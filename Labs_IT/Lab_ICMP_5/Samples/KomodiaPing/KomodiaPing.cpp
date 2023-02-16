/*
 *  Copyright (c) 2000-2003 Barak Weichselbaum <barak@komodia.com>
 *  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Contact info:
 * -------------
 *
 * Site:					http://www.komodia.com
 * Main contact:			barak@komodia.com
 * For custom projects, 
 * consulting, or other
 * paid services:			sales@komodia.com
 */

#include "stdafx.h"

#include "PingSocket.h"
#include "ScreenLog.h"

#include <conio.h>

void UsageErrorMessage(const char* pProgramName)
{
	printf("Usage:\n");
	printf("%s <host>\n",pProgramName);
}

void GeneralErrorMessage(CPingSocket* pSocket,
						 const char* pError)
{
	//Print the error
	printf("%s\n",pError);

	//Terminate al;
	if (pSocket)
		delete pSocket;

	//Close the sockets
	CSpoofBase::ShutdownSockets();
}

//Socket pointer for map
CPingSocket* gSocket=NULL;

//Proc for the message map
BOOL ShouldStop()
{
	return gSocket->IsPingDone() ||
		   kbhit();
}

int main(int argc, char* argv[])
{
	//Welcome message
	printf("KomodiaPing, Copyright 2000-2003 (c) Barak Weichselbaum! (http://www.komodia.com)\n\n");

	//First check parameters
	if (argc<2)
	{
		//Report it
		UsageErrorMessage(argv[0]);

		//Exit
		return 1;
	}

	//Our IP address
	std::string sIP;

	//Initalize data
	if (!CSpoofBase::InitializeSockets())
	{
		//Report it
		GeneralErrorMessage(NULL,"Sockets couldn't be initialized");

		//Exit
		return 2;
	}

	//Create a log
	CScreenLog aLog;
	CSpoofBase::SetLog(&aLog);

	//Our socket
	CPingSocket* pSocket;
	pSocket=new CPingSocket;

	//Save the global socket
	gSocket=pSocket;

	//Check if it's an address
	if ((*argv[1]>='a' && *argv[1]<='z') || 
		(*argv[1]>='A' && *argv[1]<='Z'))
	{
		//Try to resolve the DNS
		IP aAddr;
		aAddr=pSocket->ResolveDNS(argv[1]);

		if (aAddr)
			//Save the IP
			sIP=pSocket->LongToStdString(aAddr);
		else
		{
			//Invalid
			GeneralErrorMessage(pSocket,"Invalid host!");

			//Exit
			return 3;
		}
	}
	else
	{
		//Check address validity
		if (strlen(argv[1])>15)
		{
			//Report it
			GeneralErrorMessage(pSocket,"Invalid host!");

			//Exit
			return 3;
		}

		//Save the IP
		sIP=argv[1];
	
		//Check validity
		if (!pSocket->ValidAddress(sIP))
		{
			//Report it
			GeneralErrorMessage(pSocket,"Invalid host!");

			//Exit
			return 4;
		}
	}

	//Create and bind
	if (!pSocket->Create())
	{
		//Report it
		GeneralErrorMessage(pSocket,"Socket couldn't be created");

		//Exit
		return 5;
	}
	
	printf("Pinging:%s\nPress any key to abort\n",sIP.c_str());

	//Run the pings 4 times
	for (int iCount=0;iCount<4;++iCount)
	{
		//Ping
		if (!pSocket->Ping(sIP))
		{
			//Report it
			GeneralErrorMessage(pSocket,"Failed sending a ping!");

			//Exit
			return 6;
		}
		else
		{
			//Run a message loop
			CAsyncSocket::SimpleMessageMap(ShouldStop,
										   TRUE,
										   1);

			//Is the ping done?
			if (pSocket->IsPingDone())
				if (pSocket->IsTimeout())
					printf("Ping timeout\n");
				else
					//Can print data
					printf("Reply from %s: bytes=%i time=%ims TTL=%i\n",
						   CSpoofSocket::LongToString(pSocket->GetReplyingAddress()),
		     			   pSocket->GetDataSize(),
						   pSocket->GetTimeElapsed(),
						   pSocket->GetTTL());
			else
				break;
		}
	}

	//Shutdown
	delete pSocket;

	//Release all
	CSpoofBase::ShutdownSockets();

	//Done
	return 0;
}

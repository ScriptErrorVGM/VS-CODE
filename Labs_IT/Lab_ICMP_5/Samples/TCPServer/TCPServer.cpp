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
#include "ClientSocket.h"

#include "ScreenLog.h"

void GeneralErrorMessage(CClientSocket* pSocket,
						 const char* pError)
{
	//Report it
	printf("%s\n",pError);

	//Do we need to close/delete the socket?
	if (pSocket)
		delete pSocket;

	//Done with sockets
	CSpoofBase::ShutdownSockets();
}

int main(int argc, char* argv[])
{
	//Welcome message
	printf("TCPServer, Copyright 2000-2003 (c) Barak Weichselbaum! (http://www.komodia.com)\n\n");

	//Initalize data
	if (!CSpoofBase::InitializeSockets(TRUE,10))
	{
		//Report it
		GeneralErrorMessage(NULL,"Sockets couldn't be initialized");

		//Exit
		return 1;
	}

	//Our socket
	CClientSocket* pClient;
	pClient=new CClientSocket;

	//Create the log
	CScreenLog aLog;
	CSpoofBase::SetLog(&aLog);

	//Create and bind
	if (!pClient->Create())
	{
		//Report it
		GeneralErrorMessage(pClient,"Socket couldn't be created");

		//Exit
		return 2;
	}
	
	//Bind
	if (!pClient->Bind("127.0.0.1",1000))
	{
		//Report it
		GeneralErrorMessage(pClient,"Failed to bind to: 127.0.0.1\n");

		//Exit
		return 3;
	}

	//Try to listen
	if (!pClient->Listen(5))
	{
		//Report it
		GeneralErrorMessage(pClient,"Failed to listen\n");

		//Exit
		return 4;
	}

	printf("Telnet to 127.0.0.1 port 1000, press any key to stop\n");

	//Run the map
	CAsyncSocket::SimpleMessageMapKey(1);

	//Shutdown
	delete pClient;

	//Done with sockets
	CSpoofBase::ShutdownSockets();

	return 0;
}

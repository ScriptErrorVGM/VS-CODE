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

#include "TCPPortScannerLinear.h"
#include "TCPPortScannerMultithreaded.h"
#include "TCPPortScannerStealth.h"
#include "UDPScanner.h"

#include "ScreenLog.h"

#include <conio.h>

void UsageErrorMessage(const char* pProgramName)
{
	printf("Usage:\n");
	printf("%s <host> flags port pair (i.e. 10 20, you can specify more then one pair\ni.e 10 20 30 40)\n",pProgramName);
	printf("Flags:\n");
	printf("/s <sockets> Specify number of concurent sockets (default is 100) i.e. /s 10\n");
	printf("/m <threads> Specify scan is multithreaded (default is linear) i.e. /m 10\n");
	printf("/st <interface> Specify scan will be a stealth scan, and from which interface to send the packets (default is linear) i.e. /st 190.90.2.10 (or use GUI sample)\n");
	printf("/u <interface> Specify scan will be a UDP port scan, and from which interface to send the packets (default is linear) i.e. /u 190.90.2.10 (or use GUI sample)\n");
	printf("/r <data size> <timeout> Scan with data as well (data size in bytes, timeout in ms) not applicatable for stealth, i.e. /r 1500 1000\n");
	printf("example: %s www.komodia.com /s 10 /m 5 /r 1500 1000 1 100 130 140\n",pProgramName);
	printf("will scan my site using 10 sockets, " \
		   "5 threads (multithreaded scan), will have 1.5k for receive buffer, and 1 second timeout " \
		   "and will scan ports 1-100 and 130-140\n");
}

void GeneralErrorMessage(CTCPPortScanner* pSocket,
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
CTCPPortScanner* gSocket=NULL;

//Was it a key press
BOOL gKeyPress;

//Proc for the message map
BOOL ShouldStop()
{
	return gSocket->IsDone() ||
		   (gKeyPress=kbhit());
}

int main(int argc, char* argv[])
{
	//Welcome message
	printf("CommandTCPScanner, Copyright 2000-2003 (c) Barak Weichselbaum! (http://www.komodia.com)\n\n");

	//First check parameters
	if (argc<4)
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

	//Check if it's an address
	if ((*argv[1]>='a' && *argv[1]<='z') || 
		(*argv[1]>='A' && *argv[1]<='Z'))
	{
		//Try to resolve the DNS
		IP aAddr;
		aAddr=CSpoofSocket::ResolveDNS(argv[1]);

		if (aAddr)
			//OK
			sIP=CSpoofSocket::LongToStdString(aAddr);
		else
		{
			//Invalid
			GeneralErrorMessage(NULL,"Invalid host!");

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
			GeneralErrorMessage(NULL,"Invalid host!");

			//Exit
			return 3;
		}

		//Save it
		sIP=argv[1];
	
		//Check validity
		if (!CSpoofSocket::ValidAddress(sIP))
		{
			//Report it
			GeneralErrorMessage(NULL,"Invalid host!");

			//Exit
			return 4;
		}
	}

	//Get the number of sockets
	int iNumberOfSockets;
	iNumberOfSockets=100;

	//Enum of scan
	typedef enum _ScanType
	{
		stLinear,
		stMT,
		stStealth,
		stUDP
	} ScanType;

	//Type of scan
	ScanType aScanType;
	aScanType=stLinear;

	//Stealh/UDP bind interface
	IP aInterface;
	aInterface=0;

	//Number of threads
	int iThreads;

	//Data size and timeout
	int iDataSize;
	iDataSize=0;

	DWORD dwTimeout;
	dwTimeout=0;

	//Current position
	int iCurrentPosition;
	iCurrentPosition=2;

	BOOL bQuit;
	bQuit=FALSE;

	//Start sorting the flags
	while (!bQuit)
	{
		if (!strcmp(argv[iCurrentPosition],"/s"))
		{
			//Get the number of sockets
			if (!(iNumberOfSockets=atoi(argv[iCurrentPosition+1])))
			{
				//Report it
				GeneralErrorMessage(NULL,"Invalid number of sockets!");

				//Exit
				return 5;
			}

			//Increase our pos
			iCurrentPosition+=2;
		}
		else if (!strcmp(argv[iCurrentPosition],"/m"))
		{
			//We are multithreaded
			aScanType=stMT;

			//Get the number of threads
			if ((iThreads=atoi(argv[iCurrentPosition+1]))<=0)
			{
				//Report it
				GeneralErrorMessage(NULL,"Invalid number of threads!");

				//Exit
				return 6;
			}

			//Increase our pos
			iCurrentPosition+=2;
		}
		else if (!strcmp(argv[iCurrentPosition],"/r"))
		{
			//Get the data size
			if (!(iDataSize=atoi(argv[iCurrentPosition+1])))
			{
				//Report it
				GeneralErrorMessage(NULL,"Invalid data size!");

				//Exit
				return 7;
			}

			//Get the timeout
			if (!(dwTimeout=atoi(argv[iCurrentPosition+2])))
			{	
				//Report it
				GeneralErrorMessage(NULL,"Invalid timeout!");

				//Exit
				return 8;
			}

			//Increase our pos
			iCurrentPosition+=3;
		}
		else if (!strcmp(argv[iCurrentPosition],"/st") ||
				 !strcmp(argv[iCurrentPosition],"/u"))
		{
			//Which type?
			if (!strcmp(argv[iCurrentPosition],"/st"))
				//We are stealh
				aScanType=stStealth;
			else
				//We are UDP
				aScanType=stUDP;

			//Get the data size
			if (!(aInterface=CSpoofBase::StringToLong(argv[iCurrentPosition+1])))
			{
				//Report it
				GeneralErrorMessage(NULL,"Invalid address!");

				//Exit
				return 9;
			}

			//Increase pos count
			iCurrentPosition+=2;
		}
		//Is it a number
		else if (atoi(argv[iCurrentPosition]))
			//Quit
			bQuit=TRUE;
		else		
		{	
			//Report it
			GeneralErrorMessage(NULL,"Invalid flag!");

			//Exit
			return 10;
		}
	}

	//Our socket
	CTCPPortScanner* pSocket;

	//Which socket?
	switch (aScanType)
	{
	case stLinear:
		pSocket=new CTCPPortScannerLinear;
		break;
	case stStealth:
		pSocket=new CTCPPortScannerStealth(aInterface);
		break;
	case stMT:
		pSocket=new CTCPPortScannerMultithreaded;
		((CTCPPortScannerMultithreaded*)pSocket)->SetMaxThreads(iThreads);
		break;
	case stUDP:
		pSocket=new CUDPScanner(aInterface);
	}

	//Save the socket for the map
	gSocket=pSocket;

	//Set the number of sockets
	pSocket->SetMaxSockets(iNumberOfSockets);

	//Do we have data
	if (iDataSize &&
		dwTimeout)
		//Set it
		pSocket->SetReceiveData(iDataSize,
								dwTimeout);

	//Start putting the pairs
	int iCurrentPair;
	iCurrentPair=iCurrentPosition;

	//Print ports
	printf("Ports to scan:\n");

	while (iCurrentPair<argc)
	{
		//Can we have this pair
		if (iCurrentPair==argc)
			break;

		//Get the current number
		pSocket->AddPorts(atoi(argv[iCurrentPair]),
						  atoi(argv[iCurrentPair+1]));

		//Print them
		printf("%i-%i\n",atoi(argv[iCurrentPair]),
						 atoi(argv[iCurrentPair+1]));

		//Increase ourself
		iCurrentPair+=2;
	}

	//Initialize async handlers
	CAsyncSocket::Initialize();

	//Start the scan
	if (!pSocket->Scan(sIP))
	{
		//Report it
		GeneralErrorMessage(pSocket,"Failed scanning!");

		//Are we stealh
		if (aScanType==stStealth ||
			aScanType==stUDP)
			GeneralErrorMessage(NULL,"Check the binding parameters (or use GUI sample)!");

		//Exit
		return 12;
	}
	
	//What we are doing
	printf("\nScanning:%s\nPress any key to abort\n\n",sIP.c_str());

	//An alternative for waiting to IsDone function
	//Is to inherit from the class, and overide TCPScanDone

	//Run a message loop
	CAsyncSocket::SimpleMessageMap(ShouldStop,
								   TRUE,
								   1);

	//Was it a key press
	if (gKeyPress)
		//Stop the scan
		pSocket->StopScan();
	//Do we have an error
	else if (pSocket->IsError())
		printf("Error during scan!\n");
	else if (pSocket->IsDone())
	{
		printf("Answering ports:\n");

		//Print the result
		//Get the list
		const CTCPPortScanner::PortsList& aList=pSocket->GetPortList();

		//Iterate it
		CTCPPortScanner::PortsList::const_iterator aIterator;
		aIterator=aList.begin();

		while (aIterator!=aList.end())
		{
			//Get the port
			printf("%i\n",*aIterator);

			//Do we have data ?
			if (iDataSize &&
				dwTimeout)
				if (pSocket->GetData(*aIterator))
					//Print it
					printf("Data received:%s\n",pSocket->GetData(*aIterator));

			//Next one
			++aIterator;
		}

		//Done
		printf("Done!\n");
	}

	//Shutdown
	delete pSocket;

	//Release all
	CSpoofBase::ShutdownSockets();

	//Done
	return 0;
}

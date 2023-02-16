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

#include "ScreenLog.h"

#include "SpoofSocket.h"

#include "TCPRelayHTTP.h"
#include "UDPRelay.h"

#include <conio.h>

void UsageErrorMessage(const char* pProgramName)
{
	printf("Usage:\n");
	printf("%s <BindIP> <BindPort> <RemoteIP> <RemoteHost> <Protocol> <Timeout>\n",pProgramName);
	printf("<BindIP> - Local IP to bind to\n");
	printf("<BindPort> - Local port to bind to\n");
	printf("<RemoteIP> - Remote IP to relay data to\n");
	printf("<RemoteHost> - Remote port to relay data to\n");
	printf("<Protocol> - u for UDP, and t for TCP, h for HTTP (regular TCP relay may not work with systems that have transparent proxy\n");
	printf("<Timeout> - Timeout in MS to close inactive connections (0 is not timeout)\n");
	printf("Example: KomodiaRelay 127.0.0.1 80 64.127.67.124 80 h 0\n");
	printf("Will create a relay between localhost and my site, openning a web browser to address 127.0.0.1 will connect to my site\n");
}

int main(int argc, char* argv[])
{
	//Welcome message
	printf("KomodiaRelay, Copyright 2000-2003 (c) Barak Weichselbaum! (http://www.komodia.com)\n\n");

	//First check parameters
	if (argc<7)
	{
		//Report it
		UsageErrorMessage(argv[0]);

		//Exit
		return 1;
	}

	//Check if the addresses are valid
	if (!CSpoofSocket::ValidAddress(argv[1]))
	{
		//Report it
		printf("%s is not a valid address!\n",
			   argv[1]);

		//Exit
		return 2;
	}

	//Check the ports
	unsigned short usSourcePort;
	if (!(usSourcePort=atoi(argv[2])))
	{
		//Report it
		printf("%s is not a valid port!\n",
			   argv[2]);

		//Exit
		return 3;
	}

	//Check if the addresses are valid
	if (!CSpoofSocket::ValidAddress(argv[3]))
	{
		//Report it
		printf("%s is not a valid address!\n",
			   argv[3]);

		//Exit
		return 4;
	}

	//Check the ports
	unsigned short usDestinationPort;
	if (!(usDestinationPort=atoi(argv[4])))
	{
		//Report it
		printf("%s is not a valid port!\n",
			   argv[4]);

		//Exit
		return 5;
	}

	//Check flag
	if (argv[5][0]!='u' &&
		argv[5][0]!='t' &&
		argv[5][0]!='h')
	{
		//Report it
		printf("%s is not a protocol selector!\n",
			   argv[5]);

		//Exit
		return 6;
	}

	//Our log
	CScreenLog aScreenLog;

	//Set it
	CErrorHandler::SetLog(&aScreenLog);

	//Initialize, with no need for a message map
	if (!CSpoofBase::InitializeSocketsNoMap(TRUE,10))
	{
		//Report it
		printf("Failed to initialize sockets!\n");

		//Exit
		return 7;
	}

	//Create the appropriate relay
	CRelay* pRelay;
	if (argv[5][0]=='u')
		pRelay=new CUDPRelay;
	else if (argv[5][0]=='t')
		pRelay=new CTCPRelay;
	else
		pRelay=new CTCPRelayHTTP;

	//Set the timeout
	pRelay->SetTimeout(atol(argv[6]));

	if (!pRelay->Relay(argv[1],
					   usSourcePort,
					   argv[3],
					   usDestinationPort))
	{
		//Report it
		printf("Failed to create relay, check your bindings!\n");

		//Exit
		return 8;
	}

	//Key loop
	printf("Press any key to stop relay!\n");
	while (!kbhit())
		Sleep(100);

	//Stop the relay
	pRelay->Stop();

	//Let it close all connections
	Sleep(2000);

	//Clean up
	CSpoofBase::ShutdownSockets();
	CErrorHandler::SetLog(NULL);

	//Done
	return 0;
}

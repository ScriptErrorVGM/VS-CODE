/*
 *
 *
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
 *
 * Contact info:
 * Site: http://www.komodia.com
 * Email: barak@komodia.com
 */

#include "stdafx.h"

#include "WhoisSocket.h"
#include "ScreenLog.h"

int main(int argc, char* argv[])
{
	//Welcome message
	printf("KomodiaWhois, Copyright 2000-2003 (c) Barak Weichselbaum!  (http://www.komodia.com)\n\n");

	//Check syntex
	if (argc<2)
	{
		//Print it
		printf("Syntex: KomodiaWhois Address -i (for IP whois)\n");

		//Exit
		return 1;
	}

	//Create a log
	CScreenLog aLog;
	CSpoofBase::SetLog(&aLog);

	//Initialize sockets
	if (!CSpoofSocket::InitializeSockets(TRUE,2))
	{
		//Report it
		printf("Failed to initialize sockets!\n");

		//Exit
		return 2;
	}

	//Block is to assure clear socket delete
	{
	//Allocate it (if you want async socket, this is the place to say it)
	CWhoisSocket aSocket(FALSE);

	//Create it
	if (!aSocket.Create())
	{
		//Report it
		printf("Failed to create socket!");

		//Exit
		return 3;
	}

	//Which resolve do we want?
	if (argc>=3 &&
		(!strcmp(argv[2],
				 "-i") ||
		 !strcmp(argv[2],
				 "-I")))
	{
		if (!aSocket.WhoisIP(argv[1]))
		{
			//Report it
			printf("Failed to query IP!");

			//Exit
			return 4;
		}

		//Print it
		printf("%s\n",aSocket.GetWhoisData().c_str());
	}
	else
	{
		if (!aSocket.WhoisURL(argv[1]))
		{
			//Report it
			printf("Failed to query URL!");

			//Exit
			return 4;
		}

		//Print it
		printf("%s\n",aSocket.GetWhoisData().c_str());
		
		//Do we have an additional server
		if (!aSocket.GetAdditionalWhoisServer().empty())
		{
			//Report it
			printf("Trying to query additional server: %s\n",aSocket.GetAdditionalWhoisServer().c_str());

			//Get it as well
			if (!aSocket.Create())
			{
				//Report it
				printf("Failed to create socket!");

				//Exit
				return 5;
			}

			if (!aSocket.WhoisURL(argv[1],aSocket.GetAdditionalWhoisServer()))
			{
				//Report it
				printf("Failed to query URL!");

				//Exit
				return 6;
			}

			//Print it
			printf("\n%s\n",aSocket.GetWhoisData().c_str());
		}
	}
	}

	//Done
	CSpoofSocket::ShutdownSockets();

	//Remove the log
	CSpoofBase::SetLog(NULL);

	return 0;
}

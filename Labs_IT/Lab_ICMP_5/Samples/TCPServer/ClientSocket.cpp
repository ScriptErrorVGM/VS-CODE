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

#include "ErrorHandlerMacros.h"

#ifdef _MEMORY_DEBUG 
	#define new	   DEBUG_NEW  
	#define malloc DEBUG_MALLOC  
    static char THIS_FILE[] = __FILE__;  
#endif

#define CClientSocket_Class "CClientSocket"

CClientSocket::CClientSocket() : CTCPSocketAsync(FALSE)
{
	try
	{
		//Set our name
		SetName(CClientSocket_Class);
	}
	ERROR_HANDLER("CClientSocket")
}

CClientSocket::~CClientSocket()
{
}

BOOL CClientSocket::OnSocketAccept(int iErrorCode)
{
	try
	{
		if (iErrorCode)
			return TRUE;

		//(socket will be deleted at shutdown,
		// however this is not a good practice)
		CClientSocket* pClient=new CClientSocket;

		//Accept the socket 
		if (Accept(pClient))
		{
			char cTmp[]="Hello\n";

			//Report the connection
			printf("Connection accepted from:%s\n",pClient->LongToString(pClient->GetPeerAddress()));

			//Send to client
			pClient->Send(cTmp,strlen(cTmp));

			//Done
			return TRUE;
		}
		else
		{
			//Report it
			printf("Failed to accept socket!\n");

			//Exit
			return TRUE;
		}
	}
	ERROR_HANDLER_RETURN("OnSocketAccept",TRUE)
}

BOOL CClientSocket::OnSocketReceive(int iErrorCode)
{
	try
	{
		if (iErrorCode)
			return TRUE;

		//Receive
		char cBuffer[2000];

		int iRecv;
		iRecv=Receive(cBuffer,
					  sizeof(cBuffer));

		//Did we have an error
		if (iRecv>0)
			//And resend it
			Send(cBuffer,
				 iRecv);

		//Done
		return TRUE;
	}
	ERROR_HANDLER_RETURN("OnSocketReceive",TRUE)
}

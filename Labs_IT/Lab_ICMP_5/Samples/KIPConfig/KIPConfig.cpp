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
#include "Interfaces.h"

void GeneralErrorMessage(CInterfaces* pInter,
						 const char* pError)
{
	//Report the error
	printf("%s\n",pError);

	//Delete the socket
	if (pInter)
		delete pInter;

	//Shutdown sockets
	CSpoofBase::ShutdownSockets();
}

int main(int argc, char* argv[])
{
	//Welcome message
	printf("KIPConfig, Copyright 2000-2003 (c) Barak Weichselbaum! (http://www.komodia.com)\n\n");

	//Our interfaces
	CInterfaces* pInter;
	pInter=new CInterfaces;

	//Initalize data
	if (!CSpoofBase::InitializeSockets())
	{
		//Report it
		GeneralErrorMessage(pInter,"Sockets couldn't be initialized");

		//Exit
		return 1;
	}
	
	//Get the interfaces
	if (!pInter->GetInterfaces())
	{
		//Report it
		GeneralErrorMessage(pInter,"Failed to get interfaces!");

		//Exit
		return 2;
	}

	//Print them
	BOOL bQuit=FALSE;

	while (!bQuit)
	{
		//Print the interface
		printf("Interface: %s\n",pInter->LongToString(pInter->GetAddress()));
		printf("Mask     : %s\n",pInter->LongToString(pInter->GetMask()));

		//Check if support broadcast
		if (pInter->IsBroadcast())
			printf("Broadcast: %s\n",pInter->LongToString(pInter->GetBroadcast()));

		//Check if running
		if (pInter->IsRunning())
			printf("Interface is running.\n");

		//Check if it's a PPP
		if (pInter->IsPPP())
			printf("Interface is a PPP connection.\n");

		//Check if it's a loopback
		if (pInter->IsLoopback())
			printf("Interface is a loopback interface.\n");

		//Check if it's support multicast
		if (pInter->IsMulticast())
			printf("Interface supports multicast.\n");

		printf("\n");

		bQuit=!pInter->MoveNext();
	}

	//Dispose
	delete pInter;

	//Shutdown
	CSpoofBase::ShutdownSockets();

	return 0;
}

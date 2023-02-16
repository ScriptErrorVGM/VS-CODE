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
#include "AdvancedThread.h"

#include "GenericEvent.h"
#include "ManagedThread.h"

CAdvancedThread::CAdvancedThread()
{
}

CAdvancedThread::~CAdvancedThread()
{
}

void CAdvancedThread::Start()
{
	//Welcome screen
	printf("\nWill create a managed thread!\n\n");

	//Our thread
	CManagedThread* pThread;

	//Create the thread
	//This thread is already synchronized
	pThread=new CManagedThread(ThreadProc);

	//Start it
	pThread->Start((LPVOID)this);

	//Here the thread is guarnteed to be running
	//Let it run a bit
	Sleep(500);

	//Delete the thread
	delete pThread;
}

DWORD CAdvancedThread::ThreadProc(CGenericEvent* pEvent,
								  LPVOID lpData)
{
	//Run it until we need to exit
	while (pEvent->Wait(0))
	{
		//Print something to screen
		printf("Hello world, from thread ID: %i\n",GetCurrentThreadId());

		//Sleep a bit
		Sleep(100);
	}

	//Done
	return TRUE;
}
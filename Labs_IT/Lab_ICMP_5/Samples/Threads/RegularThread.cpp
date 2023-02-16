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
#include "RegularThread.h"

#include "GenericEvent.h"
#include "GenericThread.h"
#include "OSManager.h"

#include <stdio.h>

CRegularThread::CRegularThread()
{
	//Our event
	//We're using a class factory, because we many
	//want to port to other OS
	m_pEvent=COSManager::CreateEvent();
}

CRegularThread::~CRegularThread()
{
	//Delete the event
	delete m_pEvent;
}

DWORD CRegularThread::ThreadProc(LPVOID lpData)
{
	//Our thread
	//Get the class
	CRegularThread* pClass;
	pClass=(CRegularThread*)lpData;

	//Print something to screen
	printf("Hello world, from thread ID: %i\n",GetCurrentThreadId());

	//Signal the event
	pClass->m_pEvent->Set();

	//Done
	return TRUE;
}

void CRegularThread::Start()
{
	//Welcome screen
	printf("\nWill create a regular non synched thread!\n\n");

	//Reset the event (if already run)
	m_pEvent->Reset();

	//Our thread
	CGenericThread* pThread;

	//Create the thread
	//We're using a class factory, because we many
	//want to port to other OS
	pThread=COSManager::CreateThread(ThreadProc);

	//Start it
	pThread->Start((LPVOID)this);

	//Wait for the event, for 20 seconds
	if (m_pEvent->Wait(20000))
		//Means that timeout occured
		printf("Thread timeout!\n");
	
	//Delete the thread
	delete pThread;
}

	

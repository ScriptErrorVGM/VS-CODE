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
#include "ThreadPoolDemo.h"

#include "GenericCriticalSection.h"
#include "ThreadPool.h"
#include "OSManager.h"

#include <stdlib.h>

CThreadPoolDemo::CThreadPoolDemo()
{
	//Create the CS
	m_pCSection=COSManager::CreateCriticalSection();
}

CThreadPoolDemo::~CThreadPoolDemo()
{
	//Delete the CS
	delete m_pCSection;
}

void CThreadPoolDemo::Start()
{
	//Welcome screen
	printf("\nWill create a thread pool (with 10 threads) and run 100 jobs!\n\n");

	//Our thread pool
	CThreadPool* pPool;
	pPool=new CThreadPool(10);

	//Protect it
	std::auto_ptr<CThreadPool> pProtection(pPool);

	//Submit jobs
	for (int iCount=0;
		 iCount<100;
		 iCount++)
		pPool->SubmitJob(ThreadProc,(LPVOID)this);

	//Wait for it to finish
	while (!pPool->IsFinished())
		Sleep(100);

	//Done
}

DWORD CThreadPoolDemo::ThreadProc(LPVOID lpData)
{
	//Get our class
	CThreadPoolDemo* pClass;
	pClass=(CThreadPoolDemo*)lpData;

	//Lock the CS, with a special class to avoid loosing
	//a CS if we have a problem
	//It's like std::auto_ptr, for critical sections
	CCriticalAutoRelease aRelease(pClass->m_pCSection);

	//Print something
	printf("Hello world, from thread ID: %i\n",GetCurrentThreadId());

	//CS will auto released when proc exists, since aRelease
	//will be destructed

	//Done
	return TRUE;
}
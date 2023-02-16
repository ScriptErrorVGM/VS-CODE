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
#include "RealtimeTraceRoute.h"

#include "FormRealtimeSocket.h"
#include "GenericCriticalSection.h"
#include "OSManager.h"

#include "ErrorHandlerMacros.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define CFormRealtimeSocket_Class "CFormRealtimeSocket"

CFormRealtimeSocket::CFormRealtimeSocket(CListBox& rListBox,
										 CButton& rButton,
										 std::string sDNSServer,
										 BOOL bDNSTcp) : CRealTimeTraceRouteSocket(sDNSServer,
																				   bDNSTcp),
														 m_rListBox(rListBox),
														 m_pCSection(NULL),
														 m_rButton(rButton)
{
	try
	{
		//Set our name
		SetName(CFormRealtimeSocket_Class);

		//Create the CS
		m_pCSection=COSManager::CreateCriticalSection();
	}
	ERROR_HANDLER("CFormRealtimeSocket")
}

CFormRealtimeSocket::~CFormRealtimeSocket()
{
	try
	{
		delete m_pCSection;
	}
	ERROR_HANDLER("~CFormRealtimeSocket")
}

void CFormRealtimeSocket::TraceData(const TraceRouteData* pData,
									BOOL bResolved)
{
	try
	{
		//Create the data
		CString sData;

		//Is it the target ?
		if (pData->bTarget)
			sData="Target ";
		else
		{
			sData="Hop: ";
			
			//Convert the ID
			char aTmp[11];
			itoa(pData->ucTTL,aTmp,10);

			//Check if to add space
			if (pData->ucTTL<=9)
				sData+="0";

			//The hop
			sData+=aTmp;
		}

		//Save this data
		CString sBackup;
		sBackup=sData;

		//The address
		sData+=" Address: ";
		sData+=LongToString(pData->aReplyingAddress);

		//Are we resolved
		if (bResolved &&
			pData->bResolved)
		{
			sData+=" ";
			sData+=pData->sReverseDNS.c_str();
		}

		//Lock it
		CCriticalAutoRelease aRelease(m_pCSection,TRUE);

		//Do we need to delete
		if (bResolved)
		{
			//Find the string
			int iPos;
			iPos=m_rListBox.FindString(-1,sBackup);

			//Do we have it
			if (iPos!=LB_ERR)
				//Remove it
				m_rListBox.DeleteString(iPos);
		}

		//Do we need to recall ?
		if (bResolved && 
			pData->bFinal &&
			pData->bTarget)
		{
			sData="Hop: ";
			
			//Convert the ID
			char aTmp[11];
			itoa(pData->ucTTL,aTmp,10);

			//Check if to add space
			if (pData->ucTTL<=9)
				sData+="0";

			//The hop
			sData+=aTmp;

			//The address
			sData+=" Address: ";
			sData+=LongToString(pData->aReplyingAddress);

			if (bResolved &&
				pData->bResolved)
			{
				sData+=" ";
				sData+=pData->sReverseDNS.c_str();
			}
		}
	
		//Add it
		m_rListBox.AddString(sData);
	}
	ERROR_HANDLER("TraceData")
}

void CFormRealtimeSocket::TraceDone(BOOL bError)
{
	try
	{
		//Reenable the button
		m_rButton.EnableWindow(TRUE);
	}
	ERROR_HANDLER("TraceDone")
}
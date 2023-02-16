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
#include "KomodiaNSLookup.h"
#include "DNSClient.h"

#include "ErrorHandlerMacros.h"

#include "KomodiaNSLookupDoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define CDNSClient_Class "CDNSClient"

CDNSClient::CDNSClient(CKomodiaNSLookupDoc* pFather,
					   const std::string& rServer,
					   BOOL bTCP) : CDNSManager(rServer,
												bTCP,
												TRUE,
												TRUE),
													 m_pFather(pFather)
{
	try
	{
		//Set our name
		SetName(CDNSClient_Class);
	}
	ERROR_HANDLER("CDNSClient")
}

CDNSClient::~CDNSClient()
{
}

void CDNSClient::OnDNSError(int iErrorCode,
							LPVOID lpLocalIDData)
{
	//Error
	std::string sData;
	sData="Error resolving host!";

	//Add line terminators
	char aEndOfLine[3];
	aEndOfLine[0]=13;
	aEndOfLine[1]=10;
	aEndOfLine[2]=0;
	sData+=aEndOfLine;
	sData+=aEndOfLine;

	//Set it
	m_pFather->SetAnswer(sData);
}

void CDNSClient::OnDNSTimeout(const KomodiaDNS::CDNSQuery& rQuery,
							  LPVOID lpLocalIDData)
{
	//Error
	std::string sData;
	sData="Timeout resolving host: ";
	sData+=rQuery.GetQueryString(0);

	//Add line terminators
	char aEndOfLine[3];
	aEndOfLine[0]=13;
	aEndOfLine[1]=10;
	aEndOfLine[2]=0;
	sData+=aEndOfLine;
	sData+=aEndOfLine;

	//Set it
	m_pFather->SetAnswer(sData);
}

void CDNSClient::OnDNSReceive(KomodiaDNS::CDNSAnswers* pAnswers,
							  LPVOID lpLocalIDData)
{
	//Line terminators
	char aEndOfLine[3];
	aEndOfLine[0]=13;
	aEndOfLine[1]=10;
	aEndOfLine[2]=0;

	//Is it resolved
	if (pAnswers->IsResolved())
	{
		//Get the string
		std::string sData;
		sData=pAnswers->GetAnswerParsed(TRUE,
										TRUE,
										TRUE);
		//Set it
		m_pFather->SetAnswer(sData);
	}
	else
	{
		//Error
		std::string sData;
		sData="Failed to resolve: ";
		sData+=pAnswers->GetQuery()->GetQuery(0).sName;

		//Add line terminators
		sData+=aEndOfLine;
		sData+=aEndOfLine;

		//Set it
		m_pFather->SetAnswer(sData);
	}

	//Delete the answers
	delete pAnswers;
}
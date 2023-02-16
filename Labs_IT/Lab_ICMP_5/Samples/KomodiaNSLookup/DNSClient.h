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

#if !defined(AFX_DNSCLIENT_H__421B3942_9E46_42B0_95D2_470C29F5E486__INCLUDED_)
#define AFX_DNSCLIENT_H__421B3942_9E46_42B0_95D2_470C29F5E486__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DNSManager.h"

class CKomodiaNSLookupDoc;

class CDNSClient : public KomodiaDNS::CDNSManager
{
public:
	//Ctor and Dtor
	CDNSClient(CKomodiaNSLookupDoc* pFather,
			   const std::string& rServer,
			   BOOL bTCP);
	virtual ~CDNSClient();
protected:
	//Events for user to override
	virtual void OnDNSError(int iErrorCode,
							LPVOID lpLocalIDData);
	virtual void OnDNSTimeout(const KomodiaDNS::CDNSQuery& rQuery,
							  LPVOID lpLocalIDData);
	virtual void OnDNSReceive(KomodiaDNS::CDNSAnswers* pAnswers,
							  LPVOID lpLocalIDData);
private:
	//Our father
	CKomodiaNSLookupDoc* m_pFather;
};

#endif // !defined(AFX_DNSCLIENT_H__421B3942_9E46_42B0_95D2_470C29F5E486__INCLUDED_)

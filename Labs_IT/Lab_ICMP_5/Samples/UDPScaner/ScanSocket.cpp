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
#include "ScanSocket.h"

#include "ErrorHandlerMacros.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define CScanSocket_Class "CScanSocket"

CScanSocket::CScanSocket(const std::string& rBindAddress,
						 CListBox* pList,
						 BOOL bAutoScroll) : CUDPScanner(rBindAddress),
											 m_pListBox(pList),
											 m_bAutoScroll(bAutoScroll)
{
	try
	{
		//Set our name
		SetName(CScanSocket_Class);
	}
	ERROR_HANDLER("CScanSocket")
}

CScanSocket::~CScanSocket()
{
}

void CScanSocket::OnPort(unsigned short usPort,
						 BOOL bConnected)
{
	try
	{
		//Connected string only
		if (bConnected)
		{
			//Convert to strings
			char cTCP[10];
			ltoa(usPort,
				 cTCP,
				 10);

			//Add to the list box
			m_pListBox->AddString(cTCP);

			//Do we need to lower the display
			if (m_bAutoScroll)
				m_pListBox->SetTopIndex(m_pListBox->GetCount()-5);
		}
	}
	ERROR_HANDLER("OnPort")
}

void CScanSocket::TCPScanDone(BOOL bError)
{
	try
	{
		//Add to the list box
		m_pListBox->AddString("Scan finished");

		//Do we need to lower the display
		if (m_bAutoScroll)
			m_pListBox->SetTopIndex(m_pListBox->GetCount()-5);
	}
	ERROR_HANDLER("OnPort")
}

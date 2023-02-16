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
#include "KSniffer.h"
#include "ClientSocket.h"

//These includes are only to get the header definition
#include "TCPSocket.h"
#include "UDPSocket.h"
#include "ICMPSocket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CClientSocket::CClientSocket(CListBox* pList) : CSniffSocket(),
												m_pList(pList),
												m_bOutgoing(FALSE)
{
}

CClientSocket::~CClientSocket()
{
}

BOOL CClientSocket::Bind(const std::string& rSourceAddress,
						 unsigned short usPort)
{
	if (!CSpoofSocket::Bind(rSourceAddress,
							usPort))
		return FALSE;
	else
	{
		//Save the address
		m_sAddress=rSourceAddress;

		//Done
		return TRUE;
	}
}

BOOL CClientSocket::OnSocketReceive(int iErrorCode)
{
	char cBuffer[2000];

	//First receive the IP address
	int iReceive;
	iReceive=Receive(cBuffer,
					 sizeof(cBuffer));

	if (iReceive==SOCKET_ERROR)
		return FALSE;

	//Copy the header
	IpHeader aHeader;
	memcpy(&aHeader,
		   cBuffer,
		   IpHeaderLength);

	//Check the packet is addresses to us
	std::string sAddress;
	sAddress=CSpoofSocket::LongToStdString(aHeader.ulSourceAddress);

	//Check the data is not from us (altough someone may want to save this data)
	long lCapture;
	if ((lCapture=(sAddress==m_sAddress)) || 
		m_bOutgoing)
	{
		CString strInfo;

		if (lCapture)
		{
			strInfo="Sending packet to: ";
			strInfo+=CSpoofSocket::LongToString(aHeader.ulDestinationAddress);
		}
		else
		{
			strInfo="Received packet from: ";
			strInfo+=sAddress.c_str();
		}

		strInfo+=", Protocol:";

		CString strProtocol;
		if (aHeader.ucProtocol==IPPROTO_TCP)
			strProtocol="TCP";
		else if (aHeader.ucProtocol==IPPROTO_UDP)
			strProtocol="UDP";
		else if (aHeader.ucProtocol==IPPROTO_ICMP)
			strProtocol="ICMP";
		else
			strProtocol="Other";

		strInfo+=strProtocol;

		//Print out some data
		m_pList->AddString(strInfo);

		//Find the size of IP header (may have options)
		unsigned long ulIPHeaderSize;
		ulIPHeaderSize=(aHeader.ucHeaderLength_Version & 0x0f) << 2;

		//Read the protocol header (ignore IP options)
		unsigned long ulPos;
		ulPos=ulIPHeaderSize;

		if (aHeader.ucProtocol==IPPROTO_TCP)
			AnalyzeTCP(cBuffer+ulPos);
		else if (aHeader.ucProtocol==IPPROTO_UDP)
			AnalyzeUDP(cBuffer+ulPos);
		else if (aHeader.ucProtocol==IPPROTO_ICMP)
			AnalyzeICMP(cBuffer+ulPos);
	}

	//Read all the data
	//I'm sure however wants to use this will add his packet analyzer
	//Password sniffer here, have fun

	return TRUE;
}

void CClientSocket::AnalyzeICMP(char *cICMPBuffer)
{
	//Read the ICMP header
	ICMPHeader aHeader;
	memcpy(&aHeader,
		   cICMPBuffer,
		   ICMPHeaderLength);

	//Print out the code
	CString strICMP;

	//Convert to strings
	char cICMP[10];
	ltoa(aHeader.ucICMPType,
		 cICMP,
		 10);

	strICMP="ICMP type: ";
	strICMP+=cICMP;

	//Convert again
	ltoa(aHeader.ucICMPCode,
		 cICMP,10);

	strICMP+=", code: ";
	strICMP+=cICMP;

	//Add it
	m_pList->AddString(strICMP);
}

void CClientSocket::AnalyzeTCP(char *cTCPBuffer)
{
	//Read the ICMP header
	TCPHeader aHeader;
	memcpy(&aHeader,
		   cTCPBuffer,
		   TCPHeaderLength);

	//Print out the code
	CString strTCP;

	//Convert to strings
	char cTCP[10];
	ltoa(htons(aHeader.usSourcePort),
		 cTCP,
		 10);

	strTCP="Source port: ";
	strTCP+=cTCP;

	//Convert again
	ltoa(htons(aHeader.usDestinationPort),
		 cTCP,
		 10);

	strTCP+=", destination port: ";
	strTCP+=cTCP;

	//Add it
	m_pList->AddString(strTCP);
}

void CClientSocket::AnalyzeUDP(char *cUDPBuffer)
{
	//Read the ICMP header
	UDPHeader aHeader;
	memcpy(&aHeader,
		   cUDPBuffer,
		   UDPHeaderLength);

	//Print out the code
	CString strUDP;

	//Convert to strings
	char cUDP[10];
	ltoa(htons(aHeader.usSourcePort),
		 cUDP,
		 10);

	strUDP="Source port: ";
	strUDP+=cUDP;

	//Convert again
	ltoa(htons(aHeader.usDestinationPort),
		 cUDP,
		 10);

	strUDP+=", destination port: ";
	strUDP+=cUDP;

	//Add it
	m_pList->AddString(strUDP);
}

void CClientSocket::CaptureOutgoing(BOOL bCapture)
{
	m_bOutgoing=bCapture;
}

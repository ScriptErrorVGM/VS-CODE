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
#include "PacketCrafter.h"
#include "PacketCrafterDlg.h"

#include "Array_ptr.h"

#include "TCPCrafter.h"
#include "UDPCrafter.h"
#include "ICMPCrafter.h"

#include "UDPDialog.h"
#include "TCPDialog.h"
#include "ICMPDialog.h"

#include <memory>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPacketCrafterDlg dialog

CPacketCrafterDlg::CPacketCrafterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPacketCrafterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPacketCrafterDlg)
	m_DefaultIdentification = TRUE;
	m_DefaultSize = TRUE;
	m_FragmentationType = 0;
	m_HeaderSize = 20;
	m_Identification = 0;
	m_TTL = 255;
	m_TypeOfService = 0;
	m_SourcePort = 0;
	m_DestinationPort = 0;
	m_CheckSum = 0;
	m_DefaultChecksum = TRUE;
	m_Offset = 0;
	m_DataSize = 0;
	m_sData = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPacketCrafterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPacketCrafterDlg)
	DDX_Control(pDX, IDC_HYPERLINK, m_HyperLink);
	DDX_Control(pDX, IDC_ToAddress, m_ToAddress);
	DDX_Control(pDX, IDC_FromAddress, m_FromAddress);
	DDX_Check(pDX, IDC_DefaultIndentification, m_DefaultIdentification);
	DDX_Check(pDX, IDC_DefaultSize, m_DefaultSize);
	DDX_CBIndex(pDX, IDC_FragmentationType, m_FragmentationType);
	DDX_Text(pDX, IDC_HeaderSize, m_HeaderSize);
	DDV_MinMaxByte(pDX, m_HeaderSize, 20, 64);
	DDX_Text(pDX, IDC_Identification, m_Identification);
	DDX_Text(pDX, IDC_TTL, m_TTL);
	DDV_MinMaxByte(pDX, m_TTL, 0, 255);
	DDX_CBIndex(pDX, IDC_TypeOfService, m_TypeOfService);
	DDX_Text(pDX, IDC_SourcePort, m_SourcePort);
	DDV_MinMaxUInt(pDX, m_SourcePort, 0, 65535);
	DDX_Text(pDX, IDC_DestinationPort, m_DestinationPort);
	DDV_MinMaxUInt(pDX, m_DestinationPort, 0, 65535);
	DDX_Text(pDX, IDC_CheckSum, m_CheckSum);
	DDV_MinMaxUInt(pDX, m_CheckSum, 0, 65535);
	DDX_Check(pDX, IDC_DefaultChecksum, m_DefaultChecksum);
	DDX_Text(pDX, IDC_Offset, m_Offset);
	DDV_MinMaxUInt(pDX, m_Offset, 0, 16383);
	DDX_Text(pDX, IDC_DataSize, m_DataSize);
	DDV_MinMaxUInt(pDX, m_DataSize, 0, 64000);
	DDX_Text(pDX, IDC_DATA, m_sData);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPacketCrafterDlg, CDialog)
	//{{AFX_MSG_MAP(CPacketCrafterDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_SEND_IP, OnSendIp)
	ON_BN_CLICKED(ID_SEND_UDP, OnSendUdp)
	ON_BN_CLICKED(ID_SEND_TCP, OnSendTcp)
	ON_BN_CLICKED(ID_SEND_ICMP, OnSendICMP)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPacketCrafterDlg message handlers

BOOL CPacketCrafterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPacketCrafterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPacketCrafterDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPacketCrafterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPacketCrafterDlg::OnSendIp() 
{
	//First resync
	UpdateData(TRUE);

	//Send only if valid
	if (CheckValidIP())
	{
		//OK construct our packet
		CTCPCrafter* pCrafter;
		pCrafter=new CTCPCrafter;

		//Set the crafter parameters
		SetIPCrafter(pCrafter);

		//Send it
		SendIP(pCrafter);

		//Delete the crafter
		delete pCrafter;
	}
}

BOOL CPacketCrafterDlg::CheckValidIP()
{
	BOOL bOK;
	bOK=FALSE;

	if (!IPCtrlToSTR(&m_FromAddress))
		MessageBox("Please enter a valid source address!");
	else if (!IPCtrlToSTR(&m_ToAddress))
		MessageBox("Please enter a valid destination address!");
	else if (m_TypeOfService==-1)
		MessageBox("Please enter a valid type of service!");
	else if (m_FragmentationType==-1)
		MessageBox("Please enter a valid fragmentation size!");
	else
		bOK=TRUE;

	return bOK;
}

LPSTR CPacketCrafterDlg::IPCtrlToSTR(CIPAddressCtrl* ctrl)
{
	//Converts the control address to textual address
	//Convert bytes to string
	BYTE bOctet1;
	BYTE bOctet2;
	BYTE bOctet3;
	BYTE bOctet4;

	//Get the value and blank values
	int iBlank;
	iBlank=ctrl->GetAddress(bOctet1,bOctet2,bOctet3,bOctet4);

	if (iBlank!=4)
		//Not filled
		return NULL;
	else
	{
		in_addr iAddr;
		iAddr.S_un.S_un_b.s_b1=bOctet1;
		iAddr.S_un.S_un_b.s_b2=bOctet2;
		iAddr.S_un.S_un_b.s_b3=bOctet3;
		iAddr.S_un.S_un_b.s_b4=bOctet4;

		return inet_ntoa(iAddr);
	}
}

void CPacketCrafterDlg::SetIPCrafter(CIPCrafter *pCrafter)
{
	//Conversion from combo to fragmentation flags
	static const unsigned short ConvertFragFlag[4]={IpFragFlag_MAY_FRAG,IpFragFlag_MORE_FRAG,IpFragFlag_LAST_FRAG,IpFragFlag_DONT_FRAG};

	//Set the values
	pCrafter->SetDefault();

	//Check if we use default checksum
	pCrafter->SetUseDefaultChecksum(m_DefaultChecksum);

	//And do we need to set it
	if (!m_DefaultChecksum)
		pCrafter->SetChecksum(m_CheckSum);

	//Do we need to set the header size
	if (!m_DefaultSize)
		pCrafter->SetHeaderLength(m_HeaderSize);

	//Set the type of service
	pCrafter->SetTypeOfService(m_TypeOfService);

	//Set the fragmentation flag
	pCrafter->SetFragmentationFlags(ConvertFragFlag[m_FragmentationType] | m_Offset/8);
}

void CPacketCrafterDlg::SendIP(CSpoofSocket *pSocket)
{
	//Get the addresses
	std::string sSourceAddress;
	sSourceAddress=IPCtrlToSTR(&m_FromAddress);

	std::string sDestinationAddress;
	sDestinationAddress=IPCtrlToSTR(&m_ToAddress);

	//Set the source address
	pSocket->SetSourceAddress(sSourceAddress);

	//Create it
	if (!pSocket->Create(IPPROTO_IP))
	{
		AfxMessageBox("Failed to create raw socket with IP_HDRINCL flag!");
		return;
	}
	
	//Set the time to live
	pSocket->SetTTL(m_TTL);

	//Create a buffer to supplement the header size
	char* pBuffer;
	pBuffer=GetData();

	//Protect the buffer
	CArray_ptr<char> pProtection(pBuffer);

	int iSendSize;

	//Calculate the needed size
	if (m_DefaultSize)
		iSendSize=0;
	else
		iSendSize=m_HeaderSize-IpHeaderLength;

	//And sent a packet
	if (pSocket->Send(sDestinationAddress,
					  pBuffer,
					  iSendSize+m_DataSize,
					  m_DestinationPort)==SOCKET_ERROR)
	{
		AfxMessageBox("Failed to send data!");
		return;
	}
}

void CPacketCrafterDlg::OnSendUdp() 
{
	//First validate the data
	//First resync
	UpdateData(TRUE);

	//Send only if valid
	if (CheckValidIP())
	{
		CUDPDialog dlg(this);
	
		int nResponse = dlg.DoModal();
	}
}

void CPacketCrafterDlg::SendUDP(unsigned short usUDPChecksum,BOOL bDefaultUDPChecksum)
{
	//OK construct our packet
	CUDPCrafter* pCrafter;
	pCrafter=new CUDPCrafter;

	//Protect it
	std::auto_ptr<CUDPCrafter> pProtection(pCrafter);

	//Set the crafter parameters
	pCrafter->SetUDPChecksum(usUDPChecksum);
	pCrafter->SetUDPUseDefaultChecksum(bDefaultUDPChecksum);

	//Set the crafter parameters
	SetIPCrafter(pCrafter);

	//Get the addresses
	std::string sSourceAddress;
	sSourceAddress=IPCtrlToSTR(&m_FromAddress);

	std::string sDestinationAddress;
	sDestinationAddress=IPCtrlToSTR(&m_ToAddress);

	//Set the source address
	pCrafter->SetSourceAddress(sSourceAddress);

	//Create it
	if (!pCrafter->Create())
	{
		AfxMessageBox("Failed to create raw socket with IP_HDRINCL flag!");
		return;
	}

	//Set the time to live
	pCrafter->SetTTL(m_TTL);

	//Create a buffer to supplement the header size
	char* pBuffer;
	pBuffer=GetData();

	//Protect the buffer
	CArray_ptr<char> pProtection2(pBuffer);

	//And sent a packet
	if (pCrafter->Send(m_SourcePort,
					   sDestinationAddress,
					   m_DestinationPort,
					   pBuffer,
					   m_DataSize)==SOCKET_ERROR)
	{
		AfxMessageBox("Failed to send data!");
		return;
	}
}

void CPacketCrafterDlg::OnSendTcp() 
{
	//First validate the data
	//First resync
	UpdateData(TRUE);

	//Send only if valid
	if (CheckValidIP())
	{
		CTCPDialog dlg(this);
	
		int nResponse = dlg.DoModal();
	}
}

void CPacketCrafterDlg::SendTCP(unsigned char ucFlags,
								DWORD Acknowledge,
								DWORD Sequence,
								BYTE Offset,
								UINT Urgent,
								unsigned short usWindow,
								BOOL bDefaultChecksum,
			 					unsigned short usChecksum)
{
	//OK construct our packet
	CTCPCrafter* pCrafter;
	pCrafter=new CTCPCrafter;

	//Protect the crafter
	std::auto_ptr<CTCPCrafter> pProtection(pCrafter);

	//Set the crafter parameters
	pCrafter->SetFlags(ucFlags);
	pCrafter->SetAcknowledgeNumber(Acknowledge);
	pCrafter->SetTCPUseDefaultChecksum(bDefaultChecksum);
	pCrafter->SetTCPChecksum(usChecksum);
	pCrafter->SetSequenceNumber(Sequence);
	pCrafter->SetDataOffset(Offset);
	pCrafter->SetUrgentPointer(Urgent);
	pCrafter->SetWindow(usWindow);

	//Set the crafter parameters
	SetIPCrafter(pCrafter);

	//Get the addresses
	std::string sSourceAddress;
	sSourceAddress=IPCtrlToSTR(&m_FromAddress);

	std::string sDestinationAddress;
	sDestinationAddress=IPCtrlToSTR(&m_ToAddress);

	//Set the source address
	pCrafter->SetSourceAddress(sSourceAddress);

	//Set the time to live
	pCrafter->SetTTL(m_TTL);

	//Create it
	//Create it
	if (!pCrafter->Create())
	{
		AfxMessageBox("Failed to create raw socket with IP_HDRINCL flag!");
		return;
	}

	//Create a buffer to supplement the header size
	char* pBuffer;
	pBuffer=GetData();

	//Protect the buffer
	CArray_ptr<char> pProtection2(pBuffer);

	//And sent a packet
	if (pCrafter->SendRaw(m_SourcePort,
						  sDestinationAddress,
						  m_DestinationPort,
						  pBuffer,
						  m_DataSize,
						  0)==SOCKET_ERROR)
	{
		AfxMessageBox("Failed to send data!");
		return;
	}
}

char* CPacketCrafterDlg::GetData()
{
	//Check the string size, against the data size
	if (m_DataSize!=m_sData.GetLength())
	{
		//Ask the question
		if (AfxMessageBox("Data length is different then string data, do you want to use string length?",
						  MB_YESNO)==IDYES)
		{
			//Adjust the datasize
			m_DataSize=m_sData.GetLength();

			//Allocate and copy the data
			if (!m_DataSize)
				return NULL;
			else
			{
				//Copy the data
				char* pData;
				pData=new char[m_DataSize];
				memcpy(pData,
					   (const char*)m_sData,
					   m_DataSize);

				//And exit
				return pData;
			}
		}
		else if (m_DataSize)
		{
			//Copy the data
			char* pData;
			pData=new char[m_DataSize];
			memcpy(pData,
				   (const char*)m_sData,
				   m_DataSize);

			//Exit
			return pData;
		}
		else
			;
	}
	else if (m_DataSize)
	{
		//Copy the data
		char* pData;
		pData=new char[m_DataSize];
		memcpy(pData,
			   (const char*)m_sData,
			   m_DataSize);

		//Exit
		return pData;
	}

	//Done
	return NULL;
}

void CPacketCrafterDlg::OnSendICMP() 
{
	//First validate the data
	//First resync
	UpdateData(TRUE);

	//Send only if valid
	if (CheckValidIP())
	{
		CICMPDialog dlg(this);
	
		int nResponse = dlg.DoModal();
	}
}

// TCPDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PacketCrafter.h"
#include "TCPDialog.h"
#include "PacketCrafterDlg.h"

#include "TCPSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTCPDialog dialog


CTCPDialog::CTCPDialog(CPacketCrafterDlg* pFather)
	: CDialog(CTCPDialog::IDD, (CWnd*)pFather)
{
	//{{AFX_DATA_INIT(CTCPDialog)
	m_fAck = FALSE;
	m_fFin = FALSE;
	m_fPush = FALSE;
	m_fReset = FALSE;
	m_fSyn = FALSE;
	m_fUrg = FALSE;
	m_Acknowledge = 0;
	m_bDefaultChecksum = TRUE;
	m_Sequence = 0;
	m_Checksum = 0;
	m_Offset = 5;
	m_Urgent = 0;
	m_Window = 1500;
	//}}AFX_DATA_INIT

	//Save the father
	m_pFather=pFather;
}


void CTCPDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTCPDialog)
	DDX_Check(pDX, IDC_ACK, m_fAck);
	DDX_Check(pDX, IDC_FIN, m_fFin);
	DDX_Check(pDX, IDC_PUSH, m_fPush);
	DDX_Check(pDX, IDC_RESET, m_fReset);
	DDX_Check(pDX, IDC_SYN, m_fSyn);
	DDX_Check(pDX, IDC_URG, m_fUrg);
	DDX_Text(pDX, IDC_ACKNOWLEDGE, m_Acknowledge);
	DDX_Check(pDX, IDC_DefaultTCPChecksum, m_bDefaultChecksum);
	DDX_Text(pDX, IDC_SEQUENCE, m_Sequence);
	DDX_Text(pDX, IDC_TCPCheckSum, m_Checksum);
	DDV_MinMaxUInt(pDX, m_Checksum, 0, 65535);
	DDX_Text(pDX, IDC_TCPOFFSET, m_Offset);
	DDV_MinMaxByte(pDX, m_Offset, 0, 15);
	DDX_Text(pDX, IDC_URGENT, m_Urgent);
	DDX_Text(pDX, IDC_WINDOW, m_Window);
	DDV_MinMaxDWord(pDX, m_Window, 0, 65535);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTCPDialog, CDialog)
	//{{AFX_MSG_MAP(CTCPDialog)
	ON_BN_CLICKED(IDOK, OnSendTCP)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTCPDialog message handlers

void CTCPDialog::OnSendTCP() 
{
	//Update the data
	UpdateData(TRUE);

	//Build the flags
	unsigned char ucFlags;
	ucFlags=(m_fUrg*TCPFlag_URG+
			 m_fAck*TCPFlag_ACK+
			 m_fPush*TCPFlag_PSH+
			 m_fReset*TCPFlag_RST+
			 m_fSyn*TCPFlag_SYN+
			 m_fFin*TCPFlag_FYN);

	//Send the data
	m_pFather->SendTCP(ucFlags,
					   m_Acknowledge,
					   m_Sequence,
					   m_Offset,
					   m_Urgent,
					   m_Window,
					   m_bDefaultChecksum,
					   m_Checksum);	
}

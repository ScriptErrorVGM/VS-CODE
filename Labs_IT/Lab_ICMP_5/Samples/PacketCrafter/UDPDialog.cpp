// UDPDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PacketCrafter.h"
#include "UDPDialog.h"
#include "PacketCrafterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUDPDialog dialog


CUDPDialog::CUDPDialog(CPacketCrafterDlg* pFather)
	: CDialog(CUDPDialog::IDD, (CWnd*)pFather)
{
	//{{AFX_DATA_INIT(CUDPDialog)
	m_UDPChecksum = 0;
	m_DefaultUDPChecksum = TRUE;
	//}}AFX_DATA_INIT

	//Save the father
	m_pFather=pFather;
}


void CUDPDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUDPDialog)
	DDX_Text(pDX, IDC_CheckSum, m_UDPChecksum);
	DDV_MinMaxUInt(pDX, m_UDPChecksum, 0, 65535);
	DDX_Check(pDX, IDC_DefaultUDPChecksum, m_DefaultUDPChecksum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUDPDialog, CDialog)
	//{{AFX_MSG_MAP(CUDPDialog)
	ON_BN_CLICKED(ID_UDP, OnSendUdp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUDPDialog message handlers

void CUDPDialog::OnSendUdp() 
{	
	//Update the data
	UpdateData(TRUE);

	//Send the data
	m_pFather->SendUDP(m_UDPChecksum,m_DefaultUDPChecksum);
}

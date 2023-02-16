// ICMPDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PacketCrafter.h"
#include "ICMPDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CICMPDialog dialog


CICMPDialog::CICMPDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CICMPDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CICMPDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CICMPDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CICMPDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CICMPDialog, CDialog)
	//{{AFX_MSG_MAP(CICMPDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CICMPDialog message handlers

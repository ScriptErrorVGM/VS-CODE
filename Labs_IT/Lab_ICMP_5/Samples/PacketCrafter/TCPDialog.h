#if !defined(AFX_TCPDIALOG_H__7FCD3523_B2CC_4220_BC22_55B236D1E91D__INCLUDED_)
#define AFX_TCPDIALOG_H__7FCD3523_B2CC_4220_BC22_55B236D1E91D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TCPDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTCPDialog dialog

class CPacketCrafterDlg;
class CTCPDialog : public CDialog
{
// Construction
public:
	CTCPDialog(CPacketCrafterDlg* pFather);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTCPDialog)
	enum { IDD = IDD_TCP_DIALOG };
	BOOL	m_fAck;
	BOOL	m_fFin;
	BOOL	m_fPush;
	BOOL	m_fReset;
	BOOL	m_fSyn;
	BOOL	m_fUrg;
	DWORD	m_Acknowledge;
	BOOL	m_bDefaultChecksum;
	DWORD	m_Sequence;
	UINT	m_Checksum;
	BYTE	m_Offset;
	UINT	m_Urgent;
	DWORD	m_Window;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTCPDialog)
	afx_msg void OnSendTCP();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CPacketCrafterDlg* m_pFather;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPDIALOG_H__7FCD3523_B2CC_4220_BC22_55B236D1E91D__INCLUDED_)

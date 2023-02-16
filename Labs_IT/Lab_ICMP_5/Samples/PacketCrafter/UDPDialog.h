#if !defined(AFX_UDPDIALOG_H__BA241EF7_194E_4D4A_85EC_80298796E615__INCLUDED_)
#define AFX_UDPDIALOG_H__BA241EF7_194E_4D4A_85EC_80298796E615__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UDPDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUDPDialog dialog

class CPacketCrafterDlg;

class CUDPDialog : public CDialog
{
// Construction
public:
	CUDPDialog(CPacketCrafterDlg* pFather);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUDPDialog)
	enum { IDD = IDD_UDP_DIALOG };
	UINT	m_UDPChecksum;
	BOOL	m_DefaultUDPChecksum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDPDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUDPDialog)
	afx_msg void OnSendUdp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CPacketCrafterDlg* m_pFather;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPDIALOG_H__BA241EF7_194E_4D4A_85EC_80298796E615__INCLUDED_)

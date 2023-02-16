#if !defined(AFX_ICMPDIALOG_H__04382B79_1514_44F0_BA51_929837D4D78A__INCLUDED_)
#define AFX_ICMPDIALOG_H__04382B79_1514_44F0_BA51_929837D4D78A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICMPDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CICMPDialog dialog

class CICMPDialog : public CDialog
{
// Construction
public:
	CICMPDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CICMPDialog)
	enum { IDD = IDD_ICMP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CICMPDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CICMPDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICMPDIALOG_H__04382B79_1514_44F0_BA51_929837D4D78A__INCLUDED_)

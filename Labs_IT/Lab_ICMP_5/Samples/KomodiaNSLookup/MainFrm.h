#if !defined(AFX_MAINFRM_H__16738960_FA05_4971_800E_D97C0642BAFD__INCLUDED_)
#define AFX_MAINFRM_H__16738960_FA05_4971_800E_D97C0642BAFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMultiDocTemplate;
class CKomodiaNSLookupDoc;

#include <string>

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame(CMultiDocTemplate* pTemplate);

	//This doc has the focus
	void HasFocus(CKomodiaNSLookupDoc* pDoc);
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CReBar      m_wndReBar;
	CDialogBar      m_wndDlgBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnQuery();
	afx_msg void OnA();
	afx_msg void OnMx();
	afx_msg void OnChangeDnsphrase();
	afx_msg void OnFieldchangedDns(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSoa();
	afx_msg void OnWeb();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//Out buttons
	typedef enum _TypeButtons
	{
		tbNone,
		tbA,
		tbMX,
		tbSOA
	} TypeButtons;
private:
	//To show the URL
	LONG GetRegKey(HKEY key, LPCTSTR subkey, LPTSTR retdata);

	//Open a web site
	HINSTANCE GotoURL(LPCTSTR url, int showcmd);

	//Check if every thing is valid
	BOOL CheckValid();

	//Create a new window
	void NewWindow(TypeButtons aType,
				   const std::string& rDNSServer,
				   const std::string& rHost,
				   BOOL bExisting);

	//Convert a control to address
	std::string IPCtrlToSTR(CIPAddressCtrl* pControl);

	//Which button is selected
	TypeButtons m_aSelectedButton;

	//Our doc template
	CMultiDocTemplate* m_pTemplate;

	//The focused document
	CKomodiaNSLookupDoc* m_pFocusDoc;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__16738960_FA05_4971_800E_D97C0642BAFD__INCLUDED_)

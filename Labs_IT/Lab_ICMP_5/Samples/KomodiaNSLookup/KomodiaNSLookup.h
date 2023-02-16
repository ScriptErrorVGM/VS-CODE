// KomodiaNSLookup.h : main header file for the KOMODIANSLOOKUP application
//

#if !defined(AFX_KOMODIANSLOOKUP_H__BFFDFB07_50D3_47EF_A0A5_E369296618B2__INCLUDED_)
#define AFX_KOMODIANSLOOKUP_H__BFFDFB07_50D3_47EF_A0A5_E369296618B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupApp:
// See KomodiaNSLookup.cpp for the implementation of this class
//

class CKomodiaNSLookupApp : public CWinApp
{
public:
	CKomodiaNSLookupApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKomodiaNSLookupApp)
	public:
	virtual BOOL InitInstance();
	virtual void OnFinalRelease();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CKomodiaNSLookupApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KOMODIANSLOOKUP_H__BFFDFB07_50D3_47EF_A0A5_E369296618B2__INCLUDED_)

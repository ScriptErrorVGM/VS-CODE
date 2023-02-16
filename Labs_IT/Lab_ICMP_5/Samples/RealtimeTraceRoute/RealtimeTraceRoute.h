// RealtimeTraceRoute.h : main header file for the REALTIMETRACEROUTE application
//

#if !defined(AFX_REALTIMETRACEROUTE_H__105785B1_73C7_46F3_9070_652D5EA327C4__INCLUDED_)
#define AFX_REALTIMETRACEROUTE_H__105785B1_73C7_46F3_9070_652D5EA327C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRealtimeTraceRouteApp:
// See RealtimeTraceRoute.cpp for the implementation of this class
//

class CRealtimeTraceRouteApp : public CWinApp
{
public:
	CRealtimeTraceRouteApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRealtimeTraceRouteApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRealtimeTraceRouteApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REALTIMETRACEROUTE_H__105785B1_73C7_46F3_9070_652D5EA327C4__INCLUDED_)

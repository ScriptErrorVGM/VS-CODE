#include "stdafx.h"
#include "RealtimeTraceRoute.h"
#include "RealtimeTraceRouteDlg.h"

#include "TraceLog.h"

#include "SpoofSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRealtimeTraceRouteApp

BEGIN_MESSAGE_MAP(CRealtimeTraceRouteApp, CWinApp)
	//{{AFX_MSG_MAP(CRealtimeTraceRouteApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRealtimeTraceRouteApp construction

CRealtimeTraceRouteApp::CRealtimeTraceRouteApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CRealtimeTraceRouteApp object

CRealtimeTraceRouteApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CRealtimeTraceRouteApp initialization

BOOL CRealtimeTraceRouteApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	//Create the log
	CTraceLog aLog;

	//Set it
	CErrorHandler::SetLog(&aLog);

	//Initialize the sockets
	if (!CSpoofSocket::InitializeSockets(TRUE,5))
	{
		//Error
		AfxMessageBox("Failed to initialize sockets!");

		//Exit
		return FALSE;
	}
	else
	{
		CRealtimeTraceRouteDlg dlg;
		m_pMainWnd = &dlg;
		int nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with OK
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with Cancel
		}
	}

	//Shutdown the sockets
	CSpoofSocket::ShutdownSockets();

	//Set it
	CErrorHandler::SetLog(NULL);

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

// PacketCrafter.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "PacketCrafter.h"
#include "PacketCrafterDlg.h"

#include "SpoofBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPacketCrafterApp

BEGIN_MESSAGE_MAP(CPacketCrafterApp, CWinApp)
	//{{AFX_MSG_MAP(CPacketCrafterApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPacketCrafterApp construction

CPacketCrafterApp::CPacketCrafterApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPacketCrafterApp object

CPacketCrafterApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPacketCrafterApp initialization

BOOL CPacketCrafterApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	//Initialize the sockets
	if (!CSpoofBase::InitializeSockets())
	{
		//Report it
		AfxMessageBox("Failed to initialize sockets!");

		//Exit
		return FALSE;
	}

	CPacketCrafterDlg dlg;
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

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.

	//Terminate the sockets
	CSpoofBase::ShutdownSockets();

	return FALSE;
}

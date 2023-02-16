// KomodiaNSLookup.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "KomodiaNSLookup.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "KomodiaNSLookupDoc.h"
#include "KomodiaNSLookupView.h"

#include "SpoofSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupApp

BEGIN_MESSAGE_MAP(CKomodiaNSLookupApp, CWinApp)
	//{{AFX_MSG_MAP(CKomodiaNSLookupApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupApp construction

CKomodiaNSLookupApp::CKomodiaNSLookupApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CKomodiaNSLookupApp object

CKomodiaNSLookupApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupApp initialization

BOOL CKomodiaNSLookupApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	//Try to initialize sockets
	if (!CSpoofSocket::InitializeSockets(TRUE,
										 5))
	{
		AfxMessageBox("Failed to initialize sockets!");
		return FALSE;
	}

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register document templates

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_KOMODITYPE,
		RUNTIME_CLASS(CKomodiaNSLookupDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CKomodiaNSLookupView));
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame(pDocTemplate);
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	/*if (!ProcessShellCommand(cmdInfo))
		return FALSE;*/
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CKomodiaNSLookupApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupApp message handlers


void CKomodiaNSLookupApp::OnFinalRelease() 
{	
	CWinApp::OnFinalRelease();
}

int CKomodiaNSLookupApp::ExitInstance() 
{
	//Uninitialize sockets
	CSpoofSocket::ShutdownSockets();
	
	return CWinApp::ExitInstance();
}

// RealtimeTraceRouteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RealtimeTraceRoute.h"
#include "RealtimeTraceRouteDlg.h"

#include "FormRealtimeSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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

/////////////////////////////////////////////////////////////////////////////
// CRealtimeTraceRouteDlg dialog

CRealtimeTraceRouteDlg::CRealtimeTraceRouteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRealtimeTraceRouteDlg::IDD, pParent),
	  m_pSocket(NULL)
{
	//{{AFX_DATA_INIT(CRealtimeTraceRouteDlg)
	m_sURL = _T("");
	m_dwTimeout = 5000;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CRealtimeTraceRouteDlg::~CRealtimeTraceRouteDlg()
{
	delete m_pSocket;
}

void CRealtimeTraceRouteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRealtimeTraceRouteDlg)
	DDX_Control(pDX, IDC_URL, m_aURL);
	DDX_Control(pDX, IDOK, m_aTraceButton);
	DDX_Control(pDX, IDC_IPADDRESS, m_aTraceAddress);
	DDX_Control(pDX, IDC_DNSSERVER, m_aDNSServer);
	DDX_Control(pDX, IDC_TRACELIST, m_aListBox);
	DDX_Text(pDX, IDC_TRACEADDRESS, m_sURL);
	DDX_Text(pDX, IDC_TIMEOUT, m_dwTimeout);
	DDV_MinMaxDWord(pDX, m_dwTimeout, 3000, 60000);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRealtimeTraceRouteDlg, CDialog)
	//{{AFX_MSG_MAP(CRealtimeTraceRouteDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRealtimeTraceRouteDlg message handlers

BOOL CRealtimeTraceRouteDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRealtimeTraceRouteDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRealtimeTraceRouteDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRealtimeTraceRouteDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRealtimeTraceRouteDlg::OnOK() 
{
	//Update the data
	UpdateData(TRUE);

	//Validte it
	if (!ConvertAddress())
		return;

	//Get the DNS server
	std::string sDNS;
	sDNS=IPCtrlToSTR(&m_aDNSServer);

	//Is it valid
	if (!sDNS.length())
	{
		//Show the message
		MessageBox("Please enter a DNS server!","Error",MB_OK);
	
		//Exit
		return;
	}

	//Delete the socket
	delete m_pSocket;
	m_pSocket=NULL;

	//Set the server
	m_sDNSServer=sDNS;
	
	//Do we have a socket
	if (!m_pSocket)
	{
		//Create the socket
		m_pSocket=new CFormRealtimeSocket(m_aListBox,
										  m_aTraceButton,
										  m_sDNSServer,
										  TRUE);
		if (!m_pSocket->Create())
		{
			//Show the message
			MessageBox("Failed to create socket!","Error",MB_OK);
		
			//Exit
			return;
		}
	}

	//Get the IP
	std::string sIP;
	sIP=IPCtrlToSTR(&m_aTraceAddress);

	//Clear the list
	m_aListBox.ResetContent();

	//Disable the button
	m_aTraceButton.EnableWindow(FALSE);

	//Do it
	if (!m_pSocket->TraceRoute(sIP.c_str(),m_dwTimeout))
		//Show the message
		MessageBox("Failed to trace address!","Error",MB_OK);
}

BOOL CRealtimeTraceRouteDlg::ConvertAddress()
{
	if (m_sURL=="" &&
		!IPCtrlToSTR(&m_aTraceAddress).length())
	{
		MessageBox("Please enter address to trace!","Error",MB_OK);
		return FALSE;
	}
	else if (IPCtrlToSTR(&m_aTraceAddress).length() &&
			 m_sURL=="")
		return TRUE;

	long lAddr;

	lAddr=CSpoofSocket::ResolveDNS(std::string((LPCSTR)m_sURL));

	if (lAddr)
	{
		//Correct
		m_aTraceAddress.SetAddress(htonl(lAddr));

		//Clear the address
		m_sURL="";

		//Update the data
		UpdateData(FALSE);
	}
	else
		//Display error
		MessageBox("Couldn't resolve host name","Error",MB_OK);

	return TRUE;
}

std::string CRealtimeTraceRouteDlg::IPCtrlToSTR(CIPAddressCtrl* ctrl)
{
	//Converts the control address to textual address
	//Convert bytes to string
	BYTE bOctet1;
	BYTE bOctet2;
	BYTE bOctet3;
	BYTE bOctet4;

	//Get the value and blank values
	int iBlank;
	iBlank=ctrl->GetAddress(bOctet1,bOctet2,bOctet3,bOctet4);

	if (iBlank!=4)
		//Not filled
		return "";
	else
	{
		in_addr iAddr;
		iAddr.S_un.S_un_b.s_b1=bOctet1;
		iAddr.S_un.S_un_b.s_b2=bOctet2;
		iAddr.S_un.S_un_b.s_b3=bOctet3;
		iAddr.S_un.S_un_b.s_b4=bOctet4;

		return inet_ntoa(iAddr);
	}
}

// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "KomodiaNSLookup.h"

#include "MainFrm.h"
#include "KomodiaNSLookupDoc.h"

#include "SpoofBase.h"

#include "DNSQuery.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_QUERY, OnQuery)
	ON_BN_CLICKED(IDC_A, OnA)
	ON_BN_CLICKED(IDC_MX, OnMx)
	ON_EN_CHANGE(IDC_DNSPHRASE, OnChangeDnsphrase)
	ON_NOTIFY(IPN_FIELDCHANGED, IDC_DNS, OnFieldchangedDns)
	ON_BN_CLICKED(IDC_SOA, OnSoa)
	ON_BN_CLICKED(IDC_WEB, OnWeb)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame(CMultiDocTemplate* pTemplate) : m_aSelectedButton(tbNone),
													   m_pTemplate(pTemplate),
													   m_pFocusDoc(NULL)
{
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	/*if (!m_wndToolBar.CreateEx(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}*/
	if (!m_wndDlgBar.Create(this, IDR_MAINFRAME, 
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("Failed to create dialogbar\n");
		return -1;		// fail to create
	}

	if (!m_wndReBar.Create(this) ||
		/*!m_wndReBar.AddBar(&m_wndToolBar) ||*/
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("Failed to create rebar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	/*m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);*/

	//CheckValid();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnQuery() 
{
	//Is it OK
	if (!CheckValid())
	{
		//Report it
		AfxMessageBox("Please enter all data!");

		//Exit
		return;
	}

	//Get the control
	CIPAddressCtrl* pIP;
	pIP=(CIPAddressCtrl*)m_wndDlgBar.GetDlgItem(IDC_DNS);

	//Convert it
	std::string sIP;
	sIP=IPCtrlToSTR(pIP);

	//Get the host
	CEdit* pEdit;
	pEdit=(CEdit*)m_wndDlgBar.GetDlgItem(IDC_DNSPHRASE);

	//Take the text
	char aTmp[100];
	pEdit->GetLine(0,
				   aTmp,
				   sizeof(aTmp));

	//Is it a new window
	CButton* pNew;
	pNew=(CButton*)m_wndDlgBar.GetDlgItem(IDC_NEW);

	//Make a new window
	NewWindow(m_aSelectedButton,
			  sIP,
			  aTmp,
			  pNew->GetCheck()==BST_CHECKED);
}

void CMainFrame::OnA() 
{
	//Set status
	m_aSelectedButton=tbA;
}

void CMainFrame::OnMx() 
{
	//Set status
	m_aSelectedButton=tbMX;
}

void CMainFrame::OnChangeDnsphrase() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CMDIFrameWnd::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CMainFrame::OnFieldchangedDns(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

BOOL CMainFrame::CheckValid()
{
	//Get the box
	CButton* pReverse;
	pReverse=(CButton*)m_wndDlgBar.GetDlgItem(IDC_REVERSE);

	//Check status
	if (m_aSelectedButton==tbNone &&
		pReverse->GetCheck()!=BST_CHECKED)
		//Enable it
		return FALSE;

	//Get the control
	CIPAddressCtrl* pIP;
	pIP=(CIPAddressCtrl*)m_wndDlgBar.GetDlgItem(IDC_DNS);

	//Check IP
	if (IPCtrlToSTR(pIP).empty())
		return FALSE;

	//Get the host
	CEdit* pEdit;
	pEdit=(CEdit*)m_wndDlgBar.GetDlgItem(IDC_DNSPHRASE);

	//Take the text
	char aTmp[100];
	pEdit->GetLine(0,
				   aTmp,
				   sizeof(aTmp));

	//Is it empty
	if (strlen(aTmp)<5)
		return FALSE;

	//Done
	return TRUE;
}

void CMainFrame::NewWindow(TypeButtons aType,
						   const std::string& rDNSServer,
						   const std::string& rHost,
						   BOOL bExisting)
{
	//Our frame
	CKomodiaNSLookupDoc* pDocument;

	//Do we create?
	if (!bExisting)
	{
		//Create
		pDocument=(CKomodiaNSLookupDoc*)m_pTemplate->OpenDocumentFile(NULL);

		//Set the father
		pDocument->SetFather(this);

		//Set it as the focus
		HasFocus(pDocument);

		//Add the DNS
		std::string sTitle;
		sTitle+="DNS server: ";
		sTitle+=rDNSServer;

		//Set it's name
		pDocument->SetTitle(sTitle.c_str());

		//Get the TCP flag
		//Get the box
		CButton* pTCP;
		pTCP=(CButton*)m_wndDlgBar.GetDlgItem(IDC_TCP);

		//Create the socket
		if (!pDocument->CreateSocket(rDNSServer,
									 pTCP->GetCheck()==BST_CHECKED))
		{
			//Report it
			AfxMessageBox("Failed to create socket!");

			//Remove focus
			HasFocus(NULL);

			//Close it
			delete pDocument;
		}
	}
	else
		pDocument=m_pFocusDoc;

	//Type
	KomodiaDNS::CDNSQuery::DNSQueryTypes aDNSType;

	//Build the title
	std::string sTitle;
	switch (aType)
	{
	case tbA:
		aDNSType=KomodiaDNS::CDNSQuery::A;
		break;
	case tbMX:
		aDNSType=KomodiaDNS::CDNSQuery::MX;
		break;
	case tbSOA:
		aDNSType=KomodiaDNS::CDNSQuery::SOA;
		break;
	}

	//Is it reverse?
	//Get the box
	CButton* pReverse;
	pReverse=(CButton*)m_wndDlgBar.GetDlgItem(IDC_REVERSE);

	//Query it
	if ((pReverse->GetCheck()!=BST_CHECKED &&
		 !pDocument->QueryData(rHost,
							   aDNSType)) ||
		(pReverse->GetCheck()==BST_CHECKED &&
		 !pDocument->ReverseDNS(rHost)))
		AfxMessageBox("Failed to query data!");
}

std::string CMainFrame::IPCtrlToSTR(CIPAddressCtrl* pControl)
{
	//Converts the control address to textual address
	//Convert bytes to string
	BYTE bOctet1;
	BYTE bOctet2;
	BYTE bOctet3;
	BYTE bOctet4;

	//Get the value and blank values
	int iBlank;
	iBlank=pControl->GetAddress(bOctet1,
								bOctet2,
								bOctet3,
								bOctet4);

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

		return CSpoofBase::LongToStdString(iAddr.S_un.S_addr);
	}
}

void CMainFrame::OnSoa() 
{
	//Set status
	m_aSelectedButton=tbSOA;

	//Check if valid
	CheckValid();
}

void CMainFrame::HasFocus(CKomodiaNSLookupDoc* pDoc)
{
	//Set new windows status
	CButton* pNew;
	pNew=(CButton*)m_wndDlgBar.GetDlgItem(IDC_NEW);

	//Set it
	pNew->EnableWindow(pDoc!=NULL);

	//Save the doc
	m_pFocusDoc=pDoc;
}

LONG CMainFrame::GetRegKey(HKEY key, LPCTSTR subkey, LPTSTR retdata)
{
    HKEY hkey;
    LONG retval = RegOpenKeyEx(key, subkey, 0, KEY_QUERY_VALUE, &hkey);

    if (retval == ERROR_SUCCESS) {
        long datasize = MAX_PATH;
		TCHAR data[MAX_PATH];
		RegQueryValue(hkey, NULL, data, &datasize);
		lstrcpy(retdata,data);
		RegCloseKey(hkey);
    }

    return retval;
}

HINSTANCE CMainFrame::GotoURL(LPCTSTR url, int showcmd)
{
    TCHAR key[MAX_PATH + MAX_PATH];	

    // First try ShellExecute()
    HINSTANCE result = ShellExecute(NULL, _T("open"), url, NULL,NULL, showcmd);

    // If it failed, get the .htm regkey and lookup the program
    if ((UINT)result <= HINSTANCE_ERROR) {		
		
        if (GetRegKey(HKEY_CLASSES_ROOT, _T(".htm"), key) == ERROR_SUCCESS) {
            lstrcat(key, _T("\\shell\\open\\command"));

            if (GetRegKey(HKEY_CLASSES_ROOT,key,key) == ERROR_SUCCESS) {
                TCHAR *pos;
                pos = _tcsstr(key, _T("\"%1\""));
                if (pos == NULL) {                     // No quotes found
                    pos = strstr(key, _T("%1"));       // Check for %1, without quotes
                    if (pos == NULL)                   // No parameter at all...
                        pos = key+lstrlen(key)-1;
                    else
                        *pos = '\0';                   // Remove the parameter
                }
                else
                    *pos = '\0';                       // Remove the parameter

                lstrcat(pos, _T(" "));
                lstrcat(pos, url);
                result = (HINSTANCE) WinExec(key,showcmd);
            }
        }
	}
	  
    return result;
}

void CMainFrame::OnWeb() 
{
	GotoURL("http://www.komodia.com",SW_SHOW);
}

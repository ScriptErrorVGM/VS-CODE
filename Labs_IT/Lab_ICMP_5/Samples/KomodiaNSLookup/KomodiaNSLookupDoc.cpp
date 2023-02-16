// KomodiaNSLookupDoc.cpp : implementation of the CKomodiaNSLookupDoc class
//

#include "stdafx.h"
#include "KomodiaNSLookup.h"

#include "KomodiaNSLookupDoc.h"
#include "KomodiaNSLookupView.h"
#include "MainFrm.h"

#include "DNSClient.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupDoc

IMPLEMENT_DYNCREATE(CKomodiaNSLookupDoc, CDocument)

BEGIN_MESSAGE_MAP(CKomodiaNSLookupDoc, CDocument)
	//{{AFX_MSG_MAP(CKomodiaNSLookupDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupDoc construction/destruction

CKomodiaNSLookupDoc::CKomodiaNSLookupDoc() : m_pSocket(NULL),
											 m_pFather(NULL)
{
}

CKomodiaNSLookupDoc::~CKomodiaNSLookupDoc()
{
	delete m_pSocket;
}

BOOL CKomodiaNSLookupDoc::CreateSocket(const std::string& rServer,
									   BOOL bTCP)
{
	//Create the socket
	m_pSocket=new CDNSClient(this,
							 rServer,
							 bTCP);

	//Try to initialize
	if (!m_pSocket->Initialize())
	{
		//Delete it
		delete m_pSocket;
		m_pSocket=NULL;

		//Done
		return FALSE;
	}
	else
	{
		//Set the timeout
		m_pSocket->SetDNSTimeout(10000);

		//Done
		return TRUE;
	}
}

BOOL CKomodiaNSLookupDoc::QueryData(const std::string& rHost,
									KomodiaDNS::CDNSQuery::DNSQueryTypes aType)
{
	//Make the query
	KomodiaDNS::CDNSQuery aQuery;
	aQuery.AddQuery(rHost,
					aType);

	//Send it
	return m_pSocket->QueryDNS(aQuery)!=0;
}

BOOL CKomodiaNSLookupDoc::ReverseDNS(const std::string& rIP)
{
	return m_pSocket->GetDNSEntry(rIP)!=0;
}

void CKomodiaNSLookupDoc::SetAnswer(const std::string& rAnswer)
{
	//Set the data
	POSITION aPos;
	aPos=GetFirstViewPosition();

	//Iteate
	while (aPos!=NULL)
	{
		//Get the view
		CKomodiaNSLookupView* pView;
		pView=(CKomodiaNSLookupView*)GetNextView(aPos);

		//Set the data
		pView->GetEditCtrl().ReplaceSel(rAnswer.c_str());
	}   
}

BOOL CKomodiaNSLookupDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupDoc serialization

void CKomodiaNSLookupDoc::Serialize(CArchive& ar)
{
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupDoc diagnostics

#ifdef _DEBUG
void CKomodiaNSLookupDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKomodiaNSLookupDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupDoc commands

BOOL CKomodiaNSLookupDoc::SaveModified() 
{
	return TRUE;
}

void CKomodiaNSLookupDoc::SetFather(CMainFrame* pFather)
{
	m_pFather=pFather;
}

void CKomodiaNSLookupDoc::HasFocus()
{
	if (m_pFather)
		m_pFather->HasFocus(this);
}

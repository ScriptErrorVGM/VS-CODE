// KomodiaNSLookupView.cpp : implementation of the CKomodiaNSLookupView class
//

#include "stdafx.h"
#include "KomodiaNSLookup.h"

#include "KomodiaNSLookupDoc.h"
#include "KomodiaNSLookupView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupView

IMPLEMENT_DYNCREATE(CKomodiaNSLookupView, CEditView)

BEGIN_MESSAGE_MAP(CKomodiaNSLookupView, CEditView)
	//{{AFX_MSG_MAP(CKomodiaNSLookupView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupView construction/destruction

CKomodiaNSLookupView::CKomodiaNSLookupView()
{
}

CKomodiaNSLookupView::~CKomodiaNSLookupView()
{
}

BOOL CKomodiaNSLookupView::PreCreateWindow(CREATESTRUCT& cs)
{
	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupView drawing

void CKomodiaNSLookupView::OnDraw(CDC* pDC)
{
	CKomodiaNSLookupDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupView diagnostics

#ifdef _DEBUG
void CKomodiaNSLookupView::AssertValid() const
{
	CEditView::AssertValid();
}

void CKomodiaNSLookupView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CKomodiaNSLookupDoc* CKomodiaNSLookupView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKomodiaNSLookupDoc)));
	return (CKomodiaNSLookupDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKomodiaNSLookupView message handlers

void CKomodiaNSLookupView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	//Do we have the view
	if (bActivate)
		GetDocument()->HasFocus();
	
	//Delegate
	CEditView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

BOOL CKomodiaNSLookupView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	BOOL bResult;
	if (bResult=(CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext)))
		//Set the edit
		GetEditCtrl().SetReadOnly(TRUE);

	//Done
	return bResult;
}

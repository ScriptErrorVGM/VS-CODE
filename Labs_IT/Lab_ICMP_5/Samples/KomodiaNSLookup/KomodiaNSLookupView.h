// KomodiaNSLookupView.h : interface of the CKomodiaNSLookupView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KOMODIANSLOOKUPVIEW_H__6F804C25_12BB_449F_AE9A_EE3A00D0A7D4__INCLUDED_)
#define AFX_KOMODIANSLOOKUPVIEW_H__6F804C25_12BB_449F_AE9A_EE3A00D0A7D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKomodiaNSLookupView : public CEditView
{
protected: // create from serialization only
	CKomodiaNSLookupView();
	DECLARE_DYNCREATE(CKomodiaNSLookupView)

// Attributes
public:
	CKomodiaNSLookupDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKomodiaNSLookupView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKomodiaNSLookupView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKomodiaNSLookupView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in KomodiaNSLookupView.cpp
inline CKomodiaNSLookupDoc* CKomodiaNSLookupView::GetDocument()
   { return (CKomodiaNSLookupDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KOMODIANSLOOKUPVIEW_H__6F804C25_12BB_449F_AE9A_EE3A00D0A7D4__INCLUDED_)

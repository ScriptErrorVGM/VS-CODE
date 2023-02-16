#if !defined(AFX_KOMODIANSLOOKUPDOC_H__696CA30C_B85D_4C41_B72B_A10D4266F689__INCLUDED_)
#define AFX_KOMODIANSLOOKUPDOC_H__696CA30C_B85D_4C41_B72B_A10D4266F689__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DNSQuery.h"

#include <string>

class CDNSClient;
class CMainFrame;

class CKomodiaNSLookupDoc : public CDocument
{
protected: // create from serialization only
	CKomodiaNSLookupDoc();
	DECLARE_DYNCREATE(CKomodiaNSLookupDoc)

// Attributes
public:
	//We have focus
	void HasFocus();

	//Set our father
	void SetFather(CMainFrame* pFather);

	//Create the socket
	BOOL CreateSocket(const std::string& rServer,
					  BOOL bTCP);

	//Query the data
	BOOL QueryData(const std::string& rHost,
				   KomodiaDNS::CDNSQuery::DNSQueryTypes aType);

	//Reverse DNS
	BOOL ReverseDNS(const std::string& rIP);

	//Set the answer
	void SetAnswer(const std::string& rAnswer);
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKomodiaNSLookupDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	protected:
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKomodiaNSLookupDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKomodiaNSLookupDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//Our socket
	CDNSClient* m_pSocket;

	//Our father
	CMainFrame* m_pFather;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KOMODIANSLOOKUPDOC_H__696CA30C_B85D_4C41_B72B_A10D4266F689__INCLUDED_)

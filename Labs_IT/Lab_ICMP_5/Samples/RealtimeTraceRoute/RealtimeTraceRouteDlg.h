#if !defined(AFX_REALTIMETRACEROUTEDLG_H__ECEEA932_E996_4246_82AA_1B2439FECC6E__INCLUDED_)
#define AFX_REALTIMETRACEROUTEDLG_H__ECEEA932_E996_4246_82AA_1B2439FECC6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

class CFormRealtimeSocket;

#include "..\HyperLink\HyperLink.h"

class CRealtimeTraceRouteDlg : public CDialog
{
// Construction
public:
	CRealtimeTraceRouteDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CRealtimeTraceRouteDlg();

// Dialog Data
	//{{AFX_DATA(CRealtimeTraceRouteDlg)
	enum { IDD = IDD_REALTIMETRACEROUTE_DIALOG };
	CHyperLink	m_aURL;
	CButton	m_aTraceButton;
	CIPAddressCtrl	m_aTraceAddress;
	CIPAddressCtrl	m_aDNSServer;
	CListBox	m_aListBox;
	CString	m_sURL;
	DWORD	m_dwTimeout;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRealtimeTraceRouteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRealtimeTraceRouteDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//Convert the control
	std::string IPCtrlToSTR(CIPAddressCtrl* ctrl);

	//Convert the address
	BOOL ConvertAddress();

	//Our socket
	CFormRealtimeSocket* m_pSocket;

	//Last DNS server
	std::string m_sDNSServer;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REALTIMETRACEROUTEDLG_H__ECEEA932_E996_4246_82AA_1B2439FECC6E__INCLUDED_)

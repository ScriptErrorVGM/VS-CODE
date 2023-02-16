#if !defined(AFX_UDPSCANERDLG_H__E6A75D2B_6365_4C5A_B89C_E769D758A468__INCLUDED_)
#define AFX_UDPSCANERDLG_H__E6A75D2B_6365_4C5A_B89C_E769D758A468__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CScanSocket;

#define ICMP_EVENT 100

#include "..\HyperLink\HyperLink.h"

#include <string>

class CUDPScanerDlg : public CDialog
{
public:
	CUDPScanerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUDPScanerDlg)
	enum { IDD = IDD_UDPSCANER_DIALOG };
	CListBox	m_InterfaceList;
	CHyperLink	m_HyperLink;
	CListBox	m_UDPList;
	CIPAddressCtrl	m_DestinationIP;
	int		m_EndPort;
	int		m_StartPort;
	BOOL	m_AutoScroll;
	CString	m_URL;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDPScanerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUDPScanerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnQuit();
	afx_msg void OnScan();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//Create the socket
	BOOL CreateSocket(const std::string& rBindAddress);

	//Build the interface list
	BOOL BuildInterfaceList();

	//Can we convert the address?
	BOOL ConvertAddress();

	//Do the scan
	BOOL Scan();

	//Convert the address
	std::string IPCtrlToSTR(CIPAddressCtrl* pControl);

	//Our socket
	CScanSocket* m_pSocket;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPSCANERDLG_H__E6A75D2B_6365_4C5A_B89C_E769D758A468__INCLUDED_)

// PacketCrafterDlg.h : header file
//

#if !defined(AFX_PACKETCRAFTERDLG_H__47A7F9A8_6D06_4F48_9A78_ECBF61D153DA__INCLUDED_)
#define AFX_PACKETCRAFTERDLG_H__47A7F9A8_6D06_4F48_9A78_ECBF61D153DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPacketCrafterDlg dialog

#include "..\HyperLink\HyperLink.h"

class CIPCrafter;
class CSpoofSocket;

class CPacketCrafterDlg : public CDialog
{
// Construction
public:
	//Send a crafted TCP packet
	void SendTCP(unsigned char ucFlags,
				 DWORD Acknowledge,
				 DWORD Sequence,
				 BYTE Offset,
				 UINT Urgent,
				 unsigned short usWindow,
				 BOOL bDefaultChecksum,
			 	 unsigned short usChecksum);

	//Send a crafted UDP packet
	void SendUDP(unsigned short usUDPChecksum,BOOL bDefaultUDPChecksum);

	//CTOR
	CPacketCrafterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPacketCrafterDlg)
	enum { IDD = IDD_PACKETCRAFTER_DIALOG };
	CHyperLink	m_HyperLink;
	CIPAddressCtrl	m_ToAddress;
	CIPAddressCtrl	m_FromAddress;
	BOOL	m_DefaultIdentification;
	BOOL	m_DefaultSize;
	int		m_FragmentationType;
	BYTE	m_HeaderSize;
	DWORD	m_Identification;
	BYTE	m_TTL;
	int		m_TypeOfService;
	UINT	m_SourcePort;
	UINT	m_DestinationPort;
	UINT	m_CheckSum;
	BOOL	m_DefaultChecksum;
	UINT	m_Offset;
	UINT	m_DataSize;
	CString	m_sData;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPacketCrafterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//Configure an IP crafter
	void SetIPCrafter(CIPCrafter* pCrafter);

	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPacketCrafterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSendIp();
	afx_msg void OnSendUdp();
	afx_msg void OnSendTcp();
	afx_msg void OnSendICMP();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//Get the data from the string
	char* GetData();

	//Send a regular IP
	void SendIP(CSpoofSocket* pSocket);

	//Check that all the IP parameters are valid
	BOOL CheckValidIP();

	//Check we have a valid address
	LPSTR IPCtrlToSTR(CIPAddressCtrl* ctrl);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PACKETCRAFTERDLG_H__47A7F9A8_6D06_4F48_9A78_ECBF61D153DA__INCLUDED_)

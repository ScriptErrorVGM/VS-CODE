; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "KomodiaNSLookup.h"
LastPage=0

ClassCount=6
Class1=CKomodiaNSLookupApp
Class2=CKomodiaNSLookupDoc
Class3=CKomodiaNSLookupView
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_KOMODITYPE
Class5=CChildFrame
Class6=CAboutDlg
Resource4=IDR_KOMODITYPE (English (U.S.))
Resource5=IDD_ABOUTBOX (English (U.S.))
Resource6=IDR_MAINFRAME (English (U.S.))

[CLS:CKomodiaNSLookupApp]
Type=0
HeaderFile=KomodiaNSLookup.h
ImplementationFile=KomodiaNSLookup.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CKomodiaNSLookupDoc]
Type=0
HeaderFile=KomodiaNSLookupDoc.h
ImplementationFile=KomodiaNSLookupDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC

[CLS:CKomodiaNSLookupView]
Type=0
HeaderFile=KomodiaNSLookupView.h
ImplementationFile=KomodiaNSLookupView.cpp
Filter=C
BaseClass=CEditView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDC_WEB
BaseClass=CMDIFrameWnd
VirtualFilter=fWC


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=KomodiaNSLookup.cpp
ImplementationFile=KomodiaNSLookup.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command4=ID_APP_EXIT
Command5=ID_VIEW_TOOLBAR
Command6=ID_VIEW_STATUS_BAR
Command7=ID_APP_ABOUT
CommandCount=7
Command3=ID_FILE_MRU_FILE1

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
CommandCount=8
Command8=ID_APP_ABOUT

[MNU:IDR_KOMODITYPE]
Type=1
Class=CKomodiaNSLookupView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_WINDOW_NEW
CommandCount=18
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_EDIT_UNDO
Command15=ID_WINDOW_CASCADE
Command16=ID_WINDOW_TILE_HORZ
Command17=ID_WINDOW_ARRANGE
Command18=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
CommandCount=13
Command4=ID_EDIT_UNDO
Command13=ID_PREV_PANE


[DLG:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
ControlCount=13
Control1=IDC_DNS,SysIPAddress32,1342242816
Control2=IDC_DNSPHRASE,edit,1350631552
Control3=IDC_A,button,1342177289
Control4=IDC_MX,button,1342177289
Control5=IDC_SOA,button,1342177289
Control6=IDC_QUERY,button,1342242816
Control7=IDC_NEW,button,1476460547
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,button,1342308359
Control11=IDC_REVERSE,button,1342242819
Control12=IDC_TCP,button,1342242819
Control13=IDC_WEB,button,1342275584

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_APP_EXIT
Command2=ID_VIEW_TOOLBAR
Command3=ID_VIEW_STATUS_BAR
Command4=ID_APP_ABOUT
CommandCount=4

[MNU:IDR_KOMODITYPE (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_CLOSE
Command2=ID_APP_EXIT
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_VIEW_TOOLBAR
Command8=ID_VIEW_STATUS_BAR
Command9=ID_WINDOW_NEW
Command10=ID_WINDOW_CASCADE
Command11=ID_WINDOW_TILE_HORZ
Command12=ID_WINDOW_ARRANGE
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889


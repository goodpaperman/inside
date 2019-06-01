; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Demo.h"
LastPage=0

ClassCount=9
Class1=CDemoApp
Class2=CDemoDoc
Class3=CDemoView
Class4=CMainFrame
Class9=CAboutDlg

ResourceCount=15
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource8=IDR_CONTEXT_MENU
Resource9=IDD_ABOUTBOX (English (U.S.))
Resource10=IDR_MAINFRAME (English (U.S.))
Resource11=IDD_PROPPAGE_ADV (English (U.S.))
Resource12=IDD_PROPPAGE_SERVER (English (U.S.))
Resource13=IDD_PROPPAGE_MEDIUM (English (U.S.))
Resource14=IDD_DIALOGBAR (English (U.S.))
Resource15=IDD_PROPPAGE_CLIENT (English (U.S.))

[CLS:CDemoApp]
Type=0
HeaderFile=Demo.h
ImplementationFile=Demo.cpp
Filter=N

[CLS:CDemoDoc]
Type=0
HeaderFile=DemoDoc.h
ImplementationFile=DemoDoc.cpp
Filter=N

[CLS:CDemoView]
Type=0
HeaderFile=DemoView.h
ImplementationFile=DemoView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Demo.cpp
ImplementationFile=Demo.cpp
Filter=D

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
Command3=ID_FILE_NEW
Command4=ID_FILE_OPEN
Command5=ID_FILE_SAVE
Command6=ID_FILE_SAVE_AS
Command10=ID_FILE_MRU_FILE1
Command11=ID_APP_EXIT
Command12=ID_EDIT_UNDO
Command13=ID_EDIT_CUT
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command29=ID_VIEW_TOOLBAR
Command30=ID_VIEW_STATUS_BAR
Command32=ID_APP_ABOUT
CommandCount=32

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command17=ID_NEXT_PANE
Command18=ID_PREV_PANE
CommandCount=21


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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_EDIT_CLEAR_ALL
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_INTERNET_START_SERVER
Command15=ID_INTERNET_STOP_SERVER
Command16=ID_INTERNET_REQUEST_SOCK
Command17=ID_INTERNET_REQUEST_INET
Command18=ID_INTERNET_CONFIGURATION
Command19=ID_APP_ABOUT
CommandCount=19

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
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOGBAR (English (U.S.))]
Type=1
Class=?
ControlCount=2
Control1=IDC_REQUEST,button,1342242816
Control2=IDC_URL,edit,1350631552

[DLG:IDD_PROPPAGE_SERVER (English (U.S.))]
Type=1
Class=?
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_DIRECT,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_DEFAULT,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PORTSERVER,edit,1350631552

[DLG:IDD_PROPPAGE_ADV (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=65535,static,1342308352
Control2=IDC_IPSERVER,edit,1350631552
Control3=65535,static,1342308352
Control4=IDC_IPCLIENT,edit,1350631552

[DLG:IDD_PROPPAGE_MEDIUM (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_PROPPAGE_CLIENT (English (U.S.))]
Type=1
Class=?
ControlCount=11
Control1=65535,static,1342308352
Control2=IDC_PROXY,edit,1350631552
Control3=65535,static,1342308352
Control4=IDC_IPADDR,edit,1350631552
Control5=65535,static,1342308352
Control6=IDC_SERVER,edit,1350631552
Control7=IDC_USEPROXY,button,1342242819
Control8=65535,static,1342308352
Control9=IDC_FILE,edit,1350631552
Control10=65535,static,1342308352
Control11=IDC_PORT,edit,1350631552

[MNU:IDR_CONTEXT_MENU]
Type=1
Class=?
Command1=ID_EDIT_CLEAR_ALL
CommandCount=1


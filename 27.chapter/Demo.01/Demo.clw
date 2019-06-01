; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTextDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Demo.h"
LastPage=0

ClassCount=7
Class1=CDemoApp
Class2=CDemoDoc
Class3=CDemoView
Class4=CMainFrame
Class5=CInPlaceFrame

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource5=IDR_SRVR_EMBEDDED (English (U.S.))
Resource6=IDR_SRVR_INPLACE (English (U.S.))
Resource8=IDR_MAINFRAME (English (U.S.))
Class6=CAboutDlg
Resource3=IDR_SRVR_INPLACE
Resource4=IDR_SRVR_EMBEDDED
Resource7=IDD_ABOUTBOX (English (U.S.))
Class7=CTextDialog
Resource9=IDD_TEXT (English (U.S.))

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
BaseClass=COleServerDoc
VirtualFilter=vLODC

[CLS:CDemoView]
Type=0
HeaderFile=DemoView.h
ImplementationFile=DemoView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T

[CLS:CInPlaceFrame]
Type=0
HeaderFile=IpFrame.h
ImplementationFile=IpFrame.cpp
Filter=T



[CLS:CAboutDlg]
Type=0
HeaderFile=Demo.cpp
ImplementationFile=Demo.cpp
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
Command1=ID_APP_EXIT
Command2=ID_APP_ABOUT
CommandCount=2

[MNU:IDR_SRVR_INPLACE]
Type=1
Class=CDemoView
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
CommandCount=5
Command5=ID_APP_ABOUT

[TB:IDR_SRVR_INPLACE]
Type=1
Class=CDemoView
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
CommandCount=4
Command4=ID_APP_ABOUT

[MNU:IDR_SRVR_EMBEDDED]
Type=1
Class=CDemoView
Command1=ID_FILE_UPDATE
Command6=ID_EDIT_PASTE
Command7=ID_VIEW_TOOLBAR
Command8=ID_VIEW_STATUS_BAR
Command9=ID_APP_ABOUT
CommandCount=9
Command2=ID_APP_EXIT
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY

[ACL:IDR_SRVR_INPLACE]
Type=1
Class=CDemoView
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
CommandCount=8

[ACL:IDR_SRVR_EMBEDDED]
Type=1
Class=CDemoView
Command1=ID_FILE_UPDATE
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_NEXT_PANE
CommandCount=11
Command2=ID_EDIT_UNDO
Command11=ID_PREV_PANE


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

[TB:IDR_SRVR_INPLACE (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_APP_ABOUT
CommandCount=4

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_APP_EXIT
Command2=ID_APP_ABOUT
CommandCount=2

[MNU:IDR_SRVR_INPLACE (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_VIEW_TOOLBAR
Command6=ID_MODIFY
Command7=ID_APP_ABOUT
CommandCount=7

[MNU:IDR_SRVR_EMBEDDED (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_UPDATE
Command2=ID_APP_EXIT
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_VIEW_TOOLBAR
Command8=ID_VIEW_STATUS_BAR
Command9=ID_MODIFY
Command10=ID_APP_ABOUT
CommandCount=10

[ACL:IDR_SRVR_INPLACE (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_CANCEL_EDIT_SRVR
CommandCount=9

[ACL:IDR_SRVR_EMBEDDED (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_UPDATE
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
CommandCount=11

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CTextDialog]
Type=0
HeaderFile=TextDialog.h
ImplementationFile=TextDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTextDialog

[DLG:IDD_TEXT (English (U.S.))]
Type=1
Class=CTextDialog
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_TEXT,edit,1350631552


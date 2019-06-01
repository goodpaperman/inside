; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFontSheet
LastTemplate=CPropertySheet
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Demo.h"
LastPage=0

ClassCount=10
Class1=CDemoApp
Class2=CDemoDoc
Class3=CDemoView
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_PAGE2
Resource2=IDD_PAGE3
Resource3=IDD_PAGE1
Resource4=IDD_ABOUTBOX
Resource5=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CPage1
Class7=CPage2
Class8=CPage3
Class9=CPage4
Class10=CFontSheet
Resource6=IDD_PAGE4

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
BaseClass=CDocument
VirtualFilter=DC

[CLS:CDemoView]
Type=0
HeaderFile=DemoView.h
ImplementationFile=DemoView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CDemoView


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
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
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
Command12=ID_TRANSFER_GETDATA
Command13=ID_TRANSFER_STOREDATA
Command14=ID_FORMAT_DEFAULT
Command15=ID_FORMAT_SELECTION
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=ID_APP_ABOUT
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_SAVE
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_TRANSFER_GETDATA
Command9=ID_TRANSFER_STOREDATA
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_CUT
Command15=ID_EDIT_UNDO
CommandCount=15

[TB:IDR_MAINFRAME]
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

[DLG:IDD_PAGE1]
Type=1
Class=CPage1
ControlCount=3
Control1=IDC_FONT,button,1342308361
Control2=IDC_RADIO1,button,1342177289
Control3=IDC_RADIO3,button,1342177289

[DLG:IDD_PAGE2]
Type=1
Class=CPage2
ControlCount=3
Control1=IDC_BOLD,button,1342242819
Control2=IDC_ITALIC,button,1342242819
Control3=IDC_UNDERLINE,button,1342242819

[DLG:IDD_PAGE3]
Type=1
Class=CPage3
ControlCount=3
Control1=IDC_COLOR,button,1342308361
Control2=IDC_RADIO1,button,1342177289
Control3=IDC_RADIO3,button,1342177289

[DLG:IDD_PAGE4]
Type=1
Class=CPage4
ControlCount=2
Control1=IDC_FONTSIZE,edit,1350631552
Control2=IDC_SPIN1,msctls_updown32,1342177330

[CLS:CPage1]
Type=0
HeaderFile=Page1.h
ImplementationFile=Page1.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPage1

[CLS:CPage2]
Type=0
HeaderFile=Page2.h
ImplementationFile=Page2.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CPage3]
Type=0
HeaderFile=Page3.h
ImplementationFile=Page3.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CPage4]
Type=0
HeaderFile=property.h
ImplementationFile=property.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_FONTSIZE

[CLS:CFontSheet]
Type=0
HeaderFile=property.h
ImplementationFile=property.cpp
BaseClass=CPropertySheet
Filter=W


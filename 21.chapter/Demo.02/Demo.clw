; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDemoView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Demo.h"
LastPage=0

ClassCount=7
Class1=CDemoApp
Class2=CDemoDoc
Class3=CDemoView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CTestDemoDialog
Resource3=IDD_DEMO
Class7=CTestDemo2Dialog
Resource4=IDD_DEMO2

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
BaseClass=CView
VirtualFilter=VWC
LastObject=IDC_RYG


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_TEST_DEMO2DLL




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
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_TEST_DEMODLL
Command17=ID_TEST_DEMO2DLL
Command18=ID_APP_ABOUT
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

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

[DLG:IDD_DEMO]
Type=1
Class=CTestDemoDialog
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_INPUT,edit,1350631552
Control3=IDC_COMPUTE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_OUTPUT,edit,1350631552
Control6=IDOK,button,1342242817
Control7=IDCANCEL,button,1342242816

[CLS:CTestDemoDialog]
Type=0
HeaderFile=TestDemoDialog.h
ImplementationFile=TestDemoDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_COMPUTE

[DLG:IDD_DEMO2]
Type=1
Class=CTestDemo2Dialog
ControlCount=4
Control1=IDC_RYG,RYG,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816

[CLS:CTestDemo2Dialog]
Type=0
HeaderFile=TestDemo2Dialog.h
ImplementationFile=TestDemo2Dialog.cpp
BaseClass=CDialog
Filter=D


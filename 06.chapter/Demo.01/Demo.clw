; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDemoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Demo.h"
LastPage=0

ClassCount=6
Class1=CDemoApp
Class2=CDemoDoc
Class3=CDemoView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CDemoDlg
Resource3=IDD_DIALOG1

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
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
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

[DLG:IDD_DIALOG1]
Type=1
Class=CDemoDlg
ControlCount=30
Control1=IDC_STATIC,static,1342308352
Control2=IDC_NAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_SSN,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BIO,edit,1350631428
Control7=IDC_STATIC,button,1342177287
Control8=IDC_CAT,button,1342373897
Control9=IDC_RADIO2,button,1342242825
Control10=IDC_STATIC,button,1342308359
Control11=IDC_LIFE,button,1342242819
Control12=IDC_DIS,button,1342242819
Control13=IDC_MED,button,1342242819
Control14=IDC_STATIC,static,1342308352
Control15=IDC_SKILL,combobox,1344340225
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDUC,combobox,1344340226
Control18=IDC_STATIC,static,1342308352
Control19=IDC_DEPT,listbox,1352728835
Control20=IDC_STATIC,static,1342308352
Control21=IDC_LANG,combobox,1344340227
Control22=IDC_STATIC,static,1342308352
Control23=IDC_LOYAL,scrollbar,1342177280
Control24=IDC_STATIC,static,1342308352
Control25=IDC_RELY,scrollbar,1342177280
Control26=IDC_OK,button,1342242816
Control27=IDCANCEL,button,1342242816
Control28=IDC_SPECIAL,button,1342242816
Control29=IDC_STATIC,static,1342177283
Control30=IDC_STATIC1,static,1342308352

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

[CLS:CDemoDlg]
Type=0
HeaderFile=DemoDlg.h
ImplementationFile=DemoDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDemoDlg


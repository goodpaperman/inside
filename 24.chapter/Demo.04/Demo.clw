; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAlarm
LastTemplate=CCmdTarget
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Demo.h"
ODLFile=Demo.odl
LastPage=0

ClassCount=6
Class1=CDemoApp
Class2=CDemoDoc
Class3=CDemoView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CAlarm
Resource2=IDD_ABOUTBOX

[CLS:CDemoApp]
Type=0
HeaderFile=Demo.h
ImplementationFile=Demo.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

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


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Demo.cpp
ImplementationFile=Demo.cpp
Filter=D

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
Command11=ID_APP_ABOUT
CommandCount=11

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

[CLS:CAlarm]
Type=0
HeaderFile=Alarm.h
ImplementationFile=Alarm.cpp
BaseClass=CCmdTarget
Filter=N
VirtualFilter=C


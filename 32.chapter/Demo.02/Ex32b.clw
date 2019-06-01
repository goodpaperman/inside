; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx32bView
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex32b.h"
LastPage=0

ClassCount=7
Class1=CEx32bApp
Class2=CEx32bDoc
Class3=CEx32bView
Class4=CMainFrame
Class5=CInPlaceFrame

ResourceCount=12
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource4=IDR_SRVR_INPLACE
Resource5=IDR_SRVR_EMBEDDED
Resource6=IDD_EX32B_FORM
Resource7=IDR_SRVR_EMBEDDED (English (U.S.))
Resource8=IDD_ABOUTBOX (English (U.S.))
Resource9=IDR_MAINFRAME (English (U.S.))
Resource10=IDR_SRVR_INPLACE (English (U.S.))
Resource11=IDR_CNTR_INPLACE (English (U.S.))
Resource3=IDR_CNTR_INPLACE
Class6=CAboutDlg
Class7=CValidForm
Resource12=IDD_EX32B_FORM (English (U.S.))

[CLS:CEx32bApp]
Type=0
HeaderFile=Ex32b.h
ImplementationFile=Ex32b.cpp
Filter=N

[CLS:CEx32bDoc]
Type=0
HeaderFile=Ex32bDoc.h
ImplementationFile=Ex32bDoc.cpp
Filter=N

[CLS:CEx32bView]
Type=0
HeaderFile=Ex32bView.h
ImplementationFile=Ex32bView.cpp
Filter=D
BaseClass=CValidForm
LastObject=CEx32bView


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
HeaderFile=Ex32b.cpp
ImplementationFile=Ex32b.cpp
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
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command10=ID_EDIT_PASTE
Command11=ID_EDIT_PASTE_SPECIAL
Command12=ID_OLE_INSERT_NEW
Command13=ID_OLE_EDIT_LINKS
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY

[MNU:IDR_CNTR_INPLACE]
Type=1
Class=CEx32bView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
CommandCount=6
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT

[MNU:IDR_SRVR_INPLACE]
Type=1
Class=CEx32bView
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
CommandCount=8
Command5=ID_EDIT_PASTE_SPECIAL
Command6=ID_OLE_INSERT_NEW
Command7=ID_OLE_EDIT_LINKS
Command8=ID_APP_ABOUT

[TB:IDR_SRVR_INPLACE]
Type=1
Class=CEx32bView
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
CommandCount=4
Command4=ID_APP_ABOUT

[MNU:IDR_SRVR_EMBEDDED]
Type=1
Class=CEx32bView
Command1=ID_FILE_UPDATE
Command2=ID_FILE_SAVE_COPY_AS
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_PASTE_SPECIAL
Command9=ID_OLE_INSERT_NEW
Command10=ID_OLE_EDIT_LINKS
CommandCount=13
Command3=ID_APP_EXIT
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT

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

[ACL:IDR_CNTR_INPLACE]
Type=1
Class=CEx32bView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_PREV_PANE
CommandCount=5
Command4=ID_NEXT_PANE

[ACL:IDR_SRVR_INPLACE]
Type=1
Class=CEx32bView
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
Class=CEx32bView
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

[DLG:IDD_EX32B_FORM]
Type=1
Class=CEx32bView

[DLG:IDD_EX32B_FORM (English (U.S.))]
Type=1
Class=CEx32bView
ControlCount=11
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PERIOD,edit,1350633600
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,combobox,1344340226
Control5=IDC_STATIC,static,1342308352
Control6=IDC_HOURS,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_JOB,edit,1350631552
Control9=IDC_NUM,msctls_updown32,1342177330
Control10=IDC_SUBMIT,button,1342242816
Control11=IDCANCEL,button,1342242816

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
Command11=ID_EDIT_PASTE_SPECIAL
Command12=ID_OLE_INSERT_NEW
Command13=ID_OLE_EDIT_LINKS
Command14=ID_OLE_VERB_FIRST
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_APP_ABOUT
CommandCount=17

[MNU:IDR_CNTR_INPLACE (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
CommandCount=6

[MNU:IDR_SRVR_INPLACE (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_PASTE_SPECIAL
Command6=ID_OLE_INSERT_NEW
Command7=ID_OLE_EDIT_LINKS
Command8=ID_OLE_VERB_FIRST
Command9=ID_VIEW_TOOLBAR
Command10=ID_APP_ABOUT
CommandCount=10

[MNU:IDR_SRVR_EMBEDDED (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_UPDATE
Command2=ID_FILE_SAVE_COPY_AS
Command3=ID_APP_EXIT
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_PASTE_SPECIAL
Command9=ID_OLE_INSERT_NEW
Command10=ID_OLE_EDIT_LINKS
Command11=ID_OLE_VERB_FIRST
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_APP_ABOUT
CommandCount=14

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
Command14=ID_CANCEL_EDIT_CNTR
CommandCount=14

[ACL:IDR_CNTR_INPLACE (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_NEXT_PANE
Command5=ID_PREV_PANE
Command6=ID_CANCEL_EDIT_CNTR
CommandCount=6

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
Command12=ID_CANCEL_EDIT_CNTR
CommandCount=12

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CValidForm]
Type=0
HeaderFile=ValidForm.h
ImplementationFile=ValidForm.cpp
BaseClass=CFormView
Filter=D
VirtualFilter=VWC


; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex32a.h"
LastPage=0

ClassCount=9
Class1=CEx32aApp
Class2=CEx32aDoc
Class3=CEx32aView
Class4=CMainFrame
Class5=CInPlaceFrame
Class9=CAboutDlg

ResourceCount=13
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource4=IDR_CNTR_INPLACE
Resource5=IDR_SRVR_INPLACE
Resource6=IDR_SRVR_EMBEDDED
Resource8=IDR_SRVR_EMBEDDED (English (U.S.))
Resource9=IDD_ABOUTBOX (English (U.S.))
Resource10=IDR_MAINFRAME (English (U.S.))
Resource11=IDR_SRVR_INPLACE (English (U.S.))
Resource12=IDR_CNTR_INPLACE (English (U.S.))
Resource13=IDD_DIALOGBAR (English (U.S.))

[CLS:CEx32aApp]
Type=0
HeaderFile=Ex32a.h
ImplementationFile=Ex32a.cpp
Filter=N

[CLS:CEx32aDoc]
Type=0
HeaderFile=Ex32aDoc.h
ImplementationFile=Ex32aDoc.cpp
Filter=N
BaseClass=CRichEditDoc
VirtualFilter=DC

[CLS:CEx32aView]
Type=0
HeaderFile=Ex32aView.h
ImplementationFile=Ex32aView.cpp
Filter=C


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
HeaderFile=Ex32a.cpp
ImplementationFile=Ex32a.cpp
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
Command14=ID_EDIT_SELECT_ALL
Command15=ID_EDIT_FIND
Command16=ID_EDIT_REPEAT
Command17=ID_EDIT_REPLACE
Command18=ID_OLE_EDIT_PROPERTIES
Command19=ID_VIEW_TOOLBAR
Command20=ID_VIEW_STATUS_BAR
Command21=ID_APP_ABOUT
CommandCount=21
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY

[MNU:IDR_CNTR_INPLACE]
Type=1
Class=CEx32aView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
CommandCount=6
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT

[MNU:IDR_SRVR_INPLACE]
Type=1
Class=CEx32aView
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
CommandCount=13
Command5=ID_EDIT_PASTE_SPECIAL
Command6=ID_OLE_INSERT_NEW
Command7=ID_OLE_EDIT_LINKS
Command8=ID_EDIT_SELECT_ALL
Command9=ID_EDIT_FIND
Command10=ID_EDIT_REPEAT
Command11=ID_EDIT_REPLACE
Command12=ID_OLE_EDIT_PROPERTIES
Command13=ID_APP_ABOUT

[TB:IDR_SRVR_INPLACE]
Type=1
Class=CEx32aView
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
CommandCount=4
Command4=ID_APP_ABOUT

[MNU:IDR_SRVR_EMBEDDED]
Type=1
Class=CEx32aView
Command1=ID_FILE_UPDATE
Command2=ID_FILE_SAVE_COPY_AS
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_PASTE_SPECIAL
Command9=ID_OLE_INSERT_NEW
Command10=ID_OLE_EDIT_LINKS
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=ID_APP_ABOUT
CommandCount=18
Command3=ID_APP_EXIT
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command11=ID_EDIT_SELECT_ALL
Command12=ID_EDIT_FIND
Command13=ID_EDIT_REPEAT
Command14=ID_EDIT_REPLACE
Command15=ID_OLE_EDIT_PROPERTIES

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
Command12=ID_EDIT_SELECT_ALL
Command13=ID_EDIT_FIND
Command14=ID_EDIT_REPEAT
Command15=ID_EDIT_REPLACE
Command16=ID_NEXT_PANE
Command17=ID_PREV_PANE
CommandCount=17
Command4=ID_EDIT_UNDO

[ACL:IDR_CNTR_INPLACE]
Type=1
Class=CEx32aView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_PREV_PANE
CommandCount=5
Command4=ID_NEXT_PANE

[ACL:IDR_SRVR_INPLACE]
Type=1
Class=CEx32aView
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
CommandCount=12
Command9=ID_EDIT_SELECT_ALL
Command10=ID_EDIT_FIND
Command11=ID_EDIT_REPEAT
Command12=ID_EDIT_REPLACE

[ACL:IDR_SRVR_EMBEDDED]
Type=1
Class=CEx32aView
Command1=ID_FILE_UPDATE
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_EDIT_SELECT_ALL
Command13=ID_EDIT_REPLACE
Command14=ID_NEXT_PANE
Command15=ID_PREV_PANE
CommandCount=15
Command2=ID_EDIT_UNDO
Command11=ID_EDIT_FIND
Command12=ID_EDIT_REPEAT


[DLG:IDD_DIALOGBAR (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_URL,edit,1350631552
Control3=IDC_START,button,1342242944
Control4=IDC_STOP,button,1342242944

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
Command12=ID_EDIT_SELECT_ALL
Command13=ID_EDIT_FIND
Command14=ID_EDIT_REPEAT
Command15=ID_EDIT_REPLACE
Command16=ID_OLE_INSERT_NEW
Command17=ID_OLE_EDIT_LINKS
Command18=ID_OLE_EDIT_PROPERTIES
Command19=ID_OLE_VERB_FIRST
Command20=ID_VIEW_TOOLBAR
Command21=ID_VIEW_STATUS_BAR
Command22=ID_APP_ABOUT
CommandCount=22

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
Command6=ID_EDIT_SELECT_ALL
Command7=ID_EDIT_FIND
Command8=ID_EDIT_REPEAT
Command9=ID_EDIT_REPLACE
Command10=ID_OLE_INSERT_NEW
Command11=ID_OLE_EDIT_LINKS
Command12=ID_OLE_EDIT_PROPERTIES
Command13=ID_OLE_VERB_FIRST
Command14=ID_VIEW_TOOLBAR
Command15=ID_APP_ABOUT
CommandCount=15

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
Command9=ID_EDIT_SELECT_ALL
Command10=ID_EDIT_FIND
Command11=ID_EDIT_REPEAT
Command12=ID_EDIT_REPLACE
Command13=ID_OLE_INSERT_NEW
Command14=ID_OLE_EDIT_LINKS
Command15=ID_OLE_EDIT_PROPERTIES
Command16=ID_OLE_VERB_FIRST
Command17=ID_VIEW_TOOLBAR
Command18=ID_VIEW_STATUS_BAR
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
Command8=ID_EDIT_SELECT_ALL
Command9=ID_EDIT_FIND
Command10=ID_EDIT_REPEAT
Command11=ID_EDIT_REPLACE
Command12=ID_OLE_EDIT_PROPERTIES
Command13=ID_EDIT_UNDO
Command14=ID_EDIT_CUT
Command15=ID_EDIT_COPY
Command16=ID_EDIT_PASTE
Command17=ID_NEXT_PANE
Command18=ID_PREV_PANE
Command19=ID_CANCEL_EDIT_CNTR
CommandCount=19

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
Command5=ID_EDIT_SELECT_ALL
Command6=ID_EDIT_FIND
Command7=ID_EDIT_REPEAT
Command8=ID_EDIT_REPLACE
Command9=ID_OLE_EDIT_PROPERTIES
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_CANCEL_EDIT_SRVR
CommandCount=14

[ACL:IDR_SRVR_EMBEDDED (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_UPDATE
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_SELECT_ALL
Command7=ID_EDIT_FIND
Command8=ID_EDIT_REPEAT
Command9=ID_EDIT_REPLACE
Command10=ID_OLE_EDIT_PROPERTIES
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_NEXT_PANE
Command16=ID_PREV_PANE
Command17=ID_CANCEL_EDIT_CNTR
CommandCount=17

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889


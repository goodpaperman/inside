; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSectionSet
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Demo.h"
LastPage=0

ClassCount=7
Class1=CDemoApp
Class2=CDemoDoc
Class3=CDemoView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CDemoSet
Resource3=IDD_DEMO_FORM
Resource4=IDR_MAINFRAME (English (U.S.))
Resource5=IDD_ABOUTBOX (English (U.S.))
Class7=CSectionSet
Resource6=IDD_DEMO_FORM (English (U.S.))

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
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=ID_RECORD_UPDATE


[CLS:CDemoSet]
Type=0
HeaderFile=DemoSet.h
ImplementationFile=DemoSet.cpp
Filter=N

[DB:CDemoSet]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[InstructorID], 12, 16
Column2=[Name], 12, 80
Column3=[RoomNo], 12, 20


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
Command10=ID_RECORD_LAST
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13
Command1=ID_FILE_MRU_FILE1
Command2=ID_APP_EXIT
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_RECORD_FIRST
Command8=ID_RECORD_PREV
Command9=ID_RECORD_NEXT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_NEXT_PANE
Command10=ID_PREV_PANE
CommandCount=10
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE

[DLG:IDD_DEMO_FORM]
Type=1
Class=CDemoView

[DLG:IDD_DEMO_FORM (English (U.S.))]
Type=1
Class=CDemoView
ControlCount=9
Control1=IDC_STATIC,static,1342308865
Control2=IDC_STATIC,static,1342308352
Control3=IDC_ID,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_NAME,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_ROOM,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_SECTION,listbox,1352728835

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_RECORD_FIRST
Command6=ID_RECORD_PREV
Command7=ID_RECORD_NEXT
Command8=ID_RECORD_LAST
Command9=ID_APP_ABOUT
CommandCount=9

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_APP_EXIT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_RECORD_FIRST
Command7=ID_RECORD_PREV
Command8=ID_RECORD_NEXT
Command9=ID_RECORD_LAST
Command10=ID_RECORD_ADD
Command11=ID_RECORD_CLEARFIELDS
Command12=ID_RECORD_DELETE
Command13=ID_RECORD_UPDATE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME (English (U.S.))]
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
Command9=ID_NEXT_PANE
Command10=ID_PREV_PANE
CommandCount=10

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CSectionSet]
Type=0
HeaderFile=SectionSet.h
ImplementationFile=SectionSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CSectionSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[CourseID], 12, 16
Column2=[SectionNo], 12, 8
Column3=[InstructorID], 12, 16
Column4=[RoomNo], 12, 20
Column5=[Schedule], 12, 48
Column6=[Capacity], 5, 2


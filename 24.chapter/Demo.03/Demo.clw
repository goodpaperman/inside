; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
ODLFile=Demo.odl
ClassCount=3
Class1=CDemoApp
LastClass=CDemoAuto
NewFileInclude2=#include "Demo.h"
ResourceCount=1
NewFileInclude1=#include "stdafx.h"
Class2=CPromptDlg
LastTemplate=CCmdTarget
Class3=CDemoAuto
Resource1=IID_PROMPT

[CLS:CDemoApp]
Type=0
HeaderFile=Demo.h
ImplementationFile=Demo.cpp
Filter=N
LastObject=IDC_STRING

[DLG:IID_PROMPT]
Type=1
Class=CPromptDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STRING,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_LONG,edit,1350631552

[CLS:CPromptDlg]
Type=0
HeaderFile=PromptDlg.h
ImplementationFile=PromptDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CDemoAuto]
Type=0
HeaderFile=DemoAuto.h
ImplementationFile=DemoAuto.cpp
BaseClass=CCmdTarget
Filter=N
LastObject=CDemoAuto
VirtualFilter=C


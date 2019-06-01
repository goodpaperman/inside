@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by DEMO.HPJ. >"hlp\Demo.hm"
echo. >>"hlp\Demo.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Demo.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Demo.hm"
echo. >>"hlp\Demo.hm"
echo // Prompts (IDP_*) >>"hlp\Demo.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Demo.hm"
echo. >>"hlp\Demo.hm"
echo // Resources (IDR_*) >>"hlp\Demo.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Demo.hm"
echo. >>"hlp\Demo.hm"
echo // Dialogs (IDD_*) >>"hlp\Demo.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Demo.hm"
echo. >>"hlp\Demo.hm"
echo // Frame Controls (IDW_*) >>"hlp\Demo.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Demo.hm"
REM -- Make help for Project DEMO


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Demo.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Demo.hlp" goto :Error
if not exist "hlp\Demo.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Demo.hlp" Debug
if exist Debug\nul copy "hlp\Demo.cnt" Debug
if exist Release\nul copy "hlp\Demo.hlp" Release
if exist Release\nul copy "hlp\Demo.cnt" Release
echo.
goto :done

:Error
echo hlp\Demo.hpj(1) : error: Problem encountered creating help file

:done
echo.
pause
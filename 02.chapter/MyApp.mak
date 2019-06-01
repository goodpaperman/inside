# filename : MyApp.mak
# make file for MyApp.exe (MFC 4.0 Application)
# usage : nmake MyApp.mak (Visual C++ 5.0)

MyApp.exe : MyApp.obj
    link.exe /nologo /subsystem:windows /incremental:no \
        /machine:I386 /out:"MyApp.exe" \
        MyApp.obj \
        msvcrt.lib kernel32.lib user32.lib gdi32.lib mfc42.lib

MyApp.obj : MyApp.cpp MyApp.h
    cl.exe /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" \
        /D "_AFXDLL" /D "_MBCS" \
        /c MyApp.cpp

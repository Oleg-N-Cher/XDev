@ECHO OFF
IF "%XDev%"=="" SET XDev=..
SET WinDev=%XDev%\WinDev
SET PATH=%WinDev%\Bin\MinGW\bin;%PATH%

SET Options=-Os -fno-exceptions -fno-asynchronous-unwind-tables
SET Include=-I.. -I..\Mod
SET GCC=gcc.exe %Options% %Include%

IF EXIST ..\Mod\%1.c GOTO CLib

:OLib
%GCC% -c %1.c
IF errorlevel 1 GOTO NoInit
GOTO Exit

:NoInit
COPY /Y %1.c %1.c__
..\..\..\Bin\smartlib %1.c -noinit -nocut
%GCC% -c %1.c
MOVE /Y %1.c__ %1.c
GOTO Exit

:CLib
IF EXIST %1.h DEL %1.h
IF EXIST %1.c DEL %1.c
%GCC% -c ..\Mod\%1.c

:Exit
IF errorlevel 1 PAUSE

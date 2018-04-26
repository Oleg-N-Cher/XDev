@ECHO OFF
IF "%XDev%"=="" SET XDev=..
SET WinDev=%XDev%\WinDev
SET PATH=%WinDev%\Bin\MinGW64\bin;%PATH%

SET Options=-m64 -Os -g0 -fvisibility=hidden -fomit-frame-pointer -finline-small-functions -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-exceptions -ffunction-sections
SET Include=-I.. -I..\Mod
SET GCC=gcc.exe %Options% %Include%

IF EXIST ..\Mod\%2.c GOTO CLib

:OLib
%GCC% -c %2.c
GOTO Done

:CLib
IF EXIST %2.h DEL %2.h
IF EXIST %2.c DEL %2.c
%GCC% -c ..\Mod\%2.c

:Done
IF errorlevel 1 PAUSE

ar.exe -rc %1 %2.o
DEL %2.o

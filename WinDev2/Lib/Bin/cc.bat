@ECHO OFF
IF "%XDev%"=="" SET XDev=..
SET WinDev=%XDev%\WinDev2
SET PATH=%WinDev%\Bin\GCC\bin;%PATH%

SET Options= -m32 -Os -fno-exceptions -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections
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

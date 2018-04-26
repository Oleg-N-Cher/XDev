@ECHO OFF
IF "%XDev%"=="" SET XDev=..
SET RootBin=%XDev%\Bin
SET WinDev=%XDev%\WinDev
SET PATH=%WinDev%\Bin\MinGW\bin;%PATH%

SET Options=-m32 -Os -g0 -fvisibility=hidden -fomit-frame-pointer -finline-small-functions -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-exceptions -ffunction-sections
SET Include=-I.. -I..\Mod
SET GCC=gcc.exe %Options% %Include%

IF EXIST ..\Mod\%2.c GOTO CLib

:OLib
%RootBin%\smartlib %2.c %3 %4 %5
GOTO Compile

:CLib
IF EXIST %2.h DEL %2.h
IF EXIST %2.c DEL %2.c
%RootBin%\smartlib ..\Mod\%2.c %3 %4 %5

:Compile
FOR %%i IN (%2_???.c) DO (
  %GCC% -c %%i
  IF errorlevel 1 PAUSE
)
FOR %%i IN (%2_???.o) DO ar.exe -rc %1 %%i
DEL *.o
DEL *_0??.c

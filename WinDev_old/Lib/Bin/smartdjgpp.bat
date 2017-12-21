@REM args:
@REM   LibName ModName [PartName] [-noinit] [-nocut]

@SET RootBin=..\..\..\Bin
@SET Bin=..\..\Bin
@SET DJGPP=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\djgpp.env
@SET PATH=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\bin
@SET gcc=gcc.exe @..\Bin\djgpp.opt

@IF EXIST ..\C\%2.c GOTO clib

:olib
%RootBin%\smartlib %2.c %3 %4 %5
@GOTO compile

:clib
@IF EXIST %2.h DEL %2.h
@IF EXIST %2.c DEL %2.c
%RootBin%\smartlib ..\C\%2.c %3 %4 %5

:compile
@FOR %%i IN (%2_???.c) DO (
  %gcc% -c %%i -I ".." -I ..\C
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%2_???.o) DO ar.exe -rc %1 %%i
@%Bin%\clear

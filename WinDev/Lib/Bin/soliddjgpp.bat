@REM args:
@REM   LibName ModName

@SET RootBin=..\..\..\Bin
@SET Bin=..\..\Bin
@SET DJGPP=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\djgpp.env
@SET PATH=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\bin
@SET gcc=gcc.exe @..\Bin\djgpp.opt

@IF EXIST ..\C\%2.c GOTO clib

:olib
%gcc% -c %2.c -I ".." -I ..\C
@GOTO done

:clib
@IF EXIST %2.h DEL %2.h
@IF EXIST %2.c DEL %2.c
%gcc% -c ..\C\%2.c -I ".." -I ..\C

:done
@IF errorlevel 1 PAUSE

@ar.exe -rc %1 %2.o
@DEL %2.o

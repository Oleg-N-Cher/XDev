@REM args:
@REM   LibName ModName

@SET RootBin=..\..\..\Bin
@SET PATH=..\..\Bin\MinGW\bin
@SET gcc=gcc.exe -Os -fno-exceptions -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections

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

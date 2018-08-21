@ECHO OFF
IF NOT "%ZCCCFG%"=="" GOTO z88dk
ECHO Please install z88dk and set up the system variable ZCCCFG
PAUSE
EXIT

:z88dk

SET Opt=-SO3 --opt-code-size --max-allocs-per-node200000
SET CC=zcc.exe +zx -vn -x -clib=sdcc_iy %Opt% -Cs"--disable-warning 85" -Cs"--disable-warning 59"
SET smartlib=..\..\..\Bin\smartlib.exe

CD ..\Obj
IF EXIST Basic.h DEL Basic.h
IF EXIST Basic.c DEL Basic.c

%smartlib% ..\C\Basic.c
DIR /B Basic_???.c > z88dk_Basic.lst

%CC% @z88dk_Basic.lst -o ..\z88dk_Basic.lib
IF errorlevel 1 PAUSE

DEL /Q z88dk_Basic.lst
..\Bin\clear

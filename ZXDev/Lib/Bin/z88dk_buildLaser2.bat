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
IF EXIST Laser2.h DEL Laser2.h
IF EXIST Laser2.c DEL Laser2.c

%smartlib% ..\C\Laser2.c
DIR /B Laser2_???.c > z88dk_Laser2.lst

%CC% @z88dk_Laser2.lst -o ..\z88dk_Laser2.lib
IF errorlevel 1 PAUSE

DEL /Q z88dk_Laser2.lst
..\Bin\clear

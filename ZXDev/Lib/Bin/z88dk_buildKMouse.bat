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
IF EXIST KMouse.oh DEL KMouse.oh
IF EXIST KMouse.c DEL KMouse.c

%smartlib% ..\C\KMouse.c
DIR /B KMouse_???.c > z88dk_KMouse.lst

%CC% @z88dk_KMouse.lst -o ..\z88dk_KMouse.lib
IF errorlevel 1 PAUSE

DEL /Q z88dk_KMouse.lst
..\Bin\clear

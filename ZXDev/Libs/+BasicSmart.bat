@REM Compile the library Basic
@REM =========================
@SET rootbin=..\..\Bin
@SET bin=..\Bin
@SET obj=..\..\Ofront\Obj

@IF EXIST %obj%\Basic.h @DEL %obj%\Basic.h
@IF EXIST %obj%\Basic.c @DEL %obj%\Basic.c

%rootbin%\smartlinkrel Basic.c
@FOR %%i IN (Basic_0??.c) DO %bin%\sdcc -c -mz80 --no-std-crt0 --opt-code-size --funsigned-char --disable-warning 59 --disable-warning 85 -I "..\Obj" -L z80 %%i

@IF EXIST Basic.lib DEL Basic.lib
REM @FOR %%i IN (Basic_0??.rel) DO %bin%\sdcclib Basic.lib %%i
@FOR %%i IN (Basic_0??.rel) DO %bin%\sdar -rc Basic.lib %%i

@MOVE /Y Basic.lib z80/Basic.lib

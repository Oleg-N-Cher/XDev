@REM Compile the library Basic
@REM =========================
@SET bin=..\Bin
@SET obj=..\..\Ofront\Obj

@IF EXIST %obj%\Basic.h @DEL %obj%\Basic.h
@IF EXIST %obj%\Basic.c @DEL %obj%\Basic.c

%bin%\sdcc -c -mz80 --no-std-crt0 --opt-code-size --funsigned-char --disable-warning 59 --disable-warning 85 -I "..\Obj" -L z80 Basic.c

@PAUSE

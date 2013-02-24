@REM Compile TinyHello.c
@REM ===================

@SET bin=..\Bin
@SET libs=..\Libs
@SET obj=..\..\Ofront\Obj

@IF EXIST %obj%\TinyHello.h @DEL %obj%\TinyHello.h
@IF EXIST %obj%\TinyHello.sym @DEL %obj%\TinyHello.sym
@IF EXIST %obj%\TinyHello.c @MOVE /Y %obj%\TinyHello.c
%bin%\sdcc -mz80 --code-loc 26000 --data-loc 0xF800 --no-std-crt0 --opt-code-size --funsigned-char -I "." -I %libs% -L %libs%/z80 TinyHello.c Basic.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\Hex2bin TinyHello.ihx

@REM Link the target to TAP format
@REM =============================
@DEL /Q TinyHello.tap
%bin%\bin2data.exe -rem -org 26000 TinyHello.bin ..\TinyHello.tap TinyHello

@REM ======================================================================
@ECHO Now you can run the image "TinyHello.tap" in your favourite emulator.
@REM ======================================================================

START ..\TinyHello.tap
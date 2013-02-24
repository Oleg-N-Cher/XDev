@REM Compile HelloWorld.c
@REM ====================

@SET bin=..\Bin
@SET libs=..\Libs
@SET obj=..\..\Ofront\Obj

@IF EXIST %obj%\HelloWorld.h @DEL %obj%\HelloWorld.h
@IF EXIST %obj%\HelloWorld.sym @DEL %obj%\HelloWorld.sym
@IF EXIST %obj%\HelloWorld.c @MOVE /Y %obj%\HelloWorld.c
%bin%\sdcc -mz80 --code-loc 26000 --data-loc 0xF800 --no-std-crt0 --opt-code-size --funsigned-char --disable-warning 126 -I "." -I %libs% -L %libs%/z80 HelloWorld.c Basic.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\Hex2bin HelloWorld.ihx

@REM Link the target to TAP format
@REM =============================
@DEL /Q HelloWorld.tap
%bin%\bin2data.exe -rem -org 26000 HelloWorld.bin ..\HelloWorld.tap HelloWorld

@REM ======================================================================
@ECHO Now you can run the image "HelloWorld.tap" in your favourite emulator
@REM ======================================================================

START ..\HelloWorld.tap
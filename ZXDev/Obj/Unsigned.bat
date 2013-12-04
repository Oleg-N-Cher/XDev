@REM Compile Unsigned.c
@REM ==================

@SET bin=..\Bin
@SET lib=..\Lib
@SET obj=..\..\Ofront\Obj

@IF EXIST %obj%\Unsigned.h @DEL %obj%\Unsigned.h
@IF EXIST %obj%\Unsigned.sym @DEL %obj%\Unsigned.sym
@IF EXIST %obj%\Unsigned.c @MOVE /Y %obj%\Unsigned.c
%bin%\sdcc -mz80 --code-loc 26000 --data-loc 0xF800 --opt-code-size --funsigned-char -I "." -I %lib% -L %lib%/z80 Unsigned.c Basic.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\hex2bin Unsigned.ihx

@REM Link the target to TAP format
@REM =============================
@DEL /Q Unsigned.tap
%bin%\bin2data.exe -rem -org 26000 Unsigned.bin ..\Unsigned.tap Unsigned

@REM =====================================================================
@ECHO Now you can run the image "Unsigned.tap" in your favourite emulator.
@REM =====================================================================

START ..\Unsigned.tap
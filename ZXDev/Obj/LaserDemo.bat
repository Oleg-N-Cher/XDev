@REM Compile LaserDemo.c
@REM ===================

@SET bin=..\Bin
@SET libs=..\Libs
@SET obj=..\..\Ofront\Obj

@IF EXIST %obj%\LaserDemo.h @DEL %obj%\LaserDemo.h
@IF EXIST %obj%\LaserDemo.sym @DEL %obj%\LaserDemo.sym
@IF EXIST %obj%\LaserDemo.c @MOVE /Y %obj%\LaserDemo.c
%bin%\sdcc -mz80 --code-loc 26000 --data-loc 0xF800 --no-std-crt0 --opt-code-size --funsigned-char --disable-warning 126 -I "." -I %libs% -L %libs%/z80 LaserDemo.c Basic.lib Laser.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\hex2bin LaserDemo.ihx

@REM Link the target to TR-DOS format
@REM ================================
@DEL /Q LaserDemo.trd
%bin%\bin2trd.exe LaserDemo.trl
@ATTRIB -R laserdemo.trd
@MOVE /Y laserdemo.trd ..\LaserDemo.trd

@REM ======================================================================
@ECHO Now you can run the image "LaserDemo.trd" in your favourite emulator
@REM ======================================================================

START ..\LaserDemo.trd
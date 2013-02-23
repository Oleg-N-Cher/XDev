@REM Compile TurtleDemo.c
@REM ===================

@SET bin=..\Bin
@SET libs=..\Libs
@SET obj=..\..\Ofront\Obj

@IF EXIST %obj%\TurtleDemo.h @DEL %obj%\TurtleDemo.h
@IF EXIST %obj%\TurtleDemo.sym @DEL %obj%\TurtleDemo.sym
@IF EXIST %obj%\TurtleDemo.c @MOVE /Y %obj%\TurtleDemo.c
%bin%\sdcc -mz80 --code-loc 26000 --data-loc 0xF800 --no-std-crt0 --opt-code-size --funsigned-char --disable-warning 126 -I "." -I %libs% -L %libs%/z80 TurtleDemo.c Basic.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\Hex2bin TurtleDemo.ihx

@REM Link the target to TR-DOS format
@REM ================================
@REM WARNING! bin2trd is a MS-DOS program, must use a short filename
@DEL /Q TURTLE~1.TRD
%bin%\bin2trd.exe Turtle~1.trl
@MOVE /Y TURTLE~1.TRD ../TurtleDemo.trd

@REM ======================================================================
@ECHO Now you can run the image "TurtleDemo.trd" in your favourite emulator
@REM ======================================================================

START ..\TurtleDemo.trd
@REM Compile GraphSinus.c
@REM ====================

@SET bin=..\Bin
@SET lib=..\Lib
@SET obj=..\..\Ofront\Obj

@IF EXIST %obj%\GraphSinus.h @DEL %obj%\GraphSinus.h
@IF EXIST %obj%\GraphSinus.sym @DEL %obj%\GraphSinus.sym
@IF EXIST %obj%\GraphSinus.c @MOVE /Y %obj%\GraphSinus.c
%bin%\sdcc GraphSinus.c -mz80 --code-loc 40000 --data-loc 45000 --opt-code-size --funsigned-char --disable-warning 126 -I %lib% -I %lib%\C -I %lib%\Obj -L %lib% --disable-warning 59 --disable-warning 85 Graph.lib XDev.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\hex2bin GraphSinus.ihx

@REM %bin%\stripbin GraphSinus.bin

@REM Link the target to TAP format
@REM =============================
@DEL /Q GraphSinus.tap
%bin%\bin2data.exe -rem -org 40000 GraphSinus.bin ..\GraphSinus.tap GraphSinus

@REM ======================================================================
@ECHO Now you can run the image "GraphSinus.tap" in your favourite emulator
@REM ======================================================================

START ..\GraphSinus.tap
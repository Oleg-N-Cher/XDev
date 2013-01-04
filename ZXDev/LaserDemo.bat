@REM Compile LaserDemo.c
@REM ===================
@SET bin=..\Bin
@SET libs=..\Libs
@SET obj=..\..\Ofront\Obj
@CD Obj

@IF EXIST %obj%\LaserDemo.h @DEL %obj%\LaserDemo.h
@IF EXIST %obj%\LaserDemo.sym @DEL %obj%\LaserDemo.sym
@IF EXIST %obj%\LaserDemo.c @MOVE /Y %obj%\LaserDemo.c
%bin%\sdcc -mz80 --code-loc 26000 --data-loc 0xF800 --no-std-crt0 --opt-code-size --funsigned-char --disable-warning 126 -I "." -I %libs% -L %libs%/z80 LaserDemo.c Basic.lib Laser.lib

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\Hex2bin LaserDemo.ihx
REM Bin\stripbin LaserDemo.bin

@REM Link the target to TR-DOS format
@REM ================================
REM WARNING! bin2trd is a MS-DOS program, must use a short filename
@DEL /Q LASERD~1.TRD
%bin%\bin2trd.exe LaserD~1.trl
@MOVE /Y LASERD~1.TRD ../LaserDemo.trd

@REM ======================================================================
@ECHO Now you can run the image "LaserDemo.trd" in your favourite emulator
@REM ======================================================================

@PAUSE

@REM Compile LaserDemo.c
@REM ===================

@SET Bin=..\Bin
@SET Lib=..\Lib

@CD ..\Lib
@IF NOT EXIST Rsrc.rel %Bin%\sdcc -mz80 --opt-code-size --no-std-crt0 -I ..\Obj Rsrc.c
@CD ..\Obj

%bin%\sdcc -mz80 --code-loc 26000 --data-loc 0xF800 --no-std-crt0 --opt-code-size --funsigned-char --disable-warning 126 -I "." -I %Lib% -L %Lib%/z80 LaserDemo.c ..\Lib\Rsrc.rel Basic.lib Laser.lib
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
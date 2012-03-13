@REM Prepare the Basic from Ofront
@REM =============================
@COPY /Y /B Libs\Basic.h Basic.h
@COPY /Y /B Libs\Laser.h Laser.h
@IF EXIST Basic.c DEL /Q Basic.c
@IF EXIST Laser.c DEL /Q Laser.c

@REM Compile HelloWorld.c
@REM ====================
Bin\sdcc -mz80 --code-loc 26000 --data-loc 0xF800 --no-std-crt0 --opt-code-size --funsigned-char -L Libs/z80 LaserDemo.c Basic.lib Laser.lib

@REM Convert Intel hex format to binary
@REM ==================================
@REM Bin\makebin -p LaserDemo.ihx LaserDemo.bin
Bin\Hex2bin LaserDemo.ihx
REM Bin\stripbin LaserDemo.bin

@REM Link the target to TR-DOS format
@REM ================================
REM WARNING! bin2trd is a MS-DOS program, must use a short filename
@DEL /Q LASERD~1.TRD
Bin\bin2trd.exe LaserD~1.trl
@MOVE /Y LASERD~1.TRD LaserDemo.trd

@REM ======================================================================
@ECHO Now you can run the image "LaserDemo.trd" in your favourite emulator
@REM ======================================================================

@PAUSE

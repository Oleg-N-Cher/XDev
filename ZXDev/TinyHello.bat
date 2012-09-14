@REM Using Libs/Basic.h
@REM ===================
@IF NOT EXIST Basic.h COPY /Y /B Libs\Basic.h Basic.h
@REM IF EXIST Basic.c DEL /Q Basic.c 

@REM Compile TinyHello.c
@REM ====================
@IF EXIST ..\Ofront\Obj\TinyHello.c COPY /Y /B ..\Ofront\Obj\TinyHello.c
Bin\sdcc -mz80 --code-loc 26000 --data-loc 0xF800 --no-std-crt0 --opt-code-size --funsigned-char -L Libs/z80 TinyHello.c Basic.lib

@REM Convert Intel hex format to binary
@REM ==================================
@REM Bin\makebin -p TinyHello.ihx TinyHello.bin
Bin\Hex2bin TinyHello.ihx
REM Bin\stripbin TinyHello.bin

@REM Link the target to TR-DOS format
@REM ================================
REM WARNING! bin2trd is a MS-DOS program, must use a short filename
@DEL /Q TINYHE~1.TRD
Bin\bin2trd.exe TinyHe~1.trl
@MOVE /Y TINYHE~1.TRD TinyHello.trd

@REM ======================================================================
@ECHO Now you can run the image "TinyHello.trd" in your favourite emulator.
@REM ======================================================================

@PAUSE

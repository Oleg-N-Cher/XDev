@REM Prepare the Basic from Ofront
@REM =============================
@COPY /Y /B Libs\Basic.h Basic.h
@IF EXIST Basic.c DEL /Q Basic.c

@REM Compile HelloWorld.c
@REM ====================
Bin\sdcc -mz80 --code-loc 26000 --data-loc 0xF800 --no-std-crt0 --opt-code-size --funsigned-char -L Libs/z80 HelloWorld.c Basic.lib

@REM Convert Intel hex format to binary
@REM ==================================
@REM Bin\makebin -p HelloWorld.ihx HelloWorld.bin
Bin\Hex2bin HelloWorld.ihx
REM Bin\stripbin HelloWorld.bin

@REM Link the target to TR-DOS format
@REM ================================
REM WARNING! bin2trd is a MS-DOS program, must use a short filename
@DEL /Q HELLOW~1.TRD
Bin\bin2trd.exe HelloW~1.trl
@MOVE /Y HELLOW~1.TRD HelloWorld.trd

@REM ======================================================================
@ECHO Now you can run the image "HelloWorld.trd" in your favourite emulator
@REM ======================================================================

@PAUSE

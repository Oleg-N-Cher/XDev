@REM Compile Flower.c
@REM ================

@SET CodeAddr=38000
@SET DataAddr=45000
@SET StartCode=
@SET bin=..\Bin
@SET lib=..\Lib

%bin%\sdcc -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --opt-code-size --funsigned-char --disable-warning 126 -I "." -I %lib% -L %lib%/z80 Flower.c Graph.lib XDev.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\hex2bin Flower.ihx

@REM %bin%\stripbin Flower.bin

@REM Link the target to TAP format
@REM =============================
@DEL /Q Flower.tap
%bin%\bin2data.exe -rem -org %CodeAddr% Flower.bin ..\Flower.tap Flower

@REM ======================================================================
@ECHO Now you can run the image "Flower.tap" in your favourite emulator
@REM ======================================================================

START ..\Flower.tap
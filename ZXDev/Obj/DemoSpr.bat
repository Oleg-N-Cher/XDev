@SET CodeAddr=45056
@SET DataAddr=63488
@SET bin=..\Bin
@SET lib=..\Lib

%bin%\sdcc DemoSpr.c -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --no-std-crt0 --opt-code-size --funsigned-char -I "." -I %lib% -L %lib%/z80 Basic.lib libspr.lib --disable-warning 59 --disable-warning 85
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\hex2bin DemoSpr.ihx
%bin%\stripbin DemoSpr.bin

@REM Link the target to TAP format
@REM =============================
@DEL /Q DemoSpr.tap
%bin%\bin2data.exe -rem -org %CodeAddr% DemoSpr.bin ..\DemoSpr.tap DemoSpr

@REM ======================================================================
@ECHO Now you can run the image "DemoSpr.tap" in your favourite emulator.
@REM ======================================================================

START ..\DemoSpr.tap
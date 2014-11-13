@SET CodeAddr=46808
@SET DataAddr=63488
@SET bin=..\Bin
@SET lib=..\Lib

%bin%\sdcc TestPT3IM2.c -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --opt-code-size --funsigned-char -I "TestPT3IM2" -I %lib% -L %lib%/z80 Basic.lib PT3x0A.lib Best40.lib --disable-warning 59 --disable-warning 85
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\hex2bin TestPT3IM2.ihx

@REM Link the target to TAP format
@REM =============================
@DEL /Q TestPT3IM2.tap
%bin%\bin2data.exe -rem -org %CodeAddr% TestPT3IM2.bin ..\TestPT3IM2.tap TestPT3IM2

START ..\TestPT3IM2.tap

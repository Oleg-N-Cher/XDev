@SET CodeAddr=46846
@SET DataAddr=63488
@SET bin=..\Bin
@SET lib=..\Lib

%bin%\sdcc TestPT3.c -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --opt-code-size --funsigned-char -I "." -I %lib% -L %lib%/z80 Basic.lib PT3x0A.lib --disable-warning 59 --disable-warning 85
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\hex2bin TestPT3.ihx

@REM Link the target to TAP format
@REM =============================
@DEL /Q TestPT3.tap
%bin%\bin2data.exe -rem -org %CodeAddr% TestPT3.bin ..\TestPT3.tap TestPT3

START ..\TestPT3.tap

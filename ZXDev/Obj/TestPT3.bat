@SET CodeAddr=46854
@SET DataAddr=63488
@SET bin=..\Bin
@SET lib=..\Lib

%bin%\sdcc TestPT3.c -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --opt-code-size -I %lib% -I %lib%\C -I %lib%\Obj -L %lib% --disable-warning 59 --disable-warning 85 --disable-warning 126 Basic.lib PT3x0A.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\hex2bin TestPT3.ihx

@REM Link the target to TAP format
@REM =============================
%bin%\bin2data.exe -rem -org %CodeAddr% TestPT3.bin ..\TestPT3.tap TestPT3

START ..\TestPT3.tap

@SET Name=Flower
@SET CodeAddr=38000
@SET DataAddr=45000
@SET bin=..\Bin
@SET lib=..\Lib

%bin%\sdcc %Name%.c -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --opt-code-size --disable-warning 126 -I %lib% -I %lib%\C -I %lib%\Obj -L %lib% --disable-warning 59 --disable-warning 85 Graph.lib XDev.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\hex2bin %Name%.ihx

@REM %bin%\stripbin %Name%.bin

@REM Link the target to TAP format
@REM =============================
%bin%\bin2data.exe -rem -org %CodeAddr% %Name%.bin ..\%Name%.tap %Name%

START ..\%Name%.tap

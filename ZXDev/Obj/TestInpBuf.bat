@SET Mod=TestInpBuf
@SET Bin=..\Bin
@SET Lib=..\Lib
@SET CodeAddr=50000
@SET DataAddr=52500

%Bin%\sdcc %Mod%.c -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --reserve-regs-iy --opt-code-size --funsigned-char --disable-warning 59 --disable-warning 85 --disable-warning 126 -I %Mod% -I %Lib%\C -I %Lib%\Obj -L %Lib% Basic.lib XDev.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%Bin%\hex2bin %Mod%.ihx
%Bin%\bin2data.exe -rem -org %CodeAddr% %Mod%.bin ..\..\%Mod%.tap %Mod%
@CD ..
@START ..\%Mod%.tap

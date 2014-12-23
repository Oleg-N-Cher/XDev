@SET Mod=IM0
@SET Bin=..\Bin
@SET Lib=..\Lib
@SET CodeAddr=26000
@SET DataAddr=60000

%Bin%\sdcc %Mod%.c -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --reserve-regs-iy --opt-code-size --funsigned-char --disable-warning 126 -I %Mod% -I %Lib%\C -I %Lib%\Obj -L %Lib% --disable-warning 59 --disable-warning 85 Basic.lib XDev.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%Bin%\hex2bin %Mod%.ihx
%Bin%\bin2data.exe -rem -org %CodeAddr% %Mod%.bin ..\%Mod%.tap %Mod%
@START ..\%Mod%.tap

@SET Mod=TestInPar
@SET Bin=..\..\Bin
@SET Lib=..\..\Lib
@SET CodeAddr=50000
@SET DataAddr=52500

@IF EXIST %Mod%.c @MOVE /Y %Mod%.c %Mod%
@CD %Mod%
%Bin%\sdasz80 -o heap.rel heap.s
@IF errorlevel 1 PAUSE
%Bin%\sdcc %Mod%.c -mz80 heap.rel --code-loc %CodeAddr% --data-loc %DataAddr% --reserve-regs-iy --opt-code-size --funsigned-char --disable-warning 85 -I "." -I %Lib% -L %Lib%/z80 Basic.lib XDev.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%Bin%\hex2bin %Mod%.ihx
%Bin%\bin2data.exe -rem -org %CodeAddr% %Mod%.bin ..\..\%Mod%.tap %Mod%
@CD ..
@START ..\%Mod%.tap

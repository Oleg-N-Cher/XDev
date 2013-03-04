@SET CodeAddr=45056
@SET DataAddr=63488
@SET Bin=..\Bin
@SET Lib=..\Lib
@SET Obj=..\..\Ofront\Obj

@IF EXIST %Obj%\%1.h @DEL %Obj%\%1.h
@IF EXIST %Obj%\%1.sym @DEL %Obj%\%1.sym
@IF EXIST %Obj%\%1.c @MOVE /Y %Obj%\%1.c
%Bin%\sdcc %1.c -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --no-std-crt0 --opt-code-size -I "." -I %Lib% XDev.lib Basic.lib Laser.lib
@IF errorlevel 1 PAUSE

%Bin%\hex2bin %1.ihx
%Bin%\bin2data.exe -rem -org %CodeAddr% %1.bin ..\%1.tap %1
@START ..\%1.tap
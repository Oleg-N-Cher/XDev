@SET CodeAddr=45056
@SET DataAddr=63488
@SET sdcc=..\Bin\sdcc -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --opt-code-size --disable-warning 59 --disable-warning 85 --disable-warning 126 -I ..\Lib\C -I ..\Lib\Obj -L ..\Lib XDev.lib Graph.lib Basic.lib Laser.lib Mega.lib Best40.lib trdos.lib libspr.lib NewSupercode.lib MiraMod2.lib PT3x0A.lib Wham.lib ZX7.lib Gfx.lib

@IF EXIST %1 GOTO config

%sdcc% %1.c -I ..\Lib
@GOTO link

:config

%sdcc% %1.c -I %1

:link

@IF errorlevel 1 PAUSE
..\Bin\hex2bin %1.ihx
::..\Bin\bin2data.exe -rem -org %CodeAddr% %1.bin ..\%1.tap %1
..\Bin\bin2tap -c 24999 -a %CodeAddr% -r %CodeAddr% -b -o ..\%1.tap %1.bin
@START ..\%1.tap

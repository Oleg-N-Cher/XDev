@SET CodeAddr=0x4020
@SET DataAddr=0xc000
@SET Bin=..\Bin
@SET Lib=..\Lib

@IF EXIST %1 GOTO config

%Bin%\sdcc %1.c -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --opt-code-size --oldralloc --disable-warning 85 -I "." -I %Lib% Basic.lib Graphic.lib XDev.lib
@GOTO link

:config
%Bin%\sdcc %1.c -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --opt-code-size --oldralloc --disable-warning 85 -I %1 -I %Lib% Basic.lib Graphic.lib XDev.lib

:link
@IF errorlevel 1 PAUSE
%Bin%\hex2bin %1.ihx

@REM * binary manipulation: %1.ihx -> %1.rom ...
%Bin%\makebin -s 65536 < %1.ihx >64k.mem
@REM "split" is a GNU utility to break a file into parts.
@REM We only need the 2nd quarter of 64k.mem.
%Bin%\split -b 16384 64k.mem 16kmem.
@move 16kmem.ab ..\%1.rom
@START ..\%1.rom
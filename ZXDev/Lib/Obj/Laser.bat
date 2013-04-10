@REM Compile the library Laser
@REM =========================
@SET Bin=..\Bin

@CD ..
@IF EXIST Laser.lib DEL Laser.lib
..\Bin\sdcc -c -mz80 --opt-code-size Rsrc.c
@IF errorlevel 1 PAUSE
%Bin%\sdcc -c -mz80 --opt-code-size --disable-warning 85 Laser.c Rsrc.rel
@IF errorlevel 1 PAUSE
%Bin%\sdar -rc Laser.lib Laser.rel Rsrc.rel
@MOVE /Y Laser.lib z80/Laser.lib
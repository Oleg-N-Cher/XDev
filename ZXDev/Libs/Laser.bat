@REM Compile the library Basic
@REM =========================
@SET bin=..\Bin
@SET obj=..\Ofront\Obj

CALL Rsrc.bat
%bin%\sdcc -mz80 --no-std-crt0 --opt-code-size --disable-warning 85 -L z80 Laser.c Rsrc.rel
%bin%\sdar -rc Laser.lib Laser.rel Rsrc.rel
@MOVE /Y Laser.lib z80/Laser.lib

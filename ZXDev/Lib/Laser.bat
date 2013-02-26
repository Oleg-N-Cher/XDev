@REM Compile the library Laser
@REM =========================
@SET bin=..\Bin
@SET obj=..\..\Ofront\Obj

@IF EXIST %obj%\Laser.h @DEL %obj%\Laser.h
@IF EXIST %obj%\Laser.c @DEL %obj%\Laser.c

CALL Rsrc.bat
%bin%\sdcc -mz80 --no-std-crt0 --opt-code-size --disable-warning 85 -L z80 Laser.c Rsrc.rel
%bin%\sdar -rc Laser.lib Laser.rel Rsrc.rel
@MOVE /Y Laser.lib z80/Laser.lib

@PAUSE

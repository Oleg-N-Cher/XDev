CALL Rsrc.bat
..\Bin\sdcc -mz80 --no-std-crt0 --opt-code-size --disable-warning 85 -L z80 Laser.c Rsrc.rel
..\Bin\sdcclib Laser.lib Laser.rel Rsrc.rel
@MOVE /Y Laser.lib z80/Laser.lib

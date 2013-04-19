@CD ..
..\Bin\sdcc -c %1.c -mz80 --opt-code-size --disable-warning 59 --disable-warning 85 -I "." -I Obj -L z80
@IF errorlevel 1 PAUSE
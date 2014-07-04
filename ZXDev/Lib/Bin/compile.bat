@CD ..
@IF EXIST %1.c GOTO c_lib

:o_lib_obj
..\Bin\sdcc Obj\%1.c -mz80 --opt-code-size --no-std-crt0 --disable-warning 59 --disable-warning 85 -I "." -I include -I Obj -L z80 XDev.lib
@IF NOT errorlevel 1 GOTO exit
..\..\Bin\smartlib Obj\%1.c -nocut -noinit
..\Bin\sdcc Obj\%1.c -mz80 --opt-code-size --no-std-crt0 --disable-warning 59 --disable-warning 85 -I "." -I include -I Obj -L z80 XDev.lib
@GOTO exit

:c_lib
..\Bin\sdcc %1.c -mz80 --opt-code-size --no-std-crt0 --disable-warning 59 --disable-warning 85 -I "." -I include -I Obj -L z80 XDev.lib

:exit

@IF errorlevel 1 PAUSE
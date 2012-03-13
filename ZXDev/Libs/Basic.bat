..\Bin\sdcc -mz80 --no-std-crt0 --opt-code-size --funsigned-char --disable-warning 59 --disable-warning 85 -L z80 Basic.c      
..\Bin\sdcclib Basic.lib Basic.rel
@MOVE /Y Basic.lib z80/Basic.lib

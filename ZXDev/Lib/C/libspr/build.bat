@SET LibSpr=..\z80\libspr.lib
@IF EXIST %LibSpr% @DEL %LibSpr%

..\..\Bin\sdasz80 -o spr0_s.rel spr0_s.s
@IF errorlevel 1 PAUSE
..\..\Bin\sdasz80 -o spr0_out0_s.rel spr0_out0_s.s
@IF errorlevel 1 PAUSE
..\..\Bin\sdcc -c spr0_var_1.c -mz80 -I "." --disable-warning 85
@IF errorlevel 1 PAUSE
..\..\Bin\sdcc -c spr0_var_2.c -mz80 -I "." --disable-warning 85
@IF errorlevel 1 PAUSE
..\..\Bin\sdar -rc %LibSpr% spr0_s.rel spr0_out0_s.rel spr0_var_1.rel spr0_var_2.rel
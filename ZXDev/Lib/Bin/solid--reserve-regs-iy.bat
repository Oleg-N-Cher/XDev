@REM args:
@REM   LibName ModName

@SET sdcc=..\..\Bin\sdcc -mz80 --reserve-regs-iy --opt-code-size --disable-warning 59 --disable-warning 85 -I "." -I ".." -I ..\C
@SET smartlib=..\..\..\Bin\smartlib
@IF EXIST ..\C\%2.c GOTO c_lib

:o_lib

%sdcc% -c %2.c
@GOTO done

:c_lib

@IF EXIST ..\C\%2.oh DEL %2.oh
@IF EXIST ..\C\%2.c DEL %2.c
%sdcc% -c ..\C\%2.c

:done

@IF errorlevel 1 PAUSE
@..\..\Bin\sdar -rc %1 %2.rel
@DEL %2.rel

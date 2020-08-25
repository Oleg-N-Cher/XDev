@SET sdcc=..\..\Bin\sdcc -mz80 --opt-code-size --disable-warning 59 --disable-warning 85 -I "." -I ".." -I ..\C
@SET smartlib=..\..\..\Bin\smartlib
@IF EXIST ..\C\%1.c GOTO c_lib

:o_lib_obj

%sdcc% -c %1.c
@IF NOT errorlevel 1 GOTO exit
%smartlib% %1.c -nocut -noinit
%sdcc% -c %1.c
@GOTO exit

:c_lib

@IF EXIST ..\C\%2.h DEL %2.h
@IF EXIST ..\C\%2.c DEL %2.c
%sdcc% -c ..\C\%1.c

:exit
@IF errorlevel 1 PAUSE

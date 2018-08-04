@SET sdcc=..\..\Bin\sdcc -mz80 --opt-code-size --disable-warning 59 --disable-warning 85 -I "." -I ".." -I ..\C
@SET smartlib=..\..\..\Bin\smartlib

@IF EXIST ..\%1.lib DEL ..\%1.lib
@IF EXIST ..\C\%1.c GOTO c_lib

:o_lib_obj

%smartlib% %1.c
@GOTO compile

:c_lib

@IF EXIST %1.h DEL %1.h
@IF EXIST %1.c DEL %1.c
%smartlib% ..\C\%1.c

:compile

@FOR %%i IN (%1_???.c) DO (
  %sdcc% -c %%i
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%1_???.rel) DO ..\..\Bin\sdar -rc ..\%1.lib %%i
@..\Bin\clear

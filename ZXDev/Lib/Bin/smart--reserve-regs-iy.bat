@REM args:
@REM   LibName ModName [PartName] [-noinit] [-nocut]

@SET sdcc=..\..\Bin\sdcc -mz80 --reserve-regs-iy --opt-code-size --disable-warning 59 --disable-warning 85 -I "." -I ".." -I ..\C
@SET smartlib=..\..\..\Bin\smartlib
@IF EXIST ..\C\%2.c GOTO c_lib

:o_lib

%smartlib% %2.c %3 %4 %5
@GOTO compile

:c_lib

@IF EXIST %2.h DEL %2.h
@IF EXIST %2.c DEL %2.c
%smartlib% ..\C\%2.c %3 %4 %5

:compile

@FOR %%i IN (%2_???.c) DO (
  %sdcc% -c %%i
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%2_???.rel) DO ..\..\Bin\sdar -rc %1 %%i
@::..\Bin\clear

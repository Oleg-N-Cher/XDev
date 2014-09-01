@REM args:
@REM   LibName ModName [PartName] [-noinit] [-nocut]
@SET RootBin=..\..\Bin

@IF EXIST %2.c GOTO clib
:olib
@COPY Obj\%2.h
%RootBin%\smartlib Obj\%2.c %3 %4 %5
@GOTO compile
:clib
%RootBin%\smartlib %2.c %3 %4 %5
:compile
@FOR %%i IN (%2_???.c) DO (
  ..\Bin\sdcc -c %%i -mz80 --opt-code-size --disable-warning 59 --disable-warning 85 -I "." -I include -I Obj
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%2_???.rel) DO ..\Bin\sdar -rc %1 %%i
@CALL Bin\clear
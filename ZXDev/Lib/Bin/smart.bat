@REM args:
@REM   LibName ModName [PartName] [-noinit] [-nocut]
@CD ..
@SET RootBin=..\..\Bin
@COPY Obj\%2.h

%RootBin%\smartlib Obj\%2.c %3 %4 %5
@FOR %%i IN (%2_0??.c) DO (
  ..\Bin\sdcc -c %%i -mz80 --opt-code-size --disable-warning 59 --disable-warning 85 -I "." -I include -I Obj
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%2_0??.rel) DO ..\Bin\sdar -rc %1 %%i
@CALL Bin\clear
@CD Obj
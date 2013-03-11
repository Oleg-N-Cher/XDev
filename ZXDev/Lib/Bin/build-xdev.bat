@CD ..
@SET RootBin=..\..\Bin
@REM ..\Bin\sdcc -c %1.c -mz80 --opt-code-size --disable-warning 59 --disable-warning 85 -I "."
@REM @IF errorlevel 1 PAUSE

%RootBin%\smartlib %1.c
@FOR %%i IN (%1_0??.c) DO (
  ..\Bin\sdcc -c %%i -mz80 --opt-code-size --disable-warning 59 --disable-warning 85 -I "."
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%1_0??.rel) DO ..\Bin\sdar -rc XDev.lib %%i
@CALL Bin\clear
@CD Obj
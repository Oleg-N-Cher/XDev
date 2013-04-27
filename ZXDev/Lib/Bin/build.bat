@CD ..
@SET RootBin=..\..\Bin
@REM ..\Bin\sdcc -c %1.c -mz80 --opt-code-size --disable-warning 59 --disable-warning 85 -I "."
@REM @IF errorlevel 1 PAUSE

@IF EXIST %1.lib DEL %1.lib
%RootBin%\smartlib %1.c
@FOR %%i IN (%1_0??.c) DO (
  ..\Bin\sdcc -c %%i -mz80 --opt-code-size --disable-warning 59 --disable-warning 85 -I "." -I Obj
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%1_0??.rel) DO ..\Bin\sdar -rc %1.lib %%i
@MOVE /Y %1.lib z80/%1.lib
@Bin\clear
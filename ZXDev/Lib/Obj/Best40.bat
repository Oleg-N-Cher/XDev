@CD ..
@SET RootBin=..\..\Bin

@IF EXIST Best40.lib DEL Best40.lib

%RootBin%\smartlib Best40.c
@FOR %%i IN (Best40_0??.c) DO (
  ..\Bin\sdcc -c %%i -mz80 --opt-code-size --disable-warning 59 --disable-warning 85 -I Obj
  @IF errorlevel 1 PAUSE
)

@FOR %%i IN (Best40_0??.rel) DO ..\Bin\sdar -rc Best40.lib %%i
@MOVE /Y %1.lib z80/%1.lib
@MOVE /Y Best40.lib z80/Best40.lib
@Bin\clear

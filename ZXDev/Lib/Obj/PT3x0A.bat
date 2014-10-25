@CD ..
@SET RootBin=..\..\Bin

@IF EXIST z80\PT3x0A.lib DEL z80\PT3x0A.lib
@IF EXIST Obj\PT3x0A.h DEL Obj\PT3x0A.h
@IF EXIST Obj\PT3x0A.c DEL Obj\PT3x0A.c

%RootBin%\smartlib PT3x0A.c
@FOR %%i IN (PT3x0A_0??.c) DO (
  ..\Bin\sdcc -c %%i -mz80 --opt-code-size --disable-warning 59 --disable-warning 85 -I Obj
  @IF errorlevel 1 PAUSE
)

@FOR %%i IN (PT3x0A_0??.rel) DO ..\Bin\sdar -rc PT3x0A.lib %%i
@MOVE /Y PT3x0A.lib z80\PT3x0A.lib
@Bin\clear

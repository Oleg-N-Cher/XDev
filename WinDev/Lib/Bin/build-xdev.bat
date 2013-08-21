@CD ..
@SET RootBin=..\..\Bin
@SET tcc=..\Bin\tcc\tcc.exe

%RootBin%\smartlib %1.c
@FOR %%i IN (%1_0??.c) DO (
  %tcc% -c %%i -I "." -I Obj
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%1_0??.o) DO ..\Bin\ar -rc WinDev.a %%i
@CALL Bin\clear
@CD Obj

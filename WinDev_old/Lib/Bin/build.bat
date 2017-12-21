@SET RootBin=..\..\..\Bin
@SET PATH=..\..\Bin\MinGW\bin
@SET gcc=gcc.exe -Os -fno-exceptions -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections

@IF EXIST ..\%1.a DEL ..\%1.a
%RootBin%\smartlib %1.c
@FOR %%i IN (%1_0??.c) DO (
  %gcc% -c %%i -I ".." -I ..\C
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%1_0??.o) DO ar.exe -rc ..\%1.a %%i
@..\Bin\clean

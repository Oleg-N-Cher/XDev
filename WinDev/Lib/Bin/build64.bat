@SET Name=%1
@SET RootBin=..\..\..\Bin
@SET PATH=..\..\Bin\MinGW64\bin
@SET gcc=gcc.exe -Os -fno-exceptions -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections

IF EXIST ..\%Name%64.a DEL ..\%Name%64.a
%RootBin%\smartlib %1.c
@FOR %%i IN (%1_0??.c) DO (
  %gcc% -c %%i -I ".." -I ..\C
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%1_0??.o) DO ar.exe -rc ..\%Name%64.a %%i
@..\Bin\clean

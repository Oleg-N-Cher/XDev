@ECHO OFF
CD ..\..
SET PATH=..\BIN\TC201\BIN
SET RootBin=..\..\Bin
IF EXIST %1.lib DEL %1.lib
%RootBin%\smartlib %1.c %1
FOR %%i IN (%1???.c) DO (
  SET Mod=%%i
  START vDosPlus.exe /set frame=on;window=50;autoexec=Lib\Bin\bu.bat
)
FOR %%i IN (%1???.o) DO TLIB /C %1 +%%i
PAUSE
Bin\clear.bat

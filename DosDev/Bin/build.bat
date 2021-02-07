@ECHO OFF
IF EXIST "%ProgramFiles(x86)%" GOTO vDos

SET PATH=..\BIN\TC201\BIN
SET Lib=..\Lib
tcc.exe -1 -O -d -f87 -Z -I..\BIN\TC201\INCLUDE -L..\BIN\TC201\LIB -IOBJ -I%Lib% %Lib%\XDEV.LIB %1.c
IF errorlevel 1 PAUSE
IF EXIST %1.exe MOVE %1.exe ..
CLS
..\%1.exe
PAUSE
EXIT

:vDos

CD ..
SET Mod=%1
START vDosPlus.exe /set frame=on;window=50;autoexec=Bin\bu.bat

@ECHO OFF
IF EXIST "%ProgramFiles(x86)%" GOTO vDos

SET PATH=..\BIN\TC201\BIN
tcc.exe -1 -O -d -f87 -Z -I..\BIN\TC201\INCLUDE -IOBJ -L..\BIN\TC201\LIB -c %1.c
IF errorlevel 1 PAUSE
EXIT

:vDos

CD ..\..
SET Mod=%1
START vDosPlus.exe /set frame=on;window=50;autoexec=Lib\Bin\cc.bat

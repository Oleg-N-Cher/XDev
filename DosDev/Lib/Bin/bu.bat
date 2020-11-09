@ECHO OFF
CLS
CD Lib\Obj
SET PATH=..\..\BIN\TC201\BIN
SET Mod=%%Mod%%
tcc.exe -1 -O -d -f87 -Z -I..\..\BIN\TC201\INCLUDE -I..\C -I.. -L..\..\BIN\TC201\LIB -c %Mod%
IF errorlevel 1 PAUSE
EXIT

@ECHO OFF
CD Lib\Obj
SET PATH=..\..\BIN\TC201\BIN
SET Mod=%%Mod%%
TLIB.exe /C ..\DOSDEV +%Mod%
EXIT

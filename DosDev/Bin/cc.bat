@ECHO OFF
CLS
CD Obj
SET PATH=..\BIN\TC201\BIN
SET Lib=..\Lib
SET Mod=%%Mod%%
tcc.exe -1 -O -d -f87 -Z -I..\BIN\TC201\INCLUDE -I..\LIB\C -IOBJ -L..\BIN\TC201\LIB -I%Lib% -c %Mod%.c
IF errorlevel 1 PAUSE
EXIT

@ECHO OFF
CLS
CD Obj
SET PATH=..\BIN\TC201\BIN
SET Lib=..\Lib
SET Mod=%%Mod%%
tcc.exe -1 -O -d -f87 -Z -I..\BIN\TC201\INCLUDE -I..\LIB\C -L..\BIN\TC201\LIB -IOBJ -I%Lib% %Lib%\XDEV.LIB %Mod%.c
IF errorlevel 1 PAUSE
IF EXIST %Mod%.exe MOVE %Mod%.exe ..\%Mod%.exe
CLS
REM ..\%Mod%.exe
REM PAUSE
EXIT

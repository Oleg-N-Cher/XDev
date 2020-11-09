@ECHO OFF
CLS
CD Lib\Obj
SET PATH=..\..\BIN\TC201\BIN
SET Mod=%%Mod%%

IF EXIST ..\C\%Mod%.c GOTO c_lib

:o_lib_obj

tcc.exe -1 -O -d -f87 -Z -I..\..\BIN\TC201\INCLUDE -L..\..\BIN\TC201\LIB -I.. -c %Mod%.c
GOTO exit

:c_lib

IF EXIST ..\C\%Mod%.oh DEL %Mod%.oh >NUL
IF EXIST ..\C\%Mod%.c DEL %Mod%.c >NUL
tcc.exe -1 -O -d -f87 -Z -I..\..\BIN\TC201\INCLUDE -I..\C -L..\..\BIN\TC201\LIB -I.. -c ..\C\%Mod%.c

:exit
IF errorlevel 1 PAUSE
EXIT

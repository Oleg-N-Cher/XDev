@SET sdcc=..\Bin\sdcc -mz80 --no-std-crt0 -I ..\Lib\C -I ..\Lib\Obj --disable-warning 59 --disable-warning 85 --disable-warning 126

@IF EXIST %1 GOTO config

%sdcc% -c %1.c -I ..\Lib
@GOTO exit

:config

%sdcc% -c %1.c -I %1

:exit

@IF errorlevel 1 PAUSE

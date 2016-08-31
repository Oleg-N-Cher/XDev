@SET ZXDev=%XDev%\ZXDev
@IF "%XDev%"=="" SET ZXDev=..

@IF "%MainMod%"=="" SET MainMod=%1

@SET Options=%Options% -mz80 --no-xinit-opt --opt-code-size --disable-warning 59 --disable-warning 85 --disable-warning 126
@SET Include=%Include% -I %ZXDev%\Lib\C -I %ZXDev%\Lib\Obj
@IF "%Clean%"=="" SET Clean=true

@IF EXIST %1.sym MOVE /Y %1.sym %1.osm

@SET SDCC=%ZXDev%\Bin\sdcc.exe %Options% %Include%

@IF EXIST %1 GOTO Config

%SDCC% -c %1.c -I %ZXDev%\Lib
@GOTO Exit

:Config

%SDCC% -c %1.c -I %1

:Exit

@IF errorlevel 1 PAUSE

@IF NOT "%Clean%"=="true" GOTO Done
@DEL *.asm *.lst %1.sym
@IF "%1"=="%MainMod%" DEL %1.h %1.rel %1.osm
@IF NOT "%1"=="%MainMod%" DEL %1.c

:Done

@IF EXIST %1.osm MOVE /Y %1.osm %1.sym

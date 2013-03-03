@SET Bin=..\Bin
@SET Lib=..\Lib
@SET Obj=..\..\Ofront\Obj

@IF EXIST %Obj%\%1.h @DEL %Obj%\HelloWorld.h
@IF EXIST %Obj%\%1.sym @DEL %Obj%\HelloWorld.sym
@IF EXIST %Obj%\%1.c @MOVE /Y %Obj%\%1.c
%Bin%\sdcc -c %1.c -mz80 --opt-code-size -I "." -I %Lib%
@IF errorlevel 1 PAUSE
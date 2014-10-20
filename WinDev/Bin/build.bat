@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc\tcc

@IF EXIST %1 GOTO config

%tcc% %1.c -I "." -I %Lib%\C -I %Lib%\Obj %Lib%\Oak.a %Lib%\XDev.a %Lib%\Kol.a %Bin%\tcc\lib\SDL.def -o ..\%1.exe
@GOTO exit

:config
%tcc% %1.c -I %1 -I %Lib%\C -I %Lib%\Obj %Lib%\Oak.a %Lib%\XDev.a %Lib%\Kol.a %Bin%\tcc\lib\SDL.def -o ..\%1.exe

:exit
@IF errorlevel 1 PAUSE
@CD ..
@CLS
@%1.exe
@PAUSE
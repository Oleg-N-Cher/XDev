@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc\tcc

@IF EXIST %1 GOTO config

%tcc% -c %1.c -I "." -I %Lib%\C -I %Lib%\Obj -I %Lib%
GOTO exit

:config
%tcc% -c %1.c -I %1 -I %Lib%\C -I %Lib%\Obj -I %Lib%

:exit
@IF errorlevel 1 PAUSE
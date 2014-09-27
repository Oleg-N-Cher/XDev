@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc64\tcc

@IF EXIST %1 GOTO config

%tcc% -c %1.c -I "." -I %Lib%\Obj64 -I %Lib%
GOTO exit

:config
%tcc% -c %1.c -I %1 -I %Lib%\Obj64 -I %Lib%

:exit
@IF errorlevel 1 PAUSE
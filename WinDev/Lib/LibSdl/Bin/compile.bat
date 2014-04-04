@SET Bin=..\..\..\Bin
@SET Lib=..\..\..\Lib
@SET tcc=%Bin%\tcc\tcc.exe

%tcc% -c %1.c -I %Lib% -I %Lib%\Obj -I %Bin%\tcc\include\SDL
@IF errorlevel 1 PAUSE
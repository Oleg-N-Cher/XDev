@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc\tcc

%tcc% GrTest.c -D_SDLGUI -I %Lib% -I %Lib%\C -I %Lib%\Obj %Lib%\XDev.a %Bin%\tcc\lib\SDL.def -o ..\GrTest.exe
@IF errorlevel 1 PAUSE

@CD ..
@IF EXIST GrTest.exe START GrTest.exe

@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc64\tcc

%tcc% GrTest.c -D_SDLGUI -I %Lib% -I %Lib%\C -I %Lib%\Obj64 %Lib%\XDev64.a %Bin%\tcc64\lib\SDL.def -o ..\x64\GrTest.exe
@IF errorlevel 1 PAUSE

@CD ..\x64
@IF EXIST GrTest.exe START GrTest.exe

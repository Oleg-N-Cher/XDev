@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc\tcc

%tcc% TestSdl2.c -D_WINGUI -I %Lib% -I %Lib%\C -I %Lib%\Obj %Lib%\XDev.a %Bin%\tcc\lib\SDL2.def -o ..\TestSdl2.exe
@IF errorlevel 1 PAUSE

@CD ..
@IF EXIST TestSdl2.exe START TestSdl2.exe

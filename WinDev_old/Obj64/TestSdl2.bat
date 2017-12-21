@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc64\tcc

%tcc% TestSdl2.c -D_WINGUI -I %Lib% -I %Lib%\C -I %Lib%\Obj64 %Lib%\XDev64.a %Bin%\tcc64\lib\SDL2.def -o ..\x64\TestSdl2.exe
@IF errorlevel 1 PAUSE
@IF EXIST ..\x64\TestSdl2.exe START ..\x64\TestSdl2.exe

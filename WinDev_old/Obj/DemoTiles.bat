@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc\tcc

%tcc% DemoTiles.c -D_WINGUI -I "." -I %Lib% %Lib%\WinDev.a %Lib%\Sdl\SdlLib.a %Bin%\tcc\lib\SDL.def -o DemoTiles.exe
@IF errorlevel 1 PAUSE
@IF EXIST DemoTiles.exe MOVE DemoTiles.exe ..
@START ..\DemoTiles.exe

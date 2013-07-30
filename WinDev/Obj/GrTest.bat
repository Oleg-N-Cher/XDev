@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc\tcc

%tcc% GrTest.c -D_WINGUI -I "." -I %Lib% %Lib%\WinDev.a %Lib%\Sdl\SdlLib.a %Bin%\tcc\lib\SDL.def -o GrTest.exe
@IF errorlevel 1 PAUSE
@IF EXIST GrTest.exe MOVE GrTest.exe ..
@START ..\GrTest.exe

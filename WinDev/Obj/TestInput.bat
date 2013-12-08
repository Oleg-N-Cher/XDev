@SET Mod=TestInput
@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc\tcc

%tcc% %Mod%.c -D_WINGUI -I %Mod% -I %Lib% %Lib%\WinDev.a %Lib%\Sdl\SdlLib.a %Bin%\tcc\lib\SDL.def -o %Mod%.exe
@IF errorlevel 1 PAUSE
@IF EXIST %Mod%.exe MOVE %Mod%.exe ..
@START ..\%Mod%.exe
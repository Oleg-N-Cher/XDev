@SET Mod=TestInput
@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc64\tcc

%tcc% %Mod%.c -D_WINGUI -I %Mod% -I %Lib% %Lib%\WinDev64.a %Lib%\Sdl\SdlLib64.a %Bin%\tcc64\lib\SDL.def -o %Mod%.exe
@IF errorlevel 1 PAUSE
@IF EXIST %Mod%.exe MOVE %Mod%.exe ..\x64
@START ..\x64\%Mod%.exe
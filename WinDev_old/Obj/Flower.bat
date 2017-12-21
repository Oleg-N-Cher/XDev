@SET Name=Flower
@SET Lib=..\Lib
@SET PATH=..\Bin\MinGW\bin
@SET Opt=-nostartfiles %Lib%\C\crt1.c -Wl,-e,__WinMain
@SET Libs=%Lib%\XDev.a ..\Bin\MinGW\lib\libSDL.dll.a

gcc %Name%.c -I %Name% -s -Os -fno-exceptions -fno-asynchronous-unwind-tables -Wl,--gc-sections -Wl,--file-alignment,512 -mwindows -D_SDLGUI -I "." -I %Lib% -I %Lib%\C -I %Lib%\Obj %Libs% %Opt% -o ..\%Name%.exe
@IF errorlevel 1 PAUSE

@START ..\%Name%.exe

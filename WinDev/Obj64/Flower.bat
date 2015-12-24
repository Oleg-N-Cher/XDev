@SET Name=Flower
@SET Lib=..\Lib
@SET PATH=..\Bin\MinGW64\bin
@SET Opt=-nostartfiles %Lib%\C\crt64.c -Wl,-e,__WinMain -D_WIN64
@SET Libs=%Lib%\XDev64.a ..\Bin\MinGW64\lib\libSDL.dll.a

gcc %Name%.c -I %Name% -s -Os -fno-exceptions -fno-asynchronous-unwind-tables -Wl,--gc-sections -Wl,--file-alignment,512 -mwindows -D_SDLGUI -I "." -I %Lib% -I %Lib%\C -I %Lib%\Obj64 %Libs% %Opt% -o ..\x64\%Name%.exe
@IF errorlevel 1 PAUSE

@START ..\x64\%Name%.exe

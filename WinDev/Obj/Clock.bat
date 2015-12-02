@SET Name=Clock
@SET Lib=..\Lib
@SET PATH=..\Bin\MinGW\bin;%PATH%
@SET Opt=-nostartfiles %Lib%\C\crt1w.c -Wl,-e,__WinMain

windres Clock.res -O coff -o ClockRes.o

gcc %Name%.c ClockRes.o -s -Os -fno-exceptions -fno-asynchronous-unwind-tables -Wl,--gc-sections -Wl,--file-alignment,512 -mwindows -D_WINGUI -I "." -I %Lib% -I %Lib%\C -I %Lib%\Obj %Lib%\XDev.a %Opt% -o ..\%Name%.exe
@IF errorlevel 1 PAUSE

@IF EXIST ..\%Name%.exe START ..\%Name%.exe

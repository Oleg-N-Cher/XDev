@SET Bin=..\Bin
@SET Lib=..\Lib

@IF EXIST .djgpp GOTO DJGPP

:MinGW
@SET PATH=..\Bin\MinGW\bin
@SET gcc=gcc.exe -nostartfiles %Lib%\C\crt1.c -Wl,-e,__WinMain -D_WINGUI -DDJGPP
@SET Libs=%Lib%\Rose.a %Lib%\XDev.a %Lib%\Kol.a
@IF EXIST %1 GOTO MinGWcfg

%gcc% %1.c -s -Os -fno-exceptions -fno-asynchronous-unwind-tables -Wl,--gc-sections -Wl,--file-alignment,512 -I "." -I %Lib% -I %Lib%\C -I %Lib%\Obj %Libs% -o ..\%1.exe
@IF errorlevel 1 PAUSE
@GOTO Run

:MinGWcfg
%gcc% %1.c -s -Os -fno-exceptions -fno-asynchronous-unwind-tables -Wl,--gc-sections -Wl,--file-alignment,512 -I %1 -I %Lib% -I %Lib%\C -I %Lib%\Obj %Libs% -o ..\%1.exe
@IF errorlevel 1 PAUSE
@GOTO Run

:DJGPP
@SET DJGPP=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\djgpp.env
@SET PATH=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\bin

gcc.exe -Zcon %1.c -o ..\%1.exe @..\Bin\djgpp.opt
@IF errorlevel 1 PAUSE

:Run
@CD ..
@CLS
@%1.exe
@PAUSE

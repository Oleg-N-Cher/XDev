@SET Bin=..\Bin
@SET Lib=..\Lib

:MinGW64
@SET PATH=..\Bin\MinGW64\bin
@SET gcc=gcc.exe -nostartfiles %Lib%\C\crt1.c -Wl,-e,__WinMain -D_WINGUI -DDJGPP
@SET Libs=%Lib%\Rose64.a %Lib%\XDev64.a %Lib%\Kol64.a
@IF EXIST %1 GOTO MinGW64cfg

%gcc% %1.c -s -Os -fno-exceptions -fno-asynchronous-unwind-tables -Wl,--gc-sections -Wl,--file-alignment,512 -I "." -I %Lib% -I %Lib%\C -I %Lib%\Obj64 %Libs% -o ..\x64\%1.exe
@IF errorlevel 1 PAUSE
@GOTO Run64

:MinGW64cfg
%gcc% %1.c -s -Os -fno-exceptions -fno-asynchronous-unwind-tables -Wl,--gc-sections -Wl,--file-alignment,512 -I %1 -I %Lib% -I %Lib%\C -I %Lib%\Obj64 %Libs% -o ..\x64\%1.exe
@IF errorlevel 1 PAUSE

:Run64
@CD ..\x64 
@CLS
@%1.exe
@PAUSE

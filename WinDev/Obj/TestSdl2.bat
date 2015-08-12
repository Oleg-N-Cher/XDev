@SET Mod=TestSdl2
@SET Bin=..\Bin
@SET Lib=..\Lib

@IF EXIST .djgpp GOTO djgpp

:tcc
@SET tcc=%Bin%\tcc\tcc

%tcc% %Mod%.c -D_WINGUI -I %Lib% -I %Lib%\C -I %Lib%\Obj %Lib%\XDev.a %Bin%\tcc\lib\SDL2.def -o ..\%Mod%.exe
@IF errorlevel 1 PAUSE
@GOTO run

:djgpp
@SET DJGPP=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\djgpp.env
@SET PATH=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\bin;%PATH%

gcc.exe %Mod%.c -D_WINGUI -o ..\%Mod%.exe @..\Bin\djgpp.opt ..\Bin\djgpp\lib\libsdl2.a
@IF errorlevel 1 PAUSE

:run
@IF EXIST %Mod%.exe MOVE %Mod%.exe ..
@START ..\%Mod%.exe 

@SET Mod=MoveWindow
@SET Bin=..\Bin
@SET Lib=..\Lib

@IF EXIST .djgpp GOTO djgpp

:tcc
@SET tcc=%Bin%\tcc\tcc

%tcc% %Mod%.c -D_WINGUI -I "." -I %Lib% -I %Lib%\C -I %Lib%\Obj %Lib%\XDev.a %Bin%\tcc\lib\kernel32.def -o %Mod%.exe
@IF errorlevel 1 PAUSE
@GOTO run

:djgpp
@SET DJGPP=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\djgpp.env
@SET PATH=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\bin;%PATH%

gcc.exe %Mod%.c -o ..\%Mod%.exe @..\Bin\djgpp.opt
@IF errorlevel 1 PAUSE

:run
@IF EXIST %Mod%.exe MOVE %Mod%.exe ..
@START ..\%Mod%.exe

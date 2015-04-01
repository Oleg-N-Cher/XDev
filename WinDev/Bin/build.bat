@SET Bin=..\Bin
@SET Lib=..\Lib

@IF EXIST .djgpp GOTO djgpp

:tcc
@SET tcc=%Bin%\tcc\tcc
@IF EXIST %1 GOTO tcccfg

%tcc% %1.c -I "." -I %Lib% -I %Lib%\C -I %Lib%\Obj %Lib%\Oak.a %Lib%\XDev.a %Lib%\Kol.a %Bin%\tcc\lib\SDL.def %Bin%\tcc\lib\SDL_mixer.def -o ..\%1.exe
@IF errorlevel 1 PAUSE
@GOTO run

:tcccfg
%tcc% %1.c -I %1 -I %Lib% -I %Lib%\C -I %Lib%\Obj %Lib%\Oak.a %Lib%\XDev.a %Lib%\Kol.a %Bin%\tcc\lib\SDL.def %Bin%\tcc\lib\SDL_mixer.def -o ..\%1.exe
@IF errorlevel 1 PAUSE
@GOTO run

:djgpp
@SET DJGPP=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\djgpp.env
@SET PATH=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\bin;%PATH%

gcc.exe -Zcon %1.c -o ..\%1.exe @..\Bin\djgpp.opt
@IF errorlevel 1 PAUSE

:run
@CD ..
@CLS
@%1.exe
@PAUSE

@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc\tcc

%tcc% TestSnd.c -D_SDLGUI -I "." -I %Lib%\C -I %Lib%\Obj %Lib%\XDev.a %Bin%\tcc\lib\SDL.def %Bin%\tcc\lib\SDL_mixer.def -o ..\TestSnd.exe
@IF errorlevel 1 PAUSE
@CD ..
@IF EXIST TestSnd.exe START TestSnd.exe

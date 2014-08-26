@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc\tcc

%tcc% MoveWindow.c -D_WINGUI -I "." -I %Lib% %Lib%\WinDev.a %Bin%\tcc\lib\kernel32.def -o MoveWindow.exe
@IF errorlevel 1 PAUSE

@IF EXIST MoveWindow.exe MOVE MoveWindow.exe ..
@START ..\MoveWindow.exe

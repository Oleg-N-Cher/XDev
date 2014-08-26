@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc64\tcc
@CD ..\Obj64

%tcc% MoveWindow.c -D_WINGUI -I "." -I %Lib% %Lib%\WinDev64.a %Bin%\tcc64\lib\kernel32.def -o MoveWindow.exe
@IF errorlevel 1 PAUSE
@IF EXIST MoveWindow.exe MOVE MoveWindow.exe ..\x64
@START ..\x64\MoveWindow.exe

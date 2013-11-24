@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc64\tcc

@IF EXIST %1 GOTO config

%tcc% %1.c -I "." -I %Lib% %Lib%\WinDev64.a -o %1.exe
GOTO exit

:config
%tcc% %1.c -I %1 -I %Lib% %Lib%\WinDev64.a -o %1.exe

:exit
@IF errorlevel 1 PAUSE
@IF EXIST %1.exe MOVE %1.exe ..\x64
@CLS
@..\x64\%1.exe
@PAUSE
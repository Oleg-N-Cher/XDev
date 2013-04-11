@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc\tcc

%tcc% %1.c -I "." -I %Lib% %Lib%\WinDev.a -o %1.exe
@IF errorlevel 1 PAUSE
@IF EXIST %1.exe MOVE %1.exe ..
@CLS
@..\%1.exe
@PAUSE
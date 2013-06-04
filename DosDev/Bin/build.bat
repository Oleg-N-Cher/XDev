@SET PATH=..\BIN\TC201\BIN
@SET Lib=..\Lib
tcc -1 -O -d -f87 -Z -I..\BIN\TC201\INCLUDE -L..\BIN\TC201\LIB -IOBJ -I%Lib% %Lib%\DOSDEV.LIB %1.c
@IF errorlevel 1 PAUSE
@IF EXIST %1.exe MOVE %1.exe ..
@CLS
@..\%1.exe
@PAUSE
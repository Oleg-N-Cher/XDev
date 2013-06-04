@SET PATH=..\BIN\TC201\BIN
@SET Lib=..\Lib
tcc -1 -O -d -f87 -Z -I..\BIN\TC201\INCLUDE -IOBJ -L..\BIN\TC201\LIB -I%Lib% -c %1.c
@IF errorlevel 1 PAUSE
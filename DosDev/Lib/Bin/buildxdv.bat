@CD ..
@SET path=..\BIN\TC201\BIN
tcc -1 -O -d -f87 -Z -I..\BIN\TC201\INCLUDE -IOBJ -L..\BIN\TC201\LIB -c %1.c
@IF errorlevel 1 PAUSE
TLIB /C dosdev +%1
@CALL Bin\clear
@CD OBJ
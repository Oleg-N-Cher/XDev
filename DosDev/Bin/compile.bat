@FOR /F "tokens=*" %%f IN (..\Bin\config.cfg) DO %%f
@SET PATH=..\BIN\TC201\BIN
@SET Lib=..\Lib
@SET This=%CD:~-3%
@SET DOSBoxOpt=%DOSBoxOpt:~1,-1%
 
IF /%DOSBox%==/ GOTO :nodosbox
%DOSBox% %DOSBoxOpt% -c "mount c .." -c "c:" -c "cd %This%" -c "path %PATH%" -c "tcc -1 -O -d -f87 -Z -I..\BIN\TC201\INCLUDE -IOBJ -L..\BIN\TC201\LIB -I%Lib% -c %1.c" -c "@IF errorlevel 1 PAUSE" -c EXIT
@EXIT
 
:nodosbox
tcc -1 -O -d -f87 -Z -I..\BIN\TC201\INCLUDE -IOBJ -L..\BIN\TC201\LIB -I%Lib% -c %1.c
@IF errorlevel 1 PAUSE
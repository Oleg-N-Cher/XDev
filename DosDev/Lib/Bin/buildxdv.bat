@CD ..
@SET path=..\BIN\TC201\BIN
@SET RootBin=..\..\Bin
%RootBin%\smartlib %1.c %2
@FOR %%i IN (%2???.c) DO (
  tcc -1 -O -d -f87 -Z -I..\BIN\TC201\INCLUDE -IOBJ -L..\BIN\TC201\LIB -c %%i
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%2???.OBJ) DO TLIB /C dosdev +%%i
@CALL Bin\clear
@CD OBJ

@CD ..
@SET path=..\BIN\TC201\BIN
@SET RootBin=..\..\Bin
@IF EXIST %1.lib DEL %1.lib
%RootBin%\smartlib %1.c %1
@FOR %%i IN (%1???.c) DO (
  tcc -1 -O -d -f87 -Z -I..\BIN\TC201\INCLUDE -IOBJ -L..\BIN\TC201\LIB -c %%i
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%1???.o) DO TLIB /C %1 +%%i
@PAUSE
@Bin\clear











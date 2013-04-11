@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc\tcc

%tcc% -c %1.c -I "." -I %Lib%
@IF errorlevel 1 PAUSE
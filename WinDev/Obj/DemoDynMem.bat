@SET Mod=DemoDynMem
@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc\tcc

%tcc% %Mod%.c -I %Mod% -I %Lib% %Lib%\WinDev.a -o %Mod%.exe
@IF errorlevel 1 PAUSE
@IF EXIST %Mod%.exe MOVE %Mod%.exe ..
@CLS
@..\%Mod%.exe
@PAUSE
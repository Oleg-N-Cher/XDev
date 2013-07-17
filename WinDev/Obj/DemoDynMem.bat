@SET Mod=DemoDynMem
@SET Bin=..\..\Bin
@SET Lib=..\..\Lib
@SET tcc=%Bin%\tcc\tcc

@IF EXIST %Mod%.c @MOVE /Y %Mod%.c DemoDynMem
@CD %Mod%
%tcc% %Mod%.c -I "." -I %Lib% %Lib%\WinDev.a -o %Mod%.exe
@IF errorlevel 1 PAUSE
@IF EXIST %Mod%.exe MOVE %Mod%.exe ..\..
@CLS
@..\..\%Mod%.exe
@PAUSE
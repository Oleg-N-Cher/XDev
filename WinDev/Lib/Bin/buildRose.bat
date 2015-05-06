@REM Build the library Oak
@REM =====================

:tcc
@SET Lib=..\Rose.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\solid %Lib% Rose
@CALL ..\Bin\solid %Lib% RoseRedir

:djgpp
@IF NOT EXIST .djgpp GOTO exit
@SET Lib=..\RoseDJGPP.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\soliddjgpp %Lib% Rose
@CALL ..\Bin\soliddjgpp %Lib% RoseRedir

:exit

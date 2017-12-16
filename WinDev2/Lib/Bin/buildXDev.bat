@ECHO OFF
SET Lib=..\XDev.a
IF EXIST %Lib% DEL %Lib%

CALL ..\Bin\cc.bat %Lib% ConsoleStdIO

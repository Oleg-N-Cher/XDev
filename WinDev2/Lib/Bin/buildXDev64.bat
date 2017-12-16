@ECHO OFF
SET Lib=..\XDev64.a
IF EXIST %Lib% DEL %Lib%

CALL ..\Bin\cc64.bat %Lib% ConsoleStdIO

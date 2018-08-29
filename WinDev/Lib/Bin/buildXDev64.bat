@ECHO OFF
SET Lib=..\XDev64.a
IF EXIST %Lib% DEL %Lib%

CALL ..\Bin\cc64.bat %Lib% SYSTEM
CALL ..\Bin\cc64.bat %Lib% Strings
CALL ..\Bin\cc64.bat %Lib% ConsoleStdIO
CALL ..\Bin\cc64.bat %Lib% ConsoleWinAPI
CALL ..\Bin\cc64.bat %Lib% Files
CALL ..\Bin\cc64.bat %Lib% Delphi

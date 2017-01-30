@REM Build the library XDev
@REM ======================
@ECHO OFF

SET Lib=..\XDev.lib

SET HTC=%XDev%\ZXDev3\Bin\HTC\
IF EXIST %Lib% DEL %Lib%

CALL ..\Bin\Smart %Lib% CmdLine CMDL

MOVE /Y %Lib% %HTC%

@SET bin=..\Bin
@IF EXIST WinDev.a @DEL WinDev.a
@CALL %bin%\tccsmart SYSTEM
@CALL %bin%\tccsmart Platform
@CALL %bin%\tccsmart CmdLine
@CALL %bin%\tccsmart Console
@CALL %bin%\tccsmart Strings
@CALL %bin%\tccsmart Files
@CALL %bin%\tccsmart Math
@PAUSE
@CALL %bin%\clear
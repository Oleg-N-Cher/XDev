@SET bin=..\Bin
@IF EXIST Ofront.a @DEL Ofront.a
@CALL %bin%\tccsmart SYSTEM
@CALL %bin%\tccsmart Platform
@CALL %bin%\tccsmart CmdLine
@CALL %bin%\tccsmart Console
@CALL %bin%\tccsmart Strings
@CALL %bin%\tccsmart Files
@PAUSE
@CALL %bin%\clear
@SET bin=..\Bin
@IF EXIST Ofront32.a @DEL Ofront32.a
@CALL %bin%\tcc32smart SYSTEM
@CALL %bin%\tcc32smart Platform
@CALL %bin%\tcc32smart CmdLine
@CALL %bin%\tcc32smart Console
@CALL %bin%\tcc32smart Strings
@CALL %bin%\tcc32smart Files
@PAUSE
@CALL %bin%\clear
@SET bin=..\Bin
@IF EXIST OfrontGCC.a @DEL OfrontGCC.a
@CALL %bin%\gccsmart SYSTEM
@CALL %bin%\gccsmart Platform
@CALL %bin%\gccsmart CmdLine
@CALL %bin%\gccsmart Console
@CALL %bin%\gccsmart Strings
@CALL %bin%\gccsmart Files
@PAUSE
@CALL %bin%\clear
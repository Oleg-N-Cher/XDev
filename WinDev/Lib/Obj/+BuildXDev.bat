@REM Build the library XDev
@REM ======================
@CD ..

:tcc
@SET Lib=x86\XDev.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smart %Lib% SYSTEM
@CALL Bin\smart %Lib% Platform
@CALL Bin\smart %Lib% Strings -noinit
@CALL Bin\smart %Lib% StringsW
@CALL Bin\smart %Lib% CmdLine
@CALL Bin\smart %Lib% CmdLineW
@CALL Bin\smart %Lib% WinCmdLineW
@CALL Bin\smart %Lib% Math
@CALL Bin\smart %Lib% Files
@CALL Bin\smart %Lib% GrScr
@CALL Bin\smart %Lib% GrColors
@CALL Bin\smart %Lib% Console
@CALL Bin\smart %Lib% ConsoleW
@CALL Bin\smart %Lib% GrPixel
@CALL Bin\smart %Lib% GrTiles
@CALL Bin\smart %Lib% GrFonts
@CALL Bin\smart %Lib% GrConsole
@CALL Bin\smart %Lib% Input

:tcc64
@IF NOT EXIST Obj\.tcc64 GOTO exit
@SET Lib=x86-64\XDev64.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smart64 %Lib% SYSTEM
@CALL Bin\smart64 %Lib% Platform
@CALL Bin\smart64 %Lib% Strings -noinit
@CALL Bin\smart64 %Lib% StringsW
@CALL Bin\smart64 %Lib% CmdLine
@CALL Bin\smart64 %Lib% CmdLineW
@CALL Bin\smart64 %Lib% WinCmdLineW
@CALL Bin\smart64 %Lib% Math
@CALL Bin\smart64 %Lib% Files
@CALL Bin\smart64 %Lib% GrScr
@CALL Bin\smart64 %Lib% GrColors
@CALL Bin\smart64 %Lib% Console
@CALL Bin\smart64 %Lib% ConsoleW
@CALL Bin\smart64 %Lib% GrPixel
@CALL Bin\smart64 %Lib% GrTiles
@CALL Bin\smart64 %Lib% GrFonts
@CALL Bin\smart64 %Lib% GrConsole
@CALL Bin\smart64 %Lib% Input

:exit
@CD Obj

@REM Build the library XDev
@REM ======================

:tcc
@SET Lib=..\XDev.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart %Lib% SYSTEM
@CALL ..\Bin\smart %Lib% Platform
@CALL ..\Bin\smart %Lib% Strings -noinit
::@CALL ..\Bin\smart %Lib% StringsW
@CALL ..\Bin\smart %Lib% CmdLine
::@CALL ..\Bin\smart %Lib% CmdLineW
::@CALL ..\Bin\smart %Lib% WinCmdLineW
@CALL ..\Bin\solid %Lib% Debug
@CALL ..\Bin\smart--include %Lib% Math
@CALL ..\Bin\smart %Lib% Files
@CALL ..\Bin\solid %Lib% GrApp
@CALL ..\Bin\smart %Lib% Console
::@CALL ..\Bin\smart %Lib% ConsoleW

@COPY ..\C\GrConfigS.h GrConfig.h
 @CALL ..\Bin\smart %Lib% GrPixel
 @CALL ..\Bin\solid %Lib% GrTiles
 @CALL ..\Bin\smart %Lib% GrFonts
 @CALL ..\Bin\solid %Lib% GrConsole
@DEL GrConfig.h

@CALL ..\Bin\solid %Lib% Input
@CALL ..\Bin\smart %Lib% Timer
@CALL ..\Bin\solid %Lib% Sound
@CALL ..\Bin\smart %Lib% Delphi -noinit

:djgpp
@IF NOT EXIST .djgpp GOTO exit
@SET Lib=..\XDevDJGPP.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smartdjgpp %Lib% SYSTEM
@CALL ..\Bin\smartdjgpp %Lib% Platform
@CALL ..\Bin\smartdjgpp %Lib% Strings -noinit
::@CALL ..\Bin\smartdjgpp %Lib% StringsW
@CALL ..\Bin\smartdjgpp %Lib% CmdLine
::@CALL ..\Bin\smartdjgpp %Lib% CmdLineW
::@CALL ..\Bin\smartdjgpp %Lib% WinCmdLineW
@CALL ..\Bin\soliddjgpp %Lib% Debug
@CALL ..\Bin\smartdjgpp %Lib% Math
@CALL ..\Bin\smartdjgpp %Lib% Files
@CALL ..\Bin\soliddjgpp %Lib% GrApp
@CALL ..\Bin\smartdjgpp %Lib% Console
::@CALL ..\Bin\smartdjgpp %Lib% ConsoleW

@COPY ..\C\GrConfigS.h GrConfig.h
 @CALL ..\Bin\smartdjgpp %Lib% GrPixel
 @CALL ..\Bin\soliddjgpp %Lib% GrTiles
 @CALL ..\Bin\smartdjgpp %Lib% GrFonts
 @CALL ..\Bin\soliddjgpp %Lib% GrConsole
@DEL GrConfig.h

@CALL ..\Bin\soliddjgpp %Lib% Input
@CALL ..\Bin\smartdjgpp %Lib% Timer
@CALL ..\Bin\soliddjgpp %Lib% Sound
@CALL ..\Bin\smartdjgpp %Lib% Delphi -noinit

:exit

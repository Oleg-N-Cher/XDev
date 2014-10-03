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
@CALL ..\Bin\smart %Lib% Math
@CALL ..\Bin\smart %Lib% Files
@CALL ..\Bin\solid %Lib% GrScr
@CALL ..\Bin\smart %Lib% GrColors
@CALL ..\Bin\smart %Lib% Console
::@CALL ..\Bin\smart %Lib% ConsoleW

@COPY ..\C\GrConfigS.h GrConfig.h
 @CALL ..\Bin\smart %Lib% GrPixel
 @CALL ..\Bin\smart %Lib% GrTiles
 @CALL ..\Bin\smart %Lib% GrFonts
 @CALL ..\Bin\smart %Lib% GrConsole
@DEL GrConfig.h

@CALL ..\Bin\smart %Lib% Input

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
@CALL ..\Bin\smartdjgpp %Lib% Math
@CALL ..\Bin\smartdjgpp %Lib% Files
@CALL ..\Bin\soliddjgpp %Lib% GrScr
@CALL ..\Bin\smartdjgpp %Lib% GrColors
@CALL ..\Bin\smartdjgpp %Lib% Console
::@CALL ..\Bin\smartdjgpp %Lib% ConsoleW

@COPY ..\C\GrConfigS.h GrConfig.h
 @CALL ..\Bin\smartdjgpp %Lib% GrPixel
 @CALL ..\Bin\smartdjgpp %Lib% GrTiles
 @CALL ..\Bin\smartdjgpp %Lib% GrFonts
 @CALL ..\Bin\smartdjgpp %Lib% GrConsole
@DEL GrConfig.h

@CALL ..\Bin\smartdjgpp %Lib% Input

:exit

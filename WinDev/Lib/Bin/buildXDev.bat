@REM Build the library XDev
@REM ======================

:tcc
@SET Lib=..\x86\XDev.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart %Lib% SYSTEM
@CALL ..\Bin\smart %Lib% Platform
@CALL ..\Bin\smart %Lib% Strings -noinit
@CALL ..\Bin\smart %Lib% StringsW
@CALL ..\Bin\smart %Lib% CmdLine
@CALL ..\Bin\smart %Lib% CmdLineW
@CALL ..\Bin\smart %Lib% WinCmdLineW
@CALL ..\Bin\smart %Lib% Math
@CALL ..\Bin\smart %Lib% Files
@CALL ..\Bin\solid %Lib% GrScr
@CALL ..\Bin\smart %Lib% GrColors
@CALL ..\Bin\smart %Lib% Console
@CALL ..\Bin\smart %Lib% ConsoleW

@COPY ..\GrConfigS.h GrConfig.h
 @CALL ..\Bin\smart %Lib% GrPixel
 @CALL ..\Bin\smart %Lib% GrTiles
 @CALL ..\Bin\smart %Lib% GrFonts
 @CALL ..\Bin\smart %Lib% GrConsole
@DEL GrConfig.h

@CALL ..\Bin\smart %Lib% Input

:exit

@REM Build the library XDev
@REM ======================

@SET Lib=..\XDev.lib
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart %Lib% SYSTEM
@CALL ..\Bin\smart %Lib% Platform
@CALL ..\Bin\smart %Lib% Strings -noinit
@CALL ..\Bin\smart %Lib% CmdLine -noinit
@CALL ..\Bin\smart %Lib% GrPixel
@CALL ..\Bin\solid %Lib% GrTiles
@CALL ..\Bin\smart %Lib% GrFonts
@CALL ..\Bin\smart %Lib% Timer
@CALL ..\Bin\smart %Lib% Input
@CALL ..\Bin\smart--reserve-regs-iy %Lib% Console
@CALL ..\Bin\smart--reserve-regs-iy %Lib% Math
@CALL ..\Bin\smart %Lib% Control
@CALL ..\Bin\smart %Lib% Sound -noinit
@CALL ..\Bin\solid %Lib% Debug
@CALL ..\Bin\solid %Lib% Tasks

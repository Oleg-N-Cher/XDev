@REM Build the library Oak
@REM =====================

:MinGW
@SET Lib=..\Oak.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart %Lib% Out

:DJGPP
@IF NOT EXIST .djgpp GOTO exit
@SET Lib=..\OakDJGPP.a
@IF EXIST %Lib% DEL %Lib%
::@CALL ..\Bin\soliddjgpp %Lib% AclUtils
::@CALL ..\Bin\soliddjgpp %Lib% AclLib

:exit

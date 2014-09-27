@REM Build the library Oak
@REM =====================

:tcc
@SET Lib=..\x86\Oak.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart %Lib% Out

:djgpp
@SET Lib=..\x86\OakDJGPP.a
@IF EXIST %Lib% DEL %Lib%
::@CALL ..\Bin\soliddjgpp %Lib% AclUtils
::@CALL ..\Bin\soliddjgpp %Lib% AclLib

:exit

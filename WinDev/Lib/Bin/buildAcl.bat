@REM Build the library Acl
@REM =====================

:tcc
@SET Lib=..\Acl.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\solid %Lib% AclUtils
@CALL ..\Bin\solid %Lib% AclLib

:djgpp
@IF NOT EXIST .djgpp GOTO exit
@SET Lib=..\AclDJGPP.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\soliddjgpp %Lib% AclUtils
@CALL ..\Bin\soliddjgpp %Lib% AclLib

:exit

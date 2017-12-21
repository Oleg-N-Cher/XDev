@REM Build the library Acl
@REM =====================

:MinGW64
@SET Lib=..\Acl64.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\solid64 %Lib% AclUtils
@CALL ..\Bin\solid64 %Lib% AclLib

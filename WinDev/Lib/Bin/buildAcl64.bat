@REM Build the library Acl
@REM =====================

:tcc64
@IF NOT EXIST .tcc64 GOTO exit
@SET Lib=..\Acl64.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\solid64 %Lib% AclUtils
@CALL ..\Bin\solid64 %Lib% AclLib

:exit

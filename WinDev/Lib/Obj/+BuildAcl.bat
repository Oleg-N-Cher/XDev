@REM Build the library Acl
@REM =====================
@CD ..

:tcc
@SET Lib=x86\Acl.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\solid %Lib% AclUtils
@CALL Bin\solid %Lib% AclLib

:djgpp
@IF NOT EXIST Obj\.djgpp GOTO tcc64
@SET Lib=x86\AclDJGPP.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smartdjgpp %Lib% AclUtils
@CALL Bin\smartdjgpp %Lib% AclLib

:tcc64
@IF NOT EXIST Obj\.tcc64 GOTO exit
@SET Lib=x86-64\Acl64.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\solid64 %Lib% AclUtils
@CALL Bin\solid64 %Lib% AclLib

:exit
@CD Obj
@REM Build the library XDev
@REM ======================

@IF EXIST ..\DOSDEV.LIB DEL ..\DOSDEV.LIB
@CALL ..\Bin\buildxdv.bat SYSTEM
@REM CALL ..\Bin\buildxdv.bat Platform
@REM CALL ..\Bin\buildxdv.bat Strings
@REM CALL ..\Bin\buildxdv.bat CmdLine
@CALL ..\Bin\buildxdv.bat Console
@REM CALL ..\Bin\buildxdv.bat Math
@REM CALL ..\Bin\buildxdv.bat Files

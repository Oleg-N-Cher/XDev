@REM Build the library XDev
@REM ======================

@IF EXIST ..\DOSDEV.LIB DEL ..\DOSDEV.LIB
@CALL ..\Bin\buildxdv.bat SYSTEM SYST_
@REM CALL ..\Bin\buildxdv.bat Platform PLTFR
@CALL ..\Bin\buildxdv.bat Strings STR_
@CALL ..\Bin\buildxdv.bat CmdLine CMDL_
@CALL ..\Bin\buildxdv.bat Console CONS_
@CALL ..\Bin\buildxdv.bat Math MATH_
@REM CALL ..\Bin\buildxdv.bat Files FILES

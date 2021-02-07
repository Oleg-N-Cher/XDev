@ECHO OFF
REM Build the library XDev

IF EXIST ..\XDEV.LIB DEL ..\XDEV.LIB
CALL ..\Bin\buildxdv.bat SYSTEM SYST_
CALL ..\Bin\buildxdv.bat Platform PLTF_
CALL ..\Bin\buildxdv.bat Strings STR_
CALL ..\Bin\buildxdv.bat CmdLine CMDL_
CALL ..\Bin\buildxdv.bat Console CONS_
CALL ..\Bin\buildxdv.bat Math MATH_
CALL ..\Bin\buildxdv.bat GrApp GRAP_

@REM Build the library XDev
@REM ======================

@IF EXIST ..\XDev.lib ..\DEL XDev.lib
@CALL ..\Bin\build-xdev.bat Console
@CALL ..\Bin\build-xdev.bat GrPixel
@CALL ..\Bin\build-xdev.bat Math
@CALL ..\Bin\build-xdev.bat SYSTEM
@MOVE /Y ..\XDev.lib ..\z80\XDev.lib
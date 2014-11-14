@REM Build the library XDev
@REM ======================

@IF EXIST ..\XDev.lib ..\DEL XDev.lib
@CALL ..\Bin\build-xdev.bat SYSTEM
@CALL ..\Bin\build-xdev.bat Platform
@CALL ..\Bin\build-xdev.bat Strings
@CALL ..\Bin\build-xdev.bat Console
::@CALL ..\Bin\build-xdev.bat GrScr
@CALL ..\Bin\build-xdev.bat GrPixel
@CALL ..\Bin\build-xdev.bat GrTiles
@CALL ..\Bin\build-xdev.bat GrFonts
@CALL ..\Bin\build-xdev.bat Math
@CALL ..\Bin\build-xdev.bat Timer
@CALL ..\Bin\build-xdev.bat Input
@CALL ..\Bin\build-xdev.bat Control
@CALL ..\Bin\build-xdev.bat Sound

@MOVE /Y ..\XDev.lib ..\z80\XDev.lib

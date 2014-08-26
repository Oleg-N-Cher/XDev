@REM Build the library XDev64
@REM ========================

@IF EXIST ..\WinDev64.a DEL ..\WinDev64.a
@CALL ..\Bin\build-xdev64.bat SYSTEM
@CALL ..\Bin\build-xdev64.bat Platform
@CALL ..\Bin\build-xdev64.bat Strings
@CALL ..\Bin\build-xdev64.bat StringsW
@CALL ..\Bin\build-xdev64.bat CmdLine
@CALL ..\Bin\build-xdev64.bat CmdLineW
@CALL ..\Bin\build-xdev64.bat WinCmdLineW
@CALL ..\Bin\build-xdev64.bat Math
@CALL ..\Bin\build-xdev64.bat Files
@CALL ..\Bin\build-xdev64.bat GrScr
@CALL ..\Bin\build-xdev64.bat GrColors
@CALL ..\Bin\build-xdev64.bat Console
@CALL ..\Bin\build-xdev64.bat ConsoleW
@CALL ..\Bin\build-xdev64.bat GrPixel
@CALL ..\Bin\build-xdev64.bat GrTiles
@CALL ..\Bin\build-xdev64.bat GrFonts
@CALL ..\Bin\build-xdev64.bat GrConsole
@CALL ..\Bin\build-xdev64.bat Input
@CALL ..\Bin\build-xdev64.bat Timer

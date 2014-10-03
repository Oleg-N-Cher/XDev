@IF EXIST WinDevDJGPP.a @DEL WinDevDJGPP.a

@CALL Bin\djgppsmart.bat SYSTEM
@CALL Bin\djgppsmart.bat Platform
@CALL Bin\djgppsmart.bat Strings
@CALL Bin\djgppsmart.bat StringsW
@CALL Bin\djgppsmart.bat CmdLine
@CALL Bin\djgppsmart.bat CmdLineW
::@CALL Bin\djgppsmart.bat WinCmdLineW
@CALL Bin\djgppsmart.bat Math
@CALL Bin\djgppsmart.bat Files
@CALL Bin\djgppsmart.bat GrScr
@CALL Bin\djgppsmart.bat GrColors
@CALL Bin\djgppsmart.bat Console
::@CALL Bin\djgppsmart.bat ConsoleW
::@CALL Bin\djgppsmart.bat GrPixel
@CALL Bin\djgppsmart.bat GrTiles
@CALL Bin\djgppsmart.bat GrFonts
@CALL Bin\djgppsmart.bat GrConsole
@CALL Bin\djgppsmart.bat Input
@CALL Bin\djgppsmart.bat Timer

@PAUSE
@CALL Bin\clear
@SET bin=..\Bin
@SET DJGPP=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\djgpp.env
@SET PATH=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\bin;%PATH%
@SET gcc=gcc.exe -c -D_WIN32 -O3 -s -I "..\Bin\djgpp\include\win32"
@IF EXIST OfrontDJGPP.a @DEL OfrontDJGPP.a
@CALL %bin%\djgppsmart SYSTEM
@CALL %bin%\djgppsmart Platform
@CALL %bin%\djgppsmart CmdLine
@CALL %bin%\djgppsmart Console
@CALL %bin%\djgppsmart Strings
@CALL %bin%\djgppsmart Files
@PAUSE
@CALL %bin%\clear
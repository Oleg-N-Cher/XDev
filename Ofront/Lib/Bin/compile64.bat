@IF NOT "%XDev%"=="" GOTO XDev
@ECHO Please set system variable XDev=X:\Path\To\XDev
@PAUSE
@EXIT

:XDev
@SET WinDev=%XDev%\WinDev
@SET PATH=%WinDev%\Bin\MinGW64\bin;%PATH%
@SET gcc=gcc.exe -s -Os -fno-exceptions -fno-asynchronous-unwind-tables

@SET Mod=%1
@IF %Mod%==Unix.msvcrt SET Mod=Unix
@IF %Mod%==SYSTEM SET Mod=..\C\SYSTEM0
@IF NOT %Mod%==WinApi GOTO MinGW
@DEL WinApi.c
@EXIT

:MinGW
%gcc% -c %Mod%.c -I "." -I ..\C
@IF errorlevel 1 PAUSE
PAUSE
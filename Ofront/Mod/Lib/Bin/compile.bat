@ECHO OFF
IF NOT "%XDev%"=="" GOTO XDev
ECHO Please set system variable XDev=X:\Path\To\XDev
PAUSE
EXIT

:XDev
SET PATH=%XDev%\WinDev\Bin\MinGW\bin
SET CC=gcc.exe -I. -I.. -I..\Mod -m32 -s -Os -g0 -fvisibility=hidden -fomit-frame-pointer -finline-small-functions -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-exceptions -c
SET Mod=%1
IF "%Mod%"=="Platform.Windows" SET Mod=Platform
IF "%Mod%"=="SYSTEM" SET Mod=..\C\SYSTEM

%CC% %Mod%.c
IF errorlevel 1 PAUSE

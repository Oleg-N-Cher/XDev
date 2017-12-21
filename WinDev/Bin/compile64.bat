@ECHO OFF
IF "%XDev%"=="" SET XDev=..

SET PATH=%XDev%\WinDev\Bin\MinGW64\bin;%PATH%
SET gcc=gcc.exe -fno-exceptions -fno-asynchronous-unwind-tables -Wl,--file-alignment,512 -I%XDev%\WinDev\Lib\C -I%XDev%\WinDev\Lib\Obj64 -I%XDev%\WinDev\Lib

IF EXIST %1 GOTO config

%gcc% -c %1.c -I.
GOTO exit

:config
%gcc% -c %1.c -I%1

:exit
IF errorlevel 1 PAUSE

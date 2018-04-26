@ECHO OFF
IF "%XDev%"=="" SET XDev=..
SET WinDev=%XDev%\WinDev
SET PATH=%WinDev%\Bin\MinGW64\bin;%PATH%

IF "%MainMod%"=="" SET MainMod=%1
IF "%Pause%"=="" SET Pause=FALSE

SET Options=%Options% -m64 -fno-exceptions -fno-asynchronous-unwind-tables -Wl,--file-alignment,512 -D_WINGUI
SET Include=%Include% -I%WinDev%\Lib\Mod -I%WinDev%\Lib\Obj64
IF "%Clean%"=="" SET Clean=TRUE

SET GCC=gcc.exe %Options% %Include%

IF EXIST %1 GOTO Config

IF EXIST ..\Mod\%1.c DEL %1.h %1.c
IF EXIST ..\Mod\%1.c %GCC% -c ..\Mod\%1.c -I%WinDev%\Lib
IF NOT EXIST ..\Mod\%1.c %GCC% -c %1.c -I%WinDev%\Lib
GOTO Exit

:Config

IF EXIST ..\Mod\%1.c DEL %1.h %1.c
IF EXIST ..\Mod\%1.c %GCC% -c ..\Mod\%1.c -I%1
IF NOT EXIST ..\Mod\%1.c %GCC% -c %1.c -I%1

:Exit

IF errorlevel 1 PAUSE

IF NOT "%Clean%"=="TRUE" GOTO Done
::DEL *.asm *.lst %1.sym
::IF "%1"=="%MainMod%" DEL %1.h %1.rel %1.osm
::IF NOT "%1"=="%MainMod%" DEL %1.c

:Done

IF "%Pause%"=="TRUE" PAUSE

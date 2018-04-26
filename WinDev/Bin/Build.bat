@ECHO OFF
IF "%XDev%"=="" SET XDev=..
SET WinDev=%XDev%\WinDev
SET PATH=%WinDev%\Bin\MinGW\bin;%PATH%
IF "%MainMod%"=="" SET MainMod=%1
IF "%MainMod%"=="%1" GOTO Build

:Compile

SET SaveOptions=%Options%
SET SaveInclude=%Include%
CALL %WinDev%\Bin\Compile.bat %1
SET Options=%SaveOptions%
SET Include=%SaveInclude%

:Build

SET StripExe=-nostartfiles %WinDev%\Lib\Mod\crt1.c -Wl,-e__WinMain -D_WINGUI
IF "%App%"=="GUI" SET StripExe=-nostartfiles %WinDev%\Lib\Mod\crt1.c -Wl,-e__WinMain -D_WINGUI
IF "%App%"=="GUIcmd" SET StripExe=-nostartfiles %WinDev%\Lib\Mod\crt1w.c -Wl,-e__WinMain -D_WINGUI
IF "%App%"=="GUIcmd" SET App=GUI
SET Options=%StripExe% %Options% -m32 -s -Os -g0 -fvisibility=hidden -fomit-frame-pointer -finline-small-functions -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-exceptions -Wl,--gc-sections -Wl,--file-alignment,512
IF "%App%"=="GUI" SET Options=%Options% -mwindows
SET Include=%Include% -I%WinDev%\Lib\Mod -I%WinDev%\Lib\Obj
SET Libraries=%WinDev%\Lib\XDev.a -lgdi32
IF "%Clean%"=="" SET Clean=TRUE
IF "%Start%"=="" SET Start=TRUE
IF "%Pause%"=="" SET Pause=FALSE
IF "%Rsrc%"=="" GOTO NoRsrc

windres ..\Rsrc\%Rsrc%.res -Ocoff -Fpe-i386 -o%Rsrc%.o
SET Options=%Options% %Rsrc%.o

:NoRsrc

SET GCC=gcc.exe %Options% %Include% %Modules%

IF EXIST %MainMod% GOTO Config

%GCC% %MainMod%.c -I%WinDev%\Lib -o..\%MainMod%.exe %Libraries%
GOTO Link

:Config

%GCC% %MainMod%.c -I%MainMod% -I%WinDev%\Lib -o..\%MainMod%.exe %Libraries%

:Link

IF errorlevel 1 PAUSE

IF NOT "%Clean%"=="TRUE" GOTO Done
::DEL *.asm *.bin *.ihx *.lk *.lst *.map *.noi %MainMod%.h %MainMod%.sym %MainMod%.rel
IF "%Modules%"=="" DEL %MainMod%.c

:Done

IF "%App%"=="GUI" GOTO Gui

IF "%Start%"=="TRUE" ..\%MainMod%.exe
IF "%Pause%"=="TRUE" PAUSE
EXIT

:Gui

IF "%Pause%"=="TRUE" PAUSE
IF "%Start%"=="TRUE" START ..\%MainMod%.exe
pause
@ECHO OFF
IF "%XDev%"=="" SET XDev=..
SET WinDev=%XDev%\WinDev2
SET PATH=%WinDev%\Bin\GCC\bin;%PATH%

IF "%MainMod%"=="" SET MainMod=%1
IF "%MainMod%"=="%1" GOTO Build

:Compile

SET SaveOptions=%Options%
SET SaveInclude=%Include%
CALL %WinDev%\Bin\Compile.bat %1
SET Options=%SaveOptions%
SET Include=%SaveInclude%

:Build

SET StripExe=-nostartfiles %WinDev%\Lib\Mod\crt1.c -Wl,-e_WinMain@16 -D_WINGUI
SET Options=%StripExe% %Options% -m32 -s -Os -fno-exceptions -fno-asynchronous-unwind-tables -Wl,--gc-sections -Wl,--file-alignment,512
IF "%App%"=="GUI" SET Options=%Options% -mwindows
SET Include=%Include% -I%WinDev%\Lib\Mod -I%WinDev%\Lib\Obj
SET Libraries=%WinDev%\Lib\XDev.a -lgdi32
IF "%Clean%"=="" SET Clean=TRUE
IF "%Start%"=="" SET Start=TRUE
IF "%Pause%"=="" SET Pause=FALSE

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

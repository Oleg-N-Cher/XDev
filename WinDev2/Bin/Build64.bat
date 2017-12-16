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
SET Options=%StripExe% %Options% -m64 -s -Os -fno-exceptions -fno-asynchronous-unwind-tables -Wl,--gc-sections -Wl,--file-alignment,512
SET Include=%Include% -I%WinDev%\Lib\Mod -I%WinDev%\Lib\Obj64
SET Libraries=%Libraries% %WinDev%\Lib\XDev64.a
IF "%Clean%"=="" SET Clean=TRUE
IF "%Start%"=="" SET Start=TRUE
IF "%Pause%"=="" SET Pause=FALSE

SET GCC=gcc.exe %Options% %Include% %Modules%

IF EXIST %MainMod% GOTO Config

%GCC% %MainMod%.c -I%WinDev%\Lib -o..\x64\%MainMod%.exe %Libraries%
GOTO Link

:Config

%GCC% %MainMod%.c -I%MainMod% -I%WinDev%\Lib -o..\x64\%MainMod%.exe %Libraries%

:Link

IF errorlevel 1 PAUSE

IF NOT "%Clean%"=="TRUE" GOTO Done
::DEL *.asm *.bin *.ihx *.lk *.lst *.map *.noi %MainMod%.h %MainMod%.sym %MainMod%.rel
IF "%Modules%"=="" DEL %MainMod%.c

:Done

IF "%Start%"=="TRUE" ..\x64\%MainMod%.exe
IF "%Pause%"=="TRUE" PAUSE

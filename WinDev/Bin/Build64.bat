@ECHO OFF
IF "%XDev%"=="" SET XDev=..
SET WinDev=%XDev%\WinDev
SET PATH=%WinDev%\Bin\MinGW64\bin;%PATH%

IF "%MainMod%"=="" SET MainMod=%1
IF "%MainMod%"=="%1" GOTO Build

:Compile

SET SaveOptions=%Options%
SET SaveInclude=%Include%
CALL %WinDev%\Bin\Compile.bat %1
SET Options=%SaveOptions%
SET Include=%SaveInclude%

:Build

SET StripExe=-nostartfiles %WinDev%\Lib\Mod\crt1.c -Wl,-e_WinMain@16 -D_WINGUI -o..\x64\%MainMod%.exe
IF "%App%"=="GUI" SET StripExe=-nostartfiles %WinDev%\Lib\Mod\crt1.c -Wl,-e_WinMain@16 -D_WINGUI -o..\x64\%MainMod%.exe
IF "%App%"=="GUIcmd" SET StripExe=-nostartfiles %WinDev%\Lib\Mod\crt1w.c -Wl,-e_WinMain@16 -D_WINGUI -o..\x64\%MainMod%.exe
IF "%App%"=="GUIcmd" SET App=GUI
IF "%App%"=="DLL" SET App=DLL
IF "%App%"=="DLL" SET StripExe=-nostartfiles %WinDev%\Lib\Mod\crt1dll.c -Wl,-eDllMainCRTStartup@12 -o..\x64\%MainMod%.dll -Wl,--out-implib,%MainMod%.a
SET Options=%StripExe% %Options% -m64 -s -Os -g0 -fvisibility=hidden -fomit-frame-pointer -finline-small-functions -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-exceptions -Wl,--gc-sections
IF "%App%"=="GUI" SET Options=%Options% -mwindows
IF "%App%"=="DLL" SET Options=%Options% -fPIC -shared
SET Include=%Include% -I%WinDev%\Lib\Mod -I%WinDev%\Lib\Obj64
SET Libraries=%Libraries% %WinDev%\Lib\XDev64.a -lgdi32
IF "%Clean%"=="" SET Clean=TRUE
IF "%Start%"=="" SET Start=FALSE
IF "%Pause%"=="" SET Pause=FALSE
IF "%Rsrc%"=="" GOTO NoRsrc

windres ..\Rsrc\%Rsrc%.res -Ocoff -Fpe-x86-64 -o%Rsrc%.o
SET Options=%Options% %Rsrc%.o

:NoRsrc

SET GCC=gcc.exe %Options% %Include% %Modules%

IF EXIST %MainMod% GOTO Config

%GCC% %MainMod%.c -I%WinDev%\Lib %Libraries%
GOTO Link

:Config

%GCC% %MainMod%.c -I%MainMod% -I%WinDev%\Lib %Libraries%

:Link

IF errorlevel 1 PAUSE

IF NOT "%Clean%"=="TRUE" GOTO Done
::DEL *.asm *.bin *.ihx *.lk *.lst *.map *.noi %MainMod%.h %MainMod%.sym %MainMod%.rel
IF "%Modules%"=="" DEL %MainMod%.c

:Done

IF "%App%"=="GUI" GOTO Gui

IF "%Start%"=="TRUE" ..\x64\%MainMod%.exe
IF "%Pause%"=="TRUE" PAUSE
EXIT

:Gui

IF "%Pause%"=="TRUE" PAUSE
IF "%Start%"=="TRUE" START ..\x64\%MainMod%.exe

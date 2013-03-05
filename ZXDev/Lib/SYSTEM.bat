@REM Compile the library SYSTEM
@REM ==========================
@SET rootbin=..\..\Bin
@SET bin=..\Bin
@SET obj=..\..\Ofront\Obj

%rootbin%\smartlinkrel SYSTEM.c
@FOR %%i IN (SYSTEM_0??.c) DO %bin%\sdcc -c -mz80 --no-std-crt0 --opt-code-size --funsigned-char --disable-warning 59 --disable-warning 85 -I "..\Obj" -L z80 %%i

REM @FOR %%i IN (SYSTEM_0??.rel) DO %bin%\sdcclib z80/XDev.lib %%i
@FOR %%i IN (SYSTEM_0??.rel) DO %bin%\sdar -rc z80/XDev.lib %%i

@SET CodeAdr=25000

@ECHO OFF
SET MainMod=%1
SET HTC=%XDev%\ZXDev3\Bin\HTC\
SET PATH=%XDev%\ZXDev3\Bin\

cpm.exe -h %HTC%\C.COM -O -C %MainMod%.C
IF errorlevel 1 PAUSE
cpm.exe -h %HTC%\LINK.COM -Z -Ptext=%CodeAdr% -C%CodeAdr% %MainMod%.OBJ A:LIBC2.LIB A:BASIC.LIB
IF errorlevel 1 PAUSE
MOVE L.BIN %MainMod%.bin
::DEL *.$$$
stripbin.exe %MainMod%.bin
bin2tap.exe -c 24999 -a %CodeAdr% -r %CodeAdr% -b -o ..\%MainMod%.tap %MainMod%.bin
::bin2data.exe -rem -org %CodeAdr% %MainMod%.bin ..\%MainMod%.tap %MainMod%
START ..\%MainMod%.tap
Clean.bat

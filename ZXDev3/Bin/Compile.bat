@ECHO OFF
SET MainMod=%1
SET HTC=%XDev%\ZXDev3\Bin\HTC\
SET PATH=%XDev%\ZXDev3\Bin\

cpm.exe -h %HTC%\C.COM -C %MainMod%.C
IF errorlevel 1 PAUSE

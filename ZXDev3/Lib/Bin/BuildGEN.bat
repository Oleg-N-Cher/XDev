@ECHO OFF
SET HTC=%XDev%\ZXDev3\Bin\HTC\
SET PATH=%XDev%\ZXDev3\Bin\
SET LIB=LIBC2.LIB

CD ..\Asm\GEN
IF EXIST %LIB% DEL %LIB%
cpm.exe -h %HTC%\ZAS.COM CSV.AS
IF errorlevel 1 PAUSE
cpm.exe -h %HTC%\LIBR.COM r %LIB% CSV.OBJ
IF errorlevel 1 PAUSE
MOVE /Y %LIB% %HTC%
DEL *.OBJ

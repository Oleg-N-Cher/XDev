@ECHO OFF
SET HTC=%XDev%\ZXDev3\Bin\HTC\
SET PATH=%XDev%\ZXDev3\Bin\
SET SmartLib=%XDev%\Bin\smartlib
IF EXIST ..\C\%1.c GOTO C_Lib
IF EXIST ..\Asm\%1.asm GOTO Asm_Lib

:Ob_Lib_Obj

cpm.exe -h %HTC%\C.COM -c %1.c
IF NOT errorlevel 1 GOTO Exit
%SmartLib% %1.c -nocut -noinit
cpm.exe -h %HTC%\C.COM -c %1.c
GOTO Exit

:C_Lib

IF EXIST %1.h DEL %1.h
IF EXIST %1.c DEL %1.c
cpm.exe -h %HTC%\C.COM -c ..\C\%1.c
IF errorlevel 1 PAUSE

IF NOT EXIST ..\Asm\%1.asm GOTO Exit

:Asm_Lib

cpm.exe -h %HTC%\ZAS.COM ..\Asm\%1.asm

:Exit
IF errorlevel 1 PAUSE
PAUSE

@REM args:
@REM   LibName ModName [PartName] [-noinit] [-nocut]

@ECHO OFF
SET HTC=%XDev%\ZXDev3\Bin\HTC\
SET PATH=%XDev%\ZXDev3\Bin\
SET SmartLib=%XDev%\Bin\smartlib

IF EXIST ..\%1.lib DEL ..\%1.lib
IF EXIST ..\C\%2.c GOTO C_Lib
IF EXIST ..\Asm\%2.asm GOTO Asm_Lib

:Ob_Lib_Obj

%SmartLib% %2.c %3
GOTO Compile

:C_Lib

IF EXIST %2.h DEL %2.h
IF EXIST %2.c DEL %2.c
%SmartLib% ..\C\%2.c %3

:Compile

FOR %%i IN (%3_???.c) DO (
  cpm.exe -h %HTC%\C.COM -c %%i
  IF errorlevel 1 PAUSE
)
FOR %%i IN (%3_???.OBJ) DO cpm.exe -h %HTC%\LIBR.COM r %1.LIB %%i

IF NOT EXIST ..\Asm\%1.asm GOTO Exit

:Asm_Lib

CALL ..\Bin\Clean
%SmartLib% ..\Asm\%2.asm %3

FOR %%i IN (%3_???.asm) DO (
  cpm.exe -h %HTC%\ZAS.COM %%i
  IF errorlevel 1 PAUSE
)
FOR %%i IN (%3_???.OBJ) DO cpm.exe -h %HTC%\LIBR.COM r %1.LIB %%i

:Exit

..\Bin\Clean

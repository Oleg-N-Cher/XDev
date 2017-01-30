@ECHO OFF
SET PATH=%XDev%\ZXDev3\Bin\
SET SmartLib=%XDev%\Bin\smartlib

IF EXIST ..\%1.lib DEL ..\%1.lib
IF EXIST ..\C\%1.c GOTO C_Lib
IF EXIST ..\Asm\%1.asm GOTO Asm_Lib

:Ob_Lib_Obj

%SmartLib% %1.c %2
GOTO Compile

:C_Lib

IF EXIST %1.h DEL %1.h
IF EXIST %1.c DEL %1.c
%SmartLib% ..\C\%1.c %2

:Compile

FOR %%i IN (%2_???.c) DO (
  cpm.exe -h %HTC%\C.COM -c %%i
  IF errorlevel 1 PAUSE
)
FOR %%i IN (%2_???.OBJ) DO cpm.exe -h %HTC%\LIBR.COM r %1.LIB %%i

IF NOT EXIST ..\Asm\%1.asm GOTO Exit

:Asm_Lib

CALL ..\Bin\Clean
%SmartLib% ..\Asm\%1.asm %2

FOR %%i IN (%2_???.asm) DO (
  cpm.exe -h %HTC%\ZAS.COM %%i
  IF errorlevel 1 PAUSE
)
FOR %%i IN (%2_???.OBJ) DO cpm.exe -h %HTC%\LIBR.COM r %1.LIB %%i

:Exit

MOVE /Y %1.LIB %HTC%
..\Bin\Clean

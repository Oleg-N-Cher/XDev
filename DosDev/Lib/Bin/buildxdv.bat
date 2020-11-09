@ECHO OFF
SET SmartLib=..\..\..\Bin\smartlib.exe
IF EXIST ..\C\%1.c GOTO c_lib

:o_lib

%SmartLib% %1.c %2
GOTO compile

:c_lib

IF EXIST ..\Obj\%1.oh DEL %1.oh
IF EXIST ..\Obj\%1.c DEL %1.c
%SmartLib% ..\C\%1.c %2

:compile

FOR %%i IN (%2???.c) DO (
  SET Mod=%%i
  CD ..\..
  vDosPlus.exe /set frame=on;window=50;autoexec=Lib\Bin\bu.bat
  CD Lib\Obj
)
FOR %%i IN (%2???.OBJ) DO (
  SET Mod=%%i
  CD ..\..
  vDosPlus.exe /set frame=on;window=50;autoexec=Lib\Bin\lib.bat
  CD Lib\Obj
)
..\Bin\clear.bat

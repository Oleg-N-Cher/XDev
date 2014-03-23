@SET DJGPP=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\djgpp.env
@SET PATH=d:\Archive\Projects\XDev\WinDev\Bin\djgpp\bin;%PATH%
@SET gcc=gcc.exe @Bin\djgpp.opt

@IF EXIST %1.c GOTO nobj
%gcc% -c Obj\%1.c -I "."
@GOTO exit

:nobj
%gcc% -c %1.c -I "." -I Obj

:exit
@IF ERRORLEVEL 1 @PAUSE
::@ar -rc WinDevDJGPP.a %1.o

@..\..\Bin\smartlib %1.c
@FOR %%i IN (%1_0??.c) DO %gcc% -c %%i
@FOR %%i IN (%1_0??.o) DO ar -rc WinDevDJGPP.a %%i
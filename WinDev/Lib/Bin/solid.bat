@REM args:
@REM   LibName ModName

@SET RootBin=..\..\Bin
@SET Bin=..\Bin
@SET tcc=%Bin%\tcc\tcc.exe

@IF EXIST %2.c GOTO clib

:olib
%tcc% -c Obj\%2.c -I "." -I Obj
@GOTO done

:clib
%tcc% -c %2.c -I "." -I Obj

:done
@IF errorlevel 1 PAUSE

@%Bin%\ar -rc %1 %2.o
@DEL %2.o

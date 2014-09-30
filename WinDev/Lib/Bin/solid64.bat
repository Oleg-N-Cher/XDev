@REM args:
@REM   LibName ModName

@SET RootBin=..\..\..\Bin
@SET Bin=..\..\Bin
@SET tcc=%Bin%\tcc64\tcc.exe

@IF EXIST ..\%2.c GOTO clib

:olib
%tcc% -c %2.c -I ".." -I "."
@GOTO done

:clib
@DEL %2.h
@DEL %2.c
%tcc% -c ..\%2.c -I ".." -I "."

:done
@IF errorlevel 1 PAUSE

@%Bin%\ar64 -rc %1 %2.o
@DEL %2.o

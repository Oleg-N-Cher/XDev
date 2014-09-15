@REM args:
@REM   LibName ModName

@SET RootBin=..\..\Bin
@SET Bin=..\Bin
@SET tcc=%Bin%\tcc64\tcc.exe

@IF EXIST %2.c GOTO clib

:olib
IF NOT EXIST Obj64\%2.c GOTO thesame
%tcc% -c Obj64\%2.c -I "." -I Obj
@GOTO done
:thesame
%tcc% -c Obj\%2.c -I "." -I Obj
@GOTO done

:clib
%tcc% -c %2.c -I "." -I Obj

:done
@IF errorlevel 1 PAUSE

@%Bin%\ar64 -rc %1 %2.o
@DEL %2.o

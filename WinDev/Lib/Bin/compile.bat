@CD ..
@IF EXIST %1.c GOTO clib

:olib
..\Bin\tcc\tcc -c Obj\%1.c -I "." -I Obj
@IF errorlevel 1 GOTO noinit
@GOTO exit

:noinit
..\..\Bin\smartlib Obj\%1.c -noinit -nocut
..\Bin\tcc\tcc -c Obj\%1.c -I "." -I Obj
@GOTO exit

:clib
..\Bin\tcc\tcc -c %1.c -I "." -I Obj

:exit
@IF errorlevel 1 PAUSE

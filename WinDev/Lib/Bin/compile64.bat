@CD ..
@IF EXIST %1.c GOTO clib

:olib
IF NOT EXIST Obj64\%1.c GOTO thesame1
..\Bin\tcc64\tcc -c Obj64\%2.c -I "." -I Obj64
@GOTO errlev
:thesame1
..\Bin\tcc64\tcc -c Obj\%1.c -I "." -I Obj
:errlev
@IF errorlevel 1 GOTO noinit
@GOTO exit

:noinit
IF NOT EXIST Obj64\%1.c GOTO thesame2
..\..\Bin\smartlib Obj64\%1.c -noinit -nocut
..\Bin\tcc64\tcc -c Obj64\%1.c -I "." -I Obj64
@GOTO exit
:thesame2
..\..\Bin\smartlib Obj\%1.c -noinit -nocut
..\Bin\tcc64\tcc -c Obj\%1.c -I "." -I Obj
@GOTO exit

:clib
..\Bin\tcc64\tcc -c %1.c -I "." -I Obj

:exit
@IF errorlevel 1 PAUSE
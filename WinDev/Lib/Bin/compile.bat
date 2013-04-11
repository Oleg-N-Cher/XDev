@CD ..
..\Bin\tcc\tcc -c %1.c -I "." -I Obj
@IF errorlevel 1 PAUSE
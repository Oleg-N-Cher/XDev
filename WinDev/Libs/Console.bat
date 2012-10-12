..\Bin\smartlinkrel Console.c
@FOR %%i IN (Console_0??.c) DO ..\Bin\tcc\tcc.exe -c %%i

@IF EXIST Console.a DEL Console.a
@FOR %%i IN (Console_0??.o) DO ..\Bin\ar -rc Console.a %%i
REM ..\Bin\tcc\tiny_libmaker Console.a Console_001.o Console_002.o

@PAUSE

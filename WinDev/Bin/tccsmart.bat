@SET bin=..\Bin
@SET tcc=%bin%\tcc\tcc.exe
@SET smartlib=..\%bin%\smartlib

%tcc% -c %1.c -I "." -I Obj
@IF ERRORLEVEL 1 @PAUSE
@%smartlib% %1.c
@FOR %%i IN (%1_0??.c) DO %tcc% -c %%i -I "." -I Obj
@FOR %%i IN (%1_0??.o) DO %bin%\ar -rc WinDev.a %%i
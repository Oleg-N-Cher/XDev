@SET bin=..\Bin
@SET tcc=%bin%\tcc32\tcc.exe
%tcc% -c %1.c
@IF ERRORLEVEL 1 @PAUSE
@%bin%\smartlib %1.c
@FOR %%i IN (%1_0??.c) DO %tcc% -c %%i
@FOR %%i IN (%1_0??.o) DO %bin%\ar -rc Ofront32.a %%i
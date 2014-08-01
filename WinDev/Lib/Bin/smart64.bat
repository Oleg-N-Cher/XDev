@REM args:
@REM   LibName ModName [PartName] [-noinit] [-nocut]

@SET RootBin=..\..\Bin
@SET Bin=..\Bin
@SET tcc=%Bin%\tcc64\tcc.exe

@IF EXIST %2.c GOTO clib

:olib
@COPY Obj\%2.h
%RootBin%\smartlib Obj\%2.c %3 %4 %5
@GOTO compile

:clib
%RootBin%\smartlib %2.c %3 %4 %5

:compile
@FOR %%i IN (%2_???.c) DO (
  %tcc% -c %%i -I "." -I Obj
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%2_???.o) DO %Bin%\ar64 -rc %1 %%i
@Bin\clear
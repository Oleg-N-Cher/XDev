@SET RootBin=..\..\..\..\Bin
@SET Bin=..\..\..\Bin
@SET Lib=..\..\..\Lib
@SET tcc=%Bin%\tcc\tcc.exe

@IF EXIST ..\Pow.a DEL ..\Pow.a

%RootBin%\smartlib %1.c
@FOR %%i IN (%1_0??.c) DO (
  %tcc% -c %%i -I "." -I %Lib% -I %Lib%\Obj
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%1_0??.o) DO %Bin%\ar -rc ..\Pow.a %%i

@COPY /B /Y ..\Sym\PowStrings.sym ..\..\Sym
@COPY /B /Y ..\Obj\PowStrings.h ..\..

@..\Bin\clear
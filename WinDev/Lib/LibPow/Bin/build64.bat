@SET RootBin=..\..\..\..\Bin
@SET Bin=..\..\..\Bin
@SET Lib=..\..\..\Lib
@SET tcc=%Bin%\tcc64\tcc.exe

@CD ..
@CD Obj64
@IF EXIST ..\Pow64.a DEL ..\Pow64.a

%RootBin%\smartlib %1.c
@FOR %%i IN (%1_0??.c) DO (
  %tcc% -c %%i -I "." -I %Lib% -I %Lib%\Obj64
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%1_0??.o) DO %Bin%\ar64 -rc ..\Pow64.a %%i

@COPY /B /Y ..\Sym\PowStrings.sym ..\..\Sym
@COPY /B /Y ..\Obj\PowStrings.h ..\..

@..\Bin\clear
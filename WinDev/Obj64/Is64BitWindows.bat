@SET Mod=Is64BitWindows
@SET RootBin=..\..\Bin
@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc64\tcc

@IF EXIST %Mod%.a DEL %Mod%.a
%RootBin%\smartlib %Mod%.c
@FOR %%i IN (%Mod%_0??.c) DO (
  %tcc% -c %%i -I "." -I %Lib%
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (%Mod%_0??.o) DO %Bin%\ar64 -rc %Mod%.a %%i

@FOR %%i IN (%Mod%_0??.c) DO (
  %tcc% %%i -I "." -I %Lib% %Lib%\WinDev64.a Is64BitWindows.a -o ..\x64\%Mod%.exe
)

@IF errorlevel 1 PAUSE
@CD ..\x64
@CLS
@%Mod%.exe
@PAUSE
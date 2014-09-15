@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc64\tcc

@IF EXIST %1 GOTO config

%tcc% %1.c -I "." -I %Lib% %Lib%\x86-64\Kol64.a %Lib%\x86-64\XDev64.a -o ..\x64\%1.exe
@GOTO exit

:config
%tcc% %1.c -I %1 -I %Lib% %Lib%\x86-64\Kol64.a %Lib%\x86-64\XDev64.a -o ..\x64\%1.exe

:exit
@IF errorlevel 1 PAUSE
@CD ..\x64 
@CLS
@%1.exe
@PAUSE
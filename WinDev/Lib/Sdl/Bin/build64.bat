@SET Bin=..\..\..\Bin
@SET Lib=..\..\..\Lib
@SET tcc=%Bin%\tcc64\tcc.exe

@CD ..
@CD Obj64
%tcc% -c SdlLib.c -I "." -I %Lib% -I %Lib%\Obj64 -I %Bin%\tcc64\include\SDL
@IF errorlevel 1 PAUSE

%Bin%\ar -rc ..\SdlLib64.a SdlLib.o

@COPY /B /Y ..\Sym\SdlLib.sym ..\..\Sym
@COPY /B /Y ..\Obj\SdlLib.h ..\..
PAUSE

REM @..\Bin\clear
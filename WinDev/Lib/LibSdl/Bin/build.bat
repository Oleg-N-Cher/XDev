@SET Bin=..\..\..\Bin
@SET Lib=..\..\..\Lib
@SET tcc=%Bin%\tcc\tcc.exe

%tcc% -c %1.c -I "." -I %Lib% -I %Lib%\Obj -I %Bin%\tcc\include\SDL
@IF errorlevel 1 PAUSE

%Bin%\ar -rc ..\SdlLib.a %1.o

@COPY /B /Y ..\Sym\SdlLib.sym ..\..\Sym
@COPY /B /Y ..\Obj\SdlLib.h ..\..
PAUSE

REM @..\Bin\clear
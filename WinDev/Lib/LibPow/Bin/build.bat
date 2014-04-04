@SET Bin=..\..\..\Bin
@SET Lib=..\..\..\Lib
@SET tcc=%Bin%\tcc\tcc.exe

%tcc% -c %1.c -I "." -I %Lib% -I %Lib%\Obj
@IF errorlevel 1 PAUSE

%Bin%\ar -rc ..\PowLib.a %1.o

@COPY /B /Y ..\Sym\PowStrings.sym ..\..\Sym
@COPY /B /Y ..\Obj\PowStrings.h ..\..
PAUSE

REM @..\Bin\clear
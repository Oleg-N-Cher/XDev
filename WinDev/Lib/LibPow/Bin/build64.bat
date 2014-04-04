@SET Bin=..\..\..\Bin
@SET Lib=..\..\..\Lib
@SET tcc=%Bin%\tcc64\tcc.exe

@CD ..
@CD Obj64
%tcc% -c %1.c -I "." -I %Lib% -I %Lib%\Obj64
@IF errorlevel 1 PAUSE

%Bin%\ar -rc ..\PowLib64.a %1.o

@COPY /B /Y ..\Sym\PowStrings.sym ..\..\Sym
@COPY /B /Y ..\Obj\PowStrings.h ..\..
PAUSE

REM @..\Bin\clear
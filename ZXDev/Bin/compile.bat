@SET Bin=..\Bin
@SET Lib=..\Lib

%Bin%\sdcc -c %1.c -mz80 --opt-code-size -I "." -I %Lib% --disable-warning 59
@IF errorlevel 1 PAUSE
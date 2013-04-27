@SET Bin=..\Bin
@SET Lib=..\Lib

%Bin%\sdcc -c %1.c -mz80 --opt-code-size -I "." -I %Lib%
@IF errorlevel 1 PAUSE
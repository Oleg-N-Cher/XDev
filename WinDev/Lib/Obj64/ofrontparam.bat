@SET Bin=..\..\Bin
%Bin%\tcc64\tcc ofrontparam.c -I"." -I".." ..\XDev64.a -o ofrontparam.exe
@IF errorlevel 1 PAUSE

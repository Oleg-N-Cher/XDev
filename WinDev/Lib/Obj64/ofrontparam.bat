@SET Bin=..\..\Bin
%Bin%\tcc64\tcc ofrontparam.c -I"." -I".." ..\WinDev64.a -o ofrontparam.exe
@IF errorlevel 1 PAUSE

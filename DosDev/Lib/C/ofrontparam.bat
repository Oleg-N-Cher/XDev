@SET Bin=..\..\Bin
%Bin%\tcc\tcc ofrontparam.c -I"." -I".." ..\WinDev.a -o ofrontparam.exe
@IF errorlevel 1 PAUSE

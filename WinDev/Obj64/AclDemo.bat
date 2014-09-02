@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc64\tcc

%tcc% AclDemo.c -D_WINGUI -I "." -I %Lib% %Lib%\x86-64\Acl64.a %Lib%\x86-64\XDev64.a -o AclDemo.exe
@IF errorlevel 1 PAUSE

@IF EXIST AclDemo.exe MOVE AclDemo.exe ..\x64
@START ..\x64\AclDemo.exe

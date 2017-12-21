@SET Bin=..\Bin
@SET Lib=..\Lib
@SET tcc=%Bin%\tcc\tcc

%tcc% AclDemo.c -D_WINGUI -I "." -I %Lib% %Lib%\x86\Acl.a %Lib%\x86\Tst.a %Lib%\x86\XDev.a -o AclDemo.exe
@IF errorlevel 1 PAUSE

@IF EXIST AclDemo.exe MOVE AclDemo.exe ..
@START ..\AclDemo.exe

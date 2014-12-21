:: Build LaserDemo.c
:: =================
@SET CodeAddr=45056
@SET DataAddr=63488
@SET Bin=..\Bin
@SET Lib=..\Lib

%Bin%\sdcc -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --no-std-crt0 --opt-code-size --funsigned-char --disable-warning 59 --disable-warning 85 --disable-warning 126 -I %Lib% -I %Lib%\C -I %Lib%\Obj -L %Lib% LaserDemo.c Basic.lib Laser.lib
@IF errorlevel 1 PAUSE

:: Convert Intel hex format to binary
:: ==================================
%Bin%\hex2bin LaserDemo.ihx

:: Link the target to TR-DOS format
:: ================================
::@DEL /Q LaserDemo.trd
::%Bin%\bin2trd.exe LaserDemo.trl
::@ATTRIB -R laserdemo.trd
::@MOVE /Y laserdemo.trd ..\LaserDemo.trd
:: Link the target to TAP format
%Bin%\bin2data.exe -rem -org %CodeAddr% LaserDemo.bin ..\LaserDemo.tap LaserDemo
START ..\LaserDemo.tap

:: Build LaserDemo.c
:: =================
@SET CodeAddr=45056
@SET DataAddr=63488
@SET Bin=..\Bin
@SET Lib=..\Lib

%Bin%\sdcc -mz80 --code-loc %CodeAddr% --data-loc %DataAddr% --no-std-crt0 --opt-code-size --funsigned-char --disable-warning 126 -I "." -I %Lib% -L %Lib%/z80 LaserDemo.c Basic.lib Laser.lib LaserSprite2B.lib
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
%Bin%\hex2bin LaserDemo.ihx
%Bin%\bin2data.exe -rem -org %CodeAddr% LaserDemo.bin ..\LaserDemo.tap LaserDemo

:: ========================================================================
@ECHO Now you can run the image "LaserDemo.trd" in your favourite emulator
:: ========================================================================
START ..\LaserDemo.tap
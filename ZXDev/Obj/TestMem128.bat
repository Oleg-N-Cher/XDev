@ECHO OFF
:: Compile TestMem128.c
:: ====================

SET Name=TestMem128
SET CodeAdr=26000
SET DataAdr=30000
SET Bin=..\Bin
SET Lib=..\Lib

%Bin%\sdcc %Name%.c -mz80 --reserve-regs-iy --code-loc %CodeAdr% --data-loc %DataAdr% --opt-code-size --disable-warning 59 --disable-warning 85 --disable-warning 126 -I %Lib% -I %Lib%\C -I %Lib%\Obj -L %Lib% Basic.lib XDev.lib Mem128.lib
IF errorlevel 1 PAUSE

:: Convert Intel hex format to binary
:: ==================================
%Bin%\hex2bin %Name%.ihx

:: Link the target to TAP format
:: =============================

%Bin%\bin2data.exe -rem -org %CodeAdr% %Name%.bin ..\%Name%.tap %Name%
IF errorlevel 1 PAUSE
COPY /b ..\TestMem128.tap + TestMem128data.tap ..\%Name%.tap

:: Link the target to TR-DOS format
:: ================================
DEL /Q %Name%.trd
%bin%\bin2trd.exe %Name%.trl
ATTRIB -R %Name%.trd
MOVE /Y %Name%.trd ..\%Name%.trd

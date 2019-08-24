@REM Compile TestMem128.c
@REM ====================

@SET Bin=..\Bin
@SET Lib=..\Lib

%bin%\sdcc TestMem128.c -mz80 --reserve-regs-iy --code-loc 26000 --data-loc 30000 --opt-code-size --disable-warning 59 --disable-warning 85 --disable-warning 126 -I %Lib% -I %Lib%\C -I %Lib%\Obj -L %Lib% Basic.lib XDev.lib Mem128.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\hex2bin TestMem128.ihx

@REM Link the target to TR-DOS format
@REM ================================
@DEL /Q TestMem128.trd
%bin%\bin2trd.exe TestMem128.trl
@ATTRIB -R TestMem128.trd
@MOVE /Y TestMem128.trd ..\TestMem128.trd

@REM ======================================================================
@ECHO Now you can run the image "TestMem128.trd" in your favourite emulator
@REM ======================================================================

START ..\TestMem128.trd
@REM Compile TrDosTest.c
@REM ===================

@SET Bin=..\Bin
@SET Lib=..\Lib

%bin%\sdcc TrDosTest.c -mz80 --reserve-regs-iy --code-loc 26000 --data-loc 0xF800 --opt-code-size --funsigned-char --disable-warning 59 --disable-warning 85 --disable-warning 126 -I "." -I %Lib% -I %Lib%\C -I %Lib%\Obj -L %Lib% Basic.lib XDev.lib trdos.lib
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\hex2bin TrDosTest.ihx

@REM Link the target to TR-DOS format
@REM ================================
@DEL /Q TrDosTest.trd
%bin%\bin2trd.exe TrDosTest.trl
@ATTRIB -R TrDosTest.trd
@MOVE /Y TrDosTest.trd ..\TrDosTest.trd

@REM ======================================================================
@ECHO Now you can run the image "TrDosTest.trd" in your favourite emulator
@REM ======================================================================

START ..\TrDosTest.trd
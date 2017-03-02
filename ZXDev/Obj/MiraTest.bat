@SET CodeAddr=45056
@SET DataAddr=63488
@SET bin=..\Bin
@SET lib=..\Lib

%bin%\sdcc MiraTest.c -mz80 --reserve-regs-iy --code-loc %CodeAddr% --data-loc %DataAddr% --opt-code-size -I %lib% -I %lib%\C -I %lib%\Obj -L %lib% Basic.lib MiraMod2.lib --disable-warning 59 --disable-warning 85
@IF errorlevel 1 PAUSE

@REM Convert Intel hex format to binary
@REM ==================================
%bin%\hex2bin MiraTest.ihx
::%bin%\stripbin MiraTest.bin

@REM Link the target to TAP format
@REM =============================
%bin%\bin2data.exe -rem -org %CodeAddr% MiraTest.bin ..\MiraTest.tap MiraTest

@REM ======================================================================
@ECHO Now you can run the image "MiraTest.tap" in your favourite emulator.
@REM ======================================================================

START ..\MiraTest.tap
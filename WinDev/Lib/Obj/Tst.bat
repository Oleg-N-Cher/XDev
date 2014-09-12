@REM Build the library Pow
@REM =====================
@CD ..

:tcc
@SET Lib=x86\Tst.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\solid %Lib% Tst

:djgpp
::@IF NOT EXIST Obj\.djgpp GOTO tcc64
::@SET Lib=x86\PowDJGPP.a
::@IF EXIST %Lib% DEL %Lib%
::@CALL Bin\soliddjgpp %Lib% PowStrings -noinit

:tcc64
@IF NOT EXIST Obj64\.tcc64 GOTO exit
@SET Lib=x86-64\Tst64.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\solid64 %Lib% Tst

:exit
@CD Obj
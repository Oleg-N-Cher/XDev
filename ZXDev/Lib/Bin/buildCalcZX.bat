@SET Lib=..\CalcZX.lib
@IF EXIST %Lib% DEL %Lib%

@CALL ..\Bin\smart %Lib% CalcZX -noinit

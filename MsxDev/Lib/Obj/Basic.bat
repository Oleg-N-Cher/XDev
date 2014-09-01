@CD ..
@SET Lib=z80\Basic.lib
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smart %Lib% Basic
@CD Obj
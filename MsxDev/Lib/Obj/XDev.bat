@CD ..
@SET Lib=z80\XDev.lib
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smart %Lib% Console
@CD Obj
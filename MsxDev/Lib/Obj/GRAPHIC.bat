@CD ..
@SET Lib=z80\Graphic.lib
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smart %Lib% GRAPHIC -noinit
@CD Obj
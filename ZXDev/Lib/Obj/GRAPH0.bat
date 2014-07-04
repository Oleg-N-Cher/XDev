@SET Lib=z80\MiraMod2.lib
@IF EXIST ..\%Lib% DEL ..\%Lib%

@CALL ..\Bin\smart %Lib% GRAPH0 -noinit

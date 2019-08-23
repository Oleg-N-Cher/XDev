@SET Lib=..\Mem128.lib
@IF EXIST %Lib% DEL %Lib%

@CALL ..\Bin\smart %Lib% Mem128

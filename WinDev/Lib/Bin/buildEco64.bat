@REM Build the library Oak
@REM =====================

@IF NOT EXIST .tcc64 GOTO exit
@SET Lib=..\x86-64\Eco64.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart64 %Lib% EcoBigSets
@CALL ..\Bin\smart64 %Lib% EcoListen
@CALL ..\Bin\smart64 %Lib% EcoLists

:exit

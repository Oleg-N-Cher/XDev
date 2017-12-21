@REM Build the library Oak
@REM =====================

:MinGW64
@SET Lib=..\Eco64.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart64 %Lib% EcoBigSets
@CALL ..\Bin\solid64 %Lib% EcoBuffer
@CALL ..\Bin\smart64 %Lib% EcoListen
@CALL ..\Bin\smart64 %Lib% EcoLists
@CALL ..\Bin\solid64 %Lib% EcoVector
@CALL ..\Bin\solid64 %Lib% EcoParser

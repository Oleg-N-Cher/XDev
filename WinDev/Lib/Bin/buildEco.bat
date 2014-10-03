@REM Build the library Oak
@REM =====================

:tcc
@SET Lib=..\Eco.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart %Lib% EcoBigSets
@CALL ..\Bin\smart %Lib% EcoListen
@CALL ..\Bin\smart %Lib% EcoLists

:djgpp
@IF NOT EXIST .djgpp GOTO exit
@SET Lib=..\EcoDJGPP.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smartdjgpp %Lib% EcoBigSets
@CALL ..\Bin\smartdjgpp %Lib% EcoListen
@CALL ..\Bin\smartdjgpp %Lib% EcoLists

:exit

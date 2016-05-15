@REM Build the library Oak
@REM =====================

:MinGW
@SET Lib=..\Eco.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart %Lib% EcoBigSets
@CALL ..\Bin\solid %Lib% EcoBuffer
@CALL ..\Bin\smart %Lib% EcoListen
@CALL ..\Bin\smart %Lib% EcoLists
@CALL ..\Bin\solid %Lib% EcoVector
@CALL ..\Bin\solid %Lib% EcoParser

:DJGPP
@IF NOT EXIST .djgpp GOTO exit
@SET Lib=..\EcoDJGPP.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smartdjgpp %Lib% EcoBigSets
@CALL ..\Bin\soliddjgpp %Lib% EcoBuffer
@CALL ..\Bin\smartdjgpp %Lib% EcoListen
@CALL ..\Bin\smartdjgpp %Lib% EcoLists
@CALL ..\Bin\soliddjgpp %Lib% EcoVector
@CALL ..\Bin\soliddjgpp %Lib% EcoParser

:exit

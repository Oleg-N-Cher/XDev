@REM Build the library Oak
@REM =====================

:tcc
@SET Lib=..\Eco.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart %Lib% EcoBigSets
@CALL ..\Bin\smart %Lib% EcoListen
@CALL ..\Bin\smart %Lib% EcoLists

:djgpp
@SET Lib=..\EcoDJGPP.a
@IF EXIST %Lib% DEL %Lib%
::@CALL ..\Bin\soliddjgpp %Lib% EcoBigSets
::@CALL ..\Bin\soliddjgpp %Lib% EcoListen
::@CALL ..\Bin\soliddjgpp %Lib% EcoLists

:exit

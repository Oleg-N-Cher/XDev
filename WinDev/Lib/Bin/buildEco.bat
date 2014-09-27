@REM Build the library Oak
@REM =====================

:tcc
@SET Lib=..\x86\Eco.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart %Lib% EcoBigSets
@CALL ..\Bin\smart %Lib% EcoListen
@CALL ..\Bin\smart %Lib% EcoLists

:djgpp
@SET Lib=..\x86\EcoDJGPP.a
@IF EXIST %Lib% DEL %Lib%
::@CALL ..\Bin\soliddjgpp %Lib% AclUtils
::@CALL ..\Bin\soliddjgpp %Lib% AclLib

:exit

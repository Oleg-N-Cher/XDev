@REM Compile the library Laser
@REM =========================

@CD ..
@SET Bin=..\Bin
@SET RootBin=..\..\Bin

@IF EXIST Laser.lib DEL Laser.lib

%RootBin%\smartlib Laser.c
@FOR %%i IN (Laser_0??.c) DO (
  %Bin%\sdcc -c %%i -mz80 --opt-code-size --disable-warning 59 --disable-warning 85 -I "." -I Obj
  @IF errorlevel 1 PAUSE
)
@FOR %%i IN (Laser_0??.rel) DO %Bin%\sdar -rc Laser.lib %%i
@MOVE /Y Laser.lib z80/Laser.lib

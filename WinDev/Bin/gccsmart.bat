@SET path=d:\WIN32APP\Dev\MinGW\bin
@SET bin=..\Bin
@SET gcc=gcc.exe -O3 -s -fno-strict-aliasing
%gcc% -c %1.c
@IF ERRORLEVEL 1 @PAUSE
@%bin%\smartlinkrel %1.c
@FOR %%i IN (%1_0??.c) DO %gcc% -c %%i
@FOR %%i IN (%1_0??.o) DO %bin%\ar -rc OfrontGCC.a %%i
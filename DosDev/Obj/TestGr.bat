@ECHO OFF
CALL ..\Bin\Build.bat TestGr
:Wait
IF EXIST TestGr.exe GOTO Run
TIMEOUT /T 1 /NOBREAK >NUL
GOTO Wait
:Run
MOVE /Y TestGr.exe D:\DOS >NUL
D:\
CD \WIN32APP\DOSBox\
START DOSBox.exe -noconsole -noautoexec -c "mount C: D:\DOS" -c C:\TestGr.exe -c exit

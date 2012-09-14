..\Bin\smartlinkrel Basic.c
@FOR %%i IN (Basic_0??.c) DO ..\Bin\sdcc -c -mz80 --no-std-crt0 --opt-code-size --funsigned-char --disable-warning 59 --disable-warning 85 -L z80 %%i

@IF EXIST Basic.lib DEL Basic.lib
REM @FOR %%i IN (Basic_0??.rel) DO ..\Bin\sdcclib Basic.lib %%i
@FOR %%i IN (Basic_0??.rel) DO ..\Bin\sdar -rc Basic.lib %%i

@MOVE /Y Basic.lib z80/Basic.lib

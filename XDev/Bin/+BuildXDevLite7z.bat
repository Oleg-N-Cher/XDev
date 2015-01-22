@CD ..\..
Bin\7z.exe u -ssc -x@XDev\Bin\XDevLite-.lst XDevLite @XDev\Bin\XDevLite+.lst
@IF errorlevel 1 PAUSE

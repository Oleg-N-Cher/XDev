@CD ..\..
Bin\7z.exe u -ssc -x@XDev\Bin\XDevFull-.lst XDevFull @XDev\Bin\XDevFull+.lst
@IF errorlevel 1 PAUSE

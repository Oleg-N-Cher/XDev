@CD ..\..
Bin\7z.exe u -ssc -x@XDev\Bin\XDevFull+Src-.lst XDevFull+Src @XDev\Bin\XDevFull+Src+.lst
@IF errorlevel 1 PAUSE

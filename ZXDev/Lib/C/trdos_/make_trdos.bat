@SET LIB=..\..\trdos.lib
@SET SDCC=..\..\..\Bin\sdcc.exe -mz80 -c -Wa -g
@SET SDAR=..\..\..\Bin\sdar.exe

IF EXIST %LIB% DEL %LIB%

%SDCC% trdosIsDisk.c --disable-warning 59
%SDCC% trdosInit.c
%SDCC% trdosDiskTune.c
%SDCC% trdosDriveSel.c
%SDCC% trdosFindFile.c
%SDCC% trdosLoadFile.c
%SDCC% trdosReadFileDSP.c
%SDCC% trdosReadSectors.c

%SDCC% trdosWriteFile.c
%SDCC% trdosEraseFile.c
%SDCC% trdosWriteFileDSP.c
%SDCC% trdosWriteSectors.c

DEL *.asm
DEL *.sym
DEL *.lst

%sdar% m %LIB%
%sdar% -rc %LIB% trdosIsDisk.rel ^
		trdosInit.rel trdosDriveSel.rel trdosFindFile.rel trdosLoadFile.rel trdosReadFileDSP.rel trdosReadSectors.rel ^
		trdosWriteFile.rel trdosWriteFileDSP.rel trdosWriteSectors.rel trdosDiskTune.rel trdosEraseFile.rel
		
DEL *.rel

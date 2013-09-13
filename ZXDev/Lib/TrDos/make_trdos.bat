del trdos.lib
sdcc -mz80 -c -Wa -g trdosInit.c
sdcc -mz80 -c -Wa -g trdosDiskTune.c
sdcc -mz80 -c -Wa -g trdosDriveSel.c
sdcc -mz80 -c -Wa -g trdosFindFile.c
sdcc -mz80 -c -Wa -g trdosLoadFile.c
sdcc -mz80 -c -Wa -g trdosReadFileDSP.c
sdcc -mz80 -c -Wa -g trdosReadSectors.c

sdcc -mz80 -c -Wa -g trdosWriteFile.c
sdcc -mz80 -c -Wa -g trdosEraseFile.c
sdcc -mz80 -c -Wa -g trdosWriteFileDSP.c
sdcc -mz80 -c -Wa -g trdosWriteSectors.c

del *.asm
del *.sym
del *.lst

sdar m trdos.lib
sdar -rc trdos.lib ^
		trdosInit.rel trdosDriveSel.rel trdosFindFile.rel trdosLoadFile.rel trdosReadFileDSP.rel trdosReadSectors.rel ^
		trdosWriteFile.rel trdosWriteFileDSP.rel. trdosWriteSectors.rel trdosDiskTune.rel trdosEraseFile.rel
		
del *.rel

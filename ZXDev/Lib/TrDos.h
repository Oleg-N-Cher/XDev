#ifndef TrDos__h
#define TrDos__h

#include "TrDos/trdos.h"

#define TrDos_FDSP FDSP

#define TrDos_Init trdosInit
#define TrDos_DiskTune trdosDiskTune
#define TrDos_DriveSel trdosDriveSel
#define TrDos_FindFile(name, name__len, nameLen) trdosFindFile(name, nameLen)
#define TrDos_LoadFile(name, name__len, destPtr, fileDataLen) trdosLoadFile(name, destPtr, fileDataLen)
#define TrDos_ReadFileDSP trdosReadFileDSP
#define TrDos_ReadSectors trdosReadSectors

#define TrDos_WriteFile(name, name__len, dataPtr, dataLen) trdosWriteFile(name, dataPtr, dataLen)
#define TrDos_EraseFile(name, name__len) trdosEraseFile(name)
#define TrDos_WriteFileDSP trdosWriteFileDSP
#define TrDos_WriteSectors trdosWriteSectors

#define TrDos__init trdosInit

#endif

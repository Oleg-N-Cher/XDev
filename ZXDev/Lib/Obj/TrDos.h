/*  Ofront 1.2 -xtspkae */

#ifndef TrDos__h
#define TrDos__h

#include "SYSTEM.h"

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *TrDos_UCHARPTR;

typedef
	struct TrDos_FDSP {
		CHAR trFName[9];
		TrDos_UCHARPTR trFStart;
		INTEGER trFByteLen;
		CHAR trFSectLen, trFSector, trFTrack;
	} TrDos_FDSP;



import LONGINT *TrDos_FDSP__typ;

import void TrDos_DiskTune (void);
import void TrDos_DriveSel (CHAR driveLetter);
import void TrDos_EraseFile (CHAR *name, LONGINT name__len);
import CHAR TrDos_FindFile (CHAR *name, LONGINT name__len, CHAR nameLen);
import void TrDos_Init (void);
import void TrDos_LoadFile (CHAR *name, LONGINT name__len, TrDos_UCHARPTR destPtr, INTEGER fileDataLen);
import void TrDos_ReadFileDSP (TrDos_UCHARPTR destPtr, CHAR fileNumber);
import void TrDos_ReadSectors (TrDos_UCHARPTR destPtr, CHAR trackPos, CHAR sectorPos, CHAR LenInSectors);
import void TrDos_WriteFile (CHAR *name, LONGINT name__len, TrDos_UCHARPTR dataPtr, INTEGER dataLen);
import void TrDos_WriteFileDSP (TrDos_UCHARPTR srctPtr, CHAR fileNumber);
import void TrDos_WriteSectors (TrDos_UCHARPTR srctPtr, CHAR trackPos, CHAR sectorPos, CHAR LenInSectors);
import void *TrDos__init(void);


#endif

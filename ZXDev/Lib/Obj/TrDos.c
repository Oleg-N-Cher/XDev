/*  Ofront 1.2 -xtspkae */
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



export LONGINT *TrDos_FDSP__typ;

export void TrDos_DiskTune (void);
export void TrDos_DriveSel (CHAR driveLetter);
export void TrDos_EraseFile (CHAR *name, LONGINT name__len);
export CHAR TrDos_FindFile (CHAR *name, LONGINT name__len, CHAR nameLen);
export void TrDos_Init (void);
export void TrDos_LoadFile (CHAR *name, LONGINT name__len, TrDos_UCHARPTR destPtr, INTEGER fileDataLen);
export void TrDos_ReadFileDSP (TrDos_UCHARPTR destPtr, CHAR fileNumber);
export void TrDos_ReadSectors (TrDos_UCHARPTR destPtr, CHAR trackPos, CHAR sectorPos, CHAR LenInSectors);
export void TrDos_ReadSectors2 (TrDos_UCHARPTR srctPtr, CHAR trackPos, CHAR sectorPos, CHAR LenInSectors);
export void TrDos_WriteFile (CHAR *name, LONGINT name__len, TrDos_UCHARPTR dataPtr, INTEGER dataLen);
export void TrDos_WriteFileDSP (TrDos_UCHARPTR srctPtr, CHAR fileNumber);


void TrDos_DriveSel (CHAR driveLetter)
{
}

void TrDos_Init (void)
{
}

void TrDos_DiskTune (void)
{
}

void TrDos_ReadSectors (TrDos_UCHARPTR destPtr, CHAR trackPos, CHAR sectorPos, CHAR LenInSectors)
{
}

void TrDos_ReadFileDSP (TrDos_UCHARPTR destPtr, CHAR fileNumber)
{
}

void TrDos_ReadSectors2 (TrDos_UCHARPTR srctPtr, CHAR trackPos, CHAR sectorPos, CHAR LenInSectors)
{
}

void TrDos_WriteFileDSP (TrDos_UCHARPTR srctPtr, CHAR fileNumber)
{
}

CHAR TrDos_FindFile (CHAR *name, LONGINT name__len, CHAR nameLen)
{
	__RETCHK;
}

void TrDos_WriteFile (CHAR *name, LONGINT name__len, TrDos_UCHARPTR dataPtr, INTEGER dataLen)
{
}

void TrDos_EraseFile (CHAR *name, LONGINT name__len)
{
}

void TrDos_LoadFile (CHAR *name, LONGINT name__len, TrDos_UCHARPTR destPtr, INTEGER fileDataLen)
{
}

__TDESC(TrDos_FDSP__desc, 1, 0) = {__TDFLDS("FDSP", 18), {-4}};

export void *TrDos__init(void)
{
	__DEFMOD;
	__REGMOD("TrDos", 0);
	__REGCMD("DiskTune", TrDos_DiskTune);
	__REGCMD("Init", TrDos_Init);
	__INITYP(TrDos_FDSP, TrDos_FDSP, 0);
/* BEGIN */
	__ENDMOD;
}

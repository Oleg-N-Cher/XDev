/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "KolFiles.h"
#include "KolObj.h"
#include "KolRegistry.h"
#include "KolStrings.h"
#include "KolTypes.h"
#include "KolWindows.h"




export BOOLEAN Kol_ExtractFileName (CHAR *path, LONGINT path__len, CHAR *name, LONGINT name__len);
export BOOLEAN Kol_ExtractFilePath (CHAR *path, LONGINT path__len, CHAR *res, LONGINT res__len);


/*============================================================================*/

BOOLEAN Kol_ExtractFileName (CHAR *path, LONGINT path__len, CHAR *name, LONGINT name__len)
{
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
BOOLEAN Kol_ExtractFilePath (CHAR *path, LONGINT path__len, CHAR *res, LONGINT res__len)
{
	__RETCHK;
}

/*----------------------------------------------------------------------------*/

export void *Kol__init(void)
{
	__DEFMOD;
	__IMPORT(KolFiles__init);
	__IMPORT(KolObj__init);
	__IMPORT(KolRegistry__init);
	__IMPORT(KolStrings__init);
	__IMPORT(KolTypes__init);
	__IMPORT(KolWindows__init);
	__REGMOD("Kol", 0);
/* BEGIN */
	__ENDMOD;
}

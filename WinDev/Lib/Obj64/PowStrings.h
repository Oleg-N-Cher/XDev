/*  Ofront 1.2 -xtspkae */

#ifndef PowStrings__h
#define PowStrings__h

#include "SYSTEM.h"

typedef
	CHAR *PowStrings_StringT;

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *PowStrings_String;




import void PowStrings_Append (CHAR *dest, LONGINT dest__len, CHAR *src, LONGINT src__len);
import void PowStrings_AppendChar (CHAR *dest, LONGINT dest__len, CHAR ch);
import void PowStrings_Copy (CHAR *source, LONGINT source__len, CHAR *dest, LONGINT dest__len, LONGINT pos, LONGINT n);
import void PowStrings_Delete (CHAR *t, LONGINT t__len, LONGINT pos, LONGINT n);
import void PowStrings_HexStr (LONGINT x, CHAR *t, LONGINT t__len);
import void PowStrings_Insert (CHAR *source, LONGINT source__len, CHAR *dest, LONGINT dest__len, LONGINT pos);
import void PowStrings_InsertChar (CHAR x, CHAR *t, LONGINT t__len, LONGINT pos);
import void PowStrings_LeftAlign (CHAR *t, LONGINT t__len, LONGINT n);
import LONGINT PowStrings_Length (CHAR *t, LONGINT t__len);
import LONGINT PowStrings_Pos (CHAR *pattern, LONGINT pattern__len, CHAR *t, LONGINT t__len, LONGINT start);
import LONGINT PowStrings_PosChar (CHAR x, CHAR *t, LONGINT t__len, LONGINT start);
import void PowStrings_RemoveLeadingSpaces (CHAR *t, LONGINT t__len);
import void PowStrings_RemoveTrailingSpaces (CHAR *t, LONGINT t__len);
import void PowStrings_ReverseStringT (CHAR *t, LONGINT t__len, LONGINT n);
import void PowStrings_RightAlign (CHAR *t, LONGINT t__len, LONGINT n);
import void PowStrings_Str (LONGINT x, CHAR *t, LONGINT t__len);
import void PowStrings_UpCase (CHAR *t, LONGINT t__len);
import CHAR PowStrings_UpCaseChar (CHAR x);
import LONGINT PowStrings_Val (CHAR *t, LONGINT t__len);
import INTEGER PowStrings_ValResult (CHAR *t, LONGINT t__len);
import void *PowStrings__init(void);

#define PowStrings__init()	/*-noinit*/

#endif

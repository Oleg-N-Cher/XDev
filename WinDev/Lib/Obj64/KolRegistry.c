/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Ignore.h"
#include "KolStrings.h"
#include "KolTypes.h"
#include "WinApi.h"




export void KolRegistry_Close (SYSTEM_PTR key);
export BOOLEAN KolRegistry_Delete (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
export BOOLEAN KolRegistry_Exists (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
export INTEGER KolRegistry_GetDw (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len);
export BOOLEAN KolRegistry_GetStrNoGC (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len, CHAR *result, LONGINT result__len);
export BOOLEAN KolRegistry_KeySetStr (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len, CHAR *value, LONGINT value__len);
export SYSTEM_PTR KolRegistry_OpenCreate (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
export SYSTEM_PTR KolRegistry_OpenRead (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
export SYSTEM_PTR KolRegistry_OpenWrite (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
export BOOLEAN KolRegistry_SetDw (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len, INTEGER value);

#define KolRegistry__init()	/*-noinit*/

/*============================================================================*/

SYSTEM_PTR KolRegistry_OpenRead (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len)
{
	SYSTEM_PTR result = NIL;
	if (WinApi_RegOpenKeyExA(key, (SYSTEM_PTR)((LONGINT)subKey), 0, 0x020019, &result) != 0) {
		result = NIL;
	}
	return result;
}

/*----------------------------------------------------------------------------*/
SYSTEM_PTR KolRegistry_OpenWrite (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len)
{
	SYSTEM_PTR result = NIL;
	if (WinApi_RegOpenKeyExA(key, (SYSTEM_PTR)((LONGINT)subKey), 0, 0x02001f, &result) != 0) {
		result = NIL;
	}
	return result;
}

/*----------------------------------------------------------------------------*/
SYSTEM_PTR KolRegistry_OpenCreate (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len)
{
	SYSTEM_PTR result = NIL;
	INTEGER dwDisp;
	if (WinApi_RegCreateKeyExA(key, (SYSTEM_PTR)((LONGINT)subKey), 0, NIL, 0x0, 0x0f003f, NIL, NIL, &result, &dwDisp) != 0) {
		result = NIL;
	}
	return result;
}

/*----------------------------------------------------------------------------*/
INTEGER KolRegistry_GetDw (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len)
{
	INTEGER dwType, dwSize, result;
	dwSize = 4;
	result = 0;
	if ((key == NIL || WinApi_RegQueryValueExA(key, (SYSTEM_PTR)((LONGINT)valueName), NIL, &dwType, (SYSTEM_PTR)((LONGINT)&result), &dwSize) != 0) || dwType != 4) {
		result = 0;
	}
	return result;
}

/*----------------------------------------------------------------------------*/
static struct GetStrNoGC__5 {
	SYSTEM_PTR *key;
	CHAR *valueName;
	LONGINT valueName__len;
	CHAR *result;
	LONGINT result__len;
	INTEGER *dwType, *dwSize;
	struct GetStrNoGC__5 *lnk;
} *GetStrNoGC__5_s;

static BOOLEAN Query__6 (void);

static BOOLEAN Query__6 (void)
{
	return WinApi_RegQueryValueExA(*GetStrNoGC__5_s->key, (SYSTEM_PTR)((LONGINT)GetStrNoGC__5_s->valueName), NIL, &*GetStrNoGC__5_s->dwType, (SYSTEM_PTR)((LONGINT)GetStrNoGC__5_s->result), &*GetStrNoGC__5_s->dwSize) == 0;
}

BOOLEAN KolRegistry_GetStrNoGC (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len, CHAR *result, LONGINT result__len)
{
	INTEGER dwType, dwSize;
	struct GetStrNoGC__5 _s;
	_s.key = &key;
	_s.valueName = (void*)valueName; _s.valueName__len = valueName__len;
	_s.result = (void*)result; _s.result__len = result__len;
	_s.dwType = &dwType;
	_s.dwSize = &dwSize;
	_s.lnk = GetStrNoGC__5_s;
	GetStrNoGC__5_s = &_s;
	result[0] = 0x00;
	if (key == NIL) {
		GetStrNoGC__5_s = _s.lnk;
		return 0;
	}
	dwSize = 0;
	if (!Query__6() || dwType != 1) {
		GetStrNoGC__5_s = _s.lnk;
		return 0;
	}
	if (result__len <= (LONGINT)dwSize && Query__6()) {
		GetStrNoGC__5_s = _s.lnk;
		return 1;
	}
	GetStrNoGC__5_s = _s.lnk;
	return 0;
}

/*----------------------------------------------------------------------------*/
BOOLEAN KolRegistry_SetDw (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len, INTEGER value)
{
	return key != NIL && WinApi_RegSetValueExA(key, (SYSTEM_PTR)((LONGINT)valueName), 0, 4, (SYSTEM_PTR)((LONGINT)&value), 4) == 0;
}

/*----------------------------------------------------------------------------*/
BOOLEAN KolRegistry_KeySetStr (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len, CHAR *value, LONGINT value__len)
{
	return key != NIL && WinApi_RegSetValueExA(key, (SYSTEM_PTR)((LONGINT)valueName), 0, 1, (SYSTEM_PTR)((LONGINT)value), KolStrings_Length(value, value__len) + 1) == 0;
}

/*----------------------------------------------------------------------------*/
void KolRegistry_Close (SYSTEM_PTR key)
{
	if (key != NIL) {
		Ignore_Int(WinApi_RegCloseKey(key));
	}
}

/*----------------------------------------------------------------------------*/
BOOLEAN KolRegistry_Delete (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len)
{
	BOOLEAN result;
	result = 0;
	if (key != NIL) {
		result = WinApi_RegDeleteKey(key, (SYSTEM_PTR)((LONGINT)subKey)) == 0;
	}
	return result;
}

/*----------------------------------------------------------------------------*/
BOOLEAN KolRegistry_Exists (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len)
{
	SYSTEM_PTR k = NIL;
	if (key == NIL) {
		return 0;
	}
	k = KolRegistry_OpenRead(key, subKey, subKey__len);
	if (k != NIL) {
		KolRegistry_Close(k);
	}
	return k != NIL;
}

/*----------------------------------------------------------------------------*/

export void *KolRegistry__init(void)
{
	__DEFMOD;
	__IMPORT(Ignore__init);
	__IMPORT(KolStrings__init);
	__IMPORT(KolTypes__init);
	__IMPORT(WinApi__init);
	__REGMOD("KolRegistry", 0);
/* BEGIN */
	__ENDMOD;
}

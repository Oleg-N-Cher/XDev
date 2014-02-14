/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"
#include "Platform.h"

typedef
	struct TstInPar_Struct {
		INTEGER a, b;
	} TstInPar_Struct;

typedef
	struct TstInPar_Struct1 {
		INTEGER a, b;
	} TstInPar_Struct1;

typedef
	TstInPar_Struct1 *TstInPar_Struct1Ptr;

typedef
	TstInPar_Struct *TstInPar_StructPtr;


static CHAR TstInPar_arr[50];
static struct {
	LONGINT len[1];
	CHAR data[1];
} *TstInPar_ptr;
static TstInPar_Struct TstInPar_struct;
static TstInPar_StructPtr TstInPar_structPtr;
static TstInPar_Struct1 TstInPar_struct1;
static TstInPar_Struct1Ptr TstInPar_struct1Ptr;

export LONGINT *TstInPar_Struct__typ;
export LONGINT *TstInPar_Struct1__typ;

export void TstInPar_Struct2 (TstInPar_Struct1 str);
export void TstInPar_StructCopy (TstInPar_Struct str);
export void TstInPar_StructIn (TstInPar_Struct *str, LONGINT *str__typ);
export void TstInPar_StructIn1 (TstInPar_Struct1 *str, LONGINT *str__typ);
export void TstInPar_StructVar (TstInPar_Struct *str, LONGINT *str__typ);
export void TstInPar_Write (CHAR *str, LONGINT str__len);
export void TstInPar_Write1 (CHAR *str, LONGINT str__len);
export void TstInPar_Write2 (CHAR *str, LONGINT str__len);
export void TstInPar_WriteIn (CHAR *str, LONGINT str__len);
export void TstInPar_WriteVar (CHAR *str, LONGINT str__len);


void TstInPar_Write (CHAR *str, LONGINT str__len)
{
	__DUP(str, str__len, CHAR);
	Console_WriteStr(str, str__len);
	__DEL(str);
}

void TstInPar_WriteIn (CHAR *str, LONGINT str__len)
{
	Console_WriteStr(str, str__len);
}

void TstInPar_Write1 (CHAR *str, LONGINT str__len)
{
	Console_WriteStr(str, str__len);
}

void TstInPar_Write2 (CHAR *str, LONGINT str__len)
{
	Console_WriteStr(str, str__len);
}

void TstInPar_WriteVar (CHAR *str, LONGINT str__len)
{
	Console_WriteStr(str, str__len);
	__COPY("bla-bla-bla", str, str__len);
}

void TstInPar_StructCopy (TstInPar_Struct str)
{
}

void TstInPar_StructIn (TstInPar_Struct *str, LONGINT *str__typ)
{
}

void TstInPar_StructIn1 (TstInPar_Struct1 *str, LONGINT *str__typ)
{
}

void TstInPar_Struct2 (TstInPar_Struct1 str)
{
}

void TstInPar_StructVar (TstInPar_Struct *str, LONGINT *str__typ)
{
}

static void EnumPtrs(void (*P)(void*))
{
	P(TstInPar_ptr);
	P(TstInPar_structPtr);
	P(TstInPar_struct1Ptr);
}

__TDESC(TstInPar_Struct__desc, 1, 0) = {__TDFLDS("Struct", 4), {-4}};
__TDESC(TstInPar_Struct1__desc, 1, 0) = {__TDFLDS("Struct1", 4), {-4}};

export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(Platform__init);
	__REGMAIN("TstInPar", EnumPtrs);
	__INITYP(TstInPar_Struct, TstInPar_Struct, 0);
	__INITYP(TstInPar_Struct1, TstInPar_Struct1, 0);
/* BEGIN */
	TstInPar_Write((CHAR*)"Bla-bla-bla", (LONGINT)12);
	TstInPar_WriteIn((void*)&"Bla-bla-bla", (LONGINT)12);
	TstInPar_WriteIn((void*)&"a", (LONGINT)2);
	TstInPar_Write1((void*)&"Bla-bla-bla", (LONGINT)12);
	TstInPar_Write2((CHAR*)"Bla-bla-bla", (LONGINT)12);
	__COPY("Array", TstInPar_arr, 50);
	TstInPar_Write(TstInPar_arr, 50);
	TstInPar_WriteIn((void*)TstInPar_arr, 50);
	TstInPar_WriteIn((void*)TstInPar_arr, 50);
	TstInPar_Write1((void*)TstInPar_arr, 50);
	TstInPar_Write2(TstInPar_arr, 50);
	TstInPar_WriteVar((void*)TstInPar_arr, 50);
	TstInPar_ptr = __NEWARR(NIL, 1, 1, 1, 1, 100);
	__COPY("Pointer", TstInPar_ptr->data, TstInPar_ptr->len[0]);
	TstInPar_Write(TstInPar_ptr->data, TstInPar_ptr->len[0]);
	TstInPar_WriteIn((void*)TstInPar_ptr->data, TstInPar_ptr->len[0]);
	TstInPar_WriteIn((void*)TstInPar_ptr->data, TstInPar_ptr->len[0]);
	TstInPar_Write1((void*)TstInPar_ptr->data, TstInPar_ptr->len[0]);
	TstInPar_Write2(TstInPar_ptr->data, TstInPar_ptr->len[0]);
	TstInPar_WriteVar((void*)TstInPar_ptr->data, TstInPar_ptr->len[0]);
	Platform_DISPOSE((void*)&TstInPar_ptr);
	__FINI;
}

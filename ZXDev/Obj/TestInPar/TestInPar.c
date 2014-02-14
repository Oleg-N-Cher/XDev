/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"
#include "Platform.h"

typedef
	struct TestInPar_Struct {
		INTEGER a, b;
	} TestInPar_Struct;

typedef
	struct TestInPar_Struct1 {
		INTEGER a, b;
	} TestInPar_Struct1;

typedef
	TestInPar_Struct1 *TestInPar_Struct1Ptr;

typedef
	TestInPar_Struct *TestInPar_StructPtr;


static CHAR TestInPar_arr[50];
static struct {
	LONGINT len[1];
	CHAR data[1];
} *TestInPar_ptr;
static TestInPar_Struct TestInPar_struct;
static TestInPar_StructPtr TestInPar_structPtr;
static TestInPar_Struct1 TestInPar_struct1;
static TestInPar_Struct1Ptr TestInPar_struct1Ptr;

export LONGINT *TestInPar_Struct__typ;
export LONGINT *TestInPar_Struct1__typ;

export void TestInPar_StructIn (TestInPar_Struct *str, LONGINT *str__typ);
export void TestInPar_StructIn1 (TestInPar_Struct1 *str, LONGINT *str__typ);
export void TestInPar_StructVar (TestInPar_Struct *str, LONGINT *str__typ);
export void TestInPar_Write (CHAR *str, LONGINT str__len);
export void TestInPar_Write1 (CHAR *str, LONGINT str__len);
export void TestInPar_Write2 (CHAR *str, LONGINT str__len);
export void TestInPar_WriteIn (CHAR *str, LONGINT str__len);
export void TestInPar_WriteVar (CHAR *str, LONGINT str__len);


void TestInPar_Write (CHAR *str, LONGINT str__len)
{
	__DUP(str, str__len, CHAR);
	Console_WriteStr(str, str__len);
	__DEL(str);
}

void TestInPar_WriteIn (CHAR *str, LONGINT str__len)
{
	Console_WriteStr(str, str__len);
}

void TestInPar_Write1 (CHAR *str, LONGINT str__len)
{
	Console_WriteStr(str, str__len);
}

void TestInPar_Write2 (CHAR *str, LONGINT str__len)
{
	Console_WriteStr(str, str__len);
}

void TestInPar_WriteVar (CHAR *str, LONGINT str__len)
{
	Console_WriteStr(str, str__len);
	__COPY("bla-bla-bla", str, str__len);
}

void TestInPar_StructIn (TestInPar_Struct *str, LONGINT *str__typ)
{
}

void TestInPar_StructIn1 (TestInPar_Struct1 *str, LONGINT *str__typ)
{
}

void TestInPar_StructVar (TestInPar_Struct *str, LONGINT *str__typ)
{
}

static void EnumPtrs(void (*P)(void*))
{
	P(TestInPar_ptr);
	P(TestInPar_structPtr);
	P(TestInPar_struct1Ptr);
}

__TDESC(TestInPar_Struct__desc, 1, 0) = {__TDFLDS("Struct", 4), {-4}};
__TDESC(TestInPar_Struct1__desc, 1, 0) = {__TDFLDS("Struct1", 4), {-4}};

export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(Platform__init);
	__REGMAIN("TestInPar", EnumPtrs);
	__INITYP(TestInPar_Struct, TestInPar_Struct, 0);
	__INITYP(TestInPar_Struct1, TestInPar_Struct1, 0);
/* BEGIN */
	TestInPar_Write((CHAR*)"Bla-bla-bla", (LONGINT)12);
	TestInPar_WriteIn((void*)&"Bla-bla-bla", (LONGINT)12);
	TestInPar_WriteIn((void*)&"a", (LONGINT)2);
	TestInPar_Write1((void*)&"Bla-bla-bla", (LONGINT)12);
	TestInPar_Write2((CHAR*)"Bla-bla-bla", (LONGINT)12);
	__COPY("Array", TestInPar_arr, 50);
	TestInPar_Write(TestInPar_arr, 50);
	TestInPar_WriteIn((void*)TestInPar_arr, 50);
	TestInPar_WriteIn((void*)TestInPar_arr, 50);
	TestInPar_Write1((void*)TestInPar_arr, 50);
	TestInPar_Write2(TestInPar_arr, 50);
	TestInPar_WriteVar((void*)TestInPar_arr, 50);
	TestInPar_ptr = __NEWARR(NIL, 1, 1, 1, 1, 100);
	__COPY("Pointer", TestInPar_ptr->data, TestInPar_ptr->len[0]);
	TestInPar_Write(TestInPar_ptr->data, TestInPar_ptr->len[0]);
	TestInPar_WriteIn((void*)TestInPar_ptr->data, TestInPar_ptr->len[0]);
	TestInPar_WriteIn((void*)TestInPar_ptr->data, TestInPar_ptr->len[0]);
	TestInPar_Write1((void*)TestInPar_ptr->data, TestInPar_ptr->len[0]);
	TestInPar_Write2(TestInPar_ptr->data, TestInPar_ptr->len[0]);
	TestInPar_WriteVar((void*)TestInPar_ptr->data, TestInPar_ptr->len[0]);
	__FINI;
}

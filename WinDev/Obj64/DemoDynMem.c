/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"
#include "Platform.h"

typedef
	struct DemoDynMem_Person *DemoDynMem_PersonPtr;

typedef
	struct DemoDynMem_Person {
		CHAR name[20];
		INTEGER age;
		CHAR sex;
		DemoDynMem_PersonPtr next;
	} DemoDynMem_Person;


static DemoDynMem_PersonPtr DemoDynMem_john, DemoDynMem_mike, DemoDynMem_lisa, DemoDynMem_bob, DemoDynMem_iren, DemoDynMem_person;
static DemoDynMem_PersonPtr (*DemoDynMem_list)[5];
static INTEGER DemoDynMem_n;

export LONGINT *DemoDynMem_Person__typ;



/*============================================================================*/

static void EnumPtrs(void (*P)(void*))
{
	P(DemoDynMem_john);
	P(DemoDynMem_mike);
	P(DemoDynMem_lisa);
	P(DemoDynMem_bob);
	P(DemoDynMem_iren);
	P(DemoDynMem_person);
	P(DemoDynMem_list);
}

__TDESC(DemoDynMem_Person__desc, 1, 1) = {__TDFLDS("Person", 40), {32, -16}};

export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(Platform__init);
	__REGMAIN("DemoDynMem", EnumPtrs);
	__INITYP(DemoDynMem_Person, DemoDynMem_Person, 0);
/* BEGIN */
	__NEW(DemoDynMem_john, DemoDynMem_Person);
	__NEW(DemoDynMem_mike, DemoDynMem_Person);
	__NEW(DemoDynMem_lisa, DemoDynMem_Person);
	__NEW(DemoDynMem_bob, DemoDynMem_Person);
	__NEW(DemoDynMem_iren, DemoDynMem_Person);
	__MOVE("John Smith", DemoDynMem_john->name, 11);
	DemoDynMem_john->sex = 'M';
	DemoDynMem_john->age = 32;
	DemoDynMem_john->next = DemoDynMem_bob;
	__MOVE("Michael Bison", DemoDynMem_mike->name, 14);
	DemoDynMem_mike->sex = 'M';
	DemoDynMem_mike->age = 12;
	DemoDynMem_mike->next = DemoDynMem_lisa;
	__MOVE("Elisabeth Bow", DemoDynMem_lisa->name, 14);
	DemoDynMem_lisa->sex = 'F';
	DemoDynMem_lisa->age = 21;
	DemoDynMem_lisa->next = NIL;
	__MOVE("Boris Fellow", DemoDynMem_bob->name, 13);
	DemoDynMem_bob->sex = 'M';
	DemoDynMem_bob->age = 39;
	DemoDynMem_bob->next = DemoDynMem_iren;
	__MOVE("Iren Summer", DemoDynMem_iren->name, 12);
	DemoDynMem_iren->sex = 'F';
	DemoDynMem_iren->age = 43;
	DemoDynMem_iren->next = DemoDynMem_mike;
	DemoDynMem_person = DemoDynMem_john;
	Console_WriteStrLn((CHAR*)"Female:", (LONGINT)8);
	while (DemoDynMem_person != NIL) {
		if (DemoDynMem_person->sex == 'F') {
			Console_WriteStrLn(DemoDynMem_person->name, 20);
		}
		DemoDynMem_person = DemoDynMem_person->next;
	}
	Console_WriteLn();
	DemoDynMem_list = __NEWARR(POINTER__typ, 8, 8, 1, 0, 5);
	(*DemoDynMem_list)[0] = DemoDynMem_john;
	(*DemoDynMem_list)[1] = DemoDynMem_mike;
	(*DemoDynMem_list)[2] = DemoDynMem_lisa;
	(*DemoDynMem_list)[3] = DemoDynMem_bob;
	(*DemoDynMem_list)[4] = DemoDynMem_iren;
	DemoDynMem_n = 4;
	while (DemoDynMem_n >= 0) {
		Console_WriteStrLn((*DemoDynMem_list)[__X(DemoDynMem_n, 5)]->name, 20);
		Console_WriteCh((*DemoDynMem_list)[__X(DemoDynMem_n, 5)]->sex);
		Console_WriteLn();
		Console_WriteInt((*DemoDynMem_list)[__X(DemoDynMem_n, 5)]->age);
		Console_WriteLn();
		Console_WriteLn();
		Platform_DISPOSE((void*)&(*DemoDynMem_list)[__X(DemoDynMem_n, 5)]);
		DemoDynMem_n += -1;
	}
	Platform_DISPOSE((void*)&DemoDynMem_list);
	__FINI;
}

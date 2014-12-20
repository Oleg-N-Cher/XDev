/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "Console.h"

typedef
	struct DemoStatMem_Person *DemoStatMem_PersonPtr;

typedef
	struct DemoStatMem_Person {
		CHAR name[20];
		INTEGER age;
		CHAR sex;
		DemoStatMem_PersonPtr next;
	} DemoStatMem_Person;


static DemoStatMem_Person DemoStatMem_john, DemoStatMem_mike, DemoStatMem_lisa, DemoStatMem_bob, DemoStatMem_iren;
static DemoStatMem_PersonPtr DemoStatMem_person;
static DemoStatMem_PersonPtr DemoStatMem_list[5];
static INTEGER DemoStatMem_n;

export LONGINT *DemoStatMem_Person__typ;



/*============================================================================*/

__TDESC(DemoStatMem_Person__desc, 1, 0) = {__TDFLDS("Person", 26), {-4}};

export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(Console__init);
	__REGMAIN("DemoStatMem", 0);
	__INITYP(DemoStatMem_Person, DemoStatMem_Person, 0);
/* BEGIN */
	__MOVE("John Smith", DemoStatMem_john.name, 11);
	DemoStatMem_john.sex = 'M';
	DemoStatMem_john.age = 32;
	DemoStatMem_john.next = (DemoStatMem_PersonPtr)((INTEGER)&DemoStatMem_bob);
	__MOVE("Michael Bison", DemoStatMem_mike.name, 14);
	DemoStatMem_mike.sex = 'M';
	DemoStatMem_mike.age = 12;
	DemoStatMem_mike.next = (DemoStatMem_PersonPtr)((INTEGER)&DemoStatMem_lisa);
	__MOVE("Elisabeth Bow", DemoStatMem_lisa.name, 14);
	DemoStatMem_lisa.sex = 'F';
	DemoStatMem_lisa.age = 21;
	DemoStatMem_lisa.next = NIL;
	__MOVE("Boris Fellow", DemoStatMem_bob.name, 13);
	DemoStatMem_bob.sex = 'M';
	DemoStatMem_bob.age = 39;
	DemoStatMem_bob.next = (DemoStatMem_PersonPtr)((INTEGER)&DemoStatMem_iren);
	__MOVE("Iren Summer", DemoStatMem_iren.name, 12);
	DemoStatMem_iren.sex = 'F';
	DemoStatMem_iren.age = 43;
	DemoStatMem_iren.next = (DemoStatMem_PersonPtr)((INTEGER)&DemoStatMem_mike);
	DemoStatMem_person = (DemoStatMem_PersonPtr)((INTEGER)&DemoStatMem_john);
	Console_WriteStrLn((CHAR*)"Female:", (LONGINT)8);
	while (DemoStatMem_person != NIL) {
		if (DemoStatMem_person->sex == 'F') {
			Console_WriteStrLn(DemoStatMem_person->name, 20);
		}
		DemoStatMem_person = DemoStatMem_person->next;
	}
	Console_WriteLn();
	DemoStatMem_list[0] = (DemoStatMem_PersonPtr)((INTEGER)&DemoStatMem_john);
	DemoStatMem_list[1] = (DemoStatMem_PersonPtr)((INTEGER)&DemoStatMem_mike);
	DemoStatMem_list[2] = (DemoStatMem_PersonPtr)((INTEGER)&DemoStatMem_lisa);
	DemoStatMem_list[3] = (DemoStatMem_PersonPtr)((INTEGER)&DemoStatMem_bob);
	DemoStatMem_list[4] = (DemoStatMem_PersonPtr)((INTEGER)&DemoStatMem_iren);
	DemoStatMem_n = 4;
	while (DemoStatMem_n >= 0) {
		Console_WriteStr(DemoStatMem_list[__X(DemoStatMem_n, 5)]->name, 20);
		Console_WriteStr((CHAR*)"  ", (LONGINT)3);
		Console_WriteCh(DemoStatMem_list[__X(DemoStatMem_n, 5)]->sex);
		Console_WriteStr((CHAR*)"  ", (LONGINT)3);
		Console_WriteInt(DemoStatMem_list[__X(DemoStatMem_n, 5)]->age);
		Console_WriteLn();
		Console_WriteLn();
		DemoStatMem_n += -1;
	}
	Console_WriteStr((CHAR*)"Before POKE\'ing: ", (LONGINT)18);
	Console_WriteStrLn(DemoStatMem_john.name, 20);
	Basic_POKE((INTEGER)((INTEGER)&DemoStatMem_john.name[0]), 72);
	Basic_POKE((INTEGER)((INTEGER)&DemoStatMem_john.name[1]), 97);
	__PUT((INTEGER)&DemoStatMem_john.name[2], 'n', CHAR);
	__PUT((INTEGER)&DemoStatMem_john.name[3], 's', CHAR);
	Console_WriteStr((CHAR*)"After POKE\'ing: ", (LONGINT)17);
	Console_WriteStrLn(DemoStatMem_john.name, 20);
	__FINI;
}

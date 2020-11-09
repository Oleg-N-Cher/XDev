/* Ofront+ 1.0 -mx3 -21 */
#include "SYSTEM.oh"
#include "Console.oh"
#include "Platform.oh"

typedef
	struct DynMem_Person *DynMem_PersonPtr;

typedef
	struct DynMem_Person {
		CHAR name [20];
		SHORTINT age;
		CHAR sex;
		DynMem_PersonPtr next;
	} DynMem_Person;


static DynMem_PersonPtr DynMem_john, DynMem_mike, DynMem_lisa, DynMem_bob, DynMem_iren, DynMem_person;
static DynMem_PersonPtr (*DynMem_list) [5];
static SHORTINT DynMem_n;

export SYSTEM_ADRINT *DynMem_Person__typ;



/*============================================================================*/

static void EnumPtrs(void (*P)(void*))
{
	P(DynMem_john);
	P(DynMem_mike);
	P(DynMem_lisa);
	P(DynMem_bob);
	P(DynMem_iren);
	P(DynMem_person);
	P(DynMem_list);
}

__TDESC(DynMem_Person__desc, 2, 1) = {__TDFLDS("Person", 25), {23, -4}};

int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(Platform__init);
	__REGMAIN("DynMem", EnumPtrs);
	__INITYP(DynMem_Person, DynMem_Person, 0);
/* BEGIN */
	__NEW(DynMem_john, DynMem_Person);
	__NEW(DynMem_mike, DynMem_Person);
	__NEW(DynMem_lisa, DynMem_Person);
	__NEW(DynMem_bob, DynMem_Person);
	__NEW(DynMem_iren, DynMem_Person);
	__MOVE("John Smith", DynMem_john->name, 11);
	DynMem_john->sex = 'M';
	DynMem_john->age = 32;
	DynMem_john->next = DynMem_bob;
	__MOVE("Michael Bison", DynMem_mike->name, 14);
	DynMem_mike->sex = 'M';
	DynMem_mike->age = 12;
	DynMem_mike->next = DynMem_lisa;
	__MOVE("Elisabeth Bow", DynMem_lisa->name, 14);
	DynMem_lisa->sex = 'F';
	DynMem_lisa->age = 21;
	DynMem_lisa->next = NIL;
	__MOVE("Boris Fellow", DynMem_bob->name, 13);
	DynMem_bob->sex = 'M';
	DynMem_bob->age = 39;
	DynMem_bob->next = DynMem_iren;
	__MOVE("Iren Summer", DynMem_iren->name, 12);
	DynMem_iren->sex = 'F';
	DynMem_iren->age = 43;
	DynMem_iren->next = DynMem_mike;
	DynMem_person = DynMem_john;
	Console_WriteStrLn((CHAR*)"Female:", 8);
	while (DynMem_person != NIL) {
		if (DynMem_person->sex == 'F') {
			Console_WriteStrLn((void*)DynMem_person->name, 20);
		}
		DynMem_person = DynMem_person->next;
	}
	Console_WriteLn();
	DynMem_list = __NEWARR(POINTER__typ, 2, 1, 1, 0, (SYSTEM_ARRLEN)5);
	(*DynMem_list)[0] = DynMem_john;
	(*DynMem_list)[1] = DynMem_mike;
	(*DynMem_list)[2] = DynMem_lisa;
	(*DynMem_list)[3] = DynMem_bob;
	(*DynMem_list)[4] = DynMem_iren;
	DynMem_n = 5;
	do {
		DynMem_n += -1;
		Console_WriteStrLn((void*)(*DynMem_list)[DynMem_n]->name, 20);
		Console_WriteCh((*DynMem_list)[DynMem_n]->sex);
		Console_WriteLn();
		Console_WriteInt((*DynMem_list)[DynMem_n]->age);
		Console_WriteLn();
		Console_WriteLn();
		Platform_DISPOSE((void*)&(*DynMem_list)[DynMem_n]);
	} while (DynMem_n);
	Platform_DISPOSE((void*)&DynMem_list);
	__FINI;
}

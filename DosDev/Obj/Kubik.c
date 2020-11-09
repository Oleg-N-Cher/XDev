/* Ofront+ 1.0 -mx3 -21 */
#include "SYSTEM.oh"
#include "Console.oh"
#include "Math.oh"


static SHORTINT Kubik_one, Kubik_two, Kubik_three, Kubik_four, Kubik_five, Kubik_six, Kubik_n, Kubik_number, Kubik__for__1;




/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(Math__init);
	__REGMAIN("Kubik", 0);
/* BEGIN */
	Math_Randomize();
	Kubik_one = 0;
	Kubik_two = 0;
	Kubik_three = 0;
	Kubik_four = 0;
	Kubik_five = 0;
	Kubik_six = 0;
	Kubik_n = 1;
	Kubik__for__1 = 1000;
	do {
		Kubik_number = Math_RndRange(1, 6);
		if (Kubik_number == 1) {
			Kubik_one = Kubik_one + 1;
		}
		if (Kubik_number == 2) {
			Kubik_two = Kubik_two + 1;
		}
		if (Kubik_number == 3) {
			Kubik_three = Kubik_three + 1;
		}
		if (Kubik_number == 4) {
			Kubik_four = Kubik_four + 1;
		}
		if (Kubik_number == 5) {
			Kubik_five = Kubik_five + 1;
		}
		if (Kubik_number == 6) {
			Kubik_six = Kubik_six + 1;
		}
		Kubik_n += 1;
	} while (--Kubik__for__1);
	Console_SetColors(3);
	Console_WriteStr((CHAR*)"+---+------------+", 19);
	Console_WriteLn();
	Console_WriteStr((CHAR*)"| ", 3);
	Console_SetColors(4);
	Console_WriteInt(1);
	Console_SetColors(3);
	Console_WriteStr((CHAR*)" |            |", 16);
	Console_WriteLn();
	Console_WriteStr((CHAR*)"+---+------------+", 19);
	Console_WriteLn();
	Console_WriteStr((CHAR*)"| ", 3);
	Console_SetColors(14);
	Console_WriteInt(2);
	Console_SetColors(3);
	Console_WriteStr((CHAR*)" |            |", 16);
	Console_WriteLn();
	Console_WriteStr((CHAR*)"+---+------------+", 19);
	Console_WriteLn();
	Console_WriteStr((CHAR*)"| ", 3);
	Console_SetColors(2);
	Console_WriteInt(3);
	Console_SetColors(3);
	Console_WriteStr((CHAR*)" |            |", 16);
	Console_WriteLn();
	Console_WriteStr((CHAR*)"+---+------------+", 19);
	Console_WriteLn();
	Console_WriteStr((CHAR*)"| ", 3);
	Console_SetColors(5);
	Console_WriteInt(4);
	Console_SetColors(3);
	Console_WriteStr((CHAR*)" |            |", 16);
	Console_WriteLn();
	Console_WriteStr((CHAR*)"+---+------------+", 19);
	Console_WriteLn();
	Console_WriteStr((CHAR*)"| ", 3);
	Console_SetColors(1);
	Console_WriteInt(5);
	Console_SetColors(3);
	Console_WriteStr((CHAR*)" |            |", 16);
	Console_WriteLn();
	Console_WriteStr((CHAR*)"+---+------------+", 19);
	Console_WriteLn();
	Console_WriteStr((CHAR*)"| ", 3);
	Console_SetColors(7);
	Console_WriteInt(6);
	Console_SetColors(3);
	Console_WriteStr((CHAR*)" |            |", 16);
	Console_WriteLn();
	Console_WriteStr((CHAR*)"+---+------------+", 19);
	Console_At(10, 1);
	Console_SetColors(4);
	Console_WriteInt(Kubik_one);
	Console_At(10, 3);
	Console_SetColors(14);
	Console_WriteInt(Kubik_two);
	Console_At(10, 5);
	Console_SetColors(2);
	Console_WriteInt(Kubik_three);
	Console_At(10, 7);
	Console_SetColors(5);
	Console_WriteInt(Kubik_four);
	Console_At(10, 9);
	Console_SetColors(1);
	Console_WriteInt(Kubik_five);
	Console_At(10, 11);
	Console_SetColors(7);
	Console_WriteInt(Kubik_six);
	Console_WriteLn();
	Console_WriteLn();
	Console_WriteLn();
	__FINI;
}

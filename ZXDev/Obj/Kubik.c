/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"


static INTEGER Kubik_one, Kubik_two, Kubik_three, Kubik_four, Kubik_five, Kubik_six, Kubik_n, Kubik_number, Kubik__for__1;





export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic);
	__REGMAIN("Kubik", 0);
/* BEGIN */
	Basic_RANDOMIZE(0);
	Kubik_one = 0;
	Kubik_two = 0;
	Kubik_three = 0;
	Kubik_four = 0;
	Kubik_five = 0;
	Kubik_six = 0;
	Kubik_n = 1;
	Kubik__for__1 = 1000;
	Kubik__for__1 = (Kubik__for__1 - Kubik_n) + 1;
	do {
		Kubik_number = Basic_RND(1, 6);
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
		Kubik__for__1 -= 1;
	} while (!(Kubik__for__1 == 0));
	Basic_BORDER(0);
	Basic_PAPER(0);
	Basic_INK(5);
	Basic_CLS();
	Basic_PRSTR((CHAR*)"+---+------------+", (LONGINT)19);
	Basic_PRLN();
	Basic_PRSTR((CHAR*)"| ", (LONGINT)3);
	Basic_INK(2);
	Basic_PRINT(1);
	Basic_INK(5);
	Basic_PRSTR((CHAR*)" |            |", (LONGINT)16);
	Basic_PRLN();
	Basic_PRSTR((CHAR*)"+---+------------+", (LONGINT)19);
	Basic_PRLN();
	Basic_PRSTR((CHAR*)"| ", (LONGINT)3);
	Basic_INK(6);
	Basic_PRINT(2);
	Basic_INK(5);
	Basic_PRSTR((CHAR*)" |            |", (LONGINT)16);
	Basic_PRLN();
	Basic_PRSTR((CHAR*)"+---+------------+", (LONGINT)19);
	Basic_PRLN();
	Basic_PRSTR((CHAR*)"| ", (LONGINT)3);
	Basic_INK(4);
	Basic_PRINT(3);
	Basic_INK(5);
	Basic_PRSTR((CHAR*)" |            |", (LONGINT)16);
	Basic_PRLN();
	Basic_PRSTR((CHAR*)"+---+------------+", (LONGINT)19);
	Basic_PRLN();
	Basic_PRSTR((CHAR*)"| ", (LONGINT)3);
	Basic_INK(3);
	Basic_PRINT(4);
	Basic_INK(5);
	Basic_PRSTR((CHAR*)" |            |", (LONGINT)16);
	Basic_PRLN();
	Basic_PRSTR((CHAR*)"+---+------------+", (LONGINT)19);
	Basic_PRLN();
	Basic_PRSTR((CHAR*)"| ", (LONGINT)3);
	Basic_INK(1);
	Basic_PRINT(5);
	Basic_INK(5);
	Basic_PRSTR((CHAR*)" |            |", (LONGINT)16);
	Basic_PRLN();
	Basic_PRSTR((CHAR*)"+---+------------+", (LONGINT)19);
	Basic_PRLN();
	Basic_PRSTR((CHAR*)"| ", (LONGINT)3);
	Basic_INK(7);
	Basic_PRINT(6);
	Basic_INK(5);
	Basic_PRSTR((CHAR*)" |            |", (LONGINT)16);
	Basic_PRLN();
	Basic_PRSTR((CHAR*)"+---+------------+", (LONGINT)19);
	Basic_AT(1, 10);
	Basic_INK(2);
	Basic_PRINT(Kubik_one);
	Basic_AT(3, 10);
	Basic_INK(6);
	Basic_PRINT(Kubik_two);
	Basic_AT(5, 10);
	Basic_INK(4);
	Basic_PRINT(Kubik_three);
	Basic_AT(7, 10);
	Basic_INK(3);
	Basic_PRINT(Kubik_four);
	Basic_AT(9, 10);
	Basic_INK(1);
	Basic_PRINT(Kubik_five);
	Basic_AT(11, 10);
	Basic_INK(7);
	Basic_PRINT(Kubik_six);
	__FINI;
}

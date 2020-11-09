/* Ofront+ 1.0 -mx3 -21 */
#include "SYSTEM.oh"
#include "Console.oh"


static SHORTINT ASCII_n, ASCII__for__1;




/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__REGMAIN("ASCII", 0);
/* BEGIN */
	ASCII_n = 32;
	ASCII__for__1 = 96;
	do {
		Console_WriteCh((CHAR)ASCII_n);
		ASCII_n += 1;
	} while (--ASCII__for__1);
	__FINI;
}

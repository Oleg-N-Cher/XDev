/* Ofront+ 1.0 -smC -48 */
#include "SYSTEM.h"
#include "Console.h"


static INTEGER ASCII_n;




/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__REGMAIN("ASCII", 0);
/* BEGIN */
	ASCII_n = 32;
	while (ASCII_n <= 127) {
		Console_WriteCh((CHAR)ASCII_n);
		ASCII_n += 1;
	}
	__FINI;
}

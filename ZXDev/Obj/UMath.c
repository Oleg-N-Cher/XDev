/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"


static SHORTINT UMath_a, UMath_b;



#define UMath_UDivBytes(a, b)	( ((CHAR)a) / ((CHAR)b) )
#define UMath_UDivWords(a, b)	(((unsigned int)a)/((unsigned int)b))
#define UMath_UMultBytes(a, b)	( ((CHAR)a) * ((CHAR)b) )
#define UMath_UMultWords(a, b)	(((unsigned int)a)*((unsigned int)b))

/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__REGMAIN("UMath", 0);
/* BEGIN */
	Basic_Init();
	Basic_CLS();
	UMath_a = (SHORTINT)255;
	UMath_b = (SHORTINT)255;
	Basic_PRWORD(UMath_UMultBytes(UMath_a, UMath_b));
	Basic_PRLN();
	Basic_PRWORD(UMath_a * UMath_b);
	Basic_PRLN();
	UMath_a = (SHORTINT)255;
	UMath_b = 5;
	Basic_PRWORD(UMath_UDivBytes(UMath_a, UMath_b));
	Basic_PRLN();
	Basic_PRWORD(__DIV(UMath_a, UMath_b));
	Basic_Quit();
	__FINI;
}

/* Ofront+ 1.0 -sC -48 */
#include "SYSTEM.h"
#include "Ignore.h"
#include "Strings.h"
#include "WinAPI.h"


static INTEGER ConsoleWinAPI_hConOutput;


export void ConsoleWinAPI_SetColors (SHORTINT colors);
export void ConsoleWinAPI_WriteCh (CHAR ch);
export void ConsoleWinAPI_WriteInt (INTEGER n);
export void ConsoleWinAPI_WriteLn (void);
export void ConsoleWinAPI_WriteStr (CHAR *str, INTEGER str__len);


/*============================================================================*/

void ConsoleWinAPI_SetColors (SHORTINT colors)
{
	Ignore_Int(WinAPI_SetConsoleTextAttribute(ConsoleWinAPI_hConOutput, colors));
}

/*----------------------------------------------------------------------------*/
void ConsoleWinAPI_WriteCh (CHAR ch)
{
	INTEGER maxLen;
	Ignore_Int(WinAPI_WriteFile(ConsoleWinAPI_hConOutput, (SYSTEM_ADRINT)&ch, 1, &maxLen, NIL));
}

/*----------------------------------------------------------------------------*/
void ConsoleWinAPI_WriteLn (void)
{
	ConsoleWinAPI_WriteCh(0x0d);
	ConsoleWinAPI_WriteCh(0x0a);
}

/*----------------------------------------------------------------------------*/
void ConsoleWinAPI_WriteInt (INTEGER n)
{
	CHAR s[11];
	INTEGER i1, k;
	if (n == __LSHL(1, 31, INTEGER)) {
		__MOVE("8463847412", s, 11);
		k = 10;
	} else {
		i1 = __ABS(n);
		s[0] = (CHAR)((INTEGER)__MOD(i1, 10) + 48);
		i1 = __DIV(i1, 10);
		k = 1;
		while (i1 > 0) {
			s[__X(k, 11, "ConsoleWinAPI", -768)] = (CHAR)((INTEGER)__MOD(i1, 10) + 48);
			i1 = __DIV(i1, 10);
			k += 1;
		}
	}
	if (n < 0) {
		s[__X(k, 11, "ConsoleWinAPI", -832)] = '-';
		k += 1;
	}
	while (k > 0) {
		k -= 1;
		ConsoleWinAPI_WriteCh(s[__X(k, 11, "ConsoleWinAPI", -884)]);
	}
}

/*----------------------------------------------------------------------------*/
void ConsoleWinAPI_WriteStr (CHAR *str, INTEGER str__len)
{
	INTEGER maxLen;
	Ignore_Int(WinAPI_WriteFile(ConsoleWinAPI_hConOutput, (SYSTEM_ADRINT)str, Strings_Length((void*)str, str__len), &maxLen, NIL));
}

/*----------------------------------------------------------------------------*/

export void *ConsoleWinAPI__init(void)
{
	__DEFMOD;
	__IMPORT(Ignore__init);
	__IMPORT(Strings__init);
	__IMPORT(WinAPI__init);
	__REGMOD("ConsoleWinAPI", 0);
	__REGCMD("WriteLn", ConsoleWinAPI_WriteLn);
/* BEGIN */
	ConsoleWinAPI_hConOutput = WinAPI_GetStdHandle(-11);
	__ENDMOD;
}

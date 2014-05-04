/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrFonts.h"
#include "Input.h"
#include "Strings.h"
#include "Timer.h"




export void Console_At (INTEGER x, INTEGER y);
static void Console_BackPos (void);
export void Console_Clear (INTEGER attr);
export INTEGER Console_ReadInt (void);
export INTEGER Console_ReadIntRange (INTEGER min, INTEGER max);
export void Console_SetColors (INTEGER attr);
export void Console_SetFont (INTEGER font);
export void Console_WriteCh (CHAR ch);
export void Console_WriteInt (LONGINT i);
export void Console_WriteLn (void);
export void Console_WriteStr (CHAR *str, LONGINT str__len);
export void Console_WriteStrLn (CHAR *str, LONGINT str__len);


/*============================================================================*/

void Console_At (INTEGER x, INTEGER y)
{
}

/*----------------------------------------------------------------------------*/
void Console_Clear (INTEGER attr)
{
}

/*----------------------------------------------------------------------------*/
void Console_SetColors (INTEGER attr)
{
}

/*----------------------------------------------------------------------------*/
void Console_SetFont (INTEGER font)
{
}

/*----------------------------------------------------------------------------*/
void Console_WriteCh (CHAR ch)
{
}

/*----------------------------------------------------------------------------*/
void Console_WriteInt (LONGINT i)
{
}

/*----------------------------------------------------------------------------*/
void Console_WriteLn (void)
{
}

/*----------------------------------------------------------------------------*/
void Console_WriteStr (CHAR *str, LONGINT str__len)
{
	__DUP(str, str__len, CHAR);
	__DEL(str);
}

/*----------------------------------------------------------------------------*/
void Console_WriteStrLn (CHAR *str, LONGINT str__len)
{
	__DUP(str, str__len, CHAR);
	__DEL(str);
}

/*----------------------------------------------------------------------------*/
void Console_BackPos (void)
{
}

/*----------------------------------------------------------------------------*/
static struct ReadIntRange__5 {
	SHORTINT *digits;
	CHAR *ch;
	CHAR (*data)[8];
	struct ReadIntRange__5 *lnk;
} *ReadIntRange__5_s;

static void Accept__6 (void);

void Accept__6 (void)
{
	if (*ReadIntRange__5_s->digits < 8) {
		Console_WriteCh(*ReadIntRange__5_s->ch);
		(*ReadIntRange__5_s->data)[__X(*ReadIntRange__5_s->digits, 8)] = *ReadIntRange__5_s->ch;
		*ReadIntRange__5_s->digits += 1;
	}
}

/*----------------------------------------------------------------------------*/
INTEGER Console_ReadIntRange (INTEGER min, INTEGER max)
{
	SHORTINT i, digits;
	CHAR ch;
	CHAR data[8];
	INTEGER result;
	struct ReadIntRange__5 _s;
	_s.digits = &digits;
	_s.ch = &ch;
	_s.data = (void*)data;
	_s.lnk = ReadIntRange__5_s;
	ReadIntRange__5_s = &_s;
	digits = 0;
	for (;;) {
		for (;;) {
			Console_WriteCh('_');
			Console_BackPos();
			i = 25;
			while (i >= 1) {
				if (Input_Available() != 0) {
					Console_WriteCh(' ');
					Console_BackPos();
					goto exit__0;
				}
				Timer_Delay(10);
				i += -1;
			}
			Console_WriteCh(' ');
			Console_BackPos();
			i = 25;
			while (i >= 1) {
				if (Input_Available() != 0) {
					goto exit__0;
				}
				Timer_Delay(10);
				i += -1;
			}
		}
		exit__0:;
		ch = Input_Read();
		switch (ch) {
			case '-': 
				if (digits == 0 && min < 0) {
					Accept__6();
				}
				break;
			case '0': case '1': case '2': case '3': case '4': 
			case '5': case '6': case '7': case '8': case '9': 
				Accept__6();
				break;
			case 0x0c: 
				if (digits > 0) {
					digits -= 1;
					Console_BackPos();
					Console_WriteCh(' ');
					Console_BackPos();
				}
				break;
			case 0x0d: 
				if (digits > 0) {
					if (digits < 8) {
						data[__X(digits, 8)] = 0x00;
					}
					if ((Strings_StrToInt((void*)data, 8, &result) && result >= min) && result <= max) {
						ReadIntRange__5_s = _s.lnk;
						return result;
					}
				}
				break;
			default: 
				break;
		}
		i = 25;
		for (;;) {
			if (Input_Available() == 0 || i == 0) {
				break;
			}
			Timer_Delay(10);
			i -= 1;
		}
	}
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
INTEGER Console_ReadInt (void)
{
	return Console_ReadIntRange(-32768, 32767);
}

/*----------------------------------------------------------------------------*/

export void *Console__init(void)
{
	__DEFMOD;
	__IMPORT(GrFonts__init);
	__IMPORT(Input__init);
	__IMPORT(Strings__init);
	__IMPORT(Timer__init);
	__REGMOD("Console", 0);
	__REGCMD("WriteLn", Console_WriteLn);
/* BEGIN */
	__ENDMOD;
}

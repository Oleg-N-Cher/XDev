/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Asm.h"




export void GRAPHIC_Color (SHORTINT ForeGroundColor, SHORTINT BackGroudColor, SHORTINT BorderColor);
export void GRAPHIC_Pset (INTEGER Destination_x, INTEGER Destination_y, SHORTINT DestinationPage, SHORTINT Color, SHORTINT LogicalOperation);
export void GRAPHIC_Screen (SHORTINT mode);
export void GRAPHIC_SetColor (SHORTINT color);
export void GRAPHIC_Width (SHORTINT len);

#define GRAPHIC__init()	/*noinit*/

/*============================================================================*/

void GRAPHIC_Screen (SHORTINT mode)
{
	Asm_Code((CHAR*)"LD   HL, #2                   ", (LONGINT)31);
	Asm_Code((CHAR*)"ADD  HL, SP                   ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   A, (HL)       ; (mode)   ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   IY, (0xFCC0)  ;(EXPTBL-1)", (LONGINT)31);
	Asm_Code((CHAR*)"PUSH IX                       ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   IX, #0x005F   ; CHGMOD   ", (LONGINT)31);
	Asm_Code((CHAR*)"CALL 0x001C        ; CALSLT   ", (LONGINT)31);
	Asm_Code((CHAR*)"EI                            ", (LONGINT)31);
	Asm_Code((CHAR*)"POP IX                        ", (LONGINT)31);
}

/*----------------------------------------------------------------------------*/
void GRAPHIC_Width (SHORTINT len)
{
	Asm_Code((CHAR*)"LD   HL, #2                   ", (LONGINT)31);
	Asm_Code((CHAR*)"ADD  HL, SP                   ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   A, (HL)      ; (len)     ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   (0xF3AE), A  ; (LINL40)  ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   IY, (0xFCC0) ; (EXPTBL-1)", (LONGINT)31);
	Asm_Code((CHAR*)"PUSH IX                       ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   IX, #0x006C  ; INITXT    ", (LONGINT)31);
	Asm_Code((CHAR*)"CALL 0x001C       ; CALSLT    ", (LONGINT)31);
	Asm_Code((CHAR*)"POP IX                        ", (LONGINT)31);
	Asm_Code((CHAR*)"EI                            ", (LONGINT)31);
}

/*----------------------------------------------------------------------------*/
void GRAPHIC_Color (SHORTINT ForeGroundColor, SHORTINT BackGroudColor, SHORTINT BorderColor)
{
	Asm_Code((CHAR*)"LD   HL, #2                   ", (LONGINT)31);
	Asm_Code((CHAR*)"ADD  HL, SP                   ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   DE, #0xF3E9  ; (FORCLR)  ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   BC, #3       ; (BAKCLR)  ", (LONGINT)31);
	Asm_Code((CHAR*)"LDIR              ; (BDRCLR)  ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   IY, (0xFCC0) ; (EXPTBL-1)", (LONGINT)31);
	Asm_Code((CHAR*)"PUSH IX                       ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   IX, #0x0062  ; CHGCLR    ", (LONGINT)31);
	Asm_Code((CHAR*)"CALL 0x001C       ; CALSLT    ", (LONGINT)31);
	Asm_Code((CHAR*)"POP IX                        ", (LONGINT)31);
	Asm_Code((CHAR*)"EI                            ", (LONGINT)31);
}

/*----------------------------------------------------------------------------*/
void GRAPHIC_SetColor (SHORTINT color)
{
	Asm_Code((CHAR*)"LD   HL, #2                   ", (LONGINT)31);
	Asm_Code((CHAR*)"ADD  HL, SP                   ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   A, (HL)      ; (color)   ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   IY, (0xFCC0) ; (EXPTBL-1)", (LONGINT)31);
	Asm_Code((CHAR*)"PUSH IX                       ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   IX, #0x011A  ; SETATR    ", (LONGINT)31);
	Asm_Code((CHAR*)"CALL 0x001C       ; CALSLT    ", (LONGINT)31);
	Asm_Code((CHAR*)"EI                            ", (LONGINT)31);
	Asm_Code((CHAR*)"POP IX                        ", (LONGINT)31);
}

/*----------------------------------------------------------------------------*/
void GRAPHIC_Pset (INTEGER Destination_x, INTEGER Destination_y, SHORTINT DestinationPage, SHORTINT Color, SHORTINT LogicalOperation)
{
	Asm_Code((CHAR*)"DI                            ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   A, #0x20                 ", (LONGINT)31);
	Asm_Code((CHAR*)"OUT  (0x99), A                ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   A, #0x11                 ", (LONGINT)31);
	Asm_Code((CHAR*)"OR   #0x80                    ", (LONGINT)31);
	Asm_Code((CHAR*)"OUT  (0x99), A                ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   B, #0x0F                 ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   C, #0x9B                 ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   HL, #0xF562              ", (LONGINT)31);
	Asm_Code((CHAR*)"OTIR                          ", (LONGINT)31);
	Asm_Code((CHAR*)"LOC_40E8$:", (LONGINT)11);
	Asm_Code((CHAR*)"LD   A, #2                    ", (LONGINT)31);
	Asm_Code((CHAR*)"OUT  (0x99), A                ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   A, #0x0F                 ", (LONGINT)31);
	Asm_Code((CHAR*)"OR   #0x80                    ", (LONGINT)31);
	Asm_Code((CHAR*)"OUT  (0x99), A                ", (LONGINT)31);
	Asm_Code((CHAR*)"IN   A, (0x99)                ", (LONGINT)31);
	Asm_Code((CHAR*)"BIT  0, A                     ", (LONGINT)31);
	Asm_Code((CHAR*)"JR   NZ, LOC_40E8$            ", (LONGINT)31);
	Asm_Code((CHAR*)"XOR  A                        ", (LONGINT)31);
	Asm_Code((CHAR*)"OUT  (0x99), A                ", (LONGINT)31);
	Asm_Code((CHAR*)"LD   A, #0x8F                 ", (LONGINT)31);
	Asm_Code((CHAR*)"OUT  (0x63), A                ", (LONGINT)31);
}

/*----------------------------------------------------------------------------*/

export void *GRAPHIC__init(void)
{
	__DEFMOD;
	__IMPORT(Asm__init);
	__REGMOD("GRAPHIC", 0);
/* BEGIN */
	__ENDMOD;
}

/*************************/
/* ZX-BASIC 48k features */
/* Coded by Oleg N. Cher */
/*  zx.oberon2.ru/forum  */
/*************************/

#ifndef Basic__h
#define Basic__h

/*-------------------------- BORDER (color: Color) ---------------------------*/
extern void Basic_BORDER (unsigned char color);

/*--------------------------- COLOR (attr: UBYTE) ----------------------------*/
extern void Basic_COLOR (unsigned char atr);

/*------------------------ PRSTR (str: ARRAY OF CHAR) ------------------------*/
extern void Basic_PRSTR_C_ROM_stdcall (unsigned char *str);

#define Basic_PRSTR(str,len) Basic_PRSTR_C_ROM_stdcall(str)

#define Basic__init()

#endif

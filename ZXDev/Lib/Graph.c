#include "SYSTEM.h"
#include "Graph.h"

/*interface*/

export void Graph_ClearDevice (void);
export void Graph_CloseGraph (void);
export void Graph_InitGraph (INTEGER *GraphDriver, INTEGER *GraphMode, CHAR *PathToDriver, LONGINT PathToDriver__len);
//export void Graph_PutPixel (INTEGER x, INTEGER y);
export void Graph_PutPixel_ROM (INTEGER x, INTEGER y);
export void Graph_Line (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2);
export void Graph_SetBkColor (SHORTINT color);
export void Graph_SetColor (SHORTINT color);
export void Graph__init (void);

void BORDER (SHORTINT color);
void BRIGHT (SHORTINT mode);
void INVERSE (SHORTINT mode);
void INK (SHORTINT color);
void PAPER (SHORTINT color);

extern SHORTINT color, bkcolor;

/*implementation*/

/* Video temp attrib */
#define ATTR_T$ 0x5C8F
/* Set video attrib */
#define SETV_A$ 0x5C8D

/*================================== Header ==================================*/
SHORTINT color;
/*--------------------------------- Cut here ---------------------------------*/
SHORTINT bkcolor;
/*--------------------------------- Cut here ---------------------------------*/
export void Graph_InitGraph (INTEGER *GraphDriver, INTEGER *GraphMode, CHAR *PathToDriver, LONGINT PathToDriver__len)
{
  Graph__init();
}

/*--------------------------------- Cut here ---------------------------------*/
export void Graph_PutPixel_ROM (INTEGER x, INTEGER y)
{
__asm
#ifdef __SDCC
  LD   HL,#2
  ADD  HL,SP
  LD   C,(HL)  ; 7t
  INC  HL      ; 6t
  LD   A,(HL)
  OR   A
  RET  NZ
  INC  HL
  LD   B,(HL)
  INC  HL
  LD   A,(HL)
  OR   A
  RET  NZ
#else
  POP  AF
  LD   A,5(IX)
  OR   A
  RET  NZ
  LD   A,7(IX)
  OR   A
  RET  NZ
  LD   C,4(IX) ; 19t
  LD   B,6(IX)
#endif
  LD   IY,#0x5C3A
  LD   A,B
  CP   #0xC0
  RET  NC
  CALL #0x22B1
  JP   0x22EC
__endasm;
} //Graph_PutPixel_ROM

/*--------------------------------- Cut here ---------------------------------*/
//export void Graph_PutPixel (INTEGER x, INTEGER y)
//{
//  if( (x >= 0) & (x <= 255) & (y >= 0) & (y <= 191) )
//    Graph_PutPixel_ROM(x, y);
//} //Graph_PutPixel

/*--------------------------------- Cut here ---------------------------------*/
#define _TABLE 0xF000

#define DOWN_DE \
  LD   A,(HL) ;берем байт из фонта \
  LD   (DE),A ;и кладем в экран   \
  INC  HL     ;приращение fnt adr \
  INC  D      ;приращение scr adr

export void Graph_InitPixel (void)
{ /*
__asm
              ; (AlCo)
  LD HL,#_TABLE+256
  LD DE,#0x4000
GEN0$:
  LD (HL),D   ; |
  DEC H       ; |
  LD (HL),E   ; |
  INC H       ; |
  DOWN_DE     ; |1-я
  LD A,D      ; + и
  SUB #88     ; |2-я
  JR NZ,$+3   ; |
  LD D,A      ; |
  INC L       ; |
  JR NZ,GEN0$ ; |
  INC H
  LD A,#128
GEN1$:
  LD (HL),E  ¬
  INC H      ¦
  LD (HL),A  ¦
  DEC H      ¦3-я
  RRCA       + и
  JR NC,$+3  ¦4-я
  INC E      ¦
  INC L      ¦
  JR NZ,GEN1 -
__endasm; */
} //PutPixel

/*--------------------------------- Cut here ---------------------------------*/
static INTEGER Graph_GetSign (INTEGER x)
{
	if (x >= 0) return 1;
	return -1;
}

export void Graph_Line (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2)
{
	INTEGER dx, dy, sdx, sdy, x, y, px, py;
	dx = x2 - x1;
	dy = y2 - y1;
	sdx = Graph_GetSign(dx);
	sdy = Graph_GetSign(dy);
	dx = sdx * dx + 1;
	dy = sdy * dy + 1;
	x = 0;
	y = 0;
	px = x1;
	py = y1;
	if (dx >= dy) {
		while (x < dx) {
			Graph_PutPixel(px, py);
			y += dy;
			if (y >= dx) {
				y -= dx;
				py += sdy;
			}
			px += sdx;
			x += 1;
		}
	} else {
		while (y < dy) {
			Graph_PutPixel(px, py);
			x += dx;
			if (x >= dy) {
				x -= dy;
				px += sdx;
			}
			py += sdy;
			y += 1;
		}
	}
} //Graph_Line

/*--------------------------------- Cut here ---------------------------------*/
export void Graph_CloseGraph (void)
{
__asm
  LD   IY,#0x5C3A
  EI
  LD   BC,#0
  JP   0x1F3D
__endasm;
} //Graph_CloseGraph

/*--------------------------------- Cut here ---------------------------------*/
void INVERSE (SHORTINT mode)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   IY,#0x5C3A
  LD   A,#20
  RST  16 // IX-safe
  LD   A,4(IX)
  RST  16
  LD   A,(#ATTR_T$)
  LD   (#SETV_A$),A
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //INVERSE

/*--------------------------------- Cut here ---------------------------------*/
void INK (SHORTINT color)
{
__asm
#ifdef __SDCC
  LD   HL,#2
  ADD  HL,SP
  LD   C,(HL)
#else
  LD   C,4(IX)
#endif
  LD   A,(#ATTR_T$)
  AND  #0xF8
  OR   C
  LD   (#SETV_A$),A
  LD   (#ATTR_T$),A
__endasm;
} //INK

/*--------------------------------- Cut here ---------------------------------*/
void PAPER (SHORTINT color)
{
__asm
#ifdef __SDCC
  LD   HL,#2
  ADD  HL,SP
  LD   C,(HL)
#else
  LD   C,4(IX)
#endif
  LD   A,(#ATTR_T$)
  AND  #0xC7
  SLA  C
  SLA  C
  SLA  C
  OR   C
  LD   (#SETV_A$),A
  LD   (#ATTR_T$),A
__endasm;
} //PAPER

/*--------------------------------- Cut here ---------------------------------*/
void BORDER (SHORTINT color)
{
__asm
#ifdef __SDCC
  LD   HL,#2
  ADD  HL,SP
  LD   A,(HL)
#else
  LD   A,4(IX)
#endif
  CALL 0x229B // IX-safe
__endasm;
} //BORDER

/*--------------------------------- Cut here ---------------------------------*/
void BRIGHT (SHORTINT mode)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   IY,#0x5C3A
  LD   A,#19
  RST  16
  LD   A,4(IX)
  RST  16
  LD   A,(#ATTR_T$)
  LD   (#SETV_A$),A
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //BRIGHT

/*--------------------------------- Cut here ---------------------------------*/
export void Graph_SetBkColor (SHORTINT c)
{
  if(c == color)
    INVERSE(1);
  else
    {INVERSE(0); PAPER(c); BORDER(c);}
  bkcolor = c;
} //Graph_SetBkColor
/*--------------------------------- Cut here ---------------------------------*/
export void Graph_SetColor (SHORTINT c)
{
  if(c == bkcolor)
    INVERSE(1);
  else
    {INVERSE(0); INK(c);}
  color = c;
} //Graph_SetColor

/*--------------------------------- Cut here ---------------------------------*/
void Graph_ClearDevice (void)
{
__asm
  LD   IY,#0x5C3A
  LD   A,(#ATTR_T$)
  PUSH AF
  CALL 0xD6B // IX-safe
  POP  AF
  LD   (#ATTR_T$),A
__endasm;
} //Graph_ClearDevice

/*--------------------------------- Cut here ---------------------------------*/
void Graph__init (void)
{
__asm
  DI
__endasm;
  color = -1; bkcolor = -1;
  Graph_SetBkColor(0); Graph_SetColor(7); Graph_ClearDevice();
} //Graph__init


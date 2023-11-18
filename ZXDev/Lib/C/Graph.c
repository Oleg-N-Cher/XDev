#include "Graph.oh"

// void Graph_PutPixel (int x, int y);
void Graph_PutPixel_ROM (int x, int y) __z88dk_callee;
void Graph_Line (int x1, int y1, int x2, int y2);
void Graph_SetBkColor (signed char color) __z88dk_fastcall;
void Graph_SetColor (signed char color) __z88dk_fastcall;
void Graph__init (void);

void BORDER (signed char color) __z88dk_fastcall;
void BRIGHT (signed char mode) __z88dk_fastcall;
void INVERSE (signed char mode) __z88dk_fastcall;
void INK (signed char color) __z88dk_fastcall;
void PAPER (signed char color) __z88dk_fastcall;

extern signed char color, bkcolor;

/*implementation*/

/* Video temp attrib */
#define ATTR_T$ 0x5C8F
/* Set video attrib */
#define SETV_A$ 0x5C8D

/*================================== Header ==================================*/
signed char color;

/*--------------------------------- Cut here ---------------------------------*/
signed char bkcolor;

/*--------------------------------- Cut here ---------------------------------*/
void Graph_PutPixel_ROM (int x, int y) __naked __z88dk_callee
{
__asm
  POP  HL
  POP  BC
  EX   (SP),HL
  LD   A,B
  OR   H
  RET  NZ
  LD   B,L
  LD   A,L
  CP   #0xC0
  RET  NC
  LD   IY,#0x5C3A
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

void Graph_InitPixel (void)
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
static int Graph_GetSign (int x)
{
	if (x >= 0) return 1;
	return -1;
}

void Graph_Line (int x1, int y1, int x2, int y2)
{
	int dx, dy, sdx, sdy, x, y, px, py;
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
void Graph_CloseGraph (void) __naked
{
__asm
  LD   IY,#0x5C3A
  EI
  LD   BC,#0
  JP   0x1F3D
__endasm;
} //Graph_CloseGraph

/*--------------------------------- Cut here ---------------------------------*/
void INVERSE (signed char mode) __z88dk_fastcall
{
__asm
  LD   IY,#0x5C3A
  LD   A,#20
  RST  16 // IX-safe
  LD   A,L
  RST  16
  LD   A,(#ATTR_T$)
  LD   (#SETV_A$),A
__endasm;
} //INVERSE

/*--------------------------------- Cut here ---------------------------------*/
void INK (signed char color) __z88dk_fastcall
{
__asm
  LD   A,(#ATTR_T$)
  AND  #0xF8
  OR   L
  LD   (#SETV_A$),A
  LD   (#ATTR_T$),A
__endasm;
} //INK

/*--------------------------------- Cut here ---------------------------------*/
void PAPER (signed char color) __z88dk_fastcall
{
__asm
  LD   A,(#ATTR_T$)
  AND  #0xC7
  SLA  L
  SLA  L
  SLA  L
  OR   L
  LD   (#SETV_A$),A
  LD   (#ATTR_T$),A
__endasm;
} //PAPER

/*--------------------------------- Cut here ---------------------------------*/
void BORDER (signed char color) __naked __z88dk_fastcall 
{
__asm
  LD   A,L
  JP   0x229B // IX-safe
__endasm;
} //BORDER

/*--------------------------------- Cut here ---------------------------------*/
void BRIGHT (signed char mode) __z88dk_fastcall
{
__asm
  LD   IY,#0x5C3A
  LD   A,#19
  RST  16
  LD   A,L
  RST  16
  LD   A,(#ATTR_T$)
  LD   (#SETV_A$),A
__endasm;
} //BRIGHT

/*--------------------------------- Cut here ---------------------------------*/
void Graph_SetBkColor (signed char c) __naked __z88dk_fastcall
{
__asm
  LD   A,L        ; bkcolor := c
  LD   (_bkcolor),A
  LD   A,(_color)
  CP   L          ; IF c = color THEN
  JR   NZ, INV0BK$
  LD   L,#1       ;   INVERSE(1)
  JP   _INVERSE
INV0BK$:          ; ELSE
  PUSH HL
  CALL _PAPER     ;   PAPER(c)
  POP  HL
  CALL _BORDER    ;   BORDER(c)
  LD   L,#0
  JP   _INVERSE   ;   INVERSE(0)
__endasm;
} //Graph_SetBkColor

/*--------------------------------- Cut here ---------------------------------*/
void Graph_SetColor (signed char c) __naked __z88dk_fastcall
{
__asm
  LD   A,L        ; color := c
  LD   (_color),A
  LD   A,(_bkcolor)
  CP   L          ; IF c = bkcolor THEN
  JR   NZ, INV0COL$
  LD   L,#1       ;   INVERSE(1)
  JP   _INVERSE
INV0COL$:         ; ELSE
  CALL _INK       ;   INK(c)
  LD   L,#0
  JP   _INVERSE   ;   INVERSE(0);
__endasm;
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

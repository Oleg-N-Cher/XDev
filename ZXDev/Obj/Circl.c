/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Asm.h"
#include "Basic.h"
#include "Graph.h"


static INTEGER Circl_KD, Circl_MD, Circl_x0, Circl_y0, Circl_R, Circl_i;


static void Circl_Circ (INTEGER x, INTEGER y, INTEGER Radius);
static void Circl_EORFill (void);


/*============================================================================*/

static struct Circ__1 {
	INTEGER *x, *y;
	INTEGER *X, *Y;
	struct Circ__1 *lnk;
} *Circ__1_s;

static void Plot4__2 (void);

static void Plot4__2 (void)
{
	INTEGER ty;
	ty = *Circ__1_s->y + *Circ__1_s->Y;
	if (ty < 0) {
		ty = 0;
	} else if (ty > Graph_GetMaxY()) {
		ty = Graph_GetMaxY();
	}
	Graph_PutPixel(*Circ__1_s->x + *Circ__1_s->X, ty);
	if (*Circ__1_s->X != 0) {
		Graph_PutPixel(*Circ__1_s->x - *Circ__1_s->X, ty);
	}
	ty = *Circ__1_s->y - *Circ__1_s->Y;
	if (ty < 0) {
		ty = 0;
	} else if (ty > Graph_GetMaxY()) {
		ty = Graph_GetMaxY();
	}
	Graph_PutPixel(*Circ__1_s->x + *Circ__1_s->X, ty);
	if (*Circ__1_s->X != 0) {
		Graph_PutPixel(*Circ__1_s->x - *Circ__1_s->X, ty);
	}
}

static void Circl_Circ (INTEGER x, INTEGER y, INTEGER Radius)
{
	INTEGER X, Y, A;
	struct Circ__1 _s;
	_s.x = &x;
	_s.y = &y;
	_s.X = &X;
	_s.Y = &Y;
	_s.lnk = Circ__1_s;
	Circ__1_s = &_s;
	Y = Radius;
	X = 0;
	A = __ASHR(Radius, 1);
	do {
		Plot4__2();
		X = X + 1;
		A = A - X;
		if (A < 0) {
			A = A + Y;
			Y = Y - 1;
		}
	} while (!(X >= Y));
	A = -__ASHR(Radius, 1) - 1;
	Plot4__2();
	do {
		A = A + Y;
		Y = Y - 1;
		if (A > 0) {
			X = X + 1;
			A = A - X;
			Plot4__2();
		}
	} while (!(!(Y >= 0)));
	Circ__1_s = _s.lnk;
}

static void Circl_EORFill (void)
{
	Asm_Code((CHAR*)"  LD   L,#0X20       ", (LONGINT)22);
	Asm_Code((CHAR*)"loop1$:              ", (LONGINT)22);
	Asm_Code((CHAR*)"  DEC L              ", (LONGINT)22);
	Asm_Code((CHAR*)"  LD   H,#0X40       ", (LONGINT)22);
	Asm_Code((CHAR*)"  XOR A              ", (LONGINT)22);
	Asm_Code((CHAR*)"  LD   C,#3          ", (LONGINT)22);
	Asm_Code((CHAR*)"loop2$:              ", (LONGINT)22);
	Asm_Code((CHAR*)"  LD   B,#8          ", (LONGINT)22);
	Asm_Code((CHAR*)"  LD   DE,#32-7*256  ", (LONGINT)22);
	Asm_Code((CHAR*)"loop3$:              ", (LONGINT)22);
	Asm_Code((CHAR*)"  XOR (HL)           ", (LONGINT)22);
	Asm_Code((CHAR*)"  LD (HL),A          ", (LONGINT)22);
	Asm_Code((CHAR*)"  INC H              ", (LONGINT)22);
	Asm_Code((CHAR*)"  XOR (HL)           ", (LONGINT)22);
	Asm_Code((CHAR*)"  LD (HL),A          ", (LONGINT)22);
	Asm_Code((CHAR*)"  INC H              ", (LONGINT)22);
	Asm_Code((CHAR*)"  XOR (HL)           ", (LONGINT)22);
	Asm_Code((CHAR*)"  LD (HL),A          ", (LONGINT)22);
	Asm_Code((CHAR*)"  INC H              ", (LONGINT)22);
	Asm_Code((CHAR*)"  XOR (HL)           ", (LONGINT)22);
	Asm_Code((CHAR*)"  LD (HL),A          ", (LONGINT)22);
	Asm_Code((CHAR*)"  INC H              ", (LONGINT)22);
	Asm_Code((CHAR*)"  XOR (HL)           ", (LONGINT)22);
	Asm_Code((CHAR*)"  LD (HL),A          ", (LONGINT)22);
	Asm_Code((CHAR*)"  INC H              ", (LONGINT)22);
	Asm_Code((CHAR*)"  XOR (HL)           ", (LONGINT)22);
	Asm_Code((CHAR*)"  LD (HL),A          ", (LONGINT)22);
	Asm_Code((CHAR*)"  INC H              ", (LONGINT)22);
	Asm_Code((CHAR*)"  XOR (HL)           ", (LONGINT)22);
	Asm_Code((CHAR*)"  LD (HL),A          ", (LONGINT)22);
	Asm_Code((CHAR*)"  INC H              ", (LONGINT)22);
	Asm_Code((CHAR*)"  XOR (HL)           ", (LONGINT)22);
	Asm_Code((CHAR*)"  LD (HL),A          ", (LONGINT)22);
	Asm_Code((CHAR*)"  ADD HL,DE          ", (LONGINT)22);
	Asm_Code((CHAR*)"  DJNZ loop3$        ", (LONGINT)22);
	Asm_Code((CHAR*)"  LD DE,#8*256-8*32  ", (LONGINT)22);
	Asm_Code((CHAR*)"  ADD HL,DE          ", (LONGINT)22);
	Asm_Code((CHAR*)"  DEC C              ", (LONGINT)22);
	Asm_Code((CHAR*)"  JR NZ,loop2$       ", (LONGINT)22);
	Asm_Code((CHAR*)"  DEC L              ", (LONGINT)22);
	Asm_Code((CHAR*)"  INC L              ", (LONGINT)22);
	Asm_Code((CHAR*)"  JR NZ,loop1$       ", (LONGINT)22);
}


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Asm__init);
	__IMPORT(Basic__init);
	__IMPORT(Graph__init);
	__REGMAIN("Circl", 0);
/* BEGIN */
	Circl_KD = 1;
	Circl_MD = 1;
	Graph_InitGraph(&Circl_KD, &Circl_MD, (CHAR*)"", (LONGINT)1);
	Graph_SetBkColor(4);
	Graph_SetColor(0);
	Graph_ClearDevice();
	Basic_OVER(1);
	Circl_i = 0;
	while (Circl_i <= 20) {
		Circl_x0 = Basic_RND(-60, Graph_GetMaxX() + 60);
		Circl_y0 = Basic_RND(-60, Graph_GetMaxY() + 60);
		Circl_R = 20;
		while (Circl_R <= 60) {
			Circl_Circ(Circl_x0, Circl_y0, Circl_R);
			Circl_R += 20;
		}
		Circl_i += 1;
	}
	Circl_EORFill();
	Graph_CloseGraph();
	__FINI;
}

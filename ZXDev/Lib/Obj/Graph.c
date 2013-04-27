/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Platform.h"




export void Graph_ClearDevice (void);
export void Graph_CloseGraph (void);
export INTEGER Graph_GetMaxX (void);
export INTEGER Graph_GetMaxY (void);
static INTEGER Graph_GetSign (INTEGER x);
export void Graph_InitGraph (INTEGER *GraphDriver, INTEGER *GraphMode, CHAR *PathToDriver, LONGINT PathToDriver__len);
export void Graph_Line (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2);
export void Graph_PutPixel (INTEGER x, INTEGER y);
export void Graph_SetBkColor (CARDINAL Color);
export void Graph_SetColor (CARDINAL Color);


void Graph_ClearDevice (void)
{
}

void Graph_CloseGraph (void)
{
}

void Graph_InitGraph (INTEGER *GraphDriver, INTEGER *GraphMode, CHAR *PathToDriver, LONGINT PathToDriver__len)
{
}

INTEGER Graph_GetMaxX (void)
{
	return 255;
}

INTEGER Graph_GetMaxY (void)
{
	return 191;
}

void Graph_SetBkColor (CARDINAL Color)
{
}

void Graph_SetColor (CARDINAL Color)
{
}

void Graph_PutPixel (INTEGER x, INTEGER y)
{
}

static INTEGER Graph_GetSign (INTEGER x)
{
	if (x >= 0) {
		return 1;
	} else {
		return -1;
	}
	__RETCHK;
}

void Graph_Line (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2)
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
}


export void *Graph__init(void)
{
	__DEFMOD;
	__IMPORT(Platform);
	__REGMOD("Graph", 0);
	__REGCMD("ClearDevice", Graph_ClearDevice);
	__REGCMD("CloseGraph", Graph_CloseGraph);
/* BEGIN */
	__ENDMOD;
}

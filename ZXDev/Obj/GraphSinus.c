/* Ofront+ 1.0 -m3 -21 */
#include "SYSTEM.h"
#include "Graph.h"
#include "Math.h"


static SHORTINT GraphSinus_KD, GraphSinus_MD, GraphSinus_i, GraphSinus_s, GraphSinus_ox, GraphSinus_oy, GraphSinus__for__1;


static BYTE GraphSinus_Sign (SHORTINT x);


/*============================================================================*/

static BYTE GraphSinus_Sign (SHORTINT x)
{
	if (x > 0) {
		return 1;
	}
	if (x < 0) {
		return -1;
	}
	return 0;
}


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Graph__init);
	__IMPORT(Math__init);
	__REGMAIN("GraphSinus", 0);
/* BEGIN */
	GraphSinus_KD = 1;
	GraphSinus_MD = 1;
	Graph_InitGraph(&GraphSinus_KD, &GraphSinus_MD, (void*)&"", 1);
	GraphSinus_ox = __ASHR(Graph_GetMaxX() + 1, 1, SHORTINT);
	GraphSinus_oy = __ASHR(Graph_GetMaxY() + 1, 1, SHORTINT);
	Graph_SetColor(71);
	Graph_Line(0, GraphSinus_oy, Graph_GetMaxX() + 1, GraphSinus_oy);
	Graph_Line(GraphSinus_ox, 0, GraphSinus_ox, Graph_GetMaxY() + 1);
	Graph_Line(Graph_GetMaxX() - 4, GraphSinus_oy - 3, Graph_GetMaxX(), GraphSinus_oy - 1);
	Graph_Line(Graph_GetMaxX() - 4, GraphSinus_oy + 3, Graph_GetMaxX(), GraphSinus_oy + 1);
	Graph_Line(GraphSinus_ox - 3, 5, GraphSinus_ox - 1, 1);
	Graph_Line(GraphSinus_ox + 3, 5, GraphSinus_ox + 1, 1);
	GraphSinus_i = 1;
	GraphSinus__for__1 = GraphSinus_ox - 10;
	if (GraphSinus_i <= GraphSinus__for__1) {
		GraphSinus__for__1 = (unsigned)(GraphSinus__for__1 - GraphSinus_i) + 1;
		do {
			GraphSinus_s = (SHORTINT)__ENTIER(Math_Sin(GraphSinus_i / (SHORTREAL)(SHORTREAL)20) * (REAL)50);
			if (GraphSinus_s != 0) {
				Graph_Line(GraphSinus_i + GraphSinus_ox, GraphSinus_s + GraphSinus_oy, GraphSinus_ox, GraphSinus_oy + (SHORTINT)GraphSinus_Sign(GraphSinus_s));
				Graph_Line(GraphSinus_ox - GraphSinus_i, GraphSinus_oy - GraphSinus_s, GraphSinus_ox, GraphSinus_oy - (SHORTINT)GraphSinus_Sign(GraphSinus_s));
			}
			GraphSinus_i += 1;
		} while (--GraphSinus__for__1);
	}
	Graph_CloseGraph();
	__FINI;
}

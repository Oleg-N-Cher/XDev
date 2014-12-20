/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Graph.h"
#include "Math.h"


static INTEGER GraphSinus_KD, GraphSinus_MD, GraphSinus_i, GraphSinus_s, GraphSinus_ox, GraphSinus_oy, GraphSinus__for__1;


static SHORTINT GraphSinus_Sign (INTEGER x);


/*============================================================================*/

static SHORTINT GraphSinus_Sign (INTEGER x)
{
	if (x > 0) {
		return 1;
	}
	if (x < 0) {
		return -1;
	}
	return 0;
}


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Graph__init);
	__IMPORT(Math__init);
	__REGMAIN("GraphSinus", 0);
/* BEGIN */
	GraphSinus_KD = 1;
	GraphSinus_MD = 1;
	Graph_InitGraph(&GraphSinus_KD, &GraphSinus_MD, (CHAR*)"", (LONGINT)1);
	GraphSinus_ox = __ASHR(Graph_GetMaxX() + 1, 1);
	GraphSinus_oy = __ASHR(Graph_GetMaxY() + 1, 1);
	Graph_SetColor(71);
	Graph_Line(0, GraphSinus_oy, Graph_GetMaxX() + 1, GraphSinus_oy);
	Graph_Line(GraphSinus_ox, 0, GraphSinus_ox, Graph_GetMaxY() + 1);
	Graph_Line(Graph_GetMaxX() - 4, GraphSinus_oy - 3, Graph_GetMaxX(), GraphSinus_oy - 1);
	Graph_Line(Graph_GetMaxX() - 4, GraphSinus_oy + 3, Graph_GetMaxX(), GraphSinus_oy + 1);
	Graph_Line(GraphSinus_ox - 3, 5, GraphSinus_ox - 1, 1);
	Graph_Line(GraphSinus_ox + 3, 5, GraphSinus_ox + 1, 1);
	GraphSinus__for__1 = GraphSinus_ox - 10;
	GraphSinus_i = 1;
	while (GraphSinus_i <= GraphSinus__for__1) {
		GraphSinus_s = (int)__ENTIER(Math_Sin(GraphSinus_i / (REAL)(REAL)20) * (REAL)50);
		if (GraphSinus_s != 0) {
			Graph_Line(GraphSinus_i + GraphSinus_ox, GraphSinus_s + GraphSinus_oy, GraphSinus_ox, GraphSinus_oy + (int)GraphSinus_Sign(GraphSinus_s));
			Graph_Line(GraphSinus_ox - GraphSinus_i, GraphSinus_oy - GraphSinus_s, GraphSinus_ox, GraphSinus_oy - (int)GraphSinus_Sign(GraphSinus_s));
		}
		GraphSinus_i += 1;
	}
	Graph_CloseGraph();
	__FINI;
}

/*  Ofront 1.2 -xtspkae */

#ifndef Graph__h
#define Graph__h

#include "SYSTEM.h"




import void Graph_CloseGraph (void);
import INTEGER Graph_GetMaxX (void);
import INTEGER Graph_GetMaxY (void);
import void Graph_InitGraph (INTEGER *GraphDriver, INTEGER *GraphMode, CHAR *PathToDriver, LONGINT PathToDriver__len);
import void Graph_Line (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2);
import void Graph_PutPixel (INTEGER x, INTEGER y);
import void Graph_SetColor (CARDINAL Color);
import void *Graph__init(void);


#endif

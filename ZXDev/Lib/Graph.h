/*  Ofront 1.2 -xtspkae */

#ifndef Graph__h
#define Graph__h

#include "SYSTEM.h"
#include "GrPixel.h"


import void Graph_CloseGraph (void);
#define Graph_GetMaxX() 255
#define Graph_GetMaxY() 191
import void Graph_InitGraph (INTEGER *GraphDriver, INTEGER *GraphMode, CHAR *PathToDriver, LONGINT PathToDriver__len);
#define Graph_PutPixel Graph_PutPixel_ROM
import void Graph_Line (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2);
#define Graph_SetColor(color)
//import void *Graph__init(void);
#define Graph__init()


#endif

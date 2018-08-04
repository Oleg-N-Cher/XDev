/*  Ofront 1.2 -xtspkae */

#ifndef Graph__h
#define Graph__h

#include "SYSTEM.h"


import void Graph_ClearDevice (void);
import void Graph_CloseGraph (void);
#define Graph_GetMaxX() 255
#define Graph_GetMaxY() 191
import void Graph_InitGraph (SHORTINT *GraphDriver, SHORTINT *GraphMode, CHAR *PathToDriver, SHORTINT PathToDriver__len);
import void Graph_PutPixel_ROM (SHORTINT x, SHORTINT y);
#define Graph_PutPixel Graph_PutPixel_ROM
import void Graph_Line (SHORTINT x1, SHORTINT y1, SHORTINT x2, SHORTINT y2);
import void Graph_SetBkColor (BYTE color);
import void Graph_SetColor (BYTE color);
import void Graph__init (void);


#endif

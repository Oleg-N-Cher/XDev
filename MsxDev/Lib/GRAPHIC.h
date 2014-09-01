/*  Ofront 1.2 -xtspkae */

#ifndef GRAPHIC__h
#define GRAPHIC__h

#include "SYSTEM.h"




import void GRAPHIC_Color (SHORTINT ForeGroundColor, SHORTINT BackGroudColor, SHORTINT BorderColor);
import void GRAPHIC_Pset (INTEGER Destination_x, INTEGER Destination_y, SHORTINT DestinationPage, SHORTINT Color, SHORTINT LogicalOperation);
import void GRAPHIC_Screen (SHORTINT mode);
import void GRAPHIC_SetColor (SHORTINT color);
import void GRAPHIC_Width (SHORTINT len);
import void *GRAPHIC__init(void);

#define GRAPHIC__init()	/*noinit*/

#endif

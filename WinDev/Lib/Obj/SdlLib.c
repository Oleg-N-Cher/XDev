/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export INTEGER SdlLib_Init (SET flags);
export void SdlLib_Quit (void);

#include <SDL.h>
#define SdlLib_sdlInit(flags)	SDL_Init(flags)
#define SdlLib_sdlQuit()	SDL_Quit()

INTEGER SdlLib_Init (SET flags)
{
	return SdlLib_sdlInit(flags);
}

void SdlLib_Quit (void)
{
	SdlLib_sdlQuit();
}


export void *SdlLib__init(void)
{
	__DEFMOD;
	__REGMOD("SdlLib", 0);
	__REGCMD("Quit", SdlLib_Quit);
/* BEGIN */
	__ENDMOD;
}

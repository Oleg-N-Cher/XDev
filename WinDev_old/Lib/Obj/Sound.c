/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Ignore.h"
#include "SdlMixer.h"
#include "SdlLib.h"


export BOOLEAN Sound_initOk;


export void Sound_Free (SdlMixer_PMix_Chunk *sound);
export void Sound_Load (SdlMixer_PMix_Chunk *sound, CHAR *fileName, LONGINT fileName__len);
export void Sound_Play (SdlMixer_PMix_Chunk sound);
export void Sound_Quit (void);


/*============================================================================*/

void Sound_Load (SdlMixer_PMix_Chunk *sound, CHAR *fileName, LONGINT fileName__len)
{
	if (Sound_initOk) {
		*sound = SdlMixer_Mix_LoadWAV((SYSTEM_PTR)((INTEGER)fileName));
	} else {
		*sound = NIL;
	}
}

/*----------------------------------------------------------------------------*/
void Sound_Play (SdlMixer_PMix_Chunk sound)
{
	if (Sound_initOk && sound != NIL) {
		Ignore_Int(SdlMixer_Mix_PlayChannel(-1, sound, 0));
	}
}

/*----------------------------------------------------------------------------*/
void Sound_Free (SdlMixer_PMix_Chunk *sound)
{
	if (Sound_initOk && *sound != NIL) {
		SdlMixer_Mix_FreeChunk(*sound);
	}
}

/*----------------------------------------------------------------------------*/
void Sound_Quit (void)
{
	SdlMixer_Mix_CloseAudio();
	SdlLib_QuitSubSystem(0x10);
}

/*----------------------------------------------------------------------------*/

export void *Sound__init(void)
{
	__DEFMOD;
	__IMPORT(Ignore__init);
	__IMPORT(SdlMixer__init);
	__IMPORT(SdlLib__init);
	__REGMOD("Sound", 0);
	__REGCMD("Quit", Sound_Quit);
/* BEGIN */
	Sound_initOk = SdlLib_InitSubSystem(0x10) >= 0;
	if (Sound_initOk) {
		Sound_initOk = 0 <= SdlMixer_Mix_OpenAudio(22050, -32752, 2, 4096);
	}
	__ENDMOD;
}

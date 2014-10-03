/*  Ofront 1.2 -xtspkae */

#ifndef SdlWin32__h
#define SdlWin32__h

#include "SYSTEM.h"

typedef
	struct SdlWin32_SysWMinfo *SdlWin32_PSysWMinfo;

typedef
	struct SdlWin32_SysWMmsg *SdlWin32_PSysWMmsg;

typedef
	struct SdlWin32_Version {
		BYTE major, minor, patch;
	} SdlWin32_Version;

typedef
	struct SdlWin32_SysWMinfo {
		SdlWin32_Version version;
		INTEGER window, hGLrc;
	} SdlWin32_SysWMinfo;

typedef
	struct SdlWin32_SysWMmsg {
		SdlWin32_Version version;
		INTEGER hWnd, msg, wParam, lParam;
	} SdlWin32_SysWMmsg;



import LONGINT *SdlWin32_Version__typ;
import LONGINT *SdlWin32_SysWMinfo__typ;
import LONGINT *SdlWin32_SysWMmsg__typ;

import void *SdlWin32__init(void);

#define SdlWin32_GetWMInfo(info, info__typ)	SDL_GetWMInfo(info)
#define SdlWin32_SDL_GetWMInfo(info, info__typ)	SDL_GetWMInfo(info)
__EXTERN INTEGER SDL_GetWMInfo(SdlWin32_SysWMinfo *info);
#define SdlWin32__init()	/*-noinit*/

#endif

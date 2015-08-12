/*  Ofront 1.2 -xtspkae */

#ifndef Rose__h
#define Rose__h

#include "SYSTEM.h"

typedef
	CHAR Rose_Adr[262];

typedef
	struct Rose_Socket {
		LONGINT _prvt0;
		CHAR host[256];
		CHAR ip[16];
		char _prvt1[4];
		INTEGER port;
	} Rose_Socket;

import void Rose_Socket_Close (Rose_Socket *self, LONGINT *self__typ);
#define __Rose_Socket_Close(self, self__typ) __SEND(self__typ, Rose_Socket_Close, 0, void(*)(Rose_Socket*, LONGINT *), (self, self__typ))

typedef
	struct Rose_Listener {
		LONGINT _prvt0;
		CHAR host[256];
		CHAR ip[16];
		char _prvt1[4];
		INTEGER port;
		BOOLEAN error;
		INTEGER errcode;
	} Rose_Listener;

import void Rose_Listener_Listen (Rose_Listener *self, LONGINT *self__typ, CHAR *localAdr, LONGINT localAdr__len);
#define __Rose_Listener_Listen(self, self__typ, localAdr, localAdr__len) __SEND(self__typ, Rose_Listener_Listen, 1, void(*)(Rose_Listener*, LONGINT *, CHAR*, LONGINT ), (self, self__typ, localAdr, localAdr__len))



import LONGINT *Rose_Socket__typ;
import LONGINT *Rose_Listener__typ;

import BOOLEAN Rose_Init (void);
import void Rose_MainLoop (void);
import void Rose_Quit (void);
import void *Rose__init(void);


#endif

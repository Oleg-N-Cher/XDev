/*  Ofront 1.2 -xtspkae */

#ifndef RoseRedir__h
#define RoseRedir__h

#include "SYSTEM.h"

typedef
	CHAR *RoseRedir_Address;

typedef
	struct RoseRedir_Redirector {
		LONGINT _prvt0;
		char _prvt1[288];
		BOOLEAN error;
		INTEGER errcode;
		CHAR host[256];
		CHAR ip[16];
		INTEGER port;
	} RoseRedir_Redirector;

import void RoseRedir_Redirector_Redirect (RoseRedir_Redirector *self, LONGINT *self__typ, CHAR *localAdr, LONGINT localAdr__len, CHAR *remoteAdr, LONGINT remoteAdr__len);
import void RoseRedir_Redirector_Stop (RoseRedir_Redirector *self, LONGINT *self__typ);
#define __RoseRedir_Redirector_Redirect(self, self__typ, localAdr, localAdr__len, remoteAdr, remoteAdr__len) __SEND(self__typ, RoseRedir_Redirector_Redirect, 0, void(*)(RoseRedir_Redirector*, LONGINT *, CHAR*, LONGINT , CHAR*, LONGINT ), (self, self__typ, localAdr, localAdr__len, remoteAdr, remoteAdr__len))
#define __RoseRedir_Redirector_Stop(self, self__typ) __SEND(self__typ, RoseRedir_Redirector_Stop, 1, void(*)(RoseRedir_Redirector*, LONGINT *), (self, self__typ))



import LONGINT *RoseRedir_Redirector__typ;

import void *RoseRedir__init(void);


#endif

/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Rose.h"

typedef
	CHAR *RoseRedir_Address;

typedef
	struct RoseRedir_Redirector {
		Rose_Listener listener;
		BOOLEAN error;
		INTEGER errcode;
		CHAR host[256];
		CHAR ip[16];
		INTEGER port;
	} RoseRedir_Redirector;

export void RoseRedir_Redirector_Redirect (RoseRedir_Redirector *self, LONGINT *self__typ, CHAR *localAdr, LONGINT localAdr__len, CHAR *remoteAdr, LONGINT remoteAdr__len);
export void RoseRedir_Redirector_Stop (RoseRedir_Redirector *self, LONGINT *self__typ);
#define __RoseRedir_Redirector_Redirect(self, self__typ, localAdr, localAdr__len, remoteAdr, remoteAdr__len) __SEND(self__typ, RoseRedir_Redirector_Redirect, 0, void(*)(RoseRedir_Redirector*, LONGINT *, CHAR*, LONGINT , CHAR*, LONGINT ), (self, self__typ, localAdr, localAdr__len, remoteAdr, remoteAdr__len))
#define __RoseRedir_Redirector_Stop(self, self__typ) __SEND(self__typ, RoseRedir_Redirector_Stop, 1, void(*)(RoseRedir_Redirector*, LONGINT *), (self, self__typ))



export LONGINT *RoseRedir_Redirector__typ;



/*============================================================================*/

void RoseRedir_Redirector_Redirect (RoseRedir_Redirector *self, LONGINT *self__typ, CHAR *localAdr, LONGINT localAdr__len, CHAR *remoteAdr, LONGINT remoteAdr__len)
{
	__Rose_Listener_Listen(&(*self).listener, Rose_Listener__typ, (void*)localAdr, localAdr__len);
	(*self).error = (*self).listener.error;
	(*self).errcode = (*self).listener.errcode;
	__COPY((*self).listener.host, (*self).host, 256);
	__COPY((*self).listener.ip, (*self).ip, 16);
	(*self).port = (*self).listener.port;
}

/*----------------------------------------------------------------------------*/
void RoseRedir_Redirector_Stop (RoseRedir_Redirector *self, LONGINT *self__typ)
{
}

/*----------------------------------------------------------------------------*/
__TDESC(RoseRedir_Redirector__desc, 3, 1) = {__TDFLDS("Redirector", 584), {0, -16}};

export void *RoseRedir__init(void)
{
	__DEFMOD;
	__IMPORT(Rose__init);
	__REGMOD("RoseRedir", 0);
	__INITYP(RoseRedir_Redirector, RoseRedir_Redirector, 0);
	__INITBP(RoseRedir_Redirector, RoseRedir_Redirector_Redirect, 0);
	__INITBP(RoseRedir_Redirector, RoseRedir_Redirector_Stop, 1);
/* BEGIN */
	__ENDMOD;
}

/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "LibC.h"
#include "Ignore.h"
#include "WinNet.h"
#include "WinApi.h"

typedef
	CHAR Rose_Adr[262];

typedef
	struct Rose_Socket {
		SYSTEM_PTR handle;
		CHAR host[256];
		CHAR ip[16];
		INTEGER ipv4, port;
	} Rose_Socket;

export void Rose_Socket_Close (Rose_Socket *self, LONGINT *self__typ);
#define __Rose_Socket_Close(self, self__typ) __SEND(self__typ, Rose_Socket_Close, 0, void(*)(Rose_Socket*, LONGINT *), (self, self__typ))

typedef
	struct Rose_Listener {
		SYSTEM_PTR handle;
		CHAR host[256];
		CHAR ip[16];
		INTEGER ipv4, port;
		BOOLEAN error;
		INTEGER errcode;
	} Rose_Listener;

export void Rose_Listener_Listen (Rose_Listener *self, LONGINT *self__typ, CHAR *localAdr, LONGINT localAdr__len);
#define __Rose_Listener_Listen(self, self__typ, localAdr, localAdr__len) __SEND(self__typ, Rose_Listener_Listen, 1, void(*)(Rose_Listener*, LONGINT *, CHAR*, LONGINT ), (self, self__typ, localAdr, localAdr__len))


static BOOLEAN Rose_started;

export LONGINT *Rose_Socket__typ;
export LONGINT *Rose_Listener__typ;

export BOOLEAN Rose_Init (void);
export void Rose_MainLoop (void);
export void Rose_Quit (void);
static BOOLEAN Rose_Resolve (Rose_Socket *self, LONGINT *self__typ, CHAR *adr, LONGINT adr__len);
static BOOLEAN Rose_ResolveHost (Rose_Socket *self, LONGINT *self__typ);

#define Rose_print(i)	printf("%d", i)
#define Rose_prln()	printf("\n")
#define Rose_prstr(s, s__len)	printf("%s", s)

/*============================================================================*/

BOOLEAN Rose_Init (void)
{
	WinNet_WSADATA wsaData;
	if (!Rose_started) {
		if (0 != WinNet_WSAStartup(257, &wsaData, WinNet_WSADATA__typ)) {
			return 0;
		}
	}
	Rose_started = 1;
	return 1;
}

/*----------------------------------------------------------------------------*/
void Rose_Quit (void)
{
	if (Rose_started) {
		Rose_started = 0;
		if (WinNet_WSACleanup() == -1) {
			if (WinNet_WSAGetLastError() == 10036) {
				Ignore_Int(WinNet_WSACancelBlockingCall());
				Ignore_Int(WinNet_WSACleanup());
			}
		}
	}
}

/*----------------------------------------------------------------------------*/
void Rose_Socket_Close (Rose_Socket *self, LONGINT *self__typ)
{
	if ((*self).handle != (SYSTEM_PTR)-1) {
		Ignore_Int(WinNet_closesocket((*self).handle));
	}
}

/*----------------------------------------------------------------------------*/
typedef
	INTEGER (*IPv4Ptr__8)[1];

static BOOLEAN Rose_ResolveHost (Rose_Socket *self, LONGINT *self__typ)
{
	WinNet_Ptrhostent hp = NIL;
	IPv4Ptr__8 ipv4 = NIL;
	(*self).ipv4 = WinNet_inet_addr((SYSTEM_PTR)((LONGINT)(*self).host));
	if ((*self).ipv4 != -1) {
		return 1;
	}
	if (__STRCMP((*self).host, "localhost") == 0) {
		hp = WinNet_gethostbyname((SYSTEM_PTR)((LONGINT)(*self).host));
		if (hp != NIL) {
			__GET(hp->h_addr_list, ipv4, IPv4Ptr__8);
			(*self).ipv4 = (*ipv4)[0];
			return 1;
		}
	}
	return 0;
}

static BOOLEAN Rose_Resolve (Rose_Socket *self, LONGINT *self__typ, CHAR *adr, LONGINT adr__len)
{
	if (LibC_sscanfi((SYSTEM_PTR)((LONGINT)adr), (SYSTEM_PTR)((LONGINT)":%d"), &(*self).port) == 1) {
		(*self).host[0] = 0x00;
		(*self).ip[0] = 0x00;
		(*self).ipv4 = 0;
		return 1;
	} else if (LibC_sscanfai((SYSTEM_PTR)((LONGINT)adr), (SYSTEM_PTR)((LONGINT)"%[^:]:%d"), (SYSTEM_PTR)((LONGINT)(*self).host), &(*self).port) == 2) {
		if (Rose_ResolveHost(&*self, self__typ)) {
			return 1;
		}
	} else if (LibC_sscanfi((SYSTEM_PTR)((LONGINT)adr), (SYSTEM_PTR)((LONGINT)"%d"), &(*self).port) == 1) {
		(*self).host[0] = 0x00;
		(*self).ip[0] = 0x00;
		(*self).ipv4 = 0;
		return 1;
	} else {
		(*self).port = -1;
	}
	(*self).host[0] = 0x00;
	(*self).ip[0] = 0x00;
	(*self).ipv4 = -1;
	return 0;
}

void Rose_Listener_Listen (Rose_Listener *self, LONGINT *self__typ, CHAR *localAdr, LONGINT localAdr__len)
{
	WinNet_sockaddr_in sock_addr;
	INTEGER mode;
	(*self).handle = WinNet_socket(2, 1, 0);
	if ((*self).handle != (SYSTEM_PTR)-1) {
		Ignore_Ptr(LibC_memset((SYSTEM_PTR)((LONGINT)&sock_addr), 0, (SYSTEM_PTR)16));
		sock_addr.sin_family = 2;
		if (Rose_Resolve((void*)&*self, self__typ, (void*)localAdr, localAdr__len)) {
			sock_addr.sin_addr.S_un.S_addr = (*self).ipv4;
			Ignore_Ptr(LibC_strncpy((SYSTEM_PTR)((LONGINT)(*self).ip), (SYSTEM_PTR)WinNet_inet_ntoa(sock_addr.sin_addr), (SYSTEM_PTR)16));
			if ((*self).port >= 0 && (*self).port <= 65535) {
				sock_addr.sin_port = WinNet_htons((int)(*self).port);
				if (WinNet_bind((*self).handle, (WinNet_sockaddr*)&sock_addr, WinNet_sockaddr_in__typ, 16) != -1) {
					if (WinNet_listen((*self).handle, 5) != -1) {
						mode = 1;
						Ignore_Int(WinNet_ioctlsocket((*self).handle, WinNet_FIONBIO(), &mode));
						(*self).error = 0;
						return;
					} else {
						(*self).errcode = 24;
					}
				} else {
					(*self).errcode = 23;
				}
			} else {
				(*self).errcode = 22;
			}
		} else {
			(*self).errcode = 21;
		}
		__Rose_Socket_Close((void*)&*self, self__typ);
	} else {
		(*self).errcode = 20;
	}
	(*self).error = 1;
}

/*----------------------------------------------------------------------------*/
void Rose_MainLoop (void)
{
	WinApi_MSG msg;
	Ignore_Int(WinApi_Beep(1000, 1000));
	while (WinApi_GetMessage(&msg, WinApi_MSG__typ, NIL, 0, 0) != 0) {
		Ignore_Int(WinApi_TranslateMessage(&msg, WinApi_MSG__typ));
		Ignore_Int(WinApi_DispatchMessage(&msg, WinApi_MSG__typ));
	}
	Ignore_Int(WinApi_Beep(1000, 1000));
}

/*----------------------------------------------------------------------------*/
__TDESC(Rose_Socket__desc, 2, 1) = {__TDFLDS("Socket", 288), {0, -16}};
__TDESC(Rose_Listener__desc, 3, 1) = {__TDFLDS("Listener", 296), {0, -16}};

export void *Rose__init(void)
{
	__DEFMOD;
	__IMPORT(LibC__init);
	__IMPORT(Ignore__init);
	__IMPORT(WinNet__init);
	__IMPORT(WinApi__init);
	__REGMOD("Rose", 0);
	__REGCMD("MainLoop", Rose_MainLoop);
	__REGCMD("Quit", Rose_Quit);
	__INITYP(Rose_Socket, Rose_Socket, 0);
	__INITBP(Rose_Socket, Rose_Socket_Close, 0);
	__INITYP(Rose_Listener, Rose_Socket, 1);
	__INITBP(Rose_Listener, Rose_Listener_Listen, 1);
/* BEGIN */
	Rose_started = 0;
	__ENDMOD;
}

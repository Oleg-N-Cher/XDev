/*  Ofront 1.2 -xtspkae */

#ifndef WinNet__h
#define WinNet__h

#include "SYSTEM.h"
#include "WinApi.h"

struct WinNet__1 {
	INTEGER S_addr;
};

typedef
	struct WinNet_ACTION_HEADER {
		INTEGER transport_id;
		SHORTINT action_code, reserved;
	} WinNet_ACTION_HEADER;

typedef
	struct WinNet_ADAPTER_STATUS {
		CHAR adapter_address[6];
		CHAR rev_major, reserved0, adapter_type, rev_minor;
		SHORTINT duration, frmr_recv, frmr_xmit, iframe_recv_err, xmit_aborts;
		INTEGER xmit_success, recv_success;
		SHORTINT iframe_xmit_err, recv_buff_unavail, t1_timeouts, ti_timeouts;
		INTEGER reserved1;
		SHORTINT free_ncbs, max_cfg_ncbs, max_ncbs, xmit_buf_unavail, max_dgram_size, pending_sess, max_cfg_sess, max_sess, max_sess_pkt_size, name_count;
	} WinNet_ADAPTER_STATUS;

typedef
	struct WinNet_WSABUF {
		INTEGER len;
		SYSTEM_PTR buf;
	} WinNet_WSABUF;

typedef
	struct WinNet_QOS {
		WinNet_WSABUF SendingFlowspec, ReceivingFlowspec;
	} WinNet_QOS;

typedef
	INTEGER (__CALL_1 *WinNet_CONDITIONPROC)(WinNet_WSABUF*, LONGINT *, WinNet_WSABUF*, LONGINT *, WinNet_QOS*, LONGINT *, WinNet_QOS*, LONGINT *, WinNet_WSABUF*, LONGINT *, WinNet_WSABUF*, LONGINT *, INTEGER*, INTEGER);

typedef
	struct WinNet_NETRESOURCEA *WinNet_PtrNETRESOURCEA;

typedef
	struct WinNet_CONNECTDLGSTRUCTA {
		INTEGER cbStructure;
		SYSTEM_PTR hwndOwner;
		WinNet_PtrNETRESOURCEA lpConnRes;
		SET dwFlags;
		INTEGER dwDevNum;
	} WinNet_CONNECTDLGSTRUCTA;

typedef
	struct WinNet_NETRESOURCEW *WinNet_PtrNETRESOURCEW;

typedef
	struct WinNet_CONNECTDLGSTRUCTW {
		INTEGER cbStructure;
		SYSTEM_PTR hwndOwner;
		WinNet_PtrNETRESOURCEW lpConnRes;
		SET dwFlags;
		INTEGER dwDevNum;
	} WinNet_CONNECTDLGSTRUCTW;

typedef
	struct WinNet_DISCDLGSTRUCTA {
		INTEGER cbStructure;
		SYSTEM_PTR hwndOwner, lpLocalName, lpRemoteName;
		SET dwFlags;
	} WinNet_DISCDLGSTRUCTA;

typedef
	struct WinNet_DISCDLGSTRUCTW {
		INTEGER cbStructure;
		SYSTEM_PTR hwndOwner, lpLocalName, lpRemoteName;
		SET dwFlags;
	} WinNet_DISCDLGSTRUCTW;

typedef
	struct WinNet_fd_set {
		INTEGER fd_count;
		SYSTEM_PTR fd_array[64];
	} WinNet_fd_set;

typedef
	struct WinNet_FIND_NAME_BUFFER {
		CHAR length, access_control, frame_control;
		CHAR destination_addr[6];
		CHAR source_addr[6];
		CHAR routing_info[18];
	} WinNet_FIND_NAME_BUFFER;

typedef
	struct WinNet_FIND_NAME_HEADER {
		SHORTINT node_count;
		CHAR reserved, unique_group;
	} WinNet_FIND_NAME_HEADER;

typedef
	struct WinNet_FLOWSPEC {
		INTEGER TokenRate, TokenBucketSize, PeakBandwidth, Latency, DelayVariation, LevelOfGuarantee, CostOfCall, NetworkAvailability;
	} WinNet_FLOWSPEC;

typedef
	INTEGER (__CALL_1 *WinNet_FNGETPROFILEPATHA)(SYSTEM_PTR, SYSTEM_PTR, INTEGER);

typedef
	INTEGER (__CALL_1 *WinNet_FNGETPROFILEPATHW)(SYSTEM_PTR, SYSTEM_PTR, INTEGER);

typedef
	INTEGER (__CALL_1 *WinNet_FNPROCESSPOLICIESA)(SYSTEM_PTR, SYSTEM_PTR, SYSTEM_PTR, SYSTEM_PTR, SET);

typedef
	INTEGER (__CALL_1 *WinNet_FNPROCESSPOLICIESW)(SYSTEM_PTR, SYSTEM_PTR, SYSTEM_PTR, SYSTEM_PTR, SET);

typedef
	INTEGER (__CALL_1 *WinNet_FNRECONCILEPROFILEA)(SYSTEM_PTR, SYSTEM_PTR, SET);

typedef
	INTEGER (__CALL_1 *WinNet_FNRECONCILEPROFILEW)(SYSTEM_PTR, SYSTEM_PTR, SET);

typedef
	struct WinNet_in_addr {
		struct WinNet__1 S_un;
	} WinNet_in_addr;

typedef
	struct WinNet_hostent {
		SYSTEM_PTR h_name;
		struct {
			LONGINT len[1];
			SYSTEM_PTR data[1];
		} *h_aliases;
		SHORTINT h_addrtype, h_length;
		struct {
			LONGINT len[1];
			struct {
				LONGINT len[1];
				WinNet_in_addr data[1];
			} *data[1];
		} *h_addr_list;
	} WinNet_hostent;

typedef
	struct WinNet_LANA_ENUM {
		CHAR length;
		CHAR lana[255];
	} WinNet_LANA_ENUM;

typedef
	struct WinNet_linger {
		SHORTINT l_onoff, l_linger;
	} WinNet_linger;

typedef
	struct WinNet_NAME_BUFFER {
		CHAR name[16];
		CHAR name_num, name_flags;
	} WinNet_NAME_BUFFER;

typedef
	struct WinNet_NCB *WinNet_PtrNCB;

typedef
	struct WinNet_NCB {
		CHAR ncb_command, ncb_retcode, ncb_lsn, ncb_num;
		SYSTEM_PTR ncb_buffer;
		SHORTINT ncb_length;
		CHAR ncb_callname[16];
		CHAR ncb_name[16];
		CHAR ncb_rto, ncb_sto;
		void (__CALL_1 *ncb_post)(WinNet_PtrNCB);
		CHAR ncb_lana_num, ncb_cmd_cplt;
		CHAR ncb_reserve[10];
		SYSTEM_PTR ncb_event;
	} WinNet_NCB;

typedef
	struct WinNet_NETCONNECTINFOSTRUCT {
		INTEGER cbStructure;
		SET dwFlags;
		INTEGER dwSpeed, dwDelay, dwOptDataSize;
	} WinNet_NETCONNECTINFOSTRUCT;

typedef
	struct WinNet_NETINFOSTRUCT {
		INTEGER cbStructure, dwProviderVersion;
		SET dwStatus;
		INTEGER dwCharacteristics, dwHandle;
		SHORTINT wNetType;
		INTEGER dwPrinters, dwDrives;
	} WinNet_NETINFOSTRUCT;

typedef
	struct WinNet_NETRESOURCEA {
		INTEGER dwScope, dwType, dwDisplayType, dwUsage;
		SYSTEM_PTR lpLocalName, lpRemoteName, lpComment, lpProvider;
	} WinNet_NETRESOURCEA;

typedef
	struct WinNet_NETRESOURCEW {
		INTEGER dwScope, dwType, dwDisplayType, dwUsage;
		SYSTEM_PTR lpLocalName, lpRemoteName, lpComment, lpProvider;
	} WinNet_NETRESOURCEW;

typedef
	struct WinNet_protoent {
		SYSTEM_PTR p_name;
		struct {
			LONGINT len[1];
			SYSTEM_PTR data[1];
		} *p_aliases;
		SHORTINT p_proto;
	} WinNet_protoent;

typedef
	WinNet_ACTION_HEADER *WinNet_PtrACTION_HEADER;

typedef
	WinNet_ADAPTER_STATUS *WinNet_PtrADAPTER_STATUS;

typedef
	WinNet_CONNECTDLGSTRUCTA *WinNet_PtrCONNECTDLGSTRUCTA;

typedef
	WinNet_CONNECTDLGSTRUCTW *WinNet_PtrCONNECTDLGSTRUCTW;

typedef
	WinNet_DISCDLGSTRUCTA *WinNet_PtrDISCDLGSTRUCTA;

typedef
	WinNet_DISCDLGSTRUCTW *WinNet_PtrDISCDLGSTRUCTW;

typedef
	WinNet_fd_set *WinNet_Ptrfd_set;

typedef
	WinNet_FIND_NAME_BUFFER *WinNet_PtrFIND_NAME_BUFFER;

typedef
	WinNet_FIND_NAME_HEADER *WinNet_PtrFIND_NAME_HEADER;

typedef
	WinNet_FLOWSPEC *WinNet_PtrFLOWSPEC;

typedef
	WinNet_hostent *WinNet_Ptrhostent;

typedef
	WinNet_in_addr *WinNet_Ptrin_addr;

typedef
	WinNet_LANA_ENUM *WinNet_PtrLANA_ENUM;

typedef
	WinNet_linger *WinNet_Ptrlinger;

typedef
	WinNet_NAME_BUFFER *WinNet_PtrNAME_BUFFER;

typedef
	WinNet_NETCONNECTINFOSTRUCT *WinNet_PtrNETCONNECTINFOSTRUCT;

typedef
	WinNet_NETINFOSTRUCT *WinNet_PtrNETINFOSTRUCT;

typedef
	WinNet_protoent *WinNet_Ptrprotoent;

typedef
	WinNet_QOS *WinNet_PtrQOS;

typedef
	struct WinNet_REMOTE_NAME_INFOA *WinNet_PtrREMOTE_NAME_INFOA;

typedef
	struct WinNet_REMOTE_NAME_INFOW *WinNet_PtrREMOTE_NAME_INFOW;

typedef
	struct WinNet_servent *WinNet_Ptrservent;

typedef
	struct WinNet_SESSION_BUFFER *WinNet_PtrSESSION_BUFFER;

typedef
	struct WinNet_SESSION_HEADER *WinNet_PtrSESSION_HEADER;

typedef
	struct WinNet_sockaddr *WinNet_Ptrsockaddr;

typedef
	struct WinNet_sockaddr_in *WinNet_Ptrsockaddr_in;

typedef
	struct WinNet_timeval *WinNet_Ptrtimeval;

typedef
	struct WinNet_TRANSMIT_FILE_BUFFERS *WinNet_PtrTRANSMIT_FILE_BUFFERS;

typedef
	struct WinNet_UNIVERSAL_NAME_INFOA *WinNet_PtrUNIVERSAL_NAME_INFOA;

typedef
	struct WinNet_UNIVERSAL_NAME_INFOW *WinNet_PtrUNIVERSAL_NAME_INFOW;

typedef
	WinNet_WSABUF *WinNet_PtrWSABUF;

typedef
	struct WinNet_WSADATA *WinNet_PtrWSADATA;

typedef
	struct WinNet_WSANETWORKEVENTS *WinNet_PtrWSANETWORKEVENTS;

typedef
	struct WinNet_WSAOVERLAPPED *WinNet_PtrWSAOVERLAPPED;

typedef
	struct WinNet_WSAPROTOCOLCHAIN *WinNet_PtrWSAPROTOCOLCHAIN;

typedef
	struct WinNet_WSAPROTOCOL_INFOA *WinNet_PtrWSAPROTOCOL_INFOA;

typedef
	struct WinNet_WSAPROTOCOL_INFOW *WinNet_PtrWSAPROTOCOL_INFOW;

typedef
	struct WinNet_REMOTE_NAME_INFOA {
		SYSTEM_PTR lpUniversalName, lpConnectionName, lpRemainingPath;
	} WinNet_REMOTE_NAME_INFOA;

typedef
	struct WinNet_REMOTE_NAME_INFOW {
		SYSTEM_PTR lpUniversalName, lpConnectionName, lpRemainingPath;
	} WinNet_REMOTE_NAME_INFOW;

typedef
	struct WinNet_servent {
		SYSTEM_PTR s_name;
		struct {
			LONGINT len[1];
			SYSTEM_PTR data[1];
		} *s_aliases;
		SHORTINT s_port;
		SYSTEM_PTR s_proto;
	} WinNet_servent;

typedef
	struct WinNet_SESSION_BUFFER {
		CHAR lsn, state;
		CHAR local_name[16];
		CHAR remote_name[16];
		CHAR rcvs_outstanding, sends_outstanding;
	} WinNet_SESSION_BUFFER;

typedef
	struct WinNet_SESSION_HEADER {
		CHAR sess_name, num_sess, rcv_dg_outstanding, rcv_any_outstanding;
	} WinNet_SESSION_HEADER;

typedef
	struct WinNet_sockaddr {
		SHORTINT sa_family;
		CHAR sa_data[14];
	} WinNet_sockaddr;

typedef
	struct WinNet_sockaddr_in {
		SHORTINT sin_family, sin_port;
		WinNet_in_addr sin_addr;
		CHAR sin_zero[8];
	} WinNet_sockaddr_in;

typedef
	struct WinNet_timeval {
		INTEGER tv_sec, tv_usec;
	} WinNet_timeval;

typedef
	struct WinNet_TRANSMIT_FILE_BUFFERS {
		SYSTEM_PTR Head;
		INTEGER HeadLength;
		SYSTEM_PTR Tail;
		INTEGER TailLength;
	} WinNet_TRANSMIT_FILE_BUFFERS;

typedef
	struct WinNet_UNIVERSAL_NAME_INFOA {
		SYSTEM_PTR lpUniversalName;
	} WinNet_UNIVERSAL_NAME_INFOA;

typedef
	struct WinNet_UNIVERSAL_NAME_INFOW {
		SYSTEM_PTR lpUniversalName;
	} WinNet_UNIVERSAL_NAME_INFOW;

typedef
	struct WinNet_WSADATA {
		SHORTINT wVersion, wHighVersion;
		CHAR szDescription[257];
		CHAR szSystemStatus[129];
		SHORTINT iMaxSockets, iMaxUdpDg;
		SYSTEM_PTR lpVendorInfo;
	} WinNet_WSADATA;

typedef
	struct WinNet_WSANETWORKEVENTS {
		INTEGER lNetworkEvents;
		INTEGER iErrorCode[8];
	} WinNet_WSANETWORKEVENTS;

typedef
	struct WinNet_WSAOVERLAPPED {
		INTEGER Internal, InternalHigh, Offset, OffsetHigh, hEvent;
	} WinNet_WSAOVERLAPPED;

typedef
	void (__CALL_1 *WinNet_WSAOVERLAPPED_COMPLETION_ROUTINE)(INTEGER, INTEGER, WinNet_WSAOVERLAPPED*, LONGINT *, SET);

typedef
	struct WinNet_WSAPROTOCOLCHAIN {
		INTEGER ChainLen;
		INTEGER ChainEntries[8];
	} WinNet_WSAPROTOCOLCHAIN;

typedef
	struct WinNet_WSAPROTOCOL_INFOA {
		INTEGER dwServiceFlags1, dwServiceFlags2, dwServiceFlags3, dwServiceFlags4, dwProviderId, dwCatalogEntryId;
		WinNet_WSAPROTOCOLCHAIN ProtocolChain;
		INTEGER iVersion, iAddressFamily, iMaxSockAddr, iMinSockAddr, iSocketType, iProtocol, iNetworkByteOrder, iSecurityScheme, bMultiple, bFirst, dwMessageSize, dwProviderReserved;
		CHAR szProtocol[256];
	} WinNet_WSAPROTOCOL_INFOA;

typedef
	struct WinNet_WSAPROTOCOL_INFOW {
		INTEGER dwServiceFlags1, dwServiceFlags2, dwServiceFlags3, dwServiceFlags4, dwProviderId, dwCatalogEntryId;
		WinNet_WSAPROTOCOLCHAIN ProtocolChain;
		INTEGER iVersion, iAddressFamily, iMaxSockAddr, iMinSockAddr, iSocketType, iProtocol, iNetworkByteOrder, iSecurityScheme, bMultiple, bFirst, dwMessageSize, dwProviderReserved;
		SHORTINT szProtocol[256];
	} WinNet_WSAPROTOCOL_INFOW;

typedef
	struct WinNet_netent {
		SYSTEM_PTR n_name;
		struct {
			LONGINT len[1];
			SYSTEM_PTR data[1];
		} *n_aliases;
		SHORTINT n_addrtype;
		INTEGER n_net;
	} WinNet_netent;

typedef
	struct WinNet_sockproto {
		SHORTINT sp_family, sp_protocol;
	} WinNet_sockproto;



import LONGINT *WinNet_NETRESOURCEA__typ;
import LONGINT *WinNet_NETRESOURCEW__typ;
import LONGINT *WinNet_CONNECTDLGSTRUCTA__typ;
import LONGINT *WinNet_CONNECTDLGSTRUCTW__typ;
import LONGINT *WinNet_DISCDLGSTRUCTA__typ;
import LONGINT *WinNet_DISCDLGSTRUCTW__typ;
import LONGINT *WinNet_UNIVERSAL_NAME_INFOA__typ;
import LONGINT *WinNet_UNIVERSAL_NAME_INFOW__typ;
import LONGINT *WinNet_REMOTE_NAME_INFOA__typ;
import LONGINT *WinNet_REMOTE_NAME_INFOW__typ;
import LONGINT *WinNet_NETINFOSTRUCT__typ;
import LONGINT *WinNet_NETCONNECTINFOSTRUCT__typ;
import LONGINT *WinNet_NCB__typ;
import LONGINT *WinNet_ADAPTER_STATUS__typ;
import LONGINT *WinNet_NAME_BUFFER__typ;
import LONGINT *WinNet_SESSION_HEADER__typ;
import LONGINT *WinNet_SESSION_BUFFER__typ;
import LONGINT *WinNet_LANA_ENUM__typ;
import LONGINT *WinNet_FIND_NAME_HEADER__typ;
import LONGINT *WinNet_FIND_NAME_BUFFER__typ;
import LONGINT *WinNet_ACTION_HEADER__typ;
import LONGINT *WinNet_fd_set__typ;
import LONGINT *WinNet_timeval__typ;
import LONGINT *WinNet__1__typ;
import LONGINT *WinNet_in_addr__typ;
import LONGINT *WinNet_hostent__typ;
import LONGINT *WinNet_netent__typ;
import LONGINT *WinNet_servent__typ;
import LONGINT *WinNet_protoent__typ;
import LONGINT *WinNet_sockaddr_in__typ;
import LONGINT *WinNet_WSADATA__typ;
import LONGINT *WinNet_sockaddr__typ;
import LONGINT *WinNet_sockproto__typ;
import LONGINT *WinNet_linger__typ;
import LONGINT *WinNet_WSAOVERLAPPED__typ;
import LONGINT *WinNet_WSABUF__typ;
import LONGINT *WinNet_FLOWSPEC__typ;
import LONGINT *WinNet_QOS__typ;
import LONGINT *WinNet_WSANETWORKEVENTS__typ;
import LONGINT *WinNet_WSAPROTOCOLCHAIN__typ;
import LONGINT *WinNet_WSAPROTOCOL_INFOA__typ;
import LONGINT *WinNet_WSAPROTOCOL_INFOW__typ;
import LONGINT *WinNet_TRANSMIT_FILE_BUFFERS__typ;

import void *WinNet__init(void);

#define WinNet_AcceptEx(sListenSocket, sAcceptSocket, lpOutputBuffer, dwReceiveDataLength, dwLocalAddressLength, dwRemoteAddressLength, lpdwBytesReceived, lpOverlapped, lpOverlapped__typ)	AcceptEx(sListenSocket, sAcceptSocket, lpOutputBuffer, dwReceiveDataLength, dwLocalAddressLength, dwRemoteAddressLength, lpdwBytesReceived, lpOverlapped)
__EXTERN INTEGER __CALL_1 AcceptEx(SYSTEM_PTR sListenSocket, SYSTEM_PTR sAcceptSocket, SYSTEM_PTR lpOutputBuffer, INTEGER dwReceiveDataLength, INTEGER dwLocalAddressLength, INTEGER dwRemoteAddressLength, INTEGER *lpdwBytesReceived, WinApi_OVERLAPPED *lpOverlapped);
#define WinNet_FIONBIO()	WinNet__IOW('f', 126, unsigned long)
#define WinNet_GetAcceptExSockaddrs(lpOutputBuffer, dwReceiveDataLength, dwLocalAddressLength, dwRemoteAddressLength, LocalSockaddr, LocalSockaddrLength, RemoteSockaddr, RemoteSockaddrLength)	GetAcceptExSockaddrs(lpOutputBuffer, dwReceiveDataLength, dwLocalAddressLength, dwRemoteAddressLength, LocalSockaddr, LocalSockaddrLength, RemoteSockaddr, RemoteSockaddrLength)
__EXTERN void __CALL_1 GetAcceptExSockaddrs(SYSTEM_PTR lpOutputBuffer, INTEGER dwReceiveDataLength, INTEGER dwLocalAddressLength, INTEGER dwRemoteAddressLength, WinNet_Ptrsockaddr *LocalSockaddr, INTEGER *LocalSockaddrLength, WinNet_Ptrsockaddr *RemoteSockaddr, INTEGER *RemoteSockaddrLength);
#define WinNet_IOCPARM_MASK_F()	0x7f
#define WinNet_IOC_IN_F()	0x80000000
#define WinNet_MultinetGetConnectionPerformance(lpNetResource, lpNetResource__typ, lpNetConnectInfoStruct, lpNetConnectInfoStruct__typ)	MultinetGetConnectionPerformanceA(lpNetResource, lpNetConnectInfoStruct)
#define WinNet_MultinetGetConnectionPerformanceA(lpNetResource, lpNetResource__typ, lpNetConnectInfoStruct, lpNetConnectInfoStruct__typ)	MultinetGetConnectionPerformanceA(lpNetResource, lpNetConnectInfoStruct)
__EXTERN INTEGER __CALL_1 MultinetGetConnectionPerformanceA(WinNet_NETRESOURCEA *lpNetResource, WinNet_NETCONNECTINFOSTRUCT *lpNetConnectInfoStruct);
#define WinNet_MultinetGetConnectionPerformanceW(lpNetResource, lpNetResource__typ, lpNetConnectInfoStruct, lpNetConnectInfoStruct__typ)	MultinetGetConnectionPerformanceW(lpNetResource, lpNetConnectInfoStruct)
__EXTERN INTEGER __CALL_1 MultinetGetConnectionPerformanceW(WinNet_NETRESOURCEW *lpNetResource, WinNet_NETCONNECTINFOSTRUCT *lpNetConnectInfoStruct);
#define WinNet_Netbios(pncb, pncb__typ)	Netbios(pncb)
__EXTERN CHAR __CALL_1 Netbios(WinNet_NCB *pncb);
#define WinNet_TransmitFile(hSocket, hFile, nNumberOfBytesToWrite, nNumberOfBytesPerSend, lpOverlapped, lpOverlapped__typ, lpTransmitBuffers, lpTransmitBuffers__typ, dwReserved)	TransmitFile(hSocket, hFile, nNumberOfBytesToWrite, nNumberOfBytesPerSend, lpOverlapped, lpTransmitBuffers, dwReserved)
__EXTERN INTEGER __CALL_1 TransmitFile(SYSTEM_PTR hSocket, SYSTEM_PTR hFile, INTEGER nNumberOfBytesToWrite, INTEGER nNumberOfBytesPerSend, WinApi_OVERLAPPED *lpOverlapped, WinNet_TRANSMIT_FILE_BUFFERS *lpTransmitBuffers, INTEGER dwReserved);
#define WinNet_WNetAddConnection(lpRemoteName, lpPassword, lpLocalName)	WNetAddConnectionA(lpRemoteName, lpPassword, lpLocalName)
#define WinNet_WNetAddConnection2(lpNetResource, lpNetResource__typ, lpPassword, lpUserName, dwFlags)	WNetAddConnection2A(lpNetResource, lpPassword, lpUserName, dwFlags)
#define WinNet_WNetAddConnection2A(lpNetResource, lpNetResource__typ, lpPassword, lpUserName, dwFlags)	WNetAddConnection2A(lpNetResource, lpPassword, lpUserName, dwFlags)
__EXTERN INTEGER __CALL_1 WNetAddConnection2A(WinNet_NETRESOURCEA *lpNetResource, SYSTEM_PTR lpPassword, SYSTEM_PTR lpUserName, SET dwFlags);
#define WinNet_WNetAddConnection2W(lpNetResource, lpNetResource__typ, lpPassword, lpUserName, dwFlags)	WNetAddConnection2W(lpNetResource, lpPassword, lpUserName, dwFlags)
__EXTERN INTEGER __CALL_1 WNetAddConnection2W(WinNet_NETRESOURCEW *lpNetResource, SYSTEM_PTR lpPassword, SYSTEM_PTR lpUserName, SET dwFlags);
#define WinNet_WNetAddConnection3(hwndOwner, lpNetResource, lpNetResource__typ, lpPassword, lpUserName, dwFlags)	WNetAddConnection3A(hwndOwner, lpNetResource, lpPassword, lpUserName, dwFlags)
#define WinNet_WNetAddConnection3A(hwndOwner, lpNetResource, lpNetResource__typ, lpPassword, lpUserName, dwFlags)	WNetAddConnection3A(hwndOwner, lpNetResource, lpPassword, lpUserName, dwFlags)
__EXTERN INTEGER __CALL_1 WNetAddConnection3A(SYSTEM_PTR hwndOwner, WinNet_NETRESOURCEA *lpNetResource, SYSTEM_PTR lpPassword, SYSTEM_PTR lpUserName, SET dwFlags);
#define WinNet_WNetAddConnection3W(hwndOwner, lpNetResource, lpNetResource__typ, lpPassword, lpUserName, dwFlags)	WNetAddConnection3W(hwndOwner, lpNetResource, lpPassword, lpUserName, dwFlags)
__EXTERN INTEGER __CALL_1 WNetAddConnection3W(SYSTEM_PTR hwndOwner, WinNet_NETRESOURCEW *lpNetResource, SYSTEM_PTR lpPassword, SYSTEM_PTR lpUserName, SET dwFlags);
#define WinNet_WNetAddConnectionA(lpRemoteName, lpPassword, lpLocalName)	WNetAddConnectionA(lpRemoteName, lpPassword, lpLocalName)
__EXTERN INTEGER __CALL_1 WNetAddConnectionA(SYSTEM_PTR lpRemoteName, SYSTEM_PTR lpPassword, SYSTEM_PTR lpLocalName);
#define WinNet_WNetAddConnectionW(lpRemoteName, lpPassword, lpLocalName)	WNetAddConnectionW(lpRemoteName, lpPassword, lpLocalName)
__EXTERN INTEGER __CALL_1 WNetAddConnectionW(SYSTEM_PTR lpRemoteName, SYSTEM_PTR lpPassword, SYSTEM_PTR lpLocalName);
#define WinNet_WNetCancelConnection(lpName, fForce)	WNetCancelConnectionA(lpName, fForce)
#define WinNet_WNetCancelConnection2(lpName, dwFlags, fForce)	WNetCancelConnection2A(lpName, dwFlags, fForce)
#define WinNet_WNetCancelConnection2A(lpName, dwFlags, fForce)	WNetCancelConnection2A(lpName, dwFlags, fForce)
__EXTERN INTEGER __CALL_1 WNetCancelConnection2A(SYSTEM_PTR lpName, SET dwFlags, INTEGER fForce);
#define WinNet_WNetCancelConnection2W(lpName, dwFlags, fForce)	WNetCancelConnection2W(lpName, dwFlags, fForce)
__EXTERN INTEGER __CALL_1 WNetCancelConnection2W(SYSTEM_PTR lpName, SET dwFlags, INTEGER fForce);
#define WinNet_WNetCancelConnectionA(lpName, fForce)	WNetCancelConnectionA(lpName, fForce)
__EXTERN INTEGER __CALL_1 WNetCancelConnectionA(SYSTEM_PTR lpName, INTEGER fForce);
#define WinNet_WNetCancelConnectionW(lpName, fForce)	WNetCancelConnectionW(lpName, fForce)
__EXTERN INTEGER __CALL_1 WNetCancelConnectionW(SYSTEM_PTR lpName, INTEGER fForce);
#define WinNet_WNetCloseEnum(hEnum)	WNetCloseEnum(hEnum)
__EXTERN INTEGER __CALL_1 WNetCloseEnum(SYSTEM_PTR hEnum);
#define WinNet_WNetConnectionDialog(hwnd, dwType)	WNetConnectionDialog(hwnd, dwType)
__EXTERN INTEGER __CALL_1 WNetConnectionDialog(SYSTEM_PTR hwnd, INTEGER dwType);
#define WinNet_WNetConnectionDialog1(lpConnDlgStruct, lpConnDlgStruct__typ)	WNetConnectionDialog1A(lpConnDlgStruct)
#define WinNet_WNetConnectionDialog1A(lpConnDlgStruct, lpConnDlgStruct__typ)	WNetConnectionDialog1A(lpConnDlgStruct)
__EXTERN INTEGER __CALL_1 WNetConnectionDialog1A(WinNet_CONNECTDLGSTRUCTA *lpConnDlgStruct);
#define WinNet_WNetConnectionDialog1W(lpConnDlgStruct, lpConnDlgStruct__typ)	WNetConnectionDialog1W(lpConnDlgStruct)
__EXTERN INTEGER __CALL_1 WNetConnectionDialog1W(WinNet_CONNECTDLGSTRUCTW *lpConnDlgStruct);
#define WinNet_WNetDisconnectDialog(hwnd, dwType)	WNetDisconnectDialog(hwnd, dwType)
__EXTERN INTEGER __CALL_1 WNetDisconnectDialog(SYSTEM_PTR hwnd, INTEGER dwType);
#define WinNet_WNetDisconnectDialog1(lpConnDlgStruct, lpConnDlgStruct__typ)	WNetDisconnectDialog1A(lpConnDlgStruct)
#define WinNet_WNetDisconnectDialog1A(lpConnDlgStruct, lpConnDlgStruct__typ)	WNetDisconnectDialog1A(lpConnDlgStruct)
__EXTERN INTEGER __CALL_1 WNetDisconnectDialog1A(WinNet_DISCDLGSTRUCTA *lpConnDlgStruct);
#define WinNet_WNetDisconnectDialog1W(lpConnDlgStruct, lpConnDlgStruct__typ)	WNetDisconnectDialog1W(lpConnDlgStruct)
__EXTERN INTEGER __CALL_1 WNetDisconnectDialog1W(WinNet_DISCDLGSTRUCTW *lpConnDlgStruct);
#define WinNet_WNetEnumResource(hEnum, lpcCount, lpBuffer, lpBufferSize)	WNetEnumResourceA(hEnum, lpcCount, lpBuffer, lpBufferSize)
#define WinNet_WNetEnumResourceA(hEnum, lpcCount, lpBuffer, lpBufferSize)	WNetEnumResourceA(hEnum, lpcCount, lpBuffer, lpBufferSize)
__EXTERN INTEGER __CALL_1 WNetEnumResourceA(SYSTEM_PTR hEnum, INTEGER *lpcCount, SYSTEM_PTR lpBuffer, INTEGER *lpBufferSize);
#define WinNet_WNetEnumResourceW(hEnum, lpcCount, lpBuffer, lpBufferSize)	WNetEnumResourceW(hEnum, lpcCount, lpBuffer, lpBufferSize)
__EXTERN INTEGER __CALL_1 WNetEnumResourceW(SYSTEM_PTR hEnum, INTEGER *lpcCount, SYSTEM_PTR lpBuffer, INTEGER *lpBufferSize);
#define WinNet_WNetGetConnection(lpLocalName, lpRemoteName, lpnLength)	WNetGetConnectionA(lpLocalName, lpRemoteName, lpnLength)
#define WinNet_WNetGetConnectionA(lpLocalName, lpRemoteName, lpnLength)	WNetGetConnectionA(lpLocalName, lpRemoteName, lpnLength)
__EXTERN INTEGER __CALL_1 WNetGetConnectionA(SYSTEM_PTR lpLocalName, SYSTEM_PTR lpRemoteName, INTEGER *lpnLength);
#define WinNet_WNetGetConnectionW(lpLocalName, lpRemoteName, lpnLength)	WNetGetConnectionW(lpLocalName, lpRemoteName, lpnLength)
__EXTERN INTEGER __CALL_1 WNetGetConnectionW(SYSTEM_PTR lpLocalName, SYSTEM_PTR lpRemoteName, INTEGER *lpnLength);
#define WinNet_WNetGetLastError(lpError, lpErrorBuf, nErrorBufSize, lpNameBuf, nNameBufSize)	WNetGetLastErrorA(lpError, lpErrorBuf, nErrorBufSize, lpNameBuf, nNameBufSize)
#define WinNet_WNetGetLastErrorA(lpError, lpErrorBuf, nErrorBufSize, lpNameBuf, nNameBufSize)	WNetGetLastErrorA(lpError, lpErrorBuf, nErrorBufSize, lpNameBuf, nNameBufSize)
__EXTERN INTEGER __CALL_1 WNetGetLastErrorA(INTEGER *lpError, SYSTEM_PTR lpErrorBuf, INTEGER nErrorBufSize, SYSTEM_PTR lpNameBuf, INTEGER nNameBufSize);
#define WinNet_WNetGetLastErrorW(lpError, lpErrorBuf, nErrorBufSize, lpNameBuf, nNameBufSize)	WNetGetLastErrorW(lpError, lpErrorBuf, nErrorBufSize, lpNameBuf, nNameBufSize)
__EXTERN INTEGER __CALL_1 WNetGetLastErrorW(INTEGER *lpError, SYSTEM_PTR lpErrorBuf, INTEGER nErrorBufSize, SYSTEM_PTR lpNameBuf, INTEGER nNameBufSize);
#define WinNet_WNetGetNetworkInformation(lpProvider, lpNetInfoStruct, lpNetInfoStruct__typ)	WNetGetNetworkInformationA(lpProvider, lpNetInfoStruct)
#define WinNet_WNetGetNetworkInformationA(lpProvider, lpNetInfoStruct, lpNetInfoStruct__typ)	WNetGetNetworkInformationA(lpProvider, lpNetInfoStruct)
__EXTERN INTEGER __CALL_1 WNetGetNetworkInformationA(SYSTEM_PTR lpProvider, WinNet_NETINFOSTRUCT *lpNetInfoStruct);
#define WinNet_WNetGetNetworkInformationW(lpProvider, lpNetInfoStruct, lpNetInfoStruct__typ)	WNetGetNetworkInformationW(lpProvider, lpNetInfoStruct)
__EXTERN INTEGER __CALL_1 WNetGetNetworkInformationW(SYSTEM_PTR lpProvider, WinNet_NETINFOSTRUCT *lpNetInfoStruct);
#define WinNet_WNetGetProviderName(dwNetType, lpProviderName, lpBufferSize)	WNetGetProviderNameA(dwNetType, lpProviderName, lpBufferSize)
#define WinNet_WNetGetProviderNameA(dwNetType, lpProviderName, lpBufferSize)	WNetGetProviderNameA(dwNetType, lpProviderName, lpBufferSize)
__EXTERN INTEGER __CALL_1 WNetGetProviderNameA(INTEGER dwNetType, SYSTEM_PTR lpProviderName, INTEGER *lpBufferSize);
#define WinNet_WNetGetProviderNameW(dwNetType, lpProviderName, lpBufferSize)	WNetGetProviderNameW(dwNetType, lpProviderName, lpBufferSize)
__EXTERN INTEGER __CALL_1 WNetGetProviderNameW(INTEGER dwNetType, SYSTEM_PTR lpProviderName, INTEGER *lpBufferSize);
#define WinNet_WNetGetResourceInformation(lpNetResource, lpNetResource__typ, lpBuffer, cbBuffer, lplpSystem)	WNetGetResourceInformationA(lpNetResource, lpBuffer, cbBuffer, lplpSystem)
#define WinNet_WNetGetResourceInformationA(lpNetResource, lpNetResource__typ, lpBuffer, cbBuffer, lplpSystem)	WNetGetResourceInformationA(lpNetResource, lpBuffer, cbBuffer, lplpSystem)
__EXTERN INTEGER __CALL_1 WNetGetResourceInformationA(WinNet_NETRESOURCEA *lpNetResource, SYSTEM_PTR lpBuffer, INTEGER *cbBuffer, SYSTEM_PTR *lplpSystem);
#define WinNet_WNetGetResourceInformationW(lpNetResource, lpNetResource__typ, lpBuffer, cbBuffer, lplpSystem)	WNetGetResourceInformationW(lpNetResource, lpBuffer, cbBuffer, lplpSystem)
__EXTERN INTEGER __CALL_1 WNetGetResourceInformationW(WinNet_NETRESOURCEW *lpNetResource, SYSTEM_PTR lpBuffer, INTEGER *cbBuffer, SYSTEM_PTR *lplpSystem);
#define WinNet_WNetGetResourceParent(lpNetResource, lpNetResource__typ, lpBuffer, cbBuffer)	WNetGetResourceParentA(lpNetResource, lpBuffer, cbBuffer)
#define WinNet_WNetGetResourceParentA(lpNetResource, lpNetResource__typ, lpBuffer, cbBuffer)	WNetGetResourceParentA(lpNetResource, lpBuffer, cbBuffer)
__EXTERN INTEGER __CALL_1 WNetGetResourceParentA(WinNet_NETRESOURCEA *lpNetResource, SYSTEM_PTR lpBuffer, INTEGER *cbBuffer);
#define WinNet_WNetGetResourceParentW(lpNetResource, lpNetResource__typ, lpBuffer, cbBuffer)	WNetGetResourceParentW(lpNetResource, lpBuffer, cbBuffer)
__EXTERN INTEGER __CALL_1 WNetGetResourceParentW(WinNet_NETRESOURCEW *lpNetResource, SYSTEM_PTR lpBuffer, INTEGER *cbBuffer);
#define WinNet_WNetGetUniversalName(lpLocalPath, dwInfoLevel, lpBuffer, lpBufferSize)	WNetGetUniversalNameA(lpLocalPath, dwInfoLevel, lpBuffer, lpBufferSize)
#define WinNet_WNetGetUniversalNameA(lpLocalPath, dwInfoLevel, lpBuffer, lpBufferSize)	WNetGetUniversalNameA(lpLocalPath, dwInfoLevel, lpBuffer, lpBufferSize)
__EXTERN INTEGER __CALL_1 WNetGetUniversalNameA(SYSTEM_PTR lpLocalPath, INTEGER dwInfoLevel, SYSTEM_PTR lpBuffer, INTEGER *lpBufferSize);
#define WinNet_WNetGetUniversalNameW(lpLocalPath, dwInfoLevel, lpBuffer, lpBufferSize)	WNetGetUniversalNameW(lpLocalPath, dwInfoLevel, lpBuffer, lpBufferSize)
__EXTERN INTEGER __CALL_1 WNetGetUniversalNameW(SYSTEM_PTR lpLocalPath, INTEGER dwInfoLevel, SYSTEM_PTR lpBuffer, INTEGER *lpBufferSize);
#define WinNet_WNetGetUser(lpName, lpUserName, lpnLength)	WNetGetUserA(lpName, lpUserName, lpnLength)
#define WinNet_WNetGetUserA(lpName, lpUserName, lpnLength)	WNetGetUserA(lpName, lpUserName, lpnLength)
__EXTERN INTEGER __CALL_1 WNetGetUserA(SYSTEM_PTR lpName, SYSTEM_PTR lpUserName, INTEGER *lpnLength);
#define WinNet_WNetGetUserW(lpName, lpUserName, lpnLength)	WNetGetUserW(lpName, lpUserName, lpnLength)
__EXTERN INTEGER __CALL_1 WNetGetUserW(SYSTEM_PTR lpName, SYSTEM_PTR lpUserName, INTEGER *lpnLength);
#define WinNet_WNetOpenEnum(dwScope, dwType, dwUsage, lpNetResource, lpNetResource__typ, lphEnum)	WNetOpenEnumA(dwScope, dwType, dwUsage, lpNetResource, lphEnum)
#define WinNet_WNetOpenEnumA(dwScope, dwType, dwUsage, lpNetResource, lpNetResource__typ, lphEnum)	WNetOpenEnumA(dwScope, dwType, dwUsage, lpNetResource, lphEnum)
__EXTERN INTEGER __CALL_1 WNetOpenEnumA(INTEGER dwScope, INTEGER dwType, INTEGER dwUsage, WinNet_NETRESOURCEA *lpNetResource, SYSTEM_PTR *lphEnum);
#define WinNet_WNetOpenEnumW(dwScope, dwType, dwUsage, lpNetResource, lpNetResource__typ, lphEnum)	WNetOpenEnumW(dwScope, dwType, dwUsage, lpNetResource, lphEnum)
__EXTERN INTEGER __CALL_1 WNetOpenEnumW(INTEGER dwScope, INTEGER dwType, INTEGER dwUsage, WinNet_NETRESOURCEW *lpNetResource, SYSTEM_PTR *lphEnum);
#define WinNet_WNetSetConnection(lpName, dwProperties, pvValues)	WNetSetConnectionA(lpName, dwProperties, pvValues)
#define WinNet_WNetSetConnectionA(lpName, dwProperties, pvValues)	WNetSetConnectionA(lpName, dwProperties, pvValues)
__EXTERN INTEGER __CALL_1 WNetSetConnectionA(SYSTEM_PTR lpName, INTEGER dwProperties, SYSTEM_PTR pvValues);
#define WinNet_WNetSetConnectionW(lpName, dwProperties, pvValues)	WNetSetConnectionW(lpName, dwProperties, pvValues)
__EXTERN INTEGER __CALL_1 WNetSetConnectionW(SYSTEM_PTR lpName, INTEGER dwProperties, SYSTEM_PTR pvValues);
#define WinNet_WNetUseConnection(hwndOwner, lpNetResource, lpNetResource__typ, lpUserID, lpPassword, dwFlags, lpAccessName, lpBufferSize, lpResult)	WNetUseConnectionA(hwndOwner, lpNetResource, lpUserID, lpPassword, dwFlags, lpAccessName, lpBufferSize, lpResult)
#define WinNet_WNetUseConnectionA(hwndOwner, lpNetResource, lpNetResource__typ, lpUserID, lpPassword, dwFlags, lpAccessName, lpBufferSize, lpResult)	WNetUseConnectionA(hwndOwner, lpNetResource, lpUserID, lpPassword, dwFlags, lpAccessName, lpBufferSize, lpResult)
__EXTERN INTEGER __CALL_1 WNetUseConnectionA(SYSTEM_PTR hwndOwner, WinNet_NETRESOURCEA *lpNetResource, SYSTEM_PTR lpUserID, SYSTEM_PTR lpPassword, SET dwFlags, SYSTEM_PTR lpAccessName, INTEGER *lpBufferSize, INTEGER *lpResult);
#define WinNet_WNetUseConnectionW(hwndOwner, lpNetResource, lpNetResource__typ, lpUserID, lpPassword, dwFlags, lpAccessName, lpBufferSize, lpResult)	WNetUseConnectionW(hwndOwner, lpNetResource, lpUserID, lpPassword, dwFlags, lpAccessName, lpBufferSize, lpResult)
__EXTERN INTEGER __CALL_1 WNetUseConnectionW(SYSTEM_PTR hwndOwner, WinNet_NETRESOURCEW *lpNetResource, SYSTEM_PTR lpUserID, SYSTEM_PTR lpPassword, SET dwFlags, SYSTEM_PTR lpAccessName, INTEGER *lpBufferSize, INTEGER *lpResult);
#define WinNet_WSAAccept(s, addr, addr__typ, addrlen, lpfnCondition, dwCallbackData)	WSAAccept(s, addr, addrlen, lpfnCondition, dwCallbackData)
__EXTERN SYSTEM_PTR __CALL_1 WSAAccept(SYSTEM_PTR s, WinNet_sockaddr *addr, INTEGER *addrlen, WinNet_CONDITIONPROC lpfnCondition, INTEGER dwCallbackData);
#define WinNet_WSAAsyncGetHostByAddr(hWnd, wMsg, addr, len, type, buf, buflen)	WSAAsyncGetHostByAddr(hWnd, wMsg, addr, len, type, buf, buflen)
__EXTERN SYSTEM_PTR __CALL_1 WSAAsyncGetHostByAddr(SYSTEM_PTR hWnd, INTEGER wMsg, SYSTEM_PTR addr, INTEGER len, INTEGER type, SYSTEM_PTR buf, INTEGER buflen);
#define WinNet_WSAAsyncGetHostByName(hWnd, wMsg, name, buf, buflen)	WSAAsyncGetHostByName(hWnd, wMsg, name, buf, buflen)
__EXTERN SYSTEM_PTR __CALL_1 WSAAsyncGetHostByName(SYSTEM_PTR hWnd, INTEGER wMsg, SYSTEM_PTR name, SYSTEM_PTR buf, INTEGER buflen);
#define WinNet_WSAAsyncGetProtoByName(hWnd, wMsg, name, buf, buflen)	WSAAsyncGetProtoByName(hWnd, wMsg, name, buf, buflen)
__EXTERN SYSTEM_PTR __CALL_1 WSAAsyncGetProtoByName(SYSTEM_PTR hWnd, INTEGER wMsg, SYSTEM_PTR name, SYSTEM_PTR buf, INTEGER buflen);
#define WinNet_WSAAsyncGetProtoByNumber(hWnd, wMsg, number, buf, buflen)	WSAAsyncGetProtoByNumber(hWnd, wMsg, number, buf, buflen)
__EXTERN SYSTEM_PTR __CALL_1 WSAAsyncGetProtoByNumber(SYSTEM_PTR hWnd, INTEGER wMsg, INTEGER number, SYSTEM_PTR buf, INTEGER buflen);
#define WinNet_WSAAsyncGetServByName(hWnd, wMsg, name, proto, buf, buflen)	WSAAsyncGetServByName(hWnd, wMsg, name, proto, buf, buflen)
__EXTERN SYSTEM_PTR __CALL_1 WSAAsyncGetServByName(SYSTEM_PTR hWnd, INTEGER wMsg, SYSTEM_PTR name, SYSTEM_PTR proto, SYSTEM_PTR buf, INTEGER buflen);
#define WinNet_WSAAsyncGetServByPort(hWnd, wMsg, port, proto, buf, buflen)	WSAAsyncGetServByPort(hWnd, wMsg, port, proto, buf, buflen)
__EXTERN SYSTEM_PTR __CALL_1 WSAAsyncGetServByPort(SYSTEM_PTR hWnd, INTEGER wMsg, INTEGER port, SYSTEM_PTR proto, SYSTEM_PTR buf, INTEGER buflen);
#define WinNet_WSAAsyncSelect(s, hWnd, wMsg, lEvent)	WSAAsyncSelect(s, hWnd, wMsg, lEvent)
__EXTERN INTEGER __CALL_1 WSAAsyncSelect(SYSTEM_PTR s, SYSTEM_PTR hWnd, INTEGER wMsg, INTEGER lEvent);
#define WinNet_WSACancelAsyncRequest(hAsyncTaskHandle)	WSACancelAsyncRequest(hAsyncTaskHandle)
__EXTERN INTEGER __CALL_1 WSACancelAsyncRequest(SYSTEM_PTR hAsyncTaskHandle);
#define WinNet_WSACancelBlockingCall()	WSACancelBlockingCall()
__EXTERN INTEGER __CALL_1 WSACancelBlockingCall(void);
#define WinNet_WSACleanup()	WSACleanup()
__EXTERN INTEGER __CALL_1 WSACleanup(void);
#define WinNet_WSACloseEvent(hEvent)	WSACloseEvent(hEvent)
__EXTERN INTEGER __CALL_1 WSACloseEvent(INTEGER hEvent);
#define WinNet_WSAConnect(s, name, name__typ, namelen, lpCallerData, lpCallerData__typ, lpCalleeData, lpCalleeData__typ, lpSQOS, lpSQOS__typ, lpGQOS, lpGQOS__typ)	WSAConnect(s, name, namelen, lpCallerData, lpCalleeData, lpSQOS, lpGQOS)
__EXTERN INTEGER __CALL_1 WSAConnect(SYSTEM_PTR s, WinNet_sockaddr *name, INTEGER namelen, WinNet_WSABUF *lpCallerData, WinNet_WSABUF *lpCalleeData, WinNet_QOS *lpSQOS, WinNet_QOS *lpGQOS);
#define WinNet_WSACreateEvent()	WSACreateEvent()
__EXTERN INTEGER __CALL_1 WSACreateEvent(void);
#define WinNet_WSADuplicateSocket(s, dwProcessId, lpProtocolInfo, lpProtocolInfo__typ)	WSADuplicateSocketA(s, dwProcessId, lpProtocolInfo)
#define WinNet_WSADuplicateSocketA(s, dwProcessId, lpProtocolInfo, lpProtocolInfo__typ)	WSADuplicateSocketA(s, dwProcessId, lpProtocolInfo)
__EXTERN INTEGER __CALL_1 WSADuplicateSocketA(SYSTEM_PTR s, INTEGER dwProcessId, WinNet_WSAPROTOCOL_INFOA *lpProtocolInfo);
#define WinNet_WSADuplicateSocketW(s, dwProcessId, lpProtocolInfo, lpProtocolInfo__typ)	WSADuplicateSocketW(s, dwProcessId, lpProtocolInfo)
__EXTERN INTEGER __CALL_1 WSADuplicateSocketW(SYSTEM_PTR s, INTEGER dwProcessId, WinNet_WSAPROTOCOL_INFOW *lpProtocolInfo);
#define WinNet_WSAEnumNetworkEvents(s, hEventObject, lpNetworkEvents, lpNetworkEvents__typ)	WSAEnumNetworkEvents(s, hEventObject, lpNetworkEvents)
__EXTERN INTEGER __CALL_1 WSAEnumNetworkEvents(SYSTEM_PTR s, INTEGER hEventObject, WinNet_WSANETWORKEVENTS *lpNetworkEvents);
#define WinNet_WSAEnumProtocols(lpiProtocols, lpProtocolBuffer, lpProtocolBuffer__typ, lpdwBufferLength)	WSAEnumProtocolsA(lpiProtocols, lpProtocolBuffer, lpdwBufferLength)
#define WinNet_WSAEnumProtocolsA(lpiProtocols, lpProtocolBuffer, lpProtocolBuffer__typ, lpdwBufferLength)	WSAEnumProtocolsA(lpiProtocols, lpProtocolBuffer, lpdwBufferLength)
__EXTERN INTEGER __CALL_1 WSAEnumProtocolsA(INTEGER *lpiProtocols, WinNet_WSAPROTOCOL_INFOA *lpProtocolBuffer, INTEGER *lpdwBufferLength);
#define WinNet_WSAEnumProtocolsW(lpiProtocols, lpProtocolBuffer, lpProtocolBuffer__typ, lpdwBufferLength)	WSAEnumProtocolsW(lpiProtocols, lpProtocolBuffer, lpdwBufferLength)
__EXTERN INTEGER __CALL_1 WSAEnumProtocolsW(INTEGER *lpiProtocols, WinNet_WSAPROTOCOL_INFOW *lpProtocolBuffer, INTEGER *lpdwBufferLength);
#define WinNet_WSAEventSelect(s, hEventObject, lNetworkEvents)	WSAEventSelect(s, hEventObject, lNetworkEvents)
__EXTERN INTEGER __CALL_1 WSAEventSelect(SYSTEM_PTR s, INTEGER hEventObject, INTEGER lNetworkEvents);
#define WinNet_WSAGetLastError()	WSAGetLastError()
__EXTERN INTEGER __CALL_1 WSAGetLastError(void);
#define WinNet_WSAGetOverlappedResult(s, lpOverlapped, lpOverlapped__typ, lpcbTransfer, fWait, lpdwFlags)	WSAGetOverlappedResult(s, lpOverlapped, lpcbTransfer, fWait, lpdwFlags)
__EXTERN INTEGER __CALL_1 WSAGetOverlappedResult(SYSTEM_PTR s, WinNet_WSAOVERLAPPED *lpOverlapped, INTEGER *lpcbTransfer, INTEGER fWait, SET *lpdwFlags);
#define WinNet_WSAGetQOSByName(s, lpQOSName, lpQOSName__typ, lpQOS, lpQOS__typ)	WSAGetQOSByName(s, lpQOSName, lpQOS)
__EXTERN INTEGER __CALL_1 WSAGetQOSByName(SYSTEM_PTR s, WinNet_WSABUF *lpQOSName, WinNet_QOS *lpQOS);
#define WinNet_WSAHtonl(s, hostlong, lpnetlong)	WSAHtonl(s, hostlong, lpnetlong)
__EXTERN INTEGER __CALL_1 WSAHtonl(SYSTEM_PTR s, INTEGER hostlong, INTEGER *lpnetlong);
#define WinNet_WSAHtons(s, hostshort, lpnetshort)	WSAHtons(s, hostshort, lpnetshort)
__EXTERN INTEGER __CALL_1 WSAHtons(SYSTEM_PTR s, SHORTINT hostshort, SHORTINT *lpnetshort);
#define WinNet_WSAIoctl(s, dwIoControlCode, lpvInBuffer, cbInBuffer, lpvOutBuffer, cbOutBuffer, lpcbBytesReturned, lpOverlapped, lpOverlapped__typ, lpCompletionRoutine)	WSAIoctl(s, dwIoControlCode, lpvInBuffer, cbInBuffer, lpvOutBuffer, cbOutBuffer, lpcbBytesReturned, lpOverlapped, lpCompletionRoutine)
__EXTERN INTEGER __CALL_1 WSAIoctl(SYSTEM_PTR s, INTEGER dwIoControlCode, SYSTEM_PTR lpvInBuffer, INTEGER cbInBuffer, SYSTEM_PTR lpvOutBuffer, INTEGER cbOutBuffer, INTEGER *lpcbBytesReturned, WinNet_WSAOVERLAPPED *lpOverlapped, WinNet_WSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinNet_WSAIsBlocking()	WSAIsBlocking()
__EXTERN INTEGER __CALL_1 WSAIsBlocking(void);
#define WinNet_WSAJoinLeaf(s, name, name__typ, namelen, lpCallerData, lpCallerData__typ, lpCalleeData, lpCalleeData__typ, lpSQOS, lpSQOS__typ, lpGQOS, lpGQOS__typ, dwFlags)	WSAJoinLeaf(s, name, namelen, lpCallerData, lpCalleeData, lpSQOS, lpGQOS, dwFlags)
__EXTERN SYSTEM_PTR __CALL_1 WSAJoinLeaf(SYSTEM_PTR s, WinNet_sockaddr *name, INTEGER namelen, WinNet_WSABUF *lpCallerData, WinNet_WSABUF *lpCalleeData, WinNet_QOS *lpSQOS, WinNet_QOS *lpGQOS, SET dwFlags);
#define WinNet_WSANtohl(s, netlong, lphostlong)	WSANtohl(s, netlong, lphostlong)
__EXTERN INTEGER __CALL_1 WSANtohl(SYSTEM_PTR s, INTEGER netlong, INTEGER *lphostlong);
#define WinNet_WSANtohs(s, netshort, lphostshort)	WSANtohs(s, netshort, lphostshort)
__EXTERN INTEGER __CALL_1 WSANtohs(SYSTEM_PTR s, SHORTINT netshort, SHORTINT *lphostshort);
#define WinNet_WSARecv(s, lpBuffers, lpBuffers__typ, dwBufferCount, lpNumberOfBytesRecvd, lpFlags, lpOverlapped, lpOverlapped__typ, lpCompletionRoutine)	WSARecv(s, lpBuffers, dwBufferCount, lpNumberOfBytesRecvd, lpFlags, lpOverlapped, lpCompletionRoutine)
__EXTERN INTEGER __CALL_1 WSARecv(SYSTEM_PTR s, WinNet_WSABUF *lpBuffers, INTEGER dwBufferCount, INTEGER *lpNumberOfBytesRecvd, INTEGER *lpFlags, WinNet_WSAOVERLAPPED *lpOverlapped, WinNet_WSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinNet_WSARecvDisconnect(s, lpInboundDisconnectData, lpInboundDisconnectData__typ)	WSARecvDisconnect(s, lpInboundDisconnectData)
__EXTERN INTEGER __CALL_1 WSARecvDisconnect(SYSTEM_PTR s, WinNet_WSABUF *lpInboundDisconnectData);
#define WinNet_WSARecvEx(s, buf, len, flags)	WSARecvEx(s, buf, len, flags)
__EXTERN INTEGER __CALL_1 WSARecvEx(SYSTEM_PTR s, SYSTEM_PTR buf, INTEGER len, SET *flags);
#define WinNet_WSARecvFrom(s, lpBuffers, lpBuffers__typ, dwBufferCount, lpNumberOfBytesRecvd, lpFlags, lpFrom, lpFrom__typ, lpFromlen, lpOverlapped, lpOverlapped__typ, lpCompletionRoutine)	WSARecvFrom(s, lpBuffers, dwBufferCount, lpNumberOfBytesRecvd, lpFlags, lpFrom, lpFromlen, lpOverlapped, lpCompletionRoutine)
__EXTERN INTEGER __CALL_1 WSARecvFrom(SYSTEM_PTR s, WinNet_WSABUF *lpBuffers, INTEGER dwBufferCount, INTEGER *lpNumberOfBytesRecvd, INTEGER *lpFlags, WinNet_sockaddr *lpFrom, INTEGER *lpFromlen, WinNet_WSAOVERLAPPED *lpOverlapped, WinNet_WSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinNet_WSAResetEvent(hEvent)	WSAResetEvent(hEvent)
__EXTERN INTEGER __CALL_1 WSAResetEvent(INTEGER hEvent);
#define WinNet_WSASend(s, lpBuffers, lpBuffers__typ, dwBufferCount, lpNumberOfBytesSent, dwFlags, lpOverlapped, lpOverlapped__typ, lpCompletionRoutine)	WSASend(s, lpBuffers, dwBufferCount, lpNumberOfBytesSent, dwFlags, lpOverlapped, lpCompletionRoutine)
__EXTERN INTEGER __CALL_1 WSASend(SYSTEM_PTR s, WinNet_WSABUF *lpBuffers, INTEGER dwBufferCount, INTEGER *lpNumberOfBytesSent, SET dwFlags, WinNet_WSAOVERLAPPED *lpOverlapped, WinNet_WSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinNet_WSASendDisconnect(s, lpOutboundDisconnectData, lpOutboundDisconnectData__typ)	WSASendDisconnect(s, lpOutboundDisconnectData)
__EXTERN INTEGER __CALL_1 WSASendDisconnect(SYSTEM_PTR s, WinNet_WSABUF *lpOutboundDisconnectData);
#define WinNet_WSASendTo(s, lpBuffers, lpBuffers__typ, dwBufferCount, lpNumberOfBytesSent, dwFlags, lpTo, lpTo__typ, iTolen, lpOverlapped, lpOverlapped__typ, lpCompletionRoutine)	WSASendTo(s, lpBuffers, dwBufferCount, lpNumberOfBytesSent, dwFlags, lpTo, iTolen, lpOverlapped, lpCompletionRoutine)
__EXTERN INTEGER __CALL_1 WSASendTo(SYSTEM_PTR s, WinNet_WSABUF *lpBuffers, INTEGER dwBufferCount, INTEGER *lpNumberOfBytesSent, SET dwFlags, WinNet_sockaddr *lpTo, INTEGER iTolen, WinNet_WSAOVERLAPPED *lpOverlapped, WinNet_WSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinNet_WSASetBlockingHook(lpBlockFunc)	WSASetBlockingHook(lpBlockFunc)
__EXTERN WinApi_FARPROC __CALL_1 WSASetBlockingHook(WinApi_FARPROC lpBlockFunc);
#define WinNet_WSASetEvent(hEvent)	WSASetEvent(hEvent)
__EXTERN INTEGER __CALL_1 WSASetEvent(INTEGER hEvent);
#define WinNet_WSASetLastError(iError)	WSASetLastError(iError)
__EXTERN void __CALL_1 WSASetLastError(INTEGER iError);
#define WinNet_WSASocket(af, type, protocol, lpProtocolInfo, lpProtocolInfo__typ, g, dwFlags)	WSASocketA(af, type, protocol, lpProtocolInfo, g, dwFlags)
#define WinNet_WSASocketA(af, type, protocol, lpProtocolInfo, lpProtocolInfo__typ, g, dwFlags)	WSASocketA(af, type, protocol, lpProtocolInfo, g, dwFlags)
__EXTERN SYSTEM_PTR __CALL_1 WSASocketA(INTEGER af, INTEGER type, INTEGER protocol, WinNet_WSAPROTOCOL_INFOA *lpProtocolInfo, INTEGER g, SET dwFlags);
#define WinNet_WSASocketW(af, type, protocol, lpProtocolInfo, lpProtocolInfo__typ, g, dwFlags)	WSASocketW(af, type, protocol, lpProtocolInfo, g, dwFlags)
__EXTERN SYSTEM_PTR __CALL_1 WSASocketW(INTEGER af, INTEGER type, INTEGER protocol, WinNet_WSAPROTOCOL_INFOW *lpProtocolInfo, INTEGER g, SET dwFlags);
#define WinNet_WSAStartup(wVersionRequested, lpWSAData, lpWSAData__typ)	WSAStartup(wVersionRequested, lpWSAData)
__EXTERN INTEGER __CALL_1 WSAStartup(SHORTINT wVersionRequested, WinNet_WSADATA *lpWSAData);
#define WinNet_WSAUnhookBlockingHook()	WSAUnhookBlockingHook()
__EXTERN INTEGER __CALL_1 WSAUnhookBlockingHook(void);
#define WinNet_WSAWaitForMultipleEvents(cEvents, lphEvents, fWaitAll, dwTimeout, fAlertable)	WSAWaitForMultipleEvents(cEvents, lphEvents, fWaitAll, dwTimeout, fAlertable)
__EXTERN INTEGER __CALL_1 WSAWaitForMultipleEvents(INTEGER cEvents, INTEGER *lphEvents, INTEGER fWaitAll, INTEGER dwTimeout, INTEGER fAlertable);
#define WinNet__IOW(x, y, t)	(WinNet_IOC_IN_F()|(((long)sizeof(t)&WinNet_IOCPARM_MASK_F())<<16)|((x)<<8)|(y))
#define WinNet___WSAFDIsSet(p0, p1, p1__typ)	__WSAFDIsSet(p0, p1)
__EXTERN INTEGER __CALL_1 __WSAFDIsSet(SYSTEM_PTR p0, WinNet_fd_set *p1);
#define WinNet__init()	/*-noinit*/
#define WinNet_accept(s, addr, addr__typ, addrlen)	accept(s, addr, addrlen)
__EXTERN SYSTEM_PTR __CALL_1 accept(SYSTEM_PTR s, WinNet_sockaddr *addr, INTEGER *addrlen);
#define WinNet_bind(s, name, name__typ, namelen)	bind(s, name, namelen)
__EXTERN INTEGER __CALL_1 bind(SYSTEM_PTR s, WinNet_sockaddr *name, INTEGER namelen);
#define WinNet_closesocket(s)	closesocket(s)
__EXTERN INTEGER __CALL_1 closesocket(SYSTEM_PTR s);
#define WinNet_connect(s, name, name__typ, namelen)	connect(s, name, namelen)
__EXTERN INTEGER __CALL_1 connect(SYSTEM_PTR s, WinNet_sockaddr *name, INTEGER namelen);
#define WinNet_gethostbyaddr(addr, len, type)	gethostbyaddr(addr, len, type)
__EXTERN WinNet_Ptrhostent __CALL_1 gethostbyaddr(SYSTEM_PTR addr, INTEGER len, INTEGER type);
#define WinNet_gethostbyname(name)	gethostbyname(name)
__EXTERN WinNet_Ptrhostent __CALL_1 gethostbyname(SYSTEM_PTR name);
#define WinNet_gethostname(name, namelen)	gethostname(name, namelen)
__EXTERN INTEGER __CALL_1 gethostname(SYSTEM_PTR name, INTEGER namelen);
#define WinNet_getpeername(s, name, name__typ, namelen)	getpeername(s, name, namelen)
__EXTERN INTEGER __CALL_1 getpeername(SYSTEM_PTR s, WinNet_sockaddr *name, INTEGER *namelen);
#define WinNet_getprotobyname(name)	getprotobyname(name)
__EXTERN WinNet_Ptrprotoent __CALL_1 getprotobyname(SYSTEM_PTR name);
#define WinNet_getprotobynumber(number)	getprotobynumber(number)
__EXTERN WinNet_Ptrprotoent __CALL_1 getprotobynumber(INTEGER number);
#define WinNet_getservbyname(name, proto)	getservbyname(name, proto)
__EXTERN WinNet_Ptrservent __CALL_1 getservbyname(SYSTEM_PTR name, SYSTEM_PTR proto);
#define WinNet_getservbyport(port, proto)	getservbyport(port, proto)
__EXTERN WinNet_Ptrservent __CALL_1 getservbyport(INTEGER port, SYSTEM_PTR proto);
#define WinNet_getsockname(s, name, name__typ, namelen)	getsockname(s, name, namelen)
__EXTERN INTEGER __CALL_1 getsockname(SYSTEM_PTR s, WinNet_sockaddr *name, INTEGER *namelen);
#define WinNet_getsockopt(s, level, optname, optval, optlen)	getsockopt(s, level, optname, optval, optlen)
__EXTERN INTEGER __CALL_1 getsockopt(SYSTEM_PTR s, INTEGER level, INTEGER optname, SYSTEM_PTR optval, INTEGER *optlen);
#define WinNet_htonl(hostlong)	htonl(hostlong)
__EXTERN INTEGER __CALL_1 htonl(INTEGER hostlong);
#define WinNet_htons(hostshort)	htons(hostshort)
__EXTERN SHORTINT __CALL_1 htons(SHORTINT hostshort);
#define WinNet_inet_addr(cp)	inet_addr(cp)
__EXTERN INTEGER __CALL_1 inet_addr(SYSTEM_PTR cp);
#define WinNet_inet_ntoa(in)	inet_ntoa(in)
__EXTERN SYSTEM_PTR __CALL_1 inet_ntoa(WinNet_in_addr in);
#define WinNet_ioctlsocket(s, cmd, argp)	ioctlsocket(s, cmd, argp)
__EXTERN INTEGER __CALL_1 ioctlsocket(SYSTEM_PTR s, INTEGER cmd, INTEGER *argp);
#define WinNet_listen(s, backlog)	listen(s, backlog)
__EXTERN INTEGER __CALL_1 listen(SYSTEM_PTR s, INTEGER backlog);
#define WinNet_ntohl(netlong)	ntohl(netlong)
__EXTERN INTEGER __CALL_1 ntohl(INTEGER netlong);
#define WinNet_ntohs(netshort)	ntohs(netshort)
__EXTERN SHORTINT __CALL_1 ntohs(SHORTINT netshort);
#define WinNet_recv(s, buf, len, flags)	recv(s, buf, len, flags)
__EXTERN INTEGER __CALL_1 recv(SYSTEM_PTR s, SYSTEM_PTR buf, INTEGER len, SET flags);
#define WinNet_recvfrom(s, buf, len, flags, from, from__typ, fromlen)	recvfrom(s, buf, len, flags, from, fromlen)
__EXTERN INTEGER __CALL_1 recvfrom(SYSTEM_PTR s, SYSTEM_PTR buf, INTEGER len, SET flags, WinNet_sockaddr *from, INTEGER *fromlen);
#define WinNet_select(nfds, readfds, readfds__typ, writefds, writefds__typ, exceptfds, exceptfds__typ, timeout, timeout__typ)	select(nfds, readfds, writefds, exceptfds, timeout)
__EXTERN INTEGER __CALL_1 select(INTEGER nfds, WinNet_fd_set *readfds, WinNet_fd_set *writefds, WinNet_fd_set *exceptfds, WinNet_timeval *timeout);
#define WinNet_send(s, buf, len, flags)	send(s, buf, len, flags)
__EXTERN INTEGER __CALL_1 send(SYSTEM_PTR s, SYSTEM_PTR buf, INTEGER len, SET flags);
#define WinNet_sendto(s, buf, len, flags, to, to__typ, tolen)	sendto(s, buf, len, flags, to, tolen)
__EXTERN INTEGER __CALL_1 sendto(SYSTEM_PTR s, SYSTEM_PTR buf, INTEGER len, SET flags, WinNet_sockaddr *to, INTEGER tolen);
#define WinNet_setsockopt(s, level, optname, optval, optlen)	setsockopt(s, level, optname, optval, optlen)
__EXTERN INTEGER __CALL_1 setsockopt(SYSTEM_PTR s, INTEGER level, INTEGER optname, SYSTEM_PTR optval, INTEGER optlen);
#define WinNet_shutdown(s, how)	shutdown(s, how)
__EXTERN INTEGER __CALL_1 shutdown(SYSTEM_PTR s, INTEGER how);
#define WinNet_socket(af, type, protocol)	socket(af, type, protocol)
__EXTERN SYSTEM_PTR __CALL_1 socket(INTEGER af, INTEGER type, INTEGER protocol);

#endif

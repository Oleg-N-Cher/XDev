/*  Ofront 1.2 -xtspkae */

#ifndef WinApi__h
#define WinApi__h

#include "SYSTEM.h"

struct WinApi__24 {
	CHAR BaseMid, Flags1, Flags2, BaseHi;
};

struct WinApi__25 {
	SET fBits0;
};

struct WinApi__26 {
	struct WinApi__24 Bytes;
	struct WinApi__25 Bits;
};

struct WinApi__27 {
	INTEGER FiberData, Version;
};

struct WinApi__19 {
	INTEGER PhysicalAddress, VirtualSize;
};

struct WinApi__20 {
	INTEGER Short, Long;
};

struct WinApi__21 {
	CHAR ShortName[8];
	struct WinApi__20 Name;
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *LongName[2];
};

struct WinApi__3 {
	SHORTINT Linenumber, Size;
};

struct WinApi__4 {
	struct WinApi__3 LnSz;
	INTEGER TotalSize;
};

struct WinApi__5 {
	INTEGER PointerToLinenumber, PointerToNextFunction;
};

struct WinApi__6 {
	SHORTINT Dimension[4];
};

struct WinApi__7 {
	struct WinApi__5 Function;
	struct WinApi__6 Array;
};

struct WinApi__8 {
	INTEGER TagIndex;
	struct WinApi__4 Misc;
	struct WinApi__7 FcnAry;
	SHORTINT TvIndex;
};

struct WinApi__9 {
	CHAR Name[18];
};

struct WinApi__10 {
	INTEGER Length;
	SHORTINT NumberOfRelocations, NumberOfLinenumbers;
	INTEGER CheckSum;
	SHORTINT Number;
	CHAR Selection;
};

struct WinApi__14 {
	INTEGER VirtualAddress, RelocCount;
};

struct WinApi__13 {
	INTEGER SymbolTableIndex, VirtualAddress;
};

typedef
	struct WinApi_IMAGE_IMPORT_BY_NAME *WinApi_PtrIMAGE_IMPORT_BY_NAME;

struct WinApi__11 {
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *ForwarderString;
	struct {
		LONGINT len[1];
		INTEGER data[1];
	} *Function;
	INTEGER Ordinal;
	WinApi_PtrIMAGE_IMPORT_BY_NAME AddressOfData;
};

typedef
	struct WinApi_IMAGE_THUNK_DATA *WinApi_PtrIMAGE_THUNK_DATA;

struct WinApi__12 {
	INTEGER Characteristics;
	WinApi_PtrIMAGE_THUNK_DATA OriginalFirstThunk;
};

struct WinApi__15 {
	SET fBits0;
};

struct WinApi__16 {
	struct WinApi__15 r;
	INTEGER Name;
	SHORTINT Id;
};

struct WinApi__17 {
	SET fBits0;
};

struct WinApi__18 {
	INTEGER OffsetToData;
	struct WinApi__17 r;
};

struct WinApi__43 {
	SHORTINT wProcessorArchitecture, wReserved;
};

struct WinApi__44 {
	INTEGER dwOemId;
	struct WinApi__43 r;
};

typedef
	struct WinApi_EXCEPTION_RECORD *WinApi_PtrEXCEPTION_RECORD;

typedef
	struct WinApi_EXCEPTION_RECORD {
		INTEGER ExceptionCode;
		SET ExceptionFlags;
		WinApi_PtrEXCEPTION_RECORD ExceptionRecord;
		INTEGER ExceptionAddress, NumberParameters;
		INTEGER ExceptionInformation[15];
	} WinApi_EXCEPTION_RECORD;

typedef
	struct WinApi_EXCEPTION_DEBUG_INFO {
		WinApi_EXCEPTION_RECORD ExceptionRecord;
		INTEGER dwFirstChance;
	} WinApi_EXCEPTION_DEBUG_INFO;

typedef
	INTEGER (*WinApi_THREAD_START_ROUTINE)(INTEGER);

typedef
	struct WinApi_CREATE_THREAD_DEBUG_INFO {
		INTEGER hThread, lpThreadLocalBase;
		WinApi_THREAD_START_ROUTINE lpStartAddress;
	} WinApi_CREATE_THREAD_DEBUG_INFO;

typedef
	struct WinApi_CREATE_PROCESS_DEBUG_INFO {
		INTEGER hFile, hProcess, hThread, lpBaseOfImage, dwDebugInfoFileOffset, nDebugInfoSize, lpThreadLocalBase;
		WinApi_THREAD_START_ROUTINE lpStartAddress;
		INTEGER lpImageName;
		SHORTINT fUnicode;
	} WinApi_CREATE_PROCESS_DEBUG_INFO;

typedef
	struct WinApi_EXIT_THREAD_DEBUG_INFO {
		INTEGER dwExitCode;
	} WinApi_EXIT_THREAD_DEBUG_INFO;

typedef
	struct WinApi_EXIT_PROCESS_DEBUG_INFO {
		INTEGER dwExitCode;
	} WinApi_EXIT_PROCESS_DEBUG_INFO;

typedef
	struct WinApi_LOAD_DLL_DEBUG_INFO {
		INTEGER hFile, lpBaseOfDll, dwDebugInfoFileOffset, nDebugInfoSize, lpImageName;
		SHORTINT fUnicode;
	} WinApi_LOAD_DLL_DEBUG_INFO;

typedef
	struct WinApi_UNLOAD_DLL_DEBUG_INFO {
		INTEGER lpBaseOfDll;
	} WinApi_UNLOAD_DLL_DEBUG_INFO;

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *WinApi_PtrSTR;

typedef
	struct WinApi_OUTPUT_DEBUG_STRING_INFO {
		WinApi_PtrSTR lpDebugStringData;
		SHORTINT fUnicode, nDebugStringLength;
	} WinApi_OUTPUT_DEBUG_STRING_INFO;

typedef
	struct WinApi_RIP_INFO {
		INTEGER dwError, dwType;
	} WinApi_RIP_INFO;

struct WinApi__2 {
	WinApi_EXCEPTION_DEBUG_INFO Exception;
	WinApi_CREATE_THREAD_DEBUG_INFO CreateThread;
	WinApi_CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
	WinApi_EXIT_THREAD_DEBUG_INFO ExitThread;
	WinApi_EXIT_PROCESS_DEBUG_INFO ExitProcess;
	WinApi_LOAD_DLL_DEBUG_INFO LoadDll;
	WinApi_UNLOAD_DLL_DEBUG_INFO UnloadDll;
	WinApi_OUTPUT_DEBUG_STRING_INFO DebugString;
	WinApi_RIP_INFO RipInfo;
};

struct WinApi__30 {
	INTEGER hMem;
	INTEGER dwReserved[3];
};

struct WinApi__31 {
	INTEGER dwCommittedSize, dwUnCommittedSize, lpFirstBlock, lpLastBlock;
};

struct WinApi__32 {
	struct WinApi__30 Block;
	struct WinApi__31 Region;
};

struct WinApi__22 {
	SHORTINT UnicodeChar;
	CHAR AsciiChar;
};

typedef
	struct WinApi_KEY_EVENT_RECORD {
		INTEGER bKeyDown;
		SHORTINT wRepeatCount, wVirtualKeyCode, wVirtualScanCode;
		struct WinApi__22 uChar;
		SET dwControlKeyState;
	} WinApi_KEY_EVENT_RECORD;

typedef
	struct WinApi_COORD {
		SHORTINT X, Y;
	} WinApi_COORD;

typedef
	struct WinApi_MOUSE_EVENT_RECORD {
		WinApi_COORD dwMousePosition;
		SET dwButtonState, dwControlKeyState, dwEventFlags;
	} WinApi_MOUSE_EVENT_RECORD;

typedef
	struct WinApi_WINDOW_BUFFER_SIZE_RECORD {
		WinApi_COORD dwSize;
	} WinApi_WINDOW_BUFFER_SIZE_RECORD;

typedef
	struct WinApi_MENU_EVENT_RECORD {
		INTEGER dwCommandId;
	} WinApi_MENU_EVENT_RECORD;

typedef
	struct WinApi_FOCUS_EVENT_RECORD {
		INTEGER bSetFocus;
	} WinApi_FOCUS_EVENT_RECORD;

struct WinApi__23 {
	WinApi_KEY_EVENT_RECORD KeyEvent;
	WinApi_MOUSE_EVENT_RECORD MouseEvent;
	WinApi_WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
	WinApi_MENU_EVENT_RECORD MenuEvent;
	WinApi_FOCUS_EVENT_RECORD FocusEvent;
};

struct WinApi__1 {
	SHORTINT UnicodeChar;
	CHAR AsciiChar;
};

typedef
	struct WinApi_DLGTEMPLATE *WinApi_PtrDLGTEMPLATE;

struct WinApi__35 {
	WinApi_PtrSTR pszTemplate;
	WinApi_PtrDLGTEMPLATE pResource;
};

struct WinApi__36 {
	INTEGER hIcon;
	WinApi_PtrSTR pszIcon;
};

typedef
	struct {
		LONGINT len[1];
		SHORTINT data[1];
	} *WinApi_PtrWSTR;

struct WinApi__40 {
	WinApi_PtrWSTR pszTemplate;
	WinApi_PtrDLGTEMPLATE pResource;
};

struct WinApi__41 {
	INTEGER hIcon;
	WinApi_PtrWSTR pszIcon;
};

struct WinApi__33 {
	INTEGER hIcon;
	WinApi_PtrSTR pszIcon;
};

struct WinApi__34 {
	INTEGER nStartPage;
	WinApi_PtrSTR pStartPage;
};

typedef
	struct WinApi_PROPSHEETPAGEA *WinApi_PtrPROPSHEETPAGEA;

typedef
	struct WinApi__PSP *WinApi_Ptr_PSP;

struct WinApi__37 {
	WinApi_PtrPROPSHEETPAGEA ppsp;
	struct {
		LONGINT len[1];
		WinApi_Ptr_PSP data[1];
	} *phpage;
};

struct WinApi__38 {
	INTEGER hIcon;
	WinApi_PtrWSTR pszIcon;
};

struct WinApi__39 {
	INTEGER nStartPage;
	WinApi_PtrWSTR pStartPage;
};

typedef
	struct WinApi_PROPSHEETPAGEW *WinApi_PtrPROPSHEETPAGEW;

struct WinApi__42 {
	WinApi_PtrPROPSHEETPAGEW ppsp;
	struct {
		LONGINT len[1];
		WinApi_Ptr_PSP data[1];
	} *phpage;
};

struct WinApi__28 {
	INTEGER cbBuf, pBuf;
};

struct WinApi__29 {
	INTEGER adwData[2];
	struct WinApi__28 Data;
};

typedef
	struct WinApi_ABC {
		INTEGER abcA, abcB, abcC;
	} WinApi_ABC;

typedef
	struct WinApi_ABCFLOAT {
		REAL abcfA, abcfB, abcfC;
	} WinApi_ABCFLOAT;

typedef
	INTEGER (*WinApi_ABORTPROC)(INTEGER, INTEGER);

typedef
	struct WinApi_ACCEL {
		CHAR fVirt;
		SHORTINT key, cmd;
	} WinApi_ACCEL;

typedef
	struct WinApi_ACCESSTIMEOUT {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER iTimeOutMSec;
	} WinApi_ACCESSTIMEOUT;

typedef
	struct WinApi_ACE_HEADER {
		CHAR AceType, AceFlags;
		SHORTINT AceSize;
	} WinApi_ACE_HEADER;

typedef
	struct WinApi_ACCESS_ALLOWED_ACE {
		WinApi_ACE_HEADER Header;
		SET Mask;
		INTEGER SidStart;
	} WinApi_ACCESS_ALLOWED_ACE;

typedef
	struct WinApi_ACCESS_DENIED_ACE {
		WinApi_ACE_HEADER Header;
		SET Mask;
		INTEGER SidStart;
	} WinApi_ACCESS_DENIED_ACE;

typedef
	struct WinApi_ACL {
		CHAR AclRevision, Sbz1;
		SHORTINT AclSize, AceCount, Sbz2;
	} WinApi_ACL;

typedef
	struct WinApi_ACL_REVISION_INFORMATION {
		INTEGER AclRevision;
	} WinApi_ACL_REVISION_INFORMATION;

typedef
	struct WinApi_ACL_SIZE_INFORMATION {
		INTEGER AceCount, AclBytesInUse, AclBytesFree;
	} WinApi_ACL_SIZE_INFORMATION;

typedef
	struct WinApi_ADDJOB_INFO_1A {
		WinApi_PtrSTR Path;
		INTEGER JobId;
	} WinApi_ADDJOB_INFO_1A;

typedef
	struct WinApi_ADDJOB_INFO_1W {
		WinApi_PtrWSTR Path;
		INTEGER JobId;
	} WinApi_ADDJOB_INFO_1W;

typedef
	struct WinApi_ANIMATIONINFO {
		INTEGER cbSize, iMinAnimate;
	} WinApi_ANIMATIONINFO;

typedef
	void (*WinApi_APCFUNC)(INTEGER);

typedef
	struct WinApi_RECT {
		INTEGER left, top, right, bottom;
	} WinApi_RECT;

typedef
	struct WinApi_APPBARDATA {
		INTEGER cbSize, hWnd, uCallbackMessage, uEdge;
		WinApi_RECT rc;
		INTEGER lParam;
	} WinApi_APPBARDATA;

typedef
	struct WinApi_BITMAP {
		INTEGER bmType, bmWidth, bmHeight, bmWidthBytes;
		SHORTINT bmPlanes, bmBitsPixel;
		INTEGER bmBits;
	} WinApi_BITMAP;

typedef
	struct WinApi_BITMAPCOREHEADER {
		INTEGER bcSize;
		SHORTINT bcWidth, bcHeight, bcPlanes, bcBitCount;
	} WinApi_BITMAPCOREHEADER;

typedef
	struct WinApi_RGBTRIPLE {
		CHAR rgbtBlue, rgbtGreen, rgbtRed;
	} WinApi_RGBTRIPLE;

typedef
	struct WinApi_BITMAPCOREINFO {
		WinApi_BITMAPCOREHEADER bmciHeader;
		WinApi_RGBTRIPLE bmciColors[1];
	} WinApi_BITMAPCOREINFO;

typedef
	struct WinApi_BITMAPFILEHEADER {
		SHORTINT bfType;
		INTEGER bfSize;
		SHORTINT bfReserved1, bfReserved2;
		INTEGER bfOffBits;
	} WinApi_BITMAPFILEHEADER;

typedef
	struct WinApi_BITMAPINFOHEADER {
		INTEGER biSize, biWidth, biHeight;
		SHORTINT biPlanes, biBitCount;
		INTEGER biCompression, biSizeImage, biXPelsPerMeter, biYPelsPerMeter, biClrUsed, biClrImportant;
	} WinApi_BITMAPINFOHEADER;

typedef
	struct WinApi_RGBQUAD {
		CHAR rgbBlue, rgbGreen, rgbRed, rgbReserved;
	} WinApi_RGBQUAD;

typedef
	struct WinApi_BITMAPINFO {
		WinApi_BITMAPINFOHEADER bmiHeader;
		WinApi_RGBQUAD bmiColors[1];
	} WinApi_BITMAPINFO;

typedef
	struct WinApi_CIEXYZ {
		INTEGER ciexyzX, ciexyzY, ciexyzZ;
	} WinApi_CIEXYZ;

typedef
	struct WinApi_CIEXYZTRIPLE {
		WinApi_CIEXYZ ciexyzRed, ciexyzGreen, ciexyzBlue;
	} WinApi_CIEXYZTRIPLE;

typedef
	struct WinApi_BITMAPV4HEADER {
		INTEGER bV4Size, bV4Width, bV4Height;
		SHORTINT bV4Planes, bV4BitCount;
		INTEGER bV4V4Compression, bV4SizeImage, bV4XPelsPerMeter, bV4YPelsPerMeter, bV4ClrUsed, bV4ClrImportant, bV4RedMask, bV4GreenMask, bV4BlueMask, bV4AlphaMask, bV4CSType;
		WinApi_CIEXYZTRIPLE bV4Endpoints;
		INTEGER bV4GammaRed, bV4GammaGreen, bV4GammaBlue;
	} WinApi_BITMAPV4HEADER;

typedef
	struct WinApi_BROADCASTSYSMSG {
		INTEGER uiMessage, wParam, lParam;
	} WinApi_BROADCASTSYSMSG;

typedef
	struct WinApi_FILETIME {
		INTEGER dwLowDateTime, dwHighDateTime;
	} WinApi_FILETIME;

typedef
	struct WinApi_BY_HANDLE_FILE_INFORMATION {
		SET dwFileAttributes;
		WinApi_FILETIME ftCreationTime, ftLastAccessTime, ftLastWriteTime;
		INTEGER dwVolumeSerialNumber, nFileSizeHigh, nFileSizeLow, nNumberOfLinks, nFileIndexHigh, nFileIndexLow;
	} WinApi_BY_HANDLE_FILE_INFORMATION;

typedef
	INTEGER (*WinApi_CALINFO_ENUMPROCA)(void);

typedef
	INTEGER (*WinApi_CALINFO_ENUMPROCW)(void);

typedef
	struct WinApi_CBTACTIVATESTRUCT {
		INTEGER fMouse, hWndActive;
	} WinApi_CBTACTIVATESTRUCT;

typedef
	struct WinApi_CREATESTRUCTA *WinApi_PtrCREATESTRUCTA;

typedef
	struct WinApi_CBT_CREATEWNDA {
		WinApi_PtrCREATESTRUCTA lpcs;
		INTEGER hwndInsertAfter;
	} WinApi_CBT_CREATEWNDA;

typedef
	struct WinApi_CREATESTRUCTW *WinApi_PtrCREATESTRUCTW;

typedef
	struct WinApi_CBT_CREATEWNDW {
		WinApi_PtrCREATESTRUCTW lpcs;
		INTEGER hwndInsertAfter;
	} WinApi_CBT_CREATEWNDW;

typedef
	struct WinApi_FONTSIGNATURE {
		INTEGER fsUsb[4];
		INTEGER fsCsb[2];
	} WinApi_FONTSIGNATURE;

typedef
	struct WinApi_CHARSETINFO {
		INTEGER ciCharset, ciACP;
		WinApi_FONTSIGNATURE fs;
	} WinApi_CHARSETINFO;

typedef
	struct WinApi_CHAR_INFO {
		struct WinApi__1 Char;
		SHORTINT Attributes;
	} WinApi_CHAR_INFO;

typedef
	struct WinApi_CLIENTCREATESTRUCT {
		INTEGER hWindowMenu, idFirstChild;
	} WinApi_CLIENTCREATESTRUCT;

typedef
	INTEGER (*WinApi_CODEPAGE_ENUMPROCA)(void);

typedef
	INTEGER (*WinApi_CODEPAGE_ENUMPROCW)(void);

typedef
	struct WinApi_COLORADJUSTMENT {
		SHORTINT caSize, caFlags, caIlluminantIndex, caRedGamma, caGreenGamma, caBlueGamma, caReferenceBlack, caReferenceWhite, caContrast, caBrightness, caColorfulness, caRedGreenTint;
	} WinApi_COLORADJUSTMENT;

typedef
	struct WinApi_DCB {
		INTEGER DCBlength, BaudRate;
		SET fBits0;
		SHORTINT wReserved, XonLim, XoffLim;
		CHAR ByteSize, Parity, StopBits, XonChar, XoffChar, ErrorChar, EofChar, EvtChar;
		SHORTINT wReserved1;
	} WinApi_DCB;

typedef
	struct WinApi_COMMCONFIG {
		INTEGER dwSize;
		SHORTINT wVersion, wReserved;
		WinApi_DCB dcb;
		INTEGER dwProviderSubType, dwProviderOffset, dwProviderSize;
		SHORTINT wcProviderData[1];
	} WinApi_COMMCONFIG;

typedef
	struct WinApi_COMMPROP {
		SHORTINT wPacketLength, wPacketVersion;
		INTEGER dwServiceMask, dwReserved1, dwMaxTxQueue, dwMaxRxQueue;
		SET dwMaxBaud;
		INTEGER dwProvSubType;
		SET dwProvCapabilities, dwSettableParams, dwSettableBaud;
		SHORTINT wSettableData, wSettableStopParity;
		INTEGER dwCurrentTxQueue, dwCurrentRxQueue, dwProvSpec1, dwProvSpec2;
		SHORTINT wcProvChar[1];
	} WinApi_COMMPROP;

typedef
	struct WinApi_COMMTIMEOUTS {
		INTEGER ReadIntervalTimeout, ReadTotalTimeoutMultiplier, ReadTotalTimeoutConstant, WriteTotalTimeoutMultiplier, WriteTotalTimeoutConstant;
	} WinApi_COMMTIMEOUTS;

typedef
	struct WinApi_COMPAREITEMSTRUCT {
		SET CtlType;
		INTEGER CtlID, hwndItem, itemID1, itemData1, itemID2, itemData2, dwLocaleId;
	} WinApi_COMPAREITEMSTRUCT;

typedef
	struct WinApi_COMPOUND_ACCESS_ALLOWED_ACE {
		WinApi_ACE_HEADER Header;
		SET Mask;
		SHORTINT CompoundAceType, Reserved;
		INTEGER SidStart;
	} WinApi_COMPOUND_ACCESS_ALLOWED_ACE;

typedef
	struct WinApi_COMSTAT {
		SET fBits0;
		INTEGER cbInQue, cbOutQue;
	} WinApi_COMSTAT;

typedef
	struct WinApi_COM_GUID {
		INTEGER Data1;
		SHORTINT Data2, Data3;
		SYSTEM_BYTE Data4[8];
	} WinApi_COM_GUID;

typedef
	struct WinApi_CONSOLE_CURSOR_INFO {
		INTEGER dwSize, bVisible;
	} WinApi_CONSOLE_CURSOR_INFO;

typedef
	struct WinApi_SMALL_RECT {
		SHORTINT Left, Top, Right, Bottom;
	} WinApi_SMALL_RECT;

typedef
	struct WinApi_CONSOLE_SCREEN_BUFFER_INFO {
		WinApi_COORD dwSize, dwCursorPosition;
		SHORTINT wAttributes;
		WinApi_SMALL_RECT srWindow;
		WinApi_COORD dwMaximumWindowSize;
	} WinApi_CONSOLE_SCREEN_BUFFER_INFO;

typedef
	struct WinApi_FLOATING_SAVE_AREA {
		INTEGER ControlWord, StatusWord, TagWord, ErrorOffset, ErrorSelector, DataOffset, DataSelector;
		CHAR RegisterArea[80];
		INTEGER Cr0NpxState;
	} WinApi_FLOATING_SAVE_AREA;

typedef
	struct WinApi_CONTEXT {
		SET ContextFlags;
		INTEGER Dr0, Dr1, Dr2, Dr3, Dr6, Dr7;
		WinApi_FLOATING_SAVE_AREA FloatSave;
		INTEGER SegGs, SegFs, SegEs, SegDs, Edi, Esi, Ebx, Edx, Ecx, Eax, Ebp, Eip, SegCs, EFlags, Esp, SegSs;
	} WinApi_CONTEXT;

typedef
	struct WinApi_SECURITY_QUALITY_OF_SERVICE {
		INTEGER Length, ImpersonationLevel;
		BOOLEAN ContextTrackingMode, EffectiveOnly;
	} WinApi_SECURITY_QUALITY_OF_SERVICE;

typedef
	struct WinApi_CONVCONTEXT {
		INTEGER cb, wFlags, wCountryID, iCodePage, dwLangID, dwSecurity;
		WinApi_SECURITY_QUALITY_OF_SERVICE qos;
	} WinApi_CONVCONTEXT;

typedef
	struct WinApi_CONVINFO {
		INTEGER cb, hUser, hConvPartner, hszSvcPartner, hszServiceReq, hszTopic, hszItem, wFmt, wType;
		SET wStatus;
		INTEGER wConvst, wLastError, hConvList;
		WinApi_CONVCONTEXT ConvCtxt;
		INTEGER hwnd, hwndPartner;
	} WinApi_CONVINFO;

typedef
	struct WinApi_COPYDATASTRUCT {
		INTEGER dwData, cbData, lpData;
	} WinApi_COPYDATASTRUCT;

typedef
	struct WinApi_CPINFO {
		INTEGER MaxCharSize;
		CHAR DefaultChar[2];
		CHAR LeadByte[12];
	} WinApi_CPINFO;

typedef
	struct WinApi_CREATESTRUCTA {
		INTEGER lpCreateParams, hInstance, hMenu, hwndParent, cy, cx, y, x;
		SET style;
		WinApi_PtrSTR lpszName, lpszClass;
		SET dwExStyle;
	} WinApi_CREATESTRUCTA;

typedef
	struct WinApi_CREATESTRUCTW {
		INTEGER lpCreateParams, hInstance, hMenu, hwndParent, cy, cx, y, x;
		SET style;
		WinApi_PtrWSTR lpszName, lpszClass;
		SET dwExStyle;
	} WinApi_CREATESTRUCTW;

typedef
	struct WinApi_RTL_CRITICAL_SECTION_DEBUG *WinApi_PtrRTL_CRITICAL_SECTION_DEBUG;

typedef
	struct WinApi_RTL_CRITICAL_SECTION {
		WinApi_PtrRTL_CRITICAL_SECTION_DEBUG DebugInfo;
		INTEGER LockCount, RecursionCount, OwningThread, LockSemaphore, Reserved;
	} WinApi_RTL_CRITICAL_SECTION;

typedef
	WinApi_RTL_CRITICAL_SECTION *WinApi_PtrRTL_CRITICAL_SECTION;

typedef
	struct WinApi_LIST_ENTRY *WinApi_PtrLIST_ENTRY;

typedef
	struct WinApi_LIST_ENTRY {
		WinApi_PtrLIST_ENTRY Flink, Blink;
	} WinApi_LIST_ENTRY;

typedef
	struct WinApi_RTL_CRITICAL_SECTION_DEBUG {
		SHORTINT Type, CreatorBackTraceIndex;
		WinApi_PtrRTL_CRITICAL_SECTION CriticalSection;
		WinApi_LIST_ENTRY ProcessLocksList;
		INTEGER EntryCount, ContentionCount;
		INTEGER Spare[2];
	} WinApi_RTL_CRITICAL_SECTION_DEBUG;

typedef
	struct WinApi_CURRENCYFMTA {
		INTEGER NumDigits, LeadingZero, Grouping;
		WinApi_PtrSTR lpDecimalSep, lpThousandSep;
		INTEGER NegativeOrder, PositiveOrder;
		WinApi_PtrSTR lpCurrencySymbol;
	} WinApi_CURRENCYFMTA;

typedef
	struct WinApi_CURRENCYFMTW {
		INTEGER NumDigits, LeadingZero, Grouping;
		WinApi_PtrWSTR lpDecimalSep, lpThousandSep;
		INTEGER NegativeOrder, PositiveOrder;
		WinApi_PtrWSTR lpCurrencySymbol;
	} WinApi_CURRENCYFMTW;

typedef
	struct WinApi_CURSORSHAPE {
		INTEGER xHotSpot, yHotSpot, cx, cy, cbWidth;
		CHAR Planes, BitsPixel;
	} WinApi_CURSORSHAPE;

typedef
	struct WinApi_CWPRETSTRUCT {
		INTEGER lResult, lParam, wParam, message, hwnd;
	} WinApi_CWPRETSTRUCT;

typedef
	struct WinApi_CWPSTRUCT {
		INTEGER lParam, wParam, message, hwnd;
	} WinApi_CWPSTRUCT;

typedef
	struct WinApi_DATATYPES_INFO_1A {
		WinApi_PtrSTR pName;
	} WinApi_DATATYPES_INFO_1A;

typedef
	struct WinApi_DATATYPES_INFO_1W {
		WinApi_PtrWSTR pName;
	} WinApi_DATATYPES_INFO_1W;

typedef
	INTEGER (*WinApi_DATEFMT_ENUMPROCA)(void);

typedef
	INTEGER (*WinApi_DATEFMT_ENUMPROCW)(void);

typedef
	struct WinApi_DDEACK {
		SHORTINT fBits0;
	} WinApi_DDEACK;

typedef
	struct WinApi_DDEADVISE {
		SHORTINT fBits0, cfFormat;
	} WinApi_DDEADVISE;

typedef
	struct WinApi_DDEDATA {
		SHORTINT fBits0, cfFormat;
		CHAR Value[1];
	} WinApi_DDEDATA;

typedef
	struct WinApi_DDELN {
		SHORTINT fBits0, cfFormat;
	} WinApi_DDELN;

typedef
	struct WinApi_DDEML_MSG_HOOK_DATA {
		INTEGER uiLo, uiHi, cbData;
		INTEGER Data[8];
	} WinApi_DDEML_MSG_HOOK_DATA;

typedef
	struct WinApi_DDEPOKE {
		SHORTINT fBits0, cfFormat;
		CHAR Value[1];
	} WinApi_DDEPOKE;

typedef
	struct WinApi_DDEUP {
		SHORTINT fBits0, cfFormat;
		CHAR rgb[1];
	} WinApi_DDEUP;

typedef
	struct WinApi_DEBUGHOOKINFO {
		INTEGER idThread, idThreadInstaller, lParam, wParam, code;
	} WinApi_DEBUGHOOKINFO;

typedef
	struct WinApi_DEBUG_EVENT {
		INTEGER dwDebugEventCode, dwProcessId, dwThreadId;
		struct WinApi__2 u;
	} WinApi_DEBUG_EVENT;

typedef
	struct WinApi_DELETEITEMSTRUCT {
		SET CtlType;
		INTEGER CtlID, itemID, hwndItem, itemData;
	} WinApi_DELETEITEMSTRUCT;

typedef
	INTEGER (*WinApi_DESKTOPENUMPROC)(void);

typedef
	INTEGER (*WinApi_DESKTOPENUMPROCA)(void);

typedef
	INTEGER (*WinApi_DESKTOPENUMPROCW)(void);

typedef
	struct WinApi_DEVMODEA {
		CHAR dmDeviceName[32];
		SHORTINT dmSpecVersion, dmDriverVersion, dmSize, dmDriverExtra;
		SET dmFields;
		SHORTINT dmOrientation, dmPaperSize, dmPaperLength, dmPaperWidth, dmScale, dmCopies, dmDefaultSource, dmPrintQuality, dmColor, dmDuplex, dmYResolution, dmTTOption, dmCollate;
		CHAR dmFormName[32];
		SHORTINT dmLogPixels;
		INTEGER dmBitsPerPel, dmPelsWidth, dmPelsHeight;
		SET dmDisplayFlags;
		INTEGER dmDisplayFrequency, dmICMMethod, dmICMIntent, dmMediaType, dmDitherType, dmICCManufacturer, dmICCModel, dmPanningWidth, dmPanningHeight;
	} WinApi_DEVMODEA;

typedef
	struct WinApi_DEVMODEW {
		SHORTINT dmDeviceName[32];
		SHORTINT dmSpecVersion, dmDriverVersion, dmSize, dmDriverExtra;
		SET dmFields;
		SHORTINT dmOrientation, dmPaperSize, dmPaperLength, dmPaperWidth, dmScale, dmCopies, dmDefaultSource, dmPrintQuality, dmColor, dmDuplex, dmYResolution, dmTTOption, dmCollate;
		SHORTINT dmFormName[32];
		SHORTINT dmLogPixels;
		INTEGER dmBitsPerPel, dmPelsWidth, dmPelsHeight;
		SET dmDisplayFlags;
		INTEGER dmDisplayFrequency, dmICMMethod, dmICMIntent, dmMediaType, dmDitherType, dmICCManufacturer, dmICCModel, dmPanningWidth, dmPanningHeight;
	} WinApi_DEVMODEW;

typedef
	struct WinApi_DIBSECTION {
		WinApi_BITMAP dsBm;
		WinApi_BITMAPINFOHEADER dsBmih;
		INTEGER dsBitfields[3];
		INTEGER dshSection, dsOffset;
	} WinApi_DIBSECTION;

typedef
	struct WinApi_DLGITEMTEMPLATE {
		SET style, dwExtendedStyle;
		SHORTINT x, y, cx, cy, id;
	} WinApi_DLGITEMTEMPLATE;

typedef
	INTEGER (*WinApi_DLGPROC)(void);

typedef
	struct WinApi_DLGTEMPLATE {
		SET style, dwExtendedStyle;
		SHORTINT cdit, x, y, cx, cy;
	} WinApi_DLGTEMPLATE;

typedef
	struct WinApi_DOCINFOA {
		INTEGER cbSize;
		WinApi_PtrSTR lpszDocName, lpszOutput, lpszDatatype;
		INTEGER fwType;
	} WinApi_DOCINFOA;

typedef
	struct WinApi_DOCINFOW {
		INTEGER cbSize;
		WinApi_PtrWSTR lpszDocName, lpszOutput, lpszDatatype;
		INTEGER fwType;
	} WinApi_DOCINFOW;

typedef
	struct WinApi_DOC_INFO_1A {
		WinApi_PtrSTR pDocName, pOutputFile, pDatatype;
	} WinApi_DOC_INFO_1A;

typedef
	struct WinApi_DOC_INFO_1W {
		WinApi_PtrWSTR pDocName, pOutputFile, pDatatype;
	} WinApi_DOC_INFO_1W;

typedef
	struct WinApi_DOC_INFO_2A {
		WinApi_PtrSTR pDocName, pOutputFile, pDatatype;
		SET dwMode;
		INTEGER JobId;
	} WinApi_DOC_INFO_2A;

typedef
	struct WinApi_DOC_INFO_2W {
		WinApi_PtrWSTR pDocName, pOutputFile, pDatatype;
		SET dwMode;
		INTEGER JobId;
	} WinApi_DOC_INFO_2W;

typedef
	struct WinApi_POINT {
		INTEGER x, y;
	} WinApi_POINT;

typedef
	struct WinApi_DRAGINFOA {
		INTEGER uSize;
		WinApi_POINT pt;
		INTEGER fNC;
		WinApi_PtrSTR lpFileList;
		SET grfKeyState;
	} WinApi_DRAGINFOA;

typedef
	struct WinApi_DRAGINFOW {
		INTEGER uSize;
		WinApi_POINT pt;
		INTEGER fNC;
		WinApi_PtrWSTR lpFileList;
		SET grfKeyState;
	} WinApi_DRAGINFOW;

typedef
	struct WinApi_DRAWITEMSTRUCT {
		SET CtlType;
		INTEGER CtlID, itemID;
		SET itemAction, itemState;
		INTEGER hwndItem, hDC;
		WinApi_RECT rcItem;
		INTEGER itemData;
	} WinApi_DRAWITEMSTRUCT;

typedef
	INTEGER (*WinApi_DRAWSTATEPROC)(void);

typedef
	struct WinApi_DRAWTEXTPARAMS {
		INTEGER cbSize, iTabLength, iLeftMargin, iRightMargin, uiLengthDrawn;
	} WinApi_DRAWTEXTPARAMS;

typedef
	struct WinApi_DRIVER_INFO_1A {
		WinApi_PtrSTR pName;
	} WinApi_DRIVER_INFO_1A;

typedef
	struct WinApi_DRIVER_INFO_1W {
		WinApi_PtrWSTR pName;
	} WinApi_DRIVER_INFO_1W;

typedef
	struct WinApi_DRIVER_INFO_2A {
		INTEGER cVersion;
		WinApi_PtrSTR pName, pEnvironment, pDriverPath, pDataFile, pConfigFile;
	} WinApi_DRIVER_INFO_2A;

typedef
	struct WinApi_DRIVER_INFO_2W {
		INTEGER cVersion;
		WinApi_PtrWSTR pName, pEnvironment, pDriverPath, pDataFile, pConfigFile;
	} WinApi_DRIVER_INFO_2W;

typedef
	struct WinApi_DRIVER_INFO_3A {
		INTEGER cVersion;
		WinApi_PtrSTR pName, pEnvironment, pDriverPath, pDataFile, pConfigFile, pHelpFile, pDependentFiles, pMonitorName, pDefaultDataType;
	} WinApi_DRIVER_INFO_3A;

typedef
	struct WinApi_DRIVER_INFO_3W {
		INTEGER cVersion;
		WinApi_PtrWSTR pName, pEnvironment, pDriverPath, pDataFile, pConfigFile, pHelpFile, pDependentFiles, pMonitorName, pDefaultDataType;
	} WinApi_DRIVER_INFO_3W;

typedef
	struct WinApi_DROPSTRUCT {
		INTEGER hwndSource, hwndSink, wFmt, dwData;
		WinApi_POINT ptDrop;
		INTEGER dwControlData;
	} WinApi_DROPSTRUCT;

typedef
	INTEGER (*WinApi_EDITWORDBREAKPROC)(void);

typedef
	INTEGER (*WinApi_EDITWORDBREAKPROCA)(void);

typedef
	INTEGER (*WinApi_EDITWORDBREAKPROCW)(void);

typedef
	struct WinApi_EMR {
		INTEGER iType, nSize;
	} WinApi_EMR;

typedef
	struct WinApi_EMRABORTPATH {
		WinApi_EMR emr;
	} WinApi_EMRABORTPATH;

typedef
	struct WinApi_EMRANGLEARC {
		WinApi_EMR emr;
		WinApi_POINT ptlCenter;
		INTEGER nRadius;
		REAL eStartAngle, eSweepAngle;
	} WinApi_EMRANGLEARC;

typedef
	struct WinApi_EMRARC {
		WinApi_EMR emr;
		WinApi_RECT rclBox;
		WinApi_POINT ptlStart, ptlEnd;
	} WinApi_EMRARC;

typedef
	struct WinApi_XFORM {
		REAL eM11, eM12, eM21, eM22, eDx, eDy;
	} WinApi_XFORM;

typedef
	struct WinApi_EMRBITBLT {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER xDest, yDest, cxDest, cyDest, dwRop, xSrc, ySrc;
		WinApi_XFORM xformSrc;
		INTEGER crBkColorSrc, iUsageSrc, offBmiSrc, cbBmiSrc, offBitsSrc, cbBitsSrc;
	} WinApi_EMRBITBLT;

typedef
	struct WinApi_LOGBRUSH {
		INTEGER lbStyle, lbColor, lbHatch;
	} WinApi_LOGBRUSH;

typedef
	struct WinApi_EMRCREATEBRUSHINDIRECT {
		WinApi_EMR emr;
		INTEGER ihBrush;
		WinApi_LOGBRUSH lb;
	} WinApi_EMRCREATEBRUSHINDIRECT;

typedef
	struct WinApi_LOGCOLORSPACEW {
		INTEGER lcsSignature, lcsVersion, lcsSize, lcsCSType, lcsIntent;
		WinApi_CIEXYZTRIPLE lcsEndpoints;
		INTEGER lcsGammaRed, lcsGammaGreen, lcsGammaBlue;
		SHORTINT lcsFilename[260];
	} WinApi_LOGCOLORSPACEW;

typedef
	struct WinApi_EMRCREATECOLORSPACE {
		WinApi_EMR emr;
		INTEGER ihCS;
		WinApi_LOGCOLORSPACEW lcs;
	} WinApi_EMRCREATECOLORSPACE;

typedef
	struct WinApi_EMRCREATEDIBPATTERNBRUSHPT {
		WinApi_EMR emr;
		INTEGER ihBrush, iUsage, offBmi, cbBmi, offBits, cbBits;
	} WinApi_EMRCREATEDIBPATTERNBRUSHPT;

typedef
	struct WinApi_EMRCREATEMONOBRUSH {
		WinApi_EMR emr;
		INTEGER ihBrush, iUsage, offBmi, cbBmi, offBits, cbBits;
	} WinApi_EMRCREATEMONOBRUSH;

typedef
	struct WinApi_PALETTEENTRY {
		CHAR peRed, peGreen, peBlue, peFlags;
	} WinApi_PALETTEENTRY;

typedef
	struct WinApi_LOGPALETTE {
		SHORTINT palVersion, palNumEntries;
		WinApi_PALETTEENTRY palPalEntry[1];
	} WinApi_LOGPALETTE;

typedef
	struct WinApi_EMRCREATEPALETTE {
		WinApi_EMR emr;
		INTEGER ihPal;
		WinApi_LOGPALETTE lgpl;
	} WinApi_EMRCREATEPALETTE;

typedef
	struct WinApi_LOGPEN {
		INTEGER lopnStyle;
		WinApi_POINT lopnWidth;
		INTEGER lopnColor;
	} WinApi_LOGPEN;

typedef
	struct WinApi_EMRCREATEPEN {
		WinApi_EMR emr;
		INTEGER ihPen;
		WinApi_LOGPEN lopn;
	} WinApi_EMRCREATEPEN;

typedef
	struct WinApi_EMRSELECTCOLORSPACE {
		WinApi_EMR emr;
		INTEGER ihCS;
	} WinApi_EMRSELECTCOLORSPACE;

typedef
	struct WinApi_EMRSELECTOBJECT {
		WinApi_EMR emr;
		INTEGER ihObject;
	} WinApi_EMRSELECTOBJECT;

typedef
	struct WinApi_EMRELLIPSE {
		WinApi_EMR emr;
		WinApi_RECT rclBox;
	} WinApi_EMRELLIPSE;

typedef
	struct WinApi_EMREOF {
		WinApi_EMR emr;
		INTEGER nPalEntries, offPalEntries, nSizeLast;
	} WinApi_EMREOF;

typedef
	struct WinApi_EMREXCLUDECLIPRECT {
		WinApi_EMR emr;
		WinApi_RECT rclClip;
	} WinApi_EMREXCLUDECLIPRECT;

typedef
	struct WinApi_LOGFONTW {
		INTEGER lfHeight, lfWidth, lfEscapement, lfOrientation, lfWeight;
		CHAR lfItalic, lfUnderline, lfStrikeOut, lfCharSet, lfOutPrecision, lfClipPrecision, lfQuality, lfPitchAndFamily;
		SHORTINT lfFaceName[32];
	} WinApi_LOGFONTW;

typedef
	struct WinApi_PANOSE {
		CHAR bFamilyType, bSerifStyle, bWeight, bProportion, bContrast, bStrokeVariation, bArmStyle, bLetterform, bMidline, bXHeight;
	} WinApi_PANOSE;

typedef
	struct WinApi_EXTLOGFONTW {
		WinApi_LOGFONTW elfLogFont;
		SHORTINT elfFullName[64];
		SHORTINT elfStyle[32];
		INTEGER elfVersion, elfStyleSize, elfMatch, elfReserved;
		CHAR elfVendorId[4];
		INTEGER elfCulture;
		WinApi_PANOSE elfPanose;
	} WinApi_EXTLOGFONTW;

typedef
	struct WinApi_EMREXTCREATEFONTINDIRECTW {
		WinApi_EMR emr;
		INTEGER ihFont;
		WinApi_EXTLOGFONTW elfw;
	} WinApi_EMREXTCREATEFONTINDIRECTW;

typedef
	struct WinApi_EXTLOGPEN {
		INTEGER elpPenStyle, elpWidth, elpBrushStyle, elpColor, elpHatch, elpNumEntries;
		INTEGER elpStyleEntry[1];
	} WinApi_EXTLOGPEN;

typedef
	struct WinApi_EMREXTCREATEPEN {
		WinApi_EMR emr;
		INTEGER ihPen, offBmi, cbBmi, offBits, cbBits;
		WinApi_EXTLOGPEN elp;
	} WinApi_EMREXTCREATEPEN;

typedef
	struct WinApi_EMREXTFLOODFILL {
		WinApi_EMR emr;
		WinApi_POINT ptlStart;
		INTEGER crColor, iMode;
	} WinApi_EMREXTFLOODFILL;

typedef
	struct WinApi_EMREXTSELECTCLIPRGN {
		WinApi_EMR emr;
		INTEGER cbRgnData, iMode;
		CHAR RgnData[1];
	} WinApi_EMREXTSELECTCLIPRGN;

typedef
	struct WinApi_EMRTEXT {
		WinApi_POINT ptlReference;
		INTEGER nChars, offString, fOptions;
		WinApi_RECT rcl;
		INTEGER offDx;
	} WinApi_EMRTEXT;

typedef
	struct WinApi_EMREXTTEXTOUTA {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER iGraphicsMode;
		REAL exScale, eyScale;
		WinApi_EMRTEXT emrtext;
	} WinApi_EMREXTTEXTOUTA;

typedef
	struct WinApi_EMRFILLPATH {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
	} WinApi_EMRFILLPATH;

typedef
	struct WinApi_EMRFILLRGN {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER cbRgnData, ihBrush;
		CHAR RgnData[1];
	} WinApi_EMRFILLRGN;

typedef
	struct WinApi_EMRFORMAT {
		INTEGER dSignature, nVersion, cbData, offData;
	} WinApi_EMRFORMAT;

typedef
	struct WinApi_SIZE {
		INTEGER cx, cy;
	} WinApi_SIZE;

typedef
	struct WinApi_EMRFRAMERGN {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER cbRgnData, ihBrush;
		WinApi_SIZE szlStroke;
		CHAR RgnData[1];
	} WinApi_EMRFRAMERGN;

typedef
	struct WinApi_EMRGDICOMMENT {
		WinApi_EMR emr;
		INTEGER cbData;
		CHAR Data[1];
	} WinApi_EMRGDICOMMENT;

typedef
	struct WinApi_EMRGLSBOUNDEDRECORD {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER cbData;
		CHAR Data[1];
	} WinApi_EMRGLSBOUNDEDRECORD;

typedef
	struct WinApi_EMRGLSRECORD {
		WinApi_EMR emr;
		INTEGER cbData;
		CHAR Data[1];
	} WinApi_EMRGLSRECORD;

typedef
	struct WinApi_EMRINVERTRGN {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER cbRgnData;
		CHAR RgnData[1];
	} WinApi_EMRINVERTRGN;

typedef
	struct WinApi_EMRLINETO {
		WinApi_EMR emr;
		WinApi_POINT ptl;
	} WinApi_EMRLINETO;

typedef
	struct WinApi_EMRMASKBLT {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER xDest, yDest, cxDest, cyDest, dwRop, xSrc, ySrc;
		WinApi_XFORM xformSrc;
		INTEGER crBkColorSrc, iUsageSrc, offBmiSrc, cbBmiSrc, offBitsSrc, cbBitsSrc, xMask, yMask, iUsageMask, offBmiMask, cbBmiMask, offBitsMask, cbBitsMask;
	} WinApi_EMRMASKBLT;

typedef
	struct WinApi_EMRMODIFYWORLDTRANSFORM {
		WinApi_EMR emr;
		WinApi_XFORM xform;
		INTEGER iMode;
	} WinApi_EMRMODIFYWORLDTRANSFORM;

typedef
	struct WinApi_EMROFFSETCLIPRGN {
		WinApi_EMR emr;
		WinApi_POINT ptlOffset;
	} WinApi_EMROFFSETCLIPRGN;

typedef
	struct WinApi_PIXELFORMATDESCRIPTOR {
		SHORTINT nSize, nVersion;
		SET dwFlags;
		CHAR iPixelType, cColorBits, cRedBits, cRedShift, cGreenBits, cGreenShift, cBlueBits, cBlueShift, cAlphaBits, cAlphaShift, cAccumBits, cAccumRedBits, cAccumGreenBits, cAccumBlueBits, cAccumAlphaBits, cDepthBits, cStencilBits, cAuxBuffers, iLayerType, bReserved;
		SET dwLayerMask, dwVisibleMask, dwDamageMask;
	} WinApi_PIXELFORMATDESCRIPTOR;

typedef
	struct WinApi_EMRPIXELFORMAT {
		WinApi_EMR emr;
		WinApi_PIXELFORMATDESCRIPTOR pfd;
	} WinApi_EMRPIXELFORMAT;

typedef
	struct WinApi_EMRPLGBLT {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		WinApi_POINT aptlDest[3];
		INTEGER xSrc, ySrc, cxSrc, cySrc;
		WinApi_XFORM xformSrc;
		INTEGER crBkColorSrc, iUsageSrc, offBmiSrc, cbBmiSrc, offBitsSrc, cbBitsSrc, xMask, yMask, iUsageMask, offBmiMask, cbBmiMask, offBitsMask, cbBitsMask;
	} WinApi_EMRPLGBLT;

typedef
	struct WinApi_EMRPOLYLINE {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER cptl;
		WinApi_POINT aptl[1];
	} WinApi_EMRPOLYLINE;

typedef
	struct WinApi_POINTS {
		SHORTINT x, y;
	} WinApi_POINTS;

typedef
	struct WinApi_EMRPOLYLINE16 {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER cpts;
		WinApi_POINTS apts[1];
	} WinApi_EMRPOLYLINE16;

typedef
	struct WinApi_EMRPOLYDRAW {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER cptl;
		WinApi_POINT aptl[1];
		CHAR abTypes[1];
	} WinApi_EMRPOLYDRAW;

typedef
	struct WinApi_EMRPOLYDRAW16 {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER cpts;
		WinApi_POINTS apts[1];
		CHAR abTypes[1];
	} WinApi_EMRPOLYDRAW16;

typedef
	struct WinApi_EMRPOLYPOLYLINE {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER nPolys, cptl;
		INTEGER aPolyCounts[1];
		WinApi_POINT aptl[1];
	} WinApi_EMRPOLYPOLYLINE;

typedef
	struct WinApi_EMRPOLYPOLYLINE16 {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER nPolys, cpts;
		INTEGER aPolyCounts[1];
		WinApi_POINTS apts[1];
	} WinApi_EMRPOLYPOLYLINE16;

typedef
	struct WinApi_EMRPOLYTEXTOUTA {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER iGraphicsMode;
		REAL exScale, eyScale;
		INTEGER cStrings;
		WinApi_EMRTEXT aemrtext[1];
	} WinApi_EMRPOLYTEXTOUTA;

typedef
	struct WinApi_EMRRESIZEPALETTE {
		WinApi_EMR emr;
		INTEGER ihPal, cEntries;
	} WinApi_EMRRESIZEPALETTE;

typedef
	struct WinApi_EMRRESTOREDC {
		WinApi_EMR emr;
		INTEGER iRelative;
	} WinApi_EMRRESTOREDC;

typedef
	struct WinApi_EMRROUNDRECT {
		WinApi_EMR emr;
		WinApi_RECT rclBox;
		WinApi_SIZE szlCorner;
	} WinApi_EMRROUNDRECT;

typedef
	struct WinApi_EMRSCALEVIEWPORTEXTEX {
		WinApi_EMR emr;
		INTEGER xNum, xDenom, yNum, yDenom;
	} WinApi_EMRSCALEVIEWPORTEXTEX;

typedef
	struct WinApi_EMRSELECTCLIPPATH {
		WinApi_EMR emr;
		INTEGER iMode;
	} WinApi_EMRSELECTCLIPPATH;

typedef
	struct WinApi_EMRSELECTPALETTE {
		WinApi_EMR emr;
		INTEGER ihPal;
	} WinApi_EMRSELECTPALETTE;

typedef
	struct WinApi_EMRSETARCDIRECTION {
		WinApi_EMR emr;
		INTEGER iArcDirection;
	} WinApi_EMRSETARCDIRECTION;

typedef
	struct WinApi_EMRSETBKCOLOR {
		WinApi_EMR emr;
		INTEGER crColor;
	} WinApi_EMRSETBKCOLOR;

typedef
	struct WinApi_EMRSETVIEWPORTORGEX {
		WinApi_EMR emr;
		WinApi_POINT ptlOrigin;
	} WinApi_EMRSETVIEWPORTORGEX;

typedef
	struct WinApi_EMRSETCOLORADJUSTMENT {
		WinApi_EMR emr;
		WinApi_COLORADJUSTMENT ColorAdjustment;
	} WinApi_EMRSETCOLORADJUSTMENT;

typedef
	struct WinApi_EMRSETDIBITSTODEVICE {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER xDest, yDest, xSrc, ySrc, cxSrc, cySrc, offBmiSrc, cbBmiSrc, offBitsSrc, cbBitsSrc, iUsageSrc, iStartScan, cScans;
	} WinApi_EMRSETDIBITSTODEVICE;

typedef
	struct WinApi_EMRSETMAPPERFLAGS {
		WinApi_EMR emr;
		SET dwFlags;
	} WinApi_EMRSETMAPPERFLAGS;

typedef
	struct WinApi_EMRSETMITERLIMIT {
		WinApi_EMR emr;
		REAL eMiterLimit;
	} WinApi_EMRSETMITERLIMIT;

typedef
	struct WinApi_EMRSETPALETTEENTRIES {
		WinApi_EMR emr;
		INTEGER ihPal, iStart, cEntries;
		WinApi_PALETTEENTRY aPalEntries[1];
	} WinApi_EMRSETPALETTEENTRIES;

typedef
	struct WinApi_EMRSETPIXELV {
		WinApi_EMR emr;
		WinApi_POINT ptlPixel;
		INTEGER crColor;
	} WinApi_EMRSETPIXELV;

typedef
	struct WinApi_EMRSETVIEWPORTEXTEX {
		WinApi_EMR emr;
		WinApi_SIZE szlExtent;
	} WinApi_EMRSETVIEWPORTEXTEX;

typedef
	struct WinApi_EMRSETWORLDTRANSFORM {
		WinApi_EMR emr;
		WinApi_XFORM xform;
	} WinApi_EMRSETWORLDTRANSFORM;

typedef
	struct WinApi_EMRSTRETCHBLT {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER xDest, yDest, cxDest, cyDest, dwRop, xSrc, ySrc;
		WinApi_XFORM xformSrc;
		INTEGER crBkColorSrc, iUsageSrc, offBmiSrc, cbBmiSrc, offBitsSrc, cbBitsSrc, cxSrc, cySrc;
	} WinApi_EMRSTRETCHBLT;

typedef
	struct WinApi_EMRSTRETCHDIBITS {
		WinApi_EMR emr;
		WinApi_RECT rclBounds;
		INTEGER xDest, yDest, xSrc, ySrc, cxSrc, cySrc, offBmiSrc, cbBmiSrc, offBitsSrc, cbBitsSrc, iUsageSrc, dwRop, cxDest, cyDest;
	} WinApi_EMRSTRETCHDIBITS;

typedef
	struct WinApi_ENHMETAHEADER {
		INTEGER iType, nSize;
		WinApi_RECT rclBounds, rclFrame;
		INTEGER dSignature, nVersion, nBytes, nRecords;
		SHORTINT nHandles, sReserved;
		INTEGER nDescription, offDescription, nPalEntries;
		WinApi_SIZE szlDevice, szlMillimeters;
		INTEGER cbPixelFormat, offPixelFormat, bOpenGL;
	} WinApi_ENHMETAHEADER;

typedef
	struct WinApi_ENHMETARECORD {
		INTEGER iType, nSize;
		INTEGER dParm[1];
	} WinApi_ENHMETARECORD;

typedef
	struct WinApi_HANDLETABLE {
		INTEGER objectHandle[1];
	} WinApi_HANDLETABLE;

typedef
	INTEGER (*WinApi_ENHMFENUMPROC)(INTEGER, WinApi_HANDLETABLE*, LONGINT *, WinApi_ENHMETARECORD*, LONGINT *, INTEGER, INTEGER);

typedef
	struct WinApi_LOGFONTA {
		INTEGER lfHeight, lfWidth, lfEscapement, lfOrientation, lfWeight;
		CHAR lfItalic, lfUnderline, lfStrikeOut, lfCharSet, lfOutPrecision, lfClipPrecision, lfQuality, lfPitchAndFamily;
		CHAR lfFaceName[32];
	} WinApi_LOGFONTA;

typedef
	struct WinApi_ENUMLOGFONTA {
		WinApi_LOGFONTA elfLogFont;
		CHAR elfFullName[64];
		CHAR elfStyle[32];
	} WinApi_ENUMLOGFONTA;

typedef
	struct WinApi_ENUMLOGFONTEXA {
		WinApi_LOGFONTA elfLogFont;
		CHAR elfFullName[64];
		CHAR elfStyle[32];
		CHAR elfScript[32];
	} WinApi_ENUMLOGFONTEXA;

typedef
	struct WinApi_ENUMLOGFONTEXW {
		WinApi_LOGFONTW elfLogFont;
		SHORTINT elfFullName[64];
		SHORTINT elfStyle[32];
		SHORTINT elfScript[32];
	} WinApi_ENUMLOGFONTEXW;

typedef
	struct WinApi_ENUMLOGFONTW {
		WinApi_LOGFONTW elfLogFont;
		SHORTINT elfFullName[64];
		SHORTINT elfStyle[32];
	} WinApi_ENUMLOGFONTW;

typedef
	INTEGER (*WinApi_ENUMRESLANGPROC)(void);

typedef
	INTEGER (*WinApi_ENUMRESNAMEPROC)(void);

typedef
	INTEGER (*WinApi_ENUMRESTYPEPROC)(void);

typedef
	struct WinApi_SERVICE_STATUS {
		SET dwServiceType;
		INTEGER dwCurrentState, dwControlsAccepted, dwWin32ExitCode, dwServiceSpecificExitCode, dwCheckPoint, dwWaitHint;
	} WinApi_SERVICE_STATUS;

typedef
	struct WinApi_ENUM_SERVICE_STATUSA {
		WinApi_PtrSTR lpServiceName, lpDisplayName;
		WinApi_SERVICE_STATUS ServiceStatus;
	} WinApi_ENUM_SERVICE_STATUSA;

typedef
	struct WinApi_ENUM_SERVICE_STATUSW {
		WinApi_PtrWSTR lpServiceName, lpDisplayName;
		WinApi_SERVICE_STATUS ServiceStatus;
	} WinApi_ENUM_SERVICE_STATUSW;

typedef
	struct WinApi_EVENTLOGRECORD {
		INTEGER Length, Reserved, RecordNumber, TimeGenerated, TimeWritten, EventID;
		SHORTINT EventType, NumStrings, EventCategory, ReservedFlags;
		INTEGER ClosingRecordNumber, StringOffset, UserSidLength, UserSidOffset, DataLength, DataOffset;
	} WinApi_EVENTLOGRECORD;

typedef
	struct WinApi_EVENTMSG {
		INTEGER message, paramL, paramH, time, hwnd;
	} WinApi_EVENTMSG;

typedef
	WinApi_CONTEXT *WinApi_PtrCONTEXT;

typedef
	struct WinApi_EXCEPTION_POINTERS {
		WinApi_PtrEXCEPTION_RECORD ExceptionRecord;
		WinApi_PtrCONTEXT ContextRecord;
	} WinApi_EXCEPTION_POINTERS;

typedef
	struct WinApi_EXTLOGFONTA {
		WinApi_LOGFONTA elfLogFont;
		CHAR elfFullName[64];
		CHAR elfStyle[32];
		INTEGER elfVersion, elfStyleSize, elfMatch, elfReserved;
		CHAR elfVendorId[4];
		INTEGER elfCulture;
		WinApi_PANOSE elfPanose;
	} WinApi_EXTLOGFONTA;

typedef
	INTEGER (*WinApi_FARPROC)(void);

typedef
	void (*WinApi_FIBER_START_ROUTINE)(INTEGER);

typedef
	struct WinApi_FILE_NOTIFY_INFORMATION {
		INTEGER NextEntryOffset, Action, FileNameLength;
		SHORTINT FileName[1];
	} WinApi_FILE_NOTIFY_INFORMATION;

typedef
	struct WinApi_FILTERKEYS {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER iWaitMSec, iDelayMSec, iRepeatMSec, iBounceMSec;
	} WinApi_FILTERKEYS;

typedef
	struct WinApi_FIXED {
		SHORTINT fract, value;
	} WinApi_FIXED;

typedef
	INTEGER (*WinApi_FNADDPROPSHEETPAGE)(WinApi_Ptr_PSP, INTEGER);

typedef
	INTEGER (*WinApi_FNADDPROPSHEETPAGES)(INTEGER, WinApi_FNADDPROPSHEETPAGE, INTEGER);

typedef
	INTEGER (*WinApi_FNCALLBACK)(INTEGER, INTEGER, INTEGER, INTEGER, INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (*WinApi_FNDEVCAPS)(WinApi_PtrSTR, WinApi_PtrSTR, INTEGER, WinApi_PtrSTR, WinApi_DEVMODEA*, LONGINT *);

typedef
	INTEGER (*WinApi_FNDEVMODE)(INTEGER, INTEGER, WinApi_DEVMODEA*, LONGINT *, WinApi_PtrSTR, WinApi_PtrSTR, WinApi_DEVMODEA*, LONGINT *, WinApi_PtrSTR, INTEGER);

typedef
	INTEGER (*WinApi_FNPROPSHEETCALLBACK)(INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (*WinApi_FNPSPCALLBACKA)(INTEGER, INTEGER, WinApi_PtrPROPSHEETPAGEA);

typedef
	INTEGER (*WinApi_FNPSPCALLBACKW)(INTEGER, INTEGER, WinApi_PtrPROPSHEETPAGEW);

typedef
	struct WinApi_TEXTMETRICA {
		INTEGER tmHeight, tmAscent, tmDescent, tmInternalLeading, tmExternalLeading, tmAveCharWidth, tmMaxCharWidth, tmWeight, tmOverhang, tmDigitizedAspectX, tmDigitizedAspectY;
		CHAR tmFirstChar, tmLastChar, tmDefaultChar, tmBreakChar, tmItalic, tmUnderlined, tmStruckOut, tmPitchAndFamily, tmCharSet;
	} WinApi_TEXTMETRICA;

typedef
	INTEGER (*WinApi_FONTENUMPROC)(WinApi_LOGFONTA*, LONGINT *, WinApi_TEXTMETRICA*, LONGINT *, INTEGER, INTEGER);

typedef
	INTEGER (*WinApi_FONTENUMPROCA)(WinApi_LOGFONTA*, LONGINT *, WinApi_TEXTMETRICA*, LONGINT *, INTEGER, INTEGER);

typedef
	struct WinApi_NEWTEXTMETRICA {
		INTEGER tmHeight, tmAscent, tmDescent, tmInternalLeading, tmExternalLeading, tmAveCharWidth, tmMaxCharWidth, tmWeight, tmOverhang, tmDigitizedAspectX, tmDigitizedAspectY;
		CHAR tmFirstChar, tmLastChar, tmDefaultChar, tmBreakChar, tmItalic, tmUnderlined, tmStruckOut, tmPitchAndFamily, tmCharSet;
		INTEGER ntmFlags, ntmSizeEM, ntmCellHeight, ntmAvgWidth;
	} WinApi_NEWTEXTMETRICA;

typedef
	struct WinApi_NEWTEXTMETRICEXA {
		WinApi_NEWTEXTMETRICA ntmTm;
		WinApi_FONTSIGNATURE ntmFontSig;
	} WinApi_NEWTEXTMETRICEXA;

typedef
	INTEGER (*WinApi_FONTENUMPROCEX)(WinApi_ENUMLOGFONTEXA*, LONGINT *, WinApi_NEWTEXTMETRICEXA*, LONGINT *, INTEGER, INTEGER);

typedef
	INTEGER (*WinApi_FONTENUMPROCEXA)(WinApi_ENUMLOGFONTEXA*, LONGINT *, WinApi_NEWTEXTMETRICEXA*, LONGINT *, INTEGER, INTEGER);

typedef
	struct WinApi_NEWTEXTMETRICW {
		INTEGER tmHeight, tmAscent, tmDescent, tmInternalLeading, tmExternalLeading, tmAveCharWidth, tmMaxCharWidth, tmWeight, tmOverhang, tmDigitizedAspectX, tmDigitizedAspectY;
		SHORTINT tmFirstChar, tmLastChar, tmDefaultChar, tmBreakChar;
		CHAR tmItalic, tmUnderlined, tmStruckOut, tmPitchAndFamily, tmCharSet;
		INTEGER ntmFlags, ntmSizeEM, ntmCellHeight, ntmAvgWidth;
	} WinApi_NEWTEXTMETRICW;

typedef
	struct WinApi_NEWTEXTMETRICEXW {
		WinApi_NEWTEXTMETRICW ntmTm;
		WinApi_FONTSIGNATURE ntmFontSig;
	} WinApi_NEWTEXTMETRICEXW;

typedef
	INTEGER (*WinApi_FONTENUMPROCEXW)(WinApi_ENUMLOGFONTEXW*, LONGINT *, WinApi_NEWTEXTMETRICEXW*, LONGINT *, INTEGER, INTEGER);

typedef
	struct WinApi_TEXTMETRICW {
		INTEGER tmHeight, tmAscent, tmDescent, tmInternalLeading, tmExternalLeading, tmAveCharWidth, tmMaxCharWidth, tmWeight, tmOverhang, tmDigitizedAspectX, tmDigitizedAspectY;
		SHORTINT tmFirstChar, tmLastChar, tmDefaultChar, tmBreakChar;
		CHAR tmItalic, tmUnderlined, tmStruckOut, tmPitchAndFamily, tmCharSet;
	} WinApi_TEXTMETRICW;

typedef
	INTEGER (*WinApi_FONTENUMPROCW)(WinApi_LOGFONTW*, LONGINT *, WinApi_TEXTMETRICW*, LONGINT *, INTEGER, INTEGER);

typedef
	struct WinApi_FORM_INFO_1A {
		SET Flags;
		WinApi_PtrSTR pName;
		WinApi_SIZE Size;
		WinApi_RECT ImageableArea;
	} WinApi_FORM_INFO_1A;

typedef
	struct WinApi_FORM_INFO_1W {
		SET Flags;
		WinApi_PtrWSTR pName;
		WinApi_SIZE Size;
		WinApi_RECT ImageableArea;
	} WinApi_FORM_INFO_1W;

typedef
	struct WinApi_FPO_DATA {
		INTEGER ulOffStart, cbProcSize, cdwLocals;
		SHORTINT cdwParams, fBits0;
	} WinApi_FPO_DATA;

typedef
	struct WinApi_GCP_RESULTSA {
		INTEGER lStructSize;
		WinApi_PtrSTR lpOutString;
		struct {
			LONGINT len[1];
			INTEGER data[1];
		} *lpOrder;
		struct {
			LONGINT len[1];
			INTEGER data[1];
		} *lpDx;
		struct {
			LONGINT len[1];
			INTEGER data[1];
		} *lpCaretPos;
		WinApi_PtrSTR lpClass;
		WinApi_PtrWSTR lpGlyphs;
		INTEGER nGlyphs, nMaxFit;
	} WinApi_GCP_RESULTSA;

typedef
	struct WinApi_GCP_RESULTSW {
		INTEGER lStructSize;
		WinApi_PtrWSTR lpOutString;
		struct {
			LONGINT len[1];
			INTEGER data[1];
		} *lpOrder;
		struct {
			LONGINT len[1];
			INTEGER data[1];
		} *lpDx;
		struct {
			LONGINT len[1];
			INTEGER data[1];
		} *lpCaretPos;
		WinApi_PtrSTR lpClass;
		WinApi_PtrWSTR lpGlyphs;
		INTEGER nGlyphs, nMaxFit;
	} WinApi_GCP_RESULTSW;

typedef
	struct WinApi_GENERIC_MAPPING {
		SET GenericRead, GenericWrite, GenericExecute, GenericAll;
	} WinApi_GENERIC_MAPPING;

typedef
	struct WinApi_GLYPHMETRICS {
		INTEGER gmBlackBoxX, gmBlackBoxY;
		WinApi_POINT gmptGlyphOrigin;
		SHORTINT gmCellIncX, gmCellIncY;
	} WinApi_GLYPHMETRICS;

typedef
	struct WinApi_POINTFLOAT {
		REAL x, y;
	} WinApi_POINTFLOAT;

typedef
	struct WinApi_GLYPHMETRICSFLOAT {
		REAL gmfBlackBoxX, gmfBlackBoxY;
		WinApi_POINTFLOAT gmfptGlyphOrigin;
		REAL gmfCellIncX, gmfCellIncY;
	} WinApi_GLYPHMETRICSFLOAT;

typedef
	INTEGER (*WinApi_GOBJENUMPROC)(void);

typedef
	INTEGER (*WinApi_GRAYSTRINGPROC)(void);

typedef
	void (*WinApi_HANDLER_FUNCTION)(INTEGER);

typedef
	INTEGER (*WinApi_HANDLER_ROUTINE)(INTEGER);

typedef
	struct WinApi_HARDWAREHOOKSTRUCT {
		INTEGER hwnd, message, wParam, lParam;
	} WinApi_HARDWAREHOOKSTRUCT;

typedef
	struct WinApi_HELPINFO {
		INTEGER cbSize, iContextType, iCtrlId, hItemHandle, dwContextId;
		WinApi_POINT MousePos;
	} WinApi_HELPINFO;

typedef
	struct WinApi_HELPWININFOA {
		INTEGER wStructSize, x, y, dx, dy, wMax;
		CHAR rgchMember[2];
	} WinApi_HELPWININFOA;

typedef
	struct WinApi_HELPWININFOW {
		INTEGER wStructSize, x, y, dx, dy, wMax;
		SHORTINT rgchMember[2];
	} WinApi_HELPWININFOW;

typedef
	struct WinApi_HIGHCONTRASTA {
		INTEGER cbSize;
		SET dwFlags;
		WinApi_PtrSTR lpszDefaultScheme;
	} WinApi_HIGHCONTRASTA;

typedef
	struct WinApi_HIGHCONTRASTW {
		INTEGER cbSize;
		SET dwFlags;
		WinApi_PtrWSTR lpszDefaultScheme;
	} WinApi_HIGHCONTRASTW;

typedef
	INTEGER (*WinApi_HOOKPROC)(void);

typedef
	struct WinApi_HSZPAIR {
		INTEGER hszSvc, hszTopic;
	} WinApi_HSZPAIR;

typedef
	struct WinApi_HW_PROFILE_INFOA {
		INTEGER dwDockInfo;
		CHAR szHwProfileGuid[39];
		CHAR szHwProfileName[80];
	} WinApi_HW_PROFILE_INFOA;

typedef
	struct WinApi_HW_PROFILE_INFOW {
		INTEGER dwDockInfo;
		SHORTINT szHwProfileGuid[39];
		SHORTINT szHwProfileName[80];
	} WinApi_HW_PROFILE_INFOW;

typedef
	INTEGER (*WinApi_ICMENUMPROCA)(WinApi_PtrSTR, INTEGER);

typedef
	INTEGER (*WinApi_ICMENUMPROCW)(WinApi_PtrWSTR, INTEGER);

typedef
	struct WinApi_ICONINFO {
		INTEGER fIcon, xHotspot, yHotspot, hbmMask, hbmColor;
	} WinApi_ICONINFO;

typedef
	struct WinApi_ICONMETRICSA {
		INTEGER cbSize, iHorzSpacing, iVertSpacing, iTitleWrap;
		WinApi_LOGFONTA lfFont;
	} WinApi_ICONMETRICSA;

typedef
	struct WinApi_ICONMETRICSW {
		INTEGER cbSize, iHorzSpacing, iVertSpacing, iTitleWrap;
		WinApi_LOGFONTW lfFont;
	} WinApi_ICONMETRICSW;

typedef
	struct WinApi_IMAGE_ARCHIVE_MEMBER_HEADER {
		CHAR Name[16];
		CHAR Date[12];
		CHAR UserID[6];
		CHAR GroupID[6];
		CHAR Mode[8];
		CHAR Size[10];
		CHAR EndHeader[2];
	} WinApi_IMAGE_ARCHIVE_MEMBER_HEADER;

typedef
	struct WinApi_IMAGE_AUX_SYMBOL {
		struct WinApi__8 Sym;
		struct WinApi__9 File;
		struct WinApi__10 Section;
	} WinApi_IMAGE_AUX_SYMBOL;

typedef
	struct WinApi_IMAGE_BASE_RELOCATION {
		INTEGER VirtualAddress, SizeOfBlock;
	} WinApi_IMAGE_BASE_RELOCATION;

typedef
	struct WinApi_IMAGE_BOUND_FORWARDER_REF {
		INTEGER TimeDateStamp;
		SHORTINT OffsetModuleName, Reserved;
	} WinApi_IMAGE_BOUND_FORWARDER_REF;

typedef
	struct WinApi_IMAGE_BOUND_IMPORT_DESCRIPTOR {
		INTEGER TimeDateStamp;
		SHORTINT OffsetModuleName, NumberOfModuleForwarderRefs;
	} WinApi_IMAGE_BOUND_IMPORT_DESCRIPTOR;

typedef
	struct WinApi_IMAGE_COFF_SYMBOLS_HEADER {
		INTEGER NumberOfSymbols, LvaToFirstSymbol, NumberOfLinenumbers, LvaToFirstLinenumber, RvaToFirstByteOfCode, RvaToLastByteOfCode, RvaToFirstByteOfData, RvaToLastByteOfData;
	} WinApi_IMAGE_COFF_SYMBOLS_HEADER;

typedef
	struct WinApi_IMAGE_DATA_DIRECTORY {
		INTEGER VirtualAddress, Size;
	} WinApi_IMAGE_DATA_DIRECTORY;

typedef
	struct WinApi_IMAGE_DEBUG_DIRECTORY {
		INTEGER Characteristics, TimeDateStamp;
		SHORTINT MajorVersion, MinorVersion;
		INTEGER Type, SizeOfData, AddressOfRawData, PointerToRawData;
	} WinApi_IMAGE_DEBUG_DIRECTORY;

typedef
	struct WinApi_IMAGE_DEBUG_MISC {
		INTEGER DataType, Length;
		BOOLEAN Unicode;
		CHAR Reserved[3];
		CHAR Data[1];
	} WinApi_IMAGE_DEBUG_MISC;

typedef
	struct WinApi_IMAGE_DOS_HEADER {
		SHORTINT e_magic, e_cblp, e_cp, e_crlc, e_cparhdr, e_minalloc, e_maxalloc, e_ss, e_sp, e_csum, e_ip, e_cs, e_lfarlc, e_ovno;
		SHORTINT e_res[4];
		SHORTINT e_oemid, e_oeminfo;
		SHORTINT e_res2[10];
		INTEGER e_lfanew;
	} WinApi_IMAGE_DOS_HEADER;

typedef
	struct WinApi_IMAGE_EXPORT_DIRECTORY {
		INTEGER Characteristics, TimeDateStamp;
		SHORTINT MajorVersion, MinorVersion;
		INTEGER Name, Base, NumberOfFunctions, NumberOfNames;
		struct {
			LONGINT len[1];
			struct {
				LONGINT len[1];
				INTEGER data[1];
			} *data[1];
		} *AddressOfFunctions;
		struct {
			LONGINT len[1];
			struct {
				LONGINT len[1];
				INTEGER data[1];
			} *data[1];
		} *AddressOfNames;
		struct {
			LONGINT len[1];
			struct {
				LONGINT len[1];
				SHORTINT data[1];
			} *data[1];
		} *AddressOfNameOrdinals;
	} WinApi_IMAGE_EXPORT_DIRECTORY;

typedef
	struct WinApi_IMAGE_FILE_HEADER {
		SHORTINT Machine, NumberOfSections;
		INTEGER TimeDateStamp, PointerToSymbolTable, NumberOfSymbols;
		SHORTINT SizeOfOptionalHeader, Characteristics;
	} WinApi_IMAGE_FILE_HEADER;

typedef
	struct WinApi_IMAGE_FUNCTION_ENTRY {
		INTEGER StartingAddress, EndingAddress, EndOfPrologue;
	} WinApi_IMAGE_FUNCTION_ENTRY;

typedef
	struct WinApi_IMAGE_IMPORT_BY_NAME {
		SHORTINT Hint;
		CHAR Name[1];
	} WinApi_IMAGE_IMPORT_BY_NAME;

typedef
	struct WinApi_IMAGE_IMPORT_DESCRIPTOR {
		struct WinApi__12 u;
		INTEGER TimeDateStamp, ForwarderChain, Name;
		WinApi_PtrIMAGE_THUNK_DATA FirstThunk;
	} WinApi_IMAGE_IMPORT_DESCRIPTOR;

typedef
	struct WinApi_IMAGE_LINENUMBER {
		struct WinApi__13 Type;
		SHORTINT Linenumber;
	} WinApi_IMAGE_LINENUMBER;

typedef
	struct WinApi_IMAGE_LOAD_CONFIG_DIRECTORY {
		INTEGER Characteristics, TimeDateStamp;
		SHORTINT MajorVersion, MinorVersion;
		INTEGER GlobalFlagsClear, GlobalFlagsSet, CriticalSectionDefaultTimeout, DeCommitFreeBlockThreshold, DeCommitTotalFreeThreshold, LockPrefixTable, MaximumAllocationSize, VirtualMemoryThreshold, ProcessHeapFlags;
		INTEGER Reserved[4];
	} WinApi_IMAGE_LOAD_CONFIG_DIRECTORY;

typedef
	struct WinApi_IMAGE_OPTIONAL_HEADER {
		SHORTINT Magic;
		CHAR MajorLinkerVersion, MinorLinkerVersion;
		INTEGER SizeOfCode, SizeOfInitializedData, SizeOfUninitializedData, AddressOfEntryPoint, BaseOfCode, BaseOfData, ImageBase, SectionAlignment, FileAlignment;
		SHORTINT MajorOperatingSystemVersion, MinorOperatingSystemVersion, MajorImageVersion, MinorImageVersion, MajorSubsystemVersion, MinorSubsystemVersion;
		INTEGER Reserved1, SizeOfImage, SizeOfHeaders, CheckSum;
		SHORTINT Subsystem, DllCharacteristics;
		INTEGER SizeOfStackReserve, SizeOfStackCommit, SizeOfHeapReserve, SizeOfHeapCommit, LoaderFlags, NumberOfRvaAndSizes;
		WinApi_IMAGE_DATA_DIRECTORY DataDirectory[16];
	} WinApi_IMAGE_OPTIONAL_HEADER;

typedef
	struct WinApi_IMAGE_NT_HEADERS {
		INTEGER Signature;
		WinApi_IMAGE_FILE_HEADER FileHeader;
		WinApi_IMAGE_OPTIONAL_HEADER OptionalHeader;
	} WinApi_IMAGE_NT_HEADERS;

typedef
	struct WinApi_IMAGE_OS2_HEADER {
		SHORTINT ne_magic;
		CHAR ne_ver, ne_rev;
		SHORTINT ne_enttab, ne_cbenttab;
		INTEGER ne_crc;
		SHORTINT ne_flags, ne_autodata, ne_heap, ne_stack;
		INTEGER ne_csip, ne_sssp;
		SHORTINT ne_cseg, ne_cmod, ne_cbnrestab, ne_segtab, ne_rsrctab, ne_restab, ne_modtab, ne_imptab;
		INTEGER ne_nrestab;
		SHORTINT ne_cmovent, ne_align, ne_cres;
		CHAR ne_exetyp, ne_flagsothers;
		SHORTINT ne_pretthunks, ne_psegrefbytes, ne_swaparea, ne_expver;
	} WinApi_IMAGE_OS2_HEADER;

typedef
	struct WinApi_IMAGE_RELOCATION {
		struct WinApi__14 u;
		INTEGER SymbolTableIndex;
		SHORTINT Type;
	} WinApi_IMAGE_RELOCATION;

typedef
	struct WinApi_IMAGE_RESOURCE_DATA_ENTRY {
		INTEGER OffsetToData, Size, CodePage, Reserved;
	} WinApi_IMAGE_RESOURCE_DATA_ENTRY;

typedef
	struct WinApi_IMAGE_RESOURCE_DIRECTORY {
		INTEGER Characteristics, TimeDateStamp;
		SHORTINT MajorVersion, MinorVersion, NumberOfNamedEntries, NumberOfIdEntries;
	} WinApi_IMAGE_RESOURCE_DIRECTORY;

typedef
	struct WinApi_IMAGE_RESOURCE_DIRECTORY_ENTRY {
		struct WinApi__16 u;
		struct WinApi__18 u1;
	} WinApi_IMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef
	struct WinApi_IMAGE_RESOURCE_DIRECTORY_STRING {
		SHORTINT Length;
		CHAR NameString[1];
	} WinApi_IMAGE_RESOURCE_DIRECTORY_STRING;

typedef
	struct WinApi_IMAGE_RESOURCE_DIR_STRING_U {
		SHORTINT Length;
		SHORTINT NameString[1];
	} WinApi_IMAGE_RESOURCE_DIR_STRING_U;

typedef
	struct WinApi_IMAGE_ROM_OPTIONAL_HEADER {
		SHORTINT Magic;
		CHAR MajorLinkerVersion, MinorLinkerVersion;
		INTEGER SizeOfCode, SizeOfInitializedData, SizeOfUninitializedData, AddressOfEntryPoint, BaseOfCode, BaseOfData, BaseOfBss, GprMask;
		INTEGER CprMask[4];
		INTEGER GpValue;
	} WinApi_IMAGE_ROM_OPTIONAL_HEADER;

typedef
	struct WinApi_IMAGE_ROM_HEADERS {
		WinApi_IMAGE_FILE_HEADER FileHeader;
		WinApi_IMAGE_ROM_OPTIONAL_HEADER OptionalHeader;
	} WinApi_IMAGE_ROM_HEADERS;

typedef
	struct WinApi_IMAGE_RUNTIME_FUNCTION_ENTRY {
		INTEGER BeginAddress, EndAddress, ExceptionHandler, HandlerData, PrologEndAddress;
	} WinApi_IMAGE_RUNTIME_FUNCTION_ENTRY;

typedef
	struct WinApi_IMAGE_SECTION_HEADER {
		CHAR Name[8];
		struct WinApi__19 Misc;
		INTEGER VirtualAddress, SizeOfRawData, PointerToRawData, PointerToRelocations, PointerToLinenumbers;
		SHORTINT NumberOfRelocations, NumberOfLinenumbers;
		INTEGER Characteristics;
	} WinApi_IMAGE_SECTION_HEADER;

typedef
	struct WinApi_IMAGE_SEPARATE_DEBUG_HEADER {
		SHORTINT Signature, Flags, Machine, Characteristics;
		INTEGER TimeDateStamp, CheckSum, ImageBase, SizeOfImage, NumberOfSections, ExportedNamesSize, DebugDirectorySize;
		INTEGER Reserved[3];
	} WinApi_IMAGE_SEPARATE_DEBUG_HEADER;

typedef
	struct WinApi_IMAGE_SYMBOL {
		struct WinApi__21 N;
		INTEGER Value;
		SHORTINT SectionNumber, Type;
		CHAR StorageClass, NumberOfAuxSymbols;
	} WinApi_IMAGE_SYMBOL;

typedef
	struct WinApi_IMAGE_THUNK_DATA {
		struct WinApi__11 u1;
	} WinApi_IMAGE_THUNK_DATA;

typedef
	void (*WinApi_IMAGE_TLS_CALLBACK)(INTEGER, INTEGER, INTEGER);

typedef
	struct WinApi_IMAGE_TLS_DIRECTORY {
		INTEGER StartAddressOfRawData, EndAddressOfRawData;
		struct {
			LONGINT len[1];
			INTEGER data[1];
		} *AddressOfIndex;
		struct {
			LONGINT len[1];
			WinApi_IMAGE_TLS_CALLBACK data[1];
		} *AddressOfCallBacks;
		INTEGER SizeOfZeroFill, Characteristics;
	} WinApi_IMAGE_TLS_DIRECTORY;

typedef
	struct WinApi_IMAGE_VXD_HEADER {
		SHORTINT e32_magic;
		CHAR e32_border, e32_worder;
		INTEGER e32_level;
		SHORTINT e32_cpu, e32_os;
		INTEGER e32_ver, e32_mflags, e32_mpages, e32_startobj, e32_eip, e32_stackobj, e32_esp, e32_pagesize, e32_lastpagesize, e32_fixupsize, e32_fixupsum, e32_ldrsize, e32_ldrsum, e32_objtab, e32_objcnt, e32_objmap, e32_itermap, e32_rsrctab, e32_rsrccnt, e32_restab, e32_enttab, e32_dirtab, e32_dircnt, e32_fpagetab, e32_frectab, e32_impmod, e32_impmodcnt, e32_impproc, e32_pagesum, e32_datapage, e32_preload, e32_nrestab, e32_cbnrestab, e32_nressum, e32_autodata, e32_debuginfo, e32_debuglen, e32_instpreload, e32_instdemand, e32_heapsize;
		CHAR e32_res3[12];
		INTEGER e32_winresoff, e32_winreslen;
		SHORTINT e32_devid, e32_ddkver;
	} WinApi_IMAGE_VXD_HEADER;

typedef
	struct WinApi_INPUT_RECORD {
		SHORTINT EventType;
		struct WinApi__23 Event;
	} WinApi_INPUT_RECORD;

typedef
	struct WinApi_SYSTEMTIME {
		SHORTINT wYear, wMonth, wDayOfWeek, wDay, wHour, wMinute, wSecond, wMilliseconds;
	} WinApi_SYSTEMTIME;

typedef
	struct WinApi_JOB_INFO_1A {
		INTEGER JobId;
		WinApi_PtrSTR pPrinterName, pMachineName, pUserName, pDocument, pDatatype, pStatus;
		SET Status;
		INTEGER Priority, Position, TotalPages, PagesPrinted;
		WinApi_SYSTEMTIME Submitted;
	} WinApi_JOB_INFO_1A;

typedef
	struct WinApi_JOB_INFO_1W {
		INTEGER JobId;
		WinApi_PtrWSTR pPrinterName, pMachineName, pUserName, pDocument, pDatatype, pStatus;
		SET Status;
		INTEGER Priority, Position, TotalPages, PagesPrinted;
		WinApi_SYSTEMTIME Submitted;
	} WinApi_JOB_INFO_1W;

typedef
	WinApi_DEVMODEA *WinApi_PtrDEVMODEA;

typedef
	struct WinApi_JOB_INFO_2A {
		INTEGER JobId;
		WinApi_PtrSTR pPrinterName, pMachineName, pUserName, pDocument, pNotifyName, pDatatype, pPrintProcessor, pParameters, pDriverName;
		WinApi_PtrDEVMODEA pDevMode;
		WinApi_PtrSTR pStatus;
		INTEGER pSecurityDescriptor;
		SET Status;
		INTEGER Priority, Position, StartTime, UntilTime, TotalPages, Size;
		WinApi_SYSTEMTIME Submitted;
		INTEGER Time, PagesPrinted;
	} WinApi_JOB_INFO_2A;

typedef
	WinApi_DEVMODEW *WinApi_PtrDEVMODEW;

typedef
	struct WinApi_JOB_INFO_2W {
		INTEGER JobId;
		WinApi_PtrWSTR pPrinterName, pMachineName, pUserName, pDocument, pNotifyName, pDatatype, pPrintProcessor, pParameters, pDriverName;
		WinApi_PtrDEVMODEW pDevMode;
		WinApi_PtrWSTR pStatus;
		INTEGER pSecurityDescriptor;
		SET Status;
		INTEGER Priority, Position, StartTime, UntilTime, TotalPages, Size;
		WinApi_SYSTEMTIME Submitted;
		INTEGER Time, PagesPrinted;
	} WinApi_JOB_INFO_2W;

typedef
	struct WinApi_KERNINGPAIR {
		SHORTINT wFirst, wSecond;
		INTEGER iKernAmount;
	} WinApi_KERNINGPAIR;

typedef
	struct WinApi_LAYERPLANEDESCRIPTOR {
		SHORTINT nSize, nVersion;
		SET dwFlags;
		CHAR iPixelType, cColorBits, cRedBits, cRedShift, cGreenBits, cGreenShift, cBlueBits, cBlueShift, cAlphaBits, cAlphaShift, cAccumBits, cAccumRedBits, cAccumGreenBits, cAccumBlueBits, cAccumAlphaBits, cDepthBits, cStencilBits, cAuxBuffers, iLayerPlane, bReserved;
		INTEGER crTransparent;
	} WinApi_LAYERPLANEDESCRIPTOR;

typedef
	struct WinApi_LDT_ENTRY {
		SHORTINT LimitLow, BaseLow;
		struct WinApi__26 HighWord;
	} WinApi_LDT_ENTRY;

typedef
	INTEGER (*WinApi_LINEDDAPROC)(void);

typedef
	struct WinApi_LOCALESIGNATURE {
		INTEGER lsUsb[4];
		INTEGER lsCsbDefault[2];
		INTEGER lsCsbSupported[2];
	} WinApi_LOCALESIGNATURE;

typedef
	INTEGER (*WinApi_LOCALE_ENUMPROCA)(void);

typedef
	INTEGER (*WinApi_LOCALE_ENUMPROCW)(void);

typedef
	struct WinApi_LOGCOLORSPACEA {
		INTEGER lcsSignature, lcsVersion, lcsSize, lcsCSType, lcsIntent;
		WinApi_CIEXYZTRIPLE lcsEndpoints;
		INTEGER lcsGammaRed, lcsGammaGreen, lcsGammaBlue;
		CHAR lcsFilename[260];
	} WinApi_LOGCOLORSPACEA;

typedef
	struct WinApi_LUID_AND_ATTRIBUTES {
		LONGINT Luid;
		SET Attributes;
	} WinApi_LUID_AND_ATTRIBUTES;

typedef
	WinApi_LUID_AND_ATTRIBUTES WinApi_LUID_AND_ATTRIBUTES_ARRAY[1];

typedef
	struct WinApi_MAT2 {
		WinApi_FIXED eM11, eM12, eM21, eM22;
	} WinApi_MAT2;

typedef
	struct WinApi_MDICREATESTRUCTA {
		WinApi_PtrSTR szClass, szTitle;
		INTEGER hOwner, x, y, cx, cy;
		SET style;
		INTEGER lParam;
	} WinApi_MDICREATESTRUCTA;

typedef
	struct WinApi_MDICREATESTRUCTW {
		WinApi_PtrWSTR szClass, szTitle;
		INTEGER hOwner, x, y, cx, cy;
		SET style;
		INTEGER lParam;
	} WinApi_MDICREATESTRUCTW;

typedef
	struct WinApi_MDINEXTMENU {
		INTEGER hmenuIn, hmenuNext, hwndNext;
	} WinApi_MDINEXTMENU;

typedef
	struct WinApi_MEASUREITEMSTRUCT {
		SET CtlType;
		INTEGER CtlID, itemID, itemWidth, itemHeight, itemData;
	} WinApi_MEASUREITEMSTRUCT;

typedef
	struct WinApi_MEMORYSTATUS {
		INTEGER dwLength, dwMemoryLoad, dwTotalPhys, dwAvailPhys, dwTotalPageFile, dwAvailPageFile, dwTotalVirtual, dwAvailVirtual;
	} WinApi_MEMORYSTATUS;

typedef
	struct WinApi_MEMORY_BASIC_INFORMATION {
		INTEGER BaseAddress, AllocationBase, AllocationProtect, RegionSize, State, Protect, Type;
	} WinApi_MEMORY_BASIC_INFORMATION;

typedef
	struct WinApi_MENUITEMINFOA {
		INTEGER cbSize;
		SET fMask, fType, fState;
		INTEGER wID, hSubMenu, hbmpChecked, hbmpUnchecked, dwItemData;
		WinApi_PtrSTR dwTypeData;
		INTEGER cch;
	} WinApi_MENUITEMINFOA;

typedef
	struct WinApi_MENUITEMINFOW {
		INTEGER cbSize;
		SET fMask, fType, fState;
		INTEGER wID, hSubMenu, hbmpChecked, hbmpUnchecked, dwItemData;
		WinApi_PtrWSTR dwTypeData;
		INTEGER cch;
	} WinApi_MENUITEMINFOW;

typedef
	struct WinApi_MENUITEMTEMPLATE {
		SHORTINT mtOption, mtID;
		SHORTINT mtString[1];
	} WinApi_MENUITEMTEMPLATE;

typedef
	struct WinApi_MENUITEMTEMPLATEHEADER {
		SHORTINT versionNumber, offset;
	} WinApi_MENUITEMTEMPLATEHEADER;

typedef
	struct WinApi_MENUTEMPLATE {
		char _prvt0[1];
	} WinApi_MENUTEMPLATE;

typedef
	struct WinApi_MENUTEMPLATEA {
		char _prvt0[1];
	} WinApi_MENUTEMPLATEA;

typedef
	struct WinApi_MENUTEMPLATEW {
		char _prvt0[1];
	} WinApi_MENUTEMPLATEW;

typedef
	struct WinApi_MESSAGE_RESOURCE_BLOCK {
		INTEGER LowId, HighId, OffsetToEntries;
	} WinApi_MESSAGE_RESOURCE_BLOCK;

typedef
	struct WinApi_MESSAGE_RESOURCE_DATA {
		INTEGER NumberOfBlocks;
		WinApi_MESSAGE_RESOURCE_BLOCK Blocks[1];
	} WinApi_MESSAGE_RESOURCE_DATA;

typedef
	struct WinApi_MESSAGE_RESOURCE_ENTRY {
		SHORTINT Length, Flags;
		CHAR Text[1];
	} WinApi_MESSAGE_RESOURCE_ENTRY;

typedef
	struct WinApi_METAFILEPICT {
		INTEGER mm, xExt, yExt, hMF;
	} WinApi_METAFILEPICT;

typedef
	struct WinApi_METAHEADER {
		SHORTINT mtType, mtHeaderSize, mtVersion;
		INTEGER mtSize;
		SHORTINT mtNoObjects;
		INTEGER mtMaxRecord;
		SHORTINT mtNoParameters;
	} WinApi_METAHEADER;

typedef
	struct WinApi_METARECORD {
		INTEGER rdSize;
		SHORTINT rdFunction;
		SHORTINT rdParm[1];
	} WinApi_METARECORD;

typedef
	INTEGER (*WinApi_MFENUMPROC)(INTEGER, WinApi_HANDLETABLE*, LONGINT *, WinApi_METARECORD*, LONGINT *, INTEGER, INTEGER);

typedef
	struct WinApi_MINIMIZEDMETRICS {
		INTEGER cbSize, iWidth, iHorzGap, iVertGap, iArrange;
	} WinApi_MINIMIZEDMETRICS;

typedef
	struct WinApi_MINMAXINFO {
		WinApi_POINT ptReserved, ptMaxSize, ptMaxPosition, ptMinTrackSize, ptMaxTrackSize;
	} WinApi_MINMAXINFO;

typedef
	struct WinApi_MODEMDEVCAPS {
		INTEGER dwActualSize, dwRequiredSize, dwDevSpecificOffset, dwDevSpecificSize, dwModemProviderVersion, dwModemManufacturerOffset, dwModemManufacturerSize, dwModemModelOffset, dwModemModelSize, dwModemVersionOffset, dwModemVersionSize, dwDialOptions, dwCallSetupFailTimer, dwInactivityTimeout;
		SET dwSpeakerVolume, dwSpeakerMode, dwModemOptions;
		INTEGER dwMaxDTERate, dwMaxDCERate;
		CHAR abVariablePortion[1];
	} WinApi_MODEMDEVCAPS;

typedef
	struct WinApi_MODEMSETTINGS {
		INTEGER dwActualSize, dwRequiredSize, dwDevSpecificOffset, dwDevSpecificSize, dwCallSetupFailTimer, dwInactivityTimeout;
		SET dwSpeakerVolume, dwSpeakerMode;
		INTEGER dwPreferredModemOptions, dwNegotiatedModemOptions, dwNegotiatedDCERate;
		CHAR abVariablePortion[1];
	} WinApi_MODEMSETTINGS;

typedef
	struct WinApi_MONCBSTRUCT {
		INTEGER cb, dwTime, hTask, dwRet, wType, wFmt, hConv, hsz1, hsz2, hData, dwData1, dwData2;
		WinApi_CONVCONTEXT cc;
		INTEGER cbData;
		INTEGER Data[8];
	} WinApi_MONCBSTRUCT;

typedef
	struct WinApi_MONCONVSTRUCT {
		INTEGER cb, fConnect, dwTime, hTask, hszSvc, hszTopic, hConvClient, hConvServer;
	} WinApi_MONCONVSTRUCT;

typedef
	struct WinApi_MONERRSTRUCT {
		INTEGER cb, wLastError, dwTime, hTask;
	} WinApi_MONERRSTRUCT;

typedef
	struct WinApi_MONHSZSTRUCTA {
		INTEGER cb, fsAction, dwTime, hsz, hTask;
		CHAR str[1];
	} WinApi_MONHSZSTRUCTA;

typedef
	struct WinApi_MONHSZSTRUCTW {
		INTEGER cb, fsAction, dwTime, hsz, hTask;
		SHORTINT str[1];
	} WinApi_MONHSZSTRUCTW;

typedef
	struct WinApi_MONITOR_INFO_1A {
		WinApi_PtrSTR pName;
	} WinApi_MONITOR_INFO_1A;

typedef
	struct WinApi_MONITOR_INFO_1W {
		WinApi_PtrWSTR pName;
	} WinApi_MONITOR_INFO_1W;

typedef
	struct WinApi_MONITOR_INFO_2A {
		WinApi_PtrSTR pName, pEnvironment, pDLLName;
	} WinApi_MONITOR_INFO_2A;

typedef
	struct WinApi_MONITOR_INFO_2W {
		WinApi_PtrWSTR pName, pEnvironment, pDLLName;
	} WinApi_MONITOR_INFO_2W;

typedef
	struct WinApi_MONLINKSTRUCT {
		INTEGER cb, dwTime, hTask, fEstablished, fNoData, hszSvc, hszTopic, hszItem, wFmt, fServer, hConvServer, hConvClient;
	} WinApi_MONLINKSTRUCT;

typedef
	struct WinApi_MONMSGSTRUCT {
		INTEGER cb, hwndTo, dwTime, hTask, wMsg, wParam, lParam;
		WinApi_DDEML_MSG_HOOK_DATA dmhd;
	} WinApi_MONMSGSTRUCT;

typedef
	struct WinApi_MOUSEHOOKSTRUCT {
		WinApi_POINT pt;
		INTEGER hwnd, wHitTestCode, dwExtraInfo;
	} WinApi_MOUSEHOOKSTRUCT;

typedef
	struct WinApi_MOUSEKEYS {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER iMaxSpeed, iTimeToMaxSpeed, iCtrlSpeed, dwReserved1, dwReserved2;
	} WinApi_MOUSEKEYS;

typedef
	struct WinApi_MSG {
		INTEGER hwnd, message, wParam, lParam, time;
		WinApi_POINT pt;
	} WinApi_MSG;

typedef
	void (*WinApi_MSGBOXCALLBACK)(WinApi_HELPINFO*, LONGINT *);

typedef
	struct WinApi_MSGBOXPARAMSA {
		INTEGER cbSize, hwndOwner, hInstance;
		WinApi_PtrSTR lpszText, lpszCaption;
		SET dwStyle;
		WinApi_PtrSTR lpszIcon;
		INTEGER dwContextHelpId;
		WinApi_MSGBOXCALLBACK lpfnMsgBoxCallback;
		INTEGER dwLanguageId;
	} WinApi_MSGBOXPARAMSA;

typedef
	struct WinApi_MSGBOXPARAMSW {
		INTEGER cbSize, hwndOwner, hInstance;
		WinApi_PtrWSTR lpszText, lpszCaption;
		SET dwStyle;
		WinApi_PtrWSTR lpszIcon;
		INTEGER dwContextHelpId;
		WinApi_MSGBOXCALLBACK lpfnMsgBoxCallback;
		INTEGER dwLanguageId;
	} WinApi_MSGBOXPARAMSW;

typedef
	struct WinApi_MULTIKEYHELPA {
		INTEGER mkSize;
		CHAR mkKeylist;
		CHAR szKeyphrase[1];
	} WinApi_MULTIKEYHELPA;

typedef
	struct WinApi_MULTIKEYHELPW {
		INTEGER mkSize;
		SHORTINT mkKeylist;
		SHORTINT szKeyphrase[1];
	} WinApi_MULTIKEYHELPW;

typedef
	INTEGER (*WinApi_NAMEENUMPROCA)(void);

typedef
	INTEGER (*WinApi_NAMEENUMPROCW)(void);

typedef
	struct WinApi_WINDOWPOS *WinApi_PtrWINDOWPOS;

typedef
	struct WinApi_NCCALCSIZE_PARAMS {
		WinApi_RECT rgrc[3];
		WinApi_PtrWINDOWPOS lppos;
	} WinApi_NCCALCSIZE_PARAMS;

typedef
	INTEGER (*WinApi_NEARPROC)(void);

typedef
	INTEGER (*WinApi_NEWFONTENUMPROC)(WinApi_ENUMLOGFONTA*, LONGINT *, WinApi_NEWTEXTMETRICA*, LONGINT *, INTEGER, INTEGER);

typedef
	INTEGER (*WinApi_NEWFONTENUMPROCA)(WinApi_ENUMLOGFONTA*, LONGINT *, WinApi_NEWTEXTMETRICA*, LONGINT *, INTEGER, INTEGER);

typedef
	INTEGER (*WinApi_NEWFONTENUMPROCW)(WinApi_ENUMLOGFONTW*, LONGINT *, WinApi_NEWTEXTMETRICW*, LONGINT *, INTEGER, INTEGER);

typedef
	struct WinApi_NMHDR {
		INTEGER hwndFrom, idFrom, code;
	} WinApi_NMHDR;

typedef
	struct WinApi_NONCLIENTMETRICSA {
		INTEGER cbSize, iBorderWidth, iScrollWidth, iScrollHeight, iCaptionWidth, iCaptionHeight;
		WinApi_LOGFONTA lfCaptionFont;
		INTEGER iSmCaptionWidth, iSmCaptionHeight;
		WinApi_LOGFONTA lfSmCaptionFont;
		INTEGER iMenuWidth, iMenuHeight;
		WinApi_LOGFONTA lfMenuFont, lfStatusFont, lfMessageFont;
	} WinApi_NONCLIENTMETRICSA;

typedef
	struct WinApi_NONCLIENTMETRICSW {
		INTEGER cbSize, iBorderWidth, iScrollWidth, iScrollHeight, iCaptionWidth, iCaptionHeight;
		WinApi_LOGFONTW lfCaptionFont;
		INTEGER iSmCaptionWidth, iSmCaptionHeight;
		WinApi_LOGFONTW lfSmCaptionFont;
		INTEGER iMenuWidth, iMenuHeight;
		WinApi_LOGFONTW lfMenuFont, lfStatusFont, lfMessageFont;
	} WinApi_NONCLIENTMETRICSW;

typedef
	struct WinApi_NOTIFYICONDATAA {
		INTEGER cbSize, hWnd, uID;
		SET uFlags;
		INTEGER uCallbackMessage, hIcon;
		CHAR szTip[64];
	} WinApi_NOTIFYICONDATAA;

typedef
	struct WinApi_NOTIFYICONDATAW {
		INTEGER cbSize, hWnd, uID;
		SET uFlags;
		INTEGER uCallbackMessage, hIcon;
		SHORTINT szTip[64];
	} WinApi_NOTIFYICONDATAW;

typedef
	struct WinApi__EXCEPTION_REGISTRATION_RECORD *WinApi_Ptr_EXCEPTION_REGISTRATION_RECORD;

typedef
	struct WinApi_NT_TIB *WinApi_PtrNT_TIB;

typedef
	struct WinApi_NT_TIB {
		WinApi_Ptr_EXCEPTION_REGISTRATION_RECORD ExceptionList;
		INTEGER StackBase, StackLimit, SubSystemTib;
		struct WinApi__27 u;
		INTEGER ArbitraryUserPointer;
		WinApi_PtrNT_TIB Self;
	} WinApi_NT_TIB;

typedef
	struct WinApi_NUMBERFMTA {
		INTEGER NumDigits, LeadingZero, Grouping;
		WinApi_PtrSTR lpDecimalSep, lpThousandSep;
		INTEGER NegativeOrder;
	} WinApi_NUMBERFMTA;

typedef
	struct WinApi_NUMBERFMTW {
		INTEGER NumDigits, LeadingZero, Grouping;
		WinApi_PtrWSTR lpDecimalSep, lpThousandSep;
		INTEGER NegativeOrder;
	} WinApi_NUMBERFMTW;

typedef
	struct WinApi_OBJECTID {
		WinApi_COM_GUID Lineage;
		INTEGER Uniquifier;
	} WinApi_OBJECTID;

typedef
	struct WinApi_OFSTRUCT {
		CHAR cBytes, fFixedDisk;
		SHORTINT nErrCode, Reserved1, Reserved2;
		CHAR szPathName[128];
	} WinApi_OFSTRUCT;

typedef
	INTEGER (*WinApi_OLDFONTENUMPROC)(void);

typedef
	struct WinApi_OSVERSIONINFOA {
		INTEGER dwOSVersionInfoSize, dwMajorVersion, dwMinorVersion, dwBuildNumber, dwPlatformId;
		CHAR szCSDVersion[128];
	} WinApi_OSVERSIONINFOA;

typedef
	struct WinApi_OSVERSIONINFOW {
		INTEGER dwOSVersionInfoSize, dwMajorVersion, dwMinorVersion, dwBuildNumber, dwPlatformId;
		SHORTINT szCSDVersion[128];
	} WinApi_OSVERSIONINFOW;

typedef
	struct WinApi_OUTLINETEXTMETRICA {
		INTEGER otmSize;
		WinApi_TEXTMETRICA otmTextMetrics;
		CHAR otmFiller;
		WinApi_PANOSE otmPanoseNumber;
		INTEGER otmfsSelection, otmfsType, otmsCharSlopeRise, otmsCharSlopeRun, otmItalicAngle, otmEMSquare, otmAscent, otmDescent, otmLineGap, otmsCapEmHeight, otmsXHeight;
		WinApi_RECT otmrcFontBox;
		INTEGER otmMacAscent, otmMacDescent, otmMacLineGap, otmusMinimumPPEM;
		WinApi_POINT otmptSubscriptSize, otmptSubscriptOffset, otmptSuperscriptSize, otmptSuperscriptOffset;
		INTEGER otmsStrikeoutSize, otmsStrikeoutPosition, otmsUnderscoreSize, otmsUnderscorePosition;
		WinApi_PtrSTR otmpFamilyName, otmpFaceName, otmpStyleName, otmpFullName;
	} WinApi_OUTLINETEXTMETRICA;

typedef
	struct WinApi_OUTLINETEXTMETRICW {
		INTEGER otmSize;
		WinApi_TEXTMETRICW otmTextMetrics;
		CHAR otmFiller;
		WinApi_PANOSE otmPanoseNumber;
		INTEGER otmfsSelection, otmfsType, otmsCharSlopeRise, otmsCharSlopeRun, otmItalicAngle, otmEMSquare, otmAscent, otmDescent, otmLineGap, otmsCapEmHeight, otmsXHeight;
		WinApi_RECT otmrcFontBox;
		INTEGER otmMacAscent, otmMacDescent, otmMacLineGap, otmusMinimumPPEM;
		WinApi_POINT otmptSubscriptSize, otmptSubscriptOffset, otmptSuperscriptSize, otmptSuperscriptOffset;
		INTEGER otmsStrikeoutSize, otmsStrikeoutPosition, otmsUnderscoreSize, otmsUnderscorePosition;
		WinApi_PtrSTR otmpFamilyName, otmpFaceName, otmpStyleName, otmpFullName;
	} WinApi_OUTLINETEXTMETRICW;

typedef
	struct WinApi_OVERLAPPED {
		INTEGER Internal, InternalHigh, Offset, OffsetHigh, hEvent;
	} WinApi_OVERLAPPED;

typedef
	void (*WinApi_OVERLAPPED_COMPLETION_ROUTINE)(INTEGER, INTEGER, WinApi_OVERLAPPED*, LONGINT *);

typedef
	struct WinApi_PAINTSTRUCT {
		INTEGER hdc, fErase;
		WinApi_RECT rcPaint;
		INTEGER fRestore, fIncUpdate;
		CHAR rgbReserved[32];
	} WinApi_PAINTSTRUCT;

typedef
	struct WinApi_PELARRAY {
		INTEGER paXCount, paYCount, paXExt, paYExt;
		CHAR paRGBs;
	} WinApi_PELARRAY;

typedef
	struct WinApi_POINTFX {
		WinApi_FIXED x, y;
	} WinApi_POINTFX;

typedef
	struct WinApi_POLYTEXTA {
		INTEGER x, y, n;
		WinApi_PtrSTR lpstr;
		SET uiFlags;
		WinApi_RECT rcl;
		struct {
			LONGINT len[1];
			INTEGER data[1];
		} *pdx;
	} WinApi_POLYTEXTA;

typedef
	struct WinApi_POLYTEXTW {
		INTEGER x, y, n;
		WinApi_PtrWSTR lpstr;
		SET uiFlags;
		WinApi_RECT rcl;
		struct {
			LONGINT len[1];
			INTEGER data[1];
		} *pdx;
	} WinApi_POLYTEXTW;

typedef
	struct WinApi_PORT_INFO_1A {
		WinApi_PtrSTR pName;
	} WinApi_PORT_INFO_1A;

typedef
	struct WinApi_PORT_INFO_1W {
		WinApi_PtrWSTR pName;
	} WinApi_PORT_INFO_1W;

typedef
	struct WinApi_PORT_INFO_2A {
		WinApi_PtrSTR pPortName, pMonitorName, pDescription;
		INTEGER fPortType, Reserved;
	} WinApi_PORT_INFO_2A;

typedef
	struct WinApi_PORT_INFO_2W {
		WinApi_PtrWSTR pPortName, pMonitorName, pDescription;
		INTEGER fPortType, Reserved;
	} WinApi_PORT_INFO_2W;

typedef
	struct WinApi_PRINTER_DEFAULTSA {
		WinApi_PtrSTR pDatatype;
		WinApi_PtrDEVMODEA pDevMode;
		SET DesiredAccess;
	} WinApi_PRINTER_DEFAULTSA;

typedef
	struct WinApi_PRINTER_DEFAULTSW {
		WinApi_PtrWSTR pDatatype;
		WinApi_PtrDEVMODEW pDevMode;
		SET DesiredAccess;
	} WinApi_PRINTER_DEFAULTSW;

typedef
	struct WinApi_PRINTER_INFO_1A {
		SET Flags;
		WinApi_PtrSTR pDescription, pName, pComment;
	} WinApi_PRINTER_INFO_1A;

typedef
	struct WinApi_PRINTER_INFO_1W {
		SET Flags;
		WinApi_PtrWSTR pDescription, pName, pComment;
	} WinApi_PRINTER_INFO_1W;

typedef
	struct WinApi_PRINTER_INFO_2A {
		WinApi_PtrSTR pServerName, pPrinterName, pShareName, pPortName, pDriverName, pComment, pLocation;
		WinApi_PtrDEVMODEA pDevMode;
		WinApi_PtrSTR pSepFile, pPrintProcessor, pDatatype, pParameters;
		INTEGER pSecurityDescriptor;
		SET Attributes;
		INTEGER Priority, DefaultPriority, StartTime, UntilTime;
		SET Status;
		INTEGER cJobs, AveragePPM;
	} WinApi_PRINTER_INFO_2A;

typedef
	struct WinApi_PRINTER_INFO_2W {
		WinApi_PtrWSTR pServerName, pPrinterName, pShareName, pPortName, pDriverName, pComment, pLocation;
		WinApi_PtrDEVMODEW pDevMode;
		WinApi_PtrWSTR pSepFile, pPrintProcessor, pDatatype, pParameters;
		INTEGER pSecurityDescriptor;
		SET Attributes;
		INTEGER Priority, DefaultPriority, StartTime, UntilTime;
		SET Status;
		INTEGER cJobs, AveragePPM;
	} WinApi_PRINTER_INFO_2W;

typedef
	struct WinApi_PRINTER_INFO_3 {
		INTEGER pSecurityDescriptor;
	} WinApi_PRINTER_INFO_3;

typedef
	struct WinApi_PRINTER_INFO_4A {
		WinApi_PtrSTR pPrinterName, pServerName;
		SET Attributes;
	} WinApi_PRINTER_INFO_4A;

typedef
	struct WinApi_PRINTER_INFO_4W {
		WinApi_PtrWSTR pPrinterName, pServerName;
		SET Attributes;
	} WinApi_PRINTER_INFO_4W;

typedef
	struct WinApi_PRINTER_INFO_5A {
		WinApi_PtrSTR pPrinterName, pPortName;
		SET Attributes;
		INTEGER DeviceNotSelectedTimeout, TransmissionRetryTimeout;
	} WinApi_PRINTER_INFO_5A;

typedef
	struct WinApi_PRINTER_INFO_5W {
		WinApi_PtrWSTR pPrinterName, pPortName;
		SET Attributes;
		INTEGER DeviceNotSelectedTimeout, TransmissionRetryTimeout;
	} WinApi_PRINTER_INFO_5W;

typedef
	struct WinApi_PRINTER_INFO_6 {
		SET dwStatus;
	} WinApi_PRINTER_INFO_6;

typedef
	struct WinApi_PRINTER_NOTIFY_INFO_DATA {
		SHORTINT Type, Field;
		INTEGER Reserved, Id;
		struct WinApi__29 NotifyData;
	} WinApi_PRINTER_NOTIFY_INFO_DATA;

typedef
	struct WinApi_PRINTER_NOTIFY_INFO {
		INTEGER Version;
		SET Flags;
		INTEGER Count;
		WinApi_PRINTER_NOTIFY_INFO_DATA aData[1];
	} WinApi_PRINTER_NOTIFY_INFO;

typedef
	struct WinApi_PRINTER_NOTIFY_OPTIONS_TYPE *WinApi_PtrPRINTER_NOTIFY_OPTIONS_TYPE;

typedef
	struct WinApi_PRINTER_NOTIFY_OPTIONS {
		INTEGER Version;
		SET Flags;
		INTEGER Count;
		WinApi_PtrPRINTER_NOTIFY_OPTIONS_TYPE pTypes;
	} WinApi_PRINTER_NOTIFY_OPTIONS;

typedef
	struct WinApi_PRINTER_NOTIFY_OPTIONS_TYPE {
		SHORTINT Type, Reserved0;
		INTEGER Reserved1, Reserved2, Count;
		struct {
			LONGINT len[1];
			SHORTINT data[1];
		} *pFields;
	} WinApi_PRINTER_NOTIFY_OPTIONS_TYPE;

typedef
	struct WinApi_PRINTPROCESSOR_INFO_1A {
		WinApi_PtrSTR pName;
	} WinApi_PRINTPROCESSOR_INFO_1A;

typedef
	struct WinApi_PRINTPROCESSOR_INFO_1W {
		WinApi_PtrWSTR pName;
	} WinApi_PRINTPROCESSOR_INFO_1W;

typedef
	struct WinApi_PRIVILEGE_SET {
		INTEGER PrivilegeCount, Control;
		WinApi_LUID_AND_ATTRIBUTES Privilege[1];
	} WinApi_PRIVILEGE_SET;

typedef
	struct WinApi_PROCESS_HEAP_ENTRY {
		INTEGER lpData, cbData;
		CHAR cbOverhead, iRegionIndex;
		SHORTINT wFlags;
		struct WinApi__32 u;
	} WinApi_PROCESS_HEAP_ENTRY;

typedef
	struct WinApi_PROCESS_INFORMATION {
		INTEGER hProcess, hThread, dwProcessId, dwThreadId;
	} WinApi_PROCESS_INFORMATION;

typedef
	INTEGER (*WinApi_PROGRESS_ROUTINE)(LONGINT, LONGINT, LONGINT, LONGINT, INTEGER, INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	struct WinApi_PROPSHEETHEADERA {
		INTEGER dwSize;
		SET dwFlags;
		INTEGER hwndParent, hInstance;
		struct WinApi__33 u;
		WinApi_PtrSTR pszCaption;
		INTEGER nPages;
		struct WinApi__34 u1;
		struct WinApi__37 u2;
		WinApi_FNPROPSHEETCALLBACK pfnCallback;
	} WinApi_PROPSHEETHEADERA;

typedef
	struct WinApi_PROPSHEETHEADERW {
		INTEGER dwSize;
		SET dwFlags;
		INTEGER hwndParent, hInstance;
		struct WinApi__38 u;
		WinApi_PtrWSTR pszCaption;
		INTEGER nPages;
		struct WinApi__39 u1;
		struct WinApi__42 u2;
		WinApi_FNPROPSHEETCALLBACK pfnCallback;
	} WinApi_PROPSHEETHEADERW;

typedef
	struct WinApi_PROPSHEETPAGEA {
		INTEGER dwSize;
		SET dwFlags;
		INTEGER hInstance;
		struct WinApi__35 u;
		struct WinApi__36 u1;
		WinApi_PtrSTR pszTitle;
		WinApi_DLGPROC pfnDlgProc;
		INTEGER lParam;
		WinApi_FNPSPCALLBACKA pfnCallback;
		struct {
			LONGINT len[1];
			INTEGER data[1];
		} *pcRefParent;
	} WinApi_PROPSHEETPAGEA;

typedef
	struct WinApi_PROPSHEETPAGEW {
		INTEGER dwSize;
		SET dwFlags;
		INTEGER hInstance;
		struct WinApi__40 u;
		struct WinApi__41 u1;
		WinApi_PtrWSTR pszTitle;
		WinApi_DLGPROC pfnDlgProc;
		INTEGER lParam;
		WinApi_FNPSPCALLBACKW pfnCallback;
		struct {
			LONGINT len[1];
			INTEGER data[1];
		} *pcRefParent;
	} WinApi_PROPSHEETPAGEW;

typedef
	struct WinApi_PROVIDOR_INFO_1A {
		WinApi_PtrSTR pName, pEnvironment, pDLLName;
	} WinApi_PROVIDOR_INFO_1A;

typedef
	struct WinApi_PROVIDOR_INFO_1W {
		WinApi_PtrWSTR pName, pEnvironment, pDLLName;
	} WinApi_PROVIDOR_INFO_1W;

typedef
	struct WinApi_PSHNOTIFY {
		WinApi_NMHDR hdr;
		INTEGER lParam;
	} WinApi_PSHNOTIFY;

typedef
	struct WinApi_PVALUEA {
		WinApi_PtrSTR pv_valuename;
		INTEGER pv_valuelen, pv_value_context, pv_type;
	} WinApi_PVALUEA;

typedef
	struct WinApi_PVALUEW {
		WinApi_PtrWSTR pv_valuename;
		INTEGER pv_valuelen, pv_value_context, pv_type;
	} WinApi_PVALUEW;

typedef
	WinApi_ABC *WinApi_PtrABC;

typedef
	WinApi_ABCFLOAT *WinApi_PtrABCFLOAT;

typedef
	WinApi_ACCEL *WinApi_PtrACCEL;

typedef
	WinApi_ACCESSTIMEOUT *WinApi_PtrACCESSTIMEOUT;

typedef
	WinApi_ACCESS_ALLOWED_ACE *WinApi_PtrACCESS_ALLOWED_ACE;

typedef
	WinApi_ACCESS_DENIED_ACE *WinApi_PtrACCESS_DENIED_ACE;

typedef
	WinApi_ACE_HEADER *WinApi_PtrACE_HEADER;

typedef
	WinApi_ACL *WinApi_PtrACL;

typedef
	WinApi_ACL_REVISION_INFORMATION *WinApi_PtrACL_REVISION_INFORMATION;

typedef
	WinApi_ACL_SIZE_INFORMATION *WinApi_PtrACL_SIZE_INFORMATION;

typedef
	WinApi_ADDJOB_INFO_1A *WinApi_PtrADDJOB_INFO_1A;

typedef
	WinApi_ADDJOB_INFO_1W *WinApi_PtrADDJOB_INFO_1W;

typedef
	WinApi_ANIMATIONINFO *WinApi_PtrANIMATIONINFO;

typedef
	WinApi_APPBARDATA *WinApi_PtrAPPBARDATA;

typedef
	WinApi_BITMAP *WinApi_PtrBITMAP;

typedef
	WinApi_BITMAPCOREHEADER *WinApi_PtrBITMAPCOREHEADER;

typedef
	WinApi_BITMAPCOREINFO *WinApi_PtrBITMAPCOREINFO;

typedef
	WinApi_BITMAPFILEHEADER *WinApi_PtrBITMAPFILEHEADER;

typedef
	WinApi_BITMAPINFO *WinApi_PtrBITMAPINFO;

typedef
	WinApi_BITMAPINFOHEADER *WinApi_PtrBITMAPINFOHEADER;

typedef
	WinApi_BITMAPV4HEADER *WinApi_PtrBITMAPV4HEADER;

typedef
	WinApi_BROADCASTSYSMSG *WinApi_PtrBROADCASTSYSMSG;

typedef
	WinApi_BY_HANDLE_FILE_INFORMATION *WinApi_PtrBY_HANDLE_FILE_INFORMATION;

typedef
	WinApi_CBTACTIVATESTRUCT *WinApi_PtrCBTACTIVATESTRUCT;

typedef
	WinApi_CBT_CREATEWNDA *WinApi_PtrCBT_CREATEWNDA;

typedef
	WinApi_CBT_CREATEWNDW *WinApi_PtrCBT_CREATEWNDW;

typedef
	WinApi_CHARSETINFO *WinApi_PtrCHARSETINFO;

typedef
	WinApi_CHAR_INFO *WinApi_PtrCHAR_INFO;

typedef
	WinApi_CIEXYZ *WinApi_PtrCIEXYZ;

typedef
	WinApi_CIEXYZTRIPLE *WinApi_PtrCIEXYZTRIPLE;

typedef
	WinApi_CLIENTCREATESTRUCT *WinApi_PtrCLIENTCREATESTRUCT;

typedef
	WinApi_COLORADJUSTMENT *WinApi_PtrCOLORADJUSTMENT;

typedef
	WinApi_COMMCONFIG *WinApi_PtrCOMMCONFIG;

typedef
	WinApi_COMMPROP *WinApi_PtrCOMMPROP;

typedef
	WinApi_COMMTIMEOUTS *WinApi_PtrCOMMTIMEOUTS;

typedef
	WinApi_COMPAREITEMSTRUCT *WinApi_PtrCOMPAREITEMSTRUCT;

typedef
	WinApi_COMPOUND_ACCESS_ALLOWED_ACE *WinApi_PtrCOMPOUND_ACCESS_ALLOWED_ACE;

typedef
	WinApi_COMSTAT *WinApi_PtrCOMSTAT;

typedef
	WinApi_CONSOLE_CURSOR_INFO *WinApi_PtrCONSOLE_CURSOR_INFO;

typedef
	WinApi_CONSOLE_SCREEN_BUFFER_INFO *WinApi_PtrCONSOLE_SCREEN_BUFFER_INFO;

typedef
	WinApi_CONVCONTEXT *WinApi_PtrCONVCONTEXT;

typedef
	WinApi_CONVINFO *WinApi_PtrCONVINFO;

typedef
	WinApi_COORD *WinApi_PtrCOORD;

typedef
	WinApi_COPYDATASTRUCT *WinApi_PtrCOPYDATASTRUCT;

typedef
	WinApi_CPINFO *WinApi_PtrCPINFO;

typedef
	WinApi_CREATE_PROCESS_DEBUG_INFO *WinApi_PtrCREATE_PROCESS_DEBUG_INFO;

typedef
	WinApi_CREATE_THREAD_DEBUG_INFO *WinApi_PtrCREATE_THREAD_DEBUG_INFO;

typedef
	WinApi_CURRENCYFMTA *WinApi_PtrCURRENCYFMTA;

typedef
	WinApi_CURRENCYFMTW *WinApi_PtrCURRENCYFMTW;

typedef
	WinApi_CURSORSHAPE *WinApi_PtrCURSORSHAPE;

typedef
	WinApi_CWPRETSTRUCT *WinApi_PtrCWPRETSTRUCT;

typedef
	WinApi_CWPSTRUCT *WinApi_PtrCWPSTRUCT;

typedef
	WinApi_DATATYPES_INFO_1A *WinApi_PtrDATATYPES_INFO_1A;

typedef
	WinApi_DATATYPES_INFO_1W *WinApi_PtrDATATYPES_INFO_1W;

typedef
	WinApi_DCB *WinApi_PtrDCB;

typedef
	WinApi_DDEML_MSG_HOOK_DATA *WinApi_PtrDDEML_MSG_HOOK_DATA;

typedef
	WinApi_DEBUGHOOKINFO *WinApi_PtrDEBUGHOOKINFO;

typedef
	WinApi_DEBUG_EVENT *WinApi_PtrDEBUG_EVENT;

typedef
	WinApi_DELETEITEMSTRUCT *WinApi_PtrDELETEITEMSTRUCT;

typedef
	WinApi_DIBSECTION *WinApi_PtrDIBSECTION;

typedef
	WinApi_DLGITEMTEMPLATE *WinApi_PtrDLGITEMTEMPLATE;

typedef
	WinApi_DOCINFOA *WinApi_PtrDOCINFOA;

typedef
	WinApi_DOCINFOW *WinApi_PtrDOCINFOW;

typedef
	WinApi_DOC_INFO_1A *WinApi_PtrDOC_INFO_1A;

typedef
	WinApi_DOC_INFO_1W *WinApi_PtrDOC_INFO_1W;

typedef
	WinApi_DOC_INFO_2A *WinApi_PtrDOC_INFO_2A;

typedef
	WinApi_DOC_INFO_2W *WinApi_PtrDOC_INFO_2W;

typedef
	WinApi_DRAGINFOA *WinApi_PtrDRAGINFOA;

typedef
	WinApi_DRAGINFOW *WinApi_PtrDRAGINFOW;

typedef
	WinApi_DRAWITEMSTRUCT *WinApi_PtrDRAWITEMSTRUCT;

typedef
	WinApi_DRAWTEXTPARAMS *WinApi_PtrDRAWTEXTPARAMS;

typedef
	WinApi_DRIVER_INFO_1A *WinApi_PtrDRIVER_INFO_1A;

typedef
	WinApi_DRIVER_INFO_1W *WinApi_PtrDRIVER_INFO_1W;

typedef
	WinApi_DRIVER_INFO_2A *WinApi_PtrDRIVER_INFO_2A;

typedef
	WinApi_DRIVER_INFO_2W *WinApi_PtrDRIVER_INFO_2W;

typedef
	WinApi_DRIVER_INFO_3A *WinApi_PtrDRIVER_INFO_3A;

typedef
	WinApi_DRIVER_INFO_3W *WinApi_PtrDRIVER_INFO_3W;

typedef
	WinApi_DROPSTRUCT *WinApi_PtrDROPSTRUCT;

typedef
	WinApi_EMR *WinApi_PtrEMR;

typedef
	WinApi_EMRABORTPATH *WinApi_PtrEMRABORTPATH;

typedef
	WinApi_EMRANGLEARC *WinApi_PtrEMRANGLEARC;

typedef
	WinApi_EMRARC *WinApi_PtrEMRARC;

typedef
	WinApi_EMRBITBLT *WinApi_PtrEMRBITBLT;

typedef
	WinApi_EMRCREATEBRUSHINDIRECT *WinApi_PtrEMRCREATEBRUSHINDIRECT;

typedef
	WinApi_EMRCREATECOLORSPACE *WinApi_PtrEMRCREATECOLORSPACE;

typedef
	WinApi_EMRCREATEDIBPATTERNBRUSHPT *WinApi_PtrEMRCREATEDIBPATTERNBRUSHPT;

typedef
	WinApi_EMRCREATEMONOBRUSH *WinApi_PtrEMRCREATEMONOBRUSH;

typedef
	WinApi_EMRCREATEPALETTE *WinApi_PtrEMRCREATEPALETTE;

typedef
	WinApi_EMRCREATEPEN *WinApi_PtrEMRCREATEPEN;

typedef
	WinApi_EMRSELECTCOLORSPACE *WinApi_PtrEMRSELECTCOLORSPACE;

typedef
	WinApi_EMRSELECTOBJECT *WinApi_PtrEMRSELECTOBJECT;

typedef
	WinApi_EMRELLIPSE *WinApi_PtrEMRELLIPSE;

typedef
	WinApi_EMREOF *WinApi_PtrEMREOF;

typedef
	WinApi_EMREXCLUDECLIPRECT *WinApi_PtrEMREXCLUDECLIPRECT;

typedef
	WinApi_EMREXTCREATEFONTINDIRECTW *WinApi_PtrEMREXTCREATEFONTINDIRECTW;

typedef
	WinApi_EMREXTCREATEPEN *WinApi_PtrEMREXTCREATEPEN;

typedef
	WinApi_EMREXTFLOODFILL *WinApi_PtrEMREXTFLOODFILL;

typedef
	WinApi_EMREXTSELECTCLIPRGN *WinApi_PtrEMREXTSELECTCLIPRGN;

typedef
	WinApi_EMREXTTEXTOUTA *WinApi_PtrEMREXTTEXTOUTA;

typedef
	WinApi_EMRFILLPATH *WinApi_PtrEMRFILLPATH;

typedef
	WinApi_EMRFILLRGN *WinApi_PtrEMRFILLRGN;

typedef
	WinApi_EMRFORMAT *WinApi_PtrEMRFORMAT;

typedef
	WinApi_EMRFRAMERGN *WinApi_PtrEMRFRAMERGN;

typedef
	WinApi_EMRGDICOMMENT *WinApi_PtrEMRGDICOMMENT;

typedef
	WinApi_EMRGLSBOUNDEDRECORD *WinApi_PtrEMRGLSBOUNDEDRECORD;

typedef
	WinApi_EMRGLSRECORD *WinApi_PtrEMRGLSRECORD;

typedef
	WinApi_EMRINVERTRGN *WinApi_PtrEMRINVERTRGN;

typedef
	WinApi_EMRLINETO *WinApi_PtrEMRLINETO;

typedef
	WinApi_EMRMASKBLT *WinApi_PtrEMRMASKBLT;

typedef
	WinApi_EMRMODIFYWORLDTRANSFORM *WinApi_PtrEMRMODIFYWORLDTRANSFORM;

typedef
	WinApi_EMROFFSETCLIPRGN *WinApi_PtrEMROFFSETCLIPRGN;

typedef
	WinApi_EMRPIXELFORMAT *WinApi_PtrEMRPIXELFORMAT;

typedef
	WinApi_EMRPLGBLT *WinApi_PtrEMRPLGBLT;

typedef
	WinApi_EMRPOLYLINE *WinApi_PtrEMRPOLYLINE;

typedef
	WinApi_EMRPOLYLINE16 *WinApi_PtrEMRPOLYLINE16;

typedef
	WinApi_EMRPOLYDRAW *WinApi_PtrEMRPOLYDRAW;

typedef
	WinApi_EMRPOLYDRAW16 *WinApi_PtrEMRPOLYDRAW16;

typedef
	WinApi_EMRPOLYPOLYLINE *WinApi_PtrEMRPOLYPOLYLINE;

typedef
	WinApi_EMRPOLYPOLYLINE16 *WinApi_PtrEMRPOLYPOLYLINE16;

typedef
	WinApi_EMRPOLYTEXTOUTA *WinApi_PtrEMRPOLYTEXTOUTA;

typedef
	WinApi_EMRRESIZEPALETTE *WinApi_PtrEMRRESIZEPALETTE;

typedef
	WinApi_EMRRESTOREDC *WinApi_PtrEMRRESTOREDC;

typedef
	WinApi_EMRROUNDRECT *WinApi_PtrEMRROUNDRECT;

typedef
	WinApi_EMRSCALEVIEWPORTEXTEX *WinApi_PtrEMRSCALEVIEWPORTEXTEX;

typedef
	WinApi_EMRSELECTCLIPPATH *WinApi_PtrEMRSELECTCLIPPATH;

typedef
	WinApi_EMRSELECTPALETTE *WinApi_PtrEMRSELECTPALETTE;

typedef
	WinApi_EMRSETARCDIRECTION *WinApi_PtrEMRSETARCDIRECTION;

typedef
	WinApi_EMRSETBKCOLOR *WinApi_PtrEMRSETBKCOLOR;

typedef
	WinApi_EMRSETVIEWPORTORGEX *WinApi_PtrEMRSETVIEWPORTORGEX;

typedef
	WinApi_EMRSETCOLORADJUSTMENT *WinApi_PtrEMRSETCOLORADJUSTMENT;

typedef
	WinApi_EMRSETDIBITSTODEVICE *WinApi_PtrEMRSETDIBITSTODEVICE;

typedef
	WinApi_EMRSETMAPPERFLAGS *WinApi_PtrEMRSETMAPPERFLAGS;

typedef
	WinApi_EMRSETMITERLIMIT *WinApi_PtrEMRSETMITERLIMIT;

typedef
	WinApi_EMRSETPALETTEENTRIES *WinApi_PtrEMRSETPALETTEENTRIES;

typedef
	WinApi_EMRSETPIXELV *WinApi_PtrEMRSETPIXELV;

typedef
	WinApi_EMRSETVIEWPORTEXTEX *WinApi_PtrEMRSETVIEWPORTEXTEX;

typedef
	WinApi_EMRSETWORLDTRANSFORM *WinApi_PtrEMRSETWORLDTRANSFORM;

typedef
	WinApi_EMRSTRETCHBLT *WinApi_PtrEMRSTRETCHBLT;

typedef
	WinApi_EMRSTRETCHDIBITS *WinApi_PtrEMRSTRETCHDIBITS;

typedef
	WinApi_EMRTEXT *WinApi_PtrEMRTEXT;

typedef
	WinApi_ENHMETAHEADER *WinApi_PtrENHMETAHEADER;

typedef
	WinApi_ENHMETARECORD *WinApi_PtrENHMETARECORD;

typedef
	WinApi_ENUMLOGFONTA *WinApi_PtrENUMLOGFONTA;

typedef
	WinApi_ENUMLOGFONTEXA *WinApi_PtrENUMLOGFONTEXA;

typedef
	WinApi_ENUMLOGFONTEXW *WinApi_PtrENUMLOGFONTEXW;

typedef
	WinApi_ENUMLOGFONTW *WinApi_PtrENUMLOGFONTW;

typedef
	WinApi_ENUM_SERVICE_STATUSA *WinApi_PtrENUM_SERVICE_STATUSA;

typedef
	WinApi_ENUM_SERVICE_STATUSW *WinApi_PtrENUM_SERVICE_STATUSW;

typedef
	WinApi_EVENTLOGRECORD *WinApi_PtrEVENTLOGRECORD;

typedef
	WinApi_EVENTMSG *WinApi_PtrEVENTMSG;

typedef
	WinApi_EXCEPTION_DEBUG_INFO *WinApi_PtrEXCEPTION_DEBUG_INFO;

typedef
	WinApi_EXCEPTION_POINTERS *WinApi_PtrEXCEPTION_POINTERS;

typedef
	WinApi_EXIT_PROCESS_DEBUG_INFO *WinApi_PtrEXIT_PROCESS_DEBUG_INFO;

typedef
	WinApi_EXIT_THREAD_DEBUG_INFO *WinApi_PtrEXIT_THREAD_DEBUG_INFO;

typedef
	WinApi_EXTLOGFONTA *WinApi_PtrEXTLOGFONTA;

typedef
	WinApi_EXTLOGFONTW *WinApi_PtrEXTLOGFONTW;

typedef
	WinApi_EXTLOGPEN *WinApi_PtrEXTLOGPEN;

typedef
	WinApi_FILETIME *WinApi_PtrFILETIME;

typedef
	WinApi_FILE_NOTIFY_INFORMATION *WinApi_PtrFILE_NOTIFY_INFORMATION;

typedef
	WinApi_FILTERKEYS *WinApi_PtrFILTERKEYS;

typedef
	WinApi_FLOATING_SAVE_AREA *WinApi_PtrFLOATING_SAVE_AREA;

typedef
	WinApi_FOCUS_EVENT_RECORD *WinApi_PtrFOCUS_EVENT_RECORD;

typedef
	WinApi_FONTSIGNATURE *WinApi_PtrFONTSIGNATURE;

typedef
	WinApi_FORM_INFO_1A *WinApi_PtrFORM_INFO_1A;

typedef
	WinApi_FORM_INFO_1W *WinApi_PtrFORM_INFO_1W;

typedef
	WinApi_FPO_DATA *WinApi_PtrFPO_DATA;

typedef
	WinApi_GCP_RESULTSA *WinApi_PtrGCP_RESULTSA;

typedef
	WinApi_GCP_RESULTSW *WinApi_PtrGCP_RESULTSW;

typedef
	WinApi_GENERIC_MAPPING *WinApi_PtrGENERIC_MAPPING;

typedef
	WinApi_GLYPHMETRICS *WinApi_PtrGLYPHMETRICS;

typedef
	WinApi_GLYPHMETRICSFLOAT *WinApi_PtrGLYPHMETRICSFLOAT;

typedef
	WinApi_HANDLETABLE *WinApi_PtrHANDLETABLE;

typedef
	WinApi_HARDWAREHOOKSTRUCT *WinApi_PtrHARDWAREHOOKSTRUCT;

typedef
	WinApi_HELPINFO *WinApi_PtrHELPINFO;

typedef
	WinApi_HELPWININFOA *WinApi_PtrHELPWININFOA;

typedef
	WinApi_HELPWININFOW *WinApi_PtrHELPWININFOW;

typedef
	WinApi_HIGHCONTRASTA *WinApi_PtrHIGHCONTRASTA;

typedef
	WinApi_HIGHCONTRASTW *WinApi_PtrHIGHCONTRASTW;

typedef
	WinApi_HSZPAIR *WinApi_PtrHSZPAIR;

typedef
	WinApi_HW_PROFILE_INFOA *WinApi_PtrHW_PROFILE_INFOA;

typedef
	WinApi_HW_PROFILE_INFOW *WinApi_PtrHW_PROFILE_INFOW;

typedef
	WinApi_ICONINFO *WinApi_PtrICONINFO;

typedef
	WinApi_ICONMETRICSA *WinApi_PtrICONMETRICSA;

typedef
	WinApi_ICONMETRICSW *WinApi_PtrICONMETRICSW;

typedef
	WinApi_IMAGE_ARCHIVE_MEMBER_HEADER *WinApi_PtrIMAGE_ARCHIVE_MEMBER_HEADER;

typedef
	WinApi_IMAGE_AUX_SYMBOL *WinApi_PtrIMAGE_AUX_SYMBOL;

typedef
	WinApi_IMAGE_BASE_RELOCATION *WinApi_PtrIMAGE_BASE_RELOCATION;

typedef
	WinApi_IMAGE_BOUND_FORWARDER_REF *WinApi_PtrIMAGE_BOUND_FORWARDER_REF;

typedef
	WinApi_IMAGE_BOUND_IMPORT_DESCRIPTOR *WinApi_PtrIMAGE_BOUND_IMPORT_DESCRIPTOR;

typedef
	WinApi_IMAGE_COFF_SYMBOLS_HEADER *WinApi_PtrIMAGE_COFF_SYMBOLS_HEADER;

typedef
	WinApi_IMAGE_DATA_DIRECTORY *WinApi_PtrIMAGE_DATA_DIRECTORY;

typedef
	WinApi_IMAGE_DEBUG_DIRECTORY *WinApi_PtrIMAGE_DEBUG_DIRECTORY;

typedef
	WinApi_IMAGE_DEBUG_MISC *WinApi_PtrIMAGE_DEBUG_MISC;

typedef
	WinApi_IMAGE_DOS_HEADER *WinApi_PtrIMAGE_DOS_HEADER;

typedef
	WinApi_IMAGE_EXPORT_DIRECTORY *WinApi_PtrIMAGE_EXPORT_DIRECTORY;

typedef
	WinApi_IMAGE_FILE_HEADER *WinApi_PtrIMAGE_FILE_HEADER;

typedef
	WinApi_IMAGE_FUNCTION_ENTRY *WinApi_PtrIMAGE_FUNCTION_ENTRY;

typedef
	WinApi_IMAGE_IMPORT_DESCRIPTOR *WinApi_PtrIMAGE_IMPORT_DESCRIPTOR;

typedef
	WinApi_IMAGE_LINENUMBER *WinApi_PtrIMAGE_LINENUMBER;

typedef
	WinApi_IMAGE_LOAD_CONFIG_DIRECTORY *WinApi_PtrIMAGE_LOAD_CONFIG_DIRECTORY;

typedef
	WinApi_IMAGE_NT_HEADERS *WinApi_PtrIMAGE_NT_HEADERS;

typedef
	WinApi_IMAGE_OPTIONAL_HEADER *WinApi_PtrIMAGE_OPTIONAL_HEADER;

typedef
	WinApi_IMAGE_OS2_HEADER *WinApi_PtrIMAGE_OS2_HEADER;

typedef
	WinApi_IMAGE_RELOCATION *WinApi_PtrIMAGE_RELOCATION;

typedef
	WinApi_IMAGE_RESOURCE_DATA_ENTRY *WinApi_PtrIMAGE_RESOURCE_DATA_ENTRY;

typedef
	WinApi_IMAGE_RESOURCE_DIRECTORY *WinApi_PtrIMAGE_RESOURCE_DIRECTORY;

typedef
	WinApi_IMAGE_RESOURCE_DIRECTORY_ENTRY *WinApi_PtrIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef
	WinApi_IMAGE_RESOURCE_DIRECTORY_STRING *WinApi_PtrIMAGE_RESOURCE_DIRECTORY_STRING;

typedef
	WinApi_IMAGE_RESOURCE_DIR_STRING_U *WinApi_PtrIMAGE_RESOURCE_DIR_STRING_U;

typedef
	WinApi_IMAGE_ROM_HEADERS *WinApi_PtrIMAGE_ROM_HEADERS;

typedef
	WinApi_IMAGE_ROM_OPTIONAL_HEADER *WinApi_PtrIMAGE_ROM_OPTIONAL_HEADER;

typedef
	WinApi_IMAGE_RUNTIME_FUNCTION_ENTRY *WinApi_PtrIMAGE_RUNTIME_FUNCTION_ENTRY;

typedef
	WinApi_IMAGE_SECTION_HEADER *WinApi_PtrIMAGE_SECTION_HEADER;

typedef
	WinApi_IMAGE_SEPARATE_DEBUG_HEADER *WinApi_PtrIMAGE_SEPARATE_DEBUG_HEADER;

typedef
	WinApi_IMAGE_SYMBOL *WinApi_PtrIMAGE_SYMBOL;

typedef
	WinApi_IMAGE_TLS_DIRECTORY *WinApi_PtrIMAGE_TLS_DIRECTORY;

typedef
	WinApi_IMAGE_VXD_HEADER *WinApi_PtrIMAGE_VXD_HEADER;

typedef
	WinApi_INPUT_RECORD *WinApi_PtrINPUT_RECORD;

typedef
	WinApi_JOB_INFO_1A *WinApi_PtrJOB_INFO_1A;

typedef
	WinApi_JOB_INFO_1W *WinApi_PtrJOB_INFO_1W;

typedef
	WinApi_JOB_INFO_2A *WinApi_PtrJOB_INFO_2A;

typedef
	WinApi_JOB_INFO_2W *WinApi_PtrJOB_INFO_2W;

typedef
	WinApi_KERNINGPAIR *WinApi_PtrKERNINGPAIR;

typedef
	WinApi_KEY_EVENT_RECORD *WinApi_PtrKEY_EVENT_RECORD;

typedef
	WinApi_LAYERPLANEDESCRIPTOR *WinApi_PtrLAYERPLANEDESCRIPTOR;

typedef
	WinApi_LDT_ENTRY *WinApi_PtrLDT_ENTRY;

typedef
	WinApi_LOAD_DLL_DEBUG_INFO *WinApi_PtrLOAD_DLL_DEBUG_INFO;

typedef
	WinApi_LOCALESIGNATURE *WinApi_PtrLOCALESIGNATURE;

typedef
	WinApi_LOGBRUSH *WinApi_PtrLOGBRUSH;

typedef
	WinApi_LOGCOLORSPACEA *WinApi_PtrLOGCOLORSPACEA;

typedef
	WinApi_LOGCOLORSPACEW *WinApi_PtrLOGCOLORSPACEW;

typedef
	WinApi_LOGFONTA *WinApi_PtrLOGFONTA;

typedef
	WinApi_LOGFONTW *WinApi_PtrLOGFONTW;

typedef
	WinApi_LOGPALETTE *WinApi_PtrLOGPALETTE;

typedef
	WinApi_LOGPEN *WinApi_PtrLOGPEN;

typedef
	WinApi_LUID_AND_ATTRIBUTES *WinApi_PtrLUID_AND_ATTRIBUTES;

typedef
	WinApi_LUID_AND_ATTRIBUTES_ARRAY *WinApi_PtrLUID_AND_ATTRIBUTES_ARRAY;

typedef
	WinApi_MAT2 *WinApi_PtrMAT2;

typedef
	WinApi_MDICREATESTRUCTA *WinApi_PtrMDICREATESTRUCTA;

typedef
	WinApi_MDICREATESTRUCTW *WinApi_PtrMDICREATESTRUCTW;

typedef
	WinApi_MDINEXTMENU *WinApi_PtrMDINEXTMENU;

typedef
	WinApi_MEASUREITEMSTRUCT *WinApi_PtrMEASUREITEMSTRUCT;

typedef
	WinApi_MEMORYSTATUS *WinApi_PtrMEMORYSTATUS;

typedef
	WinApi_MEMORY_BASIC_INFORMATION *WinApi_PtrMEMORY_BASIC_INFORMATION;

typedef
	WinApi_MENUITEMINFOA *WinApi_PtrMENUITEMINFOA;

typedef
	WinApi_MENUITEMINFOW *WinApi_PtrMENUITEMINFOW;

typedef
	WinApi_MENUITEMTEMPLATE *WinApi_PtrMENUITEMTEMPLATE;

typedef
	WinApi_MENUITEMTEMPLATEHEADER *WinApi_PtrMENUITEMTEMPLATEHEADER;

typedef
	WinApi_MENUTEMPLATE *WinApi_PtrMENUTEMPLATE;

typedef
	WinApi_MENUTEMPLATEA *WinApi_PtrMENUTEMPLATEA;

typedef
	WinApi_MENUTEMPLATEW *WinApi_PtrMENUTEMPLATEW;

typedef
	WinApi_MENU_EVENT_RECORD *WinApi_PtrMENU_EVENT_RECORD;

typedef
	WinApi_MESSAGE_RESOURCE_BLOCK *WinApi_PtrMESSAGE_RESOURCE_BLOCK;

typedef
	WinApi_MESSAGE_RESOURCE_DATA *WinApi_PtrMESSAGE_RESOURCE_DATA;

typedef
	WinApi_MESSAGE_RESOURCE_ENTRY *WinApi_PtrMESSAGE_RESOURCE_ENTRY;

typedef
	WinApi_METAFILEPICT *WinApi_PtrMETAFILEPICT;

typedef
	WinApi_METAHEADER *WinApi_PtrMETAHEADER;

typedef
	WinApi_METARECORD *WinApi_PtrMETARECORD;

typedef
	WinApi_MINIMIZEDMETRICS *WinApi_PtrMINIMIZEDMETRICS;

typedef
	WinApi_MINMAXINFO *WinApi_PtrMINMAXINFO;

typedef
	WinApi_MODEMDEVCAPS *WinApi_PtrMODEMDEVCAPS;

typedef
	WinApi_MODEMSETTINGS *WinApi_PtrMODEMSETTINGS;

typedef
	WinApi_MONCBSTRUCT *WinApi_PtrMONCBSTRUCT;

typedef
	WinApi_MONCONVSTRUCT *WinApi_PtrMONCONVSTRUCT;

typedef
	WinApi_MONERRSTRUCT *WinApi_PtrMONERRSTRUCT;

typedef
	WinApi_MONHSZSTRUCTA *WinApi_PtrMONHSZSTRUCTA;

typedef
	WinApi_MONHSZSTRUCTW *WinApi_PtrMONHSZSTRUCTW;

typedef
	WinApi_MONITOR_INFO_1A *WinApi_PtrMONITOR_INFO_1A;

typedef
	WinApi_MONITOR_INFO_1W *WinApi_PtrMONITOR_INFO_1W;

typedef
	WinApi_MONITOR_INFO_2A *WinApi_PtrMONITOR_INFO_2A;

typedef
	WinApi_MONITOR_INFO_2W *WinApi_PtrMONITOR_INFO_2W;

typedef
	WinApi_MONLINKSTRUCT *WinApi_PtrMONLINKSTRUCT;

typedef
	WinApi_MONMSGSTRUCT *WinApi_PtrMONMSGSTRUCT;

typedef
	WinApi_MOUSEHOOKSTRUCT *WinApi_PtrMOUSEHOOKSTRUCT;

typedef
	WinApi_MOUSEKEYS *WinApi_PtrMOUSEKEYS;

typedef
	WinApi_MOUSE_EVENT_RECORD *WinApi_PtrMOUSE_EVENT_RECORD;

typedef
	WinApi_MSG *WinApi_PtrMSG;

typedef
	WinApi_MSGBOXPARAMSA *WinApi_PtrMSGBOXPARAMSA;

typedef
	WinApi_MSGBOXPARAMSW *WinApi_PtrMSGBOXPARAMSW;

typedef
	WinApi_MULTIKEYHELPA *WinApi_PtrMULTIKEYHELPA;

typedef
	WinApi_MULTIKEYHELPW *WinApi_PtrMULTIKEYHELPW;

typedef
	WinApi_NCCALCSIZE_PARAMS *WinApi_PtrNCCALCSIZE_PARAMS;

typedef
	WinApi_NEWTEXTMETRICA *WinApi_PtrNEWTEXTMETRICA;

typedef
	WinApi_NEWTEXTMETRICW *WinApi_PtrNEWTEXTMETRICW;

typedef
	WinApi_NMHDR *WinApi_PtrNMHDR;

typedef
	WinApi_NONCLIENTMETRICSA *WinApi_PtrNONCLIENTMETRICSA;

typedef
	WinApi_NONCLIENTMETRICSW *WinApi_PtrNONCLIENTMETRICSW;

typedef
	WinApi_NOTIFYICONDATAA *WinApi_PtrNOTIFYICONDATAA;

typedef
	WinApi_NOTIFYICONDATAW *WinApi_PtrNOTIFYICONDATAW;

typedef
	WinApi_NUMBERFMTA *WinApi_PtrNUMBERFMTA;

typedef
	WinApi_NUMBERFMTW *WinApi_PtrNUMBERFMTW;

typedef
	WinApi_OFSTRUCT *WinApi_PtrOFSTRUCT;

typedef
	WinApi_OSVERSIONINFOA *WinApi_PtrOSVERSIONINFOA;

typedef
	WinApi_OSVERSIONINFOW *WinApi_PtrOSVERSIONINFOW;

typedef
	WinApi_OUTLINETEXTMETRICA *WinApi_PtrOUTLINETEXTMETRICA;

typedef
	WinApi_OUTLINETEXTMETRICW *WinApi_PtrOUTLINETEXTMETRICW;

typedef
	WinApi_OUTPUT_DEBUG_STRING_INFO *WinApi_PtrOUTPUT_DEBUG_STRING_INFO;

typedef
	WinApi_OVERLAPPED *WinApi_PtrOVERLAPPED;

typedef
	WinApi_PAINTSTRUCT *WinApi_PtrPAINTSTRUCT;

typedef
	WinApi_PALETTEENTRY *WinApi_PtrPALETTEENTRY;

typedef
	WinApi_PANOSE *WinApi_PtrPANOSE;

typedef
	WinApi_PELARRAY *WinApi_PtrPELARRAY;

typedef
	WinApi_PIXELFORMATDESCRIPTOR *WinApi_PtrPIXELFORMATDESCRIPTOR;

typedef
	WinApi_POINT *WinApi_PtrPOINT;

typedef
	WinApi_POINTFLOAT *WinApi_PtrPOINTFLOAT;

typedef
	WinApi_POINTFX *WinApi_PtrPOINTFX;

typedef
	WinApi_POINTS *WinApi_PtrPOINTS;

typedef
	WinApi_POLYTEXTA *WinApi_PtrPOLYTEXTA;

typedef
	WinApi_POLYTEXTW *WinApi_PtrPOLYTEXTW;

typedef
	WinApi_PORT_INFO_1A *WinApi_PtrPORT_INFO_1A;

typedef
	WinApi_PORT_INFO_1W *WinApi_PtrPORT_INFO_1W;

typedef
	WinApi_PORT_INFO_2A *WinApi_PtrPORT_INFO_2A;

typedef
	WinApi_PORT_INFO_2W *WinApi_PtrPORT_INFO_2W;

typedef
	WinApi_PRINTER_DEFAULTSA *WinApi_PtrPRINTER_DEFAULTSA;

typedef
	WinApi_PRINTER_DEFAULTSW *WinApi_PtrPRINTER_DEFAULTSW;

typedef
	WinApi_PRINTER_INFO_1A *WinApi_PtrPRINTER_INFO_1A;

typedef
	WinApi_PRINTER_INFO_1W *WinApi_PtrPRINTER_INFO_1W;

typedef
	WinApi_PRINTER_INFO_2A *WinApi_PtrPRINTER_INFO_2A;

typedef
	WinApi_PRINTER_INFO_2W *WinApi_PtrPRINTER_INFO_2W;

typedef
	WinApi_PRINTER_INFO_3 *WinApi_PtrPRINTER_INFO_3;

typedef
	WinApi_PRINTER_INFO_4A *WinApi_PtrPRINTER_INFO_4A;

typedef
	WinApi_PRINTER_INFO_4W *WinApi_PtrPRINTER_INFO_4W;

typedef
	WinApi_PRINTER_INFO_5A *WinApi_PtrPRINTER_INFO_5A;

typedef
	WinApi_PRINTER_INFO_5W *WinApi_PtrPRINTER_INFO_5W;

typedef
	WinApi_PRINTER_INFO_6 *WinApi_PtrPRINTER_INFO_6;

typedef
	WinApi_PRINTER_NOTIFY_INFO *WinApi_PtrPRINTER_NOTIFY_INFO;

typedef
	WinApi_PRINTER_NOTIFY_INFO_DATA *WinApi_PtrPRINTER_NOTIFY_INFO_DATA;

typedef
	WinApi_PRINTER_NOTIFY_OPTIONS *WinApi_PtrPRINTER_NOTIFY_OPTIONS;

typedef
	WinApi_PRINTPROCESSOR_INFO_1A *WinApi_PtrPRINTPROCESSOR_INFO_1A;

typedef
	WinApi_PRINTPROCESSOR_INFO_1W *WinApi_PtrPRINTPROCESSOR_INFO_1W;

typedef
	WinApi_PRIVILEGE_SET *WinApi_PtrPRIVILEGE_SET;

typedef
	WinApi_PROCESS_HEAP_ENTRY *WinApi_PtrPROCESS_HEAP_ENTRY;

typedef
	WinApi_PROCESS_INFORMATION *WinApi_PtrPROCESS_INFORMATION;

typedef
	WinApi_PROPSHEETHEADERA *WinApi_PtrPROPSHEETHEADERA;

typedef
	WinApi_PROPSHEETHEADERW *WinApi_PtrPROPSHEETHEADERW;

typedef
	WinApi_PROVIDOR_INFO_1A *WinApi_PtrPROVIDOR_INFO_1A;

typedef
	WinApi_PROVIDOR_INFO_1W *WinApi_PtrPROVIDOR_INFO_1W;

typedef
	WinApi_PSHNOTIFY *WinApi_PtrPSHNOTIFY;

typedef
	WinApi_PVALUEA *WinApi_PtrPVALUEA;

typedef
	WinApi_PVALUEW *WinApi_PtrPVALUEW;

typedef
	struct WinApi_QUERY_SERVICE_CONFIGA *WinApi_PtrQUERY_SERVICE_CONFIGA;

typedef
	struct WinApi_QUERY_SERVICE_CONFIGW *WinApi_PtrQUERY_SERVICE_CONFIGW;

typedef
	struct WinApi_QUERY_SERVICE_LOCK_STATUSA *WinApi_PtrQUERY_SERVICE_LOCK_STATUSA;

typedef
	struct WinApi_QUERY_SERVICE_LOCK_STATUSW *WinApi_PtrQUERY_SERVICE_LOCK_STATUSW;

typedef
	struct WinApi_QUOTA_LIMITS *WinApi_PtrQUOTA_LIMITS;

typedef
	struct WinApi_RASTERIZER_STATUS *WinApi_PtrRASTERIZER_STATUS;

typedef
	WinApi_RECT *WinApi_PtrRECT;

typedef
	struct WinApi_REG_PROVIDER *WinApi_PtrREG_PROVIDER;

typedef
	WinApi_RGBQUAD *WinApi_PtrRGBQUAD;

typedef
	struct WinApi_RGNDATA *WinApi_PtrRGNDATA;

typedef
	struct WinApi_RGNDATAHEADER *WinApi_PtrRGNDATAHEADER;

typedef
	WinApi_RIP_INFO *WinApi_PtrRIP_INFO;

typedef
	struct WinApi_SCROLLINFO *WinApi_PtrSCROLLINFO;

typedef
	struct WinApi_SECURITY_ATTRIBUTES *WinApi_PtrSECURITY_ATTRIBUTES;

typedef
	struct WinApi_SECURITY_DESCRIPTOR *WinApi_PtrSECURITY_DESCRIPTOR;

typedef
	WinApi_SECURITY_QUALITY_OF_SERVICE *WinApi_PtrSECURITY_QUALITY_OF_SERVICE;

typedef
	struct WinApi_SERIALKEYSA *WinApi_PtrSERIALKEYSA;

typedef
	struct WinApi_SERIALKEYSW *WinApi_PtrSERIALKEYSW;

typedef
	WinApi_SERVICE_STATUS *WinApi_PtrSERVICE_STATUS;

typedef
	struct WinApi_SERVICE_TABLE_ENTRYA *WinApi_PtrSERVICE_TABLE_ENTRYA;

typedef
	struct WinApi_SERVICE_TABLE_ENTRYW *WinApi_PtrSERVICE_TABLE_ENTRYW;

typedef
	struct WinApi_SE_IMPERSONATION_STATE *WinApi_PtrSE_IMPERSONATION_STATE;

typedef
	struct WinApi_SHELLEXECUTEINFOA *WinApi_PtrSHELLEXECUTEINFOA;

typedef
	struct WinApi_SHELLEXECUTEINFOW *WinApi_PtrSHELLEXECUTEINFOW;

typedef
	struct WinApi_SHFILEINFOA *WinApi_PtrSHFILEINFOA;

typedef
	struct WinApi_SHFILEINFOW *WinApi_PtrSHFILEINFOW;

typedef
	struct WinApi_SHFILEOPSTRUCTA *WinApi_PtrSHFILEOPSTRUCTA;

typedef
	struct WinApi_SHFILEOPSTRUCTW *WinApi_PtrSHFILEOPSTRUCTW;

typedef
	struct WinApi_SHNAMEMAPPINGA *WinApi_PtrSHNAMEMAPPINGA;

typedef
	struct WinApi_SHNAMEMAPPINGW *WinApi_PtrSHNAMEMAPPINGW;

typedef
	struct WinApi_SID *WinApi_PtrSID;

typedef
	struct WinApi_SID_AND_ATTRIBUTES *WinApi_PtrSID_AND_ATTRIBUTES;

typedef
	struct WinApi_SID_AND_ATTRIBUTES {
		INTEGER Sid;
		SET Attributes;
	} WinApi_SID_AND_ATTRIBUTES;

typedef
	WinApi_SID_AND_ATTRIBUTES WinApi_SID_AND_ATTRIBUTES_ARRAY[1];

typedef
	WinApi_SID_AND_ATTRIBUTES_ARRAY *WinApi_PtrSID_AND_ATTRIBUTES_ARRAY;

typedef
	struct WinApi_SID_IDENTIFIER_AUTHORITY *WinApi_PtrSID_IDENTIFIER_AUTHORITY;

typedef
	struct WinApi_SINGLE_LIST_ENTRY *WinApi_PtrSINGLE_LIST_ENTRY;

typedef
	WinApi_SIZE *WinApi_PtrSIZE;

typedef
	WinApi_SMALL_RECT *WinApi_PtrSMALL_RECT;

typedef
	struct WinApi_SOUNDSENTRYA *WinApi_PtrSOUNDSENTRYA;

typedef
	struct WinApi_SOUNDSENTRYW *WinApi_PtrSOUNDSENTRYW;

typedef
	struct WinApi_STARTUPINFOA *WinApi_PtrSTARTUPINFOA;

typedef
	struct WinApi_STARTUPINFOW *WinApi_PtrSTARTUPINFOW;

typedef
	struct WinApi_STICKYKEYS *WinApi_PtrSTICKYKEYS;

typedef
	struct WinApi_STYLESTRUCT *WinApi_PtrSTYLESTRUCT;

typedef
	WinApi_SYSTEMTIME *WinApi_PtrSYSTEMTIME;

typedef
	struct WinApi_SYSTEM_ALARM_ACE *WinApi_PtrSYSTEM_ALARM_ACE;

typedef
	struct WinApi_SYSTEM_AUDIT_ACE *WinApi_PtrSYSTEM_AUDIT_ACE;

typedef
	struct WinApi_SYSTEM_INFO *WinApi_PtrSYSTEM_INFO;

typedef
	struct WinApi_SYSTEM_POWER_STATUS *WinApi_PtrSYSTEM_POWER_STATUS;

typedef
	struct WinApi_TAPE_CREATE_PARTITION *WinApi_PtrTAPE_CREATE_PARTITION;

typedef
	struct WinApi_TAPE_ERASE *WinApi_PtrTAPE_ERASE;

typedef
	struct WinApi_TAPE_GET_DRIVE_PARAMETERS *WinApi_PtrTAPE_GET_DRIVE_PARAMETERS;

typedef
	struct WinApi_TAPE_GET_MEDIA_PARAMETERS *WinApi_PtrTAPE_GET_MEDIA_PARAMETERS;

typedef
	struct WinApi_TAPE_GET_POSITION *WinApi_PtrTAPE_GET_POSITION;

typedef
	struct WinApi_TAPE_PREPARE *WinApi_PtrTAPE_PREPARE;

typedef
	struct WinApi_TAPE_SET_DRIVE_PARAMETERS *WinApi_PtrTAPE_SET_DRIVE_PARAMETERS;

typedef
	struct WinApi_TAPE_SET_MEDIA_PARAMETERS *WinApi_PtrTAPE_SET_MEDIA_PARAMETERS;

typedef
	struct WinApi_TAPE_SET_POSITION *WinApi_PtrTAPE_SET_POSITION;

typedef
	struct WinApi_TAPE_WRITE_MARKS *WinApi_PtrTAPE_WRITE_MARKS;

typedef
	WinApi_TEXTMETRICA *WinApi_PtrTEXTMETRICA;

typedef
	WinApi_TEXTMETRICW *WinApi_PtrTEXTMETRICW;

typedef
	struct WinApi_TIME_ZONE_INFORMATION *WinApi_PtrTIME_ZONE_INFORMATION;

typedef
	struct WinApi_TOGGLEKEYS *WinApi_PtrTOGGLEKEYS;

typedef
	struct WinApi_TOKEN_CONTROL *WinApi_PtrTOKEN_CONTROL;

typedef
	struct WinApi_TOKEN_DEFAULT_DACL *WinApi_PtrTOKEN_DEFAULT_DACL;

typedef
	struct WinApi_TOKEN_GROUPS *WinApi_PtrTOKEN_GROUPS;

typedef
	struct WinApi_TOKEN_OWNER *WinApi_PtrTOKEN_OWNER;

typedef
	struct WinApi_TOKEN_PRIMARY_GROUP *WinApi_PtrTOKEN_PRIMARY_GROUP;

typedef
	struct WinApi_TOKEN_PRIVILEGES *WinApi_PtrTOKEN_PRIVILEGES;

typedef
	struct WinApi_TOKEN_SOURCE *WinApi_PtrTOKEN_SOURCE;

typedef
	struct WinApi_TOKEN_STATISTICS *WinApi_PtrTOKEN_STATISTICS;

typedef
	struct WinApi_TOKEN_USER *WinApi_PtrTOKEN_USER;

typedef
	struct WinApi_TPMPARAMS *WinApi_PtrTPMPARAMS;

typedef
	struct WinApi_TTPOLYCURVE *WinApi_PtrTTPOLYCURVE;

typedef
	struct WinApi_TTPOLYGONHEADER *WinApi_PtrTTPOLYGONHEADER;

typedef
	WinApi_UNLOAD_DLL_DEBUG_INFO *WinApi_PtrUNLOAD_DLL_DEBUG_INFO;

typedef
	struct WinApi_USEROBJECTFLAGS *WinApi_PtrUSEROBJECTFLAGS;

typedef
	struct WinApi_VALENTA *WinApi_PtrVALENTA;

typedef
	struct WinApi_VALENTW *WinApi_PtrVALENTW;

typedef
	struct WinApi_WIN32_FILE_ATTRIBUTE_DATA *WinApi_PtrWIN32_FILE_ATTRIBUTE_DATA;

typedef
	struct WinApi_WIN32_FIND_DATAA *WinApi_PtrWIN32_FIND_DATAA;

typedef
	struct WinApi_WIN32_FIND_DATAW *WinApi_PtrWIN32_FIND_DATAW;

typedef
	struct WinApi_WIN32_STREAM_ID *WinApi_PtrWIN32_STREAM_ID;

typedef
	struct WinApi_WINDOWPLACEMENT *WinApi_PtrWINDOWPLACEMENT;

typedef
	WinApi_WINDOW_BUFFER_SIZE_RECORD *WinApi_PtrWINDOW_BUFFER_SIZE_RECORD;

typedef
	struct WinApi_WIN_CERTIFICATE *WinApi_PtrWIN_CERTIFICATE;

typedef
	struct WinApi_WIN_SPUB_TRUSTEDPUB_DATA *WinApi_PtrWIN_SPUB_TRUSTEDPUB_DATA;

typedef
	struct WinApi_WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT *WinApi_PtrWIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJE;

typedef
	struct WinApi_WIN_TRUST_ACTDATA_SUBJECT_ONLY *WinApi_PtrWIN_TRUST_ACTDATA_SUBJECT_ONLY;

typedef
	struct WinApi_WIN_TRUST_SUBJECT_FILE *WinApi_PtrWIN_TRUST_SUBJECT_FILE;

typedef
	struct WinApi_WNDCLASSA *WinApi_PtrWNDCLASSA;

typedef
	struct WinApi_WNDCLASSEXA *WinApi_PtrWNDCLASSEXA;

typedef
	struct WinApi_WNDCLASSEXW *WinApi_PtrWNDCLASSEXW;

typedef
	struct WinApi_WNDCLASSW *WinApi_PtrWNDCLASSW;

typedef
	WinApi_XFORM *WinApi_PtrXFORM;

typedef
	struct WinApi_val_context *WinApi_Ptrval_context;

typedef
	struct WinApi_val_context {
		INTEGER valuelen, value_context, val_buff_ptr;
	} WinApi_val_context;

typedef
	INTEGER (*WinApi_QUERYHANDLER)(INTEGER, WinApi_val_context*, LONGINT *, INTEGER, INTEGER, INTEGER*, INTEGER);

typedef
	struct WinApi_QUERY_SERVICE_CONFIGA {
		SET dwServiceType;
		INTEGER dwStartType, dwErrorControl;
		WinApi_PtrSTR lpBinaryPathName, lpLoadOrderGroup;
		INTEGER dwTagId;
		WinApi_PtrSTR lpDependencies, lpServiceStartName, lpDisplayName;
	} WinApi_QUERY_SERVICE_CONFIGA;

typedef
	struct WinApi_QUERY_SERVICE_CONFIGW {
		SET dwServiceType;
		INTEGER dwStartType, dwErrorControl;
		WinApi_PtrWSTR lpBinaryPathName, lpLoadOrderGroup;
		INTEGER dwTagId;
		WinApi_PtrWSTR lpDependencies, lpServiceStartName, lpDisplayName;
	} WinApi_QUERY_SERVICE_CONFIGW;

typedef
	struct WinApi_QUERY_SERVICE_LOCK_STATUSA {
		INTEGER fIsLocked;
		WinApi_PtrSTR lpLockOwner;
		INTEGER dwLockDuration;
	} WinApi_QUERY_SERVICE_LOCK_STATUSA;

typedef
	struct WinApi_QUERY_SERVICE_LOCK_STATUSW {
		INTEGER fIsLocked;
		WinApi_PtrWSTR lpLockOwner;
		INTEGER dwLockDuration;
	} WinApi_QUERY_SERVICE_LOCK_STATUSW;

typedef
	struct WinApi_QUOTA_LIMITS {
		INTEGER PagedPoolLimit, NonPagedPoolLimit, MinimumWorkingSetSize, MaximumWorkingSetSize, PagefileLimit;
		LONGINT TimeLimit;
	} WinApi_QUOTA_LIMITS;

typedef
	struct WinApi_RASTERIZER_STATUS {
		SHORTINT nSize, wFlags, nLanguageID;
	} WinApi_RASTERIZER_STATUS;

typedef
	struct WinApi_REG_PROVIDER {
		WinApi_QUERYHANDLER pi_R0_1val, pi_R0_allvals, pi_R3_1val, pi_R3_allvals;
		INTEGER pi_flags, pi_key_context;
	} WinApi_REG_PROVIDER;

typedef
	struct WinApi_RGNDATAHEADER {
		INTEGER dwSize, iType, nCount, nRgnSize;
		WinApi_RECT rcBound;
	} WinApi_RGNDATAHEADER;

typedef
	struct WinApi_RGNDATA {
		WinApi_RGNDATAHEADER rdh;
		CHAR Buffer[1];
	} WinApi_RGNDATA;

typedef
	INTEGER (*WinApi_ROC)(void);

typedef
	INTEGER (*WinApi_ROPENUMPROC)(void);

typedef
	INTEGER (*WinApi_ROPENUMPROCA)(void);

typedef
	INTEGER (*WinApi_ROPENUMPROCEX)(void);

typedef
	INTEGER (*WinApi_ROPENUMPROCEXA)(void);

typedef
	INTEGER (*WinApi_ROPENUMPROCEXW)(void);

typedef
	INTEGER (*WinApi_ROPENUMPROCW)(void);

typedef
	struct {
		LONGINT len[1];
		WinApi_PtrWSTR data[1];
	} *WinApi_RetCommandLineToArgvW;

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *WinApi_RetDdeAccessData;

typedef
	struct {
		LONGINT len[1];
		INTEGER data[1];
	} *WinApi_RetGetSidSubAuthority;

typedef
	struct WinApi_SCROLLINFO {
		INTEGER cbSize;
		SET fMask;
		INTEGER nMin, nMax, nPage, nPos, nTrackPos;
	} WinApi_SCROLLINFO;

typedef
	struct WinApi_SECURITY_ATTRIBUTES {
		INTEGER nLength, lpSecurityDescriptor, bInheritHandle;
	} WinApi_SECURITY_ATTRIBUTES;

typedef
	struct WinApi_SECURITY_DESCRIPTOR {
		CHAR Revision, Sbz1;
		SHORTINT Control;
		INTEGER Owner, Group;
		WinApi_PtrACL Sacl, Dacl;
	} WinApi_SECURITY_DESCRIPTOR;

typedef
	INTEGER (*WinApi_SENDASYNCPROC)(void);

typedef
	struct WinApi_SERIALKEYSA {
		INTEGER cbSize;
		SET dwFlags;
		WinApi_PtrSTR lpszActivePort, lpszPort;
		INTEGER iBaudRate, iPortState, iActive;
	} WinApi_SERIALKEYSA;

typedef
	struct WinApi_SERIALKEYSW {
		INTEGER cbSize;
		SET dwFlags;
		WinApi_PtrWSTR lpszActivePort, lpszPort;
		INTEGER iBaudRate, iPortState, iActive;
	} WinApi_SERIALKEYSW;

typedef
	void (*WinApi_SERVICE_MAIN_FUNCTIONA)(INTEGER, struct {
		LONGINT len[1];
		WinApi_PtrSTR data[1];
	}*);

typedef
	void (*WinApi_SERVICE_MAIN_FUNCTIONW)(INTEGER, struct {
		LONGINT len[1];
		WinApi_PtrWSTR data[1];
	}*);

typedef
	struct WinApi_SERVICE_TABLE_ENTRYA {
		WinApi_PtrSTR lpServiceName;
		WinApi_SERVICE_MAIN_FUNCTIONA lpServiceProc;
	} WinApi_SERVICE_TABLE_ENTRYA;

typedef
	struct WinApi_SERVICE_TABLE_ENTRYW {
		WinApi_PtrWSTR lpServiceName;
		WinApi_SERVICE_MAIN_FUNCTIONW lpServiceProc;
	} WinApi_SERVICE_TABLE_ENTRYW;

typedef
	struct WinApi_SE_IMPERSONATION_STATE {
		INTEGER Token;
		BOOLEAN CopyOnOpen, EffectiveOnly;
		INTEGER Level;
	} WinApi_SE_IMPERSONATION_STATE;

typedef
	struct WinApi_SHELLEXECUTEINFOA {
		INTEGER cbSize;
		SET fMask;
		INTEGER hwnd;
		WinApi_PtrSTR lpVerb, lpFile, lpParameters, lpDirectory;
		INTEGER nShow, hInstApp, lpIDList;
		WinApi_PtrSTR lpClass;
		INTEGER hkeyClass, dwHotKey, hIcon, hProcess;
	} WinApi_SHELLEXECUTEINFOA;

typedef
	struct WinApi_SHELLEXECUTEINFOW {
		INTEGER cbSize;
		SET fMask;
		INTEGER hwnd;
		WinApi_PtrWSTR lpVerb, lpFile, lpParameters, lpDirectory;
		INTEGER nShow, hInstApp, lpIDList;
		WinApi_PtrWSTR lpClass;
		INTEGER hkeyClass, dwHotKey, hIcon, hProcess;
	} WinApi_SHELLEXECUTEINFOW;

typedef
	struct WinApi_SHFILEINFOA {
		INTEGER hIcon, iIcon;
		SET dwAttributes;
		CHAR szDisplayName[260];
		CHAR szTypeName[80];
	} WinApi_SHFILEINFOA;

typedef
	struct WinApi_SHFILEINFOW {
		INTEGER hIcon, iIcon;
		SET dwAttributes;
		SHORTINT szDisplayName[260];
		SHORTINT szTypeName[80];
	} WinApi_SHFILEINFOW;

typedef
	struct WinApi_SHFILEOPSTRUCTA {
		INTEGER hwnd, wFunc;
		WinApi_PtrSTR pFrom, pTo;
		SHORTINT fFlags;
		INTEGER fAnyOperationsAborted, hNameMappings;
		WinApi_PtrSTR lpszProgressTitle;
	} WinApi_SHFILEOPSTRUCTA;

typedef
	struct WinApi_SHFILEOPSTRUCTW {
		INTEGER hwnd, wFunc;
		WinApi_PtrWSTR pFrom, pTo;
		SHORTINT fFlags;
		INTEGER fAnyOperationsAborted, hNameMappings;
		WinApi_PtrWSTR lpszProgressTitle;
	} WinApi_SHFILEOPSTRUCTW;

typedef
	struct WinApi_SHNAMEMAPPINGA {
		WinApi_PtrSTR pszOldPath, pszNewPath;
		INTEGER cchOldPath, cchNewPath;
	} WinApi_SHNAMEMAPPINGA;

typedef
	struct WinApi_SHNAMEMAPPINGW {
		WinApi_PtrWSTR pszOldPath, pszNewPath;
		INTEGER cchOldPath, cchNewPath;
	} WinApi_SHNAMEMAPPINGW;

typedef
	struct WinApi_SID_IDENTIFIER_AUTHORITY {
		CHAR Value[6];
	} WinApi_SID_IDENTIFIER_AUTHORITY;

typedef
	struct WinApi_SID {
		CHAR Revision, SubAuthorityCount;
		WinApi_SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
		INTEGER SubAuthority[1];
	} WinApi_SID;

typedef
	struct WinApi_SINGLE_LIST_ENTRY {
		WinApi_PtrSINGLE_LIST_ENTRY Next;
	} WinApi_SINGLE_LIST_ENTRY;

typedef
	struct WinApi_SOUNDSENTRYA {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER iFSTextEffect, iFSTextEffectMSec, iFSTextEffectColorBits, iFSGrafEffect, iFSGrafEffectMSec, iFSGrafEffectColor, iWindowsEffect, iWindowsEffectMSec;
		WinApi_PtrSTR lpszWindowsEffectDLL;
		INTEGER iWindowsEffectOrdinal;
	} WinApi_SOUNDSENTRYA;

typedef
	struct WinApi_SOUNDSENTRYW {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER iFSTextEffect, iFSTextEffectMSec, iFSTextEffectColorBits, iFSGrafEffect, iFSGrafEffectMSec, iFSGrafEffectColor, iWindowsEffect, iWindowsEffectMSec;
		WinApi_PtrWSTR lpszWindowsEffectDLL;
		INTEGER iWindowsEffectOrdinal;
	} WinApi_SOUNDSENTRYW;

typedef
	struct WinApi_STARTUPINFOA {
		INTEGER cb;
		WinApi_PtrSTR lpReserved, lpDesktop, lpTitle;
		INTEGER dwX, dwY, dwXSize, dwYSize, dwXCountChars, dwYCountChars, dwFillAttribute;
		SET dwFlags;
		SHORTINT wShowWindow, cbReserved2;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *lpReserved2;
		INTEGER hStdInput, hStdOutput, hStdError;
	} WinApi_STARTUPINFOA;

typedef
	struct WinApi_STARTUPINFOW {
		INTEGER cb;
		WinApi_PtrWSTR lpReserved, lpDesktop, lpTitle;
		INTEGER dwX, dwY, dwXSize, dwYSize, dwXCountChars, dwYCountChars, dwFillAttribute;
		SET dwFlags;
		SHORTINT wShowWindow, cbReserved2;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *lpReserved2;
		INTEGER hStdInput, hStdOutput, hStdError;
	} WinApi_STARTUPINFOW;

typedef
	struct WinApi_STICKYKEYS {
		INTEGER cbSize;
		SET dwFlags;
	} WinApi_STICKYKEYS;

typedef
	struct WinApi_STYLESTRUCT {
		SET styleOld, styleNew;
	} WinApi_STYLESTRUCT;

typedef
	struct WinApi_SYSTEM_ALARM_ACE {
		WinApi_ACE_HEADER Header;
		SET Mask;
		INTEGER SidStart;
	} WinApi_SYSTEM_ALARM_ACE;

typedef
	struct WinApi_SYSTEM_AUDIT_ACE {
		WinApi_ACE_HEADER Header;
		SET Mask;
		INTEGER SidStart;
	} WinApi_SYSTEM_AUDIT_ACE;

typedef
	struct WinApi_SYSTEM_INFO {
		struct WinApi__44 u;
		INTEGER dwPageSize, lpMinimumApplicationAddress, lpMaximumApplicationAddress, dwActiveProcessorMask, dwNumberOfProcessors, dwProcessorType, dwAllocationGranularity;
		SHORTINT wProcessorLevel, wProcessorRevision;
	} WinApi_SYSTEM_INFO;

typedef
	struct WinApi_SYSTEM_POWER_STATUS {
		CHAR ACLineStatus, BatteryFlag, BatteryLifePercent, Reserved1;
		INTEGER BatteryLifeTime, BatteryFullLifeTime;
	} WinApi_SYSTEM_POWER_STATUS;

typedef
	struct WinApi_TAPE_CREATE_PARTITION {
		INTEGER Method, Count, Size;
	} WinApi_TAPE_CREATE_PARTITION;

typedef
	struct WinApi_TAPE_ERASE {
		INTEGER Type;
		BOOLEAN Immediate;
	} WinApi_TAPE_ERASE;

typedef
	struct WinApi_TAPE_GET_DRIVE_PARAMETERS {
		BOOLEAN ECC, Compression, DataPadding, ReportSetmarks;
		INTEGER DefaultBlockSize, MaximumBlockSize, MinimumBlockSize, MaximumPartitionCount;
		SET FeaturesLow, FeaturesHigh;
		INTEGER EOTWarningZoneSize;
	} WinApi_TAPE_GET_DRIVE_PARAMETERS;

typedef
	struct WinApi_TAPE_GET_MEDIA_PARAMETERS {
		LONGINT Capacity, Remaining;
		INTEGER BlockSize, PartitionCount;
		BOOLEAN WriteProtected;
	} WinApi_TAPE_GET_MEDIA_PARAMETERS;

typedef
	struct WinApi_TAPE_GET_POSITION {
		INTEGER Type, Partition;
		LONGINT Offset;
	} WinApi_TAPE_GET_POSITION;

typedef
	struct WinApi_TAPE_PREPARE {
		INTEGER Operation;
		BOOLEAN Immediate;
	} WinApi_TAPE_PREPARE;

typedef
	struct WinApi_TAPE_SET_DRIVE_PARAMETERS {
		BOOLEAN ECC, Compression, DataPadding, ReportSetmarks;
		INTEGER EOTWarningZoneSize;
	} WinApi_TAPE_SET_DRIVE_PARAMETERS;

typedef
	struct WinApi_TAPE_SET_MEDIA_PARAMETERS {
		INTEGER BlockSize;
	} WinApi_TAPE_SET_MEDIA_PARAMETERS;

typedef
	struct WinApi_TAPE_SET_POSITION {
		INTEGER Method, Partition;
		LONGINT Offset;
		BOOLEAN Immediate;
	} WinApi_TAPE_SET_POSITION;

typedef
	struct WinApi_TAPE_WRITE_MARKS {
		INTEGER Type, Count;
		BOOLEAN Immediate;
	} WinApi_TAPE_WRITE_MARKS;

typedef
	INTEGER (*WinApi_TIMEFMT_ENUMPROCA)(void);

typedef
	INTEGER (*WinApi_TIMEFMT_ENUMPROCW)(void);

typedef
	void (*WinApi_TIMERAPCROUTINE)(INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (*WinApi_TIMERPROC)(void);

typedef
	struct WinApi_TIME_ZONE_INFORMATION {
		INTEGER Bias;
		SHORTINT StandardName[32];
		WinApi_SYSTEMTIME StandardDate;
		INTEGER StandardBias;
		SHORTINT DaylightName[32];
		WinApi_SYSTEMTIME DaylightDate;
		INTEGER DaylightBias;
	} WinApi_TIME_ZONE_INFORMATION;

typedef
	struct WinApi_TOGGLEKEYS {
		INTEGER cbSize;
		SET dwFlags;
	} WinApi_TOGGLEKEYS;

typedef
	struct WinApi_TOKEN_SOURCE {
		CHAR SourceName[8];
		LONGINT SourceIdentifier;
	} WinApi_TOKEN_SOURCE;

typedef
	struct WinApi_TOKEN_CONTROL {
		LONGINT TokenId, AuthenticationId, ModifiedId;
		WinApi_TOKEN_SOURCE TokenSource;
	} WinApi_TOKEN_CONTROL;

typedef
	struct WinApi_TOKEN_DEFAULT_DACL {
		WinApi_PtrACL DefaultDacl;
	} WinApi_TOKEN_DEFAULT_DACL;

typedef
	struct WinApi_TOKEN_GROUPS {
		INTEGER GroupCount;
		WinApi_SID_AND_ATTRIBUTES Groups[1];
	} WinApi_TOKEN_GROUPS;

typedef
	struct WinApi_TOKEN_OWNER {
		INTEGER Owner;
	} WinApi_TOKEN_OWNER;

typedef
	struct WinApi_TOKEN_PRIMARY_GROUP {
		INTEGER PrimaryGroup;
	} WinApi_TOKEN_PRIMARY_GROUP;

typedef
	struct WinApi_TOKEN_PRIVILEGES {
		INTEGER PrivilegeCount;
		WinApi_LUID_AND_ATTRIBUTES Privileges[1];
	} WinApi_TOKEN_PRIVILEGES;

typedef
	struct WinApi_TOKEN_STATISTICS {
		LONGINT TokenId, AuthenticationId, ExpirationTime;
		INTEGER TokenType, ImpersonationLevel, DynamicCharged, DynamicAvailable, GroupCount, PrivilegeCount;
		LONGINT ModifiedId;
	} WinApi_TOKEN_STATISTICS;

typedef
	struct WinApi_TOKEN_USER {
		WinApi_SID_AND_ATTRIBUTES User;
	} WinApi_TOKEN_USER;

typedef
	INTEGER (*WinApi_TOP_LEVEL_EXCEPTION_FILTER)(WinApi_EXCEPTION_POINTERS*, LONGINT *);

typedef
	struct WinApi_TPMPARAMS {
		INTEGER cbSize;
		WinApi_RECT rcExclude;
	} WinApi_TPMPARAMS;

typedef
	struct WinApi_TTPOLYCURVE {
		SHORTINT wType, cpfx;
		WinApi_POINTFX apfx[1];
	} WinApi_TTPOLYCURVE;

typedef
	struct WinApi_TTPOLYGONHEADER {
		INTEGER cb, dwType;
		WinApi_POINTFX pfxStart;
	} WinApi_TTPOLYGONHEADER;

typedef
	struct WinApi_USEROBJECTFLAGS {
		INTEGER fInherit, fReserved;
		SET dwFlags;
	} WinApi_USEROBJECTFLAGS;

typedef
	struct WinApi_VALENTA {
		WinApi_PtrSTR ve_valuename;
		INTEGER ve_valuelen, ve_valueptr, ve_type;
	} WinApi_VALENTA;

typedef
	struct WinApi_VALENTW {
		WinApi_PtrWSTR ve_valuename;
		INTEGER ve_valuelen, ve_valueptr, ve_type;
	} WinApi_VALENTW;

typedef
	struct WinApi_VS_FIXEDFILEINFO {
		INTEGER dwSignature, dwStrucVersion, dwFileVersionMS, dwFileVersionLS, dwProductVersionMS, dwProductVersionLS;
		SET dwFileFlagsMask, dwFileFlags, dwFileOS;
		INTEGER dwFileType, dwFileSubtype, dwFileDateMS, dwFileDateLS;
	} WinApi_VS_FIXEDFILEINFO;

typedef
	struct WinApi_WIN32_FILE_ATTRIBUTE_DATA {
		SET dwFileAttributes;
		WinApi_FILETIME ftCreationTime, ftLastAccessTime, ftLastWriteTime;
		INTEGER nFileSizeHigh, nFileSizeLow;
	} WinApi_WIN32_FILE_ATTRIBUTE_DATA;

typedef
	struct WinApi_WIN32_FIND_DATAA {
		SET dwFileAttributes;
		WinApi_FILETIME ftCreationTime, ftLastAccessTime, ftLastWriteTime;
		INTEGER nFileSizeHigh, nFileSizeLow, dwReserved0, dwReserved1;
		CHAR cFileName[260];
		CHAR cAlternateFileName[14];
	} WinApi_WIN32_FIND_DATAA;

typedef
	struct WinApi_WIN32_FIND_DATAW {
		SET dwFileAttributes;
		WinApi_FILETIME ftCreationTime, ftLastAccessTime, ftLastWriteTime;
		INTEGER nFileSizeHigh, nFileSizeLow, dwReserved0, dwReserved1;
		SHORTINT cFileName[260];
		SHORTINT cAlternateFileName[14];
	} WinApi_WIN32_FIND_DATAW;

typedef
	struct WinApi_WIN32_STREAM_ID {
		INTEGER dwStreamId;
		SET dwStreamAttributes;
		LONGINT Size;
		INTEGER dwStreamNameSize;
		SHORTINT cStreamName[1];
	} WinApi_WIN32_STREAM_ID;

typedef
	struct WinApi_WINDOWPLACEMENT {
		INTEGER length;
		SET flags;
		INTEGER showCmd;
		WinApi_POINT ptMinPosition, ptMaxPosition;
		WinApi_RECT rcNormalPosition;
	} WinApi_WINDOWPLACEMENT;

typedef
	struct WinApi_WINDOWPOS {
		INTEGER hwnd, hwndInsertAfter, x, y, cx, cy;
		SET flags;
	} WinApi_WINDOWPOS;

typedef
	INTEGER (*WinApi_WINSTAENUMPROC)(void);

typedef
	INTEGER (*WinApi_WINSTAENUMPROCA)(void);

typedef
	INTEGER (*WinApi_WINSTAENUMPROCW)(void);

typedef
	struct WinApi_WIN_CERTIFICATE {
		INTEGER dwLength;
		SHORTINT wRevision, wCertificateType;
		CHAR bCertificate[1];
	} WinApi_WIN_CERTIFICATE;

typedef
	struct WinApi_WIN_SPUB_TRUSTEDPUB_DATA {
		INTEGER hClientToken;
		WinApi_PtrWIN_CERTIFICATE lpCertificate;
	} WinApi_WIN_SPUB_TRUSTEDPUB_DATA;

typedef
	struct WinApi_WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT {
		INTEGER hClientToken, dwSubjectType, Subject;
	} WinApi_WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT;

typedef
	struct WinApi_WIN_TRUST_ACTDATA_SUBJECT_ONLY {
		INTEGER dwSubjectType, Subject;
	} WinApi_WIN_TRUST_ACTDATA_SUBJECT_ONLY;

typedef
	struct WinApi_WIN_TRUST_SUBJECT_FILE {
		INTEGER hFile;
		WinApi_PtrWSTR lpPath;
	} WinApi_WIN_TRUST_SUBJECT_FILE;

typedef
	INTEGER (*WinApi_WNDPROC)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	struct WinApi_WNDCLASSA {
		SET style;
		WinApi_WNDPROC lpfnWndProc;
		INTEGER cbClsExtra, cbWndExtra, hInstance, hIcon, hCursor, hbrBackground;
		WinApi_PtrSTR lpszMenuName, lpszClassName;
	} WinApi_WNDCLASSA;

typedef
	struct WinApi_WNDCLASSEXA {
		INTEGER cbSize;
		SET style;
		WinApi_WNDPROC lpfnWndProc;
		INTEGER cbClsExtra, cbWndExtra, hInstance, hIcon, hCursor, hbrBackground;
		WinApi_PtrSTR lpszMenuName, lpszClassName;
		INTEGER hIconSm;
	} WinApi_WNDCLASSEXA;

typedef
	struct WinApi_WNDCLASSEXW {
		INTEGER cbSize;
		SET style;
		WinApi_WNDPROC lpfnWndProc;
		INTEGER cbClsExtra, cbWndExtra, hInstance, hIcon, hCursor, hbrBackground;
		WinApi_PtrWSTR lpszMenuName, lpszClassName;
		INTEGER hIconSm;
	} WinApi_WNDCLASSEXW;

typedef
	struct WinApi_WNDCLASSW {
		SET style;
		WinApi_WNDPROC lpfnWndProc;
		INTEGER cbClsExtra, cbWndExtra, hInstance, hIcon, hCursor, hbrBackground;
		WinApi_PtrWSTR lpszMenuName, lpszClassName;
	} WinApi_WNDCLASSW;

typedef
	INTEGER (*WinApi_WNDENUMPROC)(void);

typedef
	struct WinApi__EXCEPTION_REGISTRATION_RECORD {
		char _prvt0[1];
	} WinApi__EXCEPTION_REGISTRATION_RECORD;

typedef
	struct WinApi__POINTL {
		INTEGER x, y;
	} WinApi__POINTL;

typedef
	struct WinApi__PSP {
		char _prvt0[1];
	} WinApi__PSP;

typedef
	struct WinApi__RECTL {
		INTEGER left, top, right, bottom;
	} WinApi__RECTL;



import LONGINT *WinApi_LIST_ENTRY__typ;
import LONGINT *WinApi_SINGLE_LIST_ENTRY__typ;
import LONGINT *WinApi_COM_GUID__typ;
import LONGINT *WinApi_OBJECTID__typ;
import LONGINT *WinApi_FLOATING_SAVE_AREA__typ;
import LONGINT *WinApi_CONTEXT__typ;
import LONGINT *WinApi__24__typ;
import LONGINT *WinApi__25__typ;
import LONGINT *WinApi__26__typ;
import LONGINT *WinApi_LDT_ENTRY__typ;
import LONGINT *WinApi_EXCEPTION_RECORD__typ;
import LONGINT *WinApi_EXCEPTION_POINTERS__typ;
import LONGINT *WinApi__EXCEPTION_REGISTRATION_RECORD__typ;
import LONGINT *WinApi__27__typ;
import LONGINT *WinApi_NT_TIB__typ;
import LONGINT *WinApi_QUOTA_LIMITS__typ;
import LONGINT *WinApi_MEMORY_BASIC_INFORMATION__typ;
import LONGINT *WinApi_FILE_NOTIFY_INFORMATION__typ;
import LONGINT *WinApi_GENERIC_MAPPING__typ;
import LONGINT *WinApi_LUID_AND_ATTRIBUTES__typ;
import LONGINT *WinApi_SID_IDENTIFIER_AUTHORITY__typ;
import LONGINT *WinApi_SID__typ;
import LONGINT *WinApi_SID_AND_ATTRIBUTES__typ;
import LONGINT *WinApi_ACL__typ;
import LONGINT *WinApi_ACE_HEADER__typ;
import LONGINT *WinApi_ACCESS_ALLOWED_ACE__typ;
import LONGINT *WinApi_ACCESS_DENIED_ACE__typ;
import LONGINT *WinApi_SYSTEM_AUDIT_ACE__typ;
import LONGINT *WinApi_SYSTEM_ALARM_ACE__typ;
import LONGINT *WinApi_COMPOUND_ACCESS_ALLOWED_ACE__typ;
import LONGINT *WinApi_ACL_REVISION_INFORMATION__typ;
import LONGINT *WinApi_ACL_SIZE_INFORMATION__typ;
import LONGINT *WinApi_SECURITY_DESCRIPTOR__typ;
import LONGINT *WinApi_PRIVILEGE_SET__typ;
import LONGINT *WinApi_TOKEN_USER__typ;
import LONGINT *WinApi_TOKEN_GROUPS__typ;
import LONGINT *WinApi_TOKEN_PRIVILEGES__typ;
import LONGINT *WinApi_TOKEN_OWNER__typ;
import LONGINT *WinApi_TOKEN_PRIMARY_GROUP__typ;
import LONGINT *WinApi_TOKEN_DEFAULT_DACL__typ;
import LONGINT *WinApi_TOKEN_SOURCE__typ;
import LONGINT *WinApi_TOKEN_STATISTICS__typ;
import LONGINT *WinApi_TOKEN_CONTROL__typ;
import LONGINT *WinApi_SECURITY_QUALITY_OF_SERVICE__typ;
import LONGINT *WinApi_SE_IMPERSONATION_STATE__typ;
import LONGINT *WinApi_IMAGE_DOS_HEADER__typ;
import LONGINT *WinApi_IMAGE_OS2_HEADER__typ;
import LONGINT *WinApi_IMAGE_VXD_HEADER__typ;
import LONGINT *WinApi_IMAGE_FILE_HEADER__typ;
import LONGINT *WinApi_IMAGE_DATA_DIRECTORY__typ;
import LONGINT *WinApi_IMAGE_OPTIONAL_HEADER__typ;
import LONGINT *WinApi_IMAGE_ROM_OPTIONAL_HEADER__typ;
import LONGINT *WinApi_IMAGE_NT_HEADERS__typ;
import LONGINT *WinApi_IMAGE_ROM_HEADERS__typ;
import LONGINT *WinApi__19__typ;
import LONGINT *WinApi_IMAGE_SECTION_HEADER__typ;
import LONGINT *WinApi__20__typ;
import LONGINT *WinApi__21__typ;
import LONGINT *WinApi_IMAGE_SYMBOL__typ;
import LONGINT *WinApi__3__typ;
import LONGINT *WinApi__4__typ;
import LONGINT *WinApi__5__typ;
import LONGINT *WinApi__6__typ;
import LONGINT *WinApi__7__typ;
import LONGINT *WinApi__8__typ;
import LONGINT *WinApi__9__typ;
import LONGINT *WinApi__10__typ;
import LONGINT *WinApi_IMAGE_AUX_SYMBOL__typ;
import LONGINT *WinApi__14__typ;
import LONGINT *WinApi_IMAGE_RELOCATION__typ;
import LONGINT *WinApi_IMAGE_BASE_RELOCATION__typ;
import LONGINT *WinApi__13__typ;
import LONGINT *WinApi_IMAGE_LINENUMBER__typ;
import LONGINT *WinApi_IMAGE_ARCHIVE_MEMBER_HEADER__typ;
import LONGINT *WinApi_IMAGE_EXPORT_DIRECTORY__typ;
import LONGINT *WinApi_IMAGE_IMPORT_BY_NAME__typ;
import LONGINT *WinApi__11__typ;
import LONGINT *WinApi_IMAGE_THUNK_DATA__typ;
import LONGINT *WinApi__12__typ;
import LONGINT *WinApi_IMAGE_IMPORT_DESCRIPTOR__typ;
import LONGINT *WinApi_IMAGE_BOUND_IMPORT_DESCRIPTOR__typ;
import LONGINT *WinApi_IMAGE_BOUND_FORWARDER_REF__typ;
import LONGINT *WinApi_IMAGE_TLS_DIRECTORY__typ;
import LONGINT *WinApi_IMAGE_RESOURCE_DIRECTORY__typ;
import LONGINT *WinApi__15__typ;
import LONGINT *WinApi__16__typ;
import LONGINT *WinApi__17__typ;
import LONGINT *WinApi__18__typ;
import LONGINT *WinApi_IMAGE_RESOURCE_DIRECTORY_ENTRY__typ;
import LONGINT *WinApi_IMAGE_RESOURCE_DIRECTORY_STRING__typ;
import LONGINT *WinApi_IMAGE_RESOURCE_DIR_STRING_U__typ;
import LONGINT *WinApi_IMAGE_RESOURCE_DATA_ENTRY__typ;
import LONGINT *WinApi_IMAGE_LOAD_CONFIG_DIRECTORY__typ;
import LONGINT *WinApi_IMAGE_RUNTIME_FUNCTION_ENTRY__typ;
import LONGINT *WinApi_IMAGE_DEBUG_DIRECTORY__typ;
import LONGINT *WinApi_IMAGE_COFF_SYMBOLS_HEADER__typ;
import LONGINT *WinApi_FPO_DATA__typ;
import LONGINT *WinApi_IMAGE_DEBUG_MISC__typ;
import LONGINT *WinApi_IMAGE_FUNCTION_ENTRY__typ;
import LONGINT *WinApi_IMAGE_SEPARATE_DEBUG_HEADER__typ;
import LONGINT *WinApi_MESSAGE_RESOURCE_ENTRY__typ;
import LONGINT *WinApi_MESSAGE_RESOURCE_BLOCK__typ;
import LONGINT *WinApi_MESSAGE_RESOURCE_DATA__typ;
import LONGINT *WinApi_RTL_CRITICAL_SECTION_DEBUG__typ;
import LONGINT *WinApi_RTL_CRITICAL_SECTION__typ;
import LONGINT *WinApi_EVENTLOGRECORD__typ;
import LONGINT *WinApi_TAPE_ERASE__typ;
import LONGINT *WinApi_TAPE_PREPARE__typ;
import LONGINT *WinApi_TAPE_WRITE_MARKS__typ;
import LONGINT *WinApi_TAPE_GET_POSITION__typ;
import LONGINT *WinApi_TAPE_SET_POSITION__typ;
import LONGINT *WinApi_TAPE_GET_DRIVE_PARAMETERS__typ;
import LONGINT *WinApi_TAPE_SET_DRIVE_PARAMETERS__typ;
import LONGINT *WinApi_TAPE_GET_MEDIA_PARAMETERS__typ;
import LONGINT *WinApi_TAPE_SET_MEDIA_PARAMETERS__typ;
import LONGINT *WinApi_TAPE_CREATE_PARTITION__typ;
import LONGINT *WinApi_RECT__typ;
import LONGINT *WinApi__RECTL__typ;
import LONGINT *WinApi_POINT__typ;
import LONGINT *WinApi__POINTL__typ;
import LONGINT *WinApi_SIZE__typ;
import LONGINT *WinApi_POINTS__typ;
import LONGINT *WinApi_OVERLAPPED__typ;
import LONGINT *WinApi_SECURITY_ATTRIBUTES__typ;
import LONGINT *WinApi_PROCESS_INFORMATION__typ;
import LONGINT *WinApi_FILETIME__typ;
import LONGINT *WinApi_SYSTEMTIME__typ;
import LONGINT *WinApi_COMMPROP__typ;
import LONGINT *WinApi_COMSTAT__typ;
import LONGINT *WinApi_DCB__typ;
import LONGINT *WinApi_COMMTIMEOUTS__typ;
import LONGINT *WinApi_COMMCONFIG__typ;
import LONGINT *WinApi__43__typ;
import LONGINT *WinApi__44__typ;
import LONGINT *WinApi_SYSTEM_INFO__typ;
import LONGINT *WinApi_MEMORYSTATUS__typ;
import LONGINT *WinApi_EXCEPTION_DEBUG_INFO__typ;
import LONGINT *WinApi_CREATE_THREAD_DEBUG_INFO__typ;
import LONGINT *WinApi_CREATE_PROCESS_DEBUG_INFO__typ;
import LONGINT *WinApi_EXIT_THREAD_DEBUG_INFO__typ;
import LONGINT *WinApi_EXIT_PROCESS_DEBUG_INFO__typ;
import LONGINT *WinApi_LOAD_DLL_DEBUG_INFO__typ;
import LONGINT *WinApi_UNLOAD_DLL_DEBUG_INFO__typ;
import LONGINT *WinApi_OUTPUT_DEBUG_STRING_INFO__typ;
import LONGINT *WinApi_RIP_INFO__typ;
import LONGINT *WinApi__2__typ;
import LONGINT *WinApi_DEBUG_EVENT__typ;
import LONGINT *WinApi_OFSTRUCT__typ;
import LONGINT *WinApi__30__typ;
import LONGINT *WinApi__31__typ;
import LONGINT *WinApi__32__typ;
import LONGINT *WinApi_PROCESS_HEAP_ENTRY__typ;
import LONGINT *WinApi_BY_HANDLE_FILE_INFORMATION__typ;
import LONGINT *WinApi_TIME_ZONE_INFORMATION__typ;
import LONGINT *WinApi_WIN32_STREAM_ID__typ;
import LONGINT *WinApi_STARTUPINFOA__typ;
import LONGINT *WinApi_STARTUPINFOW__typ;
import LONGINT *WinApi_WIN32_FIND_DATAA__typ;
import LONGINT *WinApi_WIN32_FIND_DATAW__typ;
import LONGINT *WinApi_WIN32_FILE_ATTRIBUTE_DATA__typ;
import LONGINT *WinApi_HW_PROFILE_INFOA__typ;
import LONGINT *WinApi_HW_PROFILE_INFOW__typ;
import LONGINT *WinApi_OSVERSIONINFOA__typ;
import LONGINT *WinApi_OSVERSIONINFOW__typ;
import LONGINT *WinApi_SYSTEM_POWER_STATUS__typ;
import LONGINT *WinApi_WIN_CERTIFICATE__typ;
import LONGINT *WinApi_WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT__typ;
import LONGINT *WinApi_WIN_TRUST_ACTDATA_SUBJECT_ONLY__typ;
import LONGINT *WinApi_WIN_TRUST_SUBJECT_FILE__typ;
import LONGINT *WinApi_WIN_SPUB_TRUSTEDPUB_DATA__typ;
import LONGINT *WinApi_XFORM__typ;
import LONGINT *WinApi_BITMAP__typ;
import LONGINT *WinApi_RGBTRIPLE__typ;
import LONGINT *WinApi_RGBQUAD__typ;
import LONGINT *WinApi_CIEXYZ__typ;
import LONGINT *WinApi_CIEXYZTRIPLE__typ;
import LONGINT *WinApi_LOGCOLORSPACEA__typ;
import LONGINT *WinApi_LOGCOLORSPACEW__typ;
import LONGINT *WinApi_BITMAPCOREHEADER__typ;
import LONGINT *WinApi_BITMAPINFOHEADER__typ;
import LONGINT *WinApi_BITMAPV4HEADER__typ;
import LONGINT *WinApi_BITMAPINFO__typ;
import LONGINT *WinApi_BITMAPCOREINFO__typ;
import LONGINT *WinApi_BITMAPFILEHEADER__typ;
import LONGINT *WinApi_FONTSIGNATURE__typ;
import LONGINT *WinApi_CHARSETINFO__typ;
import LONGINT *WinApi_LOCALESIGNATURE__typ;
import LONGINT *WinApi_HANDLETABLE__typ;
import LONGINT *WinApi_METARECORD__typ;
import LONGINT *WinApi_METAFILEPICT__typ;
import LONGINT *WinApi_METAHEADER__typ;
import LONGINT *WinApi_ENHMETARECORD__typ;
import LONGINT *WinApi_ENHMETAHEADER__typ;
import LONGINT *WinApi_TEXTMETRICA__typ;
import LONGINT *WinApi_TEXTMETRICW__typ;
import LONGINT *WinApi_NEWTEXTMETRICA__typ;
import LONGINT *WinApi_NEWTEXTMETRICW__typ;
import LONGINT *WinApi_NEWTEXTMETRICEXA__typ;
import LONGINT *WinApi_NEWTEXTMETRICEXW__typ;
import LONGINT *WinApi_PELARRAY__typ;
import LONGINT *WinApi_LOGBRUSH__typ;
import LONGINT *WinApi_LOGPEN__typ;
import LONGINT *WinApi_EXTLOGPEN__typ;
import LONGINT *WinApi_PALETTEENTRY__typ;
import LONGINT *WinApi_LOGPALETTE__typ;
import LONGINT *WinApi_LOGFONTA__typ;
import LONGINT *WinApi_LOGFONTW__typ;
import LONGINT *WinApi_ENUMLOGFONTA__typ;
import LONGINT *WinApi_ENUMLOGFONTW__typ;
import LONGINT *WinApi_ENUMLOGFONTEXA__typ;
import LONGINT *WinApi_ENUMLOGFONTEXW__typ;
import LONGINT *WinApi_PANOSE__typ;
import LONGINT *WinApi_EXTLOGFONTA__typ;
import LONGINT *WinApi_EXTLOGFONTW__typ;
import LONGINT *WinApi_DEVMODEA__typ;
import LONGINT *WinApi_DEVMODEW__typ;
import LONGINT *WinApi_RGNDATAHEADER__typ;
import LONGINT *WinApi_RGNDATA__typ;
import LONGINT *WinApi_ABC__typ;
import LONGINT *WinApi_ABCFLOAT__typ;
import LONGINT *WinApi_OUTLINETEXTMETRICA__typ;
import LONGINT *WinApi_OUTLINETEXTMETRICW__typ;
import LONGINT *WinApi_POLYTEXTA__typ;
import LONGINT *WinApi_POLYTEXTW__typ;
import LONGINT *WinApi_FIXED__typ;
import LONGINT *WinApi_MAT2__typ;
import LONGINT *WinApi_GLYPHMETRICS__typ;
import LONGINT *WinApi_POINTFX__typ;
import LONGINT *WinApi_TTPOLYCURVE__typ;
import LONGINT *WinApi_TTPOLYGONHEADER__typ;
import LONGINT *WinApi_GCP_RESULTSA__typ;
import LONGINT *WinApi_GCP_RESULTSW__typ;
import LONGINT *WinApi_RASTERIZER_STATUS__typ;
import LONGINT *WinApi_PIXELFORMATDESCRIPTOR__typ;
import LONGINT *WinApi_DIBSECTION__typ;
import LONGINT *WinApi_COLORADJUSTMENT__typ;
import LONGINT *WinApi_DOCINFOA__typ;
import LONGINT *WinApi_DOCINFOW__typ;
import LONGINT *WinApi_KERNINGPAIR__typ;
import LONGINT *WinApi_EMR__typ;
import LONGINT *WinApi_EMRTEXT__typ;
import LONGINT *WinApi_EMRABORTPATH__typ;
import LONGINT *WinApi_EMRSELECTCLIPPATH__typ;
import LONGINT *WinApi_EMRSETMITERLIMIT__typ;
import LONGINT *WinApi_EMRRESTOREDC__typ;
import LONGINT *WinApi_EMRSETARCDIRECTION__typ;
import LONGINT *WinApi_EMRSETMAPPERFLAGS__typ;
import LONGINT *WinApi_EMRSETBKCOLOR__typ;
import LONGINT *WinApi_EMRSELECTOBJECT__typ;
import LONGINT *WinApi_EMRSELECTCOLORSPACE__typ;
import LONGINT *WinApi_EMRSELECTPALETTE__typ;
import LONGINT *WinApi_EMRRESIZEPALETTE__typ;
import LONGINT *WinApi_EMRSETPALETTEENTRIES__typ;
import LONGINT *WinApi_EMRSETCOLORADJUSTMENT__typ;
import LONGINT *WinApi_EMRGDICOMMENT__typ;
import LONGINT *WinApi_EMREOF__typ;
import LONGINT *WinApi_EMRLINETO__typ;
import LONGINT *WinApi_EMROFFSETCLIPRGN__typ;
import LONGINT *WinApi_EMRFILLPATH__typ;
import LONGINT *WinApi_EMREXCLUDECLIPRECT__typ;
import LONGINT *WinApi_EMRSETVIEWPORTORGEX__typ;
import LONGINT *WinApi_EMRSETVIEWPORTEXTEX__typ;
import LONGINT *WinApi_EMRSCALEVIEWPORTEXTEX__typ;
import LONGINT *WinApi_EMRSETWORLDTRANSFORM__typ;
import LONGINT *WinApi_EMRMODIFYWORLDTRANSFORM__typ;
import LONGINT *WinApi_EMRSETPIXELV__typ;
import LONGINT *WinApi_EMREXTFLOODFILL__typ;
import LONGINT *WinApi_EMRELLIPSE__typ;
import LONGINT *WinApi_EMRROUNDRECT__typ;
import LONGINT *WinApi_EMRARC__typ;
import LONGINT *WinApi_EMRANGLEARC__typ;
import LONGINT *WinApi_EMRPOLYLINE__typ;
import LONGINT *WinApi_EMRPOLYLINE16__typ;
import LONGINT *WinApi_EMRPOLYDRAW__typ;
import LONGINT *WinApi_EMRPOLYDRAW16__typ;
import LONGINT *WinApi_EMRPOLYPOLYLINE__typ;
import LONGINT *WinApi_EMRPOLYPOLYLINE16__typ;
import LONGINT *WinApi_EMRINVERTRGN__typ;
import LONGINT *WinApi_EMRFILLRGN__typ;
import LONGINT *WinApi_EMRFRAMERGN__typ;
import LONGINT *WinApi_EMREXTSELECTCLIPRGN__typ;
import LONGINT *WinApi_EMREXTTEXTOUTA__typ;
import LONGINT *WinApi_EMRPOLYTEXTOUTA__typ;
import LONGINT *WinApi_EMRBITBLT__typ;
import LONGINT *WinApi_EMRSTRETCHBLT__typ;
import LONGINT *WinApi_EMRMASKBLT__typ;
import LONGINT *WinApi_EMRPLGBLT__typ;
import LONGINT *WinApi_EMRSETDIBITSTODEVICE__typ;
import LONGINT *WinApi_EMRSTRETCHDIBITS__typ;
import LONGINT *WinApi_EMREXTCREATEFONTINDIRECTW__typ;
import LONGINT *WinApi_EMRCREATEPALETTE__typ;
import LONGINT *WinApi_EMRCREATECOLORSPACE__typ;
import LONGINT *WinApi_EMRCREATEPEN__typ;
import LONGINT *WinApi_EMREXTCREATEPEN__typ;
import LONGINT *WinApi_EMRCREATEBRUSHINDIRECT__typ;
import LONGINT *WinApi_EMRCREATEMONOBRUSH__typ;
import LONGINT *WinApi_EMRCREATEDIBPATTERNBRUSHPT__typ;
import LONGINT *WinApi_EMRFORMAT__typ;
import LONGINT *WinApi_EMRGLSRECORD__typ;
import LONGINT *WinApi_EMRGLSBOUNDEDRECORD__typ;
import LONGINT *WinApi_EMRPIXELFORMAT__typ;
import LONGINT *WinApi_POINTFLOAT__typ;
import LONGINT *WinApi_GLYPHMETRICSFLOAT__typ;
import LONGINT *WinApi_LAYERPLANEDESCRIPTOR__typ;
import LONGINT *WinApi_MENUTEMPLATEA__typ;
import LONGINT *WinApi_MENUTEMPLATEW__typ;
import LONGINT *WinApi_MENUTEMPLATE__typ;
import LONGINT *WinApi_CBT_CREATEWNDA__typ;
import LONGINT *WinApi_CBT_CREATEWNDW__typ;
import LONGINT *WinApi_CBTACTIVATESTRUCT__typ;
import LONGINT *WinApi_EVENTMSG__typ;
import LONGINT *WinApi_CWPSTRUCT__typ;
import LONGINT *WinApi_CWPRETSTRUCT__typ;
import LONGINT *WinApi_DEBUGHOOKINFO__typ;
import LONGINT *WinApi_MOUSEHOOKSTRUCT__typ;
import LONGINT *WinApi_HARDWAREHOOKSTRUCT__typ;
import LONGINT *WinApi_USEROBJECTFLAGS__typ;
import LONGINT *WinApi_WNDCLASSEXA__typ;
import LONGINT *WinApi_WNDCLASSEXW__typ;
import LONGINT *WinApi_WNDCLASSA__typ;
import LONGINT *WinApi_WNDCLASSW__typ;
import LONGINT *WinApi_MSG__typ;
import LONGINT *WinApi_MINMAXINFO__typ;
import LONGINT *WinApi_COPYDATASTRUCT__typ;
import LONGINT *WinApi_MDINEXTMENU__typ;
import LONGINT *WinApi_WINDOWPOS__typ;
import LONGINT *WinApi_NCCALCSIZE_PARAMS__typ;
import LONGINT *WinApi_ACCEL__typ;
import LONGINT *WinApi_PAINTSTRUCT__typ;
import LONGINT *WinApi_CREATESTRUCTA__typ;
import LONGINT *WinApi_CREATESTRUCTW__typ;
import LONGINT *WinApi_WINDOWPLACEMENT__typ;
import LONGINT *WinApi_NMHDR__typ;
import LONGINT *WinApi_STYLESTRUCT__typ;
import LONGINT *WinApi_MEASUREITEMSTRUCT__typ;
import LONGINT *WinApi_DRAWITEMSTRUCT__typ;
import LONGINT *WinApi_DELETEITEMSTRUCT__typ;
import LONGINT *WinApi_COMPAREITEMSTRUCT__typ;
import LONGINT *WinApi_BROADCASTSYSMSG__typ;
import LONGINT *WinApi_DLGTEMPLATE__typ;
import LONGINT *WinApi_DLGITEMTEMPLATE__typ;
import LONGINT *WinApi_TPMPARAMS__typ;
import LONGINT *WinApi_MENUITEMINFOA__typ;
import LONGINT *WinApi_MENUITEMINFOW__typ;
import LONGINT *WinApi_DROPSTRUCT__typ;
import LONGINT *WinApi_DRAWTEXTPARAMS__typ;
import LONGINT *WinApi_HELPINFO__typ;
import LONGINT *WinApi_MSGBOXPARAMSA__typ;
import LONGINT *WinApi_MSGBOXPARAMSW__typ;
import LONGINT *WinApi_MENUITEMTEMPLATEHEADER__typ;
import LONGINT *WinApi_MENUITEMTEMPLATE__typ;
import LONGINT *WinApi_ICONINFO__typ;
import LONGINT *WinApi_CURSORSHAPE__typ;
import LONGINT *WinApi_SCROLLINFO__typ;
import LONGINT *WinApi_MDICREATESTRUCTA__typ;
import LONGINT *WinApi_MDICREATESTRUCTW__typ;
import LONGINT *WinApi_CLIENTCREATESTRUCT__typ;
import LONGINT *WinApi_MULTIKEYHELPA__typ;
import LONGINT *WinApi_MULTIKEYHELPW__typ;
import LONGINT *WinApi_HELPWININFOA__typ;
import LONGINT *WinApi_HELPWININFOW__typ;
import LONGINT *WinApi_NONCLIENTMETRICSA__typ;
import LONGINT *WinApi_NONCLIENTMETRICSW__typ;
import LONGINT *WinApi_MINIMIZEDMETRICS__typ;
import LONGINT *WinApi_ICONMETRICSA__typ;
import LONGINT *WinApi_ICONMETRICSW__typ;
import LONGINT *WinApi_ANIMATIONINFO__typ;
import LONGINT *WinApi_SERIALKEYSA__typ;
import LONGINT *WinApi_SERIALKEYSW__typ;
import LONGINT *WinApi_HIGHCONTRASTA__typ;
import LONGINT *WinApi_HIGHCONTRASTW__typ;
import LONGINT *WinApi_FILTERKEYS__typ;
import LONGINT *WinApi_STICKYKEYS__typ;
import LONGINT *WinApi_MOUSEKEYS__typ;
import LONGINT *WinApi_ACCESSTIMEOUT__typ;
import LONGINT *WinApi_SOUNDSENTRYA__typ;
import LONGINT *WinApi_SOUNDSENTRYW__typ;
import LONGINT *WinApi_TOGGLEKEYS__typ;
import LONGINT *WinApi_CPINFO__typ;
import LONGINT *WinApi_NUMBERFMTA__typ;
import LONGINT *WinApi_NUMBERFMTW__typ;
import LONGINT *WinApi_CURRENCYFMTA__typ;
import LONGINT *WinApi_CURRENCYFMTW__typ;
import LONGINT *WinApi_COORD__typ;
import LONGINT *WinApi_SMALL_RECT__typ;
import LONGINT *WinApi__22__typ;
import LONGINT *WinApi_KEY_EVENT_RECORD__typ;
import LONGINT *WinApi_MOUSE_EVENT_RECORD__typ;
import LONGINT *WinApi_WINDOW_BUFFER_SIZE_RECORD__typ;
import LONGINT *WinApi_MENU_EVENT_RECORD__typ;
import LONGINT *WinApi_FOCUS_EVENT_RECORD__typ;
import LONGINT *WinApi__23__typ;
import LONGINT *WinApi_INPUT_RECORD__typ;
import LONGINT *WinApi__1__typ;
import LONGINT *WinApi_CHAR_INFO__typ;
import LONGINT *WinApi_CONSOLE_SCREEN_BUFFER_INFO__typ;
import LONGINT *WinApi_CONSOLE_CURSOR_INFO__typ;
import LONGINT *WinApi_VS_FIXEDFILEINFO__typ;
import LONGINT *WinApi_val_context__typ;
import LONGINT *WinApi_PVALUEA__typ;
import LONGINT *WinApi_PVALUEW__typ;
import LONGINT *WinApi_REG_PROVIDER__typ;
import LONGINT *WinApi_VALENTA__typ;
import LONGINT *WinApi_VALENTW__typ;
import LONGINT *WinApi_DDEACK__typ;
import LONGINT *WinApi_DDEADVISE__typ;
import LONGINT *WinApi_DDEDATA__typ;
import LONGINT *WinApi_DDEPOKE__typ;
import LONGINT *WinApi_DDELN__typ;
import LONGINT *WinApi_DDEUP__typ;
import LONGINT *WinApi_HSZPAIR__typ;
import LONGINT *WinApi_CONVCONTEXT__typ;
import LONGINT *WinApi_CONVINFO__typ;
import LONGINT *WinApi_DDEML_MSG_HOOK_DATA__typ;
import LONGINT *WinApi_MONMSGSTRUCT__typ;
import LONGINT *WinApi_MONCBSTRUCT__typ;
import LONGINT *WinApi_MONHSZSTRUCTA__typ;
import LONGINT *WinApi_MONHSZSTRUCTW__typ;
import LONGINT *WinApi_MONERRSTRUCT__typ;
import LONGINT *WinApi_MONLINKSTRUCT__typ;
import LONGINT *WinApi_MONCONVSTRUCT__typ;
import LONGINT *WinApi_DRAGINFOA__typ;
import LONGINT *WinApi_DRAGINFOW__typ;
import LONGINT *WinApi_APPBARDATA__typ;
import LONGINT *WinApi_SHFILEOPSTRUCTA__typ;
import LONGINT *WinApi_SHFILEOPSTRUCTW__typ;
import LONGINT *WinApi_SHNAMEMAPPINGA__typ;
import LONGINT *WinApi_SHNAMEMAPPINGW__typ;
import LONGINT *WinApi_SHELLEXECUTEINFOA__typ;
import LONGINT *WinApi_SHELLEXECUTEINFOW__typ;
import LONGINT *WinApi_NOTIFYICONDATAA__typ;
import LONGINT *WinApi_NOTIFYICONDATAW__typ;
import LONGINT *WinApi_SHFILEINFOA__typ;
import LONGINT *WinApi_SHFILEINFOW__typ;
import LONGINT *WinApi__35__typ;
import LONGINT *WinApi__36__typ;
import LONGINT *WinApi_PROPSHEETPAGEA__typ;
import LONGINT *WinApi__40__typ;
import LONGINT *WinApi__41__typ;
import LONGINT *WinApi_PROPSHEETPAGEW__typ;
import LONGINT *WinApi__PSP__typ;
import LONGINT *WinApi__33__typ;
import LONGINT *WinApi__34__typ;
import LONGINT *WinApi__37__typ;
import LONGINT *WinApi_PROPSHEETHEADERA__typ;
import LONGINT *WinApi__38__typ;
import LONGINT *WinApi__39__typ;
import LONGINT *WinApi__42__typ;
import LONGINT *WinApi_PROPSHEETHEADERW__typ;
import LONGINT *WinApi_PSHNOTIFY__typ;
import LONGINT *WinApi_PRINTER_INFO_1A__typ;
import LONGINT *WinApi_PRINTER_INFO_1W__typ;
import LONGINT *WinApi_PRINTER_INFO_2A__typ;
import LONGINT *WinApi_PRINTER_INFO_2W__typ;
import LONGINT *WinApi_PRINTER_INFO_3__typ;
import LONGINT *WinApi_PRINTER_INFO_4A__typ;
import LONGINT *WinApi_PRINTER_INFO_4W__typ;
import LONGINT *WinApi_PRINTER_INFO_5A__typ;
import LONGINT *WinApi_PRINTER_INFO_5W__typ;
import LONGINT *WinApi_PRINTER_INFO_6__typ;
import LONGINT *WinApi_JOB_INFO_1A__typ;
import LONGINT *WinApi_JOB_INFO_1W__typ;
import LONGINT *WinApi_JOB_INFO_2A__typ;
import LONGINT *WinApi_JOB_INFO_2W__typ;
import LONGINT *WinApi_ADDJOB_INFO_1A__typ;
import LONGINT *WinApi_ADDJOB_INFO_1W__typ;
import LONGINT *WinApi_DRIVER_INFO_1A__typ;
import LONGINT *WinApi_DRIVER_INFO_1W__typ;
import LONGINT *WinApi_DRIVER_INFO_2A__typ;
import LONGINT *WinApi_DRIVER_INFO_2W__typ;
import LONGINT *WinApi_DRIVER_INFO_3A__typ;
import LONGINT *WinApi_DRIVER_INFO_3W__typ;
import LONGINT *WinApi_DOC_INFO_1A__typ;
import LONGINT *WinApi_DOC_INFO_1W__typ;
import LONGINT *WinApi_FORM_INFO_1A__typ;
import LONGINT *WinApi_FORM_INFO_1W__typ;
import LONGINT *WinApi_DOC_INFO_2A__typ;
import LONGINT *WinApi_DOC_INFO_2W__typ;
import LONGINT *WinApi_PRINTPROCESSOR_INFO_1A__typ;
import LONGINT *WinApi_PRINTPROCESSOR_INFO_1W__typ;
import LONGINT *WinApi_PORT_INFO_1A__typ;
import LONGINT *WinApi_PORT_INFO_1W__typ;
import LONGINT *WinApi_PORT_INFO_2A__typ;
import LONGINT *WinApi_PORT_INFO_2W__typ;
import LONGINT *WinApi_MONITOR_INFO_1A__typ;
import LONGINT *WinApi_MONITOR_INFO_1W__typ;
import LONGINT *WinApi_MONITOR_INFO_2A__typ;
import LONGINT *WinApi_MONITOR_INFO_2W__typ;
import LONGINT *WinApi_DATATYPES_INFO_1A__typ;
import LONGINT *WinApi_DATATYPES_INFO_1W__typ;
import LONGINT *WinApi_PRINTER_DEFAULTSA__typ;
import LONGINT *WinApi_PRINTER_DEFAULTSW__typ;
import LONGINT *WinApi_PRINTER_NOTIFY_OPTIONS_TYPE__typ;
import LONGINT *WinApi_PRINTER_NOTIFY_OPTIONS__typ;
import LONGINT *WinApi__28__typ;
import LONGINT *WinApi__29__typ;
import LONGINT *WinApi_PRINTER_NOTIFY_INFO_DATA__typ;
import LONGINT *WinApi_PRINTER_NOTIFY_INFO__typ;
import LONGINT *WinApi_PROVIDOR_INFO_1A__typ;
import LONGINT *WinApi_PROVIDOR_INFO_1W__typ;
import LONGINT *WinApi_SERVICE_STATUS__typ;
import LONGINT *WinApi_ENUM_SERVICE_STATUSA__typ;
import LONGINT *WinApi_ENUM_SERVICE_STATUSW__typ;
import LONGINT *WinApi_QUERY_SERVICE_LOCK_STATUSA__typ;
import LONGINT *WinApi_QUERY_SERVICE_LOCK_STATUSW__typ;
import LONGINT *WinApi_QUERY_SERVICE_CONFIGA__typ;
import LONGINT *WinApi_QUERY_SERVICE_CONFIGW__typ;
import LONGINT *WinApi_SERVICE_TABLE_ENTRYA__typ;
import LONGINT *WinApi_SERVICE_TABLE_ENTRYW__typ;
import LONGINT *WinApi_MODEMDEVCAPS__typ;
import LONGINT *WinApi_MODEMSETTINGS__typ;

import void *WinApi__init(void);

#define WinApi_AbortDoc(p0)	AbortDoc(p0)
__EXTERN INTEGER __CALL AbortDoc(INTEGER p0);
#define WinApi_AbortPath(p0)	AbortPath(p0)
__EXTERN INTEGER __CALL AbortPath(INTEGER p0);
#define WinApi_AbortPrinter(hPrinter)	AbortPrinter(hPrinter)
__EXTERN INTEGER __CALL AbortPrinter(INTEGER hPrinter);
#define WinApi_AbortSystemShutdown(lpMachineName)	AbortSystemShutdownA(lpMachineName)
#define WinApi_AbortSystemShutdownA(lpMachineName)	AbortSystemShutdownA(lpMachineName)
__EXTERN INTEGER __CALL AbortSystemShutdownA(WinApi_PtrSTR lpMachineName);
#define WinApi_AbortSystemShutdownW(lpMachineName)	AbortSystemShutdownW(lpMachineName)
__EXTERN INTEGER __CALL AbortSystemShutdownW(WinApi_PtrWSTR lpMachineName);
#define WinApi_AccessCheck(pSecurityDescriptor, ClientToken, DesiredAccess, GenericMapping, GenericMapping__typ, PrivilegeSet, PrivilegeSet__typ, PrivilegeSetLength, GrantedAccess, AccessStatus)	AccessCheck(pSecurityDescriptor, ClientToken, DesiredAccess, GenericMapping, PrivilegeSet, PrivilegeSetLength, GrantedAccess, AccessStatus)
__EXTERN INTEGER __CALL AccessCheck(INTEGER pSecurityDescriptor, INTEGER ClientToken, SET DesiredAccess, WinApi_GENERIC_MAPPING *GenericMapping, WinApi_PRIVILEGE_SET *PrivilegeSet, INTEGER *PrivilegeSetLength, INTEGER *GrantedAccess, INTEGER *AccessStatus);
#define WinApi_AccessCheckAndAuditAlarm(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, GenericMapping__typ, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)	AccessCheckAndAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)
#define WinApi_AccessCheckAndAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, GenericMapping__typ, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)	AccessCheckAndAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)
__EXTERN INTEGER __CALL AccessCheckAndAuditAlarmA(WinApi_PtrSTR SubsystemName, INTEGER HandleId, WinApi_PtrSTR ObjectTypeName, WinApi_PtrSTR ObjectName, INTEGER SecurityDescriptor, SET DesiredAccess, WinApi_GENERIC_MAPPING *GenericMapping, INTEGER ObjectCreation, INTEGER *GrantedAccess, INTEGER *AccessStatus, INTEGER *pfGenerateOnClose);
#define WinApi_AccessCheckAndAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, GenericMapping__typ, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)	AccessCheckAndAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)
__EXTERN INTEGER __CALL AccessCheckAndAuditAlarmW(WinApi_PtrWSTR SubsystemName, INTEGER HandleId, WinApi_PtrWSTR ObjectTypeName, WinApi_PtrWSTR ObjectName, INTEGER SecurityDescriptor, SET DesiredAccess, WinApi_GENERIC_MAPPING *GenericMapping, INTEGER ObjectCreation, INTEGER *GrantedAccess, INTEGER *AccessStatus, INTEGER *pfGenerateOnClose);
#define WinApi_ActivateKeyboardLayout(hkl, Flags)	ActivateKeyboardLayout(hkl, Flags)
__EXTERN INTEGER __CALL ActivateKeyboardLayout(INTEGER hkl, SET Flags);
#define WinApi_AddAccessAllowedAce(pAcl, pAcl__typ, dwAceRevision, AccessMask, pSid)	AddAccessAllowedAce(pAcl, dwAceRevision, AccessMask, pSid)
__EXTERN INTEGER __CALL AddAccessAllowedAce(WinApi_ACL *pAcl, INTEGER dwAceRevision, INTEGER AccessMask, INTEGER pSid);
#define WinApi_AddAccessDeniedAce(pAcl, pAcl__typ, dwAceRevision, AccessMask, pSid)	AddAccessDeniedAce(pAcl, dwAceRevision, AccessMask, pSid)
__EXTERN INTEGER __CALL AddAccessDeniedAce(WinApi_ACL *pAcl, INTEGER dwAceRevision, INTEGER AccessMask, INTEGER pSid);
#define WinApi_AddAce(pAcl, pAcl__typ, dwAceRevision, dwStartingAceIndex, pAceList, nAceListLength)	AddAce(pAcl, dwAceRevision, dwStartingAceIndex, pAceList, nAceListLength)
__EXTERN INTEGER __CALL AddAce(WinApi_ACL *pAcl, INTEGER dwAceRevision, INTEGER dwStartingAceIndex, INTEGER pAceList, INTEGER nAceListLength);
#define WinApi_AddAtom(lpString)	AddAtomA(lpString)
#define WinApi_AddAtomA(lpString)	AddAtomA(lpString)
__EXTERN SHORTINT __CALL AddAtomA(WinApi_PtrSTR lpString);
#define WinApi_AddAtomW(lpString)	AddAtomW(lpString)
__EXTERN SHORTINT __CALL AddAtomW(WinApi_PtrWSTR lpString);
#define WinApi_AddAuditAccessAce(pAcl, pAcl__typ, dwAceRevision, dwAccessMask, pSid, bAuditSuccess, bAuditFailure)	AddAuditAccessAce(pAcl, dwAceRevision, dwAccessMask, pSid, bAuditSuccess, bAuditFailure)
__EXTERN INTEGER __CALL AddAuditAccessAce(WinApi_ACL *pAcl, INTEGER dwAceRevision, INTEGER dwAccessMask, INTEGER pSid, INTEGER bAuditSuccess, INTEGER bAuditFailure);
#define WinApi_AddFontResource(p0)	AddFontResourceA(p0)
#define WinApi_AddFontResourceA(p0)	AddFontResourceA(p0)
__EXTERN INTEGER __CALL AddFontResourceA(WinApi_PtrSTR p0);
#define WinApi_AddFontResourceW(p0)	AddFontResourceW(p0)
__EXTERN INTEGER __CALL AddFontResourceW(WinApi_PtrWSTR p0);
#define WinApi_AddForm(hPrinter, Level, pForm)	AddFormA(hPrinter, Level, pForm)
#define WinApi_AddFormA(hPrinter, Level, pForm)	AddFormA(hPrinter, Level, pForm)
__EXTERN INTEGER __CALL AddFormA(INTEGER hPrinter, INTEGER Level, CHAR *pForm);
#define WinApi_AddFormW(hPrinter, Level, pForm)	AddFormW(hPrinter, Level, pForm)
__EXTERN INTEGER __CALL AddFormW(INTEGER hPrinter, INTEGER Level, CHAR *pForm);
#define WinApi_AddJob(hPrinter, Level, pData, cbBuf, pcbNeeded)	AddJobA(hPrinter, Level, pData, cbBuf, pcbNeeded)
#define WinApi_AddJobA(hPrinter, Level, pData, cbBuf, pcbNeeded)	AddJobA(hPrinter, Level, pData, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL AddJobA(INTEGER hPrinter, INTEGER Level, CHAR *pData, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_AddJobW(hPrinter, Level, pData, cbBuf, pcbNeeded)	AddJobW(hPrinter, Level, pData, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL AddJobW(INTEGER hPrinter, INTEGER Level, CHAR *pData, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_AddMonitor(pName, Level, pMonitors)	AddMonitorA(pName, Level, pMonitors)
#define WinApi_AddMonitorA(pName, Level, pMonitors)	AddMonitorA(pName, Level, pMonitors)
__EXTERN INTEGER __CALL AddMonitorA(WinApi_PtrSTR pName, INTEGER Level, CHAR *pMonitors);
#define WinApi_AddMonitorW(pName, Level, pMonitors)	AddMonitorW(pName, Level, pMonitors)
__EXTERN INTEGER __CALL AddMonitorW(WinApi_PtrWSTR pName, INTEGER Level, CHAR *pMonitors);
#define WinApi_AddPort(pName, hWnd, pMonitorName)	AddPortA(pName, hWnd, pMonitorName)
#define WinApi_AddPortA(pName, hWnd, pMonitorName)	AddPortA(pName, hWnd, pMonitorName)
__EXTERN INTEGER __CALL AddPortA(WinApi_PtrSTR pName, INTEGER hWnd, WinApi_PtrSTR pMonitorName);
#define WinApi_AddPortW(pName, hWnd, pMonitorName)	AddPortW(pName, hWnd, pMonitorName)
__EXTERN INTEGER __CALL AddPortW(WinApi_PtrWSTR pName, INTEGER hWnd, WinApi_PtrWSTR pMonitorName);
#define WinApi_AddPrintProcessor(pName, pEnvironment, pPathName, pPrintProcessorName)	AddPrintProcessorA(pName, pEnvironment, pPathName, pPrintProcessorName)
#define WinApi_AddPrintProcessorA(pName, pEnvironment, pPathName, pPrintProcessorName)	AddPrintProcessorA(pName, pEnvironment, pPathName, pPrintProcessorName)
__EXTERN INTEGER __CALL AddPrintProcessorA(WinApi_PtrSTR pName, WinApi_PtrSTR pEnvironment, WinApi_PtrSTR pPathName, WinApi_PtrSTR pPrintProcessorName);
#define WinApi_AddPrintProcessorW(pName, pEnvironment, pPathName, pPrintProcessorName)	AddPrintProcessorW(pName, pEnvironment, pPathName, pPrintProcessorName)
__EXTERN INTEGER __CALL AddPrintProcessorW(WinApi_PtrWSTR pName, WinApi_PtrWSTR pEnvironment, WinApi_PtrWSTR pPathName, WinApi_PtrWSTR pPrintProcessorName);
#define WinApi_AddPrintProvidor(pName, level, pProvidorInfo)	AddPrintProvidorA(pName, level, pProvidorInfo)
#define WinApi_AddPrintProvidorA(pName, level, pProvidorInfo)	AddPrintProvidorA(pName, level, pProvidorInfo)
__EXTERN INTEGER __CALL AddPrintProvidorA(WinApi_PtrSTR pName, INTEGER level, CHAR *pProvidorInfo);
#define WinApi_AddPrintProvidorW(pName, level, pProvidorInfo)	AddPrintProvidorW(pName, level, pProvidorInfo)
__EXTERN INTEGER __CALL AddPrintProvidorW(WinApi_PtrWSTR pName, INTEGER level, CHAR *pProvidorInfo);
#define WinApi_AddPrinter(pName, Level, pPrinter)	AddPrinterA(pName, Level, pPrinter)
#define WinApi_AddPrinterA(pName, Level, pPrinter)	AddPrinterA(pName, Level, pPrinter)
__EXTERN INTEGER __CALL AddPrinterA(WinApi_PtrSTR pName, INTEGER Level, CHAR *pPrinter);
#define WinApi_AddPrinterConnection(pName)	AddPrinterConnectionA(pName)
#define WinApi_AddPrinterConnectionA(pName)	AddPrinterConnectionA(pName)
__EXTERN INTEGER __CALL AddPrinterConnectionA(WinApi_PtrSTR pName);
#define WinApi_AddPrinterConnectionW(pName)	AddPrinterConnectionW(pName)
__EXTERN INTEGER __CALL AddPrinterConnectionW(WinApi_PtrWSTR pName);
#define WinApi_AddPrinterDriver(pName, Level, pDriverInfo)	AddPrinterDriverA(pName, Level, pDriverInfo)
#define WinApi_AddPrinterDriverA(pName, Level, pDriverInfo)	AddPrinterDriverA(pName, Level, pDriverInfo)
__EXTERN INTEGER __CALL AddPrinterDriverA(WinApi_PtrSTR pName, INTEGER Level, CHAR *pDriverInfo);
#define WinApi_AddPrinterDriverW(pName, Level, pDriverInfo)	AddPrinterDriverW(pName, Level, pDriverInfo)
__EXTERN INTEGER __CALL AddPrinterDriverW(WinApi_PtrWSTR pName, INTEGER Level, CHAR *pDriverInfo);
#define WinApi_AddPrinterW(pName, Level, pPrinter)	AddPrinterW(pName, Level, pPrinter)
__EXTERN INTEGER __CALL AddPrinterW(WinApi_PtrWSTR pName, INTEGER Level, CHAR *pPrinter);
#define WinApi_AdjustTokenGroups(TokenHandle, ResetToDefault, NewState, NewState__typ, BufferLength, PreviousState, PreviousState__typ, ReturnLength)	AdjustTokenGroups(TokenHandle, ResetToDefault, NewState, BufferLength, PreviousState, ReturnLength)
__EXTERN INTEGER __CALL AdjustTokenGroups(INTEGER TokenHandle, INTEGER ResetToDefault, WinApi_TOKEN_GROUPS *NewState, INTEGER BufferLength, WinApi_TOKEN_GROUPS *PreviousState, INTEGER *ReturnLength);
#define WinApi_AdjustTokenPrivileges(TokenHandle, DisableAllPrivileges, NewState, NewState__typ, BufferLength, PreviousState, PreviousState__typ, ReturnLength)	AdjustTokenPrivileges(TokenHandle, DisableAllPrivileges, NewState, BufferLength, PreviousState, ReturnLength)
__EXTERN INTEGER __CALL AdjustTokenPrivileges(INTEGER TokenHandle, INTEGER DisableAllPrivileges, WinApi_TOKEN_PRIVILEGES *NewState, INTEGER BufferLength, WinApi_TOKEN_PRIVILEGES *PreviousState, INTEGER *ReturnLength);
#define WinApi_AdjustWindowRect(lpRect, lpRect__typ, dwStyle, bMenu)	AdjustWindowRect(lpRect, dwStyle, bMenu)
__EXTERN INTEGER __CALL AdjustWindowRect(WinApi_RECT *lpRect, SET dwStyle, INTEGER bMenu);
#define WinApi_AdjustWindowRectEx(lpRect, lpRect__typ, dwStyle, bMenu, dwExStyle)	AdjustWindowRectEx(lpRect, dwStyle, bMenu, dwExStyle)
__EXTERN INTEGER __CALL AdjustWindowRectEx(WinApi_RECT *lpRect, SET dwStyle, INTEGER bMenu, SET dwExStyle);
#define WinApi_AdvancedDocumentProperties(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeOutput__typ, pDevModeInput, pDevModeInput__typ)	AdvancedDocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)
#define WinApi_AdvancedDocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeOutput__typ, pDevModeInput, pDevModeInput__typ)	AdvancedDocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)
__EXTERN INTEGER __CALL AdvancedDocumentPropertiesA(INTEGER hWnd, INTEGER hPrinter, WinApi_PtrSTR pDeviceName, WinApi_DEVMODEA *pDevModeOutput, WinApi_DEVMODEA *pDevModeInput);
#define WinApi_AdvancedDocumentPropertiesW(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeOutput__typ, pDevModeInput, pDevModeInput__typ)	AdvancedDocumentPropertiesW(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)
__EXTERN INTEGER __CALL AdvancedDocumentPropertiesW(INTEGER hWnd, INTEGER hPrinter, WinApi_PtrWSTR pDeviceName, WinApi_DEVMODEW *pDevModeOutput, WinApi_DEVMODEW *pDevModeInput);
#define WinApi_AllocConsole()	AllocConsole()
__EXTERN INTEGER __CALL AllocConsole(void);
#define WinApi_AllocateAndInitializeSid(pIdentifierAuthority, pIdentifierAuthority__typ, nSubAuthorityCount, nSubAuthority0, nSubAuthority1, nSubAuthority2, nSubAuthority3, nSubAuthority4, nSubAuthority5, nSubAuthority6, nSubAuthority7, pSid)	AllocateAndInitializeSid(pIdentifierAuthority, nSubAuthorityCount, nSubAuthority0, nSubAuthority1, nSubAuthority2, nSubAuthority3, nSubAuthority4, nSubAuthority5, nSubAuthority6, nSubAuthority7, pSid)
__EXTERN INTEGER __CALL AllocateAndInitializeSid(WinApi_SID_IDENTIFIER_AUTHORITY *pIdentifierAuthority, CHAR nSubAuthorityCount, INTEGER nSubAuthority0, INTEGER nSubAuthority1, INTEGER nSubAuthority2, INTEGER nSubAuthority3, INTEGER nSubAuthority4, INTEGER nSubAuthority5, INTEGER nSubAuthority6, INTEGER nSubAuthority7, INTEGER *pSid);
#define WinApi_AllocateLocallyUniqueId(Luid)	AllocateLocallyUniqueId(Luid)
__EXTERN INTEGER __CALL AllocateLocallyUniqueId(LONGINT *Luid);
#define WinApi_AngleArc(p0, p1, p2, p3, p4, p5)	AngleArc(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL AngleArc(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, REAL p4, REAL p5);
#define WinApi_AnimatePalette(p0, p1, p2, p3, p3__typ)	AnimatePalette(p0, p1, p2, p3)
__EXTERN INTEGER __CALL AnimatePalette(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_PALETTEENTRY *p3);
#define WinApi_AnsiLower(lpsz)	CharLowerA(lpsz)
#define WinApi_AnsiLowerBuff(lpsz, cchLength)	CharLowerBuffA(lpsz, cchLength)
#define WinApi_AnsiNext(lpsz)	CharNextA(lpsz)
#define WinApi_AnsiPrev(lpszStart, lpszCurrent)	CharPrevA(lpszStart, lpszCurrent)
#define WinApi_AnsiToOem(lpszSrc, lpszDst)	CharToOemA(lpszSrc, lpszDst)
#define WinApi_AnsiToOemBuff(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinApi_AnsiUpper(lpsz)	CharUpperA(lpsz)
#define WinApi_AnsiUpperBuff(lpsz, cchLength)	CharUpperBuffA(lpsz, cchLength)
#define WinApi_AnyPopup()	AnyPopup()
__EXTERN INTEGER __CALL AnyPopup(void);
#define WinApi_AppendMenu(hMenu, uFlags, uIDNewItem, lpNewItem)	AppendMenuA(hMenu, uFlags, uIDNewItem, lpNewItem)
#define WinApi_AppendMenuA(hMenu, uFlags, uIDNewItem, lpNewItem)	AppendMenuA(hMenu, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __CALL AppendMenuA(INTEGER hMenu, SET uFlags, INTEGER uIDNewItem, WinApi_PtrSTR lpNewItem);
#define WinApi_AppendMenuW(hMenu, uFlags, uIDNewItem, lpNewItem)	AppendMenuW(hMenu, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __CALL AppendMenuW(INTEGER hMenu, SET uFlags, INTEGER uIDNewItem, WinApi_PtrWSTR lpNewItem);
#define WinApi_Arc(p0, p1, p2, p3, p4, p5, p6, p7, p8)	Arc(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __CALL Arc(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinApi_ArcTo(p0, p1, p2, p3, p4, p5, p6, p7, p8)	ArcTo(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __CALL ArcTo(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinApi_AreAllAccessesGranted(GrantedAccess, DesiredAccess)	AreAllAccessesGranted(GrantedAccess, DesiredAccess)
__EXTERN INTEGER __CALL AreAllAccessesGranted(INTEGER GrantedAccess, SET DesiredAccess);
#define WinApi_AreAnyAccessesGranted(GrantedAccess, DesiredAccess)	AreAnyAccessesGranted(GrantedAccess, DesiredAccess)
__EXTERN INTEGER __CALL AreAnyAccessesGranted(INTEGER GrantedAccess, SET DesiredAccess);
#define WinApi_AreFileApisANSI()	AreFileApisANSI()
__EXTERN INTEGER __CALL AreFileApisANSI(void);
#define WinApi_ArrangeIconicWindows(hWnd)	ArrangeIconicWindows(hWnd)
__EXTERN INTEGER __CALL ArrangeIconicWindows(INTEGER hWnd);
#define WinApi_AttachThreadInput(idAttach, idAttachTo, fAttach)	AttachThreadInput(idAttach, idAttachTo, fAttach)
__EXTERN INTEGER __CALL AttachThreadInput(INTEGER idAttach, INTEGER idAttachTo, INTEGER fAttach);
#define WinApi_BackupEventLog(hEventLog, lpBackupFileName)	BackupEventLogA(hEventLog, lpBackupFileName)
#define WinApi_BackupEventLogA(hEventLog, lpBackupFileName)	BackupEventLogA(hEventLog, lpBackupFileName)
__EXTERN INTEGER __CALL BackupEventLogA(INTEGER hEventLog, WinApi_PtrSTR lpBackupFileName);
#define WinApi_BackupEventLogW(hEventLog, lpBackupFileName)	BackupEventLogW(hEventLog, lpBackupFileName)
__EXTERN INTEGER __CALL BackupEventLogW(INTEGER hEventLog, WinApi_PtrWSTR lpBackupFileName);
#define WinApi_BackupRead(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, bAbort, bProcessSecurity, lpContext)	BackupRead(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, bAbort, bProcessSecurity, lpContext)
__EXTERN INTEGER __CALL BackupRead(INTEGER hFile, CHAR *lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *lpNumberOfBytesRead, INTEGER bAbort, INTEGER bProcessSecurity, struct {
	LONGINT len[1];
	INTEGER data[1];
} *lpContext);
#define WinApi_BackupSeek(hFile, dwLowBytesToSeek, dwHighBytesToSeek, lpdwLowByteSeeked, lpdwHighByteSeeked, lpContext)	BackupSeek(hFile, dwLowBytesToSeek, dwHighBytesToSeek, lpdwLowByteSeeked, lpdwHighByteSeeked, lpContext)
__EXTERN INTEGER __CALL BackupSeek(INTEGER hFile, INTEGER dwLowBytesToSeek, INTEGER dwHighBytesToSeek, INTEGER *lpdwLowByteSeeked, INTEGER *lpdwHighByteSeeked, struct {
	LONGINT len[1];
	INTEGER data[1];
} *lpContext);
#define WinApi_BackupWrite(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, bAbort, bProcessSecurity, lpContext)	BackupWrite(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, bAbort, bProcessSecurity, lpContext)
__EXTERN INTEGER __CALL BackupWrite(INTEGER hFile, CHAR *lpBuffer, INTEGER nNumberOfBytesToWrite, INTEGER *lpNumberOfBytesWritten, INTEGER bAbort, INTEGER bProcessSecurity, struct {
	LONGINT len[1];
	INTEGER data[1];
} *lpContext);
#define WinApi_Beep(dwFreq, dwDuration)	Beep(dwFreq, dwDuration)
__EXTERN INTEGER __CALL Beep(INTEGER dwFreq, INTEGER dwDuration);
#define WinApi_BeginDeferWindowPos(nNumWindows)	BeginDeferWindowPos(nNumWindows)
__EXTERN INTEGER __CALL BeginDeferWindowPos(INTEGER nNumWindows);
#define WinApi_BeginPaint(hWnd, lpPaint, lpPaint__typ)	BeginPaint(hWnd, lpPaint)
__EXTERN INTEGER __CALL BeginPaint(INTEGER hWnd, WinApi_PAINTSTRUCT *lpPaint);
#define WinApi_BeginPath(p0)	BeginPath(p0)
__EXTERN INTEGER __CALL BeginPath(INTEGER p0);
#define WinApi_BeginUpdateResource(pFileName, bDeleteExistingResources)	BeginUpdateResourceA(pFileName, bDeleteExistingResources)
#define WinApi_BeginUpdateResourceA(pFileName, bDeleteExistingResources)	BeginUpdateResourceA(pFileName, bDeleteExistingResources)
__EXTERN INTEGER __CALL BeginUpdateResourceA(WinApi_PtrSTR pFileName, INTEGER bDeleteExistingResources);
#define WinApi_BeginUpdateResourceW(pFileName, bDeleteExistingResources)	BeginUpdateResourceW(pFileName, bDeleteExistingResources)
__EXTERN INTEGER __CALL BeginUpdateResourceW(WinApi_PtrWSTR pFileName, INTEGER bDeleteExistingResources);
#define WinApi_BitBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8)	BitBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __CALL BitBlt(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinApi_BringWindowToTop(hWnd)	BringWindowToTop(hWnd)
__EXTERN INTEGER __CALL BringWindowToTop(INTEGER hWnd);
#define WinApi_BroadcastSystemMessage(p0, p1, p2, p3, p4)	BroadcastSystemMessageA(p0, p1, p2, p3, p4)
#define WinApi_BroadcastSystemMessageA(p0, p1, p2, p3, p4)	BroadcastSystemMessageA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL BroadcastSystemMessageA(SET p0, SET *p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_BroadcastSystemMessageW(p0, p1, p2, p3, p4)	BroadcastSystemMessageW(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL BroadcastSystemMessageW(SET p0, SET *p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_BuildCommDCB(lpDef, lpDCB, lpDCB__typ)	BuildCommDCBA(lpDef, lpDCB)
#define WinApi_BuildCommDCBA(lpDef, lpDCB, lpDCB__typ)	BuildCommDCBA(lpDef, lpDCB)
__EXTERN INTEGER __CALL BuildCommDCBA(WinApi_PtrSTR lpDef, WinApi_DCB *lpDCB);
#define WinApi_BuildCommDCBAndTimeouts(lpDef, lpDCB, lpDCB__typ, lpCommTimeouts, lpCommTimeouts__typ)	BuildCommDCBAndTimeoutsA(lpDef, lpDCB, lpCommTimeouts)
#define WinApi_BuildCommDCBAndTimeoutsA(lpDef, lpDCB, lpDCB__typ, lpCommTimeouts, lpCommTimeouts__typ)	BuildCommDCBAndTimeoutsA(lpDef, lpDCB, lpCommTimeouts)
__EXTERN INTEGER __CALL BuildCommDCBAndTimeoutsA(WinApi_PtrSTR lpDef, WinApi_DCB *lpDCB, WinApi_COMMTIMEOUTS *lpCommTimeouts);
#define WinApi_BuildCommDCBAndTimeoutsW(lpDef, lpDCB, lpDCB__typ, lpCommTimeouts, lpCommTimeouts__typ)	BuildCommDCBAndTimeoutsW(lpDef, lpDCB, lpCommTimeouts)
__EXTERN INTEGER __CALL BuildCommDCBAndTimeoutsW(WinApi_PtrWSTR lpDef, WinApi_DCB *lpDCB, WinApi_COMMTIMEOUTS *lpCommTimeouts);
#define WinApi_BuildCommDCBW(lpDef, lpDCB, lpDCB__typ)	BuildCommDCBW(lpDef, lpDCB)
__EXTERN INTEGER __CALL BuildCommDCBW(WinApi_PtrWSTR lpDef, WinApi_DCB *lpDCB);
#define WinApi_CallMsgFilter(lpMsg, lpMsg__typ, nCode)	CallMsgFilterA(lpMsg, nCode)
#define WinApi_CallMsgFilterA(lpMsg, lpMsg__typ, nCode)	CallMsgFilterA(lpMsg, nCode)
__EXTERN INTEGER __CALL CallMsgFilterA(WinApi_MSG *lpMsg, INTEGER nCode);
#define WinApi_CallMsgFilterW(lpMsg, lpMsg__typ, nCode)	CallMsgFilterW(lpMsg, nCode)
__EXTERN INTEGER __CALL CallMsgFilterW(WinApi_MSG *lpMsg, INTEGER nCode);
#define WinApi_CallNamedPipe(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)	CallNamedPipeA(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)
#define WinApi_CallNamedPipeA(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)	CallNamedPipeA(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)
__EXTERN INTEGER __CALL CallNamedPipeA(WinApi_PtrSTR lpNamedPipeName, INTEGER lpInBuffer, INTEGER nInBufferSize, INTEGER lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, INTEGER nTimeOut);
#define WinApi_CallNamedPipeW(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)	CallNamedPipeW(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)
__EXTERN INTEGER __CALL CallNamedPipeW(WinApi_PtrWSTR lpNamedPipeName, INTEGER lpInBuffer, INTEGER nInBufferSize, INTEGER lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, INTEGER nTimeOut);
#define WinApi_CallNextHookEx(hhk, nCode, wParam, lParam)	CallNextHookEx(hhk, nCode, wParam, lParam)
__EXTERN INTEGER __CALL CallNextHookEx(INTEGER hhk, INTEGER nCode, INTEGER wParam, INTEGER lParam);
#define WinApi_CallWindowProc(lpPrevWndFunc, hWnd, Msg, wParam, lParam)	CallWindowProcA(lpPrevWndFunc, hWnd, Msg, wParam, lParam)
#define WinApi_CallWindowProcA(lpPrevWndFunc, hWnd, Msg, wParam, lParam)	CallWindowProcA(lpPrevWndFunc, hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL CallWindowProcA(WinApi_FARPROC lpPrevWndFunc, INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_CallWindowProcW(lpPrevWndFunc, hWnd, Msg, wParam, lParam)	CallWindowProcW(lpPrevWndFunc, hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL CallWindowProcW(WinApi_FARPROC lpPrevWndFunc, INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_CancelDC(p0)	CancelDC(p0)
__EXTERN INTEGER __CALL CancelDC(INTEGER p0);
#define WinApi_CancelWaitableTimer(hTimer)	CancelWaitableTimer(hTimer)
__EXTERN INTEGER __CALL CancelWaitableTimer(INTEGER hTimer);
#define WinApi_CascadeWindows(hwndParent, wHow, lpRect, lpRect__typ, cKids, lpKids)	CascadeWindows(hwndParent, wHow, lpRect, cKids, lpKids)
__EXTERN SHORTINT __CALL CascadeWindows(INTEGER hwndParent, INTEGER wHow, WinApi_RECT *lpRect, INTEGER cKids, INTEGER *lpKids);
#define WinApi_ChangeClipboardChain(hWndRemove, hWndNewNext)	ChangeClipboardChain(hWndRemove, hWndNewNext)
__EXTERN INTEGER __CALL ChangeClipboardChain(INTEGER hWndRemove, INTEGER hWndNewNext);
#define WinApi_ChangeDisplaySettings(lpDevMode, lpDevMode__typ, dwFlags)	ChangeDisplaySettingsA(lpDevMode, dwFlags)
#define WinApi_ChangeDisplaySettingsA(lpDevMode, lpDevMode__typ, dwFlags)	ChangeDisplaySettingsA(lpDevMode, dwFlags)
__EXTERN INTEGER __CALL ChangeDisplaySettingsA(WinApi_DEVMODEA *lpDevMode, SET dwFlags);
#define WinApi_ChangeDisplaySettingsW(lpDevMode, lpDevMode__typ, dwFlags)	ChangeDisplaySettingsW(lpDevMode, dwFlags)
__EXTERN INTEGER __CALL ChangeDisplaySettingsW(WinApi_DEVMODEW *lpDevMode, SET dwFlags);
#define WinApi_ChangeMenu(hMenu, cmd, lpszNewItem, cmdInsert, flags)	ChangeMenuA(hMenu, cmd, lpszNewItem, cmdInsert, flags)
#define WinApi_ChangeMenuA(hMenu, cmd, lpszNewItem, cmdInsert, flags)	ChangeMenuA(hMenu, cmd, lpszNewItem, cmdInsert, flags)
__EXTERN INTEGER __CALL ChangeMenuA(INTEGER hMenu, INTEGER cmd, WinApi_PtrSTR lpszNewItem, INTEGER cmdInsert, SET flags);
#define WinApi_ChangeMenuW(hMenu, cmd, lpszNewItem, cmdInsert, flags)	ChangeMenuW(hMenu, cmd, lpszNewItem, cmdInsert, flags)
__EXTERN INTEGER __CALL ChangeMenuW(INTEGER hMenu, INTEGER cmd, WinApi_PtrWSTR lpszNewItem, INTEGER cmdInsert, SET flags);
#define WinApi_ChangeServiceConfig(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)	ChangeServiceConfigA(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)
#define WinApi_ChangeServiceConfigA(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)	ChangeServiceConfigA(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)
__EXTERN INTEGER __CALL ChangeServiceConfigA(INTEGER hService, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, WinApi_PtrSTR lpBinaryPathName, WinApi_PtrSTR lpLoadOrderGroup, INTEGER *lpdwTagId, WinApi_PtrSTR lpDependencies, WinApi_PtrSTR lpServiceStartName, WinApi_PtrSTR lpPassword, WinApi_PtrSTR lpDisplayName);
#define WinApi_ChangeServiceConfigW(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)	ChangeServiceConfigW(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)
__EXTERN INTEGER __CALL ChangeServiceConfigW(INTEGER hService, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, WinApi_PtrWSTR lpBinaryPathName, WinApi_PtrWSTR lpLoadOrderGroup, INTEGER *lpdwTagId, WinApi_PtrWSTR lpDependencies, WinApi_PtrWSTR lpServiceStartName, WinApi_PtrWSTR lpPassword, WinApi_PtrWSTR lpDisplayName);
#define WinApi_CharLower(lpsz)	CharLowerA(lpsz)
#define WinApi_CharLowerA(lpsz)	CharLowerA(lpsz)
__EXTERN WinApi_PtrSTR __CALL CharLowerA(WinApi_PtrSTR lpsz);
#define WinApi_CharLowerBuff(lpsz, cchLength)	CharLowerBuffA(lpsz, cchLength)
#define WinApi_CharLowerBuffA(lpsz, cchLength)	CharLowerBuffA(lpsz, cchLength)
__EXTERN INTEGER __CALL CharLowerBuffA(WinApi_PtrSTR lpsz, INTEGER cchLength);
#define WinApi_CharLowerBuffW(lpsz, cchLength)	CharLowerBuffW(lpsz, cchLength)
__EXTERN INTEGER __CALL CharLowerBuffW(WinApi_PtrWSTR lpsz, INTEGER cchLength);
#define WinApi_CharLowerW(lpsz)	CharLowerW(lpsz)
__EXTERN WinApi_PtrWSTR __CALL CharLowerW(WinApi_PtrWSTR lpsz);
#define WinApi_CharNext(lpsz)	CharNextA(lpsz)
#define WinApi_CharNextA(lpsz)	CharNextA(lpsz)
__EXTERN WinApi_PtrSTR __CALL CharNextA(WinApi_PtrSTR lpsz);
#define WinApi_CharNextExA(CodePage, lpCurrentChar, dwFlags)	CharNextExA(CodePage, lpCurrentChar, dwFlags)
__EXTERN WinApi_PtrSTR __CALL CharNextExA(SHORTINT CodePage, WinApi_PtrSTR lpCurrentChar, SET dwFlags);
#define WinApi_CharNextW(lpsz)	CharNextW(lpsz)
__EXTERN WinApi_PtrWSTR __CALL CharNextW(WinApi_PtrWSTR lpsz);
#define WinApi_CharPrev(lpszStart, lpszCurrent)	CharPrevA(lpszStart, lpszCurrent)
#define WinApi_CharPrevA(lpszStart, lpszCurrent)	CharPrevA(lpszStart, lpszCurrent)
__EXTERN WinApi_PtrSTR __CALL CharPrevA(WinApi_PtrSTR lpszStart, WinApi_PtrSTR lpszCurrent);
#define WinApi_CharPrevExA(CodePage, lpStart, lpCurrentChar, dwFlags)	CharPrevExA(CodePage, lpStart, lpCurrentChar, dwFlags)
__EXTERN WinApi_PtrSTR __CALL CharPrevExA(SHORTINT CodePage, WinApi_PtrSTR lpStart, WinApi_PtrSTR lpCurrentChar, SET dwFlags);
#define WinApi_CharPrevW(lpszStart, lpszCurrent)	CharPrevW(lpszStart, lpszCurrent)
__EXTERN WinApi_PtrWSTR __CALL CharPrevW(WinApi_PtrWSTR lpszStart, WinApi_PtrWSTR lpszCurrent);
#define WinApi_CharToOem(lpszSrc, lpszDst)	CharToOemA(lpszSrc, lpszDst)
#define WinApi_CharToOemA(lpszSrc, lpszDst)	CharToOemA(lpszSrc, lpszDst)
__EXTERN INTEGER __CALL CharToOemA(WinApi_PtrSTR lpszSrc, WinApi_PtrSTR lpszDst);
#define WinApi_CharToOemBuff(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinApi_CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __CALL CharToOemBuffA(WinApi_PtrSTR lpszSrc, WinApi_PtrSTR lpszDst, INTEGER cchDstLength);
#define WinApi_CharToOemBuffW(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffW(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __CALL CharToOemBuffW(WinApi_PtrWSTR lpszSrc, WinApi_PtrSTR lpszDst, INTEGER cchDstLength);
#define WinApi_CharToOemW(lpszSrc, lpszDst)	CharToOemW(lpszSrc, lpszDst)
__EXTERN INTEGER __CALL CharToOemW(WinApi_PtrWSTR lpszSrc, WinApi_PtrSTR lpszDst);
#define WinApi_CharUpper(lpsz)	CharUpperA(lpsz)
#define WinApi_CharUpperA(lpsz)	CharUpperA(lpsz)
__EXTERN WinApi_PtrSTR __CALL CharUpperA(WinApi_PtrSTR lpsz);
#define WinApi_CharUpperBuff(lpsz, cchLength)	CharUpperBuffA(lpsz, cchLength)
#define WinApi_CharUpperBuffA(lpsz, cchLength)	CharUpperBuffA(lpsz, cchLength)
__EXTERN INTEGER __CALL CharUpperBuffA(WinApi_PtrSTR lpsz, INTEGER cchLength);
#define WinApi_CharUpperBuffW(lpsz, cchLength)	CharUpperBuffW(lpsz, cchLength)
__EXTERN INTEGER __CALL CharUpperBuffW(WinApi_PtrWSTR lpsz, INTEGER cchLength);
#define WinApi_CharUpperW(lpsz)	CharUpperW(lpsz)
__EXTERN WinApi_PtrWSTR __CALL CharUpperW(WinApi_PtrWSTR lpsz);
#define WinApi_CheckColorsInGamut(p0, p1, p2, p3)	CheckColorsInGamut(p0, p1, p2, p3)
__EXTERN INTEGER __CALL CheckColorsInGamut(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinApi_CheckDlgButton(hDlg, nIDButton, uCheck)	CheckDlgButton(hDlg, nIDButton, uCheck)
__EXTERN INTEGER __CALL CheckDlgButton(INTEGER hDlg, INTEGER nIDButton, SET uCheck);
#define WinApi_CheckMenuItem(hMenu, uIDCheckItem, uCheck)	CheckMenuItem(hMenu, uIDCheckItem, uCheck)
__EXTERN INTEGER __CALL CheckMenuItem(INTEGER hMenu, INTEGER uIDCheckItem, SET uCheck);
#define WinApi_CheckMenuRadioItem(p0, p1, p2, p3, p4)	CheckMenuRadioItem(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL CheckMenuRadioItem(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_CheckRadioButton(hDlg, nIDFirstButton, nIDLastButton, nIDCheckButton)	CheckRadioButton(hDlg, nIDFirstButton, nIDLastButton, nIDCheckButton)
__EXTERN INTEGER __CALL CheckRadioButton(INTEGER hDlg, INTEGER nIDFirstButton, INTEGER nIDLastButton, INTEGER nIDCheckButton);
#define WinApi_ChildWindowFromPoint(hWndParent, Point)	ChildWindowFromPoint(hWndParent, Point)
__EXTERN INTEGER __CALL ChildWindowFromPoint(INTEGER hWndParent, WinApi_POINT Point);
#define WinApi_ChildWindowFromPointEx(p0, p1, p2)	ChildWindowFromPointEx(p0, p1, p2)
__EXTERN INTEGER __CALL ChildWindowFromPointEx(INTEGER p0, WinApi_POINT p1, SET p2);
#define WinApi_ChoosePixelFormat(p0, p1, p1__typ)	ChoosePixelFormat(p0, p1)
__EXTERN INTEGER __CALL ChoosePixelFormat(INTEGER p0, WinApi_PIXELFORMATDESCRIPTOR *p1);
#define WinApi_Chord(p0, p1, p2, p3, p4, p5, p6, p7, p8)	Chord(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __CALL Chord(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinApi_ClearCommBreak(hFile)	ClearCommBreak(hFile)
__EXTERN INTEGER __CALL ClearCommBreak(INTEGER hFile);
#define WinApi_ClearCommError(hFile, lpErrors, lpStat, lpStat__typ)	ClearCommError(hFile, lpErrors, lpStat)
__EXTERN INTEGER __CALL ClearCommError(INTEGER hFile, SET *lpErrors, WinApi_COMSTAT *lpStat);
#define WinApi_ClearEventLog(hEventLog, lpBackupFileName)	ClearEventLogA(hEventLog, lpBackupFileName)
#define WinApi_ClearEventLogA(hEventLog, lpBackupFileName)	ClearEventLogA(hEventLog, lpBackupFileName)
__EXTERN INTEGER __CALL ClearEventLogA(INTEGER hEventLog, WinApi_PtrSTR lpBackupFileName);
#define WinApi_ClearEventLogW(hEventLog, lpBackupFileName)	ClearEventLogW(hEventLog, lpBackupFileName)
__EXTERN INTEGER __CALL ClearEventLogW(INTEGER hEventLog, WinApi_PtrWSTR lpBackupFileName);
#define WinApi_ClientToScreen(hWnd, lpPoint, lpPoint__typ)	ClientToScreen(hWnd, lpPoint)
__EXTERN INTEGER __CALL ClientToScreen(INTEGER hWnd, WinApi_POINT *lpPoint);
#define WinApi_ClipCursor(lpRect, lpRect__typ)	ClipCursor(lpRect)
__EXTERN INTEGER __CALL ClipCursor(WinApi_RECT *lpRect);
#define WinApi_CloseClipboard()	CloseClipboard()
__EXTERN INTEGER __CALL CloseClipboard(void);
#define WinApi_CloseDesktop(hDesktop)	CloseDesktop(hDesktop)
__EXTERN INTEGER __CALL CloseDesktop(INTEGER hDesktop);
#define WinApi_CloseEnhMetaFile(p0)	CloseEnhMetaFile(p0)
__EXTERN INTEGER __CALL CloseEnhMetaFile(INTEGER p0);
#define WinApi_CloseEventLog(hEventLog)	CloseEventLog(hEventLog)
__EXTERN INTEGER __CALL CloseEventLog(INTEGER hEventLog);
#define WinApi_CloseFigure(p0)	CloseFigure(p0)
__EXTERN INTEGER __CALL CloseFigure(INTEGER p0);
#define WinApi_CloseHandle(hObject)	CloseHandle(hObject)
__EXTERN INTEGER __CALL CloseHandle(INTEGER hObject);
#define WinApi_CloseMetaFile(p0)	CloseMetaFile(p0)
__EXTERN INTEGER __CALL CloseMetaFile(INTEGER p0);
#define WinApi_ClosePrinter(hPrinter)	ClosePrinter(hPrinter)
__EXTERN INTEGER __CALL ClosePrinter(INTEGER hPrinter);
#define WinApi_CloseServiceHandle(hSCObject)	CloseServiceHandle(hSCObject)
__EXTERN INTEGER __CALL CloseServiceHandle(INTEGER hSCObject);
#define WinApi_CloseWindow(hWnd)	CloseWindow(hWnd)
__EXTERN INTEGER __CALL CloseWindow(INTEGER hWnd);
#define WinApi_CloseWindowStation(hWinSta)	CloseWindowStation(hWinSta)
__EXTERN INTEGER __CALL CloseWindowStation(INTEGER hWinSta);
#define WinApi_ColorMatchToTarget(p0, p1, p2)	ColorMatchToTarget(p0, p1, p2)
__EXTERN INTEGER __CALL ColorMatchToTarget(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_CombineRgn(p0, p1, p2, p3)	CombineRgn(p0, p1, p2, p3)
__EXTERN INTEGER __CALL CombineRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinApi_CombineTransform(p0, p0__typ, p1, p1__typ, p2, p2__typ)	CombineTransform(p0, p1, p2)
__EXTERN INTEGER __CALL CombineTransform(WinApi_XFORM *p0, WinApi_XFORM *p1, WinApi_XFORM *p2);
#define WinApi_CommConfigDialog(lpszName, hWnd, lpCC, lpCC__typ)	CommConfigDialogA(lpszName, hWnd, lpCC)
#define WinApi_CommConfigDialogA(lpszName, hWnd, lpCC, lpCC__typ)	CommConfigDialogA(lpszName, hWnd, lpCC)
__EXTERN INTEGER __CALL CommConfigDialogA(WinApi_PtrSTR lpszName, INTEGER hWnd, WinApi_COMMCONFIG *lpCC);
#define WinApi_CommConfigDialogW(lpszName, hWnd, lpCC, lpCC__typ)	CommConfigDialogW(lpszName, hWnd, lpCC)
__EXTERN INTEGER __CALL CommConfigDialogW(WinApi_PtrWSTR lpszName, INTEGER hWnd, WinApi_COMMCONFIG *lpCC);
#define WinApi_CommandLineToArgvW(lpCmdLine, pNumArgs)	CommandLineToArgvW(lpCmdLine, pNumArgs)
__EXTERN WinApi_RetCommandLineToArgvW __CALL CommandLineToArgvW(WinApi_PtrWSTR lpCmdLine, INTEGER *pNumArgs);
#define WinApi_CompareFileTime(lpFileTime1, lpFileTime1__typ, lpFileTime2, lpFileTime2__typ)	CompareFileTime(lpFileTime1, lpFileTime2)
__EXTERN INTEGER __CALL CompareFileTime(WinApi_FILETIME *lpFileTime1, WinApi_FILETIME *lpFileTime2);
#define WinApi_CompareString(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)	CompareStringA(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)
#define WinApi_CompareStringA(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)	CompareStringA(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)
__EXTERN INTEGER __CALL CompareStringA(INTEGER Locale, SET dwCmpFlags, WinApi_PtrSTR lpString1, INTEGER cchCount1, WinApi_PtrSTR lpString2, INTEGER cchCount2);
#define WinApi_CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)	CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)
__EXTERN INTEGER __CALL CompareStringW(INTEGER Locale, SET dwCmpFlags, WinApi_PtrWSTR lpString1, INTEGER cchCount1, WinApi_PtrWSTR lpString2, INTEGER cchCount2);
#define WinApi_ConfigurePort(pName, hWnd, pPortName)	ConfigurePortA(pName, hWnd, pPortName)
#define WinApi_ConfigurePortA(pName, hWnd, pPortName)	ConfigurePortA(pName, hWnd, pPortName)
__EXTERN INTEGER __CALL ConfigurePortA(WinApi_PtrSTR pName, INTEGER hWnd, WinApi_PtrSTR pPortName);
#define WinApi_ConfigurePortW(pName, hWnd, pPortName)	ConfigurePortW(pName, hWnd, pPortName)
__EXTERN INTEGER __CALL ConfigurePortW(WinApi_PtrWSTR pName, INTEGER hWnd, WinApi_PtrWSTR pPortName);
#define WinApi_ConnectNamedPipe(hNamedPipe, lpOverlapped, lpOverlapped__typ)	ConnectNamedPipe(hNamedPipe, lpOverlapped)
__EXTERN INTEGER __CALL ConnectNamedPipe(INTEGER hNamedPipe, WinApi_OVERLAPPED *lpOverlapped);
#define WinApi_ConnectToPrinterDlg(hwnd, Flags)	ConnectToPrinterDlg(hwnd, Flags)
__EXTERN INTEGER __CALL ConnectToPrinterDlg(INTEGER hwnd, SET Flags);
#define WinApi_ContinueDebugEvent(dwProcessId, dwThreadId, dwContinueStatus)	ContinueDebugEvent(dwProcessId, dwThreadId, dwContinueStatus)
__EXTERN INTEGER __CALL ContinueDebugEvent(INTEGER dwProcessId, INTEGER dwThreadId, SET dwContinueStatus);
#define WinApi_ControlService(hService, dwControl, lpServiceStatus, lpServiceStatus__typ)	ControlService(hService, dwControl, lpServiceStatus)
__EXTERN INTEGER __CALL ControlService(INTEGER hService, INTEGER dwControl, WinApi_SERVICE_STATUS *lpServiceStatus);
#define WinApi_ConvertDefaultLocale(Locale)	ConvertDefaultLocale(Locale)
__EXTERN INTEGER __CALL ConvertDefaultLocale(INTEGER Locale);
#define WinApi_ConvertThreadToFiber(lpParameter)	ConvertThreadToFiber(lpParameter)
__EXTERN INTEGER __CALL ConvertThreadToFiber(INTEGER lpParameter);
#define WinApi_CopyAcceleratorTable(hAccelSrc, lpAccelDst, lpAccelDst__typ, cAccelEntries)	CopyAcceleratorTableA(hAccelSrc, lpAccelDst, cAccelEntries)
#define WinApi_CopyAcceleratorTableA(hAccelSrc, lpAccelDst, lpAccelDst__typ, cAccelEntries)	CopyAcceleratorTableA(hAccelSrc, lpAccelDst, cAccelEntries)
__EXTERN INTEGER __CALL CopyAcceleratorTableA(INTEGER hAccelSrc, WinApi_ACCEL *lpAccelDst, INTEGER cAccelEntries);
#define WinApi_CopyAcceleratorTableW(hAccelSrc, lpAccelDst, lpAccelDst__typ, cAccelEntries)	CopyAcceleratorTableW(hAccelSrc, lpAccelDst, cAccelEntries)
__EXTERN INTEGER __CALL CopyAcceleratorTableW(INTEGER hAccelSrc, WinApi_ACCEL *lpAccelDst, INTEGER cAccelEntries);
#define WinApi_CopyEnhMetaFile(p0, p1)	CopyEnhMetaFileA(p0, p1)
#define WinApi_CopyEnhMetaFileA(p0, p1)	CopyEnhMetaFileA(p0, p1)
__EXTERN INTEGER __CALL CopyEnhMetaFileA(INTEGER p0, WinApi_PtrSTR p1);
#define WinApi_CopyEnhMetaFileW(p0, p1)	CopyEnhMetaFileW(p0, p1)
__EXTERN INTEGER __CALL CopyEnhMetaFileW(INTEGER p0, WinApi_PtrWSTR p1);
#define WinApi_CopyFile(lpExistingFileName, lpNewFileName, bFailIfExists)	CopyFileA(lpExistingFileName, lpNewFileName, bFailIfExists)
#define WinApi_CopyFileA(lpExistingFileName, lpNewFileName, bFailIfExists)	CopyFileA(lpExistingFileName, lpNewFileName, bFailIfExists)
__EXTERN INTEGER __CALL CopyFileA(WinApi_PtrSTR lpExistingFileName, WinApi_PtrSTR lpNewFileName, INTEGER bFailIfExists);
#define WinApi_CopyFileEx(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)	CopyFileExA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)
#define WinApi_CopyFileExA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)	CopyFileExA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)
__EXTERN INTEGER __CALL CopyFileExA(WinApi_PtrSTR lpExistingFileName, WinApi_PtrSTR lpNewFileName, WinApi_PROGRESS_ROUTINE lpProgressRoutine, INTEGER lpData, INTEGER *pbCancel, INTEGER dwCopyFlags);
#define WinApi_CopyFileExW(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)	CopyFileExW(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)
__EXTERN INTEGER __CALL CopyFileExW(WinApi_PtrWSTR lpExistingFileName, WinApi_PtrWSTR lpNewFileName, WinApi_PROGRESS_ROUTINE lpProgressRoutine, INTEGER lpData, INTEGER *pbCancel, INTEGER dwCopyFlags);
#define WinApi_CopyFileW(lpExistingFileName, lpNewFileName, bFailIfExists)	CopyFileW(lpExistingFileName, lpNewFileName, bFailIfExists)
__EXTERN INTEGER __CALL CopyFileW(WinApi_PtrWSTR lpExistingFileName, WinApi_PtrWSTR lpNewFileName, INTEGER bFailIfExists);
#define WinApi_CopyIcon(hIcon)	CopyIcon(hIcon)
__EXTERN INTEGER __CALL CopyIcon(INTEGER hIcon);
#define WinApi_CopyImage(p0, p1, p2, p3, p4)	CopyImage(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL CopyImage(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_CopyLZFile(p0, p1)	CopyLZFile(p0, p1)
__EXTERN INTEGER __CALL CopyLZFile(INTEGER p0, INTEGER p1);
#define WinApi_CopyMetaFile(p0, p1)	CopyMetaFileA(p0, p1)
#define WinApi_CopyMetaFileA(p0, p1)	CopyMetaFileA(p0, p1)
__EXTERN INTEGER __CALL CopyMetaFileA(INTEGER p0, WinApi_PtrSTR p1);
#define WinApi_CopyMetaFileW(p0, p1)	CopyMetaFileW(p0, p1)
__EXTERN INTEGER __CALL CopyMetaFileW(INTEGER p0, WinApi_PtrWSTR p1);
#define WinApi_CopyRect(lprcDst, lprcDst__typ, lprcSrc, lprcSrc__typ)	CopyRect(lprcDst, lprcSrc)
__EXTERN INTEGER __CALL CopyRect(WinApi_RECT *lprcDst, WinApi_RECT *lprcSrc);
#define WinApi_CopySid(nDestinationSidLength, pDestinationSid, pSourceSid)	CopySid(nDestinationSidLength, pDestinationSid, pSourceSid)
__EXTERN INTEGER __CALL CopySid(INTEGER nDestinationSidLength, INTEGER pDestinationSid, INTEGER pSourceSid);
#define WinApi_CountClipboardFormats()	CountClipboardFormats()
__EXTERN INTEGER __CALL CountClipboardFormats(void);
#define WinApi_CreateAcceleratorTable(p0, p0__typ, p1)	CreateAcceleratorTableA(p0, p1)
#define WinApi_CreateAcceleratorTableA(p0, p0__typ, p1)	CreateAcceleratorTableA(p0, p1)
__EXTERN INTEGER __CALL CreateAcceleratorTableA(WinApi_ACCEL *p0, INTEGER p1);
#define WinApi_CreateAcceleratorTableW(p0, p0__typ, p1)	CreateAcceleratorTableW(p0, p1)
__EXTERN INTEGER __CALL CreateAcceleratorTableW(WinApi_ACCEL *p0, INTEGER p1);
#define WinApi_CreateBitmap(p0, p1, p2, p3, p4)	CreateBitmap(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL CreateBitmap(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_CreateBitmapIndirect(p0, p0__typ)	CreateBitmapIndirect(p0)
__EXTERN INTEGER __CALL CreateBitmapIndirect(WinApi_BITMAP *p0);
#define WinApi_CreateBrushIndirect(p0, p0__typ)	CreateBrushIndirect(p0)
__EXTERN INTEGER __CALL CreateBrushIndirect(WinApi_LOGBRUSH *p0);
#define WinApi_CreateCaret(hWnd, hBitmap, nWidth, nHeight)	CreateCaret(hWnd, hBitmap, nWidth, nHeight)
__EXTERN INTEGER __CALL CreateCaret(INTEGER hWnd, INTEGER hBitmap, INTEGER nWidth, INTEGER nHeight);
#define WinApi_CreateColorSpace(p0, p0__typ)	CreateColorSpaceA(p0)
#define WinApi_CreateColorSpaceA(p0, p0__typ)	CreateColorSpaceA(p0)
__EXTERN INTEGER __CALL CreateColorSpaceA(WinApi_LOGCOLORSPACEA *p0);
#define WinApi_CreateColorSpaceW(p0, p0__typ)	CreateColorSpaceW(p0)
__EXTERN INTEGER __CALL CreateColorSpaceW(WinApi_LOGCOLORSPACEW *p0);
#define WinApi_CreateCompatibleBitmap(p0, p1, p2)	CreateCompatibleBitmap(p0, p1, p2)
__EXTERN INTEGER __CALL CreateCompatibleBitmap(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_CreateCompatibleDC(p0)	CreateCompatibleDC(p0)
__EXTERN INTEGER __CALL CreateCompatibleDC(INTEGER p0);
#define WinApi_CreateConsoleScreenBuffer(dwDesiredAccess, dwShareMode, lpSecurityAttributes, lpSecurityAttributes__typ, dwFlags, lpScreenBufferData)	CreateConsoleScreenBuffer(dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwFlags, lpScreenBufferData)
__EXTERN INTEGER __CALL CreateConsoleScreenBuffer(SET dwDesiredAccess, SET dwShareMode, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes, SET dwFlags, INTEGER lpScreenBufferData);
#define WinApi_CreateCursor(hInst, xHotSpot, yHotSpot, nWidth, nHeight, pvANDPlane, pvXORPlane)	CreateCursor(hInst, xHotSpot, yHotSpot, nWidth, nHeight, pvANDPlane, pvXORPlane)
__EXTERN INTEGER __CALL CreateCursor(INTEGER hInst, INTEGER xHotSpot, INTEGER yHotSpot, INTEGER nWidth, INTEGER nHeight, INTEGER pvANDPlane, INTEGER pvXORPlane);
#define WinApi_CreateDC(p0, p1, p2, p3, p3__typ)	CreateDCA(p0, p1, p2, p3)
#define WinApi_CreateDCA(p0, p1, p2, p3, p3__typ)	CreateDCA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL CreateDCA(WinApi_PtrSTR p0, WinApi_PtrSTR p1, WinApi_PtrSTR p2, WinApi_DEVMODEA *p3);
#define WinApi_CreateDCW(p0, p1, p2, p3, p3__typ)	CreateDCW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL CreateDCW(WinApi_PtrWSTR p0, WinApi_PtrWSTR p1, WinApi_PtrWSTR p2, WinApi_DEVMODEW *p3);
#define WinApi_CreateDIBPatternBrush(p0, p1)	CreateDIBPatternBrush(p0, p1)
__EXTERN INTEGER __CALL CreateDIBPatternBrush(INTEGER p0, INTEGER p1);
#define WinApi_CreateDIBPatternBrushPt(p0, p1)	CreateDIBPatternBrushPt(p0, p1)
__EXTERN INTEGER __CALL CreateDIBPatternBrushPt(INTEGER p0, INTEGER p1);
#define WinApi_CreateDIBSection(p0, p1, p1__typ, p2, p3, p4, p5)	CreateDIBSection(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL CreateDIBSection(INTEGER p0, WinApi_BITMAPINFO *p1, INTEGER p2, INTEGER *p3, INTEGER p4, INTEGER p5);
#define WinApi_CreateDIBitmap(p0, p1, p1__typ, p2, p3, p4, p4__typ, p5)	CreateDIBitmap(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL CreateDIBitmap(INTEGER p0, WinApi_BITMAPINFOHEADER *p1, INTEGER p2, INTEGER p3, WinApi_BITMAPINFO *p4, INTEGER p5);
#define WinApi_CreateDesktop(lpszDesktop, lpszDevice, pDevmode, pDevmode__typ, dwFlags, dwDesiredAccess, lpsa, lpsa__typ)	CreateDesktopA(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)
#define WinApi_CreateDesktopA(lpszDesktop, lpszDevice, pDevmode, pDevmode__typ, dwFlags, dwDesiredAccess, lpsa, lpsa__typ)	CreateDesktopA(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)
__EXTERN INTEGER __CALL CreateDesktopA(WinApi_PtrSTR lpszDesktop, WinApi_PtrSTR lpszDevice, WinApi_DEVMODEA *pDevmode, SET dwFlags, SET dwDesiredAccess, WinApi_SECURITY_ATTRIBUTES *lpsa);
#define WinApi_CreateDesktopW(lpszDesktop, lpszDevice, pDevmode, pDevmode__typ, dwFlags, dwDesiredAccess, lpsa, lpsa__typ)	CreateDesktopW(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)
__EXTERN INTEGER __CALL CreateDesktopW(WinApi_PtrWSTR lpszDesktop, WinApi_PtrWSTR lpszDevice, WinApi_DEVMODEW *pDevmode, SET dwFlags, SET dwDesiredAccess, WinApi_SECURITY_ATTRIBUTES *lpsa);
#define WinApi_CreateDialogIndirectParam(hInstance, lpTemplate, lpTemplate__typ, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogIndirectParamA(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)
#define WinApi_CreateDialogIndirectParamA(hInstance, lpTemplate, lpTemplate__typ, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogIndirectParamA(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL CreateDialogIndirectParamA(INTEGER hInstance, WinApi_DLGTEMPLATE *lpTemplate, INTEGER hWndParent, WinApi_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinApi_CreateDialogIndirectParamW(hInstance, lpTemplate, lpTemplate__typ, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogIndirectParamW(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL CreateDialogIndirectParamW(INTEGER hInstance, WinApi_DLGTEMPLATE *lpTemplate, INTEGER hWndParent, WinApi_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinApi_CreateDialogParam(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
#define WinApi_CreateDialogParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL CreateDialogParamA(INTEGER hInstance, WinApi_PtrSTR lpTemplateName, INTEGER hWndParent, WinApi_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinApi_CreateDialogParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL CreateDialogParamW(INTEGER hInstance, WinApi_PtrWSTR lpTemplateName, INTEGER hWndParent, WinApi_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinApi_CreateDirectory(lpPathName, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateDirectoryA(lpPathName, lpSecurityAttributes)
#define WinApi_CreateDirectoryA(lpPathName, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateDirectoryA(lpPathName, lpSecurityAttributes)
__EXTERN INTEGER __CALL CreateDirectoryA(WinApi_PtrSTR lpPathName, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinApi_CreateDirectoryEx(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateDirectoryExA(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)
#define WinApi_CreateDirectoryExA(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateDirectoryExA(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)
__EXTERN INTEGER __CALL CreateDirectoryExA(WinApi_PtrSTR lpTemplateDirectory, WinApi_PtrSTR lpNewDirectory, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinApi_CreateDirectoryExW(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateDirectoryExW(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)
__EXTERN INTEGER __CALL CreateDirectoryExW(WinApi_PtrWSTR lpTemplateDirectory, WinApi_PtrWSTR lpNewDirectory, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinApi_CreateDirectoryW(lpPathName, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateDirectoryW(lpPathName, lpSecurityAttributes)
__EXTERN INTEGER __CALL CreateDirectoryW(WinApi_PtrWSTR lpPathName, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinApi_CreateDiscardableBitmap(p0, p1, p2)	CreateDiscardableBitmap(p0, p1, p2)
__EXTERN INTEGER __CALL CreateDiscardableBitmap(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_CreateEllipticRgn(p0, p1, p2, p3)	CreateEllipticRgn(p0, p1, p2, p3)
__EXTERN INTEGER __CALL CreateEllipticRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinApi_CreateEllipticRgnIndirect(p0, p0__typ)	CreateEllipticRgnIndirect(p0)
__EXTERN INTEGER __CALL CreateEllipticRgnIndirect(WinApi_RECT *p0);
#define WinApi_CreateEnhMetaFile(p0, p1, p2, p2__typ, p3)	CreateEnhMetaFileA(p0, p1, p2, p3)
#define WinApi_CreateEnhMetaFileA(p0, p1, p2, p2__typ, p3)	CreateEnhMetaFileA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL CreateEnhMetaFileA(INTEGER p0, WinApi_PtrSTR p1, WinApi_RECT *p2, WinApi_PtrSTR p3);
#define WinApi_CreateEnhMetaFileW(p0, p1, p2, p2__typ, p3)	CreateEnhMetaFileW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL CreateEnhMetaFileW(INTEGER p0, WinApi_PtrWSTR p1, WinApi_RECT *p2, WinApi_PtrWSTR p3);
#define WinApi_CreateEvent(lpEventAttributes, lpEventAttributes__typ, bManualReset, bInitialState, lpName)	CreateEventA(lpEventAttributes, bManualReset, bInitialState, lpName)
#define WinApi_CreateEventA(lpEventAttributes, lpEventAttributes__typ, bManualReset, bInitialState, lpName)	CreateEventA(lpEventAttributes, bManualReset, bInitialState, lpName)
__EXTERN INTEGER __CALL CreateEventA(WinApi_SECURITY_ATTRIBUTES *lpEventAttributes, INTEGER bManualReset, INTEGER bInitialState, WinApi_PtrSTR lpName);
#define WinApi_CreateEventW(lpEventAttributes, lpEventAttributes__typ, bManualReset, bInitialState, lpName)	CreateEventW(lpEventAttributes, bManualReset, bInitialState, lpName)
__EXTERN INTEGER __CALL CreateEventW(WinApi_SECURITY_ATTRIBUTES *lpEventAttributes, INTEGER bManualReset, INTEGER bInitialState, WinApi_PtrWSTR lpName);
#define WinApi_CreateFiber(dwStackSize, lpStartAddress, lpParameter)	CreateFiber(dwStackSize, lpStartAddress, lpParameter)
__EXTERN INTEGER __CALL CreateFiber(INTEGER dwStackSize, WinApi_FIBER_START_ROUTINE lpStartAddress, INTEGER lpParameter);
#define WinApi_CreateFile(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, lpSecurityAttributes__typ, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)	CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)
#define WinApi_CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, lpSecurityAttributes__typ, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)	CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)
__EXTERN INTEGER __CALL CreateFileA(WinApi_PtrSTR lpFileName, SET dwDesiredAccess, SET dwShareMode, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER dwCreationDisposition, SET dwFlagsAndAttributes, INTEGER hTemplateFile);
#define WinApi_CreateFileMapping(hFile, lpFileMappingAttributes, lpFileMappingAttributes__typ, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)	CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)
#define WinApi_CreateFileMappingA(hFile, lpFileMappingAttributes, lpFileMappingAttributes__typ, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)	CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)
__EXTERN INTEGER __CALL CreateFileMappingA(INTEGER hFile, WinApi_SECURITY_ATTRIBUTES *lpFileMappingAttributes, SET flProtect, INTEGER dwMaximumSizeHigh, INTEGER dwMaximumSizeLow, WinApi_PtrSTR lpName);
#define WinApi_CreateFileMappingW(hFile, lpFileMappingAttributes, lpFileMappingAttributes__typ, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)	CreateFileMappingW(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)
__EXTERN INTEGER __CALL CreateFileMappingW(INTEGER hFile, WinApi_SECURITY_ATTRIBUTES *lpFileMappingAttributes, SET flProtect, INTEGER dwMaximumSizeHigh, INTEGER dwMaximumSizeLow, WinApi_PtrWSTR lpName);
#define WinApi_CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, lpSecurityAttributes__typ, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)	CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)
__EXTERN INTEGER __CALL CreateFileW(WinApi_PtrWSTR lpFileName, SET dwDesiredAccess, SET dwShareMode, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER dwCreationDisposition, SET dwFlagsAndAttributes, INTEGER hTemplateFile);
#define WinApi_CreateFont(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)	CreateFontA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)
#define WinApi_CreateFontA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)	CreateFontA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)
__EXTERN INTEGER __CALL CreateFontA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10, INTEGER p11, INTEGER p12, WinApi_PtrSTR p13);
#define WinApi_CreateFontIndirect(p0, p0__typ)	CreateFontIndirectA(p0)
#define WinApi_CreateFontIndirectA(p0, p0__typ)	CreateFontIndirectA(p0)
__EXTERN INTEGER __CALL CreateFontIndirectA(WinApi_LOGFONTA *p0);
#define WinApi_CreateFontIndirectW(p0, p0__typ)	CreateFontIndirectW(p0)
__EXTERN INTEGER __CALL CreateFontIndirectW(WinApi_LOGFONTW *p0);
#define WinApi_CreateFontW(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)	CreateFontW(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)
__EXTERN INTEGER __CALL CreateFontW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10, INTEGER p11, INTEGER p12, WinApi_PtrWSTR p13);
#define WinApi_CreateHalftonePalette(p0)	CreateHalftonePalette(p0)
__EXTERN INTEGER __CALL CreateHalftonePalette(INTEGER p0);
#define WinApi_CreateHatchBrush(p0, p1)	CreateHatchBrush(p0, p1)
__EXTERN INTEGER __CALL CreateHatchBrush(INTEGER p0, INTEGER p1);
#define WinApi_CreateIC(p0, p1, p2, p3, p3__typ)	CreateICA(p0, p1, p2, p3)
#define WinApi_CreateICA(p0, p1, p2, p3, p3__typ)	CreateICA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL CreateICA(WinApi_PtrSTR p0, WinApi_PtrSTR p1, WinApi_PtrSTR p2, WinApi_DEVMODEA *p3);
#define WinApi_CreateICW(p0, p1, p2, p3, p3__typ)	CreateICW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL CreateICW(WinApi_PtrWSTR p0, WinApi_PtrWSTR p1, WinApi_PtrWSTR p2, WinApi_DEVMODEW *p3);
#define WinApi_CreateIcon(hInstance, nWidth, nHeight, cPlanes, cBitsPixel, lpbANDbits, lpbXORbits)	CreateIcon(hInstance, nWidth, nHeight, cPlanes, cBitsPixel, lpbANDbits, lpbXORbits)
__EXTERN INTEGER __CALL CreateIcon(INTEGER hInstance, INTEGER nWidth, INTEGER nHeight, CHAR cPlanes, CHAR cBitsPixel, CHAR *lpbANDbits, CHAR *lpbXORbits);
#define WinApi_CreateIconFromResource(presbits, dwResSize, fIcon, dwVer)	CreateIconFromResource(presbits, dwResSize, fIcon, dwVer)
__EXTERN INTEGER __CALL CreateIconFromResource(CHAR *presbits, INTEGER dwResSize, INTEGER fIcon, INTEGER dwVer);
#define WinApi_CreateIconFromResourceEx(presbits, dwResSize, fIcon, dwVer, cxDesired, cyDesired, Flags)	CreateIconFromResourceEx(presbits, dwResSize, fIcon, dwVer, cxDesired, cyDesired, Flags)
__EXTERN INTEGER __CALL CreateIconFromResourceEx(CHAR *presbits, INTEGER dwResSize, INTEGER fIcon, INTEGER dwVer, INTEGER cxDesired, INTEGER cyDesired, SET Flags);
#define WinApi_CreateIconIndirect(piconinfo, piconinfo__typ)	CreateIconIndirect(piconinfo)
__EXTERN INTEGER __CALL CreateIconIndirect(WinApi_ICONINFO *piconinfo);
#define WinApi_CreateIoCompletionPort(FileHandle, ExistingCompletionPort, CompletionKey, NumberOfConcurrentThreads)	CreateIoCompletionPort(FileHandle, ExistingCompletionPort, CompletionKey, NumberOfConcurrentThreads)
__EXTERN INTEGER __CALL CreateIoCompletionPort(INTEGER FileHandle, INTEGER ExistingCompletionPort, INTEGER CompletionKey, INTEGER NumberOfConcurrentThreads);
#define WinApi_CreateMDIWindow(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)	CreateMDIWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)
#define WinApi_CreateMDIWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)	CreateMDIWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)
__EXTERN INTEGER __CALL CreateMDIWindowA(WinApi_PtrSTR lpClassName, WinApi_PtrSTR lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent, INTEGER hInstance, INTEGER lParam);
#define WinApi_CreateMDIWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)	CreateMDIWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)
__EXTERN INTEGER __CALL CreateMDIWindowW(WinApi_PtrWSTR lpClassName, WinApi_PtrWSTR lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent, INTEGER hInstance, INTEGER lParam);
#define WinApi_CreateMailslot(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)
#define WinApi_CreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)
__EXTERN INTEGER __CALL CreateMailslotA(WinApi_PtrSTR lpName, INTEGER nMaxMessageSize, INTEGER lReadTimeout, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinApi_CreateMailslotW(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateMailslotW(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)
__EXTERN INTEGER __CALL CreateMailslotW(WinApi_PtrWSTR lpName, INTEGER nMaxMessageSize, INTEGER lReadTimeout, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinApi_CreateMenu()	CreateMenu()
__EXTERN INTEGER __CALL CreateMenu(void);
#define WinApi_CreateMetaFile(p0)	CreateMetaFileA(p0)
#define WinApi_CreateMetaFileA(p0)	CreateMetaFileA(p0)
__EXTERN INTEGER __CALL CreateMetaFileA(WinApi_PtrSTR p0);
#define WinApi_CreateMetaFileW(p0)	CreateMetaFileW(p0)
__EXTERN INTEGER __CALL CreateMetaFileW(WinApi_PtrWSTR p0);
#define WinApi_CreateMutex(lpMutexAttributes, lpMutexAttributes__typ, bInitialOwner, lpName)	CreateMutexA(lpMutexAttributes, bInitialOwner, lpName)
#define WinApi_CreateMutexA(lpMutexAttributes, lpMutexAttributes__typ, bInitialOwner, lpName)	CreateMutexA(lpMutexAttributes, bInitialOwner, lpName)
__EXTERN INTEGER __CALL CreateMutexA(WinApi_SECURITY_ATTRIBUTES *lpMutexAttributes, INTEGER bInitialOwner, WinApi_PtrSTR lpName);
#define WinApi_CreateMutexW(lpMutexAttributes, lpMutexAttributes__typ, bInitialOwner, lpName)	CreateMutexW(lpMutexAttributes, bInitialOwner, lpName)
__EXTERN INTEGER __CALL CreateMutexW(WinApi_SECURITY_ATTRIBUTES *lpMutexAttributes, INTEGER bInitialOwner, WinApi_PtrWSTR lpName);
#define WinApi_CreateNamedPipe(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateNamedPipeA(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)
#define WinApi_CreateNamedPipeA(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateNamedPipeA(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)
__EXTERN INTEGER __CALL CreateNamedPipeA(WinApi_PtrSTR lpName, INTEGER dwOpenMode, INTEGER dwPipeMode, INTEGER nMaxInstances, INTEGER nOutBufferSize, INTEGER nInBufferSize, INTEGER nDefaultTimeOut, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinApi_CreateNamedPipeW(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateNamedPipeW(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)
__EXTERN INTEGER __CALL CreateNamedPipeW(WinApi_PtrWSTR lpName, INTEGER dwOpenMode, INTEGER dwPipeMode, INTEGER nMaxInstances, INTEGER nOutBufferSize, INTEGER nInBufferSize, INTEGER nDefaultTimeOut, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinApi_CreatePalette(p0, p0__typ)	CreatePalette(p0)
__EXTERN INTEGER __CALL CreatePalette(WinApi_LOGPALETTE *p0);
#define WinApi_CreatePatternBrush(p0)	CreatePatternBrush(p0)
__EXTERN INTEGER __CALL CreatePatternBrush(INTEGER p0);
#define WinApi_CreatePen(p0, p1, p2)	CreatePen(p0, p1, p2)
__EXTERN INTEGER __CALL CreatePen(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_CreatePenIndirect(p0, p0__typ)	CreatePenIndirect(p0)
__EXTERN INTEGER __CALL CreatePenIndirect(WinApi_LOGPEN *p0);
#define WinApi_CreatePipe(hReadPipe, hWritePipe, lpPipeAttributes, lpPipeAttributes__typ, nSize)	CreatePipe(hReadPipe, hWritePipe, lpPipeAttributes, nSize)
__EXTERN INTEGER __CALL CreatePipe(INTEGER *hReadPipe, INTEGER *hWritePipe, WinApi_SECURITY_ATTRIBUTES *lpPipeAttributes, INTEGER nSize);
#define WinApi_CreatePolyPolygonRgn(p0, p0__typ, p1, p2, p3)	CreatePolyPolygonRgn(p0, p1, p2, p3)
__EXTERN INTEGER __CALL CreatePolyPolygonRgn(WinApi_POINT *p0, INTEGER *p1, INTEGER p2, INTEGER p3);
#define WinApi_CreatePolygonRgn(p0, p0__typ, p1, p2)	CreatePolygonRgn(p0, p1, p2)
__EXTERN INTEGER __CALL CreatePolygonRgn(WinApi_POINT *p0, INTEGER p1, INTEGER p2);
#define WinApi_CreatePopupMenu()	CreatePopupMenu()
__EXTERN INTEGER __CALL CreatePopupMenu(void);
#define WinApi_CreatePrivateObjectSecurity(ParentDescriptor, CreatorDescriptor, NewDescriptor, IsDirectoryObject, Token, GenericMapping, GenericMapping__typ)	CreatePrivateObjectSecurity(ParentDescriptor, CreatorDescriptor, NewDescriptor, IsDirectoryObject, Token, GenericMapping)
__EXTERN INTEGER __CALL CreatePrivateObjectSecurity(INTEGER ParentDescriptor, INTEGER CreatorDescriptor, INTEGER *NewDescriptor, INTEGER IsDirectoryObject, INTEGER Token, WinApi_GENERIC_MAPPING *GenericMapping);
#define WinApi_CreateProcess(lpApplicationName, lpCommandLine, lpProcessAttributes, lpProcessAttributes__typ, lpThreadAttributes, lpThreadAttributes__typ, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpStartupInfo__typ, lpProcessInformation, lpProcessInformation__typ)	CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
#define WinApi_CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpProcessAttributes__typ, lpThreadAttributes, lpThreadAttributes__typ, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpStartupInfo__typ, lpProcessInformation, lpProcessInformation__typ)	CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
__EXTERN INTEGER __CALL CreateProcessA(WinApi_PtrSTR lpApplicationName, WinApi_PtrSTR lpCommandLine, WinApi_SECURITY_ATTRIBUTES *lpProcessAttributes, WinApi_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, INTEGER lpEnvironment, WinApi_PtrSTR lpCurrentDirectory, WinApi_STARTUPINFOA *lpStartupInfo, WinApi_PROCESS_INFORMATION *lpProcessInformation);
#define WinApi_CreateProcessAsUser(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpProcessAttributes__typ, lpThreadAttributes, lpThreadAttributes__typ, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpStartupInfo__typ, lpProcessInformation, lpProcessInformation__typ)	CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
#define WinApi_CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpProcessAttributes__typ, lpThreadAttributes, lpThreadAttributes__typ, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpStartupInfo__typ, lpProcessInformation, lpProcessInformation__typ)	CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
__EXTERN INTEGER __CALL CreateProcessAsUserA(INTEGER hToken, WinApi_PtrSTR lpApplicationName, WinApi_PtrSTR lpCommandLine, WinApi_SECURITY_ATTRIBUTES *lpProcessAttributes, WinApi_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, INTEGER lpEnvironment, WinApi_PtrSTR lpCurrentDirectory, WinApi_STARTUPINFOA *lpStartupInfo, WinApi_PROCESS_INFORMATION *lpProcessInformation);
#define WinApi_CreateProcessAsUserW(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpProcessAttributes__typ, lpThreadAttributes, lpThreadAttributes__typ, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpStartupInfo__typ, lpProcessInformation, lpProcessInformation__typ)	CreateProcessAsUserW(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
__EXTERN INTEGER __CALL CreateProcessAsUserW(INTEGER hToken, WinApi_PtrWSTR lpApplicationName, WinApi_PtrWSTR lpCommandLine, WinApi_SECURITY_ATTRIBUTES *lpProcessAttributes, WinApi_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, INTEGER lpEnvironment, WinApi_PtrWSTR lpCurrentDirectory, WinApi_STARTUPINFOW *lpStartupInfo, WinApi_PROCESS_INFORMATION *lpProcessInformation);
#define WinApi_CreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpProcessAttributes__typ, lpThreadAttributes, lpThreadAttributes__typ, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpStartupInfo__typ, lpProcessInformation, lpProcessInformation__typ)	CreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
__EXTERN INTEGER __CALL CreateProcessW(WinApi_PtrWSTR lpApplicationName, WinApi_PtrWSTR lpCommandLine, WinApi_SECURITY_ATTRIBUTES *lpProcessAttributes, WinApi_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, INTEGER lpEnvironment, WinApi_PtrWSTR lpCurrentDirectory, WinApi_STARTUPINFOW *lpStartupInfo, WinApi_PROCESS_INFORMATION *lpProcessInformation);
#define WinApi_CreatePropertySheetPage(p0, p0__typ)	CreatePropertySheetPageA(p0)
#define WinApi_CreatePropertySheetPageA(p0, p0__typ)	CreatePropertySheetPageA(p0)
__EXTERN WinApi_Ptr_PSP __CALL CreatePropertySheetPageA(WinApi_PROPSHEETPAGEA *p0);
#define WinApi_CreatePropertySheetPageW(p0, p0__typ)	CreatePropertySheetPageW(p0)
__EXTERN WinApi_Ptr_PSP __CALL CreatePropertySheetPageW(WinApi_PROPSHEETPAGEW *p0);
#define WinApi_CreateRectRgn(p0, p1, p2, p3)	CreateRectRgn(p0, p1, p2, p3)
__EXTERN INTEGER __CALL CreateRectRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinApi_CreateRectRgnIndirect(p0, p0__typ)	CreateRectRgnIndirect(p0)
__EXTERN INTEGER __CALL CreateRectRgnIndirect(WinApi_RECT *p0);
#define WinApi_CreateRemoteThread(hProcess, lpThreadAttributes, lpThreadAttributes__typ, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId)	CreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId)
__EXTERN INTEGER __CALL CreateRemoteThread(INTEGER hProcess, WinApi_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER dwStackSize, WinApi_THREAD_START_ROUTINE lpStartAddress, INTEGER lpParameter, SET dwCreationFlags, INTEGER *lpThreadId);
#define WinApi_CreateRoundRectRgn(p0, p1, p2, p3, p4, p5)	CreateRoundRectRgn(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL CreateRoundRectRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
#define WinApi_CreateScalableFontResource(p0, p1, p2, p3)	CreateScalableFontResourceA(p0, p1, p2, p3)
#define WinApi_CreateScalableFontResourceA(p0, p1, p2, p3)	CreateScalableFontResourceA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL CreateScalableFontResourceA(INTEGER p0, WinApi_PtrSTR p1, WinApi_PtrSTR p2, WinApi_PtrSTR p3);
#define WinApi_CreateScalableFontResourceW(p0, p1, p2, p3)	CreateScalableFontResourceW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL CreateScalableFontResourceW(INTEGER p0, WinApi_PtrWSTR p1, WinApi_PtrWSTR p2, WinApi_PtrWSTR p3);
#define WinApi_CreateSemaphore(lpSemaphoreAttributes, lpSemaphoreAttributes__typ, lInitialCount, lMaximumCount, lpName)	CreateSemaphoreA(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)
#define WinApi_CreateSemaphoreA(lpSemaphoreAttributes, lpSemaphoreAttributes__typ, lInitialCount, lMaximumCount, lpName)	CreateSemaphoreA(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)
__EXTERN INTEGER __CALL CreateSemaphoreA(WinApi_SECURITY_ATTRIBUTES *lpSemaphoreAttributes, INTEGER lInitialCount, INTEGER lMaximumCount, WinApi_PtrSTR lpName);
#define WinApi_CreateSemaphoreW(lpSemaphoreAttributes, lpSemaphoreAttributes__typ, lInitialCount, lMaximumCount, lpName)	CreateSemaphoreW(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)
__EXTERN INTEGER __CALL CreateSemaphoreW(WinApi_SECURITY_ATTRIBUTES *lpSemaphoreAttributes, INTEGER lInitialCount, INTEGER lMaximumCount, WinApi_PtrWSTR lpName);
#define WinApi_CreateService(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)	CreateServiceA(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)
#define WinApi_CreateServiceA(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)	CreateServiceA(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)
__EXTERN INTEGER __CALL CreateServiceA(INTEGER hSCManager, WinApi_PtrSTR lpServiceName, WinApi_PtrSTR lpDisplayName, SET dwDesiredAccess, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, WinApi_PtrSTR lpBinaryPathName, WinApi_PtrSTR lpLoadOrderGroup, INTEGER *lpdwTagId, WinApi_PtrSTR lpDependencies, WinApi_PtrSTR lpServiceStartName, WinApi_PtrSTR lpPassword);
#define WinApi_CreateServiceW(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)	CreateServiceW(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)
__EXTERN INTEGER __CALL CreateServiceW(INTEGER hSCManager, WinApi_PtrWSTR lpServiceName, WinApi_PtrWSTR lpDisplayName, SET dwDesiredAccess, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, WinApi_PtrWSTR lpBinaryPathName, WinApi_PtrWSTR lpLoadOrderGroup, INTEGER *lpdwTagId, WinApi_PtrWSTR lpDependencies, WinApi_PtrWSTR lpServiceStartName, WinApi_PtrWSTR lpPassword);
#define WinApi_CreateSolidBrush(p0)	CreateSolidBrush(p0)
__EXTERN INTEGER __CALL CreateSolidBrush(INTEGER p0);
#define WinApi_CreateTapePartition(hDevice, dwPartitionMethod, dwCount, dwSize)	CreateTapePartition(hDevice, dwPartitionMethod, dwCount, dwSize)
__EXTERN INTEGER __CALL CreateTapePartition(INTEGER hDevice, INTEGER dwPartitionMethod, INTEGER dwCount, INTEGER dwSize);
#define WinApi_CreateThread(lpThreadAttributes, lpThreadAttributes__typ, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId)	CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId)
__EXTERN INTEGER __CALL CreateThread(WinApi_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER dwStackSize, WinApi_THREAD_START_ROUTINE lpStartAddress, INTEGER lpParameter, SET dwCreationFlags, INTEGER *lpThreadId);
#define WinApi_CreateWaitableTimer(lpTimerAttributes, lpTimerAttributes__typ, bManualReset, lpTimerName)	CreateWaitableTimerA(lpTimerAttributes, bManualReset, lpTimerName)
#define WinApi_CreateWaitableTimerA(lpTimerAttributes, lpTimerAttributes__typ, bManualReset, lpTimerName)	CreateWaitableTimerA(lpTimerAttributes, bManualReset, lpTimerName)
__EXTERN INTEGER __CALL CreateWaitableTimerA(WinApi_SECURITY_ATTRIBUTES *lpTimerAttributes, INTEGER bManualReset, WinApi_PtrSTR lpTimerName);
#define WinApi_CreateWaitableTimerW(lpTimerAttributes, lpTimerAttributes__typ, bManualReset, lpTimerName)	CreateWaitableTimerW(lpTimerAttributes, bManualReset, lpTimerName)
__EXTERN INTEGER __CALL CreateWaitableTimerW(WinApi_SECURITY_ATTRIBUTES *lpTimerAttributes, INTEGER bManualReset, WinApi_PtrWSTR lpTimerName);
#define WinApi_CreateWindowEx(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)	CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
#define WinApi_CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)	CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
__EXTERN INTEGER __CALL CreateWindowExA(SET dwExStyle, WinApi_PtrSTR lpClassName, WinApi_PtrSTR lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent, INTEGER hMenu, INTEGER hInstance, INTEGER lpParam);
#define WinApi_CreateWindowExW(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)	CreateWindowExW(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
__EXTERN INTEGER __CALL CreateWindowExW(SET dwExStyle, WinApi_PtrWSTR lpClassName, WinApi_PtrWSTR lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent, INTEGER hMenu, INTEGER hInstance, INTEGER lpParam);
#define WinApi_CreateWindowStation(lpwinsta, dwReserved, dwDesiredAccess, lpsa, lpsa__typ)	CreateWindowStationA(lpwinsta, dwReserved, dwDesiredAccess, lpsa)
#define WinApi_CreateWindowStationA(lpwinsta, dwReserved, dwDesiredAccess, lpsa, lpsa__typ)	CreateWindowStationA(lpwinsta, dwReserved, dwDesiredAccess, lpsa)
__EXTERN INTEGER __CALL CreateWindowStationA(WinApi_PtrSTR lpwinsta, INTEGER dwReserved, SET dwDesiredAccess, WinApi_SECURITY_ATTRIBUTES *lpsa);
#define WinApi_CreateWindowStationW(lpwinsta, dwReserved, dwDesiredAccess, lpsa, lpsa__typ)	CreateWindowStationW(lpwinsta, dwReserved, dwDesiredAccess, lpsa)
__EXTERN INTEGER __CALL CreateWindowStationW(WinApi_PtrWSTR lpwinsta, INTEGER dwReserved, SET dwDesiredAccess, WinApi_SECURITY_ATTRIBUTES *lpsa);
#define WinApi_DPtoLP(p0, p1, p1__typ, p2)	DPtoLP(p0, p1, p2)
__EXTERN INTEGER __CALL DPtoLP(INTEGER p0, WinApi_POINT *p1, INTEGER p2);
#define WinApi_DdeAbandonTransaction(idInst, hConv, idTransaction)	DdeAbandonTransaction(idInst, hConv, idTransaction)
__EXTERN INTEGER __CALL DdeAbandonTransaction(INTEGER idInst, INTEGER hConv, INTEGER idTransaction);
#define WinApi_DdeAccessData(hData, pcbDataSize)	DdeAccessData(hData, pcbDataSize)
__EXTERN WinApi_RetDdeAccessData __CALL DdeAccessData(INTEGER hData, INTEGER *pcbDataSize);
#define WinApi_DdeAddData(hData, pSrc, cb, cbOff)	DdeAddData(hData, pSrc, cb, cbOff)
__EXTERN INTEGER __CALL DdeAddData(INTEGER hData, CHAR *pSrc, INTEGER cb, INTEGER cbOff);
#define WinApi_DdeClientTransaction(pData, cbData, hConv, hszItem, wFmt, wType, dwTimeout, pdwResult)	DdeClientTransaction(pData, cbData, hConv, hszItem, wFmt, wType, dwTimeout, pdwResult)
__EXTERN INTEGER __CALL DdeClientTransaction(CHAR *pData, INTEGER cbData, INTEGER hConv, INTEGER hszItem, INTEGER wFmt, INTEGER wType, INTEGER dwTimeout, INTEGER *pdwResult);
#define WinApi_DdeCmpStringHandles(hsz1, hsz2)	DdeCmpStringHandles(hsz1, hsz2)
__EXTERN INTEGER __CALL DdeCmpStringHandles(INTEGER hsz1, INTEGER hsz2);
#define WinApi_DdeConnect(idInst, hszService, hszTopic, pCC, pCC__typ)	DdeConnect(idInst, hszService, hszTopic, pCC)
__EXTERN INTEGER __CALL DdeConnect(INTEGER idInst, INTEGER hszService, INTEGER hszTopic, WinApi_CONVCONTEXT *pCC);
#define WinApi_DdeConnectList(idInst, hszService, hszTopic, hConvList, pCC, pCC__typ)	DdeConnectList(idInst, hszService, hszTopic, hConvList, pCC)
__EXTERN INTEGER __CALL DdeConnectList(INTEGER idInst, INTEGER hszService, INTEGER hszTopic, INTEGER hConvList, WinApi_CONVCONTEXT *pCC);
#define WinApi_DdeCreateDataHandle(idInst, pSrc, cb, cbOff, hszItem, wFmt, afCmd)	DdeCreateDataHandle(idInst, pSrc, cb, cbOff, hszItem, wFmt, afCmd)
__EXTERN INTEGER __CALL DdeCreateDataHandle(INTEGER idInst, CHAR *pSrc, INTEGER cb, INTEGER cbOff, INTEGER hszItem, INTEGER wFmt, INTEGER afCmd);
#define WinApi_DdeCreateStringHandle(idInst, psz, iCodePage)	DdeCreateStringHandleA(idInst, psz, iCodePage)
#define WinApi_DdeCreateStringHandleA(idInst, psz, iCodePage)	DdeCreateStringHandleA(idInst, psz, iCodePage)
__EXTERN INTEGER __CALL DdeCreateStringHandleA(INTEGER idInst, WinApi_PtrSTR psz, INTEGER iCodePage);
#define WinApi_DdeCreateStringHandleW(idInst, psz, iCodePage)	DdeCreateStringHandleW(idInst, psz, iCodePage)
__EXTERN INTEGER __CALL DdeCreateStringHandleW(INTEGER idInst, WinApi_PtrWSTR psz, INTEGER iCodePage);
#define WinApi_DdeDisconnect(hConv)	DdeDisconnect(hConv)
__EXTERN INTEGER __CALL DdeDisconnect(INTEGER hConv);
#define WinApi_DdeDisconnectList(hConvList)	DdeDisconnectList(hConvList)
__EXTERN INTEGER __CALL DdeDisconnectList(INTEGER hConvList);
#define WinApi_DdeEnableCallback(idInst, hConv, wCmd)	DdeEnableCallback(idInst, hConv, wCmd)
__EXTERN INTEGER __CALL DdeEnableCallback(INTEGER idInst, INTEGER hConv, INTEGER wCmd);
#define WinApi_DdeFreeDataHandle(hData)	DdeFreeDataHandle(hData)
__EXTERN INTEGER __CALL DdeFreeDataHandle(INTEGER hData);
#define WinApi_DdeFreeStringHandle(idInst, hsz)	DdeFreeStringHandle(idInst, hsz)
__EXTERN INTEGER __CALL DdeFreeStringHandle(INTEGER idInst, INTEGER hsz);
#define WinApi_DdeGetData(hData, pDst, cbMax, cbOff)	DdeGetData(hData, pDst, cbMax, cbOff)
__EXTERN INTEGER __CALL DdeGetData(INTEGER hData, CHAR *pDst, INTEGER cbMax, INTEGER cbOff);
#define WinApi_DdeGetLastError(idInst)	DdeGetLastError(idInst)
__EXTERN INTEGER __CALL DdeGetLastError(INTEGER idInst);
#define WinApi_DdeImpersonateClient(hConv)	DdeImpersonateClient(hConv)
__EXTERN INTEGER __CALL DdeImpersonateClient(INTEGER hConv);
#define WinApi_DdeInitialize(pidInst, pfnCallback, afCmd, ulRes)	DdeInitializeA(pidInst, pfnCallback, afCmd, ulRes)
#define WinApi_DdeInitializeA(pidInst, pfnCallback, afCmd, ulRes)	DdeInitializeA(pidInst, pfnCallback, afCmd, ulRes)
__EXTERN INTEGER __CALL DdeInitializeA(INTEGER *pidInst, WinApi_FNCALLBACK pfnCallback, INTEGER afCmd, INTEGER ulRes);
#define WinApi_DdeInitializeW(pidInst, pfnCallback, afCmd, ulRes)	DdeInitializeW(pidInst, pfnCallback, afCmd, ulRes)
__EXTERN INTEGER __CALL DdeInitializeW(INTEGER *pidInst, WinApi_FNCALLBACK pfnCallback, INTEGER afCmd, INTEGER ulRes);
#define WinApi_DdeKeepStringHandle(idInst, hsz)	DdeKeepStringHandle(idInst, hsz)
__EXTERN INTEGER __CALL DdeKeepStringHandle(INTEGER idInst, INTEGER hsz);
#define WinApi_DdeNameService(idInst, hsz1, hsz2, afCmd)	DdeNameService(idInst, hsz1, hsz2, afCmd)
__EXTERN INTEGER __CALL DdeNameService(INTEGER idInst, INTEGER hsz1, INTEGER hsz2, INTEGER afCmd);
#define WinApi_DdePostAdvise(idInst, hszTopic, hszItem)	DdePostAdvise(idInst, hszTopic, hszItem)
__EXTERN INTEGER __CALL DdePostAdvise(INTEGER idInst, INTEGER hszTopic, INTEGER hszItem);
#define WinApi_DdeQueryConvInfo(hConv, idTransaction, pConvInfo, pConvInfo__typ)	DdeQueryConvInfo(hConv, idTransaction, pConvInfo)
__EXTERN INTEGER __CALL DdeQueryConvInfo(INTEGER hConv, INTEGER idTransaction, WinApi_CONVINFO *pConvInfo);
#define WinApi_DdeQueryNextServer(hConvList, hConvPrev)	DdeQueryNextServer(hConvList, hConvPrev)
__EXTERN INTEGER __CALL DdeQueryNextServer(INTEGER hConvList, INTEGER hConvPrev);
#define WinApi_DdeQueryString(idInst, hsz, psz, cchMax, iCodePage)	DdeQueryStringA(idInst, hsz, psz, cchMax, iCodePage)
#define WinApi_DdeQueryStringA(idInst, hsz, psz, cchMax, iCodePage)	DdeQueryStringA(idInst, hsz, psz, cchMax, iCodePage)
__EXTERN INTEGER __CALL DdeQueryStringA(INTEGER idInst, INTEGER hsz, WinApi_PtrSTR psz, INTEGER cchMax, INTEGER iCodePage);
#define WinApi_DdeQueryStringW(idInst, hsz, psz, cchMax, iCodePage)	DdeQueryStringW(idInst, hsz, psz, cchMax, iCodePage)
__EXTERN INTEGER __CALL DdeQueryStringW(INTEGER idInst, INTEGER hsz, WinApi_PtrWSTR psz, INTEGER cchMax, INTEGER iCodePage);
#define WinApi_DdeReconnect(hConv)	DdeReconnect(hConv)
__EXTERN INTEGER __CALL DdeReconnect(INTEGER hConv);
#define WinApi_DdeSetQualityOfService(hwndClient, pqosNew, pqosNew__typ, pqosPrev, pqosPrev__typ)	DdeSetQualityOfService(hwndClient, pqosNew, pqosPrev)
__EXTERN INTEGER __CALL DdeSetQualityOfService(INTEGER hwndClient, WinApi_SECURITY_QUALITY_OF_SERVICE *pqosNew, WinApi_SECURITY_QUALITY_OF_SERVICE *pqosPrev);
#define WinApi_DdeSetUserHandle(hConv, id, hUser)	DdeSetUserHandle(hConv, id, hUser)
__EXTERN INTEGER __CALL DdeSetUserHandle(INTEGER hConv, INTEGER id, INTEGER hUser);
#define WinApi_DdeUnaccessData(hData)	DdeUnaccessData(hData)
__EXTERN INTEGER __CALL DdeUnaccessData(INTEGER hData);
#define WinApi_DdeUninitialize(idInst)	DdeUninitialize(idInst)
__EXTERN INTEGER __CALL DdeUninitialize(INTEGER idInst);
#define WinApi_DebugActiveProcess(dwProcessId)	DebugActiveProcess(dwProcessId)
__EXTERN INTEGER __CALL DebugActiveProcess(INTEGER dwProcessId);
#define WinApi_DebugBreak()	DebugBreak()
__EXTERN void __CALL DebugBreak(void);
#define WinApi_DefDlgProc(hDlg, Msg, wParam, lParam)	DefDlgProcA(hDlg, Msg, wParam, lParam)
#define WinApi_DefDlgProcA(hDlg, Msg, wParam, lParam)	DefDlgProcA(hDlg, Msg, wParam, lParam)
__EXTERN INTEGER __CALL DefDlgProcA(INTEGER hDlg, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_DefDlgProcW(hDlg, Msg, wParam, lParam)	DefDlgProcW(hDlg, Msg, wParam, lParam)
__EXTERN INTEGER __CALL DefDlgProcW(INTEGER hDlg, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_DefFrameProc(hWnd, hWndMDIClient, uMsg, wParam, lParam)	DefFrameProcA(hWnd, hWndMDIClient, uMsg, wParam, lParam)
#define WinApi_DefFrameProcA(hWnd, hWndMDIClient, uMsg, wParam, lParam)	DefFrameProcA(hWnd, hWndMDIClient, uMsg, wParam, lParam)
__EXTERN INTEGER __CALL DefFrameProcA(INTEGER hWnd, INTEGER hWndMDIClient, INTEGER uMsg, INTEGER wParam, INTEGER lParam);
#define WinApi_DefFrameProcW(hWnd, hWndMDIClient, uMsg, wParam, lParam)	DefFrameProcW(hWnd, hWndMDIClient, uMsg, wParam, lParam)
__EXTERN INTEGER __CALL DefFrameProcW(INTEGER hWnd, INTEGER hWndMDIClient, INTEGER uMsg, INTEGER wParam, INTEGER lParam);
#define WinApi_DefMDIChildProc(hWnd, uMsg, wParam, lParam)	DefMDIChildProcA(hWnd, uMsg, wParam, lParam)
#define WinApi_DefMDIChildProcA(hWnd, uMsg, wParam, lParam)	DefMDIChildProcA(hWnd, uMsg, wParam, lParam)
__EXTERN INTEGER __CALL DefMDIChildProcA(INTEGER hWnd, INTEGER uMsg, INTEGER wParam, INTEGER lParam);
#define WinApi_DefMDIChildProcW(hWnd, uMsg, wParam, lParam)	DefMDIChildProcW(hWnd, uMsg, wParam, lParam)
__EXTERN INTEGER __CALL DefMDIChildProcW(INTEGER hWnd, INTEGER uMsg, INTEGER wParam, INTEGER lParam);
#define WinApi_DefWindowProc(hWnd, Msg, wParam, lParam)	DefWindowProcA(hWnd, Msg, wParam, lParam)
#define WinApi_DefWindowProcA(hWnd, Msg, wParam, lParam)	DefWindowProcA(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL DefWindowProcA(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_DefWindowProcW(hWnd, Msg, wParam, lParam)	DefWindowProcW(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL DefWindowProcW(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_DeferWindowPos(hWinPosInfo, hWnd, hWndInsertAfter, x, y, cx, cy, uFlags)	DeferWindowPos(hWinPosInfo, hWnd, hWndInsertAfter, x, y, cx, cy, uFlags)
__EXTERN INTEGER __CALL DeferWindowPos(INTEGER hWinPosInfo, INTEGER hWnd, INTEGER hWndInsertAfter, INTEGER x, INTEGER y, INTEGER cx, INTEGER cy, SET uFlags);
#define WinApi_DefineDosDevice(dwFlags, lpDeviceName, lpTargetPath)	DefineDosDeviceA(dwFlags, lpDeviceName, lpTargetPath)
#define WinApi_DefineDosDeviceA(dwFlags, lpDeviceName, lpTargetPath)	DefineDosDeviceA(dwFlags, lpDeviceName, lpTargetPath)
__EXTERN INTEGER __CALL DefineDosDeviceA(SET dwFlags, WinApi_PtrSTR lpDeviceName, WinApi_PtrSTR lpTargetPath);
#define WinApi_DefineDosDeviceW(dwFlags, lpDeviceName, lpTargetPath)	DefineDosDeviceW(dwFlags, lpDeviceName, lpTargetPath)
__EXTERN INTEGER __CALL DefineDosDeviceW(SET dwFlags, WinApi_PtrWSTR lpDeviceName, WinApi_PtrWSTR lpTargetPath);
#define WinApi_DeleteAce(pAcl, pAcl__typ, dwAceIndex)	DeleteAce(pAcl, dwAceIndex)
__EXTERN INTEGER __CALL DeleteAce(WinApi_ACL *pAcl, INTEGER dwAceIndex);
#define WinApi_DeleteAtom(nAtom)	DeleteAtom(nAtom)
__EXTERN SHORTINT __CALL DeleteAtom(SHORTINT nAtom);
#define WinApi_DeleteColorSpace(p0)	DeleteColorSpace(p0)
__EXTERN INTEGER __CALL DeleteColorSpace(INTEGER p0);
#define WinApi_DeleteCriticalSection(lpCriticalSection, lpCriticalSection__typ)	DeleteCriticalSection(lpCriticalSection)
__EXTERN void __CALL DeleteCriticalSection(WinApi_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinApi_DeleteDC(p0)	DeleteDC(p0)
__EXTERN INTEGER __CALL DeleteDC(INTEGER p0);
#define WinApi_DeleteEnhMetaFile(p0)	DeleteEnhMetaFile(p0)
__EXTERN INTEGER __CALL DeleteEnhMetaFile(INTEGER p0);
#define WinApi_DeleteFiber(lpFiber)	DeleteFiber(lpFiber)
__EXTERN void __CALL DeleteFiber(INTEGER lpFiber);
#define WinApi_DeleteFile(lpFileName)	DeleteFileA(lpFileName)
#define WinApi_DeleteFileA(lpFileName)	DeleteFileA(lpFileName)
__EXTERN INTEGER __CALL DeleteFileA(WinApi_PtrSTR lpFileName);
#define WinApi_DeleteFileW(lpFileName)	DeleteFileW(lpFileName)
__EXTERN INTEGER __CALL DeleteFileW(WinApi_PtrWSTR lpFileName);
#define WinApi_DeleteForm(hPrinter, pFormName)	DeleteFormA(hPrinter, pFormName)
#define WinApi_DeleteFormA(hPrinter, pFormName)	DeleteFormA(hPrinter, pFormName)
__EXTERN INTEGER __CALL DeleteFormA(INTEGER hPrinter, WinApi_PtrSTR pFormName);
#define WinApi_DeleteFormW(hPrinter, pFormName)	DeleteFormW(hPrinter, pFormName)
__EXTERN INTEGER __CALL DeleteFormW(INTEGER hPrinter, WinApi_PtrWSTR pFormName);
#define WinApi_DeleteMenu(hMenu, uPosition, uFlags)	DeleteMenu(hMenu, uPosition, uFlags)
__EXTERN INTEGER __CALL DeleteMenu(INTEGER hMenu, INTEGER uPosition, SET uFlags);
#define WinApi_DeleteMetaFile(p0)	DeleteMetaFile(p0)
__EXTERN INTEGER __CALL DeleteMetaFile(INTEGER p0);
#define WinApi_DeleteMonitor(pName, pEnvironment, pMonitorName)	DeleteMonitorA(pName, pEnvironment, pMonitorName)
#define WinApi_DeleteMonitorA(pName, pEnvironment, pMonitorName)	DeleteMonitorA(pName, pEnvironment, pMonitorName)
__EXTERN INTEGER __CALL DeleteMonitorA(WinApi_PtrSTR pName, WinApi_PtrSTR pEnvironment, WinApi_PtrSTR pMonitorName);
#define WinApi_DeleteMonitorW(pName, pEnvironment, pMonitorName)	DeleteMonitorW(pName, pEnvironment, pMonitorName)
__EXTERN INTEGER __CALL DeleteMonitorW(WinApi_PtrWSTR pName, WinApi_PtrWSTR pEnvironment, WinApi_PtrWSTR pMonitorName);
#define WinApi_DeleteObject(p0)	DeleteObject(p0)
__EXTERN INTEGER __CALL DeleteObject(INTEGER p0);
#define WinApi_DeletePort(pName, hWnd, pPortName)	DeletePortA(pName, hWnd, pPortName)
#define WinApi_DeletePortA(pName, hWnd, pPortName)	DeletePortA(pName, hWnd, pPortName)
__EXTERN INTEGER __CALL DeletePortA(WinApi_PtrSTR pName, INTEGER hWnd, WinApi_PtrSTR pPortName);
#define WinApi_DeletePortW(pName, hWnd, pPortName)	DeletePortW(pName, hWnd, pPortName)
__EXTERN INTEGER __CALL DeletePortW(WinApi_PtrWSTR pName, INTEGER hWnd, WinApi_PtrWSTR pPortName);
#define WinApi_DeletePrintProcessor(pName, pEnvironment, pPrintProcessorName)	DeletePrintProcessorA(pName, pEnvironment, pPrintProcessorName)
#define WinApi_DeletePrintProcessorA(pName, pEnvironment, pPrintProcessorName)	DeletePrintProcessorA(pName, pEnvironment, pPrintProcessorName)
__EXTERN INTEGER __CALL DeletePrintProcessorA(WinApi_PtrSTR pName, WinApi_PtrSTR pEnvironment, WinApi_PtrSTR pPrintProcessorName);
#define WinApi_DeletePrintProcessorW(pName, pEnvironment, pPrintProcessorName)	DeletePrintProcessorW(pName, pEnvironment, pPrintProcessorName)
__EXTERN INTEGER __CALL DeletePrintProcessorW(WinApi_PtrWSTR pName, WinApi_PtrWSTR pEnvironment, WinApi_PtrWSTR pPrintProcessorName);
#define WinApi_DeletePrintProvidor(pName, pEnvironment, pPrintProvidorName)	DeletePrintProvidorA(pName, pEnvironment, pPrintProvidorName)
#define WinApi_DeletePrintProvidorA(pName, pEnvironment, pPrintProvidorName)	DeletePrintProvidorA(pName, pEnvironment, pPrintProvidorName)
__EXTERN INTEGER __CALL DeletePrintProvidorA(WinApi_PtrSTR pName, WinApi_PtrSTR pEnvironment, WinApi_PtrSTR pPrintProvidorName);
#define WinApi_DeletePrintProvidorW(pName, pEnvironment, pPrintProvidorName)	DeletePrintProvidorW(pName, pEnvironment, pPrintProvidorName)
__EXTERN INTEGER __CALL DeletePrintProvidorW(WinApi_PtrWSTR pName, WinApi_PtrWSTR pEnvironment, WinApi_PtrWSTR pPrintProvidorName);
#define WinApi_DeletePrinter(hPrinter)	DeletePrinter(hPrinter)
__EXTERN INTEGER __CALL DeletePrinter(INTEGER hPrinter);
#define WinApi_DeletePrinterConnection(pName)	DeletePrinterConnectionA(pName)
#define WinApi_DeletePrinterConnectionA(pName)	DeletePrinterConnectionA(pName)
__EXTERN INTEGER __CALL DeletePrinterConnectionA(WinApi_PtrSTR pName);
#define WinApi_DeletePrinterConnectionW(pName)	DeletePrinterConnectionW(pName)
__EXTERN INTEGER __CALL DeletePrinterConnectionW(WinApi_PtrWSTR pName);
#define WinApi_DeletePrinterDriver(pName, pEnvironment, pDriverName)	DeletePrinterDriverA(pName, pEnvironment, pDriverName)
#define WinApi_DeletePrinterDriverA(pName, pEnvironment, pDriverName)	DeletePrinterDriverA(pName, pEnvironment, pDriverName)
__EXTERN INTEGER __CALL DeletePrinterDriverA(WinApi_PtrSTR pName, WinApi_PtrSTR pEnvironment, WinApi_PtrSTR pDriverName);
#define WinApi_DeletePrinterDriverW(pName, pEnvironment, pDriverName)	DeletePrinterDriverW(pName, pEnvironment, pDriverName)
__EXTERN INTEGER __CALL DeletePrinterDriverW(WinApi_PtrWSTR pName, WinApi_PtrWSTR pEnvironment, WinApi_PtrWSTR pDriverName);
#define WinApi_DeleteService(hService)	DeleteService(hService)
__EXTERN INTEGER __CALL DeleteService(INTEGER hService);
#define WinApi_DeregisterEventSource(hEventLog)	DeregisterEventSource(hEventLog)
__EXTERN INTEGER __CALL DeregisterEventSource(INTEGER hEventLog);
#define WinApi_DescribePixelFormat(p0, p1, p2, p3, p3__typ)	DescribePixelFormat(p0, p1, p2, p3)
__EXTERN INTEGER __CALL DescribePixelFormat(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_PIXELFORMATDESCRIPTOR *p3);
#define WinApi_DestroyAcceleratorTable(hAccel)	DestroyAcceleratorTable(hAccel)
__EXTERN INTEGER __CALL DestroyAcceleratorTable(INTEGER hAccel);
#define WinApi_DestroyCaret()	DestroyCaret()
__EXTERN INTEGER __CALL DestroyCaret(void);
#define WinApi_DestroyCursor(hCursor)	DestroyCursor(hCursor)
__EXTERN INTEGER __CALL DestroyCursor(INTEGER hCursor);
#define WinApi_DestroyIcon(hIcon)	DestroyIcon(hIcon)
__EXTERN INTEGER __CALL DestroyIcon(INTEGER hIcon);
#define WinApi_DestroyMenu(hMenu)	DestroyMenu(hMenu)
__EXTERN INTEGER __CALL DestroyMenu(INTEGER hMenu);
#define WinApi_DestroyPrivateObjectSecurity(ObjectDescriptor)	DestroyPrivateObjectSecurity(ObjectDescriptor)
__EXTERN INTEGER __CALL DestroyPrivateObjectSecurity(INTEGER *ObjectDescriptor);
#define WinApi_DestroyPropertySheetPage(p0)	DestroyPropertySheetPage(p0)
__EXTERN INTEGER __CALL DestroyPropertySheetPage(WinApi_Ptr_PSP p0);
#define WinApi_DestroyWindow(hWnd)	DestroyWindow(hWnd)
__EXTERN INTEGER __CALL DestroyWindow(INTEGER hWnd);
#define WinApi_DeviceCapabilities(p0, p1, p2, p3, p4, p4__typ)	DeviceCapabilitiesA(p0, p1, p2, p3, p4)
#define WinApi_DeviceCapabilitiesA(p0, p1, p2, p3, p4, p4__typ)	DeviceCapabilitiesA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL DeviceCapabilitiesA(WinApi_PtrSTR p0, WinApi_PtrSTR p1, SHORTINT p2, WinApi_PtrSTR p3, WinApi_DEVMODEA *p4);
#define WinApi_DeviceCapabilitiesW(p0, p1, p2, p3, p4, p4__typ)	DeviceCapabilitiesW(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL DeviceCapabilitiesW(WinApi_PtrWSTR p0, WinApi_PtrWSTR p1, SHORTINT p2, WinApi_PtrWSTR p3, WinApi_DEVMODEW *p4);
#define WinApi_DeviceIoControl(hDevice, dwIoControlCode, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesReturned, lpOverlapped, lpOverlapped__typ)	DeviceIoControl(hDevice, dwIoControlCode, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesReturned, lpOverlapped)
__EXTERN INTEGER __CALL DeviceIoControl(INTEGER hDevice, INTEGER dwIoControlCode, INTEGER lpInBuffer, INTEGER nInBufferSize, INTEGER lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesReturned, WinApi_OVERLAPPED *lpOverlapped);
#define WinApi_DialogBoxIndirectParam(hInstance, hDialogTemplate, hDialogTemplate__typ, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxIndirectParamA(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)
#define WinApi_DialogBoxIndirectParamA(hInstance, hDialogTemplate, hDialogTemplate__typ, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxIndirectParamA(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL DialogBoxIndirectParamA(INTEGER hInstance, WinApi_DLGTEMPLATE *hDialogTemplate, INTEGER hWndParent, WinApi_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinApi_DialogBoxIndirectParamW(hInstance, hDialogTemplate, hDialogTemplate__typ, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxIndirectParamW(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL DialogBoxIndirectParamW(INTEGER hInstance, WinApi_DLGTEMPLATE *hDialogTemplate, INTEGER hWndParent, WinApi_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinApi_DialogBoxParam(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
#define WinApi_DialogBoxParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL DialogBoxParamA(INTEGER hInstance, WinApi_PtrSTR lpTemplateName, INTEGER hWndParent, WinApi_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinApi_DialogBoxParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL DialogBoxParamW(INTEGER hInstance, WinApi_PtrWSTR lpTemplateName, INTEGER hWndParent, WinApi_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinApi_DisableThreadLibraryCalls(hLibModule)	DisableThreadLibraryCalls(hLibModule)
__EXTERN INTEGER __CALL DisableThreadLibraryCalls(INTEGER hLibModule);
#define WinApi_DisconnectNamedPipe(hNamedPipe)	DisconnectNamedPipe(hNamedPipe)
__EXTERN INTEGER __CALL DisconnectNamedPipe(INTEGER hNamedPipe);
#define WinApi_DispatchMessage(lpMsg, lpMsg__typ)	DispatchMessageA(lpMsg)
#define WinApi_DispatchMessageA(lpMsg, lpMsg__typ)	DispatchMessageA(lpMsg)
__EXTERN INTEGER __CALL DispatchMessageA(WinApi_MSG *lpMsg);
#define WinApi_DispatchMessageW(lpMsg, lpMsg__typ)	DispatchMessageW(lpMsg)
__EXTERN INTEGER __CALL DispatchMessageW(WinApi_MSG *lpMsg);
#define WinApi_DlgDirList(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)	DlgDirListA(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)
#define WinApi_DlgDirListA(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)	DlgDirListA(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)
__EXTERN INTEGER __CALL DlgDirListA(INTEGER hDlg, WinApi_PtrSTR lpPathSpec, INTEGER nIDListBox, INTEGER nIDStaticPath, SET uFileType);
#define WinApi_DlgDirListComboBox(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)	DlgDirListComboBoxA(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)
#define WinApi_DlgDirListComboBoxA(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)	DlgDirListComboBoxA(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)
__EXTERN INTEGER __CALL DlgDirListComboBoxA(INTEGER hDlg, WinApi_PtrSTR lpPathSpec, INTEGER nIDComboBox, INTEGER nIDStaticPath, INTEGER uFiletype);
#define WinApi_DlgDirListComboBoxW(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)	DlgDirListComboBoxW(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)
__EXTERN INTEGER __CALL DlgDirListComboBoxW(INTEGER hDlg, WinApi_PtrWSTR lpPathSpec, INTEGER nIDComboBox, INTEGER nIDStaticPath, INTEGER uFiletype);
#define WinApi_DlgDirListW(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)	DlgDirListW(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)
__EXTERN INTEGER __CALL DlgDirListW(INTEGER hDlg, WinApi_PtrWSTR lpPathSpec, INTEGER nIDListBox, INTEGER nIDStaticPath, SET uFileType);
#define WinApi_DlgDirSelectComboBoxEx(hDlg, lpString, nCount, nIDComboBox)	DlgDirSelectComboBoxExA(hDlg, lpString, nCount, nIDComboBox)
#define WinApi_DlgDirSelectComboBoxExA(hDlg, lpString, nCount, nIDComboBox)	DlgDirSelectComboBoxExA(hDlg, lpString, nCount, nIDComboBox)
__EXTERN INTEGER __CALL DlgDirSelectComboBoxExA(INTEGER hDlg, WinApi_PtrSTR lpString, INTEGER nCount, INTEGER nIDComboBox);
#define WinApi_DlgDirSelectComboBoxExW(hDlg, lpString, nCount, nIDComboBox)	DlgDirSelectComboBoxExW(hDlg, lpString, nCount, nIDComboBox)
__EXTERN INTEGER __CALL DlgDirSelectComboBoxExW(INTEGER hDlg, WinApi_PtrWSTR lpString, INTEGER nCount, INTEGER nIDComboBox);
#define WinApi_DlgDirSelectEx(hDlg, lpString, nCount, nIDListBox)	DlgDirSelectExA(hDlg, lpString, nCount, nIDListBox)
#define WinApi_DlgDirSelectExA(hDlg, lpString, nCount, nIDListBox)	DlgDirSelectExA(hDlg, lpString, nCount, nIDListBox)
__EXTERN INTEGER __CALL DlgDirSelectExA(INTEGER hDlg, WinApi_PtrSTR lpString, INTEGER nCount, INTEGER nIDListBox);
#define WinApi_DlgDirSelectExW(hDlg, lpString, nCount, nIDListBox)	DlgDirSelectExW(hDlg, lpString, nCount, nIDListBox)
__EXTERN INTEGER __CALL DlgDirSelectExW(INTEGER hDlg, WinApi_PtrWSTR lpString, INTEGER nCount, INTEGER nIDListBox);
#define WinApi_DoEnvironmentSubst(szString, cbString)	DoEnvironmentSubstA(szString, cbString)
#define WinApi_DoEnvironmentSubstA(szString, cbString)	DoEnvironmentSubstA(szString, cbString)
__EXTERN INTEGER __CALL DoEnvironmentSubstA(WinApi_PtrSTR szString, INTEGER cbString);
#define WinApi_DoEnvironmentSubstW(szString, cbString)	DoEnvironmentSubstW(szString, cbString)
__EXTERN INTEGER __CALL DoEnvironmentSubstW(WinApi_PtrWSTR szString, INTEGER cbString);
#define WinApi_DocumentProperties(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeOutput__typ, pDevModeInput, pDevModeInput__typ, fMode)	DocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)
#define WinApi_DocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeOutput__typ, pDevModeInput, pDevModeInput__typ, fMode)	DocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)
__EXTERN INTEGER __CALL DocumentPropertiesA(INTEGER hWnd, INTEGER hPrinter, WinApi_PtrSTR pDeviceName, WinApi_DEVMODEA *pDevModeOutput, WinApi_DEVMODEA *pDevModeInput, SET fMode);
#define WinApi_DocumentPropertiesW(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeOutput__typ, pDevModeInput, pDevModeInput__typ, fMode)	DocumentPropertiesW(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)
__EXTERN INTEGER __CALL DocumentPropertiesW(INTEGER hWnd, INTEGER hPrinter, WinApi_PtrWSTR pDeviceName, WinApi_DEVMODEW *pDevModeOutput, WinApi_DEVMODEW *pDevModeInput, SET fMode);
#define WinApi_DosDateTimeToFileTime(wFatDate, wFatTime, lpFileTime, lpFileTime__typ)	DosDateTimeToFileTime(wFatDate, wFatTime, lpFileTime)
__EXTERN INTEGER __CALL DosDateTimeToFileTime(SHORTINT wFatDate, SHORTINT wFatTime, WinApi_FILETIME *lpFileTime);
#define WinApi_DragAcceptFiles(p0, p1)	DragAcceptFiles(p0, p1)
__EXTERN void __CALL DragAcceptFiles(INTEGER p0, INTEGER p1);
#define WinApi_DragDetect(p0, p1)	DragDetect(p0, p1)
__EXTERN INTEGER __CALL DragDetect(INTEGER p0, WinApi_POINT p1);
#define WinApi_DragFinish(p0)	DragFinish(p0)
__EXTERN void __CALL DragFinish(INTEGER p0);
#define WinApi_DragObject(p0, p1, p2, p3, p4)	DragObject(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL DragObject(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_DragQueryFile(p0, p1, p2, p3)	DragQueryFileA(p0, p1, p2, p3)
#define WinApi_DragQueryFileA(p0, p1, p2, p3)	DragQueryFileA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL DragQueryFileA(INTEGER p0, INTEGER p1, WinApi_PtrSTR p2, INTEGER p3);
#define WinApi_DragQueryFileW(p0, p1, p2, p3)	DragQueryFileW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL DragQueryFileW(INTEGER p0, INTEGER p1, WinApi_PtrWSTR p2, INTEGER p3);
#define WinApi_DragQueryPoint(p0, p1, p1__typ)	DragQueryPoint(p0, p1)
__EXTERN INTEGER __CALL DragQueryPoint(INTEGER p0, WinApi_POINT *p1);
#define WinApi_DrawAnimatedRects(hwnd, idAni, lprcFrom, lprcFrom__typ, lprcTo, lprcTo__typ)	DrawAnimatedRects(hwnd, idAni, lprcFrom, lprcTo)
__EXTERN INTEGER __CALL DrawAnimatedRects(INTEGER hwnd, INTEGER idAni, WinApi_RECT *lprcFrom, WinApi_RECT *lprcTo);
#define WinApi_DrawCaption(p0, p1, p2, p2__typ, p3)	DrawCaption(p0, p1, p2, p3)
__EXTERN INTEGER __CALL DrawCaption(INTEGER p0, INTEGER p1, WinApi_RECT *p2, INTEGER p3);
#define WinApi_DrawEdge(hdc, qrc, qrc__typ, edge, grfFlags)	DrawEdge(hdc, qrc, edge, grfFlags)
__EXTERN INTEGER __CALL DrawEdge(INTEGER hdc, WinApi_RECT *qrc, SET edge, SET grfFlags);
#define WinApi_DrawEscape(p0, p1, p2, p3)	DrawEscape(p0, p1, p2, p3)
__EXTERN INTEGER __CALL DrawEscape(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_PtrSTR p3);
#define WinApi_DrawFocusRect(hDC, lprc, lprc__typ)	DrawFocusRect(hDC, lprc)
__EXTERN INTEGER __CALL DrawFocusRect(INTEGER hDC, WinApi_RECT *lprc);
#define WinApi_DrawFrameControl(p0, p1, p1__typ, p2, p3)	DrawFrameControl(p0, p1, p2, p3)
__EXTERN INTEGER __CALL DrawFrameControl(INTEGER p0, WinApi_RECT *p1, INTEGER p2, SET p3);
#define WinApi_DrawIcon(hDC, X, Y, hIcon)	DrawIcon(hDC, X, Y, hIcon)
__EXTERN INTEGER __CALL DrawIcon(INTEGER hDC, INTEGER X, INTEGER Y, INTEGER hIcon);
#define WinApi_DrawIconEx(hdc, xLeft, yTop, hIcon, cxWidth, cyWidth, istepIfAniCur, hbrFlickerFreeDraw, diFlags)	DrawIconEx(hdc, xLeft, yTop, hIcon, cxWidth, cyWidth, istepIfAniCur, hbrFlickerFreeDraw, diFlags)
__EXTERN INTEGER __CALL DrawIconEx(INTEGER hdc, INTEGER xLeft, INTEGER yTop, INTEGER hIcon, INTEGER cxWidth, INTEGER cyWidth, INTEGER istepIfAniCur, INTEGER hbrFlickerFreeDraw, SET diFlags);
#define WinApi_DrawMenuBar(hWnd)	DrawMenuBar(hWnd)
__EXTERN INTEGER __CALL DrawMenuBar(INTEGER hWnd);
#define WinApi_DrawState(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)	DrawStateA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)
#define WinApi_DrawStateA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)	DrawStateA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)
__EXTERN INTEGER __CALL DrawStateA(INTEGER p0, INTEGER p1, WinApi_DRAWSTATEPROC p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, SET p9);
#define WinApi_DrawStateW(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)	DrawStateW(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)
__EXTERN INTEGER __CALL DrawStateW(INTEGER p0, INTEGER p1, WinApi_DRAWSTATEPROC p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, SET p9);
#define WinApi_DrawText(hDC, lpString, nCount, lpRect, lpRect__typ, uFormat)	DrawTextA(hDC, lpString, nCount, lpRect, uFormat)
#define WinApi_DrawTextA(hDC, lpString, nCount, lpRect, lpRect__typ, uFormat)	DrawTextA(hDC, lpString, nCount, lpRect, uFormat)
__EXTERN INTEGER __CALL DrawTextA(INTEGER hDC, WinApi_PtrSTR lpString, INTEGER nCount, WinApi_RECT *lpRect, SET uFormat);
#define WinApi_DrawTextEx(p0, p1, p2, p3, p3__typ, p4, p5, p5__typ)	DrawTextExA(p0, p1, p2, p3, p4, p5)
#define WinApi_DrawTextExA(p0, p1, p2, p3, p3__typ, p4, p5, p5__typ)	DrawTextExA(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL DrawTextExA(INTEGER p0, WinApi_PtrSTR p1, INTEGER p2, WinApi_RECT *p3, INTEGER p4, WinApi_DRAWTEXTPARAMS *p5);
#define WinApi_DrawTextExW(p0, p1, p2, p3, p3__typ, p4, p5, p5__typ)	DrawTextExW(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL DrawTextExW(INTEGER p0, WinApi_PtrWSTR p1, INTEGER p2, WinApi_RECT *p3, INTEGER p4, WinApi_DRAWTEXTPARAMS *p5);
#define WinApi_DrawTextW(hDC, lpString, nCount, lpRect, lpRect__typ, uFormat)	DrawTextW(hDC, lpString, nCount, lpRect, uFormat)
__EXTERN INTEGER __CALL DrawTextW(INTEGER hDC, WinApi_PtrWSTR lpString, INTEGER nCount, WinApi_RECT *lpRect, SET uFormat);
#define WinApi_DuplicateHandle(hSourceProcessHandle, hSourceHandle, hTargetProcessHandle, lpTargetHandle, dwDesiredAccess, bInheritHandle, dwOptions)	DuplicateHandle(hSourceProcessHandle, hSourceHandle, hTargetProcessHandle, lpTargetHandle, dwDesiredAccess, bInheritHandle, dwOptions)
__EXTERN INTEGER __CALL DuplicateHandle(INTEGER hSourceProcessHandle, INTEGER hSourceHandle, INTEGER hTargetProcessHandle, INTEGER *lpTargetHandle, SET dwDesiredAccess, INTEGER bInheritHandle, SET dwOptions);
#define WinApi_DuplicateIcon(hInst, hIcon)	DuplicateIcon(hInst, hIcon)
__EXTERN INTEGER __CALL DuplicateIcon(INTEGER hInst, INTEGER hIcon);
#define WinApi_DuplicateToken(ExistingTokenHandle, ImpersonationLevel, DuplicateTokenHandle)	DuplicateToken(ExistingTokenHandle, ImpersonationLevel, DuplicateTokenHandle)
__EXTERN INTEGER __CALL DuplicateToken(INTEGER ExistingTokenHandle, INTEGER ImpersonationLevel, INTEGER *DuplicateTokenHandle);
#define WinApi_Ellipse(p0, p1, p2, p3, p4)	Ellipse(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL Ellipse(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_EmptyClipboard()	EmptyClipboard()
__EXTERN INTEGER __CALL EmptyClipboard(void);
#define WinApi_EnableMenuItem(hMenu, uIDEnableItem, uEnable)	EnableMenuItem(hMenu, uIDEnableItem, uEnable)
__EXTERN INTEGER __CALL EnableMenuItem(INTEGER hMenu, INTEGER uIDEnableItem, SET uEnable);
#define WinApi_EnableScrollBar(hWnd, wSBflags, wArrows)	EnableScrollBar(hWnd, wSBflags, wArrows)
__EXTERN INTEGER __CALL EnableScrollBar(INTEGER hWnd, INTEGER wSBflags, INTEGER wArrows);
#define WinApi_EnableWindow(hWnd, bEnable)	EnableWindow(hWnd, bEnable)
__EXTERN INTEGER __CALL EnableWindow(INTEGER hWnd, INTEGER bEnable);
#define WinApi_EndDeferWindowPos(hWinPosInfo)	EndDeferWindowPos(hWinPosInfo)
__EXTERN INTEGER __CALL EndDeferWindowPos(INTEGER hWinPosInfo);
#define WinApi_EndDialog(hDlg, nResult)	EndDialog(hDlg, nResult)
__EXTERN INTEGER __CALL EndDialog(INTEGER hDlg, INTEGER nResult);
#define WinApi_EndDoc(p0)	EndDoc(p0)
__EXTERN INTEGER __CALL EndDoc(INTEGER p0);
#define WinApi_EndDocPrinter(hPrinter)	EndDocPrinter(hPrinter)
__EXTERN INTEGER __CALL EndDocPrinter(INTEGER hPrinter);
#define WinApi_EndPage(p0)	EndPage(p0)
__EXTERN INTEGER __CALL EndPage(INTEGER p0);
#define WinApi_EndPagePrinter(hPrinter)	EndPagePrinter(hPrinter)
__EXTERN INTEGER __CALL EndPagePrinter(INTEGER hPrinter);
#define WinApi_EndPaint(hWnd, lpPaint, lpPaint__typ)	EndPaint(hWnd, lpPaint)
__EXTERN INTEGER __CALL EndPaint(INTEGER hWnd, WinApi_PAINTSTRUCT *lpPaint);
#define WinApi_EndPath(p0)	EndPath(p0)
__EXTERN INTEGER __CALL EndPath(INTEGER p0);
#define WinApi_EndUpdateResource(hUpdate, fDiscard)	EndUpdateResourceA(hUpdate, fDiscard)
#define WinApi_EndUpdateResourceA(hUpdate, fDiscard)	EndUpdateResourceA(hUpdate, fDiscard)
__EXTERN INTEGER __CALL EndUpdateResourceA(INTEGER hUpdate, INTEGER fDiscard);
#define WinApi_EndUpdateResourceW(hUpdate, fDiscard)	EndUpdateResourceW(hUpdate, fDiscard)
__EXTERN INTEGER __CALL EndUpdateResourceW(INTEGER hUpdate, INTEGER fDiscard);
#define WinApi_EnterCriticalSection(lpCriticalSection, lpCriticalSection__typ)	EnterCriticalSection(lpCriticalSection)
__EXTERN void __CALL EnterCriticalSection(WinApi_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinApi_EnumCalendarInfo(lpCalInfoEnumProc, Locale, Calendar, CalType)	EnumCalendarInfoA(lpCalInfoEnumProc, Locale, Calendar, CalType)
#define WinApi_EnumCalendarInfoA(lpCalInfoEnumProc, Locale, Calendar, CalType)	EnumCalendarInfoA(lpCalInfoEnumProc, Locale, Calendar, CalType)
__EXTERN INTEGER __CALL EnumCalendarInfoA(WinApi_CALINFO_ENUMPROCA lpCalInfoEnumProc, INTEGER Locale, INTEGER Calendar, INTEGER CalType);
#define WinApi_EnumCalendarInfoW(lpCalInfoEnumProc, Locale, Calendar, CalType)	EnumCalendarInfoW(lpCalInfoEnumProc, Locale, Calendar, CalType)
__EXTERN INTEGER __CALL EnumCalendarInfoW(WinApi_CALINFO_ENUMPROCW lpCalInfoEnumProc, INTEGER Locale, INTEGER Calendar, INTEGER CalType);
#define WinApi_EnumChildWindows(hWndParent, lpEnumFunc, lParam)	EnumChildWindows(hWndParent, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumChildWindows(INTEGER hWndParent, WinApi_WNDENUMPROC lpEnumFunc, INTEGER lParam);
#define WinApi_EnumClipboardFormats(format)	EnumClipboardFormats(format)
__EXTERN INTEGER __CALL EnumClipboardFormats(INTEGER format);
#define WinApi_EnumDateFormats(lpDateFmtEnumProc, Locale, dwFlags)	EnumDateFormatsA(lpDateFmtEnumProc, Locale, dwFlags)
#define WinApi_EnumDateFormatsA(lpDateFmtEnumProc, Locale, dwFlags)	EnumDateFormatsA(lpDateFmtEnumProc, Locale, dwFlags)
__EXTERN INTEGER __CALL EnumDateFormatsA(WinApi_DATEFMT_ENUMPROCA lpDateFmtEnumProc, INTEGER Locale, SET dwFlags);
#define WinApi_EnumDateFormatsW(lpDateFmtEnumProc, Locale, dwFlags)	EnumDateFormatsW(lpDateFmtEnumProc, Locale, dwFlags)
__EXTERN INTEGER __CALL EnumDateFormatsW(WinApi_DATEFMT_ENUMPROCW lpDateFmtEnumProc, INTEGER Locale, SET dwFlags);
#define WinApi_EnumDependentServices(hService, dwServiceState, lpServices, lpServices__typ, cbBufSize, pcbBytesNeeded, lpServicesReturned)	EnumDependentServicesA(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)
#define WinApi_EnumDependentServicesA(hService, dwServiceState, lpServices, lpServices__typ, cbBufSize, pcbBytesNeeded, lpServicesReturned)	EnumDependentServicesA(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)
__EXTERN INTEGER __CALL EnumDependentServicesA(INTEGER hService, INTEGER dwServiceState, WinApi_ENUM_SERVICE_STATUSA *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned);
#define WinApi_EnumDependentServicesW(hService, dwServiceState, lpServices, lpServices__typ, cbBufSize, pcbBytesNeeded, lpServicesReturned)	EnumDependentServicesW(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)
__EXTERN INTEGER __CALL EnumDependentServicesW(INTEGER hService, INTEGER dwServiceState, WinApi_ENUM_SERVICE_STATUSW *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned);
#define WinApi_EnumDesktopWindows(hDesktop, lpfn, lParam)	EnumDesktopWindows(hDesktop, lpfn, lParam)
__EXTERN INTEGER __CALL EnumDesktopWindows(INTEGER hDesktop, WinApi_WNDENUMPROC lpfn, INTEGER lParam);
#define WinApi_EnumDesktops(hwinsta, lpEnumFunc, lParam)	EnumDesktopsA(hwinsta, lpEnumFunc, lParam)
#define WinApi_EnumDesktopsA(hwinsta, lpEnumFunc, lParam)	EnumDesktopsA(hwinsta, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumDesktopsA(INTEGER hwinsta, WinApi_DESKTOPENUMPROCA lpEnumFunc, INTEGER lParam);
#define WinApi_EnumDesktopsW(hwinsta, lpEnumFunc, lParam)	EnumDesktopsW(hwinsta, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumDesktopsW(INTEGER hwinsta, WinApi_DESKTOPENUMPROCW lpEnumFunc, INTEGER lParam);
#define WinApi_EnumDisplaySettings(lpszDeviceName, iModeNum, lpDevMode, lpDevMode__typ)	EnumDisplaySettingsA(lpszDeviceName, iModeNum, lpDevMode)
#define WinApi_EnumDisplaySettingsA(lpszDeviceName, iModeNum, lpDevMode, lpDevMode__typ)	EnumDisplaySettingsA(lpszDeviceName, iModeNum, lpDevMode)
__EXTERN INTEGER __CALL EnumDisplaySettingsA(WinApi_PtrSTR lpszDeviceName, INTEGER iModeNum, WinApi_DEVMODEA *lpDevMode);
#define WinApi_EnumDisplaySettingsW(lpszDeviceName, iModeNum, lpDevMode, lpDevMode__typ)	EnumDisplaySettingsW(lpszDeviceName, iModeNum, lpDevMode)
__EXTERN INTEGER __CALL EnumDisplaySettingsW(WinApi_PtrWSTR lpszDeviceName, INTEGER iModeNum, WinApi_DEVMODEW *lpDevMode);
#define WinApi_EnumEnhMetaFile(p0, p1, p2, p3, p4, p4__typ)	EnumEnhMetaFile(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL EnumEnhMetaFile(INTEGER p0, INTEGER p1, WinApi_ENHMFENUMPROC p2, INTEGER p3, WinApi_RECT *p4);
#define WinApi_EnumFontFamilies(p0, p1, p2, p3)	EnumFontFamiliesA(p0, p1, p2, p3)
#define WinApi_EnumFontFamiliesA(p0, p1, p2, p3)	EnumFontFamiliesA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL EnumFontFamiliesA(INTEGER p0, WinApi_PtrSTR p1, WinApi_NEWFONTENUMPROCA p2, INTEGER p3);
#define WinApi_EnumFontFamiliesEx(p0, p1, p1__typ, p2, p3, p4)	EnumFontFamiliesExA(p0, p1, p2, p3, p4)
#define WinApi_EnumFontFamiliesExA(p0, p1, p1__typ, p2, p3, p4)	EnumFontFamiliesExA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL EnumFontFamiliesExA(INTEGER p0, WinApi_LOGFONTA *p1, WinApi_FONTENUMPROCEXA p2, INTEGER p3, INTEGER p4);
#define WinApi_EnumFontFamiliesExW(p0, p1, p1__typ, p2, p3, p4)	EnumFontFamiliesExW(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL EnumFontFamiliesExW(INTEGER p0, WinApi_LOGFONTW *p1, WinApi_FONTENUMPROCEXW p2, INTEGER p3, INTEGER p4);
#define WinApi_EnumFontFamiliesW(p0, p1, p2, p3)	EnumFontFamiliesW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL EnumFontFamiliesW(INTEGER p0, WinApi_PtrWSTR p1, WinApi_NEWFONTENUMPROCW p2, INTEGER p3);
#define WinApi_EnumFonts(p0, p1, p2, p3)	EnumFontsA(p0, p1, p2, p3)
#define WinApi_EnumFontsA(p0, p1, p2, p3)	EnumFontsA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL EnumFontsA(INTEGER p0, WinApi_PtrSTR p1, WinApi_FONTENUMPROCA p2, INTEGER p3);
#define WinApi_EnumFontsW(p0, p1, p2, p3)	EnumFontsW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL EnumFontsW(INTEGER p0, WinApi_PtrWSTR p1, WinApi_FONTENUMPROCW p2, INTEGER p3);
#define WinApi_EnumForms(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)	EnumFormsA(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)
#define WinApi_EnumFormsA(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)	EnumFormsA(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumFormsA(INTEGER hPrinter, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumFormsW(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)	EnumFormsW(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumFormsW(INTEGER hPrinter, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumICMProfiles(p0, p1, p2)	EnumICMProfilesA(p0, p1, p2)
#define WinApi_EnumICMProfilesA(p0, p1, p2)	EnumICMProfilesA(p0, p1, p2)
__EXTERN INTEGER __CALL EnumICMProfilesA(INTEGER p0, WinApi_ICMENUMPROCA p1, INTEGER p2);
#define WinApi_EnumICMProfilesW(p0, p1, p2)	EnumICMProfilesW(p0, p1, p2)
__EXTERN INTEGER __CALL EnumICMProfilesW(INTEGER p0, WinApi_ICMENUMPROCW p1, INTEGER p2);
#define WinApi_EnumJobs(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)	EnumJobsA(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)
#define WinApi_EnumJobsA(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)	EnumJobsA(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumJobsA(INTEGER hPrinter, INTEGER FirstJob, INTEGER NoJobs, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumJobsW(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)	EnumJobsW(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumJobsW(INTEGER hPrinter, INTEGER FirstJob, INTEGER NoJobs, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumMetaFile(p0, p1, p2, p3)	EnumMetaFile(p0, p1, p2, p3)
__EXTERN INTEGER __CALL EnumMetaFile(INTEGER p0, INTEGER p1, WinApi_MFENUMPROC p2, INTEGER p3);
#define WinApi_EnumMonitors(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)	EnumMonitorsA(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)
#define WinApi_EnumMonitorsA(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)	EnumMonitorsA(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumMonitorsA(WinApi_PtrSTR pName, INTEGER Level, CHAR *pMonitors, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumMonitorsW(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)	EnumMonitorsW(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumMonitorsW(WinApi_PtrWSTR pName, INTEGER Level, CHAR *pMonitors, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumObjects(p0, p1, p2, p3)	EnumObjects(p0, p1, p2, p3)
__EXTERN INTEGER __CALL EnumObjects(INTEGER p0, INTEGER p1, WinApi_GOBJENUMPROC p2, INTEGER p3);
#define WinApi_EnumPorts(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)	EnumPortsA(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)
#define WinApi_EnumPortsA(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)	EnumPortsA(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumPortsA(WinApi_PtrSTR pName, INTEGER Level, CHAR *pPorts, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumPortsW(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)	EnumPortsW(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumPortsW(WinApi_PtrWSTR pName, INTEGER Level, CHAR *pPorts, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumPrintProcessorDatatypes(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorDatatypesA(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)
#define WinApi_EnumPrintProcessorDatatypesA(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorDatatypesA(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumPrintProcessorDatatypesA(WinApi_PtrSTR pName, WinApi_PtrSTR pPrintProcessorName, INTEGER Level, CHAR *pDatatypes, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumPrintProcessorDatatypesW(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorDatatypesW(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumPrintProcessorDatatypesW(WinApi_PtrWSTR pName, WinApi_PtrWSTR pPrintProcessorName, INTEGER Level, CHAR *pDatatypes, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumPrintProcessors(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorsA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)
#define WinApi_EnumPrintProcessorsA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorsA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumPrintProcessorsA(WinApi_PtrSTR pName, WinApi_PtrSTR pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumPrintProcessorsW(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorsW(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumPrintProcessorsW(WinApi_PtrWSTR pName, WinApi_PtrWSTR pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumPrinterDrivers(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrinterDriversA(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)
#define WinApi_EnumPrinterDriversA(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrinterDriversA(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumPrinterDriversA(WinApi_PtrSTR pName, WinApi_PtrSTR pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumPrinterDriversW(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrinterDriversW(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumPrinterDriversW(WinApi_PtrWSTR pName, WinApi_PtrWSTR pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumPrinters(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)	EnumPrintersA(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)
#define WinApi_EnumPrintersA(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)	EnumPrintersA(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumPrintersA(SET Flags, WinApi_PtrSTR Name, INTEGER Level, CHAR *pPrinterEnum, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumPrintersW(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)	EnumPrintersW(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL EnumPrintersW(SET Flags, WinApi_PtrWSTR Name, INTEGER Level, CHAR *pPrinterEnum, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinApi_EnumProps(hWnd, lpEnumFunc)	EnumPropsA(hWnd, lpEnumFunc)
#define WinApi_EnumPropsA(hWnd, lpEnumFunc)	EnumPropsA(hWnd, lpEnumFunc)
__EXTERN INTEGER __CALL EnumPropsA(INTEGER hWnd, WinApi_ROPENUMPROCA lpEnumFunc);
#define WinApi_EnumPropsEx(hWnd, lpEnumFunc, lParam)	EnumPropsExA(hWnd, lpEnumFunc, lParam)
#define WinApi_EnumPropsExA(hWnd, lpEnumFunc, lParam)	EnumPropsExA(hWnd, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumPropsExA(INTEGER hWnd, WinApi_ROPENUMPROCEXA lpEnumFunc, INTEGER lParam);
#define WinApi_EnumPropsExW(hWnd, lpEnumFunc, lParam)	EnumPropsExW(hWnd, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumPropsExW(INTEGER hWnd, WinApi_ROPENUMPROCEXW lpEnumFunc, INTEGER lParam);
#define WinApi_EnumPropsW(hWnd, lpEnumFunc)	EnumPropsW(hWnd, lpEnumFunc)
__EXTERN INTEGER __CALL EnumPropsW(INTEGER hWnd, WinApi_ROPENUMPROCW lpEnumFunc);
#define WinApi_EnumResourceLanguages(hModule, lpType, lpName, lpEnumFunc, lParam)	EnumResourceLanguagesA(hModule, lpType, lpName, lpEnumFunc, lParam)
#define WinApi_EnumResourceLanguagesA(hModule, lpType, lpName, lpEnumFunc, lParam)	EnumResourceLanguagesA(hModule, lpType, lpName, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumResourceLanguagesA(INTEGER hModule, WinApi_PtrSTR lpType, WinApi_PtrSTR lpName, WinApi_ENUMRESLANGPROC lpEnumFunc, INTEGER lParam);
#define WinApi_EnumResourceLanguagesW(hModule, lpType, lpName, lpEnumFunc, lParam)	EnumResourceLanguagesW(hModule, lpType, lpName, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumResourceLanguagesW(INTEGER hModule, WinApi_PtrWSTR lpType, WinApi_PtrWSTR lpName, WinApi_ENUMRESLANGPROC lpEnumFunc, INTEGER lParam);
#define WinApi_EnumResourceNames(hModule, lpType, lpEnumFunc, lParam)	EnumResourceNamesA(hModule, lpType, lpEnumFunc, lParam)
#define WinApi_EnumResourceNamesA(hModule, lpType, lpEnumFunc, lParam)	EnumResourceNamesA(hModule, lpType, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumResourceNamesA(INTEGER hModule, WinApi_PtrSTR lpType, WinApi_ENUMRESNAMEPROC lpEnumFunc, INTEGER lParam);
#define WinApi_EnumResourceNamesW(hModule, lpType, lpEnumFunc, lParam)	EnumResourceNamesW(hModule, lpType, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumResourceNamesW(INTEGER hModule, WinApi_PtrWSTR lpType, WinApi_ENUMRESNAMEPROC lpEnumFunc, INTEGER lParam);
#define WinApi_EnumResourceTypes(hModule, lpEnumFunc, lParam)	EnumResourceTypesA(hModule, lpEnumFunc, lParam)
#define WinApi_EnumResourceTypesA(hModule, lpEnumFunc, lParam)	EnumResourceTypesA(hModule, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumResourceTypesA(INTEGER hModule, WinApi_ENUMRESTYPEPROC lpEnumFunc, INTEGER lParam);
#define WinApi_EnumResourceTypesW(hModule, lpEnumFunc, lParam)	EnumResourceTypesW(hModule, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumResourceTypesW(INTEGER hModule, WinApi_ENUMRESTYPEPROC lpEnumFunc, INTEGER lParam);
#define WinApi_EnumServicesStatus(hSCManager, dwServiceType, dwServiceState, lpServices, lpServices__typ, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)	EnumServicesStatusA(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)
#define WinApi_EnumServicesStatusA(hSCManager, dwServiceType, dwServiceState, lpServices, lpServices__typ, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)	EnumServicesStatusA(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)
__EXTERN INTEGER __CALL EnumServicesStatusA(INTEGER hSCManager, SET dwServiceType, INTEGER dwServiceState, WinApi_ENUM_SERVICE_STATUSA *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned, INTEGER *lpResumeHandle);
#define WinApi_EnumServicesStatusW(hSCManager, dwServiceType, dwServiceState, lpServices, lpServices__typ, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)	EnumServicesStatusW(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)
__EXTERN INTEGER __CALL EnumServicesStatusW(INTEGER hSCManager, SET dwServiceType, INTEGER dwServiceState, WinApi_ENUM_SERVICE_STATUSW *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned, INTEGER *lpResumeHandle);
#define WinApi_EnumSystemCodePages(lpCodePageEnumProc, dwFlags)	EnumSystemCodePagesA(lpCodePageEnumProc, dwFlags)
#define WinApi_EnumSystemCodePagesA(lpCodePageEnumProc, dwFlags)	EnumSystemCodePagesA(lpCodePageEnumProc, dwFlags)
__EXTERN INTEGER __CALL EnumSystemCodePagesA(WinApi_CODEPAGE_ENUMPROCA lpCodePageEnumProc, SET dwFlags);
#define WinApi_EnumSystemCodePagesW(lpCodePageEnumProc, dwFlags)	EnumSystemCodePagesW(lpCodePageEnumProc, dwFlags)
__EXTERN INTEGER __CALL EnumSystemCodePagesW(WinApi_CODEPAGE_ENUMPROCW lpCodePageEnumProc, SET dwFlags);
#define WinApi_EnumSystemLocales(lpLocaleEnumProc, dwFlags)	EnumSystemLocalesA(lpLocaleEnumProc, dwFlags)
#define WinApi_EnumSystemLocalesA(lpLocaleEnumProc, dwFlags)	EnumSystemLocalesA(lpLocaleEnumProc, dwFlags)
__EXTERN INTEGER __CALL EnumSystemLocalesA(WinApi_LOCALE_ENUMPROCA lpLocaleEnumProc, SET dwFlags);
#define WinApi_EnumSystemLocalesW(lpLocaleEnumProc, dwFlags)	EnumSystemLocalesW(lpLocaleEnumProc, dwFlags)
__EXTERN INTEGER __CALL EnumSystemLocalesW(WinApi_LOCALE_ENUMPROCW lpLocaleEnumProc, SET dwFlags);
#define WinApi_EnumThreadWindows(dwThreadId, lpfn, lParam)	EnumThreadWindows(dwThreadId, lpfn, lParam)
__EXTERN INTEGER __CALL EnumThreadWindows(INTEGER dwThreadId, WinApi_WNDENUMPROC lpfn, INTEGER lParam);
#define WinApi_EnumTimeFormats(lpTimeFmtEnumProc, Locale, dwFlags)	EnumTimeFormatsA(lpTimeFmtEnumProc, Locale, dwFlags)
#define WinApi_EnumTimeFormatsA(lpTimeFmtEnumProc, Locale, dwFlags)	EnumTimeFormatsA(lpTimeFmtEnumProc, Locale, dwFlags)
__EXTERN INTEGER __CALL EnumTimeFormatsA(WinApi_TIMEFMT_ENUMPROCA lpTimeFmtEnumProc, INTEGER Locale, SET dwFlags);
#define WinApi_EnumTimeFormatsW(lpTimeFmtEnumProc, Locale, dwFlags)	EnumTimeFormatsW(lpTimeFmtEnumProc, Locale, dwFlags)
__EXTERN INTEGER __CALL EnumTimeFormatsW(WinApi_TIMEFMT_ENUMPROCW lpTimeFmtEnumProc, INTEGER Locale, SET dwFlags);
#define WinApi_EnumWindowStations(lpEnumFunc, lParam)	EnumWindowStationsA(lpEnumFunc, lParam)
#define WinApi_EnumWindowStationsA(lpEnumFunc, lParam)	EnumWindowStationsA(lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumWindowStationsA(WinApi_WINSTAENUMPROCA lpEnumFunc, INTEGER lParam);
#define WinApi_EnumWindowStationsW(lpEnumFunc, lParam)	EnumWindowStationsW(lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumWindowStationsW(WinApi_WINSTAENUMPROCW lpEnumFunc, INTEGER lParam);
#define WinApi_EnumWindows(lpEnumFunc, lParam)	EnumWindows(lpEnumFunc, lParam)
__EXTERN INTEGER __CALL EnumWindows(WinApi_WNDENUMPROC lpEnumFunc, INTEGER lParam);
#define WinApi_EqualPrefixSid(pSid1, pSid2)	EqualPrefixSid(pSid1, pSid2)
__EXTERN INTEGER __CALL EqualPrefixSid(INTEGER pSid1, INTEGER pSid2);
#define WinApi_EqualRect(lprc1, lprc1__typ, lprc2, lprc2__typ)	EqualRect(lprc1, lprc2)
__EXTERN INTEGER __CALL EqualRect(WinApi_RECT *lprc1, WinApi_RECT *lprc2);
#define WinApi_EqualRgn(p0, p1)	EqualRgn(p0, p1)
__EXTERN INTEGER __CALL EqualRgn(INTEGER p0, INTEGER p1);
#define WinApi_EqualSid(pSid1, pSid2)	EqualSid(pSid1, pSid2)
__EXTERN INTEGER __CALL EqualSid(INTEGER pSid1, INTEGER pSid2);
#define WinApi_EraseTape(hDevice, dwEraseType, bImmediate)	EraseTape(hDevice, dwEraseType, bImmediate)
__EXTERN INTEGER __CALL EraseTape(INTEGER hDevice, INTEGER dwEraseType, INTEGER bImmediate);
#define WinApi_Escape(p0, p1, p2, p3, p4)	Escape(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL Escape(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_PtrSTR p3, INTEGER p4);
#define WinApi_EscapeCommFunction(hFile, dwFunc)	EscapeCommFunction(hFile, dwFunc)
__EXTERN INTEGER __CALL EscapeCommFunction(INTEGER hFile, INTEGER dwFunc);
#define WinApi_ExcludeClipRect(p0, p1, p2, p3, p4)	ExcludeClipRect(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL ExcludeClipRect(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_ExcludeUpdateRgn(hDC, hWnd)	ExcludeUpdateRgn(hDC, hWnd)
__EXTERN INTEGER __CALL ExcludeUpdateRgn(INTEGER hDC, INTEGER hWnd);
#define WinApi_ExitProcess(uExitCode)	ExitProcess(uExitCode)
__EXTERN void __CALL ExitProcess(INTEGER uExitCode);
#define WinApi_ExitThread(dwExitCode)	ExitThread(dwExitCode)
__EXTERN void __CALL ExitThread(INTEGER dwExitCode);
#define WinApi_ExitWindowsEx(uFlags, dwReserved)	ExitWindowsEx(uFlags, dwReserved)
__EXTERN INTEGER __CALL ExitWindowsEx(SET uFlags, INTEGER dwReserved);
#define WinApi_ExpandEnvironmentStrings(lpSrc, lpDst, nSize)	ExpandEnvironmentStringsA(lpSrc, lpDst, nSize)
#define WinApi_ExpandEnvironmentStringsA(lpSrc, lpDst, nSize)	ExpandEnvironmentStringsA(lpSrc, lpDst, nSize)
__EXTERN INTEGER __CALL ExpandEnvironmentStringsA(WinApi_PtrSTR lpSrc, WinApi_PtrSTR lpDst, INTEGER nSize);
#define WinApi_ExpandEnvironmentStringsW(lpSrc, lpDst, nSize)	ExpandEnvironmentStringsW(lpSrc, lpDst, nSize)
__EXTERN INTEGER __CALL ExpandEnvironmentStringsW(WinApi_PtrWSTR lpSrc, WinApi_PtrWSTR lpDst, INTEGER nSize);
#define WinApi_ExtCreatePen(p0, p1, p2, p2__typ, p3, p4)	ExtCreatePen(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL ExtCreatePen(INTEGER p0, INTEGER p1, WinApi_LOGBRUSH *p2, INTEGER p3, INTEGER *p4);
#define WinApi_ExtCreateRegion(p0, p0__typ, p1, p2, p2__typ)	ExtCreateRegion(p0, p1, p2)
__EXTERN INTEGER __CALL ExtCreateRegion(WinApi_XFORM *p0, INTEGER p1, WinApi_RGNDATA *p2);
#define WinApi_ExtEscape(p0, p1, p2, p3, p4, p5)	ExtEscape(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL ExtEscape(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_PtrSTR p3, INTEGER p4, WinApi_PtrSTR p5);
#define WinApi_ExtFloodFill(p0, p1, p2, p3, p4)	ExtFloodFill(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL ExtFloodFill(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_ExtSelectClipRgn(p0, p1, p2)	ExtSelectClipRgn(p0, p1, p2)
__EXTERN INTEGER __CALL ExtSelectClipRgn(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_ExtTextOut(p0, p1, p2, p3, p4, p4__typ, p5, p6, p7)	ExtTextOutA(p0, p1, p2, p3, p4, p5, p6, p7)
#define WinApi_ExtTextOutA(p0, p1, p2, p3, p4, p4__typ, p5, p6, p7)	ExtTextOutA(p0, p1, p2, p3, p4, p5, p6, p7)
__EXTERN INTEGER __CALL ExtTextOutA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinApi_RECT *p4, WinApi_PtrSTR p5, INTEGER p6, INTEGER *p7);
#define WinApi_ExtTextOutW(p0, p1, p2, p3, p4, p4__typ, p5, p6, p7)	ExtTextOutW(p0, p1, p2, p3, p4, p5, p6, p7)
__EXTERN INTEGER __CALL ExtTextOutW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinApi_RECT *p4, WinApi_PtrWSTR p5, INTEGER p6, INTEGER *p7);
#define WinApi_ExtractAssociatedIcon(hInst, lpIconPath, lpiIcon)	ExtractAssociatedIconA(hInst, lpIconPath, lpiIcon)
#define WinApi_ExtractAssociatedIconA(hInst, lpIconPath, lpiIcon)	ExtractAssociatedIconA(hInst, lpIconPath, lpiIcon)
__EXTERN INTEGER __CALL ExtractAssociatedIconA(INTEGER hInst, WinApi_PtrSTR lpIconPath, SHORTINT *lpiIcon);
#define WinApi_ExtractAssociatedIconW(hInst, lpIconPath, lpiIcon)	ExtractAssociatedIconW(hInst, lpIconPath, lpiIcon)
__EXTERN INTEGER __CALL ExtractAssociatedIconW(INTEGER hInst, WinApi_PtrWSTR lpIconPath, SHORTINT *lpiIcon);
#define WinApi_ExtractIcon(hInst, lpszExeFileName, nIconIndex)	ExtractIconA(hInst, lpszExeFileName, nIconIndex)
#define WinApi_ExtractIconA(hInst, lpszExeFileName, nIconIndex)	ExtractIconA(hInst, lpszExeFileName, nIconIndex)
__EXTERN INTEGER __CALL ExtractIconA(INTEGER hInst, WinApi_PtrSTR lpszExeFileName, INTEGER nIconIndex);
#define WinApi_ExtractIconEx(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)	ExtractIconExA(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)
#define WinApi_ExtractIconExA(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)	ExtractIconExA(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)
__EXTERN INTEGER __CALL ExtractIconExA(WinApi_PtrSTR lpszFile, INTEGER nIconIndex, INTEGER *phiconLarge, INTEGER *phiconSmall, INTEGER nIcons);
#define WinApi_ExtractIconExW(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)	ExtractIconExW(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)
__EXTERN INTEGER __CALL ExtractIconExW(WinApi_PtrWSTR lpszFile, INTEGER nIconIndex, INTEGER *phiconLarge, INTEGER *phiconSmall, INTEGER nIcons);
#define WinApi_ExtractIconW(hInst, lpszExeFileName, nIconIndex)	ExtractIconW(hInst, lpszExeFileName, nIconIndex)
__EXTERN INTEGER __CALL ExtractIconW(INTEGER hInst, WinApi_PtrWSTR lpszExeFileName, INTEGER nIconIndex);
#define WinApi_FatalAppExit(uAction, lpMessageText)	FatalAppExitA(uAction, lpMessageText)
#define WinApi_FatalAppExitA(uAction, lpMessageText)	FatalAppExitA(uAction, lpMessageText)
__EXTERN void __CALL FatalAppExitA(INTEGER uAction, WinApi_PtrSTR lpMessageText);
#define WinApi_FatalAppExitW(uAction, lpMessageText)	FatalAppExitW(uAction, lpMessageText)
__EXTERN void __CALL FatalAppExitW(INTEGER uAction, WinApi_PtrWSTR lpMessageText);
#define WinApi_FatalExit(ExitCode)	FatalExit(ExitCode)
__EXTERN void __CALL FatalExit(INTEGER ExitCode);
#define WinApi_FileTimeToDosDateTime(lpFileTime, lpFileTime__typ, lpFatDate, lpFatTime)	FileTimeToDosDateTime(lpFileTime, lpFatDate, lpFatTime)
__EXTERN INTEGER __CALL FileTimeToDosDateTime(WinApi_FILETIME *lpFileTime, SHORTINT *lpFatDate, SHORTINT *lpFatTime);
#define WinApi_FileTimeToLocalFileTime(lpFileTime, lpFileTime__typ, lpLocalFileTime, lpLocalFileTime__typ)	FileTimeToLocalFileTime(lpFileTime, lpLocalFileTime)
__EXTERN INTEGER __CALL FileTimeToLocalFileTime(WinApi_FILETIME *lpFileTime, WinApi_FILETIME *lpLocalFileTime);
#define WinApi_FileTimeToSystemTime(lpFileTime, lpFileTime__typ, lpSystemTime, lpSystemTime__typ)	FileTimeToSystemTime(lpFileTime, lpSystemTime)
__EXTERN INTEGER __CALL FileTimeToSystemTime(WinApi_FILETIME *lpFileTime, WinApi_SYSTEMTIME *lpSystemTime);
#define WinApi_FillConsoleOutputAttribute(hConsoleOutput, wAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten)	FillConsoleOutputAttribute(hConsoleOutput, wAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten)
__EXTERN INTEGER __CALL FillConsoleOutputAttribute(INTEGER hConsoleOutput, SHORTINT wAttribute, INTEGER nLength, WinApi_COORD dwWriteCoord, INTEGER *lpNumberOfAttrsWritten);
#define WinApi_FillConsoleOutputCharacter(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	FillConsoleOutputCharacterA(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
#define WinApi_FillConsoleOutputCharacterA(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	FillConsoleOutputCharacterA(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __CALL FillConsoleOutputCharacterA(INTEGER hConsoleOutput, CHAR cCharacter, INTEGER nLength, WinApi_COORD dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
#define WinApi_FillConsoleOutputCharacterW(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	FillConsoleOutputCharacterW(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __CALL FillConsoleOutputCharacterW(INTEGER hConsoleOutput, SHORTINT cCharacter, INTEGER nLength, WinApi_COORD dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
#define WinApi_FillPath(p0)	FillPath(p0)
__EXTERN INTEGER __CALL FillPath(INTEGER p0);
#define WinApi_FillRect(hDC, lprc, lprc__typ, hbr)	FillRect(hDC, lprc, hbr)
__EXTERN INTEGER __CALL FillRect(INTEGER hDC, WinApi_RECT *lprc, INTEGER hbr);
#define WinApi_FillRgn(p0, p1, p2)	FillRgn(p0, p1, p2)
__EXTERN INTEGER __CALL FillRgn(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_FindAtom(lpString)	FindAtomA(lpString)
#define WinApi_FindAtomA(lpString)	FindAtomA(lpString)
__EXTERN SHORTINT __CALL FindAtomA(WinApi_PtrSTR lpString);
#define WinApi_FindAtomW(lpString)	FindAtomW(lpString)
__EXTERN SHORTINT __CALL FindAtomW(WinApi_PtrWSTR lpString);
#define WinApi_FindClose(hFindFile)	FindClose(hFindFile)
__EXTERN INTEGER __CALL FindClose(INTEGER hFindFile);
#define WinApi_FindCloseChangeNotification(hChangeHandle)	FindCloseChangeNotification(hChangeHandle)
__EXTERN INTEGER __CALL FindCloseChangeNotification(INTEGER hChangeHandle);
#define WinApi_FindClosePrinterChangeNotification(hChange)	FindClosePrinterChangeNotification(hChange)
__EXTERN INTEGER __CALL FindClosePrinterChangeNotification(INTEGER hChange);
#define WinApi_FindExecutable(lpFile, lpDirectory, lpResult)	FindExecutableA(lpFile, lpDirectory, lpResult)
#define WinApi_FindExecutableA(lpFile, lpDirectory, lpResult)	FindExecutableA(lpFile, lpDirectory, lpResult)
__EXTERN INTEGER __CALL FindExecutableA(WinApi_PtrSTR lpFile, WinApi_PtrSTR lpDirectory, WinApi_PtrSTR lpResult);
#define WinApi_FindExecutableW(lpFile, lpDirectory, lpResult)	FindExecutableW(lpFile, lpDirectory, lpResult)
__EXTERN INTEGER __CALL FindExecutableW(WinApi_PtrWSTR lpFile, WinApi_PtrWSTR lpDirectory, WinApi_PtrWSTR lpResult);
#define WinApi_FindFirstChangeNotification(lpPathName, bWatchSubtree, dwNotifyFilter)	FindFirstChangeNotificationA(lpPathName, bWatchSubtree, dwNotifyFilter)
#define WinApi_FindFirstChangeNotificationA(lpPathName, bWatchSubtree, dwNotifyFilter)	FindFirstChangeNotificationA(lpPathName, bWatchSubtree, dwNotifyFilter)
__EXTERN INTEGER __CALL FindFirstChangeNotificationA(WinApi_PtrSTR lpPathName, INTEGER bWatchSubtree, SET dwNotifyFilter);
#define WinApi_FindFirstChangeNotificationW(lpPathName, bWatchSubtree, dwNotifyFilter)	FindFirstChangeNotificationW(lpPathName, bWatchSubtree, dwNotifyFilter)
__EXTERN INTEGER __CALL FindFirstChangeNotificationW(WinApi_PtrWSTR lpPathName, INTEGER bWatchSubtree, SET dwNotifyFilter);
#define WinApi_FindFirstFile(lpFileName, lpFindFileData, lpFindFileData__typ)	FindFirstFileA(lpFileName, lpFindFileData)
#define WinApi_FindFirstFileA(lpFileName, lpFindFileData, lpFindFileData__typ)	FindFirstFileA(lpFileName, lpFindFileData)
__EXTERN INTEGER __CALL FindFirstFileA(WinApi_PtrSTR lpFileName, WinApi_WIN32_FIND_DATAA *lpFindFileData);
#define WinApi_FindFirstFileEx(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)	FindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)
#define WinApi_FindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)	FindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)
__EXTERN INTEGER __CALL FindFirstFileExA(WinApi_PtrSTR lpFileName, INTEGER fInfoLevelId, INTEGER lpFindFileData, INTEGER fSearchOp, INTEGER lpSearchFilter, INTEGER dwAdditionalFlags);
#define WinApi_FindFirstFileExW(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)	FindFirstFileExW(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)
__EXTERN INTEGER __CALL FindFirstFileExW(WinApi_PtrWSTR lpFileName, INTEGER fInfoLevelId, INTEGER lpFindFileData, INTEGER fSearchOp, INTEGER lpSearchFilter, INTEGER dwAdditionalFlags);
#define WinApi_FindFirstFileW(lpFileName, lpFindFileData, lpFindFileData__typ)	FindFirstFileW(lpFileName, lpFindFileData)
__EXTERN INTEGER __CALL FindFirstFileW(WinApi_PtrWSTR lpFileName, WinApi_WIN32_FIND_DATAW *lpFindFileData);
#define WinApi_FindFirstFreeAce(pAcl, pAcl__typ, pAce)	FindFirstFreeAce(pAcl, pAce)
__EXTERN INTEGER __CALL FindFirstFreeAce(WinApi_ACL *pAcl, struct {
	LONGINT len[1];
	INTEGER data[1];
} *pAce);
#define WinApi_FindFirstPrinterChangeNotification(hPrinter, fdwFlags, fdwOptions, pPrinterNotifyOptions)	FindFirstPrinterChangeNotification(hPrinter, fdwFlags, fdwOptions, pPrinterNotifyOptions)
__EXTERN INTEGER __CALL FindFirstPrinterChangeNotification(INTEGER hPrinter, SET fdwFlags, INTEGER fdwOptions, INTEGER pPrinterNotifyOptions);
#define WinApi_FindNextChangeNotification(hChangeHandle)	FindNextChangeNotification(hChangeHandle)
__EXTERN INTEGER __CALL FindNextChangeNotification(INTEGER hChangeHandle);
#define WinApi_FindNextFile(hFindFile, lpFindFileData, lpFindFileData__typ)	FindNextFileA(hFindFile, lpFindFileData)
#define WinApi_FindNextFileA(hFindFile, lpFindFileData, lpFindFileData__typ)	FindNextFileA(hFindFile, lpFindFileData)
__EXTERN INTEGER __CALL FindNextFileA(INTEGER hFindFile, WinApi_WIN32_FIND_DATAA *lpFindFileData);
#define WinApi_FindNextFileW(hFindFile, lpFindFileData, lpFindFileData__typ)	FindNextFileW(hFindFile, lpFindFileData)
__EXTERN INTEGER __CALL FindNextFileW(INTEGER hFindFile, WinApi_WIN32_FIND_DATAW *lpFindFileData);
#define WinApi_FindNextPrinterChangeNotification(hChange, pdwChange, pvReserved, ppPrinterNotifyInfo)	FindNextPrinterChangeNotification(hChange, pdwChange, pvReserved, ppPrinterNotifyInfo)
__EXTERN INTEGER __CALL FindNextPrinterChangeNotification(INTEGER hChange, INTEGER *pdwChange, INTEGER pvReserved, struct {
	LONGINT len[1];
	INTEGER data[1];
} *ppPrinterNotifyInfo);
#define WinApi_FindResource(hModule, lpName, lpType)	FindResourceA(hModule, lpName, lpType)
#define WinApi_FindResourceA(hModule, lpName, lpType)	FindResourceA(hModule, lpName, lpType)
__EXTERN INTEGER __CALL FindResourceA(INTEGER hModule, WinApi_PtrSTR lpName, WinApi_PtrSTR lpType);
#define WinApi_FindResourceEx(hModule, lpType, lpName, wLanguage)	FindResourceExA(hModule, lpType, lpName, wLanguage)
#define WinApi_FindResourceExA(hModule, lpType, lpName, wLanguage)	FindResourceExA(hModule, lpType, lpName, wLanguage)
__EXTERN INTEGER __CALL FindResourceExA(INTEGER hModule, WinApi_PtrSTR lpType, WinApi_PtrSTR lpName, SHORTINT wLanguage);
#define WinApi_FindResourceExW(hModule, lpType, lpName, wLanguage)	FindResourceExW(hModule, lpType, lpName, wLanguage)
__EXTERN INTEGER __CALL FindResourceExW(INTEGER hModule, WinApi_PtrWSTR lpType, WinApi_PtrWSTR lpName, SHORTINT wLanguage);
#define WinApi_FindResourceW(hModule, lpName, lpType)	FindResourceW(hModule, lpName, lpType)
__EXTERN INTEGER __CALL FindResourceW(INTEGER hModule, WinApi_PtrWSTR lpName, WinApi_PtrWSTR lpType);
#define WinApi_FindWindow(lpClassName, lpWindowName)	FindWindowA(lpClassName, lpWindowName)
#define WinApi_FindWindowA(lpClassName, lpWindowName)	FindWindowA(lpClassName, lpWindowName)
__EXTERN INTEGER __CALL FindWindowA(WinApi_PtrSTR lpClassName, WinApi_PtrSTR lpWindowName);
#define WinApi_FindWindowEx(p0, p1, p2, p3)	FindWindowExA(p0, p1, p2, p3)
#define WinApi_FindWindowExA(p0, p1, p2, p3)	FindWindowExA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL FindWindowExA(INTEGER p0, INTEGER p1, WinApi_PtrSTR p2, WinApi_PtrSTR p3);
#define WinApi_FindWindowExW(p0, p1, p2, p3)	FindWindowExW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL FindWindowExW(INTEGER p0, INTEGER p1, WinApi_PtrWSTR p2, WinApi_PtrWSTR p3);
#define WinApi_FindWindowW(lpClassName, lpWindowName)	FindWindowW(lpClassName, lpWindowName)
__EXTERN INTEGER __CALL FindWindowW(WinApi_PtrWSTR lpClassName, WinApi_PtrWSTR lpWindowName);
#define WinApi_FixBrushOrgEx(p0, p1, p2, p3, p3__typ)	FixBrushOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL FixBrushOrgEx(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_POINT *p3);
#define WinApi_FlashWindow(hWnd, bInvert)	FlashWindow(hWnd, bInvert)
__EXTERN INTEGER __CALL FlashWindow(INTEGER hWnd, INTEGER bInvert);
#define WinApi_FlattenPath(p0)	FlattenPath(p0)
__EXTERN INTEGER __CALL FlattenPath(INTEGER p0);
#define WinApi_FloodFill(p0, p1, p2, p3)	FloodFill(p0, p1, p2, p3)
__EXTERN INTEGER __CALL FloodFill(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinApi_FlushConsoleInputBuffer(hConsoleInput)	FlushConsoleInputBuffer(hConsoleInput)
__EXTERN INTEGER __CALL FlushConsoleInputBuffer(INTEGER hConsoleInput);
#define WinApi_FlushFileBuffers(hFile)	FlushFileBuffers(hFile)
__EXTERN INTEGER __CALL FlushFileBuffers(INTEGER hFile);
#define WinApi_FlushInstructionCache(hProcess, lpBaseAddress, dwSize)	FlushInstructionCache(hProcess, lpBaseAddress, dwSize)
__EXTERN INTEGER __CALL FlushInstructionCache(INTEGER hProcess, INTEGER lpBaseAddress, INTEGER dwSize);
#define WinApi_FlushViewOfFile(lpBaseAddress, dwNumberOfBytesToFlush)	FlushViewOfFile(lpBaseAddress, dwNumberOfBytesToFlush)
__EXTERN INTEGER __CALL FlushViewOfFile(INTEGER lpBaseAddress, INTEGER dwNumberOfBytesToFlush);
#define WinApi_FoldString(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	FoldStringA(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
#define WinApi_FoldStringA(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	FoldStringA(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
__EXTERN INTEGER __CALL FoldStringA(SET dwMapFlags, WinApi_PtrSTR lpSrcStr, INTEGER cchSrc, WinApi_PtrSTR lpDestStr, INTEGER cchDest);
#define WinApi_FoldStringW(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	FoldStringW(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
__EXTERN INTEGER __CALL FoldStringW(SET dwMapFlags, WinApi_PtrWSTR lpSrcStr, INTEGER cchSrc, WinApi_PtrWSTR lpDestStr, INTEGER cchDest);
#define WinApi_FormatMessage(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)	FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)
#define WinApi_FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)	FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)
__EXTERN INTEGER __CALL FormatMessageA(SET dwFlags, INTEGER lpSource, INTEGER dwMessageId, INTEGER dwLanguageId, WinApi_PtrSTR lpBuffer, INTEGER nSize, WinApi_PtrSTR *Arguments);
#define WinApi_FormatMessageW(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)	FormatMessageW(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)
__EXTERN INTEGER __CALL FormatMessageW(SET dwFlags, INTEGER lpSource, INTEGER dwMessageId, INTEGER dwLanguageId, WinApi_PtrWSTR lpBuffer, INTEGER nSize, WinApi_PtrSTR *Arguments);
#define WinApi_FrameRect(hDC, lprc, lprc__typ, hbr)	FrameRect(hDC, lprc, hbr)
__EXTERN INTEGER __CALL FrameRect(INTEGER hDC, WinApi_RECT *lprc, INTEGER hbr);
#define WinApi_FrameRgn(p0, p1, p2, p3, p4)	FrameRgn(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL FrameRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_FreeConsole()	FreeConsole()
__EXTERN INTEGER __CALL FreeConsole(void);
#define WinApi_FreeDDElParam(msg, lParam)	FreeDDElParam(msg, lParam)
__EXTERN INTEGER __CALL FreeDDElParam(INTEGER msg, INTEGER lParam);
#define WinApi_FreeEnvironmentStrings(p0)	FreeEnvironmentStringsA(p0)
#define WinApi_FreeEnvironmentStringsA(p0)	FreeEnvironmentStringsA(p0)
__EXTERN INTEGER __CALL FreeEnvironmentStringsA(WinApi_PtrSTR p0);
#define WinApi_FreeEnvironmentStringsW(p0)	FreeEnvironmentStringsW(p0)
__EXTERN INTEGER __CALL FreeEnvironmentStringsW(WinApi_PtrWSTR p0);
#define WinApi_FreeLibrary(hLibModule)	FreeLibrary(hLibModule)
__EXTERN INTEGER __CALL FreeLibrary(INTEGER hLibModule);
#define WinApi_FreeLibraryAndExitThread(hLibModule, dwExitCode)	FreeLibraryAndExitThread(hLibModule, dwExitCode)
__EXTERN void __CALL FreeLibraryAndExitThread(INTEGER hLibModule, INTEGER dwExitCode);
#define WinApi_FreePrinterNotifyInfo(pPrinterNotifyInfo, pPrinterNotifyInfo__typ)	FreePrinterNotifyInfo(pPrinterNotifyInfo)
__EXTERN INTEGER __CALL FreePrinterNotifyInfo(WinApi_PRINTER_NOTIFY_INFO *pPrinterNotifyInfo);
#define WinApi_FreeResource(hResData)	FreeResource(hResData)
__EXTERN INTEGER __CALL FreeResource(INTEGER hResData);
#define WinApi_FreeSid(pSid)	FreeSid(pSid)
__EXTERN INTEGER __CALL FreeSid(INTEGER pSid);
#define WinApi_GdiComment(p0, p1, p2)	GdiComment(p0, p1, p2)
__EXTERN INTEGER __CALL GdiComment(INTEGER p0, INTEGER p1, CHAR *p2);
#define WinApi_GdiFlush()	GdiFlush()
__EXTERN INTEGER __CALL GdiFlush(void);
#define WinApi_GdiGetBatchLimit()	GdiGetBatchLimit()
__EXTERN INTEGER __CALL GdiGetBatchLimit(void);
#define WinApi_GdiSetBatchLimit(p0)	GdiSetBatchLimit(p0)
__EXTERN INTEGER __CALL GdiSetBatchLimit(INTEGER p0);
#define WinApi_GenerateConsoleCtrlEvent(dwCtrlEvent, dwProcessGroupId)	GenerateConsoleCtrlEvent(dwCtrlEvent, dwProcessGroupId)
__EXTERN INTEGER __CALL GenerateConsoleCtrlEvent(INTEGER dwCtrlEvent, INTEGER dwProcessGroupId);
#define WinApi_GetACP()	GetACP()
__EXTERN INTEGER __CALL GetACP(void);
#define WinApi_GetAce(pAcl, pAcl__typ, dwAceIndex, pAce)	GetAce(pAcl, dwAceIndex, pAce)
__EXTERN INTEGER __CALL GetAce(WinApi_ACL *pAcl, INTEGER dwAceIndex, struct {
	LONGINT len[1];
	INTEGER data[1];
} *pAce);
#define WinApi_GetAclInformation(pAcl, pAcl__typ, pAclInformation, nAclInformationLength, dwAclInformationClass)	GetAclInformation(pAcl, pAclInformation, nAclInformationLength, dwAclInformationClass)
__EXTERN INTEGER __CALL GetAclInformation(WinApi_ACL *pAcl, INTEGER pAclInformation, INTEGER nAclInformationLength, INTEGER dwAclInformationClass);
#define WinApi_GetActiveWindow()	GetActiveWindow()
__EXTERN INTEGER __CALL GetActiveWindow(void);
#define WinApi_GetArcDirection(p0)	GetArcDirection(p0)
__EXTERN INTEGER __CALL GetArcDirection(INTEGER p0);
#define WinApi_GetAspectRatioFilterEx(p0, p1, p1__typ)	GetAspectRatioFilterEx(p0, p1)
__EXTERN INTEGER __CALL GetAspectRatioFilterEx(INTEGER p0, WinApi_SIZE *p1);
#define WinApi_GetAsyncKeyState(vKey)	GetAsyncKeyState(vKey)
__EXTERN SHORTINT __CALL GetAsyncKeyState(INTEGER vKey);
#define WinApi_GetAtomName(nAtom, lpBuffer, nSize)	GetAtomNameA(nAtom, lpBuffer, nSize)
#define WinApi_GetAtomNameA(nAtom, lpBuffer, nSize)	GetAtomNameA(nAtom, lpBuffer, nSize)
__EXTERN INTEGER __CALL GetAtomNameA(SHORTINT nAtom, WinApi_PtrSTR lpBuffer, INTEGER nSize);
#define WinApi_GetAtomNameW(nAtom, lpBuffer, nSize)	GetAtomNameW(nAtom, lpBuffer, nSize)
__EXTERN INTEGER __CALL GetAtomNameW(SHORTINT nAtom, WinApi_PtrWSTR lpBuffer, INTEGER nSize);
#define WinApi_GetBinaryType(lpApplicationName, lpBinaryType)	GetBinaryTypeA(lpApplicationName, lpBinaryType)
#define WinApi_GetBinaryTypeA(lpApplicationName, lpBinaryType)	GetBinaryTypeA(lpApplicationName, lpBinaryType)
__EXTERN INTEGER __CALL GetBinaryTypeA(WinApi_PtrSTR lpApplicationName, INTEGER *lpBinaryType);
#define WinApi_GetBinaryTypeW(lpApplicationName, lpBinaryType)	GetBinaryTypeW(lpApplicationName, lpBinaryType)
__EXTERN INTEGER __CALL GetBinaryTypeW(WinApi_PtrWSTR lpApplicationName, INTEGER *lpBinaryType);
#define WinApi_GetBitmapBits(p0, p1, p2)	GetBitmapBits(p0, p1, p2)
__EXTERN INTEGER __CALL GetBitmapBits(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_GetBitmapDimensionEx(p0, p1, p1__typ)	GetBitmapDimensionEx(p0, p1)
__EXTERN INTEGER __CALL GetBitmapDimensionEx(INTEGER p0, WinApi_SIZE *p1);
#define WinApi_GetBkColor(p0)	GetBkColor(p0)
__EXTERN INTEGER __CALL GetBkColor(INTEGER p0);
#define WinApi_GetBkMode(p0)	GetBkMode(p0)
__EXTERN INTEGER __CALL GetBkMode(INTEGER p0);
#define WinApi_GetBoundsRect(p0, p1, p1__typ, p2)	GetBoundsRect(p0, p1, p2)
__EXTERN SET __CALL GetBoundsRect(INTEGER p0, WinApi_RECT *p1, SET p2);
#define WinApi_GetBrushOrgEx(p0, p1, p1__typ)	GetBrushOrgEx(p0, p1)
__EXTERN INTEGER __CALL GetBrushOrgEx(INTEGER p0, WinApi_POINT *p1);
#define WinApi_GetCPInfo(CodePage, lpCPInfo, lpCPInfo__typ)	GetCPInfo(CodePage, lpCPInfo)
__EXTERN INTEGER __CALL GetCPInfo(INTEGER CodePage, WinApi_CPINFO *lpCPInfo);
#define WinApi_GetCapture()	GetCapture()
__EXTERN INTEGER __CALL GetCapture(void);
#define WinApi_GetCaretBlinkTime()	GetCaretBlinkTime()
__EXTERN INTEGER __CALL GetCaretBlinkTime(void);
#define WinApi_GetCaretPos(lpPoint, lpPoint__typ)	GetCaretPos(lpPoint)
__EXTERN INTEGER __CALL GetCaretPos(WinApi_POINT *lpPoint);
#define WinApi_GetCharABCWidths(p0, p1, p2, p3, p3__typ)	GetCharABCWidthsA(p0, p1, p2, p3)
#define WinApi_GetCharABCWidthsA(p0, p1, p2, p3, p3__typ)	GetCharABCWidthsA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetCharABCWidthsA(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_ABC *p3);
#define WinApi_GetCharABCWidthsFloat(p0, p1, p2, p3, p3__typ)	GetCharABCWidthsFloatA(p0, p1, p2, p3)
#define WinApi_GetCharABCWidthsFloatA(p0, p1, p2, p3, p3__typ)	GetCharABCWidthsFloatA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetCharABCWidthsFloatA(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_ABCFLOAT *p3);
#define WinApi_GetCharABCWidthsFloatW(p0, p1, p2, p3, p3__typ)	GetCharABCWidthsFloatW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetCharABCWidthsFloatW(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_ABCFLOAT *p3);
#define WinApi_GetCharABCWidthsW(p0, p1, p2, p3, p3__typ)	GetCharABCWidthsW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetCharABCWidthsW(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_ABC *p3);
#define WinApi_GetCharWidth(p0, p1, p2, p3)	GetCharWidthA(p0, p1, p2, p3)
#define WinApi_GetCharWidth32(p0, p1, p2, p3)	GetCharWidth32A(p0, p1, p2, p3)
#define WinApi_GetCharWidth32A(p0, p1, p2, p3)	GetCharWidth32A(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetCharWidth32A(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER *p3);
#define WinApi_GetCharWidth32W(p0, p1, p2, p3)	GetCharWidth32W(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetCharWidth32W(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER *p3);
#define WinApi_GetCharWidthA(p0, p1, p2, p3)	GetCharWidthA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetCharWidthA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER *p3);
#define WinApi_GetCharWidthFloat(p0, p1, p2, p3)	GetCharWidthFloatA(p0, p1, p2, p3)
#define WinApi_GetCharWidthFloatA(p0, p1, p2, p3)	GetCharWidthFloatA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetCharWidthFloatA(INTEGER p0, INTEGER p1, INTEGER p2, REAL *p3);
#define WinApi_GetCharWidthFloatW(p0, p1, p2, p3)	GetCharWidthFloatW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetCharWidthFloatW(INTEGER p0, INTEGER p1, INTEGER p2, REAL *p3);
#define WinApi_GetCharWidthW(p0, p1, p2, p3)	GetCharWidthW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetCharWidthW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER *p3);
#define WinApi_GetCharacterPlacement(p0, p1, p2, p3, p4, p4__typ, p5)	GetCharacterPlacementA(p0, p1, p2, p3, p4, p5)
#define WinApi_GetCharacterPlacementA(p0, p1, p2, p3, p4, p4__typ, p5)	GetCharacterPlacementA(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL GetCharacterPlacementA(INTEGER p0, WinApi_PtrSTR p1, INTEGER p2, INTEGER p3, WinApi_GCP_RESULTSA *p4, INTEGER p5);
#define WinApi_GetCharacterPlacementW(p0, p1, p2, p3, p4, p4__typ, p5)	GetCharacterPlacementW(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL GetCharacterPlacementW(INTEGER p0, WinApi_PtrWSTR p1, INTEGER p2, INTEGER p3, WinApi_GCP_RESULTSW *p4, INTEGER p5);
#define WinApi_GetClassInfo(hInstance, lpClassName, lpWndClass, lpWndClass__typ)	GetClassInfoA(hInstance, lpClassName, lpWndClass)
#define WinApi_GetClassInfoA(hInstance, lpClassName, lpWndClass, lpWndClass__typ)	GetClassInfoA(hInstance, lpClassName, lpWndClass)
__EXTERN INTEGER __CALL GetClassInfoA(INTEGER hInstance, WinApi_PtrSTR lpClassName, WinApi_WNDCLASSA *lpWndClass);
#define WinApi_GetClassInfoEx(p0, p1, p2, p2__typ)	GetClassInfoExA(p0, p1, p2)
#define WinApi_GetClassInfoExA(p0, p1, p2, p2__typ)	GetClassInfoExA(p0, p1, p2)
__EXTERN INTEGER __CALL GetClassInfoExA(INTEGER p0, WinApi_PtrSTR p1, WinApi_WNDCLASSEXA *p2);
#define WinApi_GetClassInfoExW(p0, p1, p2, p2__typ)	GetClassInfoExW(p0, p1, p2)
__EXTERN INTEGER __CALL GetClassInfoExW(INTEGER p0, WinApi_PtrWSTR p1, WinApi_WNDCLASSEXW *p2);
#define WinApi_GetClassInfoW(hInstance, lpClassName, lpWndClass, lpWndClass__typ)	GetClassInfoW(hInstance, lpClassName, lpWndClass)
__EXTERN INTEGER __CALL GetClassInfoW(INTEGER hInstance, WinApi_PtrWSTR lpClassName, WinApi_WNDCLASSW *lpWndClass);
#define WinApi_GetClassLong(hWnd, nIndex)	GetClassLongA(hWnd, nIndex)
#define WinApi_GetClassLongA(hWnd, nIndex)	GetClassLongA(hWnd, nIndex)
__EXTERN INTEGER __CALL GetClassLongA(INTEGER hWnd, INTEGER nIndex);
#define WinApi_GetClassLongW(hWnd, nIndex)	GetClassLongW(hWnd, nIndex)
__EXTERN INTEGER __CALL GetClassLongW(INTEGER hWnd, INTEGER nIndex);
#define WinApi_GetClassName(hWnd, lpClassName, nMaxCount)	GetClassNameA(hWnd, lpClassName, nMaxCount)
#define WinApi_GetClassNameA(hWnd, lpClassName, nMaxCount)	GetClassNameA(hWnd, lpClassName, nMaxCount)
__EXTERN INTEGER __CALL GetClassNameA(INTEGER hWnd, WinApi_PtrSTR lpClassName, INTEGER nMaxCount);
#define WinApi_GetClassNameW(hWnd, lpClassName, nMaxCount)	GetClassNameW(hWnd, lpClassName, nMaxCount)
__EXTERN INTEGER __CALL GetClassNameW(INTEGER hWnd, WinApi_PtrWSTR lpClassName, INTEGER nMaxCount);
#define WinApi_GetClassWord(hWnd, nIndex)	GetClassWord(hWnd, nIndex)
__EXTERN SHORTINT __CALL GetClassWord(INTEGER hWnd, INTEGER nIndex);
#define WinApi_GetClientRect(hWnd, lpRect, lpRect__typ)	GetClientRect(hWnd, lpRect)
__EXTERN INTEGER __CALL GetClientRect(INTEGER hWnd, WinApi_RECT *lpRect);
#define WinApi_GetClipBox(p0, p1, p1__typ)	GetClipBox(p0, p1)
__EXTERN INTEGER __CALL GetClipBox(INTEGER p0, WinApi_RECT *p1);
#define WinApi_GetClipCursor(lpRect, lpRect__typ)	GetClipCursor(lpRect)
__EXTERN INTEGER __CALL GetClipCursor(WinApi_RECT *lpRect);
#define WinApi_GetClipRgn(p0, p1)	GetClipRgn(p0, p1)
__EXTERN INTEGER __CALL GetClipRgn(INTEGER p0, INTEGER p1);
#define WinApi_GetClipboardData(uFormat)	GetClipboardData(uFormat)
__EXTERN INTEGER __CALL GetClipboardData(INTEGER uFormat);
#define WinApi_GetClipboardFormatName(format, lpszFormatName, cchMaxCount)	GetClipboardFormatNameA(format, lpszFormatName, cchMaxCount)
#define WinApi_GetClipboardFormatNameA(format, lpszFormatName, cchMaxCount)	GetClipboardFormatNameA(format, lpszFormatName, cchMaxCount)
__EXTERN INTEGER __CALL GetClipboardFormatNameA(INTEGER format, WinApi_PtrSTR lpszFormatName, INTEGER cchMaxCount);
#define WinApi_GetClipboardFormatNameW(format, lpszFormatName, cchMaxCount)	GetClipboardFormatNameW(format, lpszFormatName, cchMaxCount)
__EXTERN INTEGER __CALL GetClipboardFormatNameW(INTEGER format, WinApi_PtrWSTR lpszFormatName, INTEGER cchMaxCount);
#define WinApi_GetClipboardOwner()	GetClipboardOwner()
__EXTERN INTEGER __CALL GetClipboardOwner(void);
#define WinApi_GetClipboardViewer()	GetClipboardViewer()
__EXTERN INTEGER __CALL GetClipboardViewer(void);
#define WinApi_GetColorAdjustment(p0, p1, p1__typ)	GetColorAdjustment(p0, p1)
__EXTERN INTEGER __CALL GetColorAdjustment(INTEGER p0, WinApi_COLORADJUSTMENT *p1);
#define WinApi_GetColorSpace(p0)	GetColorSpace(p0)
__EXTERN INTEGER __CALL GetColorSpace(INTEGER p0);
#define WinApi_GetCommConfig(hCommDev, lpCC, lpCC__typ, lpdwSize)	GetCommConfig(hCommDev, lpCC, lpdwSize)
__EXTERN INTEGER __CALL GetCommConfig(INTEGER hCommDev, WinApi_COMMCONFIG *lpCC, INTEGER *lpdwSize);
#define WinApi_GetCommMask(hFile, lpEvtMask)	GetCommMask(hFile, lpEvtMask)
__EXTERN INTEGER __CALL GetCommMask(INTEGER hFile, SET *lpEvtMask);
#define WinApi_GetCommModemStatus(hFile, lpModemStat)	GetCommModemStatus(hFile, lpModemStat)
__EXTERN INTEGER __CALL GetCommModemStatus(INTEGER hFile, SET *lpModemStat);
#define WinApi_GetCommProperties(hFile, lpCommProp, lpCommProp__typ)	GetCommProperties(hFile, lpCommProp)
__EXTERN INTEGER __CALL GetCommProperties(INTEGER hFile, WinApi_COMMPROP *lpCommProp);
#define WinApi_GetCommState(hFile, lpDCB, lpDCB__typ)	GetCommState(hFile, lpDCB)
__EXTERN INTEGER __CALL GetCommState(INTEGER hFile, WinApi_DCB *lpDCB);
#define WinApi_GetCommTimeouts(hFile, lpCommTimeouts, lpCommTimeouts__typ)	GetCommTimeouts(hFile, lpCommTimeouts)
__EXTERN INTEGER __CALL GetCommTimeouts(INTEGER hFile, WinApi_COMMTIMEOUTS *lpCommTimeouts);
#define WinApi_GetCommandLine()	GetCommandLineA()
#define WinApi_GetCommandLineA()	GetCommandLineA()
__EXTERN WinApi_PtrSTR __CALL GetCommandLineA(void);
#define WinApi_GetCommandLineW()	GetCommandLineW()
__EXTERN WinApi_PtrWSTR __CALL GetCommandLineW(void);
#define WinApi_GetCompressedFileSize(lpFileName, lpFileSizeHigh)	GetCompressedFileSizeA(lpFileName, lpFileSizeHigh)
#define WinApi_GetCompressedFileSizeA(lpFileName, lpFileSizeHigh)	GetCompressedFileSizeA(lpFileName, lpFileSizeHigh)
__EXTERN INTEGER __CALL GetCompressedFileSizeA(WinApi_PtrSTR lpFileName, INTEGER *lpFileSizeHigh);
#define WinApi_GetCompressedFileSizeW(lpFileName, lpFileSizeHigh)	GetCompressedFileSizeW(lpFileName, lpFileSizeHigh)
__EXTERN INTEGER __CALL GetCompressedFileSizeW(WinApi_PtrWSTR lpFileName, INTEGER *lpFileSizeHigh);
#define WinApi_GetComputerName(lpBuffer, nSize)	GetComputerNameA(lpBuffer, nSize)
#define WinApi_GetComputerNameA(lpBuffer, nSize)	GetComputerNameA(lpBuffer, nSize)
__EXTERN INTEGER __CALL GetComputerNameA(WinApi_PtrSTR lpBuffer, INTEGER *nSize);
#define WinApi_GetComputerNameW(lpBuffer, nSize)	GetComputerNameW(lpBuffer, nSize)
__EXTERN INTEGER __CALL GetComputerNameW(WinApi_PtrWSTR lpBuffer, INTEGER *nSize);
#define WinApi_GetConsoleCP()	GetConsoleCP()
__EXTERN INTEGER __CALL GetConsoleCP(void);
#define WinApi_GetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo, lpConsoleCursorInfo__typ)	GetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo)
__EXTERN INTEGER __CALL GetConsoleCursorInfo(INTEGER hConsoleOutput, WinApi_CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
#define WinApi_GetConsoleMode(hConsoleHandle, lpMode)	GetConsoleMode(hConsoleHandle, lpMode)
__EXTERN INTEGER __CALL GetConsoleMode(INTEGER hConsoleHandle, SET *lpMode);
#define WinApi_GetConsoleOutputCP()	GetConsoleOutputCP()
__EXTERN INTEGER __CALL GetConsoleOutputCP(void);
#define WinApi_GetConsoleScreenBufferInfo(hConsoleOutput, lpConsoleScreenBufferInfo, lpConsoleScreenBufferInfo__typ)	GetConsoleScreenBufferInfo(hConsoleOutput, lpConsoleScreenBufferInfo)
__EXTERN INTEGER __CALL GetConsoleScreenBufferInfo(INTEGER hConsoleOutput, WinApi_CONSOLE_SCREEN_BUFFER_INFO *lpConsoleScreenBufferInfo);
#define WinApi_GetConsoleTitle(lpConsoleTitle, nSize)	GetConsoleTitleA(lpConsoleTitle, nSize)
#define WinApi_GetConsoleTitleA(lpConsoleTitle, nSize)	GetConsoleTitleA(lpConsoleTitle, nSize)
__EXTERN INTEGER __CALL GetConsoleTitleA(WinApi_PtrSTR lpConsoleTitle, INTEGER nSize);
#define WinApi_GetConsoleTitleW(lpConsoleTitle, nSize)	GetConsoleTitleW(lpConsoleTitle, nSize)
__EXTERN INTEGER __CALL GetConsoleTitleW(WinApi_PtrWSTR lpConsoleTitle, INTEGER nSize);
#define WinApi_GetCurrencyFormat(Locale, dwFlags, lpValue, lpFormat, lpFormat__typ, lpCurrencyStr, cchCurrency)	GetCurrencyFormatA(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)
#define WinApi_GetCurrencyFormatA(Locale, dwFlags, lpValue, lpFormat, lpFormat__typ, lpCurrencyStr, cchCurrency)	GetCurrencyFormatA(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)
__EXTERN INTEGER __CALL GetCurrencyFormatA(INTEGER Locale, SET dwFlags, WinApi_PtrSTR lpValue, WinApi_CURRENCYFMTA *lpFormat, WinApi_PtrSTR lpCurrencyStr, INTEGER cchCurrency);
#define WinApi_GetCurrencyFormatW(Locale, dwFlags, lpValue, lpFormat, lpFormat__typ, lpCurrencyStr, cchCurrency)	GetCurrencyFormatW(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)
__EXTERN INTEGER __CALL GetCurrencyFormatW(INTEGER Locale, SET dwFlags, WinApi_PtrWSTR lpValue, WinApi_CURRENCYFMTW *lpFormat, WinApi_PtrWSTR lpCurrencyStr, INTEGER cchCurrency);
#define WinApi_GetCurrentDirectory(nBufferLength, lpBuffer)	GetCurrentDirectoryA(nBufferLength, lpBuffer)
#define WinApi_GetCurrentDirectoryA(nBufferLength, lpBuffer)	GetCurrentDirectoryA(nBufferLength, lpBuffer)
__EXTERN INTEGER __CALL GetCurrentDirectoryA(INTEGER nBufferLength, WinApi_PtrSTR lpBuffer);
#define WinApi_GetCurrentDirectoryW(nBufferLength, lpBuffer)	GetCurrentDirectoryW(nBufferLength, lpBuffer)
__EXTERN INTEGER __CALL GetCurrentDirectoryW(INTEGER nBufferLength, WinApi_PtrWSTR lpBuffer);
#define WinApi_GetCurrentHwProfile(lpHwProfileInfo, lpHwProfileInfo__typ)	GetCurrentHwProfileA(lpHwProfileInfo)
#define WinApi_GetCurrentHwProfileA(lpHwProfileInfo, lpHwProfileInfo__typ)	GetCurrentHwProfileA(lpHwProfileInfo)
__EXTERN INTEGER __CALL GetCurrentHwProfileA(WinApi_HW_PROFILE_INFOA *lpHwProfileInfo);
#define WinApi_GetCurrentHwProfileW(lpHwProfileInfo, lpHwProfileInfo__typ)	GetCurrentHwProfileW(lpHwProfileInfo)
__EXTERN INTEGER __CALL GetCurrentHwProfileW(WinApi_HW_PROFILE_INFOW *lpHwProfileInfo);
#define WinApi_GetCurrentObject(p0, p1)	GetCurrentObject(p0, p1)
__EXTERN INTEGER __CALL GetCurrentObject(INTEGER p0, INTEGER p1);
#define WinApi_GetCurrentPositionEx(p0, p1, p1__typ)	GetCurrentPositionEx(p0, p1)
__EXTERN INTEGER __CALL GetCurrentPositionEx(INTEGER p0, WinApi_POINT *p1);
#define WinApi_GetCurrentProcess()	GetCurrentProcess()
__EXTERN INTEGER __CALL GetCurrentProcess(void);
#define WinApi_GetCurrentProcessId()	GetCurrentProcessId()
__EXTERN INTEGER __CALL GetCurrentProcessId(void);
#define WinApi_GetCurrentThread()	GetCurrentThread()
__EXTERN INTEGER __CALL GetCurrentThread(void);
#define WinApi_GetCurrentThreadId()	GetCurrentThreadId()
__EXTERN INTEGER __CALL GetCurrentThreadId(void);
#define WinApi_GetCursor()	GetCursor()
__EXTERN INTEGER __CALL GetCursor(void);
#define WinApi_GetCursorPos(lpPoint, lpPoint__typ)	GetCursorPos(lpPoint)
__EXTERN INTEGER __CALL GetCursorPos(WinApi_POINT *lpPoint);
#define WinApi_GetDC(hWnd)	GetDC(hWnd)
__EXTERN INTEGER __CALL GetDC(INTEGER hWnd);
#define WinApi_GetDCEx(hWnd, hrgnClip, flags)	GetDCEx(hWnd, hrgnClip, flags)
__EXTERN INTEGER __CALL GetDCEx(INTEGER hWnd, INTEGER hrgnClip, SET flags);
#define WinApi_GetDCOrgEx(p0, p1, p1__typ)	GetDCOrgEx(p0, p1)
__EXTERN INTEGER __CALL GetDCOrgEx(INTEGER p0, WinApi_POINT *p1);
#define WinApi_GetDIBColorTable(p0, p1, p2, p3, p3__typ)	GetDIBColorTable(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetDIBColorTable(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_RGBQUAD *p3);
#define WinApi_GetDIBits(p0, p1, p2, p3, p4, p5, p5__typ, p6)	GetDIBits(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL GetDIBits(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinApi_BITMAPINFO *p5, INTEGER p6);
#define WinApi_GetDateFormat(Locale, dwFlags, lpDate, lpDate__typ, lpFormat, lpDateStr, cchDate)	GetDateFormatA(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)
#define WinApi_GetDateFormatA(Locale, dwFlags, lpDate, lpDate__typ, lpFormat, lpDateStr, cchDate)	GetDateFormatA(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)
__EXTERN INTEGER __CALL GetDateFormatA(INTEGER Locale, SET dwFlags, WinApi_SYSTEMTIME *lpDate, WinApi_PtrSTR lpFormat, WinApi_PtrSTR lpDateStr, INTEGER cchDate);
#define WinApi_GetDateFormatW(Locale, dwFlags, lpDate, lpDate__typ, lpFormat, lpDateStr, cchDate)	GetDateFormatW(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)
__EXTERN INTEGER __CALL GetDateFormatW(INTEGER Locale, SET dwFlags, WinApi_SYSTEMTIME *lpDate, WinApi_PtrWSTR lpFormat, WinApi_PtrWSTR lpDateStr, INTEGER cchDate);
#define WinApi_GetDefaultCommConfig(lpszName, lpCC, lpCC__typ, lpdwSize)	GetDefaultCommConfigA(lpszName, lpCC, lpdwSize)
#define WinApi_GetDefaultCommConfigA(lpszName, lpCC, lpCC__typ, lpdwSize)	GetDefaultCommConfigA(lpszName, lpCC, lpdwSize)
__EXTERN INTEGER __CALL GetDefaultCommConfigA(WinApi_PtrSTR lpszName, WinApi_COMMCONFIG *lpCC, INTEGER *lpdwSize);
#define WinApi_GetDefaultCommConfigW(lpszName, lpCC, lpCC__typ, lpdwSize)	GetDefaultCommConfigW(lpszName, lpCC, lpdwSize)
__EXTERN INTEGER __CALL GetDefaultCommConfigW(WinApi_PtrWSTR lpszName, WinApi_COMMCONFIG *lpCC, INTEGER *lpdwSize);
#define WinApi_GetDesktopWindow()	GetDesktopWindow()
__EXTERN INTEGER __CALL GetDesktopWindow(void);
#define WinApi_GetDeviceCaps(p0, p1)	GetDeviceCaps(p0, p1)
__EXTERN INTEGER __CALL GetDeviceCaps(INTEGER p0, INTEGER p1);
#define WinApi_GetDeviceGammaRamp(p0, p1)	GetDeviceGammaRamp(p0, p1)
__EXTERN INTEGER __CALL GetDeviceGammaRamp(INTEGER p0, INTEGER p1);
#define WinApi_GetDialogBaseUnits()	GetDialogBaseUnits()
__EXTERN INTEGER __CALL GetDialogBaseUnits(void);
#define WinApi_GetDiskFreeSpace(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)	GetDiskFreeSpaceA(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)
#define WinApi_GetDiskFreeSpaceA(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)	GetDiskFreeSpaceA(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)
__EXTERN INTEGER __CALL GetDiskFreeSpaceA(WinApi_PtrSTR lpRootPathName, INTEGER *lpSectorsPerCluster, INTEGER *lpBytesPerSector, INTEGER *lpNumberOfFreeClusters, INTEGER *lpTotalNumberOfClusters);
#define WinApi_GetDiskFreeSpaceW(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)	GetDiskFreeSpaceW(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)
__EXTERN INTEGER __CALL GetDiskFreeSpaceW(WinApi_PtrWSTR lpRootPathName, INTEGER *lpSectorsPerCluster, INTEGER *lpBytesPerSector, INTEGER *lpNumberOfFreeClusters, INTEGER *lpTotalNumberOfClusters);
#define WinApi_GetDlgCtrlID(hWnd)	GetDlgCtrlID(hWnd)
__EXTERN INTEGER __CALL GetDlgCtrlID(INTEGER hWnd);
#define WinApi_GetDlgItem(hDlg, nIDDlgItem)	GetDlgItem(hDlg, nIDDlgItem)
__EXTERN INTEGER __CALL GetDlgItem(INTEGER hDlg, INTEGER nIDDlgItem);
#define WinApi_GetDlgItemInt(hDlg, nIDDlgItem, lpTranslated, bSigned)	GetDlgItemInt(hDlg, nIDDlgItem, lpTranslated, bSigned)
__EXTERN INTEGER __CALL GetDlgItemInt(INTEGER hDlg, INTEGER nIDDlgItem, INTEGER *lpTranslated, INTEGER bSigned);
#define WinApi_GetDlgItemText(hDlg, nIDDlgItem, lpString, nMaxCount)	GetDlgItemTextA(hDlg, nIDDlgItem, lpString, nMaxCount)
#define WinApi_GetDlgItemTextA(hDlg, nIDDlgItem, lpString, nMaxCount)	GetDlgItemTextA(hDlg, nIDDlgItem, lpString, nMaxCount)
__EXTERN INTEGER __CALL GetDlgItemTextA(INTEGER hDlg, INTEGER nIDDlgItem, WinApi_PtrSTR lpString, INTEGER nMaxCount);
#define WinApi_GetDlgItemTextW(hDlg, nIDDlgItem, lpString, nMaxCount)	GetDlgItemTextW(hDlg, nIDDlgItem, lpString, nMaxCount)
__EXTERN INTEGER __CALL GetDlgItemTextW(INTEGER hDlg, INTEGER nIDDlgItem, WinApi_PtrWSTR lpString, INTEGER nMaxCount);
#define WinApi_GetDoubleClickTime()	GetDoubleClickTime()
__EXTERN INTEGER __CALL GetDoubleClickTime(void);
#define WinApi_GetDriveType(lpRootPathName)	GetDriveTypeA(lpRootPathName)
#define WinApi_GetDriveTypeA(lpRootPathName)	GetDriveTypeA(lpRootPathName)
__EXTERN INTEGER __CALL GetDriveTypeA(WinApi_PtrSTR lpRootPathName);
#define WinApi_GetDriveTypeW(lpRootPathName)	GetDriveTypeW(lpRootPathName)
__EXTERN INTEGER __CALL GetDriveTypeW(WinApi_PtrWSTR lpRootPathName);
#define WinApi_GetEnhMetaFile(p0)	GetEnhMetaFileA(p0)
#define WinApi_GetEnhMetaFileA(p0)	GetEnhMetaFileA(p0)
__EXTERN INTEGER __CALL GetEnhMetaFileA(WinApi_PtrSTR p0);
#define WinApi_GetEnhMetaFileBits(p0, p1, p2)	GetEnhMetaFileBits(p0, p1, p2)
__EXTERN INTEGER __CALL GetEnhMetaFileBits(INTEGER p0, INTEGER p1, CHAR *p2);
#define WinApi_GetEnhMetaFileDescription(p0, p1, p2)	GetEnhMetaFileDescriptionA(p0, p1, p2)
#define WinApi_GetEnhMetaFileDescriptionA(p0, p1, p2)	GetEnhMetaFileDescriptionA(p0, p1, p2)
__EXTERN INTEGER __CALL GetEnhMetaFileDescriptionA(INTEGER p0, INTEGER p1, WinApi_PtrSTR p2);
#define WinApi_GetEnhMetaFileDescriptionW(p0, p1, p2)	GetEnhMetaFileDescriptionW(p0, p1, p2)
__EXTERN INTEGER __CALL GetEnhMetaFileDescriptionW(INTEGER p0, INTEGER p1, WinApi_PtrWSTR p2);
#define WinApi_GetEnhMetaFileHeader(p0, p1, p2, p2__typ)	GetEnhMetaFileHeader(p0, p1, p2)
__EXTERN INTEGER __CALL GetEnhMetaFileHeader(INTEGER p0, INTEGER p1, WinApi_ENHMETAHEADER *p2);
#define WinApi_GetEnhMetaFilePaletteEntries(p0, p1, p2, p2__typ)	GetEnhMetaFilePaletteEntries(p0, p1, p2)
__EXTERN INTEGER __CALL GetEnhMetaFilePaletteEntries(INTEGER p0, INTEGER p1, WinApi_PALETTEENTRY *p2);
#define WinApi_GetEnhMetaFilePixelFormat(p0, p1, p2, p2__typ)	GetEnhMetaFilePixelFormat(p0, p1, p2)
__EXTERN INTEGER __CALL GetEnhMetaFilePixelFormat(INTEGER p0, INTEGER p1, WinApi_PIXELFORMATDESCRIPTOR *p2);
#define WinApi_GetEnhMetaFileW(p0)	GetEnhMetaFileW(p0)
__EXTERN INTEGER __CALL GetEnhMetaFileW(WinApi_PtrWSTR p0);
#define WinApi_GetEnvironmentStrings()	GetEnvironmentStrings()
__EXTERN WinApi_PtrSTR __CALL GetEnvironmentStrings(void);
#define WinApi_GetEnvironmentStringsA()	GetEnvironmentStrings()
#define WinApi_GetEnvironmentStringsW()	GetEnvironmentStringsW()
__EXTERN WinApi_PtrWSTR __CALL GetEnvironmentStringsW(void);
#define WinApi_GetEnvironmentVariable(lpName, lpBuffer, nSize)	GetEnvironmentVariableA(lpName, lpBuffer, nSize)
#define WinApi_GetEnvironmentVariableA(lpName, lpBuffer, nSize)	GetEnvironmentVariableA(lpName, lpBuffer, nSize)
__EXTERN INTEGER __CALL GetEnvironmentVariableA(WinApi_PtrSTR lpName, WinApi_PtrSTR lpBuffer, INTEGER nSize);
#define WinApi_GetEnvironmentVariableW(lpName, lpBuffer, nSize)	GetEnvironmentVariableW(lpName, lpBuffer, nSize)
__EXTERN INTEGER __CALL GetEnvironmentVariableW(WinApi_PtrWSTR lpName, WinApi_PtrWSTR lpBuffer, INTEGER nSize);
#define WinApi_GetExitCodeProcess(hProcess, lpExitCode)	GetExitCodeProcess(hProcess, lpExitCode)
__EXTERN INTEGER __CALL GetExitCodeProcess(INTEGER hProcess, INTEGER *lpExitCode);
#define WinApi_GetExitCodeThread(hThread, lpExitCode)	GetExitCodeThread(hThread, lpExitCode)
__EXTERN INTEGER __CALL GetExitCodeThread(INTEGER hThread, INTEGER *lpExitCode);
#define WinApi_GetExpandedName(p0, p1)	GetExpandedNameA(p0, p1)
#define WinApi_GetExpandedNameA(p0, p1)	GetExpandedNameA(p0, p1)
__EXTERN INTEGER __CALL GetExpandedNameA(WinApi_PtrSTR p0, WinApi_PtrSTR p1);
#define WinApi_GetExpandedNameW(p0, p1)	GetExpandedNameW(p0, p1)
__EXTERN INTEGER __CALL GetExpandedNameW(WinApi_PtrWSTR p0, WinApi_PtrWSTR p1);
#define WinApi_GetFileAttributes(lpFileName)	GetFileAttributesA(lpFileName)
#define WinApi_GetFileAttributesA(lpFileName)	GetFileAttributesA(lpFileName)
__EXTERN INTEGER __CALL GetFileAttributesA(WinApi_PtrSTR lpFileName);
#define WinApi_GetFileAttributesW(lpFileName)	GetFileAttributesW(lpFileName)
__EXTERN INTEGER __CALL GetFileAttributesW(WinApi_PtrWSTR lpFileName);
#define WinApi_GetFileInformationByHandle(hFile, lpFileInformation, lpFileInformation__typ)	GetFileInformationByHandle(hFile, lpFileInformation)
__EXTERN INTEGER __CALL GetFileInformationByHandle(INTEGER hFile, WinApi_BY_HANDLE_FILE_INFORMATION *lpFileInformation);
#define WinApi_GetFileSecurity(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)	GetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)
#define WinApi_GetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)	GetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)
__EXTERN INTEGER __CALL GetFileSecurityA(WinApi_PtrSTR lpFileName, SET RequestedInformation, INTEGER pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinApi_GetFileSecurityW(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)	GetFileSecurityW(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)
__EXTERN INTEGER __CALL GetFileSecurityW(WinApi_PtrWSTR lpFileName, SET RequestedInformation, INTEGER pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinApi_GetFileSize(hFile, lpFileSizeHigh)	GetFileSize(hFile, lpFileSizeHigh)
__EXTERN INTEGER __CALL GetFileSize(INTEGER hFile, INTEGER *lpFileSizeHigh);
#define WinApi_GetFileSizeEx(hFile, lpFileSizeHigh)	GetFileSizeEx(hFile, lpFileSizeHigh)
__EXTERN INTEGER __CALL GetFileSizeEx(INTEGER hFile, LONGINT *lpFileSizeHigh);
#define WinApi_GetFileTime(hFile, lpCreationTime, lpCreationTime__typ, lpLastAccessTime, lpLastAccessTime__typ, lpLastWriteTime, lpLastWriteTime__typ)	GetFileTime(hFile, lpCreationTime, lpLastAccessTime, lpLastWriteTime)
__EXTERN INTEGER __CALL GetFileTime(INTEGER hFile, WinApi_FILETIME *lpCreationTime, WinApi_FILETIME *lpLastAccessTime, WinApi_FILETIME *lpLastWriteTime);
#define WinApi_GetFileType(hFile)	GetFileType(hFile)
__EXTERN INTEGER __CALL GetFileType(INTEGER hFile);
#define WinApi_GetFileVersionInfo(lptstrFilename, dwHandle, dwLen, lpData)	GetFileVersionInfoA(lptstrFilename, dwHandle, dwLen, lpData)
#define WinApi_GetFileVersionInfoA(lptstrFilename, dwHandle, dwLen, lpData)	GetFileVersionInfoA(lptstrFilename, dwHandle, dwLen, lpData)
__EXTERN INTEGER __CALL GetFileVersionInfoA(WinApi_PtrSTR lptstrFilename, INTEGER dwHandle, INTEGER dwLen, INTEGER lpData);
#define WinApi_GetFileVersionInfoSize(lptstrFilename, lpdwHandle)	GetFileVersionInfoSizeA(lptstrFilename, lpdwHandle)
#define WinApi_GetFileVersionInfoSizeA(lptstrFilename, lpdwHandle)	GetFileVersionInfoSizeA(lptstrFilename, lpdwHandle)
__EXTERN INTEGER __CALL GetFileVersionInfoSizeA(WinApi_PtrSTR lptstrFilename, INTEGER *lpdwHandle);
#define WinApi_GetFileVersionInfoSizeW(lptstrFilename, lpdwHandle)	GetFileVersionInfoSizeW(lptstrFilename, lpdwHandle)
__EXTERN INTEGER __CALL GetFileVersionInfoSizeW(WinApi_PtrWSTR lptstrFilename, INTEGER *lpdwHandle);
#define WinApi_GetFileVersionInfoW(lptstrFilename, dwHandle, dwLen, lpData)	GetFileVersionInfoW(lptstrFilename, dwHandle, dwLen, lpData)
__EXTERN INTEGER __CALL GetFileVersionInfoW(WinApi_PtrWSTR lptstrFilename, INTEGER dwHandle, INTEGER dwLen, INTEGER lpData);
#define WinApi_GetFocus()	GetFocus()
__EXTERN INTEGER __CALL GetFocus(void);
#define WinApi_GetFontData(p0, p1, p2, p3, p4)	GetFontData(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL GetFontData(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_GetFontLanguageInfo(p0)	GetFontLanguageInfo(p0)
__EXTERN SET __CALL GetFontLanguageInfo(INTEGER p0);
#define WinApi_GetForegroundWindow()	GetForegroundWindow()
__EXTERN INTEGER __CALL GetForegroundWindow(void);
#define WinApi_GetForm(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)	GetFormA(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)
#define WinApi_GetFormA(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)	GetFormA(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL GetFormA(INTEGER hPrinter, WinApi_PtrSTR pFormName, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_GetFormW(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)	GetFormW(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL GetFormW(INTEGER hPrinter, WinApi_PtrWSTR pFormName, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_GetFullPathName(lpFileName, nBufferLength, lpBuffer, lpFilePart)	GetFullPathNameA(lpFileName, nBufferLength, lpBuffer, lpFilePart)
#define WinApi_GetFullPathNameA(lpFileName, nBufferLength, lpBuffer, lpFilePart)	GetFullPathNameA(lpFileName, nBufferLength, lpBuffer, lpFilePart)
__EXTERN INTEGER __CALL GetFullPathNameA(WinApi_PtrSTR lpFileName, INTEGER nBufferLength, WinApi_PtrSTR lpBuffer, WinApi_PtrSTR *lpFilePart);
#define WinApi_GetFullPathNameW(lpFileName, nBufferLength, lpBuffer, lpFilePart)	GetFullPathNameW(lpFileName, nBufferLength, lpBuffer, lpFilePart)
__EXTERN INTEGER __CALL GetFullPathNameW(WinApi_PtrWSTR lpFileName, INTEGER nBufferLength, WinApi_PtrWSTR lpBuffer, WinApi_PtrWSTR *lpFilePart);
#define WinApi_GetGlyphOutline(p0, p1, p2, p3, p3__typ, p4, p5, p6, p6__typ)	GetGlyphOutlineA(p0, p1, p2, p3, p4, p5, p6)
#define WinApi_GetGlyphOutlineA(p0, p1, p2, p3, p3__typ, p4, p5, p6, p6__typ)	GetGlyphOutlineA(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL GetGlyphOutlineA(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_GLYPHMETRICS *p3, INTEGER p4, INTEGER p5, WinApi_MAT2 *p6);
#define WinApi_GetGlyphOutlineW(p0, p1, p2, p3, p3__typ, p4, p5, p6, p6__typ)	GetGlyphOutlineW(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL GetGlyphOutlineW(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_GLYPHMETRICS *p3, INTEGER p4, INTEGER p5, WinApi_MAT2 *p6);
#define WinApi_GetGraphicsMode(p0)	GetGraphicsMode(p0)
__EXTERN INTEGER __CALL GetGraphicsMode(INTEGER p0);
#define WinApi_GetHandleInformation(hObject, lpdwFlags)	GetHandleInformation(hObject, lpdwFlags)
__EXTERN INTEGER __CALL GetHandleInformation(INTEGER hObject, SET *lpdwFlags);
#define WinApi_GetICMProfile(p0, p1, p2)	GetICMProfileA(p0, p1, p2)
#define WinApi_GetICMProfileA(p0, p1, p2)	GetICMProfileA(p0, p1, p2)
__EXTERN INTEGER __CALL GetICMProfileA(INTEGER p0, INTEGER *p1, WinApi_PtrSTR p2);
#define WinApi_GetICMProfileW(p0, p1, p2)	GetICMProfileW(p0, p1, p2)
__EXTERN INTEGER __CALL GetICMProfileW(INTEGER p0, INTEGER *p1, WinApi_PtrWSTR p2);
#define WinApi_GetIconInfo(hIcon, piconinfo, piconinfo__typ)	GetIconInfo(hIcon, piconinfo)
__EXTERN INTEGER __CALL GetIconInfo(INTEGER hIcon, WinApi_ICONINFO *piconinfo);
#define WinApi_GetInputState()	GetInputState()
__EXTERN INTEGER __CALL GetInputState(void);
#define WinApi_GetJob(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)	GetJobA(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)
#define WinApi_GetJobA(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)	GetJobA(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL GetJobA(INTEGER hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_GetJobW(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)	GetJobW(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL GetJobW(INTEGER hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_GetKBCodePage()	GetKBCodePage()
__EXTERN INTEGER __CALL GetKBCodePage(void);
#define WinApi_GetKernelObjectSecurity(Handle, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)	GetKernelObjectSecurity(Handle, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)
__EXTERN INTEGER __CALL GetKernelObjectSecurity(INTEGER Handle, SET RequestedInformation, INTEGER pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinApi_GetKerningPairs(p0, p1, p2, p2__typ)	GetKerningPairsA(p0, p1, p2)
#define WinApi_GetKerningPairsA(p0, p1, p2, p2__typ)	GetKerningPairsA(p0, p1, p2)
__EXTERN INTEGER __CALL GetKerningPairsA(INTEGER p0, INTEGER p1, WinApi_KERNINGPAIR *p2);
#define WinApi_GetKerningPairsW(p0, p1, p2, p2__typ)	GetKerningPairsW(p0, p1, p2)
__EXTERN INTEGER __CALL GetKerningPairsW(INTEGER p0, INTEGER p1, WinApi_KERNINGPAIR *p2);
#define WinApi_GetKeyNameText(lParam, lpString, nSize)	GetKeyNameTextA(lParam, lpString, nSize)
#define WinApi_GetKeyNameTextA(lParam, lpString, nSize)	GetKeyNameTextA(lParam, lpString, nSize)
__EXTERN INTEGER __CALL GetKeyNameTextA(INTEGER lParam, WinApi_PtrSTR lpString, INTEGER nSize);
#define WinApi_GetKeyNameTextW(lParam, lpString, nSize)	GetKeyNameTextW(lParam, lpString, nSize)
__EXTERN INTEGER __CALL GetKeyNameTextW(INTEGER lParam, WinApi_PtrWSTR lpString, INTEGER nSize);
#define WinApi_GetKeyState(nVirtKey)	GetKeyState(nVirtKey)
__EXTERN SHORTINT __CALL GetKeyState(INTEGER nVirtKey);
#define WinApi_GetKeyboardLayout(dwLayout)	GetKeyboardLayout(dwLayout)
__EXTERN INTEGER __CALL GetKeyboardLayout(INTEGER dwLayout);
#define WinApi_GetKeyboardLayoutList(nBuff, lpList)	GetKeyboardLayoutList(nBuff, lpList)
__EXTERN INTEGER __CALL GetKeyboardLayoutList(INTEGER nBuff, INTEGER *lpList);
#define WinApi_GetKeyboardLayoutName(pwszKLID)	GetKeyboardLayoutNameA(pwszKLID)
#define WinApi_GetKeyboardLayoutNameA(pwszKLID)	GetKeyboardLayoutNameA(pwszKLID)
__EXTERN INTEGER __CALL GetKeyboardLayoutNameA(WinApi_PtrSTR pwszKLID);
#define WinApi_GetKeyboardLayoutNameW(pwszKLID)	GetKeyboardLayoutNameW(pwszKLID)
__EXTERN INTEGER __CALL GetKeyboardLayoutNameW(WinApi_PtrWSTR pwszKLID);
#define WinApi_GetKeyboardState(lpKeyState)	GetKeyboardState(lpKeyState)
__EXTERN INTEGER __CALL GetKeyboardState(CHAR *lpKeyState);
#define WinApi_GetKeyboardType(nTypeFlag)	GetKeyboardType(nTypeFlag)
__EXTERN INTEGER __CALL GetKeyboardType(INTEGER nTypeFlag);
#define WinApi_GetLargestConsoleWindowSize(hConsoleOutput)	GetLargestConsoleWindowSize(hConsoleOutput)
__EXTERN INTEGER __CALL GetLargestConsoleWindowSize(INTEGER hConsoleOutput);
#define WinApi_GetLastActivePopup(hWnd)	GetLastActivePopup(hWnd)
__EXTERN INTEGER __CALL GetLastActivePopup(INTEGER hWnd);
#define WinApi_GetLastError()	GetLastError()
__EXTERN INTEGER __CALL GetLastError(void);
#define WinApi_GetLengthSid(pSid)	GetLengthSid(pSid)
__EXTERN INTEGER __CALL GetLengthSid(INTEGER pSid);
#define WinApi_GetLocalTime(lpSystemTime, lpSystemTime__typ)	GetLocalTime(lpSystemTime)
__EXTERN void __CALL GetLocalTime(WinApi_SYSTEMTIME *lpSystemTime);
#define WinApi_GetLocaleInfo(Locale, LCType, lpLCData, cchData)	GetLocaleInfoA(Locale, LCType, lpLCData, cchData)
#define WinApi_GetLocaleInfoA(Locale, LCType, lpLCData, cchData)	GetLocaleInfoA(Locale, LCType, lpLCData, cchData)
__EXTERN INTEGER __CALL GetLocaleInfoA(INTEGER Locale, INTEGER LCType, WinApi_PtrSTR lpLCData, INTEGER cchData);
#define WinApi_GetLocaleInfoW(Locale, LCType, lpLCData, cchData)	GetLocaleInfoW(Locale, LCType, lpLCData, cchData)
__EXTERN INTEGER __CALL GetLocaleInfoW(INTEGER Locale, INTEGER LCType, WinApi_PtrWSTR lpLCData, INTEGER cchData);
#define WinApi_GetLogColorSpace(p0, p1, p1__typ, p2)	GetLogColorSpaceA(p0, p1, p2)
#define WinApi_GetLogColorSpaceA(p0, p1, p1__typ, p2)	GetLogColorSpaceA(p0, p1, p2)
__EXTERN INTEGER __CALL GetLogColorSpaceA(INTEGER p0, WinApi_LOGCOLORSPACEA *p1, INTEGER p2);
#define WinApi_GetLogColorSpaceW(p0, p1, p1__typ, p2)	GetLogColorSpaceW(p0, p1, p2)
__EXTERN INTEGER __CALL GetLogColorSpaceW(INTEGER p0, WinApi_LOGCOLORSPACEW *p1, INTEGER p2);
#define WinApi_GetLogicalDriveStrings(nBufferLength, lpBuffer)	GetLogicalDriveStringsA(nBufferLength, lpBuffer)
#define WinApi_GetLogicalDriveStringsA(nBufferLength, lpBuffer)	GetLogicalDriveStringsA(nBufferLength, lpBuffer)
__EXTERN INTEGER __CALL GetLogicalDriveStringsA(INTEGER nBufferLength, WinApi_PtrSTR lpBuffer);
#define WinApi_GetLogicalDriveStringsW(nBufferLength, lpBuffer)	GetLogicalDriveStringsW(nBufferLength, lpBuffer)
__EXTERN INTEGER __CALL GetLogicalDriveStringsW(INTEGER nBufferLength, WinApi_PtrWSTR lpBuffer);
#define WinApi_GetLogicalDrives()	GetLogicalDrives()
__EXTERN INTEGER __CALL GetLogicalDrives(void);
#define WinApi_GetMailslotInfo(hMailslot, lpMaxMessageSize, lpNextSize, lpMessageCount, lpReadTimeout)	GetMailslotInfo(hMailslot, lpMaxMessageSize, lpNextSize, lpMessageCount, lpReadTimeout)
__EXTERN INTEGER __CALL GetMailslotInfo(INTEGER hMailslot, INTEGER *lpMaxMessageSize, INTEGER *lpNextSize, INTEGER *lpMessageCount, INTEGER *lpReadTimeout);
#define WinApi_GetMapMode(p0)	GetMapMode(p0)
__EXTERN INTEGER __CALL GetMapMode(INTEGER p0);
#define WinApi_GetMenu(hWnd)	GetMenu(hWnd)
__EXTERN INTEGER __CALL GetMenu(INTEGER hWnd);
#define WinApi_GetMenuCheckMarkDimensions()	GetMenuCheckMarkDimensions()
__EXTERN INTEGER __CALL GetMenuCheckMarkDimensions(void);
#define WinApi_GetMenuContextHelpId(p0)	GetMenuContextHelpId(p0)
__EXTERN INTEGER __CALL GetMenuContextHelpId(INTEGER p0);
#define WinApi_GetMenuDefaultItem(hMenu, fByPos, gmdiFlags)	GetMenuDefaultItem(hMenu, fByPos, gmdiFlags)
__EXTERN INTEGER __CALL GetMenuDefaultItem(INTEGER hMenu, INTEGER fByPos, SET gmdiFlags);
#define WinApi_GetMenuItemCount(hMenu)	GetMenuItemCount(hMenu)
__EXTERN INTEGER __CALL GetMenuItemCount(INTEGER hMenu);
#define WinApi_GetMenuItemID(hMenu, nPos)	GetMenuItemID(hMenu, nPos)
__EXTERN INTEGER __CALL GetMenuItemID(INTEGER hMenu, INTEGER nPos);
#define WinApi_GetMenuItemInfo(p0, p1, p2, p3, p3__typ)	GetMenuItemInfoA(p0, p1, p2, p3)
#define WinApi_GetMenuItemInfoA(p0, p1, p2, p3, p3__typ)	GetMenuItemInfoA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetMenuItemInfoA(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_MENUITEMINFOA *p3);
#define WinApi_GetMenuItemInfoW(p0, p1, p2, p3, p3__typ)	GetMenuItemInfoW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetMenuItemInfoW(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_MENUITEMINFOW *p3);
#define WinApi_GetMenuItemRect(hWnd, hMenu, uItem, lprcItem, lprcItem__typ)	GetMenuItemRect(hWnd, hMenu, uItem, lprcItem)
__EXTERN INTEGER __CALL GetMenuItemRect(INTEGER hWnd, INTEGER hMenu, INTEGER uItem, WinApi_RECT *lprcItem);
#define WinApi_GetMenuState(hMenu, uId, uFlags)	GetMenuState(hMenu, uId, uFlags)
__EXTERN INTEGER __CALL GetMenuState(INTEGER hMenu, INTEGER uId, SET uFlags);
#define WinApi_GetMenuString(hMenu, uIDItem, lpString, nMaxCount, uFlag)	GetMenuStringA(hMenu, uIDItem, lpString, nMaxCount, uFlag)
#define WinApi_GetMenuStringA(hMenu, uIDItem, lpString, nMaxCount, uFlag)	GetMenuStringA(hMenu, uIDItem, lpString, nMaxCount, uFlag)
__EXTERN INTEGER __CALL GetMenuStringA(INTEGER hMenu, INTEGER uIDItem, WinApi_PtrSTR lpString, INTEGER nMaxCount, SET uFlag);
#define WinApi_GetMenuStringW(hMenu, uIDItem, lpString, nMaxCount, uFlag)	GetMenuStringW(hMenu, uIDItem, lpString, nMaxCount, uFlag)
__EXTERN INTEGER __CALL GetMenuStringW(INTEGER hMenu, INTEGER uIDItem, WinApi_PtrWSTR lpString, INTEGER nMaxCount, SET uFlag);
#define WinApi_GetMessage(lpMsg, lpMsg__typ, hWnd, wMsgFilterMin, wMsgFilterMax)	GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)
#define WinApi_GetMessageA(lpMsg, lpMsg__typ, hWnd, wMsgFilterMin, wMsgFilterMax)	GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)
__EXTERN INTEGER __CALL GetMessageA(WinApi_MSG *lpMsg, INTEGER hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax);
#define WinApi_GetMessageExtraInfo()	GetMessageExtraInfo()
__EXTERN INTEGER __CALL GetMessageExtraInfo(void);
#define WinApi_GetMessagePos()	GetMessagePos()
__EXTERN INTEGER __CALL GetMessagePos(void);
#define WinApi_GetMessageTime()	GetMessageTime()
__EXTERN INTEGER __CALL GetMessageTime(void);
#define WinApi_GetMessageW(lpMsg, lpMsg__typ, hWnd, wMsgFilterMin, wMsgFilterMax)	GetMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)
__EXTERN INTEGER __CALL GetMessageW(WinApi_MSG *lpMsg, INTEGER hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax);
#define WinApi_GetMetaFile(p0)	GetMetaFileA(p0)
#define WinApi_GetMetaFileA(p0)	GetMetaFileA(p0)
__EXTERN INTEGER __CALL GetMetaFileA(WinApi_PtrSTR p0);
#define WinApi_GetMetaFileBitsEx(p0, p1, p2, p2__len)	GetMetaFileBitsEx(p0, p1, p2)
__EXTERN INTEGER __CALL GetMetaFileBitsEx(INTEGER p0, INTEGER p1, SYSTEM_BYTE *p2);
#define WinApi_GetMetaFileW(p0)	GetMetaFileW(p0)
__EXTERN INTEGER __CALL GetMetaFileW(WinApi_PtrWSTR p0);
#define WinApi_GetMetaRgn(p0, p1)	GetMetaRgn(p0, p1)
__EXTERN INTEGER __CALL GetMetaRgn(INTEGER p0, INTEGER p1);
#define WinApi_GetMiterLimit(p0, p1)	GetMiterLimit(p0, p1)
__EXTERN INTEGER __CALL GetMiterLimit(INTEGER p0, REAL *p1);
#define WinApi_GetModuleFileName(hModule, lpFilename, nSize)	GetModuleFileNameA(hModule, lpFilename, nSize)
#define WinApi_GetModuleFileNameA(hModule, lpFilename, nSize)	GetModuleFileNameA(hModule, lpFilename, nSize)
__EXTERN INTEGER __CALL GetModuleFileNameA(INTEGER hModule, WinApi_PtrSTR lpFilename, INTEGER nSize);
#define WinApi_GetModuleFileNameW(hModule, lpFilename, nSize)	GetModuleFileNameW(hModule, lpFilename, nSize)
__EXTERN INTEGER __CALL GetModuleFileNameW(INTEGER hModule, WinApi_PtrWSTR lpFilename, INTEGER nSize);
#define WinApi_GetModuleHandle(lpModuleName)	GetModuleHandleA(lpModuleName)
#define WinApi_GetModuleHandleA(lpModuleName)	GetModuleHandleA(lpModuleName)
__EXTERN INTEGER __CALL GetModuleHandleA(WinApi_PtrSTR lpModuleName);
#define WinApi_GetModuleHandleW(lpModuleName)	GetModuleHandleW(lpModuleName)
__EXTERN INTEGER __CALL GetModuleHandleW(WinApi_PtrWSTR lpModuleName);
#define WinApi_GetNamedPipeHandleState(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)	GetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)
#define WinApi_GetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)	GetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)
__EXTERN INTEGER __CALL GetNamedPipeHandleStateA(INTEGER hNamedPipe, INTEGER *lpState, INTEGER *lpCurInstances, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout, WinApi_PtrSTR lpUserName, INTEGER nMaxUserNameSize);
#define WinApi_GetNamedPipeHandleStateW(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)	GetNamedPipeHandleStateW(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)
__EXTERN INTEGER __CALL GetNamedPipeHandleStateW(INTEGER hNamedPipe, INTEGER *lpState, INTEGER *lpCurInstances, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout, WinApi_PtrWSTR lpUserName, INTEGER nMaxUserNameSize);
#define WinApi_GetNamedPipeInfo(hNamedPipe, lpFlags, lpOutBufferSize, lpInBufferSize, lpMaxInstances)	GetNamedPipeInfo(hNamedPipe, lpFlags, lpOutBufferSize, lpInBufferSize, lpMaxInstances)
__EXTERN INTEGER __CALL GetNamedPipeInfo(INTEGER hNamedPipe, INTEGER *lpFlags, INTEGER *lpOutBufferSize, INTEGER *lpInBufferSize, INTEGER *lpMaxInstances);
#define WinApi_GetNearestColor(p0, p1)	GetNearestColor(p0, p1)
__EXTERN INTEGER __CALL GetNearestColor(INTEGER p0, INTEGER p1);
#define WinApi_GetNearestPaletteIndex(p0, p1)	GetNearestPaletteIndex(p0, p1)
__EXTERN INTEGER __CALL GetNearestPaletteIndex(INTEGER p0, INTEGER p1);
#define WinApi_GetNextDlgGroupItem(hDlg, hCtl, bPrevious)	GetNextDlgGroupItem(hDlg, hCtl, bPrevious)
__EXTERN INTEGER __CALL GetNextDlgGroupItem(INTEGER hDlg, INTEGER hCtl, INTEGER bPrevious);
#define WinApi_GetNextDlgTabItem(hDlg, hCtl, bPrevious)	GetNextDlgTabItem(hDlg, hCtl, bPrevious)
__EXTERN INTEGER __CALL GetNextDlgTabItem(INTEGER hDlg, INTEGER hCtl, INTEGER bPrevious);
#define WinApi_GetNumberFormat(Locale, dwFlags, lpValue, lpFormat, lpFormat__typ, lpNumberStr, cchNumber)	GetNumberFormatA(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)
#define WinApi_GetNumberFormatA(Locale, dwFlags, lpValue, lpFormat, lpFormat__typ, lpNumberStr, cchNumber)	GetNumberFormatA(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)
__EXTERN INTEGER __CALL GetNumberFormatA(INTEGER Locale, SET dwFlags, WinApi_PtrSTR lpValue, WinApi_NUMBERFMTA *lpFormat, WinApi_PtrSTR lpNumberStr, INTEGER cchNumber);
#define WinApi_GetNumberFormatW(Locale, dwFlags, lpValue, lpFormat, lpFormat__typ, lpNumberStr, cchNumber)	GetNumberFormatW(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)
__EXTERN INTEGER __CALL GetNumberFormatW(INTEGER Locale, SET dwFlags, WinApi_PtrWSTR lpValue, WinApi_NUMBERFMTW *lpFormat, WinApi_PtrWSTR lpNumberStr, INTEGER cchNumber);
#define WinApi_GetNumberOfConsoleInputEvents(hConsoleInput, lpNumberOfEvents)	GetNumberOfConsoleInputEvents(hConsoleInput, lpNumberOfEvents)
__EXTERN INTEGER __CALL GetNumberOfConsoleInputEvents(INTEGER hConsoleInput, INTEGER *lpNumberOfEvents);
#define WinApi_GetNumberOfConsoleMouseButtons(lpNumberOfMouseButtons)	GetNumberOfConsoleMouseButtons(lpNumberOfMouseButtons)
__EXTERN INTEGER __CALL GetNumberOfConsoleMouseButtons(INTEGER *lpNumberOfMouseButtons);
#define WinApi_GetNumberOfEventLogRecords(hEventLog, NumberOfRecords)	GetNumberOfEventLogRecords(hEventLog, NumberOfRecords)
__EXTERN INTEGER __CALL GetNumberOfEventLogRecords(INTEGER hEventLog, INTEGER *NumberOfRecords);
#define WinApi_GetOEMCP()	GetOEMCP()
__EXTERN INTEGER __CALL GetOEMCP(void);
#define WinApi_GetObject(p0, p1, p2)	GetObjectA(p0, p1, p2)
#define WinApi_GetObjectA(p0, p1, p2)	GetObjectA(p0, p1, p2)
__EXTERN INTEGER __CALL GetObjectA(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_GetObjectType(h)	GetObjectType(h)
__EXTERN INTEGER __CALL GetObjectType(INTEGER h);
#define WinApi_GetObjectW(p0, p1, p2)	GetObjectW(p0, p1, p2)
__EXTERN INTEGER __CALL GetObjectW(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_GetOldestEventLogRecord(hEventLog, OldestRecord)	GetOldestEventLogRecord(hEventLog, OldestRecord)
__EXTERN INTEGER __CALL GetOldestEventLogRecord(INTEGER hEventLog, INTEGER *OldestRecord);
#define WinApi_GetOpenClipboardWindow()	GetOpenClipboardWindow()
__EXTERN INTEGER __CALL GetOpenClipboardWindow(void);
#define WinApi_GetOutlineTextMetrics(p0, p1, p2, p2__typ)	GetOutlineTextMetricsA(p0, p1, p2)
#define WinApi_GetOutlineTextMetricsA(p0, p1, p2, p2__typ)	GetOutlineTextMetricsA(p0, p1, p2)
__EXTERN INTEGER __CALL GetOutlineTextMetricsA(INTEGER p0, INTEGER p1, WinApi_OUTLINETEXTMETRICA *p2);
#define WinApi_GetOutlineTextMetricsW(p0, p1, p2, p2__typ)	GetOutlineTextMetricsW(p0, p1, p2)
__EXTERN INTEGER __CALL GetOutlineTextMetricsW(INTEGER p0, INTEGER p1, WinApi_OUTLINETEXTMETRICW *p2);
#define WinApi_GetOverlappedResult(hFile, lpOverlapped, lpOverlapped__typ, lpNumberOfBytesTransferred, bWait)	GetOverlappedResult(hFile, lpOverlapped, lpNumberOfBytesTransferred, bWait)
__EXTERN INTEGER __CALL GetOverlappedResult(INTEGER hFile, WinApi_OVERLAPPED *lpOverlapped, INTEGER *lpNumberOfBytesTransferred, INTEGER bWait);
#define WinApi_GetPaletteEntries(p0, p1, p2, p3, p3__typ)	GetPaletteEntries(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetPaletteEntries(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_PALETTEENTRY *p3);
#define WinApi_GetParent(hWnd)	GetParent(hWnd)
__EXTERN INTEGER __CALL GetParent(INTEGER hWnd);
#define WinApi_GetPath(p0, p1, p1__typ, p2, p3)	GetPath(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetPath(INTEGER p0, WinApi_POINT *p1, CHAR *p2, INTEGER p3);
#define WinApi_GetPixel(p0, p1, p2)	GetPixel(p0, p1, p2)
__EXTERN INTEGER __CALL GetPixel(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_GetPixelFormat(p0)	GetPixelFormat(p0)
__EXTERN INTEGER __CALL GetPixelFormat(INTEGER p0);
#define WinApi_GetPolyFillMode(p0)	GetPolyFillMode(p0)
__EXTERN INTEGER __CALL GetPolyFillMode(INTEGER p0);
#define WinApi_GetPrintProcessorDirectory(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)	GetPrintProcessorDirectoryA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)
#define WinApi_GetPrintProcessorDirectoryA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)	GetPrintProcessorDirectoryA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL GetPrintProcessorDirectoryA(WinApi_PtrSTR pName, WinApi_PtrSTR pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_GetPrintProcessorDirectoryW(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)	GetPrintProcessorDirectoryW(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL GetPrintProcessorDirectoryW(WinApi_PtrWSTR pName, WinApi_PtrWSTR pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_GetPrinter(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)	GetPrinterA(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)
#define WinApi_GetPrinterA(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)	GetPrinterA(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL GetPrinterA(INTEGER hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_GetPrinterData(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)	GetPrinterDataA(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)
#define WinApi_GetPrinterDataA(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)	GetPrinterDataA(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)
__EXTERN INTEGER __CALL GetPrinterDataA(INTEGER hPrinter, WinApi_PtrSTR pValueName, INTEGER *pType, CHAR *pData, INTEGER nSize, INTEGER *pcbNeeded);
#define WinApi_GetPrinterDataW(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)	GetPrinterDataW(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)
__EXTERN INTEGER __CALL GetPrinterDataW(INTEGER hPrinter, WinApi_PtrWSTR pValueName, INTEGER *pType, CHAR *pData, INTEGER nSize, INTEGER *pcbNeeded);
#define WinApi_GetPrinterDriver(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)	GetPrinterDriverA(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)
#define WinApi_GetPrinterDriverA(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)	GetPrinterDriverA(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL GetPrinterDriverA(INTEGER hPrinter, WinApi_PtrSTR pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_GetPrinterDriverDirectory(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)	GetPrinterDriverDirectoryA(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)
#define WinApi_GetPrinterDriverDirectoryA(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)	GetPrinterDriverDirectoryA(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL GetPrinterDriverDirectoryA(WinApi_PtrSTR pName, WinApi_PtrSTR pEnvironment, INTEGER Level, CHAR *pDriverDirectory, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_GetPrinterDriverDirectoryW(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)	GetPrinterDriverDirectoryW(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL GetPrinterDriverDirectoryW(WinApi_PtrWSTR pName, WinApi_PtrWSTR pEnvironment, INTEGER Level, CHAR *pDriverDirectory, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_GetPrinterDriverW(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)	GetPrinterDriverW(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL GetPrinterDriverW(INTEGER hPrinter, WinApi_PtrWSTR pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_GetPrinterW(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)	GetPrinterW(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL GetPrinterW(INTEGER hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinApi_GetPriorityClass(hProcess)	GetPriorityClass(hProcess)
__EXTERN INTEGER __CALL GetPriorityClass(INTEGER hProcess);
#define WinApi_GetPriorityClipboardFormat(paFormatPriorityList, cFormats)	GetPriorityClipboardFormat(paFormatPriorityList, cFormats)
__EXTERN INTEGER __CALL GetPriorityClipboardFormat(INTEGER *paFormatPriorityList, INTEGER cFormats);
#define WinApi_GetPrivateObjectSecurity(ObjectDescriptor, SecurityInformation, ResultantDescriptor, DescriptorLength, ReturnLength)	GetPrivateObjectSecurity(ObjectDescriptor, SecurityInformation, ResultantDescriptor, DescriptorLength, ReturnLength)
__EXTERN INTEGER __CALL GetPrivateObjectSecurity(INTEGER ObjectDescriptor, SET SecurityInformation, INTEGER ResultantDescriptor, INTEGER DescriptorLength, INTEGER *ReturnLength);
#define WinApi_GetPrivateProfileInt(lpAppName, lpKeyName, nDefault, lpFileName)	GetPrivateProfileIntA(lpAppName, lpKeyName, nDefault, lpFileName)
#define WinApi_GetPrivateProfileIntA(lpAppName, lpKeyName, nDefault, lpFileName)	GetPrivateProfileIntA(lpAppName, lpKeyName, nDefault, lpFileName)
__EXTERN INTEGER __CALL GetPrivateProfileIntA(WinApi_PtrSTR lpAppName, WinApi_PtrSTR lpKeyName, INTEGER nDefault, WinApi_PtrSTR lpFileName);
#define WinApi_GetPrivateProfileIntW(lpAppName, lpKeyName, nDefault, lpFileName)	GetPrivateProfileIntW(lpAppName, lpKeyName, nDefault, lpFileName)
__EXTERN INTEGER __CALL GetPrivateProfileIntW(WinApi_PtrWSTR lpAppName, WinApi_PtrWSTR lpKeyName, INTEGER nDefault, WinApi_PtrWSTR lpFileName);
#define WinApi_GetPrivateProfileSection(lpAppName, lpReturnedString, nSize, lpFileName)	GetPrivateProfileSectionA(lpAppName, lpReturnedString, nSize, lpFileName)
#define WinApi_GetPrivateProfileSectionA(lpAppName, lpReturnedString, nSize, lpFileName)	GetPrivateProfileSectionA(lpAppName, lpReturnedString, nSize, lpFileName)
__EXTERN INTEGER __CALL GetPrivateProfileSectionA(WinApi_PtrSTR lpAppName, WinApi_PtrSTR lpReturnedString, INTEGER nSize, WinApi_PtrSTR lpFileName);
#define WinApi_GetPrivateProfileSectionNames(lpszReturnBuffer, nSize, lpFileName)	GetPrivateProfileSectionNamesA(lpszReturnBuffer, nSize, lpFileName)
#define WinApi_GetPrivateProfileSectionNamesA(lpszReturnBuffer, nSize, lpFileName)	GetPrivateProfileSectionNamesA(lpszReturnBuffer, nSize, lpFileName)
__EXTERN INTEGER __CALL GetPrivateProfileSectionNamesA(WinApi_PtrSTR lpszReturnBuffer, INTEGER nSize, WinApi_PtrSTR lpFileName);
#define WinApi_GetPrivateProfileSectionNamesW(lpszReturnBuffer, nSize, lpFileName)	GetPrivateProfileSectionNamesW(lpszReturnBuffer, nSize, lpFileName)
__EXTERN INTEGER __CALL GetPrivateProfileSectionNamesW(WinApi_PtrWSTR lpszReturnBuffer, INTEGER nSize, WinApi_PtrWSTR lpFileName);
#define WinApi_GetPrivateProfileSectionW(lpAppName, lpReturnedString, nSize, lpFileName)	GetPrivateProfileSectionW(lpAppName, lpReturnedString, nSize, lpFileName)
__EXTERN INTEGER __CALL GetPrivateProfileSectionW(WinApi_PtrWSTR lpAppName, WinApi_PtrWSTR lpReturnedString, INTEGER nSize, WinApi_PtrWSTR lpFileName);
#define WinApi_GetPrivateProfileString(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)	GetPrivateProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)
#define WinApi_GetPrivateProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)	GetPrivateProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)
__EXTERN INTEGER __CALL GetPrivateProfileStringA(WinApi_PtrSTR lpAppName, WinApi_PtrSTR lpKeyName, WinApi_PtrSTR lpDefault, WinApi_PtrSTR lpReturnedString, INTEGER nSize, WinApi_PtrSTR lpFileName);
#define WinApi_GetPrivateProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)	GetPrivateProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)
__EXTERN INTEGER __CALL GetPrivateProfileStringW(WinApi_PtrWSTR lpAppName, WinApi_PtrWSTR lpKeyName, WinApi_PtrWSTR lpDefault, WinApi_PtrWSTR lpReturnedString, INTEGER nSize, WinApi_PtrWSTR lpFileName);
#define WinApi_GetPrivateProfileStruct(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	GetPrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
#define WinApi_GetPrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	GetPrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN INTEGER __CALL GetPrivateProfileStructA(WinApi_PtrSTR lpszSection, WinApi_PtrSTR lpszKey, INTEGER lpStruct, INTEGER uSizeStruct, WinApi_PtrSTR szFile);
#define WinApi_GetPrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	GetPrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN INTEGER __CALL GetPrivateProfileStructW(WinApi_PtrWSTR lpszSection, WinApi_PtrWSTR lpszKey, INTEGER lpStruct, INTEGER uSizeStruct, WinApi_PtrWSTR szFile);
#define WinApi_GetProcAddress(hModule, lpProcName)	GetProcAddress(hModule, lpProcName)
__EXTERN WinApi_FARPROC __CALL GetProcAddress(INTEGER hModule, WinApi_PtrSTR lpProcName);
#define WinApi_GetProcessAffinityMask(hProcess, lpProcessAffinityMask, lpSystemAffinityMask)	GetProcessAffinityMask(hProcess, lpProcessAffinityMask, lpSystemAffinityMask)
__EXTERN INTEGER __CALL GetProcessAffinityMask(INTEGER hProcess, INTEGER *lpProcessAffinityMask, INTEGER *lpSystemAffinityMask);
#define WinApi_GetProcessHeap()	GetProcessHeap()
__EXTERN INTEGER __CALL GetProcessHeap(void);
#define WinApi_GetProcessHeaps(NumberOfHeaps, ProcessHeaps)	GetProcessHeaps(NumberOfHeaps, ProcessHeaps)
__EXTERN INTEGER __CALL GetProcessHeaps(INTEGER NumberOfHeaps, INTEGER *ProcessHeaps);
#define WinApi_GetProcessShutdownParameters(lpdwLevel, lpdwFlags)	GetProcessShutdownParameters(lpdwLevel, lpdwFlags)
__EXTERN INTEGER __CALL GetProcessShutdownParameters(INTEGER *lpdwLevel, SET *lpdwFlags);
#define WinApi_GetProcessTimes(hProcess, lpCreationTime, lpCreationTime__typ, lpExitTime, lpExitTime__typ, lpKernelTime, lpKernelTime__typ, lpUserTime, lpUserTime__typ)	GetProcessTimes(hProcess, lpCreationTime, lpExitTime, lpKernelTime, lpUserTime)
__EXTERN INTEGER __CALL GetProcessTimes(INTEGER hProcess, WinApi_FILETIME *lpCreationTime, WinApi_FILETIME *lpExitTime, WinApi_FILETIME *lpKernelTime, WinApi_FILETIME *lpUserTime);
#define WinApi_GetProcessVersion(ProcessId)	GetProcessVersion(ProcessId)
__EXTERN INTEGER __CALL GetProcessVersion(INTEGER ProcessId);
#define WinApi_GetProcessWindowStation()	GetProcessWindowStation()
__EXTERN INTEGER __CALL GetProcessWindowStation(void);
#define WinApi_GetProcessWorkingSetSize(hProcess, lpMinimumWorkingSetSize, lpMaximumWorkingSetSize)	GetProcessWorkingSetSize(hProcess, lpMinimumWorkingSetSize, lpMaximumWorkingSetSize)
__EXTERN INTEGER __CALL GetProcessWorkingSetSize(INTEGER hProcess, INTEGER *lpMinimumWorkingSetSize, INTEGER *lpMaximumWorkingSetSize);
#define WinApi_GetProfileInt(lpAppName, lpKeyName, nDefault)	GetProfileIntA(lpAppName, lpKeyName, nDefault)
#define WinApi_GetProfileIntA(lpAppName, lpKeyName, nDefault)	GetProfileIntA(lpAppName, lpKeyName, nDefault)
__EXTERN INTEGER __CALL GetProfileIntA(WinApi_PtrSTR lpAppName, WinApi_PtrSTR lpKeyName, INTEGER nDefault);
#define WinApi_GetProfileIntW(lpAppName, lpKeyName, nDefault)	GetProfileIntW(lpAppName, lpKeyName, nDefault)
__EXTERN INTEGER __CALL GetProfileIntW(WinApi_PtrWSTR lpAppName, WinApi_PtrWSTR lpKeyName, INTEGER nDefault);
#define WinApi_GetProfileSection(lpAppName, lpReturnedString, nSize)	GetProfileSectionA(lpAppName, lpReturnedString, nSize)
#define WinApi_GetProfileSectionA(lpAppName, lpReturnedString, nSize)	GetProfileSectionA(lpAppName, lpReturnedString, nSize)
__EXTERN INTEGER __CALL GetProfileSectionA(WinApi_PtrSTR lpAppName, WinApi_PtrSTR lpReturnedString, INTEGER nSize);
#define WinApi_GetProfileSectionW(lpAppName, lpReturnedString, nSize)	GetProfileSectionW(lpAppName, lpReturnedString, nSize)
__EXTERN INTEGER __CALL GetProfileSectionW(WinApi_PtrWSTR lpAppName, WinApi_PtrWSTR lpReturnedString, INTEGER nSize);
#define WinApi_GetProfileString(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)	GetProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)
#define WinApi_GetProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)	GetProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)
__EXTERN INTEGER __CALL GetProfileStringA(WinApi_PtrSTR lpAppName, WinApi_PtrSTR lpKeyName, WinApi_PtrSTR lpDefault, WinApi_PtrSTR lpReturnedString, INTEGER nSize);
#define WinApi_GetProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)	GetProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)
__EXTERN INTEGER __CALL GetProfileStringW(WinApi_PtrWSTR lpAppName, WinApi_PtrWSTR lpKeyName, WinApi_PtrWSTR lpDefault, WinApi_PtrWSTR lpReturnedString, INTEGER nSize);
#define WinApi_GetProp(hWnd, lpString)	GetPropA(hWnd, lpString)
#define WinApi_GetPropA(hWnd, lpString)	GetPropA(hWnd, lpString)
__EXTERN INTEGER __CALL GetPropA(INTEGER hWnd, WinApi_PtrSTR lpString);
#define WinApi_GetPropW(hWnd, lpString)	GetPropW(hWnd, lpString)
__EXTERN INTEGER __CALL GetPropW(INTEGER hWnd, WinApi_PtrWSTR lpString);
#define WinApi_GetQueueStatus(flags)	GetQueueStatus(flags)
__EXTERN INTEGER __CALL GetQueueStatus(SET flags);
#define WinApi_GetQueuedCompletionStatus(CompletionPort, lpNumberOfBytesTransferred, lpCompletionKey, lpOverlapped, dwMilliseconds)	GetQueuedCompletionStatus(CompletionPort, lpNumberOfBytesTransferred, lpCompletionKey, lpOverlapped, dwMilliseconds)
__EXTERN INTEGER __CALL GetQueuedCompletionStatus(INTEGER CompletionPort, INTEGER *lpNumberOfBytesTransferred, INTEGER *lpCompletionKey, WinApi_PtrOVERLAPPED *lpOverlapped, INTEGER dwMilliseconds);
#define WinApi_GetROP2(p0)	GetROP2(p0)
__EXTERN INTEGER __CALL GetROP2(INTEGER p0);
#define WinApi_GetRasterizerCaps(p0, p0__typ, p1)	GetRasterizerCaps(p0, p1)
__EXTERN INTEGER __CALL GetRasterizerCaps(WinApi_RASTERIZER_STATUS *p0, INTEGER p1);
#define WinApi_GetRegionData(p0, p1, p2, p2__typ)	GetRegionData(p0, p1, p2)
__EXTERN INTEGER __CALL GetRegionData(INTEGER p0, INTEGER p1, WinApi_RGNDATA *p2);
#define WinApi_GetRgnBox(p0, p1, p1__typ)	GetRgnBox(p0, p1)
__EXTERN INTEGER __CALL GetRgnBox(INTEGER p0, WinApi_RECT *p1);
#define WinApi_GetScrollInfo(p0, p1, p2, p2__typ)	GetScrollInfo(p0, p1, p2)
__EXTERN INTEGER __CALL GetScrollInfo(INTEGER p0, INTEGER p1, WinApi_SCROLLINFO *p2);
#define WinApi_GetScrollPos(hWnd, nBar)	GetScrollPos(hWnd, nBar)
__EXTERN INTEGER __CALL GetScrollPos(INTEGER hWnd, INTEGER nBar);
#define WinApi_GetScrollRange(hWnd, nBar, lpMinPos, lpMaxPos)	GetScrollRange(hWnd, nBar, lpMinPos, lpMaxPos)
__EXTERN INTEGER __CALL GetScrollRange(INTEGER hWnd, INTEGER nBar, INTEGER *lpMinPos, INTEGER *lpMaxPos);
#define WinApi_GetSecurityDescriptorControl(pSecurityDescriptor, pControl, lpdwRevision)	GetSecurityDescriptorControl(pSecurityDescriptor, pControl, lpdwRevision)
__EXTERN INTEGER __CALL GetSecurityDescriptorControl(INTEGER pSecurityDescriptor, SHORTINT *pControl, INTEGER *lpdwRevision);
#define WinApi_GetSecurityDescriptorDacl(pSecurityDescriptor, lpbDaclPresent, pDacl, lpbDaclDefaulted)	GetSecurityDescriptorDacl(pSecurityDescriptor, lpbDaclPresent, pDacl, lpbDaclDefaulted)
__EXTERN INTEGER __CALL GetSecurityDescriptorDacl(INTEGER pSecurityDescriptor, INTEGER *lpbDaclPresent, WinApi_PtrACL *pDacl, INTEGER *lpbDaclDefaulted);
#define WinApi_GetSecurityDescriptorGroup(pSecurityDescriptor, pGroup, lpbGroupDefaulted)	GetSecurityDescriptorGroup(pSecurityDescriptor, pGroup, lpbGroupDefaulted)
__EXTERN INTEGER __CALL GetSecurityDescriptorGroup(INTEGER pSecurityDescriptor, INTEGER *pGroup, INTEGER *lpbGroupDefaulted);
#define WinApi_GetSecurityDescriptorLength(pSecurityDescriptor)	GetSecurityDescriptorLength(pSecurityDescriptor)
__EXTERN INTEGER __CALL GetSecurityDescriptorLength(INTEGER pSecurityDescriptor);
#define WinApi_GetSecurityDescriptorOwner(pSecurityDescriptor, pOwner, lpbOwnerDefaulted)	GetSecurityDescriptorOwner(pSecurityDescriptor, pOwner, lpbOwnerDefaulted)
__EXTERN INTEGER __CALL GetSecurityDescriptorOwner(INTEGER pSecurityDescriptor, INTEGER *pOwner, INTEGER *lpbOwnerDefaulted);
#define WinApi_GetSecurityDescriptorSacl(pSecurityDescriptor, lpbSaclPresent, pSacl, lpbSaclDefaulted)	GetSecurityDescriptorSacl(pSecurityDescriptor, lpbSaclPresent, pSacl, lpbSaclDefaulted)
__EXTERN INTEGER __CALL GetSecurityDescriptorSacl(INTEGER pSecurityDescriptor, INTEGER *lpbSaclPresent, WinApi_PtrACL *pSacl, INTEGER *lpbSaclDefaulted);
#define WinApi_GetServiceDisplayName(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)	GetServiceDisplayNameA(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)
#define WinApi_GetServiceDisplayNameA(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)	GetServiceDisplayNameA(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)
__EXTERN INTEGER __CALL GetServiceDisplayNameA(INTEGER hSCManager, WinApi_PtrSTR lpServiceName, WinApi_PtrSTR lpDisplayName, INTEGER *lpcchBuffer);
#define WinApi_GetServiceDisplayNameW(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)	GetServiceDisplayNameW(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)
__EXTERN INTEGER __CALL GetServiceDisplayNameW(INTEGER hSCManager, WinApi_PtrWSTR lpServiceName, WinApi_PtrWSTR lpDisplayName, INTEGER *lpcchBuffer);
#define WinApi_GetServiceKeyName(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)	GetServiceKeyNameA(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)
#define WinApi_GetServiceKeyNameA(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)	GetServiceKeyNameA(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)
__EXTERN INTEGER __CALL GetServiceKeyNameA(INTEGER hSCManager, WinApi_PtrSTR lpDisplayName, WinApi_PtrSTR lpServiceName, INTEGER *lpcchBuffer);
#define WinApi_GetServiceKeyNameW(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)	GetServiceKeyNameW(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)
__EXTERN INTEGER __CALL GetServiceKeyNameW(INTEGER hSCManager, WinApi_PtrWSTR lpDisplayName, WinApi_PtrWSTR lpServiceName, INTEGER *lpcchBuffer);
#define WinApi_GetShortPathName(lpszLongPath, lpszShortPath, cchBuffer)	GetShortPathNameA(lpszLongPath, lpszShortPath, cchBuffer)
#define WinApi_GetShortPathNameA(lpszLongPath, lpszShortPath, cchBuffer)	GetShortPathNameA(lpszLongPath, lpszShortPath, cchBuffer)
__EXTERN INTEGER __CALL GetShortPathNameA(WinApi_PtrSTR lpszLongPath, WinApi_PtrSTR lpszShortPath, INTEGER cchBuffer);
#define WinApi_GetShortPathNameW(lpszLongPath, lpszShortPath, cchBuffer)	GetShortPathNameW(lpszLongPath, lpszShortPath, cchBuffer)
__EXTERN INTEGER __CALL GetShortPathNameW(WinApi_PtrWSTR lpszLongPath, WinApi_PtrWSTR lpszShortPath, INTEGER cchBuffer);
#define WinApi_GetSidIdentifierAuthority(pSid)	GetSidIdentifierAuthority(pSid)
__EXTERN WinApi_PtrSID_IDENTIFIER_AUTHORITY __CALL GetSidIdentifierAuthority(INTEGER pSid);
#define WinApi_GetSidLengthRequired(nSubAuthorityCount)	GetSidLengthRequired(nSubAuthorityCount)
__EXTERN INTEGER __CALL GetSidLengthRequired(CHAR nSubAuthorityCount);
#define WinApi_GetSidSubAuthority(pSid, nSubAuthority)	GetSidSubAuthority(pSid, nSubAuthority)
__EXTERN WinApi_RetGetSidSubAuthority __CALL GetSidSubAuthority(INTEGER pSid, INTEGER nSubAuthority);
#define WinApi_GetSidSubAuthorityCount(pSid)	GetSidSubAuthorityCount(pSid)
__EXTERN WinApi_PtrSTR __CALL GetSidSubAuthorityCount(INTEGER pSid);
#define WinApi_GetStartupInfo(lpStartupInfo, lpStartupInfo__typ)	GetStartupInfoA(lpStartupInfo)
#define WinApi_GetStartupInfoA(lpStartupInfo, lpStartupInfo__typ)	GetStartupInfoA(lpStartupInfo)
__EXTERN void __CALL GetStartupInfoA(WinApi_STARTUPINFOA *lpStartupInfo);
#define WinApi_GetStartupInfoW(lpStartupInfo, lpStartupInfo__typ)	GetStartupInfoW(lpStartupInfo)
__EXTERN void __CALL GetStartupInfoW(WinApi_STARTUPINFOW *lpStartupInfo);
#define WinApi_GetStdHandle(nStdHandle)	GetStdHandle(nStdHandle)
__EXTERN INTEGER __CALL GetStdHandle(INTEGER nStdHandle);
#define WinApi_GetStockObject(p0)	GetStockObject(p0)
__EXTERN INTEGER __CALL GetStockObject(INTEGER p0);
#define WinApi_GetStretchBltMode(p0)	GetStretchBltMode(p0)
__EXTERN INTEGER __CALL GetStretchBltMode(INTEGER p0);
#define WinApi_GetStringTypeA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)
__EXTERN INTEGER __CALL GetStringTypeA(INTEGER Locale, SET dwInfoType, WinApi_PtrSTR lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
#define WinApi_GetStringTypeEx(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeExA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)
#define WinApi_GetStringTypeExA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeExA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)
__EXTERN INTEGER __CALL GetStringTypeExA(INTEGER Locale, SET dwInfoType, WinApi_PtrSTR lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
#define WinApi_GetStringTypeExW(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeExW(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)
__EXTERN INTEGER __CALL GetStringTypeExW(INTEGER Locale, SET dwInfoType, WinApi_PtrWSTR lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
#define WinApi_GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType)
__EXTERN INTEGER __CALL GetStringTypeW(SET dwInfoType, WinApi_PtrWSTR lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
#define WinApi_GetSubMenu(hMenu, nPos)	GetSubMenu(hMenu, nPos)
__EXTERN INTEGER __CALL GetSubMenu(INTEGER hMenu, INTEGER nPos);
#define WinApi_GetSysColor(nIndex)	GetSysColor(nIndex)
__EXTERN INTEGER __CALL GetSysColor(INTEGER nIndex);
#define WinApi_GetSysColorBrush(nIndex)	GetSysColorBrush(nIndex)
__EXTERN INTEGER __CALL GetSysColorBrush(INTEGER nIndex);
#define WinApi_GetSystemDefaultLCID()	GetSystemDefaultLCID()
__EXTERN INTEGER __CALL GetSystemDefaultLCID(void);
#define WinApi_GetSystemDefaultLangID()	GetSystemDefaultLangID()
__EXTERN SHORTINT __CALL GetSystemDefaultLangID(void);
#define WinApi_GetSystemDirectory(lpBuffer, uSize)	GetSystemDirectoryA(lpBuffer, uSize)
#define WinApi_GetSystemDirectoryA(lpBuffer, uSize)	GetSystemDirectoryA(lpBuffer, uSize)
__EXTERN INTEGER __CALL GetSystemDirectoryA(WinApi_PtrSTR lpBuffer, INTEGER uSize);
#define WinApi_GetSystemDirectoryW(lpBuffer, uSize)	GetSystemDirectoryW(lpBuffer, uSize)
__EXTERN INTEGER __CALL GetSystemDirectoryW(WinApi_PtrWSTR lpBuffer, INTEGER uSize);
#define WinApi_GetSystemInfo(lpSystemInfo, lpSystemInfo__typ)	GetSystemInfo(lpSystemInfo)
__EXTERN void __CALL GetSystemInfo(WinApi_SYSTEM_INFO *lpSystemInfo);
#define WinApi_GetSystemMenu(hWnd, bRevert)	GetSystemMenu(hWnd, bRevert)
__EXTERN INTEGER __CALL GetSystemMenu(INTEGER hWnd, INTEGER bRevert);
#define WinApi_GetSystemMetrics(nIndex)	GetSystemMetrics(nIndex)
__EXTERN INTEGER __CALL GetSystemMetrics(INTEGER nIndex);
#define WinApi_GetSystemPaletteEntries(p0, p1, p2, p3, p3__typ)	GetSystemPaletteEntries(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetSystemPaletteEntries(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_PALETTEENTRY *p3);
#define WinApi_GetSystemPaletteUse(p0)	GetSystemPaletteUse(p0)
__EXTERN INTEGER __CALL GetSystemPaletteUse(INTEGER p0);
#define WinApi_GetSystemPowerStatus(lpSystemPowerStatus, lpSystemPowerStatus__typ)	GetSystemPowerStatus(lpSystemPowerStatus)
__EXTERN INTEGER __CALL GetSystemPowerStatus(WinApi_SYSTEM_POWER_STATUS *lpSystemPowerStatus);
#define WinApi_GetSystemTime(lpSystemTime, lpSystemTime__typ)	GetSystemTime(lpSystemTime)
__EXTERN void __CALL GetSystemTime(WinApi_SYSTEMTIME *lpSystemTime);
#define WinApi_GetSystemTimeAdjustment(lpTimeAdjustment, lpTimeIncrement, lpTimeAdjustmentDisabled)	GetSystemTimeAdjustment(lpTimeAdjustment, lpTimeIncrement, lpTimeAdjustmentDisabled)
__EXTERN INTEGER __CALL GetSystemTimeAdjustment(INTEGER *lpTimeAdjustment, INTEGER *lpTimeIncrement, INTEGER *lpTimeAdjustmentDisabled);
#define WinApi_GetSystemTimeAsFileTime(lpSystemTimeAsFileTime, lpSystemTimeAsFileTime__typ)	GetSystemTimeAsFileTime(lpSystemTimeAsFileTime)
__EXTERN void __CALL GetSystemTimeAsFileTime(WinApi_FILETIME *lpSystemTimeAsFileTime);
#define WinApi_GetTabbedTextExtent(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)	GetTabbedTextExtentA(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)
#define WinApi_GetTabbedTextExtentA(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)	GetTabbedTextExtentA(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)
__EXTERN INTEGER __CALL GetTabbedTextExtentA(INTEGER hDC, WinApi_PtrSTR lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions);
#define WinApi_GetTabbedTextExtentW(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)	GetTabbedTextExtentW(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)
__EXTERN INTEGER __CALL GetTabbedTextExtentW(INTEGER hDC, WinApi_PtrWSTR lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions);
#define WinApi_GetTapeParameters(hDevice, dwOperation, lpdwSize, lpTapeInformation)	GetTapeParameters(hDevice, dwOperation, lpdwSize, lpTapeInformation)
__EXTERN INTEGER __CALL GetTapeParameters(INTEGER hDevice, INTEGER dwOperation, INTEGER *lpdwSize, INTEGER lpTapeInformation);
#define WinApi_GetTapePosition(hDevice, dwPositionType, lpdwPartition, lpdwOffsetLow, lpdwOffsetHigh)	GetTapePosition(hDevice, dwPositionType, lpdwPartition, lpdwOffsetLow, lpdwOffsetHigh)
__EXTERN INTEGER __CALL GetTapePosition(INTEGER hDevice, INTEGER dwPositionType, INTEGER *lpdwPartition, INTEGER *lpdwOffsetLow, INTEGER *lpdwOffsetHigh);
#define WinApi_GetTapeStatus(hDevice)	GetTapeStatus(hDevice)
__EXTERN INTEGER __CALL GetTapeStatus(INTEGER hDevice);
#define WinApi_GetTempFileName(lpPathName, lpPrefixString, uUnique, lpTempFileName)	GetTempFileNameA(lpPathName, lpPrefixString, uUnique, lpTempFileName)
#define WinApi_GetTempFileNameA(lpPathName, lpPrefixString, uUnique, lpTempFileName)	GetTempFileNameA(lpPathName, lpPrefixString, uUnique, lpTempFileName)
__EXTERN INTEGER __CALL GetTempFileNameA(WinApi_PtrSTR lpPathName, WinApi_PtrSTR lpPrefixString, INTEGER uUnique, WinApi_PtrSTR lpTempFileName);
#define WinApi_GetTempFileNameW(lpPathName, lpPrefixString, uUnique, lpTempFileName)	GetTempFileNameW(lpPathName, lpPrefixString, uUnique, lpTempFileName)
__EXTERN INTEGER __CALL GetTempFileNameW(WinApi_PtrWSTR lpPathName, WinApi_PtrWSTR lpPrefixString, INTEGER uUnique, WinApi_PtrWSTR lpTempFileName);
#define WinApi_GetTempPath(nBufferLength, lpBuffer)	GetTempPathA(nBufferLength, lpBuffer)
#define WinApi_GetTempPathA(nBufferLength, lpBuffer)	GetTempPathA(nBufferLength, lpBuffer)
__EXTERN INTEGER __CALL GetTempPathA(INTEGER nBufferLength, WinApi_PtrSTR lpBuffer);
#define WinApi_GetTempPathW(nBufferLength, lpBuffer)	GetTempPathW(nBufferLength, lpBuffer)
__EXTERN INTEGER __CALL GetTempPathW(INTEGER nBufferLength, WinApi_PtrWSTR lpBuffer);
#define WinApi_GetTextAlign(p0)	GetTextAlign(p0)
__EXTERN SET __CALL GetTextAlign(INTEGER p0);
#define WinApi_GetTextCharacterExtra(p0)	GetTextCharacterExtra(p0)
__EXTERN INTEGER __CALL GetTextCharacterExtra(INTEGER p0);
#define WinApi_GetTextCharset(hdc)	GetTextCharset(hdc)
__EXTERN INTEGER __CALL GetTextCharset(INTEGER hdc);
#define WinApi_GetTextCharsetInfo(hdc, lpSig, lpSig__typ, dwFlags)	GetTextCharsetInfo(hdc, lpSig, dwFlags)
__EXTERN INTEGER __CALL GetTextCharsetInfo(INTEGER hdc, WinApi_FONTSIGNATURE *lpSig, SET dwFlags);
#define WinApi_GetTextColor(p0)	GetTextColor(p0)
__EXTERN INTEGER __CALL GetTextColor(INTEGER p0);
#define WinApi_GetTextExtentExPoint(p0, p1, p2, p3, p4, p5, p6, p6__typ)	GetTextExtentExPointA(p0, p1, p2, p3, p4, p5, p6)
#define WinApi_GetTextExtentExPointA(p0, p1, p2, p3, p4, p5, p6, p6__typ)	GetTextExtentExPointA(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL GetTextExtentExPointA(INTEGER p0, WinApi_PtrSTR p1, INTEGER p2, INTEGER p3, INTEGER *p4, INTEGER *p5, WinApi_SIZE *p6);
#define WinApi_GetTextExtentExPointW(p0, p1, p2, p3, p4, p5, p6, p6__typ)	GetTextExtentExPointW(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL GetTextExtentExPointW(INTEGER p0, WinApi_PtrWSTR p1, INTEGER p2, INTEGER p3, INTEGER *p4, INTEGER *p5, WinApi_SIZE *p6);
#define WinApi_GetTextExtentPoint(p0, p1, p2, p3, p3__typ)	GetTextExtentPointA(p0, p1, p2, p3)
#define WinApi_GetTextExtentPoint32(p0, p1, p2, p3, p3__typ)	GetTextExtentPoint32A(p0, p1, p2, p3)
#define WinApi_GetTextExtentPoint32A(p0, p1, p2, p3, p3__typ)	GetTextExtentPoint32A(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetTextExtentPoint32A(INTEGER p0, WinApi_PtrSTR p1, INTEGER p2, WinApi_SIZE *p3);
#define WinApi_GetTextExtentPoint32W(p0, p1, p2, p3, p3__typ)	GetTextExtentPoint32W(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetTextExtentPoint32W(INTEGER p0, WinApi_PtrWSTR p1, INTEGER p2, WinApi_SIZE *p3);
#define WinApi_GetTextExtentPointA(p0, p1, p2, p3, p3__typ)	GetTextExtentPointA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetTextExtentPointA(INTEGER p0, WinApi_PtrSTR p1, INTEGER p2, WinApi_SIZE *p3);
#define WinApi_GetTextExtentPointW(p0, p1, p2, p3, p3__typ)	GetTextExtentPointW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL GetTextExtentPointW(INTEGER p0, WinApi_PtrWSTR p1, INTEGER p2, WinApi_SIZE *p3);
#define WinApi_GetTextFace(p0, p1, p2)	GetTextFaceA(p0, p1, p2)
#define WinApi_GetTextFaceA(p0, p1, p2)	GetTextFaceA(p0, p1, p2)
__EXTERN INTEGER __CALL GetTextFaceA(INTEGER p0, INTEGER p1, WinApi_PtrSTR p2);
#define WinApi_GetTextFaceW(p0, p1, p2)	GetTextFaceW(p0, p1, p2)
__EXTERN INTEGER __CALL GetTextFaceW(INTEGER p0, INTEGER p1, WinApi_PtrWSTR p2);
#define WinApi_GetTextMetrics(p0, p1, p1__typ)	GetTextMetricsA(p0, p1)
#define WinApi_GetTextMetricsA(p0, p1, p1__typ)	GetTextMetricsA(p0, p1)
__EXTERN INTEGER __CALL GetTextMetricsA(INTEGER p0, WinApi_TEXTMETRICA *p1);
#define WinApi_GetTextMetricsW(p0, p1, p1__typ)	GetTextMetricsW(p0, p1)
__EXTERN INTEGER __CALL GetTextMetricsW(INTEGER p0, WinApi_TEXTMETRICW *p1);
#define WinApi_GetThreadContext(hThread, lpContext, lpContext__typ)	GetThreadContext(hThread, lpContext)
__EXTERN INTEGER __CALL GetThreadContext(INTEGER hThread, WinApi_CONTEXT *lpContext);
#define WinApi_GetThreadDesktop(dwThreadId)	GetThreadDesktop(dwThreadId)
__EXTERN INTEGER __CALL GetThreadDesktop(INTEGER dwThreadId);
#define WinApi_GetThreadLocale()	GetThreadLocale()
__EXTERN INTEGER __CALL GetThreadLocale(void);
#define WinApi_GetThreadPriority(hThread)	GetThreadPriority(hThread)
__EXTERN INTEGER __CALL GetThreadPriority(INTEGER hThread);
#define WinApi_GetThreadPriorityBoost(hThread, pDisablePriorityBoost)	GetThreadPriorityBoost(hThread, pDisablePriorityBoost)
__EXTERN INTEGER __CALL GetThreadPriorityBoost(INTEGER hThread, INTEGER *pDisablePriorityBoost);
#define WinApi_GetThreadSelectorEntry(hThread, dwSelector, lpSelectorEntry, lpSelectorEntry__typ)	GetThreadSelectorEntry(hThread, dwSelector, lpSelectorEntry)
__EXTERN INTEGER __CALL GetThreadSelectorEntry(INTEGER hThread, INTEGER dwSelector, WinApi_LDT_ENTRY *lpSelectorEntry);
#define WinApi_GetThreadTimes(hThread, lpCreationTime, lpCreationTime__typ, lpExitTime, lpExitTime__typ, lpKernelTime, lpKernelTime__typ, lpUserTime, lpUserTime__typ)	GetThreadTimes(hThread, lpCreationTime, lpExitTime, lpKernelTime, lpUserTime)
__EXTERN INTEGER __CALL GetThreadTimes(INTEGER hThread, WinApi_FILETIME *lpCreationTime, WinApi_FILETIME *lpExitTime, WinApi_FILETIME *lpKernelTime, WinApi_FILETIME *lpUserTime);
#define WinApi_GetTickCount()	GetTickCount()
__EXTERN INTEGER __CALL GetTickCount(void);
#define WinApi_GetTimeFormat(Locale, dwFlags, lpTime, lpTime__typ, lpFormat, lpTimeStr, cchTime)	GetTimeFormatA(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)
#define WinApi_GetTimeFormatA(Locale, dwFlags, lpTime, lpTime__typ, lpFormat, lpTimeStr, cchTime)	GetTimeFormatA(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)
__EXTERN INTEGER __CALL GetTimeFormatA(INTEGER Locale, SET dwFlags, WinApi_SYSTEMTIME *lpTime, WinApi_PtrSTR lpFormat, WinApi_PtrSTR lpTimeStr, INTEGER cchTime);
#define WinApi_GetTimeFormatW(Locale, dwFlags, lpTime, lpTime__typ, lpFormat, lpTimeStr, cchTime)	GetTimeFormatW(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)
__EXTERN INTEGER __CALL GetTimeFormatW(INTEGER Locale, SET dwFlags, WinApi_SYSTEMTIME *lpTime, WinApi_PtrWSTR lpFormat, WinApi_PtrWSTR lpTimeStr, INTEGER cchTime);
#define WinApi_GetTimeZoneInformation(lpTimeZoneInformation, lpTimeZoneInformation__typ)	GetTimeZoneInformation(lpTimeZoneInformation)
__EXTERN INTEGER __CALL GetTimeZoneInformation(WinApi_TIME_ZONE_INFORMATION *lpTimeZoneInformation);
#define WinApi_GetTokenInformation(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength, ReturnLength)	GetTokenInformation(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength, ReturnLength)
__EXTERN INTEGER __CALL GetTokenInformation(INTEGER TokenHandle, INTEGER TokenInformationClass, INTEGER TokenInformation, INTEGER TokenInformationLength, INTEGER *ReturnLength);
#define WinApi_GetTopWindow(hWnd)	GetTopWindow(hWnd)
__EXTERN INTEGER __CALL GetTopWindow(INTEGER hWnd);
#define WinApi_GetUpdateRect(hWnd, lpRect, lpRect__typ, bErase)	GetUpdateRect(hWnd, lpRect, bErase)
__EXTERN INTEGER __CALL GetUpdateRect(INTEGER hWnd, WinApi_RECT *lpRect, INTEGER bErase);
#define WinApi_GetUpdateRgn(hWnd, hRgn, bErase)	GetUpdateRgn(hWnd, hRgn, bErase)
__EXTERN INTEGER __CALL GetUpdateRgn(INTEGER hWnd, INTEGER hRgn, INTEGER bErase);
#define WinApi_GetUserDefaultLCID()	GetUserDefaultLCID()
__EXTERN INTEGER __CALL GetUserDefaultLCID(void);
#define WinApi_GetUserDefaultLangID()	GetUserDefaultLangID()
__EXTERN SHORTINT __CALL GetUserDefaultLangID(void);
#define WinApi_GetUserName(lpBuffer, nSize)	GetUserNameA(lpBuffer, nSize)
#define WinApi_GetUserNameA(lpBuffer, nSize)	GetUserNameA(lpBuffer, nSize)
__EXTERN INTEGER __CALL GetUserNameA(WinApi_PtrSTR lpBuffer, INTEGER *nSize);
#define WinApi_GetUserNameW(lpBuffer, nSize)	GetUserNameW(lpBuffer, nSize)
__EXTERN INTEGER __CALL GetUserNameW(WinApi_PtrWSTR lpBuffer, INTEGER *nSize);
#define WinApi_GetUserObjectInformation(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)	GetUserObjectInformationA(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)
#define WinApi_GetUserObjectInformationA(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)	GetUserObjectInformationA(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)
__EXTERN INTEGER __CALL GetUserObjectInformationA(INTEGER hObj, INTEGER nIndex, INTEGER pvInfo, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinApi_GetUserObjectInformationW(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)	GetUserObjectInformationW(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)
__EXTERN INTEGER __CALL GetUserObjectInformationW(INTEGER hObj, INTEGER nIndex, INTEGER pvInfo, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinApi_GetUserObjectSecurity(hObj, pSIRequested, pSID, nLength, lpnLengthNeeded)	GetUserObjectSecurity(hObj, pSIRequested, pSID, nLength, lpnLengthNeeded)
__EXTERN INTEGER __CALL GetUserObjectSecurity(INTEGER hObj, INTEGER *pSIRequested, INTEGER pSID, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinApi_GetVersion()	GetVersion()
__EXTERN INTEGER __CALL GetVersion(void);
#define WinApi_GetVersionEx(lpVersionInformation, lpVersionInformation__typ)	GetVersionExA(lpVersionInformation)
#define WinApi_GetVersionExA(lpVersionInformation, lpVersionInformation__typ)	GetVersionExA(lpVersionInformation)
__EXTERN INTEGER __CALL GetVersionExA(WinApi_OSVERSIONINFOA *lpVersionInformation);
#define WinApi_GetVersionExW(lpVersionInformation, lpVersionInformation__typ)	GetVersionExW(lpVersionInformation)
__EXTERN INTEGER __CALL GetVersionExW(WinApi_OSVERSIONINFOW *lpVersionInformation);
#define WinApi_GetViewportExtEx(p0, p1, p1__typ)	GetViewportExtEx(p0, p1)
__EXTERN INTEGER __CALL GetViewportExtEx(INTEGER p0, WinApi_SIZE *p1);
#define WinApi_GetViewportOrgEx(p0, p1, p1__typ)	GetViewportOrgEx(p0, p1)
__EXTERN INTEGER __CALL GetViewportOrgEx(INTEGER p0, WinApi_POINT *p1);
#define WinApi_GetVolumeInformation(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)	GetVolumeInformationA(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)
#define WinApi_GetVolumeInformationA(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)	GetVolumeInformationA(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)
__EXTERN INTEGER __CALL GetVolumeInformationA(WinApi_PtrSTR lpRootPathName, WinApi_PtrSTR lpVolumeNameBuffer, INTEGER nVolumeNameSize, INTEGER *lpVolumeSerialNumber, INTEGER *lpMaximumComponentLength, SET *lpFileSystemFlags, WinApi_PtrSTR lpFileSystemNameBuffer, INTEGER nFileSystemNameSize);
#define WinApi_GetVolumeInformationW(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)	GetVolumeInformationW(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)
__EXTERN INTEGER __CALL GetVolumeInformationW(WinApi_PtrWSTR lpRootPathName, WinApi_PtrWSTR lpVolumeNameBuffer, INTEGER nVolumeNameSize, INTEGER *lpVolumeSerialNumber, INTEGER *lpMaximumComponentLength, SET *lpFileSystemFlags, WinApi_PtrWSTR lpFileSystemNameBuffer, INTEGER nFileSystemNameSize);
#define WinApi_GetWinMetaFileBits(p0, p1, p2, p3, p4)	GetWinMetaFileBits(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL GetWinMetaFileBits(INTEGER p0, INTEGER p1, CHAR *p2, INTEGER p3, INTEGER p4);
#define WinApi_GetWindow(hWnd, uCmd)	GetWindow(hWnd, uCmd)
__EXTERN INTEGER __CALL GetWindow(INTEGER hWnd, INTEGER uCmd);
#define WinApi_GetWindowContextHelpId(p0)	GetWindowContextHelpId(p0)
__EXTERN INTEGER __CALL GetWindowContextHelpId(INTEGER p0);
#define WinApi_GetWindowDC(hWnd)	GetWindowDC(hWnd)
__EXTERN INTEGER __CALL GetWindowDC(INTEGER hWnd);
#define WinApi_GetWindowExtEx(p0, p1, p1__typ)	GetWindowExtEx(p0, p1)
__EXTERN INTEGER __CALL GetWindowExtEx(INTEGER p0, WinApi_SIZE *p1);
#define WinApi_GetWindowLong(hWnd, nIndex)	GetWindowLongA(hWnd, nIndex)
#define WinApi_GetWindowLongA(hWnd, nIndex)	GetWindowLongA(hWnd, nIndex)
__EXTERN INTEGER __CALL GetWindowLongA(INTEGER hWnd, INTEGER nIndex);
#define WinApi_GetWindowLongW(hWnd, nIndex)	GetWindowLongW(hWnd, nIndex)
__EXTERN INTEGER __CALL GetWindowLongW(INTEGER hWnd, INTEGER nIndex);
#define WinApi_GetWindowOrgEx(p0, p1, p1__typ)	GetWindowOrgEx(p0, p1)
__EXTERN INTEGER __CALL GetWindowOrgEx(INTEGER p0, WinApi_POINT *p1);
#define WinApi_GetWindowPlacement(hWnd, lpwndpl, lpwndpl__typ)	GetWindowPlacement(hWnd, lpwndpl)
__EXTERN INTEGER __CALL GetWindowPlacement(INTEGER hWnd, WinApi_WINDOWPLACEMENT *lpwndpl);
#define WinApi_GetWindowRect(hWnd, lpRect, lpRect__typ)	GetWindowRect(hWnd, lpRect)
__EXTERN INTEGER __CALL GetWindowRect(INTEGER hWnd, WinApi_RECT *lpRect);
#define WinApi_GetWindowRgn(hWnd, hRgn)	GetWindowRgn(hWnd, hRgn)
__EXTERN INTEGER __CALL GetWindowRgn(INTEGER hWnd, INTEGER hRgn);
#define WinApi_GetWindowText(hWnd, lpString, nMaxCount)	GetWindowTextA(hWnd, lpString, nMaxCount)
#define WinApi_GetWindowTextA(hWnd, lpString, nMaxCount)	GetWindowTextA(hWnd, lpString, nMaxCount)
__EXTERN INTEGER __CALL GetWindowTextA(INTEGER hWnd, WinApi_PtrSTR lpString, INTEGER nMaxCount);
#define WinApi_GetWindowTextLength(hWnd)	GetWindowTextLengthA(hWnd)
#define WinApi_GetWindowTextLengthA(hWnd)	GetWindowTextLengthA(hWnd)
__EXTERN INTEGER __CALL GetWindowTextLengthA(INTEGER hWnd);
#define WinApi_GetWindowTextLengthW(hWnd)	GetWindowTextLengthW(hWnd)
__EXTERN INTEGER __CALL GetWindowTextLengthW(INTEGER hWnd);
#define WinApi_GetWindowTextW(hWnd, lpString, nMaxCount)	GetWindowTextW(hWnd, lpString, nMaxCount)
__EXTERN INTEGER __CALL GetWindowTextW(INTEGER hWnd, WinApi_PtrWSTR lpString, INTEGER nMaxCount);
#define WinApi_GetWindowThreadProcessId(hWnd, lpdwProcessId)	GetWindowThreadProcessId(hWnd, lpdwProcessId)
__EXTERN INTEGER __CALL GetWindowThreadProcessId(INTEGER hWnd, INTEGER *lpdwProcessId);
#define WinApi_GetWindowWord(hWnd, nIndex)	GetWindowWord(hWnd, nIndex)
__EXTERN SHORTINT __CALL GetWindowWord(INTEGER hWnd, INTEGER nIndex);
#define WinApi_GetWindowsDirectory(lpBuffer, uSize)	GetWindowsDirectoryA(lpBuffer, uSize)
#define WinApi_GetWindowsDirectoryA(lpBuffer, uSize)	GetWindowsDirectoryA(lpBuffer, uSize)
__EXTERN INTEGER __CALL GetWindowsDirectoryA(WinApi_PtrSTR lpBuffer, INTEGER uSize);
#define WinApi_GetWindowsDirectoryW(lpBuffer, uSize)	GetWindowsDirectoryW(lpBuffer, uSize)
__EXTERN INTEGER __CALL GetWindowsDirectoryW(WinApi_PtrWSTR lpBuffer, INTEGER uSize);
#define WinApi_GetWorldTransform(p0, p1, p1__typ)	GetWorldTransform(p0, p1)
__EXTERN INTEGER __CALL GetWorldTransform(INTEGER p0, WinApi_XFORM *p1);
#define WinApi_GlobalAddAtom(lpString)	GlobalAddAtomA(lpString)
#define WinApi_GlobalAddAtomA(lpString)	GlobalAddAtomA(lpString)
__EXTERN SHORTINT __CALL GlobalAddAtomA(WinApi_PtrSTR lpString);
#define WinApi_GlobalAddAtomW(lpString)	GlobalAddAtomW(lpString)
__EXTERN SHORTINT __CALL GlobalAddAtomW(WinApi_PtrWSTR lpString);
#define WinApi_GlobalAlloc(uFlags, dwBytes)	GlobalAlloc(uFlags, dwBytes)
__EXTERN INTEGER __CALL GlobalAlloc(SET uFlags, INTEGER dwBytes);
#define WinApi_GlobalCompact(dwMinFree)	GlobalCompact(dwMinFree)
__EXTERN INTEGER __CALL GlobalCompact(INTEGER dwMinFree);
#define WinApi_GlobalDeleteAtom(nAtom)	GlobalDeleteAtom(nAtom)
__EXTERN SHORTINT __CALL GlobalDeleteAtom(SHORTINT nAtom);
#define WinApi_GlobalFindAtom(lpString)	GlobalFindAtomA(lpString)
#define WinApi_GlobalFindAtomA(lpString)	GlobalFindAtomA(lpString)
__EXTERN SHORTINT __CALL GlobalFindAtomA(WinApi_PtrSTR lpString);
#define WinApi_GlobalFindAtomW(lpString)	GlobalFindAtomW(lpString)
__EXTERN SHORTINT __CALL GlobalFindAtomW(WinApi_PtrWSTR lpString);
#define WinApi_GlobalFix(hMem)	GlobalFix(hMem)
__EXTERN void __CALL GlobalFix(INTEGER hMem);
#define WinApi_GlobalFlags(hMem)	GlobalFlags(hMem)
__EXTERN INTEGER __CALL GlobalFlags(INTEGER hMem);
#define WinApi_GlobalFree(hMem)	GlobalFree(hMem)
__EXTERN INTEGER __CALL GlobalFree(INTEGER hMem);
#define WinApi_GlobalGetAtomName(nAtom, lpBuffer, nSize)	GlobalGetAtomNameA(nAtom, lpBuffer, nSize)
#define WinApi_GlobalGetAtomNameA(nAtom, lpBuffer, nSize)	GlobalGetAtomNameA(nAtom, lpBuffer, nSize)
__EXTERN INTEGER __CALL GlobalGetAtomNameA(SHORTINT nAtom, WinApi_PtrSTR lpBuffer, INTEGER nSize);
#define WinApi_GlobalGetAtomNameW(nAtom, lpBuffer, nSize)	GlobalGetAtomNameW(nAtom, lpBuffer, nSize)
__EXTERN INTEGER __CALL GlobalGetAtomNameW(SHORTINT nAtom, WinApi_PtrWSTR lpBuffer, INTEGER nSize);
#define WinApi_GlobalHandle(pMem)	GlobalHandle(pMem)
__EXTERN INTEGER __CALL GlobalHandle(INTEGER pMem);
#define WinApi_GlobalLock(hMem)	GlobalLock(hMem)
__EXTERN INTEGER __CALL GlobalLock(INTEGER hMem);
#define WinApi_GlobalMemoryStatus(lpBuffer, lpBuffer__typ)	GlobalMemoryStatus(lpBuffer)
__EXTERN void __CALL GlobalMemoryStatus(WinApi_MEMORYSTATUS *lpBuffer);
#define WinApi_GlobalReAlloc(hMem, dwBytes, uFlags)	GlobalReAlloc(hMem, dwBytes, uFlags)
__EXTERN INTEGER __CALL GlobalReAlloc(INTEGER hMem, INTEGER dwBytes, SET uFlags);
#define WinApi_GlobalSize(hMem)	GlobalSize(hMem)
__EXTERN INTEGER __CALL GlobalSize(INTEGER hMem);
#define WinApi_GlobalUnWire(hMem)	GlobalUnWire(hMem)
__EXTERN INTEGER __CALL GlobalUnWire(INTEGER hMem);
#define WinApi_GlobalUnfix(hMem)	GlobalUnfix(hMem)
__EXTERN void __CALL GlobalUnfix(INTEGER hMem);
#define WinApi_GlobalUnlock(hMem)	GlobalUnlock(hMem)
__EXTERN INTEGER __CALL GlobalUnlock(INTEGER hMem);
#define WinApi_GlobalWire(hMem)	GlobalWire(hMem)
__EXTERN INTEGER __CALL GlobalWire(INTEGER hMem);
#define WinApi_GrayString(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)	GrayStringA(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)
#define WinApi_GrayStringA(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)	GrayStringA(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)
__EXTERN INTEGER __CALL GrayStringA(INTEGER hDC, INTEGER hBrush, WinApi_GRAYSTRINGPROC lpOutputFunc, INTEGER lpData, INTEGER nCount, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight);
#define WinApi_GrayStringW(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)	GrayStringW(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)
__EXTERN INTEGER __CALL GrayStringW(INTEGER hDC, INTEGER hBrush, WinApi_GRAYSTRINGPROC lpOutputFunc, INTEGER lpData, INTEGER nCount, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight);
#define WinApi_HeapAlloc(hHeap, dwFlags, dwBytes)	HeapAlloc(hHeap, dwFlags, dwBytes)
__EXTERN INTEGER __CALL HeapAlloc(INTEGER hHeap, SET dwFlags, INTEGER dwBytes);
#define WinApi_HeapCompact(hHeap, dwFlags)	HeapCompact(hHeap, dwFlags)
__EXTERN INTEGER __CALL HeapCompact(INTEGER hHeap, SET dwFlags);
#define WinApi_HeapCreate(flOptions, dwInitialSize, dwMaximumSize)	HeapCreate(flOptions, dwInitialSize, dwMaximumSize)
__EXTERN INTEGER __CALL HeapCreate(SET flOptions, INTEGER dwInitialSize, INTEGER dwMaximumSize);
#define WinApi_HeapDestroy(hHeap)	HeapDestroy(hHeap)
__EXTERN INTEGER __CALL HeapDestroy(INTEGER hHeap);
#define WinApi_HeapFree(hHeap, dwFlags, lpMem)	HeapFree(hHeap, dwFlags, lpMem)
__EXTERN INTEGER __CALL HeapFree(INTEGER hHeap, SET dwFlags, INTEGER lpMem);
#define WinApi_HeapLock(hHeap)	HeapLock(hHeap)
__EXTERN INTEGER __CALL HeapLock(INTEGER hHeap);
#define WinApi_HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes)	HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes)
__EXTERN INTEGER __CALL HeapReAlloc(INTEGER hHeap, SET dwFlags, INTEGER lpMem, INTEGER dwBytes);
#define WinApi_HeapSize(hHeap, dwFlags, lpMem)	HeapSize(hHeap, dwFlags, lpMem)
__EXTERN INTEGER __CALL HeapSize(INTEGER hHeap, SET dwFlags, INTEGER lpMem);
#define WinApi_HeapUnlock(hHeap)	HeapUnlock(hHeap)
__EXTERN INTEGER __CALL HeapUnlock(INTEGER hHeap);
#define WinApi_HeapValidate(hHeap, dwFlags, lpMem)	HeapValidate(hHeap, dwFlags, lpMem)
__EXTERN INTEGER __CALL HeapValidate(INTEGER hHeap, SET dwFlags, INTEGER lpMem);
#define WinApi_HeapWalk(hHeap, lpEntry, lpEntry__typ)	HeapWalk(hHeap, lpEntry)
__EXTERN INTEGER __CALL HeapWalk(INTEGER hHeap, WinApi_PROCESS_HEAP_ENTRY *lpEntry);
#define WinApi_HideCaret(hWnd)	HideCaret(hWnd)
__EXTERN INTEGER __CALL HideCaret(INTEGER hWnd);
#define WinApi_HiliteMenuItem(hWnd, hMenu, uIDHiliteItem, uHilite)	HiliteMenuItem(hWnd, hMenu, uIDHiliteItem, uHilite)
__EXTERN INTEGER __CALL HiliteMenuItem(INTEGER hWnd, INTEGER hMenu, INTEGER uIDHiliteItem, INTEGER uHilite);
#define WinApi_ImpersonateDdeClientWindow(hWndClient, hWndServer)	ImpersonateDdeClientWindow(hWndClient, hWndServer)
__EXTERN INTEGER __CALL ImpersonateDdeClientWindow(INTEGER hWndClient, INTEGER hWndServer);
#define WinApi_ImpersonateLoggedOnUser(hToken)	ImpersonateLoggedOnUser(hToken)
__EXTERN INTEGER __CALL ImpersonateLoggedOnUser(INTEGER hToken);
#define WinApi_ImpersonateNamedPipeClient(hNamedPipe)	ImpersonateNamedPipeClient(hNamedPipe)
__EXTERN INTEGER __CALL ImpersonateNamedPipeClient(INTEGER hNamedPipe);
#define WinApi_ImpersonateSelf(ImpersonationLevel)	ImpersonateSelf(ImpersonationLevel)
__EXTERN INTEGER __CALL ImpersonateSelf(INTEGER ImpersonationLevel);
#define WinApi_InSendMessage()	InSendMessage()
__EXTERN INTEGER __CALL InSendMessage(void);
#define WinApi_InflateRect(lprc, lprc__typ, dx, dy)	InflateRect(lprc, dx, dy)
__EXTERN INTEGER __CALL InflateRect(WinApi_RECT *lprc, INTEGER dx, INTEGER dy);
#define WinApi_InitAtomTable(nSize)	InitAtomTable(nSize)
__EXTERN INTEGER __CALL InitAtomTable(INTEGER nSize);
#define WinApi_InitializeAcl(pAcl, pAcl__typ, nAclLength, dwAclRevision)	InitializeAcl(pAcl, nAclLength, dwAclRevision)
__EXTERN INTEGER __CALL InitializeAcl(WinApi_ACL *pAcl, INTEGER nAclLength, INTEGER dwAclRevision);
#define WinApi_InitializeCriticalSection(lpCriticalSection, lpCriticalSection__typ)	InitializeCriticalSection(lpCriticalSection)
__EXTERN void __CALL InitializeCriticalSection(WinApi_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinApi_InitializeSecurityDescriptor(pSecurityDescriptor, dwRevision)	InitializeSecurityDescriptor(pSecurityDescriptor, dwRevision)
__EXTERN INTEGER __CALL InitializeSecurityDescriptor(INTEGER pSecurityDescriptor, INTEGER dwRevision);
#define WinApi_InitializeSid(Sid, pIdentifierAuthority, pIdentifierAuthority__typ, nSubAuthorityCount)	InitializeSid(Sid, pIdentifierAuthority, nSubAuthorityCount)
__EXTERN INTEGER __CALL InitializeSid(INTEGER Sid, WinApi_SID_IDENTIFIER_AUTHORITY *pIdentifierAuthority, CHAR nSubAuthorityCount);
#define WinApi_InitiateSystemShutdown(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)	InitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)
#define WinApi_InitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)	InitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)
__EXTERN INTEGER __CALL InitiateSystemShutdownA(WinApi_PtrSTR lpMachineName, WinApi_PtrSTR lpMessage, INTEGER dwTimeout, INTEGER bForceAppsClosed, INTEGER bRebootAfterShutdown);
#define WinApi_InitiateSystemShutdownW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)	InitiateSystemShutdownW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)
__EXTERN INTEGER __CALL InitiateSystemShutdownW(WinApi_PtrWSTR lpMachineName, WinApi_PtrWSTR lpMessage, INTEGER dwTimeout, INTEGER bForceAppsClosed, INTEGER bRebootAfterShutdown);
#define WinApi_InsertMenu(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)	InsertMenuA(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)
#define WinApi_InsertMenuA(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)	InsertMenuA(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __CALL InsertMenuA(INTEGER hMenu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, WinApi_PtrSTR lpNewItem);
#define WinApi_InsertMenuItem(p0, p1, p2, p3, p3__typ)	InsertMenuItemA(p0, p1, p2, p3)
#define WinApi_InsertMenuItemA(p0, p1, p2, p3, p3__typ)	InsertMenuItemA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL InsertMenuItemA(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_MENUITEMINFOA *p3);
#define WinApi_InsertMenuItemW(p0, p1, p2, p3, p3__typ)	InsertMenuItemW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL InsertMenuItemW(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_MENUITEMINFOW *p3);
#define WinApi_InsertMenuW(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)	InsertMenuW(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __CALL InsertMenuW(INTEGER hMenu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, WinApi_PtrWSTR lpNewItem);
#define WinApi_InterlockedCompareExchange(Destination, Exchange, Comperand)	InterlockedCompareExchange(Destination, Exchange, Comperand)
__EXTERN INTEGER __CALL InterlockedCompareExchange(struct {
	LONGINT len[1];
	INTEGER data[1];
} *Destination, INTEGER Exchange, INTEGER Comperand);
#define WinApi_InterlockedDecrement(lpAddend)	InterlockedDecrement(lpAddend)
__EXTERN INTEGER __CALL InterlockedDecrement(INTEGER *lpAddend);
#define WinApi_InterlockedExchange(Target, Value)	InterlockedExchange(Target, Value)
__EXTERN INTEGER __CALL InterlockedExchange(INTEGER *Target, INTEGER Value);
#define WinApi_InterlockedExchangeAdd(Addend, Value)	InterlockedExchangeAdd(Addend, Value)
__EXTERN INTEGER __CALL InterlockedExchangeAdd(INTEGER *Addend, INTEGER Value);
#define WinApi_InterlockedIncrement(lpAddend)	InterlockedIncrement(lpAddend)
__EXTERN INTEGER __CALL InterlockedIncrement(INTEGER *lpAddend);
#define WinApi_IntersectClipRect(p0, p1, p2, p3, p4)	IntersectClipRect(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL IntersectClipRect(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_IntersectRect(lprcDst, lprcDst__typ, lprcSrc1, lprcSrc1__typ, lprcSrc2, lprcSrc2__typ)	IntersectRect(lprcDst, lprcSrc1, lprcSrc2)
__EXTERN INTEGER __CALL IntersectRect(WinApi_RECT *lprcDst, WinApi_RECT *lprcSrc1, WinApi_RECT *lprcSrc2);
#define WinApi_InvalidateRect(hWnd, lpRect, lpRect__typ, bErase)	InvalidateRect(hWnd, lpRect, bErase)
__EXTERN INTEGER __CALL InvalidateRect(INTEGER hWnd, WinApi_RECT *lpRect, INTEGER bErase);
#define WinApi_InvalidateRgn(hWnd, hRgn, bErase)	InvalidateRgn(hWnd, hRgn, bErase)
__EXTERN INTEGER __CALL InvalidateRgn(INTEGER hWnd, INTEGER hRgn, INTEGER bErase);
#define WinApi_InvertRect(hDC, lprc, lprc__typ)	InvertRect(hDC, lprc)
__EXTERN INTEGER __CALL InvertRect(INTEGER hDC, WinApi_RECT *lprc);
#define WinApi_InvertRgn(p0, p1)	InvertRgn(p0, p1)
__EXTERN INTEGER __CALL InvertRgn(INTEGER p0, INTEGER p1);
#define WinApi_IsBadCodePtr(lpfn)	IsBadCodePtr(lpfn)
__EXTERN INTEGER __CALL IsBadCodePtr(WinApi_FARPROC lpfn);
#define WinApi_IsBadHugeReadPtr(lp, ucb)	IsBadHugeReadPtr(lp, ucb)
__EXTERN INTEGER __CALL IsBadHugeReadPtr(INTEGER lp, INTEGER ucb);
#define WinApi_IsBadHugeWritePtr(lp, ucb)	IsBadHugeWritePtr(lp, ucb)
__EXTERN INTEGER __CALL IsBadHugeWritePtr(INTEGER lp, INTEGER ucb);
#define WinApi_IsBadReadPtr(lp, ucb)	IsBadReadPtr(lp, ucb)
__EXTERN INTEGER __CALL IsBadReadPtr(INTEGER lp, INTEGER ucb);
#define WinApi_IsBadStringPtr(lpsz, ucchMax)	IsBadStringPtrA(lpsz, ucchMax)
#define WinApi_IsBadStringPtrA(lpsz, ucchMax)	IsBadStringPtrA(lpsz, ucchMax)
__EXTERN INTEGER __CALL IsBadStringPtrA(WinApi_PtrSTR lpsz, INTEGER ucchMax);
#define WinApi_IsBadStringPtrW(lpsz, ucchMax)	IsBadStringPtrW(lpsz, ucchMax)
__EXTERN INTEGER __CALL IsBadStringPtrW(WinApi_PtrWSTR lpsz, INTEGER ucchMax);
#define WinApi_IsBadWritePtr(lp, ucb)	IsBadWritePtr(lp, ucb)
__EXTERN INTEGER __CALL IsBadWritePtr(INTEGER lp, INTEGER ucb);
#define WinApi_IsCharAlpha(ch)	IsCharAlphaA(ch)
#define WinApi_IsCharAlphaA(ch)	IsCharAlphaA(ch)
__EXTERN INTEGER __CALL IsCharAlphaA(CHAR ch);
#define WinApi_IsCharAlphaNumeric(ch)	IsCharAlphaNumericA(ch)
#define WinApi_IsCharAlphaNumericA(ch)	IsCharAlphaNumericA(ch)
__EXTERN INTEGER __CALL IsCharAlphaNumericA(CHAR ch);
#define WinApi_IsCharAlphaNumericW(ch)	IsCharAlphaNumericW(ch)
__EXTERN INTEGER __CALL IsCharAlphaNumericW(SHORTINT ch);
#define WinApi_IsCharAlphaW(ch)	IsCharAlphaW(ch)
__EXTERN INTEGER __CALL IsCharAlphaW(SHORTINT ch);
#define WinApi_IsCharLower(ch)	IsCharLowerA(ch)
#define WinApi_IsCharLowerA(ch)	IsCharLowerA(ch)
__EXTERN INTEGER __CALL IsCharLowerA(CHAR ch);
#define WinApi_IsCharLowerW(ch)	IsCharLowerW(ch)
__EXTERN INTEGER __CALL IsCharLowerW(SHORTINT ch);
#define WinApi_IsCharUpper(ch)	IsCharUpperA(ch)
#define WinApi_IsCharUpperA(ch)	IsCharUpperA(ch)
__EXTERN INTEGER __CALL IsCharUpperA(CHAR ch);
#define WinApi_IsCharUpperW(ch)	IsCharUpperW(ch)
__EXTERN INTEGER __CALL IsCharUpperW(SHORTINT ch);
#define WinApi_IsChild(hWndParent, hWnd)	IsChild(hWndParent, hWnd)
__EXTERN INTEGER __CALL IsChild(INTEGER hWndParent, INTEGER hWnd);
#define WinApi_IsClipboardFormatAvailable(format)	IsClipboardFormatAvailable(format)
__EXTERN INTEGER __CALL IsClipboardFormatAvailable(INTEGER format);
#define WinApi_IsDBCSLeadByte(TestChar)	IsDBCSLeadByte(TestChar)
__EXTERN INTEGER __CALL IsDBCSLeadByte(CHAR TestChar);
#define WinApi_IsDBCSLeadByteEx(CodePage, TestChar)	IsDBCSLeadByteEx(CodePage, TestChar)
__EXTERN INTEGER __CALL IsDBCSLeadByteEx(INTEGER CodePage, CHAR TestChar);
#define WinApi_IsDialogMessage(hDlg, lpMsg, lpMsg__typ)	IsDialogMessageA(hDlg, lpMsg)
#define WinApi_IsDialogMessageA(hDlg, lpMsg, lpMsg__typ)	IsDialogMessageA(hDlg, lpMsg)
__EXTERN INTEGER __CALL IsDialogMessageA(INTEGER hDlg, WinApi_MSG *lpMsg);
#define WinApi_IsDialogMessageW(hDlg, lpMsg, lpMsg__typ)	IsDialogMessageW(hDlg, lpMsg)
__EXTERN INTEGER __CALL IsDialogMessageW(INTEGER hDlg, WinApi_MSG *lpMsg);
#define WinApi_IsDlgButtonChecked(hDlg, nIDButton)	IsDlgButtonChecked(hDlg, nIDButton)
__EXTERN INTEGER __CALL IsDlgButtonChecked(INTEGER hDlg, INTEGER nIDButton);
#define WinApi_IsIconic(hWnd)	IsIconic(hWnd)
__EXTERN INTEGER __CALL IsIconic(INTEGER hWnd);
#define WinApi_IsMenu(hMenu)	IsMenu(hMenu)
__EXTERN INTEGER __CALL IsMenu(INTEGER hMenu);
#define WinApi_IsRectEmpty(lprc, lprc__typ)	IsRectEmpty(lprc)
__EXTERN INTEGER __CALL IsRectEmpty(WinApi_RECT *lprc);
#define WinApi_IsTextUnicode(lpBuffer, cb, lpi)	IsTextUnicode(lpBuffer, cb, lpi)
__EXTERN INTEGER __CALL IsTextUnicode(INTEGER lpBuffer, INTEGER cb, SET *lpi);
#define WinApi_IsValidAcl(pAcl, pAcl__typ)	IsValidAcl(pAcl)
__EXTERN INTEGER __CALL IsValidAcl(WinApi_ACL *pAcl);
#define WinApi_IsValidCodePage(CodePage)	IsValidCodePage(CodePage)
__EXTERN INTEGER __CALL IsValidCodePage(INTEGER CodePage);
#define WinApi_IsValidLocale(Locale, dwFlags)	IsValidLocale(Locale, dwFlags)
__EXTERN INTEGER __CALL IsValidLocale(INTEGER Locale, SET dwFlags);
#define WinApi_IsValidSecurityDescriptor(pSecurityDescriptor)	IsValidSecurityDescriptor(pSecurityDescriptor)
__EXTERN INTEGER __CALL IsValidSecurityDescriptor(INTEGER pSecurityDescriptor);
#define WinApi_IsValidSid(pSid)	IsValidSid(pSid)
__EXTERN INTEGER __CALL IsValidSid(INTEGER pSid);
#define WinApi_IsWindow(hWnd)	IsWindow(hWnd)
__EXTERN INTEGER __CALL IsWindow(INTEGER hWnd);
#define WinApi_IsWindowEnabled(hWnd)	IsWindowEnabled(hWnd)
__EXTERN INTEGER __CALL IsWindowEnabled(INTEGER hWnd);
#define WinApi_IsWindowUnicode(hWnd)	IsWindowUnicode(hWnd)
__EXTERN INTEGER __CALL IsWindowUnicode(INTEGER hWnd);
#define WinApi_IsWindowVisible(hWnd)	IsWindowVisible(hWnd)
__EXTERN INTEGER __CALL IsWindowVisible(INTEGER hWnd);
#define WinApi_IsZoomed(hWnd)	IsZoomed(hWnd)
__EXTERN INTEGER __CALL IsZoomed(INTEGER hWnd);
#define WinApi_KillTimer(hWnd, uIDEvent)	KillTimer(hWnd, uIDEvent)
__EXTERN INTEGER __CALL KillTimer(INTEGER hWnd, INTEGER uIDEvent);
#define WinApi_LCMapString(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
#define WinApi_LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
__EXTERN INTEGER __CALL LCMapStringA(INTEGER Locale, SET dwMapFlags, WinApi_PtrSTR lpSrcStr, INTEGER cchSrc, WinApi_PtrSTR lpDestStr, INTEGER cchDest);
#define WinApi_LCMapStringW(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	LCMapStringW(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
__EXTERN INTEGER __CALL LCMapStringW(INTEGER Locale, SET dwMapFlags, WinApi_PtrWSTR lpSrcStr, INTEGER cchSrc, WinApi_PtrWSTR lpDestStr, INTEGER cchDest);
#define WinApi_LPtoDP(p0, p1, p1__typ, p2)	LPtoDP(p0, p1, p2)
__EXTERN INTEGER __CALL LPtoDP(INTEGER p0, WinApi_POINT *p1, INTEGER p2);
#define WinApi_LZClose(p0)	LZClose(p0)
__EXTERN void __CALL LZClose(INTEGER p0);
#define WinApi_LZCopy(p0, p1)	LZCopy(p0, p1)
__EXTERN INTEGER __CALL LZCopy(INTEGER p0, INTEGER p1);
#define WinApi_LZDone()	LZDone()
__EXTERN void __CALL LZDone(void);
#define WinApi_LZInit(p0)	LZInit(p0)
__EXTERN INTEGER __CALL LZInit(INTEGER p0);
#define WinApi_LZOpenFile(p0, p1, p1__typ, p2)	LZOpenFileA(p0, p1, p2)
#define WinApi_LZOpenFileA(p0, p1, p1__typ, p2)	LZOpenFileA(p0, p1, p2)
__EXTERN INTEGER __CALL LZOpenFileA(WinApi_PtrSTR p0, WinApi_OFSTRUCT *p1, SHORTINT p2);
#define WinApi_LZOpenFileW(p0, p1, p1__typ, p2)	LZOpenFileW(p0, p1, p2)
__EXTERN INTEGER __CALL LZOpenFileW(WinApi_PtrWSTR p0, WinApi_OFSTRUCT *p1, SHORTINT p2);
#define WinApi_LZRead(p0, p1, p2)	LZRead(p0, p1, p2)
__EXTERN INTEGER __CALL LZRead(INTEGER p0, WinApi_PtrSTR p1, INTEGER p2);
#define WinApi_LZSeek(p0, p1, p2)	LZSeek(p0, p1, p2)
__EXTERN INTEGER __CALL LZSeek(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_LZStart()	LZStart()
__EXTERN INTEGER __CALL LZStart(void);
#define WinApi_LeaveCriticalSection(lpCriticalSection, lpCriticalSection__typ)	LeaveCriticalSection(lpCriticalSection)
__EXTERN void __CALL LeaveCriticalSection(WinApi_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinApi_LineDDA(p0, p1, p2, p3, p4, p5)	LineDDA(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL LineDDA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinApi_LINEDDAPROC p4, INTEGER p5);
#define WinApi_LineTo(p0, p1, p2)	LineTo(p0, p1, p2)
__EXTERN INTEGER __CALL LineTo(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_LoadAccelerators(hInstance, lpTableName)	LoadAcceleratorsA(hInstance, lpTableName)
#define WinApi_LoadAcceleratorsA(hInstance, lpTableName)	LoadAcceleratorsA(hInstance, lpTableName)
__EXTERN INTEGER __CALL LoadAcceleratorsA(INTEGER hInstance, WinApi_PtrSTR lpTableName);
#define WinApi_LoadAcceleratorsW(hInstance, lpTableName)	LoadAcceleratorsW(hInstance, lpTableName)
__EXTERN INTEGER __CALL LoadAcceleratorsW(INTEGER hInstance, WinApi_PtrWSTR lpTableName);
#define WinApi_LoadBitmap(hInstance, lpBitmapName)	LoadBitmapA(hInstance, lpBitmapName)
#define WinApi_LoadBitmapA(hInstance, lpBitmapName)	LoadBitmapA(hInstance, lpBitmapName)
__EXTERN INTEGER __CALL LoadBitmapA(INTEGER hInstance, WinApi_PtrSTR lpBitmapName);
#define WinApi_LoadBitmapW(hInstance, lpBitmapName)	LoadBitmapW(hInstance, lpBitmapName)
__EXTERN INTEGER __CALL LoadBitmapW(INTEGER hInstance, WinApi_PtrWSTR lpBitmapName);
#define WinApi_LoadCursor(hInstance, lpCursorName)	LoadCursorA(hInstance, lpCursorName)
#define WinApi_LoadCursorA(hInstance, lpCursorName)	LoadCursorA(hInstance, lpCursorName)
__EXTERN INTEGER __CALL LoadCursorA(INTEGER hInstance, WinApi_PtrSTR lpCursorName);
#define WinApi_LoadCursorFromFile(lpFileName)	LoadCursorFromFileA(lpFileName)
#define WinApi_LoadCursorFromFileA(lpFileName)	LoadCursorFromFileA(lpFileName)
__EXTERN INTEGER __CALL LoadCursorFromFileA(WinApi_PtrSTR lpFileName);
#define WinApi_LoadCursorFromFileW(lpFileName)	LoadCursorFromFileW(lpFileName)
__EXTERN INTEGER __CALL LoadCursorFromFileW(WinApi_PtrWSTR lpFileName);
#define WinApi_LoadCursorW(hInstance, lpCursorName)	LoadCursorW(hInstance, lpCursorName)
__EXTERN INTEGER __CALL LoadCursorW(INTEGER hInstance, WinApi_PtrWSTR lpCursorName);
#define WinApi_LoadIcon(hInstance, lpIconName)	LoadIconA(hInstance, lpIconName)
#define WinApi_LoadIconA(hInstance, lpIconName)	LoadIconA(hInstance, lpIconName)
__EXTERN INTEGER __CALL LoadIconA(INTEGER hInstance, WinApi_PtrSTR lpIconName);
#define WinApi_LoadIconW(hInstance, lpIconName)	LoadIconW(hInstance, lpIconName)
__EXTERN INTEGER __CALL LoadIconW(INTEGER hInstance, WinApi_PtrWSTR lpIconName);
#define WinApi_LoadImage(p0, p1, p2, p3, p4, p5)	LoadImageA(p0, p1, p2, p3, p4, p5)
#define WinApi_LoadImageA(p0, p1, p2, p3, p4, p5)	LoadImageA(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL LoadImageA(INTEGER p0, WinApi_PtrSTR p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
#define WinApi_LoadImageW(p0, p1, p2, p3, p4, p5)	LoadImageW(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL LoadImageW(INTEGER p0, WinApi_PtrWSTR p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
#define WinApi_LoadKeyboardLayout(pwszKLID, Flags)	LoadKeyboardLayoutA(pwszKLID, Flags)
#define WinApi_LoadKeyboardLayoutA(pwszKLID, Flags)	LoadKeyboardLayoutA(pwszKLID, Flags)
__EXTERN INTEGER __CALL LoadKeyboardLayoutA(WinApi_PtrSTR pwszKLID, SET Flags);
#define WinApi_LoadKeyboardLayoutW(pwszKLID, Flags)	LoadKeyboardLayoutW(pwszKLID, Flags)
__EXTERN INTEGER __CALL LoadKeyboardLayoutW(WinApi_PtrWSTR pwszKLID, SET Flags);
#define WinApi_LoadLibrary(lpLibFileName)	LoadLibraryA(lpLibFileName)
#define WinApi_LoadLibraryA(lpLibFileName)	LoadLibraryA(lpLibFileName)
__EXTERN INTEGER __CALL LoadLibraryA(WinApi_PtrSTR lpLibFileName);
#define WinApi_LoadLibraryEx(lpLibFileName, hFile, dwFlags)	LoadLibraryExA(lpLibFileName, hFile, dwFlags)
#define WinApi_LoadLibraryExA(lpLibFileName, hFile, dwFlags)	LoadLibraryExA(lpLibFileName, hFile, dwFlags)
__EXTERN INTEGER __CALL LoadLibraryExA(WinApi_PtrSTR lpLibFileName, INTEGER hFile, SET dwFlags);
#define WinApi_LoadLibraryExW(lpLibFileName, hFile, dwFlags)	LoadLibraryExW(lpLibFileName, hFile, dwFlags)
__EXTERN INTEGER __CALL LoadLibraryExW(WinApi_PtrWSTR lpLibFileName, INTEGER hFile, SET dwFlags);
#define WinApi_LoadLibraryW(lpLibFileName)	LoadLibraryW(lpLibFileName)
__EXTERN INTEGER __CALL LoadLibraryW(WinApi_PtrWSTR lpLibFileName);
#define WinApi_LoadMenu(hInstance, lpMenuName)	LoadMenuA(hInstance, lpMenuName)
#define WinApi_LoadMenuA(hInstance, lpMenuName)	LoadMenuA(hInstance, lpMenuName)
__EXTERN INTEGER __CALL LoadMenuA(INTEGER hInstance, WinApi_PtrSTR lpMenuName);
#define WinApi_LoadMenuIndirect(lpMenuTemplate)	LoadMenuIndirectA(lpMenuTemplate)
#define WinApi_LoadMenuIndirectA(lpMenuTemplate)	LoadMenuIndirectA(lpMenuTemplate)
__EXTERN INTEGER __CALL LoadMenuIndirectA(WinApi_PtrMENUTEMPLATEA lpMenuTemplate);
#define WinApi_LoadMenuIndirectW(lpMenuTemplate)	LoadMenuIndirectW(lpMenuTemplate)
__EXTERN INTEGER __CALL LoadMenuIndirectW(WinApi_PtrMENUTEMPLATEW lpMenuTemplate);
#define WinApi_LoadMenuW(hInstance, lpMenuName)	LoadMenuW(hInstance, lpMenuName)
__EXTERN INTEGER __CALL LoadMenuW(INTEGER hInstance, WinApi_PtrWSTR lpMenuName);
#define WinApi_LoadModule(lpModuleName, lpParameterBlock)	LoadModule(lpModuleName, lpParameterBlock)
__EXTERN INTEGER __CALL LoadModule(WinApi_PtrSTR lpModuleName, INTEGER lpParameterBlock);
#define WinApi_LoadResource(hModule, hResInfo)	LoadResource(hModule, hResInfo)
__EXTERN INTEGER __CALL LoadResource(INTEGER hModule, INTEGER hResInfo);
#define WinApi_LoadString(hInstance, uID, lpBuffer, nBufferMax)	LoadStringA(hInstance, uID, lpBuffer, nBufferMax)
#define WinApi_LoadStringA(hInstance, uID, lpBuffer, nBufferMax)	LoadStringA(hInstance, uID, lpBuffer, nBufferMax)
__EXTERN INTEGER __CALL LoadStringA(INTEGER hInstance, INTEGER uID, WinApi_PtrSTR lpBuffer, INTEGER nBufferMax);
#define WinApi_LoadStringW(hInstance, uID, lpBuffer, nBufferMax)	LoadStringW(hInstance, uID, lpBuffer, nBufferMax)
__EXTERN INTEGER __CALL LoadStringW(INTEGER hInstance, INTEGER uID, WinApi_PtrWSTR lpBuffer, INTEGER nBufferMax);
#define WinApi_LocalAlloc(uFlags, uBytes)	LocalAlloc(uFlags, uBytes)
__EXTERN INTEGER __CALL LocalAlloc(SET uFlags, INTEGER uBytes);
#define WinApi_LocalCompact(uMinFree)	LocalCompact(uMinFree)
__EXTERN INTEGER __CALL LocalCompact(INTEGER uMinFree);
#define WinApi_LocalFileTimeToFileTime(lpLocalFileTime, lpLocalFileTime__typ, lpFileTime, lpFileTime__typ)	LocalFileTimeToFileTime(lpLocalFileTime, lpFileTime)
__EXTERN INTEGER __CALL LocalFileTimeToFileTime(WinApi_FILETIME *lpLocalFileTime, WinApi_FILETIME *lpFileTime);
#define WinApi_LocalFlags(hMem)	LocalFlags(hMem)
__EXTERN INTEGER __CALL LocalFlags(INTEGER hMem);
#define WinApi_LocalFree(hMem)	LocalFree(hMem)
__EXTERN INTEGER __CALL LocalFree(INTEGER hMem);
#define WinApi_LocalHandle(pMem)	LocalHandle(pMem)
__EXTERN INTEGER __CALL LocalHandle(INTEGER pMem);
#define WinApi_LocalLock(hMem)	LocalLock(hMem)
__EXTERN INTEGER __CALL LocalLock(INTEGER hMem);
#define WinApi_LocalReAlloc(hMem, uBytes, uFlags)	LocalReAlloc(hMem, uBytes, uFlags)
__EXTERN INTEGER __CALL LocalReAlloc(INTEGER hMem, INTEGER uBytes, SET uFlags);
#define WinApi_LocalShrink(hMem, cbNewSize)	LocalShrink(hMem, cbNewSize)
__EXTERN INTEGER __CALL LocalShrink(INTEGER hMem, INTEGER cbNewSize);
#define WinApi_LocalSize(hMem)	LocalSize(hMem)
__EXTERN INTEGER __CALL LocalSize(INTEGER hMem);
#define WinApi_LocalUnlock(hMem)	LocalUnlock(hMem)
__EXTERN INTEGER __CALL LocalUnlock(INTEGER hMem);
#define WinApi_LockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh)	LockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh)
__EXTERN INTEGER __CALL LockFile(INTEGER hFile, INTEGER dwFileOffsetLow, INTEGER dwFileOffsetHigh, INTEGER nNumberOfBytesToLockLow, INTEGER nNumberOfBytesToLockHigh);
#define WinApi_LockFileEx(hFile, dwFlags, dwReserved, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh, lpOverlapped, lpOverlapped__typ)	LockFileEx(hFile, dwFlags, dwReserved, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh, lpOverlapped)
__EXTERN INTEGER __CALL LockFileEx(INTEGER hFile, SET dwFlags, INTEGER dwReserved, INTEGER nNumberOfBytesToLockLow, INTEGER nNumberOfBytesToLockHigh, WinApi_OVERLAPPED *lpOverlapped);
#define WinApi_LockResource(hResData)	LockResource(hResData)
__EXTERN INTEGER __CALL LockResource(INTEGER hResData);
#define WinApi_LockServiceDatabase(hSCManager)	LockServiceDatabase(hSCManager)
__EXTERN INTEGER __CALL LockServiceDatabase(INTEGER hSCManager);
#define WinApi_LockWindowUpdate(hWndLock)	LockWindowUpdate(hWndLock)
__EXTERN INTEGER __CALL LockWindowUpdate(INTEGER hWndLock);
#define WinApi_LogonUser(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)	LogonUserA(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)
#define WinApi_LogonUserA(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)	LogonUserA(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)
__EXTERN INTEGER __CALL LogonUserA(WinApi_PtrSTR lpszUsername, WinApi_PtrSTR lpszDomain, WinApi_PtrSTR lpszPassword, INTEGER dwLogonType, INTEGER dwLogonProvider, INTEGER *phToken);
#define WinApi_LogonUserW(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)	LogonUserW(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)
__EXTERN INTEGER __CALL LogonUserW(WinApi_PtrWSTR lpszUsername, WinApi_PtrWSTR lpszDomain, WinApi_PtrWSTR lpszPassword, INTEGER dwLogonType, INTEGER dwLogonProvider, INTEGER *phToken);
#define WinApi_LookupAccountName(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountNameA(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)
#define WinApi_LookupAccountNameA(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountNameA(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)
__EXTERN INTEGER __CALL LookupAccountNameA(WinApi_PtrSTR lpSystemName, WinApi_PtrSTR lpAccountName, INTEGER Sid, INTEGER *cbSid, WinApi_PtrSTR ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
#define WinApi_LookupAccountNameW(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountNameW(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)
__EXTERN INTEGER __CALL LookupAccountNameW(WinApi_PtrWSTR lpSystemName, WinApi_PtrWSTR lpAccountName, INTEGER Sid, INTEGER *cbSid, WinApi_PtrWSTR ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
#define WinApi_LookupAccountSid(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountSidA(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)
#define WinApi_LookupAccountSidA(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountSidA(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)
__EXTERN INTEGER __CALL LookupAccountSidA(WinApi_PtrSTR lpSystemName, INTEGER Sid, WinApi_PtrSTR Name, INTEGER *cbName, WinApi_PtrSTR ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
#define WinApi_LookupAccountSidW(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountSidW(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)
__EXTERN INTEGER __CALL LookupAccountSidW(WinApi_PtrWSTR lpSystemName, INTEGER Sid, WinApi_PtrWSTR Name, INTEGER *cbName, WinApi_PtrWSTR ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
#define WinApi_LookupIconIdFromDirectory(presbits, fIcon)	LookupIconIdFromDirectory(presbits, fIcon)
__EXTERN INTEGER __CALL LookupIconIdFromDirectory(CHAR *presbits, INTEGER fIcon);
#define WinApi_LookupIconIdFromDirectoryEx(presbits, fIcon, cxDesired, cyDesired, Flags)	LookupIconIdFromDirectoryEx(presbits, fIcon, cxDesired, cyDesired, Flags)
__EXTERN INTEGER __CALL LookupIconIdFromDirectoryEx(CHAR *presbits, INTEGER fIcon, INTEGER cxDesired, INTEGER cyDesired, SET Flags);
#define WinApi_LookupPrivilegeDisplayName(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)	LookupPrivilegeDisplayNameA(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)
#define WinApi_LookupPrivilegeDisplayNameA(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)	LookupPrivilegeDisplayNameA(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)
__EXTERN INTEGER __CALL LookupPrivilegeDisplayNameA(WinApi_PtrSTR lpSystemName, WinApi_PtrSTR lpName, WinApi_PtrSTR lpDisplayName, INTEGER *cbDisplayName, INTEGER *lpLanguageId);
#define WinApi_LookupPrivilegeDisplayNameW(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)	LookupPrivilegeDisplayNameW(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)
__EXTERN INTEGER __CALL LookupPrivilegeDisplayNameW(WinApi_PtrWSTR lpSystemName, WinApi_PtrWSTR lpName, WinApi_PtrWSTR lpDisplayName, INTEGER *cbDisplayName, INTEGER *lpLanguageId);
#define WinApi_LookupPrivilegeName(lpSystemName, lpLuid, lpName, cbName)	LookupPrivilegeNameA(lpSystemName, lpLuid, lpName, cbName)
#define WinApi_LookupPrivilegeNameA(lpSystemName, lpLuid, lpName, cbName)	LookupPrivilegeNameA(lpSystemName, lpLuid, lpName, cbName)
__EXTERN INTEGER __CALL LookupPrivilegeNameA(WinApi_PtrSTR lpSystemName, LONGINT *lpLuid, WinApi_PtrSTR lpName, INTEGER *cbName);
#define WinApi_LookupPrivilegeNameW(lpSystemName, lpLuid, lpName, cbName)	LookupPrivilegeNameW(lpSystemName, lpLuid, lpName, cbName)
__EXTERN INTEGER __CALL LookupPrivilegeNameW(WinApi_PtrWSTR lpSystemName, LONGINT *lpLuid, WinApi_PtrWSTR lpName, INTEGER *cbName);
#define WinApi_LookupPrivilegeValue(lpSystemName, lpName, lpLuid)	LookupPrivilegeValueA(lpSystemName, lpName, lpLuid)
#define WinApi_LookupPrivilegeValueA(lpSystemName, lpName, lpLuid)	LookupPrivilegeValueA(lpSystemName, lpName, lpLuid)
__EXTERN INTEGER __CALL LookupPrivilegeValueA(WinApi_PtrSTR lpSystemName, WinApi_PtrSTR lpName, LONGINT *lpLuid);
#define WinApi_LookupPrivilegeValueW(lpSystemName, lpName, lpLuid)	LookupPrivilegeValueW(lpSystemName, lpName, lpLuid)
__EXTERN INTEGER __CALL LookupPrivilegeValueW(WinApi_PtrWSTR lpSystemName, WinApi_PtrWSTR lpName, LONGINT *lpLuid);
#define WinApi_MakeAbsoluteSD(pSelfRelativeSecurityDescriptor, pAbsoluteSecurityDescriptor, lpdwAbsoluteSecurityDescriptorSize, pDacl, pDacl__typ, lpdwDaclSize, pSacl, pSacl__typ, lpdwSaclSize, pOwner, lpdwOwnerSize, pPrimaryGroup, lpdwPrimaryGroupSize)	MakeAbsoluteSD(pSelfRelativeSecurityDescriptor, pAbsoluteSecurityDescriptor, lpdwAbsoluteSecurityDescriptorSize, pDacl, lpdwDaclSize, pSacl, lpdwSaclSize, pOwner, lpdwOwnerSize, pPrimaryGroup, lpdwPrimaryGroupSize)
__EXTERN INTEGER __CALL MakeAbsoluteSD(INTEGER pSelfRelativeSecurityDescriptor, INTEGER pAbsoluteSecurityDescriptor, INTEGER *lpdwAbsoluteSecurityDescriptorSize, WinApi_ACL *pDacl, INTEGER *lpdwDaclSize, WinApi_ACL *pSacl, INTEGER *lpdwSaclSize, INTEGER pOwner, INTEGER *lpdwOwnerSize, INTEGER pPrimaryGroup, INTEGER *lpdwPrimaryGroupSize);
#define WinApi_MakeSelfRelativeSD(pAbsoluteSecurityDescriptor, pSelfRelativeSecurityDescriptor, lpdwBufferLength)	MakeSelfRelativeSD(pAbsoluteSecurityDescriptor, pSelfRelativeSecurityDescriptor, lpdwBufferLength)
__EXTERN INTEGER __CALL MakeSelfRelativeSD(INTEGER pAbsoluteSecurityDescriptor, INTEGER pSelfRelativeSecurityDescriptor, INTEGER *lpdwBufferLength);
#define WinApi_MapDialogRect(hDlg, lpRect, lpRect__typ)	MapDialogRect(hDlg, lpRect)
__EXTERN INTEGER __CALL MapDialogRect(INTEGER hDlg, WinApi_RECT *lpRect);
#define WinApi_MapGenericMask(AccessMask, GenericMapping, GenericMapping__typ)	MapGenericMask(AccessMask, GenericMapping)
__EXTERN void __CALL MapGenericMask(INTEGER *AccessMask, WinApi_GENERIC_MAPPING *GenericMapping);
#define WinApi_MapViewOfFile(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap)	MapViewOfFile(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap)
__EXTERN INTEGER __CALL MapViewOfFile(INTEGER hFileMappingObject, SET dwDesiredAccess, INTEGER dwFileOffsetHigh, INTEGER dwFileOffsetLow, INTEGER dwNumberOfBytesToMap);
#define WinApi_MapViewOfFileEx(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress)	MapViewOfFileEx(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress)
__EXTERN INTEGER __CALL MapViewOfFileEx(INTEGER hFileMappingObject, SET dwDesiredAccess, INTEGER dwFileOffsetHigh, INTEGER dwFileOffsetLow, INTEGER dwNumberOfBytesToMap, INTEGER lpBaseAddress);
#define WinApi_MapVirtualKey(uCode, uMapType)	MapVirtualKeyA(uCode, uMapType)
#define WinApi_MapVirtualKeyA(uCode, uMapType)	MapVirtualKeyA(uCode, uMapType)
__EXTERN INTEGER __CALL MapVirtualKeyA(INTEGER uCode, INTEGER uMapType);
#define WinApi_MapVirtualKeyEx(uCode, uMapType, dwhkl)	MapVirtualKeyExA(uCode, uMapType, dwhkl)
#define WinApi_MapVirtualKeyExA(uCode, uMapType, dwhkl)	MapVirtualKeyExA(uCode, uMapType, dwhkl)
__EXTERN INTEGER __CALL MapVirtualKeyExA(INTEGER uCode, INTEGER uMapType, INTEGER dwhkl);
#define WinApi_MapVirtualKeyExW(uCode, uMapType, dwhkl)	MapVirtualKeyExW(uCode, uMapType, dwhkl)
__EXTERN INTEGER __CALL MapVirtualKeyExW(INTEGER uCode, INTEGER uMapType, INTEGER dwhkl);
#define WinApi_MapVirtualKeyW(uCode, uMapType)	MapVirtualKeyW(uCode, uMapType)
__EXTERN INTEGER __CALL MapVirtualKeyW(INTEGER uCode, INTEGER uMapType);
#define WinApi_MapWindowPoints(hWndFrom, hWndTo, lpPoints, lpPoints__typ, cPoints)	MapWindowPoints(hWndFrom, hWndTo, lpPoints, cPoints)
__EXTERN INTEGER __CALL MapWindowPoints(INTEGER hWndFrom, INTEGER hWndTo, WinApi_POINT *lpPoints, INTEGER cPoints);
#define WinApi_MaskBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)	MaskBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)
__EXTERN INTEGER __CALL MaskBlt(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10, INTEGER p11);
#define WinApi_MenuItemFromPoint(hWnd, hMenu, ptScreen)	MenuItemFromPoint(hWnd, hMenu, ptScreen)
__EXTERN INTEGER __CALL MenuItemFromPoint(INTEGER hWnd, INTEGER hMenu, WinApi_POINT ptScreen);
#define WinApi_MessageBeep(uType)	MessageBeep(uType)
__EXTERN INTEGER __CALL MessageBeep(SET uType);
#define WinApi_MessageBox(hWnd, lpText, lpCaption, uType)	MessageBoxA(hWnd, lpText, lpCaption, uType)
#define WinApi_MessageBoxA(hWnd, lpText, lpCaption, uType)	MessageBoxA(hWnd, lpText, lpCaption, uType)
__EXTERN INTEGER __CALL MessageBoxA(INTEGER hWnd, WinApi_PtrSTR lpText, WinApi_PtrSTR lpCaption, SET uType);
#define WinApi_MessageBoxEx(hWnd, lpText, lpCaption, uType, wLanguageId)	MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId)
#define WinApi_MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId)	MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId)
__EXTERN INTEGER __CALL MessageBoxExA(INTEGER hWnd, WinApi_PtrSTR lpText, WinApi_PtrSTR lpCaption, SET uType, SHORTINT wLanguageId);
#define WinApi_MessageBoxExW(hWnd, lpText, lpCaption, uType, wLanguageId)	MessageBoxExW(hWnd, lpText, lpCaption, uType, wLanguageId)
__EXTERN INTEGER __CALL MessageBoxExW(INTEGER hWnd, WinApi_PtrWSTR lpText, WinApi_PtrWSTR lpCaption, SET uType, SHORTINT wLanguageId);
#define WinApi_MessageBoxIndirect(p0, p0__typ)	MessageBoxIndirectA(p0)
#define WinApi_MessageBoxIndirectA(p0, p0__typ)	MessageBoxIndirectA(p0)
__EXTERN INTEGER __CALL MessageBoxIndirectA(WinApi_MSGBOXPARAMSA *p0);
#define WinApi_MessageBoxIndirectW(p0, p0__typ)	MessageBoxIndirectW(p0)
__EXTERN INTEGER __CALL MessageBoxIndirectW(WinApi_MSGBOXPARAMSW *p0);
#define WinApi_MessageBoxW(hWnd, lpText, lpCaption, uType)	MessageBoxW(hWnd, lpText, lpCaption, uType)
__EXTERN INTEGER __CALL MessageBoxW(INTEGER hWnd, WinApi_PtrWSTR lpText, WinApi_PtrWSTR lpCaption, SET uType);
#define WinApi_ModifyMenu(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)	ModifyMenuA(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)
#define WinApi_ModifyMenuA(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)	ModifyMenuA(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __CALL ModifyMenuA(INTEGER hMnu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, WinApi_PtrSTR lpNewItem);
#define WinApi_ModifyMenuW(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)	ModifyMenuW(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __CALL ModifyMenuW(INTEGER hMnu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, WinApi_PtrWSTR lpNewItem);
#define WinApi_ModifyWorldTransform(p0, p1, p1__typ, p2)	ModifyWorldTransform(p0, p1, p2)
__EXTERN INTEGER __CALL ModifyWorldTransform(INTEGER p0, WinApi_XFORM *p1, INTEGER p2);
#define WinApi_MoveFile(lpExistingFileName, lpNewFileName)	MoveFileA(lpExistingFileName, lpNewFileName)
#define WinApi_MoveFileA(lpExistingFileName, lpNewFileName)	MoveFileA(lpExistingFileName, lpNewFileName)
__EXTERN INTEGER __CALL MoveFileA(WinApi_PtrSTR lpExistingFileName, WinApi_PtrSTR lpNewFileName);
#define WinApi_MoveFileEx(lpExistingFileName, lpNewFileName, dwFlags)	MoveFileExA(lpExistingFileName, lpNewFileName, dwFlags)
#define WinApi_MoveFileExA(lpExistingFileName, lpNewFileName, dwFlags)	MoveFileExA(lpExistingFileName, lpNewFileName, dwFlags)
__EXTERN INTEGER __CALL MoveFileExA(WinApi_PtrSTR lpExistingFileName, WinApi_PtrSTR lpNewFileName, SET dwFlags);
#define WinApi_MoveFileExW(lpExistingFileName, lpNewFileName, dwFlags)	MoveFileExW(lpExistingFileName, lpNewFileName, dwFlags)
__EXTERN INTEGER __CALL MoveFileExW(WinApi_PtrWSTR lpExistingFileName, WinApi_PtrWSTR lpNewFileName, SET dwFlags);
#define WinApi_MoveFileW(lpExistingFileName, lpNewFileName)	MoveFileW(lpExistingFileName, lpNewFileName)
__EXTERN INTEGER __CALL MoveFileW(WinApi_PtrWSTR lpExistingFileName, WinApi_PtrWSTR lpNewFileName);
#define WinApi_MoveToEx(p0, p1, p2, p3, p3__typ)	MoveToEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL MoveToEx(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_POINT *p3);
#define WinApi_MoveWindow(hWnd, X, Y, nWidth, nHeight, bRepaint)	MoveWindow(hWnd, X, Y, nWidth, nHeight, bRepaint)
__EXTERN INTEGER __CALL MoveWindow(INTEGER hWnd, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER bRepaint);
#define WinApi_MsgWaitForMultipleObjects(nCount, pHandles, fWaitAll, dwMilliseconds, dwWakeMask)	MsgWaitForMultipleObjects(nCount, pHandles, fWaitAll, dwMilliseconds, dwWakeMask)
__EXTERN INTEGER __CALL MsgWaitForMultipleObjects(INTEGER nCount, INTEGER *pHandles, INTEGER fWaitAll, INTEGER dwMilliseconds, INTEGER dwWakeMask);
#define WinApi_MsgWaitForMultipleObjectsEx(nCount, pHandles, dwMilliseconds, dwWakeMask, dwFlags)	MsgWaitForMultipleObjectsEx(nCount, pHandles, dwMilliseconds, dwWakeMask, dwFlags)
__EXTERN INTEGER __CALL MsgWaitForMultipleObjectsEx(INTEGER nCount, INTEGER *pHandles, INTEGER dwMilliseconds, INTEGER dwWakeMask, SET dwFlags);
#define WinApi_MulDiv(nNumber, nNumerator, nDenominator)	MulDiv(nNumber, nNumerator, nDenominator)
__EXTERN INTEGER __CALL MulDiv(INTEGER nNumber, INTEGER nNumerator, INTEGER nDenominator);
#define WinApi_MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cchMultiByte, lpWideCharStr, cchWideChar)	MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cchMultiByte, lpWideCharStr, cchWideChar)
__EXTERN INTEGER __CALL MultiByteToWideChar(INTEGER CodePage, SET dwFlags, WinApi_PtrSTR lpMultiByteStr, INTEGER cchMultiByte, WinApi_PtrWSTR lpWideCharStr, INTEGER cchWideChar);
#define WinApi_NotifyBootConfigStatus(BootAcceptable)	NotifyBootConfigStatus(BootAcceptable)
__EXTERN INTEGER __CALL NotifyBootConfigStatus(INTEGER BootAcceptable);
#define WinApi_NotifyChangeEventLog(hEventLog, hEvent)	NotifyChangeEventLog(hEventLog, hEvent)
__EXTERN INTEGER __CALL NotifyChangeEventLog(INTEGER hEventLog, INTEGER hEvent);
#define WinApi_ObjectCloseAuditAlarm(SubsystemName, HandleId, GenerateOnClose)	ObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose)
#define WinApi_ObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose)	ObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose)
__EXTERN INTEGER __CALL ObjectCloseAuditAlarmA(WinApi_PtrSTR SubsystemName, INTEGER HandleId, INTEGER GenerateOnClose);
#define WinApi_ObjectCloseAuditAlarmW(SubsystemName, HandleId, GenerateOnClose)	ObjectCloseAuditAlarmW(SubsystemName, HandleId, GenerateOnClose)
__EXTERN INTEGER __CALL ObjectCloseAuditAlarmW(WinApi_PtrWSTR SubsystemName, INTEGER HandleId, INTEGER GenerateOnClose);
#define WinApi_ObjectOpenAuditAlarm(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, Privileges__typ, ObjectCreation, AccessGranted, GenerateOnClose)	ObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)
#define WinApi_ObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, Privileges__typ, ObjectCreation, AccessGranted, GenerateOnClose)	ObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)
__EXTERN INTEGER __CALL ObjectOpenAuditAlarmA(WinApi_PtrSTR SubsystemName, INTEGER HandleId, WinApi_PtrSTR ObjectTypeName, WinApi_PtrSTR ObjectName, INTEGER pSecurityDescriptor, INTEGER ClientToken, SET DesiredAccess, INTEGER GrantedAccess, WinApi_PRIVILEGE_SET *Privileges, INTEGER ObjectCreation, INTEGER AccessGranted, INTEGER *GenerateOnClose);
#define WinApi_ObjectOpenAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, Privileges__typ, ObjectCreation, AccessGranted, GenerateOnClose)	ObjectOpenAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)
__EXTERN INTEGER __CALL ObjectOpenAuditAlarmW(WinApi_PtrWSTR SubsystemName, INTEGER HandleId, WinApi_PtrWSTR ObjectTypeName, WinApi_PtrWSTR ObjectName, INTEGER pSecurityDescriptor, INTEGER ClientToken, SET DesiredAccess, INTEGER GrantedAccess, WinApi_PRIVILEGE_SET *Privileges, INTEGER ObjectCreation, INTEGER AccessGranted, INTEGER *GenerateOnClose);
#define WinApi_ObjectPrivilegeAuditAlarm(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, Privileges__typ, AccessGranted)	ObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)
#define WinApi_ObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, Privileges__typ, AccessGranted)	ObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)
__EXTERN INTEGER __CALL ObjectPrivilegeAuditAlarmA(WinApi_PtrSTR SubsystemName, INTEGER HandleId, INTEGER ClientToken, SET DesiredAccess, WinApi_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
#define WinApi_ObjectPrivilegeAuditAlarmW(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, Privileges__typ, AccessGranted)	ObjectPrivilegeAuditAlarmW(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)
__EXTERN INTEGER __CALL ObjectPrivilegeAuditAlarmW(WinApi_PtrWSTR SubsystemName, INTEGER HandleId, INTEGER ClientToken, SET DesiredAccess, WinApi_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
#define WinApi_OemKeyScan(wOemChar)	OemKeyScan(wOemChar)
__EXTERN INTEGER __CALL OemKeyScan(SHORTINT wOemChar);
#define WinApi_OemToAnsi(lpszSrc, lpszDst)	OemToCharA(lpszSrc, lpszDst)
#define WinApi_OemToAnsiBuff(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinApi_OemToChar(lpszSrc, lpszDst)	OemToCharA(lpszSrc, lpszDst)
#define WinApi_OemToCharA(lpszSrc, lpszDst)	OemToCharA(lpszSrc, lpszDst)
__EXTERN INTEGER __CALL OemToCharA(WinApi_PtrSTR lpszSrc, WinApi_PtrSTR lpszDst);
#define WinApi_OemToCharBuff(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinApi_OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __CALL OemToCharBuffA(WinApi_PtrSTR lpszSrc, WinApi_PtrSTR lpszDst, INTEGER cchDstLength);
#define WinApi_OemToCharBuffW(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffW(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __CALL OemToCharBuffW(WinApi_PtrSTR lpszSrc, WinApi_PtrWSTR lpszDst, INTEGER cchDstLength);
#define WinApi_OemToCharW(lpszSrc, lpszDst)	OemToCharW(lpszSrc, lpszDst)
__EXTERN INTEGER __CALL OemToCharW(WinApi_PtrSTR lpszSrc, WinApi_PtrWSTR lpszDst);
#define WinApi_OffsetClipRgn(p0, p1, p2)	OffsetClipRgn(p0, p1, p2)
__EXTERN INTEGER __CALL OffsetClipRgn(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_OffsetRect(lprc, lprc__typ, dx, dy)	OffsetRect(lprc, dx, dy)
__EXTERN INTEGER __CALL OffsetRect(WinApi_RECT *lprc, INTEGER dx, INTEGER dy);
#define WinApi_OffsetRgn(p0, p1, p2)	OffsetRgn(p0, p1, p2)
__EXTERN INTEGER __CALL OffsetRgn(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_OffsetViewportOrgEx(p0, p1, p2, p3, p3__typ)	OffsetViewportOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL OffsetViewportOrgEx(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_POINT *p3);
#define WinApi_OffsetWindowOrgEx(p0, p1, p2, p3, p3__typ)	OffsetWindowOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL OffsetWindowOrgEx(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_POINT *p3);
#define WinApi_OpenBackupEventLog(lpUNCServerName, lpFileName)	OpenBackupEventLogA(lpUNCServerName, lpFileName)
#define WinApi_OpenBackupEventLogA(lpUNCServerName, lpFileName)	OpenBackupEventLogA(lpUNCServerName, lpFileName)
__EXTERN INTEGER __CALL OpenBackupEventLogA(WinApi_PtrSTR lpUNCServerName, WinApi_PtrSTR lpFileName);
#define WinApi_OpenBackupEventLogW(lpUNCServerName, lpFileName)	OpenBackupEventLogW(lpUNCServerName, lpFileName)
__EXTERN INTEGER __CALL OpenBackupEventLogW(WinApi_PtrWSTR lpUNCServerName, WinApi_PtrWSTR lpFileName);
#define WinApi_OpenClipboard(hWndNewOwner)	OpenClipboard(hWndNewOwner)
__EXTERN INTEGER __CALL OpenClipboard(INTEGER hWndNewOwner);
#define WinApi_OpenDesktop(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)	OpenDesktopA(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)
#define WinApi_OpenDesktopA(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)	OpenDesktopA(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)
__EXTERN INTEGER __CALL OpenDesktopA(WinApi_PtrSTR lpszDesktop, SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
#define WinApi_OpenDesktopW(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)	OpenDesktopW(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)
__EXTERN INTEGER __CALL OpenDesktopW(WinApi_PtrWSTR lpszDesktop, SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
#define WinApi_OpenEvent(dwDesiredAccess, bInheritHandle, lpName)	OpenEventA(dwDesiredAccess, bInheritHandle, lpName)
#define WinApi_OpenEventA(dwDesiredAccess, bInheritHandle, lpName)	OpenEventA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL OpenEventA(SET dwDesiredAccess, INTEGER bInheritHandle, WinApi_PtrSTR lpName);
#define WinApi_OpenEventLog(lpUNCServerName, lpSourceName)	OpenEventLogA(lpUNCServerName, lpSourceName)
#define WinApi_OpenEventLogA(lpUNCServerName, lpSourceName)	OpenEventLogA(lpUNCServerName, lpSourceName)
__EXTERN INTEGER __CALL OpenEventLogA(WinApi_PtrSTR lpUNCServerName, WinApi_PtrSTR lpSourceName);
#define WinApi_OpenEventLogW(lpUNCServerName, lpSourceName)	OpenEventLogW(lpUNCServerName, lpSourceName)
__EXTERN INTEGER __CALL OpenEventLogW(WinApi_PtrWSTR lpUNCServerName, WinApi_PtrWSTR lpSourceName);
#define WinApi_OpenEventW(dwDesiredAccess, bInheritHandle, lpName)	OpenEventW(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL OpenEventW(SET dwDesiredAccess, INTEGER bInheritHandle, WinApi_PtrWSTR lpName);
#define WinApi_OpenFile(lpFileName, lpReOpenBuff, lpReOpenBuff__typ, uStyle)	OpenFile(lpFileName, lpReOpenBuff, uStyle)
__EXTERN INTEGER __CALL OpenFile(WinApi_PtrSTR lpFileName, WinApi_OFSTRUCT *lpReOpenBuff, SET uStyle);
#define WinApi_OpenFileMapping(dwDesiredAccess, bInheritHandle, lpName)	OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName)
#define WinApi_OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName)	OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL OpenFileMappingA(SET dwDesiredAccess, INTEGER bInheritHandle, WinApi_PtrSTR lpName);
#define WinApi_OpenFileMappingW(dwDesiredAccess, bInheritHandle, lpName)	OpenFileMappingW(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL OpenFileMappingW(SET dwDesiredAccess, INTEGER bInheritHandle, WinApi_PtrWSTR lpName);
#define WinApi_OpenIcon(hWnd)	OpenIcon(hWnd)
__EXTERN INTEGER __CALL OpenIcon(INTEGER hWnd);
#define WinApi_OpenInputDesktop(dwFlags, fInherit, dwDesiredAccess)	OpenInputDesktop(dwFlags, fInherit, dwDesiredAccess)
__EXTERN INTEGER __CALL OpenInputDesktop(SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
#define WinApi_OpenMutex(dwDesiredAccess, bInheritHandle, lpName)	OpenMutexA(dwDesiredAccess, bInheritHandle, lpName)
#define WinApi_OpenMutexA(dwDesiredAccess, bInheritHandle, lpName)	OpenMutexA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL OpenMutexA(SET dwDesiredAccess, INTEGER bInheritHandle, WinApi_PtrSTR lpName);
#define WinApi_OpenMutexW(dwDesiredAccess, bInheritHandle, lpName)	OpenMutexW(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL OpenMutexW(SET dwDesiredAccess, INTEGER bInheritHandle, WinApi_PtrWSTR lpName);
#define WinApi_OpenPrinter(pPrinterName, phPrinter, pDefault, pDefault__typ)	OpenPrinterA(pPrinterName, phPrinter, pDefault)
#define WinApi_OpenPrinterA(pPrinterName, phPrinter, pDefault, pDefault__typ)	OpenPrinterA(pPrinterName, phPrinter, pDefault)
__EXTERN INTEGER __CALL OpenPrinterA(WinApi_PtrSTR pPrinterName, INTEGER *phPrinter, WinApi_PRINTER_DEFAULTSA *pDefault);
#define WinApi_OpenPrinterW(pPrinterName, phPrinter, pDefault, pDefault__typ)	OpenPrinterW(pPrinterName, phPrinter, pDefault)
__EXTERN INTEGER __CALL OpenPrinterW(WinApi_PtrWSTR pPrinterName, INTEGER *phPrinter, WinApi_PRINTER_DEFAULTSW *pDefault);
#define WinApi_OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId)	OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId)
__EXTERN INTEGER __CALL OpenProcess(SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER dwProcessId);
#define WinApi_OpenProcessToken(ProcessHandle, DesiredAccess, TokenHandle)	OpenProcessToken(ProcessHandle, DesiredAccess, TokenHandle)
__EXTERN INTEGER __CALL OpenProcessToken(INTEGER ProcessHandle, SET DesiredAccess, INTEGER *TokenHandle);
#define WinApi_OpenSCManager(lpMachineName, lpDatabaseName, dwDesiredAccess)	OpenSCManagerA(lpMachineName, lpDatabaseName, dwDesiredAccess)
#define WinApi_OpenSCManagerA(lpMachineName, lpDatabaseName, dwDesiredAccess)	OpenSCManagerA(lpMachineName, lpDatabaseName, dwDesiredAccess)
__EXTERN INTEGER __CALL OpenSCManagerA(WinApi_PtrSTR lpMachineName, WinApi_PtrSTR lpDatabaseName, SET dwDesiredAccess);
#define WinApi_OpenSCManagerW(lpMachineName, lpDatabaseName, dwDesiredAccess)	OpenSCManagerW(lpMachineName, lpDatabaseName, dwDesiredAccess)
__EXTERN INTEGER __CALL OpenSCManagerW(WinApi_PtrWSTR lpMachineName, WinApi_PtrWSTR lpDatabaseName, SET dwDesiredAccess);
#define WinApi_OpenSemaphore(dwDesiredAccess, bInheritHandle, lpName)	OpenSemaphoreA(dwDesiredAccess, bInheritHandle, lpName)
#define WinApi_OpenSemaphoreA(dwDesiredAccess, bInheritHandle, lpName)	OpenSemaphoreA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL OpenSemaphoreA(SET dwDesiredAccess, INTEGER bInheritHandle, WinApi_PtrSTR lpName);
#define WinApi_OpenSemaphoreW(dwDesiredAccess, bInheritHandle, lpName)	OpenSemaphoreW(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL OpenSemaphoreW(SET dwDesiredAccess, INTEGER bInheritHandle, WinApi_PtrWSTR lpName);
#define WinApi_OpenService(hSCManager, lpServiceName, dwDesiredAccess)	OpenServiceA(hSCManager, lpServiceName, dwDesiredAccess)
#define WinApi_OpenServiceA(hSCManager, lpServiceName, dwDesiredAccess)	OpenServiceA(hSCManager, lpServiceName, dwDesiredAccess)
__EXTERN INTEGER __CALL OpenServiceA(INTEGER hSCManager, WinApi_PtrSTR lpServiceName, SET dwDesiredAccess);
#define WinApi_OpenServiceW(hSCManager, lpServiceName, dwDesiredAccess)	OpenServiceW(hSCManager, lpServiceName, dwDesiredAccess)
__EXTERN INTEGER __CALL OpenServiceW(INTEGER hSCManager, WinApi_PtrWSTR lpServiceName, SET dwDesiredAccess);
#define WinApi_OpenThreadToken(ThreadHandle, DesiredAccess, OpenAsSelf, TokenHandle)	OpenThreadToken(ThreadHandle, DesiredAccess, OpenAsSelf, TokenHandle)
__EXTERN INTEGER __CALL OpenThreadToken(INTEGER ThreadHandle, SET DesiredAccess, INTEGER OpenAsSelf, INTEGER *TokenHandle);
#define WinApi_OpenWaitableTimer(dwDesiredAccess, bInheritHandle, lpTimerName)	OpenWaitableTimerA(dwDesiredAccess, bInheritHandle, lpTimerName)
#define WinApi_OpenWaitableTimerA(dwDesiredAccess, bInheritHandle, lpTimerName)	OpenWaitableTimerA(dwDesiredAccess, bInheritHandle, lpTimerName)
__EXTERN INTEGER __CALL OpenWaitableTimerA(SET dwDesiredAccess, INTEGER bInheritHandle, WinApi_PtrSTR lpTimerName);
#define WinApi_OpenWaitableTimerW(dwDesiredAccess, bInheritHandle, lpTimerName)	OpenWaitableTimerW(dwDesiredAccess, bInheritHandle, lpTimerName)
__EXTERN INTEGER __CALL OpenWaitableTimerW(SET dwDesiredAccess, INTEGER bInheritHandle, WinApi_PtrWSTR lpTimerName);
#define WinApi_OpenWindowStation(lpszWinSta, fInherit, dwDesiredAccess)	OpenWindowStationA(lpszWinSta, fInherit, dwDesiredAccess)
#define WinApi_OpenWindowStationA(lpszWinSta, fInherit, dwDesiredAccess)	OpenWindowStationA(lpszWinSta, fInherit, dwDesiredAccess)
__EXTERN INTEGER __CALL OpenWindowStationA(WinApi_PtrSTR lpszWinSta, INTEGER fInherit, SET dwDesiredAccess);
#define WinApi_OpenWindowStationW(lpszWinSta, fInherit, dwDesiredAccess)	OpenWindowStationW(lpszWinSta, fInherit, dwDesiredAccess)
__EXTERN INTEGER __CALL OpenWindowStationW(WinApi_PtrWSTR lpszWinSta, INTEGER fInherit, SET dwDesiredAccess);
#define WinApi_OutputDebugString(lpOutputString)	OutputDebugStringA(lpOutputString)
#define WinApi_OutputDebugStringA(lpOutputString)	OutputDebugStringA(lpOutputString)
__EXTERN void __CALL OutputDebugStringA(WinApi_PtrSTR lpOutputString);
#define WinApi_OutputDebugStringW(lpOutputString)	OutputDebugStringW(lpOutputString)
__EXTERN void __CALL OutputDebugStringW(WinApi_PtrWSTR lpOutputString);
#define WinApi_PackDDElParam(msg, uiLo, uiHi)	PackDDElParam(msg, uiLo, uiHi)
__EXTERN INTEGER __CALL PackDDElParam(INTEGER msg, INTEGER uiLo, INTEGER uiHi);
#define WinApi_PaintDesktop(hdc)	PaintDesktop(hdc)
__EXTERN INTEGER __CALL PaintDesktop(INTEGER hdc);
#define WinApi_PaintRgn(p0, p1)	PaintRgn(p0, p1)
__EXTERN INTEGER __CALL PaintRgn(INTEGER p0, INTEGER p1);
#define WinApi_PatBlt(p0, p1, p2, p3, p4, p5)	PatBlt(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL PatBlt(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
#define WinApi_PathToRegion(p0)	PathToRegion(p0)
__EXTERN INTEGER __CALL PathToRegion(INTEGER p0);
#define WinApi_PeekConsoleInput(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsRead)	PeekConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
#define WinApi_PeekConsoleInputA(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsRead)	PeekConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
__EXTERN INTEGER __CALL PeekConsoleInputA(INTEGER hConsoleInput, WinApi_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
#define WinApi_PeekConsoleInputW(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsRead)	PeekConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
__EXTERN INTEGER __CALL PeekConsoleInputW(INTEGER hConsoleInput, WinApi_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
#define WinApi_PeekMessage(lpMsg, lpMsg__typ, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)	PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)
#define WinApi_PeekMessageA(lpMsg, lpMsg__typ, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)	PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)
__EXTERN INTEGER __CALL PeekMessageA(WinApi_MSG *lpMsg, INTEGER hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax, INTEGER wRemoveMsg);
#define WinApi_PeekMessageW(lpMsg, lpMsg__typ, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)	PeekMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)
__EXTERN INTEGER __CALL PeekMessageW(WinApi_MSG *lpMsg, INTEGER hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax, INTEGER wRemoveMsg);
#define WinApi_PeekNamedPipe(hNamedPipe, lpBuffer, nBufferSize, lpBytesRead, lpTotalBytesAvail, lpBytesLeftThisMessage)	PeekNamedPipe(hNamedPipe, lpBuffer, nBufferSize, lpBytesRead, lpTotalBytesAvail, lpBytesLeftThisMessage)
__EXTERN INTEGER __CALL PeekNamedPipe(INTEGER hNamedPipe, INTEGER lpBuffer, INTEGER nBufferSize, INTEGER *lpBytesRead, INTEGER *lpTotalBytesAvail, INTEGER *lpBytesLeftThisMessage);
#define WinApi_Pie(p0, p1, p2, p3, p4, p5, p6, p7, p8)	Pie(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __CALL Pie(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinApi_PlayEnhMetaFile(p0, p1, p2, p2__typ)	PlayEnhMetaFile(p0, p1, p2)
__EXTERN INTEGER __CALL PlayEnhMetaFile(INTEGER p0, INTEGER p1, WinApi_RECT *p2);
#define WinApi_PlayEnhMetaFileRecord(p0, p1, p1__typ, p2, p2__typ, p3)	PlayEnhMetaFileRecord(p0, p1, p2, p3)
__EXTERN INTEGER __CALL PlayEnhMetaFileRecord(INTEGER p0, WinApi_HANDLETABLE *p1, WinApi_ENHMETARECORD *p2, INTEGER p3);
#define WinApi_PlayMetaFile(p0, p1)	PlayMetaFile(p0, p1)
__EXTERN INTEGER __CALL PlayMetaFile(INTEGER p0, INTEGER p1);
#define WinApi_PlayMetaFileRecord(p0, p1, p1__typ, p2, p2__typ, p3)	PlayMetaFileRecord(p0, p1, p2, p3)
__EXTERN INTEGER __CALL PlayMetaFileRecord(INTEGER p0, WinApi_HANDLETABLE *p1, WinApi_METARECORD *p2, INTEGER p3);
#define WinApi_PlgBlt(p0, p1, p1__typ, p2, p3, p4, p5, p6, p7, p8, p9)	PlgBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)
__EXTERN INTEGER __CALL PlgBlt(INTEGER p0, WinApi_POINT *p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9);
#define WinApi_PolyBezier(p0, p1, p1__typ, p2)	PolyBezier(p0, p1, p2)
__EXTERN INTEGER __CALL PolyBezier(INTEGER p0, WinApi_POINT *p1, INTEGER p2);
#define WinApi_PolyBezierTo(p0, p1, p1__typ, p2)	PolyBezierTo(p0, p1, p2)
__EXTERN INTEGER __CALL PolyBezierTo(INTEGER p0, WinApi_POINT *p1, INTEGER p2);
#define WinApi_PolyDraw(p0, p1, p1__typ, p2, p3)	PolyDraw(p0, p1, p2, p3)
__EXTERN INTEGER __CALL PolyDraw(INTEGER p0, WinApi_POINT *p1, CHAR *p2, INTEGER p3);
#define WinApi_PolyPolygon(p0, p1, p1__typ, p2, p3)	PolyPolygon(p0, p1, p2, p3)
__EXTERN INTEGER __CALL PolyPolygon(INTEGER p0, WinApi_POINT *p1, INTEGER *p2, INTEGER p3);
#define WinApi_PolyPolyline(p0, p1, p1__typ, p2, p3)	PolyPolyline(p0, p1, p2, p3)
__EXTERN INTEGER __CALL PolyPolyline(INTEGER p0, WinApi_POINT *p1, INTEGER *p2, INTEGER p3);
#define WinApi_PolyTextOut(p0, p1, p1__typ, p2)	PolyTextOutA(p0, p1, p2)
#define WinApi_PolyTextOutA(p0, p1, p1__typ, p2)	PolyTextOutA(p0, p1, p2)
__EXTERN INTEGER __CALL PolyTextOutA(INTEGER p0, WinApi_POLYTEXTA *p1, INTEGER p2);
#define WinApi_PolyTextOutW(p0, p1, p1__typ, p2)	PolyTextOutW(p0, p1, p2)
__EXTERN INTEGER __CALL PolyTextOutW(INTEGER p0, WinApi_POLYTEXTW *p1, INTEGER p2);
#define WinApi_Polygon(p0, p1, p1__typ, p2)	Polygon(p0, p1, p2)
__EXTERN INTEGER __CALL Polygon(INTEGER p0, WinApi_POINT *p1, INTEGER p2);
#define WinApi_Polyline(p0, p1, p1__typ, p2)	Polyline(p0, p1, p2)
__EXTERN INTEGER __CALL Polyline(INTEGER p0, WinApi_POINT *p1, INTEGER p2);
#define WinApi_PolylineTo(p0, p1, p1__typ, p2)	PolylineTo(p0, p1, p2)
__EXTERN INTEGER __CALL PolylineTo(INTEGER p0, WinApi_POINT *p1, INTEGER p2);
#define WinApi_PostMessage(hWnd, Msg, wParam, lParam)	PostMessageA(hWnd, Msg, wParam, lParam)
#define WinApi_PostMessageA(hWnd, Msg, wParam, lParam)	PostMessageA(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL PostMessageA(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_PostMessageW(hWnd, Msg, wParam, lParam)	PostMessageW(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL PostMessageW(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_PostQueuedCompletionStatus(CompletionPort, dwNumberOfBytesTransferred, dwCompletionKey, lpOverlapped, lpOverlapped__typ)	PostQueuedCompletionStatus(CompletionPort, dwNumberOfBytesTransferred, dwCompletionKey, lpOverlapped)
__EXTERN INTEGER __CALL PostQueuedCompletionStatus(INTEGER CompletionPort, INTEGER dwNumberOfBytesTransferred, INTEGER dwCompletionKey, WinApi_OVERLAPPED *lpOverlapped);
#define WinApi_PostQuitMessage(nExitCode)	PostQuitMessage(nExitCode)
__EXTERN void __CALL PostQuitMessage(INTEGER nExitCode);
#define WinApi_PostThreadMessage(idThread, Msg, wParam, lParam)	PostThreadMessageA(idThread, Msg, wParam, lParam)
#define WinApi_PostThreadMessageA(idThread, Msg, wParam, lParam)	PostThreadMessageA(idThread, Msg, wParam, lParam)
__EXTERN INTEGER __CALL PostThreadMessageA(INTEGER idThread, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_PostThreadMessageW(idThread, Msg, wParam, lParam)	PostThreadMessageW(idThread, Msg, wParam, lParam)
__EXTERN INTEGER __CALL PostThreadMessageW(INTEGER idThread, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_PrepareTape(hDevice, dwOperation, bImmediate)	PrepareTape(hDevice, dwOperation, bImmediate)
__EXTERN INTEGER __CALL PrepareTape(INTEGER hDevice, INTEGER dwOperation, INTEGER bImmediate);
#define WinApi_PrinterMessageBox(hPrinter, Error, hWnd, pText, pCaption, dwType)	PrinterMessageBoxA(hPrinter, Error, hWnd, pText, pCaption, dwType)
#define WinApi_PrinterMessageBoxA(hPrinter, Error, hWnd, pText, pCaption, dwType)	PrinterMessageBoxA(hPrinter, Error, hWnd, pText, pCaption, dwType)
__EXTERN INTEGER __CALL PrinterMessageBoxA(INTEGER hPrinter, INTEGER Error, INTEGER hWnd, WinApi_PtrSTR pText, WinApi_PtrSTR pCaption, INTEGER dwType);
#define WinApi_PrinterMessageBoxW(hPrinter, Error, hWnd, pText, pCaption, dwType)	PrinterMessageBoxW(hPrinter, Error, hWnd, pText, pCaption, dwType)
__EXTERN INTEGER __CALL PrinterMessageBoxW(INTEGER hPrinter, INTEGER Error, INTEGER hWnd, WinApi_PtrWSTR pText, WinApi_PtrWSTR pCaption, INTEGER dwType);
#define WinApi_PrinterProperties(hWnd, hPrinter)	PrinterProperties(hWnd, hPrinter)
__EXTERN INTEGER __CALL PrinterProperties(INTEGER hWnd, INTEGER hPrinter);
#define WinApi_PrivilegeCheck(ClientToken, RequiredPrivileges, RequiredPrivileges__typ, pfResult)	PrivilegeCheck(ClientToken, RequiredPrivileges, pfResult)
__EXTERN INTEGER __CALL PrivilegeCheck(INTEGER ClientToken, WinApi_PRIVILEGE_SET *RequiredPrivileges, INTEGER *pfResult);
#define WinApi_PrivilegedServiceAuditAlarm(SubsystemName, ServiceName, ClientToken, Privileges, Privileges__typ, AccessGranted)	PrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)
#define WinApi_PrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, Privileges__typ, AccessGranted)	PrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)
__EXTERN INTEGER __CALL PrivilegedServiceAuditAlarmA(WinApi_PtrSTR SubsystemName, WinApi_PtrSTR ServiceName, INTEGER ClientToken, WinApi_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
#define WinApi_PrivilegedServiceAuditAlarmW(SubsystemName, ServiceName, ClientToken, Privileges, Privileges__typ, AccessGranted)	PrivilegedServiceAuditAlarmW(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)
__EXTERN INTEGER __CALL PrivilegedServiceAuditAlarmW(WinApi_PtrWSTR SubsystemName, WinApi_PtrWSTR ServiceName, INTEGER ClientToken, WinApi_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
#define WinApi_PropertySheet(p0, p0__typ)	PropertySheetA(p0)
#define WinApi_PropertySheetA(p0, p0__typ)	PropertySheetA(p0)
__EXTERN INTEGER __CALL PropertySheetA(WinApi_PROPSHEETHEADERA *p0);
#define WinApi_PropertySheetW(p0, p0__typ)	PropertySheetW(p0)
__EXTERN INTEGER __CALL PropertySheetW(WinApi_PROPSHEETHEADERW *p0);
#define WinApi_PtInRect(lprc, lprc__typ, pt)	PtInRect(lprc, pt)
__EXTERN INTEGER __CALL PtInRect(WinApi_RECT *lprc, WinApi_POINT pt);
#define WinApi_PtInRegion(p0, p1, p2)	PtInRegion(p0, p1, p2)
__EXTERN INTEGER __CALL PtInRegion(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_PtVisible(p0, p1, p2)	PtVisible(p0, p1, p2)
__EXTERN INTEGER __CALL PtVisible(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_PulseEvent(hEvent)	PulseEvent(hEvent)
__EXTERN INTEGER __CALL PulseEvent(INTEGER hEvent);
#define WinApi_PurgeComm(hFile, dwFlags)	PurgeComm(hFile, dwFlags)
__EXTERN INTEGER __CALL PurgeComm(INTEGER hFile, SET dwFlags);
#define WinApi_QueryDosDevice(lpDeviceName, lpTargetPath, ucchMax)	QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax)
#define WinApi_QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax)	QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax)
__EXTERN INTEGER __CALL QueryDosDeviceA(WinApi_PtrSTR lpDeviceName, WinApi_PtrSTR lpTargetPath, INTEGER ucchMax);
#define WinApi_QueryDosDeviceW(lpDeviceName, lpTargetPath, ucchMax)	QueryDosDeviceW(lpDeviceName, lpTargetPath, ucchMax)
__EXTERN INTEGER __CALL QueryDosDeviceW(WinApi_PtrWSTR lpDeviceName, WinApi_PtrWSTR lpTargetPath, INTEGER ucchMax);
#define WinApi_QueryPerformanceCounter(lpPerformanceCount)	QueryPerformanceCounter(lpPerformanceCount)
__EXTERN INTEGER __CALL QueryPerformanceCounter(LONGINT *lpPerformanceCount);
#define WinApi_QueryPerformanceFrequency(lpFrequency)	QueryPerformanceFrequency(lpFrequency)
__EXTERN INTEGER __CALL QueryPerformanceFrequency(LONGINT *lpFrequency);
#define WinApi_QueryServiceConfig(hService, lpServiceConfig, lpServiceConfig__typ, cbBufSize, pcbBytesNeeded)	QueryServiceConfigA(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)
#define WinApi_QueryServiceConfigA(hService, lpServiceConfig, lpServiceConfig__typ, cbBufSize, pcbBytesNeeded)	QueryServiceConfigA(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __CALL QueryServiceConfigA(INTEGER hService, WinApi_QUERY_SERVICE_CONFIGA *lpServiceConfig, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinApi_QueryServiceConfigW(hService, lpServiceConfig, lpServiceConfig__typ, cbBufSize, pcbBytesNeeded)	QueryServiceConfigW(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __CALL QueryServiceConfigW(INTEGER hService, WinApi_QUERY_SERVICE_CONFIGW *lpServiceConfig, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinApi_QueryServiceLockStatus(hSCManager, lpLockStatus, lpLockStatus__typ, cbBufSize, pcbBytesNeeded)	QueryServiceLockStatusA(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)
#define WinApi_QueryServiceLockStatusA(hSCManager, lpLockStatus, lpLockStatus__typ, cbBufSize, pcbBytesNeeded)	QueryServiceLockStatusA(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __CALL QueryServiceLockStatusA(INTEGER hSCManager, WinApi_QUERY_SERVICE_LOCK_STATUSA *lpLockStatus, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinApi_QueryServiceLockStatusW(hSCManager, lpLockStatus, lpLockStatus__typ, cbBufSize, pcbBytesNeeded)	QueryServiceLockStatusW(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __CALL QueryServiceLockStatusW(INTEGER hSCManager, WinApi_QUERY_SERVICE_LOCK_STATUSW *lpLockStatus, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinApi_QueryServiceObjectSecurity(hService, dwSecurityInformation, lpSecurityDescriptor, cbBufSize, pcbBytesNeeded)	QueryServiceObjectSecurity(hService, dwSecurityInformation, lpSecurityDescriptor, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __CALL QueryServiceObjectSecurity(INTEGER hService, SET dwSecurityInformation, INTEGER lpSecurityDescriptor, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinApi_QueryServiceStatus(hService, lpServiceStatus, lpServiceStatus__typ)	QueryServiceStatus(hService, lpServiceStatus)
__EXTERN INTEGER __CALL QueryServiceStatus(INTEGER hService, WinApi_SERVICE_STATUS *lpServiceStatus);
#define WinApi_QueueUserAPC(pfnAPC, hThread, dwData)	QueueUserAPC(pfnAPC, hThread, dwData)
__EXTERN INTEGER __CALL QueueUserAPC(WinApi_APCFUNC pfnAPC, INTEGER hThread, INTEGER dwData);
#define WinApi_RaiseException(dwExceptionCode, dwExceptionFlags, nNumberOfArguments, lpArguments)	RaiseException(dwExceptionCode, dwExceptionFlags, nNumberOfArguments, lpArguments)
__EXTERN void __CALL RaiseException(INTEGER dwExceptionCode, INTEGER dwExceptionFlags, INTEGER nNumberOfArguments, INTEGER *lpArguments);
#define WinApi_ReadConsole(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)	ReadConsoleA(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)
#define WinApi_ReadConsoleA(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)	ReadConsoleA(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)
__EXTERN INTEGER __CALL ReadConsoleA(INTEGER hConsoleInput, INTEGER lpBuffer, INTEGER nNumberOfCharsToRead, INTEGER *lpNumberOfCharsRead, INTEGER lpReserved);
#define WinApi_ReadConsoleInput(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsRead)	ReadConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
#define WinApi_ReadConsoleInputA(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsRead)	ReadConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
__EXTERN INTEGER __CALL ReadConsoleInputA(INTEGER hConsoleInput, WinApi_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
#define WinApi_ReadConsoleInputW(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsRead)	ReadConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
__EXTERN INTEGER __CALL ReadConsoleInputW(INTEGER hConsoleInput, WinApi_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
#define WinApi_ReadConsoleOutput(hConsoleOutput, lpBuffer, lpBuffer__typ, dwBufferSize, dwBufferCoord, lpReadRegion, lpReadRegion__typ)	ReadConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)
#define WinApi_ReadConsoleOutputA(hConsoleOutput, lpBuffer, lpBuffer__typ, dwBufferSize, dwBufferCoord, lpReadRegion, lpReadRegion__typ)	ReadConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)
__EXTERN INTEGER __CALL ReadConsoleOutputA(INTEGER hConsoleOutput, WinApi_CHAR_INFO *lpBuffer, WinApi_COORD dwBufferSize, WinApi_COORD dwBufferCoord, WinApi_SMALL_RECT *lpReadRegion);
#define WinApi_ReadConsoleOutputAttribute(hConsoleOutput, lpAttribute, nLength, dwReadCoord, lpNumberOfAttrsRead)	ReadConsoleOutputAttribute(hConsoleOutput, lpAttribute, nLength, dwReadCoord, lpNumberOfAttrsRead)
__EXTERN INTEGER __CALL ReadConsoleOutputAttribute(INTEGER hConsoleOutput, SHORTINT *lpAttribute, INTEGER nLength, WinApi_COORD dwReadCoord, INTEGER *lpNumberOfAttrsRead);
#define WinApi_ReadConsoleOutputCharacter(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)	ReadConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)
#define WinApi_ReadConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)	ReadConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)
__EXTERN INTEGER __CALL ReadConsoleOutputCharacterA(INTEGER hConsoleOutput, WinApi_PtrSTR lpCharacter, INTEGER nLength, WinApi_COORD dwReadCoord, INTEGER *lpNumberOfCharsRead);
#define WinApi_ReadConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)	ReadConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)
__EXTERN INTEGER __CALL ReadConsoleOutputCharacterW(INTEGER hConsoleOutput, WinApi_PtrWSTR lpCharacter, INTEGER nLength, WinApi_COORD dwReadCoord, INTEGER *lpNumberOfCharsRead);
#define WinApi_ReadConsoleOutputW(hConsoleOutput, lpBuffer, lpBuffer__typ, dwBufferSize, dwBufferCoord, lpReadRegion, lpReadRegion__typ)	ReadConsoleOutputW(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)
__EXTERN INTEGER __CALL ReadConsoleOutputW(INTEGER hConsoleOutput, WinApi_CHAR_INFO *lpBuffer, WinApi_COORD dwBufferSize, WinApi_COORD dwBufferCoord, WinApi_SMALL_RECT *lpReadRegion);
#define WinApi_ReadConsoleW(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)	ReadConsoleW(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)
__EXTERN INTEGER __CALL ReadConsoleW(INTEGER hConsoleInput, INTEGER lpBuffer, INTEGER nNumberOfCharsToRead, INTEGER *lpNumberOfCharsRead, INTEGER lpReserved);
#define WinApi_ReadDirectoryChangesW(hDirectory, lpBuffer, nBufferLength, bWatchSubtree, dwNotifyFilter, lpBytesReturned, lpOverlapped, lpOverlapped__typ, lpCompletionRoutine)	ReadDirectoryChangesW(hDirectory, lpBuffer, nBufferLength, bWatchSubtree, dwNotifyFilter, lpBytesReturned, lpOverlapped, lpCompletionRoutine)
__EXTERN INTEGER __CALL ReadDirectoryChangesW(INTEGER hDirectory, INTEGER lpBuffer, INTEGER nBufferLength, INTEGER bWatchSubtree, SET dwNotifyFilter, INTEGER *lpBytesReturned, WinApi_OVERLAPPED *lpOverlapped, WinApi_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinApi_ReadEventLog(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)	ReadEventLogA(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)
#define WinApi_ReadEventLogA(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)	ReadEventLogA(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)
__EXTERN INTEGER __CALL ReadEventLogA(INTEGER hEventLog, SET dwReadFlags, INTEGER dwRecordOffset, INTEGER lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *pnBytesRead, INTEGER *pnMinNumberOfBytesNeeded);
#define WinApi_ReadEventLogW(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)	ReadEventLogW(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)
__EXTERN INTEGER __CALL ReadEventLogW(INTEGER hEventLog, SET dwReadFlags, INTEGER dwRecordOffset, INTEGER lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *pnBytesRead, INTEGER *pnMinNumberOfBytesNeeded);
#define WinApi_ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped, lpOverlapped__typ)	ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped)
__EXTERN INTEGER __CALL ReadFile(INTEGER hFile, INTEGER lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *lpNumberOfBytesRead, WinApi_OVERLAPPED *lpOverlapped);
#define WinApi_ReadFileEx(hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpOverlapped__typ, lpCompletionRoutine)	ReadFileEx(hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine)
__EXTERN INTEGER __CALL ReadFileEx(INTEGER hFile, INTEGER lpBuffer, INTEGER nNumberOfBytesToRead, WinApi_OVERLAPPED *lpOverlapped, WinApi_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinApi_ReadPrinter(hPrinter, pBuf, cbBuf, pNoBytesRead)	ReadPrinter(hPrinter, pBuf, cbBuf, pNoBytesRead)
__EXTERN INTEGER __CALL ReadPrinter(INTEGER hPrinter, INTEGER pBuf, INTEGER cbBuf, INTEGER *pNoBytesRead);
#define WinApi_ReadProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead)	ReadProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead)
__EXTERN INTEGER __CALL ReadProcessMemory(INTEGER hProcess, INTEGER lpBaseAddress, INTEGER lpBuffer, INTEGER nSize, INTEGER *lpNumberOfBytesRead);
#define WinApi_RealizePalette(p0)	RealizePalette(p0)
__EXTERN INTEGER __CALL RealizePalette(INTEGER p0);
#define WinApi_RectInRegion(p0, p1, p1__typ)	RectInRegion(p0, p1)
__EXTERN INTEGER __CALL RectInRegion(INTEGER p0, WinApi_RECT *p1);
#define WinApi_RectVisible(p0, p1, p1__typ)	RectVisible(p0, p1)
__EXTERN INTEGER __CALL RectVisible(INTEGER p0, WinApi_RECT *p1);
#define WinApi_Rectangle(p0, p1, p2, p3, p4)	Rectangle(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL Rectangle(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_RedrawWindow(hWnd, lprcUpdate, lprcUpdate__typ, hrgnUpdate, flags)	RedrawWindow(hWnd, lprcUpdate, hrgnUpdate, flags)
__EXTERN INTEGER __CALL RedrawWindow(INTEGER hWnd, WinApi_RECT *lprcUpdate, INTEGER hrgnUpdate, SET flags);
#define WinApi_RegCloseKey(hKey)	RegCloseKey(hKey)
__EXTERN INTEGER __CALL RegCloseKey(INTEGER hKey);
#define WinApi_RegConnectRegistry(lpMachineName, hKey, phkResult)	RegConnectRegistryA(lpMachineName, hKey, phkResult)
#define WinApi_RegConnectRegistryA(lpMachineName, hKey, phkResult)	RegConnectRegistryA(lpMachineName, hKey, phkResult)
__EXTERN INTEGER __CALL RegConnectRegistryA(WinApi_PtrSTR lpMachineName, INTEGER hKey, INTEGER *phkResult);
#define WinApi_RegConnectRegistryW(lpMachineName, hKey, phkResult)	RegConnectRegistryW(lpMachineName, hKey, phkResult)
__EXTERN INTEGER __CALL RegConnectRegistryW(WinApi_PtrWSTR lpMachineName, INTEGER hKey, INTEGER *phkResult);
#define WinApi_RegCreateKey(hKey, lpSubKey, phkResult)	RegCreateKeyA(hKey, lpSubKey, phkResult)
#define WinApi_RegCreateKeyA(hKey, lpSubKey, phkResult)	RegCreateKeyA(hKey, lpSubKey, phkResult)
__EXTERN INTEGER __CALL RegCreateKeyA(INTEGER hKey, WinApi_PtrSTR lpSubKey, INTEGER *phkResult);
#define WinApi_RegCreateKeyEx(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, lpSecurityAttributes__typ, phkResult, lpdwDisposition)	RegCreateKeyExA(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)
#define WinApi_RegCreateKeyExA(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, lpSecurityAttributes__typ, phkResult, lpdwDisposition)	RegCreateKeyExA(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)
__EXTERN INTEGER __CALL RegCreateKeyExA(INTEGER hKey, WinApi_PtrSTR lpSubKey, INTEGER Reserved, WinApi_PtrSTR lpClass, SET dwOptions, SET samDesired, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER *phkResult, INTEGER *lpdwDisposition);
#define WinApi_RegCreateKeyExW(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, lpSecurityAttributes__typ, phkResult, lpdwDisposition)	RegCreateKeyExW(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)
__EXTERN INTEGER __CALL RegCreateKeyExW(INTEGER hKey, WinApi_PtrWSTR lpSubKey, INTEGER Reserved, WinApi_PtrWSTR lpClass, SET dwOptions, SET samDesired, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER *phkResult, INTEGER *lpdwDisposition);
#define WinApi_RegCreateKeyW(hKey, lpSubKey, phkResult)	RegCreateKeyW(hKey, lpSubKey, phkResult)
__EXTERN INTEGER __CALL RegCreateKeyW(INTEGER hKey, WinApi_PtrWSTR lpSubKey, INTEGER *phkResult);
#define WinApi_RegDeleteKey(hKey, lpSubKey)	RegDeleteKeyA(hKey, lpSubKey)
#define WinApi_RegDeleteKeyA(hKey, lpSubKey)	RegDeleteKeyA(hKey, lpSubKey)
__EXTERN INTEGER __CALL RegDeleteKeyA(INTEGER hKey, WinApi_PtrSTR lpSubKey);
#define WinApi_RegDeleteKeyW(hKey, lpSubKey)	RegDeleteKeyW(hKey, lpSubKey)
__EXTERN INTEGER __CALL RegDeleteKeyW(INTEGER hKey, WinApi_PtrWSTR lpSubKey);
#define WinApi_RegDeleteValue(hKey, lpValueName)	RegDeleteValueA(hKey, lpValueName)
#define WinApi_RegDeleteValueA(hKey, lpValueName)	RegDeleteValueA(hKey, lpValueName)
__EXTERN INTEGER __CALL RegDeleteValueA(INTEGER hKey, WinApi_PtrSTR lpValueName);
#define WinApi_RegDeleteValueW(hKey, lpValueName)	RegDeleteValueW(hKey, lpValueName)
__EXTERN INTEGER __CALL RegDeleteValueW(INTEGER hKey, WinApi_PtrWSTR lpValueName);
#define WinApi_RegEnumKey(hKey, dwIndex, lpName, cbName)	RegEnumKeyA(hKey, dwIndex, lpName, cbName)
#define WinApi_RegEnumKeyA(hKey, dwIndex, lpName, cbName)	RegEnumKeyA(hKey, dwIndex, lpName, cbName)
__EXTERN INTEGER __CALL RegEnumKeyA(INTEGER hKey, INTEGER dwIndex, WinApi_PtrSTR lpName, INTEGER cbName);
#define WinApi_RegEnumKeyEx(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime, lpftLastWriteTime__typ)	RegEnumKeyExA(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)
#define WinApi_RegEnumKeyExA(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime, lpftLastWriteTime__typ)	RegEnumKeyExA(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)
__EXTERN INTEGER __CALL RegEnumKeyExA(INTEGER hKey, INTEGER dwIndex, WinApi_PtrSTR lpName, INTEGER *lpcbName, INTEGER *lpReserved, WinApi_PtrSTR lpClass, INTEGER *lpcbClass, WinApi_FILETIME *lpftLastWriteTime);
#define WinApi_RegEnumKeyExW(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime, lpftLastWriteTime__typ)	RegEnumKeyExW(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)
__EXTERN INTEGER __CALL RegEnumKeyExW(INTEGER hKey, INTEGER dwIndex, WinApi_PtrWSTR lpName, INTEGER *lpcbName, INTEGER *lpReserved, WinApi_PtrWSTR lpClass, INTEGER *lpcbClass, WinApi_FILETIME *lpftLastWriteTime);
#define WinApi_RegEnumKeyW(hKey, dwIndex, lpName, cbName)	RegEnumKeyW(hKey, dwIndex, lpName, cbName)
__EXTERN INTEGER __CALL RegEnumKeyW(INTEGER hKey, INTEGER dwIndex, WinApi_PtrWSTR lpName, INTEGER cbName);
#define WinApi_RegEnumValue(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)	RegEnumValueA(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)
#define WinApi_RegEnumValueA(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)	RegEnumValueA(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __CALL RegEnumValueA(INTEGER hKey, INTEGER dwIndex, WinApi_PtrSTR lpValueName, INTEGER *lpcbValueName, INTEGER *lpReserved, INTEGER *lpType, INTEGER lpData, INTEGER *lpcbData);
#define WinApi_RegEnumValueW(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)	RegEnumValueW(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __CALL RegEnumValueW(INTEGER hKey, INTEGER dwIndex, WinApi_PtrWSTR lpValueName, INTEGER *lpcbValueName, INTEGER *lpReserved, INTEGER *lpType, INTEGER lpData, INTEGER *lpcbData);
#define WinApi_RegFlushKey(hKey)	RegFlushKey(hKey)
__EXTERN INTEGER __CALL RegFlushKey(INTEGER hKey);
#define WinApi_RegGetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor, lpcbSecurityDescriptor)	RegGetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor, lpcbSecurityDescriptor)
__EXTERN INTEGER __CALL RegGetKeySecurity(INTEGER hKey, SET SecurityInformation, INTEGER pSecurityDescriptor, INTEGER *lpcbSecurityDescriptor);
#define WinApi_RegLoadKey(hKey, lpSubKey, lpFile)	RegLoadKeyA(hKey, lpSubKey, lpFile)
#define WinApi_RegLoadKeyA(hKey, lpSubKey, lpFile)	RegLoadKeyA(hKey, lpSubKey, lpFile)
__EXTERN INTEGER __CALL RegLoadKeyA(INTEGER hKey, WinApi_PtrSTR lpSubKey, WinApi_PtrSTR lpFile);
#define WinApi_RegLoadKeyW(hKey, lpSubKey, lpFile)	RegLoadKeyW(hKey, lpSubKey, lpFile)
__EXTERN INTEGER __CALL RegLoadKeyW(INTEGER hKey, WinApi_PtrWSTR lpSubKey, WinApi_PtrWSTR lpFile);
#define WinApi_RegNotifyChangeKeyValue(hKey, bWatchSubtree, dwNotifyFilter, hEvent, fAsynchronus)	RegNotifyChangeKeyValue(hKey, bWatchSubtree, dwNotifyFilter, hEvent, fAsynchronus)
__EXTERN INTEGER __CALL RegNotifyChangeKeyValue(INTEGER hKey, INTEGER bWatchSubtree, SET dwNotifyFilter, INTEGER hEvent, INTEGER fAsynchronus);
#define WinApi_RegOpenKey(hKey, lpSubKey, phkResult)	RegOpenKeyA(hKey, lpSubKey, phkResult)
#define WinApi_RegOpenKeyA(hKey, lpSubKey, phkResult)	RegOpenKeyA(hKey, lpSubKey, phkResult)
__EXTERN INTEGER __CALL RegOpenKeyA(INTEGER hKey, WinApi_PtrSTR lpSubKey, INTEGER *phkResult);
#define WinApi_RegOpenKeyEx(hKey, lpSubKey, ulOptions, samDesired, phkResult)	RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult)
#define WinApi_RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult)	RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult)
__EXTERN INTEGER __CALL RegOpenKeyExA(INTEGER hKey, WinApi_PtrSTR lpSubKey, INTEGER ulOptions, SET samDesired, INTEGER *phkResult);
#define WinApi_RegOpenKeyExW(hKey, lpSubKey, ulOptions, samDesired, phkResult)	RegOpenKeyExW(hKey, lpSubKey, ulOptions, samDesired, phkResult)
__EXTERN INTEGER __CALL RegOpenKeyExW(INTEGER hKey, WinApi_PtrWSTR lpSubKey, INTEGER ulOptions, SET samDesired, INTEGER *phkResult);
#define WinApi_RegOpenKeyW(hKey, lpSubKey, phkResult)	RegOpenKeyW(hKey, lpSubKey, phkResult)
__EXTERN INTEGER __CALL RegOpenKeyW(INTEGER hKey, WinApi_PtrWSTR lpSubKey, INTEGER *phkResult);
#define WinApi_RegQueryInfoKey(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime, lpftLastWriteTime__typ)	RegQueryInfoKeyA(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)
#define WinApi_RegQueryInfoKeyA(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime, lpftLastWriteTime__typ)	RegQueryInfoKeyA(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)
__EXTERN INTEGER __CALL RegQueryInfoKeyA(INTEGER hKey, WinApi_PtrSTR lpClass, INTEGER *lpcbClass, INTEGER *lpReserved, INTEGER *lpcSubKeys, INTEGER *lpcbMaxSubKeyLen, INTEGER *lpcbMaxClassLen, INTEGER *lpcValues, INTEGER *lpcbMaxValueNameLen, INTEGER *lpcbMaxValueLen, INTEGER *lpcbSecurityDescriptor, WinApi_FILETIME *lpftLastWriteTime);
#define WinApi_RegQueryInfoKeyW(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime, lpftLastWriteTime__typ)	RegQueryInfoKeyW(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)
__EXTERN INTEGER __CALL RegQueryInfoKeyW(INTEGER hKey, WinApi_PtrWSTR lpClass, INTEGER *lpcbClass, INTEGER *lpReserved, INTEGER *lpcSubKeys, INTEGER *lpcbMaxSubKeyLen, INTEGER *lpcbMaxClassLen, INTEGER *lpcValues, INTEGER *lpcbMaxValueNameLen, INTEGER *lpcbMaxValueLen, INTEGER *lpcbSecurityDescriptor, WinApi_FILETIME *lpftLastWriteTime);
#define WinApi_RegQueryMultipleValues(hKey, val_list, val_list__typ, num_vals, lpValueBuf, ldwTotsize)	RegQueryMultipleValuesA(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)
#define WinApi_RegQueryMultipleValuesA(hKey, val_list, val_list__typ, num_vals, lpValueBuf, ldwTotsize)	RegQueryMultipleValuesA(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)
__EXTERN INTEGER __CALL RegQueryMultipleValuesA(INTEGER hKey, WinApi_VALENTA *val_list, INTEGER num_vals, WinApi_PtrSTR lpValueBuf, INTEGER *ldwTotsize);
#define WinApi_RegQueryMultipleValuesW(hKey, val_list, val_list__typ, num_vals, lpValueBuf, ldwTotsize)	RegQueryMultipleValuesW(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)
__EXTERN INTEGER __CALL RegQueryMultipleValuesW(INTEGER hKey, WinApi_VALENTW *val_list, INTEGER num_vals, WinApi_PtrWSTR lpValueBuf, INTEGER *ldwTotsize);
#define WinApi_RegQueryValue(hKey, lpSubKey, lpValue, lpcbValue)	RegQueryValueA(hKey, lpSubKey, lpValue, lpcbValue)
#define WinApi_RegQueryValueA(hKey, lpSubKey, lpValue, lpcbValue)	RegQueryValueA(hKey, lpSubKey, lpValue, lpcbValue)
__EXTERN INTEGER __CALL RegQueryValueA(INTEGER hKey, WinApi_PtrSTR lpSubKey, WinApi_PtrSTR lpValue, INTEGER *lpcbValue);
#define WinApi_RegQueryValueEx(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)	RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)
#define WinApi_RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)	RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __CALL RegQueryValueExA(INTEGER hKey, WinApi_PtrSTR lpValueName, INTEGER *lpReserved, INTEGER *lpType, INTEGER lpData, INTEGER *lpcbData);
#define WinApi_RegQueryValueExW(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)	RegQueryValueExW(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __CALL RegQueryValueExW(INTEGER hKey, WinApi_PtrWSTR lpValueName, INTEGER *lpReserved, INTEGER *lpType, INTEGER lpData, INTEGER *lpcbData);
#define WinApi_RegQueryValueW(hKey, lpSubKey, lpValue, lpcbValue)	RegQueryValueW(hKey, lpSubKey, lpValue, lpcbValue)
__EXTERN INTEGER __CALL RegQueryValueW(INTEGER hKey, WinApi_PtrWSTR lpSubKey, WinApi_PtrWSTR lpValue, INTEGER *lpcbValue);
#define WinApi_RegReplaceKey(hKey, lpSubKey, lpNewFile, lpOldFile)	RegReplaceKeyA(hKey, lpSubKey, lpNewFile, lpOldFile)
#define WinApi_RegReplaceKeyA(hKey, lpSubKey, lpNewFile, lpOldFile)	RegReplaceKeyA(hKey, lpSubKey, lpNewFile, lpOldFile)
__EXTERN INTEGER __CALL RegReplaceKeyA(INTEGER hKey, WinApi_PtrSTR lpSubKey, WinApi_PtrSTR lpNewFile, WinApi_PtrSTR lpOldFile);
#define WinApi_RegReplaceKeyW(hKey, lpSubKey, lpNewFile, lpOldFile)	RegReplaceKeyW(hKey, lpSubKey, lpNewFile, lpOldFile)
__EXTERN INTEGER __CALL RegReplaceKeyW(INTEGER hKey, WinApi_PtrWSTR lpSubKey, WinApi_PtrWSTR lpNewFile, WinApi_PtrWSTR lpOldFile);
#define WinApi_RegRestoreKey(hKey, lpFile, dwFlags)	RegRestoreKeyA(hKey, lpFile, dwFlags)
#define WinApi_RegRestoreKeyA(hKey, lpFile, dwFlags)	RegRestoreKeyA(hKey, lpFile, dwFlags)
__EXTERN INTEGER __CALL RegRestoreKeyA(INTEGER hKey, WinApi_PtrSTR lpFile, SET dwFlags);
#define WinApi_RegRestoreKeyW(hKey, lpFile, dwFlags)	RegRestoreKeyW(hKey, lpFile, dwFlags)
__EXTERN INTEGER __CALL RegRestoreKeyW(INTEGER hKey, WinApi_PtrWSTR lpFile, SET dwFlags);
#define WinApi_RegSaveKey(hKey, lpFile, lpSecurityAttributes, lpSecurityAttributes__typ)	RegSaveKeyA(hKey, lpFile, lpSecurityAttributes)
#define WinApi_RegSaveKeyA(hKey, lpFile, lpSecurityAttributes, lpSecurityAttributes__typ)	RegSaveKeyA(hKey, lpFile, lpSecurityAttributes)
__EXTERN INTEGER __CALL RegSaveKeyA(INTEGER hKey, WinApi_PtrSTR lpFile, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinApi_RegSaveKeyW(hKey, lpFile, lpSecurityAttributes, lpSecurityAttributes__typ)	RegSaveKeyW(hKey, lpFile, lpSecurityAttributes)
__EXTERN INTEGER __CALL RegSaveKeyW(INTEGER hKey, WinApi_PtrWSTR lpFile, WinApi_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinApi_RegSetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor)	RegSetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor)
__EXTERN INTEGER __CALL RegSetKeySecurity(INTEGER hKey, SET SecurityInformation, INTEGER pSecurityDescriptor);
#define WinApi_RegSetValue(hKey, lpSubKey, dwType, lpData, cbData)	RegSetValueA(hKey, lpSubKey, dwType, lpData, cbData)
#define WinApi_RegSetValueA(hKey, lpSubKey, dwType, lpData, cbData)	RegSetValueA(hKey, lpSubKey, dwType, lpData, cbData)
__EXTERN INTEGER __CALL RegSetValueA(INTEGER hKey, WinApi_PtrSTR lpSubKey, INTEGER dwType, WinApi_PtrSTR lpData, INTEGER cbData);
#define WinApi_RegSetValueEx(hKey, lpValueName, Reserved, dwType, lpData, cbData)	RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData)
#define WinApi_RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData)	RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData)
__EXTERN INTEGER __CALL RegSetValueExA(INTEGER hKey, WinApi_PtrSTR lpValueName, INTEGER Reserved, INTEGER dwType, INTEGER lpData, INTEGER cbData);
#define WinApi_RegSetValueExW(hKey, lpValueName, Reserved, dwType, lpData, cbData)	RegSetValueExW(hKey, lpValueName, Reserved, dwType, lpData, cbData)
__EXTERN INTEGER __CALL RegSetValueExW(INTEGER hKey, WinApi_PtrWSTR lpValueName, INTEGER Reserved, INTEGER dwType, INTEGER lpData, INTEGER cbData);
#define WinApi_RegSetValueW(hKey, lpSubKey, dwType, lpData, cbData)	RegSetValueW(hKey, lpSubKey, dwType, lpData, cbData)
__EXTERN INTEGER __CALL RegSetValueW(INTEGER hKey, WinApi_PtrWSTR lpSubKey, INTEGER dwType, WinApi_PtrWSTR lpData, INTEGER cbData);
#define WinApi_RegUnLoadKey(hKey, lpSubKey)	RegUnLoadKeyA(hKey, lpSubKey)
#define WinApi_RegUnLoadKeyA(hKey, lpSubKey)	RegUnLoadKeyA(hKey, lpSubKey)
__EXTERN INTEGER __CALL RegUnLoadKeyA(INTEGER hKey, WinApi_PtrSTR lpSubKey);
#define WinApi_RegUnLoadKeyW(hKey, lpSubKey)	RegUnLoadKeyW(hKey, lpSubKey)
__EXTERN INTEGER __CALL RegUnLoadKeyW(INTEGER hKey, WinApi_PtrWSTR lpSubKey);
#define WinApi_RegisterClass(lpWndClass, lpWndClass__typ)	RegisterClassA(lpWndClass)
#define WinApi_RegisterClassA(lpWndClass, lpWndClass__typ)	RegisterClassA(lpWndClass)
__EXTERN SHORTINT __CALL RegisterClassA(WinApi_WNDCLASSA *lpWndClass);
#define WinApi_RegisterClassEx(p0, p0__typ)	RegisterClassExA(p0)
#define WinApi_RegisterClassExA(p0, p0__typ)	RegisterClassExA(p0)
__EXTERN SHORTINT __CALL RegisterClassExA(WinApi_WNDCLASSEXA *p0);
#define WinApi_RegisterClassExW(p0, p0__typ)	RegisterClassExW(p0)
__EXTERN SHORTINT __CALL RegisterClassExW(WinApi_WNDCLASSEXW *p0);
#define WinApi_RegisterClassW(lpWndClass, lpWndClass__typ)	RegisterClassW(lpWndClass)
__EXTERN SHORTINT __CALL RegisterClassW(WinApi_WNDCLASSW *lpWndClass);
#define WinApi_RegisterClipboardFormat(lpszFormat)	RegisterClipboardFormatA(lpszFormat)
#define WinApi_RegisterClipboardFormatA(lpszFormat)	RegisterClipboardFormatA(lpszFormat)
__EXTERN INTEGER __CALL RegisterClipboardFormatA(WinApi_PtrSTR lpszFormat);
#define WinApi_RegisterClipboardFormatW(lpszFormat)	RegisterClipboardFormatW(lpszFormat)
__EXTERN INTEGER __CALL RegisterClipboardFormatW(WinApi_PtrWSTR lpszFormat);
#define WinApi_RegisterEventSource(lpUNCServerName, lpSourceName)	RegisterEventSourceA(lpUNCServerName, lpSourceName)
#define WinApi_RegisterEventSourceA(lpUNCServerName, lpSourceName)	RegisterEventSourceA(lpUNCServerName, lpSourceName)
__EXTERN INTEGER __CALL RegisterEventSourceA(WinApi_PtrSTR lpUNCServerName, WinApi_PtrSTR lpSourceName);
#define WinApi_RegisterEventSourceW(lpUNCServerName, lpSourceName)	RegisterEventSourceW(lpUNCServerName, lpSourceName)
__EXTERN INTEGER __CALL RegisterEventSourceW(WinApi_PtrWSTR lpUNCServerName, WinApi_PtrWSTR lpSourceName);
#define WinApi_RegisterHotKey(hWnd, id, fsModifiers, vk)	RegisterHotKey(hWnd, id, fsModifiers, vk)
__EXTERN INTEGER __CALL RegisterHotKey(INTEGER hWnd, INTEGER id, INTEGER fsModifiers, INTEGER vk);
#define WinApi_RegisterServiceCtrlHandler(lpServiceName, lpHandlerProc)	RegisterServiceCtrlHandlerA(lpServiceName, lpHandlerProc)
#define WinApi_RegisterServiceCtrlHandlerA(lpServiceName, lpHandlerProc)	RegisterServiceCtrlHandlerA(lpServiceName, lpHandlerProc)
__EXTERN INTEGER __CALL RegisterServiceCtrlHandlerA(WinApi_PtrSTR lpServiceName, WinApi_HANDLER_FUNCTION lpHandlerProc);
#define WinApi_RegisterServiceCtrlHandlerW(lpServiceName, lpHandlerProc)	RegisterServiceCtrlHandlerW(lpServiceName, lpHandlerProc)
__EXTERN INTEGER __CALL RegisterServiceCtrlHandlerW(WinApi_PtrWSTR lpServiceName, WinApi_HANDLER_FUNCTION lpHandlerProc);
#define WinApi_RegisterWindowMessage(lpString)	RegisterWindowMessageA(lpString)
#define WinApi_RegisterWindowMessageA(lpString)	RegisterWindowMessageA(lpString)
__EXTERN INTEGER __CALL RegisterWindowMessageA(WinApi_PtrSTR lpString);
#define WinApi_RegisterWindowMessageW(lpString)	RegisterWindowMessageW(lpString)
__EXTERN INTEGER __CALL RegisterWindowMessageW(WinApi_PtrWSTR lpString);
#define WinApi_ReleaseCapture()	ReleaseCapture()
__EXTERN INTEGER __CALL ReleaseCapture(void);
#define WinApi_ReleaseDC(hWnd, hDC)	ReleaseDC(hWnd, hDC)
__EXTERN INTEGER __CALL ReleaseDC(INTEGER hWnd, INTEGER hDC);
#define WinApi_ReleaseMutex(hMutex)	ReleaseMutex(hMutex)
__EXTERN INTEGER __CALL ReleaseMutex(INTEGER hMutex);
#define WinApi_ReleaseSemaphore(hSemaphore, lReleaseCount, lpPreviousCount)	ReleaseSemaphore(hSemaphore, lReleaseCount, lpPreviousCount)
__EXTERN INTEGER __CALL ReleaseSemaphore(INTEGER hSemaphore, INTEGER lReleaseCount, INTEGER *lpPreviousCount);
#define WinApi_RemoveDirectory(lpPathName)	RemoveDirectoryA(lpPathName)
#define WinApi_RemoveDirectoryA(lpPathName)	RemoveDirectoryA(lpPathName)
__EXTERN INTEGER __CALL RemoveDirectoryA(WinApi_PtrSTR lpPathName);
#define WinApi_RemoveDirectoryW(lpPathName)	RemoveDirectoryW(lpPathName)
__EXTERN INTEGER __CALL RemoveDirectoryW(WinApi_PtrWSTR lpPathName);
#define WinApi_RemoveFontResource(p0)	RemoveFontResourceA(p0)
#define WinApi_RemoveFontResourceA(p0)	RemoveFontResourceA(p0)
__EXTERN INTEGER __CALL RemoveFontResourceA(WinApi_PtrSTR p0);
#define WinApi_RemoveFontResourceW(p0)	RemoveFontResourceW(p0)
__EXTERN INTEGER __CALL RemoveFontResourceW(WinApi_PtrWSTR p0);
#define WinApi_RemoveMenu(hMenu, uPosition, uFlags)	RemoveMenu(hMenu, uPosition, uFlags)
__EXTERN INTEGER __CALL RemoveMenu(INTEGER hMenu, INTEGER uPosition, SET uFlags);
#define WinApi_RemoveProp(hWnd, lpString)	RemovePropA(hWnd, lpString)
#define WinApi_RemovePropA(hWnd, lpString)	RemovePropA(hWnd, lpString)
__EXTERN INTEGER __CALL RemovePropA(INTEGER hWnd, WinApi_PtrSTR lpString);
#define WinApi_RemovePropW(hWnd, lpString)	RemovePropW(hWnd, lpString)
__EXTERN INTEGER __CALL RemovePropW(INTEGER hWnd, WinApi_PtrWSTR lpString);
#define WinApi_ReplyMessage(lResult)	ReplyMessage(lResult)
__EXTERN INTEGER __CALL ReplyMessage(INTEGER lResult);
#define WinApi_ReportEvent(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)	ReportEventA(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)
#define WinApi_ReportEventA(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)	ReportEventA(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)
__EXTERN INTEGER __CALL ReportEventA(INTEGER hEventLog, SHORTINT wType, SHORTINT wCategory, INTEGER dwEventID, INTEGER lpUserSid, SHORTINT wNumStrings, INTEGER dwDataSize, WinApi_PtrSTR *lpStrings, INTEGER lpRawData);
#define WinApi_ReportEventW(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)	ReportEventW(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)
__EXTERN INTEGER __CALL ReportEventW(INTEGER hEventLog, SHORTINT wType, SHORTINT wCategory, INTEGER dwEventID, INTEGER lpUserSid, SHORTINT wNumStrings, INTEGER dwDataSize, struct {
	LONGINT len[1];
	WinApi_PtrWSTR data[1];
} *lpStrings, INTEGER lpRawData);
#define WinApi_ResetDC(p0, p1, p1__typ)	ResetDCA(p0, p1)
#define WinApi_ResetDCA(p0, p1, p1__typ)	ResetDCA(p0, p1)
__EXTERN INTEGER __CALL ResetDCA(INTEGER p0, WinApi_DEVMODEA *p1);
#define WinApi_ResetDCW(p0, p1, p1__typ)	ResetDCW(p0, p1)
__EXTERN INTEGER __CALL ResetDCW(INTEGER p0, WinApi_DEVMODEW *p1);
#define WinApi_ResetEvent(hEvent)	ResetEvent(hEvent)
__EXTERN INTEGER __CALL ResetEvent(INTEGER hEvent);
#define WinApi_ResetPrinter(hPrinter, pDefault, pDefault__typ)	ResetPrinterA(hPrinter, pDefault)
#define WinApi_ResetPrinterA(hPrinter, pDefault, pDefault__typ)	ResetPrinterA(hPrinter, pDefault)
__EXTERN INTEGER __CALL ResetPrinterA(INTEGER hPrinter, WinApi_PRINTER_DEFAULTSA *pDefault);
#define WinApi_ResetPrinterW(hPrinter, pDefault, pDefault__typ)	ResetPrinterW(hPrinter, pDefault)
__EXTERN INTEGER __CALL ResetPrinterW(INTEGER hPrinter, WinApi_PRINTER_DEFAULTSW *pDefault);
#define WinApi_ResizePalette(p0, p1)	ResizePalette(p0, p1)
__EXTERN INTEGER __CALL ResizePalette(INTEGER p0, INTEGER p1);
#define WinApi_RestoreDC(p0, p1)	RestoreDC(p0, p1)
__EXTERN INTEGER __CALL RestoreDC(INTEGER p0, INTEGER p1);
#define WinApi_ResumeThread(hThread)	ResumeThread(hThread)
__EXTERN INTEGER __CALL ResumeThread(INTEGER hThread);
#define WinApi_ReuseDDElParam(lParam, msgIn, msgOut, uiLo, uiHi)	ReuseDDElParam(lParam, msgIn, msgOut, uiLo, uiHi)
__EXTERN INTEGER __CALL ReuseDDElParam(INTEGER lParam, INTEGER msgIn, INTEGER msgOut, INTEGER uiLo, INTEGER uiHi);
#define WinApi_RevertToSelf()	RevertToSelf()
__EXTERN INTEGER __CALL RevertToSelf(void);
#define WinApi_RoundRect(p0, p1, p2, p3, p4, p5, p6)	RoundRect(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL RoundRect(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6);
#define WinApi_RtlUnwind(targetFrame, targetIp, excpRec, retVal)	RtlUnwind(targetFrame, targetIp, excpRec, retVal)
__EXTERN void __CALL RtlUnwind(INTEGER targetFrame, INTEGER targetIp, WinApi_PtrEXCEPTION_RECORD excpRec, INTEGER retVal);
#define WinApi_SHAppBarMessage(dwMessage, pData, pData__typ)	SHAppBarMessage(dwMessage, pData)
__EXTERN INTEGER __CALL SHAppBarMessage(INTEGER dwMessage, WinApi_APPBARDATA *pData);
#define WinApi_SHFileOperation(lpFileOp, lpFileOp__typ)	SHFileOperationA(lpFileOp)
#define WinApi_SHFileOperationA(lpFileOp, lpFileOp__typ)	SHFileOperationA(lpFileOp)
__EXTERN INTEGER __CALL SHFileOperationA(WinApi_SHFILEOPSTRUCTA *lpFileOp);
#define WinApi_SHFileOperationW(lpFileOp, lpFileOp__typ)	SHFileOperationW(lpFileOp)
__EXTERN INTEGER __CALL SHFileOperationW(WinApi_SHFILEOPSTRUCTW *lpFileOp);
#define WinApi_SHFreeNameMappings(hNameMappings)	SHFreeNameMappings(hNameMappings)
__EXTERN void __CALL SHFreeNameMappings(INTEGER hNameMappings);
#define WinApi_SHGetFileInfo(pszPath, dwFileAttributes, psfi, psfi__typ, cbFileInfo, uFlags)	SHGetFileInfoA(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)
#define WinApi_SHGetFileInfoA(pszPath, dwFileAttributes, psfi, psfi__typ, cbFileInfo, uFlags)	SHGetFileInfoA(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)
__EXTERN INTEGER __CALL SHGetFileInfoA(WinApi_PtrSTR pszPath, SET dwFileAttributes, WinApi_SHFILEINFOA *psfi, INTEGER cbFileInfo, SET uFlags);
#define WinApi_SHGetFileInfoW(pszPath, dwFileAttributes, psfi, psfi__typ, cbFileInfo, uFlags)	SHGetFileInfoW(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)
__EXTERN INTEGER __CALL SHGetFileInfoW(WinApi_PtrWSTR pszPath, SET dwFileAttributes, WinApi_SHFILEINFOW *psfi, INTEGER cbFileInfo, SET uFlags);
#define WinApi_SHGetNewLinkInfo(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)	SHGetNewLinkInfoA(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)
#define WinApi_SHGetNewLinkInfoA(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)	SHGetNewLinkInfoA(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)
__EXTERN INTEGER __CALL SHGetNewLinkInfoA(WinApi_PtrSTR pszLinkTo, WinApi_PtrSTR pszDir, WinApi_PtrSTR pszName, INTEGER *pfMustCopy, SET uFlags);
#define WinApi_SHGetNewLinkInfoW(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)	SHGetNewLinkInfoW(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)
__EXTERN INTEGER __CALL SHGetNewLinkInfoW(WinApi_PtrWSTR pszLinkTo, WinApi_PtrWSTR pszDir, WinApi_PtrWSTR pszName, INTEGER *pfMustCopy, SET uFlags);
#define WinApi_SaveDC(p0)	SaveDC(p0)
__EXTERN INTEGER __CALL SaveDC(INTEGER p0);
#define WinApi_ScaleViewportExtEx(p0, p1, p2, p3, p4, p5, p5__typ)	ScaleViewportExtEx(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL ScaleViewportExtEx(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinApi_SIZE *p5);
#define WinApi_ScaleWindowExtEx(p0, p1, p2, p3, p4, p5, p5__typ)	ScaleWindowExtEx(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL ScaleWindowExtEx(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinApi_SIZE *p5);
#define WinApi_ScheduleJob(hPrinter, JobId)	ScheduleJob(hPrinter, JobId)
__EXTERN INTEGER __CALL ScheduleJob(INTEGER hPrinter, INTEGER JobId);
#define WinApi_ScreenToClient(hWnd, lpPoint, lpPoint__typ)	ScreenToClient(hWnd, lpPoint)
__EXTERN INTEGER __CALL ScreenToClient(INTEGER hWnd, WinApi_POINT *lpPoint);
#define WinApi_ScrollConsoleScreenBuffer(hConsoleOutput, lpScrollRectangle, lpScrollRectangle__typ, lpClipRectangle, lpClipRectangle__typ, dwDestinationOrigin, lpFill, lpFill__typ)	ScrollConsoleScreenBufferA(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)
#define WinApi_ScrollConsoleScreenBufferA(hConsoleOutput, lpScrollRectangle, lpScrollRectangle__typ, lpClipRectangle, lpClipRectangle__typ, dwDestinationOrigin, lpFill, lpFill__typ)	ScrollConsoleScreenBufferA(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)
__EXTERN INTEGER __CALL ScrollConsoleScreenBufferA(INTEGER hConsoleOutput, WinApi_SMALL_RECT *lpScrollRectangle, WinApi_SMALL_RECT *lpClipRectangle, WinApi_COORD dwDestinationOrigin, WinApi_CHAR_INFO *lpFill);
#define WinApi_ScrollConsoleScreenBufferW(hConsoleOutput, lpScrollRectangle, lpScrollRectangle__typ, lpClipRectangle, lpClipRectangle__typ, dwDestinationOrigin, lpFill, lpFill__typ)	ScrollConsoleScreenBufferW(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)
__EXTERN INTEGER __CALL ScrollConsoleScreenBufferW(INTEGER hConsoleOutput, WinApi_SMALL_RECT *lpScrollRectangle, WinApi_SMALL_RECT *lpClipRectangle, WinApi_COORD dwDestinationOrigin, WinApi_CHAR_INFO *lpFill);
#define WinApi_ScrollDC(hDC, dx, dy, lprcScroll, lprcScroll__typ, lprcClip, lprcClip__typ, hrgnUpdate, lprcUpdate, lprcUpdate__typ)	ScrollDC(hDC, dx, dy, lprcScroll, lprcClip, hrgnUpdate, lprcUpdate)
__EXTERN INTEGER __CALL ScrollDC(INTEGER hDC, INTEGER dx, INTEGER dy, WinApi_RECT *lprcScroll, WinApi_RECT *lprcClip, INTEGER hrgnUpdate, WinApi_RECT *lprcUpdate);
#define WinApi_ScrollWindow(hWnd, XAmount, YAmount, lpRect, lpRect__typ, lpClipRect, lpClipRect__typ)	ScrollWindow(hWnd, XAmount, YAmount, lpRect, lpClipRect)
__EXTERN INTEGER __CALL ScrollWindow(INTEGER hWnd, INTEGER XAmount, INTEGER YAmount, WinApi_RECT *lpRect, WinApi_RECT *lpClipRect);
#define WinApi_ScrollWindowEx(hWnd, dx, dy, prcScroll, prcScroll__typ, prcClip, prcClip__typ, hrgnUpdate, prcUpdate, prcUpdate__typ, flags)	ScrollWindowEx(hWnd, dx, dy, prcScroll, prcClip, hrgnUpdate, prcUpdate, flags)
__EXTERN INTEGER __CALL ScrollWindowEx(INTEGER hWnd, INTEGER dx, INTEGER dy, WinApi_RECT *prcScroll, WinApi_RECT *prcClip, INTEGER hrgnUpdate, WinApi_RECT *prcUpdate, SET flags);
#define WinApi_SearchPath(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)	SearchPathA(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)
#define WinApi_SearchPathA(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)	SearchPathA(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)
__EXTERN INTEGER __CALL SearchPathA(WinApi_PtrSTR lpPath, WinApi_PtrSTR lpFileName, WinApi_PtrSTR lpExtension, INTEGER nBufferLength, WinApi_PtrSTR lpBuffer, WinApi_PtrSTR *lpFilePart);
#define WinApi_SearchPathW(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)	SearchPathW(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)
__EXTERN INTEGER __CALL SearchPathW(WinApi_PtrWSTR lpPath, WinApi_PtrWSTR lpFileName, WinApi_PtrWSTR lpExtension, INTEGER nBufferLength, WinApi_PtrWSTR lpBuffer, WinApi_PtrWSTR *lpFilePart);
#define WinApi_SelectClipPath(p0, p1)	SelectClipPath(p0, p1)
__EXTERN INTEGER __CALL SelectClipPath(INTEGER p0, INTEGER p1);
#define WinApi_SelectClipRgn(p0, p1)	SelectClipRgn(p0, p1)
__EXTERN INTEGER __CALL SelectClipRgn(INTEGER p0, INTEGER p1);
#define WinApi_SelectObject(p0, p1)	SelectObject(p0, p1)
__EXTERN INTEGER __CALL SelectObject(INTEGER p0, INTEGER p1);
#define WinApi_SelectPalette(p0, p1, p2)	SelectPalette(p0, p1, p2)
__EXTERN INTEGER __CALL SelectPalette(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_SendDlgItemMessage(hDlg, nIDDlgItem, Msg, wParam, lParam)	SendDlgItemMessageA(hDlg, nIDDlgItem, Msg, wParam, lParam)
#define WinApi_SendDlgItemMessageA(hDlg, nIDDlgItem, Msg, wParam, lParam)	SendDlgItemMessageA(hDlg, nIDDlgItem, Msg, wParam, lParam)
__EXTERN INTEGER __CALL SendDlgItemMessageA(INTEGER hDlg, INTEGER nIDDlgItem, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_SendDlgItemMessageW(hDlg, nIDDlgItem, Msg, wParam, lParam)	SendDlgItemMessageW(hDlg, nIDDlgItem, Msg, wParam, lParam)
__EXTERN INTEGER __CALL SendDlgItemMessageW(INTEGER hDlg, INTEGER nIDDlgItem, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_SendMessage(hWnd, Msg, wParam, lParam)	SendMessageA(hWnd, Msg, wParam, lParam)
#define WinApi_SendMessageA(hWnd, Msg, wParam, lParam)	SendMessageA(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL SendMessageA(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_SendMessageCallback(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)	SendMessageCallbackA(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)
#define WinApi_SendMessageCallbackA(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)	SendMessageCallbackA(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)
__EXTERN INTEGER __CALL SendMessageCallbackA(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam, WinApi_SENDASYNCPROC lpResultCallBack, INTEGER dwData);
#define WinApi_SendMessageCallbackW(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)	SendMessageCallbackW(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)
__EXTERN INTEGER __CALL SendMessageCallbackW(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam, WinApi_SENDASYNCPROC lpResultCallBack, INTEGER dwData);
#define WinApi_SendMessageTimeout(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)	SendMessageTimeoutA(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)
#define WinApi_SendMessageTimeoutA(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)	SendMessageTimeoutA(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)
__EXTERN INTEGER __CALL SendMessageTimeoutA(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam, SET fuFlags, INTEGER uTimeout, INTEGER *lpdwResult);
#define WinApi_SendMessageTimeoutW(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)	SendMessageTimeoutW(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)
__EXTERN INTEGER __CALL SendMessageTimeoutW(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam, SET fuFlags, INTEGER uTimeout, INTEGER *lpdwResult);
#define WinApi_SendMessageW(hWnd, Msg, wParam, lParam)	SendMessageW(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL SendMessageW(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_SendNotifyMessage(hWnd, Msg, wParam, lParam)	SendNotifyMessageA(hWnd, Msg, wParam, lParam)
#define WinApi_SendNotifyMessageA(hWnd, Msg, wParam, lParam)	SendNotifyMessageA(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL SendNotifyMessageA(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_SendNotifyMessageW(hWnd, Msg, wParam, lParam)	SendNotifyMessageW(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL SendNotifyMessageW(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinApi_SetAbortProc(p0, p1)	SetAbortProc(p0, p1)
__EXTERN INTEGER __CALL SetAbortProc(INTEGER p0, WinApi_ABORTPROC p1);
#define WinApi_SetAclInformation(pAcl, pAcl__typ, pAclInformation, nAclInformationLength, dwAclInformationClass)	SetAclInformation(pAcl, pAclInformation, nAclInformationLength, dwAclInformationClass)
__EXTERN INTEGER __CALL SetAclInformation(WinApi_ACL *pAcl, INTEGER pAclInformation, INTEGER nAclInformationLength, INTEGER dwAclInformationClass);
#define WinApi_SetActiveWindow(hWnd)	SetActiveWindow(hWnd)
__EXTERN INTEGER __CALL SetActiveWindow(INTEGER hWnd);
#define WinApi_SetArcDirection(p0, p1)	SetArcDirection(p0, p1)
__EXTERN INTEGER __CALL SetArcDirection(INTEGER p0, INTEGER p1);
#define WinApi_SetBitmapBits(p0, p1, p2)	SetBitmapBits(p0, p1, p2)
__EXTERN INTEGER __CALL SetBitmapBits(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_SetBitmapDimensionEx(p0, p1, p2, p3, p3__typ)	SetBitmapDimensionEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetBitmapDimensionEx(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_SIZE *p3);
#define WinApi_SetBkColor(p0, p1)	SetBkColor(p0, p1)
__EXTERN INTEGER __CALL SetBkColor(INTEGER p0, INTEGER p1);
#define WinApi_SetBkMode(p0, p1)	SetBkMode(p0, p1)
__EXTERN INTEGER __CALL SetBkMode(INTEGER p0, INTEGER p1);
#define WinApi_SetBoundsRect(p0, p1, p1__typ, p2)	SetBoundsRect(p0, p1, p2)
__EXTERN SET __CALL SetBoundsRect(INTEGER p0, WinApi_RECT *p1, SET p2);
#define WinApi_SetBrushOrgEx(p0, p1, p2, p3, p3__typ)	SetBrushOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetBrushOrgEx(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_POINT *p3);
#define WinApi_SetCapture(hWnd)	SetCapture(hWnd)
__EXTERN INTEGER __CALL SetCapture(INTEGER hWnd);
#define WinApi_SetCaretBlinkTime(uMSeconds)	SetCaretBlinkTime(uMSeconds)
__EXTERN INTEGER __CALL SetCaretBlinkTime(INTEGER uMSeconds);
#define WinApi_SetCaretPos(X, Y)	SetCaretPos(X, Y)
__EXTERN INTEGER __CALL SetCaretPos(INTEGER X, INTEGER Y);
#define WinApi_SetClassLong(hWnd, nIndex, dwNewLong)	SetClassLongA(hWnd, nIndex, dwNewLong)
#define WinApi_SetClassLongA(hWnd, nIndex, dwNewLong)	SetClassLongA(hWnd, nIndex, dwNewLong)
__EXTERN INTEGER __CALL SetClassLongA(INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong);
#define WinApi_SetClassLongW(hWnd, nIndex, dwNewLong)	SetClassLongW(hWnd, nIndex, dwNewLong)
__EXTERN INTEGER __CALL SetClassLongW(INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong);
#define WinApi_SetClassWord(hWnd, nIndex, wNewWord)	SetClassWord(hWnd, nIndex, wNewWord)
__EXTERN SHORTINT __CALL SetClassWord(INTEGER hWnd, INTEGER nIndex, SHORTINT wNewWord);
#define WinApi_SetClipboardData(uFormat, hMem)	SetClipboardData(uFormat, hMem)
__EXTERN INTEGER __CALL SetClipboardData(INTEGER uFormat, INTEGER hMem);
#define WinApi_SetClipboardViewer(hWndNewViewer)	SetClipboardViewer(hWndNewViewer)
__EXTERN INTEGER __CALL SetClipboardViewer(INTEGER hWndNewViewer);
#define WinApi_SetColorAdjustment(p0, p1, p1__typ)	SetColorAdjustment(p0, p1)
__EXTERN INTEGER __CALL SetColorAdjustment(INTEGER p0, WinApi_COLORADJUSTMENT *p1);
#define WinApi_SetColorSpace(p0, p1)	SetColorSpace(p0, p1)
__EXTERN INTEGER __CALL SetColorSpace(INTEGER p0, INTEGER p1);
#define WinApi_SetCommBreak(hFile)	SetCommBreak(hFile)
__EXTERN INTEGER __CALL SetCommBreak(INTEGER hFile);
#define WinApi_SetCommConfig(hCommDev, lpCC, lpCC__typ, dwSize)	SetCommConfig(hCommDev, lpCC, dwSize)
__EXTERN INTEGER __CALL SetCommConfig(INTEGER hCommDev, WinApi_COMMCONFIG *lpCC, INTEGER dwSize);
#define WinApi_SetCommMask(hFile, dwEvtMask)	SetCommMask(hFile, dwEvtMask)
__EXTERN INTEGER __CALL SetCommMask(INTEGER hFile, SET dwEvtMask);
#define WinApi_SetCommState(hFile, lpDCB, lpDCB__typ)	SetCommState(hFile, lpDCB)
__EXTERN INTEGER __CALL SetCommState(INTEGER hFile, WinApi_DCB *lpDCB);
#define WinApi_SetCommTimeouts(hFile, lpCommTimeouts, lpCommTimeouts__typ)	SetCommTimeouts(hFile, lpCommTimeouts)
__EXTERN INTEGER __CALL SetCommTimeouts(INTEGER hFile, WinApi_COMMTIMEOUTS *lpCommTimeouts);
#define WinApi_SetComputerName(lpComputerName)	SetComputerNameA(lpComputerName)
#define WinApi_SetComputerNameA(lpComputerName)	SetComputerNameA(lpComputerName)
__EXTERN INTEGER __CALL SetComputerNameA(WinApi_PtrSTR lpComputerName);
#define WinApi_SetComputerNameW(lpComputerName)	SetComputerNameW(lpComputerName)
__EXTERN INTEGER __CALL SetComputerNameW(WinApi_PtrWSTR lpComputerName);
#define WinApi_SetConsoleActiveScreenBuffer(hConsoleOutput)	SetConsoleActiveScreenBuffer(hConsoleOutput)
__EXTERN INTEGER __CALL SetConsoleActiveScreenBuffer(INTEGER hConsoleOutput);
#define WinApi_SetConsoleCP(wCodePageID)	SetConsoleCP(wCodePageID)
__EXTERN INTEGER __CALL SetConsoleCP(INTEGER wCodePageID);
#define WinApi_SetConsoleCtrlHandler(HandlerRoutine, Add)	SetConsoleCtrlHandler(HandlerRoutine, Add)
__EXTERN INTEGER __CALL SetConsoleCtrlHandler(WinApi_HANDLER_ROUTINE HandlerRoutine, INTEGER Add);
#define WinApi_SetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo, lpConsoleCursorInfo__typ)	SetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo)
__EXTERN INTEGER __CALL SetConsoleCursorInfo(INTEGER hConsoleOutput, WinApi_CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
#define WinApi_SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition)	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition)
__EXTERN INTEGER __CALL SetConsoleCursorPosition(INTEGER hConsoleOutput, WinApi_COORD dwCursorPosition);
#define WinApi_SetConsoleMode(hConsoleHandle, dwMode)	SetConsoleMode(hConsoleHandle, dwMode)
__EXTERN INTEGER __CALL SetConsoleMode(INTEGER hConsoleHandle, SET dwMode);
#define WinApi_SetConsoleOutputCP(wCodePageID)	SetConsoleOutputCP(wCodePageID)
__EXTERN INTEGER __CALL SetConsoleOutputCP(INTEGER wCodePageID);
#define WinApi_SetConsoleScreenBufferSize(hConsoleOutput, dwSize)	SetConsoleScreenBufferSize(hConsoleOutput, dwSize)
__EXTERN INTEGER __CALL SetConsoleScreenBufferSize(INTEGER hConsoleOutput, WinApi_COORD dwSize);
#define WinApi_SetConsoleTextAttribute(hConsoleOutput, wAttributes)	SetConsoleTextAttribute(hConsoleOutput, wAttributes)
__EXTERN INTEGER __CALL SetConsoleTextAttribute(INTEGER hConsoleOutput, SHORTINT wAttributes);
#define WinApi_SetConsoleTitle(lpConsoleTitle)	SetConsoleTitleA(lpConsoleTitle)
#define WinApi_SetConsoleTitleA(lpConsoleTitle)	SetConsoleTitleA(lpConsoleTitle)
__EXTERN INTEGER __CALL SetConsoleTitleA(WinApi_PtrSTR lpConsoleTitle);
#define WinApi_SetConsoleTitleW(lpConsoleTitle)	SetConsoleTitleW(lpConsoleTitle)
__EXTERN INTEGER __CALL SetConsoleTitleW(WinApi_PtrWSTR lpConsoleTitle);
#define WinApi_SetConsoleWindowInfo(hConsoleOutput, bAbsolute, lpConsoleWindow, lpConsoleWindow__typ)	SetConsoleWindowInfo(hConsoleOutput, bAbsolute, lpConsoleWindow)
__EXTERN INTEGER __CALL SetConsoleWindowInfo(INTEGER hConsoleOutput, INTEGER bAbsolute, WinApi_SMALL_RECT *lpConsoleWindow);
#define WinApi_SetCurrentDirectory(lpPathName)	SetCurrentDirectoryA(lpPathName)
#define WinApi_SetCurrentDirectoryA(lpPathName)	SetCurrentDirectoryA(lpPathName)
__EXTERN INTEGER __CALL SetCurrentDirectoryA(WinApi_PtrSTR lpPathName);
#define WinApi_SetCurrentDirectoryW(lpPathName)	SetCurrentDirectoryW(lpPathName)
__EXTERN INTEGER __CALL SetCurrentDirectoryW(WinApi_PtrWSTR lpPathName);
#define WinApi_SetCursor(hCursor)	SetCursor(hCursor)
__EXTERN INTEGER __CALL SetCursor(INTEGER hCursor);
#define WinApi_SetCursorPos(X, Y)	SetCursorPos(X, Y)
__EXTERN INTEGER __CALL SetCursorPos(INTEGER X, INTEGER Y);
#define WinApi_SetDIBColorTable(p0, p1, p2, p3, p3__len)	SetDIBColorTable(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetDIBColorTable(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_RGBQUAD *p3);
#define WinApi_SetDIBits(p0, p1, p2, p3, p4, p5, p5__typ, p6)	SetDIBits(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL SetDIBits(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinApi_BITMAPINFO *p5, INTEGER p6);
#define WinApi_SetDIBitsToDevice(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p10__typ, p11)	SetDIBitsToDevice(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)
__EXTERN INTEGER __CALL SetDIBitsToDevice(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, WinApi_BITMAPINFO *p10, INTEGER p11);
#define WinApi_SetDebugErrorLevel(dwLevel)	SetDebugErrorLevel(dwLevel)
__EXTERN void __CALL SetDebugErrorLevel(INTEGER dwLevel);
#define WinApi_SetDefaultCommConfig(lpszName, lpCC, lpCC__typ, dwSize)	SetDefaultCommConfigA(lpszName, lpCC, dwSize)
#define WinApi_SetDefaultCommConfigA(lpszName, lpCC, lpCC__typ, dwSize)	SetDefaultCommConfigA(lpszName, lpCC, dwSize)
__EXTERN INTEGER __CALL SetDefaultCommConfigA(WinApi_PtrSTR lpszName, WinApi_COMMCONFIG *lpCC, INTEGER dwSize);
#define WinApi_SetDefaultCommConfigW(lpszName, lpCC, lpCC__typ, dwSize)	SetDefaultCommConfigW(lpszName, lpCC, dwSize)
__EXTERN INTEGER __CALL SetDefaultCommConfigW(WinApi_PtrWSTR lpszName, WinApi_COMMCONFIG *lpCC, INTEGER dwSize);
#define WinApi_SetDeviceGammaRamp(p0, p1)	SetDeviceGammaRamp(p0, p1)
__EXTERN INTEGER __CALL SetDeviceGammaRamp(INTEGER p0, INTEGER p1);
#define WinApi_SetDlgItemInt(hDlg, nIDDlgItem, uValue, bSigned)	SetDlgItemInt(hDlg, nIDDlgItem, uValue, bSigned)
__EXTERN INTEGER __CALL SetDlgItemInt(INTEGER hDlg, INTEGER nIDDlgItem, INTEGER uValue, INTEGER bSigned);
#define WinApi_SetDlgItemText(hDlg, nIDDlgItem, lpString)	SetDlgItemTextA(hDlg, nIDDlgItem, lpString)
#define WinApi_SetDlgItemTextA(hDlg, nIDDlgItem, lpString)	SetDlgItemTextA(hDlg, nIDDlgItem, lpString)
__EXTERN INTEGER __CALL SetDlgItemTextA(INTEGER hDlg, INTEGER nIDDlgItem, WinApi_PtrSTR lpString);
#define WinApi_SetDlgItemTextW(hDlg, nIDDlgItem, lpString)	SetDlgItemTextW(hDlg, nIDDlgItem, lpString)
__EXTERN INTEGER __CALL SetDlgItemTextW(INTEGER hDlg, INTEGER nIDDlgItem, WinApi_PtrWSTR lpString);
#define WinApi_SetDoubleClickTime(p0)	SetDoubleClickTime(p0)
__EXTERN INTEGER __CALL SetDoubleClickTime(INTEGER p0);
#define WinApi_SetEndOfFile(hFile)	SetEndOfFile(hFile)
__EXTERN INTEGER __CALL SetEndOfFile(INTEGER hFile);
#define WinApi_SetEnhMetaFileBits(p0, p1)	SetEnhMetaFileBits(p0, p1)
__EXTERN INTEGER __CALL SetEnhMetaFileBits(INTEGER p0, CHAR *p1);
#define WinApi_SetEnvironmentVariable(lpName, lpValue)	SetEnvironmentVariableA(lpName, lpValue)
#define WinApi_SetEnvironmentVariableA(lpName, lpValue)	SetEnvironmentVariableA(lpName, lpValue)
__EXTERN INTEGER __CALL SetEnvironmentVariableA(WinApi_PtrSTR lpName, WinApi_PtrSTR lpValue);
#define WinApi_SetEnvironmentVariableW(lpName, lpValue)	SetEnvironmentVariableW(lpName, lpValue)
__EXTERN INTEGER __CALL SetEnvironmentVariableW(WinApi_PtrWSTR lpName, WinApi_PtrWSTR lpValue);
#define WinApi_SetErrorMode(uMode)	SetErrorMode(uMode)
__EXTERN INTEGER __CALL SetErrorMode(SET uMode);
#define WinApi_SetEvent(hEvent)	SetEvent(hEvent)
__EXTERN INTEGER __CALL SetEvent(INTEGER hEvent);
#define WinApi_SetFileApisToANSI()	SetFileApisToANSI()
__EXTERN void __CALL SetFileApisToANSI(void);
#define WinApi_SetFileApisToOEM()	SetFileApisToOEM()
__EXTERN void __CALL SetFileApisToOEM(void);
#define WinApi_SetFileAttributes(lpFileName, dwFileAttributes)	SetFileAttributesA(lpFileName, dwFileAttributes)
#define WinApi_SetFileAttributesA(lpFileName, dwFileAttributes)	SetFileAttributesA(lpFileName, dwFileAttributes)
__EXTERN INTEGER __CALL SetFileAttributesA(WinApi_PtrSTR lpFileName, SET dwFileAttributes);
#define WinApi_SetFileAttributesW(lpFileName, dwFileAttributes)	SetFileAttributesW(lpFileName, dwFileAttributes)
__EXTERN INTEGER __CALL SetFileAttributesW(WinApi_PtrWSTR lpFileName, SET dwFileAttributes);
#define WinApi_SetFilePointer(hFile, lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod)	SetFilePointer(hFile, lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod)
__EXTERN INTEGER __CALL SetFilePointer(INTEGER hFile, INTEGER lDistanceToMove, INTEGER *lpDistanceToMoveHigh, INTEGER dwMoveMethod);
#define WinApi_SetFileSecurity(lpFileName, SecurityInformation, pSecurityDescriptor)	SetFileSecurityA(lpFileName, SecurityInformation, pSecurityDescriptor)
#define WinApi_SetFileSecurityA(lpFileName, SecurityInformation, pSecurityDescriptor)	SetFileSecurityA(lpFileName, SecurityInformation, pSecurityDescriptor)
__EXTERN INTEGER __CALL SetFileSecurityA(WinApi_PtrSTR lpFileName, SET SecurityInformation, INTEGER pSecurityDescriptor);
#define WinApi_SetFileSecurityW(lpFileName, SecurityInformation, pSecurityDescriptor)	SetFileSecurityW(lpFileName, SecurityInformation, pSecurityDescriptor)
__EXTERN INTEGER __CALL SetFileSecurityW(WinApi_PtrWSTR lpFileName, SET SecurityInformation, INTEGER pSecurityDescriptor);
#define WinApi_SetFileTime(hFile, lpCreationTime, lpCreationTime__typ, lpLastAccessTime, lpLastAccessTime__typ, lpLastWriteTime, lpLastWriteTime__typ)	SetFileTime(hFile, lpCreationTime, lpLastAccessTime, lpLastWriteTime)
__EXTERN INTEGER __CALL SetFileTime(INTEGER hFile, WinApi_FILETIME *lpCreationTime, WinApi_FILETIME *lpLastAccessTime, WinApi_FILETIME *lpLastWriteTime);
#define WinApi_SetFocus(hWnd)	SetFocus(hWnd)
__EXTERN INTEGER __CALL SetFocus(INTEGER hWnd);
#define WinApi_SetForegroundWindow(hWnd)	SetForegroundWindow(hWnd)
__EXTERN INTEGER __CALL SetForegroundWindow(INTEGER hWnd);
#define WinApi_SetForm(hPrinter, pFormName, Level, pForm)	SetFormA(hPrinter, pFormName, Level, pForm)
#define WinApi_SetFormA(hPrinter, pFormName, Level, pForm)	SetFormA(hPrinter, pFormName, Level, pForm)
__EXTERN INTEGER __CALL SetFormA(INTEGER hPrinter, WinApi_PtrSTR pFormName, INTEGER Level, CHAR *pForm);
#define WinApi_SetFormW(hPrinter, pFormName, Level, pForm)	SetFormW(hPrinter, pFormName, Level, pForm)
__EXTERN INTEGER __CALL SetFormW(INTEGER hPrinter, WinApi_PtrWSTR pFormName, INTEGER Level, CHAR *pForm);
#define WinApi_SetGraphicsMode(hdc, iMode)	SetGraphicsMode(hdc, iMode)
__EXTERN INTEGER __CALL SetGraphicsMode(INTEGER hdc, INTEGER iMode);
#define WinApi_SetHandleCount(uNumber)	SetHandleCount(uNumber)
__EXTERN INTEGER __CALL SetHandleCount(INTEGER uNumber);
#define WinApi_SetHandleInformation(hObject, dwMask, dwFlags)	SetHandleInformation(hObject, dwMask, dwFlags)
__EXTERN INTEGER __CALL SetHandleInformation(INTEGER hObject, INTEGER dwMask, SET dwFlags);
#define WinApi_SetICMMode(p0, p1)	SetICMMode(p0, p1)
__EXTERN INTEGER __CALL SetICMMode(INTEGER p0, INTEGER p1);
#define WinApi_SetICMProfile(p0, p1)	SetICMProfileA(p0, p1)
#define WinApi_SetICMProfileA(p0, p1)	SetICMProfileA(p0, p1)
__EXTERN INTEGER __CALL SetICMProfileA(INTEGER p0, WinApi_PtrSTR p1);
#define WinApi_SetICMProfileW(p0, p1)	SetICMProfileW(p0, p1)
__EXTERN INTEGER __CALL SetICMProfileW(INTEGER p0, WinApi_PtrWSTR p1);
#define WinApi_SetJob(hPrinter, JobId, Level, pJob, Command)	SetJobA(hPrinter, JobId, Level, pJob, Command)
#define WinApi_SetJobA(hPrinter, JobId, Level, pJob, Command)	SetJobA(hPrinter, JobId, Level, pJob, Command)
__EXTERN INTEGER __CALL SetJobA(INTEGER hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER Command);
#define WinApi_SetJobW(hPrinter, JobId, Level, pJob, Command)	SetJobW(hPrinter, JobId, Level, pJob, Command)
__EXTERN INTEGER __CALL SetJobW(INTEGER hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER Command);
#define WinApi_SetKernelObjectSecurity(Handle, SecurityInformation, SecurityDescriptor)	SetKernelObjectSecurity(Handle, SecurityInformation, SecurityDescriptor)
__EXTERN INTEGER __CALL SetKernelObjectSecurity(INTEGER Handle, SET SecurityInformation, INTEGER SecurityDescriptor);
#define WinApi_SetKeyboardState(lpKeyState)	SetKeyboardState(lpKeyState)
__EXTERN INTEGER __CALL SetKeyboardState(CHAR *lpKeyState);
#define WinApi_SetLastError(dwErrCode)	SetLastError(dwErrCode)
__EXTERN void __CALL SetLastError(INTEGER dwErrCode);
#define WinApi_SetLastErrorEx(dwErrCode, dwType)	SetLastErrorEx(dwErrCode, dwType)
__EXTERN void __CALL SetLastErrorEx(INTEGER dwErrCode, INTEGER dwType);
#define WinApi_SetLocalTime(lpSystemTime, lpSystemTime__typ)	SetLocalTime(lpSystemTime)
__EXTERN INTEGER __CALL SetLocalTime(WinApi_SYSTEMTIME *lpSystemTime);
#define WinApi_SetLocaleInfo(Locale, LCType, lpLCData)	SetLocaleInfoA(Locale, LCType, lpLCData)
#define WinApi_SetLocaleInfoA(Locale, LCType, lpLCData)	SetLocaleInfoA(Locale, LCType, lpLCData)
__EXTERN INTEGER __CALL SetLocaleInfoA(INTEGER Locale, INTEGER LCType, WinApi_PtrSTR lpLCData);
#define WinApi_SetLocaleInfoW(Locale, LCType, lpLCData)	SetLocaleInfoW(Locale, LCType, lpLCData)
__EXTERN INTEGER __CALL SetLocaleInfoW(INTEGER Locale, INTEGER LCType, WinApi_PtrWSTR lpLCData);
#define WinApi_SetMailslotInfo(hMailslot, lReadTimeout)	SetMailslotInfo(hMailslot, lReadTimeout)
__EXTERN INTEGER __CALL SetMailslotInfo(INTEGER hMailslot, INTEGER lReadTimeout);
#define WinApi_SetMapMode(p0, p1)	SetMapMode(p0, p1)
__EXTERN INTEGER __CALL SetMapMode(INTEGER p0, INTEGER p1);
#define WinApi_SetMapperFlags(p0, p1)	SetMapperFlags(p0, p1)
__EXTERN INTEGER __CALL SetMapperFlags(INTEGER p0, INTEGER p1);
#define WinApi_SetMenu(hWnd, hMenu)	SetMenu(hWnd, hMenu)
__EXTERN INTEGER __CALL SetMenu(INTEGER hWnd, INTEGER hMenu);
#define WinApi_SetMenuContextHelpId(p0, p1)	SetMenuContextHelpId(p0, p1)
__EXTERN INTEGER __CALL SetMenuContextHelpId(INTEGER p0, INTEGER p1);
#define WinApi_SetMenuDefaultItem(hMenu, uItem, fByPos)	SetMenuDefaultItem(hMenu, uItem, fByPos)
__EXTERN INTEGER __CALL SetMenuDefaultItem(INTEGER hMenu, INTEGER uItem, INTEGER fByPos);
#define WinApi_SetMenuItemBitmaps(hMenu, uPosition, uFlags, hBitmapUnchecked, hBitmapChecked)	SetMenuItemBitmaps(hMenu, uPosition, uFlags, hBitmapUnchecked, hBitmapChecked)
__EXTERN INTEGER __CALL SetMenuItemBitmaps(INTEGER hMenu, INTEGER uPosition, SET uFlags, INTEGER hBitmapUnchecked, INTEGER hBitmapChecked);
#define WinApi_SetMenuItemInfo(p0, p1, p2, p3, p3__typ)	SetMenuItemInfoA(p0, p1, p2, p3)
#define WinApi_SetMenuItemInfoA(p0, p1, p2, p3, p3__typ)	SetMenuItemInfoA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetMenuItemInfoA(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_MENUITEMINFOA *p3);
#define WinApi_SetMenuItemInfoW(p0, p1, p2, p3, p3__typ)	SetMenuItemInfoW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetMenuItemInfoW(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_MENUITEMINFOW *p3);
#define WinApi_SetMessageExtraInfo(lParam)	SetMessageExtraInfo(lParam)
__EXTERN INTEGER __CALL SetMessageExtraInfo(INTEGER lParam);
#define WinApi_SetMessageQueue(cMessagesMax)	SetMessageQueue(cMessagesMax)
__EXTERN INTEGER __CALL SetMessageQueue(INTEGER cMessagesMax);
#define WinApi_SetMetaFileBitsEx(p0, p1, p1__len)	SetMetaFileBitsEx(p0, p1)
__EXTERN INTEGER __CALL SetMetaFileBitsEx(INTEGER p0, SYSTEM_BYTE *p1);
#define WinApi_SetMetaRgn(p0)	SetMetaRgn(p0)
__EXTERN INTEGER __CALL SetMetaRgn(INTEGER p0);
#define WinApi_SetMiterLimit(p0, p1, p2)	SetMiterLimit(p0, p1, p2)
__EXTERN INTEGER __CALL SetMiterLimit(INTEGER p0, REAL p1, REAL *p2);
#define WinApi_SetNamedPipeHandleState(hNamedPipe, lpMode, lpMaxCollectionCount, lpCollectDataTimeout)	SetNamedPipeHandleState(hNamedPipe, lpMode, lpMaxCollectionCount, lpCollectDataTimeout)
__EXTERN INTEGER __CALL SetNamedPipeHandleState(INTEGER hNamedPipe, INTEGER *lpMode, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout);
#define WinApi_SetPaletteEntries(p0, p1, p2, p3, p3__typ)	SetPaletteEntries(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetPaletteEntries(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_PALETTEENTRY *p3);
#define WinApi_SetParent(hWndChild, hWndNewParent)	SetParent(hWndChild, hWndNewParent)
__EXTERN INTEGER __CALL SetParent(INTEGER hWndChild, INTEGER hWndNewParent);
#define WinApi_SetPixel(p0, p1, p2, p3)	SetPixel(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetPixel(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinApi_SetPixelFormat(p0, p1, p2, p2__typ)	SetPixelFormat(p0, p1, p2)
__EXTERN INTEGER __CALL SetPixelFormat(INTEGER p0, INTEGER p1, WinApi_PIXELFORMATDESCRIPTOR *p2);
#define WinApi_SetPixelV(p0, p1, p2, p3)	SetPixelV(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetPixelV(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinApi_SetPolyFillMode(p0, p1)	SetPolyFillMode(p0, p1)
__EXTERN INTEGER __CALL SetPolyFillMode(INTEGER p0, INTEGER p1);
#define WinApi_SetPrinter(hPrinter, Level, pPrinter, Command)	SetPrinterA(hPrinter, Level, pPrinter, Command)
#define WinApi_SetPrinterA(hPrinter, Level, pPrinter, Command)	SetPrinterA(hPrinter, Level, pPrinter, Command)
__EXTERN INTEGER __CALL SetPrinterA(INTEGER hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER Command);
#define WinApi_SetPrinterData(hPrinter, pValueName, Type, pData, cbData)	SetPrinterDataA(hPrinter, pValueName, Type, pData, cbData)
#define WinApi_SetPrinterDataA(hPrinter, pValueName, Type, pData, cbData)	SetPrinterDataA(hPrinter, pValueName, Type, pData, cbData)
__EXTERN INTEGER __CALL SetPrinterDataA(INTEGER hPrinter, WinApi_PtrSTR pValueName, INTEGER Type, CHAR *pData, INTEGER cbData);
#define WinApi_SetPrinterDataW(hPrinter, pValueName, Type, pData, cbData)	SetPrinterDataW(hPrinter, pValueName, Type, pData, cbData)
__EXTERN INTEGER __CALL SetPrinterDataW(INTEGER hPrinter, WinApi_PtrWSTR pValueName, INTEGER Type, CHAR *pData, INTEGER cbData);
#define WinApi_SetPrinterW(hPrinter, Level, pPrinter, Command)	SetPrinterW(hPrinter, Level, pPrinter, Command)
__EXTERN INTEGER __CALL SetPrinterW(INTEGER hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER Command);
#define WinApi_SetPriorityClass(hProcess, dwPriorityClass)	SetPriorityClass(hProcess, dwPriorityClass)
__EXTERN INTEGER __CALL SetPriorityClass(INTEGER hProcess, INTEGER dwPriorityClass);
#define WinApi_SetPrivateObjectSecurity(SecurityInformation, ModificationDescriptor, ObjectsSecurityDescriptor, GenericMapping, GenericMapping__typ, Token)	SetPrivateObjectSecurity(SecurityInformation, ModificationDescriptor, ObjectsSecurityDescriptor, GenericMapping, Token)
__EXTERN INTEGER __CALL SetPrivateObjectSecurity(SET SecurityInformation, INTEGER ModificationDescriptor, INTEGER *ObjectsSecurityDescriptor, WinApi_GENERIC_MAPPING *GenericMapping, INTEGER Token);
#define WinApi_SetProcessAffinityMask(hProcess, dwProcessAffinityMask)	SetProcessAffinityMask(hProcess, dwProcessAffinityMask)
__EXTERN INTEGER __CALL SetProcessAffinityMask(INTEGER hProcess, INTEGER dwProcessAffinityMask);
#define WinApi_SetProcessShutdownParameters(dwLevel, dwFlags)	SetProcessShutdownParameters(dwLevel, dwFlags)
__EXTERN INTEGER __CALL SetProcessShutdownParameters(INTEGER dwLevel, SET dwFlags);
#define WinApi_SetProcessWindowStation(hWinSta)	SetProcessWindowStation(hWinSta)
__EXTERN INTEGER __CALL SetProcessWindowStation(INTEGER hWinSta);
#define WinApi_SetProcessWorkingSetSize(hProcess, dwMinimumWorkingSetSize, dwMaximumWorkingSetSize)	SetProcessWorkingSetSize(hProcess, dwMinimumWorkingSetSize, dwMaximumWorkingSetSize)
__EXTERN INTEGER __CALL SetProcessWorkingSetSize(INTEGER hProcess, INTEGER dwMinimumWorkingSetSize, INTEGER dwMaximumWorkingSetSize);
#define WinApi_SetProp(hWnd, lpString, hData)	SetPropA(hWnd, lpString, hData)
#define WinApi_SetPropA(hWnd, lpString, hData)	SetPropA(hWnd, lpString, hData)
__EXTERN INTEGER __CALL SetPropA(INTEGER hWnd, WinApi_PtrSTR lpString, INTEGER hData);
#define WinApi_SetPropW(hWnd, lpString, hData)	SetPropW(hWnd, lpString, hData)
__EXTERN INTEGER __CALL SetPropW(INTEGER hWnd, WinApi_PtrWSTR lpString, INTEGER hData);
#define WinApi_SetROP2(p0, p1)	SetROP2(p0, p1)
__EXTERN INTEGER __CALL SetROP2(INTEGER p0, INTEGER p1);
#define WinApi_SetRect(lprc, lprc__typ, xLeft, yTop, xRight, yBottom)	SetRect(lprc, xLeft, yTop, xRight, yBottom)
__EXTERN INTEGER __CALL SetRect(WinApi_RECT *lprc, INTEGER xLeft, INTEGER yTop, INTEGER xRight, INTEGER yBottom);
#define WinApi_SetRectEmpty(lprc, lprc__typ)	SetRectEmpty(lprc)
__EXTERN INTEGER __CALL SetRectEmpty(WinApi_RECT *lprc);
#define WinApi_SetRectRgn(p0, p1, p2, p3, p4)	SetRectRgn(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL SetRectRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinApi_SetScrollInfo(p0, p1, p2, p2__typ, p3)	SetScrollInfo(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetScrollInfo(INTEGER p0, INTEGER p1, WinApi_SCROLLINFO *p2, INTEGER p3);
#define WinApi_SetScrollPos(hWnd, nBar, nPos, bRedraw)	SetScrollPos(hWnd, nBar, nPos, bRedraw)
__EXTERN INTEGER __CALL SetScrollPos(INTEGER hWnd, INTEGER nBar, INTEGER nPos, INTEGER bRedraw);
#define WinApi_SetScrollRange(hWnd, nBar, nMinPos, nMaxPos, bRedraw)	SetScrollRange(hWnd, nBar, nMinPos, nMaxPos, bRedraw)
__EXTERN INTEGER __CALL SetScrollRange(INTEGER hWnd, INTEGER nBar, INTEGER nMinPos, INTEGER nMaxPos, INTEGER bRedraw);
#define WinApi_SetSecurityDescriptorDacl(pSecurityDescriptor, bDaclPresent, pDacl, pDacl__typ, bDaclDefaulted)	SetSecurityDescriptorDacl(pSecurityDescriptor, bDaclPresent, pDacl, bDaclDefaulted)
__EXTERN INTEGER __CALL SetSecurityDescriptorDacl(INTEGER pSecurityDescriptor, INTEGER bDaclPresent, WinApi_ACL *pDacl, INTEGER bDaclDefaulted);
#define WinApi_SetSecurityDescriptorGroup(pSecurityDescriptor, pGroup, bGroupDefaulted)	SetSecurityDescriptorGroup(pSecurityDescriptor, pGroup, bGroupDefaulted)
__EXTERN INTEGER __CALL SetSecurityDescriptorGroup(INTEGER pSecurityDescriptor, INTEGER pGroup, INTEGER bGroupDefaulted);
#define WinApi_SetSecurityDescriptorOwner(pSecurityDescriptor, pOwner, bOwnerDefaulted)	SetSecurityDescriptorOwner(pSecurityDescriptor, pOwner, bOwnerDefaulted)
__EXTERN INTEGER __CALL SetSecurityDescriptorOwner(INTEGER pSecurityDescriptor, INTEGER pOwner, INTEGER bOwnerDefaulted);
#define WinApi_SetSecurityDescriptorSacl(pSecurityDescriptor, bSaclPresent, pSacl, pSacl__typ, bSaclDefaulted)	SetSecurityDescriptorSacl(pSecurityDescriptor, bSaclPresent, pSacl, bSaclDefaulted)
__EXTERN INTEGER __CALL SetSecurityDescriptorSacl(INTEGER pSecurityDescriptor, INTEGER bSaclPresent, WinApi_ACL *pSacl, INTEGER bSaclDefaulted);
#define WinApi_SetServiceObjectSecurity(hService, dwSecurityInformation, lpSecurityDescriptor)	SetServiceObjectSecurity(hService, dwSecurityInformation, lpSecurityDescriptor)
__EXTERN INTEGER __CALL SetServiceObjectSecurity(INTEGER hService, SET dwSecurityInformation, INTEGER lpSecurityDescriptor);
#define WinApi_SetServiceStatus(hServiceStatus, lpServiceStatus, lpServiceStatus__typ)	SetServiceStatus(hServiceStatus, lpServiceStatus)
__EXTERN INTEGER __CALL SetServiceStatus(INTEGER hServiceStatus, WinApi_SERVICE_STATUS *lpServiceStatus);
#define WinApi_SetStdHandle(nStdHandle, hHandle)	SetStdHandle(nStdHandle, hHandle)
__EXTERN INTEGER __CALL SetStdHandle(INTEGER nStdHandle, INTEGER hHandle);
#define WinApi_SetStretchBltMode(p0, p1)	SetStretchBltMode(p0, p1)
__EXTERN INTEGER __CALL SetStretchBltMode(INTEGER p0, INTEGER p1);
#define WinApi_SetSysColors(cElements, lpaElements, lpaRgbValues)	SetSysColors(cElements, lpaElements, lpaRgbValues)
__EXTERN INTEGER __CALL SetSysColors(INTEGER cElements, INTEGER *lpaElements, INTEGER *lpaRgbValues);
#define WinApi_SetSystemCursor(hcur, id)	SetSystemCursor(hcur, id)
__EXTERN INTEGER __CALL SetSystemCursor(INTEGER hcur, INTEGER id);
#define WinApi_SetSystemPaletteUse(p0, p1)	SetSystemPaletteUse(p0, p1)
__EXTERN INTEGER __CALL SetSystemPaletteUse(INTEGER p0, INTEGER p1);
#define WinApi_SetSystemPowerState(fSuspend, fForce)	SetSystemPowerState(fSuspend, fForce)
__EXTERN INTEGER __CALL SetSystemPowerState(INTEGER fSuspend, INTEGER fForce);
#define WinApi_SetSystemTime(lpSystemTime, lpSystemTime__typ)	SetSystemTime(lpSystemTime)
__EXTERN INTEGER __CALL SetSystemTime(WinApi_SYSTEMTIME *lpSystemTime);
#define WinApi_SetSystemTimeAdjustment(dwTimeAdjustment, bTimeAdjustmentDisabled)	SetSystemTimeAdjustment(dwTimeAdjustment, bTimeAdjustmentDisabled)
__EXTERN INTEGER __CALL SetSystemTimeAdjustment(INTEGER dwTimeAdjustment, INTEGER bTimeAdjustmentDisabled);
#define WinApi_SetTapeParameters(hDevice, dwOperation, lpTapeInformation)	SetTapeParameters(hDevice, dwOperation, lpTapeInformation)
__EXTERN INTEGER __CALL SetTapeParameters(INTEGER hDevice, INTEGER dwOperation, INTEGER lpTapeInformation);
#define WinApi_SetTapePosition(hDevice, dwPositionMethod, dwPartition, dwOffsetLow, dwOffsetHigh, bImmediate)	SetTapePosition(hDevice, dwPositionMethod, dwPartition, dwOffsetLow, dwOffsetHigh, bImmediate)
__EXTERN INTEGER __CALL SetTapePosition(INTEGER hDevice, INTEGER dwPositionMethod, INTEGER dwPartition, INTEGER dwOffsetLow, INTEGER dwOffsetHigh, INTEGER bImmediate);
#define WinApi_SetTextAlign(p0, p1)	SetTextAlign(p0, p1)
__EXTERN SET __CALL SetTextAlign(INTEGER p0, SET p1);
#define WinApi_SetTextCharacterExtra(p0, p1)	SetTextCharacterExtra(p0, p1)
__EXTERN INTEGER __CALL SetTextCharacterExtra(INTEGER p0, INTEGER p1);
#define WinApi_SetTextColor(p0, p1)	SetTextColor(p0, p1)
__EXTERN INTEGER __CALL SetTextColor(INTEGER p0, INTEGER p1);
#define WinApi_SetTextJustification(p0, p1, p2)	SetTextJustification(p0, p1, p2)
__EXTERN INTEGER __CALL SetTextJustification(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_SetThreadAffinityMask(hThread, dwThreadAffinityMask)	SetThreadAffinityMask(hThread, dwThreadAffinityMask)
__EXTERN INTEGER __CALL SetThreadAffinityMask(INTEGER hThread, INTEGER dwThreadAffinityMask);
#define WinApi_SetThreadContext(hThread, lpContext, lpContext__typ)	SetThreadContext(hThread, lpContext)
__EXTERN INTEGER __CALL SetThreadContext(INTEGER hThread, WinApi_CONTEXT *lpContext);
#define WinApi_SetThreadDesktop(hDesktop)	SetThreadDesktop(hDesktop)
__EXTERN INTEGER __CALL SetThreadDesktop(INTEGER hDesktop);
#define WinApi_SetThreadIdealProcessor(hThread, dwIdealProcessor)	SetThreadIdealProcessor(hThread, dwIdealProcessor)
__EXTERN INTEGER __CALL SetThreadIdealProcessor(INTEGER hThread, INTEGER dwIdealProcessor);
#define WinApi_SetThreadLocale(Locale)	SetThreadLocale(Locale)
__EXTERN INTEGER __CALL SetThreadLocale(INTEGER Locale);
#define WinApi_SetThreadPriority(hThread, nPriority)	SetThreadPriority(hThread, nPriority)
__EXTERN INTEGER __CALL SetThreadPriority(INTEGER hThread, INTEGER nPriority);
#define WinApi_SetThreadPriorityBoost(hThread, bDisablePriorityBoost)	SetThreadPriorityBoost(hThread, bDisablePriorityBoost)
__EXTERN INTEGER __CALL SetThreadPriorityBoost(INTEGER hThread, INTEGER bDisablePriorityBoost);
#define WinApi_SetThreadToken(Thread, Token)	SetThreadToken(Thread, Token)
__EXTERN INTEGER __CALL SetThreadToken(INTEGER *Thread, INTEGER Token);
#define WinApi_SetTimeZoneInformation(lpTimeZoneInformation, lpTimeZoneInformation__typ)	SetTimeZoneInformation(lpTimeZoneInformation)
__EXTERN INTEGER __CALL SetTimeZoneInformation(WinApi_TIME_ZONE_INFORMATION *lpTimeZoneInformation);
#define WinApi_SetTimer(hWnd, nIDEvent, uElapse, lpTimerFunc)	SetTimer(hWnd, nIDEvent, uElapse, lpTimerFunc)
__EXTERN INTEGER __CALL SetTimer(INTEGER hWnd, INTEGER nIDEvent, INTEGER uElapse, WinApi_TIMERPROC lpTimerFunc);
#define WinApi_SetTokenInformation(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength)	SetTokenInformation(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength)
__EXTERN INTEGER __CALL SetTokenInformation(INTEGER TokenHandle, INTEGER TokenInformationClass, INTEGER TokenInformation, INTEGER TokenInformationLength);
#define WinApi_SetUnhandledExceptionFilter(lpTopLevelExceptionFilter)	SetUnhandledExceptionFilter(lpTopLevelExceptionFilter)
__EXTERN WinApi_TOP_LEVEL_EXCEPTION_FILTER __CALL SetUnhandledExceptionFilter(WinApi_TOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);
#define WinApi_SetUserObjectInformation(hObj, nIndex, pvInfo, nLength)	SetUserObjectInformationA(hObj, nIndex, pvInfo, nLength)
#define WinApi_SetUserObjectInformationA(hObj, nIndex, pvInfo, nLength)	SetUserObjectInformationA(hObj, nIndex, pvInfo, nLength)
__EXTERN INTEGER __CALL SetUserObjectInformationA(INTEGER hObj, INTEGER nIndex, INTEGER pvInfo, INTEGER nLength);
#define WinApi_SetUserObjectInformationW(hObj, nIndex, pvInfo, nLength)	SetUserObjectInformationW(hObj, nIndex, pvInfo, nLength)
__EXTERN INTEGER __CALL SetUserObjectInformationW(INTEGER hObj, INTEGER nIndex, INTEGER pvInfo, INTEGER nLength);
#define WinApi_SetUserObjectSecurity(hObj, pSIRequested, pSID)	SetUserObjectSecurity(hObj, pSIRequested, pSID)
__EXTERN INTEGER __CALL SetUserObjectSecurity(INTEGER hObj, INTEGER *pSIRequested, INTEGER pSID);
#define WinApi_SetViewportExtEx(p0, p1, p2, p3, p3__typ)	SetViewportExtEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetViewportExtEx(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_SIZE *p3);
#define WinApi_SetViewportOrgEx(p0, p1, p2, p3, p3__typ)	SetViewportOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetViewportOrgEx(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_POINT *p3);
#define WinApi_SetVolumeLabel(lpRootPathName, lpVolumeName)	SetVolumeLabelA(lpRootPathName, lpVolumeName)
#define WinApi_SetVolumeLabelA(lpRootPathName, lpVolumeName)	SetVolumeLabelA(lpRootPathName, lpVolumeName)
__EXTERN INTEGER __CALL SetVolumeLabelA(WinApi_PtrSTR lpRootPathName, WinApi_PtrSTR lpVolumeName);
#define WinApi_SetVolumeLabelW(lpRootPathName, lpVolumeName)	SetVolumeLabelW(lpRootPathName, lpVolumeName)
__EXTERN INTEGER __CALL SetVolumeLabelW(WinApi_PtrWSTR lpRootPathName, WinApi_PtrWSTR lpVolumeName);
#define WinApi_SetWaitableTimer(hTimer, lpDueTime, lPeriod, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume)	SetWaitableTimer(hTimer, lpDueTime, lPeriod, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume)
__EXTERN INTEGER __CALL SetWaitableTimer(INTEGER hTimer, LONGINT *lpDueTime, INTEGER lPeriod, WinApi_TIMERAPCROUTINE pfnCompletionRoutine, INTEGER lpArgToCompletionRoutine, INTEGER fResume);
#define WinApi_SetWinMetaFileBits(p0, p1, p2, p3, p3__typ)	SetWinMetaFileBits(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetWinMetaFileBits(INTEGER p0, CHAR *p1, INTEGER p2, WinApi_METAFILEPICT *p3);
#define WinApi_SetWindowContextHelpId(p0, p1)	SetWindowContextHelpId(p0, p1)
__EXTERN INTEGER __CALL SetWindowContextHelpId(INTEGER p0, INTEGER p1);
#define WinApi_SetWindowExtEx(p0, p1, p2, p3, p3__typ)	SetWindowExtEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetWindowExtEx(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_SIZE *p3);
#define WinApi_SetWindowLong(hWnd, nIndex, dwNewLong)	SetWindowLongA(hWnd, nIndex, dwNewLong)
#define WinApi_SetWindowLongA(hWnd, nIndex, dwNewLong)	SetWindowLongA(hWnd, nIndex, dwNewLong)
__EXTERN INTEGER __CALL SetWindowLongA(INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong);
#define WinApi_SetWindowLongW(hWnd, nIndex, dwNewLong)	SetWindowLongW(hWnd, nIndex, dwNewLong)
__EXTERN INTEGER __CALL SetWindowLongW(INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong);
#define WinApi_SetWindowOrgEx(p0, p1, p2, p3, p3__typ)	SetWindowOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL SetWindowOrgEx(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_POINT *p3);
#define WinApi_SetWindowPlacement(hWnd, lpwndpl, lpwndpl__typ)	SetWindowPlacement(hWnd, lpwndpl)
__EXTERN INTEGER __CALL SetWindowPlacement(INTEGER hWnd, WinApi_WINDOWPLACEMENT *lpwndpl);
#define WinApi_SetWindowPos(hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags)	SetWindowPos(hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags)
__EXTERN INTEGER __CALL SetWindowPos(INTEGER hWnd, INTEGER hWndInsertAfter, INTEGER X, INTEGER Y, INTEGER cx, INTEGER cy, SET uFlags);
#define WinApi_SetWindowRgn(hWnd, hRgn, bRedraw)	SetWindowRgn(hWnd, hRgn, bRedraw)
__EXTERN INTEGER __CALL SetWindowRgn(INTEGER hWnd, INTEGER hRgn, INTEGER bRedraw);
#define WinApi_SetWindowText(hWnd, lpString)	SetWindowTextA(hWnd, lpString)
#define WinApi_SetWindowTextA(hWnd, lpString)	SetWindowTextA(hWnd, lpString)
__EXTERN INTEGER __CALL SetWindowTextA(INTEGER hWnd, WinApi_PtrSTR lpString);
#define WinApi_SetWindowTextW(hWnd, lpString)	SetWindowTextW(hWnd, lpString)
__EXTERN INTEGER __CALL SetWindowTextW(INTEGER hWnd, WinApi_PtrWSTR lpString);
#define WinApi_SetWindowWord(hWnd, nIndex, wNewWord)	SetWindowWord(hWnd, nIndex, wNewWord)
__EXTERN SHORTINT __CALL SetWindowWord(INTEGER hWnd, INTEGER nIndex, SHORTINT wNewWord);
#define WinApi_SetWindowsHook(nFilterType, pfnFilterProc)	SetWindowsHookA(nFilterType, pfnFilterProc)
#define WinApi_SetWindowsHookA(nFilterType, pfnFilterProc)	SetWindowsHookA(nFilterType, pfnFilterProc)
__EXTERN WinApi_HOOKPROC __CALL SetWindowsHookA(INTEGER nFilterType, WinApi_HOOKPROC pfnFilterProc);
#define WinApi_SetWindowsHookEx(idHook, lpfn, hmod, dwThreadId)	SetWindowsHookExA(idHook, lpfn, hmod, dwThreadId)
#define WinApi_SetWindowsHookExA(idHook, lpfn, hmod, dwThreadId)	SetWindowsHookExA(idHook, lpfn, hmod, dwThreadId)
__EXTERN INTEGER __CALL SetWindowsHookExA(INTEGER idHook, WinApi_HOOKPROC lpfn, INTEGER hmod, INTEGER dwThreadId);
#define WinApi_SetWindowsHookExW(idHook, lpfn, hmod, dwThreadId)	SetWindowsHookExW(idHook, lpfn, hmod, dwThreadId)
__EXTERN INTEGER __CALL SetWindowsHookExW(INTEGER idHook, WinApi_HOOKPROC lpfn, INTEGER hmod, INTEGER dwThreadId);
#define WinApi_SetWindowsHookW(nFilterType, pfnFilterProc)	SetWindowsHookW(nFilterType, pfnFilterProc)
__EXTERN WinApi_HOOKPROC __CALL SetWindowsHookW(INTEGER nFilterType, WinApi_HOOKPROC pfnFilterProc);
#define WinApi_SetWorldTransform(p0, p1, p1__typ)	SetWorldTransform(p0, p1)
__EXTERN INTEGER __CALL SetWorldTransform(INTEGER p0, WinApi_XFORM *p1);
#define WinApi_SetupComm(hFile, dwInQueue, dwOutQueue)	SetupComm(hFile, dwInQueue, dwOutQueue)
__EXTERN INTEGER __CALL SetupComm(INTEGER hFile, INTEGER dwInQueue, INTEGER dwOutQueue);
#define WinApi_ShellAbout(hWnd, szApp, szOtherStuff, hIcon)	ShellAboutA(hWnd, szApp, szOtherStuff, hIcon)
#define WinApi_ShellAboutA(hWnd, szApp, szOtherStuff, hIcon)	ShellAboutA(hWnd, szApp, szOtherStuff, hIcon)
__EXTERN INTEGER __CALL ShellAboutA(INTEGER hWnd, WinApi_PtrSTR szApp, WinApi_PtrSTR szOtherStuff, INTEGER hIcon);
#define WinApi_ShellAboutW(hWnd, szApp, szOtherStuff, hIcon)	ShellAboutW(hWnd, szApp, szOtherStuff, hIcon)
__EXTERN INTEGER __CALL ShellAboutW(INTEGER hWnd, WinApi_PtrWSTR szApp, WinApi_PtrWSTR szOtherStuff, INTEGER hIcon);
#define WinApi_ShellExecute(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)	ShellExecuteA(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)
#define WinApi_ShellExecuteA(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)	ShellExecuteA(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)
__EXTERN INTEGER __CALL ShellExecuteA(INTEGER hwnd, WinApi_PtrSTR lpOperation, WinApi_PtrSTR lpFile, WinApi_PtrSTR lpParameters, WinApi_PtrSTR lpDirectory, INTEGER nShowCmd);
#define WinApi_ShellExecuteEx(lpExecInfo, lpExecInfo__typ)	ShellExecuteExA(lpExecInfo)
#define WinApi_ShellExecuteExA(lpExecInfo, lpExecInfo__typ)	ShellExecuteExA(lpExecInfo)
__EXTERN INTEGER __CALL ShellExecuteExA(WinApi_SHELLEXECUTEINFOA *lpExecInfo);
#define WinApi_ShellExecuteExW(lpExecInfo, lpExecInfo__typ)	ShellExecuteExW(lpExecInfo)
__EXTERN INTEGER __CALL ShellExecuteExW(WinApi_SHELLEXECUTEINFOW *lpExecInfo);
#define WinApi_ShellExecuteW(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)	ShellExecuteW(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)
__EXTERN INTEGER __CALL ShellExecuteW(INTEGER hwnd, WinApi_PtrWSTR lpOperation, WinApi_PtrWSTR lpFile, WinApi_PtrWSTR lpParameters, WinApi_PtrWSTR lpDirectory, INTEGER nShowCmd);
#define WinApi_Shell_NotifyIcon(dwMessage, lpData, lpData__typ)	Shell_NotifyIconA(dwMessage, lpData)
#define WinApi_Shell_NotifyIconA(dwMessage, lpData, lpData__typ)	Shell_NotifyIconA(dwMessage, lpData)
__EXTERN INTEGER __CALL Shell_NotifyIconA(INTEGER dwMessage, WinApi_NOTIFYICONDATAA *lpData);
#define WinApi_Shell_NotifyIconW(dwMessage, lpData, lpData__typ)	Shell_NotifyIconW(dwMessage, lpData)
__EXTERN INTEGER __CALL Shell_NotifyIconW(INTEGER dwMessage, WinApi_NOTIFYICONDATAW *lpData);
#define WinApi_ShowCaret(hWnd)	ShowCaret(hWnd)
__EXTERN INTEGER __CALL ShowCaret(INTEGER hWnd);
#define WinApi_ShowCursor(bShow)	ShowCursor(bShow)
__EXTERN INTEGER __CALL ShowCursor(INTEGER bShow);
#define WinApi_ShowOwnedPopups(hWnd, fShow)	ShowOwnedPopups(hWnd, fShow)
__EXTERN INTEGER __CALL ShowOwnedPopups(INTEGER hWnd, INTEGER fShow);
#define WinApi_ShowScrollBar(hWnd, wBar, bShow)	ShowScrollBar(hWnd, wBar, bShow)
__EXTERN INTEGER __CALL ShowScrollBar(INTEGER hWnd, INTEGER wBar, INTEGER bShow);
#define WinApi_ShowWindow(hWnd, nCmdShow)	ShowWindow(hWnd, nCmdShow)
__EXTERN INTEGER __CALL ShowWindow(INTEGER hWnd, INTEGER nCmdShow);
#define WinApi_ShowWindowAsync(hWnd, nCmdShow)	ShowWindowAsync(hWnd, nCmdShow)
__EXTERN INTEGER __CALL ShowWindowAsync(INTEGER hWnd, INTEGER nCmdShow);
#define WinApi_SignalObjectAndWait(hObjectToSignal, hObjectToWaitOn, dwMilliseconds, bAlertable)	SignalObjectAndWait(hObjectToSignal, hObjectToWaitOn, dwMilliseconds, bAlertable)
__EXTERN INTEGER __CALL SignalObjectAndWait(INTEGER hObjectToSignal, INTEGER hObjectToWaitOn, INTEGER dwMilliseconds, INTEGER bAlertable);
#define WinApi_SizeofResource(hModule, hResInfo)	SizeofResource(hModule, hResInfo)
__EXTERN INTEGER __CALL SizeofResource(INTEGER hModule, INTEGER hResInfo);
#define WinApi_Sleep(dwMilliseconds)	Sleep(dwMilliseconds)
__EXTERN void __CALL Sleep(INTEGER dwMilliseconds);
#define WinApi_SleepEx(dwMilliseconds, bAlertable)	SleepEx(dwMilliseconds, bAlertable)
__EXTERN INTEGER __CALL SleepEx(INTEGER dwMilliseconds, INTEGER bAlertable);
#define WinApi_StartDoc(p0, p1, p1__typ)	StartDocA(p0, p1)
#define WinApi_StartDocA(p0, p1, p1__typ)	StartDocA(p0, p1)
__EXTERN INTEGER __CALL StartDocA(INTEGER p0, WinApi_DOCINFOA *p1);
#define WinApi_StartDocPrinter(hPrinter, Level, pDocInfo)	StartDocPrinterA(hPrinter, Level, pDocInfo)
#define WinApi_StartDocPrinterA(hPrinter, Level, pDocInfo)	StartDocPrinterA(hPrinter, Level, pDocInfo)
__EXTERN INTEGER __CALL StartDocPrinterA(INTEGER hPrinter, INTEGER Level, CHAR *pDocInfo);
#define WinApi_StartDocPrinterW(hPrinter, Level, pDocInfo)	StartDocPrinterW(hPrinter, Level, pDocInfo)
__EXTERN INTEGER __CALL StartDocPrinterW(INTEGER hPrinter, INTEGER Level, CHAR *pDocInfo);
#define WinApi_StartDocW(p0, p1, p1__typ)	StartDocW(p0, p1)
__EXTERN INTEGER __CALL StartDocW(INTEGER p0, WinApi_DOCINFOW *p1);
#define WinApi_StartPage(p0)	StartPage(p0)
__EXTERN INTEGER __CALL StartPage(INTEGER p0);
#define WinApi_StartPagePrinter(hPrinter)	StartPagePrinter(hPrinter)
__EXTERN INTEGER __CALL StartPagePrinter(INTEGER hPrinter);
#define WinApi_StartService(hService, dwNumServiceArgs, lpServiceArgVectors)	StartServiceA(hService, dwNumServiceArgs, lpServiceArgVectors)
#define WinApi_StartServiceA(hService, dwNumServiceArgs, lpServiceArgVectors)	StartServiceA(hService, dwNumServiceArgs, lpServiceArgVectors)
__EXTERN INTEGER __CALL StartServiceA(INTEGER hService, INTEGER dwNumServiceArgs, WinApi_PtrSTR *lpServiceArgVectors);
#define WinApi_StartServiceCtrlDispatcher(lpServiceStartTable, lpServiceStartTable__typ)	StartServiceCtrlDispatcherA(lpServiceStartTable)
#define WinApi_StartServiceCtrlDispatcherA(lpServiceStartTable, lpServiceStartTable__typ)	StartServiceCtrlDispatcherA(lpServiceStartTable)
__EXTERN INTEGER __CALL StartServiceCtrlDispatcherA(WinApi_SERVICE_TABLE_ENTRYA *lpServiceStartTable);
#define WinApi_StartServiceCtrlDispatcherW(lpServiceStartTable, lpServiceStartTable__typ)	StartServiceCtrlDispatcherW(lpServiceStartTable)
__EXTERN INTEGER __CALL StartServiceCtrlDispatcherW(WinApi_SERVICE_TABLE_ENTRYW *lpServiceStartTable);
#define WinApi_StartServiceW(hService, dwNumServiceArgs, lpServiceArgVectors)	StartServiceW(hService, dwNumServiceArgs, lpServiceArgVectors)
__EXTERN INTEGER __CALL StartServiceW(INTEGER hService, INTEGER dwNumServiceArgs, struct {
	LONGINT len[1];
	WinApi_PtrWSTR data[1];
} *lpServiceArgVectors);
#define WinApi_StretchBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10)	StretchBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10)
__EXTERN INTEGER __CALL StretchBlt(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10);
#define WinApi_StretchDIBits(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p10__typ, p11, p12)	StretchDIBits(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)
__EXTERN INTEGER __CALL StretchDIBits(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, WinApi_BITMAPINFO *p10, INTEGER p11, INTEGER p12);
#define WinApi_StrokeAndFillPath(p0)	StrokeAndFillPath(p0)
__EXTERN INTEGER __CALL StrokeAndFillPath(INTEGER p0);
#define WinApi_StrokePath(p0)	StrokePath(p0)
__EXTERN INTEGER __CALL StrokePath(INTEGER p0);
#define WinApi_SubtractRect(lprcDst, lprcDst__typ, lprcSrc1, lprcSrc1__typ, lprcSrc2, lprcSrc2__typ)	SubtractRect(lprcDst, lprcSrc1, lprcSrc2)
__EXTERN INTEGER __CALL SubtractRect(WinApi_RECT *lprcDst, WinApi_RECT *lprcSrc1, WinApi_RECT *lprcSrc2);
#define WinApi_SuspendThread(hThread)	SuspendThread(hThread)
__EXTERN INTEGER __CALL SuspendThread(INTEGER hThread);
#define WinApi_SwapBuffers(p0)	SwapBuffers(p0)
__EXTERN INTEGER __CALL SwapBuffers(INTEGER p0);
#define WinApi_SwapMouseButton(fSwap)	SwapMouseButton(fSwap)
__EXTERN INTEGER __CALL SwapMouseButton(INTEGER fSwap);
#define WinApi_SwitchDesktop(hDesktop)	SwitchDesktop(hDesktop)
__EXTERN INTEGER __CALL SwitchDesktop(INTEGER hDesktop);
#define WinApi_SwitchToFiber(lpFiber)	SwitchToFiber(lpFiber)
__EXTERN void __CALL SwitchToFiber(INTEGER lpFiber);
#define WinApi_SystemParametersInfo(uiAction, uiParam, pvParam, fWinIni)	SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni)
#define WinApi_SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni)	SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni)
__EXTERN INTEGER __CALL SystemParametersInfoA(INTEGER uiAction, INTEGER uiParam, INTEGER pvParam, INTEGER fWinIni);
#define WinApi_SystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni)	SystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni)
__EXTERN INTEGER __CALL SystemParametersInfoW(INTEGER uiAction, INTEGER uiParam, INTEGER pvParam, INTEGER fWinIni);
#define WinApi_SystemTimeToFileTime(lpSystemTime, lpSystemTime__typ, lpFileTime, lpFileTime__typ)	SystemTimeToFileTime(lpSystemTime, lpFileTime)
__EXTERN INTEGER __CALL SystemTimeToFileTime(WinApi_SYSTEMTIME *lpSystemTime, WinApi_FILETIME *lpFileTime);
#define WinApi_SystemTimeToTzSpecificLocalTime(lpTimeZoneInformation, lpTimeZoneInformation__typ, lpUniversalTime, lpUniversalTime__typ, lpLocalTime, lpLocalTime__typ)	SystemTimeToTzSpecificLocalTime(lpTimeZoneInformation, lpUniversalTime, lpLocalTime)
__EXTERN INTEGER __CALL SystemTimeToTzSpecificLocalTime(WinApi_TIME_ZONE_INFORMATION *lpTimeZoneInformation, WinApi_SYSTEMTIME *lpUniversalTime, WinApi_SYSTEMTIME *lpLocalTime);
#define WinApi_TabbedTextOut(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)	TabbedTextOutA(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)
#define WinApi_TabbedTextOutA(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)	TabbedTextOutA(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)
__EXTERN INTEGER __CALL TabbedTextOutA(INTEGER hDC, INTEGER X, INTEGER Y, WinApi_PtrSTR lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions, INTEGER nTabOrigin);
#define WinApi_TabbedTextOutW(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)	TabbedTextOutW(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)
__EXTERN INTEGER __CALL TabbedTextOutW(INTEGER hDC, INTEGER X, INTEGER Y, WinApi_PtrWSTR lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions, INTEGER nTabOrigin);
#define WinApi_TerminateProcess(hProcess, uExitCode)	TerminateProcess(hProcess, uExitCode)
__EXTERN INTEGER __CALL TerminateProcess(INTEGER hProcess, INTEGER uExitCode);
#define WinApi_TerminateThread(hThread, dwExitCode)	TerminateThread(hThread, dwExitCode)
__EXTERN INTEGER __CALL TerminateThread(INTEGER hThread, INTEGER dwExitCode);
#define WinApi_TextOut(p0, p1, p2, p3, p4)	TextOutA(p0, p1, p2, p3, p4)
#define WinApi_TextOutA(p0, p1, p2, p3, p4)	TextOutA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL TextOutA(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_PtrSTR p3, INTEGER p4);
#define WinApi_TextOutW(p0, p1, p2, p3, p4)	TextOutW(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL TextOutW(INTEGER p0, INTEGER p1, INTEGER p2, WinApi_PtrWSTR p3, INTEGER p4);
#define WinApi_TileWindows(hwndParent, wHow, lpRect, lpRect__typ, cKids, lpKids)	TileWindows(hwndParent, wHow, lpRect, cKids, lpKids)
__EXTERN SHORTINT __CALL TileWindows(INTEGER hwndParent, INTEGER wHow, WinApi_RECT *lpRect, INTEGER cKids, INTEGER *lpKids);
#define WinApi_TlsAlloc()	TlsAlloc()
__EXTERN INTEGER __CALL TlsAlloc(void);
#define WinApi_TlsFree(dwTlsIndex)	TlsFree(dwTlsIndex)
__EXTERN INTEGER __CALL TlsFree(INTEGER dwTlsIndex);
#define WinApi_TlsGetValue(dwTlsIndex)	TlsGetValue(dwTlsIndex)
__EXTERN INTEGER __CALL TlsGetValue(INTEGER dwTlsIndex);
#define WinApi_TlsSetValue(dwTlsIndex, lpTlsValue)	TlsSetValue(dwTlsIndex, lpTlsValue)
__EXTERN INTEGER __CALL TlsSetValue(INTEGER dwTlsIndex, INTEGER lpTlsValue);
#define WinApi_ToAscii(uVirtKey, uScanCode, lpKeyState, lpChar, uFlags)	ToAscii(uVirtKey, uScanCode, lpKeyState, lpChar, uFlags)
__EXTERN INTEGER __CALL ToAscii(INTEGER uVirtKey, INTEGER uScanCode, CHAR *lpKeyState, SHORTINT *lpChar, SET uFlags);
#define WinApi_ToAsciiEx(uVirtKey, uScanCode, lpKeyState, lpChar, uFlags, dwhkl)	ToAsciiEx(uVirtKey, uScanCode, lpKeyState, lpChar, uFlags, dwhkl)
__EXTERN INTEGER __CALL ToAsciiEx(INTEGER uVirtKey, INTEGER uScanCode, CHAR *lpKeyState, SHORTINT *lpChar, SET uFlags, INTEGER dwhkl);
#define WinApi_ToUnicode(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags)	ToUnicode(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags)
__EXTERN INTEGER __CALL ToUnicode(INTEGER wVirtKey, INTEGER wScanCode, CHAR *lpKeyState, WinApi_PtrWSTR pwszBuff, INTEGER cchBuff, INTEGER wFlags);
#define WinApi_ToUnicodeEx(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags, dwhkl)	ToUnicodeEx(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags, dwhkl)
__EXTERN INTEGER __CALL ToUnicodeEx(INTEGER wVirtKey, INTEGER wScanCode, CHAR *lpKeyState, WinApi_PtrWSTR pwszBuff, INTEGER cchBuff, INTEGER wFlags, INTEGER dwhkl);
#define WinApi_TrackPopupMenu(hMenu, uFlags, x, y, nReserved, hWnd, prcRect, prcRect__typ)	TrackPopupMenu(hMenu, uFlags, x, y, nReserved, hWnd, prcRect)
__EXTERN INTEGER __CALL TrackPopupMenu(INTEGER hMenu, SET uFlags, INTEGER x, INTEGER y, INTEGER nReserved, INTEGER hWnd, WinApi_RECT *prcRect);
#define WinApi_TrackPopupMenuEx(p0, p1, p2, p3, p4, p5, p5__typ)	TrackPopupMenuEx(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL TrackPopupMenuEx(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinApi_TPMPARAMS *p5);
#define WinApi_TransactNamedPipe(hNamedPipe, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, lpOverlapped, lpOverlapped__typ)	TransactNamedPipe(hNamedPipe, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, lpOverlapped)
__EXTERN INTEGER __CALL TransactNamedPipe(INTEGER hNamedPipe, INTEGER lpInBuffer, INTEGER nInBufferSize, INTEGER lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, WinApi_OVERLAPPED *lpOverlapped);
#define WinApi_TranslateAccelerator(hWnd, hAccTable, lpMsg, lpMsg__typ)	TranslateAcceleratorA(hWnd, hAccTable, lpMsg)
#define WinApi_TranslateAcceleratorA(hWnd, hAccTable, lpMsg, lpMsg__typ)	TranslateAcceleratorA(hWnd, hAccTable, lpMsg)
__EXTERN INTEGER __CALL TranslateAcceleratorA(INTEGER hWnd, INTEGER hAccTable, WinApi_MSG *lpMsg);
#define WinApi_TranslateAcceleratorW(hWnd, hAccTable, lpMsg, lpMsg__typ)	TranslateAcceleratorW(hWnd, hAccTable, lpMsg)
__EXTERN INTEGER __CALL TranslateAcceleratorW(INTEGER hWnd, INTEGER hAccTable, WinApi_MSG *lpMsg);
#define WinApi_TranslateCharsetInfo(lpSrc, lpCs, lpCs__typ, dwFlags)	TranslateCharsetInfo(lpSrc, lpCs, dwFlags)
__EXTERN INTEGER __CALL TranslateCharsetInfo(INTEGER *lpSrc, WinApi_CHARSETINFO *lpCs, SET dwFlags);
#define WinApi_TranslateMDISysAccel(hWndClient, lpMsg, lpMsg__typ)	TranslateMDISysAccel(hWndClient, lpMsg)
__EXTERN INTEGER __CALL TranslateMDISysAccel(INTEGER hWndClient, WinApi_MSG *lpMsg);
#define WinApi_TranslateMessage(lpMsg, lpMsg__typ)	TranslateMessage(lpMsg)
__EXTERN INTEGER __CALL TranslateMessage(WinApi_MSG *lpMsg);
#define WinApi_TransmitCommChar(hFile, cChar)	TransmitCommChar(hFile, cChar)
__EXTERN INTEGER __CALL TransmitCommChar(INTEGER hFile, CHAR cChar);
#define WinApi_TryEnterCriticalSection(lpCriticalSection, lpCriticalSection__typ)	TryEnterCriticalSection(lpCriticalSection)
__EXTERN INTEGER __CALL TryEnterCriticalSection(WinApi_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinApi_UnhandledExceptionFilter(ExceptionInfo, ExceptionInfo__typ)	UnhandledExceptionFilter(ExceptionInfo)
__EXTERN INTEGER __CALL UnhandledExceptionFilter(WinApi_EXCEPTION_POINTERS *ExceptionInfo);
#define WinApi_UnhookWindowsHook(nCode, pfnFilterProc)	UnhookWindowsHook(nCode, pfnFilterProc)
__EXTERN INTEGER __CALL UnhookWindowsHook(INTEGER nCode, WinApi_HOOKPROC pfnFilterProc);
#define WinApi_UnhookWindowsHookEx(hhk)	UnhookWindowsHookEx(hhk)
__EXTERN INTEGER __CALL UnhookWindowsHookEx(INTEGER hhk);
#define WinApi_UnionRect(lprcDst, lprcDst__typ, lprcSrc1, lprcSrc1__typ, lprcSrc2, lprcSrc2__typ)	UnionRect(lprcDst, lprcSrc1, lprcSrc2)
__EXTERN INTEGER __CALL UnionRect(WinApi_RECT *lprcDst, WinApi_RECT *lprcSrc1, WinApi_RECT *lprcSrc2);
#define WinApi_UnloadKeyboardLayout(hkl)	UnloadKeyboardLayout(hkl)
__EXTERN INTEGER __CALL UnloadKeyboardLayout(INTEGER hkl);
#define WinApi_UnlockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh)	UnlockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh)
__EXTERN INTEGER __CALL UnlockFile(INTEGER hFile, INTEGER dwFileOffsetLow, INTEGER dwFileOffsetHigh, INTEGER nNumberOfBytesToUnlockLow, INTEGER nNumberOfBytesToUnlockHigh);
#define WinApi_UnlockFileEx(hFile, dwReserved, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh, lpOverlapped, lpOverlapped__typ)	UnlockFileEx(hFile, dwReserved, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh, lpOverlapped)
__EXTERN INTEGER __CALL UnlockFileEx(INTEGER hFile, INTEGER dwReserved, INTEGER nNumberOfBytesToUnlockLow, INTEGER nNumberOfBytesToUnlockHigh, WinApi_OVERLAPPED *lpOverlapped);
#define WinApi_UnlockServiceDatabase(ScLock)	UnlockServiceDatabase(ScLock)
__EXTERN INTEGER __CALL UnlockServiceDatabase(INTEGER ScLock);
#define WinApi_UnmapViewOfFile(lpBaseAddress)	UnmapViewOfFile(lpBaseAddress)
__EXTERN INTEGER __CALL UnmapViewOfFile(INTEGER lpBaseAddress);
#define WinApi_UnpackDDElParam(msg, lParam, puiLo, puiHi)	UnpackDDElParam(msg, lParam, puiLo, puiHi)
__EXTERN INTEGER __CALL UnpackDDElParam(INTEGER msg, INTEGER lParam, INTEGER *puiLo, INTEGER *puiHi);
#define WinApi_UnrealizeObject(p0)	UnrealizeObject(p0)
__EXTERN INTEGER __CALL UnrealizeObject(INTEGER p0);
#define WinApi_UnregisterClass(lpClassName, hInstance)	UnregisterClassA(lpClassName, hInstance)
#define WinApi_UnregisterClassA(lpClassName, hInstance)	UnregisterClassA(lpClassName, hInstance)
__EXTERN INTEGER __CALL UnregisterClassA(WinApi_PtrSTR lpClassName, INTEGER hInstance);
#define WinApi_UnregisterClassW(lpClassName, hInstance)	UnregisterClassW(lpClassName, hInstance)
__EXTERN INTEGER __CALL UnregisterClassW(WinApi_PtrWSTR lpClassName, INTEGER hInstance);
#define WinApi_UnregisterHotKey(hWnd, id)	UnregisterHotKey(hWnd, id)
__EXTERN INTEGER __CALL UnregisterHotKey(INTEGER hWnd, INTEGER id);
#define WinApi_UpdateColors(p0)	UpdateColors(p0)
__EXTERN INTEGER __CALL UpdateColors(INTEGER p0);
#define WinApi_UpdateResource(hUpdate, lpType, lpName, wLanguage, lpData, cbData)	UpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cbData)
#define WinApi_UpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cbData)	UpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cbData)
__EXTERN INTEGER __CALL UpdateResourceA(INTEGER hUpdate, WinApi_PtrSTR lpType, WinApi_PtrSTR lpName, SHORTINT wLanguage, INTEGER lpData, INTEGER cbData);
#define WinApi_UpdateResourceW(hUpdate, lpType, lpName, wLanguage, lpData, cbData)	UpdateResourceW(hUpdate, lpType, lpName, wLanguage, lpData, cbData)
__EXTERN INTEGER __CALL UpdateResourceW(INTEGER hUpdate, WinApi_PtrWSTR lpType, WinApi_PtrWSTR lpName, SHORTINT wLanguage, INTEGER lpData, INTEGER cbData);
#define WinApi_UpdateWindow(hWnd)	UpdateWindow(hWnd)
__EXTERN INTEGER __CALL UpdateWindow(INTEGER hWnd);
#define WinApi_ValidateRect(hWnd, lpRect, lpRect__typ)	ValidateRect(hWnd, lpRect)
__EXTERN INTEGER __CALL ValidateRect(INTEGER hWnd, WinApi_RECT *lpRect);
#define WinApi_ValidateRgn(hWnd, hRgn)	ValidateRgn(hWnd, hRgn)
__EXTERN INTEGER __CALL ValidateRgn(INTEGER hWnd, INTEGER hRgn);
#define WinApi_VerFindFile(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)	VerFindFileA(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)
#define WinApi_VerFindFileA(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)	VerFindFileA(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)
__EXTERN SET __CALL VerFindFileA(SET uFlags, WinApi_PtrSTR szFileName, WinApi_PtrSTR szWinDir, WinApi_PtrSTR szAppDir, WinApi_PtrSTR szCurDir, INTEGER *lpuCurDirLen, WinApi_PtrSTR szDestDir, INTEGER *lpuDestDirLen);
#define WinApi_VerFindFileW(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)	VerFindFileW(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)
__EXTERN SET __CALL VerFindFileW(SET uFlags, WinApi_PtrWSTR szFileName, WinApi_PtrWSTR szWinDir, WinApi_PtrWSTR szAppDir, WinApi_PtrWSTR szCurDir, INTEGER *lpuCurDirLen, WinApi_PtrWSTR szDestDir, INTEGER *lpuDestDirLen);
#define WinApi_VerInstallFile(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)	VerInstallFileA(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)
#define WinApi_VerInstallFileA(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)	VerInstallFileA(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)
__EXTERN SET __CALL VerInstallFileA(SET uFlags, WinApi_PtrSTR szSrcFileName, WinApi_PtrSTR szDestFileName, WinApi_PtrSTR szSrcDir, WinApi_PtrSTR szDestDir, WinApi_PtrSTR szCurDir, WinApi_PtrSTR szTmpFile, INTEGER *lpuTmpFileLen);
#define WinApi_VerInstallFileW(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)	VerInstallFileW(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)
__EXTERN SET __CALL VerInstallFileW(SET uFlags, WinApi_PtrWSTR szSrcFileName, WinApi_PtrWSTR szDestFileName, WinApi_PtrWSTR szSrcDir, WinApi_PtrWSTR szDestDir, WinApi_PtrWSTR szCurDir, WinApi_PtrWSTR szTmpFile, INTEGER *lpuTmpFileLen);
#define WinApi_VerLanguageName(wLang, szLang, nSize)	VerLanguageNameA(wLang, szLang, nSize)
#define WinApi_VerLanguageNameA(wLang, szLang, nSize)	VerLanguageNameA(wLang, szLang, nSize)
__EXTERN INTEGER __CALL VerLanguageNameA(INTEGER wLang, WinApi_PtrSTR szLang, INTEGER nSize);
#define WinApi_VerLanguageNameW(wLang, szLang, nSize)	VerLanguageNameW(wLang, szLang, nSize)
__EXTERN INTEGER __CALL VerLanguageNameW(INTEGER wLang, WinApi_PtrWSTR szLang, INTEGER nSize);
#define WinApi_VerQueryValue(pBlock, lpSubBlock, lplpBuffer, puLen)	VerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen)
#define WinApi_VerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen)	VerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen)
__EXTERN INTEGER __CALL VerQueryValueA(INTEGER pBlock, WinApi_PtrSTR lpSubBlock, struct {
	LONGINT len[1];
	INTEGER data[1];
} *lplpBuffer, INTEGER *puLen);
#define WinApi_VerQueryValueW(pBlock, lpSubBlock, lplpBuffer, puLen)	VerQueryValueW(pBlock, lpSubBlock, lplpBuffer, puLen)
__EXTERN INTEGER __CALL VerQueryValueW(INTEGER pBlock, WinApi_PtrWSTR lpSubBlock, struct {
	LONGINT len[1];
	INTEGER data[1];
} *lplpBuffer, INTEGER *puLen);
#define WinApi_VirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect)	VirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect)
__EXTERN INTEGER __CALL VirtualAlloc(INTEGER lpAddress, INTEGER dwSize, SET flAllocationType, SET flProtect);
#define WinApi_VirtualFree(lpAddress, dwSize, dwFreeType)	VirtualFree(lpAddress, dwSize, dwFreeType)
__EXTERN INTEGER __CALL VirtualFree(INTEGER lpAddress, INTEGER dwSize, SET dwFreeType);
#define WinApi_VirtualLock(lpAddress, dwSize)	VirtualLock(lpAddress, dwSize)
__EXTERN INTEGER __CALL VirtualLock(INTEGER lpAddress, INTEGER dwSize);
#define WinApi_VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect)	VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect)
__EXTERN INTEGER __CALL VirtualProtect(INTEGER lpAddress, INTEGER dwSize, SET flNewProtect, INTEGER *lpflOldProtect);
#define WinApi_VirtualProtectEx(hProcess, lpAddress, dwSize, flNewProtect, lpflOldProtect)	VirtualProtectEx(hProcess, lpAddress, dwSize, flNewProtect, lpflOldProtect)
__EXTERN INTEGER __CALL VirtualProtectEx(INTEGER hProcess, INTEGER lpAddress, INTEGER dwSize, SET flNewProtect, INTEGER *lpflOldProtect);
#define WinApi_VirtualQuery(lpAddress, lpBuffer, lpBuffer__typ, dwLength)	VirtualQuery(lpAddress, lpBuffer, dwLength)
__EXTERN INTEGER __CALL VirtualQuery(INTEGER lpAddress, WinApi_MEMORY_BASIC_INFORMATION *lpBuffer, INTEGER dwLength);
#define WinApi_VirtualQueryEx(hProcess, lpAddress, lpBuffer, lpBuffer__typ, dwLength)	VirtualQueryEx(hProcess, lpAddress, lpBuffer, dwLength)
__EXTERN INTEGER __CALL VirtualQueryEx(INTEGER hProcess, INTEGER lpAddress, WinApi_MEMORY_BASIC_INFORMATION *lpBuffer, INTEGER dwLength);
#define WinApi_VirtualUnlock(lpAddress, dwSize)	VirtualUnlock(lpAddress, dwSize)
__EXTERN INTEGER __CALL VirtualUnlock(INTEGER lpAddress, INTEGER dwSize);
#define WinApi_VkKeyScan(ch)	VkKeyScanA(ch)
#define WinApi_VkKeyScanA(ch)	VkKeyScanA(ch)
__EXTERN SHORTINT __CALL VkKeyScanA(CHAR ch);
#define WinApi_VkKeyScanEx(ch, dwhkl)	VkKeyScanExA(ch, dwhkl)
#define WinApi_VkKeyScanExA(ch, dwhkl)	VkKeyScanExA(ch, dwhkl)
__EXTERN SHORTINT __CALL VkKeyScanExA(CHAR ch, INTEGER dwhkl);
#define WinApi_VkKeyScanExW(ch, dwhkl)	VkKeyScanExW(ch, dwhkl)
__EXTERN SHORTINT __CALL VkKeyScanExW(SHORTINT ch, INTEGER dwhkl);
#define WinApi_VkKeyScanW(ch)	VkKeyScanW(ch)
__EXTERN SHORTINT __CALL VkKeyScanW(SHORTINT ch);
#define WinApi_WaitCommEvent(hFile, lpEvtMask, lpOverlapped, lpOverlapped__typ)	WaitCommEvent(hFile, lpEvtMask, lpOverlapped)
__EXTERN INTEGER __CALL WaitCommEvent(INTEGER hFile, SET *lpEvtMask, WinApi_OVERLAPPED *lpOverlapped);
#define WinApi_WaitForDebugEvent(lpDebugEvent, lpDebugEvent__typ, dwMilliseconds)	WaitForDebugEvent(lpDebugEvent, dwMilliseconds)
__EXTERN INTEGER __CALL WaitForDebugEvent(WinApi_DEBUG_EVENT *lpDebugEvent, INTEGER dwMilliseconds);
#define WinApi_WaitForInputIdle(hProcess, dwMilliseconds)	WaitForInputIdle(hProcess, dwMilliseconds)
__EXTERN INTEGER __CALL WaitForInputIdle(INTEGER hProcess, INTEGER dwMilliseconds);
#define WinApi_WaitForMultipleObjects(nCount, lpHandles, bWaitAll, dwMilliseconds)	WaitForMultipleObjects(nCount, lpHandles, bWaitAll, dwMilliseconds)
__EXTERN INTEGER __CALL WaitForMultipleObjects(INTEGER nCount, INTEGER *lpHandles, INTEGER bWaitAll, INTEGER dwMilliseconds);
#define WinApi_WaitForMultipleObjectsEx(nCount, lpHandles, bWaitAll, dwMilliseconds, bAlertable)	WaitForMultipleObjectsEx(nCount, lpHandles, bWaitAll, dwMilliseconds, bAlertable)
__EXTERN INTEGER __CALL WaitForMultipleObjectsEx(INTEGER nCount, INTEGER *lpHandles, INTEGER bWaitAll, INTEGER dwMilliseconds, INTEGER bAlertable);
#define WinApi_WaitForPrinterChange(hPrinter, Flags)	WaitForPrinterChange(hPrinter, Flags)
__EXTERN INTEGER __CALL WaitForPrinterChange(INTEGER hPrinter, SET Flags);
#define WinApi_WaitForSingleObject(hHandle, dwMilliseconds)	WaitForSingleObject(hHandle, dwMilliseconds)
__EXTERN INTEGER __CALL WaitForSingleObject(INTEGER hHandle, INTEGER dwMilliseconds);
#define WinApi_WaitForSingleObjectEx(hHandle, dwMilliseconds, bAlertable)	WaitForSingleObjectEx(hHandle, dwMilliseconds, bAlertable)
__EXTERN INTEGER __CALL WaitForSingleObjectEx(INTEGER hHandle, INTEGER dwMilliseconds, INTEGER bAlertable);
#define WinApi_WaitMessage()	WaitMessage()
__EXTERN INTEGER __CALL WaitMessage(void);
#define WinApi_WaitNamedPipe(lpNamedPipeName, nTimeOut)	WaitNamedPipeA(lpNamedPipeName, nTimeOut)
#define WinApi_WaitNamedPipeA(lpNamedPipeName, nTimeOut)	WaitNamedPipeA(lpNamedPipeName, nTimeOut)
__EXTERN INTEGER __CALL WaitNamedPipeA(WinApi_PtrSTR lpNamedPipeName, INTEGER nTimeOut);
#define WinApi_WaitNamedPipeW(lpNamedPipeName, nTimeOut)	WaitNamedPipeW(lpNamedPipeName, nTimeOut)
__EXTERN INTEGER __CALL WaitNamedPipeW(WinApi_PtrWSTR lpNamedPipeName, INTEGER nTimeOut);
#define WinApi_WideCharToMultiByte(CodePage, dwFlags, lpWideCharStr, cchWideChar, lpMultiByteStr, cchMultiByte, lpDefaultChar, lpUsedDefaultChar)	WideCharToMultiByte(CodePage, dwFlags, lpWideCharStr, cchWideChar, lpMultiByteStr, cchMultiByte, lpDefaultChar, lpUsedDefaultChar)
__EXTERN INTEGER __CALL WideCharToMultiByte(INTEGER CodePage, SET dwFlags, WinApi_PtrWSTR lpWideCharStr, INTEGER cchWideChar, WinApi_PtrSTR lpMultiByteStr, INTEGER cchMultiByte, WinApi_PtrSTR lpDefaultChar, INTEGER *lpUsedDefaultChar);
#define WinApi_WidenPath(p0)	WidenPath(p0)
__EXTERN INTEGER __CALL WidenPath(INTEGER p0);
#define WinApi_WinExec(lpCmdLine, uCmdShow)	WinExec(lpCmdLine, uCmdShow)
__EXTERN INTEGER __CALL WinExec(WinApi_PtrSTR lpCmdLine, INTEGER uCmdShow);
#define WinApi_WinHelp(hWndMain, lpszHelp, uCommand, dwData)	WinHelpA(hWndMain, lpszHelp, uCommand, dwData)
#define WinApi_WinHelpA(hWndMain, lpszHelp, uCommand, dwData)	WinHelpA(hWndMain, lpszHelp, uCommand, dwData)
__EXTERN INTEGER __CALL WinHelpA(INTEGER hWndMain, WinApi_PtrSTR lpszHelp, INTEGER uCommand, INTEGER dwData);
#define WinApi_WinHelpW(hWndMain, lpszHelp, uCommand, dwData)	WinHelpW(hWndMain, lpszHelp, uCommand, dwData)
__EXTERN INTEGER __CALL WinHelpW(INTEGER hWndMain, WinApi_PtrWSTR lpszHelp, INTEGER uCommand, INTEGER dwData);
#define WinApi_WindowFromDC(hDC)	WindowFromDC(hDC)
__EXTERN INTEGER __CALL WindowFromDC(INTEGER hDC);
#define WinApi_WindowFromPoint(Point)	WindowFromPoint(Point)
__EXTERN INTEGER __CALL WindowFromPoint(WinApi_POINT Point);
#define WinApi_WriteConsole(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)	WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)
#define WinApi_WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)	WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)
__EXTERN INTEGER __CALL WriteConsoleA(INTEGER hConsoleOutput, INTEGER lpBuffer, INTEGER nNumberOfCharsToWrite, INTEGER *lpNumberOfCharsWritten, INTEGER lpReserved);
#define WinApi_WriteConsoleInput(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsWritten)	WriteConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)
#define WinApi_WriteConsoleInputA(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsWritten)	WriteConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)
__EXTERN INTEGER __CALL WriteConsoleInputA(INTEGER hConsoleInput, WinApi_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsWritten);
#define WinApi_WriteConsoleInputW(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsWritten)	WriteConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)
__EXTERN INTEGER __CALL WriteConsoleInputW(INTEGER hConsoleInput, WinApi_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsWritten);
#define WinApi_WriteConsoleOutput(hConsoleOutput, lpBuffer, lpBuffer__typ, dwBufferSize, dwBufferCoord, lpWriteRegion, lpWriteRegion__typ)	WriteConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)
#define WinApi_WriteConsoleOutputA(hConsoleOutput, lpBuffer, lpBuffer__typ, dwBufferSize, dwBufferCoord, lpWriteRegion, lpWriteRegion__typ)	WriteConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)
__EXTERN INTEGER __CALL WriteConsoleOutputA(INTEGER hConsoleOutput, WinApi_CHAR_INFO *lpBuffer, WinApi_COORD dwBufferSize, WinApi_COORD dwBufferCoord, WinApi_SMALL_RECT *lpWriteRegion);
#define WinApi_WriteConsoleOutputAttribute(hConsoleOutput, lpAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten)	WriteConsoleOutputAttribute(hConsoleOutput, lpAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten)
__EXTERN INTEGER __CALL WriteConsoleOutputAttribute(INTEGER hConsoleOutput, SHORTINT *lpAttribute, INTEGER nLength, WinApi_COORD dwWriteCoord, INTEGER *lpNumberOfAttrsWritten);
#define WinApi_WriteConsoleOutputCharacter(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	WriteConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
#define WinApi_WriteConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	WriteConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __CALL WriteConsoleOutputCharacterA(INTEGER hConsoleOutput, WinApi_PtrSTR lpCharacter, INTEGER nLength, WinApi_COORD dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
#define WinApi_WriteConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	WriteConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __CALL WriteConsoleOutputCharacterW(INTEGER hConsoleOutput, WinApi_PtrWSTR lpCharacter, INTEGER nLength, WinApi_COORD dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
#define WinApi_WriteConsoleOutputW(hConsoleOutput, lpBuffer, lpBuffer__typ, dwBufferSize, dwBufferCoord, lpWriteRegion, lpWriteRegion__typ)	WriteConsoleOutputW(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)
__EXTERN INTEGER __CALL WriteConsoleOutputW(INTEGER hConsoleOutput, WinApi_CHAR_INFO *lpBuffer, WinApi_COORD dwBufferSize, WinApi_COORD dwBufferCoord, WinApi_SMALL_RECT *lpWriteRegion);
#define WinApi_WriteConsoleW(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)	WriteConsoleW(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)
__EXTERN INTEGER __CALL WriteConsoleW(INTEGER hConsoleOutput, INTEGER lpBuffer, INTEGER nNumberOfCharsToWrite, INTEGER *lpNumberOfCharsWritten, INTEGER lpReserved);
#define WinApi_WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped, lpOverlapped__typ)	WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped)
__EXTERN INTEGER __CALL WriteFile(INTEGER hFile, INTEGER lpBuffer, INTEGER nNumberOfBytesToWrite, INTEGER *lpNumberOfBytesWritten, WinApi_OVERLAPPED *lpOverlapped);
#define WinApi_WriteFileEx(hFile, lpBuffer, nNumberOfBytesToWrite, lpOverlapped, lpOverlapped__typ, lpCompletionRoutine)	WriteFileEx(hFile, lpBuffer, nNumberOfBytesToWrite, lpOverlapped, lpCompletionRoutine)
__EXTERN INTEGER __CALL WriteFileEx(INTEGER hFile, INTEGER lpBuffer, INTEGER nNumberOfBytesToWrite, WinApi_OVERLAPPED *lpOverlapped, WinApi_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinApi_WritePrinter(hPrinter, pBuf, cbBuf, pcWritten)	WritePrinter(hPrinter, pBuf, cbBuf, pcWritten)
__EXTERN INTEGER __CALL WritePrinter(INTEGER hPrinter, INTEGER pBuf, INTEGER cbBuf, INTEGER *pcWritten);
#define WinApi_WritePrivateProfileSection(lpAppName, lpString, lpFileName)	WritePrivateProfileSectionA(lpAppName, lpString, lpFileName)
#define WinApi_WritePrivateProfileSectionA(lpAppName, lpString, lpFileName)	WritePrivateProfileSectionA(lpAppName, lpString, lpFileName)
__EXTERN INTEGER __CALL WritePrivateProfileSectionA(WinApi_PtrSTR lpAppName, WinApi_PtrSTR lpString, WinApi_PtrSTR lpFileName);
#define WinApi_WritePrivateProfileSectionW(lpAppName, lpString, lpFileName)	WritePrivateProfileSectionW(lpAppName, lpString, lpFileName)
__EXTERN INTEGER __CALL WritePrivateProfileSectionW(WinApi_PtrWSTR lpAppName, WinApi_PtrWSTR lpString, WinApi_PtrWSTR lpFileName);
#define WinApi_WritePrivateProfileString(lpAppName, lpKeyName, lpString, lpFileName)	WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName)
#define WinApi_WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName)	WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName)
__EXTERN INTEGER __CALL WritePrivateProfileStringA(WinApi_PtrSTR lpAppName, WinApi_PtrSTR lpKeyName, WinApi_PtrSTR lpString, WinApi_PtrSTR lpFileName);
#define WinApi_WritePrivateProfileStringW(lpAppName, lpKeyName, lpString, lpFileName)	WritePrivateProfileStringW(lpAppName, lpKeyName, lpString, lpFileName)
__EXTERN INTEGER __CALL WritePrivateProfileStringW(WinApi_PtrWSTR lpAppName, WinApi_PtrWSTR lpKeyName, WinApi_PtrWSTR lpString, WinApi_PtrWSTR lpFileName);
#define WinApi_WritePrivateProfileStruct(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	WritePrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
#define WinApi_WritePrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	WritePrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN INTEGER __CALL WritePrivateProfileStructA(WinApi_PtrSTR lpszSection, WinApi_PtrSTR lpszKey, INTEGER lpStruct, INTEGER uSizeStruct, WinApi_PtrSTR szFile);
#define WinApi_WritePrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	WritePrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN INTEGER __CALL WritePrivateProfileStructW(WinApi_PtrWSTR lpszSection, WinApi_PtrWSTR lpszKey, INTEGER lpStruct, INTEGER uSizeStruct, WinApi_PtrWSTR szFile);
#define WinApi_WriteProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesWritten)	WriteProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesWritten)
__EXTERN INTEGER __CALL WriteProcessMemory(INTEGER hProcess, INTEGER lpBaseAddress, INTEGER lpBuffer, INTEGER nSize, INTEGER *lpNumberOfBytesWritten);
#define WinApi_WriteProfileSection(lpAppName, lpString)	WriteProfileSectionA(lpAppName, lpString)
#define WinApi_WriteProfileSectionA(lpAppName, lpString)	WriteProfileSectionA(lpAppName, lpString)
__EXTERN INTEGER __CALL WriteProfileSectionA(WinApi_PtrSTR lpAppName, WinApi_PtrSTR lpString);
#define WinApi_WriteProfileSectionW(lpAppName, lpString)	WriteProfileSectionW(lpAppName, lpString)
__EXTERN INTEGER __CALL WriteProfileSectionW(WinApi_PtrWSTR lpAppName, WinApi_PtrWSTR lpString);
#define WinApi_WriteProfileString(lpAppName, lpKeyName, lpString)	WriteProfileStringA(lpAppName, lpKeyName, lpString)
#define WinApi_WriteProfileStringA(lpAppName, lpKeyName, lpString)	WriteProfileStringA(lpAppName, lpKeyName, lpString)
__EXTERN INTEGER __CALL WriteProfileStringA(WinApi_PtrSTR lpAppName, WinApi_PtrSTR lpKeyName, WinApi_PtrSTR lpString);
#define WinApi_WriteProfileStringW(lpAppName, lpKeyName, lpString)	WriteProfileStringW(lpAppName, lpKeyName, lpString)
__EXTERN INTEGER __CALL WriteProfileStringW(WinApi_PtrWSTR lpAppName, WinApi_PtrWSTR lpKeyName, WinApi_PtrWSTR lpString);
#define WinApi_WriteTapemark(hDevice, dwTapemarkType, dwTapemarkCount, bImmediate)	WriteTapemark(hDevice, dwTapemarkType, dwTapemarkCount, bImmediate)
__EXTERN INTEGER __CALL WriteTapemark(INTEGER hDevice, INTEGER dwTapemarkType, INTEGER dwTapemarkCount, INTEGER bImmediate);
#define WinApi__hread(hFile, lpBuffer, lBytes)	_hread(hFile, lpBuffer, lBytes)
__EXTERN INTEGER __CALL _hread(INTEGER hFile, INTEGER lpBuffer, INTEGER lBytes);
#define WinApi__hwrite(hFile, lpBuffer, lBytes)	_hwrite(hFile, lpBuffer, lBytes)
__EXTERN INTEGER __CALL _hwrite(INTEGER hFile, WinApi_PtrSTR lpBuffer, INTEGER lBytes);
#define WinApi__lclose(hFile)	_lclose(hFile)
__EXTERN INTEGER __CALL _lclose(INTEGER hFile);
#define WinApi__lcreat(lpPathName, iAttribute)	_lcreat(lpPathName, iAttribute)
__EXTERN INTEGER __CALL _lcreat(WinApi_PtrSTR lpPathName, INTEGER iAttribute);
#define WinApi__llseek(hFile, lOffset, iOrigin)	_llseek(hFile, lOffset, iOrigin)
__EXTERN INTEGER __CALL _llseek(INTEGER hFile, INTEGER lOffset, INTEGER iOrigin);
#define WinApi__lopen(lpPathName, iReadWrite)	_lopen(lpPathName, iReadWrite)
__EXTERN INTEGER __CALL _lopen(WinApi_PtrSTR lpPathName, INTEGER iReadWrite);
#define WinApi__lread(hFile, lpBuffer, uBytes)	_lread(hFile, lpBuffer, uBytes)
__EXTERN INTEGER __CALL _lread(INTEGER hFile, INTEGER lpBuffer, INTEGER uBytes);
#define WinApi__lwrite(hFile, lpBuffer, uBytes)	_lwrite(hFile, lpBuffer, uBytes)
__EXTERN INTEGER __CALL _lwrite(INTEGER hFile, WinApi_PtrSTR lpBuffer, INTEGER uBytes);
#define WinApi_keybd_event(bVk, bScan, dwFlags, dwExtraInfo)	keybd_event(bVk, bScan, dwFlags, dwExtraInfo)
__EXTERN void __CALL keybd_event(CHAR bVk, CHAR bScan, SET dwFlags, INTEGER dwExtraInfo);
#define WinApi_lstrcat(lpString1, lpString2)	lstrcatA(lpString1, lpString2)
#define WinApi_lstrcatA(lpString1, lpString2)	lstrcatA(lpString1, lpString2)
__EXTERN WinApi_PtrSTR __CALL lstrcatA(WinApi_PtrSTR lpString1, WinApi_PtrSTR lpString2);
#define WinApi_lstrcatW(lpString1, lpString2)	lstrcatW(lpString1, lpString2)
__EXTERN WinApi_PtrWSTR __CALL lstrcatW(WinApi_PtrWSTR lpString1, WinApi_PtrWSTR lpString2);
#define WinApi_lstrcmp(lpString1, lpString2)	lstrcmpA(lpString1, lpString2)
#define WinApi_lstrcmpA(lpString1, lpString2)	lstrcmpA(lpString1, lpString2)
__EXTERN INTEGER __CALL lstrcmpA(WinApi_PtrSTR lpString1, WinApi_PtrSTR lpString2);
#define WinApi_lstrcmpW(lpString1, lpString2)	lstrcmpW(lpString1, lpString2)
__EXTERN INTEGER __CALL lstrcmpW(WinApi_PtrWSTR lpString1, WinApi_PtrWSTR lpString2);
#define WinApi_lstrcmpi(lpString1, lpString2)	lstrcmpiA(lpString1, lpString2)
#define WinApi_lstrcmpiA(lpString1, lpString2)	lstrcmpiA(lpString1, lpString2)
__EXTERN INTEGER __CALL lstrcmpiA(WinApi_PtrSTR lpString1, WinApi_PtrSTR lpString2);
#define WinApi_lstrcmpiW(lpString1, lpString2)	lstrcmpiW(lpString1, lpString2)
__EXTERN INTEGER __CALL lstrcmpiW(WinApi_PtrWSTR lpString1, WinApi_PtrWSTR lpString2);
#define WinApi_lstrcpy(lpString1, lpString2)	lstrcpyA(lpString1, lpString2)
#define WinApi_lstrcpyA(lpString1, lpString2)	lstrcpyA(lpString1, lpString2)
__EXTERN WinApi_PtrSTR __CALL lstrcpyA(WinApi_PtrSTR lpString1, WinApi_PtrSTR lpString2);
#define WinApi_lstrcpyW(lpString1, lpString2)	lstrcpyW(lpString1, lpString2)
__EXTERN WinApi_PtrWSTR __CALL lstrcpyW(WinApi_PtrWSTR lpString1, WinApi_PtrWSTR lpString2);
#define WinApi_lstrcpyn(lpString1, lpString2, iMaxLength)	lstrcpynA(lpString1, lpString2, iMaxLength)
#define WinApi_lstrcpynA(lpString1, lpString2, iMaxLength)	lstrcpynA(lpString1, lpString2, iMaxLength)
__EXTERN WinApi_PtrSTR __CALL lstrcpynA(WinApi_PtrSTR lpString1, WinApi_PtrSTR lpString2, INTEGER iMaxLength);
#define WinApi_lstrcpynW(lpString1, lpString2, iMaxLength)	lstrcpynW(lpString1, lpString2, iMaxLength)
__EXTERN WinApi_PtrWSTR __CALL lstrcpynW(WinApi_PtrWSTR lpString1, WinApi_PtrWSTR lpString2, INTEGER iMaxLength);
#define WinApi_lstrlen(lpString)	lstrlenA(lpString)
#define WinApi_lstrlenA(lpString)	lstrlenA(lpString)
__EXTERN INTEGER __CALL lstrlenA(WinApi_PtrSTR lpString);
#define WinApi_lstrlenW(lpString)	lstrlenW(lpString)
__EXTERN INTEGER __CALL lstrlenW(WinApi_PtrWSTR lpString);
#define WinApi_mouse_event(dwFlags, dx, dy, cButtons, dwExtraInfo)	mouse_event(dwFlags, dx, dy, cButtons, dwExtraInfo)
__EXTERN void __CALL mouse_event(SET dwFlags, INTEGER dx, INTEGER dy, INTEGER cButtons, INTEGER dwExtraInfo);
#define WinApi_wglCopyContext(p0, p1, p2)	wglCopyContext(p0, p1, p2)
__EXTERN INTEGER __CALL wglCopyContext(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_wglCreateContext(p0)	wglCreateContext(p0)
__EXTERN INTEGER __CALL wglCreateContext(INTEGER p0);
#define WinApi_wglCreateLayerContext(p0, p1)	wglCreateLayerContext(p0, p1)
__EXTERN INTEGER __CALL wglCreateLayerContext(INTEGER p0, INTEGER p1);
#define WinApi_wglDeleteContext(p0)	wglDeleteContext(p0)
__EXTERN INTEGER __CALL wglDeleteContext(INTEGER p0);
#define WinApi_wglDescribeLayerPlane(p0, p1, p2, p3, p4, p4__typ)	wglDescribeLayerPlane(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL wglDescribeLayerPlane(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinApi_LAYERPLANEDESCRIPTOR *p4);
#define WinApi_wglGetCurrentContext()	wglGetCurrentContext()
__EXTERN INTEGER __CALL wglGetCurrentContext(void);
#define WinApi_wglGetCurrentDC()	wglGetCurrentDC()
__EXTERN INTEGER __CALL wglGetCurrentDC(void);
#define WinApi_wglGetLayerPaletteEntries(p0, p1, p2, p3, p4)	wglGetLayerPaletteEntries(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL wglGetLayerPaletteEntries(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4);
#define WinApi_wglGetProcAddress(p0)	wglGetProcAddress(p0)
__EXTERN WinApi_ROC __CALL wglGetProcAddress(WinApi_PtrSTR p0);
#define WinApi_wglMakeCurrent(p0, p1)	wglMakeCurrent(p0, p1)
__EXTERN INTEGER __CALL wglMakeCurrent(INTEGER p0, INTEGER p1);
#define WinApi_wglRealizeLayerPalette(p0, p1, p2)	wglRealizeLayerPalette(p0, p1, p2)
__EXTERN INTEGER __CALL wglRealizeLayerPalette(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinApi_wglSetLayerPaletteEntries(p0, p1, p2, p3, p4)	wglSetLayerPaletteEntries(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL wglSetLayerPaletteEntries(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4);
#define WinApi_wglShareLists(p0, p1)	wglShareLists(p0, p1)
__EXTERN INTEGER __CALL wglShareLists(INTEGER p0, INTEGER p1);
#define WinApi_wglSwapLayerBuffers(p0, p1)	wglSwapLayerBuffers(p0, p1)
__EXTERN INTEGER __CALL wglSwapLayerBuffers(INTEGER p0, INTEGER p1);
#define WinApi_wglUseFontBitmaps(p0, p1, p2, p3)	wglUseFontBitmapsA(p0, p1, p2, p3)
#define WinApi_wglUseFontBitmapsA(p0, p1, p2, p3)	wglUseFontBitmapsA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL wglUseFontBitmapsA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinApi_wglUseFontBitmapsW(p0, p1, p2, p3)	wglUseFontBitmapsW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL wglUseFontBitmapsW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinApi_wglUseFontOutlines(p0, p1, p2, p3, p4, p5, p6, p7, p7__typ)	wglUseFontOutlinesA(p0, p1, p2, p3, p4, p5, p6, p7)
#define WinApi_wglUseFontOutlinesA(p0, p1, p2, p3, p4, p5, p6, p7, p7__typ)	wglUseFontOutlinesA(p0, p1, p2, p3, p4, p5, p6, p7)
__EXTERN INTEGER __CALL wglUseFontOutlinesA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, REAL p4, REAL p5, INTEGER p6, WinApi_GLYPHMETRICSFLOAT *p7);
#define WinApi_wglUseFontOutlinesW(p0, p1, p2, p3, p4, p5, p6, p7, p7__typ)	wglUseFontOutlinesW(p0, p1, p2, p3, p4, p5, p6, p7)
__EXTERN INTEGER __CALL wglUseFontOutlinesW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, REAL p4, REAL p5, INTEGER p6, WinApi_GLYPHMETRICSFLOAT *p7);
#define WinApi_wvsprintf(p0, p1, arglist)	wvsprintfA(p0, p1, arglist)
#define WinApi_wvsprintfA(p0, p1, arglist)	wvsprintfA(p0, p1, arglist)
__EXTERN INTEGER __CALL wvsprintfA(WinApi_PtrSTR p0, WinApi_PtrSTR p1, WinApi_PtrSTR arglist);
#define WinApi_wvsprintfW(p0, p1, arglist)	wvsprintfW(p0, p1, arglist)
__EXTERN INTEGER __CALL wvsprintfW(WinApi_PtrWSTR p0, WinApi_PtrWSTR p1, WinApi_PtrSTR arglist);

#endif

/* Ofront+ 1.0 -sxt3 -88 */

#ifndef WinAPI__h
#define WinAPI__h

#include "SYSTEM.h"

struct WinAPI__22 {
	CHAR BaseMid, Flags1, Flags2, BaseHi;
};

struct WinAPI__23 {
	struct WinAPI__22 Bytes;
};

struct WinAPI__24 {
	LONGINT FiberData;
};

struct WinAPI__18 {
	INTEGER PhysicalAddress;
};

struct WinAPI__19 {
	CHAR ShortName[8];
};

struct WinAPI__7 {
	INTEGER TotalSize;
};

struct WinAPI__8 {
	INTEGER PointerToLinenumber, PointerToNextFunction;
};

struct WinAPI__9 {
	struct WinAPI__8 Function;
};

struct WinAPI__10 {
	INTEGER TagIndex;
	struct WinAPI__7 Misc;
	struct WinAPI__9 FcnAry;
	SHORTINT TvIndex;
};

struct WinAPI__14 {
	INTEGER VirtualAddress;
};

struct WinAPI__13 {
	INTEGER SymbolTableIndex;
};

struct WinAPI__11 {
	LONGINT ForwarderString;
};

typedef
	struct WinAPI_IMAGE_THUNK_DATA *WinAPI_PtrIMAGE_THUNK_DATA;

struct WinAPI__12 {
	WinAPI_PtrIMAGE_THUNK_DATA OriginalFirstThunk;
};

struct WinAPI__15 {
	SET fBits0;
};

struct WinAPI__16 {
	struct WinAPI__15 r;
};

struct WinAPI__17 {
	INTEGER OffsetToData;
};

struct WinAPI__35 {
	INTEGER dwOemId;
};

typedef
	struct WinAPI_EXCEPTION_RECORD *WinAPI_PtrEXCEPTION_RECORD;

typedef
	struct WinAPI_EXCEPTION_RECORD {
		INTEGER ExceptionCode;
		SET ExceptionFlags;
		WinAPI_PtrEXCEPTION_RECORD ExceptionRecord;
		LONGINT ExceptionAddress;
		INTEGER NumberParameters;
		INTEGER ExceptionInformation[15];
	} WinAPI_EXCEPTION_RECORD;

typedef
	struct WinAPI_EXCEPTION_DEBUG_INFO {
		WinAPI_EXCEPTION_RECORD ExceptionRecord;
		INTEGER dwFirstChance;
	} WinAPI_EXCEPTION_DEBUG_INFO;

struct WinAPI__2 {
	WinAPI_EXCEPTION_DEBUG_INFO Exception;
};

struct WinAPI__27 {
	LONGINT hMem;
	INTEGER dwReserved[3];
};

struct WinAPI__28 {
	struct WinAPI__27 Block;
};

struct WinAPI__20 {
	SHORTINT UnicodeChar;
};

typedef
	struct WinAPI_KEY_EVENT_RECORD {
		INTEGER bKeyDown;
		SHORTINT wRepeatCount, wVirtualKeyCode, wVirtualScanCode;
		struct WinAPI__20 uChar;
		SET dwControlKeyState;
	} WinAPI_KEY_EVENT_RECORD;

struct WinAPI__21 {
	WinAPI_KEY_EVENT_RECORD KeyEvent;
};

struct WinAPI__1 {
	SHORTINT UnicodeChar;
};

struct WinAPI__3 {
	LONGINT pszTemplate;
};

struct WinAPI__4 {
	LONGINT hIcon;
};

struct WinAPI__5 {
	LONGINT pszTemplate;
};

struct WinAPI__6 {
	LONGINT hIcon;
};

struct WinAPI__29 {
	LONGINT hIcon;
};

struct WinAPI__30 {
	LONGINT pStartPage;
};

typedef
	struct WinAPI_PROPSHEETPAGEA *WinAPI_PtrPROPSHEETPAGEA;

struct WinAPI__31 {
	WinAPI_PtrPROPSHEETPAGEA ppsp;
};

struct WinAPI__32 {
	LONGINT hIcon;
};

struct WinAPI__33 {
	LONGINT pStartPage;
};

typedef
	struct WinAPI_PROPSHEETPAGEW *WinAPI_PtrPROPSHEETPAGEW;

struct WinAPI__34 {
	WinAPI_PtrPROPSHEETPAGEW ppsp;
};

struct WinAPI__25 {
	INTEGER cbBuf;
	LONGINT pBuf;
};

struct WinAPI__26 {
	struct WinAPI__25 Data;
};

typedef
	struct WinAPI_ABC {
		INTEGER abcA, abcB, abcC;
	} WinAPI_ABC;

typedef
	struct WinAPI_ABCFLOAT {
		SHORTREAL abcfA, abcfB, abcfC;
	} WinAPI_ABCFLOAT;

typedef
	INTEGER (__STDCALL *WinAPI_ABORTPROC)(LONGINT, INTEGER);

typedef
	struct WinAPI_ACCEL {
		CHAR fVirt;
		SHORTINT key, cmd;
	} WinAPI_ACCEL;

typedef
	struct WinAPI_ACCESSTIMEOUT {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER iTimeOutMSec;
	} WinAPI_ACCESSTIMEOUT;

typedef
	struct WinAPI_ACE_HEADER {
		CHAR AceType, AceFlags;
		SHORTINT AceSize;
	} WinAPI_ACE_HEADER;

typedef
	struct WinAPI_ACCESS_ALLOWED_ACE {
		WinAPI_ACE_HEADER Header;
		SET Mask;
		INTEGER SidStart;
	} WinAPI_ACCESS_ALLOWED_ACE;

typedef
	struct WinAPI_ACCESS_DENIED_ACE {
		WinAPI_ACE_HEADER Header;
		SET Mask;
		INTEGER SidStart;
	} WinAPI_ACCESS_DENIED_ACE;

typedef
	struct WinAPI_ACL {
		CHAR AclRevision, Sbz1;
		SHORTINT AclSize, AceCount, Sbz2;
	} WinAPI_ACL;

typedef
	struct WinAPI_ACL_REVISION_INFORMATION {
		INTEGER AclRevision;
	} WinAPI_ACL_REVISION_INFORMATION;

typedef
	struct WinAPI_ACL_SIZE_INFORMATION {
		INTEGER AceCount, AclBytesInUse, AclBytesFree;
	} WinAPI_ACL_SIZE_INFORMATION;

typedef
	struct WinAPI_ADDJOB_INFO_1A {
		LONGINT Path;
		INTEGER JobId;
	} WinAPI_ADDJOB_INFO_1A;

typedef
	struct WinAPI_ADDJOB_INFO_1W {
		LONGINT Path;
		INTEGER JobId;
	} WinAPI_ADDJOB_INFO_1W;

typedef
	struct WinAPI_ANIMATIONINFO {
		INTEGER cbSize, iMinAnimate;
	} WinAPI_ANIMATIONINFO;

typedef
	void (__STDCALL *WinAPI_APCFUNC)(INTEGER);

typedef
	struct WinAPI_RECT {
		INTEGER left, top, right, bottom;
	} WinAPI_RECT;

typedef
	struct WinAPI_APPBARDATA {
		INTEGER cbSize;
		LONGINT hWnd;
		INTEGER uCallbackMessage, uEdge;
		WinAPI_RECT rc;
		LONGINT lParam;
	} WinAPI_APPBARDATA;

typedef
	struct WinAPI_BITMAP {
		INTEGER bmType, bmWidth, bmHeight, bmWidthBytes;
		SHORTINT bmPlanes, bmBitsPixel;
		LONGINT bmBits;
	} WinAPI_BITMAP;

typedef
	struct WinAPI_BITMAPCOREHEADER {
		INTEGER bcSize;
		SHORTINT bcWidth, bcHeight, bcPlanes, bcBitCount;
	} WinAPI_BITMAPCOREHEADER;

typedef
	struct WinAPI_RGBTRIPLE {
		CHAR rgbtBlue, rgbtGreen, rgbtRed;
	} WinAPI_RGBTRIPLE;

typedef
	struct WinAPI_BITMAPCOREINFO {
		WinAPI_BITMAPCOREHEADER bmciHeader;
		WinAPI_RGBTRIPLE bmciColors[1];
	} WinAPI_BITMAPCOREINFO;

typedef
	struct WinAPI_BITMAPFILEHEADER {
		SHORTINT bfType;
		INTEGER bfSize;
		SHORTINT bfReserved1, bfReserved2;
		INTEGER bfOffBits;
	} WinAPI_BITMAPFILEHEADER;

typedef
	struct WinAPI_BITMAPINFOHEADER {
		INTEGER biSize, biWidth, biHeight;
		SHORTINT biPlanes, biBitCount;
		INTEGER biCompression, biSizeImage, biXPelsPerMeter, biYPelsPerMeter, biClrUsed, biClrImportant;
	} WinAPI_BITMAPINFOHEADER;

typedef
	struct WinAPI_RGBQUAD {
		CHAR rgbBlue, rgbGreen, rgbRed, rgbReserved;
	} WinAPI_RGBQUAD;

typedef
	struct WinAPI_BITMAPINFO {
		WinAPI_BITMAPINFOHEADER bmiHeader;
		WinAPI_RGBQUAD bmiColors[1];
	} WinAPI_BITMAPINFO;

typedef
	struct WinAPI_CIEXYZ {
		INTEGER ciexyzX, ciexyzY, ciexyzZ;
	} WinAPI_CIEXYZ;

typedef
	struct WinAPI_CIEXYZTRIPLE {
		WinAPI_CIEXYZ ciexyzRed, ciexyzGreen, ciexyzBlue;
	} WinAPI_CIEXYZTRIPLE;

typedef
	struct WinAPI_BITMAPV4HEADER {
		INTEGER bV4Size, bV4Width, bV4Height;
		SHORTINT bV4Planes, bV4BitCount;
		INTEGER bV4V4Compression, bV4SizeImage, bV4XPelsPerMeter, bV4YPelsPerMeter, bV4ClrUsed, bV4ClrImportant, bV4RedMask, bV4GreenMask, bV4BlueMask, bV4AlphaMask, bV4CSType;
		WinAPI_CIEXYZTRIPLE bV4Endpoints;
		INTEGER bV4GammaRed, bV4GammaGreen, bV4GammaBlue;
	} WinAPI_BITMAPV4HEADER;

typedef
	struct WinAPI_BROADCASTSYSMSG {
		INTEGER uiMessage;
		LONGINT wParam, lParam;
	} WinAPI_BROADCASTSYSMSG;

typedef
	struct WinAPI_FILETIME {
		INTEGER dwLowDateTime, dwHighDateTime;
	} WinAPI_FILETIME;

typedef
	struct WinAPI_BY_HANDLE_FILE_INFORMATION {
		SET dwFileAttributes;
		WinAPI_FILETIME ftCreationTime, ftLastAccessTime, ftLastWriteTime;
		INTEGER dwVolumeSerialNumber, nFileSizeHigh, nFileSizeLow, nNumberOfLinks, nFileIndexHigh, nFileIndexLow;
	} WinAPI_BY_HANDLE_FILE_INFORMATION;

typedef
	INTEGER (__STDCALL *WinAPI_CALINFO_ENUMPROCA)(void);

typedef
	INTEGER (__STDCALL *WinAPI_CALINFO_ENUMPROCW)(void);

typedef
	struct WinAPI_CBTACTIVATESTRUCT {
		INTEGER fMouse;
		LONGINT hWndActive;
	} WinAPI_CBTACTIVATESTRUCT;

typedef
	struct WinAPI_CREATESTRUCTA *WinAPI_PtrCREATESTRUCTA;

typedef
	struct WinAPI_CBT_CREATEWNDA {
		WinAPI_PtrCREATESTRUCTA lpcs;
		LONGINT hwndInsertAfter;
	} WinAPI_CBT_CREATEWNDA;

typedef
	struct WinAPI_CREATESTRUCTW *WinAPI_PtrCREATESTRUCTW;

typedef
	struct WinAPI_CBT_CREATEWNDW {
		WinAPI_PtrCREATESTRUCTW lpcs;
		LONGINT hwndInsertAfter;
	} WinAPI_CBT_CREATEWNDW;

typedef
	struct WinAPI_FONTSIGNATURE {
		INTEGER fsUsb[4];
		INTEGER fsCsb[2];
	} WinAPI_FONTSIGNATURE;

typedef
	struct WinAPI_CHARSETINFO {
		INTEGER ciCharset, ciACP;
		WinAPI_FONTSIGNATURE fs;
	} WinAPI_CHARSETINFO;

typedef
	struct WinAPI_CHAR_INFO {
		struct WinAPI__1 Char;
		SHORTINT Attributes;
	} WinAPI_CHAR_INFO;

typedef
	struct WinAPI_CLIENTCREATESTRUCT {
		LONGINT hWindowMenu;
		INTEGER idFirstChild;
	} WinAPI_CLIENTCREATESTRUCT;

typedef
	INTEGER (__STDCALL *WinAPI_CODEPAGE_ENUMPROCA)(void);

typedef
	INTEGER (__STDCALL *WinAPI_CODEPAGE_ENUMPROCW)(void);

typedef
	struct WinAPI_COLORADJUSTMENT {
		SHORTINT caSize, caFlags, caIlluminantIndex, caRedGamma, caGreenGamma, caBlueGamma, caReferenceBlack, caReferenceWhite, caContrast, caBrightness, caColorfulness, caRedGreenTint;
	} WinAPI_COLORADJUSTMENT;

typedef
	struct WinAPI_DCB {
		INTEGER DCBlength, BaudRate;
		SET fBits0;
		SHORTINT wReserved, XonLim, XoffLim;
		CHAR ByteSize, Parity, StopBits, XonChar, XoffChar, ErrorChar, EofChar, EvtChar;
		SHORTINT wReserved1;
	} WinAPI_DCB;

typedef
	struct WinAPI_COMMCONFIG {
		INTEGER dwSize;
		SHORTINT wVersion, wReserved;
		WinAPI_DCB dcb;
		INTEGER dwProviderSubType, dwProviderOffset, dwProviderSize;
		SHORTINT wcProviderData[1];
	} WinAPI_COMMCONFIG;

typedef
	struct WinAPI_COMMPROP {
		SHORTINT wPacketLength, wPacketVersion;
		INTEGER dwServiceMask, dwReserved1, dwMaxTxQueue, dwMaxRxQueue;
		SET dwMaxBaud;
		INTEGER dwProvSubType;
		SET dwProvCapabilities, dwSettableParams, dwSettableBaud;
		SHORTINT wSettableData, wSettableStopParity;
		INTEGER dwCurrentTxQueue, dwCurrentRxQueue, dwProvSpec1, dwProvSpec2;
		SHORTINT wcProvChar[1];
	} WinAPI_COMMPROP;

typedef
	struct WinAPI_COMMTIMEOUTS {
		INTEGER ReadIntervalTimeout, ReadTotalTimeoutMultiplier, ReadTotalTimeoutConstant, WriteTotalTimeoutMultiplier, WriteTotalTimeoutConstant;
	} WinAPI_COMMTIMEOUTS;

typedef
	struct WinAPI_COMPAREITEMSTRUCT {
		SET CtlType;
		INTEGER CtlID;
		LONGINT hwndItem;
		INTEGER itemID1, itemData1, itemID2, itemData2, dwLocaleId;
	} WinAPI_COMPAREITEMSTRUCT;

typedef
	struct WinAPI_COMPOUND_ACCESS_ALLOWED_ACE {
		WinAPI_ACE_HEADER Header;
		SET Mask;
		SHORTINT CompoundAceType, Reserved;
		INTEGER SidStart;
	} WinAPI_COMPOUND_ACCESS_ALLOWED_ACE;

typedef
	struct WinAPI_COMSTAT {
		SET fBits0;
		INTEGER cbInQue, cbOutQue;
	} WinAPI_COMSTAT;

typedef
	struct WinAPI_COM_GUID {
		INTEGER Data1;
		SHORTINT Data2, Data3;
		BYTE Data4[8];
	} WinAPI_COM_GUID;

typedef
	struct WinAPI_CONSOLE_CURSOR_INFO {
		INTEGER dwSize, bVisible;
	} WinAPI_CONSOLE_CURSOR_INFO;

typedef
	struct WinAPI_COORD {
		SHORTINT X, Y;
	} WinAPI_COORD;

typedef
	struct WinAPI_SMALL_RECT {
		SHORTINT Left, Top, Right, Bottom;
	} WinAPI_SMALL_RECT;

typedef
	struct WinAPI_CONSOLE_SCREEN_BUFFER_INFO {
		WinAPI_COORD dwSize, dwCursorPosition;
		SHORTINT wAttributes;
		WinAPI_SMALL_RECT srWindow;
		WinAPI_COORD dwMaximumWindowSize;
	} WinAPI_CONSOLE_SCREEN_BUFFER_INFO;

typedef
	struct WinAPI_FLOATING_SAVE_AREA {
		INTEGER ControlWord, StatusWord, TagWord, ErrorOffset, ErrorSelector, DataOffset, DataSelector;
		CHAR RegisterArea[80];
		INTEGER Cr0NpxState;
	} WinAPI_FLOATING_SAVE_AREA;

typedef
	struct WinAPI_CONTEXT {
		SET ContextFlags;
		INTEGER Dr0, Dr1, Dr2, Dr3, Dr6, Dr7;
		WinAPI_FLOATING_SAVE_AREA FloatSave;
		INTEGER SegGs, SegFs, SegEs, SegDs, Edi, Esi, Ebx, Edx, Ecx, Eax, Ebp, Eip, SegCs, EFlags, Esp, SegSs;
	} WinAPI_CONTEXT;

typedef
	struct WinAPI_SECURITY_QUALITY_OF_SERVICE {
		INTEGER Length, ImpersonationLevel;
		BOOLEAN ContextTrackingMode, EffectiveOnly;
	} WinAPI_SECURITY_QUALITY_OF_SERVICE;

typedef
	struct WinAPI_CONVCONTEXT {
		INTEGER cb, wFlags, wCountryID, iCodePage, dwLangID, dwSecurity;
		WinAPI_SECURITY_QUALITY_OF_SERVICE qos;
	} WinAPI_CONVCONTEXT;

typedef
	struct WinAPI_CONVINFO {
		INTEGER cb, hUser;
		LONGINT hConvPartner, hszSvcPartner, hszServiceReq, hszTopic, hszItem;
		INTEGER wFmt, wType;
		SET wStatus;
		INTEGER wConvst, wLastError;
		LONGINT hConvList;
		WinAPI_CONVCONTEXT ConvCtxt;
		LONGINT hwnd, hwndPartner;
	} WinAPI_CONVINFO;

typedef
	struct WinAPI_COPYDATASTRUCT {
		INTEGER dwData, cbData;
		LONGINT lpData;
	} WinAPI_COPYDATASTRUCT;

typedef
	struct WinAPI_CPINFO {
		INTEGER MaxCharSize;
		CHAR DefaultChar[2];
		CHAR LeadByte[12];
	} WinAPI_CPINFO;

typedef
	struct WinAPI_CREATESTRUCTA {
		LONGINT lpCreateParams, hInstance, hMenu, hwndParent;
		INTEGER cy, cx, y, x;
		SET style;
		LONGINT lpszName, lpszClass;
		SET dwExStyle;
	} WinAPI_CREATESTRUCTA;

typedef
	struct WinAPI_CREATESTRUCTW {
		LONGINT lpCreateParams, hInstance, hMenu, hwndParent;
		INTEGER cy, cx, y, x;
		SET style;
		LONGINT lpszName, lpszClass;
		SET dwExStyle;
	} WinAPI_CREATESTRUCTW;

typedef
	INTEGER (__STDCALL *WinAPI_THREAD_START_ROUTINE)(LONGINT);

typedef
	struct WinAPI_CREATE_PROCESS_DEBUG_INFO {
		LONGINT hFile, hProcess, hThread, lpBaseOfImage;
		INTEGER dwDebugInfoFileOffset, nDebugInfoSize;
		LONGINT lpThreadLocalBase;
		WinAPI_THREAD_START_ROUTINE lpStartAddress;
		LONGINT lpImageName;
		SHORTINT fUnicode;
	} WinAPI_CREATE_PROCESS_DEBUG_INFO;

typedef
	struct WinAPI_CREATE_THREAD_DEBUG_INFO {
		LONGINT hThread, lpThreadLocalBase;
		WinAPI_THREAD_START_ROUTINE lpStartAddress;
	} WinAPI_CREATE_THREAD_DEBUG_INFO;

typedef
	struct WinAPI_RTL_CRITICAL_SECTION_DEBUG *WinAPI_PtrRTL_CRITICAL_SECTION_DEBUG;

typedef
	struct WinAPI_RTL_CRITICAL_SECTION {
		WinAPI_PtrRTL_CRITICAL_SECTION_DEBUG DebugInfo;
		INTEGER LockCount, RecursionCount;
		LONGINT OwningThread, LockSemaphore;
		INTEGER Reserved;
	} WinAPI_RTL_CRITICAL_SECTION;

typedef
	WinAPI_RTL_CRITICAL_SECTION *WinAPI_PtrRTL_CRITICAL_SECTION;

typedef
	struct WinAPI_LIST_ENTRY *WinAPI_PtrLIST_ENTRY;

typedef
	struct WinAPI_LIST_ENTRY {
		WinAPI_PtrLIST_ENTRY Flink, Blink;
	} WinAPI_LIST_ENTRY;

typedef
	struct WinAPI_RTL_CRITICAL_SECTION_DEBUG {
		SHORTINT Type, CreatorBackTraceIndex;
		WinAPI_PtrRTL_CRITICAL_SECTION CriticalSection;
		WinAPI_LIST_ENTRY ProcessLocksList;
		INTEGER EntryCount, ContentionCount;
		INTEGER Spare[2];
	} WinAPI_RTL_CRITICAL_SECTION_DEBUG;

typedef
	struct WinAPI_CURRENCYFMTA {
		INTEGER NumDigits, LeadingZero, Grouping;
		LONGINT lpDecimalSep, lpThousandSep;
		INTEGER NegativeOrder, PositiveOrder;
		LONGINT lpCurrencySymbol;
	} WinAPI_CURRENCYFMTA;

typedef
	struct WinAPI_CURRENCYFMTW {
		INTEGER NumDigits, LeadingZero, Grouping;
		LONGINT lpDecimalSep, lpThousandSep;
		INTEGER NegativeOrder, PositiveOrder;
		LONGINT lpCurrencySymbol;
	} WinAPI_CURRENCYFMTW;

typedef
	struct WinAPI_CURSORSHAPE {
		INTEGER xHotSpot, yHotSpot, cx, cy, cbWidth;
		CHAR Planes, BitsPixel;
	} WinAPI_CURSORSHAPE;

typedef
	struct WinAPI_CWPRETSTRUCT {
		LONGINT lResult, lParam, wParam;
		INTEGER message;
		LONGINT hwnd;
	} WinAPI_CWPRETSTRUCT;

typedef
	struct WinAPI_CWPSTRUCT {
		LONGINT lParam, wParam;
		INTEGER message;
		LONGINT hwnd;
	} WinAPI_CWPSTRUCT;

typedef
	struct WinAPI_DATATYPES_INFO_1A {
		LONGINT pName;
	} WinAPI_DATATYPES_INFO_1A;

typedef
	struct WinAPI_DATATYPES_INFO_1W {
		LONGINT pName;
	} WinAPI_DATATYPES_INFO_1W;

typedef
	INTEGER (__STDCALL *WinAPI_DATEFMT_ENUMPROCA)(void);

typedef
	INTEGER (__STDCALL *WinAPI_DATEFMT_ENUMPROCW)(void);

typedef
	struct WinAPI_DDEACK {
		SHORTINT fBits0;
	} WinAPI_DDEACK;

typedef
	struct WinAPI_DDEADVISE {
		SHORTINT fBits0, cfFormat;
	} WinAPI_DDEADVISE;

typedef
	struct WinAPI_DDEDATA {
		SHORTINT fBits0, cfFormat;
		CHAR Value[1];
	} WinAPI_DDEDATA;

typedef
	struct WinAPI_DDELN {
		SHORTINT fBits0, cfFormat;
	} WinAPI_DDELN;

typedef
	struct WinAPI_DDEML_MSG_HOOK_DATA {
		INTEGER uiLo, uiHi, cbData;
		INTEGER Data[8];
	} WinAPI_DDEML_MSG_HOOK_DATA;

typedef
	struct WinAPI_DDEPOKE {
		SHORTINT fBits0, cfFormat;
		CHAR Value[1];
	} WinAPI_DDEPOKE;

typedef
	struct WinAPI_DDEUP {
		SHORTINT fBits0, cfFormat;
		CHAR rgb[1];
	} WinAPI_DDEUP;

typedef
	struct WinAPI_DEBUGHOOKINFO {
		INTEGER idThread, idThreadInstaller;
		LONGINT lParam, wParam;
		INTEGER code;
	} WinAPI_DEBUGHOOKINFO;

typedef
	struct WinAPI_DEBUG_EVENT {
		INTEGER dwDebugEventCode, dwProcessId, dwThreadId;
		struct WinAPI__2 u;
	} WinAPI_DEBUG_EVENT;

typedef
	struct WinAPI_DELETEITEMSTRUCT {
		SET CtlType;
		INTEGER CtlID, itemID;
		LONGINT hwndItem;
		INTEGER itemData;
	} WinAPI_DELETEITEMSTRUCT;

typedef
	INTEGER (__STDCALL *WinAPI_DESKTOPENUMPROC)(void);

typedef
	INTEGER (__STDCALL *WinAPI_DESKTOPENUMPROCA)(void);

typedef
	INTEGER (__STDCALL *WinAPI_DESKTOPENUMPROCW)(void);

typedef
	struct WinAPI_DEVMODEA {
		CHAR dmDeviceName[32];
		SHORTINT dmSpecVersion, dmDriverVersion, dmSize, dmDriverExtra;
		SET dmFields;
		SHORTINT dmOrientation, dmPaperSize, dmPaperLength, dmPaperWidth, dmScale, dmCopies, dmDefaultSource, dmPrintQuality, dmColor, dmDuplex, dmYResolution, dmTTOption, dmCollate;
		CHAR dmFormName[32];
		SHORTINT dmLogPixels;
		INTEGER dmBitsPerPel, dmPelsWidth, dmPelsHeight;
		SET dmDisplayFlags;
		INTEGER dmDisplayFrequency, dmICMMethod, dmICMIntent, dmMediaType, dmDitherType, dmICCManufacturer, dmICCModel, dmPanningWidth, dmPanningHeight;
	} WinAPI_DEVMODEA;

typedef
	struct WinAPI_DEVMODEW {
		SHORTINT dmDeviceName[32];
		SHORTINT dmSpecVersion, dmDriverVersion, dmSize, dmDriverExtra;
		SET dmFields;
		SHORTINT dmOrientation, dmPaperSize, dmPaperLength, dmPaperWidth, dmScale, dmCopies, dmDefaultSource, dmPrintQuality, dmColor, dmDuplex, dmYResolution, dmTTOption, dmCollate;
		SHORTINT dmFormName[32];
		SHORTINT dmLogPixels;
		INTEGER dmBitsPerPel, dmPelsWidth, dmPelsHeight;
		SET dmDisplayFlags;
		INTEGER dmDisplayFrequency, dmICMMethod, dmICMIntent, dmMediaType, dmDitherType, dmICCManufacturer, dmICCModel, dmPanningWidth, dmPanningHeight;
	} WinAPI_DEVMODEW;

typedef
	struct WinAPI_DIBSECTION {
		WinAPI_BITMAP dsBm;
		WinAPI_BITMAPINFOHEADER dsBmih;
		INTEGER dsBitfields[3];
		LONGINT dshSection;
		INTEGER dsOffset;
	} WinAPI_DIBSECTION;

typedef
	struct WinAPI_DLGITEMTEMPLATE {
		SET style, dwExtendedStyle;
		SHORTINT x, y, cx, cy, id;
	} WinAPI_DLGITEMTEMPLATE;

typedef
	LONGINT (__STDCALL *WinAPI_DLGPROC)(LONGINT, INTEGER, LONGINT, LONGINT);

typedef
	struct WinAPI_DLGTEMPLATE {
		SET style, dwExtendedStyle;
		SHORTINT cdit, x, y, cx, cy;
	} WinAPI_DLGTEMPLATE;

typedef
	struct WinAPI_DOCINFOA {
		INTEGER cbSize;
		LONGINT lpszDocName, lpszOutput, lpszDatatype;
		INTEGER fwType;
	} WinAPI_DOCINFOA;

typedef
	struct WinAPI_DOCINFOW {
		INTEGER cbSize;
		LONGINT lpszDocName, lpszOutput, lpszDatatype;
		INTEGER fwType;
	} WinAPI_DOCINFOW;

typedef
	struct WinAPI_DOC_INFO_1A {
		LONGINT pDocName, pOutputFile, pDatatype;
	} WinAPI_DOC_INFO_1A;

typedef
	struct WinAPI_DOC_INFO_1W {
		LONGINT pDocName, pOutputFile, pDatatype;
	} WinAPI_DOC_INFO_1W;

typedef
	struct WinAPI_DOC_INFO_2A {
		LONGINT pDocName, pOutputFile, pDatatype;
		SET dwMode;
		INTEGER JobId;
	} WinAPI_DOC_INFO_2A;

typedef
	struct WinAPI_DOC_INFO_2W {
		LONGINT pDocName, pOutputFile, pDatatype;
		SET dwMode;
		INTEGER JobId;
	} WinAPI_DOC_INFO_2W;

typedef
	struct WinAPI_POINT {
		INTEGER x, y;
	} WinAPI_POINT;

typedef
	struct WinAPI_DRAGINFOA {
		INTEGER uSize;
		WinAPI_POINT pt;
		INTEGER fNC;
		LONGINT lpFileList;
		SET grfKeyState;
	} WinAPI_DRAGINFOA;

typedef
	struct WinAPI_DRAGINFOW {
		INTEGER uSize;
		WinAPI_POINT pt;
		INTEGER fNC;
		LONGINT lpFileList;
		SET grfKeyState;
	} WinAPI_DRAGINFOW;

typedef
	struct WinAPI_DRAWITEMSTRUCT {
		SET CtlType;
		INTEGER CtlID, itemID;
		SET itemAction, itemState;
		LONGINT hwndItem, hDC;
		WinAPI_RECT rcItem;
		INTEGER itemData;
	} WinAPI_DRAWITEMSTRUCT;

typedef
	INTEGER (__STDCALL *WinAPI_DRAWSTATEPROC)(void);

typedef
	struct WinAPI_DRAWTEXTPARAMS {
		INTEGER cbSize, iTabLength, iLeftMargin, iRightMargin, uiLengthDrawn;
	} WinAPI_DRAWTEXTPARAMS;

typedef
	struct WinAPI_DRIVER_INFO_1A {
		LONGINT pName;
	} WinAPI_DRIVER_INFO_1A;

typedef
	struct WinAPI_DRIVER_INFO_1W {
		LONGINT pName;
	} WinAPI_DRIVER_INFO_1W;

typedef
	struct WinAPI_DRIVER_INFO_2A {
		INTEGER cVersion;
		LONGINT pName, pEnvironment, pDriverPath, pDataFile, pConfigFile;
	} WinAPI_DRIVER_INFO_2A;

typedef
	struct WinAPI_DRIVER_INFO_2W {
		INTEGER cVersion;
		LONGINT pName, pEnvironment, pDriverPath, pDataFile, pConfigFile;
	} WinAPI_DRIVER_INFO_2W;

typedef
	struct WinAPI_DRIVER_INFO_3A {
		INTEGER cVersion;
		LONGINT pName, pEnvironment, pDriverPath, pDataFile, pConfigFile, pHelpFile, pDependentFiles, pMonitorName, pDefaultDataType;
	} WinAPI_DRIVER_INFO_3A;

typedef
	struct WinAPI_DRIVER_INFO_3W {
		INTEGER cVersion;
		LONGINT pName, pEnvironment, pDriverPath, pDataFile, pConfigFile, pHelpFile, pDependentFiles, pMonitorName, pDefaultDataType;
	} WinAPI_DRIVER_INFO_3W;

typedef
	struct WinAPI_DROPSTRUCT {
		LONGINT hwndSource, hwndSink;
		INTEGER wFmt, dwData;
		WinAPI_POINT ptDrop;
		INTEGER dwControlData;
	} WinAPI_DROPSTRUCT;

typedef
	INTEGER (__STDCALL *WinAPI_EDITWORDBREAKPROC)(void);

typedef
	INTEGER (__STDCALL *WinAPI_EDITWORDBREAKPROCA)(void);

typedef
	INTEGER (__STDCALL *WinAPI_EDITWORDBREAKPROCW)(void);

typedef
	struct WinAPI_EMR {
		INTEGER iType, nSize;
	} WinAPI_EMR;

typedef
	struct WinAPI_EMRABORTPATH {
		WinAPI_EMR emr;
	} WinAPI_EMRABORTPATH;

typedef
	struct WinAPI_EMRANGLEARC {
		WinAPI_EMR emr;
		WinAPI_POINT ptlCenter;
		INTEGER nRadius;
		SHORTREAL eStartAngle, eSweepAngle;
	} WinAPI_EMRANGLEARC;

typedef
	struct WinAPI_EMRARC {
		WinAPI_EMR emr;
		WinAPI_RECT rclBox;
		WinAPI_POINT ptlStart, ptlEnd;
	} WinAPI_EMRARC;

typedef
	struct WinAPI_XFORM {
		SHORTREAL eM11, eM12, eM21, eM22, eDx, eDy;
	} WinAPI_XFORM;

typedef
	struct WinAPI_EMRBITBLT {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER xDest, yDest, cxDest, cyDest, dwRop, xSrc, ySrc;
		WinAPI_XFORM xformSrc;
		INTEGER crBkColorSrc, iUsageSrc, offBmiSrc, cbBmiSrc, offBitsSrc, cbBitsSrc;
	} WinAPI_EMRBITBLT;

typedef
	struct WinAPI_LOGBRUSH {
		INTEGER lbStyle, lbColor, lbHatch;
	} WinAPI_LOGBRUSH;

typedef
	struct WinAPI_EMRCREATEBRUSHINDIRECT {
		WinAPI_EMR emr;
		INTEGER ihBrush;
		WinAPI_LOGBRUSH lb;
	} WinAPI_EMRCREATEBRUSHINDIRECT;

typedef
	struct WinAPI_LOGCOLORSPACEW {
		INTEGER lcsSignature, lcsVersion, lcsSize, lcsCSType, lcsIntent;
		WinAPI_CIEXYZTRIPLE lcsEndpoints;
		INTEGER lcsGammaRed, lcsGammaGreen, lcsGammaBlue;
		SHORTINT lcsFilename[260];
	} WinAPI_LOGCOLORSPACEW;

typedef
	struct WinAPI_EMRCREATECOLORSPACE {
		WinAPI_EMR emr;
		INTEGER ihCS;
		WinAPI_LOGCOLORSPACEW lcs;
	} WinAPI_EMRCREATECOLORSPACE;

typedef
	struct WinAPI_EMRCREATEDIBPATTERNBRUSHPT {
		WinAPI_EMR emr;
		INTEGER ihBrush, iUsage, offBmi, cbBmi, offBits, cbBits;
	} WinAPI_EMRCREATEDIBPATTERNBRUSHPT;

typedef
	struct WinAPI_EMRCREATEMONOBRUSH {
		WinAPI_EMR emr;
		INTEGER ihBrush, iUsage, offBmi, cbBmi, offBits, cbBits;
	} WinAPI_EMRCREATEMONOBRUSH;

typedef
	struct WinAPI_PALETTEENTRY {
		CHAR peRed, peGreen, peBlue, peFlags;
	} WinAPI_PALETTEENTRY;

typedef
	struct WinAPI_LOGPALETTE {
		SHORTINT palVersion, palNumEntries;
		WinAPI_PALETTEENTRY palPalEntry[1];
	} WinAPI_LOGPALETTE;

typedef
	struct WinAPI_EMRCREATEPALETTE {
		WinAPI_EMR emr;
		INTEGER ihPal;
		WinAPI_LOGPALETTE lgpl;
	} WinAPI_EMRCREATEPALETTE;

typedef
	struct WinAPI_LOGPEN {
		INTEGER lopnStyle;
		WinAPI_POINT lopnWidth;
		INTEGER lopnColor;
	} WinAPI_LOGPEN;

typedef
	struct WinAPI_EMRCREATEPEN {
		WinAPI_EMR emr;
		INTEGER ihPen;
		WinAPI_LOGPEN lopn;
	} WinAPI_EMRCREATEPEN;

typedef
	struct WinAPI_EMRSELECTCOLORSPACE {
		WinAPI_EMR emr;
		INTEGER ihCS;
	} WinAPI_EMRSELECTCOLORSPACE;

typedef
	struct WinAPI_EMRSELECTOBJECT {
		WinAPI_EMR emr;
		INTEGER ihObject;
	} WinAPI_EMRSELECTOBJECT;

typedef
	struct WinAPI_EMRELLIPSE {
		WinAPI_EMR emr;
		WinAPI_RECT rclBox;
	} WinAPI_EMRELLIPSE;

typedef
	struct WinAPI_EMREOF {
		WinAPI_EMR emr;
		INTEGER nPalEntries, offPalEntries, nSizeLast;
	} WinAPI_EMREOF;

typedef
	struct WinAPI_EMREXCLUDECLIPRECT {
		WinAPI_EMR emr;
		WinAPI_RECT rclClip;
	} WinAPI_EMREXCLUDECLIPRECT;

typedef
	struct WinAPI_LOGFONTW {
		INTEGER lfHeight, lfWidth, lfEscapement, lfOrientation, lfWeight;
		CHAR lfItalic, lfUnderline, lfStrikeOut, lfCharSet, lfOutPrecision, lfClipPrecision, lfQuality, lfPitchAndFamily;
		SHORTINT lfFaceName[32];
	} WinAPI_LOGFONTW;

typedef
	struct WinAPI_PANOSE {
		CHAR bFamilyType, bSerifStyle, bWeight, bProportion, bContrast, bStrokeVariation, bArmStyle, bLetterform, bMidline, bXHeight;
	} WinAPI_PANOSE;

typedef
	struct WinAPI_EXTLOGFONTW {
		WinAPI_LOGFONTW elfLogFont;
		SHORTINT elfFullName[64];
		SHORTINT elfStyle[32];
		INTEGER elfVersion, elfStyleSize, elfMatch, elfReserved;
		CHAR elfVendorId[4];
		INTEGER elfCulture;
		WinAPI_PANOSE elfPanose;
	} WinAPI_EXTLOGFONTW;

typedef
	struct WinAPI_EMREXTCREATEFONTINDIRECTW {
		WinAPI_EMR emr;
		INTEGER ihFont;
		WinAPI_EXTLOGFONTW elfw;
	} WinAPI_EMREXTCREATEFONTINDIRECTW;

typedef
	struct WinAPI_EXTLOGPEN {
		INTEGER elpPenStyle, elpWidth, elpBrushStyle, elpColor, elpHatch, elpNumEntries;
		INTEGER elpStyleEntry[1];
	} WinAPI_EXTLOGPEN;

typedef
	struct WinAPI_EMREXTCREATEPEN {
		WinAPI_EMR emr;
		INTEGER ihPen, offBmi, cbBmi, offBits, cbBits;
		WinAPI_EXTLOGPEN elp;
	} WinAPI_EMREXTCREATEPEN;

typedef
	struct WinAPI_EMREXTFLOODFILL {
		WinAPI_EMR emr;
		WinAPI_POINT ptlStart;
		INTEGER crColor, iMode;
	} WinAPI_EMREXTFLOODFILL;

typedef
	struct WinAPI_EMREXTSELECTCLIPRGN {
		WinAPI_EMR emr;
		INTEGER cbRgnData, iMode;
		CHAR RgnData[1];
	} WinAPI_EMREXTSELECTCLIPRGN;

typedef
	struct WinAPI_EMRTEXT {
		WinAPI_POINT ptlReference;
		INTEGER nChars, offString, fOptions;
		WinAPI_RECT rcl;
		INTEGER offDx;
	} WinAPI_EMRTEXT;

typedef
	struct WinAPI_EMREXTTEXTOUTA {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER iGraphicsMode;
		SHORTREAL exScale, eyScale;
		WinAPI_EMRTEXT emrtext;
	} WinAPI_EMREXTTEXTOUTA;

typedef
	struct WinAPI_EMRFILLPATH {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
	} WinAPI_EMRFILLPATH;

typedef
	struct WinAPI_EMRFILLRGN {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER cbRgnData, ihBrush;
		CHAR RgnData[1];
	} WinAPI_EMRFILLRGN;

typedef
	struct WinAPI_EMRFORMAT {
		INTEGER dSignature, nVersion, cbData, offData;
	} WinAPI_EMRFORMAT;

typedef
	struct WinAPI_SIZE {
		INTEGER cx, cy;
	} WinAPI_SIZE;

typedef
	struct WinAPI_EMRFRAMERGN {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER cbRgnData, ihBrush;
		WinAPI_SIZE szlStroke;
		CHAR RgnData[1];
	} WinAPI_EMRFRAMERGN;

typedef
	struct WinAPI_EMRGDICOMMENT {
		WinAPI_EMR emr;
		INTEGER cbData;
		CHAR Data[1];
	} WinAPI_EMRGDICOMMENT;

typedef
	struct WinAPI_EMRGLSBOUNDEDRECORD {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER cbData;
		CHAR Data[1];
	} WinAPI_EMRGLSBOUNDEDRECORD;

typedef
	struct WinAPI_EMRGLSRECORD {
		WinAPI_EMR emr;
		INTEGER cbData;
		CHAR Data[1];
	} WinAPI_EMRGLSRECORD;

typedef
	struct WinAPI_EMRINVERTRGN {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER cbRgnData;
		CHAR RgnData[1];
	} WinAPI_EMRINVERTRGN;

typedef
	struct WinAPI_EMRLINETO {
		WinAPI_EMR emr;
		WinAPI_POINT ptl;
	} WinAPI_EMRLINETO;

typedef
	struct WinAPI_EMRMASKBLT {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER xDest, yDest, cxDest, cyDest, dwRop, xSrc, ySrc;
		WinAPI_XFORM xformSrc;
		INTEGER crBkColorSrc, iUsageSrc, offBmiSrc, cbBmiSrc, offBitsSrc, cbBitsSrc, xMask, yMask, iUsageMask, offBmiMask, cbBmiMask, offBitsMask, cbBitsMask;
	} WinAPI_EMRMASKBLT;

typedef
	struct WinAPI_EMRMODIFYWORLDTRANSFORM {
		WinAPI_EMR emr;
		WinAPI_XFORM xform;
		INTEGER iMode;
	} WinAPI_EMRMODIFYWORLDTRANSFORM;

typedef
	struct WinAPI_EMROFFSETCLIPRGN {
		WinAPI_EMR emr;
		WinAPI_POINT ptlOffset;
	} WinAPI_EMROFFSETCLIPRGN;

typedef
	struct WinAPI_PIXELFORMATDESCRIPTOR {
		SHORTINT nSize, nVersion;
		SET dwFlags;
		CHAR iPixelType, cColorBits, cRedBits, cRedShift, cGreenBits, cGreenShift, cBlueBits, cBlueShift, cAlphaBits, cAlphaShift, cAccumBits, cAccumRedBits, cAccumGreenBits, cAccumBlueBits, cAccumAlphaBits, cDepthBits, cStencilBits, cAuxBuffers, iLayerType, bReserved;
		SET dwLayerMask, dwVisibleMask, dwDamageMask;
	} WinAPI_PIXELFORMATDESCRIPTOR;

typedef
	struct WinAPI_EMRPIXELFORMAT {
		WinAPI_EMR emr;
		WinAPI_PIXELFORMATDESCRIPTOR pfd;
	} WinAPI_EMRPIXELFORMAT;

typedef
	struct WinAPI_EMRPLGBLT {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		WinAPI_POINT aptlDest[3];
		INTEGER xSrc, ySrc, cxSrc, cySrc;
		WinAPI_XFORM xformSrc;
		INTEGER crBkColorSrc, iUsageSrc, offBmiSrc, cbBmiSrc, offBitsSrc, cbBitsSrc, xMask, yMask, iUsageMask, offBmiMask, cbBmiMask, offBitsMask, cbBitsMask;
	} WinAPI_EMRPLGBLT;

typedef
	struct WinAPI_EMRPOLYLINE {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER cptl;
		WinAPI_POINT aptl[1];
	} WinAPI_EMRPOLYLINE;

typedef
	struct WinAPI_POINTS {
		SHORTINT x, y;
	} WinAPI_POINTS;

typedef
	struct WinAPI_EMRPOLYLINE16 {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER cpts;
		WinAPI_POINTS apts[1];
	} WinAPI_EMRPOLYLINE16;

typedef
	struct WinAPI_EMRPOLYDRAW {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER cptl;
		WinAPI_POINT aptl[1];
		CHAR abTypes[1];
	} WinAPI_EMRPOLYDRAW;

typedef
	struct WinAPI_EMRPOLYDRAW16 {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER cpts;
		WinAPI_POINTS apts[1];
		CHAR abTypes[1];
	} WinAPI_EMRPOLYDRAW16;

typedef
	struct WinAPI_EMRPOLYPOLYLINE {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER nPolys, cptl;
		INTEGER aPolyCounts[1];
		WinAPI_POINT aptl[1];
	} WinAPI_EMRPOLYPOLYLINE;

typedef
	struct WinAPI_EMRPOLYPOLYLINE16 {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER nPolys, cpts;
		INTEGER aPolyCounts[1];
		WinAPI_POINTS apts[1];
	} WinAPI_EMRPOLYPOLYLINE16;

typedef
	struct WinAPI_EMRPOLYTEXTOUTA {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER iGraphicsMode;
		SHORTREAL exScale, eyScale;
		INTEGER cStrings;
		WinAPI_EMRTEXT aemrtext[1];
	} WinAPI_EMRPOLYTEXTOUTA;

typedef
	struct WinAPI_EMRRESIZEPALETTE {
		WinAPI_EMR emr;
		INTEGER ihPal, cEntries;
	} WinAPI_EMRRESIZEPALETTE;

typedef
	struct WinAPI_EMRRESTOREDC {
		WinAPI_EMR emr;
		INTEGER iRelative;
	} WinAPI_EMRRESTOREDC;

typedef
	struct WinAPI_EMRROUNDRECT {
		WinAPI_EMR emr;
		WinAPI_RECT rclBox;
		WinAPI_SIZE szlCorner;
	} WinAPI_EMRROUNDRECT;

typedef
	struct WinAPI_EMRSCALEVIEWPORTEXTEX {
		WinAPI_EMR emr;
		INTEGER xNum, xDenom, yNum, yDenom;
	} WinAPI_EMRSCALEVIEWPORTEXTEX;

typedef
	struct WinAPI_EMRSELECTCLIPPATH {
		WinAPI_EMR emr;
		INTEGER iMode;
	} WinAPI_EMRSELECTCLIPPATH;

typedef
	struct WinAPI_EMRSELECTPALETTE {
		WinAPI_EMR emr;
		INTEGER ihPal;
	} WinAPI_EMRSELECTPALETTE;

typedef
	struct WinAPI_EMRSETARCDIRECTION {
		WinAPI_EMR emr;
		INTEGER iArcDirection;
	} WinAPI_EMRSETARCDIRECTION;

typedef
	struct WinAPI_EMRSETBKCOLOR {
		WinAPI_EMR emr;
		INTEGER crColor;
	} WinAPI_EMRSETBKCOLOR;

typedef
	struct WinAPI_EMRSETVIEWPORTORGEX {
		WinAPI_EMR emr;
		WinAPI_POINT ptlOrigin;
	} WinAPI_EMRSETVIEWPORTORGEX;

typedef
	struct WinAPI_EMRSETCOLORADJUSTMENT {
		WinAPI_EMR emr;
		WinAPI_COLORADJUSTMENT ColorAdjustment;
	} WinAPI_EMRSETCOLORADJUSTMENT;

typedef
	struct WinAPI_EMRSETDIBITSTODEVICE {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER xDest, yDest, xSrc, ySrc, cxSrc, cySrc, offBmiSrc, cbBmiSrc, offBitsSrc, cbBitsSrc, iUsageSrc, iStartScan, cScans;
	} WinAPI_EMRSETDIBITSTODEVICE;

typedef
	struct WinAPI_EMRSETMAPPERFLAGS {
		WinAPI_EMR emr;
		SET dwFlags;
	} WinAPI_EMRSETMAPPERFLAGS;

typedef
	struct WinAPI_EMRSETMITERLIMIT {
		WinAPI_EMR emr;
		SHORTREAL eMiterLimit;
	} WinAPI_EMRSETMITERLIMIT;

typedef
	struct WinAPI_EMRSETPALETTEENTRIES {
		WinAPI_EMR emr;
		INTEGER ihPal, iStart, cEntries;
		WinAPI_PALETTEENTRY aPalEntries[1];
	} WinAPI_EMRSETPALETTEENTRIES;

typedef
	struct WinAPI_EMRSETPIXELV {
		WinAPI_EMR emr;
		WinAPI_POINT ptlPixel;
		INTEGER crColor;
	} WinAPI_EMRSETPIXELV;

typedef
	struct WinAPI_EMRSETVIEWPORTEXTEX {
		WinAPI_EMR emr;
		WinAPI_SIZE szlExtent;
	} WinAPI_EMRSETVIEWPORTEXTEX;

typedef
	struct WinAPI_EMRSETWORLDTRANSFORM {
		WinAPI_EMR emr;
		WinAPI_XFORM xform;
	} WinAPI_EMRSETWORLDTRANSFORM;

typedef
	struct WinAPI_EMRSTRETCHBLT {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER xDest, yDest, cxDest, cyDest, dwRop, xSrc, ySrc;
		WinAPI_XFORM xformSrc;
		INTEGER crBkColorSrc, iUsageSrc, offBmiSrc, cbBmiSrc, offBitsSrc, cbBitsSrc, cxSrc, cySrc;
	} WinAPI_EMRSTRETCHBLT;

typedef
	struct WinAPI_EMRSTRETCHDIBITS {
		WinAPI_EMR emr;
		WinAPI_RECT rclBounds;
		INTEGER xDest, yDest, xSrc, ySrc, cxSrc, cySrc, offBmiSrc, cbBmiSrc, offBitsSrc, cbBitsSrc, iUsageSrc, dwRop, cxDest, cyDest;
	} WinAPI_EMRSTRETCHDIBITS;

typedef
	struct WinAPI_ENHMETAHEADER {
		INTEGER iType, nSize;
		WinAPI_RECT rclBounds, rclFrame;
		INTEGER dSignature, nVersion, nBytes, nRecords;
		SHORTINT nHandles, sReserved;
		INTEGER nDescription, offDescription, nPalEntries;
		WinAPI_SIZE szlDevice, szlMillimeters;
		INTEGER cbPixelFormat, offPixelFormat, bOpenGL;
	} WinAPI_ENHMETAHEADER;

typedef
	struct WinAPI_ENHMETARECORD {
		INTEGER iType, nSize;
		INTEGER dParm[1];
	} WinAPI_ENHMETARECORD;

typedef
	struct WinAPI_HANDLETABLE {
		LONGINT objectHandle[1];
	} WinAPI_HANDLETABLE;

typedef
	INTEGER (__STDCALL *WinAPI_ENHMFENUMPROC)(LONGINT, WinAPI_HANDLETABLE*, WinAPI_ENHMETARECORD*, INTEGER, LONGINT);

typedef
	struct WinAPI_LOGFONTA {
		INTEGER lfHeight, lfWidth, lfEscapement, lfOrientation, lfWeight;
		CHAR lfItalic, lfUnderline, lfStrikeOut, lfCharSet, lfOutPrecision, lfClipPrecision, lfQuality, lfPitchAndFamily;
		CHAR lfFaceName[32];
	} WinAPI_LOGFONTA;

typedef
	struct WinAPI_ENUMLOGFONTA {
		WinAPI_LOGFONTA elfLogFont;
		CHAR elfFullName[64];
		CHAR elfStyle[32];
	} WinAPI_ENUMLOGFONTA;

typedef
	struct WinAPI_ENUMLOGFONTEXA {
		WinAPI_LOGFONTA elfLogFont;
		CHAR elfFullName[64];
		CHAR elfStyle[32];
		CHAR elfScript[32];
	} WinAPI_ENUMLOGFONTEXA;

typedef
	struct WinAPI_ENUMLOGFONTEXW {
		WinAPI_LOGFONTW elfLogFont;
		SHORTINT elfFullName[64];
		SHORTINT elfStyle[32];
		SHORTINT elfScript[32];
	} WinAPI_ENUMLOGFONTEXW;

typedef
	struct WinAPI_ENUMLOGFONTW {
		WinAPI_LOGFONTW elfLogFont;
		SHORTINT elfFullName[64];
		SHORTINT elfStyle[32];
	} WinAPI_ENUMLOGFONTW;

typedef
	INTEGER (__STDCALL *WinAPI_ENUMRESLANGPROC)(void);

typedef
	INTEGER (__STDCALL *WinAPI_ENUMRESNAMEPROC)(void);

typedef
	INTEGER (__STDCALL *WinAPI_ENUMRESTYPEPROC)(void);

typedef
	struct WinAPI_SERVICE_STATUS {
		SET dwServiceType;
		INTEGER dwCurrentState, dwControlsAccepted, dwWin32ExitCode, dwServiceSpecificExitCode, dwCheckPoint, dwWaitHint;
	} WinAPI_SERVICE_STATUS;

typedef
	struct WinAPI_ENUM_SERVICE_STATUSA {
		LONGINT lpServiceName, lpDisplayName;
		WinAPI_SERVICE_STATUS ServiceStatus;
	} WinAPI_ENUM_SERVICE_STATUSA;

typedef
	struct WinAPI_ENUM_SERVICE_STATUSW {
		LONGINT lpServiceName, lpDisplayName;
		WinAPI_SERVICE_STATUS ServiceStatus;
	} WinAPI_ENUM_SERVICE_STATUSW;

typedef
	struct WinAPI_EVENTLOGRECORD {
		INTEGER Length, Reserved, RecordNumber, TimeGenerated, TimeWritten, EventID;
		SHORTINT EventType, NumStrings, EventCategory, ReservedFlags;
		INTEGER ClosingRecordNumber, StringOffset, UserSidLength, UserSidOffset, DataLength, DataOffset;
	} WinAPI_EVENTLOGRECORD;

typedef
	struct WinAPI_EVENTMSG {
		INTEGER message, paramL, paramH, time;
		LONGINT hwnd;
	} WinAPI_EVENTMSG;

typedef
	WinAPI_CONTEXT *WinAPI_PtrCONTEXT;

typedef
	struct WinAPI_EXCEPTION_POINTERS {
		WinAPI_PtrEXCEPTION_RECORD ExceptionRecord;
		WinAPI_PtrCONTEXT ContextRecord;
	} WinAPI_EXCEPTION_POINTERS;

typedef
	struct WinAPI_EXIT_PROCESS_DEBUG_INFO {
		INTEGER dwExitCode;
	} WinAPI_EXIT_PROCESS_DEBUG_INFO;

typedef
	struct WinAPI_EXIT_THREAD_DEBUG_INFO {
		INTEGER dwExitCode;
	} WinAPI_EXIT_THREAD_DEBUG_INFO;

typedef
	struct WinAPI_EXTLOGFONTA {
		WinAPI_LOGFONTA elfLogFont;
		CHAR elfFullName[64];
		CHAR elfStyle[32];
		INTEGER elfVersion, elfStyleSize, elfMatch, elfReserved;
		CHAR elfVendorId[4];
		INTEGER elfCulture;
		WinAPI_PANOSE elfPanose;
	} WinAPI_EXTLOGFONTA;

typedef
	INTEGER (__STDCALL *WinAPI_FARPROC)(void);

typedef
	void (__STDCALL *WinAPI_FIBER_START_ROUTINE)(LONGINT);

typedef
	struct WinAPI_FILE_NOTIFY_INFORMATION {
		INTEGER NextEntryOffset, Action, FileNameLength;
		SHORTINT FileName[1];
	} WinAPI_FILE_NOTIFY_INFORMATION;

typedef
	struct WinAPI_FILTERKEYS {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER iWaitMSec, iDelayMSec, iRepeatMSec, iBounceMSec;
	} WinAPI_FILTERKEYS;

typedef
	struct WinAPI_FIXED {
		SHORTINT fract, value;
	} WinAPI_FIXED;

typedef
	struct WinAPI__PSP *WinAPI_Ptr_PSP;

typedef
	INTEGER (__STDCALL *WinAPI_FNADDPROPSHEETPAGE)(WinAPI_Ptr_PSP, LONGINT);

typedef
	INTEGER (__STDCALL *WinAPI_FNADDPROPSHEETPAGES)(LONGINT, WinAPI_FNADDPROPSHEETPAGE, LONGINT);

typedef
	LONGINT (__STDCALL *WinAPI_FNCALLBACK)(INTEGER, INTEGER, LONGINT, LONGINT, LONGINT, LONGINT, INTEGER, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_FNDEVCAPS)(LONGINT, LONGINT, INTEGER, LONGINT, WinAPI_DEVMODEA*);

typedef
	INTEGER (__STDCALL *WinAPI_FNDEVMODE)(LONGINT, LONGINT, WinAPI_DEVMODEA*, LONGINT, LONGINT, WinAPI_DEVMODEA*, LONGINT, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_FNPROPSHEETCALLBACK)(LONGINT, INTEGER, LONGINT);

typedef
	INTEGER (__STDCALL *WinAPI_FNPSPCALLBACKA)(LONGINT, INTEGER, WinAPI_PtrPROPSHEETPAGEA);

typedef
	INTEGER (__STDCALL *WinAPI_FNPSPCALLBACKW)(LONGINT, INTEGER, WinAPI_PtrPROPSHEETPAGEW);

typedef
	struct WinAPI_FOCUS_EVENT_RECORD {
		INTEGER bSetFocus;
	} WinAPI_FOCUS_EVENT_RECORD;

typedef
	INTEGER (__STDCALL *WinAPI_FONTENUMPROC)(LONGINT, LONGINT, INTEGER, LONGINT);

typedef
	INTEGER (__STDCALL *WinAPI_FONTENUMPROCA)(LONGINT, LONGINT, INTEGER, LONGINT);

typedef
	INTEGER (__STDCALL *WinAPI_FONTENUMPROCEX)(LONGINT, LONGINT, INTEGER, LONGINT);

typedef
	INTEGER (__STDCALL *WinAPI_FONTENUMPROCEXA)(LONGINT, LONGINT, INTEGER, LONGINT);

typedef
	INTEGER (__STDCALL *WinAPI_FONTENUMPROCEXW)(LONGINT, LONGINT, INTEGER, LONGINT);

typedef
	INTEGER (__STDCALL *WinAPI_FONTENUMPROCW)(LONGINT, LONGINT, INTEGER, LONGINT);

typedef
	struct WinAPI_FORM_INFO_1A {
		SET Flags;
		LONGINT pName;
		WinAPI_SIZE Size;
		WinAPI_RECT ImageableArea;
	} WinAPI_FORM_INFO_1A;

typedef
	struct WinAPI_FORM_INFO_1W {
		SET Flags;
		LONGINT pName;
		WinAPI_SIZE Size;
		WinAPI_RECT ImageableArea;
	} WinAPI_FORM_INFO_1W;

typedef
	struct WinAPI_FPO_DATA {
		INTEGER ulOffStart, cbProcSize, cdwLocals;
		SHORTINT cdwParams, fBits0;
	} WinAPI_FPO_DATA;

typedef
	struct WinAPI_GCP_RESULTSA {
		INTEGER lStructSize;
		LONGINT lpOutString, lpOrder, lpDx, lpCaretPos, lpClass, lpGlyphs;
		INTEGER nGlyphs, nMaxFit;
	} WinAPI_GCP_RESULTSA;

typedef
	struct WinAPI_GCP_RESULTSW {
		INTEGER lStructSize;
		LONGINT lpOutString, lpOrder, lpDx, lpCaretPos, lpClass, lpGlyphs;
		INTEGER nGlyphs, nMaxFit;
	} WinAPI_GCP_RESULTSW;

typedef
	struct WinAPI_GENERIC_MAPPING {
		SET GenericRead, GenericWrite, GenericExecute, GenericAll;
	} WinAPI_GENERIC_MAPPING;

typedef
	struct WinAPI_GLYPHMETRICS {
		INTEGER gmBlackBoxX, gmBlackBoxY;
		WinAPI_POINT gmptGlyphOrigin;
		SHORTINT gmCellIncX, gmCellIncY;
	} WinAPI_GLYPHMETRICS;

typedef
	struct WinAPI_POINTFLOAT {
		SHORTREAL x, y;
	} WinAPI_POINTFLOAT;

typedef
	struct WinAPI_GLYPHMETRICSFLOAT {
		SHORTREAL gmfBlackBoxX, gmfBlackBoxY;
		WinAPI_POINTFLOAT gmfptGlyphOrigin;
		SHORTREAL gmfCellIncX, gmfCellIncY;
	} WinAPI_GLYPHMETRICSFLOAT;

typedef
	INTEGER (__STDCALL *WinAPI_GOBJENUMPROC)(void);

typedef
	INTEGER (__STDCALL *WinAPI_GRAYSTRINGPROC)(void);

typedef
	void (__STDCALL *WinAPI_HANDLER_FUNCTION)(INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_HANDLER_ROUTINE)(INTEGER);

typedef
	struct WinAPI_HARDWAREHOOKSTRUCT {
		LONGINT hwnd;
		INTEGER message;
		LONGINT wParam, lParam;
	} WinAPI_HARDWAREHOOKSTRUCT;

typedef
	struct WinAPI_HELPINFO {
		INTEGER cbSize, iContextType, iCtrlId;
		LONGINT hItemHandle;
		INTEGER dwContextId;
		WinAPI_POINT MousePos;
	} WinAPI_HELPINFO;

typedef
	struct WinAPI_HELPWININFOA {
		INTEGER wStructSize, x, y, dx, dy, wMax;
		CHAR rgchMember[2];
	} WinAPI_HELPWININFOA;

typedef
	struct WinAPI_HELPWININFOW {
		INTEGER wStructSize, x, y, dx, dy, wMax;
		SHORTINT rgchMember[2];
	} WinAPI_HELPWININFOW;

typedef
	struct WinAPI_HIGHCONTRASTA {
		INTEGER cbSize;
		SET dwFlags;
		LONGINT lpszDefaultScheme;
	} WinAPI_HIGHCONTRASTA;

typedef
	struct WinAPI_HIGHCONTRASTW {
		INTEGER cbSize;
		SET dwFlags;
		LONGINT lpszDefaultScheme;
	} WinAPI_HIGHCONTRASTW;

typedef
	INTEGER (__STDCALL *WinAPI_HOOKPROC)(void);

typedef
	struct WinAPI_HSZPAIR {
		LONGINT hszSvc, hszTopic;
	} WinAPI_HSZPAIR;

typedef
	struct WinAPI_HW_PROFILE_INFOA {
		INTEGER dwDockInfo;
		CHAR szHwProfileGuid[39];
		CHAR szHwProfileName[80];
	} WinAPI_HW_PROFILE_INFOA;

typedef
	struct WinAPI_HW_PROFILE_INFOW {
		INTEGER dwDockInfo;
		SHORTINT szHwProfileGuid[39];
		SHORTINT szHwProfileName[80];
	} WinAPI_HW_PROFILE_INFOW;

typedef
	INTEGER (__STDCALL *WinAPI_ICMENUMPROCA)(LONGINT, LONGINT);

typedef
	INTEGER (__STDCALL *WinAPI_ICMENUMPROCW)(LONGINT, LONGINT);

typedef
	struct WinAPI_ICONINFO {
		INTEGER fIcon, xHotspot, yHotspot;
		LONGINT hbmMask, hbmColor;
	} WinAPI_ICONINFO;

typedef
	struct WinAPI_ICONMETRICSA {
		INTEGER cbSize, iHorzSpacing, iVertSpacing, iTitleWrap;
		WinAPI_LOGFONTA lfFont;
	} WinAPI_ICONMETRICSA;

typedef
	struct WinAPI_ICONMETRICSW {
		INTEGER cbSize, iHorzSpacing, iVertSpacing, iTitleWrap;
		WinAPI_LOGFONTW lfFont;
	} WinAPI_ICONMETRICSW;

typedef
	struct WinAPI_IMAGE_ARCHIVE_MEMBER_HEADER {
		CHAR Name[16];
		CHAR Date[12];
		CHAR UserID[6];
		CHAR GroupID[6];
		CHAR Mode[8];
		CHAR Size[10];
		CHAR EndHeader[2];
	} WinAPI_IMAGE_ARCHIVE_MEMBER_HEADER;

typedef
	struct WinAPI_IMAGE_AUX_SYMBOL {
		struct WinAPI__10 Sym;
	} WinAPI_IMAGE_AUX_SYMBOL;

typedef
	struct WinAPI_IMAGE_BASE_RELOCATION {
		INTEGER VirtualAddress, SizeOfBlock;
	} WinAPI_IMAGE_BASE_RELOCATION;

typedef
	struct WinAPI_IMAGE_BOUND_FORWARDER_REF {
		INTEGER TimeDateStamp;
		SHORTINT OffsetModuleName, Reserved;
	} WinAPI_IMAGE_BOUND_FORWARDER_REF;

typedef
	struct WinAPI_IMAGE_BOUND_IMPORT_DESCRIPTOR {
		INTEGER TimeDateStamp;
		SHORTINT OffsetModuleName, NumberOfModuleForwarderRefs;
	} WinAPI_IMAGE_BOUND_IMPORT_DESCRIPTOR;

typedef
	struct WinAPI_IMAGE_COFF_SYMBOLS_HEADER {
		INTEGER NumberOfSymbols, LvaToFirstSymbol, NumberOfLinenumbers, LvaToFirstLinenumber, RvaToFirstByteOfCode, RvaToLastByteOfCode, RvaToFirstByteOfData, RvaToLastByteOfData;
	} WinAPI_IMAGE_COFF_SYMBOLS_HEADER;

typedef
	struct WinAPI_IMAGE_DATA_DIRECTORY {
		INTEGER VirtualAddress, Size;
	} WinAPI_IMAGE_DATA_DIRECTORY;

typedef
	struct WinAPI_IMAGE_DEBUG_DIRECTORY {
		INTEGER Characteristics, TimeDateStamp;
		SHORTINT MajorVersion, MinorVersion;
		INTEGER Type, SizeOfData, AddressOfRawData, PointerToRawData;
	} WinAPI_IMAGE_DEBUG_DIRECTORY;

typedef
	struct WinAPI_IMAGE_DEBUG_MISC {
		INTEGER DataType, Length;
		BOOLEAN Unicode;
		CHAR Reserved[3];
		CHAR Data[1];
	} WinAPI_IMAGE_DEBUG_MISC;

typedef
	struct WinAPI_IMAGE_DOS_HEADER {
		SHORTINT e_magic, e_cblp, e_cp, e_crlc, e_cparhdr, e_minalloc, e_maxalloc, e_ss, e_sp, e_csum, e_ip, e_cs, e_lfarlc, e_ovno;
		SHORTINT e_res[4];
		SHORTINT e_oemid, e_oeminfo;
		SHORTINT e_res2[10];
		INTEGER e_lfanew;
	} WinAPI_IMAGE_DOS_HEADER;

typedef
	struct WinAPI_IMAGE_EXPORT_DIRECTORY {
		INTEGER Characteristics, TimeDateStamp;
		SHORTINT MajorVersion, MinorVersion;
		INTEGER Name, Base, NumberOfFunctions, NumberOfNames;
		LONGINT AddressOfFunctions, AddressOfNames, AddressOfNameOrdinals;
	} WinAPI_IMAGE_EXPORT_DIRECTORY;

typedef
	struct WinAPI_IMAGE_FILE_HEADER {
		SHORTINT Machine, NumberOfSections;
		INTEGER TimeDateStamp, PointerToSymbolTable, NumberOfSymbols;
		SHORTINT SizeOfOptionalHeader, Characteristics;
	} WinAPI_IMAGE_FILE_HEADER;

typedef
	struct WinAPI_IMAGE_FUNCTION_ENTRY {
		INTEGER StartingAddress, EndingAddress, EndOfPrologue;
	} WinAPI_IMAGE_FUNCTION_ENTRY;

typedef
	struct WinAPI_IMAGE_IMPORT_BY_NAME {
		SHORTINT Hint;
		CHAR Name[1];
	} WinAPI_IMAGE_IMPORT_BY_NAME;

typedef
	struct WinAPI_IMAGE_IMPORT_DESCRIPTOR {
		struct WinAPI__12 u;
		INTEGER TimeDateStamp, ForwarderChain, Name;
		WinAPI_PtrIMAGE_THUNK_DATA FirstThunk;
	} WinAPI_IMAGE_IMPORT_DESCRIPTOR;

typedef
	struct WinAPI_IMAGE_LINENUMBER {
		struct WinAPI__13 Type;
		SHORTINT Linenumber;
	} WinAPI_IMAGE_LINENUMBER;

typedef
	struct WinAPI_IMAGE_LOAD_CONFIG_DIRECTORY {
		INTEGER Characteristics, TimeDateStamp;
		SHORTINT MajorVersion, MinorVersion;
		INTEGER GlobalFlagsClear, GlobalFlagsSet, CriticalSectionDefaultTimeout, DeCommitFreeBlockThreshold, DeCommitTotalFreeThreshold;
		LONGINT LockPrefixTable;
		INTEGER MaximumAllocationSize, VirtualMemoryThreshold, ProcessHeapFlags;
		INTEGER Reserved[4];
	} WinAPI_IMAGE_LOAD_CONFIG_DIRECTORY;

typedef
	struct WinAPI_IMAGE_OPTIONAL_HEADER {
		SHORTINT Magic;
		CHAR MajorLinkerVersion, MinorLinkerVersion;
		INTEGER SizeOfCode, SizeOfInitializedData, SizeOfUninitializedData, AddressOfEntryPoint, BaseOfCode, BaseOfData, ImageBase, SectionAlignment, FileAlignment;
		SHORTINT MajorOperatingSystemVersion, MinorOperatingSystemVersion, MajorImageVersion, MinorImageVersion, MajorSubsystemVersion, MinorSubsystemVersion;
		INTEGER Reserved1, SizeOfImage, SizeOfHeaders, CheckSum;
		SHORTINT Subsystem, DllCharacteristics;
		INTEGER SizeOfStackReserve, SizeOfStackCommit, SizeOfHeapReserve, SizeOfHeapCommit, LoaderFlags, NumberOfRvaAndSizes;
		WinAPI_IMAGE_DATA_DIRECTORY DataDirectory[16];
	} WinAPI_IMAGE_OPTIONAL_HEADER;

typedef
	struct WinAPI_IMAGE_NT_HEADERS {
		INTEGER Signature;
		WinAPI_IMAGE_FILE_HEADER FileHeader;
		WinAPI_IMAGE_OPTIONAL_HEADER OptionalHeader;
	} WinAPI_IMAGE_NT_HEADERS;

typedef
	struct WinAPI_IMAGE_OS2_HEADER {
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
	} WinAPI_IMAGE_OS2_HEADER;

typedef
	struct WinAPI_IMAGE_RELOCATION {
		struct WinAPI__14 u;
		INTEGER SymbolTableIndex;
		SHORTINT Type;
	} WinAPI_IMAGE_RELOCATION;

typedef
	struct WinAPI_IMAGE_RESOURCE_DATA_ENTRY {
		INTEGER OffsetToData, Size, CodePage, Reserved;
	} WinAPI_IMAGE_RESOURCE_DATA_ENTRY;

typedef
	struct WinAPI_IMAGE_RESOURCE_DIRECTORY {
		INTEGER Characteristics, TimeDateStamp;
		SHORTINT MajorVersion, MinorVersion, NumberOfNamedEntries, NumberOfIdEntries;
	} WinAPI_IMAGE_RESOURCE_DIRECTORY;

typedef
	struct WinAPI_IMAGE_RESOURCE_DIRECTORY_ENTRY {
		struct WinAPI__16 u;
		struct WinAPI__17 u1;
	} WinAPI_IMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef
	struct WinAPI_IMAGE_RESOURCE_DIRECTORY_STRING {
		SHORTINT Length;
		CHAR NameString[1];
	} WinAPI_IMAGE_RESOURCE_DIRECTORY_STRING;

typedef
	struct WinAPI_IMAGE_RESOURCE_DIR_STRING_U {
		SHORTINT Length;
		SHORTINT NameString[1];
	} WinAPI_IMAGE_RESOURCE_DIR_STRING_U;

typedef
	struct WinAPI_IMAGE_ROM_OPTIONAL_HEADER {
		SHORTINT Magic;
		CHAR MajorLinkerVersion, MinorLinkerVersion;
		INTEGER SizeOfCode, SizeOfInitializedData, SizeOfUninitializedData, AddressOfEntryPoint, BaseOfCode, BaseOfData, BaseOfBss, GprMask;
		INTEGER CprMask[4];
		INTEGER GpValue;
	} WinAPI_IMAGE_ROM_OPTIONAL_HEADER;

typedef
	struct WinAPI_IMAGE_ROM_HEADERS {
		WinAPI_IMAGE_FILE_HEADER FileHeader;
		WinAPI_IMAGE_ROM_OPTIONAL_HEADER OptionalHeader;
	} WinAPI_IMAGE_ROM_HEADERS;

typedef
	struct WinAPI_IMAGE_RUNTIME_FUNCTION_ENTRY {
		INTEGER BeginAddress, EndAddress;
		LONGINT ExceptionHandler, HandlerData;
		INTEGER PrologEndAddress;
	} WinAPI_IMAGE_RUNTIME_FUNCTION_ENTRY;

typedef
	struct WinAPI_IMAGE_SECTION_HEADER {
		CHAR Name[8];
		struct WinAPI__18 Misc;
		INTEGER VirtualAddress, SizeOfRawData, PointerToRawData, PointerToRelocations, PointerToLinenumbers;
		SHORTINT NumberOfRelocations, NumberOfLinenumbers;
		INTEGER Characteristics;
	} WinAPI_IMAGE_SECTION_HEADER;

typedef
	struct WinAPI_IMAGE_SEPARATE_DEBUG_HEADER {
		SHORTINT Signature, Flags, Machine, Characteristics;
		INTEGER TimeDateStamp, CheckSum, ImageBase, SizeOfImage, NumberOfSections, ExportedNamesSize, DebugDirectorySize;
		INTEGER Reserved[3];
	} WinAPI_IMAGE_SEPARATE_DEBUG_HEADER;

typedef
	struct WinAPI_IMAGE_SYMBOL {
		struct WinAPI__19 N;
		INTEGER Value;
		SHORTINT SectionNumber, Type;
		CHAR StorageClass, NumberOfAuxSymbols;
	} WinAPI_IMAGE_SYMBOL;

typedef
	struct WinAPI_IMAGE_THUNK_DATA {
		struct WinAPI__11 u1;
	} WinAPI_IMAGE_THUNK_DATA;

typedef
	void (__STDCALL *WinAPI_IMAGE_TLS_CALLBACK)(LONGINT, INTEGER, LONGINT);

typedef
	struct WinAPI_IMAGE_TLS_DIRECTORY {
		INTEGER StartAddressOfRawData, EndAddressOfRawData;
		LONGINT AddressOfIndex, AddressOfCallBacks;
		INTEGER SizeOfZeroFill, Characteristics;
	} WinAPI_IMAGE_TLS_DIRECTORY;

typedef
	struct WinAPI_IMAGE_VXD_HEADER {
		SHORTINT e32_magic;
		CHAR e32_border, e32_worder;
		INTEGER e32_level;
		SHORTINT e32_cpu, e32_os;
		INTEGER e32_ver, e32_mflags, e32_mpages, e32_startobj, e32_eip, e32_stackobj, e32_esp, e32_pagesize, e32_lastpagesize, e32_fixupsize, e32_fixupsum, e32_ldrsize, e32_ldrsum, e32_objtab, e32_objcnt, e32_objmap, e32_itermap, e32_rsrctab, e32_rsrccnt, e32_restab, e32_enttab, e32_dirtab, e32_dircnt, e32_fpagetab, e32_frectab, e32_impmod, e32_impmodcnt, e32_impproc, e32_pagesum, e32_datapage, e32_preload, e32_nrestab, e32_cbnrestab, e32_nressum, e32_autodata, e32_debuginfo, e32_debuglen, e32_instpreload, e32_instdemand, e32_heapsize;
		CHAR e32_res3[12];
		INTEGER e32_winresoff, e32_winreslen;
		SHORTINT e32_devid, e32_ddkver;
	} WinAPI_IMAGE_VXD_HEADER;

typedef
	struct WinAPI_INPUT_RECORD {
		SHORTINT EventType;
		struct WinAPI__21 Event;
	} WinAPI_INPUT_RECORD;

typedef
	struct WinAPI_SYSTEMTIME {
		SHORTINT wYear, wMonth, wDayOfWeek, wDay, wHour, wMinute, wSecond, wMilliseconds;
	} WinAPI_SYSTEMTIME;

typedef
	struct WinAPI_JOB_INFO_1A {
		INTEGER JobId;
		LONGINT pPrinterName, pMachineName, pUserName, pDocument, pDatatype, pStatus;
		SET Status;
		INTEGER Priority, Position, TotalPages, PagesPrinted;
		WinAPI_SYSTEMTIME Submitted;
	} WinAPI_JOB_INFO_1A;

typedef
	struct WinAPI_JOB_INFO_1W {
		INTEGER JobId;
		LONGINT pPrinterName, pMachineName, pUserName, pDocument, pDatatype, pStatus;
		SET Status;
		INTEGER Priority, Position, TotalPages, PagesPrinted;
		WinAPI_SYSTEMTIME Submitted;
	} WinAPI_JOB_INFO_1W;

typedef
	WinAPI_DEVMODEA *WinAPI_PtrDEVMODEA;

typedef
	struct WinAPI_JOB_INFO_2A {
		INTEGER JobId;
		LONGINT pPrinterName, pMachineName, pUserName, pDocument, pNotifyName, pDatatype, pPrintProcessor, pParameters, pDriverName;
		WinAPI_PtrDEVMODEA pDevMode;
		LONGINT pStatus, pSecurityDescriptor;
		SET Status;
		INTEGER Priority, Position, StartTime, UntilTime, TotalPages, Size;
		WinAPI_SYSTEMTIME Submitted;
		INTEGER Time, PagesPrinted;
	} WinAPI_JOB_INFO_2A;

typedef
	WinAPI_DEVMODEW *WinAPI_PtrDEVMODEW;

typedef
	struct WinAPI_JOB_INFO_2W {
		INTEGER JobId;
		LONGINT pPrinterName, pMachineName, pUserName, pDocument, pNotifyName, pDatatype, pPrintProcessor, pParameters, pDriverName;
		WinAPI_PtrDEVMODEW pDevMode;
		LONGINT pStatus, pSecurityDescriptor;
		SET Status;
		INTEGER Priority, Position, StartTime, UntilTime, TotalPages, Size;
		WinAPI_SYSTEMTIME Submitted;
		INTEGER Time, PagesPrinted;
	} WinAPI_JOB_INFO_2W;

typedef
	struct WinAPI_KERNINGPAIR {
		SHORTINT wFirst, wSecond;
		INTEGER iKernAmount;
	} WinAPI_KERNINGPAIR;

typedef
	struct WinAPI_LAYERPLANEDESCRIPTOR {
		SHORTINT nSize, nVersion;
		SET dwFlags;
		CHAR iPixelType, cColorBits, cRedBits, cRedShift, cGreenBits, cGreenShift, cBlueBits, cBlueShift, cAlphaBits, cAlphaShift, cAccumBits, cAccumRedBits, cAccumGreenBits, cAccumBlueBits, cAccumAlphaBits, cDepthBits, cStencilBits, cAuxBuffers, iLayerPlane, bReserved;
		INTEGER crTransparent;
	} WinAPI_LAYERPLANEDESCRIPTOR;

typedef
	struct WinAPI_LDT_ENTRY {
		SHORTINT LimitLow, BaseLow;
		struct WinAPI__23 HighWord;
	} WinAPI_LDT_ENTRY;

typedef
	INTEGER (__STDCALL *WinAPI_LINEDDAPROC)(void);

typedef
	struct WinAPI_LOAD_DLL_DEBUG_INFO {
		LONGINT hFile, lpBaseOfDll;
		INTEGER dwDebugInfoFileOffset, nDebugInfoSize;
		LONGINT lpImageName;
		SHORTINT fUnicode;
	} WinAPI_LOAD_DLL_DEBUG_INFO;

typedef
	struct WinAPI_LOCALESIGNATURE {
		INTEGER lsUsb[4];
		INTEGER lsCsbDefault[2];
		INTEGER lsCsbSupported[2];
	} WinAPI_LOCALESIGNATURE;

typedef
	INTEGER (__STDCALL *WinAPI_LOCALE_ENUMPROCA)(void);

typedef
	INTEGER (__STDCALL *WinAPI_LOCALE_ENUMPROCW)(void);

typedef
	struct WinAPI_LOGCOLORSPACEA {
		INTEGER lcsSignature, lcsVersion, lcsSize, lcsCSType, lcsIntent;
		WinAPI_CIEXYZTRIPLE lcsEndpoints;
		INTEGER lcsGammaRed, lcsGammaGreen, lcsGammaBlue;
		CHAR lcsFilename[260];
	} WinAPI_LOGCOLORSPACEA;

typedef
	struct WinAPI_LUID_AND_ATTRIBUTES {
		LONGINT Luid;
		SET Attributes;
	} WinAPI_LUID_AND_ATTRIBUTES;

typedef
	WinAPI_LUID_AND_ATTRIBUTES WinAPI_LUID_AND_ATTRIBUTES_ARRAY[1];

typedef
	struct WinAPI_MAT2 {
		WinAPI_FIXED eM11, eM12, eM21, eM22;
	} WinAPI_MAT2;

typedef
	struct WinAPI_MDICREATESTRUCTA {
		LONGINT szClass, szTitle, hOwner;
		INTEGER x, y, cx, cy;
		SET style;
		LONGINT lParam;
	} WinAPI_MDICREATESTRUCTA;

typedef
	struct WinAPI_MDICREATESTRUCTW {
		LONGINT szClass, szTitle, hOwner;
		INTEGER x, y, cx, cy;
		SET style;
		LONGINT lParam;
	} WinAPI_MDICREATESTRUCTW;

typedef
	struct WinAPI_MDINEXTMENU {
		LONGINT hmenuIn, hmenuNext, hwndNext;
	} WinAPI_MDINEXTMENU;

typedef
	struct WinAPI_MEASUREITEMSTRUCT {
		SET CtlType;
		INTEGER CtlID, itemID, itemWidth, itemHeight, itemData;
	} WinAPI_MEASUREITEMSTRUCT;

typedef
	struct WinAPI_MEMORYSTATUS {
		INTEGER dwLength, dwMemoryLoad, dwTotalPhys, dwAvailPhys, dwTotalPageFile, dwAvailPageFile, dwTotalVirtual, dwAvailVirtual;
	} WinAPI_MEMORYSTATUS;

typedef
	struct WinAPI_MEMORY_BASIC_INFORMATION {
		LONGINT BaseAddress, AllocationBase;
		INTEGER AllocationProtect, RegionSize, State, Protect, Type;
	} WinAPI_MEMORY_BASIC_INFORMATION;

typedef
	struct WinAPI_MENUITEMINFOA {
		INTEGER cbSize;
		SET fMask, fType, fState;
		INTEGER wID;
		LONGINT hSubMenu, hbmpChecked, hbmpUnchecked;
		INTEGER dwItemData;
		LONGINT dwTypeData;
		INTEGER cch;
	} WinAPI_MENUITEMINFOA;

typedef
	struct WinAPI_MENUITEMINFOW {
		INTEGER cbSize;
		SET fMask, fType, fState;
		INTEGER wID;
		LONGINT hSubMenu, hbmpChecked, hbmpUnchecked;
		INTEGER dwItemData;
		LONGINT dwTypeData;
		INTEGER cch;
	} WinAPI_MENUITEMINFOW;

typedef
	struct WinAPI_MENUITEMTEMPLATE {
		SHORTINT mtOption, mtID;
		SHORTINT mtString[1];
	} WinAPI_MENUITEMTEMPLATE;

typedef
	struct WinAPI_MENUITEMTEMPLATEHEADER {
		SHORTINT versionNumber, offset;
	} WinAPI_MENUITEMTEMPLATEHEADER;

typedef
	struct WinAPI_MENUTEMPLATE {
		char _prvt0[1];
	} WinAPI_MENUTEMPLATE;

typedef
	struct WinAPI_MENUTEMPLATEA {
		char _prvt0[1];
	} WinAPI_MENUTEMPLATEA;

typedef
	struct WinAPI_MENUTEMPLATEW {
		char _prvt0[1];
	} WinAPI_MENUTEMPLATEW;

typedef
	struct WinAPI_MENU_EVENT_RECORD {
		INTEGER dwCommandId;
	} WinAPI_MENU_EVENT_RECORD;

typedef
	struct WinAPI_MESSAGE_RESOURCE_BLOCK {
		INTEGER LowId, HighId, OffsetToEntries;
	} WinAPI_MESSAGE_RESOURCE_BLOCK;

typedef
	struct WinAPI_MESSAGE_RESOURCE_DATA {
		INTEGER NumberOfBlocks;
		WinAPI_MESSAGE_RESOURCE_BLOCK Blocks[1];
	} WinAPI_MESSAGE_RESOURCE_DATA;

typedef
	struct WinAPI_MESSAGE_RESOURCE_ENTRY {
		SHORTINT Length, Flags;
		CHAR Text[1];
	} WinAPI_MESSAGE_RESOURCE_ENTRY;

typedef
	struct WinAPI_METAFILEPICT {
		INTEGER mm, xExt, yExt;
		LONGINT hMF;
	} WinAPI_METAFILEPICT;

typedef
	struct WinAPI_METAHEADER {
		SHORTINT mtType, mtHeaderSize, mtVersion;
		INTEGER mtSize;
		SHORTINT mtNoObjects;
		INTEGER mtMaxRecord;
		SHORTINT mtNoParameters;
	} WinAPI_METAHEADER;

typedef
	struct WinAPI_METARECORD {
		INTEGER rdSize;
		SHORTINT rdFunction;
		SHORTINT rdParm[1];
	} WinAPI_METARECORD;

typedef
	INTEGER (__STDCALL *WinAPI_MFENUMPROC)(LONGINT, WinAPI_HANDLETABLE*, WinAPI_METARECORD*, INTEGER, LONGINT);

typedef
	struct WinAPI_MINIMIZEDMETRICS {
		INTEGER cbSize, iWidth, iHorzGap, iVertGap, iArrange;
	} WinAPI_MINIMIZEDMETRICS;

typedef
	struct WinAPI_MINMAXINFO {
		WinAPI_POINT ptReserved, ptMaxSize, ptMaxPosition, ptMinTrackSize, ptMaxTrackSize;
	} WinAPI_MINMAXINFO;

typedef
	struct WinAPI_MODEMDEVCAPS {
		INTEGER dwActualSize, dwRequiredSize, dwDevSpecificOffset, dwDevSpecificSize, dwModemProviderVersion, dwModemManufacturerOffset, dwModemManufacturerSize, dwModemModelOffset, dwModemModelSize, dwModemVersionOffset, dwModemVersionSize, dwDialOptions, dwCallSetupFailTimer, dwInactivityTimeout;
		SET dwSpeakerVolume, dwSpeakerMode, dwModemOptions;
		INTEGER dwMaxDTERate, dwMaxDCERate;
		CHAR abVariablePortion[1];
	} WinAPI_MODEMDEVCAPS;

typedef
	struct WinAPI_MODEMSETTINGS {
		INTEGER dwActualSize, dwRequiredSize, dwDevSpecificOffset, dwDevSpecificSize, dwCallSetupFailTimer, dwInactivityTimeout;
		SET dwSpeakerVolume, dwSpeakerMode;
		INTEGER dwPreferredModemOptions, dwNegotiatedModemOptions, dwNegotiatedDCERate;
		CHAR abVariablePortion[1];
	} WinAPI_MODEMSETTINGS;

typedef
	struct WinAPI_MONCBSTRUCT {
		INTEGER cb, dwTime;
		LONGINT hTask;
		INTEGER dwRet, wType, wFmt;
		LONGINT hConv, hsz1, hsz2, hData;
		INTEGER dwData1, dwData2;
		WinAPI_CONVCONTEXT cc;
		INTEGER cbData;
		INTEGER Data[8];
	} WinAPI_MONCBSTRUCT;

typedef
	struct WinAPI_MONCONVSTRUCT {
		INTEGER cb, fConnect, dwTime;
		LONGINT hTask, hszSvc, hszTopic, hConvClient, hConvServer;
	} WinAPI_MONCONVSTRUCT;

typedef
	struct WinAPI_MONERRSTRUCT {
		INTEGER cb, wLastError, dwTime;
		LONGINT hTask;
	} WinAPI_MONERRSTRUCT;

typedef
	struct WinAPI_MONHSZSTRUCTA {
		INTEGER cb, fsAction, dwTime;
		LONGINT hsz, hTask;
		CHAR str[1];
	} WinAPI_MONHSZSTRUCTA;

typedef
	struct WinAPI_MONHSZSTRUCTW {
		INTEGER cb, fsAction, dwTime;
		LONGINT hsz, hTask;
		SHORTINT str[1];
	} WinAPI_MONHSZSTRUCTW;

typedef
	struct WinAPI_MONITOR_INFO_1A {
		LONGINT pName;
	} WinAPI_MONITOR_INFO_1A;

typedef
	struct WinAPI_MONITOR_INFO_1W {
		LONGINT pName;
	} WinAPI_MONITOR_INFO_1W;

typedef
	struct WinAPI_MONITOR_INFO_2A {
		LONGINT pName, pEnvironment, pDLLName;
	} WinAPI_MONITOR_INFO_2A;

typedef
	struct WinAPI_MONITOR_INFO_2W {
		LONGINT pName, pEnvironment, pDLLName;
	} WinAPI_MONITOR_INFO_2W;

typedef
	struct WinAPI_MONLINKSTRUCT {
		INTEGER cb, dwTime;
		LONGINT hTask;
		INTEGER fEstablished, fNoData;
		LONGINT hszSvc, hszTopic, hszItem;
		INTEGER wFmt, fServer;
		LONGINT hConvServer, hConvClient;
	} WinAPI_MONLINKSTRUCT;

typedef
	struct WinAPI_MONMSGSTRUCT {
		INTEGER cb;
		LONGINT hwndTo;
		INTEGER dwTime;
		LONGINT hTask;
		INTEGER wMsg;
		LONGINT wParam, lParam;
		WinAPI_DDEML_MSG_HOOK_DATA dmhd;
	} WinAPI_MONMSGSTRUCT;

typedef
	struct WinAPI_MOUSEHOOKSTRUCT {
		WinAPI_POINT pt;
		LONGINT hwnd;
		INTEGER wHitTestCode, dwExtraInfo;
	} WinAPI_MOUSEHOOKSTRUCT;

typedef
	struct WinAPI_MOUSEKEYS {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER iMaxSpeed, iTimeToMaxSpeed, iCtrlSpeed, dwReserved1, dwReserved2;
	} WinAPI_MOUSEKEYS;

typedef
	struct WinAPI_MOUSE_EVENT_RECORD {
		WinAPI_COORD dwMousePosition;
		SET dwButtonState, dwControlKeyState, dwEventFlags;
	} WinAPI_MOUSE_EVENT_RECORD;

typedef
	struct WinAPI_MSG {
		LONGINT hwnd;
		INTEGER message;
		LONGINT wParam, lParam;
		INTEGER time;
		WinAPI_POINT pt;
	} WinAPI_MSG;

typedef
	void (__STDCALL *WinAPI_MSGBOXCALLBACK)(WinAPI_HELPINFO*);

typedef
	struct WinAPI_MSGBOXPARAMSA {
		INTEGER cbSize;
		LONGINT hwndOwner, hInstance, lpszText, lpszCaption;
		SET dwStyle;
		LONGINT lpszIcon;
		INTEGER dwContextHelpId;
		WinAPI_MSGBOXCALLBACK lpfnMsgBoxCallback;
		INTEGER dwLanguageId;
	} WinAPI_MSGBOXPARAMSA;

typedef
	struct WinAPI_MSGBOXPARAMSW {
		INTEGER cbSize;
		LONGINT hwndOwner, hInstance, lpszText, lpszCaption;
		SET dwStyle;
		LONGINT lpszIcon;
		INTEGER dwContextHelpId;
		WinAPI_MSGBOXCALLBACK lpfnMsgBoxCallback;
		INTEGER dwLanguageId;
	} WinAPI_MSGBOXPARAMSW;

typedef
	struct WinAPI_MULTIKEYHELPA {
		INTEGER mkSize;
		CHAR mkKeylist;
		CHAR szKeyphrase[1];
	} WinAPI_MULTIKEYHELPA;

typedef
	struct WinAPI_MULTIKEYHELPW {
		INTEGER mkSize;
		SHORTINT mkKeylist;
		SHORTINT szKeyphrase[1];
	} WinAPI_MULTIKEYHELPW;

typedef
	INTEGER (__STDCALL *WinAPI_NAMEENUMPROCA)(void);

typedef
	INTEGER (__STDCALL *WinAPI_NAMEENUMPROCW)(void);

typedef
	struct WinAPI_WINDOWPOS *WinAPI_PtrWINDOWPOS;

typedef
	struct WinAPI_NCCALCSIZE_PARAMS {
		WinAPI_RECT rgrc[3];
		WinAPI_PtrWINDOWPOS lppos;
	} WinAPI_NCCALCSIZE_PARAMS;

typedef
	INTEGER (__STDCALL *WinAPI_NEARPROC)(void);

typedef
	INTEGER (__STDCALL *WinAPI_NEWFONTENUMPROC)(LONGINT, LONGINT, INTEGER, LONGINT);

typedef
	INTEGER (__STDCALL *WinAPI_NEWFONTENUMPROCA)(LONGINT, LONGINT, INTEGER, LONGINT);

typedef
	INTEGER (__STDCALL *WinAPI_NEWFONTENUMPROCW)(LONGINT, LONGINT, INTEGER, LONGINT);

typedef
	struct WinAPI_NEWTEXTMETRICA {
		INTEGER tmHeight, tmAscent, tmDescent, tmInternalLeading, tmExternalLeading, tmAveCharWidth, tmMaxCharWidth, tmWeight, tmOverhang, tmDigitizedAspectX, tmDigitizedAspectY;
		CHAR tmFirstChar, tmLastChar, tmDefaultChar, tmBreakChar, tmItalic, tmUnderlined, tmStruckOut, tmPitchAndFamily, tmCharSet;
		INTEGER ntmFlags, ntmSizeEM, ntmCellHeight, ntmAvgWidth;
	} WinAPI_NEWTEXTMETRICA;

typedef
	struct WinAPI_NEWTEXTMETRICEXA {
		WinAPI_NEWTEXTMETRICA ntmTm;
		WinAPI_FONTSIGNATURE ntmFontSig;
	} WinAPI_NEWTEXTMETRICEXA;

typedef
	struct WinAPI_NEWTEXTMETRICW {
		INTEGER tmHeight, tmAscent, tmDescent, tmInternalLeading, tmExternalLeading, tmAveCharWidth, tmMaxCharWidth, tmWeight, tmOverhang, tmDigitizedAspectX, tmDigitizedAspectY;
		SHORTINT tmFirstChar, tmLastChar, tmDefaultChar, tmBreakChar;
		CHAR tmItalic, tmUnderlined, tmStruckOut, tmPitchAndFamily, tmCharSet;
		INTEGER ntmFlags, ntmSizeEM, ntmCellHeight, ntmAvgWidth;
	} WinAPI_NEWTEXTMETRICW;

typedef
	struct WinAPI_NEWTEXTMETRICEXW {
		WinAPI_NEWTEXTMETRICW ntmTm;
		WinAPI_FONTSIGNATURE ntmFontSig;
	} WinAPI_NEWTEXTMETRICEXW;

typedef
	struct WinAPI_NMHDR {
		LONGINT hwndFrom;
		INTEGER idFrom, code;
	} WinAPI_NMHDR;

typedef
	struct WinAPI_NONCLIENTMETRICSA {
		INTEGER cbSize, iBorderWidth, iScrollWidth, iScrollHeight, iCaptionWidth, iCaptionHeight;
		WinAPI_LOGFONTA lfCaptionFont;
		INTEGER iSmCaptionWidth, iSmCaptionHeight;
		WinAPI_LOGFONTA lfSmCaptionFont;
		INTEGER iMenuWidth, iMenuHeight;
		WinAPI_LOGFONTA lfMenuFont, lfStatusFont, lfMessageFont;
	} WinAPI_NONCLIENTMETRICSA;

typedef
	struct WinAPI_NONCLIENTMETRICSW {
		INTEGER cbSize, iBorderWidth, iScrollWidth, iScrollHeight, iCaptionWidth, iCaptionHeight;
		WinAPI_LOGFONTW lfCaptionFont;
		INTEGER iSmCaptionWidth, iSmCaptionHeight;
		WinAPI_LOGFONTW lfSmCaptionFont;
		INTEGER iMenuWidth, iMenuHeight;
		WinAPI_LOGFONTW lfMenuFont, lfStatusFont, lfMessageFont;
	} WinAPI_NONCLIENTMETRICSW;

typedef
	struct WinAPI_NOTIFYICONDATAA {
		INTEGER cbSize;
		LONGINT hWnd;
		INTEGER uID;
		SET uFlags;
		INTEGER uCallbackMessage;
		LONGINT hIcon;
		CHAR szTip[64];
	} WinAPI_NOTIFYICONDATAA;

typedef
	struct WinAPI_NOTIFYICONDATAW {
		INTEGER cbSize;
		LONGINT hWnd;
		INTEGER uID;
		SET uFlags;
		INTEGER uCallbackMessage;
		LONGINT hIcon;
		SHORTINT szTip[64];
	} WinAPI_NOTIFYICONDATAW;

typedef
	struct WinAPI__EXCEPTION_REGISTRATION_RECORD *WinAPI_Ptr_EXCEPTION_REGISTRATION_RECORD;

typedef
	struct WinAPI_NT_TIB *WinAPI_PtrNT_TIB;

typedef
	struct WinAPI_NT_TIB {
		WinAPI_Ptr_EXCEPTION_REGISTRATION_RECORD ExceptionList;
		LONGINT StackBase, StackLimit, SubSystemTib;
		struct WinAPI__24 u;
		LONGINT ArbitraryUserPointer;
		WinAPI_PtrNT_TIB Self;
	} WinAPI_NT_TIB;

typedef
	struct WinAPI_NUMBERFMTA {
		INTEGER NumDigits, LeadingZero, Grouping;
		LONGINT lpDecimalSep, lpThousandSep;
		INTEGER NegativeOrder;
	} WinAPI_NUMBERFMTA;

typedef
	struct WinAPI_NUMBERFMTW {
		INTEGER NumDigits, LeadingZero, Grouping;
		LONGINT lpDecimalSep, lpThousandSep;
		INTEGER NegativeOrder;
	} WinAPI_NUMBERFMTW;

typedef
	struct WinAPI_OBJECTID {
		WinAPI_COM_GUID Lineage;
		INTEGER Uniquifier;
	} WinAPI_OBJECTID;

typedef
	struct WinAPI_OFSTRUCT {
		CHAR cBytes, fFixedDisk;
		SHORTINT nErrCode, Reserved1, Reserved2;
		CHAR szPathName[128];
	} WinAPI_OFSTRUCT;

typedef
	INTEGER (__STDCALL *WinAPI_OLDFONTENUMPROC)(void);

typedef
	struct WinAPI_OSVERSIONINFOA {
		INTEGER dwOSVersionInfoSize, dwMajorVersion, dwMinorVersion, dwBuildNumber, dwPlatformId;
		CHAR szCSDVersion[128];
	} WinAPI_OSVERSIONINFOA;

typedef
	struct WinAPI_OSVERSIONINFOW {
		INTEGER dwOSVersionInfoSize, dwMajorVersion, dwMinorVersion, dwBuildNumber, dwPlatformId;
		SHORTINT szCSDVersion[128];
	} WinAPI_OSVERSIONINFOW;

typedef
	struct WinAPI_TEXTMETRICA {
		INTEGER tmHeight, tmAscent, tmDescent, tmInternalLeading, tmExternalLeading, tmAveCharWidth, tmMaxCharWidth, tmWeight, tmOverhang, tmDigitizedAspectX, tmDigitizedAspectY;
		CHAR tmFirstChar, tmLastChar, tmDefaultChar, tmBreakChar, tmItalic, tmUnderlined, tmStruckOut, tmPitchAndFamily, tmCharSet;
	} WinAPI_TEXTMETRICA;

typedef
	struct WinAPI_OUTLINETEXTMETRICA {
		INTEGER otmSize;
		WinAPI_TEXTMETRICA otmTextMetrics;
		CHAR otmFiller;
		WinAPI_PANOSE otmPanoseNumber;
		INTEGER otmfsSelection, otmfsType, otmsCharSlopeRise, otmsCharSlopeRun, otmItalicAngle, otmEMSquare, otmAscent, otmDescent, otmLineGap, otmsCapEmHeight, otmsXHeight;
		WinAPI_RECT otmrcFontBox;
		INTEGER otmMacAscent, otmMacDescent, otmMacLineGap, otmusMinimumPPEM;
		WinAPI_POINT otmptSubscriptSize, otmptSubscriptOffset, otmptSuperscriptSize, otmptSuperscriptOffset;
		INTEGER otmsStrikeoutSize, otmsStrikeoutPosition, otmsUnderscoreSize, otmsUnderscorePosition;
		LONGINT otmpFamilyName, otmpFaceName, otmpStyleName, otmpFullName;
	} WinAPI_OUTLINETEXTMETRICA;

typedef
	struct WinAPI_TEXTMETRICW {
		INTEGER tmHeight, tmAscent, tmDescent, tmInternalLeading, tmExternalLeading, tmAveCharWidth, tmMaxCharWidth, tmWeight, tmOverhang, tmDigitizedAspectX, tmDigitizedAspectY;
		SHORTINT tmFirstChar, tmLastChar, tmDefaultChar, tmBreakChar;
		CHAR tmItalic, tmUnderlined, tmStruckOut, tmPitchAndFamily, tmCharSet;
	} WinAPI_TEXTMETRICW;

typedef
	struct WinAPI_OUTLINETEXTMETRICW {
		INTEGER otmSize;
		WinAPI_TEXTMETRICW otmTextMetrics;
		CHAR otmFiller;
		WinAPI_PANOSE otmPanoseNumber;
		INTEGER otmfsSelection, otmfsType, otmsCharSlopeRise, otmsCharSlopeRun, otmItalicAngle, otmEMSquare, otmAscent, otmDescent, otmLineGap, otmsCapEmHeight, otmsXHeight;
		WinAPI_RECT otmrcFontBox;
		INTEGER otmMacAscent, otmMacDescent, otmMacLineGap, otmusMinimumPPEM;
		WinAPI_POINT otmptSubscriptSize, otmptSubscriptOffset, otmptSuperscriptSize, otmptSuperscriptOffset;
		INTEGER otmsStrikeoutSize, otmsStrikeoutPosition, otmsUnderscoreSize, otmsUnderscorePosition;
		LONGINT otmpFamilyName, otmpFaceName, otmpStyleName, otmpFullName;
	} WinAPI_OUTLINETEXTMETRICW;

typedef
	struct WinAPI_OUTPUT_DEBUG_STRING_INFO {
		LONGINT lpDebugStringData;
		SHORTINT fUnicode, nDebugStringLength;
	} WinAPI_OUTPUT_DEBUG_STRING_INFO;

typedef
	struct WinAPI_OVERLAPPED {
		INTEGER Internal, InternalHigh, Offset, OffsetHigh;
		LONGINT hEvent;
	} WinAPI_OVERLAPPED;

typedef
	void (__STDCALL *WinAPI_OVERLAPPED_COMPLETION_ROUTINE)(INTEGER, INTEGER, WinAPI_OVERLAPPED*);

typedef
	struct WinAPI_PAINTSTRUCT {
		LONGINT hdc;
		INTEGER fErase;
		WinAPI_RECT rcPaint;
		INTEGER fRestore, fIncUpdate;
		CHAR rgbReserved[32];
	} WinAPI_PAINTSTRUCT;

typedef
	struct WinAPI_PELARRAY {
		INTEGER paXCount, paYCount, paXExt, paYExt;
		CHAR paRGBs;
	} WinAPI_PELARRAY;

typedef
	struct WinAPI_POINTFX {
		WinAPI_FIXED x, y;
	} WinAPI_POINTFX;

typedef
	struct WinAPI_POLYTEXTA {
		INTEGER x, y, n;
		LONGINT lpstr;
		SET uiFlags;
		WinAPI_RECT rcl;
		LONGINT pdx;
	} WinAPI_POLYTEXTA;

typedef
	struct WinAPI_POLYTEXTW {
		INTEGER x, y, n;
		LONGINT lpstr;
		SET uiFlags;
		WinAPI_RECT rcl;
		LONGINT pdx;
	} WinAPI_POLYTEXTW;

typedef
	struct WinAPI_PORT_INFO_1A {
		LONGINT pName;
	} WinAPI_PORT_INFO_1A;

typedef
	struct WinAPI_PORT_INFO_1W {
		LONGINT pName;
	} WinAPI_PORT_INFO_1W;

typedef
	struct WinAPI_PORT_INFO_2A {
		LONGINT pPortName, pMonitorName, pDescription;
		INTEGER fPortType, Reserved;
	} WinAPI_PORT_INFO_2A;

typedef
	struct WinAPI_PORT_INFO_2W {
		LONGINT pPortName, pMonitorName, pDescription;
		INTEGER fPortType, Reserved;
	} WinAPI_PORT_INFO_2W;

typedef
	struct WinAPI_PRINTER_DEFAULTSA {
		LONGINT pDatatype;
		WinAPI_PtrDEVMODEA pDevMode;
		SET DesiredAccess;
	} WinAPI_PRINTER_DEFAULTSA;

typedef
	struct WinAPI_PRINTER_DEFAULTSW {
		LONGINT pDatatype;
		WinAPI_PtrDEVMODEW pDevMode;
		SET DesiredAccess;
	} WinAPI_PRINTER_DEFAULTSW;

typedef
	struct WinAPI_PRINTER_INFO_1A {
		SET Flags;
		LONGINT pDescription, pName, pComment;
	} WinAPI_PRINTER_INFO_1A;

typedef
	struct WinAPI_PRINTER_INFO_1W {
		SET Flags;
		LONGINT pDescription, pName, pComment;
	} WinAPI_PRINTER_INFO_1W;

typedef
	struct WinAPI_PRINTER_INFO_2A {
		LONGINT pServerName, pPrinterName, pShareName, pPortName, pDriverName, pComment, pLocation;
		WinAPI_PtrDEVMODEA pDevMode;
		LONGINT pSepFile, pPrintProcessor, pDatatype, pParameters, pSecurityDescriptor;
		SET Attributes;
		INTEGER Priority, DefaultPriority, StartTime, UntilTime;
		SET Status;
		INTEGER cJobs, AveragePPM;
	} WinAPI_PRINTER_INFO_2A;

typedef
	struct WinAPI_PRINTER_INFO_2W {
		LONGINT pServerName, pPrinterName, pShareName, pPortName, pDriverName, pComment, pLocation;
		WinAPI_PtrDEVMODEW pDevMode;
		LONGINT pSepFile, pPrintProcessor, pDatatype, pParameters, pSecurityDescriptor;
		SET Attributes;
		INTEGER Priority, DefaultPriority, StartTime, UntilTime;
		SET Status;
		INTEGER cJobs, AveragePPM;
	} WinAPI_PRINTER_INFO_2W;

typedef
	struct WinAPI_PRINTER_INFO_3 {
		LONGINT pSecurityDescriptor;
	} WinAPI_PRINTER_INFO_3;

typedef
	struct WinAPI_PRINTER_INFO_4A {
		LONGINT pPrinterName, pServerName;
		SET Attributes;
	} WinAPI_PRINTER_INFO_4A;

typedef
	struct WinAPI_PRINTER_INFO_4W {
		LONGINT pPrinterName, pServerName;
		SET Attributes;
	} WinAPI_PRINTER_INFO_4W;

typedef
	struct WinAPI_PRINTER_INFO_5A {
		LONGINT pPrinterName, pPortName;
		SET Attributes;
		INTEGER DeviceNotSelectedTimeout, TransmissionRetryTimeout;
	} WinAPI_PRINTER_INFO_5A;

typedef
	struct WinAPI_PRINTER_INFO_5W {
		LONGINT pPrinterName, pPortName;
		SET Attributes;
		INTEGER DeviceNotSelectedTimeout, TransmissionRetryTimeout;
	} WinAPI_PRINTER_INFO_5W;

typedef
	struct WinAPI_PRINTER_INFO_6 {
		SET dwStatus;
	} WinAPI_PRINTER_INFO_6;

typedef
	struct WinAPI_PRINTER_NOTIFY_INFO_DATA {
		SHORTINT Type, Field;
		INTEGER Reserved, Id;
		struct WinAPI__26 NotifyData;
	} WinAPI_PRINTER_NOTIFY_INFO_DATA;

typedef
	struct WinAPI_PRINTER_NOTIFY_INFO {
		INTEGER Version;
		SET Flags;
		INTEGER Count;
		WinAPI_PRINTER_NOTIFY_INFO_DATA aData[1];
	} WinAPI_PRINTER_NOTIFY_INFO;

typedef
	struct WinAPI_PRINTER_NOTIFY_OPTIONS_TYPE *WinAPI_PtrPRINTER_NOTIFY_OPTIONS_TYPE;

typedef
	struct WinAPI_PRINTER_NOTIFY_OPTIONS {
		INTEGER Version;
		SET Flags;
		INTEGER Count;
		WinAPI_PtrPRINTER_NOTIFY_OPTIONS_TYPE pTypes;
	} WinAPI_PRINTER_NOTIFY_OPTIONS;

typedef
	struct WinAPI_PRINTER_NOTIFY_OPTIONS_TYPE {
		SHORTINT Type, Reserved0;
		INTEGER Reserved1, Reserved2, Count;
		LONGINT pFields;
	} WinAPI_PRINTER_NOTIFY_OPTIONS_TYPE;

typedef
	struct WinAPI_PRINTPROCESSOR_INFO_1A {
		LONGINT pName;
	} WinAPI_PRINTPROCESSOR_INFO_1A;

typedef
	struct WinAPI_PRINTPROCESSOR_INFO_1W {
		LONGINT pName;
	} WinAPI_PRINTPROCESSOR_INFO_1W;

typedef
	struct WinAPI_PRIVILEGE_SET {
		INTEGER PrivilegeCount, Control;
		WinAPI_LUID_AND_ATTRIBUTES Privilege[1];
	} WinAPI_PRIVILEGE_SET;

typedef
	struct WinAPI_PROCESS_HEAP_ENTRY {
		LONGINT lpData;
		INTEGER cbData;
		CHAR cbOverhead, iRegionIndex;
		SHORTINT wFlags;
		struct WinAPI__28 u;
	} WinAPI_PROCESS_HEAP_ENTRY;

typedef
	struct WinAPI_PROCESS_INFORMATION {
		LONGINT hProcess, hThread;
		INTEGER dwProcessId, dwThreadId;
	} WinAPI_PROCESS_INFORMATION;

typedef
	INTEGER (__STDCALL *WinAPI_PROGRESS_ROUTINE)(LONGINT, LONGINT, LONGINT, LONGINT, INTEGER, INTEGER, LONGINT, LONGINT, LONGINT);

typedef
	struct WinAPI_PROPSHEETHEADERA {
		INTEGER dwSize;
		SET dwFlags;
		LONGINT hwndParent, hInstance;
		struct WinAPI__29 u;
		LONGINT pszCaption;
		INTEGER nPages;
		struct WinAPI__30 u1;
		struct WinAPI__31 u2;
		WinAPI_FNPROPSHEETCALLBACK pfnCallback;
	} WinAPI_PROPSHEETHEADERA;

typedef
	struct WinAPI_PROPSHEETHEADERW {
		INTEGER dwSize;
		SET dwFlags;
		LONGINT hwndParent, hInstance;
		struct WinAPI__32 u;
		LONGINT pszCaption;
		INTEGER nPages;
		struct WinAPI__33 u1;
		struct WinAPI__34 u2;
		WinAPI_FNPROPSHEETCALLBACK pfnCallback;
	} WinAPI_PROPSHEETHEADERW;

typedef
	struct WinAPI_PROPSHEETPAGEA {
		INTEGER dwSize;
		SET dwFlags;
		LONGINT hInstance;
		struct WinAPI__3 u;
		struct WinAPI__4 u1;
		LONGINT pszTitle;
		WinAPI_DLGPROC pfnDlgProc;
		LONGINT lParam;
		WinAPI_FNPSPCALLBACKA pfnCallback;
		LONGINT pcRefParent;
	} WinAPI_PROPSHEETPAGEA;

typedef
	struct WinAPI_PROPSHEETPAGEW {
		INTEGER dwSize;
		SET dwFlags;
		LONGINT hInstance;
		struct WinAPI__5 u;
		struct WinAPI__6 u1;
		LONGINT pszTitle;
		WinAPI_DLGPROC pfnDlgProc;
		LONGINT lParam;
		WinAPI_FNPSPCALLBACKW pfnCallback;
		LONGINT pcRefParent;
	} WinAPI_PROPSHEETPAGEW;

typedef
	struct WinAPI_PROVIDOR_INFO_1A {
		LONGINT pName, pEnvironment, pDLLName;
	} WinAPI_PROVIDOR_INFO_1A;

typedef
	struct WinAPI_PROVIDOR_INFO_1W {
		LONGINT pName, pEnvironment, pDLLName;
	} WinAPI_PROVIDOR_INFO_1W;

typedef
	struct WinAPI_PSHNOTIFY {
		WinAPI_NMHDR hdr;
		LONGINT lParam;
	} WinAPI_PSHNOTIFY;

typedef
	struct WinAPI_PVALUEA {
		LONGINT pv_valuename;
		INTEGER pv_valuelen;
		LONGINT pv_value_context;
		INTEGER pv_type;
	} WinAPI_PVALUEA;

typedef
	struct WinAPI_PVALUEW {
		LONGINT pv_valuename;
		INTEGER pv_valuelen;
		LONGINT pv_value_context;
		INTEGER pv_type;
	} WinAPI_PVALUEW;

typedef
	WinAPI_ABC *WinAPI_PtrABC;

typedef
	WinAPI_ABCFLOAT *WinAPI_PtrABCFLOAT;

typedef
	WinAPI_ACCEL *WinAPI_PtrACCEL;

typedef
	WinAPI_ACCESSTIMEOUT *WinAPI_PtrACCESSTIMEOUT;

typedef
	WinAPI_ACCESS_ALLOWED_ACE *WinAPI_PtrACCESS_ALLOWED_ACE;

typedef
	WinAPI_ACCESS_DENIED_ACE *WinAPI_PtrACCESS_DENIED_ACE;

typedef
	WinAPI_ACE_HEADER *WinAPI_PtrACE_HEADER;

typedef
	WinAPI_ACL *WinAPI_PtrACL;

typedef
	WinAPI_ACL_REVISION_INFORMATION *WinAPI_PtrACL_REVISION_INFORMATION;

typedef
	WinAPI_ACL_SIZE_INFORMATION *WinAPI_PtrACL_SIZE_INFORMATION;

typedef
	WinAPI_ADDJOB_INFO_1A *WinAPI_PtrADDJOB_INFO_1A;

typedef
	WinAPI_ADDJOB_INFO_1W *WinAPI_PtrADDJOB_INFO_1W;

typedef
	WinAPI_ANIMATIONINFO *WinAPI_PtrANIMATIONINFO;

typedef
	WinAPI_APPBARDATA *WinAPI_PtrAPPBARDATA;

typedef
	WinAPI_BITMAP *WinAPI_PtrBITMAP;

typedef
	WinAPI_BITMAPCOREHEADER *WinAPI_PtrBITMAPCOREHEADER;

typedef
	WinAPI_BITMAPCOREINFO *WinAPI_PtrBITMAPCOREINFO;

typedef
	WinAPI_BITMAPFILEHEADER *WinAPI_PtrBITMAPFILEHEADER;

typedef
	WinAPI_BITMAPINFO *WinAPI_PtrBITMAPINFO;

typedef
	WinAPI_BITMAPINFOHEADER *WinAPI_PtrBITMAPINFOHEADER;

typedef
	WinAPI_BITMAPV4HEADER *WinAPI_PtrBITMAPV4HEADER;

typedef
	WinAPI_BROADCASTSYSMSG *WinAPI_PtrBROADCASTSYSMSG;

typedef
	WinAPI_BY_HANDLE_FILE_INFORMATION *WinAPI_PtrBY_HANDLE_FILE_INFORMATION;

typedef
	WinAPI_CBTACTIVATESTRUCT *WinAPI_PtrCBTACTIVATESTRUCT;

typedef
	WinAPI_CBT_CREATEWNDA *WinAPI_PtrCBT_CREATEWNDA;

typedef
	WinAPI_CBT_CREATEWNDW *WinAPI_PtrCBT_CREATEWNDW;

typedef
	WinAPI_CHARSETINFO *WinAPI_PtrCHARSETINFO;

typedef
	WinAPI_CHAR_INFO *WinAPI_PtrCHAR_INFO;

typedef
	WinAPI_CIEXYZ *WinAPI_PtrCIEXYZ;

typedef
	WinAPI_CIEXYZTRIPLE *WinAPI_PtrCIEXYZTRIPLE;

typedef
	WinAPI_CLIENTCREATESTRUCT *WinAPI_PtrCLIENTCREATESTRUCT;

typedef
	WinAPI_COLORADJUSTMENT *WinAPI_PtrCOLORADJUSTMENT;

typedef
	WinAPI_COMMCONFIG *WinAPI_PtrCOMMCONFIG;

typedef
	WinAPI_COMMPROP *WinAPI_PtrCOMMPROP;

typedef
	WinAPI_COMMTIMEOUTS *WinAPI_PtrCOMMTIMEOUTS;

typedef
	WinAPI_COMPAREITEMSTRUCT *WinAPI_PtrCOMPAREITEMSTRUCT;

typedef
	WinAPI_COMPOUND_ACCESS_ALLOWED_ACE *WinAPI_PtrCOMPOUND_ACCESS_ALLOWED_ACE;

typedef
	WinAPI_COMSTAT *WinAPI_PtrCOMSTAT;

typedef
	WinAPI_CONSOLE_CURSOR_INFO *WinAPI_PtrCONSOLE_CURSOR_INFO;

typedef
	WinAPI_CONSOLE_SCREEN_BUFFER_INFO *WinAPI_PtrCONSOLE_SCREEN_BUFFER_INFO;

typedef
	WinAPI_CONVCONTEXT *WinAPI_PtrCONVCONTEXT;

typedef
	WinAPI_CONVINFO *WinAPI_PtrCONVINFO;

typedef
	WinAPI_COORD *WinAPI_PtrCOORD;

typedef
	WinAPI_COPYDATASTRUCT *WinAPI_PtrCOPYDATASTRUCT;

typedef
	WinAPI_CPINFO *WinAPI_PtrCPINFO;

typedef
	WinAPI_CREATE_PROCESS_DEBUG_INFO *WinAPI_PtrCREATE_PROCESS_DEBUG_INFO;

typedef
	WinAPI_CREATE_THREAD_DEBUG_INFO *WinAPI_PtrCREATE_THREAD_DEBUG_INFO;

typedef
	WinAPI_CURRENCYFMTA *WinAPI_PtrCURRENCYFMTA;

typedef
	WinAPI_CURRENCYFMTW *WinAPI_PtrCURRENCYFMTW;

typedef
	WinAPI_CURSORSHAPE *WinAPI_PtrCURSORSHAPE;

typedef
	WinAPI_CWPRETSTRUCT *WinAPI_PtrCWPRETSTRUCT;

typedef
	WinAPI_CWPSTRUCT *WinAPI_PtrCWPSTRUCT;

typedef
	WinAPI_DATATYPES_INFO_1A *WinAPI_PtrDATATYPES_INFO_1A;

typedef
	WinAPI_DATATYPES_INFO_1W *WinAPI_PtrDATATYPES_INFO_1W;

typedef
	WinAPI_DCB *WinAPI_PtrDCB;

typedef
	WinAPI_DDEML_MSG_HOOK_DATA *WinAPI_PtrDDEML_MSG_HOOK_DATA;

typedef
	WinAPI_DEBUGHOOKINFO *WinAPI_PtrDEBUGHOOKINFO;

typedef
	WinAPI_DEBUG_EVENT *WinAPI_PtrDEBUG_EVENT;

typedef
	WinAPI_DELETEITEMSTRUCT *WinAPI_PtrDELETEITEMSTRUCT;

typedef
	WinAPI_DIBSECTION *WinAPI_PtrDIBSECTION;

typedef
	WinAPI_DLGITEMTEMPLATE *WinAPI_PtrDLGITEMTEMPLATE;

typedef
	WinAPI_DLGTEMPLATE *WinAPI_PtrDLGTEMPLATE;

typedef
	WinAPI_DOCINFOA *WinAPI_PtrDOCINFOA;

typedef
	WinAPI_DOCINFOW *WinAPI_PtrDOCINFOW;

typedef
	WinAPI_DOC_INFO_1A *WinAPI_PtrDOC_INFO_1A;

typedef
	WinAPI_DOC_INFO_1W *WinAPI_PtrDOC_INFO_1W;

typedef
	WinAPI_DOC_INFO_2A *WinAPI_PtrDOC_INFO_2A;

typedef
	WinAPI_DOC_INFO_2W *WinAPI_PtrDOC_INFO_2W;

typedef
	WinAPI_DRAGINFOA *WinAPI_PtrDRAGINFOA;

typedef
	WinAPI_DRAGINFOW *WinAPI_PtrDRAGINFOW;

typedef
	WinAPI_DRAWITEMSTRUCT *WinAPI_PtrDRAWITEMSTRUCT;

typedef
	WinAPI_DRAWTEXTPARAMS *WinAPI_PtrDRAWTEXTPARAMS;

typedef
	WinAPI_DRIVER_INFO_1A *WinAPI_PtrDRIVER_INFO_1A;

typedef
	WinAPI_DRIVER_INFO_1W *WinAPI_PtrDRIVER_INFO_1W;

typedef
	WinAPI_DRIVER_INFO_2A *WinAPI_PtrDRIVER_INFO_2A;

typedef
	WinAPI_DRIVER_INFO_2W *WinAPI_PtrDRIVER_INFO_2W;

typedef
	WinAPI_DRIVER_INFO_3A *WinAPI_PtrDRIVER_INFO_3A;

typedef
	WinAPI_DRIVER_INFO_3W *WinAPI_PtrDRIVER_INFO_3W;

typedef
	WinAPI_DROPSTRUCT *WinAPI_PtrDROPSTRUCT;

typedef
	WinAPI_EMR *WinAPI_PtrEMR;

typedef
	WinAPI_EMRABORTPATH *WinAPI_PtrEMRABORTPATH;

typedef
	WinAPI_EMRANGLEARC *WinAPI_PtrEMRANGLEARC;

typedef
	WinAPI_EMRARC *WinAPI_PtrEMRARC;

typedef
	WinAPI_EMRBITBLT *WinAPI_PtrEMRBITBLT;

typedef
	WinAPI_EMRCREATEBRUSHINDIRECT *WinAPI_PtrEMRCREATEBRUSHINDIRECT;

typedef
	WinAPI_EMRCREATECOLORSPACE *WinAPI_PtrEMRCREATECOLORSPACE;

typedef
	WinAPI_EMRCREATEDIBPATTERNBRUSHPT *WinAPI_PtrEMRCREATEDIBPATTERNBRUSHPT;

typedef
	WinAPI_EMRCREATEMONOBRUSH *WinAPI_PtrEMRCREATEMONOBRUSH;

typedef
	WinAPI_EMRCREATEPALETTE *WinAPI_PtrEMRCREATEPALETTE;

typedef
	WinAPI_EMRCREATEPEN *WinAPI_PtrEMRCREATEPEN;

typedef
	WinAPI_EMRSELECTCOLORSPACE *WinAPI_PtrEMRSELECTCOLORSPACE;

typedef
	WinAPI_EMRSELECTOBJECT *WinAPI_PtrEMRSELECTOBJECT;

typedef
	WinAPI_EMRELLIPSE *WinAPI_PtrEMRELLIPSE;

typedef
	WinAPI_EMREOF *WinAPI_PtrEMREOF;

typedef
	WinAPI_EMREXCLUDECLIPRECT *WinAPI_PtrEMREXCLUDECLIPRECT;

typedef
	WinAPI_EMREXTCREATEFONTINDIRECTW *WinAPI_PtrEMREXTCREATEFONTINDIRECTW;

typedef
	WinAPI_EMREXTCREATEPEN *WinAPI_PtrEMREXTCREATEPEN;

typedef
	WinAPI_EMREXTFLOODFILL *WinAPI_PtrEMREXTFLOODFILL;

typedef
	WinAPI_EMREXTSELECTCLIPRGN *WinAPI_PtrEMREXTSELECTCLIPRGN;

typedef
	WinAPI_EMREXTTEXTOUTA *WinAPI_PtrEMREXTTEXTOUTA;

typedef
	WinAPI_EMRFILLPATH *WinAPI_PtrEMRFILLPATH;

typedef
	WinAPI_EMRFILLRGN *WinAPI_PtrEMRFILLRGN;

typedef
	WinAPI_EMRFORMAT *WinAPI_PtrEMRFORMAT;

typedef
	WinAPI_EMRFRAMERGN *WinAPI_PtrEMRFRAMERGN;

typedef
	WinAPI_EMRGDICOMMENT *WinAPI_PtrEMRGDICOMMENT;

typedef
	WinAPI_EMRGLSBOUNDEDRECORD *WinAPI_PtrEMRGLSBOUNDEDRECORD;

typedef
	WinAPI_EMRGLSRECORD *WinAPI_PtrEMRGLSRECORD;

typedef
	WinAPI_EMRINVERTRGN *WinAPI_PtrEMRINVERTRGN;

typedef
	WinAPI_EMRLINETO *WinAPI_PtrEMRLINETO;

typedef
	WinAPI_EMRMASKBLT *WinAPI_PtrEMRMASKBLT;

typedef
	WinAPI_EMRMODIFYWORLDTRANSFORM *WinAPI_PtrEMRMODIFYWORLDTRANSFORM;

typedef
	WinAPI_EMROFFSETCLIPRGN *WinAPI_PtrEMROFFSETCLIPRGN;

typedef
	WinAPI_EMRPIXELFORMAT *WinAPI_PtrEMRPIXELFORMAT;

typedef
	WinAPI_EMRPLGBLT *WinAPI_PtrEMRPLGBLT;

typedef
	WinAPI_EMRPOLYLINE *WinAPI_PtrEMRPOLYLINE;

typedef
	WinAPI_EMRPOLYLINE16 *WinAPI_PtrEMRPOLYLINE16;

typedef
	WinAPI_EMRPOLYDRAW *WinAPI_PtrEMRPOLYDRAW;

typedef
	WinAPI_EMRPOLYDRAW16 *WinAPI_PtrEMRPOLYDRAW16;

typedef
	WinAPI_EMRPOLYPOLYLINE *WinAPI_PtrEMRPOLYPOLYLINE;

typedef
	WinAPI_EMRPOLYPOLYLINE16 *WinAPI_PtrEMRPOLYPOLYLINE16;

typedef
	WinAPI_EMRPOLYTEXTOUTA *WinAPI_PtrEMRPOLYTEXTOUTA;

typedef
	WinAPI_EMRRESIZEPALETTE *WinAPI_PtrEMRRESIZEPALETTE;

typedef
	WinAPI_EMRRESTOREDC *WinAPI_PtrEMRRESTOREDC;

typedef
	WinAPI_EMRROUNDRECT *WinAPI_PtrEMRROUNDRECT;

typedef
	WinAPI_EMRSCALEVIEWPORTEXTEX *WinAPI_PtrEMRSCALEVIEWPORTEXTEX;

typedef
	WinAPI_EMRSELECTCLIPPATH *WinAPI_PtrEMRSELECTCLIPPATH;

typedef
	WinAPI_EMRSELECTPALETTE *WinAPI_PtrEMRSELECTPALETTE;

typedef
	WinAPI_EMRSETARCDIRECTION *WinAPI_PtrEMRSETARCDIRECTION;

typedef
	WinAPI_EMRSETBKCOLOR *WinAPI_PtrEMRSETBKCOLOR;

typedef
	WinAPI_EMRSETVIEWPORTORGEX *WinAPI_PtrEMRSETVIEWPORTORGEX;

typedef
	WinAPI_EMRSETCOLORADJUSTMENT *WinAPI_PtrEMRSETCOLORADJUSTMENT;

typedef
	WinAPI_EMRSETDIBITSTODEVICE *WinAPI_PtrEMRSETDIBITSTODEVICE;

typedef
	WinAPI_EMRSETMAPPERFLAGS *WinAPI_PtrEMRSETMAPPERFLAGS;

typedef
	WinAPI_EMRSETMITERLIMIT *WinAPI_PtrEMRSETMITERLIMIT;

typedef
	WinAPI_EMRSETPALETTEENTRIES *WinAPI_PtrEMRSETPALETTEENTRIES;

typedef
	WinAPI_EMRSETPIXELV *WinAPI_PtrEMRSETPIXELV;

typedef
	WinAPI_EMRSETVIEWPORTEXTEX *WinAPI_PtrEMRSETVIEWPORTEXTEX;

typedef
	WinAPI_EMRSETWORLDTRANSFORM *WinAPI_PtrEMRSETWORLDTRANSFORM;

typedef
	WinAPI_EMRSTRETCHBLT *WinAPI_PtrEMRSTRETCHBLT;

typedef
	WinAPI_EMRSTRETCHDIBITS *WinAPI_PtrEMRSTRETCHDIBITS;

typedef
	WinAPI_EMRTEXT *WinAPI_PtrEMRTEXT;

typedef
	WinAPI_ENHMETAHEADER *WinAPI_PtrENHMETAHEADER;

typedef
	WinAPI_ENHMETARECORD *WinAPI_PtrENHMETARECORD;

typedef
	WinAPI_ENUMLOGFONTA *WinAPI_PtrENUMLOGFONTA;

typedef
	WinAPI_ENUMLOGFONTEXA *WinAPI_PtrENUMLOGFONTEXA;

typedef
	WinAPI_ENUMLOGFONTEXW *WinAPI_PtrENUMLOGFONTEXW;

typedef
	WinAPI_ENUMLOGFONTW *WinAPI_PtrENUMLOGFONTW;

typedef
	WinAPI_ENUM_SERVICE_STATUSA *WinAPI_PtrENUM_SERVICE_STATUSA;

typedef
	WinAPI_ENUM_SERVICE_STATUSW *WinAPI_PtrENUM_SERVICE_STATUSW;

typedef
	WinAPI_EVENTLOGRECORD *WinAPI_PtrEVENTLOGRECORD;

typedef
	WinAPI_EVENTMSG *WinAPI_PtrEVENTMSG;

typedef
	WinAPI_EXCEPTION_DEBUG_INFO *WinAPI_PtrEXCEPTION_DEBUG_INFO;

typedef
	WinAPI_EXCEPTION_POINTERS *WinAPI_PtrEXCEPTION_POINTERS;

typedef
	WinAPI_EXIT_PROCESS_DEBUG_INFO *WinAPI_PtrEXIT_PROCESS_DEBUG_INFO;

typedef
	WinAPI_EXIT_THREAD_DEBUG_INFO *WinAPI_PtrEXIT_THREAD_DEBUG_INFO;

typedef
	WinAPI_EXTLOGFONTA *WinAPI_PtrEXTLOGFONTA;

typedef
	WinAPI_EXTLOGFONTW *WinAPI_PtrEXTLOGFONTW;

typedef
	WinAPI_EXTLOGPEN *WinAPI_PtrEXTLOGPEN;

typedef
	WinAPI_FILETIME *WinAPI_PtrFILETIME;

typedef
	WinAPI_FILE_NOTIFY_INFORMATION *WinAPI_PtrFILE_NOTIFY_INFORMATION;

typedef
	WinAPI_FILTERKEYS *WinAPI_PtrFILTERKEYS;

typedef
	WinAPI_FLOATING_SAVE_AREA *WinAPI_PtrFLOATING_SAVE_AREA;

typedef
	WinAPI_FOCUS_EVENT_RECORD *WinAPI_PtrFOCUS_EVENT_RECORD;

typedef
	WinAPI_FONTSIGNATURE *WinAPI_PtrFONTSIGNATURE;

typedef
	WinAPI_FORM_INFO_1A *WinAPI_PtrFORM_INFO_1A;

typedef
	WinAPI_FORM_INFO_1W *WinAPI_PtrFORM_INFO_1W;

typedef
	WinAPI_FPO_DATA *WinAPI_PtrFPO_DATA;

typedef
	WinAPI_GCP_RESULTSA *WinAPI_PtrGCP_RESULTSA;

typedef
	WinAPI_GCP_RESULTSW *WinAPI_PtrGCP_RESULTSW;

typedef
	WinAPI_GENERIC_MAPPING *WinAPI_PtrGENERIC_MAPPING;

typedef
	WinAPI_GLYPHMETRICS *WinAPI_PtrGLYPHMETRICS;

typedef
	WinAPI_GLYPHMETRICSFLOAT *WinAPI_PtrGLYPHMETRICSFLOAT;

typedef
	WinAPI_HANDLETABLE *WinAPI_PtrHANDLETABLE;

typedef
	WinAPI_HARDWAREHOOKSTRUCT *WinAPI_PtrHARDWAREHOOKSTRUCT;

typedef
	WinAPI_HELPINFO *WinAPI_PtrHELPINFO;

typedef
	WinAPI_HELPWININFOA *WinAPI_PtrHELPWININFOA;

typedef
	WinAPI_HELPWININFOW *WinAPI_PtrHELPWININFOW;

typedef
	WinAPI_HIGHCONTRASTA *WinAPI_PtrHIGHCONTRASTA;

typedef
	WinAPI_HIGHCONTRASTW *WinAPI_PtrHIGHCONTRASTW;

typedef
	WinAPI_HSZPAIR *WinAPI_PtrHSZPAIR;

typedef
	WinAPI_HW_PROFILE_INFOA *WinAPI_PtrHW_PROFILE_INFOA;

typedef
	WinAPI_HW_PROFILE_INFOW *WinAPI_PtrHW_PROFILE_INFOW;

typedef
	WinAPI_ICONINFO *WinAPI_PtrICONINFO;

typedef
	WinAPI_ICONMETRICSA *WinAPI_PtrICONMETRICSA;

typedef
	WinAPI_ICONMETRICSW *WinAPI_PtrICONMETRICSW;

typedef
	WinAPI_IMAGE_ARCHIVE_MEMBER_HEADER *WinAPI_PtrIMAGE_ARCHIVE_MEMBER_HEADER;

typedef
	WinAPI_IMAGE_AUX_SYMBOL *WinAPI_PtrIMAGE_AUX_SYMBOL;

typedef
	WinAPI_IMAGE_BASE_RELOCATION *WinAPI_PtrIMAGE_BASE_RELOCATION;

typedef
	WinAPI_IMAGE_BOUND_FORWARDER_REF *WinAPI_PtrIMAGE_BOUND_FORWARDER_REF;

typedef
	WinAPI_IMAGE_BOUND_IMPORT_DESCRIPTOR *WinAPI_PtrIMAGE_BOUND_IMPORT_DESCRIPTOR;

typedef
	WinAPI_IMAGE_COFF_SYMBOLS_HEADER *WinAPI_PtrIMAGE_COFF_SYMBOLS_HEADER;

typedef
	WinAPI_IMAGE_DATA_DIRECTORY *WinAPI_PtrIMAGE_DATA_DIRECTORY;

typedef
	WinAPI_IMAGE_DEBUG_DIRECTORY *WinAPI_PtrIMAGE_DEBUG_DIRECTORY;

typedef
	WinAPI_IMAGE_DEBUG_MISC *WinAPI_PtrIMAGE_DEBUG_MISC;

typedef
	WinAPI_IMAGE_DOS_HEADER *WinAPI_PtrIMAGE_DOS_HEADER;

typedef
	WinAPI_IMAGE_EXPORT_DIRECTORY *WinAPI_PtrIMAGE_EXPORT_DIRECTORY;

typedef
	WinAPI_IMAGE_FILE_HEADER *WinAPI_PtrIMAGE_FILE_HEADER;

typedef
	WinAPI_IMAGE_FUNCTION_ENTRY *WinAPI_PtrIMAGE_FUNCTION_ENTRY;

typedef
	WinAPI_IMAGE_IMPORT_BY_NAME *WinAPI_PtrIMAGE_IMPORT_BY_NAME;

typedef
	WinAPI_IMAGE_IMPORT_DESCRIPTOR *WinAPI_PtrIMAGE_IMPORT_DESCRIPTOR;

typedef
	WinAPI_IMAGE_LINENUMBER *WinAPI_PtrIMAGE_LINENUMBER;

typedef
	WinAPI_IMAGE_LOAD_CONFIG_DIRECTORY *WinAPI_PtrIMAGE_LOAD_CONFIG_DIRECTORY;

typedef
	WinAPI_IMAGE_NT_HEADERS *WinAPI_PtrIMAGE_NT_HEADERS;

typedef
	WinAPI_IMAGE_OPTIONAL_HEADER *WinAPI_PtrIMAGE_OPTIONAL_HEADER;

typedef
	WinAPI_IMAGE_OS2_HEADER *WinAPI_PtrIMAGE_OS2_HEADER;

typedef
	WinAPI_IMAGE_RELOCATION *WinAPI_PtrIMAGE_RELOCATION;

typedef
	WinAPI_IMAGE_RESOURCE_DATA_ENTRY *WinAPI_PtrIMAGE_RESOURCE_DATA_ENTRY;

typedef
	WinAPI_IMAGE_RESOURCE_DIRECTORY *WinAPI_PtrIMAGE_RESOURCE_DIRECTORY;

typedef
	WinAPI_IMAGE_RESOURCE_DIRECTORY_ENTRY *WinAPI_PtrIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef
	WinAPI_IMAGE_RESOURCE_DIRECTORY_STRING *WinAPI_PtrIMAGE_RESOURCE_DIRECTORY_STRING;

typedef
	WinAPI_IMAGE_RESOURCE_DIR_STRING_U *WinAPI_PtrIMAGE_RESOURCE_DIR_STRING_U;

typedef
	WinAPI_IMAGE_ROM_HEADERS *WinAPI_PtrIMAGE_ROM_HEADERS;

typedef
	WinAPI_IMAGE_ROM_OPTIONAL_HEADER *WinAPI_PtrIMAGE_ROM_OPTIONAL_HEADER;

typedef
	WinAPI_IMAGE_RUNTIME_FUNCTION_ENTRY *WinAPI_PtrIMAGE_RUNTIME_FUNCTION_ENTRY;

typedef
	WinAPI_IMAGE_SECTION_HEADER *WinAPI_PtrIMAGE_SECTION_HEADER;

typedef
	WinAPI_IMAGE_SEPARATE_DEBUG_HEADER *WinAPI_PtrIMAGE_SEPARATE_DEBUG_HEADER;

typedef
	WinAPI_IMAGE_SYMBOL *WinAPI_PtrIMAGE_SYMBOL;

typedef
	WinAPI_IMAGE_TLS_DIRECTORY *WinAPI_PtrIMAGE_TLS_DIRECTORY;

typedef
	WinAPI_IMAGE_VXD_HEADER *WinAPI_PtrIMAGE_VXD_HEADER;

typedef
	WinAPI_INPUT_RECORD *WinAPI_PtrINPUT_RECORD;

typedef
	WinAPI_JOB_INFO_1A *WinAPI_PtrJOB_INFO_1A;

typedef
	WinAPI_JOB_INFO_1W *WinAPI_PtrJOB_INFO_1W;

typedef
	WinAPI_JOB_INFO_2A *WinAPI_PtrJOB_INFO_2A;

typedef
	WinAPI_JOB_INFO_2W *WinAPI_PtrJOB_INFO_2W;

typedef
	WinAPI_KERNINGPAIR *WinAPI_PtrKERNINGPAIR;

typedef
	WinAPI_KEY_EVENT_RECORD *WinAPI_PtrKEY_EVENT_RECORD;

typedef
	WinAPI_LAYERPLANEDESCRIPTOR *WinAPI_PtrLAYERPLANEDESCRIPTOR;

typedef
	WinAPI_LDT_ENTRY *WinAPI_PtrLDT_ENTRY;

typedef
	WinAPI_LOAD_DLL_DEBUG_INFO *WinAPI_PtrLOAD_DLL_DEBUG_INFO;

typedef
	WinAPI_LOCALESIGNATURE *WinAPI_PtrLOCALESIGNATURE;

typedef
	WinAPI_LOGBRUSH *WinAPI_PtrLOGBRUSH;

typedef
	WinAPI_LOGCOLORSPACEA *WinAPI_PtrLOGCOLORSPACEA;

typedef
	WinAPI_LOGCOLORSPACEW *WinAPI_PtrLOGCOLORSPACEW;

typedef
	WinAPI_LOGFONTA *WinAPI_PtrLOGFONTA;

typedef
	WinAPI_LOGFONTW *WinAPI_PtrLOGFONTW;

typedef
	WinAPI_LOGPALETTE *WinAPI_PtrLOGPALETTE;

typedef
	WinAPI_LOGPEN *WinAPI_PtrLOGPEN;

typedef
	WinAPI_LUID_AND_ATTRIBUTES *WinAPI_PtrLUID_AND_ATTRIBUTES;

typedef
	WinAPI_LUID_AND_ATTRIBUTES_ARRAY *WinAPI_PtrLUID_AND_ATTRIBUTES_ARRAY;

typedef
	WinAPI_MAT2 *WinAPI_PtrMAT2;

typedef
	WinAPI_MDICREATESTRUCTA *WinAPI_PtrMDICREATESTRUCTA;

typedef
	WinAPI_MDICREATESTRUCTW *WinAPI_PtrMDICREATESTRUCTW;

typedef
	WinAPI_MDINEXTMENU *WinAPI_PtrMDINEXTMENU;

typedef
	WinAPI_MEASUREITEMSTRUCT *WinAPI_PtrMEASUREITEMSTRUCT;

typedef
	WinAPI_MEMORYSTATUS *WinAPI_PtrMEMORYSTATUS;

typedef
	WinAPI_MEMORY_BASIC_INFORMATION *WinAPI_PtrMEMORY_BASIC_INFORMATION;

typedef
	WinAPI_MENUITEMINFOA *WinAPI_PtrMENUITEMINFOA;

typedef
	WinAPI_MENUITEMINFOW *WinAPI_PtrMENUITEMINFOW;

typedef
	WinAPI_MENUITEMTEMPLATE *WinAPI_PtrMENUITEMTEMPLATE;

typedef
	WinAPI_MENUITEMTEMPLATEHEADER *WinAPI_PtrMENUITEMTEMPLATEHEADER;

typedef
	WinAPI_MENUTEMPLATE *WinAPI_PtrMENUTEMPLATE;

typedef
	WinAPI_MENUTEMPLATEA *WinAPI_PtrMENUTEMPLATEA;

typedef
	WinAPI_MENUTEMPLATEW *WinAPI_PtrMENUTEMPLATEW;

typedef
	WinAPI_MENU_EVENT_RECORD *WinAPI_PtrMENU_EVENT_RECORD;

typedef
	WinAPI_MESSAGE_RESOURCE_BLOCK *WinAPI_PtrMESSAGE_RESOURCE_BLOCK;

typedef
	WinAPI_MESSAGE_RESOURCE_DATA *WinAPI_PtrMESSAGE_RESOURCE_DATA;

typedef
	WinAPI_MESSAGE_RESOURCE_ENTRY *WinAPI_PtrMESSAGE_RESOURCE_ENTRY;

typedef
	WinAPI_METAFILEPICT *WinAPI_PtrMETAFILEPICT;

typedef
	WinAPI_METAHEADER *WinAPI_PtrMETAHEADER;

typedef
	WinAPI_METARECORD *WinAPI_PtrMETARECORD;

typedef
	WinAPI_MINIMIZEDMETRICS *WinAPI_PtrMINIMIZEDMETRICS;

typedef
	WinAPI_MINMAXINFO *WinAPI_PtrMINMAXINFO;

typedef
	WinAPI_MODEMDEVCAPS *WinAPI_PtrMODEMDEVCAPS;

typedef
	WinAPI_MODEMSETTINGS *WinAPI_PtrMODEMSETTINGS;

typedef
	WinAPI_MONCBSTRUCT *WinAPI_PtrMONCBSTRUCT;

typedef
	WinAPI_MONCONVSTRUCT *WinAPI_PtrMONCONVSTRUCT;

typedef
	WinAPI_MONERRSTRUCT *WinAPI_PtrMONERRSTRUCT;

typedef
	WinAPI_MONHSZSTRUCTA *WinAPI_PtrMONHSZSTRUCTA;

typedef
	WinAPI_MONHSZSTRUCTW *WinAPI_PtrMONHSZSTRUCTW;

typedef
	WinAPI_MONITOR_INFO_1A *WinAPI_PtrMONITOR_INFO_1A;

typedef
	WinAPI_MONITOR_INFO_1W *WinAPI_PtrMONITOR_INFO_1W;

typedef
	WinAPI_MONITOR_INFO_2A *WinAPI_PtrMONITOR_INFO_2A;

typedef
	WinAPI_MONITOR_INFO_2W *WinAPI_PtrMONITOR_INFO_2W;

typedef
	WinAPI_MONLINKSTRUCT *WinAPI_PtrMONLINKSTRUCT;

typedef
	WinAPI_MONMSGSTRUCT *WinAPI_PtrMONMSGSTRUCT;

typedef
	WinAPI_MOUSEHOOKSTRUCT *WinAPI_PtrMOUSEHOOKSTRUCT;

typedef
	WinAPI_MOUSEKEYS *WinAPI_PtrMOUSEKEYS;

typedef
	WinAPI_MOUSE_EVENT_RECORD *WinAPI_PtrMOUSE_EVENT_RECORD;

typedef
	WinAPI_MSG *WinAPI_PtrMSG;

typedef
	WinAPI_MSGBOXPARAMSA *WinAPI_PtrMSGBOXPARAMSA;

typedef
	WinAPI_MSGBOXPARAMSW *WinAPI_PtrMSGBOXPARAMSW;

typedef
	WinAPI_MULTIKEYHELPA *WinAPI_PtrMULTIKEYHELPA;

typedef
	WinAPI_MULTIKEYHELPW *WinAPI_PtrMULTIKEYHELPW;

typedef
	WinAPI_NCCALCSIZE_PARAMS *WinAPI_PtrNCCALCSIZE_PARAMS;

typedef
	WinAPI_NEWTEXTMETRICA *WinAPI_PtrNEWTEXTMETRICA;

typedef
	WinAPI_NEWTEXTMETRICW *WinAPI_PtrNEWTEXTMETRICW;

typedef
	WinAPI_NMHDR *WinAPI_PtrNMHDR;

typedef
	WinAPI_NONCLIENTMETRICSA *WinAPI_PtrNONCLIENTMETRICSA;

typedef
	WinAPI_NONCLIENTMETRICSW *WinAPI_PtrNONCLIENTMETRICSW;

typedef
	WinAPI_NOTIFYICONDATAA *WinAPI_PtrNOTIFYICONDATAA;

typedef
	WinAPI_NOTIFYICONDATAW *WinAPI_PtrNOTIFYICONDATAW;

typedef
	WinAPI_NUMBERFMTA *WinAPI_PtrNUMBERFMTA;

typedef
	WinAPI_NUMBERFMTW *WinAPI_PtrNUMBERFMTW;

typedef
	WinAPI_OFSTRUCT *WinAPI_PtrOFSTRUCT;

typedef
	WinAPI_OSVERSIONINFOA *WinAPI_PtrOSVERSIONINFOA;

typedef
	WinAPI_OSVERSIONINFOW *WinAPI_PtrOSVERSIONINFOW;

typedef
	WinAPI_OUTLINETEXTMETRICA *WinAPI_PtrOUTLINETEXTMETRICA;

typedef
	WinAPI_OUTLINETEXTMETRICW *WinAPI_PtrOUTLINETEXTMETRICW;

typedef
	WinAPI_OUTPUT_DEBUG_STRING_INFO *WinAPI_PtrOUTPUT_DEBUG_STRING_INFO;

typedef
	WinAPI_OVERLAPPED *WinAPI_PtrOVERLAPPED;

typedef
	WinAPI_PAINTSTRUCT *WinAPI_PtrPAINTSTRUCT;

typedef
	WinAPI_PALETTEENTRY *WinAPI_PtrPALETTEENTRY;

typedef
	WinAPI_PANOSE *WinAPI_PtrPANOSE;

typedef
	WinAPI_PELARRAY *WinAPI_PtrPELARRAY;

typedef
	WinAPI_PIXELFORMATDESCRIPTOR *WinAPI_PtrPIXELFORMATDESCRIPTOR;

typedef
	WinAPI_POINT *WinAPI_PtrPOINT;

typedef
	WinAPI_POINTFLOAT *WinAPI_PtrPOINTFLOAT;

typedef
	WinAPI_POINTFX *WinAPI_PtrPOINTFX;

typedef
	WinAPI_POINTS *WinAPI_PtrPOINTS;

typedef
	WinAPI_POLYTEXTA *WinAPI_PtrPOLYTEXTA;

typedef
	WinAPI_POLYTEXTW *WinAPI_PtrPOLYTEXTW;

typedef
	WinAPI_PORT_INFO_1A *WinAPI_PtrPORT_INFO_1A;

typedef
	WinAPI_PORT_INFO_1W *WinAPI_PtrPORT_INFO_1W;

typedef
	WinAPI_PORT_INFO_2A *WinAPI_PtrPORT_INFO_2A;

typedef
	WinAPI_PORT_INFO_2W *WinAPI_PtrPORT_INFO_2W;

typedef
	WinAPI_PRINTER_DEFAULTSA *WinAPI_PtrPRINTER_DEFAULTSA;

typedef
	WinAPI_PRINTER_DEFAULTSW *WinAPI_PtrPRINTER_DEFAULTSW;

typedef
	WinAPI_PRINTER_INFO_1A *WinAPI_PtrPRINTER_INFO_1A;

typedef
	WinAPI_PRINTER_INFO_1W *WinAPI_PtrPRINTER_INFO_1W;

typedef
	WinAPI_PRINTER_INFO_2A *WinAPI_PtrPRINTER_INFO_2A;

typedef
	WinAPI_PRINTER_INFO_2W *WinAPI_PtrPRINTER_INFO_2W;

typedef
	WinAPI_PRINTER_INFO_3 *WinAPI_PtrPRINTER_INFO_3;

typedef
	WinAPI_PRINTER_INFO_4A *WinAPI_PtrPRINTER_INFO_4A;

typedef
	WinAPI_PRINTER_INFO_4W *WinAPI_PtrPRINTER_INFO_4W;

typedef
	WinAPI_PRINTER_INFO_5A *WinAPI_PtrPRINTER_INFO_5A;

typedef
	WinAPI_PRINTER_INFO_5W *WinAPI_PtrPRINTER_INFO_5W;

typedef
	WinAPI_PRINTER_INFO_6 *WinAPI_PtrPRINTER_INFO_6;

typedef
	WinAPI_PRINTER_NOTIFY_INFO *WinAPI_PtrPRINTER_NOTIFY_INFO;

typedef
	WinAPI_PRINTER_NOTIFY_INFO_DATA *WinAPI_PtrPRINTER_NOTIFY_INFO_DATA;

typedef
	WinAPI_PRINTER_NOTIFY_OPTIONS *WinAPI_PtrPRINTER_NOTIFY_OPTIONS;

typedef
	WinAPI_PRINTPROCESSOR_INFO_1A *WinAPI_PtrPRINTPROCESSOR_INFO_1A;

typedef
	WinAPI_PRINTPROCESSOR_INFO_1W *WinAPI_PtrPRINTPROCESSOR_INFO_1W;

typedef
	WinAPI_PRIVILEGE_SET *WinAPI_PtrPRIVILEGE_SET;

typedef
	WinAPI_PROCESS_HEAP_ENTRY *WinAPI_PtrPROCESS_HEAP_ENTRY;

typedef
	WinAPI_PROCESS_INFORMATION *WinAPI_PtrPROCESS_INFORMATION;

typedef
	WinAPI_PROPSHEETHEADERA *WinAPI_PtrPROPSHEETHEADERA;

typedef
	WinAPI_PROPSHEETHEADERW *WinAPI_PtrPROPSHEETHEADERW;

typedef
	WinAPI_PROVIDOR_INFO_1A *WinAPI_PtrPROVIDOR_INFO_1A;

typedef
	WinAPI_PROVIDOR_INFO_1W *WinAPI_PtrPROVIDOR_INFO_1W;

typedef
	WinAPI_PSHNOTIFY *WinAPI_PtrPSHNOTIFY;

typedef
	WinAPI_PVALUEA *WinAPI_PtrPVALUEA;

typedef
	WinAPI_PVALUEW *WinAPI_PtrPVALUEW;

typedef
	struct WinAPI_QUERY_SERVICE_CONFIGA *WinAPI_PtrQUERY_SERVICE_CONFIGA;

typedef
	struct WinAPI_QUERY_SERVICE_CONFIGW *WinAPI_PtrQUERY_SERVICE_CONFIGW;

typedef
	struct WinAPI_QUERY_SERVICE_LOCK_STATUSA *WinAPI_PtrQUERY_SERVICE_LOCK_STATUSA;

typedef
	struct WinAPI_QUERY_SERVICE_LOCK_STATUSW *WinAPI_PtrQUERY_SERVICE_LOCK_STATUSW;

typedef
	struct WinAPI_QUOTA_LIMITS *WinAPI_PtrQUOTA_LIMITS;

typedef
	struct WinAPI_RASTERIZER_STATUS *WinAPI_PtrRASTERIZER_STATUS;

typedef
	WinAPI_RECT *WinAPI_PtrRECT;

typedef
	struct WinAPI_REG_PROVIDER *WinAPI_PtrREG_PROVIDER;

typedef
	WinAPI_RGBQUAD *WinAPI_PtrRGBQUAD;

typedef
	struct WinAPI_RGNDATA *WinAPI_PtrRGNDATA;

typedef
	struct WinAPI_RGNDATAHEADER *WinAPI_PtrRGNDATAHEADER;

typedef
	struct WinAPI_RIP_INFO *WinAPI_PtrRIP_INFO;

typedef
	struct WinAPI_SCROLLINFO *WinAPI_PtrSCROLLINFO;

typedef
	struct WinAPI_SECURITY_ATTRIBUTES *WinAPI_PtrSECURITY_ATTRIBUTES;

typedef
	struct WinAPI_SECURITY_DESCRIPTOR *WinAPI_PtrSECURITY_DESCRIPTOR;

typedef
	WinAPI_SECURITY_QUALITY_OF_SERVICE *WinAPI_PtrSECURITY_QUALITY_OF_SERVICE;

typedef
	struct WinAPI_SERIALKEYSA *WinAPI_PtrSERIALKEYSA;

typedef
	struct WinAPI_SERIALKEYSW *WinAPI_PtrSERIALKEYSW;

typedef
	WinAPI_SERVICE_STATUS *WinAPI_PtrSERVICE_STATUS;

typedef
	struct WinAPI_SERVICE_TABLE_ENTRYA *WinAPI_PtrSERVICE_TABLE_ENTRYA;

typedef
	struct WinAPI_SERVICE_TABLE_ENTRYW *WinAPI_PtrSERVICE_TABLE_ENTRYW;

typedef
	struct WinAPI_SE_IMPERSONATION_STATE *WinAPI_PtrSE_IMPERSONATION_STATE;

typedef
	struct WinAPI_SHELLEXECUTEINFOA *WinAPI_PtrSHELLEXECUTEINFOA;

typedef
	struct WinAPI_SHELLEXECUTEINFOW *WinAPI_PtrSHELLEXECUTEINFOW;

typedef
	struct WinAPI_SHFILEINFOA *WinAPI_PtrSHFILEINFOA;

typedef
	struct WinAPI_SHFILEINFOW *WinAPI_PtrSHFILEINFOW;

typedef
	struct WinAPI_SHFILEOPSTRUCTA *WinAPI_PtrSHFILEOPSTRUCTA;

typedef
	struct WinAPI_SHFILEOPSTRUCTW *WinAPI_PtrSHFILEOPSTRUCTW;

typedef
	struct WinAPI_SHNAMEMAPPINGA *WinAPI_PtrSHNAMEMAPPINGA;

typedef
	struct WinAPI_SHNAMEMAPPINGW *WinAPI_PtrSHNAMEMAPPINGW;

typedef
	struct WinAPI_SID *WinAPI_PtrSID;

typedef
	struct WinAPI_SID_AND_ATTRIBUTES *WinAPI_PtrSID_AND_ATTRIBUTES;

typedef
	struct WinAPI_SID_AND_ATTRIBUTES {
		LONGINT Sid;
		SET Attributes;
	} WinAPI_SID_AND_ATTRIBUTES;

typedef
	WinAPI_SID_AND_ATTRIBUTES WinAPI_SID_AND_ATTRIBUTES_ARRAY[1];

typedef
	WinAPI_SID_AND_ATTRIBUTES_ARRAY *WinAPI_PtrSID_AND_ATTRIBUTES_ARRAY;

typedef
	struct WinAPI_SID_IDENTIFIER_AUTHORITY *WinAPI_PtrSID_IDENTIFIER_AUTHORITY;

typedef
	struct WinAPI_SINGLE_LIST_ENTRY *WinAPI_PtrSINGLE_LIST_ENTRY;

typedef
	WinAPI_SIZE *WinAPI_PtrSIZE;

typedef
	WinAPI_SMALL_RECT *WinAPI_PtrSMALL_RECT;

typedef
	struct WinAPI_SOUNDSENTRYA *WinAPI_PtrSOUNDSENTRYA;

typedef
	struct WinAPI_SOUNDSENTRYW *WinAPI_PtrSOUNDSENTRYW;

typedef
	struct WinAPI_STARTUPINFOA *WinAPI_PtrSTARTUPINFOA;

typedef
	struct WinAPI_STARTUPINFOW *WinAPI_PtrSTARTUPINFOW;

typedef
	struct WinAPI_STICKYKEYS *WinAPI_PtrSTICKYKEYS;

typedef
	struct WinAPI_STYLESTRUCT *WinAPI_PtrSTYLESTRUCT;

typedef
	WinAPI_SYSTEMTIME *WinAPI_PtrSYSTEMTIME;

typedef
	struct WinAPI_SYSTEM_ALARM_ACE *WinAPI_PtrSYSTEM_ALARM_ACE;

typedef
	struct WinAPI_SYSTEM_AUDIT_ACE *WinAPI_PtrSYSTEM_AUDIT_ACE;

typedef
	struct WinAPI_SYSTEM_INFO *WinAPI_PtrSYSTEM_INFO;

typedef
	struct WinAPI_SYSTEM_POWER_STATUS *WinAPI_PtrSYSTEM_POWER_STATUS;

typedef
	struct WinAPI_TAPE_CREATE_PARTITION *WinAPI_PtrTAPE_CREATE_PARTITION;

typedef
	struct WinAPI_TAPE_ERASE *WinAPI_PtrTAPE_ERASE;

typedef
	struct WinAPI_TAPE_GET_DRIVE_PARAMETERS *WinAPI_PtrTAPE_GET_DRIVE_PARAMETERS;

typedef
	struct WinAPI_TAPE_GET_MEDIA_PARAMETERS *WinAPI_PtrTAPE_GET_MEDIA_PARAMETERS;

typedef
	struct WinAPI_TAPE_GET_POSITION *WinAPI_PtrTAPE_GET_POSITION;

typedef
	struct WinAPI_TAPE_PREPARE *WinAPI_PtrTAPE_PREPARE;

typedef
	struct WinAPI_TAPE_SET_DRIVE_PARAMETERS *WinAPI_PtrTAPE_SET_DRIVE_PARAMETERS;

typedef
	struct WinAPI_TAPE_SET_MEDIA_PARAMETERS *WinAPI_PtrTAPE_SET_MEDIA_PARAMETERS;

typedef
	struct WinAPI_TAPE_SET_POSITION *WinAPI_PtrTAPE_SET_POSITION;

typedef
	struct WinAPI_TAPE_WRITE_MARKS *WinAPI_PtrTAPE_WRITE_MARKS;

typedef
	WinAPI_TEXTMETRICA *WinAPI_PtrTEXTMETRICA;

typedef
	WinAPI_TEXTMETRICW *WinAPI_PtrTEXTMETRICW;

typedef
	struct WinAPI_TIME_ZONE_INFORMATION *WinAPI_PtrTIME_ZONE_INFORMATION;

typedef
	struct WinAPI_TOGGLEKEYS *WinAPI_PtrTOGGLEKEYS;

typedef
	struct WinAPI_TOKEN_CONTROL *WinAPI_PtrTOKEN_CONTROL;

typedef
	struct WinAPI_TOKEN_DEFAULT_DACL *WinAPI_PtrTOKEN_DEFAULT_DACL;

typedef
	struct WinAPI_TOKEN_GROUPS *WinAPI_PtrTOKEN_GROUPS;

typedef
	struct WinAPI_TOKEN_OWNER *WinAPI_PtrTOKEN_OWNER;

typedef
	struct WinAPI_TOKEN_PRIMARY_GROUP *WinAPI_PtrTOKEN_PRIMARY_GROUP;

typedef
	struct WinAPI_TOKEN_PRIVILEGES *WinAPI_PtrTOKEN_PRIVILEGES;

typedef
	struct WinAPI_TOKEN_SOURCE *WinAPI_PtrTOKEN_SOURCE;

typedef
	struct WinAPI_TOKEN_STATISTICS *WinAPI_PtrTOKEN_STATISTICS;

typedef
	struct WinAPI_TOKEN_USER *WinAPI_PtrTOKEN_USER;

typedef
	struct WinAPI_TPMPARAMS *WinAPI_PtrTPMPARAMS;

typedef
	struct WinAPI_TTPOLYCURVE *WinAPI_PtrTTPOLYCURVE;

typedef
	struct WinAPI_TTPOLYGONHEADER *WinAPI_PtrTTPOLYGONHEADER;

typedef
	struct WinAPI_UNLOAD_DLL_DEBUG_INFO *WinAPI_PtrUNLOAD_DLL_DEBUG_INFO;

typedef
	struct WinAPI_USEROBJECTFLAGS *WinAPI_PtrUSEROBJECTFLAGS;

typedef
	struct WinAPI_VALENTA *WinAPI_PtrVALENTA;

typedef
	struct WinAPI_VALENTW *WinAPI_PtrVALENTW;

typedef
	struct WinAPI_WIN32_FILE_ATTRIBUTE_DATA *WinAPI_PtrWIN32_FILE_ATTRIBUTE_DATA;

typedef
	struct WinAPI_WIN32_FIND_DATAA *WinAPI_PtrWIN32_FIND_DATAA;

typedef
	struct WinAPI_WIN32_FIND_DATAW *WinAPI_PtrWIN32_FIND_DATAW;

typedef
	struct WinAPI_WIN32_STREAM_ID *WinAPI_PtrWIN32_STREAM_ID;

typedef
	struct WinAPI_WINDOWPLACEMENT *WinAPI_PtrWINDOWPLACEMENT;

typedef
	struct WinAPI_WINDOW_BUFFER_SIZE_RECORD *WinAPI_PtrWINDOW_BUFFER_SIZE_RECORD;

typedef
	struct WinAPI_WIN_CERTIFICATE *WinAPI_PtrWIN_CERTIFICATE;

typedef
	struct WinAPI_WIN_SPUB_TRUSTEDPUB_DATA *WinAPI_PtrWIN_SPUB_TRUSTEDPUB_DATA;

typedef
	struct WinAPI_WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT *WinAPI_PtrWIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJE;

typedef
	struct WinAPI_WIN_TRUST_ACTDATA_SUBJECT_ONLY *WinAPI_PtrWIN_TRUST_ACTDATA_SUBJECT_ONLY;

typedef
	struct WinAPI_WIN_TRUST_SUBJECT_FILE *WinAPI_PtrWIN_TRUST_SUBJECT_FILE;

typedef
	struct WinAPI_WNDCLASSA *WinAPI_PtrWNDCLASSA;

typedef
	struct WinAPI_WNDCLASSEXA *WinAPI_PtrWNDCLASSEXA;

typedef
	struct WinAPI_WNDCLASSEXW *WinAPI_PtrWNDCLASSEXW;

typedef
	struct WinAPI_WNDCLASSW *WinAPI_PtrWNDCLASSW;

typedef
	WinAPI_XFORM *WinAPI_PtrXFORM;

typedef
	struct WinAPI_val_context *WinAPI_Ptrval_context;

typedef
	struct WinAPI_val_context {
		INTEGER valuelen;
		LONGINT value_context, val_buff_ptr;
	} WinAPI_val_context;

typedef
	INTEGER (__STDCALL *WinAPI_QUERYHANDLER)(LONGINT, WinAPI_val_context*, INTEGER, LONGINT, INTEGER*, INTEGER);

typedef
	struct WinAPI_QUERY_SERVICE_CONFIGA {
		SET dwServiceType;
		INTEGER dwStartType, dwErrorControl;
		LONGINT lpBinaryPathName, lpLoadOrderGroup;
		INTEGER dwTagId;
		LONGINT lpDependencies, lpServiceStartName, lpDisplayName;
	} WinAPI_QUERY_SERVICE_CONFIGA;

typedef
	struct WinAPI_QUERY_SERVICE_CONFIGW {
		SET dwServiceType;
		INTEGER dwStartType, dwErrorControl;
		LONGINT lpBinaryPathName, lpLoadOrderGroup;
		INTEGER dwTagId;
		LONGINT lpDependencies, lpServiceStartName, lpDisplayName;
	} WinAPI_QUERY_SERVICE_CONFIGW;

typedef
	struct WinAPI_QUERY_SERVICE_LOCK_STATUSA {
		INTEGER fIsLocked;
		LONGINT lpLockOwner;
		INTEGER dwLockDuration;
	} WinAPI_QUERY_SERVICE_LOCK_STATUSA;

typedef
	struct WinAPI_QUERY_SERVICE_LOCK_STATUSW {
		INTEGER fIsLocked;
		LONGINT lpLockOwner;
		INTEGER dwLockDuration;
	} WinAPI_QUERY_SERVICE_LOCK_STATUSW;

typedef
	struct WinAPI_QUOTA_LIMITS {
		INTEGER PagedPoolLimit, NonPagedPoolLimit, MinimumWorkingSetSize, MaximumWorkingSetSize, PagefileLimit;
		LONGINT TimeLimit;
	} WinAPI_QUOTA_LIMITS;

typedef
	struct WinAPI_RASTERIZER_STATUS {
		SHORTINT nSize, wFlags, nLanguageID;
	} WinAPI_RASTERIZER_STATUS;

typedef
	struct WinAPI_REG_PROVIDER {
		WinAPI_QUERYHANDLER pi_R0_1val, pi_R0_allvals, pi_R3_1val, pi_R3_allvals;
		INTEGER pi_flags;
		LONGINT pi_key_context;
	} WinAPI_REG_PROVIDER;

typedef
	struct WinAPI_RGNDATAHEADER {
		INTEGER dwSize, iType, nCount, nRgnSize;
		WinAPI_RECT rcBound;
	} WinAPI_RGNDATAHEADER;

typedef
	struct WinAPI_RGNDATA {
		WinAPI_RGNDATAHEADER rdh;
		CHAR Buffer[1];
	} WinAPI_RGNDATA;

typedef
	struct WinAPI_RIP_INFO {
		INTEGER dwError, dwType;
	} WinAPI_RIP_INFO;

typedef
	INTEGER (__STDCALL *WinAPI_ROC)(void);

typedef
	INTEGER (__STDCALL *WinAPI_ROPENUMPROC)(void);

typedef
	INTEGER (__STDCALL *WinAPI_ROPENUMPROCA)(void);

typedef
	INTEGER (__STDCALL *WinAPI_ROPENUMPROCEX)(void);

typedef
	INTEGER (__STDCALL *WinAPI_ROPENUMPROCEXA)(void);

typedef
	INTEGER (__STDCALL *WinAPI_ROPENUMPROCEXW)(void);

typedef
	INTEGER (__STDCALL *WinAPI_ROPENUMPROCW)(void);

typedef
	struct WinAPI_SCROLLINFO {
		INTEGER cbSize;
		SET fMask;
		INTEGER nMin, nMax, nPage, nPos, nTrackPos;
	} WinAPI_SCROLLINFO;

typedef
	struct WinAPI_SECURITY_ATTRIBUTES {
		INTEGER nLength;
		LONGINT lpSecurityDescriptor;
		INTEGER bInheritHandle;
	} WinAPI_SECURITY_ATTRIBUTES;

typedef
	struct WinAPI_SECURITY_DESCRIPTOR {
		CHAR Revision, Sbz1;
		SHORTINT Control;
		LONGINT Owner, Group;
		WinAPI_PtrACL Sacl, Dacl;
	} WinAPI_SECURITY_DESCRIPTOR;

typedef
	INTEGER (__STDCALL *WinAPI_SENDASYNCPROC)(void);

typedef
	struct WinAPI_SERIALKEYSA {
		INTEGER cbSize;
		SET dwFlags;
		LONGINT lpszActivePort, lpszPort;
		INTEGER iBaudRate, iPortState, iActive;
	} WinAPI_SERIALKEYSA;

typedef
	struct WinAPI_SERIALKEYSW {
		INTEGER cbSize;
		SET dwFlags;
		LONGINT lpszActivePort, lpszPort;
		INTEGER iBaudRate, iPortState, iActive;
	} WinAPI_SERIALKEYSW;

typedef
	void (__STDCALL *WinAPI_SERVICE_MAIN_FUNCTIONA)(INTEGER, LONGINT);

typedef
	void (__STDCALL *WinAPI_SERVICE_MAIN_FUNCTIONW)(INTEGER, LONGINT);

typedef
	struct WinAPI_SERVICE_TABLE_ENTRYA {
		LONGINT lpServiceName;
		WinAPI_SERVICE_MAIN_FUNCTIONA lpServiceProc;
	} WinAPI_SERVICE_TABLE_ENTRYA;

typedef
	struct WinAPI_SERVICE_TABLE_ENTRYW {
		LONGINT lpServiceName;
		WinAPI_SERVICE_MAIN_FUNCTIONW lpServiceProc;
	} WinAPI_SERVICE_TABLE_ENTRYW;

typedef
	struct WinAPI_SE_IMPERSONATION_STATE {
		LONGINT Token;
		BOOLEAN CopyOnOpen, EffectiveOnly;
		INTEGER Level;
	} WinAPI_SE_IMPERSONATION_STATE;

typedef
	struct WinAPI_SHELLEXECUTEINFOA {
		INTEGER cbSize;
		SET fMask;
		LONGINT hwnd, lpVerb, lpFile, lpParameters, lpDirectory;
		INTEGER nShow;
		LONGINT hInstApp, lpIDList, lpClass, hkeyClass;
		INTEGER dwHotKey;
		LONGINT hIcon, hProcess;
	} WinAPI_SHELLEXECUTEINFOA;

typedef
	struct WinAPI_SHELLEXECUTEINFOW {
		INTEGER cbSize;
		SET fMask;
		LONGINT hwnd, lpVerb, lpFile, lpParameters, lpDirectory;
		INTEGER nShow;
		LONGINT hInstApp, lpIDList, lpClass, hkeyClass;
		INTEGER dwHotKey;
		LONGINT hIcon, hProcess;
	} WinAPI_SHELLEXECUTEINFOW;

typedef
	struct WinAPI_SHFILEINFOA {
		LONGINT hIcon;
		INTEGER iIcon;
		SET dwAttributes;
		CHAR szDisplayName[260];
		CHAR szTypeName[80];
	} WinAPI_SHFILEINFOA;

typedef
	struct WinAPI_SHFILEINFOW {
		LONGINT hIcon;
		INTEGER iIcon;
		SET dwAttributes;
		SHORTINT szDisplayName[260];
		SHORTINT szTypeName[80];
	} WinAPI_SHFILEINFOW;

typedef
	struct WinAPI_SHFILEOPSTRUCTA {
		LONGINT hwnd;
		INTEGER wFunc;
		LONGINT pFrom, pTo;
		SHORTINT fFlags;
		INTEGER fAnyOperationsAborted;
		LONGINT hNameMappings, lpszProgressTitle;
	} WinAPI_SHFILEOPSTRUCTA;

typedef
	struct WinAPI_SHFILEOPSTRUCTW {
		LONGINT hwnd;
		INTEGER wFunc;
		LONGINT pFrom, pTo;
		SHORTINT fFlags;
		INTEGER fAnyOperationsAborted;
		LONGINT hNameMappings, lpszProgressTitle;
	} WinAPI_SHFILEOPSTRUCTW;

typedef
	struct WinAPI_SHNAMEMAPPINGA {
		LONGINT pszOldPath, pszNewPath;
		INTEGER cchOldPath, cchNewPath;
	} WinAPI_SHNAMEMAPPINGA;

typedef
	struct WinAPI_SHNAMEMAPPINGW {
		LONGINT pszOldPath, pszNewPath;
		INTEGER cchOldPath, cchNewPath;
	} WinAPI_SHNAMEMAPPINGW;

typedef
	struct WinAPI_SID_IDENTIFIER_AUTHORITY {
		CHAR Value[6];
	} WinAPI_SID_IDENTIFIER_AUTHORITY;

typedef
	struct WinAPI_SID {
		CHAR Revision, SubAuthorityCount;
		WinAPI_SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
		INTEGER SubAuthority[1];
	} WinAPI_SID;

typedef
	struct WinAPI_SINGLE_LIST_ENTRY {
		WinAPI_PtrSINGLE_LIST_ENTRY Next;
	} WinAPI_SINGLE_LIST_ENTRY;

typedef
	struct WinAPI_SOUNDSENTRYA {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER iFSTextEffect, iFSTextEffectMSec, iFSTextEffectColorBits, iFSGrafEffect, iFSGrafEffectMSec, iFSGrafEffectColor, iWindowsEffect, iWindowsEffectMSec;
		LONGINT lpszWindowsEffectDLL;
		INTEGER iWindowsEffectOrdinal;
	} WinAPI_SOUNDSENTRYA;

typedef
	struct WinAPI_SOUNDSENTRYW {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER iFSTextEffect, iFSTextEffectMSec, iFSTextEffectColorBits, iFSGrafEffect, iFSGrafEffectMSec, iFSGrafEffectColor, iWindowsEffect, iWindowsEffectMSec;
		LONGINT lpszWindowsEffectDLL;
		INTEGER iWindowsEffectOrdinal;
	} WinAPI_SOUNDSENTRYW;

typedef
	struct WinAPI_STARTUPINFOA {
		INTEGER cb;
		LONGINT lpReserved, lpDesktop, lpTitle;
		INTEGER dwX, dwY, dwXSize, dwYSize, dwXCountChars, dwYCountChars, dwFillAttribute;
		SET dwFlags;
		SHORTINT wShowWindow, cbReserved2;
		LONGINT lpReserved2, hStdInput, hStdOutput, hStdError;
	} WinAPI_STARTUPINFOA;

typedef
	struct WinAPI_STARTUPINFOW {
		INTEGER cb;
		LONGINT lpReserved, lpDesktop, lpTitle;
		INTEGER dwX, dwY, dwXSize, dwYSize, dwXCountChars, dwYCountChars, dwFillAttribute;
		SET dwFlags;
		SHORTINT wShowWindow, cbReserved2;
		LONGINT lpReserved2, hStdInput, hStdOutput, hStdError;
	} WinAPI_STARTUPINFOW;

typedef
	struct WinAPI_STICKYKEYS {
		INTEGER cbSize;
		SET dwFlags;
	} WinAPI_STICKYKEYS;

typedef
	struct WinAPI_STYLESTRUCT {
		SET styleOld, styleNew;
	} WinAPI_STYLESTRUCT;

typedef
	struct WinAPI_SYSTEM_ALARM_ACE {
		WinAPI_ACE_HEADER Header;
		SET Mask;
		INTEGER SidStart;
	} WinAPI_SYSTEM_ALARM_ACE;

typedef
	struct WinAPI_SYSTEM_AUDIT_ACE {
		WinAPI_ACE_HEADER Header;
		SET Mask;
		INTEGER SidStart;
	} WinAPI_SYSTEM_AUDIT_ACE;

typedef
	struct WinAPI_SYSTEM_INFO {
		struct WinAPI__35 u;
		INTEGER dwPageSize;
		LONGINT lpMinimumApplicationAddress, lpMaximumApplicationAddress;
		INTEGER dwActiveProcessorMask, dwNumberOfProcessors, dwProcessorType, dwAllocationGranularity;
		SHORTINT wProcessorLevel, wProcessorRevision;
	} WinAPI_SYSTEM_INFO;

typedef
	struct WinAPI_SYSTEM_POWER_STATUS {
		CHAR ACLineStatus, BatteryFlag, BatteryLifePercent, Reserved1;
		INTEGER BatteryLifeTime, BatteryFullLifeTime;
	} WinAPI_SYSTEM_POWER_STATUS;

typedef
	struct WinAPI_TAPE_CREATE_PARTITION {
		INTEGER Method, Count, Size;
	} WinAPI_TAPE_CREATE_PARTITION;

typedef
	struct WinAPI_TAPE_ERASE {
		INTEGER Type;
		BOOLEAN Immediate;
	} WinAPI_TAPE_ERASE;

typedef
	struct WinAPI_TAPE_GET_DRIVE_PARAMETERS {
		BOOLEAN ECC, Compression, DataPadding, ReportSetmarks;
		INTEGER DefaultBlockSize, MaximumBlockSize, MinimumBlockSize, MaximumPartitionCount;
		SET FeaturesLow, FeaturesHigh;
		INTEGER EOTWarningZoneSize;
	} WinAPI_TAPE_GET_DRIVE_PARAMETERS;

typedef
	struct WinAPI_TAPE_GET_MEDIA_PARAMETERS {
		LONGINT Capacity, Remaining;
		INTEGER BlockSize, PartitionCount;
		BOOLEAN WriteProtected;
	} WinAPI_TAPE_GET_MEDIA_PARAMETERS;

typedef
	struct WinAPI_TAPE_GET_POSITION {
		INTEGER Type, Partition;
		LONGINT Offset;
	} WinAPI_TAPE_GET_POSITION;

typedef
	struct WinAPI_TAPE_PREPARE {
		INTEGER Operation;
		BOOLEAN Immediate;
	} WinAPI_TAPE_PREPARE;

typedef
	struct WinAPI_TAPE_SET_DRIVE_PARAMETERS {
		BOOLEAN ECC, Compression, DataPadding, ReportSetmarks;
		INTEGER EOTWarningZoneSize;
	} WinAPI_TAPE_SET_DRIVE_PARAMETERS;

typedef
	struct WinAPI_TAPE_SET_MEDIA_PARAMETERS {
		INTEGER BlockSize;
	} WinAPI_TAPE_SET_MEDIA_PARAMETERS;

typedef
	struct WinAPI_TAPE_SET_POSITION {
		INTEGER Method, Partition;
		LONGINT Offset;
		BOOLEAN Immediate;
	} WinAPI_TAPE_SET_POSITION;

typedef
	struct WinAPI_TAPE_WRITE_MARKS {
		INTEGER Type, Count;
		BOOLEAN Immediate;
	} WinAPI_TAPE_WRITE_MARKS;

typedef
	INTEGER (__STDCALL *WinAPI_TIMEFMT_ENUMPROCA)(void);

typedef
	INTEGER (__STDCALL *WinAPI_TIMEFMT_ENUMPROCW)(void);

typedef
	void (__STDCALL *WinAPI_TIMERAPCROUTINE)(LONGINT, INTEGER, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_TIMERPROC)(void);

typedef
	struct WinAPI_TIME_ZONE_INFORMATION {
		INTEGER Bias;
		SHORTINT StandardName[32];
		WinAPI_SYSTEMTIME StandardDate;
		INTEGER StandardBias;
		SHORTINT DaylightName[32];
		WinAPI_SYSTEMTIME DaylightDate;
		INTEGER DaylightBias;
	} WinAPI_TIME_ZONE_INFORMATION;

typedef
	struct WinAPI_TOGGLEKEYS {
		INTEGER cbSize;
		SET dwFlags;
	} WinAPI_TOGGLEKEYS;

typedef
	struct WinAPI_TOKEN_SOURCE {
		CHAR SourceName[8];
		LONGINT SourceIdentifier;
	} WinAPI_TOKEN_SOURCE;

typedef
	struct WinAPI_TOKEN_CONTROL {
		LONGINT TokenId, AuthenticationId, ModifiedId;
		WinAPI_TOKEN_SOURCE TokenSource;
	} WinAPI_TOKEN_CONTROL;

typedef
	struct WinAPI_TOKEN_DEFAULT_DACL {
		WinAPI_PtrACL DefaultDacl;
	} WinAPI_TOKEN_DEFAULT_DACL;

typedef
	struct WinAPI_TOKEN_GROUPS {
		INTEGER GroupCount;
		WinAPI_SID_AND_ATTRIBUTES Groups[1];
	} WinAPI_TOKEN_GROUPS;

typedef
	struct WinAPI_TOKEN_OWNER {
		LONGINT Owner;
	} WinAPI_TOKEN_OWNER;

typedef
	struct WinAPI_TOKEN_PRIMARY_GROUP {
		LONGINT PrimaryGroup;
	} WinAPI_TOKEN_PRIMARY_GROUP;

typedef
	struct WinAPI_TOKEN_PRIVILEGES {
		INTEGER PrivilegeCount;
		WinAPI_LUID_AND_ATTRIBUTES Privileges[1];
	} WinAPI_TOKEN_PRIVILEGES;

typedef
	struct WinAPI_TOKEN_STATISTICS {
		LONGINT TokenId, AuthenticationId, ExpirationTime;
		INTEGER TokenType, ImpersonationLevel, DynamicCharged, DynamicAvailable, GroupCount, PrivilegeCount;
		LONGINT ModifiedId;
	} WinAPI_TOKEN_STATISTICS;

typedef
	struct WinAPI_TOKEN_USER {
		WinAPI_SID_AND_ATTRIBUTES User;
	} WinAPI_TOKEN_USER;

typedef
	INTEGER (__STDCALL *WinAPI_TOP_LEVEL_EXCEPTION_FILTER)(WinAPI_EXCEPTION_POINTERS*);

typedef
	struct WinAPI_TPMPARAMS {
		INTEGER cbSize;
		WinAPI_RECT rcExclude;
	} WinAPI_TPMPARAMS;

typedef
	struct WinAPI_TTPOLYCURVE {
		SHORTINT wType, cpfx;
		WinAPI_POINTFX apfx[1];
	} WinAPI_TTPOLYCURVE;

typedef
	struct WinAPI_TTPOLYGONHEADER {
		INTEGER cb, dwType;
		WinAPI_POINTFX pfxStart;
	} WinAPI_TTPOLYGONHEADER;

typedef
	struct WinAPI_UNLOAD_DLL_DEBUG_INFO {
		LONGINT lpBaseOfDll;
	} WinAPI_UNLOAD_DLL_DEBUG_INFO;

typedef
	struct WinAPI_USEROBJECTFLAGS {
		INTEGER fInherit, fReserved;
		SET dwFlags;
	} WinAPI_USEROBJECTFLAGS;

typedef
	struct WinAPI_VALENTA {
		LONGINT ve_valuename;
		INTEGER ve_valuelen, ve_valueptr, ve_type;
	} WinAPI_VALENTA;

typedef
	struct WinAPI_VALENTW {
		LONGINT ve_valuename;
		INTEGER ve_valuelen, ve_valueptr, ve_type;
	} WinAPI_VALENTW;

typedef
	struct WinAPI_VS_FIXEDFILEINFO {
		INTEGER dwSignature, dwStrucVersion, dwFileVersionMS, dwFileVersionLS, dwProductVersionMS, dwProductVersionLS;
		SET dwFileFlagsMask, dwFileFlags, dwFileOS;
		INTEGER dwFileType, dwFileSubtype, dwFileDateMS, dwFileDateLS;
	} WinAPI_VS_FIXEDFILEINFO;

typedef
	struct WinAPI_WIN32_FILE_ATTRIBUTE_DATA {
		SET dwFileAttributes;
		WinAPI_FILETIME ftCreationTime, ftLastAccessTime, ftLastWriteTime;
		INTEGER nFileSizeHigh, nFileSizeLow;
	} WinAPI_WIN32_FILE_ATTRIBUTE_DATA;

typedef
	struct WinAPI_WIN32_FIND_DATAA {
		SET dwFileAttributes;
		WinAPI_FILETIME ftCreationTime, ftLastAccessTime, ftLastWriteTime;
		INTEGER nFileSizeHigh, nFileSizeLow, dwReserved0, dwReserved1;
		CHAR cFileName[260];
		CHAR cAlternateFileName[14];
	} WinAPI_WIN32_FIND_DATAA;

typedef
	struct WinAPI_WIN32_FIND_DATAW {
		SET dwFileAttributes;
		WinAPI_FILETIME ftCreationTime, ftLastAccessTime, ftLastWriteTime;
		INTEGER nFileSizeHigh, nFileSizeLow, dwReserved0, dwReserved1;
		SHORTINT cFileName[260];
		SHORTINT cAlternateFileName[14];
	} WinAPI_WIN32_FIND_DATAW;

typedef
	struct WinAPI_WIN32_STREAM_ID {
		INTEGER dwStreamId;
		SET dwStreamAttributes;
		LONGINT Size;
		INTEGER dwStreamNameSize;
		SHORTINT cStreamName[1];
	} WinAPI_WIN32_STREAM_ID;

typedef
	struct WinAPI_WINDOWPLACEMENT {
		INTEGER length;
		SET flags;
		INTEGER showCmd;
		WinAPI_POINT ptMinPosition, ptMaxPosition;
		WinAPI_RECT rcNormalPosition;
	} WinAPI_WINDOWPLACEMENT;

typedef
	struct WinAPI_WINDOWPOS {
		LONGINT hwnd, hwndInsertAfter;
		INTEGER x, y, cx, cy;
		SET flags;
	} WinAPI_WINDOWPOS;

typedef
	struct WinAPI_WINDOW_BUFFER_SIZE_RECORD {
		WinAPI_COORD dwSize;
	} WinAPI_WINDOW_BUFFER_SIZE_RECORD;

typedef
	INTEGER (__STDCALL *WinAPI_WINSTAENUMPROC)(void);

typedef
	INTEGER (__STDCALL *WinAPI_WINSTAENUMPROCA)(void);

typedef
	INTEGER (__STDCALL *WinAPI_WINSTAENUMPROCW)(void);

typedef
	struct WinAPI_WIN_CERTIFICATE {
		INTEGER dwLength;
		SHORTINT wRevision, wCertificateType;
		CHAR bCertificate[1];
	} WinAPI_WIN_CERTIFICATE;

typedef
	struct WinAPI_WIN_SPUB_TRUSTEDPUB_DATA {
		LONGINT hClientToken;
		WinAPI_PtrWIN_CERTIFICATE lpCertificate;
	} WinAPI_WIN_SPUB_TRUSTEDPUB_DATA;

typedef
	struct WinAPI_WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT {
		LONGINT hClientToken;
		INTEGER dwSubjectType;
		LONGINT Subject;
	} WinAPI_WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT;

typedef
	struct WinAPI_WIN_TRUST_ACTDATA_SUBJECT_ONLY {
		INTEGER dwSubjectType;
		LONGINT Subject;
	} WinAPI_WIN_TRUST_ACTDATA_SUBJECT_ONLY;

typedef
	struct WinAPI_WIN_TRUST_SUBJECT_FILE {
		LONGINT hFile, lpPath;
	} WinAPI_WIN_TRUST_SUBJECT_FILE;

typedef
	LONGINT (__STDCALL *WinAPI_WNDPROC)(LONGINT, INTEGER, LONGINT, LONGINT);

typedef
	struct WinAPI_WNDCLASSA {
		SET style;
		WinAPI_WNDPROC lpfnWndProc;
		INTEGER cbClsExtra, cbWndExtra;
		LONGINT hInstance, hIcon, hCursor, hbrBackground, lpszMenuName, lpszClassName;
	} WinAPI_WNDCLASSA;

typedef
	struct WinAPI_WNDCLASSEXA {
		INTEGER cbSize;
		SET style;
		WinAPI_WNDPROC lpfnWndProc;
		INTEGER cbClsExtra, cbWndExtra;
		LONGINT hInstance, hIcon, hCursor, hbrBackground, lpszMenuName, lpszClassName, hIconSm;
	} WinAPI_WNDCLASSEXA;

typedef
	struct WinAPI_WNDCLASSEXW {
		INTEGER cbSize;
		SET style;
		WinAPI_WNDPROC lpfnWndProc;
		INTEGER cbClsExtra, cbWndExtra;
		LONGINT hInstance, hIcon, hCursor, hbrBackground, lpszMenuName, lpszClassName, hIconSm;
	} WinAPI_WNDCLASSEXW;

typedef
	struct WinAPI_WNDCLASSW {
		SET style;
		WinAPI_WNDPROC lpfnWndProc;
		INTEGER cbClsExtra, cbWndExtra;
		LONGINT hInstance, hIcon, hCursor, hbrBackground, lpszMenuName, lpszClassName;
	} WinAPI_WNDCLASSW;

typedef
	INTEGER (__STDCALL *WinAPI_WNDENUMPROC)(void);

typedef
	struct WinAPI__EXCEPTION_REGISTRATION_RECORD {
		char _prvt0[1];
	} WinAPI__EXCEPTION_REGISTRATION_RECORD;

typedef
	struct WinAPI__POINTL {
		INTEGER x, y;
	} WinAPI__POINTL;

typedef
	struct WinAPI__PSP {
		char _prvt0[1];
	} WinAPI__PSP;

typedef
	struct WinAPI__RECTL {
		INTEGER left, top, right, bottom;
	} WinAPI__RECTL;




__EXTERN INTEGER __STDCALL AbortDoc (LONGINT p0);
__EXTERN INTEGER __STDCALL AbortPath (LONGINT p0);
__EXTERN INTEGER __STDCALL AbortPrinter (LONGINT hPrinter);
__EXTERN INTEGER __STDCALL AbortSystemShutdownA (LONGINT lpMachineName);
__EXTERN INTEGER __STDCALL AbortSystemShutdownW (LONGINT lpMachineName);
__EXTERN INTEGER __STDCALL AccessCheck (LONGINT pSecurityDescriptor, LONGINT ClientToken, SET DesiredAccess, WinAPI_GENERIC_MAPPING *GenericMapping, WinAPI_PRIVILEGE_SET *PrivilegeSet, INTEGER *PrivilegeSetLength, INTEGER *GrantedAccess, INTEGER *AccessStatus);
__EXTERN INTEGER __STDCALL AccessCheckAndAuditAlarmA (LONGINT SubsystemName, LONGINT HandleId, LONGINT ObjectTypeName, LONGINT ObjectName, LONGINT SecurityDescriptor, SET DesiredAccess, WinAPI_GENERIC_MAPPING *GenericMapping, INTEGER ObjectCreation, INTEGER *GrantedAccess, INTEGER *AccessStatus, INTEGER *pfGenerateOnClose);
__EXTERN INTEGER __STDCALL AccessCheckAndAuditAlarmW (LONGINT SubsystemName, LONGINT HandleId, LONGINT ObjectTypeName, LONGINT ObjectName, LONGINT SecurityDescriptor, SET DesiredAccess, WinAPI_GENERIC_MAPPING *GenericMapping, INTEGER ObjectCreation, INTEGER *GrantedAccess, INTEGER *AccessStatus, INTEGER *pfGenerateOnClose);
__EXTERN LONGINT __STDCALL ActivateKeyboardLayout (LONGINT hkl, SET Flags);
__EXTERN INTEGER __STDCALL AddAccessAllowedAce (WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER AccessMask, LONGINT pSid);
__EXTERN INTEGER __STDCALL AddAccessDeniedAce (WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER AccessMask, LONGINT pSid);
__EXTERN INTEGER __STDCALL AddAce (WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER dwStartingAceIndex, LONGINT pAceList, INTEGER nAceListLength);
__EXTERN SHORTINT __STDCALL AddAtomA (LONGINT lpString);
__EXTERN SHORTINT __STDCALL AddAtomW (LONGINT lpString);
__EXTERN INTEGER __STDCALL AddAuditAccessAce (WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER dwAccessMask, LONGINT pSid, INTEGER bAuditSuccess, INTEGER bAuditFailure);
__EXTERN INTEGER __STDCALL AddFontResourceA (LONGINT p0);
__EXTERN INTEGER __STDCALL AddFontResourceW (LONGINT p0);
__EXTERN INTEGER __STDCALL AddFormA (LONGINT hPrinter, INTEGER Level, CHAR *pForm);
__EXTERN INTEGER __STDCALL AddFormW (LONGINT hPrinter, INTEGER Level, CHAR *pForm);
__EXTERN INTEGER __STDCALL AddJobA (LONGINT hPrinter, INTEGER Level, CHAR *pData, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL AddJobW (LONGINT hPrinter, INTEGER Level, CHAR *pData, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL AddMonitorA (LONGINT pName, INTEGER Level, CHAR *pMonitors);
__EXTERN INTEGER __STDCALL AddMonitorW (LONGINT pName, INTEGER Level, CHAR *pMonitors);
__EXTERN INTEGER __STDCALL AddPortA (LONGINT pName, LONGINT hWnd, LONGINT pMonitorName);
__EXTERN INTEGER __STDCALL AddPortW (LONGINT pName, LONGINT hWnd, LONGINT pMonitorName);
__EXTERN INTEGER __STDCALL AddPrintProcessorA (LONGINT pName, LONGINT pEnvironment, LONGINT pPathName, LONGINT pPrintProcessorName);
__EXTERN INTEGER __STDCALL AddPrintProcessorW (LONGINT pName, LONGINT pEnvironment, LONGINT pPathName, LONGINT pPrintProcessorName);
__EXTERN INTEGER __STDCALL AddPrintProvidorA (LONGINT pName, INTEGER level, CHAR *pProvidorInfo);
__EXTERN INTEGER __STDCALL AddPrintProvidorW (LONGINT pName, INTEGER level, CHAR *pProvidorInfo);
__EXTERN LONGINT __STDCALL AddPrinterA (LONGINT pName, INTEGER Level, CHAR *pPrinter);
__EXTERN INTEGER __STDCALL AddPrinterConnectionA (LONGINT pName);
__EXTERN INTEGER __STDCALL AddPrinterConnectionW (LONGINT pName);
__EXTERN INTEGER __STDCALL AddPrinterDriverA (LONGINT pName, INTEGER Level, CHAR *pDriverInfo);
__EXTERN INTEGER __STDCALL AddPrinterDriverW (LONGINT pName, INTEGER Level, CHAR *pDriverInfo);
__EXTERN LONGINT __STDCALL AddPrinterW (LONGINT pName, INTEGER Level, CHAR *pPrinter);
__EXTERN INTEGER __STDCALL AdjustTokenGroups (LONGINT TokenHandle, INTEGER ResetToDefault, WinAPI_TOKEN_GROUPS *NewState, INTEGER BufferLength, WinAPI_TOKEN_GROUPS *PreviousState, INTEGER *ReturnLength);
__EXTERN INTEGER __STDCALL AdjustTokenPrivileges (LONGINT TokenHandle, INTEGER DisableAllPrivileges, WinAPI_TOKEN_PRIVILEGES *NewState, INTEGER BufferLength, WinAPI_TOKEN_PRIVILEGES *PreviousState, INTEGER *ReturnLength);
__EXTERN INTEGER __STDCALL AdjustWindowRect (WinAPI_RECT *lpRect, SET dwStyle, INTEGER bMenu);
__EXTERN INTEGER __STDCALL AdjustWindowRectEx (WinAPI_RECT *lpRect, SET dwStyle, INTEGER bMenu, SET dwExStyle);
__EXTERN INTEGER __STDCALL AdvancedDocumentPropertiesA (LONGINT hWnd, LONGINT hPrinter, LONGINT pDeviceName, WinAPI_DEVMODEA *pDevModeOutput, WinAPI_DEVMODEA *pDevModeInput);
__EXTERN INTEGER __STDCALL AdvancedDocumentPropertiesW (LONGINT hWnd, LONGINT hPrinter, LONGINT pDeviceName, WinAPI_DEVMODEW *pDevModeOutput, WinAPI_DEVMODEW *pDevModeInput);
__EXTERN INTEGER __STDCALL AllocConsole (void);
__EXTERN INTEGER __STDCALL AllocateAndInitializeSid (WinAPI_SID_IDENTIFIER_AUTHORITY *pIdentifierAuthority, CHAR nSubAuthorityCount, INTEGER nSubAuthority0, INTEGER nSubAuthority1, INTEGER nSubAuthority2, INTEGER nSubAuthority3, INTEGER nSubAuthority4, INTEGER nSubAuthority5, INTEGER nSubAuthority6, INTEGER nSubAuthority7, LONGINT *pSid);
__EXTERN INTEGER __STDCALL AllocateLocallyUniqueId (LONGINT *Luid);
__EXTERN INTEGER __STDCALL AngleArc (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, SHORTREAL p4, SHORTREAL p5);
__EXTERN INTEGER __STDCALL AnimatePalette (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
__EXTERN INTEGER __STDCALL AnyPopup (void);
__EXTERN INTEGER __STDCALL AppendMenuA (LONGINT hMenu, SET uFlags, INTEGER uIDNewItem, LONGINT lpNewItem);
__EXTERN INTEGER __STDCALL AppendMenuW (LONGINT hMenu, SET uFlags, INTEGER uIDNewItem, LONGINT lpNewItem);
__EXTERN INTEGER __STDCALL Arc (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
__EXTERN INTEGER __STDCALL ArcTo (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
__EXTERN INTEGER __STDCALL AreAllAccessesGranted (INTEGER GrantedAccess, SET DesiredAccess);
__EXTERN INTEGER __STDCALL AreAnyAccessesGranted (INTEGER GrantedAccess, SET DesiredAccess);
__EXTERN INTEGER __STDCALL AreFileApisANSI (void);
__EXTERN INTEGER __STDCALL ArrangeIconicWindows (LONGINT hWnd);
__EXTERN INTEGER __STDCALL AttachThreadInput (INTEGER idAttach, INTEGER idAttachTo, INTEGER fAttach);
__EXTERN INTEGER __STDCALL BackupEventLogA (LONGINT hEventLog, LONGINT lpBackupFileName);
__EXTERN INTEGER __STDCALL BackupEventLogW (LONGINT hEventLog, LONGINT lpBackupFileName);
__EXTERN INTEGER __STDCALL BackupRead (LONGINT hFile, CHAR *lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *lpNumberOfBytesRead, INTEGER bAbort, INTEGER bProcessSecurity, LONGINT lpContext);
__EXTERN INTEGER __STDCALL BackupSeek (LONGINT hFile, INTEGER dwLowBytesToSeek, INTEGER dwHighBytesToSeek, INTEGER *lpdwLowByteSeeked, INTEGER *lpdwHighByteSeeked, LONGINT lpContext);
__EXTERN INTEGER __STDCALL BackupWrite (LONGINT hFile, CHAR *lpBuffer, INTEGER nNumberOfBytesToWrite, INTEGER *lpNumberOfBytesWritten, INTEGER bAbort, INTEGER bProcessSecurity, LONGINT lpContext);
__EXTERN INTEGER __STDCALL Beep (INTEGER dwFreq, INTEGER dwDuration);
__EXTERN LONGINT __STDCALL BeginDeferWindowPos (INTEGER nNumWindows);
__EXTERN LONGINT __STDCALL BeginPaint (LONGINT hWnd, WinAPI_PAINTSTRUCT *lpPaint);
__EXTERN INTEGER __STDCALL BeginPath (LONGINT p0);
__EXTERN LONGINT __STDCALL BeginUpdateResourceA (LONGINT pFileName, INTEGER bDeleteExistingResources);
__EXTERN LONGINT __STDCALL BeginUpdateResourceW (LONGINT pFileName, INTEGER bDeleteExistingResources);
__EXTERN INTEGER __STDCALL BitBlt (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, LONGINT p5, INTEGER p6, INTEGER p7, INTEGER p8);
__EXTERN INTEGER __STDCALL BringWindowToTop (LONGINT hWnd);
__EXTERN INTEGER __STDCALL BroadcastSystemMessageA (SET p0, SET *p1, INTEGER p2, LONGINT p3, LONGINT p4);
__EXTERN INTEGER __STDCALL BroadcastSystemMessageW (SET p0, SET *p1, INTEGER p2, LONGINT p3, LONGINT p4);
__EXTERN INTEGER __STDCALL BuildCommDCBA (LONGINT lpDef, WinAPI_DCB *lpDCB);
__EXTERN INTEGER __STDCALL BuildCommDCBAndTimeoutsA (LONGINT lpDef, WinAPI_DCB *lpDCB, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
__EXTERN INTEGER __STDCALL BuildCommDCBAndTimeoutsW (LONGINT lpDef, WinAPI_DCB *lpDCB, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
__EXTERN INTEGER __STDCALL BuildCommDCBW (LONGINT lpDef, WinAPI_DCB *lpDCB);
__EXTERN INTEGER __STDCALL CallMsgFilterA (WinAPI_MSG *lpMsg, INTEGER nCode);
__EXTERN INTEGER __STDCALL CallMsgFilterW (WinAPI_MSG *lpMsg, INTEGER nCode);
__EXTERN INTEGER __STDCALL CallNamedPipeA (LONGINT lpNamedPipeName, LONGINT lpInBuffer, INTEGER nInBufferSize, LONGINT lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, INTEGER nTimeOut);
__EXTERN INTEGER __STDCALL CallNamedPipeW (LONGINT lpNamedPipeName, LONGINT lpInBuffer, INTEGER nInBufferSize, LONGINT lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, INTEGER nTimeOut);
__EXTERN LONGINT __STDCALL CallNextHookEx (LONGINT hhk, INTEGER nCode, LONGINT wParam, LONGINT lParam);
__EXTERN LONGINT __STDCALL CallWindowProcA (WinAPI_FARPROC lpPrevWndFunc, LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN LONGINT __STDCALL CallWindowProcW (WinAPI_FARPROC lpPrevWndFunc, LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN INTEGER __STDCALL CancelDC (LONGINT p0);
__EXTERN INTEGER __STDCALL CancelWaitableTimer (LONGINT hTimer);
__EXTERN SHORTINT __STDCALL CascadeWindows (LONGINT hwndParent, INTEGER wHow, WinAPI_RECT *lpRect, INTEGER cKids, LONGINT *lpKids);
__EXTERN INTEGER __STDCALL ChangeClipboardChain (LONGINT hWndRemove, LONGINT hWndNewNext);
__EXTERN INTEGER __STDCALL ChangeDisplaySettingsA (WinAPI_DEVMODEA *lpDevMode, SET dwFlags);
__EXTERN INTEGER __STDCALL ChangeDisplaySettingsW (WinAPI_DEVMODEW *lpDevMode, SET dwFlags);
__EXTERN INTEGER __STDCALL ChangeMenuA (LONGINT hMenu, INTEGER cmd, LONGINT lpszNewItem, INTEGER cmdInsert, SET flags);
__EXTERN INTEGER __STDCALL ChangeMenuW (LONGINT hMenu, INTEGER cmd, LONGINT lpszNewItem, INTEGER cmdInsert, SET flags);
__EXTERN INTEGER __STDCALL ChangeServiceConfigA (LONGINT hService, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, LONGINT lpBinaryPathName, LONGINT lpLoadOrderGroup, INTEGER *lpdwTagId, LONGINT lpDependencies, LONGINT lpServiceStartName, LONGINT lpPassword, LONGINT lpDisplayName);
__EXTERN INTEGER __STDCALL ChangeServiceConfigW (LONGINT hService, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, LONGINT lpBinaryPathName, LONGINT lpLoadOrderGroup, INTEGER *lpdwTagId, LONGINT lpDependencies, LONGINT lpServiceStartName, LONGINT lpPassword, LONGINT lpDisplayName);
__EXTERN LONGINT __STDCALL CharLowerA (LONGINT lpsz);
__EXTERN INTEGER __STDCALL CharLowerBuffA (LONGINT lpsz, INTEGER cchLength);
__EXTERN INTEGER __STDCALL CharLowerBuffW (LONGINT lpsz, INTEGER cchLength);
__EXTERN LONGINT __STDCALL CharLowerW (LONGINT lpsz);
__EXTERN LONGINT __STDCALL CharNextA (LONGINT lpsz);
__EXTERN LONGINT __STDCALL CharNextExA (SHORTINT CodePage, LONGINT lpCurrentChar, SET dwFlags);
__EXTERN LONGINT __STDCALL CharNextW (LONGINT lpsz);
__EXTERN LONGINT __STDCALL CharPrevA (LONGINT lpszStart, LONGINT lpszCurrent);
__EXTERN LONGINT __STDCALL CharPrevExA (SHORTINT CodePage, LONGINT lpStart, LONGINT lpCurrentChar, SET dwFlags);
__EXTERN LONGINT __STDCALL CharPrevW (LONGINT lpszStart, LONGINT lpszCurrent);
__EXTERN INTEGER __STDCALL CharToOemA (LONGINT lpszSrc, LONGINT lpszDst);
__EXTERN INTEGER __STDCALL CharToOemBuffA (LONGINT lpszSrc, LONGINT lpszDst, INTEGER cchDstLength);
__EXTERN INTEGER __STDCALL CharToOemBuffW (LONGINT lpszSrc, LONGINT lpszDst, INTEGER cchDstLength);
__EXTERN INTEGER __STDCALL CharToOemW (LONGINT lpszSrc, LONGINT lpszDst);
__EXTERN LONGINT __STDCALL CharUpperA (LONGINT lpsz);
__EXTERN INTEGER __STDCALL CharUpperBuffA (LONGINT lpsz, INTEGER cchLength);
__EXTERN INTEGER __STDCALL CharUpperBuffW (LONGINT lpsz, INTEGER cchLength);
__EXTERN LONGINT __STDCALL CharUpperW (LONGINT lpsz);
__EXTERN INTEGER __STDCALL CheckColorsInGamut (LONGINT p0, LONGINT p1, LONGINT p2, INTEGER p3);
__EXTERN INTEGER __STDCALL CheckDlgButton (LONGINT hDlg, INTEGER nIDButton, SET uCheck);
__EXTERN INTEGER __STDCALL CheckMenuItem (LONGINT hMenu, INTEGER uIDCheckItem, SET uCheck);
__EXTERN INTEGER __STDCALL CheckMenuRadioItem (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL CheckRadioButton (LONGINT hDlg, INTEGER nIDFirstButton, INTEGER nIDLastButton, INTEGER nIDCheckButton);
__EXTERN LONGINT __STDCALL ChildWindowFromPoint (LONGINT hWndParent, WinAPI_POINT *Point);
__EXTERN LONGINT __STDCALL ChildWindowFromPointEx (LONGINT p0, WinAPI_POINT *p1, SET p2);
__EXTERN INTEGER __STDCALL ChoosePixelFormat (LONGINT p0, WinAPI_PIXELFORMATDESCRIPTOR *p1);
__EXTERN INTEGER __STDCALL Chord (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
__EXTERN INTEGER __STDCALL ClearCommBreak (LONGINT hFile);
__EXTERN INTEGER __STDCALL ClearCommError (LONGINT hFile, SET *lpErrors, WinAPI_COMSTAT *lpStat);
__EXTERN INTEGER __STDCALL ClearEventLogA (LONGINT hEventLog, LONGINT lpBackupFileName);
__EXTERN INTEGER __STDCALL ClearEventLogW (LONGINT hEventLog, LONGINT lpBackupFileName);
__EXTERN INTEGER __STDCALL ClientToScreen (LONGINT hWnd, WinAPI_POINT *lpPoint);
__EXTERN INTEGER __STDCALL ClipCursor (WinAPI_RECT *lpRect);
__EXTERN INTEGER __STDCALL CloseClipboard (void);
__EXTERN INTEGER __STDCALL CloseDesktop (LONGINT hDesktop);
__EXTERN LONGINT __STDCALL CloseEnhMetaFile (LONGINT p0);
__EXTERN INTEGER __STDCALL CloseEventLog (LONGINT hEventLog);
__EXTERN INTEGER __STDCALL CloseFigure (LONGINT p0);
__EXTERN INTEGER __STDCALL CloseHandle (LONGINT hObject);
__EXTERN LONGINT __STDCALL CloseMetaFile (LONGINT p0);
__EXTERN INTEGER __STDCALL ClosePrinter (LONGINT hPrinter);
__EXTERN INTEGER __STDCALL CloseServiceHandle (LONGINT hSCObject);
__EXTERN INTEGER __STDCALL CloseWindow (LONGINT hWnd);
__EXTERN INTEGER __STDCALL CloseWindowStation (LONGINT hWinSta);
__EXTERN INTEGER __STDCALL ColorMatchToTarget (LONGINT p0, LONGINT p1, INTEGER p2);
__EXTERN INTEGER __STDCALL CombineRgn (LONGINT p0, LONGINT p1, LONGINT p2, INTEGER p3);
__EXTERN INTEGER __STDCALL CombineTransform (WinAPI_XFORM *p0, WinAPI_XFORM *p1, WinAPI_XFORM *p2);
__EXTERN INTEGER __STDCALL CommConfigDialogA (LONGINT lpszName, LONGINT hWnd, WinAPI_COMMCONFIG *lpCC);
__EXTERN INTEGER __STDCALL CommConfigDialogW (LONGINT lpszName, LONGINT hWnd, WinAPI_COMMCONFIG *lpCC);
__EXTERN LONGINT __STDCALL CommandLineToArgvW (LONGINT lpCmdLine, INTEGER *pNumArgs);
__EXTERN INTEGER __STDCALL CompareFileTime (WinAPI_FILETIME *lpFileTime1, WinAPI_FILETIME *lpFileTime2);
__EXTERN INTEGER __STDCALL CompareStringA (INTEGER Locale, SET dwCmpFlags, LONGINT lpString1, INTEGER cchCount1, LONGINT lpString2, INTEGER cchCount2);
__EXTERN INTEGER __STDCALL CompareStringW (INTEGER Locale, SET dwCmpFlags, LONGINT lpString1, INTEGER cchCount1, LONGINT lpString2, INTEGER cchCount2);
__EXTERN INTEGER __STDCALL ConfigurePortA (LONGINT pName, LONGINT hWnd, LONGINT pPortName);
__EXTERN INTEGER __STDCALL ConfigurePortW (LONGINT pName, LONGINT hWnd, LONGINT pPortName);
__EXTERN INTEGER __STDCALL ConnectNamedPipe (LONGINT hNamedPipe, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN LONGINT __STDCALL ConnectToPrinterDlg (LONGINT hwnd, SET Flags);
__EXTERN INTEGER __STDCALL ContinueDebugEvent (INTEGER dwProcessId, INTEGER dwThreadId, SET dwContinueStatus);
__EXTERN INTEGER __STDCALL ControlService (LONGINT hService, INTEGER dwControl, WinAPI_SERVICE_STATUS *lpServiceStatus);
__EXTERN INTEGER __STDCALL ConvertDefaultLocale (INTEGER Locale);
__EXTERN LONGINT __STDCALL ConvertThreadToFiber (LONGINT lpParameter);
__EXTERN INTEGER __STDCALL CopyAcceleratorTableA (LONGINT hAccelSrc, WinAPI_ACCEL *lpAccelDst, INTEGER cAccelEntries);
__EXTERN INTEGER __STDCALL CopyAcceleratorTableW (LONGINT hAccelSrc, WinAPI_ACCEL *lpAccelDst, INTEGER cAccelEntries);
__EXTERN LONGINT __STDCALL CopyEnhMetaFileA (LONGINT p0, LONGINT p1);
__EXTERN LONGINT __STDCALL CopyEnhMetaFileW (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL CopyFileA (LONGINT lpExistingFileName, LONGINT lpNewFileName, INTEGER bFailIfExists);
__EXTERN INTEGER __STDCALL CopyFileExA (LONGINT lpExistingFileName, LONGINT lpNewFileName, WinAPI_PROGRESS_ROUTINE lpProgressRoutine, LONGINT lpData, INTEGER *pbCancel, INTEGER dwCopyFlags);
__EXTERN INTEGER __STDCALL CopyFileExW (LONGINT lpExistingFileName, LONGINT lpNewFileName, WinAPI_PROGRESS_ROUTINE lpProgressRoutine, LONGINT lpData, INTEGER *pbCancel, INTEGER dwCopyFlags);
__EXTERN INTEGER __STDCALL CopyFileW (LONGINT lpExistingFileName, LONGINT lpNewFileName, INTEGER bFailIfExists);
__EXTERN LONGINT __STDCALL CopyIcon (LONGINT hIcon);
__EXTERN LONGINT __STDCALL CopyImage (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL CopyLZFile (INTEGER p0, INTEGER p1);
__EXTERN LONGINT __STDCALL CopyMetaFileA (LONGINT p0, LONGINT p1);
__EXTERN LONGINT __STDCALL CopyMetaFileW (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL CopyRect (WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc);
__EXTERN INTEGER __STDCALL CopySid (INTEGER nDestinationSidLength, LONGINT pDestinationSid, LONGINT pSourceSid);
__EXTERN INTEGER __STDCALL CountClipboardFormats (void);
__EXTERN LONGINT __STDCALL CreateAcceleratorTableA (WinAPI_ACCEL *p0, INTEGER p1);
__EXTERN LONGINT __STDCALL CreateAcceleratorTableW (WinAPI_ACCEL *p0, INTEGER p1);
__EXTERN LONGINT __STDCALL CreateBitmap (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, LONGINT p4);
__EXTERN LONGINT __STDCALL CreateBitmapIndirect (WinAPI_BITMAP *p0);
__EXTERN LONGINT __STDCALL CreateBrushIndirect (WinAPI_LOGBRUSH *p0);
__EXTERN INTEGER __STDCALL CreateCaret (LONGINT hWnd, LONGINT hBitmap, INTEGER nWidth, INTEGER nHeight);
__EXTERN LONGINT __STDCALL CreateColorSpaceA (WinAPI_LOGCOLORSPACEA *p0);
__EXTERN LONGINT __STDCALL CreateColorSpaceW (WinAPI_LOGCOLORSPACEW *p0);
__EXTERN LONGINT __STDCALL CreateCompatibleBitmap (LONGINT p0, INTEGER p1, INTEGER p2);
__EXTERN LONGINT __STDCALL CreateCompatibleDC (LONGINT p0);
__EXTERN LONGINT __STDCALL CreateConsoleScreenBuffer (SET dwDesiredAccess, SET dwShareMode, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, SET dwFlags, LONGINT lpScreenBufferData);
__EXTERN LONGINT __STDCALL CreateCursor (LONGINT hInst, INTEGER xHotSpot, INTEGER yHotSpot, INTEGER nWidth, INTEGER nHeight, LONGINT pvANDPlane, LONGINT pvXORPlane);
__EXTERN LONGINT __STDCALL CreateDCA (LONGINT p0, LONGINT p1, LONGINT p2, WinAPI_DEVMODEA *p3);
__EXTERN LONGINT __STDCALL CreateDCW (LONGINT p0, LONGINT p1, LONGINT p2, WinAPI_DEVMODEW *p3);
__EXTERN LONGINT __STDCALL CreateDIBPatternBrush (LONGINT p0, INTEGER p1);
__EXTERN LONGINT __STDCALL CreateDIBPatternBrushPt (LONGINT p0, INTEGER p1);
__EXTERN LONGINT __STDCALL CreateDIBSection (LONGINT p0, WinAPI_BITMAPINFO *p1, INTEGER p2, LONGINT *p3, LONGINT p4, INTEGER p5);
__EXTERN LONGINT __STDCALL CreateDIBitmap (LONGINT p0, WinAPI_BITMAPINFOHEADER *p1, INTEGER p2, LONGINT p3, WinAPI_BITMAPINFO *p4, INTEGER p5);
__EXTERN LONGINT __STDCALL CreateDesktopA (LONGINT lpszDesktop, LONGINT lpszDevice, WinAPI_DEVMODEA *pDevmode, SET dwFlags, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
__EXTERN LONGINT __STDCALL CreateDesktopW (LONGINT lpszDesktop, LONGINT lpszDevice, WinAPI_DEVMODEW *pDevmode, SET dwFlags, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
__EXTERN LONGINT __STDCALL CreateDialogIndirectParamA (LONGINT hInstance, WinAPI_DLGTEMPLATE *lpTemplate, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
__EXTERN LONGINT __STDCALL CreateDialogIndirectParamW (LONGINT hInstance, WinAPI_DLGTEMPLATE *lpTemplate, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
__EXTERN LONGINT __STDCALL CreateDialogParamA (LONGINT hInstance, LONGINT lpTemplateName, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
__EXTERN LONGINT __STDCALL CreateDialogParamW (LONGINT hInstance, LONGINT lpTemplateName, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
__EXTERN INTEGER __STDCALL CreateDirectoryA (LONGINT lpPathName, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL CreateDirectoryExA (LONGINT lpTemplateDirectory, LONGINT lpNewDirectory, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL CreateDirectoryExW (LONGINT lpTemplateDirectory, LONGINT lpNewDirectory, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL CreateDirectoryW (LONGINT lpPathName, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN LONGINT __STDCALL CreateDiscardableBitmap (LONGINT p0, INTEGER p1, INTEGER p2);
__EXTERN LONGINT __STDCALL CreateEllipticRgn (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN LONGINT __STDCALL CreateEllipticRgnIndirect (WinAPI_RECT *p0);
__EXTERN LONGINT __STDCALL CreateEnhMetaFileA (LONGINT p0, LONGINT p1, WinAPI_RECT *p2, LONGINT p3);
__EXTERN LONGINT __STDCALL CreateEnhMetaFileW (LONGINT p0, LONGINT p1, WinAPI_RECT *p2, LONGINT p3);
__EXTERN LONGINT __STDCALL CreateEventA (WinAPI_SECURITY_ATTRIBUTES *lpEventAttributes, INTEGER bManualReset, INTEGER bInitialState, LONGINT lpName);
__EXTERN LONGINT __STDCALL CreateEventW (WinAPI_SECURITY_ATTRIBUTES *lpEventAttributes, INTEGER bManualReset, INTEGER bInitialState, LONGINT lpName);
__EXTERN LONGINT __STDCALL CreateFiber (INTEGER dwStackSize, WinAPI_FIBER_START_ROUTINE lpStartAddress, LONGINT lpParameter);
__EXTERN LONGINT __STDCALL CreateFileA (LONGINT lpFileName, SET dwDesiredAccess, SET dwShareMode, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER dwCreationDisposition, SET dwFlagsAndAttributes, LONGINT hTemplateFile);
__EXTERN LONGINT __STDCALL CreateFileMappingA (LONGINT hFile, WinAPI_SECURITY_ATTRIBUTES *lpFileMappingAttributes, SET flProtect, INTEGER dwMaximumSizeHigh, INTEGER dwMaximumSizeLow, LONGINT lpName);
__EXTERN LONGINT __STDCALL CreateFileMappingW (LONGINT hFile, WinAPI_SECURITY_ATTRIBUTES *lpFileMappingAttributes, SET flProtect, INTEGER dwMaximumSizeHigh, INTEGER dwMaximumSizeLow, LONGINT lpName);
__EXTERN LONGINT __STDCALL CreateFileW (LONGINT lpFileName, SET dwDesiredAccess, SET dwShareMode, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER dwCreationDisposition, SET dwFlagsAndAttributes, LONGINT hTemplateFile);
__EXTERN LONGINT __STDCALL CreateFontA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10, INTEGER p11, INTEGER p12, LONGINT p13);
__EXTERN LONGINT __STDCALL CreateFontIndirectA (WinAPI_LOGFONTA *p0);
__EXTERN LONGINT __STDCALL CreateFontIndirectW (WinAPI_LOGFONTW *p0);
__EXTERN LONGINT __STDCALL CreateFontW (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10, INTEGER p11, INTEGER p12, LONGINT p13);
__EXTERN LONGINT __STDCALL CreateHalftonePalette (LONGINT p0);
__EXTERN LONGINT __STDCALL CreateHatchBrush (INTEGER p0, INTEGER p1);
__EXTERN LONGINT __STDCALL CreateICA (LONGINT p0, LONGINT p1, LONGINT p2, WinAPI_DEVMODEA *p3);
__EXTERN LONGINT __STDCALL CreateICW (LONGINT p0, LONGINT p1, LONGINT p2, WinAPI_DEVMODEW *p3);
__EXTERN LONGINT __STDCALL CreateIcon (LONGINT hInstance, INTEGER nWidth, INTEGER nHeight, CHAR cPlanes, CHAR cBitsPixel, CHAR *lpbANDbits, CHAR *lpbXORbits);
__EXTERN LONGINT __STDCALL CreateIconFromResource (CHAR *presbits, INTEGER dwResSize, INTEGER fIcon, INTEGER dwVer);
__EXTERN LONGINT __STDCALL CreateIconFromResourceEx (CHAR *presbits, INTEGER dwResSize, INTEGER fIcon, INTEGER dwVer, INTEGER cxDesired, INTEGER cyDesired, SET Flags);
__EXTERN LONGINT __STDCALL CreateIconIndirect (WinAPI_ICONINFO *piconinfo);
__EXTERN LONGINT __STDCALL CreateIoCompletionPort (LONGINT FileHandle, LONGINT ExistingCompletionPort, INTEGER CompletionKey, INTEGER NumberOfConcurrentThreads);
__EXTERN LONGINT __STDCALL CreateMDIWindowA (LONGINT lpClassName, LONGINT lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, LONGINT hWndParent, LONGINT hInstance, LONGINT lParam);
__EXTERN LONGINT __STDCALL CreateMDIWindowW (LONGINT lpClassName, LONGINT lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, LONGINT hWndParent, LONGINT hInstance, LONGINT lParam);
__EXTERN LONGINT __STDCALL CreateMailslotA (LONGINT lpName, INTEGER nMaxMessageSize, INTEGER lReadTimeout, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN LONGINT __STDCALL CreateMailslotW (LONGINT lpName, INTEGER nMaxMessageSize, INTEGER lReadTimeout, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN LONGINT __STDCALL CreateMenu (void);
__EXTERN LONGINT __STDCALL CreateMetaFileA (LONGINT p0);
__EXTERN LONGINT __STDCALL CreateMetaFileW (LONGINT p0);
__EXTERN LONGINT __STDCALL CreateMutexA (WinAPI_SECURITY_ATTRIBUTES *lpMutexAttributes, INTEGER bInitialOwner, LONGINT lpName);
__EXTERN LONGINT __STDCALL CreateMutexW (WinAPI_SECURITY_ATTRIBUTES *lpMutexAttributes, INTEGER bInitialOwner, LONGINT lpName);
__EXTERN LONGINT __STDCALL CreateNamedPipeA (LONGINT lpName, INTEGER dwOpenMode, INTEGER dwPipeMode, INTEGER nMaxInstances, INTEGER nOutBufferSize, INTEGER nInBufferSize, INTEGER nDefaultTimeOut, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN LONGINT __STDCALL CreateNamedPipeW (LONGINT lpName, INTEGER dwOpenMode, INTEGER dwPipeMode, INTEGER nMaxInstances, INTEGER nOutBufferSize, INTEGER nInBufferSize, INTEGER nDefaultTimeOut, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN LONGINT __STDCALL CreatePalette (WinAPI_LOGPALETTE *p0);
__EXTERN LONGINT __STDCALL CreatePatternBrush (LONGINT p0);
__EXTERN LONGINT __STDCALL CreatePen (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN LONGINT __STDCALL CreatePenIndirect (WinAPI_LOGPEN *p0);
__EXTERN INTEGER __STDCALL CreatePipe (LONGINT *hReadPipe, LONGINT *hWritePipe, WinAPI_SECURITY_ATTRIBUTES *lpPipeAttributes, INTEGER nSize);
__EXTERN LONGINT __STDCALL CreatePolyPolygonRgn (WinAPI_POINT *p0, INTEGER *p1, INTEGER p2, INTEGER p3);
__EXTERN LONGINT __STDCALL CreatePolygonRgn (WinAPI_POINT *p0, INTEGER p1, INTEGER p2);
__EXTERN LONGINT __STDCALL CreatePopupMenu (void);
__EXTERN INTEGER __STDCALL CreatePrivateObjectSecurity (LONGINT ParentDescriptor, LONGINT CreatorDescriptor, LONGINT *NewDescriptor, INTEGER IsDirectoryObject, LONGINT Token, WinAPI_GENERIC_MAPPING *GenericMapping);
__EXTERN INTEGER __STDCALL CreateProcessA (LONGINT lpApplicationName, LONGINT lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, LONGINT lpEnvironment, LONGINT lpCurrentDirectory, WinAPI_STARTUPINFOA *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
__EXTERN INTEGER __STDCALL CreateProcessAsUserA (LONGINT hToken, LONGINT lpApplicationName, LONGINT lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, LONGINT lpEnvironment, LONGINT lpCurrentDirectory, WinAPI_STARTUPINFOA *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
__EXTERN INTEGER __STDCALL CreateProcessAsUserW (LONGINT hToken, LONGINT lpApplicationName, LONGINT lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, LONGINT lpEnvironment, LONGINT lpCurrentDirectory, WinAPI_STARTUPINFOW *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
__EXTERN INTEGER __STDCALL CreateProcessW (LONGINT lpApplicationName, LONGINT lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, LONGINT lpEnvironment, LONGINT lpCurrentDirectory, WinAPI_STARTUPINFOW *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
__EXTERN WinAPI_Ptr_PSP __STDCALL CreatePropertySheetPageA (WinAPI_PROPSHEETPAGEA *p0);
__EXTERN WinAPI_Ptr_PSP __STDCALL CreatePropertySheetPageW (WinAPI_PROPSHEETPAGEW *p0);
__EXTERN LONGINT __STDCALL CreateRectRgn (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN LONGINT __STDCALL CreateRectRgnIndirect (WinAPI_RECT *p0);
__EXTERN LONGINT __STDCALL CreateRemoteThread (LONGINT hProcess, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER dwStackSize, WinAPI_THREAD_START_ROUTINE lpStartAddress, LONGINT lpParameter, SET dwCreationFlags, INTEGER *lpThreadId);
__EXTERN LONGINT __STDCALL CreateRoundRectRgn (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
__EXTERN INTEGER __STDCALL CreateScalableFontResourceA (INTEGER p0, LONGINT p1, LONGINT p2, LONGINT p3);
__EXTERN INTEGER __STDCALL CreateScalableFontResourceW (INTEGER p0, LONGINT p1, LONGINT p2, LONGINT p3);
__EXTERN LONGINT __STDCALL CreateSemaphoreA (WinAPI_SECURITY_ATTRIBUTES *lpSemaphoreAttributes, INTEGER lInitialCount, INTEGER lMaximumCount, LONGINT lpName);
__EXTERN LONGINT __STDCALL CreateSemaphoreW (WinAPI_SECURITY_ATTRIBUTES *lpSemaphoreAttributes, INTEGER lInitialCount, INTEGER lMaximumCount, LONGINT lpName);
__EXTERN LONGINT __STDCALL CreateServiceA (LONGINT hSCManager, LONGINT lpServiceName, LONGINT lpDisplayName, SET dwDesiredAccess, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, LONGINT lpBinaryPathName, LONGINT lpLoadOrderGroup, INTEGER *lpdwTagId, LONGINT lpDependencies, LONGINT lpServiceStartName, LONGINT lpPassword);
__EXTERN LONGINT __STDCALL CreateServiceW (LONGINT hSCManager, LONGINT lpServiceName, LONGINT lpDisplayName, SET dwDesiredAccess, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, LONGINT lpBinaryPathName, LONGINT lpLoadOrderGroup, INTEGER *lpdwTagId, LONGINT lpDependencies, LONGINT lpServiceStartName, LONGINT lpPassword);
__EXTERN LONGINT __STDCALL CreateSolidBrush (INTEGER p0);
__EXTERN INTEGER __STDCALL CreateTapePartition (LONGINT hDevice, INTEGER dwPartitionMethod, INTEGER dwCount, INTEGER dwSize);
__EXTERN LONGINT __STDCALL CreateThread (WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER dwStackSize, WinAPI_THREAD_START_ROUTINE lpStartAddress, LONGINT lpParameter, SET dwCreationFlags, INTEGER *lpThreadId);
__EXTERN LONGINT __STDCALL CreateWaitableTimerA (WinAPI_SECURITY_ATTRIBUTES *lpTimerAttributes, INTEGER bManualReset, LONGINT lpTimerName);
__EXTERN LONGINT __STDCALL CreateWaitableTimerW (WinAPI_SECURITY_ATTRIBUTES *lpTimerAttributes, INTEGER bManualReset, LONGINT lpTimerName);
__EXTERN LONGINT __STDCALL CreateWindowExA (SET dwExStyle, LONGINT lpClassName, LONGINT lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, LONGINT hWndParent, LONGINT hMenu, LONGINT hInstance, LONGINT lpParam);
__EXTERN LONGINT __STDCALL CreateWindowExW (SET dwExStyle, LONGINT lpClassName, LONGINT lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, LONGINT hWndParent, LONGINT hMenu, LONGINT hInstance, LONGINT lpParam);
__EXTERN LONGINT __STDCALL CreateWindowStationA (LONGINT lpwinsta, INTEGER dwReserved, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
__EXTERN LONGINT __STDCALL CreateWindowStationW (LONGINT lpwinsta, INTEGER dwReserved, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
__EXTERN INTEGER __STDCALL DPtoLP (LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL DdeAbandonTransaction (INTEGER idInst, LONGINT hConv, INTEGER idTransaction);
__EXTERN LONGINT __STDCALL DdeAccessData (LONGINT hData, INTEGER *pcbDataSize);
__EXTERN LONGINT __STDCALL DdeAddData (LONGINT hData, CHAR *pSrc, INTEGER cb, INTEGER cbOff);
__EXTERN LONGINT __STDCALL DdeClientTransaction (CHAR *pData, INTEGER cbData, LONGINT hConv, LONGINT hszItem, INTEGER wFmt, INTEGER wType, INTEGER dwTimeout, INTEGER *pdwResult);
__EXTERN INTEGER __STDCALL DdeCmpStringHandles (LONGINT hsz1, LONGINT hsz2);
__EXTERN LONGINT __STDCALL DdeConnect (INTEGER idInst, LONGINT hszService, LONGINT hszTopic, WinAPI_CONVCONTEXT *pCC);
__EXTERN LONGINT __STDCALL DdeConnectList (INTEGER idInst, LONGINT hszService, LONGINT hszTopic, LONGINT hConvList, WinAPI_CONVCONTEXT *pCC);
__EXTERN LONGINT __STDCALL DdeCreateDataHandle (INTEGER idInst, CHAR *pSrc, INTEGER cb, INTEGER cbOff, LONGINT hszItem, INTEGER wFmt, INTEGER afCmd);
__EXTERN LONGINT __STDCALL DdeCreateStringHandleA (INTEGER idInst, LONGINT psz, INTEGER iCodePage);
__EXTERN LONGINT __STDCALL DdeCreateStringHandleW (INTEGER idInst, LONGINT psz, INTEGER iCodePage);
__EXTERN INTEGER __STDCALL DdeDisconnect (LONGINT hConv);
__EXTERN INTEGER __STDCALL DdeDisconnectList (LONGINT hConvList);
__EXTERN INTEGER __STDCALL DdeEnableCallback (INTEGER idInst, LONGINT hConv, INTEGER wCmd);
__EXTERN INTEGER __STDCALL DdeFreeDataHandle (LONGINT hData);
__EXTERN INTEGER __STDCALL DdeFreeStringHandle (INTEGER idInst, LONGINT hsz);
__EXTERN INTEGER __STDCALL DdeGetData (LONGINT hData, CHAR *pDst, INTEGER cbMax, INTEGER cbOff);
__EXTERN INTEGER __STDCALL DdeGetLastError (INTEGER idInst);
__EXTERN INTEGER __STDCALL DdeImpersonateClient (LONGINT hConv);
__EXTERN INTEGER __STDCALL DdeInitializeA (INTEGER *pidInst, WinAPI_FNCALLBACK pfnCallback, INTEGER afCmd, INTEGER ulRes);
__EXTERN INTEGER __STDCALL DdeInitializeW (INTEGER *pidInst, WinAPI_FNCALLBACK pfnCallback, INTEGER afCmd, INTEGER ulRes);
__EXTERN INTEGER __STDCALL DdeKeepStringHandle (INTEGER idInst, LONGINT hsz);
__EXTERN LONGINT __STDCALL DdeNameService (INTEGER idInst, LONGINT hsz1, LONGINT hsz2, INTEGER afCmd);
__EXTERN INTEGER __STDCALL DdePostAdvise (INTEGER idInst, LONGINT hszTopic, LONGINT hszItem);
__EXTERN INTEGER __STDCALL DdeQueryConvInfo (LONGINT hConv, INTEGER idTransaction, WinAPI_CONVINFO *pConvInfo);
__EXTERN LONGINT __STDCALL DdeQueryNextServer (LONGINT hConvList, LONGINT hConvPrev);
__EXTERN INTEGER __STDCALL DdeQueryStringA (INTEGER idInst, LONGINT hsz, LONGINT psz, INTEGER cchMax, INTEGER iCodePage);
__EXTERN INTEGER __STDCALL DdeQueryStringW (INTEGER idInst, LONGINT hsz, LONGINT psz, INTEGER cchMax, INTEGER iCodePage);
__EXTERN LONGINT __STDCALL DdeReconnect (LONGINT hConv);
__EXTERN INTEGER __STDCALL DdeSetQualityOfService (LONGINT hwndClient, WinAPI_SECURITY_QUALITY_OF_SERVICE *pqosNew, WinAPI_SECURITY_QUALITY_OF_SERVICE *pqosPrev);
__EXTERN INTEGER __STDCALL DdeSetUserHandle (LONGINT hConv, INTEGER id, INTEGER hUser);
__EXTERN INTEGER __STDCALL DdeUnaccessData (LONGINT hData);
__EXTERN INTEGER __STDCALL DdeUninitialize (INTEGER idInst);
__EXTERN INTEGER __STDCALL DebugActiveProcess (INTEGER dwProcessId);
__EXTERN void __STDCALL DebugBreak (void);
__EXTERN LONGINT __STDCALL DefDlgProcA (LONGINT hDlg, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN LONGINT __STDCALL DefDlgProcW (LONGINT hDlg, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN LONGINT __STDCALL DefFrameProcA (LONGINT hWnd, LONGINT hWndMDIClient, INTEGER uMsg, LONGINT wParam, LONGINT lParam);
__EXTERN LONGINT __STDCALL DefFrameProcW (LONGINT hWnd, LONGINT hWndMDIClient, INTEGER uMsg, LONGINT wParam, LONGINT lParam);
__EXTERN LONGINT __STDCALL DefMDIChildProcA (LONGINT hWnd, INTEGER uMsg, LONGINT wParam, LONGINT lParam);
__EXTERN LONGINT __STDCALL DefMDIChildProcW (LONGINT hWnd, INTEGER uMsg, LONGINT wParam, LONGINT lParam);
__EXTERN LONGINT __STDCALL DefWindowProcA (LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN LONGINT __STDCALL DefWindowProcW (LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN LONGINT __STDCALL DeferWindowPos (LONGINT hWinPosInfo, LONGINT hWnd, LONGINT hWndInsertAfter, INTEGER x, INTEGER y, INTEGER cx, INTEGER cy, SET uFlags);
__EXTERN INTEGER __STDCALL DefineDosDeviceA (SET dwFlags, LONGINT lpDeviceName, LONGINT lpTargetPath);
__EXTERN INTEGER __STDCALL DefineDosDeviceW (SET dwFlags, LONGINT lpDeviceName, LONGINT lpTargetPath);
__EXTERN INTEGER __STDCALL DeleteAce (WinAPI_ACL *pAcl, INTEGER dwAceIndex);
__EXTERN SHORTINT __STDCALL DeleteAtom (SHORTINT nAtom);
__EXTERN INTEGER __STDCALL DeleteColorSpace (LONGINT p0);
__EXTERN void __STDCALL DeleteCriticalSection (WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
__EXTERN INTEGER __STDCALL DeleteDC (LONGINT p0);
__EXTERN INTEGER __STDCALL DeleteEnhMetaFile (LONGINT p0);
__EXTERN void __STDCALL DeleteFiber (LONGINT lpFiber);
__EXTERN INTEGER __STDCALL DeleteFileA (LONGINT lpFileName);
__EXTERN INTEGER __STDCALL DeleteFileW (LONGINT lpFileName);
__EXTERN INTEGER __STDCALL DeleteFormA (LONGINT hPrinter, LONGINT pFormName);
__EXTERN INTEGER __STDCALL DeleteFormW (LONGINT hPrinter, LONGINT pFormName);
__EXTERN INTEGER __STDCALL DeleteMenu (LONGINT hMenu, INTEGER uPosition, SET uFlags);
__EXTERN INTEGER __STDCALL DeleteMetaFile (LONGINT p0);
__EXTERN INTEGER __STDCALL DeleteMonitorA (LONGINT pName, LONGINT pEnvironment, LONGINT pMonitorName);
__EXTERN INTEGER __STDCALL DeleteMonitorW (LONGINT pName, LONGINT pEnvironment, LONGINT pMonitorName);
__EXTERN INTEGER __STDCALL DeleteObject (LONGINT p0);
__EXTERN INTEGER __STDCALL DeletePortA (LONGINT pName, LONGINT hWnd, LONGINT pPortName);
__EXTERN INTEGER __STDCALL DeletePortW (LONGINT pName, LONGINT hWnd, LONGINT pPortName);
__EXTERN INTEGER __STDCALL DeletePrintProcessorA (LONGINT pName, LONGINT pEnvironment, LONGINT pPrintProcessorName);
__EXTERN INTEGER __STDCALL DeletePrintProcessorW (LONGINT pName, LONGINT pEnvironment, LONGINT pPrintProcessorName);
__EXTERN INTEGER __STDCALL DeletePrintProvidorA (LONGINT pName, LONGINT pEnvironment, LONGINT pPrintProvidorName);
__EXTERN INTEGER __STDCALL DeletePrintProvidorW (LONGINT pName, LONGINT pEnvironment, LONGINT pPrintProvidorName);
__EXTERN INTEGER __STDCALL DeletePrinter (LONGINT hPrinter);
__EXTERN INTEGER __STDCALL DeletePrinterConnectionA (LONGINT pName);
__EXTERN INTEGER __STDCALL DeletePrinterConnectionW (LONGINT pName);
__EXTERN INTEGER __STDCALL DeletePrinterDriverA (LONGINT pName, LONGINT pEnvironment, LONGINT pDriverName);
__EXTERN INTEGER __STDCALL DeletePrinterDriverW (LONGINT pName, LONGINT pEnvironment, LONGINT pDriverName);
__EXTERN INTEGER __STDCALL DeleteService (LONGINT hService);
__EXTERN INTEGER __STDCALL DeregisterEventSource (LONGINT hEventLog);
__EXTERN INTEGER __STDCALL DescribePixelFormat (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_PIXELFORMATDESCRIPTOR *p3);
__EXTERN INTEGER __STDCALL DestroyAcceleratorTable (LONGINT hAccel);
__EXTERN INTEGER __STDCALL DestroyCaret (void);
__EXTERN INTEGER __STDCALL DestroyCursor (LONGINT hCursor);
__EXTERN INTEGER __STDCALL DestroyIcon (LONGINT hIcon);
__EXTERN INTEGER __STDCALL DestroyMenu (LONGINT hMenu);
__EXTERN INTEGER __STDCALL DestroyPrivateObjectSecurity (LONGINT *ObjectDescriptor);
__EXTERN INTEGER __STDCALL DestroyPropertySheetPage (WinAPI_Ptr_PSP p0);
__EXTERN INTEGER __STDCALL DestroyWindow (LONGINT hWnd);
__EXTERN INTEGER __STDCALL DeviceCapabilitiesA (LONGINT p0, LONGINT p1, SHORTINT p2, LONGINT p3, WinAPI_DEVMODEA *p4);
__EXTERN INTEGER __STDCALL DeviceCapabilitiesW (LONGINT p0, LONGINT p1, SHORTINT p2, LONGINT p3, WinAPI_DEVMODEW *p4);
__EXTERN INTEGER __STDCALL DeviceIoControl (LONGINT hDevice, INTEGER dwIoControlCode, LONGINT lpInBuffer, INTEGER nInBufferSize, LONGINT lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesReturned, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL DialogBoxIndirectParamA (LONGINT hInstance, WinAPI_DLGTEMPLATE *hDialogTemplate, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
__EXTERN INTEGER __STDCALL DialogBoxIndirectParamW (LONGINT hInstance, WinAPI_DLGTEMPLATE *hDialogTemplate, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
__EXTERN INTEGER __STDCALL DialogBoxParamA (LONGINT hInstance, LONGINT lpTemplateName, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
__EXTERN INTEGER __STDCALL DialogBoxParamW (LONGINT hInstance, LONGINT lpTemplateName, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
__EXTERN INTEGER __STDCALL DisableThreadLibraryCalls (LONGINT hLibModule);
__EXTERN INTEGER __STDCALL DisconnectNamedPipe (LONGINT hNamedPipe);
__EXTERN INTEGER __STDCALL DispatchMessageA (WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL DispatchMessageW (WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL DlgDirListA (LONGINT hDlg, LONGINT lpPathSpec, INTEGER nIDListBox, INTEGER nIDStaticPath, SET uFileType);
__EXTERN INTEGER __STDCALL DlgDirListComboBoxA (LONGINT hDlg, LONGINT lpPathSpec, INTEGER nIDComboBox, INTEGER nIDStaticPath, INTEGER uFiletype);
__EXTERN INTEGER __STDCALL DlgDirListComboBoxW (LONGINT hDlg, LONGINT lpPathSpec, INTEGER nIDComboBox, INTEGER nIDStaticPath, INTEGER uFiletype);
__EXTERN INTEGER __STDCALL DlgDirListW (LONGINT hDlg, LONGINT lpPathSpec, INTEGER nIDListBox, INTEGER nIDStaticPath, SET uFileType);
__EXTERN INTEGER __STDCALL DlgDirSelectComboBoxExA (LONGINT hDlg, LONGINT lpString, INTEGER nCount, INTEGER nIDComboBox);
__EXTERN INTEGER __STDCALL DlgDirSelectComboBoxExW (LONGINT hDlg, LONGINT lpString, INTEGER nCount, INTEGER nIDComboBox);
__EXTERN INTEGER __STDCALL DlgDirSelectExA (LONGINT hDlg, LONGINT lpString, INTEGER nCount, INTEGER nIDListBox);
__EXTERN INTEGER __STDCALL DlgDirSelectExW (LONGINT hDlg, LONGINT lpString, INTEGER nCount, INTEGER nIDListBox);
__EXTERN INTEGER __STDCALL DoEnvironmentSubstA (LONGINT szString, INTEGER cbString);
__EXTERN INTEGER __STDCALL DoEnvironmentSubstW (LONGINT szString, INTEGER cbString);
__EXTERN INTEGER __STDCALL DocumentPropertiesA (LONGINT hWnd, LONGINT hPrinter, LONGINT pDeviceName, WinAPI_DEVMODEA *pDevModeOutput, WinAPI_DEVMODEA *pDevModeInput, SET fMode);
__EXTERN INTEGER __STDCALL DocumentPropertiesW (LONGINT hWnd, LONGINT hPrinter, LONGINT pDeviceName, WinAPI_DEVMODEW *pDevModeOutput, WinAPI_DEVMODEW *pDevModeInput, SET fMode);
__EXTERN INTEGER __STDCALL DosDateTimeToFileTime (SHORTINT wFatDate, SHORTINT wFatTime, WinAPI_FILETIME *lpFileTime);
__EXTERN void __STDCALL DragAcceptFiles (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL DragDetect (LONGINT p0, WinAPI_POINT *p1);
__EXTERN void __STDCALL DragFinish (LONGINT p0);
__EXTERN INTEGER __STDCALL DragObject (LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, LONGINT p4);
__EXTERN INTEGER __STDCALL DragQueryFileA (LONGINT p0, INTEGER p1, LONGINT p2, INTEGER p3);
__EXTERN INTEGER __STDCALL DragQueryFileW (LONGINT p0, INTEGER p1, LONGINT p2, INTEGER p3);
__EXTERN INTEGER __STDCALL DragQueryPoint (LONGINT p0, WinAPI_POINT *p1);
__EXTERN INTEGER __STDCALL DrawAnimatedRects (LONGINT hwnd, INTEGER idAni, WinAPI_RECT *lprcFrom, WinAPI_RECT *lprcTo);
__EXTERN INTEGER __STDCALL DrawCaption (LONGINT p0, LONGINT p1, WinAPI_RECT *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL DrawEdge (LONGINT hdc, WinAPI_RECT *qrc, SET edge, SET grfFlags);
__EXTERN INTEGER __STDCALL DrawEscape (LONGINT p0, INTEGER p1, INTEGER p2, LONGINT p3);
__EXTERN INTEGER __STDCALL DrawFocusRect (LONGINT hDC, WinAPI_RECT *lprc);
__EXTERN INTEGER __STDCALL DrawFrameControl (LONGINT p0, WinAPI_RECT *p1, INTEGER p2, SET p3);
__EXTERN INTEGER __STDCALL DrawIcon (LONGINT hDC, INTEGER X, INTEGER Y, LONGINT hIcon);
__EXTERN INTEGER __STDCALL DrawIconEx (LONGINT hdc, INTEGER xLeft, INTEGER yTop, LONGINT hIcon, INTEGER cxWidth, INTEGER cyWidth, INTEGER istepIfAniCur, LONGINT hbrFlickerFreeDraw, SET diFlags);
__EXTERN INTEGER __STDCALL DrawMenuBar (LONGINT hWnd);
__EXTERN INTEGER __STDCALL DrawStateA (LONGINT p0, LONGINT p1, WinAPI_DRAWSTATEPROC p2, LONGINT p3, LONGINT p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, SET p9);
__EXTERN INTEGER __STDCALL DrawStateW (LONGINT p0, LONGINT p1, WinAPI_DRAWSTATEPROC p2, LONGINT p3, LONGINT p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, SET p9);
__EXTERN INTEGER __STDCALL DrawTextA (LONGINT hDC, LONGINT lpString, INTEGER nCount, WinAPI_RECT *lpRect, SET uFormat);
__EXTERN INTEGER __STDCALL DrawTextExA (LONGINT p0, LONGINT p1, INTEGER p2, WinAPI_RECT *p3, INTEGER p4, WinAPI_DRAWTEXTPARAMS *p5);
__EXTERN INTEGER __STDCALL DrawTextExW (LONGINT p0, LONGINT p1, INTEGER p2, WinAPI_RECT *p3, INTEGER p4, WinAPI_DRAWTEXTPARAMS *p5);
__EXTERN INTEGER __STDCALL DrawTextW (LONGINT hDC, LONGINT lpString, INTEGER nCount, WinAPI_RECT *lpRect, SET uFormat);
__EXTERN INTEGER __STDCALL DuplicateHandle (LONGINT hSourceProcessHandle, LONGINT hSourceHandle, LONGINT hTargetProcessHandle, LONGINT *lpTargetHandle, SET dwDesiredAccess, INTEGER bInheritHandle, SET dwOptions);
__EXTERN LONGINT __STDCALL DuplicateIcon (LONGINT hInst, LONGINT hIcon);
__EXTERN INTEGER __STDCALL DuplicateToken (LONGINT ExistingTokenHandle, INTEGER ImpersonationLevel, LONGINT *DuplicateTokenHandle);
__EXTERN INTEGER __STDCALL Ellipse (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL EmptyClipboard (void);
__EXTERN INTEGER __STDCALL EnableMenuItem (LONGINT hMenu, INTEGER uIDEnableItem, SET uEnable);
__EXTERN INTEGER __STDCALL EnableScrollBar (LONGINT hWnd, INTEGER wSBflags, INTEGER wArrows);
__EXTERN INTEGER __STDCALL EnableWindow (LONGINT hWnd, INTEGER bEnable);
__EXTERN INTEGER __STDCALL EndDeferWindowPos (LONGINT hWinPosInfo);
__EXTERN INTEGER __STDCALL EndDialog (LONGINT hDlg, INTEGER nResult);
__EXTERN INTEGER __STDCALL EndDoc (LONGINT p0);
__EXTERN INTEGER __STDCALL EndDocPrinter (LONGINT hPrinter);
__EXTERN INTEGER __STDCALL EndPage (LONGINT p0);
__EXTERN INTEGER __STDCALL EndPagePrinter (LONGINT hPrinter);
__EXTERN INTEGER __STDCALL EndPaint (LONGINT hWnd, WinAPI_PAINTSTRUCT *lpPaint);
__EXTERN INTEGER __STDCALL EndPath (LONGINT p0);
__EXTERN INTEGER __STDCALL EndUpdateResourceA (LONGINT hUpdate, INTEGER fDiscard);
__EXTERN INTEGER __STDCALL EndUpdateResourceW (LONGINT hUpdate, INTEGER fDiscard);
__EXTERN void __STDCALL EnterCriticalSection (WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
__EXTERN INTEGER __STDCALL EnumCalendarInfoA (WinAPI_CALINFO_ENUMPROCA lpCalInfoEnumProc, INTEGER Locale, INTEGER Calendar, INTEGER CalType);
__EXTERN INTEGER __STDCALL EnumCalendarInfoW (WinAPI_CALINFO_ENUMPROCW lpCalInfoEnumProc, INTEGER Locale, INTEGER Calendar, INTEGER CalType);
__EXTERN INTEGER __STDCALL EnumChildWindows (LONGINT hWndParent, WinAPI_WNDENUMPROC lpEnumFunc, LONGINT lParam);
__EXTERN INTEGER __STDCALL EnumClipboardFormats (INTEGER format);
__EXTERN INTEGER __STDCALL EnumDateFormatsA (WinAPI_DATEFMT_ENUMPROCA lpDateFmtEnumProc, INTEGER Locale, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumDateFormatsW (WinAPI_DATEFMT_ENUMPROCW lpDateFmtEnumProc, INTEGER Locale, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumDependentServicesA (LONGINT hService, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSA *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned);
__EXTERN INTEGER __STDCALL EnumDependentServicesW (LONGINT hService, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSW *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned);
__EXTERN INTEGER __STDCALL EnumDesktopWindows (LONGINT hDesktop, WinAPI_WNDENUMPROC lpfn, LONGINT lParam);
__EXTERN INTEGER __STDCALL EnumDesktopsA (LONGINT hwinsta, WinAPI_DESKTOPENUMPROCA lpEnumFunc, LONGINT lParam);
__EXTERN INTEGER __STDCALL EnumDesktopsW (LONGINT hwinsta, WinAPI_DESKTOPENUMPROCW lpEnumFunc, LONGINT lParam);
__EXTERN INTEGER __STDCALL EnumDisplaySettingsA (LONGINT lpszDeviceName, INTEGER iModeNum, WinAPI_DEVMODEA *lpDevMode);
__EXTERN INTEGER __STDCALL EnumDisplaySettingsW (LONGINT lpszDeviceName, INTEGER iModeNum, WinAPI_DEVMODEW *lpDevMode);
__EXTERN INTEGER __STDCALL EnumEnhMetaFile (LONGINT p0, LONGINT p1, WinAPI_ENHMFENUMPROC p2, LONGINT p3, WinAPI_RECT *p4);
__EXTERN INTEGER __STDCALL EnumFontFamiliesA (LONGINT p0, LONGINT p1, WinAPI_NEWFONTENUMPROCA p2, LONGINT p3);
__EXTERN INTEGER __STDCALL EnumFontFamiliesExA (LONGINT p0, WinAPI_LOGFONTA *p1, WinAPI_FONTENUMPROCEXA p2, LONGINT p3, INTEGER p4);
__EXTERN INTEGER __STDCALL EnumFontFamiliesExW (LONGINT p0, WinAPI_LOGFONTW *p1, WinAPI_FONTENUMPROCEXW p2, LONGINT p3, INTEGER p4);
__EXTERN INTEGER __STDCALL EnumFontFamiliesW (LONGINT p0, LONGINT p1, WinAPI_NEWFONTENUMPROCW p2, LONGINT p3);
__EXTERN INTEGER __STDCALL EnumFontsA (LONGINT p0, LONGINT p1, WinAPI_FONTENUMPROCA p2, LONGINT p3);
__EXTERN INTEGER __STDCALL EnumFontsW (LONGINT p0, LONGINT p1, WinAPI_FONTENUMPROCW p2, LONGINT p3);
__EXTERN INTEGER __STDCALL EnumFormsA (LONGINT hPrinter, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumFormsW (LONGINT hPrinter, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumICMProfilesA (LONGINT p0, WinAPI_ICMENUMPROCA p1, LONGINT p2);
__EXTERN INTEGER __STDCALL EnumICMProfilesW (LONGINT p0, WinAPI_ICMENUMPROCW p1, LONGINT p2);
__EXTERN INTEGER __STDCALL EnumJobsA (LONGINT hPrinter, INTEGER FirstJob, INTEGER NoJobs, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumJobsW (LONGINT hPrinter, INTEGER FirstJob, INTEGER NoJobs, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumMetaFile (LONGINT p0, LONGINT p1, WinAPI_MFENUMPROC p2, LONGINT p3);
__EXTERN INTEGER __STDCALL EnumMonitorsA (LONGINT pName, INTEGER Level, CHAR *pMonitors, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumMonitorsW (LONGINT pName, INTEGER Level, CHAR *pMonitors, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumObjects (LONGINT p0, INTEGER p1, WinAPI_GOBJENUMPROC p2, LONGINT p3);
__EXTERN INTEGER __STDCALL EnumPortsA (LONGINT pName, INTEGER Level, CHAR *pPorts, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPortsW (LONGINT pName, INTEGER Level, CHAR *pPorts, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrintProcessorDatatypesA (LONGINT pName, LONGINT pPrintProcessorName, INTEGER Level, CHAR *pDatatypes, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrintProcessorDatatypesW (LONGINT pName, LONGINT pPrintProcessorName, INTEGER Level, CHAR *pDatatypes, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrintProcessorsA (LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrintProcessorsW (LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrinterDriversA (LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrinterDriversW (LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrintersA (SET Flags, LONGINT Name, INTEGER Level, CHAR *pPrinterEnum, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrintersW (SET Flags, LONGINT Name, INTEGER Level, CHAR *pPrinterEnum, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPropsA (LONGINT hWnd, WinAPI_ROPENUMPROCA lpEnumFunc);
__EXTERN INTEGER __STDCALL EnumPropsExA (LONGINT hWnd, WinAPI_ROPENUMPROCEXA lpEnumFunc, LONGINT lParam);
__EXTERN INTEGER __STDCALL EnumPropsExW (LONGINT hWnd, WinAPI_ROPENUMPROCEXW lpEnumFunc, LONGINT lParam);
__EXTERN INTEGER __STDCALL EnumPropsW (LONGINT hWnd, WinAPI_ROPENUMPROCW lpEnumFunc);
__EXTERN INTEGER __STDCALL EnumResourceLanguagesA (LONGINT hModule, LONGINT lpType, LONGINT lpName, WinAPI_ENUMRESLANGPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumResourceLanguagesW (LONGINT hModule, LONGINT lpType, LONGINT lpName, WinAPI_ENUMRESLANGPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumResourceNamesA (LONGINT hModule, LONGINT lpType, WinAPI_ENUMRESNAMEPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumResourceNamesW (LONGINT hModule, LONGINT lpType, WinAPI_ENUMRESNAMEPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumResourceTypesA (LONGINT hModule, WinAPI_ENUMRESTYPEPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumResourceTypesW (LONGINT hModule, WinAPI_ENUMRESTYPEPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumServicesStatusA (LONGINT hSCManager, SET dwServiceType, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSA *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned, INTEGER *lpResumeHandle);
__EXTERN INTEGER __STDCALL EnumServicesStatusW (LONGINT hSCManager, SET dwServiceType, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSW *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned, INTEGER *lpResumeHandle);
__EXTERN INTEGER __STDCALL EnumSystemCodePagesA (WinAPI_CODEPAGE_ENUMPROCA lpCodePageEnumProc, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumSystemCodePagesW (WinAPI_CODEPAGE_ENUMPROCW lpCodePageEnumProc, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumSystemLocalesA (WinAPI_LOCALE_ENUMPROCA lpLocaleEnumProc, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumSystemLocalesW (WinAPI_LOCALE_ENUMPROCW lpLocaleEnumProc, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumThreadWindows (INTEGER dwThreadId, WinAPI_WNDENUMPROC lpfn, LONGINT lParam);
__EXTERN INTEGER __STDCALL EnumTimeFormatsA (WinAPI_TIMEFMT_ENUMPROCA lpTimeFmtEnumProc, INTEGER Locale, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumTimeFormatsW (WinAPI_TIMEFMT_ENUMPROCW lpTimeFmtEnumProc, INTEGER Locale, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumWindowStationsA (WinAPI_WINSTAENUMPROCA lpEnumFunc, LONGINT lParam);
__EXTERN INTEGER __STDCALL EnumWindowStationsW (WinAPI_WINSTAENUMPROCW lpEnumFunc, LONGINT lParam);
__EXTERN INTEGER __STDCALL EnumWindows (WinAPI_WNDENUMPROC lpEnumFunc, LONGINT lParam);
__EXTERN INTEGER __STDCALL EqualPrefixSid (LONGINT pSid1, LONGINT pSid2);
__EXTERN INTEGER __STDCALL EqualRect (WinAPI_RECT *lprc1, WinAPI_RECT *lprc2);
__EXTERN INTEGER __STDCALL EqualRgn (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL EqualSid (LONGINT pSid1, LONGINT pSid2);
__EXTERN INTEGER __STDCALL EraseTape (LONGINT hDevice, INTEGER dwEraseType, INTEGER bImmediate);
__EXTERN INTEGER __STDCALL Escape (LONGINT p0, INTEGER p1, INTEGER p2, LONGINT p3, LONGINT p4);
__EXTERN INTEGER __STDCALL EscapeCommFunction (LONGINT hFile, INTEGER dwFunc);
__EXTERN INTEGER __STDCALL ExcludeClipRect (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL ExcludeUpdateRgn (LONGINT hDC, LONGINT hWnd);
__EXTERN void __STDCALL ExitProcess (INTEGER uExitCode);
__EXTERN void __STDCALL ExitThread (INTEGER dwExitCode);
__EXTERN INTEGER __STDCALL ExitWindowsEx (SET uFlags, INTEGER dwReserved);
__EXTERN INTEGER __STDCALL ExpandEnvironmentStringsA (LONGINT lpSrc, LONGINT lpDst, INTEGER nSize);
__EXTERN INTEGER __STDCALL ExpandEnvironmentStringsW (LONGINT lpSrc, LONGINT lpDst, INTEGER nSize);
__EXTERN LONGINT __STDCALL ExtCreatePen (INTEGER p0, INTEGER p1, WinAPI_LOGBRUSH *p2, INTEGER p3, INTEGER *p4);
__EXTERN LONGINT __STDCALL ExtCreateRegion (WinAPI_XFORM *p0, INTEGER p1, WinAPI_RGNDATA *p2);
__EXTERN INTEGER __STDCALL ExtEscape (LONGINT p0, INTEGER p1, INTEGER p2, LONGINT p3, INTEGER p4, LONGINT p5);
__EXTERN INTEGER __STDCALL ExtFloodFill (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL ExtSelectClipRgn (LONGINT p0, LONGINT p1, INTEGER p2);
__EXTERN INTEGER __STDCALL ExtTextOutA (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_RECT *p4, LONGINT p5, INTEGER p6, INTEGER *p7);
__EXTERN INTEGER __STDCALL ExtTextOutW (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_RECT *p4, LONGINT p5, INTEGER p6, INTEGER *p7);
__EXTERN LONGINT __STDCALL ExtractAssociatedIconA (LONGINT hInst, LONGINT lpIconPath, SHORTINT *lpiIcon);
__EXTERN LONGINT __STDCALL ExtractAssociatedIconW (LONGINT hInst, LONGINT lpIconPath, SHORTINT *lpiIcon);
__EXTERN LONGINT __STDCALL ExtractIconA (LONGINT hInst, LONGINT lpszExeFileName, INTEGER nIconIndex);
__EXTERN INTEGER __STDCALL ExtractIconExA (LONGINT lpszFile, INTEGER nIconIndex, LONGINT *phiconLarge, LONGINT *phiconSmall, INTEGER nIcons);
__EXTERN INTEGER __STDCALL ExtractIconExW (LONGINT lpszFile, INTEGER nIconIndex, LONGINT *phiconLarge, LONGINT *phiconSmall, INTEGER nIcons);
__EXTERN LONGINT __STDCALL ExtractIconW (LONGINT hInst, LONGINT lpszExeFileName, INTEGER nIconIndex);
__EXTERN void __STDCALL FatalAppExitA (INTEGER uAction, LONGINT lpMessageText);
__EXTERN void __STDCALL FatalAppExitW (INTEGER uAction, LONGINT lpMessageText);
__EXTERN void __STDCALL FatalExit (INTEGER ExitCode);
__EXTERN INTEGER __STDCALL FileTimeToDosDateTime (WinAPI_FILETIME *lpFileTime, SHORTINT *lpFatDate, SHORTINT *lpFatTime);
__EXTERN INTEGER __STDCALL FileTimeToLocalFileTime (WinAPI_FILETIME *lpFileTime, WinAPI_FILETIME *lpLocalFileTime);
__EXTERN INTEGER __STDCALL FileTimeToSystemTime (WinAPI_FILETIME *lpFileTime, WinAPI_SYSTEMTIME *lpSystemTime);
__EXTERN INTEGER __STDCALL FillConsoleOutputAttribute (LONGINT hConsoleOutput, SHORTINT wAttribute, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfAttrsWritten);
__EXTERN INTEGER __STDCALL FillConsoleOutputCharacterA (LONGINT hConsoleOutput, CHAR cCharacter, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
__EXTERN INTEGER __STDCALL FillConsoleOutputCharacterW (LONGINT hConsoleOutput, SHORTINT cCharacter, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
__EXTERN INTEGER __STDCALL FillPath (LONGINT p0);
__EXTERN INTEGER __STDCALL FillRect (LONGINT hDC, WinAPI_RECT *lprc, LONGINT hbr);
__EXTERN INTEGER __STDCALL FillRgn (LONGINT p0, LONGINT p1, LONGINT p2);
__EXTERN SHORTINT __STDCALL FindAtomA (LONGINT lpString);
__EXTERN SHORTINT __STDCALL FindAtomW (LONGINT lpString);
__EXTERN INTEGER __STDCALL FindClose (LONGINT hFindFile);
__EXTERN INTEGER __STDCALL FindCloseChangeNotification (LONGINT hChangeHandle);
__EXTERN INTEGER __STDCALL FindClosePrinterChangeNotification (LONGINT hChange);
__EXTERN LONGINT __STDCALL FindExecutableA (LONGINT lpFile, LONGINT lpDirectory, LONGINT lpResult);
__EXTERN LONGINT __STDCALL FindExecutableW (LONGINT lpFile, LONGINT lpDirectory, LONGINT lpResult);
__EXTERN LONGINT __STDCALL FindFirstChangeNotificationA (LONGINT lpPathName, INTEGER bWatchSubtree, SET dwNotifyFilter);
__EXTERN LONGINT __STDCALL FindFirstChangeNotificationW (LONGINT lpPathName, INTEGER bWatchSubtree, SET dwNotifyFilter);
__EXTERN LONGINT __STDCALL FindFirstFileA (LONGINT lpFileName, WinAPI_WIN32_FIND_DATAA *lpFindFileData);
__EXTERN LONGINT __STDCALL FindFirstFileExA (LONGINT lpFileName, INTEGER fInfoLevelId, LONGINT lpFindFileData, INTEGER fSearchOp, LONGINT lpSearchFilter, INTEGER dwAdditionalFlags);
__EXTERN LONGINT __STDCALL FindFirstFileExW (LONGINT lpFileName, INTEGER fInfoLevelId, LONGINT lpFindFileData, INTEGER fSearchOp, LONGINT lpSearchFilter, INTEGER dwAdditionalFlags);
__EXTERN LONGINT __STDCALL FindFirstFileW (LONGINT lpFileName, WinAPI_WIN32_FIND_DATAW *lpFindFileData);
__EXTERN INTEGER __STDCALL FindFirstFreeAce (WinAPI_ACL *pAcl, LONGINT pAce);
__EXTERN LONGINT __STDCALL FindFirstPrinterChangeNotification (LONGINT hPrinter, SET fdwFlags, INTEGER fdwOptions, LONGINT pPrinterNotifyOptions);
__EXTERN INTEGER __STDCALL FindNextChangeNotification (LONGINT hChangeHandle);
__EXTERN INTEGER __STDCALL FindNextFileA (LONGINT hFindFile, WinAPI_WIN32_FIND_DATAA *lpFindFileData);
__EXTERN INTEGER __STDCALL FindNextFileW (LONGINT hFindFile, WinAPI_WIN32_FIND_DATAW *lpFindFileData);
__EXTERN INTEGER __STDCALL FindNextPrinterChangeNotification (LONGINT hChange, INTEGER *pdwChange, LONGINT pvReserved, LONGINT ppPrinterNotifyInfo);
__EXTERN LONGINT __STDCALL FindResourceA (LONGINT hModule, LONGINT lpName, LONGINT lpType);
__EXTERN LONGINT __STDCALL FindResourceExA (LONGINT hModule, LONGINT lpType, LONGINT lpName, SHORTINT wLanguage);
__EXTERN LONGINT __STDCALL FindResourceExW (LONGINT hModule, LONGINT lpType, LONGINT lpName, SHORTINT wLanguage);
__EXTERN LONGINT __STDCALL FindResourceW (LONGINT hModule, LONGINT lpName, LONGINT lpType);
__EXTERN LONGINT __STDCALL FindWindowA (LONGINT lpClassName, LONGINT lpWindowName);
__EXTERN LONGINT __STDCALL FindWindowExA (LONGINT p0, LONGINT p1, LONGINT p2, LONGINT p3);
__EXTERN LONGINT __STDCALL FindWindowExW (LONGINT p0, LONGINT p1, LONGINT p2, LONGINT p3);
__EXTERN LONGINT __STDCALL FindWindowW (LONGINT lpClassName, LONGINT lpWindowName);
__EXTERN INTEGER __STDCALL FixBrushOrgEx (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN INTEGER __STDCALL FlashWindow (LONGINT hWnd, INTEGER bInvert);
__EXTERN INTEGER __STDCALL FlattenPath (LONGINT p0);
__EXTERN INTEGER __STDCALL FloodFill (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL FlushConsoleInputBuffer (LONGINT hConsoleInput);
__EXTERN INTEGER __STDCALL FlushFileBuffers (LONGINT hFile);
__EXTERN INTEGER __STDCALL FlushInstructionCache (LONGINT hProcess, LONGINT lpBaseAddress, INTEGER dwSize);
__EXTERN INTEGER __STDCALL FlushViewOfFile (LONGINT lpBaseAddress, INTEGER dwNumberOfBytesToFlush);
__EXTERN INTEGER __STDCALL FoldStringA (SET dwMapFlags, LONGINT lpSrcStr, INTEGER cchSrc, LONGINT lpDestStr, INTEGER cchDest);
__EXTERN INTEGER __STDCALL FoldStringW (SET dwMapFlags, LONGINT lpSrcStr, INTEGER cchSrc, LONGINT lpDestStr, INTEGER cchDest);
__EXTERN INTEGER __STDCALL FormatMessageA (SET dwFlags, LONGINT lpSource, INTEGER dwMessageId, INTEGER dwLanguageId, LONGINT lpBuffer, INTEGER nSize, LONGINT *Arguments);
__EXTERN INTEGER __STDCALL FormatMessageW (SET dwFlags, LONGINT lpSource, INTEGER dwMessageId, INTEGER dwLanguageId, LONGINT lpBuffer, INTEGER nSize, LONGINT *Arguments);
__EXTERN INTEGER __STDCALL FrameRect (LONGINT hDC, WinAPI_RECT *lprc, LONGINT hbr);
__EXTERN INTEGER __STDCALL FrameRgn (LONGINT p0, LONGINT p1, LONGINT p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL FreeConsole (void);
__EXTERN INTEGER __STDCALL FreeDDElParam (INTEGER msg, INTEGER lParam);
__EXTERN INTEGER __STDCALL FreeEnvironmentStringsA (LONGINT p0);
__EXTERN INTEGER __STDCALL FreeEnvironmentStringsW (LONGINT p0);
__EXTERN INTEGER __STDCALL FreeLibrary (LONGINT hLibModule);
__EXTERN void __STDCALL FreeLibraryAndExitThread (LONGINT hLibModule, INTEGER dwExitCode);
__EXTERN INTEGER __STDCALL FreePrinterNotifyInfo (WinAPI_PRINTER_NOTIFY_INFO *pPrinterNotifyInfo);
__EXTERN INTEGER __STDCALL FreeResource (LONGINT hResData);
__EXTERN LONGINT __STDCALL FreeSid (LONGINT pSid);
__EXTERN INTEGER __STDCALL GdiComment (LONGINT p0, INTEGER p1, CHAR *p2);
__EXTERN INTEGER __STDCALL GdiFlush (void);
__EXTERN INTEGER __STDCALL GdiGetBatchLimit (void);
__EXTERN INTEGER __STDCALL GdiSetBatchLimit (INTEGER p0);
__EXTERN INTEGER __STDCALL GenerateConsoleCtrlEvent (INTEGER dwCtrlEvent, INTEGER dwProcessGroupId);
__EXTERN INTEGER __STDCALL GetACP (void);
__EXTERN INTEGER __STDCALL GetAce (WinAPI_ACL *pAcl, INTEGER dwAceIndex, LONGINT pAce);
__EXTERN INTEGER __STDCALL GetAclInformation (WinAPI_ACL *pAcl, LONGINT pAclInformation, INTEGER nAclInformationLength, INTEGER dwAclInformationClass);
__EXTERN LONGINT __STDCALL GetActiveWindow (void);
__EXTERN INTEGER __STDCALL GetArcDirection (LONGINT p0);
__EXTERN INTEGER __STDCALL GetAspectRatioFilterEx (LONGINT p0, WinAPI_SIZE *p1);
__EXTERN SHORTINT __STDCALL GetAsyncKeyState (INTEGER vKey);
__EXTERN INTEGER __STDCALL GetAtomNameA (SHORTINT nAtom, LONGINT lpBuffer, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetAtomNameW (SHORTINT nAtom, LONGINT lpBuffer, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetBinaryTypeA (LONGINT lpApplicationName, INTEGER *lpBinaryType);
__EXTERN INTEGER __STDCALL GetBinaryTypeW (LONGINT lpApplicationName, INTEGER *lpBinaryType);
__EXTERN INTEGER __STDCALL GetBitmapBits (LONGINT p0, INTEGER p1, LONGINT p2);
__EXTERN INTEGER __STDCALL GetBitmapDimensionEx (LONGINT p0, WinAPI_SIZE *p1);
__EXTERN INTEGER __STDCALL GetBkColor (LONGINT p0);
__EXTERN INTEGER __STDCALL GetBkMode (LONGINT p0);
__EXTERN SET __STDCALL GetBoundsRect (LONGINT p0, WinAPI_RECT *p1, SET p2);
__EXTERN INTEGER __STDCALL GetBrushOrgEx (LONGINT p0, WinAPI_POINT *p1);
__EXTERN INTEGER __STDCALL GetCPInfo (INTEGER CodePage, WinAPI_CPINFO *lpCPInfo);
__EXTERN LONGINT __STDCALL GetCapture (void);
__EXTERN INTEGER __STDCALL GetCaretBlinkTime (void);
__EXTERN INTEGER __STDCALL GetCaretPos (WinAPI_POINT *lpPoint);
__EXTERN INTEGER __STDCALL GetCharABCWidthsA (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_ABC *p3);
__EXTERN INTEGER __STDCALL GetCharABCWidthsFloatA (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_ABCFLOAT *p3);
__EXTERN INTEGER __STDCALL GetCharABCWidthsFloatW (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_ABCFLOAT *p3);
__EXTERN INTEGER __STDCALL GetCharABCWidthsW (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_ABC *p3);
__EXTERN INTEGER __STDCALL GetCharWidth32A (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER *p3);
__EXTERN INTEGER __STDCALL GetCharWidth32W (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER *p3);
__EXTERN INTEGER __STDCALL GetCharWidthA (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER *p3);
__EXTERN INTEGER __STDCALL GetCharWidthFloatA (LONGINT p0, INTEGER p1, INTEGER p2, SHORTREAL *p3);
__EXTERN INTEGER __STDCALL GetCharWidthFloatW (LONGINT p0, INTEGER p1, INTEGER p2, SHORTREAL *p3);
__EXTERN INTEGER __STDCALL GetCharWidthW (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER *p3);
__EXTERN INTEGER __STDCALL GetCharacterPlacementA (LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, WinAPI_GCP_RESULTSA *p4, INTEGER p5);
__EXTERN INTEGER __STDCALL GetCharacterPlacementW (LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, WinAPI_GCP_RESULTSW *p4, INTEGER p5);
__EXTERN INTEGER __STDCALL GetClassInfoA (LONGINT hInstance, LONGINT lpClassName, WinAPI_WNDCLASSA *lpWndClass);
__EXTERN INTEGER __STDCALL GetClassInfoExA (LONGINT p0, LONGINT p1, WinAPI_WNDCLASSEXA *p2);
__EXTERN INTEGER __STDCALL GetClassInfoExW (LONGINT p0, LONGINT p1, WinAPI_WNDCLASSEXW *p2);
__EXTERN INTEGER __STDCALL GetClassInfoW (LONGINT hInstance, LONGINT lpClassName, WinAPI_WNDCLASSW *lpWndClass);
__EXTERN INTEGER __STDCALL GetClassLongA (LONGINT hWnd, INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetClassLongW (LONGINT hWnd, INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetClassNameA (LONGINT hWnd, LONGINT lpClassName, INTEGER nMaxCount);
__EXTERN INTEGER __STDCALL GetClassNameW (LONGINT hWnd, LONGINT lpClassName, INTEGER nMaxCount);
__EXTERN SHORTINT __STDCALL GetClassWord (LONGINT hWnd, INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetClientRect (LONGINT hWnd, WinAPI_RECT *lpRect);
__EXTERN INTEGER __STDCALL GetClipBox (LONGINT p0, WinAPI_RECT *p1);
__EXTERN INTEGER __STDCALL GetClipCursor (WinAPI_RECT *lpRect);
__EXTERN INTEGER __STDCALL GetClipRgn (LONGINT p0, LONGINT p1);
__EXTERN LONGINT __STDCALL GetClipboardData (INTEGER uFormat);
__EXTERN INTEGER __STDCALL GetClipboardFormatNameA (INTEGER format, LONGINT lpszFormatName, INTEGER cchMaxCount);
__EXTERN INTEGER __STDCALL GetClipboardFormatNameW (INTEGER format, LONGINT lpszFormatName, INTEGER cchMaxCount);
__EXTERN LONGINT __STDCALL GetClipboardOwner (void);
__EXTERN LONGINT __STDCALL GetClipboardViewer (void);
__EXTERN INTEGER __STDCALL GetColorAdjustment (LONGINT p0, WinAPI_COLORADJUSTMENT *p1);
__EXTERN LONGINT __STDCALL GetColorSpace (LONGINT p0);
__EXTERN INTEGER __STDCALL GetCommConfig (LONGINT hCommDev, WinAPI_COMMCONFIG *lpCC, INTEGER *lpdwSize);
__EXTERN INTEGER __STDCALL GetCommMask (LONGINT hFile, SET *lpEvtMask);
__EXTERN INTEGER __STDCALL GetCommModemStatus (LONGINT hFile, SET *lpModemStat);
__EXTERN INTEGER __STDCALL GetCommProperties (LONGINT hFile, WinAPI_COMMPROP *lpCommProp);
__EXTERN INTEGER __STDCALL GetCommState (LONGINT hFile, WinAPI_DCB *lpDCB);
__EXTERN INTEGER __STDCALL GetCommTimeouts (LONGINT hFile, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
__EXTERN LONGINT __STDCALL GetCommandLineA (void);
__EXTERN LONGINT __STDCALL GetCommandLineW (void);
__EXTERN INTEGER __STDCALL GetCompressedFileSizeA (LONGINT lpFileName, INTEGER *lpFileSizeHigh);
__EXTERN INTEGER __STDCALL GetCompressedFileSizeW (LONGINT lpFileName, INTEGER *lpFileSizeHigh);
__EXTERN INTEGER __STDCALL GetComputerNameA (LONGINT lpBuffer, INTEGER *nSize);
__EXTERN INTEGER __STDCALL GetComputerNameW (LONGINT lpBuffer, INTEGER *nSize);
__EXTERN INTEGER __STDCALL GetConsoleCP (void);
__EXTERN INTEGER __STDCALL GetConsoleCursorInfo (LONGINT hConsoleOutput, WinAPI_CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
__EXTERN INTEGER __STDCALL GetConsoleMode (LONGINT hConsoleHandle, SET *lpMode);
__EXTERN INTEGER __STDCALL GetConsoleOutputCP (void);
__EXTERN INTEGER __STDCALL GetConsoleScreenBufferInfo (LONGINT hConsoleOutput, WinAPI_CONSOLE_SCREEN_BUFFER_INFO *lpConsoleScreenBufferInfo);
__EXTERN INTEGER __STDCALL GetConsoleTitleA (LONGINT lpConsoleTitle, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetConsoleTitleW (LONGINT lpConsoleTitle, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetCurrencyFormatA (INTEGER Locale, SET dwFlags, LONGINT lpValue, WinAPI_CURRENCYFMTA *lpFormat, LONGINT lpCurrencyStr, INTEGER cchCurrency);
__EXTERN INTEGER __STDCALL GetCurrencyFormatW (INTEGER Locale, SET dwFlags, LONGINT lpValue, WinAPI_CURRENCYFMTW *lpFormat, LONGINT lpCurrencyStr, INTEGER cchCurrency);
__EXTERN INTEGER __STDCALL GetCurrentDirectoryA (INTEGER nBufferLength, LONGINT lpBuffer);
__EXTERN INTEGER __STDCALL GetCurrentDirectoryW (INTEGER nBufferLength, LONGINT lpBuffer);
__EXTERN INTEGER __STDCALL GetCurrentHwProfileA (WinAPI_HW_PROFILE_INFOA *lpHwProfileInfo);
__EXTERN INTEGER __STDCALL GetCurrentHwProfileW (WinAPI_HW_PROFILE_INFOW *lpHwProfileInfo);
__EXTERN LONGINT __STDCALL GetCurrentObject (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetCurrentPositionEx (LONGINT p0, WinAPI_POINT *p1);
__EXTERN LONGINT __STDCALL GetCurrentProcess (void);
__EXTERN INTEGER __STDCALL GetCurrentProcessId (void);
__EXTERN LONGINT __STDCALL GetCurrentThread (void);
__EXTERN INTEGER __STDCALL GetCurrentThreadId (void);
__EXTERN LONGINT __STDCALL GetCursor (void);
__EXTERN INTEGER __STDCALL GetCursorPos (WinAPI_POINT *lpPoint);
__EXTERN LONGINT __STDCALL GetDC (LONGINT hWnd);
__EXTERN LONGINT __STDCALL GetDCEx (LONGINT hWnd, LONGINT hrgnClip, SET flags);
__EXTERN INTEGER __STDCALL GetDCOrgEx (LONGINT p0, WinAPI_POINT *p1);
__EXTERN INTEGER __STDCALL GetDIBColorTable (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_RGBQUAD *p3);
__EXTERN INTEGER __STDCALL GetDIBits (LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, LONGINT p4, WinAPI_BITMAPINFO *p5, INTEGER p6);
__EXTERN INTEGER __STDCALL GetDateFormatA (INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpDate, LONGINT lpFormat, LONGINT lpDateStr, INTEGER cchDate);
__EXTERN INTEGER __STDCALL GetDateFormatW (INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpDate, LONGINT lpFormat, LONGINT lpDateStr, INTEGER cchDate);
__EXTERN INTEGER __STDCALL GetDefaultCommConfigA (LONGINT lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER *lpdwSize);
__EXTERN INTEGER __STDCALL GetDefaultCommConfigW (LONGINT lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER *lpdwSize);
__EXTERN LONGINT __STDCALL GetDesktopWindow (void);
__EXTERN INTEGER __STDCALL GetDeviceCaps (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetDeviceGammaRamp (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL GetDialogBaseUnits (void);
__EXTERN INTEGER __STDCALL GetDiskFreeSpaceA (LONGINT lpRootPathName, INTEGER *lpSectorsPerCluster, INTEGER *lpBytesPerSector, INTEGER *lpNumberOfFreeClusters, INTEGER *lpTotalNumberOfClusters);
__EXTERN INTEGER __STDCALL GetDiskFreeSpaceW (LONGINT lpRootPathName, INTEGER *lpSectorsPerCluster, INTEGER *lpBytesPerSector, INTEGER *lpNumberOfFreeClusters, INTEGER *lpTotalNumberOfClusters);
__EXTERN INTEGER __STDCALL GetDlgCtrlID (LONGINT hWnd);
__EXTERN LONGINT __STDCALL GetDlgItem (LONGINT hDlg, INTEGER nIDDlgItem);
__EXTERN INTEGER __STDCALL GetDlgItemInt (LONGINT hDlg, INTEGER nIDDlgItem, INTEGER *lpTranslated, INTEGER bSigned);
__EXTERN INTEGER __STDCALL GetDlgItemTextA (LONGINT hDlg, INTEGER nIDDlgItem, LONGINT lpString, INTEGER nMaxCount);
__EXTERN INTEGER __STDCALL GetDlgItemTextW (LONGINT hDlg, INTEGER nIDDlgItem, LONGINT lpString, INTEGER nMaxCount);
__EXTERN INTEGER __STDCALL GetDoubleClickTime (void);
__EXTERN INTEGER __STDCALL GetDriveTypeA (LONGINT lpRootPathName);
__EXTERN INTEGER __STDCALL GetDriveTypeW (LONGINT lpRootPathName);
__EXTERN LONGINT __STDCALL GetEnhMetaFileA (LONGINT p0);
__EXTERN INTEGER __STDCALL GetEnhMetaFileBits (LONGINT p0, INTEGER p1, CHAR *p2);
__EXTERN INTEGER __STDCALL GetEnhMetaFileDescriptionA (LONGINT p0, INTEGER p1, LONGINT p2);
__EXTERN INTEGER __STDCALL GetEnhMetaFileDescriptionW (LONGINT p0, INTEGER p1, LONGINT p2);
__EXTERN INTEGER __STDCALL GetEnhMetaFileHeader (LONGINT p0, INTEGER p1, WinAPI_ENHMETAHEADER *p2);
__EXTERN INTEGER __STDCALL GetEnhMetaFilePaletteEntries (LONGINT p0, INTEGER p1, WinAPI_PALETTEENTRY *p2);
__EXTERN INTEGER __STDCALL GetEnhMetaFilePixelFormat (LONGINT p0, INTEGER p1, WinAPI_PIXELFORMATDESCRIPTOR *p2);
__EXTERN LONGINT __STDCALL GetEnhMetaFileW (LONGINT p0);
__EXTERN LONGINT __STDCALL GetEnvironmentStrings (void);
__EXTERN LONGINT __STDCALL GetEnvironmentStringsW (void);
__EXTERN INTEGER __STDCALL GetEnvironmentVariableA (LONGINT lpName, LONGINT lpBuffer, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetEnvironmentVariableW (LONGINT lpName, LONGINT lpBuffer, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetExitCodeProcess (LONGINT hProcess, INTEGER *lpExitCode);
__EXTERN INTEGER __STDCALL GetExitCodeThread (LONGINT hThread, INTEGER *lpExitCode);
__EXTERN INTEGER __STDCALL GetExpandedNameA (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL GetExpandedNameW (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL GetFileAttributesA (LONGINT lpFileName);
__EXTERN INTEGER __STDCALL GetFileAttributesW (LONGINT lpFileName);
__EXTERN INTEGER __STDCALL GetFileInformationByHandle (LONGINT hFile, WinAPI_BY_HANDLE_FILE_INFORMATION *lpFileInformation);
__EXTERN INTEGER __STDCALL GetFileSecurityA (LONGINT lpFileName, SET RequestedInformation, LONGINT pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
__EXTERN INTEGER __STDCALL GetFileSecurityW (LONGINT lpFileName, SET RequestedInformation, LONGINT pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
__EXTERN INTEGER __STDCALL GetFileSize (LONGINT hFile, INTEGER *lpFileSizeHigh);
__EXTERN INTEGER __STDCALL GetFileSizeEx (LONGINT hFile, LONGINT *lpFileSizeHigh);
__EXTERN INTEGER __STDCALL GetFileTime (LONGINT hFile, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpLastAccessTime, WinAPI_FILETIME *lpLastWriteTime);
__EXTERN INTEGER __STDCALL GetFileType (LONGINT hFile);
__EXTERN INTEGER __STDCALL GetFileVersionInfoA (LONGINT lptstrFilename, INTEGER dwHandle, INTEGER dwLen, LONGINT lpData);
__EXTERN INTEGER __STDCALL GetFileVersionInfoSizeA (LONGINT lptstrFilename, INTEGER *lpdwHandle);
__EXTERN INTEGER __STDCALL GetFileVersionInfoSizeW (LONGINT lptstrFilename, INTEGER *lpdwHandle);
__EXTERN INTEGER __STDCALL GetFileVersionInfoW (LONGINT lptstrFilename, INTEGER dwHandle, INTEGER dwLen, LONGINT lpData);
__EXTERN LONGINT __STDCALL GetFocus (void);
__EXTERN INTEGER __STDCALL GetFontData (LONGINT p0, INTEGER p1, INTEGER p2, LONGINT p3, INTEGER p4);
__EXTERN SET __STDCALL GetFontLanguageInfo (LONGINT p0);
__EXTERN LONGINT __STDCALL GetForegroundWindow (void);
__EXTERN INTEGER __STDCALL GetFormA (LONGINT hPrinter, LONGINT pFormName, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetFormW (LONGINT hPrinter, LONGINT pFormName, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetFullPathNameA (LONGINT lpFileName, INTEGER nBufferLength, LONGINT lpBuffer, LONGINT *lpFilePart);
__EXTERN INTEGER __STDCALL GetFullPathNameW (LONGINT lpFileName, INTEGER nBufferLength, LONGINT lpBuffer, LONGINT *lpFilePart);
__EXTERN INTEGER __STDCALL GetGlyphOutlineA (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_GLYPHMETRICS *p3, INTEGER p4, LONGINT p5, WinAPI_MAT2 *p6);
__EXTERN INTEGER __STDCALL GetGlyphOutlineW (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_GLYPHMETRICS *p3, INTEGER p4, LONGINT p5, WinAPI_MAT2 *p6);
__EXTERN INTEGER __STDCALL GetGraphicsMode (LONGINT p0);
__EXTERN INTEGER __STDCALL GetHandleInformation (LONGINT hObject, SET *lpdwFlags);
__EXTERN INTEGER __STDCALL GetICMProfileA (LONGINT p0, INTEGER *p1, LONGINT p2);
__EXTERN INTEGER __STDCALL GetICMProfileW (LONGINT p0, INTEGER *p1, LONGINT p2);
__EXTERN INTEGER __STDCALL GetIconInfo (LONGINT hIcon, WinAPI_ICONINFO *piconinfo);
__EXTERN INTEGER __STDCALL GetInputState (void);
__EXTERN INTEGER __STDCALL GetJobA (LONGINT hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetJobW (LONGINT hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetKBCodePage (void);
__EXTERN INTEGER __STDCALL GetKernelObjectSecurity (LONGINT Handle, SET RequestedInformation, LONGINT pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
__EXTERN INTEGER __STDCALL GetKerningPairsA (LONGINT p0, INTEGER p1, WinAPI_KERNINGPAIR *p2);
__EXTERN INTEGER __STDCALL GetKerningPairsW (LONGINT p0, INTEGER p1, WinAPI_KERNINGPAIR *p2);
__EXTERN INTEGER __STDCALL GetKeyNameTextA (INTEGER lParam, LONGINT lpString, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetKeyNameTextW (INTEGER lParam, LONGINT lpString, INTEGER nSize);
__EXTERN SHORTINT __STDCALL GetKeyState (INTEGER nVirtKey);
__EXTERN LONGINT __STDCALL GetKeyboardLayout (INTEGER dwLayout);
__EXTERN INTEGER __STDCALL GetKeyboardLayoutList (INTEGER nBuff, LONGINT *lpList);
__EXTERN INTEGER __STDCALL GetKeyboardLayoutNameA (LONGINT pwszKLID);
__EXTERN INTEGER __STDCALL GetKeyboardLayoutNameW (LONGINT pwszKLID);
__EXTERN INTEGER __STDCALL GetKeyboardState (CHAR *lpKeyState);
__EXTERN INTEGER __STDCALL GetKeyboardType (INTEGER nTypeFlag);
__EXTERN INTEGER __STDCALL GetLargestConsoleWindowSize (LONGINT hConsoleOutput);
__EXTERN LONGINT __STDCALL GetLastActivePopup (LONGINT hWnd);
__EXTERN INTEGER __STDCALL GetLastError (void);
__EXTERN INTEGER __STDCALL GetLengthSid (LONGINT pSid);
__EXTERN void __STDCALL GetLocalTime (WinAPI_SYSTEMTIME *lpSystemTime);
__EXTERN INTEGER __STDCALL GetLocaleInfoA (INTEGER Locale, INTEGER LCType, LONGINT lpLCData, INTEGER cchData);
__EXTERN INTEGER __STDCALL GetLocaleInfoW (INTEGER Locale, INTEGER LCType, LONGINT lpLCData, INTEGER cchData);
__EXTERN INTEGER __STDCALL GetLogColorSpaceA (LONGINT p0, WinAPI_LOGCOLORSPACEA *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetLogColorSpaceW (LONGINT p0, WinAPI_LOGCOLORSPACEW *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetLogicalDriveStringsA (INTEGER nBufferLength, LONGINT lpBuffer);
__EXTERN INTEGER __STDCALL GetLogicalDriveStringsW (INTEGER nBufferLength, LONGINT lpBuffer);
__EXTERN INTEGER __STDCALL GetLogicalDrives (void);
__EXTERN INTEGER __STDCALL GetMailslotInfo (LONGINT hMailslot, INTEGER *lpMaxMessageSize, INTEGER *lpNextSize, INTEGER *lpMessageCount, INTEGER *lpReadTimeout);
__EXTERN INTEGER __STDCALL GetMapMode (LONGINT p0);
__EXTERN LONGINT __STDCALL GetMenu (LONGINT hWnd);
__EXTERN INTEGER __STDCALL GetMenuCheckMarkDimensions (void);
__EXTERN INTEGER __STDCALL GetMenuContextHelpId (LONGINT p0);
__EXTERN INTEGER __STDCALL GetMenuDefaultItem (LONGINT hMenu, INTEGER fByPos, SET gmdiFlags);
__EXTERN INTEGER __STDCALL GetMenuItemCount (LONGINT hMenu);
__EXTERN INTEGER __STDCALL GetMenuItemID (LONGINT hMenu, INTEGER nPos);
__EXTERN INTEGER __STDCALL GetMenuItemInfoA (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOA *p3);
__EXTERN INTEGER __STDCALL GetMenuItemInfoW (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOW *p3);
__EXTERN INTEGER __STDCALL GetMenuItemRect (LONGINT hWnd, LONGINT hMenu, INTEGER uItem, WinAPI_RECT *lprcItem);
__EXTERN INTEGER __STDCALL GetMenuState (LONGINT hMenu, INTEGER uId, SET uFlags);
__EXTERN INTEGER __STDCALL GetMenuStringA (LONGINT hMenu, INTEGER uIDItem, LONGINT lpString, INTEGER nMaxCount, SET uFlag);
__EXTERN INTEGER __STDCALL GetMenuStringW (LONGINT hMenu, INTEGER uIDItem, LONGINT lpString, INTEGER nMaxCount, SET uFlag);
__EXTERN INTEGER __STDCALL GetMessageA (WinAPI_MSG *lpMsg, LONGINT hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax);
__EXTERN INTEGER __STDCALL GetMessageExtraInfo (void);
__EXTERN INTEGER __STDCALL GetMessagePos (void);
__EXTERN INTEGER __STDCALL GetMessageTime (void);
__EXTERN INTEGER __STDCALL GetMessageW (WinAPI_MSG *lpMsg, LONGINT hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax);
__EXTERN LONGINT __STDCALL GetMetaFileA (LONGINT p0);
__EXTERN INTEGER __STDCALL GetMetaFileBitsEx (LONGINT p0, INTEGER p1, BYTE *p2);
__EXTERN LONGINT __STDCALL GetMetaFileW (LONGINT p0);
__EXTERN INTEGER __STDCALL GetMetaRgn (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL GetMiterLimit (LONGINT p0, SHORTREAL *p1);
__EXTERN INTEGER __STDCALL GetModuleFileNameA (LONGINT hModule, LONGINT lpFilename, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetModuleFileNameW (LONGINT hModule, LONGINT lpFilename, INTEGER nSize);
__EXTERN LONGINT __STDCALL GetModuleHandleA (LONGINT lpModuleName);
__EXTERN LONGINT __STDCALL GetModuleHandleW (LONGINT lpModuleName);
__EXTERN INTEGER __STDCALL GetNamedPipeHandleStateA (LONGINT hNamedPipe, INTEGER *lpState, INTEGER *lpCurInstances, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout, LONGINT lpUserName, INTEGER nMaxUserNameSize);
__EXTERN INTEGER __STDCALL GetNamedPipeHandleStateW (LONGINT hNamedPipe, INTEGER *lpState, INTEGER *lpCurInstances, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout, LONGINT lpUserName, INTEGER nMaxUserNameSize);
__EXTERN INTEGER __STDCALL GetNamedPipeInfo (LONGINT hNamedPipe, INTEGER *lpFlags, INTEGER *lpOutBufferSize, INTEGER *lpInBufferSize, INTEGER *lpMaxInstances);
__EXTERN INTEGER __STDCALL GetNearestColor (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetNearestPaletteIndex (LONGINT p0, INTEGER p1);
__EXTERN LONGINT __STDCALL GetNextDlgGroupItem (LONGINT hDlg, LONGINT hCtl, INTEGER bPrevious);
__EXTERN LONGINT __STDCALL GetNextDlgTabItem (LONGINT hDlg, LONGINT hCtl, INTEGER bPrevious);
__EXTERN INTEGER __STDCALL GetNumberFormatA (INTEGER Locale, SET dwFlags, LONGINT lpValue, WinAPI_NUMBERFMTA *lpFormat, LONGINT lpNumberStr, INTEGER cchNumber);
__EXTERN INTEGER __STDCALL GetNumberFormatW (INTEGER Locale, SET dwFlags, LONGINT lpValue, WinAPI_NUMBERFMTW *lpFormat, LONGINT lpNumberStr, INTEGER cchNumber);
__EXTERN INTEGER __STDCALL GetNumberOfConsoleInputEvents (LONGINT hConsoleInput, INTEGER *lpNumberOfEvents);
__EXTERN INTEGER __STDCALL GetNumberOfConsoleMouseButtons (INTEGER *lpNumberOfMouseButtons);
__EXTERN INTEGER __STDCALL GetNumberOfEventLogRecords (LONGINT hEventLog, INTEGER *NumberOfRecords);
__EXTERN INTEGER __STDCALL GetOEMCP (void);
__EXTERN INTEGER __STDCALL GetObjectA (LONGINT p0, INTEGER p1, LONGINT p2);
__EXTERN INTEGER __STDCALL GetObjectType (LONGINT h);
__EXTERN INTEGER __STDCALL GetObjectW (LONGINT p0, INTEGER p1, LONGINT p2);
__EXTERN INTEGER __STDCALL GetOldestEventLogRecord (LONGINT hEventLog, INTEGER *OldestRecord);
__EXTERN LONGINT __STDCALL GetOpenClipboardWindow (void);
__EXTERN INTEGER __STDCALL GetOutlineTextMetricsA (LONGINT p0, INTEGER p1, WinAPI_OUTLINETEXTMETRICA *p2);
__EXTERN INTEGER __STDCALL GetOutlineTextMetricsW (LONGINT p0, INTEGER p1, WinAPI_OUTLINETEXTMETRICW *p2);
__EXTERN INTEGER __STDCALL GetOverlappedResult (LONGINT hFile, WinAPI_OVERLAPPED *lpOverlapped, INTEGER *lpNumberOfBytesTransferred, INTEGER bWait);
__EXTERN INTEGER __STDCALL GetPaletteEntries (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
__EXTERN LONGINT __STDCALL GetParent (LONGINT hWnd);
__EXTERN INTEGER __STDCALL GetPath (LONGINT p0, WinAPI_POINT *p1, CHAR *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL GetPixel (LONGINT p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetPixelFormat (LONGINT p0);
__EXTERN INTEGER __STDCALL GetPolyFillMode (LONGINT p0);
__EXTERN INTEGER __STDCALL GetPrintProcessorDirectoryA (LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrintProcessorDirectoryW (LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterA (LONGINT hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterDataA (LONGINT hPrinter, LONGINT pValueName, INTEGER *pType, CHAR *pData, INTEGER nSize, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterDataW (LONGINT hPrinter, LONGINT pValueName, INTEGER *pType, CHAR *pData, INTEGER nSize, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterDriverA (LONGINT hPrinter, LONGINT pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterDriverDirectoryA (LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pDriverDirectory, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterDriverDirectoryW (LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pDriverDirectory, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterDriverW (LONGINT hPrinter, LONGINT pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterW (LONGINT hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPriorityClass (LONGINT hProcess);
__EXTERN INTEGER __STDCALL GetPriorityClipboardFormat (INTEGER *paFormatPriorityList, INTEGER cFormats);
__EXTERN INTEGER __STDCALL GetPrivateObjectSecurity (LONGINT ObjectDescriptor, SET SecurityInformation, LONGINT ResultantDescriptor, INTEGER DescriptorLength, INTEGER *ReturnLength);
__EXTERN INTEGER __STDCALL GetPrivateProfileIntA (LONGINT lpAppName, LONGINT lpKeyName, INTEGER nDefault, LONGINT lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileIntW (LONGINT lpAppName, LONGINT lpKeyName, INTEGER nDefault, LONGINT lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileSectionA (LONGINT lpAppName, LONGINT lpReturnedString, INTEGER nSize, LONGINT lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileSectionNamesA (LONGINT lpszReturnBuffer, INTEGER nSize, LONGINT lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileSectionNamesW (LONGINT lpszReturnBuffer, INTEGER nSize, LONGINT lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileSectionW (LONGINT lpAppName, LONGINT lpReturnedString, INTEGER nSize, LONGINT lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileStringA (LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpDefault, LONGINT lpReturnedString, INTEGER nSize, LONGINT lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileStringW (LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpDefault, LONGINT lpReturnedString, INTEGER nSize, LONGINT lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileStructA (LONGINT lpszSection, LONGINT lpszKey, LONGINT lpStruct, INTEGER uSizeStruct, LONGINT szFile);
__EXTERN INTEGER __STDCALL GetPrivateProfileStructW (LONGINT lpszSection, LONGINT lpszKey, LONGINT lpStruct, INTEGER uSizeStruct, LONGINT szFile);
__EXTERN WinAPI_FARPROC __STDCALL GetProcAddress (LONGINT hModule, LONGINT lpProcName);
__EXTERN INTEGER __STDCALL GetProcessAffinityMask (LONGINT hProcess, INTEGER *lpProcessAffinityMask, INTEGER *lpSystemAffinityMask);
__EXTERN LONGINT __STDCALL GetProcessHeap (void);
__EXTERN INTEGER __STDCALL GetProcessHeaps (INTEGER NumberOfHeaps, LONGINT *ProcessHeaps);
__EXTERN INTEGER __STDCALL GetProcessShutdownParameters (INTEGER *lpdwLevel, SET *lpdwFlags);
__EXTERN INTEGER __STDCALL GetProcessTimes (LONGINT hProcess, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpExitTime, WinAPI_FILETIME *lpKernelTime, WinAPI_FILETIME *lpUserTime);
__EXTERN INTEGER __STDCALL GetProcessVersion (INTEGER ProcessId);
__EXTERN LONGINT __STDCALL GetProcessWindowStation (void);
__EXTERN INTEGER __STDCALL GetProcessWorkingSetSize (LONGINT hProcess, INTEGER *lpMinimumWorkingSetSize, INTEGER *lpMaximumWorkingSetSize);
__EXTERN INTEGER __STDCALL GetProfileIntA (LONGINT lpAppName, LONGINT lpKeyName, INTEGER nDefault);
__EXTERN INTEGER __STDCALL GetProfileIntW (LONGINT lpAppName, LONGINT lpKeyName, INTEGER nDefault);
__EXTERN INTEGER __STDCALL GetProfileSectionA (LONGINT lpAppName, LONGINT lpReturnedString, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetProfileSectionW (LONGINT lpAppName, LONGINT lpReturnedString, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetProfileStringA (LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpDefault, LONGINT lpReturnedString, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetProfileStringW (LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpDefault, LONGINT lpReturnedString, INTEGER nSize);
__EXTERN LONGINT __STDCALL GetPropA (LONGINT hWnd, LONGINT lpString);
__EXTERN LONGINT __STDCALL GetPropW (LONGINT hWnd, LONGINT lpString);
__EXTERN INTEGER __STDCALL GetQueueStatus (SET flags);
__EXTERN INTEGER __STDCALL GetQueuedCompletionStatus (LONGINT CompletionPort, INTEGER *lpNumberOfBytesTransferred, INTEGER *lpCompletionKey, WinAPI_PtrOVERLAPPED *lpOverlapped, INTEGER dwMilliseconds);
__EXTERN INTEGER __STDCALL GetROP2 (LONGINT p0);
__EXTERN INTEGER __STDCALL GetRasterizerCaps (WinAPI_RASTERIZER_STATUS *p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetRegionData (LONGINT p0, INTEGER p1, WinAPI_RGNDATA *p2);
__EXTERN INTEGER __STDCALL GetRgnBox (LONGINT p0, WinAPI_RECT *p1);
__EXTERN INTEGER __STDCALL GetScrollInfo (LONGINT p0, INTEGER p1, WinAPI_SCROLLINFO *p2);
__EXTERN INTEGER __STDCALL GetScrollPos (LONGINT hWnd, INTEGER nBar);
__EXTERN INTEGER __STDCALL GetScrollRange (LONGINT hWnd, INTEGER nBar, INTEGER *lpMinPos, INTEGER *lpMaxPos);
__EXTERN INTEGER __STDCALL GetSecurityDescriptorControl (LONGINT pSecurityDescriptor, SHORTINT *pControl, INTEGER *lpdwRevision);
__EXTERN INTEGER __STDCALL GetSecurityDescriptorDacl (LONGINT pSecurityDescriptor, INTEGER *lpbDaclPresent, WinAPI_PtrACL *pDacl, INTEGER *lpbDaclDefaulted);
__EXTERN INTEGER __STDCALL GetSecurityDescriptorGroup (LONGINT pSecurityDescriptor, LONGINT *pGroup, INTEGER *lpbGroupDefaulted);
__EXTERN INTEGER __STDCALL GetSecurityDescriptorLength (LONGINT pSecurityDescriptor);
__EXTERN INTEGER __STDCALL GetSecurityDescriptorOwner (LONGINT pSecurityDescriptor, LONGINT *pOwner, INTEGER *lpbOwnerDefaulted);
__EXTERN INTEGER __STDCALL GetSecurityDescriptorSacl (LONGINT pSecurityDescriptor, INTEGER *lpbSaclPresent, WinAPI_PtrACL *pSacl, INTEGER *lpbSaclDefaulted);
__EXTERN INTEGER __STDCALL GetServiceDisplayNameA (LONGINT hSCManager, LONGINT lpServiceName, LONGINT lpDisplayName, INTEGER *lpcchBuffer);
__EXTERN INTEGER __STDCALL GetServiceDisplayNameW (LONGINT hSCManager, LONGINT lpServiceName, LONGINT lpDisplayName, INTEGER *lpcchBuffer);
__EXTERN INTEGER __STDCALL GetServiceKeyNameA (LONGINT hSCManager, LONGINT lpDisplayName, LONGINT lpServiceName, INTEGER *lpcchBuffer);
__EXTERN INTEGER __STDCALL GetServiceKeyNameW (LONGINT hSCManager, LONGINT lpDisplayName, LONGINT lpServiceName, INTEGER *lpcchBuffer);
__EXTERN INTEGER __STDCALL GetShortPathNameA (LONGINT lpszLongPath, LONGINT lpszShortPath, INTEGER cchBuffer);
__EXTERN INTEGER __STDCALL GetShortPathNameW (LONGINT lpszLongPath, LONGINT lpszShortPath, INTEGER cchBuffer);
__EXTERN WinAPI_PtrSID_IDENTIFIER_AUTHORITY __STDCALL GetSidIdentifierAuthority (LONGINT pSid);
__EXTERN INTEGER __STDCALL GetSidLengthRequired (CHAR nSubAuthorityCount);
__EXTERN LONGINT __STDCALL GetSidSubAuthority (LONGINT pSid, INTEGER nSubAuthority);
__EXTERN LONGINT __STDCALL GetSidSubAuthorityCount (LONGINT pSid);
__EXTERN void __STDCALL GetStartupInfoA (WinAPI_STARTUPINFOA *lpStartupInfo);
__EXTERN void __STDCALL GetStartupInfoW (WinAPI_STARTUPINFOW *lpStartupInfo);
__EXTERN LONGINT __STDCALL GetStdHandle (INTEGER nStdHandle);
__EXTERN LONGINT __STDCALL GetStockObject (INTEGER p0);
__EXTERN INTEGER __STDCALL GetStretchBltMode (LONGINT p0);
__EXTERN INTEGER __STDCALL GetStringTypeA (INTEGER Locale, SET dwInfoType, LONGINT lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
__EXTERN INTEGER __STDCALL GetStringTypeExA (INTEGER Locale, SET dwInfoType, LONGINT lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
__EXTERN INTEGER __STDCALL GetStringTypeExW (INTEGER Locale, SET dwInfoType, LONGINT lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
__EXTERN INTEGER __STDCALL GetStringTypeW (SET dwInfoType, LONGINT lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
__EXTERN LONGINT __STDCALL GetSubMenu (LONGINT hMenu, INTEGER nPos);
__EXTERN INTEGER __STDCALL GetSysColor (INTEGER nIndex);
__EXTERN LONGINT __STDCALL GetSysColorBrush (INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetSystemDefaultLCID (void);
__EXTERN SHORTINT __STDCALL GetSystemDefaultLangID (void);
__EXTERN INTEGER __STDCALL GetSystemDirectoryA (LONGINT lpBuffer, INTEGER uSize);
__EXTERN INTEGER __STDCALL GetSystemDirectoryW (LONGINT lpBuffer, INTEGER uSize);
__EXTERN void __STDCALL GetSystemInfo (WinAPI_SYSTEM_INFO *lpSystemInfo);
__EXTERN LONGINT __STDCALL GetSystemMenu (LONGINT hWnd, INTEGER bRevert);
__EXTERN INTEGER __STDCALL GetSystemMetrics (INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetSystemPaletteEntries (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
__EXTERN INTEGER __STDCALL GetSystemPaletteUse (LONGINT p0);
__EXTERN INTEGER __STDCALL GetSystemPowerStatus (WinAPI_SYSTEM_POWER_STATUS *lpSystemPowerStatus);
__EXTERN void __STDCALL GetSystemTime (WinAPI_SYSTEMTIME *lpSystemTime);
__EXTERN INTEGER __STDCALL GetSystemTimeAdjustment (INTEGER *lpTimeAdjustment, INTEGER *lpTimeIncrement, INTEGER *lpTimeAdjustmentDisabled);
__EXTERN void __STDCALL GetSystemTimeAsFileTime (WinAPI_FILETIME *lpSystemTimeAsFileTime);
__EXTERN INTEGER __STDCALL GetTabbedTextExtentA (LONGINT hDC, LONGINT lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions);
__EXTERN INTEGER __STDCALL GetTabbedTextExtentW (LONGINT hDC, LONGINT lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions);
__EXTERN INTEGER __STDCALL GetTapeParameters (LONGINT hDevice, INTEGER dwOperation, INTEGER *lpdwSize, LONGINT lpTapeInformation);
__EXTERN INTEGER __STDCALL GetTapePosition (LONGINT hDevice, INTEGER dwPositionType, INTEGER *lpdwPartition, INTEGER *lpdwOffsetLow, INTEGER *lpdwOffsetHigh);
__EXTERN INTEGER __STDCALL GetTapeStatus (LONGINT hDevice);
__EXTERN INTEGER __STDCALL GetTempFileNameA (LONGINT lpPathName, LONGINT lpPrefixString, INTEGER uUnique, LONGINT lpTempFileName);
__EXTERN INTEGER __STDCALL GetTempFileNameW (LONGINT lpPathName, LONGINT lpPrefixString, INTEGER uUnique, LONGINT lpTempFileName);
__EXTERN INTEGER __STDCALL GetTempPathA (INTEGER nBufferLength, LONGINT lpBuffer);
__EXTERN INTEGER __STDCALL GetTempPathW (INTEGER nBufferLength, LONGINT lpBuffer);
__EXTERN SET __STDCALL GetTextAlign (LONGINT p0);
__EXTERN INTEGER __STDCALL GetTextCharacterExtra (LONGINT p0);
__EXTERN INTEGER __STDCALL GetTextCharset (LONGINT hdc);
__EXTERN INTEGER __STDCALL GetTextCharsetInfo (LONGINT hdc, WinAPI_FONTSIGNATURE *lpSig, SET dwFlags);
__EXTERN INTEGER __STDCALL GetTextColor (LONGINT p0);
__EXTERN INTEGER __STDCALL GetTextExtentExPointA (LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, INTEGER *p4, INTEGER *p5, WinAPI_SIZE *p6);
__EXTERN INTEGER __STDCALL GetTextExtentExPointW (LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, INTEGER *p4, INTEGER *p5, WinAPI_SIZE *p6);
__EXTERN INTEGER __STDCALL GetTextExtentPoint32A (LONGINT p0, LONGINT p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL GetTextExtentPoint32W (LONGINT p0, LONGINT p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL GetTextExtentPointA (LONGINT p0, LONGINT p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL GetTextExtentPointW (LONGINT p0, LONGINT p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL GetTextFaceA (LONGINT p0, INTEGER p1, LONGINT p2);
__EXTERN INTEGER __STDCALL GetTextFaceW (LONGINT p0, INTEGER p1, LONGINT p2);
__EXTERN INTEGER __STDCALL GetTextMetricsA (LONGINT p0, WinAPI_TEXTMETRICA *p1);
__EXTERN INTEGER __STDCALL GetTextMetricsW (LONGINT p0, WinAPI_TEXTMETRICW *p1);
__EXTERN INTEGER __STDCALL GetThreadContext (LONGINT hThread, WinAPI_CONTEXT *lpContext);
__EXTERN LONGINT __STDCALL GetThreadDesktop (INTEGER dwThreadId);
__EXTERN INTEGER __STDCALL GetThreadLocale (void);
__EXTERN INTEGER __STDCALL GetThreadPriority (LONGINT hThread);
__EXTERN INTEGER __STDCALL GetThreadPriorityBoost (LONGINT hThread, INTEGER *pDisablePriorityBoost);
__EXTERN INTEGER __STDCALL GetThreadSelectorEntry (LONGINT hThread, INTEGER dwSelector, WinAPI_LDT_ENTRY *lpSelectorEntry);
__EXTERN INTEGER __STDCALL GetThreadTimes (LONGINT hThread, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpExitTime, WinAPI_FILETIME *lpKernelTime, WinAPI_FILETIME *lpUserTime);
__EXTERN INTEGER __STDCALL GetTickCount (void);
__EXTERN INTEGER __STDCALL GetTimeFormatA (INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpTime, LONGINT lpFormat, LONGINT lpTimeStr, INTEGER cchTime);
__EXTERN INTEGER __STDCALL GetTimeFormatW (INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpTime, LONGINT lpFormat, LONGINT lpTimeStr, INTEGER cchTime);
__EXTERN INTEGER __STDCALL GetTimeZoneInformation (WinAPI_TIME_ZONE_INFORMATION *lpTimeZoneInformation);
__EXTERN INTEGER __STDCALL GetTokenInformation (LONGINT TokenHandle, INTEGER TokenInformationClass, LONGINT TokenInformation, INTEGER TokenInformationLength, INTEGER *ReturnLength);
__EXTERN LONGINT __STDCALL GetTopWindow (LONGINT hWnd);
__EXTERN INTEGER __STDCALL GetUpdateRect (LONGINT hWnd, WinAPI_RECT *lpRect, INTEGER bErase);
__EXTERN INTEGER __STDCALL GetUpdateRgn (LONGINT hWnd, LONGINT hRgn, INTEGER bErase);
__EXTERN INTEGER __STDCALL GetUserDefaultLCID (void);
__EXTERN SHORTINT __STDCALL GetUserDefaultLangID (void);
__EXTERN INTEGER __STDCALL GetUserNameA (LONGINT lpBuffer, INTEGER *nSize);
__EXTERN INTEGER __STDCALL GetUserNameW (LONGINT lpBuffer, INTEGER *nSize);
__EXTERN INTEGER __STDCALL GetUserObjectInformationA (LONGINT hObj, INTEGER nIndex, LONGINT pvInfo, INTEGER nLength, INTEGER *lpnLengthNeeded);
__EXTERN INTEGER __STDCALL GetUserObjectInformationW (LONGINT hObj, INTEGER nIndex, LONGINT pvInfo, INTEGER nLength, INTEGER *lpnLengthNeeded);
__EXTERN INTEGER __STDCALL GetUserObjectSecurity (LONGINT hObj, INTEGER *pSIRequested, LONGINT pSID, INTEGER nLength, INTEGER *lpnLengthNeeded);
__EXTERN INTEGER __STDCALL GetVersion (void);
__EXTERN INTEGER __STDCALL GetVersionExA (WinAPI_OSVERSIONINFOA *lpVersionInformation);
__EXTERN INTEGER __STDCALL GetVersionExW (WinAPI_OSVERSIONINFOW *lpVersionInformation);
__EXTERN INTEGER __STDCALL GetViewportExtEx (LONGINT p0, WinAPI_SIZE *p1);
__EXTERN INTEGER __STDCALL GetViewportOrgEx (LONGINT p0, WinAPI_POINT *p1);
__EXTERN INTEGER __STDCALL GetVolumeInformationA (LONGINT lpRootPathName, LONGINT lpVolumeNameBuffer, INTEGER nVolumeNameSize, INTEGER *lpVolumeSerialNumber, INTEGER *lpMaximumComponentLength, SET *lpFileSystemFlags, LONGINT lpFileSystemNameBuffer, INTEGER nFileSystemNameSize);
__EXTERN INTEGER __STDCALL GetVolumeInformationW (LONGINT lpRootPathName, LONGINT lpVolumeNameBuffer, INTEGER nVolumeNameSize, INTEGER *lpVolumeSerialNumber, INTEGER *lpMaximumComponentLength, SET *lpFileSystemFlags, LONGINT lpFileSystemNameBuffer, INTEGER nFileSystemNameSize);
__EXTERN INTEGER __STDCALL GetWinMetaFileBits (LONGINT p0, INTEGER p1, CHAR *p2, INTEGER p3, LONGINT p4);
__EXTERN LONGINT __STDCALL GetWindow (LONGINT hWnd, INTEGER uCmd);
__EXTERN INTEGER __STDCALL GetWindowContextHelpId (LONGINT p0);
__EXTERN LONGINT __STDCALL GetWindowDC (LONGINT hWnd);
__EXTERN INTEGER __STDCALL GetWindowExtEx (LONGINT p0, WinAPI_SIZE *p1);
__EXTERN INTEGER __STDCALL GetWindowLongA (LONGINT hWnd, INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetWindowLongW (LONGINT hWnd, INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetWindowOrgEx (LONGINT p0, WinAPI_POINT *p1);
__EXTERN INTEGER __STDCALL GetWindowPlacement (LONGINT hWnd, WinAPI_WINDOWPLACEMENT *lpwndpl);
__EXTERN INTEGER __STDCALL GetWindowRect (LONGINT hWnd, WinAPI_RECT *lpRect);
__EXTERN INTEGER __STDCALL GetWindowRgn (LONGINT hWnd, LONGINT hRgn);
__EXTERN INTEGER __STDCALL GetWindowTextA (LONGINT hWnd, LONGINT lpString, INTEGER nMaxCount);
__EXTERN INTEGER __STDCALL GetWindowTextLengthA (LONGINT hWnd);
__EXTERN INTEGER __STDCALL GetWindowTextLengthW (LONGINT hWnd);
__EXTERN INTEGER __STDCALL GetWindowTextW (LONGINT hWnd, LONGINT lpString, INTEGER nMaxCount);
__EXTERN INTEGER __STDCALL GetWindowThreadProcessId (LONGINT hWnd, INTEGER *lpdwProcessId);
__EXTERN SHORTINT __STDCALL GetWindowWord (LONGINT hWnd, INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetWindowsDirectoryA (LONGINT lpBuffer, INTEGER uSize);
__EXTERN INTEGER __STDCALL GetWindowsDirectoryW (LONGINT lpBuffer, INTEGER uSize);
__EXTERN INTEGER __STDCALL GetWorldTransform (LONGINT p0, WinAPI_XFORM *p1);
__EXTERN SHORTINT __STDCALL GlobalAddAtomA (LONGINT lpString);
__EXTERN SHORTINT __STDCALL GlobalAddAtomW (LONGINT lpString);
__EXTERN LONGINT __STDCALL GlobalAlloc (SET uFlags, LONGINT dwBytes);
__EXTERN LONGINT __STDCALL GlobalCompact (INTEGER dwMinFree);
__EXTERN SHORTINT __STDCALL GlobalDeleteAtom (SHORTINT nAtom);
__EXTERN SHORTINT __STDCALL GlobalFindAtomA (LONGINT lpString);
__EXTERN SHORTINT __STDCALL GlobalFindAtomW (LONGINT lpString);
__EXTERN void __STDCALL GlobalFix (LONGINT hMem);
__EXTERN INTEGER __STDCALL GlobalFlags (LONGINT hMem);
__EXTERN LONGINT __STDCALL GlobalFree (LONGINT hMem);
__EXTERN INTEGER __STDCALL GlobalGetAtomNameA (SHORTINT nAtom, LONGINT lpBuffer, INTEGER nSize);
__EXTERN INTEGER __STDCALL GlobalGetAtomNameW (SHORTINT nAtom, LONGINT lpBuffer, INTEGER nSize);
__EXTERN LONGINT __STDCALL GlobalHandle (LONGINT pMem);
__EXTERN LONGINT __STDCALL GlobalLock (LONGINT hMem);
__EXTERN void __STDCALL GlobalMemoryStatus (WinAPI_MEMORYSTATUS *lpBuffer);
__EXTERN LONGINT __STDCALL GlobalReAlloc (LONGINT hMem, LONGINT dwBytes, SET uFlags);
__EXTERN LONGINT __STDCALL GlobalSize (LONGINT hMem);
__EXTERN INTEGER __STDCALL GlobalUnWire (LONGINT hMem);
__EXTERN void __STDCALL GlobalUnfix (LONGINT hMem);
__EXTERN INTEGER __STDCALL GlobalUnlock (LONGINT hMem);
__EXTERN LONGINT __STDCALL GlobalWire (LONGINT hMem);
__EXTERN INTEGER __STDCALL GrayStringA (LONGINT hDC, LONGINT hBrush, WinAPI_GRAYSTRINGPROC lpOutputFunc, LONGINT lpData, INTEGER nCount, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight);
__EXTERN INTEGER __STDCALL GrayStringW (LONGINT hDC, LONGINT hBrush, WinAPI_GRAYSTRINGPROC lpOutputFunc, LONGINT lpData, INTEGER nCount, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight);
__EXTERN LONGINT __STDCALL HeapAlloc (LONGINT hHeap, SET dwFlags, LONGINT dwBytes);
__EXTERN LONGINT __STDCALL HeapCompact (LONGINT hHeap, SET dwFlags);
__EXTERN LONGINT __STDCALL HeapCreate (SET flOptions, LONGINT dwInitialSize, LONGINT dwMaximumSize);
__EXTERN INTEGER __STDCALL HeapDestroy (LONGINT hHeap);
__EXTERN INTEGER __STDCALL HeapFree (LONGINT hHeap, SET dwFlags, LONGINT lpMem);
__EXTERN INTEGER __STDCALL HeapLock (LONGINT hHeap);
__EXTERN LONGINT __STDCALL HeapReAlloc (LONGINT hHeap, SET dwFlags, LONGINT lpMem, LONGINT dwBytes);
__EXTERN LONGINT __STDCALL HeapSize (LONGINT hHeap, SET dwFlags, LONGINT lpMem);
__EXTERN INTEGER __STDCALL HeapUnlock (LONGINT hHeap);
__EXTERN INTEGER __STDCALL HeapValidate (LONGINT hHeap, SET dwFlags, LONGINT lpMem);
__EXTERN INTEGER __STDCALL HeapWalk (LONGINT hHeap, WinAPI_PROCESS_HEAP_ENTRY *lpEntry);
__EXTERN INTEGER __STDCALL HideCaret (LONGINT hWnd);
__EXTERN INTEGER __STDCALL HiliteMenuItem (LONGINT hWnd, LONGINT hMenu, INTEGER uIDHiliteItem, INTEGER uHilite);
__EXTERN INTEGER __STDCALL ImpersonateDdeClientWindow (LONGINT hWndClient, LONGINT hWndServer);
__EXTERN INTEGER __STDCALL ImpersonateLoggedOnUser (LONGINT hToken);
__EXTERN INTEGER __STDCALL ImpersonateNamedPipeClient (LONGINT hNamedPipe);
__EXTERN INTEGER __STDCALL ImpersonateSelf (INTEGER ImpersonationLevel);
__EXTERN INTEGER __STDCALL InSendMessage (void);
__EXTERN INTEGER __STDCALL InflateRect (WinAPI_RECT *lprc, INTEGER dx, INTEGER dy);
__EXTERN INTEGER __STDCALL InitAtomTable (INTEGER nSize);
__EXTERN INTEGER __STDCALL InitializeAcl (WinAPI_ACL *pAcl, INTEGER nAclLength, INTEGER dwAclRevision);
__EXTERN void __STDCALL InitializeCriticalSection (WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
__EXTERN INTEGER __STDCALL InitializeSecurityDescriptor (LONGINT pSecurityDescriptor, INTEGER dwRevision);
__EXTERN INTEGER __STDCALL InitializeSid (LONGINT Sid, WinAPI_SID_IDENTIFIER_AUTHORITY *pIdentifierAuthority, CHAR nSubAuthorityCount);
__EXTERN INTEGER __STDCALL InitiateSystemShutdownA (LONGINT lpMachineName, LONGINT lpMessage, INTEGER dwTimeout, INTEGER bForceAppsClosed, INTEGER bRebootAfterShutdown);
__EXTERN INTEGER __STDCALL InitiateSystemShutdownW (LONGINT lpMachineName, LONGINT lpMessage, INTEGER dwTimeout, INTEGER bForceAppsClosed, INTEGER bRebootAfterShutdown);
__EXTERN INTEGER __STDCALL InsertMenuA (LONGINT hMenu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, LONGINT lpNewItem);
__EXTERN INTEGER __STDCALL InsertMenuItemA (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOA *p3);
__EXTERN INTEGER __STDCALL InsertMenuItemW (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOW *p3);
__EXTERN INTEGER __STDCALL InsertMenuW (LONGINT hMenu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, LONGINT lpNewItem);
__EXTERN LONGINT __STDCALL InterlockedCompareExchange (LONGINT Destination, LONGINT Exchange, LONGINT Comperand);
__EXTERN INTEGER __STDCALL InterlockedDecrement (INTEGER *lpAddend);
__EXTERN INTEGER __STDCALL InterlockedExchange (INTEGER *Target, INTEGER Value);
__EXTERN INTEGER __STDCALL InterlockedExchangeAdd (INTEGER *Addend, INTEGER Value);
__EXTERN INTEGER __STDCALL InterlockedIncrement (INTEGER *lpAddend);
__EXTERN INTEGER __STDCALL IntersectClipRect (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL IntersectRect (WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc1, WinAPI_RECT *lprcSrc2);
__EXTERN INTEGER __STDCALL InvalidateRect (LONGINT hWnd, WinAPI_RECT *lpRect, INTEGER bErase);
__EXTERN INTEGER __STDCALL InvalidateRgn (LONGINT hWnd, LONGINT hRgn, INTEGER bErase);
__EXTERN INTEGER __STDCALL InvertRect (LONGINT hDC, WinAPI_RECT *lprc);
__EXTERN INTEGER __STDCALL InvertRgn (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL IsBadCodePtr (WinAPI_FARPROC lpfn);
__EXTERN INTEGER __STDCALL IsBadHugeReadPtr (LONGINT lp, INTEGER ucb);
__EXTERN INTEGER __STDCALL IsBadHugeWritePtr (LONGINT lp, INTEGER ucb);
__EXTERN INTEGER __STDCALL IsBadReadPtr (LONGINT lp, INTEGER ucb);
__EXTERN INTEGER __STDCALL IsBadStringPtrA (LONGINT lpsz, INTEGER ucchMax);
__EXTERN INTEGER __STDCALL IsBadStringPtrW (LONGINT lpsz, INTEGER ucchMax);
__EXTERN INTEGER __STDCALL IsBadWritePtr (LONGINT lp, INTEGER ucb);
__EXTERN INTEGER __STDCALL IsCharAlphaA (CHAR ch);
__EXTERN INTEGER __STDCALL IsCharAlphaNumericA (CHAR ch);
__EXTERN INTEGER __STDCALL IsCharAlphaNumericW (SHORTINT ch);
__EXTERN INTEGER __STDCALL IsCharAlphaW (SHORTINT ch);
__EXTERN INTEGER __STDCALL IsCharLowerA (CHAR ch);
__EXTERN INTEGER __STDCALL IsCharLowerW (SHORTINT ch);
__EXTERN INTEGER __STDCALL IsCharUpperA (CHAR ch);
__EXTERN INTEGER __STDCALL IsCharUpperW (SHORTINT ch);
__EXTERN INTEGER __STDCALL IsChild (LONGINT hWndParent, LONGINT hWnd);
__EXTERN INTEGER __STDCALL IsClipboardFormatAvailable (INTEGER format);
__EXTERN INTEGER __STDCALL IsDBCSLeadByte (CHAR TestChar);
__EXTERN INTEGER __STDCALL IsDBCSLeadByteEx (INTEGER CodePage, CHAR TestChar);
__EXTERN INTEGER __STDCALL IsDialogMessageA (LONGINT hDlg, WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL IsDialogMessageW (LONGINT hDlg, WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL IsDlgButtonChecked (LONGINT hDlg, INTEGER nIDButton);
__EXTERN INTEGER __STDCALL IsIconic (LONGINT hWnd);
__EXTERN INTEGER __STDCALL IsMenu (LONGINT hMenu);
__EXTERN INTEGER __STDCALL IsRectEmpty (WinAPI_RECT *lprc);
__EXTERN INTEGER __STDCALL IsTextUnicode (LONGINT lpBuffer, INTEGER cb, SET *lpi);
__EXTERN INTEGER __STDCALL IsValidAcl (WinAPI_ACL *pAcl);
__EXTERN INTEGER __STDCALL IsValidCodePage (INTEGER CodePage);
__EXTERN INTEGER __STDCALL IsValidLocale (INTEGER Locale, SET dwFlags);
__EXTERN INTEGER __STDCALL IsValidSecurityDescriptor (LONGINT pSecurityDescriptor);
__EXTERN INTEGER __STDCALL IsValidSid (LONGINT pSid);
__EXTERN INTEGER __STDCALL IsWindow (LONGINT hWnd);
__EXTERN INTEGER __STDCALL IsWindowEnabled (LONGINT hWnd);
__EXTERN INTEGER __STDCALL IsWindowUnicode (LONGINT hWnd);
__EXTERN INTEGER __STDCALL IsWindowVisible (LONGINT hWnd);
__EXTERN INTEGER __STDCALL IsZoomed (LONGINT hWnd);
__EXTERN INTEGER __STDCALL KillTimer (LONGINT hWnd, INTEGER uIDEvent);
__EXTERN INTEGER __STDCALL LCMapStringA (INTEGER Locale, SET dwMapFlags, LONGINT lpSrcStr, INTEGER cchSrc, LONGINT lpDestStr, INTEGER cchDest);
__EXTERN INTEGER __STDCALL LCMapStringW (INTEGER Locale, SET dwMapFlags, LONGINT lpSrcStr, INTEGER cchSrc, LONGINT lpDestStr, INTEGER cchDest);
__EXTERN INTEGER __STDCALL LPtoDP (LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN void __STDCALL LZClose (INTEGER p0);
__EXTERN INTEGER __STDCALL LZCopy (INTEGER p0, INTEGER p1);
__EXTERN void __STDCALL LZDone (void);
__EXTERN INTEGER __STDCALL LZInit (INTEGER p0);
__EXTERN INTEGER __STDCALL LZOpenFileA (LONGINT p0, WinAPI_OFSTRUCT *p1, SHORTINT p2);
__EXTERN INTEGER __STDCALL LZOpenFileW (LONGINT p0, WinAPI_OFSTRUCT *p1, SHORTINT p2);
__EXTERN INTEGER __STDCALL LZRead (INTEGER p0, LONGINT p1, INTEGER p2);
__EXTERN INTEGER __STDCALL LZSeek (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL LZStart (void);
__EXTERN void __STDCALL LeaveCriticalSection (WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
__EXTERN INTEGER __STDCALL LineDDA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_LINEDDAPROC p4, LONGINT p5);
__EXTERN INTEGER __STDCALL LineTo (LONGINT p0, INTEGER p1, INTEGER p2);
__EXTERN LONGINT __STDCALL LoadAcceleratorsA (LONGINT hInstance, LONGINT lpTableName);
__EXTERN LONGINT __STDCALL LoadAcceleratorsW (LONGINT hInstance, LONGINT lpTableName);
__EXTERN LONGINT __STDCALL LoadBitmapA (LONGINT hInstance, LONGINT lpBitmapName);
__EXTERN LONGINT __STDCALL LoadBitmapW (LONGINT hInstance, LONGINT lpBitmapName);
__EXTERN LONGINT __STDCALL LoadCursorA (LONGINT hInstance, LONGINT lpCursorName);
__EXTERN LONGINT __STDCALL LoadCursorFromFileA (LONGINT lpFileName);
__EXTERN LONGINT __STDCALL LoadCursorFromFileW (LONGINT lpFileName);
__EXTERN LONGINT __STDCALL LoadCursorW (LONGINT hInstance, LONGINT lpCursorName);
__EXTERN LONGINT __STDCALL LoadIconA (LONGINT hInstance, LONGINT lpIconName);
__EXTERN LONGINT __STDCALL LoadIconW (LONGINT hInstance, LONGINT lpIconName);
__EXTERN LONGINT __STDCALL LoadImageA (LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
__EXTERN LONGINT __STDCALL LoadImageW (LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
__EXTERN LONGINT __STDCALL LoadKeyboardLayoutA (LONGINT pwszKLID, SET Flags);
__EXTERN LONGINT __STDCALL LoadKeyboardLayoutW (LONGINT pwszKLID, SET Flags);
__EXTERN LONGINT __STDCALL LoadLibraryA (LONGINT lpLibFileName);
__EXTERN LONGINT __STDCALL LoadLibraryExA (LONGINT lpLibFileName, LONGINT hFile, SET dwFlags);
__EXTERN LONGINT __STDCALL LoadLibraryExW (LONGINT lpLibFileName, LONGINT hFile, SET dwFlags);
__EXTERN LONGINT __STDCALL LoadLibraryW (LONGINT lpLibFileName);
__EXTERN LONGINT __STDCALL LoadMenuA (LONGINT hInstance, LONGINT lpMenuName);
__EXTERN LONGINT __STDCALL LoadMenuIndirectA (WinAPI_PtrMENUTEMPLATEA lpMenuTemplate);
__EXTERN LONGINT __STDCALL LoadMenuIndirectW (WinAPI_PtrMENUTEMPLATEW lpMenuTemplate);
__EXTERN LONGINT __STDCALL LoadMenuW (LONGINT hInstance, LONGINT lpMenuName);
__EXTERN INTEGER __STDCALL LoadModule (LONGINT lpModuleName, LONGINT lpParameterBlock);
__EXTERN LONGINT __STDCALL LoadResource (LONGINT hModule, LONGINT hResInfo);
__EXTERN INTEGER __STDCALL LoadStringA (LONGINT hInstance, INTEGER uID, LONGINT lpBuffer, INTEGER nBufferMax);
__EXTERN INTEGER __STDCALL LoadStringW (LONGINT hInstance, INTEGER uID, LONGINT lpBuffer, INTEGER nBufferMax);
__EXTERN LONGINT __STDCALL LocalAlloc (SET uFlags, LONGINT uBytes);
__EXTERN LONGINT __STDCALL LocalCompact (INTEGER uMinFree);
__EXTERN INTEGER __STDCALL LocalFileTimeToFileTime (WinAPI_FILETIME *lpLocalFileTime, WinAPI_FILETIME *lpFileTime);
__EXTERN INTEGER __STDCALL LocalFlags (LONGINT hMem);
__EXTERN LONGINT __STDCALL LocalFree (LONGINT hMem);
__EXTERN LONGINT __STDCALL LocalHandle (LONGINT pMem);
__EXTERN LONGINT __STDCALL LocalLock (LONGINT hMem);
__EXTERN LONGINT __STDCALL LocalReAlloc (LONGINT hMem, LONGINT uBytes, SET uFlags);
__EXTERN LONGINT __STDCALL LocalShrink (LONGINT hMem, INTEGER cbNewSize);
__EXTERN INTEGER __STDCALL LocalSize (LONGINT hMem);
__EXTERN INTEGER __STDCALL LocalUnlock (LONGINT hMem);
__EXTERN INTEGER __STDCALL LockFile (LONGINT hFile, INTEGER dwFileOffsetLow, INTEGER dwFileOffsetHigh, INTEGER nNumberOfBytesToLockLow, INTEGER nNumberOfBytesToLockHigh);
__EXTERN INTEGER __STDCALL LockFileEx (LONGINT hFile, SET dwFlags, INTEGER dwReserved, INTEGER nNumberOfBytesToLockLow, INTEGER nNumberOfBytesToLockHigh, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN LONGINT __STDCALL LockResource (LONGINT hResData);
__EXTERN LONGINT __STDCALL LockServiceDatabase (LONGINT hSCManager);
__EXTERN INTEGER __STDCALL LockWindowUpdate (LONGINT hWndLock);
__EXTERN INTEGER __STDCALL LogonUserA (LONGINT lpszUsername, LONGINT lpszDomain, LONGINT lpszPassword, INTEGER dwLogonType, INTEGER dwLogonProvider, LONGINT *phToken);
__EXTERN INTEGER __STDCALL LogonUserW (LONGINT lpszUsername, LONGINT lpszDomain, LONGINT lpszPassword, INTEGER dwLogonType, INTEGER dwLogonProvider, LONGINT *phToken);
__EXTERN INTEGER __STDCALL LookupAccountNameA (LONGINT lpSystemName, LONGINT lpAccountName, LONGINT Sid, INTEGER *cbSid, LONGINT ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
__EXTERN INTEGER __STDCALL LookupAccountNameW (LONGINT lpSystemName, LONGINT lpAccountName, LONGINT Sid, INTEGER *cbSid, LONGINT ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
__EXTERN INTEGER __STDCALL LookupAccountSidA (LONGINT lpSystemName, LONGINT Sid, LONGINT Name, INTEGER *cbName, LONGINT ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
__EXTERN INTEGER __STDCALL LookupAccountSidW (LONGINT lpSystemName, LONGINT Sid, LONGINT Name, INTEGER *cbName, LONGINT ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
__EXTERN INTEGER __STDCALL LookupIconIdFromDirectory (CHAR *presbits, INTEGER fIcon);
__EXTERN INTEGER __STDCALL LookupIconIdFromDirectoryEx (CHAR *presbits, INTEGER fIcon, INTEGER cxDesired, INTEGER cyDesired, SET Flags);
__EXTERN INTEGER __STDCALL LookupPrivilegeDisplayNameA (LONGINT lpSystemName, LONGINT lpName, LONGINT lpDisplayName, INTEGER *cbDisplayName, INTEGER *lpLanguageId);
__EXTERN INTEGER __STDCALL LookupPrivilegeDisplayNameW (LONGINT lpSystemName, LONGINT lpName, LONGINT lpDisplayName, INTEGER *cbDisplayName, INTEGER *lpLanguageId);
__EXTERN INTEGER __STDCALL LookupPrivilegeNameA (LONGINT lpSystemName, LONGINT *lpLuid, LONGINT lpName, INTEGER *cbName);
__EXTERN INTEGER __STDCALL LookupPrivilegeNameW (LONGINT lpSystemName, LONGINT *lpLuid, LONGINT lpName, INTEGER *cbName);
__EXTERN INTEGER __STDCALL LookupPrivilegeValueA (LONGINT lpSystemName, LONGINT lpName, LONGINT *lpLuid);
__EXTERN INTEGER __STDCALL LookupPrivilegeValueW (LONGINT lpSystemName, LONGINT lpName, LONGINT *lpLuid);
__EXTERN INTEGER __STDCALL MakeAbsoluteSD (LONGINT pSelfRelativeSecurityDescriptor, LONGINT pAbsoluteSecurityDescriptor, INTEGER *lpdwAbsoluteSecurityDescriptorSize, WinAPI_ACL *pDacl, INTEGER *lpdwDaclSize, WinAPI_ACL *pSacl, INTEGER *lpdwSaclSize, LONGINT pOwner, INTEGER *lpdwOwnerSize, LONGINT pPrimaryGroup, INTEGER *lpdwPrimaryGroupSize);
__EXTERN INTEGER __STDCALL MakeSelfRelativeSD (LONGINT pAbsoluteSecurityDescriptor, LONGINT pSelfRelativeSecurityDescriptor, INTEGER *lpdwBufferLength);
__EXTERN INTEGER __STDCALL MapDialogRect (LONGINT hDlg, WinAPI_RECT *lpRect);
__EXTERN void __STDCALL MapGenericMask (INTEGER *AccessMask, WinAPI_GENERIC_MAPPING *GenericMapping);
__EXTERN LONGINT __STDCALL MapViewOfFile (LONGINT hFileMappingObject, SET dwDesiredAccess, INTEGER dwFileOffsetHigh, INTEGER dwFileOffsetLow, INTEGER dwNumberOfBytesToMap);
__EXTERN LONGINT __STDCALL MapViewOfFileEx (LONGINT hFileMappingObject, SET dwDesiredAccess, INTEGER dwFileOffsetHigh, INTEGER dwFileOffsetLow, INTEGER dwNumberOfBytesToMap, LONGINT lpBaseAddress);
__EXTERN INTEGER __STDCALL MapVirtualKeyA (INTEGER uCode, INTEGER uMapType);
__EXTERN INTEGER __STDCALL MapVirtualKeyExA (INTEGER uCode, INTEGER uMapType, LONGINT dwhkl);
__EXTERN INTEGER __STDCALL MapVirtualKeyExW (INTEGER uCode, INTEGER uMapType, LONGINT dwhkl);
__EXTERN INTEGER __STDCALL MapVirtualKeyW (INTEGER uCode, INTEGER uMapType);
__EXTERN INTEGER __STDCALL MapWindowPoints (LONGINT hWndFrom, LONGINT hWndTo, WinAPI_POINT *lpPoints, INTEGER cPoints);
__EXTERN INTEGER __STDCALL MaskBlt (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, LONGINT p5, INTEGER p6, INTEGER p7, LONGINT p8, INTEGER p9, INTEGER p10, INTEGER p11);
__EXTERN INTEGER __STDCALL MenuItemFromPoint (LONGINT hWnd, LONGINT hMenu, WinAPI_POINT *ptScreen);
__EXTERN INTEGER __STDCALL MessageBeep (SET uType);
__EXTERN INTEGER __STDCALL MessageBoxA (LONGINT hWnd, LONGINT lpText, LONGINT lpCaption, SET uType);
__EXTERN INTEGER __STDCALL MessageBoxExA (LONGINT hWnd, LONGINT lpText, LONGINT lpCaption, SET uType, SHORTINT wLanguageId);
__EXTERN INTEGER __STDCALL MessageBoxExW (LONGINT hWnd, LONGINT lpText, LONGINT lpCaption, SET uType, SHORTINT wLanguageId);
__EXTERN INTEGER __STDCALL MessageBoxIndirectA (WinAPI_MSGBOXPARAMSA *p0);
__EXTERN INTEGER __STDCALL MessageBoxIndirectW (WinAPI_MSGBOXPARAMSW *p0);
__EXTERN INTEGER __STDCALL MessageBoxW (LONGINT hWnd, LONGINT lpText, LONGINT lpCaption, SET uType);
__EXTERN INTEGER __STDCALL ModifyMenuA (LONGINT hMnu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, LONGINT lpNewItem);
__EXTERN INTEGER __STDCALL ModifyMenuW (LONGINT hMnu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, LONGINT lpNewItem);
__EXTERN INTEGER __STDCALL ModifyWorldTransform (LONGINT p0, WinAPI_XFORM *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL MoveFileA (LONGINT lpExistingFileName, LONGINT lpNewFileName);
__EXTERN INTEGER __STDCALL MoveFileExA (LONGINT lpExistingFileName, LONGINT lpNewFileName, SET dwFlags);
__EXTERN INTEGER __STDCALL MoveFileExW (LONGINT lpExistingFileName, LONGINT lpNewFileName, SET dwFlags);
__EXTERN INTEGER __STDCALL MoveFileW (LONGINT lpExistingFileName, LONGINT lpNewFileName);
__EXTERN INTEGER __STDCALL MoveToEx (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN INTEGER __STDCALL MoveWindow (LONGINT hWnd, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER bRepaint);
__EXTERN INTEGER __STDCALL MsgWaitForMultipleObjects (INTEGER nCount, LONGINT *pHandles, INTEGER fWaitAll, INTEGER dwMilliseconds, INTEGER dwWakeMask);
__EXTERN INTEGER __STDCALL MsgWaitForMultipleObjectsEx (INTEGER nCount, LONGINT *pHandles, INTEGER dwMilliseconds, INTEGER dwWakeMask, SET dwFlags);
__EXTERN INTEGER __STDCALL MulDiv (INTEGER nNumber, INTEGER nNumerator, INTEGER nDenominator);
__EXTERN INTEGER __STDCALL MultiByteToWideChar (INTEGER CodePage, SET dwFlags, LONGINT lpMultiByteStr, INTEGER cchMultiByte, LONGINT lpWideCharStr, INTEGER cchWideChar);
__EXTERN INTEGER __STDCALL NotifyBootConfigStatus (INTEGER BootAcceptable);
__EXTERN INTEGER __STDCALL NotifyChangeEventLog (LONGINT hEventLog, LONGINT hEvent);
__EXTERN INTEGER __STDCALL ObjectCloseAuditAlarmA (LONGINT SubsystemName, LONGINT HandleId, INTEGER GenerateOnClose);
__EXTERN INTEGER __STDCALL ObjectCloseAuditAlarmW (LONGINT SubsystemName, LONGINT HandleId, INTEGER GenerateOnClose);
__EXTERN INTEGER __STDCALL ObjectOpenAuditAlarmA (LONGINT SubsystemName, LONGINT HandleId, LONGINT ObjectTypeName, LONGINT ObjectName, LONGINT pSecurityDescriptor, LONGINT ClientToken, SET DesiredAccess, INTEGER GrantedAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER ObjectCreation, INTEGER AccessGranted, INTEGER *GenerateOnClose);
__EXTERN INTEGER __STDCALL ObjectOpenAuditAlarmW (LONGINT SubsystemName, LONGINT HandleId, LONGINT ObjectTypeName, LONGINT ObjectName, LONGINT pSecurityDescriptor, LONGINT ClientToken, SET DesiredAccess, INTEGER GrantedAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER ObjectCreation, INTEGER AccessGranted, INTEGER *GenerateOnClose);
__EXTERN INTEGER __STDCALL ObjectPrivilegeAuditAlarmA (LONGINT SubsystemName, LONGINT HandleId, LONGINT ClientToken, SET DesiredAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
__EXTERN INTEGER __STDCALL ObjectPrivilegeAuditAlarmW (LONGINT SubsystemName, LONGINT HandleId, LONGINT ClientToken, SET DesiredAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
__EXTERN INTEGER __STDCALL OemKeyScan (SHORTINT wOemChar);
__EXTERN INTEGER __STDCALL OemToCharA (LONGINT lpszSrc, LONGINT lpszDst);
__EXTERN INTEGER __STDCALL OemToCharBuffA (LONGINT lpszSrc, LONGINT lpszDst, INTEGER cchDstLength);
__EXTERN INTEGER __STDCALL OemToCharBuffW (LONGINT lpszSrc, LONGINT lpszDst, INTEGER cchDstLength);
__EXTERN INTEGER __STDCALL OemToCharW (LONGINT lpszSrc, LONGINT lpszDst);
__EXTERN INTEGER __STDCALL OffsetClipRgn (LONGINT p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL OffsetRect (WinAPI_RECT *lprc, INTEGER dx, INTEGER dy);
__EXTERN INTEGER __STDCALL OffsetRgn (LONGINT p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL OffsetViewportOrgEx (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN INTEGER __STDCALL OffsetWindowOrgEx (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN LONGINT __STDCALL OpenBackupEventLogA (LONGINT lpUNCServerName, LONGINT lpFileName);
__EXTERN LONGINT __STDCALL OpenBackupEventLogW (LONGINT lpUNCServerName, LONGINT lpFileName);
__EXTERN INTEGER __STDCALL OpenClipboard (LONGINT hWndNewOwner);
__EXTERN LONGINT __STDCALL OpenDesktopA (LONGINT lpszDesktop, SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
__EXTERN LONGINT __STDCALL OpenDesktopW (LONGINT lpszDesktop, SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
__EXTERN LONGINT __STDCALL OpenEventA (SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
__EXTERN LONGINT __STDCALL OpenEventLogA (LONGINT lpUNCServerName, LONGINT lpSourceName);
__EXTERN LONGINT __STDCALL OpenEventLogW (LONGINT lpUNCServerName, LONGINT lpSourceName);
__EXTERN LONGINT __STDCALL OpenEventW (SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
__EXTERN INTEGER __STDCALL OpenFile (LONGINT lpFileName, WinAPI_OFSTRUCT *lpReOpenBuff, SET uStyle);
__EXTERN LONGINT __STDCALL OpenFileMappingA (SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
__EXTERN LONGINT __STDCALL OpenFileMappingW (SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
__EXTERN INTEGER __STDCALL OpenIcon (LONGINT hWnd);
__EXTERN LONGINT __STDCALL OpenInputDesktop (SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
__EXTERN LONGINT __STDCALL OpenMutexA (SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
__EXTERN LONGINT __STDCALL OpenMutexW (SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
__EXTERN INTEGER __STDCALL OpenPrinterA (LONGINT pPrinterName, LONGINT *phPrinter, WinAPI_PRINTER_DEFAULTSA *pDefault);
__EXTERN INTEGER __STDCALL OpenPrinterW (LONGINT pPrinterName, LONGINT *phPrinter, WinAPI_PRINTER_DEFAULTSW *pDefault);
__EXTERN LONGINT __STDCALL OpenProcess (SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER dwProcessId);
__EXTERN INTEGER __STDCALL OpenProcessToken (LONGINT ProcessHandle, SET DesiredAccess, LONGINT *TokenHandle);
__EXTERN LONGINT __STDCALL OpenSCManagerA (LONGINT lpMachineName, LONGINT lpDatabaseName, SET dwDesiredAccess);
__EXTERN LONGINT __STDCALL OpenSCManagerW (LONGINT lpMachineName, LONGINT lpDatabaseName, SET dwDesiredAccess);
__EXTERN LONGINT __STDCALL OpenSemaphoreA (SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
__EXTERN LONGINT __STDCALL OpenSemaphoreW (SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
__EXTERN LONGINT __STDCALL OpenServiceA (LONGINT hSCManager, LONGINT lpServiceName, SET dwDesiredAccess);
__EXTERN LONGINT __STDCALL OpenServiceW (LONGINT hSCManager, LONGINT lpServiceName, SET dwDesiredAccess);
__EXTERN INTEGER __STDCALL OpenThreadToken (LONGINT ThreadHandle, SET DesiredAccess, INTEGER OpenAsSelf, LONGINT *TokenHandle);
__EXTERN LONGINT __STDCALL OpenWaitableTimerA (SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpTimerName);
__EXTERN LONGINT __STDCALL OpenWaitableTimerW (SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpTimerName);
__EXTERN LONGINT __STDCALL OpenWindowStationA (LONGINT lpszWinSta, INTEGER fInherit, SET dwDesiredAccess);
__EXTERN LONGINT __STDCALL OpenWindowStationW (LONGINT lpszWinSta, INTEGER fInherit, SET dwDesiredAccess);
__EXTERN void __STDCALL OutputDebugStringA (LONGINT lpOutputString);
__EXTERN void __STDCALL OutputDebugStringW (LONGINT lpOutputString);
__EXTERN INTEGER __STDCALL PackDDElParam (INTEGER msg, INTEGER uiLo, INTEGER uiHi);
__EXTERN INTEGER __STDCALL PaintDesktop (LONGINT hdc);
__EXTERN INTEGER __STDCALL PaintRgn (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL PatBlt (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
__EXTERN LONGINT __STDCALL PathToRegion (LONGINT p0);
__EXTERN INTEGER __STDCALL PeekConsoleInputA (LONGINT hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
__EXTERN INTEGER __STDCALL PeekConsoleInputW (LONGINT hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
__EXTERN INTEGER __STDCALL PeekMessageA (WinAPI_MSG *lpMsg, LONGINT hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax, INTEGER wRemoveMsg);
__EXTERN INTEGER __STDCALL PeekMessageW (WinAPI_MSG *lpMsg, LONGINT hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax, INTEGER wRemoveMsg);
__EXTERN INTEGER __STDCALL PeekNamedPipe (LONGINT hNamedPipe, LONGINT lpBuffer, INTEGER nBufferSize, INTEGER *lpBytesRead, INTEGER *lpTotalBytesAvail, INTEGER *lpBytesLeftThisMessage);
__EXTERN INTEGER __STDCALL Pie (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
__EXTERN INTEGER __STDCALL PlayEnhMetaFile (LONGINT p0, LONGINT p1, WinAPI_RECT *p2);
__EXTERN INTEGER __STDCALL PlayEnhMetaFileRecord (LONGINT p0, WinAPI_HANDLETABLE *p1, WinAPI_ENHMETARECORD *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL PlayMetaFile (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL PlayMetaFileRecord (LONGINT p0, WinAPI_HANDLETABLE *p1, WinAPI_METARECORD *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL PlgBlt (LONGINT p0, WinAPI_POINT *p1, LONGINT p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, LONGINT p7, INTEGER p8, INTEGER p9);
__EXTERN INTEGER __STDCALL PolyBezier (LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PolyBezierTo (LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PolyDraw (LONGINT p0, WinAPI_POINT *p1, CHAR *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL PolyPolygon (LONGINT p0, WinAPI_POINT *p1, INTEGER *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL PolyPolyline (LONGINT p0, WinAPI_POINT *p1, INTEGER *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL PolyTextOutA (LONGINT p0, WinAPI_POLYTEXTA *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PolyTextOutW (LONGINT p0, WinAPI_POLYTEXTW *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL Polygon (LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL Polyline (LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PolylineTo (LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PostMessageA (LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN INTEGER __STDCALL PostMessageW (LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN INTEGER __STDCALL PostQueuedCompletionStatus (LONGINT CompletionPort, INTEGER dwNumberOfBytesTransferred, INTEGER dwCompletionKey, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN void __STDCALL PostQuitMessage (INTEGER nExitCode);
__EXTERN INTEGER __STDCALL PostThreadMessageA (INTEGER idThread, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN INTEGER __STDCALL PostThreadMessageW (INTEGER idThread, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN INTEGER __STDCALL PrepareTape (LONGINT hDevice, INTEGER dwOperation, INTEGER bImmediate);
__EXTERN INTEGER __STDCALL PrinterMessageBoxA (LONGINT hPrinter, INTEGER Error, LONGINT hWnd, LONGINT pText, LONGINT pCaption, INTEGER dwType);
__EXTERN INTEGER __STDCALL PrinterMessageBoxW (LONGINT hPrinter, INTEGER Error, LONGINT hWnd, LONGINT pText, LONGINT pCaption, INTEGER dwType);
__EXTERN INTEGER __STDCALL PrinterProperties (LONGINT hWnd, LONGINT hPrinter);
__EXTERN INTEGER __STDCALL PrivilegeCheck (LONGINT ClientToken, WinAPI_PRIVILEGE_SET *RequiredPrivileges, INTEGER *pfResult);
__EXTERN INTEGER __STDCALL PrivilegedServiceAuditAlarmA (LONGINT SubsystemName, LONGINT ServiceName, LONGINT ClientToken, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
__EXTERN INTEGER __STDCALL PrivilegedServiceAuditAlarmW (LONGINT SubsystemName, LONGINT ServiceName, LONGINT ClientToken, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
__EXTERN INTEGER __STDCALL PropertySheetA (WinAPI_PROPSHEETHEADERA *p0);
__EXTERN INTEGER __STDCALL PropertySheetW (WinAPI_PROPSHEETHEADERW *p0);
__EXTERN INTEGER __STDCALL PtInRect (WinAPI_RECT *lprc, WinAPI_POINT *pt);
__EXTERN INTEGER __STDCALL PtInRegion (LONGINT p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PtVisible (LONGINT p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PulseEvent (LONGINT hEvent);
__EXTERN INTEGER __STDCALL PurgeComm (LONGINT hFile, SET dwFlags);
__EXTERN INTEGER __STDCALL QueryDosDeviceA (LONGINT lpDeviceName, LONGINT lpTargetPath, INTEGER ucchMax);
__EXTERN INTEGER __STDCALL QueryDosDeviceW (LONGINT lpDeviceName, LONGINT lpTargetPath, INTEGER ucchMax);
__EXTERN INTEGER __STDCALL QueryPerformanceCounter (LONGINT *lpPerformanceCount);
__EXTERN INTEGER __STDCALL QueryPerformanceFrequency (LONGINT *lpFrequency);
__EXTERN INTEGER __STDCALL QueryServiceConfigA (LONGINT hService, WinAPI_QUERY_SERVICE_CONFIGA *lpServiceConfig, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
__EXTERN INTEGER __STDCALL QueryServiceConfigW (LONGINT hService, WinAPI_QUERY_SERVICE_CONFIGW *lpServiceConfig, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
__EXTERN INTEGER __STDCALL QueryServiceLockStatusA (LONGINT hSCManager, WinAPI_QUERY_SERVICE_LOCK_STATUSA *lpLockStatus, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
__EXTERN INTEGER __STDCALL QueryServiceLockStatusW (LONGINT hSCManager, WinAPI_QUERY_SERVICE_LOCK_STATUSW *lpLockStatus, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
__EXTERN INTEGER __STDCALL QueryServiceObjectSecurity (LONGINT hService, SET dwSecurityInformation, LONGINT lpSecurityDescriptor, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
__EXTERN INTEGER __STDCALL QueryServiceStatus (LONGINT hService, WinAPI_SERVICE_STATUS *lpServiceStatus);
__EXTERN INTEGER __STDCALL QueueUserAPC (WinAPI_APCFUNC pfnAPC, LONGINT hThread, INTEGER dwData);
__EXTERN void __STDCALL RaiseException (INTEGER dwExceptionCode, INTEGER dwExceptionFlags, INTEGER nNumberOfArguments, INTEGER *lpArguments);
__EXTERN INTEGER __STDCALL ReadConsoleA (LONGINT hConsoleInput, LONGINT lpBuffer, INTEGER nNumberOfCharsToRead, INTEGER *lpNumberOfCharsRead, LONGINT lpReserved);
__EXTERN INTEGER __STDCALL ReadConsoleInputA (LONGINT hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
__EXTERN INTEGER __STDCALL ReadConsoleInputW (LONGINT hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
__EXTERN INTEGER __STDCALL ReadConsoleOutputA (LONGINT hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD *dwBufferSize, WinAPI_COORD *dwBufferCoord, WinAPI_SMALL_RECT *lpReadRegion);
__EXTERN INTEGER __STDCALL ReadConsoleOutputAttribute (LONGINT hConsoleOutput, SHORTINT *lpAttribute, INTEGER nLength, WinAPI_COORD *dwReadCoord, INTEGER *lpNumberOfAttrsRead);
__EXTERN INTEGER __STDCALL ReadConsoleOutputCharacterA (LONGINT hConsoleOutput, LONGINT lpCharacter, INTEGER nLength, WinAPI_COORD *dwReadCoord, INTEGER *lpNumberOfCharsRead);
__EXTERN INTEGER __STDCALL ReadConsoleOutputCharacterW (LONGINT hConsoleOutput, LONGINT lpCharacter, INTEGER nLength, WinAPI_COORD *dwReadCoord, INTEGER *lpNumberOfCharsRead);
__EXTERN INTEGER __STDCALL ReadConsoleOutputW (LONGINT hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD *dwBufferSize, WinAPI_COORD *dwBufferCoord, WinAPI_SMALL_RECT *lpReadRegion);
__EXTERN INTEGER __STDCALL ReadConsoleW (LONGINT hConsoleInput, LONGINT lpBuffer, INTEGER nNumberOfCharsToRead, INTEGER *lpNumberOfCharsRead, LONGINT lpReserved);
__EXTERN INTEGER __STDCALL ReadDirectoryChangesW (LONGINT hDirectory, LONGINT lpBuffer, INTEGER nBufferLength, INTEGER bWatchSubtree, SET dwNotifyFilter, INTEGER *lpBytesReturned, WinAPI_OVERLAPPED *lpOverlapped, WinAPI_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
__EXTERN INTEGER __STDCALL ReadEventLogA (LONGINT hEventLog, SET dwReadFlags, INTEGER dwRecordOffset, LONGINT lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *pnBytesRead, INTEGER *pnMinNumberOfBytesNeeded);
__EXTERN INTEGER __STDCALL ReadEventLogW (LONGINT hEventLog, SET dwReadFlags, INTEGER dwRecordOffset, LONGINT lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *pnBytesRead, INTEGER *pnMinNumberOfBytesNeeded);
__EXTERN INTEGER __STDCALL ReadFile (LONGINT hFile, LONGINT lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *lpNumberOfBytesRead, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL ReadFileEx (LONGINT hFile, LONGINT lpBuffer, INTEGER nNumberOfBytesToRead, WinAPI_OVERLAPPED *lpOverlapped, WinAPI_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
__EXTERN INTEGER __STDCALL ReadPrinter (LONGINT hPrinter, LONGINT pBuf, INTEGER cbBuf, INTEGER *pNoBytesRead);
__EXTERN INTEGER __STDCALL ReadProcessMemory (LONGINT hProcess, LONGINT lpBaseAddress, LONGINT lpBuffer, INTEGER nSize, INTEGER *lpNumberOfBytesRead);
__EXTERN INTEGER __STDCALL RealizePalette (LONGINT p0);
__EXTERN INTEGER __STDCALL RectInRegion (LONGINT p0, WinAPI_RECT *p1);
__EXTERN INTEGER __STDCALL RectVisible (LONGINT p0, WinAPI_RECT *p1);
__EXTERN INTEGER __STDCALL Rectangle (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL RedrawWindow (LONGINT hWnd, WinAPI_RECT *lprcUpdate, LONGINT hrgnUpdate, SET flags);
__EXTERN INTEGER __STDCALL RegCloseKey (LONGINT hKey);
__EXTERN INTEGER __STDCALL RegConnectRegistryA (LONGINT lpMachineName, LONGINT hKey, LONGINT *phkResult);
__EXTERN INTEGER __STDCALL RegConnectRegistryW (LONGINT lpMachineName, LONGINT hKey, LONGINT *phkResult);
__EXTERN INTEGER __STDCALL RegCreateKeyA (LONGINT hKey, LONGINT lpSubKey, LONGINT *phkResult);
__EXTERN INTEGER __STDCALL RegCreateKeyExA (LONGINT hKey, LONGINT lpSubKey, INTEGER Reserved, LONGINT lpClass, SET dwOptions, SET samDesired, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, LONGINT *phkResult, INTEGER *lpdwDisposition);
__EXTERN INTEGER __STDCALL RegCreateKeyExW (LONGINT hKey, LONGINT lpSubKey, INTEGER Reserved, LONGINT lpClass, SET dwOptions, SET samDesired, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, LONGINT *phkResult, INTEGER *lpdwDisposition);
__EXTERN INTEGER __STDCALL RegCreateKeyW (LONGINT hKey, LONGINT lpSubKey, LONGINT *phkResult);
__EXTERN INTEGER __STDCALL RegDeleteKeyA (LONGINT hKey, LONGINT lpSubKey);
__EXTERN INTEGER __STDCALL RegDeleteKeyW (LONGINT hKey, LONGINT lpSubKey);
__EXTERN INTEGER __STDCALL RegDeleteValueA (LONGINT hKey, LONGINT lpValueName);
__EXTERN INTEGER __STDCALL RegDeleteValueW (LONGINT hKey, LONGINT lpValueName);
__EXTERN INTEGER __STDCALL RegEnumKeyA (LONGINT hKey, INTEGER dwIndex, LONGINT lpName, INTEGER cbName);
__EXTERN INTEGER __STDCALL RegEnumKeyExA (LONGINT hKey, INTEGER dwIndex, LONGINT lpName, INTEGER *lpcbName, INTEGER *lpReserved, LONGINT lpClass, INTEGER *lpcbClass, WinAPI_FILETIME *lpftLastWriteTime);
__EXTERN INTEGER __STDCALL RegEnumKeyExW (LONGINT hKey, INTEGER dwIndex, LONGINT lpName, INTEGER *lpcbName, INTEGER *lpReserved, LONGINT lpClass, INTEGER *lpcbClass, WinAPI_FILETIME *lpftLastWriteTime);
__EXTERN INTEGER __STDCALL RegEnumKeyW (LONGINT hKey, INTEGER dwIndex, LONGINT lpName, INTEGER cbName);
__EXTERN INTEGER __STDCALL RegEnumValueA (LONGINT hKey, INTEGER dwIndex, LONGINT lpValueName, INTEGER *lpcbValueName, INTEGER *lpReserved, INTEGER *lpType, LONGINT lpData, INTEGER *lpcbData);
__EXTERN INTEGER __STDCALL RegEnumValueW (LONGINT hKey, INTEGER dwIndex, LONGINT lpValueName, INTEGER *lpcbValueName, INTEGER *lpReserved, INTEGER *lpType, LONGINT lpData, INTEGER *lpcbData);
__EXTERN INTEGER __STDCALL RegFlushKey (LONGINT hKey);
__EXTERN INTEGER __STDCALL RegGetKeySecurity (LONGINT hKey, SET SecurityInformation, LONGINT pSecurityDescriptor, INTEGER *lpcbSecurityDescriptor);
__EXTERN INTEGER __STDCALL RegLoadKeyA (LONGINT hKey, LONGINT lpSubKey, LONGINT lpFile);
__EXTERN INTEGER __STDCALL RegLoadKeyW (LONGINT hKey, LONGINT lpSubKey, LONGINT lpFile);
__EXTERN INTEGER __STDCALL RegNotifyChangeKeyValue (LONGINT hKey, INTEGER bWatchSubtree, SET dwNotifyFilter, LONGINT hEvent, INTEGER fAsynchronus);
__EXTERN INTEGER __STDCALL RegOpenKeyA (LONGINT hKey, LONGINT lpSubKey, LONGINT *phkResult);
__EXTERN INTEGER __STDCALL RegOpenKeyExA (LONGINT hKey, LONGINT lpSubKey, INTEGER ulOptions, SET samDesired, LONGINT *phkResult);
__EXTERN INTEGER __STDCALL RegOpenKeyExW (LONGINT hKey, LONGINT lpSubKey, INTEGER ulOptions, SET samDesired, LONGINT *phkResult);
__EXTERN INTEGER __STDCALL RegOpenKeyW (LONGINT hKey, LONGINT lpSubKey, LONGINT *phkResult);
__EXTERN INTEGER __STDCALL RegQueryInfoKeyA (LONGINT hKey, LONGINT lpClass, INTEGER *lpcbClass, INTEGER *lpReserved, INTEGER *lpcSubKeys, INTEGER *lpcbMaxSubKeyLen, INTEGER *lpcbMaxClassLen, INTEGER *lpcValues, INTEGER *lpcbMaxValueNameLen, INTEGER *lpcbMaxValueLen, INTEGER *lpcbSecurityDescriptor, WinAPI_FILETIME *lpftLastWriteTime);
__EXTERN INTEGER __STDCALL RegQueryInfoKeyW (LONGINT hKey, LONGINT lpClass, INTEGER *lpcbClass, INTEGER *lpReserved, INTEGER *lpcSubKeys, INTEGER *lpcbMaxSubKeyLen, INTEGER *lpcbMaxClassLen, INTEGER *lpcValues, INTEGER *lpcbMaxValueNameLen, INTEGER *lpcbMaxValueLen, INTEGER *lpcbSecurityDescriptor, WinAPI_FILETIME *lpftLastWriteTime);
__EXTERN INTEGER __STDCALL RegQueryMultipleValuesA (LONGINT hKey, WinAPI_VALENTA *val_list, INTEGER num_vals, LONGINT lpValueBuf, INTEGER *ldwTotsize);
__EXTERN INTEGER __STDCALL RegQueryMultipleValuesW (LONGINT hKey, WinAPI_VALENTW *val_list, INTEGER num_vals, LONGINT lpValueBuf, INTEGER *ldwTotsize);
__EXTERN INTEGER __STDCALL RegQueryValueA (LONGINT hKey, LONGINT lpSubKey, LONGINT lpValue, INTEGER *lpcbValue);
__EXTERN INTEGER __STDCALL RegQueryValueExA (LONGINT hKey, LONGINT lpValueName, INTEGER *lpReserved, INTEGER *lpType, LONGINT lpData, INTEGER *lpcbData);
__EXTERN INTEGER __STDCALL RegQueryValueExW (LONGINT hKey, LONGINT lpValueName, INTEGER *lpReserved, INTEGER *lpType, LONGINT lpData, INTEGER *lpcbData);
__EXTERN INTEGER __STDCALL RegQueryValueW (LONGINT hKey, LONGINT lpSubKey, LONGINT lpValue, INTEGER *lpcbValue);
__EXTERN INTEGER __STDCALL RegReplaceKeyA (LONGINT hKey, LONGINT lpSubKey, LONGINT lpNewFile, LONGINT lpOldFile);
__EXTERN INTEGER __STDCALL RegReplaceKeyW (LONGINT hKey, LONGINT lpSubKey, LONGINT lpNewFile, LONGINT lpOldFile);
__EXTERN INTEGER __STDCALL RegRestoreKeyA (LONGINT hKey, LONGINT lpFile, SET dwFlags);
__EXTERN INTEGER __STDCALL RegRestoreKeyW (LONGINT hKey, LONGINT lpFile, SET dwFlags);
__EXTERN INTEGER __STDCALL RegSaveKeyA (LONGINT hKey, LONGINT lpFile, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL RegSaveKeyW (LONGINT hKey, LONGINT lpFile, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL RegSetKeySecurity (LONGINT hKey, SET SecurityInformation, LONGINT pSecurityDescriptor);
__EXTERN INTEGER __STDCALL RegSetValueA (LONGINT hKey, LONGINT lpSubKey, INTEGER dwType, LONGINT lpData, INTEGER cbData);
__EXTERN INTEGER __STDCALL RegSetValueExA (LONGINT hKey, LONGINT lpValueName, INTEGER Reserved, INTEGER dwType, LONGINT lpData, INTEGER cbData);
__EXTERN INTEGER __STDCALL RegSetValueExW (LONGINT hKey, LONGINT lpValueName, INTEGER Reserved, INTEGER dwType, LONGINT lpData, INTEGER cbData);
__EXTERN INTEGER __STDCALL RegSetValueW (LONGINT hKey, LONGINT lpSubKey, INTEGER dwType, LONGINT lpData, INTEGER cbData);
__EXTERN INTEGER __STDCALL RegUnLoadKeyA (LONGINT hKey, LONGINT lpSubKey);
__EXTERN INTEGER __STDCALL RegUnLoadKeyW (LONGINT hKey, LONGINT lpSubKey);
__EXTERN SHORTINT __STDCALL RegisterClassA (WinAPI_WNDCLASSA *lpWndClass);
__EXTERN SHORTINT __STDCALL RegisterClassExA (WinAPI_WNDCLASSEXA *p0);
__EXTERN SHORTINT __STDCALL RegisterClassExW (WinAPI_WNDCLASSEXW *p0);
__EXTERN SHORTINT __STDCALL RegisterClassW (WinAPI_WNDCLASSW *lpWndClass);
__EXTERN INTEGER __STDCALL RegisterClipboardFormatA (LONGINT lpszFormat);
__EXTERN INTEGER __STDCALL RegisterClipboardFormatW (LONGINT lpszFormat);
__EXTERN LONGINT __STDCALL RegisterEventSourceA (LONGINT lpUNCServerName, LONGINT lpSourceName);
__EXTERN LONGINT __STDCALL RegisterEventSourceW (LONGINT lpUNCServerName, LONGINT lpSourceName);
__EXTERN INTEGER __STDCALL RegisterHotKey (LONGINT hWnd, INTEGER id, INTEGER fsModifiers, INTEGER vk);
__EXTERN INTEGER __STDCALL RegisterServiceCtrlHandlerA (LONGINT lpServiceName, WinAPI_HANDLER_FUNCTION lpHandlerProc);
__EXTERN INTEGER __STDCALL RegisterServiceCtrlHandlerW (LONGINT lpServiceName, WinAPI_HANDLER_FUNCTION lpHandlerProc);
__EXTERN INTEGER __STDCALL RegisterWindowMessageA (LONGINT lpString);
__EXTERN INTEGER __STDCALL RegisterWindowMessageW (LONGINT lpString);
__EXTERN INTEGER __STDCALL ReleaseCapture (void);
__EXTERN INTEGER __STDCALL ReleaseDC (LONGINT hWnd, LONGINT hDC);
__EXTERN INTEGER __STDCALL ReleaseMutex (LONGINT hMutex);
__EXTERN INTEGER __STDCALL ReleaseSemaphore (LONGINT hSemaphore, INTEGER lReleaseCount, INTEGER *lpPreviousCount);
__EXTERN INTEGER __STDCALL RemoveDirectoryA (LONGINT lpPathName);
__EXTERN INTEGER __STDCALL RemoveDirectoryW (LONGINT lpPathName);
__EXTERN INTEGER __STDCALL RemoveFontResourceA (LONGINT p0);
__EXTERN INTEGER __STDCALL RemoveFontResourceW (LONGINT p0);
__EXTERN INTEGER __STDCALL RemoveMenu (LONGINT hMenu, INTEGER uPosition, SET uFlags);
__EXTERN LONGINT __STDCALL RemovePropA (LONGINT hWnd, LONGINT lpString);
__EXTERN LONGINT __STDCALL RemovePropW (LONGINT hWnd, LONGINT lpString);
__EXTERN INTEGER __STDCALL ReplyMessage (LONGINT lResult);
__EXTERN INTEGER __STDCALL ReportEventA (LONGINT hEventLog, SHORTINT wType, SHORTINT wCategory, INTEGER dwEventID, LONGINT lpUserSid, SHORTINT wNumStrings, INTEGER dwDataSize, LONGINT *lpStrings, LONGINT lpRawData);
__EXTERN INTEGER __STDCALL ReportEventW (LONGINT hEventLog, SHORTINT wType, SHORTINT wCategory, INTEGER dwEventID, LONGINT lpUserSid, SHORTINT wNumStrings, INTEGER dwDataSize, LONGINT lpStrings, LONGINT lpRawData);
__EXTERN LONGINT __STDCALL ResetDCA (LONGINT p0, WinAPI_DEVMODEA *p1);
__EXTERN LONGINT __STDCALL ResetDCW (LONGINT p0, WinAPI_DEVMODEW *p1);
__EXTERN INTEGER __STDCALL ResetEvent (LONGINT hEvent);
__EXTERN INTEGER __STDCALL ResetPrinterA (LONGINT hPrinter, WinAPI_PRINTER_DEFAULTSA *pDefault);
__EXTERN INTEGER __STDCALL ResetPrinterW (LONGINT hPrinter, WinAPI_PRINTER_DEFAULTSW *pDefault);
__EXTERN INTEGER __STDCALL ResizePalette (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL RestoreDC (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL ResumeThread (LONGINT hThread);
__EXTERN INTEGER __STDCALL ReuseDDElParam (INTEGER lParam, INTEGER msgIn, INTEGER msgOut, INTEGER uiLo, INTEGER uiHi);
__EXTERN INTEGER __STDCALL RevertToSelf (void);
__EXTERN INTEGER __STDCALL RoundRect (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6);
__EXTERN void __STDCALL RtlUnwind (LONGINT targetFrame, INTEGER targetIp, WinAPI_PtrEXCEPTION_RECORD excpRec, INTEGER retVal);
__EXTERN INTEGER __STDCALL SHAppBarMessage (INTEGER dwMessage, WinAPI_APPBARDATA *pData);
__EXTERN INTEGER __STDCALL SHFileOperationA (WinAPI_SHFILEOPSTRUCTA *lpFileOp);
__EXTERN INTEGER __STDCALL SHFileOperationW (WinAPI_SHFILEOPSTRUCTW *lpFileOp);
__EXTERN void __STDCALL SHFreeNameMappings (LONGINT hNameMappings);
__EXTERN INTEGER __STDCALL SHGetFileInfoA (LONGINT pszPath, SET dwFileAttributes, WinAPI_SHFILEINFOA *psfi, INTEGER cbFileInfo, SET uFlags);
__EXTERN INTEGER __STDCALL SHGetFileInfoW (LONGINT pszPath, SET dwFileAttributes, WinAPI_SHFILEINFOW *psfi, INTEGER cbFileInfo, SET uFlags);
__EXTERN INTEGER __STDCALL SHGetNewLinkInfoA (LONGINT pszLinkTo, LONGINT pszDir, LONGINT pszName, INTEGER *pfMustCopy, SET uFlags);
__EXTERN INTEGER __STDCALL SHGetNewLinkInfoW (LONGINT pszLinkTo, LONGINT pszDir, LONGINT pszName, INTEGER *pfMustCopy, SET uFlags);
__EXTERN INTEGER __STDCALL SaveDC (LONGINT p0);
__EXTERN INTEGER __STDCALL ScaleViewportExtEx (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_SIZE *p5);
__EXTERN INTEGER __STDCALL ScaleWindowExtEx (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_SIZE *p5);
__EXTERN INTEGER __STDCALL ScheduleJob (LONGINT hPrinter, INTEGER JobId);
__EXTERN INTEGER __STDCALL ScreenToClient (LONGINT hWnd, WinAPI_POINT *lpPoint);
__EXTERN INTEGER __STDCALL ScrollConsoleScreenBufferA (LONGINT hConsoleOutput, WinAPI_SMALL_RECT *lpScrollRectangle, WinAPI_SMALL_RECT *lpClipRectangle, WinAPI_COORD *dwDestinationOrigin, WinAPI_CHAR_INFO *lpFill);
__EXTERN INTEGER __STDCALL ScrollConsoleScreenBufferW (LONGINT hConsoleOutput, WinAPI_SMALL_RECT *lpScrollRectangle, WinAPI_SMALL_RECT *lpClipRectangle, WinAPI_COORD *dwDestinationOrigin, WinAPI_CHAR_INFO *lpFill);
__EXTERN INTEGER __STDCALL ScrollDC (LONGINT hDC, INTEGER dx, INTEGER dy, WinAPI_RECT *lprcScroll, WinAPI_RECT *lprcClip, LONGINT hrgnUpdate, WinAPI_RECT *lprcUpdate);
__EXTERN INTEGER __STDCALL ScrollWindow (LONGINT hWnd, INTEGER XAmount, INTEGER YAmount, WinAPI_RECT *lpRect, WinAPI_RECT *lpClipRect);
__EXTERN INTEGER __STDCALL ScrollWindowEx (LONGINT hWnd, INTEGER dx, INTEGER dy, WinAPI_RECT *prcScroll, WinAPI_RECT *prcClip, LONGINT hrgnUpdate, WinAPI_RECT *prcUpdate, SET flags);
__EXTERN INTEGER __STDCALL SearchPathA (LONGINT lpPath, LONGINT lpFileName, LONGINT lpExtension, INTEGER nBufferLength, LONGINT lpBuffer, LONGINT *lpFilePart);
__EXTERN INTEGER __STDCALL SearchPathW (LONGINT lpPath, LONGINT lpFileName, LONGINT lpExtension, INTEGER nBufferLength, LONGINT lpBuffer, LONGINT *lpFilePart);
__EXTERN INTEGER __STDCALL SelectClipPath (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SelectClipRgn (LONGINT p0, LONGINT p1);
__EXTERN LONGINT __STDCALL SelectObject (LONGINT p0, LONGINT p1);
__EXTERN LONGINT __STDCALL SelectPalette (LONGINT p0, LONGINT p1, INTEGER p2);
__EXTERN INTEGER __STDCALL SendDlgItemMessageA (LONGINT hDlg, INTEGER nIDDlgItem, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN INTEGER __STDCALL SendDlgItemMessageW (LONGINT hDlg, INTEGER nIDDlgItem, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN LONGINT __STDCALL SendMessageA (LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN INTEGER __STDCALL SendMessageCallbackA (LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam, WinAPI_SENDASYNCPROC lpResultCallBack, INTEGER dwData);
__EXTERN INTEGER __STDCALL SendMessageCallbackW (LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam, WinAPI_SENDASYNCPROC lpResultCallBack, INTEGER dwData);
__EXTERN LONGINT __STDCALL SendMessageTimeoutA (LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam, SET fuFlags, INTEGER uTimeout, INTEGER *lpdwResult);
__EXTERN LONGINT __STDCALL SendMessageTimeoutW (LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam, SET fuFlags, INTEGER uTimeout, INTEGER *lpdwResult);
__EXTERN LONGINT __STDCALL SendMessageW (LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN INTEGER __STDCALL SendNotifyMessageA (LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN INTEGER __STDCALL SendNotifyMessageW (LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
__EXTERN INTEGER __STDCALL SetAbortProc (LONGINT p0, WinAPI_ABORTPROC p1);
__EXTERN INTEGER __STDCALL SetAclInformation (WinAPI_ACL *pAcl, LONGINT pAclInformation, INTEGER nAclInformationLength, INTEGER dwAclInformationClass);
__EXTERN LONGINT __STDCALL SetActiveWindow (LONGINT hWnd);
__EXTERN INTEGER __STDCALL SetArcDirection (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetBitmapBits (LONGINT p0, INTEGER p1, LONGINT p2);
__EXTERN INTEGER __STDCALL SetBitmapDimensionEx (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL SetBkColor (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetBkMode (LONGINT p0, INTEGER p1);
__EXTERN SET __STDCALL SetBoundsRect (LONGINT p0, WinAPI_RECT *p1, SET p2);
__EXTERN INTEGER __STDCALL SetBrushOrgEx (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN LONGINT __STDCALL SetCapture (LONGINT hWnd);
__EXTERN INTEGER __STDCALL SetCaretBlinkTime (INTEGER uMSeconds);
__EXTERN INTEGER __STDCALL SetCaretPos (INTEGER X, INTEGER Y);
__EXTERN INTEGER __STDCALL SetClassLongA (LONGINT hWnd, INTEGER nIndex, INTEGER dwNewLong);
__EXTERN INTEGER __STDCALL SetClassLongW (LONGINT hWnd, INTEGER nIndex, INTEGER dwNewLong);
__EXTERN SHORTINT __STDCALL SetClassWord (LONGINT hWnd, INTEGER nIndex, SHORTINT wNewWord);
__EXTERN LONGINT __STDCALL SetClipboardData (INTEGER uFormat, LONGINT hMem);
__EXTERN LONGINT __STDCALL SetClipboardViewer (LONGINT hWndNewViewer);
__EXTERN INTEGER __STDCALL SetColorAdjustment (LONGINT p0, WinAPI_COLORADJUSTMENT *p1);
__EXTERN INTEGER __STDCALL SetColorSpace (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL SetCommBreak (LONGINT hFile);
__EXTERN INTEGER __STDCALL SetCommConfig (LONGINT hCommDev, WinAPI_COMMCONFIG *lpCC, INTEGER dwSize);
__EXTERN INTEGER __STDCALL SetCommMask (LONGINT hFile, SET dwEvtMask);
__EXTERN INTEGER __STDCALL SetCommState (LONGINT hFile, WinAPI_DCB *lpDCB);
__EXTERN INTEGER __STDCALL SetCommTimeouts (LONGINT hFile, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
__EXTERN INTEGER __STDCALL SetComputerNameA (LONGINT lpComputerName);
__EXTERN INTEGER __STDCALL SetComputerNameW (LONGINT lpComputerName);
__EXTERN INTEGER __STDCALL SetConsoleActiveScreenBuffer (LONGINT hConsoleOutput);
__EXTERN INTEGER __STDCALL SetConsoleCP (INTEGER wCodePageID);
__EXTERN INTEGER __STDCALL SetConsoleCtrlHandler (WinAPI_HANDLER_ROUTINE HandlerRoutine, INTEGER Add);
__EXTERN INTEGER __STDCALL SetConsoleCursorInfo (LONGINT hConsoleOutput, WinAPI_CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
__EXTERN INTEGER __STDCALL SetConsoleCursorPosition (LONGINT hConsoleOutput, WinAPI_COORD *dwCursorPosition);
__EXTERN INTEGER __STDCALL SetConsoleMode (LONGINT hConsoleHandle, SET dwMode);
__EXTERN INTEGER __STDCALL SetConsoleOutputCP (INTEGER wCodePageID);
__EXTERN INTEGER __STDCALL SetConsoleScreenBufferSize (LONGINT hConsoleOutput, WinAPI_COORD *dwSize);
__EXTERN INTEGER __STDCALL SetConsoleTextAttribute (LONGINT hConsoleOutput, SHORTINT wAttributes);
__EXTERN INTEGER __STDCALL SetConsoleTitleA (LONGINT lpConsoleTitle);
__EXTERN INTEGER __STDCALL SetConsoleTitleW (LONGINT lpConsoleTitle);
__EXTERN INTEGER __STDCALL SetConsoleWindowInfo (LONGINT hConsoleOutput, INTEGER bAbsolute, WinAPI_SMALL_RECT *lpConsoleWindow);
__EXTERN INTEGER __STDCALL SetCurrentDirectoryA (LONGINT lpPathName);
__EXTERN INTEGER __STDCALL SetCurrentDirectoryW (LONGINT lpPathName);
__EXTERN LONGINT __STDCALL SetCursor (LONGINT hCursor);
__EXTERN INTEGER __STDCALL SetCursorPos (INTEGER X, INTEGER Y);
__EXTERN INTEGER __STDCALL SetDIBColorTable (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_RGBQUAD *p3, INTEGER p3__len);
__EXTERN INTEGER __STDCALL SetDIBits (LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, LONGINT p4, WinAPI_BITMAPINFO *p5, INTEGER p6);
__EXTERN INTEGER __STDCALL SetDIBitsToDevice (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, LONGINT p9, WinAPI_BITMAPINFO *p10, INTEGER p11);
__EXTERN void __STDCALL SetDebugErrorLevel (INTEGER dwLevel);
__EXTERN INTEGER __STDCALL SetDefaultCommConfigA (LONGINT lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER dwSize);
__EXTERN INTEGER __STDCALL SetDefaultCommConfigW (LONGINT lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER dwSize);
__EXTERN INTEGER __STDCALL SetDeviceGammaRamp (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL SetDlgItemInt (LONGINT hDlg, INTEGER nIDDlgItem, INTEGER uValue, INTEGER bSigned);
__EXTERN INTEGER __STDCALL SetDlgItemTextA (LONGINT hDlg, INTEGER nIDDlgItem, LONGINT lpString);
__EXTERN INTEGER __STDCALL SetDlgItemTextW (LONGINT hDlg, INTEGER nIDDlgItem, LONGINT lpString);
__EXTERN INTEGER __STDCALL SetDoubleClickTime (INTEGER p0);
__EXTERN INTEGER __STDCALL SetEndOfFile (LONGINT hFile);
__EXTERN LONGINT __STDCALL SetEnhMetaFileBits (INTEGER p0, CHAR *p1);
__EXTERN INTEGER __STDCALL SetEnvironmentVariableA (LONGINT lpName, LONGINT lpValue);
__EXTERN INTEGER __STDCALL SetEnvironmentVariableW (LONGINT lpName, LONGINT lpValue);
__EXTERN INTEGER __STDCALL SetErrorMode (SET uMode);
__EXTERN INTEGER __STDCALL SetEvent (LONGINT hEvent);
__EXTERN void __STDCALL SetFileApisToANSI (void);
__EXTERN void __STDCALL SetFileApisToOEM (void);
__EXTERN INTEGER __STDCALL SetFileAttributesA (LONGINT lpFileName, SET dwFileAttributes);
__EXTERN INTEGER __STDCALL SetFileAttributesW (LONGINT lpFileName, SET dwFileAttributes);
__EXTERN INTEGER __STDCALL SetFilePointer (LONGINT hFile, INTEGER lDistanceToMove, INTEGER *lpDistanceToMoveHigh, INTEGER dwMoveMethod);
__EXTERN INTEGER __STDCALL SetFileSecurityA (LONGINT lpFileName, SET SecurityInformation, LONGINT pSecurityDescriptor);
__EXTERN INTEGER __STDCALL SetFileSecurityW (LONGINT lpFileName, SET SecurityInformation, LONGINT pSecurityDescriptor);
__EXTERN INTEGER __STDCALL SetFileTime (LONGINT hFile, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpLastAccessTime, WinAPI_FILETIME *lpLastWriteTime);
__EXTERN LONGINT __STDCALL SetFocus (LONGINT hWnd);
__EXTERN INTEGER __STDCALL SetForegroundWindow (LONGINT hWnd);
__EXTERN INTEGER __STDCALL SetFormA (LONGINT hPrinter, LONGINT pFormName, INTEGER Level, CHAR *pForm);
__EXTERN INTEGER __STDCALL SetFormW (LONGINT hPrinter, LONGINT pFormName, INTEGER Level, CHAR *pForm);
__EXTERN INTEGER __STDCALL SetGraphicsMode (LONGINT hdc, INTEGER iMode);
__EXTERN INTEGER __STDCALL SetHandleCount (INTEGER uNumber);
__EXTERN INTEGER __STDCALL SetHandleInformation (LONGINT hObject, INTEGER dwMask, SET dwFlags);
__EXTERN INTEGER __STDCALL SetICMMode (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetICMProfileA (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL SetICMProfileW (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL SetJobA (LONGINT hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER Command);
__EXTERN INTEGER __STDCALL SetJobW (LONGINT hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER Command);
__EXTERN INTEGER __STDCALL SetKernelObjectSecurity (LONGINT Handle, SET SecurityInformation, LONGINT SecurityDescriptor);
__EXTERN INTEGER __STDCALL SetKeyboardState (CHAR *lpKeyState);
__EXTERN void __STDCALL SetLastError (INTEGER dwErrCode);
__EXTERN void __STDCALL SetLastErrorEx (INTEGER dwErrCode, INTEGER dwType);
__EXTERN INTEGER __STDCALL SetLocalTime (WinAPI_SYSTEMTIME *lpSystemTime);
__EXTERN INTEGER __STDCALL SetLocaleInfoA (INTEGER Locale, INTEGER LCType, LONGINT lpLCData);
__EXTERN INTEGER __STDCALL SetLocaleInfoW (INTEGER Locale, INTEGER LCType, LONGINT lpLCData);
__EXTERN INTEGER __STDCALL SetMailslotInfo (LONGINT hMailslot, INTEGER lReadTimeout);
__EXTERN INTEGER __STDCALL SetMapMode (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetMapperFlags (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetMenu (LONGINT hWnd, LONGINT hMenu);
__EXTERN INTEGER __STDCALL SetMenuContextHelpId (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetMenuDefaultItem (LONGINT hMenu, INTEGER uItem, INTEGER fByPos);
__EXTERN INTEGER __STDCALL SetMenuItemBitmaps (LONGINT hMenu, INTEGER uPosition, SET uFlags, LONGINT hBitmapUnchecked, LONGINT hBitmapChecked);
__EXTERN INTEGER __STDCALL SetMenuItemInfoA (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOA *p3);
__EXTERN INTEGER __STDCALL SetMenuItemInfoW (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOW *p3);
__EXTERN LONGINT __STDCALL SetMessageExtraInfo (LONGINT lParam);
__EXTERN INTEGER __STDCALL SetMessageQueue (INTEGER cMessagesMax);
__EXTERN LONGINT __STDCALL SetMetaFileBitsEx (INTEGER p0, BYTE *p1);
__EXTERN INTEGER __STDCALL SetMetaRgn (LONGINT p0);
__EXTERN INTEGER __STDCALL SetMiterLimit (LONGINT p0, SHORTREAL p1, SHORTREAL *p2);
__EXTERN INTEGER __STDCALL SetNamedPipeHandleState (LONGINT hNamedPipe, INTEGER *lpMode, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout);
__EXTERN INTEGER __STDCALL SetPaletteEntries (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
__EXTERN LONGINT __STDCALL SetParent (LONGINT hWndChild, LONGINT hWndNewParent);
__EXTERN INTEGER __STDCALL SetPixel (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL SetPixelFormat (LONGINT p0, INTEGER p1, WinAPI_PIXELFORMATDESCRIPTOR *p2);
__EXTERN INTEGER __STDCALL SetPixelV (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL SetPolyFillMode (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetPrinterA (LONGINT hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER Command);
__EXTERN INTEGER __STDCALL SetPrinterDataA (LONGINT hPrinter, LONGINT pValueName, INTEGER Type, CHAR *pData, INTEGER cbData);
__EXTERN INTEGER __STDCALL SetPrinterDataW (LONGINT hPrinter, LONGINT pValueName, INTEGER Type, CHAR *pData, INTEGER cbData);
__EXTERN INTEGER __STDCALL SetPrinterW (LONGINT hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER Command);
__EXTERN INTEGER __STDCALL SetPriorityClass (LONGINT hProcess, INTEGER dwPriorityClass);
__EXTERN INTEGER __STDCALL SetPrivateObjectSecurity (SET SecurityInformation, LONGINT ModificationDescriptor, LONGINT *ObjectsSecurityDescriptor, WinAPI_GENERIC_MAPPING *GenericMapping, LONGINT Token);
__EXTERN INTEGER __STDCALL SetProcessAffinityMask (LONGINT hProcess, INTEGER dwProcessAffinityMask);
__EXTERN INTEGER __STDCALL SetProcessShutdownParameters (INTEGER dwLevel, SET dwFlags);
__EXTERN INTEGER __STDCALL SetProcessWindowStation (LONGINT hWinSta);
__EXTERN INTEGER __STDCALL SetProcessWorkingSetSize (LONGINT hProcess, INTEGER dwMinimumWorkingSetSize, INTEGER dwMaximumWorkingSetSize);
__EXTERN INTEGER __STDCALL SetPropA (LONGINT hWnd, LONGINT lpString, LONGINT hData);
__EXTERN INTEGER __STDCALL SetPropW (LONGINT hWnd, LONGINT lpString, LONGINT hData);
__EXTERN INTEGER __STDCALL SetROP2 (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetRect (WinAPI_RECT *lprc, INTEGER xLeft, INTEGER yTop, INTEGER xRight, INTEGER yBottom);
__EXTERN INTEGER __STDCALL SetRectEmpty (WinAPI_RECT *lprc);
__EXTERN INTEGER __STDCALL SetRectRgn (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL SetScrollInfo (LONGINT p0, INTEGER p1, WinAPI_SCROLLINFO *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL SetScrollPos (LONGINT hWnd, INTEGER nBar, INTEGER nPos, INTEGER bRedraw);
__EXTERN INTEGER __STDCALL SetScrollRange (LONGINT hWnd, INTEGER nBar, INTEGER nMinPos, INTEGER nMaxPos, INTEGER bRedraw);
__EXTERN INTEGER __STDCALL SetSecurityDescriptorDacl (LONGINT pSecurityDescriptor, INTEGER bDaclPresent, WinAPI_ACL *pDacl, INTEGER bDaclDefaulted);
__EXTERN INTEGER __STDCALL SetSecurityDescriptorGroup (LONGINT pSecurityDescriptor, LONGINT pGroup, INTEGER bGroupDefaulted);
__EXTERN INTEGER __STDCALL SetSecurityDescriptorOwner (LONGINT pSecurityDescriptor, LONGINT pOwner, INTEGER bOwnerDefaulted);
__EXTERN INTEGER __STDCALL SetSecurityDescriptorSacl (LONGINT pSecurityDescriptor, INTEGER bSaclPresent, WinAPI_ACL *pSacl, INTEGER bSaclDefaulted);
__EXTERN INTEGER __STDCALL SetServiceObjectSecurity (LONGINT hService, SET dwSecurityInformation, LONGINT lpSecurityDescriptor);
__EXTERN INTEGER __STDCALL SetServiceStatus (INTEGER hServiceStatus, WinAPI_SERVICE_STATUS *lpServiceStatus);
__EXTERN INTEGER __STDCALL SetStdHandle (INTEGER nStdHandle, LONGINT hHandle);
__EXTERN INTEGER __STDCALL SetStretchBltMode (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetSysColors (INTEGER cElements, INTEGER *lpaElements, INTEGER *lpaRgbValues);
__EXTERN INTEGER __STDCALL SetSystemCursor (LONGINT hcur, INTEGER id);
__EXTERN INTEGER __STDCALL SetSystemPaletteUse (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetSystemPowerState (INTEGER fSuspend, INTEGER fForce);
__EXTERN INTEGER __STDCALL SetSystemTime (WinAPI_SYSTEMTIME *lpSystemTime);
__EXTERN INTEGER __STDCALL SetSystemTimeAdjustment (INTEGER dwTimeAdjustment, INTEGER bTimeAdjustmentDisabled);
__EXTERN INTEGER __STDCALL SetTapeParameters (LONGINT hDevice, INTEGER dwOperation, LONGINT lpTapeInformation);
__EXTERN INTEGER __STDCALL SetTapePosition (LONGINT hDevice, INTEGER dwPositionMethod, INTEGER dwPartition, INTEGER dwOffsetLow, INTEGER dwOffsetHigh, INTEGER bImmediate);
__EXTERN SET __STDCALL SetTextAlign (LONGINT p0, SET p1);
__EXTERN INTEGER __STDCALL SetTextCharacterExtra (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetTextColor (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetTextJustification (LONGINT p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL SetThreadAffinityMask (LONGINT hThread, INTEGER dwThreadAffinityMask);
__EXTERN INTEGER __STDCALL SetThreadContext (LONGINT hThread, WinAPI_CONTEXT *lpContext);
__EXTERN INTEGER __STDCALL SetThreadDesktop (LONGINT hDesktop);
__EXTERN INTEGER __STDCALL SetThreadIdealProcessor (LONGINT hThread, INTEGER dwIdealProcessor);
__EXTERN INTEGER __STDCALL SetThreadLocale (INTEGER Locale);
__EXTERN INTEGER __STDCALL SetThreadPriority (LONGINT hThread, INTEGER nPriority);
__EXTERN INTEGER __STDCALL SetThreadPriorityBoost (LONGINT hThread, INTEGER bDisablePriorityBoost);
__EXTERN INTEGER __STDCALL SetThreadToken (LONGINT *Thread, LONGINT Token);
__EXTERN INTEGER __STDCALL SetTimeZoneInformation (WinAPI_TIME_ZONE_INFORMATION *lpTimeZoneInformation);
__EXTERN INTEGER __STDCALL SetTimer (LONGINT hWnd, INTEGER nIDEvent, INTEGER uElapse, WinAPI_TIMERPROC lpTimerFunc);
__EXTERN INTEGER __STDCALL SetTokenInformation (LONGINT TokenHandle, INTEGER TokenInformationClass, LONGINT TokenInformation, INTEGER TokenInformationLength);
__EXTERN WinAPI_TOP_LEVEL_EXCEPTION_FILTER __STDCALL SetUnhandledExceptionFilter (WinAPI_TOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);
__EXTERN INTEGER __STDCALL SetUserObjectInformationA (LONGINT hObj, INTEGER nIndex, LONGINT pvInfo, INTEGER nLength);
__EXTERN INTEGER __STDCALL SetUserObjectInformationW (LONGINT hObj, INTEGER nIndex, LONGINT pvInfo, INTEGER nLength);
__EXTERN INTEGER __STDCALL SetUserObjectSecurity (LONGINT hObj, INTEGER *pSIRequested, LONGINT pSID);
__EXTERN INTEGER __STDCALL SetViewportExtEx (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL SetViewportOrgEx (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN INTEGER __STDCALL SetVolumeLabelA (LONGINT lpRootPathName, LONGINT lpVolumeName);
__EXTERN INTEGER __STDCALL SetVolumeLabelW (LONGINT lpRootPathName, LONGINT lpVolumeName);
__EXTERN INTEGER __STDCALL SetWaitableTimer (LONGINT hTimer, LONGINT *lpDueTime, INTEGER lPeriod, WinAPI_TIMERAPCROUTINE pfnCompletionRoutine, LONGINT lpArgToCompletionRoutine, INTEGER fResume);
__EXTERN LONGINT __STDCALL SetWinMetaFileBits (INTEGER p0, CHAR *p1, LONGINT p2, WinAPI_METAFILEPICT *p3);
__EXTERN INTEGER __STDCALL SetWindowContextHelpId (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetWindowExtEx (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL SetWindowLongA (LONGINT hWnd, INTEGER nIndex, INTEGER dwNewLong);
__EXTERN INTEGER __STDCALL SetWindowLongW (LONGINT hWnd, INTEGER nIndex, INTEGER dwNewLong);
__EXTERN INTEGER __STDCALL SetWindowOrgEx (LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN INTEGER __STDCALL SetWindowPlacement (LONGINT hWnd, WinAPI_WINDOWPLACEMENT *lpwndpl);
__EXTERN INTEGER __STDCALL SetWindowPos (LONGINT hWnd, LONGINT hWndInsertAfter, INTEGER X, INTEGER Y, INTEGER cx, INTEGER cy, SET uFlags);
__EXTERN INTEGER __STDCALL SetWindowRgn (LONGINT hWnd, LONGINT hRgn, INTEGER bRedraw);
__EXTERN INTEGER __STDCALL SetWindowTextA (LONGINT hWnd, LONGINT lpString);
__EXTERN INTEGER __STDCALL SetWindowTextW (LONGINT hWnd, LONGINT lpString);
__EXTERN SHORTINT __STDCALL SetWindowWord (LONGINT hWnd, INTEGER nIndex, SHORTINT wNewWord);
__EXTERN WinAPI_HOOKPROC __STDCALL SetWindowsHookA (INTEGER nFilterType, WinAPI_HOOKPROC pfnFilterProc);
__EXTERN LONGINT __STDCALL SetWindowsHookExA (INTEGER idHook, WinAPI_HOOKPROC lpfn, LONGINT hmod, INTEGER dwThreadId);
__EXTERN LONGINT __STDCALL SetWindowsHookExW (INTEGER idHook, WinAPI_HOOKPROC lpfn, LONGINT hmod, INTEGER dwThreadId);
__EXTERN WinAPI_HOOKPROC __STDCALL SetWindowsHookW (INTEGER nFilterType, WinAPI_HOOKPROC pfnFilterProc);
__EXTERN INTEGER __STDCALL SetWorldTransform (LONGINT p0, WinAPI_XFORM *p1);
__EXTERN INTEGER __STDCALL SetupComm (LONGINT hFile, INTEGER dwInQueue, INTEGER dwOutQueue);
__EXTERN INTEGER __STDCALL ShellAboutA (LONGINT hWnd, LONGINT szApp, LONGINT szOtherStuff, LONGINT hIcon);
__EXTERN INTEGER __STDCALL ShellAboutW (LONGINT hWnd, LONGINT szApp, LONGINT szOtherStuff, LONGINT hIcon);
__EXTERN LONGINT __STDCALL ShellExecuteA (LONGINT hwnd, LONGINT lpOperation, LONGINT lpFile, LONGINT lpParameters, LONGINT lpDirectory, INTEGER nShowCmd);
__EXTERN INTEGER __STDCALL ShellExecuteExA (WinAPI_SHELLEXECUTEINFOA *lpExecInfo);
__EXTERN INTEGER __STDCALL ShellExecuteExW (WinAPI_SHELLEXECUTEINFOW *lpExecInfo);
__EXTERN LONGINT __STDCALL ShellExecuteW (LONGINT hwnd, LONGINT lpOperation, LONGINT lpFile, LONGINT lpParameters, LONGINT lpDirectory, INTEGER nShowCmd);
__EXTERN INTEGER __STDCALL Shell_NotifyIconA (INTEGER dwMessage, WinAPI_NOTIFYICONDATAA *lpData);
__EXTERN INTEGER __STDCALL Shell_NotifyIconW (INTEGER dwMessage, WinAPI_NOTIFYICONDATAW *lpData);
__EXTERN INTEGER __STDCALL ShowCaret (LONGINT hWnd);
__EXTERN INTEGER __STDCALL ShowCursor (INTEGER bShow);
__EXTERN INTEGER __STDCALL ShowOwnedPopups (LONGINT hWnd, INTEGER fShow);
__EXTERN INTEGER __STDCALL ShowScrollBar (LONGINT hWnd, INTEGER wBar, INTEGER bShow);
__EXTERN INTEGER __STDCALL ShowWindow (LONGINT hWnd, INTEGER nCmdShow);
__EXTERN INTEGER __STDCALL ShowWindowAsync (LONGINT hWnd, INTEGER nCmdShow);
__EXTERN INTEGER __STDCALL SignalObjectAndWait (LONGINT hObjectToSignal, LONGINT hObjectToWaitOn, INTEGER dwMilliseconds, INTEGER bAlertable);
__EXTERN INTEGER __STDCALL SizeofResource (LONGINT hModule, LONGINT hResInfo);
__EXTERN void __STDCALL Sleep (INTEGER dwMilliseconds);
__EXTERN INTEGER __STDCALL SleepEx (INTEGER dwMilliseconds, INTEGER bAlertable);
__EXTERN INTEGER __STDCALL StartDocA (LONGINT p0, WinAPI_DOCINFOA *p1);
__EXTERN INTEGER __STDCALL StartDocPrinterA (LONGINT hPrinter, INTEGER Level, CHAR *pDocInfo);
__EXTERN INTEGER __STDCALL StartDocPrinterW (LONGINT hPrinter, INTEGER Level, CHAR *pDocInfo);
__EXTERN INTEGER __STDCALL StartDocW (LONGINT p0, WinAPI_DOCINFOW *p1);
__EXTERN INTEGER __STDCALL StartPage (LONGINT p0);
__EXTERN INTEGER __STDCALL StartPagePrinter (LONGINT hPrinter);
__EXTERN INTEGER __STDCALL StartServiceA (LONGINT hService, INTEGER dwNumServiceArgs, LONGINT *lpServiceArgVectors);
__EXTERN INTEGER __STDCALL StartServiceCtrlDispatcherA (WinAPI_SERVICE_TABLE_ENTRYA *lpServiceStartTable);
__EXTERN INTEGER __STDCALL StartServiceCtrlDispatcherW (WinAPI_SERVICE_TABLE_ENTRYW *lpServiceStartTable);
__EXTERN INTEGER __STDCALL StartServiceW (LONGINT hService, INTEGER dwNumServiceArgs, LONGINT lpServiceArgVectors);
__EXTERN INTEGER __STDCALL StretchBlt (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, LONGINT p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10);
__EXTERN INTEGER __STDCALL StretchDIBits (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, LONGINT p9, WinAPI_BITMAPINFO *p10, INTEGER p11, INTEGER p12);
__EXTERN INTEGER __STDCALL StrokeAndFillPath (LONGINT p0);
__EXTERN INTEGER __STDCALL StrokePath (LONGINT p0);
__EXTERN INTEGER __STDCALL SubtractRect (WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc1, WinAPI_RECT *lprcSrc2);
__EXTERN INTEGER __STDCALL SuspendThread (LONGINT hThread);
__EXTERN INTEGER __STDCALL SwapBuffers (LONGINT p0);
__EXTERN INTEGER __STDCALL SwapMouseButton (INTEGER fSwap);
__EXTERN INTEGER __STDCALL SwitchDesktop (LONGINT hDesktop);
__EXTERN void __STDCALL SwitchToFiber (LONGINT lpFiber);
__EXTERN INTEGER __STDCALL SystemParametersInfoA (INTEGER uiAction, INTEGER uiParam, LONGINT pvParam, INTEGER fWinIni);
__EXTERN INTEGER __STDCALL SystemParametersInfoW (INTEGER uiAction, INTEGER uiParam, LONGINT pvParam, INTEGER fWinIni);
__EXTERN INTEGER __STDCALL SystemTimeToFileTime (WinAPI_SYSTEMTIME *lpSystemTime, WinAPI_FILETIME *lpFileTime);
__EXTERN INTEGER __STDCALL SystemTimeToTzSpecificLocalTime (WinAPI_TIME_ZONE_INFORMATION *lpTimeZoneInformation, WinAPI_SYSTEMTIME *lpUniversalTime, WinAPI_SYSTEMTIME *lpLocalTime);
__EXTERN INTEGER __STDCALL TabbedTextOutA (LONGINT hDC, INTEGER X, INTEGER Y, LONGINT lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions, INTEGER nTabOrigin);
__EXTERN INTEGER __STDCALL TabbedTextOutW (LONGINT hDC, INTEGER X, INTEGER Y, LONGINT lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions, INTEGER nTabOrigin);
__EXTERN INTEGER __STDCALL TerminateProcess (LONGINT hProcess, INTEGER uExitCode);
__EXTERN INTEGER __STDCALL TerminateThread (LONGINT hThread, INTEGER dwExitCode);
__EXTERN INTEGER __STDCALL TextOutA (LONGINT p0, INTEGER p1, INTEGER p2, LONGINT p3, INTEGER p4);
__EXTERN INTEGER __STDCALL TextOutW (LONGINT p0, INTEGER p1, INTEGER p2, LONGINT p3, INTEGER p4);
__EXTERN SHORTINT __STDCALL TileWindows (LONGINT hwndParent, INTEGER wHow, WinAPI_RECT *lpRect, INTEGER cKids, LONGINT *lpKids);
__EXTERN INTEGER __STDCALL TlsAlloc (void);
__EXTERN INTEGER __STDCALL TlsFree (INTEGER dwTlsIndex);
__EXTERN LONGINT __STDCALL TlsGetValue (INTEGER dwTlsIndex);
__EXTERN INTEGER __STDCALL TlsSetValue (INTEGER dwTlsIndex, LONGINT lpTlsValue);
__EXTERN INTEGER __STDCALL ToAscii (INTEGER uVirtKey, INTEGER uScanCode, CHAR *lpKeyState, SHORTINT *lpChar, SET uFlags);
__EXTERN INTEGER __STDCALL ToAsciiEx (INTEGER uVirtKey, INTEGER uScanCode, CHAR *lpKeyState, SHORTINT *lpChar, SET uFlags, LONGINT dwhkl);
__EXTERN INTEGER __STDCALL ToUnicode (INTEGER wVirtKey, INTEGER wScanCode, CHAR *lpKeyState, LONGINT pwszBuff, INTEGER cchBuff, INTEGER wFlags);
__EXTERN INTEGER __STDCALL ToUnicodeEx (INTEGER wVirtKey, INTEGER wScanCode, CHAR *lpKeyState, LONGINT pwszBuff, INTEGER cchBuff, INTEGER wFlags, LONGINT dwhkl);
__EXTERN INTEGER __STDCALL TrackPopupMenu (LONGINT hMenu, SET uFlags, INTEGER x, INTEGER y, INTEGER nReserved, LONGINT hWnd, WinAPI_RECT *prcRect);
__EXTERN INTEGER __STDCALL TrackPopupMenuEx (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, LONGINT p4, WinAPI_TPMPARAMS *p5);
__EXTERN INTEGER __STDCALL TransactNamedPipe (LONGINT hNamedPipe, LONGINT lpInBuffer, INTEGER nInBufferSize, LONGINT lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL TranslateAcceleratorA (LONGINT hWnd, LONGINT hAccTable, WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL TranslateAcceleratorW (LONGINT hWnd, LONGINT hAccTable, WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL TranslateCharsetInfo (INTEGER *lpSrc, WinAPI_CHARSETINFO *lpCs, SET dwFlags);
__EXTERN INTEGER __STDCALL TranslateMDISysAccel (LONGINT hWndClient, WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL TranslateMessage (WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL TransmitCommChar (LONGINT hFile, CHAR cChar);
__EXTERN INTEGER __STDCALL TryEnterCriticalSection (WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
__EXTERN INTEGER __STDCALL UnhandledExceptionFilter (WinAPI_EXCEPTION_POINTERS *ExceptionInfo);
__EXTERN INTEGER __STDCALL UnhookWindowsHook (INTEGER nCode, WinAPI_HOOKPROC pfnFilterProc);
__EXTERN INTEGER __STDCALL UnhookWindowsHookEx (LONGINT hhk);
__EXTERN INTEGER __STDCALL UnionRect (WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc1, WinAPI_RECT *lprcSrc2);
__EXTERN INTEGER __STDCALL UnloadKeyboardLayout (LONGINT hkl);
__EXTERN INTEGER __STDCALL UnlockFile (LONGINT hFile, INTEGER dwFileOffsetLow, INTEGER dwFileOffsetHigh, INTEGER nNumberOfBytesToUnlockLow, INTEGER nNumberOfBytesToUnlockHigh);
__EXTERN INTEGER __STDCALL UnlockFileEx (LONGINT hFile, INTEGER dwReserved, INTEGER nNumberOfBytesToUnlockLow, INTEGER nNumberOfBytesToUnlockHigh, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL UnlockServiceDatabase (LONGINT ScLock);
__EXTERN INTEGER __STDCALL UnmapViewOfFile (LONGINT lpBaseAddress);
__EXTERN INTEGER __STDCALL UnpackDDElParam (INTEGER msg, INTEGER lParam, INTEGER *puiLo, INTEGER *puiHi);
__EXTERN INTEGER __STDCALL UnrealizeObject (LONGINT p0);
__EXTERN INTEGER __STDCALL UnregisterClassA (LONGINT lpClassName, LONGINT hInstance);
__EXTERN INTEGER __STDCALL UnregisterClassW (LONGINT lpClassName, LONGINT hInstance);
__EXTERN INTEGER __STDCALL UnregisterHotKey (LONGINT hWnd, INTEGER id);
__EXTERN INTEGER __STDCALL UpdateColors (LONGINT p0);
__EXTERN INTEGER __STDCALL UpdateResourceA (LONGINT hUpdate, LONGINT lpType, LONGINT lpName, SHORTINT wLanguage, LONGINT lpData, INTEGER cbData);
__EXTERN INTEGER __STDCALL UpdateResourceW (LONGINT hUpdate, LONGINT lpType, LONGINT lpName, SHORTINT wLanguage, LONGINT lpData, INTEGER cbData);
__EXTERN INTEGER __STDCALL UpdateWindow (LONGINT hWnd);
__EXTERN INTEGER __STDCALL ValidateRect (LONGINT hWnd, WinAPI_RECT *lpRect);
__EXTERN INTEGER __STDCALL ValidateRgn (LONGINT hWnd, LONGINT hRgn);
__EXTERN SET __STDCALL VerFindFileA (SET uFlags, LONGINT szFileName, LONGINT szWinDir, LONGINT szAppDir, LONGINT szCurDir, INTEGER *lpuCurDirLen, LONGINT szDestDir, INTEGER *lpuDestDirLen);
__EXTERN SET __STDCALL VerFindFileW (SET uFlags, LONGINT szFileName, LONGINT szWinDir, LONGINT szAppDir, LONGINT szCurDir, INTEGER *lpuCurDirLen, LONGINT szDestDir, INTEGER *lpuDestDirLen);
__EXTERN SET __STDCALL VerInstallFileA (SET uFlags, LONGINT szSrcFileName, LONGINT szDestFileName, LONGINT szSrcDir, LONGINT szDestDir, LONGINT szCurDir, LONGINT szTmpFile, INTEGER *lpuTmpFileLen);
__EXTERN SET __STDCALL VerInstallFileW (SET uFlags, LONGINT szSrcFileName, LONGINT szDestFileName, LONGINT szSrcDir, LONGINT szDestDir, LONGINT szCurDir, LONGINT szTmpFile, INTEGER *lpuTmpFileLen);
__EXTERN INTEGER __STDCALL VerLanguageNameA (INTEGER wLang, LONGINT szLang, INTEGER nSize);
__EXTERN INTEGER __STDCALL VerLanguageNameW (INTEGER wLang, LONGINT szLang, INTEGER nSize);
__EXTERN INTEGER __STDCALL VerQueryValueA (LONGINT pBlock, LONGINT lpSubBlock, LONGINT lplpBuffer, INTEGER *puLen);
__EXTERN INTEGER __STDCALL VerQueryValueW (LONGINT pBlock, LONGINT lpSubBlock, LONGINT lplpBuffer, INTEGER *puLen);
__EXTERN LONGINT __STDCALL VirtualAlloc (LONGINT lpAddress, LONGINT dwSize, SET flAllocationType, SET flProtect);
__EXTERN LONGINT __STDCALL VirtualAllocEx (LONGINT hProcess, LONGINT lpAddress, LONGINT dwSize, SET flAllocationType, SET flProtect);
__EXTERN INTEGER __STDCALL VirtualFree (LONGINT lpAddress, LONGINT dwSize, SET dwFreeType);
__EXTERN INTEGER __STDCALL VirtualLock (LONGINT lpAddress, LONGINT dwSize);
__EXTERN INTEGER __STDCALL VirtualProtect (LONGINT lpAddress, LONGINT dwSize, SET flNewProtect, INTEGER *lpflOldProtect);
__EXTERN INTEGER __STDCALL VirtualProtectEx (LONGINT hProcess, LONGINT lpAddress, LONGINT dwSize, SET flNewProtect, INTEGER *lpflOldProtect);
__EXTERN LONGINT __STDCALL VirtualQuery (LONGINT lpAddress, WinAPI_MEMORY_BASIC_INFORMATION *lpBuffer, LONGINT dwLength);
__EXTERN LONGINT __STDCALL VirtualQueryEx (LONGINT hProcess, LONGINT lpAddress, WinAPI_MEMORY_BASIC_INFORMATION *lpBuffer, LONGINT dwLength);
__EXTERN INTEGER __STDCALL VirtualUnlock (LONGINT lpAddress, LONGINT dwSize);
__EXTERN SHORTINT __STDCALL VkKeyScanA (CHAR ch);
__EXTERN SHORTINT __STDCALL VkKeyScanExA (CHAR ch, LONGINT dwhkl);
__EXTERN SHORTINT __STDCALL VkKeyScanExW (SHORTINT ch, LONGINT dwhkl);
__EXTERN SHORTINT __STDCALL VkKeyScanW (SHORTINT ch);
__EXTERN INTEGER __STDCALL WaitCommEvent (LONGINT hFile, SET *lpEvtMask, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL WaitForDebugEvent (WinAPI_DEBUG_EVENT *lpDebugEvent, INTEGER dwMilliseconds);
__EXTERN INTEGER __STDCALL WaitForInputIdle (LONGINT hProcess, INTEGER dwMilliseconds);
__EXTERN INTEGER __STDCALL WaitForMultipleObjects (INTEGER nCount, LONGINT *lpHandles, INTEGER bWaitAll, INTEGER dwMilliseconds);
__EXTERN INTEGER __STDCALL WaitForMultipleObjectsEx (INTEGER nCount, LONGINT *lpHandles, INTEGER bWaitAll, INTEGER dwMilliseconds, INTEGER bAlertable);
__EXTERN INTEGER __STDCALL WaitForPrinterChange (LONGINT hPrinter, SET Flags);
__EXTERN INTEGER __STDCALL WaitForSingleObject (LONGINT hHandle, INTEGER dwMilliseconds);
__EXTERN INTEGER __STDCALL WaitForSingleObjectEx (LONGINT hHandle, INTEGER dwMilliseconds, INTEGER bAlertable);
__EXTERN INTEGER __STDCALL WaitMessage (void);
__EXTERN INTEGER __STDCALL WaitNamedPipeA (LONGINT lpNamedPipeName, INTEGER nTimeOut);
__EXTERN INTEGER __STDCALL WaitNamedPipeW (LONGINT lpNamedPipeName, INTEGER nTimeOut);
__EXTERN INTEGER __STDCALL WideCharToMultiByte (INTEGER CodePage, SET dwFlags, LONGINT lpWideCharStr, INTEGER cchWideChar, LONGINT lpMultiByteStr, INTEGER cchMultiByte, LONGINT lpDefaultChar, INTEGER *lpUsedDefaultChar);
__EXTERN INTEGER __STDCALL WidenPath (LONGINT p0);
__EXTERN INTEGER __STDCALL WinExec (LONGINT lpCmdLine, INTEGER uCmdShow);
__EXTERN INTEGER __STDCALL WinHelpA (LONGINT hWndMain, LONGINT lpszHelp, INTEGER uCommand, INTEGER dwData);
__EXTERN INTEGER __STDCALL WinHelpW (LONGINT hWndMain, LONGINT lpszHelp, INTEGER uCommand, INTEGER dwData);
__EXTERN LONGINT __STDCALL WindowFromDC (LONGINT hDC);
__EXTERN LONGINT __STDCALL WindowFromPoint (WinAPI_POINT *Point);
__EXTERN INTEGER __STDCALL WriteConsoleA (LONGINT hConsoleOutput, LONGINT lpBuffer, INTEGER nNumberOfCharsToWrite, INTEGER *lpNumberOfCharsWritten, LONGINT lpReserved);
__EXTERN INTEGER __STDCALL WriteConsoleInputA (LONGINT hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsWritten);
__EXTERN INTEGER __STDCALL WriteConsoleInputW (LONGINT hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsWritten);
__EXTERN INTEGER __STDCALL WriteConsoleOutputA (LONGINT hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD *dwBufferSize, WinAPI_COORD *dwBufferCoord, WinAPI_SMALL_RECT *lpWriteRegion);
__EXTERN INTEGER __STDCALL WriteConsoleOutputAttribute (LONGINT hConsoleOutput, SHORTINT *lpAttribute, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfAttrsWritten);
__EXTERN INTEGER __STDCALL WriteConsoleOutputCharacterA (LONGINT hConsoleOutput, LONGINT lpCharacter, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
__EXTERN INTEGER __STDCALL WriteConsoleOutputCharacterW (LONGINT hConsoleOutput, LONGINT lpCharacter, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
__EXTERN INTEGER __STDCALL WriteConsoleOutputW (LONGINT hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD *dwBufferSize, WinAPI_COORD *dwBufferCoord, WinAPI_SMALL_RECT *lpWriteRegion);
__EXTERN INTEGER __STDCALL WriteConsoleW (LONGINT hConsoleOutput, LONGINT lpBuffer, INTEGER nNumberOfCharsToWrite, INTEGER *lpNumberOfCharsWritten, LONGINT lpReserved);
__EXTERN INTEGER __STDCALL WriteFile (LONGINT hFile, LONGINT lpBuffer, INTEGER nNumberOfBytesToWrite, INTEGER *lpNumberOfBytesWritten, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL WriteFileEx (LONGINT hFile, LONGINT lpBuffer, INTEGER nNumberOfBytesToWrite, WinAPI_OVERLAPPED *lpOverlapped, WinAPI_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
__EXTERN INTEGER __STDCALL WritePrinter (LONGINT hPrinter, LONGINT pBuf, INTEGER cbBuf, INTEGER *pcWritten);
__EXTERN INTEGER __STDCALL WritePrivateProfileSectionA (LONGINT lpAppName, LONGINT lpString, LONGINT lpFileName);
__EXTERN INTEGER __STDCALL WritePrivateProfileSectionW (LONGINT lpAppName, LONGINT lpString, LONGINT lpFileName);
__EXTERN INTEGER __STDCALL WritePrivateProfileStringA (LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpString, LONGINT lpFileName);
__EXTERN INTEGER __STDCALL WritePrivateProfileStringW (LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpString, LONGINT lpFileName);
__EXTERN INTEGER __STDCALL WritePrivateProfileStructA (LONGINT lpszSection, LONGINT lpszKey, LONGINT lpStruct, INTEGER uSizeStruct, LONGINT szFile);
__EXTERN INTEGER __STDCALL WritePrivateProfileStructW (LONGINT lpszSection, LONGINT lpszKey, LONGINT lpStruct, INTEGER uSizeStruct, LONGINT szFile);
__EXTERN INTEGER __STDCALL WriteProcessMemory (LONGINT hProcess, LONGINT lpBaseAddress, LONGINT lpBuffer, INTEGER nSize, INTEGER *lpNumberOfBytesWritten);
__EXTERN INTEGER __STDCALL WriteProfileSectionA (LONGINT lpAppName, LONGINT lpString);
__EXTERN INTEGER __STDCALL WriteProfileSectionW (LONGINT lpAppName, LONGINT lpString);
__EXTERN INTEGER __STDCALL WriteProfileStringA (LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpString);
__EXTERN INTEGER __STDCALL WriteProfileStringW (LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpString);
__EXTERN INTEGER __STDCALL WriteTapemark (LONGINT hDevice, INTEGER dwTapemarkType, INTEGER dwTapemarkCount, INTEGER bImmediate);
__EXTERN INTEGER __STDCALL _hread (INTEGER hFile, LONGINT lpBuffer, INTEGER lBytes);
__EXTERN INTEGER __STDCALL _hwrite (INTEGER hFile, LONGINT lpBuffer, INTEGER lBytes);
__EXTERN INTEGER __STDCALL _lclose (INTEGER hFile);
__EXTERN INTEGER __STDCALL _lcreat (LONGINT lpPathName, INTEGER iAttribute);
__EXTERN INTEGER __STDCALL _llseek (INTEGER hFile, INTEGER lOffset, INTEGER iOrigin);
__EXTERN INTEGER __STDCALL _lopen (LONGINT lpPathName, INTEGER iReadWrite);
__EXTERN INTEGER __STDCALL _lread (INTEGER hFile, LONGINT lpBuffer, INTEGER uBytes);
__EXTERN INTEGER __STDCALL _lwrite (INTEGER hFile, LONGINT lpBuffer, INTEGER uBytes);
__EXTERN void __STDCALL keybd_event (CHAR bVk, CHAR bScan, SET dwFlags, INTEGER dwExtraInfo);
__EXTERN LONGINT __STDCALL lstrcatA (LONGINT lpString1, LONGINT lpString2);
__EXTERN LONGINT __STDCALL lstrcatW (LONGINT lpString1, LONGINT lpString2);
__EXTERN INTEGER __STDCALL lstrcmpA (LONGINT lpString1, LONGINT lpString2);
__EXTERN INTEGER __STDCALL lstrcmpW (LONGINT lpString1, LONGINT lpString2);
__EXTERN INTEGER __STDCALL lstrcmpiA (LONGINT lpString1, LONGINT lpString2);
__EXTERN INTEGER __STDCALL lstrcmpiW (LONGINT lpString1, LONGINT lpString2);
__EXTERN LONGINT __STDCALL lstrcpyA (LONGINT lpString1, LONGINT lpString2);
__EXTERN LONGINT __STDCALL lstrcpyW (LONGINT lpString1, LONGINT lpString2);
__EXTERN LONGINT __STDCALL lstrcpynA (LONGINT lpString1, LONGINT lpString2, INTEGER iMaxLength);
__EXTERN LONGINT __STDCALL lstrcpynW (LONGINT lpString1, LONGINT lpString2, INTEGER iMaxLength);
__EXTERN INTEGER __STDCALL lstrlenA (LONGINT lpString);
__EXTERN INTEGER __STDCALL lstrlenW (LONGINT lpString);
__EXTERN void __STDCALL mouse_event (SET dwFlags, INTEGER dx, INTEGER dy, INTEGER cButtons, INTEGER dwExtraInfo);
__EXTERN INTEGER __STDCALL wglCopyContext (LONGINT p0, LONGINT p1, INTEGER p2);
__EXTERN LONGINT __STDCALL wglCreateContext (LONGINT p0);
__EXTERN LONGINT __STDCALL wglCreateLayerContext (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL wglDeleteContext (LONGINT p0);
__EXTERN INTEGER __STDCALL wglDescribeLayerPlane (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_LAYERPLANEDESCRIPTOR *p4);
__EXTERN LONGINT __STDCALL wglGetCurrentContext (void);
__EXTERN LONGINT __STDCALL wglGetCurrentDC (void);
__EXTERN INTEGER __STDCALL wglGetLayerPaletteEntries (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4);
__EXTERN WinAPI_ROC __STDCALL wglGetProcAddress (LONGINT p0);
__EXTERN INTEGER __STDCALL wglMakeCurrent (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL wglRealizeLayerPalette (LONGINT p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL wglSetLayerPaletteEntries (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4);
__EXTERN INTEGER __STDCALL wglShareLists (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL wglSwapLayerBuffers (LONGINT p0, INTEGER p1);
__EXTERN INTEGER __STDCALL wglUseFontBitmapsA (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL wglUseFontBitmapsW (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL wglUseFontOutlinesA (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, SHORTREAL p4, SHORTREAL p5, INTEGER p6, WinAPI_GLYPHMETRICSFLOAT *p7);
__EXTERN INTEGER __STDCALL wglUseFontOutlinesW (LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, SHORTREAL p4, SHORTREAL p5, INTEGER p6, WinAPI_GLYPHMETRICSFLOAT *p7);
__EXTERN INTEGER wsprintfA (LONGINT p0, LONGINT p1);
__EXTERN INTEGER wsprintfW (LONGINT p0, LONGINT p1);
__EXTERN INTEGER __STDCALL wvsprintfA (LONGINT p0, LONGINT p1, LONGINT arglist);
__EXTERN INTEGER __STDCALL wvsprintfW (LONGINT p0, LONGINT p1, LONGINT arglist);
#define WinAPI__init()

#define WinAPI_AbortSystemShutdown(lpMachineName)	AbortSystemShutdownA(lpMachineName)
#define WinAPI_AccessCheckAndAuditAlarm(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)	AccessCheckAndAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)
#define WinAPI_AddAtom(lpString)	AddAtomA(lpString)
#define WinAPI_AddFontResource(p0)	AddFontResourceA(p0)
#define WinAPI_AddForm(hPrinter, Level, pForm)	AddFormA(hPrinter, Level, pForm)
#define WinAPI_AddJob(hPrinter, Level, pData, cbBuf, pcbNeeded)	AddJobA(hPrinter, Level, pData, cbBuf, pcbNeeded)
#define WinAPI_AddMonitor(pName, Level, pMonitors)	AddMonitorA(pName, Level, pMonitors)
#define WinAPI_AddPort(pName, hWnd, pMonitorName)	AddPortA(pName, hWnd, pMonitorName)
#define WinAPI_AddPrintProcessor(pName, pEnvironment, pPathName, pPrintProcessorName)	AddPrintProcessorA(pName, pEnvironment, pPathName, pPrintProcessorName)
#define WinAPI_AddPrintProvidor(pName, level, pProvidorInfo)	AddPrintProvidorA(pName, level, pProvidorInfo)
#define WinAPI_AddPrinter(pName, Level, pPrinter)	AddPrinterA(pName, Level, pPrinter)
#define WinAPI_AddPrinterConnection(pName)	AddPrinterConnectionA(pName)
#define WinAPI_AddPrinterDriver(pName, Level, pDriverInfo)	AddPrinterDriverA(pName, Level, pDriverInfo)
#define WinAPI_AdvancedDocumentProperties(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)	AdvancedDocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)
#define WinAPI_AnsiLower(lpsz)	CharLowerA(lpsz)
#define WinAPI_AnsiLowerBuff(lpsz, cchLength)	CharLowerBuffA(lpsz, cchLength)
#define WinAPI_AnsiNext(lpsz)	CharNextA(lpsz)
#define WinAPI_AnsiPrev(lpszStart, lpszCurrent)	CharPrevA(lpszStart, lpszCurrent)
#define WinAPI_AnsiToOem(lpszSrc, lpszDst)	CharToOemA(lpszSrc, lpszDst)
#define WinAPI_AnsiToOemBuff(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinAPI_AnsiUpper(lpsz)	CharUpperA(lpsz)
#define WinAPI_AnsiUpperBuff(lpsz, cchLength)	CharUpperBuffA(lpsz, cchLength)
#define WinAPI_AppendMenu(hMenu, uFlags, uIDNewItem, lpNewItem)	AppendMenuA(hMenu, uFlags, uIDNewItem, lpNewItem)
#define WinAPI_BackupEventLog(hEventLog, lpBackupFileName)	BackupEventLogA(hEventLog, lpBackupFileName)
#define WinAPI_BeginUpdateResource(pFileName, bDeleteExistingResources)	BeginUpdateResourceA(pFileName, bDeleteExistingResources)
#define WinAPI_BroadcastSystemMessage(p0, p1, p2, p3, p4)	BroadcastSystemMessageA(p0, p1, p2, p3, p4)
#define WinAPI_BuildCommDCB(lpDef, lpDCB)	BuildCommDCBA(lpDef, lpDCB)
#define WinAPI_BuildCommDCBAndTimeouts(lpDef, lpDCB, lpCommTimeouts)	BuildCommDCBAndTimeoutsA(lpDef, lpDCB, lpCommTimeouts)
#define WinAPI_CallMsgFilter(lpMsg, nCode)	CallMsgFilterA(lpMsg, nCode)
#define WinAPI_CallNamedPipe(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)	CallNamedPipeA(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)
#define WinAPI_CallWindowProc(lpPrevWndFunc, hWnd, Msg, wParam, lParam)	CallWindowProcA(lpPrevWndFunc, hWnd, Msg, wParam, lParam)
#define WinAPI_ChangeDisplaySettings(lpDevMode, dwFlags)	ChangeDisplaySettingsA(lpDevMode, dwFlags)
#define WinAPI_ChangeMenu(hMenu, cmd, lpszNewItem, cmdInsert, flags)	ChangeMenuA(hMenu, cmd, lpszNewItem, cmdInsert, flags)
#define WinAPI_ChangeServiceConfig(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)	ChangeServiceConfigA(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)
#define WinAPI_CharLower(lpsz)	CharLowerA(lpsz)
#define WinAPI_CharLowerBuff(lpsz, cchLength)	CharLowerBuffA(lpsz, cchLength)
#define WinAPI_CharNext(lpsz)	CharNextA(lpsz)
#define WinAPI_CharPrev(lpszStart, lpszCurrent)	CharPrevA(lpszStart, lpszCurrent)
#define WinAPI_CharToOem(lpszSrc, lpszDst)	CharToOemA(lpszSrc, lpszDst)
#define WinAPI_CharToOemBuff(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinAPI_CharUpper(lpsz)	CharUpperA(lpsz)
#define WinAPI_CharUpperBuff(lpsz, cchLength)	CharUpperBuffA(lpsz, cchLength)
#define WinAPI_ClearEventLog(hEventLog, lpBackupFileName)	ClearEventLogA(hEventLog, lpBackupFileName)
#define WinAPI_CmdLine()	__lpCmdLine
#define WinAPI_CmdShow()	__nCmdShow
#define WinAPI_CommConfigDialog(lpszName, hWnd, lpCC)	CommConfigDialogA(lpszName, hWnd, lpCC)
#define WinAPI_CompareString(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)	CompareStringA(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)
#define WinAPI_ConfigurePort(pName, hWnd, pPortName)	ConfigurePortA(pName, hWnd, pPortName)
#define WinAPI_CopyAcceleratorTable(hAccelSrc, lpAccelDst, cAccelEntries)	CopyAcceleratorTableA(hAccelSrc, lpAccelDst, cAccelEntries)
#define WinAPI_CopyEnhMetaFile(p0, p1)	CopyEnhMetaFileA(p0, p1)
#define WinAPI_CopyFile(lpExistingFileName, lpNewFileName, bFailIfExists)	CopyFileA(lpExistingFileName, lpNewFileName, bFailIfExists)
#define WinAPI_CopyFileEx(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)	CopyFileExA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)
#define WinAPI_CopyMetaFile(p0, p1)	CopyMetaFileA(p0, p1)
#define WinAPI_CreateAcceleratorTable(p0, p1)	CreateAcceleratorTableA(p0, p1)
#define WinAPI_CreateColorSpace(p0)	CreateColorSpaceA(p0)
#define WinAPI_CreateDC(p0, p1, p2, p3)	CreateDCA(p0, p1, p2, p3)
#define WinAPI_CreateDesktop(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)	CreateDesktopA(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)
#define WinAPI_CreateDialogIndirectParam(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogIndirectParamA(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)
#define WinAPI_CreateDialogParam(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
#define WinAPI_CreateDirectory(lpPathName, lpSecurityAttributes)	CreateDirectoryA(lpPathName, lpSecurityAttributes)
#define WinAPI_CreateDirectoryEx(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)	CreateDirectoryExA(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)
#define WinAPI_CreateEnhMetaFile(p0, p1, p2, p3)	CreateEnhMetaFileA(p0, p1, p2, p3)
#define WinAPI_CreateEvent(lpEventAttributes, bManualReset, bInitialState, lpName)	CreateEventA(lpEventAttributes, bManualReset, bInitialState, lpName)
#define WinAPI_CreateFile(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)	CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)
#define WinAPI_CreateFileMapping(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)	CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)
#define WinAPI_CreateFont(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)	CreateFontA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)
#define WinAPI_CreateFontIndirect(p0)	CreateFontIndirectA(p0)
#define WinAPI_CreateIC(p0, p1, p2, p3)	CreateICA(p0, p1, p2, p3)
#define WinAPI_CreateMDIWindow(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)	CreateMDIWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)
#define WinAPI_CreateMailslot(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)	CreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)
#define WinAPI_CreateMetaFile(p0)	CreateMetaFileA(p0)
#define WinAPI_CreateMutex(lpMutexAttributes, bInitialOwner, lpName)	CreateMutexA(lpMutexAttributes, bInitialOwner, lpName)
#define WinAPI_CreateNamedPipe(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)	CreateNamedPipeA(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)
#define WinAPI_CreateProcess(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)	CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
#define WinAPI_CreateProcessAsUser(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)	CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
#define WinAPI_CreatePropertySheetPage(p0)	CreatePropertySheetPageA(p0)
#define WinAPI_CreateScalableFontResource(p0, p1, p2, p3)	CreateScalableFontResourceA(p0, p1, p2, p3)
#define WinAPI_CreateSemaphore(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)	CreateSemaphoreA(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)
#define WinAPI_CreateService(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)	CreateServiceA(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)
#define WinAPI_CreateWaitableTimer(lpTimerAttributes, bManualReset, lpTimerName)	CreateWaitableTimerA(lpTimerAttributes, bManualReset, lpTimerName)
#define WinAPI_CreateWindowEx(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)	CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
#define WinAPI_CreateWindowStation(lpwinsta, dwReserved, dwDesiredAccess, lpsa)	CreateWindowStationA(lpwinsta, dwReserved, dwDesiredAccess, lpsa)
#define WinAPI_DdeCreateStringHandle(idInst, psz, iCodePage)	DdeCreateStringHandleA(idInst, psz, iCodePage)
#define WinAPI_DdeInitialize(pidInst, pfnCallback, afCmd, ulRes)	DdeInitializeA(pidInst, pfnCallback, afCmd, ulRes)
#define WinAPI_DdeQueryString(idInst, hsz, psz, cchMax, iCodePage)	DdeQueryStringA(idInst, hsz, psz, cchMax, iCodePage)
#define WinAPI_DefDlgProc(hDlg, Msg, wParam, lParam)	DefDlgProcA(hDlg, Msg, wParam, lParam)
#define WinAPI_DefFrameProc(hWnd, hWndMDIClient, uMsg, wParam, lParam)	DefFrameProcA(hWnd, hWndMDIClient, uMsg, wParam, lParam)
#define WinAPI_DefMDIChildProc(hWnd, uMsg, wParam, lParam)	DefMDIChildProcA(hWnd, uMsg, wParam, lParam)
#define WinAPI_DefWindowProc(hWnd, Msg, wParam, lParam)	DefWindowProcA(hWnd, Msg, wParam, lParam)
#define WinAPI_DefineDosDevice(dwFlags, lpDeviceName, lpTargetPath)	DefineDosDeviceA(dwFlags, lpDeviceName, lpTargetPath)
#define WinAPI_DeleteFile(lpFileName)	DeleteFileA(lpFileName)
#define WinAPI_DeleteForm(hPrinter, pFormName)	DeleteFormA(hPrinter, pFormName)
#define WinAPI_DeleteMonitor(pName, pEnvironment, pMonitorName)	DeleteMonitorA(pName, pEnvironment, pMonitorName)
#define WinAPI_DeletePort(pName, hWnd, pPortName)	DeletePortA(pName, hWnd, pPortName)
#define WinAPI_DeletePrintProcessor(pName, pEnvironment, pPrintProcessorName)	DeletePrintProcessorA(pName, pEnvironment, pPrintProcessorName)
#define WinAPI_DeletePrintProvidor(pName, pEnvironment, pPrintProvidorName)	DeletePrintProvidorA(pName, pEnvironment, pPrintProvidorName)
#define WinAPI_DeletePrinterConnection(pName)	DeletePrinterConnectionA(pName)
#define WinAPI_DeletePrinterDriver(pName, pEnvironment, pDriverName)	DeletePrinterDriverA(pName, pEnvironment, pDriverName)
#define WinAPI_DeviceCapabilities(p0, p1, p2, p3, p4)	DeviceCapabilitiesA(p0, p1, p2, p3, p4)
#define WinAPI_DialogBoxIndirectParam(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxIndirectParamA(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)
#define WinAPI_DialogBoxParam(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
#define WinAPI_DispatchMessage(lpMsg)	DispatchMessageA(lpMsg)
#define WinAPI_DlgDirList(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)	DlgDirListA(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)
#define WinAPI_DlgDirListComboBox(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)	DlgDirListComboBoxA(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)
#define WinAPI_DlgDirSelectComboBoxEx(hDlg, lpString, nCount, nIDComboBox)	DlgDirSelectComboBoxExA(hDlg, lpString, nCount, nIDComboBox)
#define WinAPI_DlgDirSelectEx(hDlg, lpString, nCount, nIDListBox)	DlgDirSelectExA(hDlg, lpString, nCount, nIDListBox)
#define WinAPI_DoEnvironmentSubst(szString, cbString)	DoEnvironmentSubstA(szString, cbString)
#define WinAPI_DocumentProperties(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)	DocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)
#define WinAPI_DragQueryFile(p0, p1, p2, p3)	DragQueryFileA(p0, p1, p2, p3)
#define WinAPI_DrawState(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)	DrawStateA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)
#define WinAPI_DrawText(hDC, lpString, nCount, lpRect, uFormat)	DrawTextA(hDC, lpString, nCount, lpRect, uFormat)
#define WinAPI_DrawTextEx(p0, p1, p2, p3, p4, p5)	DrawTextExA(p0, p1, p2, p3, p4, p5)
#define WinAPI_EndUpdateResource(hUpdate, fDiscard)	EndUpdateResourceA(hUpdate, fDiscard)
#define WinAPI_EnumCalendarInfo(lpCalInfoEnumProc, Locale, Calendar, CalType)	EnumCalendarInfoA(lpCalInfoEnumProc, Locale, Calendar, CalType)
#define WinAPI_EnumDateFormats(lpDateFmtEnumProc, Locale, dwFlags)	EnumDateFormatsA(lpDateFmtEnumProc, Locale, dwFlags)
#define WinAPI_EnumDependentServices(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)	EnumDependentServicesA(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)
#define WinAPI_EnumDesktops(hwinsta, lpEnumFunc, lParam)	EnumDesktopsA(hwinsta, lpEnumFunc, lParam)
#define WinAPI_EnumDisplaySettings(lpszDeviceName, iModeNum, lpDevMode)	EnumDisplaySettingsA(lpszDeviceName, iModeNum, lpDevMode)
#define WinAPI_EnumFontFamilies(p0, p1, p2, p3)	EnumFontFamiliesA(p0, p1, p2, p3)
#define WinAPI_EnumFontFamiliesEx(p0, p1, p2, p3, p4)	EnumFontFamiliesExA(p0, p1, p2, p3, p4)
#define WinAPI_EnumFonts(p0, p1, p2, p3)	EnumFontsA(p0, p1, p2, p3)
#define WinAPI_EnumForms(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)	EnumFormsA(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumICMProfiles(p0, p1, p2)	EnumICMProfilesA(p0, p1, p2)
#define WinAPI_EnumJobs(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)	EnumJobsA(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumMonitors(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)	EnumMonitorsA(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPorts(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)	EnumPortsA(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPrintProcessorDatatypes(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorDatatypesA(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPrintProcessors(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorsA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPrinterDrivers(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrinterDriversA(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPrinters(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)	EnumPrintersA(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumProps(hWnd, lpEnumFunc)	EnumPropsA(hWnd, lpEnumFunc)
#define WinAPI_EnumPropsEx(hWnd, lpEnumFunc, lParam)	EnumPropsExA(hWnd, lpEnumFunc, lParam)
#define WinAPI_EnumResourceLanguages(hModule, lpType, lpName, lpEnumFunc, lParam)	EnumResourceLanguagesA(hModule, lpType, lpName, lpEnumFunc, lParam)
#define WinAPI_EnumResourceNames(hModule, lpType, lpEnumFunc, lParam)	EnumResourceNamesA(hModule, lpType, lpEnumFunc, lParam)
#define WinAPI_EnumResourceTypes(hModule, lpEnumFunc, lParam)	EnumResourceTypesA(hModule, lpEnumFunc, lParam)
#define WinAPI_EnumServicesStatus(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)	EnumServicesStatusA(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)
#define WinAPI_EnumSystemCodePages(lpCodePageEnumProc, dwFlags)	EnumSystemCodePagesA(lpCodePageEnumProc, dwFlags)
#define WinAPI_EnumSystemLocales(lpLocaleEnumProc, dwFlags)	EnumSystemLocalesA(lpLocaleEnumProc, dwFlags)
#define WinAPI_EnumTimeFormats(lpTimeFmtEnumProc, Locale, dwFlags)	EnumTimeFormatsA(lpTimeFmtEnumProc, Locale, dwFlags)
#define WinAPI_EnumWindowStations(lpEnumFunc, lParam)	EnumWindowStationsA(lpEnumFunc, lParam)
#define WinAPI_ExpandEnvironmentStrings(lpSrc, lpDst, nSize)	ExpandEnvironmentStringsA(lpSrc, lpDst, nSize)
#define WinAPI_ExtTextOut(p0, p1, p2, p3, p4, p5, p6, p7)	ExtTextOutA(p0, p1, p2, p3, p4, p5, p6, p7)
#define WinAPI_ExtractAssociatedIcon(hInst, lpIconPath, lpiIcon)	ExtractAssociatedIconA(hInst, lpIconPath, lpiIcon)
#define WinAPI_ExtractIcon(hInst, lpszExeFileName, nIconIndex)	ExtractIconA(hInst, lpszExeFileName, nIconIndex)
#define WinAPI_ExtractIconEx(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)	ExtractIconExA(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)
#define WinAPI_FatalAppExit(uAction, lpMessageText)	FatalAppExitA(uAction, lpMessageText)
#define WinAPI_FillConsoleOutputCharacter(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	FillConsoleOutputCharacterA(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
#define WinAPI_FindAtom(lpString)	FindAtomA(lpString)
#define WinAPI_FindExecutable(lpFile, lpDirectory, lpResult)	FindExecutableA(lpFile, lpDirectory, lpResult)
#define WinAPI_FindFirstChangeNotification(lpPathName, bWatchSubtree, dwNotifyFilter)	FindFirstChangeNotificationA(lpPathName, bWatchSubtree, dwNotifyFilter)
#define WinAPI_FindFirstFile(lpFileName, lpFindFileData)	FindFirstFileA(lpFileName, lpFindFileData)
#define WinAPI_FindFirstFileEx(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)	FindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)
#define WinAPI_FindNextFile(hFindFile, lpFindFileData)	FindNextFileA(hFindFile, lpFindFileData)
#define WinAPI_FindResource(hModule, lpName, lpType)	FindResourceA(hModule, lpName, lpType)
#define WinAPI_FindResourceEx(hModule, lpType, lpName, wLanguage)	FindResourceExA(hModule, lpType, lpName, wLanguage)
#define WinAPI_FindWindow(lpClassName, lpWindowName)	FindWindowA(lpClassName, lpWindowName)
#define WinAPI_FindWindowEx(p0, p1, p2, p3)	FindWindowExA(p0, p1, p2, p3)
#define WinAPI_FoldString(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	FoldStringA(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
#define WinAPI_FormatMessage(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)	FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)
#define WinAPI_FreeEnvironmentStrings(p0)	FreeEnvironmentStringsA(p0)
#define WinAPI_GetAtomName(nAtom, lpBuffer, nSize)	GetAtomNameA(nAtom, lpBuffer, nSize)
#define WinAPI_GetBinaryType(lpApplicationName, lpBinaryType)	GetBinaryTypeA(lpApplicationName, lpBinaryType)
#define WinAPI_GetCharABCWidths(p0, p1, p2, p3)	GetCharABCWidthsA(p0, p1, p2, p3)
#define WinAPI_GetCharABCWidthsFloat(p0, p1, p2, p3)	GetCharABCWidthsFloatA(p0, p1, p2, p3)
#define WinAPI_GetCharWidth(p0, p1, p2, p3)	GetCharWidthA(p0, p1, p2, p3)
#define WinAPI_GetCharWidth32(p0, p1, p2, p3)	GetCharWidth32A(p0, p1, p2, p3)
#define WinAPI_GetCharWidthFloat(p0, p1, p2, p3)	GetCharWidthFloatA(p0, p1, p2, p3)
#define WinAPI_GetCharacterPlacement(p0, p1, p2, p3, p4, p5)	GetCharacterPlacementA(p0, p1, p2, p3, p4, p5)
#define WinAPI_GetClassInfo(hInstance, lpClassName, lpWndClass)	GetClassInfoA(hInstance, lpClassName, lpWndClass)
#define WinAPI_GetClassInfoEx(p0, p1, p2)	GetClassInfoExA(p0, p1, p2)
#define WinAPI_GetClassLong(hWnd, nIndex)	GetClassLongA(hWnd, nIndex)
#define WinAPI_GetClassName(hWnd, lpClassName, nMaxCount)	GetClassNameA(hWnd, lpClassName, nMaxCount)
#define WinAPI_GetClipboardFormatName(format, lpszFormatName, cchMaxCount)	GetClipboardFormatNameA(format, lpszFormatName, cchMaxCount)
#define WinAPI_GetCommandLine()	GetCommandLineA()
#define WinAPI_GetCompressedFileSize(lpFileName, lpFileSizeHigh)	GetCompressedFileSizeA(lpFileName, lpFileSizeHigh)
#define WinAPI_GetComputerName(lpBuffer, nSize)	GetComputerNameA(lpBuffer, nSize)
#define WinAPI_GetConsoleTitle(lpConsoleTitle, nSize)	GetConsoleTitleA(lpConsoleTitle, nSize)
#define WinAPI_GetCurrencyFormat(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)	GetCurrencyFormatA(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)
#define WinAPI_GetCurrentDirectory(nBufferLength, lpBuffer)	GetCurrentDirectoryA(nBufferLength, lpBuffer)
#define WinAPI_GetCurrentHwProfile(lpHwProfileInfo)	GetCurrentHwProfileA(lpHwProfileInfo)
#define WinAPI_GetDateFormat(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)	GetDateFormatA(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)
#define WinAPI_GetDefaultCommConfig(lpszName, lpCC, lpdwSize)	GetDefaultCommConfigA(lpszName, lpCC, lpdwSize)
#define WinAPI_GetDiskFreeSpace(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)	GetDiskFreeSpaceA(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)
#define WinAPI_GetDlgItemText(hDlg, nIDDlgItem, lpString, nMaxCount)	GetDlgItemTextA(hDlg, nIDDlgItem, lpString, nMaxCount)
#define WinAPI_GetDriveType(lpRootPathName)	GetDriveTypeA(lpRootPathName)
#define WinAPI_GetEnhMetaFile(p0)	GetEnhMetaFileA(p0)
#define WinAPI_GetEnhMetaFileDescription(p0, p1, p2)	GetEnhMetaFileDescriptionA(p0, p1, p2)
#define WinAPI_GetEnvironmentStringsA()	GetEnvironmentStrings()
#define WinAPI_GetEnvironmentVariable(lpName, lpBuffer, nSize)	GetEnvironmentVariableA(lpName, lpBuffer, nSize)
#define WinAPI_GetExpandedName(p0, p1)	GetExpandedNameA(p0, p1)
#define WinAPI_GetFileAttributes(lpFileName)	GetFileAttributesA(lpFileName)
#define WinAPI_GetFileSecurity(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)	GetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)
#define WinAPI_GetFileVersionInfo(lptstrFilename, dwHandle, dwLen, lpData)	GetFileVersionInfoA(lptstrFilename, dwHandle, dwLen, lpData)
#define WinAPI_GetFileVersionInfoSize(lptstrFilename, lpdwHandle)	GetFileVersionInfoSizeA(lptstrFilename, lpdwHandle)
#define WinAPI_GetForm(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)	GetFormA(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)
#define WinAPI_GetFullPathName(lpFileName, nBufferLength, lpBuffer, lpFilePart)	GetFullPathNameA(lpFileName, nBufferLength, lpBuffer, lpFilePart)
#define WinAPI_GetGlyphOutline(p0, p1, p2, p3, p4, p5, p6)	GetGlyphOutlineA(p0, p1, p2, p3, p4, p5, p6)
#define WinAPI_GetICMProfile(p0, p1, p2)	GetICMProfileA(p0, p1, p2)
#define WinAPI_GetJob(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)	GetJobA(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)
#define WinAPI_GetKerningPairs(p0, p1, p2)	GetKerningPairsA(p0, p1, p2)
#define WinAPI_GetKeyNameText(lParam, lpString, nSize)	GetKeyNameTextA(lParam, lpString, nSize)
#define WinAPI_GetKeyboardLayoutName(pwszKLID)	GetKeyboardLayoutNameA(pwszKLID)
#define WinAPI_GetLocaleInfo(Locale, LCType, lpLCData, cchData)	GetLocaleInfoA(Locale, LCType, lpLCData, cchData)
#define WinAPI_GetLogColorSpace(p0, p1, p2)	GetLogColorSpaceA(p0, p1, p2)
#define WinAPI_GetLogicalDriveStrings(nBufferLength, lpBuffer)	GetLogicalDriveStringsA(nBufferLength, lpBuffer)
#define WinAPI_GetMenuItemInfo(p0, p1, p2, p3)	GetMenuItemInfoA(p0, p1, p2, p3)
#define WinAPI_GetMenuString(hMenu, uIDItem, lpString, nMaxCount, uFlag)	GetMenuStringA(hMenu, uIDItem, lpString, nMaxCount, uFlag)
#define WinAPI_GetMessage(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)	GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)
#define WinAPI_GetMetaFile(p0)	GetMetaFileA(p0)
#define WinAPI_GetModuleFileName(hModule, lpFilename, nSize)	GetModuleFileNameA(hModule, lpFilename, nSize)
#define WinAPI_GetModuleHandle(lpModuleName)	GetModuleHandleA(lpModuleName)
#define WinAPI_GetNamedPipeHandleState(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)	GetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)
#define WinAPI_GetNumberFormat(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)	GetNumberFormatA(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)
#define WinAPI_GetObject(p0, p1, p2)	GetObjectA(p0, p1, p2)
#define WinAPI_GetOutlineTextMetrics(p0, p1, p2)	GetOutlineTextMetricsA(p0, p1, p2)
#define WinAPI_GetPrintProcessorDirectory(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)	GetPrintProcessorDirectoryA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)
#define WinAPI_GetPrinter(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)	GetPrinterA(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)
#define WinAPI_GetPrinterData(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)	GetPrinterDataA(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)
#define WinAPI_GetPrinterDriver(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)	GetPrinterDriverA(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)
#define WinAPI_GetPrinterDriverDirectory(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)	GetPrinterDriverDirectoryA(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)
#define WinAPI_GetPrivateProfileInt(lpAppName, lpKeyName, nDefault, lpFileName)	GetPrivateProfileIntA(lpAppName, lpKeyName, nDefault, lpFileName)
#define WinAPI_GetPrivateProfileSection(lpAppName, lpReturnedString, nSize, lpFileName)	GetPrivateProfileSectionA(lpAppName, lpReturnedString, nSize, lpFileName)
#define WinAPI_GetPrivateProfileSectionNames(lpszReturnBuffer, nSize, lpFileName)	GetPrivateProfileSectionNamesA(lpszReturnBuffer, nSize, lpFileName)
#define WinAPI_GetPrivateProfileString(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)	GetPrivateProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)
#define WinAPI_GetPrivateProfileStruct(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	GetPrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
#define WinAPI_GetProfileInt(lpAppName, lpKeyName, nDefault)	GetProfileIntA(lpAppName, lpKeyName, nDefault)
#define WinAPI_GetProfileSection(lpAppName, lpReturnedString, nSize)	GetProfileSectionA(lpAppName, lpReturnedString, nSize)
#define WinAPI_GetProfileString(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)	GetProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)
#define WinAPI_GetProp(hWnd, lpString)	GetPropA(hWnd, lpString)
#define WinAPI_GetServiceDisplayName(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)	GetServiceDisplayNameA(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)
#define WinAPI_GetServiceKeyName(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)	GetServiceKeyNameA(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)
#define WinAPI_GetShortPathName(lpszLongPath, lpszShortPath, cchBuffer)	GetShortPathNameA(lpszLongPath, lpszShortPath, cchBuffer)
#define WinAPI_GetStartupInfo(lpStartupInfo)	GetStartupInfoA(lpStartupInfo)
#define WinAPI_GetStringTypeEx(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeExA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)
#define WinAPI_GetSystemDirectory(lpBuffer, uSize)	GetSystemDirectoryA(lpBuffer, uSize)
#define WinAPI_GetTabbedTextExtent(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)	GetTabbedTextExtentA(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)
#define WinAPI_GetTempFileName(lpPathName, lpPrefixString, uUnique, lpTempFileName)	GetTempFileNameA(lpPathName, lpPrefixString, uUnique, lpTempFileName)
#define WinAPI_GetTempPath(nBufferLength, lpBuffer)	GetTempPathA(nBufferLength, lpBuffer)
#define WinAPI_GetTextExtentExPoint(p0, p1, p2, p3, p4, p5, p6)	GetTextExtentExPointA(p0, p1, p2, p3, p4, p5, p6)
#define WinAPI_GetTextExtentPoint(p0, p1, p2, p3)	GetTextExtentPointA(p0, p1, p2, p3)
#define WinAPI_GetTextExtentPoint32(p0, p1, p2, p3)	GetTextExtentPoint32A(p0, p1, p2, p3)
#define WinAPI_GetTextFace(p0, p1, p2)	GetTextFaceA(p0, p1, p2)
#define WinAPI_GetTextMetrics(p0, p1)	GetTextMetricsA(p0, p1)
#define WinAPI_GetTimeFormat(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)	GetTimeFormatA(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)
#define WinAPI_GetUserName(lpBuffer, nSize)	GetUserNameA(lpBuffer, nSize)
#define WinAPI_GetUserObjectInformation(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)	GetUserObjectInformationA(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)
#define WinAPI_GetVersionEx(lpVersionInformation)	GetVersionExA(lpVersionInformation)
#define WinAPI_GetVolumeInformation(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)	GetVolumeInformationA(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)
#define WinAPI_GetWindowLong(hWnd, nIndex)	GetWindowLongA(hWnd, nIndex)
#define WinAPI_GetWindowText(hWnd, lpString, nMaxCount)	GetWindowTextA(hWnd, lpString, nMaxCount)
#define WinAPI_GetWindowTextLength(hWnd)	GetWindowTextLengthA(hWnd)
#define WinAPI_GetWindowsDirectory(lpBuffer, uSize)	GetWindowsDirectoryA(lpBuffer, uSize)
#define WinAPI_GlobalAddAtom(lpString)	GlobalAddAtomA(lpString)
#define WinAPI_GlobalFindAtom(lpString)	GlobalFindAtomA(lpString)
#define WinAPI_GlobalGetAtomName(nAtom, lpBuffer, nSize)	GlobalGetAtomNameA(nAtom, lpBuffer, nSize)
#define WinAPI_GrayString(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)	GrayStringA(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)
#define WinAPI_InitiateSystemShutdown(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)	InitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)
#define WinAPI_InsertMenu(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)	InsertMenuA(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)
#define WinAPI_InsertMenuItem(p0, p1, p2, p3)	InsertMenuItemA(p0, p1, p2, p3)
#define WinAPI_Instance()	__hInstance
#define WinAPI_IsBadStringPtr(lpsz, ucchMax)	IsBadStringPtrA(lpsz, ucchMax)
#define WinAPI_IsCharAlpha(ch)	IsCharAlphaA(ch)
#define WinAPI_IsCharAlphaNumeric(ch)	IsCharAlphaNumericA(ch)
#define WinAPI_IsCharLower(ch)	IsCharLowerA(ch)
#define WinAPI_IsCharUpper(ch)	IsCharUpperA(ch)
#define WinAPI_IsDialogMessage(hDlg, lpMsg)	IsDialogMessageA(hDlg, lpMsg)
#define WinAPI_LCMapString(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
#define WinAPI_LZOpenFile(p0, p1, p2)	LZOpenFileA(p0, p1, p2)
#define WinAPI_LoadAccelerators(hInstance, lpTableName)	LoadAcceleratorsA(hInstance, lpTableName)
#define WinAPI_LoadBitmap(hInstance, lpBitmapName)	LoadBitmapA(hInstance, lpBitmapName)
#define WinAPI_LoadCursor(hInstance, lpCursorName)	LoadCursorA(hInstance, lpCursorName)
#define WinAPI_LoadCursorFromFile(lpFileName)	LoadCursorFromFileA(lpFileName)
#define WinAPI_LoadIcon(hInstance, lpIconName)	LoadIconA(hInstance, lpIconName)
#define WinAPI_LoadImage(p0, p1, p2, p3, p4, p5)	LoadImageA(p0, p1, p2, p3, p4, p5)
#define WinAPI_LoadKeyboardLayout(pwszKLID, Flags)	LoadKeyboardLayoutA(pwszKLID, Flags)
#define WinAPI_LoadLibrary(lpLibFileName)	LoadLibraryA(lpLibFileName)
#define WinAPI_LoadLibraryEx(lpLibFileName, hFile, dwFlags)	LoadLibraryExA(lpLibFileName, hFile, dwFlags)
#define WinAPI_LoadMenu(hInstance, lpMenuName)	LoadMenuA(hInstance, lpMenuName)
#define WinAPI_LoadMenuIndirect(lpMenuTemplate)	LoadMenuIndirectA(lpMenuTemplate)
#define WinAPI_LoadString(hInstance, uID, lpBuffer, nBufferMax)	LoadStringA(hInstance, uID, lpBuffer, nBufferMax)
#define WinAPI_LogonUser(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)	LogonUserA(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)
#define WinAPI_LookupAccountName(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountNameA(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)
#define WinAPI_LookupAccountSid(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountSidA(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)
#define WinAPI_LookupPrivilegeDisplayName(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)	LookupPrivilegeDisplayNameA(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)
#define WinAPI_LookupPrivilegeName(lpSystemName, lpLuid, lpName, cbName)	LookupPrivilegeNameA(lpSystemName, lpLuid, lpName, cbName)
#define WinAPI_LookupPrivilegeValue(lpSystemName, lpName, lpLuid)	LookupPrivilegeValueA(lpSystemName, lpName, lpLuid)
#define WinAPI_MapVirtualKey(uCode, uMapType)	MapVirtualKeyA(uCode, uMapType)
#define WinAPI_MapVirtualKeyEx(uCode, uMapType, dwhkl)	MapVirtualKeyExA(uCode, uMapType, dwhkl)
#define WinAPI_MessageBox(hWnd, lpText, lpCaption, uType)	MessageBoxA(hWnd, lpText, lpCaption, uType)
#define WinAPI_MessageBoxEx(hWnd, lpText, lpCaption, uType, wLanguageId)	MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId)
#define WinAPI_MessageBoxIndirect(p0)	MessageBoxIndirectA(p0)
#define WinAPI_ModifyMenu(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)	ModifyMenuA(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)
#define WinAPI_MoveFile(lpExistingFileName, lpNewFileName)	MoveFileA(lpExistingFileName, lpNewFileName)
#define WinAPI_MoveFileEx(lpExistingFileName, lpNewFileName, dwFlags)	MoveFileExA(lpExistingFileName, lpNewFileName, dwFlags)
#define WinAPI_ObjectCloseAuditAlarm(SubsystemName, HandleId, GenerateOnClose)	ObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose)
#define WinAPI_ObjectOpenAuditAlarm(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)	ObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)
#define WinAPI_ObjectPrivilegeAuditAlarm(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)	ObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)
#define WinAPI_OemToAnsi(lpszSrc, lpszDst)	OemToCharA(lpszSrc, lpszDst)
#define WinAPI_OemToAnsiBuff(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinAPI_OemToChar(lpszSrc, lpszDst)	OemToCharA(lpszSrc, lpszDst)
#define WinAPI_OemToCharBuff(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinAPI_OpenBackupEventLog(lpUNCServerName, lpFileName)	OpenBackupEventLogA(lpUNCServerName, lpFileName)
#define WinAPI_OpenDesktop(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)	OpenDesktopA(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)
#define WinAPI_OpenEvent(dwDesiredAccess, bInheritHandle, lpName)	OpenEventA(dwDesiredAccess, bInheritHandle, lpName)
#define WinAPI_OpenEventLog(lpUNCServerName, lpSourceName)	OpenEventLogA(lpUNCServerName, lpSourceName)
#define WinAPI_OpenFileMapping(dwDesiredAccess, bInheritHandle, lpName)	OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName)
#define WinAPI_OpenMutex(dwDesiredAccess, bInheritHandle, lpName)	OpenMutexA(dwDesiredAccess, bInheritHandle, lpName)
#define WinAPI_OpenPrinter(pPrinterName, phPrinter, pDefault)	OpenPrinterA(pPrinterName, phPrinter, pDefault)
#define WinAPI_OpenSCManager(lpMachineName, lpDatabaseName, dwDesiredAccess)	OpenSCManagerA(lpMachineName, lpDatabaseName, dwDesiredAccess)
#define WinAPI_OpenSemaphore(dwDesiredAccess, bInheritHandle, lpName)	OpenSemaphoreA(dwDesiredAccess, bInheritHandle, lpName)
#define WinAPI_OpenService(hSCManager, lpServiceName, dwDesiredAccess)	OpenServiceA(hSCManager, lpServiceName, dwDesiredAccess)
#define WinAPI_OpenWaitableTimer(dwDesiredAccess, bInheritHandle, lpTimerName)	OpenWaitableTimerA(dwDesiredAccess, bInheritHandle, lpTimerName)
#define WinAPI_OpenWindowStation(lpszWinSta, fInherit, dwDesiredAccess)	OpenWindowStationA(lpszWinSta, fInherit, dwDesiredAccess)
#define WinAPI_OutputDebugString(lpOutputString)	OutputDebugStringA(lpOutputString)
#define WinAPI_PeekConsoleInput(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)	PeekConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
#define WinAPI_PeekMessage(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)	PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)
#define WinAPI_PolyTextOut(p0, p1, p2)	PolyTextOutA(p0, p1, p2)
#define WinAPI_PostMessage(hWnd, Msg, wParam, lParam)	PostMessageA(hWnd, Msg, wParam, lParam)
#define WinAPI_PostThreadMessage(idThread, Msg, wParam, lParam)	PostThreadMessageA(idThread, Msg, wParam, lParam)
#define WinAPI_PrevInstance()	__hPrevInstance
#define WinAPI_PrinterMessageBox(hPrinter, Error, hWnd, pText, pCaption, dwType)	PrinterMessageBoxA(hPrinter, Error, hWnd, pText, pCaption, dwType)
#define WinAPI_PrivilegedServiceAuditAlarm(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)	PrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)
#define WinAPI_PropertySheet(p0)	PropertySheetA(p0)
#define WinAPI_QueryDosDevice(lpDeviceName, lpTargetPath, ucchMax)	QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax)
#define WinAPI_QueryServiceConfig(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)	QueryServiceConfigA(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)
#define WinAPI_QueryServiceLockStatus(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)	QueryServiceLockStatusA(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)
#define WinAPI_ReadConsole(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)	ReadConsoleA(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)
#define WinAPI_ReadConsoleInput(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)	ReadConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
#define WinAPI_ReadConsoleOutput(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)	ReadConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)
#define WinAPI_ReadConsoleOutputCharacter(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)	ReadConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)
#define WinAPI_ReadEventLog(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)	ReadEventLogA(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)
#define WinAPI_RegConnectRegistry(lpMachineName, hKey, phkResult)	RegConnectRegistryA(lpMachineName, hKey, phkResult)
#define WinAPI_RegCreateKey(hKey, lpSubKey, phkResult)	RegCreateKeyA(hKey, lpSubKey, phkResult)
#define WinAPI_RegCreateKeyEx(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)	RegCreateKeyExA(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)
#define WinAPI_RegDeleteKey(hKey, lpSubKey)	RegDeleteKeyA(hKey, lpSubKey)
#define WinAPI_RegDeleteValue(hKey, lpValueName)	RegDeleteValueA(hKey, lpValueName)
#define WinAPI_RegEnumKey(hKey, dwIndex, lpName, cbName)	RegEnumKeyA(hKey, dwIndex, lpName, cbName)
#define WinAPI_RegEnumKeyEx(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)	RegEnumKeyExA(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)
#define WinAPI_RegEnumValue(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)	RegEnumValueA(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)
#define WinAPI_RegLoadKey(hKey, lpSubKey, lpFile)	RegLoadKeyA(hKey, lpSubKey, lpFile)
#define WinAPI_RegOpenKey(hKey, lpSubKey, phkResult)	RegOpenKeyA(hKey, lpSubKey, phkResult)
#define WinAPI_RegOpenKeyEx(hKey, lpSubKey, ulOptions, samDesired, phkResult)	RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult)
#define WinAPI_RegQueryInfoKey(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)	RegQueryInfoKeyA(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)
#define WinAPI_RegQueryMultipleValues(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)	RegQueryMultipleValuesA(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)
#define WinAPI_RegQueryValue(hKey, lpSubKey, lpValue, lpcbValue)	RegQueryValueA(hKey, lpSubKey, lpValue, lpcbValue)
#define WinAPI_RegQueryValueEx(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)	RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)
#define WinAPI_RegReplaceKey(hKey, lpSubKey, lpNewFile, lpOldFile)	RegReplaceKeyA(hKey, lpSubKey, lpNewFile, lpOldFile)
#define WinAPI_RegRestoreKey(hKey, lpFile, dwFlags)	RegRestoreKeyA(hKey, lpFile, dwFlags)
#define WinAPI_RegSaveKey(hKey, lpFile, lpSecurityAttributes)	RegSaveKeyA(hKey, lpFile, lpSecurityAttributes)
#define WinAPI_RegSetValue(hKey, lpSubKey, dwType, lpData, cbData)	RegSetValueA(hKey, lpSubKey, dwType, lpData, cbData)
#define WinAPI_RegSetValueEx(hKey, lpValueName, Reserved, dwType, lpData, cbData)	RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData)
#define WinAPI_RegUnLoadKey(hKey, lpSubKey)	RegUnLoadKeyA(hKey, lpSubKey)
#define WinAPI_RegisterClass(lpWndClass)	RegisterClassA(lpWndClass)
#define WinAPI_RegisterClassEx(p0)	RegisterClassExA(p0)
#define WinAPI_RegisterClipboardFormat(lpszFormat)	RegisterClipboardFormatA(lpszFormat)
#define WinAPI_RegisterEventSource(lpUNCServerName, lpSourceName)	RegisterEventSourceA(lpUNCServerName, lpSourceName)
#define WinAPI_RegisterServiceCtrlHandler(lpServiceName, lpHandlerProc)	RegisterServiceCtrlHandlerA(lpServiceName, lpHandlerProc)
#define WinAPI_RegisterWindowMessage(lpString)	RegisterWindowMessageA(lpString)
#define WinAPI_RemoveDirectory(lpPathName)	RemoveDirectoryA(lpPathName)
#define WinAPI_RemoveFontResource(p0)	RemoveFontResourceA(p0)
#define WinAPI_RemoveProp(hWnd, lpString)	RemovePropA(hWnd, lpString)
#define WinAPI_ReportEvent(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)	ReportEventA(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)
#define WinAPI_ResetDC(p0, p1)	ResetDCA(p0, p1)
#define WinAPI_ResetPrinter(hPrinter, pDefault)	ResetPrinterA(hPrinter, pDefault)
#define WinAPI_SHFileOperation(lpFileOp)	SHFileOperationA(lpFileOp)
#define WinAPI_SHGetFileInfo(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)	SHGetFileInfoA(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)
#define WinAPI_SHGetNewLinkInfo(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)	SHGetNewLinkInfoA(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)
#define WinAPI_ScrollConsoleScreenBuffer(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)	ScrollConsoleScreenBufferA(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)
#define WinAPI_SearchPath(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)	SearchPathA(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)
#define WinAPI_SendDlgItemMessage(hDlg, nIDDlgItem, Msg, wParam, lParam)	SendDlgItemMessageA(hDlg, nIDDlgItem, Msg, wParam, lParam)
#define WinAPI_SendMessage(hWnd, Msg, wParam, lParam)	SendMessageA(hWnd, Msg, wParam, lParam)
#define WinAPI_SendMessageCallback(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)	SendMessageCallbackA(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)
#define WinAPI_SendMessageTimeout(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)	SendMessageTimeoutA(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)
#define WinAPI_SendNotifyMessage(hWnd, Msg, wParam, lParam)	SendNotifyMessageA(hWnd, Msg, wParam, lParam)
#define WinAPI_SetClassLong(hWnd, nIndex, dwNewLong)	SetClassLongA(hWnd, nIndex, dwNewLong)
#define WinAPI_SetComputerName(lpComputerName)	SetComputerNameA(lpComputerName)
#define WinAPI_SetConsoleTitle(lpConsoleTitle)	SetConsoleTitleA(lpConsoleTitle)
#define WinAPI_SetCurrentDirectory(lpPathName)	SetCurrentDirectoryA(lpPathName)
#define WinAPI_SetDefaultCommConfig(lpszName, lpCC, dwSize)	SetDefaultCommConfigA(lpszName, lpCC, dwSize)
#define WinAPI_SetDlgItemText(hDlg, nIDDlgItem, lpString)	SetDlgItemTextA(hDlg, nIDDlgItem, lpString)
#define WinAPI_SetEnvironmentVariable(lpName, lpValue)	SetEnvironmentVariableA(lpName, lpValue)
#define WinAPI_SetFileAttributes(lpFileName, dwFileAttributes)	SetFileAttributesA(lpFileName, dwFileAttributes)
#define WinAPI_SetFileSecurity(lpFileName, SecurityInformation, pSecurityDescriptor)	SetFileSecurityA(lpFileName, SecurityInformation, pSecurityDescriptor)
#define WinAPI_SetForm(hPrinter, pFormName, Level, pForm)	SetFormA(hPrinter, pFormName, Level, pForm)
#define WinAPI_SetICMProfile(p0, p1)	SetICMProfileA(p0, p1)
#define WinAPI_SetJob(hPrinter, JobId, Level, pJob, Command)	SetJobA(hPrinter, JobId, Level, pJob, Command)
#define WinAPI_SetLocaleInfo(Locale, LCType, lpLCData)	SetLocaleInfoA(Locale, LCType, lpLCData)
#define WinAPI_SetMenuItemInfo(p0, p1, p2, p3)	SetMenuItemInfoA(p0, p1, p2, p3)
#define WinAPI_SetPrinter(hPrinter, Level, pPrinter, Command)	SetPrinterA(hPrinter, Level, pPrinter, Command)
#define WinAPI_SetPrinterData(hPrinter, pValueName, Type, pData, cbData)	SetPrinterDataA(hPrinter, pValueName, Type, pData, cbData)
#define WinAPI_SetProp(hWnd, lpString, hData)	SetPropA(hWnd, lpString, hData)
#define WinAPI_SetUserObjectInformation(hObj, nIndex, pvInfo, nLength)	SetUserObjectInformationA(hObj, nIndex, pvInfo, nLength)
#define WinAPI_SetVolumeLabel(lpRootPathName, lpVolumeName)	SetVolumeLabelA(lpRootPathName, lpVolumeName)
#define WinAPI_SetWindowLong(hWnd, nIndex, dwNewLong)	SetWindowLongA(hWnd, nIndex, dwNewLong)
#define WinAPI_SetWindowText(hWnd, lpString)	SetWindowTextA(hWnd, lpString)
#define WinAPI_SetWindowsHook(nFilterType, pfnFilterProc)	SetWindowsHookA(nFilterType, pfnFilterProc)
#define WinAPI_SetWindowsHookEx(idHook, lpfn, hmod, dwThreadId)	SetWindowsHookExA(idHook, lpfn, hmod, dwThreadId)
#define WinAPI_ShellAbout(hWnd, szApp, szOtherStuff, hIcon)	ShellAboutA(hWnd, szApp, szOtherStuff, hIcon)
#define WinAPI_ShellExecute(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)	ShellExecuteA(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)
#define WinAPI_ShellExecuteEx(lpExecInfo)	ShellExecuteExA(lpExecInfo)
#define WinAPI_Shell_NotifyIcon(dwMessage, lpData)	Shell_NotifyIconA(dwMessage, lpData)
#define WinAPI_StartDoc(p0, p1)	StartDocA(p0, p1)
#define WinAPI_StartDocPrinter(hPrinter, Level, pDocInfo)	StartDocPrinterA(hPrinter, Level, pDocInfo)
#define WinAPI_StartService(hService, dwNumServiceArgs, lpServiceArgVectors)	StartServiceA(hService, dwNumServiceArgs, lpServiceArgVectors)
#define WinAPI_StartServiceCtrlDispatcher(lpServiceStartTable)	StartServiceCtrlDispatcherA(lpServiceStartTable)
#define WinAPI_SystemParametersInfo(uiAction, uiParam, pvParam, fWinIni)	SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni)
#define WinAPI_TabbedTextOut(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)	TabbedTextOutA(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)
#define WinAPI_TextOut(p0, p1, p2, p3, p4)	TextOutA(p0, p1, p2, p3, p4)
#define WinAPI_TranslateAccelerator(hWnd, hAccTable, lpMsg)	TranslateAcceleratorA(hWnd, hAccTable, lpMsg)
#define WinAPI_UnregisterClass(lpClassName, hInstance)	UnregisterClassA(lpClassName, hInstance)
#define WinAPI_UpdateResource(hUpdate, lpType, lpName, wLanguage, lpData, cbData)	UpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cbData)
#define WinAPI_VerFindFile(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)	VerFindFileA(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)
#define WinAPI_VerInstallFile(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)	VerInstallFileA(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)
#define WinAPI_VerLanguageName(wLang, szLang, nSize)	VerLanguageNameA(wLang, szLang, nSize)
#define WinAPI_VerQueryValue(pBlock, lpSubBlock, lplpBuffer, puLen)	VerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen)
#define WinAPI_VkKeyScan(ch)	VkKeyScanA(ch)
#define WinAPI_VkKeyScanEx(ch, dwhkl)	VkKeyScanExA(ch, dwhkl)
#define WinAPI_WaitNamedPipe(lpNamedPipeName, nTimeOut)	WaitNamedPipeA(lpNamedPipeName, nTimeOut)
#define WinAPI_WinHelp(hWndMain, lpszHelp, uCommand, dwData)	WinHelpA(hWndMain, lpszHelp, uCommand, dwData)
#define WinAPI_WriteConsole(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)	WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)
#define WinAPI_WriteConsoleInput(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)	WriteConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)
#define WinAPI_WriteConsoleOutput(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)	WriteConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)
#define WinAPI_WriteConsoleOutputCharacter(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	WriteConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
#define WinAPI_WritePrivateProfileSection(lpAppName, lpString, lpFileName)	WritePrivateProfileSectionA(lpAppName, lpString, lpFileName)
#define WinAPI_WritePrivateProfileString(lpAppName, lpKeyName, lpString, lpFileName)	WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName)
#define WinAPI_WritePrivateProfileStruct(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	WritePrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
#define WinAPI_WriteProfileSection(lpAppName, lpString)	WriteProfileSectionA(lpAppName, lpString)
#define WinAPI_WriteProfileString(lpAppName, lpKeyName, lpString)	WriteProfileStringA(lpAppName, lpKeyName, lpString)
#define WinAPI_lstrcat(lpString1, lpString2)	lstrcatA(lpString1, lpString2)
#define WinAPI_lstrcmp(lpString1, lpString2)	lstrcmpA(lpString1, lpString2)
#define WinAPI_lstrcmpi(lpString1, lpString2)	lstrcmpiA(lpString1, lpString2)
#define WinAPI_lstrcpy(lpString1, lpString2)	lstrcpyA(lpString1, lpString2)
#define WinAPI_lstrcpyn(lpString1, lpString2, iMaxLength)	lstrcpynA(lpString1, lpString2, iMaxLength)
#define WinAPI_lstrlen(lpString)	lstrlenA(lpString)
#define WinAPI_wglUseFontBitmaps(p0, p1, p2, p3)	wglUseFontBitmapsA(p0, p1, p2, p3)
#define WinAPI_wglUseFontOutlines(p0, p1, p2, p3, p4, p5, p6, p7)	wglUseFontOutlinesA(p0, p1, p2, p3, p4, p5, p6, p7)
#define WinAPI_wsprintf(p0, p1)	wsprintfA(p0, p1)
#define WinAPI_wvsprintf(p0, p1, arglist)	wvsprintfA(p0, p1, arglist)

#endif

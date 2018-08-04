/* Ofront+ 1.0 -s3 -88 */

#ifndef WinAPI__h
#define WinAPI__h

#include "SYSTEM.h"

struct WinAPI__18 {
	CHAR BaseMid, Flags1, Flags2, BaseHi;
};

struct WinAPI__19 {
	struct WinAPI__18 Bytes;
};

struct WinAPI__20 {
	LONGINT FiberData;
};

struct WinAPI__14 {
	INTEGER PhysicalAddress;
};

struct WinAPI__15 {
	CHAR ShortName[8];
};

struct WinAPI__3 {
	INTEGER TotalSize;
};

struct WinAPI__4 {
	INTEGER PointerToLinenumber, PointerToNextFunction;
};

struct WinAPI__5 {
	struct WinAPI__4 Function;
};

struct WinAPI__6 {
	INTEGER TagIndex;
	struct WinAPI__3 Misc;
	struct WinAPI__5 FcnAry;
	SHORTINT TvIndex;
};

struct WinAPI__10 {
	INTEGER VirtualAddress;
};

struct WinAPI__9 {
	INTEGER SymbolTableIndex;
};

struct WinAPI__7 {
	LONGINT ForwarderString;
};

typedef
	struct WinAPI_IMAGE_THUNK_DATA *WinAPI_PtrIMAGE_THUNK_DATA;

struct WinAPI__8 {
	WinAPI_PtrIMAGE_THUNK_DATA OriginalFirstThunk;
};

struct WinAPI__11 {
	SET fBits0;
};

struct WinAPI__12 {
	struct WinAPI__11 r;
};

struct WinAPI__13 {
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

struct WinAPI__23 {
	LONGINT hMem;
	INTEGER dwReserved[3];
};

struct WinAPI__24 {
	struct WinAPI__23 Block;
};

struct WinAPI__16 {
	SHORTINT UnicodeChar;
};

typedef
	struct WinAPI_KEY_EVENT_RECORD {
		INTEGER bKeyDown;
		SHORTINT wRepeatCount, wVirtualKeyCode, wVirtualScanCode;
		struct WinAPI__16 uChar;
		SET dwControlKeyState;
	} WinAPI_KEY_EVENT_RECORD;

struct WinAPI__17 {
	WinAPI_KEY_EVENT_RECORD KeyEvent;
};

struct WinAPI__1 {
	SHORTINT UnicodeChar;
};

struct WinAPI__27 {
	LONGINT pszTemplate;
};

struct WinAPI__28 {
	LONGINT hIcon;
};

struct WinAPI__32 {
	LONGINT pszTemplate;
};

struct WinAPI__33 {
	LONGINT hIcon;
};

struct WinAPI__25 {
	LONGINT hIcon;
};

struct WinAPI__26 {
	LONGINT pStartPage;
};

typedef
	struct WinAPI_PROPSHEETPAGEA *WinAPI_PtrPROPSHEETPAGEA;

struct WinAPI__29 {
	WinAPI_PtrPROPSHEETPAGEA ppsp;
};

struct WinAPI__30 {
	LONGINT hIcon;
};

struct WinAPI__31 {
	LONGINT pStartPage;
};

typedef
	struct WinAPI_PROPSHEETPAGEW *WinAPI_PtrPROPSHEETPAGEW;

struct WinAPI__34 {
	WinAPI_PtrPROPSHEETPAGEW ppsp;
};

struct WinAPI__21 {
	INTEGER cbBuf;
	LONGINT pBuf;
};

struct WinAPI__22 {
	struct WinAPI__21 Data;
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
		struct WinAPI__6 Sym;
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
		struct WinAPI__8 u;
		INTEGER TimeDateStamp, ForwarderChain, Name;
		WinAPI_PtrIMAGE_THUNK_DATA FirstThunk;
	} WinAPI_IMAGE_IMPORT_DESCRIPTOR;

typedef
	struct WinAPI_IMAGE_LINENUMBER {
		struct WinAPI__9 Type;
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
		struct WinAPI__10 u;
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
		struct WinAPI__12 u;
		struct WinAPI__13 u1;
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
		struct WinAPI__14 Misc;
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
		struct WinAPI__15 N;
		INTEGER Value;
		SHORTINT SectionNumber, Type;
		CHAR StorageClass, NumberOfAuxSymbols;
	} WinAPI_IMAGE_SYMBOL;

typedef
	struct WinAPI_IMAGE_THUNK_DATA {
		struct WinAPI__7 u1;
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
		struct WinAPI__17 Event;
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
		struct WinAPI__19 HighWord;
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
		struct WinAPI__20 u;
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
		struct WinAPI__22 NotifyData;
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
		struct WinAPI__24 u;
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
		struct WinAPI__25 u;
		LONGINT pszCaption;
		INTEGER nPages;
		struct WinAPI__26 u1;
		struct WinAPI__29 u2;
		WinAPI_FNPROPSHEETCALLBACK pfnCallback;
	} WinAPI_PROPSHEETHEADERA;

typedef
	struct WinAPI_PROPSHEETHEADERW {
		INTEGER dwSize;
		SET dwFlags;
		LONGINT hwndParent, hInstance;
		struct WinAPI__30 u;
		LONGINT pszCaption;
		INTEGER nPages;
		struct WinAPI__31 u1;
		struct WinAPI__34 u2;
		WinAPI_FNPROPSHEETCALLBACK pfnCallback;
	} WinAPI_PROPSHEETHEADERW;

typedef
	struct WinAPI_PROPSHEETPAGEA {
		INTEGER dwSize;
		SET dwFlags;
		LONGINT hInstance;
		struct WinAPI__27 u;
		struct WinAPI__28 u1;
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
		struct WinAPI__32 u;
		struct WinAPI__33 u1;
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




import void *WinAPI__init(void);

__EXTERN INTEGER __STDCALL AbortDoc(LONGINT p0);
#define WinAPI_AbortDoc(p0)	AbortDoc(p0)
__EXTERN INTEGER __STDCALL AbortPath(LONGINT p0);
#define WinAPI_AbortPath(p0)	AbortPath(p0)
__EXTERN INTEGER __STDCALL AbortPrinter(LONGINT hPrinter);
#define WinAPI_AbortPrinter(hPrinter)	AbortPrinter(hPrinter)
#define WinAPI_AbortSystemShutdown(lpMachineName)	AbortSystemShutdownA(lpMachineName)
__EXTERN INTEGER __STDCALL AbortSystemShutdownA(LONGINT lpMachineName);
#define WinAPI_AbortSystemShutdownA(lpMachineName)	AbortSystemShutdownA(lpMachineName)
__EXTERN INTEGER __STDCALL AbortSystemShutdownW(LONGINT lpMachineName);
#define WinAPI_AbortSystemShutdownW(lpMachineName)	AbortSystemShutdownW(lpMachineName)
__EXTERN INTEGER __STDCALL AccessCheck(LONGINT pSecurityDescriptor, LONGINT ClientToken, SET DesiredAccess, WinAPI_GENERIC_MAPPING *GenericMapping, WinAPI_PRIVILEGE_SET *PrivilegeSet, INTEGER *PrivilegeSetLength, INTEGER *GrantedAccess, INTEGER *AccessStatus);
#define WinAPI_AccessCheck(pSecurityDescriptor, ClientToken, DesiredAccess, GenericMapping, PrivilegeSet, PrivilegeSetLength, GrantedAccess, AccessStatus)	AccessCheck(pSecurityDescriptor, ClientToken, DesiredAccess, GenericMapping, PrivilegeSet, PrivilegeSetLength, GrantedAccess, AccessStatus)
#define WinAPI_AccessCheckAndAuditAlarm(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)	AccessCheckAndAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)
__EXTERN INTEGER __STDCALL AccessCheckAndAuditAlarmA(LONGINT SubsystemName, LONGINT HandleId, LONGINT ObjectTypeName, LONGINT ObjectName, LONGINT SecurityDescriptor, SET DesiredAccess, WinAPI_GENERIC_MAPPING *GenericMapping, INTEGER ObjectCreation, INTEGER *GrantedAccess, INTEGER *AccessStatus, INTEGER *pfGenerateOnClose);
#define WinAPI_AccessCheckAndAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)	AccessCheckAndAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)
__EXTERN INTEGER __STDCALL AccessCheckAndAuditAlarmW(LONGINT SubsystemName, LONGINT HandleId, LONGINT ObjectTypeName, LONGINT ObjectName, LONGINT SecurityDescriptor, SET DesiredAccess, WinAPI_GENERIC_MAPPING *GenericMapping, INTEGER ObjectCreation, INTEGER *GrantedAccess, INTEGER *AccessStatus, INTEGER *pfGenerateOnClose);
#define WinAPI_AccessCheckAndAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)	AccessCheckAndAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)
__EXTERN LONGINT __STDCALL ActivateKeyboardLayout(LONGINT hkl, SET Flags);
#define WinAPI_ActivateKeyboardLayout(hkl, Flags)	ActivateKeyboardLayout(hkl, Flags)
__EXTERN INTEGER __STDCALL AddAccessAllowedAce(WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER AccessMask, LONGINT pSid);
#define WinAPI_AddAccessAllowedAce(pAcl, dwAceRevision, AccessMask, pSid)	AddAccessAllowedAce(pAcl, dwAceRevision, AccessMask, pSid)
__EXTERN INTEGER __STDCALL AddAccessDeniedAce(WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER AccessMask, LONGINT pSid);
#define WinAPI_AddAccessDeniedAce(pAcl, dwAceRevision, AccessMask, pSid)	AddAccessDeniedAce(pAcl, dwAceRevision, AccessMask, pSid)
__EXTERN INTEGER __STDCALL AddAce(WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER dwStartingAceIndex, LONGINT pAceList, INTEGER nAceListLength);
#define WinAPI_AddAce(pAcl, dwAceRevision, dwStartingAceIndex, pAceList, nAceListLength)	AddAce(pAcl, dwAceRevision, dwStartingAceIndex, pAceList, nAceListLength)
#define WinAPI_AddAtom(lpString)	AddAtomA(lpString)
__EXTERN SHORTINT __STDCALL AddAtomA(LONGINT lpString);
#define WinAPI_AddAtomA(lpString)	AddAtomA(lpString)
__EXTERN SHORTINT __STDCALL AddAtomW(LONGINT lpString);
#define WinAPI_AddAtomW(lpString)	AddAtomW(lpString)
__EXTERN INTEGER __STDCALL AddAuditAccessAce(WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER dwAccessMask, LONGINT pSid, INTEGER bAuditSuccess, INTEGER bAuditFailure);
#define WinAPI_AddAuditAccessAce(pAcl, dwAceRevision, dwAccessMask, pSid, bAuditSuccess, bAuditFailure)	AddAuditAccessAce(pAcl, dwAceRevision, dwAccessMask, pSid, bAuditSuccess, bAuditFailure)
#define WinAPI_AddFontResource(p0)	AddFontResourceA(p0)
__EXTERN INTEGER __STDCALL AddFontResourceA(LONGINT p0);
#define WinAPI_AddFontResourceA(p0)	AddFontResourceA(p0)
__EXTERN INTEGER __STDCALL AddFontResourceW(LONGINT p0);
#define WinAPI_AddFontResourceW(p0)	AddFontResourceW(p0)
#define WinAPI_AddForm(hPrinter, Level, pForm)	AddFormA(hPrinter, Level, pForm)
__EXTERN INTEGER __STDCALL AddFormA(LONGINT hPrinter, INTEGER Level, CHAR *pForm);
#define WinAPI_AddFormA(hPrinter, Level, pForm)	AddFormA(hPrinter, Level, pForm)
__EXTERN INTEGER __STDCALL AddFormW(LONGINT hPrinter, INTEGER Level, CHAR *pForm);
#define WinAPI_AddFormW(hPrinter, Level, pForm)	AddFormW(hPrinter, Level, pForm)
#define WinAPI_AddJob(hPrinter, Level, pData, cbBuf, pcbNeeded)	AddJobA(hPrinter, Level, pData, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL AddJobA(LONGINT hPrinter, INTEGER Level, CHAR *pData, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_AddJobA(hPrinter, Level, pData, cbBuf, pcbNeeded)	AddJobA(hPrinter, Level, pData, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL AddJobW(LONGINT hPrinter, INTEGER Level, CHAR *pData, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_AddJobW(hPrinter, Level, pData, cbBuf, pcbNeeded)	AddJobW(hPrinter, Level, pData, cbBuf, pcbNeeded)
#define WinAPI_AddMonitor(pName, Level, pMonitors)	AddMonitorA(pName, Level, pMonitors)
__EXTERN INTEGER __STDCALL AddMonitorA(LONGINT pName, INTEGER Level, CHAR *pMonitors);
#define WinAPI_AddMonitorA(pName, Level, pMonitors)	AddMonitorA(pName, Level, pMonitors)
__EXTERN INTEGER __STDCALL AddMonitorW(LONGINT pName, INTEGER Level, CHAR *pMonitors);
#define WinAPI_AddMonitorW(pName, Level, pMonitors)	AddMonitorW(pName, Level, pMonitors)
#define WinAPI_AddPort(pName, hWnd, pMonitorName)	AddPortA(pName, hWnd, pMonitorName)
__EXTERN INTEGER __STDCALL AddPortA(LONGINT pName, LONGINT hWnd, LONGINT pMonitorName);
#define WinAPI_AddPortA(pName, hWnd, pMonitorName)	AddPortA(pName, hWnd, pMonitorName)
__EXTERN INTEGER __STDCALL AddPortW(LONGINT pName, LONGINT hWnd, LONGINT pMonitorName);
#define WinAPI_AddPortW(pName, hWnd, pMonitorName)	AddPortW(pName, hWnd, pMonitorName)
#define WinAPI_AddPrintProcessor(pName, pEnvironment, pPathName, pPrintProcessorName)	AddPrintProcessorA(pName, pEnvironment, pPathName, pPrintProcessorName)
__EXTERN INTEGER __STDCALL AddPrintProcessorA(LONGINT pName, LONGINT pEnvironment, LONGINT pPathName, LONGINT pPrintProcessorName);
#define WinAPI_AddPrintProcessorA(pName, pEnvironment, pPathName, pPrintProcessorName)	AddPrintProcessorA(pName, pEnvironment, pPathName, pPrintProcessorName)
__EXTERN INTEGER __STDCALL AddPrintProcessorW(LONGINT pName, LONGINT pEnvironment, LONGINT pPathName, LONGINT pPrintProcessorName);
#define WinAPI_AddPrintProcessorW(pName, pEnvironment, pPathName, pPrintProcessorName)	AddPrintProcessorW(pName, pEnvironment, pPathName, pPrintProcessorName)
#define WinAPI_AddPrintProvidor(pName, level, pProvidorInfo)	AddPrintProvidorA(pName, level, pProvidorInfo)
__EXTERN INTEGER __STDCALL AddPrintProvidorA(LONGINT pName, INTEGER level, CHAR *pProvidorInfo);
#define WinAPI_AddPrintProvidorA(pName, level, pProvidorInfo)	AddPrintProvidorA(pName, level, pProvidorInfo)
__EXTERN INTEGER __STDCALL AddPrintProvidorW(LONGINT pName, INTEGER level, CHAR *pProvidorInfo);
#define WinAPI_AddPrintProvidorW(pName, level, pProvidorInfo)	AddPrintProvidorW(pName, level, pProvidorInfo)
#define WinAPI_AddPrinter(pName, Level, pPrinter)	AddPrinterA(pName, Level, pPrinter)
__EXTERN LONGINT __STDCALL AddPrinterA(LONGINT pName, INTEGER Level, CHAR *pPrinter);
#define WinAPI_AddPrinterA(pName, Level, pPrinter)	AddPrinterA(pName, Level, pPrinter)
#define WinAPI_AddPrinterConnection(pName)	AddPrinterConnectionA(pName)
__EXTERN INTEGER __STDCALL AddPrinterConnectionA(LONGINT pName);
#define WinAPI_AddPrinterConnectionA(pName)	AddPrinterConnectionA(pName)
__EXTERN INTEGER __STDCALL AddPrinterConnectionW(LONGINT pName);
#define WinAPI_AddPrinterConnectionW(pName)	AddPrinterConnectionW(pName)
#define WinAPI_AddPrinterDriver(pName, Level, pDriverInfo)	AddPrinterDriverA(pName, Level, pDriverInfo)
__EXTERN INTEGER __STDCALL AddPrinterDriverA(LONGINT pName, INTEGER Level, CHAR *pDriverInfo);
#define WinAPI_AddPrinterDriverA(pName, Level, pDriverInfo)	AddPrinterDriverA(pName, Level, pDriverInfo)
__EXTERN INTEGER __STDCALL AddPrinterDriverW(LONGINT pName, INTEGER Level, CHAR *pDriverInfo);
#define WinAPI_AddPrinterDriverW(pName, Level, pDriverInfo)	AddPrinterDriverW(pName, Level, pDriverInfo)
__EXTERN LONGINT __STDCALL AddPrinterW(LONGINT pName, INTEGER Level, CHAR *pPrinter);
#define WinAPI_AddPrinterW(pName, Level, pPrinter)	AddPrinterW(pName, Level, pPrinter)
__EXTERN INTEGER __STDCALL AdjustTokenGroups(LONGINT TokenHandle, INTEGER ResetToDefault, WinAPI_TOKEN_GROUPS *NewState, INTEGER BufferLength, WinAPI_TOKEN_GROUPS *PreviousState, INTEGER *ReturnLength);
#define WinAPI_AdjustTokenGroups(TokenHandle, ResetToDefault, NewState, BufferLength, PreviousState, ReturnLength)	AdjustTokenGroups(TokenHandle, ResetToDefault, NewState, BufferLength, PreviousState, ReturnLength)
__EXTERN INTEGER __STDCALL AdjustTokenPrivileges(LONGINT TokenHandle, INTEGER DisableAllPrivileges, WinAPI_TOKEN_PRIVILEGES *NewState, INTEGER BufferLength, WinAPI_TOKEN_PRIVILEGES *PreviousState, INTEGER *ReturnLength);
#define WinAPI_AdjustTokenPrivileges(TokenHandle, DisableAllPrivileges, NewState, BufferLength, PreviousState, ReturnLength)	AdjustTokenPrivileges(TokenHandle, DisableAllPrivileges, NewState, BufferLength, PreviousState, ReturnLength)
__EXTERN INTEGER __STDCALL AdjustWindowRect(WinAPI_RECT *lpRect, SET dwStyle, INTEGER bMenu);
#define WinAPI_AdjustWindowRect(lpRect, dwStyle, bMenu)	AdjustWindowRect(lpRect, dwStyle, bMenu)
__EXTERN INTEGER __STDCALL AdjustWindowRectEx(WinAPI_RECT *lpRect, SET dwStyle, INTEGER bMenu, SET dwExStyle);
#define WinAPI_AdjustWindowRectEx(lpRect, dwStyle, bMenu, dwExStyle)	AdjustWindowRectEx(lpRect, dwStyle, bMenu, dwExStyle)
#define WinAPI_AdvancedDocumentProperties(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)	AdvancedDocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)
__EXTERN INTEGER __STDCALL AdvancedDocumentPropertiesA(LONGINT hWnd, LONGINT hPrinter, LONGINT pDeviceName, WinAPI_DEVMODEA *pDevModeOutput, WinAPI_DEVMODEA *pDevModeInput);
#define WinAPI_AdvancedDocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)	AdvancedDocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)
__EXTERN INTEGER __STDCALL AdvancedDocumentPropertiesW(LONGINT hWnd, LONGINT hPrinter, LONGINT pDeviceName, WinAPI_DEVMODEW *pDevModeOutput, WinAPI_DEVMODEW *pDevModeInput);
#define WinAPI_AdvancedDocumentPropertiesW(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)	AdvancedDocumentPropertiesW(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)
__EXTERN INTEGER __STDCALL AllocConsole(void);
#define WinAPI_AllocConsole()	AllocConsole()
__EXTERN INTEGER __STDCALL AllocateAndInitializeSid(WinAPI_SID_IDENTIFIER_AUTHORITY *pIdentifierAuthority, CHAR nSubAuthorityCount, INTEGER nSubAuthority0, INTEGER nSubAuthority1, INTEGER nSubAuthority2, INTEGER nSubAuthority3, INTEGER nSubAuthority4, INTEGER nSubAuthority5, INTEGER nSubAuthority6, INTEGER nSubAuthority7, LONGINT *pSid);
#define WinAPI_AllocateAndInitializeSid(pIdentifierAuthority, nSubAuthorityCount, nSubAuthority0, nSubAuthority1, nSubAuthority2, nSubAuthority3, nSubAuthority4, nSubAuthority5, nSubAuthority6, nSubAuthority7, pSid)	AllocateAndInitializeSid(pIdentifierAuthority, nSubAuthorityCount, nSubAuthority0, nSubAuthority1, nSubAuthority2, nSubAuthority3, nSubAuthority4, nSubAuthority5, nSubAuthority6, nSubAuthority7, pSid)
__EXTERN INTEGER __STDCALL AllocateLocallyUniqueId(LONGINT *Luid);
#define WinAPI_AllocateLocallyUniqueId(Luid)	AllocateLocallyUniqueId(Luid)
__EXTERN INTEGER __STDCALL AngleArc(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, SHORTREAL p4, SHORTREAL p5);
#define WinAPI_AngleArc(p0, p1, p2, p3, p4, p5)	AngleArc(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __STDCALL AnimatePalette(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
#define WinAPI_AnimatePalette(p0, p1, p2, p3)	AnimatePalette(p0, p1, p2, p3)
#define WinAPI_AnsiLower(lpsz)	CharLowerA(lpsz)
#define WinAPI_AnsiLowerBuff(lpsz, cchLength)	CharLowerBuffA(lpsz, cchLength)
#define WinAPI_AnsiNext(lpsz)	CharNextA(lpsz)
#define WinAPI_AnsiPrev(lpszStart, lpszCurrent)	CharPrevA(lpszStart, lpszCurrent)
#define WinAPI_AnsiToOem(lpszSrc, lpszDst)	CharToOemA(lpszSrc, lpszDst)
#define WinAPI_AnsiToOemBuff(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinAPI_AnsiUpper(lpsz)	CharUpperA(lpsz)
#define WinAPI_AnsiUpperBuff(lpsz, cchLength)	CharUpperBuffA(lpsz, cchLength)
__EXTERN INTEGER __STDCALL AnyPopup(void);
#define WinAPI_AnyPopup()	AnyPopup()
#define WinAPI_AppendMenu(hMenu, uFlags, uIDNewItem, lpNewItem)	AppendMenuA(hMenu, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __STDCALL AppendMenuA(LONGINT hMenu, SET uFlags, INTEGER uIDNewItem, LONGINT lpNewItem);
#define WinAPI_AppendMenuA(hMenu, uFlags, uIDNewItem, lpNewItem)	AppendMenuA(hMenu, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __STDCALL AppendMenuW(LONGINT hMenu, SET uFlags, INTEGER uIDNewItem, LONGINT lpNewItem);
#define WinAPI_AppendMenuW(hMenu, uFlags, uIDNewItem, lpNewItem)	AppendMenuW(hMenu, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __STDCALL Arc(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinAPI_Arc(p0, p1, p2, p3, p4, p5, p6, p7, p8)	Arc(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __STDCALL ArcTo(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinAPI_ArcTo(p0, p1, p2, p3, p4, p5, p6, p7, p8)	ArcTo(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __STDCALL AreAllAccessesGranted(INTEGER GrantedAccess, SET DesiredAccess);
#define WinAPI_AreAllAccessesGranted(GrantedAccess, DesiredAccess)	AreAllAccessesGranted(GrantedAccess, DesiredAccess)
__EXTERN INTEGER __STDCALL AreAnyAccessesGranted(INTEGER GrantedAccess, SET DesiredAccess);
#define WinAPI_AreAnyAccessesGranted(GrantedAccess, DesiredAccess)	AreAnyAccessesGranted(GrantedAccess, DesiredAccess)
__EXTERN INTEGER __STDCALL AreFileApisANSI(void);
#define WinAPI_AreFileApisANSI()	AreFileApisANSI()
__EXTERN INTEGER __STDCALL ArrangeIconicWindows(LONGINT hWnd);
#define WinAPI_ArrangeIconicWindows(hWnd)	ArrangeIconicWindows(hWnd)
__EXTERN INTEGER __STDCALL AttachThreadInput(INTEGER idAttach, INTEGER idAttachTo, INTEGER fAttach);
#define WinAPI_AttachThreadInput(idAttach, idAttachTo, fAttach)	AttachThreadInput(idAttach, idAttachTo, fAttach)
#define WinAPI_BackupEventLog(hEventLog, lpBackupFileName)	BackupEventLogA(hEventLog, lpBackupFileName)
__EXTERN INTEGER __STDCALL BackupEventLogA(LONGINT hEventLog, LONGINT lpBackupFileName);
#define WinAPI_BackupEventLogA(hEventLog, lpBackupFileName)	BackupEventLogA(hEventLog, lpBackupFileName)
__EXTERN INTEGER __STDCALL BackupEventLogW(LONGINT hEventLog, LONGINT lpBackupFileName);
#define WinAPI_BackupEventLogW(hEventLog, lpBackupFileName)	BackupEventLogW(hEventLog, lpBackupFileName)
__EXTERN INTEGER __STDCALL BackupRead(LONGINT hFile, CHAR *lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *lpNumberOfBytesRead, INTEGER bAbort, INTEGER bProcessSecurity, LONGINT lpContext);
#define WinAPI_BackupRead(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, bAbort, bProcessSecurity, lpContext)	BackupRead(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, bAbort, bProcessSecurity, lpContext)
__EXTERN INTEGER __STDCALL BackupSeek(LONGINT hFile, INTEGER dwLowBytesToSeek, INTEGER dwHighBytesToSeek, INTEGER *lpdwLowByteSeeked, INTEGER *lpdwHighByteSeeked, LONGINT lpContext);
#define WinAPI_BackupSeek(hFile, dwLowBytesToSeek, dwHighBytesToSeek, lpdwLowByteSeeked, lpdwHighByteSeeked, lpContext)	BackupSeek(hFile, dwLowBytesToSeek, dwHighBytesToSeek, lpdwLowByteSeeked, lpdwHighByteSeeked, lpContext)
__EXTERN INTEGER __STDCALL BackupWrite(LONGINT hFile, CHAR *lpBuffer, INTEGER nNumberOfBytesToWrite, INTEGER *lpNumberOfBytesWritten, INTEGER bAbort, INTEGER bProcessSecurity, LONGINT lpContext);
#define WinAPI_BackupWrite(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, bAbort, bProcessSecurity, lpContext)	BackupWrite(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, bAbort, bProcessSecurity, lpContext)
__EXTERN INTEGER __STDCALL Beep(INTEGER dwFreq, INTEGER dwDuration);
#define WinAPI_Beep(dwFreq, dwDuration)	Beep(dwFreq, dwDuration)
__EXTERN LONGINT __STDCALL BeginDeferWindowPos(INTEGER nNumWindows);
#define WinAPI_BeginDeferWindowPos(nNumWindows)	BeginDeferWindowPos(nNumWindows)
__EXTERN LONGINT __STDCALL BeginPaint(LONGINT hWnd, WinAPI_PAINTSTRUCT *lpPaint);
#define WinAPI_BeginPaint(hWnd, lpPaint)	BeginPaint(hWnd, lpPaint)
__EXTERN INTEGER __STDCALL BeginPath(LONGINT p0);
#define WinAPI_BeginPath(p0)	BeginPath(p0)
#define WinAPI_BeginUpdateResource(pFileName, bDeleteExistingResources)	BeginUpdateResourceA(pFileName, bDeleteExistingResources)
__EXTERN LONGINT __STDCALL BeginUpdateResourceA(LONGINT pFileName, INTEGER bDeleteExistingResources);
#define WinAPI_BeginUpdateResourceA(pFileName, bDeleteExistingResources)	BeginUpdateResourceA(pFileName, bDeleteExistingResources)
__EXTERN LONGINT __STDCALL BeginUpdateResourceW(LONGINT pFileName, INTEGER bDeleteExistingResources);
#define WinAPI_BeginUpdateResourceW(pFileName, bDeleteExistingResources)	BeginUpdateResourceW(pFileName, bDeleteExistingResources)
__EXTERN INTEGER __STDCALL BitBlt(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, LONGINT p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinAPI_BitBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8)	BitBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __STDCALL BringWindowToTop(LONGINT hWnd);
#define WinAPI_BringWindowToTop(hWnd)	BringWindowToTop(hWnd)
#define WinAPI_BroadcastSystemMessage(p0, p1, p2, p3, p4)	BroadcastSystemMessageA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL BroadcastSystemMessageA(SET p0, SET *p1, INTEGER p2, LONGINT p3, LONGINT p4);
#define WinAPI_BroadcastSystemMessageA(p0, p1, p2, p3, p4)	BroadcastSystemMessageA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL BroadcastSystemMessageW(SET p0, SET *p1, INTEGER p2, LONGINT p3, LONGINT p4);
#define WinAPI_BroadcastSystemMessageW(p0, p1, p2, p3, p4)	BroadcastSystemMessageW(p0, p1, p2, p3, p4)
#define WinAPI_BuildCommDCB(lpDef, lpDCB)	BuildCommDCBA(lpDef, lpDCB)
__EXTERN INTEGER __STDCALL BuildCommDCBA(LONGINT lpDef, WinAPI_DCB *lpDCB);
#define WinAPI_BuildCommDCBA(lpDef, lpDCB)	BuildCommDCBA(lpDef, lpDCB)
#define WinAPI_BuildCommDCBAndTimeouts(lpDef, lpDCB, lpCommTimeouts)	BuildCommDCBAndTimeoutsA(lpDef, lpDCB, lpCommTimeouts)
__EXTERN INTEGER __STDCALL BuildCommDCBAndTimeoutsA(LONGINT lpDef, WinAPI_DCB *lpDCB, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
#define WinAPI_BuildCommDCBAndTimeoutsA(lpDef, lpDCB, lpCommTimeouts)	BuildCommDCBAndTimeoutsA(lpDef, lpDCB, lpCommTimeouts)
__EXTERN INTEGER __STDCALL BuildCommDCBAndTimeoutsW(LONGINT lpDef, WinAPI_DCB *lpDCB, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
#define WinAPI_BuildCommDCBAndTimeoutsW(lpDef, lpDCB, lpCommTimeouts)	BuildCommDCBAndTimeoutsW(lpDef, lpDCB, lpCommTimeouts)
__EXTERN INTEGER __STDCALL BuildCommDCBW(LONGINT lpDef, WinAPI_DCB *lpDCB);
#define WinAPI_BuildCommDCBW(lpDef, lpDCB)	BuildCommDCBW(lpDef, lpDCB)
#define WinAPI_CallMsgFilter(lpMsg, nCode)	CallMsgFilterA(lpMsg, nCode)
__EXTERN INTEGER __STDCALL CallMsgFilterA(WinAPI_MSG *lpMsg, INTEGER nCode);
#define WinAPI_CallMsgFilterA(lpMsg, nCode)	CallMsgFilterA(lpMsg, nCode)
__EXTERN INTEGER __STDCALL CallMsgFilterW(WinAPI_MSG *lpMsg, INTEGER nCode);
#define WinAPI_CallMsgFilterW(lpMsg, nCode)	CallMsgFilterW(lpMsg, nCode)
#define WinAPI_CallNamedPipe(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)	CallNamedPipeA(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)
__EXTERN INTEGER __STDCALL CallNamedPipeA(LONGINT lpNamedPipeName, LONGINT lpInBuffer, INTEGER nInBufferSize, LONGINT lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, INTEGER nTimeOut);
#define WinAPI_CallNamedPipeA(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)	CallNamedPipeA(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)
__EXTERN INTEGER __STDCALL CallNamedPipeW(LONGINT lpNamedPipeName, LONGINT lpInBuffer, INTEGER nInBufferSize, LONGINT lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, INTEGER nTimeOut);
#define WinAPI_CallNamedPipeW(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)	CallNamedPipeW(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)
__EXTERN LONGINT __STDCALL CallNextHookEx(LONGINT hhk, INTEGER nCode, LONGINT wParam, LONGINT lParam);
#define WinAPI_CallNextHookEx(hhk, nCode, wParam, lParam)	CallNextHookEx(hhk, nCode, wParam, lParam)
#define WinAPI_CallWindowProc(lpPrevWndFunc, hWnd, Msg, wParam, lParam)	CallWindowProcA(lpPrevWndFunc, hWnd, Msg, wParam, lParam)
__EXTERN LONGINT __STDCALL CallWindowProcA(WinAPI_FARPROC lpPrevWndFunc, LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_CallWindowProcA(lpPrevWndFunc, hWnd, Msg, wParam, lParam)	CallWindowProcA(lpPrevWndFunc, hWnd, Msg, wParam, lParam)
__EXTERN LONGINT __STDCALL CallWindowProcW(WinAPI_FARPROC lpPrevWndFunc, LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_CallWindowProcW(lpPrevWndFunc, hWnd, Msg, wParam, lParam)	CallWindowProcW(lpPrevWndFunc, hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __STDCALL CancelDC(LONGINT p0);
#define WinAPI_CancelDC(p0)	CancelDC(p0)
__EXTERN INTEGER __STDCALL CancelWaitableTimer(LONGINT hTimer);
#define WinAPI_CancelWaitableTimer(hTimer)	CancelWaitableTimer(hTimer)
__EXTERN SHORTINT __STDCALL CascadeWindows(LONGINT hwndParent, INTEGER wHow, WinAPI_RECT *lpRect, INTEGER cKids, LONGINT *lpKids);
#define WinAPI_CascadeWindows(hwndParent, wHow, lpRect, cKids, lpKids)	CascadeWindows(hwndParent, wHow, lpRect, cKids, lpKids)
__EXTERN INTEGER __STDCALL ChangeClipboardChain(LONGINT hWndRemove, LONGINT hWndNewNext);
#define WinAPI_ChangeClipboardChain(hWndRemove, hWndNewNext)	ChangeClipboardChain(hWndRemove, hWndNewNext)
#define WinAPI_ChangeDisplaySettings(lpDevMode, dwFlags)	ChangeDisplaySettingsA(lpDevMode, dwFlags)
__EXTERN INTEGER __STDCALL ChangeDisplaySettingsA(WinAPI_DEVMODEA *lpDevMode, SET dwFlags);
#define WinAPI_ChangeDisplaySettingsA(lpDevMode, dwFlags)	ChangeDisplaySettingsA(lpDevMode, dwFlags)
__EXTERN INTEGER __STDCALL ChangeDisplaySettingsW(WinAPI_DEVMODEW *lpDevMode, SET dwFlags);
#define WinAPI_ChangeDisplaySettingsW(lpDevMode, dwFlags)	ChangeDisplaySettingsW(lpDevMode, dwFlags)
#define WinAPI_ChangeMenu(hMenu, cmd, lpszNewItem, cmdInsert, flags)	ChangeMenuA(hMenu, cmd, lpszNewItem, cmdInsert, flags)
__EXTERN INTEGER __STDCALL ChangeMenuA(LONGINT hMenu, INTEGER cmd, LONGINT lpszNewItem, INTEGER cmdInsert, SET flags);
#define WinAPI_ChangeMenuA(hMenu, cmd, lpszNewItem, cmdInsert, flags)	ChangeMenuA(hMenu, cmd, lpszNewItem, cmdInsert, flags)
__EXTERN INTEGER __STDCALL ChangeMenuW(LONGINT hMenu, INTEGER cmd, LONGINT lpszNewItem, INTEGER cmdInsert, SET flags);
#define WinAPI_ChangeMenuW(hMenu, cmd, lpszNewItem, cmdInsert, flags)	ChangeMenuW(hMenu, cmd, lpszNewItem, cmdInsert, flags)
#define WinAPI_ChangeServiceConfig(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)	ChangeServiceConfigA(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)
__EXTERN INTEGER __STDCALL ChangeServiceConfigA(LONGINT hService, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, LONGINT lpBinaryPathName, LONGINT lpLoadOrderGroup, INTEGER *lpdwTagId, LONGINT lpDependencies, LONGINT lpServiceStartName, LONGINT lpPassword, LONGINT lpDisplayName);
#define WinAPI_ChangeServiceConfigA(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)	ChangeServiceConfigA(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)
__EXTERN INTEGER __STDCALL ChangeServiceConfigW(LONGINT hService, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, LONGINT lpBinaryPathName, LONGINT lpLoadOrderGroup, INTEGER *lpdwTagId, LONGINT lpDependencies, LONGINT lpServiceStartName, LONGINT lpPassword, LONGINT lpDisplayName);
#define WinAPI_ChangeServiceConfigW(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)	ChangeServiceConfigW(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)
#define WinAPI_CharLower(lpsz)	CharLowerA(lpsz)
__EXTERN LONGINT __STDCALL CharLowerA(LONGINT lpsz);
#define WinAPI_CharLowerA(lpsz)	CharLowerA(lpsz)
#define WinAPI_CharLowerBuff(lpsz, cchLength)	CharLowerBuffA(lpsz, cchLength)
__EXTERN INTEGER __STDCALL CharLowerBuffA(LONGINT lpsz, INTEGER cchLength);
#define WinAPI_CharLowerBuffA(lpsz, cchLength)	CharLowerBuffA(lpsz, cchLength)
__EXTERN INTEGER __STDCALL CharLowerBuffW(LONGINT lpsz, INTEGER cchLength);
#define WinAPI_CharLowerBuffW(lpsz, cchLength)	CharLowerBuffW(lpsz, cchLength)
__EXTERN LONGINT __STDCALL CharLowerW(LONGINT lpsz);
#define WinAPI_CharLowerW(lpsz)	CharLowerW(lpsz)
#define WinAPI_CharNext(lpsz)	CharNextA(lpsz)
__EXTERN LONGINT __STDCALL CharNextA(LONGINT lpsz);
#define WinAPI_CharNextA(lpsz)	CharNextA(lpsz)
__EXTERN LONGINT __STDCALL CharNextExA(SHORTINT CodePage, LONGINT lpCurrentChar, SET dwFlags);
#define WinAPI_CharNextExA(CodePage, lpCurrentChar, dwFlags)	CharNextExA(CodePage, lpCurrentChar, dwFlags)
__EXTERN LONGINT __STDCALL CharNextW(LONGINT lpsz);
#define WinAPI_CharNextW(lpsz)	CharNextW(lpsz)
#define WinAPI_CharPrev(lpszStart, lpszCurrent)	CharPrevA(lpszStart, lpszCurrent)
__EXTERN LONGINT __STDCALL CharPrevA(LONGINT lpszStart, LONGINT lpszCurrent);
#define WinAPI_CharPrevA(lpszStart, lpszCurrent)	CharPrevA(lpszStart, lpszCurrent)
__EXTERN LONGINT __STDCALL CharPrevExA(SHORTINT CodePage, LONGINT lpStart, LONGINT lpCurrentChar, SET dwFlags);
#define WinAPI_CharPrevExA(CodePage, lpStart, lpCurrentChar, dwFlags)	CharPrevExA(CodePage, lpStart, lpCurrentChar, dwFlags)
__EXTERN LONGINT __STDCALL CharPrevW(LONGINT lpszStart, LONGINT lpszCurrent);
#define WinAPI_CharPrevW(lpszStart, lpszCurrent)	CharPrevW(lpszStart, lpszCurrent)
#define WinAPI_CharToOem(lpszSrc, lpszDst)	CharToOemA(lpszSrc, lpszDst)
__EXTERN INTEGER __STDCALL CharToOemA(LONGINT lpszSrc, LONGINT lpszDst);
#define WinAPI_CharToOemA(lpszSrc, lpszDst)	CharToOemA(lpszSrc, lpszDst)
#define WinAPI_CharToOemBuff(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __STDCALL CharToOemBuffA(LONGINT lpszSrc, LONGINT lpszDst, INTEGER cchDstLength);
#define WinAPI_CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __STDCALL CharToOemBuffW(LONGINT lpszSrc, LONGINT lpszDst, INTEGER cchDstLength);
#define WinAPI_CharToOemBuffW(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffW(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __STDCALL CharToOemW(LONGINT lpszSrc, LONGINT lpszDst);
#define WinAPI_CharToOemW(lpszSrc, lpszDst)	CharToOemW(lpszSrc, lpszDst)
#define WinAPI_CharUpper(lpsz)	CharUpperA(lpsz)
__EXTERN LONGINT __STDCALL CharUpperA(LONGINT lpsz);
#define WinAPI_CharUpperA(lpsz)	CharUpperA(lpsz)
#define WinAPI_CharUpperBuff(lpsz, cchLength)	CharUpperBuffA(lpsz, cchLength)
__EXTERN INTEGER __STDCALL CharUpperBuffA(LONGINT lpsz, INTEGER cchLength);
#define WinAPI_CharUpperBuffA(lpsz, cchLength)	CharUpperBuffA(lpsz, cchLength)
__EXTERN INTEGER __STDCALL CharUpperBuffW(LONGINT lpsz, INTEGER cchLength);
#define WinAPI_CharUpperBuffW(lpsz, cchLength)	CharUpperBuffW(lpsz, cchLength)
__EXTERN LONGINT __STDCALL CharUpperW(LONGINT lpsz);
#define WinAPI_CharUpperW(lpsz)	CharUpperW(lpsz)
__EXTERN INTEGER __STDCALL CheckColorsInGamut(LONGINT p0, LONGINT p1, LONGINT p2, INTEGER p3);
#define WinAPI_CheckColorsInGamut(p0, p1, p2, p3)	CheckColorsInGamut(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL CheckDlgButton(LONGINT hDlg, INTEGER nIDButton, SET uCheck);
#define WinAPI_CheckDlgButton(hDlg, nIDButton, uCheck)	CheckDlgButton(hDlg, nIDButton, uCheck)
__EXTERN INTEGER __STDCALL CheckMenuItem(LONGINT hMenu, INTEGER uIDCheckItem, SET uCheck);
#define WinAPI_CheckMenuItem(hMenu, uIDCheckItem, uCheck)	CheckMenuItem(hMenu, uIDCheckItem, uCheck)
__EXTERN INTEGER __STDCALL CheckMenuRadioItem(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_CheckMenuRadioItem(p0, p1, p2, p3, p4)	CheckMenuRadioItem(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL CheckRadioButton(LONGINT hDlg, INTEGER nIDFirstButton, INTEGER nIDLastButton, INTEGER nIDCheckButton);
#define WinAPI_CheckRadioButton(hDlg, nIDFirstButton, nIDLastButton, nIDCheckButton)	CheckRadioButton(hDlg, nIDFirstButton, nIDLastButton, nIDCheckButton)
__EXTERN LONGINT __STDCALL ChildWindowFromPoint(LONGINT hWndParent, WinAPI_POINT *Point);
#define WinAPI_ChildWindowFromPoint(hWndParent, Point)	ChildWindowFromPoint(hWndParent, Point)
__EXTERN LONGINT __STDCALL ChildWindowFromPointEx(LONGINT p0, WinAPI_POINT *p1, SET p2);
#define WinAPI_ChildWindowFromPointEx(p0, p1, p2)	ChildWindowFromPointEx(p0, p1, p2)
__EXTERN INTEGER __STDCALL ChoosePixelFormat(LONGINT p0, WinAPI_PIXELFORMATDESCRIPTOR *p1);
#define WinAPI_ChoosePixelFormat(p0, p1)	ChoosePixelFormat(p0, p1)
__EXTERN INTEGER __STDCALL Chord(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinAPI_Chord(p0, p1, p2, p3, p4, p5, p6, p7, p8)	Chord(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __STDCALL ClearCommBreak(LONGINT hFile);
#define WinAPI_ClearCommBreak(hFile)	ClearCommBreak(hFile)
__EXTERN INTEGER __STDCALL ClearCommError(LONGINT hFile, SET *lpErrors, WinAPI_COMSTAT *lpStat);
#define WinAPI_ClearCommError(hFile, lpErrors, lpStat)	ClearCommError(hFile, lpErrors, lpStat)
#define WinAPI_ClearEventLog(hEventLog, lpBackupFileName)	ClearEventLogA(hEventLog, lpBackupFileName)
__EXTERN INTEGER __STDCALL ClearEventLogA(LONGINT hEventLog, LONGINT lpBackupFileName);
#define WinAPI_ClearEventLogA(hEventLog, lpBackupFileName)	ClearEventLogA(hEventLog, lpBackupFileName)
__EXTERN INTEGER __STDCALL ClearEventLogW(LONGINT hEventLog, LONGINT lpBackupFileName);
#define WinAPI_ClearEventLogW(hEventLog, lpBackupFileName)	ClearEventLogW(hEventLog, lpBackupFileName)
__EXTERN INTEGER __STDCALL ClientToScreen(LONGINT hWnd, WinAPI_POINT *lpPoint);
#define WinAPI_ClientToScreen(hWnd, lpPoint)	ClientToScreen(hWnd, lpPoint)
__EXTERN INTEGER __STDCALL ClipCursor(WinAPI_RECT *lpRect);
#define WinAPI_ClipCursor(lpRect)	ClipCursor(lpRect)
__EXTERN INTEGER __STDCALL CloseClipboard(void);
#define WinAPI_CloseClipboard()	CloseClipboard()
__EXTERN INTEGER __STDCALL CloseDesktop(LONGINT hDesktop);
#define WinAPI_CloseDesktop(hDesktop)	CloseDesktop(hDesktop)
__EXTERN LONGINT __STDCALL CloseEnhMetaFile(LONGINT p0);
#define WinAPI_CloseEnhMetaFile(p0)	CloseEnhMetaFile(p0)
__EXTERN INTEGER __STDCALL CloseEventLog(LONGINT hEventLog);
#define WinAPI_CloseEventLog(hEventLog)	CloseEventLog(hEventLog)
__EXTERN INTEGER __STDCALL CloseFigure(LONGINT p0);
#define WinAPI_CloseFigure(p0)	CloseFigure(p0)
__EXTERN INTEGER __STDCALL CloseHandle(LONGINT hObject);
#define WinAPI_CloseHandle(hObject)	CloseHandle(hObject)
__EXTERN LONGINT __STDCALL CloseMetaFile(LONGINT p0);
#define WinAPI_CloseMetaFile(p0)	CloseMetaFile(p0)
__EXTERN INTEGER __STDCALL ClosePrinter(LONGINT hPrinter);
#define WinAPI_ClosePrinter(hPrinter)	ClosePrinter(hPrinter)
__EXTERN INTEGER __STDCALL CloseServiceHandle(LONGINT hSCObject);
#define WinAPI_CloseServiceHandle(hSCObject)	CloseServiceHandle(hSCObject)
__EXTERN INTEGER __STDCALL CloseWindow(LONGINT hWnd);
#define WinAPI_CloseWindow(hWnd)	CloseWindow(hWnd)
__EXTERN INTEGER __STDCALL CloseWindowStation(LONGINT hWinSta);
#define WinAPI_CloseWindowStation(hWinSta)	CloseWindowStation(hWinSta)
#define WinAPI_CmdLine()	__lpCmdLine
#define WinAPI_CmdShow()	__nCmdShow
__EXTERN INTEGER __STDCALL ColorMatchToTarget(LONGINT p0, LONGINT p1, INTEGER p2);
#define WinAPI_ColorMatchToTarget(p0, p1, p2)	ColorMatchToTarget(p0, p1, p2)
__EXTERN INTEGER __STDCALL CombineRgn(LONGINT p0, LONGINT p1, LONGINT p2, INTEGER p3);
#define WinAPI_CombineRgn(p0, p1, p2, p3)	CombineRgn(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL CombineTransform(WinAPI_XFORM *p0, WinAPI_XFORM *p1, WinAPI_XFORM *p2);
#define WinAPI_CombineTransform(p0, p1, p2)	CombineTransform(p0, p1, p2)
#define WinAPI_CommConfigDialog(lpszName, hWnd, lpCC)	CommConfigDialogA(lpszName, hWnd, lpCC)
__EXTERN INTEGER __STDCALL CommConfigDialogA(LONGINT lpszName, LONGINT hWnd, WinAPI_COMMCONFIG *lpCC);
#define WinAPI_CommConfigDialogA(lpszName, hWnd, lpCC)	CommConfigDialogA(lpszName, hWnd, lpCC)
__EXTERN INTEGER __STDCALL CommConfigDialogW(LONGINT lpszName, LONGINT hWnd, WinAPI_COMMCONFIG *lpCC);
#define WinAPI_CommConfigDialogW(lpszName, hWnd, lpCC)	CommConfigDialogW(lpszName, hWnd, lpCC)
__EXTERN LONGINT __STDCALL CommandLineToArgvW(LONGINT lpCmdLine, INTEGER *pNumArgs);
#define WinAPI_CommandLineToArgvW(lpCmdLine, pNumArgs)	CommandLineToArgvW(lpCmdLine, pNumArgs)
__EXTERN INTEGER __STDCALL CompareFileTime(WinAPI_FILETIME *lpFileTime1, WinAPI_FILETIME *lpFileTime2);
#define WinAPI_CompareFileTime(lpFileTime1, lpFileTime2)	CompareFileTime(lpFileTime1, lpFileTime2)
#define WinAPI_CompareString(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)	CompareStringA(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)
__EXTERN INTEGER __STDCALL CompareStringA(INTEGER Locale, SET dwCmpFlags, LONGINT lpString1, INTEGER cchCount1, LONGINT lpString2, INTEGER cchCount2);
#define WinAPI_CompareStringA(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)	CompareStringA(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)
__EXTERN INTEGER __STDCALL CompareStringW(INTEGER Locale, SET dwCmpFlags, LONGINT lpString1, INTEGER cchCount1, LONGINT lpString2, INTEGER cchCount2);
#define WinAPI_CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)	CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)
#define WinAPI_ConfigurePort(pName, hWnd, pPortName)	ConfigurePortA(pName, hWnd, pPortName)
__EXTERN INTEGER __STDCALL ConfigurePortA(LONGINT pName, LONGINT hWnd, LONGINT pPortName);
#define WinAPI_ConfigurePortA(pName, hWnd, pPortName)	ConfigurePortA(pName, hWnd, pPortName)
__EXTERN INTEGER __STDCALL ConfigurePortW(LONGINT pName, LONGINT hWnd, LONGINT pPortName);
#define WinAPI_ConfigurePortW(pName, hWnd, pPortName)	ConfigurePortW(pName, hWnd, pPortName)
__EXTERN INTEGER __STDCALL ConnectNamedPipe(LONGINT hNamedPipe, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_ConnectNamedPipe(hNamedPipe, lpOverlapped)	ConnectNamedPipe(hNamedPipe, lpOverlapped)
__EXTERN LONGINT __STDCALL ConnectToPrinterDlg(LONGINT hwnd, SET Flags);
#define WinAPI_ConnectToPrinterDlg(hwnd, Flags)	ConnectToPrinterDlg(hwnd, Flags)
__EXTERN INTEGER __STDCALL ContinueDebugEvent(INTEGER dwProcessId, INTEGER dwThreadId, SET dwContinueStatus);
#define WinAPI_ContinueDebugEvent(dwProcessId, dwThreadId, dwContinueStatus)	ContinueDebugEvent(dwProcessId, dwThreadId, dwContinueStatus)
__EXTERN INTEGER __STDCALL ControlService(LONGINT hService, INTEGER dwControl, WinAPI_SERVICE_STATUS *lpServiceStatus);
#define WinAPI_ControlService(hService, dwControl, lpServiceStatus)	ControlService(hService, dwControl, lpServiceStatus)
__EXTERN INTEGER __STDCALL ConvertDefaultLocale(INTEGER Locale);
#define WinAPI_ConvertDefaultLocale(Locale)	ConvertDefaultLocale(Locale)
__EXTERN LONGINT __STDCALL ConvertThreadToFiber(LONGINT lpParameter);
#define WinAPI_ConvertThreadToFiber(lpParameter)	ConvertThreadToFiber(lpParameter)
#define WinAPI_CopyAcceleratorTable(hAccelSrc, lpAccelDst, cAccelEntries)	CopyAcceleratorTableA(hAccelSrc, lpAccelDst, cAccelEntries)
__EXTERN INTEGER __STDCALL CopyAcceleratorTableA(LONGINT hAccelSrc, WinAPI_ACCEL *lpAccelDst, INTEGER cAccelEntries);
#define WinAPI_CopyAcceleratorTableA(hAccelSrc, lpAccelDst, cAccelEntries)	CopyAcceleratorTableA(hAccelSrc, lpAccelDst, cAccelEntries)
__EXTERN INTEGER __STDCALL CopyAcceleratorTableW(LONGINT hAccelSrc, WinAPI_ACCEL *lpAccelDst, INTEGER cAccelEntries);
#define WinAPI_CopyAcceleratorTableW(hAccelSrc, lpAccelDst, cAccelEntries)	CopyAcceleratorTableW(hAccelSrc, lpAccelDst, cAccelEntries)
#define WinAPI_CopyEnhMetaFile(p0, p1)	CopyEnhMetaFileA(p0, p1)
__EXTERN LONGINT __STDCALL CopyEnhMetaFileA(LONGINT p0, LONGINT p1);
#define WinAPI_CopyEnhMetaFileA(p0, p1)	CopyEnhMetaFileA(p0, p1)
__EXTERN LONGINT __STDCALL CopyEnhMetaFileW(LONGINT p0, LONGINT p1);
#define WinAPI_CopyEnhMetaFileW(p0, p1)	CopyEnhMetaFileW(p0, p1)
#define WinAPI_CopyFile(lpExistingFileName, lpNewFileName, bFailIfExists)	CopyFileA(lpExistingFileName, lpNewFileName, bFailIfExists)
__EXTERN INTEGER __STDCALL CopyFileA(LONGINT lpExistingFileName, LONGINT lpNewFileName, INTEGER bFailIfExists);
#define WinAPI_CopyFileA(lpExistingFileName, lpNewFileName, bFailIfExists)	CopyFileA(lpExistingFileName, lpNewFileName, bFailIfExists)
#define WinAPI_CopyFileEx(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)	CopyFileExA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)
__EXTERN INTEGER __STDCALL CopyFileExA(LONGINT lpExistingFileName, LONGINT lpNewFileName, WinAPI_PROGRESS_ROUTINE lpProgressRoutine, LONGINT lpData, INTEGER *pbCancel, INTEGER dwCopyFlags);
#define WinAPI_CopyFileExA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)	CopyFileExA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)
__EXTERN INTEGER __STDCALL CopyFileExW(LONGINT lpExistingFileName, LONGINT lpNewFileName, WinAPI_PROGRESS_ROUTINE lpProgressRoutine, LONGINT lpData, INTEGER *pbCancel, INTEGER dwCopyFlags);
#define WinAPI_CopyFileExW(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)	CopyFileExW(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)
__EXTERN INTEGER __STDCALL CopyFileW(LONGINT lpExistingFileName, LONGINT lpNewFileName, INTEGER bFailIfExists);
#define WinAPI_CopyFileW(lpExistingFileName, lpNewFileName, bFailIfExists)	CopyFileW(lpExistingFileName, lpNewFileName, bFailIfExists)
__EXTERN LONGINT __STDCALL CopyIcon(LONGINT hIcon);
#define WinAPI_CopyIcon(hIcon)	CopyIcon(hIcon)
__EXTERN LONGINT __STDCALL CopyImage(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_CopyImage(p0, p1, p2, p3, p4)	CopyImage(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL CopyLZFile(INTEGER p0, INTEGER p1);
#define WinAPI_CopyLZFile(p0, p1)	CopyLZFile(p0, p1)
#define WinAPI_CopyMetaFile(p0, p1)	CopyMetaFileA(p0, p1)
__EXTERN LONGINT __STDCALL CopyMetaFileA(LONGINT p0, LONGINT p1);
#define WinAPI_CopyMetaFileA(p0, p1)	CopyMetaFileA(p0, p1)
__EXTERN LONGINT __STDCALL CopyMetaFileW(LONGINT p0, LONGINT p1);
#define WinAPI_CopyMetaFileW(p0, p1)	CopyMetaFileW(p0, p1)
__EXTERN INTEGER __STDCALL CopyRect(WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc);
#define WinAPI_CopyRect(lprcDst, lprcSrc)	CopyRect(lprcDst, lprcSrc)
__EXTERN INTEGER __STDCALL CopySid(INTEGER nDestinationSidLength, LONGINT pDestinationSid, LONGINT pSourceSid);
#define WinAPI_CopySid(nDestinationSidLength, pDestinationSid, pSourceSid)	CopySid(nDestinationSidLength, pDestinationSid, pSourceSid)
__EXTERN INTEGER __STDCALL CountClipboardFormats(void);
#define WinAPI_CountClipboardFormats()	CountClipboardFormats()
#define WinAPI_CreateAcceleratorTable(p0, p1)	CreateAcceleratorTableA(p0, p1)
__EXTERN LONGINT __STDCALL CreateAcceleratorTableA(WinAPI_ACCEL *p0, INTEGER p1);
#define WinAPI_CreateAcceleratorTableA(p0, p1)	CreateAcceleratorTableA(p0, p1)
__EXTERN LONGINT __STDCALL CreateAcceleratorTableW(WinAPI_ACCEL *p0, INTEGER p1);
#define WinAPI_CreateAcceleratorTableW(p0, p1)	CreateAcceleratorTableW(p0, p1)
__EXTERN LONGINT __STDCALL CreateBitmap(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, LONGINT p4);
#define WinAPI_CreateBitmap(p0, p1, p2, p3, p4)	CreateBitmap(p0, p1, p2, p3, p4)
__EXTERN LONGINT __STDCALL CreateBitmapIndirect(WinAPI_BITMAP *p0);
#define WinAPI_CreateBitmapIndirect(p0)	CreateBitmapIndirect(p0)
__EXTERN LONGINT __STDCALL CreateBrushIndirect(WinAPI_LOGBRUSH *p0);
#define WinAPI_CreateBrushIndirect(p0)	CreateBrushIndirect(p0)
__EXTERN INTEGER __STDCALL CreateCaret(LONGINT hWnd, LONGINT hBitmap, INTEGER nWidth, INTEGER nHeight);
#define WinAPI_CreateCaret(hWnd, hBitmap, nWidth, nHeight)	CreateCaret(hWnd, hBitmap, nWidth, nHeight)
#define WinAPI_CreateColorSpace(p0)	CreateColorSpaceA(p0)
__EXTERN LONGINT __STDCALL CreateColorSpaceA(WinAPI_LOGCOLORSPACEA *p0);
#define WinAPI_CreateColorSpaceA(p0)	CreateColorSpaceA(p0)
__EXTERN LONGINT __STDCALL CreateColorSpaceW(WinAPI_LOGCOLORSPACEW *p0);
#define WinAPI_CreateColorSpaceW(p0)	CreateColorSpaceW(p0)
__EXTERN LONGINT __STDCALL CreateCompatibleBitmap(LONGINT p0, INTEGER p1, INTEGER p2);
#define WinAPI_CreateCompatibleBitmap(p0, p1, p2)	CreateCompatibleBitmap(p0, p1, p2)
__EXTERN LONGINT __STDCALL CreateCompatibleDC(LONGINT p0);
#define WinAPI_CreateCompatibleDC(p0)	CreateCompatibleDC(p0)
__EXTERN LONGINT __STDCALL CreateConsoleScreenBuffer(SET dwDesiredAccess, SET dwShareMode, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, SET dwFlags, LONGINT lpScreenBufferData);
#define WinAPI_CreateConsoleScreenBuffer(dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwFlags, lpScreenBufferData)	CreateConsoleScreenBuffer(dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwFlags, lpScreenBufferData)
__EXTERN LONGINT __STDCALL CreateCursor(LONGINT hInst, INTEGER xHotSpot, INTEGER yHotSpot, INTEGER nWidth, INTEGER nHeight, LONGINT pvANDPlane, LONGINT pvXORPlane);
#define WinAPI_CreateCursor(hInst, xHotSpot, yHotSpot, nWidth, nHeight, pvANDPlane, pvXORPlane)	CreateCursor(hInst, xHotSpot, yHotSpot, nWidth, nHeight, pvANDPlane, pvXORPlane)
#define WinAPI_CreateDC(p0, p1, p2, p3)	CreateDCA(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL CreateDCA(LONGINT p0, LONGINT p1, LONGINT p2, WinAPI_DEVMODEA *p3);
#define WinAPI_CreateDCA(p0, p1, p2, p3)	CreateDCA(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL CreateDCW(LONGINT p0, LONGINT p1, LONGINT p2, WinAPI_DEVMODEW *p3);
#define WinAPI_CreateDCW(p0, p1, p2, p3)	CreateDCW(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL CreateDIBPatternBrush(LONGINT p0, INTEGER p1);
#define WinAPI_CreateDIBPatternBrush(p0, p1)	CreateDIBPatternBrush(p0, p1)
__EXTERN LONGINT __STDCALL CreateDIBPatternBrushPt(LONGINT p0, INTEGER p1);
#define WinAPI_CreateDIBPatternBrushPt(p0, p1)	CreateDIBPatternBrushPt(p0, p1)
__EXTERN LONGINT __STDCALL CreateDIBSection(LONGINT p0, WinAPI_BITMAPINFO *p1, INTEGER p2, LONGINT *p3, LONGINT p4, INTEGER p5);
#define WinAPI_CreateDIBSection(p0, p1, p2, p3, p4, p5)	CreateDIBSection(p0, p1, p2, p3, p4, p5)
__EXTERN LONGINT __STDCALL CreateDIBitmap(LONGINT p0, WinAPI_BITMAPINFOHEADER *p1, INTEGER p2, LONGINT p3, WinAPI_BITMAPINFO *p4, INTEGER p5);
#define WinAPI_CreateDIBitmap(p0, p1, p2, p3, p4, p5)	CreateDIBitmap(p0, p1, p2, p3, p4, p5)
#define WinAPI_CreateDesktop(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)	CreateDesktopA(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)
__EXTERN LONGINT __STDCALL CreateDesktopA(LONGINT lpszDesktop, LONGINT lpszDevice, WinAPI_DEVMODEA *pDevmode, SET dwFlags, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
#define WinAPI_CreateDesktopA(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)	CreateDesktopA(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)
__EXTERN LONGINT __STDCALL CreateDesktopW(LONGINT lpszDesktop, LONGINT lpszDevice, WinAPI_DEVMODEW *pDevmode, SET dwFlags, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
#define WinAPI_CreateDesktopW(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)	CreateDesktopW(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)
#define WinAPI_CreateDialogIndirectParam(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogIndirectParamA(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN LONGINT __STDCALL CreateDialogIndirectParamA(LONGINT hInstance, WinAPI_DLGTEMPLATE *lpTemplate, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
#define WinAPI_CreateDialogIndirectParamA(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogIndirectParamA(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN LONGINT __STDCALL CreateDialogIndirectParamW(LONGINT hInstance, WinAPI_DLGTEMPLATE *lpTemplate, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
#define WinAPI_CreateDialogIndirectParamW(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogIndirectParamW(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)
#define WinAPI_CreateDialogParam(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN LONGINT __STDCALL CreateDialogParamA(LONGINT hInstance, LONGINT lpTemplateName, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
#define WinAPI_CreateDialogParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN LONGINT __STDCALL CreateDialogParamW(LONGINT hInstance, LONGINT lpTemplateName, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
#define WinAPI_CreateDialogParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
#define WinAPI_CreateDirectory(lpPathName, lpSecurityAttributes)	CreateDirectoryA(lpPathName, lpSecurityAttributes)
__EXTERN INTEGER __STDCALL CreateDirectoryA(LONGINT lpPathName, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateDirectoryA(lpPathName, lpSecurityAttributes)	CreateDirectoryA(lpPathName, lpSecurityAttributes)
#define WinAPI_CreateDirectoryEx(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)	CreateDirectoryExA(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)
__EXTERN INTEGER __STDCALL CreateDirectoryExA(LONGINT lpTemplateDirectory, LONGINT lpNewDirectory, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateDirectoryExA(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)	CreateDirectoryExA(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)
__EXTERN INTEGER __STDCALL CreateDirectoryExW(LONGINT lpTemplateDirectory, LONGINT lpNewDirectory, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateDirectoryExW(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)	CreateDirectoryExW(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)
__EXTERN INTEGER __STDCALL CreateDirectoryW(LONGINT lpPathName, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateDirectoryW(lpPathName, lpSecurityAttributes)	CreateDirectoryW(lpPathName, lpSecurityAttributes)
__EXTERN LONGINT __STDCALL CreateDiscardableBitmap(LONGINT p0, INTEGER p1, INTEGER p2);
#define WinAPI_CreateDiscardableBitmap(p0, p1, p2)	CreateDiscardableBitmap(p0, p1, p2)
__EXTERN LONGINT __STDCALL CreateEllipticRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_CreateEllipticRgn(p0, p1, p2, p3)	CreateEllipticRgn(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL CreateEllipticRgnIndirect(WinAPI_RECT *p0);
#define WinAPI_CreateEllipticRgnIndirect(p0)	CreateEllipticRgnIndirect(p0)
#define WinAPI_CreateEnhMetaFile(p0, p1, p2, p3)	CreateEnhMetaFileA(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL CreateEnhMetaFileA(LONGINT p0, LONGINT p1, WinAPI_RECT *p2, LONGINT p3);
#define WinAPI_CreateEnhMetaFileA(p0, p1, p2, p3)	CreateEnhMetaFileA(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL CreateEnhMetaFileW(LONGINT p0, LONGINT p1, WinAPI_RECT *p2, LONGINT p3);
#define WinAPI_CreateEnhMetaFileW(p0, p1, p2, p3)	CreateEnhMetaFileW(p0, p1, p2, p3)
#define WinAPI_CreateEvent(lpEventAttributes, bManualReset, bInitialState, lpName)	CreateEventA(lpEventAttributes, bManualReset, bInitialState, lpName)
__EXTERN LONGINT __STDCALL CreateEventA(WinAPI_SECURITY_ATTRIBUTES *lpEventAttributes, INTEGER bManualReset, INTEGER bInitialState, LONGINT lpName);
#define WinAPI_CreateEventA(lpEventAttributes, bManualReset, bInitialState, lpName)	CreateEventA(lpEventAttributes, bManualReset, bInitialState, lpName)
__EXTERN LONGINT __STDCALL CreateEventW(WinAPI_SECURITY_ATTRIBUTES *lpEventAttributes, INTEGER bManualReset, INTEGER bInitialState, LONGINT lpName);
#define WinAPI_CreateEventW(lpEventAttributes, bManualReset, bInitialState, lpName)	CreateEventW(lpEventAttributes, bManualReset, bInitialState, lpName)
__EXTERN LONGINT __STDCALL CreateFiber(INTEGER dwStackSize, WinAPI_FIBER_START_ROUTINE lpStartAddress, LONGINT lpParameter);
#define WinAPI_CreateFiber(dwStackSize, lpStartAddress, lpParameter)	CreateFiber(dwStackSize, lpStartAddress, lpParameter)
#define WinAPI_CreateFile(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)	CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)
__EXTERN LONGINT __STDCALL CreateFileA(LONGINT lpFileName, SET dwDesiredAccess, SET dwShareMode, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER dwCreationDisposition, SET dwFlagsAndAttributes, LONGINT hTemplateFile);
#define WinAPI_CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)	CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)
#define WinAPI_CreateFileMapping(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)	CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)
__EXTERN LONGINT __STDCALL CreateFileMappingA(LONGINT hFile, WinAPI_SECURITY_ATTRIBUTES *lpFileMappingAttributes, SET flProtect, INTEGER dwMaximumSizeHigh, INTEGER dwMaximumSizeLow, LONGINT lpName);
#define WinAPI_CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)	CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)
__EXTERN LONGINT __STDCALL CreateFileMappingW(LONGINT hFile, WinAPI_SECURITY_ATTRIBUTES *lpFileMappingAttributes, SET flProtect, INTEGER dwMaximumSizeHigh, INTEGER dwMaximumSizeLow, LONGINT lpName);
#define WinAPI_CreateFileMappingW(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)	CreateFileMappingW(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)
__EXTERN LONGINT __STDCALL CreateFileW(LONGINT lpFileName, SET dwDesiredAccess, SET dwShareMode, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER dwCreationDisposition, SET dwFlagsAndAttributes, LONGINT hTemplateFile);
#define WinAPI_CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)	CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)
#define WinAPI_CreateFont(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)	CreateFontA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)
__EXTERN LONGINT __STDCALL CreateFontA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10, INTEGER p11, INTEGER p12, LONGINT p13);
#define WinAPI_CreateFontA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)	CreateFontA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)
#define WinAPI_CreateFontIndirect(p0)	CreateFontIndirectA(p0)
__EXTERN LONGINT __STDCALL CreateFontIndirectA(WinAPI_LOGFONTA *p0);
#define WinAPI_CreateFontIndirectA(p0)	CreateFontIndirectA(p0)
__EXTERN LONGINT __STDCALL CreateFontIndirectW(WinAPI_LOGFONTW *p0);
#define WinAPI_CreateFontIndirectW(p0)	CreateFontIndirectW(p0)
__EXTERN LONGINT __STDCALL CreateFontW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10, INTEGER p11, INTEGER p12, LONGINT p13);
#define WinAPI_CreateFontW(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)	CreateFontW(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)
__EXTERN LONGINT __STDCALL CreateHalftonePalette(LONGINT p0);
#define WinAPI_CreateHalftonePalette(p0)	CreateHalftonePalette(p0)
__EXTERN LONGINT __STDCALL CreateHatchBrush(INTEGER p0, INTEGER p1);
#define WinAPI_CreateHatchBrush(p0, p1)	CreateHatchBrush(p0, p1)
#define WinAPI_CreateIC(p0, p1, p2, p3)	CreateICA(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL CreateICA(LONGINT p0, LONGINT p1, LONGINT p2, WinAPI_DEVMODEA *p3);
#define WinAPI_CreateICA(p0, p1, p2, p3)	CreateICA(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL CreateICW(LONGINT p0, LONGINT p1, LONGINT p2, WinAPI_DEVMODEW *p3);
#define WinAPI_CreateICW(p0, p1, p2, p3)	CreateICW(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL CreateIcon(LONGINT hInstance, INTEGER nWidth, INTEGER nHeight, CHAR cPlanes, CHAR cBitsPixel, CHAR *lpbANDbits, CHAR *lpbXORbits);
#define WinAPI_CreateIcon(hInstance, nWidth, nHeight, cPlanes, cBitsPixel, lpbANDbits, lpbXORbits)	CreateIcon(hInstance, nWidth, nHeight, cPlanes, cBitsPixel, lpbANDbits, lpbXORbits)
__EXTERN LONGINT __STDCALL CreateIconFromResource(CHAR *presbits, INTEGER dwResSize, INTEGER fIcon, INTEGER dwVer);
#define WinAPI_CreateIconFromResource(presbits, dwResSize, fIcon, dwVer)	CreateIconFromResource(presbits, dwResSize, fIcon, dwVer)
__EXTERN LONGINT __STDCALL CreateIconFromResourceEx(CHAR *presbits, INTEGER dwResSize, INTEGER fIcon, INTEGER dwVer, INTEGER cxDesired, INTEGER cyDesired, SET Flags);
#define WinAPI_CreateIconFromResourceEx(presbits, dwResSize, fIcon, dwVer, cxDesired, cyDesired, Flags)	CreateIconFromResourceEx(presbits, dwResSize, fIcon, dwVer, cxDesired, cyDesired, Flags)
__EXTERN LONGINT __STDCALL CreateIconIndirect(WinAPI_ICONINFO *piconinfo);
#define WinAPI_CreateIconIndirect(piconinfo)	CreateIconIndirect(piconinfo)
__EXTERN LONGINT __STDCALL CreateIoCompletionPort(LONGINT FileHandle, LONGINT ExistingCompletionPort, INTEGER CompletionKey, INTEGER NumberOfConcurrentThreads);
#define WinAPI_CreateIoCompletionPort(FileHandle, ExistingCompletionPort, CompletionKey, NumberOfConcurrentThreads)	CreateIoCompletionPort(FileHandle, ExistingCompletionPort, CompletionKey, NumberOfConcurrentThreads)
#define WinAPI_CreateMDIWindow(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)	CreateMDIWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)
__EXTERN LONGINT __STDCALL CreateMDIWindowA(LONGINT lpClassName, LONGINT lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, LONGINT hWndParent, LONGINT hInstance, LONGINT lParam);
#define WinAPI_CreateMDIWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)	CreateMDIWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)
__EXTERN LONGINT __STDCALL CreateMDIWindowW(LONGINT lpClassName, LONGINT lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, LONGINT hWndParent, LONGINT hInstance, LONGINT lParam);
#define WinAPI_CreateMDIWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)	CreateMDIWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)
#define WinAPI_CreateMailslot(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)	CreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)
__EXTERN LONGINT __STDCALL CreateMailslotA(LONGINT lpName, INTEGER nMaxMessageSize, INTEGER lReadTimeout, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)	CreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)
__EXTERN LONGINT __STDCALL CreateMailslotW(LONGINT lpName, INTEGER nMaxMessageSize, INTEGER lReadTimeout, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateMailslotW(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)	CreateMailslotW(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)
__EXTERN LONGINT __STDCALL CreateMenu(void);
#define WinAPI_CreateMenu()	CreateMenu()
#define WinAPI_CreateMetaFile(p0)	CreateMetaFileA(p0)
__EXTERN LONGINT __STDCALL CreateMetaFileA(LONGINT p0);
#define WinAPI_CreateMetaFileA(p0)	CreateMetaFileA(p0)
__EXTERN LONGINT __STDCALL CreateMetaFileW(LONGINT p0);
#define WinAPI_CreateMetaFileW(p0)	CreateMetaFileW(p0)
#define WinAPI_CreateMutex(lpMutexAttributes, bInitialOwner, lpName)	CreateMutexA(lpMutexAttributes, bInitialOwner, lpName)
__EXTERN LONGINT __STDCALL CreateMutexA(WinAPI_SECURITY_ATTRIBUTES *lpMutexAttributes, INTEGER bInitialOwner, LONGINT lpName);
#define WinAPI_CreateMutexA(lpMutexAttributes, bInitialOwner, lpName)	CreateMutexA(lpMutexAttributes, bInitialOwner, lpName)
__EXTERN LONGINT __STDCALL CreateMutexW(WinAPI_SECURITY_ATTRIBUTES *lpMutexAttributes, INTEGER bInitialOwner, LONGINT lpName);
#define WinAPI_CreateMutexW(lpMutexAttributes, bInitialOwner, lpName)	CreateMutexW(lpMutexAttributes, bInitialOwner, lpName)
#define WinAPI_CreateNamedPipe(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)	CreateNamedPipeA(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)
__EXTERN LONGINT __STDCALL CreateNamedPipeA(LONGINT lpName, INTEGER dwOpenMode, INTEGER dwPipeMode, INTEGER nMaxInstances, INTEGER nOutBufferSize, INTEGER nInBufferSize, INTEGER nDefaultTimeOut, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateNamedPipeA(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)	CreateNamedPipeA(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)
__EXTERN LONGINT __STDCALL CreateNamedPipeW(LONGINT lpName, INTEGER dwOpenMode, INTEGER dwPipeMode, INTEGER nMaxInstances, INTEGER nOutBufferSize, INTEGER nInBufferSize, INTEGER nDefaultTimeOut, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateNamedPipeW(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)	CreateNamedPipeW(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)
__EXTERN LONGINT __STDCALL CreatePalette(WinAPI_LOGPALETTE *p0);
#define WinAPI_CreatePalette(p0)	CreatePalette(p0)
__EXTERN LONGINT __STDCALL CreatePatternBrush(LONGINT p0);
#define WinAPI_CreatePatternBrush(p0)	CreatePatternBrush(p0)
__EXTERN LONGINT __STDCALL CreatePen(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_CreatePen(p0, p1, p2)	CreatePen(p0, p1, p2)
__EXTERN LONGINT __STDCALL CreatePenIndirect(WinAPI_LOGPEN *p0);
#define WinAPI_CreatePenIndirect(p0)	CreatePenIndirect(p0)
__EXTERN INTEGER __STDCALL CreatePipe(LONGINT *hReadPipe, LONGINT *hWritePipe, WinAPI_SECURITY_ATTRIBUTES *lpPipeAttributes, INTEGER nSize);
#define WinAPI_CreatePipe(hReadPipe, hWritePipe, lpPipeAttributes, nSize)	CreatePipe(hReadPipe, hWritePipe, lpPipeAttributes, nSize)
__EXTERN LONGINT __STDCALL CreatePolyPolygonRgn(WinAPI_POINT *p0, INTEGER *p1, INTEGER p2, INTEGER p3);
#define WinAPI_CreatePolyPolygonRgn(p0, p1, p2, p3)	CreatePolyPolygonRgn(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL CreatePolygonRgn(WinAPI_POINT *p0, INTEGER p1, INTEGER p2);
#define WinAPI_CreatePolygonRgn(p0, p1, p2)	CreatePolygonRgn(p0, p1, p2)
__EXTERN LONGINT __STDCALL CreatePopupMenu(void);
#define WinAPI_CreatePopupMenu()	CreatePopupMenu()
__EXTERN INTEGER __STDCALL CreatePrivateObjectSecurity(LONGINT ParentDescriptor, LONGINT CreatorDescriptor, LONGINT *NewDescriptor, INTEGER IsDirectoryObject, LONGINT Token, WinAPI_GENERIC_MAPPING *GenericMapping);
#define WinAPI_CreatePrivateObjectSecurity(ParentDescriptor, CreatorDescriptor, NewDescriptor, IsDirectoryObject, Token, GenericMapping)	CreatePrivateObjectSecurity(ParentDescriptor, CreatorDescriptor, NewDescriptor, IsDirectoryObject, Token, GenericMapping)
#define WinAPI_CreateProcess(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)	CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
__EXTERN INTEGER __STDCALL CreateProcessA(LONGINT lpApplicationName, LONGINT lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, LONGINT lpEnvironment, LONGINT lpCurrentDirectory, WinAPI_STARTUPINFOA *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
#define WinAPI_CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)	CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
#define WinAPI_CreateProcessAsUser(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)	CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
__EXTERN INTEGER __STDCALL CreateProcessAsUserA(LONGINT hToken, LONGINT lpApplicationName, LONGINT lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, LONGINT lpEnvironment, LONGINT lpCurrentDirectory, WinAPI_STARTUPINFOA *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
#define WinAPI_CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)	CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
__EXTERN INTEGER __STDCALL CreateProcessAsUserW(LONGINT hToken, LONGINT lpApplicationName, LONGINT lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, LONGINT lpEnvironment, LONGINT lpCurrentDirectory, WinAPI_STARTUPINFOW *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
#define WinAPI_CreateProcessAsUserW(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)	CreateProcessAsUserW(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
__EXTERN INTEGER __STDCALL CreateProcessW(LONGINT lpApplicationName, LONGINT lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, LONGINT lpEnvironment, LONGINT lpCurrentDirectory, WinAPI_STARTUPINFOW *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
#define WinAPI_CreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)	CreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
#define WinAPI_CreatePropertySheetPage(p0)	CreatePropertySheetPageA(p0)
__EXTERN WinAPI_Ptr_PSP __STDCALL CreatePropertySheetPageA(WinAPI_PROPSHEETPAGEA *p0);
#define WinAPI_CreatePropertySheetPageA(p0)	CreatePropertySheetPageA(p0)
__EXTERN WinAPI_Ptr_PSP __STDCALL CreatePropertySheetPageW(WinAPI_PROPSHEETPAGEW *p0);
#define WinAPI_CreatePropertySheetPageW(p0)	CreatePropertySheetPageW(p0)
__EXTERN LONGINT __STDCALL CreateRectRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_CreateRectRgn(p0, p1, p2, p3)	CreateRectRgn(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL CreateRectRgnIndirect(WinAPI_RECT *p0);
#define WinAPI_CreateRectRgnIndirect(p0)	CreateRectRgnIndirect(p0)
__EXTERN LONGINT __STDCALL CreateRemoteThread(LONGINT hProcess, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER dwStackSize, WinAPI_THREAD_START_ROUTINE lpStartAddress, LONGINT lpParameter, SET dwCreationFlags, INTEGER *lpThreadId);
#define WinAPI_CreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId)	CreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId)
__EXTERN LONGINT __STDCALL CreateRoundRectRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
#define WinAPI_CreateRoundRectRgn(p0, p1, p2, p3, p4, p5)	CreateRoundRectRgn(p0, p1, p2, p3, p4, p5)
#define WinAPI_CreateScalableFontResource(p0, p1, p2, p3)	CreateScalableFontResourceA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL CreateScalableFontResourceA(INTEGER p0, LONGINT p1, LONGINT p2, LONGINT p3);
#define WinAPI_CreateScalableFontResourceA(p0, p1, p2, p3)	CreateScalableFontResourceA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL CreateScalableFontResourceW(INTEGER p0, LONGINT p1, LONGINT p2, LONGINT p3);
#define WinAPI_CreateScalableFontResourceW(p0, p1, p2, p3)	CreateScalableFontResourceW(p0, p1, p2, p3)
#define WinAPI_CreateSemaphore(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)	CreateSemaphoreA(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)
__EXTERN LONGINT __STDCALL CreateSemaphoreA(WinAPI_SECURITY_ATTRIBUTES *lpSemaphoreAttributes, INTEGER lInitialCount, INTEGER lMaximumCount, LONGINT lpName);
#define WinAPI_CreateSemaphoreA(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)	CreateSemaphoreA(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)
__EXTERN LONGINT __STDCALL CreateSemaphoreW(WinAPI_SECURITY_ATTRIBUTES *lpSemaphoreAttributes, INTEGER lInitialCount, INTEGER lMaximumCount, LONGINT lpName);
#define WinAPI_CreateSemaphoreW(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)	CreateSemaphoreW(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)
#define WinAPI_CreateService(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)	CreateServiceA(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)
__EXTERN LONGINT __STDCALL CreateServiceA(LONGINT hSCManager, LONGINT lpServiceName, LONGINT lpDisplayName, SET dwDesiredAccess, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, LONGINT lpBinaryPathName, LONGINT lpLoadOrderGroup, INTEGER *lpdwTagId, LONGINT lpDependencies, LONGINT lpServiceStartName, LONGINT lpPassword);
#define WinAPI_CreateServiceA(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)	CreateServiceA(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)
__EXTERN LONGINT __STDCALL CreateServiceW(LONGINT hSCManager, LONGINT lpServiceName, LONGINT lpDisplayName, SET dwDesiredAccess, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, LONGINT lpBinaryPathName, LONGINT lpLoadOrderGroup, INTEGER *lpdwTagId, LONGINT lpDependencies, LONGINT lpServiceStartName, LONGINT lpPassword);
#define WinAPI_CreateServiceW(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)	CreateServiceW(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)
__EXTERN LONGINT __STDCALL CreateSolidBrush(INTEGER p0);
#define WinAPI_CreateSolidBrush(p0)	CreateSolidBrush(p0)
__EXTERN INTEGER __STDCALL CreateTapePartition(LONGINT hDevice, INTEGER dwPartitionMethod, INTEGER dwCount, INTEGER dwSize);
#define WinAPI_CreateTapePartition(hDevice, dwPartitionMethod, dwCount, dwSize)	CreateTapePartition(hDevice, dwPartitionMethod, dwCount, dwSize)
__EXTERN LONGINT __STDCALL CreateThread(WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER dwStackSize, WinAPI_THREAD_START_ROUTINE lpStartAddress, LONGINT lpParameter, SET dwCreationFlags, INTEGER *lpThreadId);
#define WinAPI_CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId)	CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId)
#define WinAPI_CreateWaitableTimer(lpTimerAttributes, bManualReset, lpTimerName)	CreateWaitableTimerA(lpTimerAttributes, bManualReset, lpTimerName)
__EXTERN LONGINT __STDCALL CreateWaitableTimerA(WinAPI_SECURITY_ATTRIBUTES *lpTimerAttributes, INTEGER bManualReset, LONGINT lpTimerName);
#define WinAPI_CreateWaitableTimerA(lpTimerAttributes, bManualReset, lpTimerName)	CreateWaitableTimerA(lpTimerAttributes, bManualReset, lpTimerName)
__EXTERN LONGINT __STDCALL CreateWaitableTimerW(WinAPI_SECURITY_ATTRIBUTES *lpTimerAttributes, INTEGER bManualReset, LONGINT lpTimerName);
#define WinAPI_CreateWaitableTimerW(lpTimerAttributes, bManualReset, lpTimerName)	CreateWaitableTimerW(lpTimerAttributes, bManualReset, lpTimerName)
#define WinAPI_CreateWindowEx(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)	CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
__EXTERN LONGINT __STDCALL CreateWindowExA(SET dwExStyle, LONGINT lpClassName, LONGINT lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, LONGINT hWndParent, LONGINT hMenu, LONGINT hInstance, LONGINT lpParam);
#define WinAPI_CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)	CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
__EXTERN LONGINT __STDCALL CreateWindowExW(SET dwExStyle, LONGINT lpClassName, LONGINT lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, LONGINT hWndParent, LONGINT hMenu, LONGINT hInstance, LONGINT lpParam);
#define WinAPI_CreateWindowExW(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)	CreateWindowExW(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
#define WinAPI_CreateWindowStation(lpwinsta, dwReserved, dwDesiredAccess, lpsa)	CreateWindowStationA(lpwinsta, dwReserved, dwDesiredAccess, lpsa)
__EXTERN LONGINT __STDCALL CreateWindowStationA(LONGINT lpwinsta, INTEGER dwReserved, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
#define WinAPI_CreateWindowStationA(lpwinsta, dwReserved, dwDesiredAccess, lpsa)	CreateWindowStationA(lpwinsta, dwReserved, dwDesiredAccess, lpsa)
__EXTERN LONGINT __STDCALL CreateWindowStationW(LONGINT lpwinsta, INTEGER dwReserved, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
#define WinAPI_CreateWindowStationW(lpwinsta, dwReserved, dwDesiredAccess, lpsa)	CreateWindowStationW(lpwinsta, dwReserved, dwDesiredAccess, lpsa)
__EXTERN INTEGER __STDCALL DPtoLP(LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_DPtoLP(p0, p1, p2)	DPtoLP(p0, p1, p2)
__EXTERN INTEGER __STDCALL DdeAbandonTransaction(INTEGER idInst, LONGINT hConv, INTEGER idTransaction);
#define WinAPI_DdeAbandonTransaction(idInst, hConv, idTransaction)	DdeAbandonTransaction(idInst, hConv, idTransaction)
__EXTERN LONGINT __STDCALL DdeAccessData(LONGINT hData, INTEGER *pcbDataSize);
#define WinAPI_DdeAccessData(hData, pcbDataSize)	DdeAccessData(hData, pcbDataSize)
__EXTERN LONGINT __STDCALL DdeAddData(LONGINT hData, CHAR *pSrc, INTEGER cb, INTEGER cbOff);
#define WinAPI_DdeAddData(hData, pSrc, cb, cbOff)	DdeAddData(hData, pSrc, cb, cbOff)
__EXTERN LONGINT __STDCALL DdeClientTransaction(CHAR *pData, INTEGER cbData, LONGINT hConv, LONGINT hszItem, INTEGER wFmt, INTEGER wType, INTEGER dwTimeout, INTEGER *pdwResult);
#define WinAPI_DdeClientTransaction(pData, cbData, hConv, hszItem, wFmt, wType, dwTimeout, pdwResult)	DdeClientTransaction(pData, cbData, hConv, hszItem, wFmt, wType, dwTimeout, pdwResult)
__EXTERN INTEGER __STDCALL DdeCmpStringHandles(LONGINT hsz1, LONGINT hsz2);
#define WinAPI_DdeCmpStringHandles(hsz1, hsz2)	DdeCmpStringHandles(hsz1, hsz2)
__EXTERN LONGINT __STDCALL DdeConnect(INTEGER idInst, LONGINT hszService, LONGINT hszTopic, WinAPI_CONVCONTEXT *pCC);
#define WinAPI_DdeConnect(idInst, hszService, hszTopic, pCC)	DdeConnect(idInst, hszService, hszTopic, pCC)
__EXTERN LONGINT __STDCALL DdeConnectList(INTEGER idInst, LONGINT hszService, LONGINT hszTopic, LONGINT hConvList, WinAPI_CONVCONTEXT *pCC);
#define WinAPI_DdeConnectList(idInst, hszService, hszTopic, hConvList, pCC)	DdeConnectList(idInst, hszService, hszTopic, hConvList, pCC)
__EXTERN LONGINT __STDCALL DdeCreateDataHandle(INTEGER idInst, CHAR *pSrc, INTEGER cb, INTEGER cbOff, LONGINT hszItem, INTEGER wFmt, INTEGER afCmd);
#define WinAPI_DdeCreateDataHandle(idInst, pSrc, cb, cbOff, hszItem, wFmt, afCmd)	DdeCreateDataHandle(idInst, pSrc, cb, cbOff, hszItem, wFmt, afCmd)
#define WinAPI_DdeCreateStringHandle(idInst, psz, iCodePage)	DdeCreateStringHandleA(idInst, psz, iCodePage)
__EXTERN LONGINT __STDCALL DdeCreateStringHandleA(INTEGER idInst, LONGINT psz, INTEGER iCodePage);
#define WinAPI_DdeCreateStringHandleA(idInst, psz, iCodePage)	DdeCreateStringHandleA(idInst, psz, iCodePage)
__EXTERN LONGINT __STDCALL DdeCreateStringHandleW(INTEGER idInst, LONGINT psz, INTEGER iCodePage);
#define WinAPI_DdeCreateStringHandleW(idInst, psz, iCodePage)	DdeCreateStringHandleW(idInst, psz, iCodePage)
__EXTERN INTEGER __STDCALL DdeDisconnect(LONGINT hConv);
#define WinAPI_DdeDisconnect(hConv)	DdeDisconnect(hConv)
__EXTERN INTEGER __STDCALL DdeDisconnectList(LONGINT hConvList);
#define WinAPI_DdeDisconnectList(hConvList)	DdeDisconnectList(hConvList)
__EXTERN INTEGER __STDCALL DdeEnableCallback(INTEGER idInst, LONGINT hConv, INTEGER wCmd);
#define WinAPI_DdeEnableCallback(idInst, hConv, wCmd)	DdeEnableCallback(idInst, hConv, wCmd)
__EXTERN INTEGER __STDCALL DdeFreeDataHandle(LONGINT hData);
#define WinAPI_DdeFreeDataHandle(hData)	DdeFreeDataHandle(hData)
__EXTERN INTEGER __STDCALL DdeFreeStringHandle(INTEGER idInst, LONGINT hsz);
#define WinAPI_DdeFreeStringHandle(idInst, hsz)	DdeFreeStringHandle(idInst, hsz)
__EXTERN INTEGER __STDCALL DdeGetData(LONGINT hData, CHAR *pDst, INTEGER cbMax, INTEGER cbOff);
#define WinAPI_DdeGetData(hData, pDst, cbMax, cbOff)	DdeGetData(hData, pDst, cbMax, cbOff)
__EXTERN INTEGER __STDCALL DdeGetLastError(INTEGER idInst);
#define WinAPI_DdeGetLastError(idInst)	DdeGetLastError(idInst)
__EXTERN INTEGER __STDCALL DdeImpersonateClient(LONGINT hConv);
#define WinAPI_DdeImpersonateClient(hConv)	DdeImpersonateClient(hConv)
#define WinAPI_DdeInitialize(pidInst, pfnCallback, afCmd, ulRes)	DdeInitializeA(pidInst, pfnCallback, afCmd, ulRes)
__EXTERN INTEGER __STDCALL DdeInitializeA(INTEGER *pidInst, WinAPI_FNCALLBACK pfnCallback, INTEGER afCmd, INTEGER ulRes);
#define WinAPI_DdeInitializeA(pidInst, pfnCallback, afCmd, ulRes)	DdeInitializeA(pidInst, pfnCallback, afCmd, ulRes)
__EXTERN INTEGER __STDCALL DdeInitializeW(INTEGER *pidInst, WinAPI_FNCALLBACK pfnCallback, INTEGER afCmd, INTEGER ulRes);
#define WinAPI_DdeInitializeW(pidInst, pfnCallback, afCmd, ulRes)	DdeInitializeW(pidInst, pfnCallback, afCmd, ulRes)
__EXTERN INTEGER __STDCALL DdeKeepStringHandle(INTEGER idInst, LONGINT hsz);
#define WinAPI_DdeKeepStringHandle(idInst, hsz)	DdeKeepStringHandle(idInst, hsz)
__EXTERN LONGINT __STDCALL DdeNameService(INTEGER idInst, LONGINT hsz1, LONGINT hsz2, INTEGER afCmd);
#define WinAPI_DdeNameService(idInst, hsz1, hsz2, afCmd)	DdeNameService(idInst, hsz1, hsz2, afCmd)
__EXTERN INTEGER __STDCALL DdePostAdvise(INTEGER idInst, LONGINT hszTopic, LONGINT hszItem);
#define WinAPI_DdePostAdvise(idInst, hszTopic, hszItem)	DdePostAdvise(idInst, hszTopic, hszItem)
__EXTERN INTEGER __STDCALL DdeQueryConvInfo(LONGINT hConv, INTEGER idTransaction, WinAPI_CONVINFO *pConvInfo);
#define WinAPI_DdeQueryConvInfo(hConv, idTransaction, pConvInfo)	DdeQueryConvInfo(hConv, idTransaction, pConvInfo)
__EXTERN LONGINT __STDCALL DdeQueryNextServer(LONGINT hConvList, LONGINT hConvPrev);
#define WinAPI_DdeQueryNextServer(hConvList, hConvPrev)	DdeQueryNextServer(hConvList, hConvPrev)
#define WinAPI_DdeQueryString(idInst, hsz, psz, cchMax, iCodePage)	DdeQueryStringA(idInst, hsz, psz, cchMax, iCodePage)
__EXTERN INTEGER __STDCALL DdeQueryStringA(INTEGER idInst, LONGINT hsz, LONGINT psz, INTEGER cchMax, INTEGER iCodePage);
#define WinAPI_DdeQueryStringA(idInst, hsz, psz, cchMax, iCodePage)	DdeQueryStringA(idInst, hsz, psz, cchMax, iCodePage)
__EXTERN INTEGER __STDCALL DdeQueryStringW(INTEGER idInst, LONGINT hsz, LONGINT psz, INTEGER cchMax, INTEGER iCodePage);
#define WinAPI_DdeQueryStringW(idInst, hsz, psz, cchMax, iCodePage)	DdeQueryStringW(idInst, hsz, psz, cchMax, iCodePage)
__EXTERN LONGINT __STDCALL DdeReconnect(LONGINT hConv);
#define WinAPI_DdeReconnect(hConv)	DdeReconnect(hConv)
__EXTERN INTEGER __STDCALL DdeSetQualityOfService(LONGINT hwndClient, WinAPI_SECURITY_QUALITY_OF_SERVICE *pqosNew, WinAPI_SECURITY_QUALITY_OF_SERVICE *pqosPrev);
#define WinAPI_DdeSetQualityOfService(hwndClient, pqosNew, pqosPrev)	DdeSetQualityOfService(hwndClient, pqosNew, pqosPrev)
__EXTERN INTEGER __STDCALL DdeSetUserHandle(LONGINT hConv, INTEGER id, INTEGER hUser);
#define WinAPI_DdeSetUserHandle(hConv, id, hUser)	DdeSetUserHandle(hConv, id, hUser)
__EXTERN INTEGER __STDCALL DdeUnaccessData(LONGINT hData);
#define WinAPI_DdeUnaccessData(hData)	DdeUnaccessData(hData)
__EXTERN INTEGER __STDCALL DdeUninitialize(INTEGER idInst);
#define WinAPI_DdeUninitialize(idInst)	DdeUninitialize(idInst)
__EXTERN INTEGER __STDCALL DebugActiveProcess(INTEGER dwProcessId);
#define WinAPI_DebugActiveProcess(dwProcessId)	DebugActiveProcess(dwProcessId)
__EXTERN void __STDCALL DebugBreak(void);
#define WinAPI_DebugBreak()	DebugBreak()
#define WinAPI_DefDlgProc(hDlg, Msg, wParam, lParam)	DefDlgProcA(hDlg, Msg, wParam, lParam)
__EXTERN LONGINT __STDCALL DefDlgProcA(LONGINT hDlg, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_DefDlgProcA(hDlg, Msg, wParam, lParam)	DefDlgProcA(hDlg, Msg, wParam, lParam)
__EXTERN LONGINT __STDCALL DefDlgProcW(LONGINT hDlg, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_DefDlgProcW(hDlg, Msg, wParam, lParam)	DefDlgProcW(hDlg, Msg, wParam, lParam)
#define WinAPI_DefFrameProc(hWnd, hWndMDIClient, uMsg, wParam, lParam)	DefFrameProcA(hWnd, hWndMDIClient, uMsg, wParam, lParam)
__EXTERN LONGINT __STDCALL DefFrameProcA(LONGINT hWnd, LONGINT hWndMDIClient, INTEGER uMsg, LONGINT wParam, LONGINT lParam);
#define WinAPI_DefFrameProcA(hWnd, hWndMDIClient, uMsg, wParam, lParam)	DefFrameProcA(hWnd, hWndMDIClient, uMsg, wParam, lParam)
__EXTERN LONGINT __STDCALL DefFrameProcW(LONGINT hWnd, LONGINT hWndMDIClient, INTEGER uMsg, LONGINT wParam, LONGINT lParam);
#define WinAPI_DefFrameProcW(hWnd, hWndMDIClient, uMsg, wParam, lParam)	DefFrameProcW(hWnd, hWndMDIClient, uMsg, wParam, lParam)
#define WinAPI_DefMDIChildProc(hWnd, uMsg, wParam, lParam)	DefMDIChildProcA(hWnd, uMsg, wParam, lParam)
__EXTERN LONGINT __STDCALL DefMDIChildProcA(LONGINT hWnd, INTEGER uMsg, LONGINT wParam, LONGINT lParam);
#define WinAPI_DefMDIChildProcA(hWnd, uMsg, wParam, lParam)	DefMDIChildProcA(hWnd, uMsg, wParam, lParam)
__EXTERN LONGINT __STDCALL DefMDIChildProcW(LONGINT hWnd, INTEGER uMsg, LONGINT wParam, LONGINT lParam);
#define WinAPI_DefMDIChildProcW(hWnd, uMsg, wParam, lParam)	DefMDIChildProcW(hWnd, uMsg, wParam, lParam)
#define WinAPI_DefWindowProc(hWnd, Msg, wParam, lParam)	DefWindowProcA(hWnd, Msg, wParam, lParam)
__EXTERN LONGINT __STDCALL DefWindowProcA(LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_DefWindowProcA(hWnd, Msg, wParam, lParam)	DefWindowProcA(hWnd, Msg, wParam, lParam)
__EXTERN LONGINT __STDCALL DefWindowProcW(LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_DefWindowProcW(hWnd, Msg, wParam, lParam)	DefWindowProcW(hWnd, Msg, wParam, lParam)
__EXTERN LONGINT __STDCALL DeferWindowPos(LONGINT hWinPosInfo, LONGINT hWnd, LONGINT hWndInsertAfter, INTEGER x, INTEGER y, INTEGER cx, INTEGER cy, SET uFlags);
#define WinAPI_DeferWindowPos(hWinPosInfo, hWnd, hWndInsertAfter, x, y, cx, cy, uFlags)	DeferWindowPos(hWinPosInfo, hWnd, hWndInsertAfter, x, y, cx, cy, uFlags)
#define WinAPI_DefineDosDevice(dwFlags, lpDeviceName, lpTargetPath)	DefineDosDeviceA(dwFlags, lpDeviceName, lpTargetPath)
__EXTERN INTEGER __STDCALL DefineDosDeviceA(SET dwFlags, LONGINT lpDeviceName, LONGINT lpTargetPath);
#define WinAPI_DefineDosDeviceA(dwFlags, lpDeviceName, lpTargetPath)	DefineDosDeviceA(dwFlags, lpDeviceName, lpTargetPath)
__EXTERN INTEGER __STDCALL DefineDosDeviceW(SET dwFlags, LONGINT lpDeviceName, LONGINT lpTargetPath);
#define WinAPI_DefineDosDeviceW(dwFlags, lpDeviceName, lpTargetPath)	DefineDosDeviceW(dwFlags, lpDeviceName, lpTargetPath)
__EXTERN INTEGER __STDCALL DeleteAce(WinAPI_ACL *pAcl, INTEGER dwAceIndex);
#define WinAPI_DeleteAce(pAcl, dwAceIndex)	DeleteAce(pAcl, dwAceIndex)
__EXTERN SHORTINT __STDCALL DeleteAtom(SHORTINT nAtom);
#define WinAPI_DeleteAtom(nAtom)	DeleteAtom(nAtom)
__EXTERN INTEGER __STDCALL DeleteColorSpace(LONGINT p0);
#define WinAPI_DeleteColorSpace(p0)	DeleteColorSpace(p0)
__EXTERN void __STDCALL DeleteCriticalSection(WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinAPI_DeleteCriticalSection(lpCriticalSection)	DeleteCriticalSection(lpCriticalSection)
__EXTERN INTEGER __STDCALL DeleteDC(LONGINT p0);
#define WinAPI_DeleteDC(p0)	DeleteDC(p0)
__EXTERN INTEGER __STDCALL DeleteEnhMetaFile(LONGINT p0);
#define WinAPI_DeleteEnhMetaFile(p0)	DeleteEnhMetaFile(p0)
__EXTERN void __STDCALL DeleteFiber(LONGINT lpFiber);
#define WinAPI_DeleteFiber(lpFiber)	DeleteFiber(lpFiber)
#define WinAPI_DeleteFile(lpFileName)	DeleteFileA(lpFileName)
__EXTERN INTEGER __STDCALL DeleteFileA(LONGINT lpFileName);
#define WinAPI_DeleteFileA(lpFileName)	DeleteFileA(lpFileName)
__EXTERN INTEGER __STDCALL DeleteFileW(LONGINT lpFileName);
#define WinAPI_DeleteFileW(lpFileName)	DeleteFileW(lpFileName)
#define WinAPI_DeleteForm(hPrinter, pFormName)	DeleteFormA(hPrinter, pFormName)
__EXTERN INTEGER __STDCALL DeleteFormA(LONGINT hPrinter, LONGINT pFormName);
#define WinAPI_DeleteFormA(hPrinter, pFormName)	DeleteFormA(hPrinter, pFormName)
__EXTERN INTEGER __STDCALL DeleteFormW(LONGINT hPrinter, LONGINT pFormName);
#define WinAPI_DeleteFormW(hPrinter, pFormName)	DeleteFormW(hPrinter, pFormName)
__EXTERN INTEGER __STDCALL DeleteMenu(LONGINT hMenu, INTEGER uPosition, SET uFlags);
#define WinAPI_DeleteMenu(hMenu, uPosition, uFlags)	DeleteMenu(hMenu, uPosition, uFlags)
__EXTERN INTEGER __STDCALL DeleteMetaFile(LONGINT p0);
#define WinAPI_DeleteMetaFile(p0)	DeleteMetaFile(p0)
#define WinAPI_DeleteMonitor(pName, pEnvironment, pMonitorName)	DeleteMonitorA(pName, pEnvironment, pMonitorName)
__EXTERN INTEGER __STDCALL DeleteMonitorA(LONGINT pName, LONGINT pEnvironment, LONGINT pMonitorName);
#define WinAPI_DeleteMonitorA(pName, pEnvironment, pMonitorName)	DeleteMonitorA(pName, pEnvironment, pMonitorName)
__EXTERN INTEGER __STDCALL DeleteMonitorW(LONGINT pName, LONGINT pEnvironment, LONGINT pMonitorName);
#define WinAPI_DeleteMonitorW(pName, pEnvironment, pMonitorName)	DeleteMonitorW(pName, pEnvironment, pMonitorName)
__EXTERN INTEGER __STDCALL DeleteObject(LONGINT p0);
#define WinAPI_DeleteObject(p0)	DeleteObject(p0)
#define WinAPI_DeletePort(pName, hWnd, pPortName)	DeletePortA(pName, hWnd, pPortName)
__EXTERN INTEGER __STDCALL DeletePortA(LONGINT pName, LONGINT hWnd, LONGINT pPortName);
#define WinAPI_DeletePortA(pName, hWnd, pPortName)	DeletePortA(pName, hWnd, pPortName)
__EXTERN INTEGER __STDCALL DeletePortW(LONGINT pName, LONGINT hWnd, LONGINT pPortName);
#define WinAPI_DeletePortW(pName, hWnd, pPortName)	DeletePortW(pName, hWnd, pPortName)
#define WinAPI_DeletePrintProcessor(pName, pEnvironment, pPrintProcessorName)	DeletePrintProcessorA(pName, pEnvironment, pPrintProcessorName)
__EXTERN INTEGER __STDCALL DeletePrintProcessorA(LONGINT pName, LONGINT pEnvironment, LONGINT pPrintProcessorName);
#define WinAPI_DeletePrintProcessorA(pName, pEnvironment, pPrintProcessorName)	DeletePrintProcessorA(pName, pEnvironment, pPrintProcessorName)
__EXTERN INTEGER __STDCALL DeletePrintProcessorW(LONGINT pName, LONGINT pEnvironment, LONGINT pPrintProcessorName);
#define WinAPI_DeletePrintProcessorW(pName, pEnvironment, pPrintProcessorName)	DeletePrintProcessorW(pName, pEnvironment, pPrintProcessorName)
#define WinAPI_DeletePrintProvidor(pName, pEnvironment, pPrintProvidorName)	DeletePrintProvidorA(pName, pEnvironment, pPrintProvidorName)
__EXTERN INTEGER __STDCALL DeletePrintProvidorA(LONGINT pName, LONGINT pEnvironment, LONGINT pPrintProvidorName);
#define WinAPI_DeletePrintProvidorA(pName, pEnvironment, pPrintProvidorName)	DeletePrintProvidorA(pName, pEnvironment, pPrintProvidorName)
__EXTERN INTEGER __STDCALL DeletePrintProvidorW(LONGINT pName, LONGINT pEnvironment, LONGINT pPrintProvidorName);
#define WinAPI_DeletePrintProvidorW(pName, pEnvironment, pPrintProvidorName)	DeletePrintProvidorW(pName, pEnvironment, pPrintProvidorName)
__EXTERN INTEGER __STDCALL DeletePrinter(LONGINT hPrinter);
#define WinAPI_DeletePrinter(hPrinter)	DeletePrinter(hPrinter)
#define WinAPI_DeletePrinterConnection(pName)	DeletePrinterConnectionA(pName)
__EXTERN INTEGER __STDCALL DeletePrinterConnectionA(LONGINT pName);
#define WinAPI_DeletePrinterConnectionA(pName)	DeletePrinterConnectionA(pName)
__EXTERN INTEGER __STDCALL DeletePrinterConnectionW(LONGINT pName);
#define WinAPI_DeletePrinterConnectionW(pName)	DeletePrinterConnectionW(pName)
#define WinAPI_DeletePrinterDriver(pName, pEnvironment, pDriverName)	DeletePrinterDriverA(pName, pEnvironment, pDriverName)
__EXTERN INTEGER __STDCALL DeletePrinterDriverA(LONGINT pName, LONGINT pEnvironment, LONGINT pDriverName);
#define WinAPI_DeletePrinterDriverA(pName, pEnvironment, pDriverName)	DeletePrinterDriverA(pName, pEnvironment, pDriverName)
__EXTERN INTEGER __STDCALL DeletePrinterDriverW(LONGINT pName, LONGINT pEnvironment, LONGINT pDriverName);
#define WinAPI_DeletePrinterDriverW(pName, pEnvironment, pDriverName)	DeletePrinterDriverW(pName, pEnvironment, pDriverName)
__EXTERN INTEGER __STDCALL DeleteService(LONGINT hService);
#define WinAPI_DeleteService(hService)	DeleteService(hService)
__EXTERN INTEGER __STDCALL DeregisterEventSource(LONGINT hEventLog);
#define WinAPI_DeregisterEventSource(hEventLog)	DeregisterEventSource(hEventLog)
__EXTERN INTEGER __STDCALL DescribePixelFormat(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_PIXELFORMATDESCRIPTOR *p3);
#define WinAPI_DescribePixelFormat(p0, p1, p2, p3)	DescribePixelFormat(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL DestroyAcceleratorTable(LONGINT hAccel);
#define WinAPI_DestroyAcceleratorTable(hAccel)	DestroyAcceleratorTable(hAccel)
__EXTERN INTEGER __STDCALL DestroyCaret(void);
#define WinAPI_DestroyCaret()	DestroyCaret()
__EXTERN INTEGER __STDCALL DestroyCursor(LONGINT hCursor);
#define WinAPI_DestroyCursor(hCursor)	DestroyCursor(hCursor)
__EXTERN INTEGER __STDCALL DestroyIcon(LONGINT hIcon);
#define WinAPI_DestroyIcon(hIcon)	DestroyIcon(hIcon)
__EXTERN INTEGER __STDCALL DestroyMenu(LONGINT hMenu);
#define WinAPI_DestroyMenu(hMenu)	DestroyMenu(hMenu)
__EXTERN INTEGER __STDCALL DestroyPrivateObjectSecurity(LONGINT *ObjectDescriptor);
#define WinAPI_DestroyPrivateObjectSecurity(ObjectDescriptor)	DestroyPrivateObjectSecurity(ObjectDescriptor)
__EXTERN INTEGER __STDCALL DestroyPropertySheetPage(WinAPI_Ptr_PSP p0);
#define WinAPI_DestroyPropertySheetPage(p0)	DestroyPropertySheetPage(p0)
__EXTERN INTEGER __STDCALL DestroyWindow(LONGINT hWnd);
#define WinAPI_DestroyWindow(hWnd)	DestroyWindow(hWnd)
#define WinAPI_DeviceCapabilities(p0, p1, p2, p3, p4)	DeviceCapabilitiesA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL DeviceCapabilitiesA(LONGINT p0, LONGINT p1, SHORTINT p2, LONGINT p3, WinAPI_DEVMODEA *p4);
#define WinAPI_DeviceCapabilitiesA(p0, p1, p2, p3, p4)	DeviceCapabilitiesA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL DeviceCapabilitiesW(LONGINT p0, LONGINT p1, SHORTINT p2, LONGINT p3, WinAPI_DEVMODEW *p4);
#define WinAPI_DeviceCapabilitiesW(p0, p1, p2, p3, p4)	DeviceCapabilitiesW(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL DeviceIoControl(LONGINT hDevice, INTEGER dwIoControlCode, LONGINT lpInBuffer, INTEGER nInBufferSize, LONGINT lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesReturned, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_DeviceIoControl(hDevice, dwIoControlCode, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesReturned, lpOverlapped)	DeviceIoControl(hDevice, dwIoControlCode, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesReturned, lpOverlapped)
#define WinAPI_DialogBoxIndirectParam(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxIndirectParamA(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __STDCALL DialogBoxIndirectParamA(LONGINT hInstance, WinAPI_DLGTEMPLATE *hDialogTemplate, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
#define WinAPI_DialogBoxIndirectParamA(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxIndirectParamA(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __STDCALL DialogBoxIndirectParamW(LONGINT hInstance, WinAPI_DLGTEMPLATE *hDialogTemplate, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
#define WinAPI_DialogBoxIndirectParamW(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxIndirectParamW(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)
#define WinAPI_DialogBoxParam(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __STDCALL DialogBoxParamA(LONGINT hInstance, LONGINT lpTemplateName, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
#define WinAPI_DialogBoxParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __STDCALL DialogBoxParamW(LONGINT hInstance, LONGINT lpTemplateName, LONGINT hWndParent, WinAPI_DLGPROC lpDialogFunc, LONGINT dwInitParam);
#define WinAPI_DialogBoxParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __STDCALL DisableThreadLibraryCalls(LONGINT hLibModule);
#define WinAPI_DisableThreadLibraryCalls(hLibModule)	DisableThreadLibraryCalls(hLibModule)
__EXTERN INTEGER __STDCALL DisconnectNamedPipe(LONGINT hNamedPipe);
#define WinAPI_DisconnectNamedPipe(hNamedPipe)	DisconnectNamedPipe(hNamedPipe)
#define WinAPI_DispatchMessage(lpMsg)	DispatchMessageA(lpMsg)
__EXTERN INTEGER __STDCALL DispatchMessageA(WinAPI_MSG *lpMsg);
#define WinAPI_DispatchMessageA(lpMsg)	DispatchMessageA(lpMsg)
__EXTERN INTEGER __STDCALL DispatchMessageW(WinAPI_MSG *lpMsg);
#define WinAPI_DispatchMessageW(lpMsg)	DispatchMessageW(lpMsg)
#define WinAPI_DlgDirList(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)	DlgDirListA(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)
__EXTERN INTEGER __STDCALL DlgDirListA(LONGINT hDlg, LONGINT lpPathSpec, INTEGER nIDListBox, INTEGER nIDStaticPath, SET uFileType);
#define WinAPI_DlgDirListA(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)	DlgDirListA(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)
#define WinAPI_DlgDirListComboBox(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)	DlgDirListComboBoxA(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)
__EXTERN INTEGER __STDCALL DlgDirListComboBoxA(LONGINT hDlg, LONGINT lpPathSpec, INTEGER nIDComboBox, INTEGER nIDStaticPath, INTEGER uFiletype);
#define WinAPI_DlgDirListComboBoxA(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)	DlgDirListComboBoxA(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)
__EXTERN INTEGER __STDCALL DlgDirListComboBoxW(LONGINT hDlg, LONGINT lpPathSpec, INTEGER nIDComboBox, INTEGER nIDStaticPath, INTEGER uFiletype);
#define WinAPI_DlgDirListComboBoxW(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)	DlgDirListComboBoxW(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)
__EXTERN INTEGER __STDCALL DlgDirListW(LONGINT hDlg, LONGINT lpPathSpec, INTEGER nIDListBox, INTEGER nIDStaticPath, SET uFileType);
#define WinAPI_DlgDirListW(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)	DlgDirListW(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)
#define WinAPI_DlgDirSelectComboBoxEx(hDlg, lpString, nCount, nIDComboBox)	DlgDirSelectComboBoxExA(hDlg, lpString, nCount, nIDComboBox)
__EXTERN INTEGER __STDCALL DlgDirSelectComboBoxExA(LONGINT hDlg, LONGINT lpString, INTEGER nCount, INTEGER nIDComboBox);
#define WinAPI_DlgDirSelectComboBoxExA(hDlg, lpString, nCount, nIDComboBox)	DlgDirSelectComboBoxExA(hDlg, lpString, nCount, nIDComboBox)
__EXTERN INTEGER __STDCALL DlgDirSelectComboBoxExW(LONGINT hDlg, LONGINT lpString, INTEGER nCount, INTEGER nIDComboBox);
#define WinAPI_DlgDirSelectComboBoxExW(hDlg, lpString, nCount, nIDComboBox)	DlgDirSelectComboBoxExW(hDlg, lpString, nCount, nIDComboBox)
#define WinAPI_DlgDirSelectEx(hDlg, lpString, nCount, nIDListBox)	DlgDirSelectExA(hDlg, lpString, nCount, nIDListBox)
__EXTERN INTEGER __STDCALL DlgDirSelectExA(LONGINT hDlg, LONGINT lpString, INTEGER nCount, INTEGER nIDListBox);
#define WinAPI_DlgDirSelectExA(hDlg, lpString, nCount, nIDListBox)	DlgDirSelectExA(hDlg, lpString, nCount, nIDListBox)
__EXTERN INTEGER __STDCALL DlgDirSelectExW(LONGINT hDlg, LONGINT lpString, INTEGER nCount, INTEGER nIDListBox);
#define WinAPI_DlgDirSelectExW(hDlg, lpString, nCount, nIDListBox)	DlgDirSelectExW(hDlg, lpString, nCount, nIDListBox)
#define WinAPI_DoEnvironmentSubst(szString, cbString)	DoEnvironmentSubstA(szString, cbString)
__EXTERN INTEGER __STDCALL DoEnvironmentSubstA(LONGINT szString, INTEGER cbString);
#define WinAPI_DoEnvironmentSubstA(szString, cbString)	DoEnvironmentSubstA(szString, cbString)
__EXTERN INTEGER __STDCALL DoEnvironmentSubstW(LONGINT szString, INTEGER cbString);
#define WinAPI_DoEnvironmentSubstW(szString, cbString)	DoEnvironmentSubstW(szString, cbString)
#define WinAPI_DocumentProperties(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)	DocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)
__EXTERN INTEGER __STDCALL DocumentPropertiesA(LONGINT hWnd, LONGINT hPrinter, LONGINT pDeviceName, WinAPI_DEVMODEA *pDevModeOutput, WinAPI_DEVMODEA *pDevModeInput, SET fMode);
#define WinAPI_DocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)	DocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)
__EXTERN INTEGER __STDCALL DocumentPropertiesW(LONGINT hWnd, LONGINT hPrinter, LONGINT pDeviceName, WinAPI_DEVMODEW *pDevModeOutput, WinAPI_DEVMODEW *pDevModeInput, SET fMode);
#define WinAPI_DocumentPropertiesW(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)	DocumentPropertiesW(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)
__EXTERN INTEGER __STDCALL DosDateTimeToFileTime(SHORTINT wFatDate, SHORTINT wFatTime, WinAPI_FILETIME *lpFileTime);
#define WinAPI_DosDateTimeToFileTime(wFatDate, wFatTime, lpFileTime)	DosDateTimeToFileTime(wFatDate, wFatTime, lpFileTime)
__EXTERN void __STDCALL DragAcceptFiles(LONGINT p0, INTEGER p1);
#define WinAPI_DragAcceptFiles(p0, p1)	DragAcceptFiles(p0, p1)
__EXTERN INTEGER __STDCALL DragDetect(LONGINT p0, WinAPI_POINT *p1);
#define WinAPI_DragDetect(p0, p1)	DragDetect(p0, p1)
__EXTERN void __STDCALL DragFinish(LONGINT p0);
#define WinAPI_DragFinish(p0)	DragFinish(p0)
__EXTERN INTEGER __STDCALL DragObject(LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, LONGINT p4);
#define WinAPI_DragObject(p0, p1, p2, p3, p4)	DragObject(p0, p1, p2, p3, p4)
#define WinAPI_DragQueryFile(p0, p1, p2, p3)	DragQueryFileA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL DragQueryFileA(LONGINT p0, INTEGER p1, LONGINT p2, INTEGER p3);
#define WinAPI_DragQueryFileA(p0, p1, p2, p3)	DragQueryFileA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL DragQueryFileW(LONGINT p0, INTEGER p1, LONGINT p2, INTEGER p3);
#define WinAPI_DragQueryFileW(p0, p1, p2, p3)	DragQueryFileW(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL DragQueryPoint(LONGINT p0, WinAPI_POINT *p1);
#define WinAPI_DragQueryPoint(p0, p1)	DragQueryPoint(p0, p1)
__EXTERN INTEGER __STDCALL DrawAnimatedRects(LONGINT hwnd, INTEGER idAni, WinAPI_RECT *lprcFrom, WinAPI_RECT *lprcTo);
#define WinAPI_DrawAnimatedRects(hwnd, idAni, lprcFrom, lprcTo)	DrawAnimatedRects(hwnd, idAni, lprcFrom, lprcTo)
__EXTERN INTEGER __STDCALL DrawCaption(LONGINT p0, LONGINT p1, WinAPI_RECT *p2, INTEGER p3);
#define WinAPI_DrawCaption(p0, p1, p2, p3)	DrawCaption(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL DrawEdge(LONGINT hdc, WinAPI_RECT *qrc, SET edge, SET grfFlags);
#define WinAPI_DrawEdge(hdc, qrc, edge, grfFlags)	DrawEdge(hdc, qrc, edge, grfFlags)
__EXTERN INTEGER __STDCALL DrawEscape(LONGINT p0, INTEGER p1, INTEGER p2, LONGINT p3);
#define WinAPI_DrawEscape(p0, p1, p2, p3)	DrawEscape(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL DrawFocusRect(LONGINT hDC, WinAPI_RECT *lprc);
#define WinAPI_DrawFocusRect(hDC, lprc)	DrawFocusRect(hDC, lprc)
__EXTERN INTEGER __STDCALL DrawFrameControl(LONGINT p0, WinAPI_RECT *p1, INTEGER p2, SET p3);
#define WinAPI_DrawFrameControl(p0, p1, p2, p3)	DrawFrameControl(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL DrawIcon(LONGINT hDC, INTEGER X, INTEGER Y, LONGINT hIcon);
#define WinAPI_DrawIcon(hDC, X, Y, hIcon)	DrawIcon(hDC, X, Y, hIcon)
__EXTERN INTEGER __STDCALL DrawIconEx(LONGINT hdc, INTEGER xLeft, INTEGER yTop, LONGINT hIcon, INTEGER cxWidth, INTEGER cyWidth, INTEGER istepIfAniCur, LONGINT hbrFlickerFreeDraw, SET diFlags);
#define WinAPI_DrawIconEx(hdc, xLeft, yTop, hIcon, cxWidth, cyWidth, istepIfAniCur, hbrFlickerFreeDraw, diFlags)	DrawIconEx(hdc, xLeft, yTop, hIcon, cxWidth, cyWidth, istepIfAniCur, hbrFlickerFreeDraw, diFlags)
__EXTERN INTEGER __STDCALL DrawMenuBar(LONGINT hWnd);
#define WinAPI_DrawMenuBar(hWnd)	DrawMenuBar(hWnd)
#define WinAPI_DrawState(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)	DrawStateA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)
__EXTERN INTEGER __STDCALL DrawStateA(LONGINT p0, LONGINT p1, WinAPI_DRAWSTATEPROC p2, LONGINT p3, LONGINT p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, SET p9);
#define WinAPI_DrawStateA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)	DrawStateA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)
__EXTERN INTEGER __STDCALL DrawStateW(LONGINT p0, LONGINT p1, WinAPI_DRAWSTATEPROC p2, LONGINT p3, LONGINT p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, SET p9);
#define WinAPI_DrawStateW(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)	DrawStateW(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)
#define WinAPI_DrawText(hDC, lpString, nCount, lpRect, uFormat)	DrawTextA(hDC, lpString, nCount, lpRect, uFormat)
__EXTERN INTEGER __STDCALL DrawTextA(LONGINT hDC, LONGINT lpString, INTEGER nCount, WinAPI_RECT *lpRect, SET uFormat);
#define WinAPI_DrawTextA(hDC, lpString, nCount, lpRect, uFormat)	DrawTextA(hDC, lpString, nCount, lpRect, uFormat)
#define WinAPI_DrawTextEx(p0, p1, p2, p3, p4, p5)	DrawTextExA(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __STDCALL DrawTextExA(LONGINT p0, LONGINT p1, INTEGER p2, WinAPI_RECT *p3, INTEGER p4, WinAPI_DRAWTEXTPARAMS *p5);
#define WinAPI_DrawTextExA(p0, p1, p2, p3, p4, p5)	DrawTextExA(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __STDCALL DrawTextExW(LONGINT p0, LONGINT p1, INTEGER p2, WinAPI_RECT *p3, INTEGER p4, WinAPI_DRAWTEXTPARAMS *p5);
#define WinAPI_DrawTextExW(p0, p1, p2, p3, p4, p5)	DrawTextExW(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __STDCALL DrawTextW(LONGINT hDC, LONGINT lpString, INTEGER nCount, WinAPI_RECT *lpRect, SET uFormat);
#define WinAPI_DrawTextW(hDC, lpString, nCount, lpRect, uFormat)	DrawTextW(hDC, lpString, nCount, lpRect, uFormat)
__EXTERN INTEGER __STDCALL DuplicateHandle(LONGINT hSourceProcessHandle, LONGINT hSourceHandle, LONGINT hTargetProcessHandle, LONGINT *lpTargetHandle, SET dwDesiredAccess, INTEGER bInheritHandle, SET dwOptions);
#define WinAPI_DuplicateHandle(hSourceProcessHandle, hSourceHandle, hTargetProcessHandle, lpTargetHandle, dwDesiredAccess, bInheritHandle, dwOptions)	DuplicateHandle(hSourceProcessHandle, hSourceHandle, hTargetProcessHandle, lpTargetHandle, dwDesiredAccess, bInheritHandle, dwOptions)
__EXTERN LONGINT __STDCALL DuplicateIcon(LONGINT hInst, LONGINT hIcon);
#define WinAPI_DuplicateIcon(hInst, hIcon)	DuplicateIcon(hInst, hIcon)
__EXTERN INTEGER __STDCALL DuplicateToken(LONGINT ExistingTokenHandle, INTEGER ImpersonationLevel, LONGINT *DuplicateTokenHandle);
#define WinAPI_DuplicateToken(ExistingTokenHandle, ImpersonationLevel, DuplicateTokenHandle)	DuplicateToken(ExistingTokenHandle, ImpersonationLevel, DuplicateTokenHandle)
__EXTERN INTEGER __STDCALL Ellipse(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_Ellipse(p0, p1, p2, p3, p4)	Ellipse(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL EmptyClipboard(void);
#define WinAPI_EmptyClipboard()	EmptyClipboard()
__EXTERN INTEGER __STDCALL EnableMenuItem(LONGINT hMenu, INTEGER uIDEnableItem, SET uEnable);
#define WinAPI_EnableMenuItem(hMenu, uIDEnableItem, uEnable)	EnableMenuItem(hMenu, uIDEnableItem, uEnable)
__EXTERN INTEGER __STDCALL EnableScrollBar(LONGINT hWnd, INTEGER wSBflags, INTEGER wArrows);
#define WinAPI_EnableScrollBar(hWnd, wSBflags, wArrows)	EnableScrollBar(hWnd, wSBflags, wArrows)
__EXTERN INTEGER __STDCALL EnableWindow(LONGINT hWnd, INTEGER bEnable);
#define WinAPI_EnableWindow(hWnd, bEnable)	EnableWindow(hWnd, bEnable)
__EXTERN INTEGER __STDCALL EndDeferWindowPos(LONGINT hWinPosInfo);
#define WinAPI_EndDeferWindowPos(hWinPosInfo)	EndDeferWindowPos(hWinPosInfo)
__EXTERN INTEGER __STDCALL EndDialog(LONGINT hDlg, INTEGER nResult);
#define WinAPI_EndDialog(hDlg, nResult)	EndDialog(hDlg, nResult)
__EXTERN INTEGER __STDCALL EndDoc(LONGINT p0);
#define WinAPI_EndDoc(p0)	EndDoc(p0)
__EXTERN INTEGER __STDCALL EndDocPrinter(LONGINT hPrinter);
#define WinAPI_EndDocPrinter(hPrinter)	EndDocPrinter(hPrinter)
__EXTERN INTEGER __STDCALL EndPage(LONGINT p0);
#define WinAPI_EndPage(p0)	EndPage(p0)
__EXTERN INTEGER __STDCALL EndPagePrinter(LONGINT hPrinter);
#define WinAPI_EndPagePrinter(hPrinter)	EndPagePrinter(hPrinter)
__EXTERN INTEGER __STDCALL EndPaint(LONGINT hWnd, WinAPI_PAINTSTRUCT *lpPaint);
#define WinAPI_EndPaint(hWnd, lpPaint)	EndPaint(hWnd, lpPaint)
__EXTERN INTEGER __STDCALL EndPath(LONGINT p0);
#define WinAPI_EndPath(p0)	EndPath(p0)
#define WinAPI_EndUpdateResource(hUpdate, fDiscard)	EndUpdateResourceA(hUpdate, fDiscard)
__EXTERN INTEGER __STDCALL EndUpdateResourceA(LONGINT hUpdate, INTEGER fDiscard);
#define WinAPI_EndUpdateResourceA(hUpdate, fDiscard)	EndUpdateResourceA(hUpdate, fDiscard)
__EXTERN INTEGER __STDCALL EndUpdateResourceW(LONGINT hUpdate, INTEGER fDiscard);
#define WinAPI_EndUpdateResourceW(hUpdate, fDiscard)	EndUpdateResourceW(hUpdate, fDiscard)
__EXTERN void __STDCALL EnterCriticalSection(WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinAPI_EnterCriticalSection(lpCriticalSection)	EnterCriticalSection(lpCriticalSection)
#define WinAPI_EnumCalendarInfo(lpCalInfoEnumProc, Locale, Calendar, CalType)	EnumCalendarInfoA(lpCalInfoEnumProc, Locale, Calendar, CalType)
__EXTERN INTEGER __STDCALL EnumCalendarInfoA(WinAPI_CALINFO_ENUMPROCA lpCalInfoEnumProc, INTEGER Locale, INTEGER Calendar, INTEGER CalType);
#define WinAPI_EnumCalendarInfoA(lpCalInfoEnumProc, Locale, Calendar, CalType)	EnumCalendarInfoA(lpCalInfoEnumProc, Locale, Calendar, CalType)
__EXTERN INTEGER __STDCALL EnumCalendarInfoW(WinAPI_CALINFO_ENUMPROCW lpCalInfoEnumProc, INTEGER Locale, INTEGER Calendar, INTEGER CalType);
#define WinAPI_EnumCalendarInfoW(lpCalInfoEnumProc, Locale, Calendar, CalType)	EnumCalendarInfoW(lpCalInfoEnumProc, Locale, Calendar, CalType)
__EXTERN INTEGER __STDCALL EnumChildWindows(LONGINT hWndParent, WinAPI_WNDENUMPROC lpEnumFunc, LONGINT lParam);
#define WinAPI_EnumChildWindows(hWndParent, lpEnumFunc, lParam)	EnumChildWindows(hWndParent, lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumClipboardFormats(INTEGER format);
#define WinAPI_EnumClipboardFormats(format)	EnumClipboardFormats(format)
#define WinAPI_EnumDateFormats(lpDateFmtEnumProc, Locale, dwFlags)	EnumDateFormatsA(lpDateFmtEnumProc, Locale, dwFlags)
__EXTERN INTEGER __STDCALL EnumDateFormatsA(WinAPI_DATEFMT_ENUMPROCA lpDateFmtEnumProc, INTEGER Locale, SET dwFlags);
#define WinAPI_EnumDateFormatsA(lpDateFmtEnumProc, Locale, dwFlags)	EnumDateFormatsA(lpDateFmtEnumProc, Locale, dwFlags)
__EXTERN INTEGER __STDCALL EnumDateFormatsW(WinAPI_DATEFMT_ENUMPROCW lpDateFmtEnumProc, INTEGER Locale, SET dwFlags);
#define WinAPI_EnumDateFormatsW(lpDateFmtEnumProc, Locale, dwFlags)	EnumDateFormatsW(lpDateFmtEnumProc, Locale, dwFlags)
#define WinAPI_EnumDependentServices(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)	EnumDependentServicesA(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)
__EXTERN INTEGER __STDCALL EnumDependentServicesA(LONGINT hService, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSA *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned);
#define WinAPI_EnumDependentServicesA(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)	EnumDependentServicesA(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)
__EXTERN INTEGER __STDCALL EnumDependentServicesW(LONGINT hService, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSW *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned);
#define WinAPI_EnumDependentServicesW(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)	EnumDependentServicesW(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)
__EXTERN INTEGER __STDCALL EnumDesktopWindows(LONGINT hDesktop, WinAPI_WNDENUMPROC lpfn, LONGINT lParam);
#define WinAPI_EnumDesktopWindows(hDesktop, lpfn, lParam)	EnumDesktopWindows(hDesktop, lpfn, lParam)
#define WinAPI_EnumDesktops(hwinsta, lpEnumFunc, lParam)	EnumDesktopsA(hwinsta, lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumDesktopsA(LONGINT hwinsta, WinAPI_DESKTOPENUMPROCA lpEnumFunc, LONGINT lParam);
#define WinAPI_EnumDesktopsA(hwinsta, lpEnumFunc, lParam)	EnumDesktopsA(hwinsta, lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumDesktopsW(LONGINT hwinsta, WinAPI_DESKTOPENUMPROCW lpEnumFunc, LONGINT lParam);
#define WinAPI_EnumDesktopsW(hwinsta, lpEnumFunc, lParam)	EnumDesktopsW(hwinsta, lpEnumFunc, lParam)
#define WinAPI_EnumDisplaySettings(lpszDeviceName, iModeNum, lpDevMode)	EnumDisplaySettingsA(lpszDeviceName, iModeNum, lpDevMode)
__EXTERN INTEGER __STDCALL EnumDisplaySettingsA(LONGINT lpszDeviceName, INTEGER iModeNum, WinAPI_DEVMODEA *lpDevMode);
#define WinAPI_EnumDisplaySettingsA(lpszDeviceName, iModeNum, lpDevMode)	EnumDisplaySettingsA(lpszDeviceName, iModeNum, lpDevMode)
__EXTERN INTEGER __STDCALL EnumDisplaySettingsW(LONGINT lpszDeviceName, INTEGER iModeNum, WinAPI_DEVMODEW *lpDevMode);
#define WinAPI_EnumDisplaySettingsW(lpszDeviceName, iModeNum, lpDevMode)	EnumDisplaySettingsW(lpszDeviceName, iModeNum, lpDevMode)
__EXTERN INTEGER __STDCALL EnumEnhMetaFile(LONGINT p0, LONGINT p1, WinAPI_ENHMFENUMPROC p2, LONGINT p3, WinAPI_RECT *p4);
#define WinAPI_EnumEnhMetaFile(p0, p1, p2, p3, p4)	EnumEnhMetaFile(p0, p1, p2, p3, p4)
#define WinAPI_EnumFontFamilies(p0, p1, p2, p3)	EnumFontFamiliesA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL EnumFontFamiliesA(LONGINT p0, LONGINT p1, WinAPI_NEWFONTENUMPROCA p2, LONGINT p3);
#define WinAPI_EnumFontFamiliesA(p0, p1, p2, p3)	EnumFontFamiliesA(p0, p1, p2, p3)
#define WinAPI_EnumFontFamiliesEx(p0, p1, p2, p3, p4)	EnumFontFamiliesExA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL EnumFontFamiliesExA(LONGINT p0, WinAPI_LOGFONTA *p1, WinAPI_FONTENUMPROCEXA p2, LONGINT p3, INTEGER p4);
#define WinAPI_EnumFontFamiliesExA(p0, p1, p2, p3, p4)	EnumFontFamiliesExA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL EnumFontFamiliesExW(LONGINT p0, WinAPI_LOGFONTW *p1, WinAPI_FONTENUMPROCEXW p2, LONGINT p3, INTEGER p4);
#define WinAPI_EnumFontFamiliesExW(p0, p1, p2, p3, p4)	EnumFontFamiliesExW(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL EnumFontFamiliesW(LONGINT p0, LONGINT p1, WinAPI_NEWFONTENUMPROCW p2, LONGINT p3);
#define WinAPI_EnumFontFamiliesW(p0, p1, p2, p3)	EnumFontFamiliesW(p0, p1, p2, p3)
#define WinAPI_EnumFonts(p0, p1, p2, p3)	EnumFontsA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL EnumFontsA(LONGINT p0, LONGINT p1, WinAPI_FONTENUMPROCA p2, LONGINT p3);
#define WinAPI_EnumFontsA(p0, p1, p2, p3)	EnumFontsA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL EnumFontsW(LONGINT p0, LONGINT p1, WinAPI_FONTENUMPROCW p2, LONGINT p3);
#define WinAPI_EnumFontsW(p0, p1, p2, p3)	EnumFontsW(p0, p1, p2, p3)
#define WinAPI_EnumForms(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)	EnumFormsA(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumFormsA(LONGINT hPrinter, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumFormsA(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)	EnumFormsA(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumFormsW(LONGINT hPrinter, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumFormsW(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)	EnumFormsW(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumICMProfiles(p0, p1, p2)	EnumICMProfilesA(p0, p1, p2)
__EXTERN INTEGER __STDCALL EnumICMProfilesA(LONGINT p0, WinAPI_ICMENUMPROCA p1, LONGINT p2);
#define WinAPI_EnumICMProfilesA(p0, p1, p2)	EnumICMProfilesA(p0, p1, p2)
__EXTERN INTEGER __STDCALL EnumICMProfilesW(LONGINT p0, WinAPI_ICMENUMPROCW p1, LONGINT p2);
#define WinAPI_EnumICMProfilesW(p0, p1, p2)	EnumICMProfilesW(p0, p1, p2)
#define WinAPI_EnumJobs(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)	EnumJobsA(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumJobsA(LONGINT hPrinter, INTEGER FirstJob, INTEGER NoJobs, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumJobsA(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)	EnumJobsA(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumJobsW(LONGINT hPrinter, INTEGER FirstJob, INTEGER NoJobs, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumJobsW(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)	EnumJobsW(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumMetaFile(LONGINT p0, LONGINT p1, WinAPI_MFENUMPROC p2, LONGINT p3);
#define WinAPI_EnumMetaFile(p0, p1, p2, p3)	EnumMetaFile(p0, p1, p2, p3)
#define WinAPI_EnumMonitors(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)	EnumMonitorsA(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumMonitorsA(LONGINT pName, INTEGER Level, CHAR *pMonitors, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumMonitorsA(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)	EnumMonitorsA(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumMonitorsW(LONGINT pName, INTEGER Level, CHAR *pMonitors, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumMonitorsW(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)	EnumMonitorsW(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumObjects(LONGINT p0, INTEGER p1, WinAPI_GOBJENUMPROC p2, LONGINT p3);
#define WinAPI_EnumObjects(p0, p1, p2, p3)	EnumObjects(p0, p1, p2, p3)
#define WinAPI_EnumPorts(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)	EnumPortsA(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumPortsA(LONGINT pName, INTEGER Level, CHAR *pPorts, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPortsA(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)	EnumPortsA(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumPortsW(LONGINT pName, INTEGER Level, CHAR *pPorts, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPortsW(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)	EnumPortsW(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPrintProcessorDatatypes(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorDatatypesA(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumPrintProcessorDatatypesA(LONGINT pName, LONGINT pPrintProcessorName, INTEGER Level, CHAR *pDatatypes, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrintProcessorDatatypesA(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorDatatypesA(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumPrintProcessorDatatypesW(LONGINT pName, LONGINT pPrintProcessorName, INTEGER Level, CHAR *pDatatypes, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrintProcessorDatatypesW(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorDatatypesW(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPrintProcessors(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorsA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumPrintProcessorsA(LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrintProcessorsA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorsA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumPrintProcessorsW(LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrintProcessorsW(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorsW(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPrinterDrivers(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrinterDriversA(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumPrinterDriversA(LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrinterDriversA(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrinterDriversA(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumPrinterDriversW(LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrinterDriversW(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrinterDriversW(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPrinters(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)	EnumPrintersA(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumPrintersA(SET Flags, LONGINT Name, INTEGER Level, CHAR *pPrinterEnum, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrintersA(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)	EnumPrintersA(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __STDCALL EnumPrintersW(SET Flags, LONGINT Name, INTEGER Level, CHAR *pPrinterEnum, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrintersW(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)	EnumPrintersW(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumProps(hWnd, lpEnumFunc)	EnumPropsA(hWnd, lpEnumFunc)
__EXTERN INTEGER __STDCALL EnumPropsA(LONGINT hWnd, WinAPI_ROPENUMPROCA lpEnumFunc);
#define WinAPI_EnumPropsA(hWnd, lpEnumFunc)	EnumPropsA(hWnd, lpEnumFunc)
#define WinAPI_EnumPropsEx(hWnd, lpEnumFunc, lParam)	EnumPropsExA(hWnd, lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumPropsExA(LONGINT hWnd, WinAPI_ROPENUMPROCEXA lpEnumFunc, LONGINT lParam);
#define WinAPI_EnumPropsExA(hWnd, lpEnumFunc, lParam)	EnumPropsExA(hWnd, lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumPropsExW(LONGINT hWnd, WinAPI_ROPENUMPROCEXW lpEnumFunc, LONGINT lParam);
#define WinAPI_EnumPropsExW(hWnd, lpEnumFunc, lParam)	EnumPropsExW(hWnd, lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumPropsW(LONGINT hWnd, WinAPI_ROPENUMPROCW lpEnumFunc);
#define WinAPI_EnumPropsW(hWnd, lpEnumFunc)	EnumPropsW(hWnd, lpEnumFunc)
#define WinAPI_EnumResourceLanguages(hModule, lpType, lpName, lpEnumFunc, lParam)	EnumResourceLanguagesA(hModule, lpType, lpName, lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumResourceLanguagesA(LONGINT hModule, LONGINT lpType, LONGINT lpName, WinAPI_ENUMRESLANGPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumResourceLanguagesA(hModule, lpType, lpName, lpEnumFunc, lParam)	EnumResourceLanguagesA(hModule, lpType, lpName, lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumResourceLanguagesW(LONGINT hModule, LONGINT lpType, LONGINT lpName, WinAPI_ENUMRESLANGPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumResourceLanguagesW(hModule, lpType, lpName, lpEnumFunc, lParam)	EnumResourceLanguagesW(hModule, lpType, lpName, lpEnumFunc, lParam)
#define WinAPI_EnumResourceNames(hModule, lpType, lpEnumFunc, lParam)	EnumResourceNamesA(hModule, lpType, lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumResourceNamesA(LONGINT hModule, LONGINT lpType, WinAPI_ENUMRESNAMEPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumResourceNamesA(hModule, lpType, lpEnumFunc, lParam)	EnumResourceNamesA(hModule, lpType, lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumResourceNamesW(LONGINT hModule, LONGINT lpType, WinAPI_ENUMRESNAMEPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumResourceNamesW(hModule, lpType, lpEnumFunc, lParam)	EnumResourceNamesW(hModule, lpType, lpEnumFunc, lParam)
#define WinAPI_EnumResourceTypes(hModule, lpEnumFunc, lParam)	EnumResourceTypesA(hModule, lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumResourceTypesA(LONGINT hModule, WinAPI_ENUMRESTYPEPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumResourceTypesA(hModule, lpEnumFunc, lParam)	EnumResourceTypesA(hModule, lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumResourceTypesW(LONGINT hModule, WinAPI_ENUMRESTYPEPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumResourceTypesW(hModule, lpEnumFunc, lParam)	EnumResourceTypesW(hModule, lpEnumFunc, lParam)
#define WinAPI_EnumServicesStatus(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)	EnumServicesStatusA(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)
__EXTERN INTEGER __STDCALL EnumServicesStatusA(LONGINT hSCManager, SET dwServiceType, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSA *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned, INTEGER *lpResumeHandle);
#define WinAPI_EnumServicesStatusA(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)	EnumServicesStatusA(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)
__EXTERN INTEGER __STDCALL EnumServicesStatusW(LONGINT hSCManager, SET dwServiceType, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSW *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned, INTEGER *lpResumeHandle);
#define WinAPI_EnumServicesStatusW(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)	EnumServicesStatusW(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)
#define WinAPI_EnumSystemCodePages(lpCodePageEnumProc, dwFlags)	EnumSystemCodePagesA(lpCodePageEnumProc, dwFlags)
__EXTERN INTEGER __STDCALL EnumSystemCodePagesA(WinAPI_CODEPAGE_ENUMPROCA lpCodePageEnumProc, SET dwFlags);
#define WinAPI_EnumSystemCodePagesA(lpCodePageEnumProc, dwFlags)	EnumSystemCodePagesA(lpCodePageEnumProc, dwFlags)
__EXTERN INTEGER __STDCALL EnumSystemCodePagesW(WinAPI_CODEPAGE_ENUMPROCW lpCodePageEnumProc, SET dwFlags);
#define WinAPI_EnumSystemCodePagesW(lpCodePageEnumProc, dwFlags)	EnumSystemCodePagesW(lpCodePageEnumProc, dwFlags)
#define WinAPI_EnumSystemLocales(lpLocaleEnumProc, dwFlags)	EnumSystemLocalesA(lpLocaleEnumProc, dwFlags)
__EXTERN INTEGER __STDCALL EnumSystemLocalesA(WinAPI_LOCALE_ENUMPROCA lpLocaleEnumProc, SET dwFlags);
#define WinAPI_EnumSystemLocalesA(lpLocaleEnumProc, dwFlags)	EnumSystemLocalesA(lpLocaleEnumProc, dwFlags)
__EXTERN INTEGER __STDCALL EnumSystemLocalesW(WinAPI_LOCALE_ENUMPROCW lpLocaleEnumProc, SET dwFlags);
#define WinAPI_EnumSystemLocalesW(lpLocaleEnumProc, dwFlags)	EnumSystemLocalesW(lpLocaleEnumProc, dwFlags)
__EXTERN INTEGER __STDCALL EnumThreadWindows(INTEGER dwThreadId, WinAPI_WNDENUMPROC lpfn, LONGINT lParam);
#define WinAPI_EnumThreadWindows(dwThreadId, lpfn, lParam)	EnumThreadWindows(dwThreadId, lpfn, lParam)
#define WinAPI_EnumTimeFormats(lpTimeFmtEnumProc, Locale, dwFlags)	EnumTimeFormatsA(lpTimeFmtEnumProc, Locale, dwFlags)
__EXTERN INTEGER __STDCALL EnumTimeFormatsA(WinAPI_TIMEFMT_ENUMPROCA lpTimeFmtEnumProc, INTEGER Locale, SET dwFlags);
#define WinAPI_EnumTimeFormatsA(lpTimeFmtEnumProc, Locale, dwFlags)	EnumTimeFormatsA(lpTimeFmtEnumProc, Locale, dwFlags)
__EXTERN INTEGER __STDCALL EnumTimeFormatsW(WinAPI_TIMEFMT_ENUMPROCW lpTimeFmtEnumProc, INTEGER Locale, SET dwFlags);
#define WinAPI_EnumTimeFormatsW(lpTimeFmtEnumProc, Locale, dwFlags)	EnumTimeFormatsW(lpTimeFmtEnumProc, Locale, dwFlags)
#define WinAPI_EnumWindowStations(lpEnumFunc, lParam)	EnumWindowStationsA(lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumWindowStationsA(WinAPI_WINSTAENUMPROCA lpEnumFunc, LONGINT lParam);
#define WinAPI_EnumWindowStationsA(lpEnumFunc, lParam)	EnumWindowStationsA(lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumWindowStationsW(WinAPI_WINSTAENUMPROCW lpEnumFunc, LONGINT lParam);
#define WinAPI_EnumWindowStationsW(lpEnumFunc, lParam)	EnumWindowStationsW(lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EnumWindows(WinAPI_WNDENUMPROC lpEnumFunc, LONGINT lParam);
#define WinAPI_EnumWindows(lpEnumFunc, lParam)	EnumWindows(lpEnumFunc, lParam)
__EXTERN INTEGER __STDCALL EqualPrefixSid(LONGINT pSid1, LONGINT pSid2);
#define WinAPI_EqualPrefixSid(pSid1, pSid2)	EqualPrefixSid(pSid1, pSid2)
__EXTERN INTEGER __STDCALL EqualRect(WinAPI_RECT *lprc1, WinAPI_RECT *lprc2);
#define WinAPI_EqualRect(lprc1, lprc2)	EqualRect(lprc1, lprc2)
__EXTERN INTEGER __STDCALL EqualRgn(LONGINT p0, LONGINT p1);
#define WinAPI_EqualRgn(p0, p1)	EqualRgn(p0, p1)
__EXTERN INTEGER __STDCALL EqualSid(LONGINT pSid1, LONGINT pSid2);
#define WinAPI_EqualSid(pSid1, pSid2)	EqualSid(pSid1, pSid2)
__EXTERN INTEGER __STDCALL EraseTape(LONGINT hDevice, INTEGER dwEraseType, INTEGER bImmediate);
#define WinAPI_EraseTape(hDevice, dwEraseType, bImmediate)	EraseTape(hDevice, dwEraseType, bImmediate)
__EXTERN INTEGER __STDCALL Escape(LONGINT p0, INTEGER p1, INTEGER p2, LONGINT p3, LONGINT p4);
#define WinAPI_Escape(p0, p1, p2, p3, p4)	Escape(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL EscapeCommFunction(LONGINT hFile, INTEGER dwFunc);
#define WinAPI_EscapeCommFunction(hFile, dwFunc)	EscapeCommFunction(hFile, dwFunc)
__EXTERN INTEGER __STDCALL ExcludeClipRect(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_ExcludeClipRect(p0, p1, p2, p3, p4)	ExcludeClipRect(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL ExcludeUpdateRgn(LONGINT hDC, LONGINT hWnd);
#define WinAPI_ExcludeUpdateRgn(hDC, hWnd)	ExcludeUpdateRgn(hDC, hWnd)
__EXTERN void __STDCALL ExitProcess(INTEGER uExitCode);
#define WinAPI_ExitProcess(uExitCode)	ExitProcess(uExitCode)
__EXTERN void __STDCALL ExitThread(INTEGER dwExitCode);
#define WinAPI_ExitThread(dwExitCode)	ExitThread(dwExitCode)
__EXTERN INTEGER __STDCALL ExitWindowsEx(SET uFlags, INTEGER dwReserved);
#define WinAPI_ExitWindowsEx(uFlags, dwReserved)	ExitWindowsEx(uFlags, dwReserved)
#define WinAPI_ExpandEnvironmentStrings(lpSrc, lpDst, nSize)	ExpandEnvironmentStringsA(lpSrc, lpDst, nSize)
__EXTERN INTEGER __STDCALL ExpandEnvironmentStringsA(LONGINT lpSrc, LONGINT lpDst, INTEGER nSize);
#define WinAPI_ExpandEnvironmentStringsA(lpSrc, lpDst, nSize)	ExpandEnvironmentStringsA(lpSrc, lpDst, nSize)
__EXTERN INTEGER __STDCALL ExpandEnvironmentStringsW(LONGINT lpSrc, LONGINT lpDst, INTEGER nSize);
#define WinAPI_ExpandEnvironmentStringsW(lpSrc, lpDst, nSize)	ExpandEnvironmentStringsW(lpSrc, lpDst, nSize)
__EXTERN LONGINT __STDCALL ExtCreatePen(INTEGER p0, INTEGER p1, WinAPI_LOGBRUSH *p2, INTEGER p3, INTEGER *p4);
#define WinAPI_ExtCreatePen(p0, p1, p2, p3, p4)	ExtCreatePen(p0, p1, p2, p3, p4)
__EXTERN LONGINT __STDCALL ExtCreateRegion(WinAPI_XFORM *p0, INTEGER p1, WinAPI_RGNDATA *p2);
#define WinAPI_ExtCreateRegion(p0, p1, p2)	ExtCreateRegion(p0, p1, p2)
__EXTERN INTEGER __STDCALL ExtEscape(LONGINT p0, INTEGER p1, INTEGER p2, LONGINT p3, INTEGER p4, LONGINT p5);
#define WinAPI_ExtEscape(p0, p1, p2, p3, p4, p5)	ExtEscape(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __STDCALL ExtFloodFill(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_ExtFloodFill(p0, p1, p2, p3, p4)	ExtFloodFill(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL ExtSelectClipRgn(LONGINT p0, LONGINT p1, INTEGER p2);
#define WinAPI_ExtSelectClipRgn(p0, p1, p2)	ExtSelectClipRgn(p0, p1, p2)
#define WinAPI_ExtTextOut(p0, p1, p2, p3, p4, p5, p6, p7)	ExtTextOutA(p0, p1, p2, p3, p4, p5, p6, p7)
__EXTERN INTEGER __STDCALL ExtTextOutA(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_RECT *p4, LONGINT p5, INTEGER p6, INTEGER *p7);
#define WinAPI_ExtTextOutA(p0, p1, p2, p3, p4, p5, p6, p7)	ExtTextOutA(p0, p1, p2, p3, p4, p5, p6, p7)
__EXTERN INTEGER __STDCALL ExtTextOutW(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_RECT *p4, LONGINT p5, INTEGER p6, INTEGER *p7);
#define WinAPI_ExtTextOutW(p0, p1, p2, p3, p4, p5, p6, p7)	ExtTextOutW(p0, p1, p2, p3, p4, p5, p6, p7)
#define WinAPI_ExtractAssociatedIcon(hInst, lpIconPath, lpiIcon)	ExtractAssociatedIconA(hInst, lpIconPath, lpiIcon)
__EXTERN LONGINT __STDCALL ExtractAssociatedIconA(LONGINT hInst, LONGINT lpIconPath, SHORTINT *lpiIcon);
#define WinAPI_ExtractAssociatedIconA(hInst, lpIconPath, lpiIcon)	ExtractAssociatedIconA(hInst, lpIconPath, lpiIcon)
__EXTERN LONGINT __STDCALL ExtractAssociatedIconW(LONGINT hInst, LONGINT lpIconPath, SHORTINT *lpiIcon);
#define WinAPI_ExtractAssociatedIconW(hInst, lpIconPath, lpiIcon)	ExtractAssociatedIconW(hInst, lpIconPath, lpiIcon)
#define WinAPI_ExtractIcon(hInst, lpszExeFileName, nIconIndex)	ExtractIconA(hInst, lpszExeFileName, nIconIndex)
__EXTERN LONGINT __STDCALL ExtractIconA(LONGINT hInst, LONGINT lpszExeFileName, INTEGER nIconIndex);
#define WinAPI_ExtractIconA(hInst, lpszExeFileName, nIconIndex)	ExtractIconA(hInst, lpszExeFileName, nIconIndex)
#define WinAPI_ExtractIconEx(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)	ExtractIconExA(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)
__EXTERN INTEGER __STDCALL ExtractIconExA(LONGINT lpszFile, INTEGER nIconIndex, LONGINT *phiconLarge, LONGINT *phiconSmall, INTEGER nIcons);
#define WinAPI_ExtractIconExA(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)	ExtractIconExA(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)
__EXTERN INTEGER __STDCALL ExtractIconExW(LONGINT lpszFile, INTEGER nIconIndex, LONGINT *phiconLarge, LONGINT *phiconSmall, INTEGER nIcons);
#define WinAPI_ExtractIconExW(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)	ExtractIconExW(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)
__EXTERN LONGINT __STDCALL ExtractIconW(LONGINT hInst, LONGINT lpszExeFileName, INTEGER nIconIndex);
#define WinAPI_ExtractIconW(hInst, lpszExeFileName, nIconIndex)	ExtractIconW(hInst, lpszExeFileName, nIconIndex)
#define WinAPI_FatalAppExit(uAction, lpMessageText)	FatalAppExitA(uAction, lpMessageText)
__EXTERN void __STDCALL FatalAppExitA(INTEGER uAction, LONGINT lpMessageText);
#define WinAPI_FatalAppExitA(uAction, lpMessageText)	FatalAppExitA(uAction, lpMessageText)
__EXTERN void __STDCALL FatalAppExitW(INTEGER uAction, LONGINT lpMessageText);
#define WinAPI_FatalAppExitW(uAction, lpMessageText)	FatalAppExitW(uAction, lpMessageText)
__EXTERN void __STDCALL FatalExit(INTEGER ExitCode);
#define WinAPI_FatalExit(ExitCode)	FatalExit(ExitCode)
__EXTERN INTEGER __STDCALL FileTimeToDosDateTime(WinAPI_FILETIME *lpFileTime, SHORTINT *lpFatDate, SHORTINT *lpFatTime);
#define WinAPI_FileTimeToDosDateTime(lpFileTime, lpFatDate, lpFatTime)	FileTimeToDosDateTime(lpFileTime, lpFatDate, lpFatTime)
__EXTERN INTEGER __STDCALL FileTimeToLocalFileTime(WinAPI_FILETIME *lpFileTime, WinAPI_FILETIME *lpLocalFileTime);
#define WinAPI_FileTimeToLocalFileTime(lpFileTime, lpLocalFileTime)	FileTimeToLocalFileTime(lpFileTime, lpLocalFileTime)
__EXTERN INTEGER __STDCALL FileTimeToSystemTime(WinAPI_FILETIME *lpFileTime, WinAPI_SYSTEMTIME *lpSystemTime);
#define WinAPI_FileTimeToSystemTime(lpFileTime, lpSystemTime)	FileTimeToSystemTime(lpFileTime, lpSystemTime)
__EXTERN INTEGER __STDCALL FillConsoleOutputAttribute(LONGINT hConsoleOutput, SHORTINT wAttribute, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfAttrsWritten);
#define WinAPI_FillConsoleOutputAttribute(hConsoleOutput, wAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten)	FillConsoleOutputAttribute(hConsoleOutput, wAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten)
#define WinAPI_FillConsoleOutputCharacter(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	FillConsoleOutputCharacterA(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __STDCALL FillConsoleOutputCharacterA(LONGINT hConsoleOutput, CHAR cCharacter, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
#define WinAPI_FillConsoleOutputCharacterA(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	FillConsoleOutputCharacterA(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __STDCALL FillConsoleOutputCharacterW(LONGINT hConsoleOutput, SHORTINT cCharacter, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
#define WinAPI_FillConsoleOutputCharacterW(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	FillConsoleOutputCharacterW(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __STDCALL FillPath(LONGINT p0);
#define WinAPI_FillPath(p0)	FillPath(p0)
__EXTERN INTEGER __STDCALL FillRect(LONGINT hDC, WinAPI_RECT *lprc, LONGINT hbr);
#define WinAPI_FillRect(hDC, lprc, hbr)	FillRect(hDC, lprc, hbr)
__EXTERN INTEGER __STDCALL FillRgn(LONGINT p0, LONGINT p1, LONGINT p2);
#define WinAPI_FillRgn(p0, p1, p2)	FillRgn(p0, p1, p2)
#define WinAPI_FindAtom(lpString)	FindAtomA(lpString)
__EXTERN SHORTINT __STDCALL FindAtomA(LONGINT lpString);
#define WinAPI_FindAtomA(lpString)	FindAtomA(lpString)
__EXTERN SHORTINT __STDCALL FindAtomW(LONGINT lpString);
#define WinAPI_FindAtomW(lpString)	FindAtomW(lpString)
__EXTERN INTEGER __STDCALL FindClose(LONGINT hFindFile);
#define WinAPI_FindClose(hFindFile)	FindClose(hFindFile)
__EXTERN INTEGER __STDCALL FindCloseChangeNotification(LONGINT hChangeHandle);
#define WinAPI_FindCloseChangeNotification(hChangeHandle)	FindCloseChangeNotification(hChangeHandle)
__EXTERN INTEGER __STDCALL FindClosePrinterChangeNot__670(LONGINT hChange);
#define WinAPI_FindClosePrinterChangeNot__670(hChange)	FindClosePrinterChangeNot__670(hChange)
#define WinAPI_FindExecutable(lpFile, lpDirectory, lpResult)	FindExecutableA(lpFile, lpDirectory, lpResult)
__EXTERN LONGINT __STDCALL FindExecutableA(LONGINT lpFile, LONGINT lpDirectory, LONGINT lpResult);
#define WinAPI_FindExecutableA(lpFile, lpDirectory, lpResult)	FindExecutableA(lpFile, lpDirectory, lpResult)
__EXTERN LONGINT __STDCALL FindExecutableW(LONGINT lpFile, LONGINT lpDirectory, LONGINT lpResult);
#define WinAPI_FindExecutableW(lpFile, lpDirectory, lpResult)	FindExecutableW(lpFile, lpDirectory, lpResult)
#define WinAPI_FindFirstChangeNotification(lpPathName, bWatchSubtree, dwNotifyFilter)	FindFirstChangeNotificationA(lpPathName, bWatchSubtree, dwNotifyFilter)
__EXTERN LONGINT __STDCALL FindFirstChangeNotificationA(LONGINT lpPathName, INTEGER bWatchSubtree, SET dwNotifyFilter);
#define WinAPI_FindFirstChangeNotificationA(lpPathName, bWatchSubtree, dwNotifyFilter)	FindFirstChangeNotificationA(lpPathName, bWatchSubtree, dwNotifyFilter)
__EXTERN LONGINT __STDCALL FindFirstChangeNotificationW(LONGINT lpPathName, INTEGER bWatchSubtree, SET dwNotifyFilter);
#define WinAPI_FindFirstChangeNotificationW(lpPathName, bWatchSubtree, dwNotifyFilter)	FindFirstChangeNotificationW(lpPathName, bWatchSubtree, dwNotifyFilter)
#define WinAPI_FindFirstFile(lpFileName, lpFindFileData)	FindFirstFileA(lpFileName, lpFindFileData)
__EXTERN LONGINT __STDCALL FindFirstFileA(LONGINT lpFileName, WinAPI_WIN32_FIND_DATAA *lpFindFileData);
#define WinAPI_FindFirstFileA(lpFileName, lpFindFileData)	FindFirstFileA(lpFileName, lpFindFileData)
#define WinAPI_FindFirstFileEx(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)	FindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)
__EXTERN LONGINT __STDCALL FindFirstFileExA(LONGINT lpFileName, INTEGER fInfoLevelId, LONGINT lpFindFileData, INTEGER fSearchOp, LONGINT lpSearchFilter, INTEGER dwAdditionalFlags);
#define WinAPI_FindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)	FindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)
__EXTERN LONGINT __STDCALL FindFirstFileExW(LONGINT lpFileName, INTEGER fInfoLevelId, LONGINT lpFindFileData, INTEGER fSearchOp, LONGINT lpSearchFilter, INTEGER dwAdditionalFlags);
#define WinAPI_FindFirstFileExW(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)	FindFirstFileExW(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)
__EXTERN LONGINT __STDCALL FindFirstFileW(LONGINT lpFileName, WinAPI_WIN32_FIND_DATAW *lpFindFileData);
#define WinAPI_FindFirstFileW(lpFileName, lpFindFileData)	FindFirstFileW(lpFileName, lpFindFileData)
__EXTERN INTEGER __STDCALL FindFirstFreeAce(WinAPI_ACL *pAcl, LONGINT pAce);
#define WinAPI_FindFirstFreeAce(pAcl, pAce)	FindFirstFreeAce(pAcl, pAce)
__EXTERN LONGINT __STDCALL FindFirstPrinterChangeNot__684(LONGINT hPrinter, SET fdwFlags, INTEGER fdwOptions, LONGINT pPrinterNotifyOptions);
#define WinAPI_FindFirstPrinterChangeNot__684(hPrinter, fdwFlags, fdwOptions, pPrinterNotifyOptions)	FindFirstPrinterChangeNot__684(hPrinter, fdwFlags, fdwOptions, pPrinterNotifyOptions)
__EXTERN INTEGER __STDCALL FindNextChangeNotification(LONGINT hChangeHandle);
#define WinAPI_FindNextChangeNotification(hChangeHandle)	FindNextChangeNotification(hChangeHandle)
#define WinAPI_FindNextFile(hFindFile, lpFindFileData)	FindNextFileA(hFindFile, lpFindFileData)
__EXTERN INTEGER __STDCALL FindNextFileA(LONGINT hFindFile, WinAPI_WIN32_FIND_DATAA *lpFindFileData);
#define WinAPI_FindNextFileA(hFindFile, lpFindFileData)	FindNextFileA(hFindFile, lpFindFileData)
__EXTERN INTEGER __STDCALL FindNextFileW(LONGINT hFindFile, WinAPI_WIN32_FIND_DATAW *lpFindFileData);
#define WinAPI_FindNextFileW(hFindFile, lpFindFileData)	FindNextFileW(hFindFile, lpFindFileData)
__EXTERN INTEGER __STDCALL FindNextPrinterChangeNoti__689(LONGINT hChange, INTEGER *pdwChange, LONGINT pvReserved, LONGINT ppPrinterNotifyInfo);
#define WinAPI_FindNextPrinterChangeNoti__689(hChange, pdwChange, pvReserved, ppPrinterNotifyInfo)	FindNextPrinterChangeNoti__689(hChange, pdwChange, pvReserved, ppPrinterNotifyInfo)
#define WinAPI_FindResource(hModule, lpName, lpType)	FindResourceA(hModule, lpName, lpType)
__EXTERN LONGINT __STDCALL FindResourceA(LONGINT hModule, LONGINT lpName, LONGINT lpType);
#define WinAPI_FindResourceA(hModule, lpName, lpType)	FindResourceA(hModule, lpName, lpType)
#define WinAPI_FindResourceEx(hModule, lpType, lpName, wLanguage)	FindResourceExA(hModule, lpType, lpName, wLanguage)
__EXTERN LONGINT __STDCALL FindResourceExA(LONGINT hModule, LONGINT lpType, LONGINT lpName, SHORTINT wLanguage);
#define WinAPI_FindResourceExA(hModule, lpType, lpName, wLanguage)	FindResourceExA(hModule, lpType, lpName, wLanguage)
__EXTERN LONGINT __STDCALL FindResourceExW(LONGINT hModule, LONGINT lpType, LONGINT lpName, SHORTINT wLanguage);
#define WinAPI_FindResourceExW(hModule, lpType, lpName, wLanguage)	FindResourceExW(hModule, lpType, lpName, wLanguage)
__EXTERN LONGINT __STDCALL FindResourceW(LONGINT hModule, LONGINT lpName, LONGINT lpType);
#define WinAPI_FindResourceW(hModule, lpName, lpType)	FindResourceW(hModule, lpName, lpType)
#define WinAPI_FindWindow(lpClassName, lpWindowName)	FindWindowA(lpClassName, lpWindowName)
__EXTERN LONGINT __STDCALL FindWindowA(LONGINT lpClassName, LONGINT lpWindowName);
#define WinAPI_FindWindowA(lpClassName, lpWindowName)	FindWindowA(lpClassName, lpWindowName)
#define WinAPI_FindWindowEx(p0, p1, p2, p3)	FindWindowExA(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL FindWindowExA(LONGINT p0, LONGINT p1, LONGINT p2, LONGINT p3);
#define WinAPI_FindWindowExA(p0, p1, p2, p3)	FindWindowExA(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL FindWindowExW(LONGINT p0, LONGINT p1, LONGINT p2, LONGINT p3);
#define WinAPI_FindWindowExW(p0, p1, p2, p3)	FindWindowExW(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL FindWindowW(LONGINT lpClassName, LONGINT lpWindowName);
#define WinAPI_FindWindowW(lpClassName, lpWindowName)	FindWindowW(lpClassName, lpWindowName)
__EXTERN INTEGER __STDCALL FixBrushOrgEx(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_FixBrushOrgEx(p0, p1, p2, p3)	FixBrushOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL FlashWindow(LONGINT hWnd, INTEGER bInvert);
#define WinAPI_FlashWindow(hWnd, bInvert)	FlashWindow(hWnd, bInvert)
__EXTERN INTEGER __STDCALL FlattenPath(LONGINT p0);
#define WinAPI_FlattenPath(p0)	FlattenPath(p0)
__EXTERN INTEGER __STDCALL FloodFill(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_FloodFill(p0, p1, p2, p3)	FloodFill(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL FlushConsoleInputBuffer(LONGINT hConsoleInput);
#define WinAPI_FlushConsoleInputBuffer(hConsoleInput)	FlushConsoleInputBuffer(hConsoleInput)
__EXTERN INTEGER __STDCALL FlushFileBuffers(LONGINT hFile);
#define WinAPI_FlushFileBuffers(hFile)	FlushFileBuffers(hFile)
__EXTERN INTEGER __STDCALL FlushInstructionCache(LONGINT hProcess, LONGINT lpBaseAddress, INTEGER dwSize);
#define WinAPI_FlushInstructionCache(hProcess, lpBaseAddress, dwSize)	FlushInstructionCache(hProcess, lpBaseAddress, dwSize)
__EXTERN INTEGER __STDCALL FlushViewOfFile(LONGINT lpBaseAddress, INTEGER dwNumberOfBytesToFlush);
#define WinAPI_FlushViewOfFile(lpBaseAddress, dwNumberOfBytesToFlush)	FlushViewOfFile(lpBaseAddress, dwNumberOfBytesToFlush)
#define WinAPI_FoldString(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	FoldStringA(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
__EXTERN INTEGER __STDCALL FoldStringA(SET dwMapFlags, LONGINT lpSrcStr, INTEGER cchSrc, LONGINT lpDestStr, INTEGER cchDest);
#define WinAPI_FoldStringA(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	FoldStringA(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
__EXTERN INTEGER __STDCALL FoldStringW(SET dwMapFlags, LONGINT lpSrcStr, INTEGER cchSrc, LONGINT lpDestStr, INTEGER cchDest);
#define WinAPI_FoldStringW(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	FoldStringW(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
#define WinAPI_FormatMessage(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)	FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)
__EXTERN INTEGER __STDCALL FormatMessageA(SET dwFlags, LONGINT lpSource, INTEGER dwMessageId, INTEGER dwLanguageId, LONGINT lpBuffer, INTEGER nSize, LONGINT *Arguments);
#define WinAPI_FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)	FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)
__EXTERN INTEGER __STDCALL FormatMessageW(SET dwFlags, LONGINT lpSource, INTEGER dwMessageId, INTEGER dwLanguageId, LONGINT lpBuffer, INTEGER nSize, LONGINT *Arguments);
#define WinAPI_FormatMessageW(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)	FormatMessageW(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)
__EXTERN INTEGER __STDCALL FrameRect(LONGINT hDC, WinAPI_RECT *lprc, LONGINT hbr);
#define WinAPI_FrameRect(hDC, lprc, hbr)	FrameRect(hDC, lprc, hbr)
__EXTERN INTEGER __STDCALL FrameRgn(LONGINT p0, LONGINT p1, LONGINT p2, INTEGER p3, INTEGER p4);
#define WinAPI_FrameRgn(p0, p1, p2, p3, p4)	FrameRgn(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL FreeConsole(void);
#define WinAPI_FreeConsole()	FreeConsole()
__EXTERN INTEGER __STDCALL FreeDDElParam(INTEGER msg, INTEGER lParam);
#define WinAPI_FreeDDElParam(msg, lParam)	FreeDDElParam(msg, lParam)
#define WinAPI_FreeEnvironmentStrings(p0)	FreeEnvironmentStringsA(p0)
__EXTERN INTEGER __STDCALL FreeEnvironmentStringsA(LONGINT p0);
#define WinAPI_FreeEnvironmentStringsA(p0)	FreeEnvironmentStringsA(p0)
__EXTERN INTEGER __STDCALL FreeEnvironmentStringsW(LONGINT p0);
#define WinAPI_FreeEnvironmentStringsW(p0)	FreeEnvironmentStringsW(p0)
__EXTERN INTEGER __STDCALL FreeLibrary(LONGINT hLibModule);
#define WinAPI_FreeLibrary(hLibModule)	FreeLibrary(hLibModule)
__EXTERN void __STDCALL FreeLibraryAndExitThread(LONGINT hLibModule, INTEGER dwExitCode);
#define WinAPI_FreeLibraryAndExitThread(hLibModule, dwExitCode)	FreeLibraryAndExitThread(hLibModule, dwExitCode)
__EXTERN INTEGER __STDCALL FreePrinterNotifyInfo(WinAPI_PRINTER_NOTIFY_INFO *pPrinterNotifyInfo);
#define WinAPI_FreePrinterNotifyInfo(pPrinterNotifyInfo)	FreePrinterNotifyInfo(pPrinterNotifyInfo)
__EXTERN INTEGER __STDCALL FreeResource(LONGINT hResData);
#define WinAPI_FreeResource(hResData)	FreeResource(hResData)
__EXTERN LONGINT __STDCALL FreeSid(LONGINT pSid);
#define WinAPI_FreeSid(pSid)	FreeSid(pSid)
__EXTERN INTEGER __STDCALL GdiComment(LONGINT p0, INTEGER p1, CHAR *p2);
#define WinAPI_GdiComment(p0, p1, p2)	GdiComment(p0, p1, p2)
__EXTERN INTEGER __STDCALL GdiFlush(void);
#define WinAPI_GdiFlush()	GdiFlush()
__EXTERN INTEGER __STDCALL GdiGetBatchLimit(void);
#define WinAPI_GdiGetBatchLimit()	GdiGetBatchLimit()
__EXTERN INTEGER __STDCALL GdiSetBatchLimit(INTEGER p0);
#define WinAPI_GdiSetBatchLimit(p0)	GdiSetBatchLimit(p0)
__EXTERN INTEGER __STDCALL GenerateConsoleCtrlEvent(INTEGER dwCtrlEvent, INTEGER dwProcessGroupId);
#define WinAPI_GenerateConsoleCtrlEvent(dwCtrlEvent, dwProcessGroupId)	GenerateConsoleCtrlEvent(dwCtrlEvent, dwProcessGroupId)
__EXTERN INTEGER __STDCALL GetACP(void);
#define WinAPI_GetACP()	GetACP()
__EXTERN INTEGER __STDCALL GetAce(WinAPI_ACL *pAcl, INTEGER dwAceIndex, LONGINT pAce);
#define WinAPI_GetAce(pAcl, dwAceIndex, pAce)	GetAce(pAcl, dwAceIndex, pAce)
__EXTERN INTEGER __STDCALL GetAclInformation(WinAPI_ACL *pAcl, LONGINT pAclInformation, INTEGER nAclInformationLength, INTEGER dwAclInformationClass);
#define WinAPI_GetAclInformation(pAcl, pAclInformation, nAclInformationLength, dwAclInformationClass)	GetAclInformation(pAcl, pAclInformation, nAclInformationLength, dwAclInformationClass)
__EXTERN LONGINT __STDCALL GetActiveWindow(void);
#define WinAPI_GetActiveWindow()	GetActiveWindow()
__EXTERN INTEGER __STDCALL GetArcDirection(LONGINT p0);
#define WinAPI_GetArcDirection(p0)	GetArcDirection(p0)
__EXTERN INTEGER __STDCALL GetAspectRatioFilterEx(LONGINT p0, WinAPI_SIZE *p1);
#define WinAPI_GetAspectRatioFilterEx(p0, p1)	GetAspectRatioFilterEx(p0, p1)
__EXTERN SHORTINT __STDCALL GetAsyncKeyState(INTEGER vKey);
#define WinAPI_GetAsyncKeyState(vKey)	GetAsyncKeyState(vKey)
#define WinAPI_GetAtomName(nAtom, lpBuffer, nSize)	GetAtomNameA(nAtom, lpBuffer, nSize)
__EXTERN INTEGER __STDCALL GetAtomNameA(SHORTINT nAtom, LONGINT lpBuffer, INTEGER nSize);
#define WinAPI_GetAtomNameA(nAtom, lpBuffer, nSize)	GetAtomNameA(nAtom, lpBuffer, nSize)
__EXTERN INTEGER __STDCALL GetAtomNameW(SHORTINT nAtom, LONGINT lpBuffer, INTEGER nSize);
#define WinAPI_GetAtomNameW(nAtom, lpBuffer, nSize)	GetAtomNameW(nAtom, lpBuffer, nSize)
#define WinAPI_GetBinaryType(lpApplicationName, lpBinaryType)	GetBinaryTypeA(lpApplicationName, lpBinaryType)
__EXTERN INTEGER __STDCALL GetBinaryTypeA(LONGINT lpApplicationName, INTEGER *lpBinaryType);
#define WinAPI_GetBinaryTypeA(lpApplicationName, lpBinaryType)	GetBinaryTypeA(lpApplicationName, lpBinaryType)
__EXTERN INTEGER __STDCALL GetBinaryTypeW(LONGINT lpApplicationName, INTEGER *lpBinaryType);
#define WinAPI_GetBinaryTypeW(lpApplicationName, lpBinaryType)	GetBinaryTypeW(lpApplicationName, lpBinaryType)
__EXTERN INTEGER __STDCALL GetBitmapBits(LONGINT p0, INTEGER p1, LONGINT p2);
#define WinAPI_GetBitmapBits(p0, p1, p2)	GetBitmapBits(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetBitmapDimensionEx(LONGINT p0, WinAPI_SIZE *p1);
#define WinAPI_GetBitmapDimensionEx(p0, p1)	GetBitmapDimensionEx(p0, p1)
__EXTERN INTEGER __STDCALL GetBkColor(LONGINT p0);
#define WinAPI_GetBkColor(p0)	GetBkColor(p0)
__EXTERN INTEGER __STDCALL GetBkMode(LONGINT p0);
#define WinAPI_GetBkMode(p0)	GetBkMode(p0)
__EXTERN SET __STDCALL GetBoundsRect(LONGINT p0, WinAPI_RECT *p1, SET p2);
#define WinAPI_GetBoundsRect(p0, p1, p2)	GetBoundsRect(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetBrushOrgEx(LONGINT p0, WinAPI_POINT *p1);
#define WinAPI_GetBrushOrgEx(p0, p1)	GetBrushOrgEx(p0, p1)
__EXTERN INTEGER __STDCALL GetCPInfo(INTEGER CodePage, WinAPI_CPINFO *lpCPInfo);
#define WinAPI_GetCPInfo(CodePage, lpCPInfo)	GetCPInfo(CodePage, lpCPInfo)
__EXTERN LONGINT __STDCALL GetCapture(void);
#define WinAPI_GetCapture()	GetCapture()
__EXTERN INTEGER __STDCALL GetCaretBlinkTime(void);
#define WinAPI_GetCaretBlinkTime()	GetCaretBlinkTime()
__EXTERN INTEGER __STDCALL GetCaretPos(WinAPI_POINT *lpPoint);
#define WinAPI_GetCaretPos(lpPoint)	GetCaretPos(lpPoint)
#define WinAPI_GetCharABCWidths(p0, p1, p2, p3)	GetCharABCWidthsA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetCharABCWidthsA(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_ABC *p3);
#define WinAPI_GetCharABCWidthsA(p0, p1, p2, p3)	GetCharABCWidthsA(p0, p1, p2, p3)
#define WinAPI_GetCharABCWidthsFloat(p0, p1, p2, p3)	GetCharABCWidthsFloatA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetCharABCWidthsFloatA(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_ABCFLOAT *p3);
#define WinAPI_GetCharABCWidthsFloatA(p0, p1, p2, p3)	GetCharABCWidthsFloatA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetCharABCWidthsFloatW(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_ABCFLOAT *p3);
#define WinAPI_GetCharABCWidthsFloatW(p0, p1, p2, p3)	GetCharABCWidthsFloatW(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetCharABCWidthsW(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_ABC *p3);
#define WinAPI_GetCharABCWidthsW(p0, p1, p2, p3)	GetCharABCWidthsW(p0, p1, p2, p3)
#define WinAPI_GetCharWidth(p0, p1, p2, p3)	GetCharWidthA(p0, p1, p2, p3)
#define WinAPI_GetCharWidth32(p0, p1, p2, p3)	GetCharWidth32A(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetCharWidth32A(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER *p3);
#define WinAPI_GetCharWidth32A(p0, p1, p2, p3)	GetCharWidth32A(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetCharWidth32W(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER *p3);
#define WinAPI_GetCharWidth32W(p0, p1, p2, p3)	GetCharWidth32W(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetCharWidthA(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER *p3);
#define WinAPI_GetCharWidthA(p0, p1, p2, p3)	GetCharWidthA(p0, p1, p2, p3)
#define WinAPI_GetCharWidthFloat(p0, p1, p2, p3)	GetCharWidthFloatA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetCharWidthFloatA(LONGINT p0, INTEGER p1, INTEGER p2, SHORTREAL *p3);
#define WinAPI_GetCharWidthFloatA(p0, p1, p2, p3)	GetCharWidthFloatA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetCharWidthFloatW(LONGINT p0, INTEGER p1, INTEGER p2, SHORTREAL *p3);
#define WinAPI_GetCharWidthFloatW(p0, p1, p2, p3)	GetCharWidthFloatW(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetCharWidthW(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER *p3);
#define WinAPI_GetCharWidthW(p0, p1, p2, p3)	GetCharWidthW(p0, p1, p2, p3)
#define WinAPI_GetCharacterPlacement(p0, p1, p2, p3, p4, p5)	GetCharacterPlacementA(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __STDCALL GetCharacterPlacementA(LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, WinAPI_GCP_RESULTSA *p4, INTEGER p5);
#define WinAPI_GetCharacterPlacementA(p0, p1, p2, p3, p4, p5)	GetCharacterPlacementA(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __STDCALL GetCharacterPlacementW(LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, WinAPI_GCP_RESULTSW *p4, INTEGER p5);
#define WinAPI_GetCharacterPlacementW(p0, p1, p2, p3, p4, p5)	GetCharacterPlacementW(p0, p1, p2, p3, p4, p5)
#define WinAPI_GetClassInfo(hInstance, lpClassName, lpWndClass)	GetClassInfoA(hInstance, lpClassName, lpWndClass)
__EXTERN INTEGER __STDCALL GetClassInfoA(LONGINT hInstance, LONGINT lpClassName, WinAPI_WNDCLASSA *lpWndClass);
#define WinAPI_GetClassInfoA(hInstance, lpClassName, lpWndClass)	GetClassInfoA(hInstance, lpClassName, lpWndClass)
#define WinAPI_GetClassInfoEx(p0, p1, p2)	GetClassInfoExA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetClassInfoExA(LONGINT p0, LONGINT p1, WinAPI_WNDCLASSEXA *p2);
#define WinAPI_GetClassInfoExA(p0, p1, p2)	GetClassInfoExA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetClassInfoExW(LONGINT p0, LONGINT p1, WinAPI_WNDCLASSEXW *p2);
#define WinAPI_GetClassInfoExW(p0, p1, p2)	GetClassInfoExW(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetClassInfoW(LONGINT hInstance, LONGINT lpClassName, WinAPI_WNDCLASSW *lpWndClass);
#define WinAPI_GetClassInfoW(hInstance, lpClassName, lpWndClass)	GetClassInfoW(hInstance, lpClassName, lpWndClass)
#define WinAPI_GetClassLong(hWnd, nIndex)	GetClassLongA(hWnd, nIndex)
__EXTERN INTEGER __STDCALL GetClassLongA(LONGINT hWnd, INTEGER nIndex);
#define WinAPI_GetClassLongA(hWnd, nIndex)	GetClassLongA(hWnd, nIndex)
__EXTERN INTEGER __STDCALL GetClassLongW(LONGINT hWnd, INTEGER nIndex);
#define WinAPI_GetClassLongW(hWnd, nIndex)	GetClassLongW(hWnd, nIndex)
#define WinAPI_GetClassName(hWnd, lpClassName, nMaxCount)	GetClassNameA(hWnd, lpClassName, nMaxCount)
__EXTERN INTEGER __STDCALL GetClassNameA(LONGINT hWnd, LONGINT lpClassName, INTEGER nMaxCount);
#define WinAPI_GetClassNameA(hWnd, lpClassName, nMaxCount)	GetClassNameA(hWnd, lpClassName, nMaxCount)
__EXTERN INTEGER __STDCALL GetClassNameW(LONGINT hWnd, LONGINT lpClassName, INTEGER nMaxCount);
#define WinAPI_GetClassNameW(hWnd, lpClassName, nMaxCount)	GetClassNameW(hWnd, lpClassName, nMaxCount)
__EXTERN SHORTINT __STDCALL GetClassWord(LONGINT hWnd, INTEGER nIndex);
#define WinAPI_GetClassWord(hWnd, nIndex)	GetClassWord(hWnd, nIndex)
__EXTERN INTEGER __STDCALL GetClientRect(LONGINT hWnd, WinAPI_RECT *lpRect);
#define WinAPI_GetClientRect(hWnd, lpRect)	GetClientRect(hWnd, lpRect)
__EXTERN INTEGER __STDCALL GetClipBox(LONGINT p0, WinAPI_RECT *p1);
#define WinAPI_GetClipBox(p0, p1)	GetClipBox(p0, p1)
__EXTERN INTEGER __STDCALL GetClipCursor(WinAPI_RECT *lpRect);
#define WinAPI_GetClipCursor(lpRect)	GetClipCursor(lpRect)
__EXTERN INTEGER __STDCALL GetClipRgn(LONGINT p0, LONGINT p1);
#define WinAPI_GetClipRgn(p0, p1)	GetClipRgn(p0, p1)
__EXTERN LONGINT __STDCALL GetClipboardData(INTEGER uFormat);
#define WinAPI_GetClipboardData(uFormat)	GetClipboardData(uFormat)
#define WinAPI_GetClipboardFormatName(format, lpszFormatName, cchMaxCount)	GetClipboardFormatNameA(format, lpszFormatName, cchMaxCount)
__EXTERN INTEGER __STDCALL GetClipboardFormatNameA(INTEGER format, LONGINT lpszFormatName, INTEGER cchMaxCount);
#define WinAPI_GetClipboardFormatNameA(format, lpszFormatName, cchMaxCount)	GetClipboardFormatNameA(format, lpszFormatName, cchMaxCount)
__EXTERN INTEGER __STDCALL GetClipboardFormatNameW(INTEGER format, LONGINT lpszFormatName, INTEGER cchMaxCount);
#define WinAPI_GetClipboardFormatNameW(format, lpszFormatName, cchMaxCount)	GetClipboardFormatNameW(format, lpszFormatName, cchMaxCount)
__EXTERN LONGINT __STDCALL GetClipboardOwner(void);
#define WinAPI_GetClipboardOwner()	GetClipboardOwner()
__EXTERN LONGINT __STDCALL GetClipboardViewer(void);
#define WinAPI_GetClipboardViewer()	GetClipboardViewer()
__EXTERN INTEGER __STDCALL GetColorAdjustment(LONGINT p0, WinAPI_COLORADJUSTMENT *p1);
#define WinAPI_GetColorAdjustment(p0, p1)	GetColorAdjustment(p0, p1)
__EXTERN LONGINT __STDCALL GetColorSpace(LONGINT p0);
#define WinAPI_GetColorSpace(p0)	GetColorSpace(p0)
__EXTERN INTEGER __STDCALL GetCommConfig(LONGINT hCommDev, WinAPI_COMMCONFIG *lpCC, INTEGER *lpdwSize);
#define WinAPI_GetCommConfig(hCommDev, lpCC, lpdwSize)	GetCommConfig(hCommDev, lpCC, lpdwSize)
__EXTERN INTEGER __STDCALL GetCommMask(LONGINT hFile, SET *lpEvtMask);
#define WinAPI_GetCommMask(hFile, lpEvtMask)	GetCommMask(hFile, lpEvtMask)
__EXTERN INTEGER __STDCALL GetCommModemStatus(LONGINT hFile, SET *lpModemStat);
#define WinAPI_GetCommModemStatus(hFile, lpModemStat)	GetCommModemStatus(hFile, lpModemStat)
__EXTERN INTEGER __STDCALL GetCommProperties(LONGINT hFile, WinAPI_COMMPROP *lpCommProp);
#define WinAPI_GetCommProperties(hFile, lpCommProp)	GetCommProperties(hFile, lpCommProp)
__EXTERN INTEGER __STDCALL GetCommState(LONGINT hFile, WinAPI_DCB *lpDCB);
#define WinAPI_GetCommState(hFile, lpDCB)	GetCommState(hFile, lpDCB)
__EXTERN INTEGER __STDCALL GetCommTimeouts(LONGINT hFile, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
#define WinAPI_GetCommTimeouts(hFile, lpCommTimeouts)	GetCommTimeouts(hFile, lpCommTimeouts)
#define WinAPI_GetCommandLine()	GetCommandLineA()
__EXTERN LONGINT __STDCALL GetCommandLineA(void);
#define WinAPI_GetCommandLineA()	GetCommandLineA()
__EXTERN LONGINT __STDCALL GetCommandLineW(void);
#define WinAPI_GetCommandLineW()	GetCommandLineW()
#define WinAPI_GetCompressedFileSize(lpFileName, lpFileSizeHigh)	GetCompressedFileSizeA(lpFileName, lpFileSizeHigh)
__EXTERN INTEGER __STDCALL GetCompressedFileSizeA(LONGINT lpFileName, INTEGER *lpFileSizeHigh);
#define WinAPI_GetCompressedFileSizeA(lpFileName, lpFileSizeHigh)	GetCompressedFileSizeA(lpFileName, lpFileSizeHigh)
__EXTERN INTEGER __STDCALL GetCompressedFileSizeW(LONGINT lpFileName, INTEGER *lpFileSizeHigh);
#define WinAPI_GetCompressedFileSizeW(lpFileName, lpFileSizeHigh)	GetCompressedFileSizeW(lpFileName, lpFileSizeHigh)
#define WinAPI_GetComputerName(lpBuffer, nSize)	GetComputerNameA(lpBuffer, nSize)
__EXTERN INTEGER __STDCALL GetComputerNameA(LONGINT lpBuffer, INTEGER *nSize);
#define WinAPI_GetComputerNameA(lpBuffer, nSize)	GetComputerNameA(lpBuffer, nSize)
__EXTERN INTEGER __STDCALL GetComputerNameW(LONGINT lpBuffer, INTEGER *nSize);
#define WinAPI_GetComputerNameW(lpBuffer, nSize)	GetComputerNameW(lpBuffer, nSize)
__EXTERN INTEGER __STDCALL GetConsoleCP(void);
#define WinAPI_GetConsoleCP()	GetConsoleCP()
__EXTERN INTEGER __STDCALL GetConsoleCursorInfo(LONGINT hConsoleOutput, WinAPI_CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
#define WinAPI_GetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo)	GetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo)
__EXTERN INTEGER __STDCALL GetConsoleMode(LONGINT hConsoleHandle, SET *lpMode);
#define WinAPI_GetConsoleMode(hConsoleHandle, lpMode)	GetConsoleMode(hConsoleHandle, lpMode)
__EXTERN INTEGER __STDCALL GetConsoleOutputCP(void);
#define WinAPI_GetConsoleOutputCP()	GetConsoleOutputCP()
__EXTERN INTEGER __STDCALL GetConsoleScreenBufferInfo(LONGINT hConsoleOutput, WinAPI_CONSOLE_SCREEN_BUFFER_INFO *lpConsoleScreenBufferInfo);
#define WinAPI_GetConsoleScreenBufferInfo(hConsoleOutput, lpConsoleScreenBufferInfo)	GetConsoleScreenBufferInfo(hConsoleOutput, lpConsoleScreenBufferInfo)
#define WinAPI_GetConsoleTitle(lpConsoleTitle, nSize)	GetConsoleTitleA(lpConsoleTitle, nSize)
__EXTERN INTEGER __STDCALL GetConsoleTitleA(LONGINT lpConsoleTitle, INTEGER nSize);
#define WinAPI_GetConsoleTitleA(lpConsoleTitle, nSize)	GetConsoleTitleA(lpConsoleTitle, nSize)
__EXTERN INTEGER __STDCALL GetConsoleTitleW(LONGINT lpConsoleTitle, INTEGER nSize);
#define WinAPI_GetConsoleTitleW(lpConsoleTitle, nSize)	GetConsoleTitleW(lpConsoleTitle, nSize)
#define WinAPI_GetCurrencyFormat(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)	GetCurrencyFormatA(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)
__EXTERN INTEGER __STDCALL GetCurrencyFormatA(INTEGER Locale, SET dwFlags, LONGINT lpValue, WinAPI_CURRENCYFMTA *lpFormat, LONGINT lpCurrencyStr, INTEGER cchCurrency);
#define WinAPI_GetCurrencyFormatA(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)	GetCurrencyFormatA(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)
__EXTERN INTEGER __STDCALL GetCurrencyFormatW(INTEGER Locale, SET dwFlags, LONGINT lpValue, WinAPI_CURRENCYFMTW *lpFormat, LONGINT lpCurrencyStr, INTEGER cchCurrency);
#define WinAPI_GetCurrencyFormatW(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)	GetCurrencyFormatW(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)
#define WinAPI_GetCurrentDirectory(nBufferLength, lpBuffer)	GetCurrentDirectoryA(nBufferLength, lpBuffer)
__EXTERN INTEGER __STDCALL GetCurrentDirectoryA(INTEGER nBufferLength, LONGINT lpBuffer);
#define WinAPI_GetCurrentDirectoryA(nBufferLength, lpBuffer)	GetCurrentDirectoryA(nBufferLength, lpBuffer)
__EXTERN INTEGER __STDCALL GetCurrentDirectoryW(INTEGER nBufferLength, LONGINT lpBuffer);
#define WinAPI_GetCurrentDirectoryW(nBufferLength, lpBuffer)	GetCurrentDirectoryW(nBufferLength, lpBuffer)
#define WinAPI_GetCurrentHwProfile(lpHwProfileInfo)	GetCurrentHwProfileA(lpHwProfileInfo)
__EXTERN INTEGER __STDCALL GetCurrentHwProfileA(WinAPI_HW_PROFILE_INFOA *lpHwProfileInfo);
#define WinAPI_GetCurrentHwProfileA(lpHwProfileInfo)	GetCurrentHwProfileA(lpHwProfileInfo)
__EXTERN INTEGER __STDCALL GetCurrentHwProfileW(WinAPI_HW_PROFILE_INFOW *lpHwProfileInfo);
#define WinAPI_GetCurrentHwProfileW(lpHwProfileInfo)	GetCurrentHwProfileW(lpHwProfileInfo)
__EXTERN LONGINT __STDCALL GetCurrentObject(LONGINT p0, INTEGER p1);
#define WinAPI_GetCurrentObject(p0, p1)	GetCurrentObject(p0, p1)
__EXTERN INTEGER __STDCALL GetCurrentPositionEx(LONGINT p0, WinAPI_POINT *p1);
#define WinAPI_GetCurrentPositionEx(p0, p1)	GetCurrentPositionEx(p0, p1)
__EXTERN LONGINT __STDCALL GetCurrentProcess(void);
#define WinAPI_GetCurrentProcess()	GetCurrentProcess()
__EXTERN INTEGER __STDCALL GetCurrentProcessId(void);
#define WinAPI_GetCurrentProcessId()	GetCurrentProcessId()
__EXTERN LONGINT __STDCALL GetCurrentThread(void);
#define WinAPI_GetCurrentThread()	GetCurrentThread()
__EXTERN INTEGER __STDCALL GetCurrentThreadId(void);
#define WinAPI_GetCurrentThreadId()	GetCurrentThreadId()
__EXTERN LONGINT __STDCALL GetCursor(void);
#define WinAPI_GetCursor()	GetCursor()
__EXTERN INTEGER __STDCALL GetCursorPos(WinAPI_POINT *lpPoint);
#define WinAPI_GetCursorPos(lpPoint)	GetCursorPos(lpPoint)
__EXTERN LONGINT __STDCALL GetDC(LONGINT hWnd);
#define WinAPI_GetDC(hWnd)	GetDC(hWnd)
__EXTERN LONGINT __STDCALL GetDCEx(LONGINT hWnd, LONGINT hrgnClip, SET flags);
#define WinAPI_GetDCEx(hWnd, hrgnClip, flags)	GetDCEx(hWnd, hrgnClip, flags)
__EXTERN INTEGER __STDCALL GetDCOrgEx(LONGINT p0, WinAPI_POINT *p1);
#define WinAPI_GetDCOrgEx(p0, p1)	GetDCOrgEx(p0, p1)
__EXTERN INTEGER __STDCALL GetDIBColorTable(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_RGBQUAD *p3);
#define WinAPI_GetDIBColorTable(p0, p1, p2, p3)	GetDIBColorTable(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetDIBits(LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, LONGINT p4, WinAPI_BITMAPINFO *p5, INTEGER p6);
#define WinAPI_GetDIBits(p0, p1, p2, p3, p4, p5, p6)	GetDIBits(p0, p1, p2, p3, p4, p5, p6)
#define WinAPI_GetDateFormat(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)	GetDateFormatA(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)
__EXTERN INTEGER __STDCALL GetDateFormatA(INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpDate, LONGINT lpFormat, LONGINT lpDateStr, INTEGER cchDate);
#define WinAPI_GetDateFormatA(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)	GetDateFormatA(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)
__EXTERN INTEGER __STDCALL GetDateFormatW(INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpDate, LONGINT lpFormat, LONGINT lpDateStr, INTEGER cchDate);
#define WinAPI_GetDateFormatW(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)	GetDateFormatW(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)
#define WinAPI_GetDefaultCommConfig(lpszName, lpCC, lpdwSize)	GetDefaultCommConfigA(lpszName, lpCC, lpdwSize)
__EXTERN INTEGER __STDCALL GetDefaultCommConfigA(LONGINT lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER *lpdwSize);
#define WinAPI_GetDefaultCommConfigA(lpszName, lpCC, lpdwSize)	GetDefaultCommConfigA(lpszName, lpCC, lpdwSize)
__EXTERN INTEGER __STDCALL GetDefaultCommConfigW(LONGINT lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER *lpdwSize);
#define WinAPI_GetDefaultCommConfigW(lpszName, lpCC, lpdwSize)	GetDefaultCommConfigW(lpszName, lpCC, lpdwSize)
__EXTERN LONGINT __STDCALL GetDesktopWindow(void);
#define WinAPI_GetDesktopWindow()	GetDesktopWindow()
__EXTERN INTEGER __STDCALL GetDeviceCaps(LONGINT p0, INTEGER p1);
#define WinAPI_GetDeviceCaps(p0, p1)	GetDeviceCaps(p0, p1)
__EXTERN INTEGER __STDCALL GetDeviceGammaRamp(LONGINT p0, LONGINT p1);
#define WinAPI_GetDeviceGammaRamp(p0, p1)	GetDeviceGammaRamp(p0, p1)
__EXTERN INTEGER __STDCALL GetDialogBaseUnits(void);
#define WinAPI_GetDialogBaseUnits()	GetDialogBaseUnits()
#define WinAPI_GetDiskFreeSpace(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)	GetDiskFreeSpaceA(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)
__EXTERN INTEGER __STDCALL GetDiskFreeSpaceA(LONGINT lpRootPathName, INTEGER *lpSectorsPerCluster, INTEGER *lpBytesPerSector, INTEGER *lpNumberOfFreeClusters, INTEGER *lpTotalNumberOfClusters);
#define WinAPI_GetDiskFreeSpaceA(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)	GetDiskFreeSpaceA(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)
__EXTERN INTEGER __STDCALL GetDiskFreeSpaceW(LONGINT lpRootPathName, INTEGER *lpSectorsPerCluster, INTEGER *lpBytesPerSector, INTEGER *lpNumberOfFreeClusters, INTEGER *lpTotalNumberOfClusters);
#define WinAPI_GetDiskFreeSpaceW(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)	GetDiskFreeSpaceW(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)
__EXTERN INTEGER __STDCALL GetDlgCtrlID(LONGINT hWnd);
#define WinAPI_GetDlgCtrlID(hWnd)	GetDlgCtrlID(hWnd)
__EXTERN LONGINT __STDCALL GetDlgItem(LONGINT hDlg, INTEGER nIDDlgItem);
#define WinAPI_GetDlgItem(hDlg, nIDDlgItem)	GetDlgItem(hDlg, nIDDlgItem)
__EXTERN INTEGER __STDCALL GetDlgItemInt(LONGINT hDlg, INTEGER nIDDlgItem, INTEGER *lpTranslated, INTEGER bSigned);
#define WinAPI_GetDlgItemInt(hDlg, nIDDlgItem, lpTranslated, bSigned)	GetDlgItemInt(hDlg, nIDDlgItem, lpTranslated, bSigned)
#define WinAPI_GetDlgItemText(hDlg, nIDDlgItem, lpString, nMaxCount)	GetDlgItemTextA(hDlg, nIDDlgItem, lpString, nMaxCount)
__EXTERN INTEGER __STDCALL GetDlgItemTextA(LONGINT hDlg, INTEGER nIDDlgItem, LONGINT lpString, INTEGER nMaxCount);
#define WinAPI_GetDlgItemTextA(hDlg, nIDDlgItem, lpString, nMaxCount)	GetDlgItemTextA(hDlg, nIDDlgItem, lpString, nMaxCount)
__EXTERN INTEGER __STDCALL GetDlgItemTextW(LONGINT hDlg, INTEGER nIDDlgItem, LONGINT lpString, INTEGER nMaxCount);
#define WinAPI_GetDlgItemTextW(hDlg, nIDDlgItem, lpString, nMaxCount)	GetDlgItemTextW(hDlg, nIDDlgItem, lpString, nMaxCount)
__EXTERN INTEGER __STDCALL GetDoubleClickTime(void);
#define WinAPI_GetDoubleClickTime()	GetDoubleClickTime()
#define WinAPI_GetDriveType(lpRootPathName)	GetDriveTypeA(lpRootPathName)
__EXTERN INTEGER __STDCALL GetDriveTypeA(LONGINT lpRootPathName);
#define WinAPI_GetDriveTypeA(lpRootPathName)	GetDriveTypeA(lpRootPathName)
__EXTERN INTEGER __STDCALL GetDriveTypeW(LONGINT lpRootPathName);
#define WinAPI_GetDriveTypeW(lpRootPathName)	GetDriveTypeW(lpRootPathName)
#define WinAPI_GetEnhMetaFile(p0)	GetEnhMetaFileA(p0)
__EXTERN LONGINT __STDCALL GetEnhMetaFileA(LONGINT p0);
#define WinAPI_GetEnhMetaFileA(p0)	GetEnhMetaFileA(p0)
__EXTERN INTEGER __STDCALL GetEnhMetaFileBits(LONGINT p0, INTEGER p1, CHAR *p2);
#define WinAPI_GetEnhMetaFileBits(p0, p1, p2)	GetEnhMetaFileBits(p0, p1, p2)
#define WinAPI_GetEnhMetaFileDescription(p0, p1, p2)	GetEnhMetaFileDescriptionA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetEnhMetaFileDescriptionA(LONGINT p0, INTEGER p1, LONGINT p2);
#define WinAPI_GetEnhMetaFileDescriptionA(p0, p1, p2)	GetEnhMetaFileDescriptionA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetEnhMetaFileDescriptionW(LONGINT p0, INTEGER p1, LONGINT p2);
#define WinAPI_GetEnhMetaFileDescriptionW(p0, p1, p2)	GetEnhMetaFileDescriptionW(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetEnhMetaFileHeader(LONGINT p0, INTEGER p1, WinAPI_ENHMETAHEADER *p2);
#define WinAPI_GetEnhMetaFileHeader(p0, p1, p2)	GetEnhMetaFileHeader(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetEnhMetaFilePaletteEntries(LONGINT p0, INTEGER p1, WinAPI_PALETTEENTRY *p2);
#define WinAPI_GetEnhMetaFilePaletteEntries(p0, p1, p2)	GetEnhMetaFilePaletteEntries(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetEnhMetaFilePixelFormat(LONGINT p0, INTEGER p1, WinAPI_PIXELFORMATDESCRIPTOR *p2);
#define WinAPI_GetEnhMetaFilePixelFormat(p0, p1, p2)	GetEnhMetaFilePixelFormat(p0, p1, p2)
__EXTERN LONGINT __STDCALL GetEnhMetaFileW(LONGINT p0);
#define WinAPI_GetEnhMetaFileW(p0)	GetEnhMetaFileW(p0)
__EXTERN LONGINT __STDCALL GetEnvironmentStrings(void);
#define WinAPI_GetEnvironmentStrings()	GetEnvironmentStrings()
#define WinAPI_GetEnvironmentStringsA()	GetEnvironmentStrings()
__EXTERN LONGINT __STDCALL GetEnvironmentStringsW(void);
#define WinAPI_GetEnvironmentStringsW()	GetEnvironmentStringsW()
#define WinAPI_GetEnvironmentVariable(lpName, lpBuffer, nSize)	GetEnvironmentVariableA(lpName, lpBuffer, nSize)
__EXTERN INTEGER __STDCALL GetEnvironmentVariableA(LONGINT lpName, LONGINT lpBuffer, INTEGER nSize);
#define WinAPI_GetEnvironmentVariableA(lpName, lpBuffer, nSize)	GetEnvironmentVariableA(lpName, lpBuffer, nSize)
__EXTERN INTEGER __STDCALL GetEnvironmentVariableW(LONGINT lpName, LONGINT lpBuffer, INTEGER nSize);
#define WinAPI_GetEnvironmentVariableW(lpName, lpBuffer, nSize)	GetEnvironmentVariableW(lpName, lpBuffer, nSize)
__EXTERN INTEGER __STDCALL GetExitCodeProcess(LONGINT hProcess, INTEGER *lpExitCode);
#define WinAPI_GetExitCodeProcess(hProcess, lpExitCode)	GetExitCodeProcess(hProcess, lpExitCode)
__EXTERN INTEGER __STDCALL GetExitCodeThread(LONGINT hThread, INTEGER *lpExitCode);
#define WinAPI_GetExitCodeThread(hThread, lpExitCode)	GetExitCodeThread(hThread, lpExitCode)
#define WinAPI_GetExpandedName(p0, p1)	GetExpandedNameA(p0, p1)
__EXTERN INTEGER __STDCALL GetExpandedNameA(LONGINT p0, LONGINT p1);
#define WinAPI_GetExpandedNameA(p0, p1)	GetExpandedNameA(p0, p1)
__EXTERN INTEGER __STDCALL GetExpandedNameW(LONGINT p0, LONGINT p1);
#define WinAPI_GetExpandedNameW(p0, p1)	GetExpandedNameW(p0, p1)
#define WinAPI_GetFileAttributes(lpFileName)	GetFileAttributesA(lpFileName)
__EXTERN INTEGER __STDCALL GetFileAttributesA(LONGINT lpFileName);
#define WinAPI_GetFileAttributesA(lpFileName)	GetFileAttributesA(lpFileName)
__EXTERN INTEGER __STDCALL GetFileAttributesW(LONGINT lpFileName);
#define WinAPI_GetFileAttributesW(lpFileName)	GetFileAttributesW(lpFileName)
__EXTERN INTEGER __STDCALL GetFileInformationByHandle(LONGINT hFile, WinAPI_BY_HANDLE_FILE_INFORMATION *lpFileInformation);
#define WinAPI_GetFileInformationByHandle(hFile, lpFileInformation)	GetFileInformationByHandle(hFile, lpFileInformation)
#define WinAPI_GetFileSecurity(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)	GetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)
__EXTERN INTEGER __STDCALL GetFileSecurityA(LONGINT lpFileName, SET RequestedInformation, LONGINT pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinAPI_GetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)	GetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)
__EXTERN INTEGER __STDCALL GetFileSecurityW(LONGINT lpFileName, SET RequestedInformation, LONGINT pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinAPI_GetFileSecurityW(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)	GetFileSecurityW(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)
__EXTERN INTEGER __STDCALL GetFileSize(LONGINT hFile, INTEGER *lpFileSizeHigh);
#define WinAPI_GetFileSize(hFile, lpFileSizeHigh)	GetFileSize(hFile, lpFileSizeHigh)
__EXTERN INTEGER __STDCALL GetFileSizeEx(LONGINT hFile, LONGINT *lpFileSizeHigh);
#define WinAPI_GetFileSizeEx(hFile, lpFileSizeHigh)	GetFileSizeEx(hFile, lpFileSizeHigh)
__EXTERN INTEGER __STDCALL GetFileTime(LONGINT hFile, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpLastAccessTime, WinAPI_FILETIME *lpLastWriteTime);
#define WinAPI_GetFileTime(hFile, lpCreationTime, lpLastAccessTime, lpLastWriteTime)	GetFileTime(hFile, lpCreationTime, lpLastAccessTime, lpLastWriteTime)
__EXTERN INTEGER __STDCALL GetFileType(LONGINT hFile);
#define WinAPI_GetFileType(hFile)	GetFileType(hFile)
#define WinAPI_GetFileVersionInfo(lptstrFilename, dwHandle, dwLen, lpData)	GetFileVersionInfoA(lptstrFilename, dwHandle, dwLen, lpData)
__EXTERN INTEGER __STDCALL GetFileVersionInfoA(LONGINT lptstrFilename, INTEGER dwHandle, INTEGER dwLen, LONGINT lpData);
#define WinAPI_GetFileVersionInfoA(lptstrFilename, dwHandle, dwLen, lpData)	GetFileVersionInfoA(lptstrFilename, dwHandle, dwLen, lpData)
#define WinAPI_GetFileVersionInfoSize(lptstrFilename, lpdwHandle)	GetFileVersionInfoSizeA(lptstrFilename, lpdwHandle)
__EXTERN INTEGER __STDCALL GetFileVersionInfoSizeA(LONGINT lptstrFilename, INTEGER *lpdwHandle);
#define WinAPI_GetFileVersionInfoSizeA(lptstrFilename, lpdwHandle)	GetFileVersionInfoSizeA(lptstrFilename, lpdwHandle)
__EXTERN INTEGER __STDCALL GetFileVersionInfoSizeW(LONGINT lptstrFilename, INTEGER *lpdwHandle);
#define WinAPI_GetFileVersionInfoSizeW(lptstrFilename, lpdwHandle)	GetFileVersionInfoSizeW(lptstrFilename, lpdwHandle)
__EXTERN INTEGER __STDCALL GetFileVersionInfoW(LONGINT lptstrFilename, INTEGER dwHandle, INTEGER dwLen, LONGINT lpData);
#define WinAPI_GetFileVersionInfoW(lptstrFilename, dwHandle, dwLen, lpData)	GetFileVersionInfoW(lptstrFilename, dwHandle, dwLen, lpData)
__EXTERN LONGINT __STDCALL GetFocus(void);
#define WinAPI_GetFocus()	GetFocus()
__EXTERN INTEGER __STDCALL GetFontData(LONGINT p0, INTEGER p1, INTEGER p2, LONGINT p3, INTEGER p4);
#define WinAPI_GetFontData(p0, p1, p2, p3, p4)	GetFontData(p0, p1, p2, p3, p4)
__EXTERN SET __STDCALL GetFontLanguageInfo(LONGINT p0);
#define WinAPI_GetFontLanguageInfo(p0)	GetFontLanguageInfo(p0)
__EXTERN LONGINT __STDCALL GetForegroundWindow(void);
#define WinAPI_GetForegroundWindow()	GetForegroundWindow()
#define WinAPI_GetForm(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)	GetFormA(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetFormA(LONGINT hPrinter, LONGINT pFormName, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetFormA(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)	GetFormA(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetFormW(LONGINT hPrinter, LONGINT pFormName, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetFormW(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)	GetFormW(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)
#define WinAPI_GetFullPathName(lpFileName, nBufferLength, lpBuffer, lpFilePart)	GetFullPathNameA(lpFileName, nBufferLength, lpBuffer, lpFilePart)
__EXTERN INTEGER __STDCALL GetFullPathNameA(LONGINT lpFileName, INTEGER nBufferLength, LONGINT lpBuffer, LONGINT *lpFilePart);
#define WinAPI_GetFullPathNameA(lpFileName, nBufferLength, lpBuffer, lpFilePart)	GetFullPathNameA(lpFileName, nBufferLength, lpBuffer, lpFilePart)
__EXTERN INTEGER __STDCALL GetFullPathNameW(LONGINT lpFileName, INTEGER nBufferLength, LONGINT lpBuffer, LONGINT *lpFilePart);
#define WinAPI_GetFullPathNameW(lpFileName, nBufferLength, lpBuffer, lpFilePart)	GetFullPathNameW(lpFileName, nBufferLength, lpBuffer, lpFilePart)
#define WinAPI_GetGlyphOutline(p0, p1, p2, p3, p4, p5, p6)	GetGlyphOutlineA(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __STDCALL GetGlyphOutlineA(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_GLYPHMETRICS *p3, INTEGER p4, LONGINT p5, WinAPI_MAT2 *p6);
#define WinAPI_GetGlyphOutlineA(p0, p1, p2, p3, p4, p5, p6)	GetGlyphOutlineA(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __STDCALL GetGlyphOutlineW(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_GLYPHMETRICS *p3, INTEGER p4, LONGINT p5, WinAPI_MAT2 *p6);
#define WinAPI_GetGlyphOutlineW(p0, p1, p2, p3, p4, p5, p6)	GetGlyphOutlineW(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __STDCALL GetGraphicsMode(LONGINT p0);
#define WinAPI_GetGraphicsMode(p0)	GetGraphicsMode(p0)
__EXTERN INTEGER __STDCALL GetHandleInformation(LONGINT hObject, SET *lpdwFlags);
#define WinAPI_GetHandleInformation(hObject, lpdwFlags)	GetHandleInformation(hObject, lpdwFlags)
#define WinAPI_GetICMProfile(p0, p1, p2)	GetICMProfileA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetICMProfileA(LONGINT p0, INTEGER *p1, LONGINT p2);
#define WinAPI_GetICMProfileA(p0, p1, p2)	GetICMProfileA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetICMProfileW(LONGINT p0, INTEGER *p1, LONGINT p2);
#define WinAPI_GetICMProfileW(p0, p1, p2)	GetICMProfileW(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetIconInfo(LONGINT hIcon, WinAPI_ICONINFO *piconinfo);
#define WinAPI_GetIconInfo(hIcon, piconinfo)	GetIconInfo(hIcon, piconinfo)
__EXTERN INTEGER __STDCALL GetInputState(void);
#define WinAPI_GetInputState()	GetInputState()
#define WinAPI_GetJob(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)	GetJobA(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetJobA(LONGINT hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetJobA(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)	GetJobA(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetJobW(LONGINT hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetJobW(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)	GetJobW(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetKBCodePage(void);
#define WinAPI_GetKBCodePage()	GetKBCodePage()
__EXTERN INTEGER __STDCALL GetKernelObjectSecurity(LONGINT Handle, SET RequestedInformation, LONGINT pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinAPI_GetKernelObjectSecurity(Handle, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)	GetKernelObjectSecurity(Handle, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)
#define WinAPI_GetKerningPairs(p0, p1, p2)	GetKerningPairsA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetKerningPairsA(LONGINT p0, INTEGER p1, WinAPI_KERNINGPAIR *p2);
#define WinAPI_GetKerningPairsA(p0, p1, p2)	GetKerningPairsA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetKerningPairsW(LONGINT p0, INTEGER p1, WinAPI_KERNINGPAIR *p2);
#define WinAPI_GetKerningPairsW(p0, p1, p2)	GetKerningPairsW(p0, p1, p2)
#define WinAPI_GetKeyNameText(lParam, lpString, nSize)	GetKeyNameTextA(lParam, lpString, nSize)
__EXTERN INTEGER __STDCALL GetKeyNameTextA(INTEGER lParam, LONGINT lpString, INTEGER nSize);
#define WinAPI_GetKeyNameTextA(lParam, lpString, nSize)	GetKeyNameTextA(lParam, lpString, nSize)
__EXTERN INTEGER __STDCALL GetKeyNameTextW(INTEGER lParam, LONGINT lpString, INTEGER nSize);
#define WinAPI_GetKeyNameTextW(lParam, lpString, nSize)	GetKeyNameTextW(lParam, lpString, nSize)
__EXTERN SHORTINT __STDCALL GetKeyState(INTEGER nVirtKey);
#define WinAPI_GetKeyState(nVirtKey)	GetKeyState(nVirtKey)
__EXTERN LONGINT __STDCALL GetKeyboardLayout(INTEGER dwLayout);
#define WinAPI_GetKeyboardLayout(dwLayout)	GetKeyboardLayout(dwLayout)
__EXTERN INTEGER __STDCALL GetKeyboardLayoutList(INTEGER nBuff, LONGINT *lpList);
#define WinAPI_GetKeyboardLayoutList(nBuff, lpList)	GetKeyboardLayoutList(nBuff, lpList)
#define WinAPI_GetKeyboardLayoutName(pwszKLID)	GetKeyboardLayoutNameA(pwszKLID)
__EXTERN INTEGER __STDCALL GetKeyboardLayoutNameA(LONGINT pwszKLID);
#define WinAPI_GetKeyboardLayoutNameA(pwszKLID)	GetKeyboardLayoutNameA(pwszKLID)
__EXTERN INTEGER __STDCALL GetKeyboardLayoutNameW(LONGINT pwszKLID);
#define WinAPI_GetKeyboardLayoutNameW(pwszKLID)	GetKeyboardLayoutNameW(pwszKLID)
__EXTERN INTEGER __STDCALL GetKeyboardState(CHAR *lpKeyState);
#define WinAPI_GetKeyboardState(lpKeyState)	GetKeyboardState(lpKeyState)
__EXTERN INTEGER __STDCALL GetKeyboardType(INTEGER nTypeFlag);
#define WinAPI_GetKeyboardType(nTypeFlag)	GetKeyboardType(nTypeFlag)
__EXTERN INTEGER __STDCALL GetLargestConsoleWindowSize(LONGINT hConsoleOutput);
#define WinAPI_GetLargestConsoleWindowSize(hConsoleOutput)	GetLargestConsoleWindowSize(hConsoleOutput)
__EXTERN LONGINT __STDCALL GetLastActivePopup(LONGINT hWnd);
#define WinAPI_GetLastActivePopup(hWnd)	GetLastActivePopup(hWnd)
__EXTERN INTEGER __STDCALL GetLastError(void);
#define WinAPI_GetLastError()	GetLastError()
__EXTERN INTEGER __STDCALL GetLengthSid(LONGINT pSid);
#define WinAPI_GetLengthSid(pSid)	GetLengthSid(pSid)
__EXTERN void __STDCALL GetLocalTime(WinAPI_SYSTEMTIME *lpSystemTime);
#define WinAPI_GetLocalTime(lpSystemTime)	GetLocalTime(lpSystemTime)
#define WinAPI_GetLocaleInfo(Locale, LCType, lpLCData, cchData)	GetLocaleInfoA(Locale, LCType, lpLCData, cchData)
__EXTERN INTEGER __STDCALL GetLocaleInfoA(INTEGER Locale, INTEGER LCType, LONGINT lpLCData, INTEGER cchData);
#define WinAPI_GetLocaleInfoA(Locale, LCType, lpLCData, cchData)	GetLocaleInfoA(Locale, LCType, lpLCData, cchData)
__EXTERN INTEGER __STDCALL GetLocaleInfoW(INTEGER Locale, INTEGER LCType, LONGINT lpLCData, INTEGER cchData);
#define WinAPI_GetLocaleInfoW(Locale, LCType, lpLCData, cchData)	GetLocaleInfoW(Locale, LCType, lpLCData, cchData)
#define WinAPI_GetLogColorSpace(p0, p1, p2)	GetLogColorSpaceA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetLogColorSpaceA(LONGINT p0, WinAPI_LOGCOLORSPACEA *p1, INTEGER p2);
#define WinAPI_GetLogColorSpaceA(p0, p1, p2)	GetLogColorSpaceA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetLogColorSpaceW(LONGINT p0, WinAPI_LOGCOLORSPACEW *p1, INTEGER p2);
#define WinAPI_GetLogColorSpaceW(p0, p1, p2)	GetLogColorSpaceW(p0, p1, p2)
#define WinAPI_GetLogicalDriveStrings(nBufferLength, lpBuffer)	GetLogicalDriveStringsA(nBufferLength, lpBuffer)
__EXTERN INTEGER __STDCALL GetLogicalDriveStringsA(INTEGER nBufferLength, LONGINT lpBuffer);
#define WinAPI_GetLogicalDriveStringsA(nBufferLength, lpBuffer)	GetLogicalDriveStringsA(nBufferLength, lpBuffer)
__EXTERN INTEGER __STDCALL GetLogicalDriveStringsW(INTEGER nBufferLength, LONGINT lpBuffer);
#define WinAPI_GetLogicalDriveStringsW(nBufferLength, lpBuffer)	GetLogicalDriveStringsW(nBufferLength, lpBuffer)
__EXTERN INTEGER __STDCALL GetLogicalDrives(void);
#define WinAPI_GetLogicalDrives()	GetLogicalDrives()
__EXTERN INTEGER __STDCALL GetMailslotInfo(LONGINT hMailslot, INTEGER *lpMaxMessageSize, INTEGER *lpNextSize, INTEGER *lpMessageCount, INTEGER *lpReadTimeout);
#define WinAPI_GetMailslotInfo(hMailslot, lpMaxMessageSize, lpNextSize, lpMessageCount, lpReadTimeout)	GetMailslotInfo(hMailslot, lpMaxMessageSize, lpNextSize, lpMessageCount, lpReadTimeout)
__EXTERN INTEGER __STDCALL GetMapMode(LONGINT p0);
#define WinAPI_GetMapMode(p0)	GetMapMode(p0)
__EXTERN LONGINT __STDCALL GetMenu(LONGINT hWnd);
#define WinAPI_GetMenu(hWnd)	GetMenu(hWnd)
__EXTERN INTEGER __STDCALL GetMenuCheckMarkDimensions(void);
#define WinAPI_GetMenuCheckMarkDimensions()	GetMenuCheckMarkDimensions()
__EXTERN INTEGER __STDCALL GetMenuContextHelpId(LONGINT p0);
#define WinAPI_GetMenuContextHelpId(p0)	GetMenuContextHelpId(p0)
__EXTERN INTEGER __STDCALL GetMenuDefaultItem(LONGINT hMenu, INTEGER fByPos, SET gmdiFlags);
#define WinAPI_GetMenuDefaultItem(hMenu, fByPos, gmdiFlags)	GetMenuDefaultItem(hMenu, fByPos, gmdiFlags)
__EXTERN INTEGER __STDCALL GetMenuItemCount(LONGINT hMenu);
#define WinAPI_GetMenuItemCount(hMenu)	GetMenuItemCount(hMenu)
__EXTERN INTEGER __STDCALL GetMenuItemID(LONGINT hMenu, INTEGER nPos);
#define WinAPI_GetMenuItemID(hMenu, nPos)	GetMenuItemID(hMenu, nPos)
#define WinAPI_GetMenuItemInfo(p0, p1, p2, p3)	GetMenuItemInfoA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetMenuItemInfoA(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOA *p3);
#define WinAPI_GetMenuItemInfoA(p0, p1, p2, p3)	GetMenuItemInfoA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetMenuItemInfoW(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOW *p3);
#define WinAPI_GetMenuItemInfoW(p0, p1, p2, p3)	GetMenuItemInfoW(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetMenuItemRect(LONGINT hWnd, LONGINT hMenu, INTEGER uItem, WinAPI_RECT *lprcItem);
#define WinAPI_GetMenuItemRect(hWnd, hMenu, uItem, lprcItem)	GetMenuItemRect(hWnd, hMenu, uItem, lprcItem)
__EXTERN INTEGER __STDCALL GetMenuState(LONGINT hMenu, INTEGER uId, SET uFlags);
#define WinAPI_GetMenuState(hMenu, uId, uFlags)	GetMenuState(hMenu, uId, uFlags)
#define WinAPI_GetMenuString(hMenu, uIDItem, lpString, nMaxCount, uFlag)	GetMenuStringA(hMenu, uIDItem, lpString, nMaxCount, uFlag)
__EXTERN INTEGER __STDCALL GetMenuStringA(LONGINT hMenu, INTEGER uIDItem, LONGINT lpString, INTEGER nMaxCount, SET uFlag);
#define WinAPI_GetMenuStringA(hMenu, uIDItem, lpString, nMaxCount, uFlag)	GetMenuStringA(hMenu, uIDItem, lpString, nMaxCount, uFlag)
__EXTERN INTEGER __STDCALL GetMenuStringW(LONGINT hMenu, INTEGER uIDItem, LONGINT lpString, INTEGER nMaxCount, SET uFlag);
#define WinAPI_GetMenuStringW(hMenu, uIDItem, lpString, nMaxCount, uFlag)	GetMenuStringW(hMenu, uIDItem, lpString, nMaxCount, uFlag)
#define WinAPI_GetMessage(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)	GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)
__EXTERN INTEGER __STDCALL GetMessageA(WinAPI_MSG *lpMsg, LONGINT hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax);
#define WinAPI_GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)	GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)
__EXTERN INTEGER __STDCALL GetMessageExtraInfo(void);
#define WinAPI_GetMessageExtraInfo()	GetMessageExtraInfo()
__EXTERN INTEGER __STDCALL GetMessagePos(void);
#define WinAPI_GetMessagePos()	GetMessagePos()
__EXTERN INTEGER __STDCALL GetMessageTime(void);
#define WinAPI_GetMessageTime()	GetMessageTime()
__EXTERN INTEGER __STDCALL GetMessageW(WinAPI_MSG *lpMsg, LONGINT hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax);
#define WinAPI_GetMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)	GetMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)
#define WinAPI_GetMetaFile(p0)	GetMetaFileA(p0)
__EXTERN LONGINT __STDCALL GetMetaFileA(LONGINT p0);
#define WinAPI_GetMetaFileA(p0)	GetMetaFileA(p0)
__EXTERN INTEGER __STDCALL GetMetaFileBitsEx(LONGINT p0, INTEGER p1, BYTE *p2);
#define WinAPI_GetMetaFileBitsEx(p0, p1, p2)	GetMetaFileBitsEx(p0, p1, p2)
__EXTERN LONGINT __STDCALL GetMetaFileW(LONGINT p0);
#define WinAPI_GetMetaFileW(p0)	GetMetaFileW(p0)
__EXTERN INTEGER __STDCALL GetMetaRgn(LONGINT p0, LONGINT p1);
#define WinAPI_GetMetaRgn(p0, p1)	GetMetaRgn(p0, p1)
__EXTERN INTEGER __STDCALL GetMiterLimit(LONGINT p0, SHORTREAL *p1);
#define WinAPI_GetMiterLimit(p0, p1)	GetMiterLimit(p0, p1)
#define WinAPI_GetModuleFileName(hModule, lpFilename, nSize)	GetModuleFileNameA(hModule, lpFilename, nSize)
__EXTERN INTEGER __STDCALL GetModuleFileNameA(LONGINT hModule, LONGINT lpFilename, INTEGER nSize);
#define WinAPI_GetModuleFileNameA(hModule, lpFilename, nSize)	GetModuleFileNameA(hModule, lpFilename, nSize)
__EXTERN INTEGER __STDCALL GetModuleFileNameW(LONGINT hModule, LONGINT lpFilename, INTEGER nSize);
#define WinAPI_GetModuleFileNameW(hModule, lpFilename, nSize)	GetModuleFileNameW(hModule, lpFilename, nSize)
#define WinAPI_GetModuleHandle(lpModuleName)	GetModuleHandleA(lpModuleName)
__EXTERN LONGINT __STDCALL GetModuleHandleA(LONGINT lpModuleName);
#define WinAPI_GetModuleHandleA(lpModuleName)	GetModuleHandleA(lpModuleName)
__EXTERN LONGINT __STDCALL GetModuleHandleW(LONGINT lpModuleName);
#define WinAPI_GetModuleHandleW(lpModuleName)	GetModuleHandleW(lpModuleName)
#define WinAPI_GetNamedPipeHandleState(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)	GetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)
__EXTERN INTEGER __STDCALL GetNamedPipeHandleStateA(LONGINT hNamedPipe, INTEGER *lpState, INTEGER *lpCurInstances, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout, LONGINT lpUserName, INTEGER nMaxUserNameSize);
#define WinAPI_GetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)	GetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)
__EXTERN INTEGER __STDCALL GetNamedPipeHandleStateW(LONGINT hNamedPipe, INTEGER *lpState, INTEGER *lpCurInstances, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout, LONGINT lpUserName, INTEGER nMaxUserNameSize);
#define WinAPI_GetNamedPipeHandleStateW(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)	GetNamedPipeHandleStateW(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)
__EXTERN INTEGER __STDCALL GetNamedPipeInfo(LONGINT hNamedPipe, INTEGER *lpFlags, INTEGER *lpOutBufferSize, INTEGER *lpInBufferSize, INTEGER *lpMaxInstances);
#define WinAPI_GetNamedPipeInfo(hNamedPipe, lpFlags, lpOutBufferSize, lpInBufferSize, lpMaxInstances)	GetNamedPipeInfo(hNamedPipe, lpFlags, lpOutBufferSize, lpInBufferSize, lpMaxInstances)
__EXTERN INTEGER __STDCALL GetNearestColor(LONGINT p0, INTEGER p1);
#define WinAPI_GetNearestColor(p0, p1)	GetNearestColor(p0, p1)
__EXTERN INTEGER __STDCALL GetNearestPaletteIndex(LONGINT p0, INTEGER p1);
#define WinAPI_GetNearestPaletteIndex(p0, p1)	GetNearestPaletteIndex(p0, p1)
__EXTERN LONGINT __STDCALL GetNextDlgGroupItem(LONGINT hDlg, LONGINT hCtl, INTEGER bPrevious);
#define WinAPI_GetNextDlgGroupItem(hDlg, hCtl, bPrevious)	GetNextDlgGroupItem(hDlg, hCtl, bPrevious)
__EXTERN LONGINT __STDCALL GetNextDlgTabItem(LONGINT hDlg, LONGINT hCtl, INTEGER bPrevious);
#define WinAPI_GetNextDlgTabItem(hDlg, hCtl, bPrevious)	GetNextDlgTabItem(hDlg, hCtl, bPrevious)
#define WinAPI_GetNumberFormat(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)	GetNumberFormatA(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)
__EXTERN INTEGER __STDCALL GetNumberFormatA(INTEGER Locale, SET dwFlags, LONGINT lpValue, WinAPI_NUMBERFMTA *lpFormat, LONGINT lpNumberStr, INTEGER cchNumber);
#define WinAPI_GetNumberFormatA(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)	GetNumberFormatA(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)
__EXTERN INTEGER __STDCALL GetNumberFormatW(INTEGER Locale, SET dwFlags, LONGINT lpValue, WinAPI_NUMBERFMTW *lpFormat, LONGINT lpNumberStr, INTEGER cchNumber);
#define WinAPI_GetNumberFormatW(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)	GetNumberFormatW(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)
__EXTERN INTEGER __STDCALL GetNumberOfConsoleInputEvents(LONGINT hConsoleInput, INTEGER *lpNumberOfEvents);
#define WinAPI_GetNumberOfConsoleInputEvents(hConsoleInput, lpNumberOfEvents)	GetNumberOfConsoleInputEvents(hConsoleInput, lpNumberOfEvents)
__EXTERN INTEGER __STDCALL GetNumberOfConsoleMouseButtons(INTEGER *lpNumberOfMouseButtons);
#define WinAPI_GetNumberOfConsoleMouseButtons(lpNumberOfMouseButtons)	GetNumberOfConsoleMouseButtons(lpNumberOfMouseButtons)
__EXTERN INTEGER __STDCALL GetNumberOfEventLogRecords(LONGINT hEventLog, INTEGER *NumberOfRecords);
#define WinAPI_GetNumberOfEventLogRecords(hEventLog, NumberOfRecords)	GetNumberOfEventLogRecords(hEventLog, NumberOfRecords)
__EXTERN INTEGER __STDCALL GetOEMCP(void);
#define WinAPI_GetOEMCP()	GetOEMCP()
#define WinAPI_GetObject(p0, p1, p2)	GetObjectA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetObjectA(LONGINT p0, INTEGER p1, LONGINT p2);
#define WinAPI_GetObjectA(p0, p1, p2)	GetObjectA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetObjectType(LONGINT h);
#define WinAPI_GetObjectType(h)	GetObjectType(h)
__EXTERN INTEGER __STDCALL GetObjectW(LONGINT p0, INTEGER p1, LONGINT p2);
#define WinAPI_GetObjectW(p0, p1, p2)	GetObjectW(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetOldestEventLogRecord(LONGINT hEventLog, INTEGER *OldestRecord);
#define WinAPI_GetOldestEventLogRecord(hEventLog, OldestRecord)	GetOldestEventLogRecord(hEventLog, OldestRecord)
__EXTERN LONGINT __STDCALL GetOpenClipboardWindow(void);
#define WinAPI_GetOpenClipboardWindow()	GetOpenClipboardWindow()
#define WinAPI_GetOutlineTextMetrics(p0, p1, p2)	GetOutlineTextMetricsA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetOutlineTextMetricsA(LONGINT p0, INTEGER p1, WinAPI_OUTLINETEXTMETRICA *p2);
#define WinAPI_GetOutlineTextMetricsA(p0, p1, p2)	GetOutlineTextMetricsA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetOutlineTextMetricsW(LONGINT p0, INTEGER p1, WinAPI_OUTLINETEXTMETRICW *p2);
#define WinAPI_GetOutlineTextMetricsW(p0, p1, p2)	GetOutlineTextMetricsW(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetOverlappedResult(LONGINT hFile, WinAPI_OVERLAPPED *lpOverlapped, INTEGER *lpNumberOfBytesTransferred, INTEGER bWait);
#define WinAPI_GetOverlappedResult(hFile, lpOverlapped, lpNumberOfBytesTransferred, bWait)	GetOverlappedResult(hFile, lpOverlapped, lpNumberOfBytesTransferred, bWait)
__EXTERN INTEGER __STDCALL GetPaletteEntries(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
#define WinAPI_GetPaletteEntries(p0, p1, p2, p3)	GetPaletteEntries(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL GetParent(LONGINT hWnd);
#define WinAPI_GetParent(hWnd)	GetParent(hWnd)
__EXTERN INTEGER __STDCALL GetPath(LONGINT p0, WinAPI_POINT *p1, CHAR *p2, INTEGER p3);
#define WinAPI_GetPath(p0, p1, p2, p3)	GetPath(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetPixel(LONGINT p0, INTEGER p1, INTEGER p2);
#define WinAPI_GetPixel(p0, p1, p2)	GetPixel(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetPixelFormat(LONGINT p0);
#define WinAPI_GetPixelFormat(p0)	GetPixelFormat(p0)
__EXTERN INTEGER __STDCALL GetPolyFillMode(LONGINT p0);
#define WinAPI_GetPolyFillMode(p0)	GetPolyFillMode(p0)
#define WinAPI_GetPrintProcessorDirectory(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)	GetPrintProcessorDirectoryA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetPrintProcessorDirectoryA(LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrintProcessorDirectoryA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)	GetPrintProcessorDirectoryA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetPrintProcessorDirectoryW(LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrintProcessorDirectoryW(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)	GetPrintProcessorDirectoryW(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)
#define WinAPI_GetPrinter(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)	GetPrinterA(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetPrinterA(LONGINT hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterA(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)	GetPrinterA(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)
#define WinAPI_GetPrinterData(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)	GetPrinterDataA(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)
__EXTERN INTEGER __STDCALL GetPrinterDataA(LONGINT hPrinter, LONGINT pValueName, INTEGER *pType, CHAR *pData, INTEGER nSize, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterDataA(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)	GetPrinterDataA(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)
__EXTERN INTEGER __STDCALL GetPrinterDataW(LONGINT hPrinter, LONGINT pValueName, INTEGER *pType, CHAR *pData, INTEGER nSize, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterDataW(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)	GetPrinterDataW(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)
#define WinAPI_GetPrinterDriver(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)	GetPrinterDriverA(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetPrinterDriverA(LONGINT hPrinter, LONGINT pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterDriverA(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)	GetPrinterDriverA(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)
#define WinAPI_GetPrinterDriverDirectory(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)	GetPrinterDriverDirectoryA(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetPrinterDriverDirectoryA(LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pDriverDirectory, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterDriverDirectoryA(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)	GetPrinterDriverDirectoryA(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetPrinterDriverDirectoryW(LONGINT pName, LONGINT pEnvironment, INTEGER Level, CHAR *pDriverDirectory, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterDriverDirectoryW(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)	GetPrinterDriverDirectoryW(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetPrinterDriverW(LONGINT hPrinter, LONGINT pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterDriverW(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)	GetPrinterDriverW(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetPrinterW(LONGINT hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterW(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)	GetPrinterW(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)
__EXTERN INTEGER __STDCALL GetPriorityClass(LONGINT hProcess);
#define WinAPI_GetPriorityClass(hProcess)	GetPriorityClass(hProcess)
__EXTERN INTEGER __STDCALL GetPriorityClipboardFormat(INTEGER *paFormatPriorityList, INTEGER cFormats);
#define WinAPI_GetPriorityClipboardFormat(paFormatPriorityList, cFormats)	GetPriorityClipboardFormat(paFormatPriorityList, cFormats)
__EXTERN INTEGER __STDCALL GetPrivateObjectSecurity(LONGINT ObjectDescriptor, SET SecurityInformation, LONGINT ResultantDescriptor, INTEGER DescriptorLength, INTEGER *ReturnLength);
#define WinAPI_GetPrivateObjectSecurity(ObjectDescriptor, SecurityInformation, ResultantDescriptor, DescriptorLength, ReturnLength)	GetPrivateObjectSecurity(ObjectDescriptor, SecurityInformation, ResultantDescriptor, DescriptorLength, ReturnLength)
#define WinAPI_GetPrivateProfileInt(lpAppName, lpKeyName, nDefault, lpFileName)	GetPrivateProfileIntA(lpAppName, lpKeyName, nDefault, lpFileName)
__EXTERN INTEGER __STDCALL GetPrivateProfileIntA(LONGINT lpAppName, LONGINT lpKeyName, INTEGER nDefault, LONGINT lpFileName);
#define WinAPI_GetPrivateProfileIntA(lpAppName, lpKeyName, nDefault, lpFileName)	GetPrivateProfileIntA(lpAppName, lpKeyName, nDefault, lpFileName)
__EXTERN INTEGER __STDCALL GetPrivateProfileIntW(LONGINT lpAppName, LONGINT lpKeyName, INTEGER nDefault, LONGINT lpFileName);
#define WinAPI_GetPrivateProfileIntW(lpAppName, lpKeyName, nDefault, lpFileName)	GetPrivateProfileIntW(lpAppName, lpKeyName, nDefault, lpFileName)
#define WinAPI_GetPrivateProfileSection(lpAppName, lpReturnedString, nSize, lpFileName)	GetPrivateProfileSectionA(lpAppName, lpReturnedString, nSize, lpFileName)
__EXTERN INTEGER __STDCALL GetPrivateProfileSectionA(LONGINT lpAppName, LONGINT lpReturnedString, INTEGER nSize, LONGINT lpFileName);
#define WinAPI_GetPrivateProfileSectionA(lpAppName, lpReturnedString, nSize, lpFileName)	GetPrivateProfileSectionA(lpAppName, lpReturnedString, nSize, lpFileName)
#define WinAPI_GetPrivateProfileSectionNames(lpszReturnBuffer, nSize, lpFileName)	GetPrivateProfileSectionNamesA(lpszReturnBuffer, nSize, lpFileName)
__EXTERN INTEGER __STDCALL GetPrivateProfileSectionNamesA(LONGINT lpszReturnBuffer, INTEGER nSize, LONGINT lpFileName);
#define WinAPI_GetPrivateProfileSectionNamesA(lpszReturnBuffer, nSize, lpFileName)	GetPrivateProfileSectionNamesA(lpszReturnBuffer, nSize, lpFileName)
__EXTERN INTEGER __STDCALL GetPrivateProfileSectionNamesW(LONGINT lpszReturnBuffer, INTEGER nSize, LONGINT lpFileName);
#define WinAPI_GetPrivateProfileSectionNamesW(lpszReturnBuffer, nSize, lpFileName)	GetPrivateProfileSectionNamesW(lpszReturnBuffer, nSize, lpFileName)
__EXTERN INTEGER __STDCALL GetPrivateProfileSectionW(LONGINT lpAppName, LONGINT lpReturnedString, INTEGER nSize, LONGINT lpFileName);
#define WinAPI_GetPrivateProfileSectionW(lpAppName, lpReturnedString, nSize, lpFileName)	GetPrivateProfileSectionW(lpAppName, lpReturnedString, nSize, lpFileName)
#define WinAPI_GetPrivateProfileString(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)	GetPrivateProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)
__EXTERN INTEGER __STDCALL GetPrivateProfileStringA(LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpDefault, LONGINT lpReturnedString, INTEGER nSize, LONGINT lpFileName);
#define WinAPI_GetPrivateProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)	GetPrivateProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)
__EXTERN INTEGER __STDCALL GetPrivateProfileStringW(LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpDefault, LONGINT lpReturnedString, INTEGER nSize, LONGINT lpFileName);
#define WinAPI_GetPrivateProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)	GetPrivateProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)
#define WinAPI_GetPrivateProfileStruct(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	GetPrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN INTEGER __STDCALL GetPrivateProfileStructA(LONGINT lpszSection, LONGINT lpszKey, LONGINT lpStruct, INTEGER uSizeStruct, LONGINT szFile);
#define WinAPI_GetPrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	GetPrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN INTEGER __STDCALL GetPrivateProfileStructW(LONGINT lpszSection, LONGINT lpszKey, LONGINT lpStruct, INTEGER uSizeStruct, LONGINT szFile);
#define WinAPI_GetPrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	GetPrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN WinAPI_FARPROC __STDCALL GetProcAddress(LONGINT hModule, LONGINT lpProcName);
#define WinAPI_GetProcAddress(hModule, lpProcName)	GetProcAddress(hModule, lpProcName)
__EXTERN INTEGER __STDCALL GetProcessAffinityMask(LONGINT hProcess, INTEGER *lpProcessAffinityMask, INTEGER *lpSystemAffinityMask);
#define WinAPI_GetProcessAffinityMask(hProcess, lpProcessAffinityMask, lpSystemAffinityMask)	GetProcessAffinityMask(hProcess, lpProcessAffinityMask, lpSystemAffinityMask)
__EXTERN LONGINT __STDCALL GetProcessHeap(void);
#define WinAPI_GetProcessHeap()	GetProcessHeap()
__EXTERN INTEGER __STDCALL GetProcessHeaps(INTEGER NumberOfHeaps, LONGINT *ProcessHeaps);
#define WinAPI_GetProcessHeaps(NumberOfHeaps, ProcessHeaps)	GetProcessHeaps(NumberOfHeaps, ProcessHeaps)
__EXTERN INTEGER __STDCALL GetProcessShutdownParameters(INTEGER *lpdwLevel, SET *lpdwFlags);
#define WinAPI_GetProcessShutdownParameters(lpdwLevel, lpdwFlags)	GetProcessShutdownParameters(lpdwLevel, lpdwFlags)
__EXTERN INTEGER __STDCALL GetProcessTimes(LONGINT hProcess, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpExitTime, WinAPI_FILETIME *lpKernelTime, WinAPI_FILETIME *lpUserTime);
#define WinAPI_GetProcessTimes(hProcess, lpCreationTime, lpExitTime, lpKernelTime, lpUserTime)	GetProcessTimes(hProcess, lpCreationTime, lpExitTime, lpKernelTime, lpUserTime)
__EXTERN INTEGER __STDCALL GetProcessVersion(INTEGER ProcessId);
#define WinAPI_GetProcessVersion(ProcessId)	GetProcessVersion(ProcessId)
__EXTERN LONGINT __STDCALL GetProcessWindowStation(void);
#define WinAPI_GetProcessWindowStation()	GetProcessWindowStation()
__EXTERN INTEGER __STDCALL GetProcessWorkingSetSize(LONGINT hProcess, INTEGER *lpMinimumWorkingSetSize, INTEGER *lpMaximumWorkingSetSize);
#define WinAPI_GetProcessWorkingSetSize(hProcess, lpMinimumWorkingSetSize, lpMaximumWorkingSetSize)	GetProcessWorkingSetSize(hProcess, lpMinimumWorkingSetSize, lpMaximumWorkingSetSize)
#define WinAPI_GetProfileInt(lpAppName, lpKeyName, nDefault)	GetProfileIntA(lpAppName, lpKeyName, nDefault)
__EXTERN INTEGER __STDCALL GetProfileIntA(LONGINT lpAppName, LONGINT lpKeyName, INTEGER nDefault);
#define WinAPI_GetProfileIntA(lpAppName, lpKeyName, nDefault)	GetProfileIntA(lpAppName, lpKeyName, nDefault)
__EXTERN INTEGER __STDCALL GetProfileIntW(LONGINT lpAppName, LONGINT lpKeyName, INTEGER nDefault);
#define WinAPI_GetProfileIntW(lpAppName, lpKeyName, nDefault)	GetProfileIntW(lpAppName, lpKeyName, nDefault)
#define WinAPI_GetProfileSection(lpAppName, lpReturnedString, nSize)	GetProfileSectionA(lpAppName, lpReturnedString, nSize)
__EXTERN INTEGER __STDCALL GetProfileSectionA(LONGINT lpAppName, LONGINT lpReturnedString, INTEGER nSize);
#define WinAPI_GetProfileSectionA(lpAppName, lpReturnedString, nSize)	GetProfileSectionA(lpAppName, lpReturnedString, nSize)
__EXTERN INTEGER __STDCALL GetProfileSectionW(LONGINT lpAppName, LONGINT lpReturnedString, INTEGER nSize);
#define WinAPI_GetProfileSectionW(lpAppName, lpReturnedString, nSize)	GetProfileSectionW(lpAppName, lpReturnedString, nSize)
#define WinAPI_GetProfileString(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)	GetProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)
__EXTERN INTEGER __STDCALL GetProfileStringA(LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpDefault, LONGINT lpReturnedString, INTEGER nSize);
#define WinAPI_GetProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)	GetProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)
__EXTERN INTEGER __STDCALL GetProfileStringW(LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpDefault, LONGINT lpReturnedString, INTEGER nSize);
#define WinAPI_GetProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)	GetProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)
#define WinAPI_GetProp(hWnd, lpString)	GetPropA(hWnd, lpString)
__EXTERN LONGINT __STDCALL GetPropA(LONGINT hWnd, LONGINT lpString);
#define WinAPI_GetPropA(hWnd, lpString)	GetPropA(hWnd, lpString)
__EXTERN LONGINT __STDCALL GetPropW(LONGINT hWnd, LONGINT lpString);
#define WinAPI_GetPropW(hWnd, lpString)	GetPropW(hWnd, lpString)
__EXTERN INTEGER __STDCALL GetQueueStatus(SET flags);
#define WinAPI_GetQueueStatus(flags)	GetQueueStatus(flags)
__EXTERN INTEGER __STDCALL GetQueuedCompletionStatus(LONGINT CompletionPort, INTEGER *lpNumberOfBytesTransferred, INTEGER *lpCompletionKey, WinAPI_PtrOVERLAPPED *lpOverlapped, INTEGER dwMilliseconds);
#define WinAPI_GetQueuedCompletionStatus(CompletionPort, lpNumberOfBytesTransferred, lpCompletionKey, lpOverlapped, dwMilliseconds)	GetQueuedCompletionStatus(CompletionPort, lpNumberOfBytesTransferred, lpCompletionKey, lpOverlapped, dwMilliseconds)
__EXTERN INTEGER __STDCALL GetROP2(LONGINT p0);
#define WinAPI_GetROP2(p0)	GetROP2(p0)
__EXTERN INTEGER __STDCALL GetRasterizerCaps(WinAPI_RASTERIZER_STATUS *p0, INTEGER p1);
#define WinAPI_GetRasterizerCaps(p0, p1)	GetRasterizerCaps(p0, p1)
__EXTERN INTEGER __STDCALL GetRegionData(LONGINT p0, INTEGER p1, WinAPI_RGNDATA *p2);
#define WinAPI_GetRegionData(p0, p1, p2)	GetRegionData(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetRgnBox(LONGINT p0, WinAPI_RECT *p1);
#define WinAPI_GetRgnBox(p0, p1)	GetRgnBox(p0, p1)
__EXTERN INTEGER __STDCALL GetScrollInfo(LONGINT p0, INTEGER p1, WinAPI_SCROLLINFO *p2);
#define WinAPI_GetScrollInfo(p0, p1, p2)	GetScrollInfo(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetScrollPos(LONGINT hWnd, INTEGER nBar);
#define WinAPI_GetScrollPos(hWnd, nBar)	GetScrollPos(hWnd, nBar)
__EXTERN INTEGER __STDCALL GetScrollRange(LONGINT hWnd, INTEGER nBar, INTEGER *lpMinPos, INTEGER *lpMaxPos);
#define WinAPI_GetScrollRange(hWnd, nBar, lpMinPos, lpMaxPos)	GetScrollRange(hWnd, nBar, lpMinPos, lpMaxPos)
__EXTERN INTEGER __STDCALL GetSecurityDescriptorControl(LONGINT pSecurityDescriptor, SHORTINT *pControl, INTEGER *lpdwRevision);
#define WinAPI_GetSecurityDescriptorControl(pSecurityDescriptor, pControl, lpdwRevision)	GetSecurityDescriptorControl(pSecurityDescriptor, pControl, lpdwRevision)
__EXTERN INTEGER __STDCALL GetSecurityDescriptorDacl(LONGINT pSecurityDescriptor, INTEGER *lpbDaclPresent, WinAPI_PtrACL *pDacl, INTEGER *lpbDaclDefaulted);
#define WinAPI_GetSecurityDescriptorDacl(pSecurityDescriptor, lpbDaclPresent, pDacl, lpbDaclDefaulted)	GetSecurityDescriptorDacl(pSecurityDescriptor, lpbDaclPresent, pDacl, lpbDaclDefaulted)
__EXTERN INTEGER __STDCALL GetSecurityDescriptorGroup(LONGINT pSecurityDescriptor, LONGINT *pGroup, INTEGER *lpbGroupDefaulted);
#define WinAPI_GetSecurityDescriptorGroup(pSecurityDescriptor, pGroup, lpbGroupDefaulted)	GetSecurityDescriptorGroup(pSecurityDescriptor, pGroup, lpbGroupDefaulted)
__EXTERN INTEGER __STDCALL GetSecurityDescriptorLength(LONGINT pSecurityDescriptor);
#define WinAPI_GetSecurityDescriptorLength(pSecurityDescriptor)	GetSecurityDescriptorLength(pSecurityDescriptor)
__EXTERN INTEGER __STDCALL GetSecurityDescriptorOwner(LONGINT pSecurityDescriptor, LONGINT *pOwner, INTEGER *lpbOwnerDefaulted);
#define WinAPI_GetSecurityDescriptorOwner(pSecurityDescriptor, pOwner, lpbOwnerDefaulted)	GetSecurityDescriptorOwner(pSecurityDescriptor, pOwner, lpbOwnerDefaulted)
__EXTERN INTEGER __STDCALL GetSecurityDescriptorSacl(LONGINT pSecurityDescriptor, INTEGER *lpbSaclPresent, WinAPI_PtrACL *pSacl, INTEGER *lpbSaclDefaulted);
#define WinAPI_GetSecurityDescriptorSacl(pSecurityDescriptor, lpbSaclPresent, pSacl, lpbSaclDefaulted)	GetSecurityDescriptorSacl(pSecurityDescriptor, lpbSaclPresent, pSacl, lpbSaclDefaulted)
#define WinAPI_GetServiceDisplayName(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)	GetServiceDisplayNameA(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)
__EXTERN INTEGER __STDCALL GetServiceDisplayNameA(LONGINT hSCManager, LONGINT lpServiceName, LONGINT lpDisplayName, INTEGER *lpcchBuffer);
#define WinAPI_GetServiceDisplayNameA(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)	GetServiceDisplayNameA(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)
__EXTERN INTEGER __STDCALL GetServiceDisplayNameW(LONGINT hSCManager, LONGINT lpServiceName, LONGINT lpDisplayName, INTEGER *lpcchBuffer);
#define WinAPI_GetServiceDisplayNameW(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)	GetServiceDisplayNameW(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)
#define WinAPI_GetServiceKeyName(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)	GetServiceKeyNameA(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)
__EXTERN INTEGER __STDCALL GetServiceKeyNameA(LONGINT hSCManager, LONGINT lpDisplayName, LONGINT lpServiceName, INTEGER *lpcchBuffer);
#define WinAPI_GetServiceKeyNameA(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)	GetServiceKeyNameA(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)
__EXTERN INTEGER __STDCALL GetServiceKeyNameW(LONGINT hSCManager, LONGINT lpDisplayName, LONGINT lpServiceName, INTEGER *lpcchBuffer);
#define WinAPI_GetServiceKeyNameW(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)	GetServiceKeyNameW(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)
#define WinAPI_GetShortPathName(lpszLongPath, lpszShortPath, cchBuffer)	GetShortPathNameA(lpszLongPath, lpszShortPath, cchBuffer)
__EXTERN INTEGER __STDCALL GetShortPathNameA(LONGINT lpszLongPath, LONGINT lpszShortPath, INTEGER cchBuffer);
#define WinAPI_GetShortPathNameA(lpszLongPath, lpszShortPath, cchBuffer)	GetShortPathNameA(lpszLongPath, lpszShortPath, cchBuffer)
__EXTERN INTEGER __STDCALL GetShortPathNameW(LONGINT lpszLongPath, LONGINT lpszShortPath, INTEGER cchBuffer);
#define WinAPI_GetShortPathNameW(lpszLongPath, lpszShortPath, cchBuffer)	GetShortPathNameW(lpszLongPath, lpszShortPath, cchBuffer)
__EXTERN WinAPI_PtrSID_IDENTIFIER_AUTHORITY __STDCALL GetSidIdentifierAuthority(LONGINT pSid);
#define WinAPI_GetSidIdentifierAuthority(pSid)	GetSidIdentifierAuthority(pSid)
__EXTERN INTEGER __STDCALL GetSidLengthRequired(CHAR nSubAuthorityCount);
#define WinAPI_GetSidLengthRequired(nSubAuthorityCount)	GetSidLengthRequired(nSubAuthorityCount)
__EXTERN LONGINT __STDCALL GetSidSubAuthority(LONGINT pSid, INTEGER nSubAuthority);
#define WinAPI_GetSidSubAuthority(pSid, nSubAuthority)	GetSidSubAuthority(pSid, nSubAuthority)
__EXTERN LONGINT __STDCALL GetSidSubAuthorityCount(LONGINT pSid);
#define WinAPI_GetSidSubAuthorityCount(pSid)	GetSidSubAuthorityCount(pSid)
#define WinAPI_GetStartupInfo(lpStartupInfo)	GetStartupInfoA(lpStartupInfo)
__EXTERN void __STDCALL GetStartupInfoA(WinAPI_STARTUPINFOA *lpStartupInfo);
#define WinAPI_GetStartupInfoA(lpStartupInfo)	GetStartupInfoA(lpStartupInfo)
__EXTERN void __STDCALL GetStartupInfoW(WinAPI_STARTUPINFOW *lpStartupInfo);
#define WinAPI_GetStartupInfoW(lpStartupInfo)	GetStartupInfoW(lpStartupInfo)
__EXTERN LONGINT __STDCALL GetStdHandle(INTEGER nStdHandle);
#define WinAPI_GetStdHandle(nStdHandle)	GetStdHandle(nStdHandle)
__EXTERN LONGINT __STDCALL GetStockObject(INTEGER p0);
#define WinAPI_GetStockObject(p0)	GetStockObject(p0)
__EXTERN INTEGER __STDCALL GetStretchBltMode(LONGINT p0);
#define WinAPI_GetStretchBltMode(p0)	GetStretchBltMode(p0)
__EXTERN INTEGER __STDCALL GetStringTypeA(INTEGER Locale, SET dwInfoType, LONGINT lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
#define WinAPI_GetStringTypeA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)
#define WinAPI_GetStringTypeEx(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeExA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)
__EXTERN INTEGER __STDCALL GetStringTypeExA(INTEGER Locale, SET dwInfoType, LONGINT lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
#define WinAPI_GetStringTypeExA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeExA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)
__EXTERN INTEGER __STDCALL GetStringTypeExW(INTEGER Locale, SET dwInfoType, LONGINT lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
#define WinAPI_GetStringTypeExW(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeExW(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)
__EXTERN INTEGER __STDCALL GetStringTypeW(SET dwInfoType, LONGINT lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
#define WinAPI_GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType)
__EXTERN LONGINT __STDCALL GetSubMenu(LONGINT hMenu, INTEGER nPos);
#define WinAPI_GetSubMenu(hMenu, nPos)	GetSubMenu(hMenu, nPos)
__EXTERN INTEGER __STDCALL GetSysColor(INTEGER nIndex);
#define WinAPI_GetSysColor(nIndex)	GetSysColor(nIndex)
__EXTERN LONGINT __STDCALL GetSysColorBrush(INTEGER nIndex);
#define WinAPI_GetSysColorBrush(nIndex)	GetSysColorBrush(nIndex)
__EXTERN INTEGER __STDCALL GetSystemDefaultLCID(void);
#define WinAPI_GetSystemDefaultLCID()	GetSystemDefaultLCID()
__EXTERN SHORTINT __STDCALL GetSystemDefaultLangID(void);
#define WinAPI_GetSystemDefaultLangID()	GetSystemDefaultLangID()
#define WinAPI_GetSystemDirectory(lpBuffer, uSize)	GetSystemDirectoryA(lpBuffer, uSize)
__EXTERN INTEGER __STDCALL GetSystemDirectoryA(LONGINT lpBuffer, INTEGER uSize);
#define WinAPI_GetSystemDirectoryA(lpBuffer, uSize)	GetSystemDirectoryA(lpBuffer, uSize)
__EXTERN INTEGER __STDCALL GetSystemDirectoryW(LONGINT lpBuffer, INTEGER uSize);
#define WinAPI_GetSystemDirectoryW(lpBuffer, uSize)	GetSystemDirectoryW(lpBuffer, uSize)
__EXTERN void __STDCALL GetSystemInfo(WinAPI_SYSTEM_INFO *lpSystemInfo);
#define WinAPI_GetSystemInfo(lpSystemInfo)	GetSystemInfo(lpSystemInfo)
__EXTERN LONGINT __STDCALL GetSystemMenu(LONGINT hWnd, INTEGER bRevert);
#define WinAPI_GetSystemMenu(hWnd, bRevert)	GetSystemMenu(hWnd, bRevert)
__EXTERN INTEGER __STDCALL GetSystemMetrics(INTEGER nIndex);
#define WinAPI_GetSystemMetrics(nIndex)	GetSystemMetrics(nIndex)
__EXTERN INTEGER __STDCALL GetSystemPaletteEntries(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
#define WinAPI_GetSystemPaletteEntries(p0, p1, p2, p3)	GetSystemPaletteEntries(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetSystemPaletteUse(LONGINT p0);
#define WinAPI_GetSystemPaletteUse(p0)	GetSystemPaletteUse(p0)
__EXTERN INTEGER __STDCALL GetSystemPowerStatus(WinAPI_SYSTEM_POWER_STATUS *lpSystemPowerStatus);
#define WinAPI_GetSystemPowerStatus(lpSystemPowerStatus)	GetSystemPowerStatus(lpSystemPowerStatus)
__EXTERN void __STDCALL GetSystemTime(WinAPI_SYSTEMTIME *lpSystemTime);
#define WinAPI_GetSystemTime(lpSystemTime)	GetSystemTime(lpSystemTime)
__EXTERN INTEGER __STDCALL GetSystemTimeAdjustment(INTEGER *lpTimeAdjustment, INTEGER *lpTimeIncrement, INTEGER *lpTimeAdjustmentDisabled);
#define WinAPI_GetSystemTimeAdjustment(lpTimeAdjustment, lpTimeIncrement, lpTimeAdjustmentDisabled)	GetSystemTimeAdjustment(lpTimeAdjustment, lpTimeIncrement, lpTimeAdjustmentDisabled)
__EXTERN void __STDCALL GetSystemTimeAsFileTime(WinAPI_FILETIME *lpSystemTimeAsFileTime);
#define WinAPI_GetSystemTimeAsFileTime(lpSystemTimeAsFileTime)	GetSystemTimeAsFileTime(lpSystemTimeAsFileTime)
#define WinAPI_GetTabbedTextExtent(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)	GetTabbedTextExtentA(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)
__EXTERN INTEGER __STDCALL GetTabbedTextExtentA(LONGINT hDC, LONGINT lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions);
#define WinAPI_GetTabbedTextExtentA(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)	GetTabbedTextExtentA(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)
__EXTERN INTEGER __STDCALL GetTabbedTextExtentW(LONGINT hDC, LONGINT lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions);
#define WinAPI_GetTabbedTextExtentW(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)	GetTabbedTextExtentW(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)
__EXTERN INTEGER __STDCALL GetTapeParameters(LONGINT hDevice, INTEGER dwOperation, INTEGER *lpdwSize, LONGINT lpTapeInformation);
#define WinAPI_GetTapeParameters(hDevice, dwOperation, lpdwSize, lpTapeInformation)	GetTapeParameters(hDevice, dwOperation, lpdwSize, lpTapeInformation)
__EXTERN INTEGER __STDCALL GetTapePosition(LONGINT hDevice, INTEGER dwPositionType, INTEGER *lpdwPartition, INTEGER *lpdwOffsetLow, INTEGER *lpdwOffsetHigh);
#define WinAPI_GetTapePosition(hDevice, dwPositionType, lpdwPartition, lpdwOffsetLow, lpdwOffsetHigh)	GetTapePosition(hDevice, dwPositionType, lpdwPartition, lpdwOffsetLow, lpdwOffsetHigh)
__EXTERN INTEGER __STDCALL GetTapeStatus(LONGINT hDevice);
#define WinAPI_GetTapeStatus(hDevice)	GetTapeStatus(hDevice)
#define WinAPI_GetTempFileName(lpPathName, lpPrefixString, uUnique, lpTempFileName)	GetTempFileNameA(lpPathName, lpPrefixString, uUnique, lpTempFileName)
__EXTERN INTEGER __STDCALL GetTempFileNameA(LONGINT lpPathName, LONGINT lpPrefixString, INTEGER uUnique, LONGINT lpTempFileName);
#define WinAPI_GetTempFileNameA(lpPathName, lpPrefixString, uUnique, lpTempFileName)	GetTempFileNameA(lpPathName, lpPrefixString, uUnique, lpTempFileName)
__EXTERN INTEGER __STDCALL GetTempFileNameW(LONGINT lpPathName, LONGINT lpPrefixString, INTEGER uUnique, LONGINT lpTempFileName);
#define WinAPI_GetTempFileNameW(lpPathName, lpPrefixString, uUnique, lpTempFileName)	GetTempFileNameW(lpPathName, lpPrefixString, uUnique, lpTempFileName)
#define WinAPI_GetTempPath(nBufferLength, lpBuffer)	GetTempPathA(nBufferLength, lpBuffer)
__EXTERN INTEGER __STDCALL GetTempPathA(INTEGER nBufferLength, LONGINT lpBuffer);
#define WinAPI_GetTempPathA(nBufferLength, lpBuffer)	GetTempPathA(nBufferLength, lpBuffer)
__EXTERN INTEGER __STDCALL GetTempPathW(INTEGER nBufferLength, LONGINT lpBuffer);
#define WinAPI_GetTempPathW(nBufferLength, lpBuffer)	GetTempPathW(nBufferLength, lpBuffer)
__EXTERN SET __STDCALL GetTextAlign(LONGINT p0);
#define WinAPI_GetTextAlign(p0)	GetTextAlign(p0)
__EXTERN INTEGER __STDCALL GetTextCharacterExtra(LONGINT p0);
#define WinAPI_GetTextCharacterExtra(p0)	GetTextCharacterExtra(p0)
__EXTERN INTEGER __STDCALL GetTextCharset(LONGINT hdc);
#define WinAPI_GetTextCharset(hdc)	GetTextCharset(hdc)
__EXTERN INTEGER __STDCALL GetTextCharsetInfo(LONGINT hdc, WinAPI_FONTSIGNATURE *lpSig, SET dwFlags);
#define WinAPI_GetTextCharsetInfo(hdc, lpSig, dwFlags)	GetTextCharsetInfo(hdc, lpSig, dwFlags)
__EXTERN INTEGER __STDCALL GetTextColor(LONGINT p0);
#define WinAPI_GetTextColor(p0)	GetTextColor(p0)
#define WinAPI_GetTextExtentExPoint(p0, p1, p2, p3, p4, p5, p6)	GetTextExtentExPointA(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __STDCALL GetTextExtentExPointA(LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, INTEGER *p4, INTEGER *p5, WinAPI_SIZE *p6);
#define WinAPI_GetTextExtentExPointA(p0, p1, p2, p3, p4, p5, p6)	GetTextExtentExPointA(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __STDCALL GetTextExtentExPointW(LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, INTEGER *p4, INTEGER *p5, WinAPI_SIZE *p6);
#define WinAPI_GetTextExtentExPointW(p0, p1, p2, p3, p4, p5, p6)	GetTextExtentExPointW(p0, p1, p2, p3, p4, p5, p6)
#define WinAPI_GetTextExtentPoint(p0, p1, p2, p3)	GetTextExtentPointA(p0, p1, p2, p3)
#define WinAPI_GetTextExtentPoint32(p0, p1, p2, p3)	GetTextExtentPoint32A(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetTextExtentPoint32A(LONGINT p0, LONGINT p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_GetTextExtentPoint32A(p0, p1, p2, p3)	GetTextExtentPoint32A(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetTextExtentPoint32W(LONGINT p0, LONGINT p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_GetTextExtentPoint32W(p0, p1, p2, p3)	GetTextExtentPoint32W(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetTextExtentPointA(LONGINT p0, LONGINT p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_GetTextExtentPointA(p0, p1, p2, p3)	GetTextExtentPointA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL GetTextExtentPointW(LONGINT p0, LONGINT p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_GetTextExtentPointW(p0, p1, p2, p3)	GetTextExtentPointW(p0, p1, p2, p3)
#define WinAPI_GetTextFace(p0, p1, p2)	GetTextFaceA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetTextFaceA(LONGINT p0, INTEGER p1, LONGINT p2);
#define WinAPI_GetTextFaceA(p0, p1, p2)	GetTextFaceA(p0, p1, p2)
__EXTERN INTEGER __STDCALL GetTextFaceW(LONGINT p0, INTEGER p1, LONGINT p2);
#define WinAPI_GetTextFaceW(p0, p1, p2)	GetTextFaceW(p0, p1, p2)
#define WinAPI_GetTextMetrics(p0, p1)	GetTextMetricsA(p0, p1)
__EXTERN INTEGER __STDCALL GetTextMetricsA(LONGINT p0, WinAPI_TEXTMETRICA *p1);
#define WinAPI_GetTextMetricsA(p0, p1)	GetTextMetricsA(p0, p1)
__EXTERN INTEGER __STDCALL GetTextMetricsW(LONGINT p0, WinAPI_TEXTMETRICW *p1);
#define WinAPI_GetTextMetricsW(p0, p1)	GetTextMetricsW(p0, p1)
__EXTERN INTEGER __STDCALL GetThreadContext(LONGINT hThread, WinAPI_CONTEXT *lpContext);
#define WinAPI_GetThreadContext(hThread, lpContext)	GetThreadContext(hThread, lpContext)
__EXTERN LONGINT __STDCALL GetThreadDesktop(INTEGER dwThreadId);
#define WinAPI_GetThreadDesktop(dwThreadId)	GetThreadDesktop(dwThreadId)
__EXTERN INTEGER __STDCALL GetThreadLocale(void);
#define WinAPI_GetThreadLocale()	GetThreadLocale()
__EXTERN INTEGER __STDCALL GetThreadPriority(LONGINT hThread);
#define WinAPI_GetThreadPriority(hThread)	GetThreadPriority(hThread)
__EXTERN INTEGER __STDCALL GetThreadPriorityBoost(LONGINT hThread, INTEGER *pDisablePriorityBoost);
#define WinAPI_GetThreadPriorityBoost(hThread, pDisablePriorityBoost)	GetThreadPriorityBoost(hThread, pDisablePriorityBoost)
__EXTERN INTEGER __STDCALL GetThreadSelectorEntry(LONGINT hThread, INTEGER dwSelector, WinAPI_LDT_ENTRY *lpSelectorEntry);
#define WinAPI_GetThreadSelectorEntry(hThread, dwSelector, lpSelectorEntry)	GetThreadSelectorEntry(hThread, dwSelector, lpSelectorEntry)
__EXTERN INTEGER __STDCALL GetThreadTimes(LONGINT hThread, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpExitTime, WinAPI_FILETIME *lpKernelTime, WinAPI_FILETIME *lpUserTime);
#define WinAPI_GetThreadTimes(hThread, lpCreationTime, lpExitTime, lpKernelTime, lpUserTime)	GetThreadTimes(hThread, lpCreationTime, lpExitTime, lpKernelTime, lpUserTime)
__EXTERN INTEGER __STDCALL GetTickCount(void);
#define WinAPI_GetTickCount()	GetTickCount()
#define WinAPI_GetTimeFormat(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)	GetTimeFormatA(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)
__EXTERN INTEGER __STDCALL GetTimeFormatA(INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpTime, LONGINT lpFormat, LONGINT lpTimeStr, INTEGER cchTime);
#define WinAPI_GetTimeFormatA(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)	GetTimeFormatA(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)
__EXTERN INTEGER __STDCALL GetTimeFormatW(INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpTime, LONGINT lpFormat, LONGINT lpTimeStr, INTEGER cchTime);
#define WinAPI_GetTimeFormatW(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)	GetTimeFormatW(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)
__EXTERN INTEGER __STDCALL GetTimeZoneInformation(WinAPI_TIME_ZONE_INFORMATION *lpTimeZoneInformation);
#define WinAPI_GetTimeZoneInformation(lpTimeZoneInformation)	GetTimeZoneInformation(lpTimeZoneInformation)
__EXTERN INTEGER __STDCALL GetTokenInformation(LONGINT TokenHandle, INTEGER TokenInformationClass, LONGINT TokenInformation, INTEGER TokenInformationLength, INTEGER *ReturnLength);
#define WinAPI_GetTokenInformation(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength, ReturnLength)	GetTokenInformation(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength, ReturnLength)
__EXTERN LONGINT __STDCALL GetTopWindow(LONGINT hWnd);
#define WinAPI_GetTopWindow(hWnd)	GetTopWindow(hWnd)
__EXTERN INTEGER __STDCALL GetUpdateRect(LONGINT hWnd, WinAPI_RECT *lpRect, INTEGER bErase);
#define WinAPI_GetUpdateRect(hWnd, lpRect, bErase)	GetUpdateRect(hWnd, lpRect, bErase)
__EXTERN INTEGER __STDCALL GetUpdateRgn(LONGINT hWnd, LONGINT hRgn, INTEGER bErase);
#define WinAPI_GetUpdateRgn(hWnd, hRgn, bErase)	GetUpdateRgn(hWnd, hRgn, bErase)
__EXTERN INTEGER __STDCALL GetUserDefaultLCID(void);
#define WinAPI_GetUserDefaultLCID()	GetUserDefaultLCID()
__EXTERN SHORTINT __STDCALL GetUserDefaultLangID(void);
#define WinAPI_GetUserDefaultLangID()	GetUserDefaultLangID()
#define WinAPI_GetUserName(lpBuffer, nSize)	GetUserNameA(lpBuffer, nSize)
__EXTERN INTEGER __STDCALL GetUserNameA(LONGINT lpBuffer, INTEGER *nSize);
#define WinAPI_GetUserNameA(lpBuffer, nSize)	GetUserNameA(lpBuffer, nSize)
__EXTERN INTEGER __STDCALL GetUserNameW(LONGINT lpBuffer, INTEGER *nSize);
#define WinAPI_GetUserNameW(lpBuffer, nSize)	GetUserNameW(lpBuffer, nSize)
#define WinAPI_GetUserObjectInformation(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)	GetUserObjectInformationA(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)
__EXTERN INTEGER __STDCALL GetUserObjectInformationA(LONGINT hObj, INTEGER nIndex, LONGINT pvInfo, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinAPI_GetUserObjectInformationA(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)	GetUserObjectInformationA(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)
__EXTERN INTEGER __STDCALL GetUserObjectInformationW(LONGINT hObj, INTEGER nIndex, LONGINT pvInfo, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinAPI_GetUserObjectInformationW(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)	GetUserObjectInformationW(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)
__EXTERN INTEGER __STDCALL GetUserObjectSecurity(LONGINT hObj, INTEGER *pSIRequested, LONGINT pSID, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinAPI_GetUserObjectSecurity(hObj, pSIRequested, pSID, nLength, lpnLengthNeeded)	GetUserObjectSecurity(hObj, pSIRequested, pSID, nLength, lpnLengthNeeded)
__EXTERN INTEGER __STDCALL GetVersion(void);
#define WinAPI_GetVersion()	GetVersion()
#define WinAPI_GetVersionEx(lpVersionInformation)	GetVersionExA(lpVersionInformation)
__EXTERN INTEGER __STDCALL GetVersionExA(WinAPI_OSVERSIONINFOA *lpVersionInformation);
#define WinAPI_GetVersionExA(lpVersionInformation)	GetVersionExA(lpVersionInformation)
__EXTERN INTEGER __STDCALL GetVersionExW(WinAPI_OSVERSIONINFOW *lpVersionInformation);
#define WinAPI_GetVersionExW(lpVersionInformation)	GetVersionExW(lpVersionInformation)
__EXTERN INTEGER __STDCALL GetViewportExtEx(LONGINT p0, WinAPI_SIZE *p1);
#define WinAPI_GetViewportExtEx(p0, p1)	GetViewportExtEx(p0, p1)
__EXTERN INTEGER __STDCALL GetViewportOrgEx(LONGINT p0, WinAPI_POINT *p1);
#define WinAPI_GetViewportOrgEx(p0, p1)	GetViewportOrgEx(p0, p1)
#define WinAPI_GetVolumeInformation(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)	GetVolumeInformationA(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)
__EXTERN INTEGER __STDCALL GetVolumeInformationA(LONGINT lpRootPathName, LONGINT lpVolumeNameBuffer, INTEGER nVolumeNameSize, INTEGER *lpVolumeSerialNumber, INTEGER *lpMaximumComponentLength, SET *lpFileSystemFlags, LONGINT lpFileSystemNameBuffer, INTEGER nFileSystemNameSize);
#define WinAPI_GetVolumeInformationA(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)	GetVolumeInformationA(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)
__EXTERN INTEGER __STDCALL GetVolumeInformationW(LONGINT lpRootPathName, LONGINT lpVolumeNameBuffer, INTEGER nVolumeNameSize, INTEGER *lpVolumeSerialNumber, INTEGER *lpMaximumComponentLength, SET *lpFileSystemFlags, LONGINT lpFileSystemNameBuffer, INTEGER nFileSystemNameSize);
#define WinAPI_GetVolumeInformationW(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)	GetVolumeInformationW(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)
__EXTERN INTEGER __STDCALL GetWinMetaFileBits(LONGINT p0, INTEGER p1, CHAR *p2, INTEGER p3, LONGINT p4);
#define WinAPI_GetWinMetaFileBits(p0, p1, p2, p3, p4)	GetWinMetaFileBits(p0, p1, p2, p3, p4)
__EXTERN LONGINT __STDCALL GetWindow(LONGINT hWnd, INTEGER uCmd);
#define WinAPI_GetWindow(hWnd, uCmd)	GetWindow(hWnd, uCmd)
__EXTERN INTEGER __STDCALL GetWindowContextHelpId(LONGINT p0);
#define WinAPI_GetWindowContextHelpId(p0)	GetWindowContextHelpId(p0)
__EXTERN LONGINT __STDCALL GetWindowDC(LONGINT hWnd);
#define WinAPI_GetWindowDC(hWnd)	GetWindowDC(hWnd)
__EXTERN INTEGER __STDCALL GetWindowExtEx(LONGINT p0, WinAPI_SIZE *p1);
#define WinAPI_GetWindowExtEx(p0, p1)	GetWindowExtEx(p0, p1)
#define WinAPI_GetWindowLong(hWnd, nIndex)	GetWindowLongA(hWnd, nIndex)
__EXTERN INTEGER __STDCALL GetWindowLongA(LONGINT hWnd, INTEGER nIndex);
#define WinAPI_GetWindowLongA(hWnd, nIndex)	GetWindowLongA(hWnd, nIndex)
__EXTERN INTEGER __STDCALL GetWindowLongW(LONGINT hWnd, INTEGER nIndex);
#define WinAPI_GetWindowLongW(hWnd, nIndex)	GetWindowLongW(hWnd, nIndex)
__EXTERN INTEGER __STDCALL GetWindowOrgEx(LONGINT p0, WinAPI_POINT *p1);
#define WinAPI_GetWindowOrgEx(p0, p1)	GetWindowOrgEx(p0, p1)
__EXTERN INTEGER __STDCALL GetWindowPlacement(LONGINT hWnd, WinAPI_WINDOWPLACEMENT *lpwndpl);
#define WinAPI_GetWindowPlacement(hWnd, lpwndpl)	GetWindowPlacement(hWnd, lpwndpl)
__EXTERN INTEGER __STDCALL GetWindowRect(LONGINT hWnd, WinAPI_RECT *lpRect);
#define WinAPI_GetWindowRect(hWnd, lpRect)	GetWindowRect(hWnd, lpRect)
__EXTERN INTEGER __STDCALL GetWindowRgn(LONGINT hWnd, LONGINT hRgn);
#define WinAPI_GetWindowRgn(hWnd, hRgn)	GetWindowRgn(hWnd, hRgn)
#define WinAPI_GetWindowText(hWnd, lpString, nMaxCount)	GetWindowTextA(hWnd, lpString, nMaxCount)
__EXTERN INTEGER __STDCALL GetWindowTextA(LONGINT hWnd, LONGINT lpString, INTEGER nMaxCount);
#define WinAPI_GetWindowTextA(hWnd, lpString, nMaxCount)	GetWindowTextA(hWnd, lpString, nMaxCount)
#define WinAPI_GetWindowTextLength(hWnd)	GetWindowTextLengthA(hWnd)
__EXTERN INTEGER __STDCALL GetWindowTextLengthA(LONGINT hWnd);
#define WinAPI_GetWindowTextLengthA(hWnd)	GetWindowTextLengthA(hWnd)
__EXTERN INTEGER __STDCALL GetWindowTextLengthW(LONGINT hWnd);
#define WinAPI_GetWindowTextLengthW(hWnd)	GetWindowTextLengthW(hWnd)
__EXTERN INTEGER __STDCALL GetWindowTextW(LONGINT hWnd, LONGINT lpString, INTEGER nMaxCount);
#define WinAPI_GetWindowTextW(hWnd, lpString, nMaxCount)	GetWindowTextW(hWnd, lpString, nMaxCount)
__EXTERN INTEGER __STDCALL GetWindowThreadProcessId(LONGINT hWnd, INTEGER *lpdwProcessId);
#define WinAPI_GetWindowThreadProcessId(hWnd, lpdwProcessId)	GetWindowThreadProcessId(hWnd, lpdwProcessId)
__EXTERN SHORTINT __STDCALL GetWindowWord(LONGINT hWnd, INTEGER nIndex);
#define WinAPI_GetWindowWord(hWnd, nIndex)	GetWindowWord(hWnd, nIndex)
#define WinAPI_GetWindowsDirectory(lpBuffer, uSize)	GetWindowsDirectoryA(lpBuffer, uSize)
__EXTERN INTEGER __STDCALL GetWindowsDirectoryA(LONGINT lpBuffer, INTEGER uSize);
#define WinAPI_GetWindowsDirectoryA(lpBuffer, uSize)	GetWindowsDirectoryA(lpBuffer, uSize)
__EXTERN INTEGER __STDCALL GetWindowsDirectoryW(LONGINT lpBuffer, INTEGER uSize);
#define WinAPI_GetWindowsDirectoryW(lpBuffer, uSize)	GetWindowsDirectoryW(lpBuffer, uSize)
__EXTERN INTEGER __STDCALL GetWorldTransform(LONGINT p0, WinAPI_XFORM *p1);
#define WinAPI_GetWorldTransform(p0, p1)	GetWorldTransform(p0, p1)
#define WinAPI_GlobalAddAtom(lpString)	GlobalAddAtomA(lpString)
__EXTERN SHORTINT __STDCALL GlobalAddAtomA(LONGINT lpString);
#define WinAPI_GlobalAddAtomA(lpString)	GlobalAddAtomA(lpString)
__EXTERN SHORTINT __STDCALL GlobalAddAtomW(LONGINT lpString);
#define WinAPI_GlobalAddAtomW(lpString)	GlobalAddAtomW(lpString)
__EXTERN LONGINT __STDCALL GlobalAlloc(SET uFlags, LONGINT dwBytes);
#define WinAPI_GlobalAlloc(uFlags, dwBytes)	GlobalAlloc(uFlags, dwBytes)
__EXTERN LONGINT __STDCALL GlobalCompact(INTEGER dwMinFree);
#define WinAPI_GlobalCompact(dwMinFree)	GlobalCompact(dwMinFree)
__EXTERN SHORTINT __STDCALL GlobalDeleteAtom(SHORTINT nAtom);
#define WinAPI_GlobalDeleteAtom(nAtom)	GlobalDeleteAtom(nAtom)
#define WinAPI_GlobalFindAtom(lpString)	GlobalFindAtomA(lpString)
__EXTERN SHORTINT __STDCALL GlobalFindAtomA(LONGINT lpString);
#define WinAPI_GlobalFindAtomA(lpString)	GlobalFindAtomA(lpString)
__EXTERN SHORTINT __STDCALL GlobalFindAtomW(LONGINT lpString);
#define WinAPI_GlobalFindAtomW(lpString)	GlobalFindAtomW(lpString)
__EXTERN void __STDCALL GlobalFix(LONGINT hMem);
#define WinAPI_GlobalFix(hMem)	GlobalFix(hMem)
__EXTERN INTEGER __STDCALL GlobalFlags(LONGINT hMem);
#define WinAPI_GlobalFlags(hMem)	GlobalFlags(hMem)
__EXTERN LONGINT __STDCALL GlobalFree(LONGINT hMem);
#define WinAPI_GlobalFree(hMem)	GlobalFree(hMem)
#define WinAPI_GlobalGetAtomName(nAtom, lpBuffer, nSize)	GlobalGetAtomNameA(nAtom, lpBuffer, nSize)
__EXTERN INTEGER __STDCALL GlobalGetAtomNameA(SHORTINT nAtom, LONGINT lpBuffer, INTEGER nSize);
#define WinAPI_GlobalGetAtomNameA(nAtom, lpBuffer, nSize)	GlobalGetAtomNameA(nAtom, lpBuffer, nSize)
__EXTERN INTEGER __STDCALL GlobalGetAtomNameW(SHORTINT nAtom, LONGINT lpBuffer, INTEGER nSize);
#define WinAPI_GlobalGetAtomNameW(nAtom, lpBuffer, nSize)	GlobalGetAtomNameW(nAtom, lpBuffer, nSize)
__EXTERN LONGINT __STDCALL GlobalHandle(LONGINT pMem);
#define WinAPI_GlobalHandle(pMem)	GlobalHandle(pMem)
__EXTERN LONGINT __STDCALL GlobalLock(LONGINT hMem);
#define WinAPI_GlobalLock(hMem)	GlobalLock(hMem)
__EXTERN void __STDCALL GlobalMemoryStatus(WinAPI_MEMORYSTATUS *lpBuffer);
#define WinAPI_GlobalMemoryStatus(lpBuffer)	GlobalMemoryStatus(lpBuffer)
__EXTERN LONGINT __STDCALL GlobalReAlloc(LONGINT hMem, LONGINT dwBytes, SET uFlags);
#define WinAPI_GlobalReAlloc(hMem, dwBytes, uFlags)	GlobalReAlloc(hMem, dwBytes, uFlags)
__EXTERN LONGINT __STDCALL GlobalSize(LONGINT hMem);
#define WinAPI_GlobalSize(hMem)	GlobalSize(hMem)
__EXTERN INTEGER __STDCALL GlobalUnWire(LONGINT hMem);
#define WinAPI_GlobalUnWire(hMem)	GlobalUnWire(hMem)
__EXTERN void __STDCALL GlobalUnfix(LONGINT hMem);
#define WinAPI_GlobalUnfix(hMem)	GlobalUnfix(hMem)
__EXTERN INTEGER __STDCALL GlobalUnlock(LONGINT hMem);
#define WinAPI_GlobalUnlock(hMem)	GlobalUnlock(hMem)
__EXTERN LONGINT __STDCALL GlobalWire(LONGINT hMem);
#define WinAPI_GlobalWire(hMem)	GlobalWire(hMem)
#define WinAPI_GrayString(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)	GrayStringA(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)
__EXTERN INTEGER __STDCALL GrayStringA(LONGINT hDC, LONGINT hBrush, WinAPI_GRAYSTRINGPROC lpOutputFunc, LONGINT lpData, INTEGER nCount, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight);
#define WinAPI_GrayStringA(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)	GrayStringA(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)
__EXTERN INTEGER __STDCALL GrayStringW(LONGINT hDC, LONGINT hBrush, WinAPI_GRAYSTRINGPROC lpOutputFunc, LONGINT lpData, INTEGER nCount, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight);
#define WinAPI_GrayStringW(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)	GrayStringW(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)
__EXTERN LONGINT __STDCALL HeapAlloc(LONGINT hHeap, SET dwFlags, LONGINT dwBytes);
#define WinAPI_HeapAlloc(hHeap, dwFlags, dwBytes)	HeapAlloc(hHeap, dwFlags, dwBytes)
__EXTERN LONGINT __STDCALL HeapCompact(LONGINT hHeap, SET dwFlags);
#define WinAPI_HeapCompact(hHeap, dwFlags)	HeapCompact(hHeap, dwFlags)
__EXTERN LONGINT __STDCALL HeapCreate(SET flOptions, LONGINT dwInitialSize, LONGINT dwMaximumSize);
#define WinAPI_HeapCreate(flOptions, dwInitialSize, dwMaximumSize)	HeapCreate(flOptions, dwInitialSize, dwMaximumSize)
__EXTERN INTEGER __STDCALL HeapDestroy(LONGINT hHeap);
#define WinAPI_HeapDestroy(hHeap)	HeapDestroy(hHeap)
__EXTERN INTEGER __STDCALL HeapFree(LONGINT hHeap, SET dwFlags, LONGINT lpMem);
#define WinAPI_HeapFree(hHeap, dwFlags, lpMem)	HeapFree(hHeap, dwFlags, lpMem)
__EXTERN INTEGER __STDCALL HeapLock(LONGINT hHeap);
#define WinAPI_HeapLock(hHeap)	HeapLock(hHeap)
__EXTERN LONGINT __STDCALL HeapReAlloc(LONGINT hHeap, SET dwFlags, LONGINT lpMem, LONGINT dwBytes);
#define WinAPI_HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes)	HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes)
__EXTERN LONGINT __STDCALL HeapSize(LONGINT hHeap, SET dwFlags, LONGINT lpMem);
#define WinAPI_HeapSize(hHeap, dwFlags, lpMem)	HeapSize(hHeap, dwFlags, lpMem)
__EXTERN INTEGER __STDCALL HeapUnlock(LONGINT hHeap);
#define WinAPI_HeapUnlock(hHeap)	HeapUnlock(hHeap)
__EXTERN INTEGER __STDCALL HeapValidate(LONGINT hHeap, SET dwFlags, LONGINT lpMem);
#define WinAPI_HeapValidate(hHeap, dwFlags, lpMem)	HeapValidate(hHeap, dwFlags, lpMem)
__EXTERN INTEGER __STDCALL HeapWalk(LONGINT hHeap, WinAPI_PROCESS_HEAP_ENTRY *lpEntry);
#define WinAPI_HeapWalk(hHeap, lpEntry)	HeapWalk(hHeap, lpEntry)
__EXTERN INTEGER __STDCALL HideCaret(LONGINT hWnd);
#define WinAPI_HideCaret(hWnd)	HideCaret(hWnd)
__EXTERN INTEGER __STDCALL HiliteMenuItem(LONGINT hWnd, LONGINT hMenu, INTEGER uIDHiliteItem, INTEGER uHilite);
#define WinAPI_HiliteMenuItem(hWnd, hMenu, uIDHiliteItem, uHilite)	HiliteMenuItem(hWnd, hMenu, uIDHiliteItem, uHilite)
__EXTERN INTEGER __STDCALL ImpersonateDdeClientWindow(LONGINT hWndClient, LONGINT hWndServer);
#define WinAPI_ImpersonateDdeClientWindow(hWndClient, hWndServer)	ImpersonateDdeClientWindow(hWndClient, hWndServer)
__EXTERN INTEGER __STDCALL ImpersonateLoggedOnUser(LONGINT hToken);
#define WinAPI_ImpersonateLoggedOnUser(hToken)	ImpersonateLoggedOnUser(hToken)
__EXTERN INTEGER __STDCALL ImpersonateNamedPipeClient(LONGINT hNamedPipe);
#define WinAPI_ImpersonateNamedPipeClient(hNamedPipe)	ImpersonateNamedPipeClient(hNamedPipe)
__EXTERN INTEGER __STDCALL ImpersonateSelf(INTEGER ImpersonationLevel);
#define WinAPI_ImpersonateSelf(ImpersonationLevel)	ImpersonateSelf(ImpersonationLevel)
__EXTERN INTEGER __STDCALL InSendMessage(void);
#define WinAPI_InSendMessage()	InSendMessage()
__EXTERN INTEGER __STDCALL InflateRect(WinAPI_RECT *lprc, INTEGER dx, INTEGER dy);
#define WinAPI_InflateRect(lprc, dx, dy)	InflateRect(lprc, dx, dy)
__EXTERN INTEGER __STDCALL InitAtomTable(INTEGER nSize);
#define WinAPI_InitAtomTable(nSize)	InitAtomTable(nSize)
__EXTERN INTEGER __STDCALL InitializeAcl(WinAPI_ACL *pAcl, INTEGER nAclLength, INTEGER dwAclRevision);
#define WinAPI_InitializeAcl(pAcl, nAclLength, dwAclRevision)	InitializeAcl(pAcl, nAclLength, dwAclRevision)
__EXTERN void __STDCALL InitializeCriticalSection(WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinAPI_InitializeCriticalSection(lpCriticalSection)	InitializeCriticalSection(lpCriticalSection)
__EXTERN INTEGER __STDCALL InitializeSecurityDescriptor(LONGINT pSecurityDescriptor, INTEGER dwRevision);
#define WinAPI_InitializeSecurityDescriptor(pSecurityDescriptor, dwRevision)	InitializeSecurityDescriptor(pSecurityDescriptor, dwRevision)
__EXTERN INTEGER __STDCALL InitializeSid(LONGINT Sid, WinAPI_SID_IDENTIFIER_AUTHORITY *pIdentifierAuthority, CHAR nSubAuthorityCount);
#define WinAPI_InitializeSid(Sid, pIdentifierAuthority, nSubAuthorityCount)	InitializeSid(Sid, pIdentifierAuthority, nSubAuthorityCount)
#define WinAPI_InitiateSystemShutdown(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)	InitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)
__EXTERN INTEGER __STDCALL InitiateSystemShutdownA(LONGINT lpMachineName, LONGINT lpMessage, INTEGER dwTimeout, INTEGER bForceAppsClosed, INTEGER bRebootAfterShutdown);
#define WinAPI_InitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)	InitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)
__EXTERN INTEGER __STDCALL InitiateSystemShutdownW(LONGINT lpMachineName, LONGINT lpMessage, INTEGER dwTimeout, INTEGER bForceAppsClosed, INTEGER bRebootAfterShutdown);
#define WinAPI_InitiateSystemShutdownW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)	InitiateSystemShutdownW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)
#define WinAPI_InsertMenu(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)	InsertMenuA(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __STDCALL InsertMenuA(LONGINT hMenu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, LONGINT lpNewItem);
#define WinAPI_InsertMenuA(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)	InsertMenuA(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)
#define WinAPI_InsertMenuItem(p0, p1, p2, p3)	InsertMenuItemA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL InsertMenuItemA(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOA *p3);
#define WinAPI_InsertMenuItemA(p0, p1, p2, p3)	InsertMenuItemA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL InsertMenuItemW(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOW *p3);
#define WinAPI_InsertMenuItemW(p0, p1, p2, p3)	InsertMenuItemW(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL InsertMenuW(LONGINT hMenu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, LONGINT lpNewItem);
#define WinAPI_InsertMenuW(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)	InsertMenuW(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)
#define WinAPI_Instance()	__hInstance
__EXTERN LONGINT __STDCALL InterlockedCompareExchange(LONGINT Destination, LONGINT Exchange, LONGINT Comperand);
#define WinAPI_InterlockedCompareExchange(Destination, Exchange, Comperand)	InterlockedCompareExchange(Destination, Exchange, Comperand)
__EXTERN INTEGER __STDCALL InterlockedDecrement(INTEGER *lpAddend);
#define WinAPI_InterlockedDecrement(lpAddend)	InterlockedDecrement(lpAddend)
__EXTERN INTEGER __STDCALL InterlockedExchange(INTEGER *Target, INTEGER Value);
#define WinAPI_InterlockedExchange(Target, Value)	InterlockedExchange(Target, Value)
__EXTERN INTEGER __STDCALL InterlockedExchangeAdd(INTEGER *Addend, INTEGER Value);
#define WinAPI_InterlockedExchangeAdd(Addend, Value)	InterlockedExchangeAdd(Addend, Value)
__EXTERN INTEGER __STDCALL InterlockedIncrement(INTEGER *lpAddend);
#define WinAPI_InterlockedIncrement(lpAddend)	InterlockedIncrement(lpAddend)
__EXTERN INTEGER __STDCALL IntersectClipRect(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_IntersectClipRect(p0, p1, p2, p3, p4)	IntersectClipRect(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL IntersectRect(WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc1, WinAPI_RECT *lprcSrc2);
#define WinAPI_IntersectRect(lprcDst, lprcSrc1, lprcSrc2)	IntersectRect(lprcDst, lprcSrc1, lprcSrc2)
__EXTERN INTEGER __STDCALL InvalidateRect(LONGINT hWnd, WinAPI_RECT *lpRect, INTEGER bErase);
#define WinAPI_InvalidateRect(hWnd, lpRect, bErase)	InvalidateRect(hWnd, lpRect, bErase)
__EXTERN INTEGER __STDCALL InvalidateRgn(LONGINT hWnd, LONGINT hRgn, INTEGER bErase);
#define WinAPI_InvalidateRgn(hWnd, hRgn, bErase)	InvalidateRgn(hWnd, hRgn, bErase)
__EXTERN INTEGER __STDCALL InvertRect(LONGINT hDC, WinAPI_RECT *lprc);
#define WinAPI_InvertRect(hDC, lprc)	InvertRect(hDC, lprc)
__EXTERN INTEGER __STDCALL InvertRgn(LONGINT p0, LONGINT p1);
#define WinAPI_InvertRgn(p0, p1)	InvertRgn(p0, p1)
__EXTERN INTEGER __STDCALL IsBadCodePtr(WinAPI_FARPROC lpfn);
#define WinAPI_IsBadCodePtr(lpfn)	IsBadCodePtr(lpfn)
__EXTERN INTEGER __STDCALL IsBadHugeReadPtr(LONGINT lp, INTEGER ucb);
#define WinAPI_IsBadHugeReadPtr(lp, ucb)	IsBadHugeReadPtr(lp, ucb)
__EXTERN INTEGER __STDCALL IsBadHugeWritePtr(LONGINT lp, INTEGER ucb);
#define WinAPI_IsBadHugeWritePtr(lp, ucb)	IsBadHugeWritePtr(lp, ucb)
__EXTERN INTEGER __STDCALL IsBadReadPtr(LONGINT lp, INTEGER ucb);
#define WinAPI_IsBadReadPtr(lp, ucb)	IsBadReadPtr(lp, ucb)
#define WinAPI_IsBadStringPtr(lpsz, ucchMax)	IsBadStringPtrA(lpsz, ucchMax)
__EXTERN INTEGER __STDCALL IsBadStringPtrA(LONGINT lpsz, INTEGER ucchMax);
#define WinAPI_IsBadStringPtrA(lpsz, ucchMax)	IsBadStringPtrA(lpsz, ucchMax)
__EXTERN INTEGER __STDCALL IsBadStringPtrW(LONGINT lpsz, INTEGER ucchMax);
#define WinAPI_IsBadStringPtrW(lpsz, ucchMax)	IsBadStringPtrW(lpsz, ucchMax)
__EXTERN INTEGER __STDCALL IsBadWritePtr(LONGINT lp, INTEGER ucb);
#define WinAPI_IsBadWritePtr(lp, ucb)	IsBadWritePtr(lp, ucb)
#define WinAPI_IsCharAlpha(ch)	IsCharAlphaA(ch)
__EXTERN INTEGER __STDCALL IsCharAlphaA(CHAR ch);
#define WinAPI_IsCharAlphaA(ch)	IsCharAlphaA(ch)
#define WinAPI_IsCharAlphaNumeric(ch)	IsCharAlphaNumericA(ch)
__EXTERN INTEGER __STDCALL IsCharAlphaNumericA(CHAR ch);
#define WinAPI_IsCharAlphaNumericA(ch)	IsCharAlphaNumericA(ch)
__EXTERN INTEGER __STDCALL IsCharAlphaNumericW(SHORTINT ch);
#define WinAPI_IsCharAlphaNumericW(ch)	IsCharAlphaNumericW(ch)
__EXTERN INTEGER __STDCALL IsCharAlphaW(SHORTINT ch);
#define WinAPI_IsCharAlphaW(ch)	IsCharAlphaW(ch)
#define WinAPI_IsCharLower(ch)	IsCharLowerA(ch)
__EXTERN INTEGER __STDCALL IsCharLowerA(CHAR ch);
#define WinAPI_IsCharLowerA(ch)	IsCharLowerA(ch)
__EXTERN INTEGER __STDCALL IsCharLowerW(SHORTINT ch);
#define WinAPI_IsCharLowerW(ch)	IsCharLowerW(ch)
#define WinAPI_IsCharUpper(ch)	IsCharUpperA(ch)
__EXTERN INTEGER __STDCALL IsCharUpperA(CHAR ch);
#define WinAPI_IsCharUpperA(ch)	IsCharUpperA(ch)
__EXTERN INTEGER __STDCALL IsCharUpperW(SHORTINT ch);
#define WinAPI_IsCharUpperW(ch)	IsCharUpperW(ch)
__EXTERN INTEGER __STDCALL IsChild(LONGINT hWndParent, LONGINT hWnd);
#define WinAPI_IsChild(hWndParent, hWnd)	IsChild(hWndParent, hWnd)
__EXTERN INTEGER __STDCALL IsClipboardFormatAvailable(INTEGER format);
#define WinAPI_IsClipboardFormatAvailable(format)	IsClipboardFormatAvailable(format)
__EXTERN INTEGER __STDCALL IsDBCSLeadByte(CHAR TestChar);
#define WinAPI_IsDBCSLeadByte(TestChar)	IsDBCSLeadByte(TestChar)
__EXTERN INTEGER __STDCALL IsDBCSLeadByteEx(INTEGER CodePage, CHAR TestChar);
#define WinAPI_IsDBCSLeadByteEx(CodePage, TestChar)	IsDBCSLeadByteEx(CodePage, TestChar)
#define WinAPI_IsDialogMessage(hDlg, lpMsg)	IsDialogMessageA(hDlg, lpMsg)
__EXTERN INTEGER __STDCALL IsDialogMessageA(LONGINT hDlg, WinAPI_MSG *lpMsg);
#define WinAPI_IsDialogMessageA(hDlg, lpMsg)	IsDialogMessageA(hDlg, lpMsg)
__EXTERN INTEGER __STDCALL IsDialogMessageW(LONGINT hDlg, WinAPI_MSG *lpMsg);
#define WinAPI_IsDialogMessageW(hDlg, lpMsg)	IsDialogMessageW(hDlg, lpMsg)
__EXTERN INTEGER __STDCALL IsDlgButtonChecked(LONGINT hDlg, INTEGER nIDButton);
#define WinAPI_IsDlgButtonChecked(hDlg, nIDButton)	IsDlgButtonChecked(hDlg, nIDButton)
__EXTERN INTEGER __STDCALL IsIconic(LONGINT hWnd);
#define WinAPI_IsIconic(hWnd)	IsIconic(hWnd)
__EXTERN INTEGER __STDCALL IsMenu(LONGINT hMenu);
#define WinAPI_IsMenu(hMenu)	IsMenu(hMenu)
__EXTERN INTEGER __STDCALL IsRectEmpty(WinAPI_RECT *lprc);
#define WinAPI_IsRectEmpty(lprc)	IsRectEmpty(lprc)
__EXTERN INTEGER __STDCALL IsTextUnicode(LONGINT lpBuffer, INTEGER cb, SET *lpi);
#define WinAPI_IsTextUnicode(lpBuffer, cb, lpi)	IsTextUnicode(lpBuffer, cb, lpi)
__EXTERN INTEGER __STDCALL IsValidAcl(WinAPI_ACL *pAcl);
#define WinAPI_IsValidAcl(pAcl)	IsValidAcl(pAcl)
__EXTERN INTEGER __STDCALL IsValidCodePage(INTEGER CodePage);
#define WinAPI_IsValidCodePage(CodePage)	IsValidCodePage(CodePage)
__EXTERN INTEGER __STDCALL IsValidLocale(INTEGER Locale, SET dwFlags);
#define WinAPI_IsValidLocale(Locale, dwFlags)	IsValidLocale(Locale, dwFlags)
__EXTERN INTEGER __STDCALL IsValidSecurityDescriptor(LONGINT pSecurityDescriptor);
#define WinAPI_IsValidSecurityDescriptor(pSecurityDescriptor)	IsValidSecurityDescriptor(pSecurityDescriptor)
__EXTERN INTEGER __STDCALL IsValidSid(LONGINT pSid);
#define WinAPI_IsValidSid(pSid)	IsValidSid(pSid)
__EXTERN INTEGER __STDCALL IsWindow(LONGINT hWnd);
#define WinAPI_IsWindow(hWnd)	IsWindow(hWnd)
__EXTERN INTEGER __STDCALL IsWindowEnabled(LONGINT hWnd);
#define WinAPI_IsWindowEnabled(hWnd)	IsWindowEnabled(hWnd)
__EXTERN INTEGER __STDCALL IsWindowUnicode(LONGINT hWnd);
#define WinAPI_IsWindowUnicode(hWnd)	IsWindowUnicode(hWnd)
__EXTERN INTEGER __STDCALL IsWindowVisible(LONGINT hWnd);
#define WinAPI_IsWindowVisible(hWnd)	IsWindowVisible(hWnd)
__EXTERN INTEGER __STDCALL IsZoomed(LONGINT hWnd);
#define WinAPI_IsZoomed(hWnd)	IsZoomed(hWnd)
__EXTERN INTEGER __STDCALL KillTimer(LONGINT hWnd, INTEGER uIDEvent);
#define WinAPI_KillTimer(hWnd, uIDEvent)	KillTimer(hWnd, uIDEvent)
#define WinAPI_LCMapString(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
__EXTERN INTEGER __STDCALL LCMapStringA(INTEGER Locale, SET dwMapFlags, LONGINT lpSrcStr, INTEGER cchSrc, LONGINT lpDestStr, INTEGER cchDest);
#define WinAPI_LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
__EXTERN INTEGER __STDCALL LCMapStringW(INTEGER Locale, SET dwMapFlags, LONGINT lpSrcStr, INTEGER cchSrc, LONGINT lpDestStr, INTEGER cchDest);
#define WinAPI_LCMapStringW(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	LCMapStringW(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
__EXTERN INTEGER __STDCALL LPtoDP(LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_LPtoDP(p0, p1, p2)	LPtoDP(p0, p1, p2)
__EXTERN void __STDCALL LZClose(INTEGER p0);
#define WinAPI_LZClose(p0)	LZClose(p0)
__EXTERN INTEGER __STDCALL LZCopy(INTEGER p0, INTEGER p1);
#define WinAPI_LZCopy(p0, p1)	LZCopy(p0, p1)
__EXTERN void __STDCALL LZDone(void);
#define WinAPI_LZDone()	LZDone()
__EXTERN INTEGER __STDCALL LZInit(INTEGER p0);
#define WinAPI_LZInit(p0)	LZInit(p0)
#define WinAPI_LZOpenFile(p0, p1, p2)	LZOpenFileA(p0, p1, p2)
__EXTERN INTEGER __STDCALL LZOpenFileA(LONGINT p0, WinAPI_OFSTRUCT *p1, SHORTINT p2);
#define WinAPI_LZOpenFileA(p0, p1, p2)	LZOpenFileA(p0, p1, p2)
__EXTERN INTEGER __STDCALL LZOpenFileW(LONGINT p0, WinAPI_OFSTRUCT *p1, SHORTINT p2);
#define WinAPI_LZOpenFileW(p0, p1, p2)	LZOpenFileW(p0, p1, p2)
__EXTERN INTEGER __STDCALL LZRead(INTEGER p0, LONGINT p1, INTEGER p2);
#define WinAPI_LZRead(p0, p1, p2)	LZRead(p0, p1, p2)
__EXTERN INTEGER __STDCALL LZSeek(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_LZSeek(p0, p1, p2)	LZSeek(p0, p1, p2)
__EXTERN INTEGER __STDCALL LZStart(void);
#define WinAPI_LZStart()	LZStart()
__EXTERN void __STDCALL LeaveCriticalSection(WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinAPI_LeaveCriticalSection(lpCriticalSection)	LeaveCriticalSection(lpCriticalSection)
__EXTERN INTEGER __STDCALL LineDDA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_LINEDDAPROC p4, LONGINT p5);
#define WinAPI_LineDDA(p0, p1, p2, p3, p4, p5)	LineDDA(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __STDCALL LineTo(LONGINT p0, INTEGER p1, INTEGER p2);
#define WinAPI_LineTo(p0, p1, p2)	LineTo(p0, p1, p2)
#define WinAPI_LoadAccelerators(hInstance, lpTableName)	LoadAcceleratorsA(hInstance, lpTableName)
__EXTERN LONGINT __STDCALL LoadAcceleratorsA(LONGINT hInstance, LONGINT lpTableName);
#define WinAPI_LoadAcceleratorsA(hInstance, lpTableName)	LoadAcceleratorsA(hInstance, lpTableName)
__EXTERN LONGINT __STDCALL LoadAcceleratorsW(LONGINT hInstance, LONGINT lpTableName);
#define WinAPI_LoadAcceleratorsW(hInstance, lpTableName)	LoadAcceleratorsW(hInstance, lpTableName)
#define WinAPI_LoadBitmap(hInstance, lpBitmapName)	LoadBitmapA(hInstance, lpBitmapName)
__EXTERN LONGINT __STDCALL LoadBitmapA(LONGINT hInstance, LONGINT lpBitmapName);
#define WinAPI_LoadBitmapA(hInstance, lpBitmapName)	LoadBitmapA(hInstance, lpBitmapName)
__EXTERN LONGINT __STDCALL LoadBitmapW(LONGINT hInstance, LONGINT lpBitmapName);
#define WinAPI_LoadBitmapW(hInstance, lpBitmapName)	LoadBitmapW(hInstance, lpBitmapName)
#define WinAPI_LoadCursor(hInstance, lpCursorName)	LoadCursorA(hInstance, lpCursorName)
__EXTERN LONGINT __STDCALL LoadCursorA(LONGINT hInstance, LONGINT lpCursorName);
#define WinAPI_LoadCursorA(hInstance, lpCursorName)	LoadCursorA(hInstance, lpCursorName)
#define WinAPI_LoadCursorFromFile(lpFileName)	LoadCursorFromFileA(lpFileName)
__EXTERN LONGINT __STDCALL LoadCursorFromFileA(LONGINT lpFileName);
#define WinAPI_LoadCursorFromFileA(lpFileName)	LoadCursorFromFileA(lpFileName)
__EXTERN LONGINT __STDCALL LoadCursorFromFileW(LONGINT lpFileName);
#define WinAPI_LoadCursorFromFileW(lpFileName)	LoadCursorFromFileW(lpFileName)
__EXTERN LONGINT __STDCALL LoadCursorW(LONGINT hInstance, LONGINT lpCursorName);
#define WinAPI_LoadCursorW(hInstance, lpCursorName)	LoadCursorW(hInstance, lpCursorName)
#define WinAPI_LoadIcon(hInstance, lpIconName)	LoadIconA(hInstance, lpIconName)
__EXTERN LONGINT __STDCALL LoadIconA(LONGINT hInstance, LONGINT lpIconName);
#define WinAPI_LoadIconA(hInstance, lpIconName)	LoadIconA(hInstance, lpIconName)
__EXTERN LONGINT __STDCALL LoadIconW(LONGINT hInstance, LONGINT lpIconName);
#define WinAPI_LoadIconW(hInstance, lpIconName)	LoadIconW(hInstance, lpIconName)
#define WinAPI_LoadImage(p0, p1, p2, p3, p4, p5)	LoadImageA(p0, p1, p2, p3, p4, p5)
__EXTERN LONGINT __STDCALL LoadImageA(LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
#define WinAPI_LoadImageA(p0, p1, p2, p3, p4, p5)	LoadImageA(p0, p1, p2, p3, p4, p5)
__EXTERN LONGINT __STDCALL LoadImageW(LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
#define WinAPI_LoadImageW(p0, p1, p2, p3, p4, p5)	LoadImageW(p0, p1, p2, p3, p4, p5)
#define WinAPI_LoadKeyboardLayout(pwszKLID, Flags)	LoadKeyboardLayoutA(pwszKLID, Flags)
__EXTERN LONGINT __STDCALL LoadKeyboardLayoutA(LONGINT pwszKLID, SET Flags);
#define WinAPI_LoadKeyboardLayoutA(pwszKLID, Flags)	LoadKeyboardLayoutA(pwszKLID, Flags)
__EXTERN LONGINT __STDCALL LoadKeyboardLayoutW(LONGINT pwszKLID, SET Flags);
#define WinAPI_LoadKeyboardLayoutW(pwszKLID, Flags)	LoadKeyboardLayoutW(pwszKLID, Flags)
#define WinAPI_LoadLibrary(lpLibFileName)	LoadLibraryA(lpLibFileName)
__EXTERN LONGINT __STDCALL LoadLibraryA(LONGINT lpLibFileName);
#define WinAPI_LoadLibraryA(lpLibFileName)	LoadLibraryA(lpLibFileName)
#define WinAPI_LoadLibraryEx(lpLibFileName, hFile, dwFlags)	LoadLibraryExA(lpLibFileName, hFile, dwFlags)
__EXTERN LONGINT __STDCALL LoadLibraryExA(LONGINT lpLibFileName, LONGINT hFile, SET dwFlags);
#define WinAPI_LoadLibraryExA(lpLibFileName, hFile, dwFlags)	LoadLibraryExA(lpLibFileName, hFile, dwFlags)
__EXTERN LONGINT __STDCALL LoadLibraryExW(LONGINT lpLibFileName, LONGINT hFile, SET dwFlags);
#define WinAPI_LoadLibraryExW(lpLibFileName, hFile, dwFlags)	LoadLibraryExW(lpLibFileName, hFile, dwFlags)
__EXTERN LONGINT __STDCALL LoadLibraryW(LONGINT lpLibFileName);
#define WinAPI_LoadLibraryW(lpLibFileName)	LoadLibraryW(lpLibFileName)
#define WinAPI_LoadMenu(hInstance, lpMenuName)	LoadMenuA(hInstance, lpMenuName)
__EXTERN LONGINT __STDCALL LoadMenuA(LONGINT hInstance, LONGINT lpMenuName);
#define WinAPI_LoadMenuA(hInstance, lpMenuName)	LoadMenuA(hInstance, lpMenuName)
#define WinAPI_LoadMenuIndirect(lpMenuTemplate)	LoadMenuIndirectA(lpMenuTemplate)
__EXTERN LONGINT __STDCALL LoadMenuIndirectA(WinAPI_PtrMENUTEMPLATEA lpMenuTemplate);
#define WinAPI_LoadMenuIndirectA(lpMenuTemplate)	LoadMenuIndirectA(lpMenuTemplate)
__EXTERN LONGINT __STDCALL LoadMenuIndirectW(WinAPI_PtrMENUTEMPLATEW lpMenuTemplate);
#define WinAPI_LoadMenuIndirectW(lpMenuTemplate)	LoadMenuIndirectW(lpMenuTemplate)
__EXTERN LONGINT __STDCALL LoadMenuW(LONGINT hInstance, LONGINT lpMenuName);
#define WinAPI_LoadMenuW(hInstance, lpMenuName)	LoadMenuW(hInstance, lpMenuName)
__EXTERN INTEGER __STDCALL LoadModule(LONGINT lpModuleName, LONGINT lpParameterBlock);
#define WinAPI_LoadModule(lpModuleName, lpParameterBlock)	LoadModule(lpModuleName, lpParameterBlock)
__EXTERN LONGINT __STDCALL LoadResource(LONGINT hModule, LONGINT hResInfo);
#define WinAPI_LoadResource(hModule, hResInfo)	LoadResource(hModule, hResInfo)
#define WinAPI_LoadString(hInstance, uID, lpBuffer, nBufferMax)	LoadStringA(hInstance, uID, lpBuffer, nBufferMax)
__EXTERN INTEGER __STDCALL LoadStringA(LONGINT hInstance, INTEGER uID, LONGINT lpBuffer, INTEGER nBufferMax);
#define WinAPI_LoadStringA(hInstance, uID, lpBuffer, nBufferMax)	LoadStringA(hInstance, uID, lpBuffer, nBufferMax)
__EXTERN INTEGER __STDCALL LoadStringW(LONGINT hInstance, INTEGER uID, LONGINT lpBuffer, INTEGER nBufferMax);
#define WinAPI_LoadStringW(hInstance, uID, lpBuffer, nBufferMax)	LoadStringW(hInstance, uID, lpBuffer, nBufferMax)
__EXTERN LONGINT __STDCALL LocalAlloc(SET uFlags, LONGINT uBytes);
#define WinAPI_LocalAlloc(uFlags, uBytes)	LocalAlloc(uFlags, uBytes)
__EXTERN LONGINT __STDCALL LocalCompact(INTEGER uMinFree);
#define WinAPI_LocalCompact(uMinFree)	LocalCompact(uMinFree)
__EXTERN INTEGER __STDCALL LocalFileTimeToFileTime(WinAPI_FILETIME *lpLocalFileTime, WinAPI_FILETIME *lpFileTime);
#define WinAPI_LocalFileTimeToFileTime(lpLocalFileTime, lpFileTime)	LocalFileTimeToFileTime(lpLocalFileTime, lpFileTime)
__EXTERN INTEGER __STDCALL LocalFlags(LONGINT hMem);
#define WinAPI_LocalFlags(hMem)	LocalFlags(hMem)
__EXTERN LONGINT __STDCALL LocalFree(LONGINT hMem);
#define WinAPI_LocalFree(hMem)	LocalFree(hMem)
__EXTERN LONGINT __STDCALL LocalHandle(LONGINT pMem);
#define WinAPI_LocalHandle(pMem)	LocalHandle(pMem)
__EXTERN LONGINT __STDCALL LocalLock(LONGINT hMem);
#define WinAPI_LocalLock(hMem)	LocalLock(hMem)
__EXTERN LONGINT __STDCALL LocalReAlloc(LONGINT hMem, LONGINT uBytes, SET uFlags);
#define WinAPI_LocalReAlloc(hMem, uBytes, uFlags)	LocalReAlloc(hMem, uBytes, uFlags)
__EXTERN LONGINT __STDCALL LocalShrink(LONGINT hMem, INTEGER cbNewSize);
#define WinAPI_LocalShrink(hMem, cbNewSize)	LocalShrink(hMem, cbNewSize)
__EXTERN INTEGER __STDCALL LocalSize(LONGINT hMem);
#define WinAPI_LocalSize(hMem)	LocalSize(hMem)
__EXTERN INTEGER __STDCALL LocalUnlock(LONGINT hMem);
#define WinAPI_LocalUnlock(hMem)	LocalUnlock(hMem)
__EXTERN INTEGER __STDCALL LockFile(LONGINT hFile, INTEGER dwFileOffsetLow, INTEGER dwFileOffsetHigh, INTEGER nNumberOfBytesToLockLow, INTEGER nNumberOfBytesToLockHigh);
#define WinAPI_LockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh)	LockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh)
__EXTERN INTEGER __STDCALL LockFileEx(LONGINT hFile, SET dwFlags, INTEGER dwReserved, INTEGER nNumberOfBytesToLockLow, INTEGER nNumberOfBytesToLockHigh, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_LockFileEx(hFile, dwFlags, dwReserved, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh, lpOverlapped)	LockFileEx(hFile, dwFlags, dwReserved, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh, lpOverlapped)
__EXTERN LONGINT __STDCALL LockResource(LONGINT hResData);
#define WinAPI_LockResource(hResData)	LockResource(hResData)
__EXTERN LONGINT __STDCALL LockServiceDatabase(LONGINT hSCManager);
#define WinAPI_LockServiceDatabase(hSCManager)	LockServiceDatabase(hSCManager)
__EXTERN INTEGER __STDCALL LockWindowUpdate(LONGINT hWndLock);
#define WinAPI_LockWindowUpdate(hWndLock)	LockWindowUpdate(hWndLock)
#define WinAPI_LogonUser(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)	LogonUserA(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)
__EXTERN INTEGER __STDCALL LogonUserA(LONGINT lpszUsername, LONGINT lpszDomain, LONGINT lpszPassword, INTEGER dwLogonType, INTEGER dwLogonProvider, LONGINT *phToken);
#define WinAPI_LogonUserA(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)	LogonUserA(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)
__EXTERN INTEGER __STDCALL LogonUserW(LONGINT lpszUsername, LONGINT lpszDomain, LONGINT lpszPassword, INTEGER dwLogonType, INTEGER dwLogonProvider, LONGINT *phToken);
#define WinAPI_LogonUserW(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)	LogonUserW(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)
#define WinAPI_LookupAccountName(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountNameA(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)
__EXTERN INTEGER __STDCALL LookupAccountNameA(LONGINT lpSystemName, LONGINT lpAccountName, LONGINT Sid, INTEGER *cbSid, LONGINT ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
#define WinAPI_LookupAccountNameA(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountNameA(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)
__EXTERN INTEGER __STDCALL LookupAccountNameW(LONGINT lpSystemName, LONGINT lpAccountName, LONGINT Sid, INTEGER *cbSid, LONGINT ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
#define WinAPI_LookupAccountNameW(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountNameW(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)
#define WinAPI_LookupAccountSid(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountSidA(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)
__EXTERN INTEGER __STDCALL LookupAccountSidA(LONGINT lpSystemName, LONGINT Sid, LONGINT Name, INTEGER *cbName, LONGINT ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
#define WinAPI_LookupAccountSidA(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountSidA(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)
__EXTERN INTEGER __STDCALL LookupAccountSidW(LONGINT lpSystemName, LONGINT Sid, LONGINT Name, INTEGER *cbName, LONGINT ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
#define WinAPI_LookupAccountSidW(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountSidW(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)
__EXTERN INTEGER __STDCALL LookupIconIdFromDirectory(CHAR *presbits, INTEGER fIcon);
#define WinAPI_LookupIconIdFromDirectory(presbits, fIcon)	LookupIconIdFromDirectory(presbits, fIcon)
__EXTERN INTEGER __STDCALL LookupIconIdFromDirectoryEx(CHAR *presbits, INTEGER fIcon, INTEGER cxDesired, INTEGER cyDesired, SET Flags);
#define WinAPI_LookupIconIdFromDirectoryEx(presbits, fIcon, cxDesired, cyDesired, Flags)	LookupIconIdFromDirectoryEx(presbits, fIcon, cxDesired, cyDesired, Flags)
#define WinAPI_LookupPrivilegeDisplayName(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)	LookupPrivilegeDisplayNameA(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)
__EXTERN INTEGER __STDCALL LookupPrivilegeDisplayNameA(LONGINT lpSystemName, LONGINT lpName, LONGINT lpDisplayName, INTEGER *cbDisplayName, INTEGER *lpLanguageId);
#define WinAPI_LookupPrivilegeDisplayNameA(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)	LookupPrivilegeDisplayNameA(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)
__EXTERN INTEGER __STDCALL LookupPrivilegeDisplayNameW(LONGINT lpSystemName, LONGINT lpName, LONGINT lpDisplayName, INTEGER *cbDisplayName, INTEGER *lpLanguageId);
#define WinAPI_LookupPrivilegeDisplayNameW(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)	LookupPrivilegeDisplayNameW(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)
#define WinAPI_LookupPrivilegeName(lpSystemName, lpLuid, lpName, cbName)	LookupPrivilegeNameA(lpSystemName, lpLuid, lpName, cbName)
__EXTERN INTEGER __STDCALL LookupPrivilegeNameA(LONGINT lpSystemName, LONGINT *lpLuid, LONGINT lpName, INTEGER *cbName);
#define WinAPI_LookupPrivilegeNameA(lpSystemName, lpLuid, lpName, cbName)	LookupPrivilegeNameA(lpSystemName, lpLuid, lpName, cbName)
__EXTERN INTEGER __STDCALL LookupPrivilegeNameW(LONGINT lpSystemName, LONGINT *lpLuid, LONGINT lpName, INTEGER *cbName);
#define WinAPI_LookupPrivilegeNameW(lpSystemName, lpLuid, lpName, cbName)	LookupPrivilegeNameW(lpSystemName, lpLuid, lpName, cbName)
#define WinAPI_LookupPrivilegeValue(lpSystemName, lpName, lpLuid)	LookupPrivilegeValueA(lpSystemName, lpName, lpLuid)
__EXTERN INTEGER __STDCALL LookupPrivilegeValueA(LONGINT lpSystemName, LONGINT lpName, LONGINT *lpLuid);
#define WinAPI_LookupPrivilegeValueA(lpSystemName, lpName, lpLuid)	LookupPrivilegeValueA(lpSystemName, lpName, lpLuid)
__EXTERN INTEGER __STDCALL LookupPrivilegeValueW(LONGINT lpSystemName, LONGINT lpName, LONGINT *lpLuid);
#define WinAPI_LookupPrivilegeValueW(lpSystemName, lpName, lpLuid)	LookupPrivilegeValueW(lpSystemName, lpName, lpLuid)
__EXTERN INTEGER __STDCALL MakeAbsoluteSD(LONGINT pSelfRelativeSecurityDescriptor, LONGINT pAbsoluteSecurityDescriptor, INTEGER *lpdwAbsoluteSecurityDescriptorSize, WinAPI_ACL *pDacl, INTEGER *lpdwDaclSize, WinAPI_ACL *pSacl, INTEGER *lpdwSaclSize, LONGINT pOwner, INTEGER *lpdwOwnerSize, LONGINT pPrimaryGroup, INTEGER *lpdwPrimaryGroupSize);
#define WinAPI_MakeAbsoluteSD(pSelfRelativeSecurityDescriptor, pAbsoluteSecurityDescriptor, lpdwAbsoluteSecurityDescriptorSize, pDacl, lpdwDaclSize, pSacl, lpdwSaclSize, pOwner, lpdwOwnerSize, pPrimaryGroup, lpdwPrimaryGroupSize)	MakeAbsoluteSD(pSelfRelativeSecurityDescriptor, pAbsoluteSecurityDescriptor, lpdwAbsoluteSecurityDescriptorSize, pDacl, lpdwDaclSize, pSacl, lpdwSaclSize, pOwner, lpdwOwnerSize, pPrimaryGroup, lpdwPrimaryGroupSize)
__EXTERN INTEGER __STDCALL MakeSelfRelativeSD(LONGINT pAbsoluteSecurityDescriptor, LONGINT pSelfRelativeSecurityDescriptor, INTEGER *lpdwBufferLength);
#define WinAPI_MakeSelfRelativeSD(pAbsoluteSecurityDescriptor, pSelfRelativeSecurityDescriptor, lpdwBufferLength)	MakeSelfRelativeSD(pAbsoluteSecurityDescriptor, pSelfRelativeSecurityDescriptor, lpdwBufferLength)
__EXTERN INTEGER __STDCALL MapDialogRect(LONGINT hDlg, WinAPI_RECT *lpRect);
#define WinAPI_MapDialogRect(hDlg, lpRect)	MapDialogRect(hDlg, lpRect)
__EXTERN void __STDCALL MapGenericMask(INTEGER *AccessMask, WinAPI_GENERIC_MAPPING *GenericMapping);
#define WinAPI_MapGenericMask(AccessMask, GenericMapping)	MapGenericMask(AccessMask, GenericMapping)
__EXTERN LONGINT __STDCALL MapViewOfFile(LONGINT hFileMappingObject, SET dwDesiredAccess, INTEGER dwFileOffsetHigh, INTEGER dwFileOffsetLow, INTEGER dwNumberOfBytesToMap);
#define WinAPI_MapViewOfFile(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap)	MapViewOfFile(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap)
__EXTERN LONGINT __STDCALL MapViewOfFileEx(LONGINT hFileMappingObject, SET dwDesiredAccess, INTEGER dwFileOffsetHigh, INTEGER dwFileOffsetLow, INTEGER dwNumberOfBytesToMap, LONGINT lpBaseAddress);
#define WinAPI_MapViewOfFileEx(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress)	MapViewOfFileEx(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress)
#define WinAPI_MapVirtualKey(uCode, uMapType)	MapVirtualKeyA(uCode, uMapType)
__EXTERN INTEGER __STDCALL MapVirtualKeyA(INTEGER uCode, INTEGER uMapType);
#define WinAPI_MapVirtualKeyA(uCode, uMapType)	MapVirtualKeyA(uCode, uMapType)
#define WinAPI_MapVirtualKeyEx(uCode, uMapType, dwhkl)	MapVirtualKeyExA(uCode, uMapType, dwhkl)
__EXTERN INTEGER __STDCALL MapVirtualKeyExA(INTEGER uCode, INTEGER uMapType, LONGINT dwhkl);
#define WinAPI_MapVirtualKeyExA(uCode, uMapType, dwhkl)	MapVirtualKeyExA(uCode, uMapType, dwhkl)
__EXTERN INTEGER __STDCALL MapVirtualKeyExW(INTEGER uCode, INTEGER uMapType, LONGINT dwhkl);
#define WinAPI_MapVirtualKeyExW(uCode, uMapType, dwhkl)	MapVirtualKeyExW(uCode, uMapType, dwhkl)
__EXTERN INTEGER __STDCALL MapVirtualKeyW(INTEGER uCode, INTEGER uMapType);
#define WinAPI_MapVirtualKeyW(uCode, uMapType)	MapVirtualKeyW(uCode, uMapType)
__EXTERN INTEGER __STDCALL MapWindowPoints(LONGINT hWndFrom, LONGINT hWndTo, WinAPI_POINT *lpPoints, INTEGER cPoints);
#define WinAPI_MapWindowPoints(hWndFrom, hWndTo, lpPoints, cPoints)	MapWindowPoints(hWndFrom, hWndTo, lpPoints, cPoints)
__EXTERN INTEGER __STDCALL MaskBlt(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, LONGINT p5, INTEGER p6, INTEGER p7, LONGINT p8, INTEGER p9, INTEGER p10, INTEGER p11);
#define WinAPI_MaskBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)	MaskBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)
__EXTERN INTEGER __STDCALL MenuItemFromPoint(LONGINT hWnd, LONGINT hMenu, WinAPI_POINT *ptScreen);
#define WinAPI_MenuItemFromPoint(hWnd, hMenu, ptScreen)	MenuItemFromPoint(hWnd, hMenu, ptScreen)
__EXTERN INTEGER __STDCALL MessageBeep(SET uType);
#define WinAPI_MessageBeep(uType)	MessageBeep(uType)
#define WinAPI_MessageBox(hWnd, lpText, lpCaption, uType)	MessageBoxA(hWnd, lpText, lpCaption, uType)
__EXTERN INTEGER __STDCALL MessageBoxA(LONGINT hWnd, LONGINT lpText, LONGINT lpCaption, SET uType);
#define WinAPI_MessageBoxA(hWnd, lpText, lpCaption, uType)	MessageBoxA(hWnd, lpText, lpCaption, uType)
#define WinAPI_MessageBoxEx(hWnd, lpText, lpCaption, uType, wLanguageId)	MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId)
__EXTERN INTEGER __STDCALL MessageBoxExA(LONGINT hWnd, LONGINT lpText, LONGINT lpCaption, SET uType, SHORTINT wLanguageId);
#define WinAPI_MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId)	MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId)
__EXTERN INTEGER __STDCALL MessageBoxExW(LONGINT hWnd, LONGINT lpText, LONGINT lpCaption, SET uType, SHORTINT wLanguageId);
#define WinAPI_MessageBoxExW(hWnd, lpText, lpCaption, uType, wLanguageId)	MessageBoxExW(hWnd, lpText, lpCaption, uType, wLanguageId)
#define WinAPI_MessageBoxIndirect(p0)	MessageBoxIndirectA(p0)
__EXTERN INTEGER __STDCALL MessageBoxIndirectA(WinAPI_MSGBOXPARAMSA *p0);
#define WinAPI_MessageBoxIndirectA(p0)	MessageBoxIndirectA(p0)
__EXTERN INTEGER __STDCALL MessageBoxIndirectW(WinAPI_MSGBOXPARAMSW *p0);
#define WinAPI_MessageBoxIndirectW(p0)	MessageBoxIndirectW(p0)
__EXTERN INTEGER __STDCALL MessageBoxW(LONGINT hWnd, LONGINT lpText, LONGINT lpCaption, SET uType);
#define WinAPI_MessageBoxW(hWnd, lpText, lpCaption, uType)	MessageBoxW(hWnd, lpText, lpCaption, uType)
#define WinAPI_ModifyMenu(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)	ModifyMenuA(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __STDCALL ModifyMenuA(LONGINT hMnu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, LONGINT lpNewItem);
#define WinAPI_ModifyMenuA(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)	ModifyMenuA(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __STDCALL ModifyMenuW(LONGINT hMnu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, LONGINT lpNewItem);
#define WinAPI_ModifyMenuW(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)	ModifyMenuW(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __STDCALL ModifyWorldTransform(LONGINT p0, WinAPI_XFORM *p1, INTEGER p2);
#define WinAPI_ModifyWorldTransform(p0, p1, p2)	ModifyWorldTransform(p0, p1, p2)
#define WinAPI_MoveFile(lpExistingFileName, lpNewFileName)	MoveFileA(lpExistingFileName, lpNewFileName)
__EXTERN INTEGER __STDCALL MoveFileA(LONGINT lpExistingFileName, LONGINT lpNewFileName);
#define WinAPI_MoveFileA(lpExistingFileName, lpNewFileName)	MoveFileA(lpExistingFileName, lpNewFileName)
#define WinAPI_MoveFileEx(lpExistingFileName, lpNewFileName, dwFlags)	MoveFileExA(lpExistingFileName, lpNewFileName, dwFlags)
__EXTERN INTEGER __STDCALL MoveFileExA(LONGINT lpExistingFileName, LONGINT lpNewFileName, SET dwFlags);
#define WinAPI_MoveFileExA(lpExistingFileName, lpNewFileName, dwFlags)	MoveFileExA(lpExistingFileName, lpNewFileName, dwFlags)
__EXTERN INTEGER __STDCALL MoveFileExW(LONGINT lpExistingFileName, LONGINT lpNewFileName, SET dwFlags);
#define WinAPI_MoveFileExW(lpExistingFileName, lpNewFileName, dwFlags)	MoveFileExW(lpExistingFileName, lpNewFileName, dwFlags)
__EXTERN INTEGER __STDCALL MoveFileW(LONGINT lpExistingFileName, LONGINT lpNewFileName);
#define WinAPI_MoveFileW(lpExistingFileName, lpNewFileName)	MoveFileW(lpExistingFileName, lpNewFileName)
__EXTERN INTEGER __STDCALL MoveToEx(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_MoveToEx(p0, p1, p2, p3)	MoveToEx(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL MoveWindow(LONGINT hWnd, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER bRepaint);
#define WinAPI_MoveWindow(hWnd, X, Y, nWidth, nHeight, bRepaint)	MoveWindow(hWnd, X, Y, nWidth, nHeight, bRepaint)
__EXTERN INTEGER __STDCALL MsgWaitForMultipleObjects(INTEGER nCount, LONGINT *pHandles, INTEGER fWaitAll, INTEGER dwMilliseconds, INTEGER dwWakeMask);
#define WinAPI_MsgWaitForMultipleObjects(nCount, pHandles, fWaitAll, dwMilliseconds, dwWakeMask)	MsgWaitForMultipleObjects(nCount, pHandles, fWaitAll, dwMilliseconds, dwWakeMask)
__EXTERN INTEGER __STDCALL MsgWaitForMultipleObjectsEx(INTEGER nCount, LONGINT *pHandles, INTEGER dwMilliseconds, INTEGER dwWakeMask, SET dwFlags);
#define WinAPI_MsgWaitForMultipleObjectsEx(nCount, pHandles, dwMilliseconds, dwWakeMask, dwFlags)	MsgWaitForMultipleObjectsEx(nCount, pHandles, dwMilliseconds, dwWakeMask, dwFlags)
__EXTERN INTEGER __STDCALL MulDiv(INTEGER nNumber, INTEGER nNumerator, INTEGER nDenominator);
#define WinAPI_MulDiv(nNumber, nNumerator, nDenominator)	MulDiv(nNumber, nNumerator, nDenominator)
__EXTERN INTEGER __STDCALL MultiByteToWideChar(INTEGER CodePage, SET dwFlags, LONGINT lpMultiByteStr, INTEGER cchMultiByte, LONGINT lpWideCharStr, INTEGER cchWideChar);
#define WinAPI_MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cchMultiByte, lpWideCharStr, cchWideChar)	MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cchMultiByte, lpWideCharStr, cchWideChar)
__EXTERN INTEGER __STDCALL NotifyBootConfigStatus(INTEGER BootAcceptable);
#define WinAPI_NotifyBootConfigStatus(BootAcceptable)	NotifyBootConfigStatus(BootAcceptable)
__EXTERN INTEGER __STDCALL NotifyChangeEventLog(LONGINT hEventLog, LONGINT hEvent);
#define WinAPI_NotifyChangeEventLog(hEventLog, hEvent)	NotifyChangeEventLog(hEventLog, hEvent)
#define WinAPI_ObjectCloseAuditAlarm(SubsystemName, HandleId, GenerateOnClose)	ObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose)
__EXTERN INTEGER __STDCALL ObjectCloseAuditAlarmA(LONGINT SubsystemName, LONGINT HandleId, INTEGER GenerateOnClose);
#define WinAPI_ObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose)	ObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose)
__EXTERN INTEGER __STDCALL ObjectCloseAuditAlarmW(LONGINT SubsystemName, LONGINT HandleId, INTEGER GenerateOnClose);
#define WinAPI_ObjectCloseAuditAlarmW(SubsystemName, HandleId, GenerateOnClose)	ObjectCloseAuditAlarmW(SubsystemName, HandleId, GenerateOnClose)
#define WinAPI_ObjectOpenAuditAlarm(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)	ObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)
__EXTERN INTEGER __STDCALL ObjectOpenAuditAlarmA(LONGINT SubsystemName, LONGINT HandleId, LONGINT ObjectTypeName, LONGINT ObjectName, LONGINT pSecurityDescriptor, LONGINT ClientToken, SET DesiredAccess, INTEGER GrantedAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER ObjectCreation, INTEGER AccessGranted, INTEGER *GenerateOnClose);
#define WinAPI_ObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)	ObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)
__EXTERN INTEGER __STDCALL ObjectOpenAuditAlarmW(LONGINT SubsystemName, LONGINT HandleId, LONGINT ObjectTypeName, LONGINT ObjectName, LONGINT pSecurityDescriptor, LONGINT ClientToken, SET DesiredAccess, INTEGER GrantedAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER ObjectCreation, INTEGER AccessGranted, INTEGER *GenerateOnClose);
#define WinAPI_ObjectOpenAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)	ObjectOpenAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)
#define WinAPI_ObjectPrivilegeAuditAlarm(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)	ObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)
__EXTERN INTEGER __STDCALL ObjectPrivilegeAuditAlarmA(LONGINT SubsystemName, LONGINT HandleId, LONGINT ClientToken, SET DesiredAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
#define WinAPI_ObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)	ObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)
__EXTERN INTEGER __STDCALL ObjectPrivilegeAuditAlarmW(LONGINT SubsystemName, LONGINT HandleId, LONGINT ClientToken, SET DesiredAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
#define WinAPI_ObjectPrivilegeAuditAlarmW(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)	ObjectPrivilegeAuditAlarmW(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)
__EXTERN INTEGER __STDCALL OemKeyScan(SHORTINT wOemChar);
#define WinAPI_OemKeyScan(wOemChar)	OemKeyScan(wOemChar)
#define WinAPI_OemToAnsi(lpszSrc, lpszDst)	OemToCharA(lpszSrc, lpszDst)
#define WinAPI_OemToAnsiBuff(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinAPI_OemToChar(lpszSrc, lpszDst)	OemToCharA(lpszSrc, lpszDst)
__EXTERN INTEGER __STDCALL OemToCharA(LONGINT lpszSrc, LONGINT lpszDst);
#define WinAPI_OemToCharA(lpszSrc, lpszDst)	OemToCharA(lpszSrc, lpszDst)
#define WinAPI_OemToCharBuff(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __STDCALL OemToCharBuffA(LONGINT lpszSrc, LONGINT lpszDst, INTEGER cchDstLength);
#define WinAPI_OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __STDCALL OemToCharBuffW(LONGINT lpszSrc, LONGINT lpszDst, INTEGER cchDstLength);
#define WinAPI_OemToCharBuffW(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffW(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __STDCALL OemToCharW(LONGINT lpszSrc, LONGINT lpszDst);
#define WinAPI_OemToCharW(lpszSrc, lpszDst)	OemToCharW(lpszSrc, lpszDst)
__EXTERN INTEGER __STDCALL OffsetClipRgn(LONGINT p0, INTEGER p1, INTEGER p2);
#define WinAPI_OffsetClipRgn(p0, p1, p2)	OffsetClipRgn(p0, p1, p2)
__EXTERN INTEGER __STDCALL OffsetRect(WinAPI_RECT *lprc, INTEGER dx, INTEGER dy);
#define WinAPI_OffsetRect(lprc, dx, dy)	OffsetRect(lprc, dx, dy)
__EXTERN INTEGER __STDCALL OffsetRgn(LONGINT p0, INTEGER p1, INTEGER p2);
#define WinAPI_OffsetRgn(p0, p1, p2)	OffsetRgn(p0, p1, p2)
__EXTERN INTEGER __STDCALL OffsetViewportOrgEx(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_OffsetViewportOrgEx(p0, p1, p2, p3)	OffsetViewportOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL OffsetWindowOrgEx(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_OffsetWindowOrgEx(p0, p1, p2, p3)	OffsetWindowOrgEx(p0, p1, p2, p3)
#define WinAPI_OpenBackupEventLog(lpUNCServerName, lpFileName)	OpenBackupEventLogA(lpUNCServerName, lpFileName)
__EXTERN LONGINT __STDCALL OpenBackupEventLogA(LONGINT lpUNCServerName, LONGINT lpFileName);
#define WinAPI_OpenBackupEventLogA(lpUNCServerName, lpFileName)	OpenBackupEventLogA(lpUNCServerName, lpFileName)
__EXTERN LONGINT __STDCALL OpenBackupEventLogW(LONGINT lpUNCServerName, LONGINT lpFileName);
#define WinAPI_OpenBackupEventLogW(lpUNCServerName, lpFileName)	OpenBackupEventLogW(lpUNCServerName, lpFileName)
__EXTERN INTEGER __STDCALL OpenClipboard(LONGINT hWndNewOwner);
#define WinAPI_OpenClipboard(hWndNewOwner)	OpenClipboard(hWndNewOwner)
#define WinAPI_OpenDesktop(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)	OpenDesktopA(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)
__EXTERN LONGINT __STDCALL OpenDesktopA(LONGINT lpszDesktop, SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
#define WinAPI_OpenDesktopA(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)	OpenDesktopA(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)
__EXTERN LONGINT __STDCALL OpenDesktopW(LONGINT lpszDesktop, SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
#define WinAPI_OpenDesktopW(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)	OpenDesktopW(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)
#define WinAPI_OpenEvent(dwDesiredAccess, bInheritHandle, lpName)	OpenEventA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN LONGINT __STDCALL OpenEventA(SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
#define WinAPI_OpenEventA(dwDesiredAccess, bInheritHandle, lpName)	OpenEventA(dwDesiredAccess, bInheritHandle, lpName)
#define WinAPI_OpenEventLog(lpUNCServerName, lpSourceName)	OpenEventLogA(lpUNCServerName, lpSourceName)
__EXTERN LONGINT __STDCALL OpenEventLogA(LONGINT lpUNCServerName, LONGINT lpSourceName);
#define WinAPI_OpenEventLogA(lpUNCServerName, lpSourceName)	OpenEventLogA(lpUNCServerName, lpSourceName)
__EXTERN LONGINT __STDCALL OpenEventLogW(LONGINT lpUNCServerName, LONGINT lpSourceName);
#define WinAPI_OpenEventLogW(lpUNCServerName, lpSourceName)	OpenEventLogW(lpUNCServerName, lpSourceName)
__EXTERN LONGINT __STDCALL OpenEventW(SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
#define WinAPI_OpenEventW(dwDesiredAccess, bInheritHandle, lpName)	OpenEventW(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __STDCALL OpenFile(LONGINT lpFileName, WinAPI_OFSTRUCT *lpReOpenBuff, SET uStyle);
#define WinAPI_OpenFile(lpFileName, lpReOpenBuff, uStyle)	OpenFile(lpFileName, lpReOpenBuff, uStyle)
#define WinAPI_OpenFileMapping(dwDesiredAccess, bInheritHandle, lpName)	OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN LONGINT __STDCALL OpenFileMappingA(SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
#define WinAPI_OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName)	OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN LONGINT __STDCALL OpenFileMappingW(SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
#define WinAPI_OpenFileMappingW(dwDesiredAccess, bInheritHandle, lpName)	OpenFileMappingW(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __STDCALL OpenIcon(LONGINT hWnd);
#define WinAPI_OpenIcon(hWnd)	OpenIcon(hWnd)
__EXTERN LONGINT __STDCALL OpenInputDesktop(SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
#define WinAPI_OpenInputDesktop(dwFlags, fInherit, dwDesiredAccess)	OpenInputDesktop(dwFlags, fInherit, dwDesiredAccess)
#define WinAPI_OpenMutex(dwDesiredAccess, bInheritHandle, lpName)	OpenMutexA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN LONGINT __STDCALL OpenMutexA(SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
#define WinAPI_OpenMutexA(dwDesiredAccess, bInheritHandle, lpName)	OpenMutexA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN LONGINT __STDCALL OpenMutexW(SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
#define WinAPI_OpenMutexW(dwDesiredAccess, bInheritHandle, lpName)	OpenMutexW(dwDesiredAccess, bInheritHandle, lpName)
#define WinAPI_OpenPrinter(pPrinterName, phPrinter, pDefault)	OpenPrinterA(pPrinterName, phPrinter, pDefault)
__EXTERN INTEGER __STDCALL OpenPrinterA(LONGINT pPrinterName, LONGINT *phPrinter, WinAPI_PRINTER_DEFAULTSA *pDefault);
#define WinAPI_OpenPrinterA(pPrinterName, phPrinter, pDefault)	OpenPrinterA(pPrinterName, phPrinter, pDefault)
__EXTERN INTEGER __STDCALL OpenPrinterW(LONGINT pPrinterName, LONGINT *phPrinter, WinAPI_PRINTER_DEFAULTSW *pDefault);
#define WinAPI_OpenPrinterW(pPrinterName, phPrinter, pDefault)	OpenPrinterW(pPrinterName, phPrinter, pDefault)
__EXTERN LONGINT __STDCALL OpenProcess(SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER dwProcessId);
#define WinAPI_OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId)	OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId)
__EXTERN INTEGER __STDCALL OpenProcessToken(LONGINT ProcessHandle, SET DesiredAccess, LONGINT *TokenHandle);
#define WinAPI_OpenProcessToken(ProcessHandle, DesiredAccess, TokenHandle)	OpenProcessToken(ProcessHandle, DesiredAccess, TokenHandle)
#define WinAPI_OpenSCManager(lpMachineName, lpDatabaseName, dwDesiredAccess)	OpenSCManagerA(lpMachineName, lpDatabaseName, dwDesiredAccess)
__EXTERN LONGINT __STDCALL OpenSCManagerA(LONGINT lpMachineName, LONGINT lpDatabaseName, SET dwDesiredAccess);
#define WinAPI_OpenSCManagerA(lpMachineName, lpDatabaseName, dwDesiredAccess)	OpenSCManagerA(lpMachineName, lpDatabaseName, dwDesiredAccess)
__EXTERN LONGINT __STDCALL OpenSCManagerW(LONGINT lpMachineName, LONGINT lpDatabaseName, SET dwDesiredAccess);
#define WinAPI_OpenSCManagerW(lpMachineName, lpDatabaseName, dwDesiredAccess)	OpenSCManagerW(lpMachineName, lpDatabaseName, dwDesiredAccess)
#define WinAPI_OpenSemaphore(dwDesiredAccess, bInheritHandle, lpName)	OpenSemaphoreA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN LONGINT __STDCALL OpenSemaphoreA(SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
#define WinAPI_OpenSemaphoreA(dwDesiredAccess, bInheritHandle, lpName)	OpenSemaphoreA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN LONGINT __STDCALL OpenSemaphoreW(SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpName);
#define WinAPI_OpenSemaphoreW(dwDesiredAccess, bInheritHandle, lpName)	OpenSemaphoreW(dwDesiredAccess, bInheritHandle, lpName)
#define WinAPI_OpenService(hSCManager, lpServiceName, dwDesiredAccess)	OpenServiceA(hSCManager, lpServiceName, dwDesiredAccess)
__EXTERN LONGINT __STDCALL OpenServiceA(LONGINT hSCManager, LONGINT lpServiceName, SET dwDesiredAccess);
#define WinAPI_OpenServiceA(hSCManager, lpServiceName, dwDesiredAccess)	OpenServiceA(hSCManager, lpServiceName, dwDesiredAccess)
__EXTERN LONGINT __STDCALL OpenServiceW(LONGINT hSCManager, LONGINT lpServiceName, SET dwDesiredAccess);
#define WinAPI_OpenServiceW(hSCManager, lpServiceName, dwDesiredAccess)	OpenServiceW(hSCManager, lpServiceName, dwDesiredAccess)
__EXTERN INTEGER __STDCALL OpenThreadToken(LONGINT ThreadHandle, SET DesiredAccess, INTEGER OpenAsSelf, LONGINT *TokenHandle);
#define WinAPI_OpenThreadToken(ThreadHandle, DesiredAccess, OpenAsSelf, TokenHandle)	OpenThreadToken(ThreadHandle, DesiredAccess, OpenAsSelf, TokenHandle)
#define WinAPI_OpenWaitableTimer(dwDesiredAccess, bInheritHandle, lpTimerName)	OpenWaitableTimerA(dwDesiredAccess, bInheritHandle, lpTimerName)
__EXTERN LONGINT __STDCALL OpenWaitableTimerA(SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpTimerName);
#define WinAPI_OpenWaitableTimerA(dwDesiredAccess, bInheritHandle, lpTimerName)	OpenWaitableTimerA(dwDesiredAccess, bInheritHandle, lpTimerName)
__EXTERN LONGINT __STDCALL OpenWaitableTimerW(SET dwDesiredAccess, INTEGER bInheritHandle, LONGINT lpTimerName);
#define WinAPI_OpenWaitableTimerW(dwDesiredAccess, bInheritHandle, lpTimerName)	OpenWaitableTimerW(dwDesiredAccess, bInheritHandle, lpTimerName)
#define WinAPI_OpenWindowStation(lpszWinSta, fInherit, dwDesiredAccess)	OpenWindowStationA(lpszWinSta, fInherit, dwDesiredAccess)
__EXTERN LONGINT __STDCALL OpenWindowStationA(LONGINT lpszWinSta, INTEGER fInherit, SET dwDesiredAccess);
#define WinAPI_OpenWindowStationA(lpszWinSta, fInherit, dwDesiredAccess)	OpenWindowStationA(lpszWinSta, fInherit, dwDesiredAccess)
__EXTERN LONGINT __STDCALL OpenWindowStationW(LONGINT lpszWinSta, INTEGER fInherit, SET dwDesiredAccess);
#define WinAPI_OpenWindowStationW(lpszWinSta, fInherit, dwDesiredAccess)	OpenWindowStationW(lpszWinSta, fInherit, dwDesiredAccess)
#define WinAPI_OutputDebugString(lpOutputString)	OutputDebugStringA(lpOutputString)
__EXTERN void __STDCALL OutputDebugStringA(LONGINT lpOutputString);
#define WinAPI_OutputDebugStringA(lpOutputString)	OutputDebugStringA(lpOutputString)
__EXTERN void __STDCALL OutputDebugStringW(LONGINT lpOutputString);
#define WinAPI_OutputDebugStringW(lpOutputString)	OutputDebugStringW(lpOutputString)
__EXTERN INTEGER __STDCALL PackDDElParam(INTEGER msg, INTEGER uiLo, INTEGER uiHi);
#define WinAPI_PackDDElParam(msg, uiLo, uiHi)	PackDDElParam(msg, uiLo, uiHi)
__EXTERN INTEGER __STDCALL PaintDesktop(LONGINT hdc);
#define WinAPI_PaintDesktop(hdc)	PaintDesktop(hdc)
__EXTERN INTEGER __STDCALL PaintRgn(LONGINT p0, LONGINT p1);
#define WinAPI_PaintRgn(p0, p1)	PaintRgn(p0, p1)
__EXTERN INTEGER __STDCALL PatBlt(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
#define WinAPI_PatBlt(p0, p1, p2, p3, p4, p5)	PatBlt(p0, p1, p2, p3, p4, p5)
__EXTERN LONGINT __STDCALL PathToRegion(LONGINT p0);
#define WinAPI_PathToRegion(p0)	PathToRegion(p0)
#define WinAPI_PeekConsoleInput(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)	PeekConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
__EXTERN INTEGER __STDCALL PeekConsoleInputA(LONGINT hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
#define WinAPI_PeekConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)	PeekConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
__EXTERN INTEGER __STDCALL PeekConsoleInputW(LONGINT hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
#define WinAPI_PeekConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)	PeekConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
#define WinAPI_PeekMessage(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)	PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)
__EXTERN INTEGER __STDCALL PeekMessageA(WinAPI_MSG *lpMsg, LONGINT hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax, INTEGER wRemoveMsg);
#define WinAPI_PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)	PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)
__EXTERN INTEGER __STDCALL PeekMessageW(WinAPI_MSG *lpMsg, LONGINT hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax, INTEGER wRemoveMsg);
#define WinAPI_PeekMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)	PeekMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)
__EXTERN INTEGER __STDCALL PeekNamedPipe(LONGINT hNamedPipe, LONGINT lpBuffer, INTEGER nBufferSize, INTEGER *lpBytesRead, INTEGER *lpTotalBytesAvail, INTEGER *lpBytesLeftThisMessage);
#define WinAPI_PeekNamedPipe(hNamedPipe, lpBuffer, nBufferSize, lpBytesRead, lpTotalBytesAvail, lpBytesLeftThisMessage)	PeekNamedPipe(hNamedPipe, lpBuffer, nBufferSize, lpBytesRead, lpTotalBytesAvail, lpBytesLeftThisMessage)
__EXTERN INTEGER __STDCALL Pie(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinAPI_Pie(p0, p1, p2, p3, p4, p5, p6, p7, p8)	Pie(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __STDCALL PlayEnhMetaFile(LONGINT p0, LONGINT p1, WinAPI_RECT *p2);
#define WinAPI_PlayEnhMetaFile(p0, p1, p2)	PlayEnhMetaFile(p0, p1, p2)
__EXTERN INTEGER __STDCALL PlayEnhMetaFileRecord(LONGINT p0, WinAPI_HANDLETABLE *p1, WinAPI_ENHMETARECORD *p2, INTEGER p3);
#define WinAPI_PlayEnhMetaFileRecord(p0, p1, p2, p3)	PlayEnhMetaFileRecord(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL PlayMetaFile(LONGINT p0, LONGINT p1);
#define WinAPI_PlayMetaFile(p0, p1)	PlayMetaFile(p0, p1)
__EXTERN INTEGER __STDCALL PlayMetaFileRecord(LONGINT p0, WinAPI_HANDLETABLE *p1, WinAPI_METARECORD *p2, INTEGER p3);
#define WinAPI_PlayMetaFileRecord(p0, p1, p2, p3)	PlayMetaFileRecord(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL PlgBlt(LONGINT p0, WinAPI_POINT *p1, LONGINT p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, LONGINT p7, INTEGER p8, INTEGER p9);
#define WinAPI_PlgBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)	PlgBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)
__EXTERN INTEGER __STDCALL PolyBezier(LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_PolyBezier(p0, p1, p2)	PolyBezier(p0, p1, p2)
__EXTERN INTEGER __STDCALL PolyBezierTo(LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_PolyBezierTo(p0, p1, p2)	PolyBezierTo(p0, p1, p2)
__EXTERN INTEGER __STDCALL PolyDraw(LONGINT p0, WinAPI_POINT *p1, CHAR *p2, INTEGER p3);
#define WinAPI_PolyDraw(p0, p1, p2, p3)	PolyDraw(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL PolyPolygon(LONGINT p0, WinAPI_POINT *p1, INTEGER *p2, INTEGER p3);
#define WinAPI_PolyPolygon(p0, p1, p2, p3)	PolyPolygon(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL PolyPolyline(LONGINT p0, WinAPI_POINT *p1, INTEGER *p2, INTEGER p3);
#define WinAPI_PolyPolyline(p0, p1, p2, p3)	PolyPolyline(p0, p1, p2, p3)
#define WinAPI_PolyTextOut(p0, p1, p2)	PolyTextOutA(p0, p1, p2)
__EXTERN INTEGER __STDCALL PolyTextOutA(LONGINT p0, WinAPI_POLYTEXTA *p1, INTEGER p2);
#define WinAPI_PolyTextOutA(p0, p1, p2)	PolyTextOutA(p0, p1, p2)
__EXTERN INTEGER __STDCALL PolyTextOutW(LONGINT p0, WinAPI_POLYTEXTW *p1, INTEGER p2);
#define WinAPI_PolyTextOutW(p0, p1, p2)	PolyTextOutW(p0, p1, p2)
__EXTERN INTEGER __STDCALL Polygon(LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_Polygon(p0, p1, p2)	Polygon(p0, p1, p2)
__EXTERN INTEGER __STDCALL Polyline(LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_Polyline(p0, p1, p2)	Polyline(p0, p1, p2)
__EXTERN INTEGER __STDCALL PolylineTo(LONGINT p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_PolylineTo(p0, p1, p2)	PolylineTo(p0, p1, p2)
#define WinAPI_PostMessage(hWnd, Msg, wParam, lParam)	PostMessageA(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __STDCALL PostMessageA(LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_PostMessageA(hWnd, Msg, wParam, lParam)	PostMessageA(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __STDCALL PostMessageW(LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_PostMessageW(hWnd, Msg, wParam, lParam)	PostMessageW(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __STDCALL PostQueuedCompletionStatus(LONGINT CompletionPort, INTEGER dwNumberOfBytesTransferred, INTEGER dwCompletionKey, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_PostQueuedCompletionStatus(CompletionPort, dwNumberOfBytesTransferred, dwCompletionKey, lpOverlapped)	PostQueuedCompletionStatus(CompletionPort, dwNumberOfBytesTransferred, dwCompletionKey, lpOverlapped)
__EXTERN void __STDCALL PostQuitMessage(INTEGER nExitCode);
#define WinAPI_PostQuitMessage(nExitCode)	PostQuitMessage(nExitCode)
#define WinAPI_PostThreadMessage(idThread, Msg, wParam, lParam)	PostThreadMessageA(idThread, Msg, wParam, lParam)
__EXTERN INTEGER __STDCALL PostThreadMessageA(INTEGER idThread, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_PostThreadMessageA(idThread, Msg, wParam, lParam)	PostThreadMessageA(idThread, Msg, wParam, lParam)
__EXTERN INTEGER __STDCALL PostThreadMessageW(INTEGER idThread, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_PostThreadMessageW(idThread, Msg, wParam, lParam)	PostThreadMessageW(idThread, Msg, wParam, lParam)
__EXTERN INTEGER __STDCALL PrepareTape(LONGINT hDevice, INTEGER dwOperation, INTEGER bImmediate);
#define WinAPI_PrepareTape(hDevice, dwOperation, bImmediate)	PrepareTape(hDevice, dwOperation, bImmediate)
#define WinAPI_PrevInstance()	__hPrevInstance
#define WinAPI_PrinterMessageBox(hPrinter, Error, hWnd, pText, pCaption, dwType)	PrinterMessageBoxA(hPrinter, Error, hWnd, pText, pCaption, dwType)
__EXTERN INTEGER __STDCALL PrinterMessageBoxA(LONGINT hPrinter, INTEGER Error, LONGINT hWnd, LONGINT pText, LONGINT pCaption, INTEGER dwType);
#define WinAPI_PrinterMessageBoxA(hPrinter, Error, hWnd, pText, pCaption, dwType)	PrinterMessageBoxA(hPrinter, Error, hWnd, pText, pCaption, dwType)
__EXTERN INTEGER __STDCALL PrinterMessageBoxW(LONGINT hPrinter, INTEGER Error, LONGINT hWnd, LONGINT pText, LONGINT pCaption, INTEGER dwType);
#define WinAPI_PrinterMessageBoxW(hPrinter, Error, hWnd, pText, pCaption, dwType)	PrinterMessageBoxW(hPrinter, Error, hWnd, pText, pCaption, dwType)
__EXTERN INTEGER __STDCALL PrinterProperties(LONGINT hWnd, LONGINT hPrinter);
#define WinAPI_PrinterProperties(hWnd, hPrinter)	PrinterProperties(hWnd, hPrinter)
__EXTERN INTEGER __STDCALL PrivilegeCheck(LONGINT ClientToken, WinAPI_PRIVILEGE_SET *RequiredPrivileges, INTEGER *pfResult);
#define WinAPI_PrivilegeCheck(ClientToken, RequiredPrivileges, pfResult)	PrivilegeCheck(ClientToken, RequiredPrivileges, pfResult)
#define WinAPI_PrivilegedServiceAuditAlarm(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)	PrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)
__EXTERN INTEGER __STDCALL PrivilegedServiceAuditAlarmA(LONGINT SubsystemName, LONGINT ServiceName, LONGINT ClientToken, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
#define WinAPI_PrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)	PrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)
__EXTERN INTEGER __STDCALL PrivilegedServiceAuditAlarmW(LONGINT SubsystemName, LONGINT ServiceName, LONGINT ClientToken, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
#define WinAPI_PrivilegedServiceAuditAlarmW(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)	PrivilegedServiceAuditAlarmW(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)
#define WinAPI_PropertySheet(p0)	PropertySheetA(p0)
__EXTERN INTEGER __STDCALL PropertySheetA(WinAPI_PROPSHEETHEADERA *p0);
#define WinAPI_PropertySheetA(p0)	PropertySheetA(p0)
__EXTERN INTEGER __STDCALL PropertySheetW(WinAPI_PROPSHEETHEADERW *p0);
#define WinAPI_PropertySheetW(p0)	PropertySheetW(p0)
__EXTERN INTEGER __STDCALL PtInRect(WinAPI_RECT *lprc, WinAPI_POINT *pt);
#define WinAPI_PtInRect(lprc, pt)	PtInRect(lprc, pt)
__EXTERN INTEGER __STDCALL PtInRegion(LONGINT p0, INTEGER p1, INTEGER p2);
#define WinAPI_PtInRegion(p0, p1, p2)	PtInRegion(p0, p1, p2)
__EXTERN INTEGER __STDCALL PtVisible(LONGINT p0, INTEGER p1, INTEGER p2);
#define WinAPI_PtVisible(p0, p1, p2)	PtVisible(p0, p1, p2)
__EXTERN INTEGER __STDCALL PulseEvent(LONGINT hEvent);
#define WinAPI_PulseEvent(hEvent)	PulseEvent(hEvent)
__EXTERN INTEGER __STDCALL PurgeComm(LONGINT hFile, SET dwFlags);
#define WinAPI_PurgeComm(hFile, dwFlags)	PurgeComm(hFile, dwFlags)
#define WinAPI_QueryDosDevice(lpDeviceName, lpTargetPath, ucchMax)	QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax)
__EXTERN INTEGER __STDCALL QueryDosDeviceA(LONGINT lpDeviceName, LONGINT lpTargetPath, INTEGER ucchMax);
#define WinAPI_QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax)	QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax)
__EXTERN INTEGER __STDCALL QueryDosDeviceW(LONGINT lpDeviceName, LONGINT lpTargetPath, INTEGER ucchMax);
#define WinAPI_QueryDosDeviceW(lpDeviceName, lpTargetPath, ucchMax)	QueryDosDeviceW(lpDeviceName, lpTargetPath, ucchMax)
__EXTERN INTEGER __STDCALL QueryPerformanceCounter(LONGINT *lpPerformanceCount);
#define WinAPI_QueryPerformanceCounter(lpPerformanceCount)	QueryPerformanceCounter(lpPerformanceCount)
__EXTERN INTEGER __STDCALL QueryPerformanceFrequency(LONGINT *lpFrequency);
#define WinAPI_QueryPerformanceFrequency(lpFrequency)	QueryPerformanceFrequency(lpFrequency)
#define WinAPI_QueryServiceConfig(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)	QueryServiceConfigA(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __STDCALL QueryServiceConfigA(LONGINT hService, WinAPI_QUERY_SERVICE_CONFIGA *lpServiceConfig, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinAPI_QueryServiceConfigA(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)	QueryServiceConfigA(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __STDCALL QueryServiceConfigW(LONGINT hService, WinAPI_QUERY_SERVICE_CONFIGW *lpServiceConfig, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinAPI_QueryServiceConfigW(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)	QueryServiceConfigW(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)
#define WinAPI_QueryServiceLockStatus(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)	QueryServiceLockStatusA(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __STDCALL QueryServiceLockStatusA(LONGINT hSCManager, WinAPI_QUERY_SERVICE_LOCK_STATUSA *lpLockStatus, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinAPI_QueryServiceLockStatusA(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)	QueryServiceLockStatusA(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __STDCALL QueryServiceLockStatusW(LONGINT hSCManager, WinAPI_QUERY_SERVICE_LOCK_STATUSW *lpLockStatus, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinAPI_QueryServiceLockStatusW(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)	QueryServiceLockStatusW(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __STDCALL QueryServiceObjectSecurity(LONGINT hService, SET dwSecurityInformation, LONGINT lpSecurityDescriptor, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinAPI_QueryServiceObjectSecurity(hService, dwSecurityInformation, lpSecurityDescriptor, cbBufSize, pcbBytesNeeded)	QueryServiceObjectSecurity(hService, dwSecurityInformation, lpSecurityDescriptor, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __STDCALL QueryServiceStatus(LONGINT hService, WinAPI_SERVICE_STATUS *lpServiceStatus);
#define WinAPI_QueryServiceStatus(hService, lpServiceStatus)	QueryServiceStatus(hService, lpServiceStatus)
__EXTERN INTEGER __STDCALL QueueUserAPC(WinAPI_APCFUNC pfnAPC, LONGINT hThread, INTEGER dwData);
#define WinAPI_QueueUserAPC(pfnAPC, hThread, dwData)	QueueUserAPC(pfnAPC, hThread, dwData)
__EXTERN void __STDCALL RaiseException(INTEGER dwExceptionCode, INTEGER dwExceptionFlags, INTEGER nNumberOfArguments, INTEGER *lpArguments);
#define WinAPI_RaiseException(dwExceptionCode, dwExceptionFlags, nNumberOfArguments, lpArguments)	RaiseException(dwExceptionCode, dwExceptionFlags, nNumberOfArguments, lpArguments)
#define WinAPI_ReadConsole(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)	ReadConsoleA(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)
__EXTERN INTEGER __STDCALL ReadConsoleA(LONGINT hConsoleInput, LONGINT lpBuffer, INTEGER nNumberOfCharsToRead, INTEGER *lpNumberOfCharsRead, LONGINT lpReserved);
#define WinAPI_ReadConsoleA(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)	ReadConsoleA(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)
#define WinAPI_ReadConsoleInput(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)	ReadConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
__EXTERN INTEGER __STDCALL ReadConsoleInputA(LONGINT hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
#define WinAPI_ReadConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)	ReadConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
__EXTERN INTEGER __STDCALL ReadConsoleInputW(LONGINT hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
#define WinAPI_ReadConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)	ReadConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
#define WinAPI_ReadConsoleOutput(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)	ReadConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)
__EXTERN INTEGER __STDCALL ReadConsoleOutputA(LONGINT hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD *dwBufferSize, WinAPI_COORD *dwBufferCoord, WinAPI_SMALL_RECT *lpReadRegion);
#define WinAPI_ReadConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)	ReadConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)
__EXTERN INTEGER __STDCALL ReadConsoleOutputAttribute(LONGINT hConsoleOutput, SHORTINT *lpAttribute, INTEGER nLength, WinAPI_COORD *dwReadCoord, INTEGER *lpNumberOfAttrsRead);
#define WinAPI_ReadConsoleOutputAttribute(hConsoleOutput, lpAttribute, nLength, dwReadCoord, lpNumberOfAttrsRead)	ReadConsoleOutputAttribute(hConsoleOutput, lpAttribute, nLength, dwReadCoord, lpNumberOfAttrsRead)
#define WinAPI_ReadConsoleOutputCharacter(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)	ReadConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)
__EXTERN INTEGER __STDCALL ReadConsoleOutputCharacterA(LONGINT hConsoleOutput, LONGINT lpCharacter, INTEGER nLength, WinAPI_COORD *dwReadCoord, INTEGER *lpNumberOfCharsRead);
#define WinAPI_ReadConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)	ReadConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)
__EXTERN INTEGER __STDCALL ReadConsoleOutputCharacterW(LONGINT hConsoleOutput, LONGINT lpCharacter, INTEGER nLength, WinAPI_COORD *dwReadCoord, INTEGER *lpNumberOfCharsRead);
#define WinAPI_ReadConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)	ReadConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)
__EXTERN INTEGER __STDCALL ReadConsoleOutputW(LONGINT hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD *dwBufferSize, WinAPI_COORD *dwBufferCoord, WinAPI_SMALL_RECT *lpReadRegion);
#define WinAPI_ReadConsoleOutputW(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)	ReadConsoleOutputW(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)
__EXTERN INTEGER __STDCALL ReadConsoleW(LONGINT hConsoleInput, LONGINT lpBuffer, INTEGER nNumberOfCharsToRead, INTEGER *lpNumberOfCharsRead, LONGINT lpReserved);
#define WinAPI_ReadConsoleW(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)	ReadConsoleW(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)
__EXTERN INTEGER __STDCALL ReadDirectoryChangesW(LONGINT hDirectory, LONGINT lpBuffer, INTEGER nBufferLength, INTEGER bWatchSubtree, SET dwNotifyFilter, INTEGER *lpBytesReturned, WinAPI_OVERLAPPED *lpOverlapped, WinAPI_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinAPI_ReadDirectoryChangesW(hDirectory, lpBuffer, nBufferLength, bWatchSubtree, dwNotifyFilter, lpBytesReturned, lpOverlapped, lpCompletionRoutine)	ReadDirectoryChangesW(hDirectory, lpBuffer, nBufferLength, bWatchSubtree, dwNotifyFilter, lpBytesReturned, lpOverlapped, lpCompletionRoutine)
#define WinAPI_ReadEventLog(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)	ReadEventLogA(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)
__EXTERN INTEGER __STDCALL ReadEventLogA(LONGINT hEventLog, SET dwReadFlags, INTEGER dwRecordOffset, LONGINT lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *pnBytesRead, INTEGER *pnMinNumberOfBytesNeeded);
#define WinAPI_ReadEventLogA(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)	ReadEventLogA(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)
__EXTERN INTEGER __STDCALL ReadEventLogW(LONGINT hEventLog, SET dwReadFlags, INTEGER dwRecordOffset, LONGINT lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *pnBytesRead, INTEGER *pnMinNumberOfBytesNeeded);
#define WinAPI_ReadEventLogW(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)	ReadEventLogW(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)
__EXTERN INTEGER __STDCALL ReadFile(LONGINT hFile, LONGINT lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *lpNumberOfBytesRead, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped)	ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped)
__EXTERN INTEGER __STDCALL ReadFileEx(LONGINT hFile, LONGINT lpBuffer, INTEGER nNumberOfBytesToRead, WinAPI_OVERLAPPED *lpOverlapped, WinAPI_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinAPI_ReadFileEx(hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine)	ReadFileEx(hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine)
__EXTERN INTEGER __STDCALL ReadPrinter(LONGINT hPrinter, LONGINT pBuf, INTEGER cbBuf, INTEGER *pNoBytesRead);
#define WinAPI_ReadPrinter(hPrinter, pBuf, cbBuf, pNoBytesRead)	ReadPrinter(hPrinter, pBuf, cbBuf, pNoBytesRead)
__EXTERN INTEGER __STDCALL ReadProcessMemory(LONGINT hProcess, LONGINT lpBaseAddress, LONGINT lpBuffer, INTEGER nSize, INTEGER *lpNumberOfBytesRead);
#define WinAPI_ReadProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead)	ReadProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead)
__EXTERN INTEGER __STDCALL RealizePalette(LONGINT p0);
#define WinAPI_RealizePalette(p0)	RealizePalette(p0)
__EXTERN INTEGER __STDCALL RectInRegion(LONGINT p0, WinAPI_RECT *p1);
#define WinAPI_RectInRegion(p0, p1)	RectInRegion(p0, p1)
__EXTERN INTEGER __STDCALL RectVisible(LONGINT p0, WinAPI_RECT *p1);
#define WinAPI_RectVisible(p0, p1)	RectVisible(p0, p1)
__EXTERN INTEGER __STDCALL Rectangle(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_Rectangle(p0, p1, p2, p3, p4)	Rectangle(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL RedrawWindow(LONGINT hWnd, WinAPI_RECT *lprcUpdate, LONGINT hrgnUpdate, SET flags);
#define WinAPI_RedrawWindow(hWnd, lprcUpdate, hrgnUpdate, flags)	RedrawWindow(hWnd, lprcUpdate, hrgnUpdate, flags)
__EXTERN INTEGER __STDCALL RegCloseKey(LONGINT hKey);
#define WinAPI_RegCloseKey(hKey)	RegCloseKey(hKey)
#define WinAPI_RegConnectRegistry(lpMachineName, hKey, phkResult)	RegConnectRegistryA(lpMachineName, hKey, phkResult)
__EXTERN INTEGER __STDCALL RegConnectRegistryA(LONGINT lpMachineName, LONGINT hKey, LONGINT *phkResult);
#define WinAPI_RegConnectRegistryA(lpMachineName, hKey, phkResult)	RegConnectRegistryA(lpMachineName, hKey, phkResult)
__EXTERN INTEGER __STDCALL RegConnectRegistryW(LONGINT lpMachineName, LONGINT hKey, LONGINT *phkResult);
#define WinAPI_RegConnectRegistryW(lpMachineName, hKey, phkResult)	RegConnectRegistryW(lpMachineName, hKey, phkResult)
#define WinAPI_RegCreateKey(hKey, lpSubKey, phkResult)	RegCreateKeyA(hKey, lpSubKey, phkResult)
__EXTERN INTEGER __STDCALL RegCreateKeyA(LONGINT hKey, LONGINT lpSubKey, LONGINT *phkResult);
#define WinAPI_RegCreateKeyA(hKey, lpSubKey, phkResult)	RegCreateKeyA(hKey, lpSubKey, phkResult)
#define WinAPI_RegCreateKeyEx(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)	RegCreateKeyExA(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)
__EXTERN INTEGER __STDCALL RegCreateKeyExA(LONGINT hKey, LONGINT lpSubKey, INTEGER Reserved, LONGINT lpClass, SET dwOptions, SET samDesired, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, LONGINT *phkResult, INTEGER *lpdwDisposition);
#define WinAPI_RegCreateKeyExA(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)	RegCreateKeyExA(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)
__EXTERN INTEGER __STDCALL RegCreateKeyExW(LONGINT hKey, LONGINT lpSubKey, INTEGER Reserved, LONGINT lpClass, SET dwOptions, SET samDesired, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, LONGINT *phkResult, INTEGER *lpdwDisposition);
#define WinAPI_RegCreateKeyExW(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)	RegCreateKeyExW(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)
__EXTERN INTEGER __STDCALL RegCreateKeyW(LONGINT hKey, LONGINT lpSubKey, LONGINT *phkResult);
#define WinAPI_RegCreateKeyW(hKey, lpSubKey, phkResult)	RegCreateKeyW(hKey, lpSubKey, phkResult)
#define WinAPI_RegDeleteKey(hKey, lpSubKey)	RegDeleteKeyA(hKey, lpSubKey)
__EXTERN INTEGER __STDCALL RegDeleteKeyA(LONGINT hKey, LONGINT lpSubKey);
#define WinAPI_RegDeleteKeyA(hKey, lpSubKey)	RegDeleteKeyA(hKey, lpSubKey)
__EXTERN INTEGER __STDCALL RegDeleteKeyW(LONGINT hKey, LONGINT lpSubKey);
#define WinAPI_RegDeleteKeyW(hKey, lpSubKey)	RegDeleteKeyW(hKey, lpSubKey)
#define WinAPI_RegDeleteValue(hKey, lpValueName)	RegDeleteValueA(hKey, lpValueName)
__EXTERN INTEGER __STDCALL RegDeleteValueA(LONGINT hKey, LONGINT lpValueName);
#define WinAPI_RegDeleteValueA(hKey, lpValueName)	RegDeleteValueA(hKey, lpValueName)
__EXTERN INTEGER __STDCALL RegDeleteValueW(LONGINT hKey, LONGINT lpValueName);
#define WinAPI_RegDeleteValueW(hKey, lpValueName)	RegDeleteValueW(hKey, lpValueName)
#define WinAPI_RegEnumKey(hKey, dwIndex, lpName, cbName)	RegEnumKeyA(hKey, dwIndex, lpName, cbName)
__EXTERN INTEGER __STDCALL RegEnumKeyA(LONGINT hKey, INTEGER dwIndex, LONGINT lpName, INTEGER cbName);
#define WinAPI_RegEnumKeyA(hKey, dwIndex, lpName, cbName)	RegEnumKeyA(hKey, dwIndex, lpName, cbName)
#define WinAPI_RegEnumKeyEx(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)	RegEnumKeyExA(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)
__EXTERN INTEGER __STDCALL RegEnumKeyExA(LONGINT hKey, INTEGER dwIndex, LONGINT lpName, INTEGER *lpcbName, INTEGER *lpReserved, LONGINT lpClass, INTEGER *lpcbClass, WinAPI_FILETIME *lpftLastWriteTime);
#define WinAPI_RegEnumKeyExA(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)	RegEnumKeyExA(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)
__EXTERN INTEGER __STDCALL RegEnumKeyExW(LONGINT hKey, INTEGER dwIndex, LONGINT lpName, INTEGER *lpcbName, INTEGER *lpReserved, LONGINT lpClass, INTEGER *lpcbClass, WinAPI_FILETIME *lpftLastWriteTime);
#define WinAPI_RegEnumKeyExW(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)	RegEnumKeyExW(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)
__EXTERN INTEGER __STDCALL RegEnumKeyW(LONGINT hKey, INTEGER dwIndex, LONGINT lpName, INTEGER cbName);
#define WinAPI_RegEnumKeyW(hKey, dwIndex, lpName, cbName)	RegEnumKeyW(hKey, dwIndex, lpName, cbName)
#define WinAPI_RegEnumValue(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)	RegEnumValueA(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __STDCALL RegEnumValueA(LONGINT hKey, INTEGER dwIndex, LONGINT lpValueName, INTEGER *lpcbValueName, INTEGER *lpReserved, INTEGER *lpType, LONGINT lpData, INTEGER *lpcbData);
#define WinAPI_RegEnumValueA(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)	RegEnumValueA(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __STDCALL RegEnumValueW(LONGINT hKey, INTEGER dwIndex, LONGINT lpValueName, INTEGER *lpcbValueName, INTEGER *lpReserved, INTEGER *lpType, LONGINT lpData, INTEGER *lpcbData);
#define WinAPI_RegEnumValueW(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)	RegEnumValueW(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __STDCALL RegFlushKey(LONGINT hKey);
#define WinAPI_RegFlushKey(hKey)	RegFlushKey(hKey)
__EXTERN INTEGER __STDCALL RegGetKeySecurity(LONGINT hKey, SET SecurityInformation, LONGINT pSecurityDescriptor, INTEGER *lpcbSecurityDescriptor);
#define WinAPI_RegGetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor, lpcbSecurityDescriptor)	RegGetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor, lpcbSecurityDescriptor)
#define WinAPI_RegLoadKey(hKey, lpSubKey, lpFile)	RegLoadKeyA(hKey, lpSubKey, lpFile)
__EXTERN INTEGER __STDCALL RegLoadKeyA(LONGINT hKey, LONGINT lpSubKey, LONGINT lpFile);
#define WinAPI_RegLoadKeyA(hKey, lpSubKey, lpFile)	RegLoadKeyA(hKey, lpSubKey, lpFile)
__EXTERN INTEGER __STDCALL RegLoadKeyW(LONGINT hKey, LONGINT lpSubKey, LONGINT lpFile);
#define WinAPI_RegLoadKeyW(hKey, lpSubKey, lpFile)	RegLoadKeyW(hKey, lpSubKey, lpFile)
__EXTERN INTEGER __STDCALL RegNotifyChangeKeyValue(LONGINT hKey, INTEGER bWatchSubtree, SET dwNotifyFilter, LONGINT hEvent, INTEGER fAsynchronus);
#define WinAPI_RegNotifyChangeKeyValue(hKey, bWatchSubtree, dwNotifyFilter, hEvent, fAsynchronus)	RegNotifyChangeKeyValue(hKey, bWatchSubtree, dwNotifyFilter, hEvent, fAsynchronus)
#define WinAPI_RegOpenKey(hKey, lpSubKey, phkResult)	RegOpenKeyA(hKey, lpSubKey, phkResult)
__EXTERN INTEGER __STDCALL RegOpenKeyA(LONGINT hKey, LONGINT lpSubKey, LONGINT *phkResult);
#define WinAPI_RegOpenKeyA(hKey, lpSubKey, phkResult)	RegOpenKeyA(hKey, lpSubKey, phkResult)
#define WinAPI_RegOpenKeyEx(hKey, lpSubKey, ulOptions, samDesired, phkResult)	RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult)
__EXTERN INTEGER __STDCALL RegOpenKeyExA(LONGINT hKey, LONGINT lpSubKey, INTEGER ulOptions, SET samDesired, LONGINT *phkResult);
#define WinAPI_RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult)	RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult)
__EXTERN INTEGER __STDCALL RegOpenKeyExW(LONGINT hKey, LONGINT lpSubKey, INTEGER ulOptions, SET samDesired, LONGINT *phkResult);
#define WinAPI_RegOpenKeyExW(hKey, lpSubKey, ulOptions, samDesired, phkResult)	RegOpenKeyExW(hKey, lpSubKey, ulOptions, samDesired, phkResult)
__EXTERN INTEGER __STDCALL RegOpenKeyW(LONGINT hKey, LONGINT lpSubKey, LONGINT *phkResult);
#define WinAPI_RegOpenKeyW(hKey, lpSubKey, phkResult)	RegOpenKeyW(hKey, lpSubKey, phkResult)
#define WinAPI_RegQueryInfoKey(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)	RegQueryInfoKeyA(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)
__EXTERN INTEGER __STDCALL RegQueryInfoKeyA(LONGINT hKey, LONGINT lpClass, INTEGER *lpcbClass, INTEGER *lpReserved, INTEGER *lpcSubKeys, INTEGER *lpcbMaxSubKeyLen, INTEGER *lpcbMaxClassLen, INTEGER *lpcValues, INTEGER *lpcbMaxValueNameLen, INTEGER *lpcbMaxValueLen, INTEGER *lpcbSecurityDescriptor, WinAPI_FILETIME *lpftLastWriteTime);
#define WinAPI_RegQueryInfoKeyA(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)	RegQueryInfoKeyA(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)
__EXTERN INTEGER __STDCALL RegQueryInfoKeyW(LONGINT hKey, LONGINT lpClass, INTEGER *lpcbClass, INTEGER *lpReserved, INTEGER *lpcSubKeys, INTEGER *lpcbMaxSubKeyLen, INTEGER *lpcbMaxClassLen, INTEGER *lpcValues, INTEGER *lpcbMaxValueNameLen, INTEGER *lpcbMaxValueLen, INTEGER *lpcbSecurityDescriptor, WinAPI_FILETIME *lpftLastWriteTime);
#define WinAPI_RegQueryInfoKeyW(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)	RegQueryInfoKeyW(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)
#define WinAPI_RegQueryMultipleValues(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)	RegQueryMultipleValuesA(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)
__EXTERN INTEGER __STDCALL RegQueryMultipleValuesA(LONGINT hKey, WinAPI_VALENTA *val_list, INTEGER num_vals, LONGINT lpValueBuf, INTEGER *ldwTotsize);
#define WinAPI_RegQueryMultipleValuesA(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)	RegQueryMultipleValuesA(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)
__EXTERN INTEGER __STDCALL RegQueryMultipleValuesW(LONGINT hKey, WinAPI_VALENTW *val_list, INTEGER num_vals, LONGINT lpValueBuf, INTEGER *ldwTotsize);
#define WinAPI_RegQueryMultipleValuesW(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)	RegQueryMultipleValuesW(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)
#define WinAPI_RegQueryValue(hKey, lpSubKey, lpValue, lpcbValue)	RegQueryValueA(hKey, lpSubKey, lpValue, lpcbValue)
__EXTERN INTEGER __STDCALL RegQueryValueA(LONGINT hKey, LONGINT lpSubKey, LONGINT lpValue, INTEGER *lpcbValue);
#define WinAPI_RegQueryValueA(hKey, lpSubKey, lpValue, lpcbValue)	RegQueryValueA(hKey, lpSubKey, lpValue, lpcbValue)
#define WinAPI_RegQueryValueEx(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)	RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __STDCALL RegQueryValueExA(LONGINT hKey, LONGINT lpValueName, INTEGER *lpReserved, INTEGER *lpType, LONGINT lpData, INTEGER *lpcbData);
#define WinAPI_RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)	RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __STDCALL RegQueryValueExW(LONGINT hKey, LONGINT lpValueName, INTEGER *lpReserved, INTEGER *lpType, LONGINT lpData, INTEGER *lpcbData);
#define WinAPI_RegQueryValueExW(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)	RegQueryValueExW(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __STDCALL RegQueryValueW(LONGINT hKey, LONGINT lpSubKey, LONGINT lpValue, INTEGER *lpcbValue);
#define WinAPI_RegQueryValueW(hKey, lpSubKey, lpValue, lpcbValue)	RegQueryValueW(hKey, lpSubKey, lpValue, lpcbValue)
#define WinAPI_RegReplaceKey(hKey, lpSubKey, lpNewFile, lpOldFile)	RegReplaceKeyA(hKey, lpSubKey, lpNewFile, lpOldFile)
__EXTERN INTEGER __STDCALL RegReplaceKeyA(LONGINT hKey, LONGINT lpSubKey, LONGINT lpNewFile, LONGINT lpOldFile);
#define WinAPI_RegReplaceKeyA(hKey, lpSubKey, lpNewFile, lpOldFile)	RegReplaceKeyA(hKey, lpSubKey, lpNewFile, lpOldFile)
__EXTERN INTEGER __STDCALL RegReplaceKeyW(LONGINT hKey, LONGINT lpSubKey, LONGINT lpNewFile, LONGINT lpOldFile);
#define WinAPI_RegReplaceKeyW(hKey, lpSubKey, lpNewFile, lpOldFile)	RegReplaceKeyW(hKey, lpSubKey, lpNewFile, lpOldFile)
#define WinAPI_RegRestoreKey(hKey, lpFile, dwFlags)	RegRestoreKeyA(hKey, lpFile, dwFlags)
__EXTERN INTEGER __STDCALL RegRestoreKeyA(LONGINT hKey, LONGINT lpFile, SET dwFlags);
#define WinAPI_RegRestoreKeyA(hKey, lpFile, dwFlags)	RegRestoreKeyA(hKey, lpFile, dwFlags)
__EXTERN INTEGER __STDCALL RegRestoreKeyW(LONGINT hKey, LONGINT lpFile, SET dwFlags);
#define WinAPI_RegRestoreKeyW(hKey, lpFile, dwFlags)	RegRestoreKeyW(hKey, lpFile, dwFlags)
#define WinAPI_RegSaveKey(hKey, lpFile, lpSecurityAttributes)	RegSaveKeyA(hKey, lpFile, lpSecurityAttributes)
__EXTERN INTEGER __STDCALL RegSaveKeyA(LONGINT hKey, LONGINT lpFile, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_RegSaveKeyA(hKey, lpFile, lpSecurityAttributes)	RegSaveKeyA(hKey, lpFile, lpSecurityAttributes)
__EXTERN INTEGER __STDCALL RegSaveKeyW(LONGINT hKey, LONGINT lpFile, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_RegSaveKeyW(hKey, lpFile, lpSecurityAttributes)	RegSaveKeyW(hKey, lpFile, lpSecurityAttributes)
__EXTERN INTEGER __STDCALL RegSetKeySecurity(LONGINT hKey, SET SecurityInformation, LONGINT pSecurityDescriptor);
#define WinAPI_RegSetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor)	RegSetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor)
#define WinAPI_RegSetValue(hKey, lpSubKey, dwType, lpData, cbData)	RegSetValueA(hKey, lpSubKey, dwType, lpData, cbData)
__EXTERN INTEGER __STDCALL RegSetValueA(LONGINT hKey, LONGINT lpSubKey, INTEGER dwType, LONGINT lpData, INTEGER cbData);
#define WinAPI_RegSetValueA(hKey, lpSubKey, dwType, lpData, cbData)	RegSetValueA(hKey, lpSubKey, dwType, lpData, cbData)
#define WinAPI_RegSetValueEx(hKey, lpValueName, Reserved, dwType, lpData, cbData)	RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData)
__EXTERN INTEGER __STDCALL RegSetValueExA(LONGINT hKey, LONGINT lpValueName, INTEGER Reserved, INTEGER dwType, LONGINT lpData, INTEGER cbData);
#define WinAPI_RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData)	RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData)
__EXTERN INTEGER __STDCALL RegSetValueExW(LONGINT hKey, LONGINT lpValueName, INTEGER Reserved, INTEGER dwType, LONGINT lpData, INTEGER cbData);
#define WinAPI_RegSetValueExW(hKey, lpValueName, Reserved, dwType, lpData, cbData)	RegSetValueExW(hKey, lpValueName, Reserved, dwType, lpData, cbData)
__EXTERN INTEGER __STDCALL RegSetValueW(LONGINT hKey, LONGINT lpSubKey, INTEGER dwType, LONGINT lpData, INTEGER cbData);
#define WinAPI_RegSetValueW(hKey, lpSubKey, dwType, lpData, cbData)	RegSetValueW(hKey, lpSubKey, dwType, lpData, cbData)
#define WinAPI_RegUnLoadKey(hKey, lpSubKey)	RegUnLoadKeyA(hKey, lpSubKey)
__EXTERN INTEGER __STDCALL RegUnLoadKeyA(LONGINT hKey, LONGINT lpSubKey);
#define WinAPI_RegUnLoadKeyA(hKey, lpSubKey)	RegUnLoadKeyA(hKey, lpSubKey)
__EXTERN INTEGER __STDCALL RegUnLoadKeyW(LONGINT hKey, LONGINT lpSubKey);
#define WinAPI_RegUnLoadKeyW(hKey, lpSubKey)	RegUnLoadKeyW(hKey, lpSubKey)
#define WinAPI_RegisterClass(lpWndClass)	RegisterClassA(lpWndClass)
__EXTERN SHORTINT __STDCALL RegisterClassA(WinAPI_WNDCLASSA *lpWndClass);
#define WinAPI_RegisterClassA(lpWndClass)	RegisterClassA(lpWndClass)
#define WinAPI_RegisterClassEx(p0)	RegisterClassExA(p0)
__EXTERN SHORTINT __STDCALL RegisterClassExA(WinAPI_WNDCLASSEXA *p0);
#define WinAPI_RegisterClassExA(p0)	RegisterClassExA(p0)
__EXTERN SHORTINT __STDCALL RegisterClassExW(WinAPI_WNDCLASSEXW *p0);
#define WinAPI_RegisterClassExW(p0)	RegisterClassExW(p0)
__EXTERN SHORTINT __STDCALL RegisterClassW(WinAPI_WNDCLASSW *lpWndClass);
#define WinAPI_RegisterClassW(lpWndClass)	RegisterClassW(lpWndClass)
#define WinAPI_RegisterClipboardFormat(lpszFormat)	RegisterClipboardFormatA(lpszFormat)
__EXTERN INTEGER __STDCALL RegisterClipboardFormatA(LONGINT lpszFormat);
#define WinAPI_RegisterClipboardFormatA(lpszFormat)	RegisterClipboardFormatA(lpszFormat)
__EXTERN INTEGER __STDCALL RegisterClipboardFormatW(LONGINT lpszFormat);
#define WinAPI_RegisterClipboardFormatW(lpszFormat)	RegisterClipboardFormatW(lpszFormat)
#define WinAPI_RegisterEventSource(lpUNCServerName, lpSourceName)	RegisterEventSourceA(lpUNCServerName, lpSourceName)
__EXTERN LONGINT __STDCALL RegisterEventSourceA(LONGINT lpUNCServerName, LONGINT lpSourceName);
#define WinAPI_RegisterEventSourceA(lpUNCServerName, lpSourceName)	RegisterEventSourceA(lpUNCServerName, lpSourceName)
__EXTERN LONGINT __STDCALL RegisterEventSourceW(LONGINT lpUNCServerName, LONGINT lpSourceName);
#define WinAPI_RegisterEventSourceW(lpUNCServerName, lpSourceName)	RegisterEventSourceW(lpUNCServerName, lpSourceName)
__EXTERN INTEGER __STDCALL RegisterHotKey(LONGINT hWnd, INTEGER id, INTEGER fsModifiers, INTEGER vk);
#define WinAPI_RegisterHotKey(hWnd, id, fsModifiers, vk)	RegisterHotKey(hWnd, id, fsModifiers, vk)
#define WinAPI_RegisterServiceCtrlHandler(lpServiceName, lpHandlerProc)	RegisterServiceCtrlHandlerA(lpServiceName, lpHandlerProc)
__EXTERN INTEGER __STDCALL RegisterServiceCtrlHandlerA(LONGINT lpServiceName, WinAPI_HANDLER_FUNCTION lpHandlerProc);
#define WinAPI_RegisterServiceCtrlHandlerA(lpServiceName, lpHandlerProc)	RegisterServiceCtrlHandlerA(lpServiceName, lpHandlerProc)
__EXTERN INTEGER __STDCALL RegisterServiceCtrlHandlerW(LONGINT lpServiceName, WinAPI_HANDLER_FUNCTION lpHandlerProc);
#define WinAPI_RegisterServiceCtrlHandlerW(lpServiceName, lpHandlerProc)	RegisterServiceCtrlHandlerW(lpServiceName, lpHandlerProc)
#define WinAPI_RegisterWindowMessage(lpString)	RegisterWindowMessageA(lpString)
__EXTERN INTEGER __STDCALL RegisterWindowMessageA(LONGINT lpString);
#define WinAPI_RegisterWindowMessageA(lpString)	RegisterWindowMessageA(lpString)
__EXTERN INTEGER __STDCALL RegisterWindowMessageW(LONGINT lpString);
#define WinAPI_RegisterWindowMessageW(lpString)	RegisterWindowMessageW(lpString)
__EXTERN INTEGER __STDCALL ReleaseCapture(void);
#define WinAPI_ReleaseCapture()	ReleaseCapture()
__EXTERN INTEGER __STDCALL ReleaseDC(LONGINT hWnd, LONGINT hDC);
#define WinAPI_ReleaseDC(hWnd, hDC)	ReleaseDC(hWnd, hDC)
__EXTERN INTEGER __STDCALL ReleaseMutex(LONGINT hMutex);
#define WinAPI_ReleaseMutex(hMutex)	ReleaseMutex(hMutex)
__EXTERN INTEGER __STDCALL ReleaseSemaphore(LONGINT hSemaphore, INTEGER lReleaseCount, INTEGER *lpPreviousCount);
#define WinAPI_ReleaseSemaphore(hSemaphore, lReleaseCount, lpPreviousCount)	ReleaseSemaphore(hSemaphore, lReleaseCount, lpPreviousCount)
#define WinAPI_RemoveDirectory(lpPathName)	RemoveDirectoryA(lpPathName)
__EXTERN INTEGER __STDCALL RemoveDirectoryA(LONGINT lpPathName);
#define WinAPI_RemoveDirectoryA(lpPathName)	RemoveDirectoryA(lpPathName)
__EXTERN INTEGER __STDCALL RemoveDirectoryW(LONGINT lpPathName);
#define WinAPI_RemoveDirectoryW(lpPathName)	RemoveDirectoryW(lpPathName)
#define WinAPI_RemoveFontResource(p0)	RemoveFontResourceA(p0)
__EXTERN INTEGER __STDCALL RemoveFontResourceA(LONGINT p0);
#define WinAPI_RemoveFontResourceA(p0)	RemoveFontResourceA(p0)
__EXTERN INTEGER __STDCALL RemoveFontResourceW(LONGINT p0);
#define WinAPI_RemoveFontResourceW(p0)	RemoveFontResourceW(p0)
__EXTERN INTEGER __STDCALL RemoveMenu(LONGINT hMenu, INTEGER uPosition, SET uFlags);
#define WinAPI_RemoveMenu(hMenu, uPosition, uFlags)	RemoveMenu(hMenu, uPosition, uFlags)
#define WinAPI_RemoveProp(hWnd, lpString)	RemovePropA(hWnd, lpString)
__EXTERN LONGINT __STDCALL RemovePropA(LONGINT hWnd, LONGINT lpString);
#define WinAPI_RemovePropA(hWnd, lpString)	RemovePropA(hWnd, lpString)
__EXTERN LONGINT __STDCALL RemovePropW(LONGINT hWnd, LONGINT lpString);
#define WinAPI_RemovePropW(hWnd, lpString)	RemovePropW(hWnd, lpString)
__EXTERN INTEGER __STDCALL ReplyMessage(LONGINT lResult);
#define WinAPI_ReplyMessage(lResult)	ReplyMessage(lResult)
#define WinAPI_ReportEvent(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)	ReportEventA(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)
__EXTERN INTEGER __STDCALL ReportEventA(LONGINT hEventLog, SHORTINT wType, SHORTINT wCategory, INTEGER dwEventID, LONGINT lpUserSid, SHORTINT wNumStrings, INTEGER dwDataSize, LONGINT *lpStrings, LONGINT lpRawData);
#define WinAPI_ReportEventA(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)	ReportEventA(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)
__EXTERN INTEGER __STDCALL ReportEventW(LONGINT hEventLog, SHORTINT wType, SHORTINT wCategory, INTEGER dwEventID, LONGINT lpUserSid, SHORTINT wNumStrings, INTEGER dwDataSize, LONGINT lpStrings, LONGINT lpRawData);
#define WinAPI_ReportEventW(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)	ReportEventW(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)
#define WinAPI_ResetDC(p0, p1)	ResetDCA(p0, p1)
__EXTERN LONGINT __STDCALL ResetDCA(LONGINT p0, WinAPI_DEVMODEA *p1);
#define WinAPI_ResetDCA(p0, p1)	ResetDCA(p0, p1)
__EXTERN LONGINT __STDCALL ResetDCW(LONGINT p0, WinAPI_DEVMODEW *p1);
#define WinAPI_ResetDCW(p0, p1)	ResetDCW(p0, p1)
__EXTERN INTEGER __STDCALL ResetEvent(LONGINT hEvent);
#define WinAPI_ResetEvent(hEvent)	ResetEvent(hEvent)
#define WinAPI_ResetPrinter(hPrinter, pDefault)	ResetPrinterA(hPrinter, pDefault)
__EXTERN INTEGER __STDCALL ResetPrinterA(LONGINT hPrinter, WinAPI_PRINTER_DEFAULTSA *pDefault);
#define WinAPI_ResetPrinterA(hPrinter, pDefault)	ResetPrinterA(hPrinter, pDefault)
__EXTERN INTEGER __STDCALL ResetPrinterW(LONGINT hPrinter, WinAPI_PRINTER_DEFAULTSW *pDefault);
#define WinAPI_ResetPrinterW(hPrinter, pDefault)	ResetPrinterW(hPrinter, pDefault)
__EXTERN INTEGER __STDCALL ResizePalette(LONGINT p0, INTEGER p1);
#define WinAPI_ResizePalette(p0, p1)	ResizePalette(p0, p1)
__EXTERN INTEGER __STDCALL RestoreDC(LONGINT p0, INTEGER p1);
#define WinAPI_RestoreDC(p0, p1)	RestoreDC(p0, p1)
__EXTERN INTEGER __STDCALL ResumeThread(LONGINT hThread);
#define WinAPI_ResumeThread(hThread)	ResumeThread(hThread)
__EXTERN INTEGER __STDCALL ReuseDDElParam(INTEGER lParam, INTEGER msgIn, INTEGER msgOut, INTEGER uiLo, INTEGER uiHi);
#define WinAPI_ReuseDDElParam(lParam, msgIn, msgOut, uiLo, uiHi)	ReuseDDElParam(lParam, msgIn, msgOut, uiLo, uiHi)
__EXTERN INTEGER __STDCALL RevertToSelf(void);
#define WinAPI_RevertToSelf()	RevertToSelf()
__EXTERN INTEGER __STDCALL RoundRect(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6);
#define WinAPI_RoundRect(p0, p1, p2, p3, p4, p5, p6)	RoundRect(p0, p1, p2, p3, p4, p5, p6)
__EXTERN void __STDCALL RtlUnwind(LONGINT targetFrame, INTEGER targetIp, WinAPI_PtrEXCEPTION_RECORD excpRec, INTEGER retVal);
#define WinAPI_RtlUnwind(targetFrame, targetIp, excpRec, retVal)	RtlUnwind(targetFrame, targetIp, excpRec, retVal)
__EXTERN INTEGER __STDCALL SHAppBarMessage(INTEGER dwMessage, WinAPI_APPBARDATA *pData);
#define WinAPI_SHAppBarMessage(dwMessage, pData)	SHAppBarMessage(dwMessage, pData)
#define WinAPI_SHFileOperation(lpFileOp)	SHFileOperationA(lpFileOp)
__EXTERN INTEGER __STDCALL SHFileOperationA(WinAPI_SHFILEOPSTRUCTA *lpFileOp);
#define WinAPI_SHFileOperationA(lpFileOp)	SHFileOperationA(lpFileOp)
__EXTERN INTEGER __STDCALL SHFileOperationW(WinAPI_SHFILEOPSTRUCTW *lpFileOp);
#define WinAPI_SHFileOperationW(lpFileOp)	SHFileOperationW(lpFileOp)
__EXTERN void __STDCALL SHFreeNameMappings(LONGINT hNameMappings);
#define WinAPI_SHFreeNameMappings(hNameMappings)	SHFreeNameMappings(hNameMappings)
#define WinAPI_SHGetFileInfo(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)	SHGetFileInfoA(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)
__EXTERN INTEGER __STDCALL SHGetFileInfoA(LONGINT pszPath, SET dwFileAttributes, WinAPI_SHFILEINFOA *psfi, INTEGER cbFileInfo, SET uFlags);
#define WinAPI_SHGetFileInfoA(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)	SHGetFileInfoA(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)
__EXTERN INTEGER __STDCALL SHGetFileInfoW(LONGINT pszPath, SET dwFileAttributes, WinAPI_SHFILEINFOW *psfi, INTEGER cbFileInfo, SET uFlags);
#define WinAPI_SHGetFileInfoW(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)	SHGetFileInfoW(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)
#define WinAPI_SHGetNewLinkInfo(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)	SHGetNewLinkInfoA(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)
__EXTERN INTEGER __STDCALL SHGetNewLinkInfoA(LONGINT pszLinkTo, LONGINT pszDir, LONGINT pszName, INTEGER *pfMustCopy, SET uFlags);
#define WinAPI_SHGetNewLinkInfoA(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)	SHGetNewLinkInfoA(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)
__EXTERN INTEGER __STDCALL SHGetNewLinkInfoW(LONGINT pszLinkTo, LONGINT pszDir, LONGINT pszName, INTEGER *pfMustCopy, SET uFlags);
#define WinAPI_SHGetNewLinkInfoW(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)	SHGetNewLinkInfoW(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)
__EXTERN INTEGER __STDCALL SaveDC(LONGINT p0);
#define WinAPI_SaveDC(p0)	SaveDC(p0)
__EXTERN INTEGER __STDCALL ScaleViewportExtEx(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_SIZE *p5);
#define WinAPI_ScaleViewportExtEx(p0, p1, p2, p3, p4, p5)	ScaleViewportExtEx(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __STDCALL ScaleWindowExtEx(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_SIZE *p5);
#define WinAPI_ScaleWindowExtEx(p0, p1, p2, p3, p4, p5)	ScaleWindowExtEx(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __STDCALL ScheduleJob(LONGINT hPrinter, INTEGER JobId);
#define WinAPI_ScheduleJob(hPrinter, JobId)	ScheduleJob(hPrinter, JobId)
__EXTERN INTEGER __STDCALL ScreenToClient(LONGINT hWnd, WinAPI_POINT *lpPoint);
#define WinAPI_ScreenToClient(hWnd, lpPoint)	ScreenToClient(hWnd, lpPoint)
#define WinAPI_ScrollConsoleScreenBuffer(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)	ScrollConsoleScreenBufferA(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)
__EXTERN INTEGER __STDCALL ScrollConsoleScreenBufferA(LONGINT hConsoleOutput, WinAPI_SMALL_RECT *lpScrollRectangle, WinAPI_SMALL_RECT *lpClipRectangle, WinAPI_COORD *dwDestinationOrigin, WinAPI_CHAR_INFO *lpFill);
#define WinAPI_ScrollConsoleScreenBufferA(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)	ScrollConsoleScreenBufferA(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)
__EXTERN INTEGER __STDCALL ScrollConsoleScreenBufferW(LONGINT hConsoleOutput, WinAPI_SMALL_RECT *lpScrollRectangle, WinAPI_SMALL_RECT *lpClipRectangle, WinAPI_COORD *dwDestinationOrigin, WinAPI_CHAR_INFO *lpFill);
#define WinAPI_ScrollConsoleScreenBufferW(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)	ScrollConsoleScreenBufferW(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)
__EXTERN INTEGER __STDCALL ScrollDC(LONGINT hDC, INTEGER dx, INTEGER dy, WinAPI_RECT *lprcScroll, WinAPI_RECT *lprcClip, LONGINT hrgnUpdate, WinAPI_RECT *lprcUpdate);
#define WinAPI_ScrollDC(hDC, dx, dy, lprcScroll, lprcClip, hrgnUpdate, lprcUpdate)	ScrollDC(hDC, dx, dy, lprcScroll, lprcClip, hrgnUpdate, lprcUpdate)
__EXTERN INTEGER __STDCALL ScrollWindow(LONGINT hWnd, INTEGER XAmount, INTEGER YAmount, WinAPI_RECT *lpRect, WinAPI_RECT *lpClipRect);
#define WinAPI_ScrollWindow(hWnd, XAmount, YAmount, lpRect, lpClipRect)	ScrollWindow(hWnd, XAmount, YAmount, lpRect, lpClipRect)
__EXTERN INTEGER __STDCALL ScrollWindowEx(LONGINT hWnd, INTEGER dx, INTEGER dy, WinAPI_RECT *prcScroll, WinAPI_RECT *prcClip, LONGINT hrgnUpdate, WinAPI_RECT *prcUpdate, SET flags);
#define WinAPI_ScrollWindowEx(hWnd, dx, dy, prcScroll, prcClip, hrgnUpdate, prcUpdate, flags)	ScrollWindowEx(hWnd, dx, dy, prcScroll, prcClip, hrgnUpdate, prcUpdate, flags)
#define WinAPI_SearchPath(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)	SearchPathA(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)
__EXTERN INTEGER __STDCALL SearchPathA(LONGINT lpPath, LONGINT lpFileName, LONGINT lpExtension, INTEGER nBufferLength, LONGINT lpBuffer, LONGINT *lpFilePart);
#define WinAPI_SearchPathA(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)	SearchPathA(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)
__EXTERN INTEGER __STDCALL SearchPathW(LONGINT lpPath, LONGINT lpFileName, LONGINT lpExtension, INTEGER nBufferLength, LONGINT lpBuffer, LONGINT *lpFilePart);
#define WinAPI_SearchPathW(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)	SearchPathW(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)
__EXTERN INTEGER __STDCALL SelectClipPath(LONGINT p0, INTEGER p1);
#define WinAPI_SelectClipPath(p0, p1)	SelectClipPath(p0, p1)
__EXTERN INTEGER __STDCALL SelectClipRgn(LONGINT p0, LONGINT p1);
#define WinAPI_SelectClipRgn(p0, p1)	SelectClipRgn(p0, p1)
__EXTERN LONGINT __STDCALL SelectObject(LONGINT p0, LONGINT p1);
#define WinAPI_SelectObject(p0, p1)	SelectObject(p0, p1)
__EXTERN LONGINT __STDCALL SelectPalette(LONGINT p0, LONGINT p1, INTEGER p2);
#define WinAPI_SelectPalette(p0, p1, p2)	SelectPalette(p0, p1, p2)
#define WinAPI_SendDlgItemMessage(hDlg, nIDDlgItem, Msg, wParam, lParam)	SendDlgItemMessageA(hDlg, nIDDlgItem, Msg, wParam, lParam)
__EXTERN INTEGER __STDCALL SendDlgItemMessageA(LONGINT hDlg, INTEGER nIDDlgItem, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_SendDlgItemMessageA(hDlg, nIDDlgItem, Msg, wParam, lParam)	SendDlgItemMessageA(hDlg, nIDDlgItem, Msg, wParam, lParam)
__EXTERN INTEGER __STDCALL SendDlgItemMessageW(LONGINT hDlg, INTEGER nIDDlgItem, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_SendDlgItemMessageW(hDlg, nIDDlgItem, Msg, wParam, lParam)	SendDlgItemMessageW(hDlg, nIDDlgItem, Msg, wParam, lParam)
#define WinAPI_SendMessage(hWnd, Msg, wParam, lParam)	SendMessageA(hWnd, Msg, wParam, lParam)
__EXTERN LONGINT __STDCALL SendMessageA(LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_SendMessageA(hWnd, Msg, wParam, lParam)	SendMessageA(hWnd, Msg, wParam, lParam)
#define WinAPI_SendMessageCallback(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)	SendMessageCallbackA(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)
__EXTERN INTEGER __STDCALL SendMessageCallbackA(LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam, WinAPI_SENDASYNCPROC lpResultCallBack, INTEGER dwData);
#define WinAPI_SendMessageCallbackA(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)	SendMessageCallbackA(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)
__EXTERN INTEGER __STDCALL SendMessageCallbackW(LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam, WinAPI_SENDASYNCPROC lpResultCallBack, INTEGER dwData);
#define WinAPI_SendMessageCallbackW(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)	SendMessageCallbackW(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)
#define WinAPI_SendMessageTimeout(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)	SendMessageTimeoutA(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)
__EXTERN LONGINT __STDCALL SendMessageTimeoutA(LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam, SET fuFlags, INTEGER uTimeout, INTEGER *lpdwResult);
#define WinAPI_SendMessageTimeoutA(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)	SendMessageTimeoutA(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)
__EXTERN LONGINT __STDCALL SendMessageTimeoutW(LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam, SET fuFlags, INTEGER uTimeout, INTEGER *lpdwResult);
#define WinAPI_SendMessageTimeoutW(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)	SendMessageTimeoutW(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)
__EXTERN LONGINT __STDCALL SendMessageW(LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_SendMessageW(hWnd, Msg, wParam, lParam)	SendMessageW(hWnd, Msg, wParam, lParam)
#define WinAPI_SendNotifyMessage(hWnd, Msg, wParam, lParam)	SendNotifyMessageA(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __STDCALL SendNotifyMessageA(LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_SendNotifyMessageA(hWnd, Msg, wParam, lParam)	SendNotifyMessageA(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __STDCALL SendNotifyMessageW(LONGINT hWnd, INTEGER Msg, LONGINT wParam, LONGINT lParam);
#define WinAPI_SendNotifyMessageW(hWnd, Msg, wParam, lParam)	SendNotifyMessageW(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __STDCALL SetAbortProc(LONGINT p0, WinAPI_ABORTPROC p1);
#define WinAPI_SetAbortProc(p0, p1)	SetAbortProc(p0, p1)
__EXTERN INTEGER __STDCALL SetAclInformation(WinAPI_ACL *pAcl, LONGINT pAclInformation, INTEGER nAclInformationLength, INTEGER dwAclInformationClass);
#define WinAPI_SetAclInformation(pAcl, pAclInformation, nAclInformationLength, dwAclInformationClass)	SetAclInformation(pAcl, pAclInformation, nAclInformationLength, dwAclInformationClass)
__EXTERN LONGINT __STDCALL SetActiveWindow(LONGINT hWnd);
#define WinAPI_SetActiveWindow(hWnd)	SetActiveWindow(hWnd)
__EXTERN INTEGER __STDCALL SetArcDirection(LONGINT p0, INTEGER p1);
#define WinAPI_SetArcDirection(p0, p1)	SetArcDirection(p0, p1)
__EXTERN INTEGER __STDCALL SetBitmapBits(LONGINT p0, INTEGER p1, LONGINT p2);
#define WinAPI_SetBitmapBits(p0, p1, p2)	SetBitmapBits(p0, p1, p2)
__EXTERN INTEGER __STDCALL SetBitmapDimensionEx(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_SetBitmapDimensionEx(p0, p1, p2, p3)	SetBitmapDimensionEx(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL SetBkColor(LONGINT p0, INTEGER p1);
#define WinAPI_SetBkColor(p0, p1)	SetBkColor(p0, p1)
__EXTERN INTEGER __STDCALL SetBkMode(LONGINT p0, INTEGER p1);
#define WinAPI_SetBkMode(p0, p1)	SetBkMode(p0, p1)
__EXTERN SET __STDCALL SetBoundsRect(LONGINT p0, WinAPI_RECT *p1, SET p2);
#define WinAPI_SetBoundsRect(p0, p1, p2)	SetBoundsRect(p0, p1, p2)
__EXTERN INTEGER __STDCALL SetBrushOrgEx(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_SetBrushOrgEx(p0, p1, p2, p3)	SetBrushOrgEx(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL SetCapture(LONGINT hWnd);
#define WinAPI_SetCapture(hWnd)	SetCapture(hWnd)
__EXTERN INTEGER __STDCALL SetCaretBlinkTime(INTEGER uMSeconds);
#define WinAPI_SetCaretBlinkTime(uMSeconds)	SetCaretBlinkTime(uMSeconds)
__EXTERN INTEGER __STDCALL SetCaretPos(INTEGER X, INTEGER Y);
#define WinAPI_SetCaretPos(X, Y)	SetCaretPos(X, Y)
#define WinAPI_SetClassLong(hWnd, nIndex, dwNewLong)	SetClassLongA(hWnd, nIndex, dwNewLong)
__EXTERN INTEGER __STDCALL SetClassLongA(LONGINT hWnd, INTEGER nIndex, INTEGER dwNewLong);
#define WinAPI_SetClassLongA(hWnd, nIndex, dwNewLong)	SetClassLongA(hWnd, nIndex, dwNewLong)
__EXTERN INTEGER __STDCALL SetClassLongW(LONGINT hWnd, INTEGER nIndex, INTEGER dwNewLong);
#define WinAPI_SetClassLongW(hWnd, nIndex, dwNewLong)	SetClassLongW(hWnd, nIndex, dwNewLong)
__EXTERN SHORTINT __STDCALL SetClassWord(LONGINT hWnd, INTEGER nIndex, SHORTINT wNewWord);
#define WinAPI_SetClassWord(hWnd, nIndex, wNewWord)	SetClassWord(hWnd, nIndex, wNewWord)
__EXTERN LONGINT __STDCALL SetClipboardData(INTEGER uFormat, LONGINT hMem);
#define WinAPI_SetClipboardData(uFormat, hMem)	SetClipboardData(uFormat, hMem)
__EXTERN LONGINT __STDCALL SetClipboardViewer(LONGINT hWndNewViewer);
#define WinAPI_SetClipboardViewer(hWndNewViewer)	SetClipboardViewer(hWndNewViewer)
__EXTERN INTEGER __STDCALL SetColorAdjustment(LONGINT p0, WinAPI_COLORADJUSTMENT *p1);
#define WinAPI_SetColorAdjustment(p0, p1)	SetColorAdjustment(p0, p1)
__EXTERN INTEGER __STDCALL SetColorSpace(LONGINT p0, LONGINT p1);
#define WinAPI_SetColorSpace(p0, p1)	SetColorSpace(p0, p1)
__EXTERN INTEGER __STDCALL SetCommBreak(LONGINT hFile);
#define WinAPI_SetCommBreak(hFile)	SetCommBreak(hFile)
__EXTERN INTEGER __STDCALL SetCommConfig(LONGINT hCommDev, WinAPI_COMMCONFIG *lpCC, INTEGER dwSize);
#define WinAPI_SetCommConfig(hCommDev, lpCC, dwSize)	SetCommConfig(hCommDev, lpCC, dwSize)
__EXTERN INTEGER __STDCALL SetCommMask(LONGINT hFile, SET dwEvtMask);
#define WinAPI_SetCommMask(hFile, dwEvtMask)	SetCommMask(hFile, dwEvtMask)
__EXTERN INTEGER __STDCALL SetCommState(LONGINT hFile, WinAPI_DCB *lpDCB);
#define WinAPI_SetCommState(hFile, lpDCB)	SetCommState(hFile, lpDCB)
__EXTERN INTEGER __STDCALL SetCommTimeouts(LONGINT hFile, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
#define WinAPI_SetCommTimeouts(hFile, lpCommTimeouts)	SetCommTimeouts(hFile, lpCommTimeouts)
#define WinAPI_SetComputerName(lpComputerName)	SetComputerNameA(lpComputerName)
__EXTERN INTEGER __STDCALL SetComputerNameA(LONGINT lpComputerName);
#define WinAPI_SetComputerNameA(lpComputerName)	SetComputerNameA(lpComputerName)
__EXTERN INTEGER __STDCALL SetComputerNameW(LONGINT lpComputerName);
#define WinAPI_SetComputerNameW(lpComputerName)	SetComputerNameW(lpComputerName)
__EXTERN INTEGER __STDCALL SetConsoleActiveScreenBuffer(LONGINT hConsoleOutput);
#define WinAPI_SetConsoleActiveScreenBuffer(hConsoleOutput)	SetConsoleActiveScreenBuffer(hConsoleOutput)
__EXTERN INTEGER __STDCALL SetConsoleCP(INTEGER wCodePageID);
#define WinAPI_SetConsoleCP(wCodePageID)	SetConsoleCP(wCodePageID)
__EXTERN INTEGER __STDCALL SetConsoleCtrlHandler(WinAPI_HANDLER_ROUTINE HandlerRoutine, INTEGER Add);
#define WinAPI_SetConsoleCtrlHandler(HandlerRoutine, Add)	SetConsoleCtrlHandler(HandlerRoutine, Add)
__EXTERN INTEGER __STDCALL SetConsoleCursorInfo(LONGINT hConsoleOutput, WinAPI_CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
#define WinAPI_SetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo)	SetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo)
__EXTERN INTEGER __STDCALL SetConsoleCursorPosition(LONGINT hConsoleOutput, WinAPI_COORD *dwCursorPosition);
#define WinAPI_SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition)	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition)
__EXTERN INTEGER __STDCALL SetConsoleMode(LONGINT hConsoleHandle, SET dwMode);
#define WinAPI_SetConsoleMode(hConsoleHandle, dwMode)	SetConsoleMode(hConsoleHandle, dwMode)
__EXTERN INTEGER __STDCALL SetConsoleOutputCP(INTEGER wCodePageID);
#define WinAPI_SetConsoleOutputCP(wCodePageID)	SetConsoleOutputCP(wCodePageID)
__EXTERN INTEGER __STDCALL SetConsoleScreenBufferSize(LONGINT hConsoleOutput, WinAPI_COORD *dwSize);
#define WinAPI_SetConsoleScreenBufferSize(hConsoleOutput, dwSize)	SetConsoleScreenBufferSize(hConsoleOutput, dwSize)
__EXTERN INTEGER __STDCALL SetConsoleTextAttribute(LONGINT hConsoleOutput, SHORTINT wAttributes);
#define WinAPI_SetConsoleTextAttribute(hConsoleOutput, wAttributes)	SetConsoleTextAttribute(hConsoleOutput, wAttributes)
#define WinAPI_SetConsoleTitle(lpConsoleTitle)	SetConsoleTitleA(lpConsoleTitle)
__EXTERN INTEGER __STDCALL SetConsoleTitleA(LONGINT lpConsoleTitle);
#define WinAPI_SetConsoleTitleA(lpConsoleTitle)	SetConsoleTitleA(lpConsoleTitle)
__EXTERN INTEGER __STDCALL SetConsoleTitleW(LONGINT lpConsoleTitle);
#define WinAPI_SetConsoleTitleW(lpConsoleTitle)	SetConsoleTitleW(lpConsoleTitle)
__EXTERN INTEGER __STDCALL SetConsoleWindowInfo(LONGINT hConsoleOutput, INTEGER bAbsolute, WinAPI_SMALL_RECT *lpConsoleWindow);
#define WinAPI_SetConsoleWindowInfo(hConsoleOutput, bAbsolute, lpConsoleWindow)	SetConsoleWindowInfo(hConsoleOutput, bAbsolute, lpConsoleWindow)
#define WinAPI_SetCurrentDirectory(lpPathName)	SetCurrentDirectoryA(lpPathName)
__EXTERN INTEGER __STDCALL SetCurrentDirectoryA(LONGINT lpPathName);
#define WinAPI_SetCurrentDirectoryA(lpPathName)	SetCurrentDirectoryA(lpPathName)
__EXTERN INTEGER __STDCALL SetCurrentDirectoryW(LONGINT lpPathName);
#define WinAPI_SetCurrentDirectoryW(lpPathName)	SetCurrentDirectoryW(lpPathName)
__EXTERN LONGINT __STDCALL SetCursor(LONGINT hCursor);
#define WinAPI_SetCursor(hCursor)	SetCursor(hCursor)
__EXTERN INTEGER __STDCALL SetCursorPos(INTEGER X, INTEGER Y);
#define WinAPI_SetCursorPos(X, Y)	SetCursorPos(X, Y)
__EXTERN INTEGER __STDCALL SetDIBColorTable(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_RGBQUAD *p3);
#define WinAPI_SetDIBColorTable(p0, p1, p2, p3, p3__len)	SetDIBColorTable(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL SetDIBits(LONGINT p0, LONGINT p1, INTEGER p2, INTEGER p3, LONGINT p4, WinAPI_BITMAPINFO *p5, INTEGER p6);
#define WinAPI_SetDIBits(p0, p1, p2, p3, p4, p5, p6)	SetDIBits(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __STDCALL SetDIBitsToDevice(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, LONGINT p9, WinAPI_BITMAPINFO *p10, INTEGER p11);
#define WinAPI_SetDIBitsToDevice(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)	SetDIBitsToDevice(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)
__EXTERN void __STDCALL SetDebugErrorLevel(INTEGER dwLevel);
#define WinAPI_SetDebugErrorLevel(dwLevel)	SetDebugErrorLevel(dwLevel)
#define WinAPI_SetDefaultCommConfig(lpszName, lpCC, dwSize)	SetDefaultCommConfigA(lpszName, lpCC, dwSize)
__EXTERN INTEGER __STDCALL SetDefaultCommConfigA(LONGINT lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER dwSize);
#define WinAPI_SetDefaultCommConfigA(lpszName, lpCC, dwSize)	SetDefaultCommConfigA(lpszName, lpCC, dwSize)
__EXTERN INTEGER __STDCALL SetDefaultCommConfigW(LONGINT lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER dwSize);
#define WinAPI_SetDefaultCommConfigW(lpszName, lpCC, dwSize)	SetDefaultCommConfigW(lpszName, lpCC, dwSize)
__EXTERN INTEGER __STDCALL SetDeviceGammaRamp(LONGINT p0, LONGINT p1);
#define WinAPI_SetDeviceGammaRamp(p0, p1)	SetDeviceGammaRamp(p0, p1)
__EXTERN INTEGER __STDCALL SetDlgItemInt(LONGINT hDlg, INTEGER nIDDlgItem, INTEGER uValue, INTEGER bSigned);
#define WinAPI_SetDlgItemInt(hDlg, nIDDlgItem, uValue, bSigned)	SetDlgItemInt(hDlg, nIDDlgItem, uValue, bSigned)
#define WinAPI_SetDlgItemText(hDlg, nIDDlgItem, lpString)	SetDlgItemTextA(hDlg, nIDDlgItem, lpString)
__EXTERN INTEGER __STDCALL SetDlgItemTextA(LONGINT hDlg, INTEGER nIDDlgItem, LONGINT lpString);
#define WinAPI_SetDlgItemTextA(hDlg, nIDDlgItem, lpString)	SetDlgItemTextA(hDlg, nIDDlgItem, lpString)
__EXTERN INTEGER __STDCALL SetDlgItemTextW(LONGINT hDlg, INTEGER nIDDlgItem, LONGINT lpString);
#define WinAPI_SetDlgItemTextW(hDlg, nIDDlgItem, lpString)	SetDlgItemTextW(hDlg, nIDDlgItem, lpString)
__EXTERN INTEGER __STDCALL SetDoubleClickTime(INTEGER p0);
#define WinAPI_SetDoubleClickTime(p0)	SetDoubleClickTime(p0)
__EXTERN INTEGER __STDCALL SetEndOfFile(LONGINT hFile);
#define WinAPI_SetEndOfFile(hFile)	SetEndOfFile(hFile)
__EXTERN LONGINT __STDCALL SetEnhMetaFileBits(INTEGER p0, CHAR *p1);
#define WinAPI_SetEnhMetaFileBits(p0, p1)	SetEnhMetaFileBits(p0, p1)
#define WinAPI_SetEnvironmentVariable(lpName, lpValue)	SetEnvironmentVariableA(lpName, lpValue)
__EXTERN INTEGER __STDCALL SetEnvironmentVariableA(LONGINT lpName, LONGINT lpValue);
#define WinAPI_SetEnvironmentVariableA(lpName, lpValue)	SetEnvironmentVariableA(lpName, lpValue)
__EXTERN INTEGER __STDCALL SetEnvironmentVariableW(LONGINT lpName, LONGINT lpValue);
#define WinAPI_SetEnvironmentVariableW(lpName, lpValue)	SetEnvironmentVariableW(lpName, lpValue)
__EXTERN INTEGER __STDCALL SetErrorMode(SET uMode);
#define WinAPI_SetErrorMode(uMode)	SetErrorMode(uMode)
__EXTERN INTEGER __STDCALL SetEvent(LONGINT hEvent);
#define WinAPI_SetEvent(hEvent)	SetEvent(hEvent)
__EXTERN void __STDCALL SetFileApisToANSI(void);
#define WinAPI_SetFileApisToANSI()	SetFileApisToANSI()
__EXTERN void __STDCALL SetFileApisToOEM(void);
#define WinAPI_SetFileApisToOEM()	SetFileApisToOEM()
#define WinAPI_SetFileAttributes(lpFileName, dwFileAttributes)	SetFileAttributesA(lpFileName, dwFileAttributes)
__EXTERN INTEGER __STDCALL SetFileAttributesA(LONGINT lpFileName, SET dwFileAttributes);
#define WinAPI_SetFileAttributesA(lpFileName, dwFileAttributes)	SetFileAttributesA(lpFileName, dwFileAttributes)
__EXTERN INTEGER __STDCALL SetFileAttributesW(LONGINT lpFileName, SET dwFileAttributes);
#define WinAPI_SetFileAttributesW(lpFileName, dwFileAttributes)	SetFileAttributesW(lpFileName, dwFileAttributes)
__EXTERN INTEGER __STDCALL SetFilePointer(LONGINT hFile, INTEGER lDistanceToMove, INTEGER *lpDistanceToMoveHigh, INTEGER dwMoveMethod);
#define WinAPI_SetFilePointer(hFile, lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod)	SetFilePointer(hFile, lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod)
#define WinAPI_SetFileSecurity(lpFileName, SecurityInformation, pSecurityDescriptor)	SetFileSecurityA(lpFileName, SecurityInformation, pSecurityDescriptor)
__EXTERN INTEGER __STDCALL SetFileSecurityA(LONGINT lpFileName, SET SecurityInformation, LONGINT pSecurityDescriptor);
#define WinAPI_SetFileSecurityA(lpFileName, SecurityInformation, pSecurityDescriptor)	SetFileSecurityA(lpFileName, SecurityInformation, pSecurityDescriptor)
__EXTERN INTEGER __STDCALL SetFileSecurityW(LONGINT lpFileName, SET SecurityInformation, LONGINT pSecurityDescriptor);
#define WinAPI_SetFileSecurityW(lpFileName, SecurityInformation, pSecurityDescriptor)	SetFileSecurityW(lpFileName, SecurityInformation, pSecurityDescriptor)
__EXTERN INTEGER __STDCALL SetFileTime(LONGINT hFile, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpLastAccessTime, WinAPI_FILETIME *lpLastWriteTime);
#define WinAPI_SetFileTime(hFile, lpCreationTime, lpLastAccessTime, lpLastWriteTime)	SetFileTime(hFile, lpCreationTime, lpLastAccessTime, lpLastWriteTime)
__EXTERN LONGINT __STDCALL SetFocus(LONGINT hWnd);
#define WinAPI_SetFocus(hWnd)	SetFocus(hWnd)
__EXTERN INTEGER __STDCALL SetForegroundWindow(LONGINT hWnd);
#define WinAPI_SetForegroundWindow(hWnd)	SetForegroundWindow(hWnd)
#define WinAPI_SetForm(hPrinter, pFormName, Level, pForm)	SetFormA(hPrinter, pFormName, Level, pForm)
__EXTERN INTEGER __STDCALL SetFormA(LONGINT hPrinter, LONGINT pFormName, INTEGER Level, CHAR *pForm);
#define WinAPI_SetFormA(hPrinter, pFormName, Level, pForm)	SetFormA(hPrinter, pFormName, Level, pForm)
__EXTERN INTEGER __STDCALL SetFormW(LONGINT hPrinter, LONGINT pFormName, INTEGER Level, CHAR *pForm);
#define WinAPI_SetFormW(hPrinter, pFormName, Level, pForm)	SetFormW(hPrinter, pFormName, Level, pForm)
__EXTERN INTEGER __STDCALL SetGraphicsMode(LONGINT hdc, INTEGER iMode);
#define WinAPI_SetGraphicsMode(hdc, iMode)	SetGraphicsMode(hdc, iMode)
__EXTERN INTEGER __STDCALL SetHandleCount(INTEGER uNumber);
#define WinAPI_SetHandleCount(uNumber)	SetHandleCount(uNumber)
__EXTERN INTEGER __STDCALL SetHandleInformation(LONGINT hObject, INTEGER dwMask, SET dwFlags);
#define WinAPI_SetHandleInformation(hObject, dwMask, dwFlags)	SetHandleInformation(hObject, dwMask, dwFlags)
__EXTERN INTEGER __STDCALL SetICMMode(LONGINT p0, INTEGER p1);
#define WinAPI_SetICMMode(p0, p1)	SetICMMode(p0, p1)
#define WinAPI_SetICMProfile(p0, p1)	SetICMProfileA(p0, p1)
__EXTERN INTEGER __STDCALL SetICMProfileA(LONGINT p0, LONGINT p1);
#define WinAPI_SetICMProfileA(p0, p1)	SetICMProfileA(p0, p1)
__EXTERN INTEGER __STDCALL SetICMProfileW(LONGINT p0, LONGINT p1);
#define WinAPI_SetICMProfileW(p0, p1)	SetICMProfileW(p0, p1)
#define WinAPI_SetJob(hPrinter, JobId, Level, pJob, Command)	SetJobA(hPrinter, JobId, Level, pJob, Command)
__EXTERN INTEGER __STDCALL SetJobA(LONGINT hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER Command);
#define WinAPI_SetJobA(hPrinter, JobId, Level, pJob, Command)	SetJobA(hPrinter, JobId, Level, pJob, Command)
__EXTERN INTEGER __STDCALL SetJobW(LONGINT hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER Command);
#define WinAPI_SetJobW(hPrinter, JobId, Level, pJob, Command)	SetJobW(hPrinter, JobId, Level, pJob, Command)
__EXTERN INTEGER __STDCALL SetKernelObjectSecurity(LONGINT Handle, SET SecurityInformation, LONGINT SecurityDescriptor);
#define WinAPI_SetKernelObjectSecurity(Handle, SecurityInformation, SecurityDescriptor)	SetKernelObjectSecurity(Handle, SecurityInformation, SecurityDescriptor)
__EXTERN INTEGER __STDCALL SetKeyboardState(CHAR *lpKeyState);
#define WinAPI_SetKeyboardState(lpKeyState)	SetKeyboardState(lpKeyState)
__EXTERN void __STDCALL SetLastError(INTEGER dwErrCode);
#define WinAPI_SetLastError(dwErrCode)	SetLastError(dwErrCode)
__EXTERN void __STDCALL SetLastErrorEx(INTEGER dwErrCode, INTEGER dwType);
#define WinAPI_SetLastErrorEx(dwErrCode, dwType)	SetLastErrorEx(dwErrCode, dwType)
__EXTERN INTEGER __STDCALL SetLocalTime(WinAPI_SYSTEMTIME *lpSystemTime);
#define WinAPI_SetLocalTime(lpSystemTime)	SetLocalTime(lpSystemTime)
#define WinAPI_SetLocaleInfo(Locale, LCType, lpLCData)	SetLocaleInfoA(Locale, LCType, lpLCData)
__EXTERN INTEGER __STDCALL SetLocaleInfoA(INTEGER Locale, INTEGER LCType, LONGINT lpLCData);
#define WinAPI_SetLocaleInfoA(Locale, LCType, lpLCData)	SetLocaleInfoA(Locale, LCType, lpLCData)
__EXTERN INTEGER __STDCALL SetLocaleInfoW(INTEGER Locale, INTEGER LCType, LONGINT lpLCData);
#define WinAPI_SetLocaleInfoW(Locale, LCType, lpLCData)	SetLocaleInfoW(Locale, LCType, lpLCData)
__EXTERN INTEGER __STDCALL SetMailslotInfo(LONGINT hMailslot, INTEGER lReadTimeout);
#define WinAPI_SetMailslotInfo(hMailslot, lReadTimeout)	SetMailslotInfo(hMailslot, lReadTimeout)
__EXTERN INTEGER __STDCALL SetMapMode(LONGINT p0, INTEGER p1);
#define WinAPI_SetMapMode(p0, p1)	SetMapMode(p0, p1)
__EXTERN INTEGER __STDCALL SetMapperFlags(LONGINT p0, INTEGER p1);
#define WinAPI_SetMapperFlags(p0, p1)	SetMapperFlags(p0, p1)
__EXTERN INTEGER __STDCALL SetMenu(LONGINT hWnd, LONGINT hMenu);
#define WinAPI_SetMenu(hWnd, hMenu)	SetMenu(hWnd, hMenu)
__EXTERN INTEGER __STDCALL SetMenuContextHelpId(LONGINT p0, INTEGER p1);
#define WinAPI_SetMenuContextHelpId(p0, p1)	SetMenuContextHelpId(p0, p1)
__EXTERN INTEGER __STDCALL SetMenuDefaultItem(LONGINT hMenu, INTEGER uItem, INTEGER fByPos);
#define WinAPI_SetMenuDefaultItem(hMenu, uItem, fByPos)	SetMenuDefaultItem(hMenu, uItem, fByPos)
__EXTERN INTEGER __STDCALL SetMenuItemBitmaps(LONGINT hMenu, INTEGER uPosition, SET uFlags, LONGINT hBitmapUnchecked, LONGINT hBitmapChecked);
#define WinAPI_SetMenuItemBitmaps(hMenu, uPosition, uFlags, hBitmapUnchecked, hBitmapChecked)	SetMenuItemBitmaps(hMenu, uPosition, uFlags, hBitmapUnchecked, hBitmapChecked)
#define WinAPI_SetMenuItemInfo(p0, p1, p2, p3)	SetMenuItemInfoA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL SetMenuItemInfoA(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOA *p3);
#define WinAPI_SetMenuItemInfoA(p0, p1, p2, p3)	SetMenuItemInfoA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL SetMenuItemInfoW(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOW *p3);
#define WinAPI_SetMenuItemInfoW(p0, p1, p2, p3)	SetMenuItemInfoW(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL SetMessageExtraInfo(LONGINT lParam);
#define WinAPI_SetMessageExtraInfo(lParam)	SetMessageExtraInfo(lParam)
__EXTERN INTEGER __STDCALL SetMessageQueue(INTEGER cMessagesMax);
#define WinAPI_SetMessageQueue(cMessagesMax)	SetMessageQueue(cMessagesMax)
__EXTERN LONGINT __STDCALL SetMetaFileBitsEx(INTEGER p0, BYTE *p1);
#define WinAPI_SetMetaFileBitsEx(p0, p1)	SetMetaFileBitsEx(p0, p1)
__EXTERN INTEGER __STDCALL SetMetaRgn(LONGINT p0);
#define WinAPI_SetMetaRgn(p0)	SetMetaRgn(p0)
__EXTERN INTEGER __STDCALL SetMiterLimit(LONGINT p0, SHORTREAL p1, SHORTREAL *p2);
#define WinAPI_SetMiterLimit(p0, p1, p2)	SetMiterLimit(p0, p1, p2)
__EXTERN INTEGER __STDCALL SetNamedPipeHandleState(LONGINT hNamedPipe, INTEGER *lpMode, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout);
#define WinAPI_SetNamedPipeHandleState(hNamedPipe, lpMode, lpMaxCollectionCount, lpCollectDataTimeout)	SetNamedPipeHandleState(hNamedPipe, lpMode, lpMaxCollectionCount, lpCollectDataTimeout)
__EXTERN INTEGER __STDCALL SetPaletteEntries(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
#define WinAPI_SetPaletteEntries(p0, p1, p2, p3)	SetPaletteEntries(p0, p1, p2, p3)
__EXTERN LONGINT __STDCALL SetParent(LONGINT hWndChild, LONGINT hWndNewParent);
#define WinAPI_SetParent(hWndChild, hWndNewParent)	SetParent(hWndChild, hWndNewParent)
__EXTERN INTEGER __STDCALL SetPixel(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_SetPixel(p0, p1, p2, p3)	SetPixel(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL SetPixelFormat(LONGINT p0, INTEGER p1, WinAPI_PIXELFORMATDESCRIPTOR *p2);
#define WinAPI_SetPixelFormat(p0, p1, p2)	SetPixelFormat(p0, p1, p2)
__EXTERN INTEGER __STDCALL SetPixelV(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_SetPixelV(p0, p1, p2, p3)	SetPixelV(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL SetPolyFillMode(LONGINT p0, INTEGER p1);
#define WinAPI_SetPolyFillMode(p0, p1)	SetPolyFillMode(p0, p1)
#define WinAPI_SetPrinter(hPrinter, Level, pPrinter, Command)	SetPrinterA(hPrinter, Level, pPrinter, Command)
__EXTERN INTEGER __STDCALL SetPrinterA(LONGINT hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER Command);
#define WinAPI_SetPrinterA(hPrinter, Level, pPrinter, Command)	SetPrinterA(hPrinter, Level, pPrinter, Command)
#define WinAPI_SetPrinterData(hPrinter, pValueName, Type, pData, cbData)	SetPrinterDataA(hPrinter, pValueName, Type, pData, cbData)
__EXTERN INTEGER __STDCALL SetPrinterDataA(LONGINT hPrinter, LONGINT pValueName, INTEGER Type, CHAR *pData, INTEGER cbData);
#define WinAPI_SetPrinterDataA(hPrinter, pValueName, Type, pData, cbData)	SetPrinterDataA(hPrinter, pValueName, Type, pData, cbData)
__EXTERN INTEGER __STDCALL SetPrinterDataW(LONGINT hPrinter, LONGINT pValueName, INTEGER Type, CHAR *pData, INTEGER cbData);
#define WinAPI_SetPrinterDataW(hPrinter, pValueName, Type, pData, cbData)	SetPrinterDataW(hPrinter, pValueName, Type, pData, cbData)
__EXTERN INTEGER __STDCALL SetPrinterW(LONGINT hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER Command);
#define WinAPI_SetPrinterW(hPrinter, Level, pPrinter, Command)	SetPrinterW(hPrinter, Level, pPrinter, Command)
__EXTERN INTEGER __STDCALL SetPriorityClass(LONGINT hProcess, INTEGER dwPriorityClass);
#define WinAPI_SetPriorityClass(hProcess, dwPriorityClass)	SetPriorityClass(hProcess, dwPriorityClass)
__EXTERN INTEGER __STDCALL SetPrivateObjectSecurity(SET SecurityInformation, LONGINT ModificationDescriptor, LONGINT *ObjectsSecurityDescriptor, WinAPI_GENERIC_MAPPING *GenericMapping, LONGINT Token);
#define WinAPI_SetPrivateObjectSecurity(SecurityInformation, ModificationDescriptor, ObjectsSecurityDescriptor, GenericMapping, Token)	SetPrivateObjectSecurity(SecurityInformation, ModificationDescriptor, ObjectsSecurityDescriptor, GenericMapping, Token)
__EXTERN INTEGER __STDCALL SetProcessAffinityMask(LONGINT hProcess, INTEGER dwProcessAffinityMask);
#define WinAPI_SetProcessAffinityMask(hProcess, dwProcessAffinityMask)	SetProcessAffinityMask(hProcess, dwProcessAffinityMask)
__EXTERN INTEGER __STDCALL SetProcessShutdownParameters(INTEGER dwLevel, SET dwFlags);
#define WinAPI_SetProcessShutdownParameters(dwLevel, dwFlags)	SetProcessShutdownParameters(dwLevel, dwFlags)
__EXTERN INTEGER __STDCALL SetProcessWindowStation(LONGINT hWinSta);
#define WinAPI_SetProcessWindowStation(hWinSta)	SetProcessWindowStation(hWinSta)
__EXTERN INTEGER __STDCALL SetProcessWorkingSetSize(LONGINT hProcess, INTEGER dwMinimumWorkingSetSize, INTEGER dwMaximumWorkingSetSize);
#define WinAPI_SetProcessWorkingSetSize(hProcess, dwMinimumWorkingSetSize, dwMaximumWorkingSetSize)	SetProcessWorkingSetSize(hProcess, dwMinimumWorkingSetSize, dwMaximumWorkingSetSize)
#define WinAPI_SetProp(hWnd, lpString, hData)	SetPropA(hWnd, lpString, hData)
__EXTERN INTEGER __STDCALL SetPropA(LONGINT hWnd, LONGINT lpString, LONGINT hData);
#define WinAPI_SetPropA(hWnd, lpString, hData)	SetPropA(hWnd, lpString, hData)
__EXTERN INTEGER __STDCALL SetPropW(LONGINT hWnd, LONGINT lpString, LONGINT hData);
#define WinAPI_SetPropW(hWnd, lpString, hData)	SetPropW(hWnd, lpString, hData)
__EXTERN INTEGER __STDCALL SetROP2(LONGINT p0, INTEGER p1);
#define WinAPI_SetROP2(p0, p1)	SetROP2(p0, p1)
__EXTERN INTEGER __STDCALL SetRect(WinAPI_RECT *lprc, INTEGER xLeft, INTEGER yTop, INTEGER xRight, INTEGER yBottom);
#define WinAPI_SetRect(lprc, xLeft, yTop, xRight, yBottom)	SetRect(lprc, xLeft, yTop, xRight, yBottom)
__EXTERN INTEGER __STDCALL SetRectEmpty(WinAPI_RECT *lprc);
#define WinAPI_SetRectEmpty(lprc)	SetRectEmpty(lprc)
__EXTERN INTEGER __STDCALL SetRectRgn(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_SetRectRgn(p0, p1, p2, p3, p4)	SetRectRgn(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL SetScrollInfo(LONGINT p0, INTEGER p1, WinAPI_SCROLLINFO *p2, INTEGER p3);
#define WinAPI_SetScrollInfo(p0, p1, p2, p3)	SetScrollInfo(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL SetScrollPos(LONGINT hWnd, INTEGER nBar, INTEGER nPos, INTEGER bRedraw);
#define WinAPI_SetScrollPos(hWnd, nBar, nPos, bRedraw)	SetScrollPos(hWnd, nBar, nPos, bRedraw)
__EXTERN INTEGER __STDCALL SetScrollRange(LONGINT hWnd, INTEGER nBar, INTEGER nMinPos, INTEGER nMaxPos, INTEGER bRedraw);
#define WinAPI_SetScrollRange(hWnd, nBar, nMinPos, nMaxPos, bRedraw)	SetScrollRange(hWnd, nBar, nMinPos, nMaxPos, bRedraw)
__EXTERN INTEGER __STDCALL SetSecurityDescriptorDacl(LONGINT pSecurityDescriptor, INTEGER bDaclPresent, WinAPI_ACL *pDacl, INTEGER bDaclDefaulted);
#define WinAPI_SetSecurityDescriptorDacl(pSecurityDescriptor, bDaclPresent, pDacl, bDaclDefaulted)	SetSecurityDescriptorDacl(pSecurityDescriptor, bDaclPresent, pDacl, bDaclDefaulted)
__EXTERN INTEGER __STDCALL SetSecurityDescriptorGroup(LONGINT pSecurityDescriptor, LONGINT pGroup, INTEGER bGroupDefaulted);
#define WinAPI_SetSecurityDescriptorGroup(pSecurityDescriptor, pGroup, bGroupDefaulted)	SetSecurityDescriptorGroup(pSecurityDescriptor, pGroup, bGroupDefaulted)
__EXTERN INTEGER __STDCALL SetSecurityDescriptorOwner(LONGINT pSecurityDescriptor, LONGINT pOwner, INTEGER bOwnerDefaulted);
#define WinAPI_SetSecurityDescriptorOwner(pSecurityDescriptor, pOwner, bOwnerDefaulted)	SetSecurityDescriptorOwner(pSecurityDescriptor, pOwner, bOwnerDefaulted)
__EXTERN INTEGER __STDCALL SetSecurityDescriptorSacl(LONGINT pSecurityDescriptor, INTEGER bSaclPresent, WinAPI_ACL *pSacl, INTEGER bSaclDefaulted);
#define WinAPI_SetSecurityDescriptorSacl(pSecurityDescriptor, bSaclPresent, pSacl, bSaclDefaulted)	SetSecurityDescriptorSacl(pSecurityDescriptor, bSaclPresent, pSacl, bSaclDefaulted)
__EXTERN INTEGER __STDCALL SetServiceObjectSecurity(LONGINT hService, SET dwSecurityInformation, LONGINT lpSecurityDescriptor);
#define WinAPI_SetServiceObjectSecurity(hService, dwSecurityInformation, lpSecurityDescriptor)	SetServiceObjectSecurity(hService, dwSecurityInformation, lpSecurityDescriptor)
__EXTERN INTEGER __STDCALL SetServiceStatus(INTEGER hServiceStatus, WinAPI_SERVICE_STATUS *lpServiceStatus);
#define WinAPI_SetServiceStatus(hServiceStatus, lpServiceStatus)	SetServiceStatus(hServiceStatus, lpServiceStatus)
__EXTERN INTEGER __STDCALL SetStdHandle(INTEGER nStdHandle, LONGINT hHandle);
#define WinAPI_SetStdHandle(nStdHandle, hHandle)	SetStdHandle(nStdHandle, hHandle)
__EXTERN INTEGER __STDCALL SetStretchBltMode(LONGINT p0, INTEGER p1);
#define WinAPI_SetStretchBltMode(p0, p1)	SetStretchBltMode(p0, p1)
__EXTERN INTEGER __STDCALL SetSysColors(INTEGER cElements, INTEGER *lpaElements, INTEGER *lpaRgbValues);
#define WinAPI_SetSysColors(cElements, lpaElements, lpaRgbValues)	SetSysColors(cElements, lpaElements, lpaRgbValues)
__EXTERN INTEGER __STDCALL SetSystemCursor(LONGINT hcur, INTEGER id);
#define WinAPI_SetSystemCursor(hcur, id)	SetSystemCursor(hcur, id)
__EXTERN INTEGER __STDCALL SetSystemPaletteUse(LONGINT p0, INTEGER p1);
#define WinAPI_SetSystemPaletteUse(p0, p1)	SetSystemPaletteUse(p0, p1)
__EXTERN INTEGER __STDCALL SetSystemPowerState(INTEGER fSuspend, INTEGER fForce);
#define WinAPI_SetSystemPowerState(fSuspend, fForce)	SetSystemPowerState(fSuspend, fForce)
__EXTERN INTEGER __STDCALL SetSystemTime(WinAPI_SYSTEMTIME *lpSystemTime);
#define WinAPI_SetSystemTime(lpSystemTime)	SetSystemTime(lpSystemTime)
__EXTERN INTEGER __STDCALL SetSystemTimeAdjustment(INTEGER dwTimeAdjustment, INTEGER bTimeAdjustmentDisabled);
#define WinAPI_SetSystemTimeAdjustment(dwTimeAdjustment, bTimeAdjustmentDisabled)	SetSystemTimeAdjustment(dwTimeAdjustment, bTimeAdjustmentDisabled)
__EXTERN INTEGER __STDCALL SetTapeParameters(LONGINT hDevice, INTEGER dwOperation, LONGINT lpTapeInformation);
#define WinAPI_SetTapeParameters(hDevice, dwOperation, lpTapeInformation)	SetTapeParameters(hDevice, dwOperation, lpTapeInformation)
__EXTERN INTEGER __STDCALL SetTapePosition(LONGINT hDevice, INTEGER dwPositionMethod, INTEGER dwPartition, INTEGER dwOffsetLow, INTEGER dwOffsetHigh, INTEGER bImmediate);
#define WinAPI_SetTapePosition(hDevice, dwPositionMethod, dwPartition, dwOffsetLow, dwOffsetHigh, bImmediate)	SetTapePosition(hDevice, dwPositionMethod, dwPartition, dwOffsetLow, dwOffsetHigh, bImmediate)
__EXTERN SET __STDCALL SetTextAlign(LONGINT p0, SET p1);
#define WinAPI_SetTextAlign(p0, p1)	SetTextAlign(p0, p1)
__EXTERN INTEGER __STDCALL SetTextCharacterExtra(LONGINT p0, INTEGER p1);
#define WinAPI_SetTextCharacterExtra(p0, p1)	SetTextCharacterExtra(p0, p1)
__EXTERN INTEGER __STDCALL SetTextColor(LONGINT p0, INTEGER p1);
#define WinAPI_SetTextColor(p0, p1)	SetTextColor(p0, p1)
__EXTERN INTEGER __STDCALL SetTextJustification(LONGINT p0, INTEGER p1, INTEGER p2);
#define WinAPI_SetTextJustification(p0, p1, p2)	SetTextJustification(p0, p1, p2)
__EXTERN INTEGER __STDCALL SetThreadAffinityMask(LONGINT hThread, INTEGER dwThreadAffinityMask);
#define WinAPI_SetThreadAffinityMask(hThread, dwThreadAffinityMask)	SetThreadAffinityMask(hThread, dwThreadAffinityMask)
__EXTERN INTEGER __STDCALL SetThreadContext(LONGINT hThread, WinAPI_CONTEXT *lpContext);
#define WinAPI_SetThreadContext(hThread, lpContext)	SetThreadContext(hThread, lpContext)
__EXTERN INTEGER __STDCALL SetThreadDesktop(LONGINT hDesktop);
#define WinAPI_SetThreadDesktop(hDesktop)	SetThreadDesktop(hDesktop)
__EXTERN INTEGER __STDCALL SetThreadIdealProcessor(LONGINT hThread, INTEGER dwIdealProcessor);
#define WinAPI_SetThreadIdealProcessor(hThread, dwIdealProcessor)	SetThreadIdealProcessor(hThread, dwIdealProcessor)
__EXTERN INTEGER __STDCALL SetThreadLocale(INTEGER Locale);
#define WinAPI_SetThreadLocale(Locale)	SetThreadLocale(Locale)
__EXTERN INTEGER __STDCALL SetThreadPriority(LONGINT hThread, INTEGER nPriority);
#define WinAPI_SetThreadPriority(hThread, nPriority)	SetThreadPriority(hThread, nPriority)
__EXTERN INTEGER __STDCALL SetThreadPriorityBoost(LONGINT hThread, INTEGER bDisablePriorityBoost);
#define WinAPI_SetThreadPriorityBoost(hThread, bDisablePriorityBoost)	SetThreadPriorityBoost(hThread, bDisablePriorityBoost)
__EXTERN INTEGER __STDCALL SetThreadToken(LONGINT *Thread, LONGINT Token);
#define WinAPI_SetThreadToken(Thread, Token)	SetThreadToken(Thread, Token)
__EXTERN INTEGER __STDCALL SetTimeZoneInformation(WinAPI_TIME_ZONE_INFORMATION *lpTimeZoneInformation);
#define WinAPI_SetTimeZoneInformation(lpTimeZoneInformation)	SetTimeZoneInformation(lpTimeZoneInformation)
__EXTERN INTEGER __STDCALL SetTimer(LONGINT hWnd, INTEGER nIDEvent, INTEGER uElapse, WinAPI_TIMERPROC lpTimerFunc);
#define WinAPI_SetTimer(hWnd, nIDEvent, uElapse, lpTimerFunc)	SetTimer(hWnd, nIDEvent, uElapse, lpTimerFunc)
__EXTERN INTEGER __STDCALL SetTokenInformation(LONGINT TokenHandle, INTEGER TokenInformationClass, LONGINT TokenInformation, INTEGER TokenInformationLength);
#define WinAPI_SetTokenInformation(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength)	SetTokenInformation(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength)
__EXTERN WinAPI_TOP_LEVEL_EXCEPTION_FILTER __STDCALL SetUnhandledExceptionFilter(WinAPI_TOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);
#define WinAPI_SetUnhandledExceptionFilter(lpTopLevelExceptionFilter)	SetUnhandledExceptionFilter(lpTopLevelExceptionFilter)
#define WinAPI_SetUserObjectInformation(hObj, nIndex, pvInfo, nLength)	SetUserObjectInformationA(hObj, nIndex, pvInfo, nLength)
__EXTERN INTEGER __STDCALL SetUserObjectInformationA(LONGINT hObj, INTEGER nIndex, LONGINT pvInfo, INTEGER nLength);
#define WinAPI_SetUserObjectInformationA(hObj, nIndex, pvInfo, nLength)	SetUserObjectInformationA(hObj, nIndex, pvInfo, nLength)
__EXTERN INTEGER __STDCALL SetUserObjectInformationW(LONGINT hObj, INTEGER nIndex, LONGINT pvInfo, INTEGER nLength);
#define WinAPI_SetUserObjectInformationW(hObj, nIndex, pvInfo, nLength)	SetUserObjectInformationW(hObj, nIndex, pvInfo, nLength)
__EXTERN INTEGER __STDCALL SetUserObjectSecurity(LONGINT hObj, INTEGER *pSIRequested, LONGINT pSID);
#define WinAPI_SetUserObjectSecurity(hObj, pSIRequested, pSID)	SetUserObjectSecurity(hObj, pSIRequested, pSID)
__EXTERN INTEGER __STDCALL SetViewportExtEx(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_SetViewportExtEx(p0, p1, p2, p3)	SetViewportExtEx(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL SetViewportOrgEx(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_SetViewportOrgEx(p0, p1, p2, p3)	SetViewportOrgEx(p0, p1, p2, p3)
#define WinAPI_SetVolumeLabel(lpRootPathName, lpVolumeName)	SetVolumeLabelA(lpRootPathName, lpVolumeName)
__EXTERN INTEGER __STDCALL SetVolumeLabelA(LONGINT lpRootPathName, LONGINT lpVolumeName);
#define WinAPI_SetVolumeLabelA(lpRootPathName, lpVolumeName)	SetVolumeLabelA(lpRootPathName, lpVolumeName)
__EXTERN INTEGER __STDCALL SetVolumeLabelW(LONGINT lpRootPathName, LONGINT lpVolumeName);
#define WinAPI_SetVolumeLabelW(lpRootPathName, lpVolumeName)	SetVolumeLabelW(lpRootPathName, lpVolumeName)
__EXTERN INTEGER __STDCALL SetWaitableTimer(LONGINT hTimer, LONGINT *lpDueTime, INTEGER lPeriod, WinAPI_TIMERAPCROUTINE pfnCompletionRoutine, LONGINT lpArgToCompletionRoutine, INTEGER fResume);
#define WinAPI_SetWaitableTimer(hTimer, lpDueTime, lPeriod, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume)	SetWaitableTimer(hTimer, lpDueTime, lPeriod, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume)
__EXTERN LONGINT __STDCALL SetWinMetaFileBits(INTEGER p0, CHAR *p1, LONGINT p2, WinAPI_METAFILEPICT *p3);
#define WinAPI_SetWinMetaFileBits(p0, p1, p2, p3)	SetWinMetaFileBits(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL SetWindowContextHelpId(LONGINT p0, INTEGER p1);
#define WinAPI_SetWindowContextHelpId(p0, p1)	SetWindowContextHelpId(p0, p1)
__EXTERN INTEGER __STDCALL SetWindowExtEx(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_SetWindowExtEx(p0, p1, p2, p3)	SetWindowExtEx(p0, p1, p2, p3)
#define WinAPI_SetWindowLong(hWnd, nIndex, dwNewLong)	SetWindowLongA(hWnd, nIndex, dwNewLong)
__EXTERN INTEGER __STDCALL SetWindowLongA(LONGINT hWnd, INTEGER nIndex, INTEGER dwNewLong);
#define WinAPI_SetWindowLongA(hWnd, nIndex, dwNewLong)	SetWindowLongA(hWnd, nIndex, dwNewLong)
__EXTERN INTEGER __STDCALL SetWindowLongW(LONGINT hWnd, INTEGER nIndex, INTEGER dwNewLong);
#define WinAPI_SetWindowLongW(hWnd, nIndex, dwNewLong)	SetWindowLongW(hWnd, nIndex, dwNewLong)
__EXTERN INTEGER __STDCALL SetWindowOrgEx(LONGINT p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_SetWindowOrgEx(p0, p1, p2, p3)	SetWindowOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL SetWindowPlacement(LONGINT hWnd, WinAPI_WINDOWPLACEMENT *lpwndpl);
#define WinAPI_SetWindowPlacement(hWnd, lpwndpl)	SetWindowPlacement(hWnd, lpwndpl)
__EXTERN INTEGER __STDCALL SetWindowPos(LONGINT hWnd, LONGINT hWndInsertAfter, INTEGER X, INTEGER Y, INTEGER cx, INTEGER cy, SET uFlags);
#define WinAPI_SetWindowPos(hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags)	SetWindowPos(hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags)
__EXTERN INTEGER __STDCALL SetWindowRgn(LONGINT hWnd, LONGINT hRgn, INTEGER bRedraw);
#define WinAPI_SetWindowRgn(hWnd, hRgn, bRedraw)	SetWindowRgn(hWnd, hRgn, bRedraw)
#define WinAPI_SetWindowText(hWnd, lpString)	SetWindowTextA(hWnd, lpString)
__EXTERN INTEGER __STDCALL SetWindowTextA(LONGINT hWnd, LONGINT lpString);
#define WinAPI_SetWindowTextA(hWnd, lpString)	SetWindowTextA(hWnd, lpString)
__EXTERN INTEGER __STDCALL SetWindowTextW(LONGINT hWnd, LONGINT lpString);
#define WinAPI_SetWindowTextW(hWnd, lpString)	SetWindowTextW(hWnd, lpString)
__EXTERN SHORTINT __STDCALL SetWindowWord(LONGINT hWnd, INTEGER nIndex, SHORTINT wNewWord);
#define WinAPI_SetWindowWord(hWnd, nIndex, wNewWord)	SetWindowWord(hWnd, nIndex, wNewWord)
#define WinAPI_SetWindowsHook(nFilterType, pfnFilterProc)	SetWindowsHookA(nFilterType, pfnFilterProc)
__EXTERN WinAPI_HOOKPROC __STDCALL SetWindowsHookA(INTEGER nFilterType, WinAPI_HOOKPROC pfnFilterProc);
#define WinAPI_SetWindowsHookA(nFilterType, pfnFilterProc)	SetWindowsHookA(nFilterType, pfnFilterProc)
#define WinAPI_SetWindowsHookEx(idHook, lpfn, hmod, dwThreadId)	SetWindowsHookExA(idHook, lpfn, hmod, dwThreadId)
__EXTERN LONGINT __STDCALL SetWindowsHookExA(INTEGER idHook, WinAPI_HOOKPROC lpfn, LONGINT hmod, INTEGER dwThreadId);
#define WinAPI_SetWindowsHookExA(idHook, lpfn, hmod, dwThreadId)	SetWindowsHookExA(idHook, lpfn, hmod, dwThreadId)
__EXTERN LONGINT __STDCALL SetWindowsHookExW(INTEGER idHook, WinAPI_HOOKPROC lpfn, LONGINT hmod, INTEGER dwThreadId);
#define WinAPI_SetWindowsHookExW(idHook, lpfn, hmod, dwThreadId)	SetWindowsHookExW(idHook, lpfn, hmod, dwThreadId)
__EXTERN WinAPI_HOOKPROC __STDCALL SetWindowsHookW(INTEGER nFilterType, WinAPI_HOOKPROC pfnFilterProc);
#define WinAPI_SetWindowsHookW(nFilterType, pfnFilterProc)	SetWindowsHookW(nFilterType, pfnFilterProc)
__EXTERN INTEGER __STDCALL SetWorldTransform(LONGINT p0, WinAPI_XFORM *p1);
#define WinAPI_SetWorldTransform(p0, p1)	SetWorldTransform(p0, p1)
__EXTERN INTEGER __STDCALL SetupComm(LONGINT hFile, INTEGER dwInQueue, INTEGER dwOutQueue);
#define WinAPI_SetupComm(hFile, dwInQueue, dwOutQueue)	SetupComm(hFile, dwInQueue, dwOutQueue)
#define WinAPI_ShellAbout(hWnd, szApp, szOtherStuff, hIcon)	ShellAboutA(hWnd, szApp, szOtherStuff, hIcon)
__EXTERN INTEGER __STDCALL ShellAboutA(LONGINT hWnd, LONGINT szApp, LONGINT szOtherStuff, LONGINT hIcon);
#define WinAPI_ShellAboutA(hWnd, szApp, szOtherStuff, hIcon)	ShellAboutA(hWnd, szApp, szOtherStuff, hIcon)
__EXTERN INTEGER __STDCALL ShellAboutW(LONGINT hWnd, LONGINT szApp, LONGINT szOtherStuff, LONGINT hIcon);
#define WinAPI_ShellAboutW(hWnd, szApp, szOtherStuff, hIcon)	ShellAboutW(hWnd, szApp, szOtherStuff, hIcon)
#define WinAPI_ShellExecute(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)	ShellExecuteA(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)
__EXTERN LONGINT __STDCALL ShellExecuteA(LONGINT hwnd, LONGINT lpOperation, LONGINT lpFile, LONGINT lpParameters, LONGINT lpDirectory, INTEGER nShowCmd);
#define WinAPI_ShellExecuteA(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)	ShellExecuteA(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)
#define WinAPI_ShellExecuteEx(lpExecInfo)	ShellExecuteExA(lpExecInfo)
__EXTERN INTEGER __STDCALL ShellExecuteExA(WinAPI_SHELLEXECUTEINFOA *lpExecInfo);
#define WinAPI_ShellExecuteExA(lpExecInfo)	ShellExecuteExA(lpExecInfo)
__EXTERN INTEGER __STDCALL ShellExecuteExW(WinAPI_SHELLEXECUTEINFOW *lpExecInfo);
#define WinAPI_ShellExecuteExW(lpExecInfo)	ShellExecuteExW(lpExecInfo)
__EXTERN LONGINT __STDCALL ShellExecuteW(LONGINT hwnd, LONGINT lpOperation, LONGINT lpFile, LONGINT lpParameters, LONGINT lpDirectory, INTEGER nShowCmd);
#define WinAPI_ShellExecuteW(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)	ShellExecuteW(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)
#define WinAPI_Shell_NotifyIcon(dwMessage, lpData)	Shell_NotifyIconA(dwMessage, lpData)
__EXTERN INTEGER __STDCALL Shell_NotifyIconA(INTEGER dwMessage, WinAPI_NOTIFYICONDATAA *lpData);
#define WinAPI_Shell_NotifyIconA(dwMessage, lpData)	Shell_NotifyIconA(dwMessage, lpData)
__EXTERN INTEGER __STDCALL Shell_NotifyIconW(INTEGER dwMessage, WinAPI_NOTIFYICONDATAW *lpData);
#define WinAPI_Shell_NotifyIconW(dwMessage, lpData)	Shell_NotifyIconW(dwMessage, lpData)
__EXTERN INTEGER __STDCALL ShowCaret(LONGINT hWnd);
#define WinAPI_ShowCaret(hWnd)	ShowCaret(hWnd)
__EXTERN INTEGER __STDCALL ShowCursor(INTEGER bShow);
#define WinAPI_ShowCursor(bShow)	ShowCursor(bShow)
__EXTERN INTEGER __STDCALL ShowOwnedPopups(LONGINT hWnd, INTEGER fShow);
#define WinAPI_ShowOwnedPopups(hWnd, fShow)	ShowOwnedPopups(hWnd, fShow)
__EXTERN INTEGER __STDCALL ShowScrollBar(LONGINT hWnd, INTEGER wBar, INTEGER bShow);
#define WinAPI_ShowScrollBar(hWnd, wBar, bShow)	ShowScrollBar(hWnd, wBar, bShow)
__EXTERN INTEGER __STDCALL ShowWindow(LONGINT hWnd, INTEGER nCmdShow);
#define WinAPI_ShowWindow(hWnd, nCmdShow)	ShowWindow(hWnd, nCmdShow)
__EXTERN INTEGER __STDCALL ShowWindowAsync(LONGINT hWnd, INTEGER nCmdShow);
#define WinAPI_ShowWindowAsync(hWnd, nCmdShow)	ShowWindowAsync(hWnd, nCmdShow)
__EXTERN INTEGER __STDCALL SignalObjectAndWait(LONGINT hObjectToSignal, LONGINT hObjectToWaitOn, INTEGER dwMilliseconds, INTEGER bAlertable);
#define WinAPI_SignalObjectAndWait(hObjectToSignal, hObjectToWaitOn, dwMilliseconds, bAlertable)	SignalObjectAndWait(hObjectToSignal, hObjectToWaitOn, dwMilliseconds, bAlertable)
__EXTERN INTEGER __STDCALL SizeofResource(LONGINT hModule, LONGINT hResInfo);
#define WinAPI_SizeofResource(hModule, hResInfo)	SizeofResource(hModule, hResInfo)
__EXTERN void __STDCALL Sleep(INTEGER dwMilliseconds);
#define WinAPI_Sleep(dwMilliseconds)	Sleep(dwMilliseconds)
__EXTERN INTEGER __STDCALL SleepEx(INTEGER dwMilliseconds, INTEGER bAlertable);
#define WinAPI_SleepEx(dwMilliseconds, bAlertable)	SleepEx(dwMilliseconds, bAlertable)
#define WinAPI_StartDoc(p0, p1)	StartDocA(p0, p1)
__EXTERN INTEGER __STDCALL StartDocA(LONGINT p0, WinAPI_DOCINFOA *p1);
#define WinAPI_StartDocA(p0, p1)	StartDocA(p0, p1)
#define WinAPI_StartDocPrinter(hPrinter, Level, pDocInfo)	StartDocPrinterA(hPrinter, Level, pDocInfo)
__EXTERN INTEGER __STDCALL StartDocPrinterA(LONGINT hPrinter, INTEGER Level, CHAR *pDocInfo);
#define WinAPI_StartDocPrinterA(hPrinter, Level, pDocInfo)	StartDocPrinterA(hPrinter, Level, pDocInfo)
__EXTERN INTEGER __STDCALL StartDocPrinterW(LONGINT hPrinter, INTEGER Level, CHAR *pDocInfo);
#define WinAPI_StartDocPrinterW(hPrinter, Level, pDocInfo)	StartDocPrinterW(hPrinter, Level, pDocInfo)
__EXTERN INTEGER __STDCALL StartDocW(LONGINT p0, WinAPI_DOCINFOW *p1);
#define WinAPI_StartDocW(p0, p1)	StartDocW(p0, p1)
__EXTERN INTEGER __STDCALL StartPage(LONGINT p0);
#define WinAPI_StartPage(p0)	StartPage(p0)
__EXTERN INTEGER __STDCALL StartPagePrinter(LONGINT hPrinter);
#define WinAPI_StartPagePrinter(hPrinter)	StartPagePrinter(hPrinter)
#define WinAPI_StartService(hService, dwNumServiceArgs, lpServiceArgVectors)	StartServiceA(hService, dwNumServiceArgs, lpServiceArgVectors)
__EXTERN INTEGER __STDCALL StartServiceA(LONGINT hService, INTEGER dwNumServiceArgs, LONGINT *lpServiceArgVectors);
#define WinAPI_StartServiceA(hService, dwNumServiceArgs, lpServiceArgVectors)	StartServiceA(hService, dwNumServiceArgs, lpServiceArgVectors)
#define WinAPI_StartServiceCtrlDispatcher(lpServiceStartTable)	StartServiceCtrlDispatcherA(lpServiceStartTable)
__EXTERN INTEGER __STDCALL StartServiceCtrlDispatcherA(WinAPI_SERVICE_TABLE_ENTRYA *lpServiceStartTable);
#define WinAPI_StartServiceCtrlDispatcherA(lpServiceStartTable)	StartServiceCtrlDispatcherA(lpServiceStartTable)
__EXTERN INTEGER __STDCALL StartServiceCtrlDispatcherW(WinAPI_SERVICE_TABLE_ENTRYW *lpServiceStartTable);
#define WinAPI_StartServiceCtrlDispatcherW(lpServiceStartTable)	StartServiceCtrlDispatcherW(lpServiceStartTable)
__EXTERN INTEGER __STDCALL StartServiceW(LONGINT hService, INTEGER dwNumServiceArgs, LONGINT lpServiceArgVectors);
#define WinAPI_StartServiceW(hService, dwNumServiceArgs, lpServiceArgVectors)	StartServiceW(hService, dwNumServiceArgs, lpServiceArgVectors)
__EXTERN INTEGER __STDCALL StretchBlt(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, LONGINT p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10);
#define WinAPI_StretchBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10)	StretchBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10)
__EXTERN INTEGER __STDCALL StretchDIBits(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, LONGINT p9, WinAPI_BITMAPINFO *p10, INTEGER p11, INTEGER p12);
#define WinAPI_StretchDIBits(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)	StretchDIBits(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)
__EXTERN INTEGER __STDCALL StrokeAndFillPath(LONGINT p0);
#define WinAPI_StrokeAndFillPath(p0)	StrokeAndFillPath(p0)
__EXTERN INTEGER __STDCALL StrokePath(LONGINT p0);
#define WinAPI_StrokePath(p0)	StrokePath(p0)
__EXTERN INTEGER __STDCALL SubtractRect(WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc1, WinAPI_RECT *lprcSrc2);
#define WinAPI_SubtractRect(lprcDst, lprcSrc1, lprcSrc2)	SubtractRect(lprcDst, lprcSrc1, lprcSrc2)
__EXTERN INTEGER __STDCALL SuspendThread(LONGINT hThread);
#define WinAPI_SuspendThread(hThread)	SuspendThread(hThread)
__EXTERN INTEGER __STDCALL SwapBuffers(LONGINT p0);
#define WinAPI_SwapBuffers(p0)	SwapBuffers(p0)
__EXTERN INTEGER __STDCALL SwapMouseButton(INTEGER fSwap);
#define WinAPI_SwapMouseButton(fSwap)	SwapMouseButton(fSwap)
__EXTERN INTEGER __STDCALL SwitchDesktop(LONGINT hDesktop);
#define WinAPI_SwitchDesktop(hDesktop)	SwitchDesktop(hDesktop)
__EXTERN void __STDCALL SwitchToFiber(LONGINT lpFiber);
#define WinAPI_SwitchToFiber(lpFiber)	SwitchToFiber(lpFiber)
#define WinAPI_SystemParametersInfo(uiAction, uiParam, pvParam, fWinIni)	SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni)
__EXTERN INTEGER __STDCALL SystemParametersInfoA(INTEGER uiAction, INTEGER uiParam, LONGINT pvParam, INTEGER fWinIni);
#define WinAPI_SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni)	SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni)
__EXTERN INTEGER __STDCALL SystemParametersInfoW(INTEGER uiAction, INTEGER uiParam, LONGINT pvParam, INTEGER fWinIni);
#define WinAPI_SystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni)	SystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni)
__EXTERN INTEGER __STDCALL SystemTimeToFileTime(WinAPI_SYSTEMTIME *lpSystemTime, WinAPI_FILETIME *lpFileTime);
#define WinAPI_SystemTimeToFileTime(lpSystemTime, lpFileTime)	SystemTimeToFileTime(lpSystemTime, lpFileTime)
__EXTERN INTEGER __STDCALL SystemTimeToTzSpecificLoc__2059(WinAPI_TIME_ZONE_INFORMATION *lpTimeZoneInformation, WinAPI_SYSTEMTIME *lpUniversalTime, WinAPI_SYSTEMTIME *lpLocalTime);
#define WinAPI_SystemTimeToTzSpecificLoc__2059(lpTimeZoneInformation, lpUniversalTime, lpLocalTime)	SystemTimeToTzSpecificLoc__2059(lpTimeZoneInformation, lpUniversalTime, lpLocalTime)
#define WinAPI_TabbedTextOut(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)	TabbedTextOutA(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)
__EXTERN INTEGER __STDCALL TabbedTextOutA(LONGINT hDC, INTEGER X, INTEGER Y, LONGINT lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions, INTEGER nTabOrigin);
#define WinAPI_TabbedTextOutA(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)	TabbedTextOutA(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)
__EXTERN INTEGER __STDCALL TabbedTextOutW(LONGINT hDC, INTEGER X, INTEGER Y, LONGINT lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions, INTEGER nTabOrigin);
#define WinAPI_TabbedTextOutW(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)	TabbedTextOutW(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)
__EXTERN INTEGER __STDCALL TerminateProcess(LONGINT hProcess, INTEGER uExitCode);
#define WinAPI_TerminateProcess(hProcess, uExitCode)	TerminateProcess(hProcess, uExitCode)
__EXTERN INTEGER __STDCALL TerminateThread(LONGINT hThread, INTEGER dwExitCode);
#define WinAPI_TerminateThread(hThread, dwExitCode)	TerminateThread(hThread, dwExitCode)
#define WinAPI_TextOut(p0, p1, p2, p3, p4)	TextOutA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL TextOutA(LONGINT p0, INTEGER p1, INTEGER p2, LONGINT p3, INTEGER p4);
#define WinAPI_TextOutA(p0, p1, p2, p3, p4)	TextOutA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL TextOutW(LONGINT p0, INTEGER p1, INTEGER p2, LONGINT p3, INTEGER p4);
#define WinAPI_TextOutW(p0, p1, p2, p3, p4)	TextOutW(p0, p1, p2, p3, p4)
__EXTERN SHORTINT __STDCALL TileWindows(LONGINT hwndParent, INTEGER wHow, WinAPI_RECT *lpRect, INTEGER cKids, LONGINT *lpKids);
#define WinAPI_TileWindows(hwndParent, wHow, lpRect, cKids, lpKids)	TileWindows(hwndParent, wHow, lpRect, cKids, lpKids)
__EXTERN INTEGER __STDCALL TlsAlloc(void);
#define WinAPI_TlsAlloc()	TlsAlloc()
__EXTERN INTEGER __STDCALL TlsFree(INTEGER dwTlsIndex);
#define WinAPI_TlsFree(dwTlsIndex)	TlsFree(dwTlsIndex)
__EXTERN LONGINT __STDCALL TlsGetValue(INTEGER dwTlsIndex);
#define WinAPI_TlsGetValue(dwTlsIndex)	TlsGetValue(dwTlsIndex)
__EXTERN INTEGER __STDCALL TlsSetValue(INTEGER dwTlsIndex, LONGINT lpTlsValue);
#define WinAPI_TlsSetValue(dwTlsIndex, lpTlsValue)	TlsSetValue(dwTlsIndex, lpTlsValue)
__EXTERN INTEGER __STDCALL ToAscii(INTEGER uVirtKey, INTEGER uScanCode, CHAR *lpKeyState, SHORTINT *lpChar, SET uFlags);
#define WinAPI_ToAscii(uVirtKey, uScanCode, lpKeyState, lpChar, uFlags)	ToAscii(uVirtKey, uScanCode, lpKeyState, lpChar, uFlags)
__EXTERN INTEGER __STDCALL ToAsciiEx(INTEGER uVirtKey, INTEGER uScanCode, CHAR *lpKeyState, SHORTINT *lpChar, SET uFlags, LONGINT dwhkl);
#define WinAPI_ToAsciiEx(uVirtKey, uScanCode, lpKeyState, lpChar, uFlags, dwhkl)	ToAsciiEx(uVirtKey, uScanCode, lpKeyState, lpChar, uFlags, dwhkl)
__EXTERN INTEGER __STDCALL ToUnicode(INTEGER wVirtKey, INTEGER wScanCode, CHAR *lpKeyState, LONGINT pwszBuff, INTEGER cchBuff, INTEGER wFlags);
#define WinAPI_ToUnicode(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags)	ToUnicode(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags)
__EXTERN INTEGER __STDCALL ToUnicodeEx(INTEGER wVirtKey, INTEGER wScanCode, CHAR *lpKeyState, LONGINT pwszBuff, INTEGER cchBuff, INTEGER wFlags, LONGINT dwhkl);
#define WinAPI_ToUnicodeEx(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags, dwhkl)	ToUnicodeEx(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags, dwhkl)
__EXTERN INTEGER __STDCALL TrackPopupMenu(LONGINT hMenu, SET uFlags, INTEGER x, INTEGER y, INTEGER nReserved, LONGINT hWnd, WinAPI_RECT *prcRect);
#define WinAPI_TrackPopupMenu(hMenu, uFlags, x, y, nReserved, hWnd, prcRect)	TrackPopupMenu(hMenu, uFlags, x, y, nReserved, hWnd, prcRect)
__EXTERN INTEGER __STDCALL TrackPopupMenuEx(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, LONGINT p4, WinAPI_TPMPARAMS *p5);
#define WinAPI_TrackPopupMenuEx(p0, p1, p2, p3, p4, p5)	TrackPopupMenuEx(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __STDCALL TransactNamedPipe(LONGINT hNamedPipe, LONGINT lpInBuffer, INTEGER nInBufferSize, LONGINT lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_TransactNamedPipe(hNamedPipe, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, lpOverlapped)	TransactNamedPipe(hNamedPipe, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, lpOverlapped)
#define WinAPI_TranslateAccelerator(hWnd, hAccTable, lpMsg)	TranslateAcceleratorA(hWnd, hAccTable, lpMsg)
__EXTERN INTEGER __STDCALL TranslateAcceleratorA(LONGINT hWnd, LONGINT hAccTable, WinAPI_MSG *lpMsg);
#define WinAPI_TranslateAcceleratorA(hWnd, hAccTable, lpMsg)	TranslateAcceleratorA(hWnd, hAccTable, lpMsg)
__EXTERN INTEGER __STDCALL TranslateAcceleratorW(LONGINT hWnd, LONGINT hAccTable, WinAPI_MSG *lpMsg);
#define WinAPI_TranslateAcceleratorW(hWnd, hAccTable, lpMsg)	TranslateAcceleratorW(hWnd, hAccTable, lpMsg)
__EXTERN INTEGER __STDCALL TranslateCharsetInfo(INTEGER *lpSrc, WinAPI_CHARSETINFO *lpCs, SET dwFlags);
#define WinAPI_TranslateCharsetInfo(lpSrc, lpCs, dwFlags)	TranslateCharsetInfo(lpSrc, lpCs, dwFlags)
__EXTERN INTEGER __STDCALL TranslateMDISysAccel(LONGINT hWndClient, WinAPI_MSG *lpMsg);
#define WinAPI_TranslateMDISysAccel(hWndClient, lpMsg)	TranslateMDISysAccel(hWndClient, lpMsg)
__EXTERN INTEGER __STDCALL TranslateMessage(WinAPI_MSG *lpMsg);
#define WinAPI_TranslateMessage(lpMsg)	TranslateMessage(lpMsg)
__EXTERN INTEGER __STDCALL TransmitCommChar(LONGINT hFile, CHAR cChar);
#define WinAPI_TransmitCommChar(hFile, cChar)	TransmitCommChar(hFile, cChar)
__EXTERN INTEGER __STDCALL TryEnterCriticalSection(WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinAPI_TryEnterCriticalSection(lpCriticalSection)	TryEnterCriticalSection(lpCriticalSection)
__EXTERN INTEGER __STDCALL UnhandledExceptionFilter(WinAPI_EXCEPTION_POINTERS *ExceptionInfo);
#define WinAPI_UnhandledExceptionFilter(ExceptionInfo)	UnhandledExceptionFilter(ExceptionInfo)
__EXTERN INTEGER __STDCALL UnhookWindowsHook(INTEGER nCode, WinAPI_HOOKPROC pfnFilterProc);
#define WinAPI_UnhookWindowsHook(nCode, pfnFilterProc)	UnhookWindowsHook(nCode, pfnFilterProc)
__EXTERN INTEGER __STDCALL UnhookWindowsHookEx(LONGINT hhk);
#define WinAPI_UnhookWindowsHookEx(hhk)	UnhookWindowsHookEx(hhk)
__EXTERN INTEGER __STDCALL UnionRect(WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc1, WinAPI_RECT *lprcSrc2);
#define WinAPI_UnionRect(lprcDst, lprcSrc1, lprcSrc2)	UnionRect(lprcDst, lprcSrc1, lprcSrc2)
__EXTERN INTEGER __STDCALL UnloadKeyboardLayout(LONGINT hkl);
#define WinAPI_UnloadKeyboardLayout(hkl)	UnloadKeyboardLayout(hkl)
__EXTERN INTEGER __STDCALL UnlockFile(LONGINT hFile, INTEGER dwFileOffsetLow, INTEGER dwFileOffsetHigh, INTEGER nNumberOfBytesToUnlockLow, INTEGER nNumberOfBytesToUnlockHigh);
#define WinAPI_UnlockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh)	UnlockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh)
__EXTERN INTEGER __STDCALL UnlockFileEx(LONGINT hFile, INTEGER dwReserved, INTEGER nNumberOfBytesToUnlockLow, INTEGER nNumberOfBytesToUnlockHigh, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_UnlockFileEx(hFile, dwReserved, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh, lpOverlapped)	UnlockFileEx(hFile, dwReserved, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh, lpOverlapped)
__EXTERN INTEGER __STDCALL UnlockServiceDatabase(LONGINT ScLock);
#define WinAPI_UnlockServiceDatabase(ScLock)	UnlockServiceDatabase(ScLock)
__EXTERN INTEGER __STDCALL UnmapViewOfFile(LONGINT lpBaseAddress);
#define WinAPI_UnmapViewOfFile(lpBaseAddress)	UnmapViewOfFile(lpBaseAddress)
__EXTERN INTEGER __STDCALL UnpackDDElParam(INTEGER msg, INTEGER lParam, INTEGER *puiLo, INTEGER *puiHi);
#define WinAPI_UnpackDDElParam(msg, lParam, puiLo, puiHi)	UnpackDDElParam(msg, lParam, puiLo, puiHi)
__EXTERN INTEGER __STDCALL UnrealizeObject(LONGINT p0);
#define WinAPI_UnrealizeObject(p0)	UnrealizeObject(p0)
#define WinAPI_UnregisterClass(lpClassName, hInstance)	UnregisterClassA(lpClassName, hInstance)
__EXTERN INTEGER __STDCALL UnregisterClassA(LONGINT lpClassName, LONGINT hInstance);
#define WinAPI_UnregisterClassA(lpClassName, hInstance)	UnregisterClassA(lpClassName, hInstance)
__EXTERN INTEGER __STDCALL UnregisterClassW(LONGINT lpClassName, LONGINT hInstance);
#define WinAPI_UnregisterClassW(lpClassName, hInstance)	UnregisterClassW(lpClassName, hInstance)
__EXTERN INTEGER __STDCALL UnregisterHotKey(LONGINT hWnd, INTEGER id);
#define WinAPI_UnregisterHotKey(hWnd, id)	UnregisterHotKey(hWnd, id)
__EXTERN INTEGER __STDCALL UpdateColors(LONGINT p0);
#define WinAPI_UpdateColors(p0)	UpdateColors(p0)
#define WinAPI_UpdateResource(hUpdate, lpType, lpName, wLanguage, lpData, cbData)	UpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cbData)
__EXTERN INTEGER __STDCALL UpdateResourceA(LONGINT hUpdate, LONGINT lpType, LONGINT lpName, SHORTINT wLanguage, LONGINT lpData, INTEGER cbData);
#define WinAPI_UpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cbData)	UpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cbData)
__EXTERN INTEGER __STDCALL UpdateResourceW(LONGINT hUpdate, LONGINT lpType, LONGINT lpName, SHORTINT wLanguage, LONGINT lpData, INTEGER cbData);
#define WinAPI_UpdateResourceW(hUpdate, lpType, lpName, wLanguage, lpData, cbData)	UpdateResourceW(hUpdate, lpType, lpName, wLanguage, lpData, cbData)
__EXTERN INTEGER __STDCALL UpdateWindow(LONGINT hWnd);
#define WinAPI_UpdateWindow(hWnd)	UpdateWindow(hWnd)
__EXTERN INTEGER __STDCALL ValidateRect(LONGINT hWnd, WinAPI_RECT *lpRect);
#define WinAPI_ValidateRect(hWnd, lpRect)	ValidateRect(hWnd, lpRect)
__EXTERN INTEGER __STDCALL ValidateRgn(LONGINT hWnd, LONGINT hRgn);
#define WinAPI_ValidateRgn(hWnd, hRgn)	ValidateRgn(hWnd, hRgn)
#define WinAPI_VerFindFile(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)	VerFindFileA(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)
__EXTERN SET __STDCALL VerFindFileA(SET uFlags, LONGINT szFileName, LONGINT szWinDir, LONGINT szAppDir, LONGINT szCurDir, INTEGER *lpuCurDirLen, LONGINT szDestDir, INTEGER *lpuDestDirLen);
#define WinAPI_VerFindFileA(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)	VerFindFileA(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)
__EXTERN SET __STDCALL VerFindFileW(SET uFlags, LONGINT szFileName, LONGINT szWinDir, LONGINT szAppDir, LONGINT szCurDir, INTEGER *lpuCurDirLen, LONGINT szDestDir, INTEGER *lpuDestDirLen);
#define WinAPI_VerFindFileW(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)	VerFindFileW(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)
#define WinAPI_VerInstallFile(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)	VerInstallFileA(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)
__EXTERN SET __STDCALL VerInstallFileA(SET uFlags, LONGINT szSrcFileName, LONGINT szDestFileName, LONGINT szSrcDir, LONGINT szDestDir, LONGINT szCurDir, LONGINT szTmpFile, INTEGER *lpuTmpFileLen);
#define WinAPI_VerInstallFileA(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)	VerInstallFileA(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)
__EXTERN SET __STDCALL VerInstallFileW(SET uFlags, LONGINT szSrcFileName, LONGINT szDestFileName, LONGINT szSrcDir, LONGINT szDestDir, LONGINT szCurDir, LONGINT szTmpFile, INTEGER *lpuTmpFileLen);
#define WinAPI_VerInstallFileW(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)	VerInstallFileW(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)
#define WinAPI_VerLanguageName(wLang, szLang, nSize)	VerLanguageNameA(wLang, szLang, nSize)
__EXTERN INTEGER __STDCALL VerLanguageNameA(INTEGER wLang, LONGINT szLang, INTEGER nSize);
#define WinAPI_VerLanguageNameA(wLang, szLang, nSize)	VerLanguageNameA(wLang, szLang, nSize)
__EXTERN INTEGER __STDCALL VerLanguageNameW(INTEGER wLang, LONGINT szLang, INTEGER nSize);
#define WinAPI_VerLanguageNameW(wLang, szLang, nSize)	VerLanguageNameW(wLang, szLang, nSize)
#define WinAPI_VerQueryValue(pBlock, lpSubBlock, lplpBuffer, puLen)	VerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen)
__EXTERN INTEGER __STDCALL VerQueryValueA(LONGINT pBlock, LONGINT lpSubBlock, LONGINT lplpBuffer, INTEGER *puLen);
#define WinAPI_VerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen)	VerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen)
__EXTERN INTEGER __STDCALL VerQueryValueW(LONGINT pBlock, LONGINT lpSubBlock, LONGINT lplpBuffer, INTEGER *puLen);
#define WinAPI_VerQueryValueW(pBlock, lpSubBlock, lplpBuffer, puLen)	VerQueryValueW(pBlock, lpSubBlock, lplpBuffer, puLen)
__EXTERN LONGINT __STDCALL VirtualAlloc(LONGINT lpAddress, LONGINT dwSize, SET flAllocationType, SET flProtect);
#define WinAPI_VirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect)	VirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect)
__EXTERN LONGINT __STDCALL VirtualAllocEx(LONGINT hProcess, LONGINT lpAddress, LONGINT dwSize, SET flAllocationType, SET flProtect);
#define WinAPI_VirtualAllocEx(hProcess, lpAddress, dwSize, flAllocationType, flProtect)	VirtualAllocEx(hProcess, lpAddress, dwSize, flAllocationType, flProtect)
__EXTERN INTEGER __STDCALL VirtualFree(LONGINT lpAddress, LONGINT dwSize, SET dwFreeType);
#define WinAPI_VirtualFree(lpAddress, dwSize, dwFreeType)	VirtualFree(lpAddress, dwSize, dwFreeType)
__EXTERN INTEGER __STDCALL VirtualLock(LONGINT lpAddress, LONGINT dwSize);
#define WinAPI_VirtualLock(lpAddress, dwSize)	VirtualLock(lpAddress, dwSize)
__EXTERN INTEGER __STDCALL VirtualProtect(LONGINT lpAddress, LONGINT dwSize, SET flNewProtect, INTEGER *lpflOldProtect);
#define WinAPI_VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect)	VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect)
__EXTERN INTEGER __STDCALL VirtualProtectEx(LONGINT hProcess, LONGINT lpAddress, LONGINT dwSize, SET flNewProtect, INTEGER *lpflOldProtect);
#define WinAPI_VirtualProtectEx(hProcess, lpAddress, dwSize, flNewProtect, lpflOldProtect)	VirtualProtectEx(hProcess, lpAddress, dwSize, flNewProtect, lpflOldProtect)
__EXTERN LONGINT __STDCALL VirtualQuery(LONGINT lpAddress, WinAPI_MEMORY_BASIC_INFORMATION *lpBuffer, LONGINT dwLength);
#define WinAPI_VirtualQuery(lpAddress, lpBuffer, dwLength)	VirtualQuery(lpAddress, lpBuffer, dwLength)
__EXTERN LONGINT __STDCALL VirtualQueryEx(LONGINT hProcess, LONGINT lpAddress, WinAPI_MEMORY_BASIC_INFORMATION *lpBuffer, LONGINT dwLength);
#define WinAPI_VirtualQueryEx(hProcess, lpAddress, lpBuffer, dwLength)	VirtualQueryEx(hProcess, lpAddress, lpBuffer, dwLength)
__EXTERN INTEGER __STDCALL VirtualUnlock(LONGINT lpAddress, LONGINT dwSize);
#define WinAPI_VirtualUnlock(lpAddress, dwSize)	VirtualUnlock(lpAddress, dwSize)
#define WinAPI_VkKeyScan(ch)	VkKeyScanA(ch)
__EXTERN SHORTINT __STDCALL VkKeyScanA(CHAR ch);
#define WinAPI_VkKeyScanA(ch)	VkKeyScanA(ch)
#define WinAPI_VkKeyScanEx(ch, dwhkl)	VkKeyScanExA(ch, dwhkl)
__EXTERN SHORTINT __STDCALL VkKeyScanExA(CHAR ch, LONGINT dwhkl);
#define WinAPI_VkKeyScanExA(ch, dwhkl)	VkKeyScanExA(ch, dwhkl)
__EXTERN SHORTINT __STDCALL VkKeyScanExW(SHORTINT ch, LONGINT dwhkl);
#define WinAPI_VkKeyScanExW(ch, dwhkl)	VkKeyScanExW(ch, dwhkl)
__EXTERN SHORTINT __STDCALL VkKeyScanW(SHORTINT ch);
#define WinAPI_VkKeyScanW(ch)	VkKeyScanW(ch)
__EXTERN INTEGER __STDCALL WaitCommEvent(LONGINT hFile, SET *lpEvtMask, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_WaitCommEvent(hFile, lpEvtMask, lpOverlapped)	WaitCommEvent(hFile, lpEvtMask, lpOverlapped)
__EXTERN INTEGER __STDCALL WaitForDebugEvent(WinAPI_DEBUG_EVENT *lpDebugEvent, INTEGER dwMilliseconds);
#define WinAPI_WaitForDebugEvent(lpDebugEvent, dwMilliseconds)	WaitForDebugEvent(lpDebugEvent, dwMilliseconds)
__EXTERN INTEGER __STDCALL WaitForInputIdle(LONGINT hProcess, INTEGER dwMilliseconds);
#define WinAPI_WaitForInputIdle(hProcess, dwMilliseconds)	WaitForInputIdle(hProcess, dwMilliseconds)
__EXTERN INTEGER __STDCALL WaitForMultipleObjects(INTEGER nCount, LONGINT *lpHandles, INTEGER bWaitAll, INTEGER dwMilliseconds);
#define WinAPI_WaitForMultipleObjects(nCount, lpHandles, bWaitAll, dwMilliseconds)	WaitForMultipleObjects(nCount, lpHandles, bWaitAll, dwMilliseconds)
__EXTERN INTEGER __STDCALL WaitForMultipleObjectsEx(INTEGER nCount, LONGINT *lpHandles, INTEGER bWaitAll, INTEGER dwMilliseconds, INTEGER bAlertable);
#define WinAPI_WaitForMultipleObjectsEx(nCount, lpHandles, bWaitAll, dwMilliseconds, bAlertable)	WaitForMultipleObjectsEx(nCount, lpHandles, bWaitAll, dwMilliseconds, bAlertable)
__EXTERN INTEGER __STDCALL WaitForPrinterChange(LONGINT hPrinter, SET Flags);
#define WinAPI_WaitForPrinterChange(hPrinter, Flags)	WaitForPrinterChange(hPrinter, Flags)
__EXTERN INTEGER __STDCALL WaitForSingleObject(LONGINT hHandle, INTEGER dwMilliseconds);
#define WinAPI_WaitForSingleObject(hHandle, dwMilliseconds)	WaitForSingleObject(hHandle, dwMilliseconds)
__EXTERN INTEGER __STDCALL WaitForSingleObjectEx(LONGINT hHandle, INTEGER dwMilliseconds, INTEGER bAlertable);
#define WinAPI_WaitForSingleObjectEx(hHandle, dwMilliseconds, bAlertable)	WaitForSingleObjectEx(hHandle, dwMilliseconds, bAlertable)
__EXTERN INTEGER __STDCALL WaitMessage(void);
#define WinAPI_WaitMessage()	WaitMessage()
#define WinAPI_WaitNamedPipe(lpNamedPipeName, nTimeOut)	WaitNamedPipeA(lpNamedPipeName, nTimeOut)
__EXTERN INTEGER __STDCALL WaitNamedPipeA(LONGINT lpNamedPipeName, INTEGER nTimeOut);
#define WinAPI_WaitNamedPipeA(lpNamedPipeName, nTimeOut)	WaitNamedPipeA(lpNamedPipeName, nTimeOut)
__EXTERN INTEGER __STDCALL WaitNamedPipeW(LONGINT lpNamedPipeName, INTEGER nTimeOut);
#define WinAPI_WaitNamedPipeW(lpNamedPipeName, nTimeOut)	WaitNamedPipeW(lpNamedPipeName, nTimeOut)
__EXTERN INTEGER __STDCALL WideCharToMultiByte(INTEGER CodePage, SET dwFlags, LONGINT lpWideCharStr, INTEGER cchWideChar, LONGINT lpMultiByteStr, INTEGER cchMultiByte, LONGINT lpDefaultChar, INTEGER *lpUsedDefaultChar);
#define WinAPI_WideCharToMultiByte(CodePage, dwFlags, lpWideCharStr, cchWideChar, lpMultiByteStr, cchMultiByte, lpDefaultChar, lpUsedDefaultChar)	WideCharToMultiByte(CodePage, dwFlags, lpWideCharStr, cchWideChar, lpMultiByteStr, cchMultiByte, lpDefaultChar, lpUsedDefaultChar)
__EXTERN INTEGER __STDCALL WidenPath(LONGINT p0);
#define WinAPI_WidenPath(p0)	WidenPath(p0)
__EXTERN INTEGER __STDCALL WinExec(LONGINT lpCmdLine, INTEGER uCmdShow);
#define WinAPI_WinExec(lpCmdLine, uCmdShow)	WinExec(lpCmdLine, uCmdShow)
#define WinAPI_WinHelp(hWndMain, lpszHelp, uCommand, dwData)	WinHelpA(hWndMain, lpszHelp, uCommand, dwData)
__EXTERN INTEGER __STDCALL WinHelpA(LONGINT hWndMain, LONGINT lpszHelp, INTEGER uCommand, INTEGER dwData);
#define WinAPI_WinHelpA(hWndMain, lpszHelp, uCommand, dwData)	WinHelpA(hWndMain, lpszHelp, uCommand, dwData)
__EXTERN INTEGER __STDCALL WinHelpW(LONGINT hWndMain, LONGINT lpszHelp, INTEGER uCommand, INTEGER dwData);
#define WinAPI_WinHelpW(hWndMain, lpszHelp, uCommand, dwData)	WinHelpW(hWndMain, lpszHelp, uCommand, dwData)
__EXTERN LONGINT __STDCALL WindowFromDC(LONGINT hDC);
#define WinAPI_WindowFromDC(hDC)	WindowFromDC(hDC)
__EXTERN LONGINT __STDCALL WindowFromPoint(WinAPI_POINT *Point);
#define WinAPI_WindowFromPoint(Point)	WindowFromPoint(Point)
#define WinAPI_WriteConsole(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)	WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)
__EXTERN INTEGER __STDCALL WriteConsoleA(LONGINT hConsoleOutput, LONGINT lpBuffer, INTEGER nNumberOfCharsToWrite, INTEGER *lpNumberOfCharsWritten, LONGINT lpReserved);
#define WinAPI_WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)	WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)
#define WinAPI_WriteConsoleInput(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)	WriteConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)
__EXTERN INTEGER __STDCALL WriteConsoleInputA(LONGINT hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsWritten);
#define WinAPI_WriteConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)	WriteConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)
__EXTERN INTEGER __STDCALL WriteConsoleInputW(LONGINT hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsWritten);
#define WinAPI_WriteConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)	WriteConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)
#define WinAPI_WriteConsoleOutput(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)	WriteConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)
__EXTERN INTEGER __STDCALL WriteConsoleOutputA(LONGINT hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD *dwBufferSize, WinAPI_COORD *dwBufferCoord, WinAPI_SMALL_RECT *lpWriteRegion);
#define WinAPI_WriteConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)	WriteConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)
__EXTERN INTEGER __STDCALL WriteConsoleOutputAttribute(LONGINT hConsoleOutput, SHORTINT *lpAttribute, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfAttrsWritten);
#define WinAPI_WriteConsoleOutputAttribute(hConsoleOutput, lpAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten)	WriteConsoleOutputAttribute(hConsoleOutput, lpAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten)
#define WinAPI_WriteConsoleOutputCharacter(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	WriteConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __STDCALL WriteConsoleOutputCharacterA(LONGINT hConsoleOutput, LONGINT lpCharacter, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
#define WinAPI_WriteConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	WriteConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __STDCALL WriteConsoleOutputCharacterW(LONGINT hConsoleOutput, LONGINT lpCharacter, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
#define WinAPI_WriteConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	WriteConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __STDCALL WriteConsoleOutputW(LONGINT hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD *dwBufferSize, WinAPI_COORD *dwBufferCoord, WinAPI_SMALL_RECT *lpWriteRegion);
#define WinAPI_WriteConsoleOutputW(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)	WriteConsoleOutputW(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)
__EXTERN INTEGER __STDCALL WriteConsoleW(LONGINT hConsoleOutput, LONGINT lpBuffer, INTEGER nNumberOfCharsToWrite, INTEGER *lpNumberOfCharsWritten, LONGINT lpReserved);
#define WinAPI_WriteConsoleW(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)	WriteConsoleW(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)
__EXTERN INTEGER __STDCALL WriteFile(LONGINT hFile, LONGINT lpBuffer, INTEGER nNumberOfBytesToWrite, INTEGER *lpNumberOfBytesWritten, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped)	WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped)
__EXTERN INTEGER __STDCALL WriteFileEx(LONGINT hFile, LONGINT lpBuffer, INTEGER nNumberOfBytesToWrite, WinAPI_OVERLAPPED *lpOverlapped, WinAPI_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinAPI_WriteFileEx(hFile, lpBuffer, nNumberOfBytesToWrite, lpOverlapped, lpCompletionRoutine)	WriteFileEx(hFile, lpBuffer, nNumberOfBytesToWrite, lpOverlapped, lpCompletionRoutine)
__EXTERN INTEGER __STDCALL WritePrinter(LONGINT hPrinter, LONGINT pBuf, INTEGER cbBuf, INTEGER *pcWritten);
#define WinAPI_WritePrinter(hPrinter, pBuf, cbBuf, pcWritten)	WritePrinter(hPrinter, pBuf, cbBuf, pcWritten)
#define WinAPI_WritePrivateProfileSection(lpAppName, lpString, lpFileName)	WritePrivateProfileSectionA(lpAppName, lpString, lpFileName)
__EXTERN INTEGER __STDCALL WritePrivateProfileSectionA(LONGINT lpAppName, LONGINT lpString, LONGINT lpFileName);
#define WinAPI_WritePrivateProfileSectionA(lpAppName, lpString, lpFileName)	WritePrivateProfileSectionA(lpAppName, lpString, lpFileName)
__EXTERN INTEGER __STDCALL WritePrivateProfileSectionW(LONGINT lpAppName, LONGINT lpString, LONGINT lpFileName);
#define WinAPI_WritePrivateProfileSectionW(lpAppName, lpString, lpFileName)	WritePrivateProfileSectionW(lpAppName, lpString, lpFileName)
#define WinAPI_WritePrivateProfileString(lpAppName, lpKeyName, lpString, lpFileName)	WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName)
__EXTERN INTEGER __STDCALL WritePrivateProfileStringA(LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpString, LONGINT lpFileName);
#define WinAPI_WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName)	WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName)
__EXTERN INTEGER __STDCALL WritePrivateProfileStringW(LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpString, LONGINT lpFileName);
#define WinAPI_WritePrivateProfileStringW(lpAppName, lpKeyName, lpString, lpFileName)	WritePrivateProfileStringW(lpAppName, lpKeyName, lpString, lpFileName)
#define WinAPI_WritePrivateProfileStruct(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	WritePrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN INTEGER __STDCALL WritePrivateProfileStructA(LONGINT lpszSection, LONGINT lpszKey, LONGINT lpStruct, INTEGER uSizeStruct, LONGINT szFile);
#define WinAPI_WritePrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	WritePrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN INTEGER __STDCALL WritePrivateProfileStructW(LONGINT lpszSection, LONGINT lpszKey, LONGINT lpStruct, INTEGER uSizeStruct, LONGINT szFile);
#define WinAPI_WritePrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	WritePrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN INTEGER __STDCALL WriteProcessMemory(LONGINT hProcess, LONGINT lpBaseAddress, LONGINT lpBuffer, INTEGER nSize, INTEGER *lpNumberOfBytesWritten);
#define WinAPI_WriteProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesWritten)	WriteProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesWritten)
#define WinAPI_WriteProfileSection(lpAppName, lpString)	WriteProfileSectionA(lpAppName, lpString)
__EXTERN INTEGER __STDCALL WriteProfileSectionA(LONGINT lpAppName, LONGINT lpString);
#define WinAPI_WriteProfileSectionA(lpAppName, lpString)	WriteProfileSectionA(lpAppName, lpString)
__EXTERN INTEGER __STDCALL WriteProfileSectionW(LONGINT lpAppName, LONGINT lpString);
#define WinAPI_WriteProfileSectionW(lpAppName, lpString)	WriteProfileSectionW(lpAppName, lpString)
#define WinAPI_WriteProfileString(lpAppName, lpKeyName, lpString)	WriteProfileStringA(lpAppName, lpKeyName, lpString)
__EXTERN INTEGER __STDCALL WriteProfileStringA(LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpString);
#define WinAPI_WriteProfileStringA(lpAppName, lpKeyName, lpString)	WriteProfileStringA(lpAppName, lpKeyName, lpString)
__EXTERN INTEGER __STDCALL WriteProfileStringW(LONGINT lpAppName, LONGINT lpKeyName, LONGINT lpString);
#define WinAPI_WriteProfileStringW(lpAppName, lpKeyName, lpString)	WriteProfileStringW(lpAppName, lpKeyName, lpString)
__EXTERN INTEGER __STDCALL WriteTapemark(LONGINT hDevice, INTEGER dwTapemarkType, INTEGER dwTapemarkCount, INTEGER bImmediate);
#define WinAPI_WriteTapemark(hDevice, dwTapemarkType, dwTapemarkCount, bImmediate)	WriteTapemark(hDevice, dwTapemarkType, dwTapemarkCount, bImmediate)
#define WinApi_ABC__typ NIL
#define WinApi_ABCFLOAT__typ NIL
#define WinApi_ACCEL__typ NIL
#define WinApi_ACCESSTIMEOUT__typ NIL
#define WinApi_ACCESS_ALLOWED_ACE__typ NIL
#define WinApi_ACCESS_DENIED_ACE__typ NIL
#define WinApi_ACE_HEADER__typ NIL
#define WinApi_ACL__typ NIL
#define WinApi_ACL_REVISION_INFORMATION__typ NIL
#define WinApi_ACL_SIZE_INFORMATION__typ NIL
#define WinApi_ADDJOB_INFO_1A__typ NIL
#define WinApi_ADDJOB_INFO_1W__typ NIL
#define WinApi_ANIMATIONINFO__typ NIL
#define WinApi_APPBARDATA__typ NIL
#define WinApi_BITMAP__typ NIL
#define WinApi_BITMAPCOREHEADER__typ NIL
#define WinApi_BITMAPCOREINFO__typ NIL
#define WinApi_BITMAPFILEHEADER__typ NIL
#define WinApi_BITMAPINFO__typ NIL
#define WinApi_BITMAPINFOHEADER__typ NIL
#define WinApi_BITMAPV4HEADER__typ NIL
#define WinApi_BROADCASTSYSMSG__typ NIL
#define WinApi_BY_HANDLE_FILE_INFORMATION__typ NIL
#define WinApi_CBTACTIVATESTRUCT__typ NIL
#define WinApi_CBT_CREATEWNDA__typ NIL
#define WinApi_CBT_CREATEWNDW__typ NIL
#define WinApi_CHARSETINFO__typ NIL
#define WinApi_CHAR_INFO__typ NIL
#define WinApi_CIEXYZ__typ NIL
#define WinApi_CIEXYZTRIPLE__typ NIL
#define WinApi_CLIENTCREATESTRUCT__typ NIL
#define WinApi_COLORADJUSTMENT__typ NIL
#define WinApi_COMMCONFIG__typ NIL
#define WinApi_COMMPROP__typ NIL
#define WinApi_COMMTIMEOUTS__typ NIL
#define WinApi_COMPAREITEMSTRUCT__typ NIL
#define WinApi_COMPOUND_ACCESS_ALLOWED_ACE__typ NIL
#define WinApi_COMSTAT__typ NIL
#define WinApi_COM_GUID__typ NIL
#define WinApi_CONSOLE_CURSOR_INFO__typ NIL
#define WinApi_CONSOLE_SCREEN_BUFFER_INFO__typ NIL
#define WinApi_CONTEXT__typ NIL
#define WinApi_CONVCONTEXT__typ NIL
#define WinApi_CONVINFO__typ NIL
#define WinApi_COORD__typ NIL
#define WinApi_COPYDATASTRUCT__typ NIL
#define WinApi_CPINFO__typ NIL
#define WinApi_CREATESTRUCTA__typ NIL
#define WinApi_CREATESTRUCTW__typ NIL
#define WinApi_CREATE_PROCESS_DEBUG_INFO__typ NIL
#define WinApi_CREATE_THREAD_DEBUG_INFO__typ NIL
#define WinApi_CURRENCYFMTA__typ NIL
#define WinApi_CURRENCYFMTW__typ NIL
#define WinApi_CURSORSHAPE__typ NIL
#define WinApi_CWPRETSTRUCT__typ NIL
#define WinApi_CWPSTRUCT__typ NIL
#define WinApi_DATATYPES_INFO_1A__typ NIL
#define WinApi_DATATYPES_INFO_1W__typ NIL
#define WinApi_DCB__typ NIL
#define WinApi_DDEACK__typ NIL
#define WinApi_DDEADVISE__typ NIL
#define WinApi_DDEDATA__typ NIL
#define WinApi_DDELN__typ NIL
#define WinApi_DDEML_MSG_HOOK_DATA__typ NIL
#define WinApi_DDEPOKE__typ NIL
#define WinApi_DDEUP__typ NIL
#define WinApi_DEBUGHOOKINFO__typ NIL
#define WinApi_DEBUG_EVENT__typ NIL
#define WinApi_DELETEITEMSTRUCT__typ NIL
#define WinApi_DEVMODEA__typ NIL
#define WinApi_DEVMODEW__typ NIL
#define WinApi_DIBSECTION__typ NIL
#define WinApi_DLGITEMTEMPLATE__typ NIL
#define WinApi_DLGTEMPLATE__typ NIL
#define WinApi_DOCINFOA__typ NIL
#define WinApi_DOCINFOW__typ NIL
#define WinApi_DOC_INFO_1A__typ NIL
#define WinApi_DOC_INFO_1W__typ NIL
#define WinApi_DOC_INFO_2A__typ NIL
#define WinApi_DOC_INFO_2W__typ NIL
#define WinApi_DRAGINFOA__typ NIL
#define WinApi_DRAGINFOW__typ NIL
#define WinApi_DRAWITEMSTRUCT__typ NIL
#define WinApi_DRAWTEXTPARAMS__typ NIL
#define WinApi_DRIVER_INFO_1A__typ NIL
#define WinApi_DRIVER_INFO_1W__typ NIL
#define WinApi_DRIVER_INFO_2A__typ NIL
#define WinApi_DRIVER_INFO_2W__typ NIL
#define WinApi_DRIVER_INFO_3A__typ NIL
#define WinApi_DRIVER_INFO_3W__typ NIL
#define WinApi_DROPSTRUCT__typ NIL
#define WinApi_EMR__typ NIL
#define WinApi_EMRABORTPATH__typ NIL
#define WinApi_EMRANGLEARC__typ NIL
#define WinApi_EMRARC__typ NIL
#define WinApi_EMRBITBLT__typ NIL
#define WinApi_EMRCREATEBRUSHINDIRECT__typ NIL
#define WinApi_EMRCREATECOLORSPACE__typ NIL
#define WinApi_EMRCREATEDIBPATTERNBRUSHPT__typ NIL
#define WinApi_EMRCREATEMONOBRUSH__typ NIL
#define WinApi_EMRCREATEPALETTE__typ NIL
#define WinApi_EMRCREATEPEN__typ NIL
#define WinApi_EMRELLIPSE__typ NIL
#define WinApi_EMREOF__typ NIL
#define WinApi_EMREXCLUDECLIPRECT__typ NIL
#define WinApi_EMREXTCREATEFONTINDIRECTW__typ NIL
#define WinApi_EMREXTCREATEPEN__typ NIL
#define WinApi_EMREXTFLOODFILL__typ NIL
#define WinApi_EMREXTSELECTCLIPRGN__typ NIL
#define WinApi_EMREXTTEXTOUTA__typ NIL
#define WinApi_EMRFILLPATH__typ NIL
#define WinApi_EMRFILLRGN__typ NIL
#define WinApi_EMRFORMAT__typ NIL
#define WinApi_EMRFRAMERGN__typ NIL
#define WinApi_EMRGDICOMMENT__typ NIL
#define WinApi_EMRGLSBOUNDEDRECORD__typ NIL
#define WinApi_EMRGLSRECORD__typ NIL
#define WinApi_EMRINVERTRGN__typ NIL
#define WinApi_EMRLINETO__typ NIL
#define WinApi_EMRMASKBLT__typ NIL
#define WinApi_EMRMODIFYWORLDTRANSFORM__typ NIL
#define WinApi_EMROFFSETCLIPRGN__typ NIL
#define WinApi_EMRPIXELFORMAT__typ NIL
#define WinApi_EMRPLGBLT__typ NIL
#define WinApi_EMRPOLYDRAW__typ NIL
#define WinApi_EMRPOLYDRAW16__typ NIL
#define WinApi_EMRPOLYLINE__typ NIL
#define WinApi_EMRPOLYLINE16__typ NIL
#define WinApi_EMRPOLYPOLYLINE__typ NIL
#define WinApi_EMRPOLYPOLYLINE16__typ NIL
#define WinApi_EMRPOLYTEXTOUTA__typ NIL
#define WinApi_EMRRESIZEPALETTE__typ NIL
#define WinApi_EMRRESTOREDC__typ NIL
#define WinApi_EMRROUNDRECT__typ NIL
#define WinApi_EMRSCALEVIEWPORTEXTEX__typ NIL
#define WinApi_EMRSELECTCLIPPATH__typ NIL
#define WinApi_EMRSELECTCOLORSPACE__typ NIL
#define WinApi_EMRSELECTOBJECT__typ NIL
#define WinApi_EMRSELECTPALETTE__typ NIL
#define WinApi_EMRSETARCDIRECTION__typ NIL
#define WinApi_EMRSETBKCOLOR__typ NIL
#define WinApi_EMRSETCOLORADJUSTMENT__typ NIL
#define WinApi_EMRSETDIBITSTODEVICE__typ NIL
#define WinApi_EMRSETMAPPERFLAGS__typ NIL
#define WinApi_EMRSETMITERLIMIT__typ NIL
#define WinApi_EMRSETPALETTEENTRIES__typ NIL
#define WinApi_EMRSETPIXELV__typ NIL
#define WinApi_EMRSETVIEWPORTEXTEX__typ NIL
#define WinApi_EMRSETVIEWPORTORGEX__typ NIL
#define WinApi_EMRSETWORLDTRANSFORM__typ NIL
#define WinApi_EMRSTRETCHBLT__typ NIL
#define WinApi_EMRSTRETCHDIBITS__typ NIL
#define WinApi_EMRTEXT__typ NIL
#define WinApi_ENHMETAHEADER__typ NIL
#define WinApi_ENHMETARECORD__typ NIL
#define WinApi_ENUMLOGFONTA__typ NIL
#define WinApi_ENUMLOGFONTEXA__typ NIL
#define WinApi_ENUMLOGFONTEXW__typ NIL
#define WinApi_ENUMLOGFONTW__typ NIL
#define WinApi_ENUM_SERVICE_STATUSA__typ NIL
#define WinApi_ENUM_SERVICE_STATUSW__typ NIL
#define WinApi_EVENTLOGRECORD__typ NIL
#define WinApi_EVENTMSG__typ NIL
#define WinApi_EXCEPTION_DEBUG_INFO__typ NIL
#define WinApi_EXCEPTION_POINTERS__typ NIL
#define WinApi_EXCEPTION_RECORD__typ NIL
#define WinApi_EXIT_PROCESS_DEBUG_INFO__typ NIL
#define WinApi_EXIT_THREAD_DEBUG_INFO__typ NIL
#define WinApi_EXTLOGFONTA__typ NIL
#define WinApi_EXTLOGFONTW__typ NIL
#define WinApi_EXTLOGPEN__typ NIL
#define WinApi_FILETIME__typ NIL
#define WinApi_FILE_NOTIFY_INFORMATION__typ NIL
#define WinApi_FILTERKEYS__typ NIL
#define WinApi_FIXED__typ NIL
#define WinApi_FLOATING_SAVE_AREA__typ NIL
#define WinApi_FOCUS_EVENT_RECORD__typ NIL
#define WinApi_FONTSIGNATURE__typ NIL
#define WinApi_FORM_INFO_1A__typ NIL
#define WinApi_FORM_INFO_1W__typ NIL
#define WinApi_FPO_DATA__typ NIL
#define WinApi_GCP_RESULTSA__typ NIL
#define WinApi_GCP_RESULTSW__typ NIL
#define WinApi_GENERIC_MAPPING__typ NIL
#define WinApi_GLYPHMETRICS__typ NIL
#define WinApi_GLYPHMETRICSFLOAT__typ NIL
#define WinApi_HANDLETABLE__typ NIL
#define WinApi_HARDWAREHOOKSTRUCT__typ NIL
#define WinApi_HELPINFO__typ NIL
#define WinApi_HELPWININFOA__typ NIL
#define WinApi_HELPWININFOW__typ NIL
#define WinApi_HIGHCONTRASTA__typ NIL
#define WinApi_HIGHCONTRASTW__typ NIL
#define WinApi_HSZPAIR__typ NIL
#define WinApi_HW_PROFILE_INFOA__typ NIL
#define WinApi_HW_PROFILE_INFOW__typ NIL
#define WinApi_ICONINFO__typ NIL
#define WinApi_ICONMETRICSA__typ NIL
#define WinApi_ICONMETRICSW__typ NIL
#define WinApi_IMAGE_ARCHIVE_MEMBER_HEADER__typ NIL
#define WinApi_IMAGE_AUX_SYMBOL__typ NIL
#define WinApi_IMAGE_BASE_RELOCATION__typ NIL
#define WinApi_IMAGE_BOUND_FORWARDER_REF__typ NIL
#define WinApi_IMAGE_BOUND_IMPORT_DESCRIPTOR__typ NIL
#define WinApi_IMAGE_COFF_SYMBOLS_HEADER__typ NIL
#define WinApi_IMAGE_DATA_DIRECTORY__typ NIL
#define WinApi_IMAGE_DEBUG_DIRECTORY__typ NIL
#define WinApi_IMAGE_DEBUG_MISC__typ NIL
#define WinApi_IMAGE_DOS_HEADER__typ NIL
#define WinApi_IMAGE_EXPORT_DIRECTORY__typ NIL
#define WinApi_IMAGE_FILE_HEADER__typ NIL
#define WinApi_IMAGE_FUNCTION_ENTRY__typ NIL
#define WinApi_IMAGE_IMPORT_BY_NAME__typ NIL
#define WinApi_IMAGE_IMPORT_DESCRIPTOR__typ NIL
#define WinApi_IMAGE_LINENUMBER__typ NIL
#define WinApi_IMAGE_LOAD_CONFIG_DIRECTORY__typ NIL
#define WinApi_IMAGE_NT_HEADERS__typ NIL
#define WinApi_IMAGE_OPTIONAL_HEADER__typ NIL
#define WinApi_IMAGE_OS2_HEADER__typ NIL
#define WinApi_IMAGE_RELOCATION__typ NIL
#define WinApi_IMAGE_RESOURCE_DATA_ENTRY__typ NIL
#define WinApi_IMAGE_RESOURCE_DIRECTORY__typ NIL
#define WinApi_IMAGE_RESOURCE_DIRECTORY_ENTRY__typ NIL
#define WinApi_IMAGE_RESOURCE_DIRECTORY_STRING__typ NIL
#define WinApi_IMAGE_RESOURCE_DIR_STRING_U__typ NIL
#define WinApi_IMAGE_ROM_HEADERS__typ NIL
#define WinApi_IMAGE_ROM_OPTIONAL_HEADER__typ NIL
#define WinApi_IMAGE_RUNTIME_FUNCTION_ENTRY__typ NIL
#define WinApi_IMAGE_SECTION_HEADER__typ NIL
#define WinApi_IMAGE_SEPARATE_DEBUG_HEADER__typ NIL
#define WinApi_IMAGE_SYMBOL__typ NIL
#define WinApi_IMAGE_THUNK_DATA__typ NIL
#define WinApi_IMAGE_TLS_DIRECTORY__typ NIL
#define WinApi_IMAGE_VXD_HEADER__typ NIL
#define WinApi_INPUT_RECORD__typ NIL
#define WinApi_JOB_INFO_1A__typ NIL
#define WinApi_JOB_INFO_1W__typ NIL
#define WinApi_JOB_INFO_2A__typ NIL
#define WinApi_JOB_INFO_2W__typ NIL
#define WinApi_KERNINGPAIR__typ NIL
#define WinApi_KEY_EVENT_RECORD__typ NIL
#define WinApi_LAYERPLANEDESCRIPTOR__typ NIL
#define WinApi_LDT_ENTRY__typ NIL
#define WinApi_LIST_ENTRY__typ NIL
#define WinApi_LOAD_DLL_DEBUG_INFO__typ NIL
#define WinApi_LOCALESIGNATURE__typ NIL
#define WinApi_LOGBRUSH__typ NIL
#define WinApi_LOGCOLORSPACEA__typ NIL
#define WinApi_LOGCOLORSPACEW__typ NIL
#define WinApi_LOGFONTA__typ NIL
#define WinApi_LOGFONTW__typ NIL
#define WinApi_LOGPALETTE__typ NIL
#define WinApi_LOGPEN__typ NIL
#define WinApi_LUID_AND_ATTRIBUTES__typ NIL
#define WinApi_MAT2__typ NIL
#define WinApi_MDICREATESTRUCTA__typ NIL
#define WinApi_MDICREATESTRUCTW__typ NIL
#define WinApi_MDINEXTMENU__typ NIL
#define WinApi_MEASUREITEMSTRUCT__typ NIL
#define WinApi_MEMORYSTATUS__typ NIL
#define WinApi_MEMORY_BASIC_INFORMATION__typ NIL
#define WinApi_MENUITEMINFOA__typ NIL
#define WinApi_MENUITEMINFOW__typ NIL
#define WinApi_MENUITEMTEMPLATE__typ NIL
#define WinApi_MENUITEMTEMPLATEHEADER__typ NIL
#define WinApi_MENUTEMPLATE__typ NIL
#define WinApi_MENUTEMPLATEA__typ NIL
#define WinApi_MENUTEMPLATEW__typ NIL
#define WinApi_MENU_EVENT_RECORD__typ NIL
#define WinApi_MESSAGE_RESOURCE_BLOCK__typ NIL
#define WinApi_MESSAGE_RESOURCE_DATA__typ NIL
#define WinApi_MESSAGE_RESOURCE_ENTRY__typ NIL
#define WinApi_METAFILEPICT__typ NIL
#define WinApi_METAHEADER__typ NIL
#define WinApi_METARECORD__typ NIL
#define WinApi_MINIMIZEDMETRICS__typ NIL
#define WinApi_MINMAXINFO__typ NIL
#define WinApi_MODEMDEVCAPS__typ NIL
#define WinApi_MODEMSETTINGS__typ NIL
#define WinApi_MONCBSTRUCT__typ NIL
#define WinApi_MONCONVSTRUCT__typ NIL
#define WinApi_MONERRSTRUCT__typ NIL
#define WinApi_MONHSZSTRUCTA__typ NIL
#define WinApi_MONHSZSTRUCTW__typ NIL
#define WinApi_MONITOR_INFO_1A__typ NIL
#define WinApi_MONITOR_INFO_1W__typ NIL
#define WinApi_MONITOR_INFO_2A__typ NIL
#define WinApi_MONITOR_INFO_2W__typ NIL
#define WinApi_MONLINKSTRUCT__typ NIL
#define WinApi_MONMSGSTRUCT__typ NIL
#define WinApi_MOUSEHOOKSTRUCT__typ NIL
#define WinApi_MOUSEKEYS__typ NIL
#define WinApi_MOUSE_EVENT_RECORD__typ NIL
#define WinApi_MSG__typ NIL
#define WinApi_MSGBOXPARAMSA__typ NIL
#define WinApi_MSGBOXPARAMSW__typ NIL
#define WinApi_MULTIKEYHELPA__typ NIL
#define WinApi_MULTIKEYHELPW__typ NIL
#define WinApi_NCCALCSIZE_PARAMS__typ NIL
#define WinApi_NEWTEXTMETRICA__typ NIL
#define WinApi_NEWTEXTMETRICEXA__typ NIL
#define WinApi_NEWTEXTMETRICEXW__typ NIL
#define WinApi_NEWTEXTMETRICW__typ NIL
#define WinApi_NMHDR__typ NIL
#define WinApi_NONCLIENTMETRICSA__typ NIL
#define WinApi_NONCLIENTMETRICSW__typ NIL
#define WinApi_NOTIFYICONDATAA__typ NIL
#define WinApi_NOTIFYICONDATAW__typ NIL
#define WinApi_NT_TIB__typ NIL
#define WinApi_NUMBERFMTA__typ NIL
#define WinApi_NUMBERFMTW__typ NIL
#define WinApi_OBJECTID__typ NIL
#define WinApi_OFSTRUCT__typ NIL
#define WinApi_OSVERSIONINFOA__typ NIL
#define WinApi_OSVERSIONINFOW__typ NIL
#define WinApi_OUTLINETEXTMETRICA__typ NIL
#define WinApi_OUTLINETEXTMETRICW__typ NIL
#define WinApi_OUTPUT_DEBUG_STRING_INFO__typ NIL
#define WinApi_OVERLAPPED__typ NIL
#define WinApi_PAINTSTRUCT__typ NIL
#define WinApi_PALETTEENTRY__typ NIL
#define WinApi_PANOSE__typ NIL
#define WinApi_PELARRAY__typ NIL
#define WinApi_PIXELFORMATDESCRIPTOR__typ NIL
#define WinApi_POINT__typ NIL
#define WinApi_POINTFLOAT__typ NIL
#define WinApi_POINTFX__typ NIL
#define WinApi_POINTS__typ NIL
#define WinApi_POLYTEXTA__typ NIL
#define WinApi_POLYTEXTW__typ NIL
#define WinApi_PORT_INFO_1A__typ NIL
#define WinApi_PORT_INFO_1W__typ NIL
#define WinApi_PORT_INFO_2A__typ NIL
#define WinApi_PORT_INFO_2W__typ NIL
#define WinApi_PRINTER_DEFAULTSA__typ NIL
#define WinApi_PRINTER_DEFAULTSW__typ NIL
#define WinApi_PRINTER_INFO_1A__typ NIL
#define WinApi_PRINTER_INFO_1W__typ NIL
#define WinApi_PRINTER_INFO_2A__typ NIL
#define WinApi_PRINTER_INFO_2W__typ NIL
#define WinApi_PRINTER_INFO_3__typ NIL
#define WinApi_PRINTER_INFO_4A__typ NIL
#define WinApi_PRINTER_INFO_4W__typ NIL
#define WinApi_PRINTER_INFO_5A__typ NIL
#define WinApi_PRINTER_INFO_5W__typ NIL
#define WinApi_PRINTER_INFO_6__typ NIL
#define WinApi_PRINTER_NOTIFY_INFO__typ NIL
#define WinApi_PRINTER_NOTIFY_INFO_DATA__typ NIL
#define WinApi_PRINTER_NOTIFY_OPTIONS__typ NIL
#define WinApi_PRINTER_NOTIFY_OPTIONS_TYPE__typ NIL
#define WinApi_PRINTPROCESSOR_INFO_1A__typ NIL
#define WinApi_PRINTPROCESSOR_INFO_1W__typ NIL
#define WinApi_PRIVILEGE_SET__typ NIL
#define WinApi_PROCESS_HEAP_ENTRY__typ NIL
#define WinApi_PROCESS_INFORMATION__typ NIL
#define WinApi_PROPSHEETHEADERA__typ NIL
#define WinApi_PROPSHEETHEADERW__typ NIL
#define WinApi_PROPSHEETPAGEA__typ NIL
#define WinApi_PROPSHEETPAGEW__typ NIL
#define WinApi_PROVIDOR_INFO_1A__typ NIL
#define WinApi_PROVIDOR_INFO_1W__typ NIL
#define WinApi_PSHNOTIFY__typ NIL
#define WinApi_PVALUEA__typ NIL
#define WinApi_PVALUEW__typ NIL
#define WinApi_QUERY_SERVICE_CONFIGA__typ NIL
#define WinApi_QUERY_SERVICE_CONFIGW__typ NIL
#define WinApi_QUERY_SERVICE_LOCK_STATUSA__typ NIL
#define WinApi_QUERY_SERVICE_LOCK_STATUSW__typ NIL
#define WinApi_QUOTA_LIMITS__typ NIL
#define WinApi_RASTERIZER_STATUS__typ NIL
#define WinApi_RECT__typ NIL
#define WinApi_REG_PROVIDER__typ NIL
#define WinApi_RGBQUAD__typ NIL
#define WinApi_RGBTRIPLE__typ NIL
#define WinApi_RGNDATA__typ NIL
#define WinApi_RGNDATAHEADER__typ NIL
#define WinApi_RIP_INFO__typ NIL
#define WinApi_RTL_CRITICAL_SECTION__typ NIL
#define WinApi_RTL_CRITICAL_SECTION_DEBUG__typ NIL
#define WinApi_SCROLLINFO__typ NIL
#define WinApi_SECURITY_ATTRIBUTES__typ NIL
#define WinApi_SECURITY_DESCRIPTOR__typ NIL
#define WinApi_SECURITY_QUALITY_OF_SERVICE__typ NIL
#define WinApi_SERIALKEYSA__typ NIL
#define WinApi_SERIALKEYSW__typ NIL
#define WinApi_SERVICE_STATUS__typ NIL
#define WinApi_SERVICE_TABLE_ENTRYA__typ NIL
#define WinApi_SERVICE_TABLE_ENTRYW__typ NIL
#define WinApi_SE_IMPERSONATION_STATE__typ NIL
#define WinApi_SHELLEXECUTEINFOA__typ NIL
#define WinApi_SHELLEXECUTEINFOW__typ NIL
#define WinApi_SHFILEINFOA__typ NIL
#define WinApi_SHFILEINFOW__typ NIL
#define WinApi_SHFILEOPSTRUCTA__typ NIL
#define WinApi_SHFILEOPSTRUCTW__typ NIL
#define WinApi_SHNAMEMAPPINGA__typ NIL
#define WinApi_SHNAMEMAPPINGW__typ NIL
#define WinApi_SID__typ NIL
#define WinApi_SID_AND_ATTRIBUTES__typ NIL
#define WinApi_SID_IDENTIFIER_AUTHORITY__typ NIL
#define WinApi_SINGLE_LIST_ENTRY__typ NIL
#define WinApi_SIZE__typ NIL
#define WinApi_SMALL_RECT__typ NIL
#define WinApi_SOUNDSENTRYA__typ NIL
#define WinApi_SOUNDSENTRYW__typ NIL
#define WinApi_STARTUPINFOA__typ NIL
#define WinApi_STARTUPINFOW__typ NIL
#define WinApi_STICKYKEYS__typ NIL
#define WinApi_STYLESTRUCT__typ NIL
#define WinApi_SYSTEMTIME__typ NIL
#define WinApi_SYSTEM_ALARM_ACE__typ NIL
#define WinApi_SYSTEM_AUDIT_ACE__typ NIL
#define WinApi_SYSTEM_INFO__typ NIL
#define WinApi_SYSTEM_POWER_STATUS__typ NIL
#define WinApi_TAPE_CREATE_PARTITION__typ NIL
#define WinApi_TAPE_ERASE__typ NIL
#define WinApi_TAPE_GET_DRIVE_PARAMETERS__typ NIL
#define WinApi_TAPE_GET_MEDIA_PARAMETERS__typ NIL
#define WinApi_TAPE_GET_POSITION__typ NIL
#define WinApi_TAPE_PREPARE__typ NIL
#define WinApi_TAPE_SET_DRIVE_PARAMETERS__typ NIL
#define WinApi_TAPE_SET_MEDIA_PARAMETERS__typ NIL
#define WinApi_TAPE_SET_POSITION__typ NIL
#define WinApi_TAPE_WRITE_MARKS__typ NIL
#define WinApi_TEXTMETRICA__typ NIL
#define WinApi_TEXTMETRICW__typ NIL
#define WinApi_TIME_ZONE_INFORMATION__typ NIL
#define WinApi_TOGGLEKEYS__typ NIL
#define WinApi_TOKEN_CONTROL__typ NIL
#define WinApi_TOKEN_DEFAULT_DACL__typ NIL
#define WinApi_TOKEN_GROUPS__typ NIL
#define WinApi_TOKEN_OWNER__typ NIL
#define WinApi_TOKEN_PRIMARY_GROUP__typ NIL
#define WinApi_TOKEN_PRIVILEGES__typ NIL
#define WinApi_TOKEN_SOURCE__typ NIL
#define WinApi_TOKEN_STATISTICS__typ NIL
#define WinApi_TOKEN_USER__typ NIL
#define WinApi_TPMPARAMS__typ NIL
#define WinApi_TTPOLYCURVE__typ NIL
#define WinApi_TTPOLYGONHEADER__typ NIL
#define WinApi_UNLOAD_DLL_DEBUG_INFO__typ NIL
#define WinApi_USEROBJECTFLAGS__typ NIL
#define WinApi_VALENTA__typ NIL
#define WinApi_VALENTW__typ NIL
#define WinApi_VS_FIXEDFILEINFO__typ NIL
#define WinApi_WIN32_FILE_ATTRIBUTE_DATA__typ NIL
#define WinApi_WIN32_FIND_DATAA__typ NIL
#define WinApi_WIN32_FIND_DATAW__typ NIL
#define WinApi_WIN32_STREAM_ID__typ NIL
#define WinApi_WINDOWPLACEMENT__typ NIL
#define WinApi_WINDOWPOS__typ NIL
#define WinApi_WINDOW_BUFFER_SIZE_RECORD__typ NIL
#define WinApi_WIN_CERTIFICATE__typ NIL
#define WinApi_WIN_SPUB_TRUSTEDPUB_DATA__typ NIL
#define WinApi_WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT__typ NIL
#define WinApi_WIN_TRUST_ACTDATA_SUBJECT_ONLY__typ NIL
#define WinApi_WIN_TRUST_SUBJECT_FILE__typ NIL
#define WinApi_WNDCLASSA__typ NIL
#define WinApi_WNDCLASSEXA__typ NIL
#define WinApi_WNDCLASSEXW__typ NIL
#define WinApi_WNDCLASSW__typ NIL
#define WinApi_XFORM__typ NIL
#define WinApi__1__typ NIL
#define WinApi__10__typ NIL
#define WinApi__11__typ NIL
#define WinApi__12__typ NIL
#define WinApi__13__typ NIL
#define WinApi__14__typ NIL
#define WinApi__15__typ NIL
#define WinApi__16__typ NIL
#define WinApi__17__typ NIL
#define WinApi__18__typ NIL
#define WinApi__19__typ NIL
#define WinApi__2__typ NIL
#define WinApi__20__typ NIL
#define WinApi__21__typ NIL
#define WinApi__22__typ NIL
#define WinApi__23__typ NIL
#define WinApi__24__typ NIL
#define WinApi__25__typ NIL
#define WinApi__26__typ NIL
#define WinApi__27__typ NIL
#define WinApi__28__typ NIL
#define WinApi__29__typ NIL
#define WinApi__3__typ NIL
#define WinApi__30__typ NIL
#define WinApi__31__typ NIL
#define WinApi__32__typ NIL
#define WinApi__33__typ NIL
#define WinApi__34__typ NIL
#define WinApi__35__typ NIL
#define WinApi__4__typ NIL
#define WinApi__5__typ NIL
#define WinApi__6__typ NIL
#define WinApi__7__typ NIL
#define WinApi__8__typ NIL
#define WinApi__9__typ NIL
#define WinApi__EXCEPTION_REGISTRATION_RECORD__typ NIL
#define WinApi__POINTL__typ NIL
#define WinApi__PSP__typ NIL
#define WinApi__RECTL__typ NIL
#define WinApi_val_context__typ NIL
__EXTERN INTEGER __STDCALL _hread(INTEGER hFile, LONGINT lpBuffer, INTEGER lBytes);
#define WinAPI__hread(hFile, lpBuffer, lBytes)	_hread(hFile, lpBuffer, lBytes)
__EXTERN INTEGER __STDCALL _hwrite(INTEGER hFile, LONGINT lpBuffer, INTEGER lBytes);
#define WinAPI__hwrite(hFile, lpBuffer, lBytes)	_hwrite(hFile, lpBuffer, lBytes)
#define WinAPI__init()	/*-noinit*/
__EXTERN INTEGER __STDCALL _lclose(INTEGER hFile);
#define WinAPI__lclose(hFile)	_lclose(hFile)
__EXTERN INTEGER __STDCALL _lcreat(LONGINT lpPathName, INTEGER iAttribute);
#define WinAPI__lcreat(lpPathName, iAttribute)	_lcreat(lpPathName, iAttribute)
__EXTERN INTEGER __STDCALL _llseek(INTEGER hFile, INTEGER lOffset, INTEGER iOrigin);
#define WinAPI__llseek(hFile, lOffset, iOrigin)	_llseek(hFile, lOffset, iOrigin)
__EXTERN INTEGER __STDCALL _lopen(LONGINT lpPathName, INTEGER iReadWrite);
#define WinAPI__lopen(lpPathName, iReadWrite)	_lopen(lpPathName, iReadWrite)
__EXTERN INTEGER __STDCALL _lread(INTEGER hFile, LONGINT lpBuffer, INTEGER uBytes);
#define WinAPI__lread(hFile, lpBuffer, uBytes)	_lread(hFile, lpBuffer, uBytes)
__EXTERN INTEGER __STDCALL _lwrite(INTEGER hFile, LONGINT lpBuffer, INTEGER uBytes);
#define WinAPI__lwrite(hFile, lpBuffer, uBytes)	_lwrite(hFile, lpBuffer, uBytes)
__EXTERN void __STDCALL keybd_event(CHAR bVk, CHAR bScan, SET dwFlags, INTEGER dwExtraInfo);
#define WinAPI_keybd_event(bVk, bScan, dwFlags, dwExtraInfo)	keybd_event(bVk, bScan, dwFlags, dwExtraInfo)
#define WinAPI_lstrcat(lpString1, lpString2)	lstrcatA(lpString1, lpString2)
__EXTERN LONGINT __STDCALL lstrcatA(LONGINT lpString1, LONGINT lpString2);
#define WinAPI_lstrcatA(lpString1, lpString2)	lstrcatA(lpString1, lpString2)
__EXTERN LONGINT __STDCALL lstrcatW(LONGINT lpString1, LONGINT lpString2);
#define WinAPI_lstrcatW(lpString1, lpString2)	lstrcatW(lpString1, lpString2)
#define WinAPI_lstrcmp(lpString1, lpString2)	lstrcmpA(lpString1, lpString2)
__EXTERN INTEGER __STDCALL lstrcmpA(LONGINT lpString1, LONGINT lpString2);
#define WinAPI_lstrcmpA(lpString1, lpString2)	lstrcmpA(lpString1, lpString2)
__EXTERN INTEGER __STDCALL lstrcmpW(LONGINT lpString1, LONGINT lpString2);
#define WinAPI_lstrcmpW(lpString1, lpString2)	lstrcmpW(lpString1, lpString2)
#define WinAPI_lstrcmpi(lpString1, lpString2)	lstrcmpiA(lpString1, lpString2)
__EXTERN INTEGER __STDCALL lstrcmpiA(LONGINT lpString1, LONGINT lpString2);
#define WinAPI_lstrcmpiA(lpString1, lpString2)	lstrcmpiA(lpString1, lpString2)
__EXTERN INTEGER __STDCALL lstrcmpiW(LONGINT lpString1, LONGINT lpString2);
#define WinAPI_lstrcmpiW(lpString1, lpString2)	lstrcmpiW(lpString1, lpString2)
#define WinAPI_lstrcpy(lpString1, lpString2)	lstrcpyA(lpString1, lpString2)
__EXTERN LONGINT __STDCALL lstrcpyA(LONGINT lpString1, LONGINT lpString2);
#define WinAPI_lstrcpyA(lpString1, lpString2)	lstrcpyA(lpString1, lpString2)
__EXTERN LONGINT __STDCALL lstrcpyW(LONGINT lpString1, LONGINT lpString2);
#define WinAPI_lstrcpyW(lpString1, lpString2)	lstrcpyW(lpString1, lpString2)
#define WinAPI_lstrcpyn(lpString1, lpString2, iMaxLength)	lstrcpynA(lpString1, lpString2, iMaxLength)
__EXTERN LONGINT __STDCALL lstrcpynA(LONGINT lpString1, LONGINT lpString2, INTEGER iMaxLength);
#define WinAPI_lstrcpynA(lpString1, lpString2, iMaxLength)	lstrcpynA(lpString1, lpString2, iMaxLength)
__EXTERN LONGINT __STDCALL lstrcpynW(LONGINT lpString1, LONGINT lpString2, INTEGER iMaxLength);
#define WinAPI_lstrcpynW(lpString1, lpString2, iMaxLength)	lstrcpynW(lpString1, lpString2, iMaxLength)
#define WinAPI_lstrlen(lpString)	lstrlenA(lpString)
__EXTERN INTEGER __STDCALL lstrlenA(LONGINT lpString);
#define WinAPI_lstrlenA(lpString)	lstrlenA(lpString)
__EXTERN INTEGER __STDCALL lstrlenW(LONGINT lpString);
#define WinAPI_lstrlenW(lpString)	lstrlenW(lpString)
__EXTERN void __STDCALL mouse_event(SET dwFlags, INTEGER dx, INTEGER dy, INTEGER cButtons, INTEGER dwExtraInfo);
#define WinAPI_mouse_event(dwFlags, dx, dy, cButtons, dwExtraInfo)	mouse_event(dwFlags, dx, dy, cButtons, dwExtraInfo)
__EXTERN INTEGER __STDCALL wglCopyContext(LONGINT p0, LONGINT p1, INTEGER p2);
#define WinAPI_wglCopyContext(p0, p1, p2)	wglCopyContext(p0, p1, p2)
__EXTERN LONGINT __STDCALL wglCreateContext(LONGINT p0);
#define WinAPI_wglCreateContext(p0)	wglCreateContext(p0)
__EXTERN LONGINT __STDCALL wglCreateLayerContext(LONGINT p0, INTEGER p1);
#define WinAPI_wglCreateLayerContext(p0, p1)	wglCreateLayerContext(p0, p1)
__EXTERN INTEGER __STDCALL wglDeleteContext(LONGINT p0);
#define WinAPI_wglDeleteContext(p0)	wglDeleteContext(p0)
__EXTERN INTEGER __STDCALL wglDescribeLayerPlane(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_LAYERPLANEDESCRIPTOR *p4);
#define WinAPI_wglDescribeLayerPlane(p0, p1, p2, p3, p4)	wglDescribeLayerPlane(p0, p1, p2, p3, p4)
__EXTERN LONGINT __STDCALL wglGetCurrentContext(void);
#define WinAPI_wglGetCurrentContext()	wglGetCurrentContext()
__EXTERN LONGINT __STDCALL wglGetCurrentDC(void);
#define WinAPI_wglGetCurrentDC()	wglGetCurrentDC()
__EXTERN INTEGER __STDCALL wglGetLayerPaletteEntries(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4);
#define WinAPI_wglGetLayerPaletteEntries(p0, p1, p2, p3, p4)	wglGetLayerPaletteEntries(p0, p1, p2, p3, p4)
__EXTERN WinAPI_ROC __STDCALL wglGetProcAddress(LONGINT p0);
#define WinAPI_wglGetProcAddress(p0)	wglGetProcAddress(p0)
__EXTERN INTEGER __STDCALL wglMakeCurrent(LONGINT p0, LONGINT p1);
#define WinAPI_wglMakeCurrent(p0, p1)	wglMakeCurrent(p0, p1)
__EXTERN INTEGER __STDCALL wglRealizeLayerPalette(LONGINT p0, INTEGER p1, INTEGER p2);
#define WinAPI_wglRealizeLayerPalette(p0, p1, p2)	wglRealizeLayerPalette(p0, p1, p2)
__EXTERN INTEGER __STDCALL wglSetLayerPaletteEntries(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4);
#define WinAPI_wglSetLayerPaletteEntries(p0, p1, p2, p3, p4)	wglSetLayerPaletteEntries(p0, p1, p2, p3, p4)
__EXTERN INTEGER __STDCALL wglShareLists(LONGINT p0, LONGINT p1);
#define WinAPI_wglShareLists(p0, p1)	wglShareLists(p0, p1)
__EXTERN INTEGER __STDCALL wglSwapLayerBuffers(LONGINT p0, INTEGER p1);
#define WinAPI_wglSwapLayerBuffers(p0, p1)	wglSwapLayerBuffers(p0, p1)
#define WinAPI_wglUseFontBitmaps(p0, p1, p2, p3)	wglUseFontBitmapsA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL wglUseFontBitmapsA(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_wglUseFontBitmapsA(p0, p1, p2, p3)	wglUseFontBitmapsA(p0, p1, p2, p3)
__EXTERN INTEGER __STDCALL wglUseFontBitmapsW(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_wglUseFontBitmapsW(p0, p1, p2, p3)	wglUseFontBitmapsW(p0, p1, p2, p3)
#define WinAPI_wglUseFontOutlines(p0, p1, p2, p3, p4, p5, p6, p7)	wglUseFontOutlinesA(p0, p1, p2, p3, p4, p5, p6, p7)
__EXTERN INTEGER __STDCALL wglUseFontOutlinesA(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, SHORTREAL p4, SHORTREAL p5, INTEGER p6, WinAPI_GLYPHMETRICSFLOAT *p7);
#define WinAPI_wglUseFontOutlinesA(p0, p1, p2, p3, p4, p5, p6, p7)	wglUseFontOutlinesA(p0, p1, p2, p3, p4, p5, p6, p7)
__EXTERN INTEGER __STDCALL wglUseFontOutlinesW(LONGINT p0, INTEGER p1, INTEGER p2, INTEGER p3, SHORTREAL p4, SHORTREAL p5, INTEGER p6, WinAPI_GLYPHMETRICSFLOAT *p7);
#define WinAPI_wglUseFontOutlinesW(p0, p1, p2, p3, p4, p5, p6, p7)	wglUseFontOutlinesW(p0, p1, p2, p3, p4, p5, p6, p7)
#define WinAPI_wvsprintf(p0, p1, arglist)	wvsprintfA(p0, p1, arglist)
__EXTERN INTEGER __STDCALL wvsprintfA(LONGINT p0, LONGINT p1, LONGINT arglist);
#define WinAPI_wvsprintfA(p0, p1, arglist)	wvsprintfA(p0, p1, arglist)
__EXTERN INTEGER __STDCALL wvsprintfW(LONGINT p0, LONGINT p1, LONGINT arglist);
#define WinAPI_wvsprintfW(p0, p1, arglist)	wvsprintfW(p0, p1, arglist)

#endif

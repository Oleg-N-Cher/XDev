/* Ofront+ 1.0 -sxt3 -48 */

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
	INTEGER FiberData;
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
	INTEGER ForwarderString;
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
		INTEGER ExceptionAddress, NumberParameters;
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
	INTEGER hMem;
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
	INTEGER pszTemplate;
};

struct WinAPI__4 {
	INTEGER hIcon;
};

struct WinAPI__5 {
	INTEGER pszTemplate;
};

struct WinAPI__6 {
	INTEGER hIcon;
};

struct WinAPI__29 {
	INTEGER hIcon;
};

struct WinAPI__30 {
	INTEGER pStartPage;
};

typedef
	struct WinAPI_PROPSHEETPAGEA *WinAPI_PtrPROPSHEETPAGEA;

struct WinAPI__31 {
	WinAPI_PtrPROPSHEETPAGEA ppsp;
};

struct WinAPI__32 {
	INTEGER hIcon;
};

struct WinAPI__33 {
	INTEGER pStartPage;
};

typedef
	struct WinAPI_PROPSHEETPAGEW *WinAPI_PtrPROPSHEETPAGEW;

struct WinAPI__34 {
	WinAPI_PtrPROPSHEETPAGEW ppsp;
};

struct WinAPI__25 {
	INTEGER cbBuf, pBuf;
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
	INTEGER (__STDCALL *WinAPI_ABORTPROC)(INTEGER, INTEGER);

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
		INTEGER Path, JobId;
	} WinAPI_ADDJOB_INFO_1A;

typedef
	struct WinAPI_ADDJOB_INFO_1W {
		INTEGER Path, JobId;
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
		INTEGER cbSize, hWnd, uCallbackMessage, uEdge;
		WinAPI_RECT rc;
		INTEGER lParam;
	} WinAPI_APPBARDATA;

typedef
	struct WinAPI_BITMAP {
		INTEGER bmType, bmWidth, bmHeight, bmWidthBytes;
		SHORTINT bmPlanes, bmBitsPixel;
		INTEGER bmBits;
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
		INTEGER uiMessage, wParam, lParam;
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
		INTEGER fMouse, hWndActive;
	} WinAPI_CBTACTIVATESTRUCT;

typedef
	struct WinAPI_CREATESTRUCTA *WinAPI_PtrCREATESTRUCTA;

typedef
	struct WinAPI_CBT_CREATEWNDA {
		WinAPI_PtrCREATESTRUCTA lpcs;
		INTEGER hwndInsertAfter;
	} WinAPI_CBT_CREATEWNDA;

typedef
	struct WinAPI_CREATESTRUCTW *WinAPI_PtrCREATESTRUCTW;

typedef
	struct WinAPI_CBT_CREATEWNDW {
		WinAPI_PtrCREATESTRUCTW lpcs;
		INTEGER hwndInsertAfter;
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
		INTEGER hWindowMenu, idFirstChild;
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
		INTEGER CtlID, hwndItem, itemID1, itemData1, itemID2, itemData2, dwLocaleId;
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
		INTEGER cb, hUser, hConvPartner, hszSvcPartner, hszServiceReq, hszTopic, hszItem, wFmt, wType;
		SET wStatus;
		INTEGER wConvst, wLastError, hConvList;
		WinAPI_CONVCONTEXT ConvCtxt;
		INTEGER hwnd, hwndPartner;
	} WinAPI_CONVINFO;

typedef
	struct WinAPI_COPYDATASTRUCT {
		INTEGER dwData, cbData, lpData;
	} WinAPI_COPYDATASTRUCT;

typedef
	struct WinAPI_CPINFO {
		INTEGER MaxCharSize;
		CHAR DefaultChar[2];
		CHAR LeadByte[12];
	} WinAPI_CPINFO;

typedef
	struct WinAPI_CREATESTRUCTA {
		INTEGER lpCreateParams, hInstance, hMenu, hwndParent, cy, cx, y, x;
		SET style;
		INTEGER lpszName, lpszClass;
		SET dwExStyle;
	} WinAPI_CREATESTRUCTA;

typedef
	struct WinAPI_CREATESTRUCTW {
		INTEGER lpCreateParams, hInstance, hMenu, hwndParent, cy, cx, y, x;
		SET style;
		INTEGER lpszName, lpszClass;
		SET dwExStyle;
	} WinAPI_CREATESTRUCTW;

typedef
	INTEGER (__STDCALL *WinAPI_THREAD_START_ROUTINE)(INTEGER);

typedef
	struct WinAPI_CREATE_PROCESS_DEBUG_INFO {
		INTEGER hFile, hProcess, hThread, lpBaseOfImage, dwDebugInfoFileOffset, nDebugInfoSize, lpThreadLocalBase;
		WinAPI_THREAD_START_ROUTINE lpStartAddress;
		INTEGER lpImageName;
		SHORTINT fUnicode;
	} WinAPI_CREATE_PROCESS_DEBUG_INFO;

typedef
	struct WinAPI_CREATE_THREAD_DEBUG_INFO {
		INTEGER hThread, lpThreadLocalBase;
		WinAPI_THREAD_START_ROUTINE lpStartAddress;
	} WinAPI_CREATE_THREAD_DEBUG_INFO;

typedef
	struct WinAPI_RTL_CRITICAL_SECTION_DEBUG *WinAPI_PtrRTL_CRITICAL_SECTION_DEBUG;

typedef
	struct WinAPI_RTL_CRITICAL_SECTION {
		WinAPI_PtrRTL_CRITICAL_SECTION_DEBUG DebugInfo;
		INTEGER LockCount, RecursionCount, OwningThread, LockSemaphore, Reserved;
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
		INTEGER NumDigits, LeadingZero, Grouping, lpDecimalSep, lpThousandSep, NegativeOrder, PositiveOrder, lpCurrencySymbol;
	} WinAPI_CURRENCYFMTA;

typedef
	struct WinAPI_CURRENCYFMTW {
		INTEGER NumDigits, LeadingZero, Grouping, lpDecimalSep, lpThousandSep, NegativeOrder, PositiveOrder, lpCurrencySymbol;
	} WinAPI_CURRENCYFMTW;

typedef
	struct WinAPI_CURSORSHAPE {
		INTEGER xHotSpot, yHotSpot, cx, cy, cbWidth;
		CHAR Planes, BitsPixel;
	} WinAPI_CURSORSHAPE;

typedef
	struct WinAPI_CWPRETSTRUCT {
		INTEGER lResult, lParam, wParam, message, hwnd;
	} WinAPI_CWPRETSTRUCT;

typedef
	struct WinAPI_CWPSTRUCT {
		INTEGER lParam, wParam, message, hwnd;
	} WinAPI_CWPSTRUCT;

typedef
	struct WinAPI_DATATYPES_INFO_1A {
		INTEGER pName;
	} WinAPI_DATATYPES_INFO_1A;

typedef
	struct WinAPI_DATATYPES_INFO_1W {
		INTEGER pName;
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
		INTEGER idThread, idThreadInstaller, lParam, wParam, code;
	} WinAPI_DEBUGHOOKINFO;

typedef
	struct WinAPI_DEBUG_EVENT {
		INTEGER dwDebugEventCode, dwProcessId, dwThreadId;
		struct WinAPI__2 u;
	} WinAPI_DEBUG_EVENT;

typedef
	struct WinAPI_DELETEITEMSTRUCT {
		SET CtlType;
		INTEGER CtlID, itemID, hwndItem, itemData;
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
		INTEGER dshSection, dsOffset;
	} WinAPI_DIBSECTION;

typedef
	struct WinAPI_DLGITEMTEMPLATE {
		SET style, dwExtendedStyle;
		SHORTINT x, y, cx, cy, id;
	} WinAPI_DLGITEMTEMPLATE;

typedef
	INTEGER (__STDCALL *WinAPI_DLGPROC)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	struct WinAPI_DLGTEMPLATE {
		SET style, dwExtendedStyle;
		SHORTINT cdit, x, y, cx, cy;
	} WinAPI_DLGTEMPLATE;

typedef
	struct WinAPI_DOCINFOA {
		INTEGER cbSize, lpszDocName, lpszOutput, lpszDatatype, fwType;
	} WinAPI_DOCINFOA;

typedef
	struct WinAPI_DOCINFOW {
		INTEGER cbSize, lpszDocName, lpszOutput, lpszDatatype, fwType;
	} WinAPI_DOCINFOW;

typedef
	struct WinAPI_DOC_INFO_1A {
		INTEGER pDocName, pOutputFile, pDatatype;
	} WinAPI_DOC_INFO_1A;

typedef
	struct WinAPI_DOC_INFO_1W {
		INTEGER pDocName, pOutputFile, pDatatype;
	} WinAPI_DOC_INFO_1W;

typedef
	struct WinAPI_DOC_INFO_2A {
		INTEGER pDocName, pOutputFile, pDatatype;
		SET dwMode;
		INTEGER JobId;
	} WinAPI_DOC_INFO_2A;

typedef
	struct WinAPI_DOC_INFO_2W {
		INTEGER pDocName, pOutputFile, pDatatype;
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
		INTEGER fNC, lpFileList;
		SET grfKeyState;
	} WinAPI_DRAGINFOA;

typedef
	struct WinAPI_DRAGINFOW {
		INTEGER uSize;
		WinAPI_POINT pt;
		INTEGER fNC, lpFileList;
		SET grfKeyState;
	} WinAPI_DRAGINFOW;

typedef
	struct WinAPI_DRAWITEMSTRUCT {
		SET CtlType;
		INTEGER CtlID, itemID;
		SET itemAction, itemState;
		INTEGER hwndItem, hDC;
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
		INTEGER pName;
	} WinAPI_DRIVER_INFO_1A;

typedef
	struct WinAPI_DRIVER_INFO_1W {
		INTEGER pName;
	} WinAPI_DRIVER_INFO_1W;

typedef
	struct WinAPI_DRIVER_INFO_2A {
		INTEGER cVersion, pName, pEnvironment, pDriverPath, pDataFile, pConfigFile;
	} WinAPI_DRIVER_INFO_2A;

typedef
	struct WinAPI_DRIVER_INFO_2W {
		INTEGER cVersion, pName, pEnvironment, pDriverPath, pDataFile, pConfigFile;
	} WinAPI_DRIVER_INFO_2W;

typedef
	struct WinAPI_DRIVER_INFO_3A {
		INTEGER cVersion, pName, pEnvironment, pDriverPath, pDataFile, pConfigFile, pHelpFile, pDependentFiles, pMonitorName, pDefaultDataType;
	} WinAPI_DRIVER_INFO_3A;

typedef
	struct WinAPI_DRIVER_INFO_3W {
		INTEGER cVersion, pName, pEnvironment, pDriverPath, pDataFile, pConfigFile, pHelpFile, pDependentFiles, pMonitorName, pDefaultDataType;
	} WinAPI_DRIVER_INFO_3W;

typedef
	struct WinAPI_DROPSTRUCT {
		INTEGER hwndSource, hwndSink, wFmt, dwData;
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
		INTEGER objectHandle[1];
	} WinAPI_HANDLETABLE;

typedef
	INTEGER (__STDCALL *WinAPI_ENHMFENUMPROC)(INTEGER, WinAPI_HANDLETABLE*, WinAPI_ENHMETARECORD*, INTEGER, INTEGER);

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
		INTEGER lpServiceName, lpDisplayName;
		WinAPI_SERVICE_STATUS ServiceStatus;
	} WinAPI_ENUM_SERVICE_STATUSA;

typedef
	struct WinAPI_ENUM_SERVICE_STATUSW {
		INTEGER lpServiceName, lpDisplayName;
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
		INTEGER message, paramL, paramH, time, hwnd;
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
	void (__STDCALL *WinAPI_FIBER_START_ROUTINE)(INTEGER);

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
	INTEGER (__STDCALL *WinAPI_FNADDPROPSHEETPAGE)(WinAPI_Ptr_PSP, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_FNADDPROPSHEETPAGES)(INTEGER, WinAPI_FNADDPROPSHEETPAGE, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_FNCALLBACK)(INTEGER, INTEGER, INTEGER, INTEGER, INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_FNDEVCAPS)(INTEGER, INTEGER, INTEGER, INTEGER, WinAPI_DEVMODEA*);

typedef
	INTEGER (__STDCALL *WinAPI_FNDEVMODE)(INTEGER, INTEGER, WinAPI_DEVMODEA*, INTEGER, INTEGER, WinAPI_DEVMODEA*, INTEGER, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_FNPROPSHEETCALLBACK)(INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_FNPSPCALLBACKA)(INTEGER, INTEGER, WinAPI_PtrPROPSHEETPAGEA);

typedef
	INTEGER (__STDCALL *WinAPI_FNPSPCALLBACKW)(INTEGER, INTEGER, WinAPI_PtrPROPSHEETPAGEW);

typedef
	struct WinAPI_FOCUS_EVENT_RECORD {
		INTEGER bSetFocus;
	} WinAPI_FOCUS_EVENT_RECORD;

typedef
	INTEGER (__STDCALL *WinAPI_FONTENUMPROC)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_FONTENUMPROCA)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_FONTENUMPROCEX)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_FONTENUMPROCEXA)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_FONTENUMPROCEXW)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_FONTENUMPROCW)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	struct WinAPI_FORM_INFO_1A {
		SET Flags;
		INTEGER pName;
		WinAPI_SIZE Size;
		WinAPI_RECT ImageableArea;
	} WinAPI_FORM_INFO_1A;

typedef
	struct WinAPI_FORM_INFO_1W {
		SET Flags;
		INTEGER pName;
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
		INTEGER lStructSize, lpOutString, lpOrder, lpDx, lpCaretPos, lpClass, lpGlyphs, nGlyphs, nMaxFit;
	} WinAPI_GCP_RESULTSA;

typedef
	struct WinAPI_GCP_RESULTSW {
		INTEGER lStructSize, lpOutString, lpOrder, lpDx, lpCaretPos, lpClass, lpGlyphs, nGlyphs, nMaxFit;
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
		INTEGER hwnd, message, wParam, lParam;
	} WinAPI_HARDWAREHOOKSTRUCT;

typedef
	struct WinAPI_HELPINFO {
		INTEGER cbSize, iContextType, iCtrlId, hItemHandle, dwContextId;
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
		INTEGER lpszDefaultScheme;
	} WinAPI_HIGHCONTRASTA;

typedef
	struct WinAPI_HIGHCONTRASTW {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER lpszDefaultScheme;
	} WinAPI_HIGHCONTRASTW;

typedef
	INTEGER (__STDCALL *WinAPI_HOOKPROC)(void);

typedef
	struct WinAPI_HSZPAIR {
		INTEGER hszSvc, hszTopic;
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
	INTEGER (__STDCALL *WinAPI_ICMENUMPROCA)(INTEGER, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_ICMENUMPROCW)(INTEGER, INTEGER);

typedef
	struct WinAPI_ICONINFO {
		INTEGER fIcon, xHotspot, yHotspot, hbmMask, hbmColor;
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
		INTEGER Name, Base, NumberOfFunctions, NumberOfNames, AddressOfFunctions, AddressOfNames, AddressOfNameOrdinals;
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
		INTEGER GlobalFlagsClear, GlobalFlagsSet, CriticalSectionDefaultTimeout, DeCommitFreeBlockThreshold, DeCommitTotalFreeThreshold, LockPrefixTable, MaximumAllocationSize, VirtualMemoryThreshold, ProcessHeapFlags;
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
		INTEGER BeginAddress, EndAddress, ExceptionHandler, HandlerData, PrologEndAddress;
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
	void (__STDCALL *WinAPI_IMAGE_TLS_CALLBACK)(INTEGER, INTEGER, INTEGER);

typedef
	struct WinAPI_IMAGE_TLS_DIRECTORY {
		INTEGER StartAddressOfRawData, EndAddressOfRawData, AddressOfIndex, AddressOfCallBacks, SizeOfZeroFill, Characteristics;
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
		INTEGER JobId, pPrinterName, pMachineName, pUserName, pDocument, pDatatype, pStatus;
		SET Status;
		INTEGER Priority, Position, TotalPages, PagesPrinted;
		WinAPI_SYSTEMTIME Submitted;
	} WinAPI_JOB_INFO_1A;

typedef
	struct WinAPI_JOB_INFO_1W {
		INTEGER JobId, pPrinterName, pMachineName, pUserName, pDocument, pDatatype, pStatus;
		SET Status;
		INTEGER Priority, Position, TotalPages, PagesPrinted;
		WinAPI_SYSTEMTIME Submitted;
	} WinAPI_JOB_INFO_1W;

typedef
	WinAPI_DEVMODEA *WinAPI_PtrDEVMODEA;

typedef
	struct WinAPI_JOB_INFO_2A {
		INTEGER JobId, pPrinterName, pMachineName, pUserName, pDocument, pNotifyName, pDatatype, pPrintProcessor, pParameters, pDriverName;
		WinAPI_PtrDEVMODEA pDevMode;
		INTEGER pStatus, pSecurityDescriptor;
		SET Status;
		INTEGER Priority, Position, StartTime, UntilTime, TotalPages, Size;
		WinAPI_SYSTEMTIME Submitted;
		INTEGER Time, PagesPrinted;
	} WinAPI_JOB_INFO_2A;

typedef
	WinAPI_DEVMODEW *WinAPI_PtrDEVMODEW;

typedef
	struct WinAPI_JOB_INFO_2W {
		INTEGER JobId, pPrinterName, pMachineName, pUserName, pDocument, pNotifyName, pDatatype, pPrintProcessor, pParameters, pDriverName;
		WinAPI_PtrDEVMODEW pDevMode;
		INTEGER pStatus, pSecurityDescriptor;
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
		INTEGER hFile, lpBaseOfDll, dwDebugInfoFileOffset, nDebugInfoSize, lpImageName;
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
		INTEGER szClass, szTitle, hOwner, x, y, cx, cy;
		SET style;
		INTEGER lParam;
	} WinAPI_MDICREATESTRUCTA;

typedef
	struct WinAPI_MDICREATESTRUCTW {
		INTEGER szClass, szTitle, hOwner, x, y, cx, cy;
		SET style;
		INTEGER lParam;
	} WinAPI_MDICREATESTRUCTW;

typedef
	struct WinAPI_MDINEXTMENU {
		INTEGER hmenuIn, hmenuNext, hwndNext;
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
		INTEGER BaseAddress, AllocationBase, AllocationProtect, RegionSize, State, Protect, Type;
	} WinAPI_MEMORY_BASIC_INFORMATION;

typedef
	struct WinAPI_MENUITEMINFOA {
		INTEGER cbSize;
		SET fMask, fType, fState;
		INTEGER wID, hSubMenu, hbmpChecked, hbmpUnchecked, dwItemData, dwTypeData, cch;
	} WinAPI_MENUITEMINFOA;

typedef
	struct WinAPI_MENUITEMINFOW {
		INTEGER cbSize;
		SET fMask, fType, fState;
		INTEGER wID, hSubMenu, hbmpChecked, hbmpUnchecked, dwItemData, dwTypeData, cch;
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
		INTEGER mm, xExt, yExt, hMF;
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
	INTEGER (__STDCALL *WinAPI_MFENUMPROC)(INTEGER, WinAPI_HANDLETABLE*, WinAPI_METARECORD*, INTEGER, INTEGER);

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
		INTEGER cb, dwTime, hTask, dwRet, wType, wFmt, hConv, hsz1, hsz2, hData, dwData1, dwData2;
		WinAPI_CONVCONTEXT cc;
		INTEGER cbData;
		INTEGER Data[8];
	} WinAPI_MONCBSTRUCT;

typedef
	struct WinAPI_MONCONVSTRUCT {
		INTEGER cb, fConnect, dwTime, hTask, hszSvc, hszTopic, hConvClient, hConvServer;
	} WinAPI_MONCONVSTRUCT;

typedef
	struct WinAPI_MONERRSTRUCT {
		INTEGER cb, wLastError, dwTime, hTask;
	} WinAPI_MONERRSTRUCT;

typedef
	struct WinAPI_MONHSZSTRUCTA {
		INTEGER cb, fsAction, dwTime, hsz, hTask;
		CHAR str[1];
	} WinAPI_MONHSZSTRUCTA;

typedef
	struct WinAPI_MONHSZSTRUCTW {
		INTEGER cb, fsAction, dwTime, hsz, hTask;
		SHORTINT str[1];
	} WinAPI_MONHSZSTRUCTW;

typedef
	struct WinAPI_MONITOR_INFO_1A {
		INTEGER pName;
	} WinAPI_MONITOR_INFO_1A;

typedef
	struct WinAPI_MONITOR_INFO_1W {
		INTEGER pName;
	} WinAPI_MONITOR_INFO_1W;

typedef
	struct WinAPI_MONITOR_INFO_2A {
		INTEGER pName, pEnvironment, pDLLName;
	} WinAPI_MONITOR_INFO_2A;

typedef
	struct WinAPI_MONITOR_INFO_2W {
		INTEGER pName, pEnvironment, pDLLName;
	} WinAPI_MONITOR_INFO_2W;

typedef
	struct WinAPI_MONLINKSTRUCT {
		INTEGER cb, dwTime, hTask, fEstablished, fNoData, hszSvc, hszTopic, hszItem, wFmt, fServer, hConvServer, hConvClient;
	} WinAPI_MONLINKSTRUCT;

typedef
	struct WinAPI_MONMSGSTRUCT {
		INTEGER cb, hwndTo, dwTime, hTask, wMsg, wParam, lParam;
		WinAPI_DDEML_MSG_HOOK_DATA dmhd;
	} WinAPI_MONMSGSTRUCT;

typedef
	struct WinAPI_MOUSEHOOKSTRUCT {
		WinAPI_POINT pt;
		INTEGER hwnd, wHitTestCode, dwExtraInfo;
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
		INTEGER hwnd, message, wParam, lParam, time;
		WinAPI_POINT pt;
	} WinAPI_MSG;

typedef
	void (__STDCALL *WinAPI_MSGBOXCALLBACK)(WinAPI_HELPINFO*);

typedef
	struct WinAPI_MSGBOXPARAMSA {
		INTEGER cbSize, hwndOwner, hInstance, lpszText, lpszCaption;
		SET dwStyle;
		INTEGER lpszIcon, dwContextHelpId;
		WinAPI_MSGBOXCALLBACK lpfnMsgBoxCallback;
		INTEGER dwLanguageId;
	} WinAPI_MSGBOXPARAMSA;

typedef
	struct WinAPI_MSGBOXPARAMSW {
		INTEGER cbSize, hwndOwner, hInstance, lpszText, lpszCaption;
		SET dwStyle;
		INTEGER lpszIcon, dwContextHelpId;
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
	INTEGER (__STDCALL *WinAPI_NEWFONTENUMPROC)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_NEWFONTENUMPROCA)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__STDCALL *WinAPI_NEWFONTENUMPROCW)(INTEGER, INTEGER, INTEGER, INTEGER);

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
		INTEGER hwndFrom, idFrom, code;
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
		INTEGER cbSize, hWnd, uID;
		SET uFlags;
		INTEGER uCallbackMessage, hIcon;
		CHAR szTip[64];
	} WinAPI_NOTIFYICONDATAA;

typedef
	struct WinAPI_NOTIFYICONDATAW {
		INTEGER cbSize, hWnd, uID;
		SET uFlags;
		INTEGER uCallbackMessage, hIcon;
		SHORTINT szTip[64];
	} WinAPI_NOTIFYICONDATAW;

typedef
	struct WinAPI__EXCEPTION_REGISTRATION_RECORD *WinAPI_Ptr_EXCEPTION_REGISTRATION_RECORD;

typedef
	struct WinAPI_NT_TIB *WinAPI_PtrNT_TIB;

typedef
	struct WinAPI_NT_TIB {
		WinAPI_Ptr_EXCEPTION_REGISTRATION_RECORD ExceptionList;
		INTEGER StackBase, StackLimit, SubSystemTib;
		struct WinAPI__24 u;
		INTEGER ArbitraryUserPointer;
		WinAPI_PtrNT_TIB Self;
	} WinAPI_NT_TIB;

typedef
	struct WinAPI_NUMBERFMTA {
		INTEGER NumDigits, LeadingZero, Grouping, lpDecimalSep, lpThousandSep, NegativeOrder;
	} WinAPI_NUMBERFMTA;

typedef
	struct WinAPI_NUMBERFMTW {
		INTEGER NumDigits, LeadingZero, Grouping, lpDecimalSep, lpThousandSep, NegativeOrder;
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
		INTEGER otmsStrikeoutSize, otmsStrikeoutPosition, otmsUnderscoreSize, otmsUnderscorePosition, otmpFamilyName, otmpFaceName, otmpStyleName, otmpFullName;
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
		INTEGER otmsStrikeoutSize, otmsStrikeoutPosition, otmsUnderscoreSize, otmsUnderscorePosition, otmpFamilyName, otmpFaceName, otmpStyleName, otmpFullName;
	} WinAPI_OUTLINETEXTMETRICW;

typedef
	struct WinAPI_OUTPUT_DEBUG_STRING_INFO {
		INTEGER lpDebugStringData;
		SHORTINT fUnicode, nDebugStringLength;
	} WinAPI_OUTPUT_DEBUG_STRING_INFO;

typedef
	struct WinAPI_OVERLAPPED {
		INTEGER Internal, InternalHigh, Offset, OffsetHigh, hEvent;
	} WinAPI_OVERLAPPED;

typedef
	void (__STDCALL *WinAPI_OVERLAPPED_COMPLETION_ROUTINE)(INTEGER, INTEGER, WinAPI_OVERLAPPED*);

typedef
	struct WinAPI_PAINTSTRUCT {
		INTEGER hdc, fErase;
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
		INTEGER x, y, n, lpstr;
		SET uiFlags;
		WinAPI_RECT rcl;
		INTEGER pdx;
	} WinAPI_POLYTEXTA;

typedef
	struct WinAPI_POLYTEXTW {
		INTEGER x, y, n, lpstr;
		SET uiFlags;
		WinAPI_RECT rcl;
		INTEGER pdx;
	} WinAPI_POLYTEXTW;

typedef
	struct WinAPI_PORT_INFO_1A {
		INTEGER pName;
	} WinAPI_PORT_INFO_1A;

typedef
	struct WinAPI_PORT_INFO_1W {
		INTEGER pName;
	} WinAPI_PORT_INFO_1W;

typedef
	struct WinAPI_PORT_INFO_2A {
		INTEGER pPortName, pMonitorName, pDescription, fPortType, Reserved;
	} WinAPI_PORT_INFO_2A;

typedef
	struct WinAPI_PORT_INFO_2W {
		INTEGER pPortName, pMonitorName, pDescription, fPortType, Reserved;
	} WinAPI_PORT_INFO_2W;

typedef
	struct WinAPI_PRINTER_DEFAULTSA {
		INTEGER pDatatype;
		WinAPI_PtrDEVMODEA pDevMode;
		SET DesiredAccess;
	} WinAPI_PRINTER_DEFAULTSA;

typedef
	struct WinAPI_PRINTER_DEFAULTSW {
		INTEGER pDatatype;
		WinAPI_PtrDEVMODEW pDevMode;
		SET DesiredAccess;
	} WinAPI_PRINTER_DEFAULTSW;

typedef
	struct WinAPI_PRINTER_INFO_1A {
		SET Flags;
		INTEGER pDescription, pName, pComment;
	} WinAPI_PRINTER_INFO_1A;

typedef
	struct WinAPI_PRINTER_INFO_1W {
		SET Flags;
		INTEGER pDescription, pName, pComment;
	} WinAPI_PRINTER_INFO_1W;

typedef
	struct WinAPI_PRINTER_INFO_2A {
		INTEGER pServerName, pPrinterName, pShareName, pPortName, pDriverName, pComment, pLocation;
		WinAPI_PtrDEVMODEA pDevMode;
		INTEGER pSepFile, pPrintProcessor, pDatatype, pParameters, pSecurityDescriptor;
		SET Attributes;
		INTEGER Priority, DefaultPriority, StartTime, UntilTime;
		SET Status;
		INTEGER cJobs, AveragePPM;
	} WinAPI_PRINTER_INFO_2A;

typedef
	struct WinAPI_PRINTER_INFO_2W {
		INTEGER pServerName, pPrinterName, pShareName, pPortName, pDriverName, pComment, pLocation;
		WinAPI_PtrDEVMODEW pDevMode;
		INTEGER pSepFile, pPrintProcessor, pDatatype, pParameters, pSecurityDescriptor;
		SET Attributes;
		INTEGER Priority, DefaultPriority, StartTime, UntilTime;
		SET Status;
		INTEGER cJobs, AveragePPM;
	} WinAPI_PRINTER_INFO_2W;

typedef
	struct WinAPI_PRINTER_INFO_3 {
		INTEGER pSecurityDescriptor;
	} WinAPI_PRINTER_INFO_3;

typedef
	struct WinAPI_PRINTER_INFO_4A {
		INTEGER pPrinterName, pServerName;
		SET Attributes;
	} WinAPI_PRINTER_INFO_4A;

typedef
	struct WinAPI_PRINTER_INFO_4W {
		INTEGER pPrinterName, pServerName;
		SET Attributes;
	} WinAPI_PRINTER_INFO_4W;

typedef
	struct WinAPI_PRINTER_INFO_5A {
		INTEGER pPrinterName, pPortName;
		SET Attributes;
		INTEGER DeviceNotSelectedTimeout, TransmissionRetryTimeout;
	} WinAPI_PRINTER_INFO_5A;

typedef
	struct WinAPI_PRINTER_INFO_5W {
		INTEGER pPrinterName, pPortName;
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
		INTEGER Reserved1, Reserved2, Count, pFields;
	} WinAPI_PRINTER_NOTIFY_OPTIONS_TYPE;

typedef
	struct WinAPI_PRINTPROCESSOR_INFO_1A {
		INTEGER pName;
	} WinAPI_PRINTPROCESSOR_INFO_1A;

typedef
	struct WinAPI_PRINTPROCESSOR_INFO_1W {
		INTEGER pName;
	} WinAPI_PRINTPROCESSOR_INFO_1W;

typedef
	struct WinAPI_PRIVILEGE_SET {
		INTEGER PrivilegeCount, Control;
		WinAPI_LUID_AND_ATTRIBUTES Privilege[1];
	} WinAPI_PRIVILEGE_SET;

typedef
	struct WinAPI_PROCESS_HEAP_ENTRY {
		INTEGER lpData, cbData;
		CHAR cbOverhead, iRegionIndex;
		SHORTINT wFlags;
		struct WinAPI__28 u;
	} WinAPI_PROCESS_HEAP_ENTRY;

typedef
	struct WinAPI_PROCESS_INFORMATION {
		INTEGER hProcess, hThread, dwProcessId, dwThreadId;
	} WinAPI_PROCESS_INFORMATION;

typedef
	INTEGER (__STDCALL *WinAPI_PROGRESS_ROUTINE)(LONGINT, LONGINT, LONGINT, LONGINT, INTEGER, INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	struct WinAPI_PROPSHEETHEADERA {
		INTEGER dwSize;
		SET dwFlags;
		INTEGER hwndParent, hInstance;
		struct WinAPI__29 u;
		INTEGER pszCaption, nPages;
		struct WinAPI__30 u1;
		struct WinAPI__31 u2;
		WinAPI_FNPROPSHEETCALLBACK pfnCallback;
	} WinAPI_PROPSHEETHEADERA;

typedef
	struct WinAPI_PROPSHEETHEADERW {
		INTEGER dwSize;
		SET dwFlags;
		INTEGER hwndParent, hInstance;
		struct WinAPI__32 u;
		INTEGER pszCaption, nPages;
		struct WinAPI__33 u1;
		struct WinAPI__34 u2;
		WinAPI_FNPROPSHEETCALLBACK pfnCallback;
	} WinAPI_PROPSHEETHEADERW;

typedef
	struct WinAPI_PROPSHEETPAGEA {
		INTEGER dwSize;
		SET dwFlags;
		INTEGER hInstance;
		struct WinAPI__3 u;
		struct WinAPI__4 u1;
		INTEGER pszTitle;
		WinAPI_DLGPROC pfnDlgProc;
		INTEGER lParam;
		WinAPI_FNPSPCALLBACKA pfnCallback;
		INTEGER pcRefParent;
	} WinAPI_PROPSHEETPAGEA;

typedef
	struct WinAPI_PROPSHEETPAGEW {
		INTEGER dwSize;
		SET dwFlags;
		INTEGER hInstance;
		struct WinAPI__5 u;
		struct WinAPI__6 u1;
		INTEGER pszTitle;
		WinAPI_DLGPROC pfnDlgProc;
		INTEGER lParam;
		WinAPI_FNPSPCALLBACKW pfnCallback;
		INTEGER pcRefParent;
	} WinAPI_PROPSHEETPAGEW;

typedef
	struct WinAPI_PROVIDOR_INFO_1A {
		INTEGER pName, pEnvironment, pDLLName;
	} WinAPI_PROVIDOR_INFO_1A;

typedef
	struct WinAPI_PROVIDOR_INFO_1W {
		INTEGER pName, pEnvironment, pDLLName;
	} WinAPI_PROVIDOR_INFO_1W;

typedef
	struct WinAPI_PSHNOTIFY {
		WinAPI_NMHDR hdr;
		INTEGER lParam;
	} WinAPI_PSHNOTIFY;

typedef
	struct WinAPI_PVALUEA {
		INTEGER pv_valuename, pv_valuelen, pv_value_context, pv_type;
	} WinAPI_PVALUEA;

typedef
	struct WinAPI_PVALUEW {
		INTEGER pv_valuename, pv_valuelen, pv_value_context, pv_type;
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
		INTEGER Sid;
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
		INTEGER valuelen, value_context, val_buff_ptr;
	} WinAPI_val_context;

typedef
	INTEGER (__STDCALL *WinAPI_QUERYHANDLER)(INTEGER, WinAPI_val_context*, INTEGER, INTEGER, INTEGER*, INTEGER);

typedef
	struct WinAPI_QUERY_SERVICE_CONFIGA {
		SET dwServiceType;
		INTEGER dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, dwTagId, lpDependencies, lpServiceStartName, lpDisplayName;
	} WinAPI_QUERY_SERVICE_CONFIGA;

typedef
	struct WinAPI_QUERY_SERVICE_CONFIGW {
		SET dwServiceType;
		INTEGER dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, dwTagId, lpDependencies, lpServiceStartName, lpDisplayName;
	} WinAPI_QUERY_SERVICE_CONFIGW;

typedef
	struct WinAPI_QUERY_SERVICE_LOCK_STATUSA {
		INTEGER fIsLocked, lpLockOwner, dwLockDuration;
	} WinAPI_QUERY_SERVICE_LOCK_STATUSA;

typedef
	struct WinAPI_QUERY_SERVICE_LOCK_STATUSW {
		INTEGER fIsLocked, lpLockOwner, dwLockDuration;
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
		INTEGER pi_flags, pi_key_context;
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
		INTEGER nLength, lpSecurityDescriptor, bInheritHandle;
	} WinAPI_SECURITY_ATTRIBUTES;

typedef
	struct WinAPI_SECURITY_DESCRIPTOR {
		CHAR Revision, Sbz1;
		SHORTINT Control;
		INTEGER Owner, Group;
		WinAPI_PtrACL Sacl, Dacl;
	} WinAPI_SECURITY_DESCRIPTOR;

typedef
	INTEGER (__STDCALL *WinAPI_SENDASYNCPROC)(void);

typedef
	struct WinAPI_SERIALKEYSA {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER lpszActivePort, lpszPort, iBaudRate, iPortState, iActive;
	} WinAPI_SERIALKEYSA;

typedef
	struct WinAPI_SERIALKEYSW {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER lpszActivePort, lpszPort, iBaudRate, iPortState, iActive;
	} WinAPI_SERIALKEYSW;

typedef
	void (__STDCALL *WinAPI_SERVICE_MAIN_FUNCTIONA)(INTEGER, INTEGER);

typedef
	void (__STDCALL *WinAPI_SERVICE_MAIN_FUNCTIONW)(INTEGER, INTEGER);

typedef
	struct WinAPI_SERVICE_TABLE_ENTRYA {
		INTEGER lpServiceName;
		WinAPI_SERVICE_MAIN_FUNCTIONA lpServiceProc;
	} WinAPI_SERVICE_TABLE_ENTRYA;

typedef
	struct WinAPI_SERVICE_TABLE_ENTRYW {
		INTEGER lpServiceName;
		WinAPI_SERVICE_MAIN_FUNCTIONW lpServiceProc;
	} WinAPI_SERVICE_TABLE_ENTRYW;

typedef
	struct WinAPI_SE_IMPERSONATION_STATE {
		INTEGER Token;
		BOOLEAN CopyOnOpen, EffectiveOnly;
		INTEGER Level;
	} WinAPI_SE_IMPERSONATION_STATE;

typedef
	struct WinAPI_SHELLEXECUTEINFOA {
		INTEGER cbSize;
		SET fMask;
		INTEGER hwnd, lpVerb, lpFile, lpParameters, lpDirectory, nShow, hInstApp, lpIDList, lpClass, hkeyClass, dwHotKey, hIcon, hProcess;
	} WinAPI_SHELLEXECUTEINFOA;

typedef
	struct WinAPI_SHELLEXECUTEINFOW {
		INTEGER cbSize;
		SET fMask;
		INTEGER hwnd, lpVerb, lpFile, lpParameters, lpDirectory, nShow, hInstApp, lpIDList, lpClass, hkeyClass, dwHotKey, hIcon, hProcess;
	} WinAPI_SHELLEXECUTEINFOW;

typedef
	struct WinAPI_SHFILEINFOA {
		INTEGER hIcon, iIcon;
		SET dwAttributes;
		CHAR szDisplayName[260];
		CHAR szTypeName[80];
	} WinAPI_SHFILEINFOA;

typedef
	struct WinAPI_SHFILEINFOW {
		INTEGER hIcon, iIcon;
		SET dwAttributes;
		SHORTINT szDisplayName[260];
		SHORTINT szTypeName[80];
	} WinAPI_SHFILEINFOW;

typedef
	struct WinAPI_SHFILEOPSTRUCTA {
		INTEGER hwnd, wFunc, pFrom, pTo;
		SHORTINT fFlags;
		INTEGER fAnyOperationsAborted, hNameMappings, lpszProgressTitle;
	} WinAPI_SHFILEOPSTRUCTA;

typedef
	struct WinAPI_SHFILEOPSTRUCTW {
		INTEGER hwnd, wFunc, pFrom, pTo;
		SHORTINT fFlags;
		INTEGER fAnyOperationsAborted, hNameMappings, lpszProgressTitle;
	} WinAPI_SHFILEOPSTRUCTW;

typedef
	struct WinAPI_SHNAMEMAPPINGA {
		INTEGER pszOldPath, pszNewPath, cchOldPath, cchNewPath;
	} WinAPI_SHNAMEMAPPINGA;

typedef
	struct WinAPI_SHNAMEMAPPINGW {
		INTEGER pszOldPath, pszNewPath, cchOldPath, cchNewPath;
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
		INTEGER iFSTextEffect, iFSTextEffectMSec, iFSTextEffectColorBits, iFSGrafEffect, iFSGrafEffectMSec, iFSGrafEffectColor, iWindowsEffect, iWindowsEffectMSec, lpszWindowsEffectDLL, iWindowsEffectOrdinal;
	} WinAPI_SOUNDSENTRYA;

typedef
	struct WinAPI_SOUNDSENTRYW {
		INTEGER cbSize;
		SET dwFlags;
		INTEGER iFSTextEffect, iFSTextEffectMSec, iFSTextEffectColorBits, iFSGrafEffect, iFSGrafEffectMSec, iFSGrafEffectColor, iWindowsEffect, iWindowsEffectMSec, lpszWindowsEffectDLL, iWindowsEffectOrdinal;
	} WinAPI_SOUNDSENTRYW;

typedef
	struct WinAPI_STARTUPINFOA {
		INTEGER cb, lpReserved, lpDesktop, lpTitle, dwX, dwY, dwXSize, dwYSize, dwXCountChars, dwYCountChars, dwFillAttribute;
		SET dwFlags;
		SHORTINT wShowWindow, cbReserved2;
		INTEGER lpReserved2, hStdInput, hStdOutput, hStdError;
	} WinAPI_STARTUPINFOA;

typedef
	struct WinAPI_STARTUPINFOW {
		INTEGER cb, lpReserved, lpDesktop, lpTitle, dwX, dwY, dwXSize, dwYSize, dwXCountChars, dwYCountChars, dwFillAttribute;
		SET dwFlags;
		SHORTINT wShowWindow, cbReserved2;
		INTEGER lpReserved2, hStdInput, hStdOutput, hStdError;
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
		INTEGER dwPageSize, lpMinimumApplicationAddress, lpMaximumApplicationAddress, dwActiveProcessorMask, dwNumberOfProcessors, dwProcessorType, dwAllocationGranularity;
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
	void (__STDCALL *WinAPI_TIMERAPCROUTINE)(INTEGER, INTEGER, INTEGER);

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
		INTEGER Owner;
	} WinAPI_TOKEN_OWNER;

typedef
	struct WinAPI_TOKEN_PRIMARY_GROUP {
		INTEGER PrimaryGroup;
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
		INTEGER lpBaseOfDll;
	} WinAPI_UNLOAD_DLL_DEBUG_INFO;

typedef
	struct WinAPI_USEROBJECTFLAGS {
		INTEGER fInherit, fReserved;
		SET dwFlags;
	} WinAPI_USEROBJECTFLAGS;

typedef
	struct WinAPI_VALENTA {
		INTEGER ve_valuename, ve_valuelen, ve_valueptr, ve_type;
	} WinAPI_VALENTA;

typedef
	struct WinAPI_VALENTW {
		INTEGER ve_valuename, ve_valuelen, ve_valueptr, ve_type;
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
		INTEGER hwnd, hwndInsertAfter, x, y, cx, cy;
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
		INTEGER hClientToken;
		WinAPI_PtrWIN_CERTIFICATE lpCertificate;
	} WinAPI_WIN_SPUB_TRUSTEDPUB_DATA;

typedef
	struct WinAPI_WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT {
		INTEGER hClientToken, dwSubjectType, Subject;
	} WinAPI_WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT;

typedef
	struct WinAPI_WIN_TRUST_ACTDATA_SUBJECT_ONLY {
		INTEGER dwSubjectType, Subject;
	} WinAPI_WIN_TRUST_ACTDATA_SUBJECT_ONLY;

typedef
	struct WinAPI_WIN_TRUST_SUBJECT_FILE {
		INTEGER hFile, lpPath;
	} WinAPI_WIN_TRUST_SUBJECT_FILE;

typedef
	INTEGER (__STDCALL *WinAPI_WNDPROC)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	struct WinAPI_WNDCLASSA {
		SET style;
		WinAPI_WNDPROC lpfnWndProc;
		INTEGER cbClsExtra, cbWndExtra, hInstance, hIcon, hCursor, hbrBackground, lpszMenuName, lpszClassName;
	} WinAPI_WNDCLASSA;

typedef
	struct WinAPI_WNDCLASSEXA {
		INTEGER cbSize;
		SET style;
		WinAPI_WNDPROC lpfnWndProc;
		INTEGER cbClsExtra, cbWndExtra, hInstance, hIcon, hCursor, hbrBackground, lpszMenuName, lpszClassName, hIconSm;
	} WinAPI_WNDCLASSEXA;

typedef
	struct WinAPI_WNDCLASSEXW {
		INTEGER cbSize;
		SET style;
		WinAPI_WNDPROC lpfnWndProc;
		INTEGER cbClsExtra, cbWndExtra, hInstance, hIcon, hCursor, hbrBackground, lpszMenuName, lpszClassName, hIconSm;
	} WinAPI_WNDCLASSEXW;

typedef
	struct WinAPI_WNDCLASSW {
		SET style;
		WinAPI_WNDPROC lpfnWndProc;
		INTEGER cbClsExtra, cbWndExtra, hInstance, hIcon, hCursor, hbrBackground, lpszMenuName, lpszClassName;
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




__EXTERN INTEGER __STDCALL AbortDoc (INTEGER p0);
__EXTERN INTEGER __STDCALL AbortPath (INTEGER p0);
__EXTERN INTEGER __STDCALL AbortPrinter (INTEGER hPrinter);
__EXTERN INTEGER __STDCALL AbortSystemShutdownA (INTEGER lpMachineName);
__EXTERN INTEGER __STDCALL AbortSystemShutdownW (INTEGER lpMachineName);
__EXTERN INTEGER __STDCALL AccessCheck (INTEGER pSecurityDescriptor, INTEGER ClientToken, SET DesiredAccess, WinAPI_GENERIC_MAPPING *GenericMapping, WinAPI_PRIVILEGE_SET *PrivilegeSet, INTEGER *PrivilegeSetLength, INTEGER *GrantedAccess, INTEGER *AccessStatus);
__EXTERN INTEGER __STDCALL AccessCheckAndAuditAlarmA (INTEGER SubsystemName, INTEGER HandleId, INTEGER ObjectTypeName, INTEGER ObjectName, INTEGER SecurityDescriptor, SET DesiredAccess, WinAPI_GENERIC_MAPPING *GenericMapping, INTEGER ObjectCreation, INTEGER *GrantedAccess, INTEGER *AccessStatus, INTEGER *pfGenerateOnClose);
__EXTERN INTEGER __STDCALL AccessCheckAndAuditAlarmW (INTEGER SubsystemName, INTEGER HandleId, INTEGER ObjectTypeName, INTEGER ObjectName, INTEGER SecurityDescriptor, SET DesiredAccess, WinAPI_GENERIC_MAPPING *GenericMapping, INTEGER ObjectCreation, INTEGER *GrantedAccess, INTEGER *AccessStatus, INTEGER *pfGenerateOnClose);
__EXTERN INTEGER __STDCALL ActivateKeyboardLayout (INTEGER hkl, SET Flags);
__EXTERN INTEGER __STDCALL AddAccessAllowedAce (WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER AccessMask, INTEGER pSid);
__EXTERN INTEGER __STDCALL AddAccessDeniedAce (WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER AccessMask, INTEGER pSid);
__EXTERN INTEGER __STDCALL AddAce (WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER dwStartingAceIndex, INTEGER pAceList, INTEGER nAceListLength);
__EXTERN SHORTINT __STDCALL AddAtomA (INTEGER lpString);
__EXTERN SHORTINT __STDCALL AddAtomW (INTEGER lpString);
__EXTERN INTEGER __STDCALL AddAuditAccessAce (WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER dwAccessMask, INTEGER pSid, INTEGER bAuditSuccess, INTEGER bAuditFailure);
__EXTERN INTEGER __STDCALL AddFontResourceA (INTEGER p0);
__EXTERN INTEGER __STDCALL AddFontResourceW (INTEGER p0);
__EXTERN INTEGER __STDCALL AddFormA (INTEGER hPrinter, INTEGER Level, CHAR *pForm);
__EXTERN INTEGER __STDCALL AddFormW (INTEGER hPrinter, INTEGER Level, CHAR *pForm);
__EXTERN INTEGER __STDCALL AddJobA (INTEGER hPrinter, INTEGER Level, CHAR *pData, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL AddJobW (INTEGER hPrinter, INTEGER Level, CHAR *pData, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL AddMonitorA (INTEGER pName, INTEGER Level, CHAR *pMonitors);
__EXTERN INTEGER __STDCALL AddMonitorW (INTEGER pName, INTEGER Level, CHAR *pMonitors);
__EXTERN INTEGER __STDCALL AddPortA (INTEGER pName, INTEGER hWnd, INTEGER pMonitorName);
__EXTERN INTEGER __STDCALL AddPortW (INTEGER pName, INTEGER hWnd, INTEGER pMonitorName);
__EXTERN INTEGER __STDCALL AddPrintProcessorA (INTEGER pName, INTEGER pEnvironment, INTEGER pPathName, INTEGER pPrintProcessorName);
__EXTERN INTEGER __STDCALL AddPrintProcessorW (INTEGER pName, INTEGER pEnvironment, INTEGER pPathName, INTEGER pPrintProcessorName);
__EXTERN INTEGER __STDCALL AddPrintProvidorA (INTEGER pName, INTEGER level, CHAR *pProvidorInfo);
__EXTERN INTEGER __STDCALL AddPrintProvidorW (INTEGER pName, INTEGER level, CHAR *pProvidorInfo);
__EXTERN INTEGER __STDCALL AddPrinterA (INTEGER pName, INTEGER Level, CHAR *pPrinter);
__EXTERN INTEGER __STDCALL AddPrinterConnectionA (INTEGER pName);
__EXTERN INTEGER __STDCALL AddPrinterConnectionW (INTEGER pName);
__EXTERN INTEGER __STDCALL AddPrinterDriverA (INTEGER pName, INTEGER Level, CHAR *pDriverInfo);
__EXTERN INTEGER __STDCALL AddPrinterDriverW (INTEGER pName, INTEGER Level, CHAR *pDriverInfo);
__EXTERN INTEGER __STDCALL AddPrinterW (INTEGER pName, INTEGER Level, CHAR *pPrinter);
__EXTERN INTEGER __STDCALL AdjustTokenGroups (INTEGER TokenHandle, INTEGER ResetToDefault, WinAPI_TOKEN_GROUPS *NewState, INTEGER BufferLength, WinAPI_TOKEN_GROUPS *PreviousState, INTEGER *ReturnLength);
__EXTERN INTEGER __STDCALL AdjustTokenPrivileges (INTEGER TokenHandle, INTEGER DisableAllPrivileges, WinAPI_TOKEN_PRIVILEGES *NewState, INTEGER BufferLength, WinAPI_TOKEN_PRIVILEGES *PreviousState, INTEGER *ReturnLength);
__EXTERN INTEGER __STDCALL AdjustWindowRect (WinAPI_RECT *lpRect, SET dwStyle, INTEGER bMenu);
__EXTERN INTEGER __STDCALL AdjustWindowRectEx (WinAPI_RECT *lpRect, SET dwStyle, INTEGER bMenu, SET dwExStyle);
__EXTERN INTEGER __STDCALL AdvancedDocumentPropertiesA (INTEGER hWnd, INTEGER hPrinter, INTEGER pDeviceName, WinAPI_DEVMODEA *pDevModeOutput, WinAPI_DEVMODEA *pDevModeInput);
__EXTERN INTEGER __STDCALL AdvancedDocumentPropertiesW (INTEGER hWnd, INTEGER hPrinter, INTEGER pDeviceName, WinAPI_DEVMODEW *pDevModeOutput, WinAPI_DEVMODEW *pDevModeInput);
__EXTERN INTEGER __STDCALL AllocConsole (void);
__EXTERN INTEGER __STDCALL AllocateAndInitializeSid (WinAPI_SID_IDENTIFIER_AUTHORITY *pIdentifierAuthority, CHAR nSubAuthorityCount, INTEGER nSubAuthority0, INTEGER nSubAuthority1, INTEGER nSubAuthority2, INTEGER nSubAuthority3, INTEGER nSubAuthority4, INTEGER nSubAuthority5, INTEGER nSubAuthority6, INTEGER nSubAuthority7, INTEGER *pSid);
__EXTERN INTEGER __STDCALL AllocateLocallyUniqueId (LONGINT *Luid);
__EXTERN INTEGER __STDCALL AngleArc (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, SHORTREAL p4, SHORTREAL p5);
__EXTERN INTEGER __STDCALL AnimatePalette (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
__EXTERN INTEGER __STDCALL AnyPopup (void);
__EXTERN INTEGER __STDCALL AppendMenuA (INTEGER hMenu, SET uFlags, INTEGER uIDNewItem, INTEGER lpNewItem);
__EXTERN INTEGER __STDCALL AppendMenuW (INTEGER hMenu, SET uFlags, INTEGER uIDNewItem, INTEGER lpNewItem);
__EXTERN INTEGER __STDCALL Arc (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
__EXTERN INTEGER __STDCALL ArcTo (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
__EXTERN INTEGER __STDCALL AreAllAccessesGranted (INTEGER GrantedAccess, SET DesiredAccess);
__EXTERN INTEGER __STDCALL AreAnyAccessesGranted (INTEGER GrantedAccess, SET DesiredAccess);
__EXTERN INTEGER __STDCALL AreFileApisANSI (void);
__EXTERN INTEGER __STDCALL ArrangeIconicWindows (INTEGER hWnd);
__EXTERN INTEGER __STDCALL AttachThreadInput (INTEGER idAttach, INTEGER idAttachTo, INTEGER fAttach);
__EXTERN INTEGER __STDCALL BackupEventLogA (INTEGER hEventLog, INTEGER lpBackupFileName);
__EXTERN INTEGER __STDCALL BackupEventLogW (INTEGER hEventLog, INTEGER lpBackupFileName);
__EXTERN INTEGER __STDCALL BackupRead (INTEGER hFile, CHAR *lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *lpNumberOfBytesRead, INTEGER bAbort, INTEGER bProcessSecurity, INTEGER lpContext);
__EXTERN INTEGER __STDCALL BackupSeek (INTEGER hFile, INTEGER dwLowBytesToSeek, INTEGER dwHighBytesToSeek, INTEGER *lpdwLowByteSeeked, INTEGER *lpdwHighByteSeeked, INTEGER lpContext);
__EXTERN INTEGER __STDCALL BackupWrite (INTEGER hFile, CHAR *lpBuffer, INTEGER nNumberOfBytesToWrite, INTEGER *lpNumberOfBytesWritten, INTEGER bAbort, INTEGER bProcessSecurity, INTEGER lpContext);
__EXTERN INTEGER __STDCALL Beep (INTEGER dwFreq, INTEGER dwDuration);
__EXTERN INTEGER __STDCALL BeginDeferWindowPos (INTEGER nNumWindows);
__EXTERN INTEGER __STDCALL BeginPaint (INTEGER hWnd, WinAPI_PAINTSTRUCT *lpPaint);
__EXTERN INTEGER __STDCALL BeginPath (INTEGER p0);
__EXTERN INTEGER __STDCALL BeginUpdateResourceA (INTEGER pFileName, INTEGER bDeleteExistingResources);
__EXTERN INTEGER __STDCALL BeginUpdateResourceW (INTEGER pFileName, INTEGER bDeleteExistingResources);
__EXTERN INTEGER __STDCALL BitBlt (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
__EXTERN INTEGER __STDCALL BringWindowToTop (INTEGER hWnd);
__EXTERN INTEGER __STDCALL BroadcastSystemMessageA (SET p0, SET *p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL BroadcastSystemMessageW (SET p0, SET *p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL BuildCommDCBA (INTEGER lpDef, WinAPI_DCB *lpDCB);
__EXTERN INTEGER __STDCALL BuildCommDCBAndTimeoutsA (INTEGER lpDef, WinAPI_DCB *lpDCB, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
__EXTERN INTEGER __STDCALL BuildCommDCBAndTimeoutsW (INTEGER lpDef, WinAPI_DCB *lpDCB, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
__EXTERN INTEGER __STDCALL BuildCommDCBW (INTEGER lpDef, WinAPI_DCB *lpDCB);
__EXTERN INTEGER __STDCALL CallMsgFilterA (WinAPI_MSG *lpMsg, INTEGER nCode);
__EXTERN INTEGER __STDCALL CallMsgFilterW (WinAPI_MSG *lpMsg, INTEGER nCode);
__EXTERN INTEGER __STDCALL CallNamedPipeA (INTEGER lpNamedPipeName, INTEGER lpInBuffer, INTEGER nInBufferSize, INTEGER lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, INTEGER nTimeOut);
__EXTERN INTEGER __STDCALL CallNamedPipeW (INTEGER lpNamedPipeName, INTEGER lpInBuffer, INTEGER nInBufferSize, INTEGER lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, INTEGER nTimeOut);
__EXTERN INTEGER __STDCALL CallNextHookEx (INTEGER hhk, INTEGER nCode, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL CallWindowProcA (WinAPI_FARPROC lpPrevWndFunc, INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL CallWindowProcW (WinAPI_FARPROC lpPrevWndFunc, INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL CancelDC (INTEGER p0);
__EXTERN INTEGER __STDCALL CancelWaitableTimer (INTEGER hTimer);
__EXTERN SHORTINT __STDCALL CascadeWindows (INTEGER hwndParent, INTEGER wHow, WinAPI_RECT *lpRect, INTEGER cKids, INTEGER *lpKids);
__EXTERN INTEGER __STDCALL ChangeClipboardChain (INTEGER hWndRemove, INTEGER hWndNewNext);
__EXTERN INTEGER __STDCALL ChangeDisplaySettingsA (WinAPI_DEVMODEA *lpDevMode, SET dwFlags);
__EXTERN INTEGER __STDCALL ChangeDisplaySettingsW (WinAPI_DEVMODEW *lpDevMode, SET dwFlags);
__EXTERN INTEGER __STDCALL ChangeMenuA (INTEGER hMenu, INTEGER cmd, INTEGER lpszNewItem, INTEGER cmdInsert, SET flags);
__EXTERN INTEGER __STDCALL ChangeMenuW (INTEGER hMenu, INTEGER cmd, INTEGER lpszNewItem, INTEGER cmdInsert, SET flags);
__EXTERN INTEGER __STDCALL ChangeServiceConfigA (INTEGER hService, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, INTEGER lpBinaryPathName, INTEGER lpLoadOrderGroup, INTEGER *lpdwTagId, INTEGER lpDependencies, INTEGER lpServiceStartName, INTEGER lpPassword, INTEGER lpDisplayName);
__EXTERN INTEGER __STDCALL ChangeServiceConfigW (INTEGER hService, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, INTEGER lpBinaryPathName, INTEGER lpLoadOrderGroup, INTEGER *lpdwTagId, INTEGER lpDependencies, INTEGER lpServiceStartName, INTEGER lpPassword, INTEGER lpDisplayName);
__EXTERN INTEGER __STDCALL CharLowerA (INTEGER lpsz);
__EXTERN INTEGER __STDCALL CharLowerBuffA (INTEGER lpsz, INTEGER cchLength);
__EXTERN INTEGER __STDCALL CharLowerBuffW (INTEGER lpsz, INTEGER cchLength);
__EXTERN INTEGER __STDCALL CharLowerW (INTEGER lpsz);
__EXTERN INTEGER __STDCALL CharNextA (INTEGER lpsz);
__EXTERN INTEGER __STDCALL CharNextExA (SHORTINT CodePage, INTEGER lpCurrentChar, SET dwFlags);
__EXTERN INTEGER __STDCALL CharNextW (INTEGER lpsz);
__EXTERN INTEGER __STDCALL CharPrevA (INTEGER lpszStart, INTEGER lpszCurrent);
__EXTERN INTEGER __STDCALL CharPrevExA (SHORTINT CodePage, INTEGER lpStart, INTEGER lpCurrentChar, SET dwFlags);
__EXTERN INTEGER __STDCALL CharPrevW (INTEGER lpszStart, INTEGER lpszCurrent);
__EXTERN INTEGER __STDCALL CharToOemA (INTEGER lpszSrc, INTEGER lpszDst);
__EXTERN INTEGER __STDCALL CharToOemBuffA (INTEGER lpszSrc, INTEGER lpszDst, INTEGER cchDstLength);
__EXTERN INTEGER __STDCALL CharToOemBuffW (INTEGER lpszSrc, INTEGER lpszDst, INTEGER cchDstLength);
__EXTERN INTEGER __STDCALL CharToOemW (INTEGER lpszSrc, INTEGER lpszDst);
__EXTERN INTEGER __STDCALL CharUpperA (INTEGER lpsz);
__EXTERN INTEGER __STDCALL CharUpperBuffA (INTEGER lpsz, INTEGER cchLength);
__EXTERN INTEGER __STDCALL CharUpperBuffW (INTEGER lpsz, INTEGER cchLength);
__EXTERN INTEGER __STDCALL CharUpperW (INTEGER lpsz);
__EXTERN INTEGER __STDCALL CheckColorsInGamut (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL CheckDlgButton (INTEGER hDlg, INTEGER nIDButton, SET uCheck);
__EXTERN INTEGER __STDCALL CheckMenuItem (INTEGER hMenu, INTEGER uIDCheckItem, SET uCheck);
__EXTERN INTEGER __STDCALL CheckMenuRadioItem (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL CheckRadioButton (INTEGER hDlg, INTEGER nIDFirstButton, INTEGER nIDLastButton, INTEGER nIDCheckButton);
__EXTERN INTEGER __STDCALL ChildWindowFromPoint (INTEGER hWndParent, WinAPI_POINT *Point);
__EXTERN INTEGER __STDCALL ChildWindowFromPointEx (INTEGER p0, WinAPI_POINT *p1, SET p2);
__EXTERN INTEGER __STDCALL ChoosePixelFormat (INTEGER p0, WinAPI_PIXELFORMATDESCRIPTOR *p1);
__EXTERN INTEGER __STDCALL Chord (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
__EXTERN INTEGER __STDCALL ClearCommBreak (INTEGER hFile);
__EXTERN INTEGER __STDCALL ClearCommError (INTEGER hFile, SET *lpErrors, WinAPI_COMSTAT *lpStat);
__EXTERN INTEGER __STDCALL ClearEventLogA (INTEGER hEventLog, INTEGER lpBackupFileName);
__EXTERN INTEGER __STDCALL ClearEventLogW (INTEGER hEventLog, INTEGER lpBackupFileName);
__EXTERN INTEGER __STDCALL ClientToScreen (INTEGER hWnd, WinAPI_POINT *lpPoint);
__EXTERN INTEGER __STDCALL ClipCursor (WinAPI_RECT *lpRect);
__EXTERN INTEGER __STDCALL CloseClipboard (void);
__EXTERN INTEGER __STDCALL CloseDesktop (INTEGER hDesktop);
__EXTERN INTEGER __STDCALL CloseEnhMetaFile (INTEGER p0);
__EXTERN INTEGER __STDCALL CloseEventLog (INTEGER hEventLog);
__EXTERN INTEGER __STDCALL CloseFigure (INTEGER p0);
__EXTERN INTEGER __STDCALL CloseHandle (INTEGER hObject);
__EXTERN INTEGER __STDCALL CloseMetaFile (INTEGER p0);
__EXTERN INTEGER __STDCALL ClosePrinter (INTEGER hPrinter);
__EXTERN INTEGER __STDCALL CloseServiceHandle (INTEGER hSCObject);
__EXTERN INTEGER __STDCALL CloseWindow (INTEGER hWnd);
__EXTERN INTEGER __STDCALL CloseWindowStation (INTEGER hWinSta);
__EXTERN INTEGER __STDCALL ColorMatchToTarget (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL CombineRgn (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL CombineTransform (WinAPI_XFORM *p0, WinAPI_XFORM *p1, WinAPI_XFORM *p2);
__EXTERN INTEGER __STDCALL CommConfigDialogA (INTEGER lpszName, INTEGER hWnd, WinAPI_COMMCONFIG *lpCC);
__EXTERN INTEGER __STDCALL CommConfigDialogW (INTEGER lpszName, INTEGER hWnd, WinAPI_COMMCONFIG *lpCC);
__EXTERN INTEGER __STDCALL CommandLineToArgvW (INTEGER lpCmdLine, INTEGER *pNumArgs);
__EXTERN INTEGER __STDCALL CompareFileTime (WinAPI_FILETIME *lpFileTime1, WinAPI_FILETIME *lpFileTime2);
__EXTERN INTEGER __STDCALL CompareStringA (INTEGER Locale, SET dwCmpFlags, INTEGER lpString1, INTEGER cchCount1, INTEGER lpString2, INTEGER cchCount2);
__EXTERN INTEGER __STDCALL CompareStringW (INTEGER Locale, SET dwCmpFlags, INTEGER lpString1, INTEGER cchCount1, INTEGER lpString2, INTEGER cchCount2);
__EXTERN INTEGER __STDCALL ConfigurePortA (INTEGER pName, INTEGER hWnd, INTEGER pPortName);
__EXTERN INTEGER __STDCALL ConfigurePortW (INTEGER pName, INTEGER hWnd, INTEGER pPortName);
__EXTERN INTEGER __STDCALL ConnectNamedPipe (INTEGER hNamedPipe, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL ConnectToPrinterDlg (INTEGER hwnd, SET Flags);
__EXTERN INTEGER __STDCALL ContinueDebugEvent (INTEGER dwProcessId, INTEGER dwThreadId, SET dwContinueStatus);
__EXTERN INTEGER __STDCALL ControlService (INTEGER hService, INTEGER dwControl, WinAPI_SERVICE_STATUS *lpServiceStatus);
__EXTERN INTEGER __STDCALL ConvertDefaultLocale (INTEGER Locale);
__EXTERN INTEGER __STDCALL ConvertThreadToFiber (INTEGER lpParameter);
__EXTERN INTEGER __STDCALL CopyAcceleratorTableA (INTEGER hAccelSrc, WinAPI_ACCEL *lpAccelDst, INTEGER cAccelEntries);
__EXTERN INTEGER __STDCALL CopyAcceleratorTableW (INTEGER hAccelSrc, WinAPI_ACCEL *lpAccelDst, INTEGER cAccelEntries);
__EXTERN INTEGER __STDCALL CopyEnhMetaFileA (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL CopyEnhMetaFileW (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL CopyFileA (INTEGER lpExistingFileName, INTEGER lpNewFileName, INTEGER bFailIfExists);
__EXTERN INTEGER __STDCALL CopyFileExA (INTEGER lpExistingFileName, INTEGER lpNewFileName, WinAPI_PROGRESS_ROUTINE lpProgressRoutine, INTEGER lpData, INTEGER *pbCancel, INTEGER dwCopyFlags);
__EXTERN INTEGER __STDCALL CopyFileExW (INTEGER lpExistingFileName, INTEGER lpNewFileName, WinAPI_PROGRESS_ROUTINE lpProgressRoutine, INTEGER lpData, INTEGER *pbCancel, INTEGER dwCopyFlags);
__EXTERN INTEGER __STDCALL CopyFileW (INTEGER lpExistingFileName, INTEGER lpNewFileName, INTEGER bFailIfExists);
__EXTERN INTEGER __STDCALL CopyIcon (INTEGER hIcon);
__EXTERN INTEGER __STDCALL CopyImage (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL CopyLZFile (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL CopyMetaFileA (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL CopyMetaFileW (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL CopyRect (WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc);
__EXTERN INTEGER __STDCALL CopySid (INTEGER nDestinationSidLength, INTEGER pDestinationSid, INTEGER pSourceSid);
__EXTERN INTEGER __STDCALL CountClipboardFormats (void);
__EXTERN INTEGER __STDCALL CreateAcceleratorTableA (WinAPI_ACCEL *p0, INTEGER p1);
__EXTERN INTEGER __STDCALL CreateAcceleratorTableW (WinAPI_ACCEL *p0, INTEGER p1);
__EXTERN INTEGER __STDCALL CreateBitmap (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL CreateBitmapIndirect (WinAPI_BITMAP *p0);
__EXTERN INTEGER __STDCALL CreateBrushIndirect (WinAPI_LOGBRUSH *p0);
__EXTERN INTEGER __STDCALL CreateCaret (INTEGER hWnd, INTEGER hBitmap, INTEGER nWidth, INTEGER nHeight);
__EXTERN INTEGER __STDCALL CreateColorSpaceA (WinAPI_LOGCOLORSPACEA *p0);
__EXTERN INTEGER __STDCALL CreateColorSpaceW (WinAPI_LOGCOLORSPACEW *p0);
__EXTERN INTEGER __STDCALL CreateCompatibleBitmap (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL CreateCompatibleDC (INTEGER p0);
__EXTERN INTEGER __STDCALL CreateConsoleScreenBuffer (SET dwDesiredAccess, SET dwShareMode, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, SET dwFlags, INTEGER lpScreenBufferData);
__EXTERN INTEGER __STDCALL CreateCursor (INTEGER hInst, INTEGER xHotSpot, INTEGER yHotSpot, INTEGER nWidth, INTEGER nHeight, INTEGER pvANDPlane, INTEGER pvXORPlane);
__EXTERN INTEGER __STDCALL CreateDCA (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_DEVMODEA *p3);
__EXTERN INTEGER __STDCALL CreateDCW (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_DEVMODEW *p3);
__EXTERN INTEGER __STDCALL CreateDIBPatternBrush (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL CreateDIBPatternBrushPt (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL CreateDIBSection (INTEGER p0, WinAPI_BITMAPINFO *p1, INTEGER p2, INTEGER *p3, INTEGER p4, INTEGER p5);
__EXTERN INTEGER __STDCALL CreateDIBitmap (INTEGER p0, WinAPI_BITMAPINFOHEADER *p1, INTEGER p2, INTEGER p3, WinAPI_BITMAPINFO *p4, INTEGER p5);
__EXTERN INTEGER __STDCALL CreateDesktopA (INTEGER lpszDesktop, INTEGER lpszDevice, WinAPI_DEVMODEA *pDevmode, SET dwFlags, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
__EXTERN INTEGER __STDCALL CreateDesktopW (INTEGER lpszDesktop, INTEGER lpszDevice, WinAPI_DEVMODEW *pDevmode, SET dwFlags, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
__EXTERN INTEGER __STDCALL CreateDialogIndirectParamA (INTEGER hInstance, WinAPI_DLGTEMPLATE *lpTemplate, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
__EXTERN INTEGER __STDCALL CreateDialogIndirectParamW (INTEGER hInstance, WinAPI_DLGTEMPLATE *lpTemplate, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
__EXTERN INTEGER __STDCALL CreateDialogParamA (INTEGER hInstance, INTEGER lpTemplateName, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
__EXTERN INTEGER __STDCALL CreateDialogParamW (INTEGER hInstance, INTEGER lpTemplateName, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
__EXTERN INTEGER __STDCALL CreateDirectoryA (INTEGER lpPathName, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL CreateDirectoryExA (INTEGER lpTemplateDirectory, INTEGER lpNewDirectory, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL CreateDirectoryExW (INTEGER lpTemplateDirectory, INTEGER lpNewDirectory, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL CreateDirectoryW (INTEGER lpPathName, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL CreateDiscardableBitmap (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL CreateEllipticRgn (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL CreateEllipticRgnIndirect (WinAPI_RECT *p0);
__EXTERN INTEGER __STDCALL CreateEnhMetaFileA (INTEGER p0, INTEGER p1, WinAPI_RECT *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL CreateEnhMetaFileW (INTEGER p0, INTEGER p1, WinAPI_RECT *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL CreateEventA (WinAPI_SECURITY_ATTRIBUTES *lpEventAttributes, INTEGER bManualReset, INTEGER bInitialState, INTEGER lpName);
__EXTERN INTEGER __STDCALL CreateEventW (WinAPI_SECURITY_ATTRIBUTES *lpEventAttributes, INTEGER bManualReset, INTEGER bInitialState, INTEGER lpName);
__EXTERN INTEGER __STDCALL CreateFiber (INTEGER dwStackSize, WinAPI_FIBER_START_ROUTINE lpStartAddress, INTEGER lpParameter);
__EXTERN INTEGER __STDCALL CreateFileA (INTEGER lpFileName, SET dwDesiredAccess, SET dwShareMode, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER dwCreationDisposition, SET dwFlagsAndAttributes, INTEGER hTemplateFile);
__EXTERN INTEGER __STDCALL CreateFileMappingA (INTEGER hFile, WinAPI_SECURITY_ATTRIBUTES *lpFileMappingAttributes, SET flProtect, INTEGER dwMaximumSizeHigh, INTEGER dwMaximumSizeLow, INTEGER lpName);
__EXTERN INTEGER __STDCALL CreateFileMappingW (INTEGER hFile, WinAPI_SECURITY_ATTRIBUTES *lpFileMappingAttributes, SET flProtect, INTEGER dwMaximumSizeHigh, INTEGER dwMaximumSizeLow, INTEGER lpName);
__EXTERN INTEGER __STDCALL CreateFileW (INTEGER lpFileName, SET dwDesiredAccess, SET dwShareMode, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER dwCreationDisposition, SET dwFlagsAndAttributes, INTEGER hTemplateFile);
__EXTERN INTEGER __STDCALL CreateFontA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10, INTEGER p11, INTEGER p12, INTEGER p13);
__EXTERN INTEGER __STDCALL CreateFontIndirectA (WinAPI_LOGFONTA *p0);
__EXTERN INTEGER __STDCALL CreateFontIndirectW (WinAPI_LOGFONTW *p0);
__EXTERN INTEGER __STDCALL CreateFontW (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10, INTEGER p11, INTEGER p12, INTEGER p13);
__EXTERN INTEGER __STDCALL CreateHalftonePalette (INTEGER p0);
__EXTERN INTEGER __STDCALL CreateHatchBrush (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL CreateICA (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_DEVMODEA *p3);
__EXTERN INTEGER __STDCALL CreateICW (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_DEVMODEW *p3);
__EXTERN INTEGER __STDCALL CreateIcon (INTEGER hInstance, INTEGER nWidth, INTEGER nHeight, CHAR cPlanes, CHAR cBitsPixel, CHAR *lpbANDbits, CHAR *lpbXORbits);
__EXTERN INTEGER __STDCALL CreateIconFromResource (CHAR *presbits, INTEGER dwResSize, INTEGER fIcon, INTEGER dwVer);
__EXTERN INTEGER __STDCALL CreateIconFromResourceEx (CHAR *presbits, INTEGER dwResSize, INTEGER fIcon, INTEGER dwVer, INTEGER cxDesired, INTEGER cyDesired, SET Flags);
__EXTERN INTEGER __STDCALL CreateIconIndirect (WinAPI_ICONINFO *piconinfo);
__EXTERN INTEGER __STDCALL CreateIoCompletionPort (INTEGER FileHandle, INTEGER ExistingCompletionPort, INTEGER CompletionKey, INTEGER NumberOfConcurrentThreads);
__EXTERN INTEGER __STDCALL CreateMDIWindowA (INTEGER lpClassName, INTEGER lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent, INTEGER hInstance, INTEGER lParam);
__EXTERN INTEGER __STDCALL CreateMDIWindowW (INTEGER lpClassName, INTEGER lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent, INTEGER hInstance, INTEGER lParam);
__EXTERN INTEGER __STDCALL CreateMailslotA (INTEGER lpName, INTEGER nMaxMessageSize, INTEGER lReadTimeout, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL CreateMailslotW (INTEGER lpName, INTEGER nMaxMessageSize, INTEGER lReadTimeout, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL CreateMenu (void);
__EXTERN INTEGER __STDCALL CreateMetaFileA (INTEGER p0);
__EXTERN INTEGER __STDCALL CreateMetaFileW (INTEGER p0);
__EXTERN INTEGER __STDCALL CreateMutexA (WinAPI_SECURITY_ATTRIBUTES *lpMutexAttributes, INTEGER bInitialOwner, INTEGER lpName);
__EXTERN INTEGER __STDCALL CreateMutexW (WinAPI_SECURITY_ATTRIBUTES *lpMutexAttributes, INTEGER bInitialOwner, INTEGER lpName);
__EXTERN INTEGER __STDCALL CreateNamedPipeA (INTEGER lpName, INTEGER dwOpenMode, INTEGER dwPipeMode, INTEGER nMaxInstances, INTEGER nOutBufferSize, INTEGER nInBufferSize, INTEGER nDefaultTimeOut, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL CreateNamedPipeW (INTEGER lpName, INTEGER dwOpenMode, INTEGER dwPipeMode, INTEGER nMaxInstances, INTEGER nOutBufferSize, INTEGER nInBufferSize, INTEGER nDefaultTimeOut, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL CreatePalette (WinAPI_LOGPALETTE *p0);
__EXTERN INTEGER __STDCALL CreatePatternBrush (INTEGER p0);
__EXTERN INTEGER __STDCALL CreatePen (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL CreatePenIndirect (WinAPI_LOGPEN *p0);
__EXTERN INTEGER __STDCALL CreatePipe (INTEGER *hReadPipe, INTEGER *hWritePipe, WinAPI_SECURITY_ATTRIBUTES *lpPipeAttributes, INTEGER nSize);
__EXTERN INTEGER __STDCALL CreatePolyPolygonRgn (WinAPI_POINT *p0, INTEGER *p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL CreatePolygonRgn (WinAPI_POINT *p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL CreatePopupMenu (void);
__EXTERN INTEGER __STDCALL CreatePrivateObjectSecurity (INTEGER ParentDescriptor, INTEGER CreatorDescriptor, INTEGER *NewDescriptor, INTEGER IsDirectoryObject, INTEGER Token, WinAPI_GENERIC_MAPPING *GenericMapping);
__EXTERN INTEGER __STDCALL CreateProcessA (INTEGER lpApplicationName, INTEGER lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, INTEGER lpEnvironment, INTEGER lpCurrentDirectory, WinAPI_STARTUPINFOA *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
__EXTERN INTEGER __STDCALL CreateProcessAsUserA (INTEGER hToken, INTEGER lpApplicationName, INTEGER lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, INTEGER lpEnvironment, INTEGER lpCurrentDirectory, WinAPI_STARTUPINFOA *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
__EXTERN INTEGER __STDCALL CreateProcessAsUserW (INTEGER hToken, INTEGER lpApplicationName, INTEGER lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, INTEGER lpEnvironment, INTEGER lpCurrentDirectory, WinAPI_STARTUPINFOW *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
__EXTERN INTEGER __STDCALL CreateProcessW (INTEGER lpApplicationName, INTEGER lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, INTEGER lpEnvironment, INTEGER lpCurrentDirectory, WinAPI_STARTUPINFOW *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
__EXTERN WinAPI_Ptr_PSP __STDCALL CreatePropertySheetPageA (WinAPI_PROPSHEETPAGEA *p0);
__EXTERN WinAPI_Ptr_PSP __STDCALL CreatePropertySheetPageW (WinAPI_PROPSHEETPAGEW *p0);
__EXTERN INTEGER __STDCALL CreateRectRgn (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL CreateRectRgnIndirect (WinAPI_RECT *p0);
__EXTERN INTEGER __STDCALL CreateRemoteThread (INTEGER hProcess, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER dwStackSize, WinAPI_THREAD_START_ROUTINE lpStartAddress, INTEGER lpParameter, SET dwCreationFlags, INTEGER *lpThreadId);
__EXTERN INTEGER __STDCALL CreateRoundRectRgn (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
__EXTERN INTEGER __STDCALL CreateScalableFontResourceA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL CreateScalableFontResourceW (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL CreateSemaphoreA (WinAPI_SECURITY_ATTRIBUTES *lpSemaphoreAttributes, INTEGER lInitialCount, INTEGER lMaximumCount, INTEGER lpName);
__EXTERN INTEGER __STDCALL CreateSemaphoreW (WinAPI_SECURITY_ATTRIBUTES *lpSemaphoreAttributes, INTEGER lInitialCount, INTEGER lMaximumCount, INTEGER lpName);
__EXTERN INTEGER __STDCALL CreateServiceA (INTEGER hSCManager, INTEGER lpServiceName, INTEGER lpDisplayName, SET dwDesiredAccess, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, INTEGER lpBinaryPathName, INTEGER lpLoadOrderGroup, INTEGER *lpdwTagId, INTEGER lpDependencies, INTEGER lpServiceStartName, INTEGER lpPassword);
__EXTERN INTEGER __STDCALL CreateServiceW (INTEGER hSCManager, INTEGER lpServiceName, INTEGER lpDisplayName, SET dwDesiredAccess, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, INTEGER lpBinaryPathName, INTEGER lpLoadOrderGroup, INTEGER *lpdwTagId, INTEGER lpDependencies, INTEGER lpServiceStartName, INTEGER lpPassword);
__EXTERN INTEGER __STDCALL CreateSolidBrush (INTEGER p0);
__EXTERN INTEGER __STDCALL CreateTapePartition (INTEGER hDevice, INTEGER dwPartitionMethod, INTEGER dwCount, INTEGER dwSize);
__EXTERN INTEGER __STDCALL CreateThread (WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER dwStackSize, WinAPI_THREAD_START_ROUTINE lpStartAddress, INTEGER lpParameter, SET dwCreationFlags, INTEGER *lpThreadId);
__EXTERN INTEGER __STDCALL CreateWaitableTimerA (WinAPI_SECURITY_ATTRIBUTES *lpTimerAttributes, INTEGER bManualReset, INTEGER lpTimerName);
__EXTERN INTEGER __STDCALL CreateWaitableTimerW (WinAPI_SECURITY_ATTRIBUTES *lpTimerAttributes, INTEGER bManualReset, INTEGER lpTimerName);
__EXTERN INTEGER __STDCALL CreateWindowExA (SET dwExStyle, INTEGER lpClassName, INTEGER lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent, INTEGER hMenu, INTEGER hInstance, INTEGER lpParam);
__EXTERN INTEGER __STDCALL CreateWindowExW (SET dwExStyle, INTEGER lpClassName, INTEGER lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent, INTEGER hMenu, INTEGER hInstance, INTEGER lpParam);
__EXTERN INTEGER __STDCALL CreateWindowStationA (INTEGER lpwinsta, INTEGER dwReserved, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
__EXTERN INTEGER __STDCALL CreateWindowStationW (INTEGER lpwinsta, INTEGER dwReserved, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
__EXTERN INTEGER __STDCALL DPtoLP (INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL DdeAbandonTransaction (INTEGER idInst, INTEGER hConv, INTEGER idTransaction);
__EXTERN INTEGER __STDCALL DdeAccessData (INTEGER hData, INTEGER *pcbDataSize);
__EXTERN INTEGER __STDCALL DdeAddData (INTEGER hData, CHAR *pSrc, INTEGER cb, INTEGER cbOff);
__EXTERN INTEGER __STDCALL DdeClientTransaction (CHAR *pData, INTEGER cbData, INTEGER hConv, INTEGER hszItem, INTEGER wFmt, INTEGER wType, INTEGER dwTimeout, INTEGER *pdwResult);
__EXTERN INTEGER __STDCALL DdeCmpStringHandles (INTEGER hsz1, INTEGER hsz2);
__EXTERN INTEGER __STDCALL DdeConnect (INTEGER idInst, INTEGER hszService, INTEGER hszTopic, WinAPI_CONVCONTEXT *pCC);
__EXTERN INTEGER __STDCALL DdeConnectList (INTEGER idInst, INTEGER hszService, INTEGER hszTopic, INTEGER hConvList, WinAPI_CONVCONTEXT *pCC);
__EXTERN INTEGER __STDCALL DdeCreateDataHandle (INTEGER idInst, CHAR *pSrc, INTEGER cb, INTEGER cbOff, INTEGER hszItem, INTEGER wFmt, INTEGER afCmd);
__EXTERN INTEGER __STDCALL DdeCreateStringHandleA (INTEGER idInst, INTEGER psz, INTEGER iCodePage);
__EXTERN INTEGER __STDCALL DdeCreateStringHandleW (INTEGER idInst, INTEGER psz, INTEGER iCodePage);
__EXTERN INTEGER __STDCALL DdeDisconnect (INTEGER hConv);
__EXTERN INTEGER __STDCALL DdeDisconnectList (INTEGER hConvList);
__EXTERN INTEGER __STDCALL DdeEnableCallback (INTEGER idInst, INTEGER hConv, INTEGER wCmd);
__EXTERN INTEGER __STDCALL DdeFreeDataHandle (INTEGER hData);
__EXTERN INTEGER __STDCALL DdeFreeStringHandle (INTEGER idInst, INTEGER hsz);
__EXTERN INTEGER __STDCALL DdeGetData (INTEGER hData, CHAR *pDst, INTEGER cbMax, INTEGER cbOff);
__EXTERN INTEGER __STDCALL DdeGetLastError (INTEGER idInst);
__EXTERN INTEGER __STDCALL DdeImpersonateClient (INTEGER hConv);
__EXTERN INTEGER __STDCALL DdeInitializeA (INTEGER *pidInst, WinAPI_FNCALLBACK pfnCallback, INTEGER afCmd, INTEGER ulRes);
__EXTERN INTEGER __STDCALL DdeInitializeW (INTEGER *pidInst, WinAPI_FNCALLBACK pfnCallback, INTEGER afCmd, INTEGER ulRes);
__EXTERN INTEGER __STDCALL DdeKeepStringHandle (INTEGER idInst, INTEGER hsz);
__EXTERN INTEGER __STDCALL DdeNameService (INTEGER idInst, INTEGER hsz1, INTEGER hsz2, INTEGER afCmd);
__EXTERN INTEGER __STDCALL DdePostAdvise (INTEGER idInst, INTEGER hszTopic, INTEGER hszItem);
__EXTERN INTEGER __STDCALL DdeQueryConvInfo (INTEGER hConv, INTEGER idTransaction, WinAPI_CONVINFO *pConvInfo);
__EXTERN INTEGER __STDCALL DdeQueryNextServer (INTEGER hConvList, INTEGER hConvPrev);
__EXTERN INTEGER __STDCALL DdeQueryStringA (INTEGER idInst, INTEGER hsz, INTEGER psz, INTEGER cchMax, INTEGER iCodePage);
__EXTERN INTEGER __STDCALL DdeQueryStringW (INTEGER idInst, INTEGER hsz, INTEGER psz, INTEGER cchMax, INTEGER iCodePage);
__EXTERN INTEGER __STDCALL DdeReconnect (INTEGER hConv);
__EXTERN INTEGER __STDCALL DdeSetQualityOfService (INTEGER hwndClient, WinAPI_SECURITY_QUALITY_OF_SERVICE *pqosNew, WinAPI_SECURITY_QUALITY_OF_SERVICE *pqosPrev);
__EXTERN INTEGER __STDCALL DdeSetUserHandle (INTEGER hConv, INTEGER id, INTEGER hUser);
__EXTERN INTEGER __STDCALL DdeUnaccessData (INTEGER hData);
__EXTERN INTEGER __STDCALL DdeUninitialize (INTEGER idInst);
__EXTERN INTEGER __STDCALL DebugActiveProcess (INTEGER dwProcessId);
__EXTERN void __STDCALL DebugBreak (void);
__EXTERN INTEGER __STDCALL DefDlgProcA (INTEGER hDlg, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL DefDlgProcW (INTEGER hDlg, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL DefFrameProcA (INTEGER hWnd, INTEGER hWndMDIClient, INTEGER uMsg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL DefFrameProcW (INTEGER hWnd, INTEGER hWndMDIClient, INTEGER uMsg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL DefMDIChildProcA (INTEGER hWnd, INTEGER uMsg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL DefMDIChildProcW (INTEGER hWnd, INTEGER uMsg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL DefWindowProcA (INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL DefWindowProcW (INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL DeferWindowPos (INTEGER hWinPosInfo, INTEGER hWnd, INTEGER hWndInsertAfter, INTEGER x, INTEGER y, INTEGER cx, INTEGER cy, SET uFlags);
__EXTERN INTEGER __STDCALL DefineDosDeviceA (SET dwFlags, INTEGER lpDeviceName, INTEGER lpTargetPath);
__EXTERN INTEGER __STDCALL DefineDosDeviceW (SET dwFlags, INTEGER lpDeviceName, INTEGER lpTargetPath);
__EXTERN INTEGER __STDCALL DeleteAce (WinAPI_ACL *pAcl, INTEGER dwAceIndex);
__EXTERN SHORTINT __STDCALL DeleteAtom (SHORTINT nAtom);
__EXTERN INTEGER __STDCALL DeleteColorSpace (INTEGER p0);
__EXTERN void __STDCALL DeleteCriticalSection (WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
__EXTERN INTEGER __STDCALL DeleteDC (INTEGER p0);
__EXTERN INTEGER __STDCALL DeleteEnhMetaFile (INTEGER p0);
__EXTERN void __STDCALL DeleteFiber (INTEGER lpFiber);
__EXTERN INTEGER __STDCALL DeleteFileA (INTEGER lpFileName);
__EXTERN INTEGER __STDCALL DeleteFileW (INTEGER lpFileName);
__EXTERN INTEGER __STDCALL DeleteFormA (INTEGER hPrinter, INTEGER pFormName);
__EXTERN INTEGER __STDCALL DeleteFormW (INTEGER hPrinter, INTEGER pFormName);
__EXTERN INTEGER __STDCALL DeleteMenu (INTEGER hMenu, INTEGER uPosition, SET uFlags);
__EXTERN INTEGER __STDCALL DeleteMetaFile (INTEGER p0);
__EXTERN INTEGER __STDCALL DeleteMonitorA (INTEGER pName, INTEGER pEnvironment, INTEGER pMonitorName);
__EXTERN INTEGER __STDCALL DeleteMonitorW (INTEGER pName, INTEGER pEnvironment, INTEGER pMonitorName);
__EXTERN INTEGER __STDCALL DeleteObject (INTEGER p0);
__EXTERN INTEGER __STDCALL DeletePortA (INTEGER pName, INTEGER hWnd, INTEGER pPortName);
__EXTERN INTEGER __STDCALL DeletePortW (INTEGER pName, INTEGER hWnd, INTEGER pPortName);
__EXTERN INTEGER __STDCALL DeletePrintProcessorA (INTEGER pName, INTEGER pEnvironment, INTEGER pPrintProcessorName);
__EXTERN INTEGER __STDCALL DeletePrintProcessorW (INTEGER pName, INTEGER pEnvironment, INTEGER pPrintProcessorName);
__EXTERN INTEGER __STDCALL DeletePrintProvidorA (INTEGER pName, INTEGER pEnvironment, INTEGER pPrintProvidorName);
__EXTERN INTEGER __STDCALL DeletePrintProvidorW (INTEGER pName, INTEGER pEnvironment, INTEGER pPrintProvidorName);
__EXTERN INTEGER __STDCALL DeletePrinter (INTEGER hPrinter);
__EXTERN INTEGER __STDCALL DeletePrinterConnectionA (INTEGER pName);
__EXTERN INTEGER __STDCALL DeletePrinterConnectionW (INTEGER pName);
__EXTERN INTEGER __STDCALL DeletePrinterDriverA (INTEGER pName, INTEGER pEnvironment, INTEGER pDriverName);
__EXTERN INTEGER __STDCALL DeletePrinterDriverW (INTEGER pName, INTEGER pEnvironment, INTEGER pDriverName);
__EXTERN INTEGER __STDCALL DeleteService (INTEGER hService);
__EXTERN INTEGER __STDCALL DeregisterEventSource (INTEGER hEventLog);
__EXTERN INTEGER __STDCALL DescribePixelFormat (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_PIXELFORMATDESCRIPTOR *p3);
__EXTERN INTEGER __STDCALL DestroyAcceleratorTable (INTEGER hAccel);
__EXTERN INTEGER __STDCALL DestroyCaret (void);
__EXTERN INTEGER __STDCALL DestroyCursor (INTEGER hCursor);
__EXTERN INTEGER __STDCALL DestroyIcon (INTEGER hIcon);
__EXTERN INTEGER __STDCALL DestroyMenu (INTEGER hMenu);
__EXTERN INTEGER __STDCALL DestroyPrivateObjectSecurity (INTEGER *ObjectDescriptor);
__EXTERN INTEGER __STDCALL DestroyPropertySheetPage (WinAPI_Ptr_PSP p0);
__EXTERN INTEGER __STDCALL DestroyWindow (INTEGER hWnd);
__EXTERN INTEGER __STDCALL DeviceCapabilitiesA (INTEGER p0, INTEGER p1, SHORTINT p2, INTEGER p3, WinAPI_DEVMODEA *p4);
__EXTERN INTEGER __STDCALL DeviceCapabilitiesW (INTEGER p0, INTEGER p1, SHORTINT p2, INTEGER p3, WinAPI_DEVMODEW *p4);
__EXTERN INTEGER __STDCALL DeviceIoControl (INTEGER hDevice, INTEGER dwIoControlCode, INTEGER lpInBuffer, INTEGER nInBufferSize, INTEGER lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesReturned, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL DialogBoxIndirectParamA (INTEGER hInstance, WinAPI_DLGTEMPLATE *hDialogTemplate, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
__EXTERN INTEGER __STDCALL DialogBoxIndirectParamW (INTEGER hInstance, WinAPI_DLGTEMPLATE *hDialogTemplate, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
__EXTERN INTEGER __STDCALL DialogBoxParamA (INTEGER hInstance, INTEGER lpTemplateName, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
__EXTERN INTEGER __STDCALL DialogBoxParamW (INTEGER hInstance, INTEGER lpTemplateName, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
__EXTERN INTEGER __STDCALL DisableThreadLibraryCalls (INTEGER hLibModule);
__EXTERN INTEGER __STDCALL DisconnectNamedPipe (INTEGER hNamedPipe);
__EXTERN INTEGER __STDCALL DispatchMessageA (WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL DispatchMessageW (WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL DlgDirListA (INTEGER hDlg, INTEGER lpPathSpec, INTEGER nIDListBox, INTEGER nIDStaticPath, SET uFileType);
__EXTERN INTEGER __STDCALL DlgDirListComboBoxA (INTEGER hDlg, INTEGER lpPathSpec, INTEGER nIDComboBox, INTEGER nIDStaticPath, INTEGER uFiletype);
__EXTERN INTEGER __STDCALL DlgDirListComboBoxW (INTEGER hDlg, INTEGER lpPathSpec, INTEGER nIDComboBox, INTEGER nIDStaticPath, INTEGER uFiletype);
__EXTERN INTEGER __STDCALL DlgDirListW (INTEGER hDlg, INTEGER lpPathSpec, INTEGER nIDListBox, INTEGER nIDStaticPath, SET uFileType);
__EXTERN INTEGER __STDCALL DlgDirSelectComboBoxExA (INTEGER hDlg, INTEGER lpString, INTEGER nCount, INTEGER nIDComboBox);
__EXTERN INTEGER __STDCALL DlgDirSelectComboBoxExW (INTEGER hDlg, INTEGER lpString, INTEGER nCount, INTEGER nIDComboBox);
__EXTERN INTEGER __STDCALL DlgDirSelectExA (INTEGER hDlg, INTEGER lpString, INTEGER nCount, INTEGER nIDListBox);
__EXTERN INTEGER __STDCALL DlgDirSelectExW (INTEGER hDlg, INTEGER lpString, INTEGER nCount, INTEGER nIDListBox);
__EXTERN INTEGER __STDCALL DoEnvironmentSubstA (INTEGER szString, INTEGER cbString);
__EXTERN INTEGER __STDCALL DoEnvironmentSubstW (INTEGER szString, INTEGER cbString);
__EXTERN INTEGER __STDCALL DocumentPropertiesA (INTEGER hWnd, INTEGER hPrinter, INTEGER pDeviceName, WinAPI_DEVMODEA *pDevModeOutput, WinAPI_DEVMODEA *pDevModeInput, SET fMode);
__EXTERN INTEGER __STDCALL DocumentPropertiesW (INTEGER hWnd, INTEGER hPrinter, INTEGER pDeviceName, WinAPI_DEVMODEW *pDevModeOutput, WinAPI_DEVMODEW *pDevModeInput, SET fMode);
__EXTERN INTEGER __STDCALL DosDateTimeToFileTime (SHORTINT wFatDate, SHORTINT wFatTime, WinAPI_FILETIME *lpFileTime);
__EXTERN void __STDCALL DragAcceptFiles (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL DragDetect (INTEGER p0, WinAPI_POINT *p1);
__EXTERN void __STDCALL DragFinish (INTEGER p0);
__EXTERN INTEGER __STDCALL DragObject (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL DragQueryFileA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL DragQueryFileW (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL DragQueryPoint (INTEGER p0, WinAPI_POINT *p1);
__EXTERN INTEGER __STDCALL DrawAnimatedRects (INTEGER hwnd, INTEGER idAni, WinAPI_RECT *lprcFrom, WinAPI_RECT *lprcTo);
__EXTERN INTEGER __STDCALL DrawCaption (INTEGER p0, INTEGER p1, WinAPI_RECT *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL DrawEdge (INTEGER hdc, WinAPI_RECT *qrc, SET edge, SET grfFlags);
__EXTERN INTEGER __STDCALL DrawEscape (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL DrawFocusRect (INTEGER hDC, WinAPI_RECT *lprc);
__EXTERN INTEGER __STDCALL DrawFrameControl (INTEGER p0, WinAPI_RECT *p1, INTEGER p2, SET p3);
__EXTERN INTEGER __STDCALL DrawIcon (INTEGER hDC, INTEGER X, INTEGER Y, INTEGER hIcon);
__EXTERN INTEGER __STDCALL DrawIconEx (INTEGER hdc, INTEGER xLeft, INTEGER yTop, INTEGER hIcon, INTEGER cxWidth, INTEGER cyWidth, INTEGER istepIfAniCur, INTEGER hbrFlickerFreeDraw, SET diFlags);
__EXTERN INTEGER __STDCALL DrawMenuBar (INTEGER hWnd);
__EXTERN INTEGER __STDCALL DrawStateA (INTEGER p0, INTEGER p1, WinAPI_DRAWSTATEPROC p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, SET p9);
__EXTERN INTEGER __STDCALL DrawStateW (INTEGER p0, INTEGER p1, WinAPI_DRAWSTATEPROC p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, SET p9);
__EXTERN INTEGER __STDCALL DrawTextA (INTEGER hDC, INTEGER lpString, INTEGER nCount, WinAPI_RECT *lpRect, SET uFormat);
__EXTERN INTEGER __STDCALL DrawTextExA (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_RECT *p3, INTEGER p4, WinAPI_DRAWTEXTPARAMS *p5);
__EXTERN INTEGER __STDCALL DrawTextExW (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_RECT *p3, INTEGER p4, WinAPI_DRAWTEXTPARAMS *p5);
__EXTERN INTEGER __STDCALL DrawTextW (INTEGER hDC, INTEGER lpString, INTEGER nCount, WinAPI_RECT *lpRect, SET uFormat);
__EXTERN INTEGER __STDCALL DuplicateHandle (INTEGER hSourceProcessHandle, INTEGER hSourceHandle, INTEGER hTargetProcessHandle, INTEGER *lpTargetHandle, SET dwDesiredAccess, INTEGER bInheritHandle, SET dwOptions);
__EXTERN INTEGER __STDCALL DuplicateIcon (INTEGER hInst, INTEGER hIcon);
__EXTERN INTEGER __STDCALL DuplicateToken (INTEGER ExistingTokenHandle, INTEGER ImpersonationLevel, INTEGER *DuplicateTokenHandle);
__EXTERN INTEGER __STDCALL Ellipse (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL EmptyClipboard (void);
__EXTERN INTEGER __STDCALL EnableMenuItem (INTEGER hMenu, INTEGER uIDEnableItem, SET uEnable);
__EXTERN INTEGER __STDCALL EnableScrollBar (INTEGER hWnd, INTEGER wSBflags, INTEGER wArrows);
__EXTERN INTEGER __STDCALL EnableWindow (INTEGER hWnd, INTEGER bEnable);
__EXTERN INTEGER __STDCALL EndDeferWindowPos (INTEGER hWinPosInfo);
__EXTERN INTEGER __STDCALL EndDialog (INTEGER hDlg, INTEGER nResult);
__EXTERN INTEGER __STDCALL EndDoc (INTEGER p0);
__EXTERN INTEGER __STDCALL EndDocPrinter (INTEGER hPrinter);
__EXTERN INTEGER __STDCALL EndPage (INTEGER p0);
__EXTERN INTEGER __STDCALL EndPagePrinter (INTEGER hPrinter);
__EXTERN INTEGER __STDCALL EndPaint (INTEGER hWnd, WinAPI_PAINTSTRUCT *lpPaint);
__EXTERN INTEGER __STDCALL EndPath (INTEGER p0);
__EXTERN INTEGER __STDCALL EndUpdateResourceA (INTEGER hUpdate, INTEGER fDiscard);
__EXTERN INTEGER __STDCALL EndUpdateResourceW (INTEGER hUpdate, INTEGER fDiscard);
__EXTERN void __STDCALL EnterCriticalSection (WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
__EXTERN INTEGER __STDCALL EnumCalendarInfoA (WinAPI_CALINFO_ENUMPROCA lpCalInfoEnumProc, INTEGER Locale, INTEGER Calendar, INTEGER CalType);
__EXTERN INTEGER __STDCALL EnumCalendarInfoW (WinAPI_CALINFO_ENUMPROCW lpCalInfoEnumProc, INTEGER Locale, INTEGER Calendar, INTEGER CalType);
__EXTERN INTEGER __STDCALL EnumChildWindows (INTEGER hWndParent, WinAPI_WNDENUMPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumClipboardFormats (INTEGER format);
__EXTERN INTEGER __STDCALL EnumDateFormatsA (WinAPI_DATEFMT_ENUMPROCA lpDateFmtEnumProc, INTEGER Locale, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumDateFormatsW (WinAPI_DATEFMT_ENUMPROCW lpDateFmtEnumProc, INTEGER Locale, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumDependentServicesA (INTEGER hService, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSA *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned);
__EXTERN INTEGER __STDCALL EnumDependentServicesW (INTEGER hService, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSW *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned);
__EXTERN INTEGER __STDCALL EnumDesktopWindows (INTEGER hDesktop, WinAPI_WNDENUMPROC lpfn, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumDesktopsA (INTEGER hwinsta, WinAPI_DESKTOPENUMPROCA lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumDesktopsW (INTEGER hwinsta, WinAPI_DESKTOPENUMPROCW lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumDisplaySettingsA (INTEGER lpszDeviceName, INTEGER iModeNum, WinAPI_DEVMODEA *lpDevMode);
__EXTERN INTEGER __STDCALL EnumDisplaySettingsW (INTEGER lpszDeviceName, INTEGER iModeNum, WinAPI_DEVMODEW *lpDevMode);
__EXTERN INTEGER __STDCALL EnumEnhMetaFile (INTEGER p0, INTEGER p1, WinAPI_ENHMFENUMPROC p2, INTEGER p3, WinAPI_RECT *p4);
__EXTERN INTEGER __STDCALL EnumFontFamiliesA (INTEGER p0, INTEGER p1, WinAPI_NEWFONTENUMPROCA p2, INTEGER p3);
__EXTERN INTEGER __STDCALL EnumFontFamiliesExA (INTEGER p0, WinAPI_LOGFONTA *p1, WinAPI_FONTENUMPROCEXA p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL EnumFontFamiliesExW (INTEGER p0, WinAPI_LOGFONTW *p1, WinAPI_FONTENUMPROCEXW p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL EnumFontFamiliesW (INTEGER p0, INTEGER p1, WinAPI_NEWFONTENUMPROCW p2, INTEGER p3);
__EXTERN INTEGER __STDCALL EnumFontsA (INTEGER p0, INTEGER p1, WinAPI_FONTENUMPROCA p2, INTEGER p3);
__EXTERN INTEGER __STDCALL EnumFontsW (INTEGER p0, INTEGER p1, WinAPI_FONTENUMPROCW p2, INTEGER p3);
__EXTERN INTEGER __STDCALL EnumFormsA (INTEGER hPrinter, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumFormsW (INTEGER hPrinter, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumICMProfilesA (INTEGER p0, WinAPI_ICMENUMPROCA p1, INTEGER p2);
__EXTERN INTEGER __STDCALL EnumICMProfilesW (INTEGER p0, WinAPI_ICMENUMPROCW p1, INTEGER p2);
__EXTERN INTEGER __STDCALL EnumJobsA (INTEGER hPrinter, INTEGER FirstJob, INTEGER NoJobs, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumJobsW (INTEGER hPrinter, INTEGER FirstJob, INTEGER NoJobs, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumMetaFile (INTEGER p0, INTEGER p1, WinAPI_MFENUMPROC p2, INTEGER p3);
__EXTERN INTEGER __STDCALL EnumMonitorsA (INTEGER pName, INTEGER Level, CHAR *pMonitors, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumMonitorsW (INTEGER pName, INTEGER Level, CHAR *pMonitors, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumObjects (INTEGER p0, INTEGER p1, WinAPI_GOBJENUMPROC p2, INTEGER p3);
__EXTERN INTEGER __STDCALL EnumPortsA (INTEGER pName, INTEGER Level, CHAR *pPorts, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPortsW (INTEGER pName, INTEGER Level, CHAR *pPorts, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrintProcessorDatatypesA (INTEGER pName, INTEGER pPrintProcessorName, INTEGER Level, CHAR *pDatatypes, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrintProcessorDatatypesW (INTEGER pName, INTEGER pPrintProcessorName, INTEGER Level, CHAR *pDatatypes, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrintProcessorsA (INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrintProcessorsW (INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrinterDriversA (INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrinterDriversW (INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrintersA (SET Flags, INTEGER Name, INTEGER Level, CHAR *pPrinterEnum, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPrintersW (SET Flags, INTEGER Name, INTEGER Level, CHAR *pPrinterEnum, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
__EXTERN INTEGER __STDCALL EnumPropsA (INTEGER hWnd, WinAPI_ROPENUMPROCA lpEnumFunc);
__EXTERN INTEGER __STDCALL EnumPropsExA (INTEGER hWnd, WinAPI_ROPENUMPROCEXA lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumPropsExW (INTEGER hWnd, WinAPI_ROPENUMPROCEXW lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumPropsW (INTEGER hWnd, WinAPI_ROPENUMPROCW lpEnumFunc);
__EXTERN INTEGER __STDCALL EnumResourceLanguagesA (INTEGER hModule, INTEGER lpType, INTEGER lpName, WinAPI_ENUMRESLANGPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumResourceLanguagesW (INTEGER hModule, INTEGER lpType, INTEGER lpName, WinAPI_ENUMRESLANGPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumResourceNamesA (INTEGER hModule, INTEGER lpType, WinAPI_ENUMRESNAMEPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumResourceNamesW (INTEGER hModule, INTEGER lpType, WinAPI_ENUMRESNAMEPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumResourceTypesA (INTEGER hModule, WinAPI_ENUMRESTYPEPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumResourceTypesW (INTEGER hModule, WinAPI_ENUMRESTYPEPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumServicesStatusA (INTEGER hSCManager, SET dwServiceType, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSA *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned, INTEGER *lpResumeHandle);
__EXTERN INTEGER __STDCALL EnumServicesStatusW (INTEGER hSCManager, SET dwServiceType, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSW *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned, INTEGER *lpResumeHandle);
__EXTERN INTEGER __STDCALL EnumSystemCodePagesA (WinAPI_CODEPAGE_ENUMPROCA lpCodePageEnumProc, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumSystemCodePagesW (WinAPI_CODEPAGE_ENUMPROCW lpCodePageEnumProc, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumSystemLocalesA (WinAPI_LOCALE_ENUMPROCA lpLocaleEnumProc, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumSystemLocalesW (WinAPI_LOCALE_ENUMPROCW lpLocaleEnumProc, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumThreadWindows (INTEGER dwThreadId, WinAPI_WNDENUMPROC lpfn, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumTimeFormatsA (WinAPI_TIMEFMT_ENUMPROCA lpTimeFmtEnumProc, INTEGER Locale, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumTimeFormatsW (WinAPI_TIMEFMT_ENUMPROCW lpTimeFmtEnumProc, INTEGER Locale, SET dwFlags);
__EXTERN INTEGER __STDCALL EnumWindowStationsA (WinAPI_WINSTAENUMPROCA lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumWindowStationsW (WinAPI_WINSTAENUMPROCW lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EnumWindows (WinAPI_WNDENUMPROC lpEnumFunc, INTEGER lParam);
__EXTERN INTEGER __STDCALL EqualPrefixSid (INTEGER pSid1, INTEGER pSid2);
__EXTERN INTEGER __STDCALL EqualRect (WinAPI_RECT *lprc1, WinAPI_RECT *lprc2);
__EXTERN INTEGER __STDCALL EqualRgn (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL EqualSid (INTEGER pSid1, INTEGER pSid2);
__EXTERN INTEGER __STDCALL EraseTape (INTEGER hDevice, INTEGER dwEraseType, INTEGER bImmediate);
__EXTERN INTEGER __STDCALL Escape (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL EscapeCommFunction (INTEGER hFile, INTEGER dwFunc);
__EXTERN INTEGER __STDCALL ExcludeClipRect (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL ExcludeUpdateRgn (INTEGER hDC, INTEGER hWnd);
__EXTERN void __STDCALL ExitProcess (INTEGER uExitCode);
__EXTERN void __STDCALL ExitThread (INTEGER dwExitCode);
__EXTERN INTEGER __STDCALL ExitWindowsEx (SET uFlags, INTEGER dwReserved);
__EXTERN INTEGER __STDCALL ExpandEnvironmentStringsA (INTEGER lpSrc, INTEGER lpDst, INTEGER nSize);
__EXTERN INTEGER __STDCALL ExpandEnvironmentStringsW (INTEGER lpSrc, INTEGER lpDst, INTEGER nSize);
__EXTERN INTEGER __STDCALL ExtCreatePen (INTEGER p0, INTEGER p1, WinAPI_LOGBRUSH *p2, INTEGER p3, INTEGER *p4);
__EXTERN INTEGER __STDCALL ExtCreateRegion (WinAPI_XFORM *p0, INTEGER p1, WinAPI_RGNDATA *p2);
__EXTERN INTEGER __STDCALL ExtEscape (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
__EXTERN INTEGER __STDCALL ExtFloodFill (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL ExtSelectClipRgn (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL ExtTextOutA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_RECT *p4, INTEGER p5, INTEGER p6, INTEGER *p7);
__EXTERN INTEGER __STDCALL ExtTextOutW (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_RECT *p4, INTEGER p5, INTEGER p6, INTEGER *p7);
__EXTERN INTEGER __STDCALL ExtractAssociatedIconA (INTEGER hInst, INTEGER lpIconPath, SHORTINT *lpiIcon);
__EXTERN INTEGER __STDCALL ExtractAssociatedIconW (INTEGER hInst, INTEGER lpIconPath, SHORTINT *lpiIcon);
__EXTERN INTEGER __STDCALL ExtractIconA (INTEGER hInst, INTEGER lpszExeFileName, INTEGER nIconIndex);
__EXTERN INTEGER __STDCALL ExtractIconExA (INTEGER lpszFile, INTEGER nIconIndex, INTEGER *phiconLarge, INTEGER *phiconSmall, INTEGER nIcons);
__EXTERN INTEGER __STDCALL ExtractIconExW (INTEGER lpszFile, INTEGER nIconIndex, INTEGER *phiconLarge, INTEGER *phiconSmall, INTEGER nIcons);
__EXTERN INTEGER __STDCALL ExtractIconW (INTEGER hInst, INTEGER lpszExeFileName, INTEGER nIconIndex);
__EXTERN void __STDCALL FatalAppExitA (INTEGER uAction, INTEGER lpMessageText);
__EXTERN void __STDCALL FatalAppExitW (INTEGER uAction, INTEGER lpMessageText);
__EXTERN void __STDCALL FatalExit (INTEGER ExitCode);
__EXTERN INTEGER __STDCALL FileTimeToDosDateTime (WinAPI_FILETIME *lpFileTime, SHORTINT *lpFatDate, SHORTINT *lpFatTime);
__EXTERN INTEGER __STDCALL FileTimeToLocalFileTime (WinAPI_FILETIME *lpFileTime, WinAPI_FILETIME *lpLocalFileTime);
__EXTERN INTEGER __STDCALL FileTimeToSystemTime (WinAPI_FILETIME *lpFileTime, WinAPI_SYSTEMTIME *lpSystemTime);
__EXTERN INTEGER __STDCALL FillConsoleOutputAttribute (INTEGER hConsoleOutput, SHORTINT wAttribute, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfAttrsWritten);
__EXTERN INTEGER __STDCALL FillConsoleOutputCharacterA (INTEGER hConsoleOutput, CHAR cCharacter, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
__EXTERN INTEGER __STDCALL FillConsoleOutputCharacterW (INTEGER hConsoleOutput, SHORTINT cCharacter, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
__EXTERN INTEGER __STDCALL FillPath (INTEGER p0);
__EXTERN INTEGER __STDCALL FillRect (INTEGER hDC, WinAPI_RECT *lprc, INTEGER hbr);
__EXTERN INTEGER __STDCALL FillRgn (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN SHORTINT __STDCALL FindAtomA (INTEGER lpString);
__EXTERN SHORTINT __STDCALL FindAtomW (INTEGER lpString);
__EXTERN INTEGER __STDCALL FindClose (INTEGER hFindFile);
__EXTERN INTEGER __STDCALL FindCloseChangeNotification (INTEGER hChangeHandle);
__EXTERN INTEGER __STDCALL FindClosePrinterChangeNotification (INTEGER hChange);
__EXTERN INTEGER __STDCALL FindExecutableA (INTEGER lpFile, INTEGER lpDirectory, INTEGER lpResult);
__EXTERN INTEGER __STDCALL FindExecutableW (INTEGER lpFile, INTEGER lpDirectory, INTEGER lpResult);
__EXTERN INTEGER __STDCALL FindFirstChangeNotificationA (INTEGER lpPathName, INTEGER bWatchSubtree, SET dwNotifyFilter);
__EXTERN INTEGER __STDCALL FindFirstChangeNotificationW (INTEGER lpPathName, INTEGER bWatchSubtree, SET dwNotifyFilter);
__EXTERN INTEGER __STDCALL FindFirstFileA (INTEGER lpFileName, WinAPI_WIN32_FIND_DATAA *lpFindFileData);
__EXTERN INTEGER __STDCALL FindFirstFileExA (INTEGER lpFileName, INTEGER fInfoLevelId, INTEGER lpFindFileData, INTEGER fSearchOp, INTEGER lpSearchFilter, INTEGER dwAdditionalFlags);
__EXTERN INTEGER __STDCALL FindFirstFileExW (INTEGER lpFileName, INTEGER fInfoLevelId, INTEGER lpFindFileData, INTEGER fSearchOp, INTEGER lpSearchFilter, INTEGER dwAdditionalFlags);
__EXTERN INTEGER __STDCALL FindFirstFileW (INTEGER lpFileName, WinAPI_WIN32_FIND_DATAW *lpFindFileData);
__EXTERN INTEGER __STDCALL FindFirstFreeAce (WinAPI_ACL *pAcl, INTEGER pAce);
__EXTERN INTEGER __STDCALL FindFirstPrinterChangeNotification (INTEGER hPrinter, SET fdwFlags, INTEGER fdwOptions, INTEGER pPrinterNotifyOptions);
__EXTERN INTEGER __STDCALL FindNextChangeNotification (INTEGER hChangeHandle);
__EXTERN INTEGER __STDCALL FindNextFileA (INTEGER hFindFile, WinAPI_WIN32_FIND_DATAA *lpFindFileData);
__EXTERN INTEGER __STDCALL FindNextFileW (INTEGER hFindFile, WinAPI_WIN32_FIND_DATAW *lpFindFileData);
__EXTERN INTEGER __STDCALL FindNextPrinterChangeNotification (INTEGER hChange, INTEGER *pdwChange, INTEGER pvReserved, INTEGER ppPrinterNotifyInfo);
__EXTERN INTEGER __STDCALL FindResourceA (INTEGER hModule, INTEGER lpName, INTEGER lpType);
__EXTERN INTEGER __STDCALL FindResourceExA (INTEGER hModule, INTEGER lpType, INTEGER lpName, SHORTINT wLanguage);
__EXTERN INTEGER __STDCALL FindResourceExW (INTEGER hModule, INTEGER lpType, INTEGER lpName, SHORTINT wLanguage);
__EXTERN INTEGER __STDCALL FindResourceW (INTEGER hModule, INTEGER lpName, INTEGER lpType);
__EXTERN INTEGER __STDCALL FindWindowA (INTEGER lpClassName, INTEGER lpWindowName);
__EXTERN INTEGER __STDCALL FindWindowExA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL FindWindowExW (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL FindWindowW (INTEGER lpClassName, INTEGER lpWindowName);
__EXTERN INTEGER __STDCALL FixBrushOrgEx (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN INTEGER __STDCALL FlashWindow (INTEGER hWnd, INTEGER bInvert);
__EXTERN INTEGER __STDCALL FlattenPath (INTEGER p0);
__EXTERN INTEGER __STDCALL FloodFill (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL FlushConsoleInputBuffer (INTEGER hConsoleInput);
__EXTERN INTEGER __STDCALL FlushFileBuffers (INTEGER hFile);
__EXTERN INTEGER __STDCALL FlushInstructionCache (INTEGER hProcess, INTEGER lpBaseAddress, INTEGER dwSize);
__EXTERN INTEGER __STDCALL FlushViewOfFile (INTEGER lpBaseAddress, INTEGER dwNumberOfBytesToFlush);
__EXTERN INTEGER __STDCALL FoldStringA (SET dwMapFlags, INTEGER lpSrcStr, INTEGER cchSrc, INTEGER lpDestStr, INTEGER cchDest);
__EXTERN INTEGER __STDCALL FoldStringW (SET dwMapFlags, INTEGER lpSrcStr, INTEGER cchSrc, INTEGER lpDestStr, INTEGER cchDest);
__EXTERN INTEGER __STDCALL FormatMessageA (SET dwFlags, INTEGER lpSource, INTEGER dwMessageId, INTEGER dwLanguageId, INTEGER lpBuffer, INTEGER nSize, INTEGER *Arguments);
__EXTERN INTEGER __STDCALL FormatMessageW (SET dwFlags, INTEGER lpSource, INTEGER dwMessageId, INTEGER dwLanguageId, INTEGER lpBuffer, INTEGER nSize, INTEGER *Arguments);
__EXTERN INTEGER __STDCALL FrameRect (INTEGER hDC, WinAPI_RECT *lprc, INTEGER hbr);
__EXTERN INTEGER __STDCALL FrameRgn (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL FreeConsole (void);
__EXTERN INTEGER __STDCALL FreeDDElParam (INTEGER msg, INTEGER lParam);
__EXTERN INTEGER __STDCALL FreeEnvironmentStringsA (INTEGER p0);
__EXTERN INTEGER __STDCALL FreeEnvironmentStringsW (INTEGER p0);
__EXTERN INTEGER __STDCALL FreeLibrary (INTEGER hLibModule);
__EXTERN void __STDCALL FreeLibraryAndExitThread (INTEGER hLibModule, INTEGER dwExitCode);
__EXTERN INTEGER __STDCALL FreePrinterNotifyInfo (WinAPI_PRINTER_NOTIFY_INFO *pPrinterNotifyInfo);
__EXTERN INTEGER __STDCALL FreeResource (INTEGER hResData);
__EXTERN INTEGER __STDCALL FreeSid (INTEGER pSid);
__EXTERN INTEGER __STDCALL GdiComment (INTEGER p0, INTEGER p1, CHAR *p2);
__EXTERN INTEGER __STDCALL GdiFlush (void);
__EXTERN INTEGER __STDCALL GdiGetBatchLimit (void);
__EXTERN INTEGER __STDCALL GdiSetBatchLimit (INTEGER p0);
__EXTERN INTEGER __STDCALL GenerateConsoleCtrlEvent (INTEGER dwCtrlEvent, INTEGER dwProcessGroupId);
__EXTERN INTEGER __STDCALL GetACP (void);
__EXTERN INTEGER __STDCALL GetAce (WinAPI_ACL *pAcl, INTEGER dwAceIndex, INTEGER pAce);
__EXTERN INTEGER __STDCALL GetAclInformation (WinAPI_ACL *pAcl, INTEGER pAclInformation, INTEGER nAclInformationLength, INTEGER dwAclInformationClass);
__EXTERN INTEGER __STDCALL GetActiveWindow (void);
__EXTERN INTEGER __STDCALL GetArcDirection (INTEGER p0);
__EXTERN INTEGER __STDCALL GetAspectRatioFilterEx (INTEGER p0, WinAPI_SIZE *p1);
__EXTERN SHORTINT __STDCALL GetAsyncKeyState (INTEGER vKey);
__EXTERN INTEGER __STDCALL GetAtomNameA (SHORTINT nAtom, INTEGER lpBuffer, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetAtomNameW (SHORTINT nAtom, INTEGER lpBuffer, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetBinaryTypeA (INTEGER lpApplicationName, INTEGER *lpBinaryType);
__EXTERN INTEGER __STDCALL GetBinaryTypeW (INTEGER lpApplicationName, INTEGER *lpBinaryType);
__EXTERN INTEGER __STDCALL GetBitmapBits (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetBitmapDimensionEx (INTEGER p0, WinAPI_SIZE *p1);
__EXTERN INTEGER __STDCALL GetBkColor (INTEGER p0);
__EXTERN INTEGER __STDCALL GetBkMode (INTEGER p0);
__EXTERN SET __STDCALL GetBoundsRect (INTEGER p0, WinAPI_RECT *p1, SET p2);
__EXTERN INTEGER __STDCALL GetBrushOrgEx (INTEGER p0, WinAPI_POINT *p1);
__EXTERN INTEGER __STDCALL GetCPInfo (INTEGER CodePage, WinAPI_CPINFO *lpCPInfo);
__EXTERN INTEGER __STDCALL GetCapture (void);
__EXTERN INTEGER __STDCALL GetCaretBlinkTime (void);
__EXTERN INTEGER __STDCALL GetCaretPos (WinAPI_POINT *lpPoint);
__EXTERN INTEGER __STDCALL GetCharABCWidthsA (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_ABC *p3);
__EXTERN INTEGER __STDCALL GetCharABCWidthsFloatA (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_ABCFLOAT *p3);
__EXTERN INTEGER __STDCALL GetCharABCWidthsFloatW (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_ABCFLOAT *p3);
__EXTERN INTEGER __STDCALL GetCharABCWidthsW (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_ABC *p3);
__EXTERN INTEGER __STDCALL GetCharWidth32A (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER *p3);
__EXTERN INTEGER __STDCALL GetCharWidth32W (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER *p3);
__EXTERN INTEGER __STDCALL GetCharWidthA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER *p3);
__EXTERN INTEGER __STDCALL GetCharWidthFloatA (INTEGER p0, INTEGER p1, INTEGER p2, SHORTREAL *p3);
__EXTERN INTEGER __STDCALL GetCharWidthFloatW (INTEGER p0, INTEGER p1, INTEGER p2, SHORTREAL *p3);
__EXTERN INTEGER __STDCALL GetCharWidthW (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER *p3);
__EXTERN INTEGER __STDCALL GetCharacterPlacementA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_GCP_RESULTSA *p4, INTEGER p5);
__EXTERN INTEGER __STDCALL GetCharacterPlacementW (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_GCP_RESULTSW *p4, INTEGER p5);
__EXTERN INTEGER __STDCALL GetClassInfoA (INTEGER hInstance, INTEGER lpClassName, WinAPI_WNDCLASSA *lpWndClass);
__EXTERN INTEGER __STDCALL GetClassInfoExA (INTEGER p0, INTEGER p1, WinAPI_WNDCLASSEXA *p2);
__EXTERN INTEGER __STDCALL GetClassInfoExW (INTEGER p0, INTEGER p1, WinAPI_WNDCLASSEXW *p2);
__EXTERN INTEGER __STDCALL GetClassInfoW (INTEGER hInstance, INTEGER lpClassName, WinAPI_WNDCLASSW *lpWndClass);
__EXTERN INTEGER __STDCALL GetClassLongA (INTEGER hWnd, INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetClassLongW (INTEGER hWnd, INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetClassNameA (INTEGER hWnd, INTEGER lpClassName, INTEGER nMaxCount);
__EXTERN INTEGER __STDCALL GetClassNameW (INTEGER hWnd, INTEGER lpClassName, INTEGER nMaxCount);
__EXTERN SHORTINT __STDCALL GetClassWord (INTEGER hWnd, INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetClientRect (INTEGER hWnd, WinAPI_RECT *lpRect);
__EXTERN INTEGER __STDCALL GetClipBox (INTEGER p0, WinAPI_RECT *p1);
__EXTERN INTEGER __STDCALL GetClipCursor (WinAPI_RECT *lpRect);
__EXTERN INTEGER __STDCALL GetClipRgn (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetClipboardData (INTEGER uFormat);
__EXTERN INTEGER __STDCALL GetClipboardFormatNameA (INTEGER format, INTEGER lpszFormatName, INTEGER cchMaxCount);
__EXTERN INTEGER __STDCALL GetClipboardFormatNameW (INTEGER format, INTEGER lpszFormatName, INTEGER cchMaxCount);
__EXTERN INTEGER __STDCALL GetClipboardOwner (void);
__EXTERN INTEGER __STDCALL GetClipboardViewer (void);
__EXTERN INTEGER __STDCALL GetColorAdjustment (INTEGER p0, WinAPI_COLORADJUSTMENT *p1);
__EXTERN INTEGER __STDCALL GetColorSpace (INTEGER p0);
__EXTERN INTEGER __STDCALL GetCommConfig (INTEGER hCommDev, WinAPI_COMMCONFIG *lpCC, INTEGER *lpdwSize);
__EXTERN INTEGER __STDCALL GetCommMask (INTEGER hFile, SET *lpEvtMask);
__EXTERN INTEGER __STDCALL GetCommModemStatus (INTEGER hFile, SET *lpModemStat);
__EXTERN INTEGER __STDCALL GetCommProperties (INTEGER hFile, WinAPI_COMMPROP *lpCommProp);
__EXTERN INTEGER __STDCALL GetCommState (INTEGER hFile, WinAPI_DCB *lpDCB);
__EXTERN INTEGER __STDCALL GetCommTimeouts (INTEGER hFile, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
__EXTERN INTEGER __STDCALL GetCommandLineA (void);
__EXTERN INTEGER __STDCALL GetCommandLineW (void);
__EXTERN INTEGER __STDCALL GetCompressedFileSizeA (INTEGER lpFileName, INTEGER *lpFileSizeHigh);
__EXTERN INTEGER __STDCALL GetCompressedFileSizeW (INTEGER lpFileName, INTEGER *lpFileSizeHigh);
__EXTERN INTEGER __STDCALL GetComputerNameA (INTEGER lpBuffer, INTEGER *nSize);
__EXTERN INTEGER __STDCALL GetComputerNameW (INTEGER lpBuffer, INTEGER *nSize);
__EXTERN INTEGER __STDCALL GetConsoleCP (void);
__EXTERN INTEGER __STDCALL GetConsoleCursorInfo (INTEGER hConsoleOutput, WinAPI_CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
__EXTERN INTEGER __STDCALL GetConsoleMode (INTEGER hConsoleHandle, SET *lpMode);
__EXTERN INTEGER __STDCALL GetConsoleOutputCP (void);
__EXTERN INTEGER __STDCALL GetConsoleScreenBufferInfo (INTEGER hConsoleOutput, WinAPI_CONSOLE_SCREEN_BUFFER_INFO *lpConsoleScreenBufferInfo);
__EXTERN INTEGER __STDCALL GetConsoleTitleA (INTEGER lpConsoleTitle, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetConsoleTitleW (INTEGER lpConsoleTitle, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetCurrencyFormatA (INTEGER Locale, SET dwFlags, INTEGER lpValue, WinAPI_CURRENCYFMTA *lpFormat, INTEGER lpCurrencyStr, INTEGER cchCurrency);
__EXTERN INTEGER __STDCALL GetCurrencyFormatW (INTEGER Locale, SET dwFlags, INTEGER lpValue, WinAPI_CURRENCYFMTW *lpFormat, INTEGER lpCurrencyStr, INTEGER cchCurrency);
__EXTERN INTEGER __STDCALL GetCurrentDirectoryA (INTEGER nBufferLength, INTEGER lpBuffer);
__EXTERN INTEGER __STDCALL GetCurrentDirectoryW (INTEGER nBufferLength, INTEGER lpBuffer);
__EXTERN INTEGER __STDCALL GetCurrentHwProfileA (WinAPI_HW_PROFILE_INFOA *lpHwProfileInfo);
__EXTERN INTEGER __STDCALL GetCurrentHwProfileW (WinAPI_HW_PROFILE_INFOW *lpHwProfileInfo);
__EXTERN INTEGER __STDCALL GetCurrentObject (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetCurrentPositionEx (INTEGER p0, WinAPI_POINT *p1);
__EXTERN INTEGER __STDCALL GetCurrentProcess (void);
__EXTERN INTEGER __STDCALL GetCurrentProcessId (void);
__EXTERN INTEGER __STDCALL GetCurrentThread (void);
__EXTERN INTEGER __STDCALL GetCurrentThreadId (void);
__EXTERN INTEGER __STDCALL GetCursor (void);
__EXTERN INTEGER __STDCALL GetCursorPos (WinAPI_POINT *lpPoint);
__EXTERN INTEGER __STDCALL GetDC (INTEGER hWnd);
__EXTERN INTEGER __STDCALL GetDCEx (INTEGER hWnd, INTEGER hrgnClip, SET flags);
__EXTERN INTEGER __STDCALL GetDCOrgEx (INTEGER p0, WinAPI_POINT *p1);
__EXTERN INTEGER __STDCALL GetDIBColorTable (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_RGBQUAD *p3);
__EXTERN INTEGER __STDCALL GetDIBits (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_BITMAPINFO *p5, INTEGER p6);
__EXTERN INTEGER __STDCALL GetDateFormatA (INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpDate, INTEGER lpFormat, INTEGER lpDateStr, INTEGER cchDate);
__EXTERN INTEGER __STDCALL GetDateFormatW (INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpDate, INTEGER lpFormat, INTEGER lpDateStr, INTEGER cchDate);
__EXTERN INTEGER __STDCALL GetDefaultCommConfigA (INTEGER lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER *lpdwSize);
__EXTERN INTEGER __STDCALL GetDefaultCommConfigW (INTEGER lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER *lpdwSize);
__EXTERN INTEGER __STDCALL GetDesktopWindow (void);
__EXTERN INTEGER __STDCALL GetDeviceCaps (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetDeviceGammaRamp (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetDialogBaseUnits (void);
__EXTERN INTEGER __STDCALL GetDiskFreeSpaceA (INTEGER lpRootPathName, INTEGER *lpSectorsPerCluster, INTEGER *lpBytesPerSector, INTEGER *lpNumberOfFreeClusters, INTEGER *lpTotalNumberOfClusters);
__EXTERN INTEGER __STDCALL GetDiskFreeSpaceW (INTEGER lpRootPathName, INTEGER *lpSectorsPerCluster, INTEGER *lpBytesPerSector, INTEGER *lpNumberOfFreeClusters, INTEGER *lpTotalNumberOfClusters);
__EXTERN INTEGER __STDCALL GetDlgCtrlID (INTEGER hWnd);
__EXTERN INTEGER __STDCALL GetDlgItem (INTEGER hDlg, INTEGER nIDDlgItem);
__EXTERN INTEGER __STDCALL GetDlgItemInt (INTEGER hDlg, INTEGER nIDDlgItem, INTEGER *lpTranslated, INTEGER bSigned);
__EXTERN INTEGER __STDCALL GetDlgItemTextA (INTEGER hDlg, INTEGER nIDDlgItem, INTEGER lpString, INTEGER nMaxCount);
__EXTERN INTEGER __STDCALL GetDlgItemTextW (INTEGER hDlg, INTEGER nIDDlgItem, INTEGER lpString, INTEGER nMaxCount);
__EXTERN INTEGER __STDCALL GetDoubleClickTime (void);
__EXTERN INTEGER __STDCALL GetDriveTypeA (INTEGER lpRootPathName);
__EXTERN INTEGER __STDCALL GetDriveTypeW (INTEGER lpRootPathName);
__EXTERN INTEGER __STDCALL GetEnhMetaFileA (INTEGER p0);
__EXTERN INTEGER __STDCALL GetEnhMetaFileBits (INTEGER p0, INTEGER p1, CHAR *p2);
__EXTERN INTEGER __STDCALL GetEnhMetaFileDescriptionA (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetEnhMetaFileDescriptionW (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetEnhMetaFileHeader (INTEGER p0, INTEGER p1, WinAPI_ENHMETAHEADER *p2);
__EXTERN INTEGER __STDCALL GetEnhMetaFilePaletteEntries (INTEGER p0, INTEGER p1, WinAPI_PALETTEENTRY *p2);
__EXTERN INTEGER __STDCALL GetEnhMetaFilePixelFormat (INTEGER p0, INTEGER p1, WinAPI_PIXELFORMATDESCRIPTOR *p2);
__EXTERN INTEGER __STDCALL GetEnhMetaFileW (INTEGER p0);
__EXTERN INTEGER __STDCALL GetEnvironmentStrings (void);
__EXTERN INTEGER __STDCALL GetEnvironmentStringsW (void);
__EXTERN INTEGER __STDCALL GetEnvironmentVariableA (INTEGER lpName, INTEGER lpBuffer, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetEnvironmentVariableW (INTEGER lpName, INTEGER lpBuffer, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetExitCodeProcess (INTEGER hProcess, INTEGER *lpExitCode);
__EXTERN INTEGER __STDCALL GetExitCodeThread (INTEGER hThread, INTEGER *lpExitCode);
__EXTERN INTEGER __STDCALL GetExpandedNameA (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetExpandedNameW (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetFileAttributesA (INTEGER lpFileName);
__EXTERN INTEGER __STDCALL GetFileAttributesW (INTEGER lpFileName);
__EXTERN INTEGER __STDCALL GetFileInformationByHandle (INTEGER hFile, WinAPI_BY_HANDLE_FILE_INFORMATION *lpFileInformation);
__EXTERN INTEGER __STDCALL GetFileSecurityA (INTEGER lpFileName, SET RequestedInformation, INTEGER pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
__EXTERN INTEGER __STDCALL GetFileSecurityW (INTEGER lpFileName, SET RequestedInformation, INTEGER pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
__EXTERN INTEGER __STDCALL GetFileSize (INTEGER hFile, INTEGER *lpFileSizeHigh);
__EXTERN INTEGER __STDCALL GetFileSizeEx (INTEGER hFile, LONGINT *lpFileSizeHigh);
__EXTERN INTEGER __STDCALL GetFileTime (INTEGER hFile, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpLastAccessTime, WinAPI_FILETIME *lpLastWriteTime);
__EXTERN INTEGER __STDCALL GetFileType (INTEGER hFile);
__EXTERN INTEGER __STDCALL GetFileVersionInfoA (INTEGER lptstrFilename, INTEGER dwHandle, INTEGER dwLen, INTEGER lpData);
__EXTERN INTEGER __STDCALL GetFileVersionInfoSizeA (INTEGER lptstrFilename, INTEGER *lpdwHandle);
__EXTERN INTEGER __STDCALL GetFileVersionInfoSizeW (INTEGER lptstrFilename, INTEGER *lpdwHandle);
__EXTERN INTEGER __STDCALL GetFileVersionInfoW (INTEGER lptstrFilename, INTEGER dwHandle, INTEGER dwLen, INTEGER lpData);
__EXTERN INTEGER __STDCALL GetFocus (void);
__EXTERN INTEGER __STDCALL GetFontData (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN SET __STDCALL GetFontLanguageInfo (INTEGER p0);
__EXTERN INTEGER __STDCALL GetForegroundWindow (void);
__EXTERN INTEGER __STDCALL GetFormA (INTEGER hPrinter, INTEGER pFormName, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetFormW (INTEGER hPrinter, INTEGER pFormName, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetFullPathNameA (INTEGER lpFileName, INTEGER nBufferLength, INTEGER lpBuffer, INTEGER *lpFilePart);
__EXTERN INTEGER __STDCALL GetFullPathNameW (INTEGER lpFileName, INTEGER nBufferLength, INTEGER lpBuffer, INTEGER *lpFilePart);
__EXTERN INTEGER __STDCALL GetGlyphOutlineA (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_GLYPHMETRICS *p3, INTEGER p4, INTEGER p5, WinAPI_MAT2 *p6);
__EXTERN INTEGER __STDCALL GetGlyphOutlineW (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_GLYPHMETRICS *p3, INTEGER p4, INTEGER p5, WinAPI_MAT2 *p6);
__EXTERN INTEGER __STDCALL GetGraphicsMode (INTEGER p0);
__EXTERN INTEGER __STDCALL GetHandleInformation (INTEGER hObject, SET *lpdwFlags);
__EXTERN INTEGER __STDCALL GetICMProfileA (INTEGER p0, INTEGER *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetICMProfileW (INTEGER p0, INTEGER *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetIconInfo (INTEGER hIcon, WinAPI_ICONINFO *piconinfo);
__EXTERN INTEGER __STDCALL GetInputState (void);
__EXTERN INTEGER __STDCALL GetJobA (INTEGER hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetJobW (INTEGER hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetKBCodePage (void);
__EXTERN INTEGER __STDCALL GetKernelObjectSecurity (INTEGER Handle, SET RequestedInformation, INTEGER pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
__EXTERN INTEGER __STDCALL GetKerningPairsA (INTEGER p0, INTEGER p1, WinAPI_KERNINGPAIR *p2);
__EXTERN INTEGER __STDCALL GetKerningPairsW (INTEGER p0, INTEGER p1, WinAPI_KERNINGPAIR *p2);
__EXTERN INTEGER __STDCALL GetKeyNameTextA (INTEGER lParam, INTEGER lpString, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetKeyNameTextW (INTEGER lParam, INTEGER lpString, INTEGER nSize);
__EXTERN SHORTINT __STDCALL GetKeyState (INTEGER nVirtKey);
__EXTERN INTEGER __STDCALL GetKeyboardLayout (INTEGER dwLayout);
__EXTERN INTEGER __STDCALL GetKeyboardLayoutList (INTEGER nBuff, INTEGER *lpList);
__EXTERN INTEGER __STDCALL GetKeyboardLayoutNameA (INTEGER pwszKLID);
__EXTERN INTEGER __STDCALL GetKeyboardLayoutNameW (INTEGER pwszKLID);
__EXTERN INTEGER __STDCALL GetKeyboardState (CHAR *lpKeyState);
__EXTERN INTEGER __STDCALL GetKeyboardType (INTEGER nTypeFlag);
__EXTERN INTEGER __STDCALL GetLargestConsoleWindowSize (INTEGER hConsoleOutput);
__EXTERN INTEGER __STDCALL GetLastActivePopup (INTEGER hWnd);
__EXTERN INTEGER __STDCALL GetLastError (void);
__EXTERN INTEGER __STDCALL GetLengthSid (INTEGER pSid);
__EXTERN void __STDCALL GetLocalTime (WinAPI_SYSTEMTIME *lpSystemTime);
__EXTERN INTEGER __STDCALL GetLocaleInfoA (INTEGER Locale, INTEGER LCType, INTEGER lpLCData, INTEGER cchData);
__EXTERN INTEGER __STDCALL GetLocaleInfoW (INTEGER Locale, INTEGER LCType, INTEGER lpLCData, INTEGER cchData);
__EXTERN INTEGER __STDCALL GetLogColorSpaceA (INTEGER p0, WinAPI_LOGCOLORSPACEA *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetLogColorSpaceW (INTEGER p0, WinAPI_LOGCOLORSPACEW *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetLogicalDriveStringsA (INTEGER nBufferLength, INTEGER lpBuffer);
__EXTERN INTEGER __STDCALL GetLogicalDriveStringsW (INTEGER nBufferLength, INTEGER lpBuffer);
__EXTERN INTEGER __STDCALL GetLogicalDrives (void);
__EXTERN INTEGER __STDCALL GetMailslotInfo (INTEGER hMailslot, INTEGER *lpMaxMessageSize, INTEGER *lpNextSize, INTEGER *lpMessageCount, INTEGER *lpReadTimeout);
__EXTERN INTEGER __STDCALL GetMapMode (INTEGER p0);
__EXTERN INTEGER __STDCALL GetMenu (INTEGER hWnd);
__EXTERN INTEGER __STDCALL GetMenuCheckMarkDimensions (void);
__EXTERN INTEGER __STDCALL GetMenuContextHelpId (INTEGER p0);
__EXTERN INTEGER __STDCALL GetMenuDefaultItem (INTEGER hMenu, INTEGER fByPos, SET gmdiFlags);
__EXTERN INTEGER __STDCALL GetMenuItemCount (INTEGER hMenu);
__EXTERN INTEGER __STDCALL GetMenuItemID (INTEGER hMenu, INTEGER nPos);
__EXTERN INTEGER __STDCALL GetMenuItemInfoA (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOA *p3);
__EXTERN INTEGER __STDCALL GetMenuItemInfoW (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOW *p3);
__EXTERN INTEGER __STDCALL GetMenuItemRect (INTEGER hWnd, INTEGER hMenu, INTEGER uItem, WinAPI_RECT *lprcItem);
__EXTERN INTEGER __STDCALL GetMenuState (INTEGER hMenu, INTEGER uId, SET uFlags);
__EXTERN INTEGER __STDCALL GetMenuStringA (INTEGER hMenu, INTEGER uIDItem, INTEGER lpString, INTEGER nMaxCount, SET uFlag);
__EXTERN INTEGER __STDCALL GetMenuStringW (INTEGER hMenu, INTEGER uIDItem, INTEGER lpString, INTEGER nMaxCount, SET uFlag);
__EXTERN INTEGER __STDCALL GetMessageA (WinAPI_MSG *lpMsg, INTEGER hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax);
__EXTERN INTEGER __STDCALL GetMessageExtraInfo (void);
__EXTERN INTEGER __STDCALL GetMessagePos (void);
__EXTERN INTEGER __STDCALL GetMessageTime (void);
__EXTERN INTEGER __STDCALL GetMessageW (WinAPI_MSG *lpMsg, INTEGER hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax);
__EXTERN INTEGER __STDCALL GetMetaFileA (INTEGER p0);
__EXTERN INTEGER __STDCALL GetMetaFileBitsEx (INTEGER p0, INTEGER p1, BYTE *p2);
__EXTERN INTEGER __STDCALL GetMetaFileW (INTEGER p0);
__EXTERN INTEGER __STDCALL GetMetaRgn (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetMiterLimit (INTEGER p0, SHORTREAL *p1);
__EXTERN INTEGER __STDCALL GetModuleFileNameA (INTEGER hModule, INTEGER lpFilename, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetModuleFileNameW (INTEGER hModule, INTEGER lpFilename, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetModuleHandleA (INTEGER lpModuleName);
__EXTERN INTEGER __STDCALL GetModuleHandleW (INTEGER lpModuleName);
__EXTERN INTEGER __STDCALL GetNamedPipeHandleStateA (INTEGER hNamedPipe, INTEGER *lpState, INTEGER *lpCurInstances, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout, INTEGER lpUserName, INTEGER nMaxUserNameSize);
__EXTERN INTEGER __STDCALL GetNamedPipeHandleStateW (INTEGER hNamedPipe, INTEGER *lpState, INTEGER *lpCurInstances, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout, INTEGER lpUserName, INTEGER nMaxUserNameSize);
__EXTERN INTEGER __STDCALL GetNamedPipeInfo (INTEGER hNamedPipe, INTEGER *lpFlags, INTEGER *lpOutBufferSize, INTEGER *lpInBufferSize, INTEGER *lpMaxInstances);
__EXTERN INTEGER __STDCALL GetNearestColor (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetNearestPaletteIndex (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetNextDlgGroupItem (INTEGER hDlg, INTEGER hCtl, INTEGER bPrevious);
__EXTERN INTEGER __STDCALL GetNextDlgTabItem (INTEGER hDlg, INTEGER hCtl, INTEGER bPrevious);
__EXTERN INTEGER __STDCALL GetNumberFormatA (INTEGER Locale, SET dwFlags, INTEGER lpValue, WinAPI_NUMBERFMTA *lpFormat, INTEGER lpNumberStr, INTEGER cchNumber);
__EXTERN INTEGER __STDCALL GetNumberFormatW (INTEGER Locale, SET dwFlags, INTEGER lpValue, WinAPI_NUMBERFMTW *lpFormat, INTEGER lpNumberStr, INTEGER cchNumber);
__EXTERN INTEGER __STDCALL GetNumberOfConsoleInputEvents (INTEGER hConsoleInput, INTEGER *lpNumberOfEvents);
__EXTERN INTEGER __STDCALL GetNumberOfConsoleMouseButtons (INTEGER *lpNumberOfMouseButtons);
__EXTERN INTEGER __STDCALL GetNumberOfEventLogRecords (INTEGER hEventLog, INTEGER *NumberOfRecords);
__EXTERN INTEGER __STDCALL GetOEMCP (void);
__EXTERN INTEGER __STDCALL GetObjectA (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetObjectType (INTEGER h);
__EXTERN INTEGER __STDCALL GetObjectW (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetOldestEventLogRecord (INTEGER hEventLog, INTEGER *OldestRecord);
__EXTERN INTEGER __STDCALL GetOpenClipboardWindow (void);
__EXTERN INTEGER __STDCALL GetOutlineTextMetricsA (INTEGER p0, INTEGER p1, WinAPI_OUTLINETEXTMETRICA *p2);
__EXTERN INTEGER __STDCALL GetOutlineTextMetricsW (INTEGER p0, INTEGER p1, WinAPI_OUTLINETEXTMETRICW *p2);
__EXTERN INTEGER __STDCALL GetOverlappedResult (INTEGER hFile, WinAPI_OVERLAPPED *lpOverlapped, INTEGER *lpNumberOfBytesTransferred, INTEGER bWait);
__EXTERN INTEGER __STDCALL GetPaletteEntries (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
__EXTERN INTEGER __STDCALL GetParent (INTEGER hWnd);
__EXTERN INTEGER __STDCALL GetPath (INTEGER p0, WinAPI_POINT *p1, CHAR *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL GetPixel (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetPixelFormat (INTEGER p0);
__EXTERN INTEGER __STDCALL GetPolyFillMode (INTEGER p0);
__EXTERN INTEGER __STDCALL GetPrintProcessorDirectoryA (INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrintProcessorDirectoryW (INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterA (INTEGER hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterDataA (INTEGER hPrinter, INTEGER pValueName, INTEGER *pType, CHAR *pData, INTEGER nSize, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterDataW (INTEGER hPrinter, INTEGER pValueName, INTEGER *pType, CHAR *pData, INTEGER nSize, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterDriverA (INTEGER hPrinter, INTEGER pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterDriverDirectoryA (INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pDriverDirectory, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterDriverDirectoryW (INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pDriverDirectory, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterDriverW (INTEGER hPrinter, INTEGER pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPrinterW (INTEGER hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER cbBuf, INTEGER *pcbNeeded);
__EXTERN INTEGER __STDCALL GetPriorityClass (INTEGER hProcess);
__EXTERN INTEGER __STDCALL GetPriorityClipboardFormat (INTEGER *paFormatPriorityList, INTEGER cFormats);
__EXTERN INTEGER __STDCALL GetPrivateObjectSecurity (INTEGER ObjectDescriptor, SET SecurityInformation, INTEGER ResultantDescriptor, INTEGER DescriptorLength, INTEGER *ReturnLength);
__EXTERN INTEGER __STDCALL GetPrivateProfileIntA (INTEGER lpAppName, INTEGER lpKeyName, INTEGER nDefault, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileIntW (INTEGER lpAppName, INTEGER lpKeyName, INTEGER nDefault, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileSectionA (INTEGER lpAppName, INTEGER lpReturnedString, INTEGER nSize, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileSectionNamesA (INTEGER lpszReturnBuffer, INTEGER nSize, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileSectionNamesW (INTEGER lpszReturnBuffer, INTEGER nSize, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileSectionW (INTEGER lpAppName, INTEGER lpReturnedString, INTEGER nSize, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileStringA (INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpDefault, INTEGER lpReturnedString, INTEGER nSize, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileStringW (INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpDefault, INTEGER lpReturnedString, INTEGER nSize, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL GetPrivateProfileStructA (INTEGER lpszSection, INTEGER lpszKey, INTEGER lpStruct, INTEGER uSizeStruct, INTEGER szFile);
__EXTERN INTEGER __STDCALL GetPrivateProfileStructW (INTEGER lpszSection, INTEGER lpszKey, INTEGER lpStruct, INTEGER uSizeStruct, INTEGER szFile);
__EXTERN WinAPI_FARPROC __STDCALL GetProcAddress (INTEGER hModule, INTEGER lpProcName);
__EXTERN INTEGER __STDCALL GetProcessAffinityMask (INTEGER hProcess, INTEGER *lpProcessAffinityMask, INTEGER *lpSystemAffinityMask);
__EXTERN INTEGER __STDCALL GetProcessHeap (void);
__EXTERN INTEGER __STDCALL GetProcessHeaps (INTEGER NumberOfHeaps, INTEGER *ProcessHeaps);
__EXTERN INTEGER __STDCALL GetProcessShutdownParameters (INTEGER *lpdwLevel, SET *lpdwFlags);
__EXTERN INTEGER __STDCALL GetProcessTimes (INTEGER hProcess, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpExitTime, WinAPI_FILETIME *lpKernelTime, WinAPI_FILETIME *lpUserTime);
__EXTERN INTEGER __STDCALL GetProcessVersion (INTEGER ProcessId);
__EXTERN INTEGER __STDCALL GetProcessWindowStation (void);
__EXTERN INTEGER __STDCALL GetProcessWorkingSetSize (INTEGER hProcess, INTEGER *lpMinimumWorkingSetSize, INTEGER *lpMaximumWorkingSetSize);
__EXTERN INTEGER __STDCALL GetProfileIntA (INTEGER lpAppName, INTEGER lpKeyName, INTEGER nDefault);
__EXTERN INTEGER __STDCALL GetProfileIntW (INTEGER lpAppName, INTEGER lpKeyName, INTEGER nDefault);
__EXTERN INTEGER __STDCALL GetProfileSectionA (INTEGER lpAppName, INTEGER lpReturnedString, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetProfileSectionW (INTEGER lpAppName, INTEGER lpReturnedString, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetProfileStringA (INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpDefault, INTEGER lpReturnedString, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetProfileStringW (INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpDefault, INTEGER lpReturnedString, INTEGER nSize);
__EXTERN INTEGER __STDCALL GetPropA (INTEGER hWnd, INTEGER lpString);
__EXTERN INTEGER __STDCALL GetPropW (INTEGER hWnd, INTEGER lpString);
__EXTERN INTEGER __STDCALL GetQueueStatus (SET flags);
__EXTERN INTEGER __STDCALL GetQueuedCompletionStatus (INTEGER CompletionPort, INTEGER *lpNumberOfBytesTransferred, INTEGER *lpCompletionKey, WinAPI_PtrOVERLAPPED *lpOverlapped, INTEGER dwMilliseconds);
__EXTERN INTEGER __STDCALL GetROP2 (INTEGER p0);
__EXTERN INTEGER __STDCALL GetRasterizerCaps (WinAPI_RASTERIZER_STATUS *p0, INTEGER p1);
__EXTERN INTEGER __STDCALL GetRegionData (INTEGER p0, INTEGER p1, WinAPI_RGNDATA *p2);
__EXTERN INTEGER __STDCALL GetRgnBox (INTEGER p0, WinAPI_RECT *p1);
__EXTERN INTEGER __STDCALL GetScrollInfo (INTEGER p0, INTEGER p1, WinAPI_SCROLLINFO *p2);
__EXTERN INTEGER __STDCALL GetScrollPos (INTEGER hWnd, INTEGER nBar);
__EXTERN INTEGER __STDCALL GetScrollRange (INTEGER hWnd, INTEGER nBar, INTEGER *lpMinPos, INTEGER *lpMaxPos);
__EXTERN INTEGER __STDCALL GetSecurityDescriptorControl (INTEGER pSecurityDescriptor, SHORTINT *pControl, INTEGER *lpdwRevision);
__EXTERN INTEGER __STDCALL GetSecurityDescriptorDacl (INTEGER pSecurityDescriptor, INTEGER *lpbDaclPresent, WinAPI_PtrACL *pDacl, INTEGER *lpbDaclDefaulted);
__EXTERN INTEGER __STDCALL GetSecurityDescriptorGroup (INTEGER pSecurityDescriptor, INTEGER *pGroup, INTEGER *lpbGroupDefaulted);
__EXTERN INTEGER __STDCALL GetSecurityDescriptorLength (INTEGER pSecurityDescriptor);
__EXTERN INTEGER __STDCALL GetSecurityDescriptorOwner (INTEGER pSecurityDescriptor, INTEGER *pOwner, INTEGER *lpbOwnerDefaulted);
__EXTERN INTEGER __STDCALL GetSecurityDescriptorSacl (INTEGER pSecurityDescriptor, INTEGER *lpbSaclPresent, WinAPI_PtrACL *pSacl, INTEGER *lpbSaclDefaulted);
__EXTERN INTEGER __STDCALL GetServiceDisplayNameA (INTEGER hSCManager, INTEGER lpServiceName, INTEGER lpDisplayName, INTEGER *lpcchBuffer);
__EXTERN INTEGER __STDCALL GetServiceDisplayNameW (INTEGER hSCManager, INTEGER lpServiceName, INTEGER lpDisplayName, INTEGER *lpcchBuffer);
__EXTERN INTEGER __STDCALL GetServiceKeyNameA (INTEGER hSCManager, INTEGER lpDisplayName, INTEGER lpServiceName, INTEGER *lpcchBuffer);
__EXTERN INTEGER __STDCALL GetServiceKeyNameW (INTEGER hSCManager, INTEGER lpDisplayName, INTEGER lpServiceName, INTEGER *lpcchBuffer);
__EXTERN INTEGER __STDCALL GetShortPathNameA (INTEGER lpszLongPath, INTEGER lpszShortPath, INTEGER cchBuffer);
__EXTERN INTEGER __STDCALL GetShortPathNameW (INTEGER lpszLongPath, INTEGER lpszShortPath, INTEGER cchBuffer);
__EXTERN WinAPI_PtrSID_IDENTIFIER_AUTHORITY __STDCALL GetSidIdentifierAuthority (INTEGER pSid);
__EXTERN INTEGER __STDCALL GetSidLengthRequired (CHAR nSubAuthorityCount);
__EXTERN INTEGER __STDCALL GetSidSubAuthority (INTEGER pSid, INTEGER nSubAuthority);
__EXTERN INTEGER __STDCALL GetSidSubAuthorityCount (INTEGER pSid);
__EXTERN void __STDCALL GetStartupInfoA (WinAPI_STARTUPINFOA *lpStartupInfo);
__EXTERN void __STDCALL GetStartupInfoW (WinAPI_STARTUPINFOW *lpStartupInfo);
__EXTERN INTEGER __STDCALL GetStdHandle (INTEGER nStdHandle);
__EXTERN INTEGER __STDCALL GetStockObject (INTEGER p0);
__EXTERN INTEGER __STDCALL GetStretchBltMode (INTEGER p0);
__EXTERN INTEGER __STDCALL GetStringTypeA (INTEGER Locale, SET dwInfoType, INTEGER lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
__EXTERN INTEGER __STDCALL GetStringTypeExA (INTEGER Locale, SET dwInfoType, INTEGER lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
__EXTERN INTEGER __STDCALL GetStringTypeExW (INTEGER Locale, SET dwInfoType, INTEGER lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
__EXTERN INTEGER __STDCALL GetStringTypeW (SET dwInfoType, INTEGER lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
__EXTERN INTEGER __STDCALL GetSubMenu (INTEGER hMenu, INTEGER nPos);
__EXTERN INTEGER __STDCALL GetSysColor (INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetSysColorBrush (INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetSystemDefaultLCID (void);
__EXTERN SHORTINT __STDCALL GetSystemDefaultLangID (void);
__EXTERN INTEGER __STDCALL GetSystemDirectoryA (INTEGER lpBuffer, INTEGER uSize);
__EXTERN INTEGER __STDCALL GetSystemDirectoryW (INTEGER lpBuffer, INTEGER uSize);
__EXTERN void __STDCALL GetSystemInfo (WinAPI_SYSTEM_INFO *lpSystemInfo);
__EXTERN INTEGER __STDCALL GetSystemMenu (INTEGER hWnd, INTEGER bRevert);
__EXTERN INTEGER __STDCALL GetSystemMetrics (INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetSystemPaletteEntries (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
__EXTERN INTEGER __STDCALL GetSystemPaletteUse (INTEGER p0);
__EXTERN INTEGER __STDCALL GetSystemPowerStatus (WinAPI_SYSTEM_POWER_STATUS *lpSystemPowerStatus);
__EXTERN void __STDCALL GetSystemTime (WinAPI_SYSTEMTIME *lpSystemTime);
__EXTERN INTEGER __STDCALL GetSystemTimeAdjustment (INTEGER *lpTimeAdjustment, INTEGER *lpTimeIncrement, INTEGER *lpTimeAdjustmentDisabled);
__EXTERN void __STDCALL GetSystemTimeAsFileTime (WinAPI_FILETIME *lpSystemTimeAsFileTime);
__EXTERN INTEGER __STDCALL GetTabbedTextExtentA (INTEGER hDC, INTEGER lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions);
__EXTERN INTEGER __STDCALL GetTabbedTextExtentW (INTEGER hDC, INTEGER lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions);
__EXTERN INTEGER __STDCALL GetTapeParameters (INTEGER hDevice, INTEGER dwOperation, INTEGER *lpdwSize, INTEGER lpTapeInformation);
__EXTERN INTEGER __STDCALL GetTapePosition (INTEGER hDevice, INTEGER dwPositionType, INTEGER *lpdwPartition, INTEGER *lpdwOffsetLow, INTEGER *lpdwOffsetHigh);
__EXTERN INTEGER __STDCALL GetTapeStatus (INTEGER hDevice);
__EXTERN INTEGER __STDCALL GetTempFileNameA (INTEGER lpPathName, INTEGER lpPrefixString, INTEGER uUnique, INTEGER lpTempFileName);
__EXTERN INTEGER __STDCALL GetTempFileNameW (INTEGER lpPathName, INTEGER lpPrefixString, INTEGER uUnique, INTEGER lpTempFileName);
__EXTERN INTEGER __STDCALL GetTempPathA (INTEGER nBufferLength, INTEGER lpBuffer);
__EXTERN INTEGER __STDCALL GetTempPathW (INTEGER nBufferLength, INTEGER lpBuffer);
__EXTERN SET __STDCALL GetTextAlign (INTEGER p0);
__EXTERN INTEGER __STDCALL GetTextCharacterExtra (INTEGER p0);
__EXTERN INTEGER __STDCALL GetTextCharset (INTEGER hdc);
__EXTERN INTEGER __STDCALL GetTextCharsetInfo (INTEGER hdc, WinAPI_FONTSIGNATURE *lpSig, SET dwFlags);
__EXTERN INTEGER __STDCALL GetTextColor (INTEGER p0);
__EXTERN INTEGER __STDCALL GetTextExtentExPointA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4, INTEGER *p5, WinAPI_SIZE *p6);
__EXTERN INTEGER __STDCALL GetTextExtentExPointW (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4, INTEGER *p5, WinAPI_SIZE *p6);
__EXTERN INTEGER __STDCALL GetTextExtentPoint32A (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL GetTextExtentPoint32W (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL GetTextExtentPointA (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL GetTextExtentPointW (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL GetTextFaceA (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetTextFaceW (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL GetTextMetricsA (INTEGER p0, WinAPI_TEXTMETRICA *p1);
__EXTERN INTEGER __STDCALL GetTextMetricsW (INTEGER p0, WinAPI_TEXTMETRICW *p1);
__EXTERN INTEGER __STDCALL GetThreadContext (INTEGER hThread, WinAPI_CONTEXT *lpContext);
__EXTERN INTEGER __STDCALL GetThreadDesktop (INTEGER dwThreadId);
__EXTERN INTEGER __STDCALL GetThreadLocale (void);
__EXTERN INTEGER __STDCALL GetThreadPriority (INTEGER hThread);
__EXTERN INTEGER __STDCALL GetThreadPriorityBoost (INTEGER hThread, INTEGER *pDisablePriorityBoost);
__EXTERN INTEGER __STDCALL GetThreadSelectorEntry (INTEGER hThread, INTEGER dwSelector, WinAPI_LDT_ENTRY *lpSelectorEntry);
__EXTERN INTEGER __STDCALL GetThreadTimes (INTEGER hThread, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpExitTime, WinAPI_FILETIME *lpKernelTime, WinAPI_FILETIME *lpUserTime);
__EXTERN INTEGER __STDCALL GetTickCount (void);
__EXTERN INTEGER __STDCALL GetTimeFormatA (INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpTime, INTEGER lpFormat, INTEGER lpTimeStr, INTEGER cchTime);
__EXTERN INTEGER __STDCALL GetTimeFormatW (INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpTime, INTEGER lpFormat, INTEGER lpTimeStr, INTEGER cchTime);
__EXTERN INTEGER __STDCALL GetTimeZoneInformation (WinAPI_TIME_ZONE_INFORMATION *lpTimeZoneInformation);
__EXTERN INTEGER __STDCALL GetTokenInformation (INTEGER TokenHandle, INTEGER TokenInformationClass, INTEGER TokenInformation, INTEGER TokenInformationLength, INTEGER *ReturnLength);
__EXTERN INTEGER __STDCALL GetTopWindow (INTEGER hWnd);
__EXTERN INTEGER __STDCALL GetUpdateRect (INTEGER hWnd, WinAPI_RECT *lpRect, INTEGER bErase);
__EXTERN INTEGER __STDCALL GetUpdateRgn (INTEGER hWnd, INTEGER hRgn, INTEGER bErase);
__EXTERN INTEGER __STDCALL GetUserDefaultLCID (void);
__EXTERN SHORTINT __STDCALL GetUserDefaultLangID (void);
__EXTERN INTEGER __STDCALL GetUserNameA (INTEGER lpBuffer, INTEGER *nSize);
__EXTERN INTEGER __STDCALL GetUserNameW (INTEGER lpBuffer, INTEGER *nSize);
__EXTERN INTEGER __STDCALL GetUserObjectInformationA (INTEGER hObj, INTEGER nIndex, INTEGER pvInfo, INTEGER nLength, INTEGER *lpnLengthNeeded);
__EXTERN INTEGER __STDCALL GetUserObjectInformationW (INTEGER hObj, INTEGER nIndex, INTEGER pvInfo, INTEGER nLength, INTEGER *lpnLengthNeeded);
__EXTERN INTEGER __STDCALL GetUserObjectSecurity (INTEGER hObj, INTEGER *pSIRequested, INTEGER pSID, INTEGER nLength, INTEGER *lpnLengthNeeded);
__EXTERN INTEGER __STDCALL GetVersion (void);
__EXTERN INTEGER __STDCALL GetVersionExA (WinAPI_OSVERSIONINFOA *lpVersionInformation);
__EXTERN INTEGER __STDCALL GetVersionExW (WinAPI_OSVERSIONINFOW *lpVersionInformation);
__EXTERN INTEGER __STDCALL GetViewportExtEx (INTEGER p0, WinAPI_SIZE *p1);
__EXTERN INTEGER __STDCALL GetViewportOrgEx (INTEGER p0, WinAPI_POINT *p1);
__EXTERN INTEGER __STDCALL GetVolumeInformationA (INTEGER lpRootPathName, INTEGER lpVolumeNameBuffer, INTEGER nVolumeNameSize, INTEGER *lpVolumeSerialNumber, INTEGER *lpMaximumComponentLength, SET *lpFileSystemFlags, INTEGER lpFileSystemNameBuffer, INTEGER nFileSystemNameSize);
__EXTERN INTEGER __STDCALL GetVolumeInformationW (INTEGER lpRootPathName, INTEGER lpVolumeNameBuffer, INTEGER nVolumeNameSize, INTEGER *lpVolumeSerialNumber, INTEGER *lpMaximumComponentLength, SET *lpFileSystemFlags, INTEGER lpFileSystemNameBuffer, INTEGER nFileSystemNameSize);
__EXTERN INTEGER __STDCALL GetWinMetaFileBits (INTEGER p0, INTEGER p1, CHAR *p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL GetWindow (INTEGER hWnd, INTEGER uCmd);
__EXTERN INTEGER __STDCALL GetWindowContextHelpId (INTEGER p0);
__EXTERN INTEGER __STDCALL GetWindowDC (INTEGER hWnd);
__EXTERN INTEGER __STDCALL GetWindowExtEx (INTEGER p0, WinAPI_SIZE *p1);
__EXTERN INTEGER __STDCALL GetWindowLongA (INTEGER hWnd, INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetWindowLongW (INTEGER hWnd, INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetWindowOrgEx (INTEGER p0, WinAPI_POINT *p1);
__EXTERN INTEGER __STDCALL GetWindowPlacement (INTEGER hWnd, WinAPI_WINDOWPLACEMENT *lpwndpl);
__EXTERN INTEGER __STDCALL GetWindowRect (INTEGER hWnd, WinAPI_RECT *lpRect);
__EXTERN INTEGER __STDCALL GetWindowRgn (INTEGER hWnd, INTEGER hRgn);
__EXTERN INTEGER __STDCALL GetWindowTextA (INTEGER hWnd, INTEGER lpString, INTEGER nMaxCount);
__EXTERN INTEGER __STDCALL GetWindowTextLengthA (INTEGER hWnd);
__EXTERN INTEGER __STDCALL GetWindowTextLengthW (INTEGER hWnd);
__EXTERN INTEGER __STDCALL GetWindowTextW (INTEGER hWnd, INTEGER lpString, INTEGER nMaxCount);
__EXTERN INTEGER __STDCALL GetWindowThreadProcessId (INTEGER hWnd, INTEGER *lpdwProcessId);
__EXTERN SHORTINT __STDCALL GetWindowWord (INTEGER hWnd, INTEGER nIndex);
__EXTERN INTEGER __STDCALL GetWindowsDirectoryA (INTEGER lpBuffer, INTEGER uSize);
__EXTERN INTEGER __STDCALL GetWindowsDirectoryW (INTEGER lpBuffer, INTEGER uSize);
__EXTERN INTEGER __STDCALL GetWorldTransform (INTEGER p0, WinAPI_XFORM *p1);
__EXTERN SHORTINT __STDCALL GlobalAddAtomA (INTEGER lpString);
__EXTERN SHORTINT __STDCALL GlobalAddAtomW (INTEGER lpString);
__EXTERN INTEGER __STDCALL GlobalAlloc (SET uFlags, INTEGER dwBytes);
__EXTERN INTEGER __STDCALL GlobalCompact (INTEGER dwMinFree);
__EXTERN SHORTINT __STDCALL GlobalDeleteAtom (SHORTINT nAtom);
__EXTERN SHORTINT __STDCALL GlobalFindAtomA (INTEGER lpString);
__EXTERN SHORTINT __STDCALL GlobalFindAtomW (INTEGER lpString);
__EXTERN void __STDCALL GlobalFix (INTEGER hMem);
__EXTERN INTEGER __STDCALL GlobalFlags (INTEGER hMem);
__EXTERN INTEGER __STDCALL GlobalFree (INTEGER hMem);
__EXTERN INTEGER __STDCALL GlobalGetAtomNameA (SHORTINT nAtom, INTEGER lpBuffer, INTEGER nSize);
__EXTERN INTEGER __STDCALL GlobalGetAtomNameW (SHORTINT nAtom, INTEGER lpBuffer, INTEGER nSize);
__EXTERN INTEGER __STDCALL GlobalHandle (INTEGER pMem);
__EXTERN INTEGER __STDCALL GlobalLock (INTEGER hMem);
__EXTERN void __STDCALL GlobalMemoryStatus (WinAPI_MEMORYSTATUS *lpBuffer);
__EXTERN INTEGER __STDCALL GlobalReAlloc (INTEGER hMem, INTEGER dwBytes, SET uFlags);
__EXTERN INTEGER __STDCALL GlobalSize (INTEGER hMem);
__EXTERN INTEGER __STDCALL GlobalUnWire (INTEGER hMem);
__EXTERN void __STDCALL GlobalUnfix (INTEGER hMem);
__EXTERN INTEGER __STDCALL GlobalUnlock (INTEGER hMem);
__EXTERN INTEGER __STDCALL GlobalWire (INTEGER hMem);
__EXTERN INTEGER __STDCALL GrayStringA (INTEGER hDC, INTEGER hBrush, WinAPI_GRAYSTRINGPROC lpOutputFunc, INTEGER lpData, INTEGER nCount, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight);
__EXTERN INTEGER __STDCALL GrayStringW (INTEGER hDC, INTEGER hBrush, WinAPI_GRAYSTRINGPROC lpOutputFunc, INTEGER lpData, INTEGER nCount, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight);
__EXTERN INTEGER __STDCALL HeapAlloc (INTEGER hHeap, SET dwFlags, INTEGER dwBytes);
__EXTERN INTEGER __STDCALL HeapCompact (INTEGER hHeap, SET dwFlags);
__EXTERN INTEGER __STDCALL HeapCreate (SET flOptions, INTEGER dwInitialSize, INTEGER dwMaximumSize);
__EXTERN INTEGER __STDCALL HeapDestroy (INTEGER hHeap);
__EXTERN INTEGER __STDCALL HeapFree (INTEGER hHeap, SET dwFlags, INTEGER lpMem);
__EXTERN INTEGER __STDCALL HeapLock (INTEGER hHeap);
__EXTERN INTEGER __STDCALL HeapReAlloc (INTEGER hHeap, SET dwFlags, INTEGER lpMem, INTEGER dwBytes);
__EXTERN INTEGER __STDCALL HeapSize (INTEGER hHeap, SET dwFlags, INTEGER lpMem);
__EXTERN INTEGER __STDCALL HeapUnlock (INTEGER hHeap);
__EXTERN INTEGER __STDCALL HeapValidate (INTEGER hHeap, SET dwFlags, INTEGER lpMem);
__EXTERN INTEGER __STDCALL HeapWalk (INTEGER hHeap, WinAPI_PROCESS_HEAP_ENTRY *lpEntry);
__EXTERN INTEGER __STDCALL HideCaret (INTEGER hWnd);
__EXTERN INTEGER __STDCALL HiliteMenuItem (INTEGER hWnd, INTEGER hMenu, INTEGER uIDHiliteItem, INTEGER uHilite);
__EXTERN INTEGER __STDCALL ImpersonateDdeClientWindow (INTEGER hWndClient, INTEGER hWndServer);
__EXTERN INTEGER __STDCALL ImpersonateLoggedOnUser (INTEGER hToken);
__EXTERN INTEGER __STDCALL ImpersonateNamedPipeClient (INTEGER hNamedPipe);
__EXTERN INTEGER __STDCALL ImpersonateSelf (INTEGER ImpersonationLevel);
__EXTERN INTEGER __STDCALL InSendMessage (void);
__EXTERN INTEGER __STDCALL InflateRect (WinAPI_RECT *lprc, INTEGER dx, INTEGER dy);
__EXTERN INTEGER __STDCALL InitAtomTable (INTEGER nSize);
__EXTERN INTEGER __STDCALL InitializeAcl (WinAPI_ACL *pAcl, INTEGER nAclLength, INTEGER dwAclRevision);
__EXTERN void __STDCALL InitializeCriticalSection (WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
__EXTERN INTEGER __STDCALL InitializeSecurityDescriptor (INTEGER pSecurityDescriptor, INTEGER dwRevision);
__EXTERN INTEGER __STDCALL InitializeSid (INTEGER Sid, WinAPI_SID_IDENTIFIER_AUTHORITY *pIdentifierAuthority, CHAR nSubAuthorityCount);
__EXTERN INTEGER __STDCALL InitiateSystemShutdownA (INTEGER lpMachineName, INTEGER lpMessage, INTEGER dwTimeout, INTEGER bForceAppsClosed, INTEGER bRebootAfterShutdown);
__EXTERN INTEGER __STDCALL InitiateSystemShutdownW (INTEGER lpMachineName, INTEGER lpMessage, INTEGER dwTimeout, INTEGER bForceAppsClosed, INTEGER bRebootAfterShutdown);
__EXTERN INTEGER __STDCALL InsertMenuA (INTEGER hMenu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, INTEGER lpNewItem);
__EXTERN INTEGER __STDCALL InsertMenuItemA (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOA *p3);
__EXTERN INTEGER __STDCALL InsertMenuItemW (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOW *p3);
__EXTERN INTEGER __STDCALL InsertMenuW (INTEGER hMenu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, INTEGER lpNewItem);
__EXTERN INTEGER __STDCALL InterlockedCompareExchange (INTEGER Destination, INTEGER Exchange, INTEGER Comperand);
__EXTERN INTEGER __STDCALL InterlockedDecrement (INTEGER *lpAddend);
__EXTERN INTEGER __STDCALL InterlockedExchange (INTEGER *Target, INTEGER Value);
__EXTERN INTEGER __STDCALL InterlockedExchangeAdd (INTEGER *Addend, INTEGER Value);
__EXTERN INTEGER __STDCALL InterlockedIncrement (INTEGER *lpAddend);
__EXTERN INTEGER __STDCALL IntersectClipRect (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL IntersectRect (WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc1, WinAPI_RECT *lprcSrc2);
__EXTERN INTEGER __STDCALL InvalidateRect (INTEGER hWnd, WinAPI_RECT *lpRect, INTEGER bErase);
__EXTERN INTEGER __STDCALL InvalidateRgn (INTEGER hWnd, INTEGER hRgn, INTEGER bErase);
__EXTERN INTEGER __STDCALL InvertRect (INTEGER hDC, WinAPI_RECT *lprc);
__EXTERN INTEGER __STDCALL InvertRgn (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL IsBadCodePtr (WinAPI_FARPROC lpfn);
__EXTERN INTEGER __STDCALL IsBadHugeReadPtr (INTEGER lp, INTEGER ucb);
__EXTERN INTEGER __STDCALL IsBadHugeWritePtr (INTEGER lp, INTEGER ucb);
__EXTERN INTEGER __STDCALL IsBadReadPtr (INTEGER lp, INTEGER ucb);
__EXTERN INTEGER __STDCALL IsBadStringPtrA (INTEGER lpsz, INTEGER ucchMax);
__EXTERN INTEGER __STDCALL IsBadStringPtrW (INTEGER lpsz, INTEGER ucchMax);
__EXTERN INTEGER __STDCALL IsBadWritePtr (INTEGER lp, INTEGER ucb);
__EXTERN INTEGER __STDCALL IsCharAlphaA (CHAR ch);
__EXTERN INTEGER __STDCALL IsCharAlphaNumericA (CHAR ch);
__EXTERN INTEGER __STDCALL IsCharAlphaNumericW (SHORTINT ch);
__EXTERN INTEGER __STDCALL IsCharAlphaW (SHORTINT ch);
__EXTERN INTEGER __STDCALL IsCharLowerA (CHAR ch);
__EXTERN INTEGER __STDCALL IsCharLowerW (SHORTINT ch);
__EXTERN INTEGER __STDCALL IsCharUpperA (CHAR ch);
__EXTERN INTEGER __STDCALL IsCharUpperW (SHORTINT ch);
__EXTERN INTEGER __STDCALL IsChild (INTEGER hWndParent, INTEGER hWnd);
__EXTERN INTEGER __STDCALL IsClipboardFormatAvailable (INTEGER format);
__EXTERN INTEGER __STDCALL IsDBCSLeadByte (CHAR TestChar);
__EXTERN INTEGER __STDCALL IsDBCSLeadByteEx (INTEGER CodePage, CHAR TestChar);
__EXTERN INTEGER __STDCALL IsDialogMessageA (INTEGER hDlg, WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL IsDialogMessageW (INTEGER hDlg, WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL IsDlgButtonChecked (INTEGER hDlg, INTEGER nIDButton);
__EXTERN INTEGER __STDCALL IsIconic (INTEGER hWnd);
__EXTERN INTEGER __STDCALL IsMenu (INTEGER hMenu);
__EXTERN INTEGER __STDCALL IsRectEmpty (WinAPI_RECT *lprc);
__EXTERN INTEGER __STDCALL IsTextUnicode (INTEGER lpBuffer, INTEGER cb, SET *lpi);
__EXTERN INTEGER __STDCALL IsValidAcl (WinAPI_ACL *pAcl);
__EXTERN INTEGER __STDCALL IsValidCodePage (INTEGER CodePage);
__EXTERN INTEGER __STDCALL IsValidLocale (INTEGER Locale, SET dwFlags);
__EXTERN INTEGER __STDCALL IsValidSecurityDescriptor (INTEGER pSecurityDescriptor);
__EXTERN INTEGER __STDCALL IsValidSid (INTEGER pSid);
__EXTERN INTEGER __STDCALL IsWindow (INTEGER hWnd);
__EXTERN INTEGER __STDCALL IsWindowEnabled (INTEGER hWnd);
__EXTERN INTEGER __STDCALL IsWindowUnicode (INTEGER hWnd);
__EXTERN INTEGER __STDCALL IsWindowVisible (INTEGER hWnd);
__EXTERN INTEGER __STDCALL IsZoomed (INTEGER hWnd);
__EXTERN INTEGER __STDCALL KillTimer (INTEGER hWnd, INTEGER uIDEvent);
__EXTERN INTEGER __STDCALL LCMapStringA (INTEGER Locale, SET dwMapFlags, INTEGER lpSrcStr, INTEGER cchSrc, INTEGER lpDestStr, INTEGER cchDest);
__EXTERN INTEGER __STDCALL LCMapStringW (INTEGER Locale, SET dwMapFlags, INTEGER lpSrcStr, INTEGER cchSrc, INTEGER lpDestStr, INTEGER cchDest);
__EXTERN INTEGER __STDCALL LPtoDP (INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN void __STDCALL LZClose (INTEGER p0);
__EXTERN INTEGER __STDCALL LZCopy (INTEGER p0, INTEGER p1);
__EXTERN void __STDCALL LZDone (void);
__EXTERN INTEGER __STDCALL LZInit (INTEGER p0);
__EXTERN INTEGER __STDCALL LZOpenFileA (INTEGER p0, WinAPI_OFSTRUCT *p1, SHORTINT p2);
__EXTERN INTEGER __STDCALL LZOpenFileW (INTEGER p0, WinAPI_OFSTRUCT *p1, SHORTINT p2);
__EXTERN INTEGER __STDCALL LZRead (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL LZSeek (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL LZStart (void);
__EXTERN void __STDCALL LeaveCriticalSection (WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
__EXTERN INTEGER __STDCALL LineDDA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_LINEDDAPROC p4, INTEGER p5);
__EXTERN INTEGER __STDCALL LineTo (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL LoadAcceleratorsA (INTEGER hInstance, INTEGER lpTableName);
__EXTERN INTEGER __STDCALL LoadAcceleratorsW (INTEGER hInstance, INTEGER lpTableName);
__EXTERN INTEGER __STDCALL LoadBitmapA (INTEGER hInstance, INTEGER lpBitmapName);
__EXTERN INTEGER __STDCALL LoadBitmapW (INTEGER hInstance, INTEGER lpBitmapName);
__EXTERN INTEGER __STDCALL LoadCursorA (INTEGER hInstance, INTEGER lpCursorName);
__EXTERN INTEGER __STDCALL LoadCursorFromFileA (INTEGER lpFileName);
__EXTERN INTEGER __STDCALL LoadCursorFromFileW (INTEGER lpFileName);
__EXTERN INTEGER __STDCALL LoadCursorW (INTEGER hInstance, INTEGER lpCursorName);
__EXTERN INTEGER __STDCALL LoadIconA (INTEGER hInstance, INTEGER lpIconName);
__EXTERN INTEGER __STDCALL LoadIconW (INTEGER hInstance, INTEGER lpIconName);
__EXTERN INTEGER __STDCALL LoadImageA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
__EXTERN INTEGER __STDCALL LoadImageW (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
__EXTERN INTEGER __STDCALL LoadKeyboardLayoutA (INTEGER pwszKLID, SET Flags);
__EXTERN INTEGER __STDCALL LoadKeyboardLayoutW (INTEGER pwszKLID, SET Flags);
__EXTERN INTEGER __STDCALL LoadLibraryA (INTEGER lpLibFileName);
__EXTERN INTEGER __STDCALL LoadLibraryExA (INTEGER lpLibFileName, INTEGER hFile, SET dwFlags);
__EXTERN INTEGER __STDCALL LoadLibraryExW (INTEGER lpLibFileName, INTEGER hFile, SET dwFlags);
__EXTERN INTEGER __STDCALL LoadLibraryW (INTEGER lpLibFileName);
__EXTERN INTEGER __STDCALL LoadMenuA (INTEGER hInstance, INTEGER lpMenuName);
__EXTERN INTEGER __STDCALL LoadMenuIndirectA (WinAPI_PtrMENUTEMPLATEA lpMenuTemplate);
__EXTERN INTEGER __STDCALL LoadMenuIndirectW (WinAPI_PtrMENUTEMPLATEW lpMenuTemplate);
__EXTERN INTEGER __STDCALL LoadMenuW (INTEGER hInstance, INTEGER lpMenuName);
__EXTERN INTEGER __STDCALL LoadModule (INTEGER lpModuleName, INTEGER lpParameterBlock);
__EXTERN INTEGER __STDCALL LoadResource (INTEGER hModule, INTEGER hResInfo);
__EXTERN INTEGER __STDCALL LoadStringA (INTEGER hInstance, INTEGER uID, INTEGER lpBuffer, INTEGER nBufferMax);
__EXTERN INTEGER __STDCALL LoadStringW (INTEGER hInstance, INTEGER uID, INTEGER lpBuffer, INTEGER nBufferMax);
__EXTERN INTEGER __STDCALL LocalAlloc (SET uFlags, INTEGER uBytes);
__EXTERN INTEGER __STDCALL LocalCompact (INTEGER uMinFree);
__EXTERN INTEGER __STDCALL LocalFileTimeToFileTime (WinAPI_FILETIME *lpLocalFileTime, WinAPI_FILETIME *lpFileTime);
__EXTERN INTEGER __STDCALL LocalFlags (INTEGER hMem);
__EXTERN INTEGER __STDCALL LocalFree (INTEGER hMem);
__EXTERN INTEGER __STDCALL LocalHandle (INTEGER pMem);
__EXTERN INTEGER __STDCALL LocalLock (INTEGER hMem);
__EXTERN INTEGER __STDCALL LocalReAlloc (INTEGER hMem, INTEGER uBytes, SET uFlags);
__EXTERN INTEGER __STDCALL LocalShrink (INTEGER hMem, INTEGER cbNewSize);
__EXTERN INTEGER __STDCALL LocalSize (INTEGER hMem);
__EXTERN INTEGER __STDCALL LocalUnlock (INTEGER hMem);
__EXTERN INTEGER __STDCALL LockFile (INTEGER hFile, INTEGER dwFileOffsetLow, INTEGER dwFileOffsetHigh, INTEGER nNumberOfBytesToLockLow, INTEGER nNumberOfBytesToLockHigh);
__EXTERN INTEGER __STDCALL LockFileEx (INTEGER hFile, SET dwFlags, INTEGER dwReserved, INTEGER nNumberOfBytesToLockLow, INTEGER nNumberOfBytesToLockHigh, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL LockResource (INTEGER hResData);
__EXTERN INTEGER __STDCALL LockServiceDatabase (INTEGER hSCManager);
__EXTERN INTEGER __STDCALL LockWindowUpdate (INTEGER hWndLock);
__EXTERN INTEGER __STDCALL LogonUserA (INTEGER lpszUsername, INTEGER lpszDomain, INTEGER lpszPassword, INTEGER dwLogonType, INTEGER dwLogonProvider, INTEGER *phToken);
__EXTERN INTEGER __STDCALL LogonUserW (INTEGER lpszUsername, INTEGER lpszDomain, INTEGER lpszPassword, INTEGER dwLogonType, INTEGER dwLogonProvider, INTEGER *phToken);
__EXTERN INTEGER __STDCALL LookupAccountNameA (INTEGER lpSystemName, INTEGER lpAccountName, INTEGER Sid, INTEGER *cbSid, INTEGER ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
__EXTERN INTEGER __STDCALL LookupAccountNameW (INTEGER lpSystemName, INTEGER lpAccountName, INTEGER Sid, INTEGER *cbSid, INTEGER ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
__EXTERN INTEGER __STDCALL LookupAccountSidA (INTEGER lpSystemName, INTEGER Sid, INTEGER Name, INTEGER *cbName, INTEGER ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
__EXTERN INTEGER __STDCALL LookupAccountSidW (INTEGER lpSystemName, INTEGER Sid, INTEGER Name, INTEGER *cbName, INTEGER ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
__EXTERN INTEGER __STDCALL LookupIconIdFromDirectory (CHAR *presbits, INTEGER fIcon);
__EXTERN INTEGER __STDCALL LookupIconIdFromDirectoryEx (CHAR *presbits, INTEGER fIcon, INTEGER cxDesired, INTEGER cyDesired, SET Flags);
__EXTERN INTEGER __STDCALL LookupPrivilegeDisplayNameA (INTEGER lpSystemName, INTEGER lpName, INTEGER lpDisplayName, INTEGER *cbDisplayName, INTEGER *lpLanguageId);
__EXTERN INTEGER __STDCALL LookupPrivilegeDisplayNameW (INTEGER lpSystemName, INTEGER lpName, INTEGER lpDisplayName, INTEGER *cbDisplayName, INTEGER *lpLanguageId);
__EXTERN INTEGER __STDCALL LookupPrivilegeNameA (INTEGER lpSystemName, LONGINT *lpLuid, INTEGER lpName, INTEGER *cbName);
__EXTERN INTEGER __STDCALL LookupPrivilegeNameW (INTEGER lpSystemName, LONGINT *lpLuid, INTEGER lpName, INTEGER *cbName);
__EXTERN INTEGER __STDCALL LookupPrivilegeValueA (INTEGER lpSystemName, INTEGER lpName, LONGINT *lpLuid);
__EXTERN INTEGER __STDCALL LookupPrivilegeValueW (INTEGER lpSystemName, INTEGER lpName, LONGINT *lpLuid);
__EXTERN INTEGER __STDCALL MakeAbsoluteSD (INTEGER pSelfRelativeSecurityDescriptor, INTEGER pAbsoluteSecurityDescriptor, INTEGER *lpdwAbsoluteSecurityDescriptorSize, WinAPI_ACL *pDacl, INTEGER *lpdwDaclSize, WinAPI_ACL *pSacl, INTEGER *lpdwSaclSize, INTEGER pOwner, INTEGER *lpdwOwnerSize, INTEGER pPrimaryGroup, INTEGER *lpdwPrimaryGroupSize);
__EXTERN INTEGER __STDCALL MakeSelfRelativeSD (INTEGER pAbsoluteSecurityDescriptor, INTEGER pSelfRelativeSecurityDescriptor, INTEGER *lpdwBufferLength);
__EXTERN INTEGER __STDCALL MapDialogRect (INTEGER hDlg, WinAPI_RECT *lpRect);
__EXTERN void __STDCALL MapGenericMask (INTEGER *AccessMask, WinAPI_GENERIC_MAPPING *GenericMapping);
__EXTERN INTEGER __STDCALL MapViewOfFile (INTEGER hFileMappingObject, SET dwDesiredAccess, INTEGER dwFileOffsetHigh, INTEGER dwFileOffsetLow, INTEGER dwNumberOfBytesToMap);
__EXTERN INTEGER __STDCALL MapViewOfFileEx (INTEGER hFileMappingObject, SET dwDesiredAccess, INTEGER dwFileOffsetHigh, INTEGER dwFileOffsetLow, INTEGER dwNumberOfBytesToMap, INTEGER lpBaseAddress);
__EXTERN INTEGER __STDCALL MapVirtualKeyA (INTEGER uCode, INTEGER uMapType);
__EXTERN INTEGER __STDCALL MapVirtualKeyExA (INTEGER uCode, INTEGER uMapType, INTEGER dwhkl);
__EXTERN INTEGER __STDCALL MapVirtualKeyExW (INTEGER uCode, INTEGER uMapType, INTEGER dwhkl);
__EXTERN INTEGER __STDCALL MapVirtualKeyW (INTEGER uCode, INTEGER uMapType);
__EXTERN INTEGER __STDCALL MapWindowPoints (INTEGER hWndFrom, INTEGER hWndTo, WinAPI_POINT *lpPoints, INTEGER cPoints);
__EXTERN INTEGER __STDCALL MaskBlt (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10, INTEGER p11);
__EXTERN INTEGER __STDCALL MenuItemFromPoint (INTEGER hWnd, INTEGER hMenu, WinAPI_POINT *ptScreen);
__EXTERN INTEGER __STDCALL MessageBeep (SET uType);
__EXTERN INTEGER __STDCALL MessageBoxA (INTEGER hWnd, INTEGER lpText, INTEGER lpCaption, SET uType);
__EXTERN INTEGER __STDCALL MessageBoxExA (INTEGER hWnd, INTEGER lpText, INTEGER lpCaption, SET uType, SHORTINT wLanguageId);
__EXTERN INTEGER __STDCALL MessageBoxExW (INTEGER hWnd, INTEGER lpText, INTEGER lpCaption, SET uType, SHORTINT wLanguageId);
__EXTERN INTEGER __STDCALL MessageBoxIndirectA (WinAPI_MSGBOXPARAMSA *p0);
__EXTERN INTEGER __STDCALL MessageBoxIndirectW (WinAPI_MSGBOXPARAMSW *p0);
__EXTERN INTEGER __STDCALL MessageBoxW (INTEGER hWnd, INTEGER lpText, INTEGER lpCaption, SET uType);
__EXTERN INTEGER __STDCALL ModifyMenuA (INTEGER hMnu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, INTEGER lpNewItem);
__EXTERN INTEGER __STDCALL ModifyMenuW (INTEGER hMnu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, INTEGER lpNewItem);
__EXTERN INTEGER __STDCALL ModifyWorldTransform (INTEGER p0, WinAPI_XFORM *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL MoveFileA (INTEGER lpExistingFileName, INTEGER lpNewFileName);
__EXTERN INTEGER __STDCALL MoveFileExA (INTEGER lpExistingFileName, INTEGER lpNewFileName, SET dwFlags);
__EXTERN INTEGER __STDCALL MoveFileExW (INTEGER lpExistingFileName, INTEGER lpNewFileName, SET dwFlags);
__EXTERN INTEGER __STDCALL MoveFileW (INTEGER lpExistingFileName, INTEGER lpNewFileName);
__EXTERN INTEGER __STDCALL MoveToEx (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN INTEGER __STDCALL MoveWindow (INTEGER hWnd, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER bRepaint);
__EXTERN INTEGER __STDCALL MsgWaitForMultipleObjects (INTEGER nCount, INTEGER *pHandles, INTEGER fWaitAll, INTEGER dwMilliseconds, INTEGER dwWakeMask);
__EXTERN INTEGER __STDCALL MsgWaitForMultipleObjectsEx (INTEGER nCount, INTEGER *pHandles, INTEGER dwMilliseconds, INTEGER dwWakeMask, SET dwFlags);
__EXTERN INTEGER __STDCALL MulDiv (INTEGER nNumber, INTEGER nNumerator, INTEGER nDenominator);
__EXTERN INTEGER __STDCALL MultiByteToWideChar (INTEGER CodePage, SET dwFlags, INTEGER lpMultiByteStr, INTEGER cchMultiByte, INTEGER lpWideCharStr, INTEGER cchWideChar);
__EXTERN INTEGER __STDCALL NotifyBootConfigStatus (INTEGER BootAcceptable);
__EXTERN INTEGER __STDCALL NotifyChangeEventLog (INTEGER hEventLog, INTEGER hEvent);
__EXTERN INTEGER __STDCALL ObjectCloseAuditAlarmA (INTEGER SubsystemName, INTEGER HandleId, INTEGER GenerateOnClose);
__EXTERN INTEGER __STDCALL ObjectCloseAuditAlarmW (INTEGER SubsystemName, INTEGER HandleId, INTEGER GenerateOnClose);
__EXTERN INTEGER __STDCALL ObjectOpenAuditAlarmA (INTEGER SubsystemName, INTEGER HandleId, INTEGER ObjectTypeName, INTEGER ObjectName, INTEGER pSecurityDescriptor, INTEGER ClientToken, SET DesiredAccess, INTEGER GrantedAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER ObjectCreation, INTEGER AccessGranted, INTEGER *GenerateOnClose);
__EXTERN INTEGER __STDCALL ObjectOpenAuditAlarmW (INTEGER SubsystemName, INTEGER HandleId, INTEGER ObjectTypeName, INTEGER ObjectName, INTEGER pSecurityDescriptor, INTEGER ClientToken, SET DesiredAccess, INTEGER GrantedAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER ObjectCreation, INTEGER AccessGranted, INTEGER *GenerateOnClose);
__EXTERN INTEGER __STDCALL ObjectPrivilegeAuditAlarmA (INTEGER SubsystemName, INTEGER HandleId, INTEGER ClientToken, SET DesiredAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
__EXTERN INTEGER __STDCALL ObjectPrivilegeAuditAlarmW (INTEGER SubsystemName, INTEGER HandleId, INTEGER ClientToken, SET DesiredAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
__EXTERN INTEGER __STDCALL OemKeyScan (SHORTINT wOemChar);
__EXTERN INTEGER __STDCALL OemToCharA (INTEGER lpszSrc, INTEGER lpszDst);
__EXTERN INTEGER __STDCALL OemToCharBuffA (INTEGER lpszSrc, INTEGER lpszDst, INTEGER cchDstLength);
__EXTERN INTEGER __STDCALL OemToCharBuffW (INTEGER lpszSrc, INTEGER lpszDst, INTEGER cchDstLength);
__EXTERN INTEGER __STDCALL OemToCharW (INTEGER lpszSrc, INTEGER lpszDst);
__EXTERN INTEGER __STDCALL OffsetClipRgn (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL OffsetRect (WinAPI_RECT *lprc, INTEGER dx, INTEGER dy);
__EXTERN INTEGER __STDCALL OffsetRgn (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL OffsetViewportOrgEx (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN INTEGER __STDCALL OffsetWindowOrgEx (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN INTEGER __STDCALL OpenBackupEventLogA (INTEGER lpUNCServerName, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL OpenBackupEventLogW (INTEGER lpUNCServerName, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL OpenClipboard (INTEGER hWndNewOwner);
__EXTERN INTEGER __STDCALL OpenDesktopA (INTEGER lpszDesktop, SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
__EXTERN INTEGER __STDCALL OpenDesktopW (INTEGER lpszDesktop, SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
__EXTERN INTEGER __STDCALL OpenEventA (SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
__EXTERN INTEGER __STDCALL OpenEventLogA (INTEGER lpUNCServerName, INTEGER lpSourceName);
__EXTERN INTEGER __STDCALL OpenEventLogW (INTEGER lpUNCServerName, INTEGER lpSourceName);
__EXTERN INTEGER __STDCALL OpenEventW (SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
__EXTERN INTEGER __STDCALL OpenFile (INTEGER lpFileName, WinAPI_OFSTRUCT *lpReOpenBuff, SET uStyle);
__EXTERN INTEGER __STDCALL OpenFileMappingA (SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
__EXTERN INTEGER __STDCALL OpenFileMappingW (SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
__EXTERN INTEGER __STDCALL OpenIcon (INTEGER hWnd);
__EXTERN INTEGER __STDCALL OpenInputDesktop (SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
__EXTERN INTEGER __STDCALL OpenMutexA (SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
__EXTERN INTEGER __STDCALL OpenMutexW (SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
__EXTERN INTEGER __STDCALL OpenPrinterA (INTEGER pPrinterName, INTEGER *phPrinter, WinAPI_PRINTER_DEFAULTSA *pDefault);
__EXTERN INTEGER __STDCALL OpenPrinterW (INTEGER pPrinterName, INTEGER *phPrinter, WinAPI_PRINTER_DEFAULTSW *pDefault);
__EXTERN INTEGER __STDCALL OpenProcess (SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER dwProcessId);
__EXTERN INTEGER __STDCALL OpenProcessToken (INTEGER ProcessHandle, SET DesiredAccess, INTEGER *TokenHandle);
__EXTERN INTEGER __STDCALL OpenSCManagerA (INTEGER lpMachineName, INTEGER lpDatabaseName, SET dwDesiredAccess);
__EXTERN INTEGER __STDCALL OpenSCManagerW (INTEGER lpMachineName, INTEGER lpDatabaseName, SET dwDesiredAccess);
__EXTERN INTEGER __STDCALL OpenSemaphoreA (SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
__EXTERN INTEGER __STDCALL OpenSemaphoreW (SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
__EXTERN INTEGER __STDCALL OpenServiceA (INTEGER hSCManager, INTEGER lpServiceName, SET dwDesiredAccess);
__EXTERN INTEGER __STDCALL OpenServiceW (INTEGER hSCManager, INTEGER lpServiceName, SET dwDesiredAccess);
__EXTERN INTEGER __STDCALL OpenThreadToken (INTEGER ThreadHandle, SET DesiredAccess, INTEGER OpenAsSelf, INTEGER *TokenHandle);
__EXTERN INTEGER __STDCALL OpenWaitableTimerA (SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpTimerName);
__EXTERN INTEGER __STDCALL OpenWaitableTimerW (SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpTimerName);
__EXTERN INTEGER __STDCALL OpenWindowStationA (INTEGER lpszWinSta, INTEGER fInherit, SET dwDesiredAccess);
__EXTERN INTEGER __STDCALL OpenWindowStationW (INTEGER lpszWinSta, INTEGER fInherit, SET dwDesiredAccess);
__EXTERN void __STDCALL OutputDebugStringA (INTEGER lpOutputString);
__EXTERN void __STDCALL OutputDebugStringW (INTEGER lpOutputString);
__EXTERN INTEGER __STDCALL PackDDElParam (INTEGER msg, INTEGER uiLo, INTEGER uiHi);
__EXTERN INTEGER __STDCALL PaintDesktop (INTEGER hdc);
__EXTERN INTEGER __STDCALL PaintRgn (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL PatBlt (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
__EXTERN INTEGER __STDCALL PathToRegion (INTEGER p0);
__EXTERN INTEGER __STDCALL PeekConsoleInputA (INTEGER hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
__EXTERN INTEGER __STDCALL PeekConsoleInputW (INTEGER hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
__EXTERN INTEGER __STDCALL PeekMessageA (WinAPI_MSG *lpMsg, INTEGER hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax, INTEGER wRemoveMsg);
__EXTERN INTEGER __STDCALL PeekMessageW (WinAPI_MSG *lpMsg, INTEGER hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax, INTEGER wRemoveMsg);
__EXTERN INTEGER __STDCALL PeekNamedPipe (INTEGER hNamedPipe, INTEGER lpBuffer, INTEGER nBufferSize, INTEGER *lpBytesRead, INTEGER *lpTotalBytesAvail, INTEGER *lpBytesLeftThisMessage);
__EXTERN INTEGER __STDCALL Pie (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
__EXTERN INTEGER __STDCALL PlayEnhMetaFile (INTEGER p0, INTEGER p1, WinAPI_RECT *p2);
__EXTERN INTEGER __STDCALL PlayEnhMetaFileRecord (INTEGER p0, WinAPI_HANDLETABLE *p1, WinAPI_ENHMETARECORD *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL PlayMetaFile (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL PlayMetaFileRecord (INTEGER p0, WinAPI_HANDLETABLE *p1, WinAPI_METARECORD *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL PlgBlt (INTEGER p0, WinAPI_POINT *p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9);
__EXTERN INTEGER __STDCALL PolyBezier (INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PolyBezierTo (INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PolyDraw (INTEGER p0, WinAPI_POINT *p1, CHAR *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL PolyPolygon (INTEGER p0, WinAPI_POINT *p1, INTEGER *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL PolyPolyline (INTEGER p0, WinAPI_POINT *p1, INTEGER *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL PolyTextOutA (INTEGER p0, WinAPI_POLYTEXTA *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PolyTextOutW (INTEGER p0, WinAPI_POLYTEXTW *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL Polygon (INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL Polyline (INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PolylineTo (INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PostMessageA (INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL PostMessageW (INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL PostQueuedCompletionStatus (INTEGER CompletionPort, INTEGER dwNumberOfBytesTransferred, INTEGER dwCompletionKey, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN void __STDCALL PostQuitMessage (INTEGER nExitCode);
__EXTERN INTEGER __STDCALL PostThreadMessageA (INTEGER idThread, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL PostThreadMessageW (INTEGER idThread, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL PrepareTape (INTEGER hDevice, INTEGER dwOperation, INTEGER bImmediate);
__EXTERN INTEGER __STDCALL PrinterMessageBoxA (INTEGER hPrinter, INTEGER Error, INTEGER hWnd, INTEGER pText, INTEGER pCaption, INTEGER dwType);
__EXTERN INTEGER __STDCALL PrinterMessageBoxW (INTEGER hPrinter, INTEGER Error, INTEGER hWnd, INTEGER pText, INTEGER pCaption, INTEGER dwType);
__EXTERN INTEGER __STDCALL PrinterProperties (INTEGER hWnd, INTEGER hPrinter);
__EXTERN INTEGER __STDCALL PrivilegeCheck (INTEGER ClientToken, WinAPI_PRIVILEGE_SET *RequiredPrivileges, INTEGER *pfResult);
__EXTERN INTEGER __STDCALL PrivilegedServiceAuditAlarmA (INTEGER SubsystemName, INTEGER ServiceName, INTEGER ClientToken, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
__EXTERN INTEGER __STDCALL PrivilegedServiceAuditAlarmW (INTEGER SubsystemName, INTEGER ServiceName, INTEGER ClientToken, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
__EXTERN INTEGER __STDCALL PropertySheetA (WinAPI_PROPSHEETHEADERA *p0);
__EXTERN INTEGER __STDCALL PropertySheetW (WinAPI_PROPSHEETHEADERW *p0);
__EXTERN INTEGER __STDCALL PtInRect (WinAPI_RECT *lprc, WinAPI_POINT *pt);
__EXTERN INTEGER __STDCALL PtInRegion (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PtVisible (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL PulseEvent (INTEGER hEvent);
__EXTERN INTEGER __STDCALL PurgeComm (INTEGER hFile, SET dwFlags);
__EXTERN INTEGER __STDCALL QueryDosDeviceA (INTEGER lpDeviceName, INTEGER lpTargetPath, INTEGER ucchMax);
__EXTERN INTEGER __STDCALL QueryDosDeviceW (INTEGER lpDeviceName, INTEGER lpTargetPath, INTEGER ucchMax);
__EXTERN INTEGER __STDCALL QueryPerformanceCounter (LONGINT *lpPerformanceCount);
__EXTERN INTEGER __STDCALL QueryPerformanceFrequency (LONGINT *lpFrequency);
__EXTERN INTEGER __STDCALL QueryServiceConfigA (INTEGER hService, WinAPI_QUERY_SERVICE_CONFIGA *lpServiceConfig, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
__EXTERN INTEGER __STDCALL QueryServiceConfigW (INTEGER hService, WinAPI_QUERY_SERVICE_CONFIGW *lpServiceConfig, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
__EXTERN INTEGER __STDCALL QueryServiceLockStatusA (INTEGER hSCManager, WinAPI_QUERY_SERVICE_LOCK_STATUSA *lpLockStatus, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
__EXTERN INTEGER __STDCALL QueryServiceLockStatusW (INTEGER hSCManager, WinAPI_QUERY_SERVICE_LOCK_STATUSW *lpLockStatus, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
__EXTERN INTEGER __STDCALL QueryServiceObjectSecurity (INTEGER hService, SET dwSecurityInformation, INTEGER lpSecurityDescriptor, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
__EXTERN INTEGER __STDCALL QueryServiceStatus (INTEGER hService, WinAPI_SERVICE_STATUS *lpServiceStatus);
__EXTERN INTEGER __STDCALL QueueUserAPC (WinAPI_APCFUNC pfnAPC, INTEGER hThread, INTEGER dwData);
__EXTERN void __STDCALL RaiseException (INTEGER dwExceptionCode, INTEGER dwExceptionFlags, INTEGER nNumberOfArguments, INTEGER *lpArguments);
__EXTERN INTEGER __STDCALL ReadConsoleA (INTEGER hConsoleInput, INTEGER lpBuffer, INTEGER nNumberOfCharsToRead, INTEGER *lpNumberOfCharsRead, INTEGER lpReserved);
__EXTERN INTEGER __STDCALL ReadConsoleInputA (INTEGER hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
__EXTERN INTEGER __STDCALL ReadConsoleInputW (INTEGER hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
__EXTERN INTEGER __STDCALL ReadConsoleOutputA (INTEGER hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD *dwBufferSize, WinAPI_COORD *dwBufferCoord, WinAPI_SMALL_RECT *lpReadRegion);
__EXTERN INTEGER __STDCALL ReadConsoleOutputAttribute (INTEGER hConsoleOutput, SHORTINT *lpAttribute, INTEGER nLength, WinAPI_COORD *dwReadCoord, INTEGER *lpNumberOfAttrsRead);
__EXTERN INTEGER __STDCALL ReadConsoleOutputCharacterA (INTEGER hConsoleOutput, INTEGER lpCharacter, INTEGER nLength, WinAPI_COORD *dwReadCoord, INTEGER *lpNumberOfCharsRead);
__EXTERN INTEGER __STDCALL ReadConsoleOutputCharacterW (INTEGER hConsoleOutput, INTEGER lpCharacter, INTEGER nLength, WinAPI_COORD *dwReadCoord, INTEGER *lpNumberOfCharsRead);
__EXTERN INTEGER __STDCALL ReadConsoleOutputW (INTEGER hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD *dwBufferSize, WinAPI_COORD *dwBufferCoord, WinAPI_SMALL_RECT *lpReadRegion);
__EXTERN INTEGER __STDCALL ReadConsoleW (INTEGER hConsoleInput, INTEGER lpBuffer, INTEGER nNumberOfCharsToRead, INTEGER *lpNumberOfCharsRead, INTEGER lpReserved);
__EXTERN INTEGER __STDCALL ReadDirectoryChangesW (INTEGER hDirectory, INTEGER lpBuffer, INTEGER nBufferLength, INTEGER bWatchSubtree, SET dwNotifyFilter, INTEGER *lpBytesReturned, WinAPI_OVERLAPPED *lpOverlapped, WinAPI_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
__EXTERN INTEGER __STDCALL ReadEventLogA (INTEGER hEventLog, SET dwReadFlags, INTEGER dwRecordOffset, INTEGER lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *pnBytesRead, INTEGER *pnMinNumberOfBytesNeeded);
__EXTERN INTEGER __STDCALL ReadEventLogW (INTEGER hEventLog, SET dwReadFlags, INTEGER dwRecordOffset, INTEGER lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *pnBytesRead, INTEGER *pnMinNumberOfBytesNeeded);
__EXTERN INTEGER __STDCALL ReadFile (INTEGER hFile, INTEGER lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *lpNumberOfBytesRead, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL ReadFileEx (INTEGER hFile, INTEGER lpBuffer, INTEGER nNumberOfBytesToRead, WinAPI_OVERLAPPED *lpOverlapped, WinAPI_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
__EXTERN INTEGER __STDCALL ReadPrinter (INTEGER hPrinter, INTEGER pBuf, INTEGER cbBuf, INTEGER *pNoBytesRead);
__EXTERN INTEGER __STDCALL ReadProcessMemory (INTEGER hProcess, INTEGER lpBaseAddress, INTEGER lpBuffer, INTEGER nSize, INTEGER *lpNumberOfBytesRead);
__EXTERN INTEGER __STDCALL RealizePalette (INTEGER p0);
__EXTERN INTEGER __STDCALL RectInRegion (INTEGER p0, WinAPI_RECT *p1);
__EXTERN INTEGER __STDCALL RectVisible (INTEGER p0, WinAPI_RECT *p1);
__EXTERN INTEGER __STDCALL Rectangle (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL RedrawWindow (INTEGER hWnd, WinAPI_RECT *lprcUpdate, INTEGER hrgnUpdate, SET flags);
__EXTERN INTEGER __STDCALL RegCloseKey (INTEGER hKey);
__EXTERN INTEGER __STDCALL RegConnectRegistryA (INTEGER lpMachineName, INTEGER hKey, INTEGER *phkResult);
__EXTERN INTEGER __STDCALL RegConnectRegistryW (INTEGER lpMachineName, INTEGER hKey, INTEGER *phkResult);
__EXTERN INTEGER __STDCALL RegCreateKeyA (INTEGER hKey, INTEGER lpSubKey, INTEGER *phkResult);
__EXTERN INTEGER __STDCALL RegCreateKeyExA (INTEGER hKey, INTEGER lpSubKey, INTEGER Reserved, INTEGER lpClass, SET dwOptions, SET samDesired, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER *phkResult, INTEGER *lpdwDisposition);
__EXTERN INTEGER __STDCALL RegCreateKeyExW (INTEGER hKey, INTEGER lpSubKey, INTEGER Reserved, INTEGER lpClass, SET dwOptions, SET samDesired, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER *phkResult, INTEGER *lpdwDisposition);
__EXTERN INTEGER __STDCALL RegCreateKeyW (INTEGER hKey, INTEGER lpSubKey, INTEGER *phkResult);
__EXTERN INTEGER __STDCALL RegDeleteKeyA (INTEGER hKey, INTEGER lpSubKey);
__EXTERN INTEGER __STDCALL RegDeleteKeyW (INTEGER hKey, INTEGER lpSubKey);
__EXTERN INTEGER __STDCALL RegDeleteValueA (INTEGER hKey, INTEGER lpValueName);
__EXTERN INTEGER __STDCALL RegDeleteValueW (INTEGER hKey, INTEGER lpValueName);
__EXTERN INTEGER __STDCALL RegEnumKeyA (INTEGER hKey, INTEGER dwIndex, INTEGER lpName, INTEGER cbName);
__EXTERN INTEGER __STDCALL RegEnumKeyExA (INTEGER hKey, INTEGER dwIndex, INTEGER lpName, INTEGER *lpcbName, INTEGER *lpReserved, INTEGER lpClass, INTEGER *lpcbClass, WinAPI_FILETIME *lpftLastWriteTime);
__EXTERN INTEGER __STDCALL RegEnumKeyExW (INTEGER hKey, INTEGER dwIndex, INTEGER lpName, INTEGER *lpcbName, INTEGER *lpReserved, INTEGER lpClass, INTEGER *lpcbClass, WinAPI_FILETIME *lpftLastWriteTime);
__EXTERN INTEGER __STDCALL RegEnumKeyW (INTEGER hKey, INTEGER dwIndex, INTEGER lpName, INTEGER cbName);
__EXTERN INTEGER __STDCALL RegEnumValueA (INTEGER hKey, INTEGER dwIndex, INTEGER lpValueName, INTEGER *lpcbValueName, INTEGER *lpReserved, INTEGER *lpType, INTEGER lpData, INTEGER *lpcbData);
__EXTERN INTEGER __STDCALL RegEnumValueW (INTEGER hKey, INTEGER dwIndex, INTEGER lpValueName, INTEGER *lpcbValueName, INTEGER *lpReserved, INTEGER *lpType, INTEGER lpData, INTEGER *lpcbData);
__EXTERN INTEGER __STDCALL RegFlushKey (INTEGER hKey);
__EXTERN INTEGER __STDCALL RegGetKeySecurity (INTEGER hKey, SET SecurityInformation, INTEGER pSecurityDescriptor, INTEGER *lpcbSecurityDescriptor);
__EXTERN INTEGER __STDCALL RegLoadKeyA (INTEGER hKey, INTEGER lpSubKey, INTEGER lpFile);
__EXTERN INTEGER __STDCALL RegLoadKeyW (INTEGER hKey, INTEGER lpSubKey, INTEGER lpFile);
__EXTERN INTEGER __STDCALL RegNotifyChangeKeyValue (INTEGER hKey, INTEGER bWatchSubtree, SET dwNotifyFilter, INTEGER hEvent, INTEGER fAsynchronus);
__EXTERN INTEGER __STDCALL RegOpenKeyA (INTEGER hKey, INTEGER lpSubKey, INTEGER *phkResult);
__EXTERN INTEGER __STDCALL RegOpenKeyExA (INTEGER hKey, INTEGER lpSubKey, INTEGER ulOptions, SET samDesired, INTEGER *phkResult);
__EXTERN INTEGER __STDCALL RegOpenKeyExW (INTEGER hKey, INTEGER lpSubKey, INTEGER ulOptions, SET samDesired, INTEGER *phkResult);
__EXTERN INTEGER __STDCALL RegOpenKeyW (INTEGER hKey, INTEGER lpSubKey, INTEGER *phkResult);
__EXTERN INTEGER __STDCALL RegQueryInfoKeyA (INTEGER hKey, INTEGER lpClass, INTEGER *lpcbClass, INTEGER *lpReserved, INTEGER *lpcSubKeys, INTEGER *lpcbMaxSubKeyLen, INTEGER *lpcbMaxClassLen, INTEGER *lpcValues, INTEGER *lpcbMaxValueNameLen, INTEGER *lpcbMaxValueLen, INTEGER *lpcbSecurityDescriptor, WinAPI_FILETIME *lpftLastWriteTime);
__EXTERN INTEGER __STDCALL RegQueryInfoKeyW (INTEGER hKey, INTEGER lpClass, INTEGER *lpcbClass, INTEGER *lpReserved, INTEGER *lpcSubKeys, INTEGER *lpcbMaxSubKeyLen, INTEGER *lpcbMaxClassLen, INTEGER *lpcValues, INTEGER *lpcbMaxValueNameLen, INTEGER *lpcbMaxValueLen, INTEGER *lpcbSecurityDescriptor, WinAPI_FILETIME *lpftLastWriteTime);
__EXTERN INTEGER __STDCALL RegQueryMultipleValuesA (INTEGER hKey, WinAPI_VALENTA *val_list, INTEGER num_vals, INTEGER lpValueBuf, INTEGER *ldwTotsize);
__EXTERN INTEGER __STDCALL RegQueryMultipleValuesW (INTEGER hKey, WinAPI_VALENTW *val_list, INTEGER num_vals, INTEGER lpValueBuf, INTEGER *ldwTotsize);
__EXTERN INTEGER __STDCALL RegQueryValueA (INTEGER hKey, INTEGER lpSubKey, INTEGER lpValue, INTEGER *lpcbValue);
__EXTERN INTEGER __STDCALL RegQueryValueExA (INTEGER hKey, INTEGER lpValueName, INTEGER *lpReserved, INTEGER *lpType, INTEGER lpData, INTEGER *lpcbData);
__EXTERN INTEGER __STDCALL RegQueryValueExW (INTEGER hKey, INTEGER lpValueName, INTEGER *lpReserved, INTEGER *lpType, INTEGER lpData, INTEGER *lpcbData);
__EXTERN INTEGER __STDCALL RegQueryValueW (INTEGER hKey, INTEGER lpSubKey, INTEGER lpValue, INTEGER *lpcbValue);
__EXTERN INTEGER __STDCALL RegReplaceKeyA (INTEGER hKey, INTEGER lpSubKey, INTEGER lpNewFile, INTEGER lpOldFile);
__EXTERN INTEGER __STDCALL RegReplaceKeyW (INTEGER hKey, INTEGER lpSubKey, INTEGER lpNewFile, INTEGER lpOldFile);
__EXTERN INTEGER __STDCALL RegRestoreKeyA (INTEGER hKey, INTEGER lpFile, SET dwFlags);
__EXTERN INTEGER __STDCALL RegRestoreKeyW (INTEGER hKey, INTEGER lpFile, SET dwFlags);
__EXTERN INTEGER __STDCALL RegSaveKeyA (INTEGER hKey, INTEGER lpFile, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL RegSaveKeyW (INTEGER hKey, INTEGER lpFile, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
__EXTERN INTEGER __STDCALL RegSetKeySecurity (INTEGER hKey, SET SecurityInformation, INTEGER pSecurityDescriptor);
__EXTERN INTEGER __STDCALL RegSetValueA (INTEGER hKey, INTEGER lpSubKey, INTEGER dwType, INTEGER lpData, INTEGER cbData);
__EXTERN INTEGER __STDCALL RegSetValueExA (INTEGER hKey, INTEGER lpValueName, INTEGER Reserved, INTEGER dwType, INTEGER lpData, INTEGER cbData);
__EXTERN INTEGER __STDCALL RegSetValueExW (INTEGER hKey, INTEGER lpValueName, INTEGER Reserved, INTEGER dwType, INTEGER lpData, INTEGER cbData);
__EXTERN INTEGER __STDCALL RegSetValueW (INTEGER hKey, INTEGER lpSubKey, INTEGER dwType, INTEGER lpData, INTEGER cbData);
__EXTERN INTEGER __STDCALL RegUnLoadKeyA (INTEGER hKey, INTEGER lpSubKey);
__EXTERN INTEGER __STDCALL RegUnLoadKeyW (INTEGER hKey, INTEGER lpSubKey);
__EXTERN SHORTINT __STDCALL RegisterClassA (WinAPI_WNDCLASSA *lpWndClass);
__EXTERN SHORTINT __STDCALL RegisterClassExA (WinAPI_WNDCLASSEXA *p0);
__EXTERN SHORTINT __STDCALL RegisterClassExW (WinAPI_WNDCLASSEXW *p0);
__EXTERN SHORTINT __STDCALL RegisterClassW (WinAPI_WNDCLASSW *lpWndClass);
__EXTERN INTEGER __STDCALL RegisterClipboardFormatA (INTEGER lpszFormat);
__EXTERN INTEGER __STDCALL RegisterClipboardFormatW (INTEGER lpszFormat);
__EXTERN INTEGER __STDCALL RegisterEventSourceA (INTEGER lpUNCServerName, INTEGER lpSourceName);
__EXTERN INTEGER __STDCALL RegisterEventSourceW (INTEGER lpUNCServerName, INTEGER lpSourceName);
__EXTERN INTEGER __STDCALL RegisterHotKey (INTEGER hWnd, INTEGER id, INTEGER fsModifiers, INTEGER vk);
__EXTERN INTEGER __STDCALL RegisterServiceCtrlHandlerA (INTEGER lpServiceName, WinAPI_HANDLER_FUNCTION lpHandlerProc);
__EXTERN INTEGER __STDCALL RegisterServiceCtrlHandlerW (INTEGER lpServiceName, WinAPI_HANDLER_FUNCTION lpHandlerProc);
__EXTERN INTEGER __STDCALL RegisterWindowMessageA (INTEGER lpString);
__EXTERN INTEGER __STDCALL RegisterWindowMessageW (INTEGER lpString);
__EXTERN INTEGER __STDCALL ReleaseCapture (void);
__EXTERN INTEGER __STDCALL ReleaseDC (INTEGER hWnd, INTEGER hDC);
__EXTERN INTEGER __STDCALL ReleaseMutex (INTEGER hMutex);
__EXTERN INTEGER __STDCALL ReleaseSemaphore (INTEGER hSemaphore, INTEGER lReleaseCount, INTEGER *lpPreviousCount);
__EXTERN INTEGER __STDCALL RemoveDirectoryA (INTEGER lpPathName);
__EXTERN INTEGER __STDCALL RemoveDirectoryW (INTEGER lpPathName);
__EXTERN INTEGER __STDCALL RemoveFontResourceA (INTEGER p0);
__EXTERN INTEGER __STDCALL RemoveFontResourceW (INTEGER p0);
__EXTERN INTEGER __STDCALL RemoveMenu (INTEGER hMenu, INTEGER uPosition, SET uFlags);
__EXTERN INTEGER __STDCALL RemovePropA (INTEGER hWnd, INTEGER lpString);
__EXTERN INTEGER __STDCALL RemovePropW (INTEGER hWnd, INTEGER lpString);
__EXTERN INTEGER __STDCALL ReplyMessage (INTEGER lResult);
__EXTERN INTEGER __STDCALL ReportEventA (INTEGER hEventLog, SHORTINT wType, SHORTINT wCategory, INTEGER dwEventID, INTEGER lpUserSid, SHORTINT wNumStrings, INTEGER dwDataSize, INTEGER *lpStrings, INTEGER lpRawData);
__EXTERN INTEGER __STDCALL ReportEventW (INTEGER hEventLog, SHORTINT wType, SHORTINT wCategory, INTEGER dwEventID, INTEGER lpUserSid, SHORTINT wNumStrings, INTEGER dwDataSize, INTEGER lpStrings, INTEGER lpRawData);
__EXTERN INTEGER __STDCALL ResetDCA (INTEGER p0, WinAPI_DEVMODEA *p1);
__EXTERN INTEGER __STDCALL ResetDCW (INTEGER p0, WinAPI_DEVMODEW *p1);
__EXTERN INTEGER __STDCALL ResetEvent (INTEGER hEvent);
__EXTERN INTEGER __STDCALL ResetPrinterA (INTEGER hPrinter, WinAPI_PRINTER_DEFAULTSA *pDefault);
__EXTERN INTEGER __STDCALL ResetPrinterW (INTEGER hPrinter, WinAPI_PRINTER_DEFAULTSW *pDefault);
__EXTERN INTEGER __STDCALL ResizePalette (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL RestoreDC (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL ResumeThread (INTEGER hThread);
__EXTERN INTEGER __STDCALL ReuseDDElParam (INTEGER lParam, INTEGER msgIn, INTEGER msgOut, INTEGER uiLo, INTEGER uiHi);
__EXTERN INTEGER __STDCALL RevertToSelf (void);
__EXTERN INTEGER __STDCALL RoundRect (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6);
__EXTERN void __STDCALL RtlUnwind (INTEGER targetFrame, INTEGER targetIp, WinAPI_PtrEXCEPTION_RECORD excpRec, INTEGER retVal);
__EXTERN INTEGER __STDCALL SHAppBarMessage (INTEGER dwMessage, WinAPI_APPBARDATA *pData);
__EXTERN INTEGER __STDCALL SHFileOperationA (WinAPI_SHFILEOPSTRUCTA *lpFileOp);
__EXTERN INTEGER __STDCALL SHFileOperationW (WinAPI_SHFILEOPSTRUCTW *lpFileOp);
__EXTERN void __STDCALL SHFreeNameMappings (INTEGER hNameMappings);
__EXTERN INTEGER __STDCALL SHGetFileInfoA (INTEGER pszPath, SET dwFileAttributes, WinAPI_SHFILEINFOA *psfi, INTEGER cbFileInfo, SET uFlags);
__EXTERN INTEGER __STDCALL SHGetFileInfoW (INTEGER pszPath, SET dwFileAttributes, WinAPI_SHFILEINFOW *psfi, INTEGER cbFileInfo, SET uFlags);
__EXTERN INTEGER __STDCALL SHGetNewLinkInfoA (INTEGER pszLinkTo, INTEGER pszDir, INTEGER pszName, INTEGER *pfMustCopy, SET uFlags);
__EXTERN INTEGER __STDCALL SHGetNewLinkInfoW (INTEGER pszLinkTo, INTEGER pszDir, INTEGER pszName, INTEGER *pfMustCopy, SET uFlags);
__EXTERN INTEGER __STDCALL SaveDC (INTEGER p0);
__EXTERN INTEGER __STDCALL ScaleViewportExtEx (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_SIZE *p5);
__EXTERN INTEGER __STDCALL ScaleWindowExtEx (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_SIZE *p5);
__EXTERN INTEGER __STDCALL ScheduleJob (INTEGER hPrinter, INTEGER JobId);
__EXTERN INTEGER __STDCALL ScreenToClient (INTEGER hWnd, WinAPI_POINT *lpPoint);
__EXTERN INTEGER __STDCALL ScrollConsoleScreenBufferA (INTEGER hConsoleOutput, WinAPI_SMALL_RECT *lpScrollRectangle, WinAPI_SMALL_RECT *lpClipRectangle, WinAPI_COORD *dwDestinationOrigin, WinAPI_CHAR_INFO *lpFill);
__EXTERN INTEGER __STDCALL ScrollConsoleScreenBufferW (INTEGER hConsoleOutput, WinAPI_SMALL_RECT *lpScrollRectangle, WinAPI_SMALL_RECT *lpClipRectangle, WinAPI_COORD *dwDestinationOrigin, WinAPI_CHAR_INFO *lpFill);
__EXTERN INTEGER __STDCALL ScrollDC (INTEGER hDC, INTEGER dx, INTEGER dy, WinAPI_RECT *lprcScroll, WinAPI_RECT *lprcClip, INTEGER hrgnUpdate, WinAPI_RECT *lprcUpdate);
__EXTERN INTEGER __STDCALL ScrollWindow (INTEGER hWnd, INTEGER XAmount, INTEGER YAmount, WinAPI_RECT *lpRect, WinAPI_RECT *lpClipRect);
__EXTERN INTEGER __STDCALL ScrollWindowEx (INTEGER hWnd, INTEGER dx, INTEGER dy, WinAPI_RECT *prcScroll, WinAPI_RECT *prcClip, INTEGER hrgnUpdate, WinAPI_RECT *prcUpdate, SET flags);
__EXTERN INTEGER __STDCALL SearchPathA (INTEGER lpPath, INTEGER lpFileName, INTEGER lpExtension, INTEGER nBufferLength, INTEGER lpBuffer, INTEGER *lpFilePart);
__EXTERN INTEGER __STDCALL SearchPathW (INTEGER lpPath, INTEGER lpFileName, INTEGER lpExtension, INTEGER nBufferLength, INTEGER lpBuffer, INTEGER *lpFilePart);
__EXTERN INTEGER __STDCALL SelectClipPath (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SelectClipRgn (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SelectObject (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SelectPalette (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL SendDlgItemMessageA (INTEGER hDlg, INTEGER nIDDlgItem, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL SendDlgItemMessageW (INTEGER hDlg, INTEGER nIDDlgItem, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL SendMessageA (INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL SendMessageCallbackA (INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam, WinAPI_SENDASYNCPROC lpResultCallBack, INTEGER dwData);
__EXTERN INTEGER __STDCALL SendMessageCallbackW (INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam, WinAPI_SENDASYNCPROC lpResultCallBack, INTEGER dwData);
__EXTERN INTEGER __STDCALL SendMessageTimeoutA (INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam, SET fuFlags, INTEGER uTimeout, INTEGER *lpdwResult);
__EXTERN INTEGER __STDCALL SendMessageTimeoutW (INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam, SET fuFlags, INTEGER uTimeout, INTEGER *lpdwResult);
__EXTERN INTEGER __STDCALL SendMessageW (INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL SendNotifyMessageA (INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL SendNotifyMessageW (INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
__EXTERN INTEGER __STDCALL SetAbortProc (INTEGER p0, WinAPI_ABORTPROC p1);
__EXTERN INTEGER __STDCALL SetAclInformation (WinAPI_ACL *pAcl, INTEGER pAclInformation, INTEGER nAclInformationLength, INTEGER dwAclInformationClass);
__EXTERN INTEGER __STDCALL SetActiveWindow (INTEGER hWnd);
__EXTERN INTEGER __STDCALL SetArcDirection (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetBitmapBits (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL SetBitmapDimensionEx (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL SetBkColor (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetBkMode (INTEGER p0, INTEGER p1);
__EXTERN SET __STDCALL SetBoundsRect (INTEGER p0, WinAPI_RECT *p1, SET p2);
__EXTERN INTEGER __STDCALL SetBrushOrgEx (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN INTEGER __STDCALL SetCapture (INTEGER hWnd);
__EXTERN INTEGER __STDCALL SetCaretBlinkTime (INTEGER uMSeconds);
__EXTERN INTEGER __STDCALL SetCaretPos (INTEGER X, INTEGER Y);
__EXTERN INTEGER __STDCALL SetClassLongA (INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong);
__EXTERN INTEGER __STDCALL SetClassLongW (INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong);
__EXTERN SHORTINT __STDCALL SetClassWord (INTEGER hWnd, INTEGER nIndex, SHORTINT wNewWord);
__EXTERN INTEGER __STDCALL SetClipboardData (INTEGER uFormat, INTEGER hMem);
__EXTERN INTEGER __STDCALL SetClipboardViewer (INTEGER hWndNewViewer);
__EXTERN INTEGER __STDCALL SetColorAdjustment (INTEGER p0, WinAPI_COLORADJUSTMENT *p1);
__EXTERN INTEGER __STDCALL SetColorSpace (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetCommBreak (INTEGER hFile);
__EXTERN INTEGER __STDCALL SetCommConfig (INTEGER hCommDev, WinAPI_COMMCONFIG *lpCC, INTEGER dwSize);
__EXTERN INTEGER __STDCALL SetCommMask (INTEGER hFile, SET dwEvtMask);
__EXTERN INTEGER __STDCALL SetCommState (INTEGER hFile, WinAPI_DCB *lpDCB);
__EXTERN INTEGER __STDCALL SetCommTimeouts (INTEGER hFile, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
__EXTERN INTEGER __STDCALL SetComputerNameA (INTEGER lpComputerName);
__EXTERN INTEGER __STDCALL SetComputerNameW (INTEGER lpComputerName);
__EXTERN INTEGER __STDCALL SetConsoleActiveScreenBuffer (INTEGER hConsoleOutput);
__EXTERN INTEGER __STDCALL SetConsoleCP (INTEGER wCodePageID);
__EXTERN INTEGER __STDCALL SetConsoleCtrlHandler (WinAPI_HANDLER_ROUTINE HandlerRoutine, INTEGER Add);
__EXTERN INTEGER __STDCALL SetConsoleCursorInfo (INTEGER hConsoleOutput, WinAPI_CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
__EXTERN INTEGER __STDCALL SetConsoleCursorPosition (INTEGER hConsoleOutput, WinAPI_COORD *dwCursorPosition);
__EXTERN INTEGER __STDCALL SetConsoleMode (INTEGER hConsoleHandle, SET dwMode);
__EXTERN INTEGER __STDCALL SetConsoleOutputCP (INTEGER wCodePageID);
__EXTERN INTEGER __STDCALL SetConsoleScreenBufferSize (INTEGER hConsoleOutput, WinAPI_COORD *dwSize);
__EXTERN INTEGER __STDCALL SetConsoleTextAttribute (INTEGER hConsoleOutput, SHORTINT wAttributes);
__EXTERN INTEGER __STDCALL SetConsoleTitleA (INTEGER lpConsoleTitle);
__EXTERN INTEGER __STDCALL SetConsoleTitleW (INTEGER lpConsoleTitle);
__EXTERN INTEGER __STDCALL SetConsoleWindowInfo (INTEGER hConsoleOutput, INTEGER bAbsolute, WinAPI_SMALL_RECT *lpConsoleWindow);
__EXTERN INTEGER __STDCALL SetCurrentDirectoryA (INTEGER lpPathName);
__EXTERN INTEGER __STDCALL SetCurrentDirectoryW (INTEGER lpPathName);
__EXTERN INTEGER __STDCALL SetCursor (INTEGER hCursor);
__EXTERN INTEGER __STDCALL SetCursorPos (INTEGER X, INTEGER Y);
__EXTERN INTEGER __STDCALL SetDIBColorTable (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_RGBQUAD *p3, INTEGER p3__len);
__EXTERN INTEGER __STDCALL SetDIBits (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_BITMAPINFO *p5, INTEGER p6);
__EXTERN INTEGER __STDCALL SetDIBitsToDevice (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, WinAPI_BITMAPINFO *p10, INTEGER p11);
__EXTERN void __STDCALL SetDebugErrorLevel (INTEGER dwLevel);
__EXTERN INTEGER __STDCALL SetDefaultCommConfigA (INTEGER lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER dwSize);
__EXTERN INTEGER __STDCALL SetDefaultCommConfigW (INTEGER lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER dwSize);
__EXTERN INTEGER __STDCALL SetDeviceGammaRamp (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetDlgItemInt (INTEGER hDlg, INTEGER nIDDlgItem, INTEGER uValue, INTEGER bSigned);
__EXTERN INTEGER __STDCALL SetDlgItemTextA (INTEGER hDlg, INTEGER nIDDlgItem, INTEGER lpString);
__EXTERN INTEGER __STDCALL SetDlgItemTextW (INTEGER hDlg, INTEGER nIDDlgItem, INTEGER lpString);
__EXTERN INTEGER __STDCALL SetDoubleClickTime (INTEGER p0);
__EXTERN INTEGER __STDCALL SetEndOfFile (INTEGER hFile);
__EXTERN INTEGER __STDCALL SetEnhMetaFileBits (INTEGER p0, CHAR *p1);
__EXTERN INTEGER __STDCALL SetEnvironmentVariableA (INTEGER lpName, INTEGER lpValue);
__EXTERN INTEGER __STDCALL SetEnvironmentVariableW (INTEGER lpName, INTEGER lpValue);
__EXTERN INTEGER __STDCALL SetErrorMode (SET uMode);
__EXTERN INTEGER __STDCALL SetEvent (INTEGER hEvent);
__EXTERN void __STDCALL SetFileApisToANSI (void);
__EXTERN void __STDCALL SetFileApisToOEM (void);
__EXTERN INTEGER __STDCALL SetFileAttributesA (INTEGER lpFileName, SET dwFileAttributes);
__EXTERN INTEGER __STDCALL SetFileAttributesW (INTEGER lpFileName, SET dwFileAttributes);
__EXTERN INTEGER __STDCALL SetFilePointer (INTEGER hFile, INTEGER lDistanceToMove, INTEGER *lpDistanceToMoveHigh, INTEGER dwMoveMethod);
__EXTERN INTEGER __STDCALL SetFileSecurityA (INTEGER lpFileName, SET SecurityInformation, INTEGER pSecurityDescriptor);
__EXTERN INTEGER __STDCALL SetFileSecurityW (INTEGER lpFileName, SET SecurityInformation, INTEGER pSecurityDescriptor);
__EXTERN INTEGER __STDCALL SetFileTime (INTEGER hFile, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpLastAccessTime, WinAPI_FILETIME *lpLastWriteTime);
__EXTERN INTEGER __STDCALL SetFocus (INTEGER hWnd);
__EXTERN INTEGER __STDCALL SetForegroundWindow (INTEGER hWnd);
__EXTERN INTEGER __STDCALL SetFormA (INTEGER hPrinter, INTEGER pFormName, INTEGER Level, CHAR *pForm);
__EXTERN INTEGER __STDCALL SetFormW (INTEGER hPrinter, INTEGER pFormName, INTEGER Level, CHAR *pForm);
__EXTERN INTEGER __STDCALL SetGraphicsMode (INTEGER hdc, INTEGER iMode);
__EXTERN INTEGER __STDCALL SetHandleCount (INTEGER uNumber);
__EXTERN INTEGER __STDCALL SetHandleInformation (INTEGER hObject, INTEGER dwMask, SET dwFlags);
__EXTERN INTEGER __STDCALL SetICMMode (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetICMProfileA (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetICMProfileW (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetJobA (INTEGER hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER Command);
__EXTERN INTEGER __STDCALL SetJobW (INTEGER hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER Command);
__EXTERN INTEGER __STDCALL SetKernelObjectSecurity (INTEGER Handle, SET SecurityInformation, INTEGER SecurityDescriptor);
__EXTERN INTEGER __STDCALL SetKeyboardState (CHAR *lpKeyState);
__EXTERN void __STDCALL SetLastError (INTEGER dwErrCode);
__EXTERN void __STDCALL SetLastErrorEx (INTEGER dwErrCode, INTEGER dwType);
__EXTERN INTEGER __STDCALL SetLocalTime (WinAPI_SYSTEMTIME *lpSystemTime);
__EXTERN INTEGER __STDCALL SetLocaleInfoA (INTEGER Locale, INTEGER LCType, INTEGER lpLCData);
__EXTERN INTEGER __STDCALL SetLocaleInfoW (INTEGER Locale, INTEGER LCType, INTEGER lpLCData);
__EXTERN INTEGER __STDCALL SetMailslotInfo (INTEGER hMailslot, INTEGER lReadTimeout);
__EXTERN INTEGER __STDCALL SetMapMode (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetMapperFlags (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetMenu (INTEGER hWnd, INTEGER hMenu);
__EXTERN INTEGER __STDCALL SetMenuContextHelpId (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetMenuDefaultItem (INTEGER hMenu, INTEGER uItem, INTEGER fByPos);
__EXTERN INTEGER __STDCALL SetMenuItemBitmaps (INTEGER hMenu, INTEGER uPosition, SET uFlags, INTEGER hBitmapUnchecked, INTEGER hBitmapChecked);
__EXTERN INTEGER __STDCALL SetMenuItemInfoA (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOA *p3);
__EXTERN INTEGER __STDCALL SetMenuItemInfoW (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOW *p3);
__EXTERN INTEGER __STDCALL SetMessageExtraInfo (INTEGER lParam);
__EXTERN INTEGER __STDCALL SetMessageQueue (INTEGER cMessagesMax);
__EXTERN INTEGER __STDCALL SetMetaFileBitsEx (INTEGER p0, BYTE *p1);
__EXTERN INTEGER __STDCALL SetMetaRgn (INTEGER p0);
__EXTERN INTEGER __STDCALL SetMiterLimit (INTEGER p0, SHORTREAL p1, SHORTREAL *p2);
__EXTERN INTEGER __STDCALL SetNamedPipeHandleState (INTEGER hNamedPipe, INTEGER *lpMode, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout);
__EXTERN INTEGER __STDCALL SetPaletteEntries (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
__EXTERN INTEGER __STDCALL SetParent (INTEGER hWndChild, INTEGER hWndNewParent);
__EXTERN INTEGER __STDCALL SetPixel (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL SetPixelFormat (INTEGER p0, INTEGER p1, WinAPI_PIXELFORMATDESCRIPTOR *p2);
__EXTERN INTEGER __STDCALL SetPixelV (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL SetPolyFillMode (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetPrinterA (INTEGER hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER Command);
__EXTERN INTEGER __STDCALL SetPrinterDataA (INTEGER hPrinter, INTEGER pValueName, INTEGER Type, CHAR *pData, INTEGER cbData);
__EXTERN INTEGER __STDCALL SetPrinterDataW (INTEGER hPrinter, INTEGER pValueName, INTEGER Type, CHAR *pData, INTEGER cbData);
__EXTERN INTEGER __STDCALL SetPrinterW (INTEGER hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER Command);
__EXTERN INTEGER __STDCALL SetPriorityClass (INTEGER hProcess, INTEGER dwPriorityClass);
__EXTERN INTEGER __STDCALL SetPrivateObjectSecurity (SET SecurityInformation, INTEGER ModificationDescriptor, INTEGER *ObjectsSecurityDescriptor, WinAPI_GENERIC_MAPPING *GenericMapping, INTEGER Token);
__EXTERN INTEGER __STDCALL SetProcessAffinityMask (INTEGER hProcess, INTEGER dwProcessAffinityMask);
__EXTERN INTEGER __STDCALL SetProcessShutdownParameters (INTEGER dwLevel, SET dwFlags);
__EXTERN INTEGER __STDCALL SetProcessWindowStation (INTEGER hWinSta);
__EXTERN INTEGER __STDCALL SetProcessWorkingSetSize (INTEGER hProcess, INTEGER dwMinimumWorkingSetSize, INTEGER dwMaximumWorkingSetSize);
__EXTERN INTEGER __STDCALL SetPropA (INTEGER hWnd, INTEGER lpString, INTEGER hData);
__EXTERN INTEGER __STDCALL SetPropW (INTEGER hWnd, INTEGER lpString, INTEGER hData);
__EXTERN INTEGER __STDCALL SetROP2 (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetRect (WinAPI_RECT *lprc, INTEGER xLeft, INTEGER yTop, INTEGER xRight, INTEGER yBottom);
__EXTERN INTEGER __STDCALL SetRectEmpty (WinAPI_RECT *lprc);
__EXTERN INTEGER __STDCALL SetRectRgn (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL SetScrollInfo (INTEGER p0, INTEGER p1, WinAPI_SCROLLINFO *p2, INTEGER p3);
__EXTERN INTEGER __STDCALL SetScrollPos (INTEGER hWnd, INTEGER nBar, INTEGER nPos, INTEGER bRedraw);
__EXTERN INTEGER __STDCALL SetScrollRange (INTEGER hWnd, INTEGER nBar, INTEGER nMinPos, INTEGER nMaxPos, INTEGER bRedraw);
__EXTERN INTEGER __STDCALL SetSecurityDescriptorDacl (INTEGER pSecurityDescriptor, INTEGER bDaclPresent, WinAPI_ACL *pDacl, INTEGER bDaclDefaulted);
__EXTERN INTEGER __STDCALL SetSecurityDescriptorGroup (INTEGER pSecurityDescriptor, INTEGER pGroup, INTEGER bGroupDefaulted);
__EXTERN INTEGER __STDCALL SetSecurityDescriptorOwner (INTEGER pSecurityDescriptor, INTEGER pOwner, INTEGER bOwnerDefaulted);
__EXTERN INTEGER __STDCALL SetSecurityDescriptorSacl (INTEGER pSecurityDescriptor, INTEGER bSaclPresent, WinAPI_ACL *pSacl, INTEGER bSaclDefaulted);
__EXTERN INTEGER __STDCALL SetServiceObjectSecurity (INTEGER hService, SET dwSecurityInformation, INTEGER lpSecurityDescriptor);
__EXTERN INTEGER __STDCALL SetServiceStatus (INTEGER hServiceStatus, WinAPI_SERVICE_STATUS *lpServiceStatus);
__EXTERN INTEGER __STDCALL SetStdHandle (INTEGER nStdHandle, INTEGER hHandle);
__EXTERN INTEGER __STDCALL SetStretchBltMode (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetSysColors (INTEGER cElements, INTEGER *lpaElements, INTEGER *lpaRgbValues);
__EXTERN INTEGER __STDCALL SetSystemCursor (INTEGER hcur, INTEGER id);
__EXTERN INTEGER __STDCALL SetSystemPaletteUse (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetSystemPowerState (INTEGER fSuspend, INTEGER fForce);
__EXTERN INTEGER __STDCALL SetSystemTime (WinAPI_SYSTEMTIME *lpSystemTime);
__EXTERN INTEGER __STDCALL SetSystemTimeAdjustment (INTEGER dwTimeAdjustment, INTEGER bTimeAdjustmentDisabled);
__EXTERN INTEGER __STDCALL SetTapeParameters (INTEGER hDevice, INTEGER dwOperation, INTEGER lpTapeInformation);
__EXTERN INTEGER __STDCALL SetTapePosition (INTEGER hDevice, INTEGER dwPositionMethod, INTEGER dwPartition, INTEGER dwOffsetLow, INTEGER dwOffsetHigh, INTEGER bImmediate);
__EXTERN SET __STDCALL SetTextAlign (INTEGER p0, SET p1);
__EXTERN INTEGER __STDCALL SetTextCharacterExtra (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetTextColor (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetTextJustification (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL SetThreadAffinityMask (INTEGER hThread, INTEGER dwThreadAffinityMask);
__EXTERN INTEGER __STDCALL SetThreadContext (INTEGER hThread, WinAPI_CONTEXT *lpContext);
__EXTERN INTEGER __STDCALL SetThreadDesktop (INTEGER hDesktop);
__EXTERN INTEGER __STDCALL SetThreadIdealProcessor (INTEGER hThread, INTEGER dwIdealProcessor);
__EXTERN INTEGER __STDCALL SetThreadLocale (INTEGER Locale);
__EXTERN INTEGER __STDCALL SetThreadPriority (INTEGER hThread, INTEGER nPriority);
__EXTERN INTEGER __STDCALL SetThreadPriorityBoost (INTEGER hThread, INTEGER bDisablePriorityBoost);
__EXTERN INTEGER __STDCALL SetThreadToken (INTEGER *Thread, INTEGER Token);
__EXTERN INTEGER __STDCALL SetTimeZoneInformation (WinAPI_TIME_ZONE_INFORMATION *lpTimeZoneInformation);
__EXTERN INTEGER __STDCALL SetTimer (INTEGER hWnd, INTEGER nIDEvent, INTEGER uElapse, WinAPI_TIMERPROC lpTimerFunc);
__EXTERN INTEGER __STDCALL SetTokenInformation (INTEGER TokenHandle, INTEGER TokenInformationClass, INTEGER TokenInformation, INTEGER TokenInformationLength);
__EXTERN WinAPI_TOP_LEVEL_EXCEPTION_FILTER __STDCALL SetUnhandledExceptionFilter (WinAPI_TOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);
__EXTERN INTEGER __STDCALL SetUserObjectInformationA (INTEGER hObj, INTEGER nIndex, INTEGER pvInfo, INTEGER nLength);
__EXTERN INTEGER __STDCALL SetUserObjectInformationW (INTEGER hObj, INTEGER nIndex, INTEGER pvInfo, INTEGER nLength);
__EXTERN INTEGER __STDCALL SetUserObjectSecurity (INTEGER hObj, INTEGER *pSIRequested, INTEGER pSID);
__EXTERN INTEGER __STDCALL SetViewportExtEx (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL SetViewportOrgEx (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN INTEGER __STDCALL SetVolumeLabelA (INTEGER lpRootPathName, INTEGER lpVolumeName);
__EXTERN INTEGER __STDCALL SetVolumeLabelW (INTEGER lpRootPathName, INTEGER lpVolumeName);
__EXTERN INTEGER __STDCALL SetWaitableTimer (INTEGER hTimer, LONGINT *lpDueTime, INTEGER lPeriod, WinAPI_TIMERAPCROUTINE pfnCompletionRoutine, INTEGER lpArgToCompletionRoutine, INTEGER fResume);
__EXTERN INTEGER __STDCALL SetWinMetaFileBits (INTEGER p0, CHAR *p1, INTEGER p2, WinAPI_METAFILEPICT *p3);
__EXTERN INTEGER __STDCALL SetWindowContextHelpId (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL SetWindowExtEx (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
__EXTERN INTEGER __STDCALL SetWindowLongA (INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong);
__EXTERN INTEGER __STDCALL SetWindowLongW (INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong);
__EXTERN INTEGER __STDCALL SetWindowOrgEx (INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
__EXTERN INTEGER __STDCALL SetWindowPlacement (INTEGER hWnd, WinAPI_WINDOWPLACEMENT *lpwndpl);
__EXTERN INTEGER __STDCALL SetWindowPos (INTEGER hWnd, INTEGER hWndInsertAfter, INTEGER X, INTEGER Y, INTEGER cx, INTEGER cy, SET uFlags);
__EXTERN INTEGER __STDCALL SetWindowRgn (INTEGER hWnd, INTEGER hRgn, INTEGER bRedraw);
__EXTERN INTEGER __STDCALL SetWindowTextA (INTEGER hWnd, INTEGER lpString);
__EXTERN INTEGER __STDCALL SetWindowTextW (INTEGER hWnd, INTEGER lpString);
__EXTERN SHORTINT __STDCALL SetWindowWord (INTEGER hWnd, INTEGER nIndex, SHORTINT wNewWord);
__EXTERN WinAPI_HOOKPROC __STDCALL SetWindowsHookA (INTEGER nFilterType, WinAPI_HOOKPROC pfnFilterProc);
__EXTERN INTEGER __STDCALL SetWindowsHookExA (INTEGER idHook, WinAPI_HOOKPROC lpfn, INTEGER hmod, INTEGER dwThreadId);
__EXTERN INTEGER __STDCALL SetWindowsHookExW (INTEGER idHook, WinAPI_HOOKPROC lpfn, INTEGER hmod, INTEGER dwThreadId);
__EXTERN WinAPI_HOOKPROC __STDCALL SetWindowsHookW (INTEGER nFilterType, WinAPI_HOOKPROC pfnFilterProc);
__EXTERN INTEGER __STDCALL SetWorldTransform (INTEGER p0, WinAPI_XFORM *p1);
__EXTERN INTEGER __STDCALL SetupComm (INTEGER hFile, INTEGER dwInQueue, INTEGER dwOutQueue);
__EXTERN INTEGER __STDCALL ShellAboutA (INTEGER hWnd, INTEGER szApp, INTEGER szOtherStuff, INTEGER hIcon);
__EXTERN INTEGER __STDCALL ShellAboutW (INTEGER hWnd, INTEGER szApp, INTEGER szOtherStuff, INTEGER hIcon);
__EXTERN INTEGER __STDCALL ShellExecuteA (INTEGER hwnd, INTEGER lpOperation, INTEGER lpFile, INTEGER lpParameters, INTEGER lpDirectory, INTEGER nShowCmd);
__EXTERN INTEGER __STDCALL ShellExecuteExA (WinAPI_SHELLEXECUTEINFOA *lpExecInfo);
__EXTERN INTEGER __STDCALL ShellExecuteExW (WinAPI_SHELLEXECUTEINFOW *lpExecInfo);
__EXTERN INTEGER __STDCALL ShellExecuteW (INTEGER hwnd, INTEGER lpOperation, INTEGER lpFile, INTEGER lpParameters, INTEGER lpDirectory, INTEGER nShowCmd);
__EXTERN INTEGER __STDCALL Shell_NotifyIconA (INTEGER dwMessage, WinAPI_NOTIFYICONDATAA *lpData);
__EXTERN INTEGER __STDCALL Shell_NotifyIconW (INTEGER dwMessage, WinAPI_NOTIFYICONDATAW *lpData);
__EXTERN INTEGER __STDCALL ShowCaret (INTEGER hWnd);
__EXTERN INTEGER __STDCALL ShowCursor (INTEGER bShow);
__EXTERN INTEGER __STDCALL ShowOwnedPopups (INTEGER hWnd, INTEGER fShow);
__EXTERN INTEGER __STDCALL ShowScrollBar (INTEGER hWnd, INTEGER wBar, INTEGER bShow);
__EXTERN INTEGER __STDCALL ShowWindow (INTEGER hWnd, INTEGER nCmdShow);
__EXTERN INTEGER __STDCALL ShowWindowAsync (INTEGER hWnd, INTEGER nCmdShow);
__EXTERN INTEGER __STDCALL SignalObjectAndWait (INTEGER hObjectToSignal, INTEGER hObjectToWaitOn, INTEGER dwMilliseconds, INTEGER bAlertable);
__EXTERN INTEGER __STDCALL SizeofResource (INTEGER hModule, INTEGER hResInfo);
__EXTERN void __STDCALL Sleep (INTEGER dwMilliseconds);
__EXTERN INTEGER __STDCALL SleepEx (INTEGER dwMilliseconds, INTEGER bAlertable);
__EXTERN INTEGER __STDCALL StartDocA (INTEGER p0, WinAPI_DOCINFOA *p1);
__EXTERN INTEGER __STDCALL StartDocPrinterA (INTEGER hPrinter, INTEGER Level, CHAR *pDocInfo);
__EXTERN INTEGER __STDCALL StartDocPrinterW (INTEGER hPrinter, INTEGER Level, CHAR *pDocInfo);
__EXTERN INTEGER __STDCALL StartDocW (INTEGER p0, WinAPI_DOCINFOW *p1);
__EXTERN INTEGER __STDCALL StartPage (INTEGER p0);
__EXTERN INTEGER __STDCALL StartPagePrinter (INTEGER hPrinter);
__EXTERN INTEGER __STDCALL StartServiceA (INTEGER hService, INTEGER dwNumServiceArgs, INTEGER *lpServiceArgVectors);
__EXTERN INTEGER __STDCALL StartServiceCtrlDispatcherA (WinAPI_SERVICE_TABLE_ENTRYA *lpServiceStartTable);
__EXTERN INTEGER __STDCALL StartServiceCtrlDispatcherW (WinAPI_SERVICE_TABLE_ENTRYW *lpServiceStartTable);
__EXTERN INTEGER __STDCALL StartServiceW (INTEGER hService, INTEGER dwNumServiceArgs, INTEGER lpServiceArgVectors);
__EXTERN INTEGER __STDCALL StretchBlt (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10);
__EXTERN INTEGER __STDCALL StretchDIBits (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, WinAPI_BITMAPINFO *p10, INTEGER p11, INTEGER p12);
__EXTERN INTEGER __STDCALL StrokeAndFillPath (INTEGER p0);
__EXTERN INTEGER __STDCALL StrokePath (INTEGER p0);
__EXTERN INTEGER __STDCALL SubtractRect (WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc1, WinAPI_RECT *lprcSrc2);
__EXTERN INTEGER __STDCALL SuspendThread (INTEGER hThread);
__EXTERN INTEGER __STDCALL SwapBuffers (INTEGER p0);
__EXTERN INTEGER __STDCALL SwapMouseButton (INTEGER fSwap);
__EXTERN INTEGER __STDCALL SwitchDesktop (INTEGER hDesktop);
__EXTERN void __STDCALL SwitchToFiber (INTEGER lpFiber);
__EXTERN INTEGER __STDCALL SystemParametersInfoA (INTEGER uiAction, INTEGER uiParam, INTEGER pvParam, INTEGER fWinIni);
__EXTERN INTEGER __STDCALL SystemParametersInfoW (INTEGER uiAction, INTEGER uiParam, INTEGER pvParam, INTEGER fWinIni);
__EXTERN INTEGER __STDCALL SystemTimeToFileTime (WinAPI_SYSTEMTIME *lpSystemTime, WinAPI_FILETIME *lpFileTime);
__EXTERN INTEGER __STDCALL SystemTimeToTzSpecificLocalTime (WinAPI_TIME_ZONE_INFORMATION *lpTimeZoneInformation, WinAPI_SYSTEMTIME *lpUniversalTime, WinAPI_SYSTEMTIME *lpLocalTime);
__EXTERN INTEGER __STDCALL TabbedTextOutA (INTEGER hDC, INTEGER X, INTEGER Y, INTEGER lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions, INTEGER nTabOrigin);
__EXTERN INTEGER __STDCALL TabbedTextOutW (INTEGER hDC, INTEGER X, INTEGER Y, INTEGER lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions, INTEGER nTabOrigin);
__EXTERN INTEGER __STDCALL TerminateProcess (INTEGER hProcess, INTEGER uExitCode);
__EXTERN INTEGER __STDCALL TerminateThread (INTEGER hThread, INTEGER dwExitCode);
__EXTERN INTEGER __STDCALL TextOutA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN INTEGER __STDCALL TextOutW (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
__EXTERN SHORTINT __STDCALL TileWindows (INTEGER hwndParent, INTEGER wHow, WinAPI_RECT *lpRect, INTEGER cKids, INTEGER *lpKids);
__EXTERN INTEGER __STDCALL TlsAlloc (void);
__EXTERN INTEGER __STDCALL TlsFree (INTEGER dwTlsIndex);
__EXTERN INTEGER __STDCALL TlsGetValue (INTEGER dwTlsIndex);
__EXTERN INTEGER __STDCALL TlsSetValue (INTEGER dwTlsIndex, INTEGER lpTlsValue);
__EXTERN INTEGER __STDCALL ToAscii (INTEGER uVirtKey, INTEGER uScanCode, CHAR *lpKeyState, SHORTINT *lpChar, SET uFlags);
__EXTERN INTEGER __STDCALL ToAsciiEx (INTEGER uVirtKey, INTEGER uScanCode, CHAR *lpKeyState, SHORTINT *lpChar, SET uFlags, INTEGER dwhkl);
__EXTERN INTEGER __STDCALL ToUnicode (INTEGER wVirtKey, INTEGER wScanCode, CHAR *lpKeyState, INTEGER pwszBuff, INTEGER cchBuff, INTEGER wFlags);
__EXTERN INTEGER __STDCALL ToUnicodeEx (INTEGER wVirtKey, INTEGER wScanCode, CHAR *lpKeyState, INTEGER pwszBuff, INTEGER cchBuff, INTEGER wFlags, INTEGER dwhkl);
__EXTERN INTEGER __STDCALL TrackPopupMenu (INTEGER hMenu, SET uFlags, INTEGER x, INTEGER y, INTEGER nReserved, INTEGER hWnd, WinAPI_RECT *prcRect);
__EXTERN INTEGER __STDCALL TrackPopupMenuEx (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_TPMPARAMS *p5);
__EXTERN INTEGER __STDCALL TransactNamedPipe (INTEGER hNamedPipe, INTEGER lpInBuffer, INTEGER nInBufferSize, INTEGER lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL TranslateAcceleratorA (INTEGER hWnd, INTEGER hAccTable, WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL TranslateAcceleratorW (INTEGER hWnd, INTEGER hAccTable, WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL TranslateCharsetInfo (INTEGER *lpSrc, WinAPI_CHARSETINFO *lpCs, SET dwFlags);
__EXTERN INTEGER __STDCALL TranslateMDISysAccel (INTEGER hWndClient, WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL TranslateMessage (WinAPI_MSG *lpMsg);
__EXTERN INTEGER __STDCALL TransmitCommChar (INTEGER hFile, CHAR cChar);
__EXTERN INTEGER __STDCALL TryEnterCriticalSection (WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
__EXTERN INTEGER __STDCALL UnhandledExceptionFilter (WinAPI_EXCEPTION_POINTERS *ExceptionInfo);
__EXTERN INTEGER __STDCALL UnhookWindowsHook (INTEGER nCode, WinAPI_HOOKPROC pfnFilterProc);
__EXTERN INTEGER __STDCALL UnhookWindowsHookEx (INTEGER hhk);
__EXTERN INTEGER __STDCALL UnionRect (WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc1, WinAPI_RECT *lprcSrc2);
__EXTERN INTEGER __STDCALL UnloadKeyboardLayout (INTEGER hkl);
__EXTERN INTEGER __STDCALL UnlockFile (INTEGER hFile, INTEGER dwFileOffsetLow, INTEGER dwFileOffsetHigh, INTEGER nNumberOfBytesToUnlockLow, INTEGER nNumberOfBytesToUnlockHigh);
__EXTERN INTEGER __STDCALL UnlockFileEx (INTEGER hFile, INTEGER dwReserved, INTEGER nNumberOfBytesToUnlockLow, INTEGER nNumberOfBytesToUnlockHigh, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL UnlockServiceDatabase (INTEGER ScLock);
__EXTERN INTEGER __STDCALL UnmapViewOfFile (INTEGER lpBaseAddress);
__EXTERN INTEGER __STDCALL UnpackDDElParam (INTEGER msg, INTEGER lParam, INTEGER *puiLo, INTEGER *puiHi);
__EXTERN INTEGER __STDCALL UnrealizeObject (INTEGER p0);
__EXTERN INTEGER __STDCALL UnregisterClassA (INTEGER lpClassName, INTEGER hInstance);
__EXTERN INTEGER __STDCALL UnregisterClassW (INTEGER lpClassName, INTEGER hInstance);
__EXTERN INTEGER __STDCALL UnregisterHotKey (INTEGER hWnd, INTEGER id);
__EXTERN INTEGER __STDCALL UpdateColors (INTEGER p0);
__EXTERN INTEGER __STDCALL UpdateResourceA (INTEGER hUpdate, INTEGER lpType, INTEGER lpName, SHORTINT wLanguage, INTEGER lpData, INTEGER cbData);
__EXTERN INTEGER __STDCALL UpdateResourceW (INTEGER hUpdate, INTEGER lpType, INTEGER lpName, SHORTINT wLanguage, INTEGER lpData, INTEGER cbData);
__EXTERN INTEGER __STDCALL UpdateWindow (INTEGER hWnd);
__EXTERN INTEGER __STDCALL ValidateRect (INTEGER hWnd, WinAPI_RECT *lpRect);
__EXTERN INTEGER __STDCALL ValidateRgn (INTEGER hWnd, INTEGER hRgn);
__EXTERN SET __STDCALL VerFindFileA (SET uFlags, INTEGER szFileName, INTEGER szWinDir, INTEGER szAppDir, INTEGER szCurDir, INTEGER *lpuCurDirLen, INTEGER szDestDir, INTEGER *lpuDestDirLen);
__EXTERN SET __STDCALL VerFindFileW (SET uFlags, INTEGER szFileName, INTEGER szWinDir, INTEGER szAppDir, INTEGER szCurDir, INTEGER *lpuCurDirLen, INTEGER szDestDir, INTEGER *lpuDestDirLen);
__EXTERN SET __STDCALL VerInstallFileA (SET uFlags, INTEGER szSrcFileName, INTEGER szDestFileName, INTEGER szSrcDir, INTEGER szDestDir, INTEGER szCurDir, INTEGER szTmpFile, INTEGER *lpuTmpFileLen);
__EXTERN SET __STDCALL VerInstallFileW (SET uFlags, INTEGER szSrcFileName, INTEGER szDestFileName, INTEGER szSrcDir, INTEGER szDestDir, INTEGER szCurDir, INTEGER szTmpFile, INTEGER *lpuTmpFileLen);
__EXTERN INTEGER __STDCALL VerLanguageNameA (INTEGER wLang, INTEGER szLang, INTEGER nSize);
__EXTERN INTEGER __STDCALL VerLanguageNameW (INTEGER wLang, INTEGER szLang, INTEGER nSize);
__EXTERN INTEGER __STDCALL VerQueryValueA (INTEGER pBlock, INTEGER lpSubBlock, INTEGER lplpBuffer, INTEGER *puLen);
__EXTERN INTEGER __STDCALL VerQueryValueW (INTEGER pBlock, INTEGER lpSubBlock, INTEGER lplpBuffer, INTEGER *puLen);
__EXTERN INTEGER __STDCALL VirtualAlloc (INTEGER lpAddress, INTEGER dwSize, SET flAllocationType, SET flProtect);
__EXTERN INTEGER __STDCALL VirtualAllocEx (INTEGER hProcess, INTEGER lpAddress, INTEGER dwSize, SET flAllocationType, SET flProtect);
__EXTERN INTEGER __STDCALL VirtualFree (INTEGER lpAddress, INTEGER dwSize, SET dwFreeType);
__EXTERN INTEGER __STDCALL VirtualLock (INTEGER lpAddress, INTEGER dwSize);
__EXTERN INTEGER __STDCALL VirtualProtect (INTEGER lpAddress, INTEGER dwSize, SET flNewProtect, INTEGER *lpflOldProtect);
__EXTERN INTEGER __STDCALL VirtualProtectEx (INTEGER hProcess, INTEGER lpAddress, INTEGER dwSize, SET flNewProtect, INTEGER *lpflOldProtect);
__EXTERN INTEGER __STDCALL VirtualQuery (INTEGER lpAddress, WinAPI_MEMORY_BASIC_INFORMATION *lpBuffer, INTEGER dwLength);
__EXTERN INTEGER __STDCALL VirtualQueryEx (INTEGER hProcess, INTEGER lpAddress, WinAPI_MEMORY_BASIC_INFORMATION *lpBuffer, INTEGER dwLength);
__EXTERN INTEGER __STDCALL VirtualUnlock (INTEGER lpAddress, INTEGER dwSize);
__EXTERN SHORTINT __STDCALL VkKeyScanA (CHAR ch);
__EXTERN SHORTINT __STDCALL VkKeyScanExA (CHAR ch, INTEGER dwhkl);
__EXTERN SHORTINT __STDCALL VkKeyScanExW (SHORTINT ch, INTEGER dwhkl);
__EXTERN SHORTINT __STDCALL VkKeyScanW (SHORTINT ch);
__EXTERN INTEGER __STDCALL WaitCommEvent (INTEGER hFile, SET *lpEvtMask, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL WaitForDebugEvent (WinAPI_DEBUG_EVENT *lpDebugEvent, INTEGER dwMilliseconds);
__EXTERN INTEGER __STDCALL WaitForInputIdle (INTEGER hProcess, INTEGER dwMilliseconds);
__EXTERN INTEGER __STDCALL WaitForMultipleObjects (INTEGER nCount, INTEGER *lpHandles, INTEGER bWaitAll, INTEGER dwMilliseconds);
__EXTERN INTEGER __STDCALL WaitForMultipleObjectsEx (INTEGER nCount, INTEGER *lpHandles, INTEGER bWaitAll, INTEGER dwMilliseconds, INTEGER bAlertable);
__EXTERN INTEGER __STDCALL WaitForPrinterChange (INTEGER hPrinter, SET Flags);
__EXTERN INTEGER __STDCALL WaitForSingleObject (INTEGER hHandle, INTEGER dwMilliseconds);
__EXTERN INTEGER __STDCALL WaitForSingleObjectEx (INTEGER hHandle, INTEGER dwMilliseconds, INTEGER bAlertable);
__EXTERN INTEGER __STDCALL WaitMessage (void);
__EXTERN INTEGER __STDCALL WaitNamedPipeA (INTEGER lpNamedPipeName, INTEGER nTimeOut);
__EXTERN INTEGER __STDCALL WaitNamedPipeW (INTEGER lpNamedPipeName, INTEGER nTimeOut);
__EXTERN INTEGER __STDCALL WideCharToMultiByte (INTEGER CodePage, SET dwFlags, INTEGER lpWideCharStr, INTEGER cchWideChar, INTEGER lpMultiByteStr, INTEGER cchMultiByte, INTEGER lpDefaultChar, INTEGER *lpUsedDefaultChar);
__EXTERN INTEGER __STDCALL WidenPath (INTEGER p0);
__EXTERN INTEGER __STDCALL WinExec (INTEGER lpCmdLine, INTEGER uCmdShow);
__EXTERN INTEGER __STDCALL WinHelpA (INTEGER hWndMain, INTEGER lpszHelp, INTEGER uCommand, INTEGER dwData);
__EXTERN INTEGER __STDCALL WinHelpW (INTEGER hWndMain, INTEGER lpszHelp, INTEGER uCommand, INTEGER dwData);
__EXTERN INTEGER __STDCALL WindowFromDC (INTEGER hDC);
__EXTERN INTEGER __STDCALL WindowFromPoint (WinAPI_POINT *Point);
__EXTERN INTEGER __STDCALL WriteConsoleA (INTEGER hConsoleOutput, INTEGER lpBuffer, INTEGER nNumberOfCharsToWrite, INTEGER *lpNumberOfCharsWritten, INTEGER lpReserved);
__EXTERN INTEGER __STDCALL WriteConsoleInputA (INTEGER hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsWritten);
__EXTERN INTEGER __STDCALL WriteConsoleInputW (INTEGER hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsWritten);
__EXTERN INTEGER __STDCALL WriteConsoleOutputA (INTEGER hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD *dwBufferSize, WinAPI_COORD *dwBufferCoord, WinAPI_SMALL_RECT *lpWriteRegion);
__EXTERN INTEGER __STDCALL WriteConsoleOutputAttribute (INTEGER hConsoleOutput, SHORTINT *lpAttribute, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfAttrsWritten);
__EXTERN INTEGER __STDCALL WriteConsoleOutputCharacterA (INTEGER hConsoleOutput, INTEGER lpCharacter, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
__EXTERN INTEGER __STDCALL WriteConsoleOutputCharacterW (INTEGER hConsoleOutput, INTEGER lpCharacter, INTEGER nLength, WinAPI_COORD *dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
__EXTERN INTEGER __STDCALL WriteConsoleOutputW (INTEGER hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD *dwBufferSize, WinAPI_COORD *dwBufferCoord, WinAPI_SMALL_RECT *lpWriteRegion);
__EXTERN INTEGER __STDCALL WriteConsoleW (INTEGER hConsoleOutput, INTEGER lpBuffer, INTEGER nNumberOfCharsToWrite, INTEGER *lpNumberOfCharsWritten, INTEGER lpReserved);
__EXTERN INTEGER __STDCALL WriteFile (INTEGER hFile, INTEGER lpBuffer, INTEGER nNumberOfBytesToWrite, INTEGER *lpNumberOfBytesWritten, WinAPI_OVERLAPPED *lpOverlapped);
__EXTERN INTEGER __STDCALL WriteFileEx (INTEGER hFile, INTEGER lpBuffer, INTEGER nNumberOfBytesToWrite, WinAPI_OVERLAPPED *lpOverlapped, WinAPI_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
__EXTERN INTEGER __STDCALL WritePrinter (INTEGER hPrinter, INTEGER pBuf, INTEGER cbBuf, INTEGER *pcWritten);
__EXTERN INTEGER __STDCALL WritePrivateProfileSectionA (INTEGER lpAppName, INTEGER lpString, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL WritePrivateProfileSectionW (INTEGER lpAppName, INTEGER lpString, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL WritePrivateProfileStringA (INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpString, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL WritePrivateProfileStringW (INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpString, INTEGER lpFileName);
__EXTERN INTEGER __STDCALL WritePrivateProfileStructA (INTEGER lpszSection, INTEGER lpszKey, INTEGER lpStruct, INTEGER uSizeStruct, INTEGER szFile);
__EXTERN INTEGER __STDCALL WritePrivateProfileStructW (INTEGER lpszSection, INTEGER lpszKey, INTEGER lpStruct, INTEGER uSizeStruct, INTEGER szFile);
__EXTERN INTEGER __STDCALL WriteProcessMemory (INTEGER hProcess, INTEGER lpBaseAddress, INTEGER lpBuffer, INTEGER nSize, INTEGER *lpNumberOfBytesWritten);
__EXTERN INTEGER __STDCALL WriteProfileSectionA (INTEGER lpAppName, INTEGER lpString);
__EXTERN INTEGER __STDCALL WriteProfileSectionW (INTEGER lpAppName, INTEGER lpString);
__EXTERN INTEGER __STDCALL WriteProfileStringA (INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpString);
__EXTERN INTEGER __STDCALL WriteProfileStringW (INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpString);
__EXTERN INTEGER __STDCALL WriteTapemark (INTEGER hDevice, INTEGER dwTapemarkType, INTEGER dwTapemarkCount, INTEGER bImmediate);
__EXTERN INTEGER __STDCALL _hread (INTEGER hFile, INTEGER lpBuffer, INTEGER lBytes);
__EXTERN INTEGER __STDCALL _hwrite (INTEGER hFile, INTEGER lpBuffer, INTEGER lBytes);
__EXTERN INTEGER __STDCALL _lclose (INTEGER hFile);
__EXTERN INTEGER __STDCALL _lcreat (INTEGER lpPathName, INTEGER iAttribute);
__EXTERN INTEGER __STDCALL _llseek (INTEGER hFile, INTEGER lOffset, INTEGER iOrigin);
__EXTERN INTEGER __STDCALL _lopen (INTEGER lpPathName, INTEGER iReadWrite);
__EXTERN INTEGER __STDCALL _lread (INTEGER hFile, INTEGER lpBuffer, INTEGER uBytes);
__EXTERN INTEGER __STDCALL _lwrite (INTEGER hFile, INTEGER lpBuffer, INTEGER uBytes);
__EXTERN void __STDCALL keybd_event (CHAR bVk, CHAR bScan, SET dwFlags, INTEGER dwExtraInfo);
__EXTERN INTEGER __STDCALL lstrcatA (INTEGER lpString1, INTEGER lpString2);
__EXTERN INTEGER __STDCALL lstrcatW (INTEGER lpString1, INTEGER lpString2);
__EXTERN INTEGER __STDCALL lstrcmpA (INTEGER lpString1, INTEGER lpString2);
__EXTERN INTEGER __STDCALL lstrcmpW (INTEGER lpString1, INTEGER lpString2);
__EXTERN INTEGER __STDCALL lstrcmpiA (INTEGER lpString1, INTEGER lpString2);
__EXTERN INTEGER __STDCALL lstrcmpiW (INTEGER lpString1, INTEGER lpString2);
__EXTERN INTEGER __STDCALL lstrcpyA (INTEGER lpString1, INTEGER lpString2);
__EXTERN INTEGER __STDCALL lstrcpyW (INTEGER lpString1, INTEGER lpString2);
__EXTERN INTEGER __STDCALL lstrcpynA (INTEGER lpString1, INTEGER lpString2, INTEGER iMaxLength);
__EXTERN INTEGER __STDCALL lstrcpynW (INTEGER lpString1, INTEGER lpString2, INTEGER iMaxLength);
__EXTERN INTEGER __STDCALL lstrlenA (INTEGER lpString);
__EXTERN INTEGER __STDCALL lstrlenW (INTEGER lpString);
__EXTERN void __STDCALL mouse_event (SET dwFlags, INTEGER dx, INTEGER dy, INTEGER cButtons, INTEGER dwExtraInfo);
__EXTERN INTEGER __STDCALL wglCopyContext (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL wglCreateContext (INTEGER p0);
__EXTERN INTEGER __STDCALL wglCreateLayerContext (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL wglDeleteContext (INTEGER p0);
__EXTERN INTEGER __STDCALL wglDescribeLayerPlane (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_LAYERPLANEDESCRIPTOR *p4);
__EXTERN INTEGER __STDCALL wglGetCurrentContext (void);
__EXTERN INTEGER __STDCALL wglGetCurrentDC (void);
__EXTERN INTEGER __STDCALL wglGetLayerPaletteEntries (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4);
__EXTERN WinAPI_ROC __STDCALL wglGetProcAddress (INTEGER p0);
__EXTERN INTEGER __STDCALL wglMakeCurrent (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL wglRealizeLayerPalette (INTEGER p0, INTEGER p1, INTEGER p2);
__EXTERN INTEGER __STDCALL wglSetLayerPaletteEntries (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4);
__EXTERN INTEGER __STDCALL wglShareLists (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL wglSwapLayerBuffers (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL wglUseFontBitmapsA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL wglUseFontBitmapsW (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
__EXTERN INTEGER __STDCALL wglUseFontOutlinesA (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, SHORTREAL p4, SHORTREAL p5, INTEGER p6, WinAPI_GLYPHMETRICSFLOAT *p7);
__EXTERN INTEGER __STDCALL wglUseFontOutlinesW (INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, SHORTREAL p4, SHORTREAL p5, INTEGER p6, WinAPI_GLYPHMETRICSFLOAT *p7);
__EXTERN INTEGER wsprintfA (INTEGER p0, INTEGER p1);
__EXTERN INTEGER wsprintfW (INTEGER p0, INTEGER p1);
__EXTERN INTEGER __STDCALL wvsprintfA (INTEGER p0, INTEGER p1, INTEGER arglist);
__EXTERN INTEGER __STDCALL wvsprintfW (INTEGER p0, INTEGER p1, INTEGER arglist);
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

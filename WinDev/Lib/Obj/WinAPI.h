/* Ofront+ 1.0 -sC -48 */

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
	INTEGER FiberData;
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
	INTEGER ForwarderString;
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

struct WinAPI__23 {
	INTEGER hMem;
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
	INTEGER pszTemplate;
};

struct WinAPI__28 {
	INTEGER hIcon;
};

struct WinAPI__32 {
	INTEGER pszTemplate;
};

struct WinAPI__33 {
	INTEGER hIcon;
};

struct WinAPI__25 {
	INTEGER hIcon;
};

struct WinAPI__26 {
	INTEGER pStartPage;
};

typedef
	struct WinAPI_PROPSHEETPAGEA *WinAPI_PtrPROPSHEETPAGEA;

struct WinAPI__29 {
	WinAPI_PtrPROPSHEETPAGEA ppsp;
};

struct WinAPI__30 {
	INTEGER hIcon;
};

struct WinAPI__31 {
	INTEGER pStartPage;
};

typedef
	struct WinAPI_PROPSHEETPAGEW *WinAPI_PtrPROPSHEETPAGEW;

struct WinAPI__34 {
	WinAPI_PtrPROPSHEETPAGEW ppsp;
};

struct WinAPI__21 {
	INTEGER cbBuf, pBuf;
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
		REAL abcfA, abcfB, abcfC;
	} WinAPI_ABCFLOAT;

typedef
	INTEGER (__CALL_1 *WinAPI_ABORTPROC)(INTEGER, INTEGER);

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
	void (__CALL_1 *WinAPI_APCFUNC)(INTEGER);

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
	INTEGER (__CALL_1 *WinAPI_CALINFO_ENUMPROCA)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_CALINFO_ENUMPROCW)(void);

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
	INTEGER (__CALL_1 *WinAPI_CODEPAGE_ENUMPROCA)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_CODEPAGE_ENUMPROCW)(void);

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
	INTEGER (__CALL_1 *WinAPI_THREAD_START_ROUTINE)(INTEGER);

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
	INTEGER (__CALL_1 *WinAPI_DATEFMT_ENUMPROCA)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_DATEFMT_ENUMPROCW)(void);

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
	INTEGER (__CALL_1 *WinAPI_DESKTOPENUMPROC)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_DESKTOPENUMPROCA)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_DESKTOPENUMPROCW)(void);

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
	INTEGER (__CALL_1 *WinAPI_DLGPROC)(INTEGER, INTEGER, INTEGER, INTEGER);

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
	INTEGER (__CALL_1 *WinAPI_DRAWSTATEPROC)(void);

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
	INTEGER (__CALL_1 *WinAPI_EDITWORDBREAKPROC)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_EDITWORDBREAKPROCA)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_EDITWORDBREAKPROCW)(void);

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
		REAL eStartAngle, eSweepAngle;
	} WinAPI_EMRANGLEARC;

typedef
	struct WinAPI_EMRARC {
		WinAPI_EMR emr;
		WinAPI_RECT rclBox;
		WinAPI_POINT ptlStart, ptlEnd;
	} WinAPI_EMRARC;

typedef
	struct WinAPI_XFORM {
		REAL eM11, eM12, eM21, eM22, eDx, eDy;
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
		REAL exScale, eyScale;
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
		REAL exScale, eyScale;
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
		REAL eMiterLimit;
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
	INTEGER (__CALL_1 *WinAPI_ENHMFENUMPROC)(INTEGER, WinAPI_HANDLETABLE*, SYSTEM_ADRINT *, WinAPI_ENHMETARECORD*, SYSTEM_ADRINT *, INTEGER, INTEGER);

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
	INTEGER (__CALL_1 *WinAPI_ENUMRESLANGPROC)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_ENUMRESNAMEPROC)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_ENUMRESTYPEPROC)(void);

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
	INTEGER (__CALL_1 *WinAPI_FARPROC)(void);

typedef
	void (__CALL_1 *WinAPI_FIBER_START_ROUTINE)(INTEGER);

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
	INTEGER (__CALL_1 *WinAPI_FNADDPROPSHEETPAGE)(WinAPI_Ptr_PSP, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_FNADDPROPSHEETPAGES)(INTEGER, WinAPI_FNADDPROPSHEETPAGE, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_FNCALLBACK)(INTEGER, INTEGER, INTEGER, INTEGER, INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_FNDEVCAPS)(INTEGER, INTEGER, INTEGER, INTEGER, WinAPI_DEVMODEA*, SYSTEM_ADRINT *);

typedef
	INTEGER (__CALL_1 *WinAPI_FNDEVMODE)(INTEGER, INTEGER, WinAPI_DEVMODEA*, SYSTEM_ADRINT *, INTEGER, INTEGER, WinAPI_DEVMODEA*, SYSTEM_ADRINT *, INTEGER, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_FNPROPSHEETCALLBACK)(INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_FNPSPCALLBACKA)(INTEGER, INTEGER, WinAPI_PtrPROPSHEETPAGEA);

typedef
	INTEGER (__CALL_1 *WinAPI_FNPSPCALLBACKW)(INTEGER, INTEGER, WinAPI_PtrPROPSHEETPAGEW);

typedef
	struct WinAPI_FOCUS_EVENT_RECORD {
		INTEGER bSetFocus;
	} WinAPI_FOCUS_EVENT_RECORD;

typedef
	INTEGER (__CALL_1 *WinAPI_FONTENUMPROC)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_FONTENUMPROCA)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_FONTENUMPROCEX)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_FONTENUMPROCEXA)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_FONTENUMPROCEXW)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_FONTENUMPROCW)(INTEGER, INTEGER, INTEGER, INTEGER);

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
		REAL x, y;
	} WinAPI_POINTFLOAT;

typedef
	struct WinAPI_GLYPHMETRICSFLOAT {
		REAL gmfBlackBoxX, gmfBlackBoxY;
		WinAPI_POINTFLOAT gmfptGlyphOrigin;
		REAL gmfCellIncX, gmfCellIncY;
	} WinAPI_GLYPHMETRICSFLOAT;

typedef
	INTEGER (__CALL_1 *WinAPI_GOBJENUMPROC)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_GRAYSTRINGPROC)(void);

typedef
	void (__CALL_1 *WinAPI_HANDLER_FUNCTION)(INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_HANDLER_ROUTINE)(INTEGER);

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
	INTEGER (__CALL_1 *WinAPI_HOOKPROC)(void);

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
	INTEGER (__CALL_1 *WinAPI_ICMENUMPROCA)(INTEGER, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_ICMENUMPROCW)(INTEGER, INTEGER);

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
		INTEGER BeginAddress, EndAddress, ExceptionHandler, HandlerData, PrologEndAddress;
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
	void (__CALL_1 *WinAPI_IMAGE_TLS_CALLBACK)(INTEGER, INTEGER, INTEGER);

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
		struct WinAPI__17 Event;
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
		struct WinAPI__19 HighWord;
	} WinAPI_LDT_ENTRY;

typedef
	INTEGER (__CALL_1 *WinAPI_LINEDDAPROC)(void);

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
	INTEGER (__CALL_1 *WinAPI_LOCALE_ENUMPROCA)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_LOCALE_ENUMPROCW)(void);

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
	INTEGER (__CALL_1 *WinAPI_MFENUMPROC)(INTEGER, WinAPI_HANDLETABLE*, SYSTEM_ADRINT *, WinAPI_METARECORD*, SYSTEM_ADRINT *, INTEGER, INTEGER);

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
	void (__CALL_1 *WinAPI_MSGBOXCALLBACK)(WinAPI_HELPINFO*, SYSTEM_ADRINT *);

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
	INTEGER (__CALL_1 *WinAPI_NAMEENUMPROCA)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_NAMEENUMPROCW)(void);

typedef
	struct WinAPI_WINDOWPOS *WinAPI_PtrWINDOWPOS;

typedef
	struct WinAPI_NCCALCSIZE_PARAMS {
		WinAPI_RECT rgrc[3];
		WinAPI_PtrWINDOWPOS lppos;
	} WinAPI_NCCALCSIZE_PARAMS;

typedef
	INTEGER (__CALL_1 *WinAPI_NEARPROC)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_NEWFONTENUMPROC)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_NEWFONTENUMPROCA)(INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_NEWFONTENUMPROCW)(INTEGER, INTEGER, INTEGER, INTEGER);

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
		struct WinAPI__20 u;
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
	INTEGER (__CALL_1 *WinAPI_OLDFONTENUMPROC)(void);

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
	void (__CALL_1 *WinAPI_OVERLAPPED_COMPLETION_ROUTINE)(INTEGER, INTEGER, WinAPI_OVERLAPPED*, SYSTEM_ADRINT *);

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
		struct WinAPI__24 u;
	} WinAPI_PROCESS_HEAP_ENTRY;

typedef
	struct WinAPI_PROCESS_INFORMATION {
		INTEGER hProcess, hThread, dwProcessId, dwThreadId;
	} WinAPI_PROCESS_INFORMATION;

typedef
	INTEGER (__CALL_1 *WinAPI_PROGRESS_ROUTINE)(LONGINT, LONGINT, LONGINT, LONGINT, INTEGER, INTEGER, INTEGER, INTEGER, INTEGER);

typedef
	struct WinAPI_PROPSHEETHEADERA {
		INTEGER dwSize;
		SET dwFlags;
		INTEGER hwndParent, hInstance;
		struct WinAPI__25 u;
		INTEGER pszCaption, nPages;
		struct WinAPI__26 u1;
		struct WinAPI__29 u2;
		WinAPI_FNPROPSHEETCALLBACK pfnCallback;
	} WinAPI_PROPSHEETHEADERA;

typedef
	struct WinAPI_PROPSHEETHEADERW {
		INTEGER dwSize;
		SET dwFlags;
		INTEGER hwndParent, hInstance;
		struct WinAPI__30 u;
		INTEGER pszCaption, nPages;
		struct WinAPI__31 u1;
		struct WinAPI__34 u2;
		WinAPI_FNPROPSHEETCALLBACK pfnCallback;
	} WinAPI_PROPSHEETHEADERW;

typedef
	struct WinAPI_PROPSHEETPAGEA {
		INTEGER dwSize;
		SET dwFlags;
		INTEGER hInstance;
		struct WinAPI__27 u;
		struct WinAPI__28 u1;
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
		struct WinAPI__32 u;
		struct WinAPI__33 u1;
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
	INTEGER (__CALL_1 *WinAPI_QUERYHANDLER)(INTEGER, WinAPI_val_context*, SYSTEM_ADRINT *, INTEGER, INTEGER, INTEGER*, INTEGER);

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
	INTEGER (__CALL_1 *WinAPI_ROC)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_ROPENUMPROC)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_ROPENUMPROCA)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_ROPENUMPROCEX)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_ROPENUMPROCEXA)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_ROPENUMPROCEXW)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_ROPENUMPROCW)(void);

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
	INTEGER (__CALL_1 *WinAPI_SENDASYNCPROC)(void);

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
	void (__CALL_1 *WinAPI_SERVICE_MAIN_FUNCTIONA)(INTEGER, INTEGER);

typedef
	void (__CALL_1 *WinAPI_SERVICE_MAIN_FUNCTIONW)(INTEGER, INTEGER);

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
	INTEGER (__CALL_1 *WinAPI_TIMEFMT_ENUMPROCA)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_TIMEFMT_ENUMPROCW)(void);

typedef
	void (__CALL_1 *WinAPI_TIMERAPCROUTINE)(INTEGER, INTEGER, INTEGER);

typedef
	INTEGER (__CALL_1 *WinAPI_TIMERPROC)(void);

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
	INTEGER (__CALL_1 *WinAPI_TOP_LEVEL_EXCEPTION_FILTER)(WinAPI_EXCEPTION_POINTERS*, SYSTEM_ADRINT *);

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
	INTEGER (__CALL_1 *WinAPI_WINSTAENUMPROC)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_WINSTAENUMPROCA)(void);

typedef
	INTEGER (__CALL_1 *WinAPI_WINSTAENUMPROCW)(void);

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
	INTEGER (__CALL_1 *WinAPI_WNDPROC)(INTEGER, INTEGER, INTEGER, INTEGER);

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
	INTEGER (__CALL_1 *WinAPI_WNDENUMPROC)(void);

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



import SYSTEM_ADRINT *WinAPI_LIST_ENTRY__typ;
import SYSTEM_ADRINT *WinAPI_SINGLE_LIST_ENTRY__typ;
import SYSTEM_ADRINT *WinAPI_COM_GUID__typ;
import SYSTEM_ADRINT *WinAPI_OBJECTID__typ;
import SYSTEM_ADRINT *WinAPI_FLOATING_SAVE_AREA__typ;
import SYSTEM_ADRINT *WinAPI_CONTEXT__typ;
import SYSTEM_ADRINT *WinAPI__18__typ;
import SYSTEM_ADRINT *WinAPI__19__typ;
import SYSTEM_ADRINT *WinAPI_LDT_ENTRY__typ;
import SYSTEM_ADRINT *WinAPI_EXCEPTION_RECORD__typ;
import SYSTEM_ADRINT *WinAPI_EXCEPTION_POINTERS__typ;
import SYSTEM_ADRINT *WinAPI__EXCEPTION_REGISTRATION_RECORD__typ;
import SYSTEM_ADRINT *WinAPI__20__typ;
import SYSTEM_ADRINT *WinAPI_NT_TIB__typ;
import SYSTEM_ADRINT *WinAPI_QUOTA_LIMITS__typ;
import SYSTEM_ADRINT *WinAPI_MEMORY_BASIC_INFORMATION__typ;
import SYSTEM_ADRINT *WinAPI_FILE_NOTIFY_INFORMATION__typ;
import SYSTEM_ADRINT *WinAPI_GENERIC_MAPPING__typ;
import SYSTEM_ADRINT *WinAPI_LUID_AND_ATTRIBUTES__typ;
import SYSTEM_ADRINT *WinAPI_SID_IDENTIFIER_AUTHORITY__typ;
import SYSTEM_ADRINT *WinAPI_SID__typ;
import SYSTEM_ADRINT *WinAPI_SID_AND_ATTRIBUTES__typ;
import SYSTEM_ADRINT *WinAPI_ACL__typ;
import SYSTEM_ADRINT *WinAPI_ACE_HEADER__typ;
import SYSTEM_ADRINT *WinAPI_ACCESS_ALLOWED_ACE__typ;
import SYSTEM_ADRINT *WinAPI_ACCESS_DENIED_ACE__typ;
import SYSTEM_ADRINT *WinAPI_SYSTEM_AUDIT_ACE__typ;
import SYSTEM_ADRINT *WinAPI_SYSTEM_ALARM_ACE__typ;
import SYSTEM_ADRINT *WinAPI_COMPOUND_ACCESS_ALLOWED_ACE__typ;
import SYSTEM_ADRINT *WinAPI_ACL_REVISION_INFORMATION__typ;
import SYSTEM_ADRINT *WinAPI_ACL_SIZE_INFORMATION__typ;
import SYSTEM_ADRINT *WinAPI_SECURITY_DESCRIPTOR__typ;
import SYSTEM_ADRINT *WinAPI_PRIVILEGE_SET__typ;
import SYSTEM_ADRINT *WinAPI_TOKEN_USER__typ;
import SYSTEM_ADRINT *WinAPI_TOKEN_GROUPS__typ;
import SYSTEM_ADRINT *WinAPI_TOKEN_PRIVILEGES__typ;
import SYSTEM_ADRINT *WinAPI_TOKEN_OWNER__typ;
import SYSTEM_ADRINT *WinAPI_TOKEN_PRIMARY_GROUP__typ;
import SYSTEM_ADRINT *WinAPI_TOKEN_DEFAULT_DACL__typ;
import SYSTEM_ADRINT *WinAPI_TOKEN_SOURCE__typ;
import SYSTEM_ADRINT *WinAPI_TOKEN_STATISTICS__typ;
import SYSTEM_ADRINT *WinAPI_TOKEN_CONTROL__typ;
import SYSTEM_ADRINT *WinAPI_SECURITY_QUALITY_OF_SERVICE__typ;
import SYSTEM_ADRINT *WinAPI_SE_IMPERSONATION_STATE__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_DOS_HEADER__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_OS2_HEADER__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_VXD_HEADER__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_FILE_HEADER__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_DATA_DIRECTORY__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_OPTIONAL_HEADER__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_ROM_OPTIONAL_HEADER__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_NT_HEADERS__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_ROM_HEADERS__typ;
import SYSTEM_ADRINT *WinAPI__14__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_SECTION_HEADER__typ;
import SYSTEM_ADRINT *WinAPI__15__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_SYMBOL__typ;
import SYSTEM_ADRINT *WinAPI__3__typ;
import SYSTEM_ADRINT *WinAPI__4__typ;
import SYSTEM_ADRINT *WinAPI__5__typ;
import SYSTEM_ADRINT *WinAPI__6__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_AUX_SYMBOL__typ;
import SYSTEM_ADRINT *WinAPI__10__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_RELOCATION__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_BASE_RELOCATION__typ;
import SYSTEM_ADRINT *WinAPI__9__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_LINENUMBER__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_ARCHIVE_MEMBER_HEADER__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_EXPORT_DIRECTORY__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_IMPORT_BY_NAME__typ;
import SYSTEM_ADRINT *WinAPI__7__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_THUNK_DATA__typ;
import SYSTEM_ADRINT *WinAPI__8__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_IMPORT_DESCRIPTOR__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_BOUND_IMPORT_DESCRIPTOR__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_BOUND_FORWARDER_REF__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_TLS_DIRECTORY__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_RESOURCE_DIRECTORY__typ;
import SYSTEM_ADRINT *WinAPI__11__typ;
import SYSTEM_ADRINT *WinAPI__12__typ;
import SYSTEM_ADRINT *WinAPI__13__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_RESOURCE_DIRECTORY_ENTRY__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_RESOURCE_DIRECTORY_STRING__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_RESOURCE_DIR_STRING_U__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_RESOURCE_DATA_ENTRY__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_LOAD_CONFIG_DIRECTORY__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_RUNTIME_FUNCTION_ENTRY__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_DEBUG_DIRECTORY__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_COFF_SYMBOLS_HEADER__typ;
import SYSTEM_ADRINT *WinAPI_FPO_DATA__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_DEBUG_MISC__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_FUNCTION_ENTRY__typ;
import SYSTEM_ADRINT *WinAPI_IMAGE_SEPARATE_DEBUG_HEADER__typ;
import SYSTEM_ADRINT *WinAPI_MESSAGE_RESOURCE_ENTRY__typ;
import SYSTEM_ADRINT *WinAPI_MESSAGE_RESOURCE_BLOCK__typ;
import SYSTEM_ADRINT *WinAPI_MESSAGE_RESOURCE_DATA__typ;
import SYSTEM_ADRINT *WinAPI_RTL_CRITICAL_SECTION_DEBUG__typ;
import SYSTEM_ADRINT *WinAPI_RTL_CRITICAL_SECTION__typ;
import SYSTEM_ADRINT *WinAPI_EVENTLOGRECORD__typ;
import SYSTEM_ADRINT *WinAPI_TAPE_ERASE__typ;
import SYSTEM_ADRINT *WinAPI_TAPE_PREPARE__typ;
import SYSTEM_ADRINT *WinAPI_TAPE_WRITE_MARKS__typ;
import SYSTEM_ADRINT *WinAPI_TAPE_GET_POSITION__typ;
import SYSTEM_ADRINT *WinAPI_TAPE_SET_POSITION__typ;
import SYSTEM_ADRINT *WinAPI_TAPE_GET_DRIVE_PARAMETERS__typ;
import SYSTEM_ADRINT *WinAPI_TAPE_SET_DRIVE_PARAMETERS__typ;
import SYSTEM_ADRINT *WinAPI_TAPE_GET_MEDIA_PARAMETERS__typ;
import SYSTEM_ADRINT *WinAPI_TAPE_SET_MEDIA_PARAMETERS__typ;
import SYSTEM_ADRINT *WinAPI_TAPE_CREATE_PARTITION__typ;
import SYSTEM_ADRINT *WinAPI_RECT__typ;
import SYSTEM_ADRINT *WinAPI__RECTL__typ;
import SYSTEM_ADRINT *WinAPI_POINT__typ;
import SYSTEM_ADRINT *WinAPI__POINTL__typ;
import SYSTEM_ADRINT *WinAPI_SIZE__typ;
import SYSTEM_ADRINT *WinAPI_POINTS__typ;
import SYSTEM_ADRINT *WinAPI_OVERLAPPED__typ;
import SYSTEM_ADRINT *WinAPI_SECURITY_ATTRIBUTES__typ;
import SYSTEM_ADRINT *WinAPI_PROCESS_INFORMATION__typ;
import SYSTEM_ADRINT *WinAPI_FILETIME__typ;
import SYSTEM_ADRINT *WinAPI_SYSTEMTIME__typ;
import SYSTEM_ADRINT *WinAPI_COMMPROP__typ;
import SYSTEM_ADRINT *WinAPI_COMSTAT__typ;
import SYSTEM_ADRINT *WinAPI_DCB__typ;
import SYSTEM_ADRINT *WinAPI_COMMTIMEOUTS__typ;
import SYSTEM_ADRINT *WinAPI_COMMCONFIG__typ;
import SYSTEM_ADRINT *WinAPI__35__typ;
import SYSTEM_ADRINT *WinAPI_SYSTEM_INFO__typ;
import SYSTEM_ADRINT *WinAPI_MEMORYSTATUS__typ;
import SYSTEM_ADRINT *WinAPI_EXCEPTION_DEBUG_INFO__typ;
import SYSTEM_ADRINT *WinAPI_CREATE_THREAD_DEBUG_INFO__typ;
import SYSTEM_ADRINT *WinAPI_CREATE_PROCESS_DEBUG_INFO__typ;
import SYSTEM_ADRINT *WinAPI_EXIT_THREAD_DEBUG_INFO__typ;
import SYSTEM_ADRINT *WinAPI_EXIT_PROCESS_DEBUG_INFO__typ;
import SYSTEM_ADRINT *WinAPI_LOAD_DLL_DEBUG_INFO__typ;
import SYSTEM_ADRINT *WinAPI_UNLOAD_DLL_DEBUG_INFO__typ;
import SYSTEM_ADRINT *WinAPI_OUTPUT_DEBUG_STRING_INFO__typ;
import SYSTEM_ADRINT *WinAPI_RIP_INFO__typ;
import SYSTEM_ADRINT *WinAPI__2__typ;
import SYSTEM_ADRINT *WinAPI_DEBUG_EVENT__typ;
import SYSTEM_ADRINT *WinAPI_OFSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI__23__typ;
import SYSTEM_ADRINT *WinAPI__24__typ;
import SYSTEM_ADRINT *WinAPI_PROCESS_HEAP_ENTRY__typ;
import SYSTEM_ADRINT *WinAPI_BY_HANDLE_FILE_INFORMATION__typ;
import SYSTEM_ADRINT *WinAPI_TIME_ZONE_INFORMATION__typ;
import SYSTEM_ADRINT *WinAPI_WIN32_STREAM_ID__typ;
import SYSTEM_ADRINT *WinAPI_STARTUPINFOA__typ;
import SYSTEM_ADRINT *WinAPI_STARTUPINFOW__typ;
import SYSTEM_ADRINT *WinAPI_WIN32_FIND_DATAA__typ;
import SYSTEM_ADRINT *WinAPI_WIN32_FIND_DATAW__typ;
import SYSTEM_ADRINT *WinAPI_WIN32_FILE_ATTRIBUTE_DATA__typ;
import SYSTEM_ADRINT *WinAPI_HW_PROFILE_INFOA__typ;
import SYSTEM_ADRINT *WinAPI_HW_PROFILE_INFOW__typ;
import SYSTEM_ADRINT *WinAPI_OSVERSIONINFOA__typ;
import SYSTEM_ADRINT *WinAPI_OSVERSIONINFOW__typ;
import SYSTEM_ADRINT *WinAPI_SYSTEM_POWER_STATUS__typ;
import SYSTEM_ADRINT *WinAPI_WIN_CERTIFICATE__typ;
import SYSTEM_ADRINT *WinAPI_WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT__typ;
import SYSTEM_ADRINT *WinAPI_WIN_TRUST_ACTDATA_SUBJECT_ONLY__typ;
import SYSTEM_ADRINT *WinAPI_WIN_TRUST_SUBJECT_FILE__typ;
import SYSTEM_ADRINT *WinAPI_WIN_SPUB_TRUSTEDPUB_DATA__typ;
import SYSTEM_ADRINT *WinAPI_XFORM__typ;
import SYSTEM_ADRINT *WinAPI_BITMAP__typ;
import SYSTEM_ADRINT *WinAPI_RGBTRIPLE__typ;
import SYSTEM_ADRINT *WinAPI_RGBQUAD__typ;
import SYSTEM_ADRINT *WinAPI_CIEXYZ__typ;
import SYSTEM_ADRINT *WinAPI_CIEXYZTRIPLE__typ;
import SYSTEM_ADRINT *WinAPI_LOGCOLORSPACEA__typ;
import SYSTEM_ADRINT *WinAPI_LOGCOLORSPACEW__typ;
import SYSTEM_ADRINT *WinAPI_BITMAPCOREHEADER__typ;
import SYSTEM_ADRINT *WinAPI_BITMAPINFOHEADER__typ;
import SYSTEM_ADRINT *WinAPI_BITMAPV4HEADER__typ;
import SYSTEM_ADRINT *WinAPI_BITMAPINFO__typ;
import SYSTEM_ADRINT *WinAPI_BITMAPCOREINFO__typ;
import SYSTEM_ADRINT *WinAPI_BITMAPFILEHEADER__typ;
import SYSTEM_ADRINT *WinAPI_FONTSIGNATURE__typ;
import SYSTEM_ADRINT *WinAPI_CHARSETINFO__typ;
import SYSTEM_ADRINT *WinAPI_LOCALESIGNATURE__typ;
import SYSTEM_ADRINT *WinAPI_HANDLETABLE__typ;
import SYSTEM_ADRINT *WinAPI_METARECORD__typ;
import SYSTEM_ADRINT *WinAPI_METAFILEPICT__typ;
import SYSTEM_ADRINT *WinAPI_METAHEADER__typ;
import SYSTEM_ADRINT *WinAPI_ENHMETARECORD__typ;
import SYSTEM_ADRINT *WinAPI_ENHMETAHEADER__typ;
import SYSTEM_ADRINT *WinAPI_TEXTMETRICA__typ;
import SYSTEM_ADRINT *WinAPI_TEXTMETRICW__typ;
import SYSTEM_ADRINT *WinAPI_NEWTEXTMETRICA__typ;
import SYSTEM_ADRINT *WinAPI_NEWTEXTMETRICW__typ;
import SYSTEM_ADRINT *WinAPI_NEWTEXTMETRICEXA__typ;
import SYSTEM_ADRINT *WinAPI_NEWTEXTMETRICEXW__typ;
import SYSTEM_ADRINT *WinAPI_PELARRAY__typ;
import SYSTEM_ADRINT *WinAPI_LOGBRUSH__typ;
import SYSTEM_ADRINT *WinAPI_LOGPEN__typ;
import SYSTEM_ADRINT *WinAPI_EXTLOGPEN__typ;
import SYSTEM_ADRINT *WinAPI_PALETTEENTRY__typ;
import SYSTEM_ADRINT *WinAPI_LOGPALETTE__typ;
import SYSTEM_ADRINT *WinAPI_LOGFONTA__typ;
import SYSTEM_ADRINT *WinAPI_LOGFONTW__typ;
import SYSTEM_ADRINT *WinAPI_ENUMLOGFONTA__typ;
import SYSTEM_ADRINT *WinAPI_ENUMLOGFONTW__typ;
import SYSTEM_ADRINT *WinAPI_ENUMLOGFONTEXA__typ;
import SYSTEM_ADRINT *WinAPI_ENUMLOGFONTEXW__typ;
import SYSTEM_ADRINT *WinAPI_PANOSE__typ;
import SYSTEM_ADRINT *WinAPI_EXTLOGFONTA__typ;
import SYSTEM_ADRINT *WinAPI_EXTLOGFONTW__typ;
import SYSTEM_ADRINT *WinAPI_DEVMODEA__typ;
import SYSTEM_ADRINT *WinAPI_DEVMODEW__typ;
import SYSTEM_ADRINT *WinAPI_RGNDATAHEADER__typ;
import SYSTEM_ADRINT *WinAPI_RGNDATA__typ;
import SYSTEM_ADRINT *WinAPI_ABC__typ;
import SYSTEM_ADRINT *WinAPI_ABCFLOAT__typ;
import SYSTEM_ADRINT *WinAPI_OUTLINETEXTMETRICA__typ;
import SYSTEM_ADRINT *WinAPI_OUTLINETEXTMETRICW__typ;
import SYSTEM_ADRINT *WinAPI_POLYTEXTA__typ;
import SYSTEM_ADRINT *WinAPI_POLYTEXTW__typ;
import SYSTEM_ADRINT *WinAPI_FIXED__typ;
import SYSTEM_ADRINT *WinAPI_MAT2__typ;
import SYSTEM_ADRINT *WinAPI_GLYPHMETRICS__typ;
import SYSTEM_ADRINT *WinAPI_POINTFX__typ;
import SYSTEM_ADRINT *WinAPI_TTPOLYCURVE__typ;
import SYSTEM_ADRINT *WinAPI_TTPOLYGONHEADER__typ;
import SYSTEM_ADRINT *WinAPI_GCP_RESULTSA__typ;
import SYSTEM_ADRINT *WinAPI_GCP_RESULTSW__typ;
import SYSTEM_ADRINT *WinAPI_RASTERIZER_STATUS__typ;
import SYSTEM_ADRINT *WinAPI_PIXELFORMATDESCRIPTOR__typ;
import SYSTEM_ADRINT *WinAPI_DIBSECTION__typ;
import SYSTEM_ADRINT *WinAPI_COLORADJUSTMENT__typ;
import SYSTEM_ADRINT *WinAPI_DOCINFOA__typ;
import SYSTEM_ADRINT *WinAPI_DOCINFOW__typ;
import SYSTEM_ADRINT *WinAPI_KERNINGPAIR__typ;
import SYSTEM_ADRINT *WinAPI_EMR__typ;
import SYSTEM_ADRINT *WinAPI_EMRTEXT__typ;
import SYSTEM_ADRINT *WinAPI_EMRABORTPATH__typ;
import SYSTEM_ADRINT *WinAPI_EMRSELECTCLIPPATH__typ;
import SYSTEM_ADRINT *WinAPI_EMRSETMITERLIMIT__typ;
import SYSTEM_ADRINT *WinAPI_EMRRESTOREDC__typ;
import SYSTEM_ADRINT *WinAPI_EMRSETARCDIRECTION__typ;
import SYSTEM_ADRINT *WinAPI_EMRSETMAPPERFLAGS__typ;
import SYSTEM_ADRINT *WinAPI_EMRSETBKCOLOR__typ;
import SYSTEM_ADRINT *WinAPI_EMRSELECTOBJECT__typ;
import SYSTEM_ADRINT *WinAPI_EMRSELECTCOLORSPACE__typ;
import SYSTEM_ADRINT *WinAPI_EMRSELECTPALETTE__typ;
import SYSTEM_ADRINT *WinAPI_EMRRESIZEPALETTE__typ;
import SYSTEM_ADRINT *WinAPI_EMRSETPALETTEENTRIES__typ;
import SYSTEM_ADRINT *WinAPI_EMRSETCOLORADJUSTMENT__typ;
import SYSTEM_ADRINT *WinAPI_EMRGDICOMMENT__typ;
import SYSTEM_ADRINT *WinAPI_EMREOF__typ;
import SYSTEM_ADRINT *WinAPI_EMRLINETO__typ;
import SYSTEM_ADRINT *WinAPI_EMROFFSETCLIPRGN__typ;
import SYSTEM_ADRINT *WinAPI_EMRFILLPATH__typ;
import SYSTEM_ADRINT *WinAPI_EMREXCLUDECLIPRECT__typ;
import SYSTEM_ADRINT *WinAPI_EMRSETVIEWPORTORGEX__typ;
import SYSTEM_ADRINT *WinAPI_EMRSETVIEWPORTEXTEX__typ;
import SYSTEM_ADRINT *WinAPI_EMRSCALEVIEWPORTEXTEX__typ;
import SYSTEM_ADRINT *WinAPI_EMRSETWORLDTRANSFORM__typ;
import SYSTEM_ADRINT *WinAPI_EMRMODIFYWORLDTRANSFORM__typ;
import SYSTEM_ADRINT *WinAPI_EMRSETPIXELV__typ;
import SYSTEM_ADRINT *WinAPI_EMREXTFLOODFILL__typ;
import SYSTEM_ADRINT *WinAPI_EMRELLIPSE__typ;
import SYSTEM_ADRINT *WinAPI_EMRROUNDRECT__typ;
import SYSTEM_ADRINT *WinAPI_EMRARC__typ;
import SYSTEM_ADRINT *WinAPI_EMRANGLEARC__typ;
import SYSTEM_ADRINT *WinAPI_EMRPOLYLINE__typ;
import SYSTEM_ADRINT *WinAPI_EMRPOLYLINE16__typ;
import SYSTEM_ADRINT *WinAPI_EMRPOLYDRAW__typ;
import SYSTEM_ADRINT *WinAPI_EMRPOLYDRAW16__typ;
import SYSTEM_ADRINT *WinAPI_EMRPOLYPOLYLINE__typ;
import SYSTEM_ADRINT *WinAPI_EMRPOLYPOLYLINE16__typ;
import SYSTEM_ADRINT *WinAPI_EMRINVERTRGN__typ;
import SYSTEM_ADRINT *WinAPI_EMRFILLRGN__typ;
import SYSTEM_ADRINT *WinAPI_EMRFRAMERGN__typ;
import SYSTEM_ADRINT *WinAPI_EMREXTSELECTCLIPRGN__typ;
import SYSTEM_ADRINT *WinAPI_EMREXTTEXTOUTA__typ;
import SYSTEM_ADRINT *WinAPI_EMRPOLYTEXTOUTA__typ;
import SYSTEM_ADRINT *WinAPI_EMRBITBLT__typ;
import SYSTEM_ADRINT *WinAPI_EMRSTRETCHBLT__typ;
import SYSTEM_ADRINT *WinAPI_EMRMASKBLT__typ;
import SYSTEM_ADRINT *WinAPI_EMRPLGBLT__typ;
import SYSTEM_ADRINT *WinAPI_EMRSETDIBITSTODEVICE__typ;
import SYSTEM_ADRINT *WinAPI_EMRSTRETCHDIBITS__typ;
import SYSTEM_ADRINT *WinAPI_EMREXTCREATEFONTINDIRECTW__typ;
import SYSTEM_ADRINT *WinAPI_EMRCREATEPALETTE__typ;
import SYSTEM_ADRINT *WinAPI_EMRCREATECOLORSPACE__typ;
import SYSTEM_ADRINT *WinAPI_EMRCREATEPEN__typ;
import SYSTEM_ADRINT *WinAPI_EMREXTCREATEPEN__typ;
import SYSTEM_ADRINT *WinAPI_EMRCREATEBRUSHINDIRECT__typ;
import SYSTEM_ADRINT *WinAPI_EMRCREATEMONOBRUSH__typ;
import SYSTEM_ADRINT *WinAPI_EMRCREATEDIBPATTERNBRUSHPT__typ;
import SYSTEM_ADRINT *WinAPI_EMRFORMAT__typ;
import SYSTEM_ADRINT *WinAPI_EMRGLSRECORD__typ;
import SYSTEM_ADRINT *WinAPI_EMRGLSBOUNDEDRECORD__typ;
import SYSTEM_ADRINT *WinAPI_EMRPIXELFORMAT__typ;
import SYSTEM_ADRINT *WinAPI_POINTFLOAT__typ;
import SYSTEM_ADRINT *WinAPI_GLYPHMETRICSFLOAT__typ;
import SYSTEM_ADRINT *WinAPI_LAYERPLANEDESCRIPTOR__typ;
import SYSTEM_ADRINT *WinAPI_MENUTEMPLATEA__typ;
import SYSTEM_ADRINT *WinAPI_MENUTEMPLATEW__typ;
import SYSTEM_ADRINT *WinAPI_MENUTEMPLATE__typ;
import SYSTEM_ADRINT *WinAPI_CBT_CREATEWNDA__typ;
import SYSTEM_ADRINT *WinAPI_CBT_CREATEWNDW__typ;
import SYSTEM_ADRINT *WinAPI_CBTACTIVATESTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_EVENTMSG__typ;
import SYSTEM_ADRINT *WinAPI_CWPSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_CWPRETSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_DEBUGHOOKINFO__typ;
import SYSTEM_ADRINT *WinAPI_MOUSEHOOKSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_HARDWAREHOOKSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_USEROBJECTFLAGS__typ;
import SYSTEM_ADRINT *WinAPI_WNDCLASSEXA__typ;
import SYSTEM_ADRINT *WinAPI_WNDCLASSEXW__typ;
import SYSTEM_ADRINT *WinAPI_WNDCLASSA__typ;
import SYSTEM_ADRINT *WinAPI_WNDCLASSW__typ;
import SYSTEM_ADRINT *WinAPI_MSG__typ;
import SYSTEM_ADRINT *WinAPI_MINMAXINFO__typ;
import SYSTEM_ADRINT *WinAPI_COPYDATASTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_MDINEXTMENU__typ;
import SYSTEM_ADRINT *WinAPI_WINDOWPOS__typ;
import SYSTEM_ADRINT *WinAPI_NCCALCSIZE_PARAMS__typ;
import SYSTEM_ADRINT *WinAPI_ACCEL__typ;
import SYSTEM_ADRINT *WinAPI_PAINTSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_CREATESTRUCTA__typ;
import SYSTEM_ADRINT *WinAPI_CREATESTRUCTW__typ;
import SYSTEM_ADRINT *WinAPI_WINDOWPLACEMENT__typ;
import SYSTEM_ADRINT *WinAPI_NMHDR__typ;
import SYSTEM_ADRINT *WinAPI_STYLESTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_MEASUREITEMSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_DRAWITEMSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_DELETEITEMSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_COMPAREITEMSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_BROADCASTSYSMSG__typ;
import SYSTEM_ADRINT *WinAPI_DLGTEMPLATE__typ;
import SYSTEM_ADRINT *WinAPI_DLGITEMTEMPLATE__typ;
import SYSTEM_ADRINT *WinAPI_TPMPARAMS__typ;
import SYSTEM_ADRINT *WinAPI_MENUITEMINFOA__typ;
import SYSTEM_ADRINT *WinAPI_MENUITEMINFOW__typ;
import SYSTEM_ADRINT *WinAPI_DROPSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_DRAWTEXTPARAMS__typ;
import SYSTEM_ADRINT *WinAPI_HELPINFO__typ;
import SYSTEM_ADRINT *WinAPI_MSGBOXPARAMSA__typ;
import SYSTEM_ADRINT *WinAPI_MSGBOXPARAMSW__typ;
import SYSTEM_ADRINT *WinAPI_MENUITEMTEMPLATEHEADER__typ;
import SYSTEM_ADRINT *WinAPI_MENUITEMTEMPLATE__typ;
import SYSTEM_ADRINT *WinAPI_ICONINFO__typ;
import SYSTEM_ADRINT *WinAPI_CURSORSHAPE__typ;
import SYSTEM_ADRINT *WinAPI_SCROLLINFO__typ;
import SYSTEM_ADRINT *WinAPI_MDICREATESTRUCTA__typ;
import SYSTEM_ADRINT *WinAPI_MDICREATESTRUCTW__typ;
import SYSTEM_ADRINT *WinAPI_CLIENTCREATESTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_MULTIKEYHELPA__typ;
import SYSTEM_ADRINT *WinAPI_MULTIKEYHELPW__typ;
import SYSTEM_ADRINT *WinAPI_HELPWININFOA__typ;
import SYSTEM_ADRINT *WinAPI_HELPWININFOW__typ;
import SYSTEM_ADRINT *WinAPI_NONCLIENTMETRICSA__typ;
import SYSTEM_ADRINT *WinAPI_NONCLIENTMETRICSW__typ;
import SYSTEM_ADRINT *WinAPI_MINIMIZEDMETRICS__typ;
import SYSTEM_ADRINT *WinAPI_ICONMETRICSA__typ;
import SYSTEM_ADRINT *WinAPI_ICONMETRICSW__typ;
import SYSTEM_ADRINT *WinAPI_ANIMATIONINFO__typ;
import SYSTEM_ADRINT *WinAPI_SERIALKEYSA__typ;
import SYSTEM_ADRINT *WinAPI_SERIALKEYSW__typ;
import SYSTEM_ADRINT *WinAPI_HIGHCONTRASTA__typ;
import SYSTEM_ADRINT *WinAPI_HIGHCONTRASTW__typ;
import SYSTEM_ADRINT *WinAPI_FILTERKEYS__typ;
import SYSTEM_ADRINT *WinAPI_STICKYKEYS__typ;
import SYSTEM_ADRINT *WinAPI_MOUSEKEYS__typ;
import SYSTEM_ADRINT *WinAPI_ACCESSTIMEOUT__typ;
import SYSTEM_ADRINT *WinAPI_SOUNDSENTRYA__typ;
import SYSTEM_ADRINT *WinAPI_SOUNDSENTRYW__typ;
import SYSTEM_ADRINT *WinAPI_TOGGLEKEYS__typ;
import SYSTEM_ADRINT *WinAPI_CPINFO__typ;
import SYSTEM_ADRINT *WinAPI_NUMBERFMTA__typ;
import SYSTEM_ADRINT *WinAPI_NUMBERFMTW__typ;
import SYSTEM_ADRINT *WinAPI_CURRENCYFMTA__typ;
import SYSTEM_ADRINT *WinAPI_CURRENCYFMTW__typ;
import SYSTEM_ADRINT *WinAPI_COORD__typ;
import SYSTEM_ADRINT *WinAPI_SMALL_RECT__typ;
import SYSTEM_ADRINT *WinAPI__16__typ;
import SYSTEM_ADRINT *WinAPI_KEY_EVENT_RECORD__typ;
import SYSTEM_ADRINT *WinAPI_MOUSE_EVENT_RECORD__typ;
import SYSTEM_ADRINT *WinAPI_WINDOW_BUFFER_SIZE_RECORD__typ;
import SYSTEM_ADRINT *WinAPI_MENU_EVENT_RECORD__typ;
import SYSTEM_ADRINT *WinAPI_FOCUS_EVENT_RECORD__typ;
import SYSTEM_ADRINT *WinAPI__17__typ;
import SYSTEM_ADRINT *WinAPI_INPUT_RECORD__typ;
import SYSTEM_ADRINT *WinAPI__1__typ;
import SYSTEM_ADRINT *WinAPI_CHAR_INFO__typ;
import SYSTEM_ADRINT *WinAPI_CONSOLE_SCREEN_BUFFER_INFO__typ;
import SYSTEM_ADRINT *WinAPI_CONSOLE_CURSOR_INFO__typ;
import SYSTEM_ADRINT *WinAPI_VS_FIXEDFILEINFO__typ;
import SYSTEM_ADRINT *WinAPI_val_context__typ;
import SYSTEM_ADRINT *WinAPI_PVALUEA__typ;
import SYSTEM_ADRINT *WinAPI_PVALUEW__typ;
import SYSTEM_ADRINT *WinAPI_REG_PROVIDER__typ;
import SYSTEM_ADRINT *WinAPI_VALENTA__typ;
import SYSTEM_ADRINT *WinAPI_VALENTW__typ;
import SYSTEM_ADRINT *WinAPI_DDEACK__typ;
import SYSTEM_ADRINT *WinAPI_DDEADVISE__typ;
import SYSTEM_ADRINT *WinAPI_DDEDATA__typ;
import SYSTEM_ADRINT *WinAPI_DDEPOKE__typ;
import SYSTEM_ADRINT *WinAPI_DDELN__typ;
import SYSTEM_ADRINT *WinAPI_DDEUP__typ;
import SYSTEM_ADRINT *WinAPI_HSZPAIR__typ;
import SYSTEM_ADRINT *WinAPI_CONVCONTEXT__typ;
import SYSTEM_ADRINT *WinAPI_CONVINFO__typ;
import SYSTEM_ADRINT *WinAPI_DDEML_MSG_HOOK_DATA__typ;
import SYSTEM_ADRINT *WinAPI_MONMSGSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_MONCBSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_MONHSZSTRUCTA__typ;
import SYSTEM_ADRINT *WinAPI_MONHSZSTRUCTW__typ;
import SYSTEM_ADRINT *WinAPI_MONERRSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_MONLINKSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_MONCONVSTRUCT__typ;
import SYSTEM_ADRINT *WinAPI_DRAGINFOA__typ;
import SYSTEM_ADRINT *WinAPI_DRAGINFOW__typ;
import SYSTEM_ADRINT *WinAPI_APPBARDATA__typ;
import SYSTEM_ADRINT *WinAPI_SHFILEOPSTRUCTA__typ;
import SYSTEM_ADRINT *WinAPI_SHFILEOPSTRUCTW__typ;
import SYSTEM_ADRINT *WinAPI_SHNAMEMAPPINGA__typ;
import SYSTEM_ADRINT *WinAPI_SHNAMEMAPPINGW__typ;
import SYSTEM_ADRINT *WinAPI_SHELLEXECUTEINFOA__typ;
import SYSTEM_ADRINT *WinAPI_SHELLEXECUTEINFOW__typ;
import SYSTEM_ADRINT *WinAPI_NOTIFYICONDATAA__typ;
import SYSTEM_ADRINT *WinAPI_NOTIFYICONDATAW__typ;
import SYSTEM_ADRINT *WinAPI_SHFILEINFOA__typ;
import SYSTEM_ADRINT *WinAPI_SHFILEINFOW__typ;
import SYSTEM_ADRINT *WinAPI__27__typ;
import SYSTEM_ADRINT *WinAPI__28__typ;
import SYSTEM_ADRINT *WinAPI_PROPSHEETPAGEA__typ;
import SYSTEM_ADRINT *WinAPI__32__typ;
import SYSTEM_ADRINT *WinAPI__33__typ;
import SYSTEM_ADRINT *WinAPI_PROPSHEETPAGEW__typ;
import SYSTEM_ADRINT *WinAPI__PSP__typ;
import SYSTEM_ADRINT *WinAPI__25__typ;
import SYSTEM_ADRINT *WinAPI__26__typ;
import SYSTEM_ADRINT *WinAPI__29__typ;
import SYSTEM_ADRINT *WinAPI_PROPSHEETHEADERA__typ;
import SYSTEM_ADRINT *WinAPI__30__typ;
import SYSTEM_ADRINT *WinAPI__31__typ;
import SYSTEM_ADRINT *WinAPI__34__typ;
import SYSTEM_ADRINT *WinAPI_PROPSHEETHEADERW__typ;
import SYSTEM_ADRINT *WinAPI_PSHNOTIFY__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_INFO_1A__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_INFO_1W__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_INFO_2A__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_INFO_2W__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_INFO_3__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_INFO_4A__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_INFO_4W__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_INFO_5A__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_INFO_5W__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_INFO_6__typ;
import SYSTEM_ADRINT *WinAPI_JOB_INFO_1A__typ;
import SYSTEM_ADRINT *WinAPI_JOB_INFO_1W__typ;
import SYSTEM_ADRINT *WinAPI_JOB_INFO_2A__typ;
import SYSTEM_ADRINT *WinAPI_JOB_INFO_2W__typ;
import SYSTEM_ADRINT *WinAPI_ADDJOB_INFO_1A__typ;
import SYSTEM_ADRINT *WinAPI_ADDJOB_INFO_1W__typ;
import SYSTEM_ADRINT *WinAPI_DRIVER_INFO_1A__typ;
import SYSTEM_ADRINT *WinAPI_DRIVER_INFO_1W__typ;
import SYSTEM_ADRINT *WinAPI_DRIVER_INFO_2A__typ;
import SYSTEM_ADRINT *WinAPI_DRIVER_INFO_2W__typ;
import SYSTEM_ADRINT *WinAPI_DRIVER_INFO_3A__typ;
import SYSTEM_ADRINT *WinAPI_DRIVER_INFO_3W__typ;
import SYSTEM_ADRINT *WinAPI_DOC_INFO_1A__typ;
import SYSTEM_ADRINT *WinAPI_DOC_INFO_1W__typ;
import SYSTEM_ADRINT *WinAPI_FORM_INFO_1A__typ;
import SYSTEM_ADRINT *WinAPI_FORM_INFO_1W__typ;
import SYSTEM_ADRINT *WinAPI_DOC_INFO_2A__typ;
import SYSTEM_ADRINT *WinAPI_DOC_INFO_2W__typ;
import SYSTEM_ADRINT *WinAPI_PRINTPROCESSOR_INFO_1A__typ;
import SYSTEM_ADRINT *WinAPI_PRINTPROCESSOR_INFO_1W__typ;
import SYSTEM_ADRINT *WinAPI_PORT_INFO_1A__typ;
import SYSTEM_ADRINT *WinAPI_PORT_INFO_1W__typ;
import SYSTEM_ADRINT *WinAPI_PORT_INFO_2A__typ;
import SYSTEM_ADRINT *WinAPI_PORT_INFO_2W__typ;
import SYSTEM_ADRINT *WinAPI_MONITOR_INFO_1A__typ;
import SYSTEM_ADRINT *WinAPI_MONITOR_INFO_1W__typ;
import SYSTEM_ADRINT *WinAPI_MONITOR_INFO_2A__typ;
import SYSTEM_ADRINT *WinAPI_MONITOR_INFO_2W__typ;
import SYSTEM_ADRINT *WinAPI_DATATYPES_INFO_1A__typ;
import SYSTEM_ADRINT *WinAPI_DATATYPES_INFO_1W__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_DEFAULTSA__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_DEFAULTSW__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_NOTIFY_OPTIONS_TYPE__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_NOTIFY_OPTIONS__typ;
import SYSTEM_ADRINT *WinAPI__21__typ;
import SYSTEM_ADRINT *WinAPI__22__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_NOTIFY_INFO_DATA__typ;
import SYSTEM_ADRINT *WinAPI_PRINTER_NOTIFY_INFO__typ;
import SYSTEM_ADRINT *WinAPI_PROVIDOR_INFO_1A__typ;
import SYSTEM_ADRINT *WinAPI_PROVIDOR_INFO_1W__typ;
import SYSTEM_ADRINT *WinAPI_SERVICE_STATUS__typ;
import SYSTEM_ADRINT *WinAPI_ENUM_SERVICE_STATUSA__typ;
import SYSTEM_ADRINT *WinAPI_ENUM_SERVICE_STATUSW__typ;
import SYSTEM_ADRINT *WinAPI_QUERY_SERVICE_LOCK_STATUSA__typ;
import SYSTEM_ADRINT *WinAPI_QUERY_SERVICE_LOCK_STATUSW__typ;
import SYSTEM_ADRINT *WinAPI_QUERY_SERVICE_CONFIGA__typ;
import SYSTEM_ADRINT *WinAPI_QUERY_SERVICE_CONFIGW__typ;
import SYSTEM_ADRINT *WinAPI_SERVICE_TABLE_ENTRYA__typ;
import SYSTEM_ADRINT *WinAPI_SERVICE_TABLE_ENTRYW__typ;
import SYSTEM_ADRINT *WinAPI_MODEMDEVCAPS__typ;
import SYSTEM_ADRINT *WinAPI_MODEMSETTINGS__typ;

import void *WinAPI__init(void);

#define WinAPI_AbortDoc(p0)	AbortDoc(p0)
__EXTERN INTEGER __CALL_1 AbortDoc(INTEGER p0);
#define WinAPI_AbortPath(p0)	AbortPath(p0)
__EXTERN INTEGER __CALL_1 AbortPath(INTEGER p0);
#define WinAPI_AbortPrinter(hPrinter)	AbortPrinter(hPrinter)
__EXTERN INTEGER __CALL_1 AbortPrinter(INTEGER hPrinter);
#define WinAPI_AbortSystemShutdown(lpMachineName)	AbortSystemShutdownA(lpMachineName)
#define WinAPI_AbortSystemShutdownA(lpMachineName)	AbortSystemShutdownA(lpMachineName)
__EXTERN INTEGER __CALL_1 AbortSystemShutdownA(INTEGER lpMachineName);
#define WinAPI_AbortSystemShutdownW(lpMachineName)	AbortSystemShutdownW(lpMachineName)
__EXTERN INTEGER __CALL_1 AbortSystemShutdownW(INTEGER lpMachineName);
#define WinAPI_AccessCheck(pSecurityDescriptor, ClientToken, DesiredAccess, GenericMapping, GenericMapping__typ, PrivilegeSet, PrivilegeSet__typ, PrivilegeSetLength, GrantedAccess, AccessStatus)	AccessCheck(pSecurityDescriptor, ClientToken, DesiredAccess, GenericMapping, PrivilegeSet, PrivilegeSetLength, GrantedAccess, AccessStatus)
__EXTERN INTEGER __CALL_1 AccessCheck(INTEGER pSecurityDescriptor, INTEGER ClientToken, SET DesiredAccess, WinAPI_GENERIC_MAPPING *GenericMapping, WinAPI_PRIVILEGE_SET *PrivilegeSet, INTEGER *PrivilegeSetLength, INTEGER *GrantedAccess, INTEGER *AccessStatus);
#define WinAPI_AccessCheckAndAuditAlarm(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, GenericMapping__typ, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)	AccessCheckAndAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)
#define WinAPI_AccessCheckAndAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, GenericMapping__typ, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)	AccessCheckAndAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)
__EXTERN INTEGER __CALL_1 AccessCheckAndAuditAlarmA(INTEGER SubsystemName, INTEGER HandleId, INTEGER ObjectTypeName, INTEGER ObjectName, INTEGER SecurityDescriptor, SET DesiredAccess, WinAPI_GENERIC_MAPPING *GenericMapping, INTEGER ObjectCreation, INTEGER *GrantedAccess, INTEGER *AccessStatus, INTEGER *pfGenerateOnClose);
#define WinAPI_AccessCheckAndAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, GenericMapping__typ, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)	AccessCheckAndAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose)
__EXTERN INTEGER __CALL_1 AccessCheckAndAuditAlarmW(INTEGER SubsystemName, INTEGER HandleId, INTEGER ObjectTypeName, INTEGER ObjectName, INTEGER SecurityDescriptor, SET DesiredAccess, WinAPI_GENERIC_MAPPING *GenericMapping, INTEGER ObjectCreation, INTEGER *GrantedAccess, INTEGER *AccessStatus, INTEGER *pfGenerateOnClose);
#define WinAPI_ActivateKeyboardLayout(hkl, Flags)	ActivateKeyboardLayout(hkl, Flags)
__EXTERN INTEGER __CALL_1 ActivateKeyboardLayout(INTEGER hkl, SET Flags);
#define WinAPI_AddAccessAllowedAce(pAcl, pAcl__typ, dwAceRevision, AccessMask, pSid)	AddAccessAllowedAce(pAcl, dwAceRevision, AccessMask, pSid)
__EXTERN INTEGER __CALL_1 AddAccessAllowedAce(WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER AccessMask, INTEGER pSid);
#define WinAPI_AddAccessDeniedAce(pAcl, pAcl__typ, dwAceRevision, AccessMask, pSid)	AddAccessDeniedAce(pAcl, dwAceRevision, AccessMask, pSid)
__EXTERN INTEGER __CALL_1 AddAccessDeniedAce(WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER AccessMask, INTEGER pSid);
#define WinAPI_AddAce(pAcl, pAcl__typ, dwAceRevision, dwStartingAceIndex, pAceList, nAceListLength)	AddAce(pAcl, dwAceRevision, dwStartingAceIndex, pAceList, nAceListLength)
__EXTERN INTEGER __CALL_1 AddAce(WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER dwStartingAceIndex, INTEGER pAceList, INTEGER nAceListLength);
#define WinAPI_AddAtom(lpString)	AddAtomA(lpString)
#define WinAPI_AddAtomA(lpString)	AddAtomA(lpString)
__EXTERN SHORTINT __CALL_1 AddAtomA(INTEGER lpString);
#define WinAPI_AddAtomW(lpString)	AddAtomW(lpString)
__EXTERN SHORTINT __CALL_1 AddAtomW(INTEGER lpString);
#define WinAPI_AddAuditAccessAce(pAcl, pAcl__typ, dwAceRevision, dwAccessMask, pSid, bAuditSuccess, bAuditFailure)	AddAuditAccessAce(pAcl, dwAceRevision, dwAccessMask, pSid, bAuditSuccess, bAuditFailure)
__EXTERN INTEGER __CALL_1 AddAuditAccessAce(WinAPI_ACL *pAcl, INTEGER dwAceRevision, INTEGER dwAccessMask, INTEGER pSid, INTEGER bAuditSuccess, INTEGER bAuditFailure);
#define WinAPI_AddFontResource(p0)	AddFontResourceA(p0)
#define WinAPI_AddFontResourceA(p0)	AddFontResourceA(p0)
__EXTERN INTEGER __CALL_1 AddFontResourceA(INTEGER p0);
#define WinAPI_AddFontResourceW(p0)	AddFontResourceW(p0)
__EXTERN INTEGER __CALL_1 AddFontResourceW(INTEGER p0);
#define WinAPI_AddForm(hPrinter, Level, pForm)	AddFormA(hPrinter, Level, pForm)
#define WinAPI_AddFormA(hPrinter, Level, pForm)	AddFormA(hPrinter, Level, pForm)
__EXTERN INTEGER __CALL_1 AddFormA(INTEGER hPrinter, INTEGER Level, CHAR *pForm);
#define WinAPI_AddFormW(hPrinter, Level, pForm)	AddFormW(hPrinter, Level, pForm)
__EXTERN INTEGER __CALL_1 AddFormW(INTEGER hPrinter, INTEGER Level, CHAR *pForm);
#define WinAPI_AddJob(hPrinter, Level, pData, cbBuf, pcbNeeded)	AddJobA(hPrinter, Level, pData, cbBuf, pcbNeeded)
#define WinAPI_AddJobA(hPrinter, Level, pData, cbBuf, pcbNeeded)	AddJobA(hPrinter, Level, pData, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 AddJobA(INTEGER hPrinter, INTEGER Level, CHAR *pData, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_AddJobW(hPrinter, Level, pData, cbBuf, pcbNeeded)	AddJobW(hPrinter, Level, pData, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 AddJobW(INTEGER hPrinter, INTEGER Level, CHAR *pData, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_AddMonitor(pName, Level, pMonitors)	AddMonitorA(pName, Level, pMonitors)
#define WinAPI_AddMonitorA(pName, Level, pMonitors)	AddMonitorA(pName, Level, pMonitors)
__EXTERN INTEGER __CALL_1 AddMonitorA(INTEGER pName, INTEGER Level, CHAR *pMonitors);
#define WinAPI_AddMonitorW(pName, Level, pMonitors)	AddMonitorW(pName, Level, pMonitors)
__EXTERN INTEGER __CALL_1 AddMonitorW(INTEGER pName, INTEGER Level, CHAR *pMonitors);
#define WinAPI_AddPort(pName, hWnd, pMonitorName)	AddPortA(pName, hWnd, pMonitorName)
#define WinAPI_AddPortA(pName, hWnd, pMonitorName)	AddPortA(pName, hWnd, pMonitorName)
__EXTERN INTEGER __CALL_1 AddPortA(INTEGER pName, INTEGER hWnd, INTEGER pMonitorName);
#define WinAPI_AddPortW(pName, hWnd, pMonitorName)	AddPortW(pName, hWnd, pMonitorName)
__EXTERN INTEGER __CALL_1 AddPortW(INTEGER pName, INTEGER hWnd, INTEGER pMonitorName);
#define WinAPI_AddPrintProcessor(pName, pEnvironment, pPathName, pPrintProcessorName)	AddPrintProcessorA(pName, pEnvironment, pPathName, pPrintProcessorName)
#define WinAPI_AddPrintProcessorA(pName, pEnvironment, pPathName, pPrintProcessorName)	AddPrintProcessorA(pName, pEnvironment, pPathName, pPrintProcessorName)
__EXTERN INTEGER __CALL_1 AddPrintProcessorA(INTEGER pName, INTEGER pEnvironment, INTEGER pPathName, INTEGER pPrintProcessorName);
#define WinAPI_AddPrintProcessorW(pName, pEnvironment, pPathName, pPrintProcessorName)	AddPrintProcessorW(pName, pEnvironment, pPathName, pPrintProcessorName)
__EXTERN INTEGER __CALL_1 AddPrintProcessorW(INTEGER pName, INTEGER pEnvironment, INTEGER pPathName, INTEGER pPrintProcessorName);
#define WinAPI_AddPrintProvidor(pName, level, pProvidorInfo)	AddPrintProvidorA(pName, level, pProvidorInfo)
#define WinAPI_AddPrintProvidorA(pName, level, pProvidorInfo)	AddPrintProvidorA(pName, level, pProvidorInfo)
__EXTERN INTEGER __CALL_1 AddPrintProvidorA(INTEGER pName, INTEGER level, CHAR *pProvidorInfo);
#define WinAPI_AddPrintProvidorW(pName, level, pProvidorInfo)	AddPrintProvidorW(pName, level, pProvidorInfo)
__EXTERN INTEGER __CALL_1 AddPrintProvidorW(INTEGER pName, INTEGER level, CHAR *pProvidorInfo);
#define WinAPI_AddPrinter(pName, Level, pPrinter)	AddPrinterA(pName, Level, pPrinter)
#define WinAPI_AddPrinterA(pName, Level, pPrinter)	AddPrinterA(pName, Level, pPrinter)
__EXTERN INTEGER __CALL_1 AddPrinterA(INTEGER pName, INTEGER Level, CHAR *pPrinter);
#define WinAPI_AddPrinterConnection(pName)	AddPrinterConnectionA(pName)
#define WinAPI_AddPrinterConnectionA(pName)	AddPrinterConnectionA(pName)
__EXTERN INTEGER __CALL_1 AddPrinterConnectionA(INTEGER pName);
#define WinAPI_AddPrinterConnectionW(pName)	AddPrinterConnectionW(pName)
__EXTERN INTEGER __CALL_1 AddPrinterConnectionW(INTEGER pName);
#define WinAPI_AddPrinterDriver(pName, Level, pDriverInfo)	AddPrinterDriverA(pName, Level, pDriverInfo)
#define WinAPI_AddPrinterDriverA(pName, Level, pDriverInfo)	AddPrinterDriverA(pName, Level, pDriverInfo)
__EXTERN INTEGER __CALL_1 AddPrinterDriverA(INTEGER pName, INTEGER Level, CHAR *pDriverInfo);
#define WinAPI_AddPrinterDriverW(pName, Level, pDriverInfo)	AddPrinterDriverW(pName, Level, pDriverInfo)
__EXTERN INTEGER __CALL_1 AddPrinterDriverW(INTEGER pName, INTEGER Level, CHAR *pDriverInfo);
#define WinAPI_AddPrinterW(pName, Level, pPrinter)	AddPrinterW(pName, Level, pPrinter)
__EXTERN INTEGER __CALL_1 AddPrinterW(INTEGER pName, INTEGER Level, CHAR *pPrinter);
#define WinAPI_AdjustTokenGroups(TokenHandle, ResetToDefault, NewState, NewState__typ, BufferLength, PreviousState, PreviousState__typ, ReturnLength)	AdjustTokenGroups(TokenHandle, ResetToDefault, NewState, BufferLength, PreviousState, ReturnLength)
__EXTERN INTEGER __CALL_1 AdjustTokenGroups(INTEGER TokenHandle, INTEGER ResetToDefault, WinAPI_TOKEN_GROUPS *NewState, INTEGER BufferLength, WinAPI_TOKEN_GROUPS *PreviousState, INTEGER *ReturnLength);
#define WinAPI_AdjustTokenPrivileges(TokenHandle, DisableAllPrivileges, NewState, NewState__typ, BufferLength, PreviousState, PreviousState__typ, ReturnLength)	AdjustTokenPrivileges(TokenHandle, DisableAllPrivileges, NewState, BufferLength, PreviousState, ReturnLength)
__EXTERN INTEGER __CALL_1 AdjustTokenPrivileges(INTEGER TokenHandle, INTEGER DisableAllPrivileges, WinAPI_TOKEN_PRIVILEGES *NewState, INTEGER BufferLength, WinAPI_TOKEN_PRIVILEGES *PreviousState, INTEGER *ReturnLength);
#define WinAPI_AdjustWindowRect(lpRect, lpRect__typ, dwStyle, bMenu)	AdjustWindowRect(lpRect, dwStyle, bMenu)
__EXTERN INTEGER __CALL_1 AdjustWindowRect(WinAPI_RECT *lpRect, SET dwStyle, INTEGER bMenu);
#define WinAPI_AdjustWindowRectEx(lpRect, lpRect__typ, dwStyle, bMenu, dwExStyle)	AdjustWindowRectEx(lpRect, dwStyle, bMenu, dwExStyle)
__EXTERN INTEGER __CALL_1 AdjustWindowRectEx(WinAPI_RECT *lpRect, SET dwStyle, INTEGER bMenu, SET dwExStyle);
#define WinAPI_AdvancedDocumentProperties(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeOutput__typ, pDevModeInput, pDevModeInput__typ)	AdvancedDocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)
#define WinAPI_AdvancedDocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeOutput__typ, pDevModeInput, pDevModeInput__typ)	AdvancedDocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)
__EXTERN INTEGER __CALL_1 AdvancedDocumentPropertiesA(INTEGER hWnd, INTEGER hPrinter, INTEGER pDeviceName, WinAPI_DEVMODEA *pDevModeOutput, WinAPI_DEVMODEA *pDevModeInput);
#define WinAPI_AdvancedDocumentPropertiesW(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeOutput__typ, pDevModeInput, pDevModeInput__typ)	AdvancedDocumentPropertiesW(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput)
__EXTERN INTEGER __CALL_1 AdvancedDocumentPropertiesW(INTEGER hWnd, INTEGER hPrinter, INTEGER pDeviceName, WinAPI_DEVMODEW *pDevModeOutput, WinAPI_DEVMODEW *pDevModeInput);
#define WinAPI_AllocConsole()	AllocConsole()
__EXTERN INTEGER __CALL_1 AllocConsole(void);
#define WinAPI_AllocateAndInitializeSid(pIdentifierAuthority, pIdentifierAuthority__typ, nSubAuthorityCount, nSubAuthority0, nSubAuthority1, nSubAuthority2, nSubAuthority3, nSubAuthority4, nSubAuthority5, nSubAuthority6, nSubAuthority7, pSid)	AllocateAndInitializeSid(pIdentifierAuthority, nSubAuthorityCount, nSubAuthority0, nSubAuthority1, nSubAuthority2, nSubAuthority3, nSubAuthority4, nSubAuthority5, nSubAuthority6, nSubAuthority7, pSid)
__EXTERN INTEGER __CALL_1 AllocateAndInitializeSid(WinAPI_SID_IDENTIFIER_AUTHORITY *pIdentifierAuthority, CHAR nSubAuthorityCount, INTEGER nSubAuthority0, INTEGER nSubAuthority1, INTEGER nSubAuthority2, INTEGER nSubAuthority3, INTEGER nSubAuthority4, INTEGER nSubAuthority5, INTEGER nSubAuthority6, INTEGER nSubAuthority7, INTEGER *pSid);
#define WinAPI_AllocateLocallyUniqueId(Luid)	AllocateLocallyUniqueId(Luid)
__EXTERN INTEGER __CALL_1 AllocateLocallyUniqueId(LONGINT *Luid);
#define WinAPI_AngleArc(p0, p1, p2, p3, p4, p5)	AngleArc(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 AngleArc(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, REAL p4, REAL p5);
#define WinAPI_AnimatePalette(p0, p1, p2, p3, p3__typ)	AnimatePalette(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 AnimatePalette(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
#define WinAPI_AnsiLower(lpsz)	CharLowerA(lpsz)
#define WinAPI_AnsiLowerBuff(lpsz, cchLength)	CharLowerBuffA(lpsz, cchLength)
#define WinAPI_AnsiNext(lpsz)	CharNextA(lpsz)
#define WinAPI_AnsiPrev(lpszStart, lpszCurrent)	CharPrevA(lpszStart, lpszCurrent)
#define WinAPI_AnsiToOem(lpszSrc, lpszDst)	CharToOemA(lpszSrc, lpszDst)
#define WinAPI_AnsiToOemBuff(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinAPI_AnsiUpper(lpsz)	CharUpperA(lpsz)
#define WinAPI_AnsiUpperBuff(lpsz, cchLength)	CharUpperBuffA(lpsz, cchLength)
#define WinAPI_AnyPopup()	AnyPopup()
__EXTERN INTEGER __CALL_1 AnyPopup(void);
#define WinAPI_AppendMenu(hMenu, uFlags, uIDNewItem, lpNewItem)	AppendMenuA(hMenu, uFlags, uIDNewItem, lpNewItem)
#define WinAPI_AppendMenuA(hMenu, uFlags, uIDNewItem, lpNewItem)	AppendMenuA(hMenu, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __CALL_1 AppendMenuA(INTEGER hMenu, SET uFlags, INTEGER uIDNewItem, INTEGER lpNewItem);
#define WinAPI_AppendMenuW(hMenu, uFlags, uIDNewItem, lpNewItem)	AppendMenuW(hMenu, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __CALL_1 AppendMenuW(INTEGER hMenu, SET uFlags, INTEGER uIDNewItem, INTEGER lpNewItem);
#define WinAPI_Arc(p0, p1, p2, p3, p4, p5, p6, p7, p8)	Arc(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __CALL_1 Arc(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinAPI_ArcTo(p0, p1, p2, p3, p4, p5, p6, p7, p8)	ArcTo(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __CALL_1 ArcTo(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinAPI_AreAllAccessesGranted(GrantedAccess, DesiredAccess)	AreAllAccessesGranted(GrantedAccess, DesiredAccess)
__EXTERN INTEGER __CALL_1 AreAllAccessesGranted(INTEGER GrantedAccess, SET DesiredAccess);
#define WinAPI_AreAnyAccessesGranted(GrantedAccess, DesiredAccess)	AreAnyAccessesGranted(GrantedAccess, DesiredAccess)
__EXTERN INTEGER __CALL_1 AreAnyAccessesGranted(INTEGER GrantedAccess, SET DesiredAccess);
#define WinAPI_AreFileApisANSI()	AreFileApisANSI()
__EXTERN INTEGER __CALL_1 AreFileApisANSI(void);
#define WinAPI_ArrangeIconicWindows(hWnd)	ArrangeIconicWindows(hWnd)
__EXTERN INTEGER __CALL_1 ArrangeIconicWindows(INTEGER hWnd);
#define WinAPI_AttachThreadInput(idAttach, idAttachTo, fAttach)	AttachThreadInput(idAttach, idAttachTo, fAttach)
__EXTERN INTEGER __CALL_1 AttachThreadInput(INTEGER idAttach, INTEGER idAttachTo, INTEGER fAttach);
#define WinAPI_BackupEventLog(hEventLog, lpBackupFileName)	BackupEventLogA(hEventLog, lpBackupFileName)
#define WinAPI_BackupEventLogA(hEventLog, lpBackupFileName)	BackupEventLogA(hEventLog, lpBackupFileName)
__EXTERN INTEGER __CALL_1 BackupEventLogA(INTEGER hEventLog, INTEGER lpBackupFileName);
#define WinAPI_BackupEventLogW(hEventLog, lpBackupFileName)	BackupEventLogW(hEventLog, lpBackupFileName)
__EXTERN INTEGER __CALL_1 BackupEventLogW(INTEGER hEventLog, INTEGER lpBackupFileName);
#define WinAPI_BackupRead(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, bAbort, bProcessSecurity, lpContext)	BackupRead(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, bAbort, bProcessSecurity, lpContext)
__EXTERN INTEGER __CALL_1 BackupRead(INTEGER hFile, CHAR *lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *lpNumberOfBytesRead, INTEGER bAbort, INTEGER bProcessSecurity, INTEGER lpContext);
#define WinAPI_BackupSeek(hFile, dwLowBytesToSeek, dwHighBytesToSeek, lpdwLowByteSeeked, lpdwHighByteSeeked, lpContext)	BackupSeek(hFile, dwLowBytesToSeek, dwHighBytesToSeek, lpdwLowByteSeeked, lpdwHighByteSeeked, lpContext)
__EXTERN INTEGER __CALL_1 BackupSeek(INTEGER hFile, INTEGER dwLowBytesToSeek, INTEGER dwHighBytesToSeek, INTEGER *lpdwLowByteSeeked, INTEGER *lpdwHighByteSeeked, INTEGER lpContext);
#define WinAPI_BackupWrite(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, bAbort, bProcessSecurity, lpContext)	BackupWrite(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, bAbort, bProcessSecurity, lpContext)
__EXTERN INTEGER __CALL_1 BackupWrite(INTEGER hFile, CHAR *lpBuffer, INTEGER nNumberOfBytesToWrite, INTEGER *lpNumberOfBytesWritten, INTEGER bAbort, INTEGER bProcessSecurity, INTEGER lpContext);
#define WinAPI_Beep(dwFreq, dwDuration)	Beep(dwFreq, dwDuration)
__EXTERN INTEGER __CALL_1 Beep(INTEGER dwFreq, INTEGER dwDuration);
#define WinAPI_BeginDeferWindowPos(nNumWindows)	BeginDeferWindowPos(nNumWindows)
__EXTERN INTEGER __CALL_1 BeginDeferWindowPos(INTEGER nNumWindows);
#define WinAPI_BeginPaint(hWnd, lpPaint, lpPaint__typ)	BeginPaint(hWnd, lpPaint)
__EXTERN INTEGER __CALL_1 BeginPaint(INTEGER hWnd, WinAPI_PAINTSTRUCT *lpPaint);
#define WinAPI_BeginPath(p0)	BeginPath(p0)
__EXTERN INTEGER __CALL_1 BeginPath(INTEGER p0);
#define WinAPI_BeginUpdateResource(pFileName, bDeleteExistingResources)	BeginUpdateResourceA(pFileName, bDeleteExistingResources)
#define WinAPI_BeginUpdateResourceA(pFileName, bDeleteExistingResources)	BeginUpdateResourceA(pFileName, bDeleteExistingResources)
__EXTERN INTEGER __CALL_1 BeginUpdateResourceA(INTEGER pFileName, INTEGER bDeleteExistingResources);
#define WinAPI_BeginUpdateResourceW(pFileName, bDeleteExistingResources)	BeginUpdateResourceW(pFileName, bDeleteExistingResources)
__EXTERN INTEGER __CALL_1 BeginUpdateResourceW(INTEGER pFileName, INTEGER bDeleteExistingResources);
#define WinAPI_BitBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8)	BitBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __CALL_1 BitBlt(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinAPI_BringWindowToTop(hWnd)	BringWindowToTop(hWnd)
__EXTERN INTEGER __CALL_1 BringWindowToTop(INTEGER hWnd);
#define WinAPI_BroadcastSystemMessage(p0, p1, p2, p3, p4)	BroadcastSystemMessageA(p0, p1, p2, p3, p4)
#define WinAPI_BroadcastSystemMessageA(p0, p1, p2, p3, p4)	BroadcastSystemMessageA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 BroadcastSystemMessageA(SET p0, SET *p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_BroadcastSystemMessageW(p0, p1, p2, p3, p4)	BroadcastSystemMessageW(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 BroadcastSystemMessageW(SET p0, SET *p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_BuildCommDCB(lpDef, lpDCB, lpDCB__typ)	BuildCommDCBA(lpDef, lpDCB)
#define WinAPI_BuildCommDCBA(lpDef, lpDCB, lpDCB__typ)	BuildCommDCBA(lpDef, lpDCB)
__EXTERN INTEGER __CALL_1 BuildCommDCBA(INTEGER lpDef, WinAPI_DCB *lpDCB);
#define WinAPI_BuildCommDCBAndTimeouts(lpDef, lpDCB, lpDCB__typ, lpCommTimeouts, lpCommTimeouts__typ)	BuildCommDCBAndTimeoutsA(lpDef, lpDCB, lpCommTimeouts)
#define WinAPI_BuildCommDCBAndTimeoutsA(lpDef, lpDCB, lpDCB__typ, lpCommTimeouts, lpCommTimeouts__typ)	BuildCommDCBAndTimeoutsA(lpDef, lpDCB, lpCommTimeouts)
__EXTERN INTEGER __CALL_1 BuildCommDCBAndTimeoutsA(INTEGER lpDef, WinAPI_DCB *lpDCB, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
#define WinAPI_BuildCommDCBAndTimeoutsW(lpDef, lpDCB, lpDCB__typ, lpCommTimeouts, lpCommTimeouts__typ)	BuildCommDCBAndTimeoutsW(lpDef, lpDCB, lpCommTimeouts)
__EXTERN INTEGER __CALL_1 BuildCommDCBAndTimeoutsW(INTEGER lpDef, WinAPI_DCB *lpDCB, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
#define WinAPI_BuildCommDCBW(lpDef, lpDCB, lpDCB__typ)	BuildCommDCBW(lpDef, lpDCB)
__EXTERN INTEGER __CALL_1 BuildCommDCBW(INTEGER lpDef, WinAPI_DCB *lpDCB);
#define WinAPI_CallMsgFilter(lpMsg, lpMsg__typ, nCode)	CallMsgFilterA(lpMsg, nCode)
#define WinAPI_CallMsgFilterA(lpMsg, lpMsg__typ, nCode)	CallMsgFilterA(lpMsg, nCode)
__EXTERN INTEGER __CALL_1 CallMsgFilterA(WinAPI_MSG *lpMsg, INTEGER nCode);
#define WinAPI_CallMsgFilterW(lpMsg, lpMsg__typ, nCode)	CallMsgFilterW(lpMsg, nCode)
__EXTERN INTEGER __CALL_1 CallMsgFilterW(WinAPI_MSG *lpMsg, INTEGER nCode);
#define WinAPI_CallNamedPipe(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)	CallNamedPipeA(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)
#define WinAPI_CallNamedPipeA(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)	CallNamedPipeA(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)
__EXTERN INTEGER __CALL_1 CallNamedPipeA(INTEGER lpNamedPipeName, INTEGER lpInBuffer, INTEGER nInBufferSize, INTEGER lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, INTEGER nTimeOut);
#define WinAPI_CallNamedPipeW(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)	CallNamedPipeW(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut)
__EXTERN INTEGER __CALL_1 CallNamedPipeW(INTEGER lpNamedPipeName, INTEGER lpInBuffer, INTEGER nInBufferSize, INTEGER lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, INTEGER nTimeOut);
#define WinAPI_CallNextHookEx(hhk, nCode, wParam, lParam)	CallNextHookEx(hhk, nCode, wParam, lParam)
__EXTERN INTEGER __CALL_1 CallNextHookEx(INTEGER hhk, INTEGER nCode, INTEGER wParam, INTEGER lParam);
#define WinAPI_CallWindowProc(lpPrevWndFunc, hWnd, Msg, wParam, lParam)	CallWindowProcA(lpPrevWndFunc, hWnd, Msg, wParam, lParam)
#define WinAPI_CallWindowProcA(lpPrevWndFunc, hWnd, Msg, wParam, lParam)	CallWindowProcA(lpPrevWndFunc, hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 CallWindowProcA(WinAPI_FARPROC lpPrevWndFunc, INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_CallWindowProcW(lpPrevWndFunc, hWnd, Msg, wParam, lParam)	CallWindowProcW(lpPrevWndFunc, hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 CallWindowProcW(WinAPI_FARPROC lpPrevWndFunc, INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_CancelDC(p0)	CancelDC(p0)
__EXTERN INTEGER __CALL_1 CancelDC(INTEGER p0);
#define WinAPI_CancelWaitableTimer(hTimer)	CancelWaitableTimer(hTimer)
__EXTERN INTEGER __CALL_1 CancelWaitableTimer(INTEGER hTimer);
#define WinAPI_CascadeWindows(hwndParent, wHow, lpRect, lpRect__typ, cKids, lpKids)	CascadeWindows(hwndParent, wHow, lpRect, cKids, lpKids)
__EXTERN SHORTINT __CALL_1 CascadeWindows(INTEGER hwndParent, INTEGER wHow, WinAPI_RECT *lpRect, INTEGER cKids, INTEGER *lpKids);
#define WinAPI_ChangeClipboardChain(hWndRemove, hWndNewNext)	ChangeClipboardChain(hWndRemove, hWndNewNext)
__EXTERN INTEGER __CALL_1 ChangeClipboardChain(INTEGER hWndRemove, INTEGER hWndNewNext);
#define WinAPI_ChangeDisplaySettings(lpDevMode, lpDevMode__typ, dwFlags)	ChangeDisplaySettingsA(lpDevMode, dwFlags)
#define WinAPI_ChangeDisplaySettingsA(lpDevMode, lpDevMode__typ, dwFlags)	ChangeDisplaySettingsA(lpDevMode, dwFlags)
__EXTERN INTEGER __CALL_1 ChangeDisplaySettingsA(WinAPI_DEVMODEA *lpDevMode, SET dwFlags);
#define WinAPI_ChangeDisplaySettingsW(lpDevMode, lpDevMode__typ, dwFlags)	ChangeDisplaySettingsW(lpDevMode, dwFlags)
__EXTERN INTEGER __CALL_1 ChangeDisplaySettingsW(WinAPI_DEVMODEW *lpDevMode, SET dwFlags);
#define WinAPI_ChangeMenu(hMenu, cmd, lpszNewItem, cmdInsert, flags)	ChangeMenuA(hMenu, cmd, lpszNewItem, cmdInsert, flags)
#define WinAPI_ChangeMenuA(hMenu, cmd, lpszNewItem, cmdInsert, flags)	ChangeMenuA(hMenu, cmd, lpszNewItem, cmdInsert, flags)
__EXTERN INTEGER __CALL_1 ChangeMenuA(INTEGER hMenu, INTEGER cmd, INTEGER lpszNewItem, INTEGER cmdInsert, SET flags);
#define WinAPI_ChangeMenuW(hMenu, cmd, lpszNewItem, cmdInsert, flags)	ChangeMenuW(hMenu, cmd, lpszNewItem, cmdInsert, flags)
__EXTERN INTEGER __CALL_1 ChangeMenuW(INTEGER hMenu, INTEGER cmd, INTEGER lpszNewItem, INTEGER cmdInsert, SET flags);
#define WinAPI_ChangeServiceConfig(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)	ChangeServiceConfigA(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)
#define WinAPI_ChangeServiceConfigA(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)	ChangeServiceConfigA(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)
__EXTERN INTEGER __CALL_1 ChangeServiceConfigA(INTEGER hService, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, INTEGER lpBinaryPathName, INTEGER lpLoadOrderGroup, INTEGER *lpdwTagId, INTEGER lpDependencies, INTEGER lpServiceStartName, INTEGER lpPassword, INTEGER lpDisplayName);
#define WinAPI_ChangeServiceConfigW(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)	ChangeServiceConfigW(hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName)
__EXTERN INTEGER __CALL_1 ChangeServiceConfigW(INTEGER hService, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, INTEGER lpBinaryPathName, INTEGER lpLoadOrderGroup, INTEGER *lpdwTagId, INTEGER lpDependencies, INTEGER lpServiceStartName, INTEGER lpPassword, INTEGER lpDisplayName);
#define WinAPI_CharLower(lpsz)	CharLowerA(lpsz)
#define WinAPI_CharLowerA(lpsz)	CharLowerA(lpsz)
__EXTERN INTEGER __CALL_1 CharLowerA(INTEGER lpsz);
#define WinAPI_CharLowerBuff(lpsz, cchLength)	CharLowerBuffA(lpsz, cchLength)
#define WinAPI_CharLowerBuffA(lpsz, cchLength)	CharLowerBuffA(lpsz, cchLength)
__EXTERN INTEGER __CALL_1 CharLowerBuffA(INTEGER lpsz, INTEGER cchLength);
#define WinAPI_CharLowerBuffW(lpsz, cchLength)	CharLowerBuffW(lpsz, cchLength)
__EXTERN INTEGER __CALL_1 CharLowerBuffW(INTEGER lpsz, INTEGER cchLength);
#define WinAPI_CharLowerW(lpsz)	CharLowerW(lpsz)
__EXTERN INTEGER __CALL_1 CharLowerW(INTEGER lpsz);
#define WinAPI_CharNext(lpsz)	CharNextA(lpsz)
#define WinAPI_CharNextA(lpsz)	CharNextA(lpsz)
__EXTERN INTEGER __CALL_1 CharNextA(INTEGER lpsz);
#define WinAPI_CharNextExA(CodePage, lpCurrentChar, dwFlags)	CharNextExA(CodePage, lpCurrentChar, dwFlags)
__EXTERN INTEGER __CALL_1 CharNextExA(SHORTINT CodePage, INTEGER lpCurrentChar, SET dwFlags);
#define WinAPI_CharNextW(lpsz)	CharNextW(lpsz)
__EXTERN INTEGER __CALL_1 CharNextW(INTEGER lpsz);
#define WinAPI_CharPrev(lpszStart, lpszCurrent)	CharPrevA(lpszStart, lpszCurrent)
#define WinAPI_CharPrevA(lpszStart, lpszCurrent)	CharPrevA(lpszStart, lpszCurrent)
__EXTERN INTEGER __CALL_1 CharPrevA(INTEGER lpszStart, INTEGER lpszCurrent);
#define WinAPI_CharPrevExA(CodePage, lpStart, lpCurrentChar, dwFlags)	CharPrevExA(CodePage, lpStart, lpCurrentChar, dwFlags)
__EXTERN INTEGER __CALL_1 CharPrevExA(SHORTINT CodePage, INTEGER lpStart, INTEGER lpCurrentChar, SET dwFlags);
#define WinAPI_CharPrevW(lpszStart, lpszCurrent)	CharPrevW(lpszStart, lpszCurrent)
__EXTERN INTEGER __CALL_1 CharPrevW(INTEGER lpszStart, INTEGER lpszCurrent);
#define WinAPI_CharToOem(lpszSrc, lpszDst)	CharToOemA(lpszSrc, lpszDst)
#define WinAPI_CharToOemA(lpszSrc, lpszDst)	CharToOemA(lpszSrc, lpszDst)
__EXTERN INTEGER __CALL_1 CharToOemA(INTEGER lpszSrc, INTEGER lpszDst);
#define WinAPI_CharToOemBuff(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinAPI_CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffA(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __CALL_1 CharToOemBuffA(INTEGER lpszSrc, INTEGER lpszDst, INTEGER cchDstLength);
#define WinAPI_CharToOemBuffW(lpszSrc, lpszDst, cchDstLength)	CharToOemBuffW(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __CALL_1 CharToOemBuffW(INTEGER lpszSrc, INTEGER lpszDst, INTEGER cchDstLength);
#define WinAPI_CharToOemW(lpszSrc, lpszDst)	CharToOemW(lpszSrc, lpszDst)
__EXTERN INTEGER __CALL_1 CharToOemW(INTEGER lpszSrc, INTEGER lpszDst);
#define WinAPI_CharUpper(lpsz)	CharUpperA(lpsz)
#define WinAPI_CharUpperA(lpsz)	CharUpperA(lpsz)
__EXTERN INTEGER __CALL_1 CharUpperA(INTEGER lpsz);
#define WinAPI_CharUpperBuff(lpsz, cchLength)	CharUpperBuffA(lpsz, cchLength)
#define WinAPI_CharUpperBuffA(lpsz, cchLength)	CharUpperBuffA(lpsz, cchLength)
__EXTERN INTEGER __CALL_1 CharUpperBuffA(INTEGER lpsz, INTEGER cchLength);
#define WinAPI_CharUpperBuffW(lpsz, cchLength)	CharUpperBuffW(lpsz, cchLength)
__EXTERN INTEGER __CALL_1 CharUpperBuffW(INTEGER lpsz, INTEGER cchLength);
#define WinAPI_CharUpperW(lpsz)	CharUpperW(lpsz)
__EXTERN INTEGER __CALL_1 CharUpperW(INTEGER lpsz);
#define WinAPI_CheckColorsInGamut(p0, p1, p2, p3)	CheckColorsInGamut(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 CheckColorsInGamut(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_CheckDlgButton(hDlg, nIDButton, uCheck)	CheckDlgButton(hDlg, nIDButton, uCheck)
__EXTERN INTEGER __CALL_1 CheckDlgButton(INTEGER hDlg, INTEGER nIDButton, SET uCheck);
#define WinAPI_CheckMenuItem(hMenu, uIDCheckItem, uCheck)	CheckMenuItem(hMenu, uIDCheckItem, uCheck)
__EXTERN INTEGER __CALL_1 CheckMenuItem(INTEGER hMenu, INTEGER uIDCheckItem, SET uCheck);
#define WinAPI_CheckMenuRadioItem(p0, p1, p2, p3, p4)	CheckMenuRadioItem(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 CheckMenuRadioItem(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_CheckRadioButton(hDlg, nIDFirstButton, nIDLastButton, nIDCheckButton)	CheckRadioButton(hDlg, nIDFirstButton, nIDLastButton, nIDCheckButton)
__EXTERN INTEGER __CALL_1 CheckRadioButton(INTEGER hDlg, INTEGER nIDFirstButton, INTEGER nIDLastButton, INTEGER nIDCheckButton);
#define WinAPI_ChildWindowFromPoint(hWndParent, Point)	ChildWindowFromPoint(hWndParent, Point)
__EXTERN INTEGER __CALL_1 ChildWindowFromPoint(INTEGER hWndParent, WinAPI_POINT Point);
#define WinAPI_ChildWindowFromPointEx(p0, p1, p2)	ChildWindowFromPointEx(p0, p1, p2)
__EXTERN INTEGER __CALL_1 ChildWindowFromPointEx(INTEGER p0, WinAPI_POINT p1, SET p2);
#define WinAPI_ChoosePixelFormat(p0, p1, p1__typ)	ChoosePixelFormat(p0, p1)
__EXTERN INTEGER __CALL_1 ChoosePixelFormat(INTEGER p0, WinAPI_PIXELFORMATDESCRIPTOR *p1);
#define WinAPI_Chord(p0, p1, p2, p3, p4, p5, p6, p7, p8)	Chord(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __CALL_1 Chord(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinAPI_ClearCommBreak(hFile)	ClearCommBreak(hFile)
__EXTERN INTEGER __CALL_1 ClearCommBreak(INTEGER hFile);
#define WinAPI_ClearCommError(hFile, lpErrors, lpStat, lpStat__typ)	ClearCommError(hFile, lpErrors, lpStat)
__EXTERN INTEGER __CALL_1 ClearCommError(INTEGER hFile, SET *lpErrors, WinAPI_COMSTAT *lpStat);
#define WinAPI_ClearEventLog(hEventLog, lpBackupFileName)	ClearEventLogA(hEventLog, lpBackupFileName)
#define WinAPI_ClearEventLogA(hEventLog, lpBackupFileName)	ClearEventLogA(hEventLog, lpBackupFileName)
__EXTERN INTEGER __CALL_1 ClearEventLogA(INTEGER hEventLog, INTEGER lpBackupFileName);
#define WinAPI_ClearEventLogW(hEventLog, lpBackupFileName)	ClearEventLogW(hEventLog, lpBackupFileName)
__EXTERN INTEGER __CALL_1 ClearEventLogW(INTEGER hEventLog, INTEGER lpBackupFileName);
#define WinAPI_ClientToScreen(hWnd, lpPoint, lpPoint__typ)	ClientToScreen(hWnd, lpPoint)
__EXTERN INTEGER __CALL_1 ClientToScreen(INTEGER hWnd, WinAPI_POINT *lpPoint);
#define WinAPI_ClipCursor(lpRect, lpRect__typ)	ClipCursor(lpRect)
__EXTERN INTEGER __CALL_1 ClipCursor(WinAPI_RECT *lpRect);
#define WinAPI_CloseClipboard()	CloseClipboard()
__EXTERN INTEGER __CALL_1 CloseClipboard(void);
#define WinAPI_CloseDesktop(hDesktop)	CloseDesktop(hDesktop)
__EXTERN INTEGER __CALL_1 CloseDesktop(INTEGER hDesktop);
#define WinAPI_CloseEnhMetaFile(p0)	CloseEnhMetaFile(p0)
__EXTERN INTEGER __CALL_1 CloseEnhMetaFile(INTEGER p0);
#define WinAPI_CloseEventLog(hEventLog)	CloseEventLog(hEventLog)
__EXTERN INTEGER __CALL_1 CloseEventLog(INTEGER hEventLog);
#define WinAPI_CloseFigure(p0)	CloseFigure(p0)
__EXTERN INTEGER __CALL_1 CloseFigure(INTEGER p0);
#define WinAPI_CloseHandle(hObject)	CloseHandle(hObject)
__EXTERN INTEGER __CALL_1 CloseHandle(INTEGER hObject);
#define WinAPI_CloseMetaFile(p0)	CloseMetaFile(p0)
__EXTERN INTEGER __CALL_1 CloseMetaFile(INTEGER p0);
#define WinAPI_ClosePrinter(hPrinter)	ClosePrinter(hPrinter)
__EXTERN INTEGER __CALL_1 ClosePrinter(INTEGER hPrinter);
#define WinAPI_CloseServiceHandle(hSCObject)	CloseServiceHandle(hSCObject)
__EXTERN INTEGER __CALL_1 CloseServiceHandle(INTEGER hSCObject);
#define WinAPI_CloseWindow(hWnd)	CloseWindow(hWnd)
__EXTERN INTEGER __CALL_1 CloseWindow(INTEGER hWnd);
#define WinAPI_CloseWindowStation(hWinSta)	CloseWindowStation(hWinSta)
__EXTERN INTEGER __CALL_1 CloseWindowStation(INTEGER hWinSta);
#define WinAPI_CmdLine()	__lpCmdLine
#define WinAPI_CmdShow()	__nCmdShow
#define WinAPI_ColorMatchToTarget(p0, p1, p2)	ColorMatchToTarget(p0, p1, p2)
__EXTERN INTEGER __CALL_1 ColorMatchToTarget(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_CombineRgn(p0, p1, p2, p3)	CombineRgn(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 CombineRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_CombineTransform(p0, p0__typ, p1, p1__typ, p2, p2__typ)	CombineTransform(p0, p1, p2)
__EXTERN INTEGER __CALL_1 CombineTransform(WinAPI_XFORM *p0, WinAPI_XFORM *p1, WinAPI_XFORM *p2);
#define WinAPI_CommConfigDialog(lpszName, hWnd, lpCC, lpCC__typ)	CommConfigDialogA(lpszName, hWnd, lpCC)
#define WinAPI_CommConfigDialogA(lpszName, hWnd, lpCC, lpCC__typ)	CommConfigDialogA(lpszName, hWnd, lpCC)
__EXTERN INTEGER __CALL_1 CommConfigDialogA(INTEGER lpszName, INTEGER hWnd, WinAPI_COMMCONFIG *lpCC);
#define WinAPI_CommConfigDialogW(lpszName, hWnd, lpCC, lpCC__typ)	CommConfigDialogW(lpszName, hWnd, lpCC)
__EXTERN INTEGER __CALL_1 CommConfigDialogW(INTEGER lpszName, INTEGER hWnd, WinAPI_COMMCONFIG *lpCC);
#define WinAPI_CommandLineToArgvW(lpCmdLine, pNumArgs)	CommandLineToArgvW(lpCmdLine, pNumArgs)
__EXTERN INTEGER __CALL_1 CommandLineToArgvW(INTEGER lpCmdLine, INTEGER *pNumArgs);
#define WinAPI_CompareFileTime(lpFileTime1, lpFileTime1__typ, lpFileTime2, lpFileTime2__typ)	CompareFileTime(lpFileTime1, lpFileTime2)
__EXTERN INTEGER __CALL_1 CompareFileTime(WinAPI_FILETIME *lpFileTime1, WinAPI_FILETIME *lpFileTime2);
#define WinAPI_CompareString(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)	CompareStringA(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)
#define WinAPI_CompareStringA(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)	CompareStringA(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)
__EXTERN INTEGER __CALL_1 CompareStringA(INTEGER Locale, SET dwCmpFlags, INTEGER lpString1, INTEGER cchCount1, INTEGER lpString2, INTEGER cchCount2);
#define WinAPI_CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)	CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2)
__EXTERN INTEGER __CALL_1 CompareStringW(INTEGER Locale, SET dwCmpFlags, INTEGER lpString1, INTEGER cchCount1, INTEGER lpString2, INTEGER cchCount2);
#define WinAPI_ConfigurePort(pName, hWnd, pPortName)	ConfigurePortA(pName, hWnd, pPortName)
#define WinAPI_ConfigurePortA(pName, hWnd, pPortName)	ConfigurePortA(pName, hWnd, pPortName)
__EXTERN INTEGER __CALL_1 ConfigurePortA(INTEGER pName, INTEGER hWnd, INTEGER pPortName);
#define WinAPI_ConfigurePortW(pName, hWnd, pPortName)	ConfigurePortW(pName, hWnd, pPortName)
__EXTERN INTEGER __CALL_1 ConfigurePortW(INTEGER pName, INTEGER hWnd, INTEGER pPortName);
#define WinAPI_ConnectNamedPipe(hNamedPipe, lpOverlapped, lpOverlapped__typ)	ConnectNamedPipe(hNamedPipe, lpOverlapped)
__EXTERN INTEGER __CALL_1 ConnectNamedPipe(INTEGER hNamedPipe, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_ConnectToPrinterDlg(hwnd, Flags)	ConnectToPrinterDlg(hwnd, Flags)
__EXTERN INTEGER __CALL_1 ConnectToPrinterDlg(INTEGER hwnd, SET Flags);
#define WinAPI_ContinueDebugEvent(dwProcessId, dwThreadId, dwContinueStatus)	ContinueDebugEvent(dwProcessId, dwThreadId, dwContinueStatus)
__EXTERN INTEGER __CALL_1 ContinueDebugEvent(INTEGER dwProcessId, INTEGER dwThreadId, SET dwContinueStatus);
#define WinAPI_ControlService(hService, dwControl, lpServiceStatus, lpServiceStatus__typ)	ControlService(hService, dwControl, lpServiceStatus)
__EXTERN INTEGER __CALL_1 ControlService(INTEGER hService, INTEGER dwControl, WinAPI_SERVICE_STATUS *lpServiceStatus);
#define WinAPI_ConvertDefaultLocale(Locale)	ConvertDefaultLocale(Locale)
__EXTERN INTEGER __CALL_1 ConvertDefaultLocale(INTEGER Locale);
#define WinAPI_ConvertThreadToFiber(lpParameter)	ConvertThreadToFiber(lpParameter)
__EXTERN INTEGER __CALL_1 ConvertThreadToFiber(INTEGER lpParameter);
#define WinAPI_CopyAcceleratorTable(hAccelSrc, lpAccelDst, lpAccelDst__typ, cAccelEntries)	CopyAcceleratorTableA(hAccelSrc, lpAccelDst, cAccelEntries)
#define WinAPI_CopyAcceleratorTableA(hAccelSrc, lpAccelDst, lpAccelDst__typ, cAccelEntries)	CopyAcceleratorTableA(hAccelSrc, lpAccelDst, cAccelEntries)
__EXTERN INTEGER __CALL_1 CopyAcceleratorTableA(INTEGER hAccelSrc, WinAPI_ACCEL *lpAccelDst, INTEGER cAccelEntries);
#define WinAPI_CopyAcceleratorTableW(hAccelSrc, lpAccelDst, lpAccelDst__typ, cAccelEntries)	CopyAcceleratorTableW(hAccelSrc, lpAccelDst, cAccelEntries)
__EXTERN INTEGER __CALL_1 CopyAcceleratorTableW(INTEGER hAccelSrc, WinAPI_ACCEL *lpAccelDst, INTEGER cAccelEntries);
#define WinAPI_CopyEnhMetaFile(p0, p1)	CopyEnhMetaFileA(p0, p1)
#define WinAPI_CopyEnhMetaFileA(p0, p1)	CopyEnhMetaFileA(p0, p1)
__EXTERN INTEGER __CALL_1 CopyEnhMetaFileA(INTEGER p0, INTEGER p1);
#define WinAPI_CopyEnhMetaFileW(p0, p1)	CopyEnhMetaFileW(p0, p1)
__EXTERN INTEGER __CALL_1 CopyEnhMetaFileW(INTEGER p0, INTEGER p1);
#define WinAPI_CopyFile(lpExistingFileName, lpNewFileName, bFailIfExists)	CopyFileA(lpExistingFileName, lpNewFileName, bFailIfExists)
#define WinAPI_CopyFileA(lpExistingFileName, lpNewFileName, bFailIfExists)	CopyFileA(lpExistingFileName, lpNewFileName, bFailIfExists)
__EXTERN INTEGER __CALL_1 CopyFileA(INTEGER lpExistingFileName, INTEGER lpNewFileName, INTEGER bFailIfExists);
#define WinAPI_CopyFileEx(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)	CopyFileExA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)
#define WinAPI_CopyFileExA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)	CopyFileExA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)
__EXTERN INTEGER __CALL_1 CopyFileExA(INTEGER lpExistingFileName, INTEGER lpNewFileName, WinAPI_PROGRESS_ROUTINE lpProgressRoutine, INTEGER lpData, INTEGER *pbCancel, INTEGER dwCopyFlags);
#define WinAPI_CopyFileExW(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)	CopyFileExW(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags)
__EXTERN INTEGER __CALL_1 CopyFileExW(INTEGER lpExistingFileName, INTEGER lpNewFileName, WinAPI_PROGRESS_ROUTINE lpProgressRoutine, INTEGER lpData, INTEGER *pbCancel, INTEGER dwCopyFlags);
#define WinAPI_CopyFileW(lpExistingFileName, lpNewFileName, bFailIfExists)	CopyFileW(lpExistingFileName, lpNewFileName, bFailIfExists)
__EXTERN INTEGER __CALL_1 CopyFileW(INTEGER lpExistingFileName, INTEGER lpNewFileName, INTEGER bFailIfExists);
#define WinAPI_CopyIcon(hIcon)	CopyIcon(hIcon)
__EXTERN INTEGER __CALL_1 CopyIcon(INTEGER hIcon);
#define WinAPI_CopyImage(p0, p1, p2, p3, p4)	CopyImage(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 CopyImage(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_CopyLZFile(p0, p1)	CopyLZFile(p0, p1)
__EXTERN INTEGER __CALL_1 CopyLZFile(INTEGER p0, INTEGER p1);
#define WinAPI_CopyMetaFile(p0, p1)	CopyMetaFileA(p0, p1)
#define WinAPI_CopyMetaFileA(p0, p1)	CopyMetaFileA(p0, p1)
__EXTERN INTEGER __CALL_1 CopyMetaFileA(INTEGER p0, INTEGER p1);
#define WinAPI_CopyMetaFileW(p0, p1)	CopyMetaFileW(p0, p1)
__EXTERN INTEGER __CALL_1 CopyMetaFileW(INTEGER p0, INTEGER p1);
#define WinAPI_CopyRect(lprcDst, lprcDst__typ, lprcSrc, lprcSrc__typ)	CopyRect(lprcDst, lprcSrc)
__EXTERN INTEGER __CALL_1 CopyRect(WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc);
#define WinAPI_CopySid(nDestinationSidLength, pDestinationSid, pSourceSid)	CopySid(nDestinationSidLength, pDestinationSid, pSourceSid)
__EXTERN INTEGER __CALL_1 CopySid(INTEGER nDestinationSidLength, INTEGER pDestinationSid, INTEGER pSourceSid);
#define WinAPI_CountClipboardFormats()	CountClipboardFormats()
__EXTERN INTEGER __CALL_1 CountClipboardFormats(void);
#define WinAPI_CreateAcceleratorTable(p0, p0__typ, p1)	CreateAcceleratorTableA(p0, p1)
#define WinAPI_CreateAcceleratorTableA(p0, p0__typ, p1)	CreateAcceleratorTableA(p0, p1)
__EXTERN INTEGER __CALL_1 CreateAcceleratorTableA(WinAPI_ACCEL *p0, INTEGER p1);
#define WinAPI_CreateAcceleratorTableW(p0, p0__typ, p1)	CreateAcceleratorTableW(p0, p1)
__EXTERN INTEGER __CALL_1 CreateAcceleratorTableW(WinAPI_ACCEL *p0, INTEGER p1);
#define WinAPI_CreateBitmap(p0, p1, p2, p3, p4)	CreateBitmap(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 CreateBitmap(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_CreateBitmapIndirect(p0, p0__typ)	CreateBitmapIndirect(p0)
__EXTERN INTEGER __CALL_1 CreateBitmapIndirect(WinAPI_BITMAP *p0);
#define WinAPI_CreateBrushIndirect(p0, p0__typ)	CreateBrushIndirect(p0)
__EXTERN INTEGER __CALL_1 CreateBrushIndirect(WinAPI_LOGBRUSH *p0);
#define WinAPI_CreateCaret(hWnd, hBitmap, nWidth, nHeight)	CreateCaret(hWnd, hBitmap, nWidth, nHeight)
__EXTERN INTEGER __CALL_1 CreateCaret(INTEGER hWnd, INTEGER hBitmap, INTEGER nWidth, INTEGER nHeight);
#define WinAPI_CreateColorSpace(p0, p0__typ)	CreateColorSpaceA(p0)
#define WinAPI_CreateColorSpaceA(p0, p0__typ)	CreateColorSpaceA(p0)
__EXTERN INTEGER __CALL_1 CreateColorSpaceA(WinAPI_LOGCOLORSPACEA *p0);
#define WinAPI_CreateColorSpaceW(p0, p0__typ)	CreateColorSpaceW(p0)
__EXTERN INTEGER __CALL_1 CreateColorSpaceW(WinAPI_LOGCOLORSPACEW *p0);
#define WinAPI_CreateCompatibleBitmap(p0, p1, p2)	CreateCompatibleBitmap(p0, p1, p2)
__EXTERN INTEGER __CALL_1 CreateCompatibleBitmap(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_CreateCompatibleDC(p0)	CreateCompatibleDC(p0)
__EXTERN INTEGER __CALL_1 CreateCompatibleDC(INTEGER p0);
#define WinAPI_CreateConsoleScreenBuffer(dwDesiredAccess, dwShareMode, lpSecurityAttributes, lpSecurityAttributes__typ, dwFlags, lpScreenBufferData)	CreateConsoleScreenBuffer(dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwFlags, lpScreenBufferData)
__EXTERN INTEGER __CALL_1 CreateConsoleScreenBuffer(SET dwDesiredAccess, SET dwShareMode, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, SET dwFlags, INTEGER lpScreenBufferData);
#define WinAPI_CreateCursor(hInst, xHotSpot, yHotSpot, nWidth, nHeight, pvANDPlane, pvXORPlane)	CreateCursor(hInst, xHotSpot, yHotSpot, nWidth, nHeight, pvANDPlane, pvXORPlane)
__EXTERN INTEGER __CALL_1 CreateCursor(INTEGER hInst, INTEGER xHotSpot, INTEGER yHotSpot, INTEGER nWidth, INTEGER nHeight, INTEGER pvANDPlane, INTEGER pvXORPlane);
#define WinAPI_CreateDC(p0, p1, p2, p3, p3__typ)	CreateDCA(p0, p1, p2, p3)
#define WinAPI_CreateDCA(p0, p1, p2, p3, p3__typ)	CreateDCA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 CreateDCA(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_DEVMODEA *p3);
#define WinAPI_CreateDCW(p0, p1, p2, p3, p3__typ)	CreateDCW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 CreateDCW(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_DEVMODEW *p3);
#define WinAPI_CreateDIBPatternBrush(p0, p1)	CreateDIBPatternBrush(p0, p1)
__EXTERN INTEGER __CALL_1 CreateDIBPatternBrush(INTEGER p0, INTEGER p1);
#define WinAPI_CreateDIBPatternBrushPt(p0, p1)	CreateDIBPatternBrushPt(p0, p1)
__EXTERN INTEGER __CALL_1 CreateDIBPatternBrushPt(INTEGER p0, INTEGER p1);
#define WinAPI_CreateDIBSection(p0, p1, p1__typ, p2, p3, p4, p5)	CreateDIBSection(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 CreateDIBSection(INTEGER p0, WinAPI_BITMAPINFO *p1, INTEGER p2, INTEGER *p3, INTEGER p4, INTEGER p5);
#define WinAPI_CreateDIBitmap(p0, p1, p1__typ, p2, p3, p4, p4__typ, p5)	CreateDIBitmap(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 CreateDIBitmap(INTEGER p0, WinAPI_BITMAPINFOHEADER *p1, INTEGER p2, INTEGER p3, WinAPI_BITMAPINFO *p4, INTEGER p5);
#define WinAPI_CreateDesktop(lpszDesktop, lpszDevice, pDevmode, pDevmode__typ, dwFlags, dwDesiredAccess, lpsa, lpsa__typ)	CreateDesktopA(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)
#define WinAPI_CreateDesktopA(lpszDesktop, lpszDevice, pDevmode, pDevmode__typ, dwFlags, dwDesiredAccess, lpsa, lpsa__typ)	CreateDesktopA(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)
__EXTERN INTEGER __CALL_1 CreateDesktopA(INTEGER lpszDesktop, INTEGER lpszDevice, WinAPI_DEVMODEA *pDevmode, SET dwFlags, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
#define WinAPI_CreateDesktopW(lpszDesktop, lpszDevice, pDevmode, pDevmode__typ, dwFlags, dwDesiredAccess, lpsa, lpsa__typ)	CreateDesktopW(lpszDesktop, lpszDevice, pDevmode, dwFlags, dwDesiredAccess, lpsa)
__EXTERN INTEGER __CALL_1 CreateDesktopW(INTEGER lpszDesktop, INTEGER lpszDevice, WinAPI_DEVMODEW *pDevmode, SET dwFlags, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
#define WinAPI_CreateDialogIndirectParam(hInstance, lpTemplate, lpTemplate__typ, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogIndirectParamA(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)
#define WinAPI_CreateDialogIndirectParamA(hInstance, lpTemplate, lpTemplate__typ, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogIndirectParamA(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL_1 CreateDialogIndirectParamA(INTEGER hInstance, WinAPI_DLGTEMPLATE *lpTemplate, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinAPI_CreateDialogIndirectParamW(hInstance, lpTemplate, lpTemplate__typ, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogIndirectParamW(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL_1 CreateDialogIndirectParamW(INTEGER hInstance, WinAPI_DLGTEMPLATE *lpTemplate, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinAPI_CreateDialogParam(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
#define WinAPI_CreateDialogParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL_1 CreateDialogParamA(INTEGER hInstance, INTEGER lpTemplateName, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinAPI_CreateDialogParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	CreateDialogParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL_1 CreateDialogParamW(INTEGER hInstance, INTEGER lpTemplateName, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinAPI_CreateDirectory(lpPathName, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateDirectoryA(lpPathName, lpSecurityAttributes)
#define WinAPI_CreateDirectoryA(lpPathName, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateDirectoryA(lpPathName, lpSecurityAttributes)
__EXTERN INTEGER __CALL_1 CreateDirectoryA(INTEGER lpPathName, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateDirectoryEx(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateDirectoryExA(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)
#define WinAPI_CreateDirectoryExA(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateDirectoryExA(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)
__EXTERN INTEGER __CALL_1 CreateDirectoryExA(INTEGER lpTemplateDirectory, INTEGER lpNewDirectory, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateDirectoryExW(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateDirectoryExW(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes)
__EXTERN INTEGER __CALL_1 CreateDirectoryExW(INTEGER lpTemplateDirectory, INTEGER lpNewDirectory, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateDirectoryW(lpPathName, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateDirectoryW(lpPathName, lpSecurityAttributes)
__EXTERN INTEGER __CALL_1 CreateDirectoryW(INTEGER lpPathName, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateDiscardableBitmap(p0, p1, p2)	CreateDiscardableBitmap(p0, p1, p2)
__EXTERN INTEGER __CALL_1 CreateDiscardableBitmap(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_CreateEllipticRgn(p0, p1, p2, p3)	CreateEllipticRgn(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 CreateEllipticRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_CreateEllipticRgnIndirect(p0, p0__typ)	CreateEllipticRgnIndirect(p0)
__EXTERN INTEGER __CALL_1 CreateEllipticRgnIndirect(WinAPI_RECT *p0);
#define WinAPI_CreateEnhMetaFile(p0, p1, p2, p2__typ, p3)	CreateEnhMetaFileA(p0, p1, p2, p3)
#define WinAPI_CreateEnhMetaFileA(p0, p1, p2, p2__typ, p3)	CreateEnhMetaFileA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 CreateEnhMetaFileA(INTEGER p0, INTEGER p1, WinAPI_RECT *p2, INTEGER p3);
#define WinAPI_CreateEnhMetaFileW(p0, p1, p2, p2__typ, p3)	CreateEnhMetaFileW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 CreateEnhMetaFileW(INTEGER p0, INTEGER p1, WinAPI_RECT *p2, INTEGER p3);
#define WinAPI_CreateEvent(lpEventAttributes, lpEventAttributes__typ, bManualReset, bInitialState, lpName)	CreateEventA(lpEventAttributes, bManualReset, bInitialState, lpName)
#define WinAPI_CreateEventA(lpEventAttributes, lpEventAttributes__typ, bManualReset, bInitialState, lpName)	CreateEventA(lpEventAttributes, bManualReset, bInitialState, lpName)
__EXTERN INTEGER __CALL_1 CreateEventA(WinAPI_SECURITY_ATTRIBUTES *lpEventAttributes, INTEGER bManualReset, INTEGER bInitialState, INTEGER lpName);
#define WinAPI_CreateEventW(lpEventAttributes, lpEventAttributes__typ, bManualReset, bInitialState, lpName)	CreateEventW(lpEventAttributes, bManualReset, bInitialState, lpName)
__EXTERN INTEGER __CALL_1 CreateEventW(WinAPI_SECURITY_ATTRIBUTES *lpEventAttributes, INTEGER bManualReset, INTEGER bInitialState, INTEGER lpName);
#define WinAPI_CreateFiber(dwStackSize, lpStartAddress, lpParameter)	CreateFiber(dwStackSize, lpStartAddress, lpParameter)
__EXTERN INTEGER __CALL_1 CreateFiber(INTEGER dwStackSize, WinAPI_FIBER_START_ROUTINE lpStartAddress, INTEGER lpParameter);
#define WinAPI_CreateFile(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, lpSecurityAttributes__typ, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)	CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)
#define WinAPI_CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, lpSecurityAttributes__typ, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)	CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)
__EXTERN INTEGER __CALL_1 CreateFileA(INTEGER lpFileName, SET dwDesiredAccess, SET dwShareMode, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER dwCreationDisposition, SET dwFlagsAndAttributes, INTEGER hTemplateFile);
#define WinAPI_CreateFileMapping(hFile, lpFileMappingAttributes, lpFileMappingAttributes__typ, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)	CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)
#define WinAPI_CreateFileMappingA(hFile, lpFileMappingAttributes, lpFileMappingAttributes__typ, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)	CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)
__EXTERN INTEGER __CALL_1 CreateFileMappingA(INTEGER hFile, WinAPI_SECURITY_ATTRIBUTES *lpFileMappingAttributes, SET flProtect, INTEGER dwMaximumSizeHigh, INTEGER dwMaximumSizeLow, INTEGER lpName);
#define WinAPI_CreateFileMappingW(hFile, lpFileMappingAttributes, lpFileMappingAttributes__typ, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)	CreateFileMappingW(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName)
__EXTERN INTEGER __CALL_1 CreateFileMappingW(INTEGER hFile, WinAPI_SECURITY_ATTRIBUTES *lpFileMappingAttributes, SET flProtect, INTEGER dwMaximumSizeHigh, INTEGER dwMaximumSizeLow, INTEGER lpName);
#define WinAPI_CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, lpSecurityAttributes__typ, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)	CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)
__EXTERN INTEGER __CALL_1 CreateFileW(INTEGER lpFileName, SET dwDesiredAccess, SET dwShareMode, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER dwCreationDisposition, SET dwFlagsAndAttributes, INTEGER hTemplateFile);
#define WinAPI_CreateFont(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)	CreateFontA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)
#define WinAPI_CreateFontA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)	CreateFontA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)
__EXTERN INTEGER __CALL_1 CreateFontA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10, INTEGER p11, INTEGER p12, INTEGER p13);
#define WinAPI_CreateFontIndirect(p0, p0__typ)	CreateFontIndirectA(p0)
#define WinAPI_CreateFontIndirectA(p0, p0__typ)	CreateFontIndirectA(p0)
__EXTERN INTEGER __CALL_1 CreateFontIndirectA(WinAPI_LOGFONTA *p0);
#define WinAPI_CreateFontIndirectW(p0, p0__typ)	CreateFontIndirectW(p0)
__EXTERN INTEGER __CALL_1 CreateFontIndirectW(WinAPI_LOGFONTW *p0);
#define WinAPI_CreateFontW(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)	CreateFontW(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)
__EXTERN INTEGER __CALL_1 CreateFontW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10, INTEGER p11, INTEGER p12, INTEGER p13);
#define WinAPI_CreateHalftonePalette(p0)	CreateHalftonePalette(p0)
__EXTERN INTEGER __CALL_1 CreateHalftonePalette(INTEGER p0);
#define WinAPI_CreateHatchBrush(p0, p1)	CreateHatchBrush(p0, p1)
__EXTERN INTEGER __CALL_1 CreateHatchBrush(INTEGER p0, INTEGER p1);
#define WinAPI_CreateIC(p0, p1, p2, p3, p3__typ)	CreateICA(p0, p1, p2, p3)
#define WinAPI_CreateICA(p0, p1, p2, p3, p3__typ)	CreateICA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 CreateICA(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_DEVMODEA *p3);
#define WinAPI_CreateICW(p0, p1, p2, p3, p3__typ)	CreateICW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 CreateICW(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_DEVMODEW *p3);
#define WinAPI_CreateIcon(hInstance, nWidth, nHeight, cPlanes, cBitsPixel, lpbANDbits, lpbXORbits)	CreateIcon(hInstance, nWidth, nHeight, cPlanes, cBitsPixel, lpbANDbits, lpbXORbits)
__EXTERN INTEGER __CALL_1 CreateIcon(INTEGER hInstance, INTEGER nWidth, INTEGER nHeight, CHAR cPlanes, CHAR cBitsPixel, CHAR *lpbANDbits, CHAR *lpbXORbits);
#define WinAPI_CreateIconFromResource(presbits, dwResSize, fIcon, dwVer)	CreateIconFromResource(presbits, dwResSize, fIcon, dwVer)
__EXTERN INTEGER __CALL_1 CreateIconFromResource(CHAR *presbits, INTEGER dwResSize, INTEGER fIcon, INTEGER dwVer);
#define WinAPI_CreateIconFromResourceEx(presbits, dwResSize, fIcon, dwVer, cxDesired, cyDesired, Flags)	CreateIconFromResourceEx(presbits, dwResSize, fIcon, dwVer, cxDesired, cyDesired, Flags)
__EXTERN INTEGER __CALL_1 CreateIconFromResourceEx(CHAR *presbits, INTEGER dwResSize, INTEGER fIcon, INTEGER dwVer, INTEGER cxDesired, INTEGER cyDesired, SET Flags);
#define WinAPI_CreateIconIndirect(piconinfo, piconinfo__typ)	CreateIconIndirect(piconinfo)
__EXTERN INTEGER __CALL_1 CreateIconIndirect(WinAPI_ICONINFO *piconinfo);
#define WinAPI_CreateIoCompletionPort(FileHandle, ExistingCompletionPort, CompletionKey, NumberOfConcurrentThreads)	CreateIoCompletionPort(FileHandle, ExistingCompletionPort, CompletionKey, NumberOfConcurrentThreads)
__EXTERN INTEGER __CALL_1 CreateIoCompletionPort(INTEGER FileHandle, INTEGER ExistingCompletionPort, INTEGER CompletionKey, INTEGER NumberOfConcurrentThreads);
#define WinAPI_CreateMDIWindow(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)	CreateMDIWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)
#define WinAPI_CreateMDIWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)	CreateMDIWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)
__EXTERN INTEGER __CALL_1 CreateMDIWindowA(INTEGER lpClassName, INTEGER lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent, INTEGER hInstance, INTEGER lParam);
#define WinAPI_CreateMDIWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)	CreateMDIWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam)
__EXTERN INTEGER __CALL_1 CreateMDIWindowW(INTEGER lpClassName, INTEGER lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent, INTEGER hInstance, INTEGER lParam);
#define WinAPI_CreateMailslot(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)
#define WinAPI_CreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)
__EXTERN INTEGER __CALL_1 CreateMailslotA(INTEGER lpName, INTEGER nMaxMessageSize, INTEGER lReadTimeout, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateMailslotW(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateMailslotW(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes)
__EXTERN INTEGER __CALL_1 CreateMailslotW(INTEGER lpName, INTEGER nMaxMessageSize, INTEGER lReadTimeout, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateMenu()	CreateMenu()
__EXTERN INTEGER __CALL_1 CreateMenu(void);
#define WinAPI_CreateMetaFile(p0)	CreateMetaFileA(p0)
#define WinAPI_CreateMetaFileA(p0)	CreateMetaFileA(p0)
__EXTERN INTEGER __CALL_1 CreateMetaFileA(INTEGER p0);
#define WinAPI_CreateMetaFileW(p0)	CreateMetaFileW(p0)
__EXTERN INTEGER __CALL_1 CreateMetaFileW(INTEGER p0);
#define WinAPI_CreateMutex(lpMutexAttributes, lpMutexAttributes__typ, bInitialOwner, lpName)	CreateMutexA(lpMutexAttributes, bInitialOwner, lpName)
#define WinAPI_CreateMutexA(lpMutexAttributes, lpMutexAttributes__typ, bInitialOwner, lpName)	CreateMutexA(lpMutexAttributes, bInitialOwner, lpName)
__EXTERN INTEGER __CALL_1 CreateMutexA(WinAPI_SECURITY_ATTRIBUTES *lpMutexAttributes, INTEGER bInitialOwner, INTEGER lpName);
#define WinAPI_CreateMutexW(lpMutexAttributes, lpMutexAttributes__typ, bInitialOwner, lpName)	CreateMutexW(lpMutexAttributes, bInitialOwner, lpName)
__EXTERN INTEGER __CALL_1 CreateMutexW(WinAPI_SECURITY_ATTRIBUTES *lpMutexAttributes, INTEGER bInitialOwner, INTEGER lpName);
#define WinAPI_CreateNamedPipe(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateNamedPipeA(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)
#define WinAPI_CreateNamedPipeA(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateNamedPipeA(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)
__EXTERN INTEGER __CALL_1 CreateNamedPipeA(INTEGER lpName, INTEGER dwOpenMode, INTEGER dwPipeMode, INTEGER nMaxInstances, INTEGER nOutBufferSize, INTEGER nInBufferSize, INTEGER nDefaultTimeOut, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreateNamedPipeW(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes, lpSecurityAttributes__typ)	CreateNamedPipeW(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes)
__EXTERN INTEGER __CALL_1 CreateNamedPipeW(INTEGER lpName, INTEGER dwOpenMode, INTEGER dwPipeMode, INTEGER nMaxInstances, INTEGER nOutBufferSize, INTEGER nInBufferSize, INTEGER nDefaultTimeOut, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_CreatePalette(p0, p0__typ)	CreatePalette(p0)
__EXTERN INTEGER __CALL_1 CreatePalette(WinAPI_LOGPALETTE *p0);
#define WinAPI_CreatePatternBrush(p0)	CreatePatternBrush(p0)
__EXTERN INTEGER __CALL_1 CreatePatternBrush(INTEGER p0);
#define WinAPI_CreatePen(p0, p1, p2)	CreatePen(p0, p1, p2)
__EXTERN INTEGER __CALL_1 CreatePen(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_CreatePenIndirect(p0, p0__typ)	CreatePenIndirect(p0)
__EXTERN INTEGER __CALL_1 CreatePenIndirect(WinAPI_LOGPEN *p0);
#define WinAPI_CreatePipe(hReadPipe, hWritePipe, lpPipeAttributes, lpPipeAttributes__typ, nSize)	CreatePipe(hReadPipe, hWritePipe, lpPipeAttributes, nSize)
__EXTERN INTEGER __CALL_1 CreatePipe(INTEGER *hReadPipe, INTEGER *hWritePipe, WinAPI_SECURITY_ATTRIBUTES *lpPipeAttributes, INTEGER nSize);
#define WinAPI_CreatePolyPolygonRgn(p0, p0__typ, p1, p2, p3)	CreatePolyPolygonRgn(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 CreatePolyPolygonRgn(WinAPI_POINT *p0, INTEGER *p1, INTEGER p2, INTEGER p3);
#define WinAPI_CreatePolygonRgn(p0, p0__typ, p1, p2)	CreatePolygonRgn(p0, p1, p2)
__EXTERN INTEGER __CALL_1 CreatePolygonRgn(WinAPI_POINT *p0, INTEGER p1, INTEGER p2);
#define WinAPI_CreatePopupMenu()	CreatePopupMenu()
__EXTERN INTEGER __CALL_1 CreatePopupMenu(void);
#define WinAPI_CreatePrivateObjectSecurity(ParentDescriptor, CreatorDescriptor, NewDescriptor, IsDirectoryObject, Token, GenericMapping, GenericMapping__typ)	CreatePrivateObjectSecurity(ParentDescriptor, CreatorDescriptor, NewDescriptor, IsDirectoryObject, Token, GenericMapping)
__EXTERN INTEGER __CALL_1 CreatePrivateObjectSecurity(INTEGER ParentDescriptor, INTEGER CreatorDescriptor, INTEGER *NewDescriptor, INTEGER IsDirectoryObject, INTEGER Token, WinAPI_GENERIC_MAPPING *GenericMapping);
#define WinAPI_CreateProcess(lpApplicationName, lpCommandLine, lpProcessAttributes, lpProcessAttributes__typ, lpThreadAttributes, lpThreadAttributes__typ, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpStartupInfo__typ, lpProcessInformation, lpProcessInformation__typ)	CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
#define WinAPI_CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpProcessAttributes__typ, lpThreadAttributes, lpThreadAttributes__typ, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpStartupInfo__typ, lpProcessInformation, lpProcessInformation__typ)	CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
__EXTERN INTEGER __CALL_1 CreateProcessA(INTEGER lpApplicationName, INTEGER lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, INTEGER lpEnvironment, INTEGER lpCurrentDirectory, WinAPI_STARTUPINFOA *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
#define WinAPI_CreateProcessAsUser(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpProcessAttributes__typ, lpThreadAttributes, lpThreadAttributes__typ, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpStartupInfo__typ, lpProcessInformation, lpProcessInformation__typ)	CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
#define WinAPI_CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpProcessAttributes__typ, lpThreadAttributes, lpThreadAttributes__typ, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpStartupInfo__typ, lpProcessInformation, lpProcessInformation__typ)	CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
__EXTERN INTEGER __CALL_1 CreateProcessAsUserA(INTEGER hToken, INTEGER lpApplicationName, INTEGER lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, INTEGER lpEnvironment, INTEGER lpCurrentDirectory, WinAPI_STARTUPINFOA *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
#define WinAPI_CreateProcessAsUserW(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpProcessAttributes__typ, lpThreadAttributes, lpThreadAttributes__typ, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpStartupInfo__typ, lpProcessInformation, lpProcessInformation__typ)	CreateProcessAsUserW(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
__EXTERN INTEGER __CALL_1 CreateProcessAsUserW(INTEGER hToken, INTEGER lpApplicationName, INTEGER lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, INTEGER lpEnvironment, INTEGER lpCurrentDirectory, WinAPI_STARTUPINFOW *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
#define WinAPI_CreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpProcessAttributes__typ, lpThreadAttributes, lpThreadAttributes__typ, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpStartupInfo__typ, lpProcessInformation, lpProcessInformation__typ)	CreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation)
__EXTERN INTEGER __CALL_1 CreateProcessW(INTEGER lpApplicationName, INTEGER lpCommandLine, WinAPI_SECURITY_ATTRIBUTES *lpProcessAttributes, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER bInheritHandles, SET dwCreationFlags, INTEGER lpEnvironment, INTEGER lpCurrentDirectory, WinAPI_STARTUPINFOW *lpStartupInfo, WinAPI_PROCESS_INFORMATION *lpProcessInformation);
#define WinAPI_CreatePropertySheetPage(p0, p0__typ)	CreatePropertySheetPageA(p0)
#define WinAPI_CreatePropertySheetPageA(p0, p0__typ)	CreatePropertySheetPageA(p0)
__EXTERN WinAPI_Ptr_PSP __CALL_1 CreatePropertySheetPageA(WinAPI_PROPSHEETPAGEA *p0);
#define WinAPI_CreatePropertySheetPageW(p0, p0__typ)	CreatePropertySheetPageW(p0)
__EXTERN WinAPI_Ptr_PSP __CALL_1 CreatePropertySheetPageW(WinAPI_PROPSHEETPAGEW *p0);
#define WinAPI_CreateRectRgn(p0, p1, p2, p3)	CreateRectRgn(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 CreateRectRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_CreateRectRgnIndirect(p0, p0__typ)	CreateRectRgnIndirect(p0)
__EXTERN INTEGER __CALL_1 CreateRectRgnIndirect(WinAPI_RECT *p0);
#define WinAPI_CreateRemoteThread(hProcess, lpThreadAttributes, lpThreadAttributes__typ, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId)	CreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId)
__EXTERN INTEGER __CALL_1 CreateRemoteThread(INTEGER hProcess, WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER dwStackSize, WinAPI_THREAD_START_ROUTINE lpStartAddress, INTEGER lpParameter, SET dwCreationFlags, INTEGER *lpThreadId);
#define WinAPI_CreateRoundRectRgn(p0, p1, p2, p3, p4, p5)	CreateRoundRectRgn(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 CreateRoundRectRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
#define WinAPI_CreateScalableFontResource(p0, p1, p2, p3)	CreateScalableFontResourceA(p0, p1, p2, p3)
#define WinAPI_CreateScalableFontResourceA(p0, p1, p2, p3)	CreateScalableFontResourceA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 CreateScalableFontResourceA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_CreateScalableFontResourceW(p0, p1, p2, p3)	CreateScalableFontResourceW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 CreateScalableFontResourceW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_CreateSemaphore(lpSemaphoreAttributes, lpSemaphoreAttributes__typ, lInitialCount, lMaximumCount, lpName)	CreateSemaphoreA(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)
#define WinAPI_CreateSemaphoreA(lpSemaphoreAttributes, lpSemaphoreAttributes__typ, lInitialCount, lMaximumCount, lpName)	CreateSemaphoreA(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)
__EXTERN INTEGER __CALL_1 CreateSemaphoreA(WinAPI_SECURITY_ATTRIBUTES *lpSemaphoreAttributes, INTEGER lInitialCount, INTEGER lMaximumCount, INTEGER lpName);
#define WinAPI_CreateSemaphoreW(lpSemaphoreAttributes, lpSemaphoreAttributes__typ, lInitialCount, lMaximumCount, lpName)	CreateSemaphoreW(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName)
__EXTERN INTEGER __CALL_1 CreateSemaphoreW(WinAPI_SECURITY_ATTRIBUTES *lpSemaphoreAttributes, INTEGER lInitialCount, INTEGER lMaximumCount, INTEGER lpName);
#define WinAPI_CreateService(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)	CreateServiceA(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)
#define WinAPI_CreateServiceA(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)	CreateServiceA(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)
__EXTERN INTEGER __CALL_1 CreateServiceA(INTEGER hSCManager, INTEGER lpServiceName, INTEGER lpDisplayName, SET dwDesiredAccess, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, INTEGER lpBinaryPathName, INTEGER lpLoadOrderGroup, INTEGER *lpdwTagId, INTEGER lpDependencies, INTEGER lpServiceStartName, INTEGER lpPassword);
#define WinAPI_CreateServiceW(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)	CreateServiceW(hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword)
__EXTERN INTEGER __CALL_1 CreateServiceW(INTEGER hSCManager, INTEGER lpServiceName, INTEGER lpDisplayName, SET dwDesiredAccess, SET dwServiceType, INTEGER dwStartType, INTEGER dwErrorControl, INTEGER lpBinaryPathName, INTEGER lpLoadOrderGroup, INTEGER *lpdwTagId, INTEGER lpDependencies, INTEGER lpServiceStartName, INTEGER lpPassword);
#define WinAPI_CreateSolidBrush(p0)	CreateSolidBrush(p0)
__EXTERN INTEGER __CALL_1 CreateSolidBrush(INTEGER p0);
#define WinAPI_CreateTapePartition(hDevice, dwPartitionMethod, dwCount, dwSize)	CreateTapePartition(hDevice, dwPartitionMethod, dwCount, dwSize)
__EXTERN INTEGER __CALL_1 CreateTapePartition(INTEGER hDevice, INTEGER dwPartitionMethod, INTEGER dwCount, INTEGER dwSize);
#define WinAPI_CreateThread(lpThreadAttributes, lpThreadAttributes__typ, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId)	CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId)
__EXTERN INTEGER __CALL_1 CreateThread(WinAPI_SECURITY_ATTRIBUTES *lpThreadAttributes, INTEGER dwStackSize, WinAPI_THREAD_START_ROUTINE lpStartAddress, INTEGER lpParameter, SET dwCreationFlags, INTEGER *lpThreadId);
#define WinAPI_CreateWaitableTimer(lpTimerAttributes, lpTimerAttributes__typ, bManualReset, lpTimerName)	CreateWaitableTimerA(lpTimerAttributes, bManualReset, lpTimerName)
#define WinAPI_CreateWaitableTimerA(lpTimerAttributes, lpTimerAttributes__typ, bManualReset, lpTimerName)	CreateWaitableTimerA(lpTimerAttributes, bManualReset, lpTimerName)
__EXTERN INTEGER __CALL_1 CreateWaitableTimerA(WinAPI_SECURITY_ATTRIBUTES *lpTimerAttributes, INTEGER bManualReset, INTEGER lpTimerName);
#define WinAPI_CreateWaitableTimerW(lpTimerAttributes, lpTimerAttributes__typ, bManualReset, lpTimerName)	CreateWaitableTimerW(lpTimerAttributes, bManualReset, lpTimerName)
__EXTERN INTEGER __CALL_1 CreateWaitableTimerW(WinAPI_SECURITY_ATTRIBUTES *lpTimerAttributes, INTEGER bManualReset, INTEGER lpTimerName);
#define WinAPI_CreateWindowEx(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)	CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
#define WinAPI_CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)	CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
__EXTERN INTEGER __CALL_1 CreateWindowExA(SET dwExStyle, INTEGER lpClassName, INTEGER lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent, INTEGER hMenu, INTEGER hInstance, INTEGER lpParam);
#define WinAPI_CreateWindowExW(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)	CreateWindowExW(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
__EXTERN INTEGER __CALL_1 CreateWindowExW(SET dwExStyle, INTEGER lpClassName, INTEGER lpWindowName, SET dwStyle, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent, INTEGER hMenu, INTEGER hInstance, INTEGER lpParam);
#define WinAPI_CreateWindowStation(lpwinsta, dwReserved, dwDesiredAccess, lpsa, lpsa__typ)	CreateWindowStationA(lpwinsta, dwReserved, dwDesiredAccess, lpsa)
#define WinAPI_CreateWindowStationA(lpwinsta, dwReserved, dwDesiredAccess, lpsa, lpsa__typ)	CreateWindowStationA(lpwinsta, dwReserved, dwDesiredAccess, lpsa)
__EXTERN INTEGER __CALL_1 CreateWindowStationA(INTEGER lpwinsta, INTEGER dwReserved, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
#define WinAPI_CreateWindowStationW(lpwinsta, dwReserved, dwDesiredAccess, lpsa, lpsa__typ)	CreateWindowStationW(lpwinsta, dwReserved, dwDesiredAccess, lpsa)
__EXTERN INTEGER __CALL_1 CreateWindowStationW(INTEGER lpwinsta, INTEGER dwReserved, SET dwDesiredAccess, WinAPI_SECURITY_ATTRIBUTES *lpsa);
#define WinAPI_DPtoLP(p0, p1, p1__typ, p2)	DPtoLP(p0, p1, p2)
__EXTERN INTEGER __CALL_1 DPtoLP(INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_DdeAbandonTransaction(idInst, hConv, idTransaction)	DdeAbandonTransaction(idInst, hConv, idTransaction)
__EXTERN INTEGER __CALL_1 DdeAbandonTransaction(INTEGER idInst, INTEGER hConv, INTEGER idTransaction);
#define WinAPI_DdeAccessData(hData, pcbDataSize)	DdeAccessData(hData, pcbDataSize)
__EXTERN INTEGER __CALL_1 DdeAccessData(INTEGER hData, INTEGER *pcbDataSize);
#define WinAPI_DdeAddData(hData, pSrc, cb, cbOff)	DdeAddData(hData, pSrc, cb, cbOff)
__EXTERN INTEGER __CALL_1 DdeAddData(INTEGER hData, CHAR *pSrc, INTEGER cb, INTEGER cbOff);
#define WinAPI_DdeClientTransaction(pData, cbData, hConv, hszItem, wFmt, wType, dwTimeout, pdwResult)	DdeClientTransaction(pData, cbData, hConv, hszItem, wFmt, wType, dwTimeout, pdwResult)
__EXTERN INTEGER __CALL_1 DdeClientTransaction(CHAR *pData, INTEGER cbData, INTEGER hConv, INTEGER hszItem, INTEGER wFmt, INTEGER wType, INTEGER dwTimeout, INTEGER *pdwResult);
#define WinAPI_DdeCmpStringHandles(hsz1, hsz2)	DdeCmpStringHandles(hsz1, hsz2)
__EXTERN INTEGER __CALL_1 DdeCmpStringHandles(INTEGER hsz1, INTEGER hsz2);
#define WinAPI_DdeConnect(idInst, hszService, hszTopic, pCC, pCC__typ)	DdeConnect(idInst, hszService, hszTopic, pCC)
__EXTERN INTEGER __CALL_1 DdeConnect(INTEGER idInst, INTEGER hszService, INTEGER hszTopic, WinAPI_CONVCONTEXT *pCC);
#define WinAPI_DdeConnectList(idInst, hszService, hszTopic, hConvList, pCC, pCC__typ)	DdeConnectList(idInst, hszService, hszTopic, hConvList, pCC)
__EXTERN INTEGER __CALL_1 DdeConnectList(INTEGER idInst, INTEGER hszService, INTEGER hszTopic, INTEGER hConvList, WinAPI_CONVCONTEXT *pCC);
#define WinAPI_DdeCreateDataHandle(idInst, pSrc, cb, cbOff, hszItem, wFmt, afCmd)	DdeCreateDataHandle(idInst, pSrc, cb, cbOff, hszItem, wFmt, afCmd)
__EXTERN INTEGER __CALL_1 DdeCreateDataHandle(INTEGER idInst, CHAR *pSrc, INTEGER cb, INTEGER cbOff, INTEGER hszItem, INTEGER wFmt, INTEGER afCmd);
#define WinAPI_DdeCreateStringHandle(idInst, psz, iCodePage)	DdeCreateStringHandleA(idInst, psz, iCodePage)
#define WinAPI_DdeCreateStringHandleA(idInst, psz, iCodePage)	DdeCreateStringHandleA(idInst, psz, iCodePage)
__EXTERN INTEGER __CALL_1 DdeCreateStringHandleA(INTEGER idInst, INTEGER psz, INTEGER iCodePage);
#define WinAPI_DdeCreateStringHandleW(idInst, psz, iCodePage)	DdeCreateStringHandleW(idInst, psz, iCodePage)
__EXTERN INTEGER __CALL_1 DdeCreateStringHandleW(INTEGER idInst, INTEGER psz, INTEGER iCodePage);
#define WinAPI_DdeDisconnect(hConv)	DdeDisconnect(hConv)
__EXTERN INTEGER __CALL_1 DdeDisconnect(INTEGER hConv);
#define WinAPI_DdeDisconnectList(hConvList)	DdeDisconnectList(hConvList)
__EXTERN INTEGER __CALL_1 DdeDisconnectList(INTEGER hConvList);
#define WinAPI_DdeEnableCallback(idInst, hConv, wCmd)	DdeEnableCallback(idInst, hConv, wCmd)
__EXTERN INTEGER __CALL_1 DdeEnableCallback(INTEGER idInst, INTEGER hConv, INTEGER wCmd);
#define WinAPI_DdeFreeDataHandle(hData)	DdeFreeDataHandle(hData)
__EXTERN INTEGER __CALL_1 DdeFreeDataHandle(INTEGER hData);
#define WinAPI_DdeFreeStringHandle(idInst, hsz)	DdeFreeStringHandle(idInst, hsz)
__EXTERN INTEGER __CALL_1 DdeFreeStringHandle(INTEGER idInst, INTEGER hsz);
#define WinAPI_DdeGetData(hData, pDst, cbMax, cbOff)	DdeGetData(hData, pDst, cbMax, cbOff)
__EXTERN INTEGER __CALL_1 DdeGetData(INTEGER hData, CHAR *pDst, INTEGER cbMax, INTEGER cbOff);
#define WinAPI_DdeGetLastError(idInst)	DdeGetLastError(idInst)
__EXTERN INTEGER __CALL_1 DdeGetLastError(INTEGER idInst);
#define WinAPI_DdeImpersonateClient(hConv)	DdeImpersonateClient(hConv)
__EXTERN INTEGER __CALL_1 DdeImpersonateClient(INTEGER hConv);
#define WinAPI_DdeInitialize(pidInst, pfnCallback, afCmd, ulRes)	DdeInitializeA(pidInst, pfnCallback, afCmd, ulRes)
#define WinAPI_DdeInitializeA(pidInst, pfnCallback, afCmd, ulRes)	DdeInitializeA(pidInst, pfnCallback, afCmd, ulRes)
__EXTERN INTEGER __CALL_1 DdeInitializeA(INTEGER *pidInst, WinAPI_FNCALLBACK pfnCallback, INTEGER afCmd, INTEGER ulRes);
#define WinAPI_DdeInitializeW(pidInst, pfnCallback, afCmd, ulRes)	DdeInitializeW(pidInst, pfnCallback, afCmd, ulRes)
__EXTERN INTEGER __CALL_1 DdeInitializeW(INTEGER *pidInst, WinAPI_FNCALLBACK pfnCallback, INTEGER afCmd, INTEGER ulRes);
#define WinAPI_DdeKeepStringHandle(idInst, hsz)	DdeKeepStringHandle(idInst, hsz)
__EXTERN INTEGER __CALL_1 DdeKeepStringHandle(INTEGER idInst, INTEGER hsz);
#define WinAPI_DdeNameService(idInst, hsz1, hsz2, afCmd)	DdeNameService(idInst, hsz1, hsz2, afCmd)
__EXTERN INTEGER __CALL_1 DdeNameService(INTEGER idInst, INTEGER hsz1, INTEGER hsz2, INTEGER afCmd);
#define WinAPI_DdePostAdvise(idInst, hszTopic, hszItem)	DdePostAdvise(idInst, hszTopic, hszItem)
__EXTERN INTEGER __CALL_1 DdePostAdvise(INTEGER idInst, INTEGER hszTopic, INTEGER hszItem);
#define WinAPI_DdeQueryConvInfo(hConv, idTransaction, pConvInfo, pConvInfo__typ)	DdeQueryConvInfo(hConv, idTransaction, pConvInfo)
__EXTERN INTEGER __CALL_1 DdeQueryConvInfo(INTEGER hConv, INTEGER idTransaction, WinAPI_CONVINFO *pConvInfo);
#define WinAPI_DdeQueryNextServer(hConvList, hConvPrev)	DdeQueryNextServer(hConvList, hConvPrev)
__EXTERN INTEGER __CALL_1 DdeQueryNextServer(INTEGER hConvList, INTEGER hConvPrev);
#define WinAPI_DdeQueryString(idInst, hsz, psz, cchMax, iCodePage)	DdeQueryStringA(idInst, hsz, psz, cchMax, iCodePage)
#define WinAPI_DdeQueryStringA(idInst, hsz, psz, cchMax, iCodePage)	DdeQueryStringA(idInst, hsz, psz, cchMax, iCodePage)
__EXTERN INTEGER __CALL_1 DdeQueryStringA(INTEGER idInst, INTEGER hsz, INTEGER psz, INTEGER cchMax, INTEGER iCodePage);
#define WinAPI_DdeQueryStringW(idInst, hsz, psz, cchMax, iCodePage)	DdeQueryStringW(idInst, hsz, psz, cchMax, iCodePage)
__EXTERN INTEGER __CALL_1 DdeQueryStringW(INTEGER idInst, INTEGER hsz, INTEGER psz, INTEGER cchMax, INTEGER iCodePage);
#define WinAPI_DdeReconnect(hConv)	DdeReconnect(hConv)
__EXTERN INTEGER __CALL_1 DdeReconnect(INTEGER hConv);
#define WinAPI_DdeSetQualityOfService(hwndClient, pqosNew, pqosNew__typ, pqosPrev, pqosPrev__typ)	DdeSetQualityOfService(hwndClient, pqosNew, pqosPrev)
__EXTERN INTEGER __CALL_1 DdeSetQualityOfService(INTEGER hwndClient, WinAPI_SECURITY_QUALITY_OF_SERVICE *pqosNew, WinAPI_SECURITY_QUALITY_OF_SERVICE *pqosPrev);
#define WinAPI_DdeSetUserHandle(hConv, id, hUser)	DdeSetUserHandle(hConv, id, hUser)
__EXTERN INTEGER __CALL_1 DdeSetUserHandle(INTEGER hConv, INTEGER id, INTEGER hUser);
#define WinAPI_DdeUnaccessData(hData)	DdeUnaccessData(hData)
__EXTERN INTEGER __CALL_1 DdeUnaccessData(INTEGER hData);
#define WinAPI_DdeUninitialize(idInst)	DdeUninitialize(idInst)
__EXTERN INTEGER __CALL_1 DdeUninitialize(INTEGER idInst);
#define WinAPI_DebugActiveProcess(dwProcessId)	DebugActiveProcess(dwProcessId)
__EXTERN INTEGER __CALL_1 DebugActiveProcess(INTEGER dwProcessId);
#define WinAPI_DebugBreak()	DebugBreak()
__EXTERN void __CALL_1 DebugBreak(void);
#define WinAPI_DefDlgProc(hDlg, Msg, wParam, lParam)	DefDlgProcA(hDlg, Msg, wParam, lParam)
#define WinAPI_DefDlgProcA(hDlg, Msg, wParam, lParam)	DefDlgProcA(hDlg, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 DefDlgProcA(INTEGER hDlg, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_DefDlgProcW(hDlg, Msg, wParam, lParam)	DefDlgProcW(hDlg, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 DefDlgProcW(INTEGER hDlg, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_DefFrameProc(hWnd, hWndMDIClient, uMsg, wParam, lParam)	DefFrameProcA(hWnd, hWndMDIClient, uMsg, wParam, lParam)
#define WinAPI_DefFrameProcA(hWnd, hWndMDIClient, uMsg, wParam, lParam)	DefFrameProcA(hWnd, hWndMDIClient, uMsg, wParam, lParam)
__EXTERN INTEGER __CALL_1 DefFrameProcA(INTEGER hWnd, INTEGER hWndMDIClient, INTEGER uMsg, INTEGER wParam, INTEGER lParam);
#define WinAPI_DefFrameProcW(hWnd, hWndMDIClient, uMsg, wParam, lParam)	DefFrameProcW(hWnd, hWndMDIClient, uMsg, wParam, lParam)
__EXTERN INTEGER __CALL_1 DefFrameProcW(INTEGER hWnd, INTEGER hWndMDIClient, INTEGER uMsg, INTEGER wParam, INTEGER lParam);
#define WinAPI_DefMDIChildProc(hWnd, uMsg, wParam, lParam)	DefMDIChildProcA(hWnd, uMsg, wParam, lParam)
#define WinAPI_DefMDIChildProcA(hWnd, uMsg, wParam, lParam)	DefMDIChildProcA(hWnd, uMsg, wParam, lParam)
__EXTERN INTEGER __CALL_1 DefMDIChildProcA(INTEGER hWnd, INTEGER uMsg, INTEGER wParam, INTEGER lParam);
#define WinAPI_DefMDIChildProcW(hWnd, uMsg, wParam, lParam)	DefMDIChildProcW(hWnd, uMsg, wParam, lParam)
__EXTERN INTEGER __CALL_1 DefMDIChildProcW(INTEGER hWnd, INTEGER uMsg, INTEGER wParam, INTEGER lParam);
#define WinAPI_DefWindowProc(hWnd, Msg, wParam, lParam)	DefWindowProcA(hWnd, Msg, wParam, lParam)
#define WinAPI_DefWindowProcA(hWnd, Msg, wParam, lParam)	DefWindowProcA(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 DefWindowProcA(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_DefWindowProcW(hWnd, Msg, wParam, lParam)	DefWindowProcW(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 DefWindowProcW(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_DeferWindowPos(hWinPosInfo, hWnd, hWndInsertAfter, x, y, cx, cy, uFlags)	DeferWindowPos(hWinPosInfo, hWnd, hWndInsertAfter, x, y, cx, cy, uFlags)
__EXTERN INTEGER __CALL_1 DeferWindowPos(INTEGER hWinPosInfo, INTEGER hWnd, INTEGER hWndInsertAfter, INTEGER x, INTEGER y, INTEGER cx, INTEGER cy, SET uFlags);
#define WinAPI_DefineDosDevice(dwFlags, lpDeviceName, lpTargetPath)	DefineDosDeviceA(dwFlags, lpDeviceName, lpTargetPath)
#define WinAPI_DefineDosDeviceA(dwFlags, lpDeviceName, lpTargetPath)	DefineDosDeviceA(dwFlags, lpDeviceName, lpTargetPath)
__EXTERN INTEGER __CALL_1 DefineDosDeviceA(SET dwFlags, INTEGER lpDeviceName, INTEGER lpTargetPath);
#define WinAPI_DefineDosDeviceW(dwFlags, lpDeviceName, lpTargetPath)	DefineDosDeviceW(dwFlags, lpDeviceName, lpTargetPath)
__EXTERN INTEGER __CALL_1 DefineDosDeviceW(SET dwFlags, INTEGER lpDeviceName, INTEGER lpTargetPath);
#define WinAPI_DeleteAce(pAcl, pAcl__typ, dwAceIndex)	DeleteAce(pAcl, dwAceIndex)
__EXTERN INTEGER __CALL_1 DeleteAce(WinAPI_ACL *pAcl, INTEGER dwAceIndex);
#define WinAPI_DeleteAtom(nAtom)	DeleteAtom(nAtom)
__EXTERN SHORTINT __CALL_1 DeleteAtom(SHORTINT nAtom);
#define WinAPI_DeleteColorSpace(p0)	DeleteColorSpace(p0)
__EXTERN INTEGER __CALL_1 DeleteColorSpace(INTEGER p0);
#define WinAPI_DeleteCriticalSection(lpCriticalSection, lpCriticalSection__typ)	DeleteCriticalSection(lpCriticalSection)
__EXTERN void __CALL_1 DeleteCriticalSection(WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinAPI_DeleteDC(p0)	DeleteDC(p0)
__EXTERN INTEGER __CALL_1 DeleteDC(INTEGER p0);
#define WinAPI_DeleteEnhMetaFile(p0)	DeleteEnhMetaFile(p0)
__EXTERN INTEGER __CALL_1 DeleteEnhMetaFile(INTEGER p0);
#define WinAPI_DeleteFiber(lpFiber)	DeleteFiber(lpFiber)
__EXTERN void __CALL_1 DeleteFiber(INTEGER lpFiber);
#define WinAPI_DeleteFile(lpFileName)	DeleteFileA(lpFileName)
#define WinAPI_DeleteFileA(lpFileName)	DeleteFileA(lpFileName)
__EXTERN INTEGER __CALL_1 DeleteFileA(INTEGER lpFileName);
#define WinAPI_DeleteFileW(lpFileName)	DeleteFileW(lpFileName)
__EXTERN INTEGER __CALL_1 DeleteFileW(INTEGER lpFileName);
#define WinAPI_DeleteForm(hPrinter, pFormName)	DeleteFormA(hPrinter, pFormName)
#define WinAPI_DeleteFormA(hPrinter, pFormName)	DeleteFormA(hPrinter, pFormName)
__EXTERN INTEGER __CALL_1 DeleteFormA(INTEGER hPrinter, INTEGER pFormName);
#define WinAPI_DeleteFormW(hPrinter, pFormName)	DeleteFormW(hPrinter, pFormName)
__EXTERN INTEGER __CALL_1 DeleteFormW(INTEGER hPrinter, INTEGER pFormName);
#define WinAPI_DeleteMenu(hMenu, uPosition, uFlags)	DeleteMenu(hMenu, uPosition, uFlags)
__EXTERN INTEGER __CALL_1 DeleteMenu(INTEGER hMenu, INTEGER uPosition, SET uFlags);
#define WinAPI_DeleteMetaFile(p0)	DeleteMetaFile(p0)
__EXTERN INTEGER __CALL_1 DeleteMetaFile(INTEGER p0);
#define WinAPI_DeleteMonitor(pName, pEnvironment, pMonitorName)	DeleteMonitorA(pName, pEnvironment, pMonitorName)
#define WinAPI_DeleteMonitorA(pName, pEnvironment, pMonitorName)	DeleteMonitorA(pName, pEnvironment, pMonitorName)
__EXTERN INTEGER __CALL_1 DeleteMonitorA(INTEGER pName, INTEGER pEnvironment, INTEGER pMonitorName);
#define WinAPI_DeleteMonitorW(pName, pEnvironment, pMonitorName)	DeleteMonitorW(pName, pEnvironment, pMonitorName)
__EXTERN INTEGER __CALL_1 DeleteMonitorW(INTEGER pName, INTEGER pEnvironment, INTEGER pMonitorName);
#define WinAPI_DeleteObject(p0)	DeleteObject(p0)
__EXTERN INTEGER __CALL_1 DeleteObject(INTEGER p0);
#define WinAPI_DeletePort(pName, hWnd, pPortName)	DeletePortA(pName, hWnd, pPortName)
#define WinAPI_DeletePortA(pName, hWnd, pPortName)	DeletePortA(pName, hWnd, pPortName)
__EXTERN INTEGER __CALL_1 DeletePortA(INTEGER pName, INTEGER hWnd, INTEGER pPortName);
#define WinAPI_DeletePortW(pName, hWnd, pPortName)	DeletePortW(pName, hWnd, pPortName)
__EXTERN INTEGER __CALL_1 DeletePortW(INTEGER pName, INTEGER hWnd, INTEGER pPortName);
#define WinAPI_DeletePrintProcessor(pName, pEnvironment, pPrintProcessorName)	DeletePrintProcessorA(pName, pEnvironment, pPrintProcessorName)
#define WinAPI_DeletePrintProcessorA(pName, pEnvironment, pPrintProcessorName)	DeletePrintProcessorA(pName, pEnvironment, pPrintProcessorName)
__EXTERN INTEGER __CALL_1 DeletePrintProcessorA(INTEGER pName, INTEGER pEnvironment, INTEGER pPrintProcessorName);
#define WinAPI_DeletePrintProcessorW(pName, pEnvironment, pPrintProcessorName)	DeletePrintProcessorW(pName, pEnvironment, pPrintProcessorName)
__EXTERN INTEGER __CALL_1 DeletePrintProcessorW(INTEGER pName, INTEGER pEnvironment, INTEGER pPrintProcessorName);
#define WinAPI_DeletePrintProvidor(pName, pEnvironment, pPrintProvidorName)	DeletePrintProvidorA(pName, pEnvironment, pPrintProvidorName)
#define WinAPI_DeletePrintProvidorA(pName, pEnvironment, pPrintProvidorName)	DeletePrintProvidorA(pName, pEnvironment, pPrintProvidorName)
__EXTERN INTEGER __CALL_1 DeletePrintProvidorA(INTEGER pName, INTEGER pEnvironment, INTEGER pPrintProvidorName);
#define WinAPI_DeletePrintProvidorW(pName, pEnvironment, pPrintProvidorName)	DeletePrintProvidorW(pName, pEnvironment, pPrintProvidorName)
__EXTERN INTEGER __CALL_1 DeletePrintProvidorW(INTEGER pName, INTEGER pEnvironment, INTEGER pPrintProvidorName);
#define WinAPI_DeletePrinter(hPrinter)	DeletePrinter(hPrinter)
__EXTERN INTEGER __CALL_1 DeletePrinter(INTEGER hPrinter);
#define WinAPI_DeletePrinterConnection(pName)	DeletePrinterConnectionA(pName)
#define WinAPI_DeletePrinterConnectionA(pName)	DeletePrinterConnectionA(pName)
__EXTERN INTEGER __CALL_1 DeletePrinterConnectionA(INTEGER pName);
#define WinAPI_DeletePrinterConnectionW(pName)	DeletePrinterConnectionW(pName)
__EXTERN INTEGER __CALL_1 DeletePrinterConnectionW(INTEGER pName);
#define WinAPI_DeletePrinterDriver(pName, pEnvironment, pDriverName)	DeletePrinterDriverA(pName, pEnvironment, pDriverName)
#define WinAPI_DeletePrinterDriverA(pName, pEnvironment, pDriverName)	DeletePrinterDriverA(pName, pEnvironment, pDriverName)
__EXTERN INTEGER __CALL_1 DeletePrinterDriverA(INTEGER pName, INTEGER pEnvironment, INTEGER pDriverName);
#define WinAPI_DeletePrinterDriverW(pName, pEnvironment, pDriverName)	DeletePrinterDriverW(pName, pEnvironment, pDriverName)
__EXTERN INTEGER __CALL_1 DeletePrinterDriverW(INTEGER pName, INTEGER pEnvironment, INTEGER pDriverName);
#define WinAPI_DeleteService(hService)	DeleteService(hService)
__EXTERN INTEGER __CALL_1 DeleteService(INTEGER hService);
#define WinAPI_DeregisterEventSource(hEventLog)	DeregisterEventSource(hEventLog)
__EXTERN INTEGER __CALL_1 DeregisterEventSource(INTEGER hEventLog);
#define WinAPI_DescribePixelFormat(p0, p1, p2, p3, p3__typ)	DescribePixelFormat(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 DescribePixelFormat(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_PIXELFORMATDESCRIPTOR *p3);
#define WinAPI_DestroyAcceleratorTable(hAccel)	DestroyAcceleratorTable(hAccel)
__EXTERN INTEGER __CALL_1 DestroyAcceleratorTable(INTEGER hAccel);
#define WinAPI_DestroyCaret()	DestroyCaret()
__EXTERN INTEGER __CALL_1 DestroyCaret(void);
#define WinAPI_DestroyCursor(hCursor)	DestroyCursor(hCursor)
__EXTERN INTEGER __CALL_1 DestroyCursor(INTEGER hCursor);
#define WinAPI_DestroyIcon(hIcon)	DestroyIcon(hIcon)
__EXTERN INTEGER __CALL_1 DestroyIcon(INTEGER hIcon);
#define WinAPI_DestroyMenu(hMenu)	DestroyMenu(hMenu)
__EXTERN INTEGER __CALL_1 DestroyMenu(INTEGER hMenu);
#define WinAPI_DestroyPrivateObjectSecurity(ObjectDescriptor)	DestroyPrivateObjectSecurity(ObjectDescriptor)
__EXTERN INTEGER __CALL_1 DestroyPrivateObjectSecurity(INTEGER *ObjectDescriptor);
#define WinAPI_DestroyPropertySheetPage(p0)	DestroyPropertySheetPage(p0)
__EXTERN INTEGER __CALL_1 DestroyPropertySheetPage(WinAPI_Ptr_PSP p0);
#define WinAPI_DestroyWindow(hWnd)	DestroyWindow(hWnd)
__EXTERN INTEGER __CALL_1 DestroyWindow(INTEGER hWnd);
#define WinAPI_DeviceCapabilities(p0, p1, p2, p3, p4, p4__typ)	DeviceCapabilitiesA(p0, p1, p2, p3, p4)
#define WinAPI_DeviceCapabilitiesA(p0, p1, p2, p3, p4, p4__typ)	DeviceCapabilitiesA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 DeviceCapabilitiesA(INTEGER p0, INTEGER p1, SHORTINT p2, INTEGER p3, WinAPI_DEVMODEA *p4);
#define WinAPI_DeviceCapabilitiesW(p0, p1, p2, p3, p4, p4__typ)	DeviceCapabilitiesW(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 DeviceCapabilitiesW(INTEGER p0, INTEGER p1, SHORTINT p2, INTEGER p3, WinAPI_DEVMODEW *p4);
#define WinAPI_DeviceIoControl(hDevice, dwIoControlCode, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesReturned, lpOverlapped, lpOverlapped__typ)	DeviceIoControl(hDevice, dwIoControlCode, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesReturned, lpOverlapped)
__EXTERN INTEGER __CALL_1 DeviceIoControl(INTEGER hDevice, INTEGER dwIoControlCode, INTEGER lpInBuffer, INTEGER nInBufferSize, INTEGER lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesReturned, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_DialogBoxIndirectParam(hInstance, hDialogTemplate, hDialogTemplate__typ, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxIndirectParamA(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)
#define WinAPI_DialogBoxIndirectParamA(hInstance, hDialogTemplate, hDialogTemplate__typ, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxIndirectParamA(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL_1 DialogBoxIndirectParamA(INTEGER hInstance, WinAPI_DLGTEMPLATE *hDialogTemplate, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinAPI_DialogBoxIndirectParamW(hInstance, hDialogTemplate, hDialogTemplate__typ, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxIndirectParamW(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL_1 DialogBoxIndirectParamW(INTEGER hInstance, WinAPI_DLGTEMPLATE *hDialogTemplate, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinAPI_DialogBoxParam(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
#define WinAPI_DialogBoxParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL_1 DialogBoxParamA(INTEGER hInstance, INTEGER lpTemplateName, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinAPI_DialogBoxParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)	DialogBoxParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam)
__EXTERN INTEGER __CALL_1 DialogBoxParamW(INTEGER hInstance, INTEGER lpTemplateName, INTEGER hWndParent, WinAPI_DLGPROC lpDialogFunc, INTEGER dwInitParam);
#define WinAPI_DisableThreadLibraryCalls(hLibModule)	DisableThreadLibraryCalls(hLibModule)
__EXTERN INTEGER __CALL_1 DisableThreadLibraryCalls(INTEGER hLibModule);
#define WinAPI_DisconnectNamedPipe(hNamedPipe)	DisconnectNamedPipe(hNamedPipe)
__EXTERN INTEGER __CALL_1 DisconnectNamedPipe(INTEGER hNamedPipe);
#define WinAPI_DispatchMessage(lpMsg, lpMsg__typ)	DispatchMessageA(lpMsg)
#define WinAPI_DispatchMessageA(lpMsg, lpMsg__typ)	DispatchMessageA(lpMsg)
__EXTERN INTEGER __CALL_1 DispatchMessageA(WinAPI_MSG *lpMsg);
#define WinAPI_DispatchMessageW(lpMsg, lpMsg__typ)	DispatchMessageW(lpMsg)
__EXTERN INTEGER __CALL_1 DispatchMessageW(WinAPI_MSG *lpMsg);
#define WinAPI_DlgDirList(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)	DlgDirListA(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)
#define WinAPI_DlgDirListA(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)	DlgDirListA(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)
__EXTERN INTEGER __CALL_1 DlgDirListA(INTEGER hDlg, INTEGER lpPathSpec, INTEGER nIDListBox, INTEGER nIDStaticPath, SET uFileType);
#define WinAPI_DlgDirListComboBox(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)	DlgDirListComboBoxA(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)
#define WinAPI_DlgDirListComboBoxA(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)	DlgDirListComboBoxA(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)
__EXTERN INTEGER __CALL_1 DlgDirListComboBoxA(INTEGER hDlg, INTEGER lpPathSpec, INTEGER nIDComboBox, INTEGER nIDStaticPath, INTEGER uFiletype);
#define WinAPI_DlgDirListComboBoxW(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)	DlgDirListComboBoxW(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype)
__EXTERN INTEGER __CALL_1 DlgDirListComboBoxW(INTEGER hDlg, INTEGER lpPathSpec, INTEGER nIDComboBox, INTEGER nIDStaticPath, INTEGER uFiletype);
#define WinAPI_DlgDirListW(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)	DlgDirListW(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType)
__EXTERN INTEGER __CALL_1 DlgDirListW(INTEGER hDlg, INTEGER lpPathSpec, INTEGER nIDListBox, INTEGER nIDStaticPath, SET uFileType);
#define WinAPI_DlgDirSelectComboBoxEx(hDlg, lpString, nCount, nIDComboBox)	DlgDirSelectComboBoxExA(hDlg, lpString, nCount, nIDComboBox)
#define WinAPI_DlgDirSelectComboBoxExA(hDlg, lpString, nCount, nIDComboBox)	DlgDirSelectComboBoxExA(hDlg, lpString, nCount, nIDComboBox)
__EXTERN INTEGER __CALL_1 DlgDirSelectComboBoxExA(INTEGER hDlg, INTEGER lpString, INTEGER nCount, INTEGER nIDComboBox);
#define WinAPI_DlgDirSelectComboBoxExW(hDlg, lpString, nCount, nIDComboBox)	DlgDirSelectComboBoxExW(hDlg, lpString, nCount, nIDComboBox)
__EXTERN INTEGER __CALL_1 DlgDirSelectComboBoxExW(INTEGER hDlg, INTEGER lpString, INTEGER nCount, INTEGER nIDComboBox);
#define WinAPI_DlgDirSelectEx(hDlg, lpString, nCount, nIDListBox)	DlgDirSelectExA(hDlg, lpString, nCount, nIDListBox)
#define WinAPI_DlgDirSelectExA(hDlg, lpString, nCount, nIDListBox)	DlgDirSelectExA(hDlg, lpString, nCount, nIDListBox)
__EXTERN INTEGER __CALL_1 DlgDirSelectExA(INTEGER hDlg, INTEGER lpString, INTEGER nCount, INTEGER nIDListBox);
#define WinAPI_DlgDirSelectExW(hDlg, lpString, nCount, nIDListBox)	DlgDirSelectExW(hDlg, lpString, nCount, nIDListBox)
__EXTERN INTEGER __CALL_1 DlgDirSelectExW(INTEGER hDlg, INTEGER lpString, INTEGER nCount, INTEGER nIDListBox);
#define WinAPI_DoEnvironmentSubst(szString, cbString)	DoEnvironmentSubstA(szString, cbString)
#define WinAPI_DoEnvironmentSubstA(szString, cbString)	DoEnvironmentSubstA(szString, cbString)
__EXTERN INTEGER __CALL_1 DoEnvironmentSubstA(INTEGER szString, INTEGER cbString);
#define WinAPI_DoEnvironmentSubstW(szString, cbString)	DoEnvironmentSubstW(szString, cbString)
__EXTERN INTEGER __CALL_1 DoEnvironmentSubstW(INTEGER szString, INTEGER cbString);
#define WinAPI_DocumentProperties(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeOutput__typ, pDevModeInput, pDevModeInput__typ, fMode)	DocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)
#define WinAPI_DocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeOutput__typ, pDevModeInput, pDevModeInput__typ, fMode)	DocumentPropertiesA(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)
__EXTERN INTEGER __CALL_1 DocumentPropertiesA(INTEGER hWnd, INTEGER hPrinter, INTEGER pDeviceName, WinAPI_DEVMODEA *pDevModeOutput, WinAPI_DEVMODEA *pDevModeInput, SET fMode);
#define WinAPI_DocumentPropertiesW(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeOutput__typ, pDevModeInput, pDevModeInput__typ, fMode)	DocumentPropertiesW(hWnd, hPrinter, pDeviceName, pDevModeOutput, pDevModeInput, fMode)
__EXTERN INTEGER __CALL_1 DocumentPropertiesW(INTEGER hWnd, INTEGER hPrinter, INTEGER pDeviceName, WinAPI_DEVMODEW *pDevModeOutput, WinAPI_DEVMODEW *pDevModeInput, SET fMode);
#define WinAPI_DosDateTimeToFileTime(wFatDate, wFatTime, lpFileTime, lpFileTime__typ)	DosDateTimeToFileTime(wFatDate, wFatTime, lpFileTime)
__EXTERN INTEGER __CALL_1 DosDateTimeToFileTime(SHORTINT wFatDate, SHORTINT wFatTime, WinAPI_FILETIME *lpFileTime);
#define WinAPI_DragAcceptFiles(p0, p1)	DragAcceptFiles(p0, p1)
__EXTERN void __CALL_1 DragAcceptFiles(INTEGER p0, INTEGER p1);
#define WinAPI_DragDetect(p0, p1)	DragDetect(p0, p1)
__EXTERN INTEGER __CALL_1 DragDetect(INTEGER p0, WinAPI_POINT p1);
#define WinAPI_DragFinish(p0)	DragFinish(p0)
__EXTERN void __CALL_1 DragFinish(INTEGER p0);
#define WinAPI_DragObject(p0, p1, p2, p3, p4)	DragObject(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 DragObject(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_DragQueryFile(p0, p1, p2, p3)	DragQueryFileA(p0, p1, p2, p3)
#define WinAPI_DragQueryFileA(p0, p1, p2, p3)	DragQueryFileA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 DragQueryFileA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_DragQueryFileW(p0, p1, p2, p3)	DragQueryFileW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 DragQueryFileW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_DragQueryPoint(p0, p1, p1__typ)	DragQueryPoint(p0, p1)
__EXTERN INTEGER __CALL_1 DragQueryPoint(INTEGER p0, WinAPI_POINT *p1);
#define WinAPI_DrawAnimatedRects(hwnd, idAni, lprcFrom, lprcFrom__typ, lprcTo, lprcTo__typ)	DrawAnimatedRects(hwnd, idAni, lprcFrom, lprcTo)
__EXTERN INTEGER __CALL_1 DrawAnimatedRects(INTEGER hwnd, INTEGER idAni, WinAPI_RECT *lprcFrom, WinAPI_RECT *lprcTo);
#define WinAPI_DrawCaption(p0, p1, p2, p2__typ, p3)	DrawCaption(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 DrawCaption(INTEGER p0, INTEGER p1, WinAPI_RECT *p2, INTEGER p3);
#define WinAPI_DrawEdge(hdc, qrc, qrc__typ, edge, grfFlags)	DrawEdge(hdc, qrc, edge, grfFlags)
__EXTERN INTEGER __CALL_1 DrawEdge(INTEGER hdc, WinAPI_RECT *qrc, SET edge, SET grfFlags);
#define WinAPI_DrawEscape(p0, p1, p2, p3)	DrawEscape(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 DrawEscape(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_DrawFocusRect(hDC, lprc, lprc__typ)	DrawFocusRect(hDC, lprc)
__EXTERN INTEGER __CALL_1 DrawFocusRect(INTEGER hDC, WinAPI_RECT *lprc);
#define WinAPI_DrawFrameControl(p0, p1, p1__typ, p2, p3)	DrawFrameControl(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 DrawFrameControl(INTEGER p0, WinAPI_RECT *p1, INTEGER p2, SET p3);
#define WinAPI_DrawIcon(hDC, X, Y, hIcon)	DrawIcon(hDC, X, Y, hIcon)
__EXTERN INTEGER __CALL_1 DrawIcon(INTEGER hDC, INTEGER X, INTEGER Y, INTEGER hIcon);
#define WinAPI_DrawIconEx(hdc, xLeft, yTop, hIcon, cxWidth, cyWidth, istepIfAniCur, hbrFlickerFreeDraw, diFlags)	DrawIconEx(hdc, xLeft, yTop, hIcon, cxWidth, cyWidth, istepIfAniCur, hbrFlickerFreeDraw, diFlags)
__EXTERN INTEGER __CALL_1 DrawIconEx(INTEGER hdc, INTEGER xLeft, INTEGER yTop, INTEGER hIcon, INTEGER cxWidth, INTEGER cyWidth, INTEGER istepIfAniCur, INTEGER hbrFlickerFreeDraw, SET diFlags);
#define WinAPI_DrawMenuBar(hWnd)	DrawMenuBar(hWnd)
__EXTERN INTEGER __CALL_1 DrawMenuBar(INTEGER hWnd);
#define WinAPI_DrawState(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)	DrawStateA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)
#define WinAPI_DrawStateA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)	DrawStateA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)
__EXTERN INTEGER __CALL_1 DrawStateA(INTEGER p0, INTEGER p1, WinAPI_DRAWSTATEPROC p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, SET p9);
#define WinAPI_DrawStateW(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)	DrawStateW(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)
__EXTERN INTEGER __CALL_1 DrawStateW(INTEGER p0, INTEGER p1, WinAPI_DRAWSTATEPROC p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, SET p9);
#define WinAPI_DrawText(hDC, lpString, nCount, lpRect, lpRect__typ, uFormat)	DrawTextA(hDC, lpString, nCount, lpRect, uFormat)
#define WinAPI_DrawTextA(hDC, lpString, nCount, lpRect, lpRect__typ, uFormat)	DrawTextA(hDC, lpString, nCount, lpRect, uFormat)
__EXTERN INTEGER __CALL_1 DrawTextA(INTEGER hDC, INTEGER lpString, INTEGER nCount, WinAPI_RECT *lpRect, SET uFormat);
#define WinAPI_DrawTextEx(p0, p1, p2, p3, p3__typ, p4, p5, p5__typ)	DrawTextExA(p0, p1, p2, p3, p4, p5)
#define WinAPI_DrawTextExA(p0, p1, p2, p3, p3__typ, p4, p5, p5__typ)	DrawTextExA(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 DrawTextExA(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_RECT *p3, INTEGER p4, WinAPI_DRAWTEXTPARAMS *p5);
#define WinAPI_DrawTextExW(p0, p1, p2, p3, p3__typ, p4, p5, p5__typ)	DrawTextExW(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 DrawTextExW(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_RECT *p3, INTEGER p4, WinAPI_DRAWTEXTPARAMS *p5);
#define WinAPI_DrawTextW(hDC, lpString, nCount, lpRect, lpRect__typ, uFormat)	DrawTextW(hDC, lpString, nCount, lpRect, uFormat)
__EXTERN INTEGER __CALL_1 DrawTextW(INTEGER hDC, INTEGER lpString, INTEGER nCount, WinAPI_RECT *lpRect, SET uFormat);
#define WinAPI_DuplicateHandle(hSourceProcessHandle, hSourceHandle, hTargetProcessHandle, lpTargetHandle, dwDesiredAccess, bInheritHandle, dwOptions)	DuplicateHandle(hSourceProcessHandle, hSourceHandle, hTargetProcessHandle, lpTargetHandle, dwDesiredAccess, bInheritHandle, dwOptions)
__EXTERN INTEGER __CALL_1 DuplicateHandle(INTEGER hSourceProcessHandle, INTEGER hSourceHandle, INTEGER hTargetProcessHandle, INTEGER *lpTargetHandle, SET dwDesiredAccess, INTEGER bInheritHandle, SET dwOptions);
#define WinAPI_DuplicateIcon(hInst, hIcon)	DuplicateIcon(hInst, hIcon)
__EXTERN INTEGER __CALL_1 DuplicateIcon(INTEGER hInst, INTEGER hIcon);
#define WinAPI_DuplicateToken(ExistingTokenHandle, ImpersonationLevel, DuplicateTokenHandle)	DuplicateToken(ExistingTokenHandle, ImpersonationLevel, DuplicateTokenHandle)
__EXTERN INTEGER __CALL_1 DuplicateToken(INTEGER ExistingTokenHandle, INTEGER ImpersonationLevel, INTEGER *DuplicateTokenHandle);
#define WinAPI_Ellipse(p0, p1, p2, p3, p4)	Ellipse(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 Ellipse(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_EmptyClipboard()	EmptyClipboard()
__EXTERN INTEGER __CALL_1 EmptyClipboard(void);
#define WinAPI_EnableMenuItem(hMenu, uIDEnableItem, uEnable)	EnableMenuItem(hMenu, uIDEnableItem, uEnable)
__EXTERN INTEGER __CALL_1 EnableMenuItem(INTEGER hMenu, INTEGER uIDEnableItem, SET uEnable);
#define WinAPI_EnableScrollBar(hWnd, wSBflags, wArrows)	EnableScrollBar(hWnd, wSBflags, wArrows)
__EXTERN INTEGER __CALL_1 EnableScrollBar(INTEGER hWnd, INTEGER wSBflags, INTEGER wArrows);
#define WinAPI_EnableWindow(hWnd, bEnable)	EnableWindow(hWnd, bEnable)
__EXTERN INTEGER __CALL_1 EnableWindow(INTEGER hWnd, INTEGER bEnable);
#define WinAPI_EndDeferWindowPos(hWinPosInfo)	EndDeferWindowPos(hWinPosInfo)
__EXTERN INTEGER __CALL_1 EndDeferWindowPos(INTEGER hWinPosInfo);
#define WinAPI_EndDialog(hDlg, nResult)	EndDialog(hDlg, nResult)
__EXTERN INTEGER __CALL_1 EndDialog(INTEGER hDlg, INTEGER nResult);
#define WinAPI_EndDoc(p0)	EndDoc(p0)
__EXTERN INTEGER __CALL_1 EndDoc(INTEGER p0);
#define WinAPI_EndDocPrinter(hPrinter)	EndDocPrinter(hPrinter)
__EXTERN INTEGER __CALL_1 EndDocPrinter(INTEGER hPrinter);
#define WinAPI_EndPage(p0)	EndPage(p0)
__EXTERN INTEGER __CALL_1 EndPage(INTEGER p0);
#define WinAPI_EndPagePrinter(hPrinter)	EndPagePrinter(hPrinter)
__EXTERN INTEGER __CALL_1 EndPagePrinter(INTEGER hPrinter);
#define WinAPI_EndPaint(hWnd, lpPaint, lpPaint__typ)	EndPaint(hWnd, lpPaint)
__EXTERN INTEGER __CALL_1 EndPaint(INTEGER hWnd, WinAPI_PAINTSTRUCT *lpPaint);
#define WinAPI_EndPath(p0)	EndPath(p0)
__EXTERN INTEGER __CALL_1 EndPath(INTEGER p0);
#define WinAPI_EndUpdateResource(hUpdate, fDiscard)	EndUpdateResourceA(hUpdate, fDiscard)
#define WinAPI_EndUpdateResourceA(hUpdate, fDiscard)	EndUpdateResourceA(hUpdate, fDiscard)
__EXTERN INTEGER __CALL_1 EndUpdateResourceA(INTEGER hUpdate, INTEGER fDiscard);
#define WinAPI_EndUpdateResourceW(hUpdate, fDiscard)	EndUpdateResourceW(hUpdate, fDiscard)
__EXTERN INTEGER __CALL_1 EndUpdateResourceW(INTEGER hUpdate, INTEGER fDiscard);
#define WinAPI_EnterCriticalSection(lpCriticalSection, lpCriticalSection__typ)	EnterCriticalSection(lpCriticalSection)
__EXTERN void __CALL_1 EnterCriticalSection(WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinAPI_EnumCalendarInfo(lpCalInfoEnumProc, Locale, Calendar, CalType)	EnumCalendarInfoA(lpCalInfoEnumProc, Locale, Calendar, CalType)
#define WinAPI_EnumCalendarInfoA(lpCalInfoEnumProc, Locale, Calendar, CalType)	EnumCalendarInfoA(lpCalInfoEnumProc, Locale, Calendar, CalType)
__EXTERN INTEGER __CALL_1 EnumCalendarInfoA(WinAPI_CALINFO_ENUMPROCA lpCalInfoEnumProc, INTEGER Locale, INTEGER Calendar, INTEGER CalType);
#define WinAPI_EnumCalendarInfoW(lpCalInfoEnumProc, Locale, Calendar, CalType)	EnumCalendarInfoW(lpCalInfoEnumProc, Locale, Calendar, CalType)
__EXTERN INTEGER __CALL_1 EnumCalendarInfoW(WinAPI_CALINFO_ENUMPROCW lpCalInfoEnumProc, INTEGER Locale, INTEGER Calendar, INTEGER CalType);
#define WinAPI_EnumChildWindows(hWndParent, lpEnumFunc, lParam)	EnumChildWindows(hWndParent, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumChildWindows(INTEGER hWndParent, WinAPI_WNDENUMPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumClipboardFormats(format)	EnumClipboardFormats(format)
__EXTERN INTEGER __CALL_1 EnumClipboardFormats(INTEGER format);
#define WinAPI_EnumDateFormats(lpDateFmtEnumProc, Locale, dwFlags)	EnumDateFormatsA(lpDateFmtEnumProc, Locale, dwFlags)
#define WinAPI_EnumDateFormatsA(lpDateFmtEnumProc, Locale, dwFlags)	EnumDateFormatsA(lpDateFmtEnumProc, Locale, dwFlags)
__EXTERN INTEGER __CALL_1 EnumDateFormatsA(WinAPI_DATEFMT_ENUMPROCA lpDateFmtEnumProc, INTEGER Locale, SET dwFlags);
#define WinAPI_EnumDateFormatsW(lpDateFmtEnumProc, Locale, dwFlags)	EnumDateFormatsW(lpDateFmtEnumProc, Locale, dwFlags)
__EXTERN INTEGER __CALL_1 EnumDateFormatsW(WinAPI_DATEFMT_ENUMPROCW lpDateFmtEnumProc, INTEGER Locale, SET dwFlags);
#define WinAPI_EnumDependentServices(hService, dwServiceState, lpServices, lpServices__typ, cbBufSize, pcbBytesNeeded, lpServicesReturned)	EnumDependentServicesA(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)
#define WinAPI_EnumDependentServicesA(hService, dwServiceState, lpServices, lpServices__typ, cbBufSize, pcbBytesNeeded, lpServicesReturned)	EnumDependentServicesA(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)
__EXTERN INTEGER __CALL_1 EnumDependentServicesA(INTEGER hService, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSA *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned);
#define WinAPI_EnumDependentServicesW(hService, dwServiceState, lpServices, lpServices__typ, cbBufSize, pcbBytesNeeded, lpServicesReturned)	EnumDependentServicesW(hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned)
__EXTERN INTEGER __CALL_1 EnumDependentServicesW(INTEGER hService, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSW *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned);
#define WinAPI_EnumDesktopWindows(hDesktop, lpfn, lParam)	EnumDesktopWindows(hDesktop, lpfn, lParam)
__EXTERN INTEGER __CALL_1 EnumDesktopWindows(INTEGER hDesktop, WinAPI_WNDENUMPROC lpfn, INTEGER lParam);
#define WinAPI_EnumDesktops(hwinsta, lpEnumFunc, lParam)	EnumDesktopsA(hwinsta, lpEnumFunc, lParam)
#define WinAPI_EnumDesktopsA(hwinsta, lpEnumFunc, lParam)	EnumDesktopsA(hwinsta, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumDesktopsA(INTEGER hwinsta, WinAPI_DESKTOPENUMPROCA lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumDesktopsW(hwinsta, lpEnumFunc, lParam)	EnumDesktopsW(hwinsta, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumDesktopsW(INTEGER hwinsta, WinAPI_DESKTOPENUMPROCW lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumDisplaySettings(lpszDeviceName, iModeNum, lpDevMode, lpDevMode__typ)	EnumDisplaySettingsA(lpszDeviceName, iModeNum, lpDevMode)
#define WinAPI_EnumDisplaySettingsA(lpszDeviceName, iModeNum, lpDevMode, lpDevMode__typ)	EnumDisplaySettingsA(lpszDeviceName, iModeNum, lpDevMode)
__EXTERN INTEGER __CALL_1 EnumDisplaySettingsA(INTEGER lpszDeviceName, INTEGER iModeNum, WinAPI_DEVMODEA *lpDevMode);
#define WinAPI_EnumDisplaySettingsW(lpszDeviceName, iModeNum, lpDevMode, lpDevMode__typ)	EnumDisplaySettingsW(lpszDeviceName, iModeNum, lpDevMode)
__EXTERN INTEGER __CALL_1 EnumDisplaySettingsW(INTEGER lpszDeviceName, INTEGER iModeNum, WinAPI_DEVMODEW *lpDevMode);
#define WinAPI_EnumEnhMetaFile(p0, p1, p2, p3, p4, p4__typ)	EnumEnhMetaFile(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 EnumEnhMetaFile(INTEGER p0, INTEGER p1, WinAPI_ENHMFENUMPROC p2, INTEGER p3, WinAPI_RECT *p4);
#define WinAPI_EnumFontFamilies(p0, p1, p2, p3)	EnumFontFamiliesA(p0, p1, p2, p3)
#define WinAPI_EnumFontFamiliesA(p0, p1, p2, p3)	EnumFontFamiliesA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 EnumFontFamiliesA(INTEGER p0, INTEGER p1, WinAPI_NEWFONTENUMPROCA p2, INTEGER p3);
#define WinAPI_EnumFontFamiliesEx(p0, p1, p1__typ, p2, p3, p4)	EnumFontFamiliesExA(p0, p1, p2, p3, p4)
#define WinAPI_EnumFontFamiliesExA(p0, p1, p1__typ, p2, p3, p4)	EnumFontFamiliesExA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 EnumFontFamiliesExA(INTEGER p0, WinAPI_LOGFONTA *p1, WinAPI_FONTENUMPROCEXA p2, INTEGER p3, INTEGER p4);
#define WinAPI_EnumFontFamiliesExW(p0, p1, p1__typ, p2, p3, p4)	EnumFontFamiliesExW(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 EnumFontFamiliesExW(INTEGER p0, WinAPI_LOGFONTW *p1, WinAPI_FONTENUMPROCEXW p2, INTEGER p3, INTEGER p4);
#define WinAPI_EnumFontFamiliesW(p0, p1, p2, p3)	EnumFontFamiliesW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 EnumFontFamiliesW(INTEGER p0, INTEGER p1, WinAPI_NEWFONTENUMPROCW p2, INTEGER p3);
#define WinAPI_EnumFonts(p0, p1, p2, p3)	EnumFontsA(p0, p1, p2, p3)
#define WinAPI_EnumFontsA(p0, p1, p2, p3)	EnumFontsA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 EnumFontsA(INTEGER p0, INTEGER p1, WinAPI_FONTENUMPROCA p2, INTEGER p3);
#define WinAPI_EnumFontsW(p0, p1, p2, p3)	EnumFontsW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 EnumFontsW(INTEGER p0, INTEGER p1, WinAPI_FONTENUMPROCW p2, INTEGER p3);
#define WinAPI_EnumForms(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)	EnumFormsA(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumFormsA(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)	EnumFormsA(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumFormsA(INTEGER hPrinter, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumFormsW(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)	EnumFormsW(hPrinter, Level, pForm, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumFormsW(INTEGER hPrinter, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumICMProfiles(p0, p1, p2)	EnumICMProfilesA(p0, p1, p2)
#define WinAPI_EnumICMProfilesA(p0, p1, p2)	EnumICMProfilesA(p0, p1, p2)
__EXTERN INTEGER __CALL_1 EnumICMProfilesA(INTEGER p0, WinAPI_ICMENUMPROCA p1, INTEGER p2);
#define WinAPI_EnumICMProfilesW(p0, p1, p2)	EnumICMProfilesW(p0, p1, p2)
__EXTERN INTEGER __CALL_1 EnumICMProfilesW(INTEGER p0, WinAPI_ICMENUMPROCW p1, INTEGER p2);
#define WinAPI_EnumJobs(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)	EnumJobsA(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumJobsA(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)	EnumJobsA(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumJobsA(INTEGER hPrinter, INTEGER FirstJob, INTEGER NoJobs, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumJobsW(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)	EnumJobsW(hPrinter, FirstJob, NoJobs, Level, pJob, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumJobsW(INTEGER hPrinter, INTEGER FirstJob, INTEGER NoJobs, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumMetaFile(p0, p1, p2, p3)	EnumMetaFile(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 EnumMetaFile(INTEGER p0, INTEGER p1, WinAPI_MFENUMPROC p2, INTEGER p3);
#define WinAPI_EnumMonitors(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)	EnumMonitorsA(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumMonitorsA(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)	EnumMonitorsA(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumMonitorsA(INTEGER pName, INTEGER Level, CHAR *pMonitors, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumMonitorsW(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)	EnumMonitorsW(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumMonitorsW(INTEGER pName, INTEGER Level, CHAR *pMonitors, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumObjects(p0, p1, p2, p3)	EnumObjects(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 EnumObjects(INTEGER p0, INTEGER p1, WinAPI_GOBJENUMPROC p2, INTEGER p3);
#define WinAPI_EnumPorts(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)	EnumPortsA(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPortsA(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)	EnumPortsA(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumPortsA(INTEGER pName, INTEGER Level, CHAR *pPorts, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPortsW(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)	EnumPortsW(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumPortsW(INTEGER pName, INTEGER Level, CHAR *pPorts, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrintProcessorDatatypes(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorDatatypesA(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPrintProcessorDatatypesA(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorDatatypesA(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumPrintProcessorDatatypesA(INTEGER pName, INTEGER pPrintProcessorName, INTEGER Level, CHAR *pDatatypes, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrintProcessorDatatypesW(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorDatatypesW(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumPrintProcessorDatatypesW(INTEGER pName, INTEGER pPrintProcessorName, INTEGER Level, CHAR *pDatatypes, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrintProcessors(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorsA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPrintProcessorsA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorsA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumPrintProcessorsA(INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrintProcessorsW(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrintProcessorsW(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumPrintProcessorsW(INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrinterDrivers(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrinterDriversA(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPrinterDriversA(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrinterDriversA(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumPrinterDriversA(INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrinterDriversW(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)	EnumPrinterDriversW(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumPrinterDriversW(INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrinters(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)	EnumPrintersA(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)
#define WinAPI_EnumPrintersA(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)	EnumPrintersA(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumPrintersA(SET Flags, INTEGER Name, INTEGER Level, CHAR *pPrinterEnum, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumPrintersW(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)	EnumPrintersW(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned)
__EXTERN INTEGER __CALL_1 EnumPrintersW(SET Flags, INTEGER Name, INTEGER Level, CHAR *pPrinterEnum, INTEGER cbBuf, INTEGER *pcbNeeded, INTEGER *pcReturned);
#define WinAPI_EnumProps(hWnd, lpEnumFunc)	EnumPropsA(hWnd, lpEnumFunc)
#define WinAPI_EnumPropsA(hWnd, lpEnumFunc)	EnumPropsA(hWnd, lpEnumFunc)
__EXTERN INTEGER __CALL_1 EnumPropsA(INTEGER hWnd, WinAPI_ROPENUMPROCA lpEnumFunc);
#define WinAPI_EnumPropsEx(hWnd, lpEnumFunc, lParam)	EnumPropsExA(hWnd, lpEnumFunc, lParam)
#define WinAPI_EnumPropsExA(hWnd, lpEnumFunc, lParam)	EnumPropsExA(hWnd, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumPropsExA(INTEGER hWnd, WinAPI_ROPENUMPROCEXA lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumPropsExW(hWnd, lpEnumFunc, lParam)	EnumPropsExW(hWnd, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumPropsExW(INTEGER hWnd, WinAPI_ROPENUMPROCEXW lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumPropsW(hWnd, lpEnumFunc)	EnumPropsW(hWnd, lpEnumFunc)
__EXTERN INTEGER __CALL_1 EnumPropsW(INTEGER hWnd, WinAPI_ROPENUMPROCW lpEnumFunc);
#define WinAPI_EnumResourceLanguages(hModule, lpType, lpName, lpEnumFunc, lParam)	EnumResourceLanguagesA(hModule, lpType, lpName, lpEnumFunc, lParam)
#define WinAPI_EnumResourceLanguagesA(hModule, lpType, lpName, lpEnumFunc, lParam)	EnumResourceLanguagesA(hModule, lpType, lpName, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumResourceLanguagesA(INTEGER hModule, INTEGER lpType, INTEGER lpName, WinAPI_ENUMRESLANGPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumResourceLanguagesW(hModule, lpType, lpName, lpEnumFunc, lParam)	EnumResourceLanguagesW(hModule, lpType, lpName, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumResourceLanguagesW(INTEGER hModule, INTEGER lpType, INTEGER lpName, WinAPI_ENUMRESLANGPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumResourceNames(hModule, lpType, lpEnumFunc, lParam)	EnumResourceNamesA(hModule, lpType, lpEnumFunc, lParam)
#define WinAPI_EnumResourceNamesA(hModule, lpType, lpEnumFunc, lParam)	EnumResourceNamesA(hModule, lpType, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumResourceNamesA(INTEGER hModule, INTEGER lpType, WinAPI_ENUMRESNAMEPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumResourceNamesW(hModule, lpType, lpEnumFunc, lParam)	EnumResourceNamesW(hModule, lpType, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumResourceNamesW(INTEGER hModule, INTEGER lpType, WinAPI_ENUMRESNAMEPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumResourceTypes(hModule, lpEnumFunc, lParam)	EnumResourceTypesA(hModule, lpEnumFunc, lParam)
#define WinAPI_EnumResourceTypesA(hModule, lpEnumFunc, lParam)	EnumResourceTypesA(hModule, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumResourceTypesA(INTEGER hModule, WinAPI_ENUMRESTYPEPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumResourceTypesW(hModule, lpEnumFunc, lParam)	EnumResourceTypesW(hModule, lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumResourceTypesW(INTEGER hModule, WinAPI_ENUMRESTYPEPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumServicesStatus(hSCManager, dwServiceType, dwServiceState, lpServices, lpServices__typ, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)	EnumServicesStatusA(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)
#define WinAPI_EnumServicesStatusA(hSCManager, dwServiceType, dwServiceState, lpServices, lpServices__typ, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)	EnumServicesStatusA(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)
__EXTERN INTEGER __CALL_1 EnumServicesStatusA(INTEGER hSCManager, SET dwServiceType, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSA *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned, INTEGER *lpResumeHandle);
#define WinAPI_EnumServicesStatusW(hSCManager, dwServiceType, dwServiceState, lpServices, lpServices__typ, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)	EnumServicesStatusW(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle)
__EXTERN INTEGER __CALL_1 EnumServicesStatusW(INTEGER hSCManager, SET dwServiceType, INTEGER dwServiceState, WinAPI_ENUM_SERVICE_STATUSW *lpServices, INTEGER cbBufSize, INTEGER *pcbBytesNeeded, INTEGER *lpServicesReturned, INTEGER *lpResumeHandle);
#define WinAPI_EnumSystemCodePages(lpCodePageEnumProc, dwFlags)	EnumSystemCodePagesA(lpCodePageEnumProc, dwFlags)
#define WinAPI_EnumSystemCodePagesA(lpCodePageEnumProc, dwFlags)	EnumSystemCodePagesA(lpCodePageEnumProc, dwFlags)
__EXTERN INTEGER __CALL_1 EnumSystemCodePagesA(WinAPI_CODEPAGE_ENUMPROCA lpCodePageEnumProc, SET dwFlags);
#define WinAPI_EnumSystemCodePagesW(lpCodePageEnumProc, dwFlags)	EnumSystemCodePagesW(lpCodePageEnumProc, dwFlags)
__EXTERN INTEGER __CALL_1 EnumSystemCodePagesW(WinAPI_CODEPAGE_ENUMPROCW lpCodePageEnumProc, SET dwFlags);
#define WinAPI_EnumSystemLocales(lpLocaleEnumProc, dwFlags)	EnumSystemLocalesA(lpLocaleEnumProc, dwFlags)
#define WinAPI_EnumSystemLocalesA(lpLocaleEnumProc, dwFlags)	EnumSystemLocalesA(lpLocaleEnumProc, dwFlags)
__EXTERN INTEGER __CALL_1 EnumSystemLocalesA(WinAPI_LOCALE_ENUMPROCA lpLocaleEnumProc, SET dwFlags);
#define WinAPI_EnumSystemLocalesW(lpLocaleEnumProc, dwFlags)	EnumSystemLocalesW(lpLocaleEnumProc, dwFlags)
__EXTERN INTEGER __CALL_1 EnumSystemLocalesW(WinAPI_LOCALE_ENUMPROCW lpLocaleEnumProc, SET dwFlags);
#define WinAPI_EnumThreadWindows(dwThreadId, lpfn, lParam)	EnumThreadWindows(dwThreadId, lpfn, lParam)
__EXTERN INTEGER __CALL_1 EnumThreadWindows(INTEGER dwThreadId, WinAPI_WNDENUMPROC lpfn, INTEGER lParam);
#define WinAPI_EnumTimeFormats(lpTimeFmtEnumProc, Locale, dwFlags)	EnumTimeFormatsA(lpTimeFmtEnumProc, Locale, dwFlags)
#define WinAPI_EnumTimeFormatsA(lpTimeFmtEnumProc, Locale, dwFlags)	EnumTimeFormatsA(lpTimeFmtEnumProc, Locale, dwFlags)
__EXTERN INTEGER __CALL_1 EnumTimeFormatsA(WinAPI_TIMEFMT_ENUMPROCA lpTimeFmtEnumProc, INTEGER Locale, SET dwFlags);
#define WinAPI_EnumTimeFormatsW(lpTimeFmtEnumProc, Locale, dwFlags)	EnumTimeFormatsW(lpTimeFmtEnumProc, Locale, dwFlags)
__EXTERN INTEGER __CALL_1 EnumTimeFormatsW(WinAPI_TIMEFMT_ENUMPROCW lpTimeFmtEnumProc, INTEGER Locale, SET dwFlags);
#define WinAPI_EnumWindowStations(lpEnumFunc, lParam)	EnumWindowStationsA(lpEnumFunc, lParam)
#define WinAPI_EnumWindowStationsA(lpEnumFunc, lParam)	EnumWindowStationsA(lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumWindowStationsA(WinAPI_WINSTAENUMPROCA lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumWindowStationsW(lpEnumFunc, lParam)	EnumWindowStationsW(lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumWindowStationsW(WinAPI_WINSTAENUMPROCW lpEnumFunc, INTEGER lParam);
#define WinAPI_EnumWindows(lpEnumFunc, lParam)	EnumWindows(lpEnumFunc, lParam)
__EXTERN INTEGER __CALL_1 EnumWindows(WinAPI_WNDENUMPROC lpEnumFunc, INTEGER lParam);
#define WinAPI_EqualPrefixSid(pSid1, pSid2)	EqualPrefixSid(pSid1, pSid2)
__EXTERN INTEGER __CALL_1 EqualPrefixSid(INTEGER pSid1, INTEGER pSid2);
#define WinAPI_EqualRect(lprc1, lprc1__typ, lprc2, lprc2__typ)	EqualRect(lprc1, lprc2)
__EXTERN INTEGER __CALL_1 EqualRect(WinAPI_RECT *lprc1, WinAPI_RECT *lprc2);
#define WinAPI_EqualRgn(p0, p1)	EqualRgn(p0, p1)
__EXTERN INTEGER __CALL_1 EqualRgn(INTEGER p0, INTEGER p1);
#define WinAPI_EqualSid(pSid1, pSid2)	EqualSid(pSid1, pSid2)
__EXTERN INTEGER __CALL_1 EqualSid(INTEGER pSid1, INTEGER pSid2);
#define WinAPI_EraseTape(hDevice, dwEraseType, bImmediate)	EraseTape(hDevice, dwEraseType, bImmediate)
__EXTERN INTEGER __CALL_1 EraseTape(INTEGER hDevice, INTEGER dwEraseType, INTEGER bImmediate);
#define WinAPI_Escape(p0, p1, p2, p3, p4)	Escape(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 Escape(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_EscapeCommFunction(hFile, dwFunc)	EscapeCommFunction(hFile, dwFunc)
__EXTERN INTEGER __CALL_1 EscapeCommFunction(INTEGER hFile, INTEGER dwFunc);
#define WinAPI_ExcludeClipRect(p0, p1, p2, p3, p4)	ExcludeClipRect(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 ExcludeClipRect(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_ExcludeUpdateRgn(hDC, hWnd)	ExcludeUpdateRgn(hDC, hWnd)
__EXTERN INTEGER __CALL_1 ExcludeUpdateRgn(INTEGER hDC, INTEGER hWnd);
#define WinAPI_ExitProcess(uExitCode)	ExitProcess(uExitCode)
__EXTERN void __CALL_1 ExitProcess(INTEGER uExitCode);
#define WinAPI_ExitThread(dwExitCode)	ExitThread(dwExitCode)
__EXTERN void __CALL_1 ExitThread(INTEGER dwExitCode);
#define WinAPI_ExitWindowsEx(uFlags, dwReserved)	ExitWindowsEx(uFlags, dwReserved)
__EXTERN INTEGER __CALL_1 ExitWindowsEx(SET uFlags, INTEGER dwReserved);
#define WinAPI_ExpandEnvironmentStrings(lpSrc, lpDst, nSize)	ExpandEnvironmentStringsA(lpSrc, lpDst, nSize)
#define WinAPI_ExpandEnvironmentStringsA(lpSrc, lpDst, nSize)	ExpandEnvironmentStringsA(lpSrc, lpDst, nSize)
__EXTERN INTEGER __CALL_1 ExpandEnvironmentStringsA(INTEGER lpSrc, INTEGER lpDst, INTEGER nSize);
#define WinAPI_ExpandEnvironmentStringsW(lpSrc, lpDst, nSize)	ExpandEnvironmentStringsW(lpSrc, lpDst, nSize)
__EXTERN INTEGER __CALL_1 ExpandEnvironmentStringsW(INTEGER lpSrc, INTEGER lpDst, INTEGER nSize);
#define WinAPI_ExtCreatePen(p0, p1, p2, p2__typ, p3, p4)	ExtCreatePen(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 ExtCreatePen(INTEGER p0, INTEGER p1, WinAPI_LOGBRUSH *p2, INTEGER p3, INTEGER *p4);
#define WinAPI_ExtCreateRegion(p0, p0__typ, p1, p2, p2__typ)	ExtCreateRegion(p0, p1, p2)
__EXTERN INTEGER __CALL_1 ExtCreateRegion(WinAPI_XFORM *p0, INTEGER p1, WinAPI_RGNDATA *p2);
#define WinAPI_ExtEscape(p0, p1, p2, p3, p4, p5)	ExtEscape(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 ExtEscape(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
#define WinAPI_ExtFloodFill(p0, p1, p2, p3, p4)	ExtFloodFill(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 ExtFloodFill(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_ExtSelectClipRgn(p0, p1, p2)	ExtSelectClipRgn(p0, p1, p2)
__EXTERN INTEGER __CALL_1 ExtSelectClipRgn(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_ExtTextOut(p0, p1, p2, p3, p4, p4__typ, p5, p6, p7)	ExtTextOutA(p0, p1, p2, p3, p4, p5, p6, p7)
#define WinAPI_ExtTextOutA(p0, p1, p2, p3, p4, p4__typ, p5, p6, p7)	ExtTextOutA(p0, p1, p2, p3, p4, p5, p6, p7)
__EXTERN INTEGER __CALL_1 ExtTextOutA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_RECT *p4, INTEGER p5, INTEGER p6, INTEGER *p7);
#define WinAPI_ExtTextOutW(p0, p1, p2, p3, p4, p4__typ, p5, p6, p7)	ExtTextOutW(p0, p1, p2, p3, p4, p5, p6, p7)
__EXTERN INTEGER __CALL_1 ExtTextOutW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_RECT *p4, INTEGER p5, INTEGER p6, INTEGER *p7);
#define WinAPI_ExtractAssociatedIcon(hInst, lpIconPath, lpiIcon)	ExtractAssociatedIconA(hInst, lpIconPath, lpiIcon)
#define WinAPI_ExtractAssociatedIconA(hInst, lpIconPath, lpiIcon)	ExtractAssociatedIconA(hInst, lpIconPath, lpiIcon)
__EXTERN INTEGER __CALL_1 ExtractAssociatedIconA(INTEGER hInst, INTEGER lpIconPath, SHORTINT *lpiIcon);
#define WinAPI_ExtractAssociatedIconW(hInst, lpIconPath, lpiIcon)	ExtractAssociatedIconW(hInst, lpIconPath, lpiIcon)
__EXTERN INTEGER __CALL_1 ExtractAssociatedIconW(INTEGER hInst, INTEGER lpIconPath, SHORTINT *lpiIcon);
#define WinAPI_ExtractIcon(hInst, lpszExeFileName, nIconIndex)	ExtractIconA(hInst, lpszExeFileName, nIconIndex)
#define WinAPI_ExtractIconA(hInst, lpszExeFileName, nIconIndex)	ExtractIconA(hInst, lpszExeFileName, nIconIndex)
__EXTERN INTEGER __CALL_1 ExtractIconA(INTEGER hInst, INTEGER lpszExeFileName, INTEGER nIconIndex);
#define WinAPI_ExtractIconEx(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)	ExtractIconExA(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)
#define WinAPI_ExtractIconExA(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)	ExtractIconExA(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)
__EXTERN INTEGER __CALL_1 ExtractIconExA(INTEGER lpszFile, INTEGER nIconIndex, INTEGER *phiconLarge, INTEGER *phiconSmall, INTEGER nIcons);
#define WinAPI_ExtractIconExW(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)	ExtractIconExW(lpszFile, nIconIndex, phiconLarge, phiconSmall, nIcons)
__EXTERN INTEGER __CALL_1 ExtractIconExW(INTEGER lpszFile, INTEGER nIconIndex, INTEGER *phiconLarge, INTEGER *phiconSmall, INTEGER nIcons);
#define WinAPI_ExtractIconW(hInst, lpszExeFileName, nIconIndex)	ExtractIconW(hInst, lpszExeFileName, nIconIndex)
__EXTERN INTEGER __CALL_1 ExtractIconW(INTEGER hInst, INTEGER lpszExeFileName, INTEGER nIconIndex);
#define WinAPI_FatalAppExit(uAction, lpMessageText)	FatalAppExitA(uAction, lpMessageText)
#define WinAPI_FatalAppExitA(uAction, lpMessageText)	FatalAppExitA(uAction, lpMessageText)
__EXTERN void __CALL_1 FatalAppExitA(INTEGER uAction, INTEGER lpMessageText);
#define WinAPI_FatalAppExitW(uAction, lpMessageText)	FatalAppExitW(uAction, lpMessageText)
__EXTERN void __CALL_1 FatalAppExitW(INTEGER uAction, INTEGER lpMessageText);
#define WinAPI_FatalExit(ExitCode)	FatalExit(ExitCode)
__EXTERN void __CALL_1 FatalExit(INTEGER ExitCode);
#define WinAPI_FileTimeToDosDateTime(lpFileTime, lpFileTime__typ, lpFatDate, lpFatTime)	FileTimeToDosDateTime(lpFileTime, lpFatDate, lpFatTime)
__EXTERN INTEGER __CALL_1 FileTimeToDosDateTime(WinAPI_FILETIME *lpFileTime, SHORTINT *lpFatDate, SHORTINT *lpFatTime);
#define WinAPI_FileTimeToLocalFileTime(lpFileTime, lpFileTime__typ, lpLocalFileTime, lpLocalFileTime__typ)	FileTimeToLocalFileTime(lpFileTime, lpLocalFileTime)
__EXTERN INTEGER __CALL_1 FileTimeToLocalFileTime(WinAPI_FILETIME *lpFileTime, WinAPI_FILETIME *lpLocalFileTime);
#define WinAPI_FileTimeToSystemTime(lpFileTime, lpFileTime__typ, lpSystemTime, lpSystemTime__typ)	FileTimeToSystemTime(lpFileTime, lpSystemTime)
__EXTERN INTEGER __CALL_1 FileTimeToSystemTime(WinAPI_FILETIME *lpFileTime, WinAPI_SYSTEMTIME *lpSystemTime);
#define WinAPI_FillConsoleOutputAttribute(hConsoleOutput, wAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten)	FillConsoleOutputAttribute(hConsoleOutput, wAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten)
__EXTERN INTEGER __CALL_1 FillConsoleOutputAttribute(INTEGER hConsoleOutput, SHORTINT wAttribute, INTEGER nLength, WinAPI_COORD dwWriteCoord, INTEGER *lpNumberOfAttrsWritten);
#define WinAPI_FillConsoleOutputCharacter(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	FillConsoleOutputCharacterA(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
#define WinAPI_FillConsoleOutputCharacterA(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	FillConsoleOutputCharacterA(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __CALL_1 FillConsoleOutputCharacterA(INTEGER hConsoleOutput, CHAR cCharacter, INTEGER nLength, WinAPI_COORD dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
#define WinAPI_FillConsoleOutputCharacterW(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	FillConsoleOutputCharacterW(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __CALL_1 FillConsoleOutputCharacterW(INTEGER hConsoleOutput, SHORTINT cCharacter, INTEGER nLength, WinAPI_COORD dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
#define WinAPI_FillPath(p0)	FillPath(p0)
__EXTERN INTEGER __CALL_1 FillPath(INTEGER p0);
#define WinAPI_FillRect(hDC, lprc, lprc__typ, hbr)	FillRect(hDC, lprc, hbr)
__EXTERN INTEGER __CALL_1 FillRect(INTEGER hDC, WinAPI_RECT *lprc, INTEGER hbr);
#define WinAPI_FillRgn(p0, p1, p2)	FillRgn(p0, p1, p2)
__EXTERN INTEGER __CALL_1 FillRgn(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_FindAtom(lpString)	FindAtomA(lpString)
#define WinAPI_FindAtomA(lpString)	FindAtomA(lpString)
__EXTERN SHORTINT __CALL_1 FindAtomA(INTEGER lpString);
#define WinAPI_FindAtomW(lpString)	FindAtomW(lpString)
__EXTERN SHORTINT __CALL_1 FindAtomW(INTEGER lpString);
#define WinAPI_FindClose(hFindFile)	FindClose(hFindFile)
__EXTERN INTEGER __CALL_1 FindClose(INTEGER hFindFile);
#define WinAPI_FindCloseChangeNotification(hChangeHandle)	FindCloseChangeNotification(hChangeHandle)
__EXTERN INTEGER __CALL_1 FindCloseChangeNotification(INTEGER hChangeHandle);
#define WinAPI_FindClosePrinterChangeNotification(hChange)	FindClosePrinterChangeNotification(hChange)
__EXTERN INTEGER __CALL_1 FindClosePrinterChangeNotification(INTEGER hChange);
#define WinAPI_FindExecutable(lpFile, lpDirectory, lpResult)	FindExecutableA(lpFile, lpDirectory, lpResult)
#define WinAPI_FindExecutableA(lpFile, lpDirectory, lpResult)	FindExecutableA(lpFile, lpDirectory, lpResult)
__EXTERN INTEGER __CALL_1 FindExecutableA(INTEGER lpFile, INTEGER lpDirectory, INTEGER lpResult);
#define WinAPI_FindExecutableW(lpFile, lpDirectory, lpResult)	FindExecutableW(lpFile, lpDirectory, lpResult)
__EXTERN INTEGER __CALL_1 FindExecutableW(INTEGER lpFile, INTEGER lpDirectory, INTEGER lpResult);
#define WinAPI_FindFirstChangeNotification(lpPathName, bWatchSubtree, dwNotifyFilter)	FindFirstChangeNotificationA(lpPathName, bWatchSubtree, dwNotifyFilter)
#define WinAPI_FindFirstChangeNotificationA(lpPathName, bWatchSubtree, dwNotifyFilter)	FindFirstChangeNotificationA(lpPathName, bWatchSubtree, dwNotifyFilter)
__EXTERN INTEGER __CALL_1 FindFirstChangeNotificationA(INTEGER lpPathName, INTEGER bWatchSubtree, SET dwNotifyFilter);
#define WinAPI_FindFirstChangeNotificationW(lpPathName, bWatchSubtree, dwNotifyFilter)	FindFirstChangeNotificationW(lpPathName, bWatchSubtree, dwNotifyFilter)
__EXTERN INTEGER __CALL_1 FindFirstChangeNotificationW(INTEGER lpPathName, INTEGER bWatchSubtree, SET dwNotifyFilter);
#define WinAPI_FindFirstFile(lpFileName, lpFindFileData, lpFindFileData__typ)	FindFirstFileA(lpFileName, lpFindFileData)
#define WinAPI_FindFirstFileA(lpFileName, lpFindFileData, lpFindFileData__typ)	FindFirstFileA(lpFileName, lpFindFileData)
__EXTERN INTEGER __CALL_1 FindFirstFileA(INTEGER lpFileName, WinAPI_WIN32_FIND_DATAA *lpFindFileData);
#define WinAPI_FindFirstFileEx(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)	FindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)
#define WinAPI_FindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)	FindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)
__EXTERN INTEGER __CALL_1 FindFirstFileExA(INTEGER lpFileName, INTEGER fInfoLevelId, INTEGER lpFindFileData, INTEGER fSearchOp, INTEGER lpSearchFilter, INTEGER dwAdditionalFlags);
#define WinAPI_FindFirstFileExW(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)	FindFirstFileExW(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags)
__EXTERN INTEGER __CALL_1 FindFirstFileExW(INTEGER lpFileName, INTEGER fInfoLevelId, INTEGER lpFindFileData, INTEGER fSearchOp, INTEGER lpSearchFilter, INTEGER dwAdditionalFlags);
#define WinAPI_FindFirstFileW(lpFileName, lpFindFileData, lpFindFileData__typ)	FindFirstFileW(lpFileName, lpFindFileData)
__EXTERN INTEGER __CALL_1 FindFirstFileW(INTEGER lpFileName, WinAPI_WIN32_FIND_DATAW *lpFindFileData);
#define WinAPI_FindFirstFreeAce(pAcl, pAcl__typ, pAce)	FindFirstFreeAce(pAcl, pAce)
__EXTERN INTEGER __CALL_1 FindFirstFreeAce(WinAPI_ACL *pAcl, INTEGER pAce);
#define WinAPI_FindFirstPrinterChangeNotification(hPrinter, fdwFlags, fdwOptions, pPrinterNotifyOptions)	FindFirstPrinterChangeNotification(hPrinter, fdwFlags, fdwOptions, pPrinterNotifyOptions)
__EXTERN INTEGER __CALL_1 FindFirstPrinterChangeNotification(INTEGER hPrinter, SET fdwFlags, INTEGER fdwOptions, INTEGER pPrinterNotifyOptions);
#define WinAPI_FindNextChangeNotification(hChangeHandle)	FindNextChangeNotification(hChangeHandle)
__EXTERN INTEGER __CALL_1 FindNextChangeNotification(INTEGER hChangeHandle);
#define WinAPI_FindNextFile(hFindFile, lpFindFileData, lpFindFileData__typ)	FindNextFileA(hFindFile, lpFindFileData)
#define WinAPI_FindNextFileA(hFindFile, lpFindFileData, lpFindFileData__typ)	FindNextFileA(hFindFile, lpFindFileData)
__EXTERN INTEGER __CALL_1 FindNextFileA(INTEGER hFindFile, WinAPI_WIN32_FIND_DATAA *lpFindFileData);
#define WinAPI_FindNextFileW(hFindFile, lpFindFileData, lpFindFileData__typ)	FindNextFileW(hFindFile, lpFindFileData)
__EXTERN INTEGER __CALL_1 FindNextFileW(INTEGER hFindFile, WinAPI_WIN32_FIND_DATAW *lpFindFileData);
#define WinAPI_FindNextPrinterChangeNotification(hChange, pdwChange, pvReserved, ppPrinterNotifyInfo)	FindNextPrinterChangeNotification(hChange, pdwChange, pvReserved, ppPrinterNotifyInfo)
__EXTERN INTEGER __CALL_1 FindNextPrinterChangeNotification(INTEGER hChange, INTEGER *pdwChange, INTEGER pvReserved, INTEGER ppPrinterNotifyInfo);
#define WinAPI_FindResource(hModule, lpName, lpType)	FindResourceA(hModule, lpName, lpType)
#define WinAPI_FindResourceA(hModule, lpName, lpType)	FindResourceA(hModule, lpName, lpType)
__EXTERN INTEGER __CALL_1 FindResourceA(INTEGER hModule, INTEGER lpName, INTEGER lpType);
#define WinAPI_FindResourceEx(hModule, lpType, lpName, wLanguage)	FindResourceExA(hModule, lpType, lpName, wLanguage)
#define WinAPI_FindResourceExA(hModule, lpType, lpName, wLanguage)	FindResourceExA(hModule, lpType, lpName, wLanguage)
__EXTERN INTEGER __CALL_1 FindResourceExA(INTEGER hModule, INTEGER lpType, INTEGER lpName, SHORTINT wLanguage);
#define WinAPI_FindResourceExW(hModule, lpType, lpName, wLanguage)	FindResourceExW(hModule, lpType, lpName, wLanguage)
__EXTERN INTEGER __CALL_1 FindResourceExW(INTEGER hModule, INTEGER lpType, INTEGER lpName, SHORTINT wLanguage);
#define WinAPI_FindResourceW(hModule, lpName, lpType)	FindResourceW(hModule, lpName, lpType)
__EXTERN INTEGER __CALL_1 FindResourceW(INTEGER hModule, INTEGER lpName, INTEGER lpType);
#define WinAPI_FindWindow(lpClassName, lpWindowName)	FindWindowA(lpClassName, lpWindowName)
#define WinAPI_FindWindowA(lpClassName, lpWindowName)	FindWindowA(lpClassName, lpWindowName)
__EXTERN INTEGER __CALL_1 FindWindowA(INTEGER lpClassName, INTEGER lpWindowName);
#define WinAPI_FindWindowEx(p0, p1, p2, p3)	FindWindowExA(p0, p1, p2, p3)
#define WinAPI_FindWindowExA(p0, p1, p2, p3)	FindWindowExA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 FindWindowExA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_FindWindowExW(p0, p1, p2, p3)	FindWindowExW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 FindWindowExW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_FindWindowW(lpClassName, lpWindowName)	FindWindowW(lpClassName, lpWindowName)
__EXTERN INTEGER __CALL_1 FindWindowW(INTEGER lpClassName, INTEGER lpWindowName);
#define WinAPI_FixBrushOrgEx(p0, p1, p2, p3, p3__typ)	FixBrushOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 FixBrushOrgEx(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_FlashWindow(hWnd, bInvert)	FlashWindow(hWnd, bInvert)
__EXTERN INTEGER __CALL_1 FlashWindow(INTEGER hWnd, INTEGER bInvert);
#define WinAPI_FlattenPath(p0)	FlattenPath(p0)
__EXTERN INTEGER __CALL_1 FlattenPath(INTEGER p0);
#define WinAPI_FloodFill(p0, p1, p2, p3)	FloodFill(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 FloodFill(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_FlushConsoleInputBuffer(hConsoleInput)	FlushConsoleInputBuffer(hConsoleInput)
__EXTERN INTEGER __CALL_1 FlushConsoleInputBuffer(INTEGER hConsoleInput);
#define WinAPI_FlushFileBuffers(hFile)	FlushFileBuffers(hFile)
__EXTERN INTEGER __CALL_1 FlushFileBuffers(INTEGER hFile);
#define WinAPI_FlushInstructionCache(hProcess, lpBaseAddress, dwSize)	FlushInstructionCache(hProcess, lpBaseAddress, dwSize)
__EXTERN INTEGER __CALL_1 FlushInstructionCache(INTEGER hProcess, INTEGER lpBaseAddress, INTEGER dwSize);
#define WinAPI_FlushViewOfFile(lpBaseAddress, dwNumberOfBytesToFlush)	FlushViewOfFile(lpBaseAddress, dwNumberOfBytesToFlush)
__EXTERN INTEGER __CALL_1 FlushViewOfFile(INTEGER lpBaseAddress, INTEGER dwNumberOfBytesToFlush);
#define WinAPI_FoldString(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	FoldStringA(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
#define WinAPI_FoldStringA(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	FoldStringA(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
__EXTERN INTEGER __CALL_1 FoldStringA(SET dwMapFlags, INTEGER lpSrcStr, INTEGER cchSrc, INTEGER lpDestStr, INTEGER cchDest);
#define WinAPI_FoldStringW(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	FoldStringW(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
__EXTERN INTEGER __CALL_1 FoldStringW(SET dwMapFlags, INTEGER lpSrcStr, INTEGER cchSrc, INTEGER lpDestStr, INTEGER cchDest);
#define WinAPI_FormatMessage(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)	FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)
#define WinAPI_FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)	FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)
__EXTERN INTEGER __CALL_1 FormatMessageA(SET dwFlags, INTEGER lpSource, INTEGER dwMessageId, INTEGER dwLanguageId, INTEGER lpBuffer, INTEGER nSize, INTEGER *Arguments);
#define WinAPI_FormatMessageW(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)	FormatMessageW(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments)
__EXTERN INTEGER __CALL_1 FormatMessageW(SET dwFlags, INTEGER lpSource, INTEGER dwMessageId, INTEGER dwLanguageId, INTEGER lpBuffer, INTEGER nSize, INTEGER *Arguments);
#define WinAPI_FrameRect(hDC, lprc, lprc__typ, hbr)	FrameRect(hDC, lprc, hbr)
__EXTERN INTEGER __CALL_1 FrameRect(INTEGER hDC, WinAPI_RECT *lprc, INTEGER hbr);
#define WinAPI_FrameRgn(p0, p1, p2, p3, p4)	FrameRgn(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 FrameRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_FreeConsole()	FreeConsole()
__EXTERN INTEGER __CALL_1 FreeConsole(void);
#define WinAPI_FreeDDElParam(msg, lParam)	FreeDDElParam(msg, lParam)
__EXTERN INTEGER __CALL_1 FreeDDElParam(INTEGER msg, INTEGER lParam);
#define WinAPI_FreeEnvironmentStrings(p0)	FreeEnvironmentStringsA(p0)
#define WinAPI_FreeEnvironmentStringsA(p0)	FreeEnvironmentStringsA(p0)
__EXTERN INTEGER __CALL_1 FreeEnvironmentStringsA(INTEGER p0);
#define WinAPI_FreeEnvironmentStringsW(p0)	FreeEnvironmentStringsW(p0)
__EXTERN INTEGER __CALL_1 FreeEnvironmentStringsW(INTEGER p0);
#define WinAPI_FreeLibrary(hLibModule)	FreeLibrary(hLibModule)
__EXTERN INTEGER __CALL_1 FreeLibrary(INTEGER hLibModule);
#define WinAPI_FreeLibraryAndExitThread(hLibModule, dwExitCode)	FreeLibraryAndExitThread(hLibModule, dwExitCode)
__EXTERN void __CALL_1 FreeLibraryAndExitThread(INTEGER hLibModule, INTEGER dwExitCode);
#define WinAPI_FreePrinterNotifyInfo(pPrinterNotifyInfo, pPrinterNotifyInfo__typ)	FreePrinterNotifyInfo(pPrinterNotifyInfo)
__EXTERN INTEGER __CALL_1 FreePrinterNotifyInfo(WinAPI_PRINTER_NOTIFY_INFO *pPrinterNotifyInfo);
#define WinAPI_FreeResource(hResData)	FreeResource(hResData)
__EXTERN INTEGER __CALL_1 FreeResource(INTEGER hResData);
#define WinAPI_FreeSid(pSid)	FreeSid(pSid)
__EXTERN INTEGER __CALL_1 FreeSid(INTEGER pSid);
#define WinAPI_GdiComment(p0, p1, p2)	GdiComment(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GdiComment(INTEGER p0, INTEGER p1, CHAR *p2);
#define WinAPI_GdiFlush()	GdiFlush()
__EXTERN INTEGER __CALL_1 GdiFlush(void);
#define WinAPI_GdiGetBatchLimit()	GdiGetBatchLimit()
__EXTERN INTEGER __CALL_1 GdiGetBatchLimit(void);
#define WinAPI_GdiSetBatchLimit(p0)	GdiSetBatchLimit(p0)
__EXTERN INTEGER __CALL_1 GdiSetBatchLimit(INTEGER p0);
#define WinAPI_GenerateConsoleCtrlEvent(dwCtrlEvent, dwProcessGroupId)	GenerateConsoleCtrlEvent(dwCtrlEvent, dwProcessGroupId)
__EXTERN INTEGER __CALL_1 GenerateConsoleCtrlEvent(INTEGER dwCtrlEvent, INTEGER dwProcessGroupId);
#define WinAPI_GetACP()	GetACP()
__EXTERN INTEGER __CALL_1 GetACP(void);
#define WinAPI_GetAce(pAcl, pAcl__typ, dwAceIndex, pAce)	GetAce(pAcl, dwAceIndex, pAce)
__EXTERN INTEGER __CALL_1 GetAce(WinAPI_ACL *pAcl, INTEGER dwAceIndex, INTEGER pAce);
#define WinAPI_GetAclInformation(pAcl, pAcl__typ, pAclInformation, nAclInformationLength, dwAclInformationClass)	GetAclInformation(pAcl, pAclInformation, nAclInformationLength, dwAclInformationClass)
__EXTERN INTEGER __CALL_1 GetAclInformation(WinAPI_ACL *pAcl, INTEGER pAclInformation, INTEGER nAclInformationLength, INTEGER dwAclInformationClass);
#define WinAPI_GetActiveWindow()	GetActiveWindow()
__EXTERN INTEGER __CALL_1 GetActiveWindow(void);
#define WinAPI_GetArcDirection(p0)	GetArcDirection(p0)
__EXTERN INTEGER __CALL_1 GetArcDirection(INTEGER p0);
#define WinAPI_GetAspectRatioFilterEx(p0, p1, p1__typ)	GetAspectRatioFilterEx(p0, p1)
__EXTERN INTEGER __CALL_1 GetAspectRatioFilterEx(INTEGER p0, WinAPI_SIZE *p1);
#define WinAPI_GetAsyncKeyState(vKey)	GetAsyncKeyState(vKey)
__EXTERN SHORTINT __CALL_1 GetAsyncKeyState(INTEGER vKey);
#define WinAPI_GetAtomName(nAtom, lpBuffer, nSize)	GetAtomNameA(nAtom, lpBuffer, nSize)
#define WinAPI_GetAtomNameA(nAtom, lpBuffer, nSize)	GetAtomNameA(nAtom, lpBuffer, nSize)
__EXTERN INTEGER __CALL_1 GetAtomNameA(SHORTINT nAtom, INTEGER lpBuffer, INTEGER nSize);
#define WinAPI_GetAtomNameW(nAtom, lpBuffer, nSize)	GetAtomNameW(nAtom, lpBuffer, nSize)
__EXTERN INTEGER __CALL_1 GetAtomNameW(SHORTINT nAtom, INTEGER lpBuffer, INTEGER nSize);
#define WinAPI_GetBinaryType(lpApplicationName, lpBinaryType)	GetBinaryTypeA(lpApplicationName, lpBinaryType)
#define WinAPI_GetBinaryTypeA(lpApplicationName, lpBinaryType)	GetBinaryTypeA(lpApplicationName, lpBinaryType)
__EXTERN INTEGER __CALL_1 GetBinaryTypeA(INTEGER lpApplicationName, INTEGER *lpBinaryType);
#define WinAPI_GetBinaryTypeW(lpApplicationName, lpBinaryType)	GetBinaryTypeW(lpApplicationName, lpBinaryType)
__EXTERN INTEGER __CALL_1 GetBinaryTypeW(INTEGER lpApplicationName, INTEGER *lpBinaryType);
#define WinAPI_GetBitmapBits(p0, p1, p2)	GetBitmapBits(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetBitmapBits(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_GetBitmapDimensionEx(p0, p1, p1__typ)	GetBitmapDimensionEx(p0, p1)
__EXTERN INTEGER __CALL_1 GetBitmapDimensionEx(INTEGER p0, WinAPI_SIZE *p1);
#define WinAPI_GetBkColor(p0)	GetBkColor(p0)
__EXTERN INTEGER __CALL_1 GetBkColor(INTEGER p0);
#define WinAPI_GetBkMode(p0)	GetBkMode(p0)
__EXTERN INTEGER __CALL_1 GetBkMode(INTEGER p0);
#define WinAPI_GetBoundsRect(p0, p1, p1__typ, p2)	GetBoundsRect(p0, p1, p2)
__EXTERN SET __CALL_1 GetBoundsRect(INTEGER p0, WinAPI_RECT *p1, SET p2);
#define WinAPI_GetBrushOrgEx(p0, p1, p1__typ)	GetBrushOrgEx(p0, p1)
__EXTERN INTEGER __CALL_1 GetBrushOrgEx(INTEGER p0, WinAPI_POINT *p1);
#define WinAPI_GetCPInfo(CodePage, lpCPInfo, lpCPInfo__typ)	GetCPInfo(CodePage, lpCPInfo)
__EXTERN INTEGER __CALL_1 GetCPInfo(INTEGER CodePage, WinAPI_CPINFO *lpCPInfo);
#define WinAPI_GetCapture()	GetCapture()
__EXTERN INTEGER __CALL_1 GetCapture(void);
#define WinAPI_GetCaretBlinkTime()	GetCaretBlinkTime()
__EXTERN INTEGER __CALL_1 GetCaretBlinkTime(void);
#define WinAPI_GetCaretPos(lpPoint, lpPoint__typ)	GetCaretPos(lpPoint)
__EXTERN INTEGER __CALL_1 GetCaretPos(WinAPI_POINT *lpPoint);
#define WinAPI_GetCharABCWidths(p0, p1, p2, p3, p3__typ)	GetCharABCWidthsA(p0, p1, p2, p3)
#define WinAPI_GetCharABCWidthsA(p0, p1, p2, p3, p3__typ)	GetCharABCWidthsA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetCharABCWidthsA(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_ABC *p3);
#define WinAPI_GetCharABCWidthsFloat(p0, p1, p2, p3, p3__typ)	GetCharABCWidthsFloatA(p0, p1, p2, p3)
#define WinAPI_GetCharABCWidthsFloatA(p0, p1, p2, p3, p3__typ)	GetCharABCWidthsFloatA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetCharABCWidthsFloatA(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_ABCFLOAT *p3);
#define WinAPI_GetCharABCWidthsFloatW(p0, p1, p2, p3, p3__typ)	GetCharABCWidthsFloatW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetCharABCWidthsFloatW(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_ABCFLOAT *p3);
#define WinAPI_GetCharABCWidthsW(p0, p1, p2, p3, p3__typ)	GetCharABCWidthsW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetCharABCWidthsW(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_ABC *p3);
#define WinAPI_GetCharWidth(p0, p1, p2, p3)	GetCharWidthA(p0, p1, p2, p3)
#define WinAPI_GetCharWidth32(p0, p1, p2, p3)	GetCharWidth32A(p0, p1, p2, p3)
#define WinAPI_GetCharWidth32A(p0, p1, p2, p3)	GetCharWidth32A(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetCharWidth32A(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER *p3);
#define WinAPI_GetCharWidth32W(p0, p1, p2, p3)	GetCharWidth32W(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetCharWidth32W(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER *p3);
#define WinAPI_GetCharWidthA(p0, p1, p2, p3)	GetCharWidthA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetCharWidthA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER *p3);
#define WinAPI_GetCharWidthFloat(p0, p1, p2, p3)	GetCharWidthFloatA(p0, p1, p2, p3)
#define WinAPI_GetCharWidthFloatA(p0, p1, p2, p3)	GetCharWidthFloatA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetCharWidthFloatA(INTEGER p0, INTEGER p1, INTEGER p2, REAL *p3);
#define WinAPI_GetCharWidthFloatW(p0, p1, p2, p3)	GetCharWidthFloatW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetCharWidthFloatW(INTEGER p0, INTEGER p1, INTEGER p2, REAL *p3);
#define WinAPI_GetCharWidthW(p0, p1, p2, p3)	GetCharWidthW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetCharWidthW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER *p3);
#define WinAPI_GetCharacterPlacement(p0, p1, p2, p3, p4, p4__typ, p5)	GetCharacterPlacementA(p0, p1, p2, p3, p4, p5)
#define WinAPI_GetCharacterPlacementA(p0, p1, p2, p3, p4, p4__typ, p5)	GetCharacterPlacementA(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 GetCharacterPlacementA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_GCP_RESULTSA *p4, INTEGER p5);
#define WinAPI_GetCharacterPlacementW(p0, p1, p2, p3, p4, p4__typ, p5)	GetCharacterPlacementW(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 GetCharacterPlacementW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_GCP_RESULTSW *p4, INTEGER p5);
#define WinAPI_GetClassInfo(hInstance, lpClassName, lpWndClass, lpWndClass__typ)	GetClassInfoA(hInstance, lpClassName, lpWndClass)
#define WinAPI_GetClassInfoA(hInstance, lpClassName, lpWndClass, lpWndClass__typ)	GetClassInfoA(hInstance, lpClassName, lpWndClass)
__EXTERN INTEGER __CALL_1 GetClassInfoA(INTEGER hInstance, INTEGER lpClassName, WinAPI_WNDCLASSA *lpWndClass);
#define WinAPI_GetClassInfoEx(p0, p1, p2, p2__typ)	GetClassInfoExA(p0, p1, p2)
#define WinAPI_GetClassInfoExA(p0, p1, p2, p2__typ)	GetClassInfoExA(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetClassInfoExA(INTEGER p0, INTEGER p1, WinAPI_WNDCLASSEXA *p2);
#define WinAPI_GetClassInfoExW(p0, p1, p2, p2__typ)	GetClassInfoExW(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetClassInfoExW(INTEGER p0, INTEGER p1, WinAPI_WNDCLASSEXW *p2);
#define WinAPI_GetClassInfoW(hInstance, lpClassName, lpWndClass, lpWndClass__typ)	GetClassInfoW(hInstance, lpClassName, lpWndClass)
__EXTERN INTEGER __CALL_1 GetClassInfoW(INTEGER hInstance, INTEGER lpClassName, WinAPI_WNDCLASSW *lpWndClass);
#define WinAPI_GetClassLong(hWnd, nIndex)	GetClassLongA(hWnd, nIndex)
#define WinAPI_GetClassLongA(hWnd, nIndex)	GetClassLongA(hWnd, nIndex)
__EXTERN INTEGER __CALL_1 GetClassLongA(INTEGER hWnd, INTEGER nIndex);
#define WinAPI_GetClassLongW(hWnd, nIndex)	GetClassLongW(hWnd, nIndex)
__EXTERN INTEGER __CALL_1 GetClassLongW(INTEGER hWnd, INTEGER nIndex);
#define WinAPI_GetClassName(hWnd, lpClassName, nMaxCount)	GetClassNameA(hWnd, lpClassName, nMaxCount)
#define WinAPI_GetClassNameA(hWnd, lpClassName, nMaxCount)	GetClassNameA(hWnd, lpClassName, nMaxCount)
__EXTERN INTEGER __CALL_1 GetClassNameA(INTEGER hWnd, INTEGER lpClassName, INTEGER nMaxCount);
#define WinAPI_GetClassNameW(hWnd, lpClassName, nMaxCount)	GetClassNameW(hWnd, lpClassName, nMaxCount)
__EXTERN INTEGER __CALL_1 GetClassNameW(INTEGER hWnd, INTEGER lpClassName, INTEGER nMaxCount);
#define WinAPI_GetClassWord(hWnd, nIndex)	GetClassWord(hWnd, nIndex)
__EXTERN SHORTINT __CALL_1 GetClassWord(INTEGER hWnd, INTEGER nIndex);
#define WinAPI_GetClientRect(hWnd, lpRect, lpRect__typ)	GetClientRect(hWnd, lpRect)
__EXTERN INTEGER __CALL_1 GetClientRect(INTEGER hWnd, WinAPI_RECT *lpRect);
#define WinAPI_GetClipBox(p0, p1, p1__typ)	GetClipBox(p0, p1)
__EXTERN INTEGER __CALL_1 GetClipBox(INTEGER p0, WinAPI_RECT *p1);
#define WinAPI_GetClipCursor(lpRect, lpRect__typ)	GetClipCursor(lpRect)
__EXTERN INTEGER __CALL_1 GetClipCursor(WinAPI_RECT *lpRect);
#define WinAPI_GetClipRgn(p0, p1)	GetClipRgn(p0, p1)
__EXTERN INTEGER __CALL_1 GetClipRgn(INTEGER p0, INTEGER p1);
#define WinAPI_GetClipboardData(uFormat)	GetClipboardData(uFormat)
__EXTERN INTEGER __CALL_1 GetClipboardData(INTEGER uFormat);
#define WinAPI_GetClipboardFormatName(format, lpszFormatName, cchMaxCount)	GetClipboardFormatNameA(format, lpszFormatName, cchMaxCount)
#define WinAPI_GetClipboardFormatNameA(format, lpszFormatName, cchMaxCount)	GetClipboardFormatNameA(format, lpszFormatName, cchMaxCount)
__EXTERN INTEGER __CALL_1 GetClipboardFormatNameA(INTEGER format, INTEGER lpszFormatName, INTEGER cchMaxCount);
#define WinAPI_GetClipboardFormatNameW(format, lpszFormatName, cchMaxCount)	GetClipboardFormatNameW(format, lpszFormatName, cchMaxCount)
__EXTERN INTEGER __CALL_1 GetClipboardFormatNameW(INTEGER format, INTEGER lpszFormatName, INTEGER cchMaxCount);
#define WinAPI_GetClipboardOwner()	GetClipboardOwner()
__EXTERN INTEGER __CALL_1 GetClipboardOwner(void);
#define WinAPI_GetClipboardViewer()	GetClipboardViewer()
__EXTERN INTEGER __CALL_1 GetClipboardViewer(void);
#define WinAPI_GetColorAdjustment(p0, p1, p1__typ)	GetColorAdjustment(p0, p1)
__EXTERN INTEGER __CALL_1 GetColorAdjustment(INTEGER p0, WinAPI_COLORADJUSTMENT *p1);
#define WinAPI_GetColorSpace(p0)	GetColorSpace(p0)
__EXTERN INTEGER __CALL_1 GetColorSpace(INTEGER p0);
#define WinAPI_GetCommConfig(hCommDev, lpCC, lpCC__typ, lpdwSize)	GetCommConfig(hCommDev, lpCC, lpdwSize)
__EXTERN INTEGER __CALL_1 GetCommConfig(INTEGER hCommDev, WinAPI_COMMCONFIG *lpCC, INTEGER *lpdwSize);
#define WinAPI_GetCommMask(hFile, lpEvtMask)	GetCommMask(hFile, lpEvtMask)
__EXTERN INTEGER __CALL_1 GetCommMask(INTEGER hFile, SET *lpEvtMask);
#define WinAPI_GetCommModemStatus(hFile, lpModemStat)	GetCommModemStatus(hFile, lpModemStat)
__EXTERN INTEGER __CALL_1 GetCommModemStatus(INTEGER hFile, SET *lpModemStat);
#define WinAPI_GetCommProperties(hFile, lpCommProp, lpCommProp__typ)	GetCommProperties(hFile, lpCommProp)
__EXTERN INTEGER __CALL_1 GetCommProperties(INTEGER hFile, WinAPI_COMMPROP *lpCommProp);
#define WinAPI_GetCommState(hFile, lpDCB, lpDCB__typ)	GetCommState(hFile, lpDCB)
__EXTERN INTEGER __CALL_1 GetCommState(INTEGER hFile, WinAPI_DCB *lpDCB);
#define WinAPI_GetCommTimeouts(hFile, lpCommTimeouts, lpCommTimeouts__typ)	GetCommTimeouts(hFile, lpCommTimeouts)
__EXTERN INTEGER __CALL_1 GetCommTimeouts(INTEGER hFile, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
#define WinAPI_GetCommandLine()	GetCommandLineA()
#define WinAPI_GetCommandLineA()	GetCommandLineA()
__EXTERN INTEGER __CALL_1 GetCommandLineA(void);
#define WinAPI_GetCommandLineW()	GetCommandLineW()
__EXTERN INTEGER __CALL_1 GetCommandLineW(void);
#define WinAPI_GetCompressedFileSize(lpFileName, lpFileSizeHigh)	GetCompressedFileSizeA(lpFileName, lpFileSizeHigh)
#define WinAPI_GetCompressedFileSizeA(lpFileName, lpFileSizeHigh)	GetCompressedFileSizeA(lpFileName, lpFileSizeHigh)
__EXTERN INTEGER __CALL_1 GetCompressedFileSizeA(INTEGER lpFileName, INTEGER *lpFileSizeHigh);
#define WinAPI_GetCompressedFileSizeW(lpFileName, lpFileSizeHigh)	GetCompressedFileSizeW(lpFileName, lpFileSizeHigh)
__EXTERN INTEGER __CALL_1 GetCompressedFileSizeW(INTEGER lpFileName, INTEGER *lpFileSizeHigh);
#define WinAPI_GetComputerName(lpBuffer, nSize)	GetComputerNameA(lpBuffer, nSize)
#define WinAPI_GetComputerNameA(lpBuffer, nSize)	GetComputerNameA(lpBuffer, nSize)
__EXTERN INTEGER __CALL_1 GetComputerNameA(INTEGER lpBuffer, INTEGER *nSize);
#define WinAPI_GetComputerNameW(lpBuffer, nSize)	GetComputerNameW(lpBuffer, nSize)
__EXTERN INTEGER __CALL_1 GetComputerNameW(INTEGER lpBuffer, INTEGER *nSize);
#define WinAPI_GetConsoleCP()	GetConsoleCP()
__EXTERN INTEGER __CALL_1 GetConsoleCP(void);
#define WinAPI_GetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo, lpConsoleCursorInfo__typ)	GetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo)
__EXTERN INTEGER __CALL_1 GetConsoleCursorInfo(INTEGER hConsoleOutput, WinAPI_CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
#define WinAPI_GetConsoleMode(hConsoleHandle, lpMode)	GetConsoleMode(hConsoleHandle, lpMode)
__EXTERN INTEGER __CALL_1 GetConsoleMode(INTEGER hConsoleHandle, SET *lpMode);
#define WinAPI_GetConsoleOutputCP()	GetConsoleOutputCP()
__EXTERN INTEGER __CALL_1 GetConsoleOutputCP(void);
#define WinAPI_GetConsoleScreenBufferInfo(hConsoleOutput, lpConsoleScreenBufferInfo, lpConsoleScreenBufferInfo__typ)	GetConsoleScreenBufferInfo(hConsoleOutput, lpConsoleScreenBufferInfo)
__EXTERN INTEGER __CALL_1 GetConsoleScreenBufferInfo(INTEGER hConsoleOutput, WinAPI_CONSOLE_SCREEN_BUFFER_INFO *lpConsoleScreenBufferInfo);
#define WinAPI_GetConsoleTitle(lpConsoleTitle, nSize)	GetConsoleTitleA(lpConsoleTitle, nSize)
#define WinAPI_GetConsoleTitleA(lpConsoleTitle, nSize)	GetConsoleTitleA(lpConsoleTitle, nSize)
__EXTERN INTEGER __CALL_1 GetConsoleTitleA(INTEGER lpConsoleTitle, INTEGER nSize);
#define WinAPI_GetConsoleTitleW(lpConsoleTitle, nSize)	GetConsoleTitleW(lpConsoleTitle, nSize)
__EXTERN INTEGER __CALL_1 GetConsoleTitleW(INTEGER lpConsoleTitle, INTEGER nSize);
#define WinAPI_GetCurrencyFormat(Locale, dwFlags, lpValue, lpFormat, lpFormat__typ, lpCurrencyStr, cchCurrency)	GetCurrencyFormatA(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)
#define WinAPI_GetCurrencyFormatA(Locale, dwFlags, lpValue, lpFormat, lpFormat__typ, lpCurrencyStr, cchCurrency)	GetCurrencyFormatA(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)
__EXTERN INTEGER __CALL_1 GetCurrencyFormatA(INTEGER Locale, SET dwFlags, INTEGER lpValue, WinAPI_CURRENCYFMTA *lpFormat, INTEGER lpCurrencyStr, INTEGER cchCurrency);
#define WinAPI_GetCurrencyFormatW(Locale, dwFlags, lpValue, lpFormat, lpFormat__typ, lpCurrencyStr, cchCurrency)	GetCurrencyFormatW(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency)
__EXTERN INTEGER __CALL_1 GetCurrencyFormatW(INTEGER Locale, SET dwFlags, INTEGER lpValue, WinAPI_CURRENCYFMTW *lpFormat, INTEGER lpCurrencyStr, INTEGER cchCurrency);
#define WinAPI_GetCurrentDirectory(nBufferLength, lpBuffer)	GetCurrentDirectoryA(nBufferLength, lpBuffer)
#define WinAPI_GetCurrentDirectoryA(nBufferLength, lpBuffer)	GetCurrentDirectoryA(nBufferLength, lpBuffer)
__EXTERN INTEGER __CALL_1 GetCurrentDirectoryA(INTEGER nBufferLength, INTEGER lpBuffer);
#define WinAPI_GetCurrentDirectoryW(nBufferLength, lpBuffer)	GetCurrentDirectoryW(nBufferLength, lpBuffer)
__EXTERN INTEGER __CALL_1 GetCurrentDirectoryW(INTEGER nBufferLength, INTEGER lpBuffer);
#define WinAPI_GetCurrentHwProfile(lpHwProfileInfo, lpHwProfileInfo__typ)	GetCurrentHwProfileA(lpHwProfileInfo)
#define WinAPI_GetCurrentHwProfileA(lpHwProfileInfo, lpHwProfileInfo__typ)	GetCurrentHwProfileA(lpHwProfileInfo)
__EXTERN INTEGER __CALL_1 GetCurrentHwProfileA(WinAPI_HW_PROFILE_INFOA *lpHwProfileInfo);
#define WinAPI_GetCurrentHwProfileW(lpHwProfileInfo, lpHwProfileInfo__typ)	GetCurrentHwProfileW(lpHwProfileInfo)
__EXTERN INTEGER __CALL_1 GetCurrentHwProfileW(WinAPI_HW_PROFILE_INFOW *lpHwProfileInfo);
#define WinAPI_GetCurrentObject(p0, p1)	GetCurrentObject(p0, p1)
__EXTERN INTEGER __CALL_1 GetCurrentObject(INTEGER p0, INTEGER p1);
#define WinAPI_GetCurrentPositionEx(p0, p1, p1__typ)	GetCurrentPositionEx(p0, p1)
__EXTERN INTEGER __CALL_1 GetCurrentPositionEx(INTEGER p0, WinAPI_POINT *p1);
#define WinAPI_GetCurrentProcess()	GetCurrentProcess()
__EXTERN INTEGER __CALL_1 GetCurrentProcess(void);
#define WinAPI_GetCurrentProcessId()	GetCurrentProcessId()
__EXTERN INTEGER __CALL_1 GetCurrentProcessId(void);
#define WinAPI_GetCurrentThread()	GetCurrentThread()
__EXTERN INTEGER __CALL_1 GetCurrentThread(void);
#define WinAPI_GetCurrentThreadId()	GetCurrentThreadId()
__EXTERN INTEGER __CALL_1 GetCurrentThreadId(void);
#define WinAPI_GetCursor()	GetCursor()
__EXTERN INTEGER __CALL_1 GetCursor(void);
#define WinAPI_GetCursorPos(lpPoint, lpPoint__typ)	GetCursorPos(lpPoint)
__EXTERN INTEGER __CALL_1 GetCursorPos(WinAPI_POINT *lpPoint);
#define WinAPI_GetDC(hWnd)	GetDC(hWnd)
__EXTERN INTEGER __CALL_1 GetDC(INTEGER hWnd);
#define WinAPI_GetDCEx(hWnd, hrgnClip, flags)	GetDCEx(hWnd, hrgnClip, flags)
__EXTERN INTEGER __CALL_1 GetDCEx(INTEGER hWnd, INTEGER hrgnClip, SET flags);
#define WinAPI_GetDCOrgEx(p0, p1, p1__typ)	GetDCOrgEx(p0, p1)
__EXTERN INTEGER __CALL_1 GetDCOrgEx(INTEGER p0, WinAPI_POINT *p1);
#define WinAPI_GetDIBColorTable(p0, p1, p2, p3, p3__typ)	GetDIBColorTable(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetDIBColorTable(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_RGBQUAD *p3);
#define WinAPI_GetDIBits(p0, p1, p2, p3, p4, p5, p5__typ, p6)	GetDIBits(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL_1 GetDIBits(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_BITMAPINFO *p5, INTEGER p6);
#define WinAPI_GetDateFormat(Locale, dwFlags, lpDate, lpDate__typ, lpFormat, lpDateStr, cchDate)	GetDateFormatA(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)
#define WinAPI_GetDateFormatA(Locale, dwFlags, lpDate, lpDate__typ, lpFormat, lpDateStr, cchDate)	GetDateFormatA(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)
__EXTERN INTEGER __CALL_1 GetDateFormatA(INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpDate, INTEGER lpFormat, INTEGER lpDateStr, INTEGER cchDate);
#define WinAPI_GetDateFormatW(Locale, dwFlags, lpDate, lpDate__typ, lpFormat, lpDateStr, cchDate)	GetDateFormatW(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate)
__EXTERN INTEGER __CALL_1 GetDateFormatW(INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpDate, INTEGER lpFormat, INTEGER lpDateStr, INTEGER cchDate);
#define WinAPI_GetDefaultCommConfig(lpszName, lpCC, lpCC__typ, lpdwSize)	GetDefaultCommConfigA(lpszName, lpCC, lpdwSize)
#define WinAPI_GetDefaultCommConfigA(lpszName, lpCC, lpCC__typ, lpdwSize)	GetDefaultCommConfigA(lpszName, lpCC, lpdwSize)
__EXTERN INTEGER __CALL_1 GetDefaultCommConfigA(INTEGER lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER *lpdwSize);
#define WinAPI_GetDefaultCommConfigW(lpszName, lpCC, lpCC__typ, lpdwSize)	GetDefaultCommConfigW(lpszName, lpCC, lpdwSize)
__EXTERN INTEGER __CALL_1 GetDefaultCommConfigW(INTEGER lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER *lpdwSize);
#define WinAPI_GetDesktopWindow()	GetDesktopWindow()
__EXTERN INTEGER __CALL_1 GetDesktopWindow(void);
#define WinAPI_GetDeviceCaps(p0, p1)	GetDeviceCaps(p0, p1)
__EXTERN INTEGER __CALL_1 GetDeviceCaps(INTEGER p0, INTEGER p1);
#define WinAPI_GetDeviceGammaRamp(p0, p1)	GetDeviceGammaRamp(p0, p1)
__EXTERN INTEGER __CALL_1 GetDeviceGammaRamp(INTEGER p0, INTEGER p1);
#define WinAPI_GetDialogBaseUnits()	GetDialogBaseUnits()
__EXTERN INTEGER __CALL_1 GetDialogBaseUnits(void);
#define WinAPI_GetDiskFreeSpace(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)	GetDiskFreeSpaceA(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)
#define WinAPI_GetDiskFreeSpaceA(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)	GetDiskFreeSpaceA(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)
__EXTERN INTEGER __CALL_1 GetDiskFreeSpaceA(INTEGER lpRootPathName, INTEGER *lpSectorsPerCluster, INTEGER *lpBytesPerSector, INTEGER *lpNumberOfFreeClusters, INTEGER *lpTotalNumberOfClusters);
#define WinAPI_GetDiskFreeSpaceW(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)	GetDiskFreeSpaceW(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters)
__EXTERN INTEGER __CALL_1 GetDiskFreeSpaceW(INTEGER lpRootPathName, INTEGER *lpSectorsPerCluster, INTEGER *lpBytesPerSector, INTEGER *lpNumberOfFreeClusters, INTEGER *lpTotalNumberOfClusters);
#define WinAPI_GetDlgCtrlID(hWnd)	GetDlgCtrlID(hWnd)
__EXTERN INTEGER __CALL_1 GetDlgCtrlID(INTEGER hWnd);
#define WinAPI_GetDlgItem(hDlg, nIDDlgItem)	GetDlgItem(hDlg, nIDDlgItem)
__EXTERN INTEGER __CALL_1 GetDlgItem(INTEGER hDlg, INTEGER nIDDlgItem);
#define WinAPI_GetDlgItemInt(hDlg, nIDDlgItem, lpTranslated, bSigned)	GetDlgItemInt(hDlg, nIDDlgItem, lpTranslated, bSigned)
__EXTERN INTEGER __CALL_1 GetDlgItemInt(INTEGER hDlg, INTEGER nIDDlgItem, INTEGER *lpTranslated, INTEGER bSigned);
#define WinAPI_GetDlgItemText(hDlg, nIDDlgItem, lpString, nMaxCount)	GetDlgItemTextA(hDlg, nIDDlgItem, lpString, nMaxCount)
#define WinAPI_GetDlgItemTextA(hDlg, nIDDlgItem, lpString, nMaxCount)	GetDlgItemTextA(hDlg, nIDDlgItem, lpString, nMaxCount)
__EXTERN INTEGER __CALL_1 GetDlgItemTextA(INTEGER hDlg, INTEGER nIDDlgItem, INTEGER lpString, INTEGER nMaxCount);
#define WinAPI_GetDlgItemTextW(hDlg, nIDDlgItem, lpString, nMaxCount)	GetDlgItemTextW(hDlg, nIDDlgItem, lpString, nMaxCount)
__EXTERN INTEGER __CALL_1 GetDlgItemTextW(INTEGER hDlg, INTEGER nIDDlgItem, INTEGER lpString, INTEGER nMaxCount);
#define WinAPI_GetDoubleClickTime()	GetDoubleClickTime()
__EXTERN INTEGER __CALL_1 GetDoubleClickTime(void);
#define WinAPI_GetDriveType(lpRootPathName)	GetDriveTypeA(lpRootPathName)
#define WinAPI_GetDriveTypeA(lpRootPathName)	GetDriveTypeA(lpRootPathName)
__EXTERN INTEGER __CALL_1 GetDriveTypeA(INTEGER lpRootPathName);
#define WinAPI_GetDriveTypeW(lpRootPathName)	GetDriveTypeW(lpRootPathName)
__EXTERN INTEGER __CALL_1 GetDriveTypeW(INTEGER lpRootPathName);
#define WinAPI_GetEnhMetaFile(p0)	GetEnhMetaFileA(p0)
#define WinAPI_GetEnhMetaFileA(p0)	GetEnhMetaFileA(p0)
__EXTERN INTEGER __CALL_1 GetEnhMetaFileA(INTEGER p0);
#define WinAPI_GetEnhMetaFileBits(p0, p1, p2)	GetEnhMetaFileBits(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetEnhMetaFileBits(INTEGER p0, INTEGER p1, CHAR *p2);
#define WinAPI_GetEnhMetaFileDescription(p0, p1, p2)	GetEnhMetaFileDescriptionA(p0, p1, p2)
#define WinAPI_GetEnhMetaFileDescriptionA(p0, p1, p2)	GetEnhMetaFileDescriptionA(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetEnhMetaFileDescriptionA(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_GetEnhMetaFileDescriptionW(p0, p1, p2)	GetEnhMetaFileDescriptionW(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetEnhMetaFileDescriptionW(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_GetEnhMetaFileHeader(p0, p1, p2, p2__typ)	GetEnhMetaFileHeader(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetEnhMetaFileHeader(INTEGER p0, INTEGER p1, WinAPI_ENHMETAHEADER *p2);
#define WinAPI_GetEnhMetaFilePaletteEntries(p0, p1, p2, p2__typ)	GetEnhMetaFilePaletteEntries(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetEnhMetaFilePaletteEntries(INTEGER p0, INTEGER p1, WinAPI_PALETTEENTRY *p2);
#define WinAPI_GetEnhMetaFilePixelFormat(p0, p1, p2, p2__typ)	GetEnhMetaFilePixelFormat(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetEnhMetaFilePixelFormat(INTEGER p0, INTEGER p1, WinAPI_PIXELFORMATDESCRIPTOR *p2);
#define WinAPI_GetEnhMetaFileW(p0)	GetEnhMetaFileW(p0)
__EXTERN INTEGER __CALL_1 GetEnhMetaFileW(INTEGER p0);
#define WinAPI_GetEnvironmentStrings()	GetEnvironmentStrings()
__EXTERN INTEGER __CALL_1 GetEnvironmentStrings(void);
#define WinAPI_GetEnvironmentStringsA()	GetEnvironmentStrings()
#define WinAPI_GetEnvironmentStringsW()	GetEnvironmentStringsW()
__EXTERN INTEGER __CALL_1 GetEnvironmentStringsW(void);
#define WinAPI_GetEnvironmentVariable(lpName, lpBuffer, nSize)	GetEnvironmentVariableA(lpName, lpBuffer, nSize)
#define WinAPI_GetEnvironmentVariableA(lpName, lpBuffer, nSize)	GetEnvironmentVariableA(lpName, lpBuffer, nSize)
__EXTERN INTEGER __CALL_1 GetEnvironmentVariableA(INTEGER lpName, INTEGER lpBuffer, INTEGER nSize);
#define WinAPI_GetEnvironmentVariableW(lpName, lpBuffer, nSize)	GetEnvironmentVariableW(lpName, lpBuffer, nSize)
__EXTERN INTEGER __CALL_1 GetEnvironmentVariableW(INTEGER lpName, INTEGER lpBuffer, INTEGER nSize);
#define WinAPI_GetExitCodeProcess(hProcess, lpExitCode)	GetExitCodeProcess(hProcess, lpExitCode)
__EXTERN INTEGER __CALL_1 GetExitCodeProcess(INTEGER hProcess, INTEGER *lpExitCode);
#define WinAPI_GetExitCodeThread(hThread, lpExitCode)	GetExitCodeThread(hThread, lpExitCode)
__EXTERN INTEGER __CALL_1 GetExitCodeThread(INTEGER hThread, INTEGER *lpExitCode);
#define WinAPI_GetExpandedName(p0, p1)	GetExpandedNameA(p0, p1)
#define WinAPI_GetExpandedNameA(p0, p1)	GetExpandedNameA(p0, p1)
__EXTERN INTEGER __CALL_1 GetExpandedNameA(INTEGER p0, INTEGER p1);
#define WinAPI_GetExpandedNameW(p0, p1)	GetExpandedNameW(p0, p1)
__EXTERN INTEGER __CALL_1 GetExpandedNameW(INTEGER p0, INTEGER p1);
#define WinAPI_GetFileAttributes(lpFileName)	GetFileAttributesA(lpFileName)
#define WinAPI_GetFileAttributesA(lpFileName)	GetFileAttributesA(lpFileName)
__EXTERN INTEGER __CALL_1 GetFileAttributesA(INTEGER lpFileName);
#define WinAPI_GetFileAttributesW(lpFileName)	GetFileAttributesW(lpFileName)
__EXTERN INTEGER __CALL_1 GetFileAttributesW(INTEGER lpFileName);
#define WinAPI_GetFileInformationByHandle(hFile, lpFileInformation, lpFileInformation__typ)	GetFileInformationByHandle(hFile, lpFileInformation)
__EXTERN INTEGER __CALL_1 GetFileInformationByHandle(INTEGER hFile, WinAPI_BY_HANDLE_FILE_INFORMATION *lpFileInformation);
#define WinAPI_GetFileSecurity(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)	GetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)
#define WinAPI_GetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)	GetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)
__EXTERN INTEGER __CALL_1 GetFileSecurityA(INTEGER lpFileName, SET RequestedInformation, INTEGER pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinAPI_GetFileSecurityW(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)	GetFileSecurityW(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)
__EXTERN INTEGER __CALL_1 GetFileSecurityW(INTEGER lpFileName, SET RequestedInformation, INTEGER pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinAPI_GetFileSize(hFile, lpFileSizeHigh)	GetFileSize(hFile, lpFileSizeHigh)
__EXTERN INTEGER __CALL_1 GetFileSize(INTEGER hFile, INTEGER *lpFileSizeHigh);
#define WinAPI_GetFileSizeEx(hFile, lpFileSizeHigh)	GetFileSizeEx(hFile, lpFileSizeHigh)
__EXTERN INTEGER __CALL_1 GetFileSizeEx(INTEGER hFile, LONGINT *lpFileSizeHigh);
#define WinAPI_GetFileTime(hFile, lpCreationTime, lpCreationTime__typ, lpLastAccessTime, lpLastAccessTime__typ, lpLastWriteTime, lpLastWriteTime__typ)	GetFileTime(hFile, lpCreationTime, lpLastAccessTime, lpLastWriteTime)
__EXTERN INTEGER __CALL_1 GetFileTime(INTEGER hFile, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpLastAccessTime, WinAPI_FILETIME *lpLastWriteTime);
#define WinAPI_GetFileType(hFile)	GetFileType(hFile)
__EXTERN INTEGER __CALL_1 GetFileType(INTEGER hFile);
#define WinAPI_GetFileVersionInfo(lptstrFilename, dwHandle, dwLen, lpData)	GetFileVersionInfoA(lptstrFilename, dwHandle, dwLen, lpData)
#define WinAPI_GetFileVersionInfoA(lptstrFilename, dwHandle, dwLen, lpData)	GetFileVersionInfoA(lptstrFilename, dwHandle, dwLen, lpData)
__EXTERN INTEGER __CALL_1 GetFileVersionInfoA(INTEGER lptstrFilename, INTEGER dwHandle, INTEGER dwLen, INTEGER lpData);
#define WinAPI_GetFileVersionInfoSize(lptstrFilename, lpdwHandle)	GetFileVersionInfoSizeA(lptstrFilename, lpdwHandle)
#define WinAPI_GetFileVersionInfoSizeA(lptstrFilename, lpdwHandle)	GetFileVersionInfoSizeA(lptstrFilename, lpdwHandle)
__EXTERN INTEGER __CALL_1 GetFileVersionInfoSizeA(INTEGER lptstrFilename, INTEGER *lpdwHandle);
#define WinAPI_GetFileVersionInfoSizeW(lptstrFilename, lpdwHandle)	GetFileVersionInfoSizeW(lptstrFilename, lpdwHandle)
__EXTERN INTEGER __CALL_1 GetFileVersionInfoSizeW(INTEGER lptstrFilename, INTEGER *lpdwHandle);
#define WinAPI_GetFileVersionInfoW(lptstrFilename, dwHandle, dwLen, lpData)	GetFileVersionInfoW(lptstrFilename, dwHandle, dwLen, lpData)
__EXTERN INTEGER __CALL_1 GetFileVersionInfoW(INTEGER lptstrFilename, INTEGER dwHandle, INTEGER dwLen, INTEGER lpData);
#define WinAPI_GetFocus()	GetFocus()
__EXTERN INTEGER __CALL_1 GetFocus(void);
#define WinAPI_GetFontData(p0, p1, p2, p3, p4)	GetFontData(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 GetFontData(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_GetFontLanguageInfo(p0)	GetFontLanguageInfo(p0)
__EXTERN SET __CALL_1 GetFontLanguageInfo(INTEGER p0);
#define WinAPI_GetForegroundWindow()	GetForegroundWindow()
__EXTERN INTEGER __CALL_1 GetForegroundWindow(void);
#define WinAPI_GetForm(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)	GetFormA(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)
#define WinAPI_GetFormA(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)	GetFormA(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetFormA(INTEGER hPrinter, INTEGER pFormName, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetFormW(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)	GetFormW(hPrinter, pFormName, Level, pForm, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetFormW(INTEGER hPrinter, INTEGER pFormName, INTEGER Level, CHAR *pForm, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetFullPathName(lpFileName, nBufferLength, lpBuffer, lpFilePart)	GetFullPathNameA(lpFileName, nBufferLength, lpBuffer, lpFilePart)
#define WinAPI_GetFullPathNameA(lpFileName, nBufferLength, lpBuffer, lpFilePart)	GetFullPathNameA(lpFileName, nBufferLength, lpBuffer, lpFilePart)
__EXTERN INTEGER __CALL_1 GetFullPathNameA(INTEGER lpFileName, INTEGER nBufferLength, INTEGER lpBuffer, INTEGER *lpFilePart);
#define WinAPI_GetFullPathNameW(lpFileName, nBufferLength, lpBuffer, lpFilePart)	GetFullPathNameW(lpFileName, nBufferLength, lpBuffer, lpFilePart)
__EXTERN INTEGER __CALL_1 GetFullPathNameW(INTEGER lpFileName, INTEGER nBufferLength, INTEGER lpBuffer, INTEGER *lpFilePart);
#define WinAPI_GetGlyphOutline(p0, p1, p2, p3, p3__typ, p4, p5, p6, p6__typ)	GetGlyphOutlineA(p0, p1, p2, p3, p4, p5, p6)
#define WinAPI_GetGlyphOutlineA(p0, p1, p2, p3, p3__typ, p4, p5, p6, p6__typ)	GetGlyphOutlineA(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL_1 GetGlyphOutlineA(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_GLYPHMETRICS *p3, INTEGER p4, INTEGER p5, WinAPI_MAT2 *p6);
#define WinAPI_GetGlyphOutlineW(p0, p1, p2, p3, p3__typ, p4, p5, p6, p6__typ)	GetGlyphOutlineW(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL_1 GetGlyphOutlineW(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_GLYPHMETRICS *p3, INTEGER p4, INTEGER p5, WinAPI_MAT2 *p6);
#define WinAPI_GetGraphicsMode(p0)	GetGraphicsMode(p0)
__EXTERN INTEGER __CALL_1 GetGraphicsMode(INTEGER p0);
#define WinAPI_GetHandleInformation(hObject, lpdwFlags)	GetHandleInformation(hObject, lpdwFlags)
__EXTERN INTEGER __CALL_1 GetHandleInformation(INTEGER hObject, SET *lpdwFlags);
#define WinAPI_GetICMProfile(p0, p1, p2)	GetICMProfileA(p0, p1, p2)
#define WinAPI_GetICMProfileA(p0, p1, p2)	GetICMProfileA(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetICMProfileA(INTEGER p0, INTEGER *p1, INTEGER p2);
#define WinAPI_GetICMProfileW(p0, p1, p2)	GetICMProfileW(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetICMProfileW(INTEGER p0, INTEGER *p1, INTEGER p2);
#define WinAPI_GetIconInfo(hIcon, piconinfo, piconinfo__typ)	GetIconInfo(hIcon, piconinfo)
__EXTERN INTEGER __CALL_1 GetIconInfo(INTEGER hIcon, WinAPI_ICONINFO *piconinfo);
#define WinAPI_GetInputState()	GetInputState()
__EXTERN INTEGER __CALL_1 GetInputState(void);
#define WinAPI_GetJob(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)	GetJobA(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)
#define WinAPI_GetJobA(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)	GetJobA(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetJobA(INTEGER hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetJobW(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)	GetJobW(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetJobW(INTEGER hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetKBCodePage()	GetKBCodePage()
__EXTERN INTEGER __CALL_1 GetKBCodePage(void);
#define WinAPI_GetKernelObjectSecurity(Handle, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)	GetKernelObjectSecurity(Handle, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded)
__EXTERN INTEGER __CALL_1 GetKernelObjectSecurity(INTEGER Handle, SET RequestedInformation, INTEGER pSecurityDescriptor, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinAPI_GetKerningPairs(p0, p1, p2, p2__typ)	GetKerningPairsA(p0, p1, p2)
#define WinAPI_GetKerningPairsA(p0, p1, p2, p2__typ)	GetKerningPairsA(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetKerningPairsA(INTEGER p0, INTEGER p1, WinAPI_KERNINGPAIR *p2);
#define WinAPI_GetKerningPairsW(p0, p1, p2, p2__typ)	GetKerningPairsW(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetKerningPairsW(INTEGER p0, INTEGER p1, WinAPI_KERNINGPAIR *p2);
#define WinAPI_GetKeyNameText(lParam, lpString, nSize)	GetKeyNameTextA(lParam, lpString, nSize)
#define WinAPI_GetKeyNameTextA(lParam, lpString, nSize)	GetKeyNameTextA(lParam, lpString, nSize)
__EXTERN INTEGER __CALL_1 GetKeyNameTextA(INTEGER lParam, INTEGER lpString, INTEGER nSize);
#define WinAPI_GetKeyNameTextW(lParam, lpString, nSize)	GetKeyNameTextW(lParam, lpString, nSize)
__EXTERN INTEGER __CALL_1 GetKeyNameTextW(INTEGER lParam, INTEGER lpString, INTEGER nSize);
#define WinAPI_GetKeyState(nVirtKey)	GetKeyState(nVirtKey)
__EXTERN SHORTINT __CALL_1 GetKeyState(INTEGER nVirtKey);
#define WinAPI_GetKeyboardLayout(dwLayout)	GetKeyboardLayout(dwLayout)
__EXTERN INTEGER __CALL_1 GetKeyboardLayout(INTEGER dwLayout);
#define WinAPI_GetKeyboardLayoutList(nBuff, lpList)	GetKeyboardLayoutList(nBuff, lpList)
__EXTERN INTEGER __CALL_1 GetKeyboardLayoutList(INTEGER nBuff, INTEGER *lpList);
#define WinAPI_GetKeyboardLayoutName(pwszKLID)	GetKeyboardLayoutNameA(pwszKLID)
#define WinAPI_GetKeyboardLayoutNameA(pwszKLID)	GetKeyboardLayoutNameA(pwszKLID)
__EXTERN INTEGER __CALL_1 GetKeyboardLayoutNameA(INTEGER pwszKLID);
#define WinAPI_GetKeyboardLayoutNameW(pwszKLID)	GetKeyboardLayoutNameW(pwszKLID)
__EXTERN INTEGER __CALL_1 GetKeyboardLayoutNameW(INTEGER pwszKLID);
#define WinAPI_GetKeyboardState(lpKeyState)	GetKeyboardState(lpKeyState)
__EXTERN INTEGER __CALL_1 GetKeyboardState(CHAR *lpKeyState);
#define WinAPI_GetKeyboardType(nTypeFlag)	GetKeyboardType(nTypeFlag)
__EXTERN INTEGER __CALL_1 GetKeyboardType(INTEGER nTypeFlag);
#define WinAPI_GetLargestConsoleWindowSize(hConsoleOutput)	GetLargestConsoleWindowSize(hConsoleOutput)
__EXTERN INTEGER __CALL_1 GetLargestConsoleWindowSize(INTEGER hConsoleOutput);
#define WinAPI_GetLastActivePopup(hWnd)	GetLastActivePopup(hWnd)
__EXTERN INTEGER __CALL_1 GetLastActivePopup(INTEGER hWnd);
#define WinAPI_GetLastError()	GetLastError()
__EXTERN INTEGER __CALL_1 GetLastError(void);
#define WinAPI_GetLengthSid(pSid)	GetLengthSid(pSid)
__EXTERN INTEGER __CALL_1 GetLengthSid(INTEGER pSid);
#define WinAPI_GetLocalTime(lpSystemTime, lpSystemTime__typ)	GetLocalTime(lpSystemTime)
__EXTERN void __CALL_1 GetLocalTime(WinAPI_SYSTEMTIME *lpSystemTime);
#define WinAPI_GetLocaleInfo(Locale, LCType, lpLCData, cchData)	GetLocaleInfoA(Locale, LCType, lpLCData, cchData)
#define WinAPI_GetLocaleInfoA(Locale, LCType, lpLCData, cchData)	GetLocaleInfoA(Locale, LCType, lpLCData, cchData)
__EXTERN INTEGER __CALL_1 GetLocaleInfoA(INTEGER Locale, INTEGER LCType, INTEGER lpLCData, INTEGER cchData);
#define WinAPI_GetLocaleInfoW(Locale, LCType, lpLCData, cchData)	GetLocaleInfoW(Locale, LCType, lpLCData, cchData)
__EXTERN INTEGER __CALL_1 GetLocaleInfoW(INTEGER Locale, INTEGER LCType, INTEGER lpLCData, INTEGER cchData);
#define WinAPI_GetLogColorSpace(p0, p1, p1__typ, p2)	GetLogColorSpaceA(p0, p1, p2)
#define WinAPI_GetLogColorSpaceA(p0, p1, p1__typ, p2)	GetLogColorSpaceA(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetLogColorSpaceA(INTEGER p0, WinAPI_LOGCOLORSPACEA *p1, INTEGER p2);
#define WinAPI_GetLogColorSpaceW(p0, p1, p1__typ, p2)	GetLogColorSpaceW(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetLogColorSpaceW(INTEGER p0, WinAPI_LOGCOLORSPACEW *p1, INTEGER p2);
#define WinAPI_GetLogicalDriveStrings(nBufferLength, lpBuffer)	GetLogicalDriveStringsA(nBufferLength, lpBuffer)
#define WinAPI_GetLogicalDriveStringsA(nBufferLength, lpBuffer)	GetLogicalDriveStringsA(nBufferLength, lpBuffer)
__EXTERN INTEGER __CALL_1 GetLogicalDriveStringsA(INTEGER nBufferLength, INTEGER lpBuffer);
#define WinAPI_GetLogicalDriveStringsW(nBufferLength, lpBuffer)	GetLogicalDriveStringsW(nBufferLength, lpBuffer)
__EXTERN INTEGER __CALL_1 GetLogicalDriveStringsW(INTEGER nBufferLength, INTEGER lpBuffer);
#define WinAPI_GetLogicalDrives()	GetLogicalDrives()
__EXTERN INTEGER __CALL_1 GetLogicalDrives(void);
#define WinAPI_GetMailslotInfo(hMailslot, lpMaxMessageSize, lpNextSize, lpMessageCount, lpReadTimeout)	GetMailslotInfo(hMailslot, lpMaxMessageSize, lpNextSize, lpMessageCount, lpReadTimeout)
__EXTERN INTEGER __CALL_1 GetMailslotInfo(INTEGER hMailslot, INTEGER *lpMaxMessageSize, INTEGER *lpNextSize, INTEGER *lpMessageCount, INTEGER *lpReadTimeout);
#define WinAPI_GetMapMode(p0)	GetMapMode(p0)
__EXTERN INTEGER __CALL_1 GetMapMode(INTEGER p0);
#define WinAPI_GetMenu(hWnd)	GetMenu(hWnd)
__EXTERN INTEGER __CALL_1 GetMenu(INTEGER hWnd);
#define WinAPI_GetMenuCheckMarkDimensions()	GetMenuCheckMarkDimensions()
__EXTERN INTEGER __CALL_1 GetMenuCheckMarkDimensions(void);
#define WinAPI_GetMenuContextHelpId(p0)	GetMenuContextHelpId(p0)
__EXTERN INTEGER __CALL_1 GetMenuContextHelpId(INTEGER p0);
#define WinAPI_GetMenuDefaultItem(hMenu, fByPos, gmdiFlags)	GetMenuDefaultItem(hMenu, fByPos, gmdiFlags)
__EXTERN INTEGER __CALL_1 GetMenuDefaultItem(INTEGER hMenu, INTEGER fByPos, SET gmdiFlags);
#define WinAPI_GetMenuItemCount(hMenu)	GetMenuItemCount(hMenu)
__EXTERN INTEGER __CALL_1 GetMenuItemCount(INTEGER hMenu);
#define WinAPI_GetMenuItemID(hMenu, nPos)	GetMenuItemID(hMenu, nPos)
__EXTERN INTEGER __CALL_1 GetMenuItemID(INTEGER hMenu, INTEGER nPos);
#define WinAPI_GetMenuItemInfo(p0, p1, p2, p3, p3__typ)	GetMenuItemInfoA(p0, p1, p2, p3)
#define WinAPI_GetMenuItemInfoA(p0, p1, p2, p3, p3__typ)	GetMenuItemInfoA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetMenuItemInfoA(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOA *p3);
#define WinAPI_GetMenuItemInfoW(p0, p1, p2, p3, p3__typ)	GetMenuItemInfoW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetMenuItemInfoW(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOW *p3);
#define WinAPI_GetMenuItemRect(hWnd, hMenu, uItem, lprcItem, lprcItem__typ)	GetMenuItemRect(hWnd, hMenu, uItem, lprcItem)
__EXTERN INTEGER __CALL_1 GetMenuItemRect(INTEGER hWnd, INTEGER hMenu, INTEGER uItem, WinAPI_RECT *lprcItem);
#define WinAPI_GetMenuState(hMenu, uId, uFlags)	GetMenuState(hMenu, uId, uFlags)
__EXTERN INTEGER __CALL_1 GetMenuState(INTEGER hMenu, INTEGER uId, SET uFlags);
#define WinAPI_GetMenuString(hMenu, uIDItem, lpString, nMaxCount, uFlag)	GetMenuStringA(hMenu, uIDItem, lpString, nMaxCount, uFlag)
#define WinAPI_GetMenuStringA(hMenu, uIDItem, lpString, nMaxCount, uFlag)	GetMenuStringA(hMenu, uIDItem, lpString, nMaxCount, uFlag)
__EXTERN INTEGER __CALL_1 GetMenuStringA(INTEGER hMenu, INTEGER uIDItem, INTEGER lpString, INTEGER nMaxCount, SET uFlag);
#define WinAPI_GetMenuStringW(hMenu, uIDItem, lpString, nMaxCount, uFlag)	GetMenuStringW(hMenu, uIDItem, lpString, nMaxCount, uFlag)
__EXTERN INTEGER __CALL_1 GetMenuStringW(INTEGER hMenu, INTEGER uIDItem, INTEGER lpString, INTEGER nMaxCount, SET uFlag);
#define WinAPI_GetMessage(lpMsg, lpMsg__typ, hWnd, wMsgFilterMin, wMsgFilterMax)	GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)
#define WinAPI_GetMessageA(lpMsg, lpMsg__typ, hWnd, wMsgFilterMin, wMsgFilterMax)	GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)
__EXTERN INTEGER __CALL_1 GetMessageA(WinAPI_MSG *lpMsg, INTEGER hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax);
#define WinAPI_GetMessageExtraInfo()	GetMessageExtraInfo()
__EXTERN INTEGER __CALL_1 GetMessageExtraInfo(void);
#define WinAPI_GetMessagePos()	GetMessagePos()
__EXTERN INTEGER __CALL_1 GetMessagePos(void);
#define WinAPI_GetMessageTime()	GetMessageTime()
__EXTERN INTEGER __CALL_1 GetMessageTime(void);
#define WinAPI_GetMessageW(lpMsg, lpMsg__typ, hWnd, wMsgFilterMin, wMsgFilterMax)	GetMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)
__EXTERN INTEGER __CALL_1 GetMessageW(WinAPI_MSG *lpMsg, INTEGER hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax);
#define WinAPI_GetMetaFile(p0)	GetMetaFileA(p0)
#define WinAPI_GetMetaFileA(p0)	GetMetaFileA(p0)
__EXTERN INTEGER __CALL_1 GetMetaFileA(INTEGER p0);
#define WinAPI_GetMetaFileBitsEx(p0, p1, p2, p2__len)	GetMetaFileBitsEx(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetMetaFileBitsEx(INTEGER p0, INTEGER p1, BYTE *p2);
#define WinAPI_GetMetaFileW(p0)	GetMetaFileW(p0)
__EXTERN INTEGER __CALL_1 GetMetaFileW(INTEGER p0);
#define WinAPI_GetMetaRgn(p0, p1)	GetMetaRgn(p0, p1)
__EXTERN INTEGER __CALL_1 GetMetaRgn(INTEGER p0, INTEGER p1);
#define WinAPI_GetMiterLimit(p0, p1)	GetMiterLimit(p0, p1)
__EXTERN INTEGER __CALL_1 GetMiterLimit(INTEGER p0, REAL *p1);
#define WinAPI_GetModuleFileName(hModule, lpFilename, nSize)	GetModuleFileNameA(hModule, lpFilename, nSize)
#define WinAPI_GetModuleFileNameA(hModule, lpFilename, nSize)	GetModuleFileNameA(hModule, lpFilename, nSize)
__EXTERN INTEGER __CALL_1 GetModuleFileNameA(INTEGER hModule, INTEGER lpFilename, INTEGER nSize);
#define WinAPI_GetModuleFileNameW(hModule, lpFilename, nSize)	GetModuleFileNameW(hModule, lpFilename, nSize)
__EXTERN INTEGER __CALL_1 GetModuleFileNameW(INTEGER hModule, INTEGER lpFilename, INTEGER nSize);
#define WinAPI_GetModuleHandle(lpModuleName)	GetModuleHandleA(lpModuleName)
#define WinAPI_GetModuleHandleA(lpModuleName)	GetModuleHandleA(lpModuleName)
__EXTERN INTEGER __CALL_1 GetModuleHandleA(INTEGER lpModuleName);
#define WinAPI_GetModuleHandleW(lpModuleName)	GetModuleHandleW(lpModuleName)
__EXTERN INTEGER __CALL_1 GetModuleHandleW(INTEGER lpModuleName);
#define WinAPI_GetNamedPipeHandleState(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)	GetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)
#define WinAPI_GetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)	GetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)
__EXTERN INTEGER __CALL_1 GetNamedPipeHandleStateA(INTEGER hNamedPipe, INTEGER *lpState, INTEGER *lpCurInstances, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout, INTEGER lpUserName, INTEGER nMaxUserNameSize);
#define WinAPI_GetNamedPipeHandleStateW(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)	GetNamedPipeHandleStateW(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize)
__EXTERN INTEGER __CALL_1 GetNamedPipeHandleStateW(INTEGER hNamedPipe, INTEGER *lpState, INTEGER *lpCurInstances, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout, INTEGER lpUserName, INTEGER nMaxUserNameSize);
#define WinAPI_GetNamedPipeInfo(hNamedPipe, lpFlags, lpOutBufferSize, lpInBufferSize, lpMaxInstances)	GetNamedPipeInfo(hNamedPipe, lpFlags, lpOutBufferSize, lpInBufferSize, lpMaxInstances)
__EXTERN INTEGER __CALL_1 GetNamedPipeInfo(INTEGER hNamedPipe, INTEGER *lpFlags, INTEGER *lpOutBufferSize, INTEGER *lpInBufferSize, INTEGER *lpMaxInstances);
#define WinAPI_GetNearestColor(p0, p1)	GetNearestColor(p0, p1)
__EXTERN INTEGER __CALL_1 GetNearestColor(INTEGER p0, INTEGER p1);
#define WinAPI_GetNearestPaletteIndex(p0, p1)	GetNearestPaletteIndex(p0, p1)
__EXTERN INTEGER __CALL_1 GetNearestPaletteIndex(INTEGER p0, INTEGER p1);
#define WinAPI_GetNextDlgGroupItem(hDlg, hCtl, bPrevious)	GetNextDlgGroupItem(hDlg, hCtl, bPrevious)
__EXTERN INTEGER __CALL_1 GetNextDlgGroupItem(INTEGER hDlg, INTEGER hCtl, INTEGER bPrevious);
#define WinAPI_GetNextDlgTabItem(hDlg, hCtl, bPrevious)	GetNextDlgTabItem(hDlg, hCtl, bPrevious)
__EXTERN INTEGER __CALL_1 GetNextDlgTabItem(INTEGER hDlg, INTEGER hCtl, INTEGER bPrevious);
#define WinAPI_GetNumberFormat(Locale, dwFlags, lpValue, lpFormat, lpFormat__typ, lpNumberStr, cchNumber)	GetNumberFormatA(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)
#define WinAPI_GetNumberFormatA(Locale, dwFlags, lpValue, lpFormat, lpFormat__typ, lpNumberStr, cchNumber)	GetNumberFormatA(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)
__EXTERN INTEGER __CALL_1 GetNumberFormatA(INTEGER Locale, SET dwFlags, INTEGER lpValue, WinAPI_NUMBERFMTA *lpFormat, INTEGER lpNumberStr, INTEGER cchNumber);
#define WinAPI_GetNumberFormatW(Locale, dwFlags, lpValue, lpFormat, lpFormat__typ, lpNumberStr, cchNumber)	GetNumberFormatW(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber)
__EXTERN INTEGER __CALL_1 GetNumberFormatW(INTEGER Locale, SET dwFlags, INTEGER lpValue, WinAPI_NUMBERFMTW *lpFormat, INTEGER lpNumberStr, INTEGER cchNumber);
#define WinAPI_GetNumberOfConsoleInputEvents(hConsoleInput, lpNumberOfEvents)	GetNumberOfConsoleInputEvents(hConsoleInput, lpNumberOfEvents)
__EXTERN INTEGER __CALL_1 GetNumberOfConsoleInputEvents(INTEGER hConsoleInput, INTEGER *lpNumberOfEvents);
#define WinAPI_GetNumberOfConsoleMouseButtons(lpNumberOfMouseButtons)	GetNumberOfConsoleMouseButtons(lpNumberOfMouseButtons)
__EXTERN INTEGER __CALL_1 GetNumberOfConsoleMouseButtons(INTEGER *lpNumberOfMouseButtons);
#define WinAPI_GetNumberOfEventLogRecords(hEventLog, NumberOfRecords)	GetNumberOfEventLogRecords(hEventLog, NumberOfRecords)
__EXTERN INTEGER __CALL_1 GetNumberOfEventLogRecords(INTEGER hEventLog, INTEGER *NumberOfRecords);
#define WinAPI_GetOEMCP()	GetOEMCP()
__EXTERN INTEGER __CALL_1 GetOEMCP(void);
#define WinAPI_GetObject(p0, p1, p2)	GetObjectA(p0, p1, p2)
#define WinAPI_GetObjectA(p0, p1, p2)	GetObjectA(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetObjectA(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_GetObjectType(h)	GetObjectType(h)
__EXTERN INTEGER __CALL_1 GetObjectType(INTEGER h);
#define WinAPI_GetObjectW(p0, p1, p2)	GetObjectW(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetObjectW(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_GetOldestEventLogRecord(hEventLog, OldestRecord)	GetOldestEventLogRecord(hEventLog, OldestRecord)
__EXTERN INTEGER __CALL_1 GetOldestEventLogRecord(INTEGER hEventLog, INTEGER *OldestRecord);
#define WinAPI_GetOpenClipboardWindow()	GetOpenClipboardWindow()
__EXTERN INTEGER __CALL_1 GetOpenClipboardWindow(void);
#define WinAPI_GetOutlineTextMetrics(p0, p1, p2, p2__typ)	GetOutlineTextMetricsA(p0, p1, p2)
#define WinAPI_GetOutlineTextMetricsA(p0, p1, p2, p2__typ)	GetOutlineTextMetricsA(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetOutlineTextMetricsA(INTEGER p0, INTEGER p1, WinAPI_OUTLINETEXTMETRICA *p2);
#define WinAPI_GetOutlineTextMetricsW(p0, p1, p2, p2__typ)	GetOutlineTextMetricsW(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetOutlineTextMetricsW(INTEGER p0, INTEGER p1, WinAPI_OUTLINETEXTMETRICW *p2);
#define WinAPI_GetOverlappedResult(hFile, lpOverlapped, lpOverlapped__typ, lpNumberOfBytesTransferred, bWait)	GetOverlappedResult(hFile, lpOverlapped, lpNumberOfBytesTransferred, bWait)
__EXTERN INTEGER __CALL_1 GetOverlappedResult(INTEGER hFile, WinAPI_OVERLAPPED *lpOverlapped, INTEGER *lpNumberOfBytesTransferred, INTEGER bWait);
#define WinAPI_GetPaletteEntries(p0, p1, p2, p3, p3__typ)	GetPaletteEntries(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetPaletteEntries(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
#define WinAPI_GetParent(hWnd)	GetParent(hWnd)
__EXTERN INTEGER __CALL_1 GetParent(INTEGER hWnd);
#define WinAPI_GetPath(p0, p1, p1__typ, p2, p3)	GetPath(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetPath(INTEGER p0, WinAPI_POINT *p1, CHAR *p2, INTEGER p3);
#define WinAPI_GetPixel(p0, p1, p2)	GetPixel(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetPixel(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_GetPixelFormat(p0)	GetPixelFormat(p0)
__EXTERN INTEGER __CALL_1 GetPixelFormat(INTEGER p0);
#define WinAPI_GetPolyFillMode(p0)	GetPolyFillMode(p0)
__EXTERN INTEGER __CALL_1 GetPolyFillMode(INTEGER p0);
#define WinAPI_GetPrintProcessorDirectory(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)	GetPrintProcessorDirectoryA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)
#define WinAPI_GetPrintProcessorDirectoryA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)	GetPrintProcessorDirectoryA(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetPrintProcessorDirectoryA(INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrintProcessorDirectoryW(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)	GetPrintProcessorDirectoryW(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetPrintProcessorDirectoryW(INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pPrintProcessorInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrinter(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)	GetPrinterA(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)
#define WinAPI_GetPrinterA(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)	GetPrinterA(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetPrinterA(INTEGER hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterData(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)	GetPrinterDataA(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)
#define WinAPI_GetPrinterDataA(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)	GetPrinterDataA(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetPrinterDataA(INTEGER hPrinter, INTEGER pValueName, INTEGER *pType, CHAR *pData, INTEGER nSize, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterDataW(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)	GetPrinterDataW(hPrinter, pValueName, pType, pData, nSize, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetPrinterDataW(INTEGER hPrinter, INTEGER pValueName, INTEGER *pType, CHAR *pData, INTEGER nSize, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterDriver(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)	GetPrinterDriverA(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)
#define WinAPI_GetPrinterDriverA(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)	GetPrinterDriverA(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetPrinterDriverA(INTEGER hPrinter, INTEGER pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterDriverDirectory(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)	GetPrinterDriverDirectoryA(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)
#define WinAPI_GetPrinterDriverDirectoryA(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)	GetPrinterDriverDirectoryA(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetPrinterDriverDirectoryA(INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pDriverDirectory, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterDriverDirectoryW(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)	GetPrinterDriverDirectoryW(pName, pEnvironment, Level, pDriverDirectory, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetPrinterDriverDirectoryW(INTEGER pName, INTEGER pEnvironment, INTEGER Level, CHAR *pDriverDirectory, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterDriverW(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)	GetPrinterDriverW(hPrinter, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetPrinterDriverW(INTEGER hPrinter, INTEGER pEnvironment, INTEGER Level, CHAR *pDriverInfo, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPrinterW(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)	GetPrinterW(hPrinter, Level, pPrinter, cbBuf, pcbNeeded)
__EXTERN INTEGER __CALL_1 GetPrinterW(INTEGER hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER cbBuf, INTEGER *pcbNeeded);
#define WinAPI_GetPriorityClass(hProcess)	GetPriorityClass(hProcess)
__EXTERN INTEGER __CALL_1 GetPriorityClass(INTEGER hProcess);
#define WinAPI_GetPriorityClipboardFormat(paFormatPriorityList, cFormats)	GetPriorityClipboardFormat(paFormatPriorityList, cFormats)
__EXTERN INTEGER __CALL_1 GetPriorityClipboardFormat(INTEGER *paFormatPriorityList, INTEGER cFormats);
#define WinAPI_GetPrivateObjectSecurity(ObjectDescriptor, SecurityInformation, ResultantDescriptor, DescriptorLength, ReturnLength)	GetPrivateObjectSecurity(ObjectDescriptor, SecurityInformation, ResultantDescriptor, DescriptorLength, ReturnLength)
__EXTERN INTEGER __CALL_1 GetPrivateObjectSecurity(INTEGER ObjectDescriptor, SET SecurityInformation, INTEGER ResultantDescriptor, INTEGER DescriptorLength, INTEGER *ReturnLength);
#define WinAPI_GetPrivateProfileInt(lpAppName, lpKeyName, nDefault, lpFileName)	GetPrivateProfileIntA(lpAppName, lpKeyName, nDefault, lpFileName)
#define WinAPI_GetPrivateProfileIntA(lpAppName, lpKeyName, nDefault, lpFileName)	GetPrivateProfileIntA(lpAppName, lpKeyName, nDefault, lpFileName)
__EXTERN INTEGER __CALL_1 GetPrivateProfileIntA(INTEGER lpAppName, INTEGER lpKeyName, INTEGER nDefault, INTEGER lpFileName);
#define WinAPI_GetPrivateProfileIntW(lpAppName, lpKeyName, nDefault, lpFileName)	GetPrivateProfileIntW(lpAppName, lpKeyName, nDefault, lpFileName)
__EXTERN INTEGER __CALL_1 GetPrivateProfileIntW(INTEGER lpAppName, INTEGER lpKeyName, INTEGER nDefault, INTEGER lpFileName);
#define WinAPI_GetPrivateProfileSection(lpAppName, lpReturnedString, nSize, lpFileName)	GetPrivateProfileSectionA(lpAppName, lpReturnedString, nSize, lpFileName)
#define WinAPI_GetPrivateProfileSectionA(lpAppName, lpReturnedString, nSize, lpFileName)	GetPrivateProfileSectionA(lpAppName, lpReturnedString, nSize, lpFileName)
__EXTERN INTEGER __CALL_1 GetPrivateProfileSectionA(INTEGER lpAppName, INTEGER lpReturnedString, INTEGER nSize, INTEGER lpFileName);
#define WinAPI_GetPrivateProfileSectionNames(lpszReturnBuffer, nSize, lpFileName)	GetPrivateProfileSectionNamesA(lpszReturnBuffer, nSize, lpFileName)
#define WinAPI_GetPrivateProfileSectionNamesA(lpszReturnBuffer, nSize, lpFileName)	GetPrivateProfileSectionNamesA(lpszReturnBuffer, nSize, lpFileName)
__EXTERN INTEGER __CALL_1 GetPrivateProfileSectionNamesA(INTEGER lpszReturnBuffer, INTEGER nSize, INTEGER lpFileName);
#define WinAPI_GetPrivateProfileSectionNamesW(lpszReturnBuffer, nSize, lpFileName)	GetPrivateProfileSectionNamesW(lpszReturnBuffer, nSize, lpFileName)
__EXTERN INTEGER __CALL_1 GetPrivateProfileSectionNamesW(INTEGER lpszReturnBuffer, INTEGER nSize, INTEGER lpFileName);
#define WinAPI_GetPrivateProfileSectionW(lpAppName, lpReturnedString, nSize, lpFileName)	GetPrivateProfileSectionW(lpAppName, lpReturnedString, nSize, lpFileName)
__EXTERN INTEGER __CALL_1 GetPrivateProfileSectionW(INTEGER lpAppName, INTEGER lpReturnedString, INTEGER nSize, INTEGER lpFileName);
#define WinAPI_GetPrivateProfileString(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)	GetPrivateProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)
#define WinAPI_GetPrivateProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)	GetPrivateProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)
__EXTERN INTEGER __CALL_1 GetPrivateProfileStringA(INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpDefault, INTEGER lpReturnedString, INTEGER nSize, INTEGER lpFileName);
#define WinAPI_GetPrivateProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)	GetPrivateProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName)
__EXTERN INTEGER __CALL_1 GetPrivateProfileStringW(INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpDefault, INTEGER lpReturnedString, INTEGER nSize, INTEGER lpFileName);
#define WinAPI_GetPrivateProfileStruct(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	GetPrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
#define WinAPI_GetPrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	GetPrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN INTEGER __CALL_1 GetPrivateProfileStructA(INTEGER lpszSection, INTEGER lpszKey, INTEGER lpStruct, INTEGER uSizeStruct, INTEGER szFile);
#define WinAPI_GetPrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	GetPrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN INTEGER __CALL_1 GetPrivateProfileStructW(INTEGER lpszSection, INTEGER lpszKey, INTEGER lpStruct, INTEGER uSizeStruct, INTEGER szFile);
#define WinAPI_GetProcAddress(hModule, lpProcName)	GetProcAddress(hModule, lpProcName)
__EXTERN WinAPI_FARPROC __CALL_1 GetProcAddress(INTEGER hModule, INTEGER lpProcName);
#define WinAPI_GetProcessAffinityMask(hProcess, lpProcessAffinityMask, lpSystemAffinityMask)	GetProcessAffinityMask(hProcess, lpProcessAffinityMask, lpSystemAffinityMask)
__EXTERN INTEGER __CALL_1 GetProcessAffinityMask(INTEGER hProcess, INTEGER *lpProcessAffinityMask, INTEGER *lpSystemAffinityMask);
#define WinAPI_GetProcessHeap()	GetProcessHeap()
__EXTERN INTEGER __CALL_1 GetProcessHeap(void);
#define WinAPI_GetProcessHeaps(NumberOfHeaps, ProcessHeaps)	GetProcessHeaps(NumberOfHeaps, ProcessHeaps)
__EXTERN INTEGER __CALL_1 GetProcessHeaps(INTEGER NumberOfHeaps, INTEGER *ProcessHeaps);
#define WinAPI_GetProcessShutdownParameters(lpdwLevel, lpdwFlags)	GetProcessShutdownParameters(lpdwLevel, lpdwFlags)
__EXTERN INTEGER __CALL_1 GetProcessShutdownParameters(INTEGER *lpdwLevel, SET *lpdwFlags);
#define WinAPI_GetProcessTimes(hProcess, lpCreationTime, lpCreationTime__typ, lpExitTime, lpExitTime__typ, lpKernelTime, lpKernelTime__typ, lpUserTime, lpUserTime__typ)	GetProcessTimes(hProcess, lpCreationTime, lpExitTime, lpKernelTime, lpUserTime)
__EXTERN INTEGER __CALL_1 GetProcessTimes(INTEGER hProcess, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpExitTime, WinAPI_FILETIME *lpKernelTime, WinAPI_FILETIME *lpUserTime);
#define WinAPI_GetProcessVersion(ProcessId)	GetProcessVersion(ProcessId)
__EXTERN INTEGER __CALL_1 GetProcessVersion(INTEGER ProcessId);
#define WinAPI_GetProcessWindowStation()	GetProcessWindowStation()
__EXTERN INTEGER __CALL_1 GetProcessWindowStation(void);
#define WinAPI_GetProcessWorkingSetSize(hProcess, lpMinimumWorkingSetSize, lpMaximumWorkingSetSize)	GetProcessWorkingSetSize(hProcess, lpMinimumWorkingSetSize, lpMaximumWorkingSetSize)
__EXTERN INTEGER __CALL_1 GetProcessWorkingSetSize(INTEGER hProcess, INTEGER *lpMinimumWorkingSetSize, INTEGER *lpMaximumWorkingSetSize);
#define WinAPI_GetProfileInt(lpAppName, lpKeyName, nDefault)	GetProfileIntA(lpAppName, lpKeyName, nDefault)
#define WinAPI_GetProfileIntA(lpAppName, lpKeyName, nDefault)	GetProfileIntA(lpAppName, lpKeyName, nDefault)
__EXTERN INTEGER __CALL_1 GetProfileIntA(INTEGER lpAppName, INTEGER lpKeyName, INTEGER nDefault);
#define WinAPI_GetProfileIntW(lpAppName, lpKeyName, nDefault)	GetProfileIntW(lpAppName, lpKeyName, nDefault)
__EXTERN INTEGER __CALL_1 GetProfileIntW(INTEGER lpAppName, INTEGER lpKeyName, INTEGER nDefault);
#define WinAPI_GetProfileSection(lpAppName, lpReturnedString, nSize)	GetProfileSectionA(lpAppName, lpReturnedString, nSize)
#define WinAPI_GetProfileSectionA(lpAppName, lpReturnedString, nSize)	GetProfileSectionA(lpAppName, lpReturnedString, nSize)
__EXTERN INTEGER __CALL_1 GetProfileSectionA(INTEGER lpAppName, INTEGER lpReturnedString, INTEGER nSize);
#define WinAPI_GetProfileSectionW(lpAppName, lpReturnedString, nSize)	GetProfileSectionW(lpAppName, lpReturnedString, nSize)
__EXTERN INTEGER __CALL_1 GetProfileSectionW(INTEGER lpAppName, INTEGER lpReturnedString, INTEGER nSize);
#define WinAPI_GetProfileString(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)	GetProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)
#define WinAPI_GetProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)	GetProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)
__EXTERN INTEGER __CALL_1 GetProfileStringA(INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpDefault, INTEGER lpReturnedString, INTEGER nSize);
#define WinAPI_GetProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)	GetProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize)
__EXTERN INTEGER __CALL_1 GetProfileStringW(INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpDefault, INTEGER lpReturnedString, INTEGER nSize);
#define WinAPI_GetProp(hWnd, lpString)	GetPropA(hWnd, lpString)
#define WinAPI_GetPropA(hWnd, lpString)	GetPropA(hWnd, lpString)
__EXTERN INTEGER __CALL_1 GetPropA(INTEGER hWnd, INTEGER lpString);
#define WinAPI_GetPropW(hWnd, lpString)	GetPropW(hWnd, lpString)
__EXTERN INTEGER __CALL_1 GetPropW(INTEGER hWnd, INTEGER lpString);
#define WinAPI_GetQueueStatus(flags)	GetQueueStatus(flags)
__EXTERN INTEGER __CALL_1 GetQueueStatus(SET flags);
#define WinAPI_GetQueuedCompletionStatus(CompletionPort, lpNumberOfBytesTransferred, lpCompletionKey, lpOverlapped, dwMilliseconds)	GetQueuedCompletionStatus(CompletionPort, lpNumberOfBytesTransferred, lpCompletionKey, lpOverlapped, dwMilliseconds)
__EXTERN INTEGER __CALL_1 GetQueuedCompletionStatus(INTEGER CompletionPort, INTEGER *lpNumberOfBytesTransferred, INTEGER *lpCompletionKey, WinAPI_PtrOVERLAPPED *lpOverlapped, INTEGER dwMilliseconds);
#define WinAPI_GetROP2(p0)	GetROP2(p0)
__EXTERN INTEGER __CALL_1 GetROP2(INTEGER p0);
#define WinAPI_GetRasterizerCaps(p0, p0__typ, p1)	GetRasterizerCaps(p0, p1)
__EXTERN INTEGER __CALL_1 GetRasterizerCaps(WinAPI_RASTERIZER_STATUS *p0, INTEGER p1);
#define WinAPI_GetRegionData(p0, p1, p2, p2__typ)	GetRegionData(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetRegionData(INTEGER p0, INTEGER p1, WinAPI_RGNDATA *p2);
#define WinAPI_GetRgnBox(p0, p1, p1__typ)	GetRgnBox(p0, p1)
__EXTERN INTEGER __CALL_1 GetRgnBox(INTEGER p0, WinAPI_RECT *p1);
#define WinAPI_GetScrollInfo(p0, p1, p2, p2__typ)	GetScrollInfo(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetScrollInfo(INTEGER p0, INTEGER p1, WinAPI_SCROLLINFO *p2);
#define WinAPI_GetScrollPos(hWnd, nBar)	GetScrollPos(hWnd, nBar)
__EXTERN INTEGER __CALL_1 GetScrollPos(INTEGER hWnd, INTEGER nBar);
#define WinAPI_GetScrollRange(hWnd, nBar, lpMinPos, lpMaxPos)	GetScrollRange(hWnd, nBar, lpMinPos, lpMaxPos)
__EXTERN INTEGER __CALL_1 GetScrollRange(INTEGER hWnd, INTEGER nBar, INTEGER *lpMinPos, INTEGER *lpMaxPos);
#define WinAPI_GetSecurityDescriptorControl(pSecurityDescriptor, pControl, lpdwRevision)	GetSecurityDescriptorControl(pSecurityDescriptor, pControl, lpdwRevision)
__EXTERN INTEGER __CALL_1 GetSecurityDescriptorControl(INTEGER pSecurityDescriptor, SHORTINT *pControl, INTEGER *lpdwRevision);
#define WinAPI_GetSecurityDescriptorDacl(pSecurityDescriptor, lpbDaclPresent, pDacl, lpbDaclDefaulted)	GetSecurityDescriptorDacl(pSecurityDescriptor, lpbDaclPresent, pDacl, lpbDaclDefaulted)
__EXTERN INTEGER __CALL_1 GetSecurityDescriptorDacl(INTEGER pSecurityDescriptor, INTEGER *lpbDaclPresent, WinAPI_PtrACL *pDacl, INTEGER *lpbDaclDefaulted);
#define WinAPI_GetSecurityDescriptorGroup(pSecurityDescriptor, pGroup, lpbGroupDefaulted)	GetSecurityDescriptorGroup(pSecurityDescriptor, pGroup, lpbGroupDefaulted)
__EXTERN INTEGER __CALL_1 GetSecurityDescriptorGroup(INTEGER pSecurityDescriptor, INTEGER *pGroup, INTEGER *lpbGroupDefaulted);
#define WinAPI_GetSecurityDescriptorLength(pSecurityDescriptor)	GetSecurityDescriptorLength(pSecurityDescriptor)
__EXTERN INTEGER __CALL_1 GetSecurityDescriptorLength(INTEGER pSecurityDescriptor);
#define WinAPI_GetSecurityDescriptorOwner(pSecurityDescriptor, pOwner, lpbOwnerDefaulted)	GetSecurityDescriptorOwner(pSecurityDescriptor, pOwner, lpbOwnerDefaulted)
__EXTERN INTEGER __CALL_1 GetSecurityDescriptorOwner(INTEGER pSecurityDescriptor, INTEGER *pOwner, INTEGER *lpbOwnerDefaulted);
#define WinAPI_GetSecurityDescriptorSacl(pSecurityDescriptor, lpbSaclPresent, pSacl, lpbSaclDefaulted)	GetSecurityDescriptorSacl(pSecurityDescriptor, lpbSaclPresent, pSacl, lpbSaclDefaulted)
__EXTERN INTEGER __CALL_1 GetSecurityDescriptorSacl(INTEGER pSecurityDescriptor, INTEGER *lpbSaclPresent, WinAPI_PtrACL *pSacl, INTEGER *lpbSaclDefaulted);
#define WinAPI_GetServiceDisplayName(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)	GetServiceDisplayNameA(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)
#define WinAPI_GetServiceDisplayNameA(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)	GetServiceDisplayNameA(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)
__EXTERN INTEGER __CALL_1 GetServiceDisplayNameA(INTEGER hSCManager, INTEGER lpServiceName, INTEGER lpDisplayName, INTEGER *lpcchBuffer);
#define WinAPI_GetServiceDisplayNameW(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)	GetServiceDisplayNameW(hSCManager, lpServiceName, lpDisplayName, lpcchBuffer)
__EXTERN INTEGER __CALL_1 GetServiceDisplayNameW(INTEGER hSCManager, INTEGER lpServiceName, INTEGER lpDisplayName, INTEGER *lpcchBuffer);
#define WinAPI_GetServiceKeyName(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)	GetServiceKeyNameA(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)
#define WinAPI_GetServiceKeyNameA(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)	GetServiceKeyNameA(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)
__EXTERN INTEGER __CALL_1 GetServiceKeyNameA(INTEGER hSCManager, INTEGER lpDisplayName, INTEGER lpServiceName, INTEGER *lpcchBuffer);
#define WinAPI_GetServiceKeyNameW(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)	GetServiceKeyNameW(hSCManager, lpDisplayName, lpServiceName, lpcchBuffer)
__EXTERN INTEGER __CALL_1 GetServiceKeyNameW(INTEGER hSCManager, INTEGER lpDisplayName, INTEGER lpServiceName, INTEGER *lpcchBuffer);
#define WinAPI_GetShortPathName(lpszLongPath, lpszShortPath, cchBuffer)	GetShortPathNameA(lpszLongPath, lpszShortPath, cchBuffer)
#define WinAPI_GetShortPathNameA(lpszLongPath, lpszShortPath, cchBuffer)	GetShortPathNameA(lpszLongPath, lpszShortPath, cchBuffer)
__EXTERN INTEGER __CALL_1 GetShortPathNameA(INTEGER lpszLongPath, INTEGER lpszShortPath, INTEGER cchBuffer);
#define WinAPI_GetShortPathNameW(lpszLongPath, lpszShortPath, cchBuffer)	GetShortPathNameW(lpszLongPath, lpszShortPath, cchBuffer)
__EXTERN INTEGER __CALL_1 GetShortPathNameW(INTEGER lpszLongPath, INTEGER lpszShortPath, INTEGER cchBuffer);
#define WinAPI_GetSidIdentifierAuthority(pSid)	GetSidIdentifierAuthority(pSid)
__EXTERN WinAPI_PtrSID_IDENTIFIER_AUTHORITY __CALL_1 GetSidIdentifierAuthority(INTEGER pSid);
#define WinAPI_GetSidLengthRequired(nSubAuthorityCount)	GetSidLengthRequired(nSubAuthorityCount)
__EXTERN INTEGER __CALL_1 GetSidLengthRequired(CHAR nSubAuthorityCount);
#define WinAPI_GetSidSubAuthority(pSid, nSubAuthority)	GetSidSubAuthority(pSid, nSubAuthority)
__EXTERN INTEGER __CALL_1 GetSidSubAuthority(INTEGER pSid, INTEGER nSubAuthority);
#define WinAPI_GetSidSubAuthorityCount(pSid)	GetSidSubAuthorityCount(pSid)
__EXTERN INTEGER __CALL_1 GetSidSubAuthorityCount(INTEGER pSid);
#define WinAPI_GetStartupInfo(lpStartupInfo, lpStartupInfo__typ)	GetStartupInfoA(lpStartupInfo)
#define WinAPI_GetStartupInfoA(lpStartupInfo, lpStartupInfo__typ)	GetStartupInfoA(lpStartupInfo)
__EXTERN void __CALL_1 GetStartupInfoA(WinAPI_STARTUPINFOA *lpStartupInfo);
#define WinAPI_GetStartupInfoW(lpStartupInfo, lpStartupInfo__typ)	GetStartupInfoW(lpStartupInfo)
__EXTERN void __CALL_1 GetStartupInfoW(WinAPI_STARTUPINFOW *lpStartupInfo);
#define WinAPI_GetStdHandle(nStdHandle)	GetStdHandle(nStdHandle)
__EXTERN INTEGER __CALL_1 GetStdHandle(INTEGER nStdHandle);
#define WinAPI_GetStockObject(p0)	GetStockObject(p0)
__EXTERN INTEGER __CALL_1 GetStockObject(INTEGER p0);
#define WinAPI_GetStretchBltMode(p0)	GetStretchBltMode(p0)
__EXTERN INTEGER __CALL_1 GetStretchBltMode(INTEGER p0);
#define WinAPI_GetStringTypeA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)
__EXTERN INTEGER __CALL_1 GetStringTypeA(INTEGER Locale, SET dwInfoType, INTEGER lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
#define WinAPI_GetStringTypeEx(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeExA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)
#define WinAPI_GetStringTypeExA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeExA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)
__EXTERN INTEGER __CALL_1 GetStringTypeExA(INTEGER Locale, SET dwInfoType, INTEGER lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
#define WinAPI_GetStringTypeExW(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeExW(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType)
__EXTERN INTEGER __CALL_1 GetStringTypeExW(INTEGER Locale, SET dwInfoType, INTEGER lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
#define WinAPI_GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType)	GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType)
__EXTERN INTEGER __CALL_1 GetStringTypeW(SET dwInfoType, INTEGER lpSrcStr, INTEGER cchSrc, SHORTINT *lpCharType);
#define WinAPI_GetSubMenu(hMenu, nPos)	GetSubMenu(hMenu, nPos)
__EXTERN INTEGER __CALL_1 GetSubMenu(INTEGER hMenu, INTEGER nPos);
#define WinAPI_GetSysColor(nIndex)	GetSysColor(nIndex)
__EXTERN INTEGER __CALL_1 GetSysColor(INTEGER nIndex);
#define WinAPI_GetSysColorBrush(nIndex)	GetSysColorBrush(nIndex)
__EXTERN INTEGER __CALL_1 GetSysColorBrush(INTEGER nIndex);
#define WinAPI_GetSystemDefaultLCID()	GetSystemDefaultLCID()
__EXTERN INTEGER __CALL_1 GetSystemDefaultLCID(void);
#define WinAPI_GetSystemDefaultLangID()	GetSystemDefaultLangID()
__EXTERN SHORTINT __CALL_1 GetSystemDefaultLangID(void);
#define WinAPI_GetSystemDirectory(lpBuffer, uSize)	GetSystemDirectoryA(lpBuffer, uSize)
#define WinAPI_GetSystemDirectoryA(lpBuffer, uSize)	GetSystemDirectoryA(lpBuffer, uSize)
__EXTERN INTEGER __CALL_1 GetSystemDirectoryA(INTEGER lpBuffer, INTEGER uSize);
#define WinAPI_GetSystemDirectoryW(lpBuffer, uSize)	GetSystemDirectoryW(lpBuffer, uSize)
__EXTERN INTEGER __CALL_1 GetSystemDirectoryW(INTEGER lpBuffer, INTEGER uSize);
#define WinAPI_GetSystemInfo(lpSystemInfo, lpSystemInfo__typ)	GetSystemInfo(lpSystemInfo)
__EXTERN void __CALL_1 GetSystemInfo(WinAPI_SYSTEM_INFO *lpSystemInfo);
#define WinAPI_GetSystemMenu(hWnd, bRevert)	GetSystemMenu(hWnd, bRevert)
__EXTERN INTEGER __CALL_1 GetSystemMenu(INTEGER hWnd, INTEGER bRevert);
#define WinAPI_GetSystemMetrics(nIndex)	GetSystemMetrics(nIndex)
__EXTERN INTEGER __CALL_1 GetSystemMetrics(INTEGER nIndex);
#define WinAPI_GetSystemPaletteEntries(p0, p1, p2, p3, p3__typ)	GetSystemPaletteEntries(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetSystemPaletteEntries(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
#define WinAPI_GetSystemPaletteUse(p0)	GetSystemPaletteUse(p0)
__EXTERN INTEGER __CALL_1 GetSystemPaletteUse(INTEGER p0);
#define WinAPI_GetSystemPowerStatus(lpSystemPowerStatus, lpSystemPowerStatus__typ)	GetSystemPowerStatus(lpSystemPowerStatus)
__EXTERN INTEGER __CALL_1 GetSystemPowerStatus(WinAPI_SYSTEM_POWER_STATUS *lpSystemPowerStatus);
#define WinAPI_GetSystemTime(lpSystemTime, lpSystemTime__typ)	GetSystemTime(lpSystemTime)
__EXTERN void __CALL_1 GetSystemTime(WinAPI_SYSTEMTIME *lpSystemTime);
#define WinAPI_GetSystemTimeAdjustment(lpTimeAdjustment, lpTimeIncrement, lpTimeAdjustmentDisabled)	GetSystemTimeAdjustment(lpTimeAdjustment, lpTimeIncrement, lpTimeAdjustmentDisabled)
__EXTERN INTEGER __CALL_1 GetSystemTimeAdjustment(INTEGER *lpTimeAdjustment, INTEGER *lpTimeIncrement, INTEGER *lpTimeAdjustmentDisabled);
#define WinAPI_GetSystemTimeAsFileTime(lpSystemTimeAsFileTime, lpSystemTimeAsFileTime__typ)	GetSystemTimeAsFileTime(lpSystemTimeAsFileTime)
__EXTERN void __CALL_1 GetSystemTimeAsFileTime(WinAPI_FILETIME *lpSystemTimeAsFileTime);
#define WinAPI_GetTabbedTextExtent(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)	GetTabbedTextExtentA(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)
#define WinAPI_GetTabbedTextExtentA(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)	GetTabbedTextExtentA(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)
__EXTERN INTEGER __CALL_1 GetTabbedTextExtentA(INTEGER hDC, INTEGER lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions);
#define WinAPI_GetTabbedTextExtentW(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)	GetTabbedTextExtentW(hDC, lpString, nCount, nTabPositions, lpnTabStopPositions)
__EXTERN INTEGER __CALL_1 GetTabbedTextExtentW(INTEGER hDC, INTEGER lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions);
#define WinAPI_GetTapeParameters(hDevice, dwOperation, lpdwSize, lpTapeInformation)	GetTapeParameters(hDevice, dwOperation, lpdwSize, lpTapeInformation)
__EXTERN INTEGER __CALL_1 GetTapeParameters(INTEGER hDevice, INTEGER dwOperation, INTEGER *lpdwSize, INTEGER lpTapeInformation);
#define WinAPI_GetTapePosition(hDevice, dwPositionType, lpdwPartition, lpdwOffsetLow, lpdwOffsetHigh)	GetTapePosition(hDevice, dwPositionType, lpdwPartition, lpdwOffsetLow, lpdwOffsetHigh)
__EXTERN INTEGER __CALL_1 GetTapePosition(INTEGER hDevice, INTEGER dwPositionType, INTEGER *lpdwPartition, INTEGER *lpdwOffsetLow, INTEGER *lpdwOffsetHigh);
#define WinAPI_GetTapeStatus(hDevice)	GetTapeStatus(hDevice)
__EXTERN INTEGER __CALL_1 GetTapeStatus(INTEGER hDevice);
#define WinAPI_GetTempFileName(lpPathName, lpPrefixString, uUnique, lpTempFileName)	GetTempFileNameA(lpPathName, lpPrefixString, uUnique, lpTempFileName)
#define WinAPI_GetTempFileNameA(lpPathName, lpPrefixString, uUnique, lpTempFileName)	GetTempFileNameA(lpPathName, lpPrefixString, uUnique, lpTempFileName)
__EXTERN INTEGER __CALL_1 GetTempFileNameA(INTEGER lpPathName, INTEGER lpPrefixString, INTEGER uUnique, INTEGER lpTempFileName);
#define WinAPI_GetTempFileNameW(lpPathName, lpPrefixString, uUnique, lpTempFileName)	GetTempFileNameW(lpPathName, lpPrefixString, uUnique, lpTempFileName)
__EXTERN INTEGER __CALL_1 GetTempFileNameW(INTEGER lpPathName, INTEGER lpPrefixString, INTEGER uUnique, INTEGER lpTempFileName);
#define WinAPI_GetTempPath(nBufferLength, lpBuffer)	GetTempPathA(nBufferLength, lpBuffer)
#define WinAPI_GetTempPathA(nBufferLength, lpBuffer)	GetTempPathA(nBufferLength, lpBuffer)
__EXTERN INTEGER __CALL_1 GetTempPathA(INTEGER nBufferLength, INTEGER lpBuffer);
#define WinAPI_GetTempPathW(nBufferLength, lpBuffer)	GetTempPathW(nBufferLength, lpBuffer)
__EXTERN INTEGER __CALL_1 GetTempPathW(INTEGER nBufferLength, INTEGER lpBuffer);
#define WinAPI_GetTextAlign(p0)	GetTextAlign(p0)
__EXTERN SET __CALL_1 GetTextAlign(INTEGER p0);
#define WinAPI_GetTextCharacterExtra(p0)	GetTextCharacterExtra(p0)
__EXTERN INTEGER __CALL_1 GetTextCharacterExtra(INTEGER p0);
#define WinAPI_GetTextCharset(hdc)	GetTextCharset(hdc)
__EXTERN INTEGER __CALL_1 GetTextCharset(INTEGER hdc);
#define WinAPI_GetTextCharsetInfo(hdc, lpSig, lpSig__typ, dwFlags)	GetTextCharsetInfo(hdc, lpSig, dwFlags)
__EXTERN INTEGER __CALL_1 GetTextCharsetInfo(INTEGER hdc, WinAPI_FONTSIGNATURE *lpSig, SET dwFlags);
#define WinAPI_GetTextColor(p0)	GetTextColor(p0)
__EXTERN INTEGER __CALL_1 GetTextColor(INTEGER p0);
#define WinAPI_GetTextExtentExPoint(p0, p1, p2, p3, p4, p5, p6, p6__typ)	GetTextExtentExPointA(p0, p1, p2, p3, p4, p5, p6)
#define WinAPI_GetTextExtentExPointA(p0, p1, p2, p3, p4, p5, p6, p6__typ)	GetTextExtentExPointA(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL_1 GetTextExtentExPointA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4, INTEGER *p5, WinAPI_SIZE *p6);
#define WinAPI_GetTextExtentExPointW(p0, p1, p2, p3, p4, p5, p6, p6__typ)	GetTextExtentExPointW(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL_1 GetTextExtentExPointW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4, INTEGER *p5, WinAPI_SIZE *p6);
#define WinAPI_GetTextExtentPoint(p0, p1, p2, p3, p3__typ)	GetTextExtentPointA(p0, p1, p2, p3)
#define WinAPI_GetTextExtentPoint32(p0, p1, p2, p3, p3__typ)	GetTextExtentPoint32A(p0, p1, p2, p3)
#define WinAPI_GetTextExtentPoint32A(p0, p1, p2, p3, p3__typ)	GetTextExtentPoint32A(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetTextExtentPoint32A(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_GetTextExtentPoint32W(p0, p1, p2, p3, p3__typ)	GetTextExtentPoint32W(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetTextExtentPoint32W(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_GetTextExtentPointA(p0, p1, p2, p3, p3__typ)	GetTextExtentPointA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetTextExtentPointA(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_GetTextExtentPointW(p0, p1, p2, p3, p3__typ)	GetTextExtentPointW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 GetTextExtentPointW(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_GetTextFace(p0, p1, p2)	GetTextFaceA(p0, p1, p2)
#define WinAPI_GetTextFaceA(p0, p1, p2)	GetTextFaceA(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetTextFaceA(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_GetTextFaceW(p0, p1, p2)	GetTextFaceW(p0, p1, p2)
__EXTERN INTEGER __CALL_1 GetTextFaceW(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_GetTextMetrics(p0, p1, p1__typ)	GetTextMetricsA(p0, p1)
#define WinAPI_GetTextMetricsA(p0, p1, p1__typ)	GetTextMetricsA(p0, p1)
__EXTERN INTEGER __CALL_1 GetTextMetricsA(INTEGER p0, WinAPI_TEXTMETRICA *p1);
#define WinAPI_GetTextMetricsW(p0, p1, p1__typ)	GetTextMetricsW(p0, p1)
__EXTERN INTEGER __CALL_1 GetTextMetricsW(INTEGER p0, WinAPI_TEXTMETRICW *p1);
#define WinAPI_GetThreadContext(hThread, lpContext, lpContext__typ)	GetThreadContext(hThread, lpContext)
__EXTERN INTEGER __CALL_1 GetThreadContext(INTEGER hThread, WinAPI_CONTEXT *lpContext);
#define WinAPI_GetThreadDesktop(dwThreadId)	GetThreadDesktop(dwThreadId)
__EXTERN INTEGER __CALL_1 GetThreadDesktop(INTEGER dwThreadId);
#define WinAPI_GetThreadLocale()	GetThreadLocale()
__EXTERN INTEGER __CALL_1 GetThreadLocale(void);
#define WinAPI_GetThreadPriority(hThread)	GetThreadPriority(hThread)
__EXTERN INTEGER __CALL_1 GetThreadPriority(INTEGER hThread);
#define WinAPI_GetThreadPriorityBoost(hThread, pDisablePriorityBoost)	GetThreadPriorityBoost(hThread, pDisablePriorityBoost)
__EXTERN INTEGER __CALL_1 GetThreadPriorityBoost(INTEGER hThread, INTEGER *pDisablePriorityBoost);
#define WinAPI_GetThreadSelectorEntry(hThread, dwSelector, lpSelectorEntry, lpSelectorEntry__typ)	GetThreadSelectorEntry(hThread, dwSelector, lpSelectorEntry)
__EXTERN INTEGER __CALL_1 GetThreadSelectorEntry(INTEGER hThread, INTEGER dwSelector, WinAPI_LDT_ENTRY *lpSelectorEntry);
#define WinAPI_GetThreadTimes(hThread, lpCreationTime, lpCreationTime__typ, lpExitTime, lpExitTime__typ, lpKernelTime, lpKernelTime__typ, lpUserTime, lpUserTime__typ)	GetThreadTimes(hThread, lpCreationTime, lpExitTime, lpKernelTime, lpUserTime)
__EXTERN INTEGER __CALL_1 GetThreadTimes(INTEGER hThread, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpExitTime, WinAPI_FILETIME *lpKernelTime, WinAPI_FILETIME *lpUserTime);
#define WinAPI_GetTickCount()	GetTickCount()
__EXTERN INTEGER __CALL_1 GetTickCount(void);
#define WinAPI_GetTimeFormat(Locale, dwFlags, lpTime, lpTime__typ, lpFormat, lpTimeStr, cchTime)	GetTimeFormatA(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)
#define WinAPI_GetTimeFormatA(Locale, dwFlags, lpTime, lpTime__typ, lpFormat, lpTimeStr, cchTime)	GetTimeFormatA(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)
__EXTERN INTEGER __CALL_1 GetTimeFormatA(INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpTime, INTEGER lpFormat, INTEGER lpTimeStr, INTEGER cchTime);
#define WinAPI_GetTimeFormatW(Locale, dwFlags, lpTime, lpTime__typ, lpFormat, lpTimeStr, cchTime)	GetTimeFormatW(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime)
__EXTERN INTEGER __CALL_1 GetTimeFormatW(INTEGER Locale, SET dwFlags, WinAPI_SYSTEMTIME *lpTime, INTEGER lpFormat, INTEGER lpTimeStr, INTEGER cchTime);
#define WinAPI_GetTimeZoneInformation(lpTimeZoneInformation, lpTimeZoneInformation__typ)	GetTimeZoneInformation(lpTimeZoneInformation)
__EXTERN INTEGER __CALL_1 GetTimeZoneInformation(WinAPI_TIME_ZONE_INFORMATION *lpTimeZoneInformation);
#define WinAPI_GetTokenInformation(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength, ReturnLength)	GetTokenInformation(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength, ReturnLength)
__EXTERN INTEGER __CALL_1 GetTokenInformation(INTEGER TokenHandle, INTEGER TokenInformationClass, INTEGER TokenInformation, INTEGER TokenInformationLength, INTEGER *ReturnLength);
#define WinAPI_GetTopWindow(hWnd)	GetTopWindow(hWnd)
__EXTERN INTEGER __CALL_1 GetTopWindow(INTEGER hWnd);
#define WinAPI_GetUpdateRect(hWnd, lpRect, lpRect__typ, bErase)	GetUpdateRect(hWnd, lpRect, bErase)
__EXTERN INTEGER __CALL_1 GetUpdateRect(INTEGER hWnd, WinAPI_RECT *lpRect, INTEGER bErase);
#define WinAPI_GetUpdateRgn(hWnd, hRgn, bErase)	GetUpdateRgn(hWnd, hRgn, bErase)
__EXTERN INTEGER __CALL_1 GetUpdateRgn(INTEGER hWnd, INTEGER hRgn, INTEGER bErase);
#define WinAPI_GetUserDefaultLCID()	GetUserDefaultLCID()
__EXTERN INTEGER __CALL_1 GetUserDefaultLCID(void);
#define WinAPI_GetUserDefaultLangID()	GetUserDefaultLangID()
__EXTERN SHORTINT __CALL_1 GetUserDefaultLangID(void);
#define WinAPI_GetUserName(lpBuffer, nSize)	GetUserNameA(lpBuffer, nSize)
#define WinAPI_GetUserNameA(lpBuffer, nSize)	GetUserNameA(lpBuffer, nSize)
__EXTERN INTEGER __CALL_1 GetUserNameA(INTEGER lpBuffer, INTEGER *nSize);
#define WinAPI_GetUserNameW(lpBuffer, nSize)	GetUserNameW(lpBuffer, nSize)
__EXTERN INTEGER __CALL_1 GetUserNameW(INTEGER lpBuffer, INTEGER *nSize);
#define WinAPI_GetUserObjectInformation(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)	GetUserObjectInformationA(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)
#define WinAPI_GetUserObjectInformationA(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)	GetUserObjectInformationA(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)
__EXTERN INTEGER __CALL_1 GetUserObjectInformationA(INTEGER hObj, INTEGER nIndex, INTEGER pvInfo, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinAPI_GetUserObjectInformationW(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)	GetUserObjectInformationW(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded)
__EXTERN INTEGER __CALL_1 GetUserObjectInformationW(INTEGER hObj, INTEGER nIndex, INTEGER pvInfo, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinAPI_GetUserObjectSecurity(hObj, pSIRequested, pSID, nLength, lpnLengthNeeded)	GetUserObjectSecurity(hObj, pSIRequested, pSID, nLength, lpnLengthNeeded)
__EXTERN INTEGER __CALL_1 GetUserObjectSecurity(INTEGER hObj, INTEGER *pSIRequested, INTEGER pSID, INTEGER nLength, INTEGER *lpnLengthNeeded);
#define WinAPI_GetVersion()	GetVersion()
__EXTERN INTEGER __CALL_1 GetVersion(void);
#define WinAPI_GetVersionEx(lpVersionInformation, lpVersionInformation__typ)	GetVersionExA(lpVersionInformation)
#define WinAPI_GetVersionExA(lpVersionInformation, lpVersionInformation__typ)	GetVersionExA(lpVersionInformation)
__EXTERN INTEGER __CALL_1 GetVersionExA(WinAPI_OSVERSIONINFOA *lpVersionInformation);
#define WinAPI_GetVersionExW(lpVersionInformation, lpVersionInformation__typ)	GetVersionExW(lpVersionInformation)
__EXTERN INTEGER __CALL_1 GetVersionExW(WinAPI_OSVERSIONINFOW *lpVersionInformation);
#define WinAPI_GetViewportExtEx(p0, p1, p1__typ)	GetViewportExtEx(p0, p1)
__EXTERN INTEGER __CALL_1 GetViewportExtEx(INTEGER p0, WinAPI_SIZE *p1);
#define WinAPI_GetViewportOrgEx(p0, p1, p1__typ)	GetViewportOrgEx(p0, p1)
__EXTERN INTEGER __CALL_1 GetViewportOrgEx(INTEGER p0, WinAPI_POINT *p1);
#define WinAPI_GetVolumeInformation(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)	GetVolumeInformationA(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)
#define WinAPI_GetVolumeInformationA(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)	GetVolumeInformationA(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)
__EXTERN INTEGER __CALL_1 GetVolumeInformationA(INTEGER lpRootPathName, INTEGER lpVolumeNameBuffer, INTEGER nVolumeNameSize, INTEGER *lpVolumeSerialNumber, INTEGER *lpMaximumComponentLength, SET *lpFileSystemFlags, INTEGER lpFileSystemNameBuffer, INTEGER nFileSystemNameSize);
#define WinAPI_GetVolumeInformationW(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)	GetVolumeInformationW(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize)
__EXTERN INTEGER __CALL_1 GetVolumeInformationW(INTEGER lpRootPathName, INTEGER lpVolumeNameBuffer, INTEGER nVolumeNameSize, INTEGER *lpVolumeSerialNumber, INTEGER *lpMaximumComponentLength, SET *lpFileSystemFlags, INTEGER lpFileSystemNameBuffer, INTEGER nFileSystemNameSize);
#define WinAPI_GetWinMetaFileBits(p0, p1, p2, p3, p4)	GetWinMetaFileBits(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 GetWinMetaFileBits(INTEGER p0, INTEGER p1, CHAR *p2, INTEGER p3, INTEGER p4);
#define WinAPI_GetWindow(hWnd, uCmd)	GetWindow(hWnd, uCmd)
__EXTERN INTEGER __CALL_1 GetWindow(INTEGER hWnd, INTEGER uCmd);
#define WinAPI_GetWindowContextHelpId(p0)	GetWindowContextHelpId(p0)
__EXTERN INTEGER __CALL_1 GetWindowContextHelpId(INTEGER p0);
#define WinAPI_GetWindowDC(hWnd)	GetWindowDC(hWnd)
__EXTERN INTEGER __CALL_1 GetWindowDC(INTEGER hWnd);
#define WinAPI_GetWindowExtEx(p0, p1, p1__typ)	GetWindowExtEx(p0, p1)
__EXTERN INTEGER __CALL_1 GetWindowExtEx(INTEGER p0, WinAPI_SIZE *p1);
#define WinAPI_GetWindowLong(hWnd, nIndex)	GetWindowLongA(hWnd, nIndex)
#define WinAPI_GetWindowLongA(hWnd, nIndex)	GetWindowLongA(hWnd, nIndex)
__EXTERN INTEGER __CALL_1 GetWindowLongA(INTEGER hWnd, INTEGER nIndex);
#define WinAPI_GetWindowLongW(hWnd, nIndex)	GetWindowLongW(hWnd, nIndex)
__EXTERN INTEGER __CALL_1 GetWindowLongW(INTEGER hWnd, INTEGER nIndex);
#define WinAPI_GetWindowOrgEx(p0, p1, p1__typ)	GetWindowOrgEx(p0, p1)
__EXTERN INTEGER __CALL_1 GetWindowOrgEx(INTEGER p0, WinAPI_POINT *p1);
#define WinAPI_GetWindowPlacement(hWnd, lpwndpl, lpwndpl__typ)	GetWindowPlacement(hWnd, lpwndpl)
__EXTERN INTEGER __CALL_1 GetWindowPlacement(INTEGER hWnd, WinAPI_WINDOWPLACEMENT *lpwndpl);
#define WinAPI_GetWindowRect(hWnd, lpRect, lpRect__typ)	GetWindowRect(hWnd, lpRect)
__EXTERN INTEGER __CALL_1 GetWindowRect(INTEGER hWnd, WinAPI_RECT *lpRect);
#define WinAPI_GetWindowRgn(hWnd, hRgn)	GetWindowRgn(hWnd, hRgn)
__EXTERN INTEGER __CALL_1 GetWindowRgn(INTEGER hWnd, INTEGER hRgn);
#define WinAPI_GetWindowText(hWnd, lpString, nMaxCount)	GetWindowTextA(hWnd, lpString, nMaxCount)
#define WinAPI_GetWindowTextA(hWnd, lpString, nMaxCount)	GetWindowTextA(hWnd, lpString, nMaxCount)
__EXTERN INTEGER __CALL_1 GetWindowTextA(INTEGER hWnd, INTEGER lpString, INTEGER nMaxCount);
#define WinAPI_GetWindowTextLength(hWnd)	GetWindowTextLengthA(hWnd)
#define WinAPI_GetWindowTextLengthA(hWnd)	GetWindowTextLengthA(hWnd)
__EXTERN INTEGER __CALL_1 GetWindowTextLengthA(INTEGER hWnd);
#define WinAPI_GetWindowTextLengthW(hWnd)	GetWindowTextLengthW(hWnd)
__EXTERN INTEGER __CALL_1 GetWindowTextLengthW(INTEGER hWnd);
#define WinAPI_GetWindowTextW(hWnd, lpString, nMaxCount)	GetWindowTextW(hWnd, lpString, nMaxCount)
__EXTERN INTEGER __CALL_1 GetWindowTextW(INTEGER hWnd, INTEGER lpString, INTEGER nMaxCount);
#define WinAPI_GetWindowThreadProcessId(hWnd, lpdwProcessId)	GetWindowThreadProcessId(hWnd, lpdwProcessId)
__EXTERN INTEGER __CALL_1 GetWindowThreadProcessId(INTEGER hWnd, INTEGER *lpdwProcessId);
#define WinAPI_GetWindowWord(hWnd, nIndex)	GetWindowWord(hWnd, nIndex)
__EXTERN SHORTINT __CALL_1 GetWindowWord(INTEGER hWnd, INTEGER nIndex);
#define WinAPI_GetWindowsDirectory(lpBuffer, uSize)	GetWindowsDirectoryA(lpBuffer, uSize)
#define WinAPI_GetWindowsDirectoryA(lpBuffer, uSize)	GetWindowsDirectoryA(lpBuffer, uSize)
__EXTERN INTEGER __CALL_1 GetWindowsDirectoryA(INTEGER lpBuffer, INTEGER uSize);
#define WinAPI_GetWindowsDirectoryW(lpBuffer, uSize)	GetWindowsDirectoryW(lpBuffer, uSize)
__EXTERN INTEGER __CALL_1 GetWindowsDirectoryW(INTEGER lpBuffer, INTEGER uSize);
#define WinAPI_GetWorldTransform(p0, p1, p1__typ)	GetWorldTransform(p0, p1)
__EXTERN INTEGER __CALL_1 GetWorldTransform(INTEGER p0, WinAPI_XFORM *p1);
#define WinAPI_GlobalAddAtom(lpString)	GlobalAddAtomA(lpString)
#define WinAPI_GlobalAddAtomA(lpString)	GlobalAddAtomA(lpString)
__EXTERN SHORTINT __CALL_1 GlobalAddAtomA(INTEGER lpString);
#define WinAPI_GlobalAddAtomW(lpString)	GlobalAddAtomW(lpString)
__EXTERN SHORTINT __CALL_1 GlobalAddAtomW(INTEGER lpString);
#define WinAPI_GlobalAlloc(uFlags, dwBytes)	GlobalAlloc(uFlags, dwBytes)
__EXTERN INTEGER __CALL_1 GlobalAlloc(SET uFlags, INTEGER dwBytes);
#define WinAPI_GlobalCompact(dwMinFree)	GlobalCompact(dwMinFree)
__EXTERN INTEGER __CALL_1 GlobalCompact(INTEGER dwMinFree);
#define WinAPI_GlobalDeleteAtom(nAtom)	GlobalDeleteAtom(nAtom)
__EXTERN SHORTINT __CALL_1 GlobalDeleteAtom(SHORTINT nAtom);
#define WinAPI_GlobalFindAtom(lpString)	GlobalFindAtomA(lpString)
#define WinAPI_GlobalFindAtomA(lpString)	GlobalFindAtomA(lpString)
__EXTERN SHORTINT __CALL_1 GlobalFindAtomA(INTEGER lpString);
#define WinAPI_GlobalFindAtomW(lpString)	GlobalFindAtomW(lpString)
__EXTERN SHORTINT __CALL_1 GlobalFindAtomW(INTEGER lpString);
#define WinAPI_GlobalFix(hMem)	GlobalFix(hMem)
__EXTERN void __CALL_1 GlobalFix(INTEGER hMem);
#define WinAPI_GlobalFlags(hMem)	GlobalFlags(hMem)
__EXTERN INTEGER __CALL_1 GlobalFlags(INTEGER hMem);
#define WinAPI_GlobalFree(hMem)	GlobalFree(hMem)
__EXTERN INTEGER __CALL_1 GlobalFree(INTEGER hMem);
#define WinAPI_GlobalGetAtomName(nAtom, lpBuffer, nSize)	GlobalGetAtomNameA(nAtom, lpBuffer, nSize)
#define WinAPI_GlobalGetAtomNameA(nAtom, lpBuffer, nSize)	GlobalGetAtomNameA(nAtom, lpBuffer, nSize)
__EXTERN INTEGER __CALL_1 GlobalGetAtomNameA(SHORTINT nAtom, INTEGER lpBuffer, INTEGER nSize);
#define WinAPI_GlobalGetAtomNameW(nAtom, lpBuffer, nSize)	GlobalGetAtomNameW(nAtom, lpBuffer, nSize)
__EXTERN INTEGER __CALL_1 GlobalGetAtomNameW(SHORTINT nAtom, INTEGER lpBuffer, INTEGER nSize);
#define WinAPI_GlobalHandle(pMem)	GlobalHandle(pMem)
__EXTERN INTEGER __CALL_1 GlobalHandle(INTEGER pMem);
#define WinAPI_GlobalLock(hMem)	GlobalLock(hMem)
__EXTERN INTEGER __CALL_1 GlobalLock(INTEGER hMem);
#define WinAPI_GlobalMemoryStatus(lpBuffer, lpBuffer__typ)	GlobalMemoryStatus(lpBuffer)
__EXTERN void __CALL_1 GlobalMemoryStatus(WinAPI_MEMORYSTATUS *lpBuffer);
#define WinAPI_GlobalReAlloc(hMem, dwBytes, uFlags)	GlobalReAlloc(hMem, dwBytes, uFlags)
__EXTERN INTEGER __CALL_1 GlobalReAlloc(INTEGER hMem, INTEGER dwBytes, SET uFlags);
#define WinAPI_GlobalSize(hMem)	GlobalSize(hMem)
__EXTERN INTEGER __CALL_1 GlobalSize(INTEGER hMem);
#define WinAPI_GlobalUnWire(hMem)	GlobalUnWire(hMem)
__EXTERN INTEGER __CALL_1 GlobalUnWire(INTEGER hMem);
#define WinAPI_GlobalUnfix(hMem)	GlobalUnfix(hMem)
__EXTERN void __CALL_1 GlobalUnfix(INTEGER hMem);
#define WinAPI_GlobalUnlock(hMem)	GlobalUnlock(hMem)
__EXTERN INTEGER __CALL_1 GlobalUnlock(INTEGER hMem);
#define WinAPI_GlobalWire(hMem)	GlobalWire(hMem)
__EXTERN INTEGER __CALL_1 GlobalWire(INTEGER hMem);
#define WinAPI_GrayString(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)	GrayStringA(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)
#define WinAPI_GrayStringA(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)	GrayStringA(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)
__EXTERN INTEGER __CALL_1 GrayStringA(INTEGER hDC, INTEGER hBrush, WinAPI_GRAYSTRINGPROC lpOutputFunc, INTEGER lpData, INTEGER nCount, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight);
#define WinAPI_GrayStringW(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)	GrayStringW(hDC, hBrush, lpOutputFunc, lpData, nCount, X, Y, nWidth, nHeight)
__EXTERN INTEGER __CALL_1 GrayStringW(INTEGER hDC, INTEGER hBrush, WinAPI_GRAYSTRINGPROC lpOutputFunc, INTEGER lpData, INTEGER nCount, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight);
#define WinAPI_HeapAlloc(hHeap, dwFlags, dwBytes)	HeapAlloc(hHeap, dwFlags, dwBytes)
__EXTERN INTEGER __CALL_1 HeapAlloc(INTEGER hHeap, SET dwFlags, INTEGER dwBytes);
#define WinAPI_HeapCompact(hHeap, dwFlags)	HeapCompact(hHeap, dwFlags)
__EXTERN INTEGER __CALL_1 HeapCompact(INTEGER hHeap, SET dwFlags);
#define WinAPI_HeapCreate(flOptions, dwInitialSize, dwMaximumSize)	HeapCreate(flOptions, dwInitialSize, dwMaximumSize)
__EXTERN INTEGER __CALL_1 HeapCreate(SET flOptions, INTEGER dwInitialSize, INTEGER dwMaximumSize);
#define WinAPI_HeapDestroy(hHeap)	HeapDestroy(hHeap)
__EXTERN INTEGER __CALL_1 HeapDestroy(INTEGER hHeap);
#define WinAPI_HeapFree(hHeap, dwFlags, lpMem)	HeapFree(hHeap, dwFlags, lpMem)
__EXTERN INTEGER __CALL_1 HeapFree(INTEGER hHeap, SET dwFlags, INTEGER lpMem);
#define WinAPI_HeapLock(hHeap)	HeapLock(hHeap)
__EXTERN INTEGER __CALL_1 HeapLock(INTEGER hHeap);
#define WinAPI_HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes)	HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes)
__EXTERN INTEGER __CALL_1 HeapReAlloc(INTEGER hHeap, SET dwFlags, INTEGER lpMem, INTEGER dwBytes);
#define WinAPI_HeapSize(hHeap, dwFlags, lpMem)	HeapSize(hHeap, dwFlags, lpMem)
__EXTERN INTEGER __CALL_1 HeapSize(INTEGER hHeap, SET dwFlags, INTEGER lpMem);
#define WinAPI_HeapUnlock(hHeap)	HeapUnlock(hHeap)
__EXTERN INTEGER __CALL_1 HeapUnlock(INTEGER hHeap);
#define WinAPI_HeapValidate(hHeap, dwFlags, lpMem)	HeapValidate(hHeap, dwFlags, lpMem)
__EXTERN INTEGER __CALL_1 HeapValidate(INTEGER hHeap, SET dwFlags, INTEGER lpMem);
#define WinAPI_HeapWalk(hHeap, lpEntry, lpEntry__typ)	HeapWalk(hHeap, lpEntry)
__EXTERN INTEGER __CALL_1 HeapWalk(INTEGER hHeap, WinAPI_PROCESS_HEAP_ENTRY *lpEntry);
#define WinAPI_HideCaret(hWnd)	HideCaret(hWnd)
__EXTERN INTEGER __CALL_1 HideCaret(INTEGER hWnd);
#define WinAPI_HiliteMenuItem(hWnd, hMenu, uIDHiliteItem, uHilite)	HiliteMenuItem(hWnd, hMenu, uIDHiliteItem, uHilite)
__EXTERN INTEGER __CALL_1 HiliteMenuItem(INTEGER hWnd, INTEGER hMenu, INTEGER uIDHiliteItem, INTEGER uHilite);
#define WinAPI_ImpersonateDdeClientWindow(hWndClient, hWndServer)	ImpersonateDdeClientWindow(hWndClient, hWndServer)
__EXTERN INTEGER __CALL_1 ImpersonateDdeClientWindow(INTEGER hWndClient, INTEGER hWndServer);
#define WinAPI_ImpersonateLoggedOnUser(hToken)	ImpersonateLoggedOnUser(hToken)
__EXTERN INTEGER __CALL_1 ImpersonateLoggedOnUser(INTEGER hToken);
#define WinAPI_ImpersonateNamedPipeClient(hNamedPipe)	ImpersonateNamedPipeClient(hNamedPipe)
__EXTERN INTEGER __CALL_1 ImpersonateNamedPipeClient(INTEGER hNamedPipe);
#define WinAPI_ImpersonateSelf(ImpersonationLevel)	ImpersonateSelf(ImpersonationLevel)
__EXTERN INTEGER __CALL_1 ImpersonateSelf(INTEGER ImpersonationLevel);
#define WinAPI_InSendMessage()	InSendMessage()
__EXTERN INTEGER __CALL_1 InSendMessage(void);
#define WinAPI_InflateRect(lprc, lprc__typ, dx, dy)	InflateRect(lprc, dx, dy)
__EXTERN INTEGER __CALL_1 InflateRect(WinAPI_RECT *lprc, INTEGER dx, INTEGER dy);
#define WinAPI_InitAtomTable(nSize)	InitAtomTable(nSize)
__EXTERN INTEGER __CALL_1 InitAtomTable(INTEGER nSize);
#define WinAPI_InitializeAcl(pAcl, pAcl__typ, nAclLength, dwAclRevision)	InitializeAcl(pAcl, nAclLength, dwAclRevision)
__EXTERN INTEGER __CALL_1 InitializeAcl(WinAPI_ACL *pAcl, INTEGER nAclLength, INTEGER dwAclRevision);
#define WinAPI_InitializeCriticalSection(lpCriticalSection, lpCriticalSection__typ)	InitializeCriticalSection(lpCriticalSection)
__EXTERN void __CALL_1 InitializeCriticalSection(WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinAPI_InitializeSecurityDescriptor(pSecurityDescriptor, dwRevision)	InitializeSecurityDescriptor(pSecurityDescriptor, dwRevision)
__EXTERN INTEGER __CALL_1 InitializeSecurityDescriptor(INTEGER pSecurityDescriptor, INTEGER dwRevision);
#define WinAPI_InitializeSid(Sid, pIdentifierAuthority, pIdentifierAuthority__typ, nSubAuthorityCount)	InitializeSid(Sid, pIdentifierAuthority, nSubAuthorityCount)
__EXTERN INTEGER __CALL_1 InitializeSid(INTEGER Sid, WinAPI_SID_IDENTIFIER_AUTHORITY *pIdentifierAuthority, CHAR nSubAuthorityCount);
#define WinAPI_InitiateSystemShutdown(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)	InitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)
#define WinAPI_InitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)	InitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)
__EXTERN INTEGER __CALL_1 InitiateSystemShutdownA(INTEGER lpMachineName, INTEGER lpMessage, INTEGER dwTimeout, INTEGER bForceAppsClosed, INTEGER bRebootAfterShutdown);
#define WinAPI_InitiateSystemShutdownW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)	InitiateSystemShutdownW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown)
__EXTERN INTEGER __CALL_1 InitiateSystemShutdownW(INTEGER lpMachineName, INTEGER lpMessage, INTEGER dwTimeout, INTEGER bForceAppsClosed, INTEGER bRebootAfterShutdown);
#define WinAPI_InsertMenu(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)	InsertMenuA(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)
#define WinAPI_InsertMenuA(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)	InsertMenuA(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __CALL_1 InsertMenuA(INTEGER hMenu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, INTEGER lpNewItem);
#define WinAPI_InsertMenuItem(p0, p1, p2, p3, p3__typ)	InsertMenuItemA(p0, p1, p2, p3)
#define WinAPI_InsertMenuItemA(p0, p1, p2, p3, p3__typ)	InsertMenuItemA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 InsertMenuItemA(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOA *p3);
#define WinAPI_InsertMenuItemW(p0, p1, p2, p3, p3__typ)	InsertMenuItemW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 InsertMenuItemW(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOW *p3);
#define WinAPI_InsertMenuW(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)	InsertMenuW(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __CALL_1 InsertMenuW(INTEGER hMenu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, INTEGER lpNewItem);
#define WinAPI_Instance()	__hInstance
#define WinAPI_InterlockedCompareExchange(Destination, Exchange, Comperand)	InterlockedCompareExchange(Destination, Exchange, Comperand)
__EXTERN INTEGER __CALL_1 InterlockedCompareExchange(INTEGER Destination, INTEGER Exchange, INTEGER Comperand);
#define WinAPI_InterlockedDecrement(lpAddend)	InterlockedDecrement(lpAddend)
__EXTERN INTEGER __CALL_1 InterlockedDecrement(INTEGER *lpAddend);
#define WinAPI_InterlockedExchange(Target, Value)	InterlockedExchange(Target, Value)
__EXTERN INTEGER __CALL_1 InterlockedExchange(INTEGER *Target, INTEGER Value);
#define WinAPI_InterlockedExchangeAdd(Addend, Value)	InterlockedExchangeAdd(Addend, Value)
__EXTERN INTEGER __CALL_1 InterlockedExchangeAdd(INTEGER *Addend, INTEGER Value);
#define WinAPI_InterlockedIncrement(lpAddend)	InterlockedIncrement(lpAddend)
__EXTERN INTEGER __CALL_1 InterlockedIncrement(INTEGER *lpAddend);
#define WinAPI_IntersectClipRect(p0, p1, p2, p3, p4)	IntersectClipRect(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 IntersectClipRect(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_IntersectRect(lprcDst, lprcDst__typ, lprcSrc1, lprcSrc1__typ, lprcSrc2, lprcSrc2__typ)	IntersectRect(lprcDst, lprcSrc1, lprcSrc2)
__EXTERN INTEGER __CALL_1 IntersectRect(WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc1, WinAPI_RECT *lprcSrc2);
#define WinAPI_InvalidateRect(hWnd, lpRect, lpRect__typ, bErase)	InvalidateRect(hWnd, lpRect, bErase)
__EXTERN INTEGER __CALL_1 InvalidateRect(INTEGER hWnd, WinAPI_RECT *lpRect, INTEGER bErase);
#define WinAPI_InvalidateRgn(hWnd, hRgn, bErase)	InvalidateRgn(hWnd, hRgn, bErase)
__EXTERN INTEGER __CALL_1 InvalidateRgn(INTEGER hWnd, INTEGER hRgn, INTEGER bErase);
#define WinAPI_InvertRect(hDC, lprc, lprc__typ)	InvertRect(hDC, lprc)
__EXTERN INTEGER __CALL_1 InvertRect(INTEGER hDC, WinAPI_RECT *lprc);
#define WinAPI_InvertRgn(p0, p1)	InvertRgn(p0, p1)
__EXTERN INTEGER __CALL_1 InvertRgn(INTEGER p0, INTEGER p1);
#define WinAPI_IsBadCodePtr(lpfn)	IsBadCodePtr(lpfn)
__EXTERN INTEGER __CALL_1 IsBadCodePtr(WinAPI_FARPROC lpfn);
#define WinAPI_IsBadHugeReadPtr(lp, ucb)	IsBadHugeReadPtr(lp, ucb)
__EXTERN INTEGER __CALL_1 IsBadHugeReadPtr(INTEGER lp, INTEGER ucb);
#define WinAPI_IsBadHugeWritePtr(lp, ucb)	IsBadHugeWritePtr(lp, ucb)
__EXTERN INTEGER __CALL_1 IsBadHugeWritePtr(INTEGER lp, INTEGER ucb);
#define WinAPI_IsBadReadPtr(lp, ucb)	IsBadReadPtr(lp, ucb)
__EXTERN INTEGER __CALL_1 IsBadReadPtr(INTEGER lp, INTEGER ucb);
#define WinAPI_IsBadStringPtr(lpsz, ucchMax)	IsBadStringPtrA(lpsz, ucchMax)
#define WinAPI_IsBadStringPtrA(lpsz, ucchMax)	IsBadStringPtrA(lpsz, ucchMax)
__EXTERN INTEGER __CALL_1 IsBadStringPtrA(INTEGER lpsz, INTEGER ucchMax);
#define WinAPI_IsBadStringPtrW(lpsz, ucchMax)	IsBadStringPtrW(lpsz, ucchMax)
__EXTERN INTEGER __CALL_1 IsBadStringPtrW(INTEGER lpsz, INTEGER ucchMax);
#define WinAPI_IsBadWritePtr(lp, ucb)	IsBadWritePtr(lp, ucb)
__EXTERN INTEGER __CALL_1 IsBadWritePtr(INTEGER lp, INTEGER ucb);
#define WinAPI_IsCharAlpha(ch)	IsCharAlphaA(ch)
#define WinAPI_IsCharAlphaA(ch)	IsCharAlphaA(ch)
__EXTERN INTEGER __CALL_1 IsCharAlphaA(CHAR ch);
#define WinAPI_IsCharAlphaNumeric(ch)	IsCharAlphaNumericA(ch)
#define WinAPI_IsCharAlphaNumericA(ch)	IsCharAlphaNumericA(ch)
__EXTERN INTEGER __CALL_1 IsCharAlphaNumericA(CHAR ch);
#define WinAPI_IsCharAlphaNumericW(ch)	IsCharAlphaNumericW(ch)
__EXTERN INTEGER __CALL_1 IsCharAlphaNumericW(SHORTINT ch);
#define WinAPI_IsCharAlphaW(ch)	IsCharAlphaW(ch)
__EXTERN INTEGER __CALL_1 IsCharAlphaW(SHORTINT ch);
#define WinAPI_IsCharLower(ch)	IsCharLowerA(ch)
#define WinAPI_IsCharLowerA(ch)	IsCharLowerA(ch)
__EXTERN INTEGER __CALL_1 IsCharLowerA(CHAR ch);
#define WinAPI_IsCharLowerW(ch)	IsCharLowerW(ch)
__EXTERN INTEGER __CALL_1 IsCharLowerW(SHORTINT ch);
#define WinAPI_IsCharUpper(ch)	IsCharUpperA(ch)
#define WinAPI_IsCharUpperA(ch)	IsCharUpperA(ch)
__EXTERN INTEGER __CALL_1 IsCharUpperA(CHAR ch);
#define WinAPI_IsCharUpperW(ch)	IsCharUpperW(ch)
__EXTERN INTEGER __CALL_1 IsCharUpperW(SHORTINT ch);
#define WinAPI_IsChild(hWndParent, hWnd)	IsChild(hWndParent, hWnd)
__EXTERN INTEGER __CALL_1 IsChild(INTEGER hWndParent, INTEGER hWnd);
#define WinAPI_IsClipboardFormatAvailable(format)	IsClipboardFormatAvailable(format)
__EXTERN INTEGER __CALL_1 IsClipboardFormatAvailable(INTEGER format);
#define WinAPI_IsDBCSLeadByte(TestChar)	IsDBCSLeadByte(TestChar)
__EXTERN INTEGER __CALL_1 IsDBCSLeadByte(CHAR TestChar);
#define WinAPI_IsDBCSLeadByteEx(CodePage, TestChar)	IsDBCSLeadByteEx(CodePage, TestChar)
__EXTERN INTEGER __CALL_1 IsDBCSLeadByteEx(INTEGER CodePage, CHAR TestChar);
#define WinAPI_IsDialogMessage(hDlg, lpMsg, lpMsg__typ)	IsDialogMessageA(hDlg, lpMsg)
#define WinAPI_IsDialogMessageA(hDlg, lpMsg, lpMsg__typ)	IsDialogMessageA(hDlg, lpMsg)
__EXTERN INTEGER __CALL_1 IsDialogMessageA(INTEGER hDlg, WinAPI_MSG *lpMsg);
#define WinAPI_IsDialogMessageW(hDlg, lpMsg, lpMsg__typ)	IsDialogMessageW(hDlg, lpMsg)
__EXTERN INTEGER __CALL_1 IsDialogMessageW(INTEGER hDlg, WinAPI_MSG *lpMsg);
#define WinAPI_IsDlgButtonChecked(hDlg, nIDButton)	IsDlgButtonChecked(hDlg, nIDButton)
__EXTERN INTEGER __CALL_1 IsDlgButtonChecked(INTEGER hDlg, INTEGER nIDButton);
#define WinAPI_IsIconic(hWnd)	IsIconic(hWnd)
__EXTERN INTEGER __CALL_1 IsIconic(INTEGER hWnd);
#define WinAPI_IsMenu(hMenu)	IsMenu(hMenu)
__EXTERN INTEGER __CALL_1 IsMenu(INTEGER hMenu);
#define WinAPI_IsRectEmpty(lprc, lprc__typ)	IsRectEmpty(lprc)
__EXTERN INTEGER __CALL_1 IsRectEmpty(WinAPI_RECT *lprc);
#define WinAPI_IsTextUnicode(lpBuffer, cb, lpi)	IsTextUnicode(lpBuffer, cb, lpi)
__EXTERN INTEGER __CALL_1 IsTextUnicode(INTEGER lpBuffer, INTEGER cb, SET *lpi);
#define WinAPI_IsValidAcl(pAcl, pAcl__typ)	IsValidAcl(pAcl)
__EXTERN INTEGER __CALL_1 IsValidAcl(WinAPI_ACL *pAcl);
#define WinAPI_IsValidCodePage(CodePage)	IsValidCodePage(CodePage)
__EXTERN INTEGER __CALL_1 IsValidCodePage(INTEGER CodePage);
#define WinAPI_IsValidLocale(Locale, dwFlags)	IsValidLocale(Locale, dwFlags)
__EXTERN INTEGER __CALL_1 IsValidLocale(INTEGER Locale, SET dwFlags);
#define WinAPI_IsValidSecurityDescriptor(pSecurityDescriptor)	IsValidSecurityDescriptor(pSecurityDescriptor)
__EXTERN INTEGER __CALL_1 IsValidSecurityDescriptor(INTEGER pSecurityDescriptor);
#define WinAPI_IsValidSid(pSid)	IsValidSid(pSid)
__EXTERN INTEGER __CALL_1 IsValidSid(INTEGER pSid);
#define WinAPI_IsWindow(hWnd)	IsWindow(hWnd)
__EXTERN INTEGER __CALL_1 IsWindow(INTEGER hWnd);
#define WinAPI_IsWindowEnabled(hWnd)	IsWindowEnabled(hWnd)
__EXTERN INTEGER __CALL_1 IsWindowEnabled(INTEGER hWnd);
#define WinAPI_IsWindowUnicode(hWnd)	IsWindowUnicode(hWnd)
__EXTERN INTEGER __CALL_1 IsWindowUnicode(INTEGER hWnd);
#define WinAPI_IsWindowVisible(hWnd)	IsWindowVisible(hWnd)
__EXTERN INTEGER __CALL_1 IsWindowVisible(INTEGER hWnd);
#define WinAPI_IsZoomed(hWnd)	IsZoomed(hWnd)
__EXTERN INTEGER __CALL_1 IsZoomed(INTEGER hWnd);
#define WinAPI_KillTimer(hWnd, uIDEvent)	KillTimer(hWnd, uIDEvent)
__EXTERN INTEGER __CALL_1 KillTimer(INTEGER hWnd, INTEGER uIDEvent);
#define WinAPI_LCMapString(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
#define WinAPI_LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
__EXTERN INTEGER __CALL_1 LCMapStringA(INTEGER Locale, SET dwMapFlags, INTEGER lpSrcStr, INTEGER cchSrc, INTEGER lpDestStr, INTEGER cchDest);
#define WinAPI_LCMapStringW(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)	LCMapStringW(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest)
__EXTERN INTEGER __CALL_1 LCMapStringW(INTEGER Locale, SET dwMapFlags, INTEGER lpSrcStr, INTEGER cchSrc, INTEGER lpDestStr, INTEGER cchDest);
#define WinAPI_LPtoDP(p0, p1, p1__typ, p2)	LPtoDP(p0, p1, p2)
__EXTERN INTEGER __CALL_1 LPtoDP(INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_LZClose(p0)	LZClose(p0)
__EXTERN void __CALL_1 LZClose(INTEGER p0);
#define WinAPI_LZCopy(p0, p1)	LZCopy(p0, p1)
__EXTERN INTEGER __CALL_1 LZCopy(INTEGER p0, INTEGER p1);
#define WinAPI_LZDone()	LZDone()
__EXTERN void __CALL_1 LZDone(void);
#define WinAPI_LZInit(p0)	LZInit(p0)
__EXTERN INTEGER __CALL_1 LZInit(INTEGER p0);
#define WinAPI_LZOpenFile(p0, p1, p1__typ, p2)	LZOpenFileA(p0, p1, p2)
#define WinAPI_LZOpenFileA(p0, p1, p1__typ, p2)	LZOpenFileA(p0, p1, p2)
__EXTERN INTEGER __CALL_1 LZOpenFileA(INTEGER p0, WinAPI_OFSTRUCT *p1, SHORTINT p2);
#define WinAPI_LZOpenFileW(p0, p1, p1__typ, p2)	LZOpenFileW(p0, p1, p2)
__EXTERN INTEGER __CALL_1 LZOpenFileW(INTEGER p0, WinAPI_OFSTRUCT *p1, SHORTINT p2);
#define WinAPI_LZRead(p0, p1, p2)	LZRead(p0, p1, p2)
__EXTERN INTEGER __CALL_1 LZRead(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_LZSeek(p0, p1, p2)	LZSeek(p0, p1, p2)
__EXTERN INTEGER __CALL_1 LZSeek(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_LZStart()	LZStart()
__EXTERN INTEGER __CALL_1 LZStart(void);
#define WinAPI_LeaveCriticalSection(lpCriticalSection, lpCriticalSection__typ)	LeaveCriticalSection(lpCriticalSection)
__EXTERN void __CALL_1 LeaveCriticalSection(WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinAPI_LineDDA(p0, p1, p2, p3, p4, p5)	LineDDA(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 LineDDA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_LINEDDAPROC p4, INTEGER p5);
#define WinAPI_LineTo(p0, p1, p2)	LineTo(p0, p1, p2)
__EXTERN INTEGER __CALL_1 LineTo(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_LoadAccelerators(hInstance, lpTableName)	LoadAcceleratorsA(hInstance, lpTableName)
#define WinAPI_LoadAcceleratorsA(hInstance, lpTableName)	LoadAcceleratorsA(hInstance, lpTableName)
__EXTERN INTEGER __CALL_1 LoadAcceleratorsA(INTEGER hInstance, INTEGER lpTableName);
#define WinAPI_LoadAcceleratorsW(hInstance, lpTableName)	LoadAcceleratorsW(hInstance, lpTableName)
__EXTERN INTEGER __CALL_1 LoadAcceleratorsW(INTEGER hInstance, INTEGER lpTableName);
#define WinAPI_LoadBitmap(hInstance, lpBitmapName)	LoadBitmapA(hInstance, lpBitmapName)
#define WinAPI_LoadBitmapA(hInstance, lpBitmapName)	LoadBitmapA(hInstance, lpBitmapName)
__EXTERN INTEGER __CALL_1 LoadBitmapA(INTEGER hInstance, INTEGER lpBitmapName);
#define WinAPI_LoadBitmapW(hInstance, lpBitmapName)	LoadBitmapW(hInstance, lpBitmapName)
__EXTERN INTEGER __CALL_1 LoadBitmapW(INTEGER hInstance, INTEGER lpBitmapName);
#define WinAPI_LoadCursor(hInstance, lpCursorName)	LoadCursorA(hInstance, lpCursorName)
#define WinAPI_LoadCursorA(hInstance, lpCursorName)	LoadCursorA(hInstance, lpCursorName)
__EXTERN INTEGER __CALL_1 LoadCursorA(INTEGER hInstance, INTEGER lpCursorName);
#define WinAPI_LoadCursorFromFile(lpFileName)	LoadCursorFromFileA(lpFileName)
#define WinAPI_LoadCursorFromFileA(lpFileName)	LoadCursorFromFileA(lpFileName)
__EXTERN INTEGER __CALL_1 LoadCursorFromFileA(INTEGER lpFileName);
#define WinAPI_LoadCursorFromFileW(lpFileName)	LoadCursorFromFileW(lpFileName)
__EXTERN INTEGER __CALL_1 LoadCursorFromFileW(INTEGER lpFileName);
#define WinAPI_LoadCursorW(hInstance, lpCursorName)	LoadCursorW(hInstance, lpCursorName)
__EXTERN INTEGER __CALL_1 LoadCursorW(INTEGER hInstance, INTEGER lpCursorName);
#define WinAPI_LoadIcon(hInstance, lpIconName)	LoadIconA(hInstance, lpIconName)
#define WinAPI_LoadIconA(hInstance, lpIconName)	LoadIconA(hInstance, lpIconName)
__EXTERN INTEGER __CALL_1 LoadIconA(INTEGER hInstance, INTEGER lpIconName);
#define WinAPI_LoadIconW(hInstance, lpIconName)	LoadIconW(hInstance, lpIconName)
__EXTERN INTEGER __CALL_1 LoadIconW(INTEGER hInstance, INTEGER lpIconName);
#define WinAPI_LoadImage(p0, p1, p2, p3, p4, p5)	LoadImageA(p0, p1, p2, p3, p4, p5)
#define WinAPI_LoadImageA(p0, p1, p2, p3, p4, p5)	LoadImageA(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 LoadImageA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
#define WinAPI_LoadImageW(p0, p1, p2, p3, p4, p5)	LoadImageW(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 LoadImageW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
#define WinAPI_LoadKeyboardLayout(pwszKLID, Flags)	LoadKeyboardLayoutA(pwszKLID, Flags)
#define WinAPI_LoadKeyboardLayoutA(pwszKLID, Flags)	LoadKeyboardLayoutA(pwszKLID, Flags)
__EXTERN INTEGER __CALL_1 LoadKeyboardLayoutA(INTEGER pwszKLID, SET Flags);
#define WinAPI_LoadKeyboardLayoutW(pwszKLID, Flags)	LoadKeyboardLayoutW(pwszKLID, Flags)
__EXTERN INTEGER __CALL_1 LoadKeyboardLayoutW(INTEGER pwszKLID, SET Flags);
#define WinAPI_LoadLibrary(lpLibFileName)	LoadLibraryA(lpLibFileName)
#define WinAPI_LoadLibraryA(lpLibFileName)	LoadLibraryA(lpLibFileName)
__EXTERN INTEGER __CALL_1 LoadLibraryA(INTEGER lpLibFileName);
#define WinAPI_LoadLibraryEx(lpLibFileName, hFile, dwFlags)	LoadLibraryExA(lpLibFileName, hFile, dwFlags)
#define WinAPI_LoadLibraryExA(lpLibFileName, hFile, dwFlags)	LoadLibraryExA(lpLibFileName, hFile, dwFlags)
__EXTERN INTEGER __CALL_1 LoadLibraryExA(INTEGER lpLibFileName, INTEGER hFile, SET dwFlags);
#define WinAPI_LoadLibraryExW(lpLibFileName, hFile, dwFlags)	LoadLibraryExW(lpLibFileName, hFile, dwFlags)
__EXTERN INTEGER __CALL_1 LoadLibraryExW(INTEGER lpLibFileName, INTEGER hFile, SET dwFlags);
#define WinAPI_LoadLibraryW(lpLibFileName)	LoadLibraryW(lpLibFileName)
__EXTERN INTEGER __CALL_1 LoadLibraryW(INTEGER lpLibFileName);
#define WinAPI_LoadMenu(hInstance, lpMenuName)	LoadMenuA(hInstance, lpMenuName)
#define WinAPI_LoadMenuA(hInstance, lpMenuName)	LoadMenuA(hInstance, lpMenuName)
__EXTERN INTEGER __CALL_1 LoadMenuA(INTEGER hInstance, INTEGER lpMenuName);
#define WinAPI_LoadMenuIndirect(lpMenuTemplate)	LoadMenuIndirectA(lpMenuTemplate)
#define WinAPI_LoadMenuIndirectA(lpMenuTemplate)	LoadMenuIndirectA(lpMenuTemplate)
__EXTERN INTEGER __CALL_1 LoadMenuIndirectA(WinAPI_PtrMENUTEMPLATEA lpMenuTemplate);
#define WinAPI_LoadMenuIndirectW(lpMenuTemplate)	LoadMenuIndirectW(lpMenuTemplate)
__EXTERN INTEGER __CALL_1 LoadMenuIndirectW(WinAPI_PtrMENUTEMPLATEW lpMenuTemplate);
#define WinAPI_LoadMenuW(hInstance, lpMenuName)	LoadMenuW(hInstance, lpMenuName)
__EXTERN INTEGER __CALL_1 LoadMenuW(INTEGER hInstance, INTEGER lpMenuName);
#define WinAPI_LoadModule(lpModuleName, lpParameterBlock)	LoadModule(lpModuleName, lpParameterBlock)
__EXTERN INTEGER __CALL_1 LoadModule(INTEGER lpModuleName, INTEGER lpParameterBlock);
#define WinAPI_LoadResource(hModule, hResInfo)	LoadResource(hModule, hResInfo)
__EXTERN INTEGER __CALL_1 LoadResource(INTEGER hModule, INTEGER hResInfo);
#define WinAPI_LoadString(hInstance, uID, lpBuffer, nBufferMax)	LoadStringA(hInstance, uID, lpBuffer, nBufferMax)
#define WinAPI_LoadStringA(hInstance, uID, lpBuffer, nBufferMax)	LoadStringA(hInstance, uID, lpBuffer, nBufferMax)
__EXTERN INTEGER __CALL_1 LoadStringA(INTEGER hInstance, INTEGER uID, INTEGER lpBuffer, INTEGER nBufferMax);
#define WinAPI_LoadStringW(hInstance, uID, lpBuffer, nBufferMax)	LoadStringW(hInstance, uID, lpBuffer, nBufferMax)
__EXTERN INTEGER __CALL_1 LoadStringW(INTEGER hInstance, INTEGER uID, INTEGER lpBuffer, INTEGER nBufferMax);
#define WinAPI_LocalAlloc(uFlags, uBytes)	LocalAlloc(uFlags, uBytes)
__EXTERN INTEGER __CALL_1 LocalAlloc(SET uFlags, INTEGER uBytes);
#define WinAPI_LocalCompact(uMinFree)	LocalCompact(uMinFree)
__EXTERN INTEGER __CALL_1 LocalCompact(INTEGER uMinFree);
#define WinAPI_LocalFileTimeToFileTime(lpLocalFileTime, lpLocalFileTime__typ, lpFileTime, lpFileTime__typ)	LocalFileTimeToFileTime(lpLocalFileTime, lpFileTime)
__EXTERN INTEGER __CALL_1 LocalFileTimeToFileTime(WinAPI_FILETIME *lpLocalFileTime, WinAPI_FILETIME *lpFileTime);
#define WinAPI_LocalFlags(hMem)	LocalFlags(hMem)
__EXTERN INTEGER __CALL_1 LocalFlags(INTEGER hMem);
#define WinAPI_LocalFree(hMem)	LocalFree(hMem)
__EXTERN INTEGER __CALL_1 LocalFree(INTEGER hMem);
#define WinAPI_LocalHandle(pMem)	LocalHandle(pMem)
__EXTERN INTEGER __CALL_1 LocalHandle(INTEGER pMem);
#define WinAPI_LocalLock(hMem)	LocalLock(hMem)
__EXTERN INTEGER __CALL_1 LocalLock(INTEGER hMem);
#define WinAPI_LocalReAlloc(hMem, uBytes, uFlags)	LocalReAlloc(hMem, uBytes, uFlags)
__EXTERN INTEGER __CALL_1 LocalReAlloc(INTEGER hMem, INTEGER uBytes, SET uFlags);
#define WinAPI_LocalShrink(hMem, cbNewSize)	LocalShrink(hMem, cbNewSize)
__EXTERN INTEGER __CALL_1 LocalShrink(INTEGER hMem, INTEGER cbNewSize);
#define WinAPI_LocalSize(hMem)	LocalSize(hMem)
__EXTERN INTEGER __CALL_1 LocalSize(INTEGER hMem);
#define WinAPI_LocalUnlock(hMem)	LocalUnlock(hMem)
__EXTERN INTEGER __CALL_1 LocalUnlock(INTEGER hMem);
#define WinAPI_LockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh)	LockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh)
__EXTERN INTEGER __CALL_1 LockFile(INTEGER hFile, INTEGER dwFileOffsetLow, INTEGER dwFileOffsetHigh, INTEGER nNumberOfBytesToLockLow, INTEGER nNumberOfBytesToLockHigh);
#define WinAPI_LockFileEx(hFile, dwFlags, dwReserved, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh, lpOverlapped, lpOverlapped__typ)	LockFileEx(hFile, dwFlags, dwReserved, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh, lpOverlapped)
__EXTERN INTEGER __CALL_1 LockFileEx(INTEGER hFile, SET dwFlags, INTEGER dwReserved, INTEGER nNumberOfBytesToLockLow, INTEGER nNumberOfBytesToLockHigh, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_LockResource(hResData)	LockResource(hResData)
__EXTERN INTEGER __CALL_1 LockResource(INTEGER hResData);
#define WinAPI_LockServiceDatabase(hSCManager)	LockServiceDatabase(hSCManager)
__EXTERN INTEGER __CALL_1 LockServiceDatabase(INTEGER hSCManager);
#define WinAPI_LockWindowUpdate(hWndLock)	LockWindowUpdate(hWndLock)
__EXTERN INTEGER __CALL_1 LockWindowUpdate(INTEGER hWndLock);
#define WinAPI_LogonUser(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)	LogonUserA(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)
#define WinAPI_LogonUserA(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)	LogonUserA(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)
__EXTERN INTEGER __CALL_1 LogonUserA(INTEGER lpszUsername, INTEGER lpszDomain, INTEGER lpszPassword, INTEGER dwLogonType, INTEGER dwLogonProvider, INTEGER *phToken);
#define WinAPI_LogonUserW(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)	LogonUserW(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken)
__EXTERN INTEGER __CALL_1 LogonUserW(INTEGER lpszUsername, INTEGER lpszDomain, INTEGER lpszPassword, INTEGER dwLogonType, INTEGER dwLogonProvider, INTEGER *phToken);
#define WinAPI_LookupAccountName(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountNameA(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)
#define WinAPI_LookupAccountNameA(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountNameA(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)
__EXTERN INTEGER __CALL_1 LookupAccountNameA(INTEGER lpSystemName, INTEGER lpAccountName, INTEGER Sid, INTEGER *cbSid, INTEGER ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
#define WinAPI_LookupAccountNameW(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountNameW(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cbReferencedDomainName, peUse)
__EXTERN INTEGER __CALL_1 LookupAccountNameW(INTEGER lpSystemName, INTEGER lpAccountName, INTEGER Sid, INTEGER *cbSid, INTEGER ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
#define WinAPI_LookupAccountSid(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountSidA(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)
#define WinAPI_LookupAccountSidA(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountSidA(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)
__EXTERN INTEGER __CALL_1 LookupAccountSidA(INTEGER lpSystemName, INTEGER Sid, INTEGER Name, INTEGER *cbName, INTEGER ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
#define WinAPI_LookupAccountSidW(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)	LookupAccountSidW(lpSystemName, Sid, Name, cbName, ReferencedDomainName, cbReferencedDomainName, peUse)
__EXTERN INTEGER __CALL_1 LookupAccountSidW(INTEGER lpSystemName, INTEGER Sid, INTEGER Name, INTEGER *cbName, INTEGER ReferencedDomainName, INTEGER *cbReferencedDomainName, INTEGER *peUse);
#define WinAPI_LookupIconIdFromDirectory(presbits, fIcon)	LookupIconIdFromDirectory(presbits, fIcon)
__EXTERN INTEGER __CALL_1 LookupIconIdFromDirectory(CHAR *presbits, INTEGER fIcon);
#define WinAPI_LookupIconIdFromDirectoryEx(presbits, fIcon, cxDesired, cyDesired, Flags)	LookupIconIdFromDirectoryEx(presbits, fIcon, cxDesired, cyDesired, Flags)
__EXTERN INTEGER __CALL_1 LookupIconIdFromDirectoryEx(CHAR *presbits, INTEGER fIcon, INTEGER cxDesired, INTEGER cyDesired, SET Flags);
#define WinAPI_LookupPrivilegeDisplayName(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)	LookupPrivilegeDisplayNameA(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)
#define WinAPI_LookupPrivilegeDisplayNameA(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)	LookupPrivilegeDisplayNameA(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)
__EXTERN INTEGER __CALL_1 LookupPrivilegeDisplayNameA(INTEGER lpSystemName, INTEGER lpName, INTEGER lpDisplayName, INTEGER *cbDisplayName, INTEGER *lpLanguageId);
#define WinAPI_LookupPrivilegeDisplayNameW(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)	LookupPrivilegeDisplayNameW(lpSystemName, lpName, lpDisplayName, cbDisplayName, lpLanguageId)
__EXTERN INTEGER __CALL_1 LookupPrivilegeDisplayNameW(INTEGER lpSystemName, INTEGER lpName, INTEGER lpDisplayName, INTEGER *cbDisplayName, INTEGER *lpLanguageId);
#define WinAPI_LookupPrivilegeName(lpSystemName, lpLuid, lpName, cbName)	LookupPrivilegeNameA(lpSystemName, lpLuid, lpName, cbName)
#define WinAPI_LookupPrivilegeNameA(lpSystemName, lpLuid, lpName, cbName)	LookupPrivilegeNameA(lpSystemName, lpLuid, lpName, cbName)
__EXTERN INTEGER __CALL_1 LookupPrivilegeNameA(INTEGER lpSystemName, LONGINT *lpLuid, INTEGER lpName, INTEGER *cbName);
#define WinAPI_LookupPrivilegeNameW(lpSystemName, lpLuid, lpName, cbName)	LookupPrivilegeNameW(lpSystemName, lpLuid, lpName, cbName)
__EXTERN INTEGER __CALL_1 LookupPrivilegeNameW(INTEGER lpSystemName, LONGINT *lpLuid, INTEGER lpName, INTEGER *cbName);
#define WinAPI_LookupPrivilegeValue(lpSystemName, lpName, lpLuid)	LookupPrivilegeValueA(lpSystemName, lpName, lpLuid)
#define WinAPI_LookupPrivilegeValueA(lpSystemName, lpName, lpLuid)	LookupPrivilegeValueA(lpSystemName, lpName, lpLuid)
__EXTERN INTEGER __CALL_1 LookupPrivilegeValueA(INTEGER lpSystemName, INTEGER lpName, LONGINT *lpLuid);
#define WinAPI_LookupPrivilegeValueW(lpSystemName, lpName, lpLuid)	LookupPrivilegeValueW(lpSystemName, lpName, lpLuid)
__EXTERN INTEGER __CALL_1 LookupPrivilegeValueW(INTEGER lpSystemName, INTEGER lpName, LONGINT *lpLuid);
#define WinAPI_MakeAbsoluteSD(pSelfRelativeSecurityDescriptor, pAbsoluteSecurityDescriptor, lpdwAbsoluteSecurityDescriptorSize, pDacl, pDacl__typ, lpdwDaclSize, pSacl, pSacl__typ, lpdwSaclSize, pOwner, lpdwOwnerSize, pPrimaryGroup, lpdwPrimaryGroupSize)	MakeAbsoluteSD(pSelfRelativeSecurityDescriptor, pAbsoluteSecurityDescriptor, lpdwAbsoluteSecurityDescriptorSize, pDacl, lpdwDaclSize, pSacl, lpdwSaclSize, pOwner, lpdwOwnerSize, pPrimaryGroup, lpdwPrimaryGroupSize)
__EXTERN INTEGER __CALL_1 MakeAbsoluteSD(INTEGER pSelfRelativeSecurityDescriptor, INTEGER pAbsoluteSecurityDescriptor, INTEGER *lpdwAbsoluteSecurityDescriptorSize, WinAPI_ACL *pDacl, INTEGER *lpdwDaclSize, WinAPI_ACL *pSacl, INTEGER *lpdwSaclSize, INTEGER pOwner, INTEGER *lpdwOwnerSize, INTEGER pPrimaryGroup, INTEGER *lpdwPrimaryGroupSize);
#define WinAPI_MakeSelfRelativeSD(pAbsoluteSecurityDescriptor, pSelfRelativeSecurityDescriptor, lpdwBufferLength)	MakeSelfRelativeSD(pAbsoluteSecurityDescriptor, pSelfRelativeSecurityDescriptor, lpdwBufferLength)
__EXTERN INTEGER __CALL_1 MakeSelfRelativeSD(INTEGER pAbsoluteSecurityDescriptor, INTEGER pSelfRelativeSecurityDescriptor, INTEGER *lpdwBufferLength);
#define WinAPI_MapDialogRect(hDlg, lpRect, lpRect__typ)	MapDialogRect(hDlg, lpRect)
__EXTERN INTEGER __CALL_1 MapDialogRect(INTEGER hDlg, WinAPI_RECT *lpRect);
#define WinAPI_MapGenericMask(AccessMask, GenericMapping, GenericMapping__typ)	MapGenericMask(AccessMask, GenericMapping)
__EXTERN void __CALL_1 MapGenericMask(INTEGER *AccessMask, WinAPI_GENERIC_MAPPING *GenericMapping);
#define WinAPI_MapViewOfFile(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap)	MapViewOfFile(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap)
__EXTERN INTEGER __CALL_1 MapViewOfFile(INTEGER hFileMappingObject, SET dwDesiredAccess, INTEGER dwFileOffsetHigh, INTEGER dwFileOffsetLow, INTEGER dwNumberOfBytesToMap);
#define WinAPI_MapViewOfFileEx(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress)	MapViewOfFileEx(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress)
__EXTERN INTEGER __CALL_1 MapViewOfFileEx(INTEGER hFileMappingObject, SET dwDesiredAccess, INTEGER dwFileOffsetHigh, INTEGER dwFileOffsetLow, INTEGER dwNumberOfBytesToMap, INTEGER lpBaseAddress);
#define WinAPI_MapVirtualKey(uCode, uMapType)	MapVirtualKeyA(uCode, uMapType)
#define WinAPI_MapVirtualKeyA(uCode, uMapType)	MapVirtualKeyA(uCode, uMapType)
__EXTERN INTEGER __CALL_1 MapVirtualKeyA(INTEGER uCode, INTEGER uMapType);
#define WinAPI_MapVirtualKeyEx(uCode, uMapType, dwhkl)	MapVirtualKeyExA(uCode, uMapType, dwhkl)
#define WinAPI_MapVirtualKeyExA(uCode, uMapType, dwhkl)	MapVirtualKeyExA(uCode, uMapType, dwhkl)
__EXTERN INTEGER __CALL_1 MapVirtualKeyExA(INTEGER uCode, INTEGER uMapType, INTEGER dwhkl);
#define WinAPI_MapVirtualKeyExW(uCode, uMapType, dwhkl)	MapVirtualKeyExW(uCode, uMapType, dwhkl)
__EXTERN INTEGER __CALL_1 MapVirtualKeyExW(INTEGER uCode, INTEGER uMapType, INTEGER dwhkl);
#define WinAPI_MapVirtualKeyW(uCode, uMapType)	MapVirtualKeyW(uCode, uMapType)
__EXTERN INTEGER __CALL_1 MapVirtualKeyW(INTEGER uCode, INTEGER uMapType);
#define WinAPI_MapWindowPoints(hWndFrom, hWndTo, lpPoints, lpPoints__typ, cPoints)	MapWindowPoints(hWndFrom, hWndTo, lpPoints, cPoints)
__EXTERN INTEGER __CALL_1 MapWindowPoints(INTEGER hWndFrom, INTEGER hWndTo, WinAPI_POINT *lpPoints, INTEGER cPoints);
#define WinAPI_MaskBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)	MaskBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)
__EXTERN INTEGER __CALL_1 MaskBlt(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10, INTEGER p11);
#define WinAPI_MenuItemFromPoint(hWnd, hMenu, ptScreen)	MenuItemFromPoint(hWnd, hMenu, ptScreen)
__EXTERN INTEGER __CALL_1 MenuItemFromPoint(INTEGER hWnd, INTEGER hMenu, WinAPI_POINT ptScreen);
#define WinAPI_MessageBeep(uType)	MessageBeep(uType)
__EXTERN INTEGER __CALL_1 MessageBeep(SET uType);
#define WinAPI_MessageBox(hWnd, lpText, lpCaption, uType)	MessageBoxA(hWnd, lpText, lpCaption, uType)
#define WinAPI_MessageBoxA(hWnd, lpText, lpCaption, uType)	MessageBoxA(hWnd, lpText, lpCaption, uType)
__EXTERN INTEGER __CALL_1 MessageBoxA(INTEGER hWnd, INTEGER lpText, INTEGER lpCaption, SET uType);
#define WinAPI_MessageBoxEx(hWnd, lpText, lpCaption, uType, wLanguageId)	MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId)
#define WinAPI_MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId)	MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId)
__EXTERN INTEGER __CALL_1 MessageBoxExA(INTEGER hWnd, INTEGER lpText, INTEGER lpCaption, SET uType, SHORTINT wLanguageId);
#define WinAPI_MessageBoxExW(hWnd, lpText, lpCaption, uType, wLanguageId)	MessageBoxExW(hWnd, lpText, lpCaption, uType, wLanguageId)
__EXTERN INTEGER __CALL_1 MessageBoxExW(INTEGER hWnd, INTEGER lpText, INTEGER lpCaption, SET uType, SHORTINT wLanguageId);
#define WinAPI_MessageBoxIndirect(p0, p0__typ)	MessageBoxIndirectA(p0)
#define WinAPI_MessageBoxIndirectA(p0, p0__typ)	MessageBoxIndirectA(p0)
__EXTERN INTEGER __CALL_1 MessageBoxIndirectA(WinAPI_MSGBOXPARAMSA *p0);
#define WinAPI_MessageBoxIndirectW(p0, p0__typ)	MessageBoxIndirectW(p0)
__EXTERN INTEGER __CALL_1 MessageBoxIndirectW(WinAPI_MSGBOXPARAMSW *p0);
#define WinAPI_MessageBoxW(hWnd, lpText, lpCaption, uType)	MessageBoxW(hWnd, lpText, lpCaption, uType)
__EXTERN INTEGER __CALL_1 MessageBoxW(INTEGER hWnd, INTEGER lpText, INTEGER lpCaption, SET uType);
#define WinAPI_ModifyMenu(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)	ModifyMenuA(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)
#define WinAPI_ModifyMenuA(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)	ModifyMenuA(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __CALL_1 ModifyMenuA(INTEGER hMnu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, INTEGER lpNewItem);
#define WinAPI_ModifyMenuW(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)	ModifyMenuW(hMnu, uPosition, uFlags, uIDNewItem, lpNewItem)
__EXTERN INTEGER __CALL_1 ModifyMenuW(INTEGER hMnu, INTEGER uPosition, SET uFlags, INTEGER uIDNewItem, INTEGER lpNewItem);
#define WinAPI_ModifyWorldTransform(p0, p1, p1__typ, p2)	ModifyWorldTransform(p0, p1, p2)
__EXTERN INTEGER __CALL_1 ModifyWorldTransform(INTEGER p0, WinAPI_XFORM *p1, INTEGER p2);
#define WinAPI_MoveFile(lpExistingFileName, lpNewFileName)	MoveFileA(lpExistingFileName, lpNewFileName)
#define WinAPI_MoveFileA(lpExistingFileName, lpNewFileName)	MoveFileA(lpExistingFileName, lpNewFileName)
__EXTERN INTEGER __CALL_1 MoveFileA(INTEGER lpExistingFileName, INTEGER lpNewFileName);
#define WinAPI_MoveFileEx(lpExistingFileName, lpNewFileName, dwFlags)	MoveFileExA(lpExistingFileName, lpNewFileName, dwFlags)
#define WinAPI_MoveFileExA(lpExistingFileName, lpNewFileName, dwFlags)	MoveFileExA(lpExistingFileName, lpNewFileName, dwFlags)
__EXTERN INTEGER __CALL_1 MoveFileExA(INTEGER lpExistingFileName, INTEGER lpNewFileName, SET dwFlags);
#define WinAPI_MoveFileExW(lpExistingFileName, lpNewFileName, dwFlags)	MoveFileExW(lpExistingFileName, lpNewFileName, dwFlags)
__EXTERN INTEGER __CALL_1 MoveFileExW(INTEGER lpExistingFileName, INTEGER lpNewFileName, SET dwFlags);
#define WinAPI_MoveFileW(lpExistingFileName, lpNewFileName)	MoveFileW(lpExistingFileName, lpNewFileName)
__EXTERN INTEGER __CALL_1 MoveFileW(INTEGER lpExistingFileName, INTEGER lpNewFileName);
#define WinAPI_MoveToEx(p0, p1, p2, p3, p3__typ)	MoveToEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 MoveToEx(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_MoveWindow(hWnd, X, Y, nWidth, nHeight, bRepaint)	MoveWindow(hWnd, X, Y, nWidth, nHeight, bRepaint)
__EXTERN INTEGER __CALL_1 MoveWindow(INTEGER hWnd, INTEGER X, INTEGER Y, INTEGER nWidth, INTEGER nHeight, INTEGER bRepaint);
#define WinAPI_MsgWaitForMultipleObjects(nCount, pHandles, fWaitAll, dwMilliseconds, dwWakeMask)	MsgWaitForMultipleObjects(nCount, pHandles, fWaitAll, dwMilliseconds, dwWakeMask)
__EXTERN INTEGER __CALL_1 MsgWaitForMultipleObjects(INTEGER nCount, INTEGER *pHandles, INTEGER fWaitAll, INTEGER dwMilliseconds, INTEGER dwWakeMask);
#define WinAPI_MsgWaitForMultipleObjectsEx(nCount, pHandles, dwMilliseconds, dwWakeMask, dwFlags)	MsgWaitForMultipleObjectsEx(nCount, pHandles, dwMilliseconds, dwWakeMask, dwFlags)
__EXTERN INTEGER __CALL_1 MsgWaitForMultipleObjectsEx(INTEGER nCount, INTEGER *pHandles, INTEGER dwMilliseconds, INTEGER dwWakeMask, SET dwFlags);
#define WinAPI_MulDiv(nNumber, nNumerator, nDenominator)	MulDiv(nNumber, nNumerator, nDenominator)
__EXTERN INTEGER __CALL_1 MulDiv(INTEGER nNumber, INTEGER nNumerator, INTEGER nDenominator);
#define WinAPI_MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cchMultiByte, lpWideCharStr, cchWideChar)	MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cchMultiByte, lpWideCharStr, cchWideChar)
__EXTERN INTEGER __CALL_1 MultiByteToWideChar(INTEGER CodePage, SET dwFlags, INTEGER lpMultiByteStr, INTEGER cchMultiByte, INTEGER lpWideCharStr, INTEGER cchWideChar);
#define WinAPI_NotifyBootConfigStatus(BootAcceptable)	NotifyBootConfigStatus(BootAcceptable)
__EXTERN INTEGER __CALL_1 NotifyBootConfigStatus(INTEGER BootAcceptable);
#define WinAPI_NotifyChangeEventLog(hEventLog, hEvent)	NotifyChangeEventLog(hEventLog, hEvent)
__EXTERN INTEGER __CALL_1 NotifyChangeEventLog(INTEGER hEventLog, INTEGER hEvent);
#define WinAPI_ObjectCloseAuditAlarm(SubsystemName, HandleId, GenerateOnClose)	ObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose)
#define WinAPI_ObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose)	ObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose)
__EXTERN INTEGER __CALL_1 ObjectCloseAuditAlarmA(INTEGER SubsystemName, INTEGER HandleId, INTEGER GenerateOnClose);
#define WinAPI_ObjectCloseAuditAlarmW(SubsystemName, HandleId, GenerateOnClose)	ObjectCloseAuditAlarmW(SubsystemName, HandleId, GenerateOnClose)
__EXTERN INTEGER __CALL_1 ObjectCloseAuditAlarmW(INTEGER SubsystemName, INTEGER HandleId, INTEGER GenerateOnClose);
#define WinAPI_ObjectOpenAuditAlarm(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, Privileges__typ, ObjectCreation, AccessGranted, GenerateOnClose)	ObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)
#define WinAPI_ObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, Privileges__typ, ObjectCreation, AccessGranted, GenerateOnClose)	ObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)
__EXTERN INTEGER __CALL_1 ObjectOpenAuditAlarmA(INTEGER SubsystemName, INTEGER HandleId, INTEGER ObjectTypeName, INTEGER ObjectName, INTEGER pSecurityDescriptor, INTEGER ClientToken, SET DesiredAccess, INTEGER GrantedAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER ObjectCreation, INTEGER AccessGranted, INTEGER *GenerateOnClose);
#define WinAPI_ObjectOpenAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, Privileges__typ, ObjectCreation, AccessGranted, GenerateOnClose)	ObjectOpenAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose)
__EXTERN INTEGER __CALL_1 ObjectOpenAuditAlarmW(INTEGER SubsystemName, INTEGER HandleId, INTEGER ObjectTypeName, INTEGER ObjectName, INTEGER pSecurityDescriptor, INTEGER ClientToken, SET DesiredAccess, INTEGER GrantedAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER ObjectCreation, INTEGER AccessGranted, INTEGER *GenerateOnClose);
#define WinAPI_ObjectPrivilegeAuditAlarm(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, Privileges__typ, AccessGranted)	ObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)
#define WinAPI_ObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, Privileges__typ, AccessGranted)	ObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)
__EXTERN INTEGER __CALL_1 ObjectPrivilegeAuditAlarmA(INTEGER SubsystemName, INTEGER HandleId, INTEGER ClientToken, SET DesiredAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
#define WinAPI_ObjectPrivilegeAuditAlarmW(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, Privileges__typ, AccessGranted)	ObjectPrivilegeAuditAlarmW(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted)
__EXTERN INTEGER __CALL_1 ObjectPrivilegeAuditAlarmW(INTEGER SubsystemName, INTEGER HandleId, INTEGER ClientToken, SET DesiredAccess, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
#define WinAPI_OemKeyScan(wOemChar)	OemKeyScan(wOemChar)
__EXTERN INTEGER __CALL_1 OemKeyScan(SHORTINT wOemChar);
#define WinAPI_OemToAnsi(lpszSrc, lpszDst)	OemToCharA(lpszSrc, lpszDst)
#define WinAPI_OemToAnsiBuff(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinAPI_OemToChar(lpszSrc, lpszDst)	OemToCharA(lpszSrc, lpszDst)
#define WinAPI_OemToCharA(lpszSrc, lpszDst)	OemToCharA(lpszSrc, lpszDst)
__EXTERN INTEGER __CALL_1 OemToCharA(INTEGER lpszSrc, INTEGER lpszDst);
#define WinAPI_OemToCharBuff(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)
#define WinAPI_OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffA(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __CALL_1 OemToCharBuffA(INTEGER lpszSrc, INTEGER lpszDst, INTEGER cchDstLength);
#define WinAPI_OemToCharBuffW(lpszSrc, lpszDst, cchDstLength)	OemToCharBuffW(lpszSrc, lpszDst, cchDstLength)
__EXTERN INTEGER __CALL_1 OemToCharBuffW(INTEGER lpszSrc, INTEGER lpszDst, INTEGER cchDstLength);
#define WinAPI_OemToCharW(lpszSrc, lpszDst)	OemToCharW(lpszSrc, lpszDst)
__EXTERN INTEGER __CALL_1 OemToCharW(INTEGER lpszSrc, INTEGER lpszDst);
#define WinAPI_OffsetClipRgn(p0, p1, p2)	OffsetClipRgn(p0, p1, p2)
__EXTERN INTEGER __CALL_1 OffsetClipRgn(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_OffsetRect(lprc, lprc__typ, dx, dy)	OffsetRect(lprc, dx, dy)
__EXTERN INTEGER __CALL_1 OffsetRect(WinAPI_RECT *lprc, INTEGER dx, INTEGER dy);
#define WinAPI_OffsetRgn(p0, p1, p2)	OffsetRgn(p0, p1, p2)
__EXTERN INTEGER __CALL_1 OffsetRgn(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_OffsetViewportOrgEx(p0, p1, p2, p3, p3__typ)	OffsetViewportOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 OffsetViewportOrgEx(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_OffsetWindowOrgEx(p0, p1, p2, p3, p3__typ)	OffsetWindowOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 OffsetWindowOrgEx(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_OpenBackupEventLog(lpUNCServerName, lpFileName)	OpenBackupEventLogA(lpUNCServerName, lpFileName)
#define WinAPI_OpenBackupEventLogA(lpUNCServerName, lpFileName)	OpenBackupEventLogA(lpUNCServerName, lpFileName)
__EXTERN INTEGER __CALL_1 OpenBackupEventLogA(INTEGER lpUNCServerName, INTEGER lpFileName);
#define WinAPI_OpenBackupEventLogW(lpUNCServerName, lpFileName)	OpenBackupEventLogW(lpUNCServerName, lpFileName)
__EXTERN INTEGER __CALL_1 OpenBackupEventLogW(INTEGER lpUNCServerName, INTEGER lpFileName);
#define WinAPI_OpenClipboard(hWndNewOwner)	OpenClipboard(hWndNewOwner)
__EXTERN INTEGER __CALL_1 OpenClipboard(INTEGER hWndNewOwner);
#define WinAPI_OpenDesktop(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)	OpenDesktopA(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)
#define WinAPI_OpenDesktopA(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)	OpenDesktopA(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)
__EXTERN INTEGER __CALL_1 OpenDesktopA(INTEGER lpszDesktop, SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
#define WinAPI_OpenDesktopW(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)	OpenDesktopW(lpszDesktop, dwFlags, fInherit, dwDesiredAccess)
__EXTERN INTEGER __CALL_1 OpenDesktopW(INTEGER lpszDesktop, SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
#define WinAPI_OpenEvent(dwDesiredAccess, bInheritHandle, lpName)	OpenEventA(dwDesiredAccess, bInheritHandle, lpName)
#define WinAPI_OpenEventA(dwDesiredAccess, bInheritHandle, lpName)	OpenEventA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL_1 OpenEventA(SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
#define WinAPI_OpenEventLog(lpUNCServerName, lpSourceName)	OpenEventLogA(lpUNCServerName, lpSourceName)
#define WinAPI_OpenEventLogA(lpUNCServerName, lpSourceName)	OpenEventLogA(lpUNCServerName, lpSourceName)
__EXTERN INTEGER __CALL_1 OpenEventLogA(INTEGER lpUNCServerName, INTEGER lpSourceName);
#define WinAPI_OpenEventLogW(lpUNCServerName, lpSourceName)	OpenEventLogW(lpUNCServerName, lpSourceName)
__EXTERN INTEGER __CALL_1 OpenEventLogW(INTEGER lpUNCServerName, INTEGER lpSourceName);
#define WinAPI_OpenEventW(dwDesiredAccess, bInheritHandle, lpName)	OpenEventW(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL_1 OpenEventW(SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
#define WinAPI_OpenFile(lpFileName, lpReOpenBuff, lpReOpenBuff__typ, uStyle)	OpenFile(lpFileName, lpReOpenBuff, uStyle)
__EXTERN INTEGER __CALL_1 OpenFile(INTEGER lpFileName, WinAPI_OFSTRUCT *lpReOpenBuff, SET uStyle);
#define WinAPI_OpenFileMapping(dwDesiredAccess, bInheritHandle, lpName)	OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName)
#define WinAPI_OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName)	OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL_1 OpenFileMappingA(SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
#define WinAPI_OpenFileMappingW(dwDesiredAccess, bInheritHandle, lpName)	OpenFileMappingW(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL_1 OpenFileMappingW(SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
#define WinAPI_OpenIcon(hWnd)	OpenIcon(hWnd)
__EXTERN INTEGER __CALL_1 OpenIcon(INTEGER hWnd);
#define WinAPI_OpenInputDesktop(dwFlags, fInherit, dwDesiredAccess)	OpenInputDesktop(dwFlags, fInherit, dwDesiredAccess)
__EXTERN INTEGER __CALL_1 OpenInputDesktop(SET dwFlags, INTEGER fInherit, SET dwDesiredAccess);
#define WinAPI_OpenMutex(dwDesiredAccess, bInheritHandle, lpName)	OpenMutexA(dwDesiredAccess, bInheritHandle, lpName)
#define WinAPI_OpenMutexA(dwDesiredAccess, bInheritHandle, lpName)	OpenMutexA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL_1 OpenMutexA(SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
#define WinAPI_OpenMutexW(dwDesiredAccess, bInheritHandle, lpName)	OpenMutexW(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL_1 OpenMutexW(SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
#define WinAPI_OpenPrinter(pPrinterName, phPrinter, pDefault, pDefault__typ)	OpenPrinterA(pPrinterName, phPrinter, pDefault)
#define WinAPI_OpenPrinterA(pPrinterName, phPrinter, pDefault, pDefault__typ)	OpenPrinterA(pPrinterName, phPrinter, pDefault)
__EXTERN INTEGER __CALL_1 OpenPrinterA(INTEGER pPrinterName, INTEGER *phPrinter, WinAPI_PRINTER_DEFAULTSA *pDefault);
#define WinAPI_OpenPrinterW(pPrinterName, phPrinter, pDefault, pDefault__typ)	OpenPrinterW(pPrinterName, phPrinter, pDefault)
__EXTERN INTEGER __CALL_1 OpenPrinterW(INTEGER pPrinterName, INTEGER *phPrinter, WinAPI_PRINTER_DEFAULTSW *pDefault);
#define WinAPI_OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId)	OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId)
__EXTERN INTEGER __CALL_1 OpenProcess(SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER dwProcessId);
#define WinAPI_OpenProcessToken(ProcessHandle, DesiredAccess, TokenHandle)	OpenProcessToken(ProcessHandle, DesiredAccess, TokenHandle)
__EXTERN INTEGER __CALL_1 OpenProcessToken(INTEGER ProcessHandle, SET DesiredAccess, INTEGER *TokenHandle);
#define WinAPI_OpenSCManager(lpMachineName, lpDatabaseName, dwDesiredAccess)	OpenSCManagerA(lpMachineName, lpDatabaseName, dwDesiredAccess)
#define WinAPI_OpenSCManagerA(lpMachineName, lpDatabaseName, dwDesiredAccess)	OpenSCManagerA(lpMachineName, lpDatabaseName, dwDesiredAccess)
__EXTERN INTEGER __CALL_1 OpenSCManagerA(INTEGER lpMachineName, INTEGER lpDatabaseName, SET dwDesiredAccess);
#define WinAPI_OpenSCManagerW(lpMachineName, lpDatabaseName, dwDesiredAccess)	OpenSCManagerW(lpMachineName, lpDatabaseName, dwDesiredAccess)
__EXTERN INTEGER __CALL_1 OpenSCManagerW(INTEGER lpMachineName, INTEGER lpDatabaseName, SET dwDesiredAccess);
#define WinAPI_OpenSemaphore(dwDesiredAccess, bInheritHandle, lpName)	OpenSemaphoreA(dwDesiredAccess, bInheritHandle, lpName)
#define WinAPI_OpenSemaphoreA(dwDesiredAccess, bInheritHandle, lpName)	OpenSemaphoreA(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL_1 OpenSemaphoreA(SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
#define WinAPI_OpenSemaphoreW(dwDesiredAccess, bInheritHandle, lpName)	OpenSemaphoreW(dwDesiredAccess, bInheritHandle, lpName)
__EXTERN INTEGER __CALL_1 OpenSemaphoreW(SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpName);
#define WinAPI_OpenService(hSCManager, lpServiceName, dwDesiredAccess)	OpenServiceA(hSCManager, lpServiceName, dwDesiredAccess)
#define WinAPI_OpenServiceA(hSCManager, lpServiceName, dwDesiredAccess)	OpenServiceA(hSCManager, lpServiceName, dwDesiredAccess)
__EXTERN INTEGER __CALL_1 OpenServiceA(INTEGER hSCManager, INTEGER lpServiceName, SET dwDesiredAccess);
#define WinAPI_OpenServiceW(hSCManager, lpServiceName, dwDesiredAccess)	OpenServiceW(hSCManager, lpServiceName, dwDesiredAccess)
__EXTERN INTEGER __CALL_1 OpenServiceW(INTEGER hSCManager, INTEGER lpServiceName, SET dwDesiredAccess);
#define WinAPI_OpenThreadToken(ThreadHandle, DesiredAccess, OpenAsSelf, TokenHandle)	OpenThreadToken(ThreadHandle, DesiredAccess, OpenAsSelf, TokenHandle)
__EXTERN INTEGER __CALL_1 OpenThreadToken(INTEGER ThreadHandle, SET DesiredAccess, INTEGER OpenAsSelf, INTEGER *TokenHandle);
#define WinAPI_OpenWaitableTimer(dwDesiredAccess, bInheritHandle, lpTimerName)	OpenWaitableTimerA(dwDesiredAccess, bInheritHandle, lpTimerName)
#define WinAPI_OpenWaitableTimerA(dwDesiredAccess, bInheritHandle, lpTimerName)	OpenWaitableTimerA(dwDesiredAccess, bInheritHandle, lpTimerName)
__EXTERN INTEGER __CALL_1 OpenWaitableTimerA(SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpTimerName);
#define WinAPI_OpenWaitableTimerW(dwDesiredAccess, bInheritHandle, lpTimerName)	OpenWaitableTimerW(dwDesiredAccess, bInheritHandle, lpTimerName)
__EXTERN INTEGER __CALL_1 OpenWaitableTimerW(SET dwDesiredAccess, INTEGER bInheritHandle, INTEGER lpTimerName);
#define WinAPI_OpenWindowStation(lpszWinSta, fInherit, dwDesiredAccess)	OpenWindowStationA(lpszWinSta, fInherit, dwDesiredAccess)
#define WinAPI_OpenWindowStationA(lpszWinSta, fInherit, dwDesiredAccess)	OpenWindowStationA(lpszWinSta, fInherit, dwDesiredAccess)
__EXTERN INTEGER __CALL_1 OpenWindowStationA(INTEGER lpszWinSta, INTEGER fInherit, SET dwDesiredAccess);
#define WinAPI_OpenWindowStationW(lpszWinSta, fInherit, dwDesiredAccess)	OpenWindowStationW(lpszWinSta, fInherit, dwDesiredAccess)
__EXTERN INTEGER __CALL_1 OpenWindowStationW(INTEGER lpszWinSta, INTEGER fInherit, SET dwDesiredAccess);
#define WinAPI_OutputDebugString(lpOutputString)	OutputDebugStringA(lpOutputString)
#define WinAPI_OutputDebugStringA(lpOutputString)	OutputDebugStringA(lpOutputString)
__EXTERN void __CALL_1 OutputDebugStringA(INTEGER lpOutputString);
#define WinAPI_OutputDebugStringW(lpOutputString)	OutputDebugStringW(lpOutputString)
__EXTERN void __CALL_1 OutputDebugStringW(INTEGER lpOutputString);
#define WinAPI_PackDDElParam(msg, uiLo, uiHi)	PackDDElParam(msg, uiLo, uiHi)
__EXTERN INTEGER __CALL_1 PackDDElParam(INTEGER msg, INTEGER uiLo, INTEGER uiHi);
#define WinAPI_PaintDesktop(hdc)	PaintDesktop(hdc)
__EXTERN INTEGER __CALL_1 PaintDesktop(INTEGER hdc);
#define WinAPI_PaintRgn(p0, p1)	PaintRgn(p0, p1)
__EXTERN INTEGER __CALL_1 PaintRgn(INTEGER p0, INTEGER p1);
#define WinAPI_PatBlt(p0, p1, p2, p3, p4, p5)	PatBlt(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 PatBlt(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5);
#define WinAPI_PathToRegion(p0)	PathToRegion(p0)
__EXTERN INTEGER __CALL_1 PathToRegion(INTEGER p0);
#define WinAPI_PeekConsoleInput(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsRead)	PeekConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
#define WinAPI_PeekConsoleInputA(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsRead)	PeekConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
__EXTERN INTEGER __CALL_1 PeekConsoleInputA(INTEGER hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
#define WinAPI_PeekConsoleInputW(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsRead)	PeekConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
__EXTERN INTEGER __CALL_1 PeekConsoleInputW(INTEGER hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
#define WinAPI_PeekMessage(lpMsg, lpMsg__typ, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)	PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)
#define WinAPI_PeekMessageA(lpMsg, lpMsg__typ, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)	PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)
__EXTERN INTEGER __CALL_1 PeekMessageA(WinAPI_MSG *lpMsg, INTEGER hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax, INTEGER wRemoveMsg);
#define WinAPI_PeekMessageW(lpMsg, lpMsg__typ, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)	PeekMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)
__EXTERN INTEGER __CALL_1 PeekMessageW(WinAPI_MSG *lpMsg, INTEGER hWnd, INTEGER wMsgFilterMin, INTEGER wMsgFilterMax, INTEGER wRemoveMsg);
#define WinAPI_PeekNamedPipe(hNamedPipe, lpBuffer, nBufferSize, lpBytesRead, lpTotalBytesAvail, lpBytesLeftThisMessage)	PeekNamedPipe(hNamedPipe, lpBuffer, nBufferSize, lpBytesRead, lpTotalBytesAvail, lpBytesLeftThisMessage)
__EXTERN INTEGER __CALL_1 PeekNamedPipe(INTEGER hNamedPipe, INTEGER lpBuffer, INTEGER nBufferSize, INTEGER *lpBytesRead, INTEGER *lpTotalBytesAvail, INTEGER *lpBytesLeftThisMessage);
#define WinAPI_Pie(p0, p1, p2, p3, p4, p5, p6, p7, p8)	Pie(p0, p1, p2, p3, p4, p5, p6, p7, p8)
__EXTERN INTEGER __CALL_1 Pie(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8);
#define WinAPI_PlayEnhMetaFile(p0, p1, p2, p2__typ)	PlayEnhMetaFile(p0, p1, p2)
__EXTERN INTEGER __CALL_1 PlayEnhMetaFile(INTEGER p0, INTEGER p1, WinAPI_RECT *p2);
#define WinAPI_PlayEnhMetaFileRecord(p0, p1, p1__typ, p2, p2__typ, p3)	PlayEnhMetaFileRecord(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 PlayEnhMetaFileRecord(INTEGER p0, WinAPI_HANDLETABLE *p1, WinAPI_ENHMETARECORD *p2, INTEGER p3);
#define WinAPI_PlayMetaFile(p0, p1)	PlayMetaFile(p0, p1)
__EXTERN INTEGER __CALL_1 PlayMetaFile(INTEGER p0, INTEGER p1);
#define WinAPI_PlayMetaFileRecord(p0, p1, p1__typ, p2, p2__typ, p3)	PlayMetaFileRecord(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 PlayMetaFileRecord(INTEGER p0, WinAPI_HANDLETABLE *p1, WinAPI_METARECORD *p2, INTEGER p3);
#define WinAPI_PlgBlt(p0, p1, p1__typ, p2, p3, p4, p5, p6, p7, p8, p9)	PlgBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)
__EXTERN INTEGER __CALL_1 PlgBlt(INTEGER p0, WinAPI_POINT *p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9);
#define WinAPI_PolyBezier(p0, p1, p1__typ, p2)	PolyBezier(p0, p1, p2)
__EXTERN INTEGER __CALL_1 PolyBezier(INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_PolyBezierTo(p0, p1, p1__typ, p2)	PolyBezierTo(p0, p1, p2)
__EXTERN INTEGER __CALL_1 PolyBezierTo(INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_PolyDraw(p0, p1, p1__typ, p2, p3)	PolyDraw(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 PolyDraw(INTEGER p0, WinAPI_POINT *p1, CHAR *p2, INTEGER p3);
#define WinAPI_PolyPolygon(p0, p1, p1__typ, p2, p3)	PolyPolygon(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 PolyPolygon(INTEGER p0, WinAPI_POINT *p1, INTEGER *p2, INTEGER p3);
#define WinAPI_PolyPolyline(p0, p1, p1__typ, p2, p3)	PolyPolyline(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 PolyPolyline(INTEGER p0, WinAPI_POINT *p1, INTEGER *p2, INTEGER p3);
#define WinAPI_PolyTextOut(p0, p1, p1__typ, p2)	PolyTextOutA(p0, p1, p2)
#define WinAPI_PolyTextOutA(p0, p1, p1__typ, p2)	PolyTextOutA(p0, p1, p2)
__EXTERN INTEGER __CALL_1 PolyTextOutA(INTEGER p0, WinAPI_POLYTEXTA *p1, INTEGER p2);
#define WinAPI_PolyTextOutW(p0, p1, p1__typ, p2)	PolyTextOutW(p0, p1, p2)
__EXTERN INTEGER __CALL_1 PolyTextOutW(INTEGER p0, WinAPI_POLYTEXTW *p1, INTEGER p2);
#define WinAPI_Polygon(p0, p1, p1__typ, p2)	Polygon(p0, p1, p2)
__EXTERN INTEGER __CALL_1 Polygon(INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_Polyline(p0, p1, p1__typ, p2)	Polyline(p0, p1, p2)
__EXTERN INTEGER __CALL_1 Polyline(INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_PolylineTo(p0, p1, p1__typ, p2)	PolylineTo(p0, p1, p2)
__EXTERN INTEGER __CALL_1 PolylineTo(INTEGER p0, WinAPI_POINT *p1, INTEGER p2);
#define WinAPI_PostMessage(hWnd, Msg, wParam, lParam)	PostMessageA(hWnd, Msg, wParam, lParam)
#define WinAPI_PostMessageA(hWnd, Msg, wParam, lParam)	PostMessageA(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 PostMessageA(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_PostMessageW(hWnd, Msg, wParam, lParam)	PostMessageW(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 PostMessageW(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_PostQueuedCompletionStatus(CompletionPort, dwNumberOfBytesTransferred, dwCompletionKey, lpOverlapped, lpOverlapped__typ)	PostQueuedCompletionStatus(CompletionPort, dwNumberOfBytesTransferred, dwCompletionKey, lpOverlapped)
__EXTERN INTEGER __CALL_1 PostQueuedCompletionStatus(INTEGER CompletionPort, INTEGER dwNumberOfBytesTransferred, INTEGER dwCompletionKey, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_PostQuitMessage(nExitCode)	PostQuitMessage(nExitCode)
__EXTERN void __CALL_1 PostQuitMessage(INTEGER nExitCode);
#define WinAPI_PostThreadMessage(idThread, Msg, wParam, lParam)	PostThreadMessageA(idThread, Msg, wParam, lParam)
#define WinAPI_PostThreadMessageA(idThread, Msg, wParam, lParam)	PostThreadMessageA(idThread, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 PostThreadMessageA(INTEGER idThread, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_PostThreadMessageW(idThread, Msg, wParam, lParam)	PostThreadMessageW(idThread, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 PostThreadMessageW(INTEGER idThread, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_PrepareTape(hDevice, dwOperation, bImmediate)	PrepareTape(hDevice, dwOperation, bImmediate)
__EXTERN INTEGER __CALL_1 PrepareTape(INTEGER hDevice, INTEGER dwOperation, INTEGER bImmediate);
#define WinAPI_PrevInstance()	__hPrevInstance
#define WinAPI_PrinterMessageBox(hPrinter, Error, hWnd, pText, pCaption, dwType)	PrinterMessageBoxA(hPrinter, Error, hWnd, pText, pCaption, dwType)
#define WinAPI_PrinterMessageBoxA(hPrinter, Error, hWnd, pText, pCaption, dwType)	PrinterMessageBoxA(hPrinter, Error, hWnd, pText, pCaption, dwType)
__EXTERN INTEGER __CALL_1 PrinterMessageBoxA(INTEGER hPrinter, INTEGER Error, INTEGER hWnd, INTEGER pText, INTEGER pCaption, INTEGER dwType);
#define WinAPI_PrinterMessageBoxW(hPrinter, Error, hWnd, pText, pCaption, dwType)	PrinterMessageBoxW(hPrinter, Error, hWnd, pText, pCaption, dwType)
__EXTERN INTEGER __CALL_1 PrinterMessageBoxW(INTEGER hPrinter, INTEGER Error, INTEGER hWnd, INTEGER pText, INTEGER pCaption, INTEGER dwType);
#define WinAPI_PrinterProperties(hWnd, hPrinter)	PrinterProperties(hWnd, hPrinter)
__EXTERN INTEGER __CALL_1 PrinterProperties(INTEGER hWnd, INTEGER hPrinter);
#define WinAPI_PrivilegeCheck(ClientToken, RequiredPrivileges, RequiredPrivileges__typ, pfResult)	PrivilegeCheck(ClientToken, RequiredPrivileges, pfResult)
__EXTERN INTEGER __CALL_1 PrivilegeCheck(INTEGER ClientToken, WinAPI_PRIVILEGE_SET *RequiredPrivileges, INTEGER *pfResult);
#define WinAPI_PrivilegedServiceAuditAlarm(SubsystemName, ServiceName, ClientToken, Privileges, Privileges__typ, AccessGranted)	PrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)
#define WinAPI_PrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, Privileges__typ, AccessGranted)	PrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)
__EXTERN INTEGER __CALL_1 PrivilegedServiceAuditAlarmA(INTEGER SubsystemName, INTEGER ServiceName, INTEGER ClientToken, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
#define WinAPI_PrivilegedServiceAuditAlarmW(SubsystemName, ServiceName, ClientToken, Privileges, Privileges__typ, AccessGranted)	PrivilegedServiceAuditAlarmW(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted)
__EXTERN INTEGER __CALL_1 PrivilegedServiceAuditAlarmW(INTEGER SubsystemName, INTEGER ServiceName, INTEGER ClientToken, WinAPI_PRIVILEGE_SET *Privileges, INTEGER AccessGranted);
#define WinAPI_PropertySheet(p0, p0__typ)	PropertySheetA(p0)
#define WinAPI_PropertySheetA(p0, p0__typ)	PropertySheetA(p0)
__EXTERN INTEGER __CALL_1 PropertySheetA(WinAPI_PROPSHEETHEADERA *p0);
#define WinAPI_PropertySheetW(p0, p0__typ)	PropertySheetW(p0)
__EXTERN INTEGER __CALL_1 PropertySheetW(WinAPI_PROPSHEETHEADERW *p0);
#define WinAPI_PtInRect(lprc, lprc__typ, pt)	PtInRect(lprc, pt)
__EXTERN INTEGER __CALL_1 PtInRect(WinAPI_RECT *lprc, WinAPI_POINT pt);
#define WinAPI_PtInRegion(p0, p1, p2)	PtInRegion(p0, p1, p2)
__EXTERN INTEGER __CALL_1 PtInRegion(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_PtVisible(p0, p1, p2)	PtVisible(p0, p1, p2)
__EXTERN INTEGER __CALL_1 PtVisible(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_PulseEvent(hEvent)	PulseEvent(hEvent)
__EXTERN INTEGER __CALL_1 PulseEvent(INTEGER hEvent);
#define WinAPI_PurgeComm(hFile, dwFlags)	PurgeComm(hFile, dwFlags)
__EXTERN INTEGER __CALL_1 PurgeComm(INTEGER hFile, SET dwFlags);
#define WinAPI_QueryDosDevice(lpDeviceName, lpTargetPath, ucchMax)	QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax)
#define WinAPI_QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax)	QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax)
__EXTERN INTEGER __CALL_1 QueryDosDeviceA(INTEGER lpDeviceName, INTEGER lpTargetPath, INTEGER ucchMax);
#define WinAPI_QueryDosDeviceW(lpDeviceName, lpTargetPath, ucchMax)	QueryDosDeviceW(lpDeviceName, lpTargetPath, ucchMax)
__EXTERN INTEGER __CALL_1 QueryDosDeviceW(INTEGER lpDeviceName, INTEGER lpTargetPath, INTEGER ucchMax);
#define WinAPI_QueryPerformanceCounter(lpPerformanceCount)	QueryPerformanceCounter(lpPerformanceCount)
__EXTERN INTEGER __CALL_1 QueryPerformanceCounter(LONGINT *lpPerformanceCount);
#define WinAPI_QueryPerformanceFrequency(lpFrequency)	QueryPerformanceFrequency(lpFrequency)
__EXTERN INTEGER __CALL_1 QueryPerformanceFrequency(LONGINT *lpFrequency);
#define WinAPI_QueryServiceConfig(hService, lpServiceConfig, lpServiceConfig__typ, cbBufSize, pcbBytesNeeded)	QueryServiceConfigA(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)
#define WinAPI_QueryServiceConfigA(hService, lpServiceConfig, lpServiceConfig__typ, cbBufSize, pcbBytesNeeded)	QueryServiceConfigA(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __CALL_1 QueryServiceConfigA(INTEGER hService, WinAPI_QUERY_SERVICE_CONFIGA *lpServiceConfig, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinAPI_QueryServiceConfigW(hService, lpServiceConfig, lpServiceConfig__typ, cbBufSize, pcbBytesNeeded)	QueryServiceConfigW(hService, lpServiceConfig, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __CALL_1 QueryServiceConfigW(INTEGER hService, WinAPI_QUERY_SERVICE_CONFIGW *lpServiceConfig, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinAPI_QueryServiceLockStatus(hSCManager, lpLockStatus, lpLockStatus__typ, cbBufSize, pcbBytesNeeded)	QueryServiceLockStatusA(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)
#define WinAPI_QueryServiceLockStatusA(hSCManager, lpLockStatus, lpLockStatus__typ, cbBufSize, pcbBytesNeeded)	QueryServiceLockStatusA(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __CALL_1 QueryServiceLockStatusA(INTEGER hSCManager, WinAPI_QUERY_SERVICE_LOCK_STATUSA *lpLockStatus, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinAPI_QueryServiceLockStatusW(hSCManager, lpLockStatus, lpLockStatus__typ, cbBufSize, pcbBytesNeeded)	QueryServiceLockStatusW(hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __CALL_1 QueryServiceLockStatusW(INTEGER hSCManager, WinAPI_QUERY_SERVICE_LOCK_STATUSW *lpLockStatus, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinAPI_QueryServiceObjectSecurity(hService, dwSecurityInformation, lpSecurityDescriptor, cbBufSize, pcbBytesNeeded)	QueryServiceObjectSecurity(hService, dwSecurityInformation, lpSecurityDescriptor, cbBufSize, pcbBytesNeeded)
__EXTERN INTEGER __CALL_1 QueryServiceObjectSecurity(INTEGER hService, SET dwSecurityInformation, INTEGER lpSecurityDescriptor, INTEGER cbBufSize, INTEGER *pcbBytesNeeded);
#define WinAPI_QueryServiceStatus(hService, lpServiceStatus, lpServiceStatus__typ)	QueryServiceStatus(hService, lpServiceStatus)
__EXTERN INTEGER __CALL_1 QueryServiceStatus(INTEGER hService, WinAPI_SERVICE_STATUS *lpServiceStatus);
#define WinAPI_QueueUserAPC(pfnAPC, hThread, dwData)	QueueUserAPC(pfnAPC, hThread, dwData)
__EXTERN INTEGER __CALL_1 QueueUserAPC(WinAPI_APCFUNC pfnAPC, INTEGER hThread, INTEGER dwData);
#define WinAPI_RaiseException(dwExceptionCode, dwExceptionFlags, nNumberOfArguments, lpArguments)	RaiseException(dwExceptionCode, dwExceptionFlags, nNumberOfArguments, lpArguments)
__EXTERN void __CALL_1 RaiseException(INTEGER dwExceptionCode, INTEGER dwExceptionFlags, INTEGER nNumberOfArguments, INTEGER *lpArguments);
#define WinAPI_ReadConsole(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)	ReadConsoleA(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)
#define WinAPI_ReadConsoleA(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)	ReadConsoleA(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)
__EXTERN INTEGER __CALL_1 ReadConsoleA(INTEGER hConsoleInput, INTEGER lpBuffer, INTEGER nNumberOfCharsToRead, INTEGER *lpNumberOfCharsRead, INTEGER lpReserved);
#define WinAPI_ReadConsoleInput(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsRead)	ReadConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
#define WinAPI_ReadConsoleInputA(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsRead)	ReadConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
__EXTERN INTEGER __CALL_1 ReadConsoleInputA(INTEGER hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
#define WinAPI_ReadConsoleInputW(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsRead)	ReadConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead)
__EXTERN INTEGER __CALL_1 ReadConsoleInputW(INTEGER hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsRead);
#define WinAPI_ReadConsoleOutput(hConsoleOutput, lpBuffer, lpBuffer__typ, dwBufferSize, dwBufferCoord, lpReadRegion, lpReadRegion__typ)	ReadConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)
#define WinAPI_ReadConsoleOutputA(hConsoleOutput, lpBuffer, lpBuffer__typ, dwBufferSize, dwBufferCoord, lpReadRegion, lpReadRegion__typ)	ReadConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)
__EXTERN INTEGER __CALL_1 ReadConsoleOutputA(INTEGER hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD dwBufferSize, WinAPI_COORD dwBufferCoord, WinAPI_SMALL_RECT *lpReadRegion);
#define WinAPI_ReadConsoleOutputAttribute(hConsoleOutput, lpAttribute, nLength, dwReadCoord, lpNumberOfAttrsRead)	ReadConsoleOutputAttribute(hConsoleOutput, lpAttribute, nLength, dwReadCoord, lpNumberOfAttrsRead)
__EXTERN INTEGER __CALL_1 ReadConsoleOutputAttribute(INTEGER hConsoleOutput, SHORTINT *lpAttribute, INTEGER nLength, WinAPI_COORD dwReadCoord, INTEGER *lpNumberOfAttrsRead);
#define WinAPI_ReadConsoleOutputCharacter(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)	ReadConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)
#define WinAPI_ReadConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)	ReadConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)
__EXTERN INTEGER __CALL_1 ReadConsoleOutputCharacterA(INTEGER hConsoleOutput, INTEGER lpCharacter, INTEGER nLength, WinAPI_COORD dwReadCoord, INTEGER *lpNumberOfCharsRead);
#define WinAPI_ReadConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)	ReadConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead)
__EXTERN INTEGER __CALL_1 ReadConsoleOutputCharacterW(INTEGER hConsoleOutput, INTEGER lpCharacter, INTEGER nLength, WinAPI_COORD dwReadCoord, INTEGER *lpNumberOfCharsRead);
#define WinAPI_ReadConsoleOutputW(hConsoleOutput, lpBuffer, lpBuffer__typ, dwBufferSize, dwBufferCoord, lpReadRegion, lpReadRegion__typ)	ReadConsoleOutputW(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion)
__EXTERN INTEGER __CALL_1 ReadConsoleOutputW(INTEGER hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD dwBufferSize, WinAPI_COORD dwBufferCoord, WinAPI_SMALL_RECT *lpReadRegion);
#define WinAPI_ReadConsoleW(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)	ReadConsoleW(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved)
__EXTERN INTEGER __CALL_1 ReadConsoleW(INTEGER hConsoleInput, INTEGER lpBuffer, INTEGER nNumberOfCharsToRead, INTEGER *lpNumberOfCharsRead, INTEGER lpReserved);
#define WinAPI_ReadDirectoryChangesW(hDirectory, lpBuffer, nBufferLength, bWatchSubtree, dwNotifyFilter, lpBytesReturned, lpOverlapped, lpOverlapped__typ, lpCompletionRoutine)	ReadDirectoryChangesW(hDirectory, lpBuffer, nBufferLength, bWatchSubtree, dwNotifyFilter, lpBytesReturned, lpOverlapped, lpCompletionRoutine)
__EXTERN INTEGER __CALL_1 ReadDirectoryChangesW(INTEGER hDirectory, INTEGER lpBuffer, INTEGER nBufferLength, INTEGER bWatchSubtree, SET dwNotifyFilter, INTEGER *lpBytesReturned, WinAPI_OVERLAPPED *lpOverlapped, WinAPI_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinAPI_ReadEventLog(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)	ReadEventLogA(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)
#define WinAPI_ReadEventLogA(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)	ReadEventLogA(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)
__EXTERN INTEGER __CALL_1 ReadEventLogA(INTEGER hEventLog, SET dwReadFlags, INTEGER dwRecordOffset, INTEGER lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *pnBytesRead, INTEGER *pnMinNumberOfBytesNeeded);
#define WinAPI_ReadEventLogW(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)	ReadEventLogW(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded)
__EXTERN INTEGER __CALL_1 ReadEventLogW(INTEGER hEventLog, SET dwReadFlags, INTEGER dwRecordOffset, INTEGER lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *pnBytesRead, INTEGER *pnMinNumberOfBytesNeeded);
#define WinAPI_ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped, lpOverlapped__typ)	ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped)
__EXTERN INTEGER __CALL_1 ReadFile(INTEGER hFile, INTEGER lpBuffer, INTEGER nNumberOfBytesToRead, INTEGER *lpNumberOfBytesRead, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_ReadFileEx(hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpOverlapped__typ, lpCompletionRoutine)	ReadFileEx(hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine)
__EXTERN INTEGER __CALL_1 ReadFileEx(INTEGER hFile, INTEGER lpBuffer, INTEGER nNumberOfBytesToRead, WinAPI_OVERLAPPED *lpOverlapped, WinAPI_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinAPI_ReadPrinter(hPrinter, pBuf, cbBuf, pNoBytesRead)	ReadPrinter(hPrinter, pBuf, cbBuf, pNoBytesRead)
__EXTERN INTEGER __CALL_1 ReadPrinter(INTEGER hPrinter, INTEGER pBuf, INTEGER cbBuf, INTEGER *pNoBytesRead);
#define WinAPI_ReadProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead)	ReadProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead)
__EXTERN INTEGER __CALL_1 ReadProcessMemory(INTEGER hProcess, INTEGER lpBaseAddress, INTEGER lpBuffer, INTEGER nSize, INTEGER *lpNumberOfBytesRead);
#define WinAPI_RealizePalette(p0)	RealizePalette(p0)
__EXTERN INTEGER __CALL_1 RealizePalette(INTEGER p0);
#define WinAPI_RectInRegion(p0, p1, p1__typ)	RectInRegion(p0, p1)
__EXTERN INTEGER __CALL_1 RectInRegion(INTEGER p0, WinAPI_RECT *p1);
#define WinAPI_RectVisible(p0, p1, p1__typ)	RectVisible(p0, p1)
__EXTERN INTEGER __CALL_1 RectVisible(INTEGER p0, WinAPI_RECT *p1);
#define WinAPI_Rectangle(p0, p1, p2, p3, p4)	Rectangle(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 Rectangle(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_RedrawWindow(hWnd, lprcUpdate, lprcUpdate__typ, hrgnUpdate, flags)	RedrawWindow(hWnd, lprcUpdate, hrgnUpdate, flags)
__EXTERN INTEGER __CALL_1 RedrawWindow(INTEGER hWnd, WinAPI_RECT *lprcUpdate, INTEGER hrgnUpdate, SET flags);
#define WinAPI_RegCloseKey(hKey)	RegCloseKey(hKey)
__EXTERN INTEGER __CALL_1 RegCloseKey(INTEGER hKey);
#define WinAPI_RegConnectRegistry(lpMachineName, hKey, phkResult)	RegConnectRegistryA(lpMachineName, hKey, phkResult)
#define WinAPI_RegConnectRegistryA(lpMachineName, hKey, phkResult)	RegConnectRegistryA(lpMachineName, hKey, phkResult)
__EXTERN INTEGER __CALL_1 RegConnectRegistryA(INTEGER lpMachineName, INTEGER hKey, INTEGER *phkResult);
#define WinAPI_RegConnectRegistryW(lpMachineName, hKey, phkResult)	RegConnectRegistryW(lpMachineName, hKey, phkResult)
__EXTERN INTEGER __CALL_1 RegConnectRegistryW(INTEGER lpMachineName, INTEGER hKey, INTEGER *phkResult);
#define WinAPI_RegCreateKey(hKey, lpSubKey, phkResult)	RegCreateKeyA(hKey, lpSubKey, phkResult)
#define WinAPI_RegCreateKeyA(hKey, lpSubKey, phkResult)	RegCreateKeyA(hKey, lpSubKey, phkResult)
__EXTERN INTEGER __CALL_1 RegCreateKeyA(INTEGER hKey, INTEGER lpSubKey, INTEGER *phkResult);
#define WinAPI_RegCreateKeyEx(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, lpSecurityAttributes__typ, phkResult, lpdwDisposition)	RegCreateKeyExA(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)
#define WinAPI_RegCreateKeyExA(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, lpSecurityAttributes__typ, phkResult, lpdwDisposition)	RegCreateKeyExA(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)
__EXTERN INTEGER __CALL_1 RegCreateKeyExA(INTEGER hKey, INTEGER lpSubKey, INTEGER Reserved, INTEGER lpClass, SET dwOptions, SET samDesired, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER *phkResult, INTEGER *lpdwDisposition);
#define WinAPI_RegCreateKeyExW(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, lpSecurityAttributes__typ, phkResult, lpdwDisposition)	RegCreateKeyExW(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition)
__EXTERN INTEGER __CALL_1 RegCreateKeyExW(INTEGER hKey, INTEGER lpSubKey, INTEGER Reserved, INTEGER lpClass, SET dwOptions, SET samDesired, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes, INTEGER *phkResult, INTEGER *lpdwDisposition);
#define WinAPI_RegCreateKeyW(hKey, lpSubKey, phkResult)	RegCreateKeyW(hKey, lpSubKey, phkResult)
__EXTERN INTEGER __CALL_1 RegCreateKeyW(INTEGER hKey, INTEGER lpSubKey, INTEGER *phkResult);
#define WinAPI_RegDeleteKey(hKey, lpSubKey)	RegDeleteKeyA(hKey, lpSubKey)
#define WinAPI_RegDeleteKeyA(hKey, lpSubKey)	RegDeleteKeyA(hKey, lpSubKey)
__EXTERN INTEGER __CALL_1 RegDeleteKeyA(INTEGER hKey, INTEGER lpSubKey);
#define WinAPI_RegDeleteKeyW(hKey, lpSubKey)	RegDeleteKeyW(hKey, lpSubKey)
__EXTERN INTEGER __CALL_1 RegDeleteKeyW(INTEGER hKey, INTEGER lpSubKey);
#define WinAPI_RegDeleteValue(hKey, lpValueName)	RegDeleteValueA(hKey, lpValueName)
#define WinAPI_RegDeleteValueA(hKey, lpValueName)	RegDeleteValueA(hKey, lpValueName)
__EXTERN INTEGER __CALL_1 RegDeleteValueA(INTEGER hKey, INTEGER lpValueName);
#define WinAPI_RegDeleteValueW(hKey, lpValueName)	RegDeleteValueW(hKey, lpValueName)
__EXTERN INTEGER __CALL_1 RegDeleteValueW(INTEGER hKey, INTEGER lpValueName);
#define WinAPI_RegEnumKey(hKey, dwIndex, lpName, cbName)	RegEnumKeyA(hKey, dwIndex, lpName, cbName)
#define WinAPI_RegEnumKeyA(hKey, dwIndex, lpName, cbName)	RegEnumKeyA(hKey, dwIndex, lpName, cbName)
__EXTERN INTEGER __CALL_1 RegEnumKeyA(INTEGER hKey, INTEGER dwIndex, INTEGER lpName, INTEGER cbName);
#define WinAPI_RegEnumKeyEx(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime, lpftLastWriteTime__typ)	RegEnumKeyExA(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)
#define WinAPI_RegEnumKeyExA(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime, lpftLastWriteTime__typ)	RegEnumKeyExA(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)
__EXTERN INTEGER __CALL_1 RegEnumKeyExA(INTEGER hKey, INTEGER dwIndex, INTEGER lpName, INTEGER *lpcbName, INTEGER *lpReserved, INTEGER lpClass, INTEGER *lpcbClass, WinAPI_FILETIME *lpftLastWriteTime);
#define WinAPI_RegEnumKeyExW(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime, lpftLastWriteTime__typ)	RegEnumKeyExW(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime)
__EXTERN INTEGER __CALL_1 RegEnumKeyExW(INTEGER hKey, INTEGER dwIndex, INTEGER lpName, INTEGER *lpcbName, INTEGER *lpReserved, INTEGER lpClass, INTEGER *lpcbClass, WinAPI_FILETIME *lpftLastWriteTime);
#define WinAPI_RegEnumKeyW(hKey, dwIndex, lpName, cbName)	RegEnumKeyW(hKey, dwIndex, lpName, cbName)
__EXTERN INTEGER __CALL_1 RegEnumKeyW(INTEGER hKey, INTEGER dwIndex, INTEGER lpName, INTEGER cbName);
#define WinAPI_RegEnumValue(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)	RegEnumValueA(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)
#define WinAPI_RegEnumValueA(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)	RegEnumValueA(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __CALL_1 RegEnumValueA(INTEGER hKey, INTEGER dwIndex, INTEGER lpValueName, INTEGER *lpcbValueName, INTEGER *lpReserved, INTEGER *lpType, INTEGER lpData, INTEGER *lpcbData);
#define WinAPI_RegEnumValueW(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)	RegEnumValueW(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __CALL_1 RegEnumValueW(INTEGER hKey, INTEGER dwIndex, INTEGER lpValueName, INTEGER *lpcbValueName, INTEGER *lpReserved, INTEGER *lpType, INTEGER lpData, INTEGER *lpcbData);
#define WinAPI_RegFlushKey(hKey)	RegFlushKey(hKey)
__EXTERN INTEGER __CALL_1 RegFlushKey(INTEGER hKey);
#define WinAPI_RegGetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor, lpcbSecurityDescriptor)	RegGetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor, lpcbSecurityDescriptor)
__EXTERN INTEGER __CALL_1 RegGetKeySecurity(INTEGER hKey, SET SecurityInformation, INTEGER pSecurityDescriptor, INTEGER *lpcbSecurityDescriptor);
#define WinAPI_RegLoadKey(hKey, lpSubKey, lpFile)	RegLoadKeyA(hKey, lpSubKey, lpFile)
#define WinAPI_RegLoadKeyA(hKey, lpSubKey, lpFile)	RegLoadKeyA(hKey, lpSubKey, lpFile)
__EXTERN INTEGER __CALL_1 RegLoadKeyA(INTEGER hKey, INTEGER lpSubKey, INTEGER lpFile);
#define WinAPI_RegLoadKeyW(hKey, lpSubKey, lpFile)	RegLoadKeyW(hKey, lpSubKey, lpFile)
__EXTERN INTEGER __CALL_1 RegLoadKeyW(INTEGER hKey, INTEGER lpSubKey, INTEGER lpFile);
#define WinAPI_RegNotifyChangeKeyValue(hKey, bWatchSubtree, dwNotifyFilter, hEvent, fAsynchronus)	RegNotifyChangeKeyValue(hKey, bWatchSubtree, dwNotifyFilter, hEvent, fAsynchronus)
__EXTERN INTEGER __CALL_1 RegNotifyChangeKeyValue(INTEGER hKey, INTEGER bWatchSubtree, SET dwNotifyFilter, INTEGER hEvent, INTEGER fAsynchronus);
#define WinAPI_RegOpenKey(hKey, lpSubKey, phkResult)	RegOpenKeyA(hKey, lpSubKey, phkResult)
#define WinAPI_RegOpenKeyA(hKey, lpSubKey, phkResult)	RegOpenKeyA(hKey, lpSubKey, phkResult)
__EXTERN INTEGER __CALL_1 RegOpenKeyA(INTEGER hKey, INTEGER lpSubKey, INTEGER *phkResult);
#define WinAPI_RegOpenKeyEx(hKey, lpSubKey, ulOptions, samDesired, phkResult)	RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult)
#define WinAPI_RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult)	RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult)
__EXTERN INTEGER __CALL_1 RegOpenKeyExA(INTEGER hKey, INTEGER lpSubKey, INTEGER ulOptions, SET samDesired, INTEGER *phkResult);
#define WinAPI_RegOpenKeyExW(hKey, lpSubKey, ulOptions, samDesired, phkResult)	RegOpenKeyExW(hKey, lpSubKey, ulOptions, samDesired, phkResult)
__EXTERN INTEGER __CALL_1 RegOpenKeyExW(INTEGER hKey, INTEGER lpSubKey, INTEGER ulOptions, SET samDesired, INTEGER *phkResult);
#define WinAPI_RegOpenKeyW(hKey, lpSubKey, phkResult)	RegOpenKeyW(hKey, lpSubKey, phkResult)
__EXTERN INTEGER __CALL_1 RegOpenKeyW(INTEGER hKey, INTEGER lpSubKey, INTEGER *phkResult);
#define WinAPI_RegQueryInfoKey(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime, lpftLastWriteTime__typ)	RegQueryInfoKeyA(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)
#define WinAPI_RegQueryInfoKeyA(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime, lpftLastWriteTime__typ)	RegQueryInfoKeyA(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)
__EXTERN INTEGER __CALL_1 RegQueryInfoKeyA(INTEGER hKey, INTEGER lpClass, INTEGER *lpcbClass, INTEGER *lpReserved, INTEGER *lpcSubKeys, INTEGER *lpcbMaxSubKeyLen, INTEGER *lpcbMaxClassLen, INTEGER *lpcValues, INTEGER *lpcbMaxValueNameLen, INTEGER *lpcbMaxValueLen, INTEGER *lpcbSecurityDescriptor, WinAPI_FILETIME *lpftLastWriteTime);
#define WinAPI_RegQueryInfoKeyW(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime, lpftLastWriteTime__typ)	RegQueryInfoKeyW(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime)
__EXTERN INTEGER __CALL_1 RegQueryInfoKeyW(INTEGER hKey, INTEGER lpClass, INTEGER *lpcbClass, INTEGER *lpReserved, INTEGER *lpcSubKeys, INTEGER *lpcbMaxSubKeyLen, INTEGER *lpcbMaxClassLen, INTEGER *lpcValues, INTEGER *lpcbMaxValueNameLen, INTEGER *lpcbMaxValueLen, INTEGER *lpcbSecurityDescriptor, WinAPI_FILETIME *lpftLastWriteTime);
#define WinAPI_RegQueryMultipleValues(hKey, val_list, val_list__typ, num_vals, lpValueBuf, ldwTotsize)	RegQueryMultipleValuesA(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)
#define WinAPI_RegQueryMultipleValuesA(hKey, val_list, val_list__typ, num_vals, lpValueBuf, ldwTotsize)	RegQueryMultipleValuesA(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)
__EXTERN INTEGER __CALL_1 RegQueryMultipleValuesA(INTEGER hKey, WinAPI_VALENTA *val_list, INTEGER num_vals, INTEGER lpValueBuf, INTEGER *ldwTotsize);
#define WinAPI_RegQueryMultipleValuesW(hKey, val_list, val_list__typ, num_vals, lpValueBuf, ldwTotsize)	RegQueryMultipleValuesW(hKey, val_list, num_vals, lpValueBuf, ldwTotsize)
__EXTERN INTEGER __CALL_1 RegQueryMultipleValuesW(INTEGER hKey, WinAPI_VALENTW *val_list, INTEGER num_vals, INTEGER lpValueBuf, INTEGER *ldwTotsize);
#define WinAPI_RegQueryValue(hKey, lpSubKey, lpValue, lpcbValue)	RegQueryValueA(hKey, lpSubKey, lpValue, lpcbValue)
#define WinAPI_RegQueryValueA(hKey, lpSubKey, lpValue, lpcbValue)	RegQueryValueA(hKey, lpSubKey, lpValue, lpcbValue)
__EXTERN INTEGER __CALL_1 RegQueryValueA(INTEGER hKey, INTEGER lpSubKey, INTEGER lpValue, INTEGER *lpcbValue);
#define WinAPI_RegQueryValueEx(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)	RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)
#define WinAPI_RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)	RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __CALL_1 RegQueryValueExA(INTEGER hKey, INTEGER lpValueName, INTEGER *lpReserved, INTEGER *lpType, INTEGER lpData, INTEGER *lpcbData);
#define WinAPI_RegQueryValueExW(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)	RegQueryValueExW(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData)
__EXTERN INTEGER __CALL_1 RegQueryValueExW(INTEGER hKey, INTEGER lpValueName, INTEGER *lpReserved, INTEGER *lpType, INTEGER lpData, INTEGER *lpcbData);
#define WinAPI_RegQueryValueW(hKey, lpSubKey, lpValue, lpcbValue)	RegQueryValueW(hKey, lpSubKey, lpValue, lpcbValue)
__EXTERN INTEGER __CALL_1 RegQueryValueW(INTEGER hKey, INTEGER lpSubKey, INTEGER lpValue, INTEGER *lpcbValue);
#define WinAPI_RegReplaceKey(hKey, lpSubKey, lpNewFile, lpOldFile)	RegReplaceKeyA(hKey, lpSubKey, lpNewFile, lpOldFile)
#define WinAPI_RegReplaceKeyA(hKey, lpSubKey, lpNewFile, lpOldFile)	RegReplaceKeyA(hKey, lpSubKey, lpNewFile, lpOldFile)
__EXTERN INTEGER __CALL_1 RegReplaceKeyA(INTEGER hKey, INTEGER lpSubKey, INTEGER lpNewFile, INTEGER lpOldFile);
#define WinAPI_RegReplaceKeyW(hKey, lpSubKey, lpNewFile, lpOldFile)	RegReplaceKeyW(hKey, lpSubKey, lpNewFile, lpOldFile)
__EXTERN INTEGER __CALL_1 RegReplaceKeyW(INTEGER hKey, INTEGER lpSubKey, INTEGER lpNewFile, INTEGER lpOldFile);
#define WinAPI_RegRestoreKey(hKey, lpFile, dwFlags)	RegRestoreKeyA(hKey, lpFile, dwFlags)
#define WinAPI_RegRestoreKeyA(hKey, lpFile, dwFlags)	RegRestoreKeyA(hKey, lpFile, dwFlags)
__EXTERN INTEGER __CALL_1 RegRestoreKeyA(INTEGER hKey, INTEGER lpFile, SET dwFlags);
#define WinAPI_RegRestoreKeyW(hKey, lpFile, dwFlags)	RegRestoreKeyW(hKey, lpFile, dwFlags)
__EXTERN INTEGER __CALL_1 RegRestoreKeyW(INTEGER hKey, INTEGER lpFile, SET dwFlags);
#define WinAPI_RegSaveKey(hKey, lpFile, lpSecurityAttributes, lpSecurityAttributes__typ)	RegSaveKeyA(hKey, lpFile, lpSecurityAttributes)
#define WinAPI_RegSaveKeyA(hKey, lpFile, lpSecurityAttributes, lpSecurityAttributes__typ)	RegSaveKeyA(hKey, lpFile, lpSecurityAttributes)
__EXTERN INTEGER __CALL_1 RegSaveKeyA(INTEGER hKey, INTEGER lpFile, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_RegSaveKeyW(hKey, lpFile, lpSecurityAttributes, lpSecurityAttributes__typ)	RegSaveKeyW(hKey, lpFile, lpSecurityAttributes)
__EXTERN INTEGER __CALL_1 RegSaveKeyW(INTEGER hKey, INTEGER lpFile, WinAPI_SECURITY_ATTRIBUTES *lpSecurityAttributes);
#define WinAPI_RegSetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor)	RegSetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor)
__EXTERN INTEGER __CALL_1 RegSetKeySecurity(INTEGER hKey, SET SecurityInformation, INTEGER pSecurityDescriptor);
#define WinAPI_RegSetValue(hKey, lpSubKey, dwType, lpData, cbData)	RegSetValueA(hKey, lpSubKey, dwType, lpData, cbData)
#define WinAPI_RegSetValueA(hKey, lpSubKey, dwType, lpData, cbData)	RegSetValueA(hKey, lpSubKey, dwType, lpData, cbData)
__EXTERN INTEGER __CALL_1 RegSetValueA(INTEGER hKey, INTEGER lpSubKey, INTEGER dwType, INTEGER lpData, INTEGER cbData);
#define WinAPI_RegSetValueEx(hKey, lpValueName, Reserved, dwType, lpData, cbData)	RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData)
#define WinAPI_RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData)	RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData)
__EXTERN INTEGER __CALL_1 RegSetValueExA(INTEGER hKey, INTEGER lpValueName, INTEGER Reserved, INTEGER dwType, INTEGER lpData, INTEGER cbData);
#define WinAPI_RegSetValueExW(hKey, lpValueName, Reserved, dwType, lpData, cbData)	RegSetValueExW(hKey, lpValueName, Reserved, dwType, lpData, cbData)
__EXTERN INTEGER __CALL_1 RegSetValueExW(INTEGER hKey, INTEGER lpValueName, INTEGER Reserved, INTEGER dwType, INTEGER lpData, INTEGER cbData);
#define WinAPI_RegSetValueW(hKey, lpSubKey, dwType, lpData, cbData)	RegSetValueW(hKey, lpSubKey, dwType, lpData, cbData)
__EXTERN INTEGER __CALL_1 RegSetValueW(INTEGER hKey, INTEGER lpSubKey, INTEGER dwType, INTEGER lpData, INTEGER cbData);
#define WinAPI_RegUnLoadKey(hKey, lpSubKey)	RegUnLoadKeyA(hKey, lpSubKey)
#define WinAPI_RegUnLoadKeyA(hKey, lpSubKey)	RegUnLoadKeyA(hKey, lpSubKey)
__EXTERN INTEGER __CALL_1 RegUnLoadKeyA(INTEGER hKey, INTEGER lpSubKey);
#define WinAPI_RegUnLoadKeyW(hKey, lpSubKey)	RegUnLoadKeyW(hKey, lpSubKey)
__EXTERN INTEGER __CALL_1 RegUnLoadKeyW(INTEGER hKey, INTEGER lpSubKey);
#define WinAPI_RegisterClass(lpWndClass, lpWndClass__typ)	RegisterClassA(lpWndClass)
#define WinAPI_RegisterClassA(lpWndClass, lpWndClass__typ)	RegisterClassA(lpWndClass)
__EXTERN SHORTINT __CALL_1 RegisterClassA(WinAPI_WNDCLASSA *lpWndClass);
#define WinAPI_RegisterClassEx(p0, p0__typ)	RegisterClassExA(p0)
#define WinAPI_RegisterClassExA(p0, p0__typ)	RegisterClassExA(p0)
__EXTERN SHORTINT __CALL_1 RegisterClassExA(WinAPI_WNDCLASSEXA *p0);
#define WinAPI_RegisterClassExW(p0, p0__typ)	RegisterClassExW(p0)
__EXTERN SHORTINT __CALL_1 RegisterClassExW(WinAPI_WNDCLASSEXW *p0);
#define WinAPI_RegisterClassW(lpWndClass, lpWndClass__typ)	RegisterClassW(lpWndClass)
__EXTERN SHORTINT __CALL_1 RegisterClassW(WinAPI_WNDCLASSW *lpWndClass);
#define WinAPI_RegisterClipboardFormat(lpszFormat)	RegisterClipboardFormatA(lpszFormat)
#define WinAPI_RegisterClipboardFormatA(lpszFormat)	RegisterClipboardFormatA(lpszFormat)
__EXTERN INTEGER __CALL_1 RegisterClipboardFormatA(INTEGER lpszFormat);
#define WinAPI_RegisterClipboardFormatW(lpszFormat)	RegisterClipboardFormatW(lpszFormat)
__EXTERN INTEGER __CALL_1 RegisterClipboardFormatW(INTEGER lpszFormat);
#define WinAPI_RegisterEventSource(lpUNCServerName, lpSourceName)	RegisterEventSourceA(lpUNCServerName, lpSourceName)
#define WinAPI_RegisterEventSourceA(lpUNCServerName, lpSourceName)	RegisterEventSourceA(lpUNCServerName, lpSourceName)
__EXTERN INTEGER __CALL_1 RegisterEventSourceA(INTEGER lpUNCServerName, INTEGER lpSourceName);
#define WinAPI_RegisterEventSourceW(lpUNCServerName, lpSourceName)	RegisterEventSourceW(lpUNCServerName, lpSourceName)
__EXTERN INTEGER __CALL_1 RegisterEventSourceW(INTEGER lpUNCServerName, INTEGER lpSourceName);
#define WinAPI_RegisterHotKey(hWnd, id, fsModifiers, vk)	RegisterHotKey(hWnd, id, fsModifiers, vk)
__EXTERN INTEGER __CALL_1 RegisterHotKey(INTEGER hWnd, INTEGER id, INTEGER fsModifiers, INTEGER vk);
#define WinAPI_RegisterServiceCtrlHandler(lpServiceName, lpHandlerProc)	RegisterServiceCtrlHandlerA(lpServiceName, lpHandlerProc)
#define WinAPI_RegisterServiceCtrlHandlerA(lpServiceName, lpHandlerProc)	RegisterServiceCtrlHandlerA(lpServiceName, lpHandlerProc)
__EXTERN INTEGER __CALL_1 RegisterServiceCtrlHandlerA(INTEGER lpServiceName, WinAPI_HANDLER_FUNCTION lpHandlerProc);
#define WinAPI_RegisterServiceCtrlHandlerW(lpServiceName, lpHandlerProc)	RegisterServiceCtrlHandlerW(lpServiceName, lpHandlerProc)
__EXTERN INTEGER __CALL_1 RegisterServiceCtrlHandlerW(INTEGER lpServiceName, WinAPI_HANDLER_FUNCTION lpHandlerProc);
#define WinAPI_RegisterWindowMessage(lpString)	RegisterWindowMessageA(lpString)
#define WinAPI_RegisterWindowMessageA(lpString)	RegisterWindowMessageA(lpString)
__EXTERN INTEGER __CALL_1 RegisterWindowMessageA(INTEGER lpString);
#define WinAPI_RegisterWindowMessageW(lpString)	RegisterWindowMessageW(lpString)
__EXTERN INTEGER __CALL_1 RegisterWindowMessageW(INTEGER lpString);
#define WinAPI_ReleaseCapture()	ReleaseCapture()
__EXTERN INTEGER __CALL_1 ReleaseCapture(void);
#define WinAPI_ReleaseDC(hWnd, hDC)	ReleaseDC(hWnd, hDC)
__EXTERN INTEGER __CALL_1 ReleaseDC(INTEGER hWnd, INTEGER hDC);
#define WinAPI_ReleaseMutex(hMutex)	ReleaseMutex(hMutex)
__EXTERN INTEGER __CALL_1 ReleaseMutex(INTEGER hMutex);
#define WinAPI_ReleaseSemaphore(hSemaphore, lReleaseCount, lpPreviousCount)	ReleaseSemaphore(hSemaphore, lReleaseCount, lpPreviousCount)
__EXTERN INTEGER __CALL_1 ReleaseSemaphore(INTEGER hSemaphore, INTEGER lReleaseCount, INTEGER *lpPreviousCount);
#define WinAPI_RemoveDirectory(lpPathName)	RemoveDirectoryA(lpPathName)
#define WinAPI_RemoveDirectoryA(lpPathName)	RemoveDirectoryA(lpPathName)
__EXTERN INTEGER __CALL_1 RemoveDirectoryA(INTEGER lpPathName);
#define WinAPI_RemoveDirectoryW(lpPathName)	RemoveDirectoryW(lpPathName)
__EXTERN INTEGER __CALL_1 RemoveDirectoryW(INTEGER lpPathName);
#define WinAPI_RemoveFontResource(p0)	RemoveFontResourceA(p0)
#define WinAPI_RemoveFontResourceA(p0)	RemoveFontResourceA(p0)
__EXTERN INTEGER __CALL_1 RemoveFontResourceA(INTEGER p0);
#define WinAPI_RemoveFontResourceW(p0)	RemoveFontResourceW(p0)
__EXTERN INTEGER __CALL_1 RemoveFontResourceW(INTEGER p0);
#define WinAPI_RemoveMenu(hMenu, uPosition, uFlags)	RemoveMenu(hMenu, uPosition, uFlags)
__EXTERN INTEGER __CALL_1 RemoveMenu(INTEGER hMenu, INTEGER uPosition, SET uFlags);
#define WinAPI_RemoveProp(hWnd, lpString)	RemovePropA(hWnd, lpString)
#define WinAPI_RemovePropA(hWnd, lpString)	RemovePropA(hWnd, lpString)
__EXTERN INTEGER __CALL_1 RemovePropA(INTEGER hWnd, INTEGER lpString);
#define WinAPI_RemovePropW(hWnd, lpString)	RemovePropW(hWnd, lpString)
__EXTERN INTEGER __CALL_1 RemovePropW(INTEGER hWnd, INTEGER lpString);
#define WinAPI_ReplyMessage(lResult)	ReplyMessage(lResult)
__EXTERN INTEGER __CALL_1 ReplyMessage(INTEGER lResult);
#define WinAPI_ReportEvent(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)	ReportEventA(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)
#define WinAPI_ReportEventA(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)	ReportEventA(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)
__EXTERN INTEGER __CALL_1 ReportEventA(INTEGER hEventLog, SHORTINT wType, SHORTINT wCategory, INTEGER dwEventID, INTEGER lpUserSid, SHORTINT wNumStrings, INTEGER dwDataSize, INTEGER *lpStrings, INTEGER lpRawData);
#define WinAPI_ReportEventW(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)	ReportEventW(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData)
__EXTERN INTEGER __CALL_1 ReportEventW(INTEGER hEventLog, SHORTINT wType, SHORTINT wCategory, INTEGER dwEventID, INTEGER lpUserSid, SHORTINT wNumStrings, INTEGER dwDataSize, INTEGER lpStrings, INTEGER lpRawData);
#define WinAPI_ResetDC(p0, p1, p1__typ)	ResetDCA(p0, p1)
#define WinAPI_ResetDCA(p0, p1, p1__typ)	ResetDCA(p0, p1)
__EXTERN INTEGER __CALL_1 ResetDCA(INTEGER p0, WinAPI_DEVMODEA *p1);
#define WinAPI_ResetDCW(p0, p1, p1__typ)	ResetDCW(p0, p1)
__EXTERN INTEGER __CALL_1 ResetDCW(INTEGER p0, WinAPI_DEVMODEW *p1);
#define WinAPI_ResetEvent(hEvent)	ResetEvent(hEvent)
__EXTERN INTEGER __CALL_1 ResetEvent(INTEGER hEvent);
#define WinAPI_ResetPrinter(hPrinter, pDefault, pDefault__typ)	ResetPrinterA(hPrinter, pDefault)
#define WinAPI_ResetPrinterA(hPrinter, pDefault, pDefault__typ)	ResetPrinterA(hPrinter, pDefault)
__EXTERN INTEGER __CALL_1 ResetPrinterA(INTEGER hPrinter, WinAPI_PRINTER_DEFAULTSA *pDefault);
#define WinAPI_ResetPrinterW(hPrinter, pDefault, pDefault__typ)	ResetPrinterW(hPrinter, pDefault)
__EXTERN INTEGER __CALL_1 ResetPrinterW(INTEGER hPrinter, WinAPI_PRINTER_DEFAULTSW *pDefault);
#define WinAPI_ResizePalette(p0, p1)	ResizePalette(p0, p1)
__EXTERN INTEGER __CALL_1 ResizePalette(INTEGER p0, INTEGER p1);
#define WinAPI_RestoreDC(p0, p1)	RestoreDC(p0, p1)
__EXTERN INTEGER __CALL_1 RestoreDC(INTEGER p0, INTEGER p1);
#define WinAPI_ResumeThread(hThread)	ResumeThread(hThread)
__EXTERN INTEGER __CALL_1 ResumeThread(INTEGER hThread);
#define WinAPI_ReuseDDElParam(lParam, msgIn, msgOut, uiLo, uiHi)	ReuseDDElParam(lParam, msgIn, msgOut, uiLo, uiHi)
__EXTERN INTEGER __CALL_1 ReuseDDElParam(INTEGER lParam, INTEGER msgIn, INTEGER msgOut, INTEGER uiLo, INTEGER uiHi);
#define WinAPI_RevertToSelf()	RevertToSelf()
__EXTERN INTEGER __CALL_1 RevertToSelf(void);
#define WinAPI_RoundRect(p0, p1, p2, p3, p4, p5, p6)	RoundRect(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL_1 RoundRect(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6);
#define WinAPI_RtlUnwind(targetFrame, targetIp, excpRec, retVal)	RtlUnwind(targetFrame, targetIp, excpRec, retVal)
__EXTERN void __CALL_1 RtlUnwind(INTEGER targetFrame, INTEGER targetIp, WinAPI_PtrEXCEPTION_RECORD excpRec, INTEGER retVal);
#define WinAPI_SHAppBarMessage(dwMessage, pData, pData__typ)	SHAppBarMessage(dwMessage, pData)
__EXTERN INTEGER __CALL_1 SHAppBarMessage(INTEGER dwMessage, WinAPI_APPBARDATA *pData);
#define WinAPI_SHFileOperation(lpFileOp, lpFileOp__typ)	SHFileOperationA(lpFileOp)
#define WinAPI_SHFileOperationA(lpFileOp, lpFileOp__typ)	SHFileOperationA(lpFileOp)
__EXTERN INTEGER __CALL_1 SHFileOperationA(WinAPI_SHFILEOPSTRUCTA *lpFileOp);
#define WinAPI_SHFileOperationW(lpFileOp, lpFileOp__typ)	SHFileOperationW(lpFileOp)
__EXTERN INTEGER __CALL_1 SHFileOperationW(WinAPI_SHFILEOPSTRUCTW *lpFileOp);
#define WinAPI_SHFreeNameMappings(hNameMappings)	SHFreeNameMappings(hNameMappings)
__EXTERN void __CALL_1 SHFreeNameMappings(INTEGER hNameMappings);
#define WinAPI_SHGetFileInfo(pszPath, dwFileAttributes, psfi, psfi__typ, cbFileInfo, uFlags)	SHGetFileInfoA(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)
#define WinAPI_SHGetFileInfoA(pszPath, dwFileAttributes, psfi, psfi__typ, cbFileInfo, uFlags)	SHGetFileInfoA(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)
__EXTERN INTEGER __CALL_1 SHGetFileInfoA(INTEGER pszPath, SET dwFileAttributes, WinAPI_SHFILEINFOA *psfi, INTEGER cbFileInfo, SET uFlags);
#define WinAPI_SHGetFileInfoW(pszPath, dwFileAttributes, psfi, psfi__typ, cbFileInfo, uFlags)	SHGetFileInfoW(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags)
__EXTERN INTEGER __CALL_1 SHGetFileInfoW(INTEGER pszPath, SET dwFileAttributes, WinAPI_SHFILEINFOW *psfi, INTEGER cbFileInfo, SET uFlags);
#define WinAPI_SHGetNewLinkInfo(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)	SHGetNewLinkInfoA(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)
#define WinAPI_SHGetNewLinkInfoA(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)	SHGetNewLinkInfoA(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)
__EXTERN INTEGER __CALL_1 SHGetNewLinkInfoA(INTEGER pszLinkTo, INTEGER pszDir, INTEGER pszName, INTEGER *pfMustCopy, SET uFlags);
#define WinAPI_SHGetNewLinkInfoW(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)	SHGetNewLinkInfoW(pszLinkTo, pszDir, pszName, pfMustCopy, uFlags)
__EXTERN INTEGER __CALL_1 SHGetNewLinkInfoW(INTEGER pszLinkTo, INTEGER pszDir, INTEGER pszName, INTEGER *pfMustCopy, SET uFlags);
#define WinAPI_SaveDC(p0)	SaveDC(p0)
__EXTERN INTEGER __CALL_1 SaveDC(INTEGER p0);
#define WinAPI_ScaleViewportExtEx(p0, p1, p2, p3, p4, p5, p5__typ)	ScaleViewportExtEx(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 ScaleViewportExtEx(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_SIZE *p5);
#define WinAPI_ScaleWindowExtEx(p0, p1, p2, p3, p4, p5, p5__typ)	ScaleWindowExtEx(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 ScaleWindowExtEx(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_SIZE *p5);
#define WinAPI_ScheduleJob(hPrinter, JobId)	ScheduleJob(hPrinter, JobId)
__EXTERN INTEGER __CALL_1 ScheduleJob(INTEGER hPrinter, INTEGER JobId);
#define WinAPI_ScreenToClient(hWnd, lpPoint, lpPoint__typ)	ScreenToClient(hWnd, lpPoint)
__EXTERN INTEGER __CALL_1 ScreenToClient(INTEGER hWnd, WinAPI_POINT *lpPoint);
#define WinAPI_ScrollConsoleScreenBuffer(hConsoleOutput, lpScrollRectangle, lpScrollRectangle__typ, lpClipRectangle, lpClipRectangle__typ, dwDestinationOrigin, lpFill, lpFill__typ)	ScrollConsoleScreenBufferA(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)
#define WinAPI_ScrollConsoleScreenBufferA(hConsoleOutput, lpScrollRectangle, lpScrollRectangle__typ, lpClipRectangle, lpClipRectangle__typ, dwDestinationOrigin, lpFill, lpFill__typ)	ScrollConsoleScreenBufferA(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)
__EXTERN INTEGER __CALL_1 ScrollConsoleScreenBufferA(INTEGER hConsoleOutput, WinAPI_SMALL_RECT *lpScrollRectangle, WinAPI_SMALL_RECT *lpClipRectangle, WinAPI_COORD dwDestinationOrigin, WinAPI_CHAR_INFO *lpFill);
#define WinAPI_ScrollConsoleScreenBufferW(hConsoleOutput, lpScrollRectangle, lpScrollRectangle__typ, lpClipRectangle, lpClipRectangle__typ, dwDestinationOrigin, lpFill, lpFill__typ)	ScrollConsoleScreenBufferW(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill)
__EXTERN INTEGER __CALL_1 ScrollConsoleScreenBufferW(INTEGER hConsoleOutput, WinAPI_SMALL_RECT *lpScrollRectangle, WinAPI_SMALL_RECT *lpClipRectangle, WinAPI_COORD dwDestinationOrigin, WinAPI_CHAR_INFO *lpFill);
#define WinAPI_ScrollDC(hDC, dx, dy, lprcScroll, lprcScroll__typ, lprcClip, lprcClip__typ, hrgnUpdate, lprcUpdate, lprcUpdate__typ)	ScrollDC(hDC, dx, dy, lprcScroll, lprcClip, hrgnUpdate, lprcUpdate)
__EXTERN INTEGER __CALL_1 ScrollDC(INTEGER hDC, INTEGER dx, INTEGER dy, WinAPI_RECT *lprcScroll, WinAPI_RECT *lprcClip, INTEGER hrgnUpdate, WinAPI_RECT *lprcUpdate);
#define WinAPI_ScrollWindow(hWnd, XAmount, YAmount, lpRect, lpRect__typ, lpClipRect, lpClipRect__typ)	ScrollWindow(hWnd, XAmount, YAmount, lpRect, lpClipRect)
__EXTERN INTEGER __CALL_1 ScrollWindow(INTEGER hWnd, INTEGER XAmount, INTEGER YAmount, WinAPI_RECT *lpRect, WinAPI_RECT *lpClipRect);
#define WinAPI_ScrollWindowEx(hWnd, dx, dy, prcScroll, prcScroll__typ, prcClip, prcClip__typ, hrgnUpdate, prcUpdate, prcUpdate__typ, flags)	ScrollWindowEx(hWnd, dx, dy, prcScroll, prcClip, hrgnUpdate, prcUpdate, flags)
__EXTERN INTEGER __CALL_1 ScrollWindowEx(INTEGER hWnd, INTEGER dx, INTEGER dy, WinAPI_RECT *prcScroll, WinAPI_RECT *prcClip, INTEGER hrgnUpdate, WinAPI_RECT *prcUpdate, SET flags);
#define WinAPI_SearchPath(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)	SearchPathA(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)
#define WinAPI_SearchPathA(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)	SearchPathA(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)
__EXTERN INTEGER __CALL_1 SearchPathA(INTEGER lpPath, INTEGER lpFileName, INTEGER lpExtension, INTEGER nBufferLength, INTEGER lpBuffer, INTEGER *lpFilePart);
#define WinAPI_SearchPathW(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)	SearchPathW(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart)
__EXTERN INTEGER __CALL_1 SearchPathW(INTEGER lpPath, INTEGER lpFileName, INTEGER lpExtension, INTEGER nBufferLength, INTEGER lpBuffer, INTEGER *lpFilePart);
#define WinAPI_SelectClipPath(p0, p1)	SelectClipPath(p0, p1)
__EXTERN INTEGER __CALL_1 SelectClipPath(INTEGER p0, INTEGER p1);
#define WinAPI_SelectClipRgn(p0, p1)	SelectClipRgn(p0, p1)
__EXTERN INTEGER __CALL_1 SelectClipRgn(INTEGER p0, INTEGER p1);
#define WinAPI_SelectObject(p0, p1)	SelectObject(p0, p1)
__EXTERN INTEGER __CALL_1 SelectObject(INTEGER p0, INTEGER p1);
#define WinAPI_SelectPalette(p0, p1, p2)	SelectPalette(p0, p1, p2)
__EXTERN INTEGER __CALL_1 SelectPalette(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_SendDlgItemMessage(hDlg, nIDDlgItem, Msg, wParam, lParam)	SendDlgItemMessageA(hDlg, nIDDlgItem, Msg, wParam, lParam)
#define WinAPI_SendDlgItemMessageA(hDlg, nIDDlgItem, Msg, wParam, lParam)	SendDlgItemMessageA(hDlg, nIDDlgItem, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 SendDlgItemMessageA(INTEGER hDlg, INTEGER nIDDlgItem, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_SendDlgItemMessageW(hDlg, nIDDlgItem, Msg, wParam, lParam)	SendDlgItemMessageW(hDlg, nIDDlgItem, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 SendDlgItemMessageW(INTEGER hDlg, INTEGER nIDDlgItem, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_SendMessage(hWnd, Msg, wParam, lParam)	SendMessageA(hWnd, Msg, wParam, lParam)
#define WinAPI_SendMessageA(hWnd, Msg, wParam, lParam)	SendMessageA(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 SendMessageA(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_SendMessageCallback(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)	SendMessageCallbackA(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)
#define WinAPI_SendMessageCallbackA(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)	SendMessageCallbackA(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)
__EXTERN INTEGER __CALL_1 SendMessageCallbackA(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam, WinAPI_SENDASYNCPROC lpResultCallBack, INTEGER dwData);
#define WinAPI_SendMessageCallbackW(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)	SendMessageCallbackW(hWnd, Msg, wParam, lParam, lpResultCallBack, dwData)
__EXTERN INTEGER __CALL_1 SendMessageCallbackW(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam, WinAPI_SENDASYNCPROC lpResultCallBack, INTEGER dwData);
#define WinAPI_SendMessageTimeout(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)	SendMessageTimeoutA(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)
#define WinAPI_SendMessageTimeoutA(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)	SendMessageTimeoutA(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)
__EXTERN INTEGER __CALL_1 SendMessageTimeoutA(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam, SET fuFlags, INTEGER uTimeout, INTEGER *lpdwResult);
#define WinAPI_SendMessageTimeoutW(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)	SendMessageTimeoutW(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult)
__EXTERN INTEGER __CALL_1 SendMessageTimeoutW(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam, SET fuFlags, INTEGER uTimeout, INTEGER *lpdwResult);
#define WinAPI_SendMessageW(hWnd, Msg, wParam, lParam)	SendMessageW(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 SendMessageW(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_SendNotifyMessage(hWnd, Msg, wParam, lParam)	SendNotifyMessageA(hWnd, Msg, wParam, lParam)
#define WinAPI_SendNotifyMessageA(hWnd, Msg, wParam, lParam)	SendNotifyMessageA(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 SendNotifyMessageA(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_SendNotifyMessageW(hWnd, Msg, wParam, lParam)	SendNotifyMessageW(hWnd, Msg, wParam, lParam)
__EXTERN INTEGER __CALL_1 SendNotifyMessageW(INTEGER hWnd, INTEGER Msg, INTEGER wParam, INTEGER lParam);
#define WinAPI_SetAbortProc(p0, p1)	SetAbortProc(p0, p1)
__EXTERN INTEGER __CALL_1 SetAbortProc(INTEGER p0, WinAPI_ABORTPROC p1);
#define WinAPI_SetAclInformation(pAcl, pAcl__typ, pAclInformation, nAclInformationLength, dwAclInformationClass)	SetAclInformation(pAcl, pAclInformation, nAclInformationLength, dwAclInformationClass)
__EXTERN INTEGER __CALL_1 SetAclInformation(WinAPI_ACL *pAcl, INTEGER pAclInformation, INTEGER nAclInformationLength, INTEGER dwAclInformationClass);
#define WinAPI_SetActiveWindow(hWnd)	SetActiveWindow(hWnd)
__EXTERN INTEGER __CALL_1 SetActiveWindow(INTEGER hWnd);
#define WinAPI_SetArcDirection(p0, p1)	SetArcDirection(p0, p1)
__EXTERN INTEGER __CALL_1 SetArcDirection(INTEGER p0, INTEGER p1);
#define WinAPI_SetBitmapBits(p0, p1, p2)	SetBitmapBits(p0, p1, p2)
__EXTERN INTEGER __CALL_1 SetBitmapBits(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_SetBitmapDimensionEx(p0, p1, p2, p3, p3__typ)	SetBitmapDimensionEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetBitmapDimensionEx(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_SetBkColor(p0, p1)	SetBkColor(p0, p1)
__EXTERN INTEGER __CALL_1 SetBkColor(INTEGER p0, INTEGER p1);
#define WinAPI_SetBkMode(p0, p1)	SetBkMode(p0, p1)
__EXTERN INTEGER __CALL_1 SetBkMode(INTEGER p0, INTEGER p1);
#define WinAPI_SetBoundsRect(p0, p1, p1__typ, p2)	SetBoundsRect(p0, p1, p2)
__EXTERN SET __CALL_1 SetBoundsRect(INTEGER p0, WinAPI_RECT *p1, SET p2);
#define WinAPI_SetBrushOrgEx(p0, p1, p2, p3, p3__typ)	SetBrushOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetBrushOrgEx(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_SetCapture(hWnd)	SetCapture(hWnd)
__EXTERN INTEGER __CALL_1 SetCapture(INTEGER hWnd);
#define WinAPI_SetCaretBlinkTime(uMSeconds)	SetCaretBlinkTime(uMSeconds)
__EXTERN INTEGER __CALL_1 SetCaretBlinkTime(INTEGER uMSeconds);
#define WinAPI_SetCaretPos(X, Y)	SetCaretPos(X, Y)
__EXTERN INTEGER __CALL_1 SetCaretPos(INTEGER X, INTEGER Y);
#define WinAPI_SetClassLong(hWnd, nIndex, dwNewLong)	SetClassLongA(hWnd, nIndex, dwNewLong)
#define WinAPI_SetClassLongA(hWnd, nIndex, dwNewLong)	SetClassLongA(hWnd, nIndex, dwNewLong)
__EXTERN INTEGER __CALL_1 SetClassLongA(INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong);
#define WinAPI_SetClassLongW(hWnd, nIndex, dwNewLong)	SetClassLongW(hWnd, nIndex, dwNewLong)
__EXTERN INTEGER __CALL_1 SetClassLongW(INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong);
#define WinAPI_SetClassWord(hWnd, nIndex, wNewWord)	SetClassWord(hWnd, nIndex, wNewWord)
__EXTERN SHORTINT __CALL_1 SetClassWord(INTEGER hWnd, INTEGER nIndex, SHORTINT wNewWord);
#define WinAPI_SetClipboardData(uFormat, hMem)	SetClipboardData(uFormat, hMem)
__EXTERN INTEGER __CALL_1 SetClipboardData(INTEGER uFormat, INTEGER hMem);
#define WinAPI_SetClipboardViewer(hWndNewViewer)	SetClipboardViewer(hWndNewViewer)
__EXTERN INTEGER __CALL_1 SetClipboardViewer(INTEGER hWndNewViewer);
#define WinAPI_SetColorAdjustment(p0, p1, p1__typ)	SetColorAdjustment(p0, p1)
__EXTERN INTEGER __CALL_1 SetColorAdjustment(INTEGER p0, WinAPI_COLORADJUSTMENT *p1);
#define WinAPI_SetColorSpace(p0, p1)	SetColorSpace(p0, p1)
__EXTERN INTEGER __CALL_1 SetColorSpace(INTEGER p0, INTEGER p1);
#define WinAPI_SetCommBreak(hFile)	SetCommBreak(hFile)
__EXTERN INTEGER __CALL_1 SetCommBreak(INTEGER hFile);
#define WinAPI_SetCommConfig(hCommDev, lpCC, lpCC__typ, dwSize)	SetCommConfig(hCommDev, lpCC, dwSize)
__EXTERN INTEGER __CALL_1 SetCommConfig(INTEGER hCommDev, WinAPI_COMMCONFIG *lpCC, INTEGER dwSize);
#define WinAPI_SetCommMask(hFile, dwEvtMask)	SetCommMask(hFile, dwEvtMask)
__EXTERN INTEGER __CALL_1 SetCommMask(INTEGER hFile, SET dwEvtMask);
#define WinAPI_SetCommState(hFile, lpDCB, lpDCB__typ)	SetCommState(hFile, lpDCB)
__EXTERN INTEGER __CALL_1 SetCommState(INTEGER hFile, WinAPI_DCB *lpDCB);
#define WinAPI_SetCommTimeouts(hFile, lpCommTimeouts, lpCommTimeouts__typ)	SetCommTimeouts(hFile, lpCommTimeouts)
__EXTERN INTEGER __CALL_1 SetCommTimeouts(INTEGER hFile, WinAPI_COMMTIMEOUTS *lpCommTimeouts);
#define WinAPI_SetComputerName(lpComputerName)	SetComputerNameA(lpComputerName)
#define WinAPI_SetComputerNameA(lpComputerName)	SetComputerNameA(lpComputerName)
__EXTERN INTEGER __CALL_1 SetComputerNameA(INTEGER lpComputerName);
#define WinAPI_SetComputerNameW(lpComputerName)	SetComputerNameW(lpComputerName)
__EXTERN INTEGER __CALL_1 SetComputerNameW(INTEGER lpComputerName);
#define WinAPI_SetConsoleActiveScreenBuffer(hConsoleOutput)	SetConsoleActiveScreenBuffer(hConsoleOutput)
__EXTERN INTEGER __CALL_1 SetConsoleActiveScreenBuffer(INTEGER hConsoleOutput);
#define WinAPI_SetConsoleCP(wCodePageID)	SetConsoleCP(wCodePageID)
__EXTERN INTEGER __CALL_1 SetConsoleCP(INTEGER wCodePageID);
#define WinAPI_SetConsoleCtrlHandler(HandlerRoutine, Add)	SetConsoleCtrlHandler(HandlerRoutine, Add)
__EXTERN INTEGER __CALL_1 SetConsoleCtrlHandler(WinAPI_HANDLER_ROUTINE HandlerRoutine, INTEGER Add);
#define WinAPI_SetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo, lpConsoleCursorInfo__typ)	SetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo)
__EXTERN INTEGER __CALL_1 SetConsoleCursorInfo(INTEGER hConsoleOutput, WinAPI_CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
#define WinAPI_SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition)	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition)
__EXTERN INTEGER __CALL_1 SetConsoleCursorPosition(INTEGER hConsoleOutput, WinAPI_COORD dwCursorPosition);
#define WinAPI_SetConsoleMode(hConsoleHandle, dwMode)	SetConsoleMode(hConsoleHandle, dwMode)
__EXTERN INTEGER __CALL_1 SetConsoleMode(INTEGER hConsoleHandle, SET dwMode);
#define WinAPI_SetConsoleOutputCP(wCodePageID)	SetConsoleOutputCP(wCodePageID)
__EXTERN INTEGER __CALL_1 SetConsoleOutputCP(INTEGER wCodePageID);
#define WinAPI_SetConsoleScreenBufferSize(hConsoleOutput, dwSize)	SetConsoleScreenBufferSize(hConsoleOutput, dwSize)
__EXTERN INTEGER __CALL_1 SetConsoleScreenBufferSize(INTEGER hConsoleOutput, WinAPI_COORD dwSize);
#define WinAPI_SetConsoleTextAttribute(hConsoleOutput, wAttributes)	SetConsoleTextAttribute(hConsoleOutput, wAttributes)
__EXTERN INTEGER __CALL_1 SetConsoleTextAttribute(INTEGER hConsoleOutput, SHORTINT wAttributes);
#define WinAPI_SetConsoleTitle(lpConsoleTitle)	SetConsoleTitleA(lpConsoleTitle)
#define WinAPI_SetConsoleTitleA(lpConsoleTitle)	SetConsoleTitleA(lpConsoleTitle)
__EXTERN INTEGER __CALL_1 SetConsoleTitleA(INTEGER lpConsoleTitle);
#define WinAPI_SetConsoleTitleW(lpConsoleTitle)	SetConsoleTitleW(lpConsoleTitle)
__EXTERN INTEGER __CALL_1 SetConsoleTitleW(INTEGER lpConsoleTitle);
#define WinAPI_SetConsoleWindowInfo(hConsoleOutput, bAbsolute, lpConsoleWindow, lpConsoleWindow__typ)	SetConsoleWindowInfo(hConsoleOutput, bAbsolute, lpConsoleWindow)
__EXTERN INTEGER __CALL_1 SetConsoleWindowInfo(INTEGER hConsoleOutput, INTEGER bAbsolute, WinAPI_SMALL_RECT *lpConsoleWindow);
#define WinAPI_SetCurrentDirectory(lpPathName)	SetCurrentDirectoryA(lpPathName)
#define WinAPI_SetCurrentDirectoryA(lpPathName)	SetCurrentDirectoryA(lpPathName)
__EXTERN INTEGER __CALL_1 SetCurrentDirectoryA(INTEGER lpPathName);
#define WinAPI_SetCurrentDirectoryW(lpPathName)	SetCurrentDirectoryW(lpPathName)
__EXTERN INTEGER __CALL_1 SetCurrentDirectoryW(INTEGER lpPathName);
#define WinAPI_SetCursor(hCursor)	SetCursor(hCursor)
__EXTERN INTEGER __CALL_1 SetCursor(INTEGER hCursor);
#define WinAPI_SetCursorPos(X, Y)	SetCursorPos(X, Y)
__EXTERN INTEGER __CALL_1 SetCursorPos(INTEGER X, INTEGER Y);
#define WinAPI_SetDIBColorTable(p0, p1, p2, p3, p3__len)	SetDIBColorTable(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetDIBColorTable(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_RGBQUAD *p3);
#define WinAPI_SetDIBits(p0, p1, p2, p3, p4, p5, p5__typ, p6)	SetDIBits(p0, p1, p2, p3, p4, p5, p6)
__EXTERN INTEGER __CALL_1 SetDIBits(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_BITMAPINFO *p5, INTEGER p6);
#define WinAPI_SetDIBitsToDevice(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p10__typ, p11)	SetDIBitsToDevice(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)
__EXTERN INTEGER __CALL_1 SetDIBitsToDevice(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, WinAPI_BITMAPINFO *p10, INTEGER p11);
#define WinAPI_SetDebugErrorLevel(dwLevel)	SetDebugErrorLevel(dwLevel)
__EXTERN void __CALL_1 SetDebugErrorLevel(INTEGER dwLevel);
#define WinAPI_SetDefaultCommConfig(lpszName, lpCC, lpCC__typ, dwSize)	SetDefaultCommConfigA(lpszName, lpCC, dwSize)
#define WinAPI_SetDefaultCommConfigA(lpszName, lpCC, lpCC__typ, dwSize)	SetDefaultCommConfigA(lpszName, lpCC, dwSize)
__EXTERN INTEGER __CALL_1 SetDefaultCommConfigA(INTEGER lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER dwSize);
#define WinAPI_SetDefaultCommConfigW(lpszName, lpCC, lpCC__typ, dwSize)	SetDefaultCommConfigW(lpszName, lpCC, dwSize)
__EXTERN INTEGER __CALL_1 SetDefaultCommConfigW(INTEGER lpszName, WinAPI_COMMCONFIG *lpCC, INTEGER dwSize);
#define WinAPI_SetDeviceGammaRamp(p0, p1)	SetDeviceGammaRamp(p0, p1)
__EXTERN INTEGER __CALL_1 SetDeviceGammaRamp(INTEGER p0, INTEGER p1);
#define WinAPI_SetDlgItemInt(hDlg, nIDDlgItem, uValue, bSigned)	SetDlgItemInt(hDlg, nIDDlgItem, uValue, bSigned)
__EXTERN INTEGER __CALL_1 SetDlgItemInt(INTEGER hDlg, INTEGER nIDDlgItem, INTEGER uValue, INTEGER bSigned);
#define WinAPI_SetDlgItemText(hDlg, nIDDlgItem, lpString)	SetDlgItemTextA(hDlg, nIDDlgItem, lpString)
#define WinAPI_SetDlgItemTextA(hDlg, nIDDlgItem, lpString)	SetDlgItemTextA(hDlg, nIDDlgItem, lpString)
__EXTERN INTEGER __CALL_1 SetDlgItemTextA(INTEGER hDlg, INTEGER nIDDlgItem, INTEGER lpString);
#define WinAPI_SetDlgItemTextW(hDlg, nIDDlgItem, lpString)	SetDlgItemTextW(hDlg, nIDDlgItem, lpString)
__EXTERN INTEGER __CALL_1 SetDlgItemTextW(INTEGER hDlg, INTEGER nIDDlgItem, INTEGER lpString);
#define WinAPI_SetDoubleClickTime(p0)	SetDoubleClickTime(p0)
__EXTERN INTEGER __CALL_1 SetDoubleClickTime(INTEGER p0);
#define WinAPI_SetEndOfFile(hFile)	SetEndOfFile(hFile)
__EXTERN INTEGER __CALL_1 SetEndOfFile(INTEGER hFile);
#define WinAPI_SetEnhMetaFileBits(p0, p1)	SetEnhMetaFileBits(p0, p1)
__EXTERN INTEGER __CALL_1 SetEnhMetaFileBits(INTEGER p0, CHAR *p1);
#define WinAPI_SetEnvironmentVariable(lpName, lpValue)	SetEnvironmentVariableA(lpName, lpValue)
#define WinAPI_SetEnvironmentVariableA(lpName, lpValue)	SetEnvironmentVariableA(lpName, lpValue)
__EXTERN INTEGER __CALL_1 SetEnvironmentVariableA(INTEGER lpName, INTEGER lpValue);
#define WinAPI_SetEnvironmentVariableW(lpName, lpValue)	SetEnvironmentVariableW(lpName, lpValue)
__EXTERN INTEGER __CALL_1 SetEnvironmentVariableW(INTEGER lpName, INTEGER lpValue);
#define WinAPI_SetErrorMode(uMode)	SetErrorMode(uMode)
__EXTERN INTEGER __CALL_1 SetErrorMode(SET uMode);
#define WinAPI_SetEvent(hEvent)	SetEvent(hEvent)
__EXTERN INTEGER __CALL_1 SetEvent(INTEGER hEvent);
#define WinAPI_SetFileApisToANSI()	SetFileApisToANSI()
__EXTERN void __CALL_1 SetFileApisToANSI(void);
#define WinAPI_SetFileApisToOEM()	SetFileApisToOEM()
__EXTERN void __CALL_1 SetFileApisToOEM(void);
#define WinAPI_SetFileAttributes(lpFileName, dwFileAttributes)	SetFileAttributesA(lpFileName, dwFileAttributes)
#define WinAPI_SetFileAttributesA(lpFileName, dwFileAttributes)	SetFileAttributesA(lpFileName, dwFileAttributes)
__EXTERN INTEGER __CALL_1 SetFileAttributesA(INTEGER lpFileName, SET dwFileAttributes);
#define WinAPI_SetFileAttributesW(lpFileName, dwFileAttributes)	SetFileAttributesW(lpFileName, dwFileAttributes)
__EXTERN INTEGER __CALL_1 SetFileAttributesW(INTEGER lpFileName, SET dwFileAttributes);
#define WinAPI_SetFilePointer(hFile, lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod)	SetFilePointer(hFile, lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod)
__EXTERN INTEGER __CALL_1 SetFilePointer(INTEGER hFile, INTEGER lDistanceToMove, INTEGER *lpDistanceToMoveHigh, INTEGER dwMoveMethod);
#define WinAPI_SetFileSecurity(lpFileName, SecurityInformation, pSecurityDescriptor)	SetFileSecurityA(lpFileName, SecurityInformation, pSecurityDescriptor)
#define WinAPI_SetFileSecurityA(lpFileName, SecurityInformation, pSecurityDescriptor)	SetFileSecurityA(lpFileName, SecurityInformation, pSecurityDescriptor)
__EXTERN INTEGER __CALL_1 SetFileSecurityA(INTEGER lpFileName, SET SecurityInformation, INTEGER pSecurityDescriptor);
#define WinAPI_SetFileSecurityW(lpFileName, SecurityInformation, pSecurityDescriptor)	SetFileSecurityW(lpFileName, SecurityInformation, pSecurityDescriptor)
__EXTERN INTEGER __CALL_1 SetFileSecurityW(INTEGER lpFileName, SET SecurityInformation, INTEGER pSecurityDescriptor);
#define WinAPI_SetFileTime(hFile, lpCreationTime, lpCreationTime__typ, lpLastAccessTime, lpLastAccessTime__typ, lpLastWriteTime, lpLastWriteTime__typ)	SetFileTime(hFile, lpCreationTime, lpLastAccessTime, lpLastWriteTime)
__EXTERN INTEGER __CALL_1 SetFileTime(INTEGER hFile, WinAPI_FILETIME *lpCreationTime, WinAPI_FILETIME *lpLastAccessTime, WinAPI_FILETIME *lpLastWriteTime);
#define WinAPI_SetFocus(hWnd)	SetFocus(hWnd)
__EXTERN INTEGER __CALL_1 SetFocus(INTEGER hWnd);
#define WinAPI_SetForegroundWindow(hWnd)	SetForegroundWindow(hWnd)
__EXTERN INTEGER __CALL_1 SetForegroundWindow(INTEGER hWnd);
#define WinAPI_SetForm(hPrinter, pFormName, Level, pForm)	SetFormA(hPrinter, pFormName, Level, pForm)
#define WinAPI_SetFormA(hPrinter, pFormName, Level, pForm)	SetFormA(hPrinter, pFormName, Level, pForm)
__EXTERN INTEGER __CALL_1 SetFormA(INTEGER hPrinter, INTEGER pFormName, INTEGER Level, CHAR *pForm);
#define WinAPI_SetFormW(hPrinter, pFormName, Level, pForm)	SetFormW(hPrinter, pFormName, Level, pForm)
__EXTERN INTEGER __CALL_1 SetFormW(INTEGER hPrinter, INTEGER pFormName, INTEGER Level, CHAR *pForm);
#define WinAPI_SetGraphicsMode(hdc, iMode)	SetGraphicsMode(hdc, iMode)
__EXTERN INTEGER __CALL_1 SetGraphicsMode(INTEGER hdc, INTEGER iMode);
#define WinAPI_SetHandleCount(uNumber)	SetHandleCount(uNumber)
__EXTERN INTEGER __CALL_1 SetHandleCount(INTEGER uNumber);
#define WinAPI_SetHandleInformation(hObject, dwMask, dwFlags)	SetHandleInformation(hObject, dwMask, dwFlags)
__EXTERN INTEGER __CALL_1 SetHandleInformation(INTEGER hObject, INTEGER dwMask, SET dwFlags);
#define WinAPI_SetICMMode(p0, p1)	SetICMMode(p0, p1)
__EXTERN INTEGER __CALL_1 SetICMMode(INTEGER p0, INTEGER p1);
#define WinAPI_SetICMProfile(p0, p1)	SetICMProfileA(p0, p1)
#define WinAPI_SetICMProfileA(p0, p1)	SetICMProfileA(p0, p1)
__EXTERN INTEGER __CALL_1 SetICMProfileA(INTEGER p0, INTEGER p1);
#define WinAPI_SetICMProfileW(p0, p1)	SetICMProfileW(p0, p1)
__EXTERN INTEGER __CALL_1 SetICMProfileW(INTEGER p0, INTEGER p1);
#define WinAPI_SetJob(hPrinter, JobId, Level, pJob, Command)	SetJobA(hPrinter, JobId, Level, pJob, Command)
#define WinAPI_SetJobA(hPrinter, JobId, Level, pJob, Command)	SetJobA(hPrinter, JobId, Level, pJob, Command)
__EXTERN INTEGER __CALL_1 SetJobA(INTEGER hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER Command);
#define WinAPI_SetJobW(hPrinter, JobId, Level, pJob, Command)	SetJobW(hPrinter, JobId, Level, pJob, Command)
__EXTERN INTEGER __CALL_1 SetJobW(INTEGER hPrinter, INTEGER JobId, INTEGER Level, CHAR *pJob, INTEGER Command);
#define WinAPI_SetKernelObjectSecurity(Handle, SecurityInformation, SecurityDescriptor)	SetKernelObjectSecurity(Handle, SecurityInformation, SecurityDescriptor)
__EXTERN INTEGER __CALL_1 SetKernelObjectSecurity(INTEGER Handle, SET SecurityInformation, INTEGER SecurityDescriptor);
#define WinAPI_SetKeyboardState(lpKeyState)	SetKeyboardState(lpKeyState)
__EXTERN INTEGER __CALL_1 SetKeyboardState(CHAR *lpKeyState);
#define WinAPI_SetLastError(dwErrCode)	SetLastError(dwErrCode)
__EXTERN void __CALL_1 SetLastError(INTEGER dwErrCode);
#define WinAPI_SetLastErrorEx(dwErrCode, dwType)	SetLastErrorEx(dwErrCode, dwType)
__EXTERN void __CALL_1 SetLastErrorEx(INTEGER dwErrCode, INTEGER dwType);
#define WinAPI_SetLocalTime(lpSystemTime, lpSystemTime__typ)	SetLocalTime(lpSystemTime)
__EXTERN INTEGER __CALL_1 SetLocalTime(WinAPI_SYSTEMTIME *lpSystemTime);
#define WinAPI_SetLocaleInfo(Locale, LCType, lpLCData)	SetLocaleInfoA(Locale, LCType, lpLCData)
#define WinAPI_SetLocaleInfoA(Locale, LCType, lpLCData)	SetLocaleInfoA(Locale, LCType, lpLCData)
__EXTERN INTEGER __CALL_1 SetLocaleInfoA(INTEGER Locale, INTEGER LCType, INTEGER lpLCData);
#define WinAPI_SetLocaleInfoW(Locale, LCType, lpLCData)	SetLocaleInfoW(Locale, LCType, lpLCData)
__EXTERN INTEGER __CALL_1 SetLocaleInfoW(INTEGER Locale, INTEGER LCType, INTEGER lpLCData);
#define WinAPI_SetMailslotInfo(hMailslot, lReadTimeout)	SetMailslotInfo(hMailslot, lReadTimeout)
__EXTERN INTEGER __CALL_1 SetMailslotInfo(INTEGER hMailslot, INTEGER lReadTimeout);
#define WinAPI_SetMapMode(p0, p1)	SetMapMode(p0, p1)
__EXTERN INTEGER __CALL_1 SetMapMode(INTEGER p0, INTEGER p1);
#define WinAPI_SetMapperFlags(p0, p1)	SetMapperFlags(p0, p1)
__EXTERN INTEGER __CALL_1 SetMapperFlags(INTEGER p0, INTEGER p1);
#define WinAPI_SetMenu(hWnd, hMenu)	SetMenu(hWnd, hMenu)
__EXTERN INTEGER __CALL_1 SetMenu(INTEGER hWnd, INTEGER hMenu);
#define WinAPI_SetMenuContextHelpId(p0, p1)	SetMenuContextHelpId(p0, p1)
__EXTERN INTEGER __CALL_1 SetMenuContextHelpId(INTEGER p0, INTEGER p1);
#define WinAPI_SetMenuDefaultItem(hMenu, uItem, fByPos)	SetMenuDefaultItem(hMenu, uItem, fByPos)
__EXTERN INTEGER __CALL_1 SetMenuDefaultItem(INTEGER hMenu, INTEGER uItem, INTEGER fByPos);
#define WinAPI_SetMenuItemBitmaps(hMenu, uPosition, uFlags, hBitmapUnchecked, hBitmapChecked)	SetMenuItemBitmaps(hMenu, uPosition, uFlags, hBitmapUnchecked, hBitmapChecked)
__EXTERN INTEGER __CALL_1 SetMenuItemBitmaps(INTEGER hMenu, INTEGER uPosition, SET uFlags, INTEGER hBitmapUnchecked, INTEGER hBitmapChecked);
#define WinAPI_SetMenuItemInfo(p0, p1, p2, p3, p3__typ)	SetMenuItemInfoA(p0, p1, p2, p3)
#define WinAPI_SetMenuItemInfoA(p0, p1, p2, p3, p3__typ)	SetMenuItemInfoA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetMenuItemInfoA(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOA *p3);
#define WinAPI_SetMenuItemInfoW(p0, p1, p2, p3, p3__typ)	SetMenuItemInfoW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetMenuItemInfoW(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_MENUITEMINFOW *p3);
#define WinAPI_SetMessageExtraInfo(lParam)	SetMessageExtraInfo(lParam)
__EXTERN INTEGER __CALL_1 SetMessageExtraInfo(INTEGER lParam);
#define WinAPI_SetMessageQueue(cMessagesMax)	SetMessageQueue(cMessagesMax)
__EXTERN INTEGER __CALL_1 SetMessageQueue(INTEGER cMessagesMax);
#define WinAPI_SetMetaFileBitsEx(p0, p1, p1__len)	SetMetaFileBitsEx(p0, p1)
__EXTERN INTEGER __CALL_1 SetMetaFileBitsEx(INTEGER p0, BYTE *p1);
#define WinAPI_SetMetaRgn(p0)	SetMetaRgn(p0)
__EXTERN INTEGER __CALL_1 SetMetaRgn(INTEGER p0);
#define WinAPI_SetMiterLimit(p0, p1, p2)	SetMiterLimit(p0, p1, p2)
__EXTERN INTEGER __CALL_1 SetMiterLimit(INTEGER p0, REAL p1, REAL *p2);
#define WinAPI_SetNamedPipeHandleState(hNamedPipe, lpMode, lpMaxCollectionCount, lpCollectDataTimeout)	SetNamedPipeHandleState(hNamedPipe, lpMode, lpMaxCollectionCount, lpCollectDataTimeout)
__EXTERN INTEGER __CALL_1 SetNamedPipeHandleState(INTEGER hNamedPipe, INTEGER *lpMode, INTEGER *lpMaxCollectionCount, INTEGER *lpCollectDataTimeout);
#define WinAPI_SetPaletteEntries(p0, p1, p2, p3, p3__typ)	SetPaletteEntries(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetPaletteEntries(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_PALETTEENTRY *p3);
#define WinAPI_SetParent(hWndChild, hWndNewParent)	SetParent(hWndChild, hWndNewParent)
__EXTERN INTEGER __CALL_1 SetParent(INTEGER hWndChild, INTEGER hWndNewParent);
#define WinAPI_SetPixel(p0, p1, p2, p3)	SetPixel(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetPixel(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_SetPixelFormat(p0, p1, p2, p2__typ)	SetPixelFormat(p0, p1, p2)
__EXTERN INTEGER __CALL_1 SetPixelFormat(INTEGER p0, INTEGER p1, WinAPI_PIXELFORMATDESCRIPTOR *p2);
#define WinAPI_SetPixelV(p0, p1, p2, p3)	SetPixelV(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetPixelV(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_SetPolyFillMode(p0, p1)	SetPolyFillMode(p0, p1)
__EXTERN INTEGER __CALL_1 SetPolyFillMode(INTEGER p0, INTEGER p1);
#define WinAPI_SetPrinter(hPrinter, Level, pPrinter, Command)	SetPrinterA(hPrinter, Level, pPrinter, Command)
#define WinAPI_SetPrinterA(hPrinter, Level, pPrinter, Command)	SetPrinterA(hPrinter, Level, pPrinter, Command)
__EXTERN INTEGER __CALL_1 SetPrinterA(INTEGER hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER Command);
#define WinAPI_SetPrinterData(hPrinter, pValueName, Type, pData, cbData)	SetPrinterDataA(hPrinter, pValueName, Type, pData, cbData)
#define WinAPI_SetPrinterDataA(hPrinter, pValueName, Type, pData, cbData)	SetPrinterDataA(hPrinter, pValueName, Type, pData, cbData)
__EXTERN INTEGER __CALL_1 SetPrinterDataA(INTEGER hPrinter, INTEGER pValueName, INTEGER Type, CHAR *pData, INTEGER cbData);
#define WinAPI_SetPrinterDataW(hPrinter, pValueName, Type, pData, cbData)	SetPrinterDataW(hPrinter, pValueName, Type, pData, cbData)
__EXTERN INTEGER __CALL_1 SetPrinterDataW(INTEGER hPrinter, INTEGER pValueName, INTEGER Type, CHAR *pData, INTEGER cbData);
#define WinAPI_SetPrinterW(hPrinter, Level, pPrinter, Command)	SetPrinterW(hPrinter, Level, pPrinter, Command)
__EXTERN INTEGER __CALL_1 SetPrinterW(INTEGER hPrinter, INTEGER Level, CHAR *pPrinter, INTEGER Command);
#define WinAPI_SetPriorityClass(hProcess, dwPriorityClass)	SetPriorityClass(hProcess, dwPriorityClass)
__EXTERN INTEGER __CALL_1 SetPriorityClass(INTEGER hProcess, INTEGER dwPriorityClass);
#define WinAPI_SetPrivateObjectSecurity(SecurityInformation, ModificationDescriptor, ObjectsSecurityDescriptor, GenericMapping, GenericMapping__typ, Token)	SetPrivateObjectSecurity(SecurityInformation, ModificationDescriptor, ObjectsSecurityDescriptor, GenericMapping, Token)
__EXTERN INTEGER __CALL_1 SetPrivateObjectSecurity(SET SecurityInformation, INTEGER ModificationDescriptor, INTEGER *ObjectsSecurityDescriptor, WinAPI_GENERIC_MAPPING *GenericMapping, INTEGER Token);
#define WinAPI_SetProcessAffinityMask(hProcess, dwProcessAffinityMask)	SetProcessAffinityMask(hProcess, dwProcessAffinityMask)
__EXTERN INTEGER __CALL_1 SetProcessAffinityMask(INTEGER hProcess, INTEGER dwProcessAffinityMask);
#define WinAPI_SetProcessShutdownParameters(dwLevel, dwFlags)	SetProcessShutdownParameters(dwLevel, dwFlags)
__EXTERN INTEGER __CALL_1 SetProcessShutdownParameters(INTEGER dwLevel, SET dwFlags);
#define WinAPI_SetProcessWindowStation(hWinSta)	SetProcessWindowStation(hWinSta)
__EXTERN INTEGER __CALL_1 SetProcessWindowStation(INTEGER hWinSta);
#define WinAPI_SetProcessWorkingSetSize(hProcess, dwMinimumWorkingSetSize, dwMaximumWorkingSetSize)	SetProcessWorkingSetSize(hProcess, dwMinimumWorkingSetSize, dwMaximumWorkingSetSize)
__EXTERN INTEGER __CALL_1 SetProcessWorkingSetSize(INTEGER hProcess, INTEGER dwMinimumWorkingSetSize, INTEGER dwMaximumWorkingSetSize);
#define WinAPI_SetProp(hWnd, lpString, hData)	SetPropA(hWnd, lpString, hData)
#define WinAPI_SetPropA(hWnd, lpString, hData)	SetPropA(hWnd, lpString, hData)
__EXTERN INTEGER __CALL_1 SetPropA(INTEGER hWnd, INTEGER lpString, INTEGER hData);
#define WinAPI_SetPropW(hWnd, lpString, hData)	SetPropW(hWnd, lpString, hData)
__EXTERN INTEGER __CALL_1 SetPropW(INTEGER hWnd, INTEGER lpString, INTEGER hData);
#define WinAPI_SetROP2(p0, p1)	SetROP2(p0, p1)
__EXTERN INTEGER __CALL_1 SetROP2(INTEGER p0, INTEGER p1);
#define WinAPI_SetRect(lprc, lprc__typ, xLeft, yTop, xRight, yBottom)	SetRect(lprc, xLeft, yTop, xRight, yBottom)
__EXTERN INTEGER __CALL_1 SetRect(WinAPI_RECT *lprc, INTEGER xLeft, INTEGER yTop, INTEGER xRight, INTEGER yBottom);
#define WinAPI_SetRectEmpty(lprc, lprc__typ)	SetRectEmpty(lprc)
__EXTERN INTEGER __CALL_1 SetRectEmpty(WinAPI_RECT *lprc);
#define WinAPI_SetRectRgn(p0, p1, p2, p3, p4)	SetRectRgn(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 SetRectRgn(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_SetScrollInfo(p0, p1, p2, p2__typ, p3)	SetScrollInfo(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetScrollInfo(INTEGER p0, INTEGER p1, WinAPI_SCROLLINFO *p2, INTEGER p3);
#define WinAPI_SetScrollPos(hWnd, nBar, nPos, bRedraw)	SetScrollPos(hWnd, nBar, nPos, bRedraw)
__EXTERN INTEGER __CALL_1 SetScrollPos(INTEGER hWnd, INTEGER nBar, INTEGER nPos, INTEGER bRedraw);
#define WinAPI_SetScrollRange(hWnd, nBar, nMinPos, nMaxPos, bRedraw)	SetScrollRange(hWnd, nBar, nMinPos, nMaxPos, bRedraw)
__EXTERN INTEGER __CALL_1 SetScrollRange(INTEGER hWnd, INTEGER nBar, INTEGER nMinPos, INTEGER nMaxPos, INTEGER bRedraw);
#define WinAPI_SetSecurityDescriptorDacl(pSecurityDescriptor, bDaclPresent, pDacl, pDacl__typ, bDaclDefaulted)	SetSecurityDescriptorDacl(pSecurityDescriptor, bDaclPresent, pDacl, bDaclDefaulted)
__EXTERN INTEGER __CALL_1 SetSecurityDescriptorDacl(INTEGER pSecurityDescriptor, INTEGER bDaclPresent, WinAPI_ACL *pDacl, INTEGER bDaclDefaulted);
#define WinAPI_SetSecurityDescriptorGroup(pSecurityDescriptor, pGroup, bGroupDefaulted)	SetSecurityDescriptorGroup(pSecurityDescriptor, pGroup, bGroupDefaulted)
__EXTERN INTEGER __CALL_1 SetSecurityDescriptorGroup(INTEGER pSecurityDescriptor, INTEGER pGroup, INTEGER bGroupDefaulted);
#define WinAPI_SetSecurityDescriptorOwner(pSecurityDescriptor, pOwner, bOwnerDefaulted)	SetSecurityDescriptorOwner(pSecurityDescriptor, pOwner, bOwnerDefaulted)
__EXTERN INTEGER __CALL_1 SetSecurityDescriptorOwner(INTEGER pSecurityDescriptor, INTEGER pOwner, INTEGER bOwnerDefaulted);
#define WinAPI_SetSecurityDescriptorSacl(pSecurityDescriptor, bSaclPresent, pSacl, pSacl__typ, bSaclDefaulted)	SetSecurityDescriptorSacl(pSecurityDescriptor, bSaclPresent, pSacl, bSaclDefaulted)
__EXTERN INTEGER __CALL_1 SetSecurityDescriptorSacl(INTEGER pSecurityDescriptor, INTEGER bSaclPresent, WinAPI_ACL *pSacl, INTEGER bSaclDefaulted);
#define WinAPI_SetServiceObjectSecurity(hService, dwSecurityInformation, lpSecurityDescriptor)	SetServiceObjectSecurity(hService, dwSecurityInformation, lpSecurityDescriptor)
__EXTERN INTEGER __CALL_1 SetServiceObjectSecurity(INTEGER hService, SET dwSecurityInformation, INTEGER lpSecurityDescriptor);
#define WinAPI_SetServiceStatus(hServiceStatus, lpServiceStatus, lpServiceStatus__typ)	SetServiceStatus(hServiceStatus, lpServiceStatus)
__EXTERN INTEGER __CALL_1 SetServiceStatus(INTEGER hServiceStatus, WinAPI_SERVICE_STATUS *lpServiceStatus);
#define WinAPI_SetStdHandle(nStdHandle, hHandle)	SetStdHandle(nStdHandle, hHandle)
__EXTERN INTEGER __CALL_1 SetStdHandle(INTEGER nStdHandle, INTEGER hHandle);
#define WinAPI_SetStretchBltMode(p0, p1)	SetStretchBltMode(p0, p1)
__EXTERN INTEGER __CALL_1 SetStretchBltMode(INTEGER p0, INTEGER p1);
#define WinAPI_SetSysColors(cElements, lpaElements, lpaRgbValues)	SetSysColors(cElements, lpaElements, lpaRgbValues)
__EXTERN INTEGER __CALL_1 SetSysColors(INTEGER cElements, INTEGER *lpaElements, INTEGER *lpaRgbValues);
#define WinAPI_SetSystemCursor(hcur, id)	SetSystemCursor(hcur, id)
__EXTERN INTEGER __CALL_1 SetSystemCursor(INTEGER hcur, INTEGER id);
#define WinAPI_SetSystemPaletteUse(p0, p1)	SetSystemPaletteUse(p0, p1)
__EXTERN INTEGER __CALL_1 SetSystemPaletteUse(INTEGER p0, INTEGER p1);
#define WinAPI_SetSystemPowerState(fSuspend, fForce)	SetSystemPowerState(fSuspend, fForce)
__EXTERN INTEGER __CALL_1 SetSystemPowerState(INTEGER fSuspend, INTEGER fForce);
#define WinAPI_SetSystemTime(lpSystemTime, lpSystemTime__typ)	SetSystemTime(lpSystemTime)
__EXTERN INTEGER __CALL_1 SetSystemTime(WinAPI_SYSTEMTIME *lpSystemTime);
#define WinAPI_SetSystemTimeAdjustment(dwTimeAdjustment, bTimeAdjustmentDisabled)	SetSystemTimeAdjustment(dwTimeAdjustment, bTimeAdjustmentDisabled)
__EXTERN INTEGER __CALL_1 SetSystemTimeAdjustment(INTEGER dwTimeAdjustment, INTEGER bTimeAdjustmentDisabled);
#define WinAPI_SetTapeParameters(hDevice, dwOperation, lpTapeInformation)	SetTapeParameters(hDevice, dwOperation, lpTapeInformation)
__EXTERN INTEGER __CALL_1 SetTapeParameters(INTEGER hDevice, INTEGER dwOperation, INTEGER lpTapeInformation);
#define WinAPI_SetTapePosition(hDevice, dwPositionMethod, dwPartition, dwOffsetLow, dwOffsetHigh, bImmediate)	SetTapePosition(hDevice, dwPositionMethod, dwPartition, dwOffsetLow, dwOffsetHigh, bImmediate)
__EXTERN INTEGER __CALL_1 SetTapePosition(INTEGER hDevice, INTEGER dwPositionMethod, INTEGER dwPartition, INTEGER dwOffsetLow, INTEGER dwOffsetHigh, INTEGER bImmediate);
#define WinAPI_SetTextAlign(p0, p1)	SetTextAlign(p0, p1)
__EXTERN SET __CALL_1 SetTextAlign(INTEGER p0, SET p1);
#define WinAPI_SetTextCharacterExtra(p0, p1)	SetTextCharacterExtra(p0, p1)
__EXTERN INTEGER __CALL_1 SetTextCharacterExtra(INTEGER p0, INTEGER p1);
#define WinAPI_SetTextColor(p0, p1)	SetTextColor(p0, p1)
__EXTERN INTEGER __CALL_1 SetTextColor(INTEGER p0, INTEGER p1);
#define WinAPI_SetTextJustification(p0, p1, p2)	SetTextJustification(p0, p1, p2)
__EXTERN INTEGER __CALL_1 SetTextJustification(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_SetThreadAffinityMask(hThread, dwThreadAffinityMask)	SetThreadAffinityMask(hThread, dwThreadAffinityMask)
__EXTERN INTEGER __CALL_1 SetThreadAffinityMask(INTEGER hThread, INTEGER dwThreadAffinityMask);
#define WinAPI_SetThreadContext(hThread, lpContext, lpContext__typ)	SetThreadContext(hThread, lpContext)
__EXTERN INTEGER __CALL_1 SetThreadContext(INTEGER hThread, WinAPI_CONTEXT *lpContext);
#define WinAPI_SetThreadDesktop(hDesktop)	SetThreadDesktop(hDesktop)
__EXTERN INTEGER __CALL_1 SetThreadDesktop(INTEGER hDesktop);
#define WinAPI_SetThreadIdealProcessor(hThread, dwIdealProcessor)	SetThreadIdealProcessor(hThread, dwIdealProcessor)
__EXTERN INTEGER __CALL_1 SetThreadIdealProcessor(INTEGER hThread, INTEGER dwIdealProcessor);
#define WinAPI_SetThreadLocale(Locale)	SetThreadLocale(Locale)
__EXTERN INTEGER __CALL_1 SetThreadLocale(INTEGER Locale);
#define WinAPI_SetThreadPriority(hThread, nPriority)	SetThreadPriority(hThread, nPriority)
__EXTERN INTEGER __CALL_1 SetThreadPriority(INTEGER hThread, INTEGER nPriority);
#define WinAPI_SetThreadPriorityBoost(hThread, bDisablePriorityBoost)	SetThreadPriorityBoost(hThread, bDisablePriorityBoost)
__EXTERN INTEGER __CALL_1 SetThreadPriorityBoost(INTEGER hThread, INTEGER bDisablePriorityBoost);
#define WinAPI_SetThreadToken(Thread, Token)	SetThreadToken(Thread, Token)
__EXTERN INTEGER __CALL_1 SetThreadToken(INTEGER *Thread, INTEGER Token);
#define WinAPI_SetTimeZoneInformation(lpTimeZoneInformation, lpTimeZoneInformation__typ)	SetTimeZoneInformation(lpTimeZoneInformation)
__EXTERN INTEGER __CALL_1 SetTimeZoneInformation(WinAPI_TIME_ZONE_INFORMATION *lpTimeZoneInformation);
#define WinAPI_SetTimer(hWnd, nIDEvent, uElapse, lpTimerFunc)	SetTimer(hWnd, nIDEvent, uElapse, lpTimerFunc)
__EXTERN INTEGER __CALL_1 SetTimer(INTEGER hWnd, INTEGER nIDEvent, INTEGER uElapse, WinAPI_TIMERPROC lpTimerFunc);
#define WinAPI_SetTokenInformation(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength)	SetTokenInformation(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength)
__EXTERN INTEGER __CALL_1 SetTokenInformation(INTEGER TokenHandle, INTEGER TokenInformationClass, INTEGER TokenInformation, INTEGER TokenInformationLength);
#define WinAPI_SetUnhandledExceptionFilter(lpTopLevelExceptionFilter)	SetUnhandledExceptionFilter(lpTopLevelExceptionFilter)
__EXTERN WinAPI_TOP_LEVEL_EXCEPTION_FILTER __CALL_1 SetUnhandledExceptionFilter(WinAPI_TOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);
#define WinAPI_SetUserObjectInformation(hObj, nIndex, pvInfo, nLength)	SetUserObjectInformationA(hObj, nIndex, pvInfo, nLength)
#define WinAPI_SetUserObjectInformationA(hObj, nIndex, pvInfo, nLength)	SetUserObjectInformationA(hObj, nIndex, pvInfo, nLength)
__EXTERN INTEGER __CALL_1 SetUserObjectInformationA(INTEGER hObj, INTEGER nIndex, INTEGER pvInfo, INTEGER nLength);
#define WinAPI_SetUserObjectInformationW(hObj, nIndex, pvInfo, nLength)	SetUserObjectInformationW(hObj, nIndex, pvInfo, nLength)
__EXTERN INTEGER __CALL_1 SetUserObjectInformationW(INTEGER hObj, INTEGER nIndex, INTEGER pvInfo, INTEGER nLength);
#define WinAPI_SetUserObjectSecurity(hObj, pSIRequested, pSID)	SetUserObjectSecurity(hObj, pSIRequested, pSID)
__EXTERN INTEGER __CALL_1 SetUserObjectSecurity(INTEGER hObj, INTEGER *pSIRequested, INTEGER pSID);
#define WinAPI_SetViewportExtEx(p0, p1, p2, p3, p3__typ)	SetViewportExtEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetViewportExtEx(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_SetViewportOrgEx(p0, p1, p2, p3, p3__typ)	SetViewportOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetViewportOrgEx(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_SetVolumeLabel(lpRootPathName, lpVolumeName)	SetVolumeLabelA(lpRootPathName, lpVolumeName)
#define WinAPI_SetVolumeLabelA(lpRootPathName, lpVolumeName)	SetVolumeLabelA(lpRootPathName, lpVolumeName)
__EXTERN INTEGER __CALL_1 SetVolumeLabelA(INTEGER lpRootPathName, INTEGER lpVolumeName);
#define WinAPI_SetVolumeLabelW(lpRootPathName, lpVolumeName)	SetVolumeLabelW(lpRootPathName, lpVolumeName)
__EXTERN INTEGER __CALL_1 SetVolumeLabelW(INTEGER lpRootPathName, INTEGER lpVolumeName);
#define WinAPI_SetWaitableTimer(hTimer, lpDueTime, lPeriod, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume)	SetWaitableTimer(hTimer, lpDueTime, lPeriod, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume)
__EXTERN INTEGER __CALL_1 SetWaitableTimer(INTEGER hTimer, LONGINT *lpDueTime, INTEGER lPeriod, WinAPI_TIMERAPCROUTINE pfnCompletionRoutine, INTEGER lpArgToCompletionRoutine, INTEGER fResume);
#define WinAPI_SetWinMetaFileBits(p0, p1, p2, p3, p3__typ)	SetWinMetaFileBits(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetWinMetaFileBits(INTEGER p0, CHAR *p1, INTEGER p2, WinAPI_METAFILEPICT *p3);
#define WinAPI_SetWindowContextHelpId(p0, p1)	SetWindowContextHelpId(p0, p1)
__EXTERN INTEGER __CALL_1 SetWindowContextHelpId(INTEGER p0, INTEGER p1);
#define WinAPI_SetWindowExtEx(p0, p1, p2, p3, p3__typ)	SetWindowExtEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetWindowExtEx(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_SIZE *p3);
#define WinAPI_SetWindowLong(hWnd, nIndex, dwNewLong)	SetWindowLongA(hWnd, nIndex, dwNewLong)
#define WinAPI_SetWindowLongA(hWnd, nIndex, dwNewLong)	SetWindowLongA(hWnd, nIndex, dwNewLong)
__EXTERN INTEGER __CALL_1 SetWindowLongA(INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong);
#define WinAPI_SetWindowLongW(hWnd, nIndex, dwNewLong)	SetWindowLongW(hWnd, nIndex, dwNewLong)
__EXTERN INTEGER __CALL_1 SetWindowLongW(INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong);
#define WinAPI_SetWindowOrgEx(p0, p1, p2, p3, p3__typ)	SetWindowOrgEx(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 SetWindowOrgEx(INTEGER p0, INTEGER p1, INTEGER p2, WinAPI_POINT *p3);
#define WinAPI_SetWindowPlacement(hWnd, lpwndpl, lpwndpl__typ)	SetWindowPlacement(hWnd, lpwndpl)
__EXTERN INTEGER __CALL_1 SetWindowPlacement(INTEGER hWnd, WinAPI_WINDOWPLACEMENT *lpwndpl);
#define WinAPI_SetWindowPos(hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags)	SetWindowPos(hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags)
__EXTERN INTEGER __CALL_1 SetWindowPos(INTEGER hWnd, INTEGER hWndInsertAfter, INTEGER X, INTEGER Y, INTEGER cx, INTEGER cy, SET uFlags);
#define WinAPI_SetWindowRgn(hWnd, hRgn, bRedraw)	SetWindowRgn(hWnd, hRgn, bRedraw)
__EXTERN INTEGER __CALL_1 SetWindowRgn(INTEGER hWnd, INTEGER hRgn, INTEGER bRedraw);
#define WinAPI_SetWindowText(hWnd, lpString)	SetWindowTextA(hWnd, lpString)
#define WinAPI_SetWindowTextA(hWnd, lpString)	SetWindowTextA(hWnd, lpString)
__EXTERN INTEGER __CALL_1 SetWindowTextA(INTEGER hWnd, INTEGER lpString);
#define WinAPI_SetWindowTextW(hWnd, lpString)	SetWindowTextW(hWnd, lpString)
__EXTERN INTEGER __CALL_1 SetWindowTextW(INTEGER hWnd, INTEGER lpString);
#define WinAPI_SetWindowWord(hWnd, nIndex, wNewWord)	SetWindowWord(hWnd, nIndex, wNewWord)
__EXTERN SHORTINT __CALL_1 SetWindowWord(INTEGER hWnd, INTEGER nIndex, SHORTINT wNewWord);
#define WinAPI_SetWindowsHook(nFilterType, pfnFilterProc)	SetWindowsHookA(nFilterType, pfnFilterProc)
#define WinAPI_SetWindowsHookA(nFilterType, pfnFilterProc)	SetWindowsHookA(nFilterType, pfnFilterProc)
__EXTERN WinAPI_HOOKPROC __CALL_1 SetWindowsHookA(INTEGER nFilterType, WinAPI_HOOKPROC pfnFilterProc);
#define WinAPI_SetWindowsHookEx(idHook, lpfn, hmod, dwThreadId)	SetWindowsHookExA(idHook, lpfn, hmod, dwThreadId)
#define WinAPI_SetWindowsHookExA(idHook, lpfn, hmod, dwThreadId)	SetWindowsHookExA(idHook, lpfn, hmod, dwThreadId)
__EXTERN INTEGER __CALL_1 SetWindowsHookExA(INTEGER idHook, WinAPI_HOOKPROC lpfn, INTEGER hmod, INTEGER dwThreadId);
#define WinAPI_SetWindowsHookExW(idHook, lpfn, hmod, dwThreadId)	SetWindowsHookExW(idHook, lpfn, hmod, dwThreadId)
__EXTERN INTEGER __CALL_1 SetWindowsHookExW(INTEGER idHook, WinAPI_HOOKPROC lpfn, INTEGER hmod, INTEGER dwThreadId);
#define WinAPI_SetWindowsHookW(nFilterType, pfnFilterProc)	SetWindowsHookW(nFilterType, pfnFilterProc)
__EXTERN WinAPI_HOOKPROC __CALL_1 SetWindowsHookW(INTEGER nFilterType, WinAPI_HOOKPROC pfnFilterProc);
#define WinAPI_SetWorldTransform(p0, p1, p1__typ)	SetWorldTransform(p0, p1)
__EXTERN INTEGER __CALL_1 SetWorldTransform(INTEGER p0, WinAPI_XFORM *p1);
#define WinAPI_SetupComm(hFile, dwInQueue, dwOutQueue)	SetupComm(hFile, dwInQueue, dwOutQueue)
__EXTERN INTEGER __CALL_1 SetupComm(INTEGER hFile, INTEGER dwInQueue, INTEGER dwOutQueue);
#define WinAPI_ShellAbout(hWnd, szApp, szOtherStuff, hIcon)	ShellAboutA(hWnd, szApp, szOtherStuff, hIcon)
#define WinAPI_ShellAboutA(hWnd, szApp, szOtherStuff, hIcon)	ShellAboutA(hWnd, szApp, szOtherStuff, hIcon)
__EXTERN INTEGER __CALL_1 ShellAboutA(INTEGER hWnd, INTEGER szApp, INTEGER szOtherStuff, INTEGER hIcon);
#define WinAPI_ShellAboutW(hWnd, szApp, szOtherStuff, hIcon)	ShellAboutW(hWnd, szApp, szOtherStuff, hIcon)
__EXTERN INTEGER __CALL_1 ShellAboutW(INTEGER hWnd, INTEGER szApp, INTEGER szOtherStuff, INTEGER hIcon);
#define WinAPI_ShellExecute(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)	ShellExecuteA(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)
#define WinAPI_ShellExecuteA(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)	ShellExecuteA(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)
__EXTERN INTEGER __CALL_1 ShellExecuteA(INTEGER hwnd, INTEGER lpOperation, INTEGER lpFile, INTEGER lpParameters, INTEGER lpDirectory, INTEGER nShowCmd);
#define WinAPI_ShellExecuteEx(lpExecInfo, lpExecInfo__typ)	ShellExecuteExA(lpExecInfo)
#define WinAPI_ShellExecuteExA(lpExecInfo, lpExecInfo__typ)	ShellExecuteExA(lpExecInfo)
__EXTERN INTEGER __CALL_1 ShellExecuteExA(WinAPI_SHELLEXECUTEINFOA *lpExecInfo);
#define WinAPI_ShellExecuteExW(lpExecInfo, lpExecInfo__typ)	ShellExecuteExW(lpExecInfo)
__EXTERN INTEGER __CALL_1 ShellExecuteExW(WinAPI_SHELLEXECUTEINFOW *lpExecInfo);
#define WinAPI_ShellExecuteW(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)	ShellExecuteW(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd)
__EXTERN INTEGER __CALL_1 ShellExecuteW(INTEGER hwnd, INTEGER lpOperation, INTEGER lpFile, INTEGER lpParameters, INTEGER lpDirectory, INTEGER nShowCmd);
#define WinAPI_Shell_NotifyIcon(dwMessage, lpData, lpData__typ)	Shell_NotifyIconA(dwMessage, lpData)
#define WinAPI_Shell_NotifyIconA(dwMessage, lpData, lpData__typ)	Shell_NotifyIconA(dwMessage, lpData)
__EXTERN INTEGER __CALL_1 Shell_NotifyIconA(INTEGER dwMessage, WinAPI_NOTIFYICONDATAA *lpData);
#define WinAPI_Shell_NotifyIconW(dwMessage, lpData, lpData__typ)	Shell_NotifyIconW(dwMessage, lpData)
__EXTERN INTEGER __CALL_1 Shell_NotifyIconW(INTEGER dwMessage, WinAPI_NOTIFYICONDATAW *lpData);
#define WinAPI_ShowCaret(hWnd)	ShowCaret(hWnd)
__EXTERN INTEGER __CALL_1 ShowCaret(INTEGER hWnd);
#define WinAPI_ShowCursor(bShow)	ShowCursor(bShow)
__EXTERN INTEGER __CALL_1 ShowCursor(INTEGER bShow);
#define WinAPI_ShowOwnedPopups(hWnd, fShow)	ShowOwnedPopups(hWnd, fShow)
__EXTERN INTEGER __CALL_1 ShowOwnedPopups(INTEGER hWnd, INTEGER fShow);
#define WinAPI_ShowScrollBar(hWnd, wBar, bShow)	ShowScrollBar(hWnd, wBar, bShow)
__EXTERN INTEGER __CALL_1 ShowScrollBar(INTEGER hWnd, INTEGER wBar, INTEGER bShow);
#define WinAPI_ShowWindow(hWnd, nCmdShow)	ShowWindow(hWnd, nCmdShow)
__EXTERN INTEGER __CALL_1 ShowWindow(INTEGER hWnd, INTEGER nCmdShow);
#define WinAPI_ShowWindowAsync(hWnd, nCmdShow)	ShowWindowAsync(hWnd, nCmdShow)
__EXTERN INTEGER __CALL_1 ShowWindowAsync(INTEGER hWnd, INTEGER nCmdShow);
#define WinAPI_SignalObjectAndWait(hObjectToSignal, hObjectToWaitOn, dwMilliseconds, bAlertable)	SignalObjectAndWait(hObjectToSignal, hObjectToWaitOn, dwMilliseconds, bAlertable)
__EXTERN INTEGER __CALL_1 SignalObjectAndWait(INTEGER hObjectToSignal, INTEGER hObjectToWaitOn, INTEGER dwMilliseconds, INTEGER bAlertable);
#define WinAPI_SizeofResource(hModule, hResInfo)	SizeofResource(hModule, hResInfo)
__EXTERN INTEGER __CALL_1 SizeofResource(INTEGER hModule, INTEGER hResInfo);
#define WinAPI_Sleep(dwMilliseconds)	Sleep(dwMilliseconds)
__EXTERN void __CALL_1 Sleep(INTEGER dwMilliseconds);
#define WinAPI_SleepEx(dwMilliseconds, bAlertable)	SleepEx(dwMilliseconds, bAlertable)
__EXTERN INTEGER __CALL_1 SleepEx(INTEGER dwMilliseconds, INTEGER bAlertable);
#define WinAPI_StartDoc(p0, p1, p1__typ)	StartDocA(p0, p1)
#define WinAPI_StartDocA(p0, p1, p1__typ)	StartDocA(p0, p1)
__EXTERN INTEGER __CALL_1 StartDocA(INTEGER p0, WinAPI_DOCINFOA *p1);
#define WinAPI_StartDocPrinter(hPrinter, Level, pDocInfo)	StartDocPrinterA(hPrinter, Level, pDocInfo)
#define WinAPI_StartDocPrinterA(hPrinter, Level, pDocInfo)	StartDocPrinterA(hPrinter, Level, pDocInfo)
__EXTERN INTEGER __CALL_1 StartDocPrinterA(INTEGER hPrinter, INTEGER Level, CHAR *pDocInfo);
#define WinAPI_StartDocPrinterW(hPrinter, Level, pDocInfo)	StartDocPrinterW(hPrinter, Level, pDocInfo)
__EXTERN INTEGER __CALL_1 StartDocPrinterW(INTEGER hPrinter, INTEGER Level, CHAR *pDocInfo);
#define WinAPI_StartDocW(p0, p1, p1__typ)	StartDocW(p0, p1)
__EXTERN INTEGER __CALL_1 StartDocW(INTEGER p0, WinAPI_DOCINFOW *p1);
#define WinAPI_StartPage(p0)	StartPage(p0)
__EXTERN INTEGER __CALL_1 StartPage(INTEGER p0);
#define WinAPI_StartPagePrinter(hPrinter)	StartPagePrinter(hPrinter)
__EXTERN INTEGER __CALL_1 StartPagePrinter(INTEGER hPrinter);
#define WinAPI_StartService(hService, dwNumServiceArgs, lpServiceArgVectors)	StartServiceA(hService, dwNumServiceArgs, lpServiceArgVectors)
#define WinAPI_StartServiceA(hService, dwNumServiceArgs, lpServiceArgVectors)	StartServiceA(hService, dwNumServiceArgs, lpServiceArgVectors)
__EXTERN INTEGER __CALL_1 StartServiceA(INTEGER hService, INTEGER dwNumServiceArgs, INTEGER *lpServiceArgVectors);
#define WinAPI_StartServiceCtrlDispatcher(lpServiceStartTable, lpServiceStartTable__typ)	StartServiceCtrlDispatcherA(lpServiceStartTable)
#define WinAPI_StartServiceCtrlDispatcherA(lpServiceStartTable, lpServiceStartTable__typ)	StartServiceCtrlDispatcherA(lpServiceStartTable)
__EXTERN INTEGER __CALL_1 StartServiceCtrlDispatcherA(WinAPI_SERVICE_TABLE_ENTRYA *lpServiceStartTable);
#define WinAPI_StartServiceCtrlDispatcherW(lpServiceStartTable, lpServiceStartTable__typ)	StartServiceCtrlDispatcherW(lpServiceStartTable)
__EXTERN INTEGER __CALL_1 StartServiceCtrlDispatcherW(WinAPI_SERVICE_TABLE_ENTRYW *lpServiceStartTable);
#define WinAPI_StartServiceW(hService, dwNumServiceArgs, lpServiceArgVectors)	StartServiceW(hService, dwNumServiceArgs, lpServiceArgVectors)
__EXTERN INTEGER __CALL_1 StartServiceW(INTEGER hService, INTEGER dwNumServiceArgs, INTEGER lpServiceArgVectors);
#define WinAPI_StretchBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10)	StretchBlt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10)
__EXTERN INTEGER __CALL_1 StretchBlt(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, INTEGER p10);
#define WinAPI_StretchDIBits(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p10__typ, p11, p12)	StretchDIBits(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)
__EXTERN INTEGER __CALL_1 StretchDIBits(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, INTEGER p5, INTEGER p6, INTEGER p7, INTEGER p8, INTEGER p9, WinAPI_BITMAPINFO *p10, INTEGER p11, INTEGER p12);
#define WinAPI_StrokeAndFillPath(p0)	StrokeAndFillPath(p0)
__EXTERN INTEGER __CALL_1 StrokeAndFillPath(INTEGER p0);
#define WinAPI_StrokePath(p0)	StrokePath(p0)
__EXTERN INTEGER __CALL_1 StrokePath(INTEGER p0);
#define WinAPI_SubtractRect(lprcDst, lprcDst__typ, lprcSrc1, lprcSrc1__typ, lprcSrc2, lprcSrc2__typ)	SubtractRect(lprcDst, lprcSrc1, lprcSrc2)
__EXTERN INTEGER __CALL_1 SubtractRect(WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc1, WinAPI_RECT *lprcSrc2);
#define WinAPI_SuspendThread(hThread)	SuspendThread(hThread)
__EXTERN INTEGER __CALL_1 SuspendThread(INTEGER hThread);
#define WinAPI_SwapBuffers(p0)	SwapBuffers(p0)
__EXTERN INTEGER __CALL_1 SwapBuffers(INTEGER p0);
#define WinAPI_SwapMouseButton(fSwap)	SwapMouseButton(fSwap)
__EXTERN INTEGER __CALL_1 SwapMouseButton(INTEGER fSwap);
#define WinAPI_SwitchDesktop(hDesktop)	SwitchDesktop(hDesktop)
__EXTERN INTEGER __CALL_1 SwitchDesktop(INTEGER hDesktop);
#define WinAPI_SwitchToFiber(lpFiber)	SwitchToFiber(lpFiber)
__EXTERN void __CALL_1 SwitchToFiber(INTEGER lpFiber);
#define WinAPI_SystemParametersInfo(uiAction, uiParam, pvParam, fWinIni)	SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni)
#define WinAPI_SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni)	SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni)
__EXTERN INTEGER __CALL_1 SystemParametersInfoA(INTEGER uiAction, INTEGER uiParam, INTEGER pvParam, INTEGER fWinIni);
#define WinAPI_SystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni)	SystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni)
__EXTERN INTEGER __CALL_1 SystemParametersInfoW(INTEGER uiAction, INTEGER uiParam, INTEGER pvParam, INTEGER fWinIni);
#define WinAPI_SystemTimeToFileTime(lpSystemTime, lpSystemTime__typ, lpFileTime, lpFileTime__typ)	SystemTimeToFileTime(lpSystemTime, lpFileTime)
__EXTERN INTEGER __CALL_1 SystemTimeToFileTime(WinAPI_SYSTEMTIME *lpSystemTime, WinAPI_FILETIME *lpFileTime);
#define WinAPI_SystemTimeToTzSpecificLocalTime(lpTimeZoneInformation, lpTimeZoneInformation__typ, lpUniversalTime, lpUniversalTime__typ, lpLocalTime, lpLocalTime__typ)	SystemTimeToTzSpecificLocalTime(lpTimeZoneInformation, lpUniversalTime, lpLocalTime)
__EXTERN INTEGER __CALL_1 SystemTimeToTzSpecificLocalTime(WinAPI_TIME_ZONE_INFORMATION *lpTimeZoneInformation, WinAPI_SYSTEMTIME *lpUniversalTime, WinAPI_SYSTEMTIME *lpLocalTime);
#define WinAPI_TabbedTextOut(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)	TabbedTextOutA(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)
#define WinAPI_TabbedTextOutA(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)	TabbedTextOutA(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)
__EXTERN INTEGER __CALL_1 TabbedTextOutA(INTEGER hDC, INTEGER X, INTEGER Y, INTEGER lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions, INTEGER nTabOrigin);
#define WinAPI_TabbedTextOutW(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)	TabbedTextOutW(hDC, X, Y, lpString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin)
__EXTERN INTEGER __CALL_1 TabbedTextOutW(INTEGER hDC, INTEGER X, INTEGER Y, INTEGER lpString, INTEGER nCount, INTEGER nTabPositions, INTEGER *lpnTabStopPositions, INTEGER nTabOrigin);
#define WinAPI_TerminateProcess(hProcess, uExitCode)	TerminateProcess(hProcess, uExitCode)
__EXTERN INTEGER __CALL_1 TerminateProcess(INTEGER hProcess, INTEGER uExitCode);
#define WinAPI_TerminateThread(hThread, dwExitCode)	TerminateThread(hThread, dwExitCode)
__EXTERN INTEGER __CALL_1 TerminateThread(INTEGER hThread, INTEGER dwExitCode);
#define WinAPI_TextOut(p0, p1, p2, p3, p4)	TextOutA(p0, p1, p2, p3, p4)
#define WinAPI_TextOutA(p0, p1, p2, p3, p4)	TextOutA(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 TextOutA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_TextOutW(p0, p1, p2, p3, p4)	TextOutW(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 TextOutW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4);
#define WinAPI_TileWindows(hwndParent, wHow, lpRect, lpRect__typ, cKids, lpKids)	TileWindows(hwndParent, wHow, lpRect, cKids, lpKids)
__EXTERN SHORTINT __CALL_1 TileWindows(INTEGER hwndParent, INTEGER wHow, WinAPI_RECT *lpRect, INTEGER cKids, INTEGER *lpKids);
#define WinAPI_TlsAlloc()	TlsAlloc()
__EXTERN INTEGER __CALL_1 TlsAlloc(void);
#define WinAPI_TlsFree(dwTlsIndex)	TlsFree(dwTlsIndex)
__EXTERN INTEGER __CALL_1 TlsFree(INTEGER dwTlsIndex);
#define WinAPI_TlsGetValue(dwTlsIndex)	TlsGetValue(dwTlsIndex)
__EXTERN INTEGER __CALL_1 TlsGetValue(INTEGER dwTlsIndex);
#define WinAPI_TlsSetValue(dwTlsIndex, lpTlsValue)	TlsSetValue(dwTlsIndex, lpTlsValue)
__EXTERN INTEGER __CALL_1 TlsSetValue(INTEGER dwTlsIndex, INTEGER lpTlsValue);
#define WinAPI_ToAscii(uVirtKey, uScanCode, lpKeyState, lpChar, uFlags)	ToAscii(uVirtKey, uScanCode, lpKeyState, lpChar, uFlags)
__EXTERN INTEGER __CALL_1 ToAscii(INTEGER uVirtKey, INTEGER uScanCode, CHAR *lpKeyState, SHORTINT *lpChar, SET uFlags);
#define WinAPI_ToAsciiEx(uVirtKey, uScanCode, lpKeyState, lpChar, uFlags, dwhkl)	ToAsciiEx(uVirtKey, uScanCode, lpKeyState, lpChar, uFlags, dwhkl)
__EXTERN INTEGER __CALL_1 ToAsciiEx(INTEGER uVirtKey, INTEGER uScanCode, CHAR *lpKeyState, SHORTINT *lpChar, SET uFlags, INTEGER dwhkl);
#define WinAPI_ToUnicode(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags)	ToUnicode(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags)
__EXTERN INTEGER __CALL_1 ToUnicode(INTEGER wVirtKey, INTEGER wScanCode, CHAR *lpKeyState, INTEGER pwszBuff, INTEGER cchBuff, INTEGER wFlags);
#define WinAPI_ToUnicodeEx(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags, dwhkl)	ToUnicodeEx(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags, dwhkl)
__EXTERN INTEGER __CALL_1 ToUnicodeEx(INTEGER wVirtKey, INTEGER wScanCode, CHAR *lpKeyState, INTEGER pwszBuff, INTEGER cchBuff, INTEGER wFlags, INTEGER dwhkl);
#define WinAPI_TrackPopupMenu(hMenu, uFlags, x, y, nReserved, hWnd, prcRect, prcRect__typ)	TrackPopupMenu(hMenu, uFlags, x, y, nReserved, hWnd, prcRect)
__EXTERN INTEGER __CALL_1 TrackPopupMenu(INTEGER hMenu, SET uFlags, INTEGER x, INTEGER y, INTEGER nReserved, INTEGER hWnd, WinAPI_RECT *prcRect);
#define WinAPI_TrackPopupMenuEx(p0, p1, p2, p3, p4, p5, p5__typ)	TrackPopupMenuEx(p0, p1, p2, p3, p4, p5)
__EXTERN INTEGER __CALL_1 TrackPopupMenuEx(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER p4, WinAPI_TPMPARAMS *p5);
#define WinAPI_TransactNamedPipe(hNamedPipe, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, lpOverlapped, lpOverlapped__typ)	TransactNamedPipe(hNamedPipe, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, lpOverlapped)
__EXTERN INTEGER __CALL_1 TransactNamedPipe(INTEGER hNamedPipe, INTEGER lpInBuffer, INTEGER nInBufferSize, INTEGER lpOutBuffer, INTEGER nOutBufferSize, INTEGER *lpBytesRead, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_TranslateAccelerator(hWnd, hAccTable, lpMsg, lpMsg__typ)	TranslateAcceleratorA(hWnd, hAccTable, lpMsg)
#define WinAPI_TranslateAcceleratorA(hWnd, hAccTable, lpMsg, lpMsg__typ)	TranslateAcceleratorA(hWnd, hAccTable, lpMsg)
__EXTERN INTEGER __CALL_1 TranslateAcceleratorA(INTEGER hWnd, INTEGER hAccTable, WinAPI_MSG *lpMsg);
#define WinAPI_TranslateAcceleratorW(hWnd, hAccTable, lpMsg, lpMsg__typ)	TranslateAcceleratorW(hWnd, hAccTable, lpMsg)
__EXTERN INTEGER __CALL_1 TranslateAcceleratorW(INTEGER hWnd, INTEGER hAccTable, WinAPI_MSG *lpMsg);
#define WinAPI_TranslateCharsetInfo(lpSrc, lpCs, lpCs__typ, dwFlags)	TranslateCharsetInfo(lpSrc, lpCs, dwFlags)
__EXTERN INTEGER __CALL_1 TranslateCharsetInfo(INTEGER *lpSrc, WinAPI_CHARSETINFO *lpCs, SET dwFlags);
#define WinAPI_TranslateMDISysAccel(hWndClient, lpMsg, lpMsg__typ)	TranslateMDISysAccel(hWndClient, lpMsg)
__EXTERN INTEGER __CALL_1 TranslateMDISysAccel(INTEGER hWndClient, WinAPI_MSG *lpMsg);
#define WinAPI_TranslateMessage(lpMsg, lpMsg__typ)	TranslateMessage(lpMsg)
__EXTERN INTEGER __CALL_1 TranslateMessage(WinAPI_MSG *lpMsg);
#define WinAPI_TransmitCommChar(hFile, cChar)	TransmitCommChar(hFile, cChar)
__EXTERN INTEGER __CALL_1 TransmitCommChar(INTEGER hFile, CHAR cChar);
#define WinAPI_TryEnterCriticalSection(lpCriticalSection, lpCriticalSection__typ)	TryEnterCriticalSection(lpCriticalSection)
__EXTERN INTEGER __CALL_1 TryEnterCriticalSection(WinAPI_RTL_CRITICAL_SECTION *lpCriticalSection);
#define WinAPI_UnhandledExceptionFilter(ExceptionInfo, ExceptionInfo__typ)	UnhandledExceptionFilter(ExceptionInfo)
__EXTERN INTEGER __CALL_1 UnhandledExceptionFilter(WinAPI_EXCEPTION_POINTERS *ExceptionInfo);
#define WinAPI_UnhookWindowsHook(nCode, pfnFilterProc)	UnhookWindowsHook(nCode, pfnFilterProc)
__EXTERN INTEGER __CALL_1 UnhookWindowsHook(INTEGER nCode, WinAPI_HOOKPROC pfnFilterProc);
#define WinAPI_UnhookWindowsHookEx(hhk)	UnhookWindowsHookEx(hhk)
__EXTERN INTEGER __CALL_1 UnhookWindowsHookEx(INTEGER hhk);
#define WinAPI_UnionRect(lprcDst, lprcDst__typ, lprcSrc1, lprcSrc1__typ, lprcSrc2, lprcSrc2__typ)	UnionRect(lprcDst, lprcSrc1, lprcSrc2)
__EXTERN INTEGER __CALL_1 UnionRect(WinAPI_RECT *lprcDst, WinAPI_RECT *lprcSrc1, WinAPI_RECT *lprcSrc2);
#define WinAPI_UnloadKeyboardLayout(hkl)	UnloadKeyboardLayout(hkl)
__EXTERN INTEGER __CALL_1 UnloadKeyboardLayout(INTEGER hkl);
#define WinAPI_UnlockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh)	UnlockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh)
__EXTERN INTEGER __CALL_1 UnlockFile(INTEGER hFile, INTEGER dwFileOffsetLow, INTEGER dwFileOffsetHigh, INTEGER nNumberOfBytesToUnlockLow, INTEGER nNumberOfBytesToUnlockHigh);
#define WinAPI_UnlockFileEx(hFile, dwReserved, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh, lpOverlapped, lpOverlapped__typ)	UnlockFileEx(hFile, dwReserved, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh, lpOverlapped)
__EXTERN INTEGER __CALL_1 UnlockFileEx(INTEGER hFile, INTEGER dwReserved, INTEGER nNumberOfBytesToUnlockLow, INTEGER nNumberOfBytesToUnlockHigh, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_UnlockServiceDatabase(ScLock)	UnlockServiceDatabase(ScLock)
__EXTERN INTEGER __CALL_1 UnlockServiceDatabase(INTEGER ScLock);
#define WinAPI_UnmapViewOfFile(lpBaseAddress)	UnmapViewOfFile(lpBaseAddress)
__EXTERN INTEGER __CALL_1 UnmapViewOfFile(INTEGER lpBaseAddress);
#define WinAPI_UnpackDDElParam(msg, lParam, puiLo, puiHi)	UnpackDDElParam(msg, lParam, puiLo, puiHi)
__EXTERN INTEGER __CALL_1 UnpackDDElParam(INTEGER msg, INTEGER lParam, INTEGER *puiLo, INTEGER *puiHi);
#define WinAPI_UnrealizeObject(p0)	UnrealizeObject(p0)
__EXTERN INTEGER __CALL_1 UnrealizeObject(INTEGER p0);
#define WinAPI_UnregisterClass(lpClassName, hInstance)	UnregisterClassA(lpClassName, hInstance)
#define WinAPI_UnregisterClassA(lpClassName, hInstance)	UnregisterClassA(lpClassName, hInstance)
__EXTERN INTEGER __CALL_1 UnregisterClassA(INTEGER lpClassName, INTEGER hInstance);
#define WinAPI_UnregisterClassW(lpClassName, hInstance)	UnregisterClassW(lpClassName, hInstance)
__EXTERN INTEGER __CALL_1 UnregisterClassW(INTEGER lpClassName, INTEGER hInstance);
#define WinAPI_UnregisterHotKey(hWnd, id)	UnregisterHotKey(hWnd, id)
__EXTERN INTEGER __CALL_1 UnregisterHotKey(INTEGER hWnd, INTEGER id);
#define WinAPI_UpdateColors(p0)	UpdateColors(p0)
__EXTERN INTEGER __CALL_1 UpdateColors(INTEGER p0);
#define WinAPI_UpdateResource(hUpdate, lpType, lpName, wLanguage, lpData, cbData)	UpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cbData)
#define WinAPI_UpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cbData)	UpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cbData)
__EXTERN INTEGER __CALL_1 UpdateResourceA(INTEGER hUpdate, INTEGER lpType, INTEGER lpName, SHORTINT wLanguage, INTEGER lpData, INTEGER cbData);
#define WinAPI_UpdateResourceW(hUpdate, lpType, lpName, wLanguage, lpData, cbData)	UpdateResourceW(hUpdate, lpType, lpName, wLanguage, lpData, cbData)
__EXTERN INTEGER __CALL_1 UpdateResourceW(INTEGER hUpdate, INTEGER lpType, INTEGER lpName, SHORTINT wLanguage, INTEGER lpData, INTEGER cbData);
#define WinAPI_UpdateWindow(hWnd)	UpdateWindow(hWnd)
__EXTERN INTEGER __CALL_1 UpdateWindow(INTEGER hWnd);
#define WinAPI_ValidateRect(hWnd, lpRect, lpRect__typ)	ValidateRect(hWnd, lpRect)
__EXTERN INTEGER __CALL_1 ValidateRect(INTEGER hWnd, WinAPI_RECT *lpRect);
#define WinAPI_ValidateRgn(hWnd, hRgn)	ValidateRgn(hWnd, hRgn)
__EXTERN INTEGER __CALL_1 ValidateRgn(INTEGER hWnd, INTEGER hRgn);
#define WinAPI_VerFindFile(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)	VerFindFileA(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)
#define WinAPI_VerFindFileA(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)	VerFindFileA(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)
__EXTERN SET __CALL_1 VerFindFileA(SET uFlags, INTEGER szFileName, INTEGER szWinDir, INTEGER szAppDir, INTEGER szCurDir, INTEGER *lpuCurDirLen, INTEGER szDestDir, INTEGER *lpuDestDirLen);
#define WinAPI_VerFindFileW(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)	VerFindFileW(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen)
__EXTERN SET __CALL_1 VerFindFileW(SET uFlags, INTEGER szFileName, INTEGER szWinDir, INTEGER szAppDir, INTEGER szCurDir, INTEGER *lpuCurDirLen, INTEGER szDestDir, INTEGER *lpuDestDirLen);
#define WinAPI_VerInstallFile(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)	VerInstallFileA(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)
#define WinAPI_VerInstallFileA(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)	VerInstallFileA(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)
__EXTERN SET __CALL_1 VerInstallFileA(SET uFlags, INTEGER szSrcFileName, INTEGER szDestFileName, INTEGER szSrcDir, INTEGER szDestDir, INTEGER szCurDir, INTEGER szTmpFile, INTEGER *lpuTmpFileLen);
#define WinAPI_VerInstallFileW(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)	VerInstallFileW(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen)
__EXTERN SET __CALL_1 VerInstallFileW(SET uFlags, INTEGER szSrcFileName, INTEGER szDestFileName, INTEGER szSrcDir, INTEGER szDestDir, INTEGER szCurDir, INTEGER szTmpFile, INTEGER *lpuTmpFileLen);
#define WinAPI_VerLanguageName(wLang, szLang, nSize)	VerLanguageNameA(wLang, szLang, nSize)
#define WinAPI_VerLanguageNameA(wLang, szLang, nSize)	VerLanguageNameA(wLang, szLang, nSize)
__EXTERN INTEGER __CALL_1 VerLanguageNameA(INTEGER wLang, INTEGER szLang, INTEGER nSize);
#define WinAPI_VerLanguageNameW(wLang, szLang, nSize)	VerLanguageNameW(wLang, szLang, nSize)
__EXTERN INTEGER __CALL_1 VerLanguageNameW(INTEGER wLang, INTEGER szLang, INTEGER nSize);
#define WinAPI_VerQueryValue(pBlock, lpSubBlock, lplpBuffer, puLen)	VerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen)
#define WinAPI_VerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen)	VerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen)
__EXTERN INTEGER __CALL_1 VerQueryValueA(INTEGER pBlock, INTEGER lpSubBlock, INTEGER lplpBuffer, INTEGER *puLen);
#define WinAPI_VerQueryValueW(pBlock, lpSubBlock, lplpBuffer, puLen)	VerQueryValueW(pBlock, lpSubBlock, lplpBuffer, puLen)
__EXTERN INTEGER __CALL_1 VerQueryValueW(INTEGER pBlock, INTEGER lpSubBlock, INTEGER lplpBuffer, INTEGER *puLen);
#define WinAPI_VirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect)	VirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect)
__EXTERN INTEGER __CALL_1 VirtualAlloc(INTEGER lpAddress, INTEGER dwSize, SET flAllocationType, SET flProtect);
#define WinAPI_VirtualAllocEx(hProcess, lpAddress, dwSize, flAllocationType, flProtect)	VirtualAllocEx(hProcess, lpAddress, dwSize, flAllocationType, flProtect)
__EXTERN INTEGER __CALL_1 VirtualAllocEx(INTEGER hProcess, INTEGER lpAddress, INTEGER dwSize, SET flAllocationType, SET flProtect);
#define WinAPI_VirtualFree(lpAddress, dwSize, dwFreeType)	VirtualFree(lpAddress, dwSize, dwFreeType)
__EXTERN INTEGER __CALL_1 VirtualFree(INTEGER lpAddress, INTEGER dwSize, SET dwFreeType);
#define WinAPI_VirtualLock(lpAddress, dwSize)	VirtualLock(lpAddress, dwSize)
__EXTERN INTEGER __CALL_1 VirtualLock(INTEGER lpAddress, INTEGER dwSize);
#define WinAPI_VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect)	VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect)
__EXTERN INTEGER __CALL_1 VirtualProtect(INTEGER lpAddress, INTEGER dwSize, SET flNewProtect, INTEGER *lpflOldProtect);
#define WinAPI_VirtualProtectEx(hProcess, lpAddress, dwSize, flNewProtect, lpflOldProtect)	VirtualProtectEx(hProcess, lpAddress, dwSize, flNewProtect, lpflOldProtect)
__EXTERN INTEGER __CALL_1 VirtualProtectEx(INTEGER hProcess, INTEGER lpAddress, INTEGER dwSize, SET flNewProtect, INTEGER *lpflOldProtect);
#define WinAPI_VirtualQuery(lpAddress, lpBuffer, lpBuffer__typ, dwLength)	VirtualQuery(lpAddress, lpBuffer, dwLength)
__EXTERN INTEGER __CALL_1 VirtualQuery(INTEGER lpAddress, WinAPI_MEMORY_BASIC_INFORMATION *lpBuffer, INTEGER dwLength);
#define WinAPI_VirtualQueryEx(hProcess, lpAddress, lpBuffer, lpBuffer__typ, dwLength)	VirtualQueryEx(hProcess, lpAddress, lpBuffer, dwLength)
__EXTERN INTEGER __CALL_1 VirtualQueryEx(INTEGER hProcess, INTEGER lpAddress, WinAPI_MEMORY_BASIC_INFORMATION *lpBuffer, INTEGER dwLength);
#define WinAPI_VirtualUnlock(lpAddress, dwSize)	VirtualUnlock(lpAddress, dwSize)
__EXTERN INTEGER __CALL_1 VirtualUnlock(INTEGER lpAddress, INTEGER dwSize);
#define WinAPI_VkKeyScan(ch)	VkKeyScanA(ch)
#define WinAPI_VkKeyScanA(ch)	VkKeyScanA(ch)
__EXTERN SHORTINT __CALL_1 VkKeyScanA(CHAR ch);
#define WinAPI_VkKeyScanEx(ch, dwhkl)	VkKeyScanExA(ch, dwhkl)
#define WinAPI_VkKeyScanExA(ch, dwhkl)	VkKeyScanExA(ch, dwhkl)
__EXTERN SHORTINT __CALL_1 VkKeyScanExA(CHAR ch, INTEGER dwhkl);
#define WinAPI_VkKeyScanExW(ch, dwhkl)	VkKeyScanExW(ch, dwhkl)
__EXTERN SHORTINT __CALL_1 VkKeyScanExW(SHORTINT ch, INTEGER dwhkl);
#define WinAPI_VkKeyScanW(ch)	VkKeyScanW(ch)
__EXTERN SHORTINT __CALL_1 VkKeyScanW(SHORTINT ch);
#define WinAPI_WaitCommEvent(hFile, lpEvtMask, lpOverlapped, lpOverlapped__typ)	WaitCommEvent(hFile, lpEvtMask, lpOverlapped)
__EXTERN INTEGER __CALL_1 WaitCommEvent(INTEGER hFile, SET *lpEvtMask, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_WaitForDebugEvent(lpDebugEvent, lpDebugEvent__typ, dwMilliseconds)	WaitForDebugEvent(lpDebugEvent, dwMilliseconds)
__EXTERN INTEGER __CALL_1 WaitForDebugEvent(WinAPI_DEBUG_EVENT *lpDebugEvent, INTEGER dwMilliseconds);
#define WinAPI_WaitForInputIdle(hProcess, dwMilliseconds)	WaitForInputIdle(hProcess, dwMilliseconds)
__EXTERN INTEGER __CALL_1 WaitForInputIdle(INTEGER hProcess, INTEGER dwMilliseconds);
#define WinAPI_WaitForMultipleObjects(nCount, lpHandles, bWaitAll, dwMilliseconds)	WaitForMultipleObjects(nCount, lpHandles, bWaitAll, dwMilliseconds)
__EXTERN INTEGER __CALL_1 WaitForMultipleObjects(INTEGER nCount, INTEGER *lpHandles, INTEGER bWaitAll, INTEGER dwMilliseconds);
#define WinAPI_WaitForMultipleObjectsEx(nCount, lpHandles, bWaitAll, dwMilliseconds, bAlertable)	WaitForMultipleObjectsEx(nCount, lpHandles, bWaitAll, dwMilliseconds, bAlertable)
__EXTERN INTEGER __CALL_1 WaitForMultipleObjectsEx(INTEGER nCount, INTEGER *lpHandles, INTEGER bWaitAll, INTEGER dwMilliseconds, INTEGER bAlertable);
#define WinAPI_WaitForPrinterChange(hPrinter, Flags)	WaitForPrinterChange(hPrinter, Flags)
__EXTERN INTEGER __CALL_1 WaitForPrinterChange(INTEGER hPrinter, SET Flags);
#define WinAPI_WaitForSingleObject(hHandle, dwMilliseconds)	WaitForSingleObject(hHandle, dwMilliseconds)
__EXTERN INTEGER __CALL_1 WaitForSingleObject(INTEGER hHandle, INTEGER dwMilliseconds);
#define WinAPI_WaitForSingleObjectEx(hHandle, dwMilliseconds, bAlertable)	WaitForSingleObjectEx(hHandle, dwMilliseconds, bAlertable)
__EXTERN INTEGER __CALL_1 WaitForSingleObjectEx(INTEGER hHandle, INTEGER dwMilliseconds, INTEGER bAlertable);
#define WinAPI_WaitMessage()	WaitMessage()
__EXTERN INTEGER __CALL_1 WaitMessage(void);
#define WinAPI_WaitNamedPipe(lpNamedPipeName, nTimeOut)	WaitNamedPipeA(lpNamedPipeName, nTimeOut)
#define WinAPI_WaitNamedPipeA(lpNamedPipeName, nTimeOut)	WaitNamedPipeA(lpNamedPipeName, nTimeOut)
__EXTERN INTEGER __CALL_1 WaitNamedPipeA(INTEGER lpNamedPipeName, INTEGER nTimeOut);
#define WinAPI_WaitNamedPipeW(lpNamedPipeName, nTimeOut)	WaitNamedPipeW(lpNamedPipeName, nTimeOut)
__EXTERN INTEGER __CALL_1 WaitNamedPipeW(INTEGER lpNamedPipeName, INTEGER nTimeOut);
#define WinAPI_WideCharToMultiByte(CodePage, dwFlags, lpWideCharStr, cchWideChar, lpMultiByteStr, cchMultiByte, lpDefaultChar, lpUsedDefaultChar)	WideCharToMultiByte(CodePage, dwFlags, lpWideCharStr, cchWideChar, lpMultiByteStr, cchMultiByte, lpDefaultChar, lpUsedDefaultChar)
__EXTERN INTEGER __CALL_1 WideCharToMultiByte(INTEGER CodePage, SET dwFlags, INTEGER lpWideCharStr, INTEGER cchWideChar, INTEGER lpMultiByteStr, INTEGER cchMultiByte, INTEGER lpDefaultChar, INTEGER *lpUsedDefaultChar);
#define WinAPI_WidenPath(p0)	WidenPath(p0)
__EXTERN INTEGER __CALL_1 WidenPath(INTEGER p0);
#define WinAPI_WinExec(lpCmdLine, uCmdShow)	WinExec(lpCmdLine, uCmdShow)
__EXTERN INTEGER __CALL_1 WinExec(INTEGER lpCmdLine, INTEGER uCmdShow);
#define WinAPI_WinHelp(hWndMain, lpszHelp, uCommand, dwData)	WinHelpA(hWndMain, lpszHelp, uCommand, dwData)
#define WinAPI_WinHelpA(hWndMain, lpszHelp, uCommand, dwData)	WinHelpA(hWndMain, lpszHelp, uCommand, dwData)
__EXTERN INTEGER __CALL_1 WinHelpA(INTEGER hWndMain, INTEGER lpszHelp, INTEGER uCommand, INTEGER dwData);
#define WinAPI_WinHelpW(hWndMain, lpszHelp, uCommand, dwData)	WinHelpW(hWndMain, lpszHelp, uCommand, dwData)
__EXTERN INTEGER __CALL_1 WinHelpW(INTEGER hWndMain, INTEGER lpszHelp, INTEGER uCommand, INTEGER dwData);
#define WinAPI_WindowFromDC(hDC)	WindowFromDC(hDC)
__EXTERN INTEGER __CALL_1 WindowFromDC(INTEGER hDC);
#define WinAPI_WindowFromPoint(Point)	WindowFromPoint(Point)
__EXTERN INTEGER __CALL_1 WindowFromPoint(WinAPI_POINT Point);
#define WinAPI_WriteConsole(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)	WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)
#define WinAPI_WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)	WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)
__EXTERN INTEGER __CALL_1 WriteConsoleA(INTEGER hConsoleOutput, INTEGER lpBuffer, INTEGER nNumberOfCharsToWrite, INTEGER *lpNumberOfCharsWritten, INTEGER lpReserved);
#define WinAPI_WriteConsoleInput(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsWritten)	WriteConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)
#define WinAPI_WriteConsoleInputA(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsWritten)	WriteConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)
__EXTERN INTEGER __CALL_1 WriteConsoleInputA(INTEGER hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsWritten);
#define WinAPI_WriteConsoleInputW(hConsoleInput, lpBuffer, lpBuffer__typ, nLength, lpNumberOfEventsWritten)	WriteConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten)
__EXTERN INTEGER __CALL_1 WriteConsoleInputW(INTEGER hConsoleInput, WinAPI_INPUT_RECORD *lpBuffer, INTEGER nLength, INTEGER *lpNumberOfEventsWritten);
#define WinAPI_WriteConsoleOutput(hConsoleOutput, lpBuffer, lpBuffer__typ, dwBufferSize, dwBufferCoord, lpWriteRegion, lpWriteRegion__typ)	WriteConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)
#define WinAPI_WriteConsoleOutputA(hConsoleOutput, lpBuffer, lpBuffer__typ, dwBufferSize, dwBufferCoord, lpWriteRegion, lpWriteRegion__typ)	WriteConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)
__EXTERN INTEGER __CALL_1 WriteConsoleOutputA(INTEGER hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD dwBufferSize, WinAPI_COORD dwBufferCoord, WinAPI_SMALL_RECT *lpWriteRegion);
#define WinAPI_WriteConsoleOutputAttribute(hConsoleOutput, lpAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten)	WriteConsoleOutputAttribute(hConsoleOutput, lpAttribute, nLength, dwWriteCoord, lpNumberOfAttrsWritten)
__EXTERN INTEGER __CALL_1 WriteConsoleOutputAttribute(INTEGER hConsoleOutput, SHORTINT *lpAttribute, INTEGER nLength, WinAPI_COORD dwWriteCoord, INTEGER *lpNumberOfAttrsWritten);
#define WinAPI_WriteConsoleOutputCharacter(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	WriteConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
#define WinAPI_WriteConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	WriteConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __CALL_1 WriteConsoleOutputCharacterA(INTEGER hConsoleOutput, INTEGER lpCharacter, INTEGER nLength, WinAPI_COORD dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
#define WinAPI_WriteConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)	WriteConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten)
__EXTERN INTEGER __CALL_1 WriteConsoleOutputCharacterW(INTEGER hConsoleOutput, INTEGER lpCharacter, INTEGER nLength, WinAPI_COORD dwWriteCoord, INTEGER *lpNumberOfCharsWritten);
#define WinAPI_WriteConsoleOutputW(hConsoleOutput, lpBuffer, lpBuffer__typ, dwBufferSize, dwBufferCoord, lpWriteRegion, lpWriteRegion__typ)	WriteConsoleOutputW(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion)
__EXTERN INTEGER __CALL_1 WriteConsoleOutputW(INTEGER hConsoleOutput, WinAPI_CHAR_INFO *lpBuffer, WinAPI_COORD dwBufferSize, WinAPI_COORD dwBufferCoord, WinAPI_SMALL_RECT *lpWriteRegion);
#define WinAPI_WriteConsoleW(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)	WriteConsoleW(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved)
__EXTERN INTEGER __CALL_1 WriteConsoleW(INTEGER hConsoleOutput, INTEGER lpBuffer, INTEGER nNumberOfCharsToWrite, INTEGER *lpNumberOfCharsWritten, INTEGER lpReserved);
#define WinAPI_WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped, lpOverlapped__typ)	WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped)
__EXTERN INTEGER __CALL_1 WriteFile(INTEGER hFile, INTEGER lpBuffer, INTEGER nNumberOfBytesToWrite, INTEGER *lpNumberOfBytesWritten, WinAPI_OVERLAPPED *lpOverlapped);
#define WinAPI_WriteFileEx(hFile, lpBuffer, nNumberOfBytesToWrite, lpOverlapped, lpOverlapped__typ, lpCompletionRoutine)	WriteFileEx(hFile, lpBuffer, nNumberOfBytesToWrite, lpOverlapped, lpCompletionRoutine)
__EXTERN INTEGER __CALL_1 WriteFileEx(INTEGER hFile, INTEGER lpBuffer, INTEGER nNumberOfBytesToWrite, WinAPI_OVERLAPPED *lpOverlapped, WinAPI_OVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#define WinAPI_WritePrinter(hPrinter, pBuf, cbBuf, pcWritten)	WritePrinter(hPrinter, pBuf, cbBuf, pcWritten)
__EXTERN INTEGER __CALL_1 WritePrinter(INTEGER hPrinter, INTEGER pBuf, INTEGER cbBuf, INTEGER *pcWritten);
#define WinAPI_WritePrivateProfileSection(lpAppName, lpString, lpFileName)	WritePrivateProfileSectionA(lpAppName, lpString, lpFileName)
#define WinAPI_WritePrivateProfileSectionA(lpAppName, lpString, lpFileName)	WritePrivateProfileSectionA(lpAppName, lpString, lpFileName)
__EXTERN INTEGER __CALL_1 WritePrivateProfileSectionA(INTEGER lpAppName, INTEGER lpString, INTEGER lpFileName);
#define WinAPI_WritePrivateProfileSectionW(lpAppName, lpString, lpFileName)	WritePrivateProfileSectionW(lpAppName, lpString, lpFileName)
__EXTERN INTEGER __CALL_1 WritePrivateProfileSectionW(INTEGER lpAppName, INTEGER lpString, INTEGER lpFileName);
#define WinAPI_WritePrivateProfileString(lpAppName, lpKeyName, lpString, lpFileName)	WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName)
#define WinAPI_WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName)	WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName)
__EXTERN INTEGER __CALL_1 WritePrivateProfileStringA(INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpString, INTEGER lpFileName);
#define WinAPI_WritePrivateProfileStringW(lpAppName, lpKeyName, lpString, lpFileName)	WritePrivateProfileStringW(lpAppName, lpKeyName, lpString, lpFileName)
__EXTERN INTEGER __CALL_1 WritePrivateProfileStringW(INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpString, INTEGER lpFileName);
#define WinAPI_WritePrivateProfileStruct(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	WritePrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
#define WinAPI_WritePrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	WritePrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN INTEGER __CALL_1 WritePrivateProfileStructA(INTEGER lpszSection, INTEGER lpszKey, INTEGER lpStruct, INTEGER uSizeStruct, INTEGER szFile);
#define WinAPI_WritePrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)	WritePrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile)
__EXTERN INTEGER __CALL_1 WritePrivateProfileStructW(INTEGER lpszSection, INTEGER lpszKey, INTEGER lpStruct, INTEGER uSizeStruct, INTEGER szFile);
#define WinAPI_WriteProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesWritten)	WriteProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesWritten)
__EXTERN INTEGER __CALL_1 WriteProcessMemory(INTEGER hProcess, INTEGER lpBaseAddress, INTEGER lpBuffer, INTEGER nSize, INTEGER *lpNumberOfBytesWritten);
#define WinAPI_WriteProfileSection(lpAppName, lpString)	WriteProfileSectionA(lpAppName, lpString)
#define WinAPI_WriteProfileSectionA(lpAppName, lpString)	WriteProfileSectionA(lpAppName, lpString)
__EXTERN INTEGER __CALL_1 WriteProfileSectionA(INTEGER lpAppName, INTEGER lpString);
#define WinAPI_WriteProfileSectionW(lpAppName, lpString)	WriteProfileSectionW(lpAppName, lpString)
__EXTERN INTEGER __CALL_1 WriteProfileSectionW(INTEGER lpAppName, INTEGER lpString);
#define WinAPI_WriteProfileString(lpAppName, lpKeyName, lpString)	WriteProfileStringA(lpAppName, lpKeyName, lpString)
#define WinAPI_WriteProfileStringA(lpAppName, lpKeyName, lpString)	WriteProfileStringA(lpAppName, lpKeyName, lpString)
__EXTERN INTEGER __CALL_1 WriteProfileStringA(INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpString);
#define WinAPI_WriteProfileStringW(lpAppName, lpKeyName, lpString)	WriteProfileStringW(lpAppName, lpKeyName, lpString)
__EXTERN INTEGER __CALL_1 WriteProfileStringW(INTEGER lpAppName, INTEGER lpKeyName, INTEGER lpString);
#define WinAPI_WriteTapemark(hDevice, dwTapemarkType, dwTapemarkCount, bImmediate)	WriteTapemark(hDevice, dwTapemarkType, dwTapemarkCount, bImmediate)
__EXTERN INTEGER __CALL_1 WriteTapemark(INTEGER hDevice, INTEGER dwTapemarkType, INTEGER dwTapemarkCount, INTEGER bImmediate);
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
#define WinAPI__hread(hFile, lpBuffer, lBytes)	_hread(hFile, lpBuffer, lBytes)
__EXTERN INTEGER __CALL_1 _hread(INTEGER hFile, INTEGER lpBuffer, INTEGER lBytes);
#define WinAPI__hwrite(hFile, lpBuffer, lBytes)	_hwrite(hFile, lpBuffer, lBytes)
__EXTERN INTEGER __CALL_1 _hwrite(INTEGER hFile, INTEGER lpBuffer, INTEGER lBytes);
#define WinAPI__init()	/*-noinit*/
#define WinAPI__lclose(hFile)	_lclose(hFile)
__EXTERN INTEGER __CALL_1 _lclose(INTEGER hFile);
#define WinAPI__lcreat(lpPathName, iAttribute)	_lcreat(lpPathName, iAttribute)
__EXTERN INTEGER __CALL_1 _lcreat(INTEGER lpPathName, INTEGER iAttribute);
#define WinAPI__llseek(hFile, lOffset, iOrigin)	_llseek(hFile, lOffset, iOrigin)
__EXTERN INTEGER __CALL_1 _llseek(INTEGER hFile, INTEGER lOffset, INTEGER iOrigin);
#define WinAPI__lopen(lpPathName, iReadWrite)	_lopen(lpPathName, iReadWrite)
__EXTERN INTEGER __CALL_1 _lopen(INTEGER lpPathName, INTEGER iReadWrite);
#define WinAPI__lread(hFile, lpBuffer, uBytes)	_lread(hFile, lpBuffer, uBytes)
__EXTERN INTEGER __CALL_1 _lread(INTEGER hFile, INTEGER lpBuffer, INTEGER uBytes);
#define WinAPI__lwrite(hFile, lpBuffer, uBytes)	_lwrite(hFile, lpBuffer, uBytes)
__EXTERN INTEGER __CALL_1 _lwrite(INTEGER hFile, INTEGER lpBuffer, INTEGER uBytes);
#define WinAPI_keybd_event(bVk, bScan, dwFlags, dwExtraInfo)	keybd_event(bVk, bScan, dwFlags, dwExtraInfo)
__EXTERN void __CALL_1 keybd_event(CHAR bVk, CHAR bScan, SET dwFlags, INTEGER dwExtraInfo);
#define WinAPI_lstrcat(lpString1, lpString2)	lstrcatA(lpString1, lpString2)
#define WinAPI_lstrcatA(lpString1, lpString2)	lstrcatA(lpString1, lpString2)
__EXTERN INTEGER __CALL_1 lstrcatA(INTEGER lpString1, INTEGER lpString2);
#define WinAPI_lstrcatW(lpString1, lpString2)	lstrcatW(lpString1, lpString2)
__EXTERN INTEGER __CALL_1 lstrcatW(INTEGER lpString1, INTEGER lpString2);
#define WinAPI_lstrcmp(lpString1, lpString2)	lstrcmpA(lpString1, lpString2)
#define WinAPI_lstrcmpA(lpString1, lpString2)	lstrcmpA(lpString1, lpString2)
__EXTERN INTEGER __CALL_1 lstrcmpA(INTEGER lpString1, INTEGER lpString2);
#define WinAPI_lstrcmpW(lpString1, lpString2)	lstrcmpW(lpString1, lpString2)
__EXTERN INTEGER __CALL_1 lstrcmpW(INTEGER lpString1, INTEGER lpString2);
#define WinAPI_lstrcmpi(lpString1, lpString2)	lstrcmpiA(lpString1, lpString2)
#define WinAPI_lstrcmpiA(lpString1, lpString2)	lstrcmpiA(lpString1, lpString2)
__EXTERN INTEGER __CALL_1 lstrcmpiA(INTEGER lpString1, INTEGER lpString2);
#define WinAPI_lstrcmpiW(lpString1, lpString2)	lstrcmpiW(lpString1, lpString2)
__EXTERN INTEGER __CALL_1 lstrcmpiW(INTEGER lpString1, INTEGER lpString2);
#define WinAPI_lstrcpy(lpString1, lpString2)	lstrcpyA(lpString1, lpString2)
#define WinAPI_lstrcpyA(lpString1, lpString2)	lstrcpyA(lpString1, lpString2)
__EXTERN INTEGER __CALL_1 lstrcpyA(INTEGER lpString1, INTEGER lpString2);
#define WinAPI_lstrcpyW(lpString1, lpString2)	lstrcpyW(lpString1, lpString2)
__EXTERN INTEGER __CALL_1 lstrcpyW(INTEGER lpString1, INTEGER lpString2);
#define WinAPI_lstrcpyn(lpString1, lpString2, iMaxLength)	lstrcpynA(lpString1, lpString2, iMaxLength)
#define WinAPI_lstrcpynA(lpString1, lpString2, iMaxLength)	lstrcpynA(lpString1, lpString2, iMaxLength)
__EXTERN INTEGER __CALL_1 lstrcpynA(INTEGER lpString1, INTEGER lpString2, INTEGER iMaxLength);
#define WinAPI_lstrcpynW(lpString1, lpString2, iMaxLength)	lstrcpynW(lpString1, lpString2, iMaxLength)
__EXTERN INTEGER __CALL_1 lstrcpynW(INTEGER lpString1, INTEGER lpString2, INTEGER iMaxLength);
#define WinAPI_lstrlen(lpString)	lstrlenA(lpString)
#define WinAPI_lstrlenA(lpString)	lstrlenA(lpString)
__EXTERN INTEGER __CALL_1 lstrlenA(INTEGER lpString);
#define WinAPI_lstrlenW(lpString)	lstrlenW(lpString)
__EXTERN INTEGER __CALL_1 lstrlenW(INTEGER lpString);
#define WinAPI_mouse_event(dwFlags, dx, dy, cButtons, dwExtraInfo)	mouse_event(dwFlags, dx, dy, cButtons, dwExtraInfo)
__EXTERN void __CALL_1 mouse_event(SET dwFlags, INTEGER dx, INTEGER dy, INTEGER cButtons, INTEGER dwExtraInfo);
#define WinAPI_wglCopyContext(p0, p1, p2)	wglCopyContext(p0, p1, p2)
__EXTERN INTEGER __CALL_1 wglCopyContext(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_wglCreateContext(p0)	wglCreateContext(p0)
__EXTERN INTEGER __CALL_1 wglCreateContext(INTEGER p0);
#define WinAPI_wglCreateLayerContext(p0, p1)	wglCreateLayerContext(p0, p1)
__EXTERN INTEGER __CALL_1 wglCreateLayerContext(INTEGER p0, INTEGER p1);
#define WinAPI_wglDeleteContext(p0)	wglDeleteContext(p0)
__EXTERN INTEGER __CALL_1 wglDeleteContext(INTEGER p0);
#define WinAPI_wglDescribeLayerPlane(p0, p1, p2, p3, p4, p4__typ)	wglDescribeLayerPlane(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 wglDescribeLayerPlane(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, WinAPI_LAYERPLANEDESCRIPTOR *p4);
#define WinAPI_wglGetCurrentContext()	wglGetCurrentContext()
__EXTERN INTEGER __CALL_1 wglGetCurrentContext(void);
#define WinAPI_wglGetCurrentDC()	wglGetCurrentDC()
__EXTERN INTEGER __CALL_1 wglGetCurrentDC(void);
#define WinAPI_wglGetLayerPaletteEntries(p0, p1, p2, p3, p4)	wglGetLayerPaletteEntries(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 wglGetLayerPaletteEntries(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4);
#define WinAPI_wglGetProcAddress(p0)	wglGetProcAddress(p0)
__EXTERN WinAPI_ROC __CALL_1 wglGetProcAddress(INTEGER p0);
#define WinAPI_wglMakeCurrent(p0, p1)	wglMakeCurrent(p0, p1)
__EXTERN INTEGER __CALL_1 wglMakeCurrent(INTEGER p0, INTEGER p1);
#define WinAPI_wglRealizeLayerPalette(p0, p1, p2)	wglRealizeLayerPalette(p0, p1, p2)
__EXTERN INTEGER __CALL_1 wglRealizeLayerPalette(INTEGER p0, INTEGER p1, INTEGER p2);
#define WinAPI_wglSetLayerPaletteEntries(p0, p1, p2, p3, p4)	wglSetLayerPaletteEntries(p0, p1, p2, p3, p4)
__EXTERN INTEGER __CALL_1 wglSetLayerPaletteEntries(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, INTEGER *p4);
#define WinAPI_wglShareLists(p0, p1)	wglShareLists(p0, p1)
__EXTERN INTEGER __CALL_1 wglShareLists(INTEGER p0, INTEGER p1);
#define WinAPI_wglSwapLayerBuffers(p0, p1)	wglSwapLayerBuffers(p0, p1)
__EXTERN INTEGER __CALL_1 wglSwapLayerBuffers(INTEGER p0, INTEGER p1);
#define WinAPI_wglUseFontBitmaps(p0, p1, p2, p3)	wglUseFontBitmapsA(p0, p1, p2, p3)
#define WinAPI_wglUseFontBitmapsA(p0, p1, p2, p3)	wglUseFontBitmapsA(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 wglUseFontBitmapsA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_wglUseFontBitmapsW(p0, p1, p2, p3)	wglUseFontBitmapsW(p0, p1, p2, p3)
__EXTERN INTEGER __CALL_1 wglUseFontBitmapsW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3);
#define WinAPI_wglUseFontOutlines(p0, p1, p2, p3, p4, p5, p6, p7, p7__typ)	wglUseFontOutlinesA(p0, p1, p2, p3, p4, p5, p6, p7)
#define WinAPI_wglUseFontOutlinesA(p0, p1, p2, p3, p4, p5, p6, p7, p7__typ)	wglUseFontOutlinesA(p0, p1, p2, p3, p4, p5, p6, p7)
__EXTERN INTEGER __CALL_1 wglUseFontOutlinesA(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, REAL p4, REAL p5, INTEGER p6, WinAPI_GLYPHMETRICSFLOAT *p7);
#define WinAPI_wglUseFontOutlinesW(p0, p1, p2, p3, p4, p5, p6, p7, p7__typ)	wglUseFontOutlinesW(p0, p1, p2, p3, p4, p5, p6, p7)
__EXTERN INTEGER __CALL_1 wglUseFontOutlinesW(INTEGER p0, INTEGER p1, INTEGER p2, INTEGER p3, REAL p4, REAL p5, INTEGER p6, WinAPI_GLYPHMETRICSFLOAT *p7);
#define WinAPI_wvsprintf(p0, p1, arglist)	wvsprintfA(p0, p1, arglist)
#define WinAPI_wvsprintfA(p0, p1, arglist)	wvsprintfA(p0, p1, arglist)
__EXTERN INTEGER __CALL_1 wvsprintfA(INTEGER p0, INTEGER p1, INTEGER arglist);
#define WinAPI_wvsprintfW(p0, p1, arglist)	wvsprintfW(p0, p1, arglist)
__EXTERN INTEGER __CALL_1 wvsprintfW(INTEGER p0, INTEGER p1, INTEGER arglist);

#endif

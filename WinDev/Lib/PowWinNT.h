/*  Ofront 1.2 -xtspkae */

#ifndef PowWinNT__h
#define PowWinNT__h

#include "SYSTEM.h"

typedef
	struct PowWinNT_ACE_HEADER {
		CHAR AceType, AceFlags;
		SHORTINT AceSize;
	} PowWinNT_ACE_HEADER;

typedef
	struct PowWinNT_ACCESS_ALLOWED_ACE {
		PowWinNT_ACE_HEADER Header;
		INTEGER Mask, SidStart;
	} PowWinNT_ACCESS_ALLOWED_ACE;

typedef
	struct PowWinNT_ACCESS_DENIED_ACE {
		PowWinNT_ACE_HEADER Header;
		INTEGER Mask, SidStart;
	} PowWinNT_ACCESS_DENIED_ACE;

typedef
	struct PowWinNT_ACL {
		CHAR AclRevision, Sbz1;
		SHORTINT AclSize, AceCount, Sbz2;
	} PowWinNT_ACL;

typedef
	struct PowWinNT_ACL_REVISION_INFORMATION {
		INTEGER AclRevision;
	} PowWinNT_ACL_REVISION_INFORMATION;

typedef
	struct PowWinNT_ACL_SIZE_INFORMATION {
		INTEGER AceCount, AclBytesInUse, AclBytesFree;
	} PowWinNT_ACL_SIZE_INFORMATION;

typedef
	struct PowWinNT_COMPOUND_ACCESS_ALLOWED_ACE {
		PowWinNT_ACE_HEADER Header;
		INTEGER Mask;
		SHORTINT CompoundAceType, Reserved;
		INTEGER SidStart;
	} PowWinNT_COMPOUND_ACCESS_ALLOWED_ACE;

typedef
	struct PowWinNT_EVENTLOGRECORD {
		INTEGER Length, Reserved, RecordNumber, TimeGenerated, TimeWritten, EventID;
		SHORTINT EventType, NumStrings, EventCategory, ReservedFlags;
		INTEGER ClosingRecordNumber, StringOffset, UserSidLength, UserSidOffset, DataLength, DataOffset;
	} PowWinNT_EVENTLOGRECORD;

typedef
	struct PowWinNT_EXCEPTION_RECORD *PowWinNT_PEXCEPTION_RECORD;

typedef
	struct PowWinNT_EXCEPTION_POINTERS {
		PowWinNT_PEXCEPTION_RECORD ExceptionRecord;
		INTEGER ContextRecord;
	} PowWinNT_EXCEPTION_POINTERS;

typedef
	struct PowWinNT_EXCEPTION_RECORD {
		INTEGER ExceptionCode, ExceptionFlags;
		PowWinNT_PEXCEPTION_RECORD ExceptionRecord;
		INTEGER ExceptionAddress, NumberParameters, ExceptionInformation;
	} PowWinNT_EXCEPTION_RECORD;

typedef
	struct PowWinNT_TEB {
		char _prvt0[1];
	} PowWinNT_TEB;

typedef
	struct PowWinNT_FILE_NOTIFY_INFORMATION {
		INTEGER NextEntryOffset, Action, FileNameLength, FileName;
	} PowWinNT_FILE_NOTIFY_INFORMATION;

typedef
	struct PowWinNT_FPO_DATA {
		INTEGER ulOffStart, cbProcSize, cdwLocals;
		SHORTINT cdwParams, data;
	} PowWinNT_FPO_DATA;

typedef
	struct PowWinNT_GENERIC_MAPPING {
		INTEGER GenericRead, GenericWrite, GenericExecute, GenericAll;
	} PowWinNT_GENERIC_MAPPING;

typedef
	struct PowWinNT_GUID {
		INTEGER Data1;
		SHORTINT Data2, Data3;
		CHAR Data4[8];
	} PowWinNT_GUID;

typedef
	struct PowWinNT_IMAGE_ARCHIVE_MEMBER_HEADER {
		CHAR Name[16];
		CHAR Date[12];
		CHAR UserID[6];
		CHAR GroupID[6];
		CHAR Mode[8];
		CHAR Size[10];
		CHAR EndHeader[2];
	} PowWinNT_IMAGE_ARCHIVE_MEMBER_HEADER;

typedef
	struct PowWinNT_IMAGE_AUX_SYMBOL {
		CHAR Section[18];
	} PowWinNT_IMAGE_AUX_SYMBOL;

typedef
	struct PowWinNT_IMAGE_BASE_RELOCATION {
		INTEGER VirtualAddress, SizeOfBlock;
	} PowWinNT_IMAGE_BASE_RELOCATION;

typedef
	struct PowWinNT_IMAGE_BOUND_FORWARDER_REF {
		INTEGER TimeDateStamp;
		SHORTINT OffsetModuleName, Reserved;
	} PowWinNT_IMAGE_BOUND_FORWARDER_REF;

typedef
	struct PowWinNT_IMAGE_BOUND_IMPORT_DESCRIPTOR {
		INTEGER TimeDateStamp;
		SHORTINT OffsetModuleName, NumberOfModuleForwarderRefs;
	} PowWinNT_IMAGE_BOUND_IMPORT_DESCRIPTOR;

typedef
	struct PowWinNT_IMAGE_COFF_SYMBOLS_HEADER {
		INTEGER NumberOfSymbols, LvaToFirstSymbol, NumberOfLinenumbers, LvaToFirstLinenumber, RvaToFirstByteOfCode, RvaToLastByteOfCode, RvaToFirstByteOfData, RvaToLastByteOfData;
	} PowWinNT_IMAGE_COFF_SYMBOLS_HEADER;

typedef
	struct PowWinNT_IMAGE_DATA_DIRECTORY {
		INTEGER VirtualAddress, Size;
	} PowWinNT_IMAGE_DATA_DIRECTORY;

typedef
	struct PowWinNT_IMAGE_DEBUG_DIRECTORY {
		INTEGER Characteristics, TimeDateStamp;
		SHORTINT MajorVersion, MinorVersion;
		INTEGER Type, SizeOfData, AddressOfRawData, PointerToRawData;
	} PowWinNT_IMAGE_DEBUG_DIRECTORY;

typedef
	struct PowWinNT_IMAGE_DEBUG_MISC {
		INTEGER DataType, Length, Unicode;
		CHAR Reserved[3];
		INTEGER Data;
	} PowWinNT_IMAGE_DEBUG_MISC;

typedef
	struct PowWinNT_IMAGE_DOS_HEADER {
		SHORTINT e_magic, e_cblp, e_cp, e_crlc, e_cparhdr, e_minalloc, e_maxalloc, e_ss, e_sp, e_csum, e_ip, e_cs, e_lfarlc, e_ovno;
		SHORTINT e_res[4];
		SHORTINT e_oemid, e_oeminfo;
		SHORTINT e_res2[10];
		INTEGER e_lfanew;
	} PowWinNT_IMAGE_DOS_HEADER;

typedef
	struct PowWinNT_IMAGE_EXPORT_DIRECTORY {
		INTEGER Characteristics, TimeDateStamp;
		SHORTINT MajorVersion, MinorVersion;
		INTEGER Name, Base, NumberOfFunctions, NumberOfNames, AddressOfFunctions, AddressOfNames, AddressOfNameOrdinals;
	} PowWinNT_IMAGE_EXPORT_DIRECTORY;

typedef
	struct PowWinNT_IMAGE_FILE_HEADER {
		SHORTINT Machine, NumberOfSections;
		INTEGER TimeDateStamp, PointerToSymbolTable, NumberOfSymbols;
		SHORTINT SizeOfOptionalHeader, Characteristics;
	} PowWinNT_IMAGE_FILE_HEADER;

typedef
	struct PowWinNT_IMAGE_FUNCTION_ENTRY {
		INTEGER StartingAddress, EndingAddress, EndOfPrologue;
	} PowWinNT_IMAGE_FUNCTION_ENTRY;

typedef
	struct PowWinNT_IMAGE_IMPORT_BY_NAME {
		SHORTINT Hint;
		INTEGER Name;
	} PowWinNT_IMAGE_IMPORT_BY_NAME;

typedef
	struct PowWinNT_winnt_Union8 {
		INTEGER Characteristics;
	} PowWinNT_winnt_Union8;

typedef
	struct PowWinNT_IMAGE_THUNK_DATA *PowWinNT_PIMAGE_THUNK_DATA;

typedef
	struct PowWinNT_IMAGE_IMPORT_DESCRIPTOR {
		PowWinNT_winnt_Union8 u;
		INTEGER TimeDateStamp, ForwarderChain, Name;
		PowWinNT_PIMAGE_THUNK_DATA FirstThunk;
	} PowWinNT_IMAGE_IMPORT_DESCRIPTOR;

typedef
	struct PowWinNT_winnt_Union6 {
		char _prvt0[4];
	} PowWinNT_winnt_Union6;

typedef
	struct PowWinNT_IMAGE_LINENUMBER {
		PowWinNT_winnt_Union6 Type;
		SHORTINT Linenumber;
	} PowWinNT_IMAGE_LINENUMBER;

typedef
	struct PowWinNT_IMAGE_LOAD_CONFIG_DIRECTORY {
		INTEGER Characteristics, TimeDateStamp;
		SHORTINT MajorVersion, MinorVersion;
		INTEGER GlobalFlagsClear, GlobalFlagsSet, CriticalSectionDefaultTimeout, DeCommitFreeBlockThreshold, DeCommitTotalFreeThreshold, LockPrefixTable, MaximumAllocationSize, VirtualMemoryThreshold, ProcessHeapFlags, ProcessAffinityMask;
		INTEGER Reserved[3];
	} PowWinNT_IMAGE_LOAD_CONFIG_DIRECTORY;

typedef
	struct PowWinNT_IMAGE_OPTIONAL_HEADER {
		SHORTINT Magic;
		CHAR MajorLinkerVersion, MinorLinkerVersion;
		INTEGER SizeOfCode, SizeOfInitializedData, SizeOfUninitializedData, AddressOfEntryPoint, BaseOfCode, BaseOfData, ImageBase, SectionAlignment, FileAlignment;
		SHORTINT MajorOperatingSystemVersion, MinorOperatingSystemVersion, MajorImageVersion, MinorImageVersion, MajorSubsystemVersion, MinorSubsystemVersion;
		INTEGER Win32VersionValue, SizeOfImage, SizeOfHeaders, CheckSum;
		SHORTINT Subsystem, DllCharacteristics;
		INTEGER SizeOfStackReserve, SizeOfStackCommit, SizeOfHeapReserve, SizeOfHeapCommit, LoaderFlags, NumberOfRvaAndSizes;
		PowWinNT_IMAGE_DATA_DIRECTORY DataDirectory[16];
	} PowWinNT_IMAGE_OPTIONAL_HEADER;

typedef
	struct PowWinNT_IMAGE_NT_HEADERS {
		INTEGER Signature;
		PowWinNT_IMAGE_FILE_HEADER FileHeader;
		PowWinNT_IMAGE_OPTIONAL_HEADER OptionalHeader;
	} PowWinNT_IMAGE_NT_HEADERS;

typedef
	struct PowWinNT_IMAGE_OS2_HEADER {
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
	} PowWinNT_IMAGE_OS2_HEADER;

typedef
	struct PowWinNT_winnt_Union5 {
		CHAR VirtualAddress[4];
	} PowWinNT_winnt_Union5;

typedef
	struct PowWinNT_IMAGE_RELOCATION {
		PowWinNT_winnt_Union5 u;
		INTEGER SymbolTableIndex;
		SHORTINT Type;
	} PowWinNT_IMAGE_RELOCATION;

typedef
	struct PowWinNT_IMAGE_RESOURCE_DATA_ENTRY {
		INTEGER OffsetToData, Size, CodePage, Reserved;
	} PowWinNT_IMAGE_RESOURCE_DATA_ENTRY;

typedef
	struct PowWinNT_IMAGE_RESOURCE_DIRECTORY {
		INTEGER Characteristics, TimeDateStamp;
		SHORTINT MajorVersion, MinorVersion, NumberOfNamedEntries, NumberOfIdEntries;
	} PowWinNT_IMAGE_RESOURCE_DIRECTORY;

typedef
	struct PowWinNT_winnt_Union9 {
		CHAR u[4];
	} PowWinNT_winnt_Union9;

typedef
	struct PowWinNT_winnt_Union10 {
		CHAR p[4];
	} PowWinNT_winnt_Union10;

typedef
	struct PowWinNT_IMAGE_RESOURCE_DIRECTORY_ENTRY {
		PowWinNT_winnt_Union9 d;
		PowWinNT_winnt_Union10 q;
	} PowWinNT_IMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef
	struct PowWinNT_IMAGE_RESOURCE_DIRECTORY_STRING {
		SHORTINT Length;
		INTEGER NameString;
	} PowWinNT_IMAGE_RESOURCE_DIRECTORY_STRING;

typedef
	struct PowWinNT_IMAGE_RESOURCE_DIR_STRING_U {
		SHORTINT Length;
		INTEGER NameString;
	} PowWinNT_IMAGE_RESOURCE_DIR_STRING_U;

typedef
	struct PowWinNT_IMAGE_ROM_OPTIONAL_HEADER {
		SHORTINT Magic;
		CHAR MajorLinkerVersion, MinorLinkerVersion;
		INTEGER SizeOfCode, SizeOfInitializedData, SizeOfUninitializedData, AddressOfEntryPoint, BaseOfCode, BaseOfData, BaseOfBss, GprMask;
		INTEGER CprMask[4];
		INTEGER GpValue;
	} PowWinNT_IMAGE_ROM_OPTIONAL_HEADER;

typedef
	struct PowWinNT_IMAGE_ROM_HEADERS {
		PowWinNT_IMAGE_FILE_HEADER FileHeader;
		PowWinNT_IMAGE_ROM_OPTIONAL_HEADER OptionalHeader;
	} PowWinNT_IMAGE_ROM_HEADERS;

typedef
	struct PowWinNT_IMAGE_RUNTIME_FUNCTION_ENTRY {
		INTEGER BeginAddress, EndAddress, ExceptionHandler, HandlerData, PrologEndAddress;
	} PowWinNT_IMAGE_RUNTIME_FUNCTION_ENTRY;

typedef
	struct PowWinNT_winnt_Union1 {
		CHAR data[4];
	} PowWinNT_winnt_Union1;

typedef
	struct PowWinNT_IMAGE_SECTION_HEADER {
		CHAR Name[8];
		PowWinNT_winnt_Union1 Misc;
		INTEGER VirtualAddress, SizeOfRawData, PointerToRawData, PointerToRelocations, PointerToLinenumbers;
		SHORTINT NumberOfRelocations, NumberOfLinenumbers;
		INTEGER Characteristics;
	} PowWinNT_IMAGE_SECTION_HEADER;

typedef
	struct PowWinNT_IMAGE_SEPARATE_DEBUG_HEADER {
		SHORTINT Signature, Flags, Machine, Characteristics;
		INTEGER TimeDateStamp, CheckSum, ImageBase, SizeOfImage, NumberOfSections, ExportedNamesSize, DebugDirectorySize, SectionAlignment;
		INTEGER Reserved[2];
	} PowWinNT_IMAGE_SEPARATE_DEBUG_HEADER;

typedef
	struct PowWinNT_winnt_Union2 {
		CHAR Name[8];
	} PowWinNT_winnt_Union2;

typedef
	struct PowWinNT_IMAGE_SYMBOL {
		PowWinNT_winnt_Union2 N;
		INTEGER Value;
		SHORTINT SectionNumber, Type;
		CHAR StorageClass, NumberOfAuxSymbols;
	} PowWinNT_IMAGE_SYMBOL;

typedef
	struct PowWinNT_winnt_Union7 {
		INTEGER Ordinal;
	} PowWinNT_winnt_Union7;

typedef
	struct PowWinNT_IMAGE_THUNK_DATA {
		PowWinNT_winnt_Union7 u1;
	} PowWinNT_IMAGE_THUNK_DATA;

typedef
	struct PowWinNT_IMAGE_TLS_DIRECTORY {
		INTEGER StartAddressOfRawData, EndAddressOfRawData, AddressOfIndex, AddressOfCallBacks, SizeOfZeroFill, Characteristics;
	} PowWinNT_IMAGE_TLS_DIRECTORY;

typedef
	struct PowWinNT_IMAGE_VXD_HEADER {
		SHORTINT e32_magic;
		CHAR e32_border, e32_worder;
		INTEGER e32_level;
		SHORTINT e32_cpu, e32_os;
		INTEGER e32_ver, e32_mflags, e32_mpages, e32_startobj, e32_eip, e32_stackobj, e32_esp, e32_pagesize, e32_lastpagesize, e32_fixupsize, e32_fixupsum, e32_ldrsize, e32_ldrsum, e32_objtab, e32_objcnt, e32_objmap, e32_itermap, e32_rsrctab, e32_rsrccnt, e32_restab, e32_enttab, e32_dirtab, e32_dircnt, e32_fpagetab, e32_frectab, e32_impmod, e32_impmodcnt, e32_impproc, e32_pagesum, e32_datapage, e32_preload, e32_nrestab, e32_cbnrestab, e32_nressum, e32_autodata, e32_debuginfo, e32_debuglen, e32_instpreload, e32_instdemand, e32_heapsize;
		CHAR e32_res3[12];
		INTEGER e32_winresoff, e32_winreslen;
		SHORTINT e32_devid, e32_ddkver;
	} PowWinNT_IMAGE_VXD_HEADER;

typedef
	struct PowWinNT_LARGE_INTEGER {
		CHAR u[8];
	} PowWinNT_LARGE_INTEGER;

typedef
	struct PowWinNT_winnt_Union {
		CHAR Bytes[4];
	} PowWinNT_winnt_Union;

typedef
	struct PowWinNT_LDT_ENTRY {
		SHORTINT LimitLow, BaseLow;
		PowWinNT_winnt_Union HighWord;
	} PowWinNT_LDT_ENTRY;

typedef
	struct PowWinNT_LIST_ENTRY *PowWinNT_PLIST_ENTRY;

typedef
	struct PowWinNT_LIST_ENTRY {
		PowWinNT_PLIST_ENTRY Flink, Blink;
	} PowWinNT_LIST_ENTRY;

typedef
	PowWinNT_TEB *PowWinNT_LPTEB;

typedef
	struct PowWinNT_LUID {
		INTEGER LowPart, HighPart;
	} PowWinNT_LUID;

typedef
	struct PowWinNT_LUID_AND_ATTRIBUTES {
		PowWinNT_LUID Luid;
		INTEGER Attributes;
	} PowWinNT_LUID_AND_ATTRIBUTES;

typedef
	PowWinNT_LUID_AND_ATTRIBUTES PowWinNT_LUID_AND_ATTRIBUTES_ARRAY[1];

typedef
	struct PowWinNT_MEMORY_BASIC_INFORMATION {
		INTEGER BaseAddress, AllocationBase, AllocationProtect, RegionSize, State, Protect, Type;
	} PowWinNT_MEMORY_BASIC_INFORMATION;

typedef
	struct PowWinNT_MESSAGE_RESOURCE_BLOCK {
		INTEGER LowId, HighId, OffsetToEntries;
	} PowWinNT_MESSAGE_RESOURCE_BLOCK;

typedef
	struct PowWinNT_MESSAGE_RESOURCE_DATA {
		INTEGER NumberOfBlocks, Blocks;
	} PowWinNT_MESSAGE_RESOURCE_DATA;

typedef
	struct PowWinNT_MESSAGE_RESOURCE_ENTRY {
		SHORTINT Length, Flags;
		INTEGER Text;
	} PowWinNT_MESSAGE_RESOURCE_ENTRY;

typedef
	struct PowWinNT_winnt_Union0 {
		CHAR FiberData[4];
	} PowWinNT_winnt_Union0;

typedef
	struct PowWinNT_NT_TIB *PowWinNT_PNT_TIB;

typedef
	struct PowWinNT_NT_TIB {
		PowWinNT_LPTEB ExceptionList;
		INTEGER StackBase, StackLimit, SubSystemTib;
		PowWinNT_winnt_Union0 u;
		INTEGER ArbitraryUserPointer;
		PowWinNT_PNT_TIB Self;
	} PowWinNT_NT_TIB;

typedef
	struct PowWinNT_OBJECTID {
		PowWinNT_GUID Lineage;
		INTEGER Uniquifier;
	} PowWinNT_OBJECTID;

typedef
	PowWinNT_ACCESS_ALLOWED_ACE *PowWinNT_PACCESS_ALLOWED_ACE;

typedef
	PowWinNT_ACCESS_DENIED_ACE *PowWinNT_PACCESS_DENIED_ACE;

typedef
	PowWinNT_ACE_HEADER *PowWinNT_PACE_HEADER;

typedef
	PowWinNT_ACL *PowWinNT_PACL;

typedef
	PowWinNT_ACL_REVISION_INFORMATION *PowWinNT_PACL_REVISION_INFORMATION;

typedef
	PowWinNT_ACL_SIZE_INFORMATION *PowWinNT_PACL_SIZE_INFORMATION;

typedef
	PowWinNT_COMPOUND_ACCESS_ALLOWED_ACE *PowWinNT_PCOMPOUND_ACCESS_ALLOWED_ACE;

typedef
	PowWinNT_EVENTLOGRECORD *PowWinNT_PEVENTLOGRECORD;

typedef
	PowWinNT_EXCEPTION_POINTERS *PowWinNT_PEXCEPTION_POINTERS;

typedef
	PowWinNT_FILE_NOTIFY_INFORMATION *PowWinNT_PFILE_NOTIFY_INFORMATION;

typedef
	PowWinNT_FPO_DATA *PowWinNT_PFPO_DATA;

typedef
	PowWinNT_GENERIC_MAPPING *PowWinNT_PGENERIC_MAPPING;

typedef
	PowWinNT_IMAGE_ARCHIVE_MEMBER_HEADER *PowWinNT_PIMAGE_ARCHIVE_MEMBER_HEADER;

typedef
	PowWinNT_IMAGE_AUX_SYMBOL *PowWinNT_PIMAGE_AUX_SYMBOL;

typedef
	PowWinNT_IMAGE_BASE_RELOCATION *PowWinNT_PIMAGE_BASE_RELOCATION;

typedef
	PowWinNT_IMAGE_BOUND_FORWARDER_REF *PowWinNT_PIMAGE_BOUND_FORWARDER_REF;

typedef
	PowWinNT_IMAGE_BOUND_IMPORT_DESCRIPTOR *PowWinNT_PIMAGE_BOUND_IMPORT_DESCRIPTOR;

typedef
	PowWinNT_IMAGE_COFF_SYMBOLS_HEADER *PowWinNT_PIMAGE_COFF_SYMBOLS_HEADER;

typedef
	PowWinNT_IMAGE_DATA_DIRECTORY *PowWinNT_PIMAGE_DATA_DIRECTORY;

typedef
	PowWinNT_IMAGE_DEBUG_DIRECTORY *PowWinNT_PIMAGE_DEBUG_DIRECTORY;

typedef
	PowWinNT_IMAGE_DEBUG_MISC *PowWinNT_PIMAGE_DEBUG_MISC;

typedef
	PowWinNT_IMAGE_DOS_HEADER *PowWinNT_PIMAGE_DOS_HEADER;

typedef
	PowWinNT_IMAGE_EXPORT_DIRECTORY *PowWinNT_PIMAGE_EXPORT_DIRECTORY;

typedef
	PowWinNT_IMAGE_FILE_HEADER *PowWinNT_PIMAGE_FILE_HEADER;

typedef
	PowWinNT_IMAGE_FUNCTION_ENTRY *PowWinNT_PIMAGE_FUNCTION_ENTRY;

typedef
	PowWinNT_IMAGE_IMPORT_BY_NAME *PowWinNT_PIMAGE_IMPORT_BY_NAME;

typedef
	PowWinNT_IMAGE_IMPORT_DESCRIPTOR *PowWinNT_PIMAGE_IMPORT_DESCRIPTOR;

typedef
	PowWinNT_IMAGE_LINENUMBER *PowWinNT_PIMAGE_LINENUMBER;

typedef
	PowWinNT_IMAGE_LOAD_CONFIG_DIRECTORY *PowWinNT_PIMAGE_LOAD_CONFIG_DIRECTORY;

typedef
	PowWinNT_IMAGE_NT_HEADERS *PowWinNT_PIMAGE_NT_HEADERS;

typedef
	PowWinNT_IMAGE_OPTIONAL_HEADER *PowWinNT_PIMAGE_OPTIONAL_HEADER;

typedef
	PowWinNT_IMAGE_OS2_HEADER *PowWinNT_PIMAGE_OS2_HEADER;

typedef
	PowWinNT_IMAGE_RELOCATION *PowWinNT_PIMAGE_RELOCATION;

typedef
	PowWinNT_IMAGE_RESOURCE_DATA_ENTRY *PowWinNT_PIMAGE_RESOURCE_DATA_ENTRY;

typedef
	PowWinNT_IMAGE_RESOURCE_DIRECTORY *PowWinNT_PIMAGE_RESOURCE_DIRECTORY;

typedef
	PowWinNT_IMAGE_RESOURCE_DIRECTORY_ENTRY *PowWinNT_PIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef
	PowWinNT_IMAGE_RESOURCE_DIRECTORY_STRING *PowWinNT_PIMAGE_RESOURCE_DIRECTORY_STRING;

typedef
	PowWinNT_IMAGE_RESOURCE_DIR_STRING_U *PowWinNT_PIMAGE_RESOURCE_DIR_STRING_U;

typedef
	PowWinNT_IMAGE_ROM_HEADERS *PowWinNT_PIMAGE_ROM_HEADERS;

typedef
	PowWinNT_IMAGE_ROM_OPTIONAL_HEADER *PowWinNT_PIMAGE_ROM_OPTIONAL_HEADER;

typedef
	PowWinNT_IMAGE_RUNTIME_FUNCTION_ENTRY *PowWinNT_PIMAGE_RUNTIME_FUNCTION_ENTRY;

typedef
	PowWinNT_IMAGE_SECTION_HEADER *PowWinNT_PIMAGE_SECTION_HEADER;

typedef
	PowWinNT_IMAGE_SEPARATE_DEBUG_HEADER *PowWinNT_PIMAGE_SEPARATE_DEBUG_HEADER;

typedef
	PowWinNT_IMAGE_SYMBOL *PowWinNT_PIMAGE_SYMBOL;

typedef
	void (*PowWinNT_PIMAGE_TLS_CALLBACK)(INTEGER, INTEGER, INTEGER);

typedef
	PowWinNT_IMAGE_TLS_DIRECTORY *PowWinNT_PIMAGE_TLS_DIRECTORY;

typedef
	PowWinNT_IMAGE_VXD_HEADER *PowWinNT_PIMAGE_VXD_HEADER;

typedef
	struct PowWinNT_SECURITY_DESCRIPTOR *PowWinNT_PISECURITY_DESCRIPTOR;

typedef
	struct PowWinNT_SID *PowWinNT_PISID;

typedef
	PowWinNT_LARGE_INTEGER *PowWinNT_PLARGE_INTEGER;

typedef
	PowWinNT_LDT_ENTRY *PowWinNT_PLDT_ENTRY;

typedef
	PowWinNT_LUID *PowWinNT_PLUID;

typedef
	PowWinNT_LUID_AND_ATTRIBUTES *PowWinNT_PLUID_AND_ATTRIBUTES;

typedef
	PowWinNT_MEMORY_BASIC_INFORMATION *PowWinNT_PMEMORY_BASIC_INFORMATION;

typedef
	PowWinNT_MESSAGE_RESOURCE_BLOCK *PowWinNT_PMESSAGE_RESOURCE_BLOCK;

typedef
	PowWinNT_MESSAGE_RESOURCE_DATA *PowWinNT_PMESSAGE_RESOURCE_DATA;

typedef
	PowWinNT_MESSAGE_RESOURCE_ENTRY *PowWinNT_PMESSAGE_RESOURCE_ENTRY;

typedef
	struct PowWinNT_PRIVILEGE_SET *PowWinNT_PPRIVILEGE_SET;

typedef
	struct PowWinNT_QUOTA_LIMITS *PowWinNT_PQUOTA_LIMITS;

typedef
	struct PowWinNT_PRIVILEGE_SET {
		INTEGER PrivilegeCount, Control;
		PowWinNT_LUID_AND_ATTRIBUTES_ARRAY Privilege;
	} PowWinNT_PRIVILEGE_SET;

typedef
	PowWinNT_LIST_ENTRY *PowWinNT_PRLIST_ENTRY;

typedef
	struct PowWinNT_RTL_CRITICAL_SECTION *PowWinNT_PRTL_CRITICAL_SECTION;

typedef
	struct PowWinNT_RTL_CRITICAL_SECTION_DEBUG *PowWinNT_PRTL_CRITICAL_SECTION_DEBUG;

typedef
	struct PowWinNT_SECURITY_QUALITY_OF_SERVICE *PowWinNT_PSECURITY_QUALITY_OF_SERVICE;

typedef
	struct PowWinNT_SE_IMPERSONATION_STATE *PowWinNT_PSE_IMPERSONATION_STATE;

typedef
	struct PowWinNT_SID_AND_ATTRIBUTES *PowWinNT_PSID_AND_ATTRIBUTES;

typedef
	struct PowWinNT_SID_IDENTIFIER_AUTHORITY *PowWinNT_PSID_IDENTIFIER_AUTHORITY;

typedef
	struct PowWinNT_SINGLE_LIST_ENTRY *PowWinNT_PSINGLE_LIST_ENTRY;

typedef
	struct PowWinNT_SYSTEM_ALARM_ACE *PowWinNT_PSYSTEM_ALARM_ACE;

typedef
	struct PowWinNT_SYSTEM_AUDIT_ACE *PowWinNT_PSYSTEM_AUDIT_ACE;

typedef
	struct PowWinNT_TAPE_CREATE_PARTITION *PowWinNT_PTAPE_CREATE_PARTITION;

typedef
	struct PowWinNT_TAPE_ERASE *PowWinNT_PTAPE_ERASE;

typedef
	struct PowWinNT_TAPE_GET_DRIVE_PARAMETERS *PowWinNT_PTAPE_GET_DRIVE_PARAMETERS;

typedef
	struct PowWinNT_TAPE_GET_MEDIA_PARAMETERS *PowWinNT_PTAPE_GET_MEDIA_PARAMETERS;

typedef
	struct PowWinNT_TAPE_GET_POSITION *PowWinNT_PTAPE_GET_POSITION;

typedef
	struct PowWinNT_TAPE_PREPARE *PowWinNT_PTAPE_PREPARE;

typedef
	struct PowWinNT_TAPE_SET_DRIVE_PARAMETERS *PowWinNT_PTAPE_SET_DRIVE_PARAMETERS;

typedef
	struct PowWinNT_TAPE_SET_MEDIA_PARAMETERS *PowWinNT_PTAPE_SET_MEDIA_PARAMETERS;

typedef
	struct PowWinNT_TAPE_SET_POSITION *PowWinNT_PTAPE_SET_POSITION;

typedef
	struct PowWinNT_TAPE_WRITE_MARKS *PowWinNT_PTAPE_WRITE_MARKS;

typedef
	struct PowWinNT_TOKEN_CONTROL *PowWinNT_PTOKEN_CONTROL;

typedef
	struct PowWinNT_TOKEN_DEFAULT_DACL *PowWinNT_PTOKEN_DEFAULT_DACL;

typedef
	struct PowWinNT_TOKEN_GROUPS *PowWinNT_PTOKEN_GROUPS;

typedef
	struct PowWinNT_TOKEN_OWNER *PowWinNT_PTOKEN_OWNER;

typedef
	struct PowWinNT_TOKEN_PRIMARY_GROUP *PowWinNT_PTOKEN_PRIMARY_GROUP;

typedef
	struct PowWinNT_TOKEN_PRIVILEGES *PowWinNT_PTOKEN_PRIVILEGES;

typedef
	struct PowWinNT_TOKEN_SOURCE *PowWinNT_PTOKEN_SOURCE;

typedef
	struct PowWinNT_TOKEN_STATISTICS *PowWinNT_PTOKEN_STATISTICS;

typedef
	struct PowWinNT_TOKEN_USER *PowWinNT_PTOKEN_USER;

typedef
	struct PowWinNT_ULARGE_INTEGER *PowWinNT_PULARGE_INTEGER;

typedef
	struct PowWinNT_QUOTA_LIMITS {
		INTEGER PagedPoolLimit, NonPagedPoolLimit, MinimumWorkingSetSize, MaximumWorkingSetSize, PagefileLimit;
		PowWinNT_LARGE_INTEGER TimeLimit;
	} PowWinNT_QUOTA_LIMITS;

typedef
	struct PowWinNT_RTL_CRITICAL_SECTION {
		PowWinNT_PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
		INTEGER LockCount, RecursionCount, OwningThread, LockSemaphore, Reserved;
	} PowWinNT_RTL_CRITICAL_SECTION;

typedef
	struct PowWinNT_RTL_CRITICAL_SECTION_DEBUG {
		SHORTINT Type, CreatorBackTraceIndex;
		PowWinNT_PRTL_CRITICAL_SECTION CriticalSection;
		PowWinNT_LIST_ENTRY ProcessLocksList;
		INTEGER EntryCount, ContentionCount;
		INTEGER Spare[2];
	} PowWinNT_RTL_CRITICAL_SECTION_DEBUG;

typedef
	struct PowWinNT_SECURITY_DESCRIPTOR {
		CHAR Revision, Sbz1;
		SHORTINT Control;
		INTEGER Owner, Group;
		PowWinNT_PACL Sacl, Dacl;
	} PowWinNT_SECURITY_DESCRIPTOR;

typedef
	struct PowWinNT_SECURITY_QUALITY_OF_SERVICE {
		INTEGER Length, ImpersonationLevel;
		CHAR ContextTrackingMode;
		INTEGER EffectiveOnly;
	} PowWinNT_SECURITY_QUALITY_OF_SERVICE;

typedef
	struct PowWinNT_SE_IMPERSONATION_STATE {
		INTEGER Token, CopyOnOpen, EffectiveOnly, Level;
	} PowWinNT_SE_IMPERSONATION_STATE;

typedef
	struct PowWinNT_SID_IDENTIFIER_AUTHORITY {
		CHAR Value[6];
	} PowWinNT_SID_IDENTIFIER_AUTHORITY;

typedef
	struct PowWinNT_SID {
		CHAR Revision, SubAuthorityCount;
		PowWinNT_SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
		INTEGER SubAuthority[1];
	} PowWinNT_SID;

typedef
	struct PowWinNT_SID_AND_ATTRIBUTES {
		INTEGER Sid, Attributes;
	} PowWinNT_SID_AND_ATTRIBUTES;

typedef
	PowWinNT_SID_AND_ATTRIBUTES PowWinNT_SID_AND_ATTRIBUTES_ARRAY[1];

typedef
	struct PowWinNT_SINGLE_LIST_ENTRY {
		PowWinNT_PSINGLE_LIST_ENTRY Next;
	} PowWinNT_SINGLE_LIST_ENTRY;

typedef
	struct PowWinNT_SYSTEM_ALARM_ACE {
		PowWinNT_ACE_HEADER Header;
		INTEGER Mask, SidStart;
	} PowWinNT_SYSTEM_ALARM_ACE;

typedef
	struct PowWinNT_SYSTEM_AUDIT_ACE {
		PowWinNT_ACE_HEADER Header;
		INTEGER Mask, SidStart;
	} PowWinNT_SYSTEM_AUDIT_ACE;

typedef
	struct PowWinNT_TAPE_CREATE_PARTITION {
		INTEGER Method, Count, Size;
	} PowWinNT_TAPE_CREATE_PARTITION;

typedef
	struct PowWinNT_TAPE_ERASE {
		INTEGER Type, Immediate;
	} PowWinNT_TAPE_ERASE;

typedef
	struct PowWinNT_TAPE_GET_DRIVE_PARAMETERS {
		INTEGER ECC, Compression, DataPadding, ReportSetmarks, DefaultBlockSize, MaximumBlockSize, MinimumBlockSize, MaximumPartitionCount, FeaturesLow, FeaturesHigh, EOTWarningZoneSize;
	} PowWinNT_TAPE_GET_DRIVE_PARAMETERS;

typedef
	struct PowWinNT_TAPE_GET_MEDIA_PARAMETERS {
		PowWinNT_LARGE_INTEGER Capacity, Remaining;
		INTEGER BlockSize, PartitionCount, WriteProtected;
	} PowWinNT_TAPE_GET_MEDIA_PARAMETERS;

typedef
	struct PowWinNT_TAPE_GET_POSITION {
		INTEGER Type, Partition;
		PowWinNT_LARGE_INTEGER Offset;
	} PowWinNT_TAPE_GET_POSITION;

typedef
	struct PowWinNT_TAPE_PREPARE {
		INTEGER Operation, Immediate;
	} PowWinNT_TAPE_PREPARE;

typedef
	struct PowWinNT_TAPE_SET_DRIVE_PARAMETERS {
		INTEGER ECC, Compression, DataPadding, ReportSetmarks, EOTWarningZoneSize;
	} PowWinNT_TAPE_SET_DRIVE_PARAMETERS;

typedef
	struct PowWinNT_TAPE_SET_MEDIA_PARAMETERS {
		INTEGER BlockSize;
	} PowWinNT_TAPE_SET_MEDIA_PARAMETERS;

typedef
	struct PowWinNT_TAPE_SET_POSITION {
		INTEGER Method, Partition;
		PowWinNT_LARGE_INTEGER Offset;
		INTEGER Immediate;
	} PowWinNT_TAPE_SET_POSITION;

typedef
	struct PowWinNT_TAPE_WRITE_MARKS {
		INTEGER Type, Count, Immediate;
	} PowWinNT_TAPE_WRITE_MARKS;

typedef
	struct PowWinNT_TOKEN_SOURCE {
		CHAR SourceName[8];
		PowWinNT_LUID SourceIdentifier;
	} PowWinNT_TOKEN_SOURCE;

typedef
	struct PowWinNT_TOKEN_CONTROL {
		PowWinNT_LUID TokenId, AuthenticationId, ModifiedId;
		PowWinNT_TOKEN_SOURCE TokenSource;
	} PowWinNT_TOKEN_CONTROL;

typedef
	struct PowWinNT_TOKEN_DEFAULT_DACL {
		PowWinNT_PACL DefaultDacl;
	} PowWinNT_TOKEN_DEFAULT_DACL;

typedef
	struct PowWinNT_TOKEN_GROUPS {
		INTEGER GroupCount;
		PowWinNT_SID_AND_ATTRIBUTES_ARRAY Groups;
	} PowWinNT_TOKEN_GROUPS;

typedef
	struct PowWinNT_TOKEN_OWNER {
		INTEGER Owner;
	} PowWinNT_TOKEN_OWNER;

typedef
	struct PowWinNT_TOKEN_PRIMARY_GROUP {
		INTEGER PrimaryGroup;
	} PowWinNT_TOKEN_PRIMARY_GROUP;

typedef
	struct PowWinNT_TOKEN_PRIVILEGES {
		INTEGER PrivilegeCount;
		PowWinNT_LUID_AND_ATTRIBUTES_ARRAY Privileges;
	} PowWinNT_TOKEN_PRIVILEGES;

typedef
	struct PowWinNT_TOKEN_STATISTICS {
		PowWinNT_LUID TokenId, AuthenticationId;
		PowWinNT_LARGE_INTEGER ExpirationTime;
		INTEGER TokenType, ImpersonationLevel, DynamicCharged, DynamicAvailable, GroupCount, PrivilegeCount;
		PowWinNT_LUID ModifiedId;
	} PowWinNT_TOKEN_STATISTICS;

typedef
	struct PowWinNT_TOKEN_USER {
		PowWinNT_SID_AND_ATTRIBUTES User;
	} PowWinNT_TOKEN_USER;

typedef
	struct PowWinNT_ULARGE_INTEGER {
		CHAR u[8];
	} PowWinNT_ULARGE_INTEGER;

typedef
	struct PowWinNT_winnt_Struct {
		INTEGER LowPart, HighPart;
	} PowWinNT_winnt_Struct;

typedef
	struct PowWinNT_winnt_Struct0 {
		CHAR BaseMid, Flags1, Flags2, BaseHi;
	} PowWinNT_winnt_Struct0;

typedef
	struct PowWinNT_winnt_Struct1 {
		INTEGER data;
	} PowWinNT_winnt_Struct1;

typedef
	struct PowWinNT_winnt_Struct2 {
		INTEGER Short, Long;
	} PowWinNT_winnt_Struct2;

typedef
	struct PowWinNT_winnt_Union3 {
		CHAR data[4];
	} PowWinNT_winnt_Union3;

typedef
	struct PowWinNT_winnt_Union4 {
		CHAR Array[8];
	} PowWinNT_winnt_Union4;

typedef
	struct PowWinNT_winnt_Struct3 {
		INTEGER TagIndex;
		PowWinNT_winnt_Union3 Misc;
		PowWinNT_winnt_Union4 FcnAry;
		SHORTINT TvIndex;
	} PowWinNT_winnt_Struct3;

typedef
	struct PowWinNT_winnt_Struct4 {
		SHORTINT Linenumber, Size;
	} PowWinNT_winnt_Struct4;

typedef
	struct PowWinNT_winnt_Struct5 {
		INTEGER PointerToLinenumber, PointerToNextFunction;
	} PowWinNT_winnt_Struct5;

typedef
	struct PowWinNT_winnt_Struct6 {
		SHORTINT Dimension[4];
	} PowWinNT_winnt_Struct6;

typedef
	struct PowWinNT_winnt_Struct7 {
		CHAR Name[18];
	} PowWinNT_winnt_Struct7;

typedef
	struct PowWinNT_winnt_Struct8 {
		INTEGER Length;
		SHORTINT NumberOfRelocations, NumberOfLinenumbers;
		INTEGER CheckSum;
		SHORTINT Number;
		CHAR Selection;
	} PowWinNT_winnt_Struct8;

typedef
	struct PowWinNT_winnt_Struct9 {
		INTEGER Data;
	} PowWinNT_winnt_Struct9;



import LONGINT *PowWinNT_LUID__typ;
import LONGINT *PowWinNT_LARGE_INTEGER__typ;
import LONGINT *PowWinNT_winnt_Struct__typ;
import LONGINT *PowWinNT_ULARGE_INTEGER__typ;
import LONGINT *PowWinNT_LIST_ENTRY__typ;
import LONGINT *PowWinNT_SINGLE_LIST_ENTRY__typ;
import LONGINT *PowWinNT_GUID__typ;
import LONGINT *PowWinNT_OBJECTID__typ;
import LONGINT *PowWinNT_TEB__typ;
import LONGINT *PowWinNT_winnt_Struct0__typ;
import LONGINT *PowWinNT_winnt_Struct1__typ;
import LONGINT *PowWinNT_winnt_Union__typ;
import LONGINT *PowWinNT_LDT_ENTRY__typ;
import LONGINT *PowWinNT_EXCEPTION_RECORD__typ;
import LONGINT *PowWinNT_EXCEPTION_POINTERS__typ;
import LONGINT *PowWinNT_winnt_Union0__typ;
import LONGINT *PowWinNT_NT_TIB__typ;
import LONGINT *PowWinNT_QUOTA_LIMITS__typ;
import LONGINT *PowWinNT_MEMORY_BASIC_INFORMATION__typ;
import LONGINT *PowWinNT_FILE_NOTIFY_INFORMATION__typ;
import LONGINT *PowWinNT_GENERIC_MAPPING__typ;
import LONGINT *PowWinNT_LUID_AND_ATTRIBUTES__typ;
import LONGINT *PowWinNT_SID_IDENTIFIER_AUTHORITY__typ;
import LONGINT *PowWinNT_SID__typ;
import LONGINT *PowWinNT_SID_AND_ATTRIBUTES__typ;
import LONGINT *PowWinNT_ACL__typ;
import LONGINT *PowWinNT_ACE_HEADER__typ;
import LONGINT *PowWinNT_ACCESS_ALLOWED_ACE__typ;
import LONGINT *PowWinNT_ACCESS_DENIED_ACE__typ;
import LONGINT *PowWinNT_SYSTEM_AUDIT_ACE__typ;
import LONGINT *PowWinNT_SYSTEM_ALARM_ACE__typ;
import LONGINT *PowWinNT_COMPOUND_ACCESS_ALLOWED_ACE__typ;
import LONGINT *PowWinNT_ACL_REVISION_INFORMATION__typ;
import LONGINT *PowWinNT_ACL_SIZE_INFORMATION__typ;
import LONGINT *PowWinNT_SECURITY_DESCRIPTOR__typ;
import LONGINT *PowWinNT_PRIVILEGE_SET__typ;
import LONGINT *PowWinNT_TOKEN_USER__typ;
import LONGINT *PowWinNT_TOKEN_GROUPS__typ;
import LONGINT *PowWinNT_TOKEN_PRIVILEGES__typ;
import LONGINT *PowWinNT_TOKEN_OWNER__typ;
import LONGINT *PowWinNT_TOKEN_PRIMARY_GROUP__typ;
import LONGINT *PowWinNT_TOKEN_DEFAULT_DACL__typ;
import LONGINT *PowWinNT_TOKEN_SOURCE__typ;
import LONGINT *PowWinNT_TOKEN_STATISTICS__typ;
import LONGINT *PowWinNT_TOKEN_CONTROL__typ;
import LONGINT *PowWinNT_SECURITY_QUALITY_OF_SERVICE__typ;
import LONGINT *PowWinNT_SE_IMPERSONATION_STATE__typ;
import LONGINT *PowWinNT_IMAGE_DOS_HEADER__typ;
import LONGINT *PowWinNT_IMAGE_OS2_HEADER__typ;
import LONGINT *PowWinNT_IMAGE_VXD_HEADER__typ;
import LONGINT *PowWinNT_IMAGE_FILE_HEADER__typ;
import LONGINT *PowWinNT_IMAGE_DATA_DIRECTORY__typ;
import LONGINT *PowWinNT_IMAGE_OPTIONAL_HEADER__typ;
import LONGINT *PowWinNT_IMAGE_ROM_OPTIONAL_HEADER__typ;
import LONGINT *PowWinNT_IMAGE_NT_HEADERS__typ;
import LONGINT *PowWinNT_IMAGE_ROM_HEADERS__typ;
import LONGINT *PowWinNT_winnt_Union1__typ;
import LONGINT *PowWinNT_IMAGE_SECTION_HEADER__typ;
import LONGINT *PowWinNT_winnt_Struct2__typ;
import LONGINT *PowWinNT_winnt_Union2__typ;
import LONGINT *PowWinNT_IMAGE_SYMBOL__typ;
import LONGINT *PowWinNT_winnt_Struct4__typ;
import LONGINT *PowWinNT_winnt_Union3__typ;
import LONGINT *PowWinNT_winnt_Struct5__typ;
import LONGINT *PowWinNT_winnt_Struct6__typ;
import LONGINT *PowWinNT_winnt_Union4__typ;
import LONGINT *PowWinNT_winnt_Struct3__typ;
import LONGINT *PowWinNT_winnt_Struct7__typ;
import LONGINT *PowWinNT_winnt_Struct8__typ;
import LONGINT *PowWinNT_IMAGE_AUX_SYMBOL__typ;
import LONGINT *PowWinNT_winnt_Union5__typ;
import LONGINT *PowWinNT_IMAGE_RELOCATION__typ;
import LONGINT *PowWinNT_winnt_Union6__typ;
import LONGINT *PowWinNT_IMAGE_LINENUMBER__typ;
import LONGINT *PowWinNT_IMAGE_BASE_RELOCATION__typ;
import LONGINT *PowWinNT_IMAGE_ARCHIVE_MEMBER_HEADER__typ;
import LONGINT *PowWinNT_IMAGE_EXPORT_DIRECTORY__typ;
import LONGINT *PowWinNT_IMAGE_IMPORT_BY_NAME__typ;
import LONGINT *PowWinNT_winnt_Union7__typ;
import LONGINT *PowWinNT_IMAGE_THUNK_DATA__typ;
import LONGINT *PowWinNT_winnt_Union8__typ;
import LONGINT *PowWinNT_IMAGE_IMPORT_DESCRIPTOR__typ;
import LONGINT *PowWinNT_IMAGE_BOUND_IMPORT_DESCRIPTOR__typ;
import LONGINT *PowWinNT_IMAGE_BOUND_FORWARDER_REF__typ;
import LONGINT *PowWinNT_IMAGE_TLS_DIRECTORY__typ;
import LONGINT *PowWinNT_IMAGE_RESOURCE_DIRECTORY__typ;
import LONGINT *PowWinNT_winnt_Struct9__typ;
import LONGINT *PowWinNT_winnt_Union9__typ;
import LONGINT *PowWinNT_winnt_Union10__typ;
import LONGINT *PowWinNT_IMAGE_RESOURCE_DIRECTORY_ENTRY__typ;
import LONGINT *PowWinNT_IMAGE_RESOURCE_DIRECTORY_STRING__typ;
import LONGINT *PowWinNT_IMAGE_RESOURCE_DIR_STRING_U__typ;
import LONGINT *PowWinNT_IMAGE_RESOURCE_DATA_ENTRY__typ;
import LONGINT *PowWinNT_IMAGE_LOAD_CONFIG_DIRECTORY__typ;
import LONGINT *PowWinNT_IMAGE_RUNTIME_FUNCTION_ENTRY__typ;
import LONGINT *PowWinNT_IMAGE_DEBUG_DIRECTORY__typ;
import LONGINT *PowWinNT_IMAGE_COFF_SYMBOLS_HEADER__typ;
import LONGINT *PowWinNT_FPO_DATA__typ;
import LONGINT *PowWinNT_IMAGE_DEBUG_MISC__typ;
import LONGINT *PowWinNT_IMAGE_FUNCTION_ENTRY__typ;
import LONGINT *PowWinNT_IMAGE_SEPARATE_DEBUG_HEADER__typ;
import LONGINT *PowWinNT_MESSAGE_RESOURCE_ENTRY__typ;
import LONGINT *PowWinNT_MESSAGE_RESOURCE_BLOCK__typ;
import LONGINT *PowWinNT_MESSAGE_RESOURCE_DATA__typ;
import LONGINT *PowWinNT_RTL_CRITICAL_SECTION__typ;
import LONGINT *PowWinNT_RTL_CRITICAL_SECTION_DEBUG__typ;
import LONGINT *PowWinNT_EVENTLOGRECORD__typ;
import LONGINT *PowWinNT_TAPE_ERASE__typ;
import LONGINT *PowWinNT_TAPE_PREPARE__typ;
import LONGINT *PowWinNT_TAPE_WRITE_MARKS__typ;
import LONGINT *PowWinNT_TAPE_GET_POSITION__typ;
import LONGINT *PowWinNT_TAPE_SET_POSITION__typ;
import LONGINT *PowWinNT_TAPE_GET_DRIVE_PARAMETERS__typ;
import LONGINT *PowWinNT_TAPE_SET_DRIVE_PARAMETERS__typ;
import LONGINT *PowWinNT_TAPE_GET_MEDIA_PARAMETERS__typ;
import LONGINT *PowWinNT_TAPE_SET_MEDIA_PARAMETERS__typ;
import LONGINT *PowWinNT_TAPE_CREATE_PARTITION__typ;

import void *PowWinNT__init(void);

#define PowWinNT_NtCurrentTeb()	NtCurrentTeb()
__EXTERN PowWinNT_LPTEB __CALL NtCurrentTeb(void);
#define PowWinNT_RtlCopyMemory(Destination, Source, Length)	RtlCopyMemory(Destination, Source, Length)
__EXTERN void __CALL RtlCopyMemory(INTEGER Destination, INTEGER Source, INTEGER Length);
#define PowWinNT_RtlCopyMemory32(Destination, Source, Length)	RtlCopyMemory32(Destination, Source, Length)
__EXTERN void __CALL RtlCopyMemory32(INTEGER Destination, INTEGER Source, INTEGER Length);
#define PowWinNT_RtlEqualMemory(Source1, Source2, Length)	RtlEqualMemory(Source1, Source2, Length)
__EXTERN INTEGER __CALL RtlEqualMemory(INTEGER Source1, INTEGER Source2, INTEGER Length);
#define PowWinNT_RtlFillMemory(Destination, Length, Fill)	RtlFillMemory(Destination, Length, Fill)
__EXTERN void __CALL RtlFillMemory(INTEGER Destination, INTEGER Length, CHAR Fill);
#define PowWinNT_RtlMoveMemory(Destination, Source, Length)	RtlMoveMemory(Destination, Source, Length)
__EXTERN void __CALL RtlMoveMemory(INTEGER Destination, INTEGER Source, INTEGER Length);
#define PowWinNT_RtlZeroMemory(Destination, Length)	RtlZeroMemory(Destination, Length)
__EXTERN void __CALL RtlZeroMemory(INTEGER Destination, INTEGER Length);
#define PowWinNT__init()	/*-noinit*/

#endif

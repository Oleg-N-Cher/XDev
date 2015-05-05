/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "PowWinDef.h"

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
		CHAR SymbolTableIndex[4];
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
	void (__CALL_1 *PowWinNT_PIMAGE_TLS_CALLBACK)(INTEGER, INTEGER, INTEGER);

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



export LONGINT *PowWinNT_LUID__typ;
export LONGINT *PowWinNT_LARGE_INTEGER__typ;
export LONGINT *PowWinNT_winnt_Struct__typ;
export LONGINT *PowWinNT_ULARGE_INTEGER__typ;
export LONGINT *PowWinNT_LIST_ENTRY__typ;
export LONGINT *PowWinNT_SINGLE_LIST_ENTRY__typ;
export LONGINT *PowWinNT_GUID__typ;
export LONGINT *PowWinNT_OBJECTID__typ;
export LONGINT *PowWinNT_TEB__typ;
export LONGINT *PowWinNT_winnt_Struct0__typ;
export LONGINT *PowWinNT_winnt_Struct1__typ;
export LONGINT *PowWinNT_winnt_Union__typ;
export LONGINT *PowWinNT_LDT_ENTRY__typ;
export LONGINT *PowWinNT_EXCEPTION_RECORD__typ;
export LONGINT *PowWinNT_EXCEPTION_POINTERS__typ;
export LONGINT *PowWinNT_winnt_Union0__typ;
export LONGINT *PowWinNT_NT_TIB__typ;
export LONGINT *PowWinNT_QUOTA_LIMITS__typ;
export LONGINT *PowWinNT_MEMORY_BASIC_INFORMATION__typ;
export LONGINT *PowWinNT_FILE_NOTIFY_INFORMATION__typ;
export LONGINT *PowWinNT_GENERIC_MAPPING__typ;
export LONGINT *PowWinNT_LUID_AND_ATTRIBUTES__typ;
export LONGINT *PowWinNT_SID_IDENTIFIER_AUTHORITY__typ;
export LONGINT *PowWinNT_SID__typ;
export LONGINT *PowWinNT_SID_AND_ATTRIBUTES__typ;
export LONGINT *PowWinNT_ACL__typ;
export LONGINT *PowWinNT_ACE_HEADER__typ;
export LONGINT *PowWinNT_ACCESS_ALLOWED_ACE__typ;
export LONGINT *PowWinNT_ACCESS_DENIED_ACE__typ;
export LONGINT *PowWinNT_SYSTEM_AUDIT_ACE__typ;
export LONGINT *PowWinNT_SYSTEM_ALARM_ACE__typ;
export LONGINT *PowWinNT_COMPOUND_ACCESS_ALLOWED_ACE__typ;
export LONGINT *PowWinNT_ACL_REVISION_INFORMATION__typ;
export LONGINT *PowWinNT_ACL_SIZE_INFORMATION__typ;
export LONGINT *PowWinNT_SECURITY_DESCRIPTOR__typ;
export LONGINT *PowWinNT_PRIVILEGE_SET__typ;
export LONGINT *PowWinNT_TOKEN_USER__typ;
export LONGINT *PowWinNT_TOKEN_GROUPS__typ;
export LONGINT *PowWinNT_TOKEN_PRIVILEGES__typ;
export LONGINT *PowWinNT_TOKEN_OWNER__typ;
export LONGINT *PowWinNT_TOKEN_PRIMARY_GROUP__typ;
export LONGINT *PowWinNT_TOKEN_DEFAULT_DACL__typ;
export LONGINT *PowWinNT_TOKEN_SOURCE__typ;
export LONGINT *PowWinNT_TOKEN_STATISTICS__typ;
export LONGINT *PowWinNT_TOKEN_CONTROL__typ;
export LONGINT *PowWinNT_SECURITY_QUALITY_OF_SERVICE__typ;
export LONGINT *PowWinNT_SE_IMPERSONATION_STATE__typ;
export LONGINT *PowWinNT_IMAGE_DOS_HEADER__typ;
export LONGINT *PowWinNT_IMAGE_OS2_HEADER__typ;
export LONGINT *PowWinNT_IMAGE_VXD_HEADER__typ;
export LONGINT *PowWinNT_IMAGE_FILE_HEADER__typ;
export LONGINT *PowWinNT_IMAGE_DATA_DIRECTORY__typ;
export LONGINT *PowWinNT_IMAGE_OPTIONAL_HEADER__typ;
export LONGINT *PowWinNT_IMAGE_ROM_OPTIONAL_HEADER__typ;
export LONGINT *PowWinNT_IMAGE_NT_HEADERS__typ;
export LONGINT *PowWinNT_IMAGE_ROM_HEADERS__typ;
export LONGINT *PowWinNT_winnt_Union1__typ;
export LONGINT *PowWinNT_IMAGE_SECTION_HEADER__typ;
export LONGINT *PowWinNT_winnt_Struct2__typ;
export LONGINT *PowWinNT_winnt_Union2__typ;
export LONGINT *PowWinNT_IMAGE_SYMBOL__typ;
export LONGINT *PowWinNT_winnt_Struct4__typ;
export LONGINT *PowWinNT_winnt_Union3__typ;
export LONGINT *PowWinNT_winnt_Struct5__typ;
export LONGINT *PowWinNT_winnt_Struct6__typ;
export LONGINT *PowWinNT_winnt_Union4__typ;
export LONGINT *PowWinNT_winnt_Struct3__typ;
export LONGINT *PowWinNT_winnt_Struct7__typ;
export LONGINT *PowWinNT_winnt_Struct8__typ;
export LONGINT *PowWinNT_IMAGE_AUX_SYMBOL__typ;
export LONGINT *PowWinNT_winnt_Union5__typ;
export LONGINT *PowWinNT_IMAGE_RELOCATION__typ;
export LONGINT *PowWinNT_winnt_Union6__typ;
export LONGINT *PowWinNT_IMAGE_LINENUMBER__typ;
export LONGINT *PowWinNT_IMAGE_BASE_RELOCATION__typ;
export LONGINT *PowWinNT_IMAGE_ARCHIVE_MEMBER_HEADER__typ;
export LONGINT *PowWinNT_IMAGE_EXPORT_DIRECTORY__typ;
export LONGINT *PowWinNT_IMAGE_IMPORT_BY_NAME__typ;
export LONGINT *PowWinNT_winnt_Union7__typ;
export LONGINT *PowWinNT_IMAGE_THUNK_DATA__typ;
export LONGINT *PowWinNT_winnt_Union8__typ;
export LONGINT *PowWinNT_IMAGE_IMPORT_DESCRIPTOR__typ;
export LONGINT *PowWinNT_IMAGE_BOUND_IMPORT_DESCRIPTOR__typ;
export LONGINT *PowWinNT_IMAGE_BOUND_FORWARDER_REF__typ;
export LONGINT *PowWinNT_IMAGE_TLS_DIRECTORY__typ;
export LONGINT *PowWinNT_IMAGE_RESOURCE_DIRECTORY__typ;
export LONGINT *PowWinNT_winnt_Struct9__typ;
export LONGINT *PowWinNT_winnt_Union9__typ;
export LONGINT *PowWinNT_winnt_Union10__typ;
export LONGINT *PowWinNT_IMAGE_RESOURCE_DIRECTORY_ENTRY__typ;
export LONGINT *PowWinNT_IMAGE_RESOURCE_DIRECTORY_STRING__typ;
export LONGINT *PowWinNT_IMAGE_RESOURCE_DIR_STRING_U__typ;
export LONGINT *PowWinNT_IMAGE_RESOURCE_DATA_ENTRY__typ;
export LONGINT *PowWinNT_IMAGE_LOAD_CONFIG_DIRECTORY__typ;
export LONGINT *PowWinNT_IMAGE_RUNTIME_FUNCTION_ENTRY__typ;
export LONGINT *PowWinNT_IMAGE_DEBUG_DIRECTORY__typ;
export LONGINT *PowWinNT_IMAGE_COFF_SYMBOLS_HEADER__typ;
export LONGINT *PowWinNT_FPO_DATA__typ;
export LONGINT *PowWinNT_IMAGE_DEBUG_MISC__typ;
export LONGINT *PowWinNT_IMAGE_FUNCTION_ENTRY__typ;
export LONGINT *PowWinNT_IMAGE_SEPARATE_DEBUG_HEADER__typ;
export LONGINT *PowWinNT_MESSAGE_RESOURCE_ENTRY__typ;
export LONGINT *PowWinNT_MESSAGE_RESOURCE_BLOCK__typ;
export LONGINT *PowWinNT_MESSAGE_RESOURCE_DATA__typ;
export LONGINT *PowWinNT_RTL_CRITICAL_SECTION__typ;
export LONGINT *PowWinNT_RTL_CRITICAL_SECTION_DEBUG__typ;
export LONGINT *PowWinNT_EVENTLOGRECORD__typ;
export LONGINT *PowWinNT_TAPE_ERASE__typ;
export LONGINT *PowWinNT_TAPE_PREPARE__typ;
export LONGINT *PowWinNT_TAPE_WRITE_MARKS__typ;
export LONGINT *PowWinNT_TAPE_GET_POSITION__typ;
export LONGINT *PowWinNT_TAPE_SET_POSITION__typ;
export LONGINT *PowWinNT_TAPE_GET_DRIVE_PARAMETERS__typ;
export LONGINT *PowWinNT_TAPE_SET_DRIVE_PARAMETERS__typ;
export LONGINT *PowWinNT_TAPE_GET_MEDIA_PARAMETERS__typ;
export LONGINT *PowWinNT_TAPE_SET_MEDIA_PARAMETERS__typ;
export LONGINT *PowWinNT_TAPE_CREATE_PARTITION__typ;


#define PowWinNT_NtCurrentTeb()	NtCurrentTeb()
__EXTERN PowWinNT_LPTEB __CALL_1 NtCurrentTeb(void);
#define PowWinNT_RtlCopyMemory(Destination, Source, Length)	RtlCopyMemory(Destination, Source, Length)
__EXTERN void __CALL_1 RtlCopyMemory(INTEGER Destination, INTEGER Source, INTEGER Length);
#define PowWinNT_RtlCopyMemory32(Destination, Source, Length)	RtlCopyMemory32(Destination, Source, Length)
__EXTERN void __CALL_1 RtlCopyMemory32(INTEGER Destination, INTEGER Source, INTEGER Length);
#define PowWinNT_RtlEqualMemory(Source1, Source2, Length)	RtlEqualMemory(Source1, Source2, Length)
__EXTERN INTEGER __CALL_1 RtlEqualMemory(INTEGER Source1, INTEGER Source2, INTEGER Length);
#define PowWinNT_RtlFillMemory(Destination, Length, Fill)	RtlFillMemory(Destination, Length, Fill)
__EXTERN void __CALL_1 RtlFillMemory(INTEGER Destination, INTEGER Length, CHAR Fill);
#define PowWinNT_RtlMoveMemory(Destination, Source, Length)	RtlMoveMemory(Destination, Source, Length)
__EXTERN void __CALL_1 RtlMoveMemory(INTEGER Destination, INTEGER Source, INTEGER Length);
#define PowWinNT_RtlZeroMemory(Destination, Length)	RtlZeroMemory(Destination, Length)
__EXTERN void __CALL_1 RtlZeroMemory(INTEGER Destination, INTEGER Length);
#define PowWinNT__init()	/*-noinit*/

/*============================================================================*/

__TDESC(PowWinNT_LUID__desc, 1, 0) = {__TDFLDS("LUID", 8), {-8}};
__TDESC(PowWinNT_LARGE_INTEGER__desc, 1, 0) = {__TDFLDS("LARGE_INTEGER", 8), {-8}};
__TDESC(PowWinNT_winnt_Struct__desc, 1, 0) = {__TDFLDS("winnt_Struct", 8), {-8}};
__TDESC(PowWinNT_ULARGE_INTEGER__desc, 1, 0) = {__TDFLDS("ULARGE_INTEGER", 8), {-8}};
__TDESC(PowWinNT_LIST_ENTRY__desc, 1, 0) = {__TDFLDS("LIST_ENTRY", 16), {-8}};
__TDESC(PowWinNT_SINGLE_LIST_ENTRY__desc, 1, 0) = {__TDFLDS("SINGLE_LIST_ENTRY", 8), {-8}};
__TDESC(PowWinNT_GUID__desc, 1, 0) = {__TDFLDS("GUID", 16), {-8}};
__TDESC(PowWinNT_OBJECTID__desc, 1, 0) = {__TDFLDS("OBJECTID", 20), {-8}};
__TDESC(PowWinNT_TEB__desc, 1, 0) = {__TDFLDS("TEB", 1), {-8}};
__TDESC(PowWinNT_winnt_Struct0__desc, 1, 0) = {__TDFLDS("winnt_Struct0", 4), {-8}};
__TDESC(PowWinNT_winnt_Struct1__desc, 1, 0) = {__TDFLDS("winnt_Struct1", 4), {-8}};
__TDESC(PowWinNT_winnt_Union__desc, 1, 0) = {__TDFLDS("winnt_Union", 4), {-8}};
__TDESC(PowWinNT_LDT_ENTRY__desc, 1, 0) = {__TDFLDS("LDT_ENTRY", 8), {-8}};
__TDESC(PowWinNT_EXCEPTION_RECORD__desc, 1, 0) = {__TDFLDS("EXCEPTION_RECORD", 32), {-8}};
__TDESC(PowWinNT_EXCEPTION_POINTERS__desc, 1, 0) = {__TDFLDS("EXCEPTION_POINTERS", 16), {-8}};
__TDESC(PowWinNT_winnt_Union0__desc, 1, 0) = {__TDFLDS("winnt_Union0", 4), {-8}};
__TDESC(PowWinNT_NT_TIB__desc, 1, 0) = {__TDFLDS("NT_TIB", 40), {-8}};
__TDESC(PowWinNT_QUOTA_LIMITS__desc, 1, 0) = {__TDFLDS("QUOTA_LIMITS", 28), {-8}};
__TDESC(PowWinNT_MEMORY_BASIC_INFORMATION__desc, 1, 0) = {__TDFLDS("MEMORY_BASIC_INFORMATION", 28), {-8}};
__TDESC(PowWinNT_FILE_NOTIFY_INFORMATION__desc, 1, 0) = {__TDFLDS("FILE_NOTIFY_INFORMATION", 16), {-8}};
__TDESC(PowWinNT_GENERIC_MAPPING__desc, 1, 0) = {__TDFLDS("GENERIC_MAPPING", 16), {-8}};
__TDESC(PowWinNT_LUID_AND_ATTRIBUTES__desc, 1, 0) = {__TDFLDS("LUID_AND_ATTRIBUTES", 12), {-8}};
__TDESC(PowWinNT_SID_IDENTIFIER_AUTHORITY__desc, 1, 0) = {__TDFLDS("SID_IDENTIFIER_AUTHORITY", 6), {-8}};
__TDESC(PowWinNT_SID__desc, 1, 0) = {__TDFLDS("SID", 12), {-8}};
__TDESC(PowWinNT_SID_AND_ATTRIBUTES__desc, 1, 0) = {__TDFLDS("SID_AND_ATTRIBUTES", 8), {-8}};
__TDESC(PowWinNT_ACL__desc, 1, 0) = {__TDFLDS("ACL", 8), {-8}};
__TDESC(PowWinNT_ACE_HEADER__desc, 1, 0) = {__TDFLDS("ACE_HEADER", 4), {-8}};
__TDESC(PowWinNT_ACCESS_ALLOWED_ACE__desc, 1, 0) = {__TDFLDS("ACCESS_ALLOWED_ACE", 12), {-8}};
__TDESC(PowWinNT_ACCESS_DENIED_ACE__desc, 1, 0) = {__TDFLDS("ACCESS_DENIED_ACE", 12), {-8}};
__TDESC(PowWinNT_SYSTEM_AUDIT_ACE__desc, 1, 0) = {__TDFLDS("SYSTEM_AUDIT_ACE", 12), {-8}};
__TDESC(PowWinNT_SYSTEM_ALARM_ACE__desc, 1, 0) = {__TDFLDS("SYSTEM_ALARM_ACE", 12), {-8}};
__TDESC(PowWinNT_COMPOUND_ACCESS_ALLOWED_ACE__desc, 1, 0) = {__TDFLDS("COMPOUND_ACCESS_ALLOWED_ACE", 16), {-8}};
__TDESC(PowWinNT_ACL_REVISION_INFORMATION__desc, 1, 0) = {__TDFLDS("ACL_REVISION_INFORMATION", 4), {-8}};
__TDESC(PowWinNT_ACL_SIZE_INFORMATION__desc, 1, 0) = {__TDFLDS("ACL_SIZE_INFORMATION", 12), {-8}};
__TDESC(PowWinNT_SECURITY_DESCRIPTOR__desc, 1, 0) = {__TDFLDS("SECURITY_DESCRIPTOR", 32), {-8}};
__TDESC(PowWinNT_PRIVILEGE_SET__desc, 1, 0) = {__TDFLDS("PRIVILEGE_SET", 20), {-8}};
__TDESC(PowWinNT_TOKEN_USER__desc, 1, 0) = {__TDFLDS("TOKEN_USER", 8), {-8}};
__TDESC(PowWinNT_TOKEN_GROUPS__desc, 1, 0) = {__TDFLDS("TOKEN_GROUPS", 12), {-8}};
__TDESC(PowWinNT_TOKEN_PRIVILEGES__desc, 1, 0) = {__TDFLDS("TOKEN_PRIVILEGES", 16), {-8}};
__TDESC(PowWinNT_TOKEN_OWNER__desc, 1, 0) = {__TDFLDS("TOKEN_OWNER", 4), {-8}};
__TDESC(PowWinNT_TOKEN_PRIMARY_GROUP__desc, 1, 0) = {__TDFLDS("TOKEN_PRIMARY_GROUP", 4), {-8}};
__TDESC(PowWinNT_TOKEN_DEFAULT_DACL__desc, 1, 0) = {__TDFLDS("TOKEN_DEFAULT_DACL", 8), {-8}};
__TDESC(PowWinNT_TOKEN_SOURCE__desc, 1, 0) = {__TDFLDS("TOKEN_SOURCE", 16), {-8}};
__TDESC(PowWinNT_TOKEN_STATISTICS__desc, 1, 0) = {__TDFLDS("TOKEN_STATISTICS", 56), {-8}};
__TDESC(PowWinNT_TOKEN_CONTROL__desc, 1, 0) = {__TDFLDS("TOKEN_CONTROL", 40), {-8}};
__TDESC(PowWinNT_SECURITY_QUALITY_OF_SERVICE__desc, 1, 0) = {__TDFLDS("SECURITY_QUALITY_OF_SERVICE", 16), {-8}};
__TDESC(PowWinNT_SE_IMPERSONATION_STATE__desc, 1, 0) = {__TDFLDS("SE_IMPERSONATION_STATE", 16), {-8}};
__TDESC(PowWinNT_IMAGE_DOS_HEADER__desc, 1, 0) = {__TDFLDS("IMAGE_DOS_HEADER", 64), {-8}};
__TDESC(PowWinNT_IMAGE_OS2_HEADER__desc, 1, 0) = {__TDFLDS("IMAGE_OS2_HEADER", 64), {-8}};
__TDESC(PowWinNT_IMAGE_VXD_HEADER__desc, 1, 0) = {__TDFLDS("IMAGE_VXD_HEADER", 196), {-8}};
__TDESC(PowWinNT_IMAGE_FILE_HEADER__desc, 1, 0) = {__TDFLDS("IMAGE_FILE_HEADER", 20), {-8}};
__TDESC(PowWinNT_IMAGE_DATA_DIRECTORY__desc, 1, 0) = {__TDFLDS("IMAGE_DATA_DIRECTORY", 8), {-8}};
__TDESC(PowWinNT_IMAGE_OPTIONAL_HEADER__desc, 1, 0) = {__TDFLDS("IMAGE_OPTIONAL_HEADER", 224), {-8}};
__TDESC(PowWinNT_IMAGE_ROM_OPTIONAL_HEADER__desc, 1, 0) = {__TDFLDS("IMAGE_ROM_OPTIONAL_HEADER", 56), {-8}};
__TDESC(PowWinNT_IMAGE_NT_HEADERS__desc, 1, 0) = {__TDFLDS("IMAGE_NT_HEADERS", 248), {-8}};
__TDESC(PowWinNT_IMAGE_ROM_HEADERS__desc, 1, 0) = {__TDFLDS("IMAGE_ROM_HEADERS", 76), {-8}};
__TDESC(PowWinNT_winnt_Union1__desc, 1, 0) = {__TDFLDS("winnt_Union1", 4), {-8}};
__TDESC(PowWinNT_IMAGE_SECTION_HEADER__desc, 1, 0) = {__TDFLDS("IMAGE_SECTION_HEADER", 40), {-8}};
__TDESC(PowWinNT_winnt_Struct2__desc, 1, 0) = {__TDFLDS("winnt_Struct2", 8), {-8}};
__TDESC(PowWinNT_winnt_Union2__desc, 1, 0) = {__TDFLDS("winnt_Union2", 8), {-8}};
__TDESC(PowWinNT_IMAGE_SYMBOL__desc, 1, 0) = {__TDFLDS("IMAGE_SYMBOL", 20), {-8}};
__TDESC(PowWinNT_winnt_Struct4__desc, 1, 0) = {__TDFLDS("winnt_Struct4", 4), {-8}};
__TDESC(PowWinNT_winnt_Union3__desc, 1, 0) = {__TDFLDS("winnt_Union3", 4), {-8}};
__TDESC(PowWinNT_winnt_Struct5__desc, 1, 0) = {__TDFLDS("winnt_Struct5", 8), {-8}};
__TDESC(PowWinNT_winnt_Struct6__desc, 1, 0) = {__TDFLDS("winnt_Struct6", 8), {-8}};
__TDESC(PowWinNT_winnt_Union4__desc, 1, 0) = {__TDFLDS("winnt_Union4", 8), {-8}};
__TDESC(PowWinNT_winnt_Struct3__desc, 1, 0) = {__TDFLDS("winnt_Struct3", 20), {-8}};
__TDESC(PowWinNT_winnt_Struct7__desc, 1, 0) = {__TDFLDS("winnt_Struct7", 18), {-8}};
__TDESC(PowWinNT_winnt_Struct8__desc, 1, 0) = {__TDFLDS("winnt_Struct8", 16), {-8}};
__TDESC(PowWinNT_IMAGE_AUX_SYMBOL__desc, 1, 0) = {__TDFLDS("IMAGE_AUX_SYMBOL", 18), {-8}};
__TDESC(PowWinNT_winnt_Union5__desc, 1, 0) = {__TDFLDS("winnt_Union5", 4), {-8}};
__TDESC(PowWinNT_IMAGE_RELOCATION__desc, 1, 0) = {__TDFLDS("IMAGE_RELOCATION", 12), {-8}};
__TDESC(PowWinNT_winnt_Union6__desc, 1, 0) = {__TDFLDS("winnt_Union6", 4), {-8}};
__TDESC(PowWinNT_IMAGE_LINENUMBER__desc, 1, 0) = {__TDFLDS("IMAGE_LINENUMBER", 6), {-8}};
__TDESC(PowWinNT_IMAGE_BASE_RELOCATION__desc, 1, 0) = {__TDFLDS("IMAGE_BASE_RELOCATION", 8), {-8}};
__TDESC(PowWinNT_IMAGE_ARCHIVE_MEMBER_HEADER__desc, 1, 0) = {__TDFLDS("IMAGE_ARCHIVE_MEMBER_HEADER", 60), {-8}};
__TDESC(PowWinNT_IMAGE_EXPORT_DIRECTORY__desc, 1, 0) = {__TDFLDS("IMAGE_EXPORT_DIRECTORY", 40), {-8}};
__TDESC(PowWinNT_IMAGE_IMPORT_BY_NAME__desc, 1, 0) = {__TDFLDS("IMAGE_IMPORT_BY_NAME", 8), {-8}};
__TDESC(PowWinNT_winnt_Union7__desc, 1, 0) = {__TDFLDS("winnt_Union7", 4), {-8}};
__TDESC(PowWinNT_IMAGE_THUNK_DATA__desc, 1, 0) = {__TDFLDS("IMAGE_THUNK_DATA", 4), {-8}};
__TDESC(PowWinNT_winnt_Union8__desc, 1, 0) = {__TDFLDS("winnt_Union8", 4), {-8}};
__TDESC(PowWinNT_IMAGE_IMPORT_DESCRIPTOR__desc, 1, 0) = {__TDFLDS("IMAGE_IMPORT_DESCRIPTOR", 24), {-8}};
__TDESC(PowWinNT_IMAGE_BOUND_IMPORT_DESCRIPTOR__desc, 1, 0) = {__TDFLDS("IMAGE_BOUND_IMPORT_DESCRIPTOR", 8), {-8}};
__TDESC(PowWinNT_IMAGE_BOUND_FORWARDER_REF__desc, 1, 0) = {__TDFLDS("IMAGE_BOUND_FORWARDER_REF", 8), {-8}};
__TDESC(PowWinNT_IMAGE_TLS_DIRECTORY__desc, 1, 0) = {__TDFLDS("IMAGE_TLS_DIRECTORY", 24), {-8}};
__TDESC(PowWinNT_IMAGE_RESOURCE_DIRECTORY__desc, 1, 0) = {__TDFLDS("IMAGE_RESOURCE_DIRECTORY", 16), {-8}};
__TDESC(PowWinNT_winnt_Struct9__desc, 1, 0) = {__TDFLDS("winnt_Struct9", 4), {-8}};
__TDESC(PowWinNT_winnt_Union9__desc, 1, 0) = {__TDFLDS("winnt_Union9", 4), {-8}};
__TDESC(PowWinNT_winnt_Union10__desc, 1, 0) = {__TDFLDS("winnt_Union10", 4), {-8}};
__TDESC(PowWinNT_IMAGE_RESOURCE_DIRECTORY_ENTRY__desc, 1, 0) = {__TDFLDS("IMAGE_RESOURCE_DIRECTORY_ENTRY", 8), {-8}};
__TDESC(PowWinNT_IMAGE_RESOURCE_DIRECTORY_STRING__desc, 1, 0) = {__TDFLDS("IMAGE_RESOURCE_DIRECTORY_STRING", 8), {-8}};
__TDESC(PowWinNT_IMAGE_RESOURCE_DIR_STRING_U__desc, 1, 0) = {__TDFLDS("IMAGE_RESOURCE_DIR_STRING_U", 8), {-8}};
__TDESC(PowWinNT_IMAGE_RESOURCE_DATA_ENTRY__desc, 1, 0) = {__TDFLDS("IMAGE_RESOURCE_DATA_ENTRY", 16), {-8}};
__TDESC(PowWinNT_IMAGE_LOAD_CONFIG_DIRECTORY__desc, 1, 0) = {__TDFLDS("IMAGE_LOAD_CONFIG_DIRECTORY", 64), {-8}};
__TDESC(PowWinNT_IMAGE_RUNTIME_FUNCTION_ENTRY__desc, 1, 0) = {__TDFLDS("IMAGE_RUNTIME_FUNCTION_ENTRY", 20), {-8}};
__TDESC(PowWinNT_IMAGE_DEBUG_DIRECTORY__desc, 1, 0) = {__TDFLDS("IMAGE_DEBUG_DIRECTORY", 28), {-8}};
__TDESC(PowWinNT_IMAGE_COFF_SYMBOLS_HEADER__desc, 1, 0) = {__TDFLDS("IMAGE_COFF_SYMBOLS_HEADER", 32), {-8}};
__TDESC(PowWinNT_FPO_DATA__desc, 1, 0) = {__TDFLDS("FPO_DATA", 16), {-8}};
__TDESC(PowWinNT_IMAGE_DEBUG_MISC__desc, 1, 0) = {__TDFLDS("IMAGE_DEBUG_MISC", 20), {-8}};
__TDESC(PowWinNT_IMAGE_FUNCTION_ENTRY__desc, 1, 0) = {__TDFLDS("IMAGE_FUNCTION_ENTRY", 12), {-8}};
__TDESC(PowWinNT_IMAGE_SEPARATE_DEBUG_HEADER__desc, 1, 0) = {__TDFLDS("IMAGE_SEPARATE_DEBUG_HEADER", 48), {-8}};
__TDESC(PowWinNT_MESSAGE_RESOURCE_ENTRY__desc, 1, 0) = {__TDFLDS("MESSAGE_RESOURCE_ENTRY", 8), {-8}};
__TDESC(PowWinNT_MESSAGE_RESOURCE_BLOCK__desc, 1, 0) = {__TDFLDS("MESSAGE_RESOURCE_BLOCK", 12), {-8}};
__TDESC(PowWinNT_MESSAGE_RESOURCE_DATA__desc, 1, 0) = {__TDFLDS("MESSAGE_RESOURCE_DATA", 8), {-8}};
__TDESC(PowWinNT_RTL_CRITICAL_SECTION__desc, 1, 0) = {__TDFLDS("RTL_CRITICAL_SECTION", 32), {-8}};
__TDESC(PowWinNT_RTL_CRITICAL_SECTION_DEBUG__desc, 1, 0) = {__TDFLDS("RTL_CRITICAL_SECTION_DEBUG", 48), {-8}};
__TDESC(PowWinNT_EVENTLOGRECORD__desc, 1, 0) = {__TDFLDS("EVENTLOGRECORD", 56), {-8}};
__TDESC(PowWinNT_TAPE_ERASE__desc, 1, 0) = {__TDFLDS("TAPE_ERASE", 8), {-8}};
__TDESC(PowWinNT_TAPE_PREPARE__desc, 1, 0) = {__TDFLDS("TAPE_PREPARE", 8), {-8}};
__TDESC(PowWinNT_TAPE_WRITE_MARKS__desc, 1, 0) = {__TDFLDS("TAPE_WRITE_MARKS", 12), {-8}};
__TDESC(PowWinNT_TAPE_GET_POSITION__desc, 1, 0) = {__TDFLDS("TAPE_GET_POSITION", 16), {-8}};
__TDESC(PowWinNT_TAPE_SET_POSITION__desc, 1, 0) = {__TDFLDS("TAPE_SET_POSITION", 20), {-8}};
__TDESC(PowWinNT_TAPE_GET_DRIVE_PARAMETERS__desc, 1, 0) = {__TDFLDS("TAPE_GET_DRIVE_PARAMETERS", 44), {-8}};
__TDESC(PowWinNT_TAPE_SET_DRIVE_PARAMETERS__desc, 1, 0) = {__TDFLDS("TAPE_SET_DRIVE_PARAMETERS", 20), {-8}};
__TDESC(PowWinNT_TAPE_GET_MEDIA_PARAMETERS__desc, 1, 0) = {__TDFLDS("TAPE_GET_MEDIA_PARAMETERS", 28), {-8}};
__TDESC(PowWinNT_TAPE_SET_MEDIA_PARAMETERS__desc, 1, 0) = {__TDFLDS("TAPE_SET_MEDIA_PARAMETERS", 4), {-8}};
__TDESC(PowWinNT_TAPE_CREATE_PARTITION__desc, 1, 0) = {__TDFLDS("TAPE_CREATE_PARTITION", 12), {-8}};

export void *PowWinNT__init(void)
{
	__DEFMOD;
	__IMPORT(PowWinDef__init);
	__REGMOD("PowWinNT", 0);
	__INITYP(PowWinNT_LUID, PowWinNT_LUID, 0);
	__INITYP(PowWinNT_LARGE_INTEGER, PowWinNT_LARGE_INTEGER, 0);
	__INITYP(PowWinNT_winnt_Struct, PowWinNT_winnt_Struct, 0);
	__INITYP(PowWinNT_ULARGE_INTEGER, PowWinNT_ULARGE_INTEGER, 0);
	__INITYP(PowWinNT_LIST_ENTRY, PowWinNT_LIST_ENTRY, 0);
	__INITYP(PowWinNT_SINGLE_LIST_ENTRY, PowWinNT_SINGLE_LIST_ENTRY, 0);
	__INITYP(PowWinNT_GUID, PowWinNT_GUID, 0);
	__INITYP(PowWinNT_OBJECTID, PowWinNT_OBJECTID, 0);
	__INITYP(PowWinNT_TEB, PowWinNT_TEB, 0);
	__INITYP(PowWinNT_winnt_Struct0, PowWinNT_winnt_Struct0, 0);
	__INITYP(PowWinNT_winnt_Struct1, PowWinNT_winnt_Struct1, 0);
	__INITYP(PowWinNT_winnt_Union, PowWinNT_winnt_Union, 0);
	__INITYP(PowWinNT_LDT_ENTRY, PowWinNT_LDT_ENTRY, 0);
	__INITYP(PowWinNT_EXCEPTION_RECORD, PowWinNT_EXCEPTION_RECORD, 0);
	__INITYP(PowWinNT_EXCEPTION_POINTERS, PowWinNT_EXCEPTION_POINTERS, 0);
	__INITYP(PowWinNT_winnt_Union0, PowWinNT_winnt_Union0, 0);
	__INITYP(PowWinNT_NT_TIB, PowWinNT_NT_TIB, 0);
	__INITYP(PowWinNT_QUOTA_LIMITS, PowWinNT_QUOTA_LIMITS, 0);
	__INITYP(PowWinNT_MEMORY_BASIC_INFORMATION, PowWinNT_MEMORY_BASIC_INFORMATION, 0);
	__INITYP(PowWinNT_FILE_NOTIFY_INFORMATION, PowWinNT_FILE_NOTIFY_INFORMATION, 0);
	__INITYP(PowWinNT_GENERIC_MAPPING, PowWinNT_GENERIC_MAPPING, 0);
	__INITYP(PowWinNT_LUID_AND_ATTRIBUTES, PowWinNT_LUID_AND_ATTRIBUTES, 0);
	__INITYP(PowWinNT_SID_IDENTIFIER_AUTHORITY, PowWinNT_SID_IDENTIFIER_AUTHORITY, 0);
	__INITYP(PowWinNT_SID, PowWinNT_SID, 0);
	__INITYP(PowWinNT_SID_AND_ATTRIBUTES, PowWinNT_SID_AND_ATTRIBUTES, 0);
	__INITYP(PowWinNT_ACL, PowWinNT_ACL, 0);
	__INITYP(PowWinNT_ACE_HEADER, PowWinNT_ACE_HEADER, 0);
	__INITYP(PowWinNT_ACCESS_ALLOWED_ACE, PowWinNT_ACCESS_ALLOWED_ACE, 0);
	__INITYP(PowWinNT_ACCESS_DENIED_ACE, PowWinNT_ACCESS_DENIED_ACE, 0);
	__INITYP(PowWinNT_SYSTEM_AUDIT_ACE, PowWinNT_SYSTEM_AUDIT_ACE, 0);
	__INITYP(PowWinNT_SYSTEM_ALARM_ACE, PowWinNT_SYSTEM_ALARM_ACE, 0);
	__INITYP(PowWinNT_COMPOUND_ACCESS_ALLOWED_ACE, PowWinNT_COMPOUND_ACCESS_ALLOWED_ACE, 0);
	__INITYP(PowWinNT_ACL_REVISION_INFORMATION, PowWinNT_ACL_REVISION_INFORMATION, 0);
	__INITYP(PowWinNT_ACL_SIZE_INFORMATION, PowWinNT_ACL_SIZE_INFORMATION, 0);
	__INITYP(PowWinNT_SECURITY_DESCRIPTOR, PowWinNT_SECURITY_DESCRIPTOR, 0);
	__INITYP(PowWinNT_PRIVILEGE_SET, PowWinNT_PRIVILEGE_SET, 0);
	__INITYP(PowWinNT_TOKEN_USER, PowWinNT_TOKEN_USER, 0);
	__INITYP(PowWinNT_TOKEN_GROUPS, PowWinNT_TOKEN_GROUPS, 0);
	__INITYP(PowWinNT_TOKEN_PRIVILEGES, PowWinNT_TOKEN_PRIVILEGES, 0);
	__INITYP(PowWinNT_TOKEN_OWNER, PowWinNT_TOKEN_OWNER, 0);
	__INITYP(PowWinNT_TOKEN_PRIMARY_GROUP, PowWinNT_TOKEN_PRIMARY_GROUP, 0);
	__INITYP(PowWinNT_TOKEN_DEFAULT_DACL, PowWinNT_TOKEN_DEFAULT_DACL, 0);
	__INITYP(PowWinNT_TOKEN_SOURCE, PowWinNT_TOKEN_SOURCE, 0);
	__INITYP(PowWinNT_TOKEN_STATISTICS, PowWinNT_TOKEN_STATISTICS, 0);
	__INITYP(PowWinNT_TOKEN_CONTROL, PowWinNT_TOKEN_CONTROL, 0);
	__INITYP(PowWinNT_SECURITY_QUALITY_OF_SERVICE, PowWinNT_SECURITY_QUALITY_OF_SERVICE, 0);
	__INITYP(PowWinNT_SE_IMPERSONATION_STATE, PowWinNT_SE_IMPERSONATION_STATE, 0);
	__INITYP(PowWinNT_IMAGE_DOS_HEADER, PowWinNT_IMAGE_DOS_HEADER, 0);
	__INITYP(PowWinNT_IMAGE_OS2_HEADER, PowWinNT_IMAGE_OS2_HEADER, 0);
	__INITYP(PowWinNT_IMAGE_VXD_HEADER, PowWinNT_IMAGE_VXD_HEADER, 0);
	__INITYP(PowWinNT_IMAGE_FILE_HEADER, PowWinNT_IMAGE_FILE_HEADER, 0);
	__INITYP(PowWinNT_IMAGE_DATA_DIRECTORY, PowWinNT_IMAGE_DATA_DIRECTORY, 0);
	__INITYP(PowWinNT_IMAGE_OPTIONAL_HEADER, PowWinNT_IMAGE_OPTIONAL_HEADER, 0);
	__INITYP(PowWinNT_IMAGE_ROM_OPTIONAL_HEADER, PowWinNT_IMAGE_ROM_OPTIONAL_HEADER, 0);
	__INITYP(PowWinNT_IMAGE_NT_HEADERS, PowWinNT_IMAGE_NT_HEADERS, 0);
	__INITYP(PowWinNT_IMAGE_ROM_HEADERS, PowWinNT_IMAGE_ROM_HEADERS, 0);
	__INITYP(PowWinNT_winnt_Union1, PowWinNT_winnt_Union1, 0);
	__INITYP(PowWinNT_IMAGE_SECTION_HEADER, PowWinNT_IMAGE_SECTION_HEADER, 0);
	__INITYP(PowWinNT_winnt_Struct2, PowWinNT_winnt_Struct2, 0);
	__INITYP(PowWinNT_winnt_Union2, PowWinNT_winnt_Union2, 0);
	__INITYP(PowWinNT_IMAGE_SYMBOL, PowWinNT_IMAGE_SYMBOL, 0);
	__INITYP(PowWinNT_winnt_Struct4, PowWinNT_winnt_Struct4, 0);
	__INITYP(PowWinNT_winnt_Union3, PowWinNT_winnt_Union3, 0);
	__INITYP(PowWinNT_winnt_Struct5, PowWinNT_winnt_Struct5, 0);
	__INITYP(PowWinNT_winnt_Struct6, PowWinNT_winnt_Struct6, 0);
	__INITYP(PowWinNT_winnt_Union4, PowWinNT_winnt_Union4, 0);
	__INITYP(PowWinNT_winnt_Struct3, PowWinNT_winnt_Struct3, 0);
	__INITYP(PowWinNT_winnt_Struct7, PowWinNT_winnt_Struct7, 0);
	__INITYP(PowWinNT_winnt_Struct8, PowWinNT_winnt_Struct8, 0);
	__INITYP(PowWinNT_IMAGE_AUX_SYMBOL, PowWinNT_IMAGE_AUX_SYMBOL, 0);
	__INITYP(PowWinNT_winnt_Union5, PowWinNT_winnt_Union5, 0);
	__INITYP(PowWinNT_IMAGE_RELOCATION, PowWinNT_IMAGE_RELOCATION, 0);
	__INITYP(PowWinNT_winnt_Union6, PowWinNT_winnt_Union6, 0);
	__INITYP(PowWinNT_IMAGE_LINENUMBER, PowWinNT_IMAGE_LINENUMBER, 0);
	__INITYP(PowWinNT_IMAGE_BASE_RELOCATION, PowWinNT_IMAGE_BASE_RELOCATION, 0);
	__INITYP(PowWinNT_IMAGE_ARCHIVE_MEMBER_HEADER, PowWinNT_IMAGE_ARCHIVE_MEMBER_HEADER, 0);
	__INITYP(PowWinNT_IMAGE_EXPORT_DIRECTORY, PowWinNT_IMAGE_EXPORT_DIRECTORY, 0);
	__INITYP(PowWinNT_IMAGE_IMPORT_BY_NAME, PowWinNT_IMAGE_IMPORT_BY_NAME, 0);
	__INITYP(PowWinNT_winnt_Union7, PowWinNT_winnt_Union7, 0);
	__INITYP(PowWinNT_IMAGE_THUNK_DATA, PowWinNT_IMAGE_THUNK_DATA, 0);
	__INITYP(PowWinNT_winnt_Union8, PowWinNT_winnt_Union8, 0);
	__INITYP(PowWinNT_IMAGE_IMPORT_DESCRIPTOR, PowWinNT_IMAGE_IMPORT_DESCRIPTOR, 0);
	__INITYP(PowWinNT_IMAGE_BOUND_IMPORT_DESCRIPTOR, PowWinNT_IMAGE_BOUND_IMPORT_DESCRIPTOR, 0);
	__INITYP(PowWinNT_IMAGE_BOUND_FORWARDER_REF, PowWinNT_IMAGE_BOUND_FORWARDER_REF, 0);
	__INITYP(PowWinNT_IMAGE_TLS_DIRECTORY, PowWinNT_IMAGE_TLS_DIRECTORY, 0);
	__INITYP(PowWinNT_IMAGE_RESOURCE_DIRECTORY, PowWinNT_IMAGE_RESOURCE_DIRECTORY, 0);
	__INITYP(PowWinNT_winnt_Struct9, PowWinNT_winnt_Struct9, 0);
	__INITYP(PowWinNT_winnt_Union9, PowWinNT_winnt_Union9, 0);
	__INITYP(PowWinNT_winnt_Union10, PowWinNT_winnt_Union10, 0);
	__INITYP(PowWinNT_IMAGE_RESOURCE_DIRECTORY_ENTRY, PowWinNT_IMAGE_RESOURCE_DIRECTORY_ENTRY, 0);
	__INITYP(PowWinNT_IMAGE_RESOURCE_DIRECTORY_STRING, PowWinNT_IMAGE_RESOURCE_DIRECTORY_STRING, 0);
	__INITYP(PowWinNT_IMAGE_RESOURCE_DIR_STRING_U, PowWinNT_IMAGE_RESOURCE_DIR_STRING_U, 0);
	__INITYP(PowWinNT_IMAGE_RESOURCE_DATA_ENTRY, PowWinNT_IMAGE_RESOURCE_DATA_ENTRY, 0);
	__INITYP(PowWinNT_IMAGE_LOAD_CONFIG_DIRECTORY, PowWinNT_IMAGE_LOAD_CONFIG_DIRECTORY, 0);
	__INITYP(PowWinNT_IMAGE_RUNTIME_FUNCTION_ENTRY, PowWinNT_IMAGE_RUNTIME_FUNCTION_ENTRY, 0);
	__INITYP(PowWinNT_IMAGE_DEBUG_DIRECTORY, PowWinNT_IMAGE_DEBUG_DIRECTORY, 0);
	__INITYP(PowWinNT_IMAGE_COFF_SYMBOLS_HEADER, PowWinNT_IMAGE_COFF_SYMBOLS_HEADER, 0);
	__INITYP(PowWinNT_FPO_DATA, PowWinNT_FPO_DATA, 0);
	__INITYP(PowWinNT_IMAGE_DEBUG_MISC, PowWinNT_IMAGE_DEBUG_MISC, 0);
	__INITYP(PowWinNT_IMAGE_FUNCTION_ENTRY, PowWinNT_IMAGE_FUNCTION_ENTRY, 0);
	__INITYP(PowWinNT_IMAGE_SEPARATE_DEBUG_HEADER, PowWinNT_IMAGE_SEPARATE_DEBUG_HEADER, 0);
	__INITYP(PowWinNT_MESSAGE_RESOURCE_ENTRY, PowWinNT_MESSAGE_RESOURCE_ENTRY, 0);
	__INITYP(PowWinNT_MESSAGE_RESOURCE_BLOCK, PowWinNT_MESSAGE_RESOURCE_BLOCK, 0);
	__INITYP(PowWinNT_MESSAGE_RESOURCE_DATA, PowWinNT_MESSAGE_RESOURCE_DATA, 0);
	__INITYP(PowWinNT_RTL_CRITICAL_SECTION, PowWinNT_RTL_CRITICAL_SECTION, 0);
	__INITYP(PowWinNT_RTL_CRITICAL_SECTION_DEBUG, PowWinNT_RTL_CRITICAL_SECTION_DEBUG, 0);
	__INITYP(PowWinNT_EVENTLOGRECORD, PowWinNT_EVENTLOGRECORD, 0);
	__INITYP(PowWinNT_TAPE_ERASE, PowWinNT_TAPE_ERASE, 0);
	__INITYP(PowWinNT_TAPE_PREPARE, PowWinNT_TAPE_PREPARE, 0);
	__INITYP(PowWinNT_TAPE_WRITE_MARKS, PowWinNT_TAPE_WRITE_MARKS, 0);
	__INITYP(PowWinNT_TAPE_GET_POSITION, PowWinNT_TAPE_GET_POSITION, 0);
	__INITYP(PowWinNT_TAPE_SET_POSITION, PowWinNT_TAPE_SET_POSITION, 0);
	__INITYP(PowWinNT_TAPE_GET_DRIVE_PARAMETERS, PowWinNT_TAPE_GET_DRIVE_PARAMETERS, 0);
	__INITYP(PowWinNT_TAPE_SET_DRIVE_PARAMETERS, PowWinNT_TAPE_SET_DRIVE_PARAMETERS, 0);
	__INITYP(PowWinNT_TAPE_GET_MEDIA_PARAMETERS, PowWinNT_TAPE_GET_MEDIA_PARAMETERS, 0);
	__INITYP(PowWinNT_TAPE_SET_MEDIA_PARAMETERS, PowWinNT_TAPE_SET_MEDIA_PARAMETERS, 0);
	__INITYP(PowWinNT_TAPE_CREATE_PARTITION, PowWinNT_TAPE_CREATE_PARTITION, 0);
/* BEGIN */
	__ENDMOD;
}

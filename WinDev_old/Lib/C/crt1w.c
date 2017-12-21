#include "SYSTEM_Cfg.h"

#define SW_SHOWDEFAULT 10
__declspec(dllimport) void __stdcall exit (int);
__declspec(dllimport) void __stdcall ExitProcess (int);
__declspec(dllimport) void* __stdcall GetModuleHandleA (char*);
__declspec(dllimport) char* __stdcall GetCommandLineA (void);
int __stdcall WinMain (void*, void*, char*, int);

/*
 * For now the GUI startup function is the same as the console one.
 * This simply gets rid of the annoying warning about not being able
 * to find WinMainCRTStartup when linking GUI applications.
 */
void _WinMain (void) {
#ifdef SYSTEM_Cfg_KERNEL32
  ExitProcess(
#else //SYSTEM_Cfg_MSVCRT
  exit(
#endif
    WinMain(
      GetModuleHandleA((char*)0), // hlnstance
      (void*)0,                   // hPrevInstance
      GetCommandLineA(),          // lpCmdLine
      SW_SHOWDEFAULT              // CmdShow
    )
  );
} //_WinMain

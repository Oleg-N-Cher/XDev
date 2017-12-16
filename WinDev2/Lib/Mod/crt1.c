#include "SYSTEM_Cfg.h"

__declspec(dllimport) void __stdcall ExitProcess (int);
__declspec(dllimport) void exit (int);
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
    WinMain((void*)0, (void*)0, (char*)0, 0)
  );
} //_WinMain

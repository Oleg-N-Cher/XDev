/*----------------------------------------*/
/* ZX Spectrum 128k memory access library */
/* Loading files from tape & TR-DOS disk  */
/*       VEDAsoft Oberon Club, 2019       */
/*----------------------------------------*/

#ifndef Mem128__h
#define Mem128__h

extern unsigned int Mem128_filesize;

unsigned char Mem128_IsTRDOS (void) __preserves_regs(b,c,iyl,iyh);
unsigned char Mem128_LoadDisk (unsigned char *name_ext, unsigned int adr) __z88dk_callee;
unsigned char Mem128_LoadTape (unsigned char *name, unsigned int adr) __z88dk_callee;
void Mem128_Page (unsigned char n) __z88dk_fastcall __preserves_regs(d,e,h,iyl,iyh);
void Mem128_SaveDisk (unsigned char *name_ext, unsigned int adr, unsigned int size) __z88dk_callee;
void Mem128_SaveTape (unsigned char *name, unsigned int adr, unsigned int size) __z88dk_callee;

#define Mem128__init()

#endif

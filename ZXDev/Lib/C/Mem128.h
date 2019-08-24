/*----------------------------------------*/
/* ZX Spectrum 128k memory access library */
/*       VEDAsoft Oberon Club, 2019       */
/*----------------------------------------*/

#ifndef Mem128__h
#define Mem128__h

unsigned char Mem128_IsTRDOS (void) __preserves_regs(b,c,d,e,iyl,iyh);
unsigned char Mem128_LoadDisk (unsigned char *filename, unsigned int adr) __z88dk_callee;
unsigned char Mem128_LoadTape (unsigned int adr) __z88dk_fastcall;
void Mem128_Page (unsigned char n) __z88dk_fastcall __preserves_regs(d,e,h,iyl,iyh);

#define Mem128__init()

#endif

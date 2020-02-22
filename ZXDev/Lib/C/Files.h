/*----------------------------------------*/
/* Load/Save files on tape & TR-DOS disk */
/*      VEDAsoft Oberon Club, 2019       */
/*---------------------------------------*/

#ifndef Files__h
#define Files__h

extern unsigned int Files_filesize;

extern unsigned char Files_LoadDisk (unsigned char *name_ext, unsigned int adr) __z88dk_callee;
extern unsigned char Files_LoadTape (unsigned char *name, unsigned int adr) __z88dk_callee;
extern void Files_SaveDisk (unsigned char *name_ext, unsigned int adr, unsigned int size) __z88dk_callee;
extern void Files_SaveTape (unsigned char *name, unsigned int adr, unsigned int size) __z88dk_callee;

#define Files__init()

#endif

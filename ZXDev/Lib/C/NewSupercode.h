#ifndef NewSupercode__h
#define NewSupercode__h

extern void NewSupercode__2WIERSZE (unsigned int adr);
extern void NewSupercode_EKRAN1 (unsigned int adr);
extern void NewSupercode_EKRAN2 (unsigned int adr);
extern void NewSupercode_EKRAN3 (unsigned int adr);
extern void NewSupercode_EKRAN4 (unsigned int adr);
extern void NewSupercode_SIATKA (unsigned char x, unsigned char y, unsigned int ramtop);
extern void NewSupercode_DZWIEK_1 (void);
extern void NewSupercode_DZWIEK_2 (void);
extern void NewSupercode_DZWIEK_3 (void);
extern void NewSupercode_EKRAN_1 (unsigned char x);
extern void NewSupercode_EKRAN_2 (unsigned char x);
extern void NewSupercode_LITERY_ (unsigned char x, unsigned char y, unsigned char xs,
  unsigned char ys, unsigned char wdth, unsigned char *str);
#define NewSupercode_LITERY(x, y, xs, ys, wdth, str, str__len) NewSupercode_LITERY_ (x, y, xs, ys, wdth, str)
extern void NewSupercode_LDIR (unsigned int to, unsigned int from, unsigned int len) __z88dk_callee __preserves_regs(a,iyl,iyh);
#define NewSupercode__init()

#endif

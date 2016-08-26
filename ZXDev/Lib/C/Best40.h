#ifndef Best40__h
#define Best40__h

#include "SYSTEM.h"

extern unsigned char Best40_attrib;

extern void Best40_ASRL_LF_A (void);
#define Best40_ASRL_LF(attrib) Best40_attrib = attrib; Best40_ASRL_LF_A()
extern void Best40_ASRL_RG_A (void);
#define Best40_ASRL_RG(attrib) Best40_attrib = attrib; Best40_ASRL_RG_A()
extern void Best40_ASRL_UP_A (void);
#define Best40_ASRL_UP(attrib) Best40_attrib = attrib; Best40_ASRL_UP_A()
extern void Best40_ASRL_DN_A (void);
#define Best40_ASRL_DN(attrib) Best40_attrib = attrib; Best40_ASRL_DN_A()
extern void Best40_SSRL_LF (void);
extern void Best40_SSRL_RG (void);
extern void Best40_SSRL_UP (void);
extern void Best40_SSRL_DN (void);
extern void Best40_PSRL_LF (void);
extern void Best40_PSRL_RG (void);
extern void Best40_PSRL_UP (void);
extern void Best40_PSRL_DN (void);
extern void Best40_SCR_MRG (SYSTEM_ADDRESS scr_addr);
extern void Best40_SCR_INV (void);
extern void Best40_SINV_UD (SYSTEM_ADDRESS char_addr);
extern void Best40_SINV_LR (SYSTEM_ADDRESS char_addr);
extern void Best40_SROTATE (SYSTEM_ADDRESS char_addr);
extern void Best40_ACHANGE (unsigned char attr_and, unsigned char attr_or);
extern void Best40_AREPLC (unsigned char attr_from, unsigned char attr_to);
extern void Best40_PAINT (unsigned char x, unsigned char y);
extern BOOLEAN Best40_POINT (unsigned char x, unsigned char y);
extern void Best40_PFIGURE_E (unsigned char x, unsigned char y, CHAR *pattern);
#define Best40_PFIGURE(x,y,pattern,len) Best40_PFIGURE_E(x,y,pattern)
extern void Best40_PSCALER (unsigned char x1_old, unsigned char y1_old,
  unsigned char x2_old, unsigned char y2_old, unsigned char xscale,
  unsigned char yscale, unsigned char x_new, unsigned char y_new);
extern void Best40_PUTSPR (
  unsigned char x, unsigned char y, unsigned char len, unsigned char hgt,
  unsigned int adr, unsigned char mode);
void Best40_SCREEN_APART (unsigned char steps);

#define Best40__init()

#endif

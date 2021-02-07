/* Version for DOS/CGA */
extern void GrApp__init (void);
extern void GrApp_Close (void);
extern void GrApp_PutSpr (unsigned int x, unsigned int y, void *spr);
extern void GrApp_SetBkColor (unsigned int color);
extern void GrApp_SetPalette (unsigned char pal);

/*================================== Header ==================================*/
void GrApp_SetPalette (unsigned char pal) {
/* 0 - Background, Green, Red, and Brown/Yellow; */
/* 1 - Background, Cyan, Magenta, and White.     */
  asm    MOV  BL, pal
  asm    MOV  BH, 1
  asm    MOV  AH, 0BH
  asm    INT  10H
} /*GrApp_SetPalette*/

/*--------------------------------- Cut here ---------------------------------*/
void GrApp_SetBkColor (unsigned int color) {
  asm    MOV  BL, byte ptr color
  asm    XOR  BH, BH
  asm    MOV  AH, 0BH
  asm    INT  10H
} /*GrApp_SetBkColor*/

/*--------------------------------- Cut here ---------------------------------*/
void GrApp_DrawLine (void) {

} /*GrApp_DrawLine*/

void GrApp_PutSpr (unsigned int x, unsigned int y, void *spr) {
/* Draw CGA sprite */
  asm       MOV  BX, x
  asm       MOV  CL, BL
  asm       AND  CL, 3
  asm       SHL  CL, 1      /* CL - число бит для сдвига */
  asm       MOV  AX, y
  asm       XCHG AH, AL
  asm       SHR  AX, 1
  asm       ADD  BH, AL
  asm       XOR  AL, AL
  asm       ADD  BX, AX
  asm       SHR  AX, 1
  asm       SHR  AX, 1
  asm       ADD  BX, AX
  asm       SHR  BX, 1
  asm       SHR  BX, 1      /* BX - смещение байта */
  asm       MOV  AX, 0B800H
  asm       MOV  ES, AX     /* ES:BX = screen address */
  asm       MOV  SI, spr    /* DS:SI = sprite address */
  asm       CLD
  asm       LODSW           /* len */
  asm       XCHG DX, AX     /* DL = len; DH = hgt */
  asm       MOV  DI, BX
  asm       CMP  BH, 20H
  asm       JNC  ODD
      EVEN:
  asm       CALL @DRAWLINE  /* Draw even line */
  asm       JZ   EXIT
  asm       ADD  DI, 2000H
      ODD:
  asm       CALL @DRAWLINE  /* Draw odd line */
  asm       JZ   EXIT
  asm       SUB  DI, 1FB0H
  asm       JMP  SHORT EVEN
  asm @DRAWLINE:
  asm       PUSH DI
  asm       PUSH DX
  asm       LODSB
  asm       MOV  BL, AL
  asm       SHR  BL, CL     /* 011100.10 => XX.011100 */
  asm       OR   ES:[DI], BL
  asm       INC  DI
  asm       DEC  DL
  asm       JZ   DRAWLAST
      DRAWBYTE:
  asm       MOV  AH, AL
  asm       LODSB
  asm       MOV  BX, AX
  asm       SHR  BX, CL     /* 011100.10 11111111 => 10.111111 */
  asm       OR   ES:[DI], BL
  asm       INC  DI
  asm       DEC  DL
  asm       JNZ  DRAWBYTE
      DRAWLAST:
  asm       MOV  AH, AL
  asm       XOR  AL, AL
  asm       CMP  AL, CL
  asm       JZ   ZEROLAST
  asm       SHR  AX, CL     /* 111111.11 => 10.111111 */
  asm       OR   ES:[DI], AL
      ZEROLAST:
  asm       POP  DX
  asm       POP  DI
  asm       DEC  DH
  asm       RET
      EXIT:;
} /*GrApp_PutSpr*/


/*--------------------------------- Cut here ---------------------------------*/
#include <XDevCfg.h>

void GrApp_Close (void) { /* Text mode 80x25x16 colors */
#  ifdef GrApp_WaitAtExit
     asm   XOR  AH, AH
     asm   INT  16H
#  endif
  asm   MOV  AX, 3H
  asm   INT  10H
} /*GrApp_Close*/

/*--------------------------------- Cut here ---------------------------------*/
void GrApp__init (void) { /* Graphic mode 320x200x4 colors */
  asm    INT 0x11
  if ((_AX & 0x30) == 0x30) exit(100); /* No hardware for CGA graphics. */
  asm    MOV  AX, 4H
  asm    INT  10H
} /*GrApp__init*/

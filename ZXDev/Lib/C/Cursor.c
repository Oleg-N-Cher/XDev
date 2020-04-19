extern void Cursor_Draw (unsigned char x, unsigned char y) __z88dk_callee;
extern void Cursor_Init (void *shape) __z88dk_fastcall;
extern void Cursor_Hide (void);
extern unsigned char Cursor_GetControl (void);
extern void Cursor_ResetSpeedUp (void);
extern void Cursor_ResetMouseOrigin (void);

// =====  DRIVER FOR CURSOR & CONTROLS  =====
//
// This driver provides functions for drawing
// a cursor like an arrow and for moving it.
// The cursor is a sprite of 9 columns (0..8)
// and from 1 to 16 lines of pixels. The mask
// for the cursor is defined the same way.
// The cursor may be moved with keys OPQA,
// Sinclair, Kempston joysticks and Kempston
// Mouse. All controls operate at the same
// time (no selection is needed).
// The driver functions may be called in two
// ways: a. using function number (slower but
// no need to recompile an application if the
// driver code changes), b. by a direct call.
//
// #0: INIT CURSOR (set cursor shape).
// IN  Only internal images are prepared,
//     nothing is displayed on the screen.
//     IN: BC=scr_ad, DE=curs_ad
//       scr_ad points to table of 192 words
//       that are addrs of scanlines in VRAM.
//       curs_ad points to structure:
//       byte 0: Cursor height, h (1..16)
//       byte 1: Active point X (0..8)
//       byte 2: Active point Y (0..h-1)
//       byte 3: Bits 0 to 7 respectively
//         define bits 0(top)..7  of the
//         rightmost column of cursor shape
//       byte 4: Bits 0 to 7 respectively
//         define bits 8..15 of the
//         rightmost column of cursor shape
//         (byte 4 is ignored if h <= 8)
//       bytes 5..4+h: Cursor shape. Each
//         byte defines 1 line top to bottom
//       Then the mask follows in the same
//       format as cursor shape (byte 3..4+h)
//     USES: AF, BC, DE, HL, 2 stack words
//     CLKS: select + 10322 + 1075*height
//
// #1: DRAW CURSOR (also saves background).
// DR  IN:   B=y(0..191), C=x
//     USES: AF, BC, DE, HL, IX, 1 stack word
//     CLKS: select + 405 + 239*height
//
// #2: HIDE CURSOR (restore background).
// HD  Takes coords from last call to 01.
//     USES: AF, BC, DE, HL, IX
//     POST: B=0, C=px_x, Z=0
//     CLKS: select + 290 + 142*height
//
// #3: GET CONTROL BYTE for current keys.
// GC  OUT:  A=control_byte (see bits below).
//       Bit format is equal to Kempston J.:
//       0: Right (P, CS/8, 7, Kempston J.)
//       1: Left  (O, CS/5, 6, Kempston J.)
//       2: Down  (A, CS/6, 8, Kempston J.)
//       3: Up    (Q, CS/7, 9, Kempston J.)
//       4: Fire  (M, SP,   0, Kempston J.)
//       5-7 are reset to 0.
//     USES: AF, BC, D, HL
//     CLKS: select + 399
//
// 04: ADJUST COORDS with current controls.
// AC  Same controls as in 03 are considered,
//     but also Kempston Mouse is inquired.
//     Uses params set by 05, 06, 07 & 08.
//     IN:   B=y, C=x
//     OUT:  B=new_y, C=new_x, Z=nch, CY=fire
//       nch=1 means coords were not changed.
//       fire=1 if fire (J. or key) or any of
//       mouse buttons is pressed.
//     USES: AF, BC, DE, HL, 2 stack words
//     CLKS: select + 2214
//
// 05: GET/SET CONSTRAINTS for 04.
// CO  Coords won't be let to violate range.
//     IN: CY=0 for GET and CY=1 for SET.
//     IO: B=min_y, C=min_x, D=max_y, E=max_x
//     USES: AF, BC, DE, HL
//     CLKS: select + ( CY=0 ? 69 : 144 )
//
// 06: GET/SET SENSITIVITY for 04.
// SE  IN: CY=0 for GET and CY=1 for SET.
//     IO: B=mouse_s, D=max_delta, E=speedup
//       More is mouse_s (0..14), slower
//       the cursor is moved with the mouse
//       (real mouse coords from ports are
//       divided by 2^mouse_s).
//       speedup (0..127) is # of steps of
//       holding the same control keys or J.
//       after which delta for coords is
//       increased by 1 (but no more than
//       max_delta which is 1..127).
//     USES: AF, B, DE, HL
//     CLKS: select + ( CY=0 ? 54 : 182 )
//
// 07: RESET SPEEDUP for 04.
// SP  Reset speedup counter & delta.
//     USES: AF, HL
//     CLKS: select + 49
//
// 08: RESET MOUSE ORIGIN for 04.
// MO  Set mouse origin to current mouse pos.
//     Use before the cursor first appears.
//     USES: AF, HL
//     CLKS: select + 80
//
//  Mike & Helen Shevchenko,  Moscow,  2002

/*================================== Header ==================================*/

unsigned char CURSPH [512]; // Mask/Cursor phases mix
unsigned char CURS_B [256]; // Background

/*--------------------------------- Cut here ---------------------------------*/
// Black arrow (Mac style)
const unsigned char Cursor_Std [39] = { 16, 1, 1, // Height, ActiveX, ActiveY
       0b00000000, 0b00000000, // Bits of rightmost column of cursor shape
       0b00000000,             // Shape
       0b01000000,
       0b01100000,
       0b01110000,
       0b01111000,
       0b01111100,
       0b01111110,
       0b01111111,
       0b01111100,
       0b01001100,
       0b00001100,
       0b00000110,
       0b00000110,
       0b00000011,
       0b00000011,
       0b00000000,
       0b01111111, 0b10011110, // Bits of rightmost column of cursor mask
       0b00111111,             // Mask
       0b00011111,
       0b00001111,
       0b00000111,
       0b00000011,
       0b00000001,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000001,
       0b00100001,
       0b11110000,
       0b11110000,
       0b11111000,
       0b11111000,
       0b11111100
};

/*--------------------------------- Cut here ---------------------------------*/
void __variables (void) __naked {
__asm
.globl SCR_AD
.globl CURSAX
.globl CURSAY
.globl CURS_H
.globl CURSXY
       ; Driver state & parameter variables
CURS_H: .DB  16; Cursor height
CURSAX: .DB   0; Cursor active X
CURSAY: .DB   0; Cursor active Y
CURSXY: .DW   0; XY for background
SCR_AD:
       .DW 16384,16640,16896,17152,17408,17664,17920,18176
       .DW 16416,16672,16928,17184,17440,17696,17952,18208
       .DW 16448,16704,16960,17216,17472,17728,17984,18240
       .DW 16480,16736,16992,17248,17504,17760,18016,18272
       .DW 16512,16768,17024,17280,17536,17792,18048,18304
       .DW 16544,16800,17056,17312,17568,17824,18080,18336
       .DW 16576,16832,17088,17344,17600,17856,18112,18368
       .DW 16608,16864,17120,17376,17632,17888,18144,18400
       .DW 18432,18688,18944,19200,19456,19712,19968,20224
       .DW 18464,18720,18976,19232,19488,19744,20000,20256
       .DW 18496,18752,19008,19264,19520,19776,20032,20288
       .DW 18528,18784,19040,19296,19552,19808,20064,20320
       .DW 18560,18816,19072,19328,19584,19840,20096,20352
       .DW 18592,18848,19104,19360,19616,19872,20128,20384
       .DW 18624,18880,19136,19392,19648,19904,20160,20416
       .DW 18656,18912,19168,19424,19680,19936,20192,20448
       .DW 20480,20736,20992,21248,21504,21760,22016,22272
       .DW 20512,20768,21024,21280,21536,21792,22048,22304
       .DW 20544,20800,21056,21312,21568,21824,22080,22336
       .DW 20576,20832,21088,21344,21600,21856,22112,22368
       .DW 20608,20864,21120,21376,21632,21888,22144,22400
       .DW 20640,20896,21152,21408,21664,21920,22176,22432
       .DW 20672,20928,21184,21440,21696,21952,22208,22464
       .DW 20704,20960,21216,21472,21728,21984,22240,22496
CURSKS: .DB  16; steps for speedup for 04
CURSMD: .DB   5; Max delta per step for 04
CURSSN: .DB   1; Mouse sensivity
CURSLC: .DB   0; Last control byte
CURSSC: .DB   0; Cursor speedup counter
CURSSD: .DB   1; Delta for moving with keys
CURSLX: .DB   0; Mouse last X
CURSMX: .DB   0; Mouse X subpixel correction
CURSLY: .DB   0; Mouse last Y
CURSMY: .DB   0; Mouse Y subpixel correction
CURSX1: .DB   0; Min X coord for 04
CURSX2: .DB 255; Max X coord for 04
CURSY1: .DB   0; Min Y coord for 04
CURSY2: .DB 191; Max Y coord for 04
__endasm;
} //__variables

/*--------------------------------- Cut here ---------------------------------*/
void Cursor_Init (void *shape) __naked __z88dk_fastcall {
  __asm                  ; #0: INIT CURSOR (set cursor shape).
       LD   A,(HL); A=height
       INC  HL
       LD   D,H
       LD   E,L
       LD   C,(HL)
       INC  HL
       LD   B,(HL)
       INC  HL
       LD   (CURSAX),BC; (CURSAY)=B
       LD   C,(HL)
       INC  HL
       LD   B,(HL)
       INC  HL
       LD   (CURD00),BC
       CP   #1
       JR   NC,.+3
       INC  A
       JR   C,.+3
       NOP; Waste
       CP   #17
       JR   C,.+4
       LD   A,#16
       JR   NC,.+4
       CP   #0; Waste
       LD   C,A
       LD   B,#0
       ADD  HL,BC
       LD   C,(HL)
       INC  HL
       LD   B,(HL)
       INC  HL; HL -> mask
       LD   (CURM00),BC
       INC  DE
       INC  DE
       INC  DE
       INC  DE; DE -> cursor
       LD   BC,#_CURSPH
       LD   (CURS_H),A
       LD   (CURC00),A
CUR100:LD   A,(HL)
       INC  HL
       LD   (BC),A
       INC  BC
       LD   A,(DE)
       INC  DE
       LD   (BC),A
       INC  BC
       PUSH HL
       LD   A,#0xFF
       LD   HL,(CURM00)
       SRL  H
       RR   L
       LD   (CURM00),HL
       RRA
       LD   (BC),A
       INC  BC
       XOR  A
       LD   HL,(CURD00)
       SRL  H
       RR   L
       LD   (CURD00),HL
       RRA
       LD   (BC),A
       INC  BC
       POP  HL
       LD   A,(CURC00)
       DEC  A
       LD   (CURC00),A
       JR   NZ,CUR100

       LD   A,#7;phase#
       LD   HL,#_CURSPH
       LD   DE,#_CURSPH+64
CUR200:LD   BC,#64
       LDIR
       PUSH HL
       PUSH DE
       LD   BC,(CURS_H-1); B=Waste
CUR300:SCF
       RR   (HL)
       INC  HL
       INC  HL
       RR   (HL)
       DEC  HL
       OR   A; CF=0
       RR   (HL)
       INC  HL
       INC  HL
       RR   (HL)
       INC  HL
       DJNZ CUR300
       POP  DE
       POP  HL
       DEC  A
       JR   NZ,CUR200
       RET
CURC00:.DB 0
CURD00:.DW 0; 8th column for shape
CURM00:.DW 0; 8th column for mask
  __endasm;
} //Cursor_Init

/*--------------------------------- Cut here ---------------------------------*/
void Cursor_Draw (unsigned char x, unsigned char y) __naked __z88dk_callee {
__asm                    ; #1: DRAW CURSOR (also saves background).
       POP  HL
       EX   (SP),HL      ; H=y(0..191), L=x
       LD   (CURSXY),HL  ;=16
       LD   B,H          ;= 4
       LD   A,L          ;= 4
       LD   HL,#CURSAX   ;=10
       SUB  (HL)         ;= 7
       RRA               ;= 4
       RRA               ;= 4
       RRA               ;= 4
       LD   C,A          ;= 4
       LD   D,#0         ;= 7
       RL   D            ;= 8
       AND  #0b11000000  ;= 7
       LD   E,A          ;= 4
       LD   HL,#_CURSPH  ;=10
       ADD  HL,DE        ;=11
       LD   A,(CURS_H)
       LD   E,A
       LD   A,(CURSAY)
       LD   D,A
       LD   A,B
       SUB  D
       LD   B,A
       PUSH IX
       JP   NC,CUR801
CUR901:DEC  E
       INC  HL
       INC  HL
       INC  HL
       INC  HL
       LD   A,#13; Waste
       DEC  A; Waste
       JP   NZ,.-1; Waste
       NOP; Waste
       NOP; Waste
       INC  B
       JP   NZ,CUR901
CUR801:LD   A,E
       PUSH HL           ;=11
       LD   D,#0         ;= 7
       LD   E,B          ;= 4
       SLA  E            ;= 8
       RL   D            ;= 8
       LD   HL,#SCR_AD   ;=10
       ADD  HL,DE        ;=11
       LD   IX,#CURC01   ;=14
       LD   D,A          ;= 4
       LD   0(IX),A      ;=19
       LD   A,#193       ;= 7
       SUB  D            ;= 4
       LD   D,A          ;= 4
       LD   A,B          ;= 4
CURW01:CP   D            ;= 4
       JP   C,CURF01     ;=10
       DEC  A            ;= 4
       DEC  0(IX)        ;=23
       JP   .+3;Waste    ;=10
       JP   C, CURRET+1
       LD   B,#13; Waste ;= 7
       DJNZ .; Waste     ;=13*12+8
       JR   CURW01       ;=12

CURF01:LD   DE,#_CURS_B  ;=10
       BIT  5,C          ;= 8
       JP   NZ,CUR601    ;=10
       LD   A,C          ;= 4
       AND  #0b00011111  ;= 7
       CP   #31          ;= 7
       JP   Z,CUR301     ;=10
       LD   (CUR201+1),A ;=13
CUR101:LD   C,(HL)       ;= 7
       INC  HL           ;= 6
       LD   B,(HL)       ;= 7
       INC  HL           ;= 6
       EX   (SP),HL      ;=19
CUR201:LD   A,#0; SMC    ;= 7
       ADD  A,C          ;= 4
       LD   C,A          ;= 4
       LD   A,B          ;= 4
       ADC  A,#0         ;= 7
       LD   B,A          ;= 4
       LD   A,(BC)       ;= 7
       LD   (DE),A       ;= 7
       INC  DE           ;= 6
       AND  (HL)         ;= 7
       INC  HL           ;= 6
       OR   (HL)         ;= 7
       INC  HL           ;= 6
       LD   (BC),A       ;= 7
       INC  BC           ;= 6
       LD   A,(BC)       ;= 7
       LD   (DE),A       ;= 7
       INC  DE           ;= 6
       AND  (HL)         ;= 7
       INC  HL           ;= 6
       OR   (HL)         ;= 7
       INC  HL           ;= 6
       LD   (BC),A       ;= 7
       EX   (SP),HL      ;=19
       DEC  0(IX)        ;=23
       JP   NZ,CUR101    ;=10
       JR   CURRET
CUR301:LD   (CUR501+1),A ;=13
CUR401:LD   C,(HL)       ;= 7
       INC  HL           ;= 6
       LD   B,(HL)       ;= 7
       INC  HL           ;= 6
       EX   (SP),HL      ;=19
CUR501:LD   A,#0; SMC    ;= 7
       ADD  A,C          ;= 4
       LD   C,A          ;= 4
       LD   A,B          ;= 4
       ADC  A,#0         ;= 7
       LD   B,A          ;= 4
       LD   A,(BC)       ;= 7
       LD   (DE),A       ;= 7
       INC  DE           ;= 6
       AND  (HL)         ;= 7
       INC  HL           ;= 6
       OR   (HL)         ;= 7
       INC  HL           ;= 6
       LD   (BC),A       ;= 7
       INC  BC           ;= 6
       LD   A,(BC)       ;= 7
       LD   (DE),A       ;= 7
       INC  DE           ;= 6
       AND  (HL)         ;= 7
       INC  HL           ;= 6
       OR   (HL)         ;= 7
       INC  HL           ;= 6
       LD   A,(BC); Waste;= 7
       EX   (SP),HL      ;=19
       DEC  0(IX)        ;=23
       JP   NZ,CUR401    ;=10
       JR   CURRET
CUR601:LD   B,#3; Waste
       DJNZ .; Waste
CUR701:LD   C,(HL)       ;= 7
       INC  HL           ;= 6
       LD   B,(HL)       ;= 7
       INC  HL           ;= 6
       EX   (SP),HL      ;=19
       INC  HL; Waste    ;= 6
       DEC  HL; Waste    ;= 6
       INC  HL; Waste    ;= 6
       DEC  HL; Waste    ;= 6
       INC  HL; Waste    ;= 6
       DEC  HL; Waste    ;= 6
       LD   A,(BC)       ;= 7
       LD   (DE),A       ;= 7
       INC  DE           ;= 6
       AND  (HL)         ;= 7
       INC  HL           ;= 6
       OR   (HL)         ;= 7
       INC  HL           ;= 6
       LD   A,(BC); Waste;= 7
       LD   A,(BC)       ;= 7
       LD   (DE),A       ;= 7
       INC  DE           ;= 6
       AND  (HL)         ;= 7
       INC  HL           ;= 6
       OR   (HL)         ;= 7
       INC  HL           ;= 6
       LD   (BC),A       ;= 7
       EX   (SP),HL      ;=19
       DEC  0(IX)        ;=23
       JP   NZ,CUR701    ;=10
CURRET:POP  HL           ;=10
       POP  IX
       RET               ;=10
CURC01:.DB  0
__endasm;
} //Cursor_Draw

/*--------------------------------- Cut here ---------------------------------*/
void Cursor_Hide (void) __naked {
  __asm                  ; #2: HIDE CURSOR (restore background).
       LD   BC,(CURSXY)  ;=20
       LD   A,(CURS_H)   ;=13
       LD   E,A
       LD   A,(CURSAY)
       LD   D,A
       LD   A,B
       SUB  D
       LD   B,A
       PUSH IX
       JP   NC,CUR502
CUR602:DEC  E
       LD   A,#8; Waste
       DEC  A; Waste
       JP   NZ,.-1; Waste
       JP   NZ, RETHID; Waste
       INC  B
       JP   NZ,CUR602
CUR502:LD   A,E
       LD   D,#0         ;= 7
       LD   E,B          ;= 4
       SLA  E            ;= 8
       RL   D            ;= 8
       LD   IX,#SCR_AD   ;=14
       ADD  IX,DE        ;=15
       LD   H,B          ;= 4
       LD   B,A          ;= 4
       LD   A,#192       ;= 7
       SUB  B            ;= 4
CURW02:CP   H            ;= 4
       JP   NC,CURF02    ;=10
       DEC  H            ;= 4
       DEC  B            ;= 4
       LD   D,B          ;= 4
       LD   B,#7;Waste   ;= 7
       DJNZ .; Waste     ;=13*6+8
       LD   B,#0;Waste   ;= 7
       LD   B,D          ;= 4
       JR   CURW02       ;=12
CURF02:LD   HL,#_CURS_B  ;=10
       LD   A,C          ;= 4
       LD   DE,(CURSAX); D=Waste; =20
       SUB  E            ;= 4
       JP   C,CUR302     ;=10
       SRL  A            ;= 8
       SRL  A            ;= 8
       SRL  A            ;= 8
       LD   C,A          ;= 4
       CP   #31          ;= 7
       JP   Z,CUR202     ;=10
CUR102:LD   E,0(IX)      ;=19
       INC  IX           ;=10
       LD   D,0(IX)      ;=19
       INC  IX           ;=10
       LD   A,C          ;= 4
       ADD  A,E          ;= 4
       LD   E,A          ;= 4
       LD   A,D          ;= 4
       ADC  A,#0         ;= 7
       LD   D,A          ;= 4
       LDI               ;=16
       INC  BC           ;= 6
       LDI               ;=16
       INC  BC           ;= 6
       DJNZ CUR102       ;=13/8
       JR   RETHID
CUR202:LD   E,0(IX)      ;=19
       INC  IX           ;=10
       LD   D,0(IX)      ;=19
       INC  IX           ;=10
       LD   A,C          ;= 4
       ADD  A,E          ;= 4
       LD   E,A          ;= 4
       LD   A,D          ;= 4
       ADC  A,#0         ;= 7
       LD   D,A          ;= 4
       LDI               ;=16
       INC  BC           ;= 6
       INC  HL           ;= 6
       LD   A,(DE); Waste;= 7
       LD   A,I; Waste   ;= 9
       DJNZ CUR202       ;=13/8
       JR   RETHID
CUR302:LD   A,#2; Waste
       DEC  A; Waste
       JP   NZ,.-1; Waste
       JP   NZ,RETHID; Waste
       JP   NZ,RETHID; Waste
CUR402:LD   DE,(CURSAX); Waste
       SCF; Waste
       JP   NC,RETHID; Waste
       LD   E,0(IX)      ;=19
       INC  IX           ;=10
       LD   D,0(IX)      ;=19
       INC  IX           ;=10
       LD   A,(HL)       ;= 7
       LD   A,(DE)       ;= 7
       INC  HL           ;= 6
       LDI               ;=16
       INC  BC           ;= 6
       DJNZ CUR402       ;=13/8
RETHID:POP  IX
       RET               ;=10
__endasm;
} //Cursor_Hide

/*--------------------------------- Cut here ---------------------------------*/
unsigned char Cursor_GetControl (void) {
  __asm                  ; #3: GET CONTROL BYTE for current keys.
;      H <- [sp | M | 0] Q A O P
       LD   BC,#0x7FFE; B N M ss sp
       IN   A,(C)
       LD   B,#0xEF; 6 7 8 9 0
       IN   L,(C)
       LD   H,A
       RRA
       RRA
       AND  H
       AND  L
       CPL
       AND  #1
       LD   H,A
       LD   B,#0xFB; Q W E R T
       IN   A,(C)
       CPL
       RRA
       RL   H
       LD   B,#0xFD; A S D F G
       IN   A,(C)
       CPL
       RRA
       RL   H
       LD   B,#0xDF; Y U I O P
       IN   A,(C)
       CPL
       AND  #3
       SLA  H
       SLA  H
       OR   H
       LD   H,A

       LD   D,#0
       LD   B,C; cs Z X C V
       IN   A,(C)
       RRA
       JP   NC,CUR103; If cs then Cursor J.

;      A <- 9 8 6 7
       LD   A,L; 6 7 8 9 0   ;= 4
       CPL                   ;= 4
       RRA                   ;= 4
       RRA                   ;= 4
       RL   D                ;= 8
       RRA                   ;= 4
       RL   D                ;= 8
       AND  #3               ;= 7
       SLA  D                ;= 8
       SLA  D                ;= 8
       OR   D                ;= 4
       ADD  HL,BC;     Waste ;=11
       OR   A; CY=0    Waste ;= 4
       CP   #0; CY=0   Waste ;= 7
       SBC  HL,BC;     Waste ;=15
       JR   CUR203           ;=12
;                           ==112==
CUR103:;A <- 7 6 5 8
       LD   A,L              ;= 4
       AND  #16; Key 6 (down);= 7
       CP   #1; CY = Z       ;= 7
       RL   D                ;= 8
       LD   B,#0xF7; 1 2 3 4 5 ;= 7
       IN   A,(C)            ;=12
       AND  #16; Key 5 (left);= 7
       CP   #1; CY = Z       ;= 7
       RL   D                ;= 8
       LD   A,L              ;= 4
       AND  #4; Key 8 (right);= 7
       CP   #1; CY = Z       ;= 7
       RL   D                ;= 8
       LD   A,L              ;= 4
       CPL                   ;= 4
       AND  #8; Key 7 (up)   ;= 7
       OR   D                ;= 4
;                           ==112==
CUR203:LD   D,A
       IN   A,(31); Kempston J.
       OR   H
       OR   D
       LD   L,A
  __endasm;
} //Cursor_GetControl

/*
CURS04; ADJUST COORDS
       PUSH BC; Last coords
       LD   A,#0xFB; Mouse X
       IN   A,(#0xDF)
       LD   HL,(CURSLX); H=Waste
       LD   (CURSLX),A
       SUB  L
       LD   H,A
       LD   L,0
       LD   A,#0xFF; Mouse Y
       IN   A,(#0xDF)
       NEG; Mouse 0,0 is bottom-left corner
       LD   DE,(CURSLY); D=Waste
       LD   (CURSLY),A
       SUB  E
       LD   D,A
       LD   E,0
       LD   A,(CURSSN)
       OR   A
       JP   Z,CUR204
CUR104 SRA  H
       RR   L
       SRA  D
       RR   E
       DEC  A
       JP   NZ,CUR104
CUR204 LD   A,(CURSSN)
       SUB  14
       NEG
       JP   Z,CUR404
CUR304 RL   H; Waste
       RR   H; Waste
       RL   D
       RR   D
       DEC  A
       JP   NZ,CUR304
CUR404 LD   A,(CURSMX)
       ADD  A,L
       LD   (CURSMX),A
       LD   A,H
       LD   H,0
       ADC  A,H
       JP   M,CUR504
       ADD  A,C              ;= 4
       LD   C,A              ;= 4
       DEC  H; H=255         ;= 4
       JR   CUR604           ;=12
CUR504 NEG                   ;= 8
       LD   L,A              ;= 4
       LD   A,C              ;= 4
       SUB  L                ;= 4
       LD   C,A              ;= 4
CUR604 JR   NC,.+3           ;=12/7
       LD   C,H              ;= 7
       JR   C,.+3            ;=12/7
       LD   A,0; Waste       ;= 7
       LD   A,(CURSMY)
       ADD  A,E
       LD   (CURSMY),A
       LD   A,D
       LD   D,0
       ADC  A,D
       JP   M,CUR704
       ADD  A,B              ;= 4
       LD   B,A              ;= 4
       DEC  D; D=255         ;= 4
       JR   CUR804           ;=12
CUR704 NEG                   ;= 8
       LD   E,A              ;= 4
       LD   A,B              ;= 4
       SUB  E                ;= 4
       LD   B,A              ;= 4
CUR804 JR   NC,.+3           ;=12/7
       LD   B,D              ;= 7
       JR   C,.+3            ;=12/7
       LD   A,0; Waste       ;= 7
       PUSH BC
       LD   A,#0xFA
       IN   A,(#0xDF)
       CPL
       LD   C,A
       RLA
       OR   C
       AND  2
       RLCA
       RLCA
       RLCA
       LD   E,A; E4=OR of mouse buttons
       CALL CURS03; A=control_byte
       OR   E
       POP  BC; BC=coords_after_mouse

;      Update CURSSC, CURSSD

       LD   HL,CURSLC
       LD   D,(HL)
       LD   (HL),A
       INC  HL; HL=CURSSC
       CP   D
       LD   D,A; D=control_byte
       LD   A,(CURSKS)
       JP   NZ,CURA04
       LD   A,(CURSKS); Waste;=13
       NOP;             Waste;= 4
       JP   CURB04
CURA04 LD   (HL),A           ;= 7
       LD   A,1              ;= 7
       LD   (CURSSD),A       ;=13
CURB04 LD   A,D; A=ctrl_byte
       OR   A
       JP   NZ,CURC04
       LD   A,5;       Waste ;= 7
       DEC  A;         Waste ;= 4
       JP   NZ,.-1;    Waste ;=10
       LD   A,(CURSSD)       ;=13
       JR   CURD04           ;=12
CURC04 DEC  (HL)             ;=11
       LD   A,(CURSKS)       ;=13
       JP   M,CURE04         ;=10
       LD   HL,CURSSD        ;=10
       LD   HL,CURSSD; Waste ;=10
       LD   A,0; Waste       ;= 7
       SCF                   ;= 4
       JR   CURF04           ;=12
CURE04 LD   (HL),A           ;=13
       INC  HL; HL=CURSSD    ;= 6
       LD   A,(CURSMD)       ;=13
       DEC  A                ;= 4
       CP   (HL)             ;= 7
CURF04 CCF                   ;= 4
       LD   A,(HL)           ;= 7
       ADC  A,0              ;= 7
       LD   (HL),A           ;= 7
CURD04 LD   E,A; E=(CURSSD)

;      Modify (in range) BC with A

       LD   A,C
       RR   D; CY=right
       JP   C,CURI04
       NOP;      Waste       ;= 4
       SCF;      Waste       ;= 4
       RET  NC;  Waste       ;= 5
       JP   CURJ04           ;=10
CURI04 ADD  A,E              ;= 4
       JR   NC,.+4           ;=12/7
       LD   A,255            ;= 7
       JR   C,.+4            ;=12/7
CURJ04 LD   C,0; Waste       ;= 7
       RR   D; CY=left
       JP   C,CURK04
       NOP;      Waste       ;= 4
       SCF;      Waste       ;= 4
       RET  NC;  Waste       ;= 5
       JP   CURL04           ;=10
CURK04 SUB  E                ;= 4
       JR   NC,.+3           ;=12/7
       XOR  A                ;= 4
       JR   C,.+3            ;=12/7
CURL04 NOP;      Waste       ;= 4

       LD   HL,(CURSX1); H=(CURSX2)
       CP   L
       JR   NC,.+3
       LD   A,L
       JR   C,.+3
       NOP; Waste
       CP   H
       JR   C,.+3
       LD   A,H
       JR   NC,.+3
       NOP; Waste
       LD   C,A

       LD   A,B
       RR   D; CY=down
       JP   C,CURM04
       NOP;      Waste       ;= 4
       SCF;      Waste       ;= 4
       RET  NC;  Waste       ;= 5
       JP   CURN04           ;=10
CURM04 ADD  A,E              ;= 4
       JR   NC,.+4           ;=12/7
       LD   A,255            ;= 7
       JR   C,.+4            ;=12/7
CURN04 LD   B,0; Waste       ;= 7
       RR   D; CY=up
       JP   C,CURO04
       NOP;      Waste       ;= 4
       SCF;      Waste       ;= 4
       RET  NC;  Waste       ;= 5
       JP   CURP04           ;=10
CURO04 SUB  E                ;= 4
       JR   NC,.+3           ;=12/7
       XOR  A                ;= 4
       JR   C,.+3            ;=12/7
CURP04 NOP;      Waste       ;= 4

       LD   HL,(CURSY1); H=(CURSY2)
       CP   L
       JR   NC,.+3
       LD   A,L
       JR   C,.+3
       NOP; Waste
       CP   H
       JR   C,.+3
       LD   A,H
       JR   NC,.+3
       NOP; Waste
       LD   B,A

       POP  HL;    HL=original coords
       AND  A;     CY=0
       SBC  HL,BC; Z=1 if coords not changed
       LD   HL,(CURSKS); H=Waste
       LD   H,1; Initial delta
       JP   Z,CURG04
       INC  HL; Waste
       JP   CURH04
CURG04 LD   (CURSSC),HL
CURH04 LD   A,D; To keep Z
       RRA; Set CY to fire
       RET



CURS05; GET/SET CONSTRAINTS
       JR   C,CUR105
       LD   BC,(CURSX1); B=(CURSX2)
       LD   DE,(CURSY1); D=(CURSY2)
       LD   A,B
       LD   B,E
       LD   E,A
       RET
CUR105 LD   A,D
       CP   B
       JR   NC,.+4
       LD   D,B
       LD   B,A
       JR   C,.+4
       NOP; Waste
       NOP; Waste
       LD   A,E
       CP   C
       JR   NC,.+4
       LD   E,C
       LD   C,A
       JR   C,.+4
       NOP; Waste
       NOP; Waste
       LD   A,B
       LD   B,E
       LD   E,A
       LD   (CURSX1),BC; (CURSX2)=B
       LD   (CURSY1),DE; (CURSY2)=E
       RET



CURS06; GET/SET SENSIVITY
       JR   C,CUR106
       LD   A,(CURSSN)
       LD   B,A
       LD   DE,(CURSKS); D=(CURSMD)
       RET
CUR106 LD   A,B
       CP   15
       JR   C,.+4
       LD   A,14
       JR   NC,.+4
       CP   0; Waste
       LD   (CURSSN),A
       LD   A,E
       OR   A
       JP   P,.+5
       LD   E,127
       JP   M,.+5
       NOP; Waste
       LD   A,D
       OR   A
       JR   NZ,.+3
       INC  D
       JR   Z,.+3
       NOP; Waste
       JP   P,.+5
       LD   D,127
       JP   M,.+5
       CP   0; Waste
       LD   (CURSKS),DE; (CURSMD)=D
       RET
*/

/*--------------------------------- Cut here ---------------------------------*/
void Cursor_ResetSpeedUp (void) {
  __asm                  ; #7: RESET SPEEDUP counter & delta for #4.
       LD   HL,(CURSKS)
       LD   H,#1
       LD   (CURSSC),HL; (CURSSD)=H
  __endasm;
} //Cursor_ResetSpeedUp

/*--------------------------------- Cut here ---------------------------------*/
void Cursor_ResetMouseOrigin (void) {
  __asm                  ; #8: RESET MOUSE ORIGIN for #4.
       LD   A,#0xFB; Mouse X
       IN   A,(#0xDF)
       LD   (CURSLX),A
       LD   A,#0xFF; Mouse Y
       IN   A,(#0xDF)
       NEG; Mouse 0,0 is bottom-left corner
       LD   (CURSLY),A
  __endasm;
} //Cursor_ResetMouseOrigin

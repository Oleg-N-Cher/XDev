/* Configuration file of the library Basic: */

/* Interrupt mode of your program: DI, IM1, IM2. */
/* For IM 1 mode use SDCC option --reserve-regs-iy */
//#define MODE_DI
#define MODE_IM1
//#define MODE_IM2

/* Use ROM output (RST 10H, slow, 32x22) or CUSTOM (fast, 32x24) */
#define ROM_OUTPUT

/* Use fastcall model (the function parameters passed in regs.)  */
/* Use fastcall _ONLY_ if a function's parameters are constants. */
//#define AT_fastcall
//#define BORDER_fastcall
//#define INK_fastcall
//#define PAPER_fastcall
//#define FLASH_fastcall
//#define BRIGHT_fastcall
//#define OVER_fastcall
//#define INVERSE_fastcall
//#define PAUSE_fastcall
//#define PRSTR_fastcall

/* Use CLS for whole screen (with PAPER attributes in bottom lines): */
//#define CLS_FULLSCREEN


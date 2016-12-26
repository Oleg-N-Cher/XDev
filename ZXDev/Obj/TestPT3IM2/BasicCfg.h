/* Configuration file of the library Basic: */

/* Interrupt mode of your program: DI, IM1, IM2. */
/* For IM 1 mode use SDCC option --reserve-regs-iy */
//#define MODE_DI
//#define MODE_IM1
#define MODE_IM2

/* Use ROM output (RST 10H, slow, 32x22) or CUSTOM (fast, 32x24) */
#define ROM_OUTPUT

/* Use fastcall model (the function parameters passed in regs.)  */

//#define AT_fastcall
//#define ATTR_fastcall
//#define BORDER_inline
//#define DRAW_fastcall
//#define PLOT_fastcall
//#define POINT_fastcall
//#define PRSTR_fastcall

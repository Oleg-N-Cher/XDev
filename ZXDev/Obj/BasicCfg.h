/* Configuration file of the library Basic */

/* RND() result type: SHORTCARD (0..255) or CARDINAL (0..65535). */

//#define RND_SHORTCARD

/* Use ROM output (RST 10H, slow, 32x22) or CUSTOM (fast, 32x24) */

#define ROM_OUTPUT

/* Use fastcall model (the function parameters passed in regs.)  */
/* Use fastcall _ONLY_ if a function's parameters are constants. */

//#define BORDER_fastcall
//#define INK_fastcall
//#define PAPER_fastcall
//#define FLASH_fastcall
//#define BRIGHT_fastcall

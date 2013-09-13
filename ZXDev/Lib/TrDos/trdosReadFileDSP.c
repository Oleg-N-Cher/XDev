/* * * * * * * * * * * * * * * * * * * * * * * */
/* Обертка к функциям TR-DOS для SDCC  		   */
/* Бесплатно для некоммерческого использования */
/* SDCC interface for TR-DOS functions         */
/* Absolutely free for noncommercial use	   */
/* (c) 2013 Amxgris/Red Triangle/Mother Russia */
/* * * * * * * * * * * * * * * * * * * * * * * */

void trdosReadFileDSP(unsigned char *dst, unsigned char FNum)
{	dst; FNum; 
	__asm
	ld	hl,#4
	add	hl,sp
	ld	a,(hl)
	ld c,#8
	di
	call #0x3d13
	ei
	ld	hl,#2
	add	hl,sp
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	hl,#0x5cdd
	ld	bc,#0x10
	ldir
	__endasm;
}

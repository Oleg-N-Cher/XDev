/* * * * * * * * * * * * * * * * * * * * * * * */
/* Обертка к функциям TR-DOS для SDCC  		   */
/* Бесплатно для некоммерческого использования */
/* SDCC interface for TR-DOS functions         */
/* Absolutely free for noncommercial use	   */
/* (c) 2013 Amxgris/Red Triangle/Mother Russia */
/* * * * * * * * * * * * * * * * * * * * * * * */

void trdosWriteFileDSP(unsigned char *src, unsigned char FNum)
{ 	src; FNum;
	__asm
	ld	hl,#4
	add	hl,sp
	ld	a,(hl)
	dec	hl
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	hl,#0x5cdd
	ex	de,hl
	ld	bc,#9
	ldir
	ld c,#0x10
	di
	call #0x3d13
	ei
	__endasm;
}
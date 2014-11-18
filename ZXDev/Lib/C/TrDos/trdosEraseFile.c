/* * * * * * * * * * * * * * * * * * * * * * * */
/* Обертка к функциям TR-DOS для SDCC  		   */
/* Бесплатно для некоммерческого использования */
/* SDCC interface for TR-DOS functions         */
/* Absolutely free for noncommercial use	   */
/* (c) 2013 Amxgris/Red Triangle/Mother Russia */
/* * * * * * * * * * * * * * * * * * * * * * * */

void trdosEraseFile(unsigned char *dsp)
{	dsp;
	__asm
	ld	hl,#2
	add	hl,sp
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	hl,#0x5cdd
	ex	de,hl
	ld	bc,#0x10
	ldir
	ld	c,#12
	di
	call #0x3d13
	ei
	__endasm;
	
}
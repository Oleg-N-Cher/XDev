/* * * * * * * * * * * * * * * * * * * * * * * */
/* Обертка к функциям TR-DOS для SDCC  		   */
/* Бесплатно для некоммерческого использования */
/* SDCC interface for TR-DOS functions         */
/* Absolutely free for noncommercial use	   */
/* (c) 2013 Amxgris/Red Triangle/Mother Russia */
/* * * * * * * * * * * * * * * * * * * * * * * */

unsigned char trdosFindFile(char *name, unsigned char len) __naked
{	name; len;
	__asm
	ld	hl,#4
	add	hl,sp
	ld	a,(hl)
	ld	(0x5d06),a
	dec	hl
	ld	d,(hl)
	dec	hl
	ld	e,(hl)
	ld	hl,#0x5cdd
	ex	de,hl
	ld	c,a
	ld	b,#0
	ldir
	ld	c,#10
	di
	call #0x3d13
	ei
	ld	l,c
	ret
	__endasm;
}

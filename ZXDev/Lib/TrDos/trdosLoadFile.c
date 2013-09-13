/* * * * * * * * * * * * * * * * * * * * * * * */
/* Обертка к функциям TR-DOS для SDCC  		   */
/* Бесплатно для некоммерческого использования */
/* SDCC interface for TR-DOS functions         */
/* Absolutely free for noncommercial use	   */
/* (c) 2013 Amxgris/Red Triangle/Mother Russia */
/* * * * * * * * * * * * * * * * * * * * * * * */

void trdosLoadFile(char *name, unsigned char *src, unsigned int len)
{ 	name; src; len;
	__asm
	xor	a,a
	ld	(#23801),a
	ld	(#23824),a
	ld	hl,#2
	add	hl,sp
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	hl,#0x5cdd
	ex	de,hl
	ld	bc,#9
	ldir
	ld	hl,#4
	add	hl,sp
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	ld	a,(hl)
	inc	hl
	ld	h,(hl)
	ld	l,a
	ex	de,hl
	ld	c,#14
	ld	a,#3
	di
	call #0x3d13
	ei
	__endasm;
}
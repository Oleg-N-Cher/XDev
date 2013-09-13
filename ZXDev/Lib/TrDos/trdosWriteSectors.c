/* * * * * * * * * * * * * * * * * * * * * * * */
/* Обертка к функциям TR-DOS для SDCC  		   */
/* Бесплатно для некоммерческого использования */
/* SDCC interface for TR-DOS functions         */
/* Absolutely free for noncommercial use	   */
/* (c) 2013 Amxgris/Red Triangle/Mother Russia */
/* * * * * * * * * * * * * * * * * * * * * * * */

void trdosWriteSectors(unsigned char *src, unsigned char trck, unsigned char sec, unsigned char num)
{ 	src; trck; sec; num;
	__asm
	ld	hl,#6 ;+6 (num)
	add hl,sp
	ld	b,(hl)
	dec	hl ;  + 5 (sector)
	ld	e,(hl)
	dec	hl ;  + 4 (track)
	ld	d,(hl)
	dec hl ;  + 3 
	ld	a,(hl)
	dec	hl ;  + 2 (destination)
	ld h,(hl)
	ld	l,a
	ld	c,#6
	di
	call #0x3d13
	ei
	__endasm;
}

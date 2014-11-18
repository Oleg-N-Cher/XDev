/* * * * * * * * * * * * * * * * * * * * * * * */
/* Обертка к функциям TR-DOS для SDCC  		   */
/* Бесплатно для некоммерческого использования */
/* SDCC interface for TR-DOS functions         */
/* Absolutely free for noncommercial use	   */
/* (c) 2013 Amxgris/Red Triangle/Mother Russia */
/* * * * * * * * * * * * * * * * * * * * * * * */

void trdosReadSectors(unsigned char *dst, unsigned char trck, unsigned char sec, unsigned char num)
{	dst; trck; sec; num;
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
	ld l,(hl)
	ld	h,a
	ld	c,#5
	di
	call #0x3d13
	ei
	__endasm;

}
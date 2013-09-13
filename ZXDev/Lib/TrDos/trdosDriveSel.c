/* * * * * * * * * * * * * * * * * * * * * * * */
/* Обертка к функциям TR-DOS для SDCC  		   */
/* Бесплатно для некоммерческого использования */
/* SDCC interface for TR-DOS functions         */
/* Absolutely free for noncommercial use	   */
/* (c) 2013 Amxgris/Red Triangle/Mother Russia */
/* * * * * * * * * * * * * * * * * * * * * * * */

void trdosDriveSel(char drive)
{	drive;
	__asm
	ld	hl,#2
	add	hl,sp
	ld	a,(hl)
	res 5,a
	sub a,#0x41
	ld c,#1
	di
	call #0x3d13
	ei
	__endasm;
}
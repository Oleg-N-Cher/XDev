extern unsigned char _BORDERCOL;

/*================================== Header ==================================*/

unsigned char _BORDERCOL;

void border (unsigned char color) __naked __z88dk_fastcall {
__asm
	ld a,l
	ld (__BORDERCOL),a
	and #7
	bit 3,l
	jr nz,1$
	out (0xfe),a
	ret
1$:
	out (0xf6),a
	ret
__endasm;
}

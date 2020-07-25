/*
; --------------------------------------
; Adapted for SDCC by SfS & Oleg N. Cher
; --------------------------------------
;
; Init:
;	  StcInit(music_adr)
;
; Play:
;	  StcPlay every 20ms
;
; Control flags:
;	bit 0 flags == 1 is unlooped mode
;	bit 0 flags == 0 is looped mode
;
; Status flags:
;	bit 7 flags == 1, if music loop is terminated, 
;	else this bit is 0
; --------------------------------------

; Init entry
;   Init (music_adr)

; Play entry. Must be called every 20ms
;   Play

; Control and status flags
    flags: SET
*/

void StcPlayer_Init (unsigned int mod) __naked __z88dk_fastcall {
__asm
; Disassembly of the file "stcrout.bin"
; CPU Type: Z80
; Created with dZ80 2.0
; on Wednesday, 18 of February 2004 at 10:47 PM
; 
        push    ix
        call    stc_init
        pop     ix
        ret
stc_init:
        ld      a,(hl)		; read delay value
        ld      (delay),a
        ld      (data_addr),hl	; store address of data start
        inc     hl			; now hl = stc_data+1, start of pointer list
        call    read_convert_ptr	; find absolute address of position map

        ld      a,(de)		; read song length
        inc     de			; de now points to first real entry in position map
        inc     a
        ld      (song_length),a
        ld      (position_map),de
        call    read_convert_ptr

        ld      (l7c36),de
        push    de
        call    read_convert_ptr

        ld      (l7c38),de
        ld      hl,#0x001b
        call    l7c7e

        ex      de,hl
        ld      (l7c3a),hl
        ld      hl,#l7c45
        ld      (l7c3f),hl
        ld      hl,#l7c46
        ld      de,#l7c46+1
        ld      bc,#0x002c
        ld      (hl),b
        ldir
        pop     hl

        ld      bc,#0x0021
        xor     a
        call    l7c73

        dec     a
        ld      (l7c4f),a
        ld      (l7c59),a
        ld      (l7c63),a
        ld      a,#01
        ld      (delay_count),a
        inc     hl
        ld      (l7c4d),hl
        ld      (l7c57),hl
        ld      (l7c61),hl
        call    l7fe3
        ret

position_map:  .dw      0xf177
l7c36:	.dw 0xf18f
l7c38:	.dw 0xf213
l7c3a:	.dw 0xee5e
delay:         .db      0x06
delay_count:   .db      0x01
song_length:   .db      0x0c
l7c3f:	.dw 0xe745
l7c41:	.dw 0x69b8
l7c43:	.dw 0x6a57
l7c45:	.db 0xff
l7c46:	.db 0x00
	.db 0x00
l7c48:	.db 0x00, 0x00, 0x00
l7c4b:	.dw 0x0000
l7c4d:	.dw 0xf190
l7c4f:	.db 0xff
	.db 0x00, 0x00
l7c52:	.db 0x00, 0x00, 0x00
l7c55:	.db 0x00
	.db 0x00
l7c57:	.db 0x90
	.db 0xf1
l7c59:	.db 0xff, 0x00, 0x00
l7c5c:	.db 0x00, 0x00
	.db 0x00
l7c5f:	.db 0x00, 0x00
l7c61:	.db 0x90, 0xf1
l7c63:	.db 0xff
l7c64:	.db 0x00
l7c65:	.db 0x00
	.db 0x00
l7c67:	.db 0x00, 0x00
l7c69:	.db 0x00, 0x00
l7c6b:	.db 0x00
l7c6c:	.db 0x00
l7c6d:	.db 0x00
l7c6e:	.db 0x00
l7c6f:	.db 0x00
l7c70:	.db 0x00, 0x00
l7c72:	.db 0x00

l7c73:  cp      (hl)
        ret     z
        add     hl,bc
        jp      l7c73
read_convert_ptr:
        ld      e,(hl)
        inc     hl
        ld      d,(hl)
        inc     hl
        ex      de,hl		; ld hl,(hl)
l7c7e:  ld      bc,#0x0ee43
data_addr= .-2
        add     hl,bc		; convert an offset from stc_data to an absolute address
        ex      de,hl		; return it in de
        ret     
l7c84:  ld      d,#0x00
        ld      e,a
        add     a,a
        add     a,e
        ld      e,a
        add     ix,de
        ld      a,1(ix)
        bit     7,a
        ld      c,#0x10
        jp      nz,l7c97
        ld      c,d
l7c97:  bit     6,a
        ld      b,#0x02
        jp      nz,l7c9f
        ld      b,d
l7c9f:  and     #0x1f
        ld      h,a
        ld      e,2(ix)
        ld      a,0(ix)
        push    af
        and     #0xf0
        rrca    
        rrca    
        rrca    
        rrca    
        ld      d,a
        pop     af
        and     #0x0f
        ld      l,a
        bit     5,1(ix)
        ret     z
        set     4,d
        ret     
l7cbc:  ld      a,(l7c64)
        ld      c,a
        ld      hl,#song_length
        cp      (hl)
        jp      c,l7cc9
        ; End of music
        xor     a
        ld      c,a
        ; Set end_of_music flags
        ld	hl,#_StcPlayer_flags
        set	7,(hl)
        ;
l7cc9:  inc     a
        ld      (l7c64),a
        ld      l,c
        ld      h,#00
        add     hl,hl
        ld      de,(position_map)
        add     hl,de
        ld      c,(hl)
        inc     hl
        ld      a,(hl)
        ld      (l7f08),a
        ld      a,c
        ld      hl,(l7c38)
        ld      bc,#0007
        call    l7c73
        inc     hl
        call    read_convert_ptr
        ld      (l7c3f),de
        call    read_convert_ptr
        ld      (l7c41),de
        call    read_convert_ptr
        ld      (l7c43),de
        ret     
l7cfd:  dec     2(ix)
        ret     p
        ld      a,-1(ix)
        ld      2(ix),a
        ret
__endasm;
} //StcPlayer_Init

void StcPlayer_Play (void) __naked {
__asm
	push	ix
	call	stc_play
	pop	ix
	ret
stc_play:
	; check unlooped flags
	ld	hl,#_StcPlayer_flags
	bit	0,(hl)
	jr	z,stc_play_looped
	; check end of music
	bit	7,(hl)
	ret 	nz
stc_play_looped:
	ld      a,(delay_count)
        dec     a
        ld      (delay_count),a
        jp      nz,l7e52
        ld      a,(delay)
        ld      (delay_count),a
        ld      ix,#l7c48
        call    l7cfd
        jp      p,l7d33
        ld      hl,(l7c3f)
        ld      a,(hl)
        inc     a
        call    z,l7cbc
        ld      hl,(l7c3f)
        call    l7d5c
        ld      (l7c3f),hl
l7d33:  ld      ix,#l7c52
        call    l7cfd
        jp      p,l7d46
        ld      hl,(l7c41)
        call    l7d5c
        ld      (l7c41),hl
l7d46:  ld      ix,#l7c5c
        call    l7cfd
        jp      p,l7e52
        ld      hl,(l7c43)
        call    l7d5c
        ld      (l7c43),hl
        jp      l7e52
l7d5c:  ld      a,(hl)
        cp      #0x60
        jp      c,l7d8a
        cp      #0x70
        jp      c,l7d97
        cp      #0x80
        jp      c,l7db8
        jp      z,l7daf
        cp      #0x81
        jp      z,l7d95
        cp      #0x82
        jp      z,l7db5
        cp      #0x8f
        jp      c,l7dd4
        sub     #0x0a1
        ld      2(ix),a
        ld      -1(ix),a
        inc     hl
        jp      l7d5c
l7d8a:  ld      1(ix),a
        ld      0(ix),#0x00
        ld      7(ix),#0x20
l7d95:  inc     hl
        ret     
l7d97:  sub     #0x60
        push    hl
        ld      bc,#0x0063
        ld      hl,(l7c3a)
        call    l7c73
        inc     hl
        ld      3(ix),l
        ld      4(ix),h
        pop     hl
        inc     hl
        jp      l7d5c
l7daf:  inc     hl
l7db0:  ld      7(ix),#0x0ff
        ret     
l7db5:  xor     a
        jr      l7dba
l7db8:  sub     #0x70
l7dba:  push    hl
        ld      bc,#0x0021
        ld      hl,(l7c36)
        call    l7c73
        inc     hl
        ld      5(ix),l
        ld      6(ix),h
        ld      -2(ix),#00
        pop     hl
        inc     hl
        jp      l7d5c
l7dd4:  sub     #0x80
        ld      (l7c72),a
        inc     hl
        ld      a,(hl)
        inc     hl
        ld      (l7c70),a
        ld      -2(ix),#01
        push    hl
        xor     a
        ld      bc,#0x0021
        ld      hl,(l7c36)
        call    l7c73
        inc     hl
        ld      5(ix),l
        ld      6(ix),h
        pop     hl
        jp      l7d5c
l7df9:  ld      a,7(ix)
        inc     a
        ret     z
        dec     a
        dec     a
        ld      7(ix),a
        push    af
        ld      a,0(ix)
        ld      c,a
        inc     a
        and     #0x1f
        ld      0(ix),a
        pop     af
        ret     nz
        ld      e,3(ix)
        ld      d,4(ix)
        ld      hl,#0x0060
        add     hl,de
        ld      a,(hl)
        dec     a
        jp      m,l7db0
        ld      c,a
        inc     a
        and     #0x1f
        ld      0(ix),a
        inc     hl
        ld      a,(hl)
        inc     a
        ld      7(ix),a
        ret     
l7e2d:  ld      a,c
        or      a
        ret     nz
        ld      a,h
        ld      (l7c6b),a
        ret
l7e35:  ld      a,7(ix)
        inc     a
        ret     z
        ld      a,-2(ix)
        or      a
        ret     z
        cp      #0x02
        jp      z,l7e4b
        ld      2(ix),#2
        jp      l7e4f
l7e4b:  xor     a
        ld      (l7c72),a
l7e4f:  set     4,(hl)
        ret
l7e52:  ld      ix,#l7c48
        call    l7df9
        ld      a,c
        ld      (l7f00),a
        ld      ix,(l7c4b)
        call    l7c84
        ld      a,c
        or      b
        rrca
        ld      (l7c6c),a
        ld      ix,#l7c48
        ld      a,7(ix)
        inc     a
        jp      z,l7e7e
        call    l7e2d
        call    l7ef6
        ld      (l7c65),hl
l7e7e:  ld      hl,#l7c6d
        ld      (hl),a
        call    l7e35
        ld      ix,#l7c52
        call    l7df9
        ld      a,7(ix)
        inc     a
        jp      z,l7eb3
        ld      a,c
        ld      (l7f00),a
        ld      ix,(l7c55)
        call    l7c84
        ld      a,(l7c6c)
        or      c
        or      b
        ld      (l7c6c),a
        call    l7e2d
        ld      ix,#l7c52
        call    l7ef6
        ld      (l7c67),hl
l7eb3:  ld      hl,#l7c6e
        ld      (hl),a
        call    l7e35
        ld      ix,#l7c5c
        call    l7df9
        ld      a,7(ix)
        inc     a
        jp      z,l7eec
        ld      a,c
        ld      (l7f00),a
        ld      ix,(l7c5f)
        call    l7c84
        ld      a,(l7c6c)
        rlc     c
        rlc     b
        or      b
        or      c
        ld      (l7c6c),a
        call    l7e2d
        ld      ix,#l7c5c
        call    l7ef6
        ld      (l7c69),hl
l7eec:  ld      hl,#l7c6f
        ld      (hl),a
        call    l7e35
        jp      l7fe3
l7ef6:  ld      a,l
        push    af
        push    de
        ld      l,5(ix)
        ld      h,6(ix)
        ld      de,#0x000a
l7f00= .-2
        add     hl,de
        ld      a,1(ix)
        add     a,(hl)
        add     a,#00
l7f08= .-1
        add     a,a
        ld      e,a
        ld      d,#00
        ld      hl,#tonetable
        add     hl,de
        ld      e,(hl)
        inc     hl
        ld      d,(hl)
        ex      de,hl
        pop     de
        pop     af
        bit     4,d
        jr      z,l7f1f
        res     4,d
        add     hl,de
        ret
l7f1f:  and     a
        sbc     hl,de
        ret
; control and status flags byte
; bit 0 - (control) must be set, if unlooped
; bit 7 - (status) set, if music end of loop
.globl _StcPlayer_flags
_StcPlayer_flags:	.db 0x00

tonetable:
	.dw 0x0ef8, 0x0e10, 0x0d60, 0x0c80, 0x0bd8, 0x0b28, 0x0a88, 0x09f0
	.dw 0x0960, 0x08e0, 0x0858, 0x07e0, 0x077c, 0x0708, 0x06b0, 0x0640
	.dw 0x05ec, 0x0594, 0x0544, 0x04f8, 0x04b0, 0x0470, 0x042c, 0x03f0
	.dw 0x03be, 0x0384, 0x0358, 0x0320, 0x02f6, 0x02ca, 0x02a2, 0x027c
	.dw 0x0258, 0x0238, 0x0216, 0x01f8, 0x01df, 0x01c2, 0x01ac, 0x0190
	.dw 0x017b, 0x0165, 0x0151, 0x013e, 0x012c, 0x011c, 0x010b, 0x00fc
	.dw 0x00ef, 0x00e1, 0x00d6, 0x00c8, 0x00bd, 0x00b2, 0x00a8, 0x009f
	.dw 0x0096, 0x008e, 0x0085, 0x007e, 0x0077, 0x0070, 0x006b, 0x0064
	.dw 0x005e, 0x0059, 0x0054, 0x004f, 0x004b, 0x0047, 0x0042, 0x003f
	.dw 0x003b, 0x0038, 0x0035, 0x0032, 0x002f, 0x002c, 0x002a, 0x0027
	.dw 0x0025, 0x0023, 0x0021, 0x001f, 0x001d, 0x001c, 0x001a, 0x0019
	.dw 0x0017, 0x0016, 0x0015, 0x0013, 0x0012, 0x0011, 0x0010, 0x000f

l7fe3:  ld      hl,#l7c72
        xor     a
        or      (hl)
        ld      a,#0x0d
        jr      nz,l7ff1
        sub     #0x03
        dec     hl
        dec     hl
        dec     hl
l7ff1:  ld      c,#0xfd
l7ff3:  ld      b,#0xff
        out     (c),a
        ld      b,#0xbf
        outd
        dec     a
        jp      p,l7ff3
        ret
__endasm;
} //StcPlayer_Play

#ifndef GrTiles__h
#define GrTiles__h


extern void GrTiles_DrawTile8x8 (unsigned char x, unsigned char y, unsigned int tile) __z88dk_callee __preserves_regs(c,iyl,iyh);
extern void GrTiles_DrawMonoTile8x8 (unsigned char x, unsigned char y, unsigned int tile, unsigned char colors) __z88dk_callee __preserves_regs(iyl,iyh);
extern void GrTiles_GetTile8x8 (unsigned char x, unsigned char y, unsigned int tile) __z88dk_callee __preserves_regs(c,iyl,iyh);
extern void GrTiles_GetMonoTile8x8 (unsigned char x, unsigned char y, unsigned int tile) __z88dk_callee __preserves_regs(c,iyl,iyh);

#define GrTiles_DrawTile GrTiles_DrawTile8x8
#define GrTiles_DrawMonoTile GrTiles_DrawMonoTile8x8
#define GrTiles_DrawTranspMonoTile GrTiles_DrawMonoTile8x8
#define GrTiles_GetTile GrTiles_GetTile8x8
#define GrTiles_GetMonoTile GrTiles_GetMonoTile8x8

#define GrTiles__init()


#endif

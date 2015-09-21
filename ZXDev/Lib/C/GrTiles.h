#ifndef GrTiles__h
#define GrTiles__h


extern void GrTiles_DrawTile8x8 (unsigned char x, unsigned char y, unsigned int tile);
extern void GrTiles_DrawMonoTile8x8 (unsigned char x, unsigned char y, unsigned int tile, unsigned char colors);
extern void GrTiles_DrawTranspMonoTile8x8 (unsigned char x, unsigned char y, unsigned int tile, unsigned char colors);

#define GrTiles_DrawTile GrTiles_DrawTile8x8
#define GrTiles_DrawMonoTile GrTiles_DrawMonoTile8x8
#define GrTiles_DrawTranspMonoTile GrTiles_DrawMonoTile8x8

#define GrTiles__init()


#endif

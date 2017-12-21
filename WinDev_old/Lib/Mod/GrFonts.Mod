MODULE GrFonts;
IMPORT SYSTEM;

TYPE
  Font* = ARRAY [1] OF BYTE;
VAR
  ZxSpecRom8x8*, ZxSpecRus8x8* : ARRAY [1] 8 * (128 - 32) OF BYTE; 
  MsDosCga8x8* : ARRAY [1] 8 * 256 OF BYTE;

END GrFonts.
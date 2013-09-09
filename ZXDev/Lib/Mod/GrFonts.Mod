MODULE GrFonts;
IMPORT SYSTEM;

TYPE
  Font* = ARRAY [1] OF SYSTEM.BYTE;

VAR
  ZxSpecRom8x8*, MsDosCga8x8* : ARRAY [1] 8 * (128 - 32) OF SYSTEM.BYTE;

END GrFonts.
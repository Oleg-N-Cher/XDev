MODULE GrFonts;
IMPORT SYSTEM, Basic;

TYPE
  Font* = ADRINT;

CONST
  ZxSpecRom8x8* = Basic.RomFont;

VAR
  MsDosCga8x8-, MsDosCgaRus8x8-, ZxSpecRus8x8-,
  HalfSpaceRus6x8-: Font;

END GrFonts.
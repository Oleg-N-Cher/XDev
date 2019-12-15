MODULE Out6x8; IMPORT SYSTEM;

VAR
  font*: INTEGER;

PROCEDURE At* (x, y: SHORTINT);              END At;
PROCEDURE Ch* (ch: CHAR);                    END Ch;
PROCEDURE Ln*;                               END Ln;
PROCEDURE Str* (str: ARRAY [notag] OF CHAR); END Str;
PROCEDURE GenFont* (dest: INTEGER);          END GenFont;

END Out6x8.

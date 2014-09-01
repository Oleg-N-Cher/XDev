MODULE Console;

TYPE
  Coords* = SHORTINT;

PROCEDURE At* (x, y: Coords); END At;
PROCEDURE Clear* ; END Clear;
PROCEDURE WriteCh* (ch: CHAR); END WriteCh;

END Console.
MODULE [noinit] KMouse; IMPORT SYSTEM;
(**
  Short mouse driver (optimized for size - source for Prometheus / AS + manual)
  https://velesoft.speccy.cz/k-mouse_driver.htm
*)

CONST Right* = 0; Left* = 1; Down* = 2; Up* = 3; Fire* = 4;

VAR X-, Y-: SYSTEM.BYTE;

PROCEDURE- Read* (): SET;
PROCEDURE- SetXY* (x, y: INT16);
PROCEDURE- Detect* (): BOOLEAN;
 
END KMouse.

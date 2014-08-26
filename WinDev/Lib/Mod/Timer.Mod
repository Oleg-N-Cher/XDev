MODULE Timer; (** non-portable *)
IMPORT Sdl := SdlLib, Input;

PROCEDURE Delay* (msec: INTEGER);
BEGIN
  IF Input.Available() = 0 THEN END;
  Sdl.Delay(msec);
  IF Input.Available() = 0 THEN END;
END Delay;

END Timer.

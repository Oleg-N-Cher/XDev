MODULE Input;

IMPORT
  SYSTEM, Sdl := SdlLib, Ignore;

(**
Module Input is responsible for event timing, mouse and keyboard input.
http://www.ethoberon.ethz.ch/ethoberon/defs/Input.Def.html
*)

(*
DEFINITION Input;
VAR
  TimeUnit: LONGINT;
PROCEDURE Available (): INTEGER;
PROCEDURE Read (VAR ch: CHAR);
PROCEDURE Mouse (VAR keys: SET; VAR x, y: INTEGER);
PROCEDURE SetMouseLimits (w, h: INTEGER);
PROCEDURE Time (): LONGINT;
END Input.

State

-  Keyboard buffer. A queue of characters typed in from the keyboard.
-  Time. Elapsed time since system startup in units of size 1/TimeUnit seconds.

Operations

-  Available() returns the number of characters in the keyboard buffer.

-  Read(ch) returns (and removes) the next character from the keyboad buffer. If the buffer is empty, Read waits until a key is pressed.

-  Mouse(keys, x, y) returns the current mouse position (x, y) in pixels relative to the lower left corner of the screen. keys is the set of the currently pressed mouse keys (left = 2, middle = 1, right = 0).

-  SetMouseLimits(w, h) defines the rectangle where the mouse moves (in pixels).  Subsequent calls to the operation Mouse will return coordinates for x in the range 0..w-1 and y in the range 0..h-1.

-  Time() returns the time elapsed since system startup in units of size 1/TimeUnit seconds.

Examples

  IF Input.Available() > 0 THEN Input.Read(ch) END;
      REPEAT
   Input.Mouse(keys, x, y);
   ... draw mouse cursor at position (x, y) ...
  UNTIL keys = {}
seconds := Input.Time() DIV Input.TimeUnit

Origin

Part of the ETH Oberon System.  The above specification was proposed by H Moessenboeck, ETH.
*)
CONST
  (* The keyboard syms have been cleverly chosen to map to ASCII *)
  Backspace* = CHR(Sdl.K_BACKSPACE);
  Tab* = CHR(Sdl.K_TAB);
  Enter* = CHR(Sdl.K_RETURN);
  (* Pause* = CHR(Sdl.K_PAUSE); *)
  Escape* = CHR(Sdl.K_ESCAPE);
  Delete* = CHR(Sdl.K_DELETE);
  Space* = CHR(Sdl.K_SPACE);

  (* Arrows *)
  Up* = 1EX;
  Down* = 1FX;
  Right* = 10X;
  Left* = 11X;

  (* Function keys *)
  F1* = 1X;
  F2* = 2X;
  F3* = 3X;
  F4* = 4X;
  F5* = 5X;
  F6* = 6X;
  F7* = 7X;
  F8* = 8X;
  F9* = 9X;
  F10* = 0AX;
  F11* = 0BX;
  F12* = 0CX;

  KeyBufSize = 32;
  UniArrSize = 2*11 + 2*26;

TYPE
  Key* = CHAR;
  UNICHAR = SHORTINT;

VAR
  n, in, out: INTEGER;
  keybuf: ARRAY KeyBufSize OF Key;
  Uni: ARRAY UniArrSize OF UNICHAR; Ch: ARRAY UniArrSize OF CHAR;

PROCEDURE Quit; (* Quit app and exit to OS. *)
BEGIN
  Sdl.Quit; HALT(0)
END Quit;

PROCEDURE CheckAddKey (keybev: Sdl.KeyboardEvent): BOOLEAN;
VAR
  i: INTEGER; key: Key;
BEGIN
  IF (keybev.keysym.modifier * Sdl.KMOD_ALT # {}) THEN (* Alt *)
    IF (keybev.keysym.sym = Sdl.K_F4) THEN Quit END; (* F4 *)
    RETURN FALSE
  END;
  IF (keybev.keysym.modifier * Sdl.KMOD_CTRL # {}) OR (n >= KeyBufSize) THEN
    RETURN FALSE
  END;
  LOOP
    (* The keyboard syms have been cleverly chosen to map to ASCII: *)
    IF (keybev.keysym.unicode >= ORD(Space))
      &(keybev.keysym.unicode < ORD(Delete)) THEN
        key := CHR(keybev.keysym.unicode); EXIT
    END;
    CASE keybev.keysym.sym OF
    | ORD(Backspace), ORD(Tab), ORD(Enter), ORD(Escape), ORD(Delete):
        key := CHR(keybev.keysym.sym); EXIT
    (* Numeric keypad: *)
    | Sdl.K_DOWN, Sdl.K_KP2:
        key := Down; EXIT
    | Sdl.K_LEFT, Sdl.K_KP4:
        key := Left; EXIT
    | Sdl.K_RIGHT, Sdl.K_KP6:
        key := Right; EXIT
    | Sdl.K_UP, Sdl.K_KP8:
        key := Up; EXIT
    | Sdl.K_KP_PERIOD:
        key := Delete; EXIT
    | Sdl.K_KP_ENTER:
        key := Enter; EXIT
    ELSE
    END;
    (* Function keys: *)
    IF (keybev.keysym.sym >= Sdl.K_F1) & (keybev.keysym.sym <= Sdl.K_F12) THEN
      key := CHR(keybev.keysym.sym - Sdl.K_F1 + ORD(F1)); EXIT
    END;
    FOR i := UniArrSize-1 TO 0 BY -1 DO
      IF keybev.keysym.unicode = Uni[i] THEN key := Ch[i]; EXIT END;
    END;
    RETURN FALSE
  END;
  (* Add a key: *)
  keybuf[in] := key; in := (in+1) MOD KeyBufSize; INC(n);
  RETURN TRUE
END CheckAddKey;

(** Returns the number of keystrokes in the keyboard input buffer. *)
PROCEDURE Available* (): INTEGER;
VAR
  event: Sdl.Event;
BEGIN
  WHILE (Sdl.PollEvent(event) # 0) DO
    IF event.type = Sdl.KEYDOWN THEN
      IF CheckAddKey(SYSTEM.VAL(Sdl.KeyboardEvent, event)) THEN END;
    ELSIF event.type = Sdl.QUITEV THEN
      Quit
    END;
  END;
  RETURN n
END Available;

PROCEDURE TimeLeft (): INTEGER;
CONST
  TickInterval = 10;
VAR
  nextTime, now: INTEGER;
BEGIN
  nextTime := 0;
  now := Sdl.GetTicks();
  IF nextTime <= now THEN
    nextTime := now + TickInterval;
    RETURN 0
  END;
  RETURN nextTime-now
END TimeLeft;

(** Read a key from the keyboard buffer. Blocks if no key is available. *)
PROCEDURE Read* (): Key;
VAR
  key: Key; event: Sdl.Event;
BEGIN
  IF Available() = 0 THEN (* Check for events *)
    LOOP
      (*Sdl.Delay(10);*)
      WHILE (Sdl.WaitEvent(event) # 0) DO
        IF event.type = Sdl.KEYDOWN THEN
          IF CheckAddKey(SYSTEM.VAL(Sdl.KeyboardEvent, event)) THEN
            EXIT
          END;
        ELSIF event.type = Sdl.QUITEV THEN
          Quit
        END;
      END;
      Sdl.PumpEvents;
      Sdl.Delay(TimeLeft());
    END;
  END;
  DEC(n); key := keybuf[out]; out := (out+1) MOD KeyBufSize;
  RETURN key
END Read;

PROCEDURE UtoC (u: UNICHAR; c: CHAR); (* Add Unicode to Char translation. *)
BEGIN
  Uni[n] := u; Ch[n] := c; INC(n);
END UtoC;

BEGIN
  n := 0;
  UtoC(411H(* Á *), "<");
  UtoC(416H(* Æ *), ":");
  UtoC(425H(* Õ *), "{");
  UtoC(42AH(* Ú *), "}");
  UtoC(42DH(* Ý *), '"');
  UtoC(42EH(* Þ *), ">");
  UtoC(406H(* ² *), "S");
  UtoC(404H(* ª *), '"');
  UtoC(407H(* ¯ *), "}");
  UtoC(401H(* ¨ *), "~");
  UtoC(40EH(* ¡ *), "O");

  UtoC(431H(* á *), ",");
  UtoC(436H(* æ *), ";");
  UtoC(445H(* õ *), "[");
  UtoC(44AH(* ú *), "]");
  UtoC(44DH(* ý *), "'");
  UtoC(44EH(* þ *), ".");
  UtoC(456H(* ³ *), "s");
  UtoC(454H(* º *), "'");
  UtoC(457H(* ¿ *), "]");
  UtoC(451H(* ¸ *), "`");
  UtoC(45EH(* ¢ *), "o");

  UtoC(424H(* Ô *), "A");
  UtoC(418H(* È *), "B");
  UtoC(421H(* Ñ *), "C");
  UtoC(412H(* Â *), "D");
  UtoC(423H(* Ó *), "E");
  UtoC(410H(* À *), "F");
  UtoC(41FH(* Ï *), "G");
  UtoC(420H(* Ð *), "H");
  UtoC(428H(* Ø *), "I");
  UtoC(41EH(* Î *), "J");
  UtoC(41BH(* Ë *), "K");
  UtoC(414H(* Ä *), "L");
  UtoC(42CH(* Ü *), "M");
  UtoC(422H(* Ò *), "N");
  UtoC(429H(* Ù *), "O");
  UtoC(417H(* Ç *), "P");
  UtoC(419H(* É *), "Q");
  UtoC(41AH(* Ê *), "R");
  UtoC(42BH(* Û *), "S");
  UtoC(415H(* Å *), "T");
  UtoC(413H(* Ã *), "U");
  UtoC(41CH(* Ì *), "V");
  UtoC(426H(* Ö *), "W");
  UtoC(427H(* × *), "X");
  UtoC(41DH(* Í *), "Y");
  UtoC(42FH(* ß *), "Z");

  UtoC(444H(* ô *), "a");
  UtoC(438H(* è *), "b");
  UtoC(441H(* ñ *), "c");
  UtoC(432H(* â *), "d");
  UtoC(443H(* ó *), "e");
  UtoC(430H(* à *), "f");
  UtoC(43FH(* ï *), "g");
  UtoC(440H(* ð *), "h");
  UtoC(448H(* ø *), "i");
  UtoC(43EH(* î *), "j");
  UtoC(43BH(* ë *), "k");
  UtoC(434H(* ä *), "l");
  UtoC(44CH(* ü *), "m");
  UtoC(442H(* ò *), "n");
  UtoC(449H(* ù *), "o");
  UtoC(437H(* ç *), "p");
  UtoC(439H(* é *), "q");
  UtoC(43AH(* ê *), "r");
  UtoC(44BH(* û *), "s");
  UtoC(435H(* å *), "t");
  UtoC(433H(* ã *), "u");
  UtoC(43CH(* ì *), "v");
  UtoC(446H(* ö *), "w");
  UtoC(447H(* ÷ *), "x");
  UtoC(43DH(* í *), "y");
  UtoC(44FH(* ÿ *), "z");

  n := 0; in := 0; out := 0;
  Ignore.Int( Sdl.EnableUNICODE(1) );
  Ignore.Int( Sdl.EnableKeyRepeat(500, 50) );
END Input.

(*
  ToDo:

+ Belarussian Y~

*)
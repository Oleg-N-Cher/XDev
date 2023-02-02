MODULE Input;

IMPORT
  SYSTEM;

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
  Backspace* = 0CX;
(*
  Tab* = CHR(Sdl.K_TAB);*)
  Enter* = 0DX;
  (* Pause* = CHR(Sdl.K_PAUSE);*)
  Escape* = "E";
  (* Delete* = CHR(Sdl.K_DELETE); *)
  Space* = " ";

  (* Arrows *)
  Up    * = "Q";
  Down  * = "A";
  Right * = "P";
  Left  * = "O";
(*
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
  UniArrSize = 2*10 + 2*26;
*)

  LAST_K = 5C08H;

TYPE
  Key* = CHAR;
(*
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
    | Sdl.K_KP2:
        key := Down; EXIT
    | Sdl.K_KP4:
        key := Left; EXIT
    | Sdl.K_KP6:
        key := Right; EXIT
    | Sdl.K_KP8:
        key := Up; EXIT
    | Sdl.K_KP_PERIOD:
        key := Delete; EXIT
    | Sdl.K_KP_ENTER:
        key := Enter; EXIT
    ELSE
    END;
    (* Arrows: *)
    IF (keybev.keysym.sym >= Sdl.K_UP) & (keybev.keysym.sym <= Sdl.K_LEFT) THEN
      key := CHR(keybev.keysym.sym - Sdl.K_UP + ORD(Up)); EXIT
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

*)
(** Returns the number of keystrokes in the keyboard input buffer. *)
PROCEDURE Available* (): SYSTEM.BYTE;
BEGIN RETURN 0 END Available;

(** Read a key from the keyboard buffer. Blocks if no key is available. *)
PROCEDURE Read* (): Key;
BEGIN RETURN 0X END Read;

PROCEDURE RunMe50Hz* ; END RunMe50Hz;

END Input.

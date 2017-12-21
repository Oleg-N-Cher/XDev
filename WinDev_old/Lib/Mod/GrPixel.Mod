MODULE GrPixel;	(** Versia for SDL *)
IMPORT SYSTEM, Sdl := SdlLib, GrApp, Cfg := GrConfig;

TYPE
  Color* = GrApp.Color;
  Coords* = INTEGER;
VAR
  ink-: Color;
  pitch: INTEGER;
  PutActualPixelNoLock,
  Dot- , PutPixelNoLock- : PROCEDURE (x, y: Coords);

PROCEDURE PutActualPixel8Lock (x, y: Coords); (* Assuming 8-bpp mode. *)
BEGIN
  IF ~ Cfg.ChkOutOfScreen OR
    ((x>=0) & (x<=Cfg.ActualMaxX) & (y>=0) & (y<=Cfg.ActualMaxY)) THEN
      IF Sdl.LockSurface(GrApp.Screen) # 0 THEN
        SYSTEM.PUT(
          SYSTEM.VAL(LONGINT, GrApp.Screen.pixels) + y*pitch + x,
          SYSTEM.VAL(BYTE, ink));
        Sdl.UnlockSurface(GrApp.Screen);
      END;
  END;
END PutActualPixel8Lock;

PROCEDURE PutActualPixel8NoLock (x, y: Coords); (* Assuming 8-bpp mode. *)
BEGIN
  IF ~ Cfg.ChkOutOfScreen OR
    ((x>=0) & (x<=Cfg.ActualMaxX) & (y>=0) & (y<=Cfg.ActualMaxY)) THEN
      SYSTEM.PUT(
        SYSTEM.VAL(LONGINT, GrApp.Screen.pixels) + y*pitch + x,
        SYSTEM.VAL(BYTE, ink));
  END;
END PutActualPixel8NoLock;

PROCEDURE PutActualPixel16Lock (x, y: Coords); (* 15-bpp or 16-bpp mode. *)
BEGIN
  IF ~ Cfg.ChkOutOfScreen OR
    ((x>=0) & (x<=Cfg.ActualMaxX) & (y>=0) & (y<=Cfg.ActualMaxY)) THEN
      IF Sdl.LockSurface(GrApp.Screen) # 0 THEN
        SYSTEM.PUT(
          SYSTEM.VAL(LONGINT, GrApp.Screen.pixels) + y*pitch + x*2,
          SYSTEM.VAL(SHORTINT, ink));
        Sdl.UnlockSurface(GrApp.Screen);
      END;
  END;
END PutActualPixel16Lock;

PROCEDURE PutActualPixel16NoLock (x, y: Coords); (* 15-bpp or 16-bpp. *)
BEGIN
  IF ~ Cfg.ChkOutOfScreen OR
    ((x>=0) & (x<=Cfg.ActualMaxX) & (y>=0) & (y<=Cfg.ActualMaxY)) THEN
      SYSTEM.PUT(
        SYSTEM.VAL(LONGINT, GrApp.Screen.pixels) + y*pitch + x*2,
        SYSTEM.VAL(SHORTINT, ink));
  END;
END PutActualPixel16NoLock;

(* Slow 24-bpp mode, usually not used: *)
PROCEDURE PutActualPixel24Lock (x, y: Coords);
VAR
  addr: LONGINT;
BEGIN
  IF ~ Cfg.ChkOutOfScreen OR
    ((x>=0) & (x<=Cfg.ActualMaxX) & (y>=0) & (y<=Cfg.ActualMaxY)) THEN
      IF Sdl.LockSurface(GrApp.Screen) # 0 THEN
        addr := SYSTEM.VAL(LONGINT, GrApp.Screen.pixels) + y*pitch + x*3;
        SYSTEM.PUT(addr,   SYSTEM.VAL(SHORTINT, ink));
        SYSTEM.PUT(addr+2, SYSTEM.VAL(BYTE, SYSTEM.LSH(ink, -16)));
        Sdl.UnlockSurface(GrApp.Screen);
      END;
  END;
END PutActualPixel24Lock;

PROCEDURE PutActualPixel24NoLock (x, y: Coords);
VAR
  addr: LONGINT;
BEGIN
  IF ~ Cfg.ChkOutOfScreen OR
    ((x>=0) & (x<=Cfg.ActualMaxX) & (y>=0) & (y<=Cfg.ActualMaxY)) THEN
      addr := SYSTEM.VAL(LONGINT, GrApp.Screen.pixels) + y*pitch + x*3;
      SYSTEM.PUT(addr,   SYSTEM.VAL(SHORTINT, ink));
      SYSTEM.PUT(addr+2, SYSTEM.VAL(BYTE, SYSTEM.LSH(ink, -16)));
  END;
END PutActualPixel24NoLock;

PROCEDURE PutActualPixel32Lock (x, y: Coords); (* 32-bpp mode. *)
BEGIN
  IF ~ Cfg.ChkOutOfScreen OR
    ((x>=0) & (x<=Cfg.ActualMaxX) & (y>=0) & (y<=Cfg.ActualMaxY)) THEN
      IF Sdl.LockSurface(GrApp.Screen) # 0 THEN
        SYSTEM.PUT(
          SYSTEM.VAL(LONGINT, GrApp.Screen.pixels) + y*pitch + x*4, ink);
        Sdl.UnlockSurface(GrApp.Screen);
      END;
  END;
END PutActualPixel32Lock;

PROCEDURE PutActualPixel32NoLock (x, y: Coords); (* 32-bpp mode. *)
BEGIN
  IF ~ Cfg.ChkOutOfScreen OR
    ((x>=0) & (x<=Cfg.ActualMaxX) & (y>=0) & (y<=Cfg.ActualMaxY)) THEN
      SYSTEM.PUT(
        SYSTEM.VAL(LONGINT, GrApp.Screen.pixels) + y*pitch + x*4, ink);
  END;
END PutActualPixel32NoLock;

PROCEDURE PutVirtualPixelLock (x, y: Coords);
VAR
  xActual, yActual, xTemp, xNext, yNext: Coords;
BEGIN
  xActual := x * Cfg.ActualWidth DIV Cfg.VirtualWidth;
  yActual := y * Cfg.ActualHeight DIV Cfg.VirtualHeight;
  xNext := (x + 1) * Cfg.ActualWidth DIV Cfg.VirtualWidth;
  yNext := (y + 1) * Cfg.ActualHeight DIV Cfg.VirtualHeight;
  IF Sdl.LockSurface(GrApp.Screen) # 0 THEN
    WHILE yActual # yNext DO
      xTemp := xActual;
      WHILE xTemp # xNext DO
        PutActualPixelNoLock(xTemp, yActual); INC(xTemp);
      END;
      INC(yActual);
    END;
    Sdl.UnlockSurface(GrApp.Screen);
  END;
END PutVirtualPixelLock;
(* ToDo: optimize with low-level access to pixels. *)
(* ToDo: optimize with check virtual and not actual coords. *)

PROCEDURE PutVirtualPixelNoLock (x, y: Coords);
VAR
  xActual, yActual, xTemp, xNext, yNext: Coords;
BEGIN
  xActual := x * Cfg.ActualWidth DIV Cfg.VirtualWidth;
  yActual := y * Cfg.ActualHeight DIV Cfg.VirtualHeight;
  xNext := (x + 1) * Cfg.ActualWidth DIV Cfg.VirtualWidth;
  yNext := (y + 1) * Cfg.ActualHeight DIV Cfg.VirtualHeight;
  WHILE yActual # yNext DO
    xTemp := xActual;
    WHILE xTemp # xNext DO
      PutActualPixelNoLock(xTemp, yActual); INC(xTemp);
    END;
    INC(yActual);
  END;
END PutVirtualPixelNoLock;

(*
(*
  AX POP  3$ 1+ , AL MOV ; Color
*)
  POP BX         ; BX = y
  MOV WORD ES: AX, ScaleY
  PUSH AX
  MUL BX         ; ScaleY * y
  MOV DH, DL
  MOV DL, AH     ; DX = ScaleY * y DIV 256
  POP AX         ; AX = ScaleY
  POP CX         ; CX = x
  PUSH DX
  INC BX         ; y + 1
  MUL BX         ; ScaleY * (y + 1)
  PUSH AX
  MOV WORD ES: AX, ScaleX
  PUSH AX
  MUL CX         ; ScaleX * x
  MOV BH, DL
  MOV BL, AH     ; BX = ScaleX * x DIV 256
  POP AX         ; ScaleX
  INC CX
  MUL CX         ; ScaleX * (x + 1)
  POP CX
  MOV CL, AH
  POP AX

1$: CMP AL, CH
  JE 5$
  PUSH BX
2$: CMP BL, CL
  JE 4$
  PUSH AX
  PUSH BX
  PUSH CX
(*
      AX, 1 SHL  AX, 1 SHL  AX, 1 SHL   AX, 1 SHL  CX, AX MOV
      AX, 1 SHL  AX, 1 SHL  AX, CX ADD  CL, BL MOV  BX, 1 SHR
      BX, 1 SHR  BX, 1 SHR  BX, AX ADD  CL, # 7 AND
      AH, # 80 MOV  AH, CL SHR  DX, # A000 MOV  DS, DX MOV
      DX, # 3CE MOV  AL, # 8 MOV  DX, AX OUT  DL, # C4 MOV  -->
          AX, # 0F02 MOV  DX, AX OUT  CL, CL XOR  [BX], CL XCHG
      3$: AH, # 0F MOV  DX, AX OUT  CL, # FF MOV  [BX], CL XCHG
*)
  CX POP
  BX POP
  AX POP
  INC BX
  JMP SHORT 2$
4$: POP BX
  INC AX
  JMP SHORT 1$
  5$: (* MOV AX, CS : MOV DS, AX : NEXT,  END-CODE  DECIMAL*)
*)

PROCEDURE Ink* (color: Color);
BEGIN
  ink := color;
END Ink;

PROCEDURE GetSign (x: Coords): Coords;
(* Argument sign. Result:
     -1 for negative,
      1 for positive and zero
*)
BEGIN
  IF x >= 0 THEN RETURN 1 END;
  RETURN -1
END GetSign;

PROCEDURE Line* (x1, y1, x2, y2: Coords);
VAR
  dx, dy, sdx, sdy, x, y, px, py: Coords;
BEGIN
  dx := x2 - x1;  dy := y2 - y1;
  sdx := GetSign(dx); sdy := GetSign(dy);
  dx := sdx * dx + 1; dy := sdy * dy + 1;
  x := 0; y := 0;
  px := x1; py := y1;
  IF dx >= dy THEN
    x := 0; WHILE x < dx DO
      Dot(px, py);
      INC(y, dy);
      IF y >= dx THEN
        DEC(y, dx); INC(py, sdy);
      END;
      INC(px, sdx); INC(x);
    END;
  ELSE
    y := 0; WHILE y < dy DO
      Dot(px, py);
      INC(x, dx);
      IF x >= dy THEN
        DEC(x, dy); INC(px, sdx);
      END;
      INC(py, sdy); INC(y);
    END;
  END;
END Line;

PROCEDURE Circle* (cx, cy, radius: Coords);
VAR
  x, y, rr, xx, yy: Coords;

  PROCEDURE Cursors;
  BEGIN
    Dot(cx+x, cy+y); Dot(cx-x, cy+y);
    Dot(cx+x, cy-y); Dot(cx-x, cy-y);
    Dot(cx+y, cy+x); Dot(cx-y, cy+x);
    Dot(cx+y, cy-x); Dot(cx-y, cy-x);
  END Cursors;

BEGIN
  x := radius; y := 0; rr := x*x; xx := rr-x; yy := 0;
  REPEAT
    Cursors; INC(yy, y+y+1); INC(y);
    IF xx > (rr-yy) THEN INC(xx, 1-x-x); DEC(x); Cursors END;
  UNTIL x < y;
END Circle;

BEGIN
  pitch := GrApp.Screen.pitch;
  CASE SYSTEM.VAL(CHAR, GrApp.Screen.format.BytesPerPixel) OF
  | 1X: (* Assuming 8-bpp *)
    PutActualPixelNoLock := PutActualPixel8NoLock;
    PutPixelNoLock := PutActualPixel8NoLock;
    IF GrApp.MustLock THEN
      Dot := PutActualPixel8Lock;
    ELSE
      Dot := PutActualPixel8NoLock;
    END;
  | 2X: (* Probably 15-bpp or 16-bpp *)
    PutActualPixelNoLock := PutActualPixel16NoLock;
    PutPixelNoLock := PutActualPixel16NoLock;
    IF GrApp.MustLock THEN
      Dot := PutActualPixel16Lock;
    ELSE
      Dot := PutActualPixel16NoLock;
    END;
  | 3X: (* Slow 24-bpp mode, usually not used *)
    PutActualPixelNoLock := PutActualPixel24NoLock;
    PutPixelNoLock := PutActualPixel24NoLock;
    IF GrApp.MustLock THEN
      Dot := PutActualPixel24Lock;
    ELSE
      Dot := PutActualPixel24NoLock;
    END;
  | 4X: (* Probably 32-bpp *)
    PutActualPixelNoLock := PutActualPixel32NoLock;
    PutPixelNoLock := PutActualPixel32NoLock;
    IF GrApp.MustLock THEN
      Dot := PutActualPixel32Lock;
    ELSE
      Dot := PutActualPixel32NoLock;
    END;
  ELSE END;
  IF (Cfg.ActualWidth # Cfg.VirtualWidth)
    OR (Cfg.ActualHeight # Cfg.VirtualHeight) THEN
      PutPixelNoLock := PutVirtualPixelNoLock;
      IF GrApp.MustLock THEN
        Dot := PutVirtualPixelLock;
      ELSE
        Dot := PutVirtualPixelNoLock;
      END;
  END;
END GrPixel.
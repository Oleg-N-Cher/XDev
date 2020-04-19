(*

  ADW-Modula-2 example Clock

  Portions Copyright © 1987-1990 Microsoft Corp.

  2014. Edited by Frank Schoonjans

  XDev Oberon port by Oleg N. Cher, 2015

*)

(***************************************************************************
 *                                                                         *
 *  PROGRAM   : Clock.c                                                    *
 *                                                                         *
 *  PURPOSE   : To give a demonstration on the use of a timer in a windows *
 *              application.                                               *
 *                                                                         *
 *  MACROS    : HourHandPos  - Computes the hour hand position based on    *
 *                             both the hour and minute values.            *
 *                                                                         *
 *              VertEquiv    - Computes the raster line equivalent to the  *
 *                             given pixel value.                          *
 *                                                                         *
 *              HorzEquiv    - Computes the pixel equivalent to the given  *
 *                             raster line value.                          *
 *                                                                         *
 *  FUNCTIONS : AboutProc    - Dialog function for the About Dialog.       *
 *                                                                         *
 *              ClockWndProc - Window function for the application.        *
 *                                                                         *
 *              CreateTools  - Creates brushes and pens to coincide with   *
 *                             the current system colors.                  *
 *                                                                         *
 *              DeleteTools  - Destroys the brushes and pens created by    *
 *                             CreateTools.                                *
 *                                                                         *
 *              ClockCreate  - Performs the necessary initialization for   *
 *                             drawing the clock correctly and gets the    *
 *                             initial time to be displayed by the clock.  *
 *                                                                         *
 *              ClockSize    - Resize the clock to the largest possible    *
 *                             circle that will fit in the client area.    *
 *                                                                         *
 *              ClockTimer   - Update the clock to reflect the most recent *
 *                             time.                                       *
 *                                                                         *
 *              ClockPaint   - Paint the clock to display the most recent  *
 *                             time.                                       *
 *                                                                         *
 *              DrawFace     - Draws the clock face.                       *
 *                                                                         *
 *              DrawHand     - Draws a thin hand with the specified brush  *
 *                             in the specified hand position.             *
 *                                                                         *
 *              DrawFatHand  - Draws a fat hand with the specified brush   *
 *                             in the specified hand position.             *
 *                                                                         *
 *              CircleClock  - Resizes clock rectangle to keep clock       *
 *                             circular.                                   *
 *                                                                         *
 *              WinMain      - Calls the initialization function, creates  *
 *                             the main application window, and enters the *
 *                             message loop.                               *
 *                                                                         *
 *              ClockInit    - Registers the application window class and  *
 *                             initializes the circle values for the clock *
 *                             face.                                       *
 *                                                                         *
 ***************************************************************************)

MODULE Clock; (*$MAIN*)

IMPORT SYSTEM, W := WinAPI, D := Delphi, Ignore;

CONST

    BUFLEN        = 30; (* name buffer length *)

    MAXDOTWIDTH   = 25; (* maximum hour-marking dot width  *)
    MINDOTWIDTH   = 2;  (* minimum hour-marking dot width  *)
    MINDOTHEIGHT  = 1;  (* minimum hour-marking dot height *)

    (* Defines for menu items *)
    IDM_ABOUT     = 1001;
    IDS_ABOUTMENU = 1;
    IDS_APPNAME   = 2;
    IDS_TOOMANY   = 4;

    (* hand and paint flags *)
    HHAND         = 1;
    MHAND         = 0;
    PAINTALL      = 0;
    HANDPAINT     = 1;

    (* timer interval when the clock window is ...  *)
    OPEN_TLEN     = 450;    (* ... open   (every second) *)
    ICON_TLEN     = 59000;  (* ... iconic (every minute) *)

    (* distance from the center of the clock to ... *)
    HOURSIDE      = 7;   (* ... either side of the hour hand   *)
    MINUTESIDE    = 5;   (* ... either side of the minute hand *)
    HOURTIP       = 65;  (* ... the tip of the hour hand       *)
    MINUTETIP     = 80;  (* ... the tip of the minute hand     *)
    SECONDTIP     = 80;  (* ... the tip of the second hand     *)
    HOURTAIL      = 15;  (* ... the tail of the hour hand      *)
    MINUTETAIL    = 20;  (* ... the tail of the minute hand    *)

    (* conversion factors *)
    CIRTABSCALE   = 8000; (* circle table values scale down value  *)
    MMPERDM       = 100;  (* millimeters per decimeter             *)

    (* number of hand positions on ... *)
    HANDPOSITIONS = 60;                    (* ... entire clock         *)
    SIDESHIFT     = (HANDPOSITIONS DIV 4); (* ...  90 degrees of clock *)
    TAILSHIFT     = (HANDPOSITIONS DIV 2); (* ... 180 degrees of clock *)

VAR
    bFirst  : BOOLEAN;  (* TRUE if this is the 1st instance; FALSE otherwise  *)
    TimerID : INTEGER;  (* number used for timer-id                           *)
    bIconic : BOOLEAN;  (* TRUE if clock is currently iconic; FALSE otherwise *)
    Instance: W.HINSTANCE;

TYPE
    TIME = RECORD
    hour    : INTEGER;
    minute  : INTEGER;
    second  : INTEGER;
    END;

    arrPOINT    = ARRAY 2*60 OF INTEGER;

CONST

    CirTabConst = arrPOINT
    (
         0,  -7999,      836,  -7956,
      1663,  -7825,     2472,  -7608,
      3253,  -7308,     3999,  -6928,
      4702,  -6472,     5353,  -5945,
      5945,  -5353,     6472,  -4702,
      6928,  -4000,     7308,  -3253,
      7608,  -2472,     7825,  -1663,
      7956,  -836,      8000,  0,
      7956,  836,       7825,  1663,
      7608,  2472,      7308,  3253,
      6928,  4000,      6472,  4702,
      5945,  5353,      5353,  5945,
      4702,  6472,      3999,  6928,
      3253,  7308,      2472,  7608,
      1663,  7825,      836,   7956,
         0,  7999,      -836,  7956,
      -1663,  7825,     -2472,  7608,
      -3253,  7308,     -4000,  6928,
      -4702,  6472,     -5353,  5945,
      -5945,  5353,     -6472,  4702,
      -6928,  3999,     -7308,  3253,
      -7608,  2472,     -7825,  1663,
      -7956,  836,      -7999,  0,
      -7956,  -836,     -7825,  -1663,
      -7608,  -2472,    -7308,  -3253,
      -6928,  -4000,    -6472,  -4702,
      -5945,  -5353,    -5353,  -5945,
      -4702,  -6472,    -3999,  -6928,
      -3253,  -7308,    -2472,  -7608,
      -1663,  -7825,    -836,  -7956
    );

VAR
    oTime   : TIME;             (* the time currently displayed on the clock          *)

    hbrForegnd  : W.HBRUSH;       (* foreground brush -- system window text color       *)
    hbrBackgnd  : W.HBRUSH;       (* background brush -- system window backbround color *)
    hpenForegnd : W.HPEN;         (* foreground pen   -- system window text color       *)
    hpenBackgnd : W.HPEN;         (* background pen   -- system window background color *)

    CirTab      : arrPOINT;       (* the circle table *)

    (* buffer for stringtable data *)
    szBuffer    : ARRAY BUFLEN+1 OF CHAR;

    ClockRect   : W.RECT;       (* rectangle that EXACTLY bounds the clock face       *)

    ClockRadius : INTEGER;      (* clock face radius                                  *)
    ClockCenter : W.POINT;      (* clock face center                                  *)

    HRes        : INTEGER;      (* width of the display (in pixels)                   *)
    VRes        : INTEGER;      (* height of the display (in raster lines)            *)

    AspectH     : INTEGER;      (* number of pixels per decimeter on the display      *)
    AspectV     : INTEGER;      (* number of raster lines per decimeter on the display*)


VAR
    Wnd     : W.HWND;
    mess    : W.MSG;
    Menu    : W.HMENU;
    nTime   : TIME;

    sysWidth    : INTEGER;  (* width of left and right frames                  *)
    sysHeight   : INTEGER;  (* height of caption bar and top and bottom frames *)
    width   : INTEGER;      (* width of entire clock window                    *)
    height  : INTEGER;      (* height of entire clock window                   *)
    pszTooMany  : W.ADRINT;

PROCEDURE GetTime (VAR t : TIME);
VAR
    dt  : W.SYSTEMTIME;
BEGIN
    W.GetLocalTime(@dt);
    t.hour := dt.wHour;
    t.minute := dt.wMinute;
    t.second := dt.wSecond;
END GetTime;

(***************************************************************************
 *                                                                         *
 *  MACRO    : HourHandPos (TIME)                                          *
 *                                                                         *
 *  PURPOSE  : Computes the hour hand position based on both the hour and  *
 *             minute values in the given time record.                     *
 *                                                                         *
 ***************************************************************************)

PROCEDURE HourHandPos(t : TIME) : INTEGER;
BEGIN
    IF t.hour < 12 THEN
        RETURN (t.hour*5) + (t.minute DIV 12);
    ELSE
        RETURN ((t.hour - 12)*5) + (t.minute DIV 12);
    END;
END HourHandPos;

(***************************************************************************
 *                                                                         *
 *  MACRO    : VertEquiv (int)                                             *
 *                                                                         *
 *  PURPOSE  : Computes the raster line (vertical) equivalent to the given *
 *             pixel (horizontal) value.                                   *
 *                                                                         *
 ***************************************************************************)
PROCEDURE VertEquiv(l : INTEGER) : INTEGER;
BEGIN
    RETURN l * AspectV DIV AspectH;
END VertEquiv;

(***************************************************************************
 *                                                                         *
 *  MACRO    : HorzEquiv (int)                                             *
 *                                                                         *
 *  PURPOSE  : Computes the pixel (horizontal) equivalent to the given     *
 *             raster line (vertical) value.                               *
 *                                                                         *
 ***************************************************************************)
PROCEDURE HorzEquiv(l : INTEGER) : INTEGER;
BEGIN
    RETURN l * AspectH DIV AspectV;
END HorzEquiv;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : CreateTools                                                *
 *                                                                         *
 *  PURPOSE  : Creates brushes and pens to coincide with the current       *
 *             system colors.                                              *
 *                                                                         *
 ***************************************************************************)
PROCEDURE CreateTools;
BEGIN
    hbrForegnd  := W.CreateSolidBrush(W.GetSysColor(W.COLOR_WINDOWTEXT));
    hbrBackgnd  := W.CreateSolidBrush(W.GetSysColor(W.COLOR_WINDOW));
    hpenForegnd := W.CreatePen(0, 1, W.GetSysColor(W.COLOR_WINDOWTEXT));
    hpenBackgnd := W.CreatePen(0, 1, W.GetSysColor(W.COLOR_WINDOW));
END CreateTools;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : DeleteTools                                                *
 *                                                                         *
 *  PURPOSE  : Destroys the brushes and pens created by CreateTools.       *
 *                                                                         *
 ***************************************************************************)
PROCEDURE DeleteTools;
BEGIN
  Ignore.Int( W.DeleteObject(hbrForegnd) );
  Ignore.Int( W.DeleteObject(hbrBackgnd) );
  Ignore.Int( W.DeleteObject(hpenForegnd) );
  Ignore.Int( W.DeleteObject(hpenBackgnd) );
END DeleteTools;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : ClockCreate                                                *
 *                                                                         *
 *  PURPOSE  : First, for drawing the clock, ClockCreate computes the      *
 *             aspect ratio and creates the necessary pens and brushes.    *
 *             Then, if this is the first instance of the app running,     *
 *             ClockCreate scales the circle table values according to the *
 *             aspect ratio. Finally, ClockCreate gets the initial time.   *
 *                                                                         *
 ***************************************************************************)
PROCEDURE ClockCreate;
VAR
    pos     : INTEGER; (* hand position index into the circle table *)
    vSize   : INTEGER; (* height of the display in millimeters      *)
    hSize   : INTEGER; (* width of the display in millimeters       *)
    dc      : W.HDC;
BEGIN
    (* Get display size in (pixels X raster lines) *)
    (* and in (millimeters X millimeters)          *)

    dc      := W.GetDC(0);
    VRes    := W.GetDeviceCaps(dc, W.VERTRES);
    HRes    := W.GetDeviceCaps(dc, W.HORZRES);
    vSize   := W.GetDeviceCaps(dc, W.VERTSIZE);
    hSize   := W.GetDeviceCaps(dc, W.HORZSIZE);
    Ignore.Int( W.ReleaseDC(0, dc) );

    (* Compute (raster lines / decimeter) and (pixels / decimeter) *)

    AspectV := (VRes * MMPERDM) DIV vSize;
    AspectH := (HRes * MMPERDM) DIV hSize;

    CreateTools;

    (* Scale cosines for aspect ratio if this is the first instance *)

    IF bFirst # FALSE THEN
        pos := 0;

        WHILE pos < HANDPOSITIONS DO
            CirTab[2*pos+1](*y*) := VertEquiv(CirTab[2*pos+1](*y*));
            INC(pos);
        END;
    END;

    GetTime(@oTime);
END ClockCreate;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : CircleClock (int, int)                                     *
 *                                                                         *
 *  PURPOSE  : Resizes the clock rectangle to keep the face circular.      *
 *                                                                         *
 ***************************************************************************)
PROCEDURE CircleClock(maxWidth, maxHeight : INTEGER);
VAR
    clockHeight : INTEGER; (* tallest height that will keep face circular *)
    clockWidth : INTEGER;  (* widest width that will keep face circular   *)
BEGIN
    IF maxWidth > HorzEquiv(maxHeight) THEN
        (* too wide -- decrease width to keep face circular *)

        clockWidth := HorzEquiv(maxHeight);
        ClockRect.left := ClockRect.left + ((maxWidth - clockWidth) DIV 2);
        ClockRect.right := ClockRect.left + clockWidth;

    ELSE
        (* too tall -- decrease height to keep face circular *)

        clockHeight := VertEquiv(maxWidth);
        ClockRect.top := ClockRect.top + ((maxHeight - clockHeight) DIV 2);
        ClockRect.bottom := ClockRect.top + clockHeight;
    END;
END CircleClock;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : ClockSize (HWND, int, int, WORD)                           *
 *                                                                         *
 *  PURPOSE  : Resize the clock to the largest possible circle that will   *
 *             fit in the client area. If switching from not iconic to     *
 *             iconic, alter the timer to update every minute.  And if     *
 *             switching back to non iconic, restore the timer to update   *
 *             every second.                                               *
 *                                                                         *
 ***************************************************************************)
PROCEDURE ClockSize(w : W.HWND;
            newWidth, newHeight : INTEGER;
            sizeType : INTEGER);
BEGIN

  (* Set ClockRect to bound the largest possible circle in the window *)
  Ignore.Int( W.SetRect(@ClockRect, 0, 0, newWidth, newHeight) );
  CircleClock(newWidth, newHeight);

  IF sizeType = W.SIZE_MINIMIZED THEN
    (* Update once every minute in the iconic state *)

    Ignore.Int( W.KillTimer(w, TimerID) );
    Ignore.Int( W.SetTimer(w, TimerID, ICON_TLEN, SYSTEM.VAL(W.TIMERPROC, 0)));
    bIconic := TRUE;
  ELSIF bIconic # FALSE THEN
    (* Update every second in the opened state (ignore tiling) *)

    Ignore.Int( W.KillTimer(w, TimerID) );
    Ignore.Int( W.SetTimer(w, TimerID, OPEN_TLEN, SYSTEM.VAL(W.TIMERPROC, 0)));
    bIconic := FALSE;
  END;
END ClockSize;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : DrawFace (HDC)                                             *
 *                                                                         *
 *  PURPOSE  : Draws the clock face.                                       *
 *                                                                         *
 ***************************************************************************)
PROCEDURE DrawFace(DC : W.HDC);
VAR
    pos         : INTEGER;  (* hand position index into the circle table *)
    dotHeight   : INTEGER;  (* height of the hour-marking dot            *)
    dotWidth    : INTEGER;  (* width of the hour-marking dot             *)
    dotCenter   : W.POINT;  (* center point of the hour-marking dot      *)
    rc          : W.RECT;
BEGIN
    (* Compute hour-marking dot width, height, and center point *)

    dotWidth := (MAXDOTWIDTH * (ClockRect.right - ClockRect.left)) DIV HRes;
    dotHeight := VertEquiv(dotWidth);

    IF dotHeight < MINDOTHEIGHT THEN
        dotHeight := MINDOTHEIGHT;
    END;

    IF dotWidth < MINDOTWIDTH THEN
        dotWidth := MINDOTWIDTH;
    END;

    dotCenter.x := dotWidth DIV 2;
    dotCenter.y := dotHeight DIV 2;

    (* Compute the clock center and radius *)

    Ignore.Int( W.InflateRect(@ClockRect, -dotCenter.y, -dotCenter.x) );

    ClockRadius := ((ClockRect.right - ClockRect.left) DIV 2);
    ClockCenter.x := ClockRect.left + ClockRadius;
    ClockCenter.y := ClockRect.top + ((ClockRect.bottom - ClockRect.top) DIV 2);

    Ignore.Int( W.InflateRect(@ClockRect, dotCenter.y, dotCenter.x) );

    (* Draw the large hour-marking dots and small minute-marking dots *)

    FOR pos := 0 TO HANDPOSITIONS-1 DO
        rc.top := (CirTab[2*pos+1](*y*) * ClockRadius) DIV CIRTABSCALE + ClockCenter.y;
        rc.left := (CirTab[2*pos](*x*) * ClockRadius) DIV CIRTABSCALE + ClockCenter.x;

        IF (pos MOD 5) # 0 THEN

            IF ((dotWidth > MINDOTWIDTH) & (dotHeight > MINDOTHEIGHT)) THEN
                (* Draw small minute-marking dot *)

                rc.right := rc.left + 1;
                rc.bottom := rc.top + 1;
                Ignore.Int( W.FillRect(DC, @rc, hbrForegnd) );
            END;

        ELSE
            (* Draw large hour-marking dot *)

            rc.right := rc.left + dotWidth;
            rc.bottom := rc.top + dotHeight;

            Ignore.Int( W.OffsetRect(@rc, -dotCenter.x, -dotCenter.y) );
            Ignore.Int( W.FillRect(DC, @rc, hbrForegnd) );
        END;
    END;
END DrawFace;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : DrawHand (HDC, int, HPEN, int, int)                        *
 *                                                                         *
 *  PURPOSE  : Draws a thin hand with the specified pen in the specified   *
 *             hand position.                                              *
 *                                                                         *
 ***************************************************************************)
PROCEDURE DrawHand(DC : W.HDC;
           pos : INTEGER;
           Pen : W.HPEN;
           scale : INTEGER;
           patMode : INTEGER);
VAR
    radius  : INTEGER;
    xr, yr  : INTEGER;
BEGIN
    (* scale length of hand *)

    radius := (ClockRadius * scale) DIV 100;
    (* set pattern mode for hand *)

    Ignore.Int( W.SetROP2(DC, patMode) );

    (* select pen for hand *)

    Ignore.Int( W.SelectObject(DC, Pen) );

    (* Draw thin hand *)

    xr := (CirTab[2*pos](*x*) * radius) DIV CIRTABSCALE;
    yr := (CirTab[2*pos+1](*y*) * radius) DIV CIRTABSCALE;

    Ignore.Int( W.MoveToEx(DC, ClockCenter.x, ClockCenter.y, @NIL) );
    Ignore.Int( W.LineTo(DC, ClockCenter.x + xr, ClockCenter.y + yr) );
END DrawHand;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : DrawFatHand (HDC, int, HPEN, BOOL)                         *
 *                                                                         *
 *  PURPOSE  : Draws a fat hand with the specified pen in the specified    *
 *             hand position.                                              *
 *                                                                         *
 ***************************************************************************)
PROCEDURE DrawFatHand(DC : W.HDC;
              pos : INTEGER;
              Pen : W.HPEN;
              whichHand : INTEGER);
VAR
    ptTip   : W.POINT;  (* coordinates for the tip of the hand        *)
    ptTail  : W.POINT;  (* coordinates for the tail of the hand       *)
    ptSide  : W.POINT;  (* coordinates for the side of the hand       *)
    index   : INTEGER;  (* position index into the circle table       *)
    scale   : INTEGER;  (* ClockRadius percentage to scale drawing to *)
    toPaint : INTEGER;
BEGIN
    (* set pattern mode for hand *)

    Ignore.Int( W.SetROP2(DC, 13) );

    (* select pen for hand *)

    Ignore.Int( W.SelectObject(DC, Pen) );

    (* compute coordinates for the side of the hand *)

    IF whichHand = HHAND THEN
        toPaint := HOURSIDE;
    ELSE
        toPaint := MINUTESIDE;
    END;

    scale := (ClockRadius * toPaint) DIV 100;
    index := (pos + SIDESHIFT) MOD HANDPOSITIONS;
    ptSide.y := (CirTab[2*index+1](*y*) * scale) DIV CIRTABSCALE;
    ptSide.x := (CirTab[2*index](*x*) * scale) DIV CIRTABSCALE;

    (* compute coordinates for the tip of the hand *)

    IF whichHand = HHAND THEN
        toPaint := HOURTIP
    ELSE
        toPaint := MINUTETIP;
    END;

    scale := (ClockRadius * toPaint) DIV 100;
    ptTip.y := (CirTab[2*pos+1](*y*) * scale) DIV CIRTABSCALE;
    ptTip.x := (CirTab[2*pos](*x*) * scale) DIV CIRTABSCALE;

    (* compute coordinates for the tail of the hand *)

    IF whichHand = HHAND THEN
        toPaint := HOURTAIL
    ELSE
        toPaint := MINUTETAIL;
    END;

    scale := (ClockRadius * toPaint) DIV 100;
    index := (pos + TAILSHIFT) MOD HANDPOSITIONS;
    ptTail.y := (CirTab[2*index+1](*y*) * scale) DIV CIRTABSCALE;
    ptTail.x := (CirTab[2*index](*x*) * scale) DIV CIRTABSCALE;

    (* Draw tip of hand *)
  Ignore.Int(
    W.MoveToEx(DC, ClockCenter.x + ptSide.x, ClockCenter.y + ptSide.y, @NIL));
  Ignore.Int(
    W.LineTo(DC, ClockCenter.x +  ptTip.x, ClockCenter.y +  ptTip.y));
  Ignore.Int(
    W.MoveToEx(DC, ClockCenter.x - ptSide.x, ClockCenter.y - ptSide.y, @NIL));
  Ignore.Int(
    W.LineTo(DC, ClockCenter.x +  ptTip.x, ClockCenter.y +  ptTip.y));

    (* Draw tail of hand *)

  Ignore.Int(
    W.MoveToEx(DC, ClockCenter.x + ptSide.x, ClockCenter.y + ptSide.y, @NIL));
  Ignore.Int(
    W.LineTo(DC, ClockCenter.x + ptTail.x, ClockCenter.y + ptTail.y));
  Ignore.Int(
    W.MoveToEx(DC, ClockCenter.x - ptSide.x, ClockCenter.y - ptSide.y, @NIL));
  Ignore.Int(
    W.LineTo(DC, ClockCenter.x + ptTail.x, ClockCenter.y + ptTail.y));
END DrawFatHand;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : ClockPaint (HWND, HDC, int)                                *
 *                                                                         *
 *  PURPOSE  : Paint the clock to display the most recent time.            *
 *                                                                         *
 ***************************************************************************)
PROCEDURE ClockPaint(dc : W.HDC; paintType : INTEGER);
VAR
    nTime : TIME;
BEGIN
    Ignore.Int( W.SetBkMode(dc, W.TRANSPARENT) );

    IF paintType = PAINTALL THEN
        (* Paint entire clock -- face and hands *)

        Ignore.Int( W.FillRect(dc, @ClockRect, hbrBackgnd) );
        DrawFace(dc);
        DrawFatHand(dc, HourHandPos(oTime), hpenForegnd, HHAND);
        DrawFatHand(dc, oTime.minute, hpenForegnd, MHAND);
        IF bIconic = FALSE THEN
            (* Erase old second hand *)

            DrawHand(dc, oTime.second, hpenBackgnd, SECONDTIP, W.R2_NOT);
        END;
    ELSIF paintType = HANDPAINT THEN
        GetTime(@nTime);

        IF ((bIconic = FALSE) & (nTime.second # oTime.second)) THEN
            (* Second has changed -- erase old second hand *)
            DrawHand(dc, oTime.second, hpenBackgnd, SECONDTIP, W.R2_NOT);
        END;

        IF ((nTime.minute # oTime.minute) OR (nTime.hour # oTime.hour)) THEN
            (* Hour and/or minute have changed -- update hands *)

            IF bIconic # FALSE THEN
                (* Erase old minute and hour hands *)

                DrawHand(dc, oTime.minute, hpenBackgnd, MINUTETIP, W.R2_COPYPEN);
                DrawHand(dc, HourHandPos(oTime), hpenBackgnd, HOURTIP, W.R2_COPYPEN);

                (* Draw new minute and hour hands *)

                DrawHand(dc, nTime.minute, hpenForegnd, MINUTETIP, W.R2_COPYPEN);
                DrawHand(dc, HourHandPos(nTime), hpenForegnd, HOURTIP, W.R2_COPYPEN);

            ELSE
                (* Erase old minute and hour fat hands *)

                DrawFatHand(dc, oTime.minute, hpenBackgnd, MHAND);
                DrawFatHand(dc, HourHandPos(oTime), hpenBackgnd, HHAND);

                (* Draw new minute and hour fat hands *)

                DrawFatHand(dc, nTime.minute, hpenForegnd, MHAND);
                DrawFatHand(dc, HourHandPos(nTime), hpenForegnd, HHAND);
            END;
        END;

        IF ((bIconic = FALSE) & (nTime.second # oTime.second)) THEN
            (* second has changed -- draw new second hand *)
            DrawHand(dc, nTime.second, hpenBackgnd, SECONDTIP, W.R2_NOT);
        END;

        (* Store most recent time *)

        oTime.minute := nTime.minute;
        oTime.hour   := nTime.hour;
        oTime.second := nTime.second;
    END;
END ClockPaint;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : ClockTimer (HWND)                                          *
 *                                                                         *
 *  PURPOSE  : Update the clock to reflect the most recent time.           *
 *                                                                         *
 ***************************************************************************)
PROCEDURE ClockTimer(w : W.HWND);
VAR
    nTime   : TIME;
    dc      : W.HDC;
BEGIN
    GetTime(@nTime);

    (* It's possible to change any part of the system at any time through *)
    (* the Control Panel. Check for any change in second, minute, or hour *)

    IF ((nTime.second # oTime.second) OR
        (nTime.minute # oTime.minute) OR
        (nTime.hour   # oTime.hour))
    THEN
        (* The time has changed -- update the clock *)
        dc := W.GetDC(w);
        ClockPaint(dc, HANDPAINT);
        Ignore.Int( W.ReleaseDC(w, dc) );
    END;
END ClockTimer;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : About (HWND, unsigned, WORD, LONG)                         *
 *                                                                         *
 *  PURPOSE  : Dialog function for the "About..." menu item dialog.        *
 *                                                                         *
 ***************************************************************************)

PROCEDURE [stdcall] AboutProc(hDlg : W.HWND;
           message : INTEGER;
           wParam : W.WPARAM;
           lParam : W.LPARAM) : W.PtrVoid;
BEGIN
(*
    UNREFERENCED_PARAMETER(wParam);
    UNREFERENCED_PARAMETER(lParam);
*)
    CASE message OF
    | W.WM_INITDIALOG:
    | W.WM_COMMAND   : Ignore.Int( W.EndDialog(hDlg, 1) );
    ELSE RETURN 0
    END;
    RETURN 1
END AboutProc;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : ClockWndProc (HWND, unsigned, WORD, LONG)                  *
 *                                                                         *
 *  PURPOSE  : Window function for the application.                        *
 *                                                                         *
 ***************************************************************************)
PROCEDURE [stdcall] ClockWndProc(wnd : W.HWND;
              message : INTEGER;
              wParam : W.WPARAM;
              lParam : W.LPARAM) : W.LRESULT;
VAR
    ps : W.PAINTSTRUCT;
    rc : W.RECT;
BEGIN
    CASE message OF
    | W.WM_SYSCOMMAND:
                    IF wParam = IDM_ABOUT THEN
                        (* Draw and handle messages for the "About..." Dialog *)
                        Ignore.Int( W.DialogBoxParam(Instance, SYSTEM.ADR("#1"), wnd, AboutProc, 0) );
                    ELSE
                        (* Perform the default window processing *)
                        RETURN W.DefWindowProc(wnd, message, wParam, lParam);
                    END;
    | W.WM_SIZE:
                    (* Resize clock based on window size and redraw *)
                    ClockSize(wnd, D.LoWord(SYSTEM.VAL(INTEGER, lParam)), D.HiWord(SYSTEM.VAL(INTEGER, lParam)), SYSTEM.VAL(INTEGER, wParam));
                    Ignore.Int( W.UpdateWindow(wnd) );
    | W.WM_DESTROY:
                    (* Destroy clock's timer and tools before exiting *)
                    Ignore.Int( W.KillTimer(wnd, TimerID) );
                    DeleteTools;
                    W.PostQuitMessage(0);
    | W.WM_PAINT:
                    (* Paint clock displaying current time *)
                    Ignore.Int( W.InvalidateRect(wnd, @NIL, SYSTEM.VAL(INTEGER, TRUE)) );
                    Ignore.Int( W.BeginPaint(wnd, @ps) );
                    ClockPaint(ps.hdc, PAINTALL);
                    Ignore.Int( W.EndPaint(wnd, @ps) );
    | W.WM_TIMECHANGE, W.WM_TIMER:
                    (* Update clock to display new time *)
                    ClockTimer(wnd);
    | W.WM_SYSCOLORCHANGE:
                    (* Change tools to coincide with system window colors *)
                    DeleteTools;
                    CreateTools;
    | W.WM_ERASEBKGND:
                    (* Paint over the entire client area *)
                    Ignore.Int( W.GetClientRect(wnd, @rc) );
                    Ignore.Int( W.FillRect(wParam, @rc, hbrBackgnd) );
    ELSE
                    (* Perform the default window processing *)
                    RETURN W.DefWindowProc(wnd, message, wParam, lParam)
    END;
    RETURN 0
END ClockWndProc;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : ClockInit ()                                               *
 *                                                                         *
 *  PURPOSE  : Registers the applicatoin windwo class and initializes the  *
 *             circle values for the clock face.                           *
 *                                                                         *
 ***************************************************************************)

PROCEDURE ClockInit() : BOOLEAN;
VAR
    clockClass  : W.WNDCLASS;
BEGIN
    clockClass.lpszClassName := SYSTEM.ADR(szBuffer);
    clockClass.hbrBackground := 0;
    clockClass.style         := W.CS_VREDRAW + W.CS_HREDRAW + W.CS_BYTEALIGNCLIENT;
    clockClass.hInstance     := Instance;
    clockClass.lpfnWndProc   := ClockWndProc;
    clockClass.hCursor       := W.LoadCursor(Instance, W.IDC_ARROW);
    clockClass.hIcon         := W.LoadIcon(Instance, 100);

    (* added in conversion from C *)

    clockClass.cbClsExtra   := 0;
    clockClass.cbWndExtra   := 0;
    clockClass.lpszMenuName := 0;

    IF W.RegisterClass(@clockClass) = 0 THEN
        (* Error registering class -- return *)
        RETURN FALSE;
    END;

    (* Load in pre-computed circle table cosine values from resource file *)
    CirTab := CirTabConst;

    RETURN TRUE;
END ClockInit;

BEGIN
    bFirst  := TRUE;   (* TRUE if this is the 1st instance; FALSE otherwise  *)
    TimerID := 1;      (* number used for timer-id                           *)
    bIconic := FALSE;  (* TRUE if clock is currently iconic; FALSE otherwise *)
    Instance := W.Instance();

    Ignore.Int( W.LoadString(W.Instance(), IDS_APPNAME, SYSTEM.ADR(szBuffer), BUFLEN) );

    IF W.PrevInstance() = 0 THEN
    (* First instance -- register window class *)
        IF ~ ClockInit() THEN
            HALT(1);
        END;
    ELSE
        (* Not first instance -- get circle table and reset bFirst flag *)
        bFirst := FALSE;
    END;

    ClockCreate;

    (* compute window height and width *)

    sysWidth  := W.GetSystemMetrics(W.SM_CXFRAME) * 2;
    sysHeight := W.GetSystemMetrics(W.SM_CYCAPTION) + (W.GetSystemMetrics(W.SM_CYFRAME) * 2);
    width := (HRes DIV 3) + sysWidth;
    height := VertEquiv(width) + sysHeight;

    Wnd := W.CreateWindowEx( {},
             SYSTEM.ADR(szBuffer),  (* class name      *)
             SYSTEM.ADR(szBuffer),  (* The window name *)
             W.WS_OVERLAPPEDWINDOW, (* window style    *)
             SYSTEM.VAL(INTEGER, W.CW_USEDEFAULT), (* use default positioning *)
             0,             (* y not used              *)
             width,         (* window width            *)
             height,        (* window height           *)
             0,             (* NULL parent handle      *)
             0,             (* NULL menu/child handle  *)
             W.Instance(),  (* program instance        *)
             0              (* NULL data structure ref.*)
           );

    GetTime(@nTime);
    GetTime(@oTime);
    WHILE ((nTime.second = oTime.second) &
       (nTime.minute = oTime.minute) &
       (nTime.hour   = oTime.hour) ) DO
       GetTime(@oTime);
    END;

    IF W.SetTimer(Wnd, TimerID, OPEN_TLEN, SYSTEM.VAL(W.TIMERPROC, 0)) = 0 THEN
        (* 16 public timers already in use -- post error and exit *)

        pszTooMany := W.GlobalLock(W.GlobalAlloc(W.GPTR, 40));
        Ignore.Int( W.LoadString(W.Instance(), IDS_TOOMANY, pszTooMany, 40) );

        Ignore.Int( W.MessageBox(0, pszTooMany, SYSTEM.ADR(szBuffer), W.MB_OK + W.MB_ICONHAND + W.MB_SYSTEMMODAL) );

        DeleteTools;
        HALT(1);
    END;

    (* Add the "About..." menu item to the bottom of the system menu *)

    Ignore.Int( W.LoadString(W.Instance(), IDS_ABOUTMENU, SYSTEM.ADR(szBuffer), BUFLEN) );
    Menu := W.GetSystemMenu(Wnd, 0);
    Ignore.Int( W.ChangeMenu(Menu, 0, SYSTEM.ADR(szBuffer), IDM_ABOUT, W.MF_APPEND + W.MF_STRING) );

    Ignore.Int( W.ShowWindow(Wnd, W.CmdShow()) );

    (* Process messages until program termination *)

    WHILE W.GetMessage(@mess, 0, 0, 0) # 0 DO
        Ignore.Int( W.TranslateMessage(@mess) );
        Ignore.Int( W.DispatchMessage(@mess) );
    END;

END Clock.

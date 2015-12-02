(*

	ADW-Modula-2 example Clock
	
	Portions Copyright © 1987-1990 Microsoft Corp.
	
	2014. Edited by Frank Schoonjans
	
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

MODULE Clock;
<*/NOWARN:F*>
<*/Resource:CLOCK.RES*>

IMPORT SysClock;

FROM SYSTEM IMPORT
    ADR, CAST, UNREFERENCED_PARAMETER;

FROM WIN32 IMPORT
    WORD, WPARAM, LPARAM, UINT, BOOL, POINT, RECT, INT_PTR,
    LRESULT,
    HMENU, HBRUSH, HPEN, HWND, HDC,
    GlobalLock, GlobalAlloc, GPTR;

FROM WINUSER IMPORT
    GetDC, ReleaseDC, OffsetRect, InflateRect, SetRect,
    InvalidateRect, GetClientRect, RegisterClass,
    MessageBox, GetSystemMenu, ChangeMenu, ShowWindow,
    GetMessage, TranslateMessage, DispatchMessage,
    LoadString, LoadCursor, LoadIcon, IDC_ARROW,
    FillRect, DefWindowProc, UpdateWindow, PostQuitMessage,
    KillTimer, SetTimer, DialogBox,
    BeginPaint, EndPaint, GetSystemMetrics,
    CreateWindow, GetSysColor, EndDialog,
    LOWORD, HIWORD,
    MB_OK, MB_ICONHAND, MB_SYSTEMMODAL,
    SIZE_MINIMIZED, COLOR_WINDOWTEXT, COLOR_WINDOW,
    SM_CXFRAME, SM_CYFRAME, SM_CYCAPTION,
    WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, MF_APPEND, MF_STRING,
    CS_VREDRAW, CS_HREDRAW, CS_BYTEALIGNCLIENT,
    WM_INITDIALOG, WM_COMMAND, WM_SYSCOMMAND, WM_SIZE, WM_DESTROY,
    WM_PAINT, WM_TIMECHANGE, WM_TIMER, WM_SYSCOLORCHANGE,
    WM_ERASEBKGND,
    WNDCLASS, TIMERPROC, MSG, PAINTSTRUCT;

FROM WINGDI IMPORT
    CreateSolidBrush, CreatePen, GetDeviceCaps,
    SetBkMode, MoveToEx, LineTo, SetROP2,
    R2_NOT, R2_COPYPEN,
    VERTRES, HORZRES, VERTSIZE, HORZSIZE, TRANSPARENT;

FROM WINX IMPORT
    DeletePen, DeleteBrush, SelectPen,
    NULL_HWND, NULL_HMENU, NIL_POINT, NIL_RECT, NULL_HBRUSH,
    NULL_HINSTANCE,
    Instance, PrevInstance, CmdShow;

TYPE

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

    (* timer interval when the clock window is ...            *)
    OPEN_TLEN     = 450;    (* ... open   (every second) *)
    ICON_TLEN     = 59000;  (* ... iconic (every minute) *)

    (* distance from the center of the clock to ...                 *)
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

    (* number of hand positions on ...                                     *)
    HANDPOSITIONS = 60;                    (* ... entire clock         *)
    SIDESHIFT     = (HANDPOSITIONS / 4); (* ...  90 degrees of clock *)
    TAILSHIFT     = (HANDPOSITIONS / 2); (* ... 180 degrees of clock *)

VAR
    bFirst  : BOOL = TRUE;   (* TRUE if this is the 1st instance; FALSE otherwise  *)
    TimerID : INTEGER = 1;   (* number used for timer-id                           *)
    bIconic : BOOL = FALSE;  (* TRUE if clock is currently iconic; FALSE otherwise *)

TYPE
    TIME = RECORD
    hour    : INTEGER;
    minute  : INTEGER;
    second  : INTEGER;
    END;

    arrPOINT    = ARRAY [0..60-1] OF POINT;

CONST

    CirTab = arrPOINT
    {
    {     0,  -7999},   {   836,  -7956},
    {  1663,  -7825},   {  2472,  -7608},
    {  3253,  -7308},   {  3999,  -6928},
    {  4702,  -6472},   {  5353,  -5945},
    {  5945,  -5353},   {  6472,  -4702},
    {  6928,  -4000},   {  7308,  -3253},
    {  7608,  -2472},   {  7825,  -1663},
    {  7956,  -836},    {  8000,  0},
    {  7956,  836}, {  7825,  1663},
    {  7608,  2472},    {  7308,  3253},
    {  6928,  4000},    {  6472,  4702},
    {  5945,  5353},    {  5353,  5945},
    {  4702,  6472},    {  3999,  6928},
    {  3253,  7308},    {  2472,  7608},
    {  1663,  7825},    {  836,  7956},
    {     0,  7999},   {  -836,  7956},
    {  -1663,  7825},   {  -2472,  7608},
    {  -3253,  7308},   {  -4000,  6928},
    {  -4702,  6472},   {  -5353,  5945},
    {  -5945,  5353},   {  -6472,  4702},
    {  -6928,  3999},   {  -7308,  3253},
    {  -7608,  2472},   {  -7825,  1663},
    {  -7956,  836},    {  -7999,  0},
    {  -7956,  -836},   {  -7825,  -1663},
    {  -7608,  -2472},  {  -7308,  -3253},
    {  -6928,  -4000},  {  -6472,  -4702},
    {  -5945,  -5353},  {  -5353,  -5945},
    {  -4702,  -6472},  {  -3999,  -6928},
    {  -3253,  -7308},  {  -2472,  -7608},
    {  -1663,  -7825},  {  -836,  -7956}
    };

VAR
    oTime   : TIME;             (* the time currently displayed on the clock          *)

    hbrForegnd  : HBRUSH;       (* foreground brush -- system window text color       *)
    hbrBackgnd  : HBRUSH;       (* background brush -- system window backbround color *)
    hpenForegnd : HPEN;         (* foreground pen   -- system window text color       *)
    hpenBackgnd : HPEN;         (* background pen   -- system window background color *)

    lpCirTab    :  POINTER TO arrPOINT;  (* Pointer to the circle table                        *)

    (* buffer for stringtable data *)
    szBuffer    : ARRAY [0..BUFLEN] OF CHAR;

    ClockRect   : RECT;         (* rectangle that EXACTLY bounds the clock face       *)

    ClockRadius : INTEGER;      (* clock face radius                                  *)
    ClockCenter : POINT;        (* clock face center                                  *)

    HRes        : INTEGER;      (* width of the display (in pixels)                   *)
    VRes        : INTEGER;      (* height of the display (in raster lines)            *)

    AspectH     : INTEGER;      (* number of pixels per decimeter on the display      *)
    AspectV     : INTEGER;      (* number of raster lines per decimeter on the display*)


VAR
    Wnd     : HWND;
    mess    : MSG;
    Menu    : HMENU;
    nTime   : TIME;

    sysWidth    : INTEGER;  (* width of left and right frames                  *)
    sysHeight   : INTEGER;  (* height of caption bar and top and bottom frames *)
    width   : INTEGER;      (* width of entire clock window                    *)
    height  : INTEGER;      (* height of entire clock window                   *)

    pszTooMany  : POINTER TO ARRAY[0..511] OF CHAR;

PROCEDURE GetTime(VAR t : TIME);
VAR
    dt  : SysClock.DateTime;
BEGIN
    SysClock.GetClock(dt);
    t.hour := dt.hour;
    t.minute := dt.minute;
    t.second := dt.second;
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
        RETURN (t.hour*5) + (t.minute / 12);
    ELSE
        RETURN ((t.hour - 12)*5) + (t.minute / 12);
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
    RETURN l * AspectV / AspectH;
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
    RETURN l * AspectH / AspectV;
END HorzEquiv;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : CreateTools ()                                              *
 *                                                                         *
 *  PURPOSE  : Creates brushes and pens to coincide with the current       *
 *             system colors.                                              *
 *                                                                         *
 ***************************************************************************)
PROCEDURE CreateTools;
BEGIN
    hbrForegnd  := CreateSolidBrush(GetSysColor(COLOR_WINDOWTEXT));
    hbrBackgnd  := CreateSolidBrush(GetSysColor(COLOR_WINDOW));
    hpenForegnd := CreatePen(0, 1, GetSysColor(COLOR_WINDOWTEXT));
    hpenBackgnd := CreatePen(0, 1, GetSysColor(COLOR_WINDOW));
END CreateTools;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : DeleteTools ()                                              *
 *                                                                         *
 *  PURPOSE  : Destroys the brushes and pens created by CreateTools.       *
 *                                                                         *
 ***************************************************************************)
PROCEDURE DeleteTools;
BEGIN
    DeleteBrush(hbrForegnd);
    DeleteBrush(hbrBackgnd);
    DeletePen(hpenForegnd);
    DeletePen(hpenBackgnd);
END DeleteTools;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : ClockCreate ()                                              *
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
    dc      : HDC;
BEGIN
    (* Get display size in (pixels X raster lines) *)
    (* and in (millimeters X millimeters)          *)

    dc      := GetDC(NULL_HWND);
    VRes    := GetDeviceCaps(dc, VERTRES);
    HRes    := GetDeviceCaps(dc, HORZRES);
    vSize   := GetDeviceCaps(dc, VERTSIZE);
    hSize   := GetDeviceCaps(dc, HORZSIZE);
    ReleaseDC(NULL_HWND, dc);

    (* Compute (raster lines / decimeter) and (pixels / decimeter) *)

    AspectV := (VRes * MMPERDM) / vSize;
    AspectH := (HRes * MMPERDM) / hSize;

    CreateTools();

    (* Scale cosines for aspect ratio if this is the first instance *)

    IF bFirst <> FALSE THEN
        pos := 0;

        WHILE pos < HANDPOSITIONS DO
            lpCirTab^[pos].y := VertEquiv(lpCirTab^[pos].y);
            INC(pos);
        END;
    END;

    GetTime(oTime);
END ClockCreate;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : CircleClock (int, int)                                      *
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
        ClockRect.left := ClockRect.left + ((maxWidth - clockWidth) / 2);
        ClockRect.right := ClockRect.left + clockWidth;

    ELSE
        (* too tall -- decrease height to keep face circular *)

        clockHeight := VertEquiv(maxWidth);
        ClockRect.top := ClockRect.top + ((maxHeight - clockHeight) / 2);
        ClockRect.bottom := ClockRect.top + clockHeight;
    END;
END CircleClock;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : ClockSize (HWND, int, int, WORD)                            *
 *                                                                         *
 *  PURPOSE  : Resize the clock to the largest possible circle that will   *
 *             fit in the client area. If switching from not iconic to     *
 *             iconic, alter the timer to update every minute.  And if     *
 *             switching back to non iconic, restore the timer to update   *
 *             every second.                                               *
 *                                                                         *
 ***************************************************************************)
PROCEDURE ClockSize(W : HWND;
            newWidth, newHeight : INTEGER;
            sizeType : WORD);
BEGIN

    (* Set ClockRect to bound the largest possible circle in the window *)
    SetRect(ClockRect, 0, 0, newWidth, newHeight);
    CircleClock(newWidth, newHeight);

    IF sizeType = SIZE_MINIMIZED THEN
        (* Update once every minute in the iconic state *)

        KillTimer(W, TimerID);
        SetTimer(W, TimerID, ICON_TLEN, CAST(TIMERPROC, 0));
        bIconic := TRUE;
    ELSIF bIconic <> FALSE THEN
        (* Update every second in the opened state (ignore tiling) *)

        KillTimer(W, TimerID);
        SetTimer(W, TimerID, OPEN_TLEN, CAST(TIMERPROC, 0));
        bIconic := FALSE;
    END;
END ClockSize;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : DrawFace (HDC)                                              *
 *                                                                         *
 *  PURPOSE  : Draws the clock face.                                       *
 *                                                                         *
 ***************************************************************************)
PROCEDURE DrawFace(DC : HDC);
VAR
    pos     : INTEGER;  (* hand position index into the circle table *)
    dotHeight   : INTEGER;  (* height of the hour-marking dot            *)
    dotWidth    : INTEGER;  (* width of the hour-marking dot             *)
    dotCenter   : POINT;    (* center point of the hour-marking dot      *)
    rc      : RECT;
BEGIN
    (* Compute hour-marking dot width, height, and center point *)

    dotWidth := (MAXDOTWIDTH * (ClockRect.right - ClockRect.left)) / HRes;
    dotHeight := VertEquiv(dotWidth);

    IF dotHeight < MINDOTHEIGHT THEN
        dotHeight := MINDOTHEIGHT;
    END;

    IF dotWidth < MINDOTWIDTH THEN
        dotWidth := MINDOTWIDTH;
    END;

    dotCenter.x := dotWidth / 2;
    dotCenter.y := dotHeight / 2;

    (* Compute the clock center and radius *)

    InflateRect(ClockRect, -dotCenter.y, -dotCenter.x);

    ClockRadius := ((ClockRect.right - ClockRect.left) / 2);
    ClockCenter.x := ClockRect.left + ClockRadius;
    ClockCenter.y := ClockRect.top + ((ClockRect.bottom - ClockRect.top) / 2);

    InflateRect(ClockRect, dotCenter.y, dotCenter.x);

    (* Draw the large hour-marking dots and small minute-marking dots *)

    FOR pos := 0 TO HANDPOSITIONS-1 DO
        rc.top := (lpCirTab^[pos].y * ClockRadius) / CIRTABSCALE + ClockCenter.y;
        rc.left := (lpCirTab^[pos].x * ClockRadius) / CIRTABSCALE + ClockCenter.x;

        IF (pos REM 5) <> 0 THEN

            IF ((dotWidth > MINDOTWIDTH) AND (dotHeight > MINDOTHEIGHT)) THEN
                (* Draw small minute-marking dot *)

                rc.right := rc.left + 1;
                rc.bottom := rc.top + 1;
                FillRect(DC, rc, hbrForegnd);
            END;

        ELSE
            (* Draw large hour-marking dot *)

            rc.right := rc.left + dotWidth;
            rc.bottom := rc.top + dotHeight;

            OffsetRect(rc, -dotCenter.x, -dotCenter.y);
            FillRect(DC, rc, hbrForegnd);
        END;
    END;
END DrawFace;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : DrawHand (HDC, int, HPEN, int, int)                         *
 *                                                                         *
 *  PURPOSE  : Draws a thin hand with the specified pen in the specified   *
 *             hand position.                                              *
 *                                                                         *
 ***************************************************************************)
PROCEDURE DrawHand(DC : HDC;
           pos : INTEGER;
           Pen : HPEN;
           scale : INTEGER;
           patMode : INTEGER);
VAR
    radius  : INTEGER;
    xr, yr  : INTEGER;
BEGIN
    (* scale length of hand *)

    radius := (ClockRadius * scale) / 100;
    (* set pattern mode for hand *)

    SetROP2(DC, patMode);

    (* select pen for hand *)

    SelectPen(DC, Pen);

    (* Draw thin hand *)

    xr := (lpCirTab^[pos].x * radius) / CIRTABSCALE;
    yr := (lpCirTab^[pos].y * radius) / CIRTABSCALE;

    MoveToEx(DC, ClockCenter.x, ClockCenter.y, NIL_POINT);
    LineTo(DC, ClockCenter.x + xr, ClockCenter.y + yr);
END DrawHand;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : DrawFatHand (HDC, int, HPEN, BOOL)                          *
 *                                                                         *
 *  PURPOSE  : Draws a fat hand with the specified pen in the specified    *
 *             hand position.                                              *
 *                                                                         *
 ***************************************************************************)
PROCEDURE DrawFatHand(DC : HDC;
              pos : INTEGER;
              Pen : HPEN;
              whichHand : WORD);
VAR
    ptTip   : POINT;    (* coordinates for the tip of the hand        *)
    ptTail  : POINT;    (* coordinates for the tail of the hand       *)
    ptSide  : POINT;    (* coordinates for the side of the hand       *)
    index   : INTEGER;  (* position index into the circle table       *)
    scale   : INTEGER;  (* ClockRadius percentage to scale drawing to *)
    toPaint : INTEGER;
BEGIN
    (* set pattern mode for hand *)

    SetROP2(DC, 13);

    (* select pen for hand *)

    SelectPen(DC, Pen);

    (* compute coordinates for the side of the hand *)

    IF whichHand = HHAND THEN
        toPaint := HOURSIDE;
    ELSE
        toPaint := MINUTESIDE;
    END;

    scale := (ClockRadius * toPaint) / 100;
    index := (pos + SIDESHIFT) REM HANDPOSITIONS;
    ptSide.y := (lpCirTab^[index].y * scale) / CIRTABSCALE;
    ptSide.x := (lpCirTab^[index].x * scale) / CIRTABSCALE;

    (* compute coordinates for the tip of the hand *)

    IF whichHand = HHAND THEN
        toPaint := HOURTIP
    ELSE
        toPaint := MINUTETIP;
    END;

    scale := (ClockRadius * toPaint) / 100;
    ptTip.y := (lpCirTab^[pos].y * scale) / CIRTABSCALE;
    ptTip.x := (lpCirTab^[pos].x * scale) / CIRTABSCALE;

    (* compute coordinates for the tail of the hand *)

    IF whichHand = HHAND THEN
        toPaint := HOURTAIL
    ELSE
        toPaint := MINUTETAIL;
    END;

    scale := (ClockRadius * toPaint) / 100;
    index := (pos + TAILSHIFT) REM HANDPOSITIONS;
    ptTail.y := (lpCirTab^[index].y * scale) / CIRTABSCALE;
    ptTail.x := (lpCirTab^[index].x * scale) / CIRTABSCALE;

    (* Draw tip of hand *)

    MoveToEx(DC, ClockCenter.x + ptSide.x, ClockCenter.y + ptSide.y, NIL_POINT);
    LineTo(DC, ClockCenter.x +  ptTip.x, ClockCenter.y +  ptTip.y);
    MoveToEx(DC, ClockCenter.x - ptSide.x, ClockCenter.y - ptSide.y, NIL_POINT);
    LineTo(DC, ClockCenter.x +  ptTip.x, ClockCenter.y +  ptTip.y);

    (* Draw tail of hand *)

    MoveToEx(DC, ClockCenter.x + ptSide.x, ClockCenter.y + ptSide.y, NIL_POINT);
    LineTo(DC, ClockCenter.x + ptTail.x, ClockCenter.y + ptTail.y);
    MoveToEx(DC, ClockCenter.x - ptSide.x, ClockCenter.y - ptSide.y, NIL_POINT);
    LineTo(DC, ClockCenter.x + ptTail.x, ClockCenter.y + ptTail.y);
END DrawFatHand;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : ClockPaint (HWND, HDC, int)                                 *
 *                                                                         *
 *  PURPOSE  : Paint the clock to display the most recent time.            *
 *                                                                         *
 ***************************************************************************)
PROCEDURE ClockPaint(dc : HDC; paintType : INTEGER);
VAR
    nTime : TIME;
BEGIN
    SetBkMode(dc, TRANSPARENT);

    IF paintType = PAINTALL THEN
        (* Paint entire clock -- face and hands *)

        FillRect(dc, ClockRect, hbrBackgnd);
        DrawFace(dc);
        DrawFatHand(dc, HourHandPos(oTime), hpenForegnd, HHAND);
        DrawFatHand(dc, oTime.minute, hpenForegnd, MHAND);
        IF bIconic = FALSE THEN
            (* Erase old second hand *)

            DrawHand(dc, oTime.second, hpenBackgnd, SECONDTIP, R2_NOT);
        END;
    ELSIF paintType = HANDPAINT THEN
        GetTime(nTime);

        IF ((bIconic = FALSE) AND (nTime.second <> oTime.second)) THEN
            (* Second has changed -- erase old second hand *)
            DrawHand(dc, oTime.second, hpenBackgnd, SECONDTIP, R2_NOT);
        END;

        IF ((nTime.minute <> oTime.minute) OR (nTime.hour <> oTime.hour)) THEN
            (* Hour and/or minute have changed -- update hands *)

            IF bIconic <> FALSE THEN
                (* Erase old minute and hour hands *)

                DrawHand(dc, oTime.minute, hpenBackgnd, MINUTETIP, R2_COPYPEN);
                DrawHand(dc, HourHandPos(oTime), hpenBackgnd, HOURTIP, R2_COPYPEN);

                (* Draw new minute and hour hands *)

                DrawHand(dc, nTime.minute, hpenForegnd, MINUTETIP, R2_COPYPEN);
                DrawHand(dc, HourHandPos(nTime), hpenForegnd, HOURTIP, R2_COPYPEN);

            ELSE
                (* Erase old minute and hour fat hands *)

                DrawFatHand(dc, oTime.minute, hpenBackgnd, MHAND);
                DrawFatHand(dc, HourHandPos(oTime), hpenBackgnd, HHAND);

                (* Draw new minute and hour fat hands *)

                DrawFatHand(dc, nTime.minute, hpenForegnd, MHAND);
                DrawFatHand(dc, HourHandPos(nTime), hpenForegnd, HHAND);
            END;
        END;

        IF ((bIconic = FALSE) AND (nTime.second <> oTime.second)) THEN
            (* second has changed -- draw new second hand *)
            DrawHand(dc, nTime.second, hpenBackgnd, SECONDTIP, R2_NOT);
        END;

        (* Store most recent time *)

        oTime.minute := nTime.minute;
        oTime.hour   := nTime.hour;
        oTime.second := nTime.second;
    END;
END ClockPaint;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : ClockTimer (HWND)                                           *
 *                                                                         *
 *  PURPOSE  : Update the clock to reflect the most recent time.           *
 *                                                                         *
 ***************************************************************************)
PROCEDURE ClockTimer(W : HWND);
VAR
    nTime   : TIME;
    dc      : HDC;
BEGIN
    GetTime(nTime);

    (* It's possible to change any part of the system at any time through *)
    (* the Control Panel. Check for any change in second, minute, or hour *)

    IF ((nTime.second <> oTime.second) OR
        (nTime.minute <> oTime.minute) OR
        (nTime.hour   <> oTime.hour))
    THEN
        (* The time has changed -- update the clock *)
        dc := GetDC(W);
        ClockPaint(dc, HANDPAINT);
        ReleaseDC(W, dc);
    END;
END ClockTimer;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : About (HWND, unsigned, WORD, LONG)                          *
 *                                                                         *
 *  PURPOSE  : Dialog function for the "About..." menu item dialog.        *
 *                                                                         *
 ***************************************************************************)

PROCEDURE AboutProc(hDlg : HWND;
           message : UINT;
           wParam : WPARAM;
           lParam : LPARAM) : INT_PTR [EXPORT, OSCall];
BEGIN
    UNREFERENCED_PARAMETER(wParam);
    UNREFERENCED_PARAMETER(lParam);

    CASE message OF
    | WM_INITDIALOG:
    | WM_COMMAND   : EndDialog(hDlg, 1);
    ELSE RETURN 0;
    END;
    RETURN 1;
END AboutProc;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : ClockWndProc (HWND, unsigned, WORD, LONG)                   *
 *                                                                         *
 *  PURPOSE  : Window function for the application.                        *
 *                                                                         *
 ***************************************************************************)
PROCEDURE ClockWndProc(wnd : HWND;
              message : UINT;
              wParam : WPARAM;
              lParam : LPARAM) : LRESULT [EXPORT, OSCall];
VAR
    ps : PAINTSTRUCT;
    rc : RECT;
BEGIN
    CASE message OF
    | WM_SYSCOMMAND:
                    IF wParam = IDM_ABOUT THEN
                        (* Draw and handle messages for the "About..." Dialog *)
                        DialogBox(Instance, "#1", wnd, AboutProc);
                    ELSE
                        (* Perform the default window processing *)
                        RETURN DefWindowProc(wnd, message, wParam, lParam);
                    END;
    | WM_SIZE:
                    (* Resize clock based on window size and redraw *)
                    ClockSize(wnd, LOWORD(lParam), HIWORD(lParam), wParam);
                    UpdateWindow(wnd);
    | WM_DESTROY:
                    (* Destroy clock's timer and tools before exiting *)
                    KillTimer(wnd, TimerID);
                    DeleteTools();
                    PostQuitMessage(0);
    | WM_PAINT:
                    (* Paint clock displaying current time *)
                    InvalidateRect(wnd, NIL_RECT, TRUE);
                    BeginPaint(wnd, ps);
                    ClockPaint(ps.hdc, PAINTALL);
                    EndPaint(wnd, ps);
    | WM_TIMECHANGE, WM_TIMER:
                    (* Update clock to display new time *)
                    ClockTimer(wnd);
    | WM_SYSCOLORCHANGE:
                    (* Change tools to coincide with system window colors *)
                    DeleteTools();
                    CreateTools();
    | WM_ERASEBKGND:
                    (* Paint over the entire client area *)
                    GetClientRect(wnd, rc);
                    FillRect(CAST(HDC, wParam), rc, hbrBackgnd);
    ELSE
                    (* Perform the default window processing *)
                    RETURN DefWindowProc(wnd, message, wParam, lParam);
    END;
    RETURN 0;
END ClockWndProc;

(***************************************************************************
 *                                                                         *
 *  PROCEDURE : ClockInit ()                                                *
 *                                                                         *
 *  PURPOSE  : Registers the applicatoin windwo class and initializes the  *
 *             circle values for the clock face.                           *
 *                                                                         *
 ***************************************************************************)

PROCEDURE ClockInit() : BOOLEAN;
VAR
    clockClass  : WNDCLASS;
BEGIN
    clockClass.lpszClassName := ADR(szBuffer);
    clockClass.hbrBackground := NULL_HBRUSH;
    clockClass.style         := CS_VREDRAW + CS_HREDRAW + CS_BYTEALIGNCLIENT;
    clockClass.hInstance     := Instance;
    clockClass.lpfnWndProc   := ClockWndProc;
    clockClass.hCursor       := LoadCursor(Instance, IDC_ARROW^);
    clockClass.hIcon         := LoadIcon(Instance, 'Clock');

    (* added in conversion from C *)

    clockClass.cbClsExtra   := 0;
    clockClass.cbWndExtra   := 0;
    clockClass.lpszMenuName := NIL;

    IF RegisterClass(clockClass) = 0 THEN
        (* Error registering class -- return *)
        RETURN FALSE;
    END;

    (* Load in pre-computed circle table cosine values from resource file *)
    lpCirTab := ADR(CirTab);

    RETURN TRUE;
END ClockInit;

BEGIN

    LoadString(Instance, IDS_APPNAME, szBuffer, BUFLEN);

    IF PrevInstance = NULL_HINSTANCE THEN
    (* First instance -- register window class *)
        IF NOT ClockInit() THEN
            HALT(1);
        END;
    ELSE
        (* Not first instance -- get circle table and reset bFirst flag *)
        bFirst := FALSE;
    END;

    ClockCreate();

    (* compute window height and width *)

    sysWidth  := GetSystemMetrics(SM_CXFRAME) * 2;
    sysHeight := GetSystemMetrics(SM_CYCAPTION) + (GetSystemMetrics(SM_CYFRAME) * 2);
    width := (HRes / 3) + sysWidth;
    height := VertEquiv(width) + sysHeight;

    Wnd := CreateWindow( szBuffer,  (* class name              *)
             szBuffer,  (* The window name         *)
             WS_OVERLAPPEDWINDOW, (* window style            *)
             CW_USEDEFAULT, (* use default positioning *)
             0,             (* y not used              *)
             width,         (* window width            *)
             height,        (* window height           *)
             NULL_HWND,     (* NULL parent handle      *)
             NULL_HMENU,    (* NULL menu/child handle  *)
             Instance,      (* program instance        *)
             NIL        (* NULL data structure ref.*)
               );

    GetTime(nTime);
    GetTime(oTime);
    WHILE ((nTime.second = oTime.second) AND
       (nTime.minute = oTime.minute) AND
       (nTime.hour   = oTime.hour) ) DO
        GetTime(oTime);
    END;

    IF SetTimer(Wnd, TimerID, OPEN_TLEN, CAST(TIMERPROC, 0)) = 0 THEN
        (* 16 public timers already in use -- post error and exit *)

        pszTooMany := GlobalLock(GlobalAlloc(GPTR, 40));
        LoadString(Instance, IDS_TOOMANY, pszTooMany^, 40);

        MessageBox(NULL_HWND, pszTooMany^, szBuffer, MB_OK + MB_ICONHAND + MB_SYSTEMMODAL);

        DeleteTools();
        HALT(1);
    END;

    (* Add the "About..." menu item to the bottom of the system menu *)

    LoadString(Instance, IDS_ABOUTMENU, szBuffer, BUFLEN);
    Menu := GetSystemMenu(Wnd, FALSE);
    ChangeMenu(Menu, 0, szBuffer, IDM_ABOUT, MF_APPEND + MF_STRING);

    ShowWindow(Wnd, CmdShow);

    (* Process messages until program termination *)

    WHILE GetMessage(mess, NULL_HWND, 0, 0) DO
        TranslateMessage(mess);
        DispatchMessage(mess);
    END;

END Clock.

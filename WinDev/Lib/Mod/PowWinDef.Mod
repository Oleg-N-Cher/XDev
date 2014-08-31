(******************************************************************************)
(*                                                                            *)
(**)                        MODULE PowWinDef;                              (**)
(*                                                                            *)
(******************************************************************************)
(* Copyright (c) 1993; Robinson Associates                                    *)
(*                     Red Lion House                                         *)
(*                     St Mary's Street                                       *)
(*                     PAINSWICK                                              *)
(*                     Glos                                                   *)
(*                     GL6  6QR                                               *)
(*                     Tel:    (+44) (0)1452 813 699                          *)
(*                     Fax:    (+44) (0)1452 812 912                          *)
(*                     e-Mail: Oberon@robinsons.co.uk                         *)
(******************************************************************************)
(*  06-0§-1997 rel. 1.1 by Christian Wohlfahrtstaetter                        *)
(******************************************************************************)
(*                                                                            *)
(* windef.h -- Basic Windows Type Definitions                                 *)
(******************************************************************************)

IMPORT SYSTEM;

CONST 
  WINVER*= 400H;
  MAX_PATH*= 260;
  False*= 0;  (* TRUE & FALSE allready declared in Oberon 2.0 *)
  True*= 1;
  NULL* = 0;
(*  mode selections for the device mode function  *) 
  DM_UPDATE*= 1;
  DM_OUT_DEFAULT*= DM_UPDATE;
  DM_COPY*= 2;
  DM_OUT_BUFFER*= DM_COPY;
  DM_PROMPT*= 4;
  DM_IN_PROMPT*= DM_PROMPT;
  DM_MODIFY*= 8;
  DM_IN_BUFFER*= DM_MODIFY;

(*  device capabilities indices  *)
  DC_FIELDS*= 1;
  DC_PAPERS*= 2;
  DC_PAPERSIZE*= 3;
  DC_MINEXTENT*= 4;
  DC_MAXEXTENT*= 5;
  DC_BINS*= 6;
  DC_DUPLEX*= 7;
  DC_SIZE*= 8;
  DC_EXTRA*= 9;
  DC_VERSION*= 10;
  DC_DRIVER*= 11;
  DC_BINNAMES*= 12;
  DC_ENUMRESOLUTIONS*= 13;
  DC_FILEDEPENDENCIES*= 14;
  DC_TRUETYPE*= 15;
  DC_PAPERNAMES*= 16;
  DC_ORIENTATION*= 17;
  DC_COPIES*= 18;

  HFILE_ERROR*= -1;

(*                                                                        *)
(*  * BASETYPES is defined in ntdef.h if these types are already defined  *)
(*                                                                        *)

TYPE 
  ULONG*= INTEGER;
  PULONG*= INTEGER;
  USHORT*= SHORTINT;
  PUSHORT*= INTEGER;
  UCHAR*= CHAR;
  PUCHAR*= INTEGER;
  PSZ*= INTEGER;   (* pointer to char *)
  DWORD*= INTEGER;
  BOOL*= INTEGER;
  BYTE*= CHAR;
  INT*= INTEGER;
  WORD*= SHORTINT;
  PFLOAT*= INTEGER;  (* pointer to real*)
  PBOOL*= INTEGER;  (*pointer to bool*)
  LPBOOL*= PBOOL;
  PBYTE*= INTEGER;
  LPBYTE*= INTEGER;
  PINT*= INTEGER;
  LPINT*= INTEGER;
  PWORD*= INTEGER;
  LPWORD*= INTEGER;
  LPLONG*= INTEGER;
  PDWORD*= INTEGER;
  LPDWORD*= INTEGER;
  LPVOID*= INTEGER; (*SYSTEM.ADDRESS;*)    (* ???? *)
  LPCVOID*= INTEGER; (*SYSTEM.ADDRESS; *)
  UINT*= INTEGER;
  PUINT*= INTEGER;
  WCHAR* = SHORTINT;
  (*  added for oberon   *)
  LP* = INTEGER;
  PSTR* = INTEGER;
  LPSTR* = INTEGER;
  LPWSTR* = INTEGER;
  LPCSTR* = INTEGER;
  LPCWSTR* = INTEGER;
(* #ifndef NT_INCLUDED     *)
(* #include <winnt.h>      *)
(* #endif  NT_INCLUDED     *)
(*  Types use for passing & returning polymorphic values  *)

  WPARAM*= INTEGER;
  LPARAM*= INTEGER;
  LRESULT*= INTEGER;


(* Macros
<* IF __GEN_C__ THEN *>
(* H2D: this procedure corresponds to a macro. *)
PROCEDURE [_APICALL] max ( a, b: ARRAY OF BYTE );
<* ELSE *>
PROCEDURE [_APICALL]  / max ( a, b: ARRAY OF BYTE );
<* END *>
<* IF __GEN_C__ THEN *>
(* H2D: this procedure corresponds to a macro. *)
PROCEDURE [_APICALL] min ( a, b: ARRAY OF BYTE );
<* ELSE *>
PROCEDURE [_APICALL]  / min ( a, b: ARRAY OF BYTE );
<* END *>
<* IF __GEN_C__ THEN *>
(* H2D: this procedure corresponds to a macro. *)
PROCEDURE [_APICALL] MAKEWORD ( a, b: ARRAY OF BYTE );
<* ELSE *>
PROCEDURE [_APICALL]  / MAKEWORD ( a, b: ARRAY OF BYTE );
<* END *>
<* IF __GEN_C__ THEN *>
(* H2D: this procedure corresponds to a macro. *)
PROCEDURE [_APICALL] MAKELONG ( a, b: ARRAY OF BYTE );
<* ELSE *>
PROCEDURE [_APICALL]  / MAKELONG ( a, b: ARRAY OF BYTE );
<* END *>
<* IF __GEN_C__ THEN *>
(* H2D: this procedure corresponds to a macro. *)
PROCEDURE [_APICALL] LOWORD ( l: ARRAY OF BYTE );
<* ELSE *>
PROCEDURE [_APICALL]  / LOWORD ( l: ARRAY OF BYTE );
<* END *>
<* IF __GEN_C__ THEN *>
(* H2D: this procedure corresponds to a macro. *)
PROCEDURE [_APICALL] HIWORD ( l: ARRAY OF BYTE );
<* ELSE *>
PROCEDURE [_APICALL]  / HIWORD ( l: ARRAY OF BYTE );
<* END *>
<* IF __GEN_C__ THEN *>
(* H2D: this procedure corresponds to a macro. *)
PROCEDURE [_APICALL] LOBYTE ( w: ARRAY OF BYTE );
<* ELSE *>
PROCEDURE [_APICALL]  / LOBYTE ( w: ARRAY OF BYTE );
<* END *>
<* IF __GEN_C__ THEN *>
(* H2D: this procedure corresponds to a macro. *)
PROCEDURE [_APICALL] HIBYTE ( w: ARRAY OF BYTE );
<* ELSE *>
PROCEDURE [_APICALL]  / HIBYTE ( w: ARRAY OF BYTE );
<* END *>
*)
 
  HANDLE*= INTEGER;
  HWND*= INTEGER;
  HHOOK*= INTEGER;
  ATOM*= SHORTINT;
  SPHANDLE*= INTEGER;                   (*near  pointer *)
  LPHANDLE*= INTEGER;                   (*far  pointer *)
  HGLOBAL*= INTEGER;
  HLOCAL*= INTEGER;
  GLOBALHANDLE*= INTEGER;
  LOCALHANDLE*= INTEGER;

  FARPROC*= PROCEDURE (*[_APICALL]*)(): INTEGER;
  NEARPROC*= PROCEDURE (*[_APICALL]*)(): INTEGER;
  PROC*= PROCEDURE (*[_APICALL]*)(): INTEGER;

  HGDIOBJ*= INTEGER;
  HACCEL*= INTEGER;
  HBITMAP*= INTEGER;
  HBRUSH*= INTEGER;
  HCOLORSPACE*= INTEGER;
  HDC*= INTEGER;
  HGLRC*= INTEGER;                     (*  OpenGL *)
  HDESK*= INTEGER;
  HENHMETAFILE*= INTEGER;
  HFONT*= INTEGER;
  HICON*= INTEGER;
  HMENU*= INTEGER;
  HMETAFILE*= INTEGER;
  HINSTANCE*= INTEGER;
  HMODULE*= INTEGER;                   (*  HMODULEs can be used in place of HINSTANCEs  *)
  HPALETTE*= INTEGER;
  HPEN*= INTEGER;
  HRGN*= INTEGER;
  HRSRC*= INTEGER;
  HSTR*= INTEGER;
  HTASK*= INTEGER;
  HWINSTA*= INTEGER;
  HKL*= INTEGER;
  HFILE*= INTEGER;
  HCURSOR*= INTEGER;                   (*  HICONs & HCURSORs are polymorphic  *)
  COLORREF*= INTEGER;
  LPCOLORREF*= PULONG;
  
  RECT*= RECORD
    left* : INTEGER;
    top*  : INTEGER;
    right*: INTEGER;
    bottom*:INTEGER;
  END;
    
  PRECT*= POINTER TO RECT;
  NPRECT*= POINTER TO RECT;
  LPRECT*= POINTER TO RECT;
  LPCRECT*= LPRECT;

(*  rcl  *)

  RECTL*= RECORD
    left* : INTEGER;
    top*  : INTEGER;
    right*: INTEGER;
    bottom*: INTEGER;
  END;

  PRECTL*= POINTER TO RECTL;
  LPRECTL*= POINTER TO RECTL;
  LPCRECTL*= POINTER TO RECTL;

  POINT*= RECORD
    x*: INTEGER;
    y*: INTEGER;
  END;
    
  PPOINT*= POINTER TO POINT;
  NPPOINT*= POINTER TO POINT;
  LPPOINT*= POINTER TO POINT;

(*  ptl   *)

  POINTL*= RECORD
    x*: INTEGER;
    y*: INTEGER;
  END;

  PPOINTL*= POINTER TO POINTL;

  SIZE*= RECORD
    cx*: INTEGER;
    cy*: INTEGER;
  END;

  PSIZE*= POINTER TO SIZE;
  LPSIZE*= POINTER TO SIZE;

  SIZEL*=  RECORD
    cx*: INTEGER;
    cy*: INTEGER;
  END;

  PSIZEL*= POINTER TO SIZEL;
  LPSIZEL*= POINTER TO SIZEL;

  POINTS*= RECORD
    x*: SHORTINT;
    y*: SHORTINT;
  END;

  PPOINTS*= POINTER TO POINTS;
  LPPOINTS*= POINTER TO POINTS;

PROCEDURE- _init* "/*-noinit*/";

END PowWinDef.

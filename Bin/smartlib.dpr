{$APPTYPE CONSOLE}
PROGRAM smartlib;

USES Windows, KOL;

{$R *.RES}

CONST
  HeadDivisor1 = '/*='; HeadDivisor2 = '=*/';
  BodyDivisor1 = '/*-'; BodyDivisor2 = '-*/';

(*================================ StrLib.pas ================================*)
CONST
  AnsiLowCaseLookup: Array[AnsiChar] of AnsiChar = (
    #$00, #$01, #$02, #$03, #$04, #$05, #$06, #$07,
    #$08, #$09, #$0A, #$0B, #$0C, #$0D, #$0E, #$0F,
    #$10, #$11, #$12, #$13, #$14, #$15, #$16, #$17,
    #$18, #$19, #$1A, #$1B, #$1C, #$1D, #$1E, #$1F,
    #$20, #$21, #$22, #$23, #$24, #$25, #$26, #$27,
    #$28, #$29, #$2A, #$2B, #$2C, #$2D, #$2E, #$2F,
    #$30, #$31, #$32, #$33, #$34, #$35, #$36, #$37,
    #$38, #$39, #$3A, #$3B, #$3C, #$3D, #$3E, #$3F,
    #$40, #$61, #$62, #$63, #$64, #$65, #$66, #$67,
    #$68, #$69, #$6A, #$6B, #$6C, #$6D, #$6E, #$6F,
    #$70, #$71, #$72, #$73, #$74, #$75, #$76, #$77,
    #$78, #$79, #$7A, #$5B, #$5C, #$5D, #$5E, #$5F,
    #$60, #$61, #$62, #$63, #$64, #$65, #$66, #$67,
    #$68, #$69, #$6A, #$6B, #$6C, #$6D, #$6E, #$6F,
    #$70, #$71, #$72, #$73, #$74, #$75, #$76, #$77,
    #$78, #$79, #$7A, #$7B, #$7C, #$7D, #$7E, #$7F,
    #$80, #$81, #$82, #$83, #$84, #$85, #$86, #$87,
    #$88, #$89, #$8A, #$8B, #$8C, #$8D, #$8E, #$8F,
    #$90, #$91, #$92, #$93, #$94, #$95, #$96, #$97,
    #$98, #$99, #$9A, #$9B, #$9C, #$9D, #$9E, #$9F,
    #$A0, #$A1, #$A2, #$A3, #$A4, #$A5, #$A6, #$A7,
    #$A8, #$A9, #$AA, #$AB, #$AC, #$AD, #$AE, #$AF,
    #$B0, #$B1, #$B2, #$B3, #$B4, #$B5, #$B6, #$B7,
    #$B8, #$B9, #$BA, #$BB, #$BC, #$BD, #$BE, #$BF,
    #$C0, #$C1, #$C2, #$C3, #$C4, #$C5, #$C6, #$C7,
    #$C8, #$C9, #$CA, #$CB, #$CC, #$CD, #$CE, #$CF,
    #$D0, #$D1, #$D2, #$D3, #$D4, #$D5, #$D6, #$D7,
    #$D8, #$D9, #$DA, #$DB, #$DC, #$DD, #$DE, #$DF,
    #$E0, #$E1, #$E2, #$E3, #$E4, #$E5, #$E6, #$E7,
    #$E8, #$E9, #$EA, #$EB, #$EC, #$ED, #$EE, #$EF,
    #$F0, #$F1, #$F2, #$F3, #$F4, #$F5, #$F6, #$F7,
    #$F8, #$F9, #$FA, #$FB, #$FC, #$FD, #$FE, #$FF);

function StrPMatchStrNoCase(const P: PAnsiChar; const M: AnsiString): Boolean;
var T, Q : PAnsiChar;
    I, L : Integer;
    C, D : AnsiChar;
begin
  L := Length(M);
  if L = 0 then
    begin
      Result := False;
      exit;
    end;
  T := P;
  Q := Pointer(M);
  For I := 1 to L do
    begin
      C := AnsiLowCaseLookup[T^];
      D := AnsiLowCaseLookup[Q^];
      if (C = #0) or (C <> D) then
        begin
          Result := False;
          exit;
        end else
        begin
          Inc(T);
          Inc(Q);
        end;
    end;
  Result := True;
end;

function StrPMatchStr(const P: PAnsiChar; const M: AnsiString): Boolean;
var T, Q : PAnsiChar;
    I, L : Integer;
    C    : AnsiChar;
begin
  L := Length(M);
  if L = 0 then
    begin
      Result := False;
      exit;
    end;
  T := P;
  Q := Pointer(M);
  For I := 1 to L do
    begin
      C := T^;
      if (C = #0) or (C <> Q^) then
        begin
          Result := False;
          exit;
        end else
        begin
          Inc(T);
          Inc(Q);
        end;
    end;
  Result := True;
end;

function StrPMatchStrCase(const P: PAnsiChar; const M: AnsiString;
    const CaseSensitive: Boolean): Boolean;
begin
  if CaseSensitive then
    Result := StrPMatchStr(P, M) else
    Result := StrPMatchStrNoCase(P, M);
end;

FUNCTION StrPos_NoCase (CONST subStr, s: ANSISTRING; CONST index: INTEGER): INTEGER;
var P       : PAnsiChar;
    L, M, I : Integer;
begin
  L := Length(S);
  M := Length(subStr);
  if (L = 0) or (Index > L) or (M = 0) or (M > L) then
    begin
      Result := 0;
      exit;
    end;
  if Index < 1 then
    I := 1 else
    I := Index;
  P := Pointer(S);
  Inc(P, I - 1);
  Dec(L, M - 1);
  While I <= L do
    if StrPMatchStrCase(P, subStr, FALSE) then
      begin
        Result := I;
        exit;
      end else
      begin
        Inc(P);
        Inc(I);
      end;
  Result := 0;
end;

VAR
  src, header, body, partNumberAsStr: AnsiString;
  srcLen, pos, pos2, partNumber: INTEGER;

FUNCTION FindSegment (CONST div1, div2: AnsiString; fromPos: INTEGER): INTEGER;
VAR
  posBeg, posEnd: INTEGER;
BEGIN
  posBeg := StrPos_NoCase(div1, src, fromPos);
  IF posBeg > 0 THEN BEGIN (* '/*=' found *)
    posEnd := StrPos_NoCase(div2, src, posBeg + 3);
    IF posEnd > 0 THEN BEGIN (* '/*=...=*/ found *)
      RESULT := posEnd + 2; EXIT
    END;
  END;
  RESULT := 0;
END {FindSegment};

VAR
  srcName, partName: AnsiString; noinit, nocut: BOOLEAN; nPar: INTEGER;

BEGIN
  noinit := FALSE; nocut := FALSE;
  srcName := ''; partName := '';
  FOR nPar := 1 TO ParamCount DO BEGIN
    IF ParamStr(nPar) = '-noinit' THEN noinit := TRUE
    ELSE
      IF ParamStr(nPar) = '-nocut' THEN nocut := TRUE
    ELSE
      IF srcName = '' THEN srcName := ParamStr(nPar)
    ELSE
      partName := ParamStr(nPar);
    (*END*)
  END;
  src := Kol.StrLoadFromFile(srcName); srcLen := LENGTH(src);
  IF srcLen = 0 THEN BEGIN
    WriteLn('Use:'+#13#10#13#10#9'smartlib.exe src.c [partname] [-noinit] [-nocut]');
    HALT; (* Need to be source *)
  END;

  IF nocut THEN BEGIN (* NO CUT mode: *)
    IF partName = '' THEN partName := SrcName;
    IF NOT noinit THEN (* INIT: *)
      Kol.StrSaveToFile(partName, src)
    ELSE BEGIN (* NO INIT *)
      (* Detecting the parts of body ... *)
      pos := FindSegment(BodyDivisor1, BodyDivisor2, 1);
      WHILE pos > 0 DO BEGIN (* '/*-...-*/ found *)
        pos2 := FindSegment(BodyDivisor1, BodyDivisor2, pos);
        IF pos2 > 0 THEN pos := pos2 ELSE BREAK;
      END;
      DELETE(src, pos+1-80, MAXINT); Kol.StrSaveToFile(partName, src);
    END;
  END ELSE BEGIN (* CUT mode: *)

    IF partName = '' THEN partName := Kol.ExtractFileNameWOext(SrcName);
    INSERT('_', partName, MAXINT);
    (* Detecting the header ... *)
    pos := FindSegment(HeadDivisor1, HeadDivisor2, 1);
    header := '';
    IF pos > 0 THEN BEGIN (* '/*=...=*/ found *)
      header := COPY(src, 1, pos);
      DELETE(src, 1, pos);
    END;
    (* Detecting the parts of body ... *)
    partNumber := 1;
    pos := FindSegment(BodyDivisor1, BodyDivisor2, 1);
    WHILE pos > 0 DO BEGIN (* '/*-...-*/ found *)
      body := COPY(src, 1, pos);
      DELETE(src, 1, pos);
      partNumberAsStr := Kol.Int2Str(partNumber);
      WHILE LENGTH(partNumberAsStr) < 3 DO INSERT('0', partNumberAsStr, 1); (* Add '00x' *)
      Kol.StrSaveToFile(partName + partNumberAsStr + '.c', header + body);
      INC(partNumber);
      pos := FindSegment(BodyDivisor1, BodyDivisor2, 1);
    END;
    IF NOT noinit THEN BEGIN
      (* Write rest of the source file *)
      partNumberAsStr := Kol.Int2Str(partNumber);
      WHILE LENGTH(partNumberAsStr) < 3 DO INSERT('0', partNumberAsStr, 1); (* Add '00x' *)
      Kol.StrSaveToFile(partName + partNumberAsStr + '.c', header + src);
    END;

  END;
END {smartlib}.

MODULE AclDemo; (*$MAIN*)

IMPORT
   W := WinApi, Acl := AclLib, Ut := AclUtils, Ignore;

TYPE
   TWnd1 = RECORD (Acl.TWinControl)
             L1  : Acl.TLabel;
             Lb1 : Acl.TListBox;
             Ch1,
             Ch2,
             Ch3,
             Ch4 : Acl.TCheckBox;
             Btn1 : Acl.TButton;
             Btn2 : Acl.TButton;
             Prg1 : Acl.TProgressBar;
           END;

VAR
   Wnd1   : TWnd1;
   s1,s2  : ARRAY 256 OF CHAR;
   trig   : BOOLEAN;

PROCEDURE ^ (VAR w: TWnd1) WndCreate (sender: Acl.TObject);
PROCEDURE ^ (VAR w: TWnd1) Btn1Click (sender: Acl.TObject);
PROCEDURE ^ (VAR w: TWnd1) Btn2Click (sender: Acl.TObject);

PROCEDURE (VAR w: TWnd1) WndCreate (sender: Acl.TObject);
BEGIN
  w.AutoStop := TRUE; (* exit from process by closing this window*)(*
  L1 := NewLabel(Self,
           s1,
           20,10,Self.ClientWidth - 40,20,
           ss_Center,
           bk_Slide,
           0,
           clWhite);
  Lb1 := NewListBox(Self,
                     20,30,Self.ClientWidth-40,90,
                     true, // Sorted
                     clWhite,
                     clBlack);
  Ch1 := NewCheckBox(Self,
                     'Add AAA',
                     20,130,Self.ClientWidth div 2 - 40,25,
                     clWhite,
                     clWhite);
  Ch2 := NewCheckBox(Self,
                     'Add BBB',
                     20,160,Self.ClientWidth div 2 - 40,25,
                     clWhite,
                     clWhite);
  Ch3 := NewCheckBox(Self,
                     'Add 111',
                     Self.ClientWidth div 2 + 20,130,Self.ClientWidth div 2 - 40,25,
                     clWhite,
                     clWhite);
  Ch4 := NewCheckBox(Self,
                     'Add 222',
                     Self.ClientWidth div 2 + 20,160,Self.ClientWidth div 2 - 40,25,
                     clWhite,
                     clWhite);
  Btn1 := NewButton(Self,
                   'Add string',
                   0,
                   (Self.ClientWidth - 150) div 2,190,150,25,
                   clBlue,
                   clBlack);
  Btn1.OnClick := Btn1Click;
  Btn1.TabStop := false;
  Btn2 := NewButton(Self,
                   'Add progress',
                   0,
                   (Self.ClientWidth - 150) div 2,230,150,25,
                   clSilver,
                   clBlack);
  Btn2.OnClick := Btn2Click;
  Prg1 := NewProgressBar(Self,
                         20,265,Self.ClientWidth - 40,18,
                         0,100,
                         clSilver,
                         clBlack);
  Prg1.Step := 1;
*)END WndCreate;

PROCEDURE (VAR w: TWnd1) Btn1Click (sender: Acl.TObject);(*
var s : shortstring;
BEGIN
  s := '';
  if Ch1.Checked then s := s + 'AAA';
  if Ch2.Checked then s := s + 'BBB';
  if Ch3.Checked then s := s + '111';
  if Ch4.Checked then s := s + '222';
  if s <> '' then
  BEGIN
    Lb1.Add(s);
    Lb1.Focused := Lb1.Count-1;
    Lb1.setFocus;
  END;
  trig := not trig;
  if trig then
  BEGIN
    L1.Font.Name := 'Courier New';
    L1.Caption := s2;
  END     else
  BEGIN
    L1.Font.Name := 'Arial';
    L1.Caption := s1;
  END;
*)END Btn1Click;

PROCEDURE (VAR w: TWnd1) Btn2Click (sender: Acl.TObject);(*
BEGIN
  Prg1.Position := Prg1.Position + 10;
*)END Btn2Click;

BEGIN
  s1 := "Sorted ListBox Sample";
  s2 := "SORTED LISTBOX SAMPLE";
  trig := FALSE;
  Wnd1.Create(NIL);
  Wnd1.Style := W.WS_BORDER + W.WS_CAPTION + W.WS_SYSMENU;
  Wnd1.SetWidth(350);
  Wnd1.SetHeight(300);
  Wnd1.SetLeft((W.GetSystemMetrics(W.SM_CXSCREEN) - Wnd1.Width) DIV 2);
  Wnd1.SetTop((W.GetSystemMetrics(W.SM_CYSCREEN) - Wnd1.Height) DIV 2);
  Wnd1.SetColor(Ut.RGB(33X, 99X, 0FFX));
  Wnd1.SetCaption("Win32 API Programming Sample");(*
  Wnd1.OnCreate := WndCreate;*)
  Wnd1.CreateWnd;
  Wnd1.SetVisible(TRUE);(*
  Wnd1.Lb1.SetFocus;*)
  Ignore.Int( Wnd1.ShowModal() );(*
  Wnd1.Free;*)
END AclDemo.

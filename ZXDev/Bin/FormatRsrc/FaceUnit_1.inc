{ KOL MCK } // Do not remove this line!

procedure NewForm1( var Result: PForm1; AParent: PControl );
begin

  {$IFDEF KOLCLASSES}
  Result := PForm1.Create;
  {$ELSE OBJECTS}
  New( Result, Create );
  {$ENDIF KOL CLASSES/OBJECTS}
  Result.Form := NewForm( AParent, 'Resource Formatter' ).SetPosition( 192, 124 );
  Applet :=  Result.Form;
  Result.Form.Add2AutoFree( Result );
    Result.Form.SetClientSize( 1097, 456 );
    Result.MemoDest := NewEditBox( Result.Form, [ eoMultiline ] ).SetPosition( 8, 232 ).SetSize( 1081, 217 );
    Result.MemoDest.Font.FontName := 'Lucida Console';
    Result.MemoSrc := NewEditBox( Result.Form, [ eoMultiline ] ).SetPosition( 8, 8 ).SetSize( 1081, 217 );
    Result.MemoSrc.Font.FontName := 'Lucida Console';
    Result.MemoDest.Color := TColor(clWindow);
    Result.MemoSrc.Color := TColor(clWindow);
      Result.MemoSrc.OnChange := Result.MemoSrcChange;

end;


{ KOL MCK } // Do not remove this line!

procedure NewForm1( var Result: PForm1; AParent: PControl );
begin

  {$IFDEF KOLCLASSES}
  Result := PForm1.Create;
  {$ELSE OBJECTS}
  New( Result, Create );
  {$ENDIF KOL CLASSES/OBJECTS}
  Result.Form := NewForm( AParent, 'Sprite Converter from LASER BASIC to LASER BASIC 2' ).SetPosition( 192, 124 );
  Applet :=  Result.Form;
  Result.Form.Add2AutoFree( Result );
    Result.Form.SetClientSize( 633, 456 );
    Result.MemoDest := NewEditBox( Result.Form, [ eoMultiline ] ).SetPosition( 8, 232 ).SetSize( 617, 217 );
    Result.MemoDest.Font.FontName := 'Lucida Console';
    Result.MemoSrc := NewEditBox( Result.Form, [ eoMultiline ] ).SetPosition( 8, 8 ).SetSize( 617, 217 );
    Result.MemoSrc.Font.FontName := 'Lucida Console';
    Result.MemoDest.Color := TColor(clWindow);
    Result.MemoSrc.Color := TColor(clWindow);
      Result.MemoSrc.OnChange := Result.MemoSrcChange;

end;


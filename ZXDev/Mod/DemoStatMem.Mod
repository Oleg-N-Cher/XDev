MODULE DemoStatMem; (*$MAIN*)
IMPORT
  SYSTEM, IO := Console, Basic;

TYPE
  PersonPtr = POINTER [1] TO Person;
  Person = RECORD
    name: ARRAY 20 OF CHAR;
    age: SHORTINT;
    sex: CHAR; (*"M" OR "F"*)
    next: PersonPtr;
  END;

VAR
  john, mike, lisa, bob, iren: Person; person: PersonPtr;
  list: ARRAY 5 OF PersonPtr;
  n: SHORTINT;

BEGIN
  john.name := "John Smith"   ; john.sex := "M"; john.age := 32;
  john.next := SYSTEM.VAL(PersonPtr, SYSTEM.ADR(bob));
  mike.name := "Michael Bison"; mike.sex := "M"; mike.age := 12;
  mike.next := SYSTEM.VAL(PersonPtr, SYSTEM.ADR(lisa));
  lisa.name := "Elisabeth Bow"; lisa.sex := "F"; lisa.age := 21;
  lisa.next := NIL;
  bob.name  := "Boris Fellow" ; bob.sex  := "M"; bob.age  := 39;
  bob.next  := SYSTEM.VAL(PersonPtr, SYSTEM.ADR(iren));
  iren.name := "Iren Summer"  ; iren.sex := "F"; iren.age := 43;
  iren.next := SYSTEM.VAL(PersonPtr, SYSTEM.ADR(mike));

  person := SYSTEM.VAL(PersonPtr, SYSTEM.ADR(john));
  IO.WriteStrLn("Female:");
  WHILE person # NIL DO
    IF person.sex = "F" THEN IO.WriteStrLn(person.name) END;
    person := person.next;
  END; IO.WriteLn;

  list[0] := SYSTEM.VAL(PersonPtr, SYSTEM.ADR(john));
  list[1] := SYSTEM.VAL(PersonPtr, SYSTEM.ADR(mike));
  list[2] := SYSTEM.VAL(PersonPtr, SYSTEM.ADR(lisa));
  list[3] := SYSTEM.VAL(PersonPtr, SYSTEM.ADR(bob));
  list[4] := SYSTEM.VAL(PersonPtr, SYSTEM.ADR(iren));

  FOR n := LEN(list) - 1 TO 0 BY -1 DO
    IO.WriteStr(list[n].name); IO.WriteStr("  ");
    IO.WriteCh(list[n].sex); IO.WriteStr("  ");
    IO.WriteInt(list[n].age); IO.WriteLn; IO.WriteLn;
  END;

  (* Using manual POKE'ing to John.name: *)
  IO.WriteStr("Before POKE'ing: "); IO.WriteStrLn(john.name);
  Basic.POKE(SYSTEM.VAL(SHORTINT, SYSTEM.ADR(john.name[0])), ORD("H"));
  Basic.POKE(SYSTEM.VAL(SHORTINT, SYSTEM.ADR(john.name[1])), ORD("a"));
  (* Or the same by SYSTEM.PUT: *)
  SYSTEM.PUT(SYSTEM.ADR(john.name[2]), "n");
  SYSTEM.PUT(SYSTEM.ADR(john.name[3]), "s");
  IO.WriteStr("After POKE'ing: "); IO.WriteStrLn(john.name);

END DemoStatMem.
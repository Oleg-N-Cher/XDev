MODULE DemoDynMem; (*$MAIN*)
IMPORT
  IO := Console, Platform;

TYPE
  PersonPtr = POINTER TO Person;
  Person = RECORD
    name: ARRAY 20 OF CHAR;
    age: INTEGER;
    sex: CHAR; (*"M" OR "F"*)
    next: PersonPtr;
  END;

VAR
  john, mike, lisa, bob, iren, person: PersonPtr;
  list: POINTER TO ARRAY 5 OF PersonPtr;
  n: INTEGER;

BEGIN
  NEW(john); NEW(mike); NEW(lisa); NEW(bob); NEW(iren);
  john.name := "John Smith"   ; john.sex := "M"; john.age := 32;
  john.next := bob;
  mike.name := "Michael Bison"; mike.sex := "M"; mike.age := 12;
  mike.next := lisa;
  lisa.name := "Elisabeth Bow"; lisa.sex := "F"; lisa.age := 21;
  lisa.next := NIL;
  bob.name  := "Boris Fellow" ; bob.sex  := "M"; bob.age  := 39;
  bob.next  := iren;
  iren.name := "Iren Summer"  ; iren.sex := "F"; iren.age := 43;
  iren.next := mike;

  person := john; IO.WriteStrLn("Female:");
  WHILE person # NIL DO
    IF person.sex = "F" THEN IO.WriteStrLn(person.name) END;
    person := person.next;
  END; IO.WriteLn;

  NEW(list);
  list[0] := john; list[1] := mike; list[2] := lisa;
  list[3] := bob;  list[4] := iren;

  FOR n := LEN(list^) - 1 TO 0 BY -1 DO
    IO.WriteStrLn(list[n].name);
    IO.WriteCh(list[n].sex); IO.WriteLn;
    IO.WriteInt(list[n].age); IO.WriteLn; IO.WriteLn;
    Platform.DISPOSE(list[n]);
  END;
  Platform.DISPOSE(list);
END DemoDynMem.
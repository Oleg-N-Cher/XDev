MODULE TestInput; (*$MAIN*)
IMPORT Basic, Input;

VAR
  key: Input.Key;
BEGIN
  Basic.Init;
  REPEAT key := Input.Read(); Basic.PRCHAR(key);
  UNTIL key = "0";
  Basic.Quit;
END TestInput. 
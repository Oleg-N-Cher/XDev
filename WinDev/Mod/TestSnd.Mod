MODULE TestSnd; (*$MAIN*)
IMPORT Sdl := GrApp, Sound, Input;

VAR
  EduinDied: Sound.Rsrc;

BEGIN
  Sound.Load(EduinDied, "fx7.wav");
  LOOP
    Sound.Play(EduinDied);
    IF Input.Read() = " " THEN EXIT END;
  END;
  Sound.Free(EduinDied);
  Sound.Quit;
END TestSnd.
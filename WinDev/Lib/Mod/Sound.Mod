MODULE Sound;
IMPORT
  SYSTEM, Sdl := SdlLib, Mixer := SdlMixer, Ignore;

TYPE
  Rsrc* = Mixer.PMix_Chunk;

VAR
  initOk-: BOOLEAN;

PROCEDURE Load* (VAR sound: Rsrc; IN fileName: ARRAY OF CHAR);
BEGIN
  IF initOk THEN
    sound := Mixer.Mix_LoadWAV(SYSTEM.VAL(Sdl.PChar, SYSTEM.ADR(fileName)));
  ELSE
    sound := NIL;
  END;
END Load;

PROCEDURE Play* (sound: Rsrc);
BEGIN
  IF initOk & (sound # NIL) THEN
    Ignore.Int( Mixer.Mix_PlayChannel(-1, sound, 0) );
  END;
END Play;

PROCEDURE Free* (VAR sound: Rsrc);
BEGIN
  IF initOk & (sound # NIL) THEN Mixer.Mix_FreeChunk(sound) END;
END Free;

PROCEDURE Quit* ;
BEGIN
  Mixer.Mix_CloseAudio;
  Sdl.QuitSubSystem(Sdl.INIT_AUDIO);
END Quit;

BEGIN
  initOk := Sdl.InitSubSystem(Sdl.INIT_AUDIO) >= 0;
  IF initOk THEN
    initOk := (0 <=
      Mixer.Mix_OpenAudio(22050, Mixer.MIX_DEFAULT_FORMAT-10000H, 2, 4096)
    );
  END;
END Sound.

MODULE Wham; IMPORT SYSTEM;

TYPE
  Channel* = INT16;
  UINT8 = SYSTEM.BYTE;
  ADDRESS = INT32;

PROCEDURE InitPlayNote* (channel1, channel2: ADDRESS); END InitPlayNote;
PROCEDURE PlayNote* ; END PlayNote;
PROCEDURE PlayKeyPress* (channel1, channel2: ADDRESS); END PlayKeyPress;
PROCEDURE PlayTuneEnd* (channel1, channel2: ADDRESS); END PlayTuneEnd;
PROCEDURE SetTempo* (tempo: UINT8); (* REPLAY SPEED (230 TO 255) *)
END SetTempo;

END Wham.

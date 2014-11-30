(*

(c) Reobne, 2014

*)

MODULE TestSnd;
IMPORT Sound, B := Basic, Input, Asm;

VAR
  fx1, fx2, fx3, fx4, fx5, fx6, fx7: Sound.Fx;

BEGIN (*$MAIN*)
  B.Init;
  (* FX1  P=0 L=3 *)
  B.DEFDATA(fx1, 3);
  B.DATA3(0FCH+1, 001H, 0);
  (*FX2  P=3 L=13*)
  B.DEFDATA(fx2, 13);
  B.DATA2(0F0H+1, 04FH);
  B.DATA2(0F0H+1, 047H);
  B.DATA2(0F0H+1, 038H);
  B.DATA2(0F0H+1, 038H);
  B.DATA2(0F0H+1, 06AH);
  B.DATA3(0F0H+1, 06AH, 0);
  (* FX3  P=3+13=16 L=29 *)
  B.DEFDATA(fx3, 29);
  B.DATA2(0F0H+1, 02FH);
  B.DATA2(0F0H+1, 02AH);
  B.DATA2(0F0H+1, 028H);
  B.DATA2(0F0H+1, 023H);
  B.DATA2(0F0H+1, 01FH);
  B.DATA2(0F0H+1, 01CH);
  B.DATA2(0F0H+1, 01AH);
  B.DATA2(0F0H+1, 018H);
  B.DATA2(0F0H+1, 015H);
  B.DATA2(0F0H+1, 014H);
  B.DATA2(0F0H+1, 012H);
  B.DATA2(0F0H+1, 010H);
  B.DATA2(0F0H+1, 00EH);
  B.DATA3(0F0H+1, 00DH, 0);
  (* FX4  P=16+29=45 L=15 *)
  B.DEFDATA(fx4, 15);
  B.DATA2(0F7H+1, 003H);
  B.DATA2(0F7H+1, 0DFH);
  B.DATA2(0F8H+1, 0D6H);
  B.DATA2(0F9H+1, 0EBH);
  B.DATA2(0FAH+1, 082H);
  B.DATA2(0FBH+1, 0CCH);
  B.DATA3(0FDH+1, 03DH, 0);
  (* FX5  P=45+15=60 L=15 *)
  B.DEFDATA(fx5, 15);
  B.DATA2(0F0H+1, 0D4H);
  B.DATA2(0F0H+1, 0BDH);
  B.DATA2(0F0H+1, 0A8H);
  B.DATA2(0F0H+1, 09FH);
  B.DATA2(0F0H+1, 08DH);
  B.DATA2(0F0H+1, 070H);
  B.DATA3(0F0H+1, 08DH, 0);
  (* FX6  P=60+15=75 L=29*2+1+3*3+4*4+5=89 *)
  B.DEFDATA(fx6, 89);
  (*00*)B.DATA2(0A3H+1, 04FH);
  (*01*)B.DATA2(0B2H+1, 0F3H);
  (*02*)B.DATA2(0C2H+1, 0A1H);
  (*03*)B.DATA2(0D2H+1, 07BH);
  (*04*)B.DATA2(0D2H+1, 036H);
  (*05*)B.DATA2(0D1H+1, 0F8H);
  (*06*)B.DATA2(0D1H+1, 0C1H);
  (*07*)B.DATA2(0D1H+1, 0A8H);
  (*08*)B.DATA2(0D1H+1, 079H);
  (*09*)B.DATA2(0D1H+1, 050H);
  (*0A*)B.DATA2(0D1H+1, 03DH);
  (*0B*)B.DATA2(0D1H+1, 01BH);
  (*0C*)B.DATA2(0D0H+1, 0FCH);
  (*0D*)B.DATA2(0D0H+1, 0E0H);
  (*0E*)B.DATA2(0D0H+1, 0D4H);
  (*0F*)B.DATA2(0D0H+1, 0BDH);
  (*10*)B.DATA2(0D0H+1, 0A8H);
  (*11*)B.DATA2(0D0H+1, 09FH);
  (*12*)B.DATA2(0D0H+1, 08DH);
  (*13*)B.DATA2(0D0H+1, 07EH);
  (*14*)B.DATA2(0D0H+1, 070H);
  (*15*)B.DATA2(0D0H+1, 06AH);
  (*16*)B.DATA2(0D0H+1, 05EH);
  (*17*)B.DATA2(0D0H+1, 054H);
  (*18*)B.DATA2(0D0H+1, 04FH);
  (*19*)B.DATA2(0D0H+1, 047H);
  (*1A*)B.DATA2(0D0H+1, 03FH);
  (*1B*)B.DATA2(0D0H+1, 038H);
  (*1C*)B.DATA2(0D0H+1, 035H);
  (*1D*)B.DATA1(0D0H);
  B.DATA2(0FH, 0F0H);
  B.DATA1(0B0H);
  B.DATA2(02H, 0F0H);
  B.DATA1(0B0H);
  B.DATA2(02H, 0F0H);
  B.DATA1(0B0H);
  B.DATA3(08H, 0F0H+1, 038H);
  B.DATA1(0B0H);
  B.DATA3(08H, 0F0H+1, 03FH);
  B.DATA1(0B0H);
  B.DATA3(08H, 0F0H+1, 047H);
  B.DATA1(0B0H);
  B.DATA3(08H, 0F0H+1, 038H);
  B.DATA1(0B0H);
  B.DATA3(0DH, 0F0H+1, 03FH);
  B.DATA2(0B0H, 0);
  (* FX7  P=75+89=164 L=4+3+5*4+4=31 *)
  B.DEFDATA(fx7, 31);
  B.DATA3(03H, 0F9H+1, 0EBH);
  B.DATA1(0B0H);
  B.DATA2(03H, 0F0H);
  B.DATA1(0B0H);
  B.DATA3(03H, 0F8H+1, 0D6H);
  B.DATA1(0B0H);
  B.DATA3(03H, 0F9H+1, 0EBH);
  B.DATA1(0B0H);
  B.DATA3(03H, 0F8H+1, 057H);
  B.DATA1(0B0H);
  B.DATA3(03H, 0F9H+1, 0EBH);
  B.DATA1(0B0H);
  B.DATA3(03H, 0F8H+1, 057H);
  B.DATA1(0B0H);
  B.DATA4(04H, 0F7H+1, 0DFH, 0);

  B.IM2PROC(Sound.RunMe50Hz);
  Sound.Play(fx7);
  LOOP
    CASE Input.Read() OF
    | "1": Sound.Play(fx1);
    | "2": Sound.Play(fx2);
    | "3": Sound.Play(fx3);
    | "4": Sound.Play(fx4);
    | "5": Sound.Play(fx5);
    | "6": Sound.Play(fx6);
    | "7": Sound.Play(fx7);
    END;
  END;
END TestSnd.

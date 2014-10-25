/*
;$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
;$                                                             $
;$     PRO TRACKER 3.X PLAYER v3x0A by Dr.Lion/RSM (c) 2004    $
;$                                                             $
;$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
;Редактирование: 8.07.2004
;Файл исходника: PT3x0A (оптимизирован для малого размера)
;Основные технические параметры плеера:
; - базирован на ядре проигрывателя RC367 by Alone Coder;
; - версия ядра проигрывателя: [0] универсальное,малого размера;
; - максимальное время работы: 8864 такта (тестовый спецмодуль);
; - среднее время работы     : 5440 такта (тестовый спецмодуль);
; - размер проигрывателя     : 1742 (#06CE) байт;
; - качество звука           : среднее
;------ Основные точки входа в плеер ------
        ORG  #C000              ;Адрес компиляции
Compile LD   HL,module          ;Адрес модуля
        JR   INSTALL
        JP   PLAY
        JP   STOP
*/

/* ;------ Процедура инсталляции ------ */
void PT3x0A_Install (unsigned int module) __naked {
__asm
        POP  DE
        POP  HL
        PUSH HL
        PUSH DE
        LD   (Module_Adr$+1),HL    ;Адрес модуля
        DI
        PUSH HL
        LD   BC,#99
        ADD  HL,BC
        LD   A,(HL)
        INC  HL
        PUSH HL
        LD   HL,#Tb_PT$-24
        LD   C,#24
Find_FT$:
        ADD  HL,BC
        DEC  A
        JP   P,Find_FT$
        LD   IX,#tab_frq$
;------ Frequency Table Generator ------
        LD   (SP_SV$+1),SP
        LD   SP,HL
        LD   C,#12
MkFT_L0$:
        POP  HL
        LD   DE,#24
        LD   B,#8
MkFT_L1$:
        SRL  H
        RR   L
        LD   A,L
        ADC  A,D
        LD   0(IX),A
        LD   A,H
        ADC  A,D
        LD   1(IX),A
        ADD  IX,DE
        DJNZ MkFT_L1$
        LD   DE,#-8*24+2
        ADD  IX,DE
        DEC  C
        JR   NZ,MkFT_L0$
SP_SV$: LD   SP,#0
;------ продолжение инсталляции ------
        POP  HL
        LD   A,(HL)
        LD   (temp$+1),A
        INC  HL
        INC  HL
        LD   A,(HL)
        INC  HL
        LD   E,(HL)
        INC  HL
        LD   D,(HL)
        INC  HL
        LD   (smpPP$+1),HL
        LD   C,#64
        ADD  HL,BC
        LD   (ornPP$+1),HL
        LD   C,#32
        ADD  HL,BC
        LD   (Psa_beg$+1),HL
        LD   C,A
        ADD  HL,BC
        LD   (Psa_lop$+1),HL
        POP  HL
        ADD  HL,DE
        LD   (Psa_chn$+1),HL
        LD   A,B
        LD   (Am_vol$),A
        LD   (Bm_vol$),A
        LD   (Cm_vol$),A
        INC  A
        LD   (A_qty$),A
        LD   (B_qty$),A
        LD   (C_qty$),A
        LD   HL,#ZERO_M$
        LD   (Ao_adr$),HL
        LD   (Bo_adr$),HL
        LD   (Co_adr$),HL
        LD   (As_adr$),HL
        LD   (Bs_adr$),HL
        LD   (Cs_adr$),HL
        LD   (Ach_adr$),HL
        SUB  #16+1
        LD   (Ag_vol$),A
        LD   (Bg_vol$),A
        LD   (Cg_vol$),A
        SBC  A,A
        LD   (Avb_lok$),A
        LD   (Cvb_lok$),A
        LD   (Bvb_lok$),A
__endasm;
}
void PT3x0A_Stop (void) __naked {
__asm
STOP$:  LD   DE,#0x0E00
        DEC  D
        LD   BC,#0xFFFD
        OUT  (C),D
        LD   B,#0xBF
        OUT  (C),E
        JR   NZ,STOP$+3
res$:   RET
;------ Вычисление адреса орнамента/сэмпла ------
ornPP$: LD   HL,#ZERO_M$
        ADD  A,A
        JR   sm_or_P$
smpPP$: LD   HL,#ZERO_M$
sm_or_P$:
        LD   C,A
        XOR  A
        LD   B,A
        ADD  HL,BC
        LD   C,(HL)
        INC  HL
        LD   B,(HL)
        LD   HL,(Module_Adr$+1)
        ADD  HL,BC
        RET 
;------ Установка формы и частоты ENV ------
EiPP$:  LD   (E_form$),A
        EX   DE,HL
        LD   D,(HL)
        INC  HL
        LD   E,(HL)
        INC  HL
        EX   DE,HL
        LD   (Env_frq$+1),HL
        XOR  A
        LD   L,A
        LD   H,A
        LD   (Esl_frq$+1),HL
        JR   Eipp$
;------ Special Effects COM.9XXX ------
Eef_sld$:
        LD   A,(DE)             ;sld_env
        INC  DE
        EX   DE,HL
        LD   E,(HL)
        INC  HL
        LD   D,(HL)
        INC  HL
        EX   DE,HL
        LD   (Esl_sds$+1),HL    ;sds
        LD   (Esl_sts$+1),A
Eipp$:  LD   (Esl_stp$+1),A     ;stp
        LD   A,#0x10            ; %00010000
        RET 
;------ #C100 Таблица громкости (логарифмическая) ------
__endasm;
}
void __PT3x0A_TabAdr__ (void) __naked {
__asm
tab_vol$:
        ;DISPLAY "Volume Table :",$
frq_A$: .DW   0
frq_B$: .DW   0
frq_C$: .DW   0
Noise$: .DB   0
Mixer$: .DB   0
vol_A$: .DB   0
vol_B$: .DB   0
vol_C$: .DB   0
frq_E$: .DW   0
E_form$:.DB   0
ZERO_M$:.DW   0
.DB 0,0,0,0,0,0,0,0,01,01,01,01,01,01,01,01
.DB 0,0,0,0,1,1,1,1,01,01,01,01,02,02,02,02
.DB 0,0,0,1,1,1,1,1,02,02,02,02,02,03,03,03
.DB 0,0,1,1,1,1,2,2,02,02,03,03,03,03,04,04
.DB 0,0,1,1,1,2,2,2,03,03,03,04,04,04,05,05
.DB 0,0,1,1,2,2,2,3,03,04,04,04,05,05,06,06
.DB 0,0,1,1,2,2,3,3,04,04,05,05,06,06,07,07
.DB 0,1,1,2,2,3,3,4,04,05,05,06,06,07,07,08
.DB 0,1,1,2,2,3,4,4,05,05,06,07,07,08,08,09
.DB 0,1,1,2,3,3,4,5,05,06,07,07,08,09,09,10
.DB 0,1,1,2,3,4,4,5,06,07,07,08,09,10,10,11
.DB 0,1,2,2,3,4,5,6,06,07,08,09,10,10,11,12
.DB 0,1,2,3,3,4,5,6,07,08,09,10,10,11,12,13
.DB 0,1,2,3,4,5,6,7,07,08,09,10,11,12,13,14
.DB 0,1,2,3,4,5,6,7,08,09,10,11,12,13,14,15
;------ #C200 Область таблицы частот нот -------
tab_frq$:    ;EQU  $
Test_AY$:
        LD   DE,#0xFFBF
        LD   C,#0xFD
        LD   A,#02
        LD   B,D
        OUT  (C),A
        LD   B,E
        OUT  (C),E
        LD   B,D
        IN   A,(C)
        CP   E
        LD   HL,#DC_StrA$
        JR   NZ,AY_Exit$
AY_Pres$:
        LD   A,#0x10
        OUT  (C),A
        IN   A,(C)
        CP   D
        LD   HL,#AY_StrA$
        JR   NZ,AY_Exit$
        LD   HL,#YM_StrA$
AY_Exit$:
        JP   STOP$
          .DS    8
          .ASCII "Pro Tracker 3.x Player v3x0A"
          .ASCII " by Dr.Lion (C) 2004 LEN:6CE"
          .DS    8
DC_StrA$: .ASCII "Disconnected"
          .DB    0
AY_StrA$: .ASCII "AY-3-8910"
          .DB    0
YM_StrA$: .ASCII "YM2149F"
          .DB    0
          .DS    192-(.-tab_frq$)
;------ Таблица подпрограмм комманд ------
X_eff$: .DW   Xef_slT$ ;1xxx,2xxx - sld_tone
        .DW   Xef_nsT$ ;3xxx      - port_note
        .DW   Xef_dSm$ ;4.xx      - dsp_smp
        .DW   Xef_dOr$ ;5.xx      - dsp_orn
        .DW   Xef_vib$ ;6.xx      - vibrato
        .DW   res$
        .DW   res$
        .DW   Eef_sld$ ;9xxx,Axxx - sld_env
        .DW   eff_tmp$ ;B.xx      - temp$
;------ Все переменные канала A ------
Ach_adr$: .DW   ZERO_M$          ;-04 POSITION ADR
Ai_qty$:  .DB   #01              ;-02 STEP COUNTER PRESET
A_qty$:   .DB   #01              ;-01 STEP COUNTER
Afrq_Ad$: .DW   frq_A$           ;+00 ADR IN MEM OF FRQ REG
Avol_Ad$: .DW   vol_A$           ;+02 ADR IN MEM OF VOL REG
As_adr$:  .DW   ZERO_M$          ;+04 SAMPLE ADR
Ao_adr$:  .DW   ZERO_M$          ;+06 ORNAMENT ADR
ACh_IDN$: .DB   4                ;+08 CHANNEL ROLL FOR MIXER
Asl_plk$: .DB   Xsl_sts$-Xsl_plk$;+09 DSP FOR PORT ON/OFF
Avb_lok$: .DB   #0xFF            ;+10 SOUND LOCK (VIBRATO)
As_Vsl$:  .DB   #0x10            ;+11 VOLUME SLIDE ACC
Ag_vol$:  .DB   #0xF0            ;+12 GLOBAL VOLUME
Am_vol$:  .DB   0                ;+13 ENVELOPMENT MASK
As_Nsl$:  .DB   0                ;+14 NOISE SLIDE ACC
As_Esl$:  .DB   0                ;+15 ENVELOPMENT SLIDE ACC
As_dtn$:  .DW   0                ;+16 SAMP FRQ DSP ACC
As_dsp$:  .DB   0                ;+18 SAMPLE POSITION
Ao_dsp$:  .DB   0                ;+19 ORNAMENT POSITION
Asl_dsp$: .DW   0                ;+20 SLIDE DSP
Asl_stp$: .DB   0                ;+22 SLIDE STEP (DELAY)
Asl_tfr$: .DW   0                ;+23 SLIDE ADD DSP
Asl_not$: .DB   0                ;+25 SLIDE TO NOTE
As_note$: .DB   0                ;+26 SAMPLE NOTE
Asl_sts$: .DB   0                ;+27 SLIDE COUNTER PRESET
Avb_stp$: .DB   0                ;+28 VIBRATO COUNTER
Avb_frq$: .DB   0                ;+29 SOUND OFF DELAY (VIBRATO)
Avb_sts$: .DB   0                ;+30 VIBRATO COUNTER PRESET
;------ Все переменные канала B ------
Bch_adr$: .DW   ZERO_M$
Bi_qty$:  .DB   #01
B_qty$:   .DB   #01
Bfrq_Ad$: .DW   frq_B$
Bvol_Ad$: .DW   vol_B$
Bs_adr$:  .DW   ZERO_M$
Bo_adr$:  .DW   ZERO_M$
BCh_IDN$: .DB   3
Bsl_plk$: .DB   Xsl_sts$-Xsl_plk$
Bvb_lok$: .DB   #0xFF
Bs_Vsl$:  .DB   #0x10
Bg_vol$:  .DB   #0xF0
Bm_vol$:  .DB   0
Bs_Nsl$:  .DB   0
Bs_Esl$:  .DB   0
Bs_dtn$:  .DW   0
Bs_dsp$:  .DB   0
Bo_dsp$:  .DB   0
Bsl_dsp$: .DW   0
Bsl_stp$: .DB   0
Bsl_tfr$: .DW   0
Bsl_not$: .DB   0
Bs_note$: .DB   0
Bsl_sts$: .DB   0
Bvb_stp$: .DB   0
Bvb_frq$: .DB   0
Bvb_sts$: .DB   0
;------ Все переменные канала C ------
Cch_adr$: .DW   ZERO_M$
Ci_qty$:  .DB   #01
C_qty$:   .DB   #01
Cfrq_Ad$: .DW   frq_C$
Cvol_Ad$: .DW   vol_C$
Cs_adr$:  .DW   ZERO_M$
Co_adr$:  .DW   ZERO_M$
CCh_IDN$: .DB   2
Csl_plk$: .DB   Xsl_sts$-Xsl_plk$
Cvb_lok$: .DB   #0xFF
Cs_Vsl$:  .DB   #0x10
Cg_vol$:  .DB   #0xF0
Cm_vol$:  .DB   0
Cs_Nsl$:  .DB   0
Cs_Esl$:  .DB   0
Cs_dtn$:  .DW   0
Cs_dsp$:  .DB   0
Co_dsp$:  .DB   0
Csl_dsp$: .DW   0
Csl_stp$: .DB   0
Csl_tfr$: .DW   0
Csl_not$: .DB   0
Cs_note$: .DB   0
Csl_sts$: .DB   0
Cvb_stp$: .DB   0
Cvb_frq$: .DB   0
Cvb_sts$: .DB   0
__endasm;
} //PT3x0A_Install

void PT3x0A_Play (void) __naked {
__asm
;------ Play One Frame of Module ------
        PUSH IY
int_qty$:
        LD   A,#1
        DEC  A
        JR   NZ,SamplIT$
;------ Просчет следующей строки паттерна ------
        LD   IY,#Afrq_Ad$
        CALL Get_Pos$
        LD   IY,#Bfrq_Ad$
        CALL Get_Pos$
        LD   IY,#Cfrq_Ad$
        CALL Get_Pos$
temp$:  LD   A,#3                ;temp
SamplIT$:
        LD   (int_qty$+1),A
;------ Проигрывание сэмплером каналов ABC ------
N_add$: LD   IX,#0              ;HX=noise LX=mix
        LD   BC,#0              ;smp_sl_env
        EXX 
        LD   IY,#Afrq_Ad$
        CALL OneChan$
        LD   IY,#Bfrq_Ad$
        CALL OneChan$
        LD   IY,#Cfrq_Ad$
        CALL OneChan$
;------ Модифицированый сэмплер Envelopment ------
Sampl_E$:
        EXX
Esl_frq$:
        LD   DE,#0             ;stp_sl_env
Env_frq$:
        LD   HL,#0             ;frq_env
        ADD  HL,BC
        ADD  HL,DE
        LD   (frq_E$),HL
;------ Просчет Slide DSP для Envelopment ------
Esl_stp$:
        LD   A,#0
        DEC  A
        JP   M,MPU_Out$
        JR   NZ,Esl_n0$
Esl_sds$:
        LD   HL,#0
        ADD  HL,DE
        LD   (Esl_frq$+1),HL
Esl_sts$:
        LD   A,#0
Esl_n0$:LD   (Esl_stp$+1),A
;---- Update Noise & Mixer Than Out ----
MPU_Out$:
        .DB  0xDD
        LD   A,H; <= LD   A,HX  ;noise value
        LD   (N_add$+3),A
N_frq$: ADD  A,#0
        LD   (Noise$),A
        .DB  0xDD
        LD   A,L; <= LD   A,LX  ;mixer bits
        LD   (Mixer$),A
        POP  IY                 ;old IY value
        LD   HL,#frq_A$
        LD   DE,#0xFFBF
        LD   C,#0xFD
        LD   A,#14
AY_Out$:LD   B,D
        OUT  (C),L
        LD   B,E
        DEC  A
        JR   Z,EN_Out$
        OUTI 
        JR   AY_Out$
EN_Out$:OR   (HL)
        RET  Z
        OUT  (C),A
        LD   (HL),#0
        RET 
;------ Универсальный сэмплер для каналов ABC ------
OneChan$:
        LD   (Quit_S$+1),SP
        LD   SP,IY
        POP  HL
        LD   (FrqR_A$+1),HL
        POP  HL
        LD   (VolR_A$+1),HL
        POP  HL
        LD   (Xs_adr$+1),HL
        POP  HL
        LD   (Xo_adr$+1),HL
        POP  HL
        LD   A,L
        LD   (Ch_Roll$+1),A
        LD   A,H
        LD   (Xsl_plk$-1),A
;------ Переделанный под переменные сэмплер PT3.67 ------
        LD   A,10(IY)           ;Xvb_lok
        LD   H,A
        INC  A
        JP   Z,Xvb_n0$
Xs_adr$:LD   SP,#0              ;sample
        POP  DE                 ;loop E=beg D=end
        LD   A,18(IY)           ;Xs_dsp
        LD   L,A
        INC  A
        CP   D
        JR   C,Xs_n0$
        LD   A,E
Xs_n0$: LD   18(IY),A
        ADD  HL,HL
        ADD  HL,HL
        ADD  HL,SP
        LD   SP,HL
        POP  DE                 ;D= Nm ts ns Tm v3 v2 v1 v0
        LD   A,D                ;E= sv +- N4 N3 N2 N1 N0 Em
        OR   #0xF0
        LD   L,A
        LD   A,E
        ADD  A,A
        LD   A,11(IY)           ;Xs_Vsl
        JR   NC,Xs_VslG$
        JP   M,Xs_n2$
        SUB  #1
        JR   Xs_n3$
Xs_n2$: CP   #31
Xs_n3$: ADC  A,#0
        LD   11(IY),A
Xs_VslG$:
        ADD  A,L
        JR   C,Xs_n4$
        XOR  A
Xs_n4$: CP   #16
        JR   C,Xg_vol$
        LD   A,#15
Xg_vol$:ADD  A,12(IY)           ;Xg_vol
        LD   L,A
        LD   H,#>frq_A$         ;tab_vol
        LD   A,(HL)
        SRL  E
        JR   C,Xm_vo0$
        OR   13(IY)             ;Xm_vol
Xm_vo0$:EX   AF,AF
        LD   A,D
        RLCA 
        JR   C,Xs_n5$
        LD   A,14(IY)           ;Xs_Nsl
        ADD  A,E
        BIT  5,D
        JR   Z,Xs_n6$
        LD   14(IY),A
Xs_n6$: .DB  0xDD
        LD   H,A; <= LD   HX,A
        JR   Xs_n7$
Xs_n5$: LD   A,E
        AND  #31
        CP   #16
        JR   C,Xs_Esl$
        OR   #0xF0
Xs_Esl$:ADD  A,15(IY)           ;Xs_Esl
        BIT  5,D
        JR   Z,Xs_n9$
        LD   15(IY),A
Xs_n9$: EXX
        ADD  A,C
        LD   C,A
        EXX 
Xs_n7$: LD   A,D
        AND  #0x90              ;%10010000
Ch_Roll$:
        LD   B,#0
MixLoop$:
        RRCA
        DJNZ MixLoop$
        .DB  0xDD
        OR   L  ; <= OR   LX
        .DB  0xDD
        LD   L,A; <= LD   LX,A
        POP  BC                 ;smp_frq_dsp
        LD   L,16(IY)           ;накопитель dsp
        LD   H,17(IY)
        ADD  HL,BC
        BIT  6,D
        JR   Z,Xs_n10$
        LD   16(IY),L           ;новое значение
        LD   17(IY),H           ;накопителя dsp
Xs_n10$:EX   DE,HL
Xo_adr$:LD   SP,#0              ;ornament
        POP  BC                 ;loop C=beg B=end
        LD   A,19(IY)           ;Xo_dsp
        LD   L,A
        INC  A
        CP   B
        JR   C,Xo_n0$
        LD   A,C
Xo_n0$: LD   19(IY),A
        LD   H,#0
        ADD  HL,SP
        LD   A,26(IY)           ;Xs_note
        ADD  A,(HL)             ;dsp_orn  (ORNAMENTS ON/OFF)
        ADD  A,A
        JR   NC,Xo_n1$          ;;
        XOR  A                  ;;
Xo_n1$: LD   L,#95*2            ;;
        CP   L                  ;;
        JR   NC,Xo_n2$          ;;
        LD   L,A                ;;
Xo_n2$: LD   H,#>tab_frq$
        LD   SP,HL
        POP  HL                 ;частота ноты+
        ADD  HL,DE              ;+накопитель сэмпла (смещение)+
        LD   C,20(IY)
        LD   B,21(IY)
        ADD HL,BC               ;+накопитель SLIDE TONE/PORT
FrqR_A$:LD   (frq_A$),HL
        LD   A,22(IY)           ;Xsl_stp
        DEC  A
        JP   M,Xsl_s0$          ;If Xsl_stp=0 then SLIDE OFF
        JR   NZ,Xsl_s1$
        LD   E,23(IY)           ;Xsl_tfr-приращение накопителя
        LD   D,24(IY)           ;SLIDE TONE/PORT при его изме-
        ADD  HL,DE              ;нении.
        EX   DE,HL
        ADD  HL,BC
        LD   20(IY),L           ;новое значение измененного
        LD   21(IY),H           ;накопителя SLIDE TONE/PORT
        JR   Xsl_sts$           ;переключатель PORT ON/OFF!
Xsl_plk$:    ;EQU  $
        LD   A,25(IY)           ;нота, к которой стремится
        LD   L,A                ;команда PORT.
        ADD  HL,HL
        LD   H,#>tab_frq$
        LD   SP,HL
        POP  HL
        CP   26(IY)             ;последняя встреченая нота, в HL
        JR   NC,Xsl_n0$         ;вычесленная по ней частота.
        EX   DE,HL
Xsl_n0$:SBC  HL,DE
        JR   C,Xsl_sts$
        LD   26(IY),A           ;частоты нот совпали и теперь:
        XOR  A                  ;- Xs_note=Xsl_not
        LD   20(IY),A           ;- Xsl_dsp=0
        LD   21(IY),A
        JR   Xsl_s1$
Xsl_sts$:
        LD   A,27(IY)
Xsl_s1$:LD   22(IY),A
Xsl_s0$:EX   AF,AF
Xvb_n0$:;EQU  $
VolR_A$:LD   (vol_A$),A
        LD   A,28(IY)
        DEC  A
        JP   M,Quit_S$
        JR   NZ,Xvb_n1$
        DEC  A                  ;A=#FF
        XOR  10(IY)             ;A XOR Xvb_lok
        LD   10(IY),A
        LD   A,29(IY)
        JR   NZ,Xvb_n1$
        LD   A,30(IY)
Xvb_n1$:LD   28(IY),A
Quit_S$:LD   SP,#0
        RET 
;------ Get Position + Next Pattern ------
Get_Pos$:
        DEC  -1(IY)             ;X_qty
        RET  NZ
        LD   E,-4(IY)           ;adr_chan
        LD   D,-3(IY)
        LD   A,(DE)
        AND  A
        JR   NZ,Cont_0$
        LD   (N_frq$+1),A
        LD   D,A
        LD   (Sv_SP0$+1),SP
Psa_beg$:
        LD   HL,#module$+201
        LD   A,(HL)
        INC  A
        JR   NZ,Cont_1$
Psa_lop$:
        LD   HL,#module$+201
Cont_1$:LD   E,(HL)
        INC  HL
        LD   (Psa_beg$+1),HL
Psa_chn$:
        LD   HL,#0
        ADD  HL,DE
        ADD  HL,DE
        LD   SP,HL
ia_pos0$:
Module_Adr$:
        LD   BC,#0              ;Адрес модуля
        POP  HL
        ADD  HL,BC
        EX   DE,HL              ;DE=adr_chn_A
        POP  HL
        ADD  HL,BC              ;HL=adr_chn_B
        LD   (Bch_adr$),HL
        POP  HL
        ADD  HL,BC              ;HL=adr_chn_C
        LD   (Cch_adr$),HL
Sv_SP0$:LD   SP,#0
Cont_0$:CALL Xn_clc1$
        LD   -4(IY),E
        LD   -3(IY),D
        LD   A,-2(IY)           ;Xi_qty
        LD   -1(IY),A           ;X_qty
        RET 
;------ Дешифрация позиции по одному каналу ------
Xni_not$:
        LD   26(IY),A           ;Xs_note
        XOR  A
        LD   10(IY),A           ;Xvb_lok
        LD   18(IY),A           ;Xs_dsp
        LD   11(IY),#0x10       ;Xs_Vsl
        LD   14(IY),A           ;Xs_Nsl
        LD   15(IY),A           ;Xs_Esl
        LD   16(IY),A           ;Xs_dtn  low
        LD   17(IY),A           ;Xs_dtn  High
        LD   19(IY),A           ;Xo_dsp
        LD   20(IY),A           ;Xsl_dsp low
        LD   21(IY),A           ;Xsl_dsp High
        LD   22(IY),A           ;Xsl_stp
        LD   28(IY),A           ;Xvb_stp
        RET 
Xni_vol$:
        JR   NZ,Xni_v0$
        LD   28(IY),A           ;Xvb_stp=#00
        DEC  A
        LD   10(IY),A           ;Xvb_lok=#0xFF
        RET 
Xni_v0$:ADD  A,A
        ADD  A,A
        ADD  A,A
        ADD  A,A
        LD   12(IY),A           ;Xg_vol=A*16
        JR   Xn_clc2$
Xni_s_o$:
        CALL ornPP$
        LD   6(IY),L            ;Xo_adr=HL
        LD   7(IY),H
Xni_vse$:
        CALL NZ,EiPP$
Xni_sm0$:
        LD   13(IY),A           ;Xm_vol
        XOR  A
        LD   19(IY),A           ;Xo_dsp=0
        LD   A,(DE)
        INC  DE
        JR   Xnism0U$
Xni_smp$:
        RET  Z
        ADD  A,A
Xnism0U$:
        CALL smpPP$
        LD   4(IY),L            ;Xs_adr
        LD   5(IY),H
Xn_clc1$:
        LD   BC,#0x1020
Xn_clc2$:
        LD   A,(DE)
        INC  DE
        ADD  A,B
        JR   C,Xni_s_o$
        ADD  A,C
        JR   C,Xni_smp$
        ADD  A,B
        JR   C,Xni_vol$
        ADD  A,B
        JR   C,Xni_vqe$
        ADD  A,#96
        JR   C,Xni_not$
        ADD  A,B
        JR   C,Xni_orn$
        ADD  A,C
        JR   C,Xni_noi$
        ADD  A,B
        JR   C,Xni_vse$
        ADD  A,B
        LD   HL,#X_eff$-2
        ADD  A,A
        ADD  A,L
        LD   L,A
        LD   C,(HL)
        INC  L
        LD   B,(HL)
        PUSH BC
        LD   A,26(IY)           ;Xs_note
        EX   AF,AF
        JR   Xn_clc1$
Xni_noi$:
        LD   (N_frq$+1),A        ;GLOBALnoise
        JR   Xn_clc2$
Xni_vqe$:
        JR   Z,Xni_v1$
        DEC  A
        JR   NZ,Xni_e0$
        LD   A,(DE)
        LD   -2(IY),A           ;Xi_qty
        INC  DE
        JR   Xn_clc2$
Xni_e0$:CALL EiPP$
Xni_v1$:LD   13(IY),A           ;Xm_vol
        JR   Xn_clc2$
Xni_orn$:
        CALL ornPP$
        LD   6(IY),L            ;Xo_adr=HL
        LD   7(IY),H
        LD   19(IY),A           ;Xo_dsp=0
        JR   Xn_clc1$
;------ Special Effects COM.XXXX ------
;Off_PRT$: ;EQU  Xsl_sts$-Xsl_plk$
Xef_slT$:
        LD   A,(DE)
        INC  DE
        LD   22(IY),A           ;Xsl_stp
        LD   27(IY),A           ;Xsl_sts
        LD   A,(DE)
        INC  DE
        LD   23(IY),A           ;Xsl_tfr (LOW)
        LD   A,(DE)
        INC  DE
        LD   24(IY),A           ;Xsl_tfr (HIGH)
        LD   28(IY),#0          ;Xvb_stp
        LD   9(IY),#(Xsl_sts$-Xsl_plk$) ;Xsl_plk=PORT_OFF
        RET 
Xef_nsT$:
        CALL Xef_slT$
        LD   A,(DE)
        INC  DE
        LD   23(IY),A           ;Xsl_tfr (LOW)
        LD   A,(DE)
        INC  DE
        LD   24(IY),A           ;Xsl_tfr (HIGH)
        LD   9(IY),#0           ;Xsl_plk=PORT_ON
        LD   A,26(IY)           ;Xs_note
        LD   25(IY),A           ;Xsl_not
        EX   AF,AF
        LD   26(IY),A
        RET 
Xef_dSm$:
        LD   A,(DE)
        INC  DE
        LD   18(IY),A           ;Xs_dsp
        RET 
Xef_dOr$:
        LD   A,(DE)
        INC  DE
        LD   19(IY),A           ;Xo_dsp
        RET 
Xef_vib$:
        LD   A,(DE)
        INC  DE
        LD   28(IY),A
        LD   30(IY),A
        LD   A,(DE)
        INC  DE
        LD   29(IY),A
        LD   22(IY),#0          ;Xsl_stp отключение SLIDE
        RET 
eff_tmp$:
        LD   A,(DE)
        INC  DE
        LD   (temp$+1),A
        RET 
;------ Frequency Tables for Generate ------
Tb_PT$:   .DW   #0x0C22*2,#0x0B72*2,#0x0ACF*2,#0x0A33*2
          .DW   #0x09A1*2,#0x0917*2,#0x0894*2,#0x0819*2
          .DW   #0x07A4*2,#0x0737*2,#0x06CF*2,#0x066D*2
Tb_ST$:   .DW   #0x0EF8*2,#0x0E10*2,#0x0D60*2,#0x0C80*2
          .DW   #0x0BD8*2,#0x0B28*2,#0x0A88*2,#0x09F0*2
          .DW   #0x0960*2,#0x08E0*2,#0x0858*2,#0x07E0*2
Tb_REAL$: .DW   #0x0CDA*2,#0x0C22*2,#0x0B72*2,#0x0ACF*2
          .DW   #0x0A33*2,#0x09A1*2,#0x0917*2,#0x0894*2
          .DW   #0x0819*2,#0x07A4*2,#0x0737*2,#0x06CF*2
Tb_ASM$:  .DW   #0x0D10*2,#0x0C55*2,#0x0BA4*2,#0x0AFC*2
          .DW   #0x0A5F*2,#0x09CA*2,#0x093D*2,#0x08B8*2
          .DW   #0x083B*2,#0x07C5*2,#0x0755*2,#0x06EC*2
;------ Конец плеера-начало модуля ------
module$:;DISPLAY "Module Adress:",module$
        ;DISPLAY "Player Lenght:",module$-Compile$
__endasm;
} //PT3x0A_Play

/*
;------ пример использования -------
        INCBIN  "ace.m"
        ORG  #7000
        DI 
        CALL Compile$
play_l  EI 
        HALT 
        CALL Compile$+5
        LD   A,#0x7F
        IN   A,(-2)
        RRA 
        JR   C,play_l
        JP   Compile$+8
*/


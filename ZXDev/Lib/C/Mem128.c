/*----------------------------------------*/
/* ZX Spectrum 128k memory access library */
/* Loading files from tape & TR-DOS disk  */
/*       VEDAsoft Oberon Club, 2019       */
/*----------------------------------------*/

extern unsigned int Mem128_filesize;

unsigned char Mem128_IsTRDOS (void);
unsigned char Mem128_LoadDisk (unsigned char *name_ext, unsigned int adr) __z88dk_callee;
unsigned char Mem128_LoadTape (unsigned char *name, unsigned int adr) __z88dk_callee;
void Mem128_Page (unsigned char n) __z88dk_fastcall;
void Mem128_SaveDisk (unsigned char *name_ext, unsigned int adr, unsigned int size) __z88dk_callee;
void Mem128_SaveTape (unsigned char *name, unsigned int adr, unsigned int size) __z88dk_callee;

/*================================== Header ==================================*/
unsigned int Mem128_filesize;
/*--------------------------------- Cut here ---------------------------------*/
unsigned char Mem128_tapeHeader [17];

/*--------------------------------- Cut here ---------------------------------*/
unsigned char Mem128_IsTRDOS (void) {
  __asm 
       LD      HL,(#23635)
       LD      DE,#23755
       XOR     A
       SBC     HL,DE
       LD      L,A
       RET     Z
       INC     L
  __endasm;
} //Mem128_IsTRDOS

/*--------------------------------- Cut here ---------------------------------*/
unsigned char Mem128_LoadDisk (unsigned char *name_ext, unsigned int adr) __naked __z88dk_callee {
  __asm // http://zxpress.ru/article.php?id=11342
        // http://zxpress.ru/book_articles.php?id=1352
       POP     HL
       EX      (SP),HL
       LD      C,#0x13
       CALL    0x3D13
       LD      C,#0x0A    ; Поиск файла по его имени
       CALL    0x3D13
       LD      A,C        ; В C - номер файла в каталоге
       INC     C
       JR      NZ,CONTINUE$
       POP     HL         ; Если C=#FF, файл не найден - выход
       EX      (SP),HL
       LD      L,#0
       RET
CONTINUE$:
       LD      C,#08      ; Чтение параметров файла в перемененной DOS
       CALL    0x3D13
       POP     HL
       EX      (SP),HL    ; Адрес загрузки блока
       XOR     A          ; 0 для LOAD
       LD      (#0x5CF9),A
       LD      (#0x5D10),A
       DEC     A          ; Адрес блока в HL, длина - из каталога
       LD      C,#0x0E    ; Загрузка файла по его имени
       CALL    0x3D13
       LD      HL,(#0x5CE8)
       LD      (#_Mem128_filesize),HL
       LD      L,#1
       RET
  __endasm;
} //Mem128_LoadDisk

/*--------------------------------- Cut here ---------------------------------*/
extern unsigned char Mem128_tapeHeader [17];

unsigned char Mem128_LoadTape (unsigned char *name, unsigned int adr) __naked __z88dk_callee {
  __asm // http://zxpress.ru/book_articles.php?id=1876
       PUSH    IX
       LD      IX, #_Mem128_tapeHeader
       LD      DE, #17
       XOR     A          // Ожидается заголовок
       SCF                // Загрузка кодового блока
       INC     D
       EX      AF,AF
       DEC     D
       DI
       LD      A,#15      // Номер начального цвета бордюра + 8
       OUT     (#254),A
       CALL    1378
       LD      A,#7       // Восстановление цвета бордюра
       OUT     (#254),A
       EI
       POP     IX
       POP     HL         // Адрес возврата
       POP     DE         // Имя файла
       POP     BC         // Адрес загрузки файла
       PUSH    HL
       LD      L,#2       // ErrLoadingHeader
       JR      NC,ERROR$  // Ошибка загрузки или нажато Break/Space
       PUSH    IX
       PUSH    BC
       POP     IX         // Адрес загрузки файла
       LD      HL,#_Mem128_tapeHeader+1
       LD      B,#10
MATCHNAME$:
       LD      A,(DE)
       OR      A
       JR      Z,MATCH$
       CP      (HL)
       JR      NZ,NOTMATCH$
       INC     DE
       INC     HL
       DJNZ    MATCHNAME$
MATCH$:LD      DE,(#_Mem128_tapeHeader+11)
       LD      (#_Mem128_filesize),DE
       LD      A,#255     // Ожидается тело файла
       SCF                // Загрузка кодового блока
       INC     D
       EX      AF,AF
       DEC     D
       DI
       LD      A,#15      // Номер начального цвета бордюра + 8
       OUT     (#254),A
       CALL    1378
       LD      A,#7       // Восстановление цвета бордюра
       OUT     (#254),A
       EI
       POP     IX       
       LD      L,#1       // ErrTapeLoading
       JR      NC,ERROR$
       DEC     L          // OK
       RET
NOTMATCH$:
       POP     IX
       LD      L,#3       // ErrNameNotMatch
ERROR$:
       LD      A,#0x7F
       IN      A,(0xFE)
       RRA
       RET     C
       LD      L,#4
       RET
  __endasm;
} //Mem128_LoadTape

/*--------------------------------- Cut here ---------------------------------*/
void Mem128_Page (unsigned char n) __z88dk_fastcall {
  __asm // https://zxpress.ru/article.php?id=9971
       LD      A,L
       AND     #8         ; Номер страницы > 7
       RLA                ; Результат
       LD      BC,#0x1FFD ; выдать
       DI                 ; Запрет прерываний.
       OUT     (C),A      ; в порт #1FFD.
       LD      A,L
       AND     #7         ; Откорректировать
                          ; номер страницы для
                          ; порта #7FFD.
       OR      #0x10      ; Установить ПЗУ 48.
       LD      B,#0x7F    ; Выдать в
       OUT     (C),A      ; порт #7FFD.
       EI                 ; Разрешить прерывания.
  __endasm;
} //Mem128_Page

/*--------------------------------- Cut here ---------------------------------*/
void Mem128_SaveDisk (unsigned char *name_ext, unsigned int adr, unsigned int size)
__naked __z88dk_callee { // http://zxpress.ru/article.php?id=11342
  __asm
       POP     HL
       EX      (SP),HL    ; Адрес имени файла
       LD      C,#0x13
       CALL    0x3D13
       POP     HL
       POP     DE         ; Адрес записываемых данных
       EX      (SP),HL    ; Длина файла
       EX      DE,HL
       LD      C,#0x0B    ; Запись на диск файла
       JP      0x3D13
  __endasm;
} // Mem128_SaveDisk

/*--------------------------------- Cut here ---------------------------------*/
void Mem128_SaveTape (unsigned char *name, unsigned int adr, unsigned int size)
__naked __z88dk_callee { // http://zxpress.ru/book_articles.php?id=850
/* A header always consists of 17 bytes:

        Byte    Length  Description
        ---------------------------
        0       1       Type (0,1,2 or 3)
        1       10      Filename (padded with blanks)
        11      2       Length of code block
        13      2       Start address of the code block
        15      2       32768
*/
  __asm
       POP     HL
       EX      (SP),HL    ; Filename
       LD      DE,#_Mem128_tapeHeader
       LD      A,#3       ; SAVE "" CODE
       LD      (DE),A
       INC     DE
       LD      B,#10
NAMELOOP$:
       LD      A,(HL)
       OR      A
       JR      NZ,NAMECHAR$
       LD      A,#' '
       DEC     HL
NAMECHAR$:
       LD      (DE),A
       INC     HL
       INC     DE
       DJNZ    NAMELOOP$
       POP     HL
       POP     BC         ; Start address of the code block
       EX      (SP),HL    ; Length of code block
       LD      (#_Mem128_tapeHeader+11),HL
       LD      (#_Mem128_tapeHeader+13),BC
       LD      HL,#32768
       LD      (#_Mem128_tapeHeader+15),HL
       PUSH    IX
       LD      IX,#_Mem128_tapeHeader
       LD      DE,#17
       XOR     A
       CALL    1222
       LD      IX,(#_Mem128_tapeHeader+13)
       LD      DE,(#_Mem128_tapeHeader+11)
       LD      A,#255
       CALL    1222
       POP     IX
       RET
  __endasm;
} // Mem128_SaveTape

/*----------------------------------------*/
/* ZX Spectrum 128k memory access library */
/*       VEDAsoft Oberon Club, 2019       */
/*----------------------------------------*/

void Mem128_Page (unsigned char n) __z88dk_fastcall;

/*================================== Header ==================================*/

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

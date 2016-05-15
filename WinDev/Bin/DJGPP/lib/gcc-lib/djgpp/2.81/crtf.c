/* crtf.c is copyright by Robert H”hne 1998. You can use it freely
   and also modify it if you want but in that case please include
   a note that you have modified it before you distribute modified
   versions of it.
   You are not allowed to distribute this file in compiled form
   only. You have to include ever the source for the file so the
   user can see, what the startup file really does.
   Use that file at your own risk.
*/
/* This file is used as additional startup file when linking programs
   for DJGPP. This is needed if you want to have full exception support.
   It needs some assistance by the linker script and assumes that in the
   linker script the symbol ___EH_FRAME_BEGIN__ is defined and that this
   symbol is defined as the first symbol in the .eh_frame section (shortened
   to the .eh_fram section). To explain it, here a snipped from a linker
   script, how it could be written:

  .data  ALIGN(0x200) : {
    djgpp_first_ctor = . ;
    LONG(_init_frame) ;
    *(.ctor)
    djgpp_last_ctor = . ;
    djgpp_first_dtor = . ;
    *(.dtor)
    djgpp_last_dtor = . ;
    *(.data)
    *(.gcc_exc)
    ___EH_FRAME_BEGIN__ = . ;
    *(.eh_fram)
    ___EH_FRAME_END__ = . ;
    LONG(0)
     edata  =  . ; _edata = .;
     . = ALIGN(0x200);
  }
   

   As the next it assumes, that this file is placed as the first (or the
   second after crt0.o) object file in each executable via the specs
   file so it can be sure, that the function with the constructor attribute
   is called first before any other constructors. As an example, here a
   sample entry, how the specs file could be written:

*startfile:
%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crtf.o crt0.o%s}}

   
*/
   
extern void __EH_FRAME_BEGIN__();
/* This function is provided with the libgcc.a library which
   simply registers the start of the exception tables by remembering
   the address passed with the first argument and initializing
   a struct passed with the second argument. */
extern void __register_frame_info (void *, void *);

static void __attribute__((constructor))
frame_dummy ()
{
  /* normally this should be a
  struct object {
    void *pc_begin;
    void *pc_end;
    void *fde_begin;
    void **fde_array;
    size_t count;
    struct object *next;
  };
  but a placeholder of the same size does it also */
  /* W A R N I N G : If the size of this struct changes in future
     versions of gcc, remember this here !!! The struct is declared
     in the file frame.h from the gcc sources */
  static int object[6];

  __register_frame_info (__EH_FRAME_BEGIN__, &object);
}                           


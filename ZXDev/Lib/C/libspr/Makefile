# Создание библиотеки
LIBNAME=libspr.lib

# Список файлов для преобразования h -> hS
HSFILES=spr_const.hS

# 
OFILES= spr0_s.o spr0_var.o spr0_out0_s.o

# Сборка объектников
all: $(HSFILES) $(OFILES)
	$(CCLIB) a $(LIBNAME) *.o


# Объектники из С
main.o:
	$(CC) -c $(COPTS) main.c

%.o:%.c
	$(CC) -c $(COPTS) $<

%.o:%.s
	$(AS) -l -s -o $@ $<

%.hS:%.h
	s2hs $< $@

# Генерация кода
crt0.s: templates/crt0.s_tmpl
	ga_abs $< $@ $(CLOC) $(SSIZE)

# Очистка
clean: 
	rm -f *.lib *.lst *.sym *.exp *.bin *.map *.mem *.lnk *.ihx *.rel *.rst *.asm *.bin crt0.s *.o *.hS *.\$$C
# Очистка


/* bin2trd */
/* Binary & Hobeta files --> .TRD (c)1999, Copper Feet */
/* Modified for Linux - Alexander Shabarshin (shaos@mail.ru) */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#ifdef linux
#include <unistd.h>
#endif
#ifndef O_BINARY
#define O_BINARY 0
#endif

int HO,HI;

char Fname[80];
char LISTname[80];
char TRDname[80]; 

char tr0[0x800]; /* таблица файлов tr-dos */
char sec9[256]; /* 9-й сектор */
#define DNAME sec9+0xF5
char *pt,*ppt; /* указатели в текстовом ф-ле */
char *pt_line;
/* парам. текущ. ф-ла */
char TRDOSname[9]; /* имя tr-dos файла */
char ftyp; /* тип */
unsigned fstart; /* стартов. адр */
unsigned blk; /* длина файла в блоках 256 */
long flen; /* истинная длина файла */
int _tr,_sec; /* временные трек, сектор */

#define MAXSEC 2560
int asec; /* абсолютный сектор (начиная с trk0, sid0, sec0) */
int Nfile; /* число файлов */
int freesec; /* число свободных секторов */
int Line; /* обрабатываемая строка файла */
int TRUNC; /* 0/1 - стандартный/резиновый trd */
int PASS_N; /* 0/1 - номер прохода */
int isHEAD; /* заголовок TRD был? */
int nnn; /* для get_string - длина строки */

int fTRUNC = 0;

int filelength(int f)
{
  int sz = lseek(f,0,SEEK_END);
  lseek(f,0,SEEK_SET);
  return sz;
}

/* -------обработка строк */
#define ENDS(c) (c<=' ' || c==';')
#define CR '\r'

void ini_cright(void)
{
  int i;
  char x,c[16]="<bin2trd.c>";
  for(i=0;i<128;i++) strcpy(tr0+i*16+1,c);
}


void sskip(void) /* Пропуск space,tab */
{
  while ( (*pt==' ')||(*pt==9) ) pt++;
}

void skip_end(void) /* Пропуск текста до конца */
{
  while (*pt!=CR && *pt!='\n') pt++;
  while (*pt==CR || *pt=='\n') pt++;
}

char skip_comma(void) /* Пропуск до ",". (0) - ОК, (1) - СR/LF или ";" */
{
  while (*pt!=',' && *pt!=CR && *pt!='\n' && *pt!=';') pt++;
  if (*pt==',') { pt++; sskip(); return 0;}
  return 1;
}

int cword(char *s)
{
  int i,len=strlen(s);
  for (i=0;i<len;i++) {if(toupper(pt[i])!=s[i]) return -1;}
  pt+=len;
  sskip();
  return 0;
}

void errm(char *emess) /* error */
{
  printf("ERROR (Line=%03u): ",Line);
  printf("<%s>\n",emess);
}

void errex(char *emess) /* fatal error */
{
  printf("ERRLINE [");
  while(*pt_line!=CR && *pt_line!='\n' && *pt_line!=0) {printf("%c",*pt_line);pt_line++;}
  printf("]\nERROR (Line=%03u): ",Line);
  printf("<%s>\n",emess);
  exit(-1);
}

int get_string(char *s, int maxL, int *lens)
{
  int i;
  for(i=0;i<maxL;i++) s[i]=' ';
  if(*pt!='\"') {errm("Unknown keyword");return -1;}
  pt++;
  i=0;
LOO1:
  if(*pt=='\"') {pt++;sskip();*lens=i;return 0;}
  i++;
  if (i>maxL) {errm("Too long parameter"); return -1;}
  *s=*pt;
  s++;
  pt++;
  goto LOO1;
}

/* -------ввод чисел */

unsigned short dec_n(void) /* Десятичное число */
{
  unsigned short i=0;
  while (isdigit(*pt))
	{ i=i*10 + *pt - '0'; pt++;}
  return i;
}

unsigned short hex_n(void) /* Шестнадцатеричное число (#) */
{
  unsigned short i=0;
  char c;
  while (isxdigit(*pt))
	{
	  if (isdigit(*pt)) i= (i<<4) + *pt -'0';
	  else {c=toupper(*pt); i = (i<<4) + c -'A'+10;}
	  pt++;
	}
  return i;
}

short num(unsigned int *i)  /* Число без знака (0-ok; -1-bad) */
{
  if (isdigit(*pt)) {*i=dec_n();return 0;}
  if (*pt=='#')
     {
	  pt++;
	  if(!isxdigit(*pt)) goto ERRNUM;
	  *i=hex_n();return 0;
     }
ERRNUM:
  errm("Illegal number");
  return -1;
}



/* -------вспомогательные */

int load_file(int HB)   /* загрузить очередной файл (0/1 - bin/hobeta) */
{
   unsigned int i,j,k,check;
   char hhead[17];
   /* открыть файл */
   HI=open(Fname,O_RDONLY | O_BINARY);
   if(HI==-1)
    {
      printf("ERROR (Line=%03u, File=\"%s\")\n",Line,Fname);
      perror("FILE ERROR");
      exit(-1);
    }

   if(HB==0)
   /* BIN */
   {
    flen=filelength(HI);
    if(flen>65536) errex("Binary file longer then 65536 bytes");
    if(flen==0) errex("Binary file has zero length");
    blk=(unsigned)(flen/256L);
    if(flen%256L!=0L) blk++;
   }
   else
   /* HOBETA */
   {
    read(HI,hhead,17);
    for(i=0;i<8;i++) TRDOSname[i]=hhead[i];
    ftyp=hhead[8];
    fstart=(long)hhead[9]+(long)hhead[10]*256L;
    flen=(long)hhead[11]+(long)hhead[12]*256L;
    blk=hhead[14];
    check=hhead[15]+hhead[16]*256;
    for(j=i=0; i<0x0F; ++i)
    {
       k = hhead[i]; k &= 0xFF;
       j += (k * 0x0101 + i);
    }
    j &= 0xFFFF;
    if(j!=check) errex("Illegal checksum in header of hobeta");
   }
   /* записать файл */
   if (PASS_N)
   {
     unsigned long blen=(unsigned long)blk*256L;
     char *mem=(char*)malloc(blen);
     if(mem==0) errex("Out of Memory");
     read(HI,mem,blen);
     write(HO,mem,blen);
     free(mem);
   }
   close (HI);
   return 0;
}

void tr_sec(int abss) /* получить дорожку/сектор по абс сектору */
{
   _tr=(abss)/16;
   _sec=(abss)%16;
}

void putFAT(char cl)
{
  /* задать параметры в FAT */
  char *fd=tr0+Nfile*16;
  tr_sec(asec);
  strcpy(fd,TRDOSname);
  fd[8]=ftyp;
  fd[9]=fstart%256;
  fd[10]=fstart/256;
  fd[11]=flen%256;
  fd[12]=flen/256;
  fd[13]=blk;
  fd[14]=_sec;
  fd[15]=_tr;

  asec+=blk;
  if(asec>=((TRUNC?255:80)*16*2))
  {
    if(TRUNC==0)
      errex("Standart .TRD more then 655.360 bytes ");
    else
      errex("Extended .TRD more then 2.088.960 bytes ");
  }

  Nfile++;

  if(PASS_N)
  {
   printf(
   "[%c%03u] Name=\"%s%c\" Len=%05u Start=%05u Blk=%03u Trk=%03u Sec=%02u\n",
   cl,Nfile,TRDOSname,ftyp,(int)flen,fstart,blk,_tr,_sec);
  }

}


void get_default(void) /* установить парам TRDOS файла по умолчанию */
{
  int i,j,k,space;
  char *b=Fname;

  for(i=strlen (b);i>0;)
  {
    i--;
    if (b[i]=='\\') break;
  }
  j=strlen(b)-i;
  space=0;
  for(k=0;k<8;k++)
  {
     if(b[k+i]=='.') space=1;
     if(k>=j) space=1;
     if(space==0) TRDOSname[k]=b[k+i];
     else TRDOSname[k]=' ';
  }
  ftyp='C';
  fstart=0;
}

void set_TRD_name(void)
{
  int i,j,k;
  char *b=LISTname;
  i=strlen(b);
  for(j=0;j<i;j++) b[j]=tolower(b[j]);
  if(b[i-3]!='t' || b[i-2]!='r' || b[i-1]!='l')
      {
       errm("Descriptor must have TRL extention");
       exit(-1);
      }
  strcpy(TRDname,LISTname);
  TRDname[i-1]='d';
}

int get_TYP(void) /* получить тип файла */
{
  if(skip_comma()) goto ERT;
  if(*pt==',') return 0;
  if(get_string(&ftyp,1,&nnn)==0) return 0;
ERT:
  errex("Illegal type of TR-DOS file");
  return -1;
}

int get_MSDOSname(void)
{
  if(ENDS(*pt)) errex("Name of file expected");
  if(get_string(Fname,79,&nnn)) errex("Error in name of file");
  Fname[nnn]=0;
  return 0;
}

int get_TRDOSname(void)
{                                              
  int i;
  if(skip_comma()) goto ERTD;
  if(*pt==',') return 0;
  for(i=0;i<8;i++)TRDOSname[i]=' ';
  if(get_string(TRDOSname,8,&nnn)==0) return 0;
ERTD:
  errex("Error in name of TRDOS file");
  return -1;
}

int get_STRT(void)
{
  if(skip_comma()) goto ERS;
  if(num(&fstart)==0) return 0;
ERS:
  errex("Error in <start> parameter");
  return -1;
}



/* -------трансляция команд */

int d_disk(int T)
{
   if(isHEAD)errex("Second header of disk");
   isHEAD++;
   TRUNC=T;
   if(ENDS(*pt)) return 0;
   if(get_string(DNAME,8,&nnn)) errex("Illegal name of TRDOS disk");
   return 0;
}

int d_file(int bin_type)
{
  if (Nfile>=128) errex("More then 128 files");
  get_MSDOSname();
  get_default();
  load_file(bin_type);
  if(!(ENDS(*pt)))get_TRDOSname();
  if(!(ENDS(*pt)))get_TYP();
  if(!(ENDS(*pt)))get_STRT();
  putFAT(bin_type?'H':'B');

  return 0;

}

/* -------работа с TRD */


void ini_pass(void)
{
 asec=16; /* исключая т.файлов */
 Nfile=0;
 Line=1;
 isHEAD=0;
}


int com_type(void) /* Получить номер команды */
{ /* (0-нет, 1/2/3/4-normal/extend/bin/hobeta, -1-error) */
  int ct;
  sskip();
  if(ENDS(*pt)) return 0;
  ct=-1;
  switch(toupper(*pt))
  {
    case 'N':if(cword("NORMAL")==0)ct=1;break;
    case 'E':if(cword("EXTENDED")==0)ct=2;break;
    case 'B':if(cword("BINARY")==0)ct=3;break;
    case 'H':if(cword("HOBETA")==0)ct=4;break;
    case 'T':if(cword("TRUNC")==0)ct=5;break;
  }
  if(ct==-1)
      errex("Unknown keyword");
  return ct;
}

int pass(int N)
{
   unsigned len;
   int HI;
   PASS_N=N;
   ini_pass();
   /* загрузить дескриптор */
   HI=open(LISTname,O_BINARY | O_RDONLY);
   if (HI==-1){perror("File open ERROR");exit(-1);}
   len=filelength(HI);
   printf("Input file: %s (%u bytes)\n\n",LISTname,len);
   ppt=pt=(char *)malloc(len+2);
   if(ppt==0) { printf("Out of Memory!\n"); exit(-1); }
   read(HI,ppt,len);
   ppt[len]='\n'; ppt[len+1]=0;
   close(HI);
NEWLINE:
   /* прочитать строчку */
   if(*pt==0){free(ppt); return 0;} /* конец файла */
   pt_line=pt;
   switch(com_type())
   {
     case 0:break;
     case 1:if(d_disk(0)!=0)return -1;break;
     case 2:if(d_disk(1)!=0)return -1;break;
     case 3:if(d_file(0)!=0)return -1;break;
     case 4:if(d_file(1)!=0)return -1;break;
     case 5:fTRUNC=1;break;
     default:return -1;
   }
   skip_end();
   Line++;
   goto NEWLINE;

}

int open_trd(void)
{
  int i;
  HO=open(TRDname,O_BINARY | O_CREAT | O_TRUNC | O_RDWR); /* ,S_IWRITE); */
  if (HO==-1) {perror("Error of disk image making\n"); return -1;}
  /* заполнить заголовок диска */
  tr_sec(asec);
  freesec=16*(TRUNC?255:80)*2-asec;
  for(i=0;i<9;i++)
	   sec9[0xEA+i]=32;

  sec9[0xE1]=_sec;
  sec9[0xE2]=_tr;
  sec9[0xE3]=0x16;
  sec9[0xE4]=Nfile;
  sec9[0xE5]=freesec%256;
  sec9[0xE6]=freesec/256;
  sec9[0xE7]=0x10;
  sec9[0xF4]=00;
  write(HO,tr0,8*256);
  write(HO,sec9,256);
  for (i=0;i<8*256;i++) tr0[i]=0xDD;
  write(HO,tr0,7*256);

  printf("%s TR-DOS Disk (DD80)  Label: \"%8s\"\n"
	 "Files: %u  Free sectors: %u\t\n\n",
	(TRUNC?"Extended":"Normal"),DNAME,Nfile,freesec);
  return 0;
}

int close_trd(void)
{
  if(TRUNC==0)
  {
    unsigned i;
    long unsigned nulldat;
    long unsigned dummyL=32768L;
    char *pp=(char*)malloc((unsigned)dummyL);
    for (i=0;i<dummyL;i++) pp[i]=0xCF;
    if(!fTRUNC && asec<MAXSEC)
    {
      nulldat=(long)(MAXSEC-asec)*256L;
      while(nulldat>dummyL)
      {
	write(HO,pp,(unsigned)dummyL);
	nulldat-=dummyL;
      }
      if(nulldat>0)
      {
	write(HO,pp,(unsigned)nulldat);
      }
    }
    free(pp);
  }
  close(HO);
  return 0;
}

int bin2trd(void)
{
  if (pass(0)) return -1;
  if (open_trd()) return -1;
  if (pass(1)) return -1;
  if (close_trd()) return -1;
  return 0;
}

int main(short n_arg,char *arg[]) /****MAIN****/
{
  int res;
  printf("\nMaking TRD file from binaries or/and hobeta files (v1.0-2002)");
  printf("\n(c) 1999  Copper Feet (Vyacheslav Mednonogov)");
  printf("\n    2002  Modification by Alexander Shabarshin (shaos@mail.ru)\n\n");
  if (n_arg==1)
    {
      printf("   Usage:\n\tbin2trd <filename>.trl\n\n");
      return -1;
    }
  strcpy(LISTname,arg[1]);
  strcpy(DNAME,"nonamed ");
  set_TRD_name();
  ini_cright();
  res = bin2trd();
  if(fTRUNC) printf("\nTRD file was truncated\n");
  if(res==0) printf("\nOk!\n\n");
  return res;
}


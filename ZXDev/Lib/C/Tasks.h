#ifndef Tasks__h
#define Tasks__h

typedef
  struct Tasks_Context {
    INTEGER _prvt0, _prvt1;
    INTEGER _prvt2, _prvt3, _prvt4;
  } Tasks_Context;

typedef
  struct Tasks_Huge {
    INTEGER _prvt0, _prvt1;
    char _prvt2 [120];
    INTEGER _prvt3, _prvt4, _prvt5;
  } Tasks_Huge;

typedef
  struct Tasks_Large {
    INTEGER _prvt0, _prvt1;
    char _prvt2 [100];
    INTEGER _prvt3, _prvt4, _prvt5;
  } Tasks_Large;

typedef
  struct Tasks_Medium {
    INTEGER _prvt0, _prvt1;
    char _prvt2 [80];
    INTEGER _prvt3, _prvt4, _prvt5;
  } Tasks_Medium;

typedef
  struct Tasks_Small {
    INTEGER _prvt0, _prvt1;
    char _prvt2 [60];
    INTEGER _prvt3, _prvt4, _prvt5;
  } Tasks_Small;

typedef
  struct Tasks_Tiny {
    INTEGER _prvt0, _prvt1;
    char _prvt2 [40];
    INTEGER _prvt3, _prvt4, _prvt5;
  } Tasks_Tiny;


#define Tasks_Context__typ 0
#define Tasks_Tiny__typ 0
#define Tasks_Small__typ 0
#define Tasks_Medium__typ 0
#define Tasks_Large__typ 0
#define Tasks_Huge__typ 0


extern unsigned char Tasks_count;
#define Tasks_Count() Tasks_count

#define Tasks_Id(ctx) (int)ctx

extern int Tasks_myid;
#define Tasks_MyId() Tasks_myid

extern void Tasks_Run (void);

extern void Tasks_Spawn_Ex (Tasks_Context *ctx, unsigned int size, void (*proc)(void)) __z88dk_callee;
#define Tasks_Spawn(ctx, proc) Tasks_Spawn_Ex((void*)&ctx, sizeof(ctx), proc)

extern void Tasks_Yield (void);

extern void Tasks__init (void) __preserves_regs(b,c,d,e,iyl,iyh);


#endif

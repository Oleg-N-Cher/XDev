#ifndef Tasks__h
#define Tasks__h

typedef
  struct Tasks_Context {
    INTEGER _prvt0, _prvt1;
    INTEGER _prvt2, _prvt3;
  } Tasks_Context;

typedef
  struct Tasks_Huge {
    INTEGER _prvt0, _prvt1;
    char _prvt2 [120];
    INTEGER _prvt3, _prvt4;
  } Tasks_Huge;

typedef
  struct Tasks_Large {
    INTEGER _prvt0, _prvt1;
    char _prvt2 [100];
    INTEGER _prvt3, _prvt4;
  } Tasks_Large;

typedef
  struct Tasks_Medium {
    INTEGER _prvt0, _prvt1;
    char _prvt2 [80];
    INTEGER _prvt3, _prvt4;
  } Tasks_Medium;

typedef
  struct Tasks_Small {
    INTEGER _prvt0, _prvt1;
    char _prvt2 [60];
    INTEGER _prvt3, _prvt4;
  } Tasks_Small;

typedef
  struct Tasks_Tiny {
    INTEGER _prvt0, _prvt1;
    char _prvt2 [40];
    INTEGER _prvt3, _prvt4;
  } Tasks_Tiny;


#define Tasks_Context__typ NIL
#define Tasks_Tiny__typ NIL
#define Tasks_Small__typ NIL
#define Tasks_Medium__typ NIL
#define Tasks_Large__typ NIL
#define Tasks_Huge__typ NIL


extern unsigned char Tasks_count;
extern unsigned int Tasks_runned;


extern unsigned char Tasks_Run (void);
extern void Tasks_Spawn_Ex (Tasks_Context *ctx, unsigned int size, void (*proc)(void));// __z88dk_callee;
#define Tasks_Spawn(ctx, proc) Tasks_Spawn_Ex((void*)&ctx, sizeof(ctx), proc)
extern void Tasks_Yield (void);

#define Tasks__init() Tasks_count = 0; Tasks_runned = 0


#endif

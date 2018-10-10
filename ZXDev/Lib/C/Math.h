#ifndef Math__h
#define Math__h


extern float Math_ArcTan (float x);
extern float Math_Cos (float x);
extern float Math_Exp (float x);
extern float Math_Ln (float x);
extern float Math_Sin (float x);
extern float Math_Sqrt (float x);
extern void Math_UIntToBCD (unsigned int n) __z88dk_fastcall;
extern void Math_Randomize (void);
extern unsigned int Math_RndRange (unsigned int min, unsigned int max);
#define Math__init()


#endif

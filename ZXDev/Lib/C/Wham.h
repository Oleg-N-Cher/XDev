#ifndef Wham__h
#define Wham__h


extern void Wham_InitPlayNote (unsigned int chan1, unsigned int chan2);
extern void Wham_PlayNote (void);
extern void Wham_PlayKeyPress (unsigned int chan1, unsigned int chan2);
extern void Wham_PlayTuneEnd (unsigned int chan1, unsigned int chan2);
extern void Wham_SetTempo (unsigned char tempo);
#define Wham__init()


#endif

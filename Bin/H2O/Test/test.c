#include "mod.h"

typedef T t1;
pT pt1;

int i1;
short int i2;
long int i3;
unsigned int i4;
unsigned short int i5;
unsigned long int i6;

unsigned u;
short s;
long l;
char c;

int * pi;
int ** ppi;

int f1(int x, int y);
int * f2(int x, int y);
int (* f3)(int x, int y);
void f4 (void);
void f5 (int, int, ...);

int ai [];
int * aai1 [3][3];
int (* aai2) [3][3];

struct A {
  int a:1;
  int b;
} sA1;

struct A sA2;
struct A * psA;

struct A * (* next)(struct A * p);

enum B { a=1, b, c } e1;

typedef unsigned long long I;

I i7;
volatile I i8;
volatile I i9, * const i10;
int a[sizeof(int)];


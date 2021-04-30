IMPLEMENTATION MODULE mathlib;
CONST NoOfCoeff =10;
      MaxPosReal=1.0E38;
      MinPosReal=1.0E-38;
      oneOe     =3.67879515E-1; (*1.0/e*)

      PIo2=PI/2.0;
      PIo4=PI/4.0;
      PI2 =PI*2.0;


PROCEDURE Sin(x:REAL):REAL;
CONST PI  =3.1415926531932;
      PIo2=PI/2.0;
      PIo4=PI/4.0;
      PI2 =PI*2.0;
VAR y,xa,xb,xc,xd:REAL;
    sign,q:BOOLEAN;
BEGIN
  IF x>=0.0 THEN sign:=FALSE ELSE sign:=TRUE; x:=-x END;
  IF x>PI2 THEN x:=x-PI2*FLOAT(TRUNC(x/PI2)) END;
  IF x>PI THEN sign:=NOT sign; x:=x-PI END;
  q:=FALSE;
  WHILE x>PIo4 DO
    x:=ABS(x-PIo2);
    q:=NOT q;
  END;
  xa:=x*x;
  IF q THEN
    xb:=xa*xa;
    y:=1.0 - 0.5*xa + 0.041666666666*xb - 0.0013888888888*xb*xa;
    IF x>0.3 THEN
      xc:=xb*xb;
      y:=y + 0.0000248015873*xc;
      IF x>0.65 THEN y:=y - 0.0000002755731922*xc*xa END;
    END;
  ELSE
    xb:=xa*x;
    xc:=xb*xa;
    y:=x - 0.16666666666666*xb + 0.008333333333333*xc;
    IF x>0.2 THEN
      xd:=xc*xa;
      y:=y - 0.0001984126984*xd;
      IF x>0.45 THEN y:=y + 0.00000275573*xd*xa END;
    END;
  END;
  IF sign THEN y:=-y END;
  RETURN y;
END Sin;

PROCEDURE Cos(x:REAL):REAL;
BEGIN
  RETURN Sin(x+PIo2);
END Cos;

PROCEDURE Tan(x:REAL):REAL;
BEGIN
  RETURN Sin(x)/Cos(x)
END Tan;

PROCEDURE Cot(x:REAL):REAL;
BEGIN
  RETURN Cos(x)/Sin(x)
END Cot;

PROCEDURE ATan(x:REAL):REAL;
CONST C0= 0.463647609;
      C1=-1.570796327;
      C2=-80.34270561;
      C3=-1.191447224;
      C4=-0.07833542786;
      C5= 1.258464112;
      C6= 2.104518952;
      C7= 6.364241687;
      C8=26.27277525;
      C9=12.37469388;

VAR y,h:REAL;
    sign:BOOLEAN;

BEGIN
  IF x>=0.0 THEN sign:=FALSE ELSE sign:=TRUE; x:=-x END;
  IF x>1.0 THEN
    x:=1.0/x;
    h:=C1;
  ELSE h:=0.0 END;
  IF x>0.5 THEN
    h:=h+C0;
    x:=(x*2.0-1.0)/(x+2.0);
  END;
  y:=x*x;
  y:=ABS(x/(C2/(C3/(C4/(y+C5)+C6+y)+C7+y)+C8+y)*C9+h);
  IF sign THEN y:=-y END;
  RETURN y
END ATan;

PROCEDURE Sqrt(x:REAL):REAL;
VAR y,z,e,ee:REAL;
BEGIN
  IF x>0.0 THEN
    y:=2.0;
    REPEAT z:=y; y:=z*z UNTIL y>x;
    e:=y;
    LOOP
      y:=z;
      z:=0.5*(y+x/y);
      ee:=ABS(y-z);

      IF (ee=e) OR (ee>=e) THEN EXIT END;     (* kranke float aritmetik *)

      e:=ee;
    END;
    RETURN z;
  END;
  RETURN 0.0
END Sqrt;


PROCEDURE ASin(x:REAL):REAL;
VAR s:REAL;
BEGIN
  s:=1.0-x*x;
  IF s<=0.0 THEN
    IF x>=0.0 THEN RETURN PI/2.0 ELSE RETURN -PI/2.0 END;
  END;
  RETURN ATan(x/Sqrt(s))
END ASin;

PROCEDURE ACos(x:REAL):REAL;
BEGIN RETURN PI/2.0-ASin(x) END ACos;

PROCEDURE Log(x:REAL):REAL;
VAR f,s,t,xm,xp,y:REAL;
    i:CARDINAL;
BEGIN
  IF x<=0.0 THEN RETURN -MaxPosReal END;
  IF x<oneOe THEN
    i:=0;
    REPEAT x:=x*e; INC(i) UNTIL x>oneOe;
    RETURN Log(x)-FLOAT(i);
  ELSIF x<=e THEN
    i:=1;
    xm:=x-1.0;
    xp:=x+1.0;
    s:=xm/xp;
    f:=s;
    y:=f*f;
    REPEAT INC(i,2); f:=f*y; t:=f/FLOAT(i); s:=s+t UNTIL ABS(t)<=epsilon;
    RETURN 2.0*s
  ELSE
    i:=0;
    REPEAT x:=x*oneOe; INC(i) UNTIL x<e;
    RETURN Log(x)+FLOAT(i);
  END;
END Log;

PROCEDURE Exp(x:REAL):REAL;
VAR f,s:REAL;
    i:CARDINAL;
BEGIN
  IF x<-45.0 THEN RETURN MinPosReal
  ELSIF x<0.0 THEN RETURN 1.0/Exp(-x)
  ELSIF x<1.0 THEN
    i:=0;
    s:=1.0;
    f:=1.0;
    REPEAT INC(i);f:=f*x/FLOAT(i); s:=s+f UNTIL f<epsilon;
    RETURN s
  ELSIF x<45.0 THEN
    f:=Exp(x-FLOAT(TRUNC(x)));
    FOR i:=1 TO TRUNC(x) DO f:=f*e END;
    RETURN f
  ELSE RETURN MaxPosReal END;
END Exp;

PROCEDURE Power(x, y:REAL):REAL;
BEGIN RETURN Exp(Log(x)*y) END Power;

PROCEDURE Round(x:REAL):INTEGER;
BEGIN 
  IF x>=0.0 THEN x:=x+0.5 ELSE x:=x-0.5 END;
  RETURN INT(x);
END Round;

PROCEDURE Floor(x:REAL):REAL;
VAR y:REAL;
BEGIN
  y:=VAL(REAL, VAL(INTEGER, x));
  IF y>x THEN y:=y-1.0 END;  
  RETURN y;
END Floor;




VAR heps:REAL;
BEGIN
  heps:=0.125;
  REPEAT
    epsilon:=heps;
    heps:=heps/2.0;
  UNTIL (heps+2.0 <= 2.0);
END mathlib.

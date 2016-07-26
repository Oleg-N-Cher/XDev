MODULE TestASH;

VAR
  res, longarg: LONGINT;

BEGIN
  res := ASH(longarg, 60); (* Translates to:

	TestASH_res = __ASHL(TestASH_longarg, 60);
	
#define __ASHL(x, n)	((INTEGER)(x)<<(n))

Argument TestASH_longarg casts to INTEGER and high bits are lost!

*)
END TestASH.

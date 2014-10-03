#include "SYSTEM.h"
#include "Ignore.h"
#include "SdlLib.h"


static INTEGER Input_n, Input_in, Input_out;
static CHAR Input_keybuf[32];
static SHORTINT Input_Uni[72];
static CHAR Input_Ch[72];


export INTEGER Input_Available (void);
static BOOLEAN Input_CheckAddKey (SdlLib_KeyboardEvent keybev);
static void Input_Quit (void);
export CHAR Input_Read (void);
static INTEGER Input_TimeLeft (void);
static void Input_UtoC (SHORTINT u, CHAR c);


/*================================== Header ==================================*/

static void Input_Quit (void)
{
	SdlLib_Quit();
	__HALT(0);
}

static BOOLEAN Input_CheckAddKey (SdlLib_KeyboardEvent keybev)
{
	INTEGER i;
	CHAR key;
	if ((keybev.keysym.modifier & 0x0300) != 0x0) {
		if (keybev.keysym.sym == 285) {
			Input_Quit();
		}
		return 0;
	}
	if ((keybev.keysym.modifier & 0xc0) != 0x0 || Input_n >= 32) {
		return 0;
	}
	for (;;) {
		if ((int)keybev.keysym.unicode >= 32 && (int)keybev.keysym.unicode < 127) {
			key = (CHAR)keybev.keysym.unicode;
			break;
		}
		switch (keybev.keysym.sym) {
			case 8: case 9: case 13: case 27: case 127: 
				key = (CHAR)keybev.keysym.sym;
				goto exit__0;
				break;
			case 258: 
				key = 0x19;
				goto exit__0;
				break;
			case 260: 
				key = 0x1b;
				goto exit__0;
				break;
			case 262: 
				key = 0x1a;
				goto exit__0;
				break;
			case 264: 
				key = 0x18;
				goto exit__0;
				break;
			case 266: 
				key = 0x7f;
				goto exit__0;
				break;
			case 271: 
				key = 0x0d;
				goto exit__0;
				break;
			default: 
				break;
		}
		if (keybev.keysym.sym >= 273 && keybev.keysym.sym <= 276) {
			key = (CHAR)((keybev.keysym.sym - 273) + 24);
			break;
		}
		if (keybev.keysym.sym >= 282 && keybev.keysym.sym <= 293) {
			key = (CHAR)((keybev.keysym.sym - 282) + 1);
			break;
		}
		i = 71;
		while (i >= 0) {
			if (keybev.keysym.unicode == Input_Uni[__X(i, 72)]) {
				key = Input_Ch[__X(i, 72)];
				goto exit__0;
			}
			i += -1;
		}
		return 0;
	}
	exit__0:;
	Input_keybuf[__X(Input_in, 32)] = key;
	Input_in = __MASK(Input_in + 1, -32);
	Input_n += 1;
	return 1;
}

INTEGER Input_Available (void)
{
	SdlLib_Event event;
	while (SdlLib_PollEvent(&event, SdlLib_Event__typ) != 0) {
		if (__VAL(CHAR, event.type) == 0x02) {
			if (Input_CheckAddKey(__VAL(SdlLib_KeyboardEvent, event))) {
			}
		} else if (__VAL(CHAR, event.type) == 0x0c) {
			Input_Quit();
		}
	}
	return Input_n;
}

/*--------------------------------- Cut here ---------------------------------*/
static INTEGER Input_TimeLeft (void)
{
	INTEGER nextTime, now;
	nextTime = 0;
	now = SdlLib_GetTicks();
	if (nextTime <= now) {
		nextTime = now + 10;
		return 0;
	}
	return nextTime - now;
}

CHAR Input_Read (void)
{
	CHAR key;
	SdlLib_Event event;
	if (Input_Available() == 0) {
		for (;;) {
			while (SdlLib_WaitEvent(&event, SdlLib_Event__typ) != 0) {
				if (__VAL(CHAR, event.type) == 0x02) {
					if (Input_CheckAddKey(__VAL(SdlLib_KeyboardEvent, event))) {
						goto exit__1;
					}
				} else if (__VAL(CHAR, event.type) == 0x0c) {
					Input_Quit();
				}
			}
			SdlLib_PumpEvents();
			SdlLib_Delay(Input_TimeLeft());
		}
		exit__1:;
	}
	Input_n -= 1;
	key = Input_keybuf[__X(Input_out, 32)];
	Input_out = __MASK(Input_out + 1, -32);
	return key;
}

/*--------------------------------- Cut here ---------------------------------*/
static void Input_UtoC (SHORTINT u, CHAR c)
{
	Input_Uni[__X(Input_n, 72)] = u;
	Input_Ch[__X(Input_n, 72)] = c;
	Input_n += 1;
}


export void *Input__init(void)
{
	__DEFMOD;
	__IMPORT(Ignore__init);
	__IMPORT(SdlLib__init);
	__REGMOD("Input", 0);
/* BEGIN */
	Input_n = 0;
	Input_UtoC(1041, '<');
	Input_UtoC(1046, ':');
	Input_UtoC(1061, '{');
	Input_UtoC(1066, '}');
	Input_UtoC(1069, '\"');
	Input_UtoC(1070, '>');
	Input_UtoC(1030, 'S');
	Input_UtoC(1028, '\"');
	Input_UtoC(1031, '}');
	Input_UtoC(1025, '~');
	Input_UtoC(1073, ',');
	Input_UtoC(1078, ';');
	Input_UtoC(1093, '[');
	Input_UtoC(1098, ']');
	Input_UtoC(1101, '\'');
	Input_UtoC(1102, '.');
	Input_UtoC(1110, 's');
	Input_UtoC(1108, '\'');
	Input_UtoC(1111, ']');
	Input_UtoC(1105, '`');
	Input_UtoC(1060, 'A');
	Input_UtoC(1048, 'B');
	Input_UtoC(1057, 'C');
	Input_UtoC(1042, 'D');
	Input_UtoC(1059, 'E');
	Input_UtoC(1040, 'F');
	Input_UtoC(1055, 'G');
	Input_UtoC(1056, 'H');
	Input_UtoC(1064, 'I');
	Input_UtoC(1054, 'J');
	Input_UtoC(1051, 'K');
	Input_UtoC(1044, 'L');
	Input_UtoC(1068, 'M');
	Input_UtoC(1058, 'N');
	Input_UtoC(1065, 'O');
	Input_UtoC(1047, 'P');
	Input_UtoC(1049, 'Q');
	Input_UtoC(1050, 'R');
	Input_UtoC(1067, 'S');
	Input_UtoC(1045, 'T');
	Input_UtoC(1043, 'U');
	Input_UtoC(1052, 'V');
	Input_UtoC(1062, 'W');
	Input_UtoC(1063, 'X');
	Input_UtoC(1053, 'Y');
	Input_UtoC(1071, 'Z');
	Input_UtoC(1092, 'a');
	Input_UtoC(1080, 'b');
	Input_UtoC(1089, 'c');
	Input_UtoC(1074, 'd');
	Input_UtoC(1091, 'e');
	Input_UtoC(1072, 'f');
	Input_UtoC(1087, 'g');
	Input_UtoC(1088, 'h');
	Input_UtoC(1096, 'i');
	Input_UtoC(1086, 'j');
	Input_UtoC(1083, 'k');
	Input_UtoC(1076, 'l');
	Input_UtoC(1100, 'm');
	Input_UtoC(1090, 'n');
	Input_UtoC(1097, 'o');
	Input_UtoC(1079, 'p');
	Input_UtoC(1081, 'q');
	Input_UtoC(1082, 'r');
	Input_UtoC(1099, 's');
	Input_UtoC(1077, 't');
	Input_UtoC(1075, 'u');
	Input_UtoC(1084, 'v');
	Input_UtoC(1094, 'w');
	Input_UtoC(1095, 'x');
	Input_UtoC(1085, 'y');
	Input_UtoC(1103, 'z');
	Input_n = 0;
	Input_in = 0;
	Input_out = 0;
	Ignore_Int(SdlLib_EnableUNICODE(1));
	Ignore_Int(SdlLib_EnableKeyRepeat(500, 50));
	__ENDMOD;
}


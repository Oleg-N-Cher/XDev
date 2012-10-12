#include "Console.h"

//static void Unused (void)
//{
//  Beep(100, 100);
//}

int main (int argc, char **argv)
{
  SetColors(0x10 + 0x0B);
  WriteStr("Hello World");

  return 0;
}

/* Sergeev Sergey 10-6 20.01.2016*/
#include<stdio.h>

unsigned FindGCD( unsigned a, unsigned b )
{
  unsigned c;

  c = a % b;
  while (c != 0)
  {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}
unsigned FindLCM( unsigned a, unsigned b )
{
  return a * b / FindGCD(a, b);
}
void main( void )
{
  unsigned a, b;

  printf("A:");
  scanf("%u", &a);
  printf("B:");
  scanf("%u", &b);
  printf("GCD %u\n", FindGCD(a, b));
  printf("LCM %u\n", FindLCM(a, b));
}

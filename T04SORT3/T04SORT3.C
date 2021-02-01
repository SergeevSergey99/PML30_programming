/* Sergeev Sergey */
/* 10-6 */
/* 20.01.2016 */
#include<stdio.h>

void main( void )
{
  float a, b, c, tmp;

  printf("A:");
  scanf("%f", &a);
  printf("B:");
  scanf("%f", &b);
  printf("C:");
  scanf("%f", &c);
  if (a > b)
  {
    tmp = a;
    a = b;
    b = tmp;
  }
  if (b > c)
  {
    tmp = b;
    b = c;
    c = tmp;
  }
  if (a > b)
  {
    tmp = a;
    a = b;
    b = tmp;
  }
  printf("%f %f %f\n", a, b, c);
}
/*End of program*/
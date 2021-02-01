/*Sergeev Sergey 10-6 27.02.2016*/
#include"SEQ.h"
#include<stdio.h>

int SumOfNumbers( int A )
{
  int sum = 0;
  while ( A != 0)
  {
    sum += A % 10;
    A /= 10;
  }
  if (sum % 2 == 0)
    return 1;
  return 0;
}
int Mirrow( int A )
{
  int y = 0, x = A;
  while( x != 0 )
  {
    y = y * 10 + x % 10;
    x /= 10;
  }
  if (y == A)
    return 1;
return 0;
}
void Seq( void )
{
  int Sum = 0, num = 0,mirrs = 0, num2 = 0, num10 = 0,
      Is_first = 1, min, max, x;
  float Averrens = 0;

  do
  {
    printf("X(0 - for Finish): ");
    scanf("%i", &x);
    if (x != 0)
    {
      if (Is_first)
        min = max = x, Is_first = 0;
      if (x < min)
        min = x;
      if (x > max)
        max = x;
      Sum += x;
      num++;
      if (Mirrow( x ))
        mirrs++;
      if (SumOfNumbers( x ))
        num10++;
      if (x % 2 == 0)
        num2++;
    }
  } while (x != 0);
  if (num != 0)
  {
    Averrens = Sum * 1.0 / num;
    printf("Sum   = %i\n", Sum);
    printf("Num   = %i\n", num);
    printf("Ave   = %f\n", Averrens);
    printf("Min   = %i\n", min);
    printf("Max   = %i\n", max);
    printf("Num2  = %i\n", num2);
    printf("Num!2 = %i\n", num - num2);
    printf("Num10 = %i\n", num10);
    printf("Mirrs = %i\n", mirrs);
  }
}
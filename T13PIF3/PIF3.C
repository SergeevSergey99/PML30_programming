/*Sergeev Sergey 10-6 27.02.2016*/
#include<stdio.h>
#include<math.h>
#include"PIF3.h"

void PrintPif3( int N )
{
  int a, b, c;

  for (a = 1; a < N; a++)
    for (b = 1; b < N; b++)
    {
      c = sqrt( a * a + b * b);
      if (a <= b)
        if (c * c == a * a + b * b)
          printf("%i  %i  %i\n", a, b, c);
    }
}
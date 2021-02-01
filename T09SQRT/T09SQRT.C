/*Sergeev Sergey 10-6 06.02.2016*/
#include"sqrt.h"
#include<math.h>
#include<stdio.h>

void main( void )
{
  double x;

  scanf("%lf", &x);
  printf("MySqrt   = %.15f\nRealSqrt = %.15f\n", MySqrt(x), sqrt(x));
}
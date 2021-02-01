/*Sergeev Sergey 10-6 06.02.2016*/
#include<stdio.h>
#include"sqrt.h"
double Abs( double x )
{
  if (x >= 0)
    return x;
  return -x;
}
double MySqrt( double x )
{
  double A0, A1;

  A0 = x;
  A1 = 0.5 * (A0 + x / A0);
  while (Abs( A1-A0 ) > 0.00000000000001)
  {
    A0 = A1;
    A1 = 0.5 * (A0 + x / A0);
  }
  return A1;
}
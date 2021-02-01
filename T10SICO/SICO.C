/*Sergeev Sergey 10-6 13.02.2016*/
#include<stdio.h>
#include"SICO.h"
#include<stdio.h>

double MyPow(double x, int n)
{
  double pow = 1;
  int i;

  for (i = 0; i < n; pow *= x, i++)
  ;
  return pow;
}
int Fact( int x )
{
  int fact = 1, i;

  for (i = 1; i <= x; fact *=i, i++)
  ;
  return fact;
}
double MyAbs( double x )
{
  if (x >= 0)
    return x;
  return -x;
}
double MySin(double x)
{
  double sum = x, an = x;
  int n = 0;

  while(MyAbs( an ) > 0.00000000000001)
  {
    an *= (-1) * x * x / (4.0 * n * n + 10.0 * n + 6.0);
    sum += an;
    n++;
  }
  return sum;
}
double MyCos( double x )
{
  int n = 0;
  double sum = 1, a = 1;
  /*MyPow(-1, n+1) * MyPow( x, n * 2+2) / Fact( 2 * n+2 );
  (2*n +2)*(2*n+1)*/
  while (MyAbs( a ) > 0.000000000000001)
  {
    a *= (-1) * x * x / (2 * n + 2) / (2 * n + 1);
    sum += a;
    n++;
  }
  return sum;
}
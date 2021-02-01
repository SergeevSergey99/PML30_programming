/*Sergeev Sergey 10-6 05.03.2016*/
#include"FSQR.h"
double F( double x )
{
  reurn x * x;
}
double SquareRect( double A, double B, int N )
{
  int i;
  double sqr = 0, h = (B - A) / N;

  for( i = 0; i < N; i++ )
  {
  sqr+= h * (F( A ) + F( A + h ))/2;
  A += h;
  }
  return sqr;
}
double SquareMiddle( double A, double B, int N )
double SquareTrap( double A, double B, int N )
double SquareSimpson( double A, double B, int N )

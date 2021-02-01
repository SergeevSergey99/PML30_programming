/*Sergeev Sergey 10-6 13.02.2016*/
#include<stdio.h>
#include<math.h>
#include<SICO.h>

void main( void )
{
  double x = 0, Pi = 3.14159265358979;

  scanf( "%lf", &x );
  x *= Pi/180;
  printf( "MySin - %.15f\nSin - %.15f\n", MySin( x ), sin( x ) );
  printf( "MyCos - %.15f\nCos - %.15f\n", MyCos( x ), cos( x ) );
}
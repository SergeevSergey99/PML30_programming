/*Sergeev Sergey 10-6 20.02.2016*/
#include<stdio.h>
#include"WDAY.h"

void main( void )
{
  int D, M, Y;
  scanf("%i\n", &D);
  scanf("%i\n", &M);
  scanf("%i\n", &Y);
  GetWeekDay( D, M, Y );
}
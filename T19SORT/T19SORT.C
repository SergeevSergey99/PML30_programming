/*Sergeev Sergey 10-6 14.05.2016*/
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"SORT.h"

#define MAX 15000

void ( *Fill[] )( int *a, int N ) =
{
FillIncr, FillDecr, FillRand,
FillEqual, FillMostly
};
void main( void )
{
  static int a[MAX];
  int i;

  printf("\n");
  for(i = 0; i <= 4; i++)
  {
    Fill[i]( &a, MAX );
    OutMas( &a, MAX );
  }
  getch();
}
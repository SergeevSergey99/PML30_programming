/*Sergeev Sergey 10-6 20.02.2016*/
#include<stdio.h>
#include"PIF.h"

void PrintPif( int N )
{
  int i, j;

  for( i = 1; i <= N; i++)
    {
      for( j = 1; j <= N; j++)
      {
        if (i * j < 10000)
          printf(" ");
        if (i * j < 1000)
          printf(" ");
        if (i * j < 100)
          printf(" ");
        if (i * j < 10)
          printf(" ");
        printf( " %i", i * j);
      }
    printf("\n");
    }
}
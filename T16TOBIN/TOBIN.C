/*Sergeev Sergey 12.03.2016*/
#include<stdio.h>
#include"TOBIN.h"

void PrintBin( ulong X )
{
  int i;
  for( i = 31; i >= 0; i--)
  {
    if ((X & (1 << i)) != 0)
      printf("1");
    else
      printf("0");
  }
  printf("\n");
  getch();
}
/*Sergeev Sergey 11.10. 2016*/    
#include<stdlib.h>
#include<stdio.h>
#include"FSORT.h"

int main(void)
{ 
  int N, i;
  static int *A;
  Gen(10000);
  N = GetCount();
  A = malloc(sizeof(int) * N);
  if (A == NULL)
    return;
  ReadMas( A, N );        
  QuickSort( A, N );    
  WriteMas( A, N );
  free(A);
  return 0;
}
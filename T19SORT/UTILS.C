/*Sergeev Sergey 10-6 14.05.2016*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"SORT.h"

void FillIncr( int *A, int N )
{
  int i;

  for (i = 0; i < N; i++)
    A[i] = i + 1;
}
void FillDecr( int *A, int N )
{
  int i;

  for (i = 0; i < N; i++)
    A[i] = N - i;
}
void FillRand( int *A, int N )
{
  int i;

  for (i = 0; i < N; i++)
    A[i] = rand() % 100;
}
void FillEqual( int *A, int N )
{
  int i;

  for (i = 0; i < N; i++)
    A[i] = N % 10;
}
void FillMostly( int *A, int N )
{
  int i, q, p;

  FillIncr( A, N);
  for (i = 0; i <= N / 20; i++)
    {
      p = rand() % N;
      q = rand() % N;
      Swap( &A[p], &A[q] );
    }
}
void OutMas( int *A, int N )
{
  int i;
  for (i = 0; i < N; i++)
    printf( "%i ", A[i] );
  printf("\n");
}
int CheckSort( int *A, int N )
{
  int i;

  for (i = 0; i < N - 1; i++)
  if (A[i] > A[i +1])
    return 0;
  return 1;
}
/*Sergeev Sergey 11-6 27.09.2016*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"SORT.h"

void FillIncr( float *A, int N )
{
  int i;

  for (i = 0; i < N; i++)
    A[i] = i + 1;
}
void FillDecr( float *A, int N )
{
  int i;

  for (i = 0; i < N; i++)
    A[i] = N - i;
}
void FillRand( float *A, int N )
{
  int i;

  for (i = 0; i < N; i++)
    A[i] = rand() % 100;
}
void FillEqual( float *A, int N )
{
  int i;

  for (i = 0; i < N; i++)
    A[i] = N % 10;
}
void FillMostly( float *A, int N )
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
void OutMas( float *A, int N )
{
  int i;
  for (i = 0; i < N; i++)
    printf( "%i ", A[i] );
  printf("\n");
}
void Swap( float *A, float *B )
{
  int tmp = *A;

  *A = *B;
  *B = tmp;
}
int CheckSort( float *A, int N )
{
  int i;

  for (i = 0; i < N - 1; i++)
  if (A[i] > A[i + 1])
    return 0;
  return 1;
}
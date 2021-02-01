/*Sergeev Sergey 11.10. 2016*/   
#include<stdio.h>
#include<stdlib.h>
#include"FSORT.h"

void Gen(int N)
{
  int i;
  FILE *F;

  F = fopen("IN.TXT","w");
  for(i = 0; i < N; i++)
    fprintf( F, "%i\n", rand() - RAND_MAX / 2 );
  fclose(F);
}
int GetCount(void)
{
  int cnt = 0, x;
  FILE *F;

  F = fopen("IN.TXT","r");
  if (F == NULL)
    return 0;
  while (fscanf( F, "%i", &x ) == 1)
    cnt++;
  fclose(F);
  return cnt;
}
void ReadMas(int *A, int N)
{
  int i;
  FILE *F;

  F = fopen("IN.TXT","r");
  if (F == NULL)
    return;
  for(i = 0; i < N; i++)
    fscanf( F, "%i", &A[i]);
  fclose(F);
}
void WriteMas(int *A, int N)
{
  int i;
  FILE *F;

  F = fopen("OUT.TXT","w");
  if (F == NULL)
    return;
  for(i = 0; i < N; i++)
    fprintf( F, "%i\n", A[i]);
  fclose(F);
}
void Swap(int *A, int *B)
{
  int tmp = *A;

  *A = *B;
  *B = tmp;
}
void QuickSort(int *A, int N)
{

  int b = 0, e = N - 1;
  int  x = A[N / 2];

  while (b <= e)
  {
    while (A[b] < x)
      b++;
    while (A[e] > x)
      e--;
    if (b <= e)
    {
      if (b != e)
        Swap( &A[b], &A[e] );
      b++;
      e--;
    }
  }
  if (N >= 2)
  {
  QuickSort( A, e + 1 );
  QuickSort( A + b, N - b );
  }
}
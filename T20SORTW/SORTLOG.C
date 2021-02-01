/*Sergeev Sergey 11-6 27.09.2016*/
#include<stdlib.h>
#include"SORT.h"

static float *B;

void MergeSortRec( float *A, int N )
{
  int M, k, i = 0, j = N / 2;

  if (N < 2) 
    return;
  M = N / 2;
  MergeSortRec( A, M );
  MergeSortRec( A + M, N - M );
  
  for (k = 0; k < N; k++)
    if (j >= N || i < M && A[i] < A[j])
      B[k] = A[i++];
    else
      B[k] = A[j++];

  for (k = 0; k < N; k++)
    A[k] = B[k];
}
void MergeSort(float *A, int N)
{
  B = malloc(sizeof(float) * N);
  if (B == NULL)
    return;
  MergeSortRec( A, N );
  free(B);
}
void QuickSort( float *A, int N )
{

  int b = 0, e = N - 1;
  float  x = A[N / 2];

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
void HeapCorrection( float *A, int N, int i )
{
  int l, r, best; 

  while(1)
  {
    l = 2 * i + 1;
    r = 2 * i + 2;
    best = i;

    if (l < N && A[i] < A[l])
      best = l;
    if (r < N && A[best] < A[r])
      best = r;
    if (best == i)
      return;
    Swap( &A[i], &A[best]);
    i = best;
  }
}
void HeapSort(float *A, int N)
{
  int i;

  for (i = N / 2 - 1; i >= 0; i--)
    HeapCorrection( A, N, i);
  while (N-- > 1)
  {
    Swap( &A[0], &A[N]);
    HeapCorrection( A, N, 0);
  }                            
}
/*-----21.02.2017------
--------SERGEEV--------
--------SERGEY---------
----11-6----GROUP-B----*/

#include <glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "DPIC.h"

void Swap(byte *A, byte *B)
{
  byte tmp = *A;

  *A = *B;
  *B = tmp;
}
void QuickSort(byte *A, int N)
{

  int b = 0, e = N - 1;
  int x = A[N / 2];
  
  if (N < 2)
    return;
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
  
  QuickSort( A, e + 1 );
  QuickSort( A + b, N - b );
  
}
void PicFilterRoberts(PIC *PDest, PIC *PSrc, double Alpha)
{
  int x, y, c, A, B, C, D;
  for(y = 0; y < PSrc->H; y++)
    for(x = 0; x < PSrc->W; x++)
      for(c = 0; c < 3; c++)
      {
        A = PicGet(PSrc, x, y, c);
        B = PicGet(PSrc, x + 1, y, c);
        C = PicGet(PSrc, x, y + 1, c);
        D = PicGet(PSrc, x + 1, y + 1, c);
        PDest->Pixels[y * PDest->W + x][c] = Alpha * (abs(A - D) + abs(B - C)) ;
      }
}
void PicFilterSobel(PIC *PDest, PIC *PSrc, double Alpha)
{        
  int x, y, c, A, B, C, D, E, F, G, H, f, g;
  for(y = 0; y < PSrc->H; y++)
    for(x = 0; x < PSrc->W; x++)
      for(c = 0; c < 3; c++)
      {
        A = PicGet(PSrc, x - 1, y - 1, c);
        B = PicGet(PSrc, x, y - 1, c);
        C = PicGet(PSrc, x + 1, y - 1, c);
        D = PicGet(PSrc, x - 1, y, c);
        E = PicGet(PSrc, x + 1, y, c);
        F = PicGet(PSrc, x - 1, y + 1, c);
        G = PicGet(PSrc, x, y + 1, c);
        H = PicGet(PSrc, x + 1, y + 1, c);
        f = (A + 2 * B + C) - (F + 2 * G + H);
        g = (A + 2 * D + F) - (C + 2 * E + H);
        PDest->Pixels[y * PDest->W + x][c] = Alpha * sqrt(f * f + g * g) ;
      }
}
void PicFilterMedian(PIC *PDest, PIC *PSrc, int N)
{  
  byte *A;
  int x, y, c, i, j, k;

  if ((A = malloc(N * N)) ==  NULL)
    return;
  for(y = 0; y < PSrc->H; y++)
    for(x = 0; x < PSrc->W; x++)
      for(c = 0; c < 3; c++)
      { 
        k = 0;
        for(i = 0; i < N; i++)
          for(j = 0; j < N; j++)
            A[k++] = PicGet(PSrc, x - N / 2 + j, y - N / 2 + i, c);
            QuickSort(A, N * N);
              PDest->Pixels[y * PDest->W + x][c] = A[N * N / 2] ;
      }    
      free(A);
}                                                                           
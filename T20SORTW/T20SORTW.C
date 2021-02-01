//Sergeev Sergey 11-6 27.09.2016
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"SORT.h"

#define MAX 9000000
void ( *Fill[] )( float *A, int N ) =
{
  FillIncr, FillDecr, FillRand,
  FillEqual, FillMostly
};
void ( *Sort[] )( float *A, int N ) =
{
  MergeSort, QuickSort, HeapSort
};
void main( void )
{
  static float A[MAX];
  int i, j;
  clock_t tiks;
  float seconds;

  printf("Fill:  1 - Incr;  2 - Decr;  3 - Rand;  4 - Equal;  5 - Mostly\n");
  printf("Sort:   1 - Merge;   2 - Quick;   3 - Heap\n");
  printf("Number of Elements:   %i\n\n", MAX);
  for(j = 0; j <= 2; j++)
  {
     for(i = 0; i <= 4; i++)
     {
       Fill[i]( A, MAX );
       tiks = clock();
       Sort[j]( A, MAX );
       tiks = clock() - tiks;
       seconds = (float)tiks / CLOCKS_PER_SEC;
       printf("Sort: %i    Fill: %i      Check:%i      Time is: %f\n", j + 1, i + 1, CheckSort( A, MAX ), seconds);
     }
  }
  _getch();
}
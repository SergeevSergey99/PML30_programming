/* Sergeev Sergey 10-6 30.01.2016 */

#include<stdio.h>
#include<math.h>

int Fact( int x )
{
  int fact = 1, i;


  for (i = 1; i <= x; fact *=i, i++)
  ;
  return fact;
}
void Triangle(int N, int K)
{
  int i, j;

  for (i = 0; i <= N; i++)
  for (j = 0; j <= i; j++)
  {
  printf("%i ", CNK( i, j ));
  if (N == i && K==j)
   j
  }
}
int CNK( int N , int K )
{
  return Fact( N ) / (Fact( K ) * Fact(N - K));
}
void main( void )
{
  int N, K;

  printf("N:");
  scanf("%i", &N);
  printf("K:");
  scanf("%i", &K);
  printf("%i", CNK( N, K ));
  Triangle( N, K );
}
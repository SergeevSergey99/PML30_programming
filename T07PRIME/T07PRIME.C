/* Sergeev Sergey 10-6 23.01.2016 */

#include<stdio.h>
#include<math.h>

int IsPrime( int x )
{
  int last = sqrt( x ), i = 2;

  while (i <= last)
  {
    if (x % i == 0)
      return 0;
    i++;
  }
  return 1;
}
void PrintAllPrime( int x )
{
  int i = 2, cnt = 0;
  while (i != x)
  {
    if (IsPrime(i))
    {
      printf("%i, ", i);
      cnt++;
    }
  i++;
  }
  printf("  -----   %i\n", cnt);
}
void Multi( int x )
{
  int i = 2, number = x;
  while (i <= x && i <= number)
  {
    if (IsPrime(i))
      if (number % i == 0)
      {
        printf(" %i ", i);
        number /= i;
      }
      else
        i++;
    else
      i++;
  }
  printf("\n");
}
void main( void )
{
  int x;

  printf("X:");
  scanf("%i", &x);
  if (IsPrime(x))
    printf("Is Prime\n");
  else
    printf("Is Not Prime\n");
  PrintAllPrime( x );
  Multi( x );
}
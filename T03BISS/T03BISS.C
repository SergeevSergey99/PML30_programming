/* Sergeev Sergey, 10-6, 16.01.2016 */

#include<stdio.h>
#include<conio.h>

int isBissextile( int Year )
{
  if (Year % 4 == 0)
    if (Year % 100 == 0)
      if (Year % 400 == 0)
        return 1;
      else
        return 0;
    else
      return 1;
  else
    return 0;
}
void main( void )
{
  int Year;
  printf( "Imput year" );
  scanf( "%i", &Year );
  if (isBissextile( Year ))
    printf("Year is Bissextile");
  else
    printf("Year is not Bissextile");
}
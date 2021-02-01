/* Sergeev Sergey, 10-6, 12.12.2015 */

#include <stdio.h>

void main(void)
{
//clrscr();
   float a, b, x;
      printf ( "X*A+B=0\n" );
      printf ( "imput A and after B\n" );
      scanf ( "%f%f", &a, &b );

      if ( a == 0 )
         if ( b == 0 )
           printf ( "X can be any number" );
         else
           printf ( "ERROR\n" );
      else
      {
        x = -( b / a );
        printf ( "X = %f\n", x);
      }
      getch();
}
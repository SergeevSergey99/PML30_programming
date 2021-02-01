/* Sergeev Sergey 10-6 20.01.2016 */
#include<stdio.h>
#include<math.h>
/*ax^2+bx+c=0*/
void SolveQuadratic( float a, float b, float c )
{
  float d;

  d = b * b - 4 * a * c;
  if (a == 0)
    if (b == 0)
      if (c == 0)
        printf("ANY NUMBER\n");
      else
        printf("NO SOLUTIONS\n");
    else
      printf(" +- %f\n", sqrt(c/b));
  else
    if (d < 0)
      printf("%f +- i * %f\n"
      , -b / (2 * a),
      sqrt(-d) / (2 * a) );
    else
      printf("%f %f\n"
      , ( -b + sqrt(d) ) / 2 / a
      , ( -b - sqrt(d) ) / 2 / a );

}
void main( void )
{
  float a, b, c;

  printf("A:");
  scanf("%f", &a);
  printf("B:");
  scanf("%f", &b);
  printf("C:");
  scanf("%f", &c);
  SolveQuadratic( a, b, c );
}
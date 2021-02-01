/*Sergeev Sergey 11.10. 2016*/    
#include<stdlib.h>
#include<stdio.h>

static int *Sito;
void Fill(int N)
{
  int i, x;

  for(i = 0, x = 2; x <= N; i++, x++)
    Sito[i] = x;
}
int Primes(int N)
{
  int i, j, cnt = 0;

  for( i = 0; i < N; i++ )
    for( j = i + 1; j < N; j++ )
      if ((Sito[i] != 0)&&(Sito[j] != 0)&&(Sito[j] % Sito[i] == 0))
      {
        Sito[j] = 0;
        cnt = cnt++; 
      }

  cnt = N - cnt;
  return cnt;
}
void WriteMas(int *Mas, int N)
{
  int i;
  FILE *F;

  F = fopen("OUT.TXT","w");
  if (F == NULL)
    return;
  for(i = 0; i < N; i++)
    fprintf( F, "%i\n", Mas[i]);
  fclose(F);
}
void FillMas(int *Mas, int N)
{
  int i, j = 0;

  for( i = 0; i < N - 1; i++ )
  {
    if (Sito[i] != 0)
    {
      Mas[j] =  Sito[i];
      j++;
    }
  }
} 
int main(void)
{
  int M, cnt;
  int *Mas;

  scanf("%i", &M);
  Sito = malloc(sizeof(int) * M);
  if(Sito ==NULL)
    return;
  Fill( M );
  cnt = Primes( M );
  
  Mas = malloc(sizeof(int) * cnt);
  if(Mas ==NULL)
    return;                  
  FillMas( Mas, M );
  WriteMas( Mas, cnt );
  free(Sito);
  free(Mas);
  return 0; 
}
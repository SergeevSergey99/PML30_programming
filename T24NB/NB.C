/*--------------------------------
----------Sergeev_Sergey----------
--------------------11_6----------
-----------------group_B----------
--------------29.11.2016----------
--------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include"NB.h"
#include<ctype.h> 
void GetStr(char *Str, int MaxLen)
{
  char ch;
  int i = 0;

  while ((ch = getchar()) != '\n')
    if (Str != NULL && i < MaxLen - 1)
      Str[i++] = ch;
  if (Str != NULL && i < MaxLen)
    Str[i++] = 0;
}
void ReadPupil(PUPIL *P)
{
  printf("SurName:");
  GetStr(P->SurName, sizeof(P->SurName));
  printf("Name:");
  GetStr(P->Name, sizeof(P->Name));
  printf("Phone:");
  GetStr(P->Phone, sizeof(P->Phone));
  printf("Birthday\n  Day:");
  scanf("%i", &P->Birthday.Day); 
  GetStr(NULL, 0);
  printf("  Month:");
  scanf("%i", &P->Birthday.Month); 
  GetStr(NULL, 0);
  printf("  Year:");
  scanf("%i", &P->Birthday.Year); 
  GetStr(NULL, 0);
  printf("Form:");
  scanf("%i", &P->Form); 
  GetStr(NULL, 0);
  printf("FormDigit:");
  P->FormDigit = getchar();
  GetStr(NULL, 0);
  printf("Sex:");
  if (getchar() == 'm')
    P->Sex = 'm';
  else
    P->Sex = 'f';
  GetStr(NULL, 0);
}
int SaveDB(char *FileName, PUPIL *Base, int Size)
{
  FILE *F;

  F = fopen(FileName, "wb");
  if (F == NULL)
    return 0;
  fwrite(Base, sizeof(PUPIL), Size, F);
  fclose(F);
  return 1;
}
int LoadDB(char *FileName, PUPIL *Base, int MaxSize)
{
  FILE *F;
  int N;

  if ((F = fopen(FileName, "rb")) == NULL)
    return 0;
  N = fread(Base, sizeof(PUPIL), MaxSize, F);
  fclose(F);
  return 1;
}
void Swap(PUPIL *Pupil1, PUPIL *Pupil2)
{
  PUPIL tmp = *Pupil1;
  *Pupil1 = *Pupil2;
  *Pupil2 = tmp;
}

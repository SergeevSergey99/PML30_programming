/*-----27.12.2016------
--------SERGEEV--------
--------SERGEY---------
----11-6----GROUP-B----*/

/*-------Update--------
-------24.01.2017------*/

/*-------Update--------
-------07.02.2017------*/

#include "DPIC.h"
#include <stdio.h>
#include <stdlib.h>

void PicDraw(PIC *P, int X0, int Y0)
{
  int i, j, off = 0;

  for (i = 0; i < P->H; i++)
    for (j = 0; j < P->W; j++, off++)
      PutPixel(X0 + j, Y0 + i, P->Pixels[off][2],
                               P->Pixels[off][1],
                               P->Pixels[off][0]);
}
int PicCreate(PIC *P, int NewW, int NewH)
{
  P->Pixels = malloc(NewW * NewH * sizeof(RGB));
  if (P->Pixels != NULL)
  {
    P->W = NewW;
    P->H = NewH;
    return 1;
  }
  return 0;
}
void PicFree(PIC *P)
{
  if (P->Pixels != NULL)
    free(P->Pixels);
  P->Pixels = NULL;
  P->W = P->H = 0;
}
int PicLoad(PIC *P, char *FileName)
{
  FILE *F;
  int x = 0, y = 0;

  if ((F = fopen(FileName, "rb")) == NULL)
    return 0;
  fread(&x, 2, 1, F);
  fread(&y, 2, 1, F);


  if (!PicCreate(P, x, y))
  {
    fclose(F);
    return 0;
  }
  fread(P->Pixels, 3, x * y, F);
  fclose(F);
  return 1;
}
int PicSave(char *FileName, PIC *P)
{
  FILE *F;

  if ((F = fopen(FileName, "wb")) == NULL)
    return 0;
  fwrite(&P->W, 2, 1, F);
  fwrite(&P->H, 2, 1, F);  
  fwrite(&P->Pixels, 3, P->H * P->W, F);
  fclose(F);
  return 1;
}                                   
int PicGet(PIC *P, int x, int y, int c)
{
  x = (x + P->W) % P->W;
  y = (y + P->H) % P->H;
  return P->Pixels[y * P->W + x][c];
}
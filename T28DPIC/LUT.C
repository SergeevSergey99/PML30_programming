/*-----24.01.2017------
--------SERGEEV--------
--------SERGEY---------
----11-6----GROUP-B----*/

#include <math.h>
#include "DPIC.h"

int Clamp(int X, int A, int B)
{
  if (X < A) 
    return A;
  if (X > B) 
    return B;
  return X;
}
float fClamp(float X, float A, float B)
{
  if (X < A) 
    return A;
  if (X > B) 
    return B;
  return X;
}
void LutSetCopy(byte *LUT)
{
  int i;
  for(i = 0; i < 256; i++)
    LUT[i] = i;
}
void LutSetNegative(byte *LUT)
{
  int i;
  for(i = 0; i < 256; i++)
    LUT[i] = 255 - i;
}
void LutSetBrightness(byte *LUT, int Di)
{
   int i;
  for(i = 0; i < 256; i++)
    LUT[i] = Clamp(i + Di, 0, 255);  
}
void LutSetContrast(byte *LUT, int A, int B)
{                            
  int i;                                                 
  for(i = 0; i < 256; i++)
    LUT[i] = Clamp(255 * (i - A) / (B - A), 0, 255);
}

void LutSetGamma(byte *LUT, double Gamma)
{                             
  int i;
  for(i = 0; i < 256; i++)

    LUT[i] = (byte)(255 * pow(i / 255.0, 1 / Gamma));
}
void LutSetAutoContrast(byte *LUT, PIC *P);
void LutApply(PIC *PicDest, PIC *PicSrc, byte *LUT)
{ 
  int x, y, c;
  for(y = 0; y < PicSrc->H; y++)
    for(x = 0; x < PicSrc->W; x++)
      for(c = 0; c < 3; c++)
        PicDest->Pixels[y * PicSrc->W + x][c] = LUT[PicSrc->Pixels[y * PicSrc->W + x][c]];
}
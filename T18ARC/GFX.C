/*Sergeev Sergey 10-6 23.04.2016*/
#include"GFX.H"
int pov(int x, int n)
{
  int i, pov = 1;
  for(i = 0; i < n; i++)
    pov *= x;
  return pov;
}
void SetGr( void )
{
  _asm{
    mov AX, 0x13
    int 0x10
  }
}
void CloseGr( void )
{
  _asm{
    mov AX, 3
    int 0x10
  }
}
void PutPixel( int x, int y, int color)
{
  *(unsigned char*)(0xA0000000UL + y * 320U + x) = color;
}

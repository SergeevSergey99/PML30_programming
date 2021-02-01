/*Sergeev Sergey 10-6 16.04.2016*/
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include"GFX.H"

#define Br_X 30
#define Br_Y 30
#define Br_W 20
#define Br_H 10
#define Br_NX 13
#define Br_NY 10
  int Bricks[Br_NY][Br_NX];

int Board( int bx, int bw, int *x )
{
  int vb = 2, i, j, AutoDriver = 0;

  if ((*(char*)0x417 & 1) == 1 && bx + bw < 319)
  {
    for(i = 0; i < vb; i++)
    {
      bx++;
      for(j = 0; j < 4; j++)
      PutPixel( bx - 1 - j , 199, 0);
      PutPixel( bx + bw , 199, 7);
    }
  }
  if ((*(char*)0x417 & 2) != 0 && bx > 0)
  {
    for (i = 0; i < vb; i++)
    {
      bx--;
      for (j = 0; j < 4; j++)
        PutPixel( bx + bw +j , 199, 0);
      PutPixel( bx - 1, 199, 7);
    }
  }
  if (( *(char *)0x417 & 4) != 0)
  {
    AutoDriver = 1 - AutoDriver;
  }
  if (AutoDriver == 1)
  {
    if (*x >= bx + bw)
      for (i = 0; i < vb; i++)
        {
          bx++;
          for (j = 0; j < 4; j++)
          PutPixel( bx - 1 - j , 199, 0);
          PutPixel( bx + bw , 199, 7);
        }
    if (*x <= bx )
      for(i = 0; i < vb; i++)
        {
          bx--;
          for(j = 0; j < 4; j++)
            PutPixel( bx + bw +j , 199, 0);
          PutPixel( bx - 1, 199, 7);
        }
  }
  for(i = 0; i < bw; i++)
    PutPixel( bx + i, 199, 7);
  return bx;
}
void DrawBrick( int nx, int ny )
{
  int x, y;

  for (y = 0; y < Br_H; y++)
    for (x = 0; x < Br_W; x++)
      PutPixel( Br_X + nx * Br_W + x,
                Br_Y + ny * Br_H + y,
                Bricks[ny][nx]);
}
int Hit( int x, int y )
{
  if (x < Br_X || y < Br_Y)
    return 0;
  x -= Br_X;
  y -= Br_Y;
  x /= Br_W;
  y /= Br_H;
  if (x >= Br_NX || y >= Br_NY)
    return 0;
  if (Bricks[y][x] == 0)
    return 0;
  Bricks[y][x]--;
  DrawBrick( x, y);
  return 1;
}
void main( void )
{
  int  y = 10, sx = 1, sy = 1;
  static int x;
  int i, j, bx = 100, bw = 50, life = 3;

  x = rand() % 300;
  *(char*)0x417 = 112;
  SetGr();
  for(i = 0; i < Br_NY; i++)
    for(j = 0; j < Br_NX; j++)
      {
      Bricks[i][j] = 5;
      DrawBrick( j, i);
      }
  while(!kbhit() && life != 0)
  {
    bx = Board( bx, bw, &x);
    PutPixel( x, y, 0);
    if (Hit( x + sx, y ))
      sx = -sx;
    if (Hit( x, y + sy ))
      sy = -sy;
    if (Hit( x + sx, y + sy ))
      sx = -sx, sy = -sy;
    x += sx;
    y += sy;
    PutPixel( x, y, 10);
    delay(8);
    if (x < 1 || x > 318)
      sx = -sx;
    if (y < 1 || y > 198)
      sy = -sy;
    if ((y == 199)&&(x < bx || x > bx + bw))
      {
        life--;
        if (life == 2)
          *(char*)0x417 = 80;
        if (life == 1)
          *(char*)0x417 = 16;
      }
  }
  CloseGr();
  *(char*)0x417 = 0;
}
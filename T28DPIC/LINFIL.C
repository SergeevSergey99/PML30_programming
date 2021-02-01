/*-----07.02.2016------
--------SERGEEV--------
--------SERGEY---------
----11-6----GROUP-B----*/
#include "DPIC.h"

FILTER Filters[] = 
{
  {
    "Blur", {
              {1, 1, 1},
              {1, 1, 1},
              {1, 1, 1}
            },
    9, 0
  },
  {
    "Small Blur", {
              {0, 1, 0},
              {1, 1, 1},
              {0, 1, 0}
            },
    5, 0
  },
  {
    "Gaus Blur", {
              {1, 2, 1},
              {2, 4, 2},
              {1, 2, 1}
            },
    16, 0
  },
  {
    "Hight pass", {
                    {-1, -1, -1},
                    {-1, 9, -1},
                    {-1, -1, -1}
                  },
    1, 0
  },
  {
    "Small Hight pass", {
                          {0, -1, 0},
                          {-1, 5, -1},
                          {0, -1, 0}
                        },
    1, 0
  },
  {
    "Gradient Laplass", {
                          {-1, -1, -1},
                          {-1, 8, -1},
                          {-1, -1, -1}
                        },
    1, 128
  },
  {
    "Small Gradient Laplass", {
                                {0, -1, 0},
                                {-1, 4, -1},
                                {0, -1, 0}
                              },
    1, 128
  }, 
  {
    "Gradient Embossing N", {
                              {-1, -1, -1},
                              {-1, 2, -1},
                              {1, 1, 1}
                            },
    1, 128
  },
  {
    "Gradient Embossing NE", {
                               {-1, -1, -1},
                               {1, 2, -1},
                               {1, 1, -1}
                             },
    1, 128
  },
  {
    "Gradient Embossing E", {
                              {1, -1, -1},
                              {1, 2, -1},
                              {1, -1, -1}
                            },
    1, 128
  },
  {
    "Gradient Embossing ES", {
                               {1, 1, -1},
                               {1, 2, -1},
                               {-1, -1, -1}
                             },
    1, 128
  },
  {
    "Gradient Embossing S", {
                              {1, 1, 1},
                              {-1, 2, -1},
                              {-1, -1, -1}
                            },
    1, 128
  },
  {
    "Gradient Embossing SW", {
                               {-1, 1, 1},
                               {-1, 2, 1},
                               {-1, -1, -1}
                             },
    1, 128
  },
  {
    "Gradient Embossing W", {
                              {-1, -1, 1},
                              {-1, 2, 1},
                              {-1, -1, 1}
                            },
    1, 128
  },
  {
    "Gradient Embossing WN", {
                               {-1, -1, -1},
                               {-1, 2, 1},
                               {-1, 1, 1}
                             },
    1, 128
  }, 
  {
    "Small Gradient Embossing N", {
                                    {0, -1, 0},
                                    {0, 1, 0},
                                    {0, 0, 0}
                                  },
    1, 128
  },
  {
    "Small Gradient Embossing NE", {
                                     {0, 0, -1},
                                     {0, 1, 0},
                                     {0, 0, 0}
                                   },
    1, 128
  },
  {
    "Small Gradient Embossing E", {
                                    {0, 0, 0},
                                    {0, 1, -1},
                                    {0, 0, 0}
                                  },
    1, 128
  },
  {
    "Small Gradient Embossing ES", {
                                     {0, 0, 0},
                                     {0, 1, 0},
                                     {0, 0, -1}
                                   },
    1, 128
  },
  {
    "Small Gradient Embossing S", {
                                    {0, 0, 0},
                                    {0, 1, 0},
                                    {0, -1, 0}
                                  },
    1, 128
  },
  {
    "Small Gradient Embossing SW", {
                                     {0, 0, 0},
                                     {0, 1, 0},
                                     {-1, 0, 0}
                                   },
    1, 128
  },
  {
    "Small Gradient Embossing W", {
                                    {0, 0, 0},
                                    {-1, 1, 0},
                                    {0, 0, 0}
                                  },
    1, 128
  },
  {
    "Small Gradient Embossing WN", {
                                     {-1, 0, 0},
                                     {0, 1, 0},
                                     {0, 0, 0}
                                   },
    1, 128
  }
};

int NumOfFilters = (sizeof(Filters) / sizeof(Filters[0]));

void PicFilter(PIC *Dest, PIC *Src, FILTER *F)
{ 
  int x, y, c, i, j, sum;
  for(y = 0; y < Src->H; y++)
    for(x = 0; x < Src->W; x++)
      for(c = 0; c < 3; c++)
      {
        sum = 0;
        for(i = 0; i < 3; i++)
          for(j = 0; j < 3; j++)
            sum +=F->A[i][j] * PicGet(Src, x + j - 1, y + i - 1, c);  
        Dest->Pixels[y * Dest->W + x][c] = Clamp(sum / F->Frac + F->Bias, 0, 255);
      }
}
/*-----27.12.2016------
--------SERGEEV--------
--------SERGEY---------
----11-6----GROUP-B----*/

/*-------Update--------
-------24.01.2017------*/

/*-------Update--------
--Filters_and_LINFIL.C-
-------07.02.2017------*/

/*-------Update--------
----MENU_and_NLFIL.C---
-------21.02.2017------*/

#include <glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "DPIC.h"

double Zoom = 1; 
PIC Image1, Image2;
int Picture = 0;
unsigned char Frame[FRAME_H][FRAME_W][3];
char *Name[21] = 
 { "X:\\PICS\\M.G24",
   "X:\\PICS\\ROOF.G24",
   "X:\\PICS\\STONE.G24",
   "X:\\PICS\\PARKET.G24",    
   "X:\\PICS\\RIVETS.G24",
   "X:\\PICS\\GRASS.G24",
   "X:\\PICS\\GIR.G24",
   "X:\\PICS\\GLOBE.G24",
   "X:\\PICS\\S1.G24",
   "X:\\PICS\\BRICK.G24",
   "X:\\PICS\\BULKHEAD.G24",    
   "X:\\PICS\\GR.G24",    
   "X:\\PICS\\PYATACK.G24", 
   "X:\\PICS\\SKYTST.G24",
   "X:\\PICS\\SOCCER.G24",
   "X:\\PICS\\vane.g24",    
   "X:\\PICS\\VEIN.G24",
   "X:\\PICS\\VINNYPUH.G24",
   "X:\\PICS\\WOODSHGL.G24", 
   "X:\\PICS\\ZNAK30.G24",
   "X:\\PICS\\ZNAK.G24"   
 };  

void PutPixel(int X, int Y, int R, int G, int B)
{
  if (X >= 0 && X < FRAME_W && Y >= 0 && Y < FRAME_H)
  {
    Frame[Y][X][0] = B;
    Frame[Y][X][1] = G;
    Frame[Y][X][2] = R;
  }
}
void AutoDraw(PIC *P)
{
  static int X = 0, Y = 0;

  PicDraw(P, X, Y);
  X += P->W;
  if (X >= FRAME_W - P->W)
  {
    X = 0;
    Y += P->H;
    if (Y >= FRAME_H - P->H)
      Y = 0;
  } 
}
void Display(void)
{  
  
  //glClearColor(0.3, 0.5, 0.7, 1);
  glClear(GL_COLOR_BUFFER_BIT);
   
  glRasterPos2d(-1, 1);
  glPixelZoom(Zoom, -Zoom);

  glDrawPixels(FRAME_W, FRAME_H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame); 

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}
void Keyboard(unsigned char Key, int X, int Y)
{
  if (Key == 27)
    exit(0);
  if (Key == '+')
    Zoom *= 1.01;
  if (Key == '-')
    Zoom /= 1.01;
}
void MenuHandle( int Value )
{
  PIC tmp;
  byte L1[256];
   
     
  if (Value >= 100)
  {              
    Picture = Value - 100;
    PicLoad(&Image1,Name[Picture]);
    PicLoad(&Image2,Name[Picture]);
  }

  switch (Value)
  {
    case 0: 
      exit(0);
      break;
    case 1: 
      break;
    case 2: 
      LutSetNegative(L1);
      LutApply(&Image2, &Image1, L1);
      break; 
    case 3: 
      LutSetContrast(L1, 50, 205);
      LutApply(&Image2, &Image1, L1);
      break;
    case 4: 
      LutSetContrast(L1, -50, 305);
      LutApply(&Image2, &Image1, L1);
      break;
    case 5: 
      LutSetBrightness(L1, 100);
      LutApply(&Image2, &Image1, L1);
      break;
    case 6: 
      LutSetGamma(L1, 1.6);
      LutApply(&Image2, &Image1, L1);
      break;
    case 7: 
      PicFilterRoberts(&Image2, &Image1, 1.0);
      break;
    case 8: 
      PicFilterRoberts(&Image2, &Image1, 1.5);
      break;
    case 9: 
      PicFilterRoberts(&Image2, &Image1, 2.0);
      break;
    case 10: 
      PicFilterRoberts(&Image2, &Image1, 2.5);
      break;
    case 11: 
      PicFilterSobel(&Image2, &Image1, 1.0);
      break;
    case 12: 
      PicFilterSobel(&Image2, &Image1, 1.5);
      break;
    case 13: 
      PicFilterSobel(&Image2, &Image1, 2.0);
      break;
    case 14: 
      PicFilterSobel(&Image2, &Image1, 2.5);
      break; 
    case 15: 
      PicFilterMedian(&Image2, &Image1, 3);
      break;  
    case 16: 
      PicFilterMedian(&Image2, &Image1, 5);
      break;  
    case 17: 
      PicFilterMedian(&Image2, &Image1, 7);
      break;                             
    case 18: 
      PicFilterMedian(&Image2, &Image1, 9);
      break;  
    case 100:         
      break;  
    case 101:
      break;
    case 102:
      break;
    case 103: 
      break;
    case 104: 
      break;
    case 105: 
      break;
    case 106: 
      break;
    case 107: 
      break; 
    case 108:         
      break;  
    case 109:
      break;
    case 110:
      break;
    case 111: 
      break;
    case 112: 
      break;
    case 113: 
      break;
    case 114: 
      break;
    case 115: 
      break; 
    case 116:         
      break;  
    case 117:
      break;
    case 118:
      break;
    case 119: 
      break;
    case 120: 
      break;
    default:      
        PicFilter(&Image2, &Image1, &Filters[Value - 30]);
        break;
  }      
  PicDraw(&Image2, 0, 0);
  //AutoDraw(&Image2);
  tmp = Image1;
  Image1 = Image2;
  Image2 = tmp;
  // PicFree(&P);
  //PicFree(&P2);
 
  
}
void Menu(void)
{
  
  int i, menu, lut_menu, contr_menu, linfil_menu, nonlinfil_menu, rob_menu, sob_menu, med_menu, new_menu;

  menu = glutCreateMenu(MenuHandle);
  lut_menu = glutCreateMenu(MenuHandle);
  contr_menu = glutCreateMenu(MenuHandle);
  linfil_menu = glutCreateMenu(MenuHandle);
  nonlinfil_menu = glutCreateMenu(MenuHandle);
  rob_menu = glutCreateMenu(MenuHandle);
  sob_menu = glutCreateMenu(MenuHandle);
  new_menu = glutCreateMenu(MenuHandle);
  med_menu = glutCreateMenu(MenuHandle);
  
  glutSetMenu(contr_menu);  
  glutAddMenuEntry("Decrease", 3);
  glutAddMenuEntry("Increase", 4);

  glutSetMenu(lut_menu);  
  glutAddMenuEntry("Negative", 2);
  glutAddSubMenu("Contrast", contr_menu);
  glutAddMenuEntry("Brightness", 5);
  glutAddMenuEntry("Gamma", 6);

  glutSetMenu(linfil_menu); 
  for(i = 0; i < NumOfFilters; i++)
    glutAddMenuEntry(Filters[i].Name, 30 + i);

  glutSetMenu(rob_menu);  
  glutAddMenuEntry("1.0", 7);
  glutAddMenuEntry("1.5", 8);
  glutAddMenuEntry("2.0", 9);
  glutAddMenuEntry("2.5", 10);
  
  glutSetMenu(sob_menu);
  glutAddMenuEntry("1.0", 11);
  glutAddMenuEntry("1.5", 12);
  glutAddMenuEntry("2.0", 13);
  glutAddMenuEntry("2.5", 14);
                      
  glutSetMenu(med_menu);
  glutAddMenuEntry("3x3", 15);
  glutAddMenuEntry("5x5", 16);
  glutAddMenuEntry("7x7", 17);
  glutAddMenuEntry("9x9", 18);
  
  glutSetMenu(nonlinfil_menu);      
  glutAddSubMenu("Roberts", rob_menu);
  glutAddSubMenu("Sobel", sob_menu);
  glutAddSubMenu("Median", med_menu);
  
  glutSetMenu(new_menu);
  glutAddMenuEntry("X:\\PICS\\M.G24", 100);
  glutAddMenuEntry("X:\\PICS\\ROOF.G24", 101);
  glutAddMenuEntry("X:\\PICS\\STONE.G24", 102);
  glutAddMenuEntry("X:\\PICS\\PARKET.G24", 103);
  glutAddMenuEntry("X:\\PICS\\RIVETS.G24", 104);
  glutAddMenuEntry("X:\\PICS\\GRASS.G24", 105);
  glutAddMenuEntry("X:\\PICS\\GIR.G24", 106);
  glutAddMenuEntry("X:\\PICS\\GLOBE.G24", 107);
  glutAddMenuEntry("X:\\PICS\\S1.G24", 108);
  glutAddMenuEntry("X:\\PICS\\BRICK.G24", 109);
  glutAddMenuEntry("X:\\PICS\\BULKHEAD.G24", 110);
  glutAddMenuEntry("X:\\PICS\\GR.G24", 111);
  glutAddMenuEntry("X:\\PICS\\PYATACK.G24", 112);
  glutAddMenuEntry("X:\\PICS\\SKYTST.G24", 113);
  glutAddMenuEntry("X:\\PICS\\SOCCER.G24", 114);
  glutAddMenuEntry("X:\\PICS\\vane.g24", 115);
  glutAddMenuEntry("X:\\PICS\\VEIN.G24", 116);
  glutAddMenuEntry("X:\\PICS\\VINNYPUH.G24", 117);
  glutAddMenuEntry("X:\\PICS\\WOODSHGL.G24", 118);
  glutAddMenuEntry("X:\\PICS\\ZNAK30.G24", 119);
  glutAddMenuEntry("X:\\PICS\\ZNAK.G24", 120);
   
  glutSetMenu(menu);
  glutAddMenuEntry("Exit", 0);    
  glutAddMenuEntry("Undo", 1);
  glutAddSubMenu("LUT", lut_menu);
  glutAddSubMenu("Liner Filters", linfil_menu);
  glutAddSubMenu("NonLiner Filters", nonlinfil_menu);
  glutAddSubMenu("New", new_menu);    
  
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void main(int argc, char *argv[])
{
  //int i;
   
  if (!PicLoad(&Image1, Name[Picture]))
    return;
  if (!PicLoad(&Image2, Name[Picture]))
    return;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(FRAME_W, FRAME_H);
  glutCreateWindow("SERGEEV SERGEY 11-6");
  
  Menu();
  
  AutoDraw(&Image1);
  /*
  if(PicLoad(&P,Name[Picture]))
  {
    AutoDraw(&P);
    if(PicCreate(&P2, P.W, P.H))
    {
      byte L1[256];
      LutSetCopy(L1);

      LutSetNegative(L1);
      LutApply(&P2, &P, L1);
      AutoDraw(&P2);
    
      LutSetContrast(L1, 50, 205);
      LutApply(&P2, &P, L1);
      AutoDraw(&P2);

      LutSetBrightness(L1, 100);
      LutApply(&P2, &P, L1);
      AutoDraw(&P2);

      LutSetGamma(L1, 1.6);
      LutApply(&P2, &P, L1);
      AutoDraw(&P2);
      for(i = 0; i < NumOfFilters; i++)
      {
        PicFilter(&P2, &P, &Filters[i]);
        AutoDraw(&P2);
      }
    }
      //PicDraw(&P, rand() % FRAME_W, rand() % FRAME_H);   
    
             
       
    PicFree(&P);
    PicFree(&P2);
    }
    */
    
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glutMainLoop();
}
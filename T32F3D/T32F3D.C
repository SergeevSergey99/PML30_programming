/*-----16.05.2017------
--------SERGEEV--------
--------SERGEY---------
----11-6----GROUP-B----*/
//#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include "glut.h"
//#include <freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double SyncTime;
int IsPause;
double pi = 3.1415926535;
float os[27];

void Timer( void )
{
  long t = clock();
  static long StartTime = -1, OldTime, PauseTime = 0;

  if (StartTime == -1)
    StartTime = OldTime = t;

  if (IsPause)
    PauseTime += t - OldTime;
  else
    SyncTime = (t - PauseTime - StartTime) / (double)CLOCKS_PER_SEC;

  OldTime = t;
}
void Display(void)
{ 
  int j;
  Timer(); 
  glClearColor(0.6, 0.6, 0.6, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
 // glFrustum(0,2,-1,1,-2,2);
  gluLookAt(15,5,0,0,0,0,-5,0,0);
                         
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_NORMALIZE);
 
  for( j = 0; j < 9; j++)
  {
    glPushMatrix();        
    glRotated(50* SyncTime , 0, 1, 0);
    glTranslated(10 * sin((j + 1) * 2 * pi / 9), 0, 10 * cos((j + 1) * 2 * pi / 9));       
    glRotated(90 * SyncTime , os[j * 3], os[j * 3 + 1],  os[j * 3 + 2]);
    switch(j)
    {                 
    case 0:                    
      glColor3d(1,0,0); 
      glutSolidCube(0.8);
    break;
    case 1:                    
      glColor3d(0.6,0.4,0);
      glutSolidTeapot(0.8);
    break;
    case 2:                    
      glColor3d(0.4,0.6,0);
      glutSolidTorus(0.3,0.5,10,10);
      glPushMatrix();        
      glTranslated(1 * sin((j + 1) * 2 * pi / 9), 0, 1 * cos((j + 1) * 2 * pi / 9));       
      glRotated(50* SyncTime , 0, 1, 0);
      glTranslated(1 * sin((j + 1) * 2 * pi / 9), 0, 1 * cos((j + 1) * 2 * pi / 9));       
      glRotated(90 * SyncTime , os[j * 3], os[j * 3 + 1],  os[j * 3 + 2]);  
      glColor3d(0.6, 0, 0.4);
      glutSolidSphere(0.2, 19, 19);
      glPushMatrix();        
      //glTranslated(-1 * sin((j + 1) * 2 * pi / 9), 0, 1 * cos((j + 1) * 2 * pi / 9));       
      glRotated(50* SyncTime , 0, 1, 0);
      glTranslated(-0.3 * sin((j + 1) * 2 * pi / 9), 0, -0.3 * cos((j + 1) * 2 * pi / 9));       
      glRotated(90 * SyncTime , os[j * 3], os[j * 3 + 1],  os[j * 3 + 2]);  
      glColor3d(1, 0, 1);
      glutSolidSphere(0.1, 19, 19);
      glPopMatrix();
      glPopMatrix();
    break;
    case 3:   
      glColor3d(0,1,0);
      glScaled(0.6, 0.6, 0.6); 
      glutSolidDodecahedron();
    break;
    case 4:                    
      glColor3d(0,0.6,0.4);
      glutSolidOctahedron();
    break;
    case 5:                    
      glColor3d(0, 0.4, 0.6); 
      glutSolidTetrahedron();
    break;
    case 6:              
      glColor3d(0,0,1);      
      glScaled(0.6, 0.6, 0.6); 
      glutSolidIcosahedron();
    break;
    case 7:                    
      glColor3d(0.4,0,0.6); 
      glutSolidCone(0.5, 1, 10, 10);
    break;
    case 8:                    
      glColor3d(0.6, 0, 0.4);
      glutSolidSphere(0.8, 19, 19);
    break;
    }
    
      glPushMatrix();        
      //glTranslated(-1 * sin((j + 1) * 2 * pi / 9), 0, 1 * cos((j + 1) * 2 * pi / 9));       
      glRotated(50* SyncTime , 0, 1, 0);
      glTranslated(-2 * sin((j + 1) * 2 * pi / 9), 0, -2 * cos((j + 1) * 2 * pi / 9));       
      glRotated(90 * SyncTime , os[j * 3], os[j * 3 + 1],  os[j * 3 + 2]);  
      glColor3d(1, 1, 0);
      glutSolidSphere(0.2, 19, 19);
      glPopMatrix();
      glPushMatrix();        
      //glTranslated(-1 * sin((j + 1) * 2 * pi / 9), 0, 1 * cos((j + 1) * 2 * pi / 9));       
      glRotated(50* SyncTime , 1, 0, 0);
      glTranslated(-2.5 * sin((j + 1) * 2 * pi / 9), 0, 2.5 * cos((j + 1) * 2 * pi / 9));       
      glRotated(90 * SyncTime , os[j * 3], os[j * 3 + 1],  os[j * 3 + 2]);  
      glColor3d(0, 1, 1);
      glutSolidSphere(0.2, 19, 19);
      glPopMatrix();
    glPopMatrix();
  }
  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}
void Keyboard(unsigned char Key, int X, int Y)
{
	if (Key == 27)
		exit(0);
    else 
	if (Key == 'p')
    IsPause = !IsPause;
}
void Reshape( int W, int H )
{
  double size = 1, ratio_x = size, ratio_y = size;

  if (W > H)
    ratio_x *= (double)W / H;
  else
    ratio_y *= (double)H / W;

  glViewport(0, 0, W, H);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-ratio_x, ratio_x, -ratio_y, ratio_y, size, 300);
  glMatrixMode(GL_MODELVIEW);
}
void main(int argc, char *argv[])
{
  int i;
  for(i = 0; i < 27; i++)
    os[i] = (double)rand() / RAND_MAX; 
  //printf("%f",(double)rand()/RAND_MAX);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(1400, 1000);
  glutCreateWindow("SERGEEV SERGEY 11-6");
  
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);  
  glutReshapeFunc(Reshape);
  
  glutFullScreen();

  glEnable(GL_DEPTH_TEST);

  glutMainLoop();
}
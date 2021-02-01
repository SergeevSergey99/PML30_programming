/*-----------13-12-2016--------------
-----------Sergeev-Sergey------------
----------------11-6---------------*/
#include<glut.h>

#define FRAME_W 256
#define FRAME_H 256

unsigned char Frame[FRAME_H][FRAME_W][3];
double Zoom = 3; 

void Display(void)
{
  glClearColor(0.3, 0.5, 0.7, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  Frame[100][100][1] = 255;
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
}
void main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(1400, 1000);
  glutCreateWindow("SERGEEV SERGEY 11-6");
  
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glutMainLoop();
}
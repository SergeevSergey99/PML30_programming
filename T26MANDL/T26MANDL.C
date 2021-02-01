#define _CRT_SECURE_NO_WARNINGS
//#define FREEGLUT_STATIC

#include <windows.h>
#include <glut.h>
#include "ÑOMPL.h"

//#pragma comment(lib, "freeglut.lib")
unsigned char Frame[FRAME_H][FRAME_W][3];
GLfloat Zoom = 0.85;

void Keyboard(BYTE Key, INT X, INT Y)
{
	if (Key == 27)
		exit(0);
	/*else if (Key == ' ')
	{
		glClearColor((DOUBLE)rand() / RAND_MAX, (DOUBLE)rand() / RAND_MAX, (DOUBLE)rand() / RAND_MAX, 1);
	}*/
}

void Display(void)
{
	double X0 = 0, X1 = -3, Y0 = 0, Y1 = 2;
	int Xs, Ys, n;
	COMPL Z;

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	for (Ys = FRAME_H / -2; Ys < FRAME_H / 2; Ys++)
		for (Xs = FRAME_W / -4; Xs < FRAME_W * 3 / 4; Xs++)
		{
			Z = SetCompl(Xs * (X1 - X0) / FRAME_W, Ys * (Y1 - Y0) / FRAME_H);
			n = Mandlebrot(Z);
		 	Frame[Ys + FRAME_H / 2][Xs + FRAME_W / 4][0] = n * 5;
			Frame[Ys + FRAME_H / 2][Xs + FRAME_W / 4][1] = n;
			Frame[Ys + FRAME_H / 2][Xs + FRAME_W / 4][2] = n / 2;
		}
	glRasterPos2d(-1, 1);
	glPixelZoom(Zoom, -Zoom);
	glDrawPixels(FRAME_W, FRAME_H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);

	glFinish();
	glutSwapBuffers();
	glutPostRedisplay();
}

int main( int argc, char *argv[] ) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(FRAME_W, FRAME_H);
	glutCreateWindow("Sergeev SV");
	glutFullScreen();
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}
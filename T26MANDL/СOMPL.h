#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define FRAME_H 1000
#define FRAME_W 1500

typedef struct {
	double A, B;
}COMPL;

COMPL SetCompl(double A, double B);
COMPL AddCompl(COMPL A, COMPL B);
COMPL MultCompl(COMPL A, COMPL B);
double ComplNorm(COMPL Z);
int Mandlebrot(COMPL Z);
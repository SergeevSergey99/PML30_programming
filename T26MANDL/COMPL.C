#define _CRT_SECURE_NO_WARNINGS

#include "ÑOMPL.h"
#include <math.h>

COMPL SetCompl(double A, double B) 
{
	COMPL Z;
	Z.A = A;
	Z.B = B;
	return Z;
}
COMPL AddCompl(COMPL A, COMPL B)
{
	COMPL Z;
	Z.A = A.A + B.A;
	Z.B = A.B + B.B;
	return Z;
}
COMPL MultCompl(COMPL A, COMPL B)
{
	COMPL Z;
	Z.A = A.A * B.A - A.B * B.B;
	Z.B = A.A * B.B + A.B * B.A;
	return Z;
}
double ComplNorm(COMPL Z)
{
	return sqrt(Z.A * Z.A + Z.B * Z.B);
}
int Mandlebrot(COMPL Z)
{
	COMPL Z0 = Z;
	int n = 0;

	while (n < 255 && ComplNorm(Z) < 2)
	{
		Z = AddCompl(MultCompl(Z, Z), Z0);
		n++;
	}
	return n;
}
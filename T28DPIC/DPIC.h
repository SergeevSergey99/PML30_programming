/*-----27.12.2016------
--------SERGEEV--------
--------SERGEY---------
----11-6----GROUP-B----*/

/*-------Update--------
-------07.02.2017------*/

/*-------Update--------
----MENU_and_NLFIL.C---
-------21.02.2017------*/

#define FRAME_H 750
#define FRAME_W 1500

typedef unsigned char byte;
typedef unsigned char RGB[3];
typedef struct{
  int W, H;
  RGB *Pixels;
}PIC;
typedef struct{
  char *Name;
  int A[3][3], Frac, Bias;
}FILTER;

extern FILTER Filters[];
extern int NumOfFilters;


void PutPixel(int X, int Y, int R, int G, int B);
void PicDraw(PIC *P, int X0, int Y0);
int PicCreate(PIC *P, int NewW, int NewH);
void PicFree(PIC *P);
int PicLoad(PIC *P, char *FileName);
int PicSave(char *FileName, PIC *P);
int PicGet(PIC *P, int x, int y, int c);


void PicFilter(PIC *Dest, PIC *Src, FILTER *F);

void LutSetCopy(byte *LUT);
void LutSetNegative(byte *LUT);
void LutSetBrightness(byte *LUT, int Di);
void LutSetContrast(byte *LUT,int A, int B);
void LutSetGamma(byte *LUT, double Gamma);
void LutSetAutoContrast(byte *LUT, PIC *P);
void LutApply(PIC *PicDest, PIC *PicSrc, byte *LUT);
int Clamp(int X, int A, int B);
float fClamp(float X, float A, float B);

void PicFilterRoberts(PIC *PDest, PIC *PSrc, double Alpha);
void PicFilterSobel(PIC *PDest, PIC *PSrc, double Alpha);
void PicFilterMedian(PIC *PDest, PIC *PSrc, int N);
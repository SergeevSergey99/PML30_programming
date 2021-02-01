/*--------------------------------
----------Sergeev_Sergey----------
--------------------11_6----------
-----------------group_B----------
--------------29.11.2016----------
--------------------------------*/
typedef struct
{
  int Year, Month, Day;
} DATE;
typedef struct
{
  char SurName[30], Name[15];
  DATE Birthday;
  char Phone[20];
  char Sex;
  int Form;
  char FormDigit;
} PUPIL;
void GetStr(char *Str, int MaxLen);
void ReadPupil(PUPIL *P);
int SaveDB(char *FileName, PUPIL *Base, int Size);  
int LoadDB(char *FileName, PUPIL *Base, int MaxSize); 
void Swap(PUPIL *Pupil1, PUPIL *Pupil2);
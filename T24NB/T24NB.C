/*--------------------------------
----------Sergeev_Sergey----------
--------------------11_6----------
-----------------group_B----------
--------------29.11.2016----------
--------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include"NB.h"
#include<ctype.h>
#define MAX 50
void main(void)
{
  int DBSize = 0, run = 1, i;
  static PUPIL DB[MAX];
  char fname[100];

  while (run)
  {
    printf("DB vp\n"
           "0 - exit\n"
           "1 - add a new pupil\n"
           "2 - out all pupils\n"
           "3 - delete pupil by number\n"
           "4 - sort pupils\n"
           "5 - flip pupil base\n"
           "6 - save pupil base\n"
           "7 - load pupil base\n");
    switch(_getch())
    {
    case '0':
      run = 0;
      break;
    case '1':
      if (DBSize < MAX)
        ReadPupil(&DB[DBSize++]);
      else 
        printf("Not enough room...\n");
      break;
    case '2':
      printf("------------------------------------------------------------------------------\n");
      printf("#\tSurName\tName\tSex\tBirthday\tPhone\t\t\tForm\n");
      for(i = 0; i < DBSize; i++)
        printf("%i)\t%s\t%s\t%c\t%02i.%02i.%04i\t%s\t%i-%c\n", i, DB[i].SurName, DB[i].Name,
        DB[i].Sex, DB[i].Birthday.Day, DB[i].Birthday.Month, DB[i].Birthday.Year, DB[i].Phone, DB[i].Form, DB[i].FormDigit);
      
      printf("------------------------------------------------------------------------------\n");
      break;
    case '3':
      printf("Imput a number for delete:");
      scanf("%i", &i);
      GetStr(NULL, 0);
      if (i >= 0 && i < DBSize)
        DB[i] = DB[--DBSize];
      else 
        printf("Incorrect number (0...%i)", DBSize);
      break;
    case '4': 
      printf("Choose type of sort:\n"
             "1 - Alfabetical\n"
             "2 - Age\n");
       switch(_getch())
    {       
      case '1':        
        printf("Alfabetical\n");
        break;     
      case '2':
        printf("Age\n");
        break;
    default: 
      printf("incorrect choice...\n");
    }
      break;
    case '5':
      for(i = 0; i < DBSize / 2; i++)
        Swap(&DB[i], &DB[DBSize - i - 1]);
      break; 
    case '6':
      printf("Imput file name for save:");
      GetStr(fname, sizeof(fname));
      if (SaveDB(fname, DB, DBSize))
        printf("OK...\n");
      else
        printf("Fail...\n");
      break;
    case '7':
      printf("Imput file name for open:");
      GetStr(fname, sizeof(fname));
      DBSize = LoadDB(fname, DB, MAX);
      printf("REad %i records\n",DBSize);
      break;
    default: 
      printf("incorrect choice...\n");
    }
  }
}
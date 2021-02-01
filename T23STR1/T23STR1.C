/*--------------------------------
----------Sergeev Sergey----------
--------------------11-6----------
-----------------group B----------
--------------25.10.2016----------
--------------------------------*/
#include<stdio.h>
#include<stdlib.h>  
#include"STR1.h"

void main(void)
{
  char *s, fname[1000] = "X:\\TXT\\ORWELL.TXT";
  char abc[26] = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;

  s = Load(fname);
  if (s == NULL)
  {
    printf("No memory or no file...\n");
    return;
  }
  
  printf("Length of file is    %15i\n", StrLength(s));
  printf("Number of Strings is %15i\n", StrStringCount(s));
  printf("Number of Digits is  %15i\n", StrDigitCount(s, 0, StrLength(s)));
  printf("Number of Letters is %15i\n\n", StrLettersCount(s));
  while (i < 26)
  {
    printf("Number of        %c: %16i\n", abc[i], StrEachLetterCount(s, i));   
    i++;
  }
  i = 0;
  while (i < 32)
  {                          
    
    printf("Number of        %c: %16i\n", i + 128, StrEachRUSLetterCount(s, i));   
    if (i == 5)
      printf("Number of        %c: %16i\n", 240,  StrEachRUSLetterCount(s, 32));   
    i++;
  }

  if (IsSymetrik(s, 0, 0) == 1)
    printf("Text of file is Symetrik\n");
  else    printf("Text of file is not Symetrik\n");
  
  if (IsPolindrom(s) == 1)
      printf("Text of file is Polindrom\n");
  else    printf("Text of file is not Polindrom\n");
  
  printf("Number of words in file is               %5i\n", WordsCount(s));
  printf("Number of Simetrik words in file is      %5i\n", WordsSymetrikCount(s));
  printf("Sum of Digits in strings of text is      %5i\n", DigitSum(s));
  free(s);
  getch();
}
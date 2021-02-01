/*--------------------------------
----------Sergeev Sergey----------
--------------------11-6----------
-----------------group B----------
--------------25.10.2016----------
--------------------------------*/
#include<stdio.h>
#include<stdlib.h>

char *Load(char *FileName);
int StrLength(char *s);
/*void GetStr(char *Str, int MaxLen);    */
int StrDigitCount(char *s, int begin, int end);
int StrLettersCount(char *s);
int StrStringCount(char *s);          
int StrEachLetterCount(char *s, int i);        
int StrEachRUSLetterCount(char *s, int N);    
int IsSymetrik(char *s, int i, int j);                      
int IsPolindrom(char *s);
int WordsCount(char *s);
int WordsSymetrikCount(char *s);
int DigitSum(char *s);
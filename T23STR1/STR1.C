/*--------------------------------
----------Sergeev Sergey----------
--------------------11-6----------
-----------------group B----------
--------------25.10.2016----------
--------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include"STR1.h"
#include<ctype.h>
#include<math.h>
int DigitSum(char *s)
{ 
  int Sum = 0, cnt =  0, i = 0, begin, end;
  while (s[i] != 0) 
  {
    if (isspace(s[i]))
      i++;
    if (s[i] != 0 && !isspace(s[i]))
    {
      begin = i;
      while (s[i] != 0 && !isspace(s[i]))
        i++;
      end = i - 1;
      cnt = StrDigitCount(s, begin, end);
      while (begin <= end && cnt != 0)
      {
        if (s[begin] >= '0' && s[begin] <= '9')
          {
            Sum = Sum + pow(10, cnt - 1) * s[begin]; 
            cnt--;
          }
        begin++;
      }
    }
    
  }
  return Sum;
}
int IsSymetrik(char *s, int i, int j)
{
  if (i == 0 && j == 0)
  {
    while (s[j] != 0)
      j++;
    j--;
  }
  while (i < j)
  {
    if (s[i] != s[j])
      return 0;
    i++;
    j--;
  }
  return 1;    
}
int WordsSymetrikCount(char *s)
{
  int cnt =  0, i = 0, begin, end;
  
  while (s[i] != 0) 
  {
    if (isspace(s[i]))
      i++;
    if (s[i] != 0)
    {
      begin = i;
      while (s[i] != 0 && !isspace(s[i]))
        i++;
      end = i - 1;
      if (IsSymetrik(s, begin, end))
        cnt++;
    }
  }
  return cnt;
}      
int WordsCount(char *s)
{
  int cnt =  0;
  char oldc = ' ';

  while (*s != 0) 
  {
    if (isspace(oldc) && !isspace(*s))
      cnt++;
    oldc = *s++;
  }
  return cnt;
}                            
int IsPolindrom(char *s)
{
  int i = 0, j = 0;

  while (s[j] != 0)
    j++;
  j--;
  while (i < j)
  {
    while (s[i] == ' ')
      i++;
    while (s[j] == ' ')
      j--;
    if (s[i] != s[j])
      return 0;
    i++;
    j--;
  }
  return 1;
}

int StrEachLetterCount(char *s, int N)
{
  int cnt = 0, i = 65 + N;

  while (*s != 0)
  {
    if ((*s == i)||(*s == i + 32))
      cnt++;
    s++;
  }
  return cnt;
}

int StrEachRUSLetterCount(char *s, int N)
{
  int cnt[33] = {0}, i = 0;

  while (*s != 0)
  {
    if (*s >= 128 && *s < 160)
      cnt[*s - 128]++;
    if (*s >= 160 && *s < 175)
      cnt[*s - 160]++;    
    if (*s >= 208 && *s < 240)
      cnt[*s - 208 + 16];
    if (*s == 240 || *s == 241)
    cnt[32]++;
    s++;
  }
  return cnt[N];
}


int StrDigitCount(char *s, int begin, int end)
{
  int cnt = 0;

  while (s[begin] != s[end])
  {
    if (begin == end)
      return cnt;
    if (s[begin] >= '0' && s[begin] <= '9')
      cnt++;
    begin++;
  }
  return cnt;
}
int StrStringCount(char *s)
{
  int cnt = 0;

  while (*s != 0)
  {
    if (*s == 10)
      cnt++;
    s++;
  }
  return cnt;
}
int StrLettersCount(char *s)
{
  int cnt = 0;

  while (*s != 0)
  {
    if ((*s >= 'a' && *s <= 'z')||(*s >= 'A' && *s <= 'Z'))
      cnt++;
    s++;
  }
  return cnt;
}
/*void GetStr(char *Str, int MaxLen)
{
  char ch;
  int i = 0;

  while ((ch = getchar()) != '\n')
    if (Str != NULL && i < MaxLen - 1)
      Str[i++] = ch;
  if (Str != NULL && i < MaxLen)
    Str[i++] = 0;
} */
int StrLength(char *s)
{
  int i = 0;
    while (s[i] != 0)
      i++;
  return i;
}
char *Load(char *FileName)
{
  int i = 0;
  char *s;
  FILE *F;

  F = fopen(FileName, "r");
  if (F == NULL)
    return NULL;
  while (fgetc(F) != EOF)
    i++;
  s = malloc(i + 1);
  if (s != NULL)
  {
    rewind(F);
    i = fread(s, 1, i, F);
    s[i] = 0;
  }
  fclose(F);
  return s;
}
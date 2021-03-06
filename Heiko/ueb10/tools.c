#include <stdio.h>
#include <string.h>
#include "tools.h"
#include "ini.h"

void clearBuffer()
{
  char foo;
  do
  {
    scanf("%c",&foo);
  } while (foo != '\n');
}


void countCharsPerType(unsigned char *ascii, int *anz, int *charCount)
{
  int i = 0;

  for (i = 0; i < *charCount; i++)
  {
    if ( (ascii[i] >= 'A') && (ascii[i] <= 'Z') )
      anz[ascii[i] + 32] += 1;
    else
    {
      anz[ascii[i]] += 1;
    }
  }
}


int getString (unsigned char *ascii)
{
  int i;

  do
  {
    *ascii = '\0';
    scanf("%150[^\n]", ascii);
  } while (*ascii == '\0');
  
  /*
  for (i = 0; ascii[i-1] != '\n'; i++)
  {
    if (i == MAXZEICHEN)
    { 
      clearBuffer();
      break;
    }
    scanf("%c", ascii + i);
  }
  */
  i = strlen(ascii);
  return i; // (i-1);  //um \n nicht zu betrachten 
}


void clearArray(int * countPointer, int size)
{
  int i;
 
  for (i = 0; i < size; i++)
  {
    countPointer[i] = 0;
  }
}

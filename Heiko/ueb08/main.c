#include <stdio.h>
#include "escapesequenzen.h"

void printFrame();
short getNumber(int line);
void printInputNumber(int line, short number);
char getOperator();
void printInputOperator(char operator);
short calcResult(short n1, short n2, char op);
void printResult(short n1, char op, short n2, short res);
void printResultNumber(int line, short number);
void printResultBinary(int line, short number);  //Noch Fehler
void printResultOperator(char operator);
int askAgain();
void clearBuffer();

int main()
{
  short n1, n2;
  char op;

  do
  {
    printFrame();
    n1 = getNumber(4);
    op = getOperator();
    n2 = getNumber(6);

    printResult(n1, op, n2, (calcResult(n1, n2, op)) );

  } while ( askAgain() );

  return 0;
}


void printFrame()
{
  CLEAR;
  HOME;
  printf("|----------------------------------------------------------|\n");
  printf("| Bitoperatoren-Rechner                                    |\n");
  printf("|                                                          |\n");
  printf("| Eingabe Zahl 1:                                          |\n");
  printf("| Operator:                                                |\n");
  printf("| Eingabe Zahl 2:                                          |\n");
  printf("|                                                          |\n");
  printf("|----------------------------------------------------------|\n");
  printf("|                                                          |\n");
  printf("|          |  dez.  |  okt.   |  hex.  | Binärdarstellung  |\n");
  printf("| Zahl 1   |        |         |        |                   |\n");
  printf("| Operator |        |         |        |                   |\n");
  printf("| Zahl 2   |        |         |        |                   |\n");
  printf("| -------------------------------------------------------- |\n");
  printf("| Ergebnis |        |         |        |                   |\n");
  printf("|                                                          |\n");
  printf("|----------------------------------------------------------|\n");
}

short getNumber(int line)
{
  short int number;
  POSITION(line, 19);  //19 --> Position of cursor in line
  while ( !(scanf("%hi",&number)) ) //h --> short int  //solange kein (short) int eingegeben
  {
    clearBuffer();
    POSITION(line,1);
    CLEAR_LINE;
    if (line == 4)  //Zahl 1
    {
      printf("| Eingabe Zahl 1:                                          |\n");
    }
    else  //Zahl 2
    {
      printf("| Eingabe Zahl 1:                                          |\n");
    }
  }
  clearBuffer();
  printInputNumber(line, number);
  return number;
}


void printInputNumber(int line, short number)
{
  POSITION(line,0);  // An Anfang der Zeile
  CLEAR_LINE;
  if (line == 4)  //Zahl 1
  {
    printf("| Eingabe Zahl 1: %-6hi                                   |\n", number);
  }
  else  //Zahl 2
  {
    printf("| Eingabe Zahl 1: %-6hi                                   |\n", number);
  }
}


char getOperator()
{
  char op, op2;
  do
  {
    POSITION(5,19);
    scanf("%c",&op);
    if (op == '<' || op == '>')  // Überprüfung, ob auch wirklich << oder >> eingelesen wurde
    {
      scanf("%c",&op2);
    } 
    clearBuffer();
    //Neuschreiben der Eingabezeile (Falscheingabe)
    POSITION(5,0);
    CLEAR_LINE;
    printf("| Operator:                                                |");
  } while ( (op != '&') && (op != '|') && (op != '^') && (op != '<') && (op2 != '<') && (op != '>') && (op2 != '>') );
  printInputOperator(op);
  return op;
}


void printInputOperator(char operator)
{
  POSITION(5,0);
  CLEAR_LINE;
  if ( (operator != '<') && (operator != '>') ) //da nur << und >> 2 char lang
  { 
    printf("| Operator:       %c                                        |\n", operator);
  }
  else
  {
    printf("| Operator:       %c%c                                       |\n", operator, operator);
  }
}


short calcResult(short n1, short n2, char op)
{
  switch(op)
  {
  case '&': return (n1 & n2);  // AND
  case '|': return (n1 | n2);  // OR
  case '^': return (n1 ^ n2);  // XOR
  case '<': return (n1 << n2); // shift left
  case '>': return (n1 >> n2); // shift right
  default : printf("\nSerious calculation error\n");
  }

  return 0;
}


void printResult(short n1, char op, short n2, short res)
{
  printResultNumber(11,n1);  //Zahl 1
  printResultOperator(op);
  printResultNumber(13,n2);  //Zahl 2
  printResultNumber(15,res); //Ergebnis
}


void printResultNumber(int line, short number)
{
  POSITION(line,13);  // Positon dez.
  printf("%7hi", number);
  POSITION(line,24);  // Position okt.
  printf("%6ho", number);
  POSITION(line,33);  // Position hex.
  printf("%6hx", number);
  //vorstellen der 0x vor hex.
  if ( number > 0 )
  {
    if ( number < 15 )
    {
      POSITION(line,36);
      printf("0x");
    }
    else
    {
      if (number < 255)
      {
	POSITION(line,35);
	printf("0x");
      }
      else
      {
	if (number < 4095)  
	{
	  POSITION(line,34);
	  printf("0x");
	}
	else
	{
	  POSITION(line,33);
	  printf("0x");
	}
      }
    }
  }
  else  //kleiner Null
  {
    if (number > 15)
    {
      POSITION(line,36);
      printf("0x");
    }
    else
    {
      if (number > 255)
      {
	POSITION(line,35);
	printf("0x");
      }
      else
      {
	if (number > 4095)  
	{
	  POSITION(line,34);
	  printf("0x");
	}
	else
	{
	  if (number == 0)
	  {
	    POSITION(line,36);
	    printf("0x");
	  }
	  else
	  {
	    POSITION(line,33);
	    printf("0x");
	  }
	}
      }
    }
  }
  POSITION(1,1);
  printf("line: %hi  number: %hi",line, number);
  printResultBinary(line, number);
}


void printResultBinary(int line, short number)
{
  int size, i;
  size = sizeof(short) *8;  // *8 da sizeof Größe in Byte zurückgibt
  POSITION(line,42);
  for (i = (size-1); i >= 0; i--)  //Ausgabe: von links nach rechts
  {
    printf("%i", (number >> i) & 1 );  //auszugebendes Bit nach ganz rechts shiften, durch &1 werden alle anderen Bits auf 0 gesetzt.
  }
}


void printResultOperator(char operator)
{
  POSITION(12,1);
  CLEAR_LINE;
  if ( (operator != '<') && (operator != '>') )  //da nur << und >> 2 Zeichen lang
  { 
     printf("| Operator |     %2c |      %2c |     %2c |        %2c         |\n", operator, operator, operator, operator);
  }
  else
  {
    printf("| Operator |     %c%c |      %c%c |     %c%c |        %c%c         |\n", operator, operator, operator, operator, operator, operator, operator, operator);
  }
}


int askAgain()
{
  char usrInputChar = 'a';
  POSITION(17, 0);
  printf("\n");
  printf("Moechten Sie noch einmal (j/n)? ");
  scanf("%c",&usrInputChar);


  while ( (usrInputChar != 'j') && (usrInputChar != 'n' ) && (usrInputChar != 'J') && (usrInputChar != 'N' ) )  //Bei Falscheingabe der yes/no-Abfrage
  {
    POSITION(18, 0);
    CLEAR_LINE;
    printf("Moechten Sie noch einmal (j/n)? ");
    clearBuffer();
    scanf("%c",&usrInputChar);
  }
  clearBuffer();
  switch (usrInputChar)
  {
    case 'j': return 1;
    case 'J': return 1;
    case 'n': return 0;
    case 'N': return 0;
  } 
  printf("Serious input error\n");
  return 0;
}


void clearBuffer()
{
  char foo;
  do
  {
    scanf("%c",&foo);
  } while (foo != '\n');
}

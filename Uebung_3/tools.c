#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escapesequenzen.h"
#include "tools.h"

/*************************************************************************
*   Sammelort kurzer, und dynamisch einsetzbarer Funktionen
*   Die meisten Module verbessern die Benutzeroberfläche
*************************************************************************/
//  --------------------------------------------------------------------------------
//  druckt Linie aus gewünschten Zeichen, in gewünschter Länge
//  --------------------------------------------------------------------------------
void printLine(char Zeichen, int Anzahl)
{
int j = 0;
for ( j = 0; j<Anzahl; j++ )
    {
        printf("%c", Zeichen);
    }
    printf("\n");
}

//  --------------------------------------------------------------------------------
//  Warteaufruf beendet durch die Eingabetaste
//  --------------------------------------------------------------------------------
void waitForEnter()
{
    char Dummy;
    printf("\nBitte druecken Sie die Eingabetaste ...\n");
    do
        scanf("%c", &Dummy);
    while(Dummy !='\n');
}

//  --------------------------------------------------------------------------------
//  Zeichenpuffer loeschen
//  --------------------------------------------------------------------------------
void clearBuffer()
{
   char Dummy;
   do
   {
      scanf("%c", &Dummy);
   } while (Dummy != '\n');
}

void clearScreen()
{
CLEAR;
POSITION(1, 1);
}
//  --------------------------------------------------------------------------------
//  schreibt "falsche Eingabe" bei Aufruf
//  --------------------------------------------------------------------------------
void falscheEingabe()
{
    POSITION(10, 1);
    FORECOLOR_RED;
    printf("   falsche Eingabe!");
    FORECOLOR_WHITE;
}

//  --------------------------------------------------------------------------------
//  Eingabefunktion schreibt eingegebenen Text von temporärem Speicher in
//  exakt großen Speicherbereich und gibt die Adresse dieses Bereichs zurück.
//  --------------------------------------------------------------------------------
int getText(char * Titel, char **Zeiger, unsigned int Maxlen, int AllowEmpty) // Prompt = Eingabeaufforderung, Bool = 1 oder 0 -> Wahrheitswert
{
    char *Input = NULL;
    char Format[20];
    unsigned int Len = 0;

    if(Zeiger == NULL)
    return 0;

    *Zeiger = NULL;                                                           // leeren

    Input = calloc( Maxlen + 1 , sizeof(char));
    sprintf(Format, "%%%i[^\n]", Maxlen);                                     // Formatiert die folgende Benutzereingabe
    //printf("%s", Format);
    if(Input)
    {
            do
            {
            CLEAR_LINE;
            printf("%s ", Titel); // Titel
            scanf(Format, Input); // Eingabeaufforderung
            clearBuffer();
            Len = strlen(Input); // die Länge der Text wird gezählt
            if(Len > 0)
                {
                *Zeiger = calloc(Len+1, sizeof(char*)); // Speicher für genau der Eingegebene Text reservieren
                strcpy(*Zeiger, Input);
                //printf("%s", *Zeiger);
                free(Input);//reservierter Speicher muss immer am Ende freigegeben werden
                Input= NULL;
                return 0;
                }
            else if(AllowEmpty)
                {
                free(Input);
                Input = NULL;
                return 1;
                }
            else// if (!AllowEmpty)
            {
            UP(1);
            }
            }while(!Len);
        free(Input); //reservierter Speicher muss immer am Ende freigegeben werden
        Input = NULL;
    }
    return 0;
}

/*
int getTextTo(char *Prompt, char **Pointer, int Maxlen, int AllowEmpty)
{
char *Input = NULL;
char Format[20];
int scanErg;
int Len;

if (Maxlen <= 0)
    return 0;

if(Pointer == NULL)
    return 0;

*Pointer = NULL;

Input = calloc(Maxlen + 1, sizeof(char));
    if(Input)
    {
    sprintf(Format, "%%%i[n]", Maxlen);
        do
        {
        printf("%s", Prompt);
        scanErg = scanf(Format, Input);
        clearBuffer();
            if(scanErg == 1)
            {
            Len = strlen(Input);
                if(Len > 0)
                {
                *Pointer = calloc(Len+1, sizeof(char));
                    if(Pointer)
                    {
                    strcpy(*Pointer, Input);
                    }
                    else
                    {
                    free(Input);
                    return 0;
                    }
                }
                else if(AllowEmpty)
                {
                break;
                }
                else
                scanErg = 0;
            }
            else if(AllowEmpty)
            {
            break;
            }
        }while(scanErg == 0);
        free(Input);
        return 1;
    }
    return 0;
}
*/

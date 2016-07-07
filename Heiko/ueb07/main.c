#include <stdio.h>

int main()
{
  double Op1, Op2, Erg;
  int Menuewahl, GueltigeEingabe;
  char foo;

  do
  {
    //Menü anzeigen
    printf("Einfacher Taschenrechner\n");
    printf("========================\n\n");
    printf("1. Addition\n");
    printf("2. Subtraktion\n");
    printf("3. Multiplikation\n");
    printf("4. Division\n");
    printf("9. Programmende\n");
    printf("\nIhre Wahl: ");

    if ( scanf("%d",&Menuewahl) )
    {
      do //Puffer leeren
      {
	scanf("%c",&foo);
      } while (foo != '\n');
      GueltigeEingabe = 1;  // = TRUE
      switch (Menuewahl)  // Ausgabe der Menuewahl:
      {
      case 1: printf("Addition\n");
	      printf("--------\n");
	      break;
      case 2: printf("Subtraktion\n");
	      printf("-----------\n");
	      break;
      case 3: printf("Multiplikation\n");
	      printf("--------------\n");
	      break;
      case 4: printf("Division\n");
	      printf("--------\n");
	      break;
      default:
	GueltigeEingabe = 0;  // FALSE
      }

      if (GueltigeEingabe == 1)
      {
	do  //Einlesen erste Operant
	{
	  printf("Erster Operant: ");
	  GueltigeEingabe = scanf("%lf",&Op1);
	  do //Puffer leeren
	  {
	    scanf("%c",&foo);
	  } while (foo != '\n');
	  if (GueltigeEingabe == 0)
	  {
	    printf("Falsche Eingabe\n");
	  }
	} while (GueltigeEingabe == 0);

	do  //Einlesen zweiter Operant
	{
	  printf("Zweiter Operant: ");
	  GueltigeEingabe = scanf("%lf",&Op2);
	  do //Puffer leeren
	  {
	    scanf("%c",&foo);
	  } while (foo != '\n');
	  if (GueltigeEingabe == 0)
	  {
	    printf("Falsche Eingabe\n");
	  }
	  else
	  {
	    if ( (Menuewahl == 4) && (Op2 == 0.0) )  //Abfangen der Div. durch 0
	    {
	      printf("Fehler: Division durch 0\n");
	      GueltigeEingabe = 0;
	    }
	  }
	} while (GueltigeEingabe == 0);
      }
      switch (Menuewahl)  //Ausgabe der Ergebnisse
      {
      case 1: Erg = Op1 + Op2;
	      printf("\n%.6f + %.6f = %.6f\n", Op1, Op2, Erg);
	      break;
      case 2: Erg = Op1 - Op2;
	      printf("\n%.6f - %.6f = %.6f\n", Op1, Op2, Erg);
	      break;
      case 3: Erg = Op1 * Op2;
	      printf("\n%.6f * %.6f = %.6f\n", Op1, Op2, Erg);
	      break;
      case 4: Erg = Op1 / Op2;
	      printf("\n%.6f / %.6f = %.6f\n", Op1, Op2, Erg);
	      break;
      case 9: break;
      default: printf("Falsche Eingabe\n");
      }
    }
    else
    {
      printf("Falsche Eingabe\n");
    }

    printf("\nBitte druecken Sie die Eingabetaste ...\n");
    scanf("%c",&foo);

  } while (Menuewahl != 9);

  printf("Programm wird beendet.\n");
  return 0;
}

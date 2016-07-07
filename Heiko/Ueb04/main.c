#include <stdio.h>
#include <math.h>

double read ();

//Printf: x1,x2,p,q soll 8 breit und 2 dezimalstellen sein. BEACHTE: . wird NICHT mitgezählt


int main()
{
  double p, q;   //Eingaben
  double x1, x2; //Ergebnisse
  double paramsqrt;

  printf("|--------------------------------------------------------------------|\n");
  printf("| Dieses Programm loest eine quadratische Gleichung zweiten Grades:  |\n");
  printf("| x^2 + p * x + q = 0                                                |\n");
  printf("|                                                                    |\n");
  printf("| Geben Sie bitte die Faktoren p und q ein:                          |\n");
  printf("|--------------------------------------------------------------------|\n");

  

  //Einlesen von p und q
  printf("p = ");
  p = scanf("%lf"&p);
  printf("\nq = ");
  q = read();

  //Berechnung der beiden x-Werte
  paramsqrt = ((q * q) / 4) - q;
  x1 = ((p / 2) * -1) + sqrt(paramsqrt);
  x2 = ((p / 2) * -1) - sqrt(paramsqrt);

  printf("|--------------------------------------------------------------------|\n");
  printf("| Es wird nun die quadratische Gleichung zweiten Grades              |\n");
  printf("| x^2 + %8.2f * x + %8.2f = 0                                  |\n", p, q);
  printf("| geloest.                                                           |\n");
  printf("|                                _____________________________       |\n");
  printf("|           1             +     /  %8.2f ^ 2               \\      |\n", p);
  printf("| x    = - --- * %8.2f - \\  /  ------------- - %-8.2f           |\n", p, q);
  printf("|  1,2      2                \\/         4                            |\n");
  printf("|                                                                    |\n");
  printf("| x1 = %-8.2f                                                      |\n", x1);
  printf("| x2 = %-8.2f                                                      |\n", x2);
  printf("|--------------------------------------------------------------------|\n");
  

  return 0;
}


double read()
{
  double input;
  char foo;
  while ((scanf("%lf",&input))!=1)
  {
    //Wenn kein Integer eingegeben wurde
    printf("Dies ist keine gueltige Eingabe.\nBitte geben Sie den Wert erneut ein.\n");
    scanf("%c",&foo);  //leeren des Puffers bei einer Falscheingabe
  }
  return input;
}

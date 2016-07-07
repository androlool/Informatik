#include <stdio.h>

double Reihe(double r1, double r2, double r3);
double Parallel(double r1, double r2, double r3);
double Wheaton(double r1, double r2, double r3);

int main()
{
	//Wiederstandswerte
	double r1=500.0;
	double r2=200.0;
	double r3=300.0;

	printf("Wiederstand R1 = %f Ohm\n",r1);
	printf("Wiederstand R2 = %f Ohm\n",r2);
	printf("Wiederstand R3 = %f Ohm\n",r3);
	printf("\n");

	//Aufruf der Berechnungen
	double reihe = Reihe(r1,r2,r3);
	double parallel = Parallel(r1,r2,r3);
	double wheaton =Wheaton(r1,r2,r3);

	printf("Reihenschaltung:\n");
	printf("%f Ohm + %f Ohm + %f Ohm %f Ohm\n\n",r1,r2,r3,reihe);

	printf("Parallelschaltung:\n");
	printf("1 / %f Ohm + 1 / %f Ohm + 1 / %f Ohm = 1 / %f Ohm \n\n",r1,r2,r3,parallel);

	printf("Wheatonsche Messbruecke:\n");
	printf("%f Ohm * ( %f Ohm / %f Ohm) = %f Ohm\n\n",r1,r2,r3,wheaton);


	return 0;
}


//Berechnung des Wiederstandes der Reihenschaltung
double Reihe(double r1, double r2, double r3)
{
	double r = r1 + r2 + r3;
	return r;
}


//Berechnung des Wiederstandes der Parallelschaltung
double Parallel(double r1, double r2, double r3)
{
	double r = (1/r1) + (1/r2) + (1/r3);
	return 1/r;
}


//Berechnung des Wiederstandes der Wheatonschen Messbrücke
double Wheaton(double r1, double r2, double r3)
{
	double r = (r1 / r2) * r3;
	return r;
}

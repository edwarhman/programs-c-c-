//Programa que calcula el rango de la frecuencia cardiaca óptima que debe tener una persona según su edad

#include <iostream>
#include "FrecuenciaCardiaca.h"
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	FrecuenciaCardiaca persona1("Emerson","Warhman",18, 3, 1997);
	int frecMin= 0, frecMax = 0;
	persona1.establecerFrecuenciaCardiaca(&frecMin, &frecMax);
	cout << "La frecuencia optima de " << persona1.obtenerNombre() << " " << persona1.obtenerApellido() << " de " << persona1.obtenerEdad()
		 << " años es entre " << frecMin << " y " << frecMax << "pulsasiones por minuto." << endl;

	return 0;
}

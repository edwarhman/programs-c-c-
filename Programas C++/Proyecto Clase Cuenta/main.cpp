#include <iostream>
#include "Cuenta.h"
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main()
{
	int selector = 0;
	int valor = 0;
	setlocale(LC_ALL, "");
	Cuenta cuenta1(-100);
	cuenta1.mostrarSaldo();
	do
	{
		cout << "\nDebe ingresar el número de la operación que desea realizar."
			 << "\n1. Consultar saldo."
			 << "\t2. Abonar monto."
			 << "\t3. Retirar monto."
			 << "\t0. Salir."
			 << "\nIngrese el número de operación: ";
		cin >> selector;

		switch (selector)
		{
		case 1:
			cuenta1.mostrarSaldo();
			break;
		case 2:
			cout << "Ingrese el monto que desea abonar: ";
			cin >> valor;
			cuenta1.abonar(valor);
			break;
		case 3:
			cout << "Ingrese el monto que desea retirar: ";
			cin >> valor;
			cuenta1.retirar(valor);
			break;
		default:
			break;
		}
	} while (selector != 0);

	return 0;
}

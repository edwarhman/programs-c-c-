#include "EmpleadoPorComision.h"
#include "EmpleadoBaseMasComision.h"
#include <locale.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");

    // Empleado con comisi�n
    EmpleadoPorComision empleado("Jaimito", "Gonz�lez", "(222)-2222", 5000,0.2);
    empleado.imprimir();
    cout << "Sueldo del empleado: " << empleado.ingresos() << endl;

    // Empleado con ingreso base y comisi�n
    EmpleadoBaseMasComision empleado1("Tom�s", "Salagoza", "(333)-3333", 8000, 0.1, 700);
    empleado1.imprimir();
    cout << "Sueldo del empleado: " << empleado1.ingresos() << endl;

    return 0;
}

#include "SinDuplicados.h"
#include <iostream>
#include <locale.h>
using namespace std;

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    SinDuplicados miArreglo;

    cout << "Antes de mostrar arreglo." << endl;
    miArreglo.mostrarElementos();
    cout << "Después de mostrar arreglo." << endl;

    // Leer 20 datos
    cout << "Usted debe ingresar 20 números que se encuentren entre 10 y 100" << endl;
    for (size_t i = 0; i < ELEMENTOS; i++)
    {
        cout << "Por favor ingrese un número: ";
        miArreglo.leerEntrada();
    }
    
    cout << "Los elementos del arreglo son: ";
    miArreglo.mostrarElementos();
    return 0;
}

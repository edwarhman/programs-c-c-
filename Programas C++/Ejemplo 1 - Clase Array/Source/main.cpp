#include <locale.h>
#include <iostream>
#include "Arreglos.h"
#include <initializer_list>
using namespace std;

void mostrarArreglo(const Arreglos &a);

int main()
{
    setlocale(LC_ALL, "");
    Arreglos a1(10);
    for (size_t i = 0; i < a1.obtenerTamanio(); i++)
    {
        a1[i] = i;
    }
    cout << "En el arreglo se encuentran los elementos:" << endl;
    mostrarArreglo(a1);
    Arreglos a2(a1);
    cout << "En el arreglo se encuentran los elementos:" << endl;
    mostrarArreglo(a2);

    if (a1 == a2)
    {
        cout <<"\nAmbos arreglos son iguales." << endl;
    }
    
    Arreglos a3 = a1;
    mostrarArreglo(a3);
    cout << "Ingrese " << a3.obtenerTamanio() << " enteros para el arreglo:";
    cin >> a3;
    cout << a3;
    return 0;
}

void mostrarArreglo(const Arreglos &a)
{
    for (size_t i = 0; i < a.obtenerTamanio(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
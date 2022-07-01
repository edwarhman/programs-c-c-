#include <iostream>
using namespace std;

// Prototipos funciones
template <typename T>
T Maximo(T valor1, T valor2, T valor3);
template <typename T>
T Minimo(T valor1, T valor2, T valor3);

// Funcion main
int main(int argc, char const *argv[])
{
    cout << Minimo(13, 53, 23) << endl;
    cout << Minimo('A', 'G', 'T') << endl;
    cout << Maximo(13, 53, 23) << endl;
    cout << Maximo(13.25, 53.41, 23.42) << endl;
    return 0;
}

template <typename T>
T Maximo(T valor1, T valor2, T valor3)
{
    T valorMaximo = valor1;
    if (valor2 > valorMaximo)
    {
        valorMaximo = valor2;
    }
    if (valor3 > valorMaximo)
    {
        valorMaximo = valor3;
    }
    return valorMaximo;
}

template <typename T>
T Minimo(T valor1, T valor2, T valor3)
{
    T valorMinimo = valor1;
    if (valor2 < valorMinimo)
    {
        valorMinimo = valor2;
    }
    if (valor3 < valorMinimo)
    {
        valorMinimo = valor3;
    }
    return valorMinimo;
}


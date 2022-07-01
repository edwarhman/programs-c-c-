#include <iostream>
#include <iomanip>
#include "EnteroEnorme.h"
#include <ctype.h>
#include "MisFunciones.h"
using namespace std;


EnteroEnorme::EnteroEnorme()
{
    digitos = {0};
}

EnteroEnorme::EnteroEnorme(string cadena)
{
    digitos = {0};
    convertir(&cadena);
}

EnteroEnorme::~EnteroEnorme()
{
}

void EnteroEnorme::leerEntrada(string *entrada)
{
    char cadena[DIGITOS];
    cout << "Ingrese un entero positivo de hasta " << DIGITOS << " digitos: ";
    cin.getline(cadena,DIGITOS);
    if (esDigito(cadena))
    {
        *entrada = cadena;
        cout << endl;
    }
    else
    {
        cerr << "Error. La entrada suministrada no es un número entero." << endl << endl;
        leerEntrada(entrada);
    }
}

void EnteroEnorme::convertir(const string *cadena)
{
    int espacios = 0;
    espacios = DIGITOS - cadena->length();
    for (int i = DIGITOS - 1; i >= espacios; i--)
    {
        digitos[i] = (int) cadena->at(i - espacios) - 48;
    }
}

void EnteroEnorme::recibir() 
{
    string entrada;
    leerEntrada(&entrada);
    convertir(&entrada);
}

void EnteroEnorme::imprimir() const
{
    bool primerDigito = false;
    for (auto &i : digitos)
    {
        if (i == 0 && primerDigito == false)
        {//¡IMPORTANTE, NO BORRAR!
        }
        else
        {
            primerDigito = true;
            cout << i;
        }
    }
    cout << "\n";
}

// Operadores Aritméticos

// Operador Suma
const EnteroEnorme EnteroEnorme::operator+(EnteroEnorme arg2) const
{
    EnteroEnorme enteroRetorno;
    int suma = 0;
    int acumulador = 0;
    for (int i = DIGITOS - 1; i >= 0; i--)
    {
        suma = arg2.obtenerDigito(i) + this->obtenerDigito(i) + acumulador;
        if (suma > 9)
        {
            acumulador = 1;
            suma = 0;
        }
        else
        {
            acumulador = 0;
        }
        enteroRetorno.establecerDigito(i, suma);
    }
    return enteroRetorno;
}

// Operador de asignación
EnteroEnorme EnteroEnorme::operator=(EnteroEnorme arg2)
{
    for (size_t i = 0; i < DIGITOS; i++)
    {
        this->establecerDigito(i, arg2.obtenerDigito(i));
    }
}


#include "Monedas.h"
#include <random>
#include <time.h>
#include <iostream>
using namespace std;

default_random_engine motor(static_cast<unsigned int>(time(0)));
uniform_int_distribution<unsigned int> aleartorio(0,1);

Monedas::Monedas(/* args */)
:ultimoLanzamiento(0)
{

}

Monedas::~Monedas()
{

}

bool Monedas::tirarMoneda()
{
    ultimoLanzamiento = aleartorio(motor);
    mostrarResultado();
    return ultimoLanzamiento;
}

void Monedas::mostrarResultado() const
{
    if(ultimoLanzamiento)
        cout << "El resultado es cruz." << endl;
    else
        cout << "El resultado es cara." << endl;
}
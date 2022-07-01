#include <random>
#include <ctime>
#include "JuegoDados.h"
#include <iostream>
#define RANGO 36000
using namespace std;

int main(int argc, char const *argv[])
{
    default_random_engine motor(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> aleartorio(1, JuegoDados::caras);
    JuegoDados juego1;
    cout << "El motor al inicio de main es " << motor << endl;
    for (size_t i = 0; i < RANGO; i++)
    {
        juego1.lanzarDados();
    }
    cout << endl;
    juego1.mostrarResultados();
    return 0;
}

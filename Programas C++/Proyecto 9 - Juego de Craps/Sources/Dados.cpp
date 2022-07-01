#include "Dados.h"
#include <random>
#include <ctime>
using namespace std;
default_random_engine motor(static_cast<unsigned int>(time(0)));
uniform_int_distribution<unsigned int> aleartorio(1, TOTAL_CARAS);

Dados::Dados(/* args */)
{
}

Dados::~Dados()
{
}

//Función que arroja la cantidad de dados ingresados por el usuario y retorna el valor de los resultados
unsigned Dados::tirarDado(unsigned dados) const
{
    if(dados == 1)
        return aleartorio(motor);
    else
        return aleartorio(motor) + tirarDado(dados-1);
}
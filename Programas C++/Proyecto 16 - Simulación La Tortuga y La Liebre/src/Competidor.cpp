#include "Competidor.h"
using namespace std;

Competidor::Competidor(char nuevoIdentificador)
:posicion(1), identificador(nuevoIdentificador)
{
}

Competidor::~Competidor()
{
}

void Competidor::mover(int nuevaPosicion)
{
    if (nuevaPosicion <= 0)
    {
        posicion = 1;
    }
    else if (nuevaPosicion <= META)
    {
        posicion = nuevaPosicion;
    }
    else
    {
        posicion = META;
    }
    
}

int Competidor::obtenerPosicion() const
{
    return posicion;
}

char Competidor::obtenerIdentificador() const
{
    return identificador;
}
#include "Liebre.h"
#include <time.h>
#include <random>
using namespace std;
default_random_engine motor(static_cast<unsigned>(time(0)));
uniform_int_distribution<unsigned> movimientos(1, 10);

Liebre::Liebre()
:Competidor('L')
{
}

Liebre::~Liebre()
{
}

void Liebre::mover()
{
    unsigned aleartorio;
    int nuevaPosicion = 0;
    int movimiento = 0;
    aleartorio = movimientos(motor);
    if (aleartorio <= 2)
    {
        movimiento = 0;
    }
    else if (aleartorio <= 4)
    {
        movimiento = 9;
    }
    else if (aleartorio <= 5)
    {
        movimiento = -12;
    }
    else if (aleartorio <= 8)
    {
        movimiento = 1;
    }
    else
    {
        movimiento = -2;
    }
    nuevaPosicion = Competidor::obtenerPosicion() + movimiento;
    Competidor::mover(nuevaPosicion);
    
}
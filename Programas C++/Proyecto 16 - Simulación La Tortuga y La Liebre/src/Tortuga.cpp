#include "Tortuga.h"
#include <time.h>
#include <random>
using namespace std;
default_random_engine  motor1(static_cast<unsigned>(time(0)));
uniform_int_distribution<unsigned> movimientos1(1, 10);

Tortuga::Tortuga()
:Competidor('T')
{
}

Tortuga::~Tortuga()
{
}

void Tortuga::mover()
{
    int movimiento = 0;
    int nuevaPosicion = 0;
    unsigned aleartorio = movimientos1(motor1);
    if (aleartorio <= 5)
    {
        movimiento = 3;
    }
    else if (aleartorio <= 7)
    {
        movimiento = -6;
    }
    else
    {
        movimiento = 1;
    }
    nuevaPosicion = Competidor::obtenerPosicion() + movimiento;
    Competidor::mover(nuevaPosicion);
}
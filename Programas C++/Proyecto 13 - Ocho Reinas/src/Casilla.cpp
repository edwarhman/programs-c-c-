#include "Casilla.h"
#include <stdexcept>
using namespace std;
//Constructor de la clase (establece el estado y las eliminaciones a 0).
Casilla::Casilla(/* args */)
:estado(0), eliminaciones(0)
{
}

// Destructor de la clase.
Casilla::~Casilla()
{
}

// Establece el estado de la casilla al valor suministrado como parámetro.
void Casilla::establecerEstado(unsigned nuevoEstado)
{
    if (nuevoEstado >= 0)
    {
        estado = nuevoEstado;
    }
    else
    {
        throw invalid_argument("Dato invalido. El nuevo valor debe ser mayor o igual a 0.");
    }
    
}

// Obtiene el estado actual de la casilla.
unsigned Casilla::obtenerEstado() const
{
    return estado;
}

// Establece las eliminaciones de la casilla al valor suministrado como parámetro.
void Casilla::establecerEliminaciones(unsigned bloqueos)
{
    if (bloqueos >= 0)
    {
        eliminaciones = bloqueos;
    }
    else
    {
        throw invalid_argument("Dato invalido. El nuevo valor debe ser mayor o igual a 0.");
    }
    
}

// devuelve las eliminaciones de la casilla.
unsigned Casilla::obtenerEliminaciones() const
{
    return eliminaciones;
}
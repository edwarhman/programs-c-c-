#include "PosiblesSumas.h"

// Constructor clase Posible suma
PosiblesSumas::PosiblesSumas(int iResultado)
: apariciones(0), posibleResultado(iResultado)
{

}

void PosiblesSumas::aumentarApariciones()
{
    apariciones++;
}

int PosiblesSumas::obtenerPosiblesSumas() const
{
    return posibleResultado;
}

int PosiblesSumas::obtenerApariciones() const
{
    return apariciones;
}
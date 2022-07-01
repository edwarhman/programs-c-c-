#include "FechaHora.h"
#include <iostream>
using namespace std;

// h : hora, m : minuto, s: segundo, dd: dia, mm: mes, aa: año
FechaHora::FechaHora(int h, int m, int s, int dd, int mm, int aa)
:Tiempo(h, m, s), Fecha(dd, mm, aa)
{
}

FechaHora::~FechaHora()
{
}

void FechaHora::imprimir() const
{
    Tiempo::imprimirEstandar();
    Fecha::imprimir();
}

void FechaHora::tictac()
{
    Tiempo::tictac();
    if (Tiempo::operator==(Tiempo(0, 0, 1)))
    {
        Fecha::siguienteDia();
    }
}


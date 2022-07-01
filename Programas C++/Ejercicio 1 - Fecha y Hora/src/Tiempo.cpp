#include "Tiempo.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <ctime>
#define DOCE 12
using namespace std;

// Constructores
Tiempo::Tiempo()
:hora(0), min(0), seg(0)
{
    time_t tiempo = time(0);   
    hora = localtime(&tiempo)->tm_hour; 
    min = localtime(&tiempo)->tm_min;
    seg = localtime(&tiempo)->tm_sec;
}

Tiempo::Tiempo(int h, int m, int s)
{
    establecerTiempo(h, m, s);
}

Tiempo::~Tiempo()
{
}

//Funciones Establecer

void Tiempo::establecerTiempo(int nHora, int nMin, int nSeg)
{
    establecerHora(nHora);
    establecerMin(nMin);
    establecerSeg(nSeg);
}

void Tiempo::establecerTiempo(time_t)
{
    time_t tiempo = time(0);
    establecerHora(localtime(&tiempo)->tm_hour);
    establecerMin(localtime(&tiempo)->tm_min);
    establecerSeg(localtime(&tiempo)->tm_sec);
}

void Tiempo::establecerHora(int entrada)
{
    if (entrada >= 0 && entrada < 24)
    {
        hora = entrada;
    }
    else
    {
        throw invalid_argument("Argumento inválido. La hora no puede ser mayor a 23.");
    }   
}

void Tiempo::establecerMin(int entrada)
{
    if (entrada >= 0 && entrada < 60)
    {
        min = entrada;
    }
    else
    {
        throw invalid_argument("Argumento inválido. Los minutos no pueden ser mayor a 60.");
    }   
}

void Tiempo::establecerSeg(int entrada)
{
    if (entrada >= 0 && entrada < 60)
    {
        seg = entrada;
    }
    else
    {
        throw invalid_argument("Argumento inválido. Los segundos no pueden ser mayor a 59.");
    }   
}


// Funciones obtener

int Tiempo::obtenerHora() const 
{
    return hora;
}

int Tiempo::obtenerMin() const 
{
    return min;
}

int Tiempo::obtenerSeg() const 
{
    return seg;
}

// Funciones de impresion

void Tiempo::imprimirUniversal() const
{
    cout << setw(2) << setfill('0') << obtenerHora() << ":" << setw(2) << obtenerMin() << ":" << setw(2) << obtenerSeg() << endl;
}

void Tiempo::imprimirEstandar() const
{
    cout << setw(2) << setfill('0') << ((obtenerHora() == 0 || obtenerHora() == DOCE)? DOCE : obtenerHora() % DOCE) << ":" << setw(2) << obtenerMin() << ":" << setw(2) << obtenerSeg() << ((obtenerHora() < DOCE )? " A.M." : " P.M.") << endl;
}

// Otras funciones

void Tiempo::tictac() 
{
    int h = obtenerHora();
    int m = obtenerMin();
    int s = obtenerSeg() + 1;

    if (s >= 60)
    {
        m++;
        s = 0;
        if ( m >= 60)
        {
            h++;
            m = 0;
            if ( h >= 24)
            {
                h = 0;
            }
        }
    }
    establecerTiempo(h, m, s);
}

// Operadores sobrecargados

bool Tiempo::operator==(Tiempo arg2) const
{
    if (
        this->obtenerHora() == arg2.obtenerHora() &&
        this->obtenerMin() == arg2.obtenerMin() &&
        this->obtenerSeg() == arg2.obtenerSeg()
    )
    {
        return true;
    }
    else
    {
        return false;
    }
}
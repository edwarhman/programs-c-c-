#include "Competicion.h"
#include <string>
#include <iostream>
#include <windows.h>
using namespace std;


Competicion::Competicion()
    : tortuga(), liebre()
{
}

Competicion::~Competicion()
{
}

Tortuga * Competicion::obtenerTortuga() 
{
    return &tortuga;
}

Liebre * Competicion::obtenerLiebre() 
{
    return &liebre;
}

void Competicion::comenzar()
{
    while (!comprobarEstado())
    {
        Sleep(1000);
        system("cls");
        obtenerLiebre()->mover();
        obtenerTortuga()->mover();
        mostrar();
    }
    establecerGanador();
}

void Competicion::mostrar() const
{
    for (size_t i = 1; i <= META; i++)
    {
        if (i == tortuga.obtenerPosicion())
        {
            cout << tortuga.obtenerIdentificador() << " ";
        }
        else if (i == META)
        {
            cout << "me";
        }
        else
        {
            cout << " ";
        }
    }
    cout << endl;
    int corredura = 0;
    for (size_t i = 1; i <= META; i++)
    {
        if (i == liebre.obtenerPosicion())
        {
            cout << liebre.obtenerIdentificador() << " ";
            if (liebre.obtenerPosicion() == tortuga.obtenerPosicion() && i != 1)
            {
                cout << "OUCH!" ;
                corredura += string("OUCH!").size();
            }
        }
        else if (i == META - corredura)
        {
            cout << "ta";
        }    
        else
        {
            cout << " ";
        }
    }
    cout << endl;
}

bool Competicion::comprobarEstado() const
{
    if (tortuga.obtenerPosicion()>= META || liebre.obtenerPosicion() >= META)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Competicion::establecerGanador()
{
    if(obtenerLiebre()->obtenerPosicion() == META && obtenerTortuga()->obtenerPosicion() == META)
    {
        ganador = Ganador::EMPATE;
    }
    else if (obtenerTortuga()->obtenerPosicion() != META )
    {
        ganador = Ganador::LIEBRE;
    }
    else
    {
        ganador = Ganador::TORTUGA;
    }
}

Ganador Competicion::obtenerGanador() const
{
    return ganador;
}

void Competicion::mostrarGanador() const
{
    switch (obtenerGanador())
    {
    case Ganador::LIEBRE:
        cout << "La liebre gana. Uoooh" << endl;
        break;
    case Ganador::TORTUGA:
        cout << "La tortuga gana. Yeiiiih" << endl;
        break;
    default:
        cout << "Hubo un empate." << endl;
        break;
    }
}
#include "Apuestas.h"
#include <iostream>
using namespace std;


Apuestas::Apuestas()
:fondos(1000), apuesta(0), enjuego(0)
{
}

Apuestas::~Apuestas()
{
}

void Apuestas::apostar()
{
    int entrada;
    cout << "Ingrese la cantidad que desea apostar: ";
    cin >> entrada;
    establecerApuesta(entrada);
}

void Apuestas::establecerApuesta(int valor)
{
    if(valor>obtenerFondos())
        {
            cerr << "Entrada inválida. La apuesta no puede ser mayor a los fondos." << endl;
            apostar();
        }
    else if (valor <= 0)
    {
        cerr << "Entrada inválida. La apuesta debe ser mayor a 0." << endl;
        apostar();
    }
    else 
        apuesta = valor;
    
}


unsigned Apuestas::obtenerFondos() const
{
    return fondos;
}

unsigned Apuestas::obtenerApuesta() const
{
    return apuesta;
}

void Apuestas::establecerFondos(Resultado estado)
{
    if (estado == Resultado::GANA)
    {
        fondos += (obtenerEnJuego() * 2);
    }
    else if (estado == Resultado::PIERDE)
    {
        fondos -= obtenerApuesta();
    }
    
}

void Apuestas::mostrarFondos() const
{
    cout << "Su saldo actual es " << obtenerFondos() << endl;
}

void Apuestas::incrementarApuesta()
{
    char entrada;
    cout << "¿Desea incrementar la apuesta? (s/n): ";
    cin >> entrada;
    if (entrada == 's' || entrada == 'S')
    {
        apostar();
        establecerFondos(Resultado::PIERDE);
        establecerEnJuego();
    }
    else if (entrada == 'n' || entrada == 'S')
    {
        cout << "Presione enter para volver a tirar." << endl;
        cin.getloc();
    }
    
}

void Apuestas::reestablecerEnJuego()
{
    enjuego = 0;
}

void Apuestas::establecerEnJuego()
{
    enjuego += apuesta;
}

unsigned Apuestas::obtenerEnJuego() const
{
    return enjuego;
}
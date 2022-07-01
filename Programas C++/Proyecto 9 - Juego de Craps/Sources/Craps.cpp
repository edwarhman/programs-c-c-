#include "Craps.h"
#include <iostream>
using namespace std;

//Constructor de la clase Craps
Craps::Craps(/* args */)
:estado(Estado::REPITE), tiro(0), conteoTiros(0), puntoJugador(0)
{
}//Fin de Constructor

//Destructor de la clase
Craps::~Craps()
{
}//Fin de destructor

//Función si comprueba el estado del juego y determina si el juego debe finalizar;
bool Craps::comprobarEstado()
{
    if (obtenerConteoTiros() == 1)
    {
        comprobarTiradaInicial(); 
    }
    else
    {
        comprobarRestoDeTiros();
    }
    if (obtenerEstado()==Estado::GANA || obtenerEstado() == Estado::PIERDE)
    {
        return true; //Indica que el juego debe terminar
    }
    else
    {
        return false; //Indica que el juego debe finalizar
    }
    
    
}//Fin de la función comprobarEstado

//Función que comprueba la tirada inicial y establece el estado según corresponda
void Craps::comprobarTiradaInicial()
{
    if (obtenerTiro() == 7 || obtenerTiro() == 11) //Condición de victoria
    {
        establecerEstado(Estado::GANA);
    }
    else if (obtenerTiro() == 2 || obtenerTiro() == 3 || obtenerTiro() == 12) //Condición de derrota
    {
        establecerEstado(Estado::PIERDE);
    }
    else //El juego continúa
    {
        establecerPuntoJugador();
        establecerEstado(Estado::REPITE);
    }
    
}//Fin de la función comprobarTiradaInicial

//Función que comprueba las tiradas distintas a la primera y establece el estado según corresponda
void Craps::comprobarRestoDeTiros()
{
    if (obtenerPuntoJugador() == obtenerTiro()) //Condición de victoria
    {
        establecerEstado(Estado::GANA);
    }
    else if (obtenerTiro() == 7) //Condición de derrota
    {
        establecerEstado(Estado::PIERDE);
    }
    else //El juego continúa
    {
        establecerEstado(Estado::REPITE);
    }
    
}//Fin de la función comprobarRestoDeTiros

//Función que establece el estado actual del juego según el parámetro suministrado
void Craps::establecerEstado(Estado nuevoEstado)
{
    estado = nuevoEstado;
}//Fin de la función establecerEstado

//Función que establece el tiro actual como el punto del jugador
void Craps::establecerPuntoJugador()
{
    puntoJugador = obtenerTiro();
}//Fin de la función establecerPuntoJugador

//Función que obtiene el punto del jugador
unsigned Craps::obtenerPuntoJugador() const
{
    return puntoJugador;
}//Fin de la función obtenerPuntoJugador

//Función que obtiene el tiro actual
unsigned Craps::obtenerTiro() const
{
    return tiro;
}//Fin de la función obtenerTiro

//Función que establece el tiro del dado. El argumento debe ser la suma de los dados
//Tambien incremeta en uno la cantidad de tiros
void Craps::establecerTiro(unsigned nuevoTiro)
{
    tiro = nuevoTiro;
    incrementarTiros();
}//Fin de la función establecerTiro

//Función que incrementa en uno la cantidad de tiros hechos por el usuario
void Craps::incrementarTiros()
{
    ++conteoTiros;
}//Fin de la función incrementarTiros

//Función que obtiene el estado actual de la partida
Estado Craps::obtenerEstado() const
{
    return estado;
}//Fin de la función obtenerEstado

//Función que obtiene la cantidad de tiros realizados
unsigned Craps::obtenerConteoTiros() const
{
     return conteoTiros;
}//Fin de la función obtenerConteoTiros

void Craps::mostrarMensaje(Mensajes tipoMensaje) const
{
    switch (tipoMensaje)
    {
    case Mensajes::INICIAL:
        cout << "Tirada Inicial\nSi saca un 7 o un 11 ganará."
                "\nSi saca un 2, un 3 o un 12 perderá."
                "\nSi saca  4, 5, 6, 8, 9 o 10 seguirá jugando" << endl;
        break;
    case Mensajes::CONTINUAR:
        cout << "Ha sacado un " << obtenerTiro() << ". Debe continuar jugando."
             << "\nSu siguiente tiro debe ser igual a " << obtenerPuntoJugador() 
             << "\nSi sale un 7 perderá la partida." << endl; 
        break;
    case Mensajes::GANADOR:
        cout << "Ha sacado un " << obtenerTiro() << endl;
        cout << "¡Felicidades! Ha ganado el juego." << endl;
        break;
    case Mensajes::PERDEDOR:
        cout << "Ha sacado un " << obtenerTiro() << endl;
        cout << "Lástima. Usted ha perdido el juego." << endl;
        break;

    default:
        break;
    }
}


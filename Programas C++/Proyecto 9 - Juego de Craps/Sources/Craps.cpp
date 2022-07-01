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

//Funci�n si comprueba el estado del juego y determina si el juego debe finalizar;
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
    
    
}//Fin de la funci�n comprobarEstado

//Funci�n que comprueba la tirada inicial y establece el estado seg�n corresponda
void Craps::comprobarTiradaInicial()
{
    if (obtenerTiro() == 7 || obtenerTiro() == 11) //Condici�n de victoria
    {
        establecerEstado(Estado::GANA);
    }
    else if (obtenerTiro() == 2 || obtenerTiro() == 3 || obtenerTiro() == 12) //Condici�n de derrota
    {
        establecerEstado(Estado::PIERDE);
    }
    else //El juego contin�a
    {
        establecerPuntoJugador();
        establecerEstado(Estado::REPITE);
    }
    
}//Fin de la funci�n comprobarTiradaInicial

//Funci�n que comprueba las tiradas distintas a la primera y establece el estado seg�n corresponda
void Craps::comprobarRestoDeTiros()
{
    if (obtenerPuntoJugador() == obtenerTiro()) //Condici�n de victoria
    {
        establecerEstado(Estado::GANA);
    }
    else if (obtenerTiro() == 7) //Condici�n de derrota
    {
        establecerEstado(Estado::PIERDE);
    }
    else //El juego contin�a
    {
        establecerEstado(Estado::REPITE);
    }
    
}//Fin de la funci�n comprobarRestoDeTiros

//Funci�n que establece el estado actual del juego seg�n el par�metro suministrado
void Craps::establecerEstado(Estado nuevoEstado)
{
    estado = nuevoEstado;
}//Fin de la funci�n establecerEstado

//Funci�n que establece el tiro actual como el punto del jugador
void Craps::establecerPuntoJugador()
{
    puntoJugador = obtenerTiro();
}//Fin de la funci�n establecerPuntoJugador

//Funci�n que obtiene el punto del jugador
unsigned Craps::obtenerPuntoJugador() const
{
    return puntoJugador;
}//Fin de la funci�n obtenerPuntoJugador

//Funci�n que obtiene el tiro actual
unsigned Craps::obtenerTiro() const
{
    return tiro;
}//Fin de la funci�n obtenerTiro

//Funci�n que establece el tiro del dado. El argumento debe ser la suma de los dados
//Tambien incremeta en uno la cantidad de tiros
void Craps::establecerTiro(unsigned nuevoTiro)
{
    tiro = nuevoTiro;
    incrementarTiros();
}//Fin de la funci�n establecerTiro

//Funci�n que incrementa en uno la cantidad de tiros hechos por el usuario
void Craps::incrementarTiros()
{
    ++conteoTiros;
}//Fin de la funci�n incrementarTiros

//Funci�n que obtiene el estado actual de la partida
Estado Craps::obtenerEstado() const
{
    return estado;
}//Fin de la funci�n obtenerEstado

//Funci�n que obtiene la cantidad de tiros realizados
unsigned Craps::obtenerConteoTiros() const
{
     return conteoTiros;
}//Fin de la funci�n obtenerConteoTiros

void Craps::mostrarMensaje(Mensajes tipoMensaje) const
{
    switch (tipoMensaje)
    {
    case Mensajes::INICIAL:
        cout << "Tirada Inicial\nSi saca un 7 o un 11 ganar�."
                "\nSi saca un 2, un 3 o un 12 perder�."
                "\nSi saca  4, 5, 6, 8, 9 o 10 seguir� jugando" << endl;
        break;
    case Mensajes::CONTINUAR:
        cout << "Ha sacado un " << obtenerTiro() << ". Debe continuar jugando."
             << "\nSu siguiente tiro debe ser igual a " << obtenerPuntoJugador() 
             << "\nSi sale un 7 perder� la partida." << endl; 
        break;
    case Mensajes::GANADOR:
        cout << "Ha sacado un " << obtenerTiro() << endl;
        cout << "�Felicidades! Ha ganado el juego." << endl;
        break;
    case Mensajes::PERDEDOR:
        cout << "Ha sacado un " << obtenerTiro() << endl;
        cout << "L�stima. Usted ha perdido el juego." << endl;
        break;

    default:
        break;
    }
}


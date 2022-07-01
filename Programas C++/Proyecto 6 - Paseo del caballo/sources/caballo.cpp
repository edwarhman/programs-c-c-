#include "caballo.h"
#include <vector>
#include <random>
#include <time.h>
using namespace std;

default_random_engine motor(static_cast<unsigned> (time(0)));
uniform_int_distribution<unsigned> aleartorio(0, MOVIMIENTOS - 1);
bool buscarEnArreglo(const array<unsigned, MOVIMIENTOS> &arreglo, unsigned valor);

//Constructor predeterminado de la clase caballo
Caballo::Caballo(Tablero &tabla, Coordenadas posicionInicial)
:posicionActual(posicionInicial), movimientos(1), tablero(tabla) 
{
    tabla.establecerCasilla(posicionInicial, 1);
}//Fin de constructor predeterminado


//Destructor de la clase caballo
Caballo::~Caballo()
{
}//Fin del destructor de la clase


//Funcion que obtiene la posicion actual del caballo en el tablero
Coordenadas Caballo::obtenerPosicionActual() const
{
    return posicionActual;
} ///Fin funcion obtenerPosicionActual

//Funcion que mueve al caballo segun sus patrones de movimiento siempre que sea un movimiento valido
bool Caballo::moverCaballo()
{
    vector<Coordenadas> posiblePosicion;
    bool empate = false;
    unsigned menor = MOVIMIENTOS +1;
    for (size_t i = 0; i < MOVIMIENTOS; i++)
    {
        if (evaluarMovimiento(obtenerPosicionActual() + movimiento[i]))
        {
            posiblePosicion.push_back(posicionActual + movimiento[i]);
        }   
    }//Fin de ciclo for
    for (auto &i : posiblePosicion)
    {
       
        if (tablero.obtenerAccesibilidad(i) < menor)
        {
            menor = tablero.obtenerAccesibilidad(i);
            posicionActual = i;
            empate = false;
        }
        else if (tablero.obtenerAccesibilidad(i) == menor)
        {
            empate = true;
        }
    }

    if (empate)
    {
        unsigned nuevoMenor = MOVIMIENTOS + 1;
        for (auto &i : posiblePosicion)
        {
            if (tablero.obtenerAccesibilidad(i) == menor)
                if(evaluarProximoMovimiento(i) < nuevoMenor)
                {
                    nuevoMenor = evaluarProximoMovimiento(i);
                    posicionActual = i;
                }
        }
        
    }

    if (posiblePosicion.size()>0)
    {
        movimientos++;
        tablero.establecerCasilla(obtenerPosicionActual(),movimientos);
        return true;
    }
    
    return false;
}//Fin funcion moverCaballo

//Funcion que evalua el proximo movimiento y devuelve la accesibilidad del movimiento posible más bajo
int Caballo::evaluarProximoMovimiento(const Coordenadas &r) const
{
    int menor = MOVIMIENTOS + 1;
    for (size_t i = 0; i < MOVIMIENTOS; i++)
    {
        if(evaluarMovimiento(r + movimiento[i]) && tablero.obtenerAccesibilidad(r + movimiento[i]) < menor)
            menor = tablero.obtenerAccesibilidad(r + movimiento[i]);
    }
    return menor;
}

//Funcion que evalua si es posible realizar el movimiento
bool Caballo::evaluarMovimiento(Coordenadas prueba) const
{
    //Coordenadas prueba = {(obtenerPosicionActual() + movimiento[indice])};
    //cout << prueba.obtenerX() << ", " << prueba.obtenerY() << endl;
    if (prueba >= Coordenadas(0, 0) && prueba < Coordenadas(MOVIMIENTOS, MOVIMIENTOS) && tablero.obtenerCasilla(prueba) == 0)
    {
        return true;
    }
    else
        return false;
}//Fin de funcion evaluarMovimiento

// Función que devuelve los movimientos dados por el caballo
int Caballo::obtenerMovimientos() const
{
    return movimientos;
}

// Función que mueve el caballo a una casilla del tablero utilizando generación de números aleartorios.
bool Caballo::moverAleartoriamente()
{
    unsigned indice = aleartorio(motor); // Variable que guarda el número generado aleartoriamente.
    array<unsigned, MOVIMIENTOS> conteoPosiblesMovimientos{0}; // lista en el que se lleva el conteo de cada movimiento realizado
    // Aumenta en uno la cantidad de veces que se a realizado el movimiento.
    conteoPosiblesMovimientos[indice]++;
    while (buscarEnArreglo(conteoPosiblesMovimientos, 0))
    {
        // Se evalúa si es movimiento es válido.
        if (evaluarMovimiento(obtenerPosicionActual() + movimiento[indice]))
        {
            posicionActual += movimiento[indice];
            movimientos++;
            tablero.establecerCasilla(obtenerPosicionActual(), movimientos);
            return true;
        }
        indice = aleartorio(motor);
        conteoPosiblesMovimientos[indice]++;
    }
    
    return false;
}


// Busca en el arreglo suministrado como primer parámetro el valor suministrado como segundo parámetro
bool buscarEnArreglo(const array<unsigned, MOVIMIENTOS> &arreglo, unsigned valor)
{
    for (auto &i : arreglo) //Para cada elemento en el arreglo
    {
        if(i == valor)
            return true;
    }

    return false;
    
}
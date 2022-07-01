#include "tablero.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Constructor predeterminado de la clase tablero
Tablero::Tablero()

{
    tabla = {0};
    accesibilidad = {
        2, 3, 4, 4, 4, 4, 3, 2,
        3, 4, 6, 6, 6, 6, 4, 3,
        4, 6, 8, 8, 8, 8, 6, 4,
        4, 6, 8, 8, 8, 8, 6, 4,
        4, 6, 8, 8, 8, 8, 6, 4,
        4, 6, 8, 8, 8, 8, 6, 4,
        3, 4, 6, 6, 6, 6, 4, 3,
        2, 3, 4, 4, 4, 4, 3, 2
    };
}//fin constructor predeterminado

//Destructor de la clase tablero
Tablero::~Tablero()
{
}

//Funcion que devuelve las dimensiones del tablero
int Tablero::obtenerDimensiones()const 
{
    return dimensiones;
}//fin de funcion obtenerDimensiones

//Funcion que muestra el tablero en pantalla
void Tablero::mostrarTablero() const
{
    for (size_t i = obtenerDimensiones(); i > 0 ; i--)
    //for (size_t i = 0; i < obtenerDimensiones(); i++)
    {
        for (size_t j = 0; j < obtenerDimensiones(); j++)
        {
            cout<< setw(2) << tabla[i-1][j] << "  ";
        }//Fin de ciclo for interno
        cout << endl;
        cout << endl;
    } //Fin de ciclo for externo
    cout << endl;
}//Fin de funcion mostrar tablero

//Funcion que muestra el heuristica en pantalla
void Tablero::mostrarHeuristica() const
{
    for (size_t i = obtenerDimensiones(); i > 0 ; i--)
    //for (size_t i = 0; i < obtenerDimensiones(); i++)
    {
        for (size_t j = 0; j < obtenerDimensiones(); j++)
        {
            cout<< setw(2) << accesibilidad[i-1][j] << "  ";
        }//Fin de ciclo for interno
        cout << endl;
        cout << endl;
    } //Fin de ciclo for externo
    cout << endl;
}//Fin de funcion mostrar Heuristica

//Funcion que establece el valor almacenado en una casilla
void Tablero::establecerCasilla(const Coordenadas posicion, int movimiento)
{
    tabla[posicion.obtenerY()][posicion.obtenerX()] = movimiento;
}//Fin de funcion establecerCasilla

//Funcion que obtiene el valor almacenado en la casilla pasada como coordenada
int Tablero::obtenerCasilla(Coordenadas posicion) const 
{
    return tabla[posicion.obtenerY()][posicion.obtenerX()];
}//Fin funcion obtenerCasilla


//Funcion que obtiene el valor almacenado en una casilla a partir de sus x y y
int Tablero::obtenerCasilla(const int x, const int y) const
{
    return tabla[y][x];
}//Fin funcion obtenerCasilla

// Función que la accesibilidad de una posición dada cómo parámetro
int Tablero::obtenerAccesibilidad(Coordenadas posicion) const 
{
    return accesibilidad[posicion.obtenerY()][posicion.obtenerX()];
}//Fin funcion obtenerCasilla
#include "Tablero.h"
#include "Reina.h"
#include <iostream>
using namespace std;

// Constructor de la clase.
Tablero::Tablero()
:contadorReinas(0), sinOpciones(false)
{
    establecerCasillas();
}

// Destructor de la clase.
Tablero::~Tablero()
{
}

// Muestra el tablero en pantalla.
void Tablero::mostrarTablero() const
{
    //const Tablero *pt = this;
    const Reina reina(this);
    for (size_t j = DIMENSIONES; j > 0; j--)
    {
        for (size_t i = 1; i <= DIMENSIONES; i++)
        {
            /* if (casilla[j][i].obtenerEstado() == 0 )
            {
                cout << "0 ";
            }
            else if(casilla[j][i].obtenerEstado() == 1)
            {
                cout << "x ";
            }
            else
            {
                cout << "R ";
            } */
            cout << reina.puntosAlEliminar(Coordenadas(i,j)) << " ";
            
        }
        cout << endl;
    }
    cout << endl;
}

// Obtiene la direccion de la casilla solicitada
const Casilla & Tablero::obtenerCasilla(Coordenadas posicion) const
{
    return casilla[posicion.obtenerY()][posicion.obtenerX()]; 
}

// Establece las casillas del tablero a 0.
void Tablero::establecerCasillas()
{
    Reina reina(this);
    for (size_t j = 1; j <= DIMENSIONES; j++)
    {
        for (size_t i = 1; i <= DIMENSIONES; i++)
        {
            casilla[j][i].establecerEliminaciones(reina.casillasEliminadas(Coordenadas(i, j)));
        }
    
    }
    
}

// Establece el total de reinas en el tablero.
void Tablero::establecerReinasTotales(unsigned reinas) 
{
    if (reinas >= 0)
    {
        contadorReinas = reinas;
    }
    else
    {
        throw invalid_argument("Argumento inválido. La reina debe ser mayor o igual a 0.");
    }
    
    
}

// Obtiene el total de reinas en el tablero
unsigned Tablero::obtenerReinasTotales() const
{
    return contadorReinas;
}

//evalua si la casilla suministrada como argumento está disponible.
//devuelve true si lo está y false si no lo está.
bool Tablero::evaluarCasilla(Coordenadas posicion) const
{
    if (casilla[posicion.obtenerY()][posicion.obtenerX()].obtenerEstado() == (unsigned)PosibleEstado::VACIA)
    {
        return true;
    }
    
    return false;
}

// establece si quedan o no opciones para colocar la reina.
void Tablero::establecerSinOpciones(bool nuevoEstado)
{
    sinOpciones = nuevoEstado;
}

// obtiene si quedan o no opciones para colocar la reina.
bool Tablero::obtenerSinOpciones() const
{
    return sinOpciones;
}

//busca la casilla que al colocar una reina elimine la menor cantidad de casillas posibles.
void Tablero::buscarMenor(vector<Coordenadas> * candidato)
{
    unsigned menor = DIMENSIONES * DIMENSIONES;
    candidato->clear();
    for (size_t j = 1; j <= DIMENSIONES; j++)
    {
        for (size_t i = 1; i <= DIMENSIONES; i++)
        {
            if (evaluarCasilla(Coordenadas(i, j)))
            {
                if (obtenerCasilla(Coordenadas(i, j)).obtenerEliminaciones() < menor)
                {
                    candidato->clear();
                    candidato->push_back(Coordenadas(i, j));
                    menor = obtenerCasilla(Coordenadas(i, j)).obtenerEliminaciones();
                }
                else if (obtenerCasilla(Coordenadas(i, j)).obtenerEliminaciones() == menor)
                {
                    candidato->push_back(Coordenadas(i, j));
                }
                
            }
            
        }
        
    }
    
}

//Coloca la reina en la mejor posición posible.
void Tablero::colocarReina()
{
    Reina reina(this);
    vector<Coordenadas> posibleCandidato;
    buscarMenor(&posibleCandidato);
    //cout << posibleCandidato.size() << endl;

    /* for (auto &i : posibleCandidato)
    {
        cout << i.obtenerX() << ", "
             << i.obtenerY() << endl;
    } */
    

    if (posibleCandidato.size() > 1)
    {
        evaluarPosiblesCandidatos(&posibleCandidato);
    }
    if (posibleCandidato.size() == 1)
    {
        reina.eliminarCasillas(posibleCandidato[0]);
        /* cout << posibleCandidato[0].obtenerX() << ", "
             << posibleCandidato[0].obtenerY() << endl; */
        //establecerCasilla(posibleCandidato[0], PosibleEstado::REINA);
        establecerReinasTotales(obtenerReinasTotales() + 1);
    }
    else
    {
        establecerSinOpciones(true);
    }
    
}

// Evalúa los posibles candidatos para determinar cual es más indicado
// El que tenga mayor número de eliminaciones.
void Tablero::evaluarPosiblesCandidatos(vector<Coordenadas> *candidato)
{
    Reina reina(this);
    unsigned puntosTotales = 0;
    Coordenadas nuevoCandidato;
    unsigned mayor = 0;
    // cout << "candidatos " << endl;
    for (auto &i : *candidato)
    {
        puntosTotales = reina.puntosAlEliminar(i);
        if (puntosTotales > mayor)
        {
            mayor = puntosTotales;
            nuevoCandidato = i;
            /* cout << nuevoCandidato.obtenerX() << ", "
             << nuevoCandidato.obtenerY() << endl; */
        }
        
    }
    candidato->clear();
    candidato->push_back(nuevoCandidato);
}

// Establece la casilla suministrada como 1er parámetro al estado
// suministrado como 2do parámetro
void Tablero::establecerCasilla(Coordenadas posicion, PosibleEstado nuevoEstado)
{
    casilla[posicion.obtenerY()][posicion.obtenerX()].establecerEstado((unsigned)nuevoEstado);
}
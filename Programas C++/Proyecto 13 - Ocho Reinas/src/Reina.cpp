#include "Reina.h"
using namespace std;

//Constructor de la clase
Reina::Reina(Tablero * nuevoTablero)
:tablero(nuevoTablero)
{
}

Reina::Reina(const Tablero * nuevoTablero)
:tableroConst(nuevoTablero)
{
}

//Destructor de la clase
Reina::~Reina()
{
}

// devuelve la cantidad de casillas que puede eliminar una reina en una determinada posición.
unsigned Reina::casillasEliminadas(Coordenadas posicion) const
{
    unsigned x = posicion.obtenerX();
    unsigned y = posicion.obtenerY();
    unsigned total = DIMENSIONES * 2 - 1;

    // Diagonal derecha superior
    for (size_t i = x, j = y; i <= DIMENSIONES && j <= DIMENSIONES; i++, j++)
    {
        if (i != x && j != y)
        {
            total++;
        }
        
    }

    // Diagonal izquierda superior
    for (size_t i = x, j = y; i > 0 && j <= DIMENSIONES; i--, j++)
    {
        if (i != x && j != y)
        {
            total++;
        }
        
    }

    // Diagonal izquierda inferior
    for (size_t i = x, j = y; i > 0 && j > 0; i--, j--)
    {
        if (i != x && j != y)
        {
            total++;
        }
        
    }

    // Diagonal derecha inferior
    for (size_t i = x, j = y; i <= DIMENSIONES && j > 0; i++, j--)
    {
        if (i != x && j != y)
        {
            total++;
        }
        
    }
    
    return total;
}

// Elimina las casillas correspondientes del tablero al colocar a la reina en una posición determinada.
void Reina::eliminarCasillas(Coordenadas posicion)
{
    unsigned x = posicion.obtenerX();
    unsigned y = posicion.obtenerY();
    tablero->establecerCasilla(posicion,PosibleEstado::REINA);

    // Diagonal derecha superior
    for (size_t i = x, j = y; i <= DIMENSIONES && j <= DIMENSIONES; i++, j++)
    {
        if (i != x && j != y)
        {
            tablero->establecerCasilla(Coordenadas(i, j),PosibleEstado::ELIMINADA);
        }
        
    }

    // Diagonal izquierda superior
    for (size_t i = x, j = y; i > 0 && j <= DIMENSIONES; i--, j++)
    {
        if (i != x && j != y)
        {
            tablero->establecerCasilla(Coordenadas(i, j),PosibleEstado::ELIMINADA);
        }
        
    }

    // Diagonal izquierda inferior
    for (size_t i = x, j = y; i > 0 && j > 0; i--, j--)
    {
        if (i != x && j != y)
        {
            tablero->establecerCasilla(Coordenadas(i, j),PosibleEstado::ELIMINADA);
        }
        
    }

    // Diagonal derecha inferior
    for (size_t i = x, j = y; i <= DIMENSIONES && j > 0; i++, j--)
    {
        if (i != x && j != y)
        {
            tablero->establecerCasilla(Coordenadas(i, j),PosibleEstado::ELIMINADA);
        }
        
    }
    
    // Horizontal
    for (size_t i = 1; i <= DIMENSIONES; i++)
    {
        if (i != x)
        {
            tablero->establecerCasilla(Coordenadas(i, y),PosibleEstado::ELIMINADA);
        }
    }
    
    // Vertical
    for (size_t i = 1; i <= DIMENSIONES; i++)
    {
        if (i != y)
        {
            tablero->establecerCasilla(Coordenadas(x, i),PosibleEstado::ELIMINADA);
        }
    }
    
}

//
unsigned Reina::puntosAlEliminar(Coordenadas posicion) const
{
    unsigned x = posicion.obtenerX();
    unsigned y = posicion.obtenerY();
    unsigned total = tableroConst->obtenerCasilla(posicion).obtenerEliminaciones();

    // Diagonal derecha superior
    for (size_t i = x, j = y; i <= DIMENSIONES && j <= DIMENSIONES; i++, j++)
    {
        if (i != x && j != y)
        {
            total += tableroConst->obtenerCasilla(Coordenadas(i, j)).obtenerEliminaciones();
        }
        
    }

    // Diagonal izquierda superior
    for (size_t i = x, j = y; i > 0 && j <= DIMENSIONES; i--, j++)
    {
        if (i != x && j != y)
        {
            total += tableroConst->obtenerCasilla(Coordenadas(i, j)).obtenerEliminaciones();
        }
        
    }

    // Diagonal izquierda inferior
    for (size_t i = x, j = y; i > 0 && j > 0; i--, j--)
    {
        if (i != x && j != y)
        {
            total += tableroConst->obtenerCasilla(Coordenadas(i, j)).obtenerEliminaciones();
        }
        
    }

    // Diagonal derecha inferior
    for (size_t i = x, j = y; i <= DIMENSIONES && j > 0; i++, j--)
    {
        if (i != x && j != y)
        {
            total += tableroConst->obtenerCasilla(Coordenadas(i, j)).obtenerEliminaciones();
        }
        
    }
    
    // Horizontal
    for (size_t i = 1; i <= DIMENSIONES; i++)
    {
        if (i != x)
        {
            total += tableroConst->obtenerCasilla(Coordenadas(i, y)).obtenerEliminaciones();
        }
    }
    
    // Vertical
    for (size_t i = 1; i <= DIMENSIONES; i++)
    {
        if (i != y)
        {
            total += tableroConst->obtenerCasilla(Coordenadas(x, i)).obtenerEliminaciones();
        }
    }

    return total;
}
#if !defined(REINA_H)
#define REINA_H
#include "Tablero.h"
#include "coordenadas.h"
class Reina
{
private:
    Tablero *tablero; // Tablero en el que se efectuarán los movimientos de la reina
    const Tablero *tableroConst;
public:
    Reina(Tablero * nuevoTablero); // Constructor de la clase.
    Reina(const Tablero * nuevoTablero); // Constructor de la clase.
    ~Reina(); // Destructor de la clase.
    unsigned casillasEliminadas(Coordenadas posicion) const; // Devuelve la cantidad de casillas del 
    // tablero que puede eliminar la reina al situarla en la casilla pasada como parámetro.

    void eliminarCasillas(Coordenadas posicion); // Elimina las casillas correspondientes 
    // al colocar la reina en una casilla suministrada como parámetro.

    unsigned puntosAlEliminar(Coordenadas posicion) const; // Devuelve el total de puntos que puede eliminar 
    // la reina al colocarla en la posición del tablero suministrada cómo parámetro.
};




#endif // REINA_H

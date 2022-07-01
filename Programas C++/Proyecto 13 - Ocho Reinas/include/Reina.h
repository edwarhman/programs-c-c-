#if !defined(REINA_H)
#define REINA_H
#include "Tablero.h"
#include "coordenadas.h"
class Reina
{
private:
    Tablero *tablero; // Tablero en el que se efectuar�n los movimientos de la reina
    const Tablero *tableroConst;
public:
    Reina(Tablero * nuevoTablero); // Constructor de la clase.
    Reina(const Tablero * nuevoTablero); // Constructor de la clase.
    ~Reina(); // Destructor de la clase.
    unsigned casillasEliminadas(Coordenadas posicion) const; // Devuelve la cantidad de casillas del 
    // tablero que puede eliminar la reina al situarla en la casilla pasada como par�metro.

    void eliminarCasillas(Coordenadas posicion); // Elimina las casillas correspondientes 
    // al colocar la reina en una casilla suministrada como par�metro.

    unsigned puntosAlEliminar(Coordenadas posicion) const; // Devuelve el total de puntos que puede eliminar 
    // la reina al colocarla en la posici�n del tablero suministrada c�mo par�metro.
};




#endif // REINA_H

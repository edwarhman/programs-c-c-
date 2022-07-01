#if !defined(TABLERO_H)
#define TABLERO_H
#include <array>
#include <vector>
#include "Casilla.h"
#include "coordenadas.h"
#define DIMENSIONES 8

// Posibles estados de una casilla 
enum class PosibleEstado {VACIA, ELIMINADA, REINA};

class Tablero
{
private:
    std::array<std::array< Casilla, DIMENSIONES + 1>, DIMENSIONES + 1> casilla; // vector bidimensional que representa el tablero
    unsigned contadorReinas; // Conteo de las reinas colocadas en el tablero.
    bool sinOpciones; // Indica si ya no se pueden colocar m�s piezas (true: no se puede, false: si se puede).
public:
    Tablero(); // Constructor de la clase
    ~Tablero(); // Destructor de la clase
    void mostrarTablero() const; // Funci�n que muestra el tablero en pantalla.
    const Casilla & obtenerCasilla(Coordenadas posicion) const; //obtiene la direcci�n de la casilla en la posici�n suministrada como par�metro.
    void establecerCasillas(); // establece todas las casillas a 0.
    void establecerReinasTotales(unsigned reinas); // establece el total de reinas.
    unsigned obtenerReinasTotales() const; // obtiene el total de reinas.
    bool evaluarCasilla(Coordenadas posicion) const; // eval�a si la casilla de la posici�n suministrada est� disponible.
    void establecerSinOpciones(bool estado); // establece el nuevo estado del tablero.
    bool obtenerSinOpciones() const; // obtiene el estado del tablero.
    void buscarMenor(std::vector<Coordenadas> * candidatos); // busca el menor.
    void colocarReina(); // coloca la reina
    void evaluarPosiblesCandidatos(std::vector<Coordenadas> *candidatos); //se evaluan los posibles candidatos si hay mas de uno al buscar menor.
    void establecerCasilla(Coordenadas posicion, PosibleEstado nuevoEstado); // establece la casilla de la posici�n suministrada como 1er par�metro 
                                                                            //con el estado suministrado como 2do par�metro
};

#endif // TABLERO_H

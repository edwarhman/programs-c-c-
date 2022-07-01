#if !defined(TABLERO_H)
#define TABLERO_H
#include <array>
#include "coordenadas.h"

class Tablero
{
private:
    const static int dimensiones = 8; //Dimensiones del tablero
    std::array<std::array<int, dimensiones >, dimensiones> tabla;  //Array bidimensional que almacena las casillas del tablero
    std::array<std::array<int, dimensiones >, dimensiones> accesibilidad;  //Array bidimensional que almacena las casillas del tablero
public:
    Tablero();  ///Constructor predeterminado
    ~Tablero();  //Destructor de la clase
    int obtenerDimensiones() const;   //Obtiene las dimensiones de la clase
    void mostrarTablero() const;  //Muestra el tablero en pantalla
    void establecerCasilla(const Coordenadas, int);   //establece el argumento como casilla del tablero
    int obtenerCasilla(Coordenadas) const;   //Obtiene la casilla de la posicion suministrada
    int obtenerCasilla(const int, const int) const;
    void mostrarHeuristica() const;
    int obtenerAccesibilidad(Coordenadas) const;
};

#endif // TABLERO_H

#if !defined(CABALLO_H)
#define CABALLO_H
#include "tablero.h"
#define MOVIMIENTOS 8
class Caballo
{
private:
    Coordenadas posicionActual;
    int movimientos;
    Tablero &tablero;
public:
    const std::array<Coordenadas, 8> movimiento = {{
        Coordenadas(2, 1), Coordenadas(1, 2), Coordenadas(-1, 2), Coordenadas(-2, 1),
        Coordenadas(-2, -1), Coordenadas(-1, -2), Coordenadas(1, -2), Coordenadas(2, -1)}};
		
    Caballo(Tablero &, Coordenadas);
    ~Caballo();
    bool moverCaballo();
    Coordenadas obtenerPosicionActual() const;
    int obtenerMovimientos() const;
    bool evaluarMovimiento(Coordenadas) const; 
    int evaluarProximoMovimiento(const Coordenadas &) const;
    bool moverAleartoriamente();

};

#endif // CABALLO_H

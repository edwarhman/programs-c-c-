#include "caballo.h"
using namespace std;


int main(int argc, char const *argv[])
{
    /* Caballo::movimiento = {
        Coordenadas(2, 1), Coordenadas(1, 2), Coordenadas(-1, 2), Coordenadas(-2, 1),
        Coordenadas(-2, -1), Coordenadas(-1, -2), Coordenadas(1, -2), Coordenadas(2, -1)
    }; */
    Tablero tabla;
    Caballo caballoPrueba(tabla,Coordenadas(3, 3));
    tabla.mostrarTablero();
    
    return 0;
}

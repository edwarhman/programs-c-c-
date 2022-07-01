#include <iostream>
#include "coordenadas.h"
#include "Tablero.h"
#include "Reina.h"
using namespace std;
int main(int argc, char const *argv[])
{
    Tablero miTablero;
    Reina miReina(&miTablero);
    //miReina.eliminarCasillas(Coordenadas(5, 5));
    //cout << miReina.puntosAlEliminar(Coordenadas(5, 5)) << endl;
    miTablero.mostrarTablero();

    /* cout << endl;
    cout << miTablero.obtenerReinasTotales() << endl;
    miTablero.colocarReina();
    miTablero.mostrarTablero();
    cout << miTablero.obtenerReinasTotales() << endl; */


    cout << "Se intenta llenar el tablero." << endl;
    while (!miTablero.obtenerSinOpciones())
    {
        miTablero.colocarReina();
        miTablero.mostrarTablero();
        //cout << endl;
    }
    cout << "Todo fue como la seda" << endl;
    miTablero.mostrarTablero(); 

    cout << miTablero.obtenerReinasTotales() << endl; 
    return 0;
}

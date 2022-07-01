#include <iostream>
#include <iomanip>
#include <locale.h>
#include <vector>
#include "caballo.h"
#include "tablero.h"
#define MOV_MAXIMOS 64
using namespace std;

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    Tablero *miTabla;
    Caballo *miCaballo;
    unsigned intentosCompletados = 0;

    for (size_t i = 0; i < MOVIMIENTOS; i++)
    {
        for (size_t j = 0; j < MOVIMIENTOS; j++)
        {
            miTabla = new Tablero;
            miCaballo = new Caballo(*miTabla, Coordenadas(i, j));
            cout << "Intento que empieza en la posición (" << i << ", " << j << ")." << endl;
            while (miCaballo->moverCaballo())
            {
            }
            miTabla->mostrarTablero();
            cout << "Se realizaron " << miCaballo->obtenerMovimientos() << " movimientos.\n" << endl;
            if(miCaballo->obtenerMovimientos() == MOV_MAXIMOS)
                intentosCompletados++;
            delete miTabla;
            delete miCaballo;
        }
        
    }
    cout << "Se completaron un total de " << intentosCompletados << " recorridos." << endl;
    
    //Modo aleartorio
    array<unsigned, 65> recorridos{0};
    cout << "Recorrido aleartorio." << endl;
    unsigned contador = 0;
    while(recorridos[64] == 0)
    {
        miTabla = new Tablero;
        miCaballo = new Caballo(*miTabla, Coordenadas(0, 0));

        while (miCaballo->moverAleartoriamente())
        {
        }
        cout << ++contador << " ";
        if(miCaballo->obtenerMovimientos() == 64)
            miTabla->mostrarTablero();
        recorridos[miCaballo->obtenerMovimientos()]++;
        delete miCaballo;
        delete miTabla;
    }

    cout << "movimientos\t" << setw(8) << "Cantidad de recorridos." << endl;
    for (size_t i = 1; i < recorridos.size(); i++)
    {
        cout << i << setw(12) << recorridos[i] << endl;
    }
    
    
    /* miTabla->mostrarTablero();
    cout << "Se realizaron " << miCaballo->obtenerMovimientos() << " movimientos.\n" << endl; */    
    return 0;
}

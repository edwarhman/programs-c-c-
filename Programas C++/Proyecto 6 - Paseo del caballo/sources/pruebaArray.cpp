#include <array>
#include <iostream>
#include <locale.h>
#include "coordenadas.h"
using namespace std;
void mostrarArreglo(const array<Coordenadas,8> &a);
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"");
    cout << "Hola niño ¿cómo estás tú? " << endl;
    array<Coordenadas,8> movimiento = {
	Coordenadas(4, 7),Coordenadas(7, 3),Coordenadas(4, 1),Coordenadas(2, 8),
	Coordenadas(6, 9),Coordenadas(2, 5),Coordenadas(1, 2),Coordenadas(5, 6)};
    cout << movimiento[0].obtenerX() << ", " << movimiento[0].obtenerY() << endl;
    cout << endl;
    mostrarArreglo(movimiento);
    return 0;
}

void mostrarArreglo(const array<Coordenadas,8> &a)
{
        for (auto &i : a)
        {
            cout << i.obtenerX() << ", " << i.obtenerY() << endl;
        }
        
    cout << endl;
}

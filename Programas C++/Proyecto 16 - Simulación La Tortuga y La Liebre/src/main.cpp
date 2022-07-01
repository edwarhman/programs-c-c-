#include <iostream>
#include <locale.h>
#include <windows.h>
#include "Competicion.h"
using namespace std;

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    Competicion carrera;
    cout << "Programa que simula una carrera entre una tortuga y una liebre."
            "\nPulse una tecla para empezar la carrera" << endl;
    system("pause");
    carrera.mostrar();
    carrera.comenzar();
    carrera.mostrarGanador();
    return 0;
}


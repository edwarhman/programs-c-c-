#include "Tiempo.h"
#include "Fecha.h"
#include <iostream>
#include <ctime>
#include <windows.h>
#include <locale.h>
#include "FechaHora.h"
using namespace std;


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    FechaHora miFecha(15, 23, 54, 18, 3, 1997);
    miFecha.imprimir();
    for (size_t i = 0; i < 100000; i++)
    {
        system("cls");
        miFecha.tictac();
        miFecha.imprimir();
    }
    return 0;
}


/* int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    // cout << "HOLA MUNDO" << endl;
    time_t tiempo = time(0);

    int hora = localtime(&tiempo)->tm_hour;
    cout << hora << endl;
    Tiempo miTiempo;
    miTiempo.imprimirUniversal();
    //cout << "pulse una tecla." ;
    //system("pause");
    miTiempo.establecerTiempo(6, 30, 12);
    miTiempo.establecerTiempo(time(0));
    miTiempo.imprimirUniversal();
    miTiempo.imprimirEstandar();
    for (size_t i = 0; i < 200; i++)
    {
        miTiempo.tictac();
    }
    
    miTiempo.imprimirUniversal();
    miTiempo.imprimirEstandar();
    //system("pause");
    
    // Cronómetro
    for (size_t i = 0; i < 610; i++)
    {
        system("cls");
        miTiempo.tictac();
        miTiempo.imprimirUniversal();
        miTiempo.imprimirEstandar();
        Sleep(400);
    }
    
    Fecha miFecha;
    miFecha.establecerFecha();

    for (size_t i = 0; i < 101; i++)
    {
        miFecha.siguienteDia();
        miFecha.imprimir();
    }
    

    return 0;
} */

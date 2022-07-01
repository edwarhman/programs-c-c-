#include <iostream>
#include <iomanip>
#include "Simpletron.h"
#include <locale.h>
#define BANDERA -99999
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    //DECLARACIÓN DE VARIABLES
    int memoria[100] = {0};
    int acumulador = 0;
    int contadorInstrucciones = 0;
    int codigoOperacion = 0;
    int operando = 0;
    int registroDeInstruccion = 0;
    long centinela = 0;

    cout << "*** Empieza la carga del programa ***\n";
    while (centinela != BANDERA)
    {
        cout << setw(2) << setfill('0') << contadorInstrucciones << setfill('\0') << " ";
        lee(contadorInstrucciones, memoria, &centinela);
        contadorInstrucciones++;
    }

    cout << "*** Se completó la carga del programa ***" << endl;
    cout << endl << "*** Empieza la ejecución del programa ***\n";

    centinela = contadorInstrucciones;
    contadorInstrucciones = 0;

    while (codigoOperacion != (int)Operaciones::ALTO)
    {
        cout << setw(2) << setfill('0') << contadorInstrucciones << setfill('\0') << " ";
        registroDeInstruccion = memoria[contadorInstrucciones];
        obtenerCodigoyOperando(&codigoOperacion, &operando, registroDeInstruccion);
        realizarInstruccion(codigoOperacion, operando, memoria, &acumulador, &contadorInstrucciones, registroDeInstruccion);
        contadorInstrucciones++;
    }
    
    //alto(acumulador, contadorInstrucciones, registroDeInstruccion, codigoOperacion, operando, memoria);
    return 0;
}


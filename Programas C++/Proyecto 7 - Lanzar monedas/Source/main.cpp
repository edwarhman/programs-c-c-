#include "Monedas.h"
#include <iostream>
using namespace std;

void mostrarResultados(unsigned int cruz, unsigned int cara);
int main(int argc, char const *argv[])
{
    unsigned int contadorCruz = 0, contadorCara = 0;
    unsigned int lado = 0;
    Monedas moneda;
    for (size_t i = 0; i < 100; i++)
    {

        lado = moneda.tirarMoneda();
        if (lado)
            contadorCruz++;
        else 
            contadorCara++;
    }
    
    mostrarResultados(contadorCruz,contadorCara);

    return 0;
}

void mostrarResultados(unsigned int cruz, unsigned int cara)
{
    cout << "\nHubo un total de " << cruz << " cruces.\n"
            "Hubo un total de " << cara << "caras. " << endl;
}
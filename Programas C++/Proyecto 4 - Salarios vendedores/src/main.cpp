#include "Salarios.h"
#include <iostream>
#include <iomanip>
#include <locale.h>
using namespace std;

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    cout << "Hola" << endl;
    array<int,10> arreglo;
    cout << arreglo.size() << endl;
    Salarios salarioJun;
    salarioJun.agregarVendedor();
    salarioJun.calcularSalarios();
    salarioJun.clasificarVendedores();
    salarioJun.mostrarClasificacionVendedores();
    return 0;
}

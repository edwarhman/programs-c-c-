#include <locale.h>
#include <iostream>
#include "MisFunciones.h"
#include "EnteroEnorme.h"
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    EnteroEnorme miEntero;
    miEntero.recibir();
    miEntero.imprimir();
    return 0;
}


#include "Rectangulo.h"
#include <iostream>
#include <locale.h>
using namespace std;
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    Rectangulo miRectangulo(3.0, 4.0);
    miRectangulo.imprimir();

    cout << "Hola mundo" << endl;
    cout << '\a';
    cout << "¿Cómo estás?" << endl;
    return 0;
}

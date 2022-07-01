#include "Rectangulo.h"
#include <iostream>
#include <locale.h>
using namespace std;
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    Rectangulo miRectangulo1;
    array<array<float, COORDENADAS>, VERTICES> misVertices;

    try
    {
        //Rectangulo::leerEntrada(&misVertices);
        miRectangulo1.establecerRectangulo();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        //Rectangulo::leerEntrada(&misVertices);
        miRectangulo1.establecerRectangulo();
    }
    
    miRectangulo1.imprimir();
    miRectangulo1.establecerCaracterRelleno();
    miRectangulo1.dibujar();
    return 0;
}

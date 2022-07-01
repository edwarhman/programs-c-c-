#include <iostream>
#include "LibroCalificaciones.h"

using namespace std;

int main()
{
    LibroCalificaciones libro1("Introduccion a C++");
    LibroCalificaciones libro2("Estructuras de datos con C++");

    cout << "Libro 1 creado para el curso " << libro1.obtenerNombreCurso() << "\nLibro 2 creado para el curso " << libro2.obtenerNombreCurso() << endl;
    return 0;
}

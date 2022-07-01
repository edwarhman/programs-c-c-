#include <iostream>
#include "LibroCalificaciones.h"
#include <locale.h>
#include <wchar.h>

using namespace std;

int main(int argc, char const *argv[])
{
    array<array<int,CAN_PRUEBAS>,CAN_ESTUDIANTES> calificaciones = {15, 2, 3, 9, 8, 84};
    setlocale(LC_ALL, "");
    //Inicialización de variables
    LibroCalificaciones libro1("Introduccion a la programacion en C", "Emerson Warhman",calificaciones); //contiene los datos de la clase 1
    LibroCalificaciones libro2("Estructuras de datos en C++", "David Cardona",calificaciones); //contiene los datos de la clase 2
    string entrada; // contiene los datos de entrada que seran utilizados para almacenar los nombres de los instructores

    //Presentación del programa
    cout << "Libro 1 creado para el curso: " << libro1.obtenerNombreCurso() << "\nDictado por "
         << libro1.obtenerNombreInstructor() << "\nLibro 2 creado para el curso: " << libro2.obtenerNombreCurso()
         << "\nDictado por " << libro2.obtenerNombreInstructor() << endl;

    //Solicitar y almacenar el nombre del instructor de la clase
    cout << "\nIngrese el nombre del instructor de la clase 1: ";
    getline(cin, entrada);
    libro1.establecerNombreInstructor(entrada);

    //Muestra Los datos generales de la clase
    libro1.mostrarMensaje();

    //Recibe las calificaciones de la clase hasta que se ingrese el valor fin de archivo.
    libro1.recibirCalificaciones();

    //Muestra las calificaciones de la clase
    libro1.mostrarReporteCalificaciones();
    return 0;
}

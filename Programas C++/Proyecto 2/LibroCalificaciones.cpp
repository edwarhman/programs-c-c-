#include <iostream>
#include <iomanip>
#include "LibroCalificaciones.h"

using namespace std;
//Constructor de la Clase LibroCalificaciones
LibroCalificaciones::LibroCalificaciones(string nombreC, string nombreI, std::array<std::array<int,CAN_PRUEBAS>,CAN_ESTUDIANTES> &arregloCalificaciones)
    : nombreCurso(nombreC), //Inicializa nombre curso
      nombreInstructor(nombreI), //Inicializa nombre instructor
      aCuenta(0),
      bCuenta(0),
      cCuenta(0),
      dCuenta(0),
      fCuenta(0),
      calificaciones(arregloCalificaciones)
{

}//fin del constructor

//Funci�n que establece el nombre del curso
void LibroCalificaciones::establecerNombreCurso(string nombre)
{
    if (nombre.size() <= 25)
    {
        nombreCurso = nombre;
    }
    else
    {
        nombreCurso = nombre.substr(0, 25);
        cerr << "El nombre " << nombre
             << " excede la longitud m�xima (25)\n"
             << "se limit� nombreCurso a los primeros 25 caracteres.\n";
    }
        
} // fin de funci�n establecerNombreCurso

//funcion que obtiene el nombre del curso
string LibroCalificaciones::obtenerNombreCurso() const
{
    return nombreCurso;
} //fin de funcion obtenerNombreCurso

//funcion que muestra un mensaje de bienvenida al usuario del curso
void LibroCalificaciones::mostrarMensaje() const
{
    cout << "Bienvenido al libro de calificaciones para\n"
         << obtenerNombreCurso() << "\ndictado por " 
         << obtenerNombreInstructor() << endl;
} //Fin de funci�n mostrarMensaje

//funcion que establece el nombre del instructor del curso
void LibroCalificaciones::establecerNombreInstructor(string nombre)
{
    nombreInstructor = nombre;
} //fin funcion establecerNombreInstructor

//funcion que obtiene el nombre del instructor
string LibroCalificaciones::obtenerNombreInstructor() const
{
    return nombreInstructor;
} //fin funcion obtenerNombreInstructor

//Funcion que recibe un numero albitrario de calificaciones del usuario;
//actualiza el controlador de calificaciones
void LibroCalificaciones::recibirCalificaciones()
{
    char calificacion = ' ';

    cout << "escriba las calificaciones de letra."
         << "escriba el caracter EOF para terminar la entrada. "
         << endl;
    //itera la entrada de datos hasta que se escriba la secuencia
    //fin de archivo EOF
    while ((calificacion = cin.get()) != EOF)
    {
    	cout << calificacion << endl;
        // determina cual calificacion se introdujo
        switch (calificacion)
        {
        case 'a': case 'A':
            ++aCuenta;
            break;
        case 'b': case 'B':
            ++bCuenta;
            break;
        case 'c': case 'C':
            ++cCuenta;
            break;
        case 'd': case 'D':
            ++dCuenta;
            break;
        case 'f': case 'F':
            ++fCuenta;
            break;
        case '\n': case '\t': case ' ': //ignora caracteres de nueva l�nea, tabulaci�n y espacios en blanco
        	break;
        
        default:
            cout << "Se introdujo una letra de calificacion incorrecta."
                 << " Escriba una nueva calificaci�n. " << endl;
            break;
        } //fin de switch
    } //fin de while
    
} //fin de la funci�n recibirCalificaciones

//Funcion que muestra un reporte de las calificaciones
void LibroCalificaciones::mostrarReporteCalificaciones() const
{
    // imprime un resumen del resultado
    cout << "\n\nNumero de estudiantes que recibieron cada calificaci�n de letra:"
         << "\nA:" << aCuenta //Muestra el n�mero de calificaciones de A
         << "\nB:" << bCuenta //Muestra el n�mero de calificaciones de B
         << "\nC:" << cCuenta //Muestra el n�mero de calificaciones de C
         << "\nD:" << dCuenta //Muestra el n�mero de calificaciones de D
         << "\nF:" << fCuenta //Muestra el n�mero de calificaciones de F
         << endl;
}

void LibroCalificaciones::procesarCalificaciones() const
{
    //Imprimir arreglo calificaciones
    imprimirCalificaciones();

    //Calcula el promedio entre las calificaciones
    cout << setprecision(2) << fixed;

    //Muestra la calificacion minima y la maxima
    cout << "La calificaci�n m�s baja es " << obtenerMinimo()
         << "\nLa calificaci�n m�s alta es " <<obtenerMaximo()
         << endl;

    //Imprime el grafico de distribuci�n de las calificaciones
    imprimirGraficoBarras();
} //Fin de la funci�n procesarCalificaciones

//Buscar la calificacion m�nima
int LibroCalificaciones::obtenerMinimo() const
{
    int calificacionInf = 100;
    for (auto &estudiante : calificaciones)
    {

        for (auto &calificacion : estudiante)
        {
            if (calificacion < calificacionInf)
            {
                calificacionInf = calificacion;
            }
        }
    }
    
    return calificacionInf;
}

//Buscar la calificacion m�xima
int LibroCalificaciones::obtenerMaximo() const
{
    int calificacionMax = 0;
    for (auto &estudiante : calificaciones)
    {
        for (auto &calificacion : estudiante)
        {
            if (calificacion > calificacionMax)
            {
                calificacionMax = calificacion;
            }
        }

    }
    
    return calificacionMax;
}

//Obtener promedio de las calificaciones
double LibroCalificaciones::obtenerPromedio(const array<int, CAN_PRUEBAS> &conjuntoDeCalificaciones) const
{
    int total = 0;
    for (int calificacion : conjuntoDeCalificaciones)
    {
        total += calificacion;
    }
    
    return static_cast<double>(total) / calificaciones.size();
}

//Imprime grafico de barras
void LibroCalificaciones::imprimirGraficoBarras() const
{
    cout << "\nDistribuci�n de calificaciones:" <<endl;
    //tama�o del array frecuencia
    const size_t sizeFrecuencia = 11;
    //Almacena la frecuencia de calificaciones en cada rango de 10 punto
    array<unsigned int, sizeFrecuencia> frecuencia = {};
    //para cada calificaci�n, incrementa la frecuencia adecuada
    for (auto const &estudiante : calificaciones)
    {
        for (auto const &calificacion : estudiante)
        {
            ++frecuencia[calificacion / 10];
        } //Fin ciclo for 1

    }
    
    //Para cada frecuencia de calificaci�n, imprime barra en el gr�fico
    for (size_t cuenta = 0; cuenta < sizeFrecuencia; cuenta++)
    {
        //Imprime etiquetas de las barras ("0-9:", ..., "90-99:", "100;")
        if(0==cuenta)
            cout << "0-9:";
        else if (sizeFrecuencia-1==cuenta)
            cout << "100:";
        else 
            cout << cuenta*10 << "-" <<cuenta*10 +1 << ":";
        for (int estrellas = 0; estrellas < frecuencia[cuenta]; estrellas++)
        {
            cout << "*";
        }//Fin de for 2
        cout << endl; //Empieza una nueva linea de salida
    }//Fin de for 1
}//Fin de la funcion imprimirGraficos

//Imprimir el contenido del arreglo calificaciones
void LibroCalificaciones::imprimirCalificaciones() const
{
    cout << "\nLas calificaciones son:\n\n";
    //Imprime un encabezado de columnas para cada una de las pruebas
    cout << "         "; //Alinea los encabezados de las columnas
    for (size_t prueba = 0; prueba < CAN_PRUEBAS; prueba++)
    {
        cout << "Prueba " << prueba + 1 << " "; 
    }
    cout << "Promedio" << endl;
    //imprime las calificaciones de cada estudiante
    for (size_t estudiante = 0; estudiante < calificaciones.size(); estudiante++)
    {
        cout << "Estudiante " << setw(2) << estudiante + 1;
        //imprime las calificaciones del estudiante
        for (size_t prueba = 0; prueba < calificaciones[estudiante].size(); prueba++)
        {
            cout << setw(8) << calificaciones[estudiante][prueba];
        }
        //Llamada de la funcion promedio para calcular el promedio del estudiante.
        //Pasa la fila de calificaciones como argumento
        double promedio = obtenerPromedio(calificaciones[estudiante]);
        cout << setw(9) << setprecision(2) << fixed << promedio << endl;
    } //Fin ciclo for 1
} //Fin funcion imprimirCalificaciones
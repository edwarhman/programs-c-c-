#include "SinDuplicados.h"
#include <iostream>
using namespace std;

// Constructor de la clase.
SinDuplicados::SinDuplicados(/* args */)
{
    for (auto &i : arreglo)
    {
        i = 0;
    }
    
}

// Destructor de la clase.
SinDuplicados::~SinDuplicados()
{
}



// Función que lee la entrada del usuario para almacenarla en el arreglo.
void SinDuplicados::leerEntrada()
{
    unsigned entrada = 0; // Variable que almacena la entrada sin validar del usuario.
    cin >> entrada; // Se lee la entrada del usuario y se almacena.

    // Se evalua si la entrada del usuario cumple con los requisitos del programa.
    if (VAL_MIN <= entrada && VAL_MAX >= entrada) 
    // Si se cumplen los requisitos:
    {
        // Se busca la entrada del usuario en el arreglo.
        if (!buscarElemento(entrada))
        {
            // Si no se encuentra la entrada en el arreglo, se almacena esta en el primer espacio disponible del arreglo.
            establecerElemento(entrada); 
        }
        
    }
    else
    // Si no se cumplen los requisitos:
    {
        // Se muestra un mensaje de error.
        cout << "Entrada inválida. Tiene que ingresar un número entre " << VAL_MIN << " y " << VAL_MAX << ". " << endl;

        // Se vuelve a pedir el número.
        cout << "Por favor ingrese un número válido: ";
        leerEntrada();
    }
    
}

//Evalua si el argumento ya se encuentra en el arreglo.
bool SinDuplicados::buscarElemento(unsigned dato) const
{
    size_t i = 0; // contador utilizado para acceder a los elementos del arreglo.
    
    do  // Evalua el elemento del arreglo hasta que se encuentra el primer 0 o se llega al final del arreglo.
    {
        if (dato == arreglo[i]) 
        {
            return true; // Si el dato ya se encuentra en el arreglo devuelve true.
        }
        ++i;
    } while (i < ELEMENTOS && arreglo[i] != 0);

    // Si ninguno de los elementos coincide devuelve false.
    return false;
}

// Función que establece el elemento del arreglo
void SinDuplicados::establecerElemento(unsigned dato)
{
    size_t i = 0; // Contador utilizado para acceder a los elementos del arreglo.
    
    // Se incrementa i en 1 hasta que se encuetre un elemento distinto de 0 o se llegue al final del arreglo.
    while (i < ELEMENTOS && arreglo[i] != 0)
    {
        ++i;
    }
    //Se establece el primer elemento que contenga un 0 con el dato suministrado como argumento.
    if (i < ELEMENTOS)
    {
        arreglo[i] = dato;
    }
    
}

// Función que muestra los elementos del arreglo.
void SinDuplicados::mostrarElementos() const
{
    // Muestra cada elemento del arreglo que sea distinto de 0.
    for (size_t i = 0; i < ELEMENTOS && arreglo[i] != 0; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}
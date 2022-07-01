#include "SinDuplicados.h"
#include <iostream>
using namespace std;

// Constructor de la clase.
SinDuplicados::SinDuplicados(/* args */)
{   
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
    // Para cada elemento del vector se evalua si el dato coincide con el elemento..
    for (const auto &elemento : arreglo)
    {
        // de ser así se devuelve true.
        if(elemento == dato)
            return true;
    }

    // Si ninguno de los elementos coincide devuelve false.
    return false;
}

// Función que establece el argumento suministrado como un nuevo elemento del arreglo.
void SinDuplicados::establecerElemento(unsigned dato)
{
    arreglo.push_back(dato);
}

// Función que muestra los elementos del vector.
void SinDuplicados::mostrarElementos() const
{
    // Muestra cada elemento del vector.
    for (const &elemento : arreglo)
    {
        cout << elemento << " ";
    }
    
    cout << endl;
}
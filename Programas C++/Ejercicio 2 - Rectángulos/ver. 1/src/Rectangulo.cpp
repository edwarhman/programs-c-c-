#include "Rectangulo.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#define MAXIMO 20.0f
using namespace std;

Rectangulo::Rectangulo()
:longitud(1.0), altura(1.0)
{

}
Rectangulo::Rectangulo(float l = 1.0, float a = 1.0)
{
    establecerRectangulo(l, a);
}

Rectangulo::~Rectangulo()
{
}

// Funciones establecer

// establece la longitud y la altura del rectángulo.
// arg <l>: longitud, arg <a>: altura.
void Rectangulo::establecerRectangulo(float l, float a)
{
    try
    {
        establecerLongitud(l);
        establecerAltura(a);
    }
    catch (const invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }
}

// Establece la longitud y la altura del rectángulo. A partir de la entrada del usuario en la consola.
void Rectangulo::establecerRectangulo()
{
    float l = 0.0;
    float a = 0.0;
    cout << "Por favor ingrese la longitud seguida la altura y luego presione enter: ";
    cin >> l >> a;
    try
    {
        establecerLongitud(l);
        establecerAltura(a);
    }
    catch (const invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
        establecerRectangulo();
    }
}

// establece la longitud del rectangulo.
// arg<valor>: longitud.
void Rectangulo::establecerLongitud(float valor)
{
    if (valor > 0.0 && valor < MAXIMO)
    {
        longitud = valor;
    }
    else
    {
        throw invalid_argument("Argumento inválido. La longitud debe estar entre 0.0 y " + (int)MAXIMO);
    }
}

// establece la altura del rectangulo.
// arg<valor>: altura.
void Rectangulo::establecerAltura(float valor)
{
    if (valor > 0.0 && valor < MAXIMO)
    {
        altura = valor;
    }
    else
    {
        throw invalid_argument("Argumento inválido. La altura debe estar entre 0.0 y " + (int)MAXIMO);
    }
    
}
// Funciones obtener

float Rectangulo::obtenerLongitud() const
{
    return longitud;
}

float Rectangulo::obtenerAltura() const
{
    return altura;
}

// Cálculos

// obtiene el perímetro del rectángulo
float Rectangulo::perimetro() const
{
    return obtenerLongitud() * 2 + obtenerAltura() * 2;
}

// obtiene el área del rectángulo
float Rectangulo::area() const
{
    return obtenerLongitud() * obtenerAltura();
}

// Impresión
void Rectangulo::imprimir() const
{
    cout << fixed << setprecision(2);
    cout << "Longitud: " << obtenerLongitud() << '\n'
         << "Altura: " << obtenerAltura() << '\n'
         << "Perímetro: " << perimetro() << '\n'
         << "Área: " << area() << '\n';
}


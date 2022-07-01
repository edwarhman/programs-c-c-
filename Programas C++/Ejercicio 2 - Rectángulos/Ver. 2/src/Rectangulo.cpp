#include "Rectangulo.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <math.h>
#define LIMITE 100
#define MAXIMO 20.0f
using namespace std;

Rectangulo::Rectangulo()
:longitud(1.0), anchura(1.0)
{

}
Rectangulo::Rectangulo(float l = 1.0, float a = 1.0)
{
    establecerRectangulo(l, a);
}

Rectangulo::~Rectangulo()
{
}

void Rectangulo::leerEntrada(array<array <float, COORDENADAS>, VERTICES> *entrada)
{
    for (auto &i : *entrada)
    {
        cout << "Por favor ingrese las coordenadas x e y del vertice:";
        for (auto &j : i)
        {
            cin >> j;
        }
        
    }
    
}

// Funciones establecer

// establece la longitud y la altura del rectángulo.
// arg <l>: longitud, arg <a>: altura.
void Rectangulo::establecerRectangulo(float l, float a)
{
    try
    {
        establecerLongitud(l);
        establecerAnchura(a);
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
    array < array <float, COORDENADAS>, VERTICES> esquinas;
    float a = 0.0;
    static char eleccion = '\0';
    if (eleccion == '\0')
    {
        cout << "Por favor indique de que manera quiere ingresar los datos del Rectángulo.\n"
             << "Escriba V para obtener el rectángulo a partir de sus vertices.\n"
             << "Escriba D para ingresar el rectángulo utilizando sus dimensiones longitud y anchura.\n"
             << "Ingrese su opción: ";
        cin >> eleccion;
    }
    
    if (eleccion == 'd' || eleccion == 'D')
    {
            cout << "\nPor favor ingrese la longitud seguida la altura y luego presione enter: ";
        cin >> l >> a;
        try
        {
            establecerLongitud(l);
            establecerAnchura(a);
        }
        catch (const invalid_argument &e)
        {
            std::cerr << e.what() << "Se le volverán a solicitar los datos.\n";
            system("pause");
            establecerRectangulo();
        }
    }
    else if (eleccion == 'v' || eleccion == 'V')
    {
        try
        {
            cout << '\n';
            leerEntrada(&esquinas);
            establecerRectangulo(esquinas);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << "Se le volverán a solicitar los datos.\n";
            system("pause");
            establecerRectangulo();
        }
        
    }
    else
    {
        cout << "Entrada inválida. Por favor intente otra vez." << endl;
        eleccion = '\0';
        establecerRectangulo();
    }
    
    
    
}

void Rectangulo::establecerRectangulo(std::array<std::array<float, COORDENADAS>, VERTICES> entrada)
{
    vector<float> distancias;
    float nuevaDistancia = 0.0;
    bool valido = true;
    int contador = 0;
    for (auto &i : entrada)
    {
        nuevaDistancia = 0.0;
        for (auto &j : entrada)
        {
            if (sqrt(pow((i[0] - j[0]),2) + pow((i[1] - j[1]),2) ) > nuevaDistancia) 
            {
                nuevaDistancia = sqrt(pow((i[0] - j[0]),2) + pow((i[1] - j[1]),2));
            }
        }
        distancias.push_back(nuevaDistancia);
    }
    for (auto &i : distancias)
    {
        if (i != nuevaDistancia)
        {
            throw invalid_argument("argumentos inválidos. Los vertices ingresados no definen un rectángulo");
        }
        
    }
    vertices = entrada;

    establecerAyA();
    
}

void Rectangulo::establecerAyA() 
{
    float long1 = 0;
    float long2 = 0;
        for (auto &j : vertices)
        {
            if (vertices[0][0] == j[0] && vertices[0][1] != j[1])
            {
                long1 = fabs(vertices[0][1] - j[1]);
                cout << "(" << vertices[0][0] << ", " <<  vertices[0][1] << ") (" << j[0] << ", " << j[1] << ") " << long1 << endl;
            }

            if (vertices[0][1] == j[1] && vertices[0][0] != j[0])
            {
                long2 = fabs(vertices[0][0] - j[0]);
                cout << "(" << vertices[0][0] << ", " <<  vertices[0][1] << ") (" << j[0] << ", " << j[1] << ") " << long2 << endl;
            }
        }
    if (long1 > long2)
    {
        establecerLongitud(long1);
        establecerAnchura(long2);
    }
    else
    {
        establecerLongitud(long2);
        establecerAnchura(long1);
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
        throw invalid_argument("Argumento inválido. La longitud debe estar entre 0.0 y 20.0" + (int)MAXIMO);
    }
}

// establece la altura del rectangulo.
// arg<valor>: altura.
void Rectangulo::establecerAnchura(float valor)
{
    if (valor > 0.0 && valor < MAXIMO)
    {
        anchura = valor;
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

float Rectangulo::obtenerAnchura() const
{
    return anchura;
}

// Cálculos

// obtiene el perímetro del rectángulo
float Rectangulo::perimetro() const
{
    return obtenerLongitud() * 2 + obtenerAnchura() * 2;
}

// obtiene el área del rectángulo
float Rectangulo::area() const
{
    return obtenerLongitud() * obtenerAnchura();
}

// Impresión
void Rectangulo::imprimir() const
{
    cout << endl; 
    cout << fixed << setprecision(2);
    cout << "puntos: ";
    for (auto &i : vertices)
    {
        cout << "(" << i[0] << ", " << i[1] << ") ";
    }
    
    cout << "\nDimensiones\n"
         << "======================\n"
         << "Longitud: " << '\t' << setw(6) << obtenerLongitud() << '\n'
         << "Anchura: " << '\t' << setw(6) << obtenerAnchura() << '\n'
         << "Perímetro: " << '\t' << setw(6) << perimetro() << '\n'
         << "Área: " << "\t\t" << setw(6) << area() << '\n'
         << "======================\n";
    cout << '\n' << (cuadrado()? "El rectángulo es un cuadrado" : "") << '\n';

}

bool Rectangulo::cuadrado() const
{
    if (obtenerAnchura() == obtenerLongitud())
    {
        return true;
    }
    return false;
}

void Rectangulo::dibujar() const
{
    array<float, COORDENADAS> puntoMin{LIMITE, LIMITE};
    array<float, COORDENADAS> puntoMax{0, 0};
    for (auto &i : vertices)
    {
        if (i[0] < puntoMin[0] && i[1] < puntoMin[1])
        {
            puntoMin[0] = i[0];
            puntoMin[1] = i[1];   
        }
        if (i[0] > puntoMax[0] && i[1] > puntoMax[1])
        {
            puntoMax[0] = i[0];
            puntoMax[1] = i[1];   
        }
        
    }
    for (int j = LIMITE - 1; j >= 0; j--)
    {
        cout << setw(2) << j;
        for (size_t i = 0; i < LIMITE; i++)
        {
            if (j >= puntoMin[1] && j <= puntoMax[1] && i >= puntoMin[0] && i <= puntoMax[0])
            {
                cout << caracterRelleno() << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << '\n';
    }
}

void Rectangulo::establecerCaracterRelleno()
{
    char entrada;
    cout << "Por favor ingrese el carácter con el que se dibujará el rectángulo: ";
    try
    {
        cin >> entrada;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "Caracter inválido." << '\n';
        establecerCaracterRelleno();
    }
    caracter = entrada;

}

char Rectangulo::caracterRelleno() const
{
    return caracter;
}
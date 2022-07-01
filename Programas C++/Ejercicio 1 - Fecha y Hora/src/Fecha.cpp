#include "Fecha.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Fecha::Fecha(int dd, int mm, int aa)
{
    establecerFecha(dd, mm, aa);
}
Fecha::Fecha()
:dia(1), mes(1), anio(1901)
{
}

Fecha::~Fecha()
{
}

// Funciones establecer

void Fecha::establecerFecha(int d, int m, int a)
{
    establecerAnio(a);
    establecerMes(m);
    establecerDia(d);
}
void Fecha::establecerFecha()
{
    int d = 0, m = 0, a = 0;
    cout << "Ingrese la fecha separada por espacios (dd mm aaaa): ";
    cin >> d >> m >> a;
    try
    {
        establecerAnio(a);
        establecerMes(m);
        establecerDia(d);
    }
    catch(const invalid_argument &e)
    {
        
        std::cerr << "Ocurrio una exepción: " << e.what() << '\n';
        establecerFecha();
    }
    
}
void Fecha::establecerDia(int entrada)
{
    if (evaluarDia(entrada))
    {
        // cout << entrada << endl;
        dia = entrada;
    }
}

void Fecha::establecerMes(int entrada)
{
    if (entrada <= 12 && entrada >= 0)
    {
        mes = entrada;
    }
    else
    {
        throw invalid_argument("Argunmento inválido. El mes debe estar entre 1 y 12.");
    }   
}
void Fecha::establecerAnio(int entrada)
{
    if (entrada > 0 && entrada <10000)
    {
        anio = entrada;
    }
    else
    {
        throw invalid_argument("Argumento inválido. El año debe estar entre 1 y 9999.");
    }
    
    
}

// Funciones obtener

int Fecha::obtenerDia() const
{
    return dia;
}
int Fecha::obtenerMes() const
{
    return mes;
}
int Fecha::obtenerAnio() const
{
    return anio;
}

// Función imprimir
void Fecha::imprimir() const
{

    cout << setfill('0') << setw(2) << obtenerDia() << "/" << setw(2) << obtenerMes() << "/" << setw(4) << obtenerAnio() << "." << endl;
}

// Otras funciones

bool Fecha::evaluarDia(int entrada) const
{
    string mensaje;
    if (entrada <= 0)
    {
        throw invalid_argument("Argumento inválido. El día no puede ser menor o igual a 0.");
    }
    else
    {
        switch (obtenerMes())
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (entrada <= 31)
            {
                // cout << entrada << endl;
                return true;
            }
            else
            {
                throw invalid_argument("Argumento inválido. Los días de los meses 1, 3, 5, 7, 8, 10 y 12 no pueden ser mayores a 31.");
            }
            break;
        case 2:
            if (evaluarFebrero(entrada))
            {
                return true;
            }
            else
            {
                mensaje = "Argumento inválido. Un día de febrero de un año" + string(esBisiesto() ? " bisiesto no puede ser mayor a 29." : " no bisiesto no puede ser mayor a 28.");
                throw invalid_argument(mensaje);
            }
            break;
        default:
            if (entrada <= 30)
            {
                return true;
            }
            else
            {
                throw invalid_argument("Argumento inválido. Los días de los meses 4, 6, 9 y 11 no pueden ser mayores a 30.");
            }
            break;
        }
    }
    
}

bool Fecha::evaluarFebrero(int d) const
{
    if (esBisiesto())
    {
        if (d <= 29)
        {
            return true;
        }    
    }
    else
    {
        if (d < 29)
        {
            return true;
        }
    }
    return false;
}

bool Fecha::esBisiesto() const
{
    if (obtenerAnio() % 4 == 0)
    {
        if (obtenerAnio() % 100 == 0)
        {
            if (obtenerAnio() % 400 == 0)
            {
                return true;
            }
        }
        else
        {
            return true;
        }
    }
    return false;
}

void Fecha::siguienteDia() 
{
    int d = obtenerDia() + 1;
    int m = obtenerMes();
    int a = obtenerAnio();
    try
    {
        evaluarDia(d);
    }
    catch (const invalid_argument &e)
    {
        m++;
        d = 1;
        if (m >= 12)
        {
            a++;
            m = 1;
        }
    }
    establecerFecha(d, m, a);    
}
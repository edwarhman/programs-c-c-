#include "EmpleadoPorComision.h"
#include <stdexcept>
#include <iostream>
using namespace std;


//Constructor de la clase
EmpleadoPorComision::EmpleadoPorComision(const string &nombre, const string &apellido, const string &nss,
                                         double ventas, double comision)
:primerNombre(nombre), apellidoPaterno(apellido), numeroSeguroSocial(nss)
{
    establecerVentasBrutas(ventas);
    establecerTarifaComision(comision);
}

// Destructor de la clase
EmpleadoPorComision::~EmpleadoPorComision()
{
}

// Funcion que establece el primer nombre
void EmpleadoPorComision::establecerPrimerNombre(const string &nombre)
{
    primerNombre = nombre;
}

// Función que obtiene el primer nombre
string EmpleadoPorComision::obtenerPrimerNombre() const
{
    return primerNombre;
}

// Funcion que establece el apellido paterno
void EmpleadoPorComision::establecerApellidoPaterno(const string &apellido)
{
    apellidoPaterno = apellido;
}

// Función que obtiene el apellido paterno
string EmpleadoPorComision::obtenerApellidoPaterno() const
{
    return apellidoPaterno;
}
// Funcion que establece el seguro social
void EmpleadoPorComision::establecerNumeroSeguroSocial(const string &nss)
{
    numeroSeguroSocial = nss;
}

// Función que obtiene el seguro social
string EmpleadoPorComision::obtenerNumeroSeguroSocial() const
{
    return numeroSeguroSocial;
}

// Función que establece las ventas brutas
void EmpleadoPorComision::establecerVentasBrutas(double ventas)
{
    if (ventas >= 0.0)
    {
        ventasBrutas = ventas;
    }
    else
    {
        throw invalid_argument("Las ventas brutas deben ser mayor o igual a 0.0");
    }
    
}

// Función que obtiene las ventas brutas
double EmpleadoPorComision::obtenerVentasBrutas() const
{
    return ventasBrutas;
}

// Función que establece la tarifa por comisión
void EmpleadoPorComision::establecerTarifaComision(double comision)
{
    if (comision > 0.0)
    {
        tarifaComision = comision;
    }
    else
    {
        throw invalid_argument("La comision debe ser mayor a 0.0 y menor a 1.0");
    }
    
}

// Función que obtiene la tarifa por comisión
double EmpleadoPorComision::obtenertarifaComision() const
{
    return tarifaComision;
}

// Función que obtiene los ingresos
double EmpleadoPorComision::ingresos() const
{
    return obtenertarifaComision()*obtenerVentasBrutas();
}

// Función que imprime en pantalla los datos
void EmpleadoPorComision::imprimir() const
{
    cout << "Empleado: " << obtenerPrimerNombre() << " " << obtenerApellidoPaterno()
         << "\nNúmero de seguro social: " << obtenerNumeroSeguroSocial()
         << "\nVentas brutas: " << obtenerVentasBrutas()
         << "\nTarifa de comisión: " << obtenertarifaComision()
         << endl;
}


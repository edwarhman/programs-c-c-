#include "EmpleadoPorComision.h"
#include <iostream>
#include <stdexcept>
using namespace std;

EmpleadoPorComision::EmpleadoPorComision(const std::string & nombre, const std::string & apellido, const std::string & nss, double ventas, double comision)
:Empleado(nombre, apellido, nss)
{
    establecerVentasBrutas(ventas);
    establecerTarifaComision(comision);
}

void EmpleadoPorComision::establecerVentasBrutas(double ventas)
{
    if (ventas >= 0.0)
    {
        ventasBrutas = ventas;
    }
    else
    {
        throw invalid_argument("Las ventas brutas deben ser mayor o igual a 0.");
    }
}

double EmpleadoPorComision::obtenerVentasBrutas() const
{
    return ventasBrutas;
}

void EmpleadoPorComision::establecerTarifaComision(double comision)
{
    if (comision > 0)
    {
        tarifaComision = comision;
    }
    else
    {
        throw invalid_argument("La tarifa por comisión debe ser mayor a 0.");
    }
    
}

double EmpleadoPorComision::obtenerTarifaComision() const
{
    return tarifaComision;
}

double EmpleadoPorComision::ingresos() const
{
    return obtenerVentasBrutas() * obtenerTarifaComision();
}

void EmpleadoPorComision::imprimir() const
{
    cout << "Empleado por comisión: ";
    Empleado::imprimir();
    cout << "\nVentas brutas: " << obtenerVentasBrutas() 
         << "\nTarifa comisión: " << obtenerTarifaComision();
}


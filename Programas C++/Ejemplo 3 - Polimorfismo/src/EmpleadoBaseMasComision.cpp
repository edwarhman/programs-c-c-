#include "EmpleadoBaseMasComision.h"
#include <iostream>
#include <stdexcept>
using namespace std;

EmpleadoBaseMasComision::EmpleadoBaseMasComision(const std::string & nombre, const std::string & apellido, const std::string & nss, double ventas, double tarifa, double salario)
:EmpleadoPorComision(nombre, apellido, nss, ventas, tarifa)
{
    establecerSalarioBase(salario);
}

void EmpleadoBaseMasComision::establecerSalarioBase(double salario)
{
    if (salario > 0)
    {
        salarioBase = salario;
    }
    else
    {
        throw invalid_argument("El salario base debe ser mayor a 0.");
    }
}

double EmpleadoBaseMasComision::obtenerSalarioBase() const
{
    return salarioBase;
}

double EmpleadoBaseMasComision::ingresos() const
{
    return obtenerSalarioBase() + EmpleadoPorComision::ingresos();
}

void EmpleadoBaseMasComision::imprimir() const
{
    cout << "Con salario base ";
    EmpleadoPorComision::imprimir();
    cout << "\nSalario Base: " << obtenerSalarioBase();
}
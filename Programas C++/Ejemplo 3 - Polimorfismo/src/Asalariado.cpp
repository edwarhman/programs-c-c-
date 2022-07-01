#include "Asalariado.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Asalariado::Asalariado(const std::string & nombre, const std::string & apellido, const std::string & nss, double salario)
:Empleado(nombre, apellido, nss)
{
    establecerSalarioSemanal(salario);
}

void Asalariado::establecerSalarioSemanal(double salario)
{
    if (salario > 0)
    {
        salarioSemanal = salario;
    }
    else
    {
        throw invalid_argument("El salario semanal debe ser mayor a 0.");
    }     
}

double Asalariado::obtenerSalarioSemanal() const
{
    return salarioSemanal;
}

double Asalariado::ingresos() const
{
    return obtenerSalarioSemanal();
}

void Asalariado::imprimir() const
{
    cout << "Empleado asalariado: ";
    Empleado::imprimir();
    cout << "\nSalario : " << obtenerSalarioSemanal();
}
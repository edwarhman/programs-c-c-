#include "EmpleadoBaseMasComision.h"
#include <stdexcept>
#include <iostream>
using namespace std;

// Constructor de la clase
EmpleadoBaseMasComision::EmpleadoBaseMasComision(const std::string & nombre, const std::string & apellido, const std::string & nss, double ventas = 0.0, double comision = 0.0, double salario = 0.0)
:EmpleadoPorComision(nombre, apellido, nss, ventas, comision)
{
    establecerSalarioBase(salario);
}

// Destructor de la clase
EmpleadoBaseMasComision::~EmpleadoBaseMasComision()
{
}

// Funci�n que establece el salario base
void EmpleadoBaseMasComision::establecerSalarioBase(double salario)
{
    if (salario >= 0)
    {
        salarioBase = salario;
    }
    else
    {
        throw invalid_argument("El salario base debe ser mayor a 0.");
    }
    
}

// Funci�n que obtiene el salario base
double EmpleadoBaseMasComision::obtenerSalarioBase() const
{
    return salarioBase;
}

// Funci�n que obtiene los ingresos
double EmpleadoBaseMasComision::ingresos() const
{
    return EmpleadoPorComision::ingresos() + obtenerSalarioBase();
}

// Funci�n que imprime en pantalla los datos del empleado
void EmpleadoBaseMasComision::imprimir() const
{
    EmpleadoPorComision::imprimir();
    cout << "Salario base: " << obtenerSalarioBase() << endl;
}

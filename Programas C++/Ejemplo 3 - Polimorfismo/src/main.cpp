#include <iostream>
#include <iomanip>
#include <vector>
#include "Empleado.h"
#include "EmpleadoPorComision.h"
#include "Asalariado.h"
#include "EmpleadoBaseMasComision.h"
#include <locale.h>
using namespace std;

void sl(){ cout << endl;}
void imprimeDatos(const Empleado * const ptrE);
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    cout << fixed << setprecision(2);

    Asalariado asalariado("Emerson", "Warhman", "111-11-1111", 200);
    EmpleadoPorComision porComision("Nestor","Mendoza","222-22-2222", 1000, 0.12);
    EmpleadoBaseMasComision baseMasComision("Samuel","Adarmes","333-33-3333", 1000, 0.05, 50);

    asalariado.imprimir();
    cout << "\nObtuvo $" << asalariado.ingresos() << endl;
    porComision.imprimir();
    cout << "\nObtuvo $" << porComision.ingresos() << endl;
    baseMasComision.imprimir();
    cout << "\nObtuvo $" << baseMasComision.ingresos() << endl;

    vector <Empleado *> empleado(3);
    empleado[0] = &asalariado;
    empleado[1] = &porComision;
    empleado[2] = &baseMasComision;
    cout << "Vinculación dinámica mediante apuntador a la clase base.\n" << endl;
    for (auto i : empleado)
    {
        EmpleadoBaseMasComision *refBaseMasComision = dynamic_cast<EmpleadoBaseMasComision *>(i);
        sl();
        if (refBaseMasComision != nullptr)
        {
            double salarioAnterior = refBaseMasComision->ingresos();
            cout << "salario anterior: " << salarioAnterior << endl;
            refBaseMasComision->establecerSalarioBase(salarioAnterior * 1.10 );
            cout << "el nuevo salario base con aumento de 10% es: " << refBaseMasComision->obtenerSalarioBase() << endl;
        }
        
        imprimeDatos(i);
    }
    
    return 0;
}

void imprimeDatos(const Empleado * const ptrE)
{
    ptrE->imprimir();
    cout << "\nObtuvo $" << ptrE->ingresos() << endl; cout << endl;
}
#include <iostream>
#include "Cuenta.h"
using namespace std;
Cuenta::Cuenta(int saldo)
{
    if (saldo<0)
    {
        saldoCuenta = 0;
        cerr << "Inicialización inválida. Saldo establecido a 0" << endl;
    }
    else
    {
        saldoCuenta = saldo;
    }
}
void Cuenta::establecerSaldo(int saldo)
{
    if (saldo<0)
    {
        cerr << "Argumento inválido. Estado de cuenta sin cambios" << endl;
    }
    else
    {
        saldoCuenta = saldo;
    }
}

int Cuenta::obtenerSaldo() const
{
    return saldoCuenta;
}

void Cuenta::abonar(int monto)
{
    establecerSaldo(obtenerSaldo() + monto);
    cout << "Operación exitosa." << endl;
    mostrarSaldo();
}

void Cuenta::retirar(int monto)
{
    if (obtenerSaldo() < monto)
    {
        cerr << "El monto a retirar no puede ser mayor a su saldo." << endl;
    }
    else
    {
        establecerSaldo(obtenerSaldo() - monto);
        cout << "Operación exitosa." << endl;
        mostrarSaldo();
    }
    
}

void Cuenta::mostrarSaldo() const
{
    cout << "su saldo actual es: " << obtenerSaldo() << endl;
}

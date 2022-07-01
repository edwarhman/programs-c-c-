#include "Empleado.h"
#include <iostream>
using namespace std;
Empleado::Empleado(const std::string &nombre, const std::string &apellido, const std::string &nss)
:primerNombre(nombre), apellidoPaterno(apellido), numeroSeguroSocial(nss)
{
}

void Empleado::establecerPrimerNombre(const string & nombre)
{
    primerNombre = nombre;
}

string Empleado::obtenerPrimerNombre() const
{
    return primerNombre;
}

void Empleado::establecerApellidoPaterno(const string & apellido)
{
    apellidoPaterno = apellido;
}

string Empleado::obtenerApellidoPaterno() const
{
    return apellidoPaterno;
}

void Empleado::establecerNumeroSeguroSocial(const string & nss)
{
    numeroSeguroSocial = nss;
}

string Empleado::obtenerNumeroSeguroSocial() const
{
    return numeroSeguroSocial;
}

void Empleado::imprimir() const
{
    cout << obtenerPrimerNombre() << " " << obtenerApellidoPaterno()
         << "\nNúmero de seguro social: " << obtenerNumeroSeguroSocial();
}
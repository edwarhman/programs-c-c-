#include <iostream>
#include "FrecuenciaCardiaca.h"

using namespace std;

FrecuenciaCardiaca::FrecuenciaCardiaca(string nombre, string apellido,int dia,int mes,int anio)
{
    nombrePersona = nombre;
    apellidoPersona = apellido;
    diaNacimiento = dia;
    mesNacimiento = mes;
    anioNacimiento = anio;
    establecerEdad();
}

void FrecuenciaCardiaca::establecerNombre(string nombre)
{
    if (nombre.length() < 20)
    {
        nombrePersona = nombre;
    }
    else
    {
        nombrePersona = nombre.substr(0, 20);
        cerr << "No se pudo almacenar el nombre completo (el máximo son 20 caracteres)." << endl;
    }
}

void FrecuenciaCardiaca::establecerApellido(string nombre)
{
    if (nombre.length() < 20)
    {
        apellidoPersona = nombre;
    }
    else
    {
        apellidoPersona = nombre.substr(0, 20);
        cerr << "No se pudo almacenar el nombre completo (el máximo son 20 caracteres)." << endl;
    }
}

void FrecuenciaCardiaca::establecerDiaNacimiento(int dia)
{
    if (dia>0 && dia < 32)
    {
        diaNacimiento = dia;
    }
    else
    {
        cerr << "Dato inválido." << endl;
    }
}
void FrecuenciaCardiaca::establecerMesNacimiento(int mes)
{
    if (mes>0 && mes < 13)
    {
        mesNacimiento = mes;
    }
    else
    {
        cerr << "Dato inválido." << endl;
    }
}
void FrecuenciaCardiaca::establecerAnioNacimiento(int anio)
{
    if (anio>0 && anio < 32)
    {
        anioNacimiento = anio;
    }
    else
    {
        cerr << "Dato inválido." << endl;
    }
}

string FrecuenciaCardiaca::obtenerNombre() const
{
    return nombrePersona;
}

string FrecuenciaCardiaca::obtenerApellido() const
{
    return apellidoPersona;
}

int FrecuenciaCardiaca::obtenerDiaNacimiento() const
{
    return diaNacimiento;
}

int FrecuenciaCardiaca::obtenerMesNacimiento() const
{
    return mesNacimiento;
}

int FrecuenciaCardiaca::obtenerAnioNacimiento() const
{
    return anioNacimiento;
}

void FrecuenciaCardiaca::establecerEdad()
{
    static int dia = 0, mes = 0, anio = 0;
    int edad = 0;
    if (dia <= 0 || mes <= 0 || anio <= 0)
    {
        cout << "Por favor ingrese la fecha actual (DD MM AAAA): ";
        cin >> dia >> mes >> anio;
    }
    edad = anio - obtenerAnioNacimiento();
    if (mes < obtenerMesNacimiento() || (mes == obtenerMesNacimiento() && dia < obtenerDiaNacimiento()))
    {
        edad--;
    }
    edadPersona = edad;
}

int FrecuenciaCardiaca::obtenerEdad() const
{
    return edadPersona;
}

void FrecuenciaCardiaca::establecerFrecuenciaCardiaca(int* A, int* B) const
{
    int frecuencia = 0;
    frecuencia = 220 - obtenerEdad();
    *A = frecuencia*50/100;
    *B = frecuencia*85/100;
}

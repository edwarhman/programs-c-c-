#include "AdivinaElNumero.h"
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

default_random_engine motor(static_cast<unsigned int>(time(0)));
uniform_int_distribution<unsigned int> aleartorio(MINIMO,MAXIMO);

AdivinaElNumero::AdivinaElNumero(/* args */)
:numeroAleartorio(0), entradaUsuario(0), intentos(0)
{
    
}

AdivinaElNumero::~AdivinaElNumero()
{
	
}

void AdivinaElNumero::LeerEntrada()
{
    unsigned int entrada = 0; //Entrada que sera evaluada
    do
    {
        cin >> entrada;
        if (EvaluarEntrada(entrada))
        {
            entradaUsuario = entrada;
            intentos++;
        }
        else    
            cout << "entrada inv�lida. Ingrese otro n�mero: ";
    } while (!EvaluarEntrada(entrada));
}

bool AdivinaElNumero::EvaluarEntrada(unsigned int entrada) const
{
    if (entrada <= MAXIMO && entrada >= MINIMO)
    {
        return true;
    }
    else 
        return false;
}

bool AdivinaElNumero::CompararNumeros()
{
    if (entradaUsuario == numeroAleartorio)
    {
        MostrarMensaje(0);
        MensajeAlGanar();
        return true;
    }
    else if (entradaUsuario > numeroAleartorio)
    {
        MostrarMensaje(1);
        LeerEntrada();
        return false;
    }
    else
    {
        MostrarMensaje(2);
        LeerEntrada();
        return false;
    }
    return false;
}

void AdivinaElNumero::MostrarMensaje(unsigned int caso) const
{
    switch (caso)
    {
    case 2:
        cout << "demasiado bajo, vuelva a intentarlo. ";
        break;
    case 1:
        cout << "demasiado alto, vuelva a intentarlo. ";
        break;
    default:
        cout << "Felicidades. Ha adivinado el n�mero." << endl;
        break;
    }
}


void AdivinaElNumero::GenerarAleartorio()
{
    numeroAleartorio = aleartorio(motor);
    intentos = 0;
}

void AdivinaElNumero::MensajeAlGanar() const
{
    if (intentos < INTENTOS_OP)
    {
        cout << "O ya sab�a usted el secreto, o tuvo suerte." << endl;
    }
    else if (intentos == INTENTOS_OP)
    {
        cout << "�Aj�! Ya sab�a usted el secreto." << endl;
    }
    else
    {
        cout << "�Deber�a haberlo hecho mejor!" << endl;
    }
    
}

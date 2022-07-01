#include <iostream>
#include "AdivinaElNumero.h"
#include <locale.h>
using namespace std;

//Prototipos

bool decidirFin();

int main()
{
    setlocale(LC_ALL,"");
    AdivinaElNumero juego;
    bool terminarRonda = false;
    do
    {
        juego.GenerarAleartorio();
        cout << "Tengo un número entre " << MINIMO << " y " << MAXIMO << "." << endl;
        cout << "¿Puedes adivinar mi número?" << endl;
        cout << "Por favor escribe tu primera respuesta: ";
        juego.LeerEntrada();
        do
        {
            terminarRonda = juego.CompararNumeros();

        } while (!terminarRonda);
        
    } while (decidirFin());
    
    return 0;
}


//Pregunta al usuario si desea repetir el juego o finalizar el programa
bool decidirFin()
{
    char entrada;
    cout << "¿Desea repetir el juego? (S/N): ";
    cin >> entrada;
    switch (entrada)
    {
    case 's': case 'S':
        return true;

    case 'n': case 'N':
        return false;    
    default:
        cout << "entrada inválida" << endl;
        return false;
    }
}

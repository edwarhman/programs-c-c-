#include "Craps.h"
#include <iostream>
#include "Dados.h"
#include "Apuestas.h"
#include <locale.h>
using namespace std;

bool salir();
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"");
    //Variables
    Dados dado;
    Apuestas jugador1;

    Craps::mostrarReglas();
    do
    {
        Craps miCraps;
        jugador1.reestablecerEnJuego();
        miCraps.mostrarMensaje(Mensajes::INICIAL);
        jugador1.mostrarFondos();
        jugador1.apostar();
        jugador1.establecerFondos(Resultado::PIERDE);
        jugador1.establecerEnJuego();
        miCraps.establecerTiro(dado.tirarDado(2));
        while (!miCraps.comprobarEstado())
        {
            cout << "====================================================" << endl;
            miCraps.mostrarMensaje(Mensajes::CONTINUAR);
            jugador1.mostrarFondos();
            jugador1.incrementarApuesta();  
            miCraps.establecerTiro(dado.tirarDado(2));
            
        }

        if (miCraps.obtenerEstado() == Estado::GANA)
        {
            cout << "====================================================" << endl;
            jugador1.establecerFondos(Resultado::GANA);
            miCraps.mostrarMensaje(Mensajes::GANADOR);
            jugador1.mostrarFondos();
        }
        else if (miCraps.obtenerEstado() == Estado::PIERDE)
        {
            cout << "====================================================" << endl;
            miCraps.mostrarMensaje(Mensajes::PERDEDOR);
        }

    } while (jugador1.obtenerFondos() != 0 && !salir());
    
    if (jugador1.obtenerFondos() == 0)
    {
        cout << "Se ha quedado sin fondos. Mejor suerte la próxima vez." << endl;
    }
    else
    {
        cout << "¡Vuelva pronto!" << endl;
    }
 
    return 0;
}

bool salir()
{
    char respuesta = '0';
    cout << "¿Desea retirarse? (s/n) ";
    cin >> respuesta;
    if(respuesta == 's' || respuesta == 'S')
    {
        cout << "====================================================" << endl;
        return true;
    }
    else if(respuesta == 'n' || respuesta == 'N')
    {
        cout << "====================================================" << endl;
        return false;
    }
}


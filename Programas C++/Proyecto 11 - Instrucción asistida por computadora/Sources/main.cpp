#include "cai.h"
#include <locale.h>
#include <iostream>
#define PREGUNTAS 10
using namespace std;


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    cai partida;
    
    partida.elegirOperacion();
    partida.elegirDificultad();
    cout << "Tiene que responder correctamente a las 10 preguntas." << endl;
    for (size_t i = 0; i < PREGUNTAS; i++)
    {
        cout << i + 1 << ". ";
        partida.generarPregunta();
        do
        {
            partida.establecerRespuesta();
            partida.evaluarRespuesta();
            partida.mostrarMensaje();
        } while (!partida.obtenerAcierto()); //Fin de ciclo do-while para ingresar la respuesta correcta
        cout << endl;
    } //Fin de ciclo for para generar las 10 preguntas
    
    partida.mostrarResultados();
    return 0;
 }
 
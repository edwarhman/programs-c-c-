#include <iostream>
#include "Votaciones.h"
#include <locale.h>
using namespace std;

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"");
    array<string, QUESTIONS + 1> misTemas{
        " ",
        "La salud deberia ser gratuita y de fácil acceso.",
        "Cadena perpetua para los crimitales que cometen asesinato.",
        "Multas por violar el derecho a la paz y tranquilidad.",
        "Mantequilla gratis a cada familia.",
        "Pensiones justas a los ciudadanos de la tercera edad.",
    };
    cout << "ingrese la cantidad de encuestados: ";
    Votaciones misVotaciones(misTemas);
    misVotaciones.askQuestions();
    misVotaciones.showElections(); 
    system("pause");
    return 0;
}

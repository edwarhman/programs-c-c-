#include "JuegoDados.h"
#include <iostream>

using namespace std;

default_random_engine motor(static_cast<unsigned int>(time(0)));
uniform_int_distribution<unsigned int> aleartorio(1, JuegoDados::caras);

//Constructor clase JuegoDados
JuegoDados::JuegoDados()
{
    int suma = 0;
    for (size_t i = 1; i <= caras; i++)
    {
        for (size_t j = 1; j <= caras; j++)
        {
            suma = i + j;
            if (!evaluarVector(suma))
            {
                listaResultados.push_back(PosiblesSumas(suma));
            }
            
        }
        
    }
    
} //Fin de constructor

//Funcion que establece las apariciones del resultado suministrado
void JuegoDados::establecerApariciones(int test)
{
    for (auto &elemento : listaResultados)
    {
        if (test == elemento.obtenerPosiblesSumas())
        {
            elemento.aumentarApariciones();
        }
        
    }
    
}//fin funcion establecerApariciones

//Funcion que muestra los resultados
void JuegoDados::mostrarResultados() const
{
    for (auto &elemento : listaResultados)
    {
        cout << "El resultado " << elemento.obtenerPosiblesSumas() << " aparece\t"
             << elemento.obtenerApariciones() << endl;
    }
    
    
}//Fin de funcion mostrarResultados

bool JuegoDados::evaluarVector(int test) const
{
    bool seRepite = false;
    if (listaResultados.size() > 0)
    {
        for (auto &i : listaResultados)
        {
            if (test == i.obtenerPosiblesSumas())
            {
                seRepite = true;
            }
            
        }
        
    }
    return seRepite;
} //fin funcion mostrarResultados

//Funcion que lanza ambos dados y establece el resultado 
void JuegoDados::lanzarDados()
{

    int suma = 0;
    suma = aleartorio(motor) + aleartorio(motor);
    establecerApariciones(suma);
} //Fin de funcion lanzarDados

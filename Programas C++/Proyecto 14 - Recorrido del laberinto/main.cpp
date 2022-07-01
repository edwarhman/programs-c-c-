#include <iostream>
#include <locale.h>
#include <array>
#include <random>
#include <ctime>

#define TAM_FILA 12
using namespace std;

default_random_engine motor(static_cast<unsigned>( time(0)));
uniform_int_distribution<unsigned> paredes(40, 45);
uniform_int_distribution<unsigned> posAleartoria(0, TAM_FILA - 1);

//Prototipos de funciones
void generarLaberinto(array<array<char, TAM_FILA>, TAM_FILA> &lab);
void rellenarInterior(array<array<char, TAM_FILA>, TAM_FILA> &lab);
void establecerBorde(array<array<char, TAM_FILA>, TAM_FILA> &lab);
void mostrarLaberinto(array<array<char, TAM_FILA>, TAM_FILA> &lab);
void generarParedes(array<array<char, TAM_FILA>, TAM_FILA> &lab);
bool comprobarAdyacentes(array<array<char, TAM_FILA>, TAM_FILA> lab, int x, int y);
void soloUnCamino(array<array<char, TAM_FILA>, TAM_FILA> &lab);
bool comprobarCaminosAdyacentes(const array<array<char, TAM_FILA>, TAM_FILA> &lab, int x, int y);

// Función main
int main(int argc, char const *argv[])
{
    cout << endl;
    array<array<char, TAM_FILA>, TAM_FILA> laberinto;
    generarLaberinto(laberinto);
    mostrarLaberinto(laberinto);
    return 0;
}


// Funciones secundarias
void generarLaberinto(array<array<char, TAM_FILA>, TAM_FILA> &lab)
{
    rellenarInterior(lab);
    establecerBorde(lab);
    generarParedes(lab);
}

void rellenarInterior(array<array<char, TAM_FILA>, TAM_FILA> &lab)
{
    for (size_t fila = 0; fila < TAM_FILA; fila++)
    {
        for (size_t caracter = 0; caracter < TAM_FILA; caracter++)
        {
            lab[fila][caracter] = '-';
        }
        
    }
    
}

void establecerBorde(array<array<char, TAM_FILA>, TAM_FILA> &lab)
{
    for (size_t elemento = 0; elemento < TAM_FILA; elemento++)
    {
        lab[0][elemento] = '#';
        lab[TAM_FILA - 1][elemento] = '#';
        lab[elemento][0] = '#';
        lab[elemento][TAM_FILA - 1] = '#';
    }
    
}

void mostrarLaberinto(array<array<char, TAM_FILA>, TAM_FILA> &lab)
{
    for (size_t fila = 0; fila < TAM_FILA; fila++)
    {
        for (size_t caracter = 0; caracter < TAM_FILA; caracter++)
        {
            cout << lab[fila][caracter] << " ";
        }
        cout << endl;
    }
    
}

void generarParedes(array<array<char, TAM_FILA>, TAM_FILA> &lab)
{
    int cantidadParedes = 40; //paredes(motor);
    //cout << cantidadParedes << endl;
    int posA = 0;
    int posB = 0;
    while (cantidadParedes > 0)
    {
        posA = posAleartoria(motor);    
        posB = posAleartoria(motor);    
        if (lab[posA][posB] == '-' && comprobarAdyacentes(lab, posB, posA))
        {
            lab[posA][posB] = '#';
            cantidadParedes--;
        }
        //cout << cantidadParedes << " ";
        mostrarLaberinto(lab);
    }
    soloUnCamino(lab);
    //cout << endl;
}

bool comprobarAdyacentes(array<array<char, TAM_FILA>, TAM_FILA> lab, int x, int y)
{
    int contador = 0;
    int diagonales = 0;
    int lados = 0;
    if (lab[y+1][x+1] == '#')
    {
        diagonales++;
    }
    if (lab[y-1][x-1] == '#')
    {
        diagonales++;
    }
    if (lab[y+1][x-1] == '#')
    {
        diagonales++;
    }
    if (lab[y-1][x+1] == '#')
    {
        diagonales++;
    }
    if (lab[y][x+1] == '#')
    {
        lados++;
    }
    if (lab[y][x-1] == '#')
    {
        lados++;
    }
    if (lab[y-1][x] == '#')
    {
        lados++;
    }
    if (lab[y+1][x] == '#')
    {
        lados++;
    }
    if (diagonales + lados >= 4)
    {
        return false;
    }
    else if (diagonales > 0 && lados <= 0 )
    {
        return false;
    }
    
    else
    {
        return true;
    }
    
    
}

void soloUnCamino(array<array<char, TAM_FILA>, TAM_FILA> &lab)
{
    for (size_t j = 1; j < lab.size() - 1; j++)
    {
        for (size_t i = 1; i < lab.size() - 1; i++)
        {
            if( lab[j][i] == '-' && !comprobarCaminosAdyacentes(lab, i, j) && comprobarAdyacentes(lab, i, j))
                lab[j][i] = '#';
        }
        
    }
}

bool comprobarCaminosAdyacentes(const array<array<char, TAM_FILA>, TAM_FILA> &lab, int x, int y)
{
    if (lab[y+1][x]=='-' && lab[y][x+1]=='-' && lab[y+1][x+1]=='-')
    {
        return false;
    }
    else if (lab[y+1][x]=='-' && lab[y][x-1]=='-' && lab[y+1][x-1]=='-')
    {
        return false;
    }
    else if (lab[y-1][x]=='-' && lab[y][x-1]=='-' && lab[y-1][x-1]=='-')
    {
        return false;
    }
    else if (lab[y-1][x]=='-' && lab[y][x+1]=='-' && lab[y-1][x+1]=='-')
    {
        return false;
    }
    else
    {
        return true;
    }
    
    
}
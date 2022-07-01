#include <locale.h>
#include <stdio.h>
#include "C:\Users\Emerson\Documents\Programas en C\Headers\misHeaders.h"
#define TAM_LISTA 10

int calcularSuma(int lista[],int elementos);
int encontrarMAX(int lista[],int elementos);

int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"spanish");
    puts("Programa que solicita 10 números enteros y calcula la suma entre ellos. Tambien indica cual es el mayor.");
    int lista[TAM_LISTA];
    int suma=0,
        MAX=0;
    
    LeerListaEnteros(lista,TAM_LISTA);
    suma=calcularSuma(lista,TAM_LISTA);
    MAX=encontrarMAX(lista,TAM_LISTA);

    printf("La suma de todos los elementos de la lista es %d.\n",suma);
    printf("El valor máximo es %d.\n",MAX);
    return 0;
}

int calcularSuma(int lista[],int elementos)
{
    int suma=0;
    for (int i = 0; i < elementos; i++)
    {
        suma+=lista[i];
    }
    return suma;
}
int encontrarMAX(int lista[],int elementos)
{
    int MAX=0;
    for (int i = 0; i < elementos; i++)
    {
        if(lista[i]>MAX) MAX=lista[i];
    }
    return MAX;
}

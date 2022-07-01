#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <C:\Users\Emerson\Documents\Programas en C\Headers\misheaders.h>
void llena_a(int arreglo[],int rango);
void muestra_a(int arreglo[],int rango);
void invertir_a(int arreglo[],int rango);
int main(int argc, char const *argv[])
{
    int N=0;
    int lista[200]={0};
    setlocale(LC_CTYPE,"spanish");
    srand(1);
    N=LeerEntero("Por favor ingrese la cantidad de números.");
    llena_a(lista,N);
    muestra_a(lista,N);
    invertir_a(lista,N);
    muestra_a(lista,N);
    return 0;
}

void llena_a(int arreglo[],int rango)
{
    for (int i = 0; i < rango; i++)
    {
        arreglo[i]=rand();
    }
    
}
void muestra_a(int arreglo[],int rango)
{
    for (int i = 0; i < rango; i++)
    {
        printf("%d ",arreglo[i]);
    }
    printf("\n");
    
}
void invertir_a(int arreglo[],int rango)
{
    int aux[200]={0};
    for (int i = 0; i < rango; i++)
    {
        aux[i]=arreglo[rango-i-1];
    }
    for (int i = 0; i < rango; i++)
    {
        arreglo[i]=aux[i];
    }
    
}
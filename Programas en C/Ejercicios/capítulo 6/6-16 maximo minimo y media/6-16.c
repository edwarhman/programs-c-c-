#include <stdio.h>
#include <locale.h>
#include "C:/Users/Emerson/Documents/Programas en C/Headers/misHeaders.h"

//DECLARACIÓN ESTRUCTURAS

struct lista 
{
    int elementos[50];
    float media;
    int cantidad,
        maximo,
        minimo;
};

void Maximo(struct lista* p);
void Minimo(struct lista* p);
void Media(struct lista* p);

int main(void)
{
    struct lista numeros;
    setlocale(LC_CTYPE,"spanish");

    //Encabezado del programa
    puts("Programa que calcula la media y de un conjunto de números suministrados por el usuario.");
    puts("También indica cual de ellos es el mayor y cual es el menor.");

    //Entrada de datos
    numeros.cantidad=LeerEntero("Por favor indique cuantos datos desea ingresar: ");
    LeerListaEnteros(numeros.elementos,numeros.cantidad);

    //Operaciones
    Maximo(&numeros);
    Minimo(&numeros);
    Media(&numeros);

    //Salida de datos
    printf("\nMaximo: %d",numeros.maximo);
    printf("\nMínimo: %d",numeros.minimo);
    printf("\nMedia: %.2f",numeros.media);
    printf("%d",numeros.cantidad);
    return 0;
    
}

void Maximo(struct lista* p)
{
    int max=0;
    for (int i = 0; i < p->cantidad; i++)
    {
        if (p->elementos[i]>max)
        {
            max=p->elementos[i];
        }
    }
    p->maximo=max;
}

void Minimo(struct lista* pp)
{
    int min;
    for (int i = 0; i < pp->cantidad; i++)
    {
        if (i==0||pp->elementos[i]<min)
        {
            min=pp->elementos[i];
        }
        
    }
    pp->minimo=min;
}

void Media(struct lista* p)
{
    int suma=0, numero=0;
    float med=0;
    
    for (int i = 0; i < p->cantidad; i++)
    {
        numero=p->elementos[i];
        suma+=numero;
        
    }
    med=(float)suma/p->cantidad;
    p->media=med;
}


#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define TAM 3
struct Cadena
{
    char cadena[100];
    int longitud;
    int ocurrencias;  //ocurrencias de palabras de cuatro letras en la cadena
    char copia[100];
};
int N=0;
void mostrar_r(struct Cadena ca[]);
void leer_cadenas(struct Cadena ca[]);
void sustituir(struct Cadena *ca,int i);
void copiar_cadena(struct Cadena ca[]);
void evaluar_cadenas(struct Cadena ca[]);
calcular_l(struct Cadena ca[]);
int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"spanish");
    struct Cadena coleccion[20];
    leer_cadenas(coleccion);
    printf("\n%d\n",N);
    calcular_l(coleccion);
    copiar_cadena(coleccion);
    evaluar_cadenas(coleccion);
    mostrar_r(coleccion);
    return 0;
}
void mostrar_r(struct Cadena ca[])
{
    int i=0;
    for (int i = 0; i < N ; i++)
    {
        printf("Cadena %d: \n", i + 1);
        printf("Original: %s",ca[i].cadena);
        printf("\nlongitud: %d",ca[i].longitud);
        printf("\nOcurrencias de palabras de cuatro letras: %d",ca[i].ocurrencias);
        printf("\nModificado: %s\n\n",ca[i].copia);
    }
}

void leer_cadenas(struct Cadena ca[])
{
    char bandera[100];
    int i = 0;
    printf("Ingrese las cadenas que desee evaluar. Para finalizar el escaneo escribir salir y presionar enter.\n");
    do
    {
        printf("Por favor ingrese la cadena: \n");
        gets(ca[i].cadena);
        strcpy(bandera,ca[i].cadena);
        i++;
    } while (strcmp(bandera,"salir")!=0);
    N=i-1;
}
void evaluar_cadenas(struct Cadena ca[])
{
    int i = 0, n = 0, j=0;
    for (i = 0; i < N; i++)
    {
        do
        {
            if(n == 0)
            {
                if(ca[i].cadena[j+4]==' ' || ca[i].cadena[j+4]=='\0')
                {
                   sustituir(&ca[i],j);
                   j+=5;
                   continue;
                }
            }
            if(ca[i].cadena[j]==' ')
                n=-1;
            printf("\n%d",j);
            j++;
            n++;
        } while (ca[i].longitud>j);
        n=0;
        j=0;
        
    }
    
}
void sustituir(struct Cadena *ca,int i)
{
    for (int j = 0; j < 4; i++,j++)
    {
        ca->copia[i]='*';
    }
    
}
void copiar_cadena(struct Cadena ca[])
{
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        strcpy(ca[i].copia,ca[i].cadena);
        
    }
    
}
calcular_l(struct Cadena ca[])
{
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        j = 0;
        do
        {
            j++;
        } while (ca[i].cadena[j]!='\0');
        ca[i].longitud=j-1;
    }
    
}
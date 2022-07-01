#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>


enum {FALSE,TRUE};
//PROTOTIPOS
int LeerEntero(char mensaje []);
void LeerCadena(char cadena[]);
int esPrimo (int numero);
int esPerfecto(int numero);
int esBisiesto(int year);
void LeerListaEnteros(int lista[],int elementos);
int calcula_mcd(int m, int n);
int random(int lower,int upper);
void intercambiar(int *A, int *B);
//FUNCIONES
int LeerEntero(char mensaje [])
{
    int valor=0;
    char caracter[20]="0";
    for (; valor < 1;)
    {
        printf(mensaje);
        scanf("%d", &valor);
        if (valor < 1)
        {
            //if(strcmp(caracter,"0")==0)
            gets(caracter);
            printf("Dato inválido.\n");
            
        }
    }
    return valor;
}

void LeerCadena(char cadena[])
{
    scanf("%s",cadena);
}

void LeerListaEnteros(int lista[],int elementos)
{
    switch (elementos)
    {
    case 0:
        puts("Ingrese valores enteros positivos. Cuando haya finalizado ingrese 0: ");
        for (int i = 0; scanf("%d",&lista[i++])!=0;){}
        break;
    
    default:
        printf("ingrese %d números enteros positivos: ",elementos);
        for (int i = 0; i < elementos; i++)
        {
            scanf("%d",&lista[i]);
        }
        
        break;
    }
}

int esPrimo (int numero)
{
    int resto=0,
        lo_es=TRUE;
    for (int i = 2; i < numero&&lo_es;)
    {
        resto=numero%i;
        (resto==0)?lo_es=FALSE:i++;
    }
    return lo_es;
}

int esPerfecto(int numero)
{
    int lo_es=FALSE,
        suma=0;
    int resto = 0;
    for (int i = 1; i < numero; i++)
    {
        resto=(int)numero%i;
        if(resto==0)suma+=i;
    }
    if(suma==numero) lo_es=TRUE;
    return lo_es;
}

int esBisiesto(int year)
{
    int lo_es=FALSE;
    if ((year % 4)==0)
    {
        if (!year % 100 == 0)
            lo_es = TRUE;
        else if (year % 400)
            lo_es = TRUE;
    }
    return lo_es;
}

int calcula_mcd(int m, int n)
{
    int aux=0;
    if(n>m)
    {
        aux=m;
        m=n;
        n=aux;
    }
    for(;n>0;)
    {
        aux=m%n;
        m=n;
        n=aux;
    }
    return m;
}
int random(int lower,int upper)
{
    int aleartorio=rand();
    return (aleartorio%(upper-lower+1)+lower);
}
void intercambiar(int *A, int *B)
{
    int AUX;
    AUX=*A;
    *A=*B;
    *B=AUX;
    return;
}
#include <stdio.h>
#include <locale.h>
#define RANGO 80
enum BOOLEAN {FALSE,TRUE};

int es_primo(int arreglo[],int N,int numero);
void muestra_l (int arreglo[],int rango);
void llenar_l (int lista[], int rango);
int main(int argc, char const *argv[])
{
    int lista[RANGO]={1};
    setlocale(LC_CTYPE,"spanish");
    printf("Programa que muestra los primeros %d números primos.\n",RANGO);
    llenar_l(lista,RANGO);
    //muestra_l(lista,RANGO);
    return 0;
}

int es_primo(int arreglo[],int N,int numero)
{
    int lo_es=TRUE;
    int resto=0;
    for (int i = 1; i < N; i++)
    {
        resto=numero%arreglo[i];
        if (resto==0)
        {
            lo_es=FALSE;
            break;
        }
    }
    return lo_es;
}

void llenar_l (int lista[], int rango)
{
    int N=1;
    for (int i = 0; i < rango; N++)
    {
        if (es_primo(lista,i,N))
        {
            lista[i]=N;
            printf("%d\t",lista[i++]);
        }
        
    }
    
}

void muestra_l (int arreglo[],int rango)
{
    for (int i = 0; i < rango; i++)
    {
        printf("%d\t",arreglo[i]);
    }
    
}
/*
int es_realmente_primo (int numero)
{
    int n=0,
        rango=0;
    int resto;
    int lo_es = TRUE;
    static int primos[RANGO]={1};

    for ( n = 1; n < numero; n++,resto=1)
    {
        for (int i = 0; i < rango; i++)
        {
            resto=n%primos[i];
        }
        if (resto==0)
        {
             
        }
        
    }
}
*/
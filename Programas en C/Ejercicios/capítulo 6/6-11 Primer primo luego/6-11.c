#include <locale.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numero=0;
    setlocale(LC_CTYPE,"spanish");
    puts("Programa que solicita un número y halla el primer número primo que sea mayor.");
    numero=pedirDato("Ingrese un número: ");
    for (int i = numero;; i++)
    {
        if (esPrimo(i))
        {
            printf("El primer numero primo luego de %d es %d\n",numero,i);
            break;
        }
        
    }
    
    return 0;
}

int esPrimo(int numero)
{
    int lo_es =1;
    int resto=0;
    for (int i = 2; i < numero; i++)
    {
        resto=numero%i;
        if (resto==0)
        {
            lo_es=0;
            break;
        }
        
    }
    return lo_es;
}

int pedirDato(char mensaje[30])
{
    int dato=0;
    char entrada[20];
    for(;dato<=0;)
    {
        printf(mensaje);
        scanf("%d",&dato);
        if (dato<=0)
        {
            scanf("%s",entrada);
            puts("Dato inválido.");
            //break;
        }
        
    }
    return dato;
}

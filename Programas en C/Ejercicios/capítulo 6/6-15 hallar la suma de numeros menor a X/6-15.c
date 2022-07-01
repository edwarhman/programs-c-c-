#include <stdio.h>
#include <locale.h>
int sumadeN(int numero);
void EvaluarSuma(int numero);
int pedirDato(char mensaje[30]);
int main(int argc, char const *argv[])
{
    int numero=0;
    setlocale(LC_CTYPE,"spanish");
    puts("Programa que encuentra el primer número natural cuya suma con los números anteriores es mayor a un número suministrado por el usuario.");
    numero=pedirDato("Por favor ingrese un número: ");
    EvaluarSuma(numero);
    return 0;
}

int sumadeN(int numero)
{
    int suma=0;
    for (int i = 0; i < numero; i++)
    {
        suma=suma+(numero-i);
    }
    return suma;
}

void EvaluarSuma(int numero)
{
    int i = 2;
    for (; sumadeN(i)<=numero; i++)
    {
        
    }
    printf("El número es %d.\n",i);
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
        }
    }
    return dato;
}
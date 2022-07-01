#include <locale.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int numero;
    setlocale(LC_CTYPE,"Spanish");
    puts("Programa que visualiza la suma de la serie de e^x para cada uno de los valores desde 1 a 100.");
    numero=PedirDato("Ingrese el valor de X: ");
    printf("%d\n",numero);
    Serie_Ex(numero);
    return 0;
}

double Factorial(int n)
{
    static double factorial=1;
    factorial*=n;
    //printf("%e\t",factorial);
    return factorial;
}

void Serie_Ex(int x)
{
    double suma = 1;
    for (int i = 1; i < 101; i++)
    {
        suma+=((pow(x,i))/Factorial(i));
        printf("i=%d\t%f\n",i,suma);
    }
    return;
}
int PedirDato(char mensaje[30])
{
    int dato=-1;
    for(;;)
    {
        printf(mensaje);
        scanf("%d", &dato);
        if(dato>=0) break;
            else puts("Dato inválido");
    }
    return dato;
}
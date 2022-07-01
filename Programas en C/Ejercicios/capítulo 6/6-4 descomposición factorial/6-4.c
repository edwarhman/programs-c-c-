#include <stdio.h>
#include <locale.h>
#define VAL_INI 1900
#define VAL_FIN 2000
void Des_factorial(int numero);
int main(int argc, char const *argv[])
{
    int numero = 154;
    char caracter;
    setlocale(LC_CTYPE, "spanish");
    puts("Programa que determina y muestra la descomposición factorial de los números comprendidos entre 1900 y 2000.");
    printf("Presione Enter para comenzar. ");
    scanf("nada",&caracter);
    for (int i = VAL_INI; i <= VAL_FIN; i++)
    {
        printf("%d ",i);
        Des_factorial(i);
        puts("");
    }

    return 0;
}

void Des_factorial(int numero)
{
    for (int i = 2; i <= numero;)
    {
        if ((numero % i) == 0)
        {
            printf("%d ", i);
            numero /= i;
        }
        else
            i++;
    }
}
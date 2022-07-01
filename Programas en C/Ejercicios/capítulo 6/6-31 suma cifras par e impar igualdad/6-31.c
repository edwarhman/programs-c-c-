#include <stdio.h>
void parEimpar(int numero);
int main(int argc, char const *argv[])
{
    int numero = 7566;
    for (int i = 1000; i < 10000; i++)
    {
        parEimpar(i);
    }
    printf("hola a todo el mundo");
    return 0;
}

void parEimpar(int numero)
{
    int resto = numero, divisor = 0, sPAR = 0, sIMPAR = 0;
    for (int i = 1000; i >= 1; resto %= i, i /= 10)
    {
        divisor = resto / i;
        if (divisor % 2 == 0)
        {
            sPAR += divisor;
        }
        else
            sIMPAR += divisor;
    }
    if (sIMPAR == sPAR)
        printf("\t%d", numero);
    return;
}

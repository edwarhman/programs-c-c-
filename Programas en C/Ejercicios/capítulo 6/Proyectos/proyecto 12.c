#include <stdio.h>
#include "C:/Users/Emerson/Documents/Programas en C/Headers/misHeaders.h"

int main(int argc, char const *argv[])
{
    int m=0,n=0,mcd=0;
    setlocale(LC_CTYPE,"spanish");
    puts("Programa que calcula el m�ximo com�n divisor entre dos n�meros.");
    m=LeerEntero("ingrese el primer valor: ");
    n=LeerEntero("ingrese el segundo valor: ");
    mcd=calcula_mcd(m,n);
    printf("El m�ximo com�n divisor es %d",mcd);
    return 0;
}

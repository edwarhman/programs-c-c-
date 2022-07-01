#include <stdio.h>

int numero=0,resultado=0;


int main(int argc, char const *argv[])
{
    printf("Programa que multiplica un numero entero dado por 2.\nPor favor ingrese un numero: ");
    scanf("%d",&numero);
    resultado=numero*2;
    printf("El resultado es %d.",resultado);
    return 0;
}

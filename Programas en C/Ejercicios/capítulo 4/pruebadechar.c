#include <stdio.h>
#include <locale.h>

char caracter,caracter2;
int entero;
int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"spanish");
    printf("Ingrese un número entero: ");
    scanf("%d",&entero);
    printf("Su entero es %d",entero);
    printf("\nIngrese un caracter: ");
    scanf("\r%c",&caracter);
    printf("Su caracter es %c",caracter);
    printf("\nIngrese un entero: ");
    scanf("%d",&entero);
    printf("Su entero es %d",entero);
    return 0;
}

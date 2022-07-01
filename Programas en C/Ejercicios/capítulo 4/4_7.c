#include <stdio.h>
#include <locale.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"spanish");
    char cadena[5];
    printf("Introduzca una palabra con no más de cinco letras: ");
    gets(cadena);
    printf("*********************\n");
    printf("*                   *\n");
    printf("*       %s       *\n",cadena);
    printf("*                   *\n");
    printf("*********************\n");
    printf("Su palabra es: %s",cadena);
    return 0;
}

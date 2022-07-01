#include <locale.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int ret=0;
    char cadena1[20]="hola",cadena2[20]="main";
    printf("Introduzca una palabra: ");
    scanf("%s",cadena1);
    ret=strncmp(cadena1,cadena2,"mayo");
    printf("%d",ret);
    return 0;
}

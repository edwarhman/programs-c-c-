#include <locale.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int year=1;
    setlocale(LC_CTYPE,"spanish");
    printf("Programa que indica si un a�o introducido por el usuario es bisiesto.\n");
    printf("Por favor introduzca un a�o: ");
    scanf("%d",&year);
    if (year%4==0)
    {
        if ((year%100==0&&year%400==0)||year%100!=0)
        {
            printf("El a�o %d es bisiesto.\n",year);
        } else printf("El a�o %d no es bisiesto.\n",year);
        
    } else printf("El a�o %d no es bisiesto.\n",year);
    
    return 0;
}

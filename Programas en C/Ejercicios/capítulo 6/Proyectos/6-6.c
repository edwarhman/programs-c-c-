#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    int espacios_enblanco=0;
    //int i=0;
    char cadena[130];
    printf("Ingrese alguna cosa: ");
    gets(cadena);
    puts(cadena);
    
    for (int i = 0;cadena[i]!=0; i++)
    {
        if (isspace(cadena[i]))
        {
            espacios_enblanco++;
        }
        //printf("%d ",cadena[i]);
        //printf("%d\t",i);
    }
    printf("%d",espacios_enblanco);
    return 0;
}

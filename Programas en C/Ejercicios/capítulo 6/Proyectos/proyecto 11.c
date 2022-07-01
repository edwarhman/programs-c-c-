#include <stdio.h>
#include <locale.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    char cadena[20],cadena2[20]={""};
    int entero=0, n=0,i=0,k=1;
    printf("Ingrese un entero: ");
    gets(cadena);
    for (i = 0; isdigit(cadena[i]); i++,k*=10);
    for(n=i;n>0;n--)
    {   
        k/=10;
        cadena2[i-n]=cadena[n-1];
        entero+=((cadena[n-1]-48)*k);
    }
    printf("%s",cadena2);
    //entero='1';
    printf("\n%d",entero);
    return 0;
}

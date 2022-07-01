#include <locale.h>
#include <stdio.h>
#define MAXIMO 11
int rango=0;
int cuadrado[MAXIMO][MAXIMO];
int Pedir_dato(char mensaje[64]);
int main(int argc, char const *argv[])
{
    puts("Programa que visualiza un cuadrado mágico de orden impar comprendido entre 3 y 11.");
    
    rango=Pedir_dato("Por favor ingrese un valor que sea impar y que esté comprendido entre 3 y 11: ");
    for (int i = 1,m=rango/2,n=0; i <= rango*rango; i++,m++,n--)
    {
        if (m >= rango)
        {
            m = 0;
        }
        if (n < 0)
        {
            n = rango - 1;
        }
        if (cuadrado[m][n]!=0)
        {
            m--;
            n+=2;
        }
        if (m <0)
        {  
            m=rango - 1;
        }
        if (n>rango)
        {
            n=n-rango;
        }
        cuadrado[m][n]=i;
    }
    printf("\n");
    for (int n = 0, m=0; n < rango;)
    {
        printf("%d\t",cuadrado[m][n]);
        if (m>=rango-1)
        {
            printf("\n\n");
            m=0;
            n++;
        }
        else m++;
        
    }
    
    
    return 0;
}
int Pedir_dato(char mensaje[64])
{
    int dato_entero = 0;
    char caracter="\0";
    for (;;)
    {
        printf(mensaje);
        scanf("%d", &dato_entero);
        if (dato_entero > 1)
        {
            break;
        }
        scanf("%c",&caracter);
        puts("Dato inválido.");
        
    }
    return dato_entero;
}

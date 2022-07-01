#include <stdio.h>
#include <locale.h>
enum ROMANOS {M=1000,D=500,C=100,L=50,X=10,V=5,I=1};
int main(int argc, char const *argv[])
{
    char cadena[11];
    int romano[10]={0},
        k=0,
        entero=0;
    setlocale(LC_CTYPE,"spanish");
    const char letrasASCII[]={'M','D','C','L','X','V','I'};
    const int l_romanos[]={M,D,C,L,X,V,I};
    puts("Programa que lee un número romano y luego lo represente en numeración arábica.");
    printf("Ingrese un número romano de hasta 10 caracteres: ");
    gets(cadena);
    for (int i = 0; cadena[i]!='\0'; i++,k++)
    {
       for (int j = 0; j < 7; j++)
       {
           if (cadena[i]==letrasASCII[j])
           {
               romano[i]=l_romanos[j];
           }
           
       }
       
    }
    printf("\n%d\n",k);
    
    for (int i = 0; i < k; i++)
    {
        printf("%d\n",romano[i]);
        entero+=(romano[i]>=romano[i+1])?romano[i]:(-romano[i]);
    }

    printf("en numeración arábica es %d",entero);
    

    
    return 0;
}

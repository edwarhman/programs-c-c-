#include <stdio.h>
#include <C:\Users\Emerson\Documents\Programas en C\Headers\misheaders.h>

void build_pyd(int T[], int pisos);
void muestra_pyd(int T[], int pisos);

int main(int argc, char const *argv[])
{
    int triangulo[200]={0};
    int pisos=0;

    setlocale(LC_CTYPE,"spanish");
    puts("Programa que imprime en pantalla un triángulo de Pascal a partir de un número inicial y una cantidad de pisos. Ambos datos suministrados por el usuario.");
    triangulo[0]= LeerEntero("Ingrese el valor del primer número: ");
    pisos= LeerEntero("Ingrese la cantidad de pisos: ");
    build_pyd(triangulo,pisos);
    muestra_pyd(triangulo,pisos);
    return 0;
}

void build_pyd(int T[], int pisos)
{
    int i=1, j=0;
    while (i-j<pisos)
    {
        T[i++]=T[j];
        for (int k = 1; k < (i-j-1);k++)
        {
            T[i++]=T[j] + T[++j];
        }
        T[i++]=T[j++];
    }
}

void muestra_pyd(int T[], int pisos)
{
    int n=0;
    for (int i = 0; i < pisos; i++)
    {
        for (int k = i+1; k < pisos; k++)
        {
            printf("\t");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("%d\t\t",T[n++]);
        }
        printf("\n");        
    }
    
}
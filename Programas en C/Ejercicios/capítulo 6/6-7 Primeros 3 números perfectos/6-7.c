#include <locale.h>
#include <stdio.h>
#define RANGO 20
#define MAXIMO 32000
int EsPerfecto(double numero);
int main(int argc, char const *argv[])
{
    double pares[RANGO],
        impares[RANGO];
    setlocale(LC_CTYPE,"spanish");
    printf("Los primeros tres números perfectos pares son:\n");

    for (int numero = 2,i = 0,j=0; j<3 && i<3; numero++)
    {
        if (EsPerfecto(numero)==1)
        {
            if(numero%2==0)
            {
                pares[i]=numero;
                i++;
            }else
            {
                impares[j]=numero;
                i++;
            }  
        }
    }
    printf("Pares:\n");
    for (int i=0;i<3;i++)
    {
        printf("%e\n",pares[i]);
    }
    printf("Impares:\n");
    for (int i=0;i<3;i++)
    {
        printf("%e\n",impares[i]);
    }
    return 0;
}

int EsPerfecto(double numero)
{
    int resto=0;
    int respuesta=0,
        suma=0;
    for(int i=1;i<numero;i++)
    {
        resto=(int)numero%i;
        if (resto==0)
        {
            suma+=i;
        }
    }
    if(suma==numero)
    {
        respuesta=1;
    }
    return respuesta;
}

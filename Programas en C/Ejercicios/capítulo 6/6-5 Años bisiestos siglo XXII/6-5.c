#include <locale.h>
#include <stdio.h>
#define A_INICIAL 2101
#define A_FINAL 2200
int bisiesto(int year);
int main(int argc, char const *argv[])
{
    char entrada;
    printf("Programa que muestra todos los años bisiestos del siglo XXII\n");
    printf("Por favor pulse la tecla Enter para iniciar el programa.");
    scanf("nada",entrada);
    for (int year = A_INICIAL; year <= A_FINAL; year++)
    {
        if (bisiesto(year))  //LA FUNCIÓN DETERMINA SI EL AÑO ES BISIESTO O NO.
        {
            printf("%d\n",year);
        }
    }
    return 0;
}

int bisiesto(int year)
{
    int es_bisiesto = 0;
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                es_bisiesto=1;
            }
        }
        else
            es_bisiesto=1;
    }
    return es_bisiesto;
}

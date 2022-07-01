#include <stdio.h>
#include <locale.h>


int main(int argc, char const *argv[])
{
    //DECLARACIÓN DE VARIABLES
    int seg,seg_totales,min,horas,dias,semanas;
    char repetir;
    //ENCABEZADO
    setlocale(LC_CTYPE,"spanish");
    printf("Programa que trasnforma una cantidad dada en segundos a su equivalente en semanas, días, horas, minutos y segundos.\n");
    
    do
    {
        printf("Por favor ingrese los segundos: ");
        scanf("%d",&seg);
        //CÁLCULOS
        seg_totales=seg;
        min=seg/60;
        seg=seg%60;
        horas=min/60;
        min=min%60;
        dias=horas/24;
        horas=horas%24;
        semanas=dias/7;
        dias=dias%7;
        //SALIDA DE RESULTADOS
        printf("%d segundos equivalen a %d semanas, %d días, %d horas, %d minutos y %d segundos.\n",seg_totales,semanas,dias,horas,min,seg);
        //¿REPETIR?
        for (;;)
        {
            printf("¿Desea repetir el programa? (s/n): ");
            scanf("\r%c",&repetir);
            if(repetir=='s'||repetir=='S'||repetir=='n'||repetir=='N') break;
                else printf("Respuesta inválida.\n");
        }
    } while (repetir=='s'||repetir=='S');
    return 0;
}

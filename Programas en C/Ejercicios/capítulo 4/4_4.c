#include <stdio.h>
#include <locale.h>


int main(int argc, char const *argv[])
{
    //declaración de variables.
    float pulgadas,yardas,pies,cmetros,metros;
    setlocale(LC_CTYPE,"spanish");
    printf("Programa que convierte una medida dada en pies a yardas, pulgadas pies, centímetros y metros para luego mostrarlas en pantalla.\n");
    printf("\nPor favor ingrese una medida expresada en pies: ");
    scanf("%f",&pies);

    //CÁLCULOS
    pulgadas=12*pies;
    yardas=pies/3;
    cmetros=pulgadas*2.54f;
    metros=cmetros/100;

    //SALIDA DE RESULTADOS
    printf("\nYardas: %.2f\nMetros: %.2f\nPies: %.2f\npulgadas: %.2f\ncentímetros: %.2f\n",yardas,metros,pies,pulgadas,cmetros);
    return 0;
}

#include <stdio.h>
#include <locale.h>


int main(int argc, char const *argv[])
{
    //declaraci�n de variables.
    float pulgadas,yardas,pies,cmetros,metros;
    setlocale(LC_CTYPE,"spanish");
    printf("Programa que convierte una medida dada en pies a yardas, pulgadas pies, cent�metros y metros para luego mostrarlas en pantalla.\n");
    printf("\nPor favor ingrese una medida expresada en pies: ");
    scanf("%f",&pies);

    //C�LCULOS
    pulgadas=12*pies;
    yardas=pies/3;
    cmetros=pulgadas*2.54f;
    metros=cmetros/100;

    //SALIDA DE RESULTADOS
    printf("\nYardas: %.2f\nMetros: %.2f\nPies: %.2f\npulgadas: %.2f\ncent�metros: %.2f\n",yardas,metros,pies,pulgadas,cmetros);
    return 0;
}

#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    float celsius,fahren;
    //Encabezado y entrada de datos.
    setlocale(LC_CTYPE,"spanish");
    printf("Programa que transforma una temperatura dada en grados celsius a grados fahrenheit.\n");
    printf("Por favor ingrese la temperatura en Celsius (°c): ");
    scanf("%f",&celsius);
    //Cálculo.
    fahren=celsius*9/5+32;
    printf("\n%.1f ° Celsius son %.1f ° Fahrenheit.",celsius,fahren);
    /* code */
    return 0;
}

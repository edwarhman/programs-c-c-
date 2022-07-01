#include <stdio.h>


float ancho=0, largo =0, superficie=0;

int main(int argc, char const *argv[])
{
    printf("Programa que calcula la superficie de una habitacion.\nPor favor ingrese la anchura:");
    scanf("%f",&ancho);
    printf("Ahora ingrese el largo:");
    scanf("%f",&largo);
    superficie=largo*ancho;
    printf("La superficie de la habitacion es %.4f.",superficie);
    //printf("%f %f",ancho,largo);
    return 0;
}

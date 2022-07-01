#include <stdio.h>
#include <locale.h>
#include <math.h>


int main(int argc, char const *argv[])
{
    //DECLARACIÓN DE VARIABLES
    float area, vertice_a,vertice_b,vertice_c,perimetro;
    int salir;
    char entrada;
    setlocale(LC_CTYPE,"spanish");
    //ENCABEZADO
    printf("Programa que calcula el area de un triángulo a partir de sus lados suministrados por el usuario.\n");
    do
    {
    //ENTRADA DE DATOS
        printf("Por favor ingrese el tamaño de los lados A, B y C del triángulo: ");
        scanf("%f %f %f",&vertice_a,&vertice_b,&vertice_c);
    //CÁLCULOS
        perimetro=(vertice_a+vertice_b+vertice_c)/2;
        area=sqrt(fabs(perimetro-vertice_a)*fabs(perimetro-vertice_b)*fabs(perimetro-vertice_c)*perimetro);
    //SALIDA DE DATOS
        printf("El area del triángulo de vertices %.2f, %.2f y %.2f es %.2f\n",vertice_a,vertice_b,vertice_c,area);
    //REPETIR PROGRAMA
        do
        {
            printf("¿Desea repetir el programa? (s/n): ");
            scanf("\r%c",&entrada);
            if (entrada=='s'||entrada=='S') salir=0;
                else if (entrada=='n'||entrada=='N') salir=1;
                    else printf("Argumento inválido.\n");       
        } while (!(entrada=='s'||entrada=='S'||entrada=='n'||entrada=='N'));                
    } while (!salir);
    return 0;
}

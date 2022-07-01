#include <stdio.h>
#include <locale.h>
#define PI 3.141597
int main(int argc, char const *argv[])
{
    //DECLARACIÓN DE VARIABLES
    float radio,altura,area_l, volumen;
    int salir=0;
    char entrada;
    //ENCABEZADO Y ENTRADA DE DATOS
    setlocale(LC_CTYPE,"spanish");
    printf("Programa que calcula el area lateral y el volumen de un cilindro a traves de su radio y de su altura.\n");
    while (!salir)
    {
        printf("Por favor ingrese el radio del cilindro seguido de su altura: ");
        scanf("%f %f",&radio,&altura);
        //CÁLCULOS
        area_l=2*radio*altura;
        volumen=2*PI*radio*radio*altura;
        //SALIDA DE RESULTADOS
        printf("El area lateral del cilindro es %.2f y su volumen es %.2f.",area_l,volumen);
        do
        {
            printf("\n¿Desea repetir el programa?(s/n): ");
            scanf("\r%c",&entrada);
            if(entrada=='s') salir=0;
                else if(entrada=='n') salir=1;
                    else printf("Entrada inválida.");
        } while (!(entrada=='s'||entrada=='n'));
        
        
        
    }
    return 0;

}

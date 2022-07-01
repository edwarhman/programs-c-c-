#include <stdio.h>
#include <locale.h>

int num_a,num_b,producto,resto;
float cociente;

int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"spanish");
    //Encabezado y entrada de datos.
    printf("Programa que calcula el producto, el cociente y el resto de dos números dados.\n");
    printf("Introduzca dos números enteros: ");
    scanf("%d %d",&num_a,&num_b);

    //Cálculos.
    producto=num_b*num_a;
    cociente=(float)num_a/(float)num_b;
    resto=num_a%num_b;

    //Salida de datos.
    printf("\n\nProducto: %d * %d = %d\n",num_a,num_b,producto);
    printf("Cociente: %d / %d = %4f\n",num_a,num_b,cociente);
    printf("Resto: %d \\% %d = %d\n",num_a,num_b,resto);
    return 0;
}

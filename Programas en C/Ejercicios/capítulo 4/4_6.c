#include <stdio.h>
#include <locale.h>


int main(int argc, char const *argv[])
{
    //Declaración de variables
    int num_a, num_b;

    setlocale(LC_CTYPE,"spanish");
    //Encabezado y entrada de datos.
    printf("Programa que solicita dos números enteros y visualiza el mayor de ellos.");
    printf("\nPor favor ingrese dos números enteros: ");
    scanf("%d %d",&num_a,&num_b);
    if(num_a>num_b){
        printf("El número %d es el mayor.",num_a);
    }
    else if (num_b>num_a){
        printf("El número %d es el mayor.",num_b);
    }
    else printf("Ambos números son iguales.");
    return 0;
}

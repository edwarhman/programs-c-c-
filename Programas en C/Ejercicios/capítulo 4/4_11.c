#include <stdio.h>
#include <locale.h>


int main(int argc, char const *argv[])
{
    //DECLARACI�N DE VARIABLES
    int num_a,num_b,producto,cociente,resto,salir;
    char entrada;
    //ENCABEZADO
    setlocale(LC_CTYPE,"spanish");
    printf("Programa que calcula el producto el cociente entero y el resto entre dos n�meros de tres cifras.\n");
    //ENTRADA DE DATOS
    do
    {
        do
        {
            printf("Por favor ingrese dos n�meros de tres cifras: ");
            scanf("%d %d",&num_a,&num_b);
            if (!(num_a>99&&num_a<1000&&num_b>99&&num_b<1000)) printf("Argumentos inv�lidos, por favor verif�quelos.\n");
        } while (!(num_a>99&&num_a<1000&&num_b>99&&num_b<1000));
        //C�LCULOS
        producto=num_b*num_a;
        cociente=num_a/num_b;
        resto=num_a%num_b;
        printf("El producto es %d, el cociente entero es %d y el resto es %d.\n",producto,cociente,resto);
        do
        {
            printf("�Desea repetir el programa? (s/n): ");
            scanf("\r%c",&entrada);
            if (entrada!='s'&&entrada!='S'&&entrada!='n'&&entrada!='N') printf("Entrada inv�lida.\n");
        } while (entrada!='s'&&entrada!='S'&&entrada!='n'&&entrada!='N');
        if (entrada=='s'||entrada=='S') salir=0;
        else salir=1;
    } while (!salir);
    return 0;
}

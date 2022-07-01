#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    int num_a,num_b,producto,cociente,resto,salir;                         //DECLARACI�N DE VARIABLES
    char entrada;
    setlocale(LC_CTYPE,"spanish");                                        //ENCABEZADO
    printf("Programa que calcula el producto el cociente entero y el resto entre dos n�meros de tres cifras.\n");
    do
    {
        for (;;)
        {
            printf("Por favor ingrese dos n�meros de tres cifras: ");     //ENTRADA DE DATOS
            scanf("%d %d",&num_a,&num_b);
            if(num_b>99&&num_b<1000&&num_a>99&&num_a<1000) break;
                else printf("Datos inv�lidos. Por favor rectif�quelos.\n");
        }
        producto=num_b*num_a;
        cociente=num_a/num_b;                                             //C�LCULOS
        resto=num_a%num_b;
        printf("El producto es %d, el cociente entero es %d y el resto es %d.\n",producto,cociente,resto);
        for (;;)
        {
            printf("�Desea repetir el programa? (s/n): ");                //�REPETIR PROGRAMA?
            scanf("\r%c",&entrada);
            if (entrada=='s'||entrada=='S'||entrada=='n'||entrada=='N') break;
                else printf("Entrada inv�lida.\n");
        }   
        if (entrada=='s'||entrada=='S') salir=0;
            else salir=1;             
    } while (!salir);    
    return 0;
}

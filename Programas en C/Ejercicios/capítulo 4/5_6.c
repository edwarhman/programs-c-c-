#include <locale.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N,M,A,C,B;
    N=M=A=B=C=0;
    setlocale(LC_CTYPE,"spanish");
    printf("Programa que redondea un número dado por el usuario a su centena más próxima.\n");
    printf("Por favor ingrese un número con no más de 4 cifras: ");
    scanf("%d",&N);
    if (N%1000==0)
    {
        M=N;
    }else if (N>100)
            {
                A=(N-(N%1000))/1000;
                B=(N%1000-(N%1000%100))/100;
                C=(N%1000%100-(N%1000%100%10))/10;
                if (C>=5) M=A*1000+(B+1)*100;
                else M=A*1000+B*100;
            }else if (N>=50) M=100;
                    else M=0;
    printf("El resultado es %d",M);
    return 0;
}

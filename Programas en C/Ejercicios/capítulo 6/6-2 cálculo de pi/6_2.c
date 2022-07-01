#include <locale.h>
#include <stdio.h>
#include <math.h>
int Pedir_datos(char mensaje[50]);
void Calcular_pi(int N_terminos);
int main(int argc, char const *argv[])
{
    int terminos=0;
    puts("Programa que calcula la constante PI utilizando la serie de Nilakantha a partir de una cantidad de terminos dados.");
    terminos=Pedir_datos("Por favor ingrese la cantidad de terminos: ");
    Calcular_pi(terminos);
    return 0;
}

int Pedir_datos(char mensaje[50])
{
    int N_terminos=-1;
    char cadena[10];
    for(;;)
    {
    printf(mensaje);
    scanf("%d",&N_terminos);
    if(N_terminos>0) break;
    scanf("%s",cadena);
    puts("Dato inválido.");
    }
    return N_terminos;
}
void Calcular_pi(int N_terminos)
{
    float PI=3;
    for (int i = 2; i <= N_terminos*2; i+=2)
    {
        PI=-PI-(4/(float)(i*(i+1)*(i+2)));
    }
    printf("Pi es %f",fabs(PI));
    return; 
    
}
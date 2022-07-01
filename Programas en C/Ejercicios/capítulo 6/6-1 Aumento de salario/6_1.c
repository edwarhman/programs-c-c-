#include <stdio.h>
#include <locale.h>
#define AUMENTO1 0.2f
#define AUMENTO2 0.1f
#define AUMENTO3 0.05f

float pedir_entrada(char entrada[64]);
void Aumentar_salario(float salario);

int main(int argc, char const *argv[])
{
    float salario;
    setlocale(LC_CTYPE,"spanish");
    puts("Programa que calcula el aumento del salario de un trabajador según la siguiente tabla:");
    puts("SALARIO(dolares)\tAUMENTO %");
    puts("-0 a 9000\t\t20");
    puts("-9001 a 15000\t\t10");
    puts("-15000 a 20000\t\t5");
    puts("-más de 20000\t\t0");

    salario=pedir_entrada("Por favor ingrese el salario: ");
    Aumentar_salario(salario);
    return 0;
}

float pedir_entrada(char entrada[64])
{
    float parametro=-1;
    char cadena[20];
    for(;;)
    {
    printf(entrada);
    scanf("%f",&parametro);
    if(parametro>=0) break;
    scanf("%s",cadena);
    printf("Entrada inválida.\n");
    }
    return parametro;
}
void Aumentar_salario(float salario)
{
    if (salario<=20000)
    {
        if (salario<=15000)
        {
            if (salario<=9000) salario+=salario*AUMENTO1;
                else salario+=salario*AUMENTO2;
        }salario+=salario*AUMENTO3;    
    }
    printf("El nuevo salario es %.2f",salario);
    return;
}
